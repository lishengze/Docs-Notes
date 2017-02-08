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
///CExchangeDataSyncStatusResource是一个说明在CExchangeDataSyncStatusFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusResource : public CDatabaseResource
{
public:
	///构造方法
	CExchangeDataSyncStatusResource(void);
	virtual ~CExchangeDataSyncStatusResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CExchangeDataSyncStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CExchangeDataSyncStatusFactory
	///@return	该CExchangeDataSyncStatusFactory
	CExchangeDataSyncStatusFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CExchangeDataSyncStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CExchangeDataSyncStatusResource *alloc(int type, CExchangeDataSyncStatusFactory *pFactory, CExchangeDataSyncStatus *pObject, CWriteableExchangeDataSyncStatus *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CExchangeDataSyncStatusFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableExchangeDataSyncStatus writeableObject;
	
	static CMemoryStack<CExchangeDataSyncStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusResource是一个说明在CSGDataSyncStatusFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusResource : public CDatabaseResource
{
public:
	///构造方法
	CSGDataSyncStatusResource(void);
	virtual ~CSGDataSyncStatusResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSGDataSyncStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSGDataSyncStatusFactory
	///@return	该CSGDataSyncStatusFactory
	CSGDataSyncStatusFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CSGDataSyncStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSGDataSyncStatusResource *alloc(int type, CSGDataSyncStatusFactory *pFactory, CSGDataSyncStatus *pObject, CWriteableSGDataSyncStatus *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSGDataSyncStatusFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSGDataSyncStatus writeableObject;
	
	static CMemoryStack<CSGDataSyncStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeResource是一个说明在CCurrentTimeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrentTimeResource(void);
	virtual ~CCurrentTimeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrentTimeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrentTimeFactory
	///@return	该CCurrentTimeFactory
	CCurrentTimeFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrentTimeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrentTimeResource *alloc(int type, CCurrentTimeFactory *pFactory, CCurrentTime *pObject, CWriteableCurrentTime *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrentTimeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrentTime writeableObject;
	
	static CMemoryStack<CCurrentTimeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescResource是一个说明在CDataCenterDescFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescResource : public CDatabaseResource
{
public:
	///构造方法
	CDataCenterDescResource(void);
	virtual ~CDataCenterDescResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CDataCenterDescFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CDataCenterDescFactory
	///@return	该CDataCenterDescFactory
	CDataCenterDescFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CDataCenterDescFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CDataCenterDescResource *alloc(int type, CDataCenterDescFactory *pFactory, CDataCenterDesc *pObject, CWriteableDataCenterDesc *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CDataCenterDescFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableDataCenterDesc writeableObject;
	
	static CMemoryStack<CDataCenterDescResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeResource是一个说明在CExchangeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeResource : public CDatabaseResource
{
public:
	///构造方法
	CExchangeResource(void);
	virtual ~CExchangeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CExchangeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CExchangeFactory
	///@return	该CExchangeFactory
	CExchangeFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CExchangeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CExchangeResource *alloc(int type, CExchangeFactory *pFactory, CExchange *pObject, CWriteableExchange *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CExchangeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableExchange writeableObject;
	
	static CMemoryStack<CExchangeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupResource是一个说明在CSettlementGroupFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupResource : public CDatabaseResource
{
public:
	///构造方法
	CSettlementGroupResource(void);
	virtual ~CSettlementGroupResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CSettlementGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CSettlementGroupFactory
	///@return	该CSettlementGroupFactory
	CSettlementGroupFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CSettlementGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CSettlementGroupResource *alloc(int type, CSettlementGroupFactory *pFactory, CSettlementGroup *pObject, CWriteableSettlementGroup *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CSettlementGroupFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableSettlementGroup writeableObject;
	
	static CMemoryStack<CSettlementGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketResource是一个说明在CMarketFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketResource : public CDatabaseResource
{
public:
	///构造方法
	CMarketResource(void);
	virtual ~CMarketResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMarketFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMarketFactory
	///@return	该CMarketFactory
	CMarketFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMarketFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMarketResource *alloc(int type, CMarketFactory *pFactory, CMarket *pObject, CWriteableMarket *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMarketFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMarket writeableObject;
	
	static CMemoryStack<CMarketResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductResource是一个说明在CMarketProductFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductResource : public CDatabaseResource
{
public:
	///构造方法
	CMarketProductResource(void);
	virtual ~CMarketProductResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMarketProductFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMarketProductFactory
	///@return	该CMarketProductFactory
	CMarketProductFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMarketProductFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMarketProductResource *alloc(int type, CMarketProductFactory *pFactory, CMarketProduct *pObject, CWriteableMarketProduct *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMarketProductFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMarketProduct writeableObject;
	
	static CMemoryStack<CMarketProductResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupResource是一个说明在CMarketProductGroupFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupResource : public CDatabaseResource
{
public:
	///构造方法
	CMarketProductGroupResource(void);
	virtual ~CMarketProductGroupResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMarketProductGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMarketProductGroupFactory
	///@return	该CMarketProductGroupFactory
	CMarketProductGroupFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMarketProductGroupFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMarketProductGroupResource *alloc(int type, CMarketProductGroupFactory *pFactory, CMarketProductGroup *pObject, CWriteableMarketProductGroup *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMarketProductGroupFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMarketProductGroup writeableObject;
	
	static CMemoryStack<CMarketProductGroupResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusResource是一个说明在CMdPubStatusFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusResource : public CDatabaseResource
{
public:
	///构造方法
	CMdPubStatusResource(void);
	virtual ~CMdPubStatusResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMdPubStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMdPubStatusFactory
	///@return	该CMdPubStatusFactory
	CMdPubStatusFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMdPubStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMdPubStatusResource *alloc(int type, CMdPubStatusFactory *pFactory, CMdPubStatus *pObject, CWriteableMdPubStatus *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMdPubStatusFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMdPubStatus writeableObject;
	
	static CMemoryStack<CMdPubStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicResource是一个说明在CMarketDataTopicFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicResource : public CDatabaseResource
{
public:
	///构造方法
	CMarketDataTopicResource(void);
	virtual ~CMarketDataTopicResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMarketDataTopicFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMarketDataTopicFactory
	///@return	该CMarketDataTopicFactory
	CMarketDataTopicFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMarketDataTopicFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMarketDataTopicResource *alloc(int type, CMarketDataTopicFactory *pFactory, CMarketDataTopic *pObject, CWriteableMarketDataTopic *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMarketDataTopicFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMarketDataTopic writeableObject;
	
	static CMemoryStack<CMarketDataTopicResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeResource是一个说明在CPartTopicSubscribeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeResource : public CDatabaseResource
{
public:
	///构造方法
	CPartTopicSubscribeResource(void);
	virtual ~CPartTopicSubscribeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartTopicSubscribeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartTopicSubscribeFactory
	///@return	该CPartTopicSubscribeFactory
	CPartTopicSubscribeFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartTopicSubscribeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartTopicSubscribeResource *alloc(int type, CPartTopicSubscribeFactory *pFactory, CPartTopicSubscribe *pObject, CWriteablePartTopicSubscribe *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartTopicSubscribeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartTopicSubscribe writeableObject;
	
	static CMemoryStack<CPartTopicSubscribeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantResource是一个说明在CParticipantFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantResource : public CDatabaseResource
{
public:
	///构造方法
	CParticipantResource(void);
	virtual ~CParticipantResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CParticipantFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CParticipantFactory
	///@return	该CParticipantFactory
	CParticipantFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CParticipantFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CParticipantResource *alloc(int type, CParticipantFactory *pFactory, CParticipant *pObject, CWriteableParticipant *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CParticipantFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableParticipant writeableObject;
	
	static CMemoryStack<CParticipantResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserResource是一个说明在CUserFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserResource : public CDatabaseResource
{
public:
	///构造方法
	CUserResource(void);
	virtual ~CUserResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CUserFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CUserFactory
	///@return	该CUserFactory
	CUserFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CUserFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CUserResource *alloc(int type, CUserFactory *pFactory, CUser *pObject, CWriteableUser *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CUserFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableUser writeableObject;
	
	static CMemoryStack<CUserResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientResource是一个说明在CClientFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientResource : public CDatabaseResource
{
public:
	///构造方法
	CClientResource(void);
	virtual ~CClientResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CClientFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CClientFactory
	///@return	该CClientFactory
	CClientFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CClientFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CClientResource *alloc(int type, CClientFactory *pFactory, CClient *pObject, CWriteableClient *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CClientFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableClient writeableObject;
	
	static CMemoryStack<CClientResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPResource是一个说明在CUserIPFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPResource : public CDatabaseResource
{
public:
	///构造方法
	CUserIPResource(void);
	virtual ~CUserIPResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CUserIPFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CUserIPFactory
	///@return	该CUserIPFactory
	CUserIPFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CUserIPFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CUserIPResource *alloc(int type, CUserIPFactory *pFactory, CUserIP *pObject, CWriteableUserIP *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CUserIPFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableUserIP writeableObject;
	
	static CMemoryStack<CUserIPResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientResource是一个说明在CPartClientFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientResource : public CDatabaseResource
{
public:
	///构造方法
	CPartClientResource(void);
	virtual ~CPartClientResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartClientFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartClientFactory
	///@return	该CPartClientFactory
	CPartClientFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartClientFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartClientResource *alloc(int type, CPartClientFactory *pFactory, CPartClient *pObject, CWriteablePartClient *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartClientFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartClient writeableObject;
	
	static CMemoryStack<CPartClientResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartResource是一个说明在CClearingTradingPartFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartResource : public CDatabaseResource
{
public:
	///构造方法
	CClearingTradingPartResource(void);
	virtual ~CClearingTradingPartResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CClearingTradingPartFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CClearingTradingPartFactory
	///@return	该CClearingTradingPartFactory
	CClearingTradingPartFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CClearingTradingPartFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CClearingTradingPartResource *alloc(int type, CClearingTradingPartFactory *pFactory, CClearingTradingPart *pObject, CWriteableClearingTradingPart *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CClearingTradingPartFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableClearingTradingPart writeableObject;
	
	static CMemoryStack<CClearingTradingPartResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineResource是一个说明在CAliasDefineFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineResource : public CDatabaseResource
{
public:
	///构造方法
	CAliasDefineResource(void);
	virtual ~CAliasDefineResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CAliasDefineFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CAliasDefineFactory
	///@return	该CAliasDefineFactory
	CAliasDefineFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CAliasDefineFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CAliasDefineResource *alloc(int type, CAliasDefineFactory *pFactory, CAliasDefine *pObject, CWriteableAliasDefine *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CAliasDefineFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableAliasDefine writeableObject;
	
	static CMemoryStack<CAliasDefineResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightResource是一个说明在CUserFunctionRightFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightResource : public CDatabaseResource
{
public:
	///构造方法
	CUserFunctionRightResource(void);
	virtual ~CUserFunctionRightResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CUserFunctionRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CUserFunctionRightFactory
	///@return	该CUserFunctionRightFactory
	CUserFunctionRightFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CUserFunctionRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CUserFunctionRightResource *alloc(int type, CUserFunctionRightFactory *pFactory, CUserFunctionRight *pObject, CWriteableUserFunctionRight *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CUserFunctionRightFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableUserFunctionRight writeableObject;
	
	static CMemoryStack<CUserFunctionRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CAccountResource是一个说明在CAccountFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountResource : public CDatabaseResource
{
public:
	///构造方法
	CAccountResource(void);
	virtual ~CAccountResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CAccountFactory
	///@return	该CAccountFactory
	CAccountFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CAccountResource *alloc(int type, CAccountFactory *pFactory, CAccount *pObject, CWriteableAccount *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CAccountFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableAccount writeableObject;
	
	static CMemoryStack<CAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxResource是一个说明在CUserCommFluxFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxResource : public CDatabaseResource
{
public:
	///构造方法
	CUserCommFluxResource(void);
	virtual ~CUserCommFluxResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CUserCommFluxFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CUserCommFluxFactory
	///@return	该CUserCommFluxFactory
	CUserCommFluxFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CUserCommFluxFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CUserCommFluxResource *alloc(int type, CUserCommFluxFactory *pFactory, CUserCommFlux *pObject, CWriteableUserCommFlux *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CUserCommFluxFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableUserCommFlux writeableObject;
	
	static CMemoryStack<CUserCommFluxResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogResource是一个说明在CMarketDataLogFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogResource : public CDatabaseResource
{
public:
	///构造方法
	CMarketDataLogResource(void);
	virtual ~CMarketDataLogResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMarketDataLogFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMarketDataLogFactory
	///@return	该CMarketDataLogFactory
	CMarketDataLogFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMarketDataLogFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMarketDataLogResource *alloc(int type, CMarketDataLogFactory *pFactory, CMarketDataLog *pObject, CWriteableMarketDataLog *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMarketDataLogFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMarketDataLog writeableObject;
	
	static CMemoryStack<CMarketDataLogResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionResource是一个说明在CUserSessionFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionResource : public CDatabaseResource
{
public:
	///构造方法
	CUserSessionResource(void);
	virtual ~CUserSessionResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CUserSessionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CUserSessionFactory
	///@return	该CUserSessionFactory
	CUserSessionFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CUserSessionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CUserSessionResource *alloc(int type, CUserSessionFactory *pFactory, CUserSession *pObject, CWriteableUserSession *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CUserSessionFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableUserSession writeableObject;
	
	static CMemoryStack<CUserSessionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionResource是一个说明在CMDSessionFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionResource : public CDatabaseResource
{
public:
	///构造方法
	CMDSessionResource(void);
	virtual ~CMDSessionResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMDSessionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMDSessionFactory
	///@return	该CMDSessionFactory
	CMDSessionFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMDSessionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMDSessionResource *alloc(int type, CMDSessionFactory *pFactory, CMDSession *pObject, CWriteableMDSession *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMDSessionFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMDSession writeableObject;
	
	static CMemoryStack<CMDSessionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoResource是一个说明在CLoginInfoFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoResource : public CDatabaseResource
{
public:
	///构造方法
	CLoginInfoResource(void);
	virtual ~CLoginInfoResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CLoginInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CLoginInfoFactory
	///@return	该CLoginInfoFactory
	CLoginInfoFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CLoginInfoFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CLoginInfoResource *alloc(int type, CLoginInfoFactory *pFactory, CLoginInfo *pObject, CWriteableLoginInfo *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CLoginInfoFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableLoginInfo writeableObject;
	
	static CMemoryStack<CLoginInfoResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailResource是一个说明在CDepthMarketDataDetailFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailResource : public CDatabaseResource
{
public:
	///构造方法
	CDepthMarketDataDetailResource(void);
	virtual ~CDepthMarketDataDetailResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CDepthMarketDataDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CDepthMarketDataDetailFactory
	///@return	该CDepthMarketDataDetailFactory
	CDepthMarketDataDetailFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CDepthMarketDataDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CDepthMarketDataDetailResource *alloc(int type, CDepthMarketDataDetailFactory *pFactory, CDepthMarketDataDetail *pObject, CWriteableDepthMarketDataDetail *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CDepthMarketDataDetailFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableDepthMarketDataDetail writeableObject;
	
	static CMemoryStack<CDepthMarketDataDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailResource是一个说明在CInstrumentStatusDetailFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailResource : public CDatabaseResource
{
public:
	///构造方法
	CInstrumentStatusDetailResource(void);
	virtual ~CInstrumentStatusDetailResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CInstrumentStatusDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CInstrumentStatusDetailFactory
	///@return	该CInstrumentStatusDetailFactory
	CInstrumentStatusDetailFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CInstrumentStatusDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CInstrumentStatusDetailResource *alloc(int type, CInstrumentStatusDetailFactory *pFactory, CInstrumentStatusDetail *pObject, CWriteableInstrumentStatusDetail *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CInstrumentStatusDetailFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableInstrumentStatusDetail writeableObject;
	
	static CMemoryStack<CInstrumentStatusDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusResource是一个说明在CFrontStatusFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusResource : public CDatabaseResource
{
public:
	///构造方法
	CFrontStatusResource(void);
	virtual ~CFrontStatusResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CFrontStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CFrontStatusFactory
	///@return	该CFrontStatusFactory
	CFrontStatusFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CFrontStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CFrontStatusResource *alloc(int type, CFrontStatusFactory *pFactory, CFrontStatus *pObject, CWriteableFrontStatus *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CFrontStatusFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableFrontStatus writeableObject;
	
	static CMemoryStack<CFrontStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDResource是一个说明在CMaxLocalIDFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDResource : public CDatabaseResource
{
public:
	///构造方法
	CMaxLocalIDResource(void);
	virtual ~CMaxLocalIDResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMaxLocalIDFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMaxLocalIDFactory
	///@return	该CMaxLocalIDFactory
	CMaxLocalIDFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMaxLocalIDFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMaxLocalIDResource *alloc(int type, CMaxLocalIDFactory *pFactory, CMaxLocalID *pObject, CWriteableMaxLocalID *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMaxLocalIDFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMaxLocalID writeableObject;
	
	static CMemoryStack<CMaxLocalIDResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinResource是一个说明在CBulletinFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinResource : public CDatabaseResource
{
public:
	///构造方法
	CBulletinResource(void);
	virtual ~CBulletinResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CBulletinFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CBulletinFactory
	///@return	该CBulletinFactory
	CBulletinFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CBulletinFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CBulletinResource *alloc(int type, CBulletinFactory *pFactory, CBulletin *pObject, CWriteableBulletin *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CBulletinFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableBulletin writeableObject;
	
	static CMemoryStack<CBulletinResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyResource是一个说明在CMarketDataModifyFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyResource : public CDatabaseResource
{
public:
	///构造方法
	CMarketDataModifyResource(void);
	virtual ~CMarketDataModifyResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMarketDataModifyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMarketDataModifyFactory
	///@return	该CMarketDataModifyFactory
	CMarketDataModifyFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMarketDataModifyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMarketDataModifyResource *alloc(int type, CMarketDataModifyFactory *pFactory, CMarketDataModify *pObject, CWriteableMarketDataModify *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMarketDataModifyFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMarketDataModify writeableObject;
	
	static CMemoryStack<CMarketDataModifyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataResource是一个说明在CDepthMarketDataFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataResource : public CDatabaseResource
{
public:
	///构造方法
	CDepthMarketDataResource(void);
	virtual ~CDepthMarketDataResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CDepthMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CDepthMarketDataFactory
	///@return	该CDepthMarketDataFactory
	CDepthMarketDataFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CDepthMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CDepthMarketDataResource *alloc(int type, CDepthMarketDataFactory *pFactory, CDepthMarketData *pObject, CWriteableDepthMarketData *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CDepthMarketDataFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableDepthMarketData writeableObject;
	
	static CMemoryStack<CDepthMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataResource是一个说明在CTopicMarketDataFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataResource : public CDatabaseResource
{
public:
	///构造方法
	CTopicMarketDataResource(void);
	virtual ~CTopicMarketDataResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CTopicMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CTopicMarketDataFactory
	///@return	该CTopicMarketDataFactory
	CTopicMarketDataFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CTopicMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CTopicMarketDataResource *alloc(int type, CTopicMarketDataFactory *pFactory, CTopicMarketData *pObject, CWriteableTopicMarketData *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CTopicMarketDataFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableTopicMarketData writeableObject;
	
	static CMemoryStack<CTopicMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionResource是一个说明在CTopicMarketDataVersionFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionResource : public CDatabaseResource
{
public:
	///构造方法
	CTopicMarketDataVersionResource(void);
	virtual ~CTopicMarketDataVersionResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CTopicMarketDataVersionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CTopicMarketDataVersionFactory
	///@return	该CTopicMarketDataVersionFactory
	CTopicMarketDataVersionFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CTopicMarketDataVersionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CTopicMarketDataVersionResource *alloc(int type, CTopicMarketDataVersionFactory *pFactory, CTopicMarketDataVersion *pObject, CWriteableTopicMarketDataVersion *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CTopicMarketDataVersionFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableTopicMarketDataVersion writeableObject;
	
	static CMemoryStack<CTopicMarketDataVersionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInformationResource是一个说明在CInformationFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationResource : public CDatabaseResource
{
public:
	///构造方法
	CInformationResource(void);
	virtual ~CInformationResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CInformationFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CInformationFactory
	///@return	该CInformationFactory
	CInformationFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CInformationFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CInformationResource *alloc(int type, CInformationFactory *pFactory, CInformation *pObject, CWriteableInformation *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CInformationFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableInformation writeableObject;
	
	static CMemoryStack<CInformationResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountResource是一个说明在COrderCountFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountResource : public CDatabaseResource
{
public:
	///构造方法
	COrderCountResource(void);
	virtual ~COrderCountResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的COrderCountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的COrderCountFactory
	///@return	该COrderCountFactory
	COrderCountFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的COrderCountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static COrderCountResource *alloc(int type, COrderCountFactory *pFactory, COrderCount *pObject, CWriteableOrderCount *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	COrderCountFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableOrderCount writeableObject;
	
	static CMemoryStack<COrderCountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentResource是一个说明在CInstrumentFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentResource : public CDatabaseResource
{
public:
	///构造方法
	CInstrumentResource(void);
	virtual ~CInstrumentResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CInstrumentFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CInstrumentFactory
	///@return	该CInstrumentFactory
	CInstrumentFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CInstrumentFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CInstrumentResource *alloc(int type, CInstrumentFactory *pFactory, CInstrument *pObject, CWriteableInstrument *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CInstrumentFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableInstrument writeableObject;
	
	static CMemoryStack<CInstrumentResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegResource是一个说明在CCombinationLegFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegResource : public CDatabaseResource
{
public:
	///构造方法
	CCombinationLegResource(void);
	virtual ~CCombinationLegResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCombinationLegFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCombinationLegFactory
	///@return	该CCombinationLegFactory
	CCombinationLegFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCombinationLegFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCombinationLegResource *alloc(int type, CCombinationLegFactory *pFactory, CCombinationLeg *pObject, CWriteableCombinationLeg *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCombinationLegFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCombinationLeg writeableObject;
	
	static CMemoryStack<CCombinationLegResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountResource是一个说明在CPartRoleAccountFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountResource : public CDatabaseResource
{
public:
	///构造方法
	CPartRoleAccountResource(void);
	virtual ~CPartRoleAccountResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartRoleAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartRoleAccountFactory
	///@return	该CPartRoleAccountFactory
	CPartRoleAccountFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartRoleAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartRoleAccountResource *alloc(int type, CPartRoleAccountFactory *pFactory, CPartRoleAccount *pObject, CWriteablePartRoleAccount *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartRoleAccountFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartRoleAccount writeableObject;
	
	static CMemoryStack<CPartRoleAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleResource是一个说明在CPartProductRoleFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleResource : public CDatabaseResource
{
public:
	///构造方法
	CPartProductRoleResource(void);
	virtual ~CPartProductRoleResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartProductRoleFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartProductRoleFactory
	///@return	该CPartProductRoleFactory
	CPartProductRoleFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartProductRoleFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartProductRoleResource *alloc(int type, CPartProductRoleFactory *pFactory, CPartProductRole *pObject, CWriteablePartProductRole *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartProductRoleFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartProductRole writeableObject;
	
	static CMemoryStack<CPartProductRoleResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightResource是一个说明在CPartProductRightFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightResource : public CDatabaseResource
{
public:
	///构造方法
	CPartProductRightResource(void);
	virtual ~CPartProductRightResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartProductRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartProductRightFactory
	///@return	该CPartProductRightFactory
	CPartProductRightFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartProductRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartProductRightResource *alloc(int type, CPartProductRightFactory *pFactory, CPartProductRight *pObject, CWriteablePartProductRight *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartProductRightFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartProductRight writeableObject;
	
	static CMemoryStack<CPartProductRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightResource是一个说明在CPartInstrumentRightFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightResource : public CDatabaseResource
{
public:
	///构造方法
	CPartInstrumentRightResource(void);
	virtual ~CPartInstrumentRightResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartInstrumentRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartInstrumentRightFactory
	///@return	该CPartInstrumentRightFactory
	CPartInstrumentRightFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartInstrumentRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartInstrumentRightResource *alloc(int type, CPartInstrumentRightFactory *pFactory, CPartInstrumentRight *pObject, CWriteablePartInstrumentRight *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartInstrumentRightFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartInstrumentRight writeableObject;
	
	static CMemoryStack<CPartInstrumentRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightResource是一个说明在CClientProductRightFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightResource : public CDatabaseResource
{
public:
	///构造方法
	CClientProductRightResource(void);
	virtual ~CClientProductRightResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CClientProductRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CClientProductRightFactory
	///@return	该CClientProductRightFactory
	CClientProductRightFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CClientProductRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CClientProductRightResource *alloc(int type, CClientProductRightFactory *pFactory, CClientProductRight *pObject, CWriteableClientProductRight *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CClientProductRightFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableClientProductRight writeableObject;
	
	static CMemoryStack<CClientProductRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightResource是一个说明在CClientInstrumentRightFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightResource : public CDatabaseResource
{
public:
	///构造方法
	CClientInstrumentRightResource(void);
	virtual ~CClientInstrumentRightResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CClientInstrumentRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CClientInstrumentRightFactory
	///@return	该CClientInstrumentRightFactory
	CClientInstrumentRightFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CClientInstrumentRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CClientInstrumentRightResource *alloc(int type, CClientInstrumentRightFactory *pFactory, CClientInstrumentRight *pObject, CWriteableClientInstrumentRight *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CClientInstrumentRightFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableClientInstrumentRight writeableObject;
	
	static CMemoryStack<CClientInstrumentRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightResource是一个说明在CPartClientProductRightFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightResource : public CDatabaseResource
{
public:
	///构造方法
	CPartClientProductRightResource(void);
	virtual ~CPartClientProductRightResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartClientProductRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartClientProductRightFactory
	///@return	该CPartClientProductRightFactory
	CPartClientProductRightFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartClientProductRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartClientProductRightResource *alloc(int type, CPartClientProductRightFactory *pFactory, CPartClientProductRight *pObject, CWriteablePartClientProductRight *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartClientProductRightFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartClientProductRight writeableObject;
	
	static CMemoryStack<CPartClientProductRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightResource是一个说明在CPartClientInstrumentRightFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightResource : public CDatabaseResource
{
public:
	///构造方法
	CPartClientInstrumentRightResource(void);
	virtual ~CPartClientInstrumentRightResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartClientInstrumentRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartClientInstrumentRightFactory
	///@return	该CPartClientInstrumentRightFactory
	CPartClientInstrumentRightFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartClientInstrumentRightFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartClientInstrumentRightResource *alloc(int type, CPartClientInstrumentRightFactory *pFactory, CPartClientInstrumentRight *pObject, CWriteablePartClientInstrumentRight *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartClientInstrumentRightFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartClientInstrumentRight writeableObject;
	
	static CMemoryStack<CPartClientInstrumentRightResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyResource是一个说明在CCurrProductPropertyFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrProductPropertyResource(void);
	virtual ~CCurrProductPropertyResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrProductPropertyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrProductPropertyFactory
	///@return	该CCurrProductPropertyFactory
	CCurrProductPropertyFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrProductPropertyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrProductPropertyResource *alloc(int type, CCurrProductPropertyFactory *pFactory, CCurrProductProperty *pObject, CWriteableCurrProductProperty *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrProductPropertyFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrProductProperty writeableObject;
	
	static CMemoryStack<CCurrProductPropertyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyResource是一个说明在CCurrInstrumentPropertyFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrInstrumentPropertyResource(void);
	virtual ~CCurrInstrumentPropertyResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrInstrumentPropertyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrInstrumentPropertyFactory
	///@return	该CCurrInstrumentPropertyFactory
	CCurrInstrumentPropertyFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrInstrumentPropertyFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrInstrumentPropertyResource *alloc(int type, CCurrInstrumentPropertyFactory *pFactory, CCurrInstrumentProperty *pObject, CWriteableCurrInstrumentProperty *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrInstrumentPropertyFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrInstrumentProperty writeableObject;
	
	static CMemoryStack<CCurrInstrumentPropertyResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingResource是一个说明在CCurrPriceBandingFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrPriceBandingResource(void);
	virtual ~CCurrPriceBandingResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrPriceBandingFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrPriceBandingFactory
	///@return	该CCurrPriceBandingFactory
	CCurrPriceBandingFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrPriceBandingFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrPriceBandingResource *alloc(int type, CCurrPriceBandingFactory *pFactory, CCurrPriceBanding *pObject, CWriteableCurrPriceBanding *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrPriceBandingFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrPriceBanding writeableObject;
	
	static CMemoryStack<CCurrPriceBandingResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateResource是一个说明在CCurrMarginRateFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrMarginRateResource(void);
	virtual ~CCurrMarginRateResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrMarginRateFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrMarginRateFactory
	///@return	该CCurrMarginRateFactory
	CCurrMarginRateFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrMarginRateFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrMarginRateResource *alloc(int type, CCurrMarginRateFactory *pFactory, CCurrMarginRate *pObject, CWriteableCurrMarginRate *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrMarginRateFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrMarginRate writeableObject;
	
	static CMemoryStack<CCurrMarginRateResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailResource是一个说明在CCurrMarginRateDetailFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrMarginRateDetailResource(void);
	virtual ~CCurrMarginRateDetailResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrMarginRateDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrMarginRateDetailFactory
	///@return	该CCurrMarginRateDetailFactory
	CCurrMarginRateDetailFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrMarginRateDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrMarginRateDetailResource *alloc(int type, CCurrMarginRateDetailFactory *pFactory, CCurrMarginRateDetail *pObject, CWriteableCurrMarginRateDetail *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrMarginRateDetailFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrMarginRateDetail writeableObject;
	
	static CMemoryStack<CCurrMarginRateDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitResource是一个说明在CCurrPartPosiLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrPartPosiLimitResource(void);
	virtual ~CCurrPartPosiLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrPartPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrPartPosiLimitFactory
	///@return	该CCurrPartPosiLimitFactory
	CCurrPartPosiLimitFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrPartPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrPartPosiLimitResource *alloc(int type, CCurrPartPosiLimitFactory *pFactory, CCurrPartPosiLimit *pObject, CWriteableCurrPartPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrPartPosiLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrPartPosiLimit writeableObject;
	
	static CMemoryStack<CCurrPartPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailResource是一个说明在CCurrPartPosiLimitDetailFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrPartPosiLimitDetailResource(void);
	virtual ~CCurrPartPosiLimitDetailResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrPartPosiLimitDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrPartPosiLimitDetailFactory
	///@return	该CCurrPartPosiLimitDetailFactory
	CCurrPartPosiLimitDetailFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrPartPosiLimitDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrPartPosiLimitDetailResource *alloc(int type, CCurrPartPosiLimitDetailFactory *pFactory, CCurrPartPosiLimitDetail *pObject, CWriteableCurrPartPosiLimitDetail *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrPartPosiLimitDetailFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrPartPosiLimitDetail writeableObject;
	
	static CMemoryStack<CCurrPartPosiLimitDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitResource是一个说明在CCurrClientPosiLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrClientPosiLimitResource(void);
	virtual ~CCurrClientPosiLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrClientPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrClientPosiLimitFactory
	///@return	该CCurrClientPosiLimitFactory
	CCurrClientPosiLimitFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrClientPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrClientPosiLimitResource *alloc(int type, CCurrClientPosiLimitFactory *pFactory, CCurrClientPosiLimit *pObject, CWriteableCurrClientPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrClientPosiLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrClientPosiLimit writeableObject;
	
	static CMemoryStack<CCurrClientPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailResource是一个说明在CCurrClientPosiLimitDetailFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrClientPosiLimitDetailResource(void);
	virtual ~CCurrClientPosiLimitDetailResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrClientPosiLimitDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrClientPosiLimitDetailFactory
	///@return	该CCurrClientPosiLimitDetailFactory
	CCurrClientPosiLimitDetailFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrClientPosiLimitDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrClientPosiLimitDetailResource *alloc(int type, CCurrClientPosiLimitDetailFactory *pFactory, CCurrClientPosiLimitDetail *pObject, CWriteableCurrClientPosiLimitDetail *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrClientPosiLimitDetailFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrClientPosiLimitDetail writeableObject;
	
	static CMemoryStack<CCurrClientPosiLimitDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitResource是一个说明在CCurrSpecialPosiLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrSpecialPosiLimitResource(void);
	virtual ~CCurrSpecialPosiLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrSpecialPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrSpecialPosiLimitFactory
	///@return	该CCurrSpecialPosiLimitFactory
	CCurrSpecialPosiLimitFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrSpecialPosiLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrSpecialPosiLimitResource *alloc(int type, CCurrSpecialPosiLimitFactory *pFactory, CCurrSpecialPosiLimit *pObject, CWriteableCurrSpecialPosiLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrSpecialPosiLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrSpecialPosiLimit writeableObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailResource是一个说明在CCurrSpecialPosiLimitDetailFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrSpecialPosiLimitDetailResource(void);
	virtual ~CCurrSpecialPosiLimitDetailResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrSpecialPosiLimitDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrSpecialPosiLimitDetailFactory
	///@return	该CCurrSpecialPosiLimitDetailFactory
	CCurrSpecialPosiLimitDetailFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrSpecialPosiLimitDetailFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrSpecialPosiLimitDetailResource *alloc(int type, CCurrSpecialPosiLimitDetailFactory *pFactory, CCurrSpecialPosiLimitDetail *pObject, CWriteableCurrSpecialPosiLimitDetail *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrSpecialPosiLimitDetailFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrSpecialPosiLimitDetail writeableObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitDetailResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleResource是一个说明在CCurrHedgeRuleFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrHedgeRuleResource(void);
	virtual ~CCurrHedgeRuleResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrHedgeRuleFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrHedgeRuleFactory
	///@return	该CCurrHedgeRuleFactory
	CCurrHedgeRuleFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrHedgeRuleFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrHedgeRuleResource *alloc(int type, CCurrHedgeRuleFactory *pFactory, CCurrHedgeRule *pObject, CWriteableCurrHedgeRule *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrHedgeRuleFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrHedgeRule writeableObject;
	
	static CMemoryStack<CCurrHedgeRuleResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrResource是一个说明在CCurrTradingSegmentAttrFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrTradingSegmentAttrResource(void);
	virtual ~CCurrTradingSegmentAttrResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrTradingSegmentAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrTradingSegmentAttrFactory
	///@return	该CCurrTradingSegmentAttrFactory
	CCurrTradingSegmentAttrFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrTradingSegmentAttrFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrTradingSegmentAttrResource *alloc(int type, CCurrTradingSegmentAttrFactory *pFactory, CCurrTradingSegmentAttr *pObject, CWriteableCurrTradingSegmentAttr *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrTradingSegmentAttrFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrTradingSegmentAttr writeableObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseResource是一个说明在CCurrFuseFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrFuseResource(void);
	virtual ~CCurrFuseResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrFuseFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrFuseFactory
	///@return	该CCurrFuseFactory
	CCurrFuseFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrFuseFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrFuseResource *alloc(int type, CCurrFuseFactory *pFactory, CCurrFuse *pObject, CWriteableCurrFuse *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrFuseFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrFuse writeableObject;
	
	static CMemoryStack<CCurrFuseResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountResource是一个说明在CTradingAccountFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountResource : public CDatabaseResource
{
public:
	///构造方法
	CTradingAccountResource(void);
	virtual ~CTradingAccountResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CTradingAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CTradingAccountFactory
	///@return	该CTradingAccountFactory
	CTradingAccountFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CTradingAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CTradingAccountResource *alloc(int type, CTradingAccountFactory *pFactory, CTradingAccount *pObject, CWriteableTradingAccount *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CTradingAccountFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableTradingAccount writeableObject;
	
	static CMemoryStack<CTradingAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountResource是一个说明在CBaseReserveAccountFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountResource : public CDatabaseResource
{
public:
	///构造方法
	CBaseReserveAccountResource(void);
	virtual ~CBaseReserveAccountResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CBaseReserveAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CBaseReserveAccountFactory
	///@return	该CBaseReserveAccountFactory
	CBaseReserveAccountFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CBaseReserveAccountFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CBaseReserveAccountResource *alloc(int type, CBaseReserveAccountFactory *pFactory, CBaseReserveAccount *pObject, CWriteableBaseReserveAccount *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CBaseReserveAccountFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableBaseReserveAccount writeableObject;
	
	static CMemoryStack<CBaseReserveAccountResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionResource是一个说明在CPartPositionFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionResource : public CDatabaseResource
{
public:
	///构造方法
	CPartPositionResource(void);
	virtual ~CPartPositionResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CPartPositionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CPartPositionFactory
	///@return	该CPartPositionFactory
	CPartPositionFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CPartPositionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CPartPositionResource *alloc(int type, CPartPositionFactory *pFactory, CPartPosition *pObject, CWriteablePartPosition *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CPartPositionFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteablePartPosition writeableObject;
	
	static CMemoryStack<CPartPositionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionResource是一个说明在CClientPositionFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionResource : public CDatabaseResource
{
public:
	///构造方法
	CClientPositionResource(void);
	virtual ~CClientPositionResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CClientPositionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CClientPositionFactory
	///@return	该CClientPositionFactory
	CClientPositionFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CClientPositionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CClientPositionResource *alloc(int type, CClientPositionFactory *pFactory, CClientPosition *pObject, CWriteableClientPosition *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CClientPositionFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableClientPosition writeableObject;
	
	static CMemoryStack<CClientPositionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeResource是一个说明在CHedgeVolumeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeResource : public CDatabaseResource
{
public:
	///构造方法
	CHedgeVolumeResource(void);
	virtual ~CHedgeVolumeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CHedgeVolumeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CHedgeVolumeFactory
	///@return	该CHedgeVolumeFactory
	CHedgeVolumeFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CHedgeVolumeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CHedgeVolumeResource *alloc(int type, CHedgeVolumeFactory *pFactory, CHedgeVolume *pObject, CWriteableHedgeVolume *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CHedgeVolumeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableHedgeVolume writeableObject;
	
	static CMemoryStack<CHedgeVolumeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderResource是一个说明在CRemainOrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderResource : public CDatabaseResource
{
public:
	///构造方法
	CRemainOrderResource(void);
	virtual ~CRemainOrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CRemainOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CRemainOrderFactory
	///@return	该CRemainOrderFactory
	CRemainOrderFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CRemainOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CRemainOrderResource *alloc(int type, CRemainOrderFactory *pFactory, CRemainOrder *pObject, CWriteableRemainOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CRemainOrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableRemainOrder writeableObject;
	
	static CMemoryStack<CRemainOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataResource是一个说明在CMarketDataFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataResource : public CDatabaseResource
{
public:
	///构造方法
	CMarketDataResource(void);
	virtual ~CMarketDataResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMarketDataFactory
	///@return	该CMarketDataFactory
	CMarketDataFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMarketDataResource *alloc(int type, CMarketDataFactory *pFactory, CMarketData *pObject, CWriteableMarketData *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMarketDataFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMarketData writeableObject;
	
	static CMemoryStack<CMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionResource是一个说明在CClearingPartPositionFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionResource : public CDatabaseResource
{
public:
	///构造方法
	CClearingPartPositionResource(void);
	virtual ~CClearingPartPositionResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CClearingPartPositionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CClearingPartPositionFactory
	///@return	该CClearingPartPositionFactory
	CClearingPartPositionFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CClearingPartPositionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CClearingPartPositionResource *alloc(int type, CClearingPartPositionFactory *pFactory, CClearingPartPosition *pObject, CWriteableClearingPartPosition *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CClearingPartPositionFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableClearingPartPosition writeableObject;
	
	static CMemoryStack<CClearingPartPositionResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusResource是一个说明在CInstrumentStatusFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusResource : public CDatabaseResource
{
public:
	///构造方法
	CInstrumentStatusResource(void);
	virtual ~CInstrumentStatusResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CInstrumentStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CInstrumentStatusFactory
	///@return	该CInstrumentStatusFactory
	CInstrumentStatusFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CInstrumentStatusFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CInstrumentStatusResource *alloc(int type, CInstrumentStatusFactory *pFactory, CInstrumentStatus *pObject, CWriteableInstrumentStatus *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CInstrumentStatusFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableInstrumentStatus writeableObject;
	
	static CMemoryStack<CInstrumentStatusResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///COrderResource是一个说明在COrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderResource : public CDatabaseResource
{
public:
	///构造方法
	COrderResource(void);
	virtual ~COrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的COrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的COrderFactory
	///@return	该COrderFactory
	COrderFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的COrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static COrderResource *alloc(int type, COrderFactory *pFactory, COrder *pObject, CWriteableOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	COrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableOrder writeableObject;
	
	static CMemoryStack<COrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderResource是一个说明在CCombOrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderResource : public CDatabaseResource
{
public:
	///构造方法
	CCombOrderResource(void);
	virtual ~CCombOrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCombOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCombOrderFactory
	///@return	该CCombOrderFactory
	CCombOrderFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCombOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCombOrderResource *alloc(int type, CCombOrderFactory *pFactory, CCombOrder *pObject, CWriteableCombOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCombOrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCombOrder writeableObject;
	
	static CMemoryStack<CCombOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderResource是一个说明在COTCOrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderResource : public CDatabaseResource
{
public:
	///构造方法
	COTCOrderResource(void);
	virtual ~COTCOrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的COTCOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的COTCOrderFactory
	///@return	该COTCOrderFactory
	COTCOrderFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的COTCOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static COTCOrderResource *alloc(int type, COTCOrderFactory *pFactory, COTCOrder *pObject, CWriteableOTCOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	COTCOrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableOTCOrder writeableObject;
	
	static CMemoryStack<COTCOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderResource是一个说明在CImplyOrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderResource : public CDatabaseResource
{
public:
	///构造方法
	CImplyOrderResource(void);
	virtual ~CImplyOrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CImplyOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CImplyOrderFactory
	///@return	该CImplyOrderFactory
	CImplyOrderFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CImplyOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CImplyOrderResource *alloc(int type, CImplyOrderFactory *pFactory, CImplyOrder *pObject, CWriteableImplyOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CImplyOrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableImplyOrder writeableObject;
	
	static CMemoryStack<CImplyOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteResource是一个说明在CQuoteFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteResource : public CDatabaseResource
{
public:
	///构造方法
	CQuoteResource(void);
	virtual ~CQuoteResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CQuoteFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CQuoteFactory
	///@return	该CQuoteFactory
	CQuoteFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CQuoteFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CQuoteResource *alloc(int type, CQuoteFactory *pFactory, CQuote *pObject, CWriteableQuote *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CQuoteFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableQuote writeableObject;
	
	static CMemoryStack<CQuoteResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataResource是一个说明在CMBLMarketDataFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataResource : public CDatabaseResource
{
public:
	///构造方法
	CMBLMarketDataResource(void);
	virtual ~CMBLMarketDataResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CMBLMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CMBLMarketDataFactory
	///@return	该CMBLMarketDataFactory
	CMBLMarketDataFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CMBLMarketDataFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CMBLMarketDataResource *alloc(int type, CMBLMarketDataFactory *pFactory, CMBLMarketData *pObject, CWriteableMBLMarketData *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CMBLMarketDataFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableMBLMarketData writeableObject;
	
	static CMemoryStack<CMBLMarketDataResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CTradeResource是一个说明在CTradeFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeResource : public CDatabaseResource
{
public:
	///构造方法
	CTradeResource(void);
	virtual ~CTradeResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CTradeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CTradeFactory
	///@return	该CTradeFactory
	CTradeFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CTradeFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CTradeResource *alloc(int type, CTradeFactory *pFactory, CTrade *pObject, CWriteableTrade *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CTradeFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableTrade writeableObject;
	
	static CMemoryStack<CTradeResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseResource是一个说明在CFusePhaseFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseResource : public CDatabaseResource
{
public:
	///构造方法
	CFusePhaseResource(void);
	virtual ~CFusePhaseResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CFusePhaseFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CFusePhaseFactory
	///@return	该CFusePhaseFactory
	CFusePhaseFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CFusePhaseFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CFusePhaseResource *alloc(int type, CFusePhaseFactory *pFactory, CFusePhase *pObject, CWriteableFusePhase *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CFusePhaseFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableFusePhase writeableObject;
	
	static CMemoryStack<CFusePhaseResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderResource是一个说明在CExecOrderFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderResource : public CDatabaseResource
{
public:
	///构造方法
	CExecOrderResource(void);
	virtual ~CExecOrderResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CExecOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CExecOrderFactory
	///@return	该CExecOrderFactory
	CExecOrderFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CExecOrderFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CExecOrderResource *alloc(int type, CExecOrderFactory *pFactory, CExecOrder *pObject, CWriteableExecOrder *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CExecOrderFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableExecOrder writeableObject;
	
	static CMemoryStack<CExecOrderResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureResource是一个说明在CUniPressureFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureResource : public CDatabaseResource
{
public:
	///构造方法
	CUniPressureResource(void);
	virtual ~CUniPressureResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CUniPressureFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CUniPressureFactory
	///@return	该CUniPressureFactory
	CUniPressureFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CUniPressureFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CUniPressureResource *alloc(int type, CUniPressureFactory *pFactory, CUniPressure *pObject, CWriteableUniPressure *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CUniPressureFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableUniPressure writeableObject;
	
	static CMemoryStack<CUniPressureResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitResource是一个说明在CBasePriceLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CBasePriceLimitResource(void);
	virtual ~CBasePriceLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CBasePriceLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CBasePriceLimitFactory
	///@return	该CBasePriceLimitFactory
	CBasePriceLimitFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CBasePriceLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CBasePriceLimitResource *alloc(int type, CBasePriceLimitFactory *pFactory, CBasePriceLimit *pObject, CWriteableBasePriceLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CBasePriceLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableBasePriceLimit writeableObject;
	
	static CMemoryStack<CBasePriceLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitResource是一个说明在CCreditLimitFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitResource : public CDatabaseResource
{
public:
	///构造方法
	CCreditLimitResource(void);
	virtual ~CCreditLimitResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCreditLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCreditLimitFactory
	///@return	该CCreditLimitFactory
	CCreditLimitFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCreditLimitFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCreditLimitResource *alloc(int type, CCreditLimitFactory *pFactory, CCreditLimit *pObject, CWriteableCreditLimit *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCreditLimitFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCreditLimit writeableObject;
	
	static CMemoryStack<CCreditLimitResource> resourceList;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionResource是一个说明在CCurrInstrumentOptionFactory中使用事务管理的原子资源
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionResource : public CDatabaseResource
{
public:
	///构造方法
	CCurrInstrumentOptionResource(void);
	virtual ~CCurrInstrumentOptionResource(void);

	///初始化
	///@param	type	资源类型，应当是CREATE_ACTION、DELETE_ACTION或UPDATE_ACTION
	///@param	pFactory	本资源所在的CCurrInstrumentOptionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
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

	///释放自己
	virtual void free(void);

	///获取本资源所在的CCurrInstrumentOptionFactory
	///@return	该CCurrInstrumentOptionFactory
	CCurrInstrumentOptionFactory *getFactory(void)
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
	///@param	pFactory	本资源所在的CCurrInstrumentOptionFactory
	///@param	pObject	本资源的地址
	///@param	pWriteableObject	新的对象值，当type为UPDATE_ACTION时有效，在目前的实现中没有用处
	///@param	updateIndex	是否更新索引
	///@return	返回一个有指定内容的资源
	static CCurrInstrumentOptionResource *alloc(int type, CCurrInstrumentOptionFactory *pFactory, CCurrInstrumentOption *pObject, CWriteableCurrInstrumentOption *pWriteableObject, bool updateIndex=true);
private:
	///存放本资源所在的对象工厂
	CCurrInstrumentOptionFactory *pFactory;
	
	///存放本资源修改前的值，当type为CREATE_ACTION和DELETE_ACTION时，本项无意义
	CWriteableCurrInstrumentOption writeableObject;
	
	static CMemoryStack<CCurrInstrumentOptionResource> resourceList;
};

#endif
