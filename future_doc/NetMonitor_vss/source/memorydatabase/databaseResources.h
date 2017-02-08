/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseResources.h
///@brief�����������ڴ�������Դ�����Է�����������
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASERESOURCES_H
#define DATABASERESOURCES_H

#include "databaseData.h"
#include "MemoryStack.h"

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusResource��һ��˵����CExchangeDataSyncStatusFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusResource : public CDatabaseResource
{
public:
	///���췽��
	CExchangeDataSyncStatusResource(void);
	virtual ~CExchangeDataSyncStatusResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CExchangeDataSyncStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CExchangeDataSyncStatusFactory *pFactory, CExchangeDataSyncStatus *pObject, CWriteableExchangeDataSyncStatus *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CExchangeDataSyncStatusFactory
	///@return	��CExchangeDataSyncStatusFactory
	CExchangeDataSyncStatusFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CExchangeDataSyncStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CExchangeDataSyncStatusResource *alloc(int type, CExchangeDataSyncStatusFactory *pFactory, CExchangeDataSyncStatus *pObject, CWriteableExchangeDataSyncStatus *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CExchangeDataSyncStatusFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableExchangeDataSyncStatus writeableObject;
	
	static CMemoryStack<CExchangeDataSyncStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusResource��һ��˵����CSGDataSyncStatusFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusResource : public CDatabaseResource
{
public:
	///���췽��
	CSGDataSyncStatusResource(void);
	virtual ~CSGDataSyncStatusResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSGDataSyncStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSGDataSyncStatusFactory *pFactory, CSGDataSyncStatus *pObject, CWriteableSGDataSyncStatus *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CSGDataSyncStatusFactory
	///@return	��CSGDataSyncStatusFactory
	CSGDataSyncStatusFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSGDataSyncStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSGDataSyncStatusResource *alloc(int type, CSGDataSyncStatusFactory *pFactory, CSGDataSyncStatus *pObject, CWriteableSGDataSyncStatus *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSGDataSyncStatusFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSGDataSyncStatus writeableObject;
	
	static CMemoryStack<CSGDataSyncStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeResource��һ��˵����CCurrentTimeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrentTimeResource(void);
	virtual ~CCurrentTimeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrentTimeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrentTimeFactory *pFactory, CCurrentTime *pObject, CWriteableCurrentTime *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrentTimeFactory
	///@return	��CCurrentTimeFactory
	CCurrentTimeFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrentTimeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrentTimeResource *alloc(int type, CCurrentTimeFactory *pFactory, CCurrentTime *pObject, CWriteableCurrentTime *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrentTimeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrentTime writeableObject;
	
	static CMemoryStack<CCurrentTimeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescResource��һ��˵����CDataCenterDescFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescResource : public CDatabaseResource
{
public:
	///���췽��
	CDataCenterDescResource(void);
	virtual ~CDataCenterDescResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CDataCenterDescFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CDataCenterDescFactory *pFactory, CDataCenterDesc *pObject, CWriteableDataCenterDesc *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CDataCenterDescFactory
	///@return	��CDataCenterDescFactory
	CDataCenterDescFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CDataCenterDescFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CDataCenterDescResource *alloc(int type, CDataCenterDescFactory *pFactory, CDataCenterDesc *pObject, CWriteableDataCenterDesc *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CDataCenterDescFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableDataCenterDesc writeableObject;
	
	static CMemoryStack<CDataCenterDescResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeResource��һ��˵����CExchangeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeResource : public CDatabaseResource
{
public:
	///���췽��
	CExchangeResource(void);
	virtual ~CExchangeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CExchangeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CExchangeFactory *pFactory, CExchange *pObject, CWriteableExchange *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CExchangeFactory
	///@return	��CExchangeFactory
	CExchangeFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CExchangeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CExchangeResource *alloc(int type, CExchangeFactory *pFactory, CExchange *pObject, CWriteableExchange *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CExchangeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableExchange writeableObject;
	
	static CMemoryStack<CExchangeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupResource��һ��˵����CSettlementGroupFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupResource : public CDatabaseResource
{
public:
	///���췽��
	CSettlementGroupResource(void);
	virtual ~CSettlementGroupResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSettlementGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSettlementGroupFactory *pFactory, CSettlementGroup *pObject, CWriteableSettlementGroup *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CSettlementGroupFactory
	///@return	��CSettlementGroupFactory
	CSettlementGroupFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSettlementGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSettlementGroupResource *alloc(int type, CSettlementGroupFactory *pFactory, CSettlementGroup *pObject, CWriteableSettlementGroup *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSettlementGroupFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSettlementGroup writeableObject;
	
	static CMemoryStack<CSettlementGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketResource��һ��˵����CMarketFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketResource : public CDatabaseResource
{
public:
	///���췽��
	CMarketResource(void);
	virtual ~CMarketResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMarketFactory *pFactory, CMarket *pObject, CWriteableMarket *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMarketFactory
	///@return	��CMarketFactory
	CMarketFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMarketResource *alloc(int type, CMarketFactory *pFactory, CMarket *pObject, CWriteableMarket *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMarketFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMarket writeableObject;
	
	static CMemoryStack<CMarketResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductResource��һ��˵����CMarketProductFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductResource : public CDatabaseResource
{
public:
	///���췽��
	CMarketProductResource(void);
	virtual ~CMarketProductResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketProductFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMarketProductFactory *pFactory, CMarketProduct *pObject, CWriteableMarketProduct *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMarketProductFactory
	///@return	��CMarketProductFactory
	CMarketProductFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketProductFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMarketProductResource *alloc(int type, CMarketProductFactory *pFactory, CMarketProduct *pObject, CWriteableMarketProduct *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMarketProductFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMarketProduct writeableObject;
	
	static CMemoryStack<CMarketProductResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupResource��һ��˵����CMarketProductGroupFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupResource : public CDatabaseResource
{
public:
	///���췽��
	CMarketProductGroupResource(void);
	virtual ~CMarketProductGroupResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketProductGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMarketProductGroupFactory *pFactory, CMarketProductGroup *pObject, CWriteableMarketProductGroup *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMarketProductGroupFactory
	///@return	��CMarketProductGroupFactory
	CMarketProductGroupFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketProductGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMarketProductGroupResource *alloc(int type, CMarketProductGroupFactory *pFactory, CMarketProductGroup *pObject, CWriteableMarketProductGroup *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMarketProductGroupFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMarketProductGroup writeableObject;
	
	static CMemoryStack<CMarketProductGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusResource��һ��˵����CMdPubStatusFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusResource : public CDatabaseResource
{
public:
	///���췽��
	CMdPubStatusResource(void);
	virtual ~CMdPubStatusResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMdPubStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMdPubStatusFactory *pFactory, CMdPubStatus *pObject, CWriteableMdPubStatus *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMdPubStatusFactory
	///@return	��CMdPubStatusFactory
	CMdPubStatusFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMdPubStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMdPubStatusResource *alloc(int type, CMdPubStatusFactory *pFactory, CMdPubStatus *pObject, CWriteableMdPubStatus *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMdPubStatusFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMdPubStatus writeableObject;
	
	static CMemoryStack<CMdPubStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicResource��һ��˵����CMarketDataTopicFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicResource : public CDatabaseResource
{
public:
	///���췽��
	CMarketDataTopicResource(void);
	virtual ~CMarketDataTopicResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataTopicFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMarketDataTopicFactory *pFactory, CMarketDataTopic *pObject, CWriteableMarketDataTopic *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMarketDataTopicFactory
	///@return	��CMarketDataTopicFactory
	CMarketDataTopicFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataTopicFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMarketDataTopicResource *alloc(int type, CMarketDataTopicFactory *pFactory, CMarketDataTopic *pObject, CWriteableMarketDataTopic *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMarketDataTopicFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMarketDataTopic writeableObject;
	
	static CMemoryStack<CMarketDataTopicResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeResource��һ��˵����CPartTopicSubscribeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeResource : public CDatabaseResource
{
public:
	///���췽��
	CPartTopicSubscribeResource(void);
	virtual ~CPartTopicSubscribeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartTopicSubscribeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartTopicSubscribeFactory *pFactory, CPartTopicSubscribe *pObject, CWriteablePartTopicSubscribe *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartTopicSubscribeFactory
	///@return	��CPartTopicSubscribeFactory
	CPartTopicSubscribeFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartTopicSubscribeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartTopicSubscribeResource *alloc(int type, CPartTopicSubscribeFactory *pFactory, CPartTopicSubscribe *pObject, CWriteablePartTopicSubscribe *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartTopicSubscribeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartTopicSubscribe writeableObject;
	
	static CMemoryStack<CPartTopicSubscribeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantResource��һ��˵����CParticipantFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantResource : public CDatabaseResource
{
public:
	///���췽��
	CParticipantResource(void);
	virtual ~CParticipantResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CParticipantFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CParticipantFactory *pFactory, CParticipant *pObject, CWriteableParticipant *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CParticipantFactory
	///@return	��CParticipantFactory
	CParticipantFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CParticipantFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CParticipantResource *alloc(int type, CParticipantFactory *pFactory, CParticipant *pObject, CWriteableParticipant *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CParticipantFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableParticipant writeableObject;
	
	static CMemoryStack<CParticipantResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserResource��һ��˵����CUserFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserResource : public CDatabaseResource
{
public:
	///���췽��
	CUserResource(void);
	virtual ~CUserResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CUserFactory *pFactory, CUser *pObject, CWriteableUser *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CUserFactory
	///@return	��CUserFactory
	CUserFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CUserResource *alloc(int type, CUserFactory *pFactory, CUser *pObject, CWriteableUser *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CUserFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableUser writeableObject;
	
	static CMemoryStack<CUserResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientResource��һ��˵����CClientFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientResource : public CDatabaseResource
{
public:
	///���췽��
	CClientResource(void);
	virtual ~CClientResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CClientFactory *pFactory, CClient *pObject, CWriteableClient *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CClientFactory
	///@return	��CClientFactory
	CClientFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CClientResource *alloc(int type, CClientFactory *pFactory, CClient *pObject, CWriteableClient *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CClientFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableClient writeableObject;
	
	static CMemoryStack<CClientResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPResource��һ��˵����CUserIPFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPResource : public CDatabaseResource
{
public:
	///���췽��
	CUserIPResource(void);
	virtual ~CUserIPResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserIPFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CUserIPFactory *pFactory, CUserIP *pObject, CWriteableUserIP *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CUserIPFactory
	///@return	��CUserIPFactory
	CUserIPFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserIPFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CUserIPResource *alloc(int type, CUserIPFactory *pFactory, CUserIP *pObject, CWriteableUserIP *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CUserIPFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableUserIP writeableObject;
	
	static CMemoryStack<CUserIPResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientResource��һ��˵����CPartClientFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientResource : public CDatabaseResource
{
public:
	///���췽��
	CPartClientResource(void);
	virtual ~CPartClientResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartClientFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartClientFactory *pFactory, CPartClient *pObject, CWriteablePartClient *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartClientFactory
	///@return	��CPartClientFactory
	CPartClientFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartClientFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartClientResource *alloc(int type, CPartClientFactory *pFactory, CPartClient *pObject, CWriteablePartClient *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartClientFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartClient writeableObject;
	
	static CMemoryStack<CPartClientResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartResource��һ��˵����CClearingTradingPartFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartResource : public CDatabaseResource
{
public:
	///���췽��
	CClearingTradingPartResource(void);
	virtual ~CClearingTradingPartResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClearingTradingPartFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CClearingTradingPartFactory *pFactory, CClearingTradingPart *pObject, CWriteableClearingTradingPart *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CClearingTradingPartFactory
	///@return	��CClearingTradingPartFactory
	CClearingTradingPartFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClearingTradingPartFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CClearingTradingPartResource *alloc(int type, CClearingTradingPartFactory *pFactory, CClearingTradingPart *pObject, CWriteableClearingTradingPart *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CClearingTradingPartFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableClearingTradingPart writeableObject;
	
	static CMemoryStack<CClearingTradingPartResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineResource��һ��˵����CAliasDefineFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineResource : public CDatabaseResource
{
public:
	///���췽��
	CAliasDefineResource(void);
	virtual ~CAliasDefineResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CAliasDefineFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CAliasDefineFactory *pFactory, CAliasDefine *pObject, CWriteableAliasDefine *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CAliasDefineFactory
	///@return	��CAliasDefineFactory
	CAliasDefineFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CAliasDefineFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CAliasDefineResource *alloc(int type, CAliasDefineFactory *pFactory, CAliasDefine *pObject, CWriteableAliasDefine *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CAliasDefineFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableAliasDefine writeableObject;
	
	static CMemoryStack<CAliasDefineResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightResource��һ��˵����CUserFunctionRightFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightResource : public CDatabaseResource
{
public:
	///���췽��
	CUserFunctionRightResource(void);
	virtual ~CUserFunctionRightResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserFunctionRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CUserFunctionRightFactory *pFactory, CUserFunctionRight *pObject, CWriteableUserFunctionRight *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CUserFunctionRightFactory
	///@return	��CUserFunctionRightFactory
	CUserFunctionRightFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserFunctionRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CUserFunctionRightResource *alloc(int type, CUserFunctionRightFactory *pFactory, CUserFunctionRight *pObject, CWriteableUserFunctionRight *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CUserFunctionRightFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableUserFunctionRight writeableObject;
	
	static CMemoryStack<CUserFunctionRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CAccountResource��һ��˵����CAccountFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountResource : public CDatabaseResource
{
public:
	///���췽��
	CAccountResource(void);
	virtual ~CAccountResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CAccountFactory *pFactory, CAccount *pObject, CWriteableAccount *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CAccountFactory
	///@return	��CAccountFactory
	CAccountFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CAccountResource *alloc(int type, CAccountFactory *pFactory, CAccount *pObject, CWriteableAccount *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CAccountFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableAccount writeableObject;
	
	static CMemoryStack<CAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxResource��һ��˵����CUserCommFluxFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxResource : public CDatabaseResource
{
public:
	///���췽��
	CUserCommFluxResource(void);
	virtual ~CUserCommFluxResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserCommFluxFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CUserCommFluxFactory *pFactory, CUserCommFlux *pObject, CWriteableUserCommFlux *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CUserCommFluxFactory
	///@return	��CUserCommFluxFactory
	CUserCommFluxFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserCommFluxFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CUserCommFluxResource *alloc(int type, CUserCommFluxFactory *pFactory, CUserCommFlux *pObject, CWriteableUserCommFlux *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CUserCommFluxFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableUserCommFlux writeableObject;
	
	static CMemoryStack<CUserCommFluxResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogResource��һ��˵����CMarketDataLogFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogResource : public CDatabaseResource
{
public:
	///���췽��
	CMarketDataLogResource(void);
	virtual ~CMarketDataLogResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataLogFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMarketDataLogFactory *pFactory, CMarketDataLog *pObject, CWriteableMarketDataLog *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMarketDataLogFactory
	///@return	��CMarketDataLogFactory
	CMarketDataLogFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataLogFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMarketDataLogResource *alloc(int type, CMarketDataLogFactory *pFactory, CMarketDataLog *pObject, CWriteableMarketDataLog *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMarketDataLogFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMarketDataLog writeableObject;
	
	static CMemoryStack<CMarketDataLogResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionResource��һ��˵����CUserSessionFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionResource : public CDatabaseResource
{
public:
	///���췽��
	CUserSessionResource(void);
	virtual ~CUserSessionResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserSessionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CUserSessionFactory *pFactory, CUserSession *pObject, CWriteableUserSession *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CUserSessionFactory
	///@return	��CUserSessionFactory
	CUserSessionFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUserSessionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CUserSessionResource *alloc(int type, CUserSessionFactory *pFactory, CUserSession *pObject, CWriteableUserSession *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CUserSessionFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableUserSession writeableObject;
	
	static CMemoryStack<CUserSessionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionResource��һ��˵����CMDSessionFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionResource : public CDatabaseResource
{
public:
	///���췽��
	CMDSessionResource(void);
	virtual ~CMDSessionResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMDSessionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMDSessionFactory *pFactory, CMDSession *pObject, CWriteableMDSession *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMDSessionFactory
	///@return	��CMDSessionFactory
	CMDSessionFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMDSessionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMDSessionResource *alloc(int type, CMDSessionFactory *pFactory, CMDSession *pObject, CWriteableMDSession *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMDSessionFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMDSession writeableObject;
	
	static CMemoryStack<CMDSessionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoResource��һ��˵����CLoginInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CLoginInfoResource(void);
	virtual ~CLoginInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CLoginInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CLoginInfoFactory *pFactory, CLoginInfo *pObject, CWriteableLoginInfo *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CLoginInfoFactory
	///@return	��CLoginInfoFactory
	CLoginInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CLoginInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CLoginInfoResource *alloc(int type, CLoginInfoFactory *pFactory, CLoginInfo *pObject, CWriteableLoginInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CLoginInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableLoginInfo writeableObject;
	
	static CMemoryStack<CLoginInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailResource��һ��˵����CDepthMarketDataDetailFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailResource : public CDatabaseResource
{
public:
	///���췽��
	CDepthMarketDataDetailResource(void);
	virtual ~CDepthMarketDataDetailResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CDepthMarketDataDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CDepthMarketDataDetailFactory *pFactory, CDepthMarketDataDetail *pObject, CWriteableDepthMarketDataDetail *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CDepthMarketDataDetailFactory
	///@return	��CDepthMarketDataDetailFactory
	CDepthMarketDataDetailFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CDepthMarketDataDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CDepthMarketDataDetailResource *alloc(int type, CDepthMarketDataDetailFactory *pFactory, CDepthMarketDataDetail *pObject, CWriteableDepthMarketDataDetail *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CDepthMarketDataDetailFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableDepthMarketDataDetail writeableObject;
	
	static CMemoryStack<CDepthMarketDataDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailResource��һ��˵����CInstrumentStatusDetailFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailResource : public CDatabaseResource
{
public:
	///���췽��
	CInstrumentStatusDetailResource(void);
	virtual ~CInstrumentStatusDetailResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInstrumentStatusDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CInstrumentStatusDetailFactory *pFactory, CInstrumentStatusDetail *pObject, CWriteableInstrumentStatusDetail *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CInstrumentStatusDetailFactory
	///@return	��CInstrumentStatusDetailFactory
	CInstrumentStatusDetailFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInstrumentStatusDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CInstrumentStatusDetailResource *alloc(int type, CInstrumentStatusDetailFactory *pFactory, CInstrumentStatusDetail *pObject, CWriteableInstrumentStatusDetail *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CInstrumentStatusDetailFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableInstrumentStatusDetail writeableObject;
	
	static CMemoryStack<CInstrumentStatusDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusResource��һ��˵����CFrontStatusFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusResource : public CDatabaseResource
{
public:
	///���췽��
	CFrontStatusResource(void);
	virtual ~CFrontStatusResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CFrontStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CFrontStatusFactory *pFactory, CFrontStatus *pObject, CWriteableFrontStatus *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CFrontStatusFactory
	///@return	��CFrontStatusFactory
	CFrontStatusFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CFrontStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CFrontStatusResource *alloc(int type, CFrontStatusFactory *pFactory, CFrontStatus *pObject, CWriteableFrontStatus *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CFrontStatusFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableFrontStatus writeableObject;
	
	static CMemoryStack<CFrontStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDResource��һ��˵����CMaxLocalIDFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDResource : public CDatabaseResource
{
public:
	///���췽��
	CMaxLocalIDResource(void);
	virtual ~CMaxLocalIDResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMaxLocalIDFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMaxLocalIDFactory *pFactory, CMaxLocalID *pObject, CWriteableMaxLocalID *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMaxLocalIDFactory
	///@return	��CMaxLocalIDFactory
	CMaxLocalIDFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMaxLocalIDFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMaxLocalIDResource *alloc(int type, CMaxLocalIDFactory *pFactory, CMaxLocalID *pObject, CWriteableMaxLocalID *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMaxLocalIDFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMaxLocalID writeableObject;
	
	static CMemoryStack<CMaxLocalIDResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinResource��һ��˵����CBulletinFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinResource : public CDatabaseResource
{
public:
	///���췽��
	CBulletinResource(void);
	virtual ~CBulletinResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CBulletinFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CBulletinFactory *pFactory, CBulletin *pObject, CWriteableBulletin *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CBulletinFactory
	///@return	��CBulletinFactory
	CBulletinFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CBulletinFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CBulletinResource *alloc(int type, CBulletinFactory *pFactory, CBulletin *pObject, CWriteableBulletin *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CBulletinFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableBulletin writeableObject;
	
	static CMemoryStack<CBulletinResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyResource��һ��˵����CMarketDataModifyFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyResource : public CDatabaseResource
{
public:
	///���췽��
	CMarketDataModifyResource(void);
	virtual ~CMarketDataModifyResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataModifyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMarketDataModifyFactory *pFactory, CMarketDataModify *pObject, CWriteableMarketDataModify *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMarketDataModifyFactory
	///@return	��CMarketDataModifyFactory
	CMarketDataModifyFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataModifyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMarketDataModifyResource *alloc(int type, CMarketDataModifyFactory *pFactory, CMarketDataModify *pObject, CWriteableMarketDataModify *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMarketDataModifyFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMarketDataModify writeableObject;
	
	static CMemoryStack<CMarketDataModifyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataResource��һ��˵����CDepthMarketDataFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataResource : public CDatabaseResource
{
public:
	///���췽��
	CDepthMarketDataResource(void);
	virtual ~CDepthMarketDataResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CDepthMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CDepthMarketDataFactory *pFactory, CDepthMarketData *pObject, CWriteableDepthMarketData *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CDepthMarketDataFactory
	///@return	��CDepthMarketDataFactory
	CDepthMarketDataFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CDepthMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CDepthMarketDataResource *alloc(int type, CDepthMarketDataFactory *pFactory, CDepthMarketData *pObject, CWriteableDepthMarketData *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CDepthMarketDataFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableDepthMarketData writeableObject;
	
	static CMemoryStack<CDepthMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataResource��һ��˵����CTopicMarketDataFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataResource : public CDatabaseResource
{
public:
	///���췽��
	CTopicMarketDataResource(void);
	virtual ~CTopicMarketDataResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTopicMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CTopicMarketDataFactory *pFactory, CTopicMarketData *pObject, CWriteableTopicMarketData *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CTopicMarketDataFactory
	///@return	��CTopicMarketDataFactory
	CTopicMarketDataFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTopicMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CTopicMarketDataResource *alloc(int type, CTopicMarketDataFactory *pFactory, CTopicMarketData *pObject, CWriteableTopicMarketData *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CTopicMarketDataFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableTopicMarketData writeableObject;
	
	static CMemoryStack<CTopicMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionResource��һ��˵����CTopicMarketDataVersionFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionResource : public CDatabaseResource
{
public:
	///���췽��
	CTopicMarketDataVersionResource(void);
	virtual ~CTopicMarketDataVersionResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTopicMarketDataVersionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CTopicMarketDataVersionFactory *pFactory, CTopicMarketDataVersion *pObject, CWriteableTopicMarketDataVersion *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CTopicMarketDataVersionFactory
	///@return	��CTopicMarketDataVersionFactory
	CTopicMarketDataVersionFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTopicMarketDataVersionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CTopicMarketDataVersionResource *alloc(int type, CTopicMarketDataVersionFactory *pFactory, CTopicMarketDataVersion *pObject, CWriteableTopicMarketDataVersion *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CTopicMarketDataVersionFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableTopicMarketDataVersion writeableObject;
	
	static CMemoryStack<CTopicMarketDataVersionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInformationResource��һ��˵����CInformationFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationResource : public CDatabaseResource
{
public:
	///���췽��
	CInformationResource(void);
	virtual ~CInformationResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInformationFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CInformationFactory *pFactory, CInformation *pObject, CWriteableInformation *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CInformationFactory
	///@return	��CInformationFactory
	CInformationFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInformationFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CInformationResource *alloc(int type, CInformationFactory *pFactory, CInformation *pObject, CWriteableInformation *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CInformationFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableInformation writeableObject;
	
	static CMemoryStack<CInformationResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountResource��һ��˵����COrderCountFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountResource : public CDatabaseResource
{
public:
	///���췽��
	COrderCountResource(void);
	virtual ~COrderCountResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�COrderCountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, COrderCountFactory *pFactory, COrderCount *pObject, CWriteableOrderCount *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�COrderCountFactory
	///@return	��COrderCountFactory
	COrderCountFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�COrderCountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static COrderCountResource *alloc(int type, COrderCountFactory *pFactory, COrderCount *pObject, CWriteableOrderCount *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	COrderCountFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableOrderCount writeableObject;
	
	static CMemoryStack<COrderCountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentResource��һ��˵����CInstrumentFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentResource : public CDatabaseResource
{
public:
	///���췽��
	CInstrumentResource(void);
	virtual ~CInstrumentResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInstrumentFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CInstrumentFactory *pFactory, CInstrument *pObject, CWriteableInstrument *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CInstrumentFactory
	///@return	��CInstrumentFactory
	CInstrumentFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInstrumentFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CInstrumentResource *alloc(int type, CInstrumentFactory *pFactory, CInstrument *pObject, CWriteableInstrument *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CInstrumentFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableInstrument writeableObject;
	
	static CMemoryStack<CInstrumentResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegResource��һ��˵����CCombinationLegFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegResource : public CDatabaseResource
{
public:
	///���췽��
	CCombinationLegResource(void);
	virtual ~CCombinationLegResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCombinationLegFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCombinationLegFactory *pFactory, CCombinationLeg *pObject, CWriteableCombinationLeg *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCombinationLegFactory
	///@return	��CCombinationLegFactory
	CCombinationLegFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCombinationLegFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCombinationLegResource *alloc(int type, CCombinationLegFactory *pFactory, CCombinationLeg *pObject, CWriteableCombinationLeg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCombinationLegFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCombinationLeg writeableObject;
	
	static CMemoryStack<CCombinationLegResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountResource��һ��˵����CPartRoleAccountFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountResource : public CDatabaseResource
{
public:
	///���췽��
	CPartRoleAccountResource(void);
	virtual ~CPartRoleAccountResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartRoleAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartRoleAccountFactory *pFactory, CPartRoleAccount *pObject, CWriteablePartRoleAccount *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartRoleAccountFactory
	///@return	��CPartRoleAccountFactory
	CPartRoleAccountFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartRoleAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartRoleAccountResource *alloc(int type, CPartRoleAccountFactory *pFactory, CPartRoleAccount *pObject, CWriteablePartRoleAccount *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartRoleAccountFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartRoleAccount writeableObject;
	
	static CMemoryStack<CPartRoleAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleResource��һ��˵����CPartProductRoleFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleResource : public CDatabaseResource
{
public:
	///���췽��
	CPartProductRoleResource(void);
	virtual ~CPartProductRoleResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartProductRoleFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartProductRoleFactory *pFactory, CPartProductRole *pObject, CWriteablePartProductRole *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartProductRoleFactory
	///@return	��CPartProductRoleFactory
	CPartProductRoleFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartProductRoleFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartProductRoleResource *alloc(int type, CPartProductRoleFactory *pFactory, CPartProductRole *pObject, CWriteablePartProductRole *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartProductRoleFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartProductRole writeableObject;
	
	static CMemoryStack<CPartProductRoleResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightResource��һ��˵����CPartProductRightFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightResource : public CDatabaseResource
{
public:
	///���췽��
	CPartProductRightResource(void);
	virtual ~CPartProductRightResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartProductRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartProductRightFactory *pFactory, CPartProductRight *pObject, CWriteablePartProductRight *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartProductRightFactory
	///@return	��CPartProductRightFactory
	CPartProductRightFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartProductRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartProductRightResource *alloc(int type, CPartProductRightFactory *pFactory, CPartProductRight *pObject, CWriteablePartProductRight *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartProductRightFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartProductRight writeableObject;
	
	static CMemoryStack<CPartProductRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightResource��һ��˵����CPartInstrumentRightFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightResource : public CDatabaseResource
{
public:
	///���췽��
	CPartInstrumentRightResource(void);
	virtual ~CPartInstrumentRightResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartInstrumentRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartInstrumentRightFactory *pFactory, CPartInstrumentRight *pObject, CWriteablePartInstrumentRight *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartInstrumentRightFactory
	///@return	��CPartInstrumentRightFactory
	CPartInstrumentRightFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartInstrumentRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartInstrumentRightResource *alloc(int type, CPartInstrumentRightFactory *pFactory, CPartInstrumentRight *pObject, CWriteablePartInstrumentRight *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartInstrumentRightFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartInstrumentRight writeableObject;
	
	static CMemoryStack<CPartInstrumentRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightResource��һ��˵����CClientProductRightFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightResource : public CDatabaseResource
{
public:
	///���췽��
	CClientProductRightResource(void);
	virtual ~CClientProductRightResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientProductRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CClientProductRightFactory *pFactory, CClientProductRight *pObject, CWriteableClientProductRight *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CClientProductRightFactory
	///@return	��CClientProductRightFactory
	CClientProductRightFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientProductRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CClientProductRightResource *alloc(int type, CClientProductRightFactory *pFactory, CClientProductRight *pObject, CWriteableClientProductRight *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CClientProductRightFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableClientProductRight writeableObject;
	
	static CMemoryStack<CClientProductRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightResource��һ��˵����CClientInstrumentRightFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightResource : public CDatabaseResource
{
public:
	///���췽��
	CClientInstrumentRightResource(void);
	virtual ~CClientInstrumentRightResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientInstrumentRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CClientInstrumentRightFactory *pFactory, CClientInstrumentRight *pObject, CWriteableClientInstrumentRight *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CClientInstrumentRightFactory
	///@return	��CClientInstrumentRightFactory
	CClientInstrumentRightFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientInstrumentRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CClientInstrumentRightResource *alloc(int type, CClientInstrumentRightFactory *pFactory, CClientInstrumentRight *pObject, CWriteableClientInstrumentRight *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CClientInstrumentRightFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableClientInstrumentRight writeableObject;
	
	static CMemoryStack<CClientInstrumentRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightResource��һ��˵����CPartClientProductRightFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightResource : public CDatabaseResource
{
public:
	///���췽��
	CPartClientProductRightResource(void);
	virtual ~CPartClientProductRightResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartClientProductRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartClientProductRightFactory *pFactory, CPartClientProductRight *pObject, CWriteablePartClientProductRight *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartClientProductRightFactory
	///@return	��CPartClientProductRightFactory
	CPartClientProductRightFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartClientProductRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartClientProductRightResource *alloc(int type, CPartClientProductRightFactory *pFactory, CPartClientProductRight *pObject, CWriteablePartClientProductRight *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartClientProductRightFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartClientProductRight writeableObject;
	
	static CMemoryStack<CPartClientProductRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightResource��һ��˵����CPartClientInstrumentRightFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightResource : public CDatabaseResource
{
public:
	///���췽��
	CPartClientInstrumentRightResource(void);
	virtual ~CPartClientInstrumentRightResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartClientInstrumentRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartClientInstrumentRightFactory *pFactory, CPartClientInstrumentRight *pObject, CWriteablePartClientInstrumentRight *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartClientInstrumentRightFactory
	///@return	��CPartClientInstrumentRightFactory
	CPartClientInstrumentRightFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartClientInstrumentRightFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartClientInstrumentRightResource *alloc(int type, CPartClientInstrumentRightFactory *pFactory, CPartClientInstrumentRight *pObject, CWriteablePartClientInstrumentRight *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartClientInstrumentRightFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartClientInstrumentRight writeableObject;
	
	static CMemoryStack<CPartClientInstrumentRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyResource��һ��˵����CCurrProductPropertyFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrProductPropertyResource(void);
	virtual ~CCurrProductPropertyResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrProductPropertyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrProductPropertyFactory *pFactory, CCurrProductProperty *pObject, CWriteableCurrProductProperty *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrProductPropertyFactory
	///@return	��CCurrProductPropertyFactory
	CCurrProductPropertyFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrProductPropertyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrProductPropertyResource *alloc(int type, CCurrProductPropertyFactory *pFactory, CCurrProductProperty *pObject, CWriteableCurrProductProperty *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrProductPropertyFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrProductProperty writeableObject;
	
	static CMemoryStack<CCurrProductPropertyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyResource��һ��˵����CCurrInstrumentPropertyFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrInstrumentPropertyResource(void);
	virtual ~CCurrInstrumentPropertyResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrInstrumentPropertyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrInstrumentPropertyFactory *pFactory, CCurrInstrumentProperty *pObject, CWriteableCurrInstrumentProperty *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrInstrumentPropertyFactory
	///@return	��CCurrInstrumentPropertyFactory
	CCurrInstrumentPropertyFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrInstrumentPropertyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrInstrumentPropertyResource *alloc(int type, CCurrInstrumentPropertyFactory *pFactory, CCurrInstrumentProperty *pObject, CWriteableCurrInstrumentProperty *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrInstrumentPropertyFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrInstrumentProperty writeableObject;
	
	static CMemoryStack<CCurrInstrumentPropertyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingResource��һ��˵����CCurrPriceBandingFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrPriceBandingResource(void);
	virtual ~CCurrPriceBandingResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrPriceBandingFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrPriceBandingFactory *pFactory, CCurrPriceBanding *pObject, CWriteableCurrPriceBanding *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrPriceBandingFactory
	///@return	��CCurrPriceBandingFactory
	CCurrPriceBandingFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrPriceBandingFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrPriceBandingResource *alloc(int type, CCurrPriceBandingFactory *pFactory, CCurrPriceBanding *pObject, CWriteableCurrPriceBanding *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrPriceBandingFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrPriceBanding writeableObject;
	
	static CMemoryStack<CCurrPriceBandingResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateResource��һ��˵����CCurrMarginRateFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrMarginRateResource(void);
	virtual ~CCurrMarginRateResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrMarginRateFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrMarginRateFactory *pFactory, CCurrMarginRate *pObject, CWriteableCurrMarginRate *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrMarginRateFactory
	///@return	��CCurrMarginRateFactory
	CCurrMarginRateFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrMarginRateFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrMarginRateResource *alloc(int type, CCurrMarginRateFactory *pFactory, CCurrMarginRate *pObject, CWriteableCurrMarginRate *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrMarginRateFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrMarginRate writeableObject;
	
	static CMemoryStack<CCurrMarginRateResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailResource��һ��˵����CCurrMarginRateDetailFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrMarginRateDetailResource(void);
	virtual ~CCurrMarginRateDetailResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrMarginRateDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrMarginRateDetailFactory *pFactory, CCurrMarginRateDetail *pObject, CWriteableCurrMarginRateDetail *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrMarginRateDetailFactory
	///@return	��CCurrMarginRateDetailFactory
	CCurrMarginRateDetailFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrMarginRateDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrMarginRateDetailResource *alloc(int type, CCurrMarginRateDetailFactory *pFactory, CCurrMarginRateDetail *pObject, CWriteableCurrMarginRateDetail *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrMarginRateDetailFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrMarginRateDetail writeableObject;
	
	static CMemoryStack<CCurrMarginRateDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitResource��һ��˵����CCurrPartPosiLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrPartPosiLimitResource(void);
	virtual ~CCurrPartPosiLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrPartPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrPartPosiLimitFactory *pFactory, CCurrPartPosiLimit *pObject, CWriteableCurrPartPosiLimit *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrPartPosiLimitFactory
	///@return	��CCurrPartPosiLimitFactory
	CCurrPartPosiLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrPartPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrPartPosiLimitResource *alloc(int type, CCurrPartPosiLimitFactory *pFactory, CCurrPartPosiLimit *pObject, CWriteableCurrPartPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrPartPosiLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrPartPosiLimit writeableObject;
	
	static CMemoryStack<CCurrPartPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailResource��һ��˵����CCurrPartPosiLimitDetailFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrPartPosiLimitDetailResource(void);
	virtual ~CCurrPartPosiLimitDetailResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrPartPosiLimitDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrPartPosiLimitDetailFactory *pFactory, CCurrPartPosiLimitDetail *pObject, CWriteableCurrPartPosiLimitDetail *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrPartPosiLimitDetailFactory
	///@return	��CCurrPartPosiLimitDetailFactory
	CCurrPartPosiLimitDetailFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrPartPosiLimitDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrPartPosiLimitDetailResource *alloc(int type, CCurrPartPosiLimitDetailFactory *pFactory, CCurrPartPosiLimitDetail *pObject, CWriteableCurrPartPosiLimitDetail *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrPartPosiLimitDetailFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrPartPosiLimitDetail writeableObject;
	
	static CMemoryStack<CCurrPartPosiLimitDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitResource��һ��˵����CCurrClientPosiLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrClientPosiLimitResource(void);
	virtual ~CCurrClientPosiLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrClientPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrClientPosiLimitFactory *pFactory, CCurrClientPosiLimit *pObject, CWriteableCurrClientPosiLimit *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrClientPosiLimitFactory
	///@return	��CCurrClientPosiLimitFactory
	CCurrClientPosiLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrClientPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrClientPosiLimitResource *alloc(int type, CCurrClientPosiLimitFactory *pFactory, CCurrClientPosiLimit *pObject, CWriteableCurrClientPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrClientPosiLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrClientPosiLimit writeableObject;
	
	static CMemoryStack<CCurrClientPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailResource��һ��˵����CCurrClientPosiLimitDetailFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrClientPosiLimitDetailResource(void);
	virtual ~CCurrClientPosiLimitDetailResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrClientPosiLimitDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrClientPosiLimitDetailFactory *pFactory, CCurrClientPosiLimitDetail *pObject, CWriteableCurrClientPosiLimitDetail *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrClientPosiLimitDetailFactory
	///@return	��CCurrClientPosiLimitDetailFactory
	CCurrClientPosiLimitDetailFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrClientPosiLimitDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrClientPosiLimitDetailResource *alloc(int type, CCurrClientPosiLimitDetailFactory *pFactory, CCurrClientPosiLimitDetail *pObject, CWriteableCurrClientPosiLimitDetail *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrClientPosiLimitDetailFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrClientPosiLimitDetail writeableObject;
	
	static CMemoryStack<CCurrClientPosiLimitDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitResource��һ��˵����CCurrSpecialPosiLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrSpecialPosiLimitResource(void);
	virtual ~CCurrSpecialPosiLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrSpecialPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrSpecialPosiLimitFactory *pFactory, CCurrSpecialPosiLimit *pObject, CWriteableCurrSpecialPosiLimit *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrSpecialPosiLimitFactory
	///@return	��CCurrSpecialPosiLimitFactory
	CCurrSpecialPosiLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrSpecialPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrSpecialPosiLimitResource *alloc(int type, CCurrSpecialPosiLimitFactory *pFactory, CCurrSpecialPosiLimit *pObject, CWriteableCurrSpecialPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrSpecialPosiLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrSpecialPosiLimit writeableObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailResource��һ��˵����CCurrSpecialPosiLimitDetailFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrSpecialPosiLimitDetailResource(void);
	virtual ~CCurrSpecialPosiLimitDetailResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrSpecialPosiLimitDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrSpecialPosiLimitDetailFactory *pFactory, CCurrSpecialPosiLimitDetail *pObject, CWriteableCurrSpecialPosiLimitDetail *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrSpecialPosiLimitDetailFactory
	///@return	��CCurrSpecialPosiLimitDetailFactory
	CCurrSpecialPosiLimitDetailFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrSpecialPosiLimitDetailFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrSpecialPosiLimitDetailResource *alloc(int type, CCurrSpecialPosiLimitDetailFactory *pFactory, CCurrSpecialPosiLimitDetail *pObject, CWriteableCurrSpecialPosiLimitDetail *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrSpecialPosiLimitDetailFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrSpecialPosiLimitDetail writeableObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleResource��һ��˵����CCurrHedgeRuleFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrHedgeRuleResource(void);
	virtual ~CCurrHedgeRuleResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrHedgeRuleFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrHedgeRuleFactory *pFactory, CCurrHedgeRule *pObject, CWriteableCurrHedgeRule *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrHedgeRuleFactory
	///@return	��CCurrHedgeRuleFactory
	CCurrHedgeRuleFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrHedgeRuleFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrHedgeRuleResource *alloc(int type, CCurrHedgeRuleFactory *pFactory, CCurrHedgeRule *pObject, CWriteableCurrHedgeRule *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrHedgeRuleFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrHedgeRule writeableObject;
	
	static CMemoryStack<CCurrHedgeRuleResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrResource��һ��˵����CCurrTradingSegmentAttrFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrTradingSegmentAttrResource(void);
	virtual ~CCurrTradingSegmentAttrResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrTradingSegmentAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrTradingSegmentAttrFactory *pFactory, CCurrTradingSegmentAttr *pObject, CWriteableCurrTradingSegmentAttr *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrTradingSegmentAttrFactory
	///@return	��CCurrTradingSegmentAttrFactory
	CCurrTradingSegmentAttrFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrTradingSegmentAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrTradingSegmentAttrResource *alloc(int type, CCurrTradingSegmentAttrFactory *pFactory, CCurrTradingSegmentAttr *pObject, CWriteableCurrTradingSegmentAttr *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrTradingSegmentAttrFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrTradingSegmentAttr writeableObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseResource��һ��˵����CCurrFuseFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrFuseResource(void);
	virtual ~CCurrFuseResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrFuseFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrFuseFactory *pFactory, CCurrFuse *pObject, CWriteableCurrFuse *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrFuseFactory
	///@return	��CCurrFuseFactory
	CCurrFuseFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrFuseFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrFuseResource *alloc(int type, CCurrFuseFactory *pFactory, CCurrFuse *pObject, CWriteableCurrFuse *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrFuseFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrFuse writeableObject;
	
	static CMemoryStack<CCurrFuseResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountResource��һ��˵����CTradingAccountFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountResource : public CDatabaseResource
{
public:
	///���췽��
	CTradingAccountResource(void);
	virtual ~CTradingAccountResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTradingAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CTradingAccountFactory *pFactory, CTradingAccount *pObject, CWriteableTradingAccount *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CTradingAccountFactory
	///@return	��CTradingAccountFactory
	CTradingAccountFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTradingAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CTradingAccountResource *alloc(int type, CTradingAccountFactory *pFactory, CTradingAccount *pObject, CWriteableTradingAccount *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CTradingAccountFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableTradingAccount writeableObject;
	
	static CMemoryStack<CTradingAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountResource��һ��˵����CBaseReserveAccountFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountResource : public CDatabaseResource
{
public:
	///���췽��
	CBaseReserveAccountResource(void);
	virtual ~CBaseReserveAccountResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CBaseReserveAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CBaseReserveAccountFactory *pFactory, CBaseReserveAccount *pObject, CWriteableBaseReserveAccount *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CBaseReserveAccountFactory
	///@return	��CBaseReserveAccountFactory
	CBaseReserveAccountFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CBaseReserveAccountFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CBaseReserveAccountResource *alloc(int type, CBaseReserveAccountFactory *pFactory, CBaseReserveAccount *pObject, CWriteableBaseReserveAccount *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CBaseReserveAccountFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableBaseReserveAccount writeableObject;
	
	static CMemoryStack<CBaseReserveAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionResource��һ��˵����CPartPositionFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionResource : public CDatabaseResource
{
public:
	///���췽��
	CPartPositionResource(void);
	virtual ~CPartPositionResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartPositionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CPartPositionFactory *pFactory, CPartPosition *pObject, CWriteablePartPosition *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CPartPositionFactory
	///@return	��CPartPositionFactory
	CPartPositionFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CPartPositionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CPartPositionResource *alloc(int type, CPartPositionFactory *pFactory, CPartPosition *pObject, CWriteablePartPosition *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CPartPositionFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteablePartPosition writeableObject;
	
	static CMemoryStack<CPartPositionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionResource��һ��˵����CClientPositionFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionResource : public CDatabaseResource
{
public:
	///���췽��
	CClientPositionResource(void);
	virtual ~CClientPositionResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientPositionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CClientPositionFactory *pFactory, CClientPosition *pObject, CWriteableClientPosition *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CClientPositionFactory
	///@return	��CClientPositionFactory
	CClientPositionFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClientPositionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CClientPositionResource *alloc(int type, CClientPositionFactory *pFactory, CClientPosition *pObject, CWriteableClientPosition *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CClientPositionFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableClientPosition writeableObject;
	
	static CMemoryStack<CClientPositionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeResource��һ��˵����CHedgeVolumeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeResource : public CDatabaseResource
{
public:
	///���췽��
	CHedgeVolumeResource(void);
	virtual ~CHedgeVolumeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CHedgeVolumeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CHedgeVolumeFactory *pFactory, CHedgeVolume *pObject, CWriteableHedgeVolume *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CHedgeVolumeFactory
	///@return	��CHedgeVolumeFactory
	CHedgeVolumeFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CHedgeVolumeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CHedgeVolumeResource *alloc(int type, CHedgeVolumeFactory *pFactory, CHedgeVolume *pObject, CWriteableHedgeVolume *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CHedgeVolumeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableHedgeVolume writeableObject;
	
	static CMemoryStack<CHedgeVolumeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderResource��һ��˵����CRemainOrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderResource : public CDatabaseResource
{
public:
	///���췽��
	CRemainOrderResource(void);
	virtual ~CRemainOrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRemainOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRemainOrderFactory *pFactory, CRemainOrder *pObject, CWriteableRemainOrder *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CRemainOrderFactory
	///@return	��CRemainOrderFactory
	CRemainOrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRemainOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRemainOrderResource *alloc(int type, CRemainOrderFactory *pFactory, CRemainOrder *pObject, CWriteableRemainOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRemainOrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRemainOrder writeableObject;
	
	static CMemoryStack<CRemainOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataResource��һ��˵����CMarketDataFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataResource : public CDatabaseResource
{
public:
	///���췽��
	CMarketDataResource(void);
	virtual ~CMarketDataResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMarketDataFactory *pFactory, CMarketData *pObject, CWriteableMarketData *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMarketDataFactory
	///@return	��CMarketDataFactory
	CMarketDataFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMarketDataResource *alloc(int type, CMarketDataFactory *pFactory, CMarketData *pObject, CWriteableMarketData *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMarketDataFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMarketData writeableObject;
	
	static CMemoryStack<CMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionResource��һ��˵����CClearingPartPositionFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionResource : public CDatabaseResource
{
public:
	///���췽��
	CClearingPartPositionResource(void);
	virtual ~CClearingPartPositionResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClearingPartPositionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CClearingPartPositionFactory *pFactory, CClearingPartPosition *pObject, CWriteableClearingPartPosition *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CClearingPartPositionFactory
	///@return	��CClearingPartPositionFactory
	CClearingPartPositionFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CClearingPartPositionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CClearingPartPositionResource *alloc(int type, CClearingPartPositionFactory *pFactory, CClearingPartPosition *pObject, CWriteableClearingPartPosition *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CClearingPartPositionFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableClearingPartPosition writeableObject;
	
	static CMemoryStack<CClearingPartPositionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusResource��һ��˵����CInstrumentStatusFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusResource : public CDatabaseResource
{
public:
	///���췽��
	CInstrumentStatusResource(void);
	virtual ~CInstrumentStatusResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInstrumentStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CInstrumentStatusFactory *pFactory, CInstrumentStatus *pObject, CWriteableInstrumentStatus *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CInstrumentStatusFactory
	///@return	��CInstrumentStatusFactory
	CInstrumentStatusFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CInstrumentStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CInstrumentStatusResource *alloc(int type, CInstrumentStatusFactory *pFactory, CInstrumentStatus *pObject, CWriteableInstrumentStatus *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CInstrumentStatusFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableInstrumentStatus writeableObject;
	
	static CMemoryStack<CInstrumentStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///COrderResource��һ��˵����COrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderResource : public CDatabaseResource
{
public:
	///���췽��
	COrderResource(void);
	virtual ~COrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�COrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, COrderFactory *pFactory, COrder *pObject, CWriteableOrder *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�COrderFactory
	///@return	��COrderFactory
	COrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�COrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static COrderResource *alloc(int type, COrderFactory *pFactory, COrder *pObject, CWriteableOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	COrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableOrder writeableObject;
	
	static CMemoryStack<COrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderResource��һ��˵����CCombOrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderResource : public CDatabaseResource
{
public:
	///���췽��
	CCombOrderResource(void);
	virtual ~CCombOrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCombOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCombOrderFactory *pFactory, CCombOrder *pObject, CWriteableCombOrder *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCombOrderFactory
	///@return	��CCombOrderFactory
	CCombOrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCombOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCombOrderResource *alloc(int type, CCombOrderFactory *pFactory, CCombOrder *pObject, CWriteableCombOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCombOrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCombOrder writeableObject;
	
	static CMemoryStack<CCombOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderResource��һ��˵����COTCOrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderResource : public CDatabaseResource
{
public:
	///���췽��
	COTCOrderResource(void);
	virtual ~COTCOrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�COTCOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, COTCOrderFactory *pFactory, COTCOrder *pObject, CWriteableOTCOrder *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�COTCOrderFactory
	///@return	��COTCOrderFactory
	COTCOrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�COTCOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static COTCOrderResource *alloc(int type, COTCOrderFactory *pFactory, COTCOrder *pObject, CWriteableOTCOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	COTCOrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableOTCOrder writeableObject;
	
	static CMemoryStack<COTCOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderResource��һ��˵����CImplyOrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderResource : public CDatabaseResource
{
public:
	///���췽��
	CImplyOrderResource(void);
	virtual ~CImplyOrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CImplyOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CImplyOrderFactory *pFactory, CImplyOrder *pObject, CWriteableImplyOrder *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CImplyOrderFactory
	///@return	��CImplyOrderFactory
	CImplyOrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CImplyOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CImplyOrderResource *alloc(int type, CImplyOrderFactory *pFactory, CImplyOrder *pObject, CWriteableImplyOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CImplyOrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableImplyOrder writeableObject;
	
	static CMemoryStack<CImplyOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteResource��һ��˵����CQuoteFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteResource : public CDatabaseResource
{
public:
	///���췽��
	CQuoteResource(void);
	virtual ~CQuoteResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CQuoteFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CQuoteFactory *pFactory, CQuote *pObject, CWriteableQuote *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CQuoteFactory
	///@return	��CQuoteFactory
	CQuoteFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CQuoteFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CQuoteResource *alloc(int type, CQuoteFactory *pFactory, CQuote *pObject, CWriteableQuote *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CQuoteFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableQuote writeableObject;
	
	static CMemoryStack<CQuoteResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataResource��һ��˵����CMBLMarketDataFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataResource : public CDatabaseResource
{
public:
	///���췽��
	CMBLMarketDataResource(void);
	virtual ~CMBLMarketDataResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMBLMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CMBLMarketDataFactory *pFactory, CMBLMarketData *pObject, CWriteableMBLMarketData *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CMBLMarketDataFactory
	///@return	��CMBLMarketDataFactory
	CMBLMarketDataFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CMBLMarketDataFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CMBLMarketDataResource *alloc(int type, CMBLMarketDataFactory *pFactory, CMBLMarketData *pObject, CWriteableMBLMarketData *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CMBLMarketDataFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableMBLMarketData writeableObject;
	
	static CMemoryStack<CMBLMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTradeResource��һ��˵����CTradeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeResource : public CDatabaseResource
{
public:
	///���췽��
	CTradeResource(void);
	virtual ~CTradeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTradeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CTradeFactory *pFactory, CTrade *pObject, CWriteableTrade *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CTradeFactory
	///@return	��CTradeFactory
	CTradeFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CTradeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CTradeResource *alloc(int type, CTradeFactory *pFactory, CTrade *pObject, CWriteableTrade *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CTradeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableTrade writeableObject;
	
	static CMemoryStack<CTradeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseResource��һ��˵����CFusePhaseFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseResource : public CDatabaseResource
{
public:
	///���췽��
	CFusePhaseResource(void);
	virtual ~CFusePhaseResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CFusePhaseFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CFusePhaseFactory *pFactory, CFusePhase *pObject, CWriteableFusePhase *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CFusePhaseFactory
	///@return	��CFusePhaseFactory
	CFusePhaseFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CFusePhaseFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CFusePhaseResource *alloc(int type, CFusePhaseFactory *pFactory, CFusePhase *pObject, CWriteableFusePhase *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CFusePhaseFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableFusePhase writeableObject;
	
	static CMemoryStack<CFusePhaseResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderResource��һ��˵����CExecOrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderResource : public CDatabaseResource
{
public:
	///���췽��
	CExecOrderResource(void);
	virtual ~CExecOrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CExecOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CExecOrderFactory *pFactory, CExecOrder *pObject, CWriteableExecOrder *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CExecOrderFactory
	///@return	��CExecOrderFactory
	CExecOrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CExecOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CExecOrderResource *alloc(int type, CExecOrderFactory *pFactory, CExecOrder *pObject, CWriteableExecOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CExecOrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableExecOrder writeableObject;
	
	static CMemoryStack<CExecOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureResource��һ��˵����CUniPressureFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureResource : public CDatabaseResource
{
public:
	///���췽��
	CUniPressureResource(void);
	virtual ~CUniPressureResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUniPressureFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CUniPressureFactory *pFactory, CUniPressure *pObject, CWriteableUniPressure *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CUniPressureFactory
	///@return	��CUniPressureFactory
	CUniPressureFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CUniPressureFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CUniPressureResource *alloc(int type, CUniPressureFactory *pFactory, CUniPressure *pObject, CWriteableUniPressure *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CUniPressureFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableUniPressure writeableObject;
	
	static CMemoryStack<CUniPressureResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitResource��һ��˵����CBasePriceLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CBasePriceLimitResource(void);
	virtual ~CBasePriceLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CBasePriceLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CBasePriceLimitFactory *pFactory, CBasePriceLimit *pObject, CWriteableBasePriceLimit *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CBasePriceLimitFactory
	///@return	��CBasePriceLimitFactory
	CBasePriceLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CBasePriceLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CBasePriceLimitResource *alloc(int type, CBasePriceLimitFactory *pFactory, CBasePriceLimit *pObject, CWriteableBasePriceLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CBasePriceLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableBasePriceLimit writeableObject;
	
	static CMemoryStack<CBasePriceLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitResource��һ��˵����CCreditLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CCreditLimitResource(void);
	virtual ~CCreditLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCreditLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCreditLimitFactory *pFactory, CCreditLimit *pObject, CWriteableCreditLimit *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCreditLimitFactory
	///@return	��CCreditLimitFactory
	CCreditLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCreditLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCreditLimitResource *alloc(int type, CCreditLimitFactory *pFactory, CCreditLimit *pObject, CWriteableCreditLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCreditLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCreditLimit writeableObject;
	
	static CMemoryStack<CCreditLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionResource��һ��˵����CCurrInstrumentOptionFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionResource : public CDatabaseResource
{
public:
	///���췽��
	CCurrInstrumentOptionResource(void);
	virtual ~CCurrInstrumentOptionResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrInstrumentOptionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CCurrInstrumentOptionFactory *pFactory, CCurrInstrumentOption *pObject, CWriteableCurrInstrumentOption *pWriteableObject, bool updateIndex=true)
	{
		m_type=type;
		m_updateIndex=updateIndex;
		this->pFactory=pFactory;
		this->ref=(void *)pObject;
		switch (type)
		{
		case CREATE_ACTION:
			break;
		case UPDATE_ACTION:
		case DELETE_ACTION:
			pFactory->retrieve(pObject,&writeableObject);
			break;
		default:
			RAISE_DESIGN_ERROR("Invalid resource type");
		}				
	}

	///�ͷ��Լ�
	virtual void free(void);

	///��ȡ����Դ���ڵ�CCurrInstrumentOptionFactory
	///@return	��CCurrInstrumentOptionFactory
	CCurrInstrumentOptionFactory *getFactory(void)
	{
		return pFactory;
	}

	///����ύ
	virtual void commit(void);
	
	///��ɹ���
	virtual void rollback(void);
	
	///��ȡ���ȼ������ȼ����Կ���commitʱ�Ĵ���
	///@return	����Դ�����ȼ���0��ʾ��ߣ�1��ʾ������1��ʾ���
	virtual int getPriority(void);

	///����һ����ָ�����ݵ���Դ
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CCurrInstrumentOptionFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CCurrInstrumentOptionResource *alloc(int type, CCurrInstrumentOptionFactory *pFactory, CCurrInstrumentOption *pObject, CWriteableCurrInstrumentOption *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CCurrInstrumentOptionFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableCurrInstrumentOption writeableObject;
	
	static CMemoryStack<CCurrInstrumentOptionResource> resourceList;
};

#endif
