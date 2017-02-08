/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseResources.h
///@brief定义了若干内存数据资源，可以放置于事务中
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASERESOURCES_H
#define DATABASERESOURCES_H

#include "databaseData.h"
#include "MemoryStack.h"

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderResource是一个说明在CSysInvalidateOrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderResource : public CDatabaseResource
{
public:
	///构造方法
	CSysInvalidateOrderResource(void);
	virtual ~CSysInvalidateOrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysInvalidateOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysInvalidateOrderFactory
	///@return	该CSysInvalidateOrderFactory
	CSysInvalidateOrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysInvalidateOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysInvalidateOrderResource *alloc(int type, CSysInvalidateOrderFactory *pFactory, CSysInvalidateOrder *pObject, CWriteableSysInvalidateOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysInvalidateOrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysInvalidateOrder writeableObject;
	
	static CMemoryStack<CSysInvalidateOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusResource是一个说明在CSysOrderStatusFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusResource : public CDatabaseResource
{
public:
	///构造方法
	CSysOrderStatusResource(void);
	virtual ~CSysOrderStatusResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysOrderStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysOrderStatusFactory
	///@return	该CSysOrderStatusFactory
	CSysOrderStatusFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysOrderStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysOrderStatusResource *alloc(int type, CSysOrderStatusFactory *pFactory, CSysOrderStatus *pObject, CWriteableSysOrderStatus *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysOrderStatusFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysOrderStatus writeableObject;
	
	static CMemoryStack<CSysOrderStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderResource是一个说明在CSysBargainOrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderResource : public CDatabaseResource
{
public:
	///构造方法
	CSysBargainOrderResource(void);
	virtual ~CSysBargainOrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysBargainOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysBargainOrderFactory
	///@return	该CSysBargainOrderFactory
	CSysBargainOrderFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysBargainOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysBargainOrderResource *alloc(int type, CSysBargainOrderFactory *pFactory, CSysBargainOrder *pObject, CWriteableSysBargainOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysBargainOrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysBargainOrder writeableObject;
	
	static CMemoryStack<CSysBargainOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyResource是一个说明在CSysInstPropertyFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyResource : public CDatabaseResource
{
public:
	///构造方法
	CSysInstPropertyResource(void);
	virtual ~CSysInstPropertyResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysInstPropertyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysInstPropertyFactory
	///@return	该CSysInstPropertyFactory
	CSysInstPropertyFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysInstPropertyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysInstPropertyResource *alloc(int type, CSysInstPropertyFactory *pFactory, CSysInstProperty *pObject, CWriteableSysInstProperty *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysInstPropertyFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysInstProperty writeableObject;
	
	static CMemoryStack<CSysInstPropertyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateResource是一个说明在CSysMarginRateFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMarginRateResource(void);
	virtual ~CSysMarginRateResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMarginRateFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMarginRateFactory
	///@return	该CSysMarginRateFactory
	CSysMarginRateFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMarginRateFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMarginRateResource *alloc(int type, CSysMarginRateFactory *pFactory, CSysMarginRate *pObject, CWriteableSysMarginRate *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMarginRateFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMarginRate writeableObject;
	
	static CMemoryStack<CSysMarginRateResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitResource是一个说明在CSysPriceLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CSysPriceLimitResource(void);
	virtual ~CSysPriceLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPriceLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysPriceLimitFactory
	///@return	该CSysPriceLimitFactory
	CSysPriceLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPriceLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysPriceLimitResource *alloc(int type, CSysPriceLimitFactory *pFactory, CSysPriceLimit *pObject, CWriteableSysPriceLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysPriceLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysPriceLimit writeableObject;
	
	static CMemoryStack<CSysPriceLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitResource是一个说明在CSysPartPosiLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CSysPartPosiLimitResource(void);
	virtual ~CSysPartPosiLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPartPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysPartPosiLimitFactory
	///@return	该CSysPartPosiLimitFactory
	CSysPartPosiLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPartPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysPartPosiLimitResource *alloc(int type, CSysPartPosiLimitFactory *pFactory, CSysPartPosiLimit *pObject, CWriteableSysPartPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysPartPosiLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysPartPosiLimit writeableObject;
	
	static CMemoryStack<CSysPartPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitResource是一个说明在CSysClientPosiLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CSysClientPosiLimitResource(void);
	virtual ~CSysClientPosiLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysClientPosiLimitFactory
	///@return	该CSysClientPosiLimitFactory
	CSysClientPosiLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysClientPosiLimitResource *alloc(int type, CSysClientPosiLimitFactory *pFactory, CSysClientPosiLimit *pObject, CWriteableSysClientPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysClientPosiLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysClientPosiLimit writeableObject;
	
	static CMemoryStack<CSysClientPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitResource是一个说明在CSysSpecialPosiLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CSysSpecialPosiLimitResource(void);
	virtual ~CSysSpecialPosiLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysSpecialPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysSpecialPosiLimitFactory
	///@return	该CSysSpecialPosiLimitFactory
	CSysSpecialPosiLimitFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysSpecialPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysSpecialPosiLimitResource *alloc(int type, CSysSpecialPosiLimitFactory *pFactory, CSysSpecialPosiLimit *pObject, CWriteableSysSpecialPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysSpecialPosiLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysSpecialPosiLimit writeableObject;
	
	static CMemoryStack<CSysSpecialPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgResource是一个说明在CSysTransactionChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysTransactionChgResource(void);
	virtual ~CSysTransactionChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysTransactionChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysTransactionChgFactory
	///@return	该CSysTransactionChgFactory
	CSysTransactionChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysTransactionChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysTransactionChgResource *alloc(int type, CSysTransactionChgFactory *pFactory, CSysTransactionChg *pObject, CWriteableSysTransactionChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysTransactionChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysTransactionChg writeableObject;
	
	static CMemoryStack<CSysTransactionChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgResource是一个说明在CSysClientChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysClientChgResource(void);
	virtual ~CSysClientChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysClientChgFactory
	///@return	该CSysClientChgFactory
	CSysClientChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysClientChgResource *alloc(int type, CSysClientChgFactory *pFactory, CSysClientChg *pObject, CWriteableSysClientChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysClientChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysClientChg writeableObject;
	
	static CMemoryStack<CSysClientChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgResource是一个说明在CSysPartClientChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysPartClientChgResource(void);
	virtual ~CSysPartClientChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPartClientChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysPartClientChgFactory
	///@return	该CSysPartClientChgFactory
	CSysPartClientChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPartClientChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysPartClientChgResource *alloc(int type, CSysPartClientChgFactory *pFactory, CSysPartClientChg *pObject, CWriteableSysPartClientChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysPartClientChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysPartClientChg writeableObject;
	
	static CMemoryStack<CSysPartClientChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgResource是一个说明在CSysPosiLimitChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysPosiLimitChgResource(void);
	virtual ~CSysPosiLimitChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPosiLimitChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysPosiLimitChgFactory
	///@return	该CSysPosiLimitChgFactory
	CSysPosiLimitChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPosiLimitChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysPosiLimitChgResource *alloc(int type, CSysPosiLimitChgFactory *pFactory, CSysPosiLimitChg *pObject, CWriteableSysPosiLimitChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysPosiLimitChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysPosiLimitChg writeableObject;
	
	static CMemoryStack<CSysPosiLimitChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgResource是一个说明在CSysClientPosiLimitChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysClientPosiLimitChgResource(void);
	virtual ~CSysClientPosiLimitChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientPosiLimitChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysClientPosiLimitChgFactory
	///@return	该CSysClientPosiLimitChgFactory
	CSysClientPosiLimitChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientPosiLimitChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysClientPosiLimitChgResource *alloc(int type, CSysClientPosiLimitChgFactory *pFactory, CSysClientPosiLimitChg *pObject, CWriteableSysClientPosiLimitChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysClientPosiLimitChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysClientPosiLimitChg writeableObject;
	
	static CMemoryStack<CSysClientPosiLimitChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgResource是一个说明在CSysSpecPosiLimitChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysSpecPosiLimitChgResource(void);
	virtual ~CSysSpecPosiLimitChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysSpecPosiLimitChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysSpecPosiLimitChgFactory
	///@return	该CSysSpecPosiLimitChgFactory
	CSysSpecPosiLimitChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysSpecPosiLimitChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysSpecPosiLimitChgResource *alloc(int type, CSysSpecPosiLimitChgFactory *pFactory, CSysSpecPosiLimitChg *pObject, CWriteableSysSpecPosiLimitChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysSpecPosiLimitChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysSpecPosiLimitChg writeableObject;
	
	static CMemoryStack<CSysSpecPosiLimitChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgResource是一个说明在CSysHedgeDetailChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysHedgeDetailChgResource(void);
	virtual ~CSysHedgeDetailChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysHedgeDetailChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysHedgeDetailChgFactory
	///@return	该CSysHedgeDetailChgFactory
	CSysHedgeDetailChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysHedgeDetailChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysHedgeDetailChgResource *alloc(int type, CSysHedgeDetailChgFactory *pFactory, CSysHedgeDetailChg *pObject, CWriteableSysHedgeDetailChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysHedgeDetailChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysHedgeDetailChg writeableObject;
	
	static CMemoryStack<CSysHedgeDetailChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgResource是一个说明在CSysParticipantChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysParticipantChgResource(void);
	virtual ~CSysParticipantChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysParticipantChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysParticipantChgFactory
	///@return	该CSysParticipantChgFactory
	CSysParticipantChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysParticipantChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysParticipantChgResource *alloc(int type, CSysParticipantChgFactory *pFactory, CSysParticipantChg *pObject, CWriteableSysParticipantChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysParticipantChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysParticipantChg writeableObject;
	
	static CMemoryStack<CSysParticipantChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgResource是一个说明在CSysMarginRateChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMarginRateChgResource(void);
	virtual ~CSysMarginRateChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMarginRateChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMarginRateChgFactory
	///@return	该CSysMarginRateChgFactory
	CSysMarginRateChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMarginRateChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMarginRateChgResource *alloc(int type, CSysMarginRateChgFactory *pFactory, CSysMarginRateChg *pObject, CWriteableSysMarginRateChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMarginRateChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMarginRateChg writeableObject;
	
	static CMemoryStack<CSysMarginRateChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgResource是一个说明在CSysUserIpChgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgResource : public CDatabaseResource
{
public:
	///构造方法
	CSysUserIpChgResource(void);
	virtual ~CSysUserIpChgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysUserIpChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysUserIpChgFactory
	///@return	该CSysUserIpChgFactory
	CSysUserIpChgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysUserIpChgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysUserIpChgResource *alloc(int type, CSysUserIpChgFactory *pFactory, CSysUserIpChg *pObject, CWriteableSysUserIpChg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysUserIpChgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysUserIpChg writeableObject;
	
	static CMemoryStack<CSysUserIpChgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeResource是一个说明在CSysPartTradeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysPartTradeResource(void);
	virtual ~CSysPartTradeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPartTradeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysPartTradeFactory
	///@return	该CSysPartTradeFactory
	CSysPartTradeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysPartTradeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysPartTradeResource *alloc(int type, CSysPartTradeFactory *pFactory, CSysPartTrade *pObject, CWriteableSysPartTrade *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysPartTradeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysPartTrade writeableObject;
	
	static CMemoryStack<CSysPartTradeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrResource是一个说明在CSysMdbObjectAttrFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbObjectAttrResource(void);
	virtual ~CSysMdbObjectAttrResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbObjectAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbObjectAttrFactory
	///@return	该CSysMdbObjectAttrFactory
	CSysMdbObjectAttrFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbObjectAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbObjectAttrResource *alloc(int type, CSysMdbObjectAttrFactory *pFactory, CSysMdbObjectAttr *pObject, CWriteableSysMdbObjectAttr *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbObjectAttrFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbObjectAttr writeableObject;
	
	static CMemoryStack<CSysMdbObjectAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoResource是一个说明在CSysMdbSyslogInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbSyslogInfoResource(void);
	virtual ~CSysMdbSyslogInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbSyslogInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbSyslogInfoFactory
	///@return	该CSysMdbSyslogInfoFactory
	CSysMdbSyslogInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbSyslogInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbSyslogInfoResource *alloc(int type, CSysMdbSyslogInfoFactory *pFactory, CSysMdbSyslogInfo *pObject, CWriteableSysMdbSyslogInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbSyslogInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbSyslogInfo writeableObject;
	
	static CMemoryStack<CSysMdbSyslogInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoResource是一个说明在CSysUserInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysUserInfoResource(void);
	virtual ~CSysUserInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysUserInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysUserInfoFactory
	///@return	该CSysUserInfoFactory
	CSysUserInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysUserInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysUserInfoResource *alloc(int type, CSysUserInfoFactory *pFactory, CSysUserInfo *pObject, CWriteableSysUserInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysUserInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysUserInfo writeableObject;
	
	static CMemoryStack<CSysUserInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoResource是一个说明在CSysOnlineUserInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysOnlineUserInfoResource(void);
	virtual ~CSysOnlineUserInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysOnlineUserInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysOnlineUserInfoFactory
	///@return	该CSysOnlineUserInfoFactory
	CSysOnlineUserInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysOnlineUserInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysOnlineUserInfoResource *alloc(int type, CSysOnlineUserInfoFactory *pFactory, CSysOnlineUserInfo *pObject, CWriteableSysOnlineUserInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysOnlineUserInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysOnlineUserInfo writeableObject;
	
	static CMemoryStack<CSysOnlineUserInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventResource是一个说明在CSysWarningEventFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventResource : public CDatabaseResource
{
public:
	///构造方法
	CSysWarningEventResource(void);
	virtual ~CSysWarningEventResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysWarningEventFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysWarningEventFactory
	///@return	该CSysWarningEventFactory
	CSysWarningEventFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysWarningEventFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysWarningEventResource *alloc(int type, CSysWarningEventFactory *pFactory, CSysWarningEvent *pObject, CWriteableSysWarningEvent *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysWarningEventFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysWarningEvent writeableObject;
	
	static CMemoryStack<CSysWarningEventResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryResource是一个说明在CSysWarningQueryFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryResource : public CDatabaseResource
{
public:
	///构造方法
	CSysWarningQueryResource(void);
	virtual ~CSysWarningQueryResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysWarningQueryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysWarningQueryFactory
	///@return	该CSysWarningQueryFactory
	CSysWarningQueryFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysWarningQueryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysWarningQueryResource *alloc(int type, CSysWarningQueryFactory *pFactory, CSysWarningQuery *pObject, CWriteableSysWarningQuery *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysWarningQueryFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysWarningQuery writeableObject;
	
	static CMemoryStack<CSysWarningQueryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventResource是一个说明在CSyslogEventFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventResource : public CDatabaseResource
{
public:
	///构造方法
	CSyslogEventResource(void);
	virtual ~CSyslogEventResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSyslogEventFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSyslogEventFactory
	///@return	该CSyslogEventFactory
	CSyslogEventFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSyslogEventFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSyslogEventResource *alloc(int type, CSyslogEventFactory *pFactory, CSyslogEvent *pObject, CWriteableSyslogEvent *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSyslogEventFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSyslogEvent writeableObject;
	
	static CMemoryStack<CSyslogEventResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripResource是一个说明在CSysEventDescripFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripResource : public CDatabaseResource
{
public:
	///构造方法
	CSysEventDescripResource(void);
	virtual ~CSysEventDescripResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysEventDescripFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysEventDescripFactory
	///@return	该CSysEventDescripFactory
	CSysEventDescripFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysEventDescripFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysEventDescripResource *alloc(int type, CSysEventDescripFactory *pFactory, CSysEventDescrip *pObject, CWriteableSysEventDescrip *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysEventDescripFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysEventDescrip writeableObject;
	
	static CMemoryStack<CSysEventDescripResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonResource是一个说明在CRspQryHostEnvCommonFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonResource : public CDatabaseResource
{
public:
	///构造方法
	CRspQryHostEnvCommonResource(void);
	virtual ~CRspQryHostEnvCommonResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvCommonFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRspQryHostEnvCommonFactory
	///@return	该CRspQryHostEnvCommonFactory
	CRspQryHostEnvCommonFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvCommonFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRspQryHostEnvCommonResource *alloc(int type, CRspQryHostEnvCommonFactory *pFactory, CRspQryHostEnvCommon *pObject, CWriteableRspQryHostEnvCommon *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRspQryHostEnvCommonFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRspQryHostEnvCommon writeableObject;
	
	static CMemoryStack<CRspQryHostEnvCommonResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanResource是一个说明在CRspQryHostEnvLanFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanResource : public CDatabaseResource
{
public:
	///构造方法
	CRspQryHostEnvLanResource(void);
	virtual ~CRspQryHostEnvLanResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvLanFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRspQryHostEnvLanFactory
	///@return	该CRspQryHostEnvLanFactory
	CRspQryHostEnvLanFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvLanFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRspQryHostEnvLanResource *alloc(int type, CRspQryHostEnvLanFactory *pFactory, CRspQryHostEnvLan *pObject, CWriteableRspQryHostEnvLan *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRspQryHostEnvLanFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRspQryHostEnvLan writeableObject;
	
	static CMemoryStack<CRspQryHostEnvLanResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageResource是一个说明在CRspQryHostEnvStorageFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageResource : public CDatabaseResource
{
public:
	///构造方法
	CRspQryHostEnvStorageResource(void);
	virtual ~CRspQryHostEnvStorageResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvStorageFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRspQryHostEnvStorageFactory
	///@return	该CRspQryHostEnvStorageFactory
	CRspQryHostEnvStorageFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvStorageFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRspQryHostEnvStorageResource *alloc(int type, CRspQryHostEnvStorageFactory *pFactory, CRspQryHostEnvStorage *pObject, CWriteableRspQryHostEnvStorage *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRspQryHostEnvStorageFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRspQryHostEnvStorage writeableObject;
	
	static CMemoryStack<CRspQryHostEnvStorageResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOResource是一个说明在CRspQryHostEnvIOFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOResource : public CDatabaseResource
{
public:
	///构造方法
	CRspQryHostEnvIOResource(void);
	virtual ~CRspQryHostEnvIOResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvIOFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRspQryHostEnvIOFactory
	///@return	该CRspQryHostEnvIOFactory
	CRspQryHostEnvIOFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvIOFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRspQryHostEnvIOResource *alloc(int type, CRspQryHostEnvIOFactory *pFactory, CRspQryHostEnvIO *pObject, CWriteableRspQryHostEnvIO *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRspQryHostEnvIOFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRspQryHostEnvIO writeableObject;
	
	static CMemoryStack<CRspQryHostEnvIOResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSResource是一个说明在CRspQryHostEnvFSFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSResource : public CDatabaseResource
{
public:
	///构造方法
	CRspQryHostEnvFSResource(void);
	virtual ~CRspQryHostEnvFSResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvFSFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRspQryHostEnvFSFactory
	///@return	该CRspQryHostEnvFSFactory
	CRspQryHostEnvFSFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvFSFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRspQryHostEnvFSResource *alloc(int type, CRspQryHostEnvFSFactory *pFactory, CRspQryHostEnvFS *pObject, CWriteableRspQryHostEnvFS *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRspQryHostEnvFSFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRspQryHostEnvFS writeableObject;
	
	static CMemoryStack<CRspQryHostEnvFSResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapResource是一个说明在CRspQryHostEnvSwapFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapResource : public CDatabaseResource
{
public:
	///构造方法
	CRspQryHostEnvSwapResource(void);
	virtual ~CRspQryHostEnvSwapResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvSwapFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRspQryHostEnvSwapFactory
	///@return	该CRspQryHostEnvSwapFactory
	CRspQryHostEnvSwapFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvSwapFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRspQryHostEnvSwapResource *alloc(int type, CRspQryHostEnvSwapFactory *pFactory, CRspQryHostEnvSwap *pObject, CWriteableRspQryHostEnvSwap *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRspQryHostEnvSwapFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRspQryHostEnvSwap writeableObject;
	
	static CMemoryStack<CRspQryHostEnvSwapResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgResource是一个说明在CRspQryHostEnvLanCfgFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgResource : public CDatabaseResource
{
public:
	///构造方法
	CRspQryHostEnvLanCfgResource(void);
	virtual ~CRspQryHostEnvLanCfgResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvLanCfgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRspQryHostEnvLanCfgFactory
	///@return	该CRspQryHostEnvLanCfgFactory
	CRspQryHostEnvLanCfgFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRspQryHostEnvLanCfgFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRspQryHostEnvLanCfgResource *alloc(int type, CRspQryHostEnvLanCfgFactory *pFactory, CRspQryHostEnvLanCfg *pObject, CWriteableRspQryHostEnvLanCfg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRspQryHostEnvLanCfgFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRspQryHostEnvLanCfg writeableObject;
	
	static CMemoryStack<CRspQryHostEnvLanCfgResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoResource是一个说明在CSysMdbTopCpuInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbTopCpuInfoResource(void);
	virtual ~CSysMdbTopCpuInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTopCpuInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbTopCpuInfoFactory
	///@return	该CSysMdbTopCpuInfoFactory
	CSysMdbTopCpuInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTopCpuInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbTopCpuInfoResource *alloc(int type, CSysMdbTopCpuInfoFactory *pFactory, CSysMdbTopCpuInfo *pObject, CWriteableSysMdbTopCpuInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbTopCpuInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbTopCpuInfo writeableObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoResource是一个说明在CSysMdbTopMemInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbTopMemInfoResource(void);
	virtual ~CSysMdbTopMemInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTopMemInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbTopMemInfoFactory
	///@return	该CSysMdbTopMemInfoFactory
	CSysMdbTopMemInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTopMemInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbTopMemInfoResource *alloc(int type, CSysMdbTopMemInfoFactory *pFactory, CSysMdbTopMemInfo *pObject, CWriteableSysMdbTopMemInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbTopMemInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbTopMemInfo writeableObject;
	
	static CMemoryStack<CSysMdbTopMemInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoResource是一个说明在CSysMdbTopProcessInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbTopProcessInfoResource(void);
	virtual ~CSysMdbTopProcessInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTopProcessInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbTopProcessInfoFactory
	///@return	该CSysMdbTopProcessInfoFactory
	CSysMdbTopProcessInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTopProcessInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbTopProcessInfoResource *alloc(int type, CSysMdbTopProcessInfoFactory *pFactory, CSysMdbTopProcessInfo *pObject, CWriteableSysMdbTopProcessInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbTopProcessInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbTopProcessInfo writeableObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoResource是一个说明在CSysMdbFileSystemInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbFileSystemInfoResource(void);
	virtual ~CSysMdbFileSystemInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbFileSystemInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbFileSystemInfoFactory
	///@return	该CSysMdbFileSystemInfoFactory
	CSysMdbFileSystemInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbFileSystemInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbFileSystemInfoResource *alloc(int type, CSysMdbFileSystemInfoFactory *pFactory, CSysMdbFileSystemInfo *pObject, CWriteableSysMdbFileSystemInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbFileSystemInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbFileSystemInfo writeableObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoResource是一个说明在CSysMdbNetworkInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbNetworkInfoResource(void);
	virtual ~CSysMdbNetworkInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbNetworkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbNetworkInfoFactory
	///@return	该CSysMdbNetworkInfoFactory
	CSysMdbNetworkInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbNetworkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbNetworkInfoResource *alloc(int type, CSysMdbNetworkInfoFactory *pFactory, CSysMdbNetworkInfo *pObject, CWriteableSysMdbNetworkInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbNetworkInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbNetworkInfo writeableObject;
	
	static CMemoryStack<CSysMdbNetworkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitResource是一个说明在CSysParticipantInitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitResource : public CDatabaseResource
{
public:
	///构造方法
	CSysParticipantInitResource(void);
	virtual ~CSysParticipantInitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysParticipantInitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysParticipantInitFactory
	///@return	该CSysParticipantInitFactory
	CSysParticipantInitFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysParticipantInitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysParticipantInitResource *alloc(int type, CSysParticipantInitFactory *pFactory, CSysParticipantInit *pObject, CWriteableSysParticipantInit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysParticipantInitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysParticipantInit writeableObject;
	
	static CMemoryStack<CSysParticipantInitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitResource是一个说明在CSysUserInitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitResource : public CDatabaseResource
{
public:
	///构造方法
	CSysUserInitResource(void);
	virtual ~CSysUserInitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysUserInitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysUserInitFactory
	///@return	该CSysUserInitFactory
	CSysUserInitFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysUserInitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysUserInitResource *alloc(int type, CSysUserInitFactory *pFactory, CSysUserInit *pObject, CWriteableSysUserInit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysUserInitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysUserInit writeableObject;
	
	static CMemoryStack<CSysUserInitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitResource是一个说明在CSysClientInitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitResource : public CDatabaseResource
{
public:
	///构造方法
	CSysClientInitResource(void);
	virtual ~CSysClientInitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientInitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysClientInitFactory
	///@return	该CSysClientInitFactory
	CSysClientInitFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysClientInitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysClientInitResource *alloc(int type, CSysClientInitFactory *pFactory, CSysClientInit *pObject, CWriteableSysClientInit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysClientInitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysClientInit writeableObject;
	
	static CMemoryStack<CSysClientInitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoResource是一个说明在CSysTradeUserLoginInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysTradeUserLoginInfoResource(void);
	virtual ~CSysTradeUserLoginInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysTradeUserLoginInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysTradeUserLoginInfoFactory
	///@return	该CSysTradeUserLoginInfoFactory
	CSysTradeUserLoginInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysTradeUserLoginInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysTradeUserLoginInfoResource *alloc(int type, CSysTradeUserLoginInfoFactory *pFactory, CSysTradeUserLoginInfo *pObject, CWriteableSysTradeUserLoginInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysTradeUserLoginInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysTradeUserLoginInfo writeableObject;
	
	static CMemoryStack<CSysTradeUserLoginInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoResource是一个说明在CSysMdbWebAppInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbWebAppInfoResource(void);
	virtual ~CSysMdbWebAppInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbWebAppInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbWebAppInfoFactory
	///@return	该CSysMdbWebAppInfoFactory
	CSysMdbWebAppInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbWebAppInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbWebAppInfoResource *alloc(int type, CSysMdbWebAppInfoFactory *pFactory, CSysMdbWebAppInfo *pObject, CWriteableSysMdbWebAppInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbWebAppInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbWebAppInfo writeableObject;
	
	static CMemoryStack<CSysMdbWebAppInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoResource是一个说明在CSysMdbMemPoolInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbMemPoolInfoResource(void);
	virtual ~CSysMdbMemPoolInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbMemPoolInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbMemPoolInfoFactory
	///@return	该CSysMdbMemPoolInfoFactory
	CSysMdbMemPoolInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbMemPoolInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbMemPoolInfoResource *alloc(int type, CSysMdbMemPoolInfoFactory *pFactory, CSysMdbMemPoolInfo *pObject, CWriteableSysMdbMemPoolInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbMemPoolInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbMemPoolInfo writeableObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoResource是一个说明在CSysMdbConnectorInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbConnectorInfoResource(void);
	virtual ~CSysMdbConnectorInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbConnectorInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbConnectorInfoFactory
	///@return	该CSysMdbConnectorInfoFactory
	CSysMdbConnectorInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbConnectorInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbConnectorInfoResource *alloc(int type, CSysMdbConnectorInfoFactory *pFactory, CSysMdbConnectorInfo *pObject, CWriteableSysMdbConnectorInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbConnectorInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbConnectorInfo writeableObject;
	
	static CMemoryStack<CSysMdbConnectorInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryResource是一个说明在CSysMdbDBQueryFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbDBQueryResource(void);
	virtual ~CSysMdbDBQueryResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbDBQueryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbDBQueryFactory
	///@return	该CSysMdbDBQueryFactory
	CSysMdbDBQueryFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbDBQueryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbDBQueryResource *alloc(int type, CSysMdbDBQueryFactory *pFactory, CSysMdbDBQuery *pObject, CWriteableSysMdbDBQuery *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbDBQueryFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbDBQuery writeableObject;
	
	static CMemoryStack<CSysMdbDBQueryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaResource是一个说明在CSysNetAreaFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetAreaResource(void);
	virtual ~CSysNetAreaResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetAreaFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetAreaFactory
	///@return	该CSysNetAreaFactory
	CSysNetAreaFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetAreaFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetAreaResource *alloc(int type, CSysNetAreaFactory *pFactory, CSysNetArea *pObject, CWriteableSysNetArea *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetAreaFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetArea writeableObject;
	
	static CMemoryStack<CSysNetAreaResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaResource是一个说明在CSysNetSubAreaFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetSubAreaResource(void);
	virtual ~CSysNetSubAreaResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetSubAreaFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetSubAreaFactory
	///@return	该CSysNetSubAreaFactory
	CSysNetSubAreaFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetSubAreaFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetSubAreaResource *alloc(int type, CSysNetSubAreaFactory *pFactory, CSysNetSubArea *pObject, CWriteableSysNetSubArea *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetSubAreaFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetSubArea writeableObject;
	
	static CMemoryStack<CSysNetSubAreaResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPResource是一个说明在CSysNetSubAreaIPFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetSubAreaIPResource(void);
	virtual ~CSysNetSubAreaIPResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetSubAreaIPFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetSubAreaIPFactory
	///@return	该CSysNetSubAreaIPFactory
	CSysNetSubAreaIPFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetSubAreaIPFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetSubAreaIPResource *alloc(int type, CSysNetSubAreaIPFactory *pFactory, CSysNetSubAreaIP *pObject, CWriteableSysNetSubAreaIP *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetSubAreaIPFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetSubAreaIP writeableObject;
	
	static CMemoryStack<CSysNetSubAreaIPResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaResource是一个说明在CSysNetFuncAreaFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetFuncAreaResource(void);
	virtual ~CSysNetFuncAreaResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetFuncAreaFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetFuncAreaFactory
	///@return	该CSysNetFuncAreaFactory
	CSysNetFuncAreaFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetFuncAreaFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetFuncAreaResource *alloc(int type, CSysNetFuncAreaFactory *pFactory, CSysNetFuncArea *pObject, CWriteableSysNetFuncArea *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetFuncAreaFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetFuncArea writeableObject;
	
	static CMemoryStack<CSysNetFuncAreaResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceResource是一个说明在CSysNetDeviceFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetDeviceResource(void);
	virtual ~CSysNetDeviceResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetDeviceFactory
	///@return	该CSysNetDeviceFactory
	CSysNetDeviceFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetDeviceResource *alloc(int type, CSysNetDeviceFactory *pFactory, CSysNetDevice *pObject, CWriteableSysNetDevice *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetDeviceFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetDevice writeableObject;
	
	static CMemoryStack<CSysNetDeviceResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedResource是一个说明在CSysNetDeviceLinkedFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetDeviceLinkedResource(void);
	virtual ~CSysNetDeviceLinkedResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceLinkedFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetDeviceLinkedFactory
	///@return	该CSysNetDeviceLinkedFactory
	CSysNetDeviceLinkedFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceLinkedFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetDeviceLinkedResource *alloc(int type, CSysNetDeviceLinkedFactory *pFactory, CSysNetDeviceLinked *pObject, CWriteableSysNetDeviceLinked *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetDeviceLinkedFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetDeviceLinked writeableObject;
	
	static CMemoryStack<CSysNetDeviceLinkedResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDResource是一个说明在CSysNetOIDFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetOIDResource(void);
	virtual ~CSysNetOIDResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetOIDFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetOIDFactory
	///@return	该CSysNetOIDFactory
	CSysNetOIDFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetOIDFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetOIDResource *alloc(int type, CSysNetOIDFactory *pFactory, CSysNetOID *pObject, CWriteableSysNetOID *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetOIDFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetOID writeableObject;
	
	static CMemoryStack<CSysNetOIDResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeResource是一个说明在CSysNetDeviceTypeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetDeviceTypeResource(void);
	virtual ~CSysNetDeviceTypeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetDeviceTypeFactory
	///@return	该CSysNetDeviceTypeFactory
	CSysNetDeviceTypeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetDeviceTypeResource *alloc(int type, CSysNetDeviceTypeFactory *pFactory, CSysNetDeviceType *pObject, CWriteableSysNetDeviceType *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetDeviceTypeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetDeviceType writeableObject;
	
	static CMemoryStack<CSysNetDeviceTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyResource是一个说明在CSysNetTimePolicyFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetTimePolicyResource(void);
	virtual ~CSysNetTimePolicyResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetTimePolicyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetTimePolicyFactory
	///@return	该CSysNetTimePolicyFactory
	CSysNetTimePolicyFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetTimePolicyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetTimePolicyResource *alloc(int type, CSysNetTimePolicyFactory *pFactory, CSysNetTimePolicy *pObject, CWriteableSysNetTimePolicy *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetTimePolicyFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetTimePolicy writeableObject;
	
	static CMemoryStack<CSysNetTimePolicyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskResource是一个说明在CSysNetGatherTaskFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetGatherTaskResource(void);
	virtual ~CSysNetGatherTaskResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetGatherTaskFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetGatherTaskFactory
	///@return	该CSysNetGatherTaskFactory
	CSysNetGatherTaskFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetGatherTaskFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetGatherTaskResource *alloc(int type, CSysNetGatherTaskFactory *pFactory, CSysNetGatherTask *pObject, CWriteableSysNetGatherTask *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetGatherTaskFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetGatherTask writeableObject;
	
	static CMemoryStack<CSysNetGatherTaskResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryResource是一个说明在CSysNetDeviceCategoryFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetDeviceCategoryResource(void);
	virtual ~CSysNetDeviceCategoryResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceCategoryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetDeviceCategoryFactory
	///@return	该CSysNetDeviceCategoryFactory
	CSysNetDeviceCategoryFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDeviceCategoryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetDeviceCategoryResource *alloc(int type, CSysNetDeviceCategoryFactory *pFactory, CSysNetDeviceCategory *pObject, CWriteableSysNetDeviceCategory *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetDeviceCategoryFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetDeviceCategory writeableObject;
	
	static CMemoryStack<CSysNetDeviceCategoryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryResource是一个说明在CSysNetManufactoryFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetManufactoryResource(void);
	virtual ~CSysNetManufactoryResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetManufactoryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetManufactoryFactory
	///@return	该CSysNetManufactoryFactory
	CSysNetManufactoryFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetManufactoryFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetManufactoryResource *alloc(int type, CSysNetManufactoryFactory *pFactory, CSysNetManufactory *pObject, CWriteableSysNetManufactory *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetManufactoryFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetManufactory writeableObject;
	
	static CMemoryStack<CSysNetManufactoryResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityResource是一个说明在CSysNetCommunityFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetCommunityResource(void);
	virtual ~CSysNetCommunityResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetCommunityFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetCommunityFactory
	///@return	该CSysNetCommunityFactory
	CSysNetCommunityFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetCommunityFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetCommunityResource *alloc(int type, CSysNetCommunityFactory *pFactory, CSysNetCommunity *pObject, CWriteableSysNetCommunity *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetCommunityFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetCommunity writeableObject;
	
	static CMemoryStack<CSysNetCommunityResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeResource是一个说明在CSysNetPortTypeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetPortTypeResource(void);
	virtual ~CSysNetPortTypeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPortTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetPortTypeFactory
	///@return	该CSysNetPortTypeFactory
	CSysNetPortTypeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPortTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetPortTypeResource *alloc(int type, CSysNetPortTypeFactory *pFactory, CSysNetPortType *pObject, CWriteableSysNetPortType *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetPortTypeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetPortType writeableObject;
	
	static CMemoryStack<CSysNetPortTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceResource是一个说明在CSysNetInterfaceFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetInterfaceResource(void);
	virtual ~CSysNetInterfaceResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetInterfaceFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetInterfaceFactory
	///@return	该CSysNetInterfaceFactory
	CSysNetInterfaceFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetInterfaceFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetInterfaceResource *alloc(int type, CSysNetInterfaceFactory *pFactory, CSysNetInterface *pObject, CWriteableSysNetInterface *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetInterfaceFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetInterface writeableObject;
	
	static CMemoryStack<CSysNetInterfaceResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDResource是一个说明在CSysNetGeneralOIDFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetGeneralOIDResource(void);
	virtual ~CSysNetGeneralOIDResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetGeneralOIDFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetGeneralOIDFactory
	///@return	该CSysNetGeneralOIDFactory
	CSysNetGeneralOIDFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetGeneralOIDFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetGeneralOIDResource *alloc(int type, CSysNetGeneralOIDFactory *pFactory, CSysNetGeneralOID *pObject, CWriteableSysNetGeneralOID *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetGeneralOIDFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetGeneralOID writeableObject;
	
	static CMemoryStack<CSysNetGeneralOIDResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeResource是一个说明在CSysNetMonitorTypeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorTypeResource(void);
	virtual ~CSysNetMonitorTypeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorTypeFactory
	///@return	该CSysNetMonitorTypeFactory
	CSysNetMonitorTypeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorTypeResource *alloc(int type, CSysNetMonitorTypeFactory *pFactory, CSysNetMonitorType *pObject, CWriteableSysNetMonitorType *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorTypeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorType writeableObject;
	
	static CMemoryStack<CSysNetMonitorTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeResource是一个说明在CSysNetMonitorAttrScopeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorAttrScopeResource(void);
	virtual ~CSysNetMonitorAttrScopeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorAttrScopeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorAttrScopeFactory
	///@return	该CSysNetMonitorAttrScopeFactory
	CSysNetMonitorAttrScopeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorAttrScopeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorAttrScopeResource *alloc(int type, CSysNetMonitorAttrScopeFactory *pFactory, CSysNetMonitorAttrScope *pObject, CWriteableSysNetMonitorAttrScope *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorAttrScopeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorAttrScope writeableObject;
	
	static CMemoryStack<CSysNetMonitorAttrScopeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeResource是一个说明在CSysNetMonitorAttrTypeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorAttrTypeResource(void);
	virtual ~CSysNetMonitorAttrTypeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorAttrTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorAttrTypeFactory
	///@return	该CSysNetMonitorAttrTypeFactory
	CSysNetMonitorAttrTypeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorAttrTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorAttrTypeResource *alloc(int type, CSysNetMonitorAttrTypeFactory *pFactory, CSysNetMonitorAttrType *pObject, CWriteableSysNetMonitorAttrType *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorAttrTypeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorAttrType writeableObject;
	
	static CMemoryStack<CSysNetMonitorAttrTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeResource是一个说明在CSysNetMonitorCommandTypeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorCommandTypeResource(void);
	virtual ~CSysNetMonitorCommandTypeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorCommandTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorCommandTypeFactory
	///@return	该CSysNetMonitorCommandTypeFactory
	CSysNetMonitorCommandTypeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorCommandTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorCommandTypeResource *alloc(int type, CSysNetMonitorCommandTypeFactory *pFactory, CSysNetMonitorCommandType *pObject, CWriteableSysNetMonitorCommandType *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorCommandTypeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorCommandType writeableObject;
	
	static CMemoryStack<CSysNetMonitorCommandTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupResource是一个说明在CSysNetMonitorActionGroupFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorActionGroupResource(void);
	virtual ~CSysNetMonitorActionGroupResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorActionGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorActionGroupFactory
	///@return	该CSysNetMonitorActionGroupFactory
	CSysNetMonitorActionGroupFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorActionGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorActionGroupResource *alloc(int type, CSysNetMonitorActionGroupFactory *pFactory, CSysNetMonitorActionGroup *pObject, CWriteableSysNetMonitorActionGroup *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorActionGroupFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorActionGroup writeableObject;
	
	static CMemoryStack<CSysNetMonitorActionGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupResource是一个说明在CSysNetMonitorDeviceGroupFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorDeviceGroupResource(void);
	virtual ~CSysNetMonitorDeviceGroupResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorDeviceGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorDeviceGroupFactory
	///@return	该CSysNetMonitorDeviceGroupFactory
	CSysNetMonitorDeviceGroupFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorDeviceGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorDeviceGroupResource *alloc(int type, CSysNetMonitorDeviceGroupFactory *pFactory, CSysNetMonitorDeviceGroup *pObject, CWriteableSysNetMonitorDeviceGroup *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorDeviceGroupFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorDeviceGroup writeableObject;
	
	static CMemoryStack<CSysNetMonitorDeviceGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoResource是一个说明在CSysNetMonitorTaskInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorTaskInfoResource(void);
	virtual ~CSysNetMonitorTaskInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorTaskInfoFactory
	///@return	该CSysNetMonitorTaskInfoFactory
	CSysNetMonitorTaskInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorTaskInfoResource *alloc(int type, CSysNetMonitorTaskInfoFactory *pFactory, CSysNetMonitorTaskInfo *pObject, CWriteableSysNetMonitorTaskInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorTaskInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorTaskInfo writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetResource是一个说明在CSysNetMonitorTaskObjectSetFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorTaskObjectSetResource(void);
	virtual ~CSysNetMonitorTaskObjectSetResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskObjectSetFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorTaskObjectSetFactory
	///@return	该CSysNetMonitorTaskObjectSetFactory
	CSysNetMonitorTaskObjectSetFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskObjectSetFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorTaskObjectSetResource *alloc(int type, CSysNetMonitorTaskObjectSetFactory *pFactory, CSysNetMonitorTaskObjectSet *pObject, CWriteableSysNetMonitorTaskObjectSet *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorTaskObjectSetFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorTaskObjectSet writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskObjectSetResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultResource是一个说明在CSysNetMonitorTaskResultFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorTaskResultResource(void);
	virtual ~CSysNetMonitorTaskResultResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskResultFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorTaskResultFactory
	///@return	该CSysNetMonitorTaskResultFactory
	CSysNetMonitorTaskResultFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskResultFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorTaskResultResource *alloc(int type, CSysNetMonitorTaskResultFactory *pFactory, CSysNetMonitorTaskResult *pObject, CWriteableSysNetMonitorTaskResult *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorTaskResultFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorTaskResult writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoResource是一个说明在CSysNetPartyLinkInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetPartyLinkInfoResource(void);
	virtual ~CSysNetPartyLinkInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPartyLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetPartyLinkInfoFactory
	///@return	该CSysNetPartyLinkInfoFactory
	CSysNetPartyLinkInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPartyLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetPartyLinkInfoResource *alloc(int type, CSysNetPartyLinkInfoFactory *pFactory, CSysNetPartyLinkInfo *pObject, CWriteableSysNetPartyLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetPartyLinkInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetPartyLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetPartyLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoResource是一个说明在CSysNetDelPartyLinkInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetDelPartyLinkInfoResource(void);
	virtual ~CSysNetDelPartyLinkInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDelPartyLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetDelPartyLinkInfoFactory
	///@return	该CSysNetDelPartyLinkInfoFactory
	CSysNetDelPartyLinkInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDelPartyLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetDelPartyLinkInfoResource *alloc(int type, CSysNetDelPartyLinkInfoFactory *pFactory, CSysNetDelPartyLinkInfo *pObject, CWriteableSysNetDelPartyLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetDelPartyLinkInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetDelPartyLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetDelPartyLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeResource是一个说明在CSysNetPartyLinkAddrChangeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetPartyLinkAddrChangeResource(void);
	virtual ~CSysNetPartyLinkAddrChangeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPartyLinkAddrChangeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetPartyLinkAddrChangeFactory
	///@return	该CSysNetPartyLinkAddrChangeFactory
	CSysNetPartyLinkAddrChangeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPartyLinkAddrChangeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetPartyLinkAddrChangeResource *alloc(int type, CSysNetPartyLinkAddrChangeFactory *pFactory, CSysNetPartyLinkAddrChange *pObject, CWriteableSysNetPartyLinkAddrChange *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetPartyLinkAddrChangeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetPartyLinkAddrChange writeableObject;
	
	static CMemoryStack<CSysNetPartyLinkAddrChangeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrResource是一个说明在CSysNetMonitorActionAttrFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorActionAttrResource(void);
	virtual ~CSysNetMonitorActionAttrResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorActionAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorActionAttrFactory
	///@return	该CSysNetMonitorActionAttrFactory
	CSysNetMonitorActionAttrFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorActionAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorActionAttrResource *alloc(int type, CSysNetMonitorActionAttrFactory *pFactory, CSysNetMonitorActionAttr *pObject, CWriteableSysNetMonitorActionAttr *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorActionAttrFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorActionAttr writeableObject;
	
	static CMemoryStack<CSysNetMonitorActionAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleResource是一个说明在CSysNetModuleFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetModuleResource(void);
	virtual ~CSysNetModuleResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetModuleFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetModuleFactory
	///@return	该CSysNetModuleFactory
	CSysNetModuleFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetModuleFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetModuleResource *alloc(int type, CSysNetModuleFactory *pFactory, CSysNetModule *pObject, CWriteableSysNetModule *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetModuleFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetModule writeableObject;
	
	static CMemoryStack<CSysNetModuleResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprResource是一个说明在CSysNetEventExprFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetEventExprResource(void);
	virtual ~CSysNetEventExprResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetEventExprFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetEventExprFactory
	///@return	该CSysNetEventExprFactory
	CSysNetEventExprFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetEventExprFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetEventExprResource *alloc(int type, CSysNetEventExprFactory *pFactory, CSysNetEventExpr *pObject, CWriteableSysNetEventExpr *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetEventExprFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetEventExpr writeableObject;
	
	static CMemoryStack<CSysNetEventExprResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeResource是一个说明在CSysNetEventTypeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetEventTypeResource(void);
	virtual ~CSysNetEventTypeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetEventTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetEventTypeFactory
	///@return	该CSysNetEventTypeFactory
	CSysNetEventTypeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetEventTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetEventTypeResource *alloc(int type, CSysNetEventTypeFactory *pFactory, CSysNetEventType *pObject, CWriteableSysNetEventType *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetEventTypeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetEventType writeableObject;
	
	static CMemoryStack<CSysNetEventTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeResource是一个说明在CSysNetSubEventTypeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetSubEventTypeResource(void);
	virtual ~CSysNetSubEventTypeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetSubEventTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetSubEventTypeFactory
	///@return	该CSysNetSubEventTypeFactory
	CSysNetSubEventTypeFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetSubEventTypeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetSubEventTypeResource *alloc(int type, CSysNetSubEventTypeFactory *pFactory, CSysNetSubEventType *pObject, CWriteableSysNetSubEventType *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetSubEventTypeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetSubEventType writeableObject;
	
	static CMemoryStack<CSysNetSubEventTypeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelResource是一个说明在CSysNetEventLevelFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetEventLevelResource(void);
	virtual ~CSysNetEventLevelResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetEventLevelFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetEventLevelFactory
	///@return	该CSysNetEventLevelFactory
	CSysNetEventLevelFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetEventLevelFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetEventLevelResource *alloc(int type, CSysNetEventLevelFactory *pFactory, CSysNetEventLevel *pObject, CWriteableSysNetEventLevel *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetEventLevelFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetEventLevel writeableObject;
	
	static CMemoryStack<CSysNetEventLevelResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskResource是一个说明在CSysNetMonitorDeviceTaskFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorDeviceTaskResource(void);
	virtual ~CSysNetMonitorDeviceTaskResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorDeviceTaskFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorDeviceTaskFactory
	///@return	该CSysNetMonitorDeviceTaskFactory
	CSysNetMonitorDeviceTaskFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorDeviceTaskFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorDeviceTaskResource *alloc(int type, CSysNetMonitorDeviceTaskFactory *pFactory, CSysNetMonitorDeviceTask *pObject, CWriteableSysNetMonitorDeviceTask *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorDeviceTaskFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorDeviceTask writeableObject;
	
	static CMemoryStack<CSysNetMonitorDeviceTaskResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsResource是一个说明在CSysNetMonitorTaskInstAttrsFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMonitorTaskInstAttrsResource(void);
	virtual ~CSysNetMonitorTaskInstAttrsResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskInstAttrsFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMonitorTaskInstAttrsFactory
	///@return	该CSysNetMonitorTaskInstAttrsFactory
	CSysNetMonitorTaskInstAttrsFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMonitorTaskInstAttrsFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMonitorTaskInstAttrsResource *alloc(int type, CSysNetMonitorTaskInstAttrsFactory *pFactory, CSysNetMonitorTaskInstAttrs *pObject, CWriteableSysNetMonitorTaskInstAttrs *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMonitorTaskInstAttrsFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMonitorTaskInstAttrs writeableObject;
	
	static CMemoryStack<CSysNetMonitorTaskInstAttrsResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineResource是一个说明在CSysNetBaseLineFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetBaseLineResource(void);
	virtual ~CSysNetBaseLineResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetBaseLineFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetBaseLineFactory
	///@return	该CSysNetBaseLineFactory
	CSysNetBaseLineFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetBaseLineFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetBaseLineResource *alloc(int type, CSysNetBaseLineFactory *pFactory, CSysNetBaseLine *pObject, CWriteableSysNetBaseLine *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetBaseLineFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetBaseLine writeableObject;
	
	static CMemoryStack<CSysNetBaseLineResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskResource是一个说明在CSysNetBaseLineTaskFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetBaseLineTaskResource(void);
	virtual ~CSysNetBaseLineTaskResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetBaseLineTaskFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetBaseLineTaskFactory
	///@return	该CSysNetBaseLineTaskFactory
	CSysNetBaseLineTaskFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetBaseLineTaskFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetBaseLineTaskResource *alloc(int type, CSysNetBaseLineTaskFactory *pFactory, CSysNetBaseLineTask *pObject, CWriteableSysNetBaseLineTask *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetBaseLineTaskFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetBaseLineTask writeableObject;
	
	static CMemoryStack<CSysNetBaseLineTaskResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoResource是一个说明在CSysMdbNetPartyLinkStatusInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbNetPartyLinkStatusInfoResource(void);
	virtual ~CSysMdbNetPartyLinkStatusInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbNetPartyLinkStatusInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbNetPartyLinkStatusInfoFactory
	///@return	该CSysMdbNetPartyLinkStatusInfoFactory
	CSysMdbNetPartyLinkStatusInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbNetPartyLinkStatusInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbNetPartyLinkStatusInfoResource *alloc(int type, CSysMdbNetPartyLinkStatusInfoFactory *pFactory, CSysMdbNetPartyLinkStatusInfo *pObject, CWriteableSysMdbNetPartyLinkStatusInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbNetPartyLinkStatusInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbNetPartyLinkStatusInfo writeableObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoResource是一个说明在CSysNetMemberSDHLineInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetMemberSDHLineInfoResource(void);
	virtual ~CSysNetMemberSDHLineInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMemberSDHLineInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetMemberSDHLineInfoFactory
	///@return	该CSysNetMemberSDHLineInfoFactory
	CSysNetMemberSDHLineInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetMemberSDHLineInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetMemberSDHLineInfoResource *alloc(int type, CSysNetMemberSDHLineInfoFactory *pFactory, CSysNetMemberSDHLineInfo *pObject, CWriteableSysNetMemberSDHLineInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetMemberSDHLineInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetMemberSDHLineInfo writeableObject;
	
	static CMemoryStack<CSysNetMemberSDHLineInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoResource是一个说明在CSysNetDDNLinkInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetDDNLinkInfoResource(void);
	virtual ~CSysNetDDNLinkInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDDNLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetDDNLinkInfoFactory
	///@return	该CSysNetDDNLinkInfoFactory
	CSysNetDDNLinkInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetDDNLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetDDNLinkInfoResource *alloc(int type, CSysNetDDNLinkInfoFactory *pFactory, CSysNetDDNLinkInfo *pObject, CWriteableSysNetDDNLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetDDNLinkInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetDDNLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetDDNLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoResource是一个说明在CSysNetPseudMemberLinkInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetPseudMemberLinkInfoResource(void);
	virtual ~CSysNetPseudMemberLinkInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPseudMemberLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetPseudMemberLinkInfoFactory
	///@return	该CSysNetPseudMemberLinkInfoFactory
	CSysNetPseudMemberLinkInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPseudMemberLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetPseudMemberLinkInfoResource *alloc(int type, CSysNetPseudMemberLinkInfoFactory *pFactory, CSysNetPseudMemberLinkInfo *pObject, CWriteableSysNetPseudMemberLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetPseudMemberLinkInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetPseudMemberLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetPseudMemberLinkInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoResource是一个说明在CSysNetOuterDeviceInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetOuterDeviceInfoResource(void);
	virtual ~CSysNetOuterDeviceInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetOuterDeviceInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetOuterDeviceInfoFactory
	///@return	该CSysNetOuterDeviceInfoFactory
	CSysNetOuterDeviceInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetOuterDeviceInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetOuterDeviceInfoResource *alloc(int type, CSysNetOuterDeviceInfoFactory *pFactory, CSysNetOuterDeviceInfo *pObject, CWriteableSysNetOuterDeviceInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetOuterDeviceInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetOuterDeviceInfo writeableObject;
	
	static CMemoryStack<CSysNetOuterDeviceInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoResource是一个说明在CSysLocalPingResultInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysLocalPingResultInfoResource(void);
	virtual ~CSysLocalPingResultInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysLocalPingResultInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysLocalPingResultInfoFactory
	///@return	该CSysLocalPingResultInfoFactory
	CSysLocalPingResultInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysLocalPingResultInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysLocalPingResultInfoResource *alloc(int type, CSysLocalPingResultInfoFactory *pFactory, CSysLocalPingResultInfo *pObject, CWriteableSysLocalPingResultInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysLocalPingResultInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysLocalPingResultInfo writeableObject;
	
	static CMemoryStack<CSysLocalPingResultInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoResource是一个说明在CSysRomotePingResultInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysRomotePingResultInfoResource(void);
	virtual ~CSysRomotePingResultInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysRomotePingResultInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysRomotePingResultInfoFactory
	///@return	该CSysRomotePingResultInfoFactory
	CSysRomotePingResultInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysRomotePingResultInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysRomotePingResultInfoResource *alloc(int type, CSysRomotePingResultInfoFactory *pFactory, CSysRomotePingResultInfo *pObject, CWriteableSysRomotePingResultInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysRomotePingResultInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysRomotePingResultInfo writeableObject;
	
	static CMemoryStack<CSysRomotePingResultInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesResource是一个说明在CSysParticTradeOrderStatesFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesResource : public CDatabaseResource
{
public:
	///构造方法
	CSysParticTradeOrderStatesResource(void);
	virtual ~CSysParticTradeOrderStatesResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysParticTradeOrderStatesFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysParticTradeOrderStatesFactory
	///@return	该CSysParticTradeOrderStatesFactory
	CSysParticTradeOrderStatesFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysParticTradeOrderStatesFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysParticTradeOrderStatesResource *alloc(int type, CSysParticTradeOrderStatesFactory *pFactory, CSysParticTradeOrderStates *pObject, CWriteableSysParticTradeOrderStates *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysParticTradeOrderStatesFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysParticTradeOrderStates writeableObject;
	
	static CMemoryStack<CSysParticTradeOrderStatesResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoResource是一个说明在CSysMdbRouterInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbRouterInfoResource(void);
	virtual ~CSysMdbRouterInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbRouterInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbRouterInfoFactory
	///@return	该CSysMdbRouterInfoFactory
	CSysMdbRouterInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbRouterInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbRouterInfoResource *alloc(int type, CSysMdbRouterInfoFactory *pFactory, CSysMdbRouterInfo *pObject, CWriteableSysMdbRouterInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbRouterInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbRouterInfo writeableObject;
	
	static CMemoryStack<CSysMdbRouterInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOResource是一个说明在CSysMdbDiskIOFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbDiskIOResource(void);
	virtual ~CSysMdbDiskIOResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbDiskIOFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbDiskIOFactory
	///@return	该CSysMdbDiskIOFactory
	CSysMdbDiskIOFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbDiskIOFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbDiskIOResource *alloc(int type, CSysMdbDiskIOFactory *pFactory, CSysMdbDiskIO *pObject, CWriteableSysMdbDiskIO *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbDiskIOFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbDiskIO writeableObject;
	
	static CMemoryStack<CSysMdbDiskIOResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoResource是一个说明在CSysMdbStatInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbStatInfoResource(void);
	virtual ~CSysMdbStatInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbStatInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbStatInfoFactory
	///@return	该CSysMdbStatInfoFactory
	CSysMdbStatInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbStatInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbStatInfoResource *alloc(int type, CSysMdbStatInfoFactory *pFactory, CSysMdbStatInfo *pObject, CWriteableSysMdbStatInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbStatInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbStatInfo writeableObject;
	
	static CMemoryStack<CSysMdbStatInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatResource是一个说明在CSysMdbTradeFrontOrderRttStatFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMdbTradeFrontOrderRttStatResource(void);
	virtual ~CSysMdbTradeFrontOrderRttStatResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTradeFrontOrderRttStatFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMdbTradeFrontOrderRttStatFactory
	///@return	该CSysMdbTradeFrontOrderRttStatFactory
	CSysMdbTradeFrontOrderRttStatFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMdbTradeFrontOrderRttStatFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMdbTradeFrontOrderRttStatResource *alloc(int type, CSysMdbTradeFrontOrderRttStatFactory *pFactory, CSysMdbTradeFrontOrderRttStat *pObject, CWriteableSysMdbTradeFrontOrderRttStat *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMdbTradeFrontOrderRttStatFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMdbTradeFrontOrderRttStat writeableObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusResource是一个说明在CSysInstrumentStatusFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusResource : public CDatabaseResource
{
public:
	///构造方法
	CSysInstrumentStatusResource(void);
	virtual ~CSysInstrumentStatusResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysInstrumentStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysInstrumentStatusFactory
	///@return	该CSysInstrumentStatusFactory
	CSysInstrumentStatusFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysInstrumentStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysInstrumentStatusResource *alloc(int type, CSysInstrumentStatusFactory *pFactory, CSysInstrumentStatus *pObject, CWriteableSysInstrumentStatus *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysInstrumentStatusFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysInstrumentStatus writeableObject;
	
	static CMemoryStack<CSysInstrumentStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrResource是一个说明在CSysCurrTradingSegmentAttrFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrResource : public CDatabaseResource
{
public:
	///构造方法
	CSysCurrTradingSegmentAttrResource(void);
	virtual ~CSysCurrTradingSegmentAttrResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysCurrTradingSegmentAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysCurrTradingSegmentAttrFactory
	///@return	该CSysCurrTradingSegmentAttrFactory
	CSysCurrTradingSegmentAttrFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysCurrTradingSegmentAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysCurrTradingSegmentAttrResource *alloc(int type, CSysCurrTradingSegmentAttrFactory *pFactory, CSysCurrTradingSegmentAttr *pObject, CWriteableSysCurrTradingSegmentAttr *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysCurrTradingSegmentAttrFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysCurrTradingSegmentAttr writeableObject;
	
	static CMemoryStack<CSysCurrTradingSegmentAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostResource是一个说明在CSysMemberLinkCostFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostResource : public CDatabaseResource
{
public:
	///构造方法
	CSysMemberLinkCostResource(void);
	virtual ~CSysMemberLinkCostResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMemberLinkCostFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysMemberLinkCostFactory
	///@return	该CSysMemberLinkCostFactory
	CSysMemberLinkCostFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysMemberLinkCostFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysMemberLinkCostResource *alloc(int type, CSysMemberLinkCostFactory *pFactory, CSysMemberLinkCost *pObject, CWriteableSysMemberLinkCost *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysMemberLinkCostFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysMemberLinkCost writeableObject;
	
	static CMemoryStack<CSysMemberLinkCostResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentResource是一个说明在CSysNetPartylinkMonthlyRentFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetPartylinkMonthlyRentResource(void);
	virtual ~CSysNetPartylinkMonthlyRentResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPartylinkMonthlyRentFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetPartylinkMonthlyRentFactory
	///@return	该CSysNetPartylinkMonthlyRentFactory
	CSysNetPartylinkMonthlyRentFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetPartylinkMonthlyRentFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetPartylinkMonthlyRentResource *alloc(int type, CSysNetPartylinkMonthlyRentFactory *pFactory, CSysNetPartylinkMonthlyRent *pObject, CWriteableSysNetPartylinkMonthlyRent *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetPartylinkMonthlyRentFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetPartylinkMonthlyRent writeableObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoResource是一个说明在CSysNetNonPartyLinkInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CSysNetNonPartyLinkInfoResource(void);
	virtual ~CSysNetNonPartyLinkInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetNonPartyLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSysNetNonPartyLinkInfoFactory
	///@return	该CSysNetNonPartyLinkInfoFactory
	CSysNetNonPartyLinkInfoFactory *getFactory(void)
	{
		return pFactory;
	}

	///完成提交
	virtual void commit(void);
	
	///完成滚回
	virtual void rollback(void);
	
	///获取优先级，优先级可以控制commit时的次序
	///@return	本资源的优先级，0表示最高，1表示正常，1表示最低
	virtual int getPriority(void);

	///申请一个有指定内容的资源
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSysNetNonPartyLinkInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSysNetNonPartyLinkInfoResource *alloc(int type, CSysNetNonPartyLinkInfoFactory *pFactory, CSysNetNonPartyLinkInfo *pObject, CWriteableSysNetNonPartyLinkInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSysNetNonPartyLinkInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSysNetNonPartyLinkInfo writeableObject;
	
	static CMemoryStack<CSysNetNonPartyLinkInfoResource> resourceList;
};

#endif
