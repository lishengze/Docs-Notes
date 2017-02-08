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
///CSysInvalidateOrderResource��һ��˵����CSysInvalidateOrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderResource : public CDatabaseResource
{
public:
	///���췽��
	CSysInvalidateOrderResource(void);
	virtual ~CSysInvalidateOrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysInvalidateOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysInvalidateOrderFactory *pFactory, CSysInvalidateOrder *pObject, CWriteableSysInvalidateOrder *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysInvalidateOrderFactory
	///@return	��CSysInvalidateOrderFactory
	CSysInvalidateOrderFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysInvalidateOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysInvalidateOrderResource *alloc(int type, CSysInvalidateOrderFactory *pFactory, CSysInvalidateOrder *pObject, CWriteableSysInvalidateOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysInvalidateOrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysInvalidateOrder writeableObject;
	
	static CMemoryStack<CSysInvalidateOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusResource��һ��˵����CSysOrderStatusFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusResource : public CDatabaseResource
{
public:
	///���췽��
	CSysOrderStatusResource(void);
	virtual ~CSysOrderStatusResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysOrderStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysOrderStatusFactory *pFactory, CSysOrderStatus *pObject, CWriteableSysOrderStatus *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysOrderStatusFactory
	///@return	��CSysOrderStatusFactory
	CSysOrderStatusFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysOrderStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysOrderStatusResource *alloc(int type, CSysOrderStatusFactory *pFactory, CSysOrderStatus *pObject, CWriteableSysOrderStatus *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysOrderStatusFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysOrderStatus writeableObject;
	
	static CMemoryStack<CSysOrderStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderResource��һ��˵����CSysBargainOrderFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderResource : public CDatabaseResource
{
public:
	///���췽��
	CSysBargainOrderResource(void);
	virtual ~CSysBargainOrderResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysBargainOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysBargainOrderFactory *pFactory, CSysBargainOrder *pObject, CWriteableSysBargainOrder *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysBargainOrderFactory
	///@return	��CSysBargainOrderFactory
	CSysBargainOrderFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysBargainOrderFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysBargainOrderResource *alloc(int type, CSysBargainOrderFactory *pFactory, CSysBargainOrder *pObject, CWriteableSysBargainOrder *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysBargainOrderFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysBargainOrder writeableObject;
	
	static CMemoryStack<CSysBargainOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyResource��һ��˵����CSysInstPropertyFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyResource : public CDatabaseResource
{
public:
	///���췽��
	CSysInstPropertyResource(void);
	virtual ~CSysInstPropertyResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysInstPropertyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysInstPropertyFactory *pFactory, CSysInstProperty *pObject, CWriteableSysInstProperty *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysInstPropertyFactory
	///@return	��CSysInstPropertyFactory
	CSysInstPropertyFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysInstPropertyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysInstPropertyResource *alloc(int type, CSysInstPropertyFactory *pFactory, CSysInstProperty *pObject, CWriteableSysInstProperty *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysInstPropertyFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysInstProperty writeableObject;
	
	static CMemoryStack<CSysInstPropertyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateResource��һ��˵����CSysMarginRateFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMarginRateResource(void);
	virtual ~CSysMarginRateResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMarginRateFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMarginRateFactory *pFactory, CSysMarginRate *pObject, CWriteableSysMarginRate *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMarginRateFactory
	///@return	��CSysMarginRateFactory
	CSysMarginRateFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMarginRateFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMarginRateResource *alloc(int type, CSysMarginRateFactory *pFactory, CSysMarginRate *pObject, CWriteableSysMarginRate *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMarginRateFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMarginRate writeableObject;
	
	static CMemoryStack<CSysMarginRateResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitResource��һ��˵����CSysPriceLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CSysPriceLimitResource(void);
	virtual ~CSysPriceLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysPriceLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysPriceLimitFactory *pFactory, CSysPriceLimit *pObject, CWriteableSysPriceLimit *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysPriceLimitFactory
	///@return	��CSysPriceLimitFactory
	CSysPriceLimitFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysPriceLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysPriceLimitResource *alloc(int type, CSysPriceLimitFactory *pFactory, CSysPriceLimit *pObject, CWriteableSysPriceLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysPriceLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysPriceLimit writeableObject;
	
	static CMemoryStack<CSysPriceLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitResource��һ��˵����CSysPartPosiLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CSysPartPosiLimitResource(void);
	virtual ~CSysPartPosiLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysPartPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysPartPosiLimitFactory *pFactory, CSysPartPosiLimit *pObject, CWriteableSysPartPosiLimit *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysPartPosiLimitFactory
	///@return	��CSysPartPosiLimitFactory
	CSysPartPosiLimitFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysPartPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysPartPosiLimitResource *alloc(int type, CSysPartPosiLimitFactory *pFactory, CSysPartPosiLimit *pObject, CWriteableSysPartPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysPartPosiLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysPartPosiLimit writeableObject;
	
	static CMemoryStack<CSysPartPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitResource��һ��˵����CSysClientPosiLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CSysClientPosiLimitResource(void);
	virtual ~CSysClientPosiLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysClientPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysClientPosiLimitFactory *pFactory, CSysClientPosiLimit *pObject, CWriteableSysClientPosiLimit *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysClientPosiLimitFactory
	///@return	��CSysClientPosiLimitFactory
	CSysClientPosiLimitFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysClientPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysClientPosiLimitResource *alloc(int type, CSysClientPosiLimitFactory *pFactory, CSysClientPosiLimit *pObject, CWriteableSysClientPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysClientPosiLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysClientPosiLimit writeableObject;
	
	static CMemoryStack<CSysClientPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitResource��һ��˵����CSysSpecialPosiLimitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitResource : public CDatabaseResource
{
public:
	///���췽��
	CSysSpecialPosiLimitResource(void);
	virtual ~CSysSpecialPosiLimitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysSpecialPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysSpecialPosiLimitFactory *pFactory, CSysSpecialPosiLimit *pObject, CWriteableSysSpecialPosiLimit *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysSpecialPosiLimitFactory
	///@return	��CSysSpecialPosiLimitFactory
	CSysSpecialPosiLimitFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysSpecialPosiLimitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysSpecialPosiLimitResource *alloc(int type, CSysSpecialPosiLimitFactory *pFactory, CSysSpecialPosiLimit *pObject, CWriteableSysSpecialPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysSpecialPosiLimitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysSpecialPosiLimit writeableObject;
	
	static CMemoryStack<CSysSpecialPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgResource��һ��˵����CSysTransactionChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysTransactionChgResource(void);
	virtual ~CSysTransactionChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysTransactionChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysTransactionChgFactory *pFactory, CSysTransactionChg *pObject, CWriteableSysTransactionChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysTransactionChgFactory
	///@return	��CSysTransactionChgFactory
	CSysTransactionChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysTransactionChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysTransactionChgResource *alloc(int type, CSysTransactionChgFactory *pFactory, CSysTransactionChg *pObject, CWriteableSysTransactionChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysTransactionChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysTransactionChg writeableObject;
	
	static CMemoryStack<CSysTransactionChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgResource��һ��˵����CSysClientChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysClientChgResource(void);
	virtual ~CSysClientChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysClientChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysClientChgFactory *pFactory, CSysClientChg *pObject, CWriteableSysClientChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysClientChgFactory
	///@return	��CSysClientChgFactory
	CSysClientChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysClientChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysClientChgResource *alloc(int type, CSysClientChgFactory *pFactory, CSysClientChg *pObject, CWriteableSysClientChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysClientChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysClientChg writeableObject;
	
	static CMemoryStack<CSysClientChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgResource��һ��˵����CSysPartClientChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysPartClientChgResource(void);
	virtual ~CSysPartClientChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysPartClientChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysPartClientChgFactory *pFactory, CSysPartClientChg *pObject, CWriteableSysPartClientChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysPartClientChgFactory
	///@return	��CSysPartClientChgFactory
	CSysPartClientChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysPartClientChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysPartClientChgResource *alloc(int type, CSysPartClientChgFactory *pFactory, CSysPartClientChg *pObject, CWriteableSysPartClientChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysPartClientChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysPartClientChg writeableObject;
	
	static CMemoryStack<CSysPartClientChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgResource��һ��˵����CSysPosiLimitChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysPosiLimitChgResource(void);
	virtual ~CSysPosiLimitChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysPosiLimitChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysPosiLimitChgFactory *pFactory, CSysPosiLimitChg *pObject, CWriteableSysPosiLimitChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysPosiLimitChgFactory
	///@return	��CSysPosiLimitChgFactory
	CSysPosiLimitChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysPosiLimitChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysPosiLimitChgResource *alloc(int type, CSysPosiLimitChgFactory *pFactory, CSysPosiLimitChg *pObject, CWriteableSysPosiLimitChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysPosiLimitChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysPosiLimitChg writeableObject;
	
	static CMemoryStack<CSysPosiLimitChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgResource��һ��˵����CSysClientPosiLimitChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysClientPosiLimitChgResource(void);
	virtual ~CSysClientPosiLimitChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysClientPosiLimitChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysClientPosiLimitChgFactory *pFactory, CSysClientPosiLimitChg *pObject, CWriteableSysClientPosiLimitChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysClientPosiLimitChgFactory
	///@return	��CSysClientPosiLimitChgFactory
	CSysClientPosiLimitChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysClientPosiLimitChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysClientPosiLimitChgResource *alloc(int type, CSysClientPosiLimitChgFactory *pFactory, CSysClientPosiLimitChg *pObject, CWriteableSysClientPosiLimitChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysClientPosiLimitChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysClientPosiLimitChg writeableObject;
	
	static CMemoryStack<CSysClientPosiLimitChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgResource��һ��˵����CSysSpecPosiLimitChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysSpecPosiLimitChgResource(void);
	virtual ~CSysSpecPosiLimitChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysSpecPosiLimitChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysSpecPosiLimitChgFactory *pFactory, CSysSpecPosiLimitChg *pObject, CWriteableSysSpecPosiLimitChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysSpecPosiLimitChgFactory
	///@return	��CSysSpecPosiLimitChgFactory
	CSysSpecPosiLimitChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysSpecPosiLimitChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysSpecPosiLimitChgResource *alloc(int type, CSysSpecPosiLimitChgFactory *pFactory, CSysSpecPosiLimitChg *pObject, CWriteableSysSpecPosiLimitChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysSpecPosiLimitChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysSpecPosiLimitChg writeableObject;
	
	static CMemoryStack<CSysSpecPosiLimitChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgResource��һ��˵����CSysHedgeDetailChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysHedgeDetailChgResource(void);
	virtual ~CSysHedgeDetailChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysHedgeDetailChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysHedgeDetailChgFactory *pFactory, CSysHedgeDetailChg *pObject, CWriteableSysHedgeDetailChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysHedgeDetailChgFactory
	///@return	��CSysHedgeDetailChgFactory
	CSysHedgeDetailChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysHedgeDetailChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysHedgeDetailChgResource *alloc(int type, CSysHedgeDetailChgFactory *pFactory, CSysHedgeDetailChg *pObject, CWriteableSysHedgeDetailChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysHedgeDetailChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysHedgeDetailChg writeableObject;
	
	static CMemoryStack<CSysHedgeDetailChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgResource��һ��˵����CSysParticipantChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysParticipantChgResource(void);
	virtual ~CSysParticipantChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysParticipantChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysParticipantChgFactory *pFactory, CSysParticipantChg *pObject, CWriteableSysParticipantChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysParticipantChgFactory
	///@return	��CSysParticipantChgFactory
	CSysParticipantChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysParticipantChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysParticipantChgResource *alloc(int type, CSysParticipantChgFactory *pFactory, CSysParticipantChg *pObject, CWriteableSysParticipantChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysParticipantChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysParticipantChg writeableObject;
	
	static CMemoryStack<CSysParticipantChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgResource��һ��˵����CSysMarginRateChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMarginRateChgResource(void);
	virtual ~CSysMarginRateChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMarginRateChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMarginRateChgFactory *pFactory, CSysMarginRateChg *pObject, CWriteableSysMarginRateChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMarginRateChgFactory
	///@return	��CSysMarginRateChgFactory
	CSysMarginRateChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMarginRateChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMarginRateChgResource *alloc(int type, CSysMarginRateChgFactory *pFactory, CSysMarginRateChg *pObject, CWriteableSysMarginRateChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMarginRateChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMarginRateChg writeableObject;
	
	static CMemoryStack<CSysMarginRateChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgResource��һ��˵����CSysUserIpChgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgResource : public CDatabaseResource
{
public:
	///���췽��
	CSysUserIpChgResource(void);
	virtual ~CSysUserIpChgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysUserIpChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysUserIpChgFactory *pFactory, CSysUserIpChg *pObject, CWriteableSysUserIpChg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysUserIpChgFactory
	///@return	��CSysUserIpChgFactory
	CSysUserIpChgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysUserIpChgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysUserIpChgResource *alloc(int type, CSysUserIpChgFactory *pFactory, CSysUserIpChg *pObject, CWriteableSysUserIpChg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysUserIpChgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysUserIpChg writeableObject;
	
	static CMemoryStack<CSysUserIpChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeResource��һ��˵����CSysPartTradeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysPartTradeResource(void);
	virtual ~CSysPartTradeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysPartTradeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysPartTradeFactory *pFactory, CSysPartTrade *pObject, CWriteableSysPartTrade *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysPartTradeFactory
	///@return	��CSysPartTradeFactory
	CSysPartTradeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysPartTradeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysPartTradeResource *alloc(int type, CSysPartTradeFactory *pFactory, CSysPartTrade *pObject, CWriteableSysPartTrade *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysPartTradeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysPartTrade writeableObject;
	
	static CMemoryStack<CSysPartTradeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrResource��һ��˵����CSysMdbObjectAttrFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbObjectAttrResource(void);
	virtual ~CSysMdbObjectAttrResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbObjectAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbObjectAttrFactory *pFactory, CSysMdbObjectAttr *pObject, CWriteableSysMdbObjectAttr *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbObjectAttrFactory
	///@return	��CSysMdbObjectAttrFactory
	CSysMdbObjectAttrFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbObjectAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbObjectAttrResource *alloc(int type, CSysMdbObjectAttrFactory *pFactory, CSysMdbObjectAttr *pObject, CWriteableSysMdbObjectAttr *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbObjectAttrFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbObjectAttr writeableObject;
	
	static CMemoryStack<CSysMdbObjectAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoResource��һ��˵����CSysMdbSyslogInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbSyslogInfoResource(void);
	virtual ~CSysMdbSyslogInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbSyslogInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbSyslogInfoFactory *pFactory, CSysMdbSyslogInfo *pObject, CWriteableSysMdbSyslogInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbSyslogInfoFactory
	///@return	��CSysMdbSyslogInfoFactory
	CSysMdbSyslogInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbSyslogInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbSyslogInfoResource *alloc(int type, CSysMdbSyslogInfoFactory *pFactory, CSysMdbSyslogInfo *pObject, CWriteableSysMdbSyslogInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbSyslogInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbSyslogInfo writeableObject;
	
	static CMemoryStack<CSysMdbSyslogInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoResource��һ��˵����CSysUserInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysUserInfoResource(void);
	virtual ~CSysUserInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysUserInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysUserInfoFactory *pFactory, CSysUserInfo *pObject, CWriteableSysUserInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysUserInfoFactory
	///@return	��CSysUserInfoFactory
	CSysUserInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysUserInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysUserInfoResource *alloc(int type, CSysUserInfoFactory *pFactory, CSysUserInfo *pObject, CWriteableSysUserInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysUserInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysUserInfo writeableObject;
	
	static CMemoryStack<CSysUserInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoResource��һ��˵����CSysOnlineUserInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysOnlineUserInfoResource(void);
	virtual ~CSysOnlineUserInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysOnlineUserInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysOnlineUserInfoFactory *pFactory, CSysOnlineUserInfo *pObject, CWriteableSysOnlineUserInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysOnlineUserInfoFactory
	///@return	��CSysOnlineUserInfoFactory
	CSysOnlineUserInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysOnlineUserInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysOnlineUserInfoResource *alloc(int type, CSysOnlineUserInfoFactory *pFactory, CSysOnlineUserInfo *pObject, CWriteableSysOnlineUserInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysOnlineUserInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysOnlineUserInfo writeableObject;
	
	static CMemoryStack<CSysOnlineUserInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventResource��һ��˵����CSysWarningEventFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventResource : public CDatabaseResource
{
public:
	///���췽��
	CSysWarningEventResource(void);
	virtual ~CSysWarningEventResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysWarningEventFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysWarningEventFactory *pFactory, CSysWarningEvent *pObject, CWriteableSysWarningEvent *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysWarningEventFactory
	///@return	��CSysWarningEventFactory
	CSysWarningEventFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysWarningEventFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysWarningEventResource *alloc(int type, CSysWarningEventFactory *pFactory, CSysWarningEvent *pObject, CWriteableSysWarningEvent *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysWarningEventFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysWarningEvent writeableObject;
	
	static CMemoryStack<CSysWarningEventResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryResource��һ��˵����CSysWarningQueryFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryResource : public CDatabaseResource
{
public:
	///���췽��
	CSysWarningQueryResource(void);
	virtual ~CSysWarningQueryResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysWarningQueryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysWarningQueryFactory *pFactory, CSysWarningQuery *pObject, CWriteableSysWarningQuery *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysWarningQueryFactory
	///@return	��CSysWarningQueryFactory
	CSysWarningQueryFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysWarningQueryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysWarningQueryResource *alloc(int type, CSysWarningQueryFactory *pFactory, CSysWarningQuery *pObject, CWriteableSysWarningQuery *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysWarningQueryFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysWarningQuery writeableObject;
	
	static CMemoryStack<CSysWarningQueryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventResource��һ��˵����CSyslogEventFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventResource : public CDatabaseResource
{
public:
	///���췽��
	CSyslogEventResource(void);
	virtual ~CSyslogEventResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSyslogEventFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSyslogEventFactory *pFactory, CSyslogEvent *pObject, CWriteableSyslogEvent *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSyslogEventFactory
	///@return	��CSyslogEventFactory
	CSyslogEventFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSyslogEventFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSyslogEventResource *alloc(int type, CSyslogEventFactory *pFactory, CSyslogEvent *pObject, CWriteableSyslogEvent *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSyslogEventFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSyslogEvent writeableObject;
	
	static CMemoryStack<CSyslogEventResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripResource��һ��˵����CSysEventDescripFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripResource : public CDatabaseResource
{
public:
	///���췽��
	CSysEventDescripResource(void);
	virtual ~CSysEventDescripResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysEventDescripFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysEventDescripFactory *pFactory, CSysEventDescrip *pObject, CWriteableSysEventDescrip *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysEventDescripFactory
	///@return	��CSysEventDescripFactory
	CSysEventDescripFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysEventDescripFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysEventDescripResource *alloc(int type, CSysEventDescripFactory *pFactory, CSysEventDescrip *pObject, CWriteableSysEventDescrip *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysEventDescripFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysEventDescrip writeableObject;
	
	static CMemoryStack<CSysEventDescripResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonResource��һ��˵����CRspQryHostEnvCommonFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonResource : public CDatabaseResource
{
public:
	///���췽��
	CRspQryHostEnvCommonResource(void);
	virtual ~CRspQryHostEnvCommonResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvCommonFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRspQryHostEnvCommonFactory *pFactory, CRspQryHostEnvCommon *pObject, CWriteableRspQryHostEnvCommon *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CRspQryHostEnvCommonFactory
	///@return	��CRspQryHostEnvCommonFactory
	CRspQryHostEnvCommonFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvCommonFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRspQryHostEnvCommonResource *alloc(int type, CRspQryHostEnvCommonFactory *pFactory, CRspQryHostEnvCommon *pObject, CWriteableRspQryHostEnvCommon *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRspQryHostEnvCommonFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRspQryHostEnvCommon writeableObject;
	
	static CMemoryStack<CRspQryHostEnvCommonResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanResource��һ��˵����CRspQryHostEnvLanFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanResource : public CDatabaseResource
{
public:
	///���췽��
	CRspQryHostEnvLanResource(void);
	virtual ~CRspQryHostEnvLanResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvLanFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRspQryHostEnvLanFactory *pFactory, CRspQryHostEnvLan *pObject, CWriteableRspQryHostEnvLan *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CRspQryHostEnvLanFactory
	///@return	��CRspQryHostEnvLanFactory
	CRspQryHostEnvLanFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvLanFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRspQryHostEnvLanResource *alloc(int type, CRspQryHostEnvLanFactory *pFactory, CRspQryHostEnvLan *pObject, CWriteableRspQryHostEnvLan *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRspQryHostEnvLanFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRspQryHostEnvLan writeableObject;
	
	static CMemoryStack<CRspQryHostEnvLanResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageResource��һ��˵����CRspQryHostEnvStorageFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageResource : public CDatabaseResource
{
public:
	///���췽��
	CRspQryHostEnvStorageResource(void);
	virtual ~CRspQryHostEnvStorageResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvStorageFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRspQryHostEnvStorageFactory *pFactory, CRspQryHostEnvStorage *pObject, CWriteableRspQryHostEnvStorage *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CRspQryHostEnvStorageFactory
	///@return	��CRspQryHostEnvStorageFactory
	CRspQryHostEnvStorageFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvStorageFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRspQryHostEnvStorageResource *alloc(int type, CRspQryHostEnvStorageFactory *pFactory, CRspQryHostEnvStorage *pObject, CWriteableRspQryHostEnvStorage *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRspQryHostEnvStorageFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRspQryHostEnvStorage writeableObject;
	
	static CMemoryStack<CRspQryHostEnvStorageResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOResource��һ��˵����CRspQryHostEnvIOFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOResource : public CDatabaseResource
{
public:
	///���췽��
	CRspQryHostEnvIOResource(void);
	virtual ~CRspQryHostEnvIOResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvIOFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRspQryHostEnvIOFactory *pFactory, CRspQryHostEnvIO *pObject, CWriteableRspQryHostEnvIO *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CRspQryHostEnvIOFactory
	///@return	��CRspQryHostEnvIOFactory
	CRspQryHostEnvIOFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvIOFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRspQryHostEnvIOResource *alloc(int type, CRspQryHostEnvIOFactory *pFactory, CRspQryHostEnvIO *pObject, CWriteableRspQryHostEnvIO *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRspQryHostEnvIOFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRspQryHostEnvIO writeableObject;
	
	static CMemoryStack<CRspQryHostEnvIOResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSResource��һ��˵����CRspQryHostEnvFSFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSResource : public CDatabaseResource
{
public:
	///���췽��
	CRspQryHostEnvFSResource(void);
	virtual ~CRspQryHostEnvFSResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvFSFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRspQryHostEnvFSFactory *pFactory, CRspQryHostEnvFS *pObject, CWriteableRspQryHostEnvFS *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CRspQryHostEnvFSFactory
	///@return	��CRspQryHostEnvFSFactory
	CRspQryHostEnvFSFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvFSFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRspQryHostEnvFSResource *alloc(int type, CRspQryHostEnvFSFactory *pFactory, CRspQryHostEnvFS *pObject, CWriteableRspQryHostEnvFS *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRspQryHostEnvFSFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRspQryHostEnvFS writeableObject;
	
	static CMemoryStack<CRspQryHostEnvFSResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapResource��һ��˵����CRspQryHostEnvSwapFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapResource : public CDatabaseResource
{
public:
	///���췽��
	CRspQryHostEnvSwapResource(void);
	virtual ~CRspQryHostEnvSwapResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvSwapFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRspQryHostEnvSwapFactory *pFactory, CRspQryHostEnvSwap *pObject, CWriteableRspQryHostEnvSwap *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CRspQryHostEnvSwapFactory
	///@return	��CRspQryHostEnvSwapFactory
	CRspQryHostEnvSwapFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvSwapFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRspQryHostEnvSwapResource *alloc(int type, CRspQryHostEnvSwapFactory *pFactory, CRspQryHostEnvSwap *pObject, CWriteableRspQryHostEnvSwap *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRspQryHostEnvSwapFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRspQryHostEnvSwap writeableObject;
	
	static CMemoryStack<CRspQryHostEnvSwapResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgResource��һ��˵����CRspQryHostEnvLanCfgFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgResource : public CDatabaseResource
{
public:
	///���췽��
	CRspQryHostEnvLanCfgResource(void);
	virtual ~CRspQryHostEnvLanCfgResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvLanCfgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CRspQryHostEnvLanCfgFactory *pFactory, CRspQryHostEnvLanCfg *pObject, CWriteableRspQryHostEnvLanCfg *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CRspQryHostEnvLanCfgFactory
	///@return	��CRspQryHostEnvLanCfgFactory
	CRspQryHostEnvLanCfgFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CRspQryHostEnvLanCfgFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CRspQryHostEnvLanCfgResource *alloc(int type, CRspQryHostEnvLanCfgFactory *pFactory, CRspQryHostEnvLanCfg *pObject, CWriteableRspQryHostEnvLanCfg *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CRspQryHostEnvLanCfgFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableRspQryHostEnvLanCfg writeableObject;
	
	static CMemoryStack<CRspQryHostEnvLanCfgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoResource��һ��˵����CSysMdbTopCpuInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbTopCpuInfoResource(void);
	virtual ~CSysMdbTopCpuInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbTopCpuInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbTopCpuInfoFactory *pFactory, CSysMdbTopCpuInfo *pObject, CWriteableSysMdbTopCpuInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbTopCpuInfoFactory
	///@return	��CSysMdbTopCpuInfoFactory
	CSysMdbTopCpuInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbTopCpuInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbTopCpuInfoResource *alloc(int type, CSysMdbTopCpuInfoFactory *pFactory, CSysMdbTopCpuInfo *pObject, CWriteableSysMdbTopCpuInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbTopCpuInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbTopCpuInfo writeableObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoResource��һ��˵����CSysMdbTopMemInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbTopMemInfoResource(void);
	virtual ~CSysMdbTopMemInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbTopMemInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbTopMemInfoFactory *pFactory, CSysMdbTopMemInfo *pObject, CWriteableSysMdbTopMemInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbTopMemInfoFactory
	///@return	��CSysMdbTopMemInfoFactory
	CSysMdbTopMemInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbTopMemInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbTopMemInfoResource *alloc(int type, CSysMdbTopMemInfoFactory *pFactory, CSysMdbTopMemInfo *pObject, CWriteableSysMdbTopMemInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbTopMemInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbTopMemInfo writeableObject;
	
	static CMemoryStack<CSysMdbTopMemInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoResource��һ��˵����CSysMdbTopProcessInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbTopProcessInfoResource(void);
	virtual ~CSysMdbTopProcessInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbTopProcessInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbTopProcessInfoFactory *pFactory, CSysMdbTopProcessInfo *pObject, CWriteableSysMdbTopProcessInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbTopProcessInfoFactory
	///@return	��CSysMdbTopProcessInfoFactory
	CSysMdbTopProcessInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbTopProcessInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbTopProcessInfoResource *alloc(int type, CSysMdbTopProcessInfoFactory *pFactory, CSysMdbTopProcessInfo *pObject, CWriteableSysMdbTopProcessInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbTopProcessInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbTopProcessInfo writeableObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoResource��һ��˵����CSysMdbFileSystemInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbFileSystemInfoResource(void);
	virtual ~CSysMdbFileSystemInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbFileSystemInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbFileSystemInfoFactory *pFactory, CSysMdbFileSystemInfo *pObject, CWriteableSysMdbFileSystemInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbFileSystemInfoFactory
	///@return	��CSysMdbFileSystemInfoFactory
	CSysMdbFileSystemInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbFileSystemInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbFileSystemInfoResource *alloc(int type, CSysMdbFileSystemInfoFactory *pFactory, CSysMdbFileSystemInfo *pObject, CWriteableSysMdbFileSystemInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbFileSystemInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbFileSystemInfo writeableObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoResource��һ��˵����CSysMdbNetworkInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbNetworkInfoResource(void);
	virtual ~CSysMdbNetworkInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbNetworkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbNetworkInfoFactory *pFactory, CSysMdbNetworkInfo *pObject, CWriteableSysMdbNetworkInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbNetworkInfoFactory
	///@return	��CSysMdbNetworkInfoFactory
	CSysMdbNetworkInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbNetworkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbNetworkInfoResource *alloc(int type, CSysMdbNetworkInfoFactory *pFactory, CSysMdbNetworkInfo *pObject, CWriteableSysMdbNetworkInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbNetworkInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbNetworkInfo writeableObject;
	
	static CMemoryStack<CSysMdbNetworkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitResource��һ��˵����CSysParticipantInitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitResource : public CDatabaseResource
{
public:
	///���췽��
	CSysParticipantInitResource(void);
	virtual ~CSysParticipantInitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysParticipantInitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysParticipantInitFactory *pFactory, CSysParticipantInit *pObject, CWriteableSysParticipantInit *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysParticipantInitFactory
	///@return	��CSysParticipantInitFactory
	CSysParticipantInitFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysParticipantInitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysParticipantInitResource *alloc(int type, CSysParticipantInitFactory *pFactory, CSysParticipantInit *pObject, CWriteableSysParticipantInit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysParticipantInitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysParticipantInit writeableObject;
	
	static CMemoryStack<CSysParticipantInitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitResource��һ��˵����CSysUserInitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitResource : public CDatabaseResource
{
public:
	///���췽��
	CSysUserInitResource(void);
	virtual ~CSysUserInitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysUserInitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysUserInitFactory *pFactory, CSysUserInit *pObject, CWriteableSysUserInit *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysUserInitFactory
	///@return	��CSysUserInitFactory
	CSysUserInitFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysUserInitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysUserInitResource *alloc(int type, CSysUserInitFactory *pFactory, CSysUserInit *pObject, CWriteableSysUserInit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysUserInitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysUserInit writeableObject;
	
	static CMemoryStack<CSysUserInitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitResource��һ��˵����CSysClientInitFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitResource : public CDatabaseResource
{
public:
	///���췽��
	CSysClientInitResource(void);
	virtual ~CSysClientInitResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysClientInitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysClientInitFactory *pFactory, CSysClientInit *pObject, CWriteableSysClientInit *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysClientInitFactory
	///@return	��CSysClientInitFactory
	CSysClientInitFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysClientInitFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysClientInitResource *alloc(int type, CSysClientInitFactory *pFactory, CSysClientInit *pObject, CWriteableSysClientInit *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysClientInitFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysClientInit writeableObject;
	
	static CMemoryStack<CSysClientInitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoResource��һ��˵����CSysTradeUserLoginInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysTradeUserLoginInfoResource(void);
	virtual ~CSysTradeUserLoginInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysTradeUserLoginInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysTradeUserLoginInfoFactory *pFactory, CSysTradeUserLoginInfo *pObject, CWriteableSysTradeUserLoginInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysTradeUserLoginInfoFactory
	///@return	��CSysTradeUserLoginInfoFactory
	CSysTradeUserLoginInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysTradeUserLoginInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysTradeUserLoginInfoResource *alloc(int type, CSysTradeUserLoginInfoFactory *pFactory, CSysTradeUserLoginInfo *pObject, CWriteableSysTradeUserLoginInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysTradeUserLoginInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysTradeUserLoginInfo writeableObject;
	
	static CMemoryStack<CSysTradeUserLoginInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoResource��һ��˵����CSysMdbWebAppInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbWebAppInfoResource(void);
	virtual ~CSysMdbWebAppInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbWebAppInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbWebAppInfoFactory *pFactory, CSysMdbWebAppInfo *pObject, CWriteableSysMdbWebAppInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbWebAppInfoFactory
	///@return	��CSysMdbWebAppInfoFactory
	CSysMdbWebAppInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbWebAppInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbWebAppInfoResource *alloc(int type, CSysMdbWebAppInfoFactory *pFactory, CSysMdbWebAppInfo *pObject, CWriteableSysMdbWebAppInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbWebAppInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbWebAppInfo writeableObject;
	
	static CMemoryStack<CSysMdbWebAppInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoResource��һ��˵����CSysMdbMemPoolInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbMemPoolInfoResource(void);
	virtual ~CSysMdbMemPoolInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbMemPoolInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbMemPoolInfoFactory *pFactory, CSysMdbMemPoolInfo *pObject, CWriteableSysMdbMemPoolInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbMemPoolInfoFactory
	///@return	��CSysMdbMemPoolInfoFactory
	CSysMdbMemPoolInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbMemPoolInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbMemPoolInfoResource *alloc(int type, CSysMdbMemPoolInfoFactory *pFactory, CSysMdbMemPoolInfo *pObject, CWriteableSysMdbMemPoolInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbMemPoolInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbMemPoolInfo writeableObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoResource��һ��˵����CSysMdbConnectorInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbConnectorInfoResource(void);
	virtual ~CSysMdbConnectorInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbConnectorInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbConnectorInfoFactory *pFactory, CSysMdbConnectorInfo *pObject, CWriteableSysMdbConnectorInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbConnectorInfoFactory
	///@return	��CSysMdbConnectorInfoFactory
	CSysMdbConnectorInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbConnectorInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbConnectorInfoResource *alloc(int type, CSysMdbConnectorInfoFactory *pFactory, CSysMdbConnectorInfo *pObject, CWriteableSysMdbConnectorInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbConnectorInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbConnectorInfo writeableObject;
	
	static CMemoryStack<CSysMdbConnectorInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryResource��һ��˵����CSysMdbDBQueryFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbDBQueryResource(void);
	virtual ~CSysMdbDBQueryResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbDBQueryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbDBQueryFactory *pFactory, CSysMdbDBQuery *pObject, CWriteableSysMdbDBQuery *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbDBQueryFactory
	///@return	��CSysMdbDBQueryFactory
	CSysMdbDBQueryFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbDBQueryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbDBQueryResource *alloc(int type, CSysMdbDBQueryFactory *pFactory, CSysMdbDBQuery *pObject, CWriteableSysMdbDBQuery *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbDBQueryFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbDBQuery writeableObject;
	
	static CMemoryStack<CSysMdbDBQueryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaResource��һ��˵����CSysNetAreaFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetAreaResource(void);
	virtual ~CSysNetAreaResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetAreaFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetAreaFactory *pFactory, CSysNetArea *pObject, CWriteableSysNetArea *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetAreaFactory
	///@return	��CSysNetAreaFactory
	CSysNetAreaFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetAreaFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetAreaResource *alloc(int type, CSysNetAreaFactory *pFactory, CSysNetArea *pObject, CWriteableSysNetArea *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetAreaFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetArea writeableObject;
	
	static CMemoryStack<CSysNetAreaResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaResource��һ��˵����CSysNetSubAreaFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetSubAreaResource(void);
	virtual ~CSysNetSubAreaResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetSubAreaFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetSubAreaFactory *pFactory, CSysNetSubArea *pObject, CWriteableSysNetSubArea *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetSubAreaFactory
	///@return	��CSysNetSubAreaFactory
	CSysNetSubAreaFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetSubAreaFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetSubAreaResource *alloc(int type, CSysNetSubAreaFactory *pFactory, CSysNetSubArea *pObject, CWriteableSysNetSubArea *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetSubAreaFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetSubArea writeableObject;
	
	static CMemoryStack<CSysNetSubAreaResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPResource��һ��˵����CSysNetSubAreaIPFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetSubAreaIPResource(void);
	virtual ~CSysNetSubAreaIPResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetSubAreaIPFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetSubAreaIPFactory *pFactory, CSysNetSubAreaIP *pObject, CWriteableSysNetSubAreaIP *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetSubAreaIPFactory
	///@return	��CSysNetSubAreaIPFactory
	CSysNetSubAreaIPFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetSubAreaIPFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetSubAreaIPResource *alloc(int type, CSysNetSubAreaIPFactory *pFactory, CSysNetSubAreaIP *pObject, CWriteableSysNetSubAreaIP *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetSubAreaIPFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetSubAreaIP writeableObject;
	
	static CMemoryStack<CSysNetSubAreaIPResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaResource��һ��˵����CSysNetFuncAreaFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetFuncAreaResource(void);
	virtual ~CSysNetFuncAreaResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetFuncAreaFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetFuncAreaFactory *pFactory, CSysNetFuncArea *pObject, CWriteableSysNetFuncArea *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetFuncAreaFactory
	///@return	��CSysNetFuncAreaFactory
	CSysNetFuncAreaFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetFuncAreaFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetFuncAreaResource *alloc(int type, CSysNetFuncAreaFactory *pFactory, CSysNetFuncArea *pObject, CWriteableSysNetFuncArea *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetFuncAreaFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetFuncArea writeableObject;
	
	static CMemoryStack<CSysNetFuncAreaResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceResource��һ��˵����CSysNetDeviceFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetDeviceResource(void);
	virtual ~CSysNetDeviceResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetDeviceFactory *pFactory, CSysNetDevice *pObject, CWriteableSysNetDevice *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetDeviceFactory
	///@return	��CSysNetDeviceFactory
	CSysNetDeviceFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetDeviceResource *alloc(int type, CSysNetDeviceFactory *pFactory, CSysNetDevice *pObject, CWriteableSysNetDevice *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetDeviceFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetDevice writeableObject;
	
	static CMemoryStack<CSysNetDeviceResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedResource��һ��˵����CSysNetDeviceLinkedFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetDeviceLinkedResource(void);
	virtual ~CSysNetDeviceLinkedResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceLinkedFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetDeviceLinkedFactory *pFactory, CSysNetDeviceLinked *pObject, CWriteableSysNetDeviceLinked *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetDeviceLinkedFactory
	///@return	��CSysNetDeviceLinkedFactory
	CSysNetDeviceLinkedFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceLinkedFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetDeviceLinkedResource *alloc(int type, CSysNetDeviceLinkedFactory *pFactory, CSysNetDeviceLinked *pObject, CWriteableSysNetDeviceLinked *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetDeviceLinkedFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetDeviceLinked writeableObject;
	
	static CMemoryStack<CSysNetDeviceLinkedResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDResource��һ��˵����CSysNetOIDFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetOIDResource(void);
	virtual ~CSysNetOIDResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetOIDFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetOIDFactory *pFactory, CSysNetOID *pObject, CWriteableSysNetOID *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetOIDFactory
	///@return	��CSysNetOIDFactory
	CSysNetOIDFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetOIDFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetOIDResource *alloc(int type, CSysNetOIDFactory *pFactory, CSysNetOID *pObject, CWriteableSysNetOID *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetOIDFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetOID writeableObject;
	
	static CMemoryStack<CSysNetOIDResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeResource��һ��˵����CSysNetDeviceTypeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetDeviceTypeResource(void);
	virtual ~CSysNetDeviceTypeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetDeviceTypeFactory *pFactory, CSysNetDeviceType *pObject, CWriteableSysNetDeviceType *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetDeviceTypeFactory
	///@return	��CSysNetDeviceTypeFactory
	CSysNetDeviceTypeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetDeviceTypeResource *alloc(int type, CSysNetDeviceTypeFactory *pFactory, CSysNetDeviceType *pObject, CWriteableSysNetDeviceType *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetDeviceTypeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetDeviceType writeableObject;
	
	static CMemoryStack<CSysNetDeviceTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyResource��һ��˵����CSysNetTimePolicyFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetTimePolicyResource(void);
	virtual ~CSysNetTimePolicyResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetTimePolicyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetTimePolicyFactory *pFactory, CSysNetTimePolicy *pObject, CWriteableSysNetTimePolicy *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetTimePolicyFactory
	///@return	��CSysNetTimePolicyFactory
	CSysNetTimePolicyFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetTimePolicyFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetTimePolicyResource *alloc(int type, CSysNetTimePolicyFactory *pFactory, CSysNetTimePolicy *pObject, CWriteableSysNetTimePolicy *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetTimePolicyFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetTimePolicy writeableObject;
	
	static CMemoryStack<CSysNetTimePolicyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskResource��һ��˵����CSysNetGatherTaskFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetGatherTaskResource(void);
	virtual ~CSysNetGatherTaskResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetGatherTaskFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetGatherTaskFactory *pFactory, CSysNetGatherTask *pObject, CWriteableSysNetGatherTask *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetGatherTaskFactory
	///@return	��CSysNetGatherTaskFactory
	CSysNetGatherTaskFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetGatherTaskFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetGatherTaskResource *alloc(int type, CSysNetGatherTaskFactory *pFactory, CSysNetGatherTask *pObject, CWriteableSysNetGatherTask *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetGatherTaskFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetGatherTask writeableObject;
	
	static CMemoryStack<CSysNetGatherTaskResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryResource��һ��˵����CSysNetDeviceCategoryFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetDeviceCategoryResource(void);
	virtual ~CSysNetDeviceCategoryResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceCategoryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetDeviceCategoryFactory *pFactory, CSysNetDeviceCategory *pObject, CWriteableSysNetDeviceCategory *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetDeviceCategoryFactory
	///@return	��CSysNetDeviceCategoryFactory
	CSysNetDeviceCategoryFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetDeviceCategoryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetDeviceCategoryResource *alloc(int type, CSysNetDeviceCategoryFactory *pFactory, CSysNetDeviceCategory *pObject, CWriteableSysNetDeviceCategory *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetDeviceCategoryFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetDeviceCategory writeableObject;
	
	static CMemoryStack<CSysNetDeviceCategoryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryResource��һ��˵����CSysNetManufactoryFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetManufactoryResource(void);
	virtual ~CSysNetManufactoryResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetManufactoryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetManufactoryFactory *pFactory, CSysNetManufactory *pObject, CWriteableSysNetManufactory *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetManufactoryFactory
	///@return	��CSysNetManufactoryFactory
	CSysNetManufactoryFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetManufactoryFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetManufactoryResource *alloc(int type, CSysNetManufactoryFactory *pFactory, CSysNetManufactory *pObject, CWriteableSysNetManufactory *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetManufactoryFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetManufactory writeableObject;
	
	static CMemoryStack<CSysNetManufactoryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityResource��һ��˵����CSysNetCommunityFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetCommunityResource(void);
	virtual ~CSysNetCommunityResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetCommunityFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetCommunityFactory *pFactory, CSysNetCommunity *pObject, CWriteableSysNetCommunity *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetCommunityFactory
	///@return	��CSysNetCommunityFactory
	CSysNetCommunityFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetCommunityFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetCommunityResource *alloc(int type, CSysNetCommunityFactory *pFactory, CSysNetCommunity *pObject, CWriteableSysNetCommunity *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetCommunityFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetCommunity writeableObject;
	
	static CMemoryStack<CSysNetCommunityResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeResource��һ��˵����CSysNetPortTypeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetPortTypeResource(void);
	virtual ~CSysNetPortTypeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetPortTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetPortTypeFactory *pFactory, CSysNetPortType *pObject, CWriteableSysNetPortType *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetPortTypeFactory
	///@return	��CSysNetPortTypeFactory
	CSysNetPortTypeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetPortTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetPortTypeResource *alloc(int type, CSysNetPortTypeFactory *pFactory, CSysNetPortType *pObject, CWriteableSysNetPortType *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetPortTypeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetPortType writeableObject;
	
	static CMemoryStack<CSysNetPortTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceResource��һ��˵����CSysNetInterfaceFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetInterfaceResource(void);
	virtual ~CSysNetInterfaceResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetInterfaceFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetInterfaceFactory *pFactory, CSysNetInterface *pObject, CWriteableSysNetInterface *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetInterfaceFactory
	///@return	��CSysNetInterfaceFactory
	CSysNetInterfaceFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetInterfaceFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetInterfaceResource *alloc(int type, CSysNetInterfaceFactory *pFactory, CSysNetInterface *pObject, CWriteableSysNetInterface *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetInterfaceFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetInterface writeableObject;
	
	static CMemoryStack<CSysNetInterfaceResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDResource��һ��˵����CSysNetGeneralOIDFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetGeneralOIDResource(void);
	virtual ~CSysNetGeneralOIDResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetGeneralOIDFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetGeneralOIDFactory *pFactory, CSysNetGeneralOID *pObject, CWriteableSysNetGeneralOID *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetGeneralOIDFactory
	///@return	��CSysNetGeneralOIDFactory
	CSysNetGeneralOIDFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetGeneralOIDFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetGeneralOIDResource *alloc(int type, CSysNetGeneralOIDFactory *pFactory, CSysNetGeneralOID *pObject, CWriteableSysNetGeneralOID *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetGeneralOIDFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetGeneralOID writeableObject;
	
	static CMemoryStack<CSysNetGeneralOIDResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeResource��һ��˵����CSysNetMonitorTypeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorTypeResource(void);
	virtual ~CSysNetMonitorTypeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorTypeFactory *pFactory, CSysNetMonitorType *pObject, CWriteableSysNetMonitorType *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorTypeFactory
	///@return	��CSysNetMonitorTypeFactory
	CSysNetMonitorTypeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorTypeResource *alloc(int type, CSysNetMonitorTypeFactory *pFactory, CSysNetMonitorType *pObject, CWriteableSysNetMonitorType *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorTypeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorType writeableObject;
	
	static CMemoryStack<CSysNetMonitorTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeResource��һ��˵����CSysNetMonitorAttrScopeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorAttrScopeResource(void);
	virtual ~CSysNetMonitorAttrScopeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorAttrScopeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorAttrScopeFactory *pFactory, CSysNetMonitorAttrScope *pObject, CWriteableSysNetMonitorAttrScope *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorAttrScopeFactory
	///@return	��CSysNetMonitorAttrScopeFactory
	CSysNetMonitorAttrScopeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorAttrScopeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorAttrScopeResource *alloc(int type, CSysNetMonitorAttrScopeFactory *pFactory, CSysNetMonitorAttrScope *pObject, CWriteableSysNetMonitorAttrScope *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorAttrScopeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorAttrScope writeableObject;
	
	static CMemoryStack<CSysNetMonitorAttrScopeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeResource��һ��˵����CSysNetMonitorAttrTypeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorAttrTypeResource(void);
	virtual ~CSysNetMonitorAttrTypeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorAttrTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorAttrTypeFactory *pFactory, CSysNetMonitorAttrType *pObject, CWriteableSysNetMonitorAttrType *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorAttrTypeFactory
	///@return	��CSysNetMonitorAttrTypeFactory
	CSysNetMonitorAttrTypeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorAttrTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorAttrTypeResource *alloc(int type, CSysNetMonitorAttrTypeFactory *pFactory, CSysNetMonitorAttrType *pObject, CWriteableSysNetMonitorAttrType *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorAttrTypeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorAttrType writeableObject;
	
	static CMemoryStack<CSysNetMonitorAttrTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeResource��һ��˵����CSysNetMonitorCommandTypeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorCommandTypeResource(void);
	virtual ~CSysNetMonitorCommandTypeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorCommandTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorCommandTypeFactory *pFactory, CSysNetMonitorCommandType *pObject, CWriteableSysNetMonitorCommandType *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorCommandTypeFactory
	///@return	��CSysNetMonitorCommandTypeFactory
	CSysNetMonitorCommandTypeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorCommandTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorCommandTypeResource *alloc(int type, CSysNetMonitorCommandTypeFactory *pFactory, CSysNetMonitorCommandType *pObject, CWriteableSysNetMonitorCommandType *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorCommandTypeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorCommandType writeableObject;
	
	static CMemoryStack<CSysNetMonitorCommandTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupResource��һ��˵����CSysNetMonitorActionGroupFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorActionGroupResource(void);
	virtual ~CSysNetMonitorActionGroupResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorActionGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorActionGroupFactory *pFactory, CSysNetMonitorActionGroup *pObject, CWriteableSysNetMonitorActionGroup *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorActionGroupFactory
	///@return	��CSysNetMonitorActionGroupFactory
	CSysNetMonitorActionGroupFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorActionGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorActionGroupResource *alloc(int type, CSysNetMonitorActionGroupFactory *pFactory, CSysNetMonitorActionGroup *pObject, CWriteableSysNetMonitorActionGroup *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorActionGroupFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorActionGroup writeableObject;
	
	static CMemoryStack<CSysNetMonitorActionGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupResource��һ��˵����CSysNetMonitorDeviceGroupFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorDeviceGroupResource(void);
	virtual ~CSysNetMonitorDeviceGroupResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorDeviceGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorDeviceGroupFactory *pFactory, CSysNetMonitorDeviceGroup *pObject, CWriteableSysNetMonitorDeviceGroup *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorDeviceGroupFactory
	///@return	��CSysNetMonitorDeviceGroupFactory
	CSysNetMonitorDeviceGroupFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorDeviceGroupFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorDeviceGroupResource *alloc(int type, CSysNetMonitorDeviceGroupFactory *pFactory, CSysNetMonitorDeviceGroup *pObject, CWriteableSysNetMonitorDeviceGroup *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorDeviceGroupFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorDeviceGroup writeableObject;
	
	static CMemoryStack<CSysNetMonitorDeviceGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoResource��һ��˵����CSysNetMonitorTaskInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorTaskInfoResource(void);
	virtual ~CSysNetMonitorTaskInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorTaskInfoFactory *pFactory, CSysNetMonitorTaskInfo *pObject, CWriteableSysNetMonitorTaskInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorTaskInfoFactory
	///@return	��CSysNetMonitorTaskInfoFactory
	CSysNetMonitorTaskInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorTaskInfoResource *alloc(int type, CSysNetMonitorTaskInfoFactory *pFactory, CSysNetMonitorTaskInfo *pObject, CWriteableSysNetMonitorTaskInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorTaskInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorTaskInfo writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetResource��һ��˵����CSysNetMonitorTaskObjectSetFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorTaskObjectSetResource(void);
	virtual ~CSysNetMonitorTaskObjectSetResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskObjectSetFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorTaskObjectSetFactory *pFactory, CSysNetMonitorTaskObjectSet *pObject, CWriteableSysNetMonitorTaskObjectSet *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorTaskObjectSetFactory
	///@return	��CSysNetMonitorTaskObjectSetFactory
	CSysNetMonitorTaskObjectSetFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskObjectSetFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorTaskObjectSetResource *alloc(int type, CSysNetMonitorTaskObjectSetFactory *pFactory, CSysNetMonitorTaskObjectSet *pObject, CWriteableSysNetMonitorTaskObjectSet *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorTaskObjectSetFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorTaskObjectSet writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskObjectSetResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultResource��һ��˵����CSysNetMonitorTaskResultFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorTaskResultResource(void);
	virtual ~CSysNetMonitorTaskResultResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskResultFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorTaskResultFactory *pFactory, CSysNetMonitorTaskResult *pObject, CWriteableSysNetMonitorTaskResult *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorTaskResultFactory
	///@return	��CSysNetMonitorTaskResultFactory
	CSysNetMonitorTaskResultFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskResultFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorTaskResultResource *alloc(int type, CSysNetMonitorTaskResultFactory *pFactory, CSysNetMonitorTaskResult *pObject, CWriteableSysNetMonitorTaskResult *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorTaskResultFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorTaskResult writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoResource��һ��˵����CSysNetPartyLinkInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetPartyLinkInfoResource(void);
	virtual ~CSysNetPartyLinkInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetPartyLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetPartyLinkInfoFactory *pFactory, CSysNetPartyLinkInfo *pObject, CWriteableSysNetPartyLinkInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetPartyLinkInfoFactory
	///@return	��CSysNetPartyLinkInfoFactory
	CSysNetPartyLinkInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetPartyLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetPartyLinkInfoResource *alloc(int type, CSysNetPartyLinkInfoFactory *pFactory, CSysNetPartyLinkInfo *pObject, CWriteableSysNetPartyLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetPartyLinkInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetPartyLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetPartyLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoResource��һ��˵����CSysNetDelPartyLinkInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetDelPartyLinkInfoResource(void);
	virtual ~CSysNetDelPartyLinkInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetDelPartyLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetDelPartyLinkInfoFactory *pFactory, CSysNetDelPartyLinkInfo *pObject, CWriteableSysNetDelPartyLinkInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetDelPartyLinkInfoFactory
	///@return	��CSysNetDelPartyLinkInfoFactory
	CSysNetDelPartyLinkInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetDelPartyLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetDelPartyLinkInfoResource *alloc(int type, CSysNetDelPartyLinkInfoFactory *pFactory, CSysNetDelPartyLinkInfo *pObject, CWriteableSysNetDelPartyLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetDelPartyLinkInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetDelPartyLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetDelPartyLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeResource��һ��˵����CSysNetPartyLinkAddrChangeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetPartyLinkAddrChangeResource(void);
	virtual ~CSysNetPartyLinkAddrChangeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetPartyLinkAddrChangeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetPartyLinkAddrChangeFactory *pFactory, CSysNetPartyLinkAddrChange *pObject, CWriteableSysNetPartyLinkAddrChange *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetPartyLinkAddrChangeFactory
	///@return	��CSysNetPartyLinkAddrChangeFactory
	CSysNetPartyLinkAddrChangeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetPartyLinkAddrChangeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetPartyLinkAddrChangeResource *alloc(int type, CSysNetPartyLinkAddrChangeFactory *pFactory, CSysNetPartyLinkAddrChange *pObject, CWriteableSysNetPartyLinkAddrChange *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetPartyLinkAddrChangeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetPartyLinkAddrChange writeableObject;
	
	static CMemoryStack<CSysNetPartyLinkAddrChangeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrResource��һ��˵����CSysNetMonitorActionAttrFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorActionAttrResource(void);
	virtual ~CSysNetMonitorActionAttrResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorActionAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorActionAttrFactory *pFactory, CSysNetMonitorActionAttr *pObject, CWriteableSysNetMonitorActionAttr *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorActionAttrFactory
	///@return	��CSysNetMonitorActionAttrFactory
	CSysNetMonitorActionAttrFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorActionAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorActionAttrResource *alloc(int type, CSysNetMonitorActionAttrFactory *pFactory, CSysNetMonitorActionAttr *pObject, CWriteableSysNetMonitorActionAttr *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorActionAttrFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorActionAttr writeableObject;
	
	static CMemoryStack<CSysNetMonitorActionAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleResource��һ��˵����CSysNetModuleFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetModuleResource(void);
	virtual ~CSysNetModuleResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetModuleFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetModuleFactory *pFactory, CSysNetModule *pObject, CWriteableSysNetModule *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetModuleFactory
	///@return	��CSysNetModuleFactory
	CSysNetModuleFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetModuleFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetModuleResource *alloc(int type, CSysNetModuleFactory *pFactory, CSysNetModule *pObject, CWriteableSysNetModule *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetModuleFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetModule writeableObject;
	
	static CMemoryStack<CSysNetModuleResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprResource��һ��˵����CSysNetEventExprFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetEventExprResource(void);
	virtual ~CSysNetEventExprResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetEventExprFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetEventExprFactory *pFactory, CSysNetEventExpr *pObject, CWriteableSysNetEventExpr *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetEventExprFactory
	///@return	��CSysNetEventExprFactory
	CSysNetEventExprFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetEventExprFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetEventExprResource *alloc(int type, CSysNetEventExprFactory *pFactory, CSysNetEventExpr *pObject, CWriteableSysNetEventExpr *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetEventExprFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetEventExpr writeableObject;
	
	static CMemoryStack<CSysNetEventExprResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeResource��һ��˵����CSysNetEventTypeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetEventTypeResource(void);
	virtual ~CSysNetEventTypeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetEventTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetEventTypeFactory *pFactory, CSysNetEventType *pObject, CWriteableSysNetEventType *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetEventTypeFactory
	///@return	��CSysNetEventTypeFactory
	CSysNetEventTypeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetEventTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetEventTypeResource *alloc(int type, CSysNetEventTypeFactory *pFactory, CSysNetEventType *pObject, CWriteableSysNetEventType *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetEventTypeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetEventType writeableObject;
	
	static CMemoryStack<CSysNetEventTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeResource��һ��˵����CSysNetSubEventTypeFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetSubEventTypeResource(void);
	virtual ~CSysNetSubEventTypeResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetSubEventTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetSubEventTypeFactory *pFactory, CSysNetSubEventType *pObject, CWriteableSysNetSubEventType *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetSubEventTypeFactory
	///@return	��CSysNetSubEventTypeFactory
	CSysNetSubEventTypeFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetSubEventTypeFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetSubEventTypeResource *alloc(int type, CSysNetSubEventTypeFactory *pFactory, CSysNetSubEventType *pObject, CWriteableSysNetSubEventType *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetSubEventTypeFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetSubEventType writeableObject;
	
	static CMemoryStack<CSysNetSubEventTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelResource��һ��˵����CSysNetEventLevelFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetEventLevelResource(void);
	virtual ~CSysNetEventLevelResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetEventLevelFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetEventLevelFactory *pFactory, CSysNetEventLevel *pObject, CWriteableSysNetEventLevel *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetEventLevelFactory
	///@return	��CSysNetEventLevelFactory
	CSysNetEventLevelFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetEventLevelFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetEventLevelResource *alloc(int type, CSysNetEventLevelFactory *pFactory, CSysNetEventLevel *pObject, CWriteableSysNetEventLevel *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetEventLevelFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetEventLevel writeableObject;
	
	static CMemoryStack<CSysNetEventLevelResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskResource��һ��˵����CSysNetMonitorDeviceTaskFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorDeviceTaskResource(void);
	virtual ~CSysNetMonitorDeviceTaskResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorDeviceTaskFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorDeviceTaskFactory *pFactory, CSysNetMonitorDeviceTask *pObject, CWriteableSysNetMonitorDeviceTask *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorDeviceTaskFactory
	///@return	��CSysNetMonitorDeviceTaskFactory
	CSysNetMonitorDeviceTaskFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorDeviceTaskFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorDeviceTaskResource *alloc(int type, CSysNetMonitorDeviceTaskFactory *pFactory, CSysNetMonitorDeviceTask *pObject, CWriteableSysNetMonitorDeviceTask *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorDeviceTaskFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorDeviceTask writeableObject;
	
	static CMemoryStack<CSysNetMonitorDeviceTaskResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsResource��һ��˵����CSysNetMonitorTaskInstAttrsFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMonitorTaskInstAttrsResource(void);
	virtual ~CSysNetMonitorTaskInstAttrsResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskInstAttrsFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMonitorTaskInstAttrsFactory *pFactory, CSysNetMonitorTaskInstAttrs *pObject, CWriteableSysNetMonitorTaskInstAttrs *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMonitorTaskInstAttrsFactory
	///@return	��CSysNetMonitorTaskInstAttrsFactory
	CSysNetMonitorTaskInstAttrsFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMonitorTaskInstAttrsFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMonitorTaskInstAttrsResource *alloc(int type, CSysNetMonitorTaskInstAttrsFactory *pFactory, CSysNetMonitorTaskInstAttrs *pObject, CWriteableSysNetMonitorTaskInstAttrs *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMonitorTaskInstAttrsFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMonitorTaskInstAttrs writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskInstAttrsResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineResource��һ��˵����CSysNetBaseLineFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetBaseLineResource(void);
	virtual ~CSysNetBaseLineResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetBaseLineFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetBaseLineFactory *pFactory, CSysNetBaseLine *pObject, CWriteableSysNetBaseLine *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetBaseLineFactory
	///@return	��CSysNetBaseLineFactory
	CSysNetBaseLineFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetBaseLineFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetBaseLineResource *alloc(int type, CSysNetBaseLineFactory *pFactory, CSysNetBaseLine *pObject, CWriteableSysNetBaseLine *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetBaseLineFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetBaseLine writeableObject;
	
	static CMemoryStack<CSysNetBaseLineResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskResource��һ��˵����CSysNetBaseLineTaskFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetBaseLineTaskResource(void);
	virtual ~CSysNetBaseLineTaskResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetBaseLineTaskFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetBaseLineTaskFactory *pFactory, CSysNetBaseLineTask *pObject, CWriteableSysNetBaseLineTask *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetBaseLineTaskFactory
	///@return	��CSysNetBaseLineTaskFactory
	CSysNetBaseLineTaskFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetBaseLineTaskFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetBaseLineTaskResource *alloc(int type, CSysNetBaseLineTaskFactory *pFactory, CSysNetBaseLineTask *pObject, CWriteableSysNetBaseLineTask *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetBaseLineTaskFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetBaseLineTask writeableObject;
	
	static CMemoryStack<CSysNetBaseLineTaskResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoResource��һ��˵����CSysMdbNetPartyLinkStatusInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbNetPartyLinkStatusInfoResource(void);
	virtual ~CSysMdbNetPartyLinkStatusInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbNetPartyLinkStatusInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbNetPartyLinkStatusInfoFactory *pFactory, CSysMdbNetPartyLinkStatusInfo *pObject, CWriteableSysMdbNetPartyLinkStatusInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbNetPartyLinkStatusInfoFactory
	///@return	��CSysMdbNetPartyLinkStatusInfoFactory
	CSysMdbNetPartyLinkStatusInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbNetPartyLinkStatusInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbNetPartyLinkStatusInfoResource *alloc(int type, CSysMdbNetPartyLinkStatusInfoFactory *pFactory, CSysMdbNetPartyLinkStatusInfo *pObject, CWriteableSysMdbNetPartyLinkStatusInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbNetPartyLinkStatusInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbNetPartyLinkStatusInfo writeableObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoResource��һ��˵����CSysNetMemberSDHLineInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetMemberSDHLineInfoResource(void);
	virtual ~CSysNetMemberSDHLineInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetMemberSDHLineInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetMemberSDHLineInfoFactory *pFactory, CSysNetMemberSDHLineInfo *pObject, CWriteableSysNetMemberSDHLineInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetMemberSDHLineInfoFactory
	///@return	��CSysNetMemberSDHLineInfoFactory
	CSysNetMemberSDHLineInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetMemberSDHLineInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetMemberSDHLineInfoResource *alloc(int type, CSysNetMemberSDHLineInfoFactory *pFactory, CSysNetMemberSDHLineInfo *pObject, CWriteableSysNetMemberSDHLineInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetMemberSDHLineInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetMemberSDHLineInfo writeableObject;
	
	static CMemoryStack<CSysNetMemberSDHLineInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoResource��һ��˵����CSysNetDDNLinkInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetDDNLinkInfoResource(void);
	virtual ~CSysNetDDNLinkInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetDDNLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetDDNLinkInfoFactory *pFactory, CSysNetDDNLinkInfo *pObject, CWriteableSysNetDDNLinkInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetDDNLinkInfoFactory
	///@return	��CSysNetDDNLinkInfoFactory
	CSysNetDDNLinkInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetDDNLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetDDNLinkInfoResource *alloc(int type, CSysNetDDNLinkInfoFactory *pFactory, CSysNetDDNLinkInfo *pObject, CWriteableSysNetDDNLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetDDNLinkInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetDDNLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetDDNLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoResource��һ��˵����CSysNetPseudMemberLinkInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetPseudMemberLinkInfoResource(void);
	virtual ~CSysNetPseudMemberLinkInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetPseudMemberLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetPseudMemberLinkInfoFactory *pFactory, CSysNetPseudMemberLinkInfo *pObject, CWriteableSysNetPseudMemberLinkInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetPseudMemberLinkInfoFactory
	///@return	��CSysNetPseudMemberLinkInfoFactory
	CSysNetPseudMemberLinkInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetPseudMemberLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetPseudMemberLinkInfoResource *alloc(int type, CSysNetPseudMemberLinkInfoFactory *pFactory, CSysNetPseudMemberLinkInfo *pObject, CWriteableSysNetPseudMemberLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetPseudMemberLinkInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetPseudMemberLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetPseudMemberLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoResource��һ��˵����CSysNetOuterDeviceInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetOuterDeviceInfoResource(void);
	virtual ~CSysNetOuterDeviceInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetOuterDeviceInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetOuterDeviceInfoFactory *pFactory, CSysNetOuterDeviceInfo *pObject, CWriteableSysNetOuterDeviceInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetOuterDeviceInfoFactory
	///@return	��CSysNetOuterDeviceInfoFactory
	CSysNetOuterDeviceInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetOuterDeviceInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetOuterDeviceInfoResource *alloc(int type, CSysNetOuterDeviceInfoFactory *pFactory, CSysNetOuterDeviceInfo *pObject, CWriteableSysNetOuterDeviceInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetOuterDeviceInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetOuterDeviceInfo writeableObject;
	
	static CMemoryStack<CSysNetOuterDeviceInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoResource��һ��˵����CSysLocalPingResultInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysLocalPingResultInfoResource(void);
	virtual ~CSysLocalPingResultInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysLocalPingResultInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysLocalPingResultInfoFactory *pFactory, CSysLocalPingResultInfo *pObject, CWriteableSysLocalPingResultInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysLocalPingResultInfoFactory
	///@return	��CSysLocalPingResultInfoFactory
	CSysLocalPingResultInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysLocalPingResultInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysLocalPingResultInfoResource *alloc(int type, CSysLocalPingResultInfoFactory *pFactory, CSysLocalPingResultInfo *pObject, CWriteableSysLocalPingResultInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysLocalPingResultInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysLocalPingResultInfo writeableObject;
	
	static CMemoryStack<CSysLocalPingResultInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoResource��һ��˵����CSysRomotePingResultInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysRomotePingResultInfoResource(void);
	virtual ~CSysRomotePingResultInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysRomotePingResultInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysRomotePingResultInfoFactory *pFactory, CSysRomotePingResultInfo *pObject, CWriteableSysRomotePingResultInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysRomotePingResultInfoFactory
	///@return	��CSysRomotePingResultInfoFactory
	CSysRomotePingResultInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysRomotePingResultInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysRomotePingResultInfoResource *alloc(int type, CSysRomotePingResultInfoFactory *pFactory, CSysRomotePingResultInfo *pObject, CWriteableSysRomotePingResultInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysRomotePingResultInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysRomotePingResultInfo writeableObject;
	
	static CMemoryStack<CSysRomotePingResultInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesResource��һ��˵����CSysParticTradeOrderStatesFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesResource : public CDatabaseResource
{
public:
	///���췽��
	CSysParticTradeOrderStatesResource(void);
	virtual ~CSysParticTradeOrderStatesResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysParticTradeOrderStatesFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysParticTradeOrderStatesFactory *pFactory, CSysParticTradeOrderStates *pObject, CWriteableSysParticTradeOrderStates *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysParticTradeOrderStatesFactory
	///@return	��CSysParticTradeOrderStatesFactory
	CSysParticTradeOrderStatesFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysParticTradeOrderStatesFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysParticTradeOrderStatesResource *alloc(int type, CSysParticTradeOrderStatesFactory *pFactory, CSysParticTradeOrderStates *pObject, CWriteableSysParticTradeOrderStates *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysParticTradeOrderStatesFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysParticTradeOrderStates writeableObject;
	
	static CMemoryStack<CSysParticTradeOrderStatesResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoResource��һ��˵����CSysMdbRouterInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbRouterInfoResource(void);
	virtual ~CSysMdbRouterInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbRouterInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbRouterInfoFactory *pFactory, CSysMdbRouterInfo *pObject, CWriteableSysMdbRouterInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbRouterInfoFactory
	///@return	��CSysMdbRouterInfoFactory
	CSysMdbRouterInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbRouterInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbRouterInfoResource *alloc(int type, CSysMdbRouterInfoFactory *pFactory, CSysMdbRouterInfo *pObject, CWriteableSysMdbRouterInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbRouterInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbRouterInfo writeableObject;
	
	static CMemoryStack<CSysMdbRouterInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOResource��һ��˵����CSysMdbDiskIOFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbDiskIOResource(void);
	virtual ~CSysMdbDiskIOResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbDiskIOFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbDiskIOFactory *pFactory, CSysMdbDiskIO *pObject, CWriteableSysMdbDiskIO *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbDiskIOFactory
	///@return	��CSysMdbDiskIOFactory
	CSysMdbDiskIOFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbDiskIOFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbDiskIOResource *alloc(int type, CSysMdbDiskIOFactory *pFactory, CSysMdbDiskIO *pObject, CWriteableSysMdbDiskIO *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbDiskIOFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbDiskIO writeableObject;
	
	static CMemoryStack<CSysMdbDiskIOResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoResource��һ��˵����CSysMdbStatInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbStatInfoResource(void);
	virtual ~CSysMdbStatInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbStatInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbStatInfoFactory *pFactory, CSysMdbStatInfo *pObject, CWriteableSysMdbStatInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbStatInfoFactory
	///@return	��CSysMdbStatInfoFactory
	CSysMdbStatInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbStatInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbStatInfoResource *alloc(int type, CSysMdbStatInfoFactory *pFactory, CSysMdbStatInfo *pObject, CWriteableSysMdbStatInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbStatInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbStatInfo writeableObject;
	
	static CMemoryStack<CSysMdbStatInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatResource��һ��˵����CSysMdbTradeFrontOrderRttStatFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMdbTradeFrontOrderRttStatResource(void);
	virtual ~CSysMdbTradeFrontOrderRttStatResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMdbTradeFrontOrderRttStatFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMdbTradeFrontOrderRttStatFactory *pFactory, CSysMdbTradeFrontOrderRttStat *pObject, CWriteableSysMdbTradeFrontOrderRttStat *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMdbTradeFrontOrderRttStatFactory
	///@return	��CSysMdbTradeFrontOrderRttStatFactory
	CSysMdbTradeFrontOrderRttStatFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMdbTradeFrontOrderRttStatFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMdbTradeFrontOrderRttStatResource *alloc(int type, CSysMdbTradeFrontOrderRttStatFactory *pFactory, CSysMdbTradeFrontOrderRttStat *pObject, CWriteableSysMdbTradeFrontOrderRttStat *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMdbTradeFrontOrderRttStatFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMdbTradeFrontOrderRttStat writeableObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusResource��һ��˵����CSysInstrumentStatusFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusResource : public CDatabaseResource
{
public:
	///���췽��
	CSysInstrumentStatusResource(void);
	virtual ~CSysInstrumentStatusResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysInstrumentStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysInstrumentStatusFactory *pFactory, CSysInstrumentStatus *pObject, CWriteableSysInstrumentStatus *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysInstrumentStatusFactory
	///@return	��CSysInstrumentStatusFactory
	CSysInstrumentStatusFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysInstrumentStatusFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysInstrumentStatusResource *alloc(int type, CSysInstrumentStatusFactory *pFactory, CSysInstrumentStatus *pObject, CWriteableSysInstrumentStatus *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysInstrumentStatusFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysInstrumentStatus writeableObject;
	
	static CMemoryStack<CSysInstrumentStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrResource��һ��˵����CSysCurrTradingSegmentAttrFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrResource : public CDatabaseResource
{
public:
	///���췽��
	CSysCurrTradingSegmentAttrResource(void);
	virtual ~CSysCurrTradingSegmentAttrResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysCurrTradingSegmentAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysCurrTradingSegmentAttrFactory *pFactory, CSysCurrTradingSegmentAttr *pObject, CWriteableSysCurrTradingSegmentAttr *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysCurrTradingSegmentAttrFactory
	///@return	��CSysCurrTradingSegmentAttrFactory
	CSysCurrTradingSegmentAttrFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysCurrTradingSegmentAttrFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysCurrTradingSegmentAttrResource *alloc(int type, CSysCurrTradingSegmentAttrFactory *pFactory, CSysCurrTradingSegmentAttr *pObject, CWriteableSysCurrTradingSegmentAttr *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysCurrTradingSegmentAttrFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysCurrTradingSegmentAttr writeableObject;
	
	static CMemoryStack<CSysCurrTradingSegmentAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostResource��һ��˵����CSysMemberLinkCostFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostResource : public CDatabaseResource
{
public:
	///���췽��
	CSysMemberLinkCostResource(void);
	virtual ~CSysMemberLinkCostResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysMemberLinkCostFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysMemberLinkCostFactory *pFactory, CSysMemberLinkCost *pObject, CWriteableSysMemberLinkCost *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysMemberLinkCostFactory
	///@return	��CSysMemberLinkCostFactory
	CSysMemberLinkCostFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysMemberLinkCostFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysMemberLinkCostResource *alloc(int type, CSysMemberLinkCostFactory *pFactory, CSysMemberLinkCost *pObject, CWriteableSysMemberLinkCost *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysMemberLinkCostFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysMemberLinkCost writeableObject;
	
	static CMemoryStack<CSysMemberLinkCostResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentResource��һ��˵����CSysNetPartylinkMonthlyRentFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetPartylinkMonthlyRentResource(void);
	virtual ~CSysNetPartylinkMonthlyRentResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetPartylinkMonthlyRentFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetPartylinkMonthlyRentFactory *pFactory, CSysNetPartylinkMonthlyRent *pObject, CWriteableSysNetPartylinkMonthlyRent *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetPartylinkMonthlyRentFactory
	///@return	��CSysNetPartylinkMonthlyRentFactory
	CSysNetPartylinkMonthlyRentFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetPartylinkMonthlyRentFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetPartylinkMonthlyRentResource *alloc(int type, CSysNetPartylinkMonthlyRentFactory *pFactory, CSysNetPartylinkMonthlyRent *pObject, CWriteableSysNetPartylinkMonthlyRent *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetPartylinkMonthlyRentFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetPartylinkMonthlyRent writeableObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoResource��һ��˵����CSysNetNonPartyLinkInfoFactory��ʹ����������ԭ����Դ
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoResource : public CDatabaseResource
{
public:
	///���췽��
	CSysNetNonPartyLinkInfoResource(void);
	virtual ~CSysNetNonPartyLinkInfoResource(void);

	///��ʼ��
	///@param	type	��Դ���ͣ�Ӧ����CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION
	///@param	pFactory	����Դ���ڵ�CSysNetNonPartyLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	void init(int type, CSysNetNonPartyLinkInfoFactory *pFactory, CSysNetNonPartyLinkInfo *pObject, CWriteableSysNetNonPartyLinkInfo *pWriteableObject, bool updateIndex=true)
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

	///��ȡ����Դ���ڵ�CSysNetNonPartyLinkInfoFactory
	///@return	��CSysNetNonPartyLinkInfoFactory
	CSysNetNonPartyLinkInfoFactory *getFactory(void)
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
	///@param	pFactory	����Դ���ڵ�CSysNetNonPartyLinkInfoFactory
	///@param	pObject	����Դ�ĵ�ַ
	///@param	pWriteableObject	�µĶ���ֵ����typeΪUPDATE_ACTIONʱ��Ч����Ŀǰ��ʵ����û���ô�
	///@param	updateIndex	�Ƿ��������
	///@return	����һ����ָ�����ݵ���Դ
	static CSysNetNonPartyLinkInfoResource *alloc(int type, CSysNetNonPartyLinkInfoFactory *pFactory, CSysNetNonPartyLinkInfo *pObject, CWriteableSysNetNonPartyLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///��ű���Դ���ڵĶ��󹤳�
	CSysNetNonPartyLinkInfoFactory *pFactory;
	
	///��ű���Դ�޸�ǰ��ֵ����typeΪCREATE_ACTION��DELETE_ACTIONʱ������������
	CWriteableSysNetNonPartyLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetNonPartyLinkInfoResource> resourceList;
};

#endif
