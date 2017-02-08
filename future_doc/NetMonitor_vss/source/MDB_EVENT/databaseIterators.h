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
///CMonitorEntityIteratorByTime是一个对监控实体使用ByTime方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityIteratorByTime: public CMonitorEntityIterator
{
	friend class CMonitorEntityFactory;
private:
	///检查此对象是否满足条件
	///@param	pMonitorEntity		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMonitorEntity *pMonitorEntity);

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
	CWriteableMonitorEntity m_compareObject;
	
	static CMemoryStack<CMonitorEntityIteratorByTime> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonitorObject	监控对象
	///@param	MonitorItem	监控指标项
	///@param	MonitorTime	监控时间
	CMonitorEntityIteratorByTime(CMonitorEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& MonitorItem,const CReadOnlyMonitorTimeType& MonitorTime)
	{
		init(pFactory,MonitorObject,MonitorItem,MonitorTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonitorObject	监控对象
	///@param	MonitorItem	监控指标项
	///@param	MonitorTime	监控时间
	static CMonitorEntityIteratorByTime *alloc(CMonitorEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& MonitorItem,const CReadOnlyMonitorTimeType& MonitorTime);

	///构造方法
	CMonitorEntityIteratorByTime(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonitorObject	监控对象
	///@param	MonitorItem	监控指标项
	///@param	MonitorTime	监控时间
	void init(CMonitorEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& MonitorItem,const CReadOnlyMonitorTimeType& MonitorTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CMonitorEntityIteratorByTime(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMonitorEntity，必须在startFindByTime以后，endFindByTime之前叫用
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CMonitorEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMonitorEntity * pByTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CMonitorEntityIteratorByAll是一个对监控实体使用ByAll方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityIteratorByAll: public CMonitorEntityIterator
{
	friend class CMonitorEntityFactory;
private:
	///检查此对象是否满足条件
	///@param	pMonitorEntity		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CMonitorEntity *pMonitorEntity);

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
	CWriteableMonitorEntity m_compareObject;
	
	static CMemoryStack<CMonitorEntityIteratorByAll> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	CMonitorEntityIteratorByAll(CMonitorEntityFactory *pFactory
		)
	{
		init(pFactory);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	static CMonitorEntityIteratorByAll *alloc(CMonitorEntityFactory *pFactory
		);

	///构造方法
	CMonitorEntityIteratorByAll(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	void init(CMonitorEntityFactory *pFactory
		);

	///析构方法，将负责释放所占用的空间
	virtual ~CMonitorEntityIteratorByAll(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CMonitorEntity，必须在startFindByAll以后，endFindByAll之前叫用
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CMonitorEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByAll 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMonitorEntity * pByAll,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityIteratorByKey是一个对事件实体使用ByKey方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityIteratorByKey: public CEventEntityIterator
{
	friend class CEventEntityFactory;
private:
	///检查此对象是否满足条件
	///@param	pEventEntity		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CEventEntity *pEventEntity);

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
	CWriteableEventEntity m_compareObject;
	
	static CMemoryStack<CEventEntityIteratorByKey> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	CEventEntityIteratorByKey(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime)
	{
		init(pFactory,EventName,MonitorTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	static CEventEntityIteratorByKey *alloc(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///构造方法
	CEventEntityIteratorByKey(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	void init(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CEventEntityIteratorByKey(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CEventEntity，必须在startFindByKey以后，endFindByKey之前叫用
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CEventEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByKey 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableEventEntity * pByKey,CTransaction *pTransaction = NULL, bool updateIndex=true);
};
/////////////////////////////////////////////////////////////////////////
///CEventEntityIteratorByObject是一个对事件实体使用ByObject方法进行
///查找的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityIteratorByObject: public CEventEntityIterator
{
	friend class CEventEntityFactory;
private:
	///检查此对象是否满足条件
	///@param	pEventEntity		要被检查的对象
	///@return	1表示满足条件，0表示不满足条件
	int match(CEventEntity *pEventEntity);

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
	CWriteableEventEntity m_compareObject;
	
	static CMemoryStack<CEventEntityIteratorByObject> iteratorList;
public:
	///构造方法
	///@param	pFactory	要查找的对象工厂
	///@param	MonitorObject	对象名
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	CEventEntityIteratorByObject(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime)
	{
		init(pFactory,MonitorObject,EventName,MonitorTime);
	}

	///申请一个新的对象
	///@param	pFactory	要查找的对象工厂
	///@param	MonitorObject	对象名
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	static CEventEntityIteratorByObject *alloc(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///构造方法
	CEventEntityIteratorByObject(void)
	{
	}

	///初始化
	///@param	pFactory	要查找的对象工厂
	///@param	MonitorObject	对象名
	///@param	EventName	事件名
	///@param	MonitorTime	监控时间
	void init(CEventEntityFactory *pFactory
		,const CReadOnlyMonitorObjectType& MonitorObject,const CReadOnlyMonitorItemType& EventName,const CReadOnlyMonitorTimeType& MonitorTime);

	///析构方法，将负责释放所占用的空间
	virtual ~CEventEntityIteratorByObject(void);
	
	virtual void free(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///寻找下一个符合条件的CEventEntity，必须在startFindByObject以后，endFindByObject之前叫用
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CEventEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pByObject 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableEventEntity * pByObject,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

#endif
