/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseIteratorRepository.h
///@brief	定义了若干个内存数据库的iterator库，以便各种查询
///@history 
///20061222	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEITERATORREPOSITORY_H
#define DATABASEITERATORREPOSITORY_H

#include "BaseDataStruct.h"
#include "databaseFactories.h"

/////////////////////////////////////////////////////////////////////////
///CMonitorEntitySingleIterator是至多返回一个监控实体的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntitySingleIterator: public CMonitorEntityIterator
{
private:
	CMonitorEntity *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMonitorEntitySingleIterator(CMonitorEntityFactory *pFactory,CMonitorEntity *pResult)
		:CMonitorEntityIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMonitorEntitySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMonitorEntity
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CMonitorEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMonitorEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityPredict是判断一个监控实体是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityPredict
{
public:
	///判断是否合法
	///@param	pMonitorEntity	要被判断的监控实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMonitorEntity *pMonitorEntity)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityAndPredict是对两个监控实体谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityAndPredict : public CMonitorEntityPredict
{
private:
	CMonitorEntityPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMonitorEntityAndPredict(CMonitorEntityPredict *p1, CMonitorEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMonitorEntityAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMonitorEntity	要被判断的监控实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMonitorEntity *pMonitorEntity)
	{
		return m_p1->isValid(pMonitorEntity) && m_p2->isValid(pMonitorEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityOrPredict是对两个监控实体谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityOrPredict : public CMonitorEntityPredict
{
private:
	CMonitorEntityPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMonitorEntityOrPredict(CMonitorEntityPredict *p1, CMonitorEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMonitorEntityOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMonitorEntity	要被判断的监控实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMonitorEntity *pMonitorEntity)
	{
		return m_p1->isValid(pMonitorEntity) || m_p2->isValid(pMonitorEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityNotPredict是对一个监控实体谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityNotPredict : public CMonitorEntityPredict
{
private:
	CMonitorEntityPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMonitorEntityNotPredict(CMonitorEntityPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMonitorEntityNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMonitorEntity	要被判断的监控实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMonitorEntity *pMonitorEntity)
	{
		return !m_predict->isValid(pMonitorEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityFilter是一个对已有的监控实体枚举器进行过滤的枚举器
///@author	王肇东
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
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMonitorEntityFilter(CMonitorEntityIterator *pBaseIterator, CMonitorEntityPredict *pPredict, bool continueResult=false)
		:CMonitorEntityIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMonitorEntityFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMonitorEntity
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CMonitorEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMonitorEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityLinkIterator是连接两个监控实体枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityLinkIterator: public CMonitorEntityIterator
{
private:
	CMonitorEntityIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMonitorEntityLinkIterator(CMonitorEntityIterator *pBaseIterator1,CMonitorEntityIterator *pBaseIterator2)
		:CMonitorEntityIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMonitorEntityLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMonitorEntity
	///@return	下一个满足条件CMonitorEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CMonitorEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMonitorEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CEventEntitySingleIterator是至多返回一个事件实体的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntitySingleIterator: public CEventEntityIterator
{
private:
	CEventEntity *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CEventEntitySingleIterator(CEventEntityFactory *pFactory,CEventEntity *pResult)
		:CEventEntityIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CEventEntitySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CEventEntity
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CEventEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pEventEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityPredict是判断一个事件实体是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityPredict
{
public:
	///判断是否合法
	///@param	pEventEntity	要被判断的事件实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CEventEntity *pEventEntity)=0;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityAndPredict是对两个事件实体谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityAndPredict : public CEventEntityPredict
{
private:
	CEventEntityPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CEventEntityAndPredict(CEventEntityPredict *p1, CEventEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CEventEntityAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pEventEntity	要被判断的事件实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CEventEntity *pEventEntity)
	{
		return m_p1->isValid(pEventEntity) && m_p2->isValid(pEventEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityOrPredict是对两个事件实体谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityOrPredict : public CEventEntityPredict
{
private:
	CEventEntityPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CEventEntityOrPredict(CEventEntityPredict *p1, CEventEntityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CEventEntityOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pEventEntity	要被判断的事件实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CEventEntity *pEventEntity)
	{
		return m_p1->isValid(pEventEntity) || m_p2->isValid(pEventEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityNotPredict是对一个事件实体谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityNotPredict : public CEventEntityPredict
{
private:
	CEventEntityPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CEventEntityNotPredict(CEventEntityPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CEventEntityNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pEventEntity	要被判断的事件实体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CEventEntity *pEventEntity)
	{
		return !m_predict->isValid(pEventEntity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityFilter是一个对已有的事件实体枚举器进行过滤的枚举器
///@author	王肇东
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
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CEventEntityFilter(CEventEntityIterator *pBaseIterator, CEventEntityPredict *pPredict, bool continueResult=false)
		:CEventEntityIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CEventEntityFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CEventEntity
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CEventEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pEventEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityLinkIterator是连接两个事件实体枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityLinkIterator: public CEventEntityIterator
{
private:
	CEventEntityIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CEventEntityLinkIterator(CEventEntityIterator *pBaseIterator1,CEventEntityIterator *pBaseIterator2)
		:CEventEntityIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CEventEntityLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CEventEntity
	///@return	下一个满足条件CEventEntity，如果已经没有一个满足要求了，则返回NULL
	virtual CEventEntity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pEventEntity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


#endif
