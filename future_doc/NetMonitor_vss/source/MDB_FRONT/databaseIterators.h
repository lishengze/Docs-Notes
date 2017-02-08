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
///CSysInvalidateOrderIteratorByActionTime��һ������Ч����ʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderIteratorByActionTime: public CSysInvalidateOrderIterator
{
	friend class CSysInvalidateOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysInvalidateOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysInvalidateOrder *pSysInvalidateOrder);

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
	CWriteableSysInvalidateOrder m_compareObject;
	
	static CMemoryStack<CSysInvalidateOrderIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysInvalidateOrderIteratorByActionTime(CSysInvalidateOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysInvalidateOrderIteratorByActionTime *alloc(CSysInvalidateOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysInvalidateOrderIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysInvalidateOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysInvalidateOrderIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysInvalidateOrder��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysInvalidateOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInvalidateOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusIteratorByActionTime��һ���Ա���״̬ʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusIteratorByActionTime: public CSysOrderStatusIterator
{
	friend class CSysOrderStatusFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysOrderStatus		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysOrderStatus *pSysOrderStatus);

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
	CWriteableSysOrderStatus m_compareObject;
	
	static CMemoryStack<CSysOrderStatusIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysOrderStatusIteratorByActionTime(CSysOrderStatusFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysOrderStatusIteratorByActionTime *alloc(CSysOrderStatusFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysOrderStatusIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysOrderStatusFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysOrderStatusIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysOrderStatus��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysOrderStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOrderStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderIteratorByActionTime��һ���Ա����ɽ�ʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderIteratorByActionTime: public CSysBargainOrderIterator
{
	friend class CSysBargainOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysBargainOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysBargainOrder *pSysBargainOrder);

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
	CWriteableSysBargainOrder m_compareObject;
	
	static CMemoryStack<CSysBargainOrderIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysBargainOrderIteratorByActionTime(CSysBargainOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysBargainOrderIteratorByActionTime *alloc(CSysBargainOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysBargainOrderIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysBargainOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysBargainOrderIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysBargainOrder��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysBargainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysBargainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyIteratorByAll��һ���Ժ�Լ��������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyIteratorByAll: public CSysInstPropertyIterator
{
	friend class CSysInstPropertyFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysInstProperty		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysInstProperty *pSysInstProperty);

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
	CWriteableSysInstProperty m_compareObject;
	
	static CMemoryStack<CSysInstPropertyIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysInstPropertyIteratorByAll(CSysInstPropertyFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysInstPropertyIteratorByAll *alloc(CSysInstPropertyFactory *pFactory
		);

	///���췽��
	CSysInstPropertyIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysInstPropertyFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysInstPropertyIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysInstProperty��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysInstProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstProperty * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateIteratorByAll��һ���Ժ�Լ��֤����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateIteratorByAll: public CSysMarginRateIterator
{
	friend class CSysMarginRateFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMarginRate		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMarginRate *pSysMarginRate);

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
	CWriteableSysMarginRate m_compareObject;
	
	static CMemoryStack<CSysMarginRateIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMarginRateIteratorByAll(CSysMarginRateFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMarginRateIteratorByAll *alloc(CSysMarginRateFactory *pFactory
		);

	///���췽��
	CSysMarginRateIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMarginRateFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMarginRateIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMarginRate��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRate * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitIteratorByAll��һ���Ժ�Լ�ǵ�ͣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitIteratorByAll: public CSysPriceLimitIterator
{
	friend class CSysPriceLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysPriceLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysPriceLimit *pSysPriceLimit);

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
	CWriteableSysPriceLimit m_compareObject;
	
	static CMemoryStack<CSysPriceLimitIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysPriceLimitIteratorByAll(CSysPriceLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysPriceLimitIteratorByAll *alloc(CSysPriceLimitFactory *pFactory
		);

	///���췽��
	CSysPriceLimitIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysPriceLimitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPriceLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysPriceLimit��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysPriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitIteratorByAll��һ���Ի�Ա�޲�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitIteratorByAll: public CSysPartPosiLimitIterator
{
	friend class CSysPartPosiLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysPartPosiLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysPartPosiLimit *pSysPartPosiLimit);

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
	CWriteableSysPartPosiLimit m_compareObject;
	
	static CMemoryStack<CSysPartPosiLimitIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysPartPosiLimitIteratorByAll(CSysPartPosiLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysPartPosiLimitIteratorByAll *alloc(CSysPartPosiLimitFactory *pFactory
		);

	///���췽��
	CSysPartPosiLimitIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysPartPosiLimitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPartPosiLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysPartPosiLimit��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitIteratorByAll��һ���Կͻ��޲�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitIteratorByAll: public CSysClientPosiLimitIterator
{
	friend class CSysClientPosiLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysClientPosiLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysClientPosiLimit *pSysClientPosiLimit);

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
	CWriteableSysClientPosiLimit m_compareObject;
	
	static CMemoryStack<CSysClientPosiLimitIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysClientPosiLimitIteratorByAll(CSysClientPosiLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysClientPosiLimitIteratorByAll *alloc(CSysClientPosiLimitFactory *pFactory
		);

	///���췽��
	CSysClientPosiLimitIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysClientPosiLimitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientPosiLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysClientPosiLimit��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitIteratorByAll��һ��������ͻ��޲�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitIteratorByAll: public CSysSpecialPosiLimitIterator
{
	friend class CSysSpecialPosiLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysSpecialPosiLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysSpecialPosiLimit *pSysSpecialPosiLimit);

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
	CWriteableSysSpecialPosiLimit m_compareObject;
	
	static CMemoryStack<CSysSpecialPosiLimitIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysSpecialPosiLimitIteratorByAll(CSysSpecialPosiLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysSpecialPosiLimitIteratorByAll *alloc(CSysSpecialPosiLimitFactory *pFactory
		);

	///���췽��
	CSysSpecialPosiLimitIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysSpecialPosiLimitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysSpecialPosiLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysSpecialPosiLimit��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgIteratorByActionTime��һ�����˻�������ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgIteratorByActionTime: public CSysTransactionChgIterator
{
	friend class CSysTransactionChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysTransactionChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysTransactionChg *pSysTransactionChg);

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
	CWriteableSysTransactionChg m_compareObject;
	
	static CMemoryStack<CSysTransactionChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysTransactionChgIteratorByActionTime(CSysTransactionChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysTransactionChgIteratorByActionTime *alloc(CSysTransactionChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysTransactionChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysTransactionChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysTransactionChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysTransactionChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysTransactionChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTransactionChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgIteratorByActionTime��һ���Կͻ����ݱ䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgIteratorByActionTime: public CSysClientChgIterator
{
	friend class CSysClientChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysClientChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysClientChg *pSysClientChg);

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
	CWriteableSysClientChg m_compareObject;
	
	static CMemoryStack<CSysClientChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysClientChgIteratorByActionTime(CSysClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysClientChgIteratorByActionTime *alloc(CSysClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysClientChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysClientChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgIteratorByActionTime��һ���Ի�Ա�ͻ����ձ䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgIteratorByActionTime: public CSysPartClientChgIterator
{
	friend class CSysPartClientChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysPartClientChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysPartClientChg *pSysPartClientChg);

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
	CWriteableSysPartClientChg m_compareObject;
	
	static CMemoryStack<CSysPartClientChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysPartClientChgIteratorByActionTime(CSysPartClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysPartClientChgIteratorByActionTime *alloc(CSysPartClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysPartClientChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysPartClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPartClientChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysPartClientChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysPartClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartClientChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgIteratorByActionTime��һ�����޲����ݱ䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgIteratorByActionTime: public CSysPosiLimitChgIterator
{
	friend class CSysPosiLimitChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysPosiLimitChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysPosiLimitChg *pSysPosiLimitChg);

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
	CWriteableSysPosiLimitChg m_compareObject;
	
	static CMemoryStack<CSysPosiLimitChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysPosiLimitChgIteratorByActionTime(CSysPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysPosiLimitChgIteratorByActionTime *alloc(CSysPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysPosiLimitChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPosiLimitChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysPosiLimitChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgIteratorByActionTime��һ�����޲����ݱ䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgIteratorByActionTime: public CSysClientPosiLimitChgIterator
{
	friend class CSysClientPosiLimitChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysClientPosiLimitChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysClientPosiLimitChg *pSysClientPosiLimitChg);

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
	CWriteableSysClientPosiLimitChg m_compareObject;
	
	static CMemoryStack<CSysClientPosiLimitChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysClientPosiLimitChgIteratorByActionTime(CSysClientPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysClientPosiLimitChgIteratorByActionTime *alloc(CSysClientPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysClientPosiLimitChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysClientPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientPosiLimitChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysClientPosiLimitChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysClientPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgIteratorByActionTime��һ�����޲����ݱ䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgIteratorByActionTime: public CSysSpecPosiLimitChgIterator
{
	friend class CSysSpecPosiLimitChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysSpecPosiLimitChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);

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
	CWriteableSysSpecPosiLimitChg m_compareObject;
	
	static CMemoryStack<CSysSpecPosiLimitChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysSpecPosiLimitChgIteratorByActionTime(CSysSpecPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysSpecPosiLimitChgIteratorByActionTime *alloc(CSysSpecPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysSpecPosiLimitChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysSpecPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysSpecPosiLimitChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysSpecPosiLimitChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysSpecPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgIteratorByActionTime��һ���Ա�ֵ��ȱ䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgIteratorByActionTime: public CSysHedgeDetailChgIterator
{
	friend class CSysHedgeDetailChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysHedgeDetailChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysHedgeDetailChg *pSysHedgeDetailChg);

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
	CWriteableSysHedgeDetailChg m_compareObject;
	
	static CMemoryStack<CSysHedgeDetailChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysHedgeDetailChgIteratorByActionTime(CSysHedgeDetailChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysHedgeDetailChgIteratorByActionTime *alloc(CSysHedgeDetailChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysHedgeDetailChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysHedgeDetailChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysHedgeDetailChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysHedgeDetailChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysHedgeDetailChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgIteratorByActionTime��һ���Ի�Ա�䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgIteratorByActionTime: public CSysParticipantChgIterator
{
	friend class CSysParticipantChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysParticipantChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysParticipantChg *pSysParticipantChg);

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
	CWriteableSysParticipantChg m_compareObject;
	
	static CMemoryStack<CSysParticipantChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysParticipantChgIteratorByActionTime(CSysParticipantChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysParticipantChgIteratorByActionTime *alloc(CSysParticipantChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysParticipantChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysParticipantChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysParticipantChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysParticipantChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysParticipantChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgIteratorByActionTime��һ���Ա�֤���ʱ䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgIteratorByActionTime: public CSysMarginRateChgIterator
{
	friend class CSysMarginRateChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMarginRateChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMarginRateChg *pSysMarginRateChg);

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
	CWriteableSysMarginRateChg m_compareObject;
	
	static CMemoryStack<CSysMarginRateChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysMarginRateChgIteratorByActionTime(CSysMarginRateChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysMarginRateChgIteratorByActionTime *alloc(CSysMarginRateChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysMarginRateChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysMarginRateChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMarginRateChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMarginRateChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysMarginRateChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRateChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgIteratorByActionTime��һ����IP��ַ�䶯��ѯʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgIteratorByActionTime: public CSysUserIpChgIterator
{
	friend class CSysUserIpChgFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysUserIpChg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysUserIpChg *pSysUserIpChg);

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
	CWriteableSysUserIpChg m_compareObject;
	
	static CMemoryStack<CSysUserIpChgIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	CSysUserIpChgIteratorByActionTime(CSysUserIpChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	static CSysUserIpChgIteratorByActionTime *alloc(CSysUserIpChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///���췽��
	CSysUserIpChgIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ActionTime	
	void init(CSysUserIpChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserIpChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysUserIpChg��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysUserIpChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserIpChg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeIteratorByAll��һ���Ի�Ա������Ϣʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeIteratorByAll: public CSysPartTradeIterator
{
	friend class CSysPartTradeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysPartTrade		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysPartTrade *pSysPartTrade);

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
	CWriteableSysPartTrade m_compareObject;
	
	static CMemoryStack<CSysPartTradeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysPartTradeIteratorByAll(CSysPartTradeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysPartTradeIteratorByAll *alloc(CSysPartTradeFactory *pFactory
		);

	///���췽��
	CSysPartTradeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysPartTradeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPartTradeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysPartTrade��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysPartTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartTrade * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorByIDType��һ���Զ���״ָ̬��ʹ��ByIDType��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorByIDType: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbObjectAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorByIDType> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbObjectAttrIteratorByIDType(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbObjectAttrIteratorByIDType *alloc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbObjectAttrIteratorByIDType(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbObjectAttrIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbObjectAttr��������startFindByIDType�Ժ�endFindByIDType֮ǰ����
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorByDsc��һ���Զ���״ָ̬��ʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorByDsc: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbObjectAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbObjectAttrIteratorByDsc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbObjectAttrIteratorByDsc *alloc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbObjectAttrIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbObjectAttrIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbObjectAttr��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorBytheAll��һ���Զ���״ָ̬��ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorBytheAll: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbObjectAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbObjectAttrIteratorBytheAll(CSysMdbObjectAttrFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbObjectAttrIteratorBytheAll *alloc(CSysMdbObjectAttrFactory *pFactory
		);

	///���췽��
	CSysMdbObjectAttrIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbObjectAttrFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbObjectAttrIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbObjectAttr��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorByDataDelete��һ���Զ���״ָ̬��ʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorByDataDelete: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbObjectAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbObjectAttrIteratorByDataDelete(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbObjectAttrIteratorByDataDelete *alloc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbObjectAttrIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbObjectAttrIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbObjectAttr��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIteratorByAll��һ������־�ļ����ݴ�����Ϣʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIteratorByAll: public CSysMdbSyslogInfoIterator
{
	friend class CSysMdbSyslogInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbSyslogInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

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
	CWriteableSysMdbSyslogInfo m_compareObject;
	
	static CMemoryStack<CSysMdbSyslogInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	AttrType	
	CSysMdbSyslogInfoIteratorByAll(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType)
	{
		init(pFactory,ObjectID,AttrType);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	AttrType	
	static CSysMdbSyslogInfoIteratorByAll *alloc(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType);

	///���췽��
	CSysMdbSyslogInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	AttrType	
	void init(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbSyslogInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbSyslogInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysMdbSyslogInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIteratorBytheAll��һ������־�ļ����ݴ�����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIteratorBytheAll: public CSysMdbSyslogInfoIterator
{
	friend class CSysMdbSyslogInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbSyslogInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

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
	CWriteableSysMdbSyslogInfo m_compareObject;
	
	static CMemoryStack<CSysMdbSyslogInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbSyslogInfoIteratorBytheAll(CSysMdbSyslogInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbSyslogInfoIteratorBytheAll *alloc(CSysMdbSyslogInfoFactory *pFactory
		);

	///���췽��
	CSysMdbSyslogInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbSyslogInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbSyslogInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbSyslogInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbSyslogInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIteratorByDataDelete��һ������־�ļ����ݴ�����Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIteratorByDataDelete: public CSysMdbSyslogInfoIterator
{
	friend class CSysMdbSyslogInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbSyslogInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

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
	CWriteableSysMdbSyslogInfo m_compareObject;
	
	static CMemoryStack<CSysMdbSyslogInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	AttrType	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbSyslogInfoIteratorByDataDelete(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,AttrType,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	AttrType	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbSyslogInfoIteratorByDataDelete *alloc(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbSyslogInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	AttrType	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbSyslogInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbSyslogInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbSyslogInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIteratorByHostName��һ�����û���Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIteratorByHostName: public CSysUserInfoIterator
{
	friend class CSysUserInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysUserInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysUserInfo *pSysUserInfo);

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
	CWriteableSysUserInfo m_compareObject;
	
	static CMemoryStack<CSysUserInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	CSysUserInfoIteratorByHostName(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	static CSysUserInfoIteratorByHostName *alloc(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysUserInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	void init(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysUserInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIteratorBytheAll��һ�����û���Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIteratorBytheAll: public CSysUserInfoIterator
{
	friend class CSysUserInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysUserInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysUserInfo *pSysUserInfo);

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
	CWriteableSysUserInfo m_compareObject;
	
	static CMemoryStack<CSysUserInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysUserInfoIteratorBytheAll(CSysUserInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysUserInfoIteratorBytheAll *alloc(CSysUserInfoFactory *pFactory
		);

	///���췽��
	CSysUserInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysUserInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysUserInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIteratorByDsc��һ�����û���Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIteratorByDsc: public CSysUserInfoIterator
{
	friend class CSysUserInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysUserInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysUserInfo *pSysUserInfo);

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
	CWriteableSysUserInfo m_compareObject;
	
	static CMemoryStack<CSysUserInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	CSysUserInfoIteratorByDsc(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	static CSysUserInfoIteratorByDsc *alloc(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///���췽��
	CSysUserInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	void init(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysUserInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIteratorByHostName��һ���������û���Ϣ��ѯӦ��ʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIteratorByHostName: public CSysOnlineUserInfoIterator
{
	friend class CSysOnlineUserInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysOnlineUserInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysOnlineUserInfo *pSysOnlineUserInfo);

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
	CWriteableSysOnlineUserInfo m_compareObject;
	
	static CMemoryStack<CSysOnlineUserInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	CSysOnlineUserInfoIteratorByHostName(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	static CSysOnlineUserInfoIteratorByHostName *alloc(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysOnlineUserInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	void init(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysOnlineUserInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysOnlineUserInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysOnlineUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIteratorBytheAll��һ���������û���Ϣ��ѯӦ��ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIteratorBytheAll: public CSysOnlineUserInfoIterator
{
	friend class CSysOnlineUserInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysOnlineUserInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysOnlineUserInfo *pSysOnlineUserInfo);

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
	CWriteableSysOnlineUserInfo m_compareObject;
	
	static CMemoryStack<CSysOnlineUserInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysOnlineUserInfoIteratorBytheAll(CSysOnlineUserInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysOnlineUserInfoIteratorBytheAll *alloc(CSysOnlineUserInfoFactory *pFactory
		);

	///���췽��
	CSysOnlineUserInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysOnlineUserInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysOnlineUserInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysOnlineUserInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysOnlineUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIteratorByDsc��һ���������û���Ϣ��ѯӦ��ʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIteratorByDsc: public CSysOnlineUserInfoIterator
{
	friend class CSysOnlineUserInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysOnlineUserInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysOnlineUserInfo *pSysOnlineUserInfo);

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
	CWriteableSysOnlineUserInfo m_compareObject;
	
	static CMemoryStack<CSysOnlineUserInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	CSysOnlineUserInfoIteratorByDsc(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	static CSysOnlineUserInfoIteratorByDsc *alloc(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///���췽��
	CSysOnlineUserInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	void init(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysOnlineUserInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysOnlineUserInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysOnlineUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorByTime��һ���Ը澯�¼���ѯӦ��ʹ��ByTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorByTime: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysWarningEvent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorByTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	OccurTime	
	CSysWarningEventIteratorByTime(CSysWarningEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime)
	{
		init(pFactory,MonDate,OccurTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	OccurTime	
	static CSysWarningEventIteratorByTime *alloc(CSysWarningEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///���췽��
	CSysWarningEventIteratorByTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	OccurTime	
	void init(CSysWarningEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysWarningEventIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysWarningEvent��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorByAll��һ���Ը澯�¼���ѯӦ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorByAll: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysWarningEvent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysWarningEventIteratorByAll(CSysWarningEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysWarningEventIteratorByAll *alloc(CSysWarningEventFactory *pFactory
		);

	///���췽��
	CSysWarningEventIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysWarningEventFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysWarningEventIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysWarningEvent��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorByEvendIDs��һ���Ը澯�¼���ѯӦ��ʹ��ByEvendIDs��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorByEvendIDs: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysWarningEvent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorByEvendIDs> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EvendID	
	CSysWarningEventIteratorByEvendIDs(CSysWarningEventFactory *pFactory
		,const CReadOnlyVolumeType& EvendID)
	{
		init(pFactory,EvendID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EvendID	
	static CSysWarningEventIteratorByEvendIDs *alloc(CSysWarningEventFactory *pFactory
		,const CReadOnlyVolumeType& EvendID);

	///���췽��
	CSysWarningEventIteratorByEvendIDs(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EvendID	
	void init(CSysWarningEventFactory *pFactory
		,const CReadOnlyVolumeType& EvendID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysWarningEventIteratorByEvendIDs(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysWarningEvent��������startFindByEvendIDs�Ժ�endFindByEvendIDs֮ǰ����
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByEvendIDs ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pByEvendIDs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorBytheAll��һ���Ը澯�¼���ѯӦ��ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorBytheAll: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysWarningEvent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysWarningEventIteratorBytheAll(CSysWarningEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysWarningEventIteratorBytheAll *alloc(CSysWarningEventFactory *pFactory
		);

	///���췽��
	CSysWarningEventIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysWarningEventFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysWarningEventIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysWarningEvent��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryIteratorByTime��һ���Ը澯��ϸӦ��ʹ��ByTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryIteratorByTime: public CSysWarningQueryIterator
{
	friend class CSysWarningQueryFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysWarningQuery		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysWarningQuery *pSysWarningQuery);

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
	CWriteableSysWarningQuery m_compareObject;
	
	static CMemoryStack<CSysWarningQueryIteratorByTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	CSysWarningQueryIteratorByTime(CSysWarningQueryFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	static CSysWarningQueryIteratorByTime *alloc(CSysWarningQueryFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysWarningQueryIteratorByTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysWarningQueryFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysWarningQueryIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysWarningQuery��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CSysWarningQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventIteratorByTime��һ������־�¼���ѯӦ��ʹ��ByTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIteratorByTime: public CSyslogEventIterator
{
	friend class CSyslogEventFactory;
private:
	///���˶����Ƿ���������
	///@param	pSyslogEvent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSyslogEvent *pSyslogEvent);

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
	CWriteableSyslogEvent m_compareObject;
	
	static CMemoryStack<CSyslogEventIteratorByTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	OccurTime	
	CSyslogEventIteratorByTime(CSyslogEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime)
	{
		init(pFactory,MonDate,OccurTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	OccurTime	
	static CSyslogEventIteratorByTime *alloc(CSyslogEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///���췽��
	CSyslogEventIteratorByTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	OccurTime	
	void init(CSyslogEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSyslogEventIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSyslogEvent��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CSyslogEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSyslogEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSyslogEvent * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSyslogEventIteratorBytheAll��һ������־�¼���ѯӦ��ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIteratorBytheAll: public CSyslogEventIterator
{
	friend class CSyslogEventFactory;
private:
	///���˶����Ƿ���������
	///@param	pSyslogEvent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSyslogEvent *pSyslogEvent);

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
	CWriteableSyslogEvent m_compareObject;
	
	static CMemoryStack<CSyslogEventIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSyslogEventIteratorBytheAll(CSyslogEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSyslogEventIteratorBytheAll *alloc(CSyslogEventFactory *pFactory
		);

	///���췽��
	CSyslogEventIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSyslogEventFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSyslogEventIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSyslogEvent��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSyslogEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSyslogEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSyslogEvent * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSyslogEventIteratorByAll��һ������־�¼���ѯӦ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIteratorByAll: public CSyslogEventIterator
{
	friend class CSyslogEventFactory;
private:
	///���˶����Ƿ���������
	///@param	pSyslogEvent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSyslogEvent *pSyslogEvent);

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
	CWriteableSyslogEvent m_compareObject;
	
	static CMemoryStack<CSyslogEventIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSyslogEventIteratorByAll(CSyslogEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSyslogEventIteratorByAll *alloc(CSyslogEventFactory *pFactory
		);

	///���췽��
	CSyslogEventIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSyslogEventFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSyslogEventIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSyslogEvent��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSyslogEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSyslogEvent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSyslogEvent * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIteratorByTime��һ�����¼�������ѯʹ��ByTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIteratorByTime: public CSysEventDescripIterator
{
	friend class CSysEventDescripFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysEventDescrip		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysEventDescrip *pSysEventDescrip);

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
	CWriteableSysEventDescrip m_compareObject;
	
	static CMemoryStack<CSysEventDescripIteratorByTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	CSysEventDescripIteratorByTime(CSysEventDescripFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	static CSysEventDescripIteratorByTime *alloc(CSysEventDescripFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysEventDescripIteratorByTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysEventDescripFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysEventDescripIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysEventDescrip��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CSysEventDescrip������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysEventDescrip *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIteratorBytheAll��һ�����¼�������ѯʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIteratorBytheAll: public CSysEventDescripIterator
{
	friend class CSysEventDescripFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysEventDescrip		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysEventDescrip *pSysEventDescrip);

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
	CWriteableSysEventDescrip m_compareObject;
	
	static CMemoryStack<CSysEventDescripIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysEventDescripIteratorBytheAll(CSysEventDescripFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysEventDescripIteratorBytheAll *alloc(CSysEventDescripFactory *pFactory
		);

	///���췽��
	CSysEventDescripIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysEventDescripFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysEventDescripIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysEventDescrip��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysEventDescrip������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysEventDescrip *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIteratorByAll��һ�����¼�������ѯʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIteratorByAll: public CSysEventDescripIterator
{
	friend class CSysEventDescripFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysEventDescrip		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysEventDescrip *pSysEventDescrip);

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
	CWriteableSysEventDescrip m_compareObject;
	
	static CMemoryStack<CSysEventDescripIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysEventDescripIteratorByAll(CSysEventDescripFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysEventDescripIteratorByAll *alloc(CSysEventDescripFactory *pFactory
		);

	///���췽��
	CSysEventDescripIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysEventDescripFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysEventDescripIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysEventDescrip��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysEventDescrip������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysEventDescrip *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonIteratorByHostName��һ��������������Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonIteratorByHostName: public CRspQryHostEnvCommonIterator
{
	friend class CRspQryHostEnvCommonFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvCommon		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvCommon *pRspQryHostEnvCommon);

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
	CWriteableRspQryHostEnvCommon m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvCommonIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CRspQryHostEnvCommonIteratorByHostName(CRspQryHostEnvCommonFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CRspQryHostEnvCommonIteratorByHostName *alloc(CRspQryHostEnvCommonFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///���췽��
	CRspQryHostEnvCommonIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CRspQryHostEnvCommonFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvCommonIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvCommon��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CRspQryHostEnvCommon������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonIteratorBytheAll��һ��������������Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonIteratorBytheAll: public CRspQryHostEnvCommonIterator
{
	friend class CRspQryHostEnvCommonFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvCommon		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvCommon *pRspQryHostEnvCommon);

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
	CWriteableRspQryHostEnvCommon m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvCommonIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CRspQryHostEnvCommonIteratorBytheAll(CRspQryHostEnvCommonFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CRspQryHostEnvCommonIteratorBytheAll *alloc(CRspQryHostEnvCommonFactory *pFactory
		);

	///���췽��
	CRspQryHostEnvCommonIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CRspQryHostEnvCommonFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvCommonIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvCommon��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CRspQryHostEnvCommon������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanIteratorByHostName��һ������������Lan��Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanIteratorByHostName: public CRspQryHostEnvLanIterator
{
	friend class CRspQryHostEnvLanFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvLan		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvLan *pRspQryHostEnvLan);

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
	CWriteableRspQryHostEnvLan m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CRspQryHostEnvLanIteratorByHostName(CRspQryHostEnvLanFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CRspQryHostEnvLanIteratorByHostName *alloc(CRspQryHostEnvLanFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///���췽��
	CRspQryHostEnvLanIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CRspQryHostEnvLanFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvLanIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvLan��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CRspQryHostEnvLan������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanIteratorBytheAll��һ������������Lan��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanIteratorBytheAll: public CRspQryHostEnvLanIterator
{
	friend class CRspQryHostEnvLanFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvLan		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvLan *pRspQryHostEnvLan);

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
	CWriteableRspQryHostEnvLan m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CRspQryHostEnvLanIteratorBytheAll(CRspQryHostEnvLanFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CRspQryHostEnvLanIteratorBytheAll *alloc(CRspQryHostEnvLanFactory *pFactory
		);

	///���췽��
	CRspQryHostEnvLanIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CRspQryHostEnvLanFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvLanIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvLan��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CRspQryHostEnvLan������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageIteratorByHostName��һ�������������洢�豸��Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageIteratorByHostName: public CRspQryHostEnvStorageIterator
{
	friend class CRspQryHostEnvStorageFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvStorage		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvStorage *pRspQryHostEnvStorage);

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
	CWriteableRspQryHostEnvStorage m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvStorageIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CRspQryHostEnvStorageIteratorByHostName(CRspQryHostEnvStorageFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CRspQryHostEnvStorageIteratorByHostName *alloc(CRspQryHostEnvStorageFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///���췽��
	CRspQryHostEnvStorageIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CRspQryHostEnvStorageFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvStorageIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvStorage��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CRspQryHostEnvStorage������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageIteratorBytheAll��һ�������������洢�豸��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageIteratorBytheAll: public CRspQryHostEnvStorageIterator
{
	friend class CRspQryHostEnvStorageFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvStorage		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvStorage *pRspQryHostEnvStorage);

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
	CWriteableRspQryHostEnvStorage m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvStorageIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CRspQryHostEnvStorageIteratorBytheAll(CRspQryHostEnvStorageFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CRspQryHostEnvStorageIteratorBytheAll *alloc(CRspQryHostEnvStorageFactory *pFactory
		);

	///���췽��
	CRspQryHostEnvStorageIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CRspQryHostEnvStorageFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvStorageIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvStorage��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CRspQryHostEnvStorage������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOIteratorByHostName��һ������������IO�豸��Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOIteratorByHostName: public CRspQryHostEnvIOIterator
{
	friend class CRspQryHostEnvIOFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvIO		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvIO *pRspQryHostEnvIO);

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
	CWriteableRspQryHostEnvIO m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvIOIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CRspQryHostEnvIOIteratorByHostName(CRspQryHostEnvIOFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CRspQryHostEnvIOIteratorByHostName *alloc(CRspQryHostEnvIOFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///���췽��
	CRspQryHostEnvIOIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CRspQryHostEnvIOFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvIOIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvIO��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CRspQryHostEnvIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOIteratorBytheAll��һ������������IO�豸��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOIteratorBytheAll: public CRspQryHostEnvIOIterator
{
	friend class CRspQryHostEnvIOFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvIO		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvIO *pRspQryHostEnvIO);

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
	CWriteableRspQryHostEnvIO m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvIOIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CRspQryHostEnvIOIteratorBytheAll(CRspQryHostEnvIOFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CRspQryHostEnvIOIteratorBytheAll *alloc(CRspQryHostEnvIOFactory *pFactory
		);

	///���췽��
	CRspQryHostEnvIOIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CRspQryHostEnvIOFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvIOIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvIO��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CRspQryHostEnvIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSIteratorByHostName��һ�������������ļ�ϵͳ��Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSIteratorByHostName: public CRspQryHostEnvFSIterator
{
	friend class CRspQryHostEnvFSFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvFS		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvFS *pRspQryHostEnvFS);

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
	CWriteableRspQryHostEnvFS m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvFSIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CRspQryHostEnvFSIteratorByHostName(CRspQryHostEnvFSFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CRspQryHostEnvFSIteratorByHostName *alloc(CRspQryHostEnvFSFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///���췽��
	CRspQryHostEnvFSIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CRspQryHostEnvFSFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvFSIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvFS��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CRspQryHostEnvFS������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSIteratorBytheAll��һ�������������ļ�ϵͳ��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSIteratorBytheAll: public CRspQryHostEnvFSIterator
{
	friend class CRspQryHostEnvFSFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvFS		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvFS *pRspQryHostEnvFS);

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
	CWriteableRspQryHostEnvFS m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvFSIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CRspQryHostEnvFSIteratorBytheAll(CRspQryHostEnvFSFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CRspQryHostEnvFSIteratorBytheAll *alloc(CRspQryHostEnvFSFactory *pFactory
		);

	///���췽��
	CRspQryHostEnvFSIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CRspQryHostEnvFSFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvFSIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvFS��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CRspQryHostEnvFS������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapIteratorByHostName��һ����������������������Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapIteratorByHostName: public CRspQryHostEnvSwapIterator
{
	friend class CRspQryHostEnvSwapFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvSwap		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvSwap *pRspQryHostEnvSwap);

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
	CWriteableRspQryHostEnvSwap m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvSwapIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CRspQryHostEnvSwapIteratorByHostName(CRspQryHostEnvSwapFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CRspQryHostEnvSwapIteratorByHostName *alloc(CRspQryHostEnvSwapFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///���췽��
	CRspQryHostEnvSwapIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CRspQryHostEnvSwapFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvSwapIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvSwap��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CRspQryHostEnvSwap������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapIteratorBytheAll��һ����������������������Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapIteratorBytheAll: public CRspQryHostEnvSwapIterator
{
	friend class CRspQryHostEnvSwapFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvSwap		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvSwap *pRspQryHostEnvSwap);

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
	CWriteableRspQryHostEnvSwap m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvSwapIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CRspQryHostEnvSwapIteratorBytheAll(CRspQryHostEnvSwapFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CRspQryHostEnvSwapIteratorBytheAll *alloc(CRspQryHostEnvSwapFactory *pFactory
		);

	///���췽��
	CRspQryHostEnvSwapIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CRspQryHostEnvSwapFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvSwapIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvSwap��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CRspQryHostEnvSwap������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgIteratorByHostName��һ����������������������Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgIteratorByHostName: public CRspQryHostEnvLanCfgIterator
{
	friend class CRspQryHostEnvLanCfgFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvLanCfg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);

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
	CWriteableRspQryHostEnvLanCfg m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanCfgIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CRspQryHostEnvLanCfgIteratorByHostName(CRspQryHostEnvLanCfgFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CRspQryHostEnvLanCfgIteratorByHostName *alloc(CRspQryHostEnvLanCfgFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///���췽��
	CRspQryHostEnvLanCfgIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CRspQryHostEnvLanCfgFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvLanCfgIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvLanCfg��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CRspQryHostEnvLanCfg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgIteratorBytheAll��һ����������������������Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgIteratorBytheAll: public CRspQryHostEnvLanCfgIterator
{
	friend class CRspQryHostEnvLanCfgFactory;
private:
	///���˶����Ƿ���������
	///@param	pRspQryHostEnvLanCfg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);

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
	CWriteableRspQryHostEnvLanCfg m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanCfgIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CRspQryHostEnvLanCfgIteratorBytheAll(CRspQryHostEnvLanCfgFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CRspQryHostEnvLanCfgIteratorBytheAll *alloc(CRspQryHostEnvLanCfgFactory *pFactory
		);

	///���췽��
	CRspQryHostEnvLanCfgIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CRspQryHostEnvLanCfgFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvLanCfgIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRspQryHostEnvLanCfg��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CRspQryHostEnvLanCfg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorByHostName��һ����CPU��Դʹ����Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorByHostName: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopCpuInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopCpuInfoIteratorByHostName(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopCpuInfoIteratorByHostName *alloc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbTopCpuInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopCpuInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopCpuInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorByDsc��һ����CPU��Դʹ����Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorByDsc: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopCpuInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CSysMdbTopCpuInfoIteratorByDsc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CSysMdbTopCpuInfoIteratorByDsc *alloc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///���췽��
	CSysMdbTopCpuInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopCpuInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopCpuInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorBytheAll��һ����CPU��Դʹ����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorBytheAll: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopCpuInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbTopCpuInfoIteratorBytheAll(CSysMdbTopCpuInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbTopCpuInfoIteratorBytheAll *alloc(CSysMdbTopCpuInfoFactory *pFactory
		);

	///���췽��
	CSysMdbTopCpuInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbTopCpuInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopCpuInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopCpuInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorByDataDelete��һ����CPU��Դʹ����Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorByDataDelete: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopCpuInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopCpuInfoIteratorByDataDelete(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopCpuInfoIteratorByDataDelete *alloc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbTopCpuInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopCpuInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopCpuInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorByHostName��һ�����ڴ���Դʹ����Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorByHostName: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopMemInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopMemInfoIteratorByHostName(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopMemInfoIteratorByHostName *alloc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbTopMemInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopMemInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopMemInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorByDsc��һ�����ڴ���Դʹ����Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorByDsc: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopMemInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CSysMdbTopMemInfoIteratorByDsc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CSysMdbTopMemInfoIteratorByDsc *alloc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///���췽��
	CSysMdbTopMemInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopMemInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopMemInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorBytheAll��һ�����ڴ���Դʹ����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorBytheAll: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopMemInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbTopMemInfoIteratorBytheAll(CSysMdbTopMemInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbTopMemInfoIteratorBytheAll *alloc(CSysMdbTopMemInfoFactory *pFactory
		);

	///���췽��
	CSysMdbTopMemInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbTopMemInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopMemInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopMemInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorByDataDelete��һ�����ڴ���Դʹ����Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorByDataDelete: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopMemInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopMemInfoIteratorByDataDelete(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopMemInfoIteratorByDataDelete *alloc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbTopMemInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopMemInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopMemInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIteratorByHostName��һ���Խ�����Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIteratorByHostName: public CSysMdbTopProcessInfoIterator
{
	friend class CSysMdbTopProcessInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopProcessInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

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
	CWriteableSysMdbTopProcessInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopProcessInfoIteratorByHostName(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopProcessInfoIteratorByHostName *alloc(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbTopProcessInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopProcessInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopProcessInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbTopProcessInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIteratorByDsc��һ���Խ�����Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIteratorByDsc: public CSysMdbTopProcessInfoIterator
{
	friend class CSysMdbTopProcessInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopProcessInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

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
	CWriteableSysMdbTopProcessInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CSysMdbTopProcessInfoIteratorByDsc(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CSysMdbTopProcessInfoIteratorByDsc *alloc(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///���췽��
	CSysMdbTopProcessInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopProcessInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopProcessInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbTopProcessInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIteratorBytheAll��һ���Խ�����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIteratorBytheAll: public CSysMdbTopProcessInfoIterator
{
	friend class CSysMdbTopProcessInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTopProcessInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

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
	CWriteableSysMdbTopProcessInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbTopProcessInfoIteratorBytheAll(CSysMdbTopProcessInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbTopProcessInfoIteratorBytheAll *alloc(CSysMdbTopProcessInfoFactory *pFactory
		);

	///���췽��
	CSysMdbTopProcessInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbTopProcessInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopProcessInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTopProcessInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbTopProcessInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIteratorByHostName��һ�����ļ�ϵͳ��Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIteratorByHostName: public CSysMdbFileSystemInfoIterator
{
	friend class CSysMdbFileSystemInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbFileSystemInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

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
	CWriteableSysMdbFileSystemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbFileSystemInfoIteratorByHostName(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbFileSystemInfoIteratorByHostName *alloc(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbFileSystemInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbFileSystemInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbFileSystemInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbFileSystemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIteratorByDsc��һ�����ļ�ϵͳ��Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIteratorByDsc: public CSysMdbFileSystemInfoIterator
{
	friend class CSysMdbFileSystemInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbFileSystemInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

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
	CWriteableSysMdbFileSystemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	CSysMdbFileSystemInfoIteratorByDsc(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	static CSysMdbFileSystemInfoIteratorByDsc *alloc(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///���췽��
	CSysMdbFileSystemInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	HostName	
	void init(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbFileSystemInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbFileSystemInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbFileSystemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIteratorBytheAll��һ�����ļ�ϵͳ��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIteratorBytheAll: public CSysMdbFileSystemInfoIterator
{
	friend class CSysMdbFileSystemInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbFileSystemInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

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
	CWriteableSysMdbFileSystemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbFileSystemInfoIteratorBytheAll(CSysMdbFileSystemInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbFileSystemInfoIteratorBytheAll *alloc(CSysMdbFileSystemInfoFactory *pFactory
		);

	///���췽��
	CSysMdbFileSystemInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbFileSystemInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbFileSystemInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbFileSystemInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbFileSystemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorByHostName��һ��������ʹ����Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorByHostName: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbNetworkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbNetworkInfoIteratorByHostName(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbNetworkInfoIteratorByHostName *alloc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbNetworkInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetworkInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbNetworkInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorByDsc��һ��������ʹ����Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorByDsc: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbNetworkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbNetworkInfoIteratorByDsc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbNetworkInfoIteratorByDsc *alloc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbNetworkInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetworkInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbNetworkInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorBytheAll��һ��������ʹ����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorBytheAll: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbNetworkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbNetworkInfoIteratorBytheAll(CSysMdbNetworkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbNetworkInfoIteratorBytheAll *alloc(CSysMdbNetworkInfoFactory *pFactory
		);

	///���췽��
	CSysMdbNetworkInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbNetworkInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetworkInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbNetworkInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorByDataDelete��һ��������ʹ����Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorByDataDelete: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbNetworkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbNetworkInfoIteratorByDataDelete(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbNetworkInfoIteratorByDataDelete *alloc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbNetworkInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetworkInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbNetworkInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitIteratorByAll��һ���Ի�Աʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitIteratorByAll: public CSysParticipantInitIterator
{
	friend class CSysParticipantInitFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysParticipantInit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysParticipantInit *pSysParticipantInit);

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
	CWriteableSysParticipantInit m_compareObject;
	
	static CMemoryStack<CSysParticipantInitIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysParticipantInitIteratorByAll(CSysParticipantInitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysParticipantInitIteratorByAll *alloc(CSysParticipantInitFactory *pFactory
		);

	///���췽��
	CSysParticipantInitIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysParticipantInitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysParticipantInitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysParticipantInit��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysParticipantInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitIteratorByAll��һ���Խ����û�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitIteratorByAll: public CSysUserInitIterator
{
	friend class CSysUserInitFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysUserInit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysUserInit *pSysUserInit);

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
	CWriteableSysUserInit m_compareObject;
	
	static CMemoryStack<CSysUserInitIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysUserInitIteratorByAll(CSysUserInitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysUserInitIteratorByAll *alloc(CSysUserInitFactory *pFactory
		);

	///���췽��
	CSysUserInitIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysUserInitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserInitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysUserInit��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysUserInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitIteratorByAll��һ���Կͻ�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitIteratorByAll: public CSysClientInitIterator
{
	friend class CSysClientInitFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysClientInit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysClientInit *pSysClientInit);

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
	CWriteableSysClientInit m_compareObject;
	
	static CMemoryStack<CSysClientInitIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysClientInitIteratorByAll(CSysClientInitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysClientInitIteratorByAll *alloc(CSysClientInitFactory *pFactory
		);

	///���췽��
	CSysClientInitIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysClientInitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientInitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysClientInit��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysClientInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientInit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientInit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoIteratorByAll��һ���Խ���ϵͳ��¼��Ϣʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoIteratorByAll: public CSysTradeUserLoginInfoIterator
{
	friend class CSysTradeUserLoginInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysTradeUserLoginInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);

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
	CWriteableSysTradeUserLoginInfo m_compareObject;
	
	static CMemoryStack<CSysTradeUserLoginInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysTradeUserLoginInfoIteratorByAll(CSysTradeUserLoginInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysTradeUserLoginInfoIteratorByAll *alloc(CSysTradeUserLoginInfoFactory *pFactory
		);

	///���췽��
	CSysTradeUserLoginInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysTradeUserLoginInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysTradeUserLoginInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysTradeUserLoginInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysTradeUserLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorByIDType��һ����WebӦ����Ϣʹ��ByIDType��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorByIDType: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbWebAppInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorByIDType> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbWebAppInfoIteratorByIDType(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbWebAppInfoIteratorByIDType *alloc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbWebAppInfoIteratorByIDType(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbWebAppInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbWebAppInfo��������startFindByIDType�Ժ�endFindByIDType֮ǰ����
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorByDsc��һ����WebӦ����Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorByDsc: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbWebAppInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	CSysMdbWebAppInfoIteratorByDsc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	static CSysMdbWebAppInfoIteratorByDsc *alloc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///���췽��
	CSysMdbWebAppInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	void init(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbWebAppInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbWebAppInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorBytheAll��һ����WebӦ����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorBytheAll: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbWebAppInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbWebAppInfoIteratorBytheAll(CSysMdbWebAppInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbWebAppInfoIteratorBytheAll *alloc(CSysMdbWebAppInfoFactory *pFactory
		);

	///���췽��
	CSysMdbWebAppInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbWebAppInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbWebAppInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbWebAppInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorByDataDelete��һ����WebӦ����Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorByDataDelete: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbWebAppInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbWebAppInfoIteratorByDataDelete(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbWebAppInfoIteratorByDataDelete *alloc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbWebAppInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbWebAppInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbWebAppInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorByIDType��һ����ϵͳ�ڴ����Ϣʹ��ByIDType��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorByIDType: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbMemPoolInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorByIDType> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbMemPoolInfoIteratorByIDType(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbMemPoolInfoIteratorByIDType *alloc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbMemPoolInfoIteratorByIDType(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbMemPoolInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbMemPoolInfo��������startFindByIDType�Ժ�endFindByIDType֮ǰ����
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorByDsc��һ����ϵͳ�ڴ����Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorByDsc: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbMemPoolInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	CSysMdbMemPoolInfoIteratorByDsc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	static CSysMdbMemPoolInfoIteratorByDsc *alloc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///���췽��
	CSysMdbMemPoolInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	void init(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbMemPoolInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbMemPoolInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorBytheAll��һ����ϵͳ�ڴ����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorBytheAll: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbMemPoolInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbMemPoolInfoIteratorBytheAll(CSysMdbMemPoolInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbMemPoolInfoIteratorBytheAll *alloc(CSysMdbMemPoolInfoFactory *pFactory
		);

	///���췽��
	CSysMdbMemPoolInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbMemPoolInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbMemPoolInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbMemPoolInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorByDataDelete��һ����ϵͳ�ڴ����Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorByDataDelete: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbMemPoolInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbMemPoolInfoIteratorByDataDelete(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbMemPoolInfoIteratorByDataDelete *alloc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbMemPoolInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbMemPoolInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbMemPoolInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorByIDType��һ������������Ϣʹ��ByIDType��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorByIDType: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbConnectorInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorByIDType> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbConnectorInfoIteratorByIDType(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbConnectorInfoIteratorByIDType *alloc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbConnectorInfoIteratorByIDType(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbConnectorInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbConnectorInfo��������startFindByIDType�Ժ�endFindByIDType֮ǰ����
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorByDsc��һ������������Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorByDsc: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbConnectorInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	CSysMdbConnectorInfoIteratorByDsc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	static CSysMdbConnectorInfoIteratorByDsc *alloc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///���췽��
	CSysMdbConnectorInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	void init(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbConnectorInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbConnectorInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorBytheAll��һ������������Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorBytheAll: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbConnectorInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbConnectorInfoIteratorBytheAll(CSysMdbConnectorInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbConnectorInfoIteratorBytheAll *alloc(CSysMdbConnectorInfoFactory *pFactory
		);

	///���췽��
	CSysMdbConnectorInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbConnectorInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbConnectorInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbConnectorInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorByDataDelete��һ������������Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorByDataDelete: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbConnectorInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbConnectorInfoIteratorByDataDelete(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbConnectorInfoIteratorByDataDelete *alloc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbConnectorInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbConnectorInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbConnectorInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorByIDType��һ�������ݿ��ѯӦ��ʹ��ByIDType��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorByIDType: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDBQuery		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorByIDType> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDBQueryIteratorByIDType(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDBQueryIteratorByIDType *alloc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbDBQueryIteratorByIDType(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDBQueryIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDBQuery��������startFindByIDType�Ժ�endFindByIDType֮ǰ����
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorByDsc��һ�������ݿ��ѯӦ��ʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorByDsc: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDBQuery		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbDBQueryIteratorByDsc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbDBQueryIteratorByDsc *alloc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbDBQueryIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDBQueryIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDBQuery��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorBytheAll��һ�������ݿ��ѯӦ��ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorBytheAll: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDBQuery		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbDBQueryIteratorBytheAll(CSysMdbDBQueryFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbDBQueryIteratorBytheAll *alloc(CSysMdbDBQueryFactory *pFactory
		);

	///���췽��
	CSysMdbDBQueryIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbDBQueryFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDBQueryIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDBQuery��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorByDataDelete��һ�������ݿ��ѯӦ��ʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorByDataDelete: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDBQuery		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDBQueryIteratorByDataDelete(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDBQueryIteratorByDataDelete *alloc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbDBQueryIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDBQueryIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDBQuery��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaIteratorByAll��һ���������������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaIteratorByAll: public CSysNetAreaIterator
{
	friend class CSysNetAreaFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetArea		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetArea *pSysNetArea);

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
	CWriteableSysNetArea m_compareObject;
	
	static CMemoryStack<CSysNetAreaIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetAreaIteratorByAll(CSysNetAreaFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetAreaIteratorByAll *alloc(CSysNetAreaFactory *pFactory
		);

	///���췽��
	CSysNetAreaIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetAreaFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetAreaIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetArea��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetArea * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIteratorByAll��һ������������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIteratorByAll: public CSysNetSubAreaIterator
{
	friend class CSysNetSubAreaFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetSubArea		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetSubArea *pSysNetSubArea);

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
	CWriteableSysNetSubArea m_compareObject;
	
	static CMemoryStack<CSysNetSubAreaIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetSubAreaIteratorByAll(CSysNetSubAreaFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetSubAreaIteratorByAll *alloc(CSysNetSubAreaFactory *pFactory
		);

	///���췽��
	CSysNetSubAreaIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetSubAreaFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetSubAreaIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetSubArea��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetSubArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPIteratorByAll��һ������������IPʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPIteratorByAll: public CSysNetSubAreaIPIterator
{
	friend class CSysNetSubAreaIPFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetSubAreaIP		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetSubAreaIP *pSysNetSubAreaIP);

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
	CWriteableSysNetSubAreaIP m_compareObject;
	
	static CMemoryStack<CSysNetSubAreaIPIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetSubAreaIPIteratorByAll(CSysNetSubAreaIPFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetSubAreaIPIteratorByAll *alloc(CSysNetSubAreaIPFactory *pFactory
		);

	///���췽��
	CSysNetSubAreaIPIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetSubAreaIPFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetSubAreaIPIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetSubAreaIP��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetSubAreaIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaIteratorByAll��һ����ְ����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaIteratorByAll: public CSysNetFuncAreaIterator
{
	friend class CSysNetFuncAreaFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetFuncArea		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetFuncArea *pSysNetFuncArea);

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
	CWriteableSysNetFuncArea m_compareObject;
	
	static CMemoryStack<CSysNetFuncAreaIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetFuncAreaIteratorByAll(CSysNetFuncAreaFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetFuncAreaIteratorByAll *alloc(CSysNetFuncAreaFactory *pFactory
		);

	///���췽��
	CSysNetFuncAreaIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetFuncAreaFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetFuncAreaIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetFuncArea��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetFuncArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetFuncArea *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIteratorByAll��һ���������豸ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIteratorByAll: public CSysNetDeviceIterator
{
	friend class CSysNetDeviceFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDevice		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDevice *pSysNetDevice);

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
	CWriteableSysNetDevice m_compareObject;
	
	static CMemoryStack<CSysNetDeviceIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetDeviceIteratorByAll(CSysNetDeviceFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetDeviceIteratorByAll *alloc(CSysNetDeviceFactory *pFactory
		);

	///���췽��
	CSysNetDeviceIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetDeviceFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDevice��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetDevice������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDevice *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDevice * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIteratorByIPDECODE��һ���������豸ʹ��ByIPDECODE��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIteratorByIPDECODE: public CSysNetDeviceIterator
{
	friend class CSysNetDeviceFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDevice		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDevice *pSysNetDevice);

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
	CWriteableSysNetDevice m_compareObject;
	
	static CMemoryStack<CSysNetDeviceIteratorByIPDECODE> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	IPDECODE	
	CSysNetDeviceIteratorByIPDECODE(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& IPDECODE)
	{
		init(pFactory,IPDECODE);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	IPDECODE	
	static CSysNetDeviceIteratorByIPDECODE *alloc(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& IPDECODE);

	///���췽��
	CSysNetDeviceIteratorByIPDECODE(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	IPDECODE	
	void init(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& IPDECODE);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceIteratorByIPDECODE(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDevice��������startFindByIPDECODE�Ժ�endFindByIPDECODE֮ǰ����
	///@return	��һ����������CSysNetDevice������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDevice *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIPDECODE ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDevice * pByIPDECODE,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIteratorBySubAreaID��һ���������豸ʹ��BySubAreaID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIteratorBySubAreaID: public CSysNetDeviceIterator
{
	friend class CSysNetDeviceFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDevice		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDevice *pSysNetDevice);

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
	CWriteableSysNetDevice m_compareObject;
	
	static CMemoryStack<CSysNetDeviceIteratorBySubAreaID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SysNetSubAreaID	
	CSysNetDeviceIteratorBySubAreaID(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& SysNetSubAreaID)
	{
		init(pFactory,SysNetSubAreaID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SysNetSubAreaID	
	static CSysNetDeviceIteratorBySubAreaID *alloc(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& SysNetSubAreaID);

	///���췽��
	CSysNetDeviceIteratorBySubAreaID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SysNetSubAreaID	
	void init(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& SysNetSubAreaID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceIteratorBySubAreaID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDevice��������startFindBySubAreaID�Ժ�endFindBySubAreaID֮ǰ����
	///@return	��һ����������CSysNetDevice������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDevice *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySubAreaID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDevice * pBySubAreaID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIteratorByAll��һ���������豸���ӹ�ϵʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIteratorByAll: public CSysNetDeviceLinkedIterator
{
	friend class CSysNetDeviceLinkedFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDeviceLinked		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDeviceLinked *pSysNetDeviceLinked);

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
	CWriteableSysNetDeviceLinked m_compareObject;
	
	static CMemoryStack<CSysNetDeviceLinkedIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetDeviceLinkedIteratorByAll(CSysNetDeviceLinkedFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetDeviceLinkedIteratorByAll *alloc(CSysNetDeviceLinkedFactory *pFactory
		);

	///���췽��
	CSysNetDeviceLinkedIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetDeviceLinkedFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceLinkedIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDeviceLinked��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetDeviceLinked������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIteratorByNetObjectID��һ���������豸���ӹ�ϵʹ��ByNetObjectID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIteratorByNetObjectID: public CSysNetDeviceLinkedIterator
{
	friend class CSysNetDeviceLinkedFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDeviceLinked		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDeviceLinked *pSysNetDeviceLinked);

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
	CWriteableSysNetDeviceLinked m_compareObject;
	
	static CMemoryStack<CSysNetDeviceLinkedIteratorByNetObjectID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	NetObjectID	
	CSysNetDeviceLinkedIteratorByNetObjectID(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& NetObjectID)
	{
		init(pFactory,NetObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	NetObjectID	
	static CSysNetDeviceLinkedIteratorByNetObjectID *alloc(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& NetObjectID);

	///���췽��
	CSysNetDeviceLinkedIteratorByNetObjectID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	NetObjectID	
	void init(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& NetObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceLinkedIteratorByNetObjectID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDeviceLinked��������startFindByNetObjectID�Ժ�endFindByNetObjectID֮ǰ����
	///@return	��һ����������CSysNetDeviceLinked������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByNetObjectID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pByNetObjectID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIteratorByLinkNetObjectID��һ���������豸���ӹ�ϵʹ��ByLinkNetObjectID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIteratorByLinkNetObjectID: public CSysNetDeviceLinkedIterator
{
	friend class CSysNetDeviceLinkedFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDeviceLinked		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDeviceLinked *pSysNetDeviceLinked);

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
	CWriteableSysNetDeviceLinked m_compareObject;
	
	static CMemoryStack<CSysNetDeviceLinkedIteratorByLinkNetObjectID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LinkNetObjectID	
	CSysNetDeviceLinkedIteratorByLinkNetObjectID(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& LinkNetObjectID)
	{
		init(pFactory,LinkNetObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LinkNetObjectID	
	static CSysNetDeviceLinkedIteratorByLinkNetObjectID *alloc(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& LinkNetObjectID);

	///���췽��
	CSysNetDeviceLinkedIteratorByLinkNetObjectID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LinkNetObjectID	
	void init(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& LinkNetObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceLinkedIteratorByLinkNetObjectID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDeviceLinked��������startFindByLinkNetObjectID�Ժ�endFindByLinkNetObjectID֮ǰ����
	///@return	��һ����������CSysNetDeviceLinked������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByLinkNetObjectID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pByLinkNetObjectID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDIteratorByAll��һ����OIDʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDIteratorByAll: public CSysNetOIDIterator
{
	friend class CSysNetOIDFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetOID		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetOID *pSysNetOID);

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
	CWriteableSysNetOID m_compareObject;
	
	static CMemoryStack<CSysNetOIDIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetOIDIteratorByAll(CSysNetOIDFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetOIDIteratorByAll *alloc(CSysNetOIDFactory *pFactory
		);

	///���췽��
	CSysNetOIDIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetOIDFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetOIDIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetOID��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOID * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeIteratorByAll��һ���������豸����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeIteratorByAll: public CSysNetDeviceTypeIterator
{
	friend class CSysNetDeviceTypeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDeviceType		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDeviceType *pSysNetDeviceType);

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
	CWriteableSysNetDeviceType m_compareObject;
	
	static CMemoryStack<CSysNetDeviceTypeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetDeviceTypeIteratorByAll(CSysNetDeviceTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetDeviceTypeIteratorByAll *alloc(CSysNetDeviceTypeFactory *pFactory
		);

	///���췽��
	CSysNetDeviceTypeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetDeviceTypeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDeviceType��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetDeviceType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyIteratorByAll��һ����ʱ�����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyIteratorByAll: public CSysNetTimePolicyIterator
{
	friend class CSysNetTimePolicyFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetTimePolicy		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetTimePolicy *pSysNetTimePolicy);

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
	CWriteableSysNetTimePolicy m_compareObject;
	
	static CMemoryStack<CSysNetTimePolicyIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetTimePolicyIteratorByAll(CSysNetTimePolicyFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetTimePolicyIteratorByAll *alloc(CSysNetTimePolicyFactory *pFactory
		);

	///���췽��
	CSysNetTimePolicyIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetTimePolicyFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetTimePolicyIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetTimePolicy��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetTimePolicy������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetTimePolicy *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskIteratorByAll��һ���Բɼ�����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskIteratorByAll: public CSysNetGatherTaskIterator
{
	friend class CSysNetGatherTaskFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetGatherTask		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetGatherTask *pSysNetGatherTask);

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
	CWriteableSysNetGatherTask m_compareObject;
	
	static CMemoryStack<CSysNetGatherTaskIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetGatherTaskIteratorByAll(CSysNetGatherTaskFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetGatherTaskIteratorByAll *alloc(CSysNetGatherTaskFactory *pFactory
		);

	///���췽��
	CSysNetGatherTaskIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetGatherTaskFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetGatherTaskIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetGatherTask��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetGatherTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGatherTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskIteratorByNetObjectID��һ���Բɼ�����ʹ��ByNetObjectID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskIteratorByNetObjectID: public CSysNetGatherTaskIterator
{
	friend class CSysNetGatherTaskFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetGatherTask		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetGatherTask *pSysNetGatherTask);

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
	CWriteableSysNetGatherTask m_compareObject;
	
	static CMemoryStack<CSysNetGatherTaskIteratorByNetObjectID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	CSysNetGatherTaskIteratorByNetObjectID(CSysNetGatherTaskFactory *pFactory
		,const CReadOnlyNetObjectIDType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	static CSysNetGatherTaskIteratorByNetObjectID *alloc(CSysNetGatherTaskFactory *pFactory
		,const CReadOnlyNetObjectIDType& ObjectID);

	///���췽��
	CSysNetGatherTaskIteratorByNetObjectID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	void init(CSysNetGatherTaskFactory *pFactory
		,const CReadOnlyNetObjectIDType& ObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetGatherTaskIteratorByNetObjectID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetGatherTask��������startFindByNetObjectID�Ժ�endFindByNetObjectID֮ǰ����
	///@return	��һ����������CSysNetGatherTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGatherTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByNetObjectID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pByNetObjectID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryIteratorByAll��һ���Գ����豸���ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryIteratorByAll: public CSysNetDeviceCategoryIterator
{
	friend class CSysNetDeviceCategoryFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDeviceCategory		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDeviceCategory *pSysNetDeviceCategory);

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
	CWriteableSysNetDeviceCategory m_compareObject;
	
	static CMemoryStack<CSysNetDeviceCategoryIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetDeviceCategoryIteratorByAll(CSysNetDeviceCategoryFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetDeviceCategoryIteratorByAll *alloc(CSysNetDeviceCategoryFactory *pFactory
		);

	///���췽��
	CSysNetDeviceCategoryIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetDeviceCategoryFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceCategoryIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDeviceCategory��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetDeviceCategory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryIteratorByAll��һ�����豸����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryIteratorByAll: public CSysNetManufactoryIterator
{
	friend class CSysNetManufactoryFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetManufactory		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetManufactory *pSysNetManufactory);

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
	CWriteableSysNetManufactory m_compareObject;
	
	static CMemoryStack<CSysNetManufactoryIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetManufactoryIteratorByAll(CSysNetManufactoryFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetManufactoryIteratorByAll *alloc(CSysNetManufactoryFactory *pFactory
		);

	///���췽��
	CSysNetManufactoryIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetManufactoryFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetManufactoryIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetManufactory��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetManufactory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetManufactory *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityIteratorByAll��һ�����豸��ͬ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityIteratorByAll: public CSysNetCommunityIterator
{
	friend class CSysNetCommunityFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetCommunity		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetCommunity *pSysNetCommunity);

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
	CWriteableSysNetCommunity m_compareObject;
	
	static CMemoryStack<CSysNetCommunityIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetCommunityIteratorByAll(CSysNetCommunityFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetCommunityIteratorByAll *alloc(CSysNetCommunityFactory *pFactory
		);

	///���췽��
	CSysNetCommunityIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetCommunityFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetCommunityIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetCommunity��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetCommunity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetCommunity *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeIteratorByAll��һ���Զ˿�����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeIteratorByAll: public CSysNetPortTypeIterator
{
	friend class CSysNetPortTypeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetPortType		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetPortType *pSysNetPortType);

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
	CWriteableSysNetPortType m_compareObject;
	
	static CMemoryStack<CSysNetPortTypeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetPortTypeIteratorByAll(CSysNetPortTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetPortTypeIteratorByAll *alloc(CSysNetPortTypeFactory *pFactory
		);

	///���췽��
	CSysNetPortTypeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetPortTypeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPortTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetPortType��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetPortType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPortType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPortType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceIteratorByAll��һ���Զ˿�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceIteratorByAll: public CSysNetInterfaceIterator
{
	friend class CSysNetInterfaceFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetInterface		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetInterface *pSysNetInterface);

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
	CWriteableSysNetInterface m_compareObject;
	
	static CMemoryStack<CSysNetInterfaceIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetInterfaceIteratorByAll(CSysNetInterfaceFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetInterfaceIteratorByAll *alloc(CSysNetInterfaceFactory *pFactory
		);

	///���췽��
	CSysNetInterfaceIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetInterfaceFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetInterfaceIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetInterface��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetInterface������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetInterface *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetInterface * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceIteratorByDeviceID��һ���Զ˿�ʹ��ByDeviceID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceIteratorByDeviceID: public CSysNetInterfaceIterator
{
	friend class CSysNetInterfaceFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetInterface		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetInterface *pSysNetInterface);

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
	CWriteableSysNetInterface m_compareObject;
	
	static CMemoryStack<CSysNetInterfaceIteratorByDeviceID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceID	
	CSysNetInterfaceIteratorByDeviceID(CSysNetInterfaceFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID)
	{
		init(pFactory,DeviceID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceID	
	static CSysNetInterfaceIteratorByDeviceID *alloc(CSysNetInterfaceFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///���췽��
	CSysNetInterfaceIteratorByDeviceID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceID	
	void init(CSysNetInterfaceFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetInterfaceIteratorByDeviceID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetInterface��������startFindByDeviceID�Ժ�endFindByDeviceID֮ǰ����
	///@return	��һ����������CSysNetInterface������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetInterface *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDeviceID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetInterface * pByDeviceID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDIteratorByAll��һ����ͨ��OIDʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDIteratorByAll: public CSysNetGeneralOIDIterator
{
	friend class CSysNetGeneralOIDFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetGeneralOID		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetGeneralOID *pSysNetGeneralOID);

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
	CWriteableSysNetGeneralOID m_compareObject;
	
	static CMemoryStack<CSysNetGeneralOIDIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetGeneralOIDIteratorByAll(CSysNetGeneralOIDFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetGeneralOIDIteratorByAll *alloc(CSysNetGeneralOIDFactory *pFactory
		);

	///���췽��
	CSysNetGeneralOIDIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetGeneralOIDFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetGeneralOIDIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetGeneralOID��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetGeneralOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGeneralOID *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeIteratorByAll��һ���Լ�ض������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeIteratorByAll: public CSysNetMonitorTypeIterator
{
	friend class CSysNetMonitorTypeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorType		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorType *pSysNetMonitorType);

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
	CWriteableSysNetMonitorType m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTypeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorTypeIteratorByAll(CSysNetMonitorTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorTypeIteratorByAll *alloc(CSysNetMonitorTypeFactory *pFactory
		);

	///���췽��
	CSysNetMonitorTypeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorTypeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorType��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeIteratorByAll��һ����ָ��ͳ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeIteratorByAll: public CSysNetMonitorAttrScopeIterator
{
	friend class CSysNetMonitorAttrScopeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorAttrScope		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);

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
	CWriteableSysNetMonitorAttrScope m_compareObject;
	
	static CMemoryStack<CSysNetMonitorAttrScopeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorAttrScopeIteratorByAll(CSysNetMonitorAttrScopeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorAttrScopeIteratorByAll *alloc(CSysNetMonitorAttrScopeFactory *pFactory
		);

	///���췽��
	CSysNetMonitorAttrScopeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorAttrScopeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorAttrScopeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorAttrScope��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorAttrScope������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeIteratorByAll��һ���Լ��ָ���ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeIteratorByAll: public CSysNetMonitorAttrTypeIterator
{
	friend class CSysNetMonitorAttrTypeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorAttrType		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorAttrType *pSysNetMonitorAttrType);

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
	CWriteableSysNetMonitorAttrType m_compareObject;
	
	static CMemoryStack<CSysNetMonitorAttrTypeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorAttrTypeIteratorByAll(CSysNetMonitorAttrTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorAttrTypeIteratorByAll *alloc(CSysNetMonitorAttrTypeFactory *pFactory
		);

	///���췽��
	CSysNetMonitorAttrTypeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorAttrTypeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorAttrTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorAttrType��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorAttrType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeIteratorByAll��һ���Լ��ָ���ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeIteratorByAll: public CSysNetMonitorCommandTypeIterator
{
	friend class CSysNetMonitorCommandTypeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorCommandType		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorCommandType *pSysNetMonitorCommandType);

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
	CWriteableSysNetMonitorCommandType m_compareObject;
	
	static CMemoryStack<CSysNetMonitorCommandTypeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorCommandTypeIteratorByAll(CSysNetMonitorCommandTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorCommandTypeIteratorByAll *alloc(CSysNetMonitorCommandTypeFactory *pFactory
		);

	///���췽��
	CSysNetMonitorCommandTypeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorCommandTypeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorCommandTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorCommandType��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorCommandType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupIteratorByAll��һ���Զ������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupIteratorByAll: public CSysNetMonitorActionGroupIterator
{
	friend class CSysNetMonitorActionGroupFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorActionGroup		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);

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
	CWriteableSysNetMonitorActionGroup m_compareObject;
	
	static CMemoryStack<CSysNetMonitorActionGroupIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorActionGroupIteratorByAll(CSysNetMonitorActionGroupFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorActionGroupIteratorByAll *alloc(CSysNetMonitorActionGroupFactory *pFactory
		);

	///���췽��
	CSysNetMonitorActionGroupIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorActionGroupFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorActionGroupIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorActionGroup��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorActionGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupIteratorByAll��һ�����豸�������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupIteratorByAll: public CSysNetMonitorDeviceGroupIterator
{
	friend class CSysNetMonitorDeviceGroupFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorDeviceGroup		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);

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
	CWriteableSysNetMonitorDeviceGroup m_compareObject;
	
	static CMemoryStack<CSysNetMonitorDeviceGroupIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorDeviceGroupIteratorByAll(CSysNetMonitorDeviceGroupFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorDeviceGroupIteratorByAll *alloc(CSysNetMonitorDeviceGroupFactory *pFactory
		);

	///���췽��
	CSysNetMonitorDeviceGroupIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorDeviceGroupFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorDeviceGroupIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorDeviceGroup��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorDeviceGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoIteratorByAll��һ����������Ϣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoIteratorByAll: public CSysNetMonitorTaskInfoIterator
{
	friend class CSysNetMonitorTaskInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);

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
	CWriteableSysNetMonitorTaskInfo m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorTaskInfoIteratorByAll(CSysNetMonitorTaskInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorTaskInfoIteratorByAll *alloc(CSysNetMonitorTaskInfoFactory *pFactory
		);

	///���췽��
	CSysNetMonitorTaskInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorTaskInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetIteratorByAll��һ�����������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetIteratorByAll: public CSysNetMonitorTaskObjectSetIterator
{
	friend class CSysNetMonitorTaskObjectSetFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskObjectSet		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);

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
	CWriteableSysNetMonitorTaskObjectSet m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskObjectSetIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorTaskObjectSetIteratorByAll(CSysNetMonitorTaskObjectSetFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorTaskObjectSetIteratorByAll *alloc(CSysNetMonitorTaskObjectSetFactory *pFactory
		);

	///���췽��
	CSysNetMonitorTaskObjectSetIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorTaskObjectSetFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskObjectSetIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskObjectSet��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskObjectSet������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID��һ�����������ʹ��ByDeviceGroup_ID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID: public CSysNetMonitorTaskObjectSetIterator
{
	friend class CSysNetMonitorTaskObjectSetFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskObjectSet		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);

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
	CWriteableSysNetMonitorTaskObjectSet m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceGroup_ID	
	CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID(CSysNetMonitorTaskObjectSetFactory *pFactory
		,const CReadOnlyVolumeType& DeviceGroup_ID)
	{
		init(pFactory,DeviceGroup_ID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceGroup_ID	
	static CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID *alloc(CSysNetMonitorTaskObjectSetFactory *pFactory
		,const CReadOnlyVolumeType& DeviceGroup_ID);

	///���췽��
	CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceGroup_ID	
	void init(CSysNetMonitorTaskObjectSetFactory *pFactory
		,const CReadOnlyVolumeType& DeviceGroup_ID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskObjectSet��������startFindByDeviceGroup_ID�Ժ�endFindByDeviceGroup_ID֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskObjectSet������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDeviceGroup_ID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pByDeviceGroup_ID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByAll��һ������������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByAll: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskResult		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorTaskResultIteratorByAll(CSysNetMonitorTaskResultFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorTaskResultIteratorByAll *alloc(CSysNetMonitorTaskResultFactory *pFactory
		);

	///���췽��
	CSysNetMonitorTaskResultIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorTaskResultFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskResultIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskResult��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByTask_ID��һ������������ʹ��ByTask_ID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByTask_ID: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskResult		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByTask_ID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	CSysNetMonitorTaskResultIteratorByTask_ID(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID)
	{
		init(pFactory,MonDate,Task_ID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	static CSysNetMonitorTaskResultIteratorByTask_ID *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID);

	///���췽��
	CSysNetMonitorTaskResultIteratorByTask_ID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskResultIteratorByTask_ID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskResult��������startFindByTask_ID�Ժ�endFindByTask_ID֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTask_ID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByTask_ID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByOnlyDate��һ������������ʹ��ByOnlyDate��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByOnlyDate: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskResult		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByOnlyDate> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	CSysNetMonitorTaskResultIteratorByOnlyDate(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate)
	{
		init(pFactory,MonDate);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	static CSysNetMonitorTaskResultIteratorByOnlyDate *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate);

	///���췽��
	CSysNetMonitorTaskResultIteratorByOnlyDate(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskResultIteratorByOnlyDate(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskResult��������startFindByOnlyDate�Ժ�endFindByOnlyDate֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByOnlyDate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByOnlyDate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByIDTaskTime��һ������������ʹ��ByIDTaskTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByIDTaskTime: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskResult		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByIDTaskTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@param	OperateTime	
	CSysNetMonitorTaskResultIteratorByIDTaskTime(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID,const CReadOnlyVolumeType& OperateTime)
	{
		init(pFactory,MonDate,Task_ID,ObjectID,OperateTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@param	OperateTime	
	static CSysNetMonitorTaskResultIteratorByIDTaskTime *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID,const CReadOnlyVolumeType& OperateTime);

	///���췽��
	CSysNetMonitorTaskResultIteratorByIDTaskTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@param	OperateTime	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID,const CReadOnlyVolumeType& OperateTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskResultIteratorByIDTaskTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskResult��������startFindByIDTaskTime�Ժ�endFindByIDTaskTime֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDTaskTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByIDTaskTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByDataDelete��һ������������ʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByDataDelete: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskResult		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	CSysNetMonitorTaskResultIteratorByDataDelete(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID)
	{
		init(pFactory,MonDate,Task_ID,ObjectID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	static CSysNetMonitorTaskResultIteratorByDataDelete *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID);

	///���췽��
	CSysNetMonitorTaskResultIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskResultIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskResult��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoIteratorByAll��һ���Ի�Ա��·��Ϣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoIteratorByAll: public CSysNetPartyLinkInfoIterator
{
	friend class CSysNetPartyLinkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetPartyLinkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);

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
	CWriteableSysNetPartyLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetPartyLinkInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetPartyLinkInfoIteratorByAll(CSysNetPartyLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetPartyLinkInfoIteratorByAll *alloc(CSysNetPartyLinkInfoFactory *pFactory
		);

	///���췽��
	CSysNetPartyLinkInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetPartyLinkInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartyLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetPartyLinkInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoIteratorByAll��һ���Ի�Ա��·��Ϣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoIteratorByAll: public CSysNetDelPartyLinkInfoIterator
{
	friend class CSysNetDelPartyLinkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDelPartyLinkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);

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
	CWriteableSysNetDelPartyLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetDelPartyLinkInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetDelPartyLinkInfoIteratorByAll(CSysNetDelPartyLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetDelPartyLinkInfoIteratorByAll *alloc(CSysNetDelPartyLinkInfoFactory *pFactory
		);

	///���췽��
	CSysNetDelPartyLinkInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetDelPartyLinkInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDelPartyLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDelPartyLinkInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetDelPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeIteratorByAll��һ���Ի�Ա��·��Ϣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeIteratorByAll: public CSysNetPartyLinkAddrChangeIterator
{
	friend class CSysNetPartyLinkAddrChangeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetPartyLinkAddrChange		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);

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
	CWriteableSysNetPartyLinkAddrChange m_compareObject;
	
	static CMemoryStack<CSysNetPartyLinkAddrChangeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetPartyLinkAddrChangeIteratorByAll(CSysNetPartyLinkAddrChangeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetPartyLinkAddrChangeIteratorByAll *alloc(CSysNetPartyLinkAddrChangeFactory *pFactory
		);

	///���췽��
	CSysNetPartyLinkAddrChangeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetPartyLinkAddrChangeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartyLinkAddrChangeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetPartyLinkAddrChange��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetPartyLinkAddrChange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrIteratorByAll��һ���Լ�ض���ָ����ձ�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrIteratorByAll: public CSysNetMonitorActionAttrIterator
{
	friend class CSysNetMonitorActionAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorActionAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);

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
	CWriteableSysNetMonitorActionAttr m_compareObject;
	
	static CMemoryStack<CSysNetMonitorActionAttrIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorActionAttrIteratorByAll(CSysNetMonitorActionAttrFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorActionAttrIteratorByAll *alloc(CSysNetMonitorActionAttrFactory *pFactory
		);

	///���췽��
	CSysNetMonitorActionAttrIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorActionAttrFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorActionAttrIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorActionAttr��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorActionAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleIteratorByAll��һ����ģ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleIteratorByAll: public CSysNetModuleIterator
{
	friend class CSysNetModuleFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetModule		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetModule *pSysNetModule);

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
	CWriteableSysNetModule m_compareObject;
	
	static CMemoryStack<CSysNetModuleIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetModuleIteratorByAll(CSysNetModuleFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetModuleIteratorByAll *alloc(CSysNetModuleFactory *pFactory
		);

	///���췽��
	CSysNetModuleIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetModuleFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetModuleIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetModule��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetModule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetModule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetModule * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetModuleIteratorByDeviceID��һ����ģ��ʹ��ByDeviceID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleIteratorByDeviceID: public CSysNetModuleIterator
{
	friend class CSysNetModuleFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetModule		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetModule *pSysNetModule);

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
	CWriteableSysNetModule m_compareObject;
	
	static CMemoryStack<CSysNetModuleIteratorByDeviceID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceID	
	CSysNetModuleIteratorByDeviceID(CSysNetModuleFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID)
	{
		init(pFactory,DeviceID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceID	
	static CSysNetModuleIteratorByDeviceID *alloc(CSysNetModuleFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///���췽��
	CSysNetModuleIteratorByDeviceID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	DeviceID	
	void init(CSysNetModuleFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetModuleIteratorByDeviceID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetModule��������startFindByDeviceID�Ժ�endFindByDeviceID֮ǰ����
	///@return	��һ����������CSysNetModule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetModule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDeviceID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetModule * pByDeviceID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprIteratorByAll��һ���Ը澯���ʽ��Ϣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprIteratorByAll: public CSysNetEventExprIterator
{
	friend class CSysNetEventExprFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetEventExpr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetEventExpr *pSysNetEventExpr);

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
	CWriteableSysNetEventExpr m_compareObject;
	
	static CMemoryStack<CSysNetEventExprIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetEventExprIteratorByAll(CSysNetEventExprFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetEventExprIteratorByAll *alloc(CSysNetEventExprFactory *pFactory
		);

	///���췽��
	CSysNetEventExprIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetEventExprFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetEventExprIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetEventExpr��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetEventExpr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventExpr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeIteratorByAll��һ�����¼�����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeIteratorByAll: public CSysNetEventTypeIterator
{
	friend class CSysNetEventTypeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetEventType		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetEventType *pSysNetEventType);

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
	CWriteableSysNetEventType m_compareObject;
	
	static CMemoryStack<CSysNetEventTypeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetEventTypeIteratorByAll(CSysNetEventTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetEventTypeIteratorByAll *alloc(CSysNetEventTypeFactory *pFactory
		);

	///���췽��
	CSysNetEventTypeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetEventTypeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetEventTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetEventType��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeIteratorByAll��һ�����¼�������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeIteratorByAll: public CSysNetSubEventTypeIterator
{
	friend class CSysNetSubEventTypeFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetSubEventType		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetSubEventType *pSysNetSubEventType);

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
	CWriteableSysNetSubEventType m_compareObject;
	
	static CMemoryStack<CSysNetSubEventTypeIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetSubEventTypeIteratorByAll(CSysNetSubEventTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetSubEventTypeIteratorByAll *alloc(CSysNetSubEventTypeFactory *pFactory
		);

	///���췽��
	CSysNetSubEventTypeIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetSubEventTypeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetSubEventTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetSubEventType��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetSubEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubEventType *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelIteratorByAll��һ�����¼�����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelIteratorByAll: public CSysNetEventLevelIterator
{
	friend class CSysNetEventLevelFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetEventLevel		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetEventLevel *pSysNetEventLevel);

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
	CWriteableSysNetEventLevel m_compareObject;
	
	static CMemoryStack<CSysNetEventLevelIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetEventLevelIteratorByAll(CSysNetEventLevelFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetEventLevelIteratorByAll *alloc(CSysNetEventLevelFactory *pFactory
		);

	///���췽��
	CSysNetEventLevelIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetEventLevelFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetEventLevelIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetEventLevel��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetEventLevel������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventLevel *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskIteratorByAll��һ�������������������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskIteratorByAll: public CSysNetMonitorDeviceTaskIterator
{
	friend class CSysNetMonitorDeviceTaskFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorDeviceTask		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);

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
	CWriteableSysNetMonitorDeviceTask m_compareObject;
	
	static CMemoryStack<CSysNetMonitorDeviceTaskIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorDeviceTaskIteratorByAll(CSysNetMonitorDeviceTaskFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorDeviceTaskIteratorByAll *alloc(CSysNetMonitorDeviceTaskFactory *pFactory
		);

	///���췽��
	CSysNetMonitorDeviceTaskIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorDeviceTaskFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorDeviceTaskIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorDeviceTask��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorDeviceTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskIteratorByID��һ�������������������ʹ��ByID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskIteratorByID: public CSysNetMonitorDeviceTaskIterator
{
	friend class CSysNetMonitorDeviceTaskFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorDeviceTask		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);

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
	CWriteableSysNetMonitorDeviceTask m_compareObject;
	
	static CMemoryStack<CSysNetMonitorDeviceTaskIteratorByID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	CSysNetMonitorDeviceTaskIteratorByID(CSysNetMonitorDeviceTaskFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	static CSysNetMonitorDeviceTaskIteratorByID *alloc(CSysNetMonitorDeviceTaskFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///���췽��
	CSysNetMonitorDeviceTaskIteratorByID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	void init(CSysNetMonitorDeviceTaskFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorDeviceTaskIteratorByID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorDeviceTask��������startFindByID�Ժ�endFindByID֮ǰ����
	///@return	��һ����������CSysNetMonitorDeviceTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pByID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsIteratorByAll��һ��������ָ��ָ�꼯��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsIteratorByAll: public CSysNetMonitorTaskInstAttrsIterator
{
	friend class CSysNetMonitorTaskInstAttrsFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMonitorTaskInstAttrs		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);

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
	CWriteableSysNetMonitorTaskInstAttrs m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskInstAttrsIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMonitorTaskInstAttrsIteratorByAll(CSysNetMonitorTaskInstAttrsFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMonitorTaskInstAttrsIteratorByAll *alloc(CSysNetMonitorTaskInstAttrsFactory *pFactory
		);

	///���췽��
	CSysNetMonitorTaskInstAttrsIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMonitorTaskInstAttrsFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskInstAttrsIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMonitorTaskInstAttrs��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMonitorTaskInstAttrs������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineIteratorByAll��һ���Ի��߱�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineIteratorByAll: public CSysNetBaseLineIterator
{
	friend class CSysNetBaseLineFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetBaseLine		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetBaseLine *pSysNetBaseLine);

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
	CWriteableSysNetBaseLine m_compareObject;
	
	static CMemoryStack<CSysNetBaseLineIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetBaseLineIteratorByAll(CSysNetBaseLineFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetBaseLineIteratorByAll *alloc(CSysNetBaseLineFactory *pFactory
		);

	///���췽��
	CSysNetBaseLineIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetBaseLineFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetBaseLineIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetBaseLine��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetBaseLine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineIteratorByID��һ���Ի��߱�ʹ��ByID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineIteratorByID: public CSysNetBaseLineIterator
{
	friend class CSysNetBaseLineFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetBaseLine		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetBaseLine *pSysNetBaseLine);

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
	CWriteableSysNetBaseLine m_compareObject;
	
	static CMemoryStack<CSysNetBaseLineIteratorByID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	CSysNetBaseLineIteratorByID(CSysNetBaseLineFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	static CSysNetBaseLineIteratorByID *alloc(CSysNetBaseLineFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///���췽��
	CSysNetBaseLineIteratorByID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	void init(CSysNetBaseLineFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetBaseLineIteratorByID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetBaseLine��������startFindByID�Ժ�endFindByID֮ǰ����
	///@return	��һ����������CSysNetBaseLine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLine *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pByID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskIteratorByAll��һ���Ի��������ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskIteratorByAll: public CSysNetBaseLineTaskIterator
{
	friend class CSysNetBaseLineTaskFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetBaseLineTask		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetBaseLineTask *pSysNetBaseLineTask);

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
	CWriteableSysNetBaseLineTask m_compareObject;
	
	static CMemoryStack<CSysNetBaseLineTaskIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetBaseLineTaskIteratorByAll(CSysNetBaseLineTaskFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetBaseLineTaskIteratorByAll *alloc(CSysNetBaseLineTaskFactory *pFactory
		);

	///���췽��
	CSysNetBaseLineTaskIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetBaseLineTaskFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetBaseLineTaskIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetBaseLineTask��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetBaseLineTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIteratorByTime��һ���Ի�Ա��·״̬��Ϣ��ʹ��ByTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIteratorByTime: public CSysMdbNetPartyLinkStatusInfoIterator
{
	friend class CSysMdbNetPartyLinkStatusInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbNetPartyLinkStatusInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

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
	CWriteableSysMdbNetPartyLinkStatusInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbNetPartyLinkStatusInfoIteratorByTime(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbNetPartyLinkStatusInfoIteratorByTime *alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbNetPartyLinkStatusInfoIteratorByTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetPartyLinkStatusInfoIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbNetPartyLinkStatusInfo��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CSysMdbNetPartyLinkStatusInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIteratorByDsc��һ���Ի�Ա��·״̬��Ϣ��ʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIteratorByDsc: public CSysMdbNetPartyLinkStatusInfoIterator
{
	friend class CSysMdbNetPartyLinkStatusInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbNetPartyLinkStatusInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

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
	CWriteableSysMdbNetPartyLinkStatusInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbNetPartyLinkStatusInfoIteratorByDsc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbNetPartyLinkStatusInfoIteratorByDsc *alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbNetPartyLinkStatusInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetPartyLinkStatusInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbNetPartyLinkStatusInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbNetPartyLinkStatusInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIteratorByAll��һ���Ի�Ա��·״̬��Ϣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIteratorByAll: public CSysMdbNetPartyLinkStatusInfoIterator
{
	friend class CSysMdbNetPartyLinkStatusInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbNetPartyLinkStatusInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

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
	CWriteableSysMdbNetPartyLinkStatusInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbNetPartyLinkStatusInfoIteratorByAll(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbNetPartyLinkStatusInfoIteratorByAll *alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		);

	///���췽��
	CSysMdbNetPartyLinkStatusInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetPartyLinkStatusInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbNetPartyLinkStatusInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysMdbNetPartyLinkStatusInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoIteratorByAll��һ���Ի�ԱSDH��·��ϸ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoIteratorByAll: public CSysNetMemberSDHLineInfoIterator
{
	friend class CSysNetMemberSDHLineInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetMemberSDHLineInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);

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
	CWriteableSysNetMemberSDHLineInfo m_compareObject;
	
	static CMemoryStack<CSysNetMemberSDHLineInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetMemberSDHLineInfoIteratorByAll(CSysNetMemberSDHLineInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetMemberSDHLineInfoIteratorByAll *alloc(CSysNetMemberSDHLineInfoFactory *pFactory
		);

	///���췽��
	CSysNetMemberSDHLineInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetMemberSDHLineInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMemberSDHLineInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetMemberSDHLineInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetMemberSDHLineInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoIteratorByAll��һ����DDN��·��Ϣ��ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoIteratorByAll: public CSysNetDDNLinkInfoIterator
{
	friend class CSysNetDDNLinkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetDDNLinkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);

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
	CWriteableSysNetDDNLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetDDNLinkInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetDDNLinkInfoIteratorByAll(CSysNetDDNLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetDDNLinkInfoIteratorByAll *alloc(CSysNetDDNLinkInfoFactory *pFactory
		);

	///���췽��
	CSysNetDDNLinkInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetDDNLinkInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDDNLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetDDNLinkInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetDDNLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoIteratorByAll��һ���Էǻ�Ա��·ʹ����Ϣʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoIteratorByAll: public CSysNetPseudMemberLinkInfoIterator
{
	friend class CSysNetPseudMemberLinkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetPseudMemberLinkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);

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
	CWriteableSysNetPseudMemberLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetPseudMemberLinkInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetPseudMemberLinkInfoIteratorByAll(CSysNetPseudMemberLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetPseudMemberLinkInfoIteratorByAll *alloc(CSysNetPseudMemberLinkInfoFactory *pFactory
		);

	///���췽��
	CSysNetPseudMemberLinkInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetPseudMemberLinkInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPseudMemberLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetPseudMemberLinkInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetPseudMemberLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoIteratorByAll��һ����Զ���豸��Ϣʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoIteratorByAll: public CSysNetOuterDeviceInfoIterator
{
	friend class CSysNetOuterDeviceInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetOuterDeviceInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);

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
	CWriteableSysNetOuterDeviceInfo m_compareObject;
	
	static CMemoryStack<CSysNetOuterDeviceInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetOuterDeviceInfoIteratorByAll(CSysNetOuterDeviceInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetOuterDeviceInfoIteratorByAll *alloc(CSysNetOuterDeviceInfoFactory *pFactory
		);

	///���췽��
	CSysNetOuterDeviceInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetOuterDeviceInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetOuterDeviceInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetOuterDeviceInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetOuterDeviceInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoIteratorByAll��һ���Ա���ping���ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoIteratorByAll: public CSysLocalPingResultInfoIterator
{
	friend class CSysLocalPingResultInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysLocalPingResultInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysLocalPingResultInfo *pSysLocalPingResultInfo);

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
	CWriteableSysLocalPingResultInfo m_compareObject;
	
	static CMemoryStack<CSysLocalPingResultInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysLocalPingResultInfoIteratorByAll(CSysLocalPingResultInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysLocalPingResultInfoIteratorByAll *alloc(CSysLocalPingResultInfoFactory *pFactory
		);

	///���췽��
	CSysLocalPingResultInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysLocalPingResultInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysLocalPingResultInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysLocalPingResultInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysLocalPingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoIteratorByIDType��һ���Ա���ping���ʹ��ByIDType��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoIteratorByIDType: public CSysLocalPingResultInfoIterator
{
	friend class CSysLocalPingResultInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysLocalPingResultInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysLocalPingResultInfo *pSysLocalPingResultInfo);

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
	CWriteableSysLocalPingResultInfo m_compareObject;
	
	static CMemoryStack<CSysLocalPingResultInfoIteratorByIDType> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	CSysLocalPingResultInfoIteratorByIDType(CSysLocalPingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	static CSysLocalPingResultInfoIteratorByIDType *alloc(CSysLocalPingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///���췽��
	CSysLocalPingResultInfoIteratorByIDType(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	void init(CSysLocalPingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysLocalPingResultInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysLocalPingResultInfo��������startFindByIDType�Ժ�endFindByIDType֮ǰ����
	///@return	��һ����������CSysLocalPingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoIteratorByAll��һ����Զ��ping���ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoIteratorByAll: public CSysRomotePingResultInfoIterator
{
	friend class CSysRomotePingResultInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysRomotePingResultInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysRomotePingResultInfo *pSysRomotePingResultInfo);

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
	CWriteableSysRomotePingResultInfo m_compareObject;
	
	static CMemoryStack<CSysRomotePingResultInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysRomotePingResultInfoIteratorByAll(CSysRomotePingResultInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysRomotePingResultInfoIteratorByAll *alloc(CSysRomotePingResultInfoFactory *pFactory
		);

	///���췽��
	CSysRomotePingResultInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysRomotePingResultInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysRomotePingResultInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysRomotePingResultInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysRomotePingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoIteratorByIDType��һ����Զ��ping���ʹ��ByIDType��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoIteratorByIDType: public CSysRomotePingResultInfoIterator
{
	friend class CSysRomotePingResultInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysRomotePingResultInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysRomotePingResultInfo *pSysRomotePingResultInfo);

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
	CWriteableSysRomotePingResultInfo m_compareObject;
	
	static CMemoryStack<CSysRomotePingResultInfoIteratorByIDType> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	CSysRomotePingResultInfoIteratorByIDType(CSysRomotePingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	static CSysRomotePingResultInfoIteratorByIDType *alloc(CSysRomotePingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///���췽��
	CSysRomotePingResultInfoIteratorByIDType(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ID	
	void init(CSysRomotePingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysRomotePingResultInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysRomotePingResultInfo��������startFindByIDType�Ժ�endFindByIDType֮ǰ����
	///@return	��һ����������CSysRomotePingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByIDType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesIteratorByAll��һ���Ի�Աϯλ����״̬ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesIteratorByAll: public CSysParticTradeOrderStatesIterator
{
	friend class CSysParticTradeOrderStatesFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysParticTradeOrderStates		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysParticTradeOrderStates *pSysParticTradeOrderStates);

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
	CWriteableSysParticTradeOrderStates m_compareObject;
	
	static CMemoryStack<CSysParticTradeOrderStatesIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysParticTradeOrderStatesIteratorByAll(CSysParticTradeOrderStatesFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysParticTradeOrderStatesIteratorByAll *alloc(CSysParticTradeOrderStatesFactory *pFactory
		);

	///���췽��
	CSysParticTradeOrderStatesIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysParticTradeOrderStatesFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysParticTradeOrderStatesIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysParticTradeOrderStates��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysParticTradeOrderStates������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesIteratorByUserID��һ���Ի�Աϯλ����״̬ʹ��ByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesIteratorByUserID: public CSysParticTradeOrderStatesIterator
{
	friend class CSysParticTradeOrderStatesFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysParticTradeOrderStates		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysParticTradeOrderStates *pSysParticTradeOrderStates);

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
	CWriteableSysParticTradeOrderStates m_compareObject;
	
	static CMemoryStack<CSysParticTradeOrderStatesIteratorByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	CSysParticTradeOrderStatesIteratorByUserID(CSysParticTradeOrderStatesFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyUserIDType& UserID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ParticipantID,UserID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysParticTradeOrderStatesIteratorByUserID *alloc(CSysParticTradeOrderStatesFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyUserIDType& UserID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysParticTradeOrderStatesIteratorByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysParticTradeOrderStatesFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyUserIDType& UserID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysParticTradeOrderStatesIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysParticTradeOrderStates��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CSysParticTradeOrderStates������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorByHostName��һ����ϵͳ·����Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorByHostName: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbRouterInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbRouterInfoIteratorByHostName(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbRouterInfoIteratorByHostName *alloc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbRouterInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbRouterInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbRouterInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorByDsc��һ����ϵͳ·����Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorByDsc: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbRouterInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbRouterInfoIteratorByDsc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbRouterInfoIteratorByDsc *alloc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbRouterInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbRouterInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbRouterInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorBytheAll��һ����ϵͳ·����Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorBytheAll: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbRouterInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbRouterInfoIteratorBytheAll(CSysMdbRouterInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbRouterInfoIteratorBytheAll *alloc(CSysMdbRouterInfoFactory *pFactory
		);

	///���췽��
	CSysMdbRouterInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbRouterInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbRouterInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbRouterInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorByDataDelete��һ����ϵͳ·����Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorByDataDelete: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbRouterInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbRouterInfoIteratorByDataDelete(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbRouterInfoIteratorByDataDelete *alloc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbRouterInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbRouterInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbRouterInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorByHostName��һ���Դ���I/O��Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorByHostName: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDiskIO		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDiskIOIteratorByHostName(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDiskIOIteratorByHostName *alloc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbDiskIOIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDiskIOIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDiskIO��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorByDsc��һ���Դ���I/O��Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorByDsc: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDiskIO		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbDiskIOIteratorByDsc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbDiskIOIteratorByDsc *alloc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbDiskIOIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDiskIOIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDiskIO��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorBytheAll��һ���Դ���I/O��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorBytheAll: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDiskIO		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbDiskIOIteratorBytheAll(CSysMdbDiskIOFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbDiskIOIteratorBytheAll *alloc(CSysMdbDiskIOFactory *pFactory
		);

	///���췽��
	CSysMdbDiskIOIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbDiskIOFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDiskIOIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDiskIO��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorByDataDelete��һ���Դ���I/O��Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorByDataDelete: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbDiskIO		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDiskIOIteratorByDataDelete(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDiskIOIteratorByDataDelete *alloc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbDiskIOIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDiskIOIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbDiskIO��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorByHostName��һ����ϵͳ״̬��Ϣʹ��ByHostName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorByHostName: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbStatInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorByHostName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbStatInfoIteratorByHostName(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbStatInfoIteratorByHostName *alloc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbStatInfoIteratorByHostName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbStatInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbStatInfo��������startFindByHostName�Ժ�endFindByHostName֮ǰ����
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByHostName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorByDsc��һ����ϵͳ״̬��Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorByDsc: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbStatInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbStatInfoIteratorByDsc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbStatInfoIteratorByDsc *alloc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbStatInfoIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbStatInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbStatInfo��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorBytheAll��һ����ϵͳ״̬��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorBytheAll: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbStatInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbStatInfoIteratorBytheAll(CSysMdbStatInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbStatInfoIteratorBytheAll *alloc(CSysMdbStatInfoFactory *pFactory
		);

	///���췽��
	CSysMdbStatInfoIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbStatInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbStatInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbStatInfo��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorByDataDelete��һ����ϵͳ״̬��Ϣʹ��ByDataDelete��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorByDataDelete: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbStatInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorByDataDelete> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbStatInfoIteratorByDataDelete(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbStatInfoIteratorByDataDelete *alloc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbStatInfoIteratorByDataDelete(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbStatInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbStatInfo��������startFindByDataDelete�Ժ�endFindByDataDelete֮ǰ����
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDataDelete ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex��һ���Խ���ϵͳǰ�ñ�����Ӧ��Ϣʹ��ByFrontIndex��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex: public CSysMdbTradeFrontOrderRttStatIterator
{
	friend class CSysMdbTradeFrontOrderRttStatFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTradeFrontOrderRttStat		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

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
	CWriteableSysMdbTradeFrontOrderRttStat m_compareObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	static CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex *alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///���췽��
	CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ObjectID	
	///@param	MonTime	
	void init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTradeFrontOrderRttStat��������startFindByFrontIndex�Ժ�endFindByFrontIndex֮ǰ����
	///@return	��һ����������CSysMdbTradeFrontOrderRttStat������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByFrontIndex ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pByFrontIndex,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIteratorByDsc��һ���Խ���ϵͳǰ�ñ�����Ӧ��Ϣʹ��ByDsc��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIteratorByDsc: public CSysMdbTradeFrontOrderRttStatIterator
{
	friend class CSysMdbTradeFrontOrderRttStatFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTradeFrontOrderRttStat		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

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
	CWriteableSysMdbTradeFrontOrderRttStat m_compareObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorByDsc> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	CSysMdbTradeFrontOrderRttStatIteratorByDsc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	static CSysMdbTradeFrontOrderRttStatIteratorByDsc *alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///���췽��
	CSysMdbTradeFrontOrderRttStatIteratorByDsc(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SubcriberID	
	void init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTradeFrontOrderRttStatIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTradeFrontOrderRttStat��������startFindByDsc�Ժ�endFindByDsc֮ǰ����
	///@return	��һ����������CSysMdbTradeFrontOrderRttStat������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDsc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIteratorBytheAll��һ���Խ���ϵͳǰ�ñ�����Ӧ��Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIteratorBytheAll: public CSysMdbTradeFrontOrderRttStatIterator
{
	friend class CSysMdbTradeFrontOrderRttStatFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMdbTradeFrontOrderRttStat		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

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
	CWriteableSysMdbTradeFrontOrderRttStat m_compareObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMdbTradeFrontOrderRttStatIteratorBytheAll(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMdbTradeFrontOrderRttStatIteratorBytheAll *alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		);

	///���췽��
	CSysMdbTradeFrontOrderRttStatIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTradeFrontOrderRttStatIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMdbTradeFrontOrderRttStat��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMdbTradeFrontOrderRttStat������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusIteratorByActionTime��һ���Ժ�Լ״̬�л�ʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusIteratorByActionTime: public CSysInstrumentStatusIterator
{
	friend class CSysInstrumentStatusFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysInstrumentStatus		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysInstrumentStatus *pSysInstrumentStatus);

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
	CWriteableSysInstrumentStatus m_compareObject;
	
	static CMemoryStack<CSysInstrumentStatusIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EnterTime	
	CSysInstrumentStatusIteratorByActionTime(CSysInstrumentStatusFactory *pFactory
		,const CReadOnlyTimeType& EnterTime)
	{
		init(pFactory,EnterTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EnterTime	
	static CSysInstrumentStatusIteratorByActionTime *alloc(CSysInstrumentStatusFactory *pFactory
		,const CReadOnlyTimeType& EnterTime);

	///���췽��
	CSysInstrumentStatusIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	EnterTime	
	void init(CSysInstrumentStatusFactory *pFactory
		,const CReadOnlyTimeType& EnterTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysInstrumentStatusIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysInstrumentStatus��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusIteratorBytheAll��һ���Ժ�Լ״̬�л�ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusIteratorBytheAll: public CSysInstrumentStatusIterator
{
	friend class CSysInstrumentStatusFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysInstrumentStatus		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysInstrumentStatus *pSysInstrumentStatus);

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
	CWriteableSysInstrumentStatus m_compareObject;
	
	static CMemoryStack<CSysInstrumentStatusIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysInstrumentStatusIteratorBytheAll(CSysInstrumentStatusFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysInstrumentStatusIteratorBytheAll *alloc(CSysInstrumentStatusFactory *pFactory
		);

	///���췽��
	CSysInstrumentStatusIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysInstrumentStatusFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysInstrumentStatusIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysInstrumentStatus��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrIteratorByActionTime��һ���Ժ�Լ���׽���Ϣʹ��ByActionTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrIteratorByActionTime: public CSysCurrTradingSegmentAttrIterator
{
	friend class CSysCurrTradingSegmentAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysCurrTradingSegmentAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);

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
	CWriteableSysCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CSysCurrTradingSegmentAttrIteratorByActionTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	StartTime	
	CSysCurrTradingSegmentAttrIteratorByActionTime(CSysCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime)
	{
		init(pFactory,StartTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	StartTime	
	static CSysCurrTradingSegmentAttrIteratorByActionTime *alloc(CSysCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///���췽��
	CSysCurrTradingSegmentAttrIteratorByActionTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	StartTime	
	void init(CSysCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysCurrTradingSegmentAttrIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysCurrTradingSegmentAttr��������startFindByActionTime�Ժ�endFindByActionTime֮ǰ����
	///@return	��һ����������CSysCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByActionTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrIteratorBytheAll��һ���Ժ�Լ���׽���Ϣʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrIteratorBytheAll: public CSysCurrTradingSegmentAttrIterator
{
	friend class CSysCurrTradingSegmentAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysCurrTradingSegmentAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);

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
	CWriteableSysCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CSysCurrTradingSegmentAttrIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysCurrTradingSegmentAttrIteratorBytheAll(CSysCurrTradingSegmentAttrFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysCurrTradingSegmentAttrIteratorBytheAll *alloc(CSysCurrTradingSegmentAttrFactory *pFactory
		);

	///���췽��
	CSysCurrTradingSegmentAttrIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysCurrTradingSegmentAttrFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysCurrTradingSegmentAttrIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysCurrTradingSegmentAttr��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIteratorByPayTime��һ���Ի�Ա��·���ñ�ʹ��ByPayTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIteratorByPayTime: public CSysMemberLinkCostIterator
{
	friend class CSysMemberLinkCostFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMemberLinkCost		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMemberLinkCost *pSysMemberLinkCost);

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
	CWriteableSysMemberLinkCost m_compareObject;
	
	static CMemoryStack<CSysMemberLinkCostIteratorByPayTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	Pay_Date	
	CSysMemberLinkCostIteratorByPayTime(CSysMemberLinkCostFactory *pFactory
		,const CReadOnlyCfgNameType& Pay_Date)
	{
		init(pFactory,Pay_Date);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	Pay_Date	
	static CSysMemberLinkCostIteratorByPayTime *alloc(CSysMemberLinkCostFactory *pFactory
		,const CReadOnlyCfgNameType& Pay_Date);

	///���췽��
	CSysMemberLinkCostIteratorByPayTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	Pay_Date	
	void init(CSysMemberLinkCostFactory *pFactory
		,const CReadOnlyCfgNameType& Pay_Date);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMemberLinkCostIteratorByPayTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMemberLinkCost��������startFindByPayTime�Ժ�endFindByPayTime֮ǰ����
	///@return	��һ����������CSysMemberLinkCost������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMemberLinkCost *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByPayTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pByPayTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIteratorBytheAll��һ���Ի�Ա��·���ñ�ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIteratorBytheAll: public CSysMemberLinkCostIterator
{
	friend class CSysMemberLinkCostFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMemberLinkCost		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMemberLinkCost *pSysMemberLinkCost);

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
	CWriteableSysMemberLinkCost m_compareObject;
	
	static CMemoryStack<CSysMemberLinkCostIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMemberLinkCostIteratorBytheAll(CSysMemberLinkCostFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMemberLinkCostIteratorBytheAll *alloc(CSysMemberLinkCostFactory *pFactory
		);

	///���췽��
	CSysMemberLinkCostIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMemberLinkCostFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMemberLinkCostIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMemberLinkCost��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysMemberLinkCost������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMemberLinkCost *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIteratorByAll��һ���Ի�Ա��·���ñ�ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIteratorByAll: public CSysMemberLinkCostIterator
{
	friend class CSysMemberLinkCostFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysMemberLinkCost		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysMemberLinkCost *pSysMemberLinkCost);

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
	CWriteableSysMemberLinkCost m_compareObject;
	
	static CMemoryStack<CSysMemberLinkCostIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysMemberLinkCostIteratorByAll(CSysMemberLinkCostFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysMemberLinkCostIteratorByAll *alloc(CSysMemberLinkCostFactory *pFactory
		);

	///���췽��
	CSysMemberLinkCostIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysMemberLinkCostFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMemberLinkCostIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysMemberLinkCost��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysMemberLinkCost������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMemberLinkCost *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIteratorByLineName��һ���Ի�Ա��·�����ʹ��ByLineName��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIteratorByLineName: public CSysNetPartylinkMonthlyRentIterator
{
	friend class CSysNetPartylinkMonthlyRentFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetPartylinkMonthlyRent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

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
	CWriteableSysNetPartylinkMonthlyRent m_compareObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentIteratorByLineName> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LineName	
	CSysNetPartylinkMonthlyRentIteratorByLineName(CSysNetPartylinkMonthlyRentFactory *pFactory
		,const CReadOnlyParticipantNameType& LineName)
	{
		init(pFactory,LineName);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LineName	
	static CSysNetPartylinkMonthlyRentIteratorByLineName *alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		,const CReadOnlyParticipantNameType& LineName);

	///���췽��
	CSysNetPartylinkMonthlyRentIteratorByLineName(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LineName	
	void init(CSysNetPartylinkMonthlyRentFactory *pFactory
		,const CReadOnlyParticipantNameType& LineName);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartylinkMonthlyRentIteratorByLineName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetPartylinkMonthlyRent��������startFindByLineName�Ժ�endFindByLineName֮ǰ����
	///@return	��һ����������CSysNetPartylinkMonthlyRent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByLineName ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pByLineName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIteratorBytheAll��һ���Ի�Ա��·�����ʹ��BytheAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIteratorBytheAll: public CSysNetPartylinkMonthlyRentIterator
{
	friend class CSysNetPartylinkMonthlyRentFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetPartylinkMonthlyRent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

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
	CWriteableSysNetPartylinkMonthlyRent m_compareObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentIteratorBytheAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetPartylinkMonthlyRentIteratorBytheAll(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetPartylinkMonthlyRentIteratorBytheAll *alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///���췽��
	CSysNetPartylinkMonthlyRentIteratorBytheAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartylinkMonthlyRentIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetPartylinkMonthlyRent��������startFindBytheAll�Ժ�endFindBytheAll֮ǰ����
	///@return	��һ����������CSysNetPartylinkMonthlyRent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBytheAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIteratorByAll��һ���Ի�Ա��·�����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIteratorByAll: public CSysNetPartylinkMonthlyRentIterator
{
	friend class CSysNetPartylinkMonthlyRentFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetPartylinkMonthlyRent		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

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
	CWriteableSysNetPartylinkMonthlyRent m_compareObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetPartylinkMonthlyRentIteratorByAll(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetPartylinkMonthlyRentIteratorByAll *alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///���췽��
	CSysNetPartylinkMonthlyRentIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartylinkMonthlyRentIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetPartylinkMonthlyRent��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetPartylinkMonthlyRent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoIteratorByAll��һ���Ի�Ա��·�����ʹ��ByAll��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoIteratorByAll: public CSysNetNonPartyLinkInfoIterator
{
	friend class CSysNetNonPartyLinkInfoFactory;
private:
	///���˶����Ƿ���������
	///@param	pSysNetNonPartyLinkInfo		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);

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
	CWriteableSysNetNonPartyLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetNonPartyLinkInfoIteratorByAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CSysNetNonPartyLinkInfoIteratorByAll(CSysNetNonPartyLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CSysNetNonPartyLinkInfoIteratorByAll *alloc(CSysNetNonPartyLinkInfoFactory *pFactory
		);

	///���췽��
	CSysNetNonPartyLinkInfoIteratorByAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CSysNetNonPartyLinkInfoFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetNonPartyLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSysNetNonPartyLinkInfo��������startFindByAll�Ժ�endFindByAll֮ǰ����
	///@return	��һ����������CSysNetNonPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

#endif
