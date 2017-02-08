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
///CExchangeDataSyncStatusSingleIterator�����෵��һ������������ͬ��״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusSingleIterator: public CExchangeDataSyncStatusIterator
{
private:
	CExchangeDataSyncStatus *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CExchangeDataSyncStatusSingleIterator(CExchangeDataSyncStatusFactory *pFactory,CExchangeDataSyncStatus *pResult)
		:CExchangeDataSyncStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CExchangeDataSyncStatusSingleIterator(void)
	{
	}

	///Ѱ����һ������������CExchangeDataSyncStatus
	///@return	��һ����������CExchangeDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchangeDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchangeDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusPredict���ж�һ������������ͬ��״̬�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pExchangeDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusAndPredict�Ƕ���������������ͬ��״̬ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusAndPredict : public CExchangeDataSyncStatusPredict
{
private:
	CExchangeDataSyncStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CExchangeDataSyncStatusAndPredict(CExchangeDataSyncStatusPredict *p1, CExchangeDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CExchangeDataSyncStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExchangeDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return m_p1->isValid(pExchangeDataSyncStatus) && m_p2->isValid(pExchangeDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusOrPredict�Ƕ���������������ͬ��״̬ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusOrPredict : public CExchangeDataSyncStatusPredict
{
private:
	CExchangeDataSyncStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CExchangeDataSyncStatusOrPredict(CExchangeDataSyncStatusPredict *p1, CExchangeDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CExchangeDataSyncStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExchangeDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return m_p1->isValid(pExchangeDataSyncStatus) || m_p2->isValid(pExchangeDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusNotPredict�Ƕ�һ������������ͬ��״̬ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusNotPredict : public CExchangeDataSyncStatusPredict
{
private:
	CExchangeDataSyncStatusPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CExchangeDataSyncStatusNotPredict(CExchangeDataSyncStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CExchangeDataSyncStatusNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExchangeDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return !m_predict->isValid(pExchangeDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusFilter��һ�������еĽ���������ͬ��״̬ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusFilter: public CExchangeDataSyncStatusIterator
{
private:
	CExchangeDataSyncStatusIterator *m_baseIterator;
	CExchangeDataSyncStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CExchangeDataSyncStatusFilter(CExchangeDataSyncStatusIterator *pBaseIterator, CExchangeDataSyncStatusPredict *pPredict, bool continueResult=false)
		:CExchangeDataSyncStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CExchangeDataSyncStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CExchangeDataSyncStatus
	///@return	��һ����������CExchangeDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchangeDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchangeDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusLinkIterator��������������������ͬ��״̬ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusLinkIterator: public CExchangeDataSyncStatusIterator
{
private:
	CExchangeDataSyncStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CExchangeDataSyncStatusLinkIterator(CExchangeDataSyncStatusIterator *pBaseIterator1,CExchangeDataSyncStatusIterator *pBaseIterator2)
		:CExchangeDataSyncStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CExchangeDataSyncStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CExchangeDataSyncStatus
	///@return	��һ����������CExchangeDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchangeDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchangeDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusSingleIterator�����෵��һ������������ͬ��״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusSingleIterator: public CSGDataSyncStatusIterator
{
private:
	CSGDataSyncStatus *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSGDataSyncStatusSingleIterator(CSGDataSyncStatusFactory *pFactory,CSGDataSyncStatus *pResult)
		:CSGDataSyncStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSGDataSyncStatusSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSGDataSyncStatus
	///@return	��һ����������CSGDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSGDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSGDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusPredict���ж�һ������������ͬ��״̬�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSGDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusAndPredict�Ƕ���������������ͬ��״̬ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusAndPredict : public CSGDataSyncStatusPredict
{
private:
	CSGDataSyncStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSGDataSyncStatusAndPredict(CSGDataSyncStatusPredict *p1, CSGDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSGDataSyncStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSGDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return m_p1->isValid(pSGDataSyncStatus) && m_p2->isValid(pSGDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusOrPredict�Ƕ���������������ͬ��״̬ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusOrPredict : public CSGDataSyncStatusPredict
{
private:
	CSGDataSyncStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSGDataSyncStatusOrPredict(CSGDataSyncStatusPredict *p1, CSGDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSGDataSyncStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSGDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return m_p1->isValid(pSGDataSyncStatus) || m_p2->isValid(pSGDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusNotPredict�Ƕ�һ������������ͬ��״̬ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusNotPredict : public CSGDataSyncStatusPredict
{
private:
	CSGDataSyncStatusPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSGDataSyncStatusNotPredict(CSGDataSyncStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSGDataSyncStatusNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSGDataSyncStatus	Ҫ���жϵĽ���������ͬ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return !m_predict->isValid(pSGDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusFilter��һ�������еĽ���������ͬ��״̬ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusFilter: public CSGDataSyncStatusIterator
{
private:
	CSGDataSyncStatusIterator *m_baseIterator;
	CSGDataSyncStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSGDataSyncStatusFilter(CSGDataSyncStatusIterator *pBaseIterator, CSGDataSyncStatusPredict *pPredict, bool continueResult=false)
		:CSGDataSyncStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSGDataSyncStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSGDataSyncStatus
	///@return	��һ����������CSGDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSGDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSGDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusLinkIterator��������������������ͬ��״̬ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusLinkIterator: public CSGDataSyncStatusIterator
{
private:
	CSGDataSyncStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSGDataSyncStatusLinkIterator(CSGDataSyncStatusIterator *pBaseIterator1,CSGDataSyncStatusIterator *pBaseIterator2)
		:CSGDataSyncStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSGDataSyncStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSGDataSyncStatus
	///@return	��һ����������CSGDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSGDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSGDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrentTimeSingleIterator�����෵��һ����ǰʱ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeSingleIterator: public CCurrentTimeIterator
{
private:
	CCurrentTime *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrentTimeSingleIterator(CCurrentTimeFactory *pFactory,CCurrentTime *pResult)
		:CCurrentTimeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrentTimeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrentTime
	///@return	��һ����������CCurrentTime������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrentTime *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrentTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimePredict���ж�һ����ǰʱ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrentTime	Ҫ���жϵĵ�ǰʱ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrentTime *pCurrentTime)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeAndPredict�Ƕ�������ǰʱ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeAndPredict : public CCurrentTimePredict
{
private:
	CCurrentTimePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrentTimeAndPredict(CCurrentTimePredict *p1, CCurrentTimePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrentTimeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrentTime	Ҫ���жϵĵ�ǰʱ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrentTime *pCurrentTime)
	{
		return m_p1->isValid(pCurrentTime) && m_p2->isValid(pCurrentTime);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeOrPredict�Ƕ�������ǰʱ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeOrPredict : public CCurrentTimePredict
{
private:
	CCurrentTimePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrentTimeOrPredict(CCurrentTimePredict *p1, CCurrentTimePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrentTimeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrentTime	Ҫ���жϵĵ�ǰʱ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrentTime *pCurrentTime)
	{
		return m_p1->isValid(pCurrentTime) || m_p2->isValid(pCurrentTime);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeNotPredict�Ƕ�һ����ǰʱ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeNotPredict : public CCurrentTimePredict
{
private:
	CCurrentTimePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrentTimeNotPredict(CCurrentTimePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrentTimeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrentTime	Ҫ���жϵĵ�ǰʱ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrentTime *pCurrentTime)
	{
		return !m_predict->isValid(pCurrentTime);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeFilter��һ�������еĵ�ǰʱ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeFilter: public CCurrentTimeIterator
{
private:
	CCurrentTimeIterator *m_baseIterator;
	CCurrentTimePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrentTimeFilter(CCurrentTimeIterator *pBaseIterator, CCurrentTimePredict *pPredict, bool continueResult=false)
		:CCurrentTimeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrentTimeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrentTime
	///@return	��һ����������CCurrentTime������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrentTime *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrentTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeLinkIterator������������ǰʱ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeLinkIterator: public CCurrentTimeIterator
{
private:
	CCurrentTimeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrentTimeLinkIterator(CCurrentTimeIterator *pBaseIterator1,CCurrentTimeIterator *pBaseIterator2)
		:CCurrentTimeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrentTimeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrentTime
	///@return	��һ����������CCurrentTime������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrentTime *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrentTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CDataCenterDescSingleIterator�����෵��һ����������������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescSingleIterator: public CDataCenterDescIterator
{
private:
	CDataCenterDesc *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CDataCenterDescSingleIterator(CDataCenterDescFactory *pFactory,CDataCenterDesc *pResult)
		:CDataCenterDescIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CDataCenterDescSingleIterator(void)
	{
	}

	///Ѱ����һ������������CDataCenterDesc
	///@return	��һ����������CDataCenterDesc������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDataCenterDesc *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDataCenterDesc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescPredict���ж�һ���������������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pDataCenterDesc	Ҫ���жϵ�������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)=0;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescAndPredict�Ƕ�����������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescAndPredict : public CDataCenterDescPredict
{
private:
	CDataCenterDescPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CDataCenterDescAndPredict(CDataCenterDescPredict *p1, CDataCenterDescPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CDataCenterDescAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDataCenterDesc	Ҫ���жϵ�������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)
	{
		return m_p1->isValid(pDataCenterDesc) && m_p2->isValid(pDataCenterDesc);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescOrPredict�Ƕ�����������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescOrPredict : public CDataCenterDescPredict
{
private:
	CDataCenterDescPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CDataCenterDescOrPredict(CDataCenterDescPredict *p1, CDataCenterDescPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CDataCenterDescOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDataCenterDesc	Ҫ���жϵ�������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)
	{
		return m_p1->isValid(pDataCenterDesc) || m_p2->isValid(pDataCenterDesc);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescNotPredict�Ƕ�һ��������������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescNotPredict : public CDataCenterDescPredict
{
private:
	CDataCenterDescPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CDataCenterDescNotPredict(CDataCenterDescPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CDataCenterDescNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDataCenterDesc	Ҫ���жϵ�������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)
	{
		return !m_predict->isValid(pDataCenterDesc);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescFilter��һ�������е�������������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescFilter: public CDataCenterDescIterator
{
private:
	CDataCenterDescIterator *m_baseIterator;
	CDataCenterDescPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CDataCenterDescFilter(CDataCenterDescIterator *pBaseIterator, CDataCenterDescPredict *pPredict, bool continueResult=false)
		:CDataCenterDescIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CDataCenterDescFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CDataCenterDesc
	///@return	��һ����������CDataCenterDesc������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDataCenterDesc *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDataCenterDesc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescLinkIterator����������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescLinkIterator: public CDataCenterDescIterator
{
private:
	CDataCenterDescIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CDataCenterDescLinkIterator(CDataCenterDescIterator *pBaseIterator1,CDataCenterDescIterator *pBaseIterator2)
		:CDataCenterDescIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CDataCenterDescLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CDataCenterDesc
	///@return	��һ����������CDataCenterDesc������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDataCenterDesc *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDataCenterDesc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CExchangeSingleIterator�����෵��һ����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeSingleIterator: public CExchangeIterator
{
private:
	CExchange *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CExchangeSingleIterator(CExchangeFactory *pFactory,CExchange *pResult)
		:CExchangeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CExchangeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CExchange
	///@return	��һ����������CExchange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchange *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangePredict���ж�һ���������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pExchange	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchange *pExchange)=0;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeAndPredict�Ƕ�����������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeAndPredict : public CExchangePredict
{
private:
	CExchangePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CExchangeAndPredict(CExchangePredict *p1, CExchangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CExchangeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExchange	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchange *pExchange)
	{
		return m_p1->isValid(pExchange) && m_p2->isValid(pExchange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeOrPredict�Ƕ�����������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeOrPredict : public CExchangePredict
{
private:
	CExchangePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CExchangeOrPredict(CExchangePredict *p1, CExchangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CExchangeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExchange	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchange *pExchange)
	{
		return m_p1->isValid(pExchange) || m_p2->isValid(pExchange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeNotPredict�Ƕ�һ��������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeNotPredict : public CExchangePredict
{
private:
	CExchangePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CExchangeNotPredict(CExchangePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CExchangeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExchange	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExchange *pExchange)
	{
		return !m_predict->isValid(pExchange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeFilter��һ�������еĽ�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeFilter: public CExchangeIterator
{
private:
	CExchangeIterator *m_baseIterator;
	CExchangePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CExchangeFilter(CExchangeIterator *pBaseIterator, CExchangePredict *pPredict, bool continueResult=false)
		:CExchangeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CExchangeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CExchange
	///@return	��һ����������CExchange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchange *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangeLinkIterator����������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeLinkIterator: public CExchangeIterator
{
private:
	CExchangeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CExchangeLinkIterator(CExchangeIterator *pBaseIterator1,CExchangeIterator *pBaseIterator2)
		:CExchangeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CExchangeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CExchange
	///@return	��һ����������CExchange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchange *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSettlementGroupSingleIterator�����෵��һ���������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupSingleIterator: public CSettlementGroupIterator
{
private:
	CSettlementGroup *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CSettlementGroupSingleIterator(CSettlementGroupFactory *pFactory,CSettlementGroup *pResult)
		:CSettlementGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CSettlementGroupSingleIterator(void)
	{
	}

	///Ѱ����һ������������CSettlementGroup
	///@return	��һ����������CSettlementGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSettlementGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSettlementGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupPredict���ж�һ���������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pSettlementGroup	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSettlementGroup *pSettlementGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupAndPredict�Ƕ�����������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupAndPredict : public CSettlementGroupPredict
{
private:
	CSettlementGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSettlementGroupAndPredict(CSettlementGroupPredict *p1, CSettlementGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSettlementGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSettlementGroup	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSettlementGroup *pSettlementGroup)
	{
		return m_p1->isValid(pSettlementGroup) && m_p2->isValid(pSettlementGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupOrPredict�Ƕ�����������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupOrPredict : public CSettlementGroupPredict
{
private:
	CSettlementGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CSettlementGroupOrPredict(CSettlementGroupPredict *p1, CSettlementGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CSettlementGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSettlementGroup	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSettlementGroup *pSettlementGroup)
	{
		return m_p1->isValid(pSettlementGroup) || m_p2->isValid(pSettlementGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupNotPredict�Ƕ�һ��������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupNotPredict : public CSettlementGroupPredict
{
private:
	CSettlementGroupPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CSettlementGroupNotPredict(CSettlementGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CSettlementGroupNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pSettlementGroup	Ҫ���жϵĽ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CSettlementGroup *pSettlementGroup)
	{
		return !m_predict->isValid(pSettlementGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupFilter��һ�������еĽ�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupFilter: public CSettlementGroupIterator
{
private:
	CSettlementGroupIterator *m_baseIterator;
	CSettlementGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CSettlementGroupFilter(CSettlementGroupIterator *pBaseIterator, CSettlementGroupPredict *pPredict, bool continueResult=false)
		:CSettlementGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CSettlementGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CSettlementGroup
	///@return	��һ����������CSettlementGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSettlementGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSettlementGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupLinkIterator����������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupLinkIterator: public CSettlementGroupIterator
{
private:
	CSettlementGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CSettlementGroupLinkIterator(CSettlementGroupIterator *pBaseIterator1,CSettlementGroupIterator *pBaseIterator2)
		:CSettlementGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CSettlementGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CSettlementGroup
	///@return	��һ����������CSettlementGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSettlementGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSettlementGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketSingleIterator�����෵��һ���г���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketSingleIterator: public CMarketIterator
{
private:
	CMarket *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMarketSingleIterator(CMarketFactory *pFactory,CMarket *pResult)
		:CMarketIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMarketSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMarket
	///@return	��һ����������CMarket������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarket *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarket ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketPredict���ж�һ���г��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMarket	Ҫ���жϵ��г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarket *pMarket)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketAndPredict�Ƕ������г�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketAndPredict : public CMarketPredict
{
private:
	CMarketPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketAndPredict(CMarketPredict *p1, CMarketPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarket	Ҫ���жϵ��г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarket *pMarket)
	{
		return m_p1->isValid(pMarket) && m_p2->isValid(pMarket);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketOrPredict�Ƕ������г�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketOrPredict : public CMarketPredict
{
private:
	CMarketPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketOrPredict(CMarketPredict *p1, CMarketPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarket	Ҫ���жϵ��г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarket *pMarket)
	{
		return m_p1->isValid(pMarket) || m_p2->isValid(pMarket);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketNotPredict�Ƕ�һ���г�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketNotPredict : public CMarketPredict
{
private:
	CMarketPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMarketNotPredict(CMarketPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMarketNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarket	Ҫ���жϵ��г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarket *pMarket)
	{
		return !m_predict->isValid(pMarket);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketFilter��һ�������е��г�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketFilter: public CMarketIterator
{
private:
	CMarketIterator *m_baseIterator;
	CMarketPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMarketFilter(CMarketIterator *pBaseIterator, CMarketPredict *pPredict, bool continueResult=false)
		:CMarketIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMarketFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMarket
	///@return	��һ����������CMarket������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarket *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarket ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketLinkIterator�����������г�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketLinkIterator: public CMarketIterator
{
private:
	CMarketIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMarketLinkIterator(CMarketIterator *pBaseIterator1,CMarketIterator *pBaseIterator2)
		:CMarketIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMarketLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMarket
	///@return	��һ����������CMarket������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarket *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarket ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketProductSingleIterator�����෵��һ���г���Ʒ������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductSingleIterator: public CMarketProductIterator
{
private:
	CMarketProduct *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMarketProductSingleIterator(CMarketProductFactory *pFactory,CMarketProduct *pResult)
		:CMarketProductIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMarketProductSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMarketProduct
	///@return	��һ����������CMarketProduct������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProduct *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProduct ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductPredict���ж�һ���г���Ʒ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMarketProduct	Ҫ���жϵ��г���Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProduct *pMarketProduct)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductAndPredict�Ƕ������г���Ʒ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductAndPredict : public CMarketProductPredict
{
private:
	CMarketProductPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketProductAndPredict(CMarketProductPredict *p1, CMarketProductPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketProductAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketProduct	Ҫ���жϵ��г���Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProduct *pMarketProduct)
	{
		return m_p1->isValid(pMarketProduct) && m_p2->isValid(pMarketProduct);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductOrPredict�Ƕ������г���Ʒ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductOrPredict : public CMarketProductPredict
{
private:
	CMarketProductPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketProductOrPredict(CMarketProductPredict *p1, CMarketProductPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketProductOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketProduct	Ҫ���жϵ��г���Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProduct *pMarketProduct)
	{
		return m_p1->isValid(pMarketProduct) || m_p2->isValid(pMarketProduct);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductNotPredict�Ƕ�һ���г���Ʒ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductNotPredict : public CMarketProductPredict
{
private:
	CMarketProductPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMarketProductNotPredict(CMarketProductPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMarketProductNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketProduct	Ҫ���жϵ��г���Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProduct *pMarketProduct)
	{
		return !m_predict->isValid(pMarketProduct);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductFilter��һ�������е��г���Ʒ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductFilter: public CMarketProductIterator
{
private:
	CMarketProductIterator *m_baseIterator;
	CMarketProductPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMarketProductFilter(CMarketProductIterator *pBaseIterator, CMarketProductPredict *pPredict, bool continueResult=false)
		:CMarketProductIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMarketProductFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMarketProduct
	///@return	��һ����������CMarketProduct������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProduct *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProduct ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductLinkIterator�����������г���Ʒ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductLinkIterator: public CMarketProductIterator
{
private:
	CMarketProductIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMarketProductLinkIterator(CMarketProductIterator *pBaseIterator1,CMarketProductIterator *pBaseIterator2)
		:CMarketProductIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMarketProductLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMarketProduct
	///@return	��һ����������CMarketProduct������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProduct *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProduct ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupSingleIterator�����෵��һ���г���Ʒ�������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupSingleIterator: public CMarketProductGroupIterator
{
private:
	CMarketProductGroup *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMarketProductGroupSingleIterator(CMarketProductGroupFactory *pFactory,CMarketProductGroup *pResult)
		:CMarketProductGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMarketProductGroupSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMarketProductGroup
	///@return	��һ����������CMarketProductGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProductGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProductGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupPredict���ж�һ���г���Ʒ������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMarketProductGroup	Ҫ���жϵ��г���Ʒ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupAndPredict�Ƕ������г���Ʒ�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupAndPredict : public CMarketProductGroupPredict
{
private:
	CMarketProductGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketProductGroupAndPredict(CMarketProductGroupPredict *p1, CMarketProductGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketProductGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketProductGroup	Ҫ���жϵ��г���Ʒ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)
	{
		return m_p1->isValid(pMarketProductGroup) && m_p2->isValid(pMarketProductGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupOrPredict�Ƕ������г���Ʒ�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupOrPredict : public CMarketProductGroupPredict
{
private:
	CMarketProductGroupPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketProductGroupOrPredict(CMarketProductGroupPredict *p1, CMarketProductGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketProductGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketProductGroup	Ҫ���жϵ��г���Ʒ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)
	{
		return m_p1->isValid(pMarketProductGroup) || m_p2->isValid(pMarketProductGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupNotPredict�Ƕ�һ���г���Ʒ�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupNotPredict : public CMarketProductGroupPredict
{
private:
	CMarketProductGroupPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMarketProductGroupNotPredict(CMarketProductGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMarketProductGroupNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketProductGroup	Ҫ���жϵ��г���Ʒ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)
	{
		return !m_predict->isValid(pMarketProductGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupFilter��һ�������е��г���Ʒ�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupFilter: public CMarketProductGroupIterator
{
private:
	CMarketProductGroupIterator *m_baseIterator;
	CMarketProductGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMarketProductGroupFilter(CMarketProductGroupIterator *pBaseIterator, CMarketProductGroupPredict *pPredict, bool continueResult=false)
		:CMarketProductGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMarketProductGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMarketProductGroup
	///@return	��һ����������CMarketProductGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProductGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProductGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupLinkIterator�����������г���Ʒ�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupLinkIterator: public CMarketProductGroupIterator
{
private:
	CMarketProductGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMarketProductGroupLinkIterator(CMarketProductGroupIterator *pBaseIterator1,CMarketProductGroupIterator *pBaseIterator2)
		:CMarketProductGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMarketProductGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMarketProductGroup
	///@return	��һ����������CMarketProductGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProductGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProductGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMdPubStatusSingleIterator�����෵��һ�����鷢��״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusSingleIterator: public CMdPubStatusIterator
{
private:
	CMdPubStatus *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMdPubStatusSingleIterator(CMdPubStatusFactory *pFactory,CMdPubStatus *pResult)
		:CMdPubStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMdPubStatusSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMdPubStatus
	///@return	��һ����������CMdPubStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMdPubStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMdPubStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusPredict���ж�һ�����鷢��״̬�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMdPubStatus	Ҫ���жϵ����鷢��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMdPubStatus *pMdPubStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusAndPredict�Ƕ��������鷢��״̬ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusAndPredict : public CMdPubStatusPredict
{
private:
	CMdPubStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMdPubStatusAndPredict(CMdPubStatusPredict *p1, CMdPubStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMdPubStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMdPubStatus	Ҫ���жϵ����鷢��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMdPubStatus *pMdPubStatus)
	{
		return m_p1->isValid(pMdPubStatus) && m_p2->isValid(pMdPubStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusOrPredict�Ƕ��������鷢��״̬ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusOrPredict : public CMdPubStatusPredict
{
private:
	CMdPubStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMdPubStatusOrPredict(CMdPubStatusPredict *p1, CMdPubStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMdPubStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMdPubStatus	Ҫ���жϵ����鷢��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMdPubStatus *pMdPubStatus)
	{
		return m_p1->isValid(pMdPubStatus) || m_p2->isValid(pMdPubStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusNotPredict�Ƕ�һ�����鷢��״̬ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusNotPredict : public CMdPubStatusPredict
{
private:
	CMdPubStatusPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMdPubStatusNotPredict(CMdPubStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMdPubStatusNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMdPubStatus	Ҫ���жϵ����鷢��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMdPubStatus *pMdPubStatus)
	{
		return !m_predict->isValid(pMdPubStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusFilter��һ�������е����鷢��״̬ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusFilter: public CMdPubStatusIterator
{
private:
	CMdPubStatusIterator *m_baseIterator;
	CMdPubStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMdPubStatusFilter(CMdPubStatusIterator *pBaseIterator, CMdPubStatusPredict *pPredict, bool continueResult=false)
		:CMdPubStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMdPubStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMdPubStatus
	///@return	��һ����������CMdPubStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMdPubStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMdPubStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusLinkIterator�������������鷢��״̬ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusLinkIterator: public CMdPubStatusIterator
{
private:
	CMdPubStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMdPubStatusLinkIterator(CMdPubStatusIterator *pBaseIterator1,CMdPubStatusIterator *pBaseIterator2)
		:CMdPubStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMdPubStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMdPubStatus
	///@return	��һ����������CMdPubStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMdPubStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMdPubStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicSingleIterator�����෵��һ�����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicSingleIterator: public CMarketDataTopicIterator
{
private:
	CMarketDataTopic *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMarketDataTopicSingleIterator(CMarketDataTopicFactory *pFactory,CMarketDataTopic *pResult)
		:CMarketDataTopicIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMarketDataTopicSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMarketDataTopic
	///@return	��һ����������CMarketDataTopic������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataTopic *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataTopic ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicPredict���ж�һ�����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataTopic	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicAndPredict�Ƕ�������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicAndPredict : public CMarketDataTopicPredict
{
private:
	CMarketDataTopicPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataTopicAndPredict(CMarketDataTopicPredict *p1, CMarketDataTopicPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataTopicAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataTopic	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)
	{
		return m_p1->isValid(pMarketDataTopic) && m_p2->isValid(pMarketDataTopic);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicOrPredict�Ƕ�������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicOrPredict : public CMarketDataTopicPredict
{
private:
	CMarketDataTopicPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataTopicOrPredict(CMarketDataTopicPredict *p1, CMarketDataTopicPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataTopicOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataTopic	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)
	{
		return m_p1->isValid(pMarketDataTopic) || m_p2->isValid(pMarketDataTopic);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicNotPredict�Ƕ�һ����������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicNotPredict : public CMarketDataTopicPredict
{
private:
	CMarketDataTopicPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMarketDataTopicNotPredict(CMarketDataTopicPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMarketDataTopicNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataTopic	Ҫ���жϵ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)
	{
		return !m_predict->isValid(pMarketDataTopic);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicFilter��һ�������е���������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicFilter: public CMarketDataTopicIterator
{
private:
	CMarketDataTopicIterator *m_baseIterator;
	CMarketDataTopicPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMarketDataTopicFilter(CMarketDataTopicIterator *pBaseIterator, CMarketDataTopicPredict *pPredict, bool continueResult=false)
		:CMarketDataTopicIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMarketDataTopicFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMarketDataTopic
	///@return	��һ����������CMarketDataTopic������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataTopic *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataTopic ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicLinkIterator������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicLinkIterator: public CMarketDataTopicIterator
{
private:
	CMarketDataTopicIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMarketDataTopicLinkIterator(CMarketDataTopicIterator *pBaseIterator1,CMarketDataTopicIterator *pBaseIterator2)
		:CMarketDataTopicIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMarketDataTopicLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMarketDataTopic
	///@return	��һ����������CMarketDataTopic������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataTopic *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataTopic ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeSingleIterator�����෵��һ����Ա�����г���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeSingleIterator: public CPartTopicSubscribeIterator
{
private:
	CPartTopicSubscribe *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartTopicSubscribeSingleIterator(CPartTopicSubscribeFactory *pFactory,CPartTopicSubscribe *pResult)
		:CPartTopicSubscribeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartTopicSubscribeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartTopicSubscribe
	///@return	��һ����������CPartTopicSubscribe������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartTopicSubscribe *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartTopicSubscribe ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribePredict���ж�һ����Ա�����г��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartTopicSubscribe	Ҫ���жϵĻ�Ա�����г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeAndPredict�Ƕ�������Ա�����г�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeAndPredict : public CPartTopicSubscribePredict
{
private:
	CPartTopicSubscribePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartTopicSubscribeAndPredict(CPartTopicSubscribePredict *p1, CPartTopicSubscribePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartTopicSubscribeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartTopicSubscribe	Ҫ���жϵĻ�Ա�����г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return m_p1->isValid(pPartTopicSubscribe) && m_p2->isValid(pPartTopicSubscribe);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeOrPredict�Ƕ�������Ա�����г�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeOrPredict : public CPartTopicSubscribePredict
{
private:
	CPartTopicSubscribePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartTopicSubscribeOrPredict(CPartTopicSubscribePredict *p1, CPartTopicSubscribePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartTopicSubscribeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartTopicSubscribe	Ҫ���жϵĻ�Ա�����г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return m_p1->isValid(pPartTopicSubscribe) || m_p2->isValid(pPartTopicSubscribe);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeNotPredict�Ƕ�һ����Ա�����г�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeNotPredict : public CPartTopicSubscribePredict
{
private:
	CPartTopicSubscribePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartTopicSubscribeNotPredict(CPartTopicSubscribePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartTopicSubscribeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartTopicSubscribe	Ҫ���жϵĻ�Ա�����г�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return !m_predict->isValid(pPartTopicSubscribe);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeFilter��һ�������еĻ�Ա�����г�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeFilter: public CPartTopicSubscribeIterator
{
private:
	CPartTopicSubscribeIterator *m_baseIterator;
	CPartTopicSubscribePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartTopicSubscribeFilter(CPartTopicSubscribeIterator *pBaseIterator, CPartTopicSubscribePredict *pPredict, bool continueResult=false)
		:CPartTopicSubscribeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartTopicSubscribeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartTopicSubscribe
	///@return	��һ����������CPartTopicSubscribe������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartTopicSubscribe *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartTopicSubscribe ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeLinkIterator������������Ա�����г�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeLinkIterator: public CPartTopicSubscribeIterator
{
private:
	CPartTopicSubscribeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartTopicSubscribeLinkIterator(CPartTopicSubscribeIterator *pBaseIterator1,CPartTopicSubscribeIterator *pBaseIterator2)
		:CPartTopicSubscribeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartTopicSubscribeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartTopicSubscribe
	///@return	��һ����������CPartTopicSubscribe������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartTopicSubscribe *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartTopicSubscribe ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CParticipantSingleIterator�����෵��һ����Ա��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantSingleIterator: public CParticipantIterator
{
private:
	CParticipant *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CParticipantSingleIterator(CParticipantFactory *pFactory,CParticipant *pResult)
		:CParticipantIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CParticipantSingleIterator(void)
	{
	}

	///Ѱ����һ������������CParticipant
	///@return	��һ����������CParticipant������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CParticipant *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantPredict���ж�һ����Ա�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pParticipant	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CParticipant *pParticipant)=0;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantAndPredict�Ƕ�������Աν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantAndPredict : public CParticipantPredict
{
private:
	CParticipantPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CParticipantAndPredict(CParticipantPredict *p1, CParticipantPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CParticipantAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pParticipant	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CParticipant *pParticipant)
	{
		return m_p1->isValid(pParticipant) && m_p2->isValid(pParticipant);
	}
};

/////////////////////////////////////////////////////////////////////////
///CParticipantOrPredict�Ƕ�������Աν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantOrPredict : public CParticipantPredict
{
private:
	CParticipantPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CParticipantOrPredict(CParticipantPredict *p1, CParticipantPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CParticipantOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pParticipant	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CParticipant *pParticipant)
	{
		return m_p1->isValid(pParticipant) || m_p2->isValid(pParticipant);
	}
};

/////////////////////////////////////////////////////////////////////////
///CParticipantNotPredict�Ƕ�һ����Աν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantNotPredict : public CParticipantPredict
{
private:
	CParticipantPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CParticipantNotPredict(CParticipantPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CParticipantNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pParticipant	Ҫ���жϵĻ�Ա
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CParticipant *pParticipant)
	{
		return !m_predict->isValid(pParticipant);
	}
};

/////////////////////////////////////////////////////////////////////////
///CParticipantFilter��һ�������еĻ�Աö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantFilter: public CParticipantIterator
{
private:
	CParticipantIterator *m_baseIterator;
	CParticipantPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CParticipantFilter(CParticipantIterator *pBaseIterator, CParticipantPredict *pPredict, bool continueResult=false)
		:CParticipantIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CParticipantFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CParticipant
	///@return	��һ����������CParticipant������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CParticipant *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantLinkIterator������������Աö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantLinkIterator: public CParticipantIterator
{
private:
	CParticipantIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CParticipantLinkIterator(CParticipantIterator *pBaseIterator1,CParticipantIterator *pBaseIterator2)
		:CParticipantIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CParticipantLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CParticipant
	///@return	��һ����������CParticipant������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CParticipant *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartOfParticipantIterator��һ����Աö������Ӧ�Ľ��㽻�׻�Ա��ϵ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartOfParticipantIterator: public CClearingTradingPartIterator
{
private:
	CParticipantIterator *m_baseIterator;
	CClearingTradingPart *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CClearingTradingPartOfParticipantIterator(CClearingTradingPartFactory *pFactory,CParticipantIterator *pBaseIterator)
		:CClearingTradingPartIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CClearingTradingPartOfParticipantIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CClearingTradingPart
	///@return	��һ����������CClearingTradingPart������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingTradingPart *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingTradingPart ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingTradingPart *pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserSingleIterator�����෵��һ���û���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSingleIterator: public CUserIterator
{
private:
	CUser *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CUserSingleIterator(CUserFactory *pFactory,CUser *pResult)
		:CUserIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CUserSingleIterator(void)
	{
	}

	///Ѱ����һ������������CUser
	///@return	��һ����������CUser������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUser *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUser ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserPredict���ж�һ���û��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pUser	Ҫ���жϵ��û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUser *pUser)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserAndPredict�Ƕ������û�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserAndPredict : public CUserPredict
{
private:
	CUserPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserAndPredict(CUserPredict *p1, CUserPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUser	Ҫ���жϵ��û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUser *pUser)
	{
		return m_p1->isValid(pUser) && m_p2->isValid(pUser);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserOrPredict�Ƕ������û�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserOrPredict : public CUserPredict
{
private:
	CUserPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserOrPredict(CUserPredict *p1, CUserPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUser	Ҫ���жϵ��û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUser *pUser)
	{
		return m_p1->isValid(pUser) || m_p2->isValid(pUser);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserNotPredict�Ƕ�һ���û�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserNotPredict : public CUserPredict
{
private:
	CUserPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CUserNotPredict(CUserPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CUserNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUser	Ҫ���жϵ��û�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUser *pUser)
	{
		return !m_predict->isValid(pUser);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFilter��һ�������е��û�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFilter: public CUserIterator
{
private:
	CUserIterator *m_baseIterator;
	CUserPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CUserFilter(CUserIterator *pBaseIterator, CUserPredict *pPredict, bool continueResult=false)
		:CUserIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CUserFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CUser
	///@return	��һ����������CUser������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUser *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUser ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserLinkIterator�����������û�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserLinkIterator: public CUserIterator
{
private:
	CUserIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CUserLinkIterator(CUserIterator *pBaseIterator1,CUserIterator *pBaseIterator2)
		:CUserIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CUserLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CUser
	///@return	��һ����������CUser������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUser *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUser ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientSingleIterator�����෵��һ���ͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientSingleIterator: public CClientIterator
{
private:
	CClient *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CClientSingleIterator(CClientFactory *pFactory,CClient *pResult)
		:CClientIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CClientSingleIterator(void)
	{
	}

	///Ѱ����һ������������CClient
	///@return	��һ����������CClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPredict���ж�һ���ͻ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pClient	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClient *pClient)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientAndPredict�Ƕ������ͻ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientAndPredict : public CClientPredict
{
private:
	CClientPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientAndPredict(CClientPredict *p1, CClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClient	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClient *pClient)
	{
		return m_p1->isValid(pClient) && m_p2->isValid(pClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientOrPredict�Ƕ������ͻ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientOrPredict : public CClientPredict
{
private:
	CClientPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientOrPredict(CClientPredict *p1, CClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClient	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClient *pClient)
	{
		return m_p1->isValid(pClient) || m_p2->isValid(pClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientNotPredict�Ƕ�һ���ͻ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientNotPredict : public CClientPredict
{
private:
	CClientPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CClientNotPredict(CClientPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CClientNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClient	Ҫ���жϵĿͻ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClient *pClient)
	{
		return !m_predict->isValid(pClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientFilter��һ�������еĿͻ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientFilter: public CClientIterator
{
private:
	CClientIterator *m_baseIterator;
	CClientPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CClientFilter(CClientIterator *pBaseIterator, CClientPredict *pPredict, bool continueResult=false)
		:CClientIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CClientFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CClient
	///@return	��һ����������CClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientLinkIterator�����������ͻ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientLinkIterator: public CClientIterator
{
private:
	CClientIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CClientLinkIterator(CClientIterator *pBaseIterator1,CClientIterator *pBaseIterator2)
		:CClientIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CClientLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CClient
	///@return	��һ����������CClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserIPSingleIterator�����෵��һ������ԱIP��ַ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPSingleIterator: public CUserIPIterator
{
private:
	CUserIP *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CUserIPSingleIterator(CUserIPFactory *pFactory,CUserIP *pResult)
		:CUserIPIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CUserIPSingleIterator(void)
	{
	}

	///Ѱ����һ������������CUserIP
	///@return	��һ����������CUserIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserIPPredict���ж�һ������ԱIP��ַ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pUserIP	Ҫ���жϵĽ���ԱIP��ַ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserIP *pUserIP)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPAndPredict�Ƕ���������ԱIP��ַν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPAndPredict : public CUserIPPredict
{
private:
	CUserIPPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserIPAndPredict(CUserIPPredict *p1, CUserIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserIPAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserIP	Ҫ���жϵĽ���ԱIP��ַ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserIP *pUserIP)
	{
		return m_p1->isValid(pUserIP) && m_p2->isValid(pUserIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserIPOrPredict�Ƕ���������ԱIP��ַν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPOrPredict : public CUserIPPredict
{
private:
	CUserIPPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserIPOrPredict(CUserIPPredict *p1, CUserIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserIPOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserIP	Ҫ���жϵĽ���ԱIP��ַ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserIP *pUserIP)
	{
		return m_p1->isValid(pUserIP) || m_p2->isValid(pUserIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserIPNotPredict�Ƕ�һ������ԱIP��ַν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPNotPredict : public CUserIPPredict
{
private:
	CUserIPPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CUserIPNotPredict(CUserIPPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CUserIPNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserIP	Ҫ���жϵĽ���ԱIP��ַ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserIP *pUserIP)
	{
		return !m_predict->isValid(pUserIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserIPFilter��һ�������еĽ���ԱIP��ַö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPFilter: public CUserIPIterator
{
private:
	CUserIPIterator *m_baseIterator;
	CUserIPPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CUserIPFilter(CUserIPIterator *pBaseIterator, CUserIPPredict *pPredict, bool continueResult=false)
		:CUserIPIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CUserIPFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CUserIP
	///@return	��һ����������CUserIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserIPLinkIterator��������������ԱIP��ַö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPLinkIterator: public CUserIPIterator
{
private:
	CUserIPIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CUserIPLinkIterator(CUserIPIterator *pBaseIterator1,CUserIPIterator *pBaseIterator2)
		:CUserIPIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CUserIPLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CUserIP
	///@return	��һ����������CUserIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartClientSingleIterator�����෵��һ����Ա�ͻ���ϵ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientSingleIterator: public CPartClientIterator
{
private:
	CPartClient *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartClientSingleIterator(CPartClientFactory *pFactory,CPartClient *pResult)
		:CPartClientIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartClientSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientPredict���ж�һ����Ա�ͻ���ϵ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartClient	Ҫ���жϵĻ�Ա�ͻ���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClient *pPartClient)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientAndPredict�Ƕ�������Ա�ͻ���ϵν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientAndPredict : public CPartClientPredict
{
private:
	CPartClientPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartClientAndPredict(CPartClientPredict *p1, CPartClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartClientAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClient	Ҫ���жϵĻ�Ա�ͻ���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClient *pPartClient)
	{
		return m_p1->isValid(pPartClient) && m_p2->isValid(pPartClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOrPredict�Ƕ�������Ա�ͻ���ϵν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOrPredict : public CPartClientPredict
{
private:
	CPartClientPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartClientOrPredict(CPartClientPredict *p1, CPartClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartClientOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClient	Ҫ���жϵĻ�Ա�ͻ���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClient *pPartClient)
	{
		return m_p1->isValid(pPartClient) || m_p2->isValid(pPartClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientNotPredict�Ƕ�һ����Ա�ͻ���ϵν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientNotPredict : public CPartClientPredict
{
private:
	CPartClientPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartClientNotPredict(CPartClientPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartClientNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClient	Ҫ���жϵĻ�Ա�ͻ���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClient *pPartClient)
	{
		return !m_predict->isValid(pPartClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientFilter��һ�������еĻ�Ա�ͻ���ϵö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientFilter: public CPartClientIterator
{
private:
	CPartClientIterator *m_baseIterator;
	CPartClientPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartClientFilter(CPartClientIterator *pBaseIterator, CPartClientPredict *pPredict, bool continueResult=false)
		:CPartClientIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartClientFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientLinkIterator������������Ա�ͻ���ϵö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientLinkIterator: public CPartClientIterator
{
private:
	CPartClientIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartClientLinkIterator(CPartClientIterator *pBaseIterator1,CPartClientIterator *pBaseIterator2)
		:CPartClientIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartClientLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantOfPartClientIterator��һ����Ա�ͻ���ϵö������Ӧ�Ļ�Ա��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantOfPartClientIterator: public CParticipantIterator
{
private:
	CPartClientIterator *m_baseIterator;
	CParticipant *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CParticipantOfPartClientIterator(CParticipantFactory *pFactory,CPartClientIterator *pBaseIterator)
		:CParticipantIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CParticipantOfPartClientIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CParticipant
	///@return	��һ����������CParticipant������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CParticipant *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableParticipant *pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientOfPartClientIterator��һ����Ա�ͻ���ϵö������Ӧ�Ŀͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientOfPartClientIterator: public CClientIterator
{
private:
	CPartClientIterator *m_baseIterator;
	CClient *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CClientOfPartClientIterator(CClientFactory *pFactory,CPartClientIterator *pBaseIterator)
		:CClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CClientOfPartClientIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CClient
	///@return	��һ����������CClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClient *pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartSingleIterator�����෵��һ�����㽻�׻�Ա��ϵ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartSingleIterator: public CClearingTradingPartIterator
{
private:
	CClearingTradingPart *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CClearingTradingPartSingleIterator(CClearingTradingPartFactory *pFactory,CClearingTradingPart *pResult)
		:CClearingTradingPartIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CClearingTradingPartSingleIterator(void)
	{
	}

	///Ѱ����һ������������CClearingTradingPart
	///@return	��һ����������CClearingTradingPart������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingTradingPart *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingTradingPart ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartPredict���ж�һ�����㽻�׻�Ա��ϵ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pClearingTradingPart	Ҫ���жϵĽ��㽻�׻�Ա��ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartAndPredict�Ƕ��������㽻�׻�Ա��ϵν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartAndPredict : public CClearingTradingPartPredict
{
private:
	CClearingTradingPartPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClearingTradingPartAndPredict(CClearingTradingPartPredict *p1, CClearingTradingPartPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClearingTradingPartAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClearingTradingPart	Ҫ���жϵĽ��㽻�׻�Ա��ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)
	{
		return m_p1->isValid(pClearingTradingPart) && m_p2->isValid(pClearingTradingPart);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartOrPredict�Ƕ��������㽻�׻�Ա��ϵν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartOrPredict : public CClearingTradingPartPredict
{
private:
	CClearingTradingPartPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClearingTradingPartOrPredict(CClearingTradingPartPredict *p1, CClearingTradingPartPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClearingTradingPartOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClearingTradingPart	Ҫ���жϵĽ��㽻�׻�Ա��ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)
	{
		return m_p1->isValid(pClearingTradingPart) || m_p2->isValid(pClearingTradingPart);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartNotPredict�Ƕ�һ�����㽻�׻�Ա��ϵν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartNotPredict : public CClearingTradingPartPredict
{
private:
	CClearingTradingPartPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CClearingTradingPartNotPredict(CClearingTradingPartPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CClearingTradingPartNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClearingTradingPart	Ҫ���жϵĽ��㽻�׻�Ա��ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)
	{
		return !m_predict->isValid(pClearingTradingPart);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartFilter��һ�������еĽ��㽻�׻�Ա��ϵö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartFilter: public CClearingTradingPartIterator
{
private:
	CClearingTradingPartIterator *m_baseIterator;
	CClearingTradingPartPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CClearingTradingPartFilter(CClearingTradingPartIterator *pBaseIterator, CClearingTradingPartPredict *pPredict, bool continueResult=false)
		:CClearingTradingPartIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CClearingTradingPartFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CClearingTradingPart
	///@return	��һ����������CClearingTradingPart������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingTradingPart *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingTradingPart ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartLinkIterator�������������㽻�׻�Ա��ϵö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartLinkIterator: public CClearingTradingPartIterator
{
private:
	CClearingTradingPartIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CClearingTradingPartLinkIterator(CClearingTradingPartIterator *pBaseIterator1,CClearingTradingPartIterator *pBaseIterator2)
		:CClearingTradingPartIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CClearingTradingPartLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CClearingTradingPart
	///@return	��һ����������CClearingTradingPart������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingTradingPart *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingTradingPart ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CAliasDefineSingleIterator�����෵��һ�����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineSingleIterator: public CAliasDefineIterator
{
private:
	CAliasDefine *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CAliasDefineSingleIterator(CAliasDefineFactory *pFactory,CAliasDefine *pResult)
		:CAliasDefineIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CAliasDefineSingleIterator(void)
	{
	}

	///Ѱ����һ������������CAliasDefine
	///@return	��һ����������CAliasDefine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAliasDefine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAliasDefine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefinePredict���ж�һ�����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefinePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pAliasDefine	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAliasDefine *pAliasDefine)=0;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineAndPredict�Ƕ�������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineAndPredict : public CAliasDefinePredict
{
private:
	CAliasDefinePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CAliasDefineAndPredict(CAliasDefinePredict *p1, CAliasDefinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CAliasDefineAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pAliasDefine	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAliasDefine *pAliasDefine)
	{
		return m_p1->isValid(pAliasDefine) && m_p2->isValid(pAliasDefine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineOrPredict�Ƕ�������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineOrPredict : public CAliasDefinePredict
{
private:
	CAliasDefinePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CAliasDefineOrPredict(CAliasDefinePredict *p1, CAliasDefinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CAliasDefineOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pAliasDefine	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAliasDefine *pAliasDefine)
	{
		return m_p1->isValid(pAliasDefine) || m_p2->isValid(pAliasDefine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineNotPredict�Ƕ�һ����������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineNotPredict : public CAliasDefinePredict
{
private:
	CAliasDefinePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CAliasDefineNotPredict(CAliasDefinePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CAliasDefineNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pAliasDefine	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAliasDefine *pAliasDefine)
	{
		return !m_predict->isValid(pAliasDefine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineFilter��һ�������еı�������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineFilter: public CAliasDefineIterator
{
private:
	CAliasDefineIterator *m_baseIterator;
	CAliasDefinePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CAliasDefineFilter(CAliasDefineIterator *pBaseIterator, CAliasDefinePredict *pPredict, bool continueResult=false)
		:CAliasDefineIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CAliasDefineFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CAliasDefine
	///@return	��һ����������CAliasDefine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAliasDefine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAliasDefine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineLinkIterator������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineLinkIterator: public CAliasDefineIterator
{
private:
	CAliasDefineIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CAliasDefineLinkIterator(CAliasDefineIterator *pBaseIterator1,CAliasDefineIterator *pBaseIterator2)
		:CAliasDefineIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CAliasDefineLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CAliasDefine
	///@return	��һ����������CAliasDefine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAliasDefine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAliasDefine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightSingleIterator�����෵��һ���û�����Ȩ�޵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightSingleIterator: public CUserFunctionRightIterator
{
private:
	CUserFunctionRight *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CUserFunctionRightSingleIterator(CUserFunctionRightFactory *pFactory,CUserFunctionRight *pResult)
		:CUserFunctionRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CUserFunctionRightSingleIterator(void)
	{
	}

	///Ѱ����һ������������CUserFunctionRight
	///@return	��һ����������CUserFunctionRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserFunctionRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserFunctionRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightPredict���ж�һ���û�����Ȩ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pUserFunctionRight	Ҫ���жϵ��û�����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightAndPredict�Ƕ������û�����Ȩ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightAndPredict : public CUserFunctionRightPredict
{
private:
	CUserFunctionRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserFunctionRightAndPredict(CUserFunctionRightPredict *p1, CUserFunctionRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserFunctionRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserFunctionRight	Ҫ���жϵ��û�����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)
	{
		return m_p1->isValid(pUserFunctionRight) && m_p2->isValid(pUserFunctionRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightOrPredict�Ƕ������û�����Ȩ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightOrPredict : public CUserFunctionRightPredict
{
private:
	CUserFunctionRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserFunctionRightOrPredict(CUserFunctionRightPredict *p1, CUserFunctionRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserFunctionRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserFunctionRight	Ҫ���жϵ��û�����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)
	{
		return m_p1->isValid(pUserFunctionRight) || m_p2->isValid(pUserFunctionRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightNotPredict�Ƕ�һ���û�����Ȩ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightNotPredict : public CUserFunctionRightPredict
{
private:
	CUserFunctionRightPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CUserFunctionRightNotPredict(CUserFunctionRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CUserFunctionRightNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserFunctionRight	Ҫ���жϵ��û�����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)
	{
		return !m_predict->isValid(pUserFunctionRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightFilter��һ�������е��û�����Ȩ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightFilter: public CUserFunctionRightIterator
{
private:
	CUserFunctionRightIterator *m_baseIterator;
	CUserFunctionRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CUserFunctionRightFilter(CUserFunctionRightIterator *pBaseIterator, CUserFunctionRightPredict *pPredict, bool continueResult=false)
		:CUserFunctionRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CUserFunctionRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CUserFunctionRight
	///@return	��һ����������CUserFunctionRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserFunctionRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserFunctionRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightLinkIterator�����������û�����Ȩ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightLinkIterator: public CUserFunctionRightIterator
{
private:
	CUserFunctionRightIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CUserFunctionRightLinkIterator(CUserFunctionRightIterator *pBaseIterator1,CUserFunctionRightIterator *pBaseIterator2)
		:CUserFunctionRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CUserFunctionRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CUserFunctionRight
	///@return	��һ����������CUserFunctionRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserFunctionRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserFunctionRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CAccountSingleIterator�����෵��һ���ʽ��˻���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountSingleIterator: public CAccountIterator
{
private:
	CAccount *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CAccountSingleIterator(CAccountFactory *pFactory,CAccount *pResult)
		:CAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CAccountSingleIterator(void)
	{
	}

	///Ѱ����һ������������CAccount
	///@return	��һ����������CAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAccountPredict���ж�һ���ʽ��˻��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pAccount	Ҫ���жϵ��ʽ��˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAccount *pAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CAccountAndPredict�Ƕ������ʽ��˻�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountAndPredict : public CAccountPredict
{
private:
	CAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CAccountAndPredict(CAccountPredict *p1, CAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pAccount	Ҫ���жϵ��ʽ��˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAccount *pAccount)
	{
		return m_p1->isValid(pAccount) && m_p2->isValid(pAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAccountOrPredict�Ƕ������ʽ��˻�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountOrPredict : public CAccountPredict
{
private:
	CAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CAccountOrPredict(CAccountPredict *p1, CAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pAccount	Ҫ���жϵ��ʽ��˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAccount *pAccount)
	{
		return m_p1->isValid(pAccount) || m_p2->isValid(pAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAccountNotPredict�Ƕ�һ���ʽ��˻�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountNotPredict : public CAccountPredict
{
private:
	CAccountPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CAccountNotPredict(CAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CAccountNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pAccount	Ҫ���жϵ��ʽ��˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CAccount *pAccount)
	{
		return !m_predict->isValid(pAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAccountFilter��һ�������е��ʽ��˻�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountFilter: public CAccountIterator
{
private:
	CAccountIterator *m_baseIterator;
	CAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CAccountFilter(CAccountIterator *pBaseIterator, CAccountPredict *pPredict, bool continueResult=false)
		:CAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CAccount
	///@return	��һ����������CAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAccountLinkIterator�����������ʽ��˻�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountLinkIterator: public CAccountIterator
{
private:
	CAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CAccountLinkIterator(CAccountIterator *pBaseIterator1,CAccountIterator *pBaseIterator2)
		:CAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CAccount
	///@return	��һ����������CAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountOfAccountIterator��һ���ʽ��˻�ö������Ӧ�Ľ����˻���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountOfAccountIterator: public CTradingAccountIterator
{
private:
	CAccountIterator *m_baseIterator;
	CTradingAccount *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CTradingAccountOfAccountIterator(CTradingAccountFactory *pFactory,CAccountIterator *pBaseIterator)
		:CTradingAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CTradingAccountOfAccountIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CTradingAccount
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTradingAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTradingAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTradingAccount *pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserCommFluxSingleIterator�����෵��һ���û�ͨѶ����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxSingleIterator: public CUserCommFluxIterator
{
private:
	CUserCommFlux *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CUserCommFluxSingleIterator(CUserCommFluxFactory *pFactory,CUserCommFlux *pResult)
		:CUserCommFluxIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CUserCommFluxSingleIterator(void)
	{
	}

	///Ѱ����һ������������CUserCommFlux
	///@return	��һ����������CUserCommFlux������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserCommFlux *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserCommFlux ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxPredict���ж�һ���û�ͨѶ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pUserCommFlux	Ҫ���жϵ��û�ͨѶ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserCommFlux *pUserCommFlux)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxAndPredict�Ƕ������û�ͨѶ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxAndPredict : public CUserCommFluxPredict
{
private:
	CUserCommFluxPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserCommFluxAndPredict(CUserCommFluxPredict *p1, CUserCommFluxPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserCommFluxAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserCommFlux	Ҫ���жϵ��û�ͨѶ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserCommFlux *pUserCommFlux)
	{
		return m_p1->isValid(pUserCommFlux) && m_p2->isValid(pUserCommFlux);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxOrPredict�Ƕ������û�ͨѶ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxOrPredict : public CUserCommFluxPredict
{
private:
	CUserCommFluxPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserCommFluxOrPredict(CUserCommFluxPredict *p1, CUserCommFluxPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserCommFluxOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserCommFlux	Ҫ���жϵ��û�ͨѶ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserCommFlux *pUserCommFlux)
	{
		return m_p1->isValid(pUserCommFlux) || m_p2->isValid(pUserCommFlux);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxNotPredict�Ƕ�һ���û�ͨѶ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxNotPredict : public CUserCommFluxPredict
{
private:
	CUserCommFluxPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CUserCommFluxNotPredict(CUserCommFluxPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CUserCommFluxNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserCommFlux	Ҫ���жϵ��û�ͨѶ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserCommFlux *pUserCommFlux)
	{
		return !m_predict->isValid(pUserCommFlux);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxFilter��һ�������е��û�ͨѶ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxFilter: public CUserCommFluxIterator
{
private:
	CUserCommFluxIterator *m_baseIterator;
	CUserCommFluxPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CUserCommFluxFilter(CUserCommFluxIterator *pBaseIterator, CUserCommFluxPredict *pPredict, bool continueResult=false)
		:CUserCommFluxIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CUserCommFluxFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CUserCommFlux
	///@return	��һ����������CUserCommFlux������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserCommFlux *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserCommFlux ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxLinkIterator�����������û�ͨѶ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxLinkIterator: public CUserCommFluxIterator
{
private:
	CUserCommFluxIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CUserCommFluxLinkIterator(CUserCommFluxIterator *pBaseIterator1,CUserCommFluxIterator *pBaseIterator2)
		:CUserCommFluxIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CUserCommFluxLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CUserCommFlux
	///@return	��һ����������CUserCommFlux������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserCommFlux *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserCommFlux ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataLogSingleIterator�����෵��һ��������ˮ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogSingleIterator: public CMarketDataLogIterator
{
private:
	CMarketDataLog *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMarketDataLogSingleIterator(CMarketDataLogFactory *pFactory,CMarketDataLog *pResult)
		:CMarketDataLogIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMarketDataLogSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMarketDataLog
	///@return	��һ����������CMarketDataLog������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataLog *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataLog ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogPredict���ж�һ��������ˮ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataLog	Ҫ���жϵ�������ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataLog *pMarketDataLog)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogAndPredict�Ƕ�����������ˮν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogAndPredict : public CMarketDataLogPredict
{
private:
	CMarketDataLogPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataLogAndPredict(CMarketDataLogPredict *p1, CMarketDataLogPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataLogAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataLog	Ҫ���жϵ�������ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataLog *pMarketDataLog)
	{
		return m_p1->isValid(pMarketDataLog) && m_p2->isValid(pMarketDataLog);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogOrPredict�Ƕ�����������ˮν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogOrPredict : public CMarketDataLogPredict
{
private:
	CMarketDataLogPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataLogOrPredict(CMarketDataLogPredict *p1, CMarketDataLogPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataLogOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataLog	Ҫ���жϵ�������ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataLog *pMarketDataLog)
	{
		return m_p1->isValid(pMarketDataLog) || m_p2->isValid(pMarketDataLog);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogNotPredict�Ƕ�һ��������ˮν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogNotPredict : public CMarketDataLogPredict
{
private:
	CMarketDataLogPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMarketDataLogNotPredict(CMarketDataLogPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMarketDataLogNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataLog	Ҫ���жϵ�������ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataLog *pMarketDataLog)
	{
		return !m_predict->isValid(pMarketDataLog);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogFilter��һ�������е�������ˮö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogFilter: public CMarketDataLogIterator
{
private:
	CMarketDataLogIterator *m_baseIterator;
	CMarketDataLogPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMarketDataLogFilter(CMarketDataLogIterator *pBaseIterator, CMarketDataLogPredict *pPredict, bool continueResult=false)
		:CMarketDataLogIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMarketDataLogFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMarketDataLog
	///@return	��һ����������CMarketDataLog������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataLog *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataLog ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogLinkIterator����������������ˮö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogLinkIterator: public CMarketDataLogIterator
{
private:
	CMarketDataLogIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMarketDataLogLinkIterator(CMarketDataLogIterator *pBaseIterator1,CMarketDataLogIterator *pBaseIterator2)
		:CMarketDataLogIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMarketDataLogLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMarketDataLog
	///@return	��һ����������CMarketDataLog������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataLog *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataLog ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserSessionSingleIterator�����෵��һ������Ա���߻Ự��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionSingleIterator: public CUserSessionIterator
{
private:
	CUserSession *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CUserSessionSingleIterator(CUserSessionFactory *pFactory,CUserSession *pResult)
		:CUserSessionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CUserSessionSingleIterator(void)
	{
	}

	///Ѱ����һ������������CUserSession
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionPredict���ж�һ������Ա���߻Ự�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pUserSession	Ҫ���жϵĽ���Ա���߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserSession *pUserSession)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionAndPredict�Ƕ���������Ա���߻Ựν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionAndPredict : public CUserSessionPredict
{
private:
	CUserSessionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserSessionAndPredict(CUserSessionPredict *p1, CUserSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserSessionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserSession	Ҫ���жϵĽ���Ա���߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserSession *pUserSession)
	{
		return m_p1->isValid(pUserSession) && m_p2->isValid(pUserSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionOrPredict�Ƕ���������Ա���߻Ựν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionOrPredict : public CUserSessionPredict
{
private:
	CUserSessionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUserSessionOrPredict(CUserSessionPredict *p1, CUserSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUserSessionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserSession	Ҫ���жϵĽ���Ա���߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserSession *pUserSession)
	{
		return m_p1->isValid(pUserSession) || m_p2->isValid(pUserSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionNotPredict�Ƕ�һ������Ա���߻Ựν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionNotPredict : public CUserSessionPredict
{
private:
	CUserSessionPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CUserSessionNotPredict(CUserSessionPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CUserSessionNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUserSession	Ҫ���жϵĽ���Ա���߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUserSession *pUserSession)
	{
		return !m_predict->isValid(pUserSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionFilter��һ�������еĽ���Ա���߻Ựö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionFilter: public CUserSessionIterator
{
private:
	CUserSessionIterator *m_baseIterator;
	CUserSessionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CUserSessionFilter(CUserSessionIterator *pBaseIterator, CUserSessionPredict *pPredict, bool continueResult=false)
		:CUserSessionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CUserSessionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CUserSession
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionLinkIterator��������������Ա���߻Ựö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionLinkIterator: public CUserSessionIterator
{
private:
	CUserSessionIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CUserSessionLinkIterator(CUserSessionIterator *pBaseIterator1,CUserSessionIterator *pBaseIterator2)
		:CUserSessionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CUserSessionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CUserSession
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserOfUserSessionIterator��һ������Ա���߻Ựö������Ӧ�Ľ���Ա��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserOfUserSessionIterator: public CUserIterator
{
private:
	CUserSessionIterator *m_baseIterator;
	CUser *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CUserOfUserSessionIterator(CUserFactory *pFactory,CUserSessionIterator *pBaseIterator)
		:CUserIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CUserOfUserSessionIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CUser
	///@return	��һ����������CUser������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUser *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUser ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUser *pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMDSessionSingleIterator�����෵��һ�����鶩�������߻Ự��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionSingleIterator: public CMDSessionIterator
{
private:
	CMDSession *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMDSessionSingleIterator(CMDSessionFactory *pFactory,CMDSession *pResult)
		:CMDSessionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMDSessionSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMDSession
	///@return	��һ����������CMDSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMDSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMDSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionPredict���ж�һ�����鶩�������߻Ự�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMDSession	Ҫ���жϵ����鶩�������߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMDSession *pMDSession)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionAndPredict�Ƕ��������鶩�������߻Ựν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionAndPredict : public CMDSessionPredict
{
private:
	CMDSessionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMDSessionAndPredict(CMDSessionPredict *p1, CMDSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMDSessionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMDSession	Ҫ���жϵ����鶩�������߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMDSession *pMDSession)
	{
		return m_p1->isValid(pMDSession) && m_p2->isValid(pMDSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionOrPredict�Ƕ��������鶩�������߻Ựν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionOrPredict : public CMDSessionPredict
{
private:
	CMDSessionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMDSessionOrPredict(CMDSessionPredict *p1, CMDSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMDSessionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMDSession	Ҫ���жϵ����鶩�������߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMDSession *pMDSession)
	{
		return m_p1->isValid(pMDSession) || m_p2->isValid(pMDSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionNotPredict�Ƕ�һ�����鶩�������߻Ựν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionNotPredict : public CMDSessionPredict
{
private:
	CMDSessionPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMDSessionNotPredict(CMDSessionPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMDSessionNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMDSession	Ҫ���жϵ����鶩�������߻Ự
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMDSession *pMDSession)
	{
		return !m_predict->isValid(pMDSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionFilter��һ�������е����鶩�������߻Ựö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionFilter: public CMDSessionIterator
{
private:
	CMDSessionIterator *m_baseIterator;
	CMDSessionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMDSessionFilter(CMDSessionIterator *pBaseIterator, CMDSessionPredict *pPredict, bool continueResult=false)
		:CMDSessionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMDSessionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMDSession
	///@return	��һ����������CMDSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMDSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMDSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionLinkIterator�������������鶩�������߻Ựö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionLinkIterator: public CMDSessionIterator
{
private:
	CMDSessionIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMDSessionLinkIterator(CMDSessionIterator *pBaseIterator1,CMDSessionIterator *pBaseIterator2)
		:CMDSessionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMDSessionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMDSession
	///@return	��һ����������CMDSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMDSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMDSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CLoginInfoSingleIterator�����෵��һ���û���½�ǳ���Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoSingleIterator: public CLoginInfoIterator
{
private:
	CLoginInfo *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CLoginInfoSingleIterator(CLoginInfoFactory *pFactory,CLoginInfo *pResult)
		:CLoginInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CLoginInfoSingleIterator(void)
	{
	}

	///Ѱ����һ������������CLoginInfo
	///@return	��һ����������CLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CLoginInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoPredict���ж�һ���û���½�ǳ���Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pLoginInfo	Ҫ���жϵ��û���½�ǳ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CLoginInfo *pLoginInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoAndPredict�Ƕ������û���½�ǳ���Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoAndPredict : public CLoginInfoPredict
{
private:
	CLoginInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CLoginInfoAndPredict(CLoginInfoPredict *p1, CLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CLoginInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pLoginInfo	Ҫ���жϵ��û���½�ǳ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CLoginInfo *pLoginInfo)
	{
		return m_p1->isValid(pLoginInfo) && m_p2->isValid(pLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoOrPredict�Ƕ������û���½�ǳ���Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoOrPredict : public CLoginInfoPredict
{
private:
	CLoginInfoPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CLoginInfoOrPredict(CLoginInfoPredict *p1, CLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CLoginInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pLoginInfo	Ҫ���жϵ��û���½�ǳ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CLoginInfo *pLoginInfo)
	{
		return m_p1->isValid(pLoginInfo) || m_p2->isValid(pLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoNotPredict�Ƕ�һ���û���½�ǳ���Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoNotPredict : public CLoginInfoPredict
{
private:
	CLoginInfoPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CLoginInfoNotPredict(CLoginInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CLoginInfoNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pLoginInfo	Ҫ���жϵ��û���½�ǳ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CLoginInfo *pLoginInfo)
	{
		return !m_predict->isValid(pLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoFilter��һ�������е��û���½�ǳ���Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoFilter: public CLoginInfoIterator
{
private:
	CLoginInfoIterator *m_baseIterator;
	CLoginInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CLoginInfoFilter(CLoginInfoIterator *pBaseIterator, CLoginInfoPredict *pPredict, bool continueResult=false)
		:CLoginInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CLoginInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CLoginInfo
	///@return	��һ����������CLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CLoginInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoLinkIterator�����������û���½�ǳ���Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoLinkIterator: public CLoginInfoIterator
{
private:
	CLoginInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CLoginInfoLinkIterator(CLoginInfoIterator *pBaseIterator1,CLoginInfoIterator *pBaseIterator2)
		:CLoginInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CLoginInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CLoginInfo
	///@return	��һ����������CLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CLoginInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailSingleIterator�����෵��һ������г�������ϸ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailSingleIterator: public CDepthMarketDataDetailIterator
{
private:
	CDepthMarketDataDetail *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CDepthMarketDataDetailSingleIterator(CDepthMarketDataDetailFactory *pFactory,CDepthMarketDataDetail *pResult)
		:CDepthMarketDataDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CDepthMarketDataDetailSingleIterator(void)
	{
	}

	///Ѱ����һ������������CDepthMarketDataDetail
	///@return	��һ����������CDepthMarketDataDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketDataDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketDataDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailPredict���ж�һ������г�������ϸ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketDataDetail	Ҫ���жϵ�����г�������ϸ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailAndPredict�Ƕ���������г�������ϸν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailAndPredict : public CDepthMarketDataDetailPredict
{
private:
	CDepthMarketDataDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CDepthMarketDataDetailAndPredict(CDepthMarketDataDetailPredict *p1, CDepthMarketDataDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CDepthMarketDataDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketDataDetail	Ҫ���жϵ�����г�������ϸ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return m_p1->isValid(pDepthMarketDataDetail) && m_p2->isValid(pDepthMarketDataDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailOrPredict�Ƕ���������г�������ϸν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailOrPredict : public CDepthMarketDataDetailPredict
{
private:
	CDepthMarketDataDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CDepthMarketDataDetailOrPredict(CDepthMarketDataDetailPredict *p1, CDepthMarketDataDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CDepthMarketDataDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketDataDetail	Ҫ���жϵ�����г�������ϸ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return m_p1->isValid(pDepthMarketDataDetail) || m_p2->isValid(pDepthMarketDataDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailNotPredict�Ƕ�һ������г�������ϸν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailNotPredict : public CDepthMarketDataDetailPredict
{
private:
	CDepthMarketDataDetailPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CDepthMarketDataDetailNotPredict(CDepthMarketDataDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CDepthMarketDataDetailNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketDataDetail	Ҫ���жϵ�����г�������ϸ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return !m_predict->isValid(pDepthMarketDataDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailFilter��һ�������е�����г�������ϸö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailFilter: public CDepthMarketDataDetailIterator
{
private:
	CDepthMarketDataDetailIterator *m_baseIterator;
	CDepthMarketDataDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CDepthMarketDataDetailFilter(CDepthMarketDataDetailIterator *pBaseIterator, CDepthMarketDataDetailPredict *pPredict, bool continueResult=false)
		:CDepthMarketDataDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CDepthMarketDataDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CDepthMarketDataDetail
	///@return	��һ����������CDepthMarketDataDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketDataDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketDataDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailLinkIterator��������������г�������ϸö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailLinkIterator: public CDepthMarketDataDetailIterator
{
private:
	CDepthMarketDataDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CDepthMarketDataDetailLinkIterator(CDepthMarketDataDetailIterator *pBaseIterator1,CDepthMarketDataDetailIterator *pBaseIterator2)
		:CDepthMarketDataDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CDepthMarketDataDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CDepthMarketDataDetail
	///@return	��һ����������CDepthMarketDataDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketDataDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketDataDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailSingleIterator�����෵��һ����Լ����״̬��ˮ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailSingleIterator: public CInstrumentStatusDetailIterator
{
private:
	CInstrumentStatusDetail *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CInstrumentStatusDetailSingleIterator(CInstrumentStatusDetailFactory *pFactory,CInstrumentStatusDetail *pResult)
		:CInstrumentStatusDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CInstrumentStatusDetailSingleIterator(void)
	{
	}

	///Ѱ����һ������������CInstrumentStatusDetail
	///@return	��һ����������CInstrumentStatusDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatusDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatusDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailPredict���ж�һ����Լ����״̬��ˮ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatusDetail	Ҫ���жϵĺ�Լ����״̬��ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailAndPredict�Ƕ�������Լ����״̬��ˮν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailAndPredict : public CInstrumentStatusDetailPredict
{
private:
	CInstrumentStatusDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInstrumentStatusDetailAndPredict(CInstrumentStatusDetailPredict *p1, CInstrumentStatusDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInstrumentStatusDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatusDetail	Ҫ���жϵĺ�Լ����״̬��ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return m_p1->isValid(pInstrumentStatusDetail) && m_p2->isValid(pInstrumentStatusDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailOrPredict�Ƕ�������Լ����״̬��ˮν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailOrPredict : public CInstrumentStatusDetailPredict
{
private:
	CInstrumentStatusDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInstrumentStatusDetailOrPredict(CInstrumentStatusDetailPredict *p1, CInstrumentStatusDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInstrumentStatusDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatusDetail	Ҫ���жϵĺ�Լ����״̬��ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return m_p1->isValid(pInstrumentStatusDetail) || m_p2->isValid(pInstrumentStatusDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailNotPredict�Ƕ�һ����Լ����״̬��ˮν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailNotPredict : public CInstrumentStatusDetailPredict
{
private:
	CInstrumentStatusDetailPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CInstrumentStatusDetailNotPredict(CInstrumentStatusDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CInstrumentStatusDetailNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatusDetail	Ҫ���жϵĺ�Լ����״̬��ˮ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return !m_predict->isValid(pInstrumentStatusDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailFilter��һ�������еĺ�Լ����״̬��ˮö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailFilter: public CInstrumentStatusDetailIterator
{
private:
	CInstrumentStatusDetailIterator *m_baseIterator;
	CInstrumentStatusDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CInstrumentStatusDetailFilter(CInstrumentStatusDetailIterator *pBaseIterator, CInstrumentStatusDetailPredict *pPredict, bool continueResult=false)
		:CInstrumentStatusDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CInstrumentStatusDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CInstrumentStatusDetail
	///@return	��һ����������CInstrumentStatusDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatusDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatusDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailLinkIterator������������Լ����״̬��ˮö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailLinkIterator: public CInstrumentStatusDetailIterator
{
private:
	CInstrumentStatusDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CInstrumentStatusDetailLinkIterator(CInstrumentStatusDetailIterator *pBaseIterator1,CInstrumentStatusDetailIterator *pBaseIterator2)
		:CInstrumentStatusDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CInstrumentStatusDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CInstrumentStatusDetail
	///@return	��һ����������CInstrumentStatusDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatusDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatusDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CFrontStatusSingleIterator�����෵��һ��ǰ��״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusSingleIterator: public CFrontStatusIterator
{
private:
	CFrontStatus *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CFrontStatusSingleIterator(CFrontStatusFactory *pFactory,CFrontStatus *pResult)
		:CFrontStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CFrontStatusSingleIterator(void)
	{
	}

	///Ѱ����һ������������CFrontStatus
	///@return	��һ����������CFrontStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFrontStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFrontStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusPredict���ж�һ��ǰ��״̬�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pFrontStatus	Ҫ���жϵ�ǰ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFrontStatus *pFrontStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusAndPredict�Ƕ�����ǰ��״̬ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusAndPredict : public CFrontStatusPredict
{
private:
	CFrontStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CFrontStatusAndPredict(CFrontStatusPredict *p1, CFrontStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CFrontStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pFrontStatus	Ҫ���жϵ�ǰ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFrontStatus *pFrontStatus)
	{
		return m_p1->isValid(pFrontStatus) && m_p2->isValid(pFrontStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusOrPredict�Ƕ�����ǰ��״̬ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusOrPredict : public CFrontStatusPredict
{
private:
	CFrontStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CFrontStatusOrPredict(CFrontStatusPredict *p1, CFrontStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CFrontStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pFrontStatus	Ҫ���жϵ�ǰ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFrontStatus *pFrontStatus)
	{
		return m_p1->isValid(pFrontStatus) || m_p2->isValid(pFrontStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusNotPredict�Ƕ�һ��ǰ��״̬ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusNotPredict : public CFrontStatusPredict
{
private:
	CFrontStatusPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CFrontStatusNotPredict(CFrontStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CFrontStatusNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pFrontStatus	Ҫ���жϵ�ǰ��״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFrontStatus *pFrontStatus)
	{
		return !m_predict->isValid(pFrontStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusFilter��һ�������е�ǰ��״̬ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusFilter: public CFrontStatusIterator
{
private:
	CFrontStatusIterator *m_baseIterator;
	CFrontStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CFrontStatusFilter(CFrontStatusIterator *pBaseIterator, CFrontStatusPredict *pPredict, bool continueResult=false)
		:CFrontStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CFrontStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CFrontStatus
	///@return	��һ����������CFrontStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFrontStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFrontStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusLinkIterator����������ǰ��״̬ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusLinkIterator: public CFrontStatusIterator
{
private:
	CFrontStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CFrontStatusLinkIterator(CFrontStatusIterator *pBaseIterator1,CFrontStatusIterator *pBaseIterator2)
		:CFrontStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CFrontStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CFrontStatus
	///@return	��һ����������CFrontStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFrontStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFrontStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDSingleIterator�����෵��һ����󱾵ر����ŵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDSingleIterator: public CMaxLocalIDIterator
{
private:
	CMaxLocalID *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMaxLocalIDSingleIterator(CMaxLocalIDFactory *pFactory,CMaxLocalID *pResult)
		:CMaxLocalIDIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMaxLocalIDSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMaxLocalID
	///@return	��һ����������CMaxLocalID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMaxLocalID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMaxLocalID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDPredict���ж�һ����󱾵ر������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMaxLocalID	Ҫ���жϵ���󱾵ر�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMaxLocalID *pMaxLocalID)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDAndPredict�Ƕ�������󱾵ر�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDAndPredict : public CMaxLocalIDPredict
{
private:
	CMaxLocalIDPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMaxLocalIDAndPredict(CMaxLocalIDPredict *p1, CMaxLocalIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMaxLocalIDAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMaxLocalID	Ҫ���жϵ���󱾵ر�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMaxLocalID *pMaxLocalID)
	{
		return m_p1->isValid(pMaxLocalID) && m_p2->isValid(pMaxLocalID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDOrPredict�Ƕ�������󱾵ر�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDOrPredict : public CMaxLocalIDPredict
{
private:
	CMaxLocalIDPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMaxLocalIDOrPredict(CMaxLocalIDPredict *p1, CMaxLocalIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMaxLocalIDOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMaxLocalID	Ҫ���жϵ���󱾵ر�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMaxLocalID *pMaxLocalID)
	{
		return m_p1->isValid(pMaxLocalID) || m_p2->isValid(pMaxLocalID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDNotPredict�Ƕ�һ����󱾵ر�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDNotPredict : public CMaxLocalIDPredict
{
private:
	CMaxLocalIDPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMaxLocalIDNotPredict(CMaxLocalIDPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMaxLocalIDNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMaxLocalID	Ҫ���жϵ���󱾵ر�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMaxLocalID *pMaxLocalID)
	{
		return !m_predict->isValid(pMaxLocalID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDFilter��һ�������е���󱾵ر�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDFilter: public CMaxLocalIDIterator
{
private:
	CMaxLocalIDIterator *m_baseIterator;
	CMaxLocalIDPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMaxLocalIDFilter(CMaxLocalIDIterator *pBaseIterator, CMaxLocalIDPredict *pPredict, bool continueResult=false)
		:CMaxLocalIDIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMaxLocalIDFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMaxLocalID
	///@return	��һ����������CMaxLocalID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMaxLocalID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMaxLocalID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDLinkIterator������������󱾵ر�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDLinkIterator: public CMaxLocalIDIterator
{
private:
	CMaxLocalIDIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMaxLocalIDLinkIterator(CMaxLocalIDIterator *pBaseIterator1,CMaxLocalIDIterator *pBaseIterator2)
		:CMaxLocalIDIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMaxLocalIDLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMaxLocalID
	///@return	��һ����������CMaxLocalID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMaxLocalID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMaxLocalID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CBulletinSingleIterator�����෵��һ��������Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinSingleIterator: public CBulletinIterator
{
private:
	CBulletin *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CBulletinSingleIterator(CBulletinFactory *pFactory,CBulletin *pResult)
		:CBulletinIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CBulletinSingleIterator(void)
	{
	}

	///Ѱ����һ������������CBulletin
	///@return	��һ����������CBulletin������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBulletin *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBulletin ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBulletinPredict���ж�һ��������Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pBulletin	Ҫ���жϵĹ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBulletin *pBulletin)=0;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinAndPredict�Ƕ�����������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinAndPredict : public CBulletinPredict
{
private:
	CBulletinPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CBulletinAndPredict(CBulletinPredict *p1, CBulletinPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CBulletinAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBulletin	Ҫ���жϵĹ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBulletin *pBulletin)
	{
		return m_p1->isValid(pBulletin) && m_p2->isValid(pBulletin);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBulletinOrPredict�Ƕ�����������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinOrPredict : public CBulletinPredict
{
private:
	CBulletinPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CBulletinOrPredict(CBulletinPredict *p1, CBulletinPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CBulletinOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBulletin	Ҫ���жϵĹ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBulletin *pBulletin)
	{
		return m_p1->isValid(pBulletin) || m_p2->isValid(pBulletin);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBulletinNotPredict�Ƕ�һ��������Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinNotPredict : public CBulletinPredict
{
private:
	CBulletinPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CBulletinNotPredict(CBulletinPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CBulletinNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBulletin	Ҫ���жϵĹ�����Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBulletin *pBulletin)
	{
		return !m_predict->isValid(pBulletin);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBulletinFilter��һ�������еĹ�����Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinFilter: public CBulletinIterator
{
private:
	CBulletinIterator *m_baseIterator;
	CBulletinPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CBulletinFilter(CBulletinIterator *pBaseIterator, CBulletinPredict *pPredict, bool continueResult=false)
		:CBulletinIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CBulletinFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CBulletin
	///@return	��һ����������CBulletin������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBulletin *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBulletin ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBulletinLinkIterator����������������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinLinkIterator: public CBulletinIterator
{
private:
	CBulletinIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CBulletinLinkIterator(CBulletinIterator *pBaseIterator1,CBulletinIterator *pBaseIterator2)
		:CBulletinIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CBulletinLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CBulletin
	///@return	��һ����������CBulletin������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBulletin *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBulletin ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataModifySingleIterator�����෵��һ������䶯��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifySingleIterator: public CMarketDataModifyIterator
{
private:
	CMarketDataModify *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMarketDataModifySingleIterator(CMarketDataModifyFactory *pFactory,CMarketDataModify *pResult)
		:CMarketDataModifyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMarketDataModifySingleIterator(void)
	{
	}

	///Ѱ����һ������������CMarketDataModify
	///@return	��һ����������CMarketDataModify������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataModify *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataModify ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyPredict���ж�һ������䶯�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataModify	Ҫ���жϵ�����䶯
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataModify *pMarketDataModify)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyAndPredict�Ƕ���������䶯ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyAndPredict : public CMarketDataModifyPredict
{
private:
	CMarketDataModifyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataModifyAndPredict(CMarketDataModifyPredict *p1, CMarketDataModifyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataModifyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataModify	Ҫ���жϵ�����䶯
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataModify *pMarketDataModify)
	{
		return m_p1->isValid(pMarketDataModify) && m_p2->isValid(pMarketDataModify);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyOrPredict�Ƕ���������䶯ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyOrPredict : public CMarketDataModifyPredict
{
private:
	CMarketDataModifyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataModifyOrPredict(CMarketDataModifyPredict *p1, CMarketDataModifyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataModifyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataModify	Ҫ���жϵ�����䶯
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataModify *pMarketDataModify)
	{
		return m_p1->isValid(pMarketDataModify) || m_p2->isValid(pMarketDataModify);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyNotPredict�Ƕ�һ������䶯ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyNotPredict : public CMarketDataModifyPredict
{
private:
	CMarketDataModifyPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMarketDataModifyNotPredict(CMarketDataModifyPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMarketDataModifyNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketDataModify	Ҫ���жϵ�����䶯
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketDataModify *pMarketDataModify)
	{
		return !m_predict->isValid(pMarketDataModify);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyFilter��һ�������е�����䶯ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyFilter: public CMarketDataModifyIterator
{
private:
	CMarketDataModifyIterator *m_baseIterator;
	CMarketDataModifyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMarketDataModifyFilter(CMarketDataModifyIterator *pBaseIterator, CMarketDataModifyPredict *pPredict, bool continueResult=false)
		:CMarketDataModifyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMarketDataModifyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMarketDataModify
	///@return	��һ����������CMarketDataModify������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataModify *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataModify ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyLinkIterator��������������䶯ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyLinkIterator: public CMarketDataModifyIterator
{
private:
	CMarketDataModifyIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMarketDataModifyLinkIterator(CMarketDataModifyIterator *pBaseIterator1,CMarketDataModifyIterator *pBaseIterator2)
		:CMarketDataModifyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMarketDataModifyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMarketDataModify
	///@return	��һ����������CMarketDataModify������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataModify *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataModify ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataOfMarketDataModifyIterator��һ������䶯ö������Ӧ����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataOfMarketDataModifyIterator: public CDepthMarketDataIterator
{
private:
	CMarketDataModifyIterator *m_baseIterator;
	CDepthMarketData *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CDepthMarketDataOfMarketDataModifyIterator(CDepthMarketDataFactory *pFactory,CMarketDataModifyIterator *pBaseIterator)
		:CDepthMarketDataIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CDepthMarketDataOfMarketDataModifyIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CDepthMarketData
	///@return	��һ����������CDepthMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketData *pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataSingleIterator�����෵��һ����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataSingleIterator: public CDepthMarketDataIterator
{
private:
	CDepthMarketData *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CDepthMarketDataSingleIterator(CDepthMarketDataFactory *pFactory,CDepthMarketData *pResult)
		:CDepthMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CDepthMarketDataSingleIterator(void)
	{
	}

	///Ѱ����һ������������CDepthMarketData
	///@return	��һ����������CDepthMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataPredict���ж�һ����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketData	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketData *pDepthMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataAndPredict�Ƕ������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataAndPredict : public CDepthMarketDataPredict
{
private:
	CDepthMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CDepthMarketDataAndPredict(CDepthMarketDataPredict *p1, CDepthMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CDepthMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketData	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketData *pDepthMarketData)
	{
		return m_p1->isValid(pDepthMarketData) && m_p2->isValid(pDepthMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataOrPredict�Ƕ������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataOrPredict : public CDepthMarketDataPredict
{
private:
	CDepthMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CDepthMarketDataOrPredict(CDepthMarketDataPredict *p1, CDepthMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CDepthMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketData	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketData *pDepthMarketData)
	{
		return m_p1->isValid(pDepthMarketData) || m_p2->isValid(pDepthMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataNotPredict�Ƕ�һ���������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataNotPredict : public CDepthMarketDataPredict
{
private:
	CDepthMarketDataPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CDepthMarketDataNotPredict(CDepthMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CDepthMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pDepthMarketData	Ҫ���жϵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CDepthMarketData *pDepthMarketData)
	{
		return !m_predict->isValid(pDepthMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataFilter��һ�������е��������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataFilter: public CDepthMarketDataIterator
{
private:
	CDepthMarketDataIterator *m_baseIterator;
	CDepthMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CDepthMarketDataFilter(CDepthMarketDataIterator *pBaseIterator, CDepthMarketDataPredict *pPredict, bool continueResult=false)
		:CDepthMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CDepthMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CDepthMarketData
	///@return	��һ����������CDepthMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataLinkIterator�����������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataLinkIterator: public CDepthMarketDataIterator
{
private:
	CDepthMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CDepthMarketDataLinkIterator(CDepthMarketDataIterator *pBaseIterator1,CDepthMarketDataIterator *pBaseIterator2)
		:CDepthMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CDepthMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CDepthMarketData
	///@return	��һ����������CDepthMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfDepthMarketDataIterator��һ���������ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfDepthMarketDataIterator: public CInstrumentIterator
{
private:
	CDepthMarketDataIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfDepthMarketDataIterator(CInstrumentFactory *pFactory,CDepthMarketDataIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfDepthMarketDataIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataSingleIterator�����෵��һ�������������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataSingleIterator: public CTopicMarketDataIterator
{
private:
	CTopicMarketData *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CTopicMarketDataSingleIterator(CTopicMarketDataFactory *pFactory,CTopicMarketData *pResult)
		:CTopicMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CTopicMarketDataSingleIterator(void)
	{
	}

	///Ѱ����һ������������CTopicMarketData
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataPredict���ж�һ�������������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketData	Ҫ���жϵķ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketData *pTopicMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataAndPredict�Ƕ���������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataAndPredict : public CTopicMarketDataPredict
{
private:
	CTopicMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTopicMarketDataAndPredict(CTopicMarketDataPredict *p1, CTopicMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTopicMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketData	Ҫ���жϵķ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketData *pTopicMarketData)
	{
		return m_p1->isValid(pTopicMarketData) && m_p2->isValid(pTopicMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataOrPredict�Ƕ���������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataOrPredict : public CTopicMarketDataPredict
{
private:
	CTopicMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTopicMarketDataOrPredict(CTopicMarketDataPredict *p1, CTopicMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTopicMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketData	Ҫ���жϵķ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketData *pTopicMarketData)
	{
		return m_p1->isValid(pTopicMarketData) || m_p2->isValid(pTopicMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataNotPredict�Ƕ�һ������������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataNotPredict : public CTopicMarketDataPredict
{
private:
	CTopicMarketDataPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CTopicMarketDataNotPredict(CTopicMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CTopicMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketData	Ҫ���жϵķ���������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketData *pTopicMarketData)
	{
		return !m_predict->isValid(pTopicMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataFilter��һ�������еķ���������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataFilter: public CTopicMarketDataIterator
{
private:
	CTopicMarketDataIterator *m_baseIterator;
	CTopicMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CTopicMarketDataFilter(CTopicMarketDataIterator *pBaseIterator, CTopicMarketDataPredict *pPredict, bool continueResult=false)
		:CTopicMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CTopicMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CTopicMarketData
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataLinkIterator��������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataLinkIterator: public CTopicMarketDataIterator
{
private:
	CTopicMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CTopicMarketDataLinkIterator(CTopicMarketDataIterator *pBaseIterator1,CTopicMarketDataIterator *pBaseIterator2)
		:CTopicMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CTopicMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CTopicMarketData
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionSingleIterator�����෵��һ��������������յ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionSingleIterator: public CTopicMarketDataVersionIterator
{
private:
	CTopicMarketDataVersion *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CTopicMarketDataVersionSingleIterator(CTopicMarketDataVersionFactory *pFactory,CTopicMarketDataVersion *pResult)
		:CTopicMarketDataVersionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CTopicMarketDataVersionSingleIterator(void)
	{
	}

	///Ѱ����һ������������CTopicMarketDataVersion
	///@return	��һ����������CTopicMarketDataVersion������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketDataVersion ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionPredict���ж�һ����������������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketDataVersion	Ҫ���жϵķ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionAndPredict�Ƕ������������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionAndPredict : public CTopicMarketDataVersionPredict
{
private:
	CTopicMarketDataVersionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTopicMarketDataVersionAndPredict(CTopicMarketDataVersionPredict *p1, CTopicMarketDataVersionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTopicMarketDataVersionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketDataVersion	Ҫ���жϵķ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return m_p1->isValid(pTopicMarketDataVersion) && m_p2->isValid(pTopicMarketDataVersion);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionOrPredict�Ƕ������������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionOrPredict : public CTopicMarketDataVersionPredict
{
private:
	CTopicMarketDataVersionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTopicMarketDataVersionOrPredict(CTopicMarketDataVersionPredict *p1, CTopicMarketDataVersionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTopicMarketDataVersionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketDataVersion	Ҫ���жϵķ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return m_p1->isValid(pTopicMarketDataVersion) || m_p2->isValid(pTopicMarketDataVersion);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionNotPredict�Ƕ�һ���������������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionNotPredict : public CTopicMarketDataVersionPredict
{
private:
	CTopicMarketDataVersionPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CTopicMarketDataVersionNotPredict(CTopicMarketDataVersionPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CTopicMarketDataVersionNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTopicMarketDataVersion	Ҫ���жϵķ������������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return !m_predict->isValid(pTopicMarketDataVersion);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionFilter��һ�������еķ������������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionFilter: public CTopicMarketDataVersionIterator
{
private:
	CTopicMarketDataVersionIterator *m_baseIterator;
	CTopicMarketDataVersionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CTopicMarketDataVersionFilter(CTopicMarketDataVersionIterator *pBaseIterator, CTopicMarketDataVersionPredict *pPredict, bool continueResult=false)
		:CTopicMarketDataVersionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CTopicMarketDataVersionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CTopicMarketDataVersion
	///@return	��һ����������CTopicMarketDataVersion������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketDataVersion ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionLinkIterator�����������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionLinkIterator: public CTopicMarketDataVersionIterator
{
private:
	CTopicMarketDataVersionIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CTopicMarketDataVersionLinkIterator(CTopicMarketDataVersionIterator *pBaseIterator1,CTopicMarketDataVersionIterator *pBaseIterator2)
		:CTopicMarketDataVersionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CTopicMarketDataVersionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CTopicMarketDataVersion
	///@return	��һ����������CTopicMarketDataVersion������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketDataVersion ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInformationSingleIterator�����෵��һ����Ϣ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationSingleIterator: public CInformationIterator
{
private:
	CInformation *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CInformationSingleIterator(CInformationFactory *pFactory,CInformation *pResult)
		:CInformationIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CInformationSingleIterator(void)
	{
	}

	///Ѱ����һ������������CInformation
	///@return	��һ����������CInformation������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInformation *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInformation ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInformationPredict���ж�һ����Ϣ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pInformation	Ҫ���жϵ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInformation *pInformation)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInformationAndPredict�Ƕ�������Ϣν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationAndPredict : public CInformationPredict
{
private:
	CInformationPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInformationAndPredict(CInformationPredict *p1, CInformationPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInformationAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInformation	Ҫ���жϵ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInformation *pInformation)
	{
		return m_p1->isValid(pInformation) && m_p2->isValid(pInformation);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInformationOrPredict�Ƕ�������Ϣν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationOrPredict : public CInformationPredict
{
private:
	CInformationPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInformationOrPredict(CInformationPredict *p1, CInformationPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInformationOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInformation	Ҫ���жϵ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInformation *pInformation)
	{
		return m_p1->isValid(pInformation) || m_p2->isValid(pInformation);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInformationNotPredict�Ƕ�һ����Ϣν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationNotPredict : public CInformationPredict
{
private:
	CInformationPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CInformationNotPredict(CInformationPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CInformationNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInformation	Ҫ���жϵ���Ϣ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInformation *pInformation)
	{
		return !m_predict->isValid(pInformation);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInformationFilter��һ�������е���Ϣö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationFilter: public CInformationIterator
{
private:
	CInformationIterator *m_baseIterator;
	CInformationPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CInformationFilter(CInformationIterator *pBaseIterator, CInformationPredict *pPredict, bool continueResult=false)
		:CInformationIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CInformationFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CInformation
	///@return	��һ����������CInformation������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInformation *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInformation ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInformationLinkIterator������������Ϣö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationLinkIterator: public CInformationIterator
{
private:
	CInformationIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CInformationLinkIterator(CInformationIterator *pBaseIterator1,CInformationIterator *pBaseIterator2)
		:CInformationIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CInformationLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CInformation
	///@return	��һ����������CInformation������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInformation *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInformation ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///COrderCountSingleIterator�����෵��һ������������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountSingleIterator: public COrderCountIterator
{
private:
	COrderCount *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	COrderCountSingleIterator(COrderCountFactory *pFactory,COrderCount *pResult)
		:COrderCountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~COrderCountSingleIterator(void)
	{
	}

	///Ѱ����һ������������COrderCount
	///@return	��һ����������COrderCount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrderCount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrderCount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderCountPredict���ж�һ�����������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pOrderCount	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrderCount *pOrderCount)=0;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountAndPredict�Ƕ�������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountAndPredict : public COrderCountPredict
{
private:
	COrderCountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	COrderCountAndPredict(COrderCountPredict *p1, COrderCountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~COrderCountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOrderCount	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrderCount *pOrderCount)
	{
		return m_p1->isValid(pOrderCount) && m_p2->isValid(pOrderCount);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderCountOrPredict�Ƕ�������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountOrPredict : public COrderCountPredict
{
private:
	COrderCountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	COrderCountOrPredict(COrderCountPredict *p1, COrderCountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~COrderCountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOrderCount	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrderCount *pOrderCount)
	{
		return m_p1->isValid(pOrderCount) || m_p2->isValid(pOrderCount);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderCountNotPredict�Ƕ�һ����������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountNotPredict : public COrderCountPredict
{
private:
	COrderCountPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	COrderCountNotPredict(COrderCountPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~COrderCountNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOrderCount	Ҫ���жϵı�������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrderCount *pOrderCount)
	{
		return !m_predict->isValid(pOrderCount);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderCountFilter��һ�������еı�������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountFilter: public COrderCountIterator
{
private:
	COrderCountIterator *m_baseIterator;
	COrderCountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	COrderCountFilter(COrderCountIterator *pBaseIterator, COrderCountPredict *pPredict, bool continueResult=false)
		:COrderCountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~COrderCountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������COrderCount
	///@return	��һ����������COrderCount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrderCount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrderCount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderCountLinkIterator������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountLinkIterator: public COrderCountIterator
{
private:
	COrderCountIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	COrderCountLinkIterator(COrderCountIterator *pBaseIterator1,COrderCountIterator *pBaseIterator2)
		:COrderCountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~COrderCountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������COrderCount
	///@return	��һ����������COrderCount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrderCount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrderCount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentSingleIterator�����෵��һ����Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentSingleIterator: public CInstrumentIterator
{
private:
	CInstrument *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CInstrumentSingleIterator(CInstrumentFactory *pFactory,CInstrument *pResult)
		:CInstrumentIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CInstrumentSingleIterator(void)
	{
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentPredict���ж�һ����Լ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pInstrument	Ҫ���жϵĺ�Լ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrument *pInstrument)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentAndPredict�Ƕ�������Լν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentAndPredict : public CInstrumentPredict
{
private:
	CInstrumentPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInstrumentAndPredict(CInstrumentPredict *p1, CInstrumentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInstrumentAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrument	Ҫ���жϵĺ�Լ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrument *pInstrument)
	{
		return m_p1->isValid(pInstrument) && m_p2->isValid(pInstrument);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOrPredict�Ƕ�������Լν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOrPredict : public CInstrumentPredict
{
private:
	CInstrumentPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInstrumentOrPredict(CInstrumentPredict *p1, CInstrumentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInstrumentOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrument	Ҫ���жϵĺ�Լ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrument *pInstrument)
	{
		return m_p1->isValid(pInstrument) || m_p2->isValid(pInstrument);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentNotPredict�Ƕ�һ����Լν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentNotPredict : public CInstrumentPredict
{
private:
	CInstrumentPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CInstrumentNotPredict(CInstrumentPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CInstrumentNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrument	Ҫ���жϵĺ�Լ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrument *pInstrument)
	{
		return !m_predict->isValid(pInstrument);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentFilter��һ�������еĺ�Լö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentFilter: public CInstrumentIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CInstrumentPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CInstrumentFilter(CInstrumentIterator *pBaseIterator, CInstrumentPredict *pPredict, bool continueResult=false)
		:CInstrumentIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CInstrumentFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentLinkIterator������������Լö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentLinkIterator: public CInstrumentIterator
{
private:
	CInstrumentIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CInstrumentLinkIterator(CInstrumentIterator *pBaseIterator1,CInstrumentIterator *pBaseIterator2)
		:CInstrumentIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CInstrumentLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseInstrumentOfInstrumentIterator��һ����Լö������Ӧ�Ļ�����Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseInstrumentOfInstrumentIterator: public CInstrumentIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CBaseInstrumentOfInstrumentIterator(CInstrumentFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CBaseInstrumentOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentPropertyOfInstrumentIterator��һ����Լö������Ӧ�ĺ�Լ���Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentPropertyOfInstrumentIterator: public CCurrInstrumentPropertyIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CCurrInstrumentProperty *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentPropertyOfInstrumentIterator(CCurrInstrumentPropertyFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CCurrInstrumentPropertyIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentPropertyOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CCurrInstrumentProperty
	///@return	��һ����������CCurrInstrumentProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusOfInstrumentIterator��һ����Լö������Ӧ�ĺ�Լ״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusOfInstrumentIterator: public CInstrumentStatusIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CInstrumentStatus *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentStatusOfInstrumentIterator(CInstrumentStatusFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CInstrumentStatusIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentStatusOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrumentStatus
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatus *pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataOfInstrumentIterator��һ����Լö������Ӧ�������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataOfInstrumentIterator: public CMarketDataIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CMarketData *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CMarketDataOfInstrumentIterator(CMarketDataFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CMarketDataIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CMarketDataOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CMarketData
	///@return	��һ����������CMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketData *pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleOfInstrumentIterator��һ����Լö������Ӧ�����ڱ�ֵ�����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleOfInstrumentIterator: public CCurrHedgeRuleIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CCurrHedgeRule *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CCurrHedgeRuleOfInstrumentIterator(CCurrHedgeRuleFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CCurrHedgeRuleIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CCurrHedgeRuleOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CCurrHedgeRule
	///@return	��һ����������CCurrHedgeRule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrHedgeRule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrHedgeRule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrHedgeRule *pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseOfInstrumentIterator��һ����Լö������Ӧ���۶Ϲ����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseOfInstrumentIterator: public CCurrFuseIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CCurrFuse *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CCurrFuseOfInstrumentIterator(CCurrFuseFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CCurrFuseIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CCurrFuseOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CCurrFuse
	///@return	��һ����������CCurrFuse������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrFuse *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrFuse ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrFuse *pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseOfInstrumentIterator��һ����Լö������Ӧ���۶�״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseOfInstrumentIterator: public CFusePhaseIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CFusePhase *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CFusePhaseOfInstrumentIterator(CFusePhaseFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CFusePhaseIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CFusePhaseOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CFusePhase
	///@return	��һ����������CFusePhase������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFusePhase *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFusePhase ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFusePhase *pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitOfInstrumentIterator��һ����Լö������Ӧ���ǵ�ͣ�����õ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitOfInstrumentIterator: public CBasePriceLimitIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CBasePriceLimit *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CBasePriceLimitOfInstrumentIterator(CBasePriceLimitFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CBasePriceLimitIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CBasePriceLimitOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CBasePriceLimit
	///@return	��һ����������CBasePriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBasePriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBasePriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBasePriceLimit *pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureOfInstrumentIterator��һ����Լö������Ӧ�ĵ����������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureOfInstrumentIterator: public CUniPressureIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CUniPressure *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CUniPressureOfInstrumentIterator(CUniPressureFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CUniPressureIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CUniPressureOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CUniPressure
	///@return	��һ����������CUniPressure������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUniPressure *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUniPressure ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUniPressure *pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusOfInstrumentIterator��һ����Լö������Ӧ�Ľ�����ͬ��״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusOfInstrumentIterator: public CSGDataSyncStatusIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CSGDataSyncStatus *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CSGDataSyncStatusOfInstrumentIterator(CSGDataSyncStatusFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CSGDataSyncStatusIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CSGDataSyncStatusOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CSGDataSyncStatus
	///@return	��һ����������CSGDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSGDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSGDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus *pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCombinationLegSingleIterator�����෵��һ����Ϻ�Լ���ȵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegSingleIterator: public CCombinationLegIterator
{
private:
	CCombinationLeg *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCombinationLegSingleIterator(CCombinationLegFactory *pFactory,CCombinationLeg *pResult)
		:CCombinationLegIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCombinationLegSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCombinationLeg
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombinationLeg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombinationLeg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegPredict���ж�һ����Ϻ�Լ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCombinationLeg	Ҫ���жϵ���Ϻ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombinationLeg *pCombinationLeg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegAndPredict�Ƕ�������Ϻ�Լ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegAndPredict : public CCombinationLegPredict
{
private:
	CCombinationLegPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCombinationLegAndPredict(CCombinationLegPredict *p1, CCombinationLegPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCombinationLegAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCombinationLeg	Ҫ���жϵ���Ϻ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombinationLeg *pCombinationLeg)
	{
		return m_p1->isValid(pCombinationLeg) && m_p2->isValid(pCombinationLeg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegOrPredict�Ƕ�������Ϻ�Լ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegOrPredict : public CCombinationLegPredict
{
private:
	CCombinationLegPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCombinationLegOrPredict(CCombinationLegPredict *p1, CCombinationLegPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCombinationLegOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCombinationLeg	Ҫ���жϵ���Ϻ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombinationLeg *pCombinationLeg)
	{
		return m_p1->isValid(pCombinationLeg) || m_p2->isValid(pCombinationLeg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegNotPredict�Ƕ�һ����Ϻ�Լ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegNotPredict : public CCombinationLegPredict
{
private:
	CCombinationLegPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCombinationLegNotPredict(CCombinationLegPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCombinationLegNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCombinationLeg	Ҫ���жϵ���Ϻ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombinationLeg *pCombinationLeg)
	{
		return !m_predict->isValid(pCombinationLeg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegFilter��һ�������е���Ϻ�Լ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegFilter: public CCombinationLegIterator
{
private:
	CCombinationLegIterator *m_baseIterator;
	CCombinationLegPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCombinationLegFilter(CCombinationLegIterator *pBaseIterator, CCombinationLegPredict *pPredict, bool continueResult=false)
		:CCombinationLegIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCombinationLegFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCombinationLeg
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombinationLeg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombinationLeg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegLinkIterator������������Ϻ�Լ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegLinkIterator: public CCombinationLegIterator
{
private:
	CCombinationLegIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCombinationLegLinkIterator(CCombinationLegIterator *pBaseIterator1,CCombinationLegIterator *pBaseIterator2)
		:CCombinationLegIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCombinationLegLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCombinationLeg
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombinationLeg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombinationLeg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationInstrumentOfCombinationLegIterator��һ����Ϻ�Լ����ö������Ӧ����Ϻ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationInstrumentOfCombinationLegIterator: public CInstrumentIterator
{
private:
	CCombinationLegIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CCombinationInstrumentOfCombinationLegIterator(CInstrumentFactory *pFactory,CCombinationLegIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CCombinationInstrumentOfCombinationLegIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CLegInstrumentOfCombinationLegIterator��һ����Ϻ�Լ����ö������Ӧ�ĵ��Ⱥ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLegInstrumentOfCombinationLegIterator: public CInstrumentIterator
{
private:
	CCombinationLegIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CLegInstrumentOfCombinationLegIterator(CInstrumentFactory *pFactory,CCombinationLegIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CLegInstrumentOfCombinationLegIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountSingleIterator�����෵��һ����Ա�˻���ϵ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountSingleIterator: public CPartRoleAccountIterator
{
private:
	CPartRoleAccount *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartRoleAccountSingleIterator(CPartRoleAccountFactory *pFactory,CPartRoleAccount *pResult)
		:CPartRoleAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartRoleAccountSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartRoleAccount
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartRoleAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartRoleAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountPredict���ж�һ����Ա�˻���ϵ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartRoleAccount	Ҫ���жϵĻ�Ա�˻���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountAndPredict�Ƕ�������Ա�˻���ϵν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountAndPredict : public CPartRoleAccountPredict
{
private:
	CPartRoleAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartRoleAccountAndPredict(CPartRoleAccountPredict *p1, CPartRoleAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartRoleAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartRoleAccount	Ҫ���жϵĻ�Ա�˻���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)
	{
		return m_p1->isValid(pPartRoleAccount) && m_p2->isValid(pPartRoleAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountOrPredict�Ƕ�������Ա�˻���ϵν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountOrPredict : public CPartRoleAccountPredict
{
private:
	CPartRoleAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartRoleAccountOrPredict(CPartRoleAccountPredict *p1, CPartRoleAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartRoleAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartRoleAccount	Ҫ���жϵĻ�Ա�˻���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)
	{
		return m_p1->isValid(pPartRoleAccount) || m_p2->isValid(pPartRoleAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountNotPredict�Ƕ�һ����Ա�˻���ϵν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountNotPredict : public CPartRoleAccountPredict
{
private:
	CPartRoleAccountPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartRoleAccountNotPredict(CPartRoleAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartRoleAccountNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartRoleAccount	Ҫ���жϵĻ�Ա�˻���ϵ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)
	{
		return !m_predict->isValid(pPartRoleAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountFilter��һ�������еĻ�Ա�˻���ϵö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountFilter: public CPartRoleAccountIterator
{
private:
	CPartRoleAccountIterator *m_baseIterator;
	CPartRoleAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartRoleAccountFilter(CPartRoleAccountIterator *pBaseIterator, CPartRoleAccountPredict *pPredict, bool continueResult=false)
		:CPartRoleAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartRoleAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartRoleAccount
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartRoleAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartRoleAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountLinkIterator������������Ա�˻���ϵö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountLinkIterator: public CPartRoleAccountIterator
{
private:
	CPartRoleAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartRoleAccountLinkIterator(CPartRoleAccountIterator *pBaseIterator1,CPartRoleAccountIterator *pBaseIterator2)
		:CPartRoleAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartRoleAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartRoleAccount
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartRoleAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartRoleAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountOfPartRoleAccountIterator��һ����Ա�˻���ϵö������Ӧ���ʻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountOfPartRoleAccountIterator: public CTradingAccountIterator
{
private:
	CPartRoleAccountIterator *m_baseIterator;
	CTradingAccount *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CTradingAccountOfPartRoleAccountIterator(CTradingAccountFactory *pFactory,CPartRoleAccountIterator *pBaseIterator)
		:CTradingAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CTradingAccountOfPartRoleAccountIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CTradingAccount
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTradingAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTradingAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTradingAccount *pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartProductRoleSingleIterator�����෵��һ����Ա��Ʒ��ɫ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleSingleIterator: public CPartProductRoleIterator
{
private:
	CPartProductRole *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartProductRoleSingleIterator(CPartProductRoleFactory *pFactory,CPartProductRole *pResult)
		:CPartProductRoleIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartProductRoleSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartProductRole
	///@return	��һ����������CPartProductRole������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRole *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRole ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRolePredict���ж�һ����Ա��Ʒ��ɫ�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRolePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRole	Ҫ���жϵĻ�Ա��Ʒ��ɫ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRole *pPartProductRole)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleAndPredict�Ƕ�������Ա��Ʒ��ɫν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleAndPredict : public CPartProductRolePredict
{
private:
	CPartProductRolePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartProductRoleAndPredict(CPartProductRolePredict *p1, CPartProductRolePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartProductRoleAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRole	Ҫ���жϵĻ�Ա��Ʒ��ɫ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRole *pPartProductRole)
	{
		return m_p1->isValid(pPartProductRole) && m_p2->isValid(pPartProductRole);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleOrPredict�Ƕ�������Ա��Ʒ��ɫν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleOrPredict : public CPartProductRolePredict
{
private:
	CPartProductRolePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartProductRoleOrPredict(CPartProductRolePredict *p1, CPartProductRolePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartProductRoleOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRole	Ҫ���жϵĻ�Ա��Ʒ��ɫ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRole *pPartProductRole)
	{
		return m_p1->isValid(pPartProductRole) || m_p2->isValid(pPartProductRole);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleNotPredict�Ƕ�һ����Ա��Ʒ��ɫν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleNotPredict : public CPartProductRolePredict
{
private:
	CPartProductRolePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartProductRoleNotPredict(CPartProductRolePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartProductRoleNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRole	Ҫ���жϵĻ�Ա��Ʒ��ɫ
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRole *pPartProductRole)
	{
		return !m_predict->isValid(pPartProductRole);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleFilter��һ�������еĻ�Ա��Ʒ��ɫö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleFilter: public CPartProductRoleIterator
{
private:
	CPartProductRoleIterator *m_baseIterator;
	CPartProductRolePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartProductRoleFilter(CPartProductRoleIterator *pBaseIterator, CPartProductRolePredict *pPredict, bool continueResult=false)
		:CPartProductRoleIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartProductRoleFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartProductRole
	///@return	��һ����������CPartProductRole������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRole *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRole ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleLinkIterator������������Ա��Ʒ��ɫö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleLinkIterator: public CPartProductRoleIterator
{
private:
	CPartProductRoleIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartProductRoleLinkIterator(CPartProductRoleIterator *pBaseIterator1,CPartProductRoleIterator *pBaseIterator2)
		:CPartProductRoleIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartProductRoleLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartProductRole
	///@return	��һ����������CPartProductRole������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRole *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRole ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartProductRightSingleIterator�����෵��һ����Ա��Ʒ����Ȩ�޵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightSingleIterator: public CPartProductRightIterator
{
private:
	CPartProductRight *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartProductRightSingleIterator(CPartProductRightFactory *pFactory,CPartProductRight *pResult)
		:CPartProductRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartProductRightSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartProductRight
	///@return	��һ����������CPartProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightPredict���ж�һ����Ա��Ʒ����Ȩ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRight	Ҫ���жϵĻ�Ա��Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRight *pPartProductRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightAndPredict�Ƕ�������Ա��Ʒ����Ȩ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightAndPredict : public CPartProductRightPredict
{
private:
	CPartProductRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartProductRightAndPredict(CPartProductRightPredict *p1, CPartProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartProductRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRight	Ҫ���жϵĻ�Ա��Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRight *pPartProductRight)
	{
		return m_p1->isValid(pPartProductRight) && m_p2->isValid(pPartProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightOrPredict�Ƕ�������Ա��Ʒ����Ȩ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightOrPredict : public CPartProductRightPredict
{
private:
	CPartProductRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartProductRightOrPredict(CPartProductRightPredict *p1, CPartProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartProductRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRight	Ҫ���жϵĻ�Ա��Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRight *pPartProductRight)
	{
		return m_p1->isValid(pPartProductRight) || m_p2->isValid(pPartProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightNotPredict�Ƕ�һ����Ա��Ʒ����Ȩ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightNotPredict : public CPartProductRightPredict
{
private:
	CPartProductRightPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartProductRightNotPredict(CPartProductRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartProductRightNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartProductRight	Ҫ���жϵĻ�Ա��Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartProductRight *pPartProductRight)
	{
		return !m_predict->isValid(pPartProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightFilter��һ�������еĻ�Ա��Ʒ����Ȩ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightFilter: public CPartProductRightIterator
{
private:
	CPartProductRightIterator *m_baseIterator;
	CPartProductRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartProductRightFilter(CPartProductRightIterator *pBaseIterator, CPartProductRightPredict *pPredict, bool continueResult=false)
		:CPartProductRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartProductRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartProductRight
	///@return	��һ����������CPartProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightLinkIterator������������Ա��Ʒ����Ȩ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightLinkIterator: public CPartProductRightIterator
{
private:
	CPartProductRightIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartProductRightLinkIterator(CPartProductRightIterator *pBaseIterator1,CPartProductRightIterator *pBaseIterator2)
		:CPartProductRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartProductRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartProductRight
	///@return	��һ����������CPartProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightSingleIterator�����෵��һ����Ա��Լ����Ȩ�޵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightSingleIterator: public CPartInstrumentRightIterator
{
private:
	CPartInstrumentRight *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartInstrumentRightSingleIterator(CPartInstrumentRightFactory *pFactory,CPartInstrumentRight *pResult)
		:CPartInstrumentRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartInstrumentRightSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartInstrumentRight
	///@return	��һ����������CPartInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightPredict���ж�һ����Ա��Լ����Ȩ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartInstrumentRight	Ҫ���жϵĻ�Ա��Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightAndPredict�Ƕ�������Ա��Լ����Ȩ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightAndPredict : public CPartInstrumentRightPredict
{
private:
	CPartInstrumentRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartInstrumentRightAndPredict(CPartInstrumentRightPredict *p1, CPartInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartInstrumentRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartInstrumentRight	Ҫ���жϵĻ�Ա��Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)
	{
		return m_p1->isValid(pPartInstrumentRight) && m_p2->isValid(pPartInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightOrPredict�Ƕ�������Ա��Լ����Ȩ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightOrPredict : public CPartInstrumentRightPredict
{
private:
	CPartInstrumentRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartInstrumentRightOrPredict(CPartInstrumentRightPredict *p1, CPartInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartInstrumentRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartInstrumentRight	Ҫ���жϵĻ�Ա��Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)
	{
		return m_p1->isValid(pPartInstrumentRight) || m_p2->isValid(pPartInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightNotPredict�Ƕ�һ����Ա��Լ����Ȩ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightNotPredict : public CPartInstrumentRightPredict
{
private:
	CPartInstrumentRightPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartInstrumentRightNotPredict(CPartInstrumentRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartInstrumentRightNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartInstrumentRight	Ҫ���жϵĻ�Ա��Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)
	{
		return !m_predict->isValid(pPartInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightFilter��һ�������еĻ�Ա��Լ����Ȩ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightFilter: public CPartInstrumentRightIterator
{
private:
	CPartInstrumentRightIterator *m_baseIterator;
	CPartInstrumentRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartInstrumentRightFilter(CPartInstrumentRightIterator *pBaseIterator, CPartInstrumentRightPredict *pPredict, bool continueResult=false)
		:CPartInstrumentRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartInstrumentRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartInstrumentRight
	///@return	��һ����������CPartInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightLinkIterator������������Ա��Լ����Ȩ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightLinkIterator: public CPartInstrumentRightIterator
{
private:
	CPartInstrumentRightIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartInstrumentRightLinkIterator(CPartInstrumentRightIterator *pBaseIterator1,CPartInstrumentRightIterator *pBaseIterator2)
		:CPartInstrumentRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartInstrumentRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartInstrumentRight
	///@return	��һ����������CPartInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientProductRightSingleIterator�����෵��һ���ͻ���Ʒ����Ȩ�޵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightSingleIterator: public CClientProductRightIterator
{
private:
	CClientProductRight *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CClientProductRightSingleIterator(CClientProductRightFactory *pFactory,CClientProductRight *pResult)
		:CClientProductRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CClientProductRightSingleIterator(void)
	{
	}

	///Ѱ����һ������������CClientProductRight
	///@return	��һ����������CClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightPredict���ж�һ���ͻ���Ʒ����Ȩ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pClientProductRight	Ҫ���жϵĿͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientProductRight *pClientProductRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightAndPredict�Ƕ������ͻ���Ʒ����Ȩ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightAndPredict : public CClientProductRightPredict
{
private:
	CClientProductRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientProductRightAndPredict(CClientProductRightPredict *p1, CClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientProductRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientProductRight	Ҫ���жϵĿͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientProductRight *pClientProductRight)
	{
		return m_p1->isValid(pClientProductRight) && m_p2->isValid(pClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightOrPredict�Ƕ������ͻ���Ʒ����Ȩ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightOrPredict : public CClientProductRightPredict
{
private:
	CClientProductRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientProductRightOrPredict(CClientProductRightPredict *p1, CClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientProductRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientProductRight	Ҫ���жϵĿͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientProductRight *pClientProductRight)
	{
		return m_p1->isValid(pClientProductRight) || m_p2->isValid(pClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightNotPredict�Ƕ�һ���ͻ���Ʒ����Ȩ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightNotPredict : public CClientProductRightPredict
{
private:
	CClientProductRightPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CClientProductRightNotPredict(CClientProductRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CClientProductRightNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientProductRight	Ҫ���жϵĿͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientProductRight *pClientProductRight)
	{
		return !m_predict->isValid(pClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightFilter��һ�������еĿͻ���Ʒ����Ȩ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightFilter: public CClientProductRightIterator
{
private:
	CClientProductRightIterator *m_baseIterator;
	CClientProductRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CClientProductRightFilter(CClientProductRightIterator *pBaseIterator, CClientProductRightPredict *pPredict, bool continueResult=false)
		:CClientProductRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CClientProductRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CClientProductRight
	///@return	��һ����������CClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightLinkIterator�����������ͻ���Ʒ����Ȩ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightLinkIterator: public CClientProductRightIterator
{
private:
	CClientProductRightIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CClientProductRightLinkIterator(CClientProductRightIterator *pBaseIterator1,CClientProductRightIterator *pBaseIterator2)
		:CClientProductRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CClientProductRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CClientProductRight
	///@return	��һ����������CClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightSingleIterator�����෵��һ���ͻ���Լ����Ȩ�޵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightSingleIterator: public CClientInstrumentRightIterator
{
private:
	CClientInstrumentRight *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CClientInstrumentRightSingleIterator(CClientInstrumentRightFactory *pFactory,CClientInstrumentRight *pResult)
		:CClientInstrumentRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CClientInstrumentRightSingleIterator(void)
	{
	}

	///Ѱ����һ������������CClientInstrumentRight
	///@return	��һ����������CClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightPredict���ж�һ���ͻ���Լ����Ȩ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pClientInstrumentRight	Ҫ���жϵĿͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightAndPredict�Ƕ������ͻ���Լ����Ȩ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightAndPredict : public CClientInstrumentRightPredict
{
private:
	CClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientInstrumentRightAndPredict(CClientInstrumentRightPredict *p1, CClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientInstrumentRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientInstrumentRight	Ҫ���жϵĿͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)
	{
		return m_p1->isValid(pClientInstrumentRight) && m_p2->isValid(pClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightOrPredict�Ƕ������ͻ���Լ����Ȩ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightOrPredict : public CClientInstrumentRightPredict
{
private:
	CClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientInstrumentRightOrPredict(CClientInstrumentRightPredict *p1, CClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientInstrumentRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientInstrumentRight	Ҫ���жϵĿͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)
	{
		return m_p1->isValid(pClientInstrumentRight) || m_p2->isValid(pClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightNotPredict�Ƕ�һ���ͻ���Լ����Ȩ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightNotPredict : public CClientInstrumentRightPredict
{
private:
	CClientInstrumentRightPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CClientInstrumentRightNotPredict(CClientInstrumentRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CClientInstrumentRightNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientInstrumentRight	Ҫ���жϵĿͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)
	{
		return !m_predict->isValid(pClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightFilter��һ�������еĿͻ���Լ����Ȩ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightFilter: public CClientInstrumentRightIterator
{
private:
	CClientInstrumentRightIterator *m_baseIterator;
	CClientInstrumentRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CClientInstrumentRightFilter(CClientInstrumentRightIterator *pBaseIterator, CClientInstrumentRightPredict *pPredict, bool continueResult=false)
		:CClientInstrumentRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CClientInstrumentRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CClientInstrumentRight
	///@return	��һ����������CClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightLinkIterator�����������ͻ���Լ����Ȩ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightLinkIterator: public CClientInstrumentRightIterator
{
private:
	CClientInstrumentRightIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CClientInstrumentRightLinkIterator(CClientInstrumentRightIterator *pBaseIterator1,CClientInstrumentRightIterator *pBaseIterator2)
		:CClientInstrumentRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CClientInstrumentRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CClientInstrumentRight
	///@return	��һ����������CClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightSingleIterator�����෵��һ����Ա�ͻ���Ʒ����Ȩ�޵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightSingleIterator: public CPartClientProductRightIterator
{
private:
	CPartClientProductRight *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartClientProductRightSingleIterator(CPartClientProductRightFactory *pFactory,CPartClientProductRight *pResult)
		:CPartClientProductRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartClientProductRightSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartClientProductRight
	///@return	��һ����������CPartClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightPredict���ж�һ����Ա�ͻ���Ʒ����Ȩ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartClientProductRight	Ҫ���жϵĻ�Ա�ͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightAndPredict�Ƕ�������Ա�ͻ���Ʒ����Ȩ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightAndPredict : public CPartClientProductRightPredict
{
private:
	CPartClientProductRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartClientProductRightAndPredict(CPartClientProductRightPredict *p1, CPartClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartClientProductRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClientProductRight	Ҫ���жϵĻ�Ա�ͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)
	{
		return m_p1->isValid(pPartClientProductRight) && m_p2->isValid(pPartClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightOrPredict�Ƕ�������Ա�ͻ���Ʒ����Ȩ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightOrPredict : public CPartClientProductRightPredict
{
private:
	CPartClientProductRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartClientProductRightOrPredict(CPartClientProductRightPredict *p1, CPartClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartClientProductRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClientProductRight	Ҫ���жϵĻ�Ա�ͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)
	{
		return m_p1->isValid(pPartClientProductRight) || m_p2->isValid(pPartClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightNotPredict�Ƕ�һ����Ա�ͻ���Ʒ����Ȩ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightNotPredict : public CPartClientProductRightPredict
{
private:
	CPartClientProductRightPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartClientProductRightNotPredict(CPartClientProductRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartClientProductRightNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClientProductRight	Ҫ���жϵĻ�Ա�ͻ���Ʒ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)
	{
		return !m_predict->isValid(pPartClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightFilter��һ�������еĻ�Ա�ͻ���Ʒ����Ȩ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightFilter: public CPartClientProductRightIterator
{
private:
	CPartClientProductRightIterator *m_baseIterator;
	CPartClientProductRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartClientProductRightFilter(CPartClientProductRightIterator *pBaseIterator, CPartClientProductRightPredict *pPredict, bool continueResult=false)
		:CPartClientProductRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartClientProductRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartClientProductRight
	///@return	��һ����������CPartClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightLinkIterator������������Ա�ͻ���Ʒ����Ȩ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightLinkIterator: public CPartClientProductRightIterator
{
private:
	CPartClientProductRightIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartClientProductRightLinkIterator(CPartClientProductRightIterator *pBaseIterator1,CPartClientProductRightIterator *pBaseIterator2)
		:CPartClientProductRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartClientProductRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartClientProductRight
	///@return	��һ����������CPartClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightSingleIterator�����෵��һ����Ա�ͻ���Լ����Ȩ�޵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightSingleIterator: public CPartClientInstrumentRightIterator
{
private:
	CPartClientInstrumentRight *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartClientInstrumentRightSingleIterator(CPartClientInstrumentRightFactory *pFactory,CPartClientInstrumentRight *pResult)
		:CPartClientInstrumentRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartClientInstrumentRightSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartClientInstrumentRight
	///@return	��һ����������CPartClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightPredict���ж�һ����Ա�ͻ���Լ����Ȩ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartClientInstrumentRight	Ҫ���жϵĻ�Ա�ͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightAndPredict�Ƕ�������Ա�ͻ���Լ����Ȩ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightAndPredict : public CPartClientInstrumentRightPredict
{
private:
	CPartClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartClientInstrumentRightAndPredict(CPartClientInstrumentRightPredict *p1, CPartClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartClientInstrumentRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClientInstrumentRight	Ҫ���жϵĻ�Ա�ͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return m_p1->isValid(pPartClientInstrumentRight) && m_p2->isValid(pPartClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightOrPredict�Ƕ�������Ա�ͻ���Լ����Ȩ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightOrPredict : public CPartClientInstrumentRightPredict
{
private:
	CPartClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartClientInstrumentRightOrPredict(CPartClientInstrumentRightPredict *p1, CPartClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartClientInstrumentRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClientInstrumentRight	Ҫ���жϵĻ�Ա�ͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return m_p1->isValid(pPartClientInstrumentRight) || m_p2->isValid(pPartClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightNotPredict�Ƕ�һ����Ա�ͻ���Լ����Ȩ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightNotPredict : public CPartClientInstrumentRightPredict
{
private:
	CPartClientInstrumentRightPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartClientInstrumentRightNotPredict(CPartClientInstrumentRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartClientInstrumentRightNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartClientInstrumentRight	Ҫ���жϵĻ�Ա�ͻ���Լ����Ȩ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return !m_predict->isValid(pPartClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightFilter��һ�������еĻ�Ա�ͻ���Լ����Ȩ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightFilter: public CPartClientInstrumentRightIterator
{
private:
	CPartClientInstrumentRightIterator *m_baseIterator;
	CPartClientInstrumentRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartClientInstrumentRightFilter(CPartClientInstrumentRightIterator *pBaseIterator, CPartClientInstrumentRightPredict *pPredict, bool continueResult=false)
		:CPartClientInstrumentRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartClientInstrumentRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartClientInstrumentRight
	///@return	��һ����������CPartClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightLinkIterator������������Ա�ͻ���Լ����Ȩ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightLinkIterator: public CPartClientInstrumentRightIterator
{
private:
	CPartClientInstrumentRightIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartClientInstrumentRightLinkIterator(CPartClientInstrumentRightIterator *pBaseIterator1,CPartClientInstrumentRightIterator *pBaseIterator2)
		:CPartClientInstrumentRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartClientInstrumentRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartClientInstrumentRight
	///@return	��һ����������CPartClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertySingleIterator�����෵��һ����Ʒ���Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertySingleIterator: public CCurrProductPropertyIterator
{
private:
	CCurrProductProperty *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrProductPropertySingleIterator(CCurrProductPropertyFactory *pFactory,CCurrProductProperty *pResult)
		:CCurrProductPropertyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrProductPropertySingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrProductProperty
	///@return	��һ����������CCurrProductProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrProductProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrProductProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyPredict���ж�һ����Ʒ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrProductProperty	Ҫ���жϵĲ�Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyAndPredict�Ƕ�������Ʒ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyAndPredict : public CCurrProductPropertyPredict
{
private:
	CCurrProductPropertyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrProductPropertyAndPredict(CCurrProductPropertyPredict *p1, CCurrProductPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrProductPropertyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrProductProperty	Ҫ���жϵĲ�Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)
	{
		return m_p1->isValid(pCurrProductProperty) && m_p2->isValid(pCurrProductProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyOrPredict�Ƕ�������Ʒ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyOrPredict : public CCurrProductPropertyPredict
{
private:
	CCurrProductPropertyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrProductPropertyOrPredict(CCurrProductPropertyPredict *p1, CCurrProductPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrProductPropertyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrProductProperty	Ҫ���жϵĲ�Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)
	{
		return m_p1->isValid(pCurrProductProperty) || m_p2->isValid(pCurrProductProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyNotPredict�Ƕ�һ����Ʒ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyNotPredict : public CCurrProductPropertyPredict
{
private:
	CCurrProductPropertyPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrProductPropertyNotPredict(CCurrProductPropertyPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrProductPropertyNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrProductProperty	Ҫ���жϵĲ�Ʒ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)
	{
		return !m_predict->isValid(pCurrProductProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyFilter��һ�������еĲ�Ʒ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyFilter: public CCurrProductPropertyIterator
{
private:
	CCurrProductPropertyIterator *m_baseIterator;
	CCurrProductPropertyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrProductPropertyFilter(CCurrProductPropertyIterator *pBaseIterator, CCurrProductPropertyPredict *pPredict, bool continueResult=false)
		:CCurrProductPropertyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrProductPropertyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrProductProperty
	///@return	��һ����������CCurrProductProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrProductProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrProductProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyLinkIterator������������Ʒ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyLinkIterator: public CCurrProductPropertyIterator
{
private:
	CCurrProductPropertyIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrProductPropertyLinkIterator(CCurrProductPropertyIterator *pBaseIterator1,CCurrProductPropertyIterator *pBaseIterator2)
		:CCurrProductPropertyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrProductPropertyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrProductProperty
	///@return	��һ����������CCurrProductProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrProductProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrProductProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertySingleIterator�����෵��һ����Լ���Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertySingleIterator: public CCurrInstrumentPropertyIterator
{
private:
	CCurrInstrumentProperty *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrInstrumentPropertySingleIterator(CCurrInstrumentPropertyFactory *pFactory,CCurrInstrumentProperty *pResult)
		:CCurrInstrumentPropertyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrInstrumentPropertySingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrInstrumentProperty
	///@return	��һ����������CCurrInstrumentProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyPredict���ж�һ����Լ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentProperty	Ҫ���жϵĺ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyAndPredict�Ƕ�������Լ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyAndPredict : public CCurrInstrumentPropertyPredict
{
private:
	CCurrInstrumentPropertyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrInstrumentPropertyAndPredict(CCurrInstrumentPropertyPredict *p1, CCurrInstrumentPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrInstrumentPropertyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentProperty	Ҫ���жϵĺ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return m_p1->isValid(pCurrInstrumentProperty) && m_p2->isValid(pCurrInstrumentProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyOrPredict�Ƕ�������Լ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyOrPredict : public CCurrInstrumentPropertyPredict
{
private:
	CCurrInstrumentPropertyPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrInstrumentPropertyOrPredict(CCurrInstrumentPropertyPredict *p1, CCurrInstrumentPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrInstrumentPropertyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentProperty	Ҫ���жϵĺ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return m_p1->isValid(pCurrInstrumentProperty) || m_p2->isValid(pCurrInstrumentProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyNotPredict�Ƕ�һ����Լ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyNotPredict : public CCurrInstrumentPropertyPredict
{
private:
	CCurrInstrumentPropertyPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrInstrumentPropertyNotPredict(CCurrInstrumentPropertyPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrInstrumentPropertyNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentProperty	Ҫ���жϵĺ�Լ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return !m_predict->isValid(pCurrInstrumentProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyFilter��һ�������еĺ�Լ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyFilter: public CCurrInstrumentPropertyIterator
{
private:
	CCurrInstrumentPropertyIterator *m_baseIterator;
	CCurrInstrumentPropertyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrInstrumentPropertyFilter(CCurrInstrumentPropertyIterator *pBaseIterator, CCurrInstrumentPropertyPredict *pPredict, bool continueResult=false)
		:CCurrInstrumentPropertyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrInstrumentPropertyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrInstrumentProperty
	///@return	��һ����������CCurrInstrumentProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyLinkIterator������������Լ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyLinkIterator: public CCurrInstrumentPropertyIterator
{
private:
	CCurrInstrumentPropertyIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrInstrumentPropertyLinkIterator(CCurrInstrumentPropertyIterator *pBaseIterator1,CCurrInstrumentPropertyIterator *pBaseIterator2)
		:CCurrInstrumentPropertyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrInstrumentPropertyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrInstrumentProperty
	///@return	��һ����������CCurrInstrumentProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingSingleIterator�����෵��һ����ǰ�۸�󶨵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingSingleIterator: public CCurrPriceBandingIterator
{
private:
	CCurrPriceBanding *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrPriceBandingSingleIterator(CCurrPriceBandingFactory *pFactory,CCurrPriceBanding *pResult)
		:CCurrPriceBandingIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrPriceBandingSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrPriceBanding
	///@return	��һ����������CCurrPriceBanding������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPriceBanding *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPriceBanding ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingPredict���ж�һ����ǰ�۸���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrPriceBanding	Ҫ���жϵĵ�ǰ�۸��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingAndPredict�Ƕ�������ǰ�۸��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingAndPredict : public CCurrPriceBandingPredict
{
private:
	CCurrPriceBandingPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrPriceBandingAndPredict(CCurrPriceBandingPredict *p1, CCurrPriceBandingPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrPriceBandingAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPriceBanding	Ҫ���жϵĵ�ǰ�۸��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)
	{
		return m_p1->isValid(pCurrPriceBanding) && m_p2->isValid(pCurrPriceBanding);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingOrPredict�Ƕ�������ǰ�۸��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingOrPredict : public CCurrPriceBandingPredict
{
private:
	CCurrPriceBandingPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrPriceBandingOrPredict(CCurrPriceBandingPredict *p1, CCurrPriceBandingPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrPriceBandingOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPriceBanding	Ҫ���жϵĵ�ǰ�۸��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)
	{
		return m_p1->isValid(pCurrPriceBanding) || m_p2->isValid(pCurrPriceBanding);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingNotPredict�Ƕ�һ����ǰ�۸��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingNotPredict : public CCurrPriceBandingPredict
{
private:
	CCurrPriceBandingPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrPriceBandingNotPredict(CCurrPriceBandingPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrPriceBandingNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPriceBanding	Ҫ���жϵĵ�ǰ�۸��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)
	{
		return !m_predict->isValid(pCurrPriceBanding);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingFilter��һ�������еĵ�ǰ�۸��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingFilter: public CCurrPriceBandingIterator
{
private:
	CCurrPriceBandingIterator *m_baseIterator;
	CCurrPriceBandingPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrPriceBandingFilter(CCurrPriceBandingIterator *pBaseIterator, CCurrPriceBandingPredict *pPredict, bool continueResult=false)
		:CCurrPriceBandingIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrPriceBandingFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrPriceBanding
	///@return	��һ����������CCurrPriceBanding������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPriceBanding *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPriceBanding ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingLinkIterator������������ǰ�۸��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingLinkIterator: public CCurrPriceBandingIterator
{
private:
	CCurrPriceBandingIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrPriceBandingLinkIterator(CCurrPriceBandingIterator *pBaseIterator1,CCurrPriceBandingIterator *pBaseIterator2)
		:CCurrPriceBandingIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrPriceBandingLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrPriceBanding
	///@return	��һ����������CCurrPriceBanding������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPriceBanding *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPriceBanding ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateSingleIterator�����෵��һ�������Լ��֤���ʵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateSingleIterator: public CCurrMarginRateIterator
{
private:
	CCurrMarginRate *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrMarginRateSingleIterator(CCurrMarginRateFactory *pFactory,CCurrMarginRate *pResult)
		:CCurrMarginRateIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrMarginRateSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrMarginRate
	///@return	��һ����������CCurrMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRatePredict���ж�һ�������Լ��֤�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRatePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRate	Ҫ���жϵĵ����Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateAndPredict�Ƕ����������Լ��֤����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateAndPredict : public CCurrMarginRatePredict
{
private:
	CCurrMarginRatePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrMarginRateAndPredict(CCurrMarginRatePredict *p1, CCurrMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrMarginRateAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRate	Ҫ���жϵĵ����Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)
	{
		return m_p1->isValid(pCurrMarginRate) && m_p2->isValid(pCurrMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateOrPredict�Ƕ����������Լ��֤����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateOrPredict : public CCurrMarginRatePredict
{
private:
	CCurrMarginRatePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrMarginRateOrPredict(CCurrMarginRatePredict *p1, CCurrMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrMarginRateOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRate	Ҫ���жϵĵ����Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)
	{
		return m_p1->isValid(pCurrMarginRate) || m_p2->isValid(pCurrMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateNotPredict�Ƕ�һ�������Լ��֤����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateNotPredict : public CCurrMarginRatePredict
{
private:
	CCurrMarginRatePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrMarginRateNotPredict(CCurrMarginRatePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrMarginRateNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRate	Ҫ���жϵĵ����Լ��֤����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)
	{
		return !m_predict->isValid(pCurrMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateFilter��һ�������еĵ����Լ��֤����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateFilter: public CCurrMarginRateIterator
{
private:
	CCurrMarginRateIterator *m_baseIterator;
	CCurrMarginRatePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrMarginRateFilter(CCurrMarginRateIterator *pBaseIterator, CCurrMarginRatePredict *pPredict, bool continueResult=false)
		:CCurrMarginRateIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrMarginRateFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrMarginRate
	///@return	��һ����������CCurrMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateLinkIterator���������������Լ��֤����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateLinkIterator: public CCurrMarginRateIterator
{
private:
	CCurrMarginRateIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrMarginRateLinkIterator(CCurrMarginRateIterator *pBaseIterator1,CCurrMarginRateIterator *pBaseIterator2)
		:CCurrMarginRateIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrMarginRateLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrMarginRate
	///@return	��һ����������CCurrMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailSingleIterator�����෵��һ�������Լ��֤���ʵ���ϸ���ݵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailSingleIterator: public CCurrMarginRateDetailIterator
{
private:
	CCurrMarginRateDetail *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrMarginRateDetailSingleIterator(CCurrMarginRateDetailFactory *pFactory,CCurrMarginRateDetail *pResult)
		:CCurrMarginRateDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrMarginRateDetailSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrMarginRateDetail
	///@return	��һ����������CCurrMarginRateDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRateDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailPredict���ж�һ�������Լ��֤���ʵ���ϸ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRateDetail	Ҫ���жϵĵ����Լ��֤���ʵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailAndPredict�Ƕ����������Լ��֤���ʵ���ϸ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailAndPredict : public CCurrMarginRateDetailPredict
{
private:
	CCurrMarginRateDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrMarginRateDetailAndPredict(CCurrMarginRateDetailPredict *p1, CCurrMarginRateDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrMarginRateDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRateDetail	Ҫ���жϵĵ����Լ��֤���ʵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return m_p1->isValid(pCurrMarginRateDetail) && m_p2->isValid(pCurrMarginRateDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailOrPredict�Ƕ����������Լ��֤���ʵ���ϸ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailOrPredict : public CCurrMarginRateDetailPredict
{
private:
	CCurrMarginRateDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrMarginRateDetailOrPredict(CCurrMarginRateDetailPredict *p1, CCurrMarginRateDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrMarginRateDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRateDetail	Ҫ���жϵĵ����Լ��֤���ʵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return m_p1->isValid(pCurrMarginRateDetail) || m_p2->isValid(pCurrMarginRateDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailNotPredict�Ƕ�һ�������Լ��֤���ʵ���ϸ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailNotPredict : public CCurrMarginRateDetailPredict
{
private:
	CCurrMarginRateDetailPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrMarginRateDetailNotPredict(CCurrMarginRateDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrMarginRateDetailNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrMarginRateDetail	Ҫ���жϵĵ����Լ��֤���ʵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return !m_predict->isValid(pCurrMarginRateDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailFilter��һ�������еĵ����Լ��֤���ʵ���ϸ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailFilter: public CCurrMarginRateDetailIterator
{
private:
	CCurrMarginRateDetailIterator *m_baseIterator;
	CCurrMarginRateDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrMarginRateDetailFilter(CCurrMarginRateDetailIterator *pBaseIterator, CCurrMarginRateDetailPredict *pPredict, bool continueResult=false)
		:CCurrMarginRateDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrMarginRateDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrMarginRateDetail
	///@return	��һ����������CCurrMarginRateDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRateDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailLinkIterator���������������Լ��֤���ʵ���ϸ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailLinkIterator: public CCurrMarginRateDetailIterator
{
private:
	CCurrMarginRateDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrMarginRateDetailLinkIterator(CCurrMarginRateDetailIterator *pBaseIterator1,CCurrMarginRateDetailIterator *pBaseIterator2)
		:CCurrMarginRateDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrMarginRateDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrMarginRateDetail
	///@return	��һ����������CCurrMarginRateDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRateDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitSingleIterator�����෵��һ����ǰ��Ա��Լ�޲ֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitSingleIterator: public CCurrPartPosiLimitIterator
{
private:
	CCurrPartPosiLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrPartPosiLimitSingleIterator(CCurrPartPosiLimitFactory *pFactory,CCurrPartPosiLimit *pResult)
		:CCurrPartPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrPartPosiLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrPartPosiLimit
	///@return	��һ����������CCurrPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitPredict���ж�һ����ǰ��Ա��Լ�޲��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimit	Ҫ���жϵĵ�ǰ��Ա��Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitAndPredict�Ƕ�������ǰ��Ա��Լ�޲�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitAndPredict : public CCurrPartPosiLimitPredict
{
private:
	CCurrPartPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrPartPosiLimitAndPredict(CCurrPartPosiLimitPredict *p1, CCurrPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrPartPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimit	Ҫ���жϵĵ�ǰ��Ա��Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return m_p1->isValid(pCurrPartPosiLimit) && m_p2->isValid(pCurrPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitOrPredict�Ƕ�������ǰ��Ա��Լ�޲�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitOrPredict : public CCurrPartPosiLimitPredict
{
private:
	CCurrPartPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrPartPosiLimitOrPredict(CCurrPartPosiLimitPredict *p1, CCurrPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrPartPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimit	Ҫ���жϵĵ�ǰ��Ա��Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return m_p1->isValid(pCurrPartPosiLimit) || m_p2->isValid(pCurrPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitNotPredict�Ƕ�һ����ǰ��Ա��Լ�޲�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitNotPredict : public CCurrPartPosiLimitPredict
{
private:
	CCurrPartPosiLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrPartPosiLimitNotPredict(CCurrPartPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrPartPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimit	Ҫ���жϵĵ�ǰ��Ա��Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return !m_predict->isValid(pCurrPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitFilter��һ�������еĵ�ǰ��Ա��Լ�޲�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitFilter: public CCurrPartPosiLimitIterator
{
private:
	CCurrPartPosiLimitIterator *m_baseIterator;
	CCurrPartPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrPartPosiLimitFilter(CCurrPartPosiLimitIterator *pBaseIterator, CCurrPartPosiLimitPredict *pPredict, bool continueResult=false)
		:CCurrPartPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrPartPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrPartPosiLimit
	///@return	��һ����������CCurrPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitLinkIterator������������ǰ��Ա��Լ�޲�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitLinkIterator: public CCurrPartPosiLimitIterator
{
private:
	CCurrPartPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrPartPosiLimitLinkIterator(CCurrPartPosiLimitIterator *pBaseIterator1,CCurrPartPosiLimitIterator *pBaseIterator2)
		:CCurrPartPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrPartPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrPartPosiLimit
	///@return	��һ����������CCurrPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailSingleIterator�����෵��һ����ǰ��Ա��Լ�޲ֵ���ϸ���ݵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailSingleIterator: public CCurrPartPosiLimitDetailIterator
{
private:
	CCurrPartPosiLimitDetail *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrPartPosiLimitDetailSingleIterator(CCurrPartPosiLimitDetailFactory *pFactory,CCurrPartPosiLimitDetail *pResult)
		:CCurrPartPosiLimitDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrPartPosiLimitDetailSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrPartPosiLimitDetail
	///@return	��һ����������CCurrPartPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailPredict���ж�һ����ǰ��Ա��Լ�޲ֵ���ϸ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimitDetail	Ҫ���жϵĵ�ǰ��Ա��Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailAndPredict�Ƕ�������ǰ��Ա��Լ�޲ֵ���ϸ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailAndPredict : public CCurrPartPosiLimitDetailPredict
{
private:
	CCurrPartPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrPartPosiLimitDetailAndPredict(CCurrPartPosiLimitDetailPredict *p1, CCurrPartPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrPartPosiLimitDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimitDetail	Ҫ���жϵĵ�ǰ��Ա��Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return m_p1->isValid(pCurrPartPosiLimitDetail) && m_p2->isValid(pCurrPartPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailOrPredict�Ƕ�������ǰ��Ա��Լ�޲ֵ���ϸ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailOrPredict : public CCurrPartPosiLimitDetailPredict
{
private:
	CCurrPartPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrPartPosiLimitDetailOrPredict(CCurrPartPosiLimitDetailPredict *p1, CCurrPartPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrPartPosiLimitDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimitDetail	Ҫ���жϵĵ�ǰ��Ա��Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return m_p1->isValid(pCurrPartPosiLimitDetail) || m_p2->isValid(pCurrPartPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailNotPredict�Ƕ�һ����ǰ��Ա��Լ�޲ֵ���ϸ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailNotPredict : public CCurrPartPosiLimitDetailPredict
{
private:
	CCurrPartPosiLimitDetailPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrPartPosiLimitDetailNotPredict(CCurrPartPosiLimitDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrPartPosiLimitDetailNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrPartPosiLimitDetail	Ҫ���жϵĵ�ǰ��Ա��Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return !m_predict->isValid(pCurrPartPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailFilter��һ�������еĵ�ǰ��Ա��Լ�޲ֵ���ϸ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailFilter: public CCurrPartPosiLimitDetailIterator
{
private:
	CCurrPartPosiLimitDetailIterator *m_baseIterator;
	CCurrPartPosiLimitDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrPartPosiLimitDetailFilter(CCurrPartPosiLimitDetailIterator *pBaseIterator, CCurrPartPosiLimitDetailPredict *pPredict, bool continueResult=false)
		:CCurrPartPosiLimitDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrPartPosiLimitDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrPartPosiLimitDetail
	///@return	��һ����������CCurrPartPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailLinkIterator������������ǰ��Ա��Լ�޲ֵ���ϸ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailLinkIterator: public CCurrPartPosiLimitDetailIterator
{
private:
	CCurrPartPosiLimitDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrPartPosiLimitDetailLinkIterator(CCurrPartPosiLimitDetailIterator *pBaseIterator1,CCurrPartPosiLimitDetailIterator *pBaseIterator2)
		:CCurrPartPosiLimitDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrPartPosiLimitDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrPartPosiLimitDetail
	///@return	��һ����������CCurrPartPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitSingleIterator�����෵��һ����ǰ�ͻ���Լ�޲ֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitSingleIterator: public CCurrClientPosiLimitIterator
{
private:
	CCurrClientPosiLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrClientPosiLimitSingleIterator(CCurrClientPosiLimitFactory *pFactory,CCurrClientPosiLimit *pResult)
		:CCurrClientPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrClientPosiLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrClientPosiLimit
	///@return	��һ����������CCurrClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitPredict���ж�һ����ǰ�ͻ���Լ�޲��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimit	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitAndPredict�Ƕ�������ǰ�ͻ���Լ�޲�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitAndPredict : public CCurrClientPosiLimitPredict
{
private:
	CCurrClientPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrClientPosiLimitAndPredict(CCurrClientPosiLimitPredict *p1, CCurrClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrClientPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimit	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return m_p1->isValid(pCurrClientPosiLimit) && m_p2->isValid(pCurrClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitOrPredict�Ƕ�������ǰ�ͻ���Լ�޲�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitOrPredict : public CCurrClientPosiLimitPredict
{
private:
	CCurrClientPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrClientPosiLimitOrPredict(CCurrClientPosiLimitPredict *p1, CCurrClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrClientPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimit	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return m_p1->isValid(pCurrClientPosiLimit) || m_p2->isValid(pCurrClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitNotPredict�Ƕ�һ����ǰ�ͻ���Լ�޲�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitNotPredict : public CCurrClientPosiLimitPredict
{
private:
	CCurrClientPosiLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrClientPosiLimitNotPredict(CCurrClientPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrClientPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimit	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return !m_predict->isValid(pCurrClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitFilter��һ�������еĵ�ǰ�ͻ���Լ�޲�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitFilter: public CCurrClientPosiLimitIterator
{
private:
	CCurrClientPosiLimitIterator *m_baseIterator;
	CCurrClientPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrClientPosiLimitFilter(CCurrClientPosiLimitIterator *pBaseIterator, CCurrClientPosiLimitPredict *pPredict, bool continueResult=false)
		:CCurrClientPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrClientPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrClientPosiLimit
	///@return	��һ����������CCurrClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitLinkIterator������������ǰ�ͻ���Լ�޲�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitLinkIterator: public CCurrClientPosiLimitIterator
{
private:
	CCurrClientPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrClientPosiLimitLinkIterator(CCurrClientPosiLimitIterator *pBaseIterator1,CCurrClientPosiLimitIterator *pBaseIterator2)
		:CCurrClientPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrClientPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrClientPosiLimit
	///@return	��һ����������CCurrClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailSingleIterator�����෵��һ����ǰ�ͻ���Լ�޲ֵ���ϸ���ݵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailSingleIterator: public CCurrClientPosiLimitDetailIterator
{
private:
	CCurrClientPosiLimitDetail *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrClientPosiLimitDetailSingleIterator(CCurrClientPosiLimitDetailFactory *pFactory,CCurrClientPosiLimitDetail *pResult)
		:CCurrClientPosiLimitDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrClientPosiLimitDetailSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrClientPosiLimitDetail
	///@return	��һ����������CCurrClientPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailPredict���ж�һ����ǰ�ͻ���Լ�޲ֵ���ϸ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimitDetail	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailAndPredict�Ƕ�������ǰ�ͻ���Լ�޲ֵ���ϸ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailAndPredict : public CCurrClientPosiLimitDetailPredict
{
private:
	CCurrClientPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrClientPosiLimitDetailAndPredict(CCurrClientPosiLimitDetailPredict *p1, CCurrClientPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrClientPosiLimitDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimitDetail	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return m_p1->isValid(pCurrClientPosiLimitDetail) && m_p2->isValid(pCurrClientPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailOrPredict�Ƕ�������ǰ�ͻ���Լ�޲ֵ���ϸ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailOrPredict : public CCurrClientPosiLimitDetailPredict
{
private:
	CCurrClientPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrClientPosiLimitDetailOrPredict(CCurrClientPosiLimitDetailPredict *p1, CCurrClientPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrClientPosiLimitDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimitDetail	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return m_p1->isValid(pCurrClientPosiLimitDetail) || m_p2->isValid(pCurrClientPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailNotPredict�Ƕ�һ����ǰ�ͻ���Լ�޲ֵ���ϸ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailNotPredict : public CCurrClientPosiLimitDetailPredict
{
private:
	CCurrClientPosiLimitDetailPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrClientPosiLimitDetailNotPredict(CCurrClientPosiLimitDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrClientPosiLimitDetailNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrClientPosiLimitDetail	Ҫ���жϵĵ�ǰ�ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return !m_predict->isValid(pCurrClientPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailFilter��һ�������еĵ�ǰ�ͻ���Լ�޲ֵ���ϸ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailFilter: public CCurrClientPosiLimitDetailIterator
{
private:
	CCurrClientPosiLimitDetailIterator *m_baseIterator;
	CCurrClientPosiLimitDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrClientPosiLimitDetailFilter(CCurrClientPosiLimitDetailIterator *pBaseIterator, CCurrClientPosiLimitDetailPredict *pPredict, bool continueResult=false)
		:CCurrClientPosiLimitDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrClientPosiLimitDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrClientPosiLimitDetail
	///@return	��һ����������CCurrClientPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailLinkIterator������������ǰ�ͻ���Լ�޲ֵ���ϸ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailLinkIterator: public CCurrClientPosiLimitDetailIterator
{
private:
	CCurrClientPosiLimitDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrClientPosiLimitDetailLinkIterator(CCurrClientPosiLimitDetailIterator *pBaseIterator1,CCurrClientPosiLimitDetailIterator *pBaseIterator2)
		:CCurrClientPosiLimitDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrClientPosiLimitDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrClientPosiLimitDetail
	///@return	��һ����������CCurrClientPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitSingleIterator�����෵��һ����ǰ����ͻ���Լ�޲ֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitSingleIterator: public CCurrSpecialPosiLimitIterator
{
private:
	CCurrSpecialPosiLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrSpecialPosiLimitSingleIterator(CCurrSpecialPosiLimitFactory *pFactory,CCurrSpecialPosiLimit *pResult)
		:CCurrSpecialPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrSpecialPosiLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrSpecialPosiLimit
	///@return	��һ����������CCurrSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitPredict���ж�һ����ǰ����ͻ���Լ�޲��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimit	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitAndPredict�Ƕ�������ǰ����ͻ���Լ�޲�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitAndPredict : public CCurrSpecialPosiLimitPredict
{
private:
	CCurrSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrSpecialPosiLimitAndPredict(CCurrSpecialPosiLimitPredict *p1, CCurrSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrSpecialPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimit	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return m_p1->isValid(pCurrSpecialPosiLimit) && m_p2->isValid(pCurrSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitOrPredict�Ƕ�������ǰ����ͻ���Լ�޲�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitOrPredict : public CCurrSpecialPosiLimitPredict
{
private:
	CCurrSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrSpecialPosiLimitOrPredict(CCurrSpecialPosiLimitPredict *p1, CCurrSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrSpecialPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimit	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return m_p1->isValid(pCurrSpecialPosiLimit) || m_p2->isValid(pCurrSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitNotPredict�Ƕ�һ����ǰ����ͻ���Լ�޲�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitNotPredict : public CCurrSpecialPosiLimitPredict
{
private:
	CCurrSpecialPosiLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrSpecialPosiLimitNotPredict(CCurrSpecialPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrSpecialPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimit	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return !m_predict->isValid(pCurrSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitFilter��һ�������еĵ�ǰ����ͻ���Լ�޲�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitFilter: public CCurrSpecialPosiLimitIterator
{
private:
	CCurrSpecialPosiLimitIterator *m_baseIterator;
	CCurrSpecialPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrSpecialPosiLimitFilter(CCurrSpecialPosiLimitIterator *pBaseIterator, CCurrSpecialPosiLimitPredict *pPredict, bool continueResult=false)
		:CCurrSpecialPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrSpecialPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrSpecialPosiLimit
	///@return	��һ����������CCurrSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitLinkIterator������������ǰ����ͻ���Լ�޲�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitLinkIterator: public CCurrSpecialPosiLimitIterator
{
private:
	CCurrSpecialPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrSpecialPosiLimitLinkIterator(CCurrSpecialPosiLimitIterator *pBaseIterator1,CCurrSpecialPosiLimitIterator *pBaseIterator2)
		:CCurrSpecialPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrSpecialPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrSpecialPosiLimit
	///@return	��һ����������CCurrSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailSingleIterator�����෵��һ����ǰ����ͻ���Լ�޲ֵ���ϸ���ݵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailSingleIterator: public CCurrSpecialPosiLimitDetailIterator
{
private:
	CCurrSpecialPosiLimitDetail *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrSpecialPosiLimitDetailSingleIterator(CCurrSpecialPosiLimitDetailFactory *pFactory,CCurrSpecialPosiLimitDetail *pResult)
		:CCurrSpecialPosiLimitDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrSpecialPosiLimitDetailSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrSpecialPosiLimitDetail
	///@return	��һ����������CCurrSpecialPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailPredict���ж�һ����ǰ����ͻ���Լ�޲ֵ���ϸ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimitDetail	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailAndPredict�Ƕ�������ǰ����ͻ���Լ�޲ֵ���ϸ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailAndPredict : public CCurrSpecialPosiLimitDetailPredict
{
private:
	CCurrSpecialPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrSpecialPosiLimitDetailAndPredict(CCurrSpecialPosiLimitDetailPredict *p1, CCurrSpecialPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrSpecialPosiLimitDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimitDetail	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return m_p1->isValid(pCurrSpecialPosiLimitDetail) && m_p2->isValid(pCurrSpecialPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailOrPredict�Ƕ�������ǰ����ͻ���Լ�޲ֵ���ϸ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailOrPredict : public CCurrSpecialPosiLimitDetailPredict
{
private:
	CCurrSpecialPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrSpecialPosiLimitDetailOrPredict(CCurrSpecialPosiLimitDetailPredict *p1, CCurrSpecialPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrSpecialPosiLimitDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimitDetail	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return m_p1->isValid(pCurrSpecialPosiLimitDetail) || m_p2->isValid(pCurrSpecialPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailNotPredict�Ƕ�һ����ǰ����ͻ���Լ�޲ֵ���ϸ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailNotPredict : public CCurrSpecialPosiLimitDetailPredict
{
private:
	CCurrSpecialPosiLimitDetailPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrSpecialPosiLimitDetailNotPredict(CCurrSpecialPosiLimitDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrSpecialPosiLimitDetailNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrSpecialPosiLimitDetail	Ҫ���жϵĵ�ǰ����ͻ���Լ�޲ֵ���ϸ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return !m_predict->isValid(pCurrSpecialPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailFilter��һ�������еĵ�ǰ����ͻ���Լ�޲ֵ���ϸ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailFilter: public CCurrSpecialPosiLimitDetailIterator
{
private:
	CCurrSpecialPosiLimitDetailIterator *m_baseIterator;
	CCurrSpecialPosiLimitDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrSpecialPosiLimitDetailFilter(CCurrSpecialPosiLimitDetailIterator *pBaseIterator, CCurrSpecialPosiLimitDetailPredict *pPredict, bool continueResult=false)
		:CCurrSpecialPosiLimitDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrSpecialPosiLimitDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrSpecialPosiLimitDetail
	///@return	��һ����������CCurrSpecialPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailLinkIterator������������ǰ����ͻ���Լ�޲ֵ���ϸ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailLinkIterator: public CCurrSpecialPosiLimitDetailIterator
{
private:
	CCurrSpecialPosiLimitDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrSpecialPosiLimitDetailLinkIterator(CCurrSpecialPosiLimitDetailIterator *pBaseIterator1,CCurrSpecialPosiLimitDetailIterator *pBaseIterator2)
		:CCurrSpecialPosiLimitDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrSpecialPosiLimitDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrSpecialPosiLimitDetail
	///@return	��һ����������CCurrSpecialPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleSingleIterator�����෵��һ����ǰ��Լ���ڱ�ֵ���Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleSingleIterator: public CCurrHedgeRuleIterator
{
private:
	CCurrHedgeRule *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrHedgeRuleSingleIterator(CCurrHedgeRuleFactory *pFactory,CCurrHedgeRule *pResult)
		:CCurrHedgeRuleIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrHedgeRuleSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrHedgeRule
	///@return	��һ����������CCurrHedgeRule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrHedgeRule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrHedgeRule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRulePredict���ж�һ����ǰ��Լ���ڱ�ֵ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRulePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrHedgeRule	Ҫ���жϵĵ�ǰ��Լ���ڱ�ֵ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleAndPredict�Ƕ�������ǰ��Լ���ڱ�ֵ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleAndPredict : public CCurrHedgeRulePredict
{
private:
	CCurrHedgeRulePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrHedgeRuleAndPredict(CCurrHedgeRulePredict *p1, CCurrHedgeRulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrHedgeRuleAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrHedgeRule	Ҫ���жϵĵ�ǰ��Լ���ڱ�ֵ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)
	{
		return m_p1->isValid(pCurrHedgeRule) && m_p2->isValid(pCurrHedgeRule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleOrPredict�Ƕ�������ǰ��Լ���ڱ�ֵ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleOrPredict : public CCurrHedgeRulePredict
{
private:
	CCurrHedgeRulePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrHedgeRuleOrPredict(CCurrHedgeRulePredict *p1, CCurrHedgeRulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrHedgeRuleOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrHedgeRule	Ҫ���жϵĵ�ǰ��Լ���ڱ�ֵ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)
	{
		return m_p1->isValid(pCurrHedgeRule) || m_p2->isValid(pCurrHedgeRule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleNotPredict�Ƕ�һ����ǰ��Լ���ڱ�ֵ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleNotPredict : public CCurrHedgeRulePredict
{
private:
	CCurrHedgeRulePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrHedgeRuleNotPredict(CCurrHedgeRulePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrHedgeRuleNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrHedgeRule	Ҫ���жϵĵ�ǰ��Լ���ڱ�ֵ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)
	{
		return !m_predict->isValid(pCurrHedgeRule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleFilter��һ�������еĵ�ǰ��Լ���ڱ�ֵ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleFilter: public CCurrHedgeRuleIterator
{
private:
	CCurrHedgeRuleIterator *m_baseIterator;
	CCurrHedgeRulePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrHedgeRuleFilter(CCurrHedgeRuleIterator *pBaseIterator, CCurrHedgeRulePredict *pPredict, bool continueResult=false)
		:CCurrHedgeRuleIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrHedgeRuleFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrHedgeRule
	///@return	��һ����������CCurrHedgeRule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrHedgeRule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrHedgeRule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleLinkIterator������������ǰ��Լ���ڱ�ֵ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleLinkIterator: public CCurrHedgeRuleIterator
{
private:
	CCurrHedgeRuleIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrHedgeRuleLinkIterator(CCurrHedgeRuleIterator *pBaseIterator1,CCurrHedgeRuleIterator *pBaseIterator2)
		:CCurrHedgeRuleIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrHedgeRuleLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrHedgeRule
	///@return	��һ����������CCurrHedgeRule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrHedgeRule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrHedgeRule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrSingleIterator�����෵��һ����ǰ��Լ���׽׶����Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrSingleIterator: public CCurrTradingSegmentAttrIterator
{
private:
	CCurrTradingSegmentAttr *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrTradingSegmentAttrSingleIterator(CCurrTradingSegmentAttrFactory *pFactory,CCurrTradingSegmentAttr *pResult)
		:CCurrTradingSegmentAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrTradingSegmentAttrSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrTradingSegmentAttr
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrPredict���ж�һ����ǰ��Լ���׽׶������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrTradingSegmentAttr	Ҫ���жϵĵ�ǰ��Լ���׽׶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrAndPredict�Ƕ�������ǰ��Լ���׽׶�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrAndPredict : public CCurrTradingSegmentAttrPredict
{
private:
	CCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrTradingSegmentAttrAndPredict(CCurrTradingSegmentAttrPredict *p1, CCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrTradingSegmentAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrTradingSegmentAttr	Ҫ���жϵĵ�ǰ��Լ���׽׶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pCurrTradingSegmentAttr) && m_p2->isValid(pCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrOrPredict�Ƕ�������ǰ��Լ���׽׶�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrOrPredict : public CCurrTradingSegmentAttrPredict
{
private:
	CCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrTradingSegmentAttrOrPredict(CCurrTradingSegmentAttrPredict *p1, CCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrTradingSegmentAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrTradingSegmentAttr	Ҫ���жϵĵ�ǰ��Լ���׽׶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pCurrTradingSegmentAttr) || m_p2->isValid(pCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrNotPredict�Ƕ�һ����ǰ��Լ���׽׶�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrNotPredict : public CCurrTradingSegmentAttrPredict
{
private:
	CCurrTradingSegmentAttrPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrTradingSegmentAttrNotPredict(CCurrTradingSegmentAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrTradingSegmentAttrNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrTradingSegmentAttr	Ҫ���жϵĵ�ǰ��Լ���׽׶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return !m_predict->isValid(pCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrFilter��һ�������еĵ�ǰ��Լ���׽׶�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrFilter: public CCurrTradingSegmentAttrIterator
{
private:
	CCurrTradingSegmentAttrIterator *m_baseIterator;
	CCurrTradingSegmentAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrTradingSegmentAttrFilter(CCurrTradingSegmentAttrIterator *pBaseIterator, CCurrTradingSegmentAttrPredict *pPredict, bool continueResult=false)
		:CCurrTradingSegmentAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrTradingSegmentAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrTradingSegmentAttr
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrLinkIterator������������ǰ��Լ���׽׶�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrLinkIterator: public CCurrTradingSegmentAttrIterator
{
private:
	CCurrTradingSegmentAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrTradingSegmentAttrLinkIterator(CCurrTradingSegmentAttrIterator *pBaseIterator1,CCurrTradingSegmentAttrIterator *pBaseIterator2)
		:CCurrTradingSegmentAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrTradingSegmentAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrTradingSegmentAttr
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrFuseSingleIterator�����෵��һ����ǰ��Լ�۶����Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseSingleIterator: public CCurrFuseIterator
{
private:
	CCurrFuse *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrFuseSingleIterator(CCurrFuseFactory *pFactory,CCurrFuse *pResult)
		:CCurrFuseIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrFuseSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrFuse
	///@return	��һ����������CCurrFuse������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrFuse *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrFuse ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFusePredict���ж�һ����ǰ��Լ�۶������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFusePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrFuse	Ҫ���жϵĵ�ǰ��Լ�۶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrFuse *pCurrFuse)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseAndPredict�Ƕ�������ǰ��Լ�۶�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseAndPredict : public CCurrFusePredict
{
private:
	CCurrFusePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrFuseAndPredict(CCurrFusePredict *p1, CCurrFusePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrFuseAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrFuse	Ҫ���жϵĵ�ǰ��Լ�۶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrFuse *pCurrFuse)
	{
		return m_p1->isValid(pCurrFuse) && m_p2->isValid(pCurrFuse);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseOrPredict�Ƕ�������ǰ��Լ�۶�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseOrPredict : public CCurrFusePredict
{
private:
	CCurrFusePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrFuseOrPredict(CCurrFusePredict *p1, CCurrFusePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrFuseOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrFuse	Ҫ���жϵĵ�ǰ��Լ�۶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrFuse *pCurrFuse)
	{
		return m_p1->isValid(pCurrFuse) || m_p2->isValid(pCurrFuse);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseNotPredict�Ƕ�һ����ǰ��Լ�۶�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseNotPredict : public CCurrFusePredict
{
private:
	CCurrFusePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrFuseNotPredict(CCurrFusePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrFuseNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrFuse	Ҫ���жϵĵ�ǰ��Լ�۶�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrFuse *pCurrFuse)
	{
		return !m_predict->isValid(pCurrFuse);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseFilter��һ�������еĵ�ǰ��Լ�۶�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseFilter: public CCurrFuseIterator
{
private:
	CCurrFuseIterator *m_baseIterator;
	CCurrFusePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrFuseFilter(CCurrFuseIterator *pBaseIterator, CCurrFusePredict *pPredict, bool continueResult=false)
		:CCurrFuseIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrFuseFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrFuse
	///@return	��һ����������CCurrFuse������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrFuse *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrFuse ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseLinkIterator������������ǰ��Լ�۶�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseLinkIterator: public CCurrFuseIterator
{
private:
	CCurrFuseIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrFuseLinkIterator(CCurrFuseIterator *pBaseIterator1,CCurrFuseIterator *pBaseIterator2)
		:CCurrFuseIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrFuseLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrFuse
	///@return	��һ����������CCurrFuse������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrFuse *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrFuse ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTradingAccountSingleIterator�����෵��һ�������˻���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountSingleIterator: public CTradingAccountIterator
{
private:
	CTradingAccount *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CTradingAccountSingleIterator(CTradingAccountFactory *pFactory,CTradingAccount *pResult)
		:CTradingAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CTradingAccountSingleIterator(void)
	{
	}

	///Ѱ����һ������������CTradingAccount
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTradingAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTradingAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountPredict���ж�һ�������˻��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pTradingAccount	Ҫ���жϵĽ����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTradingAccount *pTradingAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountAndPredict�Ƕ����������˻�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountAndPredict : public CTradingAccountPredict
{
private:
	CTradingAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTradingAccountAndPredict(CTradingAccountPredict *p1, CTradingAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTradingAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTradingAccount	Ҫ���жϵĽ����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTradingAccount *pTradingAccount)
	{
		return m_p1->isValid(pTradingAccount) && m_p2->isValid(pTradingAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountOrPredict�Ƕ����������˻�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountOrPredict : public CTradingAccountPredict
{
private:
	CTradingAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTradingAccountOrPredict(CTradingAccountPredict *p1, CTradingAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTradingAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTradingAccount	Ҫ���жϵĽ����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTradingAccount *pTradingAccount)
	{
		return m_p1->isValid(pTradingAccount) || m_p2->isValid(pTradingAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountNotPredict�Ƕ�һ�������˻�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountNotPredict : public CTradingAccountPredict
{
private:
	CTradingAccountPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CTradingAccountNotPredict(CTradingAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CTradingAccountNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTradingAccount	Ҫ���жϵĽ����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTradingAccount *pTradingAccount)
	{
		return !m_predict->isValid(pTradingAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountFilter��һ�������еĽ����˻�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountFilter: public CTradingAccountIterator
{
private:
	CTradingAccountIterator *m_baseIterator;
	CTradingAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CTradingAccountFilter(CTradingAccountIterator *pBaseIterator, CTradingAccountPredict *pPredict, bool continueResult=false)
		:CTradingAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CTradingAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CTradingAccount
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTradingAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTradingAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountLinkIterator���������������˻�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountLinkIterator: public CTradingAccountIterator
{
private:
	CTradingAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CTradingAccountLinkIterator(CTradingAccountIterator *pBaseIterator1,CTradingAccountIterator *pBaseIterator2)
		:CTradingAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CTradingAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CTradingAccount
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTradingAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTradingAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountOfTradingAccountIterator��һ�������˻�ö������Ӧ�Ļ���׼�����˻���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountOfTradingAccountIterator: public CBaseReserveAccountIterator
{
private:
	CTradingAccountIterator *m_baseIterator;
	CBaseReserveAccount *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CBaseReserveAccountOfTradingAccountIterator(CBaseReserveAccountFactory *pFactory,CTradingAccountIterator *pBaseIterator)
		:CBaseReserveAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CBaseReserveAccountOfTradingAccountIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CBaseReserveAccount
	///@return	��һ����������CBaseReserveAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBaseReserveAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBaseReserveAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBaseReserveAccount *pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountSingleIterator�����෵��һ������׼�����˻���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountSingleIterator: public CBaseReserveAccountIterator
{
private:
	CBaseReserveAccount *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CBaseReserveAccountSingleIterator(CBaseReserveAccountFactory *pFactory,CBaseReserveAccount *pResult)
		:CBaseReserveAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CBaseReserveAccountSingleIterator(void)
	{
	}

	///Ѱ����һ������������CBaseReserveAccount
	///@return	��һ����������CBaseReserveAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBaseReserveAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBaseReserveAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountPredict���ж�һ������׼�����˻��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pBaseReserveAccount	Ҫ���жϵĻ���׼�����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountAndPredict�Ƕ���������׼�����˻�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountAndPredict : public CBaseReserveAccountPredict
{
private:
	CBaseReserveAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CBaseReserveAccountAndPredict(CBaseReserveAccountPredict *p1, CBaseReserveAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CBaseReserveAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBaseReserveAccount	Ҫ���жϵĻ���׼�����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)
	{
		return m_p1->isValid(pBaseReserveAccount) && m_p2->isValid(pBaseReserveAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountOrPredict�Ƕ���������׼�����˻�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountOrPredict : public CBaseReserveAccountPredict
{
private:
	CBaseReserveAccountPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CBaseReserveAccountOrPredict(CBaseReserveAccountPredict *p1, CBaseReserveAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CBaseReserveAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBaseReserveAccount	Ҫ���жϵĻ���׼�����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)
	{
		return m_p1->isValid(pBaseReserveAccount) || m_p2->isValid(pBaseReserveAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountNotPredict�Ƕ�һ������׼�����˻�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountNotPredict : public CBaseReserveAccountPredict
{
private:
	CBaseReserveAccountPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CBaseReserveAccountNotPredict(CBaseReserveAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CBaseReserveAccountNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBaseReserveAccount	Ҫ���жϵĻ���׼�����˻�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)
	{
		return !m_predict->isValid(pBaseReserveAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountFilter��һ�������еĻ���׼�����˻�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountFilter: public CBaseReserveAccountIterator
{
private:
	CBaseReserveAccountIterator *m_baseIterator;
	CBaseReserveAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CBaseReserveAccountFilter(CBaseReserveAccountIterator *pBaseIterator, CBaseReserveAccountPredict *pPredict, bool continueResult=false)
		:CBaseReserveAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CBaseReserveAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CBaseReserveAccount
	///@return	��һ����������CBaseReserveAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBaseReserveAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBaseReserveAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountLinkIterator��������������׼�����˻�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountLinkIterator: public CBaseReserveAccountIterator
{
private:
	CBaseReserveAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CBaseReserveAccountLinkIterator(CBaseReserveAccountIterator *pBaseIterator1,CBaseReserveAccountIterator *pBaseIterator2)
		:CBaseReserveAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CBaseReserveAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CBaseReserveAccount
	///@return	��һ����������CBaseReserveAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBaseReserveAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBaseReserveAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartPositionSingleIterator�����෵��һ����Ա�ֲֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionSingleIterator: public CPartPositionIterator
{
private:
	CPartPosition *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CPartPositionSingleIterator(CPartPositionFactory *pFactory,CPartPosition *pResult)
		:CPartPositionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CPartPositionSingleIterator(void)
	{
	}

	///Ѱ����һ������������CPartPosition
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionPredict���ж�һ����Ա�ֲ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pPartPosition	Ҫ���жϵĻ�Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartPosition *pPartPosition)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionAndPredict�Ƕ�������Ա�ֲ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionAndPredict : public CPartPositionPredict
{
private:
	CPartPositionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartPositionAndPredict(CPartPositionPredict *p1, CPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartPositionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartPosition	Ҫ���жϵĻ�Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartPosition *pPartPosition)
	{
		return m_p1->isValid(pPartPosition) && m_p2->isValid(pPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionOrPredict�Ƕ�������Ա�ֲ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionOrPredict : public CPartPositionPredict
{
private:
	CPartPositionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CPartPositionOrPredict(CPartPositionPredict *p1, CPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CPartPositionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartPosition	Ҫ���жϵĻ�Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartPosition *pPartPosition)
	{
		return m_p1->isValid(pPartPosition) || m_p2->isValid(pPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionNotPredict�Ƕ�һ����Ա�ֲ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionNotPredict : public CPartPositionPredict
{
private:
	CPartPositionPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CPartPositionNotPredict(CPartPositionPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CPartPositionNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pPartPosition	Ҫ���жϵĻ�Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CPartPosition *pPartPosition)
	{
		return !m_predict->isValid(pPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionFilter��һ�������еĻ�Ա�ֲ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionFilter: public CPartPositionIterator
{
private:
	CPartPositionIterator *m_baseIterator;
	CPartPositionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CPartPositionFilter(CPartPositionIterator *pBaseIterator, CPartPositionPredict *pPredict, bool continueResult=false)
		:CPartPositionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CPartPositionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CPartPosition
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionLinkIterator������������Ա�ֲ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionLinkIterator: public CPartPositionIterator
{
private:
	CPartPositionIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CPartPositionLinkIterator(CPartPositionIterator *pBaseIterator1,CPartPositionIterator *pBaseIterator2)
		:CPartPositionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CPartPositionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CPartPosition
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientPositionSingleIterator�����෵��һ���ͻ��ֲֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionSingleIterator: public CClientPositionIterator
{
private:
	CClientPosition *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CClientPositionSingleIterator(CClientPositionFactory *pFactory,CClientPosition *pResult)
		:CClientPositionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CClientPositionSingleIterator(void)
	{
	}

	///Ѱ����һ������������CClientPosition
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionPredict���ж�һ���ͻ��ֲ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pClientPosition	Ҫ���жϵĿͻ��ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientPosition *pClientPosition)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionAndPredict�Ƕ������ͻ��ֲ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionAndPredict : public CClientPositionPredict
{
private:
	CClientPositionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientPositionAndPredict(CClientPositionPredict *p1, CClientPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientPositionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientPosition	Ҫ���жϵĿͻ��ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientPosition *pClientPosition)
	{
		return m_p1->isValid(pClientPosition) && m_p2->isValid(pClientPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionOrPredict�Ƕ������ͻ��ֲ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionOrPredict : public CClientPositionPredict
{
private:
	CClientPositionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClientPositionOrPredict(CClientPositionPredict *p1, CClientPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClientPositionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientPosition	Ҫ���жϵĿͻ��ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientPosition *pClientPosition)
	{
		return m_p1->isValid(pClientPosition) || m_p2->isValid(pClientPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionNotPredict�Ƕ�һ���ͻ��ֲ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionNotPredict : public CClientPositionPredict
{
private:
	CClientPositionPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CClientPositionNotPredict(CClientPositionPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CClientPositionNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClientPosition	Ҫ���жϵĿͻ��ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClientPosition *pClientPosition)
	{
		return !m_predict->isValid(pClientPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionFilter��һ�������еĿͻ��ֲ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionFilter: public CClientPositionIterator
{
private:
	CClientPositionIterator *m_baseIterator;
	CClientPositionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CClientPositionFilter(CClientPositionIterator *pBaseIterator, CClientPositionPredict *pPredict, bool continueResult=false)
		:CClientPositionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CClientPositionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CClientPosition
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionLinkIterator�����������ͻ��ֲ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionLinkIterator: public CClientPositionIterator
{
private:
	CClientPositionIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CClientPositionLinkIterator(CClientPositionIterator *pBaseIterator1,CClientPositionIterator *pBaseIterator2)
		:CClientPositionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CClientPositionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CClientPosition
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitOfClientPositionIterator��һ���ͻ��ֲ�ö������Ӧ�����ö�ȵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitOfClientPositionIterator: public CCreditLimitIterator
{
private:
	CClientPositionIterator *m_baseIterator;
	CCreditLimit *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CCreditLimitOfClientPositionIterator(CCreditLimitFactory *pFactory,CClientPositionIterator *pBaseIterator)
		:CCreditLimitIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CCreditLimitOfClientPositionIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CCreditLimit
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCreditLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit *pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountOfClientPositionIterator��һ���ͻ��ֲ�ö������Ӧ�Ļ�Ա��ɫ�ʺŵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountOfClientPositionIterator: public CPartRoleAccountIterator
{
private:
	CClientPositionIterator *m_baseIterator;
	CPartRoleAccount *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CPartRoleAccountOfClientPositionIterator(CPartRoleAccountFactory *pFactory,CClientPositionIterator *pBaseIterator)
		:CPartRoleAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CPartRoleAccountOfClientPositionIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CPartRoleAccount
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartRoleAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartRoleAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartRoleAccount *pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeSingleIterator�����෵��һ����ֵ�������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeSingleIterator: public CHedgeVolumeIterator
{
private:
	CHedgeVolume *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CHedgeVolumeSingleIterator(CHedgeVolumeFactory *pFactory,CHedgeVolume *pResult)
		:CHedgeVolumeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CHedgeVolumeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CHedgeVolume
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CHedgeVolume *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pHedgeVolume ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumePredict���ж�һ����ֵ������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pHedgeVolume	Ҫ���жϵı�ֵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CHedgeVolume *pHedgeVolume)=0;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeAndPredict�Ƕ�������ֵ�����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeAndPredict : public CHedgeVolumePredict
{
private:
	CHedgeVolumePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CHedgeVolumeAndPredict(CHedgeVolumePredict *p1, CHedgeVolumePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CHedgeVolumeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pHedgeVolume	Ҫ���жϵı�ֵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CHedgeVolume *pHedgeVolume)
	{
		return m_p1->isValid(pHedgeVolume) && m_p2->isValid(pHedgeVolume);
	}
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeOrPredict�Ƕ�������ֵ�����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeOrPredict : public CHedgeVolumePredict
{
private:
	CHedgeVolumePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CHedgeVolumeOrPredict(CHedgeVolumePredict *p1, CHedgeVolumePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CHedgeVolumeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pHedgeVolume	Ҫ���жϵı�ֵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CHedgeVolume *pHedgeVolume)
	{
		return m_p1->isValid(pHedgeVolume) || m_p2->isValid(pHedgeVolume);
	}
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeNotPredict�Ƕ�һ����ֵ�����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeNotPredict : public CHedgeVolumePredict
{
private:
	CHedgeVolumePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CHedgeVolumeNotPredict(CHedgeVolumePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CHedgeVolumeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pHedgeVolume	Ҫ���жϵı�ֵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CHedgeVolume *pHedgeVolume)
	{
		return !m_predict->isValid(pHedgeVolume);
	}
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeFilter��һ�������еı�ֵ�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeFilter: public CHedgeVolumeIterator
{
private:
	CHedgeVolumeIterator *m_baseIterator;
	CHedgeVolumePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CHedgeVolumeFilter(CHedgeVolumeIterator *pBaseIterator, CHedgeVolumePredict *pPredict, bool continueResult=false)
		:CHedgeVolumeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CHedgeVolumeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CHedgeVolume
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CHedgeVolume *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pHedgeVolume ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeLinkIterator������������ֵ�����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeLinkIterator: public CHedgeVolumeIterator
{
private:
	CHedgeVolumeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CHedgeVolumeLinkIterator(CHedgeVolumeIterator *pBaseIterator1,CHedgeVolumeIterator *pBaseIterator2)
		:CHedgeVolumeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CHedgeVolumeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CHedgeVolume
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CHedgeVolume *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pHedgeVolume ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRemainOrderSingleIterator�����෵��һ����ʷ������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderSingleIterator: public CRemainOrderIterator
{
private:
	CRemainOrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CRemainOrderSingleIterator(CRemainOrderFactory *pFactory,CRemainOrder *pResult)
		:CRemainOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CRemainOrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������CRemainOrder
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRemainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRemainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderPredict���ж�һ����ʷ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pRemainOrder	Ҫ���жϵ���ʷ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRemainOrder *pRemainOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderAndPredict�Ƕ�������ʷ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderAndPredict : public CRemainOrderPredict
{
private:
	CRemainOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRemainOrderAndPredict(CRemainOrderPredict *p1, CRemainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRemainOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRemainOrder	Ҫ���жϵ���ʷ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRemainOrder *pRemainOrder)
	{
		return m_p1->isValid(pRemainOrder) && m_p2->isValid(pRemainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderOrPredict�Ƕ�������ʷ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderOrPredict : public CRemainOrderPredict
{
private:
	CRemainOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CRemainOrderOrPredict(CRemainOrderPredict *p1, CRemainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CRemainOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRemainOrder	Ҫ���жϵ���ʷ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRemainOrder *pRemainOrder)
	{
		return m_p1->isValid(pRemainOrder) || m_p2->isValid(pRemainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderNotPredict�Ƕ�һ����ʷ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderNotPredict : public CRemainOrderPredict
{
private:
	CRemainOrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CRemainOrderNotPredict(CRemainOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CRemainOrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pRemainOrder	Ҫ���жϵ���ʷ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CRemainOrder *pRemainOrder)
	{
		return !m_predict->isValid(pRemainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderFilter��һ�������е���ʷ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderFilter: public CRemainOrderIterator
{
private:
	CRemainOrderIterator *m_baseIterator;
	CRemainOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CRemainOrderFilter(CRemainOrderIterator *pBaseIterator, CRemainOrderPredict *pPredict, bool continueResult=false)
		:CRemainOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CRemainOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CRemainOrder
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRemainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRemainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderLinkIterator������������ʷ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderLinkIterator: public CRemainOrderIterator
{
private:
	CRemainOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CRemainOrderLinkIterator(CRemainOrderIterator *pBaseIterator1,CRemainOrderIterator *pBaseIterator2)
		:CRemainOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CRemainOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CRemainOrder
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRemainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRemainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataSingleIterator�����෵��һ�������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataSingleIterator: public CMarketDataIterator
{
private:
	CMarketData *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMarketDataSingleIterator(CMarketDataFactory *pFactory,CMarketData *pResult)
		:CMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMarketDataSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMarketData
	///@return	��һ����������CMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataPredict���ж�һ�������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMarketData	Ҫ���жϵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketData *pMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataAndPredict�Ƕ���������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataAndPredict : public CMarketDataPredict
{
private:
	CMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataAndPredict(CMarketDataPredict *p1, CMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketData	Ҫ���жϵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketData *pMarketData)
	{
		return m_p1->isValid(pMarketData) && m_p2->isValid(pMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataOrPredict�Ƕ���������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataOrPredict : public CMarketDataPredict
{
private:
	CMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMarketDataOrPredict(CMarketDataPredict *p1, CMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketData	Ҫ���жϵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketData *pMarketData)
	{
		return m_p1->isValid(pMarketData) || m_p2->isValid(pMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataNotPredict�Ƕ�һ������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataNotPredict : public CMarketDataPredict
{
private:
	CMarketDataPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMarketDataNotPredict(CMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMarketData	Ҫ���жϵ�����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMarketData *pMarketData)
	{
		return !m_predict->isValid(pMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataFilter��һ�������е�����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataFilter: public CMarketDataIterator
{
private:
	CMarketDataIterator *m_baseIterator;
	CMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMarketDataFilter(CMarketDataIterator *pBaseIterator, CMarketDataPredict *pPredict, bool continueResult=false)
		:CMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMarketData
	///@return	��һ����������CMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLinkIterator��������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLinkIterator: public CMarketDataIterator
{
private:
	CMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMarketDataLinkIterator(CMarketDataIterator *pBaseIterator1,CMarketDataIterator *pBaseIterator2)
		:CMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMarketData
	///@return	��һ����������CMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionSingleIterator�����෵��һ�������Ա�ֲֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionSingleIterator: public CClearingPartPositionIterator
{
private:
	CClearingPartPosition *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CClearingPartPositionSingleIterator(CClearingPartPositionFactory *pFactory,CClearingPartPosition *pResult)
		:CClearingPartPositionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CClearingPartPositionSingleIterator(void)
	{
	}

	///Ѱ����һ������������CClearingPartPosition
	///@return	��һ����������CClearingPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionPredict���ж�һ�������Ա�ֲ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pClearingPartPosition	Ҫ���жϵĽ����Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionAndPredict�Ƕ����������Ա�ֲ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionAndPredict : public CClearingPartPositionPredict
{
private:
	CClearingPartPositionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClearingPartPositionAndPredict(CClearingPartPositionPredict *p1, CClearingPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClearingPartPositionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClearingPartPosition	Ҫ���жϵĽ����Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)
	{
		return m_p1->isValid(pClearingPartPosition) && m_p2->isValid(pClearingPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionOrPredict�Ƕ����������Ա�ֲ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionOrPredict : public CClearingPartPositionPredict
{
private:
	CClearingPartPositionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CClearingPartPositionOrPredict(CClearingPartPositionPredict *p1, CClearingPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CClearingPartPositionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClearingPartPosition	Ҫ���жϵĽ����Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)
	{
		return m_p1->isValid(pClearingPartPosition) || m_p2->isValid(pClearingPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionNotPredict�Ƕ�һ�������Ա�ֲ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionNotPredict : public CClearingPartPositionPredict
{
private:
	CClearingPartPositionPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CClearingPartPositionNotPredict(CClearingPartPositionPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CClearingPartPositionNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pClearingPartPosition	Ҫ���жϵĽ����Ա�ֲ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)
	{
		return !m_predict->isValid(pClearingPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionFilter��һ�������еĽ����Ա�ֲ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionFilter: public CClearingPartPositionIterator
{
private:
	CClearingPartPositionIterator *m_baseIterator;
	CClearingPartPositionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CClearingPartPositionFilter(CClearingPartPositionIterator *pBaseIterator, CClearingPartPositionPredict *pPredict, bool continueResult=false)
		:CClearingPartPositionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CClearingPartPositionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CClearingPartPosition
	///@return	��һ����������CClearingPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionLinkIterator���������������Ա�ֲ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionLinkIterator: public CClearingPartPositionIterator
{
private:
	CClearingPartPositionIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CClearingPartPositionLinkIterator(CClearingPartPositionIterator *pBaseIterator1,CClearingPartPositionIterator *pBaseIterator2)
		:CClearingPartPositionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CClearingPartPositionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CClearingPartPosition
	///@return	��һ����������CClearingPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusSingleIterator�����෵��һ����Լ״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusSingleIterator: public CInstrumentStatusIterator
{
private:
	CInstrumentStatus *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CInstrumentStatusSingleIterator(CInstrumentStatusFactory *pFactory,CInstrumentStatus *pResult)
		:CInstrumentStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CInstrumentStatusSingleIterator(void)
	{
	}

	///Ѱ����һ������������CInstrumentStatus
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusPredict���ж�һ����Լ״̬�Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatus	Ҫ���жϵĺ�Լ״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusAndPredict�Ƕ�������Լ״̬ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusAndPredict : public CInstrumentStatusPredict
{
private:
	CInstrumentStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInstrumentStatusAndPredict(CInstrumentStatusPredict *p1, CInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInstrumentStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatus	Ҫ���жϵĺ�Լ״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)
	{
		return m_p1->isValid(pInstrumentStatus) && m_p2->isValid(pInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusOrPredict�Ƕ�������Լ״̬ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusOrPredict : public CInstrumentStatusPredict
{
private:
	CInstrumentStatusPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CInstrumentStatusOrPredict(CInstrumentStatusPredict *p1, CInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CInstrumentStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatus	Ҫ���жϵĺ�Լ״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)
	{
		return m_p1->isValid(pInstrumentStatus) || m_p2->isValid(pInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusNotPredict�Ƕ�һ����Լ״̬ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusNotPredict : public CInstrumentStatusPredict
{
private:
	CInstrumentStatusPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CInstrumentStatusNotPredict(CInstrumentStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CInstrumentStatusNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pInstrumentStatus	Ҫ���жϵĺ�Լ״̬
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)
	{
		return !m_predict->isValid(pInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusFilter��һ�������еĺ�Լ״̬ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusFilter: public CInstrumentStatusIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CInstrumentStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CInstrumentStatusFilter(CInstrumentStatusIterator *pBaseIterator, CInstrumentStatusPredict *pPredict, bool continueResult=false)
		:CInstrumentStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CInstrumentStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CInstrumentStatus
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusLinkIterator������������Լ״̬ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusLinkIterator: public CInstrumentStatusIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CInstrumentStatusLinkIterator(CInstrumentStatusIterator *pBaseIterator1,CInstrumentStatusIterator *pBaseIterator2)
		:CInstrumentStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CInstrumentStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CInstrumentStatus
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfInstrumentStatusIterator��һ����Լ״̬ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfInstrumentStatusIterator: public CInstrumentIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfInstrumentStatusIterator(CInstrumentFactory *pFactory,CInstrumentStatusIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfInstrumentStatusIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingOfInstrumentStatusIterator��һ����Լ״̬ö������Ӧ�ļ۸�󶨵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingOfInstrumentStatusIterator: public CCurrPriceBandingIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CCurrPriceBanding *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CCurrPriceBandingOfInstrumentStatusIterator(CCurrPriceBandingFactory *pFactory,CInstrumentStatusIterator *pBaseIterator)
		:CCurrPriceBandingIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CCurrPriceBandingOfInstrumentStatusIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CCurrPriceBanding
	///@return	��һ����������CCurrPriceBanding������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPriceBanding *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPriceBanding ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPriceBanding *pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusOfInstrumentStatusIterator��һ����Լ״̬ö������Ӧ�����鷢��״̬��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusOfInstrumentStatusIterator: public CMdPubStatusIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CMdPubStatus *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CMdPubStatusOfInstrumentStatusIterator(CMdPubStatusFactory *pFactory,CInstrumentStatusIterator *pBaseIterator)
		:CMdPubStatusIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CMdPubStatusOfInstrumentStatusIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CMdPubStatus
	///@return	��һ����������CMdPubStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMdPubStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMdPubStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMdPubStatus *pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///COrderSingleIterator�����෵��һ��������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderSingleIterator: public COrderIterator
{
private:
	COrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	COrderSingleIterator(COrderFactory *pFactory,COrder *pResult)
		:COrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~COrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������COrder
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderPredict���ж�һ�������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pOrder	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrder *pOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///COrderAndPredict�Ƕ���������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderAndPredict : public COrderPredict
{
private:
	COrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	COrderAndPredict(COrderPredict *p1, COrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~COrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOrder	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrder *pOrder)
	{
		return m_p1->isValid(pOrder) && m_p2->isValid(pOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderOrPredict�Ƕ���������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderOrPredict : public COrderPredict
{
private:
	COrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	COrderOrPredict(COrderPredict *p1, COrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~COrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOrder	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrder *pOrder)
	{
		return m_p1->isValid(pOrder) || m_p2->isValid(pOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderNotPredict�Ƕ�һ������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderNotPredict : public COrderPredict
{
private:
	COrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	COrderNotPredict(COrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~COrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOrder	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COrder *pOrder)
	{
		return !m_predict->isValid(pOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderFilter��һ�������еı���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderFilter: public COrderIterator
{
private:
	COrderIterator *m_baseIterator;
	COrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	COrderFilter(COrderIterator *pBaseIterator, COrderPredict *pPredict, bool continueResult=false)
		:COrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~COrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������COrder
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderLinkIterator��������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderLinkIterator: public COrderIterator
{
private:
	COrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	COrderLinkIterator(COrderIterator *pBaseIterator1,COrderIterator *pBaseIterator2)
		:COrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~COrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������COrder
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfOrderIterator��һ������ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfOrderIterator: public CInstrumentIterator
{
private:
	COrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfOrderIterator(CInstrumentFactory *pFactory,COrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfOrderIterator��һ������ö����ָ���Ļ�Ա�ͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfOrderIterator: public CPartClientIterator
{
private:
	COrderIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CPartClientOfOrderIterator(CPartClientFactory *pFactory,COrderIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CPartClientOfOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionOfOrderIterator��һ������ö������Ӧ�Ŀͻ��ֲֵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionOfOrderIterator: public CClientPositionIterator
{
private:
	COrderIterator *m_baseIterator;
	CClientPosition *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CClientPositionOfOrderIterator(CClientPositionFactory *pFactory,COrderIterator *pBaseIterator)
		:CClientPositionIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CClientPositionOfOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CClientPosition
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition *pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCombOrderSingleIterator�����෵��һ����ϱ�����ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderSingleIterator: public CCombOrderIterator
{
private:
	CCombOrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCombOrderSingleIterator(CCombOrderFactory *pFactory,CCombOrder *pResult)
		:CCombOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCombOrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCombOrder
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderPredict���ж�һ����ϱ����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCombOrder	Ҫ���жϵ���ϱ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombOrder *pCombOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderAndPredict�Ƕ�������ϱ���ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderAndPredict : public CCombOrderPredict
{
private:
	CCombOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCombOrderAndPredict(CCombOrderPredict *p1, CCombOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCombOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCombOrder	Ҫ���жϵ���ϱ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombOrder *pCombOrder)
	{
		return m_p1->isValid(pCombOrder) && m_p2->isValid(pCombOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderOrPredict�Ƕ�������ϱ���ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderOrPredict : public CCombOrderPredict
{
private:
	CCombOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCombOrderOrPredict(CCombOrderPredict *p1, CCombOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCombOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCombOrder	Ҫ���жϵ���ϱ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombOrder *pCombOrder)
	{
		return m_p1->isValid(pCombOrder) || m_p2->isValid(pCombOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderNotPredict�Ƕ�һ����ϱ���ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderNotPredict : public CCombOrderPredict
{
private:
	CCombOrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCombOrderNotPredict(CCombOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCombOrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCombOrder	Ҫ���жϵ���ϱ���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCombOrder *pCombOrder)
	{
		return !m_predict->isValid(pCombOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderFilter��һ�������е���ϱ���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderFilter: public CCombOrderIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CCombOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCombOrderFilter(CCombOrderIterator *pBaseIterator, CCombOrderPredict *pPredict, bool continueResult=false)
		:CCombOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCombOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCombOrder
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderLinkIterator������������ϱ���ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderLinkIterator: public CCombOrderIterator
{
private:
	CCombOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCombOrderLinkIterator(CCombOrderIterator *pBaseIterator1,CCombOrderIterator *pBaseIterator2)
		:CCombOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCombOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCombOrder
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfCombOrderIterator��һ����ϱ���ö����ָ���Ļ�Ա�ͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfCombOrderIterator: public CPartClientIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CPartClientOfCombOrderIterator(CPartClientFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CPartClientOfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument1OfCombOrderIterator��һ����ϱ���ö������Ӧ�ĺ�Լ1��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument1OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrument1OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrument1OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument2OfCombOrderIterator��һ����ϱ���ö������Ӧ�ĺ�Լ2��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument2OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrument2OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrument2OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument3OfCombOrderIterator��һ����ϱ���ö������Ӧ�ĺ�Լ3��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument3OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrument3OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrument3OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument4OfCombOrderIterator��һ����ϱ���ö������Ӧ�ĺ�Լ4��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument4OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrument4OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrument4OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///COTCOrderSingleIterator�����෵��һ��OTC������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderSingleIterator: public COTCOrderIterator
{
private:
	COTCOrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	COTCOrderSingleIterator(COTCOrderFactory *pFactory,COTCOrder *pResult)
		:COTCOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~COTCOrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������COTCOrder
	///@return	��һ����������COTCOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COTCOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOTCOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderPredict���ж�һ��OTC�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pOTCOrder	Ҫ���жϵ�OTC����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COTCOrder *pOTCOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderAndPredict�Ƕ�����OTC����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderAndPredict : public COTCOrderPredict
{
private:
	COTCOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	COTCOrderAndPredict(COTCOrderPredict *p1, COTCOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~COTCOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOTCOrder	Ҫ���жϵ�OTC����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COTCOrder *pOTCOrder)
	{
		return m_p1->isValid(pOTCOrder) && m_p2->isValid(pOTCOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderOrPredict�Ƕ�����OTC����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderOrPredict : public COTCOrderPredict
{
private:
	COTCOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	COTCOrderOrPredict(COTCOrderPredict *p1, COTCOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~COTCOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOTCOrder	Ҫ���жϵ�OTC����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COTCOrder *pOTCOrder)
	{
		return m_p1->isValid(pOTCOrder) || m_p2->isValid(pOTCOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderNotPredict�Ƕ�һ��OTC����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderNotPredict : public COTCOrderPredict
{
private:
	COTCOrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	COTCOrderNotPredict(COTCOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~COTCOrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pOTCOrder	Ҫ���жϵ�OTC����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(COTCOrder *pOTCOrder)
	{
		return !m_predict->isValid(pOTCOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderFilter��һ�������е�OTC����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderFilter: public COTCOrderIterator
{
private:
	COTCOrderIterator *m_baseIterator;
	COTCOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	COTCOrderFilter(COTCOrderIterator *pBaseIterator, COTCOrderPredict *pPredict, bool continueResult=false)
		:COTCOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~COTCOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������COTCOrder
	///@return	��һ����������COTCOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COTCOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOTCOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderLinkIterator����������OTC����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderLinkIterator: public COTCOrderIterator
{
private:
	COTCOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	COTCOrderLinkIterator(COTCOrderIterator *pBaseIterator1,COTCOrderIterator *pBaseIterator2)
		:COTCOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~COTCOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������COTCOrder
	///@return	��һ����������COTCOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COTCOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOTCOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfOTCOrderIterator��һ��OTC����ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfOTCOrderIterator: public CInstrumentIterator
{
private:
	COTCOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfOTCOrderIterator(CInstrumentFactory *pFactory,COTCOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfOTCOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CImplyOrderSingleIterator�����෵��һ����ʽ������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderSingleIterator: public CImplyOrderIterator
{
private:
	CImplyOrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CImplyOrderSingleIterator(CImplyOrderFactory *pFactory,CImplyOrder *pResult)
		:CImplyOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CImplyOrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������CImplyOrder
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CImplyOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pImplyOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderPredict���ж�һ����ʽ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pImplyOrder	Ҫ���жϵ���ʽ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CImplyOrder *pImplyOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderAndPredict�Ƕ�������ʽ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderAndPredict : public CImplyOrderPredict
{
private:
	CImplyOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CImplyOrderAndPredict(CImplyOrderPredict *p1, CImplyOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CImplyOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pImplyOrder	Ҫ���жϵ���ʽ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CImplyOrder *pImplyOrder)
	{
		return m_p1->isValid(pImplyOrder) && m_p2->isValid(pImplyOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderOrPredict�Ƕ�������ʽ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderOrPredict : public CImplyOrderPredict
{
private:
	CImplyOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CImplyOrderOrPredict(CImplyOrderPredict *p1, CImplyOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CImplyOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pImplyOrder	Ҫ���жϵ���ʽ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CImplyOrder *pImplyOrder)
	{
		return m_p1->isValid(pImplyOrder) || m_p2->isValid(pImplyOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderNotPredict�Ƕ�һ����ʽ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderNotPredict : public CImplyOrderPredict
{
private:
	CImplyOrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CImplyOrderNotPredict(CImplyOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CImplyOrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pImplyOrder	Ҫ���жϵ���ʽ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CImplyOrder *pImplyOrder)
	{
		return !m_predict->isValid(pImplyOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderFilter��һ�������е���ʽ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderFilter: public CImplyOrderIterator
{
private:
	CImplyOrderIterator *m_baseIterator;
	CImplyOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CImplyOrderFilter(CImplyOrderIterator *pBaseIterator, CImplyOrderPredict *pPredict, bool continueResult=false)
		:CImplyOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CImplyOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CImplyOrder
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CImplyOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pImplyOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderLinkIterator������������ʽ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderLinkIterator: public CImplyOrderIterator
{
private:
	CImplyOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CImplyOrderLinkIterator(CImplyOrderIterator *pBaseIterator1,CImplyOrderIterator *pBaseIterator2)
		:CImplyOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CImplyOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CImplyOrder
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CImplyOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pImplyOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CQuoteSingleIterator�����෵��һ�����۵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteSingleIterator: public CQuoteIterator
{
private:
	CQuote *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CQuoteSingleIterator(CQuoteFactory *pFactory,CQuote *pResult)
		:CQuoteIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CQuoteSingleIterator(void)
	{
	}

	///Ѱ����һ������������CQuote
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CQuote *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pQuote ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CQuotePredict���ж�һ�������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuotePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pQuote	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CQuote *pQuote)=0;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteAndPredict�Ƕ���������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteAndPredict : public CQuotePredict
{
private:
	CQuotePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CQuoteAndPredict(CQuotePredict *p1, CQuotePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CQuoteAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pQuote	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CQuote *pQuote)
	{
		return m_p1->isValid(pQuote) && m_p2->isValid(pQuote);
	}
};

/////////////////////////////////////////////////////////////////////////
///CQuoteOrPredict�Ƕ���������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteOrPredict : public CQuotePredict
{
private:
	CQuotePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CQuoteOrPredict(CQuotePredict *p1, CQuotePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CQuoteOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pQuote	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CQuote *pQuote)
	{
		return m_p1->isValid(pQuote) || m_p2->isValid(pQuote);
	}
};

/////////////////////////////////////////////////////////////////////////
///CQuoteNotPredict�Ƕ�һ������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteNotPredict : public CQuotePredict
{
private:
	CQuotePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CQuoteNotPredict(CQuotePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CQuoteNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pQuote	Ҫ���жϵı���
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CQuote *pQuote)
	{
		return !m_predict->isValid(pQuote);
	}
};

/////////////////////////////////////////////////////////////////////////
///CQuoteFilter��һ�������еı���ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteFilter: public CQuoteIterator
{
private:
	CQuoteIterator *m_baseIterator;
	CQuotePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CQuoteFilter(CQuoteIterator *pBaseIterator, CQuotePredict *pPredict, bool continueResult=false)
		:CQuoteIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CQuoteFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CQuote
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CQuote *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pQuote ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CQuoteLinkIterator��������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteLinkIterator: public CQuoteIterator
{
private:
	CQuoteIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CQuoteLinkIterator(CQuoteIterator *pBaseIterator1,CQuoteIterator *pBaseIterator2)
		:CQuoteIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CQuoteLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CQuote
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CQuote *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pQuote ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfQuoteIterator��һ������ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfQuoteIterator: public CInstrumentIterator
{
private:
	CQuoteIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfQuoteIterator(CInstrumentFactory *pFactory,CQuoteIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfQuoteIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfQuoteIterator��һ������ö����ָ���Ļ�Ա�ͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfQuoteIterator: public CPartClientIterator
{
private:
	CQuoteIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CPartClientOfQuoteIterator(CPartClientFactory *pFactory,CQuoteIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CPartClientOfQuoteIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataSingleIterator�����෵��һ���ּ۱��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataSingleIterator: public CMBLMarketDataIterator
{
private:
	CMBLMarketData *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMBLMarketDataSingleIterator(CMBLMarketDataFactory *pFactory,CMBLMarketData *pResult)
		:CMBLMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMBLMarketDataSingleIterator(void)
	{
	}

	///Ѱ����һ������������CMBLMarketData
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMBLMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataPredict���ж�һ���ּ۱��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMBLMarketData	Ҫ���жϵķּ۱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMBLMarketData *pMBLMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataAndPredict�Ƕ������ּ۱�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataAndPredict : public CMBLMarketDataPredict
{
private:
	CMBLMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMBLMarketDataAndPredict(CMBLMarketDataPredict *p1, CMBLMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMBLMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMBLMarketData	Ҫ���жϵķּ۱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMBLMarketData *pMBLMarketData)
	{
		return m_p1->isValid(pMBLMarketData) && m_p2->isValid(pMBLMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataOrPredict�Ƕ������ּ۱�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataOrPredict : public CMBLMarketDataPredict
{
private:
	CMBLMarketDataPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMBLMarketDataOrPredict(CMBLMarketDataPredict *p1, CMBLMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMBLMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMBLMarketData	Ҫ���жϵķּ۱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMBLMarketData *pMBLMarketData)
	{
		return m_p1->isValid(pMBLMarketData) || m_p2->isValid(pMBLMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataNotPredict�Ƕ�һ���ּ۱�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataNotPredict : public CMBLMarketDataPredict
{
private:
	CMBLMarketDataPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMBLMarketDataNotPredict(CMBLMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMBLMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMBLMarketData	Ҫ���жϵķּ۱�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMBLMarketData *pMBLMarketData)
	{
		return !m_predict->isValid(pMBLMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataFilter��һ�������еķּ۱�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataFilter: public CMBLMarketDataIterator
{
private:
	CMBLMarketDataIterator *m_baseIterator;
	CMBLMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMBLMarketDataFilter(CMBLMarketDataIterator *pBaseIterator, CMBLMarketDataPredict *pPredict, bool continueResult=false)
		:CMBLMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMBLMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMBLMarketData
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMBLMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataLinkIterator�����������ּ۱�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataLinkIterator: public CMBLMarketDataIterator
{
private:
	CMBLMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMBLMarketDataLinkIterator(CMBLMarketDataIterator *pBaseIterator1,CMBLMarketDataIterator *pBaseIterator2)
		:CMBLMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMBLMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMBLMarketData
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMBLMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTradeSingleIterator�����෵��һ���ɽ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeSingleIterator: public CTradeIterator
{
private:
	CTrade *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CTradeSingleIterator(CTradeFactory *pFactory,CTrade *pResult)
		:CTradeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CTradeSingleIterator(void)
	{
	}

	///Ѱ����һ������������CTrade
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradePredict���ж�һ���ɽ��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pTrade	Ҫ���жϵĳɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTrade *pTrade)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTradeAndPredict�Ƕ������ɽ�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeAndPredict : public CTradePredict
{
private:
	CTradePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTradeAndPredict(CTradePredict *p1, CTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTradeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTrade	Ҫ���жϵĳɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTrade *pTrade)
	{
		return m_p1->isValid(pTrade) && m_p2->isValid(pTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradeOrPredict�Ƕ������ɽ�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeOrPredict : public CTradePredict
{
private:
	CTradePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CTradeOrPredict(CTradePredict *p1, CTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CTradeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTrade	Ҫ���жϵĳɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTrade *pTrade)
	{
		return m_p1->isValid(pTrade) || m_p2->isValid(pTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradeNotPredict�Ƕ�һ���ɽ�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeNotPredict : public CTradePredict
{
private:
	CTradePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CTradeNotPredict(CTradePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CTradeNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pTrade	Ҫ���жϵĳɽ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CTrade *pTrade)
	{
		return !m_predict->isValid(pTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradeFilter��һ�������еĳɽ�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeFilter: public CTradeIterator
{
private:
	CTradeIterator *m_baseIterator;
	CTradePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CTradeFilter(CTradeIterator *pBaseIterator, CTradePredict *pPredict, bool continueResult=false)
		:CTradeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CTradeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CTrade
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradeLinkIterator�����������ɽ�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeLinkIterator: public CTradeIterator
{
private:
	CTradeIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CTradeLinkIterator(CTradeIterator *pBaseIterator1,CTradeIterator *pBaseIterator2)
		:CTradeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CTradeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CTrade
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfTradeIterator��һ���ɽ�ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfTradeIterator: public CInstrumentIterator
{
private:
	CTradeIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfTradeIterator(CInstrumentFactory *pFactory,CTradeIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfTradeIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfTradeIterator��һ���ɽ�ö����ָ���Ļ�Ա�ͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfTradeIterator: public CPartClientIterator
{
private:
	CTradeIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CPartClientOfTradeIterator(CPartClientFactory *pFactory,CTradeIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CPartClientOfTradeIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CFusePhaseSingleIterator�����෵��һ���۶Ͻ׶ε�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseSingleIterator: public CFusePhaseIterator
{
private:
	CFusePhase *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CFusePhaseSingleIterator(CFusePhaseFactory *pFactory,CFusePhase *pResult)
		:CFusePhaseIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CFusePhaseSingleIterator(void)
	{
	}

	///Ѱ����һ������������CFusePhase
	///@return	��һ����������CFusePhase������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFusePhase *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFusePhase ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhasePredict���ж�һ���۶Ͻ׶��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhasePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pFusePhase	Ҫ���жϵ��۶Ͻ׶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFusePhase *pFusePhase)=0;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseAndPredict�Ƕ������۶Ͻ׶�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseAndPredict : public CFusePhasePredict
{
private:
	CFusePhasePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CFusePhaseAndPredict(CFusePhasePredict *p1, CFusePhasePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CFusePhaseAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pFusePhase	Ҫ���жϵ��۶Ͻ׶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFusePhase *pFusePhase)
	{
		return m_p1->isValid(pFusePhase) && m_p2->isValid(pFusePhase);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseOrPredict�Ƕ������۶Ͻ׶�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseOrPredict : public CFusePhasePredict
{
private:
	CFusePhasePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CFusePhaseOrPredict(CFusePhasePredict *p1, CFusePhasePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CFusePhaseOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pFusePhase	Ҫ���жϵ��۶Ͻ׶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFusePhase *pFusePhase)
	{
		return m_p1->isValid(pFusePhase) || m_p2->isValid(pFusePhase);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseNotPredict�Ƕ�һ���۶Ͻ׶�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseNotPredict : public CFusePhasePredict
{
private:
	CFusePhasePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CFusePhaseNotPredict(CFusePhasePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CFusePhaseNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pFusePhase	Ҫ���жϵ��۶Ͻ׶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CFusePhase *pFusePhase)
	{
		return !m_predict->isValid(pFusePhase);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseFilter��һ�������е��۶Ͻ׶�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseFilter: public CFusePhaseIterator
{
private:
	CFusePhaseIterator *m_baseIterator;
	CFusePhasePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CFusePhaseFilter(CFusePhaseIterator *pBaseIterator, CFusePhasePredict *pPredict, bool continueResult=false)
		:CFusePhaseIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CFusePhaseFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CFusePhase
	///@return	��һ����������CFusePhase������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFusePhase *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFusePhase ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseLinkIterator�����������۶Ͻ׶�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseLinkIterator: public CFusePhaseIterator
{
private:
	CFusePhaseIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CFusePhaseLinkIterator(CFusePhaseIterator *pBaseIterator1,CFusePhaseIterator *pBaseIterator2)
		:CFusePhaseIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CFusePhaseLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CFusePhase
	///@return	��һ����������CFusePhase������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFusePhase *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFusePhase ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfFusePhaseIterator��һ���۶Ͻ׶�ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfFusePhaseIterator: public CInstrumentIterator
{
private:
	CFusePhaseIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfFusePhaseIterator(CInstrumentFactory *pFactory,CFusePhaseIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfFusePhaseIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CExecOrderSingleIterator�����෵��һ��ִ�������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderSingleIterator: public CExecOrderIterator
{
private:
	CExecOrder *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CExecOrderSingleIterator(CExecOrderFactory *pFactory,CExecOrder *pResult)
		:CExecOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CExecOrderSingleIterator(void)
	{
	}

	///Ѱ����һ������������CExecOrder
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExecOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderPredict���ж�һ��ִ�������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pExecOrder	Ҫ���жϵ�ִ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExecOrder *pExecOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderAndPredict�Ƕ�����ִ������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderAndPredict : public CExecOrderPredict
{
private:
	CExecOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CExecOrderAndPredict(CExecOrderPredict *p1, CExecOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CExecOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExecOrder	Ҫ���жϵ�ִ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExecOrder *pExecOrder)
	{
		return m_p1->isValid(pExecOrder) && m_p2->isValid(pExecOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderOrPredict�Ƕ�����ִ������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderOrPredict : public CExecOrderPredict
{
private:
	CExecOrderPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CExecOrderOrPredict(CExecOrderPredict *p1, CExecOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CExecOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExecOrder	Ҫ���жϵ�ִ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExecOrder *pExecOrder)
	{
		return m_p1->isValid(pExecOrder) || m_p2->isValid(pExecOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderNotPredict�Ƕ�һ��ִ������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderNotPredict : public CExecOrderPredict
{
private:
	CExecOrderPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CExecOrderNotPredict(CExecOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CExecOrderNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pExecOrder	Ҫ���жϵ�ִ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CExecOrder *pExecOrder)
	{
		return !m_predict->isValid(pExecOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderFilter��һ�������е�ִ������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderFilter: public CExecOrderIterator
{
private:
	CExecOrderIterator *m_baseIterator;
	CExecOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CExecOrderFilter(CExecOrderIterator *pBaseIterator, CExecOrderPredict *pPredict, bool continueResult=false)
		:CExecOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CExecOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CExecOrder
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExecOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderLinkIterator����������ִ������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderLinkIterator: public CExecOrderIterator
{
private:
	CExecOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CExecOrderLinkIterator(CExecOrderIterator *pBaseIterator1,CExecOrderIterator *pBaseIterator2)
		:CExecOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CExecOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CExecOrder
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExecOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfExecOrderIterator��һ��ִ������ö����ָ���Ļ�Ա�ͻ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfExecOrderIterator: public CPartClientIterator
{
private:
	CExecOrderIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CPartClientOfExecOrderIterator(CPartClientFactory *pFactory,CExecOrderIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CPartClientOfExecOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CPartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfExecOrderIterator��һ��ִ������ö������Ӧ�ĺ�Լ��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfExecOrderIterator: public CInstrumentIterator
{
private:
	CExecOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///���캯��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pBaseIterator	������ö����
	CInstrumentOfExecOrderIterator(CInstrumentFactory *pFactory,CExecOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///��������
	~CInstrumentOfExecOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///Ѱ����һ������������CInstrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUniPressureSingleIterator�����෵��һ�������������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureSingleIterator: public CUniPressureIterator
{
private:
	CUniPressure *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CUniPressureSingleIterator(CUniPressureFactory *pFactory,CUniPressure *pResult)
		:CUniPressureIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CUniPressureSingleIterator(void)
	{
	}

	///Ѱ����һ������������CUniPressure
	///@return	��һ����������CUniPressure������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUniPressure *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUniPressure ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressurePredict���ж�һ������������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressurePredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pUniPressure	Ҫ���жϵĵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUniPressure *pUniPressure)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureAndPredict�Ƕ��������������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureAndPredict : public CUniPressurePredict
{
private:
	CUniPressurePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUniPressureAndPredict(CUniPressurePredict *p1, CUniPressurePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUniPressureAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUniPressure	Ҫ���жϵĵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUniPressure *pUniPressure)
	{
		return m_p1->isValid(pUniPressure) && m_p2->isValid(pUniPressure);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureOrPredict�Ƕ��������������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureOrPredict : public CUniPressurePredict
{
private:
	CUniPressurePredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CUniPressureOrPredict(CUniPressurePredict *p1, CUniPressurePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CUniPressureOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUniPressure	Ҫ���жϵĵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUniPressure *pUniPressure)
	{
		return m_p1->isValid(pUniPressure) || m_p2->isValid(pUniPressure);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureNotPredict�Ƕ�һ�����������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureNotPredict : public CUniPressurePredict
{
private:
	CUniPressurePredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CUniPressureNotPredict(CUniPressurePredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CUniPressureNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pUniPressure	Ҫ���жϵĵ��������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CUniPressure *pUniPressure)
	{
		return !m_predict->isValid(pUniPressure);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureFilter��һ�������еĵ��������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureFilter: public CUniPressureIterator
{
private:
	CUniPressureIterator *m_baseIterator;
	CUniPressurePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CUniPressureFilter(CUniPressureIterator *pBaseIterator, CUniPressurePredict *pPredict, bool continueResult=false)
		:CUniPressureIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CUniPressureFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CUniPressure
	///@return	��һ����������CUniPressure������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUniPressure *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUniPressure ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureLinkIterator�������������������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureLinkIterator: public CUniPressureIterator
{
private:
	CUniPressureIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CUniPressureLinkIterator(CUniPressureIterator *pBaseIterator1,CUniPressureIterator *pBaseIterator2)
		:CUniPressureIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CUniPressureLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CUniPressure
	///@return	��һ����������CUniPressure������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUniPressure *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUniPressure ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitSingleIterator�����෵��һ���ǵ�ͣ�����õ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitSingleIterator: public CBasePriceLimitIterator
{
private:
	CBasePriceLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CBasePriceLimitSingleIterator(CBasePriceLimitFactory *pFactory,CBasePriceLimit *pResult)
		:CBasePriceLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CBasePriceLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CBasePriceLimit
	///@return	��һ����������CBasePriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBasePriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBasePriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitPredict���ж�һ���ǵ�ͣ�������Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pBasePriceLimit	Ҫ���жϵ��ǵ�ͣ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitAndPredict�Ƕ������ǵ�ͣ������ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitAndPredict : public CBasePriceLimitPredict
{
private:
	CBasePriceLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CBasePriceLimitAndPredict(CBasePriceLimitPredict *p1, CBasePriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CBasePriceLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBasePriceLimit	Ҫ���жϵ��ǵ�ͣ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)
	{
		return m_p1->isValid(pBasePriceLimit) && m_p2->isValid(pBasePriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitOrPredict�Ƕ������ǵ�ͣ������ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitOrPredict : public CBasePriceLimitPredict
{
private:
	CBasePriceLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CBasePriceLimitOrPredict(CBasePriceLimitPredict *p1, CBasePriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CBasePriceLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBasePriceLimit	Ҫ���жϵ��ǵ�ͣ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)
	{
		return m_p1->isValid(pBasePriceLimit) || m_p2->isValid(pBasePriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitNotPredict�Ƕ�һ���ǵ�ͣ������ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitNotPredict : public CBasePriceLimitPredict
{
private:
	CBasePriceLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CBasePriceLimitNotPredict(CBasePriceLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CBasePriceLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pBasePriceLimit	Ҫ���жϵ��ǵ�ͣ������
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)
	{
		return !m_predict->isValid(pBasePriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitFilter��һ�������е��ǵ�ͣ������ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitFilter: public CBasePriceLimitIterator
{
private:
	CBasePriceLimitIterator *m_baseIterator;
	CBasePriceLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CBasePriceLimitFilter(CBasePriceLimitIterator *pBaseIterator, CBasePriceLimitPredict *pPredict, bool continueResult=false)
		:CBasePriceLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CBasePriceLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CBasePriceLimit
	///@return	��һ����������CBasePriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBasePriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBasePriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitLinkIterator�����������ǵ�ͣ������ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitLinkIterator: public CBasePriceLimitIterator
{
private:
	CBasePriceLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CBasePriceLimitLinkIterator(CBasePriceLimitIterator *pBaseIterator1,CBasePriceLimitIterator *pBaseIterator2)
		:CBasePriceLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CBasePriceLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CBasePriceLimit
	///@return	��һ����������CBasePriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBasePriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBasePriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCreditLimitSingleIterator�����෵��һ�������޶��ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitSingleIterator: public CCreditLimitIterator
{
private:
	CCreditLimit *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCreditLimitSingleIterator(CCreditLimitFactory *pFactory,CCreditLimit *pResult)
		:CCreditLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCreditLimitSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCreditLimit
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCreditLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitPredict���ж�һ�������޶��Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCreditLimit	Ҫ���жϵ������޶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCreditLimit *pCreditLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitAndPredict�Ƕ����������޶�ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitAndPredict : public CCreditLimitPredict
{
private:
	CCreditLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCreditLimitAndPredict(CCreditLimitPredict *p1, CCreditLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCreditLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCreditLimit	Ҫ���жϵ������޶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCreditLimit *pCreditLimit)
	{
		return m_p1->isValid(pCreditLimit) && m_p2->isValid(pCreditLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitOrPredict�Ƕ����������޶�ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitOrPredict : public CCreditLimitPredict
{
private:
	CCreditLimitPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCreditLimitOrPredict(CCreditLimitPredict *p1, CCreditLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCreditLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCreditLimit	Ҫ���жϵ������޶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCreditLimit *pCreditLimit)
	{
		return m_p1->isValid(pCreditLimit) || m_p2->isValid(pCreditLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitNotPredict�Ƕ�һ�������޶�ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitNotPredict : public CCreditLimitPredict
{
private:
	CCreditLimitPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCreditLimitNotPredict(CCreditLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCreditLimitNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCreditLimit	Ҫ���жϵ������޶�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCreditLimit *pCreditLimit)
	{
		return !m_predict->isValid(pCreditLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitFilter��һ�������е������޶�ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitFilter: public CCreditLimitIterator
{
private:
	CCreditLimitIterator *m_baseIterator;
	CCreditLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCreditLimitFilter(CCreditLimitIterator *pBaseIterator, CCreditLimitPredict *pPredict, bool continueResult=false)
		:CCreditLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCreditLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCreditLimit
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCreditLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitLinkIterator���������������޶�ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitLinkIterator: public CCreditLimitIterator
{
private:
	CCreditLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCreditLimitLinkIterator(CCreditLimitIterator *pBaseIterator1,CCreditLimitIterator *pBaseIterator2)
		:CCreditLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCreditLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCreditLimit
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCreditLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionSingleIterator�����෵��һ�������ڻ���Լ��Ȩ���Ե�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionSingleIterator: public CCurrInstrumentOptionIterator
{
private:
	CCurrInstrumentOption *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CCurrInstrumentOptionSingleIterator(CCurrInstrumentOptionFactory *pFactory,CCurrInstrumentOption *pResult)
		:CCurrInstrumentOptionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CCurrInstrumentOptionSingleIterator(void)
	{
	}

	///Ѱ����һ������������CCurrInstrumentOption
	///@return	��һ����������CCurrInstrumentOption������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentOption *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentOption ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionPredict���ж�һ�������ڻ���Լ��Ȩ�����Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentOption	Ҫ���жϵĵ����ڻ���Լ��Ȩ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionAndPredict�Ƕ����������ڻ���Լ��Ȩ����ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionAndPredict : public CCurrInstrumentOptionPredict
{
private:
	CCurrInstrumentOptionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrInstrumentOptionAndPredict(CCurrInstrumentOptionPredict *p1, CCurrInstrumentOptionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrInstrumentOptionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentOption	Ҫ���жϵĵ����ڻ���Լ��Ȩ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return m_p1->isValid(pCurrInstrumentOption) && m_p2->isValid(pCurrInstrumentOption);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionOrPredict�Ƕ����������ڻ���Լ��Ȩ����ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionOrPredict : public CCurrInstrumentOptionPredict
{
private:
	CCurrInstrumentOptionPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CCurrInstrumentOptionOrPredict(CCurrInstrumentOptionPredict *p1, CCurrInstrumentOptionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CCurrInstrumentOptionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentOption	Ҫ���жϵĵ����ڻ���Լ��Ȩ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return m_p1->isValid(pCurrInstrumentOption) || m_p2->isValid(pCurrInstrumentOption);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionNotPredict�Ƕ�һ�������ڻ���Լ��Ȩ����ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionNotPredict : public CCurrInstrumentOptionPredict
{
private:
	CCurrInstrumentOptionPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CCurrInstrumentOptionNotPredict(CCurrInstrumentOptionPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CCurrInstrumentOptionNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pCurrInstrumentOption	Ҫ���жϵĵ����ڻ���Լ��Ȩ����
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return !m_predict->isValid(pCurrInstrumentOption);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionFilter��һ�������еĵ����ڻ���Լ��Ȩ����ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionFilter: public CCurrInstrumentOptionIterator
{
private:
	CCurrInstrumentOptionIterator *m_baseIterator;
	CCurrInstrumentOptionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CCurrInstrumentOptionFilter(CCurrInstrumentOptionIterator *pBaseIterator, CCurrInstrumentOptionPredict *pPredict, bool continueResult=false)
		:CCurrInstrumentOptionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CCurrInstrumentOptionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CCurrInstrumentOption
	///@return	��һ����������CCurrInstrumentOption������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentOption *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentOption ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionLinkIterator���������������ڻ���Լ��Ȩ����ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionLinkIterator: public CCurrInstrumentOptionIterator
{
private:
	CCurrInstrumentOptionIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CCurrInstrumentOptionLinkIterator(CCurrInstrumentOptionIterator *pBaseIterator1,CCurrInstrumentOptionIterator *pBaseIterator2)
		:CCurrInstrumentOptionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CCurrInstrumentOptionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CCurrInstrumentOption
	///@return	��һ����������CCurrInstrumentOption������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentOption *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentOption ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


#endif
