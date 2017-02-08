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
///CExchangeDataSyncStatusSingleIterator是至多返回一个交易所数据同步状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusSingleIterator: public CExchangeDataSyncStatusIterator
{
private:
	CExchangeDataSyncStatus *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CExchangeDataSyncStatusSingleIterator(CExchangeDataSyncStatusFactory *pFactory,CExchangeDataSyncStatus *pResult)
		:CExchangeDataSyncStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CExchangeDataSyncStatusSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CExchangeDataSyncStatus
	///@return	下一个满足条件CExchangeDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CExchangeDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExchangeDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusPredict是判断一个交易所数据同步状态是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusPredict
{
public:
	///判断是否合法
	///@param	pExchangeDataSyncStatus	要被判断的交易所数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusAndPredict是对两个交易所数据同步状态谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusAndPredict : public CExchangeDataSyncStatusPredict
{
private:
	CExchangeDataSyncStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CExchangeDataSyncStatusAndPredict(CExchangeDataSyncStatusPredict *p1, CExchangeDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CExchangeDataSyncStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pExchangeDataSyncStatus	要被判断的交易所数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return m_p1->isValid(pExchangeDataSyncStatus) && m_p2->isValid(pExchangeDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusOrPredict是对两个交易所数据同步状态谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusOrPredict : public CExchangeDataSyncStatusPredict
{
private:
	CExchangeDataSyncStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CExchangeDataSyncStatusOrPredict(CExchangeDataSyncStatusPredict *p1, CExchangeDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CExchangeDataSyncStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pExchangeDataSyncStatus	要被判断的交易所数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return m_p1->isValid(pExchangeDataSyncStatus) || m_p2->isValid(pExchangeDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusNotPredict是对一个交易所数据同步状态谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusNotPredict : public CExchangeDataSyncStatusPredict
{
private:
	CExchangeDataSyncStatusPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CExchangeDataSyncStatusNotPredict(CExchangeDataSyncStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CExchangeDataSyncStatusNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pExchangeDataSyncStatus	要被判断的交易所数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return !m_predict->isValid(pExchangeDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusFilter是一个对已有的交易所数据同步状态枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusFilter: public CExchangeDataSyncStatusIterator
{
private:
	CExchangeDataSyncStatusIterator *m_baseIterator;
	CExchangeDataSyncStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CExchangeDataSyncStatusFilter(CExchangeDataSyncStatusIterator *pBaseIterator, CExchangeDataSyncStatusPredict *pPredict, bool continueResult=false)
		:CExchangeDataSyncStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CExchangeDataSyncStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CExchangeDataSyncStatus
	///@return	下一个满足条件CExchangeDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CExchangeDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExchangeDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusLinkIterator是连接两个交易所数据同步状态枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusLinkIterator: public CExchangeDataSyncStatusIterator
{
private:
	CExchangeDataSyncStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CExchangeDataSyncStatusLinkIterator(CExchangeDataSyncStatusIterator *pBaseIterator1,CExchangeDataSyncStatusIterator *pBaseIterator2)
		:CExchangeDataSyncStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CExchangeDataSyncStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CExchangeDataSyncStatus
	///@return	下一个满足条件CExchangeDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CExchangeDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExchangeDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusSingleIterator是至多返回一个结算组数据同步状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusSingleIterator: public CSGDataSyncStatusIterator
{
private:
	CSGDataSyncStatus *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSGDataSyncStatusSingleIterator(CSGDataSyncStatusFactory *pFactory,CSGDataSyncStatus *pResult)
		:CSGDataSyncStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSGDataSyncStatusSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSGDataSyncStatus
	///@return	下一个满足条件CSGDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSGDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSGDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusPredict是判断一个结算组数据同步状态是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusPredict
{
public:
	///判断是否合法
	///@param	pSGDataSyncStatus	要被判断的结算组数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusAndPredict是对两个结算组数据同步状态谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusAndPredict : public CSGDataSyncStatusPredict
{
private:
	CSGDataSyncStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSGDataSyncStatusAndPredict(CSGDataSyncStatusPredict *p1, CSGDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSGDataSyncStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSGDataSyncStatus	要被判断的结算组数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return m_p1->isValid(pSGDataSyncStatus) && m_p2->isValid(pSGDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusOrPredict是对两个结算组数据同步状态谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusOrPredict : public CSGDataSyncStatusPredict
{
private:
	CSGDataSyncStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSGDataSyncStatusOrPredict(CSGDataSyncStatusPredict *p1, CSGDataSyncStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSGDataSyncStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSGDataSyncStatus	要被判断的结算组数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return m_p1->isValid(pSGDataSyncStatus) || m_p2->isValid(pSGDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusNotPredict是对一个结算组数据同步状态谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusNotPredict : public CSGDataSyncStatusPredict
{
private:
	CSGDataSyncStatusPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSGDataSyncStatusNotPredict(CSGDataSyncStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSGDataSyncStatusNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSGDataSyncStatus	要被判断的结算组数据同步状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return !m_predict->isValid(pSGDataSyncStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusFilter是一个对已有的结算组数据同步状态枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusFilter: public CSGDataSyncStatusIterator
{
private:
	CSGDataSyncStatusIterator *m_baseIterator;
	CSGDataSyncStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSGDataSyncStatusFilter(CSGDataSyncStatusIterator *pBaseIterator, CSGDataSyncStatusPredict *pPredict, bool continueResult=false)
		:CSGDataSyncStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSGDataSyncStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSGDataSyncStatus
	///@return	下一个满足条件CSGDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSGDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSGDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusLinkIterator是连接两个结算组数据同步状态枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusLinkIterator: public CSGDataSyncStatusIterator
{
private:
	CSGDataSyncStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSGDataSyncStatusLinkIterator(CSGDataSyncStatusIterator *pBaseIterator1,CSGDataSyncStatusIterator *pBaseIterator2)
		:CSGDataSyncStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSGDataSyncStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSGDataSyncStatus
	///@return	下一个满足条件CSGDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSGDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSGDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrentTimeSingleIterator是至多返回一个当前时间的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeSingleIterator: public CCurrentTimeIterator
{
private:
	CCurrentTime *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrentTimeSingleIterator(CCurrentTimeFactory *pFactory,CCurrentTime *pResult)
		:CCurrentTimeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrentTimeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrentTime
	///@return	下一个满足条件CCurrentTime，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrentTime *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrentTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimePredict是判断一个当前时间是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimePredict
{
public:
	///判断是否合法
	///@param	pCurrentTime	要被判断的当前时间
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrentTime *pCurrentTime)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeAndPredict是对两个当前时间谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeAndPredict : public CCurrentTimePredict
{
private:
	CCurrentTimePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrentTimeAndPredict(CCurrentTimePredict *p1, CCurrentTimePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrentTimeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrentTime	要被判断的当前时间
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrentTime *pCurrentTime)
	{
		return m_p1->isValid(pCurrentTime) && m_p2->isValid(pCurrentTime);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeOrPredict是对两个当前时间谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeOrPredict : public CCurrentTimePredict
{
private:
	CCurrentTimePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrentTimeOrPredict(CCurrentTimePredict *p1, CCurrentTimePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrentTimeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrentTime	要被判断的当前时间
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrentTime *pCurrentTime)
	{
		return m_p1->isValid(pCurrentTime) || m_p2->isValid(pCurrentTime);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeNotPredict是对一个当前时间谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeNotPredict : public CCurrentTimePredict
{
private:
	CCurrentTimePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrentTimeNotPredict(CCurrentTimePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrentTimeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrentTime	要被判断的当前时间
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrentTime *pCurrentTime)
	{
		return !m_predict->isValid(pCurrentTime);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeFilter是一个对已有的当前时间枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeFilter: public CCurrentTimeIterator
{
private:
	CCurrentTimeIterator *m_baseIterator;
	CCurrentTimePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrentTimeFilter(CCurrentTimeIterator *pBaseIterator, CCurrentTimePredict *pPredict, bool continueResult=false)
		:CCurrentTimeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrentTimeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrentTime
	///@return	下一个满足条件CCurrentTime，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrentTime *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrentTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeLinkIterator是连接两个当前时间枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeLinkIterator: public CCurrentTimeIterator
{
private:
	CCurrentTimeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrentTimeLinkIterator(CCurrentTimeIterator *pBaseIterator1,CCurrentTimeIterator *pBaseIterator2)
		:CCurrentTimeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrentTimeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrentTime
	///@return	下一个满足条件CCurrentTime，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrentTime *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrentTime 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CDataCenterDescSingleIterator是至多返回一个数据中心描述的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescSingleIterator: public CDataCenterDescIterator
{
private:
	CDataCenterDesc *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CDataCenterDescSingleIterator(CDataCenterDescFactory *pFactory,CDataCenterDesc *pResult)
		:CDataCenterDescIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CDataCenterDescSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CDataCenterDesc
	///@return	下一个满足条件CDataCenterDesc，如果已经没有一个满足要求了，则返回NULL
	virtual CDataCenterDesc *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDataCenterDesc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescPredict是判断一个数据中心描述是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescPredict
{
public:
	///判断是否合法
	///@param	pDataCenterDesc	要被判断的数据中心描述
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)=0;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescAndPredict是对两个数据中心描述谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescAndPredict : public CDataCenterDescPredict
{
private:
	CDataCenterDescPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CDataCenterDescAndPredict(CDataCenterDescPredict *p1, CDataCenterDescPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CDataCenterDescAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pDataCenterDesc	要被判断的数据中心描述
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)
	{
		return m_p1->isValid(pDataCenterDesc) && m_p2->isValid(pDataCenterDesc);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescOrPredict是对两个数据中心描述谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescOrPredict : public CDataCenterDescPredict
{
private:
	CDataCenterDescPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CDataCenterDescOrPredict(CDataCenterDescPredict *p1, CDataCenterDescPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CDataCenterDescOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pDataCenterDesc	要被判断的数据中心描述
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)
	{
		return m_p1->isValid(pDataCenterDesc) || m_p2->isValid(pDataCenterDesc);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescNotPredict是对一个数据中心描述谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescNotPredict : public CDataCenterDescPredict
{
private:
	CDataCenterDescPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CDataCenterDescNotPredict(CDataCenterDescPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CDataCenterDescNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pDataCenterDesc	要被判断的数据中心描述
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDataCenterDesc *pDataCenterDesc)
	{
		return !m_predict->isValid(pDataCenterDesc);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescFilter是一个对已有的数据中心描述枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescFilter: public CDataCenterDescIterator
{
private:
	CDataCenterDescIterator *m_baseIterator;
	CDataCenterDescPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CDataCenterDescFilter(CDataCenterDescIterator *pBaseIterator, CDataCenterDescPredict *pPredict, bool continueResult=false)
		:CDataCenterDescIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CDataCenterDescFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CDataCenterDesc
	///@return	下一个满足条件CDataCenterDesc，如果已经没有一个满足要求了，则返回NULL
	virtual CDataCenterDesc *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDataCenterDesc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescLinkIterator是连接两个数据中心描述枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescLinkIterator: public CDataCenterDescIterator
{
private:
	CDataCenterDescIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CDataCenterDescLinkIterator(CDataCenterDescIterator *pBaseIterator1,CDataCenterDescIterator *pBaseIterator2)
		:CDataCenterDescIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CDataCenterDescLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CDataCenterDesc
	///@return	下一个满足条件CDataCenterDesc，如果已经没有一个满足要求了，则返回NULL
	virtual CDataCenterDesc *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDataCenterDesc 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CExchangeSingleIterator是至多返回一个交易所的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeSingleIterator: public CExchangeIterator
{
private:
	CExchange *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CExchangeSingleIterator(CExchangeFactory *pFactory,CExchange *pResult)
		:CExchangeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CExchangeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CExchange
	///@return	下一个满足条件CExchange，如果已经没有一个满足要求了，则返回NULL
	virtual CExchange *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExchange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangePredict是判断一个交易所是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangePredict
{
public:
	///判断是否合法
	///@param	pExchange	要被判断的交易所
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchange *pExchange)=0;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeAndPredict是对两个交易所谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeAndPredict : public CExchangePredict
{
private:
	CExchangePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CExchangeAndPredict(CExchangePredict *p1, CExchangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CExchangeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pExchange	要被判断的交易所
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchange *pExchange)
	{
		return m_p1->isValid(pExchange) && m_p2->isValid(pExchange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeOrPredict是对两个交易所谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeOrPredict : public CExchangePredict
{
private:
	CExchangePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CExchangeOrPredict(CExchangePredict *p1, CExchangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CExchangeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pExchange	要被判断的交易所
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchange *pExchange)
	{
		return m_p1->isValid(pExchange) || m_p2->isValid(pExchange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeNotPredict是对一个交易所谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeNotPredict : public CExchangePredict
{
private:
	CExchangePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CExchangeNotPredict(CExchangePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CExchangeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pExchange	要被判断的交易所
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExchange *pExchange)
	{
		return !m_predict->isValid(pExchange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExchangeFilter是一个对已有的交易所枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeFilter: public CExchangeIterator
{
private:
	CExchangeIterator *m_baseIterator;
	CExchangePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CExchangeFilter(CExchangeIterator *pBaseIterator, CExchangePredict *pPredict, bool continueResult=false)
		:CExchangeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CExchangeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CExchange
	///@return	下一个满足条件CExchange，如果已经没有一个满足要求了，则返回NULL
	virtual CExchange *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExchange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExchangeLinkIterator是连接两个交易所枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeLinkIterator: public CExchangeIterator
{
private:
	CExchangeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CExchangeLinkIterator(CExchangeIterator *pBaseIterator1,CExchangeIterator *pBaseIterator2)
		:CExchangeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CExchangeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CExchange
	///@return	下一个满足条件CExchange，如果已经没有一个满足要求了，则返回NULL
	virtual CExchange *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExchange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSettlementGroupSingleIterator是至多返回一个结算组的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupSingleIterator: public CSettlementGroupIterator
{
private:
	CSettlementGroup *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSettlementGroupSingleIterator(CSettlementGroupFactory *pFactory,CSettlementGroup *pResult)
		:CSettlementGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSettlementGroupSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSettlementGroup
	///@return	下一个满足条件CSettlementGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSettlementGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSettlementGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupPredict是判断一个结算组是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupPredict
{
public:
	///判断是否合法
	///@param	pSettlementGroup	要被判断的结算组
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSettlementGroup *pSettlementGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupAndPredict是对两个结算组谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupAndPredict : public CSettlementGroupPredict
{
private:
	CSettlementGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSettlementGroupAndPredict(CSettlementGroupPredict *p1, CSettlementGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSettlementGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSettlementGroup	要被判断的结算组
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSettlementGroup *pSettlementGroup)
	{
		return m_p1->isValid(pSettlementGroup) && m_p2->isValid(pSettlementGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupOrPredict是对两个结算组谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupOrPredict : public CSettlementGroupPredict
{
private:
	CSettlementGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSettlementGroupOrPredict(CSettlementGroupPredict *p1, CSettlementGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSettlementGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSettlementGroup	要被判断的结算组
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSettlementGroup *pSettlementGroup)
	{
		return m_p1->isValid(pSettlementGroup) || m_p2->isValid(pSettlementGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupNotPredict是对一个结算组谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupNotPredict : public CSettlementGroupPredict
{
private:
	CSettlementGroupPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSettlementGroupNotPredict(CSettlementGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSettlementGroupNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSettlementGroup	要被判断的结算组
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSettlementGroup *pSettlementGroup)
	{
		return !m_predict->isValid(pSettlementGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupFilter是一个对已有的结算组枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupFilter: public CSettlementGroupIterator
{
private:
	CSettlementGroupIterator *m_baseIterator;
	CSettlementGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSettlementGroupFilter(CSettlementGroupIterator *pBaseIterator, CSettlementGroupPredict *pPredict, bool continueResult=false)
		:CSettlementGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSettlementGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSettlementGroup
	///@return	下一个满足条件CSettlementGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSettlementGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSettlementGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupLinkIterator是连接两个结算组枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupLinkIterator: public CSettlementGroupIterator
{
private:
	CSettlementGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSettlementGroupLinkIterator(CSettlementGroupIterator *pBaseIterator1,CSettlementGroupIterator *pBaseIterator2)
		:CSettlementGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSettlementGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSettlementGroup
	///@return	下一个满足条件CSettlementGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSettlementGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSettlementGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketSingleIterator是至多返回一个市场的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketSingleIterator: public CMarketIterator
{
private:
	CMarket *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMarketSingleIterator(CMarketFactory *pFactory,CMarket *pResult)
		:CMarketIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMarketSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMarket
	///@return	下一个满足条件CMarket，如果已经没有一个满足要求了，则返回NULL
	virtual CMarket *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarket 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketPredict是判断一个市场是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketPredict
{
public:
	///判断是否合法
	///@param	pMarket	要被判断的市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarket *pMarket)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketAndPredict是对两个市场谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketAndPredict : public CMarketPredict
{
private:
	CMarketPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketAndPredict(CMarketPredict *p1, CMarketPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarket	要被判断的市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarket *pMarket)
	{
		return m_p1->isValid(pMarket) && m_p2->isValid(pMarket);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketOrPredict是对两个市场谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketOrPredict : public CMarketPredict
{
private:
	CMarketPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketOrPredict(CMarketPredict *p1, CMarketPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarket	要被判断的市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarket *pMarket)
	{
		return m_p1->isValid(pMarket) || m_p2->isValid(pMarket);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketNotPredict是对一个市场谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketNotPredict : public CMarketPredict
{
private:
	CMarketPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMarketNotPredict(CMarketPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMarketNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMarket	要被判断的市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarket *pMarket)
	{
		return !m_predict->isValid(pMarket);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketFilter是一个对已有的市场枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketFilter: public CMarketIterator
{
private:
	CMarketIterator *m_baseIterator;
	CMarketPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMarketFilter(CMarketIterator *pBaseIterator, CMarketPredict *pPredict, bool continueResult=false)
		:CMarketIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMarketFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMarket
	///@return	下一个满足条件CMarket，如果已经没有一个满足要求了，则返回NULL
	virtual CMarket *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarket 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketLinkIterator是连接两个市场枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketLinkIterator: public CMarketIterator
{
private:
	CMarketIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMarketLinkIterator(CMarketIterator *pBaseIterator1,CMarketIterator *pBaseIterator2)
		:CMarketIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMarketLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMarket
	///@return	下一个满足条件CMarket，如果已经没有一个满足要求了，则返回NULL
	virtual CMarket *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarket 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketProductSingleIterator是至多返回一个市场产品关联的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductSingleIterator: public CMarketProductIterator
{
private:
	CMarketProduct *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMarketProductSingleIterator(CMarketProductFactory *pFactory,CMarketProduct *pResult)
		:CMarketProductIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMarketProductSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMarketProduct
	///@return	下一个满足条件CMarketProduct，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProduct *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProduct 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductPredict是判断一个市场产品关联是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductPredict
{
public:
	///判断是否合法
	///@param	pMarketProduct	要被判断的市场产品关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProduct *pMarketProduct)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductAndPredict是对两个市场产品关联谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductAndPredict : public CMarketProductPredict
{
private:
	CMarketProductPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketProductAndPredict(CMarketProductPredict *p1, CMarketProductPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketProductAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketProduct	要被判断的市场产品关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProduct *pMarketProduct)
	{
		return m_p1->isValid(pMarketProduct) && m_p2->isValid(pMarketProduct);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductOrPredict是对两个市场产品关联谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductOrPredict : public CMarketProductPredict
{
private:
	CMarketProductPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketProductOrPredict(CMarketProductPredict *p1, CMarketProductPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketProductOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketProduct	要被判断的市场产品关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProduct *pMarketProduct)
	{
		return m_p1->isValid(pMarketProduct) || m_p2->isValid(pMarketProduct);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductNotPredict是对一个市场产品关联谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductNotPredict : public CMarketProductPredict
{
private:
	CMarketProductPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMarketProductNotPredict(CMarketProductPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMarketProductNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMarketProduct	要被判断的市场产品关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProduct *pMarketProduct)
	{
		return !m_predict->isValid(pMarketProduct);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductFilter是一个对已有的市场产品关联枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductFilter: public CMarketProductIterator
{
private:
	CMarketProductIterator *m_baseIterator;
	CMarketProductPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMarketProductFilter(CMarketProductIterator *pBaseIterator, CMarketProductPredict *pPredict, bool continueResult=false)
		:CMarketProductIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMarketProductFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMarketProduct
	///@return	下一个满足条件CMarketProduct，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProduct *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProduct 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductLinkIterator是连接两个市场产品关联枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductLinkIterator: public CMarketProductIterator
{
private:
	CMarketProductIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMarketProductLinkIterator(CMarketProductIterator *pBaseIterator1,CMarketProductIterator *pBaseIterator2)
		:CMarketProductIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMarketProductLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMarketProduct
	///@return	下一个满足条件CMarketProduct，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProduct *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProduct 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupSingleIterator是至多返回一个市场产品组关联的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupSingleIterator: public CMarketProductGroupIterator
{
private:
	CMarketProductGroup *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMarketProductGroupSingleIterator(CMarketProductGroupFactory *pFactory,CMarketProductGroup *pResult)
		:CMarketProductGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMarketProductGroupSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMarketProductGroup
	///@return	下一个满足条件CMarketProductGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProductGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProductGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupPredict是判断一个市场产品组关联是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupPredict
{
public:
	///判断是否合法
	///@param	pMarketProductGroup	要被判断的市场产品组关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupAndPredict是对两个市场产品组关联谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupAndPredict : public CMarketProductGroupPredict
{
private:
	CMarketProductGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketProductGroupAndPredict(CMarketProductGroupPredict *p1, CMarketProductGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketProductGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketProductGroup	要被判断的市场产品组关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)
	{
		return m_p1->isValid(pMarketProductGroup) && m_p2->isValid(pMarketProductGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupOrPredict是对两个市场产品组关联谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupOrPredict : public CMarketProductGroupPredict
{
private:
	CMarketProductGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketProductGroupOrPredict(CMarketProductGroupPredict *p1, CMarketProductGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketProductGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketProductGroup	要被判断的市场产品组关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)
	{
		return m_p1->isValid(pMarketProductGroup) || m_p2->isValid(pMarketProductGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupNotPredict是对一个市场产品组关联谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupNotPredict : public CMarketProductGroupPredict
{
private:
	CMarketProductGroupPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMarketProductGroupNotPredict(CMarketProductGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMarketProductGroupNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMarketProductGroup	要被判断的市场产品组关联
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketProductGroup *pMarketProductGroup)
	{
		return !m_predict->isValid(pMarketProductGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupFilter是一个对已有的市场产品组关联枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupFilter: public CMarketProductGroupIterator
{
private:
	CMarketProductGroupIterator *m_baseIterator;
	CMarketProductGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMarketProductGroupFilter(CMarketProductGroupIterator *pBaseIterator, CMarketProductGroupPredict *pPredict, bool continueResult=false)
		:CMarketProductGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMarketProductGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMarketProductGroup
	///@return	下一个满足条件CMarketProductGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProductGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProductGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupLinkIterator是连接两个市场产品组关联枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupLinkIterator: public CMarketProductGroupIterator
{
private:
	CMarketProductGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMarketProductGroupLinkIterator(CMarketProductGroupIterator *pBaseIterator1,CMarketProductGroupIterator *pBaseIterator2)
		:CMarketProductGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMarketProductGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMarketProductGroup
	///@return	下一个满足条件CMarketProductGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketProductGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketProductGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMdPubStatusSingleIterator是至多返回一个行情发布状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusSingleIterator: public CMdPubStatusIterator
{
private:
	CMdPubStatus *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMdPubStatusSingleIterator(CMdPubStatusFactory *pFactory,CMdPubStatus *pResult)
		:CMdPubStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMdPubStatusSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMdPubStatus
	///@return	下一个满足条件CMdPubStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CMdPubStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMdPubStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusPredict是判断一个行情发布状态是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusPredict
{
public:
	///判断是否合法
	///@param	pMdPubStatus	要被判断的行情发布状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMdPubStatus *pMdPubStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusAndPredict是对两个行情发布状态谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusAndPredict : public CMdPubStatusPredict
{
private:
	CMdPubStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMdPubStatusAndPredict(CMdPubStatusPredict *p1, CMdPubStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMdPubStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMdPubStatus	要被判断的行情发布状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMdPubStatus *pMdPubStatus)
	{
		return m_p1->isValid(pMdPubStatus) && m_p2->isValid(pMdPubStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusOrPredict是对两个行情发布状态谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusOrPredict : public CMdPubStatusPredict
{
private:
	CMdPubStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMdPubStatusOrPredict(CMdPubStatusPredict *p1, CMdPubStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMdPubStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMdPubStatus	要被判断的行情发布状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMdPubStatus *pMdPubStatus)
	{
		return m_p1->isValid(pMdPubStatus) || m_p2->isValid(pMdPubStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusNotPredict是对一个行情发布状态谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusNotPredict : public CMdPubStatusPredict
{
private:
	CMdPubStatusPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMdPubStatusNotPredict(CMdPubStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMdPubStatusNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMdPubStatus	要被判断的行情发布状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMdPubStatus *pMdPubStatus)
	{
		return !m_predict->isValid(pMdPubStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusFilter是一个对已有的行情发布状态枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusFilter: public CMdPubStatusIterator
{
private:
	CMdPubStatusIterator *m_baseIterator;
	CMdPubStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMdPubStatusFilter(CMdPubStatusIterator *pBaseIterator, CMdPubStatusPredict *pPredict, bool continueResult=false)
		:CMdPubStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMdPubStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMdPubStatus
	///@return	下一个满足条件CMdPubStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CMdPubStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMdPubStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusLinkIterator是连接两个行情发布状态枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusLinkIterator: public CMdPubStatusIterator
{
private:
	CMdPubStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMdPubStatusLinkIterator(CMdPubStatusIterator *pBaseIterator1,CMdPubStatusIterator *pBaseIterator2)
		:CMdPubStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMdPubStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMdPubStatus
	///@return	下一个满足条件CMdPubStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CMdPubStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMdPubStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicSingleIterator是至多返回一个行情主题的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicSingleIterator: public CMarketDataTopicIterator
{
private:
	CMarketDataTopic *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMarketDataTopicSingleIterator(CMarketDataTopicFactory *pFactory,CMarketDataTopic *pResult)
		:CMarketDataTopicIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMarketDataTopicSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMarketDataTopic
	///@return	下一个满足条件CMarketDataTopic，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataTopic *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataTopic 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicPredict是判断一个行情主题是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicPredict
{
public:
	///判断是否合法
	///@param	pMarketDataTopic	要被判断的行情主题
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicAndPredict是对两个行情主题谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicAndPredict : public CMarketDataTopicPredict
{
private:
	CMarketDataTopicPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataTopicAndPredict(CMarketDataTopicPredict *p1, CMarketDataTopicPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataTopicAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketDataTopic	要被判断的行情主题
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)
	{
		return m_p1->isValid(pMarketDataTopic) && m_p2->isValid(pMarketDataTopic);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicOrPredict是对两个行情主题谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicOrPredict : public CMarketDataTopicPredict
{
private:
	CMarketDataTopicPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataTopicOrPredict(CMarketDataTopicPredict *p1, CMarketDataTopicPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataTopicOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketDataTopic	要被判断的行情主题
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)
	{
		return m_p1->isValid(pMarketDataTopic) || m_p2->isValid(pMarketDataTopic);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicNotPredict是对一个行情主题谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicNotPredict : public CMarketDataTopicPredict
{
private:
	CMarketDataTopicPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMarketDataTopicNotPredict(CMarketDataTopicPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMarketDataTopicNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMarketDataTopic	要被判断的行情主题
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataTopic *pMarketDataTopic)
	{
		return !m_predict->isValid(pMarketDataTopic);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicFilter是一个对已有的行情主题枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicFilter: public CMarketDataTopicIterator
{
private:
	CMarketDataTopicIterator *m_baseIterator;
	CMarketDataTopicPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMarketDataTopicFilter(CMarketDataTopicIterator *pBaseIterator, CMarketDataTopicPredict *pPredict, bool continueResult=false)
		:CMarketDataTopicIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMarketDataTopicFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMarketDataTopic
	///@return	下一个满足条件CMarketDataTopic，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataTopic *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataTopic 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicLinkIterator是连接两个行情主题枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicLinkIterator: public CMarketDataTopicIterator
{
private:
	CMarketDataTopicIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMarketDataTopicLinkIterator(CMarketDataTopicIterator *pBaseIterator1,CMarketDataTopicIterator *pBaseIterator2)
		:CMarketDataTopicIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMarketDataTopicLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMarketDataTopic
	///@return	下一个满足条件CMarketDataTopic，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataTopic *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataTopic 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeSingleIterator是至多返回一个会员订阅市场的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeSingleIterator: public CPartTopicSubscribeIterator
{
private:
	CPartTopicSubscribe *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartTopicSubscribeSingleIterator(CPartTopicSubscribeFactory *pFactory,CPartTopicSubscribe *pResult)
		:CPartTopicSubscribeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartTopicSubscribeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartTopicSubscribe
	///@return	下一个满足条件CPartTopicSubscribe，如果已经没有一个满足要求了，则返回NULL
	virtual CPartTopicSubscribe *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartTopicSubscribe 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribePredict是判断一个会员订阅市场是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribePredict
{
public:
	///判断是否合法
	///@param	pPartTopicSubscribe	要被判断的会员订阅市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeAndPredict是对两个会员订阅市场谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeAndPredict : public CPartTopicSubscribePredict
{
private:
	CPartTopicSubscribePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartTopicSubscribeAndPredict(CPartTopicSubscribePredict *p1, CPartTopicSubscribePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartTopicSubscribeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartTopicSubscribe	要被判断的会员订阅市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return m_p1->isValid(pPartTopicSubscribe) && m_p2->isValid(pPartTopicSubscribe);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeOrPredict是对两个会员订阅市场谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeOrPredict : public CPartTopicSubscribePredict
{
private:
	CPartTopicSubscribePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartTopicSubscribeOrPredict(CPartTopicSubscribePredict *p1, CPartTopicSubscribePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartTopicSubscribeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartTopicSubscribe	要被判断的会员订阅市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return m_p1->isValid(pPartTopicSubscribe) || m_p2->isValid(pPartTopicSubscribe);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeNotPredict是对一个会员订阅市场谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeNotPredict : public CPartTopicSubscribePredict
{
private:
	CPartTopicSubscribePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartTopicSubscribeNotPredict(CPartTopicSubscribePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartTopicSubscribeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartTopicSubscribe	要被判断的会员订阅市场
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return !m_predict->isValid(pPartTopicSubscribe);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeFilter是一个对已有的会员订阅市场枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeFilter: public CPartTopicSubscribeIterator
{
private:
	CPartTopicSubscribeIterator *m_baseIterator;
	CPartTopicSubscribePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartTopicSubscribeFilter(CPartTopicSubscribeIterator *pBaseIterator, CPartTopicSubscribePredict *pPredict, bool continueResult=false)
		:CPartTopicSubscribeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartTopicSubscribeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartTopicSubscribe
	///@return	下一个满足条件CPartTopicSubscribe，如果已经没有一个满足要求了，则返回NULL
	virtual CPartTopicSubscribe *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartTopicSubscribe 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeLinkIterator是连接两个会员订阅市场枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeLinkIterator: public CPartTopicSubscribeIterator
{
private:
	CPartTopicSubscribeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartTopicSubscribeLinkIterator(CPartTopicSubscribeIterator *pBaseIterator1,CPartTopicSubscribeIterator *pBaseIterator2)
		:CPartTopicSubscribeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartTopicSubscribeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartTopicSubscribe
	///@return	下一个满足条件CPartTopicSubscribe，如果已经没有一个满足要求了，则返回NULL
	virtual CPartTopicSubscribe *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartTopicSubscribe 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CParticipantSingleIterator是至多返回一个会员的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantSingleIterator: public CParticipantIterator
{
private:
	CParticipant *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CParticipantSingleIterator(CParticipantFactory *pFactory,CParticipant *pResult)
		:CParticipantIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CParticipantSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CParticipant
	///@return	下一个满足条件CParticipant，如果已经没有一个满足要求了，则返回NULL
	virtual CParticipant *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantPredict是判断一个会员是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantPredict
{
public:
	///判断是否合法
	///@param	pParticipant	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CParticipant *pParticipant)=0;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantAndPredict是对两个会员谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantAndPredict : public CParticipantPredict
{
private:
	CParticipantPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CParticipantAndPredict(CParticipantPredict *p1, CParticipantPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CParticipantAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pParticipant	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CParticipant *pParticipant)
	{
		return m_p1->isValid(pParticipant) && m_p2->isValid(pParticipant);
	}
};

/////////////////////////////////////////////////////////////////////////
///CParticipantOrPredict是对两个会员谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantOrPredict : public CParticipantPredict
{
private:
	CParticipantPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CParticipantOrPredict(CParticipantPredict *p1, CParticipantPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CParticipantOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pParticipant	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CParticipant *pParticipant)
	{
		return m_p1->isValid(pParticipant) || m_p2->isValid(pParticipant);
	}
};

/////////////////////////////////////////////////////////////////////////
///CParticipantNotPredict是对一个会员谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantNotPredict : public CParticipantPredict
{
private:
	CParticipantPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CParticipantNotPredict(CParticipantPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CParticipantNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pParticipant	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CParticipant *pParticipant)
	{
		return !m_predict->isValid(pParticipant);
	}
};

/////////////////////////////////////////////////////////////////////////
///CParticipantFilter是一个对已有的会员枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantFilter: public CParticipantIterator
{
private:
	CParticipantIterator *m_baseIterator;
	CParticipantPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CParticipantFilter(CParticipantIterator *pBaseIterator, CParticipantPredict *pPredict, bool continueResult=false)
		:CParticipantIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CParticipantFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CParticipant
	///@return	下一个满足条件CParticipant，如果已经没有一个满足要求了，则返回NULL
	virtual CParticipant *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantLinkIterator是连接两个会员枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantLinkIterator: public CParticipantIterator
{
private:
	CParticipantIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CParticipantLinkIterator(CParticipantIterator *pBaseIterator1,CParticipantIterator *pBaseIterator2)
		:CParticipantIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CParticipantLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CParticipant
	///@return	下一个满足条件CParticipant，如果已经没有一个满足要求了，则返回NULL
	virtual CParticipant *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartOfParticipantIterator是一个会员枚举器对应的结算交易会员关系的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartOfParticipantIterator: public CClearingTradingPartIterator
{
private:
	CParticipantIterator *m_baseIterator;
	CClearingTradingPart *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CClearingTradingPartOfParticipantIterator(CClearingTradingPartFactory *pFactory,CParticipantIterator *pBaseIterator)
		:CClearingTradingPartIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CClearingTradingPartOfParticipantIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CClearingTradingPart
	///@return	下一个满足条件CClearingTradingPart，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingTradingPart *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClearingTradingPart 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingTradingPart *pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserSingleIterator是至多返回一个用户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSingleIterator: public CUserIterator
{
private:
	CUser *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CUserSingleIterator(CUserFactory *pFactory,CUser *pResult)
		:CUserIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CUserSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CUser
	///@return	下一个满足条件CUser，如果已经没有一个满足要求了，则返回NULL
	virtual CUser *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUser 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserPredict是判断一个用户是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserPredict
{
public:
	///判断是否合法
	///@param	pUser	要被判断的用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUser *pUser)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserAndPredict是对两个用户谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserAndPredict : public CUserPredict
{
private:
	CUserPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserAndPredict(CUserPredict *p1, CUserPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUser	要被判断的用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUser *pUser)
	{
		return m_p1->isValid(pUser) && m_p2->isValid(pUser);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserOrPredict是对两个用户谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserOrPredict : public CUserPredict
{
private:
	CUserPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserOrPredict(CUserPredict *p1, CUserPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUser	要被判断的用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUser *pUser)
	{
		return m_p1->isValid(pUser) || m_p2->isValid(pUser);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserNotPredict是对一个用户谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserNotPredict : public CUserPredict
{
private:
	CUserPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CUserNotPredict(CUserPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CUserNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pUser	要被判断的用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUser *pUser)
	{
		return !m_predict->isValid(pUser);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFilter是一个对已有的用户枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFilter: public CUserIterator
{
private:
	CUserIterator *m_baseIterator;
	CUserPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CUserFilter(CUserIterator *pBaseIterator, CUserPredict *pPredict, bool continueResult=false)
		:CUserIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CUserFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CUser
	///@return	下一个满足条件CUser，如果已经没有一个满足要求了，则返回NULL
	virtual CUser *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUser 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserLinkIterator是连接两个用户枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserLinkIterator: public CUserIterator
{
private:
	CUserIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CUserLinkIterator(CUserIterator *pBaseIterator1,CUserIterator *pBaseIterator2)
		:CUserIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CUserLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CUser
	///@return	下一个满足条件CUser，如果已经没有一个满足要求了，则返回NULL
	virtual CUser *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUser 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientSingleIterator是至多返回一个客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientSingleIterator: public CClientIterator
{
private:
	CClient *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CClientSingleIterator(CClientFactory *pFactory,CClient *pResult)
		:CClientIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CClientSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CClient
	///@return	下一个满足条件CClient，如果已经没有一个满足要求了，则返回NULL
	virtual CClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPredict是判断一个客户是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPredict
{
public:
	///判断是否合法
	///@param	pClient	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClient *pClient)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientAndPredict是对两个客户谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientAndPredict : public CClientPredict
{
private:
	CClientPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientAndPredict(CClientPredict *p1, CClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClient	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClient *pClient)
	{
		return m_p1->isValid(pClient) && m_p2->isValid(pClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientOrPredict是对两个客户谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientOrPredict : public CClientPredict
{
private:
	CClientPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientOrPredict(CClientPredict *p1, CClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClient	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClient *pClient)
	{
		return m_p1->isValid(pClient) || m_p2->isValid(pClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientNotPredict是对一个客户谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientNotPredict : public CClientPredict
{
private:
	CClientPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CClientNotPredict(CClientPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CClientNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pClient	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClient *pClient)
	{
		return !m_predict->isValid(pClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientFilter是一个对已有的客户枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientFilter: public CClientIterator
{
private:
	CClientIterator *m_baseIterator;
	CClientPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CClientFilter(CClientIterator *pBaseIterator, CClientPredict *pPredict, bool continueResult=false)
		:CClientIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CClientFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CClient
	///@return	下一个满足条件CClient，如果已经没有一个满足要求了，则返回NULL
	virtual CClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientLinkIterator是连接两个客户枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientLinkIterator: public CClientIterator
{
private:
	CClientIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CClientLinkIterator(CClientIterator *pBaseIterator1,CClientIterator *pBaseIterator2)
		:CClientIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CClientLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CClient
	///@return	下一个满足条件CClient，如果已经没有一个满足要求了，则返回NULL
	virtual CClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserIPSingleIterator是至多返回一个交易员IP地址的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPSingleIterator: public CUserIPIterator
{
private:
	CUserIP *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CUserIPSingleIterator(CUserIPFactory *pFactory,CUserIP *pResult)
		:CUserIPIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CUserIPSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CUserIP
	///@return	下一个满足条件CUserIP，如果已经没有一个满足要求了，则返回NULL
	virtual CUserIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserIPPredict是判断一个交易员IP地址是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPPredict
{
public:
	///判断是否合法
	///@param	pUserIP	要被判断的交易员IP地址
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserIP *pUserIP)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPAndPredict是对两个交易员IP地址谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPAndPredict : public CUserIPPredict
{
private:
	CUserIPPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserIPAndPredict(CUserIPPredict *p1, CUserIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserIPAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserIP	要被判断的交易员IP地址
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserIP *pUserIP)
	{
		return m_p1->isValid(pUserIP) && m_p2->isValid(pUserIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserIPOrPredict是对两个交易员IP地址谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPOrPredict : public CUserIPPredict
{
private:
	CUserIPPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserIPOrPredict(CUserIPPredict *p1, CUserIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserIPOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserIP	要被判断的交易员IP地址
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserIP *pUserIP)
	{
		return m_p1->isValid(pUserIP) || m_p2->isValid(pUserIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserIPNotPredict是对一个交易员IP地址谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPNotPredict : public CUserIPPredict
{
private:
	CUserIPPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CUserIPNotPredict(CUserIPPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CUserIPNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pUserIP	要被判断的交易员IP地址
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserIP *pUserIP)
	{
		return !m_predict->isValid(pUserIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserIPFilter是一个对已有的交易员IP地址枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPFilter: public CUserIPIterator
{
private:
	CUserIPIterator *m_baseIterator;
	CUserIPPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CUserIPFilter(CUserIPIterator *pBaseIterator, CUserIPPredict *pPredict, bool continueResult=false)
		:CUserIPIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CUserIPFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CUserIP
	///@return	下一个满足条件CUserIP，如果已经没有一个满足要求了，则返回NULL
	virtual CUserIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserIPLinkIterator是连接两个交易员IP地址枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPLinkIterator: public CUserIPIterator
{
private:
	CUserIPIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CUserIPLinkIterator(CUserIPIterator *pBaseIterator1,CUserIPIterator *pBaseIterator2)
		:CUserIPIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CUserIPLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CUserIP
	///@return	下一个满足条件CUserIP，如果已经没有一个满足要求了，则返回NULL
	virtual CUserIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartClientSingleIterator是至多返回一个会员客户关系的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientSingleIterator: public CPartClientIterator
{
private:
	CPartClient *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartClientSingleIterator(CPartClientFactory *pFactory,CPartClient *pResult)
		:CPartClientIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartClientSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientPredict是判断一个会员客户关系是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientPredict
{
public:
	///判断是否合法
	///@param	pPartClient	要被判断的会员客户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClient *pPartClient)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientAndPredict是对两个会员客户关系谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientAndPredict : public CPartClientPredict
{
private:
	CPartClientPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartClientAndPredict(CPartClientPredict *p1, CPartClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartClientAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartClient	要被判断的会员客户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClient *pPartClient)
	{
		return m_p1->isValid(pPartClient) && m_p2->isValid(pPartClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOrPredict是对两个会员客户关系谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOrPredict : public CPartClientPredict
{
private:
	CPartClientPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartClientOrPredict(CPartClientPredict *p1, CPartClientPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartClientOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartClient	要被判断的会员客户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClient *pPartClient)
	{
		return m_p1->isValid(pPartClient) || m_p2->isValid(pPartClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientNotPredict是对一个会员客户关系谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientNotPredict : public CPartClientPredict
{
private:
	CPartClientPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartClientNotPredict(CPartClientPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartClientNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartClient	要被判断的会员客户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClient *pPartClient)
	{
		return !m_predict->isValid(pPartClient);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientFilter是一个对已有的会员客户关系枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientFilter: public CPartClientIterator
{
private:
	CPartClientIterator *m_baseIterator;
	CPartClientPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartClientFilter(CPartClientIterator *pBaseIterator, CPartClientPredict *pPredict, bool continueResult=false)
		:CPartClientIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartClientFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientLinkIterator是连接两个会员客户关系枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientLinkIterator: public CPartClientIterator
{
private:
	CPartClientIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartClientLinkIterator(CPartClientIterator *pBaseIterator1,CPartClientIterator *pBaseIterator2)
		:CPartClientIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartClientLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CParticipantOfPartClientIterator是一个会员客户关系枚举器对应的会员的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantOfPartClientIterator: public CParticipantIterator
{
private:
	CPartClientIterator *m_baseIterator;
	CParticipant *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CParticipantOfPartClientIterator(CParticipantFactory *pFactory,CPartClientIterator *pBaseIterator)
		:CParticipantIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CParticipantOfPartClientIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CParticipant
	///@return	下一个满足条件CParticipant，如果已经没有一个满足要求了，则返回NULL
	virtual CParticipant *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pParticipant 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableParticipant *pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientOfPartClientIterator是一个会员客户关系枚举器对应的客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientOfPartClientIterator: public CClientIterator
{
private:
	CPartClientIterator *m_baseIterator;
	CClient *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CClientOfPartClientIterator(CClientFactory *pFactory,CPartClientIterator *pBaseIterator)
		:CClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CClientOfPartClientIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CClient
	///@return	下一个满足条件CClient，如果已经没有一个满足要求了，则返回NULL
	virtual CClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClient *pClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartSingleIterator是至多返回一个结算交易会员关系的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartSingleIterator: public CClearingTradingPartIterator
{
private:
	CClearingTradingPart *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CClearingTradingPartSingleIterator(CClearingTradingPartFactory *pFactory,CClearingTradingPart *pResult)
		:CClearingTradingPartIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CClearingTradingPartSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CClearingTradingPart
	///@return	下一个满足条件CClearingTradingPart，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingTradingPart *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClearingTradingPart 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartPredict是判断一个结算交易会员关系是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartPredict
{
public:
	///判断是否合法
	///@param	pClearingTradingPart	要被判断的结算交易会员关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartAndPredict是对两个结算交易会员关系谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartAndPredict : public CClearingTradingPartPredict
{
private:
	CClearingTradingPartPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClearingTradingPartAndPredict(CClearingTradingPartPredict *p1, CClearingTradingPartPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClearingTradingPartAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClearingTradingPart	要被判断的结算交易会员关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)
	{
		return m_p1->isValid(pClearingTradingPart) && m_p2->isValid(pClearingTradingPart);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartOrPredict是对两个结算交易会员关系谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartOrPredict : public CClearingTradingPartPredict
{
private:
	CClearingTradingPartPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClearingTradingPartOrPredict(CClearingTradingPartPredict *p1, CClearingTradingPartPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClearingTradingPartOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClearingTradingPart	要被判断的结算交易会员关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)
	{
		return m_p1->isValid(pClearingTradingPart) || m_p2->isValid(pClearingTradingPart);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartNotPredict是对一个结算交易会员关系谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartNotPredict : public CClearingTradingPartPredict
{
private:
	CClearingTradingPartPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CClearingTradingPartNotPredict(CClearingTradingPartPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CClearingTradingPartNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pClearingTradingPart	要被判断的结算交易会员关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingTradingPart *pClearingTradingPart)
	{
		return !m_predict->isValid(pClearingTradingPart);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartFilter是一个对已有的结算交易会员关系枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartFilter: public CClearingTradingPartIterator
{
private:
	CClearingTradingPartIterator *m_baseIterator;
	CClearingTradingPartPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CClearingTradingPartFilter(CClearingTradingPartIterator *pBaseIterator, CClearingTradingPartPredict *pPredict, bool continueResult=false)
		:CClearingTradingPartIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CClearingTradingPartFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CClearingTradingPart
	///@return	下一个满足条件CClearingTradingPart，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingTradingPart *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClearingTradingPart 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartLinkIterator是连接两个结算交易会员关系枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartLinkIterator: public CClearingTradingPartIterator
{
private:
	CClearingTradingPartIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CClearingTradingPartLinkIterator(CClearingTradingPartIterator *pBaseIterator1,CClearingTradingPartIterator *pBaseIterator2)
		:CClearingTradingPartIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CClearingTradingPartLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CClearingTradingPart
	///@return	下一个满足条件CClearingTradingPart，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingTradingPart *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClearingTradingPart 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CAliasDefineSingleIterator是至多返回一个别名定义的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineSingleIterator: public CAliasDefineIterator
{
private:
	CAliasDefine *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CAliasDefineSingleIterator(CAliasDefineFactory *pFactory,CAliasDefine *pResult)
		:CAliasDefineIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CAliasDefineSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CAliasDefine
	///@return	下一个满足条件CAliasDefine，如果已经没有一个满足要求了，则返回NULL
	virtual CAliasDefine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAliasDefine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefinePredict是判断一个别名定义是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefinePredict
{
public:
	///判断是否合法
	///@param	pAliasDefine	要被判断的别名定义
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAliasDefine *pAliasDefine)=0;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineAndPredict是对两个别名定义谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineAndPredict : public CAliasDefinePredict
{
private:
	CAliasDefinePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CAliasDefineAndPredict(CAliasDefinePredict *p1, CAliasDefinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CAliasDefineAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pAliasDefine	要被判断的别名定义
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAliasDefine *pAliasDefine)
	{
		return m_p1->isValid(pAliasDefine) && m_p2->isValid(pAliasDefine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineOrPredict是对两个别名定义谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineOrPredict : public CAliasDefinePredict
{
private:
	CAliasDefinePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CAliasDefineOrPredict(CAliasDefinePredict *p1, CAliasDefinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CAliasDefineOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pAliasDefine	要被判断的别名定义
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAliasDefine *pAliasDefine)
	{
		return m_p1->isValid(pAliasDefine) || m_p2->isValid(pAliasDefine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineNotPredict是对一个别名定义谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineNotPredict : public CAliasDefinePredict
{
private:
	CAliasDefinePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CAliasDefineNotPredict(CAliasDefinePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CAliasDefineNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pAliasDefine	要被判断的别名定义
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAliasDefine *pAliasDefine)
	{
		return !m_predict->isValid(pAliasDefine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineFilter是一个对已有的别名定义枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineFilter: public CAliasDefineIterator
{
private:
	CAliasDefineIterator *m_baseIterator;
	CAliasDefinePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CAliasDefineFilter(CAliasDefineIterator *pBaseIterator, CAliasDefinePredict *pPredict, bool continueResult=false)
		:CAliasDefineIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CAliasDefineFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CAliasDefine
	///@return	下一个满足条件CAliasDefine，如果已经没有一个满足要求了，则返回NULL
	virtual CAliasDefine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAliasDefine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineLinkIterator是连接两个别名定义枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineLinkIterator: public CAliasDefineIterator
{
private:
	CAliasDefineIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CAliasDefineLinkIterator(CAliasDefineIterator *pBaseIterator1,CAliasDefineIterator *pBaseIterator2)
		:CAliasDefineIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CAliasDefineLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CAliasDefine
	///@return	下一个满足条件CAliasDefine，如果已经没有一个满足要求了，则返回NULL
	virtual CAliasDefine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAliasDefine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightSingleIterator是至多返回一个用户功能权限的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightSingleIterator: public CUserFunctionRightIterator
{
private:
	CUserFunctionRight *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CUserFunctionRightSingleIterator(CUserFunctionRightFactory *pFactory,CUserFunctionRight *pResult)
		:CUserFunctionRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CUserFunctionRightSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CUserFunctionRight
	///@return	下一个满足条件CUserFunctionRight，如果已经没有一个满足要求了，则返回NULL
	virtual CUserFunctionRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserFunctionRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightPredict是判断一个用户功能权限是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightPredict
{
public:
	///判断是否合法
	///@param	pUserFunctionRight	要被判断的用户功能权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightAndPredict是对两个用户功能权限谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightAndPredict : public CUserFunctionRightPredict
{
private:
	CUserFunctionRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserFunctionRightAndPredict(CUserFunctionRightPredict *p1, CUserFunctionRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserFunctionRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserFunctionRight	要被判断的用户功能权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)
	{
		return m_p1->isValid(pUserFunctionRight) && m_p2->isValid(pUserFunctionRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightOrPredict是对两个用户功能权限谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightOrPredict : public CUserFunctionRightPredict
{
private:
	CUserFunctionRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserFunctionRightOrPredict(CUserFunctionRightPredict *p1, CUserFunctionRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserFunctionRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserFunctionRight	要被判断的用户功能权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)
	{
		return m_p1->isValid(pUserFunctionRight) || m_p2->isValid(pUserFunctionRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightNotPredict是对一个用户功能权限谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightNotPredict : public CUserFunctionRightPredict
{
private:
	CUserFunctionRightPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CUserFunctionRightNotPredict(CUserFunctionRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CUserFunctionRightNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pUserFunctionRight	要被判断的用户功能权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserFunctionRight *pUserFunctionRight)
	{
		return !m_predict->isValid(pUserFunctionRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightFilter是一个对已有的用户功能权限枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightFilter: public CUserFunctionRightIterator
{
private:
	CUserFunctionRightIterator *m_baseIterator;
	CUserFunctionRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CUserFunctionRightFilter(CUserFunctionRightIterator *pBaseIterator, CUserFunctionRightPredict *pPredict, bool continueResult=false)
		:CUserFunctionRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CUserFunctionRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CUserFunctionRight
	///@return	下一个满足条件CUserFunctionRight，如果已经没有一个满足要求了，则返回NULL
	virtual CUserFunctionRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserFunctionRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightLinkIterator是连接两个用户功能权限枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightLinkIterator: public CUserFunctionRightIterator
{
private:
	CUserFunctionRightIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CUserFunctionRightLinkIterator(CUserFunctionRightIterator *pBaseIterator1,CUserFunctionRightIterator *pBaseIterator2)
		:CUserFunctionRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CUserFunctionRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CUserFunctionRight
	///@return	下一个满足条件CUserFunctionRight，如果已经没有一个满足要求了，则返回NULL
	virtual CUserFunctionRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserFunctionRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CAccountSingleIterator是至多返回一个资金账户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountSingleIterator: public CAccountIterator
{
private:
	CAccount *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CAccountSingleIterator(CAccountFactory *pFactory,CAccount *pResult)
		:CAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CAccountSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CAccount
	///@return	下一个满足条件CAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAccountPredict是判断一个资金账户是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountPredict
{
public:
	///判断是否合法
	///@param	pAccount	要被判断的资金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAccount *pAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CAccountAndPredict是对两个资金账户谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountAndPredict : public CAccountPredict
{
private:
	CAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CAccountAndPredict(CAccountPredict *p1, CAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pAccount	要被判断的资金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAccount *pAccount)
	{
		return m_p1->isValid(pAccount) && m_p2->isValid(pAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAccountOrPredict是对两个资金账户谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountOrPredict : public CAccountPredict
{
private:
	CAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CAccountOrPredict(CAccountPredict *p1, CAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pAccount	要被判断的资金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAccount *pAccount)
	{
		return m_p1->isValid(pAccount) || m_p2->isValid(pAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAccountNotPredict是对一个资金账户谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountNotPredict : public CAccountPredict
{
private:
	CAccountPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CAccountNotPredict(CAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CAccountNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pAccount	要被判断的资金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CAccount *pAccount)
	{
		return !m_predict->isValid(pAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CAccountFilter是一个对已有的资金账户枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountFilter: public CAccountIterator
{
private:
	CAccountIterator *m_baseIterator;
	CAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CAccountFilter(CAccountIterator *pBaseIterator, CAccountPredict *pPredict, bool continueResult=false)
		:CAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CAccount
	///@return	下一个满足条件CAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CAccountLinkIterator是连接两个资金账户枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountLinkIterator: public CAccountIterator
{
private:
	CAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CAccountLinkIterator(CAccountIterator *pBaseIterator1,CAccountIterator *pBaseIterator2)
		:CAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CAccount
	///@return	下一个满足条件CAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountOfAccountIterator是一个资金账户枚举器对应的交易账户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountOfAccountIterator: public CTradingAccountIterator
{
private:
	CAccountIterator *m_baseIterator;
	CTradingAccount *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CTradingAccountOfAccountIterator(CTradingAccountFactory *pFactory,CAccountIterator *pBaseIterator)
		:CTradingAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CTradingAccountOfAccountIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CTradingAccount
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CTradingAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTradingAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTradingAccount *pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserCommFluxSingleIterator是至多返回一个用户通讯量的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxSingleIterator: public CUserCommFluxIterator
{
private:
	CUserCommFlux *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CUserCommFluxSingleIterator(CUserCommFluxFactory *pFactory,CUserCommFlux *pResult)
		:CUserCommFluxIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CUserCommFluxSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CUserCommFlux
	///@return	下一个满足条件CUserCommFlux，如果已经没有一个满足要求了，则返回NULL
	virtual CUserCommFlux *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserCommFlux 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxPredict是判断一个用户通讯量是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxPredict
{
public:
	///判断是否合法
	///@param	pUserCommFlux	要被判断的用户通讯量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserCommFlux *pUserCommFlux)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxAndPredict是对两个用户通讯量谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxAndPredict : public CUserCommFluxPredict
{
private:
	CUserCommFluxPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserCommFluxAndPredict(CUserCommFluxPredict *p1, CUserCommFluxPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserCommFluxAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserCommFlux	要被判断的用户通讯量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserCommFlux *pUserCommFlux)
	{
		return m_p1->isValid(pUserCommFlux) && m_p2->isValid(pUserCommFlux);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxOrPredict是对两个用户通讯量谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxOrPredict : public CUserCommFluxPredict
{
private:
	CUserCommFluxPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserCommFluxOrPredict(CUserCommFluxPredict *p1, CUserCommFluxPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserCommFluxOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserCommFlux	要被判断的用户通讯量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserCommFlux *pUserCommFlux)
	{
		return m_p1->isValid(pUserCommFlux) || m_p2->isValid(pUserCommFlux);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxNotPredict是对一个用户通讯量谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxNotPredict : public CUserCommFluxPredict
{
private:
	CUserCommFluxPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CUserCommFluxNotPredict(CUserCommFluxPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CUserCommFluxNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pUserCommFlux	要被判断的用户通讯量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserCommFlux *pUserCommFlux)
	{
		return !m_predict->isValid(pUserCommFlux);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxFilter是一个对已有的用户通讯量枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxFilter: public CUserCommFluxIterator
{
private:
	CUserCommFluxIterator *m_baseIterator;
	CUserCommFluxPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CUserCommFluxFilter(CUserCommFluxIterator *pBaseIterator, CUserCommFluxPredict *pPredict, bool continueResult=false)
		:CUserCommFluxIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CUserCommFluxFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CUserCommFlux
	///@return	下一个满足条件CUserCommFlux，如果已经没有一个满足要求了，则返回NULL
	virtual CUserCommFlux *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserCommFlux 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxLinkIterator是连接两个用户通讯量枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxLinkIterator: public CUserCommFluxIterator
{
private:
	CUserCommFluxIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CUserCommFluxLinkIterator(CUserCommFluxIterator *pBaseIterator1,CUserCommFluxIterator *pBaseIterator2)
		:CUserCommFluxIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CUserCommFluxLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CUserCommFlux
	///@return	下一个满足条件CUserCommFlux，如果已经没有一个满足要求了，则返回NULL
	virtual CUserCommFlux *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserCommFlux 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataLogSingleIterator是至多返回一个行情流水的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogSingleIterator: public CMarketDataLogIterator
{
private:
	CMarketDataLog *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMarketDataLogSingleIterator(CMarketDataLogFactory *pFactory,CMarketDataLog *pResult)
		:CMarketDataLogIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMarketDataLogSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMarketDataLog
	///@return	下一个满足条件CMarketDataLog，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataLog *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataLog 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogPredict是判断一个行情流水是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogPredict
{
public:
	///判断是否合法
	///@param	pMarketDataLog	要被判断的行情流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataLog *pMarketDataLog)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogAndPredict是对两个行情流水谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogAndPredict : public CMarketDataLogPredict
{
private:
	CMarketDataLogPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataLogAndPredict(CMarketDataLogPredict *p1, CMarketDataLogPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataLogAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketDataLog	要被判断的行情流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataLog *pMarketDataLog)
	{
		return m_p1->isValid(pMarketDataLog) && m_p2->isValid(pMarketDataLog);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogOrPredict是对两个行情流水谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogOrPredict : public CMarketDataLogPredict
{
private:
	CMarketDataLogPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataLogOrPredict(CMarketDataLogPredict *p1, CMarketDataLogPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataLogOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketDataLog	要被判断的行情流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataLog *pMarketDataLog)
	{
		return m_p1->isValid(pMarketDataLog) || m_p2->isValid(pMarketDataLog);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogNotPredict是对一个行情流水谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogNotPredict : public CMarketDataLogPredict
{
private:
	CMarketDataLogPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMarketDataLogNotPredict(CMarketDataLogPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMarketDataLogNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMarketDataLog	要被判断的行情流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataLog *pMarketDataLog)
	{
		return !m_predict->isValid(pMarketDataLog);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogFilter是一个对已有的行情流水枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogFilter: public CMarketDataLogIterator
{
private:
	CMarketDataLogIterator *m_baseIterator;
	CMarketDataLogPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMarketDataLogFilter(CMarketDataLogIterator *pBaseIterator, CMarketDataLogPredict *pPredict, bool continueResult=false)
		:CMarketDataLogIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMarketDataLogFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMarketDataLog
	///@return	下一个满足条件CMarketDataLog，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataLog *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataLog 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogLinkIterator是连接两个行情流水枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogLinkIterator: public CMarketDataLogIterator
{
private:
	CMarketDataLogIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMarketDataLogLinkIterator(CMarketDataLogIterator *pBaseIterator1,CMarketDataLogIterator *pBaseIterator2)
		:CMarketDataLogIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMarketDataLogLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMarketDataLog
	///@return	下一个满足条件CMarketDataLog，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataLog *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataLog 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUserSessionSingleIterator是至多返回一个交易员在线会话的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionSingleIterator: public CUserSessionIterator
{
private:
	CUserSession *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CUserSessionSingleIterator(CUserSessionFactory *pFactory,CUserSession *pResult)
		:CUserSessionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CUserSessionSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CUserSession
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	virtual CUserSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionPredict是判断一个交易员在线会话是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionPredict
{
public:
	///判断是否合法
	///@param	pUserSession	要被判断的交易员在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserSession *pUserSession)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionAndPredict是对两个交易员在线会话谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionAndPredict : public CUserSessionPredict
{
private:
	CUserSessionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserSessionAndPredict(CUserSessionPredict *p1, CUserSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserSessionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserSession	要被判断的交易员在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserSession *pUserSession)
	{
		return m_p1->isValid(pUserSession) && m_p2->isValid(pUserSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionOrPredict是对两个交易员在线会话谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionOrPredict : public CUserSessionPredict
{
private:
	CUserSessionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUserSessionOrPredict(CUserSessionPredict *p1, CUserSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUserSessionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUserSession	要被判断的交易员在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserSession *pUserSession)
	{
		return m_p1->isValid(pUserSession) || m_p2->isValid(pUserSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionNotPredict是对一个交易员在线会话谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionNotPredict : public CUserSessionPredict
{
private:
	CUserSessionPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CUserSessionNotPredict(CUserSessionPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CUserSessionNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pUserSession	要被判断的交易员在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUserSession *pUserSession)
	{
		return !m_predict->isValid(pUserSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionFilter是一个对已有的交易员在线会话枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionFilter: public CUserSessionIterator
{
private:
	CUserSessionIterator *m_baseIterator;
	CUserSessionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CUserSessionFilter(CUserSessionIterator *pBaseIterator, CUserSessionPredict *pPredict, bool continueResult=false)
		:CUserSessionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CUserSessionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CUserSession
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	virtual CUserSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionLinkIterator是连接两个交易员在线会话枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionLinkIterator: public CUserSessionIterator
{
private:
	CUserSessionIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CUserSessionLinkIterator(CUserSessionIterator *pBaseIterator1,CUserSessionIterator *pBaseIterator2)
		:CUserSessionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CUserSessionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CUserSession
	///@return	下一个满足条件CUserSession，如果已经没有一个满足要求了，则返回NULL
	virtual CUserSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUserSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUserOfUserSessionIterator是一个交易员在线会话枚举器对应的交易员的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserOfUserSessionIterator: public CUserIterator
{
private:
	CUserSessionIterator *m_baseIterator;
	CUser *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CUserOfUserSessionIterator(CUserFactory *pFactory,CUserSessionIterator *pBaseIterator)
		:CUserIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CUserOfUserSessionIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CUser
	///@return	下一个满足条件CUser，如果已经没有一个满足要求了，则返回NULL
	virtual CUser *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUser 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUser *pUser,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMDSessionSingleIterator是至多返回一个行情订阅者在线会话的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionSingleIterator: public CMDSessionIterator
{
private:
	CMDSession *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMDSessionSingleIterator(CMDSessionFactory *pFactory,CMDSession *pResult)
		:CMDSessionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMDSessionSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMDSession
	///@return	下一个满足条件CMDSession，如果已经没有一个满足要求了，则返回NULL
	virtual CMDSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMDSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionPredict是判断一个行情订阅者在线会话是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionPredict
{
public:
	///判断是否合法
	///@param	pMDSession	要被判断的行情订阅者在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMDSession *pMDSession)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionAndPredict是对两个行情订阅者在线会话谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionAndPredict : public CMDSessionPredict
{
private:
	CMDSessionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMDSessionAndPredict(CMDSessionPredict *p1, CMDSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMDSessionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMDSession	要被判断的行情订阅者在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMDSession *pMDSession)
	{
		return m_p1->isValid(pMDSession) && m_p2->isValid(pMDSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionOrPredict是对两个行情订阅者在线会话谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionOrPredict : public CMDSessionPredict
{
private:
	CMDSessionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMDSessionOrPredict(CMDSessionPredict *p1, CMDSessionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMDSessionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMDSession	要被判断的行情订阅者在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMDSession *pMDSession)
	{
		return m_p1->isValid(pMDSession) || m_p2->isValid(pMDSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionNotPredict是对一个行情订阅者在线会话谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionNotPredict : public CMDSessionPredict
{
private:
	CMDSessionPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMDSessionNotPredict(CMDSessionPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMDSessionNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMDSession	要被判断的行情订阅者在线会话
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMDSession *pMDSession)
	{
		return !m_predict->isValid(pMDSession);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionFilter是一个对已有的行情订阅者在线会话枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionFilter: public CMDSessionIterator
{
private:
	CMDSessionIterator *m_baseIterator;
	CMDSessionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMDSessionFilter(CMDSessionIterator *pBaseIterator, CMDSessionPredict *pPredict, bool continueResult=false)
		:CMDSessionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMDSessionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMDSession
	///@return	下一个满足条件CMDSession，如果已经没有一个满足要求了，则返回NULL
	virtual CMDSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMDSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionLinkIterator是连接两个行情订阅者在线会话枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionLinkIterator: public CMDSessionIterator
{
private:
	CMDSessionIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMDSessionLinkIterator(CMDSessionIterator *pBaseIterator1,CMDSessionIterator *pBaseIterator2)
		:CMDSessionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMDSessionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMDSession
	///@return	下一个满足条件CMDSession，如果已经没有一个满足要求了，则返回NULL
	virtual CMDSession *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMDSession 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CLoginInfoSingleIterator是至多返回一个用户登陆登出信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoSingleIterator: public CLoginInfoIterator
{
private:
	CLoginInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CLoginInfoSingleIterator(CLoginInfoFactory *pFactory,CLoginInfo *pResult)
		:CLoginInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CLoginInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CLoginInfo
	///@return	下一个满足条件CLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CLoginInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoPredict是判断一个用户登陆登出信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoPredict
{
public:
	///判断是否合法
	///@param	pLoginInfo	要被判断的用户登陆登出信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CLoginInfo *pLoginInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoAndPredict是对两个用户登陆登出信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoAndPredict : public CLoginInfoPredict
{
private:
	CLoginInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CLoginInfoAndPredict(CLoginInfoPredict *p1, CLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CLoginInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pLoginInfo	要被判断的用户登陆登出信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CLoginInfo *pLoginInfo)
	{
		return m_p1->isValid(pLoginInfo) && m_p2->isValid(pLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoOrPredict是对两个用户登陆登出信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoOrPredict : public CLoginInfoPredict
{
private:
	CLoginInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CLoginInfoOrPredict(CLoginInfoPredict *p1, CLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CLoginInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pLoginInfo	要被判断的用户登陆登出信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CLoginInfo *pLoginInfo)
	{
		return m_p1->isValid(pLoginInfo) || m_p2->isValid(pLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoNotPredict是对一个用户登陆登出信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoNotPredict : public CLoginInfoPredict
{
private:
	CLoginInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CLoginInfoNotPredict(CLoginInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CLoginInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pLoginInfo	要被判断的用户登陆登出信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CLoginInfo *pLoginInfo)
	{
		return !m_predict->isValid(pLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoFilter是一个对已有的用户登陆登出信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoFilter: public CLoginInfoIterator
{
private:
	CLoginInfoIterator *m_baseIterator;
	CLoginInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CLoginInfoFilter(CLoginInfoIterator *pBaseIterator, CLoginInfoPredict *pPredict, bool continueResult=false)
		:CLoginInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CLoginInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CLoginInfo
	///@return	下一个满足条件CLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CLoginInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoLinkIterator是连接两个用户登陆登出信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoLinkIterator: public CLoginInfoIterator
{
private:
	CLoginInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CLoginInfoLinkIterator(CLoginInfoIterator *pBaseIterator1,CLoginInfoIterator *pBaseIterator2)
		:CLoginInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CLoginInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CLoginInfo
	///@return	下一个满足条件CLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CLoginInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailSingleIterator是至多返回一个深度市场行情明细的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailSingleIterator: public CDepthMarketDataDetailIterator
{
private:
	CDepthMarketDataDetail *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CDepthMarketDataDetailSingleIterator(CDepthMarketDataDetailFactory *pFactory,CDepthMarketDataDetail *pResult)
		:CDepthMarketDataDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CDepthMarketDataDetailSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CDepthMarketDataDetail
	///@return	下一个满足条件CDepthMarketDataDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketDataDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketDataDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailPredict是判断一个深度市场行情明细是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailPredict
{
public:
	///判断是否合法
	///@param	pDepthMarketDataDetail	要被判断的深度市场行情明细
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailAndPredict是对两个深度市场行情明细谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailAndPredict : public CDepthMarketDataDetailPredict
{
private:
	CDepthMarketDataDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CDepthMarketDataDetailAndPredict(CDepthMarketDataDetailPredict *p1, CDepthMarketDataDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CDepthMarketDataDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pDepthMarketDataDetail	要被判断的深度市场行情明细
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return m_p1->isValid(pDepthMarketDataDetail) && m_p2->isValid(pDepthMarketDataDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailOrPredict是对两个深度市场行情明细谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailOrPredict : public CDepthMarketDataDetailPredict
{
private:
	CDepthMarketDataDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CDepthMarketDataDetailOrPredict(CDepthMarketDataDetailPredict *p1, CDepthMarketDataDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CDepthMarketDataDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pDepthMarketDataDetail	要被判断的深度市场行情明细
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return m_p1->isValid(pDepthMarketDataDetail) || m_p2->isValid(pDepthMarketDataDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailNotPredict是对一个深度市场行情明细谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailNotPredict : public CDepthMarketDataDetailPredict
{
private:
	CDepthMarketDataDetailPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CDepthMarketDataDetailNotPredict(CDepthMarketDataDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CDepthMarketDataDetailNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pDepthMarketDataDetail	要被判断的深度市场行情明细
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return !m_predict->isValid(pDepthMarketDataDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailFilter是一个对已有的深度市场行情明细枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailFilter: public CDepthMarketDataDetailIterator
{
private:
	CDepthMarketDataDetailIterator *m_baseIterator;
	CDepthMarketDataDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CDepthMarketDataDetailFilter(CDepthMarketDataDetailIterator *pBaseIterator, CDepthMarketDataDetailPredict *pPredict, bool continueResult=false)
		:CDepthMarketDataDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CDepthMarketDataDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CDepthMarketDataDetail
	///@return	下一个满足条件CDepthMarketDataDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketDataDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketDataDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailLinkIterator是连接两个深度市场行情明细枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailLinkIterator: public CDepthMarketDataDetailIterator
{
private:
	CDepthMarketDataDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CDepthMarketDataDetailLinkIterator(CDepthMarketDataDetailIterator *pBaseIterator1,CDepthMarketDataDetailIterator *pBaseIterator2)
		:CDepthMarketDataDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CDepthMarketDataDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CDepthMarketDataDetail
	///@return	下一个满足条件CDepthMarketDataDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketDataDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketDataDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailSingleIterator是至多返回一个合约交易状态流水的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailSingleIterator: public CInstrumentStatusDetailIterator
{
private:
	CInstrumentStatusDetail *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CInstrumentStatusDetailSingleIterator(CInstrumentStatusDetailFactory *pFactory,CInstrumentStatusDetail *pResult)
		:CInstrumentStatusDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CInstrumentStatusDetailSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CInstrumentStatusDetail
	///@return	下一个满足条件CInstrumentStatusDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatusDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatusDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailPredict是判断一个合约交易状态流水是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailPredict
{
public:
	///判断是否合法
	///@param	pInstrumentStatusDetail	要被判断的合约交易状态流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailAndPredict是对两个合约交易状态流水谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailAndPredict : public CInstrumentStatusDetailPredict
{
private:
	CInstrumentStatusDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInstrumentStatusDetailAndPredict(CInstrumentStatusDetailPredict *p1, CInstrumentStatusDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInstrumentStatusDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInstrumentStatusDetail	要被判断的合约交易状态流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return m_p1->isValid(pInstrumentStatusDetail) && m_p2->isValid(pInstrumentStatusDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailOrPredict是对两个合约交易状态流水谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailOrPredict : public CInstrumentStatusDetailPredict
{
private:
	CInstrumentStatusDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInstrumentStatusDetailOrPredict(CInstrumentStatusDetailPredict *p1, CInstrumentStatusDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInstrumentStatusDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInstrumentStatusDetail	要被判断的合约交易状态流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return m_p1->isValid(pInstrumentStatusDetail) || m_p2->isValid(pInstrumentStatusDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailNotPredict是对一个合约交易状态流水谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailNotPredict : public CInstrumentStatusDetailPredict
{
private:
	CInstrumentStatusDetailPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CInstrumentStatusDetailNotPredict(CInstrumentStatusDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CInstrumentStatusDetailNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pInstrumentStatusDetail	要被判断的合约交易状态流水
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return !m_predict->isValid(pInstrumentStatusDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailFilter是一个对已有的合约交易状态流水枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailFilter: public CInstrumentStatusDetailIterator
{
private:
	CInstrumentStatusDetailIterator *m_baseIterator;
	CInstrumentStatusDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CInstrumentStatusDetailFilter(CInstrumentStatusDetailIterator *pBaseIterator, CInstrumentStatusDetailPredict *pPredict, bool continueResult=false)
		:CInstrumentStatusDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CInstrumentStatusDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CInstrumentStatusDetail
	///@return	下一个满足条件CInstrumentStatusDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatusDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatusDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailLinkIterator是连接两个合约交易状态流水枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailLinkIterator: public CInstrumentStatusDetailIterator
{
private:
	CInstrumentStatusDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CInstrumentStatusDetailLinkIterator(CInstrumentStatusDetailIterator *pBaseIterator1,CInstrumentStatusDetailIterator *pBaseIterator2)
		:CInstrumentStatusDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CInstrumentStatusDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CInstrumentStatusDetail
	///@return	下一个满足条件CInstrumentStatusDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatusDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatusDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CFrontStatusSingleIterator是至多返回一个前置状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusSingleIterator: public CFrontStatusIterator
{
private:
	CFrontStatus *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CFrontStatusSingleIterator(CFrontStatusFactory *pFactory,CFrontStatus *pResult)
		:CFrontStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CFrontStatusSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CFrontStatus
	///@return	下一个满足条件CFrontStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CFrontStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pFrontStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusPredict是判断一个前置状态是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusPredict
{
public:
	///判断是否合法
	///@param	pFrontStatus	要被判断的前置状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFrontStatus *pFrontStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusAndPredict是对两个前置状态谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusAndPredict : public CFrontStatusPredict
{
private:
	CFrontStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CFrontStatusAndPredict(CFrontStatusPredict *p1, CFrontStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CFrontStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pFrontStatus	要被判断的前置状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFrontStatus *pFrontStatus)
	{
		return m_p1->isValid(pFrontStatus) && m_p2->isValid(pFrontStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusOrPredict是对两个前置状态谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusOrPredict : public CFrontStatusPredict
{
private:
	CFrontStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CFrontStatusOrPredict(CFrontStatusPredict *p1, CFrontStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CFrontStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pFrontStatus	要被判断的前置状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFrontStatus *pFrontStatus)
	{
		return m_p1->isValid(pFrontStatus) || m_p2->isValid(pFrontStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusNotPredict是对一个前置状态谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusNotPredict : public CFrontStatusPredict
{
private:
	CFrontStatusPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CFrontStatusNotPredict(CFrontStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CFrontStatusNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pFrontStatus	要被判断的前置状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFrontStatus *pFrontStatus)
	{
		return !m_predict->isValid(pFrontStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusFilter是一个对已有的前置状态枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusFilter: public CFrontStatusIterator
{
private:
	CFrontStatusIterator *m_baseIterator;
	CFrontStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CFrontStatusFilter(CFrontStatusIterator *pBaseIterator, CFrontStatusPredict *pPredict, bool continueResult=false)
		:CFrontStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CFrontStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CFrontStatus
	///@return	下一个满足条件CFrontStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CFrontStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pFrontStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusLinkIterator是连接两个前置状态枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusLinkIterator: public CFrontStatusIterator
{
private:
	CFrontStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CFrontStatusLinkIterator(CFrontStatusIterator *pBaseIterator1,CFrontStatusIterator *pBaseIterator2)
		:CFrontStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CFrontStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CFrontStatus
	///@return	下一个满足条件CFrontStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CFrontStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pFrontStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDSingleIterator是至多返回一个最大本地报单号的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDSingleIterator: public CMaxLocalIDIterator
{
private:
	CMaxLocalID *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMaxLocalIDSingleIterator(CMaxLocalIDFactory *pFactory,CMaxLocalID *pResult)
		:CMaxLocalIDIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMaxLocalIDSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMaxLocalID
	///@return	下一个满足条件CMaxLocalID，如果已经没有一个满足要求了，则返回NULL
	virtual CMaxLocalID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMaxLocalID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDPredict是判断一个最大本地报单号是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDPredict
{
public:
	///判断是否合法
	///@param	pMaxLocalID	要被判断的最大本地报单号
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMaxLocalID *pMaxLocalID)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDAndPredict是对两个最大本地报单号谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDAndPredict : public CMaxLocalIDPredict
{
private:
	CMaxLocalIDPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMaxLocalIDAndPredict(CMaxLocalIDPredict *p1, CMaxLocalIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMaxLocalIDAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMaxLocalID	要被判断的最大本地报单号
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMaxLocalID *pMaxLocalID)
	{
		return m_p1->isValid(pMaxLocalID) && m_p2->isValid(pMaxLocalID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDOrPredict是对两个最大本地报单号谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDOrPredict : public CMaxLocalIDPredict
{
private:
	CMaxLocalIDPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMaxLocalIDOrPredict(CMaxLocalIDPredict *p1, CMaxLocalIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMaxLocalIDOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMaxLocalID	要被判断的最大本地报单号
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMaxLocalID *pMaxLocalID)
	{
		return m_p1->isValid(pMaxLocalID) || m_p2->isValid(pMaxLocalID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDNotPredict是对一个最大本地报单号谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDNotPredict : public CMaxLocalIDPredict
{
private:
	CMaxLocalIDPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMaxLocalIDNotPredict(CMaxLocalIDPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMaxLocalIDNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMaxLocalID	要被判断的最大本地报单号
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMaxLocalID *pMaxLocalID)
	{
		return !m_predict->isValid(pMaxLocalID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDFilter是一个对已有的最大本地报单号枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDFilter: public CMaxLocalIDIterator
{
private:
	CMaxLocalIDIterator *m_baseIterator;
	CMaxLocalIDPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMaxLocalIDFilter(CMaxLocalIDIterator *pBaseIterator, CMaxLocalIDPredict *pPredict, bool continueResult=false)
		:CMaxLocalIDIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMaxLocalIDFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMaxLocalID
	///@return	下一个满足条件CMaxLocalID，如果已经没有一个满足要求了，则返回NULL
	virtual CMaxLocalID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMaxLocalID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDLinkIterator是连接两个最大本地报单号枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDLinkIterator: public CMaxLocalIDIterator
{
private:
	CMaxLocalIDIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMaxLocalIDLinkIterator(CMaxLocalIDIterator *pBaseIterator1,CMaxLocalIDIterator *pBaseIterator2)
		:CMaxLocalIDIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMaxLocalIDLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMaxLocalID
	///@return	下一个满足条件CMaxLocalID，如果已经没有一个满足要求了，则返回NULL
	virtual CMaxLocalID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMaxLocalID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CBulletinSingleIterator是至多返回一个公告信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinSingleIterator: public CBulletinIterator
{
private:
	CBulletin *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CBulletinSingleIterator(CBulletinFactory *pFactory,CBulletin *pResult)
		:CBulletinIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CBulletinSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CBulletin
	///@return	下一个满足条件CBulletin，如果已经没有一个满足要求了，则返回NULL
	virtual CBulletin *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBulletin 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBulletinPredict是判断一个公告信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinPredict
{
public:
	///判断是否合法
	///@param	pBulletin	要被判断的公告信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBulletin *pBulletin)=0;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinAndPredict是对两个公告信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinAndPredict : public CBulletinPredict
{
private:
	CBulletinPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CBulletinAndPredict(CBulletinPredict *p1, CBulletinPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CBulletinAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pBulletin	要被判断的公告信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBulletin *pBulletin)
	{
		return m_p1->isValid(pBulletin) && m_p2->isValid(pBulletin);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBulletinOrPredict是对两个公告信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinOrPredict : public CBulletinPredict
{
private:
	CBulletinPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CBulletinOrPredict(CBulletinPredict *p1, CBulletinPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CBulletinOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pBulletin	要被判断的公告信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBulletin *pBulletin)
	{
		return m_p1->isValid(pBulletin) || m_p2->isValid(pBulletin);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBulletinNotPredict是对一个公告信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinNotPredict : public CBulletinPredict
{
private:
	CBulletinPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CBulletinNotPredict(CBulletinPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CBulletinNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pBulletin	要被判断的公告信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBulletin *pBulletin)
	{
		return !m_predict->isValid(pBulletin);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBulletinFilter是一个对已有的公告信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinFilter: public CBulletinIterator
{
private:
	CBulletinIterator *m_baseIterator;
	CBulletinPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CBulletinFilter(CBulletinIterator *pBaseIterator, CBulletinPredict *pPredict, bool continueResult=false)
		:CBulletinIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CBulletinFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CBulletin
	///@return	下一个满足条件CBulletin，如果已经没有一个满足要求了，则返回NULL
	virtual CBulletin *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBulletin 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBulletinLinkIterator是连接两个公告信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinLinkIterator: public CBulletinIterator
{
private:
	CBulletinIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CBulletinLinkIterator(CBulletinIterator *pBaseIterator1,CBulletinIterator *pBaseIterator2)
		:CBulletinIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CBulletinLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CBulletin
	///@return	下一个满足条件CBulletin，如果已经没有一个满足要求了，则返回NULL
	virtual CBulletin *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBulletin 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataModifySingleIterator是至多返回一个行情变动的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifySingleIterator: public CMarketDataModifyIterator
{
private:
	CMarketDataModify *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMarketDataModifySingleIterator(CMarketDataModifyFactory *pFactory,CMarketDataModify *pResult)
		:CMarketDataModifyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMarketDataModifySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMarketDataModify
	///@return	下一个满足条件CMarketDataModify，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataModify *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataModify 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyPredict是判断一个行情变动是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyPredict
{
public:
	///判断是否合法
	///@param	pMarketDataModify	要被判断的行情变动
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataModify *pMarketDataModify)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyAndPredict是对两个行情变动谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyAndPredict : public CMarketDataModifyPredict
{
private:
	CMarketDataModifyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataModifyAndPredict(CMarketDataModifyPredict *p1, CMarketDataModifyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataModifyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketDataModify	要被判断的行情变动
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataModify *pMarketDataModify)
	{
		return m_p1->isValid(pMarketDataModify) && m_p2->isValid(pMarketDataModify);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyOrPredict是对两个行情变动谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyOrPredict : public CMarketDataModifyPredict
{
private:
	CMarketDataModifyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataModifyOrPredict(CMarketDataModifyPredict *p1, CMarketDataModifyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataModifyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketDataModify	要被判断的行情变动
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataModify *pMarketDataModify)
	{
		return m_p1->isValid(pMarketDataModify) || m_p2->isValid(pMarketDataModify);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyNotPredict是对一个行情变动谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyNotPredict : public CMarketDataModifyPredict
{
private:
	CMarketDataModifyPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMarketDataModifyNotPredict(CMarketDataModifyPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMarketDataModifyNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMarketDataModify	要被判断的行情变动
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketDataModify *pMarketDataModify)
	{
		return !m_predict->isValid(pMarketDataModify);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyFilter是一个对已有的行情变动枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyFilter: public CMarketDataModifyIterator
{
private:
	CMarketDataModifyIterator *m_baseIterator;
	CMarketDataModifyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMarketDataModifyFilter(CMarketDataModifyIterator *pBaseIterator, CMarketDataModifyPredict *pPredict, bool continueResult=false)
		:CMarketDataModifyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMarketDataModifyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMarketDataModify
	///@return	下一个满足条件CMarketDataModify，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataModify *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataModify 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyLinkIterator是连接两个行情变动枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyLinkIterator: public CMarketDataModifyIterator
{
private:
	CMarketDataModifyIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMarketDataModifyLinkIterator(CMarketDataModifyIterator *pBaseIterator1,CMarketDataModifyIterator *pBaseIterator2)
		:CMarketDataModifyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMarketDataModifyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMarketDataModify
	///@return	下一个满足条件CMarketDataModify，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketDataModify *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketDataModify 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataOfMarketDataModifyIterator是一个行情变动枚举器对应的深度行情的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataOfMarketDataModifyIterator: public CDepthMarketDataIterator
{
private:
	CMarketDataModifyIterator *m_baseIterator;
	CDepthMarketData *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CDepthMarketDataOfMarketDataModifyIterator(CDepthMarketDataFactory *pFactory,CMarketDataModifyIterator *pBaseIterator)
		:CDepthMarketDataIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CDepthMarketDataOfMarketDataModifyIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CDepthMarketData
	///@return	下一个满足条件CDepthMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketData *pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataSingleIterator是至多返回一个深度行情的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataSingleIterator: public CDepthMarketDataIterator
{
private:
	CDepthMarketData *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CDepthMarketDataSingleIterator(CDepthMarketDataFactory *pFactory,CDepthMarketData *pResult)
		:CDepthMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CDepthMarketDataSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CDepthMarketData
	///@return	下一个满足条件CDepthMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataPredict是判断一个深度行情是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataPredict
{
public:
	///判断是否合法
	///@param	pDepthMarketData	要被判断的深度行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketData *pDepthMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataAndPredict是对两个深度行情谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataAndPredict : public CDepthMarketDataPredict
{
private:
	CDepthMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CDepthMarketDataAndPredict(CDepthMarketDataPredict *p1, CDepthMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CDepthMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pDepthMarketData	要被判断的深度行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketData *pDepthMarketData)
	{
		return m_p1->isValid(pDepthMarketData) && m_p2->isValid(pDepthMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataOrPredict是对两个深度行情谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataOrPredict : public CDepthMarketDataPredict
{
private:
	CDepthMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CDepthMarketDataOrPredict(CDepthMarketDataPredict *p1, CDepthMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CDepthMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pDepthMarketData	要被判断的深度行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketData *pDepthMarketData)
	{
		return m_p1->isValid(pDepthMarketData) || m_p2->isValid(pDepthMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataNotPredict是对一个深度行情谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataNotPredict : public CDepthMarketDataPredict
{
private:
	CDepthMarketDataPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CDepthMarketDataNotPredict(CDepthMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CDepthMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pDepthMarketData	要被判断的深度行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CDepthMarketData *pDepthMarketData)
	{
		return !m_predict->isValid(pDepthMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataFilter是一个对已有的深度行情枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataFilter: public CDepthMarketDataIterator
{
private:
	CDepthMarketDataIterator *m_baseIterator;
	CDepthMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CDepthMarketDataFilter(CDepthMarketDataIterator *pBaseIterator, CDepthMarketDataPredict *pPredict, bool continueResult=false)
		:CDepthMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CDepthMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CDepthMarketData
	///@return	下一个满足条件CDepthMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataLinkIterator是连接两个深度行情枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataLinkIterator: public CDepthMarketDataIterator
{
private:
	CDepthMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CDepthMarketDataLinkIterator(CDepthMarketDataIterator *pBaseIterator1,CDepthMarketDataIterator *pBaseIterator2)
		:CDepthMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CDepthMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CDepthMarketData
	///@return	下一个满足条件CDepthMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CDepthMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pDepthMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfDepthMarketDataIterator是一个深度行情枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfDepthMarketDataIterator: public CInstrumentIterator
{
private:
	CDepthMarketDataIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfDepthMarketDataIterator(CInstrumentFactory *pFactory,CDepthMarketDataIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfDepthMarketDataIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataSingleIterator是至多返回一个分主题行情的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataSingleIterator: public CTopicMarketDataIterator
{
private:
	CTopicMarketData *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CTopicMarketDataSingleIterator(CTopicMarketDataFactory *pFactory,CTopicMarketData *pResult)
		:CTopicMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CTopicMarketDataSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CTopicMarketData
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataPredict是判断一个分主题行情是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataPredict
{
public:
	///判断是否合法
	///@param	pTopicMarketData	要被判断的分主题行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketData *pTopicMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataAndPredict是对两个分主题行情谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataAndPredict : public CTopicMarketDataPredict
{
private:
	CTopicMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTopicMarketDataAndPredict(CTopicMarketDataPredict *p1, CTopicMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTopicMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTopicMarketData	要被判断的分主题行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketData *pTopicMarketData)
	{
		return m_p1->isValid(pTopicMarketData) && m_p2->isValid(pTopicMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataOrPredict是对两个分主题行情谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataOrPredict : public CTopicMarketDataPredict
{
private:
	CTopicMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTopicMarketDataOrPredict(CTopicMarketDataPredict *p1, CTopicMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTopicMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTopicMarketData	要被判断的分主题行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketData *pTopicMarketData)
	{
		return m_p1->isValid(pTopicMarketData) || m_p2->isValid(pTopicMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataNotPredict是对一个分主题行情谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataNotPredict : public CTopicMarketDataPredict
{
private:
	CTopicMarketDataPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CTopicMarketDataNotPredict(CTopicMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CTopicMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pTopicMarketData	要被判断的分主题行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketData *pTopicMarketData)
	{
		return !m_predict->isValid(pTopicMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataFilter是一个对已有的分主题行情枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataFilter: public CTopicMarketDataIterator
{
private:
	CTopicMarketDataIterator *m_baseIterator;
	CTopicMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CTopicMarketDataFilter(CTopicMarketDataIterator *pBaseIterator, CTopicMarketDataPredict *pPredict, bool continueResult=false)
		:CTopicMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CTopicMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CTopicMarketData
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataLinkIterator是连接两个分主题行情枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataLinkIterator: public CTopicMarketDataIterator
{
private:
	CTopicMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CTopicMarketDataLinkIterator(CTopicMarketDataIterator *pBaseIterator1,CTopicMarketDataIterator *pBaseIterator2)
		:CTopicMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CTopicMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CTopicMarketData
	///@return	下一个满足条件CTopicMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionSingleIterator是至多返回一个分主题行情快照的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionSingleIterator: public CTopicMarketDataVersionIterator
{
private:
	CTopicMarketDataVersion *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CTopicMarketDataVersionSingleIterator(CTopicMarketDataVersionFactory *pFactory,CTopicMarketDataVersion *pResult)
		:CTopicMarketDataVersionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CTopicMarketDataVersionSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CTopicMarketDataVersion
	///@return	下一个满足条件CTopicMarketDataVersion，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketDataVersion 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionPredict是判断一个分主题行情快照是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionPredict
{
public:
	///判断是否合法
	///@param	pTopicMarketDataVersion	要被判断的分主题行情快照
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionAndPredict是对两个分主题行情快照谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionAndPredict : public CTopicMarketDataVersionPredict
{
private:
	CTopicMarketDataVersionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTopicMarketDataVersionAndPredict(CTopicMarketDataVersionPredict *p1, CTopicMarketDataVersionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTopicMarketDataVersionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTopicMarketDataVersion	要被判断的分主题行情快照
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return m_p1->isValid(pTopicMarketDataVersion) && m_p2->isValid(pTopicMarketDataVersion);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionOrPredict是对两个分主题行情快照谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionOrPredict : public CTopicMarketDataVersionPredict
{
private:
	CTopicMarketDataVersionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTopicMarketDataVersionOrPredict(CTopicMarketDataVersionPredict *p1, CTopicMarketDataVersionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTopicMarketDataVersionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTopicMarketDataVersion	要被判断的分主题行情快照
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return m_p1->isValid(pTopicMarketDataVersion) || m_p2->isValid(pTopicMarketDataVersion);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionNotPredict是对一个分主题行情快照谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionNotPredict : public CTopicMarketDataVersionPredict
{
private:
	CTopicMarketDataVersionPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CTopicMarketDataVersionNotPredict(CTopicMarketDataVersionPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CTopicMarketDataVersionNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pTopicMarketDataVersion	要被判断的分主题行情快照
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return !m_predict->isValid(pTopicMarketDataVersion);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionFilter是一个对已有的分主题行情快照枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionFilter: public CTopicMarketDataVersionIterator
{
private:
	CTopicMarketDataVersionIterator *m_baseIterator;
	CTopicMarketDataVersionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CTopicMarketDataVersionFilter(CTopicMarketDataVersionIterator *pBaseIterator, CTopicMarketDataVersionPredict *pPredict, bool continueResult=false)
		:CTopicMarketDataVersionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CTopicMarketDataVersionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CTopicMarketDataVersion
	///@return	下一个满足条件CTopicMarketDataVersion，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketDataVersion 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionLinkIterator是连接两个分主题行情快照枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionLinkIterator: public CTopicMarketDataVersionIterator
{
private:
	CTopicMarketDataVersionIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CTopicMarketDataVersionLinkIterator(CTopicMarketDataVersionIterator *pBaseIterator1,CTopicMarketDataVersionIterator *pBaseIterator2)
		:CTopicMarketDataVersionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CTopicMarketDataVersionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CTopicMarketDataVersion
	///@return	下一个满足条件CTopicMarketDataVersion，如果已经没有一个满足要求了，则返回NULL
	virtual CTopicMarketDataVersion *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTopicMarketDataVersion 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInformationSingleIterator是至多返回一个信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationSingleIterator: public CInformationIterator
{
private:
	CInformation *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CInformationSingleIterator(CInformationFactory *pFactory,CInformation *pResult)
		:CInformationIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CInformationSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CInformation
	///@return	下一个满足条件CInformation，如果已经没有一个满足要求了，则返回NULL
	virtual CInformation *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInformation 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInformationPredict是判断一个信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationPredict
{
public:
	///判断是否合法
	///@param	pInformation	要被判断的信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInformation *pInformation)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInformationAndPredict是对两个信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationAndPredict : public CInformationPredict
{
private:
	CInformationPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInformationAndPredict(CInformationPredict *p1, CInformationPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInformationAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInformation	要被判断的信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInformation *pInformation)
	{
		return m_p1->isValid(pInformation) && m_p2->isValid(pInformation);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInformationOrPredict是对两个信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationOrPredict : public CInformationPredict
{
private:
	CInformationPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInformationOrPredict(CInformationPredict *p1, CInformationPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInformationOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInformation	要被判断的信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInformation *pInformation)
	{
		return m_p1->isValid(pInformation) || m_p2->isValid(pInformation);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInformationNotPredict是对一个信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationNotPredict : public CInformationPredict
{
private:
	CInformationPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CInformationNotPredict(CInformationPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CInformationNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pInformation	要被判断的信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInformation *pInformation)
	{
		return !m_predict->isValid(pInformation);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInformationFilter是一个对已有的信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationFilter: public CInformationIterator
{
private:
	CInformationIterator *m_baseIterator;
	CInformationPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CInformationFilter(CInformationIterator *pBaseIterator, CInformationPredict *pPredict, bool continueResult=false)
		:CInformationIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CInformationFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CInformation
	///@return	下一个满足条件CInformation，如果已经没有一个满足要求了，则返回NULL
	virtual CInformation *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInformation 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInformationLinkIterator是连接两个信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationLinkIterator: public CInformationIterator
{
private:
	CInformationIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CInformationLinkIterator(CInformationIterator *pBaseIterator1,CInformationIterator *pBaseIterator2)
		:CInformationIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CInformationLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CInformation
	///@return	下一个满足条件CInformation，如果已经没有一个满足要求了，则返回NULL
	virtual CInformation *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInformation 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///COrderCountSingleIterator是至多返回一个报单数量的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountSingleIterator: public COrderCountIterator
{
private:
	COrderCount *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	COrderCountSingleIterator(COrderCountFactory *pFactory,COrderCount *pResult)
		:COrderCountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~COrderCountSingleIterator(void)
	{
	}

	///寻找下一个符合条件的COrderCount
	///@return	下一个满足条件COrderCount，如果已经没有一个满足要求了，则返回NULL
	virtual COrderCount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOrderCount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderCountPredict是判断一个报单数量是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountPredict
{
public:
	///判断是否合法
	///@param	pOrderCount	要被判断的报单数量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrderCount *pOrderCount)=0;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountAndPredict是对两个报单数量谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountAndPredict : public COrderCountPredict
{
private:
	COrderCountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	COrderCountAndPredict(COrderCountPredict *p1, COrderCountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~COrderCountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pOrderCount	要被判断的报单数量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrderCount *pOrderCount)
	{
		return m_p1->isValid(pOrderCount) && m_p2->isValid(pOrderCount);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderCountOrPredict是对两个报单数量谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountOrPredict : public COrderCountPredict
{
private:
	COrderCountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	COrderCountOrPredict(COrderCountPredict *p1, COrderCountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~COrderCountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pOrderCount	要被判断的报单数量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrderCount *pOrderCount)
	{
		return m_p1->isValid(pOrderCount) || m_p2->isValid(pOrderCount);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderCountNotPredict是对一个报单数量谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountNotPredict : public COrderCountPredict
{
private:
	COrderCountPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	COrderCountNotPredict(COrderCountPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~COrderCountNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pOrderCount	要被判断的报单数量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrderCount *pOrderCount)
	{
		return !m_predict->isValid(pOrderCount);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderCountFilter是一个对已有的报单数量枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountFilter: public COrderCountIterator
{
private:
	COrderCountIterator *m_baseIterator;
	COrderCountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	COrderCountFilter(COrderCountIterator *pBaseIterator, COrderCountPredict *pPredict, bool continueResult=false)
		:COrderCountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~COrderCountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的COrderCount
	///@return	下一个满足条件COrderCount，如果已经没有一个满足要求了，则返回NULL
	virtual COrderCount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOrderCount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderCountLinkIterator是连接两个报单数量枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountLinkIterator: public COrderCountIterator
{
private:
	COrderCountIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	COrderCountLinkIterator(COrderCountIterator *pBaseIterator1,COrderCountIterator *pBaseIterator2)
		:COrderCountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~COrderCountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的COrderCount
	///@return	下一个满足条件COrderCount，如果已经没有一个满足要求了，则返回NULL
	virtual COrderCount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOrderCount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentSingleIterator是至多返回一个合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentSingleIterator: public CInstrumentIterator
{
private:
	CInstrument *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CInstrumentSingleIterator(CInstrumentFactory *pFactory,CInstrument *pResult)
		:CInstrumentIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CInstrumentSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentPredict是判断一个合约是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentPredict
{
public:
	///判断是否合法
	///@param	pInstrument	要被判断的合约
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrument *pInstrument)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentAndPredict是对两个合约谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentAndPredict : public CInstrumentPredict
{
private:
	CInstrumentPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInstrumentAndPredict(CInstrumentPredict *p1, CInstrumentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInstrumentAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInstrument	要被判断的合约
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrument *pInstrument)
	{
		return m_p1->isValid(pInstrument) && m_p2->isValid(pInstrument);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOrPredict是对两个合约谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOrPredict : public CInstrumentPredict
{
private:
	CInstrumentPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInstrumentOrPredict(CInstrumentPredict *p1, CInstrumentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInstrumentOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInstrument	要被判断的合约
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrument *pInstrument)
	{
		return m_p1->isValid(pInstrument) || m_p2->isValid(pInstrument);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentNotPredict是对一个合约谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentNotPredict : public CInstrumentPredict
{
private:
	CInstrumentPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CInstrumentNotPredict(CInstrumentPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CInstrumentNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pInstrument	要被判断的合约
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrument *pInstrument)
	{
		return !m_predict->isValid(pInstrument);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentFilter是一个对已有的合约枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentFilter: public CInstrumentIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CInstrumentPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CInstrumentFilter(CInstrumentIterator *pBaseIterator, CInstrumentPredict *pPredict, bool continueResult=false)
		:CInstrumentIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CInstrumentFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentLinkIterator是连接两个合约枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentLinkIterator: public CInstrumentIterator
{
private:
	CInstrumentIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CInstrumentLinkIterator(CInstrumentIterator *pBaseIterator1,CInstrumentIterator *pBaseIterator2)
		:CInstrumentIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CInstrumentLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseInstrumentOfInstrumentIterator是一个合约枚举器对应的基础合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseInstrumentOfInstrumentIterator: public CInstrumentIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CBaseInstrumentOfInstrumentIterator(CInstrumentFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CBaseInstrumentOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentPropertyOfInstrumentIterator是一个合约枚举器对应的合约属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentPropertyOfInstrumentIterator: public CCurrInstrumentPropertyIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CCurrInstrumentProperty *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentPropertyOfInstrumentIterator(CCurrInstrumentPropertyFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CCurrInstrumentPropertyIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentPropertyOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CCurrInstrumentProperty
	///@return	下一个满足条件CCurrInstrumentProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusOfInstrumentIterator是一个合约枚举器对应的合约状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusOfInstrumentIterator: public CInstrumentStatusIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CInstrumentStatus *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentStatusOfInstrumentIterator(CInstrumentStatusFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CInstrumentStatusIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentStatusOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrumentStatus
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatus *pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataOfInstrumentIterator是一个合约枚举器对应的行情的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataOfInstrumentIterator: public CMarketDataIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CMarketData *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CMarketDataOfInstrumentIterator(CMarketDataFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CMarketDataIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CMarketDataOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CMarketData
	///@return	下一个满足条件CMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketData *pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleOfInstrumentIterator是一个合约枚举器对应的套期保值规则的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleOfInstrumentIterator: public CCurrHedgeRuleIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CCurrHedgeRule *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CCurrHedgeRuleOfInstrumentIterator(CCurrHedgeRuleFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CCurrHedgeRuleIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CCurrHedgeRuleOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CCurrHedgeRule
	///@return	下一个满足条件CCurrHedgeRule，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrHedgeRule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrHedgeRule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrHedgeRule *pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseOfInstrumentIterator是一个合约枚举器对应的熔断规则的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseOfInstrumentIterator: public CCurrFuseIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CCurrFuse *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CCurrFuseOfInstrumentIterator(CCurrFuseFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CCurrFuseIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CCurrFuseOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CCurrFuse
	///@return	下一个满足条件CCurrFuse，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrFuse *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrFuse 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrFuse *pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseOfInstrumentIterator是一个合约枚举器对应的熔断状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseOfInstrumentIterator: public CFusePhaseIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CFusePhase *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CFusePhaseOfInstrumentIterator(CFusePhaseFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CFusePhaseIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CFusePhaseOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CFusePhase
	///@return	下一个满足条件CFusePhase，如果已经没有一个满足要求了，则返回NULL
	virtual CFusePhase *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pFusePhase 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFusePhase *pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitOfInstrumentIterator是一个合约枚举器对应的涨跌停板设置的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitOfInstrumentIterator: public CBasePriceLimitIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CBasePriceLimit *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CBasePriceLimitOfInstrumentIterator(CBasePriceLimitFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CBasePriceLimitIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CBasePriceLimitOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CBasePriceLimit
	///@return	下一个满足条件CBasePriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CBasePriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBasePriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBasePriceLimit *pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureOfInstrumentIterator是一个合约枚举器对应的单边市情况的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureOfInstrumentIterator: public CUniPressureIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CUniPressure *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CUniPressureOfInstrumentIterator(CUniPressureFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CUniPressureIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CUniPressureOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CUniPressure
	///@return	下一个满足条件CUniPressure，如果已经没有一个满足要求了，则返回NULL
	virtual CUniPressure *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUniPressure 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUniPressure *pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusOfInstrumentIterator是一个合约枚举器对应的结算组同步状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusOfInstrumentIterator: public CSGDataSyncStatusIterator
{
private:
	CInstrumentIterator *m_baseIterator;
	CSGDataSyncStatus *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CSGDataSyncStatusOfInstrumentIterator(CSGDataSyncStatusFactory *pFactory,CInstrumentIterator *pBaseIterator)
		:CSGDataSyncStatusIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CSGDataSyncStatusOfInstrumentIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CSGDataSyncStatus
	///@return	下一个满足条件CSGDataSyncStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSGDataSyncStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSGDataSyncStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus *pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCombinationLegSingleIterator是至多返回一个组合合约单腿的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegSingleIterator: public CCombinationLegIterator
{
private:
	CCombinationLeg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCombinationLegSingleIterator(CCombinationLegFactory *pFactory,CCombinationLeg *pResult)
		:CCombinationLegIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCombinationLegSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCombinationLeg
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	virtual CCombinationLeg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCombinationLeg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegPredict是判断一个组合合约单腿是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegPredict
{
public:
	///判断是否合法
	///@param	pCombinationLeg	要被判断的组合合约单腿
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombinationLeg *pCombinationLeg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegAndPredict是对两个组合合约单腿谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegAndPredict : public CCombinationLegPredict
{
private:
	CCombinationLegPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCombinationLegAndPredict(CCombinationLegPredict *p1, CCombinationLegPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCombinationLegAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCombinationLeg	要被判断的组合合约单腿
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombinationLeg *pCombinationLeg)
	{
		return m_p1->isValid(pCombinationLeg) && m_p2->isValid(pCombinationLeg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegOrPredict是对两个组合合约单腿谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegOrPredict : public CCombinationLegPredict
{
private:
	CCombinationLegPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCombinationLegOrPredict(CCombinationLegPredict *p1, CCombinationLegPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCombinationLegOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCombinationLeg	要被判断的组合合约单腿
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombinationLeg *pCombinationLeg)
	{
		return m_p1->isValid(pCombinationLeg) || m_p2->isValid(pCombinationLeg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegNotPredict是对一个组合合约单腿谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegNotPredict : public CCombinationLegPredict
{
private:
	CCombinationLegPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCombinationLegNotPredict(CCombinationLegPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCombinationLegNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCombinationLeg	要被判断的组合合约单腿
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombinationLeg *pCombinationLeg)
	{
		return !m_predict->isValid(pCombinationLeg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegFilter是一个对已有的组合合约单腿枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegFilter: public CCombinationLegIterator
{
private:
	CCombinationLegIterator *m_baseIterator;
	CCombinationLegPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCombinationLegFilter(CCombinationLegIterator *pBaseIterator, CCombinationLegPredict *pPredict, bool continueResult=false)
		:CCombinationLegIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCombinationLegFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCombinationLeg
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	virtual CCombinationLeg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCombinationLeg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegLinkIterator是连接两个组合合约单腿枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegLinkIterator: public CCombinationLegIterator
{
private:
	CCombinationLegIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCombinationLegLinkIterator(CCombinationLegIterator *pBaseIterator1,CCombinationLegIterator *pBaseIterator2)
		:CCombinationLegIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCombinationLegLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCombinationLeg
	///@return	下一个满足条件CCombinationLeg，如果已经没有一个满足要求了，则返回NULL
	virtual CCombinationLeg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCombinationLeg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombinationInstrumentOfCombinationLegIterator是一个组合合约单腿枚举器对应的组合合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationInstrumentOfCombinationLegIterator: public CInstrumentIterator
{
private:
	CCombinationLegIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CCombinationInstrumentOfCombinationLegIterator(CInstrumentFactory *pFactory,CCombinationLegIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CCombinationInstrumentOfCombinationLegIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CLegInstrumentOfCombinationLegIterator是一个组合合约单腿枚举器对应的单腿合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLegInstrumentOfCombinationLegIterator: public CInstrumentIterator
{
private:
	CCombinationLegIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CLegInstrumentOfCombinationLegIterator(CInstrumentFactory *pFactory,CCombinationLegIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CLegInstrumentOfCombinationLegIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountSingleIterator是至多返回一个会员账户关系的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountSingleIterator: public CPartRoleAccountIterator
{
private:
	CPartRoleAccount *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartRoleAccountSingleIterator(CPartRoleAccountFactory *pFactory,CPartRoleAccount *pResult)
		:CPartRoleAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartRoleAccountSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartRoleAccount
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CPartRoleAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartRoleAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountPredict是判断一个会员账户关系是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountPredict
{
public:
	///判断是否合法
	///@param	pPartRoleAccount	要被判断的会员账户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountAndPredict是对两个会员账户关系谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountAndPredict : public CPartRoleAccountPredict
{
private:
	CPartRoleAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartRoleAccountAndPredict(CPartRoleAccountPredict *p1, CPartRoleAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartRoleAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartRoleAccount	要被判断的会员账户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)
	{
		return m_p1->isValid(pPartRoleAccount) && m_p2->isValid(pPartRoleAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountOrPredict是对两个会员账户关系谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountOrPredict : public CPartRoleAccountPredict
{
private:
	CPartRoleAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartRoleAccountOrPredict(CPartRoleAccountPredict *p1, CPartRoleAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartRoleAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartRoleAccount	要被判断的会员账户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)
	{
		return m_p1->isValid(pPartRoleAccount) || m_p2->isValid(pPartRoleAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountNotPredict是对一个会员账户关系谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountNotPredict : public CPartRoleAccountPredict
{
private:
	CPartRoleAccountPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartRoleAccountNotPredict(CPartRoleAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartRoleAccountNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartRoleAccount	要被判断的会员账户关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartRoleAccount *pPartRoleAccount)
	{
		return !m_predict->isValid(pPartRoleAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountFilter是一个对已有的会员账户关系枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountFilter: public CPartRoleAccountIterator
{
private:
	CPartRoleAccountIterator *m_baseIterator;
	CPartRoleAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartRoleAccountFilter(CPartRoleAccountIterator *pBaseIterator, CPartRoleAccountPredict *pPredict, bool continueResult=false)
		:CPartRoleAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartRoleAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartRoleAccount
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CPartRoleAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartRoleAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountLinkIterator是连接两个会员账户关系枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountLinkIterator: public CPartRoleAccountIterator
{
private:
	CPartRoleAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartRoleAccountLinkIterator(CPartRoleAccountIterator *pBaseIterator1,CPartRoleAccountIterator *pBaseIterator2)
		:CPartRoleAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartRoleAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartRoleAccount
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CPartRoleAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartRoleAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountOfPartRoleAccountIterator是一个会员账户关系枚举器对应的帐户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountOfPartRoleAccountIterator: public CTradingAccountIterator
{
private:
	CPartRoleAccountIterator *m_baseIterator;
	CTradingAccount *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CTradingAccountOfPartRoleAccountIterator(CTradingAccountFactory *pFactory,CPartRoleAccountIterator *pBaseIterator)
		:CTradingAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CTradingAccountOfPartRoleAccountIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CTradingAccount
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CTradingAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTradingAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTradingAccount *pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartProductRoleSingleIterator是至多返回一个会员产品角色的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleSingleIterator: public CPartProductRoleIterator
{
private:
	CPartProductRole *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartProductRoleSingleIterator(CPartProductRoleFactory *pFactory,CPartProductRole *pResult)
		:CPartProductRoleIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartProductRoleSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartProductRole
	///@return	下一个满足条件CPartProductRole，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRole *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRole 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRolePredict是判断一个会员产品角色是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRolePredict
{
public:
	///判断是否合法
	///@param	pPartProductRole	要被判断的会员产品角色
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRole *pPartProductRole)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleAndPredict是对两个会员产品角色谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleAndPredict : public CPartProductRolePredict
{
private:
	CPartProductRolePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartProductRoleAndPredict(CPartProductRolePredict *p1, CPartProductRolePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartProductRoleAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartProductRole	要被判断的会员产品角色
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRole *pPartProductRole)
	{
		return m_p1->isValid(pPartProductRole) && m_p2->isValid(pPartProductRole);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleOrPredict是对两个会员产品角色谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleOrPredict : public CPartProductRolePredict
{
private:
	CPartProductRolePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartProductRoleOrPredict(CPartProductRolePredict *p1, CPartProductRolePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartProductRoleOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartProductRole	要被判断的会员产品角色
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRole *pPartProductRole)
	{
		return m_p1->isValid(pPartProductRole) || m_p2->isValid(pPartProductRole);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleNotPredict是对一个会员产品角色谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleNotPredict : public CPartProductRolePredict
{
private:
	CPartProductRolePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartProductRoleNotPredict(CPartProductRolePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartProductRoleNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartProductRole	要被判断的会员产品角色
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRole *pPartProductRole)
	{
		return !m_predict->isValid(pPartProductRole);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleFilter是一个对已有的会员产品角色枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleFilter: public CPartProductRoleIterator
{
private:
	CPartProductRoleIterator *m_baseIterator;
	CPartProductRolePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartProductRoleFilter(CPartProductRoleIterator *pBaseIterator, CPartProductRolePredict *pPredict, bool continueResult=false)
		:CPartProductRoleIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartProductRoleFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartProductRole
	///@return	下一个满足条件CPartProductRole，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRole *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRole 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleLinkIterator是连接两个会员产品角色枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleLinkIterator: public CPartProductRoleIterator
{
private:
	CPartProductRoleIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartProductRoleLinkIterator(CPartProductRoleIterator *pBaseIterator1,CPartProductRoleIterator *pBaseIterator2)
		:CPartProductRoleIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartProductRoleLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartProductRole
	///@return	下一个满足条件CPartProductRole，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRole *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRole 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartProductRightSingleIterator是至多返回一个会员产品交易权限的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightSingleIterator: public CPartProductRightIterator
{
private:
	CPartProductRight *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartProductRightSingleIterator(CPartProductRightFactory *pFactory,CPartProductRight *pResult)
		:CPartProductRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartProductRightSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartProductRight
	///@return	下一个满足条件CPartProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightPredict是判断一个会员产品交易权限是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightPredict
{
public:
	///判断是否合法
	///@param	pPartProductRight	要被判断的会员产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRight *pPartProductRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightAndPredict是对两个会员产品交易权限谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightAndPredict : public CPartProductRightPredict
{
private:
	CPartProductRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartProductRightAndPredict(CPartProductRightPredict *p1, CPartProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartProductRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartProductRight	要被判断的会员产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRight *pPartProductRight)
	{
		return m_p1->isValid(pPartProductRight) && m_p2->isValid(pPartProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightOrPredict是对两个会员产品交易权限谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightOrPredict : public CPartProductRightPredict
{
private:
	CPartProductRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartProductRightOrPredict(CPartProductRightPredict *p1, CPartProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartProductRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartProductRight	要被判断的会员产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRight *pPartProductRight)
	{
		return m_p1->isValid(pPartProductRight) || m_p2->isValid(pPartProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightNotPredict是对一个会员产品交易权限谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightNotPredict : public CPartProductRightPredict
{
private:
	CPartProductRightPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartProductRightNotPredict(CPartProductRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartProductRightNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartProductRight	要被判断的会员产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartProductRight *pPartProductRight)
	{
		return !m_predict->isValid(pPartProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightFilter是一个对已有的会员产品交易权限枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightFilter: public CPartProductRightIterator
{
private:
	CPartProductRightIterator *m_baseIterator;
	CPartProductRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartProductRightFilter(CPartProductRightIterator *pBaseIterator, CPartProductRightPredict *pPredict, bool continueResult=false)
		:CPartProductRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartProductRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartProductRight
	///@return	下一个满足条件CPartProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightLinkIterator是连接两个会员产品交易权限枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightLinkIterator: public CPartProductRightIterator
{
private:
	CPartProductRightIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartProductRightLinkIterator(CPartProductRightIterator *pBaseIterator1,CPartProductRightIterator *pBaseIterator2)
		:CPartProductRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartProductRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartProductRight
	///@return	下一个满足条件CPartProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightSingleIterator是至多返回一个会员合约交易权限的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightSingleIterator: public CPartInstrumentRightIterator
{
private:
	CPartInstrumentRight *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartInstrumentRightSingleIterator(CPartInstrumentRightFactory *pFactory,CPartInstrumentRight *pResult)
		:CPartInstrumentRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartInstrumentRightSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartInstrumentRight
	///@return	下一个满足条件CPartInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightPredict是判断一个会员合约交易权限是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightPredict
{
public:
	///判断是否合法
	///@param	pPartInstrumentRight	要被判断的会员合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightAndPredict是对两个会员合约交易权限谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightAndPredict : public CPartInstrumentRightPredict
{
private:
	CPartInstrumentRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartInstrumentRightAndPredict(CPartInstrumentRightPredict *p1, CPartInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartInstrumentRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartInstrumentRight	要被判断的会员合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)
	{
		return m_p1->isValid(pPartInstrumentRight) && m_p2->isValid(pPartInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightOrPredict是对两个会员合约交易权限谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightOrPredict : public CPartInstrumentRightPredict
{
private:
	CPartInstrumentRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartInstrumentRightOrPredict(CPartInstrumentRightPredict *p1, CPartInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartInstrumentRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartInstrumentRight	要被判断的会员合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)
	{
		return m_p1->isValid(pPartInstrumentRight) || m_p2->isValid(pPartInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightNotPredict是对一个会员合约交易权限谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightNotPredict : public CPartInstrumentRightPredict
{
private:
	CPartInstrumentRightPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartInstrumentRightNotPredict(CPartInstrumentRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartInstrumentRightNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartInstrumentRight	要被判断的会员合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartInstrumentRight *pPartInstrumentRight)
	{
		return !m_predict->isValid(pPartInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightFilter是一个对已有的会员合约交易权限枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightFilter: public CPartInstrumentRightIterator
{
private:
	CPartInstrumentRightIterator *m_baseIterator;
	CPartInstrumentRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartInstrumentRightFilter(CPartInstrumentRightIterator *pBaseIterator, CPartInstrumentRightPredict *pPredict, bool continueResult=false)
		:CPartInstrumentRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartInstrumentRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartInstrumentRight
	///@return	下一个满足条件CPartInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightLinkIterator是连接两个会员合约交易权限枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightLinkIterator: public CPartInstrumentRightIterator
{
private:
	CPartInstrumentRightIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartInstrumentRightLinkIterator(CPartInstrumentRightIterator *pBaseIterator1,CPartInstrumentRightIterator *pBaseIterator2)
		:CPartInstrumentRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartInstrumentRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartInstrumentRight
	///@return	下一个满足条件CPartInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientProductRightSingleIterator是至多返回一个客户产品交易权限的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightSingleIterator: public CClientProductRightIterator
{
private:
	CClientProductRight *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CClientProductRightSingleIterator(CClientProductRightFactory *pFactory,CClientProductRight *pResult)
		:CClientProductRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CClientProductRightSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CClientProductRight
	///@return	下一个满足条件CClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightPredict是判断一个客户产品交易权限是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightPredict
{
public:
	///判断是否合法
	///@param	pClientProductRight	要被判断的客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientProductRight *pClientProductRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightAndPredict是对两个客户产品交易权限谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightAndPredict : public CClientProductRightPredict
{
private:
	CClientProductRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientProductRightAndPredict(CClientProductRightPredict *p1, CClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientProductRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClientProductRight	要被判断的客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientProductRight *pClientProductRight)
	{
		return m_p1->isValid(pClientProductRight) && m_p2->isValid(pClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightOrPredict是对两个客户产品交易权限谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightOrPredict : public CClientProductRightPredict
{
private:
	CClientProductRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientProductRightOrPredict(CClientProductRightPredict *p1, CClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientProductRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClientProductRight	要被判断的客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientProductRight *pClientProductRight)
	{
		return m_p1->isValid(pClientProductRight) || m_p2->isValid(pClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightNotPredict是对一个客户产品交易权限谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightNotPredict : public CClientProductRightPredict
{
private:
	CClientProductRightPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CClientProductRightNotPredict(CClientProductRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CClientProductRightNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pClientProductRight	要被判断的客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientProductRight *pClientProductRight)
	{
		return !m_predict->isValid(pClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightFilter是一个对已有的客户产品交易权限枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightFilter: public CClientProductRightIterator
{
private:
	CClientProductRightIterator *m_baseIterator;
	CClientProductRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CClientProductRightFilter(CClientProductRightIterator *pBaseIterator, CClientProductRightPredict *pPredict, bool continueResult=false)
		:CClientProductRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CClientProductRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CClientProductRight
	///@return	下一个满足条件CClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightLinkIterator是连接两个客户产品交易权限枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightLinkIterator: public CClientProductRightIterator
{
private:
	CClientProductRightIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CClientProductRightLinkIterator(CClientProductRightIterator *pBaseIterator1,CClientProductRightIterator *pBaseIterator2)
		:CClientProductRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CClientProductRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CClientProductRight
	///@return	下一个满足条件CClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightSingleIterator是至多返回一个客户合约交易权限的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightSingleIterator: public CClientInstrumentRightIterator
{
private:
	CClientInstrumentRight *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CClientInstrumentRightSingleIterator(CClientInstrumentRightFactory *pFactory,CClientInstrumentRight *pResult)
		:CClientInstrumentRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CClientInstrumentRightSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CClientInstrumentRight
	///@return	下一个满足条件CClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightPredict是判断一个客户合约交易权限是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightPredict
{
public:
	///判断是否合法
	///@param	pClientInstrumentRight	要被判断的客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightAndPredict是对两个客户合约交易权限谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightAndPredict : public CClientInstrumentRightPredict
{
private:
	CClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientInstrumentRightAndPredict(CClientInstrumentRightPredict *p1, CClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientInstrumentRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClientInstrumentRight	要被判断的客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)
	{
		return m_p1->isValid(pClientInstrumentRight) && m_p2->isValid(pClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightOrPredict是对两个客户合约交易权限谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightOrPredict : public CClientInstrumentRightPredict
{
private:
	CClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientInstrumentRightOrPredict(CClientInstrumentRightPredict *p1, CClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientInstrumentRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClientInstrumentRight	要被判断的客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)
	{
		return m_p1->isValid(pClientInstrumentRight) || m_p2->isValid(pClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightNotPredict是对一个客户合约交易权限谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightNotPredict : public CClientInstrumentRightPredict
{
private:
	CClientInstrumentRightPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CClientInstrumentRightNotPredict(CClientInstrumentRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CClientInstrumentRightNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pClientInstrumentRight	要被判断的客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientInstrumentRight *pClientInstrumentRight)
	{
		return !m_predict->isValid(pClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightFilter是一个对已有的客户合约交易权限枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightFilter: public CClientInstrumentRightIterator
{
private:
	CClientInstrumentRightIterator *m_baseIterator;
	CClientInstrumentRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CClientInstrumentRightFilter(CClientInstrumentRightIterator *pBaseIterator, CClientInstrumentRightPredict *pPredict, bool continueResult=false)
		:CClientInstrumentRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CClientInstrumentRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CClientInstrumentRight
	///@return	下一个满足条件CClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightLinkIterator是连接两个客户合约交易权限枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightLinkIterator: public CClientInstrumentRightIterator
{
private:
	CClientInstrumentRightIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CClientInstrumentRightLinkIterator(CClientInstrumentRightIterator *pBaseIterator1,CClientInstrumentRightIterator *pBaseIterator2)
		:CClientInstrumentRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CClientInstrumentRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CClientInstrumentRight
	///@return	下一个满足条件CClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightSingleIterator是至多返回一个会员客户产品交易权限的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightSingleIterator: public CPartClientProductRightIterator
{
private:
	CPartClientProductRight *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartClientProductRightSingleIterator(CPartClientProductRightFactory *pFactory,CPartClientProductRight *pResult)
		:CPartClientProductRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartClientProductRightSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartClientProductRight
	///@return	下一个满足条件CPartClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightPredict是判断一个会员客户产品交易权限是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightPredict
{
public:
	///判断是否合法
	///@param	pPartClientProductRight	要被判断的会员客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightAndPredict是对两个会员客户产品交易权限谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightAndPredict : public CPartClientProductRightPredict
{
private:
	CPartClientProductRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartClientProductRightAndPredict(CPartClientProductRightPredict *p1, CPartClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartClientProductRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartClientProductRight	要被判断的会员客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)
	{
		return m_p1->isValid(pPartClientProductRight) && m_p2->isValid(pPartClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightOrPredict是对两个会员客户产品交易权限谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightOrPredict : public CPartClientProductRightPredict
{
private:
	CPartClientProductRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartClientProductRightOrPredict(CPartClientProductRightPredict *p1, CPartClientProductRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartClientProductRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartClientProductRight	要被判断的会员客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)
	{
		return m_p1->isValid(pPartClientProductRight) || m_p2->isValid(pPartClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightNotPredict是对一个会员客户产品交易权限谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightNotPredict : public CPartClientProductRightPredict
{
private:
	CPartClientProductRightPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartClientProductRightNotPredict(CPartClientProductRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartClientProductRightNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartClientProductRight	要被判断的会员客户产品交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientProductRight *pPartClientProductRight)
	{
		return !m_predict->isValid(pPartClientProductRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightFilter是一个对已有的会员客户产品交易权限枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightFilter: public CPartClientProductRightIterator
{
private:
	CPartClientProductRightIterator *m_baseIterator;
	CPartClientProductRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartClientProductRightFilter(CPartClientProductRightIterator *pBaseIterator, CPartClientProductRightPredict *pPredict, bool continueResult=false)
		:CPartClientProductRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartClientProductRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartClientProductRight
	///@return	下一个满足条件CPartClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightLinkIterator是连接两个会员客户产品交易权限枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightLinkIterator: public CPartClientProductRightIterator
{
private:
	CPartClientProductRightIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartClientProductRightLinkIterator(CPartClientProductRightIterator *pBaseIterator1,CPartClientProductRightIterator *pBaseIterator2)
		:CPartClientProductRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartClientProductRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartClientProductRight
	///@return	下一个满足条件CPartClientProductRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientProductRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientProductRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightSingleIterator是至多返回一个会员客户合约交易权限的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightSingleIterator: public CPartClientInstrumentRightIterator
{
private:
	CPartClientInstrumentRight *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartClientInstrumentRightSingleIterator(CPartClientInstrumentRightFactory *pFactory,CPartClientInstrumentRight *pResult)
		:CPartClientInstrumentRightIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartClientInstrumentRightSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartClientInstrumentRight
	///@return	下一个满足条件CPartClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightPredict是判断一个会员客户合约交易权限是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightPredict
{
public:
	///判断是否合法
	///@param	pPartClientInstrumentRight	要被判断的会员客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightAndPredict是对两个会员客户合约交易权限谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightAndPredict : public CPartClientInstrumentRightPredict
{
private:
	CPartClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartClientInstrumentRightAndPredict(CPartClientInstrumentRightPredict *p1, CPartClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartClientInstrumentRightAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartClientInstrumentRight	要被判断的会员客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return m_p1->isValid(pPartClientInstrumentRight) && m_p2->isValid(pPartClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightOrPredict是对两个会员客户合约交易权限谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightOrPredict : public CPartClientInstrumentRightPredict
{
private:
	CPartClientInstrumentRightPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartClientInstrumentRightOrPredict(CPartClientInstrumentRightPredict *p1, CPartClientInstrumentRightPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartClientInstrumentRightOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartClientInstrumentRight	要被判断的会员客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return m_p1->isValid(pPartClientInstrumentRight) || m_p2->isValid(pPartClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightNotPredict是对一个会员客户合约交易权限谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightNotPredict : public CPartClientInstrumentRightPredict
{
private:
	CPartClientInstrumentRightPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartClientInstrumentRightNotPredict(CPartClientInstrumentRightPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartClientInstrumentRightNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartClientInstrumentRight	要被判断的会员客户合约交易权限
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return !m_predict->isValid(pPartClientInstrumentRight);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightFilter是一个对已有的会员客户合约交易权限枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightFilter: public CPartClientInstrumentRightIterator
{
private:
	CPartClientInstrumentRightIterator *m_baseIterator;
	CPartClientInstrumentRightPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartClientInstrumentRightFilter(CPartClientInstrumentRightIterator *pBaseIterator, CPartClientInstrumentRightPredict *pPredict, bool continueResult=false)
		:CPartClientInstrumentRightIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartClientInstrumentRightFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartClientInstrumentRight
	///@return	下一个满足条件CPartClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightLinkIterator是连接两个会员客户合约交易权限枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightLinkIterator: public CPartClientInstrumentRightIterator
{
private:
	CPartClientInstrumentRightIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartClientInstrumentRightLinkIterator(CPartClientInstrumentRightIterator *pBaseIterator1,CPartClientInstrumentRightIterator *pBaseIterator2)
		:CPartClientInstrumentRightIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartClientInstrumentRightLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartClientInstrumentRight
	///@return	下一个满足条件CPartClientInstrumentRight，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClientInstrumentRight *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClientInstrumentRight 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertySingleIterator是至多返回一个产品属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertySingleIterator: public CCurrProductPropertyIterator
{
private:
	CCurrProductProperty *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrProductPropertySingleIterator(CCurrProductPropertyFactory *pFactory,CCurrProductProperty *pResult)
		:CCurrProductPropertyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrProductPropertySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrProductProperty
	///@return	下一个满足条件CCurrProductProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrProductProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrProductProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyPredict是判断一个产品属性是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyPredict
{
public:
	///判断是否合法
	///@param	pCurrProductProperty	要被判断的产品属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyAndPredict是对两个产品属性谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyAndPredict : public CCurrProductPropertyPredict
{
private:
	CCurrProductPropertyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrProductPropertyAndPredict(CCurrProductPropertyPredict *p1, CCurrProductPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrProductPropertyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrProductProperty	要被判断的产品属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)
	{
		return m_p1->isValid(pCurrProductProperty) && m_p2->isValid(pCurrProductProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyOrPredict是对两个产品属性谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyOrPredict : public CCurrProductPropertyPredict
{
private:
	CCurrProductPropertyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrProductPropertyOrPredict(CCurrProductPropertyPredict *p1, CCurrProductPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrProductPropertyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrProductProperty	要被判断的产品属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)
	{
		return m_p1->isValid(pCurrProductProperty) || m_p2->isValid(pCurrProductProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyNotPredict是对一个产品属性谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyNotPredict : public CCurrProductPropertyPredict
{
private:
	CCurrProductPropertyPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrProductPropertyNotPredict(CCurrProductPropertyPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrProductPropertyNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrProductProperty	要被判断的产品属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrProductProperty *pCurrProductProperty)
	{
		return !m_predict->isValid(pCurrProductProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyFilter是一个对已有的产品属性枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyFilter: public CCurrProductPropertyIterator
{
private:
	CCurrProductPropertyIterator *m_baseIterator;
	CCurrProductPropertyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrProductPropertyFilter(CCurrProductPropertyIterator *pBaseIterator, CCurrProductPropertyPredict *pPredict, bool continueResult=false)
		:CCurrProductPropertyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrProductPropertyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrProductProperty
	///@return	下一个满足条件CCurrProductProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrProductProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrProductProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyLinkIterator是连接两个产品属性枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyLinkIterator: public CCurrProductPropertyIterator
{
private:
	CCurrProductPropertyIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrProductPropertyLinkIterator(CCurrProductPropertyIterator *pBaseIterator1,CCurrProductPropertyIterator *pBaseIterator2)
		:CCurrProductPropertyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrProductPropertyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrProductProperty
	///@return	下一个满足条件CCurrProductProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrProductProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrProductProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertySingleIterator是至多返回一个合约属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertySingleIterator: public CCurrInstrumentPropertyIterator
{
private:
	CCurrInstrumentProperty *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrInstrumentPropertySingleIterator(CCurrInstrumentPropertyFactory *pFactory,CCurrInstrumentProperty *pResult)
		:CCurrInstrumentPropertyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrInstrumentPropertySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrInstrumentProperty
	///@return	下一个满足条件CCurrInstrumentProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyPredict是判断一个合约属性是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyPredict
{
public:
	///判断是否合法
	///@param	pCurrInstrumentProperty	要被判断的合约属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyAndPredict是对两个合约属性谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyAndPredict : public CCurrInstrumentPropertyPredict
{
private:
	CCurrInstrumentPropertyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrInstrumentPropertyAndPredict(CCurrInstrumentPropertyPredict *p1, CCurrInstrumentPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrInstrumentPropertyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrInstrumentProperty	要被判断的合约属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return m_p1->isValid(pCurrInstrumentProperty) && m_p2->isValid(pCurrInstrumentProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyOrPredict是对两个合约属性谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyOrPredict : public CCurrInstrumentPropertyPredict
{
private:
	CCurrInstrumentPropertyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrInstrumentPropertyOrPredict(CCurrInstrumentPropertyPredict *p1, CCurrInstrumentPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrInstrumentPropertyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrInstrumentProperty	要被判断的合约属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return m_p1->isValid(pCurrInstrumentProperty) || m_p2->isValid(pCurrInstrumentProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyNotPredict是对一个合约属性谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyNotPredict : public CCurrInstrumentPropertyPredict
{
private:
	CCurrInstrumentPropertyPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrInstrumentPropertyNotPredict(CCurrInstrumentPropertyPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrInstrumentPropertyNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrInstrumentProperty	要被判断的合约属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return !m_predict->isValid(pCurrInstrumentProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyFilter是一个对已有的合约属性枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyFilter: public CCurrInstrumentPropertyIterator
{
private:
	CCurrInstrumentPropertyIterator *m_baseIterator;
	CCurrInstrumentPropertyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrInstrumentPropertyFilter(CCurrInstrumentPropertyIterator *pBaseIterator, CCurrInstrumentPropertyPredict *pPredict, bool continueResult=false)
		:CCurrInstrumentPropertyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrInstrumentPropertyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrInstrumentProperty
	///@return	下一个满足条件CCurrInstrumentProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyLinkIterator是连接两个合约属性枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyLinkIterator: public CCurrInstrumentPropertyIterator
{
private:
	CCurrInstrumentPropertyIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrInstrumentPropertyLinkIterator(CCurrInstrumentPropertyIterator *pBaseIterator1,CCurrInstrumentPropertyIterator *pBaseIterator2)
		:CCurrInstrumentPropertyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrInstrumentPropertyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrInstrumentProperty
	///@return	下一个满足条件CCurrInstrumentProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingSingleIterator是至多返回一个当前价格绑定的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingSingleIterator: public CCurrPriceBandingIterator
{
private:
	CCurrPriceBanding *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrPriceBandingSingleIterator(CCurrPriceBandingFactory *pFactory,CCurrPriceBanding *pResult)
		:CCurrPriceBandingIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrPriceBandingSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrPriceBanding
	///@return	下一个满足条件CCurrPriceBanding，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPriceBanding *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPriceBanding 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingPredict是判断一个当前价格绑定是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingPredict
{
public:
	///判断是否合法
	///@param	pCurrPriceBanding	要被判断的当前价格绑定
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingAndPredict是对两个当前价格绑定谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingAndPredict : public CCurrPriceBandingPredict
{
private:
	CCurrPriceBandingPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrPriceBandingAndPredict(CCurrPriceBandingPredict *p1, CCurrPriceBandingPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrPriceBandingAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrPriceBanding	要被判断的当前价格绑定
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)
	{
		return m_p1->isValid(pCurrPriceBanding) && m_p2->isValid(pCurrPriceBanding);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingOrPredict是对两个当前价格绑定谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingOrPredict : public CCurrPriceBandingPredict
{
private:
	CCurrPriceBandingPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrPriceBandingOrPredict(CCurrPriceBandingPredict *p1, CCurrPriceBandingPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrPriceBandingOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrPriceBanding	要被判断的当前价格绑定
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)
	{
		return m_p1->isValid(pCurrPriceBanding) || m_p2->isValid(pCurrPriceBanding);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingNotPredict是对一个当前价格绑定谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingNotPredict : public CCurrPriceBandingPredict
{
private:
	CCurrPriceBandingPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrPriceBandingNotPredict(CCurrPriceBandingPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrPriceBandingNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrPriceBanding	要被判断的当前价格绑定
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPriceBanding *pCurrPriceBanding)
	{
		return !m_predict->isValid(pCurrPriceBanding);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingFilter是一个对已有的当前价格绑定枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingFilter: public CCurrPriceBandingIterator
{
private:
	CCurrPriceBandingIterator *m_baseIterator;
	CCurrPriceBandingPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrPriceBandingFilter(CCurrPriceBandingIterator *pBaseIterator, CCurrPriceBandingPredict *pPredict, bool continueResult=false)
		:CCurrPriceBandingIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrPriceBandingFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrPriceBanding
	///@return	下一个满足条件CCurrPriceBanding，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPriceBanding *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPriceBanding 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingLinkIterator是连接两个当前价格绑定枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingLinkIterator: public CCurrPriceBandingIterator
{
private:
	CCurrPriceBandingIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrPriceBandingLinkIterator(CCurrPriceBandingIterator *pBaseIterator1,CCurrPriceBandingIterator *pBaseIterator2)
		:CCurrPriceBandingIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrPriceBandingLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrPriceBanding
	///@return	下一个满足条件CCurrPriceBanding，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPriceBanding *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPriceBanding 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateSingleIterator是至多返回一个当天合约保证金率的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateSingleIterator: public CCurrMarginRateIterator
{
private:
	CCurrMarginRate *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrMarginRateSingleIterator(CCurrMarginRateFactory *pFactory,CCurrMarginRate *pResult)
		:CCurrMarginRateIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrMarginRateSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrMarginRate
	///@return	下一个满足条件CCurrMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRatePredict是判断一个当天合约保证金率是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRatePredict
{
public:
	///判断是否合法
	///@param	pCurrMarginRate	要被判断的当天合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateAndPredict是对两个当天合约保证金率谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateAndPredict : public CCurrMarginRatePredict
{
private:
	CCurrMarginRatePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrMarginRateAndPredict(CCurrMarginRatePredict *p1, CCurrMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrMarginRateAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrMarginRate	要被判断的当天合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)
	{
		return m_p1->isValid(pCurrMarginRate) && m_p2->isValid(pCurrMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateOrPredict是对两个当天合约保证金率谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateOrPredict : public CCurrMarginRatePredict
{
private:
	CCurrMarginRatePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrMarginRateOrPredict(CCurrMarginRatePredict *p1, CCurrMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrMarginRateOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrMarginRate	要被判断的当天合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)
	{
		return m_p1->isValid(pCurrMarginRate) || m_p2->isValid(pCurrMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateNotPredict是对一个当天合约保证金率谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateNotPredict : public CCurrMarginRatePredict
{
private:
	CCurrMarginRatePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrMarginRateNotPredict(CCurrMarginRatePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrMarginRateNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrMarginRate	要被判断的当天合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRate *pCurrMarginRate)
	{
		return !m_predict->isValid(pCurrMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateFilter是一个对已有的当天合约保证金率枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateFilter: public CCurrMarginRateIterator
{
private:
	CCurrMarginRateIterator *m_baseIterator;
	CCurrMarginRatePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrMarginRateFilter(CCurrMarginRateIterator *pBaseIterator, CCurrMarginRatePredict *pPredict, bool continueResult=false)
		:CCurrMarginRateIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrMarginRateFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrMarginRate
	///@return	下一个满足条件CCurrMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateLinkIterator是连接两个当天合约保证金率枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateLinkIterator: public CCurrMarginRateIterator
{
private:
	CCurrMarginRateIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrMarginRateLinkIterator(CCurrMarginRateIterator *pBaseIterator1,CCurrMarginRateIterator *pBaseIterator2)
		:CCurrMarginRateIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrMarginRateLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrMarginRate
	///@return	下一个满足条件CCurrMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailSingleIterator是至多返回一个当天合约保证金率的详细内容的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailSingleIterator: public CCurrMarginRateDetailIterator
{
private:
	CCurrMarginRateDetail *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrMarginRateDetailSingleIterator(CCurrMarginRateDetailFactory *pFactory,CCurrMarginRateDetail *pResult)
		:CCurrMarginRateDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrMarginRateDetailSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrMarginRateDetail
	///@return	下一个满足条件CCurrMarginRateDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRateDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailPredict是判断一个当天合约保证金率的详细内容是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailPredict
{
public:
	///判断是否合法
	///@param	pCurrMarginRateDetail	要被判断的当天合约保证金率的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailAndPredict是对两个当天合约保证金率的详细内容谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailAndPredict : public CCurrMarginRateDetailPredict
{
private:
	CCurrMarginRateDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrMarginRateDetailAndPredict(CCurrMarginRateDetailPredict *p1, CCurrMarginRateDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrMarginRateDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrMarginRateDetail	要被判断的当天合约保证金率的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return m_p1->isValid(pCurrMarginRateDetail) && m_p2->isValid(pCurrMarginRateDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailOrPredict是对两个当天合约保证金率的详细内容谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailOrPredict : public CCurrMarginRateDetailPredict
{
private:
	CCurrMarginRateDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrMarginRateDetailOrPredict(CCurrMarginRateDetailPredict *p1, CCurrMarginRateDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrMarginRateDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrMarginRateDetail	要被判断的当天合约保证金率的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return m_p1->isValid(pCurrMarginRateDetail) || m_p2->isValid(pCurrMarginRateDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailNotPredict是对一个当天合约保证金率的详细内容谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailNotPredict : public CCurrMarginRateDetailPredict
{
private:
	CCurrMarginRateDetailPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrMarginRateDetailNotPredict(CCurrMarginRateDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrMarginRateDetailNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrMarginRateDetail	要被判断的当天合约保证金率的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return !m_predict->isValid(pCurrMarginRateDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailFilter是一个对已有的当天合约保证金率的详细内容枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailFilter: public CCurrMarginRateDetailIterator
{
private:
	CCurrMarginRateDetailIterator *m_baseIterator;
	CCurrMarginRateDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrMarginRateDetailFilter(CCurrMarginRateDetailIterator *pBaseIterator, CCurrMarginRateDetailPredict *pPredict, bool continueResult=false)
		:CCurrMarginRateDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrMarginRateDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrMarginRateDetail
	///@return	下一个满足条件CCurrMarginRateDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRateDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailLinkIterator是连接两个当天合约保证金率的详细内容枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailLinkIterator: public CCurrMarginRateDetailIterator
{
private:
	CCurrMarginRateDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrMarginRateDetailLinkIterator(CCurrMarginRateDetailIterator *pBaseIterator1,CCurrMarginRateDetailIterator *pBaseIterator2)
		:CCurrMarginRateDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrMarginRateDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrMarginRateDetail
	///@return	下一个满足条件CCurrMarginRateDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrMarginRateDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrMarginRateDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitSingleIterator是至多返回一个当前会员合约限仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitSingleIterator: public CCurrPartPosiLimitIterator
{
private:
	CCurrPartPosiLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrPartPosiLimitSingleIterator(CCurrPartPosiLimitFactory *pFactory,CCurrPartPosiLimit *pResult)
		:CCurrPartPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrPartPosiLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrPartPosiLimit
	///@return	下一个满足条件CCurrPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitPredict是判断一个当前会员合约限仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitPredict
{
public:
	///判断是否合法
	///@param	pCurrPartPosiLimit	要被判断的当前会员合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitAndPredict是对两个当前会员合约限仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitAndPredict : public CCurrPartPosiLimitPredict
{
private:
	CCurrPartPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrPartPosiLimitAndPredict(CCurrPartPosiLimitPredict *p1, CCurrPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrPartPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrPartPosiLimit	要被判断的当前会员合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return m_p1->isValid(pCurrPartPosiLimit) && m_p2->isValid(pCurrPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitOrPredict是对两个当前会员合约限仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitOrPredict : public CCurrPartPosiLimitPredict
{
private:
	CCurrPartPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrPartPosiLimitOrPredict(CCurrPartPosiLimitPredict *p1, CCurrPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrPartPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrPartPosiLimit	要被判断的当前会员合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return m_p1->isValid(pCurrPartPosiLimit) || m_p2->isValid(pCurrPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitNotPredict是对一个当前会员合约限仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitNotPredict : public CCurrPartPosiLimitPredict
{
private:
	CCurrPartPosiLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrPartPosiLimitNotPredict(CCurrPartPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrPartPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrPartPosiLimit	要被判断的当前会员合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return !m_predict->isValid(pCurrPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitFilter是一个对已有的当前会员合约限仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitFilter: public CCurrPartPosiLimitIterator
{
private:
	CCurrPartPosiLimitIterator *m_baseIterator;
	CCurrPartPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrPartPosiLimitFilter(CCurrPartPosiLimitIterator *pBaseIterator, CCurrPartPosiLimitPredict *pPredict, bool continueResult=false)
		:CCurrPartPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrPartPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrPartPosiLimit
	///@return	下一个满足条件CCurrPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitLinkIterator是连接两个当前会员合约限仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitLinkIterator: public CCurrPartPosiLimitIterator
{
private:
	CCurrPartPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrPartPosiLimitLinkIterator(CCurrPartPosiLimitIterator *pBaseIterator1,CCurrPartPosiLimitIterator *pBaseIterator2)
		:CCurrPartPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrPartPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrPartPosiLimit
	///@return	下一个满足条件CCurrPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailSingleIterator是至多返回一个当前会员合约限仓的详细内容的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailSingleIterator: public CCurrPartPosiLimitDetailIterator
{
private:
	CCurrPartPosiLimitDetail *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrPartPosiLimitDetailSingleIterator(CCurrPartPosiLimitDetailFactory *pFactory,CCurrPartPosiLimitDetail *pResult)
		:CCurrPartPosiLimitDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrPartPosiLimitDetailSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrPartPosiLimitDetail
	///@return	下一个满足条件CCurrPartPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailPredict是判断一个当前会员合约限仓的详细内容是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailPredict
{
public:
	///判断是否合法
	///@param	pCurrPartPosiLimitDetail	要被判断的当前会员合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailAndPredict是对两个当前会员合约限仓的详细内容谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailAndPredict : public CCurrPartPosiLimitDetailPredict
{
private:
	CCurrPartPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrPartPosiLimitDetailAndPredict(CCurrPartPosiLimitDetailPredict *p1, CCurrPartPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrPartPosiLimitDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrPartPosiLimitDetail	要被判断的当前会员合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return m_p1->isValid(pCurrPartPosiLimitDetail) && m_p2->isValid(pCurrPartPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailOrPredict是对两个当前会员合约限仓的详细内容谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailOrPredict : public CCurrPartPosiLimitDetailPredict
{
private:
	CCurrPartPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrPartPosiLimitDetailOrPredict(CCurrPartPosiLimitDetailPredict *p1, CCurrPartPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrPartPosiLimitDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrPartPosiLimitDetail	要被判断的当前会员合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return m_p1->isValid(pCurrPartPosiLimitDetail) || m_p2->isValid(pCurrPartPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailNotPredict是对一个当前会员合约限仓的详细内容谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailNotPredict : public CCurrPartPosiLimitDetailPredict
{
private:
	CCurrPartPosiLimitDetailPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrPartPosiLimitDetailNotPredict(CCurrPartPosiLimitDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrPartPosiLimitDetailNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrPartPosiLimitDetail	要被判断的当前会员合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return !m_predict->isValid(pCurrPartPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailFilter是一个对已有的当前会员合约限仓的详细内容枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailFilter: public CCurrPartPosiLimitDetailIterator
{
private:
	CCurrPartPosiLimitDetailIterator *m_baseIterator;
	CCurrPartPosiLimitDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrPartPosiLimitDetailFilter(CCurrPartPosiLimitDetailIterator *pBaseIterator, CCurrPartPosiLimitDetailPredict *pPredict, bool continueResult=false)
		:CCurrPartPosiLimitDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrPartPosiLimitDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrPartPosiLimitDetail
	///@return	下一个满足条件CCurrPartPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailLinkIterator是连接两个当前会员合约限仓的详细内容枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailLinkIterator: public CCurrPartPosiLimitDetailIterator
{
private:
	CCurrPartPosiLimitDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrPartPosiLimitDetailLinkIterator(CCurrPartPosiLimitDetailIterator *pBaseIterator1,CCurrPartPosiLimitDetailIterator *pBaseIterator2)
		:CCurrPartPosiLimitDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrPartPosiLimitDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrPartPosiLimitDetail
	///@return	下一个满足条件CCurrPartPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPartPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPartPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitSingleIterator是至多返回一个当前客户合约限仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitSingleIterator: public CCurrClientPosiLimitIterator
{
private:
	CCurrClientPosiLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrClientPosiLimitSingleIterator(CCurrClientPosiLimitFactory *pFactory,CCurrClientPosiLimit *pResult)
		:CCurrClientPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrClientPosiLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrClientPosiLimit
	///@return	下一个满足条件CCurrClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitPredict是判断一个当前客户合约限仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitPredict
{
public:
	///判断是否合法
	///@param	pCurrClientPosiLimit	要被判断的当前客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitAndPredict是对两个当前客户合约限仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitAndPredict : public CCurrClientPosiLimitPredict
{
private:
	CCurrClientPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrClientPosiLimitAndPredict(CCurrClientPosiLimitPredict *p1, CCurrClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrClientPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrClientPosiLimit	要被判断的当前客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return m_p1->isValid(pCurrClientPosiLimit) && m_p2->isValid(pCurrClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitOrPredict是对两个当前客户合约限仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitOrPredict : public CCurrClientPosiLimitPredict
{
private:
	CCurrClientPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrClientPosiLimitOrPredict(CCurrClientPosiLimitPredict *p1, CCurrClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrClientPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrClientPosiLimit	要被判断的当前客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return m_p1->isValid(pCurrClientPosiLimit) || m_p2->isValid(pCurrClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitNotPredict是对一个当前客户合约限仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitNotPredict : public CCurrClientPosiLimitPredict
{
private:
	CCurrClientPosiLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrClientPosiLimitNotPredict(CCurrClientPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrClientPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrClientPosiLimit	要被判断的当前客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return !m_predict->isValid(pCurrClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitFilter是一个对已有的当前客户合约限仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitFilter: public CCurrClientPosiLimitIterator
{
private:
	CCurrClientPosiLimitIterator *m_baseIterator;
	CCurrClientPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrClientPosiLimitFilter(CCurrClientPosiLimitIterator *pBaseIterator, CCurrClientPosiLimitPredict *pPredict, bool continueResult=false)
		:CCurrClientPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrClientPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrClientPosiLimit
	///@return	下一个满足条件CCurrClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitLinkIterator是连接两个当前客户合约限仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitLinkIterator: public CCurrClientPosiLimitIterator
{
private:
	CCurrClientPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrClientPosiLimitLinkIterator(CCurrClientPosiLimitIterator *pBaseIterator1,CCurrClientPosiLimitIterator *pBaseIterator2)
		:CCurrClientPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrClientPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrClientPosiLimit
	///@return	下一个满足条件CCurrClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailSingleIterator是至多返回一个当前客户合约限仓的详细内容的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailSingleIterator: public CCurrClientPosiLimitDetailIterator
{
private:
	CCurrClientPosiLimitDetail *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrClientPosiLimitDetailSingleIterator(CCurrClientPosiLimitDetailFactory *pFactory,CCurrClientPosiLimitDetail *pResult)
		:CCurrClientPosiLimitDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrClientPosiLimitDetailSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrClientPosiLimitDetail
	///@return	下一个满足条件CCurrClientPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailPredict是判断一个当前客户合约限仓的详细内容是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailPredict
{
public:
	///判断是否合法
	///@param	pCurrClientPosiLimitDetail	要被判断的当前客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailAndPredict是对两个当前客户合约限仓的详细内容谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailAndPredict : public CCurrClientPosiLimitDetailPredict
{
private:
	CCurrClientPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrClientPosiLimitDetailAndPredict(CCurrClientPosiLimitDetailPredict *p1, CCurrClientPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrClientPosiLimitDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrClientPosiLimitDetail	要被判断的当前客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return m_p1->isValid(pCurrClientPosiLimitDetail) && m_p2->isValid(pCurrClientPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailOrPredict是对两个当前客户合约限仓的详细内容谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailOrPredict : public CCurrClientPosiLimitDetailPredict
{
private:
	CCurrClientPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrClientPosiLimitDetailOrPredict(CCurrClientPosiLimitDetailPredict *p1, CCurrClientPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrClientPosiLimitDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrClientPosiLimitDetail	要被判断的当前客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return m_p1->isValid(pCurrClientPosiLimitDetail) || m_p2->isValid(pCurrClientPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailNotPredict是对一个当前客户合约限仓的详细内容谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailNotPredict : public CCurrClientPosiLimitDetailPredict
{
private:
	CCurrClientPosiLimitDetailPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrClientPosiLimitDetailNotPredict(CCurrClientPosiLimitDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrClientPosiLimitDetailNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrClientPosiLimitDetail	要被判断的当前客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return !m_predict->isValid(pCurrClientPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailFilter是一个对已有的当前客户合约限仓的详细内容枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailFilter: public CCurrClientPosiLimitDetailIterator
{
private:
	CCurrClientPosiLimitDetailIterator *m_baseIterator;
	CCurrClientPosiLimitDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrClientPosiLimitDetailFilter(CCurrClientPosiLimitDetailIterator *pBaseIterator, CCurrClientPosiLimitDetailPredict *pPredict, bool continueResult=false)
		:CCurrClientPosiLimitDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrClientPosiLimitDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrClientPosiLimitDetail
	///@return	下一个满足条件CCurrClientPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailLinkIterator是连接两个当前客户合约限仓的详细内容枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailLinkIterator: public CCurrClientPosiLimitDetailIterator
{
private:
	CCurrClientPosiLimitDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrClientPosiLimitDetailLinkIterator(CCurrClientPosiLimitDetailIterator *pBaseIterator1,CCurrClientPosiLimitDetailIterator *pBaseIterator2)
		:CCurrClientPosiLimitDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrClientPosiLimitDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrClientPosiLimitDetail
	///@return	下一个满足条件CCurrClientPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrClientPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrClientPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitSingleIterator是至多返回一个当前特殊客户合约限仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitSingleIterator: public CCurrSpecialPosiLimitIterator
{
private:
	CCurrSpecialPosiLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrSpecialPosiLimitSingleIterator(CCurrSpecialPosiLimitFactory *pFactory,CCurrSpecialPosiLimit *pResult)
		:CCurrSpecialPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrSpecialPosiLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrSpecialPosiLimit
	///@return	下一个满足条件CCurrSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitPredict是判断一个当前特殊客户合约限仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitPredict
{
public:
	///判断是否合法
	///@param	pCurrSpecialPosiLimit	要被判断的当前特殊客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitAndPredict是对两个当前特殊客户合约限仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitAndPredict : public CCurrSpecialPosiLimitPredict
{
private:
	CCurrSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrSpecialPosiLimitAndPredict(CCurrSpecialPosiLimitPredict *p1, CCurrSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrSpecialPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrSpecialPosiLimit	要被判断的当前特殊客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return m_p1->isValid(pCurrSpecialPosiLimit) && m_p2->isValid(pCurrSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitOrPredict是对两个当前特殊客户合约限仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitOrPredict : public CCurrSpecialPosiLimitPredict
{
private:
	CCurrSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrSpecialPosiLimitOrPredict(CCurrSpecialPosiLimitPredict *p1, CCurrSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrSpecialPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrSpecialPosiLimit	要被判断的当前特殊客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return m_p1->isValid(pCurrSpecialPosiLimit) || m_p2->isValid(pCurrSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitNotPredict是对一个当前特殊客户合约限仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitNotPredict : public CCurrSpecialPosiLimitPredict
{
private:
	CCurrSpecialPosiLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrSpecialPosiLimitNotPredict(CCurrSpecialPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrSpecialPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrSpecialPosiLimit	要被判断的当前特殊客户合约限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return !m_predict->isValid(pCurrSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitFilter是一个对已有的当前特殊客户合约限仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitFilter: public CCurrSpecialPosiLimitIterator
{
private:
	CCurrSpecialPosiLimitIterator *m_baseIterator;
	CCurrSpecialPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrSpecialPosiLimitFilter(CCurrSpecialPosiLimitIterator *pBaseIterator, CCurrSpecialPosiLimitPredict *pPredict, bool continueResult=false)
		:CCurrSpecialPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrSpecialPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrSpecialPosiLimit
	///@return	下一个满足条件CCurrSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitLinkIterator是连接两个当前特殊客户合约限仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitLinkIterator: public CCurrSpecialPosiLimitIterator
{
private:
	CCurrSpecialPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrSpecialPosiLimitLinkIterator(CCurrSpecialPosiLimitIterator *pBaseIterator1,CCurrSpecialPosiLimitIterator *pBaseIterator2)
		:CCurrSpecialPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrSpecialPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrSpecialPosiLimit
	///@return	下一个满足条件CCurrSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailSingleIterator是至多返回一个当前特殊客户合约限仓的详细内容的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailSingleIterator: public CCurrSpecialPosiLimitDetailIterator
{
private:
	CCurrSpecialPosiLimitDetail *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrSpecialPosiLimitDetailSingleIterator(CCurrSpecialPosiLimitDetailFactory *pFactory,CCurrSpecialPosiLimitDetail *pResult)
		:CCurrSpecialPosiLimitDetailIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrSpecialPosiLimitDetailSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrSpecialPosiLimitDetail
	///@return	下一个满足条件CCurrSpecialPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailPredict是判断一个当前特殊客户合约限仓的详细内容是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailPredict
{
public:
	///判断是否合法
	///@param	pCurrSpecialPosiLimitDetail	要被判断的当前特殊客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailAndPredict是对两个当前特殊客户合约限仓的详细内容谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailAndPredict : public CCurrSpecialPosiLimitDetailPredict
{
private:
	CCurrSpecialPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrSpecialPosiLimitDetailAndPredict(CCurrSpecialPosiLimitDetailPredict *p1, CCurrSpecialPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrSpecialPosiLimitDetailAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrSpecialPosiLimitDetail	要被判断的当前特殊客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return m_p1->isValid(pCurrSpecialPosiLimitDetail) && m_p2->isValid(pCurrSpecialPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailOrPredict是对两个当前特殊客户合约限仓的详细内容谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailOrPredict : public CCurrSpecialPosiLimitDetailPredict
{
private:
	CCurrSpecialPosiLimitDetailPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrSpecialPosiLimitDetailOrPredict(CCurrSpecialPosiLimitDetailPredict *p1, CCurrSpecialPosiLimitDetailPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrSpecialPosiLimitDetailOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrSpecialPosiLimitDetail	要被判断的当前特殊客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return m_p1->isValid(pCurrSpecialPosiLimitDetail) || m_p2->isValid(pCurrSpecialPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailNotPredict是对一个当前特殊客户合约限仓的详细内容谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailNotPredict : public CCurrSpecialPosiLimitDetailPredict
{
private:
	CCurrSpecialPosiLimitDetailPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrSpecialPosiLimitDetailNotPredict(CCurrSpecialPosiLimitDetailPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrSpecialPosiLimitDetailNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrSpecialPosiLimitDetail	要被判断的当前特殊客户合约限仓的详细内容
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return !m_predict->isValid(pCurrSpecialPosiLimitDetail);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailFilter是一个对已有的当前特殊客户合约限仓的详细内容枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailFilter: public CCurrSpecialPosiLimitDetailIterator
{
private:
	CCurrSpecialPosiLimitDetailIterator *m_baseIterator;
	CCurrSpecialPosiLimitDetailPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrSpecialPosiLimitDetailFilter(CCurrSpecialPosiLimitDetailIterator *pBaseIterator, CCurrSpecialPosiLimitDetailPredict *pPredict, bool continueResult=false)
		:CCurrSpecialPosiLimitDetailIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrSpecialPosiLimitDetailFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrSpecialPosiLimitDetail
	///@return	下一个满足条件CCurrSpecialPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailLinkIterator是连接两个当前特殊客户合约限仓的详细内容枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailLinkIterator: public CCurrSpecialPosiLimitDetailIterator
{
private:
	CCurrSpecialPosiLimitDetailIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrSpecialPosiLimitDetailLinkIterator(CCurrSpecialPosiLimitDetailIterator *pBaseIterator1,CCurrSpecialPosiLimitDetailIterator *pBaseIterator2)
		:CCurrSpecialPosiLimitDetailIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrSpecialPosiLimitDetailLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrSpecialPosiLimitDetail
	///@return	下一个满足条件CCurrSpecialPosiLimitDetail，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrSpecialPosiLimitDetail *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrSpecialPosiLimitDetail 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleSingleIterator是至多返回一个当前合约套期保值属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleSingleIterator: public CCurrHedgeRuleIterator
{
private:
	CCurrHedgeRule *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrHedgeRuleSingleIterator(CCurrHedgeRuleFactory *pFactory,CCurrHedgeRule *pResult)
		:CCurrHedgeRuleIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrHedgeRuleSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrHedgeRule
	///@return	下一个满足条件CCurrHedgeRule，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrHedgeRule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrHedgeRule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRulePredict是判断一个当前合约套期保值属性是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRulePredict
{
public:
	///判断是否合法
	///@param	pCurrHedgeRule	要被判断的当前合约套期保值属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleAndPredict是对两个当前合约套期保值属性谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleAndPredict : public CCurrHedgeRulePredict
{
private:
	CCurrHedgeRulePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrHedgeRuleAndPredict(CCurrHedgeRulePredict *p1, CCurrHedgeRulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrHedgeRuleAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrHedgeRule	要被判断的当前合约套期保值属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)
	{
		return m_p1->isValid(pCurrHedgeRule) && m_p2->isValid(pCurrHedgeRule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleOrPredict是对两个当前合约套期保值属性谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleOrPredict : public CCurrHedgeRulePredict
{
private:
	CCurrHedgeRulePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrHedgeRuleOrPredict(CCurrHedgeRulePredict *p1, CCurrHedgeRulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrHedgeRuleOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrHedgeRule	要被判断的当前合约套期保值属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)
	{
		return m_p1->isValid(pCurrHedgeRule) || m_p2->isValid(pCurrHedgeRule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleNotPredict是对一个当前合约套期保值属性谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleNotPredict : public CCurrHedgeRulePredict
{
private:
	CCurrHedgeRulePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrHedgeRuleNotPredict(CCurrHedgeRulePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrHedgeRuleNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrHedgeRule	要被判断的当前合约套期保值属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrHedgeRule *pCurrHedgeRule)
	{
		return !m_predict->isValid(pCurrHedgeRule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleFilter是一个对已有的当前合约套期保值属性枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleFilter: public CCurrHedgeRuleIterator
{
private:
	CCurrHedgeRuleIterator *m_baseIterator;
	CCurrHedgeRulePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrHedgeRuleFilter(CCurrHedgeRuleIterator *pBaseIterator, CCurrHedgeRulePredict *pPredict, bool continueResult=false)
		:CCurrHedgeRuleIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrHedgeRuleFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrHedgeRule
	///@return	下一个满足条件CCurrHedgeRule，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrHedgeRule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrHedgeRule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleLinkIterator是连接两个当前合约套期保值属性枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleLinkIterator: public CCurrHedgeRuleIterator
{
private:
	CCurrHedgeRuleIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrHedgeRuleLinkIterator(CCurrHedgeRuleIterator *pBaseIterator1,CCurrHedgeRuleIterator *pBaseIterator2)
		:CCurrHedgeRuleIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrHedgeRuleLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrHedgeRule
	///@return	下一个满足条件CCurrHedgeRule，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrHedgeRule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrHedgeRule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrSingleIterator是至多返回一个当前合约交易阶段属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrSingleIterator: public CCurrTradingSegmentAttrIterator
{
private:
	CCurrTradingSegmentAttr *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrTradingSegmentAttrSingleIterator(CCurrTradingSegmentAttrFactory *pFactory,CCurrTradingSegmentAttr *pResult)
		:CCurrTradingSegmentAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrTradingSegmentAttrSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrTradingSegmentAttr
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrPredict是判断一个当前合约交易阶段属性是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrPredict
{
public:
	///判断是否合法
	///@param	pCurrTradingSegmentAttr	要被判断的当前合约交易阶段属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrAndPredict是对两个当前合约交易阶段属性谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrAndPredict : public CCurrTradingSegmentAttrPredict
{
private:
	CCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrTradingSegmentAttrAndPredict(CCurrTradingSegmentAttrPredict *p1, CCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrTradingSegmentAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrTradingSegmentAttr	要被判断的当前合约交易阶段属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pCurrTradingSegmentAttr) && m_p2->isValid(pCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrOrPredict是对两个当前合约交易阶段属性谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrOrPredict : public CCurrTradingSegmentAttrPredict
{
private:
	CCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrTradingSegmentAttrOrPredict(CCurrTradingSegmentAttrPredict *p1, CCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrTradingSegmentAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrTradingSegmentAttr	要被判断的当前合约交易阶段属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pCurrTradingSegmentAttr) || m_p2->isValid(pCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrNotPredict是对一个当前合约交易阶段属性谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrNotPredict : public CCurrTradingSegmentAttrPredict
{
private:
	CCurrTradingSegmentAttrPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrTradingSegmentAttrNotPredict(CCurrTradingSegmentAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrTradingSegmentAttrNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrTradingSegmentAttr	要被判断的当前合约交易阶段属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return !m_predict->isValid(pCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrFilter是一个对已有的当前合约交易阶段属性枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrFilter: public CCurrTradingSegmentAttrIterator
{
private:
	CCurrTradingSegmentAttrIterator *m_baseIterator;
	CCurrTradingSegmentAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrTradingSegmentAttrFilter(CCurrTradingSegmentAttrIterator *pBaseIterator, CCurrTradingSegmentAttrPredict *pPredict, bool continueResult=false)
		:CCurrTradingSegmentAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrTradingSegmentAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrTradingSegmentAttr
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrLinkIterator是连接两个当前合约交易阶段属性枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrLinkIterator: public CCurrTradingSegmentAttrIterator
{
private:
	CCurrTradingSegmentAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrTradingSegmentAttrLinkIterator(CCurrTradingSegmentAttrIterator *pBaseIterator1,CCurrTradingSegmentAttrIterator *pBaseIterator2)
		:CCurrTradingSegmentAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrTradingSegmentAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrTradingSegmentAttr
	///@return	下一个满足条件CCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrFuseSingleIterator是至多返回一个当前合约熔断属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseSingleIterator: public CCurrFuseIterator
{
private:
	CCurrFuse *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrFuseSingleIterator(CCurrFuseFactory *pFactory,CCurrFuse *pResult)
		:CCurrFuseIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrFuseSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrFuse
	///@return	下一个满足条件CCurrFuse，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrFuse *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrFuse 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFusePredict是判断一个当前合约熔断属性是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFusePredict
{
public:
	///判断是否合法
	///@param	pCurrFuse	要被判断的当前合约熔断属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrFuse *pCurrFuse)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseAndPredict是对两个当前合约熔断属性谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseAndPredict : public CCurrFusePredict
{
private:
	CCurrFusePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrFuseAndPredict(CCurrFusePredict *p1, CCurrFusePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrFuseAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrFuse	要被判断的当前合约熔断属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrFuse *pCurrFuse)
	{
		return m_p1->isValid(pCurrFuse) && m_p2->isValid(pCurrFuse);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseOrPredict是对两个当前合约熔断属性谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseOrPredict : public CCurrFusePredict
{
private:
	CCurrFusePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrFuseOrPredict(CCurrFusePredict *p1, CCurrFusePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrFuseOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrFuse	要被判断的当前合约熔断属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrFuse *pCurrFuse)
	{
		return m_p1->isValid(pCurrFuse) || m_p2->isValid(pCurrFuse);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseNotPredict是对一个当前合约熔断属性谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseNotPredict : public CCurrFusePredict
{
private:
	CCurrFusePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrFuseNotPredict(CCurrFusePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrFuseNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrFuse	要被判断的当前合约熔断属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrFuse *pCurrFuse)
	{
		return !m_predict->isValid(pCurrFuse);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseFilter是一个对已有的当前合约熔断属性枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseFilter: public CCurrFuseIterator
{
private:
	CCurrFuseIterator *m_baseIterator;
	CCurrFusePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrFuseFilter(CCurrFuseIterator *pBaseIterator, CCurrFusePredict *pPredict, bool continueResult=false)
		:CCurrFuseIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrFuseFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrFuse
	///@return	下一个满足条件CCurrFuse，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrFuse *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrFuse 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseLinkIterator是连接两个当前合约熔断属性枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseLinkIterator: public CCurrFuseIterator
{
private:
	CCurrFuseIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrFuseLinkIterator(CCurrFuseIterator *pBaseIterator1,CCurrFuseIterator *pBaseIterator2)
		:CCurrFuseIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrFuseLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrFuse
	///@return	下一个满足条件CCurrFuse，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrFuse *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrFuse 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTradingAccountSingleIterator是至多返回一个交易账户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountSingleIterator: public CTradingAccountIterator
{
private:
	CTradingAccount *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CTradingAccountSingleIterator(CTradingAccountFactory *pFactory,CTradingAccount *pResult)
		:CTradingAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CTradingAccountSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CTradingAccount
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CTradingAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTradingAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountPredict是判断一个交易账户是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountPredict
{
public:
	///判断是否合法
	///@param	pTradingAccount	要被判断的交易账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTradingAccount *pTradingAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountAndPredict是对两个交易账户谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountAndPredict : public CTradingAccountPredict
{
private:
	CTradingAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTradingAccountAndPredict(CTradingAccountPredict *p1, CTradingAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTradingAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTradingAccount	要被判断的交易账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTradingAccount *pTradingAccount)
	{
		return m_p1->isValid(pTradingAccount) && m_p2->isValid(pTradingAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountOrPredict是对两个交易账户谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountOrPredict : public CTradingAccountPredict
{
private:
	CTradingAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTradingAccountOrPredict(CTradingAccountPredict *p1, CTradingAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTradingAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTradingAccount	要被判断的交易账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTradingAccount *pTradingAccount)
	{
		return m_p1->isValid(pTradingAccount) || m_p2->isValid(pTradingAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountNotPredict是对一个交易账户谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountNotPredict : public CTradingAccountPredict
{
private:
	CTradingAccountPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CTradingAccountNotPredict(CTradingAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CTradingAccountNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pTradingAccount	要被判断的交易账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTradingAccount *pTradingAccount)
	{
		return !m_predict->isValid(pTradingAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountFilter是一个对已有的交易账户枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountFilter: public CTradingAccountIterator
{
private:
	CTradingAccountIterator *m_baseIterator;
	CTradingAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CTradingAccountFilter(CTradingAccountIterator *pBaseIterator, CTradingAccountPredict *pPredict, bool continueResult=false)
		:CTradingAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CTradingAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CTradingAccount
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CTradingAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTradingAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountLinkIterator是连接两个交易账户枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountLinkIterator: public CTradingAccountIterator
{
private:
	CTradingAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CTradingAccountLinkIterator(CTradingAccountIterator *pBaseIterator1,CTradingAccountIterator *pBaseIterator2)
		:CTradingAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CTradingAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CTradingAccount
	///@return	下一个满足条件CTradingAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CTradingAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTradingAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountOfTradingAccountIterator是一个交易账户枚举器对应的基本准备金账户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountOfTradingAccountIterator: public CBaseReserveAccountIterator
{
private:
	CTradingAccountIterator *m_baseIterator;
	CBaseReserveAccount *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CBaseReserveAccountOfTradingAccountIterator(CBaseReserveAccountFactory *pFactory,CTradingAccountIterator *pBaseIterator)
		:CBaseReserveAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CBaseReserveAccountOfTradingAccountIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CBaseReserveAccount
	///@return	下一个满足条件CBaseReserveAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CBaseReserveAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBaseReserveAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBaseReserveAccount *pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountSingleIterator是至多返回一个基本准备金账户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountSingleIterator: public CBaseReserveAccountIterator
{
private:
	CBaseReserveAccount *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CBaseReserveAccountSingleIterator(CBaseReserveAccountFactory *pFactory,CBaseReserveAccount *pResult)
		:CBaseReserveAccountIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CBaseReserveAccountSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CBaseReserveAccount
	///@return	下一个满足条件CBaseReserveAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CBaseReserveAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBaseReserveAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountPredict是判断一个基本准备金账户是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountPredict
{
public:
	///判断是否合法
	///@param	pBaseReserveAccount	要被判断的基本准备金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)=0;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountAndPredict是对两个基本准备金账户谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountAndPredict : public CBaseReserveAccountPredict
{
private:
	CBaseReserveAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CBaseReserveAccountAndPredict(CBaseReserveAccountPredict *p1, CBaseReserveAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CBaseReserveAccountAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pBaseReserveAccount	要被判断的基本准备金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)
	{
		return m_p1->isValid(pBaseReserveAccount) && m_p2->isValid(pBaseReserveAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountOrPredict是对两个基本准备金账户谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountOrPredict : public CBaseReserveAccountPredict
{
private:
	CBaseReserveAccountPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CBaseReserveAccountOrPredict(CBaseReserveAccountPredict *p1, CBaseReserveAccountPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CBaseReserveAccountOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pBaseReserveAccount	要被判断的基本准备金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)
	{
		return m_p1->isValid(pBaseReserveAccount) || m_p2->isValid(pBaseReserveAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountNotPredict是对一个基本准备金账户谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountNotPredict : public CBaseReserveAccountPredict
{
private:
	CBaseReserveAccountPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CBaseReserveAccountNotPredict(CBaseReserveAccountPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CBaseReserveAccountNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pBaseReserveAccount	要被判断的基本准备金账户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBaseReserveAccount *pBaseReserveAccount)
	{
		return !m_predict->isValid(pBaseReserveAccount);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountFilter是一个对已有的基本准备金账户枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountFilter: public CBaseReserveAccountIterator
{
private:
	CBaseReserveAccountIterator *m_baseIterator;
	CBaseReserveAccountPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CBaseReserveAccountFilter(CBaseReserveAccountIterator *pBaseIterator, CBaseReserveAccountPredict *pPredict, bool continueResult=false)
		:CBaseReserveAccountIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CBaseReserveAccountFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CBaseReserveAccount
	///@return	下一个满足条件CBaseReserveAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CBaseReserveAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBaseReserveAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountLinkIterator是连接两个基本准备金账户枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountLinkIterator: public CBaseReserveAccountIterator
{
private:
	CBaseReserveAccountIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CBaseReserveAccountLinkIterator(CBaseReserveAccountIterator *pBaseIterator1,CBaseReserveAccountIterator *pBaseIterator2)
		:CBaseReserveAccountIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CBaseReserveAccountLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CBaseReserveAccount
	///@return	下一个满足条件CBaseReserveAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CBaseReserveAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBaseReserveAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CPartPositionSingleIterator是至多返回一个会员持仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionSingleIterator: public CPartPositionIterator
{
private:
	CPartPosition *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CPartPositionSingleIterator(CPartPositionFactory *pFactory,CPartPosition *pResult)
		:CPartPositionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CPartPositionSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CPartPosition
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionPredict是判断一个会员持仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionPredict
{
public:
	///判断是否合法
	///@param	pPartPosition	要被判断的会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartPosition *pPartPosition)=0;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionAndPredict是对两个会员持仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionAndPredict : public CPartPositionPredict
{
private:
	CPartPositionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartPositionAndPredict(CPartPositionPredict *p1, CPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartPositionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartPosition	要被判断的会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartPosition *pPartPosition)
	{
		return m_p1->isValid(pPartPosition) && m_p2->isValid(pPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionOrPredict是对两个会员持仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionOrPredict : public CPartPositionPredict
{
private:
	CPartPositionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CPartPositionOrPredict(CPartPositionPredict *p1, CPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CPartPositionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pPartPosition	要被判断的会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartPosition *pPartPosition)
	{
		return m_p1->isValid(pPartPosition) || m_p2->isValid(pPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionNotPredict是对一个会员持仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionNotPredict : public CPartPositionPredict
{
private:
	CPartPositionPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CPartPositionNotPredict(CPartPositionPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CPartPositionNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pPartPosition	要被判断的会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CPartPosition *pPartPosition)
	{
		return !m_predict->isValid(pPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionFilter是一个对已有的会员持仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionFilter: public CPartPositionIterator
{
private:
	CPartPositionIterator *m_baseIterator;
	CPartPositionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CPartPositionFilter(CPartPositionIterator *pBaseIterator, CPartPositionPredict *pPredict, bool continueResult=false)
		:CPartPositionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CPartPositionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CPartPosition
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionLinkIterator是连接两个会员持仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionLinkIterator: public CPartPositionIterator
{
private:
	CPartPositionIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CPartPositionLinkIterator(CPartPositionIterator *pBaseIterator1,CPartPositionIterator *pBaseIterator2)
		:CPartPositionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CPartPositionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CPartPosition
	///@return	下一个满足条件CPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClientPositionSingleIterator是至多返回一个客户持仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionSingleIterator: public CClientPositionIterator
{
private:
	CClientPosition *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CClientPositionSingleIterator(CClientPositionFactory *pFactory,CClientPosition *pResult)
		:CClientPositionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CClientPositionSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CClientPosition
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionPredict是判断一个客户持仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionPredict
{
public:
	///判断是否合法
	///@param	pClientPosition	要被判断的客户持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientPosition *pClientPosition)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionAndPredict是对两个客户持仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionAndPredict : public CClientPositionPredict
{
private:
	CClientPositionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientPositionAndPredict(CClientPositionPredict *p1, CClientPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientPositionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClientPosition	要被判断的客户持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientPosition *pClientPosition)
	{
		return m_p1->isValid(pClientPosition) && m_p2->isValid(pClientPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionOrPredict是对两个客户持仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionOrPredict : public CClientPositionPredict
{
private:
	CClientPositionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClientPositionOrPredict(CClientPositionPredict *p1, CClientPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClientPositionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClientPosition	要被判断的客户持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientPosition *pClientPosition)
	{
		return m_p1->isValid(pClientPosition) || m_p2->isValid(pClientPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionNotPredict是对一个客户持仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionNotPredict : public CClientPositionPredict
{
private:
	CClientPositionPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CClientPositionNotPredict(CClientPositionPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CClientPositionNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pClientPosition	要被判断的客户持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClientPosition *pClientPosition)
	{
		return !m_predict->isValid(pClientPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionFilter是一个对已有的客户持仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionFilter: public CClientPositionIterator
{
private:
	CClientPositionIterator *m_baseIterator;
	CClientPositionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CClientPositionFilter(CClientPositionIterator *pBaseIterator, CClientPositionPredict *pPredict, bool continueResult=false)
		:CClientPositionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CClientPositionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CClientPosition
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionLinkIterator是连接两个客户持仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionLinkIterator: public CClientPositionIterator
{
private:
	CClientPositionIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CClientPositionLinkIterator(CClientPositionIterator *pBaseIterator1,CClientPositionIterator *pBaseIterator2)
		:CClientPositionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CClientPositionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CClientPosition
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitOfClientPositionIterator是一个客户持仓枚举器对应的信用额度的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitOfClientPositionIterator: public CCreditLimitIterator
{
private:
	CClientPositionIterator *m_baseIterator;
	CCreditLimit *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CCreditLimitOfClientPositionIterator(CCreditLimitFactory *pFactory,CClientPositionIterator *pBaseIterator)
		:CCreditLimitIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CCreditLimitOfClientPositionIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CCreditLimit
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCreditLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit *pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountOfClientPositionIterator是一个客户持仓枚举器对应的会员角色帐号的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountOfClientPositionIterator: public CPartRoleAccountIterator
{
private:
	CClientPositionIterator *m_baseIterator;
	CPartRoleAccount *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CPartRoleAccountOfClientPositionIterator(CPartRoleAccountFactory *pFactory,CClientPositionIterator *pBaseIterator)
		:CPartRoleAccountIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CPartRoleAccountOfClientPositionIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CPartRoleAccount
	///@return	下一个满足条件CPartRoleAccount，如果已经没有一个满足要求了，则返回NULL
	virtual CPartRoleAccount *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartRoleAccount 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartRoleAccount *pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeSingleIterator是至多返回一个保值额度量的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeSingleIterator: public CHedgeVolumeIterator
{
private:
	CHedgeVolume *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CHedgeVolumeSingleIterator(CHedgeVolumeFactory *pFactory,CHedgeVolume *pResult)
		:CHedgeVolumeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CHedgeVolumeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CHedgeVolume
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	virtual CHedgeVolume *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pHedgeVolume 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumePredict是判断一个保值额度量是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumePredict
{
public:
	///判断是否合法
	///@param	pHedgeVolume	要被判断的保值额度量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CHedgeVolume *pHedgeVolume)=0;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeAndPredict是对两个保值额度量谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeAndPredict : public CHedgeVolumePredict
{
private:
	CHedgeVolumePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CHedgeVolumeAndPredict(CHedgeVolumePredict *p1, CHedgeVolumePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CHedgeVolumeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pHedgeVolume	要被判断的保值额度量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CHedgeVolume *pHedgeVolume)
	{
		return m_p1->isValid(pHedgeVolume) && m_p2->isValid(pHedgeVolume);
	}
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeOrPredict是对两个保值额度量谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeOrPredict : public CHedgeVolumePredict
{
private:
	CHedgeVolumePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CHedgeVolumeOrPredict(CHedgeVolumePredict *p1, CHedgeVolumePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CHedgeVolumeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pHedgeVolume	要被判断的保值额度量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CHedgeVolume *pHedgeVolume)
	{
		return m_p1->isValid(pHedgeVolume) || m_p2->isValid(pHedgeVolume);
	}
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeNotPredict是对一个保值额度量谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeNotPredict : public CHedgeVolumePredict
{
private:
	CHedgeVolumePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CHedgeVolumeNotPredict(CHedgeVolumePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CHedgeVolumeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pHedgeVolume	要被判断的保值额度量
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CHedgeVolume *pHedgeVolume)
	{
		return !m_predict->isValid(pHedgeVolume);
	}
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeFilter是一个对已有的保值额度量枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeFilter: public CHedgeVolumeIterator
{
private:
	CHedgeVolumeIterator *m_baseIterator;
	CHedgeVolumePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CHedgeVolumeFilter(CHedgeVolumeIterator *pBaseIterator, CHedgeVolumePredict *pPredict, bool continueResult=false)
		:CHedgeVolumeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CHedgeVolumeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CHedgeVolume
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	virtual CHedgeVolume *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pHedgeVolume 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeLinkIterator是连接两个保值额度量枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeLinkIterator: public CHedgeVolumeIterator
{
private:
	CHedgeVolumeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CHedgeVolumeLinkIterator(CHedgeVolumeIterator *pBaseIterator1,CHedgeVolumeIterator *pBaseIterator2)
		:CHedgeVolumeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CHedgeVolumeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CHedgeVolume
	///@return	下一个满足条件CHedgeVolume，如果已经没有一个满足要求了，则返回NULL
	virtual CHedgeVolume *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pHedgeVolume 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRemainOrderSingleIterator是至多返回一个历史报单的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderSingleIterator: public CRemainOrderIterator
{
private:
	CRemainOrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRemainOrderSingleIterator(CRemainOrderFactory *pFactory,CRemainOrder *pResult)
		:CRemainOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRemainOrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRemainOrder
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CRemainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRemainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderPredict是判断一个历史报单是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderPredict
{
public:
	///判断是否合法
	///@param	pRemainOrder	要被判断的历史报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRemainOrder *pRemainOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderAndPredict是对两个历史报单谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderAndPredict : public CRemainOrderPredict
{
private:
	CRemainOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRemainOrderAndPredict(CRemainOrderPredict *p1, CRemainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRemainOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRemainOrder	要被判断的历史报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRemainOrder *pRemainOrder)
	{
		return m_p1->isValid(pRemainOrder) && m_p2->isValid(pRemainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderOrPredict是对两个历史报单谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderOrPredict : public CRemainOrderPredict
{
private:
	CRemainOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRemainOrderOrPredict(CRemainOrderPredict *p1, CRemainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRemainOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRemainOrder	要被判断的历史报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRemainOrder *pRemainOrder)
	{
		return m_p1->isValid(pRemainOrder) || m_p2->isValid(pRemainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderNotPredict是对一个历史报单谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderNotPredict : public CRemainOrderPredict
{
private:
	CRemainOrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRemainOrderNotPredict(CRemainOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRemainOrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRemainOrder	要被判断的历史报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRemainOrder *pRemainOrder)
	{
		return !m_predict->isValid(pRemainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderFilter是一个对已有的历史报单枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderFilter: public CRemainOrderIterator
{
private:
	CRemainOrderIterator *m_baseIterator;
	CRemainOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRemainOrderFilter(CRemainOrderIterator *pBaseIterator, CRemainOrderPredict *pPredict, bool continueResult=false)
		:CRemainOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRemainOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRemainOrder
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CRemainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRemainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderLinkIterator是连接两个历史报单枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderLinkIterator: public CRemainOrderIterator
{
private:
	CRemainOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRemainOrderLinkIterator(CRemainOrderIterator *pBaseIterator1,CRemainOrderIterator *pBaseIterator2)
		:CRemainOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRemainOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRemainOrder
	///@return	下一个满足条件CRemainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CRemainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRemainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMarketDataSingleIterator是至多返回一个行情的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataSingleIterator: public CMarketDataIterator
{
private:
	CMarketData *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMarketDataSingleIterator(CMarketDataFactory *pFactory,CMarketData *pResult)
		:CMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMarketDataSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMarketData
	///@return	下一个满足条件CMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataPredict是判断一个行情是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataPredict
{
public:
	///判断是否合法
	///@param	pMarketData	要被判断的行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketData *pMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataAndPredict是对两个行情谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataAndPredict : public CMarketDataPredict
{
private:
	CMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataAndPredict(CMarketDataPredict *p1, CMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketData	要被判断的行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketData *pMarketData)
	{
		return m_p1->isValid(pMarketData) && m_p2->isValid(pMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataOrPredict是对两个行情谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataOrPredict : public CMarketDataPredict
{
private:
	CMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMarketDataOrPredict(CMarketDataPredict *p1, CMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMarketData	要被判断的行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketData *pMarketData)
	{
		return m_p1->isValid(pMarketData) || m_p2->isValid(pMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataNotPredict是对一个行情谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataNotPredict : public CMarketDataPredict
{
private:
	CMarketDataPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMarketDataNotPredict(CMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMarketData	要被判断的行情
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMarketData *pMarketData)
	{
		return !m_predict->isValid(pMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataFilter是一个对已有的行情枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataFilter: public CMarketDataIterator
{
private:
	CMarketDataIterator *m_baseIterator;
	CMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMarketDataFilter(CMarketDataIterator *pBaseIterator, CMarketDataPredict *pPredict, bool continueResult=false)
		:CMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMarketData
	///@return	下一个满足条件CMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLinkIterator是连接两个行情枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLinkIterator: public CMarketDataIterator
{
private:
	CMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMarketDataLinkIterator(CMarketDataIterator *pBaseIterator1,CMarketDataIterator *pBaseIterator2)
		:CMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMarketData
	///@return	下一个满足条件CMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionSingleIterator是至多返回一个结算会员持仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionSingleIterator: public CClearingPartPositionIterator
{
private:
	CClearingPartPosition *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CClearingPartPositionSingleIterator(CClearingPartPositionFactory *pFactory,CClearingPartPosition *pResult)
		:CClearingPartPositionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CClearingPartPositionSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CClearingPartPosition
	///@return	下一个满足条件CClearingPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClearingPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionPredict是判断一个结算会员持仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionPredict
{
public:
	///判断是否合法
	///@param	pClearingPartPosition	要被判断的结算会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)=0;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionAndPredict是对两个结算会员持仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionAndPredict : public CClearingPartPositionPredict
{
private:
	CClearingPartPositionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClearingPartPositionAndPredict(CClearingPartPositionPredict *p1, CClearingPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClearingPartPositionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClearingPartPosition	要被判断的结算会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)
	{
		return m_p1->isValid(pClearingPartPosition) && m_p2->isValid(pClearingPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionOrPredict是对两个结算会员持仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionOrPredict : public CClearingPartPositionPredict
{
private:
	CClearingPartPositionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CClearingPartPositionOrPredict(CClearingPartPositionPredict *p1, CClearingPartPositionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CClearingPartPositionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pClearingPartPosition	要被判断的结算会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)
	{
		return m_p1->isValid(pClearingPartPosition) || m_p2->isValid(pClearingPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionNotPredict是对一个结算会员持仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionNotPredict : public CClearingPartPositionPredict
{
private:
	CClearingPartPositionPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CClearingPartPositionNotPredict(CClearingPartPositionPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CClearingPartPositionNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pClearingPartPosition	要被判断的结算会员持仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CClearingPartPosition *pClearingPartPosition)
	{
		return !m_predict->isValid(pClearingPartPosition);
	}
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionFilter是一个对已有的结算会员持仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionFilter: public CClearingPartPositionIterator
{
private:
	CClearingPartPositionIterator *m_baseIterator;
	CClearingPartPositionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CClearingPartPositionFilter(CClearingPartPositionIterator *pBaseIterator, CClearingPartPositionPredict *pPredict, bool continueResult=false)
		:CClearingPartPositionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CClearingPartPositionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CClearingPartPosition
	///@return	下一个满足条件CClearingPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClearingPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionLinkIterator是连接两个结算会员持仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionLinkIterator: public CClearingPartPositionIterator
{
private:
	CClearingPartPositionIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CClearingPartPositionLinkIterator(CClearingPartPositionIterator *pBaseIterator1,CClearingPartPositionIterator *pBaseIterator2)
		:CClearingPartPositionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CClearingPartPositionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CClearingPartPosition
	///@return	下一个满足条件CClearingPartPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClearingPartPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClearingPartPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusSingleIterator是至多返回一个合约状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusSingleIterator: public CInstrumentStatusIterator
{
private:
	CInstrumentStatus *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CInstrumentStatusSingleIterator(CInstrumentStatusFactory *pFactory,CInstrumentStatus *pResult)
		:CInstrumentStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CInstrumentStatusSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CInstrumentStatus
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusPredict是判断一个合约状态是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusPredict
{
public:
	///判断是否合法
	///@param	pInstrumentStatus	要被判断的合约状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusAndPredict是对两个合约状态谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusAndPredict : public CInstrumentStatusPredict
{
private:
	CInstrumentStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInstrumentStatusAndPredict(CInstrumentStatusPredict *p1, CInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInstrumentStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInstrumentStatus	要被判断的合约状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)
	{
		return m_p1->isValid(pInstrumentStatus) && m_p2->isValid(pInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusOrPredict是对两个合约状态谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusOrPredict : public CInstrumentStatusPredict
{
private:
	CInstrumentStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CInstrumentStatusOrPredict(CInstrumentStatusPredict *p1, CInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CInstrumentStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pInstrumentStatus	要被判断的合约状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)
	{
		return m_p1->isValid(pInstrumentStatus) || m_p2->isValid(pInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusNotPredict是对一个合约状态谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusNotPredict : public CInstrumentStatusPredict
{
private:
	CInstrumentStatusPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CInstrumentStatusNotPredict(CInstrumentStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CInstrumentStatusNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pInstrumentStatus	要被判断的合约状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CInstrumentStatus *pInstrumentStatus)
	{
		return !m_predict->isValid(pInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusFilter是一个对已有的合约状态枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusFilter: public CInstrumentStatusIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CInstrumentStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CInstrumentStatusFilter(CInstrumentStatusIterator *pBaseIterator, CInstrumentStatusPredict *pPredict, bool continueResult=false)
		:CInstrumentStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CInstrumentStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CInstrumentStatus
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusLinkIterator是连接两个合约状态枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusLinkIterator: public CInstrumentStatusIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CInstrumentStatusLinkIterator(CInstrumentStatusIterator *pBaseIterator1,CInstrumentStatusIterator *pBaseIterator2)
		:CInstrumentStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CInstrumentStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CInstrumentStatus
	///@return	下一个满足条件CInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfInstrumentStatusIterator是一个合约状态枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfInstrumentStatusIterator: public CInstrumentIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfInstrumentStatusIterator(CInstrumentFactory *pFactory,CInstrumentStatusIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfInstrumentStatusIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingOfInstrumentStatusIterator是一个合约状态枚举器对应的价格绑定的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingOfInstrumentStatusIterator: public CCurrPriceBandingIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CCurrPriceBanding *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CCurrPriceBandingOfInstrumentStatusIterator(CCurrPriceBandingFactory *pFactory,CInstrumentStatusIterator *pBaseIterator)
		:CCurrPriceBandingIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CCurrPriceBandingOfInstrumentStatusIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CCurrPriceBanding
	///@return	下一个满足条件CCurrPriceBanding，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrPriceBanding *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrPriceBanding 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrPriceBanding *pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusOfInstrumentStatusIterator是一个合约状态枚举器对应的行情发布状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusOfInstrumentStatusIterator: public CMdPubStatusIterator
{
private:
	CInstrumentStatusIterator *m_baseIterator;
	CMdPubStatus *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CMdPubStatusOfInstrumentStatusIterator(CMdPubStatusFactory *pFactory,CInstrumentStatusIterator *pBaseIterator)
		:CMdPubStatusIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CMdPubStatusOfInstrumentStatusIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CMdPubStatus
	///@return	下一个满足条件CMdPubStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CMdPubStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMdPubStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMdPubStatus *pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///COrderSingleIterator是至多返回一个报单的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderSingleIterator: public COrderIterator
{
private:
	COrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	COrderSingleIterator(COrderFactory *pFactory,COrder *pResult)
		:COrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~COrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的COrder
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderPredict是判断一个报单是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderPredict
{
public:
	///判断是否合法
	///@param	pOrder	要被判断的报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrder *pOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///COrderAndPredict是对两个报单谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderAndPredict : public COrderPredict
{
private:
	COrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	COrderAndPredict(COrderPredict *p1, COrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~COrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pOrder	要被判断的报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrder *pOrder)
	{
		return m_p1->isValid(pOrder) && m_p2->isValid(pOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderOrPredict是对两个报单谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderOrPredict : public COrderPredict
{
private:
	COrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	COrderOrPredict(COrderPredict *p1, COrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~COrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pOrder	要被判断的报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrder *pOrder)
	{
		return m_p1->isValid(pOrder) || m_p2->isValid(pOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderNotPredict是对一个报单谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderNotPredict : public COrderPredict
{
private:
	COrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	COrderNotPredict(COrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~COrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pOrder	要被判断的报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COrder *pOrder)
	{
		return !m_predict->isValid(pOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COrderFilter是一个对已有的报单枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderFilter: public COrderIterator
{
private:
	COrderIterator *m_baseIterator;
	COrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	COrderFilter(COrderIterator *pBaseIterator, COrderPredict *pPredict, bool continueResult=false)
		:COrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~COrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的COrder
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COrderLinkIterator是连接两个报单枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderLinkIterator: public COrderIterator
{
private:
	COrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	COrderLinkIterator(COrderIterator *pBaseIterator1,COrderIterator *pBaseIterator2)
		:COrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~COrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的COrder
	///@return	下一个满足条件COrder，如果已经没有一个满足要求了，则返回NULL
	virtual COrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfOrderIterator是一个报单枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfOrderIterator: public CInstrumentIterator
{
private:
	COrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfOrderIterator(CInstrumentFactory *pFactory,COrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfOrderIterator是一个报单枚举器指定的会员客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfOrderIterator: public CPartClientIterator
{
private:
	COrderIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CPartClientOfOrderIterator(CPartClientFactory *pFactory,COrderIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CPartClientOfOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionOfOrderIterator是一个报单枚举器对应的客户持仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionOfOrderIterator: public CClientPositionIterator
{
private:
	COrderIterator *m_baseIterator;
	CClientPosition *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CClientPositionOfOrderIterator(CClientPositionFactory *pFactory,COrderIterator *pBaseIterator)
		:CClientPositionIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CClientPositionOfOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CClientPosition
	///@return	下一个满足条件CClientPosition，如果已经没有一个满足要求了，则返回NULL
	virtual CClientPosition *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pClientPosition 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableClientPosition *pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCombOrderSingleIterator是至多返回一个组合报单的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderSingleIterator: public CCombOrderIterator
{
private:
	CCombOrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCombOrderSingleIterator(CCombOrderFactory *pFactory,CCombOrder *pResult)
		:CCombOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCombOrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCombOrder
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CCombOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCombOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderPredict是判断一个组合报单是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderPredict
{
public:
	///判断是否合法
	///@param	pCombOrder	要被判断的组合报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombOrder *pCombOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderAndPredict是对两个组合报单谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderAndPredict : public CCombOrderPredict
{
private:
	CCombOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCombOrderAndPredict(CCombOrderPredict *p1, CCombOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCombOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCombOrder	要被判断的组合报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombOrder *pCombOrder)
	{
		return m_p1->isValid(pCombOrder) && m_p2->isValid(pCombOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderOrPredict是对两个组合报单谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderOrPredict : public CCombOrderPredict
{
private:
	CCombOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCombOrderOrPredict(CCombOrderPredict *p1, CCombOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCombOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCombOrder	要被判断的组合报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombOrder *pCombOrder)
	{
		return m_p1->isValid(pCombOrder) || m_p2->isValid(pCombOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderNotPredict是对一个组合报单谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderNotPredict : public CCombOrderPredict
{
private:
	CCombOrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCombOrderNotPredict(CCombOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCombOrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCombOrder	要被判断的组合报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCombOrder *pCombOrder)
	{
		return !m_predict->isValid(pCombOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderFilter是一个对已有的组合报单枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderFilter: public CCombOrderIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CCombOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCombOrderFilter(CCombOrderIterator *pBaseIterator, CCombOrderPredict *pPredict, bool continueResult=false)
		:CCombOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCombOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCombOrder
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CCombOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCombOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderLinkIterator是连接两个组合报单枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderLinkIterator: public CCombOrderIterator
{
private:
	CCombOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCombOrderLinkIterator(CCombOrderIterator *pBaseIterator1,CCombOrderIterator *pBaseIterator2)
		:CCombOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCombOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCombOrder
	///@return	下一个满足条件CCombOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CCombOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCombOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfCombOrderIterator是一个组合报单枚举器指定的会员客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfCombOrderIterator: public CPartClientIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CPartClientOfCombOrderIterator(CPartClientFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CPartClientOfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument1OfCombOrderIterator是一个组合报单枚举器对应的合约1的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument1OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrument1OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrument1OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument2OfCombOrderIterator是一个组合报单枚举器对应的合约2的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument2OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrument2OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrument2OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument3OfCombOrderIterator是一个组合报单枚举器对应的合约3的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument3OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrument3OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrument3OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrument4OfCombOrderIterator是一个组合报单枚举器对应的合约4的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrument4OfCombOrderIterator: public CInstrumentIterator
{
private:
	CCombOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrument4OfCombOrderIterator(CInstrumentFactory *pFactory,CCombOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrument4OfCombOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///COTCOrderSingleIterator是至多返回一个OTC报单的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderSingleIterator: public COTCOrderIterator
{
private:
	COTCOrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	COTCOrderSingleIterator(COTCOrderFactory *pFactory,COTCOrder *pResult)
		:COTCOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~COTCOrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的COTCOrder
	///@return	下一个满足条件COTCOrder，如果已经没有一个满足要求了，则返回NULL
	virtual COTCOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOTCOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderPredict是判断一个OTC报单是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderPredict
{
public:
	///判断是否合法
	///@param	pOTCOrder	要被判断的OTC报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COTCOrder *pOTCOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderAndPredict是对两个OTC报单谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderAndPredict : public COTCOrderPredict
{
private:
	COTCOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	COTCOrderAndPredict(COTCOrderPredict *p1, COTCOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~COTCOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pOTCOrder	要被判断的OTC报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COTCOrder *pOTCOrder)
	{
		return m_p1->isValid(pOTCOrder) && m_p2->isValid(pOTCOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderOrPredict是对两个OTC报单谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderOrPredict : public COTCOrderPredict
{
private:
	COTCOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	COTCOrderOrPredict(COTCOrderPredict *p1, COTCOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~COTCOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pOTCOrder	要被判断的OTC报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COTCOrder *pOTCOrder)
	{
		return m_p1->isValid(pOTCOrder) || m_p2->isValid(pOTCOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderNotPredict是对一个OTC报单谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderNotPredict : public COTCOrderPredict
{
private:
	COTCOrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	COTCOrderNotPredict(COTCOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~COTCOrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pOTCOrder	要被判断的OTC报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(COTCOrder *pOTCOrder)
	{
		return !m_predict->isValid(pOTCOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderFilter是一个对已有的OTC报单枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderFilter: public COTCOrderIterator
{
private:
	COTCOrderIterator *m_baseIterator;
	COTCOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	COTCOrderFilter(COTCOrderIterator *pBaseIterator, COTCOrderPredict *pPredict, bool continueResult=false)
		:COTCOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~COTCOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的COTCOrder
	///@return	下一个满足条件COTCOrder，如果已经没有一个满足要求了，则返回NULL
	virtual COTCOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOTCOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderLinkIterator是连接两个OTC报单枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderLinkIterator: public COTCOrderIterator
{
private:
	COTCOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	COTCOrderLinkIterator(COTCOrderIterator *pBaseIterator1,COTCOrderIterator *pBaseIterator2)
		:COTCOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~COTCOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的COTCOrder
	///@return	下一个满足条件COTCOrder，如果已经没有一个满足要求了，则返回NULL
	virtual COTCOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pOTCOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfOTCOrderIterator是一个OTC报单枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfOTCOrderIterator: public CInstrumentIterator
{
private:
	COTCOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfOTCOrderIterator(CInstrumentFactory *pFactory,COTCOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfOTCOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CImplyOrderSingleIterator是至多返回一个隐式报单的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderSingleIterator: public CImplyOrderIterator
{
private:
	CImplyOrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CImplyOrderSingleIterator(CImplyOrderFactory *pFactory,CImplyOrder *pResult)
		:CImplyOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CImplyOrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CImplyOrder
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CImplyOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pImplyOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderPredict是判断一个隐式报单是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderPredict
{
public:
	///判断是否合法
	///@param	pImplyOrder	要被判断的隐式报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CImplyOrder *pImplyOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderAndPredict是对两个隐式报单谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderAndPredict : public CImplyOrderPredict
{
private:
	CImplyOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CImplyOrderAndPredict(CImplyOrderPredict *p1, CImplyOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CImplyOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pImplyOrder	要被判断的隐式报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CImplyOrder *pImplyOrder)
	{
		return m_p1->isValid(pImplyOrder) && m_p2->isValid(pImplyOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderOrPredict是对两个隐式报单谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderOrPredict : public CImplyOrderPredict
{
private:
	CImplyOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CImplyOrderOrPredict(CImplyOrderPredict *p1, CImplyOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CImplyOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pImplyOrder	要被判断的隐式报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CImplyOrder *pImplyOrder)
	{
		return m_p1->isValid(pImplyOrder) || m_p2->isValid(pImplyOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderNotPredict是对一个隐式报单谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderNotPredict : public CImplyOrderPredict
{
private:
	CImplyOrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CImplyOrderNotPredict(CImplyOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CImplyOrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pImplyOrder	要被判断的隐式报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CImplyOrder *pImplyOrder)
	{
		return !m_predict->isValid(pImplyOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderFilter是一个对已有的隐式报单枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderFilter: public CImplyOrderIterator
{
private:
	CImplyOrderIterator *m_baseIterator;
	CImplyOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CImplyOrderFilter(CImplyOrderIterator *pBaseIterator, CImplyOrderPredict *pPredict, bool continueResult=false)
		:CImplyOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CImplyOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CImplyOrder
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CImplyOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pImplyOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderLinkIterator是连接两个隐式报单枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderLinkIterator: public CImplyOrderIterator
{
private:
	CImplyOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CImplyOrderLinkIterator(CImplyOrderIterator *pBaseIterator1,CImplyOrderIterator *pBaseIterator2)
		:CImplyOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CImplyOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CImplyOrder
	///@return	下一个满足条件CImplyOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CImplyOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pImplyOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CQuoteSingleIterator是至多返回一个报价的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteSingleIterator: public CQuoteIterator
{
private:
	CQuote *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CQuoteSingleIterator(CQuoteFactory *pFactory,CQuote *pResult)
		:CQuoteIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CQuoteSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CQuote
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	virtual CQuote *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pQuote 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CQuotePredict是判断一个报价是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuotePredict
{
public:
	///判断是否合法
	///@param	pQuote	要被判断的报价
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CQuote *pQuote)=0;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteAndPredict是对两个报价谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteAndPredict : public CQuotePredict
{
private:
	CQuotePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CQuoteAndPredict(CQuotePredict *p1, CQuotePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CQuoteAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pQuote	要被判断的报价
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CQuote *pQuote)
	{
		return m_p1->isValid(pQuote) && m_p2->isValid(pQuote);
	}
};

/////////////////////////////////////////////////////////////////////////
///CQuoteOrPredict是对两个报价谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteOrPredict : public CQuotePredict
{
private:
	CQuotePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CQuoteOrPredict(CQuotePredict *p1, CQuotePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CQuoteOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pQuote	要被判断的报价
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CQuote *pQuote)
	{
		return m_p1->isValid(pQuote) || m_p2->isValid(pQuote);
	}
};

/////////////////////////////////////////////////////////////////////////
///CQuoteNotPredict是对一个报价谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteNotPredict : public CQuotePredict
{
private:
	CQuotePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CQuoteNotPredict(CQuotePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CQuoteNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pQuote	要被判断的报价
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CQuote *pQuote)
	{
		return !m_predict->isValid(pQuote);
	}
};

/////////////////////////////////////////////////////////////////////////
///CQuoteFilter是一个对已有的报价枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteFilter: public CQuoteIterator
{
private:
	CQuoteIterator *m_baseIterator;
	CQuotePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CQuoteFilter(CQuoteIterator *pBaseIterator, CQuotePredict *pPredict, bool continueResult=false)
		:CQuoteIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CQuoteFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CQuote
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	virtual CQuote *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pQuote 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CQuoteLinkIterator是连接两个报价枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteLinkIterator: public CQuoteIterator
{
private:
	CQuoteIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CQuoteLinkIterator(CQuoteIterator *pBaseIterator1,CQuoteIterator *pBaseIterator2)
		:CQuoteIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CQuoteLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CQuote
	///@return	下一个满足条件CQuote，如果已经没有一个满足要求了，则返回NULL
	virtual CQuote *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pQuote 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfQuoteIterator是一个报价枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfQuoteIterator: public CInstrumentIterator
{
private:
	CQuoteIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfQuoteIterator(CInstrumentFactory *pFactory,CQuoteIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfQuoteIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfQuoteIterator是一个报价枚举器指定的会员客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfQuoteIterator: public CPartClientIterator
{
private:
	CQuoteIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CPartClientOfQuoteIterator(CPartClientFactory *pFactory,CQuoteIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CPartClientOfQuoteIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataSingleIterator是至多返回一个分价表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataSingleIterator: public CMBLMarketDataIterator
{
private:
	CMBLMarketData *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CMBLMarketDataSingleIterator(CMBLMarketDataFactory *pFactory,CMBLMarketData *pResult)
		:CMBLMarketDataIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CMBLMarketDataSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CMBLMarketData
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMBLMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataPredict是判断一个分价表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataPredict
{
public:
	///判断是否合法
	///@param	pMBLMarketData	要被判断的分价表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMBLMarketData *pMBLMarketData)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataAndPredict是对两个分价表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataAndPredict : public CMBLMarketDataPredict
{
private:
	CMBLMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMBLMarketDataAndPredict(CMBLMarketDataPredict *p1, CMBLMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMBLMarketDataAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMBLMarketData	要被判断的分价表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMBLMarketData *pMBLMarketData)
	{
		return m_p1->isValid(pMBLMarketData) && m_p2->isValid(pMBLMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataOrPredict是对两个分价表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataOrPredict : public CMBLMarketDataPredict
{
private:
	CMBLMarketDataPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CMBLMarketDataOrPredict(CMBLMarketDataPredict *p1, CMBLMarketDataPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CMBLMarketDataOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pMBLMarketData	要被判断的分价表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMBLMarketData *pMBLMarketData)
	{
		return m_p1->isValid(pMBLMarketData) || m_p2->isValid(pMBLMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataNotPredict是对一个分价表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataNotPredict : public CMBLMarketDataPredict
{
private:
	CMBLMarketDataPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CMBLMarketDataNotPredict(CMBLMarketDataPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CMBLMarketDataNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pMBLMarketData	要被判断的分价表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CMBLMarketData *pMBLMarketData)
	{
		return !m_predict->isValid(pMBLMarketData);
	}
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataFilter是一个对已有的分价表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataFilter: public CMBLMarketDataIterator
{
private:
	CMBLMarketDataIterator *m_baseIterator;
	CMBLMarketDataPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CMBLMarketDataFilter(CMBLMarketDataIterator *pBaseIterator, CMBLMarketDataPredict *pPredict, bool continueResult=false)
		:CMBLMarketDataIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CMBLMarketDataFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CMBLMarketData
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMBLMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataLinkIterator是连接两个分价表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataLinkIterator: public CMBLMarketDataIterator
{
private:
	CMBLMarketDataIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CMBLMarketDataLinkIterator(CMBLMarketDataIterator *pBaseIterator1,CMBLMarketDataIterator *pBaseIterator2)
		:CMBLMarketDataIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CMBLMarketDataLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CMBLMarketData
	///@return	下一个满足条件CMBLMarketData，如果已经没有一个满足要求了，则返回NULL
	virtual CMBLMarketData *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pMBLMarketData 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CTradeSingleIterator是至多返回一个成交的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeSingleIterator: public CTradeIterator
{
private:
	CTrade *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CTradeSingleIterator(CTradeFactory *pFactory,CTrade *pResult)
		:CTradeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CTradeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CTrade
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradePredict是判断一个成交是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradePredict
{
public:
	///判断是否合法
	///@param	pTrade	要被判断的成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTrade *pTrade)=0;
};

/////////////////////////////////////////////////////////////////////////
///CTradeAndPredict是对两个成交谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeAndPredict : public CTradePredict
{
private:
	CTradePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTradeAndPredict(CTradePredict *p1, CTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTradeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTrade	要被判断的成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTrade *pTrade)
	{
		return m_p1->isValid(pTrade) && m_p2->isValid(pTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradeOrPredict是对两个成交谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeOrPredict : public CTradePredict
{
private:
	CTradePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CTradeOrPredict(CTradePredict *p1, CTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CTradeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pTrade	要被判断的成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTrade *pTrade)
	{
		return m_p1->isValid(pTrade) || m_p2->isValid(pTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradeNotPredict是对一个成交谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeNotPredict : public CTradePredict
{
private:
	CTradePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CTradeNotPredict(CTradePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CTradeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pTrade	要被判断的成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CTrade *pTrade)
	{
		return !m_predict->isValid(pTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CTradeFilter是一个对已有的成交枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeFilter: public CTradeIterator
{
private:
	CTradeIterator *m_baseIterator;
	CTradePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CTradeFilter(CTradeIterator *pBaseIterator, CTradePredict *pPredict, bool continueResult=false)
		:CTradeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CTradeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CTrade
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CTradeLinkIterator是连接两个成交枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeLinkIterator: public CTradeIterator
{
private:
	CTradeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CTradeLinkIterator(CTradeIterator *pBaseIterator1,CTradeIterator *pBaseIterator2)
		:CTradeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CTradeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CTrade
	///@return	下一个满足条件CTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfTradeIterator是一个成交枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfTradeIterator: public CInstrumentIterator
{
private:
	CTradeIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfTradeIterator(CInstrumentFactory *pFactory,CTradeIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfTradeIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfTradeIterator是一个成交枚举器指定的会员客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfTradeIterator: public CPartClientIterator
{
private:
	CTradeIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CPartClientOfTradeIterator(CPartClientFactory *pFactory,CTradeIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CPartClientOfTradeIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CFusePhaseSingleIterator是至多返回一个熔断阶段的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseSingleIterator: public CFusePhaseIterator
{
private:
	CFusePhase *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CFusePhaseSingleIterator(CFusePhaseFactory *pFactory,CFusePhase *pResult)
		:CFusePhaseIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CFusePhaseSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CFusePhase
	///@return	下一个满足条件CFusePhase，如果已经没有一个满足要求了，则返回NULL
	virtual CFusePhase *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pFusePhase 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhasePredict是判断一个熔断阶段是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhasePredict
{
public:
	///判断是否合法
	///@param	pFusePhase	要被判断的熔断阶段
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFusePhase *pFusePhase)=0;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseAndPredict是对两个熔断阶段谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseAndPredict : public CFusePhasePredict
{
private:
	CFusePhasePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CFusePhaseAndPredict(CFusePhasePredict *p1, CFusePhasePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CFusePhaseAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pFusePhase	要被判断的熔断阶段
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFusePhase *pFusePhase)
	{
		return m_p1->isValid(pFusePhase) && m_p2->isValid(pFusePhase);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseOrPredict是对两个熔断阶段谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseOrPredict : public CFusePhasePredict
{
private:
	CFusePhasePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CFusePhaseOrPredict(CFusePhasePredict *p1, CFusePhasePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CFusePhaseOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pFusePhase	要被判断的熔断阶段
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFusePhase *pFusePhase)
	{
		return m_p1->isValid(pFusePhase) || m_p2->isValid(pFusePhase);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseNotPredict是对一个熔断阶段谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseNotPredict : public CFusePhasePredict
{
private:
	CFusePhasePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CFusePhaseNotPredict(CFusePhasePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CFusePhaseNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pFusePhase	要被判断的熔断阶段
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CFusePhase *pFusePhase)
	{
		return !m_predict->isValid(pFusePhase);
	}
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseFilter是一个对已有的熔断阶段枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseFilter: public CFusePhaseIterator
{
private:
	CFusePhaseIterator *m_baseIterator;
	CFusePhasePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CFusePhaseFilter(CFusePhaseIterator *pBaseIterator, CFusePhasePredict *pPredict, bool continueResult=false)
		:CFusePhaseIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CFusePhaseFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CFusePhase
	///@return	下一个满足条件CFusePhase，如果已经没有一个满足要求了，则返回NULL
	virtual CFusePhase *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pFusePhase 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseLinkIterator是连接两个熔断阶段枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseLinkIterator: public CFusePhaseIterator
{
private:
	CFusePhaseIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CFusePhaseLinkIterator(CFusePhaseIterator *pBaseIterator1,CFusePhaseIterator *pBaseIterator2)
		:CFusePhaseIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CFusePhaseLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CFusePhase
	///@return	下一个满足条件CFusePhase，如果已经没有一个满足要求了，则返回NULL
	virtual CFusePhase *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pFusePhase 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfFusePhaseIterator是一个熔断阶段枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfFusePhaseIterator: public CInstrumentIterator
{
private:
	CFusePhaseIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfFusePhaseIterator(CInstrumentFactory *pFactory,CFusePhaseIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfFusePhaseIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CExecOrderSingleIterator是至多返回一个执行宣告的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderSingleIterator: public CExecOrderIterator
{
private:
	CExecOrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CExecOrderSingleIterator(CExecOrderFactory *pFactory,CExecOrder *pResult)
		:CExecOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CExecOrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CExecOrder
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExecOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderPredict是判断一个执行宣告是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderPredict
{
public:
	///判断是否合法
	///@param	pExecOrder	要被判断的执行宣告
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExecOrder *pExecOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderAndPredict是对两个执行宣告谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderAndPredict : public CExecOrderPredict
{
private:
	CExecOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CExecOrderAndPredict(CExecOrderPredict *p1, CExecOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CExecOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pExecOrder	要被判断的执行宣告
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExecOrder *pExecOrder)
	{
		return m_p1->isValid(pExecOrder) && m_p2->isValid(pExecOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderOrPredict是对两个执行宣告谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderOrPredict : public CExecOrderPredict
{
private:
	CExecOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CExecOrderOrPredict(CExecOrderPredict *p1, CExecOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CExecOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pExecOrder	要被判断的执行宣告
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExecOrder *pExecOrder)
	{
		return m_p1->isValid(pExecOrder) || m_p2->isValid(pExecOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderNotPredict是对一个执行宣告谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderNotPredict : public CExecOrderPredict
{
private:
	CExecOrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CExecOrderNotPredict(CExecOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CExecOrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pExecOrder	要被判断的执行宣告
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CExecOrder *pExecOrder)
	{
		return !m_predict->isValid(pExecOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderFilter是一个对已有的执行宣告枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderFilter: public CExecOrderIterator
{
private:
	CExecOrderIterator *m_baseIterator;
	CExecOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CExecOrderFilter(CExecOrderIterator *pBaseIterator, CExecOrderPredict *pPredict, bool continueResult=false)
		:CExecOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CExecOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CExecOrder
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExecOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderLinkIterator是连接两个执行宣告枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderLinkIterator: public CExecOrderIterator
{
private:
	CExecOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CExecOrderLinkIterator(CExecOrderIterator *pBaseIterator1,CExecOrderIterator *pBaseIterator2)
		:CExecOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CExecOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CExecOrder
	///@return	下一个满足条件CExecOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CExecOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pExecOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CPartClientOfExecOrderIterator是一个执行宣告枚举器指定的会员客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientOfExecOrderIterator: public CPartClientIterator
{
private:
	CExecOrderIterator *m_baseIterator;
	CPartClient *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CPartClientOfExecOrderIterator(CPartClientFactory *pFactory,CExecOrderIterator *pBaseIterator)
		:CPartClientIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CPartClientOfExecOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CPartClient
	///@return	下一个满足条件CPartClient，如果已经没有一个满足要求了，则返回NULL
	virtual CPartClient *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pPartClient 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentOfExecOrderIterator是一个执行宣告枚举器对应的合约的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentOfExecOrderIterator: public CInstrumentIterator
{
private:
	CExecOrderIterator *m_baseIterator;
	CInstrument *m_current;
public:
	///构造函数
	///@param	pFactory	要使用的对象工厂
	///@param	pBaseIterator	基础的枚举器
	CInstrumentOfExecOrderIterator(CInstrumentFactory *pFactory,CExecOrderIterator *pBaseIterator)
		:CInstrumentIterator(pFactory)
	{
		m_baseIterator=pBaseIterator;
		m_current=NULL;
	}
	
	///析构函数
	~CInstrumentOfExecOrderIterator(void)
	{
		m_baseIterator->free();
	}

	///寻找下一个符合条件的CInstrument
	///@return	下一个满足条件CInstrument，如果已经没有一个满足要求了，则返回NULL
	virtual CInstrument *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pInstrument 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CUniPressureSingleIterator是至多返回一个单边市情况的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureSingleIterator: public CUniPressureIterator
{
private:
	CUniPressure *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CUniPressureSingleIterator(CUniPressureFactory *pFactory,CUniPressure *pResult)
		:CUniPressureIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CUniPressureSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CUniPressure
	///@return	下一个满足条件CUniPressure，如果已经没有一个满足要求了，则返回NULL
	virtual CUniPressure *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUniPressure 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressurePredict是判断一个单边市情况是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressurePredict
{
public:
	///判断是否合法
	///@param	pUniPressure	要被判断的单边市情况
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUniPressure *pUniPressure)=0;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureAndPredict是对两个单边市情况谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureAndPredict : public CUniPressurePredict
{
private:
	CUniPressurePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUniPressureAndPredict(CUniPressurePredict *p1, CUniPressurePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUniPressureAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUniPressure	要被判断的单边市情况
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUniPressure *pUniPressure)
	{
		return m_p1->isValid(pUniPressure) && m_p2->isValid(pUniPressure);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureOrPredict是对两个单边市情况谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureOrPredict : public CUniPressurePredict
{
private:
	CUniPressurePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CUniPressureOrPredict(CUniPressurePredict *p1, CUniPressurePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CUniPressureOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pUniPressure	要被判断的单边市情况
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUniPressure *pUniPressure)
	{
		return m_p1->isValid(pUniPressure) || m_p2->isValid(pUniPressure);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureNotPredict是对一个单边市情况谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureNotPredict : public CUniPressurePredict
{
private:
	CUniPressurePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CUniPressureNotPredict(CUniPressurePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CUniPressureNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pUniPressure	要被判断的单边市情况
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CUniPressure *pUniPressure)
	{
		return !m_predict->isValid(pUniPressure);
	}
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureFilter是一个对已有的单边市情况枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureFilter: public CUniPressureIterator
{
private:
	CUniPressureIterator *m_baseIterator;
	CUniPressurePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CUniPressureFilter(CUniPressureIterator *pBaseIterator, CUniPressurePredict *pPredict, bool continueResult=false)
		:CUniPressureIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CUniPressureFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CUniPressure
	///@return	下一个满足条件CUniPressure，如果已经没有一个满足要求了，则返回NULL
	virtual CUniPressure *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUniPressure 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureLinkIterator是连接两个单边市情况枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureLinkIterator: public CUniPressureIterator
{
private:
	CUniPressureIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CUniPressureLinkIterator(CUniPressureIterator *pBaseIterator1,CUniPressureIterator *pBaseIterator2)
		:CUniPressureIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CUniPressureLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CUniPressure
	///@return	下一个满足条件CUniPressure，如果已经没有一个满足要求了，则返回NULL
	virtual CUniPressure *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pUniPressure 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitSingleIterator是至多返回一个涨跌停板设置的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitSingleIterator: public CBasePriceLimitIterator
{
private:
	CBasePriceLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CBasePriceLimitSingleIterator(CBasePriceLimitFactory *pFactory,CBasePriceLimit *pResult)
		:CBasePriceLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CBasePriceLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CBasePriceLimit
	///@return	下一个满足条件CBasePriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CBasePriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBasePriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitPredict是判断一个涨跌停板设置是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitPredict
{
public:
	///判断是否合法
	///@param	pBasePriceLimit	要被判断的涨跌停板设置
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitAndPredict是对两个涨跌停板设置谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitAndPredict : public CBasePriceLimitPredict
{
private:
	CBasePriceLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CBasePriceLimitAndPredict(CBasePriceLimitPredict *p1, CBasePriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CBasePriceLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pBasePriceLimit	要被判断的涨跌停板设置
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)
	{
		return m_p1->isValid(pBasePriceLimit) && m_p2->isValid(pBasePriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitOrPredict是对两个涨跌停板设置谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitOrPredict : public CBasePriceLimitPredict
{
private:
	CBasePriceLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CBasePriceLimitOrPredict(CBasePriceLimitPredict *p1, CBasePriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CBasePriceLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pBasePriceLimit	要被判断的涨跌停板设置
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)
	{
		return m_p1->isValid(pBasePriceLimit) || m_p2->isValid(pBasePriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitNotPredict是对一个涨跌停板设置谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitNotPredict : public CBasePriceLimitPredict
{
private:
	CBasePriceLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CBasePriceLimitNotPredict(CBasePriceLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CBasePriceLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pBasePriceLimit	要被判断的涨跌停板设置
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CBasePriceLimit *pBasePriceLimit)
	{
		return !m_predict->isValid(pBasePriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitFilter是一个对已有的涨跌停板设置枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitFilter: public CBasePriceLimitIterator
{
private:
	CBasePriceLimitIterator *m_baseIterator;
	CBasePriceLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CBasePriceLimitFilter(CBasePriceLimitIterator *pBaseIterator, CBasePriceLimitPredict *pPredict, bool continueResult=false)
		:CBasePriceLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CBasePriceLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CBasePriceLimit
	///@return	下一个满足条件CBasePriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CBasePriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBasePriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitLinkIterator是连接两个涨跌停板设置枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitLinkIterator: public CBasePriceLimitIterator
{
private:
	CBasePriceLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CBasePriceLimitLinkIterator(CBasePriceLimitIterator *pBaseIterator1,CBasePriceLimitIterator *pBaseIterator2)
		:CBasePriceLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CBasePriceLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CBasePriceLimit
	///@return	下一个满足条件CBasePriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CBasePriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pBasePriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCreditLimitSingleIterator是至多返回一个信用限额的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitSingleIterator: public CCreditLimitIterator
{
private:
	CCreditLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCreditLimitSingleIterator(CCreditLimitFactory *pFactory,CCreditLimit *pResult)
		:CCreditLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCreditLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCreditLimit
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCreditLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitPredict是判断一个信用限额是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitPredict
{
public:
	///判断是否合法
	///@param	pCreditLimit	要被判断的信用限额
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCreditLimit *pCreditLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitAndPredict是对两个信用限额谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitAndPredict : public CCreditLimitPredict
{
private:
	CCreditLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCreditLimitAndPredict(CCreditLimitPredict *p1, CCreditLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCreditLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCreditLimit	要被判断的信用限额
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCreditLimit *pCreditLimit)
	{
		return m_p1->isValid(pCreditLimit) && m_p2->isValid(pCreditLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitOrPredict是对两个信用限额谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitOrPredict : public CCreditLimitPredict
{
private:
	CCreditLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCreditLimitOrPredict(CCreditLimitPredict *p1, CCreditLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCreditLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCreditLimit	要被判断的信用限额
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCreditLimit *pCreditLimit)
	{
		return m_p1->isValid(pCreditLimit) || m_p2->isValid(pCreditLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitNotPredict是对一个信用限额谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitNotPredict : public CCreditLimitPredict
{
private:
	CCreditLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCreditLimitNotPredict(CCreditLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCreditLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCreditLimit	要被判断的信用限额
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCreditLimit *pCreditLimit)
	{
		return !m_predict->isValid(pCreditLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitFilter是一个对已有的信用限额枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitFilter: public CCreditLimitIterator
{
private:
	CCreditLimitIterator *m_baseIterator;
	CCreditLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCreditLimitFilter(CCreditLimitIterator *pBaseIterator, CCreditLimitPredict *pPredict, bool continueResult=false)
		:CCreditLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCreditLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCreditLimit
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCreditLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitLinkIterator是连接两个信用限额枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitLinkIterator: public CCreditLimitIterator
{
private:
	CCreditLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCreditLimitLinkIterator(CCreditLimitIterator *pBaseIterator1,CCreditLimitIterator *pBaseIterator2)
		:CCreditLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCreditLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCreditLimit
	///@return	下一个满足条件CCreditLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CCreditLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCreditLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionSingleIterator是至多返回一个当日期货合约期权属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionSingleIterator: public CCurrInstrumentOptionIterator
{
private:
	CCurrInstrumentOption *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CCurrInstrumentOptionSingleIterator(CCurrInstrumentOptionFactory *pFactory,CCurrInstrumentOption *pResult)
		:CCurrInstrumentOptionIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CCurrInstrumentOptionSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CCurrInstrumentOption
	///@return	下一个满足条件CCurrInstrumentOption，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentOption *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentOption 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionPredict是判断一个当日期货合约期权属性是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionPredict
{
public:
	///判断是否合法
	///@param	pCurrInstrumentOption	要被判断的当日期货合约期权属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionAndPredict是对两个当日期货合约期权属性谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionAndPredict : public CCurrInstrumentOptionPredict
{
private:
	CCurrInstrumentOptionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrInstrumentOptionAndPredict(CCurrInstrumentOptionPredict *p1, CCurrInstrumentOptionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrInstrumentOptionAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrInstrumentOption	要被判断的当日期货合约期权属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return m_p1->isValid(pCurrInstrumentOption) && m_p2->isValid(pCurrInstrumentOption);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionOrPredict是对两个当日期货合约期权属性谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionOrPredict : public CCurrInstrumentOptionPredict
{
private:
	CCurrInstrumentOptionPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CCurrInstrumentOptionOrPredict(CCurrInstrumentOptionPredict *p1, CCurrInstrumentOptionPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CCurrInstrumentOptionOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pCurrInstrumentOption	要被判断的当日期货合约期权属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return m_p1->isValid(pCurrInstrumentOption) || m_p2->isValid(pCurrInstrumentOption);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionNotPredict是对一个当日期货合约期权属性谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionNotPredict : public CCurrInstrumentOptionPredict
{
private:
	CCurrInstrumentOptionPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CCurrInstrumentOptionNotPredict(CCurrInstrumentOptionPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CCurrInstrumentOptionNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pCurrInstrumentOption	要被判断的当日期货合约期权属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return !m_predict->isValid(pCurrInstrumentOption);
	}
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionFilter是一个对已有的当日期货合约期权属性枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionFilter: public CCurrInstrumentOptionIterator
{
private:
	CCurrInstrumentOptionIterator *m_baseIterator;
	CCurrInstrumentOptionPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CCurrInstrumentOptionFilter(CCurrInstrumentOptionIterator *pBaseIterator, CCurrInstrumentOptionPredict *pPredict, bool continueResult=false)
		:CCurrInstrumentOptionIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CCurrInstrumentOptionFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CCurrInstrumentOption
	///@return	下一个满足条件CCurrInstrumentOption，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentOption *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentOption 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionLinkIterator是连接两个当日期货合约期权属性枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionLinkIterator: public CCurrInstrumentOptionIterator
{
private:
	CCurrInstrumentOptionIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CCurrInstrumentOptionLinkIterator(CCurrInstrumentOptionIterator *pBaseIterator1,CCurrInstrumentOptionIterator *pBaseIterator2)
		:CCurrInstrumentOptionIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CCurrInstrumentOptionLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CCurrInstrumentOption
	///@return	下一个满足条件CCurrInstrumentOption，如果已经没有一个满足要求了，则返回NULL
	virtual CCurrInstrumentOption *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pCurrInstrumentOption 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


#endif
