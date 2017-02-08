/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseIterators.h
///@brief定义了若干个内存数据库的iterator
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEITERATORS_H
#define DATABASEITERATORS_H

#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "MemoryStack.h"


/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusIteratorStartBySettlementGroupID是一个对结算组数据同步状态使用StartBySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusIteratorStartBySettlementGroupID: public CSGDataSyncStatusIterator
{
	friend class CSGDataSyncStatusFactory;
private:
	///检查此对象是否满足条件
	///@param	pSGDataSyncStatus		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSGDataSyncStatus *pSGDataSyncStatus);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableSGDataSyncStatus m_compareObject;
	
	static CMemoryStack<CSGDataSyncStatusIteratorStartBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CSGDataSyncStatusIteratorStartBySettlementGroupID(CSGDataSyncStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CSGDataSyncStatusIteratorStartBySettlementGroupID *alloc(CSGDataSyncStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CSGDataSyncStatusIteratorStartBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CSGDataSyncStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSGDataSyncStatusIteratorStartBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSGDataSyncStatus，必须在startFindStartBySettlementGroupID以后，endFindStartBySettlementGroupID之前叫用
	///@return	下一个满足条件CSGDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSGDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pStartBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};






/////////////////////////////////////////////////////////////////////////
///CMarketProductIteratorByProductID是一个对市场产品关联使用ByProductID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductIteratorByProductID: public CMarketProductIterator
{
	friend class CMarketProductFactory;
private:
	///检查此对象是否满足条件
	///@param	pMarketProduct		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMarketProduct *pMarketProduct);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMarketProduct m_compareObject;
	
	static CMemoryStack<CMarketProductIteratorByProductID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ProductID	产品代码
	CMarketProductIteratorByProductID(CMarketProductFactory *pFactory
		,const CReadOnlyProductIDType& ProductID)
	{
		init(pFactory,ProductID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ProductID	产品代码
	static CMarketProductIteratorByProductID *alloc(CMarketProductFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///构造方法
	CMarketProductIteratorByProductID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ProductID	产品代码
	void init(CMarketProductFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketProductIteratorByProductID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMarketProduct，必须在startFindByProductID以后，endFindByProductID之前叫用
	///@return	下一个满足条件CMarketProduct，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProduct *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByProductID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProduct * pByProductID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupIteratorByProductGroupID是一个对市场产品组关联使用ByProductGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupIteratorByProductGroupID: public CMarketProductGroupIterator
{
	friend class CMarketProductGroupFactory;
private:
	///检查此对象是否满足条件
	///@param	pMarketProductGroup		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMarketProductGroup *pMarketProductGroup);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMarketProductGroup m_compareObject;
	
	static CMemoryStack<CMarketProductGroupIteratorByProductGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组代码
	CMarketProductGroupIteratorByProductGroupID(CMarketProductGroupFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID)
	{
		init(pFactory,ProductGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组代码
	static CMarketProductGroupIteratorByProductGroupID *alloc(CMarketProductGroupFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///构造方法
	CMarketProductGroupIteratorByProductGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组代码
	void init(CMarketProductGroupFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketProductGroupIteratorByProductGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMarketProductGroup，必须在startFindByProductGroupID以后，endFindByProductGroupID之前叫用
	///@return	下一个满足条件CMarketProductGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProductGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByProductGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pByProductGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicIteratorByMarketID是一个对行情主题使用ByMarketID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicIteratorByMarketID: public CMarketDataTopicIterator
{
	friend class CMarketDataTopicFactory;
private:
	///检查此对象是否满足条件
	///@param	pMarketDataTopic		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMarketDataTopic *pMarketDataTopic);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMarketDataTopic m_compareObject;
	
	static CMemoryStack<CMarketDataTopicIteratorByMarketID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MarketID	市场代码
	CMarketDataTopicIteratorByMarketID(CMarketDataTopicFactory *pFactory
		,const CReadOnlyMarketIDType& MarketID)
	{
		init(pFactory,MarketID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MarketID	市场代码
	static CMarketDataTopicIteratorByMarketID *alloc(CMarketDataTopicFactory *pFactory
		,const CReadOnlyMarketIDType& MarketID);

	///构造方法
	CMarketDataTopicIteratorByMarketID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MarketID	市场代码
	void init(CMarketDataTopicFactory *pFactory
		,const CReadOnlyMarketIDType& MarketID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataTopicIteratorByMarketID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMarketDataTopic，必须在startFindByMarketID以后，endFindByMarketID之前叫用
	///@return	下一个满足条件CMarketDataTopic，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataTopic *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByMarketID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pByMarketID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeIteratorByPartID是一个对会员订阅市场使用ByPartID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeIteratorByPartID: public CPartTopicSubscribeIterator
{
	friend class CPartTopicSubscribeFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartTopicSubscribe		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartTopicSubscribe *pPartTopicSubscribe);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartTopicSubscribe m_compareObject;
	
	static CMemoryStack<CPartTopicSubscribeIteratorByPartID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员代码
	CPartTopicSubscribeIteratorByPartID(CPartTopicSubscribeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员代码
	static CPartTopicSubscribeIteratorByPartID *alloc(CPartTopicSubscribeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CPartTopicSubscribeIteratorByPartID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员代码
	void init(CPartTopicSubscribeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartTopicSubscribeIteratorByPartID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartTopicSubscribe，必须在startFindByPartID以后，endFindByPartID之前叫用
	///@return	下一个满足条件CPartTopicSubscribe，如果已经没有一个满足要求了，则返回NULL
	virtual CPartTopicSubscribe *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByPartID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pByPartID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantIteratorStartByParticipantID是一个对会员使用StartByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantIteratorStartByParticipantID: public CParticipantIterator
{
	friend class CParticipantFactory;
private:
	///检查此对象是否满足条件
	///@param	pParticipant		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CParticipant *pParticipant);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableParticipant m_compareObject;
	
	static CMemoryStack<CParticipantIteratorStartByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	CParticipantIteratorStartByParticipantID(CParticipantFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	static CParticipantIteratorStartByParticipantID *alloc(CParticipantFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CParticipantIteratorStartByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	void init(CParticipantFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CParticipantIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CParticipant，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CParticipant，如果已经没有一个满足要求了，则返回NULL
	virtual CParticipant *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableParticipant * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserIteratorStartByUserID是一个对用户使用StartByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIteratorStartByUserID: public CUserIterator
{
	friend class CUserFactory;
private:
	///检查此对象是否满足条件
	///@param	pUser		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CUser *pUser);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableUser m_compareObject;
	
	static CMemoryStack<CUserIteratorStartByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户编号
	CUserIteratorStartByUserID(CUserFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户编号
	static CUserIteratorStartByUserID *alloc(CUserFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///构造方法
	CUserIteratorStartByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户编号
	void init(CUserFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///析构方法，将负责释放所占用的空间
	virtual ~CUserIteratorStartByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CUser，必须在startFindStartByUserID以后，endFindStartByUserID之前叫用
	///@return	下一个满足条件CUser，如果已经没有一个满足要求了，则返回NULL
	virtual CUser *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUser * pStartByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserIPIteratorByUserID是一个对交易员IP地址使用ByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPIteratorByUserID: public CUserIPIterator
{
	friend class CUserIPFactory;
private:
	///检查此对象是否满足条件
	///@param	pUserIP		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CUserIP *pUserIP);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableUserIP m_compareObject;
	
	static CMemoryStack<CUserIPIteratorByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户编号
	CUserIPIteratorByUserID(CUserIPFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户编号
	static CUserIPIteratorByUserID *alloc(CUserIPFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///构造方法
	CUserIPIteratorByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户编号
	void init(CUserIPFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///析构方法，将负责释放所占用的空间
	virtual ~CUserIPIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CUserIP，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CUserIP，如果已经没有一个满足要求了，则返回NULL
	virtual CUserIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserIP * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientIteratorStartByParticipant是一个对会员客户关系使用StartByParticipant方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientIteratorStartByParticipant: public CPartClientIterator
{
	friend class CPartClientFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartClient		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartClient *pPartClient);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartClient m_compareObject;
	
	static CMemoryStack<CPartClientIteratorStartByParticipant> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CPartClientIteratorStartByParticipant(CPartClientFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CPartClientIteratorStartByParticipant *alloc(CPartClientFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CPartClientIteratorStartByParticipant(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CPartClientFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientIteratorStartByParticipant(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartClient，必须在startFindStartByParticipant以后，endFindStartByParticipant之前叫用
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient * pStartByParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartClientIteratorStartByClient是一个对会员客户关系使用StartByClient方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientIteratorStartByClient: public CPartClientIterator
{
	friend class CPartClientFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartClient		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartClient *pPartClient);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartClient m_compareObject;
	
	static CMemoryStack<CPartClientIteratorStartByClient> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	CPartClientIteratorStartByClient(CPartClientFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	static CPartClientIteratorStartByClient *alloc(CPartClientFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///构造方法
	CPartClientIteratorStartByClient(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	void init(CPartClientFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientIteratorStartByClient(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartClient，必须在startFindStartByClient以后，endFindStartByClient之前叫用
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient * pStartByClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};




/////////////////////////////////////////////////////////////////////////
///CAccountIteratorStartByParticipantID是一个对资金账户使用StartByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountIteratorStartByParticipantID: public CAccountIterator
{
	friend class CAccountFactory;
private:
	///检查此对象是否满足条件
	///@param	pAccount		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CAccount *pAccount);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableAccount m_compareObject;
	
	static CMemoryStack<CAccountIteratorStartByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	CAccountIteratorStartByParticipantID(CAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	static CAccountIteratorStartByParticipantID *alloc(CAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CAccountIteratorStartByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	void init(CAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CAccountIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CAccount，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAccount * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataLogIteratorByMarketDataLogNo是一个对行情流水使用ByMarketDataLogNo方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogIteratorByMarketDataLogNo: public CMarketDataLogIterator
{
	friend class CMarketDataLogFactory;
private:
	///检查此对象是否满足条件
	///@param	pMarketDataLog		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMarketDataLog *pMarketDataLog);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMarketDataLog m_compareObject;
	
	static CMemoryStack<CMarketDataLogIteratorByMarketDataLogNo> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MarketDataLogNo	行情流水编号
	CMarketDataLogIteratorByMarketDataLogNo(CMarketDataLogFactory *pFactory
		,const CReadOnlySequenceNoType& MarketDataLogNo)
	{
		init(pFactory,MarketDataLogNo);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MarketDataLogNo	行情流水编号
	static CMarketDataLogIteratorByMarketDataLogNo *alloc(CMarketDataLogFactory *pFactory
		,const CReadOnlySequenceNoType& MarketDataLogNo);

	///构造方法
	CMarketDataLogIteratorByMarketDataLogNo(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MarketDataLogNo	行情流水编号
	void init(CMarketDataLogFactory *pFactory
		,const CReadOnlySequenceNoType& MarketDataLogNo);

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataLogIteratorByMarketDataLogNo(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMarketDataLog，必须在startFindByMarketDataLogNo以后，endFindByMarketDataLogNo之前叫用
	///@return	下一个满足条件CMarketDataLog，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataLog *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByMarketDataLogNo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataLog * pByMarketDataLogNo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionIteratorByFrontID是一个对交易员在线会话使用ByFrontID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionIteratorByFrontID: public CUserSessionIterator
{
	friend class CUserSessionFactory;
private:
	///检查此对象是否满足条件
	///@param	pUserSession		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CUserSession *pUserSession);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableUserSession m_compareObject;
	
	static CMemoryStack<CUserSessionIteratorByFrontID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	FrontID	前置编号
	CUserSessionIteratorByFrontID(CUserSessionFactory *pFactory
		,const CReadOnlyFrontIDType& FrontID)
	{
		init(pFactory,FrontID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	FrontID	前置编号
	static CUserSessionIteratorByFrontID *alloc(CUserSessionFactory *pFactory
		,const CReadOnlyFrontIDType& FrontID);

	///构造方法
	CUserSessionIteratorByFrontID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	FrontID	前置编号
	void init(CUserSessionFactory *pFactory
		,const CReadOnlyFrontIDType& FrontID);

	///析构方法，将负责释放所占用的空间
	virtual ~CUserSessionIteratorByFrontID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CUserSession，必须在startFindByFrontID以后，endFindByFrontID之前叫用
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	virtual CUserSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByFrontID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserSession * pByFrontID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CUserSessionIteratorStartByUserID是一个对交易员在线会话使用StartByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionIteratorStartByUserID: public CUserSessionIterator
{
	friend class CUserSessionFactory;
private:
	///检查此对象是否满足条件
	///@param	pUserSession		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CUserSession *pUserSession);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableUserSession m_compareObject;
	
	static CMemoryStack<CUserSessionIteratorStartByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户号
	CUserSessionIteratorStartByUserID(CUserSessionFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户号
	static CUserSessionIteratorStartByUserID *alloc(CUserSessionFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///构造方法
	CUserSessionIteratorStartByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户号
	void init(CUserSessionFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///析构方法，将负责释放所占用的空间
	virtual ~CUserSessionIteratorStartByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CUserSession，必须在startFindStartByUserID以后，endFindStartByUserID之前叫用
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	virtual CUserSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserSession * pStartByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};







/////////////////////////////////////////////////////////////////////////
///CBulletinIteratorStartByBulletinID是一个对公告信息使用StartByBulletinID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinIteratorStartByBulletinID: public CBulletinIterator
{
	friend class CBulletinFactory;
private:
	///检查此对象是否满足条件
	///@param	pBulletin		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CBulletin *pBulletin);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableBulletin m_compareObject;
	
	static CMemoryStack<CBulletinIteratorStartByBulletinID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	BulletinID	公告编号
	CBulletinIteratorStartByBulletinID(CBulletinFactory *pFactory
		,const CReadOnlyBulletinIDType& BulletinID)
	{
		init(pFactory,BulletinID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	BulletinID	公告编号
	static CBulletinIteratorStartByBulletinID *alloc(CBulletinFactory *pFactory
		,const CReadOnlyBulletinIDType& BulletinID);

	///构造方法
	CBulletinIteratorStartByBulletinID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	BulletinID	公告编号
	void init(CBulletinFactory *pFactory
		,const CReadOnlyBulletinIDType& BulletinID);

	///析构方法，将负责释放所占用的空间
	virtual ~CBulletinIteratorStartByBulletinID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CBulletin，必须在startFindStartByBulletinID以后，endFindStartByBulletinID之前叫用
	///@return	下一个满足条件CBulletin，如果已经没有一个满足要求了，则返回NULL
	virtual CBulletin *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByBulletinID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBulletin * pStartByBulletinID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyIteratorBySettlementGroupID是一个对行情变动使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyIteratorBySettlementGroupID: public CMarketDataModifyIterator
{
	friend class CMarketDataModifyFactory;
private:
	///检查此对象是否满足条件
	///@param	pMarketDataModify		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMarketDataModify *pMarketDataModify);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CMarketDataModify *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CMarketDataModify *m_pNext;

	///用于存储查询参数的对象
	CWriteableMarketDataModify m_compareObject;
	
	static CMemoryStack<CMarketDataModifyIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CMarketDataModifyIteratorBySettlementGroupID(CMarketDataModifyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CMarketDataModifyIteratorBySettlementGroupID *alloc(CMarketDataModifyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CMarketDataModifyIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CMarketDataModifyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataModifyIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMarketDataModify，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CMarketDataModify，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataModify *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataModify * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataIteratorBySettlementGroupID是一个对深度行情使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataIteratorBySettlementGroupID: public CDepthMarketDataIterator
{
	friend class CDepthMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pDepthMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CDepthMarketData *pDepthMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CDepthMarketData *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CDepthMarketData *m_pNext;

	///用于存储查询参数的对象
	CWriteableDepthMarketData m_compareObject;
	
	static CMemoryStack<CDepthMarketDataIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CDepthMarketDataIteratorBySettlementGroupID(CDepthMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CDepthMarketDataIteratorBySettlementGroupID *alloc(CDepthMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CDepthMarketDataIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CDepthMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CDepthMarketDataIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CDepthMarketData，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CDepthMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketData * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIteratorByTopicID是一个对分主题行情使用ByTopicID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIteratorByTopicID: public CTopicMarketDataIterator
{
	friend class CTopicMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pTopicMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTopicMarketData *pTopicMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTopicMarketData m_compareObject;
	
	static CMemoryStack<CTopicMarketDataIteratorByTopicID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	TopicID	主题代码
	CTopicMarketDataIteratorByTopicID(CTopicMarketDataFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID)
	{
		init(pFactory,TopicID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	TopicID	主题代码
	static CTopicMarketDataIteratorByTopicID *alloc(CTopicMarketDataFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID);

	///构造方法
	CTopicMarketDataIteratorByTopicID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	TopicID	主题代码
	void init(CTopicMarketDataFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataIteratorByTopicID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTopicMarketData，必须在startFindByTopicID以后，endFindByTopicID之前叫用
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTopicID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketData * pByTopicID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIteratorByInstrumentID是一个对分主题行情使用ByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIteratorByInstrumentID: public CTopicMarketDataIterator
{
	friend class CTopicMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pTopicMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTopicMarketData *pTopicMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTopicMarketData m_compareObject;
	
	static CMemoryStack<CTopicMarketDataIteratorByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	CTopicMarketDataIteratorByInstrumentID(CTopicMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	static CTopicMarketDataIteratorByInstrumentID *alloc(CTopicMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CTopicMarketDataIteratorByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	void init(CTopicMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTopicMarketData，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketData * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIteratorBySettlementGroupID是一个对分主题行情使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIteratorBySettlementGroupID: public CTopicMarketDataIterator
{
	friend class CTopicMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pTopicMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTopicMarketData *pTopicMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CTopicMarketData *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CTopicMarketData *m_pNext;

	///用于存储查询参数的对象
	CWriteableTopicMarketData m_compareObject;
	
	static CMemoryStack<CTopicMarketDataIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CTopicMarketDataIteratorBySettlementGroupID(CTopicMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CTopicMarketDataIteratorBySettlementGroupID *alloc(CTopicMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CTopicMarketDataIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CTopicMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTopicMarketData，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketData * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionIteratorByTopicAndVersion是一个对分主题行情快照使用ByTopicAndVersion方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionIteratorByTopicAndVersion: public CTopicMarketDataVersionIterator
{
	friend class CTopicMarketDataVersionFactory;
private:
	///检查此对象是否满足条件
	///@param	pTopicMarketDataVersion		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTopicMarketDataVersion *pTopicMarketDataVersion);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTopicMarketDataVersion m_compareObject;
	
	static CMemoryStack<CTopicMarketDataVersionIteratorByTopicAndVersion> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	TopicID	主题代码
	///@param	Version	快照版本
	CTopicMarketDataVersionIteratorByTopicAndVersion(CTopicMarketDataVersionFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID,const CReadOnlySequenceNoType& Version)
	{
		init(pFactory,TopicID,Version);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	TopicID	主题代码
	///@param	Version	快照版本
	static CTopicMarketDataVersionIteratorByTopicAndVersion *alloc(CTopicMarketDataVersionFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID,const CReadOnlySequenceNoType& Version);

	///构造方法
	CTopicMarketDataVersionIteratorByTopicAndVersion(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	TopicID	主题代码
	///@param	Version	快照版本
	void init(CTopicMarketDataVersionFactory *pFactory
		,const CReadOnlyTopicIDType& TopicID,const CReadOnlySequenceNoType& Version);

	///析构方法，将负责释放所占用的空间
	virtual ~CTopicMarketDataVersionIteratorByTopicAndVersion(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTopicMarketDataVersion，必须在startFindByTopicAndVersion以后，endFindByTopicAndVersion之前叫用
	///@return	下一个满足条件CTopicMarketDataVersion，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTopicAndVersion 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pByTopicAndVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInformationIteratorByInformationID是一个对信息使用ByInformationID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationIteratorByInformationID: public CInformationIterator
{
	friend class CInformationFactory;
private:
	///检查此对象是否满足条件
	///@param	pInformation		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInformation *pInformation);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableInformation m_compareObject;
	
	static CMemoryStack<CInformationIteratorByInformationID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InformationID	消息编号
	CInformationIteratorByInformationID(CInformationFactory *pFactory
		,const CReadOnlyInformationIDType& InformationID)
	{
		init(pFactory,InformationID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InformationID	消息编号
	static CInformationIteratorByInformationID *alloc(CInformationFactory *pFactory
		,const CReadOnlyInformationIDType& InformationID);

	///构造方法
	CInformationIteratorByInformationID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InformationID	消息编号
	void init(CInformationFactory *pFactory
		,const CReadOnlyInformationIDType& InformationID);

	///析构方法，将负责释放所占用的空间
	virtual ~CInformationIteratorByInformationID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInformation，必须在startFindByInformationID以后，endFindByInformationID之前叫用
	///@return	下一个满足条件CInformation，如果已经没有一个满足要求了，则返回NULL
	virtual CInformation *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByInformationID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInformation * pByInformationID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorStartByInstrumentID是一个对合约使用StartByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorStartByInstrumentID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrument		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrument *pInstrument);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorStartByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	CInstrumentIteratorStartByInstrumentID(CInstrumentFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	static CInstrumentIteratorStartByInstrumentID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CInstrumentIteratorStartByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrument，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorBySettlementGroupID是一个对合约使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorBySettlementGroupID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrument		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrument *pInstrument);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CInstrument *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CInstrument *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CInstrumentIteratorBySettlementGroupID(CInstrumentFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CInstrumentIteratorBySettlementGroupID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CInstrumentIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CInstrumentFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrument，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByProductID是一个对合约使用ByProductID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByProductID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrument		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrument *pInstrument);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByProductID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ProductID	产品编号
	CInstrumentIteratorByProductID(CInstrumentFactory *pFactory
		,const CReadOnlyProductIDType& ProductID)
	{
		init(pFactory,ProductID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ProductID	产品编号
	static CInstrumentIteratorByProductID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///构造方法
	CInstrumentIteratorByProductID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ProductID	产品编号
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductIDType& ProductID);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentIteratorByProductID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrument，必须在startFindByProductID以后，endFindByProductID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByProductID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pByProductID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByProductGroupID是一个对合约使用ByProductGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByProductGroupID: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrument		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrument *pInstrument);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByProductGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	CInstrumentIteratorByProductGroupID(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID)
	{
		init(pFactory,ProductGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	static CInstrumentIteratorByProductGroupID *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///构造方法
	CInstrumentIteratorByProductGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentIteratorByProductGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrument，必须在startFindByProductGroupID以后，endFindByProductGroupID之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByProductGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pByProductGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByDeliveryMonth是一个对合约使用ByDeliveryMonth方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByDeliveryMonth: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrument		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrument *pInstrument);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByDeliveryMonth> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	CInstrumentIteratorByDeliveryMonth(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth)
	{
		init(pFactory,ProductGroupID,DeliveryYear,DeliveryMonth);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	static CInstrumentIteratorByDeliveryMonth *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///构造方法
	CInstrumentIteratorByDeliveryMonth(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentIteratorByDeliveryMonth(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrument，必须在startFindByDeliveryMonth以后，endFindByDeliveryMonth之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDeliveryMonth 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pByDeliveryMonth,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentIteratorByRevDeliveryMonth是一个对合约使用ByRevDeliveryMonth方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIteratorByRevDeliveryMonth: public CInstrumentIterator
{
	friend class CInstrumentFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrument		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrument *pInstrument);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrument m_compareObject;
	
	static CMemoryStack<CInstrumentIteratorByRevDeliveryMonth> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	CInstrumentIteratorByRevDeliveryMonth(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth)
	{
		init(pFactory,ProductGroupID,DeliveryYear,DeliveryMonth);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	static CInstrumentIteratorByRevDeliveryMonth *alloc(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///构造方法
	CInstrumentIteratorByRevDeliveryMonth(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ProductGroupID	产品组编号
	///@param	DeliveryYear	交割年份
	///@param	DeliveryMonth	交割月份
	void init(CInstrumentFactory *pFactory
		,const CReadOnlyProductGroupIDType& ProductGroupID,const CReadOnlyYearType& DeliveryYear,const CReadOnlyMonthType& DeliveryMonth);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentIteratorByRevDeliveryMonth(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrument，必须在startFindByRevDeliveryMonth以后，endFindByRevDeliveryMonth之前叫用
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByRevDeliveryMonth 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pByRevDeliveryMonth,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegIteratorByCombination是一个对组合合约单腿使用ByCombination方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIteratorByCombination: public CCombinationLegIterator
{
	friend class CCombinationLegFactory;
private:
	///检查此对象是否满足条件
	///@param	pCombinationLeg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCombinationLeg *pCombinationLeg);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableCombinationLeg m_compareObject;
	
	static CMemoryStack<CCombinationLegIteratorByCombination> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	CombInstrumentID	组合合约代码
	CCombinationLegIteratorByCombination(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID)
	{
		init(pFactory,CombInstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	CombInstrumentID	组合合约代码
	static CCombinationLegIteratorByCombination *alloc(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID);

	///构造方法
	CCombinationLegIteratorByCombination(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	CombInstrumentID	组合合约代码
	void init(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCombinationLegIteratorByCombination(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCombinationLeg，必须在startFindByCombination以后，endFindByCombination之前叫用
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	virtual CCombinationLeg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByCombination 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombinationLeg * pByCombination,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombinationLegIteratorByLeg是一个对组合合约单腿使用ByLeg方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIteratorByLeg: public CCombinationLegIterator
{
	friend class CCombinationLegFactory;
private:
	///检查此对象是否满足条件
	///@param	pCombinationLeg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCombinationLeg *pCombinationLeg);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableCombinationLeg m_compareObject;
	
	static CMemoryStack<CCombinationLegIteratorByLeg> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	LegInstrumentID	单腿合约代码
	CCombinationLegIteratorByLeg(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& LegInstrumentID)
	{
		init(pFactory,LegInstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	LegInstrumentID	单腿合约代码
	static CCombinationLegIteratorByLeg *alloc(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& LegInstrumentID);

	///构造方法
	CCombinationLegIteratorByLeg(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	LegInstrumentID	单腿合约代码
	void init(CCombinationLegFactory *pFactory
		,const CReadOnlyInstrumentIDType& LegInstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCombinationLegIteratorByLeg(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCombinationLeg，必须在startFindByLeg以后，endFindByLeg之前叫用
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	virtual CCombinationLeg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByLeg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombinationLeg * pByLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombinationLegIteratorBySettlementGroupID是一个对组合合约单腿使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIteratorBySettlementGroupID: public CCombinationLegIterator
{
	friend class CCombinationLegFactory;
private:
	///检查此对象是否满足条件
	///@param	pCombinationLeg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCombinationLeg *pCombinationLeg);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCombinationLeg *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCombinationLeg *m_pNext;

	///用于存储查询参数的对象
	CWriteableCombinationLeg m_compareObject;
	
	static CMemoryStack<CCombinationLegIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCombinationLegIteratorBySettlementGroupID(CCombinationLegFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCombinationLegIteratorBySettlementGroupID *alloc(CCombinationLegFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCombinationLegIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCombinationLegFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCombinationLegIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCombinationLeg，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	virtual CCombinationLeg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombinationLeg * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountIteratorBySettlementGroupID是一个对会员账户关系使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountIteratorBySettlementGroupID: public CPartRoleAccountIterator
{
	friend class CPartRoleAccountFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartRoleAccount		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartRoleAccount *pPartRoleAccount);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CPartRoleAccount *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CPartRoleAccount *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartRoleAccount m_compareObject;
	
	static CMemoryStack<CPartRoleAccountIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CPartRoleAccountIteratorBySettlementGroupID(CPartRoleAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CPartRoleAccountIteratorBySettlementGroupID *alloc(CPartRoleAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CPartRoleAccountIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CPartRoleAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartRoleAccountIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartRoleAccount，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CPartRoleAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountIteratorStartByParticipantID是一个对会员账户关系使用StartByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountIteratorStartByParticipantID: public CPartRoleAccountIterator
{
	friend class CPartRoleAccountFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartRoleAccount		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartRoleAccount *pPartRoleAccount);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartRoleAccount m_compareObject;
	
	static CMemoryStack<CPartRoleAccountIteratorStartByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CPartRoleAccountIteratorStartByParticipantID(CPartRoleAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CPartRoleAccountIteratorStartByParticipantID *alloc(CPartRoleAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CPartRoleAccountIteratorStartByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CPartRoleAccountFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartRoleAccountIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartRoleAccount，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CPartRoleAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleIteratorBySettlementGroupID是一个对会员产品角色使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleIteratorBySettlementGroupID: public CPartProductRoleIterator
{
	friend class CPartProductRoleFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartProductRole		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartProductRole *pPartProductRole);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CPartProductRole *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CPartProductRole *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartProductRole m_compareObject;
	
	static CMemoryStack<CPartProductRoleIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CPartProductRoleIteratorBySettlementGroupID(CPartProductRoleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CPartProductRoleIteratorBySettlementGroupID *alloc(CPartProductRoleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CPartProductRoleIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CPartProductRoleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartProductRoleIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartProductRole，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartProductRole，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRole *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRole * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightIteratorBySettlementGroupID是一个对会员产品交易权限使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightIteratorBySettlementGroupID: public CPartProductRightIterator
{
	friend class CPartProductRightFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartProductRight		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartProductRight *pPartProductRight);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CPartProductRight *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CPartProductRight *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartProductRight m_compareObject;
	
	static CMemoryStack<CPartProductRightIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CPartProductRightIteratorBySettlementGroupID(CPartProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CPartProductRightIteratorBySettlementGroupID *alloc(CPartProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CPartProductRightIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CPartProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartProductRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartProductRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightIteratorBySettlementGroupID是一个对会员合约交易权限使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightIteratorBySettlementGroupID: public CPartInstrumentRightIterator
{
	friend class CPartInstrumentRightFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartInstrumentRight		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartInstrumentRight *pPartInstrumentRight);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CPartInstrumentRight *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CPartInstrumentRight *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartInstrumentRight m_compareObject;
	
	static CMemoryStack<CPartInstrumentRightIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CPartInstrumentRightIteratorBySettlementGroupID(CPartInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CPartInstrumentRightIteratorBySettlementGroupID *alloc(CPartInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CPartInstrumentRightIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CPartInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartInstrumentRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartInstrumentRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightIteratorBySettlementGroupID是一个对客户产品交易权限使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightIteratorBySettlementGroupID: public CClientProductRightIterator
{
	friend class CClientProductRightFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientProductRight		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientProductRight *pClientProductRight);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CClientProductRight *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CClientProductRight *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientProductRight m_compareObject;
	
	static CMemoryStack<CClientProductRightIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CClientProductRightIteratorBySettlementGroupID(CClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CClientProductRightIteratorBySettlementGroupID *alloc(CClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CClientProductRightIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientProductRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientProductRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientProductRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightIteratorBySettlementGroupID是一个对客户合约交易权限使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightIteratorBySettlementGroupID: public CClientInstrumentRightIterator
{
	friend class CClientInstrumentRightFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientInstrumentRight		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientInstrumentRight *pClientInstrumentRight);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CClientInstrumentRight *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CClientInstrumentRight *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientInstrumentRight m_compareObject;
	
	static CMemoryStack<CClientInstrumentRightIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CClientInstrumentRightIteratorBySettlementGroupID(CClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CClientInstrumentRightIteratorBySettlementGroupID *alloc(CClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CClientInstrumentRightIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientInstrumentRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientInstrumentRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightIteratorBySettlementGroupID是一个对会员客户产品交易权限使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightIteratorBySettlementGroupID: public CPartClientProductRightIterator
{
	friend class CPartClientProductRightFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartClientProductRight		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartClientProductRight *pPartClientProductRight);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CPartClientProductRight *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CPartClientProductRight *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartClientProductRight m_compareObject;
	
	static CMemoryStack<CPartClientProductRightIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CPartClientProductRightIteratorBySettlementGroupID(CPartClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CPartClientProductRightIteratorBySettlementGroupID *alloc(CPartClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CPartClientProductRightIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CPartClientProductRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientProductRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartClientProductRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightIteratorBySettlementGroupID是一个对会员客户合约交易权限使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightIteratorBySettlementGroupID: public CPartClientInstrumentRightIterator
{
	friend class CPartClientInstrumentRightFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartClientInstrumentRight		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartClientInstrumentRight *pPartClientInstrumentRight);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CPartClientInstrumentRight *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CPartClientInstrumentRight *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartClientInstrumentRight m_compareObject;
	
	static CMemoryStack<CPartClientInstrumentRightIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CPartClientInstrumentRightIteratorBySettlementGroupID(CPartClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CPartClientInstrumentRightIteratorBySettlementGroupID *alloc(CPartClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CPartClientInstrumentRightIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CPartClientInstrumentRightFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartClientInstrumentRightIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartClientInstrumentRight，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyIteratorBySettlementGroupID是一个对产品属性使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyIteratorBySettlementGroupID: public CCurrProductPropertyIterator
{
	friend class CCurrProductPropertyFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrProductProperty		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrProductProperty *pCurrProductProperty);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrProductProperty *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrProductProperty *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrProductProperty m_compareObject;
	
	static CMemoryStack<CCurrProductPropertyIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrProductPropertyIteratorBySettlementGroupID(CCurrProductPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrProductPropertyIteratorBySettlementGroupID *alloc(CCurrProductPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrProductPropertyIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrProductPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrProductPropertyIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrProductProperty，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrProductProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrProductProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyIteratorBySettlementGroupID是一个对合约属性使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyIteratorBySettlementGroupID: public CCurrInstrumentPropertyIterator
{
	friend class CCurrInstrumentPropertyFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrInstrumentProperty		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrInstrumentProperty *pCurrInstrumentProperty);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrInstrumentProperty *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrInstrumentProperty *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrInstrumentProperty m_compareObject;
	
	static CMemoryStack<CCurrInstrumentPropertyIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrInstrumentPropertyIteratorBySettlementGroupID(CCurrInstrumentPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrInstrumentPropertyIteratorBySettlementGroupID *alloc(CCurrInstrumentPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrInstrumentPropertyIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrInstrumentPropertyFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrInstrumentPropertyIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrInstrumentProperty，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrInstrumentProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingIteratorBySettlementGroupID是一个对当前价格绑定使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingIteratorBySettlementGroupID: public CCurrPriceBandingIterator
{
	friend class CCurrPriceBandingFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrPriceBanding		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrPriceBanding *pCurrPriceBanding);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrPriceBanding *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrPriceBanding *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrPriceBanding m_compareObject;
	
	static CMemoryStack<CCurrPriceBandingIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrPriceBandingIteratorBySettlementGroupID(CCurrPriceBandingFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrPriceBandingIteratorBySettlementGroupID *alloc(CCurrPriceBandingFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrPriceBandingIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrPriceBandingFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPriceBandingIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrPriceBanding，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrPriceBanding，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPriceBanding *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateIteratorBySettlementGroupID是一个对当天合约保证金率使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateIteratorBySettlementGroupID: public CCurrMarginRateIterator
{
	friend class CCurrMarginRateFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrMarginRate		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrMarginRate *pCurrMarginRate);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrMarginRate *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrMarginRate *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrMarginRate m_compareObject;
	
	static CMemoryStack<CCurrMarginRateIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrMarginRateIteratorBySettlementGroupID(CCurrMarginRateFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrMarginRateIteratorBySettlementGroupID *alloc(CCurrMarginRateFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrMarginRateIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrMarginRateFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrMarginRateIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrMarginRate，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailIteratorBySettlementGroupID是一个对当天合约保证金率的详细内容使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailIteratorBySettlementGroupID: public CCurrMarginRateDetailIterator
{
	friend class CCurrMarginRateDetailFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrMarginRateDetail		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrMarginRateDetail *pCurrMarginRateDetail);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrMarginRateDetail *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrMarginRateDetail *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrMarginRateDetail m_compareObject;
	
	static CMemoryStack<CCurrMarginRateDetailIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrMarginRateDetailIteratorBySettlementGroupID(CCurrMarginRateDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrMarginRateDetailIteratorBySettlementGroupID *alloc(CCurrMarginRateDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrMarginRateDetailIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrMarginRateDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrMarginRateDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrMarginRateDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrMarginRateDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitIteratorBySettlementGroupID是一个对当前会员合约限仓使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitIteratorBySettlementGroupID: public CCurrPartPosiLimitIterator
{
	friend class CCurrPartPosiLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrPartPosiLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrPartPosiLimit *pCurrPartPosiLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrPartPosiLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrPartPosiLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrPartPosiLimit m_compareObject;
	
	static CMemoryStack<CCurrPartPosiLimitIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrPartPosiLimitIteratorBySettlementGroupID(CCurrPartPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrPartPosiLimitIteratorBySettlementGroupID *alloc(CCurrPartPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrPartPosiLimitIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrPartPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPartPosiLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrPartPosiLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailIteratorBySettlementGroupID是一个对当前会员合约限仓的详细内容使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailIteratorBySettlementGroupID: public CCurrPartPosiLimitDetailIterator
{
	friend class CCurrPartPosiLimitDetailFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrPartPosiLimitDetail		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrPartPosiLimitDetail *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrPartPosiLimitDetail *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrPartPosiLimitDetail m_compareObject;
	
	static CMemoryStack<CCurrPartPosiLimitDetailIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrPartPosiLimitDetailIteratorBySettlementGroupID(CCurrPartPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrPartPosiLimitDetailIteratorBySettlementGroupID *alloc(CCurrPartPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrPartPosiLimitDetailIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrPartPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrPartPosiLimitDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrPartPosiLimitDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrPartPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitIteratorBySettlementGroupID是一个对当前客户合约限仓使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitIteratorBySettlementGroupID: public CCurrClientPosiLimitIterator
{
	friend class CCurrClientPosiLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrClientPosiLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrClientPosiLimit *pCurrClientPosiLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrClientPosiLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrClientPosiLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrClientPosiLimit m_compareObject;
	
	static CMemoryStack<CCurrClientPosiLimitIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrClientPosiLimitIteratorBySettlementGroupID(CCurrClientPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrClientPosiLimitIteratorBySettlementGroupID *alloc(CCurrClientPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrClientPosiLimitIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrClientPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrClientPosiLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrClientPosiLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailIteratorBySettlementGroupID是一个对当前客户合约限仓的详细内容使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailIteratorBySettlementGroupID: public CCurrClientPosiLimitDetailIterator
{
	friend class CCurrClientPosiLimitDetailFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrClientPosiLimitDetail		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrClientPosiLimitDetail *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrClientPosiLimitDetail *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrClientPosiLimitDetail m_compareObject;
	
	static CMemoryStack<CCurrClientPosiLimitDetailIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrClientPosiLimitDetailIteratorBySettlementGroupID(CCurrClientPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrClientPosiLimitDetailIteratorBySettlementGroupID *alloc(CCurrClientPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrClientPosiLimitDetailIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrClientPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrClientPosiLimitDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrClientPosiLimitDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrClientPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitIteratorBySettlementGroupID是一个对当前特殊客户合约限仓使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitIteratorBySettlementGroupID: public CCurrSpecialPosiLimitIterator
{
	friend class CCurrSpecialPosiLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrSpecialPosiLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrSpecialPosiLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrSpecialPosiLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrSpecialPosiLimit m_compareObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrSpecialPosiLimitIteratorBySettlementGroupID(CCurrSpecialPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrSpecialPosiLimitIteratorBySettlementGroupID *alloc(CCurrSpecialPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrSpecialPosiLimitIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrSpecialPosiLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrSpecialPosiLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrSpecialPosiLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID是一个对当前特殊客户合约限仓的详细内容使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID: public CCurrSpecialPosiLimitDetailIterator
{
	friend class CCurrSpecialPosiLimitDetailFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrSpecialPosiLimitDetail		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrSpecialPosiLimitDetail *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrSpecialPosiLimitDetail *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrSpecialPosiLimitDetail m_compareObject;
	
	static CMemoryStack<CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID(CCurrSpecialPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID *alloc(CCurrSpecialPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrSpecialPosiLimitDetailFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrSpecialPosiLimitDetail，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrSpecialPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleIteratorBySettlementGroupID是一个对当前合约套期保值属性使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleIteratorBySettlementGroupID: public CCurrHedgeRuleIterator
{
	friend class CCurrHedgeRuleFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrHedgeRule		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrHedgeRule *pCurrHedgeRule);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrHedgeRule *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrHedgeRule *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrHedgeRule m_compareObject;
	
	static CMemoryStack<CCurrHedgeRuleIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrHedgeRuleIteratorBySettlementGroupID(CCurrHedgeRuleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrHedgeRuleIteratorBySettlementGroupID *alloc(CCurrHedgeRuleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrHedgeRuleIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrHedgeRuleFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrHedgeRuleIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrHedgeRule，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrHedgeRule，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrHedgeRule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIteratorBySettlementGroupID是一个对当前合约交易阶段属性使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIteratorBySettlementGroupID: public CCurrTradingSegmentAttrIterator
{
	friend class CCurrTradingSegmentAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrTradingSegmentAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrTradingSegmentAttr *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrTradingSegmentAttr *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrTradingSegmentAttrIteratorBySettlementGroupID(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrTradingSegmentAttrIteratorBySettlementGroupID *alloc(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrTradingSegmentAttrIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrTradingSegmentAttrIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrTradingSegmentAttr，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIteratorByTime是一个对当前合约交易阶段属性使用ByTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIteratorByTime: public CCurrTradingSegmentAttrIterator
{
	friend class CCurrTradingSegmentAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrTradingSegmentAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrIteratorByTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	StartTime	起始时间
	CCurrTradingSegmentAttrIteratorByTime(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime)
	{
		init(pFactory,StartTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	StartTime	起始时间
	static CCurrTradingSegmentAttrIteratorByTime *alloc(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///构造方法
	CCurrTradingSegmentAttrIteratorByTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	StartTime	起始时间
	void init(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrTradingSegmentAttrIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrTradingSegmentAttr，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIteratorByInstrument是一个对当前合约交易阶段属性使用ByInstrument方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIteratorByInstrument: public CCurrTradingSegmentAttrIterator
{
	friend class CCurrTradingSegmentAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrTradingSegmentAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CCurrTradingSegmentAttrIteratorByInstrument> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约编号
	CCurrTradingSegmentAttrIteratorByInstrument(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约编号
	static CCurrTradingSegmentAttrIteratorByInstrument *alloc(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CCurrTradingSegmentAttrIteratorByInstrument(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约编号
	void init(CCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrTradingSegmentAttrIteratorByInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrTradingSegmentAttr，必须在startFindByInstrument以后，endFindByInstrument之前叫用
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pByInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseIteratorBySettlementGroupID是一个对当前合约熔断属性使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseIteratorBySettlementGroupID: public CCurrFuseIterator
{
	friend class CCurrFuseFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrFuse		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrFuse *pCurrFuse);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrFuse *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrFuse *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrFuse m_compareObject;
	
	static CMemoryStack<CCurrFuseIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrFuseIteratorBySettlementGroupID(CCurrFuseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrFuseIteratorBySettlementGroupID *alloc(CCurrFuseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrFuseIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrFuseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrFuseIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrFuse，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrFuse，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrFuse *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrFuse * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountIteratorBySettlementGroupID是一个对交易账户使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountIteratorBySettlementGroupID: public CTradingAccountIterator
{
	friend class CTradingAccountFactory;
private:
	///检查此对象是否满足条件
	///@param	pTradingAccount		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTradingAccount *pTradingAccount);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CTradingAccount *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CTradingAccount *m_pNext;

	///用于存储查询参数的对象
	CWriteableTradingAccount m_compareObject;
	
	static CMemoryStack<CTradingAccountIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CTradingAccountIteratorBySettlementGroupID(CTradingAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CTradingAccountIteratorBySettlementGroupID *alloc(CTradingAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CTradingAccountIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CTradingAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTradingAccountIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTradingAccount，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CTradingAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTradingAccount * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountIteratorBySettlementGroupID是一个对基本准备金账户使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountIteratorBySettlementGroupID: public CBaseReserveAccountIterator
{
	friend class CBaseReserveAccountFactory;
private:
	///检查此对象是否满足条件
	///@param	pBaseReserveAccount		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CBaseReserveAccount *pBaseReserveAccount);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CBaseReserveAccount *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CBaseReserveAccount *m_pNext;

	///用于存储查询参数的对象
	CWriteableBaseReserveAccount m_compareObject;
	
	static CMemoryStack<CBaseReserveAccountIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CBaseReserveAccountIteratorBySettlementGroupID(CBaseReserveAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CBaseReserveAccountIteratorBySettlementGroupID *alloc(CBaseReserveAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CBaseReserveAccountIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CBaseReserveAccountFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CBaseReserveAccountIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CBaseReserveAccount，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CBaseReserveAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CBaseReserveAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionIteratorStartByInstrument是一个对会员持仓使用StartByInstrument方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIteratorStartByInstrument: public CPartPositionIterator
{
	friend class CPartPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartPosition *pPartPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartPosition m_compareObject;
	
	static CMemoryStack<CPartPositionIteratorStartByInstrument> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	CPartPositionIteratorStartByInstrument(CPartPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	static CPartPositionIteratorStartByInstrument *alloc(CPartPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CPartPositionIteratorStartByInstrument(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	void init(CPartPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartPositionIteratorStartByInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartPosition，必须在startFindStartByInstrument以后，endFindStartByInstrument之前叫用
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartPosition * pStartByInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartPositionIteratorStartByParticipant是一个对会员持仓使用StartByParticipant方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIteratorStartByParticipant: public CPartPositionIterator
{
	friend class CPartPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartPosition *pPartPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartPosition m_compareObject;
	
	static CMemoryStack<CPartPositionIteratorStartByParticipant> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CPartPositionIteratorStartByParticipant(CPartPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CPartPositionIteratorStartByParticipant *alloc(CPartPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CPartPositionIteratorStartByParticipant(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CPartPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartPositionIteratorStartByParticipant(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartPosition，必须在startFindStartByParticipant以后，endFindStartByParticipant之前叫用
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartPosition * pStartByParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CPartPositionIteratorBySettlementGroupID是一个对会员持仓使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIteratorBySettlementGroupID: public CPartPositionIterator
{
	friend class CPartPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pPartPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CPartPosition *pPartPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CPartPosition *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CPartPosition *m_pNext;

	///用于存储查询参数的对象
	CWriteablePartPosition m_compareObject;
	
	static CMemoryStack<CPartPositionIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CPartPositionIteratorBySettlementGroupID(CPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CPartPositionIteratorBySettlementGroupID *alloc(CPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CPartPositionIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CPartPositionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CPartPosition，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartPosition * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorByClientAndInstrument是一个对客户持仓使用ByClientAndInstrument方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorByClientAndInstrument: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientPosition *pClientPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CHashIndexNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CHashIndexNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorByClientAndInstrument> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	///@param	PosiDirection	多空方向
	///@param	HedgeFlag	投保标志
	CClientPositionIteratorByClientAndInstrument(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID,const CReadOnlyPosiDirectionType& PosiDirection,const CReadOnlyHedgeFlagType& HedgeFlag)
	{
		init(pFactory,ClientID,InstrumentID,PosiDirection,HedgeFlag);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	///@param	PosiDirection	多空方向
	///@param	HedgeFlag	投保标志
	static CClientPositionIteratorByClientAndInstrument *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID,const CReadOnlyPosiDirectionType& PosiDirection,const CReadOnlyHedgeFlagType& HedgeFlag);

	///构造方法
	CClientPositionIteratorByClientAndInstrument(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	///@param	PosiDirection	多空方向
	///@param	HedgeFlag	投保标志
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID,const CReadOnlyPosiDirectionType& PosiDirection,const CReadOnlyHedgeFlagType& HedgeFlag);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionIteratorByClientAndInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientPosition，必须在startFindByClientAndInstrument以后，endFindByClientAndInstrument之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByClientAndInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pByClientAndInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorStartByParticipant是一个对客户持仓使用StartByParticipant方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorStartByParticipant: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientPosition *pClientPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorStartByParticipant> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CClientPositionIteratorStartByParticipant(CClientPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CClientPositionIteratorStartByParticipant *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CClientPositionIteratorStartByParticipant(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionIteratorStartByParticipant(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientPosition，必须在startFindStartByParticipant以后，endFindStartByParticipant之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pStartByParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorStartByClient是一个对客户持仓使用StartByClient方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorStartByClient: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientPosition *pClientPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorStartByClient> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	CClientPositionIteratorStartByClient(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	static CClientPositionIteratorStartByClient *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///构造方法
	CClientPositionIteratorStartByClient(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionIteratorStartByClient(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientPosition，必须在startFindStartByClient以后，endFindStartByClient之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pStartByClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorStartByInstrument是一个对客户持仓使用StartByInstrument方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorStartByInstrument: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientPosition *pClientPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorStartByInstrument> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	CClientPositionIteratorStartByInstrument(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	static CClientPositionIteratorStartByInstrument *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CClientPositionIteratorStartByInstrument(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionIteratorStartByInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientPosition，必须在startFindStartByInstrument以后，endFindStartByInstrument之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pStartByInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorByInstrumentID是一个对客户持仓使用ByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorByInstrumentID: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientPosition *pClientPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CClientPosition *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CClientPosition *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	CClientPositionIteratorByInstrumentID(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	static CClientPositionIteratorByInstrumentID *alloc(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CClientPositionIteratorByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	void init(CClientPositionFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientPosition，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CClientPositionIteratorBySettlementGroupID是一个对客户持仓使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIteratorBySettlementGroupID: public CClientPositionIterator
{
	friend class CClientPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pClientPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClientPosition *pClientPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CClientPosition *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CClientPosition *m_pNext;

	///用于存储查询参数的对象
	CWriteableClientPosition m_compareObject;
	
	static CMemoryStack<CClientPositionIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CClientPositionIteratorBySettlementGroupID(CClientPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CClientPositionIteratorBySettlementGroupID *alloc(CClientPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CClientPositionIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CClientPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClientPositionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClientPosition，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeIteratorBySettlementGroupID是一个对保值额度量使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeIteratorBySettlementGroupID: public CHedgeVolumeIterator
{
	friend class CHedgeVolumeFactory;
private:
	///检查此对象是否满足条件
	///@param	pHedgeVolume		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CHedgeVolume *pHedgeVolume);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CHedgeVolume *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CHedgeVolume *m_pNext;

	///用于存储查询参数的对象
	CWriteableHedgeVolume m_compareObject;
	
	static CMemoryStack<CHedgeVolumeIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CHedgeVolumeIteratorBySettlementGroupID(CHedgeVolumeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CHedgeVolumeIteratorBySettlementGroupID *alloc(CHedgeVolumeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CHedgeVolumeIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CHedgeVolumeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CHedgeVolumeIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CHedgeVolume，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	virtual CHedgeVolume *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableHedgeVolume * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeIteratorStartByPartClientAndInstrument是一个对保值额度量使用StartByPartClientAndInstrument方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeIteratorStartByPartClientAndInstrument: public CHedgeVolumeIterator
{
	friend class CHedgeVolumeFactory;
private:
	///检查此对象是否满足条件
	///@param	pHedgeVolume		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CHedgeVolume *pHedgeVolume);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableHedgeVolume m_compareObject;
	
	static CMemoryStack<CHedgeVolumeIteratorStartByPartClientAndInstrument> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	CHedgeVolumeIteratorStartByPartClientAndInstrument(CHedgeVolumeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,ParticipantID,ClientID,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	static CHedgeVolumeIteratorStartByPartClientAndInstrument *alloc(CHedgeVolumeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CHedgeVolumeIteratorStartByPartClientAndInstrument(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员编号
	///@param	ClientID	客户编号
	///@param	InstrumentID	合约代码
	void init(CHedgeVolumeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CHedgeVolumeIteratorStartByPartClientAndInstrument(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CHedgeVolume，必须在startFindStartByPartClientAndInstrument以后，endFindStartByPartClientAndInstrument之前叫用
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	virtual CHedgeVolume *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByPartClientAndInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableHedgeVolume * pStartByPartClientAndInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderIteratorBySettlementGroupID是一个对历史报单使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderIteratorBySettlementGroupID: public CRemainOrderIterator
{
	friend class CRemainOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pRemainOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRemainOrder *pRemainOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CRemainOrder *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CRemainOrder *m_pNext;

	///用于存储查询参数的对象
	CWriteableRemainOrder m_compareObject;
	
	static CMemoryStack<CRemainOrderIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CRemainOrderIteratorBySettlementGroupID(CRemainOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CRemainOrderIteratorBySettlementGroupID *alloc(CRemainOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CRemainOrderIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CRemainOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CRemainOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRemainOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CRemainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRemainOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRemainOrderIteratorByInstrumentID是一个对历史报单使用ByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderIteratorByInstrumentID: public CRemainOrderIterator
{
	friend class CRemainOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pRemainOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRemainOrder *pRemainOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableRemainOrder m_compareObject;
	
	static CMemoryStack<CRemainOrderIteratorByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约编号
	CRemainOrderIteratorByInstrumentID(CRemainOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约编号
	static CRemainOrderIteratorByInstrumentID *alloc(CRemainOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CRemainOrderIteratorByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约编号
	void init(CRemainOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CRemainOrderIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRemainOrder，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CRemainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRemainOrder * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataIteratorBySettlementGroupID是一个对行情使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataIteratorBySettlementGroupID: public CMarketDataIterator
{
	friend class CMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMarketData *pMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CMarketData *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CMarketData *m_pNext;

	///用于存储查询参数的对象
	CWriteableMarketData m_compareObject;
	
	static CMemoryStack<CMarketDataIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CMarketDataIteratorBySettlementGroupID(CMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CMarketDataIteratorBySettlementGroupID *alloc(CMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CMarketDataIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CMarketDataFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMarketDataIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMarketData，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketData * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionIteratorBySettlementGroupID是一个对结算会员持仓使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionIteratorBySettlementGroupID: public CClearingPartPositionIterator
{
	friend class CClearingPartPositionFactory;
private:
	///检查此对象是否满足条件
	///@param	pClearingPartPosition		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CClearingPartPosition *pClearingPartPosition);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CClearingPartPosition *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CClearingPartPosition *m_pNext;

	///用于存储查询参数的对象
	CWriteableClearingPartPosition m_compareObject;
	
	static CMemoryStack<CClearingPartPositionIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CClearingPartPositionIteratorBySettlementGroupID(CClearingPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CClearingPartPositionIteratorBySettlementGroupID *alloc(CClearingPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CClearingPartPositionIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CClearingPartPositionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CClearingPartPositionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CClearingPartPosition，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CClearingPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusIteratorStartByInstrumentID是一个对合约状态使用StartByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusIteratorStartByInstrumentID: public CInstrumentStatusIterator
{
	friend class CInstrumentStatusFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrumentStatus		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrumentStatus *pInstrumentStatus);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrumentStatus m_compareObject;
	
	static CMemoryStack<CInstrumentStatusIteratorStartByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	CInstrumentStatusIteratorStartByInstrumentID(CInstrumentStatusFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	static CInstrumentStatusIteratorStartByInstrumentID *alloc(CInstrumentStatusFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CInstrumentStatusIteratorStartByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	void init(CInstrumentStatusFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentStatusIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrumentStatus，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusIteratorBySettlementGroupID是一个对合约状态使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusIteratorBySettlementGroupID: public CInstrumentStatusIterator
{
	friend class CInstrumentStatusFactory;
private:
	///检查此对象是否满足条件
	///@param	pInstrumentStatus		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CInstrumentStatus *pInstrumentStatus);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CInstrumentStatus *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CInstrumentStatus *m_pNext;

	///用于存储查询参数的对象
	CWriteableInstrumentStatus m_compareObject;
	
	static CMemoryStack<CInstrumentStatusIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	CInstrumentStatusIteratorBySettlementGroupID(CInstrumentStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	static CInstrumentStatusIteratorBySettlementGroupID *alloc(CInstrumentStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CInstrumentStatusIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	void init(CInstrumentStatusFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CInstrumentStatusIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CInstrumentStatus，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderIteratorStartByParticipantID是一个对报单使用StartByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorStartByParticipantID: public COrderIterator
{
	friend class COrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(COrder *pOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorStartByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	COrderIteratorStartByParticipantID(COrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static COrderIteratorStartByParticipantID *alloc(COrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	COrderIteratorStartByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(COrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~COrderIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的COrder，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorBySettlementGroupID是一个对报单使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorBySettlementGroupID: public COrderIterator
{
	friend class COrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(COrder *pOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	COrder *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	COrder *m_pNext;

	///用于存储查询参数的对象
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	COrderIteratorBySettlementGroupID(COrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static COrderIteratorBySettlementGroupID *alloc(COrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	COrderIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(COrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~COrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的COrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorByUserID是一个对报单使用ByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorByUserID: public COrderIterator
{
	friend class COrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(COrder *pOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	COrderIteratorByUserID(COrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	static COrderIteratorByUserID *alloc(COrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///构造方法
	COrderIteratorByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	void init(COrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///析构方法，将负责释放所占用的空间
	virtual ~COrderIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的COrder，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorByInstrumentID是一个对报单使用ByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorByInstrumentID: public COrderIterator
{
	friend class COrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(COrder *pOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	COrder *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	COrder *m_pNext;

	///用于存储查询参数的对象
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	COrderIteratorByInstrumentID(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	static COrderIteratorByInstrumentID *alloc(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	COrderIteratorByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	void init(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~COrderIteratorByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的COrder，必须在startFindByInstrumentID以后，endFindByInstrumentID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///COrderIteratorStartByInstrumentID是一个对报单使用StartByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIteratorStartByInstrumentID: public COrderIterator
{
	friend class COrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(COrder *pOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableOrder m_compareObject;
	
	static CMemoryStack<COrderIteratorStartByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	COrderIteratorStartByInstrumentID(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	static COrderIteratorStartByInstrumentID *alloc(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	COrderIteratorStartByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	void init(COrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~COrderIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的COrder，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderIteratorStartByParticipantID是一个对组合报单使用StartByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIteratorStartByParticipantID: public CCombOrderIterator
{
	friend class CCombOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pCombOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCombOrder *pCombOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableCombOrder m_compareObject;
	
	static CMemoryStack<CCombOrderIteratorStartByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CCombOrderIteratorStartByParticipantID(CCombOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CCombOrderIteratorStartByParticipantID *alloc(CCombOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CCombOrderIteratorStartByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CCombOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCombOrderIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCombOrder，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CCombOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombOrder * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombOrderIteratorBySettlementGroupID是一个对组合报单使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIteratorBySettlementGroupID: public CCombOrderIterator
{
	friend class CCombOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pCombOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCombOrder *pCombOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCombOrder *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCombOrder *m_pNext;

	///用于存储查询参数的对象
	CWriteableCombOrder m_compareObject;
	
	static CMemoryStack<CCombOrderIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCombOrderIteratorBySettlementGroupID(CCombOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCombOrderIteratorBySettlementGroupID *alloc(CCombOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCombOrderIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCombOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCombOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCombOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CCombOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCombOrderIteratorByUserID是一个对组合报单使用ByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIteratorByUserID: public CCombOrderIterator
{
	friend class CCombOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pCombOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCombOrder *pCombOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableCombOrder m_compareObject;
	
	static CMemoryStack<CCombOrderIteratorByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	CCombOrderIteratorByUserID(CCombOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	static CCombOrderIteratorByUserID *alloc(CCombOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///构造方法
	CCombOrderIteratorByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	void init(CCombOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCombOrderIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCombOrder，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CCombOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombOrder * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderIteratorBySettlementGroupID是一个对OTC报单使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderIteratorBySettlementGroupID: public COTCOrderIterator
{
	friend class COTCOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pOTCOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(COTCOrder *pOTCOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	COTCOrder *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	COTCOrder *m_pNext;

	///用于存储查询参数的对象
	CWriteableOTCOrder m_compareObject;
	
	static CMemoryStack<COTCOrderIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	COTCOrderIteratorBySettlementGroupID(COTCOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static COTCOrderIteratorBySettlementGroupID *alloc(COTCOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	COTCOrderIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(COTCOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~COTCOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的COTCOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件COTCOrder，如果已经没有一个满足要求了，则返回NULL
	virtual COTCOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOTCOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderIteratorByImplyLeg是一个对隐式报单使用ByImplyLeg方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIteratorByImplyLeg: public CImplyOrderIterator
{
	friend class CImplyOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pImplyOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CImplyOrder *pImplyOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableImplyOrder m_compareObject;
	
	static CMemoryStack<CImplyOrderIteratorByImplyLeg> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	CombInstrumentID	组合报单号
	///@param	ImplyLegID	派生报单单腿编号
	///@param	Direction	派生报单买卖方向
	CImplyOrderIteratorByImplyLeg(CImplyOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID,const CReadOnlyLegIDType& ImplyLegID,const CReadOnlyDirectionType& Direction)
	{
		init(pFactory,CombInstrumentID,ImplyLegID,Direction);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	CombInstrumentID	组合报单号
	///@param	ImplyLegID	派生报单单腿编号
	///@param	Direction	派生报单买卖方向
	static CImplyOrderIteratorByImplyLeg *alloc(CImplyOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID,const CReadOnlyLegIDType& ImplyLegID,const CReadOnlyDirectionType& Direction);

	///构造方法
	CImplyOrderIteratorByImplyLeg(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	CombInstrumentID	组合报单号
	///@param	ImplyLegID	派生报单单腿编号
	///@param	Direction	派生报单买卖方向
	void init(CImplyOrderFactory *pFactory
		,const CReadOnlyInstrumentIDType& CombInstrumentID,const CReadOnlyLegIDType& ImplyLegID,const CReadOnlyDirectionType& Direction);

	///析构方法，将负责释放所占用的空间
	virtual ~CImplyOrderIteratorByImplyLeg(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CImplyOrder，必须在startFindByImplyLeg以后，endFindByImplyLeg之前叫用
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CImplyOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByImplyLeg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableImplyOrder * pByImplyLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CImplyOrderIteratorByImplyOrderAndAnchorLeg是一个对隐式报单使用ByImplyOrderAndAnchorLeg方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIteratorByImplyOrderAndAnchorLeg: public CImplyOrderIterator
{
	friend class CImplyOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pImplyOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CImplyOrder *pImplyOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableImplyOrder m_compareObject;
	
	static CMemoryStack<CImplyOrderIteratorByImplyOrderAndAnchorLeg> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ImplyOrderID	隐含报单号
	///@param	AnchorLegID	锚报单分腿编号
	CImplyOrderIteratorByImplyOrderAndAnchorLeg(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID,const CReadOnlyLegIDType& AnchorLegID)
	{
		init(pFactory,ImplyOrderID,AnchorLegID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ImplyOrderID	隐含报单号
	///@param	AnchorLegID	锚报单分腿编号
	static CImplyOrderIteratorByImplyOrderAndAnchorLeg *alloc(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID,const CReadOnlyLegIDType& AnchorLegID);

	///构造方法
	CImplyOrderIteratorByImplyOrderAndAnchorLeg(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ImplyOrderID	隐含报单号
	///@param	AnchorLegID	锚报单分腿编号
	void init(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID,const CReadOnlyLegIDType& AnchorLegID);

	///析构方法，将负责释放所占用的空间
	virtual ~CImplyOrderIteratorByImplyOrderAndAnchorLeg(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CImplyOrder，必须在startFindByImplyOrderAndAnchorLeg以后，endFindByImplyOrderAndAnchorLeg之前叫用
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CImplyOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByImplyOrderAndAnchorLeg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableImplyOrder * pByImplyOrderAndAnchorLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CImplyOrderIteratorByImplyOrder是一个对隐式报单使用ByImplyOrder方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIteratorByImplyOrder: public CImplyOrderIterator
{
	friend class CImplyOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pImplyOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CImplyOrder *pImplyOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableImplyOrder m_compareObject;
	
	static CMemoryStack<CImplyOrderIteratorByImplyOrder> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ImplyOrderID	隐含报单号
	CImplyOrderIteratorByImplyOrder(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID)
	{
		init(pFactory,ImplyOrderID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ImplyOrderID	隐含报单号
	static CImplyOrderIteratorByImplyOrder *alloc(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID);

	///构造方法
	CImplyOrderIteratorByImplyOrder(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ImplyOrderID	隐含报单号
	void init(CImplyOrderFactory *pFactory
		,const CReadOnlyOrderSysIDType& ImplyOrderID);

	///析构方法，将负责释放所占用的空间
	virtual ~CImplyOrderIteratorByImplyOrder(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CImplyOrder，必须在startFindByImplyOrder以后，endFindByImplyOrder之前叫用
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CImplyOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByImplyOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableImplyOrder * pByImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CQuoteIteratorByUserID是一个对报价使用ByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIteratorByUserID: public CQuoteIterator
{
	friend class CQuoteFactory;
private:
	///检查此对象是否满足条件
	///@param	pQuote		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CQuote *pQuote);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableQuote m_compareObject;
	
	static CMemoryStack<CQuoteIteratorByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户
	CQuoteIteratorByUserID(CQuoteFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户
	static CQuoteIteratorByUserID *alloc(CQuoteFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///构造方法
	CQuoteIteratorByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	用户
	void init(CQuoteFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///析构方法，将负责释放所占用的空间
	virtual ~CQuoteIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CQuote，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	virtual CQuote *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableQuote * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CQuoteIteratorStartByParticipantID是一个对报价使用StartByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIteratorStartByParticipantID: public CQuoteIterator
{
	friend class CQuoteFactory;
private:
	///检查此对象是否满足条件
	///@param	pQuote		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CQuote *pQuote);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableQuote m_compareObject;
	
	static CMemoryStack<CQuoteIteratorStartByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CQuoteIteratorStartByParticipantID(CQuoteFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CQuoteIteratorStartByParticipantID *alloc(CQuoteFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CQuoteIteratorStartByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CQuoteFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CQuoteIteratorStartByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CQuote，必须在startFindStartByParticipantID以后，endFindStartByParticipantID之前叫用
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	virtual CQuote *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableQuote * pStartByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CQuoteIteratorBySettlementGroupID是一个对报价使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIteratorBySettlementGroupID: public CQuoteIterator
{
	friend class CQuoteFactory;
private:
	///检查此对象是否满足条件
	///@param	pQuote		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CQuote *pQuote);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CQuote *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CQuote *m_pNext;

	///用于存储查询参数的对象
	CWriteableQuote m_compareObject;
	
	static CMemoryStack<CQuoteIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CQuoteIteratorBySettlementGroupID(CQuoteFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CQuoteIteratorBySettlementGroupID *alloc(CQuoteFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CQuoteIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CQuoteFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CQuoteIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CQuote，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	virtual CQuote *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableQuote * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorByBuyMBLData是一个对分价表使用ByBuyMBLData方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorByBuyMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pMBLMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMBLMarketData *pMBLMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorByBuyMBLData> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	CMBLMarketDataIteratorByBuyMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	static CMBLMarketDataIteratorByBuyMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CMBLMarketDataIteratorByBuyMBLData(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMBLMarketDataIteratorByBuyMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindByBuyMBLData以后，endFindByBuyMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByBuyMBLData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pByBuyMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorBySellMBLData是一个对分价表使用BySellMBLData方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorBySellMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pMBLMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMBLMarketData *pMBLMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorBySellMBLData> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	CMBLMarketDataIteratorBySellMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	static CMBLMarketDataIteratorBySellMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CMBLMarketDataIteratorBySellMBLData(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMBLMarketDataIteratorBySellMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindBySellMBLData以后，endFindBySellMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySellMBLData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pBySellMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorStartByBuyMBLData是一个对分价表使用StartByBuyMBLData方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorStartByBuyMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pMBLMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMBLMarketData *pMBLMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorStartByBuyMBLData> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	CMBLMarketDataIteratorStartByBuyMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	static CMBLMarketDataIteratorStartByBuyMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CMBLMarketDataIteratorStartByBuyMBLData(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMBLMarketDataIteratorStartByBuyMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindStartByBuyMBLData以后，endFindStartByBuyMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByBuyMBLData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pStartByBuyMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIteratorStartBySellMBLData是一个对分价表使用StartBySellMBLData方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIteratorStartBySellMBLData: public CMBLMarketDataIterator
{
	friend class CMBLMarketDataFactory;
private:
	///检查此对象是否满足条件
	///@param	pMBLMarketData		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMBLMarketData *pMBLMarketData);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableMBLMarketData m_compareObject;
	
	static CMemoryStack<CMBLMarketDataIteratorStartBySellMBLData> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	CMBLMarketDataIteratorStartBySellMBLData(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	static CMBLMarketDataIteratorStartBySellMBLData *alloc(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CMBLMarketDataIteratorStartBySellMBLData(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约代码
	void init(CMBLMarketDataFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CMBLMarketDataIteratorStartBySellMBLData(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMBLMarketData，必须在startFindStartBySellMBLData以后，endFindStartBySellMBLData之前叫用
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartBySellMBLData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pStartBySellMBLData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradeIteratorAll是一个对成交使用All方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorAll: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///检查此对象是否满足条件
	///@param	pTrade		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTrade *pTrade);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CTradeIteratorAll(CTradeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CTradeIteratorAll *alloc(CTradeFactory *pFactory
		);

	///构造方法
	CTradeIteratorAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CTradeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CTradeIteratorAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTrade，必须在startFindAll以后，endFindAll之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorByTradeID是一个对成交使用ByTradeID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorByTradeID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///检查此对象是否满足条件
	///@param	pTrade		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTrade *pTrade);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorByTradeID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	TradeID	成交编号
	CTradeIteratorByTradeID(CTradeFactory *pFactory
		,const CReadOnlyTradeIDType& TradeID)
	{
		init(pFactory,TradeID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	TradeID	成交编号
	static CTradeIteratorByTradeID *alloc(CTradeFactory *pFactory
		,const CReadOnlyTradeIDType& TradeID);

	///构造方法
	CTradeIteratorByTradeID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	TradeID	成交编号
	void init(CTradeFactory *pFactory
		,const CReadOnlyTradeIDType& TradeID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTradeIteratorByTradeID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTrade，必须在startFindByTradeID以后，endFindByTradeID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTradeID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pByTradeID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorStartByPartID是一个对成交使用StartByPartID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorStartByPartID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///检查此对象是否满足条件
	///@param	pTrade		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTrade *pTrade);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorStartByPartID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CTradeIteratorStartByPartID(CTradeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CTradeIteratorStartByPartID *alloc(CTradeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CTradeIteratorStartByPartID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CTradeFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTradeIteratorStartByPartID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTrade，必须在startFindStartByPartID以后，endFindStartByPartID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByPartID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pStartByPartID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorByClientID是一个对成交使用ByClientID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorByClientID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///检查此对象是否满足条件
	///@param	pTrade		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTrade *pTrade);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorByClientID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	CTradeIteratorByClientID(CTradeFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	static CTradeIteratorByClientID *alloc(CTradeFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///构造方法
	CTradeIteratorByClientID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	void init(CTradeFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTradeIteratorByClientID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTrade，必须在startFindByClientID以后，endFindByClientID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByClientID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pByClientID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorStartByInstrumentID是一个对成交使用StartByInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorStartByInstrumentID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///检查此对象是否满足条件
	///@param	pTrade		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTrade *pTrade);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorStartByInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	CTradeIteratorStartByInstrumentID(CTradeFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	static CTradeIteratorStartByInstrumentID *alloc(CTradeFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CTradeIteratorStartByInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	InstrumentID	合约号
	void init(CTradeFactory *pFactory
		,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTradeIteratorStartByInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTrade，必须在startFindStartByInstrumentID以后，endFindStartByInstrumentID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pStartByInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pStartByInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CTradeIteratorBySettlementGroupID是一个对成交使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIteratorBySettlementGroupID: public CTradeIterator
{
	friend class CTradeFactory;
private:
	///检查此对象是否满足条件
	///@param	pTrade		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CTrade *pTrade);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CTrade *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CTrade *m_pNext;

	///用于存储查询参数的对象
	CWriteableTrade m_compareObject;
	
	static CMemoryStack<CTradeIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CTradeIteratorBySettlementGroupID(CTradeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CTradeIteratorBySettlementGroupID *alloc(CTradeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CTradeIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CTradeFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CTradeIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CTrade，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseIteratorBySettlementGroupID是一个对熔断阶段使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseIteratorBySettlementGroupID: public CFusePhaseIterator
{
	friend class CFusePhaseFactory;
private:
	///检查此对象是否满足条件
	///@param	pFusePhase		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CFusePhase *pFusePhase);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CFusePhase *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CFusePhase *m_pNext;

	///用于存储查询参数的对象
	CWriteableFusePhase m_compareObject;
	
	static CMemoryStack<CFusePhaseIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	CFusePhaseIteratorBySettlementGroupID(CFusePhaseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	static CFusePhaseIteratorBySettlementGroupID *alloc(CFusePhaseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CFusePhaseIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	void init(CFusePhaseFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CFusePhaseIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CFusePhase，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CFusePhase，如果已经没有一个满足要求了，则返回NULL
	virtual CFusePhase *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFusePhase * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorBySettlementGroupID是一个对执行宣告使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorBySettlementGroupID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pExecOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CExecOrder *pExecOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CExecOrder *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CExecOrder *m_pNext;

	///用于存储查询参数的对象
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	CExecOrderIteratorBySettlementGroupID(CExecOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	static CExecOrderIteratorBySettlementGroupID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CExecOrderIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	void init(CExecOrderFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CExecOrderIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CExecOrder，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByParticipantID是一个对执行宣告使用ByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByParticipantID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pExecOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CExecOrder *pExecOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	CExecOrderIteratorByParticipantID(CExecOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	static CExecOrderIteratorByParticipantID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CExecOrderIteratorByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	会员号
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CExecOrderIteratorByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CExecOrder，必须在startFindByParticipantID以后，endFindByParticipantID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByClientID是一个对执行宣告使用ByClientID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByClientID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pExecOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CExecOrder *pExecOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByClientID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	CExecOrderIteratorByClientID(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID)
	{
		init(pFactory,ClientID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	static CExecOrderIteratorByClientID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///构造方法
	CExecOrderIteratorByClientID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID);

	///析构方法，将负责释放所占用的空间
	virtual ~CExecOrderIteratorByClientID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CExecOrder，必须在startFindByClientID以后，endFindByClientID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByClientID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pByClientID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByClientIDAndInstrumentID是一个对执行宣告使用ByClientIDAndInstrumentID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByClientIDAndInstrumentID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pExecOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CExecOrder *pExecOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByClientIDAndInstrumentID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	CExecOrderIteratorByClientIDAndInstrumentID(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID)
	{
		init(pFactory,ClientID,InstrumentID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	static CExecOrderIteratorByClientIDAndInstrumentID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///构造方法
	CExecOrderIteratorByClientIDAndInstrumentID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ClientID	客户号
	///@param	InstrumentID	合约号
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyClientIDType& ClientID,const CReadOnlyInstrumentIDType& InstrumentID);

	///析构方法，将负责释放所占用的空间
	virtual ~CExecOrderIteratorByClientIDAndInstrumentID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CExecOrder，必须在startFindByClientIDAndInstrumentID以后，endFindByClientIDAndInstrumentID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByClientIDAndInstrumentID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pByClientIDAndInstrumentID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CExecOrderIteratorByUserID是一个对执行宣告使用ByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIteratorByUserID: public CExecOrderIterator
{
	friend class CExecOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pExecOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CExecOrder *pExecOrder);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的索引节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CAVLNode *m_pCurrent;

	///当m_gotNext为true时，本值下一次next时的开始寻找的节点对应的索引节点，其他情况下无意义
	CAVLNode *m_pNext;

	///用于存储查询参数的对象
	CWriteableExecOrder m_compareObject;
	
	static CMemoryStack<CExecOrderIteratorByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	CExecOrderIteratorByUserID(CExecOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID)
	{
		init(pFactory,UserID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	static CExecOrderIteratorByUserID *alloc(CExecOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///构造方法
	CExecOrderIteratorByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	UserID	交易员代码
	void init(CExecOrderFactory *pFactory
		,const CReadOnlyUserIDType& UserID);

	///析构方法，将负责释放所占用的空间
	virtual ~CExecOrderIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CExecOrder，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureIteratorBySettlementGroupID是一个对单边市情况使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureIteratorBySettlementGroupID: public CUniPressureIterator
{
	friend class CUniPressureFactory;
private:
	///检查此对象是否满足条件
	///@param	pUniPressure		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CUniPressure *pUniPressure);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CUniPressure *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CUniPressure *m_pNext;

	///用于存储查询参数的对象
	CWriteableUniPressure m_compareObject;
	
	static CMemoryStack<CUniPressureIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	CUniPressureIteratorBySettlementGroupID(CUniPressureFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	static CUniPressureIteratorBySettlementGroupID *alloc(CUniPressureFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CUniPressureIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	void init(CUniPressureFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CUniPressureIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CUniPressure，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CUniPressure，如果已经没有一个满足要求了，则返回NULL
	virtual CUniPressure *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUniPressure * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitIteratorBySettlementGroupID是一个对涨跌停板设置使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitIteratorBySettlementGroupID: public CBasePriceLimitIterator
{
	friend class CBasePriceLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pBasePriceLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CBasePriceLimit *pBasePriceLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CBasePriceLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CBasePriceLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableBasePriceLimit m_compareObject;
	
	static CMemoryStack<CBasePriceLimitIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	CBasePriceLimitIteratorBySettlementGroupID(CBasePriceLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	static CBasePriceLimitIteratorBySettlementGroupID *alloc(CBasePriceLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CBasePriceLimitIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组编号
	void init(CBasePriceLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CBasePriceLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CBasePriceLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CBasePriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CBasePriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorBySettlementGroupID是一个对信用限额使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorBySettlementGroupID: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pCreditLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCreditLimit *pCreditLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCreditLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCreditLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCreditLimitIteratorBySettlementGroupID(CCreditLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCreditLimitIteratorBySettlementGroupID *alloc(CCreditLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCreditLimitIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCreditLimitFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCreditLimitIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCreditLimit，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorAllByParticipantID是一个对信用限额使用AllByParticipantID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorAllByParticipantID: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pCreditLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCreditLimit *pCreditLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCreditLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCreditLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorAllByParticipantID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	交易会员编号
	CCreditLimitIteratorAllByParticipantID(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID)
	{
		init(pFactory,ParticipantID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	交易会员编号
	static CCreditLimitIteratorAllByParticipantID *alloc(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///构造方法
	CCreditLimitIteratorAllByParticipantID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	交易会员编号
	void init(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCreditLimitIteratorAllByParticipantID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCreditLimit，必须在startFindAllByParticipantID以后，endFindAllByParticipantID之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAllByParticipantID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pAllByParticipantID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorAllByClearingPartID是一个对信用限额使用AllByClearingPartID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorAllByClearingPartID: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pCreditLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCreditLimit *pCreditLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCreditLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCreditLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorAllByClearingPartID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ClearingPartID	结算会员编号
	CCreditLimitIteratorAllByClearingPartID(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ClearingPartID)
	{
		init(pFactory,ClearingPartID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ClearingPartID	结算会员编号
	static CCreditLimitIteratorAllByClearingPartID *alloc(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ClearingPartID);

	///构造方法
	CCreditLimitIteratorAllByClearingPartID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ClearingPartID	结算会员编号
	void init(CCreditLimitFactory *pFactory
		,const CReadOnlyParticipantIDType& ClearingPartID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCreditLimitIteratorAllByClearingPartID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCreditLimit，必须在startFindAllByClearingPartID以后，endFindAllByClearingPartID之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAllByClearingPartID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pAllByClearingPartID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CCreditLimitIteratorAll是一个对信用限额使用All方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIteratorAll: public CCreditLimitIterator
{
	friend class CCreditLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pCreditLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCreditLimit *pCreditLimit);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCreditLimit *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCreditLimit *m_pNext;

	///用于存储查询参数的对象
	CWriteableCreditLimit m_compareObject;
	
	static CMemoryStack<CCreditLimitIteratorAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CCreditLimitIteratorAll(CCreditLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CCreditLimitIteratorAll *alloc(CCreditLimitFactory *pFactory
		);

	///构造方法
	CCreditLimitIteratorAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CCreditLimitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CCreditLimitIteratorAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCreditLimit，必须在startFindAll以后，endFindAll之前叫用
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionIteratorBySettlementGroupID是一个对当日期货合约期权属性使用BySettlementGroupID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionIteratorBySettlementGroupID: public CCurrInstrumentOptionIterator
{
	friend class CCurrInstrumentOptionFactory;
private:
	///检查此对象是否满足条件
	///@param	pCurrInstrumentOption		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CCurrInstrumentOption *pCurrInstrumentOption);

	///在需要的情况下，获取下一个值，如果不是第一次，而且还没有取过下一个值，
	///那么就必须保证叫用时m_pCurrent指向正确的值，否则本方法的结果不确定
	void internalGetNext(void);

	///是否是第一次查询
	int m_isFirstTime;
	
	///是否已经取了下一个对象
	bool m_gotNext;

	///存储最后一次找到的节点
	///当m_isFirstTime为1时，或者发生了DeleteCurrent时，本值无意义
	CCurrInstrumentOption *m_pCurrent;
	
	///当m_gotNext为true时，本值下一次next时的开始寻找的节点，其他情况下无意义
	CCurrInstrumentOption *m_pNext;

	///用于存储查询参数的对象
	CWriteableCurrInstrumentOption m_compareObject;
	
	static CMemoryStack<CCurrInstrumentOptionIteratorBySettlementGroupID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	CCurrInstrumentOptionIteratorBySettlementGroupID(CCurrInstrumentOptionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID)
	{
		init(pFactory,SettlementGroupID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	static CCurrInstrumentOptionIteratorBySettlementGroupID *alloc(CCurrInstrumentOptionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///构造方法
	CCurrInstrumentOptionIteratorBySettlementGroupID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SettlementGroupID	结算组代码
	void init(CCurrInstrumentOptionFactory *pFactory
		,const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///析构方法，将负责释放所占用的空间
	virtual ~CCurrInstrumentOptionIteratorBySettlementGroupID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CCurrInstrumentOption，必须在startFindBySettlementGroupID以后，endFindBySettlementGroupID之前叫用
	///@return	下一个满足条件CCurrInstrumentOption，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentOption *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySettlementGroupID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pBySettlementGroupID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

#endif
