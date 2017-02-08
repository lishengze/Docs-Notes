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
///CMonitorEntitySingleIterator�����෵��һ�����ʵ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntitySingleIterator: public CMonitorEntityIterator
{
private:
	CMonitorEntity *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CMonitorEntitySingleIterator(CMonitorEntityFactory *pFactory,CMonitorEntity *pResult)
		:CMonitorEntityIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CMonitorEntitySingleIterator(void)
	{
	}

	///Ѱ����һ������������CMonitorEntity
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMonitorEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMonitorEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityPredict���ж�һ�����ʵ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pMonitorEntity	Ҫ���жϵļ��ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMonitorEntity *pMonitorEntity)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityAndPredict�Ƕ��������ʵ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityAndPredict : public CMonitorEntityPredict
{
private:
	CMonitorEntityPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMonitorEntityAndPredict(CMonitorEntityPredict *p1, CMonitorEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMonitorEntityAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMonitorEntity	Ҫ���жϵļ��ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMonitorEntity *pMonitorEntity)
	{
		return m_p1->isValid(pMonitorEntity) && m_p2->isValid(pMonitorEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityOrPredict�Ƕ��������ʵ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityOrPredict : public CMonitorEntityPredict
{
private:
	CMonitorEntityPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CMonitorEntityOrPredict(CMonitorEntityPredict *p1, CMonitorEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CMonitorEntityOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMonitorEntity	Ҫ���жϵļ��ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMonitorEntity *pMonitorEntity)
	{
		return m_p1->isValid(pMonitorEntity) || m_p2->isValid(pMonitorEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityNotPredict�Ƕ�һ�����ʵ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityNotPredict : public CMonitorEntityPredict
{
private:
	CMonitorEntityPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CMonitorEntityNotPredict(CMonitorEntityPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CMonitorEntityNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pMonitorEntity	Ҫ���жϵļ��ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CMonitorEntity *pMonitorEntity)
	{
		return !m_predict->isValid(pMonitorEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityFilter��һ�������еļ��ʵ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityFilter: public CMonitorEntityIterator
{
private:
	CMonitorEntityIterator *m_baseIterator;
	CMonitorEntityPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CMonitorEntityFilter(CMonitorEntityIterator *pBaseIterator, CMonitorEntityPredict *pPredict, bool continueResult=false)
		:CMonitorEntityIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CMonitorEntityFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CMonitorEntity
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMonitorEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMonitorEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityLinkIterator�������������ʵ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityLinkIterator: public CMonitorEntityIterator
{
private:
	CMonitorEntityIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CMonitorEntityLinkIterator(CMonitorEntityIterator *pBaseIterator1,CMonitorEntityIterator *pBaseIterator2)
		:CMonitorEntityIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CMonitorEntityLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CMonitorEntity
	///@return	��һ����������CMonitorEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMonitorEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMonitorEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CEventEntitySingleIterator�����෵��һ���¼�ʵ���ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntitySingleIterator: public CEventEntityIterator
{
private:
	CEventEntity *m_pResult;
	bool m_finished;
public:
	///���췽��
	///@param	pFactory	Ҫʹ�õĶ��󹤳�
	///@param	pResult	Ҫ���صĵ������
	CEventEntitySingleIterator(CEventEntityFactory *pFactory,CEventEntity *pResult)
		:CEventEntityIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///���췽��
	~CEventEntitySingleIterator(void)
	{
	}

	///Ѱ����һ������������CEventEntity
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CEventEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pEventEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityPredict���ж�һ���¼�ʵ���Ƿ����������ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityPredict
{
public:
	///�ж��Ƿ�Ϸ�
	///@param	pEventEntity	Ҫ���жϵ��¼�ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CEventEntity *pEventEntity)=0;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityAndPredict�Ƕ������¼�ʵ��ν�ʵ���ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityAndPredict : public CEventEntityPredict
{
private:
	CEventEntityPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CEventEntityAndPredict(CEventEntityPredict *p1, CEventEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CEventEntityAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pEventEntity	Ҫ���жϵ��¼�ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CEventEntity *pEventEntity)
	{
		return m_p1->isValid(pEventEntity) && m_p2->isValid(pEventEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityOrPredict�Ƕ������¼�ʵ��ν�ʵĻ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityOrPredict : public CEventEntityPredict
{
private:
	CEventEntityPredict *m_p1,*m_p2;
public:
	///���췽��
	///@param	p1	��һ��ν��
	///@param	p2	�ڶ���ν��
	CEventEntityOrPredict(CEventEntityPredict *p1, CEventEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///��������
	~CEventEntityOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pEventEntity	Ҫ���жϵ��¼�ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CEventEntity *pEventEntity)
	{
		return m_p1->isValid(pEventEntity) || m_p2->isValid(pEventEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityNotPredict�Ƕ�һ���¼�ʵ��ν�ʵķ�ν��
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityNotPredict : public CEventEntityPredict
{
private:
	CEventEntityPredict *m_predict;
public:
	///���췽��
	///@param	predict	����ν��
	CEventEntityNotPredict(CEventEntityPredict *predict)
	{
		m_predict=predict;
	}
	
	///��������
	~CEventEntityNotPredict(void)
	{
		delete m_predict;
	}

	///�ж��Ƿ�Ϸ�
	///@param	pEventEntity	Ҫ���жϵ��¼�ʵ��
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	virtual bool isValid(CEventEntity *pEventEntity)
	{
		return !m_predict->isValid(pEventEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityFilter��һ�������е��¼�ʵ��ö�������й��˵�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityFilter: public CEventEntityIterator
{
private:
	CEventEntityIterator *m_baseIterator;
	CEventEntityPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///���캯��
	///@param	pBaseIterator	������ö����
	///@param	pPredict	�ж��Ƿ�Ϸ���ν��
	///@param	continueResult	true��ʾ�������������ǻ���ö�������������������false��ʾ�������
	CEventEntityFilter(CEventEntityIterator *pBaseIterator, CEventEntityPredict *pPredict, bool continueResult=false)
		:CEventEntityIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///��������
	~CEventEntityFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///Ѱ����һ������������CEventEntity
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CEventEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pEventEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityLinkIterator�����������¼�ʵ��ö������ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityLinkIterator: public CEventEntityIterator
{
private:
	CEventEntityIterator *m_baseIterator[2];
	int m_id;
public:
	///���캯��
	///@param	pBaseIterator1	������ö����1
	///@param	pBaseIterator2	������ö����2
	CEventEntityLinkIterator(CEventEntityIterator *pBaseIterator1,CEventEntityIterator *pBaseIterator2)
		:CEventEntityIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///��������
	~CEventEntityLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///Ѱ����һ������������CEventEntity
	///@return	��һ����������CEventEntity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CEventEntity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pEventEntity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


#endif
