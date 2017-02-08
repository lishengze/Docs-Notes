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
///CSysInvalidateOrderIteratorByActionTime是一个对无效报单使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderIteratorByActionTime: public CSysInvalidateOrderIterator
{
	friend class CSysInvalidateOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysInvalidateOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysInvalidateOrder *pSysInvalidateOrder);

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
	CWriteableSysInvalidateOrder m_compareObject;
	
	static CMemoryStack<CSysInvalidateOrderIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysInvalidateOrderIteratorByActionTime(CSysInvalidateOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysInvalidateOrderIteratorByActionTime *alloc(CSysInvalidateOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysInvalidateOrderIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysInvalidateOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysInvalidateOrderIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysInvalidateOrder，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysInvalidateOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInvalidateOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusIteratorByActionTime是一个对报单状态使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusIteratorByActionTime: public CSysOrderStatusIterator
{
	friend class CSysOrderStatusFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysOrderStatus		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysOrderStatus *pSysOrderStatus);

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
	CWriteableSysOrderStatus m_compareObject;
	
	static CMemoryStack<CSysOrderStatusIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysOrderStatusIteratorByActionTime(CSysOrderStatusFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysOrderStatusIteratorByActionTime *alloc(CSysOrderStatusFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysOrderStatusIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysOrderStatusFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysOrderStatusIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysOrderStatus，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysOrderStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOrderStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderIteratorByActionTime是一个对报单成交使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderIteratorByActionTime: public CSysBargainOrderIterator
{
	friend class CSysBargainOrderFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysBargainOrder		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysBargainOrder *pSysBargainOrder);

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
	CWriteableSysBargainOrder m_compareObject;
	
	static CMemoryStack<CSysBargainOrderIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysBargainOrderIteratorByActionTime(CSysBargainOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysBargainOrderIteratorByActionTime *alloc(CSysBargainOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysBargainOrderIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysBargainOrderFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysBargainOrderIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysBargainOrder，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysBargainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysBargainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyIteratorByAll是一个对合约基本属性使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyIteratorByAll: public CSysInstPropertyIterator
{
	friend class CSysInstPropertyFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysInstProperty		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysInstProperty *pSysInstProperty);

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
	CWriteableSysInstProperty m_compareObject;
	
	static CMemoryStack<CSysInstPropertyIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysInstPropertyIteratorByAll(CSysInstPropertyFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysInstPropertyIteratorByAll *alloc(CSysInstPropertyFactory *pFactory
		);

	///构造方法
	CSysInstPropertyIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysInstPropertyFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysInstPropertyIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysInstProperty，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysInstProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstProperty * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateIteratorByAll是一个对合约保证金率使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateIteratorByAll: public CSysMarginRateIterator
{
	friend class CSysMarginRateFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMarginRate		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMarginRate *pSysMarginRate);

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
	CWriteableSysMarginRate m_compareObject;
	
	static CMemoryStack<CSysMarginRateIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMarginRateIteratorByAll(CSysMarginRateFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMarginRateIteratorByAll *alloc(CSysMarginRateFactory *pFactory
		);

	///构造方法
	CSysMarginRateIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMarginRateFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMarginRateIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMarginRate，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRate * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitIteratorByAll是一个对合约涨跌停板使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitIteratorByAll: public CSysPriceLimitIterator
{
	friend class CSysPriceLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysPriceLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysPriceLimit *pSysPriceLimit);

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
	CWriteableSysPriceLimit m_compareObject;
	
	static CMemoryStack<CSysPriceLimitIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysPriceLimitIteratorByAll(CSysPriceLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysPriceLimitIteratorByAll *alloc(CSysPriceLimitFactory *pFactory
		);

	///构造方法
	CSysPriceLimitIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysPriceLimitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPriceLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysPriceLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysPriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitIteratorByAll是一个对会员限仓使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitIteratorByAll: public CSysPartPosiLimitIterator
{
	friend class CSysPartPosiLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysPartPosiLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysPartPosiLimit *pSysPartPosiLimit);

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
	CWriteableSysPartPosiLimit m_compareObject;
	
	static CMemoryStack<CSysPartPosiLimitIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysPartPosiLimitIteratorByAll(CSysPartPosiLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysPartPosiLimitIteratorByAll *alloc(CSysPartPosiLimitFactory *pFactory
		);

	///构造方法
	CSysPartPosiLimitIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysPartPosiLimitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartPosiLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysPartPosiLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitIteratorByAll是一个对客户限仓使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitIteratorByAll: public CSysClientPosiLimitIterator
{
	friend class CSysClientPosiLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysClientPosiLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysClientPosiLimit *pSysClientPosiLimit);

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
	CWriteableSysClientPosiLimit m_compareObject;
	
	static CMemoryStack<CSysClientPosiLimitIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysClientPosiLimitIteratorByAll(CSysClientPosiLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysClientPosiLimitIteratorByAll *alloc(CSysClientPosiLimitFactory *pFactory
		);

	///构造方法
	CSysClientPosiLimitIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysClientPosiLimitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientPosiLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysClientPosiLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitIteratorByAll是一个对特殊客户限仓使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitIteratorByAll: public CSysSpecialPosiLimitIterator
{
	friend class CSysSpecialPosiLimitFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysSpecialPosiLimit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysSpecialPosiLimit *pSysSpecialPosiLimit);

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
	CWriteableSysSpecialPosiLimit m_compareObject;
	
	static CMemoryStack<CSysSpecialPosiLimitIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysSpecialPosiLimitIteratorByAll(CSysSpecialPosiLimitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysSpecialPosiLimitIteratorByAll *alloc(CSysSpecialPosiLimitFactory *pFactory
		);

	///构造方法
	CSysSpecialPosiLimitIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysSpecialPosiLimitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysSpecialPosiLimitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysSpecialPosiLimit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgIteratorByActionTime是一个对账户出入金查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgIteratorByActionTime: public CSysTransactionChgIterator
{
	friend class CSysTransactionChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysTransactionChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysTransactionChg *pSysTransactionChg);

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
	CWriteableSysTransactionChg m_compareObject;
	
	static CMemoryStack<CSysTransactionChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysTransactionChgIteratorByActionTime(CSysTransactionChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysTransactionChgIteratorByActionTime *alloc(CSysTransactionChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysTransactionChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysTransactionChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysTransactionChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysTransactionChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysTransactionChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTransactionChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgIteratorByActionTime是一个对客户数据变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgIteratorByActionTime: public CSysClientChgIterator
{
	friend class CSysClientChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysClientChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysClientChg *pSysClientChg);

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
	CWriteableSysClientChg m_compareObject;
	
	static CMemoryStack<CSysClientChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysClientChgIteratorByActionTime(CSysClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysClientChgIteratorByActionTime *alloc(CSysClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysClientChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysClientChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgIteratorByActionTime是一个对会员客户对照变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgIteratorByActionTime: public CSysPartClientChgIterator
{
	friend class CSysPartClientChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysPartClientChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysPartClientChg *pSysPartClientChg);

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
	CWriteableSysPartClientChg m_compareObject;
	
	static CMemoryStack<CSysPartClientChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysPartClientChgIteratorByActionTime(CSysPartClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysPartClientChgIteratorByActionTime *alloc(CSysPartClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysPartClientChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysPartClientChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartClientChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysPartClientChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysPartClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgIteratorByActionTime是一个对限仓数据变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgIteratorByActionTime: public CSysPosiLimitChgIterator
{
	friend class CSysPosiLimitChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysPosiLimitChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysPosiLimitChg *pSysPosiLimitChg);

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
	CWriteableSysPosiLimitChg m_compareObject;
	
	static CMemoryStack<CSysPosiLimitChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysPosiLimitChgIteratorByActionTime(CSysPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysPosiLimitChgIteratorByActionTime *alloc(CSysPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysPosiLimitChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPosiLimitChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysPosiLimitChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgIteratorByActionTime是一个对限仓数据变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgIteratorByActionTime: public CSysClientPosiLimitChgIterator
{
	friend class CSysClientPosiLimitChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysClientPosiLimitChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysClientPosiLimitChg *pSysClientPosiLimitChg);

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
	CWriteableSysClientPosiLimitChg m_compareObject;
	
	static CMemoryStack<CSysClientPosiLimitChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysClientPosiLimitChgIteratorByActionTime(CSysClientPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysClientPosiLimitChgIteratorByActionTime *alloc(CSysClientPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysClientPosiLimitChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysClientPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientPosiLimitChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysClientPosiLimitChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysClientPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgIteratorByActionTime是一个对限仓数据变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgIteratorByActionTime: public CSysSpecPosiLimitChgIterator
{
	friend class CSysSpecPosiLimitChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysSpecPosiLimitChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);

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
	CWriteableSysSpecPosiLimitChg m_compareObject;
	
	static CMemoryStack<CSysSpecPosiLimitChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysSpecPosiLimitChgIteratorByActionTime(CSysSpecPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysSpecPosiLimitChgIteratorByActionTime *alloc(CSysSpecPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysSpecPosiLimitChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysSpecPosiLimitChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysSpecPosiLimitChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysSpecPosiLimitChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysSpecPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgIteratorByActionTime是一个对保值额度变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgIteratorByActionTime: public CSysHedgeDetailChgIterator
{
	friend class CSysHedgeDetailChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysHedgeDetailChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysHedgeDetailChg *pSysHedgeDetailChg);

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
	CWriteableSysHedgeDetailChg m_compareObject;
	
	static CMemoryStack<CSysHedgeDetailChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysHedgeDetailChgIteratorByActionTime(CSysHedgeDetailChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysHedgeDetailChgIteratorByActionTime *alloc(CSysHedgeDetailChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysHedgeDetailChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysHedgeDetailChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysHedgeDetailChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysHedgeDetailChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysHedgeDetailChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgIteratorByActionTime是一个对会员变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgIteratorByActionTime: public CSysParticipantChgIterator
{
	friend class CSysParticipantChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysParticipantChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysParticipantChg *pSysParticipantChg);

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
	CWriteableSysParticipantChg m_compareObject;
	
	static CMemoryStack<CSysParticipantChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysParticipantChgIteratorByActionTime(CSysParticipantChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysParticipantChgIteratorByActionTime *alloc(CSysParticipantChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysParticipantChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysParticipantChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticipantChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysParticipantChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysParticipantChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgIteratorByActionTime是一个对保证金率变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgIteratorByActionTime: public CSysMarginRateChgIterator
{
	friend class CSysMarginRateChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMarginRateChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMarginRateChg *pSysMarginRateChg);

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
	CWriteableSysMarginRateChg m_compareObject;
	
	static CMemoryStack<CSysMarginRateChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysMarginRateChgIteratorByActionTime(CSysMarginRateChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysMarginRateChgIteratorByActionTime *alloc(CSysMarginRateChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysMarginRateChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysMarginRateChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMarginRateChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMarginRateChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysMarginRateChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRateChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgIteratorByActionTime是一个对IP地址变动查询使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgIteratorByActionTime: public CSysUserIpChgIterator
{
	friend class CSysUserIpChgFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysUserIpChg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysUserIpChg *pSysUserIpChg);

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
	CWriteableSysUserIpChg m_compareObject;
	
	static CMemoryStack<CSysUserIpChgIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	CSysUserIpChgIteratorByActionTime(CSysUserIpChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime)
	{
		init(pFactory,ActionTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	static CSysUserIpChgIteratorByActionTime *alloc(CSysUserIpChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///构造方法
	CSysUserIpChgIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ActionTime	
	void init(CSysUserIpChgFactory *pFactory
		,const CReadOnlyTimeType& ActionTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserIpChgIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysUserIpChg，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysUserIpChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserIpChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeIteratorByAll是一个对会员交易信息使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeIteratorByAll: public CSysPartTradeIterator
{
	friend class CSysPartTradeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysPartTrade		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysPartTrade *pSysPartTrade);

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
	CWriteableSysPartTrade m_compareObject;
	
	static CMemoryStack<CSysPartTradeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysPartTradeIteratorByAll(CSysPartTradeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysPartTradeIteratorByAll *alloc(CSysPartTradeFactory *pFactory
		);

	///构造方法
	CSysPartTradeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysPartTradeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysPartTradeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysPartTrade，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysPartTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartTrade * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorByIDType是一个对对象状态指标使用ByIDType方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorByIDType: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbObjectAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorByIDType> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbObjectAttrIteratorByIDType(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbObjectAttrIteratorByIDType *alloc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbObjectAttrIteratorByIDType(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbObjectAttrIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorByDsc是一个对对象状态指标使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorByDsc: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbObjectAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbObjectAttrIteratorByDsc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbObjectAttrIteratorByDsc *alloc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbObjectAttrIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbObjectAttrIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorBytheAll是一个对对象状态指标使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorBytheAll: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbObjectAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbObjectAttrIteratorBytheAll(CSysMdbObjectAttrFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbObjectAttrIteratorBytheAll *alloc(CSysMdbObjectAttrFactory *pFactory
		);

	///构造方法
	CSysMdbObjectAttrIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbObjectAttrFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbObjectAttrIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIteratorByDataDelete是一个对对象状态指标使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIteratorByDataDelete: public CSysMdbObjectAttrIterator
{
	friend class CSysMdbObjectAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbObjectAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbObjectAttr *pSysMdbObjectAttr);

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
	CWriteableSysMdbObjectAttr m_compareObject;
	
	static CMemoryStack<CSysMdbObjectAttrIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbObjectAttrIteratorByDataDelete(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbObjectAttrIteratorByDataDelete *alloc(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbObjectAttrIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbObjectAttrFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbObjectAttrIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbObjectAttr，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIteratorByAll是一个对日志文件内容传输信息使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIteratorByAll: public CSysMdbSyslogInfoIterator
{
	friend class CSysMdbSyslogInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbSyslogInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

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
	CWriteableSysMdbSyslogInfo m_compareObject;
	
	static CMemoryStack<CSysMdbSyslogInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	AttrType	
	CSysMdbSyslogInfoIteratorByAll(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType)
	{
		init(pFactory,ObjectID,AttrType);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	AttrType	
	static CSysMdbSyslogInfoIteratorByAll *alloc(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType);

	///构造方法
	CSysMdbSyslogInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	AttrType	
	void init(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbSyslogInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbSyslogInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIteratorBytheAll是一个对日志文件内容传输信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIteratorBytheAll: public CSysMdbSyslogInfoIterator
{
	friend class CSysMdbSyslogInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbSyslogInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

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
	CWriteableSysMdbSyslogInfo m_compareObject;
	
	static CMemoryStack<CSysMdbSyslogInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbSyslogInfoIteratorBytheAll(CSysMdbSyslogInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbSyslogInfoIteratorBytheAll *alloc(CSysMdbSyslogInfoFactory *pFactory
		);

	///构造方法
	CSysMdbSyslogInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbSyslogInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbSyslogInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbSyslogInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIteratorByDataDelete是一个对日志文件内容传输信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIteratorByDataDelete: public CSysMdbSyslogInfoIterator
{
	friend class CSysMdbSyslogInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbSyslogInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbSyslogInfo *pSysMdbSyslogInfo);

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
	CWriteableSysMdbSyslogInfo m_compareObject;
	
	static CMemoryStack<CSysMdbSyslogInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	AttrType	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbSyslogInfoIteratorByDataDelete(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,AttrType,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	AttrType	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbSyslogInfoIteratorByDataDelete *alloc(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbSyslogInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	AttrType	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbSyslogInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyVolumeType& AttrType,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbSyslogInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbSyslogInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIteratorByHostName是一个对用户信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIteratorByHostName: public CSysUserInfoIterator
{
	friend class CSysUserInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysUserInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysUserInfo *pSysUserInfo);

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
	CWriteableSysUserInfo m_compareObject;
	
	static CMemoryStack<CSysUserInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	CSysUserInfoIteratorByHostName(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	static CSysUserInfoIteratorByHostName *alloc(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysUserInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	void init(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysUserInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIteratorBytheAll是一个对用户信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIteratorBytheAll: public CSysUserInfoIterator
{
	friend class CSysUserInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysUserInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysUserInfo *pSysUserInfo);

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
	CWriteableSysUserInfo m_compareObject;
	
	static CMemoryStack<CSysUserInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysUserInfoIteratorBytheAll(CSysUserInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysUserInfoIteratorBytheAll *alloc(CSysUserInfoFactory *pFactory
		);

	///构造方法
	CSysUserInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysUserInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysUserInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIteratorByDsc是一个对用户信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIteratorByDsc: public CSysUserInfoIterator
{
	friend class CSysUserInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysUserInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysUserInfo *pSysUserInfo);

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
	CWriteableSysUserInfo m_compareObject;
	
	static CMemoryStack<CSysUserInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	CSysUserInfoIteratorByDsc(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	static CSysUserInfoIteratorByDsc *alloc(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///构造方法
	CSysUserInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	void init(CSysUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysUserInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIteratorByHostName是一个对在线用户信息查询应答使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIteratorByHostName: public CSysOnlineUserInfoIterator
{
	friend class CSysOnlineUserInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysOnlineUserInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysOnlineUserInfo *pSysOnlineUserInfo);

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
	CWriteableSysOnlineUserInfo m_compareObject;
	
	static CMemoryStack<CSysOnlineUserInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	CSysOnlineUserInfoIteratorByHostName(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	static CSysOnlineUserInfoIteratorByHostName *alloc(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysOnlineUserInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	void init(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysOnlineUserInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysOnlineUserInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIteratorBytheAll是一个对在线用户信息查询应答使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIteratorBytheAll: public CSysOnlineUserInfoIterator
{
	friend class CSysOnlineUserInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysOnlineUserInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysOnlineUserInfo *pSysOnlineUserInfo);

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
	CWriteableSysOnlineUserInfo m_compareObject;
	
	static CMemoryStack<CSysOnlineUserInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysOnlineUserInfoIteratorBytheAll(CSysOnlineUserInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysOnlineUserInfoIteratorBytheAll *alloc(CSysOnlineUserInfoFactory *pFactory
		);

	///构造方法
	CSysOnlineUserInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysOnlineUserInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysOnlineUserInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysOnlineUserInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIteratorByDsc是一个对在线用户信息查询应答使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIteratorByDsc: public CSysOnlineUserInfoIterator
{
	friend class CSysOnlineUserInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysOnlineUserInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysOnlineUserInfo *pSysOnlineUserInfo);

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
	CWriteableSysOnlineUserInfo m_compareObject;
	
	static CMemoryStack<CSysOnlineUserInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	CSysOnlineUserInfoIteratorByDsc(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	static CSysOnlineUserInfoIteratorByDsc *alloc(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///构造方法
	CSysOnlineUserInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	void init(CSysOnlineUserInfoFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysOnlineUserInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysOnlineUserInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorByTime是一个对告警事件查询应答使用ByTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorByTime: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysWarningEvent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorByTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	OccurTime	
	CSysWarningEventIteratorByTime(CSysWarningEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime)
	{
		init(pFactory,MonDate,OccurTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	OccurTime	
	static CSysWarningEventIteratorByTime *alloc(CSysWarningEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///构造方法
	CSysWarningEventIteratorByTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	OccurTime	
	void init(CSysWarningEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningEventIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorByAll是一个对告警事件查询应答使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorByAll: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysWarningEvent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysWarningEventIteratorByAll(CSysWarningEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysWarningEventIteratorByAll *alloc(CSysWarningEventFactory *pFactory
		);

	///构造方法
	CSysWarningEventIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysWarningEventFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningEventIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorByEvendIDs是一个对告警事件查询应答使用ByEvendIDs方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorByEvendIDs: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysWarningEvent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorByEvendIDs> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	EvendID	
	CSysWarningEventIteratorByEvendIDs(CSysWarningEventFactory *pFactory
		,const CReadOnlyVolumeType& EvendID)
	{
		init(pFactory,EvendID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	EvendID	
	static CSysWarningEventIteratorByEvendIDs *alloc(CSysWarningEventFactory *pFactory
		,const CReadOnlyVolumeType& EvendID);

	///构造方法
	CSysWarningEventIteratorByEvendIDs(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	EvendID	
	void init(CSysWarningEventFactory *pFactory
		,const CReadOnlyVolumeType& EvendID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningEventIteratorByEvendIDs(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindByEvendIDs以后，endFindByEvendIDs之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByEvendIDs 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pByEvendIDs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIteratorBytheAll是一个对告警事件查询应答使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIteratorBytheAll: public CSysWarningEventIterator
{
	friend class CSysWarningEventFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysWarningEvent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysWarningEvent *pSysWarningEvent);

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
	CWriteableSysWarningEvent m_compareObject;
	
	static CMemoryStack<CSysWarningEventIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysWarningEventIteratorBytheAll(CSysWarningEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysWarningEventIteratorBytheAll *alloc(CSysWarningEventFactory *pFactory
		);

	///构造方法
	CSysWarningEventIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysWarningEventFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningEventIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysWarningEvent，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryIteratorByTime是一个对告警明细应答使用ByTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryIteratorByTime: public CSysWarningQueryIterator
{
	friend class CSysWarningQueryFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysWarningQuery		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysWarningQuery *pSysWarningQuery);

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
	CWriteableSysWarningQuery m_compareObject;
	
	static CMemoryStack<CSysWarningQueryIteratorByTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	CSysWarningQueryIteratorByTime(CSysWarningQueryFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	static CSysWarningQueryIteratorByTime *alloc(CSysWarningQueryFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysWarningQueryIteratorByTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysWarningQueryFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysWarningQueryIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysWarningQuery，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysWarningQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventIteratorByTime是一个对日志事件查询应答使用ByTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIteratorByTime: public CSyslogEventIterator
{
	friend class CSyslogEventFactory;
private:
	///检查此对象是否满足条件
	///@param	pSyslogEvent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSyslogEvent *pSyslogEvent);

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
	CWriteableSyslogEvent m_compareObject;
	
	static CMemoryStack<CSyslogEventIteratorByTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	OccurTime	
	CSyslogEventIteratorByTime(CSyslogEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime)
	{
		init(pFactory,MonDate,OccurTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	OccurTime	
	static CSyslogEventIteratorByTime *alloc(CSyslogEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///构造方法
	CSyslogEventIteratorByTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	OccurTime	
	void init(CSyslogEventFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& OccurTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSyslogEventIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSyslogEvent，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSyslogEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSyslogEvent * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSyslogEventIteratorBytheAll是一个对日志事件查询应答使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIteratorBytheAll: public CSyslogEventIterator
{
	friend class CSyslogEventFactory;
private:
	///检查此对象是否满足条件
	///@param	pSyslogEvent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSyslogEvent *pSyslogEvent);

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
	CWriteableSyslogEvent m_compareObject;
	
	static CMemoryStack<CSyslogEventIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSyslogEventIteratorBytheAll(CSyslogEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSyslogEventIteratorBytheAll *alloc(CSyslogEventFactory *pFactory
		);

	///构造方法
	CSyslogEventIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSyslogEventFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSyslogEventIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSyslogEvent，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSyslogEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSyslogEvent * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSyslogEventIteratorByAll是一个对日志事件查询应答使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIteratorByAll: public CSyslogEventIterator
{
	friend class CSyslogEventFactory;
private:
	///检查此对象是否满足条件
	///@param	pSyslogEvent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSyslogEvent *pSyslogEvent);

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
	CWriteableSyslogEvent m_compareObject;
	
	static CMemoryStack<CSyslogEventIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSyslogEventIteratorByAll(CSyslogEventFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSyslogEventIteratorByAll *alloc(CSyslogEventFactory *pFactory
		);

	///构造方法
	CSyslogEventIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSyslogEventFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSyslogEventIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSyslogEvent，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSyslogEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSyslogEvent * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIteratorByTime是一个对事件描述查询使用ByTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIteratorByTime: public CSysEventDescripIterator
{
	friend class CSysEventDescripFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysEventDescrip		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysEventDescrip *pSysEventDescrip);

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
	CWriteableSysEventDescrip m_compareObject;
	
	static CMemoryStack<CSysEventDescripIteratorByTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	CSysEventDescripIteratorByTime(CSysEventDescripFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	static CSysEventDescripIteratorByTime *alloc(CSysEventDescripFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysEventDescripIteratorByTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysEventDescripFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysEventDescripIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysEventDescrip，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	virtual CSysEventDescrip *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIteratorBytheAll是一个对事件描述查询使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIteratorBytheAll: public CSysEventDescripIterator
{
	friend class CSysEventDescripFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysEventDescrip		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysEventDescrip *pSysEventDescrip);

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
	CWriteableSysEventDescrip m_compareObject;
	
	static CMemoryStack<CSysEventDescripIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysEventDescripIteratorBytheAll(CSysEventDescripFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysEventDescripIteratorBytheAll *alloc(CSysEventDescripFactory *pFactory
		);

	///构造方法
	CSysEventDescripIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysEventDescripFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysEventDescripIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysEventDescrip，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	virtual CSysEventDescrip *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIteratorByAll是一个对事件描述查询使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIteratorByAll: public CSysEventDescripIterator
{
	friend class CSysEventDescripFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysEventDescrip		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysEventDescrip *pSysEventDescrip);

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
	CWriteableSysEventDescrip m_compareObject;
	
	static CMemoryStack<CSysEventDescripIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysEventDescripIteratorByAll(CSysEventDescripFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysEventDescripIteratorByAll *alloc(CSysEventDescripFactory *pFactory
		);

	///构造方法
	CSysEventDescripIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysEventDescripFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysEventDescripIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysEventDescrip，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	virtual CSysEventDescrip *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonIteratorByHostName是一个对主机环境信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonIteratorByHostName: public CRspQryHostEnvCommonIterator
{
	friend class CRspQryHostEnvCommonFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvCommon		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvCommon *pRspQryHostEnvCommon);

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
	CWriteableRspQryHostEnvCommon m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvCommonIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CRspQryHostEnvCommonIteratorByHostName(CRspQryHostEnvCommonFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CRspQryHostEnvCommonIteratorByHostName *alloc(CRspQryHostEnvCommonFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///构造方法
	CRspQryHostEnvCommonIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CRspQryHostEnvCommonFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvCommonIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvCommon，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonIteratorBytheAll是一个对主机环境信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonIteratorBytheAll: public CRspQryHostEnvCommonIterator
{
	friend class CRspQryHostEnvCommonFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvCommon		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvCommon *pRspQryHostEnvCommon);

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
	CWriteableRspQryHostEnvCommon m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvCommonIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CRspQryHostEnvCommonIteratorBytheAll(CRspQryHostEnvCommonFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CRspQryHostEnvCommonIteratorBytheAll *alloc(CRspQryHostEnvCommonFactory *pFactory
		);

	///构造方法
	CRspQryHostEnvCommonIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CRspQryHostEnvCommonFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvCommonIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvCommon，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanIteratorByHostName是一个对主机环境Lan信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanIteratorByHostName: public CRspQryHostEnvLanIterator
{
	friend class CRspQryHostEnvLanFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvLan		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvLan *pRspQryHostEnvLan);

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
	CWriteableRspQryHostEnvLan m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CRspQryHostEnvLanIteratorByHostName(CRspQryHostEnvLanFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CRspQryHostEnvLanIteratorByHostName *alloc(CRspQryHostEnvLanFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///构造方法
	CRspQryHostEnvLanIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CRspQryHostEnvLanFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvLan，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanIteratorBytheAll是一个对主机环境Lan信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanIteratorBytheAll: public CRspQryHostEnvLanIterator
{
	friend class CRspQryHostEnvLanFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvLan		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvLan *pRspQryHostEnvLan);

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
	CWriteableRspQryHostEnvLan m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CRspQryHostEnvLanIteratorBytheAll(CRspQryHostEnvLanFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CRspQryHostEnvLanIteratorBytheAll *alloc(CRspQryHostEnvLanFactory *pFactory
		);

	///构造方法
	CRspQryHostEnvLanIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CRspQryHostEnvLanFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvLan，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageIteratorByHostName是一个对主机环境存储设备信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageIteratorByHostName: public CRspQryHostEnvStorageIterator
{
	friend class CRspQryHostEnvStorageFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvStorage		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvStorage *pRspQryHostEnvStorage);

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
	CWriteableRspQryHostEnvStorage m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvStorageIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CRspQryHostEnvStorageIteratorByHostName(CRspQryHostEnvStorageFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CRspQryHostEnvStorageIteratorByHostName *alloc(CRspQryHostEnvStorageFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///构造方法
	CRspQryHostEnvStorageIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CRspQryHostEnvStorageFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvStorageIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvStorage，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageIteratorBytheAll是一个对主机环境存储设备信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageIteratorBytheAll: public CRspQryHostEnvStorageIterator
{
	friend class CRspQryHostEnvStorageFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvStorage		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvStorage *pRspQryHostEnvStorage);

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
	CWriteableRspQryHostEnvStorage m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvStorageIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CRspQryHostEnvStorageIteratorBytheAll(CRspQryHostEnvStorageFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CRspQryHostEnvStorageIteratorBytheAll *alloc(CRspQryHostEnvStorageFactory *pFactory
		);

	///构造方法
	CRspQryHostEnvStorageIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CRspQryHostEnvStorageFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvStorageIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvStorage，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOIteratorByHostName是一个对主机环境IO设备信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOIteratorByHostName: public CRspQryHostEnvIOIterator
{
	friend class CRspQryHostEnvIOFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvIO		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvIO *pRspQryHostEnvIO);

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
	CWriteableRspQryHostEnvIO m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvIOIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CRspQryHostEnvIOIteratorByHostName(CRspQryHostEnvIOFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CRspQryHostEnvIOIteratorByHostName *alloc(CRspQryHostEnvIOFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///构造方法
	CRspQryHostEnvIOIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CRspQryHostEnvIOFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvIOIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvIO，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOIteratorBytheAll是一个对主机环境IO设备信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOIteratorBytheAll: public CRspQryHostEnvIOIterator
{
	friend class CRspQryHostEnvIOFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvIO		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvIO *pRspQryHostEnvIO);

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
	CWriteableRspQryHostEnvIO m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvIOIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CRspQryHostEnvIOIteratorBytheAll(CRspQryHostEnvIOFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CRspQryHostEnvIOIteratorBytheAll *alloc(CRspQryHostEnvIOFactory *pFactory
		);

	///构造方法
	CRspQryHostEnvIOIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CRspQryHostEnvIOFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvIOIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvIO，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSIteratorByHostName是一个对主机环境文件系统信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSIteratorByHostName: public CRspQryHostEnvFSIterator
{
	friend class CRspQryHostEnvFSFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvFS		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvFS *pRspQryHostEnvFS);

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
	CWriteableRspQryHostEnvFS m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvFSIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CRspQryHostEnvFSIteratorByHostName(CRspQryHostEnvFSFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CRspQryHostEnvFSIteratorByHostName *alloc(CRspQryHostEnvFSFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///构造方法
	CRspQryHostEnvFSIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CRspQryHostEnvFSFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvFSIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvFS，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSIteratorBytheAll是一个对主机环境文件系统信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSIteratorBytheAll: public CRspQryHostEnvFSIterator
{
	friend class CRspQryHostEnvFSFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvFS		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvFS *pRspQryHostEnvFS);

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
	CWriteableRspQryHostEnvFS m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvFSIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CRspQryHostEnvFSIteratorBytheAll(CRspQryHostEnvFSFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CRspQryHostEnvFSIteratorBytheAll *alloc(CRspQryHostEnvFSFactory *pFactory
		);

	///构造方法
	CRspQryHostEnvFSIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CRspQryHostEnvFSFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvFSIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvFS，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapIteratorByHostName是一个对主机环境交换分区信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapIteratorByHostName: public CRspQryHostEnvSwapIterator
{
	friend class CRspQryHostEnvSwapFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvSwap		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvSwap *pRspQryHostEnvSwap);

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
	CWriteableRspQryHostEnvSwap m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvSwapIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CRspQryHostEnvSwapIteratorByHostName(CRspQryHostEnvSwapFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CRspQryHostEnvSwapIteratorByHostName *alloc(CRspQryHostEnvSwapFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///构造方法
	CRspQryHostEnvSwapIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CRspQryHostEnvSwapFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvSwapIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvSwap，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapIteratorBytheAll是一个对主机环境交换分区信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapIteratorBytheAll: public CRspQryHostEnvSwapIterator
{
	friend class CRspQryHostEnvSwapFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvSwap		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvSwap *pRspQryHostEnvSwap);

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
	CWriteableRspQryHostEnvSwap m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvSwapIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CRspQryHostEnvSwapIteratorBytheAll(CRspQryHostEnvSwapFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CRspQryHostEnvSwapIteratorBytheAll *alloc(CRspQryHostEnvSwapFactory *pFactory
		);

	///构造方法
	CRspQryHostEnvSwapIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CRspQryHostEnvSwapFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvSwapIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvSwap，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgIteratorByHostName是一个对主机环境网卡配置信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgIteratorByHostName: public CRspQryHostEnvLanCfgIterator
{
	friend class CRspQryHostEnvLanCfgFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvLanCfg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);

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
	CWriteableRspQryHostEnvLanCfg m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanCfgIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CRspQryHostEnvLanCfgIteratorByHostName(CRspQryHostEnvLanCfgFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CRspQryHostEnvLanCfgIteratorByHostName *alloc(CRspQryHostEnvLanCfgFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///构造方法
	CRspQryHostEnvLanCfgIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CRspQryHostEnvLanCfgFactory *pFactory
		,const CReadOnlyTypeObjectIDType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanCfgIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvLanCfg，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgIteratorBytheAll是一个对主机环境网卡配置信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgIteratorBytheAll: public CRspQryHostEnvLanCfgIterator
{
	friend class CRspQryHostEnvLanCfgFactory;
private:
	///检查此对象是否满足条件
	///@param	pRspQryHostEnvLanCfg		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);

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
	CWriteableRspQryHostEnvLanCfg m_compareObject;
	
	static CMemoryStack<CRspQryHostEnvLanCfgIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CRspQryHostEnvLanCfgIteratorBytheAll(CRspQryHostEnvLanCfgFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CRspQryHostEnvLanCfgIteratorBytheAll *alloc(CRspQryHostEnvLanCfgFactory *pFactory
		);

	///构造方法
	CRspQryHostEnvLanCfgIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CRspQryHostEnvLanCfgFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CRspQryHostEnvLanCfgIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CRspQryHostEnvLanCfg，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorByHostName是一个对CPU资源使用信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorByHostName: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopCpuInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopCpuInfoIteratorByHostName(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopCpuInfoIteratorByHostName *alloc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbTopCpuInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopCpuInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorByDsc是一个对CPU资源使用信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorByDsc: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopCpuInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CSysMdbTopCpuInfoIteratorByDsc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CSysMdbTopCpuInfoIteratorByDsc *alloc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///构造方法
	CSysMdbTopCpuInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopCpuInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorBytheAll是一个对CPU资源使用信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorBytheAll: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopCpuInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbTopCpuInfoIteratorBytheAll(CSysMdbTopCpuInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbTopCpuInfoIteratorBytheAll *alloc(CSysMdbTopCpuInfoFactory *pFactory
		);

	///构造方法
	CSysMdbTopCpuInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbTopCpuInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopCpuInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIteratorByDataDelete是一个对CPU资源使用信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIteratorByDataDelete: public CSysMdbTopCpuInfoIterator
{
	friend class CSysMdbTopCpuInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopCpuInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);

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
	CWriteableSysMdbTopCpuInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopCpuInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopCpuInfoIteratorByDataDelete(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopCpuInfoIteratorByDataDelete *alloc(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbTopCpuInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopCpuInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopCpuInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopCpuInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorByHostName是一个对内存资源使用信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorByHostName: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopMemInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopMemInfoIteratorByHostName(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopMemInfoIteratorByHostName *alloc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbTopMemInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopMemInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorByDsc是一个对内存资源使用信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorByDsc: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopMemInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CSysMdbTopMemInfoIteratorByDsc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CSysMdbTopMemInfoIteratorByDsc *alloc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///构造方法
	CSysMdbTopMemInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopMemInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorBytheAll是一个对内存资源使用信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorBytheAll: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopMemInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbTopMemInfoIteratorBytheAll(CSysMdbTopMemInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbTopMemInfoIteratorBytheAll *alloc(CSysMdbTopMemInfoFactory *pFactory
		);

	///构造方法
	CSysMdbTopMemInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbTopMemInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopMemInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIteratorByDataDelete是一个对内存资源使用信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIteratorByDataDelete: public CSysMdbTopMemInfoIterator
{
	friend class CSysMdbTopMemInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopMemInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopMemInfo *pSysMdbTopMemInfo);

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
	CWriteableSysMdbTopMemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopMemInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopMemInfoIteratorByDataDelete(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopMemInfoIteratorByDataDelete *alloc(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbTopMemInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopMemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopMemInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopMemInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIteratorByHostName是一个对进程信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIteratorByHostName: public CSysMdbTopProcessInfoIterator
{
	friend class CSysMdbTopProcessInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopProcessInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

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
	CWriteableSysMdbTopProcessInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbTopProcessInfoIteratorByHostName(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbTopProcessInfoIteratorByHostName *alloc(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbTopProcessInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopProcessInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopProcessInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIteratorByDsc是一个对进程信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIteratorByDsc: public CSysMdbTopProcessInfoIterator
{
	friend class CSysMdbTopProcessInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopProcessInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

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
	CWriteableSysMdbTopProcessInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CSysMdbTopProcessInfoIteratorByDsc(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CSysMdbTopProcessInfoIteratorByDsc *alloc(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///构造方法
	CSysMdbTopProcessInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CSysMdbTopProcessInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopProcessInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopProcessInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIteratorBytheAll是一个对进程信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIteratorBytheAll: public CSysMdbTopProcessInfoIterator
{
	friend class CSysMdbTopProcessInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTopProcessInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);

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
	CWriteableSysMdbTopProcessInfo m_compareObject;
	
	static CMemoryStack<CSysMdbTopProcessInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbTopProcessInfoIteratorBytheAll(CSysMdbTopProcessInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbTopProcessInfoIteratorBytheAll *alloc(CSysMdbTopProcessInfoFactory *pFactory
		);

	///构造方法
	CSysMdbTopProcessInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbTopProcessInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTopProcessInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTopProcessInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIteratorByHostName是一个对文件系统信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIteratorByHostName: public CSysMdbFileSystemInfoIterator
{
	friend class CSysMdbFileSystemInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbFileSystemInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

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
	CWriteableSysMdbFileSystemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbFileSystemInfoIteratorByHostName(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,HostName,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbFileSystemInfoIteratorByHostName *alloc(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbFileSystemInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbFileSystemInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbFileSystemInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIteratorByDsc是一个对文件系统信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIteratorByDsc: public CSysMdbFileSystemInfoIterator
{
	friend class CSysMdbFileSystemInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbFileSystemInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

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
	CWriteableSysMdbFileSystemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	CSysMdbFileSystemInfoIteratorByDsc(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName)
	{
		init(pFactory,HostName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	static CSysMdbFileSystemInfoIteratorByDsc *alloc(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///构造方法
	CSysMdbFileSystemInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	HostName	
	void init(CSysMdbFileSystemInfoFactory *pFactory
		,const CReadOnlyVolumeType& HostName);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbFileSystemInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbFileSystemInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIteratorBytheAll是一个对文件系统信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIteratorBytheAll: public CSysMdbFileSystemInfoIterator
{
	friend class CSysMdbFileSystemInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbFileSystemInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);

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
	CWriteableSysMdbFileSystemInfo m_compareObject;
	
	static CMemoryStack<CSysMdbFileSystemInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbFileSystemInfoIteratorBytheAll(CSysMdbFileSystemInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbFileSystemInfoIteratorBytheAll *alloc(CSysMdbFileSystemInfoFactory *pFactory
		);

	///构造方法
	CSysMdbFileSystemInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbFileSystemInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbFileSystemInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbFileSystemInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorByHostName是一个对网络使用信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorByHostName: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbNetworkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbNetworkInfoIteratorByHostName(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbNetworkInfoIteratorByHostName *alloc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbNetworkInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetworkInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorByDsc是一个对网络使用信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorByDsc: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbNetworkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbNetworkInfoIteratorByDsc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbNetworkInfoIteratorByDsc *alloc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbNetworkInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetworkInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorBytheAll是一个对网络使用信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorBytheAll: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbNetworkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbNetworkInfoIteratorBytheAll(CSysMdbNetworkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbNetworkInfoIteratorBytheAll *alloc(CSysMdbNetworkInfoFactory *pFactory
		);

	///构造方法
	CSysMdbNetworkInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbNetworkInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetworkInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIteratorByDataDelete是一个对网络使用信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIteratorByDataDelete: public CSysMdbNetworkInfoIterator
{
	friend class CSysMdbNetworkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbNetworkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbNetworkInfo *pSysMdbNetworkInfo);

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
	CWriteableSysMdbNetworkInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetworkInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbNetworkInfoIteratorByDataDelete(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbNetworkInfoIteratorByDataDelete *alloc(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbNetworkInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbNetworkInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetworkInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbNetworkInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitIteratorByAll是一个对会员使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitIteratorByAll: public CSysParticipantInitIterator
{
	friend class CSysParticipantInitFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysParticipantInit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysParticipantInit *pSysParticipantInit);

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
	CWriteableSysParticipantInit m_compareObject;
	
	static CMemoryStack<CSysParticipantInitIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysParticipantInitIteratorByAll(CSysParticipantInitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysParticipantInitIteratorByAll *alloc(CSysParticipantInitFactory *pFactory
		);

	///构造方法
	CSysParticipantInitIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysParticipantInitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticipantInitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysParticipantInit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysParticipantInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitIteratorByAll是一个对交易用户使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitIteratorByAll: public CSysUserInitIterator
{
	friend class CSysUserInitFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysUserInit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysUserInit *pSysUserInit);

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
	CWriteableSysUserInit m_compareObject;
	
	static CMemoryStack<CSysUserInitIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysUserInitIteratorByAll(CSysUserInitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysUserInitIteratorByAll *alloc(CSysUserInitFactory *pFactory
		);

	///构造方法
	CSysUserInitIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysUserInitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysUserInitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysUserInit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysUserInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitIteratorByAll是一个对客户使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitIteratorByAll: public CSysClientInitIterator
{
	friend class CSysClientInitFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysClientInit		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysClientInit *pSysClientInit);

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
	CWriteableSysClientInit m_compareObject;
	
	static CMemoryStack<CSysClientInitIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysClientInitIteratorByAll(CSysClientInitFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysClientInitIteratorByAll *alloc(CSysClientInitFactory *pFactory
		);

	///构造方法
	CSysClientInitIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysClientInitFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysClientInitIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysClientInit，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysClientInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientInit * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoIteratorByAll是一个对交易系统登录信息使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoIteratorByAll: public CSysTradeUserLoginInfoIterator
{
	friend class CSysTradeUserLoginInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysTradeUserLoginInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);

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
	CWriteableSysTradeUserLoginInfo m_compareObject;
	
	static CMemoryStack<CSysTradeUserLoginInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysTradeUserLoginInfoIteratorByAll(CSysTradeUserLoginInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysTradeUserLoginInfoIteratorByAll *alloc(CSysTradeUserLoginInfoFactory *pFactory
		);

	///构造方法
	CSysTradeUserLoginInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysTradeUserLoginInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysTradeUserLoginInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysTradeUserLoginInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysTradeUserLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorByIDType是一个对Web应用信息使用ByIDType方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorByIDType: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbWebAppInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorByIDType> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbWebAppInfoIteratorByIDType(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbWebAppInfoIteratorByIDType *alloc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbWebAppInfoIteratorByIDType(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbWebAppInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorByDsc是一个对Web应用信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorByDsc: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbWebAppInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	CSysMdbWebAppInfoIteratorByDsc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	static CSysMdbWebAppInfoIteratorByDsc *alloc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///构造方法
	CSysMdbWebAppInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	void init(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbWebAppInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorBytheAll是一个对Web应用信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorBytheAll: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbWebAppInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbWebAppInfoIteratorBytheAll(CSysMdbWebAppInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbWebAppInfoIteratorBytheAll *alloc(CSysMdbWebAppInfoFactory *pFactory
		);

	///构造方法
	CSysMdbWebAppInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbWebAppInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbWebAppInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIteratorByDataDelete是一个对Web应用信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIteratorByDataDelete: public CSysMdbWebAppInfoIterator
{
	friend class CSysMdbWebAppInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbWebAppInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbWebAppInfo *pSysMdbWebAppInfo);

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
	CWriteableSysMdbWebAppInfo m_compareObject;
	
	static CMemoryStack<CSysMdbWebAppInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbWebAppInfoIteratorByDataDelete(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbWebAppInfoIteratorByDataDelete *alloc(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbWebAppInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbWebAppInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbWebAppInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbWebAppInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorByIDType是一个对系统内存池信息使用ByIDType方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorByIDType: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbMemPoolInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorByIDType> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbMemPoolInfoIteratorByIDType(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbMemPoolInfoIteratorByIDType *alloc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbMemPoolInfoIteratorByIDType(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbMemPoolInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorByDsc是一个对系统内存池信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorByDsc: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbMemPoolInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	CSysMdbMemPoolInfoIteratorByDsc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	static CSysMdbMemPoolInfoIteratorByDsc *alloc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///构造方法
	CSysMdbMemPoolInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	void init(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbMemPoolInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorBytheAll是一个对系统内存池信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorBytheAll: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbMemPoolInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbMemPoolInfoIteratorBytheAll(CSysMdbMemPoolInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbMemPoolInfoIteratorBytheAll *alloc(CSysMdbMemPoolInfoFactory *pFactory
		);

	///构造方法
	CSysMdbMemPoolInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbMemPoolInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbMemPoolInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIteratorByDataDelete是一个对系统内存池信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIteratorByDataDelete: public CSysMdbMemPoolInfoIterator
{
	friend class CSysMdbMemPoolInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbMemPoolInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);

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
	CWriteableSysMdbMemPoolInfo m_compareObject;
	
	static CMemoryStack<CSysMdbMemPoolInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbMemPoolInfoIteratorByDataDelete(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbMemPoolInfoIteratorByDataDelete *alloc(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbMemPoolInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbMemPoolInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbMemPoolInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbMemPoolInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorByIDType是一个对连接器信息使用ByIDType方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorByIDType: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbConnectorInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorByIDType> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbConnectorInfoIteratorByIDType(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbConnectorInfoIteratorByIDType *alloc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbConnectorInfoIteratorByIDType(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbConnectorInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorByDsc是一个对连接器信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorByDsc: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbConnectorInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	CSysMdbConnectorInfoIteratorByDsc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	static CSysMdbConnectorInfoIteratorByDsc *alloc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///构造方法
	CSysMdbConnectorInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	void init(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbConnectorInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorBytheAll是一个对连接器信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorBytheAll: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbConnectorInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbConnectorInfoIteratorBytheAll(CSysMdbConnectorInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbConnectorInfoIteratorBytheAll *alloc(CSysMdbConnectorInfoFactory *pFactory
		);

	///构造方法
	CSysMdbConnectorInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbConnectorInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbConnectorInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIteratorByDataDelete是一个对连接器信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIteratorByDataDelete: public CSysMdbConnectorInfoIterator
{
	friend class CSysMdbConnectorInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbConnectorInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbConnectorInfo *pSysMdbConnectorInfo);

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
	CWriteableSysMdbConnectorInfo m_compareObject;
	
	static CMemoryStack<CSysMdbConnectorInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbConnectorInfoIteratorByDataDelete(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbConnectorInfoIteratorByDataDelete *alloc(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbConnectorInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbConnectorInfoFactory *pFactory
		,const CReadOnlyVolumeType& ObjectID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbConnectorInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbConnectorInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorByIDType是一个对数据库查询应答使用ByIDType方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorByIDType: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDBQuery		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorByIDType> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDBQueryIteratorByIDType(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDBQueryIteratorByIDType *alloc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbDBQueryIteratorByIDType(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDBQueryIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorByDsc是一个对数据库查询应答使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorByDsc: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDBQuery		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbDBQueryIteratorByDsc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbDBQueryIteratorByDsc *alloc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbDBQueryIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDBQueryIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorBytheAll是一个对数据库查询应答使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorBytheAll: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDBQuery		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbDBQueryIteratorBytheAll(CSysMdbDBQueryFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbDBQueryIteratorBytheAll *alloc(CSysMdbDBQueryFactory *pFactory
		);

	///构造方法
	CSysMdbDBQueryIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbDBQueryFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDBQueryIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIteratorByDataDelete是一个对数据库查询应答使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIteratorByDataDelete: public CSysMdbDBQueryIterator
{
	friend class CSysMdbDBQueryFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDBQuery		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDBQuery *pSysMdbDBQuery);

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
	CWriteableSysMdbDBQuery m_compareObject;
	
	static CMemoryStack<CSysMdbDBQueryIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDBQueryIteratorByDataDelete(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDBQueryIteratorByDataDelete *alloc(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbDBQueryIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDBQueryFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDBQueryIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDBQuery，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaIteratorByAll是一个对网络大区划分使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaIteratorByAll: public CSysNetAreaIterator
{
	friend class CSysNetAreaFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetArea		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetArea *pSysNetArea);

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
	CWriteableSysNetArea m_compareObject;
	
	static CMemoryStack<CSysNetAreaIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetAreaIteratorByAll(CSysNetAreaFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetAreaIteratorByAll *alloc(CSysNetAreaFactory *pFactory
		);

	///构造方法
	CSysNetAreaIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetAreaFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetAreaIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetArea，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetArea * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIteratorByAll是一个对网络子区使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIteratorByAll: public CSysNetSubAreaIterator
{
	friend class CSysNetSubAreaFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetSubArea		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetSubArea *pSysNetSubArea);

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
	CWriteableSysNetSubArea m_compareObject;
	
	static CMemoryStack<CSysNetSubAreaIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetSubAreaIteratorByAll(CSysNetSubAreaFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetSubAreaIteratorByAll *alloc(CSysNetSubAreaFactory *pFactory
		);

	///构造方法
	CSysNetSubAreaIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetSubAreaFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubAreaIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetSubArea，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetSubArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPIteratorByAll是一个对网络子区IP使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPIteratorByAll: public CSysNetSubAreaIPIterator
{
	friend class CSysNetSubAreaIPFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetSubAreaIP		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetSubAreaIP *pSysNetSubAreaIP);

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
	CWriteableSysNetSubAreaIP m_compareObject;
	
	static CMemoryStack<CSysNetSubAreaIPIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetSubAreaIPIteratorByAll(CSysNetSubAreaIPFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetSubAreaIPIteratorByAll *alloc(CSysNetSubAreaIPFactory *pFactory
		);

	///构造方法
	CSysNetSubAreaIPIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetSubAreaIPFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubAreaIPIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetSubAreaIP，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetSubAreaIP，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaIteratorByAll是一个对职能区使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaIteratorByAll: public CSysNetFuncAreaIterator
{
	friend class CSysNetFuncAreaFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetFuncArea		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetFuncArea *pSysNetFuncArea);

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
	CWriteableSysNetFuncArea m_compareObject;
	
	static CMemoryStack<CSysNetFuncAreaIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetFuncAreaIteratorByAll(CSysNetFuncAreaFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetFuncAreaIteratorByAll *alloc(CSysNetFuncAreaFactory *pFactory
		);

	///构造方法
	CSysNetFuncAreaIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetFuncAreaFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetFuncAreaIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetFuncArea，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetFuncArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetFuncArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIteratorByAll是一个对网络设备使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIteratorByAll: public CSysNetDeviceIterator
{
	friend class CSysNetDeviceFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDevice		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDevice *pSysNetDevice);

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
	CWriteableSysNetDevice m_compareObject;
	
	static CMemoryStack<CSysNetDeviceIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetDeviceIteratorByAll(CSysNetDeviceFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetDeviceIteratorByAll *alloc(CSysNetDeviceFactory *pFactory
		);

	///构造方法
	CSysNetDeviceIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetDeviceFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDevice，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDevice *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDevice * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIteratorByIPDECODE是一个对网络设备使用ByIPDECODE方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIteratorByIPDECODE: public CSysNetDeviceIterator
{
	friend class CSysNetDeviceFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDevice		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDevice *pSysNetDevice);

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
	CWriteableSysNetDevice m_compareObject;
	
	static CMemoryStack<CSysNetDeviceIteratorByIPDECODE> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	IPDECODE	
	CSysNetDeviceIteratorByIPDECODE(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& IPDECODE)
	{
		init(pFactory,IPDECODE);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	IPDECODE	
	static CSysNetDeviceIteratorByIPDECODE *alloc(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& IPDECODE);

	///构造方法
	CSysNetDeviceIteratorByIPDECODE(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	IPDECODE	
	void init(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& IPDECODE);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceIteratorByIPDECODE(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDevice，必须在startFindByIPDECODE以后，endFindByIPDECODE之前叫用
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDevice *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIPDECODE 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDevice * pByIPDECODE,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIteratorBySubAreaID是一个对网络设备使用BySubAreaID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIteratorBySubAreaID: public CSysNetDeviceIterator
{
	friend class CSysNetDeviceFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDevice		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDevice *pSysNetDevice);

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
	CWriteableSysNetDevice m_compareObject;
	
	static CMemoryStack<CSysNetDeviceIteratorBySubAreaID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SysNetSubAreaID	
	CSysNetDeviceIteratorBySubAreaID(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& SysNetSubAreaID)
	{
		init(pFactory,SysNetSubAreaID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SysNetSubAreaID	
	static CSysNetDeviceIteratorBySubAreaID *alloc(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& SysNetSubAreaID);

	///构造方法
	CSysNetDeviceIteratorBySubAreaID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SysNetSubAreaID	
	void init(CSysNetDeviceFactory *pFactory
		,const CReadOnlyVolumeType& SysNetSubAreaID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceIteratorBySubAreaID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDevice，必须在startFindBySubAreaID以后，endFindBySubAreaID之前叫用
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDevice *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBySubAreaID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDevice * pBySubAreaID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIteratorByAll是一个对网络设备连接关系使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIteratorByAll: public CSysNetDeviceLinkedIterator
{
	friend class CSysNetDeviceLinkedFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDeviceLinked		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDeviceLinked *pSysNetDeviceLinked);

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
	CWriteableSysNetDeviceLinked m_compareObject;
	
	static CMemoryStack<CSysNetDeviceLinkedIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetDeviceLinkedIteratorByAll(CSysNetDeviceLinkedFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetDeviceLinkedIteratorByAll *alloc(CSysNetDeviceLinkedFactory *pFactory
		);

	///构造方法
	CSysNetDeviceLinkedIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetDeviceLinkedFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceLinkedIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDeviceLinked，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIteratorByNetObjectID是一个对网络设备连接关系使用ByNetObjectID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIteratorByNetObjectID: public CSysNetDeviceLinkedIterator
{
	friend class CSysNetDeviceLinkedFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDeviceLinked		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDeviceLinked *pSysNetDeviceLinked);

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
	CWriteableSysNetDeviceLinked m_compareObject;
	
	static CMemoryStack<CSysNetDeviceLinkedIteratorByNetObjectID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	NetObjectID	
	CSysNetDeviceLinkedIteratorByNetObjectID(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& NetObjectID)
	{
		init(pFactory,NetObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	NetObjectID	
	static CSysNetDeviceLinkedIteratorByNetObjectID *alloc(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& NetObjectID);

	///构造方法
	CSysNetDeviceLinkedIteratorByNetObjectID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	NetObjectID	
	void init(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& NetObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceLinkedIteratorByNetObjectID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDeviceLinked，必须在startFindByNetObjectID以后，endFindByNetObjectID之前叫用
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByNetObjectID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pByNetObjectID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIteratorByLinkNetObjectID是一个对网络设备连接关系使用ByLinkNetObjectID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIteratorByLinkNetObjectID: public CSysNetDeviceLinkedIterator
{
	friend class CSysNetDeviceLinkedFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDeviceLinked		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDeviceLinked *pSysNetDeviceLinked);

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
	CWriteableSysNetDeviceLinked m_compareObject;
	
	static CMemoryStack<CSysNetDeviceLinkedIteratorByLinkNetObjectID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	LinkNetObjectID	
	CSysNetDeviceLinkedIteratorByLinkNetObjectID(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& LinkNetObjectID)
	{
		init(pFactory,LinkNetObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	LinkNetObjectID	
	static CSysNetDeviceLinkedIteratorByLinkNetObjectID *alloc(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& LinkNetObjectID);

	///构造方法
	CSysNetDeviceLinkedIteratorByLinkNetObjectID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	LinkNetObjectID	
	void init(CSysNetDeviceLinkedFactory *pFactory
		,const CReadOnlyNetObjectIDType& LinkNetObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceLinkedIteratorByLinkNetObjectID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDeviceLinked，必须在startFindByLinkNetObjectID以后，endFindByLinkNetObjectID之前叫用
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByLinkNetObjectID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pByLinkNetObjectID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDIteratorByAll是一个对OID使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDIteratorByAll: public CSysNetOIDIterator
{
	friend class CSysNetOIDFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetOID		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetOID *pSysNetOID);

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
	CWriteableSysNetOID m_compareObject;
	
	static CMemoryStack<CSysNetOIDIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetOIDIteratorByAll(CSysNetOIDFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetOIDIteratorByAll *alloc(CSysNetOIDFactory *pFactory
		);

	///构造方法
	CSysNetOIDIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetOIDFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetOIDIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetOID，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOID * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeIteratorByAll是一个对网络设备类型使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeIteratorByAll: public CSysNetDeviceTypeIterator
{
	friend class CSysNetDeviceTypeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDeviceType		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDeviceType *pSysNetDeviceType);

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
	CWriteableSysNetDeviceType m_compareObject;
	
	static CMemoryStack<CSysNetDeviceTypeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetDeviceTypeIteratorByAll(CSysNetDeviceTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetDeviceTypeIteratorByAll *alloc(CSysNetDeviceTypeFactory *pFactory
		);

	///构造方法
	CSysNetDeviceTypeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetDeviceTypeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDeviceType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDeviceType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyIteratorByAll是一个对时间策略使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyIteratorByAll: public CSysNetTimePolicyIterator
{
	friend class CSysNetTimePolicyFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetTimePolicy		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetTimePolicy *pSysNetTimePolicy);

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
	CWriteableSysNetTimePolicy m_compareObject;
	
	static CMemoryStack<CSysNetTimePolicyIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetTimePolicyIteratorByAll(CSysNetTimePolicyFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetTimePolicyIteratorByAll *alloc(CSysNetTimePolicyFactory *pFactory
		);

	///构造方法
	CSysNetTimePolicyIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetTimePolicyFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetTimePolicyIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetTimePolicy，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetTimePolicy，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetTimePolicy *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskIteratorByAll是一个对采集任务使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskIteratorByAll: public CSysNetGatherTaskIterator
{
	friend class CSysNetGatherTaskFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetGatherTask		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetGatherTask *pSysNetGatherTask);

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
	CWriteableSysNetGatherTask m_compareObject;
	
	static CMemoryStack<CSysNetGatherTaskIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetGatherTaskIteratorByAll(CSysNetGatherTaskFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetGatherTaskIteratorByAll *alloc(CSysNetGatherTaskFactory *pFactory
		);

	///构造方法
	CSysNetGatherTaskIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetGatherTaskFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetGatherTaskIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetGatherTask，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGatherTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskIteratorByNetObjectID是一个对采集任务使用ByNetObjectID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskIteratorByNetObjectID: public CSysNetGatherTaskIterator
{
	friend class CSysNetGatherTaskFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetGatherTask		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetGatherTask *pSysNetGatherTask);

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
	CWriteableSysNetGatherTask m_compareObject;
	
	static CMemoryStack<CSysNetGatherTaskIteratorByNetObjectID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	CSysNetGatherTaskIteratorByNetObjectID(CSysNetGatherTaskFactory *pFactory
		,const CReadOnlyNetObjectIDType& ObjectID)
	{
		init(pFactory,ObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	static CSysNetGatherTaskIteratorByNetObjectID *alloc(CSysNetGatherTaskFactory *pFactory
		,const CReadOnlyNetObjectIDType& ObjectID);

	///构造方法
	CSysNetGatherTaskIteratorByNetObjectID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	void init(CSysNetGatherTaskFactory *pFactory
		,const CReadOnlyNetObjectIDType& ObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetGatherTaskIteratorByNetObjectID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetGatherTask，必须在startFindByNetObjectID以后，endFindByNetObjectID之前叫用
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGatherTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByNetObjectID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pByNetObjectID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryIteratorByAll是一个对常用设备类别使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryIteratorByAll: public CSysNetDeviceCategoryIterator
{
	friend class CSysNetDeviceCategoryFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDeviceCategory		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDeviceCategory *pSysNetDeviceCategory);

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
	CWriteableSysNetDeviceCategory m_compareObject;
	
	static CMemoryStack<CSysNetDeviceCategoryIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetDeviceCategoryIteratorByAll(CSysNetDeviceCategoryFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetDeviceCategoryIteratorByAll *alloc(CSysNetDeviceCategoryFactory *pFactory
		);

	///构造方法
	CSysNetDeviceCategoryIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetDeviceCategoryFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDeviceCategoryIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDeviceCategory，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDeviceCategory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryIteratorByAll是一个对设备厂商使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryIteratorByAll: public CSysNetManufactoryIterator
{
	friend class CSysNetManufactoryFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetManufactory		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetManufactory *pSysNetManufactory);

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
	CWriteableSysNetManufactory m_compareObject;
	
	static CMemoryStack<CSysNetManufactoryIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetManufactoryIteratorByAll(CSysNetManufactoryFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetManufactoryIteratorByAll *alloc(CSysNetManufactoryFactory *pFactory
		);

	///构造方法
	CSysNetManufactoryIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetManufactoryFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetManufactoryIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetManufactory，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetManufactory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetManufactory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityIteratorByAll是一个对设备共同体使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityIteratorByAll: public CSysNetCommunityIterator
{
	friend class CSysNetCommunityFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetCommunity		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetCommunity *pSysNetCommunity);

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
	CWriteableSysNetCommunity m_compareObject;
	
	static CMemoryStack<CSysNetCommunityIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetCommunityIteratorByAll(CSysNetCommunityFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetCommunityIteratorByAll *alloc(CSysNetCommunityFactory *pFactory
		);

	///构造方法
	CSysNetCommunityIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetCommunityFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetCommunityIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetCommunity，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetCommunity，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetCommunity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeIteratorByAll是一个对端口类型使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeIteratorByAll: public CSysNetPortTypeIterator
{
	friend class CSysNetPortTypeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetPortType		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetPortType *pSysNetPortType);

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
	CWriteableSysNetPortType m_compareObject;
	
	static CMemoryStack<CSysNetPortTypeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetPortTypeIteratorByAll(CSysNetPortTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetPortTypeIteratorByAll *alloc(CSysNetPortTypeFactory *pFactory
		);

	///构造方法
	CSysNetPortTypeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetPortTypeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPortTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetPortType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPortType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPortType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPortType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceIteratorByAll是一个对端口使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceIteratorByAll: public CSysNetInterfaceIterator
{
	friend class CSysNetInterfaceFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetInterface		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetInterface *pSysNetInterface);

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
	CWriteableSysNetInterface m_compareObject;
	
	static CMemoryStack<CSysNetInterfaceIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetInterfaceIteratorByAll(CSysNetInterfaceFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetInterfaceIteratorByAll *alloc(CSysNetInterfaceFactory *pFactory
		);

	///构造方法
	CSysNetInterfaceIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetInterfaceFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetInterfaceIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetInterface，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetInterface *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetInterface * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceIteratorByDeviceID是一个对端口使用ByDeviceID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceIteratorByDeviceID: public CSysNetInterfaceIterator
{
	friend class CSysNetInterfaceFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetInterface		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetInterface *pSysNetInterface);

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
	CWriteableSysNetInterface m_compareObject;
	
	static CMemoryStack<CSysNetInterfaceIteratorByDeviceID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceID	
	CSysNetInterfaceIteratorByDeviceID(CSysNetInterfaceFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID)
	{
		init(pFactory,DeviceID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceID	
	static CSysNetInterfaceIteratorByDeviceID *alloc(CSysNetInterfaceFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///构造方法
	CSysNetInterfaceIteratorByDeviceID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceID	
	void init(CSysNetInterfaceFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetInterfaceIteratorByDeviceID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetInterface，必须在startFindByDeviceID以后，endFindByDeviceID之前叫用
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetInterface *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDeviceID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetInterface * pByDeviceID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDIteratorByAll是一个对通用OID使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDIteratorByAll: public CSysNetGeneralOIDIterator
{
	friend class CSysNetGeneralOIDFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetGeneralOID		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetGeneralOID *pSysNetGeneralOID);

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
	CWriteableSysNetGeneralOID m_compareObject;
	
	static CMemoryStack<CSysNetGeneralOIDIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetGeneralOIDIteratorByAll(CSysNetGeneralOIDFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetGeneralOIDIteratorByAll *alloc(CSysNetGeneralOIDFactory *pFactory
		);

	///构造方法
	CSysNetGeneralOIDIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetGeneralOIDFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetGeneralOIDIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetGeneralOID，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetGeneralOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGeneralOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeIteratorByAll是一个对监控对象类别使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeIteratorByAll: public CSysNetMonitorTypeIterator
{
	friend class CSysNetMonitorTypeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorType		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorType *pSysNetMonitorType);

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
	CWriteableSysNetMonitorType m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTypeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorTypeIteratorByAll(CSysNetMonitorTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorTypeIteratorByAll *alloc(CSysNetMonitorTypeFactory *pFactory
		);

	///构造方法
	CSysNetMonitorTypeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorTypeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeIteratorByAll是一个对指标统表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeIteratorByAll: public CSysNetMonitorAttrScopeIterator
{
	friend class CSysNetMonitorAttrScopeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorAttrScope		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);

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
	CWriteableSysNetMonitorAttrScope m_compareObject;
	
	static CMemoryStack<CSysNetMonitorAttrScopeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorAttrScopeIteratorByAll(CSysNetMonitorAttrScopeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorAttrScopeIteratorByAll *alloc(CSysNetMonitorAttrScopeFactory *pFactory
		);

	///构造方法
	CSysNetMonitorAttrScopeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorAttrScopeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorAttrScopeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorAttrScope，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorAttrScope，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeIteratorByAll是一个对监控指标表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeIteratorByAll: public CSysNetMonitorAttrTypeIterator
{
	friend class CSysNetMonitorAttrTypeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorAttrType		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorAttrType *pSysNetMonitorAttrType);

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
	CWriteableSysNetMonitorAttrType m_compareObject;
	
	static CMemoryStack<CSysNetMonitorAttrTypeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorAttrTypeIteratorByAll(CSysNetMonitorAttrTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorAttrTypeIteratorByAll *alloc(CSysNetMonitorAttrTypeFactory *pFactory
		);

	///构造方法
	CSysNetMonitorAttrTypeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorAttrTypeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorAttrTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorAttrType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorAttrType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeIteratorByAll是一个对监控指令表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeIteratorByAll: public CSysNetMonitorCommandTypeIterator
{
	friend class CSysNetMonitorCommandTypeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorCommandType		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorCommandType *pSysNetMonitorCommandType);

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
	CWriteableSysNetMonitorCommandType m_compareObject;
	
	static CMemoryStack<CSysNetMonitorCommandTypeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorCommandTypeIteratorByAll(CSysNetMonitorCommandTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorCommandTypeIteratorByAll *alloc(CSysNetMonitorCommandTypeFactory *pFactory
		);

	///构造方法
	CSysNetMonitorCommandTypeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorCommandTypeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorCommandTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorCommandType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorCommandType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupIteratorByAll是一个对动作族表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupIteratorByAll: public CSysNetMonitorActionGroupIterator
{
	friend class CSysNetMonitorActionGroupFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorActionGroup		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);

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
	CWriteableSysNetMonitorActionGroup m_compareObject;
	
	static CMemoryStack<CSysNetMonitorActionGroupIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorActionGroupIteratorByAll(CSysNetMonitorActionGroupFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorActionGroupIteratorByAll *alloc(CSysNetMonitorActionGroupFactory *pFactory
		);

	///构造方法
	CSysNetMonitorActionGroupIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorActionGroupFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorActionGroupIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorActionGroup，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorActionGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupIteratorByAll是一个对设备对象组表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupIteratorByAll: public CSysNetMonitorDeviceGroupIterator
{
	friend class CSysNetMonitorDeviceGroupFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorDeviceGroup		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);

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
	CWriteableSysNetMonitorDeviceGroup m_compareObject;
	
	static CMemoryStack<CSysNetMonitorDeviceGroupIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorDeviceGroupIteratorByAll(CSysNetMonitorDeviceGroupFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorDeviceGroupIteratorByAll *alloc(CSysNetMonitorDeviceGroupFactory *pFactory
		);

	///构造方法
	CSysNetMonitorDeviceGroupIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorDeviceGroupFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorDeviceGroupIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorDeviceGroup，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorDeviceGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoIteratorByAll是一个对任务信息表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoIteratorByAll: public CSysNetMonitorTaskInfoIterator
{
	friend class CSysNetMonitorTaskInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);

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
	CWriteableSysNetMonitorTaskInfo m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorTaskInfoIteratorByAll(CSysNetMonitorTaskInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorTaskInfoIteratorByAll *alloc(CSysNetMonitorTaskInfoFactory *pFactory
		);

	///构造方法
	CSysNetMonitorTaskInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorTaskInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetIteratorByAll是一个对任务对象集使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetIteratorByAll: public CSysNetMonitorTaskObjectSetIterator
{
	friend class CSysNetMonitorTaskObjectSetFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskObjectSet		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);

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
	CWriteableSysNetMonitorTaskObjectSet m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskObjectSetIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorTaskObjectSetIteratorByAll(CSysNetMonitorTaskObjectSetFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorTaskObjectSetIteratorByAll *alloc(CSysNetMonitorTaskObjectSetFactory *pFactory
		);

	///构造方法
	CSysNetMonitorTaskObjectSetIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorTaskObjectSetFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskObjectSetIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskObjectSet，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID是一个对任务对象集使用ByDeviceGroup_ID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID: public CSysNetMonitorTaskObjectSetIterator
{
	friend class CSysNetMonitorTaskObjectSetFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskObjectSet		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);

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
	CWriteableSysNetMonitorTaskObjectSet m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceGroup_ID	
	CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID(CSysNetMonitorTaskObjectSetFactory *pFactory
		,const CReadOnlyVolumeType& DeviceGroup_ID)
	{
		init(pFactory,DeviceGroup_ID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceGroup_ID	
	static CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID *alloc(CSysNetMonitorTaskObjectSetFactory *pFactory
		,const CReadOnlyVolumeType& DeviceGroup_ID);

	///构造方法
	CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceGroup_ID	
	void init(CSysNetMonitorTaskObjectSetFactory *pFactory
		,const CReadOnlyVolumeType& DeviceGroup_ID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskObjectSetIteratorByDeviceGroup_ID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskObjectSet，必须在startFindByDeviceGroup_ID以后，endFindByDeviceGroup_ID之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDeviceGroup_ID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pByDeviceGroup_ID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByAll是一个对任务结果表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByAll: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskResult		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorTaskResultIteratorByAll(CSysNetMonitorTaskResultFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorTaskResultIteratorByAll *alloc(CSysNetMonitorTaskResultFactory *pFactory
		);

	///构造方法
	CSysNetMonitorTaskResultIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorTaskResultFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskResultIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByTask_ID是一个对任务结果表使用ByTask_ID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByTask_ID: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskResult		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByTask_ID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	CSysNetMonitorTaskResultIteratorByTask_ID(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID)
	{
		init(pFactory,MonDate,Task_ID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	static CSysNetMonitorTaskResultIteratorByTask_ID *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID);

	///构造方法
	CSysNetMonitorTaskResultIteratorByTask_ID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskResultIteratorByTask_ID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByTask_ID以后，endFindByTask_ID之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTask_ID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByTask_ID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByOnlyDate是一个对任务结果表使用ByOnlyDate方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByOnlyDate: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskResult		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByOnlyDate> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	CSysNetMonitorTaskResultIteratorByOnlyDate(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate)
	{
		init(pFactory,MonDate);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	static CSysNetMonitorTaskResultIteratorByOnlyDate *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate);

	///构造方法
	CSysNetMonitorTaskResultIteratorByOnlyDate(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskResultIteratorByOnlyDate(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByOnlyDate以后，endFindByOnlyDate之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByOnlyDate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByOnlyDate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByIDTaskTime是一个对任务结果表使用ByIDTaskTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByIDTaskTime: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskResult		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByIDTaskTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@param	OperateTime	
	CSysNetMonitorTaskResultIteratorByIDTaskTime(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID,const CReadOnlyVolumeType& OperateTime)
	{
		init(pFactory,MonDate,Task_ID,ObjectID,OperateTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@param	OperateTime	
	static CSysNetMonitorTaskResultIteratorByIDTaskTime *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID,const CReadOnlyVolumeType& OperateTime);

	///构造方法
	CSysNetMonitorTaskResultIteratorByIDTaskTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	///@param	OperateTime	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID,const CReadOnlyVolumeType& OperateTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskResultIteratorByIDTaskTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByIDTaskTime以后，endFindByIDTaskTime之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDTaskTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByIDTaskTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIteratorByDataDelete是一个对任务结果表使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIteratorByDataDelete: public CSysNetMonitorTaskResultIterator
{
	friend class CSysNetMonitorTaskResultFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskResult		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);

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
	CWriteableSysNetMonitorTaskResult m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskResultIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	CSysNetMonitorTaskResultIteratorByDataDelete(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID)
	{
		init(pFactory,MonDate,Task_ID,ObjectID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	static CSysNetMonitorTaskResultIteratorByDataDelete *alloc(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID);

	///构造方法
	CSysNetMonitorTaskResultIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	Task_ID	
	///@param	ObjectID	
	void init(CSysNetMonitorTaskResultFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyVolumeType& Task_ID,const CReadOnlyNetObjectIDType& ObjectID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskResultIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskResult，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoIteratorByAll是一个对会员链路信息表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoIteratorByAll: public CSysNetPartyLinkInfoIterator
{
	friend class CSysNetPartyLinkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetPartyLinkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);

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
	CWriteableSysNetPartyLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetPartyLinkInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetPartyLinkInfoIteratorByAll(CSysNetPartyLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetPartyLinkInfoIteratorByAll *alloc(CSysNetPartyLinkInfoFactory *pFactory
		);

	///构造方法
	CSysNetPartyLinkInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetPartyLinkInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartyLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetPartyLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoIteratorByAll是一个对会员链路信息表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoIteratorByAll: public CSysNetDelPartyLinkInfoIterator
{
	friend class CSysNetDelPartyLinkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDelPartyLinkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);

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
	CWriteableSysNetDelPartyLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetDelPartyLinkInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetDelPartyLinkInfoIteratorByAll(CSysNetDelPartyLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetDelPartyLinkInfoIteratorByAll *alloc(CSysNetDelPartyLinkInfoFactory *pFactory
		);

	///构造方法
	CSysNetDelPartyLinkInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetDelPartyLinkInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDelPartyLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDelPartyLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDelPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeIteratorByAll是一个对会员链路信息表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeIteratorByAll: public CSysNetPartyLinkAddrChangeIterator
{
	friend class CSysNetPartyLinkAddrChangeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetPartyLinkAddrChange		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);

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
	CWriteableSysNetPartyLinkAddrChange m_compareObject;
	
	static CMemoryStack<CSysNetPartyLinkAddrChangeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetPartyLinkAddrChangeIteratorByAll(CSysNetPartyLinkAddrChangeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetPartyLinkAddrChangeIteratorByAll *alloc(CSysNetPartyLinkAddrChangeFactory *pFactory
		);

	///构造方法
	CSysNetPartyLinkAddrChangeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetPartyLinkAddrChangeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartyLinkAddrChangeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetPartyLinkAddrChange，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPartyLinkAddrChange，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrIteratorByAll是一个对监控动作指标对照表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrIteratorByAll: public CSysNetMonitorActionAttrIterator
{
	friend class CSysNetMonitorActionAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorActionAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);

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
	CWriteableSysNetMonitorActionAttr m_compareObject;
	
	static CMemoryStack<CSysNetMonitorActionAttrIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorActionAttrIteratorByAll(CSysNetMonitorActionAttrFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorActionAttrIteratorByAll *alloc(CSysNetMonitorActionAttrFactory *pFactory
		);

	///构造方法
	CSysNetMonitorActionAttrIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorActionAttrFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorActionAttrIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorActionAttr，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorActionAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleIteratorByAll是一个对模块使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleIteratorByAll: public CSysNetModuleIterator
{
	friend class CSysNetModuleFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetModule		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetModule *pSysNetModule);

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
	CWriteableSysNetModule m_compareObject;
	
	static CMemoryStack<CSysNetModuleIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetModuleIteratorByAll(CSysNetModuleFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetModuleIteratorByAll *alloc(CSysNetModuleFactory *pFactory
		);

	///构造方法
	CSysNetModuleIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetModuleFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetModuleIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetModule，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetModule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetModule * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetModuleIteratorByDeviceID是一个对模块使用ByDeviceID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleIteratorByDeviceID: public CSysNetModuleIterator
{
	friend class CSysNetModuleFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetModule		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetModule *pSysNetModule);

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
	CWriteableSysNetModule m_compareObject;
	
	static CMemoryStack<CSysNetModuleIteratorByDeviceID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceID	
	CSysNetModuleIteratorByDeviceID(CSysNetModuleFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID)
	{
		init(pFactory,DeviceID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceID	
	static CSysNetModuleIteratorByDeviceID *alloc(CSysNetModuleFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///构造方法
	CSysNetModuleIteratorByDeviceID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	DeviceID	
	void init(CSysNetModuleFactory *pFactory
		,const CReadOnlyVolumeType& DeviceID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetModuleIteratorByDeviceID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetModule，必须在startFindByDeviceID以后，endFindByDeviceID之前叫用
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetModule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDeviceID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetModule * pByDeviceID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprIteratorByAll是一个对告警表达式信息表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprIteratorByAll: public CSysNetEventExprIterator
{
	friend class CSysNetEventExprFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetEventExpr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetEventExpr *pSysNetEventExpr);

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
	CWriteableSysNetEventExpr m_compareObject;
	
	static CMemoryStack<CSysNetEventExprIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetEventExprIteratorByAll(CSysNetEventExprFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetEventExprIteratorByAll *alloc(CSysNetEventExprFactory *pFactory
		);

	///构造方法
	CSysNetEventExprIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetEventExprFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventExprIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetEventExpr，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetEventExpr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventExpr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeIteratorByAll是一个对事件类型使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeIteratorByAll: public CSysNetEventTypeIterator
{
	friend class CSysNetEventTypeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetEventType		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetEventType *pSysNetEventType);

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
	CWriteableSysNetEventType m_compareObject;
	
	static CMemoryStack<CSysNetEventTypeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetEventTypeIteratorByAll(CSysNetEventTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetEventTypeIteratorByAll *alloc(CSysNetEventTypeFactory *pFactory
		);

	///构造方法
	CSysNetEventTypeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetEventTypeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetEventType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeIteratorByAll是一个对事件子类型使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeIteratorByAll: public CSysNetSubEventTypeIterator
{
	friend class CSysNetSubEventTypeFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetSubEventType		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetSubEventType *pSysNetSubEventType);

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
	CWriteableSysNetSubEventType m_compareObject;
	
	static CMemoryStack<CSysNetSubEventTypeIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetSubEventTypeIteratorByAll(CSysNetSubEventTypeFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetSubEventTypeIteratorByAll *alloc(CSysNetSubEventTypeFactory *pFactory
		);

	///构造方法
	CSysNetSubEventTypeIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetSubEventTypeFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetSubEventTypeIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetSubEventType，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetSubEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelIteratorByAll是一个对事件级别使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelIteratorByAll: public CSysNetEventLevelIterator
{
	friend class CSysNetEventLevelFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetEventLevel		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetEventLevel *pSysNetEventLevel);

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
	CWriteableSysNetEventLevel m_compareObject;
	
	static CMemoryStack<CSysNetEventLevelIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetEventLevelIteratorByAll(CSysNetEventLevelFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetEventLevelIteratorByAll *alloc(CSysNetEventLevelFactory *pFactory
		);

	///构造方法
	CSysNetEventLevelIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetEventLevelFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetEventLevelIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetEventLevel，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetEventLevel，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventLevel *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskIteratorByAll是一个对任务结果规则分析表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskIteratorByAll: public CSysNetMonitorDeviceTaskIterator
{
	friend class CSysNetMonitorDeviceTaskFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorDeviceTask		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);

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
	CWriteableSysNetMonitorDeviceTask m_compareObject;
	
	static CMemoryStack<CSysNetMonitorDeviceTaskIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorDeviceTaskIteratorByAll(CSysNetMonitorDeviceTaskFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorDeviceTaskIteratorByAll *alloc(CSysNetMonitorDeviceTaskFactory *pFactory
		);

	///构造方法
	CSysNetMonitorDeviceTaskIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorDeviceTaskFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorDeviceTaskIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorDeviceTask，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskIteratorByID是一个对任务结果规则分析表使用ByID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskIteratorByID: public CSysNetMonitorDeviceTaskIterator
{
	friend class CSysNetMonitorDeviceTaskFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorDeviceTask		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);

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
	CWriteableSysNetMonitorDeviceTask m_compareObject;
	
	static CMemoryStack<CSysNetMonitorDeviceTaskIteratorByID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	CSysNetMonitorDeviceTaskIteratorByID(CSysNetMonitorDeviceTaskFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	static CSysNetMonitorDeviceTaskIteratorByID *alloc(CSysNetMonitorDeviceTaskFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///构造方法
	CSysNetMonitorDeviceTaskIteratorByID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	void init(CSysNetMonitorDeviceTaskFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorDeviceTaskIteratorByID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorDeviceTask，必须在startFindByID以后，endFindByID之前叫用
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pByID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsIteratorByAll是一个对任务指令指标集表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsIteratorByAll: public CSysNetMonitorTaskInstAttrsIterator
{
	friend class CSysNetMonitorTaskInstAttrsFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMonitorTaskInstAttrs		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);

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
	CWriteableSysNetMonitorTaskInstAttrs m_compareObject;
	
	static CMemoryStack<CSysNetMonitorTaskInstAttrsIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMonitorTaskInstAttrsIteratorByAll(CSysNetMonitorTaskInstAttrsFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMonitorTaskInstAttrsIteratorByAll *alloc(CSysNetMonitorTaskInstAttrsFactory *pFactory
		);

	///构造方法
	CSysNetMonitorTaskInstAttrsIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMonitorTaskInstAttrsFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMonitorTaskInstAttrsIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMonitorTaskInstAttrs，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMonitorTaskInstAttrs，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineIteratorByAll是一个对基线表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineIteratorByAll: public CSysNetBaseLineIterator
{
	friend class CSysNetBaseLineFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetBaseLine		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetBaseLine *pSysNetBaseLine);

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
	CWriteableSysNetBaseLine m_compareObject;
	
	static CMemoryStack<CSysNetBaseLineIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetBaseLineIteratorByAll(CSysNetBaseLineFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetBaseLineIteratorByAll *alloc(CSysNetBaseLineFactory *pFactory
		);

	///构造方法
	CSysNetBaseLineIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetBaseLineFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetBaseLineIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetBaseLine，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineIteratorByID是一个对基线表使用ByID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineIteratorByID: public CSysNetBaseLineIterator
{
	friend class CSysNetBaseLineFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetBaseLine		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetBaseLine *pSysNetBaseLine);

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
	CWriteableSysNetBaseLine m_compareObject;
	
	static CMemoryStack<CSysNetBaseLineIteratorByID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	CSysNetBaseLineIteratorByID(CSysNetBaseLineFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	static CSysNetBaseLineIteratorByID *alloc(CSysNetBaseLineFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///构造方法
	CSysNetBaseLineIteratorByID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	void init(CSysNetBaseLineFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetBaseLineIteratorByID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetBaseLine，必须在startFindByID以后，endFindByID之前叫用
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pByID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskIteratorByAll是一个对基线任务表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskIteratorByAll: public CSysNetBaseLineTaskIterator
{
	friend class CSysNetBaseLineTaskFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetBaseLineTask		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetBaseLineTask *pSysNetBaseLineTask);

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
	CWriteableSysNetBaseLineTask m_compareObject;
	
	static CMemoryStack<CSysNetBaseLineTaskIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetBaseLineTaskIteratorByAll(CSysNetBaseLineTaskFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetBaseLineTaskIteratorByAll *alloc(CSysNetBaseLineTaskFactory *pFactory
		);

	///构造方法
	CSysNetBaseLineTaskIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetBaseLineTaskFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetBaseLineTaskIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetBaseLineTask，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetBaseLineTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIteratorByTime是一个对会员链路状态信息表使用ByTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIteratorByTime: public CSysMdbNetPartyLinkStatusInfoIterator
{
	friend class CSysMdbNetPartyLinkStatusInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbNetPartyLinkStatusInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

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
	CWriteableSysMdbNetPartyLinkStatusInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbNetPartyLinkStatusInfoIteratorByTime(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbNetPartyLinkStatusInfoIteratorByTime *alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbNetPartyLinkStatusInfoIteratorByTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetPartyLinkStatusInfoIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIteratorByDsc是一个对会员链路状态信息表使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIteratorByDsc: public CSysMdbNetPartyLinkStatusInfoIterator
{
	friend class CSysMdbNetPartyLinkStatusInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbNetPartyLinkStatusInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

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
	CWriteableSysMdbNetPartyLinkStatusInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbNetPartyLinkStatusInfoIteratorByDsc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbNetPartyLinkStatusInfoIteratorByDsc *alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbNetPartyLinkStatusInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetPartyLinkStatusInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIteratorByAll是一个对会员链路状态信息表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIteratorByAll: public CSysMdbNetPartyLinkStatusInfoIterator
{
	friend class CSysMdbNetPartyLinkStatusInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbNetPartyLinkStatusInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);

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
	CWriteableSysMdbNetPartyLinkStatusInfo m_compareObject;
	
	static CMemoryStack<CSysMdbNetPartyLinkStatusInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbNetPartyLinkStatusInfoIteratorByAll(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbNetPartyLinkStatusInfoIteratorByAll *alloc(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		);

	///构造方法
	CSysMdbNetPartyLinkStatusInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbNetPartyLinkStatusInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbNetPartyLinkStatusInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoIteratorByAll是一个对会员SDH线路明细表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoIteratorByAll: public CSysNetMemberSDHLineInfoIterator
{
	friend class CSysNetMemberSDHLineInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetMemberSDHLineInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);

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
	CWriteableSysNetMemberSDHLineInfo m_compareObject;
	
	static CMemoryStack<CSysNetMemberSDHLineInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetMemberSDHLineInfoIteratorByAll(CSysNetMemberSDHLineInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetMemberSDHLineInfoIteratorByAll *alloc(CSysNetMemberSDHLineInfoFactory *pFactory
		);

	///构造方法
	CSysNetMemberSDHLineInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetMemberSDHLineInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetMemberSDHLineInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetMemberSDHLineInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetMemberSDHLineInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoIteratorByAll是一个对DDN链路信息表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoIteratorByAll: public CSysNetDDNLinkInfoIterator
{
	friend class CSysNetDDNLinkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetDDNLinkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);

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
	CWriteableSysNetDDNLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetDDNLinkInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetDDNLinkInfoIteratorByAll(CSysNetDDNLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetDDNLinkInfoIteratorByAll *alloc(CSysNetDDNLinkInfoFactory *pFactory
		);

	///构造方法
	CSysNetDDNLinkInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetDDNLinkInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetDDNLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetDDNLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetDDNLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoIteratorByAll是一个对非会员线路使用信息使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoIteratorByAll: public CSysNetPseudMemberLinkInfoIterator
{
	friend class CSysNetPseudMemberLinkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetPseudMemberLinkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);

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
	CWriteableSysNetPseudMemberLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetPseudMemberLinkInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetPseudMemberLinkInfoIteratorByAll(CSysNetPseudMemberLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetPseudMemberLinkInfoIteratorByAll *alloc(CSysNetPseudMemberLinkInfoFactory *pFactory
		);

	///构造方法
	CSysNetPseudMemberLinkInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetPseudMemberLinkInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPseudMemberLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetPseudMemberLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPseudMemberLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoIteratorByAll是一个对远端设备信息使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoIteratorByAll: public CSysNetOuterDeviceInfoIterator
{
	friend class CSysNetOuterDeviceInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetOuterDeviceInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);

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
	CWriteableSysNetOuterDeviceInfo m_compareObject;
	
	static CMemoryStack<CSysNetOuterDeviceInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetOuterDeviceInfoIteratorByAll(CSysNetOuterDeviceInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetOuterDeviceInfoIteratorByAll *alloc(CSysNetOuterDeviceInfoFactory *pFactory
		);

	///构造方法
	CSysNetOuterDeviceInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetOuterDeviceInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetOuterDeviceInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetOuterDeviceInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetOuterDeviceInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoIteratorByAll是一个对本地ping结果使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoIteratorByAll: public CSysLocalPingResultInfoIterator
{
	friend class CSysLocalPingResultInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysLocalPingResultInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysLocalPingResultInfo *pSysLocalPingResultInfo);

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
	CWriteableSysLocalPingResultInfo m_compareObject;
	
	static CMemoryStack<CSysLocalPingResultInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysLocalPingResultInfoIteratorByAll(CSysLocalPingResultInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysLocalPingResultInfoIteratorByAll *alloc(CSysLocalPingResultInfoFactory *pFactory
		);

	///构造方法
	CSysLocalPingResultInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysLocalPingResultInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysLocalPingResultInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysLocalPingResultInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoIteratorByIDType是一个对本地ping结果使用ByIDType方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoIteratorByIDType: public CSysLocalPingResultInfoIterator
{
	friend class CSysLocalPingResultInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysLocalPingResultInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysLocalPingResultInfo *pSysLocalPingResultInfo);

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
	CWriteableSysLocalPingResultInfo m_compareObject;
	
	static CMemoryStack<CSysLocalPingResultInfoIteratorByIDType> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	CSysLocalPingResultInfoIteratorByIDType(CSysLocalPingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	static CSysLocalPingResultInfoIteratorByIDType *alloc(CSysLocalPingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///构造方法
	CSysLocalPingResultInfoIteratorByIDType(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	void init(CSysLocalPingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysLocalPingResultInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysLocalPingResultInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoIteratorByAll是一个对远程ping结果使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoIteratorByAll: public CSysRomotePingResultInfoIterator
{
	friend class CSysRomotePingResultInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysRomotePingResultInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysRomotePingResultInfo *pSysRomotePingResultInfo);

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
	CWriteableSysRomotePingResultInfo m_compareObject;
	
	static CMemoryStack<CSysRomotePingResultInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysRomotePingResultInfoIteratorByAll(CSysRomotePingResultInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysRomotePingResultInfoIteratorByAll *alloc(CSysRomotePingResultInfoFactory *pFactory
		);

	///构造方法
	CSysRomotePingResultInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysRomotePingResultInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysRomotePingResultInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysRomotePingResultInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoIteratorByIDType是一个对远程ping结果使用ByIDType方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoIteratorByIDType: public CSysRomotePingResultInfoIterator
{
	friend class CSysRomotePingResultInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysRomotePingResultInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysRomotePingResultInfo *pSysRomotePingResultInfo);

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
	CWriteableSysRomotePingResultInfo m_compareObject;
	
	static CMemoryStack<CSysRomotePingResultInfoIteratorByIDType> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	CSysRomotePingResultInfoIteratorByIDType(CSysRomotePingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID)
	{
		init(pFactory,ID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	static CSysRomotePingResultInfoIteratorByIDType *alloc(CSysRomotePingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///构造方法
	CSysRomotePingResultInfoIteratorByIDType(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ID	
	void init(CSysRomotePingResultInfoFactory *pFactory
		,const CReadOnlyVolumeType& ID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysRomotePingResultInfoIteratorByIDType(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysRomotePingResultInfo，必须在startFindByIDType以后，endFindByIDType之前叫用
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByIDType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pByIDType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesIteratorByAll是一个对会员席位交易状态使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesIteratorByAll: public CSysParticTradeOrderStatesIterator
{
	friend class CSysParticTradeOrderStatesFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysParticTradeOrderStates		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysParticTradeOrderStates *pSysParticTradeOrderStates);

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
	CWriteableSysParticTradeOrderStates m_compareObject;
	
	static CMemoryStack<CSysParticTradeOrderStatesIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysParticTradeOrderStatesIteratorByAll(CSysParticTradeOrderStatesFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysParticTradeOrderStatesIteratorByAll *alloc(CSysParticTradeOrderStatesFactory *pFactory
		);

	///构造方法
	CSysParticTradeOrderStatesIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysParticTradeOrderStatesFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticTradeOrderStatesIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysParticTradeOrderStates，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesIteratorByUserID是一个对会员席位交易状态使用ByUserID方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesIteratorByUserID: public CSysParticTradeOrderStatesIterator
{
	friend class CSysParticTradeOrderStatesFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysParticTradeOrderStates		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysParticTradeOrderStates *pSysParticTradeOrderStates);

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
	CWriteableSysParticTradeOrderStates m_compareObject;
	
	static CMemoryStack<CSysParticTradeOrderStatesIteratorByUserID> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	CSysParticTradeOrderStatesIteratorByUserID(CSysParticTradeOrderStatesFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyUserIDType& UserID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ParticipantID,UserID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysParticTradeOrderStatesIteratorByUserID *alloc(CSysParticTradeOrderStatesFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyUserIDType& UserID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysParticTradeOrderStatesIteratorByUserID(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ParticipantID	
	///@param	UserID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysParticTradeOrderStatesFactory *pFactory
		,const CReadOnlyParticipantIDType& ParticipantID,const CReadOnlyUserIDType& UserID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysParticTradeOrderStatesIteratorByUserID(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysParticTradeOrderStates，必须在startFindByUserID以后，endFindByUserID之前叫用
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByUserID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pByUserID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorByHostName是一个对系统路由信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorByHostName: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbRouterInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbRouterInfoIteratorByHostName(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbRouterInfoIteratorByHostName *alloc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbRouterInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbRouterInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorByDsc是一个对系统路由信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorByDsc: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbRouterInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbRouterInfoIteratorByDsc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbRouterInfoIteratorByDsc *alloc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbRouterInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbRouterInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorBytheAll是一个对系统路由信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorBytheAll: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbRouterInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbRouterInfoIteratorBytheAll(CSysMdbRouterInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbRouterInfoIteratorBytheAll *alloc(CSysMdbRouterInfoFactory *pFactory
		);

	///构造方法
	CSysMdbRouterInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbRouterInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbRouterInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIteratorByDataDelete是一个对系统路由信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIteratorByDataDelete: public CSysMdbRouterInfoIterator
{
	friend class CSysMdbRouterInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbRouterInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbRouterInfo *pSysMdbRouterInfo);

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
	CWriteableSysMdbRouterInfo m_compareObject;
	
	static CMemoryStack<CSysMdbRouterInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbRouterInfoIteratorByDataDelete(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbRouterInfoIteratorByDataDelete *alloc(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbRouterInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbRouterInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbRouterInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbRouterInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorByHostName是一个对磁盘I/O信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorByHostName: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDiskIO		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDiskIOIteratorByHostName(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDiskIOIteratorByHostName *alloc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbDiskIOIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDiskIOIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorByDsc是一个对磁盘I/O信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorByDsc: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDiskIO		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbDiskIOIteratorByDsc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbDiskIOIteratorByDsc *alloc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbDiskIOIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDiskIOIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorBytheAll是一个对磁盘I/O信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorBytheAll: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDiskIO		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbDiskIOIteratorBytheAll(CSysMdbDiskIOFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbDiskIOIteratorBytheAll *alloc(CSysMdbDiskIOFactory *pFactory
		);

	///构造方法
	CSysMdbDiskIOIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbDiskIOFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDiskIOIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIteratorByDataDelete是一个对磁盘I/O信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIteratorByDataDelete: public CSysMdbDiskIOIterator
{
	friend class CSysMdbDiskIOFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbDiskIO		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbDiskIO *pSysMdbDiskIO);

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
	CWriteableSysMdbDiskIO m_compareObject;
	
	static CMemoryStack<CSysMdbDiskIOIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbDiskIOIteratorByDataDelete(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbDiskIOIteratorByDataDelete *alloc(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbDiskIOIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbDiskIOFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbDiskIOIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbDiskIO，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorByHostName是一个对系统状态信息使用ByHostName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorByHostName: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbStatInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorByHostName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbStatInfoIteratorByHostName(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbStatInfoIteratorByHostName *alloc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbStatInfoIteratorByHostName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbStatInfoIteratorByHostName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindByHostName以后，endFindByHostName之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByHostName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pByHostName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorByDsc是一个对系统状态信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorByDsc: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbStatInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbStatInfoIteratorByDsc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbStatInfoIteratorByDsc *alloc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbStatInfoIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbStatInfoIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorBytheAll是一个对系统状态信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorBytheAll: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbStatInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbStatInfoIteratorBytheAll(CSysMdbStatInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbStatInfoIteratorBytheAll *alloc(CSysMdbStatInfoFactory *pFactory
		);

	///构造方法
	CSysMdbStatInfoIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbStatInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbStatInfoIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIteratorByDataDelete是一个对系统状态信息使用ByDataDelete方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIteratorByDataDelete: public CSysMdbStatInfoIterator
{
	friend class CSysMdbStatInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbStatInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbStatInfo *pSysMdbStatInfo);

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
	CWriteableSysMdbStatInfo m_compareObject;
	
	static CMemoryStack<CSysMdbStatInfoIteratorByDataDelete> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	CSysMdbStatInfoIteratorByDataDelete(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,SubcriberID,MonDate,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	static CSysMdbStatInfoIteratorByDataDelete *alloc(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbStatInfoIteratorByDataDelete(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	///@param	MonDate	
	///@param	MonTime	
	void init(CSysMdbStatInfoFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID,const CReadOnlyDateType& MonDate,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbStatInfoIteratorByDataDelete(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbStatInfo，必须在startFindByDataDelete以后，endFindByDataDelete之前叫用
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDataDelete 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pByDataDelete,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex是一个对交易系统前置报单响应信息使用ByFrontIndex方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex: public CSysMdbTradeFrontOrderRttStatIterator
{
	friend class CSysMdbTradeFrontOrderRttStatFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTradeFrontOrderRttStat		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

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
	CWriteableSysMdbTradeFrontOrderRttStat m_compareObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime)
	{
		init(pFactory,ObjectID,MonTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	static CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex *alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///构造方法
	CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	ObjectID	
	///@param	MonTime	
	void init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyTypeObjectIDType& ObjectID,const CReadOnlyTimeType& MonTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTradeFrontOrderRttStatIteratorByFrontIndex(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat，必须在startFindByFrontIndex以后，endFindByFrontIndex之前叫用
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByFrontIndex 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pByFrontIndex,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIteratorByDsc是一个对交易系统前置报单响应信息使用ByDsc方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIteratorByDsc: public CSysMdbTradeFrontOrderRttStatIterator
{
	friend class CSysMdbTradeFrontOrderRttStatFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTradeFrontOrderRttStat		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

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
	CWriteableSysMdbTradeFrontOrderRttStat m_compareObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorByDsc> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	CSysMdbTradeFrontOrderRttStatIteratorByDsc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID)
	{
		init(pFactory,SubcriberID);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	static CSysMdbTradeFrontOrderRttStatIteratorByDsc *alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///构造方法
	CSysMdbTradeFrontOrderRttStatIteratorByDsc(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	SubcriberID	
	void init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		,const CReadOnlyVolumeType& SubcriberID);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTradeFrontOrderRttStatIteratorByDsc(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat，必须在startFindByDsc以后，endFindByDsc之前叫用
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByDsc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pByDsc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIteratorBytheAll是一个对交易系统前置报单响应信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIteratorBytheAll: public CSysMdbTradeFrontOrderRttStatIterator
{
	friend class CSysMdbTradeFrontOrderRttStatFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMdbTradeFrontOrderRttStat		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);

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
	CWriteableSysMdbTradeFrontOrderRttStat m_compareObject;
	
	static CMemoryStack<CSysMdbTradeFrontOrderRttStatIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMdbTradeFrontOrderRttStatIteratorBytheAll(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMdbTradeFrontOrderRttStatIteratorBytheAll *alloc(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		);

	///构造方法
	CSysMdbTradeFrontOrderRttStatIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMdbTradeFrontOrderRttStatFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMdbTradeFrontOrderRttStatIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusIteratorByActionTime是一个对合约状态切换使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusIteratorByActionTime: public CSysInstrumentStatusIterator
{
	friend class CSysInstrumentStatusFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysInstrumentStatus		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysInstrumentStatus *pSysInstrumentStatus);

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
	CWriteableSysInstrumentStatus m_compareObject;
	
	static CMemoryStack<CSysInstrumentStatusIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	EnterTime	
	CSysInstrumentStatusIteratorByActionTime(CSysInstrumentStatusFactory *pFactory
		,const CReadOnlyTimeType& EnterTime)
	{
		init(pFactory,EnterTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	EnterTime	
	static CSysInstrumentStatusIteratorByActionTime *alloc(CSysInstrumentStatusFactory *pFactory
		,const CReadOnlyTimeType& EnterTime);

	///构造方法
	CSysInstrumentStatusIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	EnterTime	
	void init(CSysInstrumentStatusFactory *pFactory
		,const CReadOnlyTimeType& EnterTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysInstrumentStatusIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysInstrumentStatus，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusIteratorBytheAll是一个对合约状态切换使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusIteratorBytheAll: public CSysInstrumentStatusIterator
{
	friend class CSysInstrumentStatusFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysInstrumentStatus		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysInstrumentStatus *pSysInstrumentStatus);

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
	CWriteableSysInstrumentStatus m_compareObject;
	
	static CMemoryStack<CSysInstrumentStatusIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysInstrumentStatusIteratorBytheAll(CSysInstrumentStatusFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysInstrumentStatusIteratorBytheAll *alloc(CSysInstrumentStatusFactory *pFactory
		);

	///构造方法
	CSysInstrumentStatusIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysInstrumentStatusFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysInstrumentStatusIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysInstrumentStatus，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrIteratorByActionTime是一个对合约交易节信息使用ByActionTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrIteratorByActionTime: public CSysCurrTradingSegmentAttrIterator
{
	friend class CSysCurrTradingSegmentAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysCurrTradingSegmentAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);

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
	CWriteableSysCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CSysCurrTradingSegmentAttrIteratorByActionTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	StartTime	
	CSysCurrTradingSegmentAttrIteratorByActionTime(CSysCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime)
	{
		init(pFactory,StartTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	StartTime	
	static CSysCurrTradingSegmentAttrIteratorByActionTime *alloc(CSysCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///构造方法
	CSysCurrTradingSegmentAttrIteratorByActionTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	StartTime	
	void init(CSysCurrTradingSegmentAttrFactory *pFactory
		,const CReadOnlyTimeType& StartTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysCurrTradingSegmentAttrIteratorByActionTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysCurrTradingSegmentAttr，必须在startFindByActionTime以后，endFindByActionTime之前叫用
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByActionTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pByActionTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrIteratorBytheAll是一个对合约交易节信息使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrIteratorBytheAll: public CSysCurrTradingSegmentAttrIterator
{
	friend class CSysCurrTradingSegmentAttrFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysCurrTradingSegmentAttr		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);

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
	CWriteableSysCurrTradingSegmentAttr m_compareObject;
	
	static CMemoryStack<CSysCurrTradingSegmentAttrIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysCurrTradingSegmentAttrIteratorBytheAll(CSysCurrTradingSegmentAttrFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysCurrTradingSegmentAttrIteratorBytheAll *alloc(CSysCurrTradingSegmentAttrFactory *pFactory
		);

	///构造方法
	CSysCurrTradingSegmentAttrIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysCurrTradingSegmentAttrFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysCurrTradingSegmentAttrIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysCurrTradingSegmentAttr，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIteratorByPayTime是一个对会员链路费用表使用ByPayTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIteratorByPayTime: public CSysMemberLinkCostIterator
{
	friend class CSysMemberLinkCostFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMemberLinkCost		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMemberLinkCost *pSysMemberLinkCost);

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
	CWriteableSysMemberLinkCost m_compareObject;
	
	static CMemoryStack<CSysMemberLinkCostIteratorByPayTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	Pay_Date	
	CSysMemberLinkCostIteratorByPayTime(CSysMemberLinkCostFactory *pFactory
		,const CReadOnlyCfgNameType& Pay_Date)
	{
		init(pFactory,Pay_Date);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	Pay_Date	
	static CSysMemberLinkCostIteratorByPayTime *alloc(CSysMemberLinkCostFactory *pFactory
		,const CReadOnlyCfgNameType& Pay_Date);

	///构造方法
	CSysMemberLinkCostIteratorByPayTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	Pay_Date	
	void init(CSysMemberLinkCostFactory *pFactory
		,const CReadOnlyCfgNameType& Pay_Date);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMemberLinkCostIteratorByPayTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMemberLinkCost，必须在startFindByPayTime以后，endFindByPayTime之前叫用
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMemberLinkCost *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByPayTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pByPayTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIteratorBytheAll是一个对会员链路费用表使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIteratorBytheAll: public CSysMemberLinkCostIterator
{
	friend class CSysMemberLinkCostFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMemberLinkCost		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMemberLinkCost *pSysMemberLinkCost);

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
	CWriteableSysMemberLinkCost m_compareObject;
	
	static CMemoryStack<CSysMemberLinkCostIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMemberLinkCostIteratorBytheAll(CSysMemberLinkCostFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMemberLinkCostIteratorBytheAll *alloc(CSysMemberLinkCostFactory *pFactory
		);

	///构造方法
	CSysMemberLinkCostIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMemberLinkCostFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMemberLinkCostIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMemberLinkCost，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMemberLinkCost *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIteratorByAll是一个对会员链路费用表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIteratorByAll: public CSysMemberLinkCostIterator
{
	friend class CSysMemberLinkCostFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysMemberLinkCost		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysMemberLinkCost *pSysMemberLinkCost);

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
	CWriteableSysMemberLinkCost m_compareObject;
	
	static CMemoryStack<CSysMemberLinkCostIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysMemberLinkCostIteratorByAll(CSysMemberLinkCostFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysMemberLinkCostIteratorByAll *alloc(CSysMemberLinkCostFactory *pFactory
		);

	///构造方法
	CSysMemberLinkCostIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysMemberLinkCostFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysMemberLinkCostIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysMemberLinkCost，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMemberLinkCost *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIteratorByLineName是一个对会员链路月租表使用ByLineName方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIteratorByLineName: public CSysNetPartylinkMonthlyRentIterator
{
	friend class CSysNetPartylinkMonthlyRentFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetPartylinkMonthlyRent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

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
	CWriteableSysNetPartylinkMonthlyRent m_compareObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentIteratorByLineName> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	LineName	
	CSysNetPartylinkMonthlyRentIteratorByLineName(CSysNetPartylinkMonthlyRentFactory *pFactory
		,const CReadOnlyParticipantNameType& LineName)
	{
		init(pFactory,LineName);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	LineName	
	static CSysNetPartylinkMonthlyRentIteratorByLineName *alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		,const CReadOnlyParticipantNameType& LineName);

	///构造方法
	CSysNetPartylinkMonthlyRentIteratorByLineName(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	LineName	
	void init(CSysNetPartylinkMonthlyRentFactory *pFactory
		,const CReadOnlyParticipantNameType& LineName);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartylinkMonthlyRentIteratorByLineName(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent，必须在startFindByLineName以后，endFindByLineName之前叫用
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByLineName 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pByLineName,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIteratorBytheAll是一个对会员链路月租表使用BytheAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIteratorBytheAll: public CSysNetPartylinkMonthlyRentIterator
{
	friend class CSysNetPartylinkMonthlyRentFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetPartylinkMonthlyRent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

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
	CWriteableSysNetPartylinkMonthlyRent m_compareObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentIteratorBytheAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetPartylinkMonthlyRentIteratorBytheAll(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetPartylinkMonthlyRentIteratorBytheAll *alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///构造方法
	CSysNetPartylinkMonthlyRentIteratorBytheAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartylinkMonthlyRentIteratorBytheAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent，必须在startFindBytheAll以后，endFindBytheAll之前叫用
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBytheAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pBytheAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIteratorByAll是一个对会员链路月租表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIteratorByAll: public CSysNetPartylinkMonthlyRentIterator
{
	friend class CSysNetPartylinkMonthlyRentFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetPartylinkMonthlyRent		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);

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
	CWriteableSysNetPartylinkMonthlyRent m_compareObject;
	
	static CMemoryStack<CSysNetPartylinkMonthlyRentIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetPartylinkMonthlyRentIteratorByAll(CSysNetPartylinkMonthlyRentFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetPartylinkMonthlyRentIteratorByAll *alloc(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///构造方法
	CSysNetPartylinkMonthlyRentIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetPartylinkMonthlyRentFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetPartylinkMonthlyRentIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoIteratorByAll是一个对会员链路月租表使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoIteratorByAll: public CSysNetNonPartyLinkInfoIterator
{
	friend class CSysNetNonPartyLinkInfoFactory;
private:
	///检查此对象是否满足条件
	///@param	pSysNetNonPartyLinkInfo		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);

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
	CWriteableSysNetNonPartyLinkInfo m_compareObject;
	
	static CMemoryStack<CSysNetNonPartyLinkInfoIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CSysNetNonPartyLinkInfoIteratorByAll(CSysNetNonPartyLinkInfoFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CSysNetNonPartyLinkInfoIteratorByAll *alloc(CSysNetNonPartyLinkInfoFactory *pFactory
		);

	///构造方法
	CSysNetNonPartyLinkInfoIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CSysNetNonPartyLinkInfoFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CSysNetNonPartyLinkInfoIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CSysNetNonPartyLinkInfo，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CSysNetNonPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

#endif
