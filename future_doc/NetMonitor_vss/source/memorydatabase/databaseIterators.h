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
///CSGDataSyncStatusIteratorStartBySettlementGroupID��һ���Խ���������ͬ��״̬ʹ��StartBySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusIteratorStartBySettlementGroupID: public CSGDataSyncStatusIterator
{
	friend class CSGDataSyncStatusFactory;
private:
	///���˶����Ƿ���������
	///@param	pSGDataSyncStatus		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CSGDataSyncStatus *pSGDataSyncStatus);

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
	CWriteableSGDataSyncStatus m_compareObject;
	
	static CMemoryStack<CSGDataSyncStatusIteratorStartBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CSGDataSyncStatusIteratorStartBySettlementGroupID(CSGDataSyncStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CSGDataSyncStatusIteratorStartBySettlementGroupID *alloc(CSGDataSyncStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CSGDataSyncStatusIteratorStartBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CSGDataSyncStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSGDataSyncStatusIteratorStartBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CSGDataSyncStatus��������startFindStartBySettlementGroupID�Ժ�endFindStartBySettlementGroupID֮ǰ����
	///@return	��һ����������CSGDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSGDataSyncStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pStartBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};






/////////////////////////////////////////////////////////////////////////
///CMarketProductIteratorByProductID��һ�����г���Ʒ����ʹ��ByProductID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductIteratorByProductID: public CMarketProductIterator
{
	friend class CMarketProductFactory;
private:
	///���˶����Ƿ���������
	///@param	pMarketProduct		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMarketProduct *pMarketProduct);

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
	CWriteableMarketProduct m_compareObject;
	
	static CMemoryStack<CMarketProductIteratorByProductID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductID	��Ʒ����
	CMarketProductIteratorByProductID(CMarketProductFactory *pFactory
		,const CReadOnlyProductIDType& ProductID)
	{
		init(pFactory,ProductID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductID	��Ʒ����
	static CMarketProductIteratorByProductID *alloc(CMarketProductFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///���췽��
	CMarketProductIteratorByProductID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductID	��Ʒ����
	void init(CMarketProductFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketProductIteratorByProductID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMarketProduct��������startFindByProductID�Ժ�endFindByProductID֮ǰ����
	///@return	��һ����������CMarketProduct������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProduct *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByProductID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProduct * pByProductID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupIteratorByProductGroupID��һ�����г���Ʒ�����ʹ��ByProductGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupIteratorByProductGroupID: public CMarketProductGroupIterator
{
	friend class CMarketProductGroupFactory;
private:
	///���˶����Ƿ���������
	///@param	pMarketProductGroup		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMarketProductGroup *pMarketProductGroup);

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
	CWriteableMarketProductGroup m_compareObject;
	
	static CMemoryStack<CMarketProductGroupIteratorByProductGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ�����
	CMarketProductGroupIteratorByProductGroupID(CMarketProductGroupFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID)
	{
		init(pFactory,ProductGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ�����
	static CMarketProductGroupIteratorByProductGroupID *alloc(CMarketProductGroupFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///���췽��
	CMarketProductGroupIteratorByProductGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ�����
	void init(CMarketProductGroupFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketProductGroupIteratorByProductGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMarketProductGroup��������startFindByProductGroupID�Ժ�endFindByProductGroupID֮ǰ����
	///@return	��һ����������CMarketProductGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProductGroup *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByProductGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pByProductGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicIteratorByMarketID��һ������������ʹ��ByMarketID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicIteratorByMarketID: public CMarketDataTopicIterator
{
	friend class CMarketDataTopicFactory;
private:
	///���˶����Ƿ���������
	///@param	pMarketDataTopic		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMarketDataTopic *pMarketDataTopic);

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
	CWriteableMarketDataTopic m_compareObject;
	
	static CMemoryStack<CMarketDataTopicIteratorByMarketID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MarketID	�г�����
	CMarketDataTopicIteratorByMarketID(CMarketDataTopicFactory *pFactory
		,const CReadOnlyMarketIDType& MarketID)
	{
		init(pFactory,MarketID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MarketID	�г�����
	static CMarketDataTopicIteratorByMarketID *alloc(CMarketDataTopicFactory *pFactory
		,const CReadOnlyMarketIDType& MarketID);

	///���췽��
	CMarketDataTopicIteratorByMarketID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MarketID	�г�����
	void init(CMarketDataTopicFactory *pFactory
		,const CReadOnlyMarketIDType& MarketID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataTopicIteratorByMarketID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMarketDataTopic��������startFindByMarketID�Ժ�endFindByMarketID֮ǰ����
	///@return	��һ����������CMarketDataTopic������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataTopic *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByMarketID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pByMarketID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeIteratorByPartID��һ���Ի�Ա�����г�ʹ��ByPartID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeIteratorByPartID: public CPartTopicSubscribeIterator
{
	friend class CPartTopicSubscribeFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartTopicSubscribe		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartTopicSubscribe *pPartTopicSubscribe);

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
	CWriteablePartTopicSubscribe m_compareObject;
	
	static CMemoryStack<CPartTopicSubscribeIteratorByPartID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա����
	CPartTopicSubscribeIteratorByPartID(CPartTopicSubscribeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա����
	static CPartTopicSubscribeIteratorByPartID *alloc(CPartTopicSubscribeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CPartTopicSubscribeIteratorByPartID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա����
	void init(CPartTopicSubscribeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartTopicSubscribeIteratorByPartID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartTopicSubscribe��������startFindByPartID�Ժ�endFindByPartID֮ǰ����
	///@return	��һ����������CPartTopicSubscribe������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartTopicSubscribe *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByPartID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pByPartID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantIteratorStartByParticipantID��һ���Ի�Աʹ��StartByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantIteratorStartByParticipantID: public CParticipantIterator
{
	friend class CParticipantFactory;
private:
	///���˶����Ƿ���������
	///@param	pParticipant		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CParticipant *pParticipant);

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
	CWriteableParticipant m_compareObject;
	
	static CMemoryStack<CParticipantIteratorStartByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	CParticipantIteratorStartByParticipantID(CParticipantFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	static CParticipantIteratorStartByParticipantID *alloc(CParticipantFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CParticipantIteratorStartByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	void init(CParticipantFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CParticipantIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CParticipant��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CParticipant������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CParticipant *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableParticipant * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserIteratorStartByUserID��һ�����û�ʹ��StartByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIteratorStartByUserID: public CUserIterator
{
	friend class CUserFactory;
private:
	///���˶����Ƿ���������
	///@param	pUser		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CUser *pUser);

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
	CWriteableUser m_compareObject;
	
	static CMemoryStack<CUserIteratorStartByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û����
	CUserIteratorStartByUserID(CUserFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û����
	static CUserIteratorStartByUserID *alloc(CUserFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///���췽��
	CUserIteratorStartByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û����
	void init(CUserFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserIteratorStartByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CUser��������startFindStartByUserID�Ժ�endFindStartByUserID֮ǰ����
	///@return	��һ����������CUser������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUser *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUser * pStartByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserIPIteratorByUserID��һ���Խ���ԱIP��ַʹ��ByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPIteratorByUserID: public CUserIPIterator
{
	friend class CUserIPFactory;
private:
	///���˶����Ƿ���������
	///@param	pUserIP		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CUserIP *pUserIP);

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
	CWriteableUserIP m_compareObject;
	
	static CMemoryStack<CUserIPIteratorByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û����
	CUserIPIteratorByUserID(CUserIPFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û����
	static CUserIPIteratorByUserID *alloc(CUserIPFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///���췽��
	CUserIPIteratorByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û����
	void init(CUserIPFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserIPIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CUserIP��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CUserIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserIP *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserIP * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientIteratorStartByParticipant��һ���Ի�Ա�ͻ���ϵʹ��StartByParticipant��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientIteratorStartByParticipant: public CPartClientIterator
{
	friend class CPartClientFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartClient		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartClient *pPartClient);

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
	CWriteablePartClient m_compareObject;
	
	static CMemoryStack<CPartClientIteratorStartByParticipant> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CPartClientIteratorStartByParticipant(CPartClientFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CPartClientIteratorStartByParticipant *alloc(CPartClientFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CPartClientIteratorStartByParticipant(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CPartClientFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientIteratorStartByParticipant(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartClient��������startFindStartByParticipant�Ժ�endFindStartByParticipant֮ǰ����
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient * pStartByParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartClientIteratorStartByClient��һ���Ի�Ա�ͻ���ϵʹ��StartByClient��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientIteratorStartByClient: public CPartClientIterator
{
	friend class CPartClientFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartClient		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartClient *pPartClient);

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
	CWriteablePartClient m_compareObject;
	
	static CMemoryStack<CPartClientIteratorStartByClient> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	CPartClientIteratorStartByClient(CPartClientFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	static CPartClientIteratorStartByClient *alloc(CPartClientFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///���췽��
	CPartClientIteratorStartByClient(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	void init(CPartClientFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientIteratorStartByClient(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartClient��������startFindStartByClient�Ժ�endFindStartByClient֮ǰ����
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient * pStartByClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};




/////////////////////////////////////////////////////////////////////////
///CAccountIteratorStartByParticipantID��һ�����ʽ��˻�ʹ��StartByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountIteratorStartByParticipantID: public CAccountIterator
{
	friend class CAccountFactory;
private:
	///���˶����Ƿ���������
	///@param	pAccount		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CAccount *pAccount);

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
	CWriteableAccount m_compareObject;
	
	static CMemoryStack<CAccountIteratorStartByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	CAccountIteratorStartByParticipantID(CAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	static CAccountIteratorStartByParticipantID *alloc(CAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CAccountIteratorStartByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	void init(CAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CAccountIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CAccount��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAccount * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataLogIteratorByMarketDataLogNo��һ����������ˮʹ��ByMarketDataLogNo��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogIteratorByMarketDataLogNo: public CMarketDataLogIterator
{
	friend class CMarketDataLogFactory;
private:
	///���˶����Ƿ���������
	///@param	pMarketDataLog		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMarketDataLog *pMarketDataLog);

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
	CWriteableMarketDataLog m_compareObject;
	
	static CMemoryStack<CMarketDataLogIteratorByMarketDataLogNo> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MarketDataLogNo	������ˮ���
	CMarketDataLogIteratorByMarketDataLogNo(CMarketDataLogFactory *pFactory
		,const CReadOnlySequenceNoType& MarketDataLogNo)
	{
		init(pFactory,MarketDataLogNo);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MarketDataLogNo	������ˮ���
	static CMarketDataLogIteratorByMarketDataLogNo *alloc(CMarketDataLogFactory *pFactory
		,const CReadOnlySequenceNoType& MarketDataLogNo);

	///���췽��
	CMarketDataLogIteratorByMarketDataLogNo(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	MarketDataLogNo	������ˮ���
	void init(CMarketDataLogFactory *pFactory
		,const CReadOnlySequenceNoType& MarketDataLogNo);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataLogIteratorByMarketDataLogNo(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMarketDataLog��������startFindByMarketDataLogNo�Ժ�endFindByMarketDataLogNo֮ǰ����
	///@return	��һ����������CMarketDataLog������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataLog *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByMarketDataLogNo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataLog * pByMarketDataLogNo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionIteratorByFrontID��һ���Խ���Ա���߻Ựʹ��ByFrontID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionIteratorByFrontID: public CUserSessionIterator
{
	friend class CUserSessionFactory;
private:
	///���˶����Ƿ���������
	///@param	pUserSession		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CUserSession *pUserSession);

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
	CWriteableUserSession m_compareObject;
	
	static CMemoryStack<CUserSessionIteratorByFrontID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	FrontID	ǰ�ñ��
	CUserSessionIteratorByFrontID(CUserSessionFactory *pFactory
		,const CReadOnlyFrontIDType& FrontID)
	{
		init(pFactory,FrontID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	FrontID	ǰ�ñ��
	static CUserSessionIteratorByFrontID *alloc(CUserSessionFactory *pFactory
		,const CReadOnlyFrontIDType& FrontID);

	///���췽��
	CUserSessionIteratorByFrontID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	FrontID	ǰ�ñ��
	void init(CUserSessionFactory *pFactory
		,const CReadOnlyFrontIDType& FrontID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserSessionIteratorByFrontID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CUserSession��������startFindByFrontID�Ժ�endFindByFrontID֮ǰ����
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByFrontID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserSession * pByFrontID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CUserSessionIteratorStartByUserID��һ���Խ���Ա���߻Ựʹ��StartByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionIteratorStartByUserID: public CUserSessionIterator
{
	friend class CUserSessionFactory;
private:
	///���˶����Ƿ���������
	///@param	pUserSession		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CUserSession *pUserSession);

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
	CWriteableUserSession m_compareObject;
	
	static CMemoryStack<CUserSessionIteratorStartByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û���
	CUserSessionIteratorStartByUserID(CUserSessionFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û���
	static CUserSessionIteratorStartByUserID *alloc(CUserSessionFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///���췽��
	CUserSessionIteratorStartByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û���
	void init(CUserSessionFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserSessionIteratorStartByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CUserSession��������startFindStartByUserID�Ժ�endFindStartByUserID֮ǰ����
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserSession *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserSession * pStartByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};







/////////////////////////////////////////////////////////////////////////
///CBulletinIteratorStartByBulletinID��һ���Թ�����Ϣʹ��StartByBulletinID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinIteratorStartByBulletinID: public CBulletinIterator
{
	friend class CBulletinFactory;
private:
	///���˶����Ƿ���������
	///@param	pBulletin		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CBulletin *pBulletin);

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
	CWriteableBulletin m_compareObject;
	
	static CMemoryStack<CBulletinIteratorStartByBulletinID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	BulletinID	������
	CBulletinIteratorStartByBulletinID(CBulletinFactory *pFactory
		,const CReadOnlyBulletinIDType& BulletinID)
	{
		init(pFactory,BulletinID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	BulletinID	������
	static CBulletinIteratorStartByBulletinID *alloc(CBulletinFactory *pFactory
		,const CReadOnlyBulletinIDType& BulletinID);

	///���췽��
	CBulletinIteratorStartByBulletinID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	BulletinID	������
	void init(CBulletinFactory *pFactory
		,const CReadOnlyBulletinIDType& BulletinID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBulletinIteratorStartByBulletinID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CBulletin��������startFindStartByBulletinID�Ժ�endFindStartByBulletinID֮ǰ����
	///@return	��һ����������CBulletin������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBulletin *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByBulletinID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBulletin * pStartByBulletinID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyIteratorBySettlementGroupID��һ��������䶯ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyIteratorBySettlementGroupID: public CMarketDataModifyIterator
{
	friend class CMarketDataModifyFactory;
private:
	///���˶����Ƿ���������
	///@param	pMarketDataModify		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMarketDataModify *pMarketDataModify);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CMarketDataModify *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CMarketDataModify *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableMarketDataModify m_compareObject;
	
	static CMemoryStack<CMarketDataModifyIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CMarketDataModifyIteratorBySettlementGroupID(CMarketDataModifyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CMarketDataModifyIteratorBySettlementGroupID *alloc(CMarketDataModifyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CMarketDataModifyIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CMarketDataModifyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataModifyIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMarketDataModify��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CMarketDataModify������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataModify *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataModify * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataIteratorBySettlementGroupID��һ�����������ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataIteratorBySettlementGroupID: public CDepthMarketDataIterator
{
	friend class CDepthMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pDepthMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CDepthMarketData *pDepthMarketData);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CDepthMarketData *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CDepthMarketData *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableDepthMarketData m_compareObject;
	
	static CMemoryStack<CDepthMarketDataIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CDepthMarketDataIteratorBySettlementGroupID(CDepthMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CDepthMarketDataIteratorBySettlementGroupID *alloc(CDepthMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CDepthMarketDataIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CDepthMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDepthMarketDataIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CDepthMarketData��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CDepthMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketData * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIteratorByTopicID��һ���Է���������ʹ��ByTopicID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIteratorByTopicID: public CTopicMarketDataIterator
{
	friend class CTopicMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pTopicMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTopicMarketData *pTopicMarketData);

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
	CWriteableTopicMarketData m_compareObject;
	
	static CMemoryStack<CTopicMarketDataIteratorByTopicID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TopicID	�������
	CTopicMarketDataIteratorByTopicID(CTopicMarketDataFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID)
	{
		init(pFactory,TopicID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TopicID	�������
	static CTopicMarketDataIteratorByTopicID *alloc(CTopicMarketDataFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID);

	///���췽��
	CTopicMarketDataIteratorByTopicID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TopicID	�������
	void init(CTopicMarketDataFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataIteratorByTopicID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTopicMarketData��������startFindByTopicID�Ժ�endFindByTopicID֮ǰ����
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTopicID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketData * pByTopicID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIteratorByInstrumentID��һ���Է���������ʹ��ByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIteratorByInstrumentID: public CTopicMarketDataIterator
{
	friend class CTopicMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pTopicMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTopicMarketData *pTopicMarketData);

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
	CWriteableTopicMarketData m_compareObject;
	
	static CMemoryStack<CTopicMarketDataIteratorByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	CTopicMarketDataIteratorByInstrumentID(CTopicMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	static CTopicMarketDataIteratorByInstrumentID *alloc(CTopicMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CTopicMarketDataIteratorByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	void init(CTopicMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTopicMarketData��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketData * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIteratorBySettlementGroupID��һ���Է���������ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIteratorBySettlementGroupID: public CTopicMarketDataIterator
{
	friend class CTopicMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pTopicMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTopicMarketData *pTopicMarketData);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CTopicMarketData *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CTopicMarketData *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableTopicMarketData m_compareObject;
	
	static CMemoryStack<CTopicMarketDataIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CTopicMarketDataIteratorBySettlementGroupID(CTopicMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CTopicMarketDataIteratorBySettlementGroupID *alloc(CTopicMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CTopicMarketDataIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CTopicMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTopicMarketData��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketData * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionIteratorByTopicAndVersion��һ���Է������������ʹ��ByTopicAndVersion��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionIteratorByTopicAndVersion: public CTopicMarketDataVersionIterator
{
	friend class CTopicMarketDataVersionFactory;
private:
	///���˶����Ƿ���������
	///@param	pTopicMarketDataVersion		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTopicMarketDataVersion *pTopicMarketDataVersion);

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
	CWriteableTopicMarketDataVersion m_compareObject;
	
	static CMemoryStack<CTopicMarketDataVersionIteratorByTopicAndVersion> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TopicID	�������
	///@param	Version	���հ汾
	CTopicMarketDataVersionIteratorByTopicAndVersion(CTopicMarketDataVersionFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID,const CReadOnlySequenceNoType& Version)
	{
		init(pFactory,TopicID,Version);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TopicID	�������
	///@param	Version	���հ汾
	static CTopicMarketDataVersionIteratorByTopicAndVersion *alloc(CTopicMarketDataVersionFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID,const CReadOnlySequenceNoType& Version);

	///���췽��
	CTopicMarketDataVersionIteratorByTopicAndVersion(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TopicID	�������
	///@param	Version	���հ汾
	void init(CTopicMarketDataVersionFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID,const CReadOnlySequenceNoType& Version);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataVersionIteratorByTopicAndVersion(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTopicMarketDataVersion��������startFindByTopicAndVersion�Ժ�endFindByTopicAndVersion֮ǰ����
	///@return	��һ����������CTopicMarketDataVersion������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTopicAndVersion ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pByTopicAndVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInformationIteratorByInformationID��һ������Ϣʹ��ByInformationID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationIteratorByInformationID: public CInformationIterator
{
	friend class CInformationFactory;
private:
	///���˶����Ƿ���������
	///@param	pInformation		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInformation *pInformation);

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
	CWriteableInformation m_compareObject;
	
	static CMemoryStack<CInformationIteratorByInformationID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InformationID	��Ϣ���
	CInformationIteratorByInformationID(CInformationFactory *pFactory
		,const CReadOnlyInformationIDType& InformationID)
	{
		init(pFactory,InformationID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InformationID	��Ϣ���
	static CInformationIteratorByInformationID *alloc(CInformationFactory *pFactory
		,const CReadOnlyInformationIDType& InformationID);

	///���췽��
	CInformationIteratorByInformationID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InformationID	��Ϣ���
	void init(CInformationFactory *pFactory
		,const CReadOnlyInformationIDType& InformationID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInformationIteratorByInformationID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInformation��������startFindByInformationID�Ժ�endFindByInformationID֮ǰ����
	///@return	��һ����������CInformation������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInformation *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByInformationID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInformation * pByInformationID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorStartByInstrumentID��һ���Ժ�Լʹ��StartByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorStartByInstrumentID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrument		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrument *pInstrument);

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
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorStartByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	CInstrumentIteratorStartByInstrumentID(CInstrumentFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	static CInstrumentIteratorStartByInstrumentID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CInstrumentIteratorStartByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrument��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorBySettlementGroupID��һ���Ժ�Լʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorBySettlementGroupID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrument		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrument *pInstrument);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CInstrument *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CInstrument *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CInstrumentIteratorBySettlementGroupID(CInstrumentFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CInstrumentIteratorBySettlementGroupID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CInstrumentIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CInstrumentFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrument��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByProductID��һ���Ժ�Լʹ��ByProductID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByProductID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrument		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrument *pInstrument);

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
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByProductID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductID	��Ʒ���
	CInstrumentIteratorByProductID(CInstrumentFactory *pFactory
		,const CReadOnlyProductIDType& ProductID)
	{
		init(pFactory,ProductID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductID	��Ʒ���
	static CInstrumentIteratorByProductID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///���췽��
	CInstrumentIteratorByProductID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductID	��Ʒ���
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentIteratorByProductID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrument��������startFindByProductID�Ժ�endFindByProductID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByProductID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pByProductID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByProductGroupID��һ���Ժ�Լʹ��ByProductGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByProductGroupID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrument		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrument *pInstrument);

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
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByProductGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	CInstrumentIteratorByProductGroupID(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID)
	{
		init(pFactory,ProductGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	static CInstrumentIteratorByProductGroupID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///���췽��
	CInstrumentIteratorByProductGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentIteratorByProductGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrument��������startFindByProductGroupID�Ժ�endFindByProductGroupID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByProductGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pByProductGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByDeliveryMonth��һ���Ժ�Լʹ��ByDeliveryMonth��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByDeliveryMonth: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrument		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrument *pInstrument);

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
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByDeliveryMonth> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	CInstrumentIteratorByDeliveryMonth(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth)
	{
		init(pFactory,ProductGroupID,DeliveryYear,DeliveryMonth);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	static CInstrumentIteratorByDeliveryMonth *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///���췽��
	CInstrumentIteratorByDeliveryMonth(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentIteratorByDeliveryMonth(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrument��������startFindByDeliveryMonth�Ժ�endFindByDeliveryMonth֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByDeliveryMonth ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pByDeliveryMonth,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByRevDeliveryMonth��һ���Ժ�Լʹ��ByRevDeliveryMonth��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByRevDeliveryMonth: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrument		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrument *pInstrument);

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
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByRevDeliveryMonth> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	CInstrumentIteratorByRevDeliveryMonth(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth)
	{
		init(pFactory,ProductGroupID,DeliveryYear,DeliveryMonth);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	static CInstrumentIteratorByRevDeliveryMonth *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///���췽��
	CInstrumentIteratorByRevDeliveryMonth(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentIteratorByRevDeliveryMonth(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrument��������startFindByRevDeliveryMonth�Ժ�endFindByRevDeliveryMonth֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByRevDeliveryMonth ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pByRevDeliveryMonth,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegIteratorByCombination��һ������Ϻ�Լ����ʹ��ByCombination��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIteratorByCombination: public CCombinationLegIterator
{
	friend class CCombinationLegFactory;
private:
	///���˶����Ƿ���������
	///@param	pCombinationLeg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCombinationLeg *pCombinationLeg);

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
	CWriteableCombinationLeg m_compareObject;
	
	static CMemoryStack<CCombinationLegIteratorByCombination> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	CombInstrumentID	��Ϻ�Լ����
	CCombinationLegIteratorByCombination(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID)
	{
		init(pFactory,CombInstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	CombInstrumentID	��Ϻ�Լ����
	static CCombinationLegIteratorByCombination *alloc(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID);

	///���췽��
	CCombinationLegIteratorByCombination(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	CombInstrumentID	��Ϻ�Լ����
	void init(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombinationLegIteratorByCombination(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCombinationLeg��������startFindByCombination�Ժ�endFindByCombination֮ǰ����
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombinationLeg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByCombination ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombinationLeg * pByCombination,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombinationLegIteratorByLeg��һ������Ϻ�Լ����ʹ��ByLeg��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIteratorByLeg: public CCombinationLegIterator
{
	friend class CCombinationLegFactory;
private:
	///���˶����Ƿ���������
	///@param	pCombinationLeg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCombinationLeg *pCombinationLeg);

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
	CWriteableCombinationLeg m_compareObject;
	
	static CMemoryStack<CCombinationLegIteratorByLeg> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LegInstrumentID	���Ⱥ�Լ����
	CCombinationLegIteratorByLeg(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& LegInstrumentID)
	{
		init(pFactory,LegInstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LegInstrumentID	���Ⱥ�Լ����
	static CCombinationLegIteratorByLeg *alloc(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& LegInstrumentID);

	///���췽��
	CCombinationLegIteratorByLeg(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	LegInstrumentID	���Ⱥ�Լ����
	void init(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& LegInstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombinationLegIteratorByLeg(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCombinationLeg��������startFindByLeg�Ժ�endFindByLeg֮ǰ����
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombinationLeg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByLeg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombinationLeg * pByLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombinationLegIteratorBySettlementGroupID��һ������Ϻ�Լ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIteratorBySettlementGroupID: public CCombinationLegIterator
{
	friend class CCombinationLegFactory;
private:
	///���˶����Ƿ���������
	///@param	pCombinationLeg		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCombinationLeg *pCombinationLeg);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCombinationLeg *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCombinationLeg *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCombinationLeg m_compareObject;
	
	static CMemoryStack<CCombinationLegIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCombinationLegIteratorBySettlementGroupID(CCombinationLegFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCombinationLegIteratorBySettlementGroupID *alloc(CCombinationLegFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCombinationLegIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCombinationLegFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombinationLegIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCombinationLeg��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombinationLeg *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombinationLeg * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountIteratorBySettlementGroupID��һ���Ի�Ա�˻���ϵʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountIteratorBySettlementGroupID: public CPartRoleAccountIterator
{
	friend class CPartRoleAccountFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartRoleAccount		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartRoleAccount *pPartRoleAccount);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CPartRoleAccount *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CPartRoleAccount *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteablePartRoleAccount m_compareObject;
	
	static CMemoryStack<CPartRoleAccountIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CPartRoleAccountIteratorBySettlementGroupID(CPartRoleAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CPartRoleAccountIteratorBySettlementGroupID *alloc(CPartRoleAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CPartRoleAccountIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CPartRoleAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartRoleAccountIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartRoleAccount��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartRoleAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountIteratorStartByParticipantID��һ���Ի�Ա�˻���ϵʹ��StartByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountIteratorStartByParticipantID: public CPartRoleAccountIterator
{
	friend class CPartRoleAccountFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartRoleAccount		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartRoleAccount *pPartRoleAccount);

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
	CWriteablePartRoleAccount m_compareObject;
	
	static CMemoryStack<CPartRoleAccountIteratorStartByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CPartRoleAccountIteratorStartByParticipantID(CPartRoleAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CPartRoleAccountIteratorStartByParticipantID *alloc(CPartRoleAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CPartRoleAccountIteratorStartByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CPartRoleAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartRoleAccountIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartRoleAccount��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartRoleAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleIteratorBySettlementGroupID��һ���Ի�Ա��Ʒ��ɫʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleIteratorBySettlementGroupID: public CPartProductRoleIterator
{
	friend class CPartProductRoleFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartProductRole		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartProductRole *pPartProductRole);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CPartProductRole *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CPartProductRole *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteablePartProductRole m_compareObject;
	
	static CMemoryStack<CPartProductRoleIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CPartProductRoleIteratorBySettlementGroupID(CPartProductRoleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CPartProductRoleIteratorBySettlementGroupID *alloc(CPartProductRoleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CPartProductRoleIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CPartProductRoleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartProductRoleIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartProductRole��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartProductRole������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRole *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRole * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightIteratorBySettlementGroupID��һ���Ի�Ա��Ʒ����Ȩ��ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightIteratorBySettlementGroupID: public CPartProductRightIterator
{
	friend class CPartProductRightFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartProductRight		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartProductRight *pPartProductRight);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CPartProductRight *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CPartProductRight *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteablePartProductRight m_compareObject;
	
	static CMemoryStack<CPartProductRightIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CPartProductRightIteratorBySettlementGroupID(CPartProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CPartProductRightIteratorBySettlementGroupID *alloc(CPartProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CPartProductRightIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CPartProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartProductRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartProductRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightIteratorBySettlementGroupID��һ���Ի�Ա��Լ����Ȩ��ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightIteratorBySettlementGroupID: public CPartInstrumentRightIterator
{
	friend class CPartInstrumentRightFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartInstrumentRight		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartInstrumentRight *pPartInstrumentRight);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CPartInstrumentRight *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CPartInstrumentRight *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteablePartInstrumentRight m_compareObject;
	
	static CMemoryStack<CPartInstrumentRightIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CPartInstrumentRightIteratorBySettlementGroupID(CPartInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CPartInstrumentRightIteratorBySettlementGroupID *alloc(CPartInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CPartInstrumentRightIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CPartInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartInstrumentRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartInstrumentRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightIteratorBySettlementGroupID��һ���Կͻ���Ʒ����Ȩ��ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightIteratorBySettlementGroupID: public CClientProductRightIterator
{
	friend class CClientProductRightFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientProductRight		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientProductRight *pClientProductRight);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CClientProductRight *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CClientProductRight *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableClientProductRight m_compareObject;
	
	static CMemoryStack<CClientProductRightIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CClientProductRightIteratorBySettlementGroupID(CClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CClientProductRightIteratorBySettlementGroupID *alloc(CClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CClientProductRightIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientProductRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientProductRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientProductRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightIteratorBySettlementGroupID��һ���Կͻ���Լ����Ȩ��ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightIteratorBySettlementGroupID: public CClientInstrumentRightIterator
{
	friend class CClientInstrumentRightFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientInstrumentRight		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientInstrumentRight *pClientInstrumentRight);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CClientInstrumentRight *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CClientInstrumentRight *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableClientInstrumentRight m_compareObject;
	
	static CMemoryStack<CClientInstrumentRightIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CClientInstrumentRightIteratorBySettlementGroupID(CClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CClientInstrumentRightIteratorBySettlementGroupID *alloc(CClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CClientInstrumentRightIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientInstrumentRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientInstrumentRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightIteratorBySettlementGroupID��һ���Ի�Ա�ͻ���Ʒ����Ȩ��ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightIteratorBySettlementGroupID: public CPartClientProductRightIterator
{
	friend class CPartClientProductRightFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartClientProductRight		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartClientProductRight *pPartClientProductRight);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CPartClientProductRight *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CPartClientProductRight *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteablePartClientProductRight m_compareObject;
	
	static CMemoryStack<CPartClientProductRightIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CPartClientProductRightIteratorBySettlementGroupID(CPartClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CPartClientProductRightIteratorBySettlementGroupID *alloc(CPartClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CPartClientProductRightIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CPartClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientProductRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartClientProductRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientProductRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightIteratorBySettlementGroupID��һ���Ի�Ա�ͻ���Լ����Ȩ��ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightIteratorBySettlementGroupID: public CPartClientInstrumentRightIterator
{
	friend class CPartClientInstrumentRightFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartClientInstrumentRight		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartClientInstrumentRight *pPartClientInstrumentRight);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CPartClientInstrumentRight *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CPartClientInstrumentRight *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteablePartClientInstrumentRight m_compareObject;
	
	static CMemoryStack<CPartClientInstrumentRightIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CPartClientInstrumentRightIteratorBySettlementGroupID(CPartClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CPartClientInstrumentRightIteratorBySettlementGroupID *alloc(CPartClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CPartClientInstrumentRightIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CPartClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientInstrumentRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartClientInstrumentRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyIteratorBySettlementGroupID��һ���Բ�Ʒ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyIteratorBySettlementGroupID: public CCurrProductPropertyIterator
{
	friend class CCurrProductPropertyFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrProductProperty		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrProductProperty *pCurrProductProperty);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrProductProperty *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrProductProperty *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrProductProperty m_compareObject;
	
	static CMemoryStack<CCurrProductPropertyIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrProductPropertyIteratorBySettlementGroupID(CCurrProductPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrProductPropertyIteratorBySettlementGroupID *alloc(CCurrProductPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrProductPropertyIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrProductPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrProductPropertyIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrProductProperty��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrProductProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrProductProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyIteratorBySettlementGroupID��һ���Ժ�Լ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyIteratorBySettlementGroupID: public CCurrInstrumentPropertyIterator
{
	friend class CCurrInstrumentPropertyFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrInstrumentProperty		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrInstrumentProperty *pCurrInstrumentProperty);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrInstrumentProperty *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrInstrumentProperty *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrInstrumentProperty m_compareObject;
	
	static CMemoryStack<CCurrInstrumentPropertyIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrInstrumentPropertyIteratorBySettlementGroupID(CCurrInstrumentPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrInstrumentPropertyIteratorBySettlementGroupID *alloc(CCurrInstrumentPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrInstrumentPropertyIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrInstrumentPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrInstrumentPropertyIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrInstrumentProperty��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrInstrumentProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingIteratorBySettlementGroupID��һ���Ե�ǰ�۸��ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingIteratorBySettlementGroupID: public CCurrPriceBandingIterator
{
	friend class CCurrPriceBandingFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrPriceBanding		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrPriceBanding *pCurrPriceBanding);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrPriceBanding *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrPriceBanding *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrPriceBanding m_compareObject;
	
	static CMemoryStack<CCurrPriceBandingIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrPriceBandingIteratorBySettlementGroupID(CCurrPriceBandingFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrPriceBandingIteratorBySettlementGroupID *alloc(CCurrPriceBandingFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrPriceBandingIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrPriceBandingFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPriceBandingIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrPriceBanding��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrPriceBanding������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPriceBanding *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateIteratorBySettlementGroupID��һ���Ե����Լ��֤����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateIteratorBySettlementGroupID: public CCurrMarginRateIterator
{
	friend class CCurrMarginRateFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrMarginRate		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrMarginRate *pCurrMarginRate);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrMarginRate *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrMarginRate *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrMarginRate m_compareObject;
	
	static CMemoryStack<CCurrMarginRateIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrMarginRateIteratorBySettlementGroupID(CCurrMarginRateFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrMarginRateIteratorBySettlementGroupID *alloc(CCurrMarginRateFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrMarginRateIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrMarginRateFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrMarginRateIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrMarginRate��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRate *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailIteratorBySettlementGroupID��һ���Ե����Լ��֤���ʵ���ϸ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailIteratorBySettlementGroupID: public CCurrMarginRateDetailIterator
{
	friend class CCurrMarginRateDetailFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrMarginRateDetail		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrMarginRateDetail *pCurrMarginRateDetail);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrMarginRateDetail *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrMarginRateDetail *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrMarginRateDetail m_compareObject;
	
	static CMemoryStack<CCurrMarginRateDetailIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrMarginRateDetailIteratorBySettlementGroupID(CCurrMarginRateDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrMarginRateDetailIteratorBySettlementGroupID *alloc(CCurrMarginRateDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrMarginRateDetailIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrMarginRateDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrMarginRateDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrMarginRateDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrMarginRateDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitIteratorBySettlementGroupID��һ���Ե�ǰ��Ա��Լ�޲�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitIteratorBySettlementGroupID: public CCurrPartPosiLimitIterator
{
	friend class CCurrPartPosiLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrPartPosiLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrPartPosiLimit *pCurrPartPosiLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrPartPosiLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrPartPosiLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrPartPosiLimit m_compareObject;
	
	static CMemoryStack<CCurrPartPosiLimitIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrPartPosiLimitIteratorBySettlementGroupID(CCurrPartPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrPartPosiLimitIteratorBySettlementGroupID *alloc(CCurrPartPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrPartPosiLimitIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrPartPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPartPosiLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrPartPosiLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailIteratorBySettlementGroupID��һ���Ե�ǰ��Ա��Լ�޲ֵ���ϸ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailIteratorBySettlementGroupID: public CCurrPartPosiLimitDetailIterator
{
	friend class CCurrPartPosiLimitDetailFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrPartPosiLimitDetail		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrPartPosiLimitDetail *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrPartPosiLimitDetail *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrPartPosiLimitDetail m_compareObject;
	
	static CMemoryStack<CCurrPartPosiLimitDetailIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrPartPosiLimitDetailIteratorBySettlementGroupID(CCurrPartPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrPartPosiLimitDetailIteratorBySettlementGroupID *alloc(CCurrPartPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrPartPosiLimitDetailIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrPartPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPartPosiLimitDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrPartPosiLimitDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrPartPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitIteratorBySettlementGroupID��һ���Ե�ǰ�ͻ���Լ�޲�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitIteratorBySettlementGroupID: public CCurrClientPosiLimitIterator
{
	friend class CCurrClientPosiLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrClientPosiLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrClientPosiLimit *pCurrClientPosiLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrClientPosiLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrClientPosiLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrClientPosiLimit m_compareObject;
	
	static CMemoryStack<CCurrClientPosiLimitIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrClientPosiLimitIteratorBySettlementGroupID(CCurrClientPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrClientPosiLimitIteratorBySettlementGroupID *alloc(CCurrClientPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrClientPosiLimitIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrClientPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrClientPosiLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrClientPosiLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailIteratorBySettlementGroupID��һ���Ե�ǰ�ͻ���Լ�޲ֵ���ϸ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailIteratorBySettlementGroupID: public CCurrClientPosiLimitDetailIterator
{
	friend class CCurrClientPosiLimitDetailFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrClientPosiLimitDetail		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrClientPosiLimitDetail *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrClientPosiLimitDetail *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrClientPosiLimitDetail m_compareObject;
	
	static CMemoryStack<CCurrClientPosiLimitDetailIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrClientPosiLimitDetailIteratorBySettlementGroupID(CCurrClientPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrClientPosiLimitDetailIteratorBySettlementGroupID *alloc(CCurrClientPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrClientPosiLimitDetailIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrClientPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrClientPosiLimitDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrClientPosiLimitDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrClientPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitIteratorBySettlementGroupID��һ���Ե�ǰ����ͻ���Լ�޲�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitIteratorBySettlementGroupID: public CCurrSpecialPosiLimitIterator
{
	friend class CCurrSpecialPosiLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrSpecialPosiLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrSpecialPosiLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrSpecialPosiLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrSpecialPosiLimit m_compareObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrSpecialPosiLimitIteratorBySettlementGroupID(CCurrSpecialPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrSpecialPosiLimitIteratorBySettlementGroupID *alloc(CCurrSpecialPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrSpecialPosiLimitIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrSpecialPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrSpecialPosiLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrSpecialPosiLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID��һ���Ե�ǰ����ͻ���Լ�޲ֵ���ϸ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID: public CCurrSpecialPosiLimitDetailIterator
{
	friend class CCurrSpecialPosiLimitDetailFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrSpecialPosiLimitDetail		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrSpecialPosiLimitDetail *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrSpecialPosiLimitDetail *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrSpecialPosiLimitDetail m_compareObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID(CCurrSpecialPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID *alloc(CCurrSpecialPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrSpecialPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrSpecialPosiLimitDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrSpecialPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleIteratorBySettlementGroupID��һ���Ե�ǰ��Լ���ڱ�ֵ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleIteratorBySettlementGroupID: public CCurrHedgeRuleIterator
{
	friend class CCurrHedgeRuleFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrHedgeRule		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrHedgeRule *pCurrHedgeRule);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrHedgeRule *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrHedgeRule *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrHedgeRule m_compareObject;
	
	static CMemoryStack<CCurrHedgeRuleIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrHedgeRuleIteratorBySettlementGroupID(CCurrHedgeRuleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrHedgeRuleIteratorBySettlementGroupID *alloc(CCurrHedgeRuleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrHedgeRuleIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrHedgeRuleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrHedgeRuleIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrHedgeRule��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrHedgeRule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrHedgeRule *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIteratorBySettlementGroupID��һ���Ե�ǰ��Լ���׽׶�����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIteratorBySettlementGroupID: public CCurrTradingSegmentAttrIterator
{
	friend class CCurrTradingSegmentAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrTradingSegmentAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrTradingSegmentAttr *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrTradingSegmentAttr *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrTradingSegmentAttrIteratorBySettlementGroupID(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrTradingSegmentAttrIteratorBySettlementGroupID *alloc(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrTradingSegmentAttrIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrTradingSegmentAttrIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrTradingSegmentAttr��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIteratorByTime��һ���Ե�ǰ��Լ���׽׶�����ʹ��ByTime��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIteratorByTime: public CCurrTradingSegmentAttrIterator
{
	friend class CCurrTradingSegmentAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrTradingSegmentAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

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
	CWriteableCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrIteratorByTime> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	StartTime	��ʼʱ��
	CCurrTradingSegmentAttrIteratorByTime(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime)
	{
		init(pFactory,StartTime);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	StartTime	��ʼʱ��
	static CCurrTradingSegmentAttrIteratorByTime *alloc(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///���췽��
	CCurrTradingSegmentAttrIteratorByTime(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	StartTime	��ʼʱ��
	void init(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrTradingSegmentAttrIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrTradingSegmentAttr��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIteratorByInstrument��һ���Ե�ǰ��Լ���׽׶�����ʹ��ByInstrument��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIteratorByInstrument: public CCurrTradingSegmentAttrIterator
{
	friend class CCurrTradingSegmentAttrFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrTradingSegmentAttr		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

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
	CWriteableCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrIteratorByInstrument> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ���
	CCurrTradingSegmentAttrIteratorByInstrument(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ���
	static CCurrTradingSegmentAttrIteratorByInstrument *alloc(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CCurrTradingSegmentAttrIteratorByInstrument(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ���
	void init(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrTradingSegmentAttrIteratorByInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrTradingSegmentAttr��������startFindByInstrument�Ժ�endFindByInstrument֮ǰ����
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pByInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseIteratorBySettlementGroupID��һ���Ե�ǰ��Լ�۶�����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseIteratorBySettlementGroupID: public CCurrFuseIterator
{
	friend class CCurrFuseFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrFuse		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrFuse *pCurrFuse);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrFuse *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrFuse *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrFuse m_compareObject;
	
	static CMemoryStack<CCurrFuseIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrFuseIteratorBySettlementGroupID(CCurrFuseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrFuseIteratorBySettlementGroupID *alloc(CCurrFuseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrFuseIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrFuseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrFuseIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrFuse��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrFuse������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrFuse *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrFuse * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountIteratorBySettlementGroupID��һ���Խ����˻�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountIteratorBySettlementGroupID: public CTradingAccountIterator
{
	friend class CTradingAccountFactory;
private:
	///���˶����Ƿ���������
	///@param	pTradingAccount		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTradingAccount *pTradingAccount);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CTradingAccount *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CTradingAccount *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableTradingAccount m_compareObject;
	
	static CMemoryStack<CTradingAccountIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CTradingAccountIteratorBySettlementGroupID(CTradingAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CTradingAccountIteratorBySettlementGroupID *alloc(CTradingAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CTradingAccountIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CTradingAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradingAccountIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTradingAccount��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTradingAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTradingAccount * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountIteratorBySettlementGroupID��һ���Ի���׼�����˻�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountIteratorBySettlementGroupID: public CBaseReserveAccountIterator
{
	friend class CBaseReserveAccountFactory;
private:
	///���˶����Ƿ���������
	///@param	pBaseReserveAccount		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CBaseReserveAccount *pBaseReserveAccount);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CBaseReserveAccount *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CBaseReserveAccount *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableBaseReserveAccount m_compareObject;
	
	static CMemoryStack<CBaseReserveAccountIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CBaseReserveAccountIteratorBySettlementGroupID(CBaseReserveAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CBaseReserveAccountIteratorBySettlementGroupID *alloc(CBaseReserveAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CBaseReserveAccountIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CBaseReserveAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBaseReserveAccountIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CBaseReserveAccount��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CBaseReserveAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBaseReserveAccount *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionIteratorStartByInstrument��һ���Ի�Ա�ֲ�ʹ��StartByInstrument��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIteratorStartByInstrument: public CPartPositionIterator
{
	friend class CPartPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartPosition *pPartPosition);

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
	CWriteablePartPosition m_compareObject;
	
	static CMemoryStack<CPartPositionIteratorStartByInstrument> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	CPartPositionIteratorStartByInstrument(CPartPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	static CPartPositionIteratorStartByInstrument *alloc(CPartPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CPartPositionIteratorStartByInstrument(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	void init(CPartPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartPositionIteratorStartByInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartPosition��������startFindStartByInstrument�Ժ�endFindStartByInstrument֮ǰ����
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartPosition * pStartByInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartPositionIteratorStartByParticipant��һ���Ի�Ա�ֲ�ʹ��StartByParticipant��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIteratorStartByParticipant: public CPartPositionIterator
{
	friend class CPartPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartPosition *pPartPosition);

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
	CWriteablePartPosition m_compareObject;
	
	static CMemoryStack<CPartPositionIteratorStartByParticipant> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CPartPositionIteratorStartByParticipant(CPartPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CPartPositionIteratorStartByParticipant *alloc(CPartPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CPartPositionIteratorStartByParticipant(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CPartPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartPositionIteratorStartByParticipant(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartPosition��������startFindStartByParticipant�Ժ�endFindStartByParticipant֮ǰ����
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartPosition * pStartByParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartPositionIteratorBySettlementGroupID��һ���Ի�Ա�ֲ�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIteratorBySettlementGroupID: public CPartPositionIterator
{
	friend class CPartPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pPartPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CPartPosition *pPartPosition);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CPartPosition *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CPartPosition *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteablePartPosition m_compareObject;
	
	static CMemoryStack<CPartPositionIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CPartPositionIteratorBySettlementGroupID(CPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CPartPositionIteratorBySettlementGroupID *alloc(CPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CPartPositionIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartPositionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CPartPosition��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartPosition * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorByClientAndInstrument��һ���Կͻ��ֲ�ʹ��ByClientAndInstrument��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorByClientAndInstrument: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientPosition *pClientPosition);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��������ڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CHashIndexNode *m_pCurrent;

	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ��Ӧ�������ڵ㣬���������������
	CHashIndexNode *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorByClientAndInstrument> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	///@param	PosiDirection	��շ���
	///@param	HedgeFlag	Ͷ����־
	CClientPositionIteratorByClientAndInstrument(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID,const CReadOnlyPosiDirectionType& PosiDirection,const CReadOnlyHedgeFlagType& HedgeFlag)
	{
		init(pFactory,ClientID,InstrumentID,PosiDirection,HedgeFlag);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	///@param	PosiDirection	��շ���
	///@param	HedgeFlag	Ͷ����־
	static CClientPositionIteratorByClientAndInstrument *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID,const CReadOnlyPosiDirectionType& PosiDirection,const CReadOnlyHedgeFlagType& HedgeFlag);

	///���췽��
	CClientPositionIteratorByClientAndInstrument(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	///@param	PosiDirection	��շ���
	///@param	HedgeFlag	Ͷ����־
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID,const CReadOnlyPosiDirectionType& PosiDirection,const CReadOnlyHedgeFlagType& HedgeFlag);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionIteratorByClientAndInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientPosition��������startFindByClientAndInstrument�Ժ�endFindByClientAndInstrument֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByClientAndInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pByClientAndInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorStartByParticipant��һ���Կͻ��ֲ�ʹ��StartByParticipant��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorStartByParticipant: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientPosition *pClientPosition);

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
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorStartByParticipant> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CClientPositionIteratorStartByParticipant(CClientPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CClientPositionIteratorStartByParticipant *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CClientPositionIteratorStartByParticipant(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionIteratorStartByParticipant(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientPosition��������startFindStartByParticipant�Ժ�endFindStartByParticipant֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pStartByParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorStartByClient��һ���Կͻ��ֲ�ʹ��StartByClient��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorStartByClient: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientPosition *pClientPosition);

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
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorStartByClient> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	CClientPositionIteratorStartByClient(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	static CClientPositionIteratorStartByClient *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///���췽��
	CClientPositionIteratorStartByClient(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionIteratorStartByClient(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientPosition��������startFindStartByClient�Ժ�endFindStartByClient֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pStartByClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorStartByInstrument��һ���Կͻ��ֲ�ʹ��StartByInstrument��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorStartByInstrument: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientPosition *pClientPosition);

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
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorStartByInstrument> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	CClientPositionIteratorStartByInstrument(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	static CClientPositionIteratorStartByInstrument *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CClientPositionIteratorStartByInstrument(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionIteratorStartByInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientPosition��������startFindStartByInstrument�Ժ�endFindStartByInstrument֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pStartByInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorByInstrumentID��һ���Կͻ��ֲ�ʹ��ByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorByInstrumentID: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientPosition *pClientPosition);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CClientPosition *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CClientPosition *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	CClientPositionIteratorByInstrumentID(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	static CClientPositionIteratorByInstrumentID *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CClientPositionIteratorByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientPosition��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorBySettlementGroupID��һ���Կͻ��ֲ�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorBySettlementGroupID: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pClientPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClientPosition *pClientPosition);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CClientPosition *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CClientPosition *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CClientPositionIteratorBySettlementGroupID(CClientPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CClientPositionIteratorBySettlementGroupID *alloc(CClientPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CClientPositionIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CClientPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClientPosition��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeIteratorBySettlementGroupID��һ���Ա�ֵ�����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeIteratorBySettlementGroupID: public CHedgeVolumeIterator
{
	friend class CHedgeVolumeFactory;
private:
	///���˶����Ƿ���������
	///@param	pHedgeVolume		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CHedgeVolume *pHedgeVolume);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CHedgeVolume *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CHedgeVolume *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableHedgeVolume m_compareObject;
	
	static CMemoryStack<CHedgeVolumeIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CHedgeVolumeIteratorBySettlementGroupID(CHedgeVolumeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CHedgeVolumeIteratorBySettlementGroupID *alloc(CHedgeVolumeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CHedgeVolumeIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CHedgeVolumeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CHedgeVolumeIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CHedgeVolume��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CHedgeVolume *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableHedgeVolume * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeIteratorStartByPartClientAndInstrument��һ���Ա�ֵ�����ʹ��StartByPartClientAndInstrument��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeIteratorStartByPartClientAndInstrument: public CHedgeVolumeIterator
{
	friend class CHedgeVolumeFactory;
private:
	///���˶����Ƿ���������
	///@param	pHedgeVolume		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CHedgeVolume *pHedgeVolume);

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
	CWriteableHedgeVolume m_compareObject;
	
	static CMemoryStack<CHedgeVolumeIteratorStartByPartClientAndInstrument> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	CHedgeVolumeIteratorStartByPartClientAndInstrument(CHedgeVolumeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,ParticipantID,ClientID,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	static CHedgeVolumeIteratorStartByPartClientAndInstrument *alloc(CHedgeVolumeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CHedgeVolumeIteratorStartByPartClientAndInstrument(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	void init(CHedgeVolumeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CHedgeVolumeIteratorStartByPartClientAndInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CHedgeVolume��������startFindStartByPartClientAndInstrument�Ժ�endFindStartByPartClientAndInstrument֮ǰ����
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CHedgeVolume *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByPartClientAndInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableHedgeVolume * pStartByPartClientAndInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderIteratorBySettlementGroupID��һ������ʷ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderIteratorBySettlementGroupID: public CRemainOrderIterator
{
	friend class CRemainOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pRemainOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRemainOrder *pRemainOrder);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CRemainOrder *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CRemainOrder *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableRemainOrder m_compareObject;
	
	static CMemoryStack<CRemainOrderIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CRemainOrderIteratorBySettlementGroupID(CRemainOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CRemainOrderIteratorBySettlementGroupID *alloc(CRemainOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CRemainOrderIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CRemainOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRemainOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRemainOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRemainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRemainOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRemainOrderIteratorByInstrumentID��һ������ʷ����ʹ��ByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderIteratorByInstrumentID: public CRemainOrderIterator
{
	friend class CRemainOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pRemainOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CRemainOrder *pRemainOrder);

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
	CWriteableRemainOrder m_compareObject;
	
	static CMemoryStack<CRemainOrderIteratorByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ���
	CRemainOrderIteratorByInstrumentID(CRemainOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ���
	static CRemainOrderIteratorByInstrumentID *alloc(CRemainOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CRemainOrderIteratorByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ���
	void init(CRemainOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRemainOrderIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CRemainOrder��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRemainOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRemainOrder * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataIteratorBySettlementGroupID��һ��������ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataIteratorBySettlementGroupID: public CMarketDataIterator
{
	friend class CMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMarketData *pMarketData);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CMarketData *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CMarketData *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableMarketData m_compareObject;
	
	static CMemoryStack<CMarketDataIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CMarketDataIteratorBySettlementGroupID(CMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CMarketDataIteratorBySettlementGroupID *alloc(CMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CMarketDataIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMarketData��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketData * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionIteratorBySettlementGroupID��һ���Խ����Ա�ֲ�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionIteratorBySettlementGroupID: public CClearingPartPositionIterator
{
	friend class CClearingPartPositionFactory;
private:
	///���˶����Ƿ���������
	///@param	pClearingPartPosition		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CClearingPartPosition *pClearingPartPosition);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CClearingPartPosition *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CClearingPartPosition *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableClearingPartPosition m_compareObject;
	
	static CMemoryStack<CClearingPartPositionIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CClearingPartPositionIteratorBySettlementGroupID(CClearingPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CClearingPartPositionIteratorBySettlementGroupID *alloc(CClearingPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CClearingPartPositionIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CClearingPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClearingPartPositionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CClearingPartPosition��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClearingPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingPartPosition *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusIteratorStartByInstrumentID��һ���Ժ�Լ״̬ʹ��StartByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusIteratorStartByInstrumentID: public CInstrumentStatusIterator
{
	friend class CInstrumentStatusFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrumentStatus		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrumentStatus *pInstrumentStatus);

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
	CWriteableInstrumentStatus m_compareObject;
	
	static CMemoryStack<CInstrumentStatusIteratorStartByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	CInstrumentStatusIteratorStartByInstrumentID(CInstrumentStatusFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	static CInstrumentStatusIteratorStartByInstrumentID *alloc(CInstrumentStatusFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CInstrumentStatusIteratorStartByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	void init(CInstrumentStatusFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentStatusIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrumentStatus��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusIteratorBySettlementGroupID��һ���Ժ�Լ״̬ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusIteratorBySettlementGroupID: public CInstrumentStatusIterator
{
	friend class CInstrumentStatusFactory;
private:
	///���˶����Ƿ���������
	///@param	pInstrumentStatus		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CInstrumentStatus *pInstrumentStatus);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CInstrumentStatus *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CInstrumentStatus *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableInstrumentStatus m_compareObject;
	
	static CMemoryStack<CInstrumentStatusIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	CInstrumentStatusIteratorBySettlementGroupID(CInstrumentStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	static CInstrumentStatusIteratorBySettlementGroupID *alloc(CInstrumentStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CInstrumentStatusIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	void init(CInstrumentStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentStatusIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CInstrumentStatus��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatus *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderIteratorStartByParticipantID��һ���Ա���ʹ��StartByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorStartByParticipantID: public COrderIterator
{
	friend class COrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(COrder *pOrder);

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
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorStartByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	COrderIteratorStartByParticipantID(COrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static COrderIteratorStartByParticipantID *alloc(COrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	COrderIteratorStartByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(COrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������COrder��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorBySettlementGroupID��һ���Ա���ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorBySettlementGroupID: public COrderIterator
{
	friend class COrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(COrder *pOrder);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	COrder *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	COrder *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	COrderIteratorBySettlementGroupID(COrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static COrderIteratorBySettlementGroupID *alloc(COrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	COrderIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(COrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������COrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorByUserID��һ���Ա���ʹ��ByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorByUserID: public COrderIterator
{
	friend class COrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(COrder *pOrder);

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
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	COrderIteratorByUserID(COrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	static COrderIteratorByUserID *alloc(COrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///���췽��
	COrderIteratorByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	void init(COrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������COrder��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorByInstrumentID��һ���Ա���ʹ��ByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorByInstrumentID: public COrderIterator
{
	friend class COrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(COrder *pOrder);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	COrder *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	COrder *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	COrderIteratorByInstrumentID(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	static COrderIteratorByInstrumentID *alloc(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	COrderIteratorByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	void init(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������COrder��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorStartByInstrumentID��һ���Ա���ʹ��StartByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorStartByInstrumentID: public COrderIterator
{
	friend class COrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(COrder *pOrder);

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
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorStartByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	COrderIteratorStartByInstrumentID(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	static COrderIteratorStartByInstrumentID *alloc(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	COrderIteratorStartByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	void init(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������COrder��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderIteratorStartByParticipantID��һ������ϱ���ʹ��StartByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIteratorStartByParticipantID: public CCombOrderIterator
{
	friend class CCombOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pCombOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCombOrder *pCombOrder);

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
	CWriteableCombOrder m_compareObject;
	
	static CMemoryStack<CCombOrderIteratorStartByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CCombOrderIteratorStartByParticipantID(CCombOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CCombOrderIteratorStartByParticipantID *alloc(CCombOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CCombOrderIteratorStartByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CCombOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombOrderIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCombOrder��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombOrder * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombOrderIteratorBySettlementGroupID��һ������ϱ���ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIteratorBySettlementGroupID: public CCombOrderIterator
{
	friend class CCombOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pCombOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCombOrder *pCombOrder);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCombOrder *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCombOrder *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCombOrder m_compareObject;
	
	static CMemoryStack<CCombOrderIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCombOrderIteratorBySettlementGroupID(CCombOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCombOrderIteratorBySettlementGroupID *alloc(CCombOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCombOrderIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCombOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCombOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombOrderIteratorByUserID��һ������ϱ���ʹ��ByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIteratorByUserID: public CCombOrderIterator
{
	friend class CCombOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pCombOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCombOrder *pCombOrder);

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
	CWriteableCombOrder m_compareObject;
	
	static CMemoryStack<CCombOrderIteratorByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	CCombOrderIteratorByUserID(CCombOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	static CCombOrderIteratorByUserID *alloc(CCombOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///���췽��
	CCombOrderIteratorByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	void init(CCombOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombOrderIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCombOrder��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombOrder * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderIteratorBySettlementGroupID��һ����OTC����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderIteratorBySettlementGroupID: public COTCOrderIterator
{
	friend class COTCOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pOTCOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(COTCOrder *pOTCOrder);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	COTCOrder *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	COTCOrder *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableOTCOrder m_compareObject;
	
	static CMemoryStack<COTCOrderIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	COTCOrderIteratorBySettlementGroupID(COTCOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static COTCOrderIteratorBySettlementGroupID *alloc(COTCOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	COTCOrderIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(COTCOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COTCOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������COTCOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������COTCOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COTCOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOTCOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderIteratorByImplyLeg��һ������ʽ����ʹ��ByImplyLeg��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIteratorByImplyLeg: public CImplyOrderIterator
{
	friend class CImplyOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pImplyOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CImplyOrder *pImplyOrder);

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
	CWriteableImplyOrder m_compareObject;
	
	static CMemoryStack<CImplyOrderIteratorByImplyLeg> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	CombInstrumentID	��ϱ�����
	///@param	ImplyLegID	�����������ȱ��
	///@param	Direction	����������������
	CImplyOrderIteratorByImplyLeg(CImplyOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID,const CReadOnlyLegIDType& ImplyLegID,const CReadOnlyDirectionType& Direction)
	{
		init(pFactory,CombInstrumentID,ImplyLegID,Direction);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	CombInstrumentID	��ϱ�����
	///@param	ImplyLegID	�����������ȱ��
	///@param	Direction	����������������
	static CImplyOrderIteratorByImplyLeg *alloc(CImplyOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID,const CReadOnlyLegIDType& ImplyLegID,const CReadOnlyDirectionType& Direction);

	///���췽��
	CImplyOrderIteratorByImplyLeg(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	CombInstrumentID	��ϱ�����
	///@param	ImplyLegID	�����������ȱ��
	///@param	Direction	����������������
	void init(CImplyOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID,const CReadOnlyLegIDType& ImplyLegID,const CReadOnlyDirectionType& Direction);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CImplyOrderIteratorByImplyLeg(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CImplyOrder��������startFindByImplyLeg�Ժ�endFindByImplyLeg֮ǰ����
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CImplyOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByImplyLeg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableImplyOrder * pByImplyLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CImplyOrderIteratorByImplyOrderAndAnchorLeg��һ������ʽ����ʹ��ByImplyOrderAndAnchorLeg��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIteratorByImplyOrderAndAnchorLeg: public CImplyOrderIterator
{
	friend class CImplyOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pImplyOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CImplyOrder *pImplyOrder);

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
	CWriteableImplyOrder m_compareObject;
	
	static CMemoryStack<CImplyOrderIteratorByImplyOrderAndAnchorLeg> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ImplyOrderID	����������
	///@param	AnchorLegID	ê�������ȱ��
	CImplyOrderIteratorByImplyOrderAndAnchorLeg(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID,const CReadOnlyLegIDType& AnchorLegID)
	{
		init(pFactory,ImplyOrderID,AnchorLegID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ImplyOrderID	����������
	///@param	AnchorLegID	ê�������ȱ��
	static CImplyOrderIteratorByImplyOrderAndAnchorLeg *alloc(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID,const CReadOnlyLegIDType& AnchorLegID);

	///���췽��
	CImplyOrderIteratorByImplyOrderAndAnchorLeg(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ImplyOrderID	����������
	///@param	AnchorLegID	ê�������ȱ��
	void init(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID,const CReadOnlyLegIDType& AnchorLegID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CImplyOrderIteratorByImplyOrderAndAnchorLeg(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CImplyOrder��������startFindByImplyOrderAndAnchorLeg�Ժ�endFindByImplyOrderAndAnchorLeg֮ǰ����
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CImplyOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByImplyOrderAndAnchorLeg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableImplyOrder * pByImplyOrderAndAnchorLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CImplyOrderIteratorByImplyOrder��һ������ʽ����ʹ��ByImplyOrder��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIteratorByImplyOrder: public CImplyOrderIterator
{
	friend class CImplyOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pImplyOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CImplyOrder *pImplyOrder);

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
	CWriteableImplyOrder m_compareObject;
	
	static CMemoryStack<CImplyOrderIteratorByImplyOrder> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ImplyOrderID	����������
	CImplyOrderIteratorByImplyOrder(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID)
	{
		init(pFactory,ImplyOrderID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ImplyOrderID	����������
	static CImplyOrderIteratorByImplyOrder *alloc(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID);

	///���췽��
	CImplyOrderIteratorByImplyOrder(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ImplyOrderID	����������
	void init(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CImplyOrderIteratorByImplyOrder(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CImplyOrder��������startFindByImplyOrder�Ժ�endFindByImplyOrder֮ǰ����
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CImplyOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByImplyOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableImplyOrder * pByImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CQuoteIteratorByUserID��һ���Ա���ʹ��ByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIteratorByUserID: public CQuoteIterator
{
	friend class CQuoteFactory;
private:
	///���˶����Ƿ���������
	///@param	pQuote		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CQuote *pQuote);

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
	CWriteableQuote m_compareObject;
	
	static CMemoryStack<CQuoteIteratorByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û�
	CQuoteIteratorByUserID(CQuoteFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û�
	static CQuoteIteratorByUserID *alloc(CQuoteFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///���췽��
	CQuoteIteratorByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	�û�
	void init(CQuoteFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CQuoteIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CQuote��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CQuote *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableQuote * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CQuoteIteratorStartByParticipantID��һ���Ա���ʹ��StartByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIteratorStartByParticipantID: public CQuoteIterator
{
	friend class CQuoteFactory;
private:
	///���˶����Ƿ���������
	///@param	pQuote		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CQuote *pQuote);

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
	CWriteableQuote m_compareObject;
	
	static CMemoryStack<CQuoteIteratorStartByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CQuoteIteratorStartByParticipantID(CQuoteFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CQuoteIteratorStartByParticipantID *alloc(CQuoteFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CQuoteIteratorStartByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CQuoteFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CQuoteIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CQuote��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CQuote *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableQuote * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CQuoteIteratorBySettlementGroupID��һ���Ա���ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIteratorBySettlementGroupID: public CQuoteIterator
{
	friend class CQuoteFactory;
private:
	///���˶����Ƿ���������
	///@param	pQuote		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CQuote *pQuote);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CQuote *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CQuote *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableQuote m_compareObject;
	
	static CMemoryStack<CQuoteIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CQuoteIteratorBySettlementGroupID(CQuoteFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CQuoteIteratorBySettlementGroupID *alloc(CQuoteFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CQuoteIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CQuoteFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CQuoteIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CQuote��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CQuote *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableQuote * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorByBuyMBLData��һ���Էּ۱�ʹ��ByBuyMBLData��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorByBuyMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pMBLMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMBLMarketData *pMBLMarketData);

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
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorByBuyMBLData> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	CMBLMarketDataIteratorByBuyMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	static CMBLMarketDataIteratorByBuyMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CMBLMarketDataIteratorByBuyMBLData(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMBLMarketDataIteratorByBuyMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMBLMarketData��������startFindByBuyMBLData�Ժ�endFindByBuyMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByBuyMBLData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pByBuyMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorBySellMBLData��һ���Էּ۱�ʹ��BySellMBLData��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorBySellMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pMBLMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMBLMarketData *pMBLMarketData);

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
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorBySellMBLData> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	CMBLMarketDataIteratorBySellMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	static CMBLMarketDataIteratorBySellMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CMBLMarketDataIteratorBySellMBLData(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMBLMarketDataIteratorBySellMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMBLMarketData��������startFindBySellMBLData�Ժ�endFindBySellMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySellMBLData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pBySellMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorStartByBuyMBLData��һ���Էּ۱�ʹ��StartByBuyMBLData��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorStartByBuyMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pMBLMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMBLMarketData *pMBLMarketData);

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
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorStartByBuyMBLData> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	CMBLMarketDataIteratorStartByBuyMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	static CMBLMarketDataIteratorStartByBuyMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CMBLMarketDataIteratorStartByBuyMBLData(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMBLMarketDataIteratorStartByBuyMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMBLMarketData��������startFindStartByBuyMBLData�Ժ�endFindStartByBuyMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByBuyMBLData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pStartByBuyMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorStartBySellMBLData��һ���Էּ۱�ʹ��StartBySellMBLData��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorStartBySellMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///���˶����Ƿ���������
	///@param	pMBLMarketData		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CMBLMarketData *pMBLMarketData);

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
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorStartBySellMBLData> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	CMBLMarketDataIteratorStartBySellMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	static CMBLMarketDataIteratorStartBySellMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CMBLMarketDataIteratorStartBySellMBLData(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ����
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMBLMarketDataIteratorStartBySellMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CMBLMarketData��������startFindStartBySellMBLData�Ժ�endFindStartBySellMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartBySellMBLData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pStartBySellMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradeIteratorAll��һ���Գɽ�ʹ��All��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorAll: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///���˶����Ƿ���������
	///@param	pTrade		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTrade *pTrade);

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
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CTradeIteratorAll(CTradeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CTradeIteratorAll *alloc(CTradeFactory *pFactory
		);

	///���췽��
	CTradeIteratorAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CTradeFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeIteratorAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTrade��������startFindAll�Ժ�endFindAll֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorByTradeID��һ���Գɽ�ʹ��ByTradeID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorByTradeID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///���˶����Ƿ���������
	///@param	pTrade		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTrade *pTrade);

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
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorByTradeID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TradeID	�ɽ����
	CTradeIteratorByTradeID(CTradeFactory *pFactory
		,const CReadOnlyTradeIDType& TradeID)
	{
		init(pFactory,TradeID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TradeID	�ɽ����
	static CTradeIteratorByTradeID *alloc(CTradeFactory *pFactory
		,const CReadOnlyTradeIDType& TradeID);

	///���췽��
	CTradeIteratorByTradeID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	TradeID	�ɽ����
	void init(CTradeFactory *pFactory
		,const CReadOnlyTradeIDType& TradeID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeIteratorByTradeID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTrade��������startFindByTradeID�Ժ�endFindByTradeID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByTradeID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pByTradeID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorStartByPartID��һ���Գɽ�ʹ��StartByPartID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorStartByPartID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///���˶����Ƿ���������
	///@param	pTrade		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTrade *pTrade);

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
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorStartByPartID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CTradeIteratorStartByPartID(CTradeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CTradeIteratorStartByPartID *alloc(CTradeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CTradeIteratorStartByPartID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CTradeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeIteratorStartByPartID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTrade��������startFindStartByPartID�Ժ�endFindStartByPartID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByPartID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pStartByPartID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorByClientID��һ���Գɽ�ʹ��ByClientID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorByClientID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///���˶����Ƿ���������
	///@param	pTrade		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTrade *pTrade);

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
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorByClientID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	CTradeIteratorByClientID(CTradeFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	static CTradeIteratorByClientID *alloc(CTradeFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///���췽��
	CTradeIteratorByClientID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	void init(CTradeFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeIteratorByClientID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTrade��������startFindByClientID�Ժ�endFindByClientID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByClientID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pByClientID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorStartByInstrumentID��һ���Գɽ�ʹ��StartByInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorStartByInstrumentID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///���˶����Ƿ���������
	///@param	pTrade		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTrade *pTrade);

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
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorStartByInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	CTradeIteratorStartByInstrumentID(CTradeFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	static CTradeIteratorStartByInstrumentID *alloc(CTradeFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CTradeIteratorStartByInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	InstrumentID	��Լ��
	void init(CTradeFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTrade��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pStartByInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorBySettlementGroupID��һ���Գɽ�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorBySettlementGroupID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///���˶����Ƿ���������
	///@param	pTrade		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CTrade *pTrade);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CTrade *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CTrade *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CTradeIteratorBySettlementGroupID(CTradeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CTradeIteratorBySettlementGroupID *alloc(CTradeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CTradeIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CTradeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CTrade��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseIteratorBySettlementGroupID��һ�����۶Ͻ׶�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseIteratorBySettlementGroupID: public CFusePhaseIterator
{
	friend class CFusePhaseFactory;
private:
	///���˶����Ƿ���������
	///@param	pFusePhase		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CFusePhase *pFusePhase);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CFusePhase *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CFusePhase *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableFusePhase m_compareObject;
	
	static CMemoryStack<CFusePhaseIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	CFusePhaseIteratorBySettlementGroupID(CFusePhaseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	static CFusePhaseIteratorBySettlementGroupID *alloc(CFusePhaseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CFusePhaseIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	void init(CFusePhaseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CFusePhaseIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CFusePhase��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CFusePhase������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFusePhase *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFusePhase * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorBySettlementGroupID��һ����ִ������ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorBySettlementGroupID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pExecOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CExecOrder *pExecOrder);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CExecOrder *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CExecOrder *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	CExecOrderIteratorBySettlementGroupID(CExecOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	static CExecOrderIteratorBySettlementGroupID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CExecOrderIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	void init(CExecOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExecOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CExecOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByParticipantID��һ����ִ������ʹ��ByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByParticipantID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pExecOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CExecOrder *pExecOrder);

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
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	CExecOrderIteratorByParticipantID(CExecOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	static CExecOrderIteratorByParticipantID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CExecOrderIteratorByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	��Ա��
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExecOrderIteratorByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CExecOrder��������startFindByParticipantID�Ժ�endFindByParticipantID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByClientID��һ����ִ������ʹ��ByClientID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByClientID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pExecOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CExecOrder *pExecOrder);

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
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByClientID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	CExecOrderIteratorByClientID(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	static CExecOrderIteratorByClientID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///���췽��
	CExecOrderIteratorByClientID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExecOrderIteratorByClientID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CExecOrder��������startFindByClientID�Ժ�endFindByClientID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByClientID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pByClientID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByClientIDAndInstrumentID��һ����ִ������ʹ��ByClientIDAndInstrumentID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByClientIDAndInstrumentID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pExecOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CExecOrder *pExecOrder);

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
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByClientIDAndInstrumentID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	CExecOrderIteratorByClientIDAndInstrumentID(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,ClientID,InstrumentID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	static CExecOrderIteratorByClientIDAndInstrumentID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///���췽��
	CExecOrderIteratorByClientIDAndInstrumentID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExecOrderIteratorByClientIDAndInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CExecOrder��������startFindByClientIDAndInstrumentID�Ժ�endFindByClientIDAndInstrumentID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByClientIDAndInstrumentID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pByClientIDAndInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByUserID��һ����ִ������ʹ��ByUserID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByUserID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///���˶����Ƿ���������
	///@param	pExecOrder		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CExecOrder *pExecOrder);

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
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByUserID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	CExecOrderIteratorByUserID(CExecOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	static CExecOrderIteratorByUserID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///���췽��
	CExecOrderIteratorByUserID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	UserID	����Ա����
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExecOrderIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CExecOrder��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pByUserID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureIteratorBySettlementGroupID��һ���Ե��������ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureIteratorBySettlementGroupID: public CUniPressureIterator
{
	friend class CUniPressureFactory;
private:
	///���˶����Ƿ���������
	///@param	pUniPressure		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CUniPressure *pUniPressure);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CUniPressure *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CUniPressure *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableUniPressure m_compareObject;
	
	static CMemoryStack<CUniPressureIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	CUniPressureIteratorBySettlementGroupID(CUniPressureFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	static CUniPressureIteratorBySettlementGroupID *alloc(CUniPressureFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CUniPressureIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	void init(CUniPressureFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUniPressureIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CUniPressure��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CUniPressure������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUniPressure *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUniPressure * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitIteratorBySettlementGroupID��һ�����ǵ�ͣ������ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitIteratorBySettlementGroupID: public CBasePriceLimitIterator
{
	friend class CBasePriceLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pBasePriceLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CBasePriceLimit *pBasePriceLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CBasePriceLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CBasePriceLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableBasePriceLimit m_compareObject;
	
	static CMemoryStack<CBasePriceLimitIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	CBasePriceLimitIteratorBySettlementGroupID(CBasePriceLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	static CBasePriceLimitIteratorBySettlementGroupID *alloc(CBasePriceLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CBasePriceLimitIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	��������
	void init(CBasePriceLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBasePriceLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CBasePriceLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CBasePriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBasePriceLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorBySettlementGroupID��һ���������޶�ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorBySettlementGroupID: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pCreditLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCreditLimit *pCreditLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCreditLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCreditLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCreditLimitIteratorBySettlementGroupID(CCreditLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCreditLimitIteratorBySettlementGroupID *alloc(CCreditLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCreditLimitIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCreditLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCreditLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCreditLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorAllByParticipantID��һ���������޶�ʹ��AllByParticipantID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorAllByParticipantID: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pCreditLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCreditLimit *pCreditLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCreditLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCreditLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorAllByParticipantID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	���׻�Ա���
	CCreditLimitIteratorAllByParticipantID(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	���׻�Ա���
	static CCreditLimitIteratorAllByParticipantID *alloc(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///���췽��
	CCreditLimitIteratorAllByParticipantID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ParticipantID	���׻�Ա���
	void init(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCreditLimitIteratorAllByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCreditLimit��������startFindAllByParticipantID�Ժ�endFindAllByParticipantID֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAllByParticipantID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pAllByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorAllByClearingPartID��һ���������޶�ʹ��AllByClearingPartID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorAllByClearingPartID: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pCreditLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCreditLimit *pCreditLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCreditLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCreditLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorAllByClearingPartID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClearingPartID	�����Ա���
	CCreditLimitIteratorAllByClearingPartID(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ClearingPartID)
	{
		init(pFactory,ClearingPartID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClearingPartID	�����Ա���
	static CCreditLimitIteratorAllByClearingPartID *alloc(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ClearingPartID);

	///���췽��
	CCreditLimitIteratorAllByClearingPartID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	ClearingPartID	�����Ա���
	void init(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ClearingPartID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCreditLimitIteratorAllByClearingPartID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCreditLimit��������startFindAllByClearingPartID�Ժ�endFindAllByClearingPartID֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAllByClearingPartID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pAllByClearingPartID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorAll��һ���������޶�ʹ��All��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorAll: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///���˶����Ƿ���������
	///@param	pCreditLimit		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCreditLimit *pCreditLimit);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCreditLimit *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCreditLimit *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorAll> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	CCreditLimitIteratorAll(CCreditLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	static CCreditLimitIteratorAll *alloc(CCreditLimitFactory *pFactory
		);

	///���췽��
	CCreditLimitIteratorAll(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	void init(CCreditLimitFactory *pFactory
		);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCreditLimitIteratorAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCreditLimit��������startFindAll�Ժ�endFindAll֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAll ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionIteratorBySettlementGroupID��һ���Ե����ڻ���Լ��Ȩ����ʹ��BySettlementGroupID��������
///���ҵ�ö����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionIteratorBySettlementGroupID: public CCurrInstrumentOptionIterator
{
	friend class CCurrInstrumentOptionFactory;
private:
	///���˶����Ƿ���������
	///@param	pCurrInstrumentOption		Ҫ�����Ķ���
	///@return	1��ʾ����������0��ʾ����������
	int match(CCurrInstrumentOption *pCurrInstrumentOption);

	///����Ҫ������£���ȡ��һ��ֵ��������ǵ�һ�Σ����һ�û��ȡ����һ��ֵ��
	///��ô�ͱ��뱣֤����ʱm_pCurrentָ����ȷ��ֵ�����򱾷����Ľ����ȷ��
	void internalGetNext(void);

	///�Ƿ��ǵ�һ�β�ѯ
	int m_isFirstTime;
	
	///�Ƿ��Ѿ�ȡ����һ������
	bool m_gotNext;

	///�洢���һ���ҵ��Ľڵ�
	///��m_isFirstTimeΪ1ʱ�����߷�����DeleteCurrentʱ����ֵ������
	CCurrInstrumentOption *m_pCurrent;
	
	///��m_gotNextΪtrueʱ����ֵ��һ��nextʱ�Ŀ�ʼѰ�ҵĽڵ㣬���������������
	CCurrInstrumentOption *m_pNext;

	///���ڴ洢��ѯ�����Ķ���
	CWriteableCurrInstrumentOption m_compareObject;
	
	static CMemoryStack<CCurrInstrumentOptionIteratorBySettlementGroupID> iteratorList;
public:
	///���췽��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	CCurrInstrumentOptionIteratorBySettlementGroupID(CCurrInstrumentOptionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///����һ���µĶ���
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	static CCurrInstrumentOptionIteratorBySettlementGroupID *alloc(CCurrInstrumentOptionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///���췽��
	CCurrInstrumentOptionIteratorBySettlementGroupID(void)
	{
	}

	///��ʼ��
	///@param	pFactory	Ҫ���ҵĶ��󹤳�
	///@param	SettlementGroupID	���������
	void init(CCurrInstrumentOptionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrInstrumentOptionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///Ѱ����һ������������CCurrInstrumentOption��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrInstrumentOption������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentOption *next(void);
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBySettlementGroupID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

#endif
