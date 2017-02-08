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
///CSysInvalidateOrderSingleIterator是至多返回一个无效报单的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderSingleIterator: public CSysInvalidateOrderIterator
{
private:
	CSysInvalidateOrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysInvalidateOrderSingleIterator(CSysInvalidateOrderFactory *pFactory,CSysInvalidateOrder *pResult)
		:CSysInvalidateOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysInvalidateOrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysInvalidateOrder
	///@return	下一个满足条件CSysInvalidateOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInvalidateOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInvalidateOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderPredict是判断一个无效报单是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderPredict
{
public:
	///判断是否合法
	///@param	pSysInvalidateOrder	要被判断的无效报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderAndPredict是对两个无效报单谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderAndPredict : public CSysInvalidateOrderPredict
{
private:
	CSysInvalidateOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysInvalidateOrderAndPredict(CSysInvalidateOrderPredict *p1, CSysInvalidateOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysInvalidateOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysInvalidateOrder	要被判断的无效报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return m_p1->isValid(pSysInvalidateOrder) && m_p2->isValid(pSysInvalidateOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderOrPredict是对两个无效报单谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderOrPredict : public CSysInvalidateOrderPredict
{
private:
	CSysInvalidateOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysInvalidateOrderOrPredict(CSysInvalidateOrderPredict *p1, CSysInvalidateOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysInvalidateOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysInvalidateOrder	要被判断的无效报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return m_p1->isValid(pSysInvalidateOrder) || m_p2->isValid(pSysInvalidateOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderNotPredict是对一个无效报单谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderNotPredict : public CSysInvalidateOrderPredict
{
private:
	CSysInvalidateOrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysInvalidateOrderNotPredict(CSysInvalidateOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysInvalidateOrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysInvalidateOrder	要被判断的无效报单
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return !m_predict->isValid(pSysInvalidateOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderFilter是一个对已有的无效报单枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderFilter: public CSysInvalidateOrderIterator
{
private:
	CSysInvalidateOrderIterator *m_baseIterator;
	CSysInvalidateOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysInvalidateOrderFilter(CSysInvalidateOrderIterator *pBaseIterator, CSysInvalidateOrderPredict *pPredict, bool continueResult=false)
		:CSysInvalidateOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysInvalidateOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysInvalidateOrder
	///@return	下一个满足条件CSysInvalidateOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInvalidateOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInvalidateOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderLinkIterator是连接两个无效报单枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderLinkIterator: public CSysInvalidateOrderIterator
{
private:
	CSysInvalidateOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysInvalidateOrderLinkIterator(CSysInvalidateOrderIterator *pBaseIterator1,CSysInvalidateOrderIterator *pBaseIterator2)
		:CSysInvalidateOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysInvalidateOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysInvalidateOrder
	///@return	下一个满足条件CSysInvalidateOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInvalidateOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInvalidateOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusSingleIterator是至多返回一个报单状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusSingleIterator: public CSysOrderStatusIterator
{
private:
	CSysOrderStatus *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysOrderStatusSingleIterator(CSysOrderStatusFactory *pFactory,CSysOrderStatus *pResult)
		:CSysOrderStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysOrderStatusSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysOrderStatus
	///@return	下一个满足条件CSysOrderStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOrderStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysOrderStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusPredict是判断一个报单状态是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusPredict
{
public:
	///判断是否合法
	///@param	pSysOrderStatus	要被判断的报单状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusAndPredict是对两个报单状态谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusAndPredict : public CSysOrderStatusPredict
{
private:
	CSysOrderStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysOrderStatusAndPredict(CSysOrderStatusPredict *p1, CSysOrderStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysOrderStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysOrderStatus	要被判断的报单状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)
	{
		return m_p1->isValid(pSysOrderStatus) && m_p2->isValid(pSysOrderStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusOrPredict是对两个报单状态谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusOrPredict : public CSysOrderStatusPredict
{
private:
	CSysOrderStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysOrderStatusOrPredict(CSysOrderStatusPredict *p1, CSysOrderStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysOrderStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysOrderStatus	要被判断的报单状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)
	{
		return m_p1->isValid(pSysOrderStatus) || m_p2->isValid(pSysOrderStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusNotPredict是对一个报单状态谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusNotPredict : public CSysOrderStatusPredict
{
private:
	CSysOrderStatusPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysOrderStatusNotPredict(CSysOrderStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysOrderStatusNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysOrderStatus	要被判断的报单状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOrderStatus *pSysOrderStatus)
	{
		return !m_predict->isValid(pSysOrderStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusFilter是一个对已有的报单状态枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusFilter: public CSysOrderStatusIterator
{
private:
	CSysOrderStatusIterator *m_baseIterator;
	CSysOrderStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysOrderStatusFilter(CSysOrderStatusIterator *pBaseIterator, CSysOrderStatusPredict *pPredict, bool continueResult=false)
		:CSysOrderStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysOrderStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysOrderStatus
	///@return	下一个满足条件CSysOrderStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOrderStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysOrderStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusLinkIterator是连接两个报单状态枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusLinkIterator: public CSysOrderStatusIterator
{
private:
	CSysOrderStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysOrderStatusLinkIterator(CSysOrderStatusIterator *pBaseIterator1,CSysOrderStatusIterator *pBaseIterator2)
		:CSysOrderStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysOrderStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysOrderStatus
	///@return	下一个满足条件CSysOrderStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOrderStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysOrderStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderSingleIterator是至多返回一个报单成交的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderSingleIterator: public CSysBargainOrderIterator
{
private:
	CSysBargainOrder *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysBargainOrderSingleIterator(CSysBargainOrderFactory *pFactory,CSysBargainOrder *pResult)
		:CSysBargainOrderIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysBargainOrderSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysBargainOrder
	///@return	下一个满足条件CSysBargainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysBargainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysBargainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderPredict是判断一个报单成交是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderPredict
{
public:
	///判断是否合法
	///@param	pSysBargainOrder	要被判断的报单成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderAndPredict是对两个报单成交谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderAndPredict : public CSysBargainOrderPredict
{
private:
	CSysBargainOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysBargainOrderAndPredict(CSysBargainOrderPredict *p1, CSysBargainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysBargainOrderAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysBargainOrder	要被判断的报单成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)
	{
		return m_p1->isValid(pSysBargainOrder) && m_p2->isValid(pSysBargainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderOrPredict是对两个报单成交谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderOrPredict : public CSysBargainOrderPredict
{
private:
	CSysBargainOrderPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysBargainOrderOrPredict(CSysBargainOrderPredict *p1, CSysBargainOrderPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysBargainOrderOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysBargainOrder	要被判断的报单成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)
	{
		return m_p1->isValid(pSysBargainOrder) || m_p2->isValid(pSysBargainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderNotPredict是对一个报单成交谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderNotPredict : public CSysBargainOrderPredict
{
private:
	CSysBargainOrderPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysBargainOrderNotPredict(CSysBargainOrderPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysBargainOrderNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysBargainOrder	要被判断的报单成交
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysBargainOrder *pSysBargainOrder)
	{
		return !m_predict->isValid(pSysBargainOrder);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderFilter是一个对已有的报单成交枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderFilter: public CSysBargainOrderIterator
{
private:
	CSysBargainOrderIterator *m_baseIterator;
	CSysBargainOrderPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysBargainOrderFilter(CSysBargainOrderIterator *pBaseIterator, CSysBargainOrderPredict *pPredict, bool continueResult=false)
		:CSysBargainOrderIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysBargainOrderFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysBargainOrder
	///@return	下一个满足条件CSysBargainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysBargainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysBargainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderLinkIterator是连接两个报单成交枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderLinkIterator: public CSysBargainOrderIterator
{
private:
	CSysBargainOrderIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysBargainOrderLinkIterator(CSysBargainOrderIterator *pBaseIterator1,CSysBargainOrderIterator *pBaseIterator2)
		:CSysBargainOrderIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysBargainOrderLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysBargainOrder
	///@return	下一个满足条件CSysBargainOrder，如果已经没有一个满足要求了，则返回NULL
	virtual CSysBargainOrder *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysBargainOrder 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysInstPropertySingleIterator是至多返回一个合约基本属性的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertySingleIterator: public CSysInstPropertyIterator
{
private:
	CSysInstProperty *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysInstPropertySingleIterator(CSysInstPropertyFactory *pFactory,CSysInstProperty *pResult)
		:CSysInstPropertyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysInstPropertySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysInstProperty
	///@return	下一个满足条件CSysInstProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyPredict是判断一个合约基本属性是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyPredict
{
public:
	///判断是否合法
	///@param	pSysInstProperty	要被判断的合约基本属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstProperty *pSysInstProperty)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyAndPredict是对两个合约基本属性谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyAndPredict : public CSysInstPropertyPredict
{
private:
	CSysInstPropertyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysInstPropertyAndPredict(CSysInstPropertyPredict *p1, CSysInstPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysInstPropertyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysInstProperty	要被判断的合约基本属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstProperty *pSysInstProperty)
	{
		return m_p1->isValid(pSysInstProperty) && m_p2->isValid(pSysInstProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyOrPredict是对两个合约基本属性谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyOrPredict : public CSysInstPropertyPredict
{
private:
	CSysInstPropertyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysInstPropertyOrPredict(CSysInstPropertyPredict *p1, CSysInstPropertyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysInstPropertyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysInstProperty	要被判断的合约基本属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstProperty *pSysInstProperty)
	{
		return m_p1->isValid(pSysInstProperty) || m_p2->isValid(pSysInstProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyNotPredict是对一个合约基本属性谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyNotPredict : public CSysInstPropertyPredict
{
private:
	CSysInstPropertyPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysInstPropertyNotPredict(CSysInstPropertyPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysInstPropertyNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysInstProperty	要被判断的合约基本属性
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstProperty *pSysInstProperty)
	{
		return !m_predict->isValid(pSysInstProperty);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyFilter是一个对已有的合约基本属性枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyFilter: public CSysInstPropertyIterator
{
private:
	CSysInstPropertyIterator *m_baseIterator;
	CSysInstPropertyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysInstPropertyFilter(CSysInstPropertyIterator *pBaseIterator, CSysInstPropertyPredict *pPredict, bool continueResult=false)
		:CSysInstPropertyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysInstPropertyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysInstProperty
	///@return	下一个满足条件CSysInstProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyLinkIterator是连接两个合约基本属性枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyLinkIterator: public CSysInstPropertyIterator
{
private:
	CSysInstPropertyIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysInstPropertyLinkIterator(CSysInstPropertyIterator *pBaseIterator1,CSysInstPropertyIterator *pBaseIterator2)
		:CSysInstPropertyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysInstPropertyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysInstProperty
	///@return	下一个满足条件CSysInstProperty，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstProperty *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstProperty 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMarginRateSingleIterator是至多返回一个合约保证金率的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateSingleIterator: public CSysMarginRateIterator
{
private:
	CSysMarginRate *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMarginRateSingleIterator(CSysMarginRateFactory *pFactory,CSysMarginRate *pResult)
		:CSysMarginRateIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMarginRateSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMarginRate
	///@return	下一个满足条件CSysMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRatePredict是判断一个合约保证金率是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRatePredict
{
public:
	///判断是否合法
	///@param	pSysMarginRate	要被判断的合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRate *pSysMarginRate)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateAndPredict是对两个合约保证金率谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateAndPredict : public CSysMarginRatePredict
{
private:
	CSysMarginRatePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMarginRateAndPredict(CSysMarginRatePredict *p1, CSysMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMarginRateAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMarginRate	要被判断的合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRate *pSysMarginRate)
	{
		return m_p1->isValid(pSysMarginRate) && m_p2->isValid(pSysMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateOrPredict是对两个合约保证金率谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateOrPredict : public CSysMarginRatePredict
{
private:
	CSysMarginRatePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMarginRateOrPredict(CSysMarginRatePredict *p1, CSysMarginRatePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMarginRateOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMarginRate	要被判断的合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRate *pSysMarginRate)
	{
		return m_p1->isValid(pSysMarginRate) || m_p2->isValid(pSysMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateNotPredict是对一个合约保证金率谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateNotPredict : public CSysMarginRatePredict
{
private:
	CSysMarginRatePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMarginRateNotPredict(CSysMarginRatePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMarginRateNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMarginRate	要被判断的合约保证金率
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRate *pSysMarginRate)
	{
		return !m_predict->isValid(pSysMarginRate);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateFilter是一个对已有的合约保证金率枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateFilter: public CSysMarginRateIterator
{
private:
	CSysMarginRateIterator *m_baseIterator;
	CSysMarginRatePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMarginRateFilter(CSysMarginRateIterator *pBaseIterator, CSysMarginRatePredict *pPredict, bool continueResult=false)
		:CSysMarginRateIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMarginRateFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMarginRate
	///@return	下一个满足条件CSysMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateLinkIterator是连接两个合约保证金率枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateLinkIterator: public CSysMarginRateIterator
{
private:
	CSysMarginRateIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMarginRateLinkIterator(CSysMarginRateIterator *pBaseIterator1,CSysMarginRateIterator *pBaseIterator2)
		:CSysMarginRateIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMarginRateLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMarginRate
	///@return	下一个满足条件CSysMarginRate，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRate *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRate 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitSingleIterator是至多返回一个合约涨跌停板的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitSingleIterator: public CSysPriceLimitIterator
{
private:
	CSysPriceLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysPriceLimitSingleIterator(CSysPriceLimitFactory *pFactory,CSysPriceLimit *pResult)
		:CSysPriceLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysPriceLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysPriceLimit
	///@return	下一个满足条件CSysPriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitPredict是判断一个合约涨跌停板是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitPredict
{
public:
	///判断是否合法
	///@param	pSysPriceLimit	要被判断的合约涨跌停板
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitAndPredict是对两个合约涨跌停板谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitAndPredict : public CSysPriceLimitPredict
{
private:
	CSysPriceLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPriceLimitAndPredict(CSysPriceLimitPredict *p1, CSysPriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPriceLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPriceLimit	要被判断的合约涨跌停板
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)
	{
		return m_p1->isValid(pSysPriceLimit) && m_p2->isValid(pSysPriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitOrPredict是对两个合约涨跌停板谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitOrPredict : public CSysPriceLimitPredict
{
private:
	CSysPriceLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPriceLimitOrPredict(CSysPriceLimitPredict *p1, CSysPriceLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPriceLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPriceLimit	要被判断的合约涨跌停板
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)
	{
		return m_p1->isValid(pSysPriceLimit) || m_p2->isValid(pSysPriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitNotPredict是对一个合约涨跌停板谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitNotPredict : public CSysPriceLimitPredict
{
private:
	CSysPriceLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysPriceLimitNotPredict(CSysPriceLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysPriceLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysPriceLimit	要被判断的合约涨跌停板
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPriceLimit *pSysPriceLimit)
	{
		return !m_predict->isValid(pSysPriceLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitFilter是一个对已有的合约涨跌停板枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitFilter: public CSysPriceLimitIterator
{
private:
	CSysPriceLimitIterator *m_baseIterator;
	CSysPriceLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysPriceLimitFilter(CSysPriceLimitIterator *pBaseIterator, CSysPriceLimitPredict *pPredict, bool continueResult=false)
		:CSysPriceLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysPriceLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysPriceLimit
	///@return	下一个满足条件CSysPriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitLinkIterator是连接两个合约涨跌停板枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitLinkIterator: public CSysPriceLimitIterator
{
private:
	CSysPriceLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysPriceLimitLinkIterator(CSysPriceLimitIterator *pBaseIterator1,CSysPriceLimitIterator *pBaseIterator2)
		:CSysPriceLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysPriceLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysPriceLimit
	///@return	下一个满足条件CSysPriceLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPriceLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPriceLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitSingleIterator是至多返回一个会员限仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitSingleIterator: public CSysPartPosiLimitIterator
{
private:
	CSysPartPosiLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysPartPosiLimitSingleIterator(CSysPartPosiLimitFactory *pFactory,CSysPartPosiLimit *pResult)
		:CSysPartPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysPartPosiLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysPartPosiLimit
	///@return	下一个满足条件CSysPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitPredict是判断一个会员限仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitPredict
{
public:
	///判断是否合法
	///@param	pSysPartPosiLimit	要被判断的会员限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitAndPredict是对两个会员限仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitAndPredict : public CSysPartPosiLimitPredict
{
private:
	CSysPartPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPartPosiLimitAndPredict(CSysPartPosiLimitPredict *p1, CSysPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPartPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPartPosiLimit	要被判断的会员限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return m_p1->isValid(pSysPartPosiLimit) && m_p2->isValid(pSysPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitOrPredict是对两个会员限仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitOrPredict : public CSysPartPosiLimitPredict
{
private:
	CSysPartPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPartPosiLimitOrPredict(CSysPartPosiLimitPredict *p1, CSysPartPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPartPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPartPosiLimit	要被判断的会员限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return m_p1->isValid(pSysPartPosiLimit) || m_p2->isValid(pSysPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitNotPredict是对一个会员限仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitNotPredict : public CSysPartPosiLimitPredict
{
private:
	CSysPartPosiLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysPartPosiLimitNotPredict(CSysPartPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysPartPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysPartPosiLimit	要被判断的会员限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return !m_predict->isValid(pSysPartPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitFilter是一个对已有的会员限仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitFilter: public CSysPartPosiLimitIterator
{
private:
	CSysPartPosiLimitIterator *m_baseIterator;
	CSysPartPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysPartPosiLimitFilter(CSysPartPosiLimitIterator *pBaseIterator, CSysPartPosiLimitPredict *pPredict, bool continueResult=false)
		:CSysPartPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysPartPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysPartPosiLimit
	///@return	下一个满足条件CSysPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitLinkIterator是连接两个会员限仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitLinkIterator: public CSysPartPosiLimitIterator
{
private:
	CSysPartPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysPartPosiLimitLinkIterator(CSysPartPosiLimitIterator *pBaseIterator1,CSysPartPosiLimitIterator *pBaseIterator2)
		:CSysPartPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysPartPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysPartPosiLimit
	///@return	下一个满足条件CSysPartPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitSingleIterator是至多返回一个客户限仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitSingleIterator: public CSysClientPosiLimitIterator
{
private:
	CSysClientPosiLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysClientPosiLimitSingleIterator(CSysClientPosiLimitFactory *pFactory,CSysClientPosiLimit *pResult)
		:CSysClientPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysClientPosiLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysClientPosiLimit
	///@return	下一个满足条件CSysClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitPredict是判断一个客户限仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitPredict
{
public:
	///判断是否合法
	///@param	pSysClientPosiLimit	要被判断的客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitAndPredict是对两个客户限仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitAndPredict : public CSysClientPosiLimitPredict
{
private:
	CSysClientPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientPosiLimitAndPredict(CSysClientPosiLimitPredict *p1, CSysClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientPosiLimit	要被判断的客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return m_p1->isValid(pSysClientPosiLimit) && m_p2->isValid(pSysClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitOrPredict是对两个客户限仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitOrPredict : public CSysClientPosiLimitPredict
{
private:
	CSysClientPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientPosiLimitOrPredict(CSysClientPosiLimitPredict *p1, CSysClientPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientPosiLimit	要被判断的客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return m_p1->isValid(pSysClientPosiLimit) || m_p2->isValid(pSysClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitNotPredict是对一个客户限仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitNotPredict : public CSysClientPosiLimitPredict
{
private:
	CSysClientPosiLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysClientPosiLimitNotPredict(CSysClientPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysClientPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysClientPosiLimit	要被判断的客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return !m_predict->isValid(pSysClientPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitFilter是一个对已有的客户限仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitFilter: public CSysClientPosiLimitIterator
{
private:
	CSysClientPosiLimitIterator *m_baseIterator;
	CSysClientPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysClientPosiLimitFilter(CSysClientPosiLimitIterator *pBaseIterator, CSysClientPosiLimitPredict *pPredict, bool continueResult=false)
		:CSysClientPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysClientPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysClientPosiLimit
	///@return	下一个满足条件CSysClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitLinkIterator是连接两个客户限仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitLinkIterator: public CSysClientPosiLimitIterator
{
private:
	CSysClientPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysClientPosiLimitLinkIterator(CSysClientPosiLimitIterator *pBaseIterator1,CSysClientPosiLimitIterator *pBaseIterator2)
		:CSysClientPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysClientPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysClientPosiLimit
	///@return	下一个满足条件CSysClientPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitSingleIterator是至多返回一个特殊客户限仓的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitSingleIterator: public CSysSpecialPosiLimitIterator
{
private:
	CSysSpecialPosiLimit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysSpecialPosiLimitSingleIterator(CSysSpecialPosiLimitFactory *pFactory,CSysSpecialPosiLimit *pResult)
		:CSysSpecialPosiLimitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysSpecialPosiLimitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysSpecialPosiLimit
	///@return	下一个满足条件CSysSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitPredict是判断一个特殊客户限仓是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitPredict
{
public:
	///判断是否合法
	///@param	pSysSpecialPosiLimit	要被判断的特殊客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitAndPredict是对两个特殊客户限仓谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitAndPredict : public CSysSpecialPosiLimitPredict
{
private:
	CSysSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysSpecialPosiLimitAndPredict(CSysSpecialPosiLimitPredict *p1, CSysSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysSpecialPosiLimitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysSpecialPosiLimit	要被判断的特殊客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return m_p1->isValid(pSysSpecialPosiLimit) && m_p2->isValid(pSysSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitOrPredict是对两个特殊客户限仓谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitOrPredict : public CSysSpecialPosiLimitPredict
{
private:
	CSysSpecialPosiLimitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysSpecialPosiLimitOrPredict(CSysSpecialPosiLimitPredict *p1, CSysSpecialPosiLimitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysSpecialPosiLimitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysSpecialPosiLimit	要被判断的特殊客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return m_p1->isValid(pSysSpecialPosiLimit) || m_p2->isValid(pSysSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitNotPredict是对一个特殊客户限仓谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitNotPredict : public CSysSpecialPosiLimitPredict
{
private:
	CSysSpecialPosiLimitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysSpecialPosiLimitNotPredict(CSysSpecialPosiLimitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysSpecialPosiLimitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysSpecialPosiLimit	要被判断的特殊客户限仓
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return !m_predict->isValid(pSysSpecialPosiLimit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitFilter是一个对已有的特殊客户限仓枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitFilter: public CSysSpecialPosiLimitIterator
{
private:
	CSysSpecialPosiLimitIterator *m_baseIterator;
	CSysSpecialPosiLimitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysSpecialPosiLimitFilter(CSysSpecialPosiLimitIterator *pBaseIterator, CSysSpecialPosiLimitPredict *pPredict, bool continueResult=false)
		:CSysSpecialPosiLimitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysSpecialPosiLimitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysSpecialPosiLimit
	///@return	下一个满足条件CSysSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitLinkIterator是连接两个特殊客户限仓枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitLinkIterator: public CSysSpecialPosiLimitIterator
{
private:
	CSysSpecialPosiLimitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysSpecialPosiLimitLinkIterator(CSysSpecialPosiLimitIterator *pBaseIterator1,CSysSpecialPosiLimitIterator *pBaseIterator2)
		:CSysSpecialPosiLimitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysSpecialPosiLimitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysSpecialPosiLimit
	///@return	下一个满足条件CSysSpecialPosiLimit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecialPosiLimit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecialPosiLimit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgSingleIterator是至多返回一个账户出入金查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgSingleIterator: public CSysTransactionChgIterator
{
private:
	CSysTransactionChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysTransactionChgSingleIterator(CSysTransactionChgFactory *pFactory,CSysTransactionChg *pResult)
		:CSysTransactionChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysTransactionChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysTransactionChg
	///@return	下一个满足条件CSysTransactionChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTransactionChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysTransactionChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgPredict是判断一个账户出入金查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgPredict
{
public:
	///判断是否合法
	///@param	pSysTransactionChg	要被判断的账户出入金查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgAndPredict是对两个账户出入金查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgAndPredict : public CSysTransactionChgPredict
{
private:
	CSysTransactionChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysTransactionChgAndPredict(CSysTransactionChgPredict *p1, CSysTransactionChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysTransactionChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysTransactionChg	要被判断的账户出入金查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)
	{
		return m_p1->isValid(pSysTransactionChg) && m_p2->isValid(pSysTransactionChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgOrPredict是对两个账户出入金查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgOrPredict : public CSysTransactionChgPredict
{
private:
	CSysTransactionChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysTransactionChgOrPredict(CSysTransactionChgPredict *p1, CSysTransactionChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysTransactionChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysTransactionChg	要被判断的账户出入金查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)
	{
		return m_p1->isValid(pSysTransactionChg) || m_p2->isValid(pSysTransactionChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgNotPredict是对一个账户出入金查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgNotPredict : public CSysTransactionChgPredict
{
private:
	CSysTransactionChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysTransactionChgNotPredict(CSysTransactionChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysTransactionChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysTransactionChg	要被判断的账户出入金查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTransactionChg *pSysTransactionChg)
	{
		return !m_predict->isValid(pSysTransactionChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgFilter是一个对已有的账户出入金查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgFilter: public CSysTransactionChgIterator
{
private:
	CSysTransactionChgIterator *m_baseIterator;
	CSysTransactionChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysTransactionChgFilter(CSysTransactionChgIterator *pBaseIterator, CSysTransactionChgPredict *pPredict, bool continueResult=false)
		:CSysTransactionChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysTransactionChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysTransactionChg
	///@return	下一个满足条件CSysTransactionChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTransactionChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysTransactionChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgLinkIterator是连接两个账户出入金查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgLinkIterator: public CSysTransactionChgIterator
{
private:
	CSysTransactionChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysTransactionChgLinkIterator(CSysTransactionChgIterator *pBaseIterator1,CSysTransactionChgIterator *pBaseIterator2)
		:CSysTransactionChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysTransactionChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysTransactionChg
	///@return	下一个满足条件CSysTransactionChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTransactionChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysTransactionChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientChgSingleIterator是至多返回一个客户数据变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgSingleIterator: public CSysClientChgIterator
{
private:
	CSysClientChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysClientChgSingleIterator(CSysClientChgFactory *pFactory,CSysClientChg *pResult)
		:CSysClientChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysClientChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysClientChg
	///@return	下一个满足条件CSysClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgPredict是判断一个客户数据变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgPredict
{
public:
	///判断是否合法
	///@param	pSysClientChg	要被判断的客户数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientChg *pSysClientChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgAndPredict是对两个客户数据变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgAndPredict : public CSysClientChgPredict
{
private:
	CSysClientChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientChgAndPredict(CSysClientChgPredict *p1, CSysClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientChg	要被判断的客户数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientChg *pSysClientChg)
	{
		return m_p1->isValid(pSysClientChg) && m_p2->isValid(pSysClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgOrPredict是对两个客户数据变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgOrPredict : public CSysClientChgPredict
{
private:
	CSysClientChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientChgOrPredict(CSysClientChgPredict *p1, CSysClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientChg	要被判断的客户数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientChg *pSysClientChg)
	{
		return m_p1->isValid(pSysClientChg) || m_p2->isValid(pSysClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgNotPredict是对一个客户数据变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgNotPredict : public CSysClientChgPredict
{
private:
	CSysClientChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysClientChgNotPredict(CSysClientChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysClientChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysClientChg	要被判断的客户数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientChg *pSysClientChg)
	{
		return !m_predict->isValid(pSysClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgFilter是一个对已有的客户数据变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgFilter: public CSysClientChgIterator
{
private:
	CSysClientChgIterator *m_baseIterator;
	CSysClientChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysClientChgFilter(CSysClientChgIterator *pBaseIterator, CSysClientChgPredict *pPredict, bool continueResult=false)
		:CSysClientChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysClientChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysClientChg
	///@return	下一个满足条件CSysClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgLinkIterator是连接两个客户数据变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgLinkIterator: public CSysClientChgIterator
{
private:
	CSysClientChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysClientChgLinkIterator(CSysClientChgIterator *pBaseIterator1,CSysClientChgIterator *pBaseIterator2)
		:CSysClientChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysClientChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysClientChg
	///@return	下一个满足条件CSysClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgSingleIterator是至多返回一个会员客户对照变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgSingleIterator: public CSysPartClientChgIterator
{
private:
	CSysPartClientChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysPartClientChgSingleIterator(CSysPartClientChgFactory *pFactory,CSysPartClientChg *pResult)
		:CSysPartClientChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysPartClientChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysPartClientChg
	///@return	下一个满足条件CSysPartClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgPredict是判断一个会员客户对照变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgPredict
{
public:
	///判断是否合法
	///@param	pSysPartClientChg	要被判断的会员客户对照变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgAndPredict是对两个会员客户对照变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgAndPredict : public CSysPartClientChgPredict
{
private:
	CSysPartClientChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPartClientChgAndPredict(CSysPartClientChgPredict *p1, CSysPartClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPartClientChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPartClientChg	要被判断的会员客户对照变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)
	{
		return m_p1->isValid(pSysPartClientChg) && m_p2->isValid(pSysPartClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgOrPredict是对两个会员客户对照变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgOrPredict : public CSysPartClientChgPredict
{
private:
	CSysPartClientChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPartClientChgOrPredict(CSysPartClientChgPredict *p1, CSysPartClientChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPartClientChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPartClientChg	要被判断的会员客户对照变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)
	{
		return m_p1->isValid(pSysPartClientChg) || m_p2->isValid(pSysPartClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgNotPredict是对一个会员客户对照变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgNotPredict : public CSysPartClientChgPredict
{
private:
	CSysPartClientChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysPartClientChgNotPredict(CSysPartClientChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysPartClientChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysPartClientChg	要被判断的会员客户对照变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartClientChg *pSysPartClientChg)
	{
		return !m_predict->isValid(pSysPartClientChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgFilter是一个对已有的会员客户对照变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgFilter: public CSysPartClientChgIterator
{
private:
	CSysPartClientChgIterator *m_baseIterator;
	CSysPartClientChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysPartClientChgFilter(CSysPartClientChgIterator *pBaseIterator, CSysPartClientChgPredict *pPredict, bool continueResult=false)
		:CSysPartClientChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysPartClientChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysPartClientChg
	///@return	下一个满足条件CSysPartClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgLinkIterator是连接两个会员客户对照变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgLinkIterator: public CSysPartClientChgIterator
{
private:
	CSysPartClientChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysPartClientChgLinkIterator(CSysPartClientChgIterator *pBaseIterator1,CSysPartClientChgIterator *pBaseIterator2)
		:CSysPartClientChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysPartClientChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysPartClientChg
	///@return	下一个满足条件CSysPartClientChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartClientChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartClientChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgSingleIterator是至多返回一个限仓数据变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgSingleIterator: public CSysPosiLimitChgIterator
{
private:
	CSysPosiLimitChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysPosiLimitChgSingleIterator(CSysPosiLimitChgFactory *pFactory,CSysPosiLimitChg *pResult)
		:CSysPosiLimitChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysPosiLimitChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysPosiLimitChg
	///@return	下一个满足条件CSysPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgPredict是判断一个限仓数据变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgPredict
{
public:
	///判断是否合法
	///@param	pSysPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgAndPredict是对两个限仓数据变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgAndPredict : public CSysPosiLimitChgPredict
{
private:
	CSysPosiLimitChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPosiLimitChgAndPredict(CSysPosiLimitChgPredict *p1, CSysPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPosiLimitChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return m_p1->isValid(pSysPosiLimitChg) && m_p2->isValid(pSysPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgOrPredict是对两个限仓数据变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgOrPredict : public CSysPosiLimitChgPredict
{
private:
	CSysPosiLimitChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPosiLimitChgOrPredict(CSysPosiLimitChgPredict *p1, CSysPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPosiLimitChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return m_p1->isValid(pSysPosiLimitChg) || m_p2->isValid(pSysPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgNotPredict是对一个限仓数据变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgNotPredict : public CSysPosiLimitChgPredict
{
private:
	CSysPosiLimitChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysPosiLimitChgNotPredict(CSysPosiLimitChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysPosiLimitChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return !m_predict->isValid(pSysPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgFilter是一个对已有的限仓数据变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgFilter: public CSysPosiLimitChgIterator
{
private:
	CSysPosiLimitChgIterator *m_baseIterator;
	CSysPosiLimitChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysPosiLimitChgFilter(CSysPosiLimitChgIterator *pBaseIterator, CSysPosiLimitChgPredict *pPredict, bool continueResult=false)
		:CSysPosiLimitChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysPosiLimitChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysPosiLimitChg
	///@return	下一个满足条件CSysPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgLinkIterator是连接两个限仓数据变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgLinkIterator: public CSysPosiLimitChgIterator
{
private:
	CSysPosiLimitChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysPosiLimitChgLinkIterator(CSysPosiLimitChgIterator *pBaseIterator1,CSysPosiLimitChgIterator *pBaseIterator2)
		:CSysPosiLimitChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysPosiLimitChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysPosiLimitChg
	///@return	下一个满足条件CSysPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgSingleIterator是至多返回一个限仓数据变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgSingleIterator: public CSysClientPosiLimitChgIterator
{
private:
	CSysClientPosiLimitChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysClientPosiLimitChgSingleIterator(CSysClientPosiLimitChgFactory *pFactory,CSysClientPosiLimitChg *pResult)
		:CSysClientPosiLimitChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysClientPosiLimitChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysClientPosiLimitChg
	///@return	下一个满足条件CSysClientPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgPredict是判断一个限仓数据变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgPredict
{
public:
	///判断是否合法
	///@param	pSysClientPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgAndPredict是对两个限仓数据变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgAndPredict : public CSysClientPosiLimitChgPredict
{
private:
	CSysClientPosiLimitChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientPosiLimitChgAndPredict(CSysClientPosiLimitChgPredict *p1, CSysClientPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientPosiLimitChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return m_p1->isValid(pSysClientPosiLimitChg) && m_p2->isValid(pSysClientPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgOrPredict是对两个限仓数据变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgOrPredict : public CSysClientPosiLimitChgPredict
{
private:
	CSysClientPosiLimitChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientPosiLimitChgOrPredict(CSysClientPosiLimitChgPredict *p1, CSysClientPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientPosiLimitChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return m_p1->isValid(pSysClientPosiLimitChg) || m_p2->isValid(pSysClientPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgNotPredict是对一个限仓数据变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgNotPredict : public CSysClientPosiLimitChgPredict
{
private:
	CSysClientPosiLimitChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysClientPosiLimitChgNotPredict(CSysClientPosiLimitChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysClientPosiLimitChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysClientPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return !m_predict->isValid(pSysClientPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgFilter是一个对已有的限仓数据变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgFilter: public CSysClientPosiLimitChgIterator
{
private:
	CSysClientPosiLimitChgIterator *m_baseIterator;
	CSysClientPosiLimitChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysClientPosiLimitChgFilter(CSysClientPosiLimitChgIterator *pBaseIterator, CSysClientPosiLimitChgPredict *pPredict, bool continueResult=false)
		:CSysClientPosiLimitChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysClientPosiLimitChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysClientPosiLimitChg
	///@return	下一个满足条件CSysClientPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgLinkIterator是连接两个限仓数据变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgLinkIterator: public CSysClientPosiLimitChgIterator
{
private:
	CSysClientPosiLimitChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysClientPosiLimitChgLinkIterator(CSysClientPosiLimitChgIterator *pBaseIterator1,CSysClientPosiLimitChgIterator *pBaseIterator2)
		:CSysClientPosiLimitChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysClientPosiLimitChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysClientPosiLimitChg
	///@return	下一个满足条件CSysClientPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgSingleIterator是至多返回一个限仓数据变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgSingleIterator: public CSysSpecPosiLimitChgIterator
{
private:
	CSysSpecPosiLimitChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysSpecPosiLimitChgSingleIterator(CSysSpecPosiLimitChgFactory *pFactory,CSysSpecPosiLimitChg *pResult)
		:CSysSpecPosiLimitChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysSpecPosiLimitChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysSpecPosiLimitChg
	///@return	下一个满足条件CSysSpecPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgPredict是判断一个限仓数据变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgPredict
{
public:
	///判断是否合法
	///@param	pSysSpecPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgAndPredict是对两个限仓数据变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgAndPredict : public CSysSpecPosiLimitChgPredict
{
private:
	CSysSpecPosiLimitChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysSpecPosiLimitChgAndPredict(CSysSpecPosiLimitChgPredict *p1, CSysSpecPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysSpecPosiLimitChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysSpecPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return m_p1->isValid(pSysSpecPosiLimitChg) && m_p2->isValid(pSysSpecPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgOrPredict是对两个限仓数据变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgOrPredict : public CSysSpecPosiLimitChgPredict
{
private:
	CSysSpecPosiLimitChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysSpecPosiLimitChgOrPredict(CSysSpecPosiLimitChgPredict *p1, CSysSpecPosiLimitChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysSpecPosiLimitChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysSpecPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return m_p1->isValid(pSysSpecPosiLimitChg) || m_p2->isValid(pSysSpecPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgNotPredict是对一个限仓数据变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgNotPredict : public CSysSpecPosiLimitChgPredict
{
private:
	CSysSpecPosiLimitChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysSpecPosiLimitChgNotPredict(CSysSpecPosiLimitChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysSpecPosiLimitChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysSpecPosiLimitChg	要被判断的限仓数据变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return !m_predict->isValid(pSysSpecPosiLimitChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgFilter是一个对已有的限仓数据变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgFilter: public CSysSpecPosiLimitChgIterator
{
private:
	CSysSpecPosiLimitChgIterator *m_baseIterator;
	CSysSpecPosiLimitChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysSpecPosiLimitChgFilter(CSysSpecPosiLimitChgIterator *pBaseIterator, CSysSpecPosiLimitChgPredict *pPredict, bool continueResult=false)
		:CSysSpecPosiLimitChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysSpecPosiLimitChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysSpecPosiLimitChg
	///@return	下一个满足条件CSysSpecPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgLinkIterator是连接两个限仓数据变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgLinkIterator: public CSysSpecPosiLimitChgIterator
{
private:
	CSysSpecPosiLimitChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysSpecPosiLimitChgLinkIterator(CSysSpecPosiLimitChgIterator *pBaseIterator1,CSysSpecPosiLimitChgIterator *pBaseIterator2)
		:CSysSpecPosiLimitChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysSpecPosiLimitChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysSpecPosiLimitChg
	///@return	下一个满足条件CSysSpecPosiLimitChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysSpecPosiLimitChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysSpecPosiLimitChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgSingleIterator是至多返回一个保值额度变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgSingleIterator: public CSysHedgeDetailChgIterator
{
private:
	CSysHedgeDetailChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysHedgeDetailChgSingleIterator(CSysHedgeDetailChgFactory *pFactory,CSysHedgeDetailChg *pResult)
		:CSysHedgeDetailChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysHedgeDetailChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysHedgeDetailChg
	///@return	下一个满足条件CSysHedgeDetailChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysHedgeDetailChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgPredict是判断一个保值额度变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgPredict
{
public:
	///判断是否合法
	///@param	pSysHedgeDetailChg	要被判断的保值额度变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgAndPredict是对两个保值额度变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgAndPredict : public CSysHedgeDetailChgPredict
{
private:
	CSysHedgeDetailChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysHedgeDetailChgAndPredict(CSysHedgeDetailChgPredict *p1, CSysHedgeDetailChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysHedgeDetailChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysHedgeDetailChg	要被判断的保值额度变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return m_p1->isValid(pSysHedgeDetailChg) && m_p2->isValid(pSysHedgeDetailChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgOrPredict是对两个保值额度变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgOrPredict : public CSysHedgeDetailChgPredict
{
private:
	CSysHedgeDetailChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysHedgeDetailChgOrPredict(CSysHedgeDetailChgPredict *p1, CSysHedgeDetailChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysHedgeDetailChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysHedgeDetailChg	要被判断的保值额度变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return m_p1->isValid(pSysHedgeDetailChg) || m_p2->isValid(pSysHedgeDetailChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgNotPredict是对一个保值额度变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgNotPredict : public CSysHedgeDetailChgPredict
{
private:
	CSysHedgeDetailChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysHedgeDetailChgNotPredict(CSysHedgeDetailChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysHedgeDetailChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysHedgeDetailChg	要被判断的保值额度变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return !m_predict->isValid(pSysHedgeDetailChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgFilter是一个对已有的保值额度变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgFilter: public CSysHedgeDetailChgIterator
{
private:
	CSysHedgeDetailChgIterator *m_baseIterator;
	CSysHedgeDetailChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysHedgeDetailChgFilter(CSysHedgeDetailChgIterator *pBaseIterator, CSysHedgeDetailChgPredict *pPredict, bool continueResult=false)
		:CSysHedgeDetailChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysHedgeDetailChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysHedgeDetailChg
	///@return	下一个满足条件CSysHedgeDetailChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysHedgeDetailChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgLinkIterator是连接两个保值额度变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgLinkIterator: public CSysHedgeDetailChgIterator
{
private:
	CSysHedgeDetailChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysHedgeDetailChgLinkIterator(CSysHedgeDetailChgIterator *pBaseIterator1,CSysHedgeDetailChgIterator *pBaseIterator2)
		:CSysHedgeDetailChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysHedgeDetailChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysHedgeDetailChg
	///@return	下一个满足条件CSysHedgeDetailChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysHedgeDetailChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysHedgeDetailChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgSingleIterator是至多返回一个会员变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgSingleIterator: public CSysParticipantChgIterator
{
private:
	CSysParticipantChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysParticipantChgSingleIterator(CSysParticipantChgFactory *pFactory,CSysParticipantChg *pResult)
		:CSysParticipantChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysParticipantChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysParticipantChg
	///@return	下一个满足条件CSysParticipantChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgPredict是判断一个会员变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgPredict
{
public:
	///判断是否合法
	///@param	pSysParticipantChg	要被判断的会员变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgAndPredict是对两个会员变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgAndPredict : public CSysParticipantChgPredict
{
private:
	CSysParticipantChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysParticipantChgAndPredict(CSysParticipantChgPredict *p1, CSysParticipantChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysParticipantChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysParticipantChg	要被判断的会员变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)
	{
		return m_p1->isValid(pSysParticipantChg) && m_p2->isValid(pSysParticipantChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgOrPredict是对两个会员变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgOrPredict : public CSysParticipantChgPredict
{
private:
	CSysParticipantChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysParticipantChgOrPredict(CSysParticipantChgPredict *p1, CSysParticipantChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysParticipantChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysParticipantChg	要被判断的会员变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)
	{
		return m_p1->isValid(pSysParticipantChg) || m_p2->isValid(pSysParticipantChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgNotPredict是对一个会员变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgNotPredict : public CSysParticipantChgPredict
{
private:
	CSysParticipantChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysParticipantChgNotPredict(CSysParticipantChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysParticipantChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysParticipantChg	要被判断的会员变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantChg *pSysParticipantChg)
	{
		return !m_predict->isValid(pSysParticipantChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgFilter是一个对已有的会员变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgFilter: public CSysParticipantChgIterator
{
private:
	CSysParticipantChgIterator *m_baseIterator;
	CSysParticipantChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysParticipantChgFilter(CSysParticipantChgIterator *pBaseIterator, CSysParticipantChgPredict *pPredict, bool continueResult=false)
		:CSysParticipantChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysParticipantChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysParticipantChg
	///@return	下一个满足条件CSysParticipantChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgLinkIterator是连接两个会员变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgLinkIterator: public CSysParticipantChgIterator
{
private:
	CSysParticipantChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysParticipantChgLinkIterator(CSysParticipantChgIterator *pBaseIterator1,CSysParticipantChgIterator *pBaseIterator2)
		:CSysParticipantChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysParticipantChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysParticipantChg
	///@return	下一个满足条件CSysParticipantChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgSingleIterator是至多返回一个保证金率变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgSingleIterator: public CSysMarginRateChgIterator
{
private:
	CSysMarginRateChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMarginRateChgSingleIterator(CSysMarginRateChgFactory *pFactory,CSysMarginRateChg *pResult)
		:CSysMarginRateChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMarginRateChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMarginRateChg
	///@return	下一个满足条件CSysMarginRateChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRateChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRateChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgPredict是判断一个保证金率变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgPredict
{
public:
	///判断是否合法
	///@param	pSysMarginRateChg	要被判断的保证金率变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgAndPredict是对两个保证金率变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgAndPredict : public CSysMarginRateChgPredict
{
private:
	CSysMarginRateChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMarginRateChgAndPredict(CSysMarginRateChgPredict *p1, CSysMarginRateChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMarginRateChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMarginRateChg	要被判断的保证金率变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)
	{
		return m_p1->isValid(pSysMarginRateChg) && m_p2->isValid(pSysMarginRateChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgOrPredict是对两个保证金率变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgOrPredict : public CSysMarginRateChgPredict
{
private:
	CSysMarginRateChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMarginRateChgOrPredict(CSysMarginRateChgPredict *p1, CSysMarginRateChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMarginRateChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMarginRateChg	要被判断的保证金率变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)
	{
		return m_p1->isValid(pSysMarginRateChg) || m_p2->isValid(pSysMarginRateChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgNotPredict是对一个保证金率变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgNotPredict : public CSysMarginRateChgPredict
{
private:
	CSysMarginRateChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMarginRateChgNotPredict(CSysMarginRateChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMarginRateChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMarginRateChg	要被判断的保证金率变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMarginRateChg *pSysMarginRateChg)
	{
		return !m_predict->isValid(pSysMarginRateChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgFilter是一个对已有的保证金率变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgFilter: public CSysMarginRateChgIterator
{
private:
	CSysMarginRateChgIterator *m_baseIterator;
	CSysMarginRateChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMarginRateChgFilter(CSysMarginRateChgIterator *pBaseIterator, CSysMarginRateChgPredict *pPredict, bool continueResult=false)
		:CSysMarginRateChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMarginRateChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMarginRateChg
	///@return	下一个满足条件CSysMarginRateChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRateChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRateChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgLinkIterator是连接两个保证金率变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgLinkIterator: public CSysMarginRateChgIterator
{
private:
	CSysMarginRateChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMarginRateChgLinkIterator(CSysMarginRateChgIterator *pBaseIterator1,CSysMarginRateChgIterator *pBaseIterator2)
		:CSysMarginRateChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMarginRateChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMarginRateChg
	///@return	下一个满足条件CSysMarginRateChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMarginRateChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMarginRateChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgSingleIterator是至多返回一个IP地址变动查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgSingleIterator: public CSysUserIpChgIterator
{
private:
	CSysUserIpChg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysUserIpChgSingleIterator(CSysUserIpChgFactory *pFactory,CSysUserIpChg *pResult)
		:CSysUserIpChgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysUserIpChgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysUserIpChg
	///@return	下一个满足条件CSysUserIpChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserIpChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserIpChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgPredict是判断一个IP地址变动查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgPredict
{
public:
	///判断是否合法
	///@param	pSysUserIpChg	要被判断的IP地址变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgAndPredict是对两个IP地址变动查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgAndPredict : public CSysUserIpChgPredict
{
private:
	CSysUserIpChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysUserIpChgAndPredict(CSysUserIpChgPredict *p1, CSysUserIpChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysUserIpChgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysUserIpChg	要被判断的IP地址变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)
	{
		return m_p1->isValid(pSysUserIpChg) && m_p2->isValid(pSysUserIpChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgOrPredict是对两个IP地址变动查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgOrPredict : public CSysUserIpChgPredict
{
private:
	CSysUserIpChgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysUserIpChgOrPredict(CSysUserIpChgPredict *p1, CSysUserIpChgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysUserIpChgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysUserIpChg	要被判断的IP地址变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)
	{
		return m_p1->isValid(pSysUserIpChg) || m_p2->isValid(pSysUserIpChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgNotPredict是对一个IP地址变动查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgNotPredict : public CSysUserIpChgPredict
{
private:
	CSysUserIpChgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysUserIpChgNotPredict(CSysUserIpChgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysUserIpChgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysUserIpChg	要被判断的IP地址变动查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserIpChg *pSysUserIpChg)
	{
		return !m_predict->isValid(pSysUserIpChg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgFilter是一个对已有的IP地址变动查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgFilter: public CSysUserIpChgIterator
{
private:
	CSysUserIpChgIterator *m_baseIterator;
	CSysUserIpChgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysUserIpChgFilter(CSysUserIpChgIterator *pBaseIterator, CSysUserIpChgPredict *pPredict, bool continueResult=false)
		:CSysUserIpChgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysUserIpChgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysUserIpChg
	///@return	下一个满足条件CSysUserIpChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserIpChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserIpChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgLinkIterator是连接两个IP地址变动查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgLinkIterator: public CSysUserIpChgIterator
{
private:
	CSysUserIpChgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysUserIpChgLinkIterator(CSysUserIpChgIterator *pBaseIterator1,CSysUserIpChgIterator *pBaseIterator2)
		:CSysUserIpChgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysUserIpChgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysUserIpChg
	///@return	下一个满足条件CSysUserIpChg，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserIpChg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserIpChg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysPartTradeSingleIterator是至多返回一个会员交易信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeSingleIterator: public CSysPartTradeIterator
{
private:
	CSysPartTrade *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysPartTradeSingleIterator(CSysPartTradeFactory *pFactory,CSysPartTrade *pResult)
		:CSysPartTradeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysPartTradeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysPartTrade
	///@return	下一个满足条件CSysPartTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradePredict是判断一个会员交易信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradePredict
{
public:
	///判断是否合法
	///@param	pSysPartTrade	要被判断的会员交易信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartTrade *pSysPartTrade)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeAndPredict是对两个会员交易信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeAndPredict : public CSysPartTradePredict
{
private:
	CSysPartTradePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPartTradeAndPredict(CSysPartTradePredict *p1, CSysPartTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPartTradeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPartTrade	要被判断的会员交易信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartTrade *pSysPartTrade)
	{
		return m_p1->isValid(pSysPartTrade) && m_p2->isValid(pSysPartTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeOrPredict是对两个会员交易信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeOrPredict : public CSysPartTradePredict
{
private:
	CSysPartTradePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysPartTradeOrPredict(CSysPartTradePredict *p1, CSysPartTradePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysPartTradeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysPartTrade	要被判断的会员交易信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartTrade *pSysPartTrade)
	{
		return m_p1->isValid(pSysPartTrade) || m_p2->isValid(pSysPartTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeNotPredict是对一个会员交易信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeNotPredict : public CSysPartTradePredict
{
private:
	CSysPartTradePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysPartTradeNotPredict(CSysPartTradePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysPartTradeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysPartTrade	要被判断的会员交易信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysPartTrade *pSysPartTrade)
	{
		return !m_predict->isValid(pSysPartTrade);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeFilter是一个对已有的会员交易信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeFilter: public CSysPartTradeIterator
{
private:
	CSysPartTradeIterator *m_baseIterator;
	CSysPartTradePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysPartTradeFilter(CSysPartTradeIterator *pBaseIterator, CSysPartTradePredict *pPredict, bool continueResult=false)
		:CSysPartTradeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysPartTradeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysPartTrade
	///@return	下一个满足条件CSysPartTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeLinkIterator是连接两个会员交易信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeLinkIterator: public CSysPartTradeIterator
{
private:
	CSysPartTradeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysPartTradeLinkIterator(CSysPartTradeIterator *pBaseIterator1,CSysPartTradeIterator *pBaseIterator2)
		:CSysPartTradeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysPartTradeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysPartTrade
	///@return	下一个满足条件CSysPartTrade，如果已经没有一个满足要求了，则返回NULL
	virtual CSysPartTrade *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysPartTrade 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrSingleIterator是至多返回一个对象状态指标的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrSingleIterator: public CSysMdbObjectAttrIterator
{
private:
	CSysMdbObjectAttr *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbObjectAttrSingleIterator(CSysMdbObjectAttrFactory *pFactory,CSysMdbObjectAttr *pResult)
		:CSysMdbObjectAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbObjectAttrSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbObjectAttr
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbObjectAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrPredict是判断一个对象状态指标是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrPredict
{
public:
	///判断是否合法
	///@param	pSysMdbObjectAttr	要被判断的对象状态指标
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrAndPredict是对两个对象状态指标谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrAndPredict : public CSysMdbObjectAttrPredict
{
private:
	CSysMdbObjectAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbObjectAttrAndPredict(CSysMdbObjectAttrPredict *p1, CSysMdbObjectAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbObjectAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbObjectAttr	要被判断的对象状态指标
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return m_p1->isValid(pSysMdbObjectAttr) && m_p2->isValid(pSysMdbObjectAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrOrPredict是对两个对象状态指标谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrOrPredict : public CSysMdbObjectAttrPredict
{
private:
	CSysMdbObjectAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbObjectAttrOrPredict(CSysMdbObjectAttrPredict *p1, CSysMdbObjectAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbObjectAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbObjectAttr	要被判断的对象状态指标
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return m_p1->isValid(pSysMdbObjectAttr) || m_p2->isValid(pSysMdbObjectAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrNotPredict是对一个对象状态指标谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrNotPredict : public CSysMdbObjectAttrPredict
{
private:
	CSysMdbObjectAttrPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbObjectAttrNotPredict(CSysMdbObjectAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbObjectAttrNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbObjectAttr	要被判断的对象状态指标
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return !m_predict->isValid(pSysMdbObjectAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrFilter是一个对已有的对象状态指标枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrFilter: public CSysMdbObjectAttrIterator
{
private:
	CSysMdbObjectAttrIterator *m_baseIterator;
	CSysMdbObjectAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbObjectAttrFilter(CSysMdbObjectAttrIterator *pBaseIterator, CSysMdbObjectAttrPredict *pPredict, bool continueResult=false)
		:CSysMdbObjectAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbObjectAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbObjectAttr
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbObjectAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrLinkIterator是连接两个对象状态指标枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrLinkIterator: public CSysMdbObjectAttrIterator
{
private:
	CSysMdbObjectAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbObjectAttrLinkIterator(CSysMdbObjectAttrIterator *pBaseIterator1,CSysMdbObjectAttrIterator *pBaseIterator2)
		:CSysMdbObjectAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbObjectAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbObjectAttr
	///@return	下一个满足条件CSysMdbObjectAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbObjectAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbObjectAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoSingleIterator是至多返回一个日志文件内容传输信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoSingleIterator: public CSysMdbSyslogInfoIterator
{
private:
	CSysMdbSyslogInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbSyslogInfoSingleIterator(CSysMdbSyslogInfoFactory *pFactory,CSysMdbSyslogInfo *pResult)
		:CSysMdbSyslogInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbSyslogInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbSyslogInfo
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbSyslogInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoPredict是判断一个日志文件内容传输信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbSyslogInfo	要被判断的日志文件内容传输信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoAndPredict是对两个日志文件内容传输信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoAndPredict : public CSysMdbSyslogInfoPredict
{
private:
	CSysMdbSyslogInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbSyslogInfoAndPredict(CSysMdbSyslogInfoPredict *p1, CSysMdbSyslogInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbSyslogInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbSyslogInfo	要被判断的日志文件内容传输信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return m_p1->isValid(pSysMdbSyslogInfo) && m_p2->isValid(pSysMdbSyslogInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoOrPredict是对两个日志文件内容传输信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoOrPredict : public CSysMdbSyslogInfoPredict
{
private:
	CSysMdbSyslogInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbSyslogInfoOrPredict(CSysMdbSyslogInfoPredict *p1, CSysMdbSyslogInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbSyslogInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbSyslogInfo	要被判断的日志文件内容传输信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return m_p1->isValid(pSysMdbSyslogInfo) || m_p2->isValid(pSysMdbSyslogInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoNotPredict是对一个日志文件内容传输信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoNotPredict : public CSysMdbSyslogInfoPredict
{
private:
	CSysMdbSyslogInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbSyslogInfoNotPredict(CSysMdbSyslogInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbSyslogInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbSyslogInfo	要被判断的日志文件内容传输信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return !m_predict->isValid(pSysMdbSyslogInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoFilter是一个对已有的日志文件内容传输信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoFilter: public CSysMdbSyslogInfoIterator
{
private:
	CSysMdbSyslogInfoIterator *m_baseIterator;
	CSysMdbSyslogInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbSyslogInfoFilter(CSysMdbSyslogInfoIterator *pBaseIterator, CSysMdbSyslogInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbSyslogInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbSyslogInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbSyslogInfo
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbSyslogInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoLinkIterator是连接两个日志文件内容传输信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoLinkIterator: public CSysMdbSyslogInfoIterator
{
private:
	CSysMdbSyslogInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbSyslogInfoLinkIterator(CSysMdbSyslogInfoIterator *pBaseIterator1,CSysMdbSyslogInfoIterator *pBaseIterator2)
		:CSysMdbSyslogInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbSyslogInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbSyslogInfo
	///@return	下一个满足条件CSysMdbSyslogInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbSyslogInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbSyslogInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysUserInfoSingleIterator是至多返回一个用户信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoSingleIterator: public CSysUserInfoIterator
{
private:
	CSysUserInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysUserInfoSingleIterator(CSysUserInfoFactory *pFactory,CSysUserInfo *pResult)
		:CSysUserInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysUserInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysUserInfo
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoPredict是判断一个用户信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoPredict
{
public:
	///判断是否合法
	///@param	pSysUserInfo	要被判断的用户信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInfo *pSysUserInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoAndPredict是对两个用户信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoAndPredict : public CSysUserInfoPredict
{
private:
	CSysUserInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysUserInfoAndPredict(CSysUserInfoPredict *p1, CSysUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysUserInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysUserInfo	要被判断的用户信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInfo *pSysUserInfo)
	{
		return m_p1->isValid(pSysUserInfo) && m_p2->isValid(pSysUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoOrPredict是对两个用户信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoOrPredict : public CSysUserInfoPredict
{
private:
	CSysUserInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysUserInfoOrPredict(CSysUserInfoPredict *p1, CSysUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysUserInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysUserInfo	要被判断的用户信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInfo *pSysUserInfo)
	{
		return m_p1->isValid(pSysUserInfo) || m_p2->isValid(pSysUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoNotPredict是对一个用户信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoNotPredict : public CSysUserInfoPredict
{
private:
	CSysUserInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysUserInfoNotPredict(CSysUserInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysUserInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysUserInfo	要被判断的用户信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInfo *pSysUserInfo)
	{
		return !m_predict->isValid(pSysUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoFilter是一个对已有的用户信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoFilter: public CSysUserInfoIterator
{
private:
	CSysUserInfoIterator *m_baseIterator;
	CSysUserInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysUserInfoFilter(CSysUserInfoIterator *pBaseIterator, CSysUserInfoPredict *pPredict, bool continueResult=false)
		:CSysUserInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysUserInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysUserInfo
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoLinkIterator是连接两个用户信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoLinkIterator: public CSysUserInfoIterator
{
private:
	CSysUserInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysUserInfoLinkIterator(CSysUserInfoIterator *pBaseIterator1,CSysUserInfoIterator *pBaseIterator2)
		:CSysUserInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysUserInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysUserInfo
	///@return	下一个满足条件CSysUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoSingleIterator是至多返回一个在线用户信息查询应答的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoSingleIterator: public CSysOnlineUserInfoIterator
{
private:
	CSysOnlineUserInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysOnlineUserInfoSingleIterator(CSysOnlineUserInfoFactory *pFactory,CSysOnlineUserInfo *pResult)
		:CSysOnlineUserInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysOnlineUserInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysOnlineUserInfo
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysOnlineUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoPredict是判断一个在线用户信息查询应答是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoPredict
{
public:
	///判断是否合法
	///@param	pSysOnlineUserInfo	要被判断的在线用户信息查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoAndPredict是对两个在线用户信息查询应答谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoAndPredict : public CSysOnlineUserInfoPredict
{
private:
	CSysOnlineUserInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysOnlineUserInfoAndPredict(CSysOnlineUserInfoPredict *p1, CSysOnlineUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysOnlineUserInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysOnlineUserInfo	要被判断的在线用户信息查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return m_p1->isValid(pSysOnlineUserInfo) && m_p2->isValid(pSysOnlineUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoOrPredict是对两个在线用户信息查询应答谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoOrPredict : public CSysOnlineUserInfoPredict
{
private:
	CSysOnlineUserInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysOnlineUserInfoOrPredict(CSysOnlineUserInfoPredict *p1, CSysOnlineUserInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysOnlineUserInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysOnlineUserInfo	要被判断的在线用户信息查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return m_p1->isValid(pSysOnlineUserInfo) || m_p2->isValid(pSysOnlineUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoNotPredict是对一个在线用户信息查询应答谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoNotPredict : public CSysOnlineUserInfoPredict
{
private:
	CSysOnlineUserInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysOnlineUserInfoNotPredict(CSysOnlineUserInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysOnlineUserInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysOnlineUserInfo	要被判断的在线用户信息查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return !m_predict->isValid(pSysOnlineUserInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoFilter是一个对已有的在线用户信息查询应答枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoFilter: public CSysOnlineUserInfoIterator
{
private:
	CSysOnlineUserInfoIterator *m_baseIterator;
	CSysOnlineUserInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysOnlineUserInfoFilter(CSysOnlineUserInfoIterator *pBaseIterator, CSysOnlineUserInfoPredict *pPredict, bool continueResult=false)
		:CSysOnlineUserInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysOnlineUserInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysOnlineUserInfo
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysOnlineUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoLinkIterator是连接两个在线用户信息查询应答枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoLinkIterator: public CSysOnlineUserInfoIterator
{
private:
	CSysOnlineUserInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysOnlineUserInfoLinkIterator(CSysOnlineUserInfoIterator *pBaseIterator1,CSysOnlineUserInfoIterator *pBaseIterator2)
		:CSysOnlineUserInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysOnlineUserInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysOnlineUserInfo
	///@return	下一个满足条件CSysOnlineUserInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysOnlineUserInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysOnlineUserInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysWarningEventSingleIterator是至多返回一个告警事件查询应答的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventSingleIterator: public CSysWarningEventIterator
{
private:
	CSysWarningEvent *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysWarningEventSingleIterator(CSysWarningEventFactory *pFactory,CSysWarningEvent *pResult)
		:CSysWarningEventIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysWarningEventSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysWarningEvent
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventPredict是判断一个告警事件查询应答是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventPredict
{
public:
	///判断是否合法
	///@param	pSysWarningEvent	要被判断的告警事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventAndPredict是对两个告警事件查询应答谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventAndPredict : public CSysWarningEventPredict
{
private:
	CSysWarningEventPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysWarningEventAndPredict(CSysWarningEventPredict *p1, CSysWarningEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysWarningEventAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysWarningEvent	要被判断的告警事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)
	{
		return m_p1->isValid(pSysWarningEvent) && m_p2->isValid(pSysWarningEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventOrPredict是对两个告警事件查询应答谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventOrPredict : public CSysWarningEventPredict
{
private:
	CSysWarningEventPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysWarningEventOrPredict(CSysWarningEventPredict *p1, CSysWarningEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysWarningEventOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysWarningEvent	要被判断的告警事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)
	{
		return m_p1->isValid(pSysWarningEvent) || m_p2->isValid(pSysWarningEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventNotPredict是对一个告警事件查询应答谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventNotPredict : public CSysWarningEventPredict
{
private:
	CSysWarningEventPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysWarningEventNotPredict(CSysWarningEventPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysWarningEventNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysWarningEvent	要被判断的告警事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningEvent *pSysWarningEvent)
	{
		return !m_predict->isValid(pSysWarningEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventFilter是一个对已有的告警事件查询应答枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventFilter: public CSysWarningEventIterator
{
private:
	CSysWarningEventIterator *m_baseIterator;
	CSysWarningEventPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysWarningEventFilter(CSysWarningEventIterator *pBaseIterator, CSysWarningEventPredict *pPredict, bool continueResult=false)
		:CSysWarningEventIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysWarningEventFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysWarningEvent
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventLinkIterator是连接两个告警事件查询应答枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventLinkIterator: public CSysWarningEventIterator
{
private:
	CSysWarningEventIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysWarningEventLinkIterator(CSysWarningEventIterator *pBaseIterator1,CSysWarningEventIterator *pBaseIterator2)
		:CSysWarningEventIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysWarningEventLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysWarningEvent
	///@return	下一个满足条件CSysWarningEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysWarningQuerySingleIterator是至多返回一个告警明细应答的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQuerySingleIterator: public CSysWarningQueryIterator
{
private:
	CSysWarningQuery *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysWarningQuerySingleIterator(CSysWarningQueryFactory *pFactory,CSysWarningQuery *pResult)
		:CSysWarningQueryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysWarningQuerySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysWarningQuery
	///@return	下一个满足条件CSysWarningQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryPredict是判断一个告警明细应答是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryPredict
{
public:
	///判断是否合法
	///@param	pSysWarningQuery	要被判断的告警明细应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryAndPredict是对两个告警明细应答谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryAndPredict : public CSysWarningQueryPredict
{
private:
	CSysWarningQueryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysWarningQueryAndPredict(CSysWarningQueryPredict *p1, CSysWarningQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysWarningQueryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysWarningQuery	要被判断的告警明细应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)
	{
		return m_p1->isValid(pSysWarningQuery) && m_p2->isValid(pSysWarningQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryOrPredict是对两个告警明细应答谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryOrPredict : public CSysWarningQueryPredict
{
private:
	CSysWarningQueryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysWarningQueryOrPredict(CSysWarningQueryPredict *p1, CSysWarningQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysWarningQueryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysWarningQuery	要被判断的告警明细应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)
	{
		return m_p1->isValid(pSysWarningQuery) || m_p2->isValid(pSysWarningQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryNotPredict是对一个告警明细应答谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryNotPredict : public CSysWarningQueryPredict
{
private:
	CSysWarningQueryPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysWarningQueryNotPredict(CSysWarningQueryPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysWarningQueryNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysWarningQuery	要被判断的告警明细应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysWarningQuery *pSysWarningQuery)
	{
		return !m_predict->isValid(pSysWarningQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryFilter是一个对已有的告警明细应答枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryFilter: public CSysWarningQueryIterator
{
private:
	CSysWarningQueryIterator *m_baseIterator;
	CSysWarningQueryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysWarningQueryFilter(CSysWarningQueryIterator *pBaseIterator, CSysWarningQueryPredict *pPredict, bool continueResult=false)
		:CSysWarningQueryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysWarningQueryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysWarningQuery
	///@return	下一个满足条件CSysWarningQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryLinkIterator是连接两个告警明细应答枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryLinkIterator: public CSysWarningQueryIterator
{
private:
	CSysWarningQueryIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysWarningQueryLinkIterator(CSysWarningQueryIterator *pBaseIterator1,CSysWarningQueryIterator *pBaseIterator2)
		:CSysWarningQueryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysWarningQueryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysWarningQuery
	///@return	下一个满足条件CSysWarningQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysWarningQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysWarningQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSyslogEventSingleIterator是至多返回一个日志事件查询应答的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventSingleIterator: public CSyslogEventIterator
{
private:
	CSyslogEvent *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSyslogEventSingleIterator(CSyslogEventFactory *pFactory,CSyslogEvent *pResult)
		:CSyslogEventIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSyslogEventSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSyslogEvent
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSyslogEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSyslogEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventPredict是判断一个日志事件查询应答是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventPredict
{
public:
	///判断是否合法
	///@param	pSyslogEvent	要被判断的日志事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSyslogEvent *pSyslogEvent)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventAndPredict是对两个日志事件查询应答谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventAndPredict : public CSyslogEventPredict
{
private:
	CSyslogEventPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSyslogEventAndPredict(CSyslogEventPredict *p1, CSyslogEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSyslogEventAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSyslogEvent	要被判断的日志事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSyslogEvent *pSyslogEvent)
	{
		return m_p1->isValid(pSyslogEvent) && m_p2->isValid(pSyslogEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventOrPredict是对两个日志事件查询应答谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventOrPredict : public CSyslogEventPredict
{
private:
	CSyslogEventPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSyslogEventOrPredict(CSyslogEventPredict *p1, CSyslogEventPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSyslogEventOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSyslogEvent	要被判断的日志事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSyslogEvent *pSyslogEvent)
	{
		return m_p1->isValid(pSyslogEvent) || m_p2->isValid(pSyslogEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventNotPredict是对一个日志事件查询应答谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventNotPredict : public CSyslogEventPredict
{
private:
	CSyslogEventPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSyslogEventNotPredict(CSyslogEventPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSyslogEventNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSyslogEvent	要被判断的日志事件查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSyslogEvent *pSyslogEvent)
	{
		return !m_predict->isValid(pSyslogEvent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventFilter是一个对已有的日志事件查询应答枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventFilter: public CSyslogEventIterator
{
private:
	CSyslogEventIterator *m_baseIterator;
	CSyslogEventPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSyslogEventFilter(CSyslogEventIterator *pBaseIterator, CSyslogEventPredict *pPredict, bool continueResult=false)
		:CSyslogEventIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSyslogEventFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSyslogEvent
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSyslogEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSyslogEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventLinkIterator是连接两个日志事件查询应答枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventLinkIterator: public CSyslogEventIterator
{
private:
	CSyslogEventIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSyslogEventLinkIterator(CSyslogEventIterator *pBaseIterator1,CSyslogEventIterator *pBaseIterator2)
		:CSyslogEventIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSyslogEventLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSyslogEvent
	///@return	下一个满足条件CSyslogEvent，如果已经没有一个满足要求了，则返回NULL
	virtual CSyslogEvent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSyslogEvent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysEventDescripSingleIterator是至多返回一个事件描述查询的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripSingleIterator: public CSysEventDescripIterator
{
private:
	CSysEventDescrip *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysEventDescripSingleIterator(CSysEventDescripFactory *pFactory,CSysEventDescrip *pResult)
		:CSysEventDescripIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysEventDescripSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysEventDescrip
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	virtual CSysEventDescrip *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysEventDescrip 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripPredict是判断一个事件描述查询是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripPredict
{
public:
	///判断是否合法
	///@param	pSysEventDescrip	要被判断的事件描述查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripAndPredict是对两个事件描述查询谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripAndPredict : public CSysEventDescripPredict
{
private:
	CSysEventDescripPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysEventDescripAndPredict(CSysEventDescripPredict *p1, CSysEventDescripPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysEventDescripAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysEventDescrip	要被判断的事件描述查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)
	{
		return m_p1->isValid(pSysEventDescrip) && m_p2->isValid(pSysEventDescrip);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripOrPredict是对两个事件描述查询谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripOrPredict : public CSysEventDescripPredict
{
private:
	CSysEventDescripPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysEventDescripOrPredict(CSysEventDescripPredict *p1, CSysEventDescripPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysEventDescripOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysEventDescrip	要被判断的事件描述查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)
	{
		return m_p1->isValid(pSysEventDescrip) || m_p2->isValid(pSysEventDescrip);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripNotPredict是对一个事件描述查询谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripNotPredict : public CSysEventDescripPredict
{
private:
	CSysEventDescripPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysEventDescripNotPredict(CSysEventDescripPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysEventDescripNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysEventDescrip	要被判断的事件描述查询
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysEventDescrip *pSysEventDescrip)
	{
		return !m_predict->isValid(pSysEventDescrip);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripFilter是一个对已有的事件描述查询枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripFilter: public CSysEventDescripIterator
{
private:
	CSysEventDescripIterator *m_baseIterator;
	CSysEventDescripPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysEventDescripFilter(CSysEventDescripIterator *pBaseIterator, CSysEventDescripPredict *pPredict, bool continueResult=false)
		:CSysEventDescripIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysEventDescripFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysEventDescrip
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	virtual CSysEventDescrip *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysEventDescrip 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripLinkIterator是连接两个事件描述查询枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripLinkIterator: public CSysEventDescripIterator
{
private:
	CSysEventDescripIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysEventDescripLinkIterator(CSysEventDescripIterator *pBaseIterator1,CSysEventDescripIterator *pBaseIterator2)
		:CSysEventDescripIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysEventDescripLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysEventDescrip
	///@return	下一个满足条件CSysEventDescrip，如果已经没有一个满足要求了，则返回NULL
	virtual CSysEventDescrip *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysEventDescrip 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonSingleIterator是至多返回一个主机环境信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonSingleIterator: public CRspQryHostEnvCommonIterator
{
private:
	CRspQryHostEnvCommon *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRspQryHostEnvCommonSingleIterator(CRspQryHostEnvCommonFactory *pFactory,CRspQryHostEnvCommon *pResult)
		:CRspQryHostEnvCommonIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRspQryHostEnvCommonSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRspQryHostEnvCommon
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvCommon 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonPredict是判断一个主机环境信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonPredict
{
public:
	///判断是否合法
	///@param	pRspQryHostEnvCommon	要被判断的主机环境信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonAndPredict是对两个主机环境信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonAndPredict : public CRspQryHostEnvCommonPredict
{
private:
	CRspQryHostEnvCommonPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvCommonAndPredict(CRspQryHostEnvCommonPredict *p1, CRspQryHostEnvCommonPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvCommonAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvCommon	要被判断的主机环境信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return m_p1->isValid(pRspQryHostEnvCommon) && m_p2->isValid(pRspQryHostEnvCommon);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonOrPredict是对两个主机环境信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonOrPredict : public CRspQryHostEnvCommonPredict
{
private:
	CRspQryHostEnvCommonPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvCommonOrPredict(CRspQryHostEnvCommonPredict *p1, CRspQryHostEnvCommonPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvCommonOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvCommon	要被判断的主机环境信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return m_p1->isValid(pRspQryHostEnvCommon) || m_p2->isValid(pRspQryHostEnvCommon);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonNotPredict是对一个主机环境信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonNotPredict : public CRspQryHostEnvCommonPredict
{
private:
	CRspQryHostEnvCommonPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRspQryHostEnvCommonNotPredict(CRspQryHostEnvCommonPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRspQryHostEnvCommonNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRspQryHostEnvCommon	要被判断的主机环境信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return !m_predict->isValid(pRspQryHostEnvCommon);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonFilter是一个对已有的主机环境信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonFilter: public CRspQryHostEnvCommonIterator
{
private:
	CRspQryHostEnvCommonIterator *m_baseIterator;
	CRspQryHostEnvCommonPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRspQryHostEnvCommonFilter(CRspQryHostEnvCommonIterator *pBaseIterator, CRspQryHostEnvCommonPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvCommonIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRspQryHostEnvCommonFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRspQryHostEnvCommon
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvCommon 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonLinkIterator是连接两个主机环境信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonLinkIterator: public CRspQryHostEnvCommonIterator
{
private:
	CRspQryHostEnvCommonIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRspQryHostEnvCommonLinkIterator(CRspQryHostEnvCommonIterator *pBaseIterator1,CRspQryHostEnvCommonIterator *pBaseIterator2)
		:CRspQryHostEnvCommonIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRspQryHostEnvCommonLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRspQryHostEnvCommon
	///@return	下一个满足条件CRspQryHostEnvCommon，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvCommon *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvCommon 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanSingleIterator是至多返回一个主机环境Lan信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanSingleIterator: public CRspQryHostEnvLanIterator
{
private:
	CRspQryHostEnvLan *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRspQryHostEnvLanSingleIterator(CRspQryHostEnvLanFactory *pFactory,CRspQryHostEnvLan *pResult)
		:CRspQryHostEnvLanIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRspQryHostEnvLanSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRspQryHostEnvLan
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLan 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanPredict是判断一个主机环境Lan信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanPredict
{
public:
	///判断是否合法
	///@param	pRspQryHostEnvLan	要被判断的主机环境Lan信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanAndPredict是对两个主机环境Lan信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanAndPredict : public CRspQryHostEnvLanPredict
{
private:
	CRspQryHostEnvLanPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvLanAndPredict(CRspQryHostEnvLanPredict *p1, CRspQryHostEnvLanPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvLanAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvLan	要被判断的主机环境Lan信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return m_p1->isValid(pRspQryHostEnvLan) && m_p2->isValid(pRspQryHostEnvLan);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanOrPredict是对两个主机环境Lan信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanOrPredict : public CRspQryHostEnvLanPredict
{
private:
	CRspQryHostEnvLanPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvLanOrPredict(CRspQryHostEnvLanPredict *p1, CRspQryHostEnvLanPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvLanOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvLan	要被判断的主机环境Lan信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return m_p1->isValid(pRspQryHostEnvLan) || m_p2->isValid(pRspQryHostEnvLan);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanNotPredict是对一个主机环境Lan信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanNotPredict : public CRspQryHostEnvLanPredict
{
private:
	CRspQryHostEnvLanPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRspQryHostEnvLanNotPredict(CRspQryHostEnvLanPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRspQryHostEnvLanNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRspQryHostEnvLan	要被判断的主机环境Lan信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return !m_predict->isValid(pRspQryHostEnvLan);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanFilter是一个对已有的主机环境Lan信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanFilter: public CRspQryHostEnvLanIterator
{
private:
	CRspQryHostEnvLanIterator *m_baseIterator;
	CRspQryHostEnvLanPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRspQryHostEnvLanFilter(CRspQryHostEnvLanIterator *pBaseIterator, CRspQryHostEnvLanPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvLanIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRspQryHostEnvLanFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRspQryHostEnvLan
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLan 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanLinkIterator是连接两个主机环境Lan信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanLinkIterator: public CRspQryHostEnvLanIterator
{
private:
	CRspQryHostEnvLanIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRspQryHostEnvLanLinkIterator(CRspQryHostEnvLanIterator *pBaseIterator1,CRspQryHostEnvLanIterator *pBaseIterator2)
		:CRspQryHostEnvLanIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRspQryHostEnvLanLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRspQryHostEnvLan
	///@return	下一个满足条件CRspQryHostEnvLan，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLan *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLan 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageSingleIterator是至多返回一个主机环境存储设备信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageSingleIterator: public CRspQryHostEnvStorageIterator
{
private:
	CRspQryHostEnvStorage *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRspQryHostEnvStorageSingleIterator(CRspQryHostEnvStorageFactory *pFactory,CRspQryHostEnvStorage *pResult)
		:CRspQryHostEnvStorageIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRspQryHostEnvStorageSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRspQryHostEnvStorage
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvStorage 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStoragePredict是判断一个主机环境存储设备信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStoragePredict
{
public:
	///判断是否合法
	///@param	pRspQryHostEnvStorage	要被判断的主机环境存储设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageAndPredict是对两个主机环境存储设备信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageAndPredict : public CRspQryHostEnvStoragePredict
{
private:
	CRspQryHostEnvStoragePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvStorageAndPredict(CRspQryHostEnvStoragePredict *p1, CRspQryHostEnvStoragePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvStorageAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvStorage	要被判断的主机环境存储设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return m_p1->isValid(pRspQryHostEnvStorage) && m_p2->isValid(pRspQryHostEnvStorage);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageOrPredict是对两个主机环境存储设备信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageOrPredict : public CRspQryHostEnvStoragePredict
{
private:
	CRspQryHostEnvStoragePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvStorageOrPredict(CRspQryHostEnvStoragePredict *p1, CRspQryHostEnvStoragePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvStorageOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvStorage	要被判断的主机环境存储设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return m_p1->isValid(pRspQryHostEnvStorage) || m_p2->isValid(pRspQryHostEnvStorage);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageNotPredict是对一个主机环境存储设备信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageNotPredict : public CRspQryHostEnvStoragePredict
{
private:
	CRspQryHostEnvStoragePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRspQryHostEnvStorageNotPredict(CRspQryHostEnvStoragePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRspQryHostEnvStorageNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRspQryHostEnvStorage	要被判断的主机环境存储设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return !m_predict->isValid(pRspQryHostEnvStorage);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageFilter是一个对已有的主机环境存储设备信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageFilter: public CRspQryHostEnvStorageIterator
{
private:
	CRspQryHostEnvStorageIterator *m_baseIterator;
	CRspQryHostEnvStoragePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRspQryHostEnvStorageFilter(CRspQryHostEnvStorageIterator *pBaseIterator, CRspQryHostEnvStoragePredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvStorageIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRspQryHostEnvStorageFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRspQryHostEnvStorage
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvStorage 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageLinkIterator是连接两个主机环境存储设备信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageLinkIterator: public CRspQryHostEnvStorageIterator
{
private:
	CRspQryHostEnvStorageIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRspQryHostEnvStorageLinkIterator(CRspQryHostEnvStorageIterator *pBaseIterator1,CRspQryHostEnvStorageIterator *pBaseIterator2)
		:CRspQryHostEnvStorageIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRspQryHostEnvStorageLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRspQryHostEnvStorage
	///@return	下一个满足条件CRspQryHostEnvStorage，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvStorage *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvStorage 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOSingleIterator是至多返回一个主机环境IO设备信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOSingleIterator: public CRspQryHostEnvIOIterator
{
private:
	CRspQryHostEnvIO *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRspQryHostEnvIOSingleIterator(CRspQryHostEnvIOFactory *pFactory,CRspQryHostEnvIO *pResult)
		:CRspQryHostEnvIOIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRspQryHostEnvIOSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRspQryHostEnvIO
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOPredict是判断一个主机环境IO设备信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOPredict
{
public:
	///判断是否合法
	///@param	pRspQryHostEnvIO	要被判断的主机环境IO设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOAndPredict是对两个主机环境IO设备信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOAndPredict : public CRspQryHostEnvIOPredict
{
private:
	CRspQryHostEnvIOPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvIOAndPredict(CRspQryHostEnvIOPredict *p1, CRspQryHostEnvIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvIOAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvIO	要被判断的主机环境IO设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return m_p1->isValid(pRspQryHostEnvIO) && m_p2->isValid(pRspQryHostEnvIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOOrPredict是对两个主机环境IO设备信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOOrPredict : public CRspQryHostEnvIOPredict
{
private:
	CRspQryHostEnvIOPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvIOOrPredict(CRspQryHostEnvIOPredict *p1, CRspQryHostEnvIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvIOOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvIO	要被判断的主机环境IO设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return m_p1->isValid(pRspQryHostEnvIO) || m_p2->isValid(pRspQryHostEnvIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIONotPredict是对一个主机环境IO设备信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIONotPredict : public CRspQryHostEnvIOPredict
{
private:
	CRspQryHostEnvIOPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRspQryHostEnvIONotPredict(CRspQryHostEnvIOPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRspQryHostEnvIONotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRspQryHostEnvIO	要被判断的主机环境IO设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return !m_predict->isValid(pRspQryHostEnvIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOFilter是一个对已有的主机环境IO设备信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOFilter: public CRspQryHostEnvIOIterator
{
private:
	CRspQryHostEnvIOIterator *m_baseIterator;
	CRspQryHostEnvIOPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRspQryHostEnvIOFilter(CRspQryHostEnvIOIterator *pBaseIterator, CRspQryHostEnvIOPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvIOIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRspQryHostEnvIOFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRspQryHostEnvIO
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOLinkIterator是连接两个主机环境IO设备信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOLinkIterator: public CRspQryHostEnvIOIterator
{
private:
	CRspQryHostEnvIOIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRspQryHostEnvIOLinkIterator(CRspQryHostEnvIOIterator *pBaseIterator1,CRspQryHostEnvIOIterator *pBaseIterator2)
		:CRspQryHostEnvIOIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRspQryHostEnvIOLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRspQryHostEnvIO
	///@return	下一个满足条件CRspQryHostEnvIO，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSSingleIterator是至多返回一个主机环境文件系统信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSSingleIterator: public CRspQryHostEnvFSIterator
{
private:
	CRspQryHostEnvFS *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRspQryHostEnvFSSingleIterator(CRspQryHostEnvFSFactory *pFactory,CRspQryHostEnvFS *pResult)
		:CRspQryHostEnvFSIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRspQryHostEnvFSSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRspQryHostEnvFS
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvFS 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSPredict是判断一个主机环境文件系统信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSPredict
{
public:
	///判断是否合法
	///@param	pRspQryHostEnvFS	要被判断的主机环境文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSAndPredict是对两个主机环境文件系统信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSAndPredict : public CRspQryHostEnvFSPredict
{
private:
	CRspQryHostEnvFSPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvFSAndPredict(CRspQryHostEnvFSPredict *p1, CRspQryHostEnvFSPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvFSAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvFS	要被判断的主机环境文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return m_p1->isValid(pRspQryHostEnvFS) && m_p2->isValid(pRspQryHostEnvFS);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSOrPredict是对两个主机环境文件系统信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSOrPredict : public CRspQryHostEnvFSPredict
{
private:
	CRspQryHostEnvFSPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvFSOrPredict(CRspQryHostEnvFSPredict *p1, CRspQryHostEnvFSPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvFSOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvFS	要被判断的主机环境文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return m_p1->isValid(pRspQryHostEnvFS) || m_p2->isValid(pRspQryHostEnvFS);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSNotPredict是对一个主机环境文件系统信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSNotPredict : public CRspQryHostEnvFSPredict
{
private:
	CRspQryHostEnvFSPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRspQryHostEnvFSNotPredict(CRspQryHostEnvFSPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRspQryHostEnvFSNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRspQryHostEnvFS	要被判断的主机环境文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return !m_predict->isValid(pRspQryHostEnvFS);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSFilter是一个对已有的主机环境文件系统信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSFilter: public CRspQryHostEnvFSIterator
{
private:
	CRspQryHostEnvFSIterator *m_baseIterator;
	CRspQryHostEnvFSPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRspQryHostEnvFSFilter(CRspQryHostEnvFSIterator *pBaseIterator, CRspQryHostEnvFSPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvFSIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRspQryHostEnvFSFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRspQryHostEnvFS
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvFS 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSLinkIterator是连接两个主机环境文件系统信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSLinkIterator: public CRspQryHostEnvFSIterator
{
private:
	CRspQryHostEnvFSIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRspQryHostEnvFSLinkIterator(CRspQryHostEnvFSIterator *pBaseIterator1,CRspQryHostEnvFSIterator *pBaseIterator2)
		:CRspQryHostEnvFSIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRspQryHostEnvFSLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRspQryHostEnvFS
	///@return	下一个满足条件CRspQryHostEnvFS，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvFS *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvFS 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapSingleIterator是至多返回一个主机环境交换分区信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapSingleIterator: public CRspQryHostEnvSwapIterator
{
private:
	CRspQryHostEnvSwap *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRspQryHostEnvSwapSingleIterator(CRspQryHostEnvSwapFactory *pFactory,CRspQryHostEnvSwap *pResult)
		:CRspQryHostEnvSwapIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRspQryHostEnvSwapSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRspQryHostEnvSwap
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvSwap 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapPredict是判断一个主机环境交换分区信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapPredict
{
public:
	///判断是否合法
	///@param	pRspQryHostEnvSwap	要被判断的主机环境交换分区信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapAndPredict是对两个主机环境交换分区信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapAndPredict : public CRspQryHostEnvSwapPredict
{
private:
	CRspQryHostEnvSwapPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvSwapAndPredict(CRspQryHostEnvSwapPredict *p1, CRspQryHostEnvSwapPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvSwapAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvSwap	要被判断的主机环境交换分区信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return m_p1->isValid(pRspQryHostEnvSwap) && m_p2->isValid(pRspQryHostEnvSwap);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapOrPredict是对两个主机环境交换分区信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapOrPredict : public CRspQryHostEnvSwapPredict
{
private:
	CRspQryHostEnvSwapPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvSwapOrPredict(CRspQryHostEnvSwapPredict *p1, CRspQryHostEnvSwapPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvSwapOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvSwap	要被判断的主机环境交换分区信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return m_p1->isValid(pRspQryHostEnvSwap) || m_p2->isValid(pRspQryHostEnvSwap);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapNotPredict是对一个主机环境交换分区信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapNotPredict : public CRspQryHostEnvSwapPredict
{
private:
	CRspQryHostEnvSwapPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRspQryHostEnvSwapNotPredict(CRspQryHostEnvSwapPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRspQryHostEnvSwapNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRspQryHostEnvSwap	要被判断的主机环境交换分区信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return !m_predict->isValid(pRspQryHostEnvSwap);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapFilter是一个对已有的主机环境交换分区信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapFilter: public CRspQryHostEnvSwapIterator
{
private:
	CRspQryHostEnvSwapIterator *m_baseIterator;
	CRspQryHostEnvSwapPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRspQryHostEnvSwapFilter(CRspQryHostEnvSwapIterator *pBaseIterator, CRspQryHostEnvSwapPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvSwapIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRspQryHostEnvSwapFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRspQryHostEnvSwap
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvSwap 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapLinkIterator是连接两个主机环境交换分区信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapLinkIterator: public CRspQryHostEnvSwapIterator
{
private:
	CRspQryHostEnvSwapIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRspQryHostEnvSwapLinkIterator(CRspQryHostEnvSwapIterator *pBaseIterator1,CRspQryHostEnvSwapIterator *pBaseIterator2)
		:CRspQryHostEnvSwapIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRspQryHostEnvSwapLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRspQryHostEnvSwap
	///@return	下一个满足条件CRspQryHostEnvSwap，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvSwap *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvSwap 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgSingleIterator是至多返回一个主机环境网卡配置信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgSingleIterator: public CRspQryHostEnvLanCfgIterator
{
private:
	CRspQryHostEnvLanCfg *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CRspQryHostEnvLanCfgSingleIterator(CRspQryHostEnvLanCfgFactory *pFactory,CRspQryHostEnvLanCfg *pResult)
		:CRspQryHostEnvLanCfgIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CRspQryHostEnvLanCfgSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CRspQryHostEnvLanCfg
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLanCfg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgPredict是判断一个主机环境网卡配置信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgPredict
{
public:
	///判断是否合法
	///@param	pRspQryHostEnvLanCfg	要被判断的主机环境网卡配置信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)=0;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgAndPredict是对两个主机环境网卡配置信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgAndPredict : public CRspQryHostEnvLanCfgPredict
{
private:
	CRspQryHostEnvLanCfgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvLanCfgAndPredict(CRspQryHostEnvLanCfgPredict *p1, CRspQryHostEnvLanCfgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvLanCfgAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvLanCfg	要被判断的主机环境网卡配置信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return m_p1->isValid(pRspQryHostEnvLanCfg) && m_p2->isValid(pRspQryHostEnvLanCfg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgOrPredict是对两个主机环境网卡配置信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgOrPredict : public CRspQryHostEnvLanCfgPredict
{
private:
	CRspQryHostEnvLanCfgPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CRspQryHostEnvLanCfgOrPredict(CRspQryHostEnvLanCfgPredict *p1, CRspQryHostEnvLanCfgPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CRspQryHostEnvLanCfgOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pRspQryHostEnvLanCfg	要被判断的主机环境网卡配置信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return m_p1->isValid(pRspQryHostEnvLanCfg) || m_p2->isValid(pRspQryHostEnvLanCfg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgNotPredict是对一个主机环境网卡配置信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgNotPredict : public CRspQryHostEnvLanCfgPredict
{
private:
	CRspQryHostEnvLanCfgPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CRspQryHostEnvLanCfgNotPredict(CRspQryHostEnvLanCfgPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CRspQryHostEnvLanCfgNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pRspQryHostEnvLanCfg	要被判断的主机环境网卡配置信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return !m_predict->isValid(pRspQryHostEnvLanCfg);
	}
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgFilter是一个对已有的主机环境网卡配置信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgFilter: public CRspQryHostEnvLanCfgIterator
{
private:
	CRspQryHostEnvLanCfgIterator *m_baseIterator;
	CRspQryHostEnvLanCfgPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CRspQryHostEnvLanCfgFilter(CRspQryHostEnvLanCfgIterator *pBaseIterator, CRspQryHostEnvLanCfgPredict *pPredict, bool continueResult=false)
		:CRspQryHostEnvLanCfgIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CRspQryHostEnvLanCfgFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CRspQryHostEnvLanCfg
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLanCfg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgLinkIterator是连接两个主机环境网卡配置信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgLinkIterator: public CRspQryHostEnvLanCfgIterator
{
private:
	CRspQryHostEnvLanCfgIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CRspQryHostEnvLanCfgLinkIterator(CRspQryHostEnvLanCfgIterator *pBaseIterator1,CRspQryHostEnvLanCfgIterator *pBaseIterator2)
		:CRspQryHostEnvLanCfgIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CRspQryHostEnvLanCfgLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CRspQryHostEnvLanCfg
	///@return	下一个满足条件CRspQryHostEnvLanCfg，如果已经没有一个满足要求了，则返回NULL
	virtual CRspQryHostEnvLanCfg *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pRspQryHostEnvLanCfg 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoSingleIterator是至多返回一个CPU资源使用信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoSingleIterator: public CSysMdbTopCpuInfoIterator
{
private:
	CSysMdbTopCpuInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbTopCpuInfoSingleIterator(CSysMdbTopCpuInfoFactory *pFactory,CSysMdbTopCpuInfo *pResult)
		:CSysMdbTopCpuInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbTopCpuInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbTopCpuInfo
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopCpuInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoPredict是判断一个CPU资源使用信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbTopCpuInfo	要被判断的CPU资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoAndPredict是对两个CPU资源使用信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoAndPredict : public CSysMdbTopCpuInfoPredict
{
private:
	CSysMdbTopCpuInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTopCpuInfoAndPredict(CSysMdbTopCpuInfoPredict *p1, CSysMdbTopCpuInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTopCpuInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTopCpuInfo	要被判断的CPU资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return m_p1->isValid(pSysMdbTopCpuInfo) && m_p2->isValid(pSysMdbTopCpuInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoOrPredict是对两个CPU资源使用信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoOrPredict : public CSysMdbTopCpuInfoPredict
{
private:
	CSysMdbTopCpuInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTopCpuInfoOrPredict(CSysMdbTopCpuInfoPredict *p1, CSysMdbTopCpuInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTopCpuInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTopCpuInfo	要被判断的CPU资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return m_p1->isValid(pSysMdbTopCpuInfo) || m_p2->isValid(pSysMdbTopCpuInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoNotPredict是对一个CPU资源使用信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoNotPredict : public CSysMdbTopCpuInfoPredict
{
private:
	CSysMdbTopCpuInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbTopCpuInfoNotPredict(CSysMdbTopCpuInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbTopCpuInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbTopCpuInfo	要被判断的CPU资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return !m_predict->isValid(pSysMdbTopCpuInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoFilter是一个对已有的CPU资源使用信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoFilter: public CSysMdbTopCpuInfoIterator
{
private:
	CSysMdbTopCpuInfoIterator *m_baseIterator;
	CSysMdbTopCpuInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbTopCpuInfoFilter(CSysMdbTopCpuInfoIterator *pBaseIterator, CSysMdbTopCpuInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbTopCpuInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbTopCpuInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbTopCpuInfo
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopCpuInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoLinkIterator是连接两个CPU资源使用信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoLinkIterator: public CSysMdbTopCpuInfoIterator
{
private:
	CSysMdbTopCpuInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbTopCpuInfoLinkIterator(CSysMdbTopCpuInfoIterator *pBaseIterator1,CSysMdbTopCpuInfoIterator *pBaseIterator2)
		:CSysMdbTopCpuInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbTopCpuInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbTopCpuInfo
	///@return	下一个满足条件CSysMdbTopCpuInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopCpuInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopCpuInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoSingleIterator是至多返回一个内存资源使用信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoSingleIterator: public CSysMdbTopMemInfoIterator
{
private:
	CSysMdbTopMemInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbTopMemInfoSingleIterator(CSysMdbTopMemInfoFactory *pFactory,CSysMdbTopMemInfo *pResult)
		:CSysMdbTopMemInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbTopMemInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbTopMemInfo
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopMemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoPredict是判断一个内存资源使用信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbTopMemInfo	要被判断的内存资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoAndPredict是对两个内存资源使用信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoAndPredict : public CSysMdbTopMemInfoPredict
{
private:
	CSysMdbTopMemInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTopMemInfoAndPredict(CSysMdbTopMemInfoPredict *p1, CSysMdbTopMemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTopMemInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTopMemInfo	要被判断的内存资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return m_p1->isValid(pSysMdbTopMemInfo) && m_p2->isValid(pSysMdbTopMemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoOrPredict是对两个内存资源使用信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoOrPredict : public CSysMdbTopMemInfoPredict
{
private:
	CSysMdbTopMemInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTopMemInfoOrPredict(CSysMdbTopMemInfoPredict *p1, CSysMdbTopMemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTopMemInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTopMemInfo	要被判断的内存资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return m_p1->isValid(pSysMdbTopMemInfo) || m_p2->isValid(pSysMdbTopMemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoNotPredict是对一个内存资源使用信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoNotPredict : public CSysMdbTopMemInfoPredict
{
private:
	CSysMdbTopMemInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbTopMemInfoNotPredict(CSysMdbTopMemInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbTopMemInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbTopMemInfo	要被判断的内存资源使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return !m_predict->isValid(pSysMdbTopMemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoFilter是一个对已有的内存资源使用信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoFilter: public CSysMdbTopMemInfoIterator
{
private:
	CSysMdbTopMemInfoIterator *m_baseIterator;
	CSysMdbTopMemInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbTopMemInfoFilter(CSysMdbTopMemInfoIterator *pBaseIterator, CSysMdbTopMemInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbTopMemInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbTopMemInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbTopMemInfo
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopMemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoLinkIterator是连接两个内存资源使用信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoLinkIterator: public CSysMdbTopMemInfoIterator
{
private:
	CSysMdbTopMemInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbTopMemInfoLinkIterator(CSysMdbTopMemInfoIterator *pBaseIterator1,CSysMdbTopMemInfoIterator *pBaseIterator2)
		:CSysMdbTopMemInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbTopMemInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbTopMemInfo
	///@return	下一个满足条件CSysMdbTopMemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopMemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopMemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoSingleIterator是至多返回一个进程信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoSingleIterator: public CSysMdbTopProcessInfoIterator
{
private:
	CSysMdbTopProcessInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbTopProcessInfoSingleIterator(CSysMdbTopProcessInfoFactory *pFactory,CSysMdbTopProcessInfo *pResult)
		:CSysMdbTopProcessInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbTopProcessInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbTopProcessInfo
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopProcessInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoPredict是判断一个进程信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbTopProcessInfo	要被判断的进程信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoAndPredict是对两个进程信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoAndPredict : public CSysMdbTopProcessInfoPredict
{
private:
	CSysMdbTopProcessInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTopProcessInfoAndPredict(CSysMdbTopProcessInfoPredict *p1, CSysMdbTopProcessInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTopProcessInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTopProcessInfo	要被判断的进程信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return m_p1->isValid(pSysMdbTopProcessInfo) && m_p2->isValid(pSysMdbTopProcessInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoOrPredict是对两个进程信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoOrPredict : public CSysMdbTopProcessInfoPredict
{
private:
	CSysMdbTopProcessInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTopProcessInfoOrPredict(CSysMdbTopProcessInfoPredict *p1, CSysMdbTopProcessInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTopProcessInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTopProcessInfo	要被判断的进程信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return m_p1->isValid(pSysMdbTopProcessInfo) || m_p2->isValid(pSysMdbTopProcessInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoNotPredict是对一个进程信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoNotPredict : public CSysMdbTopProcessInfoPredict
{
private:
	CSysMdbTopProcessInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbTopProcessInfoNotPredict(CSysMdbTopProcessInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbTopProcessInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbTopProcessInfo	要被判断的进程信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return !m_predict->isValid(pSysMdbTopProcessInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoFilter是一个对已有的进程信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoFilter: public CSysMdbTopProcessInfoIterator
{
private:
	CSysMdbTopProcessInfoIterator *m_baseIterator;
	CSysMdbTopProcessInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbTopProcessInfoFilter(CSysMdbTopProcessInfoIterator *pBaseIterator, CSysMdbTopProcessInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbTopProcessInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbTopProcessInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbTopProcessInfo
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopProcessInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoLinkIterator是连接两个进程信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoLinkIterator: public CSysMdbTopProcessInfoIterator
{
private:
	CSysMdbTopProcessInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbTopProcessInfoLinkIterator(CSysMdbTopProcessInfoIterator *pBaseIterator1,CSysMdbTopProcessInfoIterator *pBaseIterator2)
		:CSysMdbTopProcessInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbTopProcessInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbTopProcessInfo
	///@return	下一个满足条件CSysMdbTopProcessInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTopProcessInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTopProcessInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoSingleIterator是至多返回一个文件系统信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoSingleIterator: public CSysMdbFileSystemInfoIterator
{
private:
	CSysMdbFileSystemInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbFileSystemInfoSingleIterator(CSysMdbFileSystemInfoFactory *pFactory,CSysMdbFileSystemInfo *pResult)
		:CSysMdbFileSystemInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbFileSystemInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbFileSystemInfo
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbFileSystemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoPredict是判断一个文件系统信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbFileSystemInfo	要被判断的文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoAndPredict是对两个文件系统信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoAndPredict : public CSysMdbFileSystemInfoPredict
{
private:
	CSysMdbFileSystemInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbFileSystemInfoAndPredict(CSysMdbFileSystemInfoPredict *p1, CSysMdbFileSystemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbFileSystemInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbFileSystemInfo	要被判断的文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return m_p1->isValid(pSysMdbFileSystemInfo) && m_p2->isValid(pSysMdbFileSystemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoOrPredict是对两个文件系统信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoOrPredict : public CSysMdbFileSystemInfoPredict
{
private:
	CSysMdbFileSystemInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbFileSystemInfoOrPredict(CSysMdbFileSystemInfoPredict *p1, CSysMdbFileSystemInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbFileSystemInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbFileSystemInfo	要被判断的文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return m_p1->isValid(pSysMdbFileSystemInfo) || m_p2->isValid(pSysMdbFileSystemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoNotPredict是对一个文件系统信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoNotPredict : public CSysMdbFileSystemInfoPredict
{
private:
	CSysMdbFileSystemInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbFileSystemInfoNotPredict(CSysMdbFileSystemInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbFileSystemInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbFileSystemInfo	要被判断的文件系统信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return !m_predict->isValid(pSysMdbFileSystemInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoFilter是一个对已有的文件系统信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoFilter: public CSysMdbFileSystemInfoIterator
{
private:
	CSysMdbFileSystemInfoIterator *m_baseIterator;
	CSysMdbFileSystemInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbFileSystemInfoFilter(CSysMdbFileSystemInfoIterator *pBaseIterator, CSysMdbFileSystemInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbFileSystemInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbFileSystemInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbFileSystemInfo
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbFileSystemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoLinkIterator是连接两个文件系统信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoLinkIterator: public CSysMdbFileSystemInfoIterator
{
private:
	CSysMdbFileSystemInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbFileSystemInfoLinkIterator(CSysMdbFileSystemInfoIterator *pBaseIterator1,CSysMdbFileSystemInfoIterator *pBaseIterator2)
		:CSysMdbFileSystemInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbFileSystemInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbFileSystemInfo
	///@return	下一个满足条件CSysMdbFileSystemInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbFileSystemInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbFileSystemInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoSingleIterator是至多返回一个网络使用信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoSingleIterator: public CSysMdbNetworkInfoIterator
{
private:
	CSysMdbNetworkInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbNetworkInfoSingleIterator(CSysMdbNetworkInfoFactory *pFactory,CSysMdbNetworkInfo *pResult)
		:CSysMdbNetworkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbNetworkInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbNetworkInfo
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetworkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoPredict是判断一个网络使用信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbNetworkInfo	要被判断的网络使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoAndPredict是对两个网络使用信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoAndPredict : public CSysMdbNetworkInfoPredict
{
private:
	CSysMdbNetworkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbNetworkInfoAndPredict(CSysMdbNetworkInfoPredict *p1, CSysMdbNetworkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbNetworkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbNetworkInfo	要被判断的网络使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return m_p1->isValid(pSysMdbNetworkInfo) && m_p2->isValid(pSysMdbNetworkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoOrPredict是对两个网络使用信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoOrPredict : public CSysMdbNetworkInfoPredict
{
private:
	CSysMdbNetworkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbNetworkInfoOrPredict(CSysMdbNetworkInfoPredict *p1, CSysMdbNetworkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbNetworkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbNetworkInfo	要被判断的网络使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return m_p1->isValid(pSysMdbNetworkInfo) || m_p2->isValid(pSysMdbNetworkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoNotPredict是对一个网络使用信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoNotPredict : public CSysMdbNetworkInfoPredict
{
private:
	CSysMdbNetworkInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbNetworkInfoNotPredict(CSysMdbNetworkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbNetworkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbNetworkInfo	要被判断的网络使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return !m_predict->isValid(pSysMdbNetworkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoFilter是一个对已有的网络使用信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoFilter: public CSysMdbNetworkInfoIterator
{
private:
	CSysMdbNetworkInfoIterator *m_baseIterator;
	CSysMdbNetworkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbNetworkInfoFilter(CSysMdbNetworkInfoIterator *pBaseIterator, CSysMdbNetworkInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbNetworkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbNetworkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbNetworkInfo
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetworkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoLinkIterator是连接两个网络使用信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoLinkIterator: public CSysMdbNetworkInfoIterator
{
private:
	CSysMdbNetworkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbNetworkInfoLinkIterator(CSysMdbNetworkInfoIterator *pBaseIterator1,CSysMdbNetworkInfoIterator *pBaseIterator2)
		:CSysMdbNetworkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbNetworkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbNetworkInfo
	///@return	下一个满足条件CSysMdbNetworkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetworkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetworkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitSingleIterator是至多返回一个会员的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitSingleIterator: public CSysParticipantInitIterator
{
private:
	CSysParticipantInit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysParticipantInitSingleIterator(CSysParticipantInitFactory *pFactory,CSysParticipantInit *pResult)
		:CSysParticipantInitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysParticipantInitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysParticipantInit
	///@return	下一个满足条件CSysParticipantInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitPredict是判断一个会员是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitPredict
{
public:
	///判断是否合法
	///@param	pSysParticipantInit	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitAndPredict是对两个会员谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitAndPredict : public CSysParticipantInitPredict
{
private:
	CSysParticipantInitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysParticipantInitAndPredict(CSysParticipantInitPredict *p1, CSysParticipantInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysParticipantInitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysParticipantInit	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)
	{
		return m_p1->isValid(pSysParticipantInit) && m_p2->isValid(pSysParticipantInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitOrPredict是对两个会员谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitOrPredict : public CSysParticipantInitPredict
{
private:
	CSysParticipantInitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysParticipantInitOrPredict(CSysParticipantInitPredict *p1, CSysParticipantInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysParticipantInitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysParticipantInit	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)
	{
		return m_p1->isValid(pSysParticipantInit) || m_p2->isValid(pSysParticipantInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitNotPredict是对一个会员谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitNotPredict : public CSysParticipantInitPredict
{
private:
	CSysParticipantInitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysParticipantInitNotPredict(CSysParticipantInitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysParticipantInitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysParticipantInit	要被判断的会员
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticipantInit *pSysParticipantInit)
	{
		return !m_predict->isValid(pSysParticipantInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitFilter是一个对已有的会员枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitFilter: public CSysParticipantInitIterator
{
private:
	CSysParticipantInitIterator *m_baseIterator;
	CSysParticipantInitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysParticipantInitFilter(CSysParticipantInitIterator *pBaseIterator, CSysParticipantInitPredict *pPredict, bool continueResult=false)
		:CSysParticipantInitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysParticipantInitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysParticipantInit
	///@return	下一个满足条件CSysParticipantInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitLinkIterator是连接两个会员枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitLinkIterator: public CSysParticipantInitIterator
{
private:
	CSysParticipantInitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysParticipantInitLinkIterator(CSysParticipantInitIterator *pBaseIterator1,CSysParticipantInitIterator *pBaseIterator2)
		:CSysParticipantInitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysParticipantInitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysParticipantInit
	///@return	下一个满足条件CSysParticipantInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticipantInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticipantInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysUserInitSingleIterator是至多返回一个交易用户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitSingleIterator: public CSysUserInitIterator
{
private:
	CSysUserInit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysUserInitSingleIterator(CSysUserInitFactory *pFactory,CSysUserInit *pResult)
		:CSysUserInitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysUserInitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysUserInit
	///@return	下一个满足条件CSysUserInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitPredict是判断一个交易用户是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitPredict
{
public:
	///判断是否合法
	///@param	pSysUserInit	要被判断的交易用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInit *pSysUserInit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitAndPredict是对两个交易用户谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitAndPredict : public CSysUserInitPredict
{
private:
	CSysUserInitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysUserInitAndPredict(CSysUserInitPredict *p1, CSysUserInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysUserInitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysUserInit	要被判断的交易用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInit *pSysUserInit)
	{
		return m_p1->isValid(pSysUserInit) && m_p2->isValid(pSysUserInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitOrPredict是对两个交易用户谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitOrPredict : public CSysUserInitPredict
{
private:
	CSysUserInitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysUserInitOrPredict(CSysUserInitPredict *p1, CSysUserInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysUserInitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysUserInit	要被判断的交易用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInit *pSysUserInit)
	{
		return m_p1->isValid(pSysUserInit) || m_p2->isValid(pSysUserInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitNotPredict是对一个交易用户谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitNotPredict : public CSysUserInitPredict
{
private:
	CSysUserInitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysUserInitNotPredict(CSysUserInitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysUserInitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysUserInit	要被判断的交易用户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysUserInit *pSysUserInit)
	{
		return !m_predict->isValid(pSysUserInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitFilter是一个对已有的交易用户枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitFilter: public CSysUserInitIterator
{
private:
	CSysUserInitIterator *m_baseIterator;
	CSysUserInitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysUserInitFilter(CSysUserInitIterator *pBaseIterator, CSysUserInitPredict *pPredict, bool continueResult=false)
		:CSysUserInitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysUserInitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysUserInit
	///@return	下一个满足条件CSysUserInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitLinkIterator是连接两个交易用户枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitLinkIterator: public CSysUserInitIterator
{
private:
	CSysUserInitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysUserInitLinkIterator(CSysUserInitIterator *pBaseIterator1,CSysUserInitIterator *pBaseIterator2)
		:CSysUserInitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysUserInitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysUserInit
	///@return	下一个满足条件CSysUserInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysUserInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysUserInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysClientInitSingleIterator是至多返回一个客户的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitSingleIterator: public CSysClientInitIterator
{
private:
	CSysClientInit *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysClientInitSingleIterator(CSysClientInitFactory *pFactory,CSysClientInit *pResult)
		:CSysClientInitIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysClientInitSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysClientInit
	///@return	下一个满足条件CSysClientInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitPredict是判断一个客户是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitPredict
{
public:
	///判断是否合法
	///@param	pSysClientInit	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientInit *pSysClientInit)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitAndPredict是对两个客户谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitAndPredict : public CSysClientInitPredict
{
private:
	CSysClientInitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientInitAndPredict(CSysClientInitPredict *p1, CSysClientInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientInitAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientInit	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientInit *pSysClientInit)
	{
		return m_p1->isValid(pSysClientInit) && m_p2->isValid(pSysClientInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitOrPredict是对两个客户谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitOrPredict : public CSysClientInitPredict
{
private:
	CSysClientInitPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysClientInitOrPredict(CSysClientInitPredict *p1, CSysClientInitPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysClientInitOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysClientInit	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientInit *pSysClientInit)
	{
		return m_p1->isValid(pSysClientInit) || m_p2->isValid(pSysClientInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitNotPredict是对一个客户谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitNotPredict : public CSysClientInitPredict
{
private:
	CSysClientInitPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysClientInitNotPredict(CSysClientInitPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysClientInitNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysClientInit	要被判断的客户
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysClientInit *pSysClientInit)
	{
		return !m_predict->isValid(pSysClientInit);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitFilter是一个对已有的客户枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitFilter: public CSysClientInitIterator
{
private:
	CSysClientInitIterator *m_baseIterator;
	CSysClientInitPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysClientInitFilter(CSysClientInitIterator *pBaseIterator, CSysClientInitPredict *pPredict, bool continueResult=false)
		:CSysClientInitIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysClientInitFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysClientInit
	///@return	下一个满足条件CSysClientInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitLinkIterator是连接两个客户枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitLinkIterator: public CSysClientInitIterator
{
private:
	CSysClientInitIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysClientInitLinkIterator(CSysClientInitIterator *pBaseIterator1,CSysClientInitIterator *pBaseIterator2)
		:CSysClientInitIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysClientInitLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysClientInit
	///@return	下一个满足条件CSysClientInit，如果已经没有一个满足要求了，则返回NULL
	virtual CSysClientInit *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysClientInit 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoSingleIterator是至多返回一个交易系统登录信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoSingleIterator: public CSysTradeUserLoginInfoIterator
{
private:
	CSysTradeUserLoginInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysTradeUserLoginInfoSingleIterator(CSysTradeUserLoginInfoFactory *pFactory,CSysTradeUserLoginInfo *pResult)
		:CSysTradeUserLoginInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysTradeUserLoginInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysTradeUserLoginInfo
	///@return	下一个满足条件CSysTradeUserLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysTradeUserLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoPredict是判断一个交易系统登录信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoPredict
{
public:
	///判断是否合法
	///@param	pSysTradeUserLoginInfo	要被判断的交易系统登录信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoAndPredict是对两个交易系统登录信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoAndPredict : public CSysTradeUserLoginInfoPredict
{
private:
	CSysTradeUserLoginInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysTradeUserLoginInfoAndPredict(CSysTradeUserLoginInfoPredict *p1, CSysTradeUserLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysTradeUserLoginInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysTradeUserLoginInfo	要被判断的交易系统登录信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return m_p1->isValid(pSysTradeUserLoginInfo) && m_p2->isValid(pSysTradeUserLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoOrPredict是对两个交易系统登录信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoOrPredict : public CSysTradeUserLoginInfoPredict
{
private:
	CSysTradeUserLoginInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysTradeUserLoginInfoOrPredict(CSysTradeUserLoginInfoPredict *p1, CSysTradeUserLoginInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysTradeUserLoginInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysTradeUserLoginInfo	要被判断的交易系统登录信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return m_p1->isValid(pSysTradeUserLoginInfo) || m_p2->isValid(pSysTradeUserLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoNotPredict是对一个交易系统登录信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoNotPredict : public CSysTradeUserLoginInfoPredict
{
private:
	CSysTradeUserLoginInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysTradeUserLoginInfoNotPredict(CSysTradeUserLoginInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysTradeUserLoginInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysTradeUserLoginInfo	要被判断的交易系统登录信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return !m_predict->isValid(pSysTradeUserLoginInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoFilter是一个对已有的交易系统登录信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoFilter: public CSysTradeUserLoginInfoIterator
{
private:
	CSysTradeUserLoginInfoIterator *m_baseIterator;
	CSysTradeUserLoginInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysTradeUserLoginInfoFilter(CSysTradeUserLoginInfoIterator *pBaseIterator, CSysTradeUserLoginInfoPredict *pPredict, bool continueResult=false)
		:CSysTradeUserLoginInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysTradeUserLoginInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysTradeUserLoginInfo
	///@return	下一个满足条件CSysTradeUserLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysTradeUserLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoLinkIterator是连接两个交易系统登录信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoLinkIterator: public CSysTradeUserLoginInfoIterator
{
private:
	CSysTradeUserLoginInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysTradeUserLoginInfoLinkIterator(CSysTradeUserLoginInfoIterator *pBaseIterator1,CSysTradeUserLoginInfoIterator *pBaseIterator2)
		:CSysTradeUserLoginInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysTradeUserLoginInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysTradeUserLoginInfo
	///@return	下一个满足条件CSysTradeUserLoginInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysTradeUserLoginInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysTradeUserLoginInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoSingleIterator是至多返回一个Web应用信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoSingleIterator: public CSysMdbWebAppInfoIterator
{
private:
	CSysMdbWebAppInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbWebAppInfoSingleIterator(CSysMdbWebAppInfoFactory *pFactory,CSysMdbWebAppInfo *pResult)
		:CSysMdbWebAppInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbWebAppInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbWebAppInfo
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbWebAppInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoPredict是判断一个Web应用信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbWebAppInfo	要被判断的Web应用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoAndPredict是对两个Web应用信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoAndPredict : public CSysMdbWebAppInfoPredict
{
private:
	CSysMdbWebAppInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbWebAppInfoAndPredict(CSysMdbWebAppInfoPredict *p1, CSysMdbWebAppInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbWebAppInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbWebAppInfo	要被判断的Web应用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return m_p1->isValid(pSysMdbWebAppInfo) && m_p2->isValid(pSysMdbWebAppInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoOrPredict是对两个Web应用信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoOrPredict : public CSysMdbWebAppInfoPredict
{
private:
	CSysMdbWebAppInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbWebAppInfoOrPredict(CSysMdbWebAppInfoPredict *p1, CSysMdbWebAppInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbWebAppInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbWebAppInfo	要被判断的Web应用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return m_p1->isValid(pSysMdbWebAppInfo) || m_p2->isValid(pSysMdbWebAppInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoNotPredict是对一个Web应用信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoNotPredict : public CSysMdbWebAppInfoPredict
{
private:
	CSysMdbWebAppInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbWebAppInfoNotPredict(CSysMdbWebAppInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbWebAppInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbWebAppInfo	要被判断的Web应用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return !m_predict->isValid(pSysMdbWebAppInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoFilter是一个对已有的Web应用信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoFilter: public CSysMdbWebAppInfoIterator
{
private:
	CSysMdbWebAppInfoIterator *m_baseIterator;
	CSysMdbWebAppInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbWebAppInfoFilter(CSysMdbWebAppInfoIterator *pBaseIterator, CSysMdbWebAppInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbWebAppInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbWebAppInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbWebAppInfo
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbWebAppInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoLinkIterator是连接两个Web应用信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoLinkIterator: public CSysMdbWebAppInfoIterator
{
private:
	CSysMdbWebAppInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbWebAppInfoLinkIterator(CSysMdbWebAppInfoIterator *pBaseIterator1,CSysMdbWebAppInfoIterator *pBaseIterator2)
		:CSysMdbWebAppInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbWebAppInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbWebAppInfo
	///@return	下一个满足条件CSysMdbWebAppInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbWebAppInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbWebAppInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoSingleIterator是至多返回一个系统内存池信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoSingleIterator: public CSysMdbMemPoolInfoIterator
{
private:
	CSysMdbMemPoolInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbMemPoolInfoSingleIterator(CSysMdbMemPoolInfoFactory *pFactory,CSysMdbMemPoolInfo *pResult)
		:CSysMdbMemPoolInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbMemPoolInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbMemPoolInfo
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbMemPoolInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoPredict是判断一个系统内存池信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbMemPoolInfo	要被判断的系统内存池信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoAndPredict是对两个系统内存池信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoAndPredict : public CSysMdbMemPoolInfoPredict
{
private:
	CSysMdbMemPoolInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbMemPoolInfoAndPredict(CSysMdbMemPoolInfoPredict *p1, CSysMdbMemPoolInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbMemPoolInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbMemPoolInfo	要被判断的系统内存池信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return m_p1->isValid(pSysMdbMemPoolInfo) && m_p2->isValid(pSysMdbMemPoolInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoOrPredict是对两个系统内存池信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoOrPredict : public CSysMdbMemPoolInfoPredict
{
private:
	CSysMdbMemPoolInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbMemPoolInfoOrPredict(CSysMdbMemPoolInfoPredict *p1, CSysMdbMemPoolInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbMemPoolInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbMemPoolInfo	要被判断的系统内存池信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return m_p1->isValid(pSysMdbMemPoolInfo) || m_p2->isValid(pSysMdbMemPoolInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoNotPredict是对一个系统内存池信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoNotPredict : public CSysMdbMemPoolInfoPredict
{
private:
	CSysMdbMemPoolInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbMemPoolInfoNotPredict(CSysMdbMemPoolInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbMemPoolInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbMemPoolInfo	要被判断的系统内存池信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return !m_predict->isValid(pSysMdbMemPoolInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoFilter是一个对已有的系统内存池信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoFilter: public CSysMdbMemPoolInfoIterator
{
private:
	CSysMdbMemPoolInfoIterator *m_baseIterator;
	CSysMdbMemPoolInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbMemPoolInfoFilter(CSysMdbMemPoolInfoIterator *pBaseIterator, CSysMdbMemPoolInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbMemPoolInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbMemPoolInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbMemPoolInfo
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbMemPoolInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoLinkIterator是连接两个系统内存池信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoLinkIterator: public CSysMdbMemPoolInfoIterator
{
private:
	CSysMdbMemPoolInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbMemPoolInfoLinkIterator(CSysMdbMemPoolInfoIterator *pBaseIterator1,CSysMdbMemPoolInfoIterator *pBaseIterator2)
		:CSysMdbMemPoolInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbMemPoolInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbMemPoolInfo
	///@return	下一个满足条件CSysMdbMemPoolInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbMemPoolInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbMemPoolInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoSingleIterator是至多返回一个连接器信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoSingleIterator: public CSysMdbConnectorInfoIterator
{
private:
	CSysMdbConnectorInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbConnectorInfoSingleIterator(CSysMdbConnectorInfoFactory *pFactory,CSysMdbConnectorInfo *pResult)
		:CSysMdbConnectorInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbConnectorInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbConnectorInfo
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbConnectorInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoPredict是判断一个连接器信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbConnectorInfo	要被判断的连接器信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoAndPredict是对两个连接器信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoAndPredict : public CSysMdbConnectorInfoPredict
{
private:
	CSysMdbConnectorInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbConnectorInfoAndPredict(CSysMdbConnectorInfoPredict *p1, CSysMdbConnectorInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbConnectorInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbConnectorInfo	要被判断的连接器信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return m_p1->isValid(pSysMdbConnectorInfo) && m_p2->isValid(pSysMdbConnectorInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoOrPredict是对两个连接器信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoOrPredict : public CSysMdbConnectorInfoPredict
{
private:
	CSysMdbConnectorInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbConnectorInfoOrPredict(CSysMdbConnectorInfoPredict *p1, CSysMdbConnectorInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbConnectorInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbConnectorInfo	要被判断的连接器信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return m_p1->isValid(pSysMdbConnectorInfo) || m_p2->isValid(pSysMdbConnectorInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoNotPredict是对一个连接器信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoNotPredict : public CSysMdbConnectorInfoPredict
{
private:
	CSysMdbConnectorInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbConnectorInfoNotPredict(CSysMdbConnectorInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbConnectorInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbConnectorInfo	要被判断的连接器信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return !m_predict->isValid(pSysMdbConnectorInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoFilter是一个对已有的连接器信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoFilter: public CSysMdbConnectorInfoIterator
{
private:
	CSysMdbConnectorInfoIterator *m_baseIterator;
	CSysMdbConnectorInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbConnectorInfoFilter(CSysMdbConnectorInfoIterator *pBaseIterator, CSysMdbConnectorInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbConnectorInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbConnectorInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbConnectorInfo
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbConnectorInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoLinkIterator是连接两个连接器信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoLinkIterator: public CSysMdbConnectorInfoIterator
{
private:
	CSysMdbConnectorInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbConnectorInfoLinkIterator(CSysMdbConnectorInfoIterator *pBaseIterator1,CSysMdbConnectorInfoIterator *pBaseIterator2)
		:CSysMdbConnectorInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbConnectorInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbConnectorInfo
	///@return	下一个满足条件CSysMdbConnectorInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbConnectorInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbConnectorInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQuerySingleIterator是至多返回一个数据库查询应答的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQuerySingleIterator: public CSysMdbDBQueryIterator
{
private:
	CSysMdbDBQuery *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbDBQuerySingleIterator(CSysMdbDBQueryFactory *pFactory,CSysMdbDBQuery *pResult)
		:CSysMdbDBQueryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbDBQuerySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbDBQuery
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDBQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryPredict是判断一个数据库查询应答是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryPredict
{
public:
	///判断是否合法
	///@param	pSysMdbDBQuery	要被判断的数据库查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryAndPredict是对两个数据库查询应答谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryAndPredict : public CSysMdbDBQueryPredict
{
private:
	CSysMdbDBQueryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbDBQueryAndPredict(CSysMdbDBQueryPredict *p1, CSysMdbDBQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbDBQueryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbDBQuery	要被判断的数据库查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return m_p1->isValid(pSysMdbDBQuery) && m_p2->isValid(pSysMdbDBQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryOrPredict是对两个数据库查询应答谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryOrPredict : public CSysMdbDBQueryPredict
{
private:
	CSysMdbDBQueryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbDBQueryOrPredict(CSysMdbDBQueryPredict *p1, CSysMdbDBQueryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbDBQueryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbDBQuery	要被判断的数据库查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return m_p1->isValid(pSysMdbDBQuery) || m_p2->isValid(pSysMdbDBQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryNotPredict是对一个数据库查询应答谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryNotPredict : public CSysMdbDBQueryPredict
{
private:
	CSysMdbDBQueryPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbDBQueryNotPredict(CSysMdbDBQueryPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbDBQueryNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbDBQuery	要被判断的数据库查询应答
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return !m_predict->isValid(pSysMdbDBQuery);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryFilter是一个对已有的数据库查询应答枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryFilter: public CSysMdbDBQueryIterator
{
private:
	CSysMdbDBQueryIterator *m_baseIterator;
	CSysMdbDBQueryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbDBQueryFilter(CSysMdbDBQueryIterator *pBaseIterator, CSysMdbDBQueryPredict *pPredict, bool continueResult=false)
		:CSysMdbDBQueryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbDBQueryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbDBQuery
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDBQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryLinkIterator是连接两个数据库查询应答枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryLinkIterator: public CSysMdbDBQueryIterator
{
private:
	CSysMdbDBQueryIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbDBQueryLinkIterator(CSysMdbDBQueryIterator *pBaseIterator1,CSysMdbDBQueryIterator *pBaseIterator2)
		:CSysMdbDBQueryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbDBQueryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbDBQuery
	///@return	下一个满足条件CSysMdbDBQuery，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDBQuery *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDBQuery 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetAreaSingleIterator是至多返回一个网络大区划分的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaSingleIterator: public CSysNetAreaIterator
{
private:
	CSysNetArea *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetAreaSingleIterator(CSysNetAreaFactory *pFactory,CSysNetArea *pResult)
		:CSysNetAreaIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetAreaSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetArea
	///@return	下一个满足条件CSysNetArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaPredict是判断一个网络大区划分是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaPredict
{
public:
	///判断是否合法
	///@param	pSysNetArea	要被判断的网络大区划分
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetArea *pSysNetArea)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaAndPredict是对两个网络大区划分谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaAndPredict : public CSysNetAreaPredict
{
private:
	CSysNetAreaPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetAreaAndPredict(CSysNetAreaPredict *p1, CSysNetAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetAreaAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetArea	要被判断的网络大区划分
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetArea *pSysNetArea)
	{
		return m_p1->isValid(pSysNetArea) && m_p2->isValid(pSysNetArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaOrPredict是对两个网络大区划分谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaOrPredict : public CSysNetAreaPredict
{
private:
	CSysNetAreaPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetAreaOrPredict(CSysNetAreaPredict *p1, CSysNetAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetAreaOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetArea	要被判断的网络大区划分
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetArea *pSysNetArea)
	{
		return m_p1->isValid(pSysNetArea) || m_p2->isValid(pSysNetArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaNotPredict是对一个网络大区划分谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaNotPredict : public CSysNetAreaPredict
{
private:
	CSysNetAreaPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetAreaNotPredict(CSysNetAreaPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetAreaNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetArea	要被判断的网络大区划分
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetArea *pSysNetArea)
	{
		return !m_predict->isValid(pSysNetArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaFilter是一个对已有的网络大区划分枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaFilter: public CSysNetAreaIterator
{
private:
	CSysNetAreaIterator *m_baseIterator;
	CSysNetAreaPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetAreaFilter(CSysNetAreaIterator *pBaseIterator, CSysNetAreaPredict *pPredict, bool continueResult=false)
		:CSysNetAreaIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetAreaFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetArea
	///@return	下一个满足条件CSysNetArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaLinkIterator是连接两个网络大区划分枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaLinkIterator: public CSysNetAreaIterator
{
private:
	CSysNetAreaIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetAreaLinkIterator(CSysNetAreaIterator *pBaseIterator1,CSysNetAreaIterator *pBaseIterator2)
		:CSysNetAreaIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetAreaLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetArea
	///@return	下一个满足条件CSysNetArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaSingleIterator是至多返回一个网络子区的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaSingleIterator: public CSysNetSubAreaIterator
{
private:
	CSysNetSubArea *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetSubAreaSingleIterator(CSysNetSubAreaFactory *pFactory,CSysNetSubArea *pResult)
		:CSysNetSubAreaIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetSubAreaSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetSubArea
	///@return	下一个满足条件CSysNetSubArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaPredict是判断一个网络子区是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaPredict
{
public:
	///判断是否合法
	///@param	pSysNetSubArea	要被判断的网络子区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaAndPredict是对两个网络子区谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaAndPredict : public CSysNetSubAreaPredict
{
private:
	CSysNetSubAreaPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetSubAreaAndPredict(CSysNetSubAreaPredict *p1, CSysNetSubAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetSubAreaAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetSubArea	要被判断的网络子区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)
	{
		return m_p1->isValid(pSysNetSubArea) && m_p2->isValid(pSysNetSubArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaOrPredict是对两个网络子区谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaOrPredict : public CSysNetSubAreaPredict
{
private:
	CSysNetSubAreaPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetSubAreaOrPredict(CSysNetSubAreaPredict *p1, CSysNetSubAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetSubAreaOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetSubArea	要被判断的网络子区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)
	{
		return m_p1->isValid(pSysNetSubArea) || m_p2->isValid(pSysNetSubArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaNotPredict是对一个网络子区谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaNotPredict : public CSysNetSubAreaPredict
{
private:
	CSysNetSubAreaPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetSubAreaNotPredict(CSysNetSubAreaPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetSubAreaNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetSubArea	要被判断的网络子区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubArea *pSysNetSubArea)
	{
		return !m_predict->isValid(pSysNetSubArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaFilter是一个对已有的网络子区枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaFilter: public CSysNetSubAreaIterator
{
private:
	CSysNetSubAreaIterator *m_baseIterator;
	CSysNetSubAreaPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetSubAreaFilter(CSysNetSubAreaIterator *pBaseIterator, CSysNetSubAreaPredict *pPredict, bool continueResult=false)
		:CSysNetSubAreaIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetSubAreaFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetSubArea
	///@return	下一个满足条件CSysNetSubArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaLinkIterator是连接两个网络子区枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaLinkIterator: public CSysNetSubAreaIterator
{
private:
	CSysNetSubAreaIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetSubAreaLinkIterator(CSysNetSubAreaIterator *pBaseIterator1,CSysNetSubAreaIterator *pBaseIterator2)
		:CSysNetSubAreaIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetSubAreaLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetSubArea
	///@return	下一个满足条件CSysNetSubArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPSingleIterator是至多返回一个网络子区IP的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPSingleIterator: public CSysNetSubAreaIPIterator
{
private:
	CSysNetSubAreaIP *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetSubAreaIPSingleIterator(CSysNetSubAreaIPFactory *pFactory,CSysNetSubAreaIP *pResult)
		:CSysNetSubAreaIPIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetSubAreaIPSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetSubAreaIP
	///@return	下一个满足条件CSysNetSubAreaIP，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubAreaIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPPredict是判断一个网络子区IP是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPPredict
{
public:
	///判断是否合法
	///@param	pSysNetSubAreaIP	要被判断的网络子区IP
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPAndPredict是对两个网络子区IP谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPAndPredict : public CSysNetSubAreaIPPredict
{
private:
	CSysNetSubAreaIPPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetSubAreaIPAndPredict(CSysNetSubAreaIPPredict *p1, CSysNetSubAreaIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetSubAreaIPAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetSubAreaIP	要被判断的网络子区IP
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return m_p1->isValid(pSysNetSubAreaIP) && m_p2->isValid(pSysNetSubAreaIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPOrPredict是对两个网络子区IP谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPOrPredict : public CSysNetSubAreaIPPredict
{
private:
	CSysNetSubAreaIPPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetSubAreaIPOrPredict(CSysNetSubAreaIPPredict *p1, CSysNetSubAreaIPPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetSubAreaIPOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetSubAreaIP	要被判断的网络子区IP
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return m_p1->isValid(pSysNetSubAreaIP) || m_p2->isValid(pSysNetSubAreaIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPNotPredict是对一个网络子区IP谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPNotPredict : public CSysNetSubAreaIPPredict
{
private:
	CSysNetSubAreaIPPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetSubAreaIPNotPredict(CSysNetSubAreaIPPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetSubAreaIPNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetSubAreaIP	要被判断的网络子区IP
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return !m_predict->isValid(pSysNetSubAreaIP);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPFilter是一个对已有的网络子区IP枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPFilter: public CSysNetSubAreaIPIterator
{
private:
	CSysNetSubAreaIPIterator *m_baseIterator;
	CSysNetSubAreaIPPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetSubAreaIPFilter(CSysNetSubAreaIPIterator *pBaseIterator, CSysNetSubAreaIPPredict *pPredict, bool continueResult=false)
		:CSysNetSubAreaIPIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetSubAreaIPFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetSubAreaIP
	///@return	下一个满足条件CSysNetSubAreaIP，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubAreaIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPLinkIterator是连接两个网络子区IP枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPLinkIterator: public CSysNetSubAreaIPIterator
{
private:
	CSysNetSubAreaIPIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetSubAreaIPLinkIterator(CSysNetSubAreaIPIterator *pBaseIterator1,CSysNetSubAreaIPIterator *pBaseIterator2)
		:CSysNetSubAreaIPIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetSubAreaIPLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetSubAreaIP
	///@return	下一个满足条件CSysNetSubAreaIP，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubAreaIP *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubAreaIP 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaSingleIterator是至多返回一个职能区的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaSingleIterator: public CSysNetFuncAreaIterator
{
private:
	CSysNetFuncArea *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetFuncAreaSingleIterator(CSysNetFuncAreaFactory *pFactory,CSysNetFuncArea *pResult)
		:CSysNetFuncAreaIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetFuncAreaSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetFuncArea
	///@return	下一个满足条件CSysNetFuncArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetFuncArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetFuncArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaPredict是判断一个职能区是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaPredict
{
public:
	///判断是否合法
	///@param	pSysNetFuncArea	要被判断的职能区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaAndPredict是对两个职能区谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaAndPredict : public CSysNetFuncAreaPredict
{
private:
	CSysNetFuncAreaPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetFuncAreaAndPredict(CSysNetFuncAreaPredict *p1, CSysNetFuncAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetFuncAreaAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetFuncArea	要被判断的职能区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)
	{
		return m_p1->isValid(pSysNetFuncArea) && m_p2->isValid(pSysNetFuncArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaOrPredict是对两个职能区谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaOrPredict : public CSysNetFuncAreaPredict
{
private:
	CSysNetFuncAreaPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetFuncAreaOrPredict(CSysNetFuncAreaPredict *p1, CSysNetFuncAreaPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetFuncAreaOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetFuncArea	要被判断的职能区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)
	{
		return m_p1->isValid(pSysNetFuncArea) || m_p2->isValid(pSysNetFuncArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaNotPredict是对一个职能区谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaNotPredict : public CSysNetFuncAreaPredict
{
private:
	CSysNetFuncAreaPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetFuncAreaNotPredict(CSysNetFuncAreaPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetFuncAreaNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetFuncArea	要被判断的职能区
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetFuncArea *pSysNetFuncArea)
	{
		return !m_predict->isValid(pSysNetFuncArea);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaFilter是一个对已有的职能区枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaFilter: public CSysNetFuncAreaIterator
{
private:
	CSysNetFuncAreaIterator *m_baseIterator;
	CSysNetFuncAreaPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetFuncAreaFilter(CSysNetFuncAreaIterator *pBaseIterator, CSysNetFuncAreaPredict *pPredict, bool continueResult=false)
		:CSysNetFuncAreaIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetFuncAreaFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetFuncArea
	///@return	下一个满足条件CSysNetFuncArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetFuncArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetFuncArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaLinkIterator是连接两个职能区枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaLinkIterator: public CSysNetFuncAreaIterator
{
private:
	CSysNetFuncAreaIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetFuncAreaLinkIterator(CSysNetFuncAreaIterator *pBaseIterator1,CSysNetFuncAreaIterator *pBaseIterator2)
		:CSysNetFuncAreaIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetFuncAreaLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetFuncArea
	///@return	下一个满足条件CSysNetFuncArea，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetFuncArea *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetFuncArea 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceSingleIterator是至多返回一个网络设备的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceSingleIterator: public CSysNetDeviceIterator
{
private:
	CSysNetDevice *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetDeviceSingleIterator(CSysNetDeviceFactory *pFactory,CSysNetDevice *pResult)
		:CSysNetDeviceIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetDeviceSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetDevice
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDevice *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDevice 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDevicePredict是判断一个网络设备是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDevicePredict
{
public:
	///判断是否合法
	///@param	pSysNetDevice	要被判断的网络设备
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDevice *pSysNetDevice)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceAndPredict是对两个网络设备谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceAndPredict : public CSysNetDevicePredict
{
private:
	CSysNetDevicePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceAndPredict(CSysNetDevicePredict *p1, CSysNetDevicePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDevice	要被判断的网络设备
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDevice *pSysNetDevice)
	{
		return m_p1->isValid(pSysNetDevice) && m_p2->isValid(pSysNetDevice);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceOrPredict是对两个网络设备谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceOrPredict : public CSysNetDevicePredict
{
private:
	CSysNetDevicePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceOrPredict(CSysNetDevicePredict *p1, CSysNetDevicePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDevice	要被判断的网络设备
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDevice *pSysNetDevice)
	{
		return m_p1->isValid(pSysNetDevice) || m_p2->isValid(pSysNetDevice);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceNotPredict是对一个网络设备谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceNotPredict : public CSysNetDevicePredict
{
private:
	CSysNetDevicePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetDeviceNotPredict(CSysNetDevicePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetDeviceNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetDevice	要被判断的网络设备
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDevice *pSysNetDevice)
	{
		return !m_predict->isValid(pSysNetDevice);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceFilter是一个对已有的网络设备枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceFilter: public CSysNetDeviceIterator
{
private:
	CSysNetDeviceIterator *m_baseIterator;
	CSysNetDevicePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetDeviceFilter(CSysNetDeviceIterator *pBaseIterator, CSysNetDevicePredict *pPredict, bool continueResult=false)
		:CSysNetDeviceIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetDeviceFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetDevice
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDevice *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDevice 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkIterator是连接两个网络设备枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkIterator: public CSysNetDeviceIterator
{
private:
	CSysNetDeviceIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetDeviceLinkIterator(CSysNetDeviceIterator *pBaseIterator1,CSysNetDeviceIterator *pBaseIterator2)
		:CSysNetDeviceIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetDeviceLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetDevice
	///@return	下一个满足条件CSysNetDevice，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDevice *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDevice 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedSingleIterator是至多返回一个网络设备连接关系的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedSingleIterator: public CSysNetDeviceLinkedIterator
{
private:
	CSysNetDeviceLinked *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetDeviceLinkedSingleIterator(CSysNetDeviceLinkedFactory *pFactory,CSysNetDeviceLinked *pResult)
		:CSysNetDeviceLinkedIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetDeviceLinkedSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetDeviceLinked
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceLinked 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedPredict是判断一个网络设备连接关系是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedPredict
{
public:
	///判断是否合法
	///@param	pSysNetDeviceLinked	要被判断的网络设备连接关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedAndPredict是对两个网络设备连接关系谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedAndPredict : public CSysNetDeviceLinkedPredict
{
private:
	CSysNetDeviceLinkedPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceLinkedAndPredict(CSysNetDeviceLinkedPredict *p1, CSysNetDeviceLinkedPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceLinkedAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDeviceLinked	要被判断的网络设备连接关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return m_p1->isValid(pSysNetDeviceLinked) && m_p2->isValid(pSysNetDeviceLinked);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedOrPredict是对两个网络设备连接关系谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedOrPredict : public CSysNetDeviceLinkedPredict
{
private:
	CSysNetDeviceLinkedPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceLinkedOrPredict(CSysNetDeviceLinkedPredict *p1, CSysNetDeviceLinkedPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceLinkedOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDeviceLinked	要被判断的网络设备连接关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return m_p1->isValid(pSysNetDeviceLinked) || m_p2->isValid(pSysNetDeviceLinked);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedNotPredict是对一个网络设备连接关系谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedNotPredict : public CSysNetDeviceLinkedPredict
{
private:
	CSysNetDeviceLinkedPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetDeviceLinkedNotPredict(CSysNetDeviceLinkedPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetDeviceLinkedNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetDeviceLinked	要被判断的网络设备连接关系
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return !m_predict->isValid(pSysNetDeviceLinked);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedFilter是一个对已有的网络设备连接关系枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedFilter: public CSysNetDeviceLinkedIterator
{
private:
	CSysNetDeviceLinkedIterator *m_baseIterator;
	CSysNetDeviceLinkedPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetDeviceLinkedFilter(CSysNetDeviceLinkedIterator *pBaseIterator, CSysNetDeviceLinkedPredict *pPredict, bool continueResult=false)
		:CSysNetDeviceLinkedIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetDeviceLinkedFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetDeviceLinked
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceLinked 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedLinkIterator是连接两个网络设备连接关系枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedLinkIterator: public CSysNetDeviceLinkedIterator
{
private:
	CSysNetDeviceLinkedIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetDeviceLinkedLinkIterator(CSysNetDeviceLinkedIterator *pBaseIterator1,CSysNetDeviceLinkedIterator *pBaseIterator2)
		:CSysNetDeviceLinkedIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetDeviceLinkedLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetDeviceLinked
	///@return	下一个满足条件CSysNetDeviceLinked，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceLinked *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceLinked 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetOIDSingleIterator是至多返回一个OID的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDSingleIterator: public CSysNetOIDIterator
{
private:
	CSysNetOID *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetOIDSingleIterator(CSysNetOIDFactory *pFactory,CSysNetOID *pResult)
		:CSysNetOIDIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetOIDSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetOID
	///@return	下一个满足条件CSysNetOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDPredict是判断一个OID是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDPredict
{
public:
	///判断是否合法
	///@param	pSysNetOID	要被判断的OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOID *pSysNetOID)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDAndPredict是对两个OID谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDAndPredict : public CSysNetOIDPredict
{
private:
	CSysNetOIDPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetOIDAndPredict(CSysNetOIDPredict *p1, CSysNetOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetOIDAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetOID	要被判断的OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOID *pSysNetOID)
	{
		return m_p1->isValid(pSysNetOID) && m_p2->isValid(pSysNetOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDOrPredict是对两个OID谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDOrPredict : public CSysNetOIDPredict
{
private:
	CSysNetOIDPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetOIDOrPredict(CSysNetOIDPredict *p1, CSysNetOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetOIDOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetOID	要被判断的OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOID *pSysNetOID)
	{
		return m_p1->isValid(pSysNetOID) || m_p2->isValid(pSysNetOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDNotPredict是对一个OID谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDNotPredict : public CSysNetOIDPredict
{
private:
	CSysNetOIDPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetOIDNotPredict(CSysNetOIDPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetOIDNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetOID	要被判断的OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOID *pSysNetOID)
	{
		return !m_predict->isValid(pSysNetOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDFilter是一个对已有的OID枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDFilter: public CSysNetOIDIterator
{
private:
	CSysNetOIDIterator *m_baseIterator;
	CSysNetOIDPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetOIDFilter(CSysNetOIDIterator *pBaseIterator, CSysNetOIDPredict *pPredict, bool continueResult=false)
		:CSysNetOIDIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetOIDFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetOID
	///@return	下一个满足条件CSysNetOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDLinkIterator是连接两个OID枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDLinkIterator: public CSysNetOIDIterator
{
private:
	CSysNetOIDIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetOIDLinkIterator(CSysNetOIDIterator *pBaseIterator1,CSysNetOIDIterator *pBaseIterator2)
		:CSysNetOIDIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetOIDLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetOID
	///@return	下一个满足条件CSysNetOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeSingleIterator是至多返回一个网络设备类型的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeSingleIterator: public CSysNetDeviceTypeIterator
{
private:
	CSysNetDeviceType *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetDeviceTypeSingleIterator(CSysNetDeviceTypeFactory *pFactory,CSysNetDeviceType *pResult)
		:CSysNetDeviceTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetDeviceTypeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetDeviceType
	///@return	下一个满足条件CSysNetDeviceType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypePredict是判断一个网络设备类型是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypePredict
{
public:
	///判断是否合法
	///@param	pSysNetDeviceType	要被判断的网络设备类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeAndPredict是对两个网络设备类型谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeAndPredict : public CSysNetDeviceTypePredict
{
private:
	CSysNetDeviceTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceTypeAndPredict(CSysNetDeviceTypePredict *p1, CSysNetDeviceTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDeviceType	要被判断的网络设备类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)
	{
		return m_p1->isValid(pSysNetDeviceType) && m_p2->isValid(pSysNetDeviceType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeOrPredict是对两个网络设备类型谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeOrPredict : public CSysNetDeviceTypePredict
{
private:
	CSysNetDeviceTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceTypeOrPredict(CSysNetDeviceTypePredict *p1, CSysNetDeviceTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDeviceType	要被判断的网络设备类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)
	{
		return m_p1->isValid(pSysNetDeviceType) || m_p2->isValid(pSysNetDeviceType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeNotPredict是对一个网络设备类型谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeNotPredict : public CSysNetDeviceTypePredict
{
private:
	CSysNetDeviceTypePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetDeviceTypeNotPredict(CSysNetDeviceTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetDeviceTypeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetDeviceType	要被判断的网络设备类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceType *pSysNetDeviceType)
	{
		return !m_predict->isValid(pSysNetDeviceType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeFilter是一个对已有的网络设备类型枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeFilter: public CSysNetDeviceTypeIterator
{
private:
	CSysNetDeviceTypeIterator *m_baseIterator;
	CSysNetDeviceTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetDeviceTypeFilter(CSysNetDeviceTypeIterator *pBaseIterator, CSysNetDeviceTypePredict *pPredict, bool continueResult=false)
		:CSysNetDeviceTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetDeviceTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetDeviceType
	///@return	下一个满足条件CSysNetDeviceType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeLinkIterator是连接两个网络设备类型枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeLinkIterator: public CSysNetDeviceTypeIterator
{
private:
	CSysNetDeviceTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetDeviceTypeLinkIterator(CSysNetDeviceTypeIterator *pBaseIterator1,CSysNetDeviceTypeIterator *pBaseIterator2)
		:CSysNetDeviceTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetDeviceTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetDeviceType
	///@return	下一个满足条件CSysNetDeviceType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicySingleIterator是至多返回一个时间策略的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicySingleIterator: public CSysNetTimePolicyIterator
{
private:
	CSysNetTimePolicy *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetTimePolicySingleIterator(CSysNetTimePolicyFactory *pFactory,CSysNetTimePolicy *pResult)
		:CSysNetTimePolicyIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetTimePolicySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetTimePolicy
	///@return	下一个满足条件CSysNetTimePolicy，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetTimePolicy *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetTimePolicy 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyPredict是判断一个时间策略是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyPredict
{
public:
	///判断是否合法
	///@param	pSysNetTimePolicy	要被判断的时间策略
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyAndPredict是对两个时间策略谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyAndPredict : public CSysNetTimePolicyPredict
{
private:
	CSysNetTimePolicyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetTimePolicyAndPredict(CSysNetTimePolicyPredict *p1, CSysNetTimePolicyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetTimePolicyAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetTimePolicy	要被判断的时间策略
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return m_p1->isValid(pSysNetTimePolicy) && m_p2->isValid(pSysNetTimePolicy);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyOrPredict是对两个时间策略谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyOrPredict : public CSysNetTimePolicyPredict
{
private:
	CSysNetTimePolicyPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetTimePolicyOrPredict(CSysNetTimePolicyPredict *p1, CSysNetTimePolicyPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetTimePolicyOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetTimePolicy	要被判断的时间策略
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return m_p1->isValid(pSysNetTimePolicy) || m_p2->isValid(pSysNetTimePolicy);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyNotPredict是对一个时间策略谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyNotPredict : public CSysNetTimePolicyPredict
{
private:
	CSysNetTimePolicyPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetTimePolicyNotPredict(CSysNetTimePolicyPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetTimePolicyNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetTimePolicy	要被判断的时间策略
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return !m_predict->isValid(pSysNetTimePolicy);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyFilter是一个对已有的时间策略枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyFilter: public CSysNetTimePolicyIterator
{
private:
	CSysNetTimePolicyIterator *m_baseIterator;
	CSysNetTimePolicyPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetTimePolicyFilter(CSysNetTimePolicyIterator *pBaseIterator, CSysNetTimePolicyPredict *pPredict, bool continueResult=false)
		:CSysNetTimePolicyIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetTimePolicyFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetTimePolicy
	///@return	下一个满足条件CSysNetTimePolicy，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetTimePolicy *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetTimePolicy 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyLinkIterator是连接两个时间策略枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyLinkIterator: public CSysNetTimePolicyIterator
{
private:
	CSysNetTimePolicyIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetTimePolicyLinkIterator(CSysNetTimePolicyIterator *pBaseIterator1,CSysNetTimePolicyIterator *pBaseIterator2)
		:CSysNetTimePolicyIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetTimePolicyLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetTimePolicy
	///@return	下一个满足条件CSysNetTimePolicy，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetTimePolicy *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetTimePolicy 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskSingleIterator是至多返回一个采集任务的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskSingleIterator: public CSysNetGatherTaskIterator
{
private:
	CSysNetGatherTask *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetGatherTaskSingleIterator(CSysNetGatherTaskFactory *pFactory,CSysNetGatherTask *pResult)
		:CSysNetGatherTaskIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetGatherTaskSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetGatherTask
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGatherTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGatherTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskPredict是判断一个采集任务是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskPredict
{
public:
	///判断是否合法
	///@param	pSysNetGatherTask	要被判断的采集任务
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskAndPredict是对两个采集任务谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskAndPredict : public CSysNetGatherTaskPredict
{
private:
	CSysNetGatherTaskPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetGatherTaskAndPredict(CSysNetGatherTaskPredict *p1, CSysNetGatherTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetGatherTaskAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetGatherTask	要被判断的采集任务
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)
	{
		return m_p1->isValid(pSysNetGatherTask) && m_p2->isValid(pSysNetGatherTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskOrPredict是对两个采集任务谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskOrPredict : public CSysNetGatherTaskPredict
{
private:
	CSysNetGatherTaskPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetGatherTaskOrPredict(CSysNetGatherTaskPredict *p1, CSysNetGatherTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetGatherTaskOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetGatherTask	要被判断的采集任务
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)
	{
		return m_p1->isValid(pSysNetGatherTask) || m_p2->isValid(pSysNetGatherTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskNotPredict是对一个采集任务谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskNotPredict : public CSysNetGatherTaskPredict
{
private:
	CSysNetGatherTaskPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetGatherTaskNotPredict(CSysNetGatherTaskPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetGatherTaskNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetGatherTask	要被判断的采集任务
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGatherTask *pSysNetGatherTask)
	{
		return !m_predict->isValid(pSysNetGatherTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskFilter是一个对已有的采集任务枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskFilter: public CSysNetGatherTaskIterator
{
private:
	CSysNetGatherTaskIterator *m_baseIterator;
	CSysNetGatherTaskPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetGatherTaskFilter(CSysNetGatherTaskIterator *pBaseIterator, CSysNetGatherTaskPredict *pPredict, bool continueResult=false)
		:CSysNetGatherTaskIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetGatherTaskFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetGatherTask
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGatherTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGatherTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskLinkIterator是连接两个采集任务枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskLinkIterator: public CSysNetGatherTaskIterator
{
private:
	CSysNetGatherTaskIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetGatherTaskLinkIterator(CSysNetGatherTaskIterator *pBaseIterator1,CSysNetGatherTaskIterator *pBaseIterator2)
		:CSysNetGatherTaskIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetGatherTaskLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetGatherTask
	///@return	下一个满足条件CSysNetGatherTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGatherTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGatherTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategorySingleIterator是至多返回一个常用设备类别的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategorySingleIterator: public CSysNetDeviceCategoryIterator
{
private:
	CSysNetDeviceCategory *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetDeviceCategorySingleIterator(CSysNetDeviceCategoryFactory *pFactory,CSysNetDeviceCategory *pResult)
		:CSysNetDeviceCategoryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetDeviceCategorySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetDeviceCategory
	///@return	下一个满足条件CSysNetDeviceCategory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceCategory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryPredict是判断一个常用设备类别是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryPredict
{
public:
	///判断是否合法
	///@param	pSysNetDeviceCategory	要被判断的常用设备类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryAndPredict是对两个常用设备类别谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryAndPredict : public CSysNetDeviceCategoryPredict
{
private:
	CSysNetDeviceCategoryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceCategoryAndPredict(CSysNetDeviceCategoryPredict *p1, CSysNetDeviceCategoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceCategoryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDeviceCategory	要被判断的常用设备类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return m_p1->isValid(pSysNetDeviceCategory) && m_p2->isValid(pSysNetDeviceCategory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryOrPredict是对两个常用设备类别谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryOrPredict : public CSysNetDeviceCategoryPredict
{
private:
	CSysNetDeviceCategoryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDeviceCategoryOrPredict(CSysNetDeviceCategoryPredict *p1, CSysNetDeviceCategoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDeviceCategoryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDeviceCategory	要被判断的常用设备类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return m_p1->isValid(pSysNetDeviceCategory) || m_p2->isValid(pSysNetDeviceCategory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryNotPredict是对一个常用设备类别谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryNotPredict : public CSysNetDeviceCategoryPredict
{
private:
	CSysNetDeviceCategoryPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetDeviceCategoryNotPredict(CSysNetDeviceCategoryPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetDeviceCategoryNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetDeviceCategory	要被判断的常用设备类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return !m_predict->isValid(pSysNetDeviceCategory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryFilter是一个对已有的常用设备类别枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryFilter: public CSysNetDeviceCategoryIterator
{
private:
	CSysNetDeviceCategoryIterator *m_baseIterator;
	CSysNetDeviceCategoryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetDeviceCategoryFilter(CSysNetDeviceCategoryIterator *pBaseIterator, CSysNetDeviceCategoryPredict *pPredict, bool continueResult=false)
		:CSysNetDeviceCategoryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetDeviceCategoryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetDeviceCategory
	///@return	下一个满足条件CSysNetDeviceCategory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceCategory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryLinkIterator是连接两个常用设备类别枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryLinkIterator: public CSysNetDeviceCategoryIterator
{
private:
	CSysNetDeviceCategoryIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetDeviceCategoryLinkIterator(CSysNetDeviceCategoryIterator *pBaseIterator1,CSysNetDeviceCategoryIterator *pBaseIterator2)
		:CSysNetDeviceCategoryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetDeviceCategoryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetDeviceCategory
	///@return	下一个满足条件CSysNetDeviceCategory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDeviceCategory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDeviceCategory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetManufactorySingleIterator是至多返回一个设备厂商的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactorySingleIterator: public CSysNetManufactoryIterator
{
private:
	CSysNetManufactory *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetManufactorySingleIterator(CSysNetManufactoryFactory *pFactory,CSysNetManufactory *pResult)
		:CSysNetManufactoryIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetManufactorySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetManufactory
	///@return	下一个满足条件CSysNetManufactory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetManufactory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetManufactory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryPredict是判断一个设备厂商是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryPredict
{
public:
	///判断是否合法
	///@param	pSysNetManufactory	要被判断的设备厂商
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryAndPredict是对两个设备厂商谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryAndPredict : public CSysNetManufactoryPredict
{
private:
	CSysNetManufactoryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetManufactoryAndPredict(CSysNetManufactoryPredict *p1, CSysNetManufactoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetManufactoryAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetManufactory	要被判断的设备厂商
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)
	{
		return m_p1->isValid(pSysNetManufactory) && m_p2->isValid(pSysNetManufactory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryOrPredict是对两个设备厂商谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryOrPredict : public CSysNetManufactoryPredict
{
private:
	CSysNetManufactoryPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetManufactoryOrPredict(CSysNetManufactoryPredict *p1, CSysNetManufactoryPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetManufactoryOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetManufactory	要被判断的设备厂商
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)
	{
		return m_p1->isValid(pSysNetManufactory) || m_p2->isValid(pSysNetManufactory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryNotPredict是对一个设备厂商谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryNotPredict : public CSysNetManufactoryPredict
{
private:
	CSysNetManufactoryPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetManufactoryNotPredict(CSysNetManufactoryPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetManufactoryNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetManufactory	要被判断的设备厂商
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetManufactory *pSysNetManufactory)
	{
		return !m_predict->isValid(pSysNetManufactory);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryFilter是一个对已有的设备厂商枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryFilter: public CSysNetManufactoryIterator
{
private:
	CSysNetManufactoryIterator *m_baseIterator;
	CSysNetManufactoryPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetManufactoryFilter(CSysNetManufactoryIterator *pBaseIterator, CSysNetManufactoryPredict *pPredict, bool continueResult=false)
		:CSysNetManufactoryIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetManufactoryFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetManufactory
	///@return	下一个满足条件CSysNetManufactory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetManufactory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetManufactory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryLinkIterator是连接两个设备厂商枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryLinkIterator: public CSysNetManufactoryIterator
{
private:
	CSysNetManufactoryIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetManufactoryLinkIterator(CSysNetManufactoryIterator *pBaseIterator1,CSysNetManufactoryIterator *pBaseIterator2)
		:CSysNetManufactoryIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetManufactoryLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetManufactory
	///@return	下一个满足条件CSysNetManufactory，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetManufactory *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetManufactory 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetCommunitySingleIterator是至多返回一个设备共同体的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunitySingleIterator: public CSysNetCommunityIterator
{
private:
	CSysNetCommunity *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetCommunitySingleIterator(CSysNetCommunityFactory *pFactory,CSysNetCommunity *pResult)
		:CSysNetCommunityIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetCommunitySingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetCommunity
	///@return	下一个满足条件CSysNetCommunity，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetCommunity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetCommunity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityPredict是判断一个设备共同体是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityPredict
{
public:
	///判断是否合法
	///@param	pSysNetCommunity	要被判断的设备共同体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityAndPredict是对两个设备共同体谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityAndPredict : public CSysNetCommunityPredict
{
private:
	CSysNetCommunityPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetCommunityAndPredict(CSysNetCommunityPredict *p1, CSysNetCommunityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetCommunityAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetCommunity	要被判断的设备共同体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)
	{
		return m_p1->isValid(pSysNetCommunity) && m_p2->isValid(pSysNetCommunity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityOrPredict是对两个设备共同体谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityOrPredict : public CSysNetCommunityPredict
{
private:
	CSysNetCommunityPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetCommunityOrPredict(CSysNetCommunityPredict *p1, CSysNetCommunityPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetCommunityOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetCommunity	要被判断的设备共同体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)
	{
		return m_p1->isValid(pSysNetCommunity) || m_p2->isValid(pSysNetCommunity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityNotPredict是对一个设备共同体谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityNotPredict : public CSysNetCommunityPredict
{
private:
	CSysNetCommunityPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetCommunityNotPredict(CSysNetCommunityPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetCommunityNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetCommunity	要被判断的设备共同体
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetCommunity *pSysNetCommunity)
	{
		return !m_predict->isValid(pSysNetCommunity);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityFilter是一个对已有的设备共同体枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityFilter: public CSysNetCommunityIterator
{
private:
	CSysNetCommunityIterator *m_baseIterator;
	CSysNetCommunityPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetCommunityFilter(CSysNetCommunityIterator *pBaseIterator, CSysNetCommunityPredict *pPredict, bool continueResult=false)
		:CSysNetCommunityIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetCommunityFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetCommunity
	///@return	下一个满足条件CSysNetCommunity，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetCommunity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetCommunity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityLinkIterator是连接两个设备共同体枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityLinkIterator: public CSysNetCommunityIterator
{
private:
	CSysNetCommunityIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetCommunityLinkIterator(CSysNetCommunityIterator *pBaseIterator1,CSysNetCommunityIterator *pBaseIterator2)
		:CSysNetCommunityIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetCommunityLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetCommunity
	///@return	下一个满足条件CSysNetCommunity，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetCommunity *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetCommunity 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeSingleIterator是至多返回一个端口类型的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeSingleIterator: public CSysNetPortTypeIterator
{
private:
	CSysNetPortType *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetPortTypeSingleIterator(CSysNetPortTypeFactory *pFactory,CSysNetPortType *pResult)
		:CSysNetPortTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetPortTypeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetPortType
	///@return	下一个满足条件CSysNetPortType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPortType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPortType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypePredict是判断一个端口类型是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypePredict
{
public:
	///判断是否合法
	///@param	pSysNetPortType	要被判断的端口类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPortType *pSysNetPortType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeAndPredict是对两个端口类型谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeAndPredict : public CSysNetPortTypePredict
{
private:
	CSysNetPortTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPortTypeAndPredict(CSysNetPortTypePredict *p1, CSysNetPortTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPortTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPortType	要被判断的端口类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPortType *pSysNetPortType)
	{
		return m_p1->isValid(pSysNetPortType) && m_p2->isValid(pSysNetPortType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeOrPredict是对两个端口类型谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeOrPredict : public CSysNetPortTypePredict
{
private:
	CSysNetPortTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPortTypeOrPredict(CSysNetPortTypePredict *p1, CSysNetPortTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPortTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPortType	要被判断的端口类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPortType *pSysNetPortType)
	{
		return m_p1->isValid(pSysNetPortType) || m_p2->isValid(pSysNetPortType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeNotPredict是对一个端口类型谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeNotPredict : public CSysNetPortTypePredict
{
private:
	CSysNetPortTypePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetPortTypeNotPredict(CSysNetPortTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetPortTypeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetPortType	要被判断的端口类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPortType *pSysNetPortType)
	{
		return !m_predict->isValid(pSysNetPortType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeFilter是一个对已有的端口类型枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeFilter: public CSysNetPortTypeIterator
{
private:
	CSysNetPortTypeIterator *m_baseIterator;
	CSysNetPortTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetPortTypeFilter(CSysNetPortTypeIterator *pBaseIterator, CSysNetPortTypePredict *pPredict, bool continueResult=false)
		:CSysNetPortTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetPortTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetPortType
	///@return	下一个满足条件CSysNetPortType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPortType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPortType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeLinkIterator是连接两个端口类型枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeLinkIterator: public CSysNetPortTypeIterator
{
private:
	CSysNetPortTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetPortTypeLinkIterator(CSysNetPortTypeIterator *pBaseIterator1,CSysNetPortTypeIterator *pBaseIterator2)
		:CSysNetPortTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetPortTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetPortType
	///@return	下一个满足条件CSysNetPortType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPortType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPortType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceSingleIterator是至多返回一个端口的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceSingleIterator: public CSysNetInterfaceIterator
{
private:
	CSysNetInterface *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetInterfaceSingleIterator(CSysNetInterfaceFactory *pFactory,CSysNetInterface *pResult)
		:CSysNetInterfaceIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetInterfaceSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetInterface
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetInterface *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetInterface 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfacePredict是判断一个端口是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfacePredict
{
public:
	///判断是否合法
	///@param	pSysNetInterface	要被判断的端口
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetInterface *pSysNetInterface)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceAndPredict是对两个端口谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceAndPredict : public CSysNetInterfacePredict
{
private:
	CSysNetInterfacePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetInterfaceAndPredict(CSysNetInterfacePredict *p1, CSysNetInterfacePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetInterfaceAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetInterface	要被判断的端口
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetInterface *pSysNetInterface)
	{
		return m_p1->isValid(pSysNetInterface) && m_p2->isValid(pSysNetInterface);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceOrPredict是对两个端口谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceOrPredict : public CSysNetInterfacePredict
{
private:
	CSysNetInterfacePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetInterfaceOrPredict(CSysNetInterfacePredict *p1, CSysNetInterfacePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetInterfaceOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetInterface	要被判断的端口
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetInterface *pSysNetInterface)
	{
		return m_p1->isValid(pSysNetInterface) || m_p2->isValid(pSysNetInterface);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceNotPredict是对一个端口谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceNotPredict : public CSysNetInterfacePredict
{
private:
	CSysNetInterfacePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetInterfaceNotPredict(CSysNetInterfacePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetInterfaceNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetInterface	要被判断的端口
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetInterface *pSysNetInterface)
	{
		return !m_predict->isValid(pSysNetInterface);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceFilter是一个对已有的端口枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceFilter: public CSysNetInterfaceIterator
{
private:
	CSysNetInterfaceIterator *m_baseIterator;
	CSysNetInterfacePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetInterfaceFilter(CSysNetInterfaceIterator *pBaseIterator, CSysNetInterfacePredict *pPredict, bool continueResult=false)
		:CSysNetInterfaceIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetInterfaceFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetInterface
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetInterface *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetInterface 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceLinkIterator是连接两个端口枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceLinkIterator: public CSysNetInterfaceIterator
{
private:
	CSysNetInterfaceIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetInterfaceLinkIterator(CSysNetInterfaceIterator *pBaseIterator1,CSysNetInterfaceIterator *pBaseIterator2)
		:CSysNetInterfaceIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetInterfaceLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetInterface
	///@return	下一个满足条件CSysNetInterface，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetInterface *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetInterface 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDSingleIterator是至多返回一个通用OID的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDSingleIterator: public CSysNetGeneralOIDIterator
{
private:
	CSysNetGeneralOID *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetGeneralOIDSingleIterator(CSysNetGeneralOIDFactory *pFactory,CSysNetGeneralOID *pResult)
		:CSysNetGeneralOIDIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetGeneralOIDSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetGeneralOID
	///@return	下一个满足条件CSysNetGeneralOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGeneralOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGeneralOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDPredict是判断一个通用OID是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDPredict
{
public:
	///判断是否合法
	///@param	pSysNetGeneralOID	要被判断的通用OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDAndPredict是对两个通用OID谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDAndPredict : public CSysNetGeneralOIDPredict
{
private:
	CSysNetGeneralOIDPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetGeneralOIDAndPredict(CSysNetGeneralOIDPredict *p1, CSysNetGeneralOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetGeneralOIDAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetGeneralOID	要被判断的通用OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return m_p1->isValid(pSysNetGeneralOID) && m_p2->isValid(pSysNetGeneralOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDOrPredict是对两个通用OID谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDOrPredict : public CSysNetGeneralOIDPredict
{
private:
	CSysNetGeneralOIDPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetGeneralOIDOrPredict(CSysNetGeneralOIDPredict *p1, CSysNetGeneralOIDPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetGeneralOIDOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetGeneralOID	要被判断的通用OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return m_p1->isValid(pSysNetGeneralOID) || m_p2->isValid(pSysNetGeneralOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDNotPredict是对一个通用OID谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDNotPredict : public CSysNetGeneralOIDPredict
{
private:
	CSysNetGeneralOIDPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetGeneralOIDNotPredict(CSysNetGeneralOIDPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetGeneralOIDNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetGeneralOID	要被判断的通用OID
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return !m_predict->isValid(pSysNetGeneralOID);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDFilter是一个对已有的通用OID枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDFilter: public CSysNetGeneralOIDIterator
{
private:
	CSysNetGeneralOIDIterator *m_baseIterator;
	CSysNetGeneralOIDPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetGeneralOIDFilter(CSysNetGeneralOIDIterator *pBaseIterator, CSysNetGeneralOIDPredict *pPredict, bool continueResult=false)
		:CSysNetGeneralOIDIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetGeneralOIDFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetGeneralOID
	///@return	下一个满足条件CSysNetGeneralOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGeneralOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGeneralOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDLinkIterator是连接两个通用OID枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDLinkIterator: public CSysNetGeneralOIDIterator
{
private:
	CSysNetGeneralOIDIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetGeneralOIDLinkIterator(CSysNetGeneralOIDIterator *pBaseIterator1,CSysNetGeneralOIDIterator *pBaseIterator2)
		:CSysNetGeneralOIDIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetGeneralOIDLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetGeneralOID
	///@return	下一个满足条件CSysNetGeneralOID，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetGeneralOID *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetGeneralOID 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeSingleIterator是至多返回一个监控对象类别的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeSingleIterator: public CSysNetMonitorTypeIterator
{
private:
	CSysNetMonitorType *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorTypeSingleIterator(CSysNetMonitorTypeFactory *pFactory,CSysNetMonitorType *pResult)
		:CSysNetMonitorTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorTypeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorType
	///@return	下一个满足条件CSysNetMonitorType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypePredict是判断一个监控对象类别是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypePredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorType	要被判断的监控对象类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeAndPredict是对两个监控对象类别谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeAndPredict : public CSysNetMonitorTypePredict
{
private:
	CSysNetMonitorTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTypeAndPredict(CSysNetMonitorTypePredict *p1, CSysNetMonitorTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorType	要被判断的监控对象类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)
	{
		return m_p1->isValid(pSysNetMonitorType) && m_p2->isValid(pSysNetMonitorType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeOrPredict是对两个监控对象类别谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeOrPredict : public CSysNetMonitorTypePredict
{
private:
	CSysNetMonitorTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTypeOrPredict(CSysNetMonitorTypePredict *p1, CSysNetMonitorTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorType	要被判断的监控对象类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)
	{
		return m_p1->isValid(pSysNetMonitorType) || m_p2->isValid(pSysNetMonitorType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeNotPredict是对一个监控对象类别谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeNotPredict : public CSysNetMonitorTypePredict
{
private:
	CSysNetMonitorTypePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorTypeNotPredict(CSysNetMonitorTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorTypeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorType	要被判断的监控对象类别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorType *pSysNetMonitorType)
	{
		return !m_predict->isValid(pSysNetMonitorType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeFilter是一个对已有的监控对象类别枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeFilter: public CSysNetMonitorTypeIterator
{
private:
	CSysNetMonitorTypeIterator *m_baseIterator;
	CSysNetMonitorTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorTypeFilter(CSysNetMonitorTypeIterator *pBaseIterator, CSysNetMonitorTypePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorType
	///@return	下一个满足条件CSysNetMonitorType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeLinkIterator是连接两个监控对象类别枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeLinkIterator: public CSysNetMonitorTypeIterator
{
private:
	CSysNetMonitorTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorTypeLinkIterator(CSysNetMonitorTypeIterator *pBaseIterator1,CSysNetMonitorTypeIterator *pBaseIterator2)
		:CSysNetMonitorTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorType
	///@return	下一个满足条件CSysNetMonitorType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeSingleIterator是至多返回一个指标统表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeSingleIterator: public CSysNetMonitorAttrScopeIterator
{
private:
	CSysNetMonitorAttrScope *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorAttrScopeSingleIterator(CSysNetMonitorAttrScopeFactory *pFactory,CSysNetMonitorAttrScope *pResult)
		:CSysNetMonitorAttrScopeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorAttrScopeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorAttrScope
	///@return	下一个满足条件CSysNetMonitorAttrScope，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrScope 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopePredict是判断一个指标统表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopePredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorAttrScope	要被判断的指标统表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeAndPredict是对两个指标统表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeAndPredict : public CSysNetMonitorAttrScopePredict
{
private:
	CSysNetMonitorAttrScopePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorAttrScopeAndPredict(CSysNetMonitorAttrScopePredict *p1, CSysNetMonitorAttrScopePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorAttrScopeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorAttrScope	要被判断的指标统表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return m_p1->isValid(pSysNetMonitorAttrScope) && m_p2->isValid(pSysNetMonitorAttrScope);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeOrPredict是对两个指标统表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeOrPredict : public CSysNetMonitorAttrScopePredict
{
private:
	CSysNetMonitorAttrScopePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorAttrScopeOrPredict(CSysNetMonitorAttrScopePredict *p1, CSysNetMonitorAttrScopePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorAttrScopeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorAttrScope	要被判断的指标统表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return m_p1->isValid(pSysNetMonitorAttrScope) || m_p2->isValid(pSysNetMonitorAttrScope);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeNotPredict是对一个指标统表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeNotPredict : public CSysNetMonitorAttrScopePredict
{
private:
	CSysNetMonitorAttrScopePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorAttrScopeNotPredict(CSysNetMonitorAttrScopePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorAttrScopeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorAttrScope	要被判断的指标统表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return !m_predict->isValid(pSysNetMonitorAttrScope);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeFilter是一个对已有的指标统表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeFilter: public CSysNetMonitorAttrScopeIterator
{
private:
	CSysNetMonitorAttrScopeIterator *m_baseIterator;
	CSysNetMonitorAttrScopePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorAttrScopeFilter(CSysNetMonitorAttrScopeIterator *pBaseIterator, CSysNetMonitorAttrScopePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorAttrScopeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorAttrScopeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorAttrScope
	///@return	下一个满足条件CSysNetMonitorAttrScope，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrScope 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeLinkIterator是连接两个指标统表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeLinkIterator: public CSysNetMonitorAttrScopeIterator
{
private:
	CSysNetMonitorAttrScopeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorAttrScopeLinkIterator(CSysNetMonitorAttrScopeIterator *pBaseIterator1,CSysNetMonitorAttrScopeIterator *pBaseIterator2)
		:CSysNetMonitorAttrScopeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorAttrScopeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorAttrScope
	///@return	下一个满足条件CSysNetMonitorAttrScope，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrScope *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrScope 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeSingleIterator是至多返回一个监控指标表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeSingleIterator: public CSysNetMonitorAttrTypeIterator
{
private:
	CSysNetMonitorAttrType *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorAttrTypeSingleIterator(CSysNetMonitorAttrTypeFactory *pFactory,CSysNetMonitorAttrType *pResult)
		:CSysNetMonitorAttrTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorAttrTypeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorAttrType
	///@return	下一个满足条件CSysNetMonitorAttrType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypePredict是判断一个监控指标表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypePredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorAttrType	要被判断的监控指标表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeAndPredict是对两个监控指标表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeAndPredict : public CSysNetMonitorAttrTypePredict
{
private:
	CSysNetMonitorAttrTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorAttrTypeAndPredict(CSysNetMonitorAttrTypePredict *p1, CSysNetMonitorAttrTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorAttrTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorAttrType	要被判断的监控指标表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return m_p1->isValid(pSysNetMonitorAttrType) && m_p2->isValid(pSysNetMonitorAttrType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeOrPredict是对两个监控指标表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeOrPredict : public CSysNetMonitorAttrTypePredict
{
private:
	CSysNetMonitorAttrTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorAttrTypeOrPredict(CSysNetMonitorAttrTypePredict *p1, CSysNetMonitorAttrTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorAttrTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorAttrType	要被判断的监控指标表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return m_p1->isValid(pSysNetMonitorAttrType) || m_p2->isValid(pSysNetMonitorAttrType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeNotPredict是对一个监控指标表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeNotPredict : public CSysNetMonitorAttrTypePredict
{
private:
	CSysNetMonitorAttrTypePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorAttrTypeNotPredict(CSysNetMonitorAttrTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorAttrTypeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorAttrType	要被判断的监控指标表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return !m_predict->isValid(pSysNetMonitorAttrType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeFilter是一个对已有的监控指标表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeFilter: public CSysNetMonitorAttrTypeIterator
{
private:
	CSysNetMonitorAttrTypeIterator *m_baseIterator;
	CSysNetMonitorAttrTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorAttrTypeFilter(CSysNetMonitorAttrTypeIterator *pBaseIterator, CSysNetMonitorAttrTypePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorAttrTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorAttrTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorAttrType
	///@return	下一个满足条件CSysNetMonitorAttrType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeLinkIterator是连接两个监控指标表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeLinkIterator: public CSysNetMonitorAttrTypeIterator
{
private:
	CSysNetMonitorAttrTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorAttrTypeLinkIterator(CSysNetMonitorAttrTypeIterator *pBaseIterator1,CSysNetMonitorAttrTypeIterator *pBaseIterator2)
		:CSysNetMonitorAttrTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorAttrTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorAttrType
	///@return	下一个满足条件CSysNetMonitorAttrType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorAttrType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorAttrType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeSingleIterator是至多返回一个监控指令表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeSingleIterator: public CSysNetMonitorCommandTypeIterator
{
private:
	CSysNetMonitorCommandType *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorCommandTypeSingleIterator(CSysNetMonitorCommandTypeFactory *pFactory,CSysNetMonitorCommandType *pResult)
		:CSysNetMonitorCommandTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorCommandTypeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorCommandType
	///@return	下一个满足条件CSysNetMonitorCommandType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorCommandType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypePredict是判断一个监控指令表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypePredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorCommandType	要被判断的监控指令表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeAndPredict是对两个监控指令表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeAndPredict : public CSysNetMonitorCommandTypePredict
{
private:
	CSysNetMonitorCommandTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorCommandTypeAndPredict(CSysNetMonitorCommandTypePredict *p1, CSysNetMonitorCommandTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorCommandTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorCommandType	要被判断的监控指令表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return m_p1->isValid(pSysNetMonitorCommandType) && m_p2->isValid(pSysNetMonitorCommandType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeOrPredict是对两个监控指令表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeOrPredict : public CSysNetMonitorCommandTypePredict
{
private:
	CSysNetMonitorCommandTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorCommandTypeOrPredict(CSysNetMonitorCommandTypePredict *p1, CSysNetMonitorCommandTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorCommandTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorCommandType	要被判断的监控指令表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return m_p1->isValid(pSysNetMonitorCommandType) || m_p2->isValid(pSysNetMonitorCommandType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeNotPredict是对一个监控指令表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeNotPredict : public CSysNetMonitorCommandTypePredict
{
private:
	CSysNetMonitorCommandTypePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorCommandTypeNotPredict(CSysNetMonitorCommandTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorCommandTypeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorCommandType	要被判断的监控指令表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return !m_predict->isValid(pSysNetMonitorCommandType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeFilter是一个对已有的监控指令表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeFilter: public CSysNetMonitorCommandTypeIterator
{
private:
	CSysNetMonitorCommandTypeIterator *m_baseIterator;
	CSysNetMonitorCommandTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorCommandTypeFilter(CSysNetMonitorCommandTypeIterator *pBaseIterator, CSysNetMonitorCommandTypePredict *pPredict, bool continueResult=false)
		:CSysNetMonitorCommandTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorCommandTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorCommandType
	///@return	下一个满足条件CSysNetMonitorCommandType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorCommandType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeLinkIterator是连接两个监控指令表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeLinkIterator: public CSysNetMonitorCommandTypeIterator
{
private:
	CSysNetMonitorCommandTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorCommandTypeLinkIterator(CSysNetMonitorCommandTypeIterator *pBaseIterator1,CSysNetMonitorCommandTypeIterator *pBaseIterator2)
		:CSysNetMonitorCommandTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorCommandTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorCommandType
	///@return	下一个满足条件CSysNetMonitorCommandType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorCommandType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorCommandType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupSingleIterator是至多返回一个动作族表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupSingleIterator: public CSysNetMonitorActionGroupIterator
{
private:
	CSysNetMonitorActionGroup *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorActionGroupSingleIterator(CSysNetMonitorActionGroupFactory *pFactory,CSysNetMonitorActionGroup *pResult)
		:CSysNetMonitorActionGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorActionGroupSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorActionGroup
	///@return	下一个满足条件CSysNetMonitorActionGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupPredict是判断一个动作族表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorActionGroup	要被判断的动作族表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupAndPredict是对两个动作族表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupAndPredict : public CSysNetMonitorActionGroupPredict
{
private:
	CSysNetMonitorActionGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorActionGroupAndPredict(CSysNetMonitorActionGroupPredict *p1, CSysNetMonitorActionGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorActionGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorActionGroup	要被判断的动作族表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return m_p1->isValid(pSysNetMonitorActionGroup) && m_p2->isValid(pSysNetMonitorActionGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupOrPredict是对两个动作族表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupOrPredict : public CSysNetMonitorActionGroupPredict
{
private:
	CSysNetMonitorActionGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorActionGroupOrPredict(CSysNetMonitorActionGroupPredict *p1, CSysNetMonitorActionGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorActionGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorActionGroup	要被判断的动作族表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return m_p1->isValid(pSysNetMonitorActionGroup) || m_p2->isValid(pSysNetMonitorActionGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupNotPredict是对一个动作族表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupNotPredict : public CSysNetMonitorActionGroupPredict
{
private:
	CSysNetMonitorActionGroupPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorActionGroupNotPredict(CSysNetMonitorActionGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorActionGroupNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorActionGroup	要被判断的动作族表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return !m_predict->isValid(pSysNetMonitorActionGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupFilter是一个对已有的动作族表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupFilter: public CSysNetMonitorActionGroupIterator
{
private:
	CSysNetMonitorActionGroupIterator *m_baseIterator;
	CSysNetMonitorActionGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorActionGroupFilter(CSysNetMonitorActionGroupIterator *pBaseIterator, CSysNetMonitorActionGroupPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorActionGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorActionGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorActionGroup
	///@return	下一个满足条件CSysNetMonitorActionGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupLinkIterator是连接两个动作族表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupLinkIterator: public CSysNetMonitorActionGroupIterator
{
private:
	CSysNetMonitorActionGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorActionGroupLinkIterator(CSysNetMonitorActionGroupIterator *pBaseIterator1,CSysNetMonitorActionGroupIterator *pBaseIterator2)
		:CSysNetMonitorActionGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorActionGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorActionGroup
	///@return	下一个满足条件CSysNetMonitorActionGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupSingleIterator是至多返回一个设备对象组表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupSingleIterator: public CSysNetMonitorDeviceGroupIterator
{
private:
	CSysNetMonitorDeviceGroup *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorDeviceGroupSingleIterator(CSysNetMonitorDeviceGroupFactory *pFactory,CSysNetMonitorDeviceGroup *pResult)
		:CSysNetMonitorDeviceGroupIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorDeviceGroupSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorDeviceGroup
	///@return	下一个满足条件CSysNetMonitorDeviceGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupPredict是判断一个设备对象组表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorDeviceGroup	要被判断的设备对象组表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupAndPredict是对两个设备对象组表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupAndPredict : public CSysNetMonitorDeviceGroupPredict
{
private:
	CSysNetMonitorDeviceGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorDeviceGroupAndPredict(CSysNetMonitorDeviceGroupPredict *p1, CSysNetMonitorDeviceGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorDeviceGroupAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorDeviceGroup	要被判断的设备对象组表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return m_p1->isValid(pSysNetMonitorDeviceGroup) && m_p2->isValid(pSysNetMonitorDeviceGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupOrPredict是对两个设备对象组表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupOrPredict : public CSysNetMonitorDeviceGroupPredict
{
private:
	CSysNetMonitorDeviceGroupPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorDeviceGroupOrPredict(CSysNetMonitorDeviceGroupPredict *p1, CSysNetMonitorDeviceGroupPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorDeviceGroupOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorDeviceGroup	要被判断的设备对象组表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return m_p1->isValid(pSysNetMonitorDeviceGroup) || m_p2->isValid(pSysNetMonitorDeviceGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupNotPredict是对一个设备对象组表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupNotPredict : public CSysNetMonitorDeviceGroupPredict
{
private:
	CSysNetMonitorDeviceGroupPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorDeviceGroupNotPredict(CSysNetMonitorDeviceGroupPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorDeviceGroupNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorDeviceGroup	要被判断的设备对象组表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return !m_predict->isValid(pSysNetMonitorDeviceGroup);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupFilter是一个对已有的设备对象组表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupFilter: public CSysNetMonitorDeviceGroupIterator
{
private:
	CSysNetMonitorDeviceGroupIterator *m_baseIterator;
	CSysNetMonitorDeviceGroupPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorDeviceGroupFilter(CSysNetMonitorDeviceGroupIterator *pBaseIterator, CSysNetMonitorDeviceGroupPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorDeviceGroupIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorDeviceGroupFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorDeviceGroup
	///@return	下一个满足条件CSysNetMonitorDeviceGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupLinkIterator是连接两个设备对象组表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupLinkIterator: public CSysNetMonitorDeviceGroupIterator
{
private:
	CSysNetMonitorDeviceGroupIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorDeviceGroupLinkIterator(CSysNetMonitorDeviceGroupIterator *pBaseIterator1,CSysNetMonitorDeviceGroupIterator *pBaseIterator2)
		:CSysNetMonitorDeviceGroupIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorDeviceGroupLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorDeviceGroup
	///@return	下一个满足条件CSysNetMonitorDeviceGroup，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceGroup *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceGroup 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoSingleIterator是至多返回一个任务信息表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoSingleIterator: public CSysNetMonitorTaskInfoIterator
{
private:
	CSysNetMonitorTaskInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorTaskInfoSingleIterator(CSysNetMonitorTaskInfoFactory *pFactory,CSysNetMonitorTaskInfo *pResult)
		:CSysNetMonitorTaskInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorTaskInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorTaskInfo
	///@return	下一个满足条件CSysNetMonitorTaskInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoPredict是判断一个任务信息表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorTaskInfo	要被判断的任务信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoAndPredict是对两个任务信息表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoAndPredict : public CSysNetMonitorTaskInfoPredict
{
private:
	CSysNetMonitorTaskInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskInfoAndPredict(CSysNetMonitorTaskInfoPredict *p1, CSysNetMonitorTaskInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskInfo	要被判断的任务信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return m_p1->isValid(pSysNetMonitorTaskInfo) && m_p2->isValid(pSysNetMonitorTaskInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoOrPredict是对两个任务信息表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoOrPredict : public CSysNetMonitorTaskInfoPredict
{
private:
	CSysNetMonitorTaskInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskInfoOrPredict(CSysNetMonitorTaskInfoPredict *p1, CSysNetMonitorTaskInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskInfo	要被判断的任务信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return m_p1->isValid(pSysNetMonitorTaskInfo) || m_p2->isValid(pSysNetMonitorTaskInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoNotPredict是对一个任务信息表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoNotPredict : public CSysNetMonitorTaskInfoPredict
{
private:
	CSysNetMonitorTaskInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorTaskInfoNotPredict(CSysNetMonitorTaskInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorTaskInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskInfo	要被判断的任务信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return !m_predict->isValid(pSysNetMonitorTaskInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoFilter是一个对已有的任务信息表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoFilter: public CSysNetMonitorTaskInfoIterator
{
private:
	CSysNetMonitorTaskInfoIterator *m_baseIterator;
	CSysNetMonitorTaskInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorTaskInfoFilter(CSysNetMonitorTaskInfoIterator *pBaseIterator, CSysNetMonitorTaskInfoPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorTaskInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorTaskInfo
	///@return	下一个满足条件CSysNetMonitorTaskInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoLinkIterator是连接两个任务信息表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoLinkIterator: public CSysNetMonitorTaskInfoIterator
{
private:
	CSysNetMonitorTaskInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorTaskInfoLinkIterator(CSysNetMonitorTaskInfoIterator *pBaseIterator1,CSysNetMonitorTaskInfoIterator *pBaseIterator2)
		:CSysNetMonitorTaskInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorTaskInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorTaskInfo
	///@return	下一个满足条件CSysNetMonitorTaskInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetSingleIterator是至多返回一个任务对象集的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetSingleIterator: public CSysNetMonitorTaskObjectSetIterator
{
private:
	CSysNetMonitorTaskObjectSet *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorTaskObjectSetSingleIterator(CSysNetMonitorTaskObjectSetFactory *pFactory,CSysNetMonitorTaskObjectSet *pResult)
		:CSysNetMonitorTaskObjectSetIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorTaskObjectSetSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorTaskObjectSet
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskObjectSet 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetPredict是判断一个任务对象集是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorTaskObjectSet	要被判断的任务对象集
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetAndPredict是对两个任务对象集谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetAndPredict : public CSysNetMonitorTaskObjectSetPredict
{
private:
	CSysNetMonitorTaskObjectSetPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskObjectSetAndPredict(CSysNetMonitorTaskObjectSetPredict *p1, CSysNetMonitorTaskObjectSetPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskObjectSetAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskObjectSet	要被判断的任务对象集
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return m_p1->isValid(pSysNetMonitorTaskObjectSet) && m_p2->isValid(pSysNetMonitorTaskObjectSet);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetOrPredict是对两个任务对象集谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetOrPredict : public CSysNetMonitorTaskObjectSetPredict
{
private:
	CSysNetMonitorTaskObjectSetPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskObjectSetOrPredict(CSysNetMonitorTaskObjectSetPredict *p1, CSysNetMonitorTaskObjectSetPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskObjectSetOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskObjectSet	要被判断的任务对象集
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return m_p1->isValid(pSysNetMonitorTaskObjectSet) || m_p2->isValid(pSysNetMonitorTaskObjectSet);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetNotPredict是对一个任务对象集谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetNotPredict : public CSysNetMonitorTaskObjectSetPredict
{
private:
	CSysNetMonitorTaskObjectSetPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorTaskObjectSetNotPredict(CSysNetMonitorTaskObjectSetPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorTaskObjectSetNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskObjectSet	要被判断的任务对象集
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return !m_predict->isValid(pSysNetMonitorTaskObjectSet);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetFilter是一个对已有的任务对象集枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetFilter: public CSysNetMonitorTaskObjectSetIterator
{
private:
	CSysNetMonitorTaskObjectSetIterator *m_baseIterator;
	CSysNetMonitorTaskObjectSetPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorTaskObjectSetFilter(CSysNetMonitorTaskObjectSetIterator *pBaseIterator, CSysNetMonitorTaskObjectSetPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskObjectSetIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorTaskObjectSetFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorTaskObjectSet
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskObjectSet 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetLinkIterator是连接两个任务对象集枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetLinkIterator: public CSysNetMonitorTaskObjectSetIterator
{
private:
	CSysNetMonitorTaskObjectSetIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorTaskObjectSetLinkIterator(CSysNetMonitorTaskObjectSetIterator *pBaseIterator1,CSysNetMonitorTaskObjectSetIterator *pBaseIterator2)
		:CSysNetMonitorTaskObjectSetIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorTaskObjectSetLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorTaskObjectSet
	///@return	下一个满足条件CSysNetMonitorTaskObjectSet，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskObjectSet *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskObjectSet 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultSingleIterator是至多返回一个任务结果表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultSingleIterator: public CSysNetMonitorTaskResultIterator
{
private:
	CSysNetMonitorTaskResult *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorTaskResultSingleIterator(CSysNetMonitorTaskResultFactory *pFactory,CSysNetMonitorTaskResult *pResult)
		:CSysNetMonitorTaskResultIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorTaskResultSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorTaskResult
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskResult 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultPredict是判断一个任务结果表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorTaskResult	要被判断的任务结果表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultAndPredict是对两个任务结果表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultAndPredict : public CSysNetMonitorTaskResultPredict
{
private:
	CSysNetMonitorTaskResultPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskResultAndPredict(CSysNetMonitorTaskResultPredict *p1, CSysNetMonitorTaskResultPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskResultAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskResult	要被判断的任务结果表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return m_p1->isValid(pSysNetMonitorTaskResult) && m_p2->isValid(pSysNetMonitorTaskResult);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultOrPredict是对两个任务结果表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultOrPredict : public CSysNetMonitorTaskResultPredict
{
private:
	CSysNetMonitorTaskResultPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskResultOrPredict(CSysNetMonitorTaskResultPredict *p1, CSysNetMonitorTaskResultPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskResultOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskResult	要被判断的任务结果表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return m_p1->isValid(pSysNetMonitorTaskResult) || m_p2->isValid(pSysNetMonitorTaskResult);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultNotPredict是对一个任务结果表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultNotPredict : public CSysNetMonitorTaskResultPredict
{
private:
	CSysNetMonitorTaskResultPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorTaskResultNotPredict(CSysNetMonitorTaskResultPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorTaskResultNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskResult	要被判断的任务结果表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return !m_predict->isValid(pSysNetMonitorTaskResult);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultFilter是一个对已有的任务结果表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultFilter: public CSysNetMonitorTaskResultIterator
{
private:
	CSysNetMonitorTaskResultIterator *m_baseIterator;
	CSysNetMonitorTaskResultPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorTaskResultFilter(CSysNetMonitorTaskResultIterator *pBaseIterator, CSysNetMonitorTaskResultPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskResultIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorTaskResultFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorTaskResult
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskResult 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultLinkIterator是连接两个任务结果表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultLinkIterator: public CSysNetMonitorTaskResultIterator
{
private:
	CSysNetMonitorTaskResultIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorTaskResultLinkIterator(CSysNetMonitorTaskResultIterator *pBaseIterator1,CSysNetMonitorTaskResultIterator *pBaseIterator2)
		:CSysNetMonitorTaskResultIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorTaskResultLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorTaskResult
	///@return	下一个满足条件CSysNetMonitorTaskResult，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskResult *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskResult 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoSingleIterator是至多返回一个会员链路信息表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoSingleIterator: public CSysNetPartyLinkInfoIterator
{
private:
	CSysNetPartyLinkInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetPartyLinkInfoSingleIterator(CSysNetPartyLinkInfoFactory *pFactory,CSysNetPartyLinkInfo *pResult)
		:CSysNetPartyLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetPartyLinkInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetPartyLinkInfo
	///@return	下一个满足条件CSysNetPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoPredict是判断一个会员链路信息表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoAndPredict是对两个会员链路信息表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoAndPredict : public CSysNetPartyLinkInfoPredict
{
private:
	CSysNetPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPartyLinkInfoAndPredict(CSysNetPartyLinkInfoPredict *p1, CSysNetPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPartyLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetPartyLinkInfo) && m_p2->isValid(pSysNetPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoOrPredict是对两个会员链路信息表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoOrPredict : public CSysNetPartyLinkInfoPredict
{
private:
	CSysNetPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPartyLinkInfoOrPredict(CSysNetPartyLinkInfoPredict *p1, CSysNetPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPartyLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetPartyLinkInfo) || m_p2->isValid(pSysNetPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoNotPredict是对一个会员链路信息表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoNotPredict : public CSysNetPartyLinkInfoPredict
{
private:
	CSysNetPartyLinkInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetPartyLinkInfoNotPredict(CSysNetPartyLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetPartyLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return !m_predict->isValid(pSysNetPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoFilter是一个对已有的会员链路信息表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoFilter: public CSysNetPartyLinkInfoIterator
{
private:
	CSysNetPartyLinkInfoIterator *m_baseIterator;
	CSysNetPartyLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetPartyLinkInfoFilter(CSysNetPartyLinkInfoIterator *pBaseIterator, CSysNetPartyLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetPartyLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetPartyLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetPartyLinkInfo
	///@return	下一个满足条件CSysNetPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoLinkIterator是连接两个会员链路信息表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoLinkIterator: public CSysNetPartyLinkInfoIterator
{
private:
	CSysNetPartyLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetPartyLinkInfoLinkIterator(CSysNetPartyLinkInfoIterator *pBaseIterator1,CSysNetPartyLinkInfoIterator *pBaseIterator2)
		:CSysNetPartyLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetPartyLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetPartyLinkInfo
	///@return	下一个满足条件CSysNetPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoSingleIterator是至多返回一个会员链路信息表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoSingleIterator: public CSysNetDelPartyLinkInfoIterator
{
private:
	CSysNetDelPartyLinkInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetDelPartyLinkInfoSingleIterator(CSysNetDelPartyLinkInfoFactory *pFactory,CSysNetDelPartyLinkInfo *pResult)
		:CSysNetDelPartyLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetDelPartyLinkInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetDelPartyLinkInfo
	///@return	下一个满足条件CSysNetDelPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDelPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoPredict是判断一个会员链路信息表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetDelPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoAndPredict是对两个会员链路信息表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoAndPredict : public CSysNetDelPartyLinkInfoPredict
{
private:
	CSysNetDelPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDelPartyLinkInfoAndPredict(CSysNetDelPartyLinkInfoPredict *p1, CSysNetDelPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDelPartyLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDelPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetDelPartyLinkInfo) && m_p2->isValid(pSysNetDelPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoOrPredict是对两个会员链路信息表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoOrPredict : public CSysNetDelPartyLinkInfoPredict
{
private:
	CSysNetDelPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDelPartyLinkInfoOrPredict(CSysNetDelPartyLinkInfoPredict *p1, CSysNetDelPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDelPartyLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDelPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetDelPartyLinkInfo) || m_p2->isValid(pSysNetDelPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoNotPredict是对一个会员链路信息表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoNotPredict : public CSysNetDelPartyLinkInfoPredict
{
private:
	CSysNetDelPartyLinkInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetDelPartyLinkInfoNotPredict(CSysNetDelPartyLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetDelPartyLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetDelPartyLinkInfo	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return !m_predict->isValid(pSysNetDelPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoFilter是一个对已有的会员链路信息表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoFilter: public CSysNetDelPartyLinkInfoIterator
{
private:
	CSysNetDelPartyLinkInfoIterator *m_baseIterator;
	CSysNetDelPartyLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetDelPartyLinkInfoFilter(CSysNetDelPartyLinkInfoIterator *pBaseIterator, CSysNetDelPartyLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetDelPartyLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetDelPartyLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetDelPartyLinkInfo
	///@return	下一个满足条件CSysNetDelPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDelPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoLinkIterator是连接两个会员链路信息表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoLinkIterator: public CSysNetDelPartyLinkInfoIterator
{
private:
	CSysNetDelPartyLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetDelPartyLinkInfoLinkIterator(CSysNetDelPartyLinkInfoIterator *pBaseIterator1,CSysNetDelPartyLinkInfoIterator *pBaseIterator2)
		:CSysNetDelPartyLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetDelPartyLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetDelPartyLinkInfo
	///@return	下一个满足条件CSysNetDelPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDelPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDelPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeSingleIterator是至多返回一个会员链路信息表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeSingleIterator: public CSysNetPartyLinkAddrChangeIterator
{
private:
	CSysNetPartyLinkAddrChange *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetPartyLinkAddrChangeSingleIterator(CSysNetPartyLinkAddrChangeFactory *pFactory,CSysNetPartyLinkAddrChange *pResult)
		:CSysNetPartyLinkAddrChangeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetPartyLinkAddrChangeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetPartyLinkAddrChange
	///@return	下一个满足条件CSysNetPartyLinkAddrChange，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkAddrChange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangePredict是判断一个会员链路信息表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangePredict
{
public:
	///判断是否合法
	///@param	pSysNetPartyLinkAddrChange	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeAndPredict是对两个会员链路信息表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeAndPredict : public CSysNetPartyLinkAddrChangePredict
{
private:
	CSysNetPartyLinkAddrChangePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPartyLinkAddrChangeAndPredict(CSysNetPartyLinkAddrChangePredict *p1, CSysNetPartyLinkAddrChangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPartyLinkAddrChangeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPartyLinkAddrChange	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return m_p1->isValid(pSysNetPartyLinkAddrChange) && m_p2->isValid(pSysNetPartyLinkAddrChange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeOrPredict是对两个会员链路信息表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeOrPredict : public CSysNetPartyLinkAddrChangePredict
{
private:
	CSysNetPartyLinkAddrChangePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPartyLinkAddrChangeOrPredict(CSysNetPartyLinkAddrChangePredict *p1, CSysNetPartyLinkAddrChangePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPartyLinkAddrChangeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPartyLinkAddrChange	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return m_p1->isValid(pSysNetPartyLinkAddrChange) || m_p2->isValid(pSysNetPartyLinkAddrChange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeNotPredict是对一个会员链路信息表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeNotPredict : public CSysNetPartyLinkAddrChangePredict
{
private:
	CSysNetPartyLinkAddrChangePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetPartyLinkAddrChangeNotPredict(CSysNetPartyLinkAddrChangePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetPartyLinkAddrChangeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetPartyLinkAddrChange	要被判断的会员链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return !m_predict->isValid(pSysNetPartyLinkAddrChange);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeFilter是一个对已有的会员链路信息表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeFilter: public CSysNetPartyLinkAddrChangeIterator
{
private:
	CSysNetPartyLinkAddrChangeIterator *m_baseIterator;
	CSysNetPartyLinkAddrChangePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetPartyLinkAddrChangeFilter(CSysNetPartyLinkAddrChangeIterator *pBaseIterator, CSysNetPartyLinkAddrChangePredict *pPredict, bool continueResult=false)
		:CSysNetPartyLinkAddrChangeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetPartyLinkAddrChangeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetPartyLinkAddrChange
	///@return	下一个满足条件CSysNetPartyLinkAddrChange，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkAddrChange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeLinkIterator是连接两个会员链路信息表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeLinkIterator: public CSysNetPartyLinkAddrChangeIterator
{
private:
	CSysNetPartyLinkAddrChangeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetPartyLinkAddrChangeLinkIterator(CSysNetPartyLinkAddrChangeIterator *pBaseIterator1,CSysNetPartyLinkAddrChangeIterator *pBaseIterator2)
		:CSysNetPartyLinkAddrChangeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetPartyLinkAddrChangeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetPartyLinkAddrChange
	///@return	下一个满足条件CSysNetPartyLinkAddrChange，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartyLinkAddrChange *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartyLinkAddrChange 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrSingleIterator是至多返回一个监控动作指标对照表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrSingleIterator: public CSysNetMonitorActionAttrIterator
{
private:
	CSysNetMonitorActionAttr *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorActionAttrSingleIterator(CSysNetMonitorActionAttrFactory *pFactory,CSysNetMonitorActionAttr *pResult)
		:CSysNetMonitorActionAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorActionAttrSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorActionAttr
	///@return	下一个满足条件CSysNetMonitorActionAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrPredict是判断一个监控动作指标对照表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorActionAttr	要被判断的监控动作指标对照表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrAndPredict是对两个监控动作指标对照表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrAndPredict : public CSysNetMonitorActionAttrPredict
{
private:
	CSysNetMonitorActionAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorActionAttrAndPredict(CSysNetMonitorActionAttrPredict *p1, CSysNetMonitorActionAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorActionAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorActionAttr	要被判断的监控动作指标对照表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return m_p1->isValid(pSysNetMonitorActionAttr) && m_p2->isValid(pSysNetMonitorActionAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrOrPredict是对两个监控动作指标对照表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrOrPredict : public CSysNetMonitorActionAttrPredict
{
private:
	CSysNetMonitorActionAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorActionAttrOrPredict(CSysNetMonitorActionAttrPredict *p1, CSysNetMonitorActionAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorActionAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorActionAttr	要被判断的监控动作指标对照表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return m_p1->isValid(pSysNetMonitorActionAttr) || m_p2->isValid(pSysNetMonitorActionAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrNotPredict是对一个监控动作指标对照表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrNotPredict : public CSysNetMonitorActionAttrPredict
{
private:
	CSysNetMonitorActionAttrPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorActionAttrNotPredict(CSysNetMonitorActionAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorActionAttrNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorActionAttr	要被判断的监控动作指标对照表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return !m_predict->isValid(pSysNetMonitorActionAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrFilter是一个对已有的监控动作指标对照表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrFilter: public CSysNetMonitorActionAttrIterator
{
private:
	CSysNetMonitorActionAttrIterator *m_baseIterator;
	CSysNetMonitorActionAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorActionAttrFilter(CSysNetMonitorActionAttrIterator *pBaseIterator, CSysNetMonitorActionAttrPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorActionAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorActionAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorActionAttr
	///@return	下一个满足条件CSysNetMonitorActionAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrLinkIterator是连接两个监控动作指标对照表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrLinkIterator: public CSysNetMonitorActionAttrIterator
{
private:
	CSysNetMonitorActionAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorActionAttrLinkIterator(CSysNetMonitorActionAttrIterator *pBaseIterator1,CSysNetMonitorActionAttrIterator *pBaseIterator2)
		:CSysNetMonitorActionAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorActionAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorActionAttr
	///@return	下一个满足条件CSysNetMonitorActionAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorActionAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorActionAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetModuleSingleIterator是至多返回一个模块的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleSingleIterator: public CSysNetModuleIterator
{
private:
	CSysNetModule *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetModuleSingleIterator(CSysNetModuleFactory *pFactory,CSysNetModule *pResult)
		:CSysNetModuleIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetModuleSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetModule
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetModule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetModule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModulePredict是判断一个模块是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModulePredict
{
public:
	///判断是否合法
	///@param	pSysNetModule	要被判断的模块
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetModule *pSysNetModule)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleAndPredict是对两个模块谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleAndPredict : public CSysNetModulePredict
{
private:
	CSysNetModulePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetModuleAndPredict(CSysNetModulePredict *p1, CSysNetModulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetModuleAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetModule	要被判断的模块
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetModule *pSysNetModule)
	{
		return m_p1->isValid(pSysNetModule) && m_p2->isValid(pSysNetModule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleOrPredict是对两个模块谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleOrPredict : public CSysNetModulePredict
{
private:
	CSysNetModulePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetModuleOrPredict(CSysNetModulePredict *p1, CSysNetModulePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetModuleOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetModule	要被判断的模块
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetModule *pSysNetModule)
	{
		return m_p1->isValid(pSysNetModule) || m_p2->isValid(pSysNetModule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleNotPredict是对一个模块谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleNotPredict : public CSysNetModulePredict
{
private:
	CSysNetModulePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetModuleNotPredict(CSysNetModulePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetModuleNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetModule	要被判断的模块
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetModule *pSysNetModule)
	{
		return !m_predict->isValid(pSysNetModule);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleFilter是一个对已有的模块枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleFilter: public CSysNetModuleIterator
{
private:
	CSysNetModuleIterator *m_baseIterator;
	CSysNetModulePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetModuleFilter(CSysNetModuleIterator *pBaseIterator, CSysNetModulePredict *pPredict, bool continueResult=false)
		:CSysNetModuleIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetModuleFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetModule
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetModule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetModule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleLinkIterator是连接两个模块枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleLinkIterator: public CSysNetModuleIterator
{
private:
	CSysNetModuleIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetModuleLinkIterator(CSysNetModuleIterator *pBaseIterator1,CSysNetModuleIterator *pBaseIterator2)
		:CSysNetModuleIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetModuleLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetModule
	///@return	下一个满足条件CSysNetModule，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetModule *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetModule 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprSingleIterator是至多返回一个告警表达式信息表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprSingleIterator: public CSysNetEventExprIterator
{
private:
	CSysNetEventExpr *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetEventExprSingleIterator(CSysNetEventExprFactory *pFactory,CSysNetEventExpr *pResult)
		:CSysNetEventExprIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetEventExprSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetEventExpr
	///@return	下一个满足条件CSysNetEventExpr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventExpr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventExpr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprPredict是判断一个告警表达式信息表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprPredict
{
public:
	///判断是否合法
	///@param	pSysNetEventExpr	要被判断的告警表达式信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprAndPredict是对两个告警表达式信息表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprAndPredict : public CSysNetEventExprPredict
{
private:
	CSysNetEventExprPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetEventExprAndPredict(CSysNetEventExprPredict *p1, CSysNetEventExprPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetEventExprAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetEventExpr	要被判断的告警表达式信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)
	{
		return m_p1->isValid(pSysNetEventExpr) && m_p2->isValid(pSysNetEventExpr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprOrPredict是对两个告警表达式信息表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprOrPredict : public CSysNetEventExprPredict
{
private:
	CSysNetEventExprPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetEventExprOrPredict(CSysNetEventExprPredict *p1, CSysNetEventExprPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetEventExprOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetEventExpr	要被判断的告警表达式信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)
	{
		return m_p1->isValid(pSysNetEventExpr) || m_p2->isValid(pSysNetEventExpr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprNotPredict是对一个告警表达式信息表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprNotPredict : public CSysNetEventExprPredict
{
private:
	CSysNetEventExprPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetEventExprNotPredict(CSysNetEventExprPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetEventExprNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetEventExpr	要被判断的告警表达式信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventExpr *pSysNetEventExpr)
	{
		return !m_predict->isValid(pSysNetEventExpr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprFilter是一个对已有的告警表达式信息表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprFilter: public CSysNetEventExprIterator
{
private:
	CSysNetEventExprIterator *m_baseIterator;
	CSysNetEventExprPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetEventExprFilter(CSysNetEventExprIterator *pBaseIterator, CSysNetEventExprPredict *pPredict, bool continueResult=false)
		:CSysNetEventExprIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetEventExprFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetEventExpr
	///@return	下一个满足条件CSysNetEventExpr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventExpr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventExpr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprLinkIterator是连接两个告警表达式信息表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprLinkIterator: public CSysNetEventExprIterator
{
private:
	CSysNetEventExprIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetEventExprLinkIterator(CSysNetEventExprIterator *pBaseIterator1,CSysNetEventExprIterator *pBaseIterator2)
		:CSysNetEventExprIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetEventExprLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetEventExpr
	///@return	下一个满足条件CSysNetEventExpr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventExpr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventExpr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeSingleIterator是至多返回一个事件类型的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeSingleIterator: public CSysNetEventTypeIterator
{
private:
	CSysNetEventType *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetEventTypeSingleIterator(CSysNetEventTypeFactory *pFactory,CSysNetEventType *pResult)
		:CSysNetEventTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetEventTypeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetEventType
	///@return	下一个满足条件CSysNetEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypePredict是判断一个事件类型是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypePredict
{
public:
	///判断是否合法
	///@param	pSysNetEventType	要被判断的事件类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventType *pSysNetEventType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeAndPredict是对两个事件类型谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeAndPredict : public CSysNetEventTypePredict
{
private:
	CSysNetEventTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetEventTypeAndPredict(CSysNetEventTypePredict *p1, CSysNetEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetEventTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetEventType	要被判断的事件类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventType *pSysNetEventType)
	{
		return m_p1->isValid(pSysNetEventType) && m_p2->isValid(pSysNetEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeOrPredict是对两个事件类型谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeOrPredict : public CSysNetEventTypePredict
{
private:
	CSysNetEventTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetEventTypeOrPredict(CSysNetEventTypePredict *p1, CSysNetEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetEventTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetEventType	要被判断的事件类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventType *pSysNetEventType)
	{
		return m_p1->isValid(pSysNetEventType) || m_p2->isValid(pSysNetEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeNotPredict是对一个事件类型谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeNotPredict : public CSysNetEventTypePredict
{
private:
	CSysNetEventTypePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetEventTypeNotPredict(CSysNetEventTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetEventTypeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetEventType	要被判断的事件类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventType *pSysNetEventType)
	{
		return !m_predict->isValid(pSysNetEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeFilter是一个对已有的事件类型枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeFilter: public CSysNetEventTypeIterator
{
private:
	CSysNetEventTypeIterator *m_baseIterator;
	CSysNetEventTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetEventTypeFilter(CSysNetEventTypeIterator *pBaseIterator, CSysNetEventTypePredict *pPredict, bool continueResult=false)
		:CSysNetEventTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetEventTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetEventType
	///@return	下一个满足条件CSysNetEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeLinkIterator是连接两个事件类型枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeLinkIterator: public CSysNetEventTypeIterator
{
private:
	CSysNetEventTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetEventTypeLinkIterator(CSysNetEventTypeIterator *pBaseIterator1,CSysNetEventTypeIterator *pBaseIterator2)
		:CSysNetEventTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetEventTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetEventType
	///@return	下一个满足条件CSysNetEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeSingleIterator是至多返回一个事件子类型的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeSingleIterator: public CSysNetSubEventTypeIterator
{
private:
	CSysNetSubEventType *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetSubEventTypeSingleIterator(CSysNetSubEventTypeFactory *pFactory,CSysNetSubEventType *pResult)
		:CSysNetSubEventTypeIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetSubEventTypeSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetSubEventType
	///@return	下一个满足条件CSysNetSubEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypePredict是判断一个事件子类型是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypePredict
{
public:
	///判断是否合法
	///@param	pSysNetSubEventType	要被判断的事件子类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeAndPredict是对两个事件子类型谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeAndPredict : public CSysNetSubEventTypePredict
{
private:
	CSysNetSubEventTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetSubEventTypeAndPredict(CSysNetSubEventTypePredict *p1, CSysNetSubEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetSubEventTypeAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetSubEventType	要被判断的事件子类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)
	{
		return m_p1->isValid(pSysNetSubEventType) && m_p2->isValid(pSysNetSubEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeOrPredict是对两个事件子类型谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeOrPredict : public CSysNetSubEventTypePredict
{
private:
	CSysNetSubEventTypePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetSubEventTypeOrPredict(CSysNetSubEventTypePredict *p1, CSysNetSubEventTypePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetSubEventTypeOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetSubEventType	要被判断的事件子类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)
	{
		return m_p1->isValid(pSysNetSubEventType) || m_p2->isValid(pSysNetSubEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeNotPredict是对一个事件子类型谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeNotPredict : public CSysNetSubEventTypePredict
{
private:
	CSysNetSubEventTypePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetSubEventTypeNotPredict(CSysNetSubEventTypePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetSubEventTypeNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetSubEventType	要被判断的事件子类型
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetSubEventType *pSysNetSubEventType)
	{
		return !m_predict->isValid(pSysNetSubEventType);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeFilter是一个对已有的事件子类型枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeFilter: public CSysNetSubEventTypeIterator
{
private:
	CSysNetSubEventTypeIterator *m_baseIterator;
	CSysNetSubEventTypePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetSubEventTypeFilter(CSysNetSubEventTypeIterator *pBaseIterator, CSysNetSubEventTypePredict *pPredict, bool continueResult=false)
		:CSysNetSubEventTypeIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetSubEventTypeFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetSubEventType
	///@return	下一个满足条件CSysNetSubEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeLinkIterator是连接两个事件子类型枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeLinkIterator: public CSysNetSubEventTypeIterator
{
private:
	CSysNetSubEventTypeIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetSubEventTypeLinkIterator(CSysNetSubEventTypeIterator *pBaseIterator1,CSysNetSubEventTypeIterator *pBaseIterator2)
		:CSysNetSubEventTypeIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetSubEventTypeLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetSubEventType
	///@return	下一个满足条件CSysNetSubEventType，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetSubEventType *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetSubEventType 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelSingleIterator是至多返回一个事件级别的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelSingleIterator: public CSysNetEventLevelIterator
{
private:
	CSysNetEventLevel *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetEventLevelSingleIterator(CSysNetEventLevelFactory *pFactory,CSysNetEventLevel *pResult)
		:CSysNetEventLevelIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetEventLevelSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetEventLevel
	///@return	下一个满足条件CSysNetEventLevel，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventLevel *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventLevel 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelPredict是判断一个事件级别是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelPredict
{
public:
	///判断是否合法
	///@param	pSysNetEventLevel	要被判断的事件级别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelAndPredict是对两个事件级别谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelAndPredict : public CSysNetEventLevelPredict
{
private:
	CSysNetEventLevelPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetEventLevelAndPredict(CSysNetEventLevelPredict *p1, CSysNetEventLevelPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetEventLevelAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetEventLevel	要被判断的事件级别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)
	{
		return m_p1->isValid(pSysNetEventLevel) && m_p2->isValid(pSysNetEventLevel);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelOrPredict是对两个事件级别谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelOrPredict : public CSysNetEventLevelPredict
{
private:
	CSysNetEventLevelPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetEventLevelOrPredict(CSysNetEventLevelPredict *p1, CSysNetEventLevelPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetEventLevelOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetEventLevel	要被判断的事件级别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)
	{
		return m_p1->isValid(pSysNetEventLevel) || m_p2->isValid(pSysNetEventLevel);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelNotPredict是对一个事件级别谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelNotPredict : public CSysNetEventLevelPredict
{
private:
	CSysNetEventLevelPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetEventLevelNotPredict(CSysNetEventLevelPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetEventLevelNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetEventLevel	要被判断的事件级别
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetEventLevel *pSysNetEventLevel)
	{
		return !m_predict->isValid(pSysNetEventLevel);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelFilter是一个对已有的事件级别枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelFilter: public CSysNetEventLevelIterator
{
private:
	CSysNetEventLevelIterator *m_baseIterator;
	CSysNetEventLevelPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetEventLevelFilter(CSysNetEventLevelIterator *pBaseIterator, CSysNetEventLevelPredict *pPredict, bool continueResult=false)
		:CSysNetEventLevelIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetEventLevelFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetEventLevel
	///@return	下一个满足条件CSysNetEventLevel，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventLevel *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventLevel 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelLinkIterator是连接两个事件级别枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelLinkIterator: public CSysNetEventLevelIterator
{
private:
	CSysNetEventLevelIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetEventLevelLinkIterator(CSysNetEventLevelIterator *pBaseIterator1,CSysNetEventLevelIterator *pBaseIterator2)
		:CSysNetEventLevelIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetEventLevelLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetEventLevel
	///@return	下一个满足条件CSysNetEventLevel，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetEventLevel *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetEventLevel 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskSingleIterator是至多返回一个任务结果规则分析表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskSingleIterator: public CSysNetMonitorDeviceTaskIterator
{
private:
	CSysNetMonitorDeviceTask *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorDeviceTaskSingleIterator(CSysNetMonitorDeviceTaskFactory *pFactory,CSysNetMonitorDeviceTask *pResult)
		:CSysNetMonitorDeviceTaskIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorDeviceTaskSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorDeviceTask
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskPredict是判断一个任务结果规则分析表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorDeviceTask	要被判断的任务结果规则分析表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskAndPredict是对两个任务结果规则分析表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskAndPredict : public CSysNetMonitorDeviceTaskPredict
{
private:
	CSysNetMonitorDeviceTaskPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorDeviceTaskAndPredict(CSysNetMonitorDeviceTaskPredict *p1, CSysNetMonitorDeviceTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorDeviceTaskAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorDeviceTask	要被判断的任务结果规则分析表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return m_p1->isValid(pSysNetMonitorDeviceTask) && m_p2->isValid(pSysNetMonitorDeviceTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskOrPredict是对两个任务结果规则分析表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskOrPredict : public CSysNetMonitorDeviceTaskPredict
{
private:
	CSysNetMonitorDeviceTaskPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorDeviceTaskOrPredict(CSysNetMonitorDeviceTaskPredict *p1, CSysNetMonitorDeviceTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorDeviceTaskOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorDeviceTask	要被判断的任务结果规则分析表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return m_p1->isValid(pSysNetMonitorDeviceTask) || m_p2->isValid(pSysNetMonitorDeviceTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskNotPredict是对一个任务结果规则分析表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskNotPredict : public CSysNetMonitorDeviceTaskPredict
{
private:
	CSysNetMonitorDeviceTaskPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorDeviceTaskNotPredict(CSysNetMonitorDeviceTaskPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorDeviceTaskNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorDeviceTask	要被判断的任务结果规则分析表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return !m_predict->isValid(pSysNetMonitorDeviceTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskFilter是一个对已有的任务结果规则分析表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskFilter: public CSysNetMonitorDeviceTaskIterator
{
private:
	CSysNetMonitorDeviceTaskIterator *m_baseIterator;
	CSysNetMonitorDeviceTaskPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorDeviceTaskFilter(CSysNetMonitorDeviceTaskIterator *pBaseIterator, CSysNetMonitorDeviceTaskPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorDeviceTaskIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorDeviceTaskFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorDeviceTask
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskLinkIterator是连接两个任务结果规则分析表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskLinkIterator: public CSysNetMonitorDeviceTaskIterator
{
private:
	CSysNetMonitorDeviceTaskIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorDeviceTaskLinkIterator(CSysNetMonitorDeviceTaskIterator *pBaseIterator1,CSysNetMonitorDeviceTaskIterator *pBaseIterator2)
		:CSysNetMonitorDeviceTaskIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorDeviceTaskLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorDeviceTask
	///@return	下一个满足条件CSysNetMonitorDeviceTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorDeviceTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorDeviceTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsSingleIterator是至多返回一个任务指令指标集表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsSingleIterator: public CSysNetMonitorTaskInstAttrsIterator
{
private:
	CSysNetMonitorTaskInstAttrs *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMonitorTaskInstAttrsSingleIterator(CSysNetMonitorTaskInstAttrsFactory *pFactory,CSysNetMonitorTaskInstAttrs *pResult)
		:CSysNetMonitorTaskInstAttrsIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMonitorTaskInstAttrsSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMonitorTaskInstAttrs
	///@return	下一个满足条件CSysNetMonitorTaskInstAttrs，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInstAttrs 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsPredict是判断一个任务指令指标集表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsPredict
{
public:
	///判断是否合法
	///@param	pSysNetMonitorTaskInstAttrs	要被判断的任务指令指标集表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsAndPredict是对两个任务指令指标集表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsAndPredict : public CSysNetMonitorTaskInstAttrsPredict
{
private:
	CSysNetMonitorTaskInstAttrsPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskInstAttrsAndPredict(CSysNetMonitorTaskInstAttrsPredict *p1, CSysNetMonitorTaskInstAttrsPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskInstAttrsAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskInstAttrs	要被判断的任务指令指标集表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return m_p1->isValid(pSysNetMonitorTaskInstAttrs) && m_p2->isValid(pSysNetMonitorTaskInstAttrs);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsOrPredict是对两个任务指令指标集表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsOrPredict : public CSysNetMonitorTaskInstAttrsPredict
{
private:
	CSysNetMonitorTaskInstAttrsPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMonitorTaskInstAttrsOrPredict(CSysNetMonitorTaskInstAttrsPredict *p1, CSysNetMonitorTaskInstAttrsPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMonitorTaskInstAttrsOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskInstAttrs	要被判断的任务指令指标集表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return m_p1->isValid(pSysNetMonitorTaskInstAttrs) || m_p2->isValid(pSysNetMonitorTaskInstAttrs);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsNotPredict是对一个任务指令指标集表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsNotPredict : public CSysNetMonitorTaskInstAttrsPredict
{
private:
	CSysNetMonitorTaskInstAttrsPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMonitorTaskInstAttrsNotPredict(CSysNetMonitorTaskInstAttrsPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMonitorTaskInstAttrsNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMonitorTaskInstAttrs	要被判断的任务指令指标集表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return !m_predict->isValid(pSysNetMonitorTaskInstAttrs);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsFilter是一个对已有的任务指令指标集表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsFilter: public CSysNetMonitorTaskInstAttrsIterator
{
private:
	CSysNetMonitorTaskInstAttrsIterator *m_baseIterator;
	CSysNetMonitorTaskInstAttrsPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMonitorTaskInstAttrsFilter(CSysNetMonitorTaskInstAttrsIterator *pBaseIterator, CSysNetMonitorTaskInstAttrsPredict *pPredict, bool continueResult=false)
		:CSysNetMonitorTaskInstAttrsIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMonitorTaskInstAttrsFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMonitorTaskInstAttrs
	///@return	下一个满足条件CSysNetMonitorTaskInstAttrs，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInstAttrs 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsLinkIterator是连接两个任务指令指标集表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsLinkIterator: public CSysNetMonitorTaskInstAttrsIterator
{
private:
	CSysNetMonitorTaskInstAttrsIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMonitorTaskInstAttrsLinkIterator(CSysNetMonitorTaskInstAttrsIterator *pBaseIterator1,CSysNetMonitorTaskInstAttrsIterator *pBaseIterator2)
		:CSysNetMonitorTaskInstAttrsIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMonitorTaskInstAttrsLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMonitorTaskInstAttrs
	///@return	下一个满足条件CSysNetMonitorTaskInstAttrs，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMonitorTaskInstAttrs 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineSingleIterator是至多返回一个基线表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineSingleIterator: public CSysNetBaseLineIterator
{
private:
	CSysNetBaseLine *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetBaseLineSingleIterator(CSysNetBaseLineFactory *pFactory,CSysNetBaseLine *pResult)
		:CSysNetBaseLineIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetBaseLineSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetBaseLine
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLinePredict是判断一个基线表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLinePredict
{
public:
	///判断是否合法
	///@param	pSysNetBaseLine	要被判断的基线表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineAndPredict是对两个基线表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineAndPredict : public CSysNetBaseLinePredict
{
private:
	CSysNetBaseLinePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetBaseLineAndPredict(CSysNetBaseLinePredict *p1, CSysNetBaseLinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetBaseLineAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetBaseLine	要被判断的基线表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)
	{
		return m_p1->isValid(pSysNetBaseLine) && m_p2->isValid(pSysNetBaseLine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineOrPredict是对两个基线表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineOrPredict : public CSysNetBaseLinePredict
{
private:
	CSysNetBaseLinePredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetBaseLineOrPredict(CSysNetBaseLinePredict *p1, CSysNetBaseLinePredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetBaseLineOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetBaseLine	要被判断的基线表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)
	{
		return m_p1->isValid(pSysNetBaseLine) || m_p2->isValid(pSysNetBaseLine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineNotPredict是对一个基线表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineNotPredict : public CSysNetBaseLinePredict
{
private:
	CSysNetBaseLinePredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetBaseLineNotPredict(CSysNetBaseLinePredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetBaseLineNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetBaseLine	要被判断的基线表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLine *pSysNetBaseLine)
	{
		return !m_predict->isValid(pSysNetBaseLine);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineFilter是一个对已有的基线表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineFilter: public CSysNetBaseLineIterator
{
private:
	CSysNetBaseLineIterator *m_baseIterator;
	CSysNetBaseLinePredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetBaseLineFilter(CSysNetBaseLineIterator *pBaseIterator, CSysNetBaseLinePredict *pPredict, bool continueResult=false)
		:CSysNetBaseLineIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetBaseLineFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetBaseLine
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineLinkIterator是连接两个基线表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineLinkIterator: public CSysNetBaseLineIterator
{
private:
	CSysNetBaseLineIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetBaseLineLinkIterator(CSysNetBaseLineIterator *pBaseIterator1,CSysNetBaseLineIterator *pBaseIterator2)
		:CSysNetBaseLineIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetBaseLineLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetBaseLine
	///@return	下一个满足条件CSysNetBaseLine，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLine *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLine 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskSingleIterator是至多返回一个基线任务表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskSingleIterator: public CSysNetBaseLineTaskIterator
{
private:
	CSysNetBaseLineTask *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetBaseLineTaskSingleIterator(CSysNetBaseLineTaskFactory *pFactory,CSysNetBaseLineTask *pResult)
		:CSysNetBaseLineTaskIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetBaseLineTaskSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetBaseLineTask
	///@return	下一个满足条件CSysNetBaseLineTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLineTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskPredict是判断一个基线任务表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskPredict
{
public:
	///判断是否合法
	///@param	pSysNetBaseLineTask	要被判断的基线任务表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskAndPredict是对两个基线任务表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskAndPredict : public CSysNetBaseLineTaskPredict
{
private:
	CSysNetBaseLineTaskPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetBaseLineTaskAndPredict(CSysNetBaseLineTaskPredict *p1, CSysNetBaseLineTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetBaseLineTaskAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetBaseLineTask	要被判断的基线任务表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return m_p1->isValid(pSysNetBaseLineTask) && m_p2->isValid(pSysNetBaseLineTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskOrPredict是对两个基线任务表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskOrPredict : public CSysNetBaseLineTaskPredict
{
private:
	CSysNetBaseLineTaskPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetBaseLineTaskOrPredict(CSysNetBaseLineTaskPredict *p1, CSysNetBaseLineTaskPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetBaseLineTaskOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetBaseLineTask	要被判断的基线任务表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return m_p1->isValid(pSysNetBaseLineTask) || m_p2->isValid(pSysNetBaseLineTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskNotPredict是对一个基线任务表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskNotPredict : public CSysNetBaseLineTaskPredict
{
private:
	CSysNetBaseLineTaskPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetBaseLineTaskNotPredict(CSysNetBaseLineTaskPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetBaseLineTaskNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetBaseLineTask	要被判断的基线任务表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return !m_predict->isValid(pSysNetBaseLineTask);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskFilter是一个对已有的基线任务表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskFilter: public CSysNetBaseLineTaskIterator
{
private:
	CSysNetBaseLineTaskIterator *m_baseIterator;
	CSysNetBaseLineTaskPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetBaseLineTaskFilter(CSysNetBaseLineTaskIterator *pBaseIterator, CSysNetBaseLineTaskPredict *pPredict, bool continueResult=false)
		:CSysNetBaseLineTaskIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetBaseLineTaskFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetBaseLineTask
	///@return	下一个满足条件CSysNetBaseLineTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLineTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskLinkIterator是连接两个基线任务表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskLinkIterator: public CSysNetBaseLineTaskIterator
{
private:
	CSysNetBaseLineTaskIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetBaseLineTaskLinkIterator(CSysNetBaseLineTaskIterator *pBaseIterator1,CSysNetBaseLineTaskIterator *pBaseIterator2)
		:CSysNetBaseLineTaskIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetBaseLineTaskLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetBaseLineTask
	///@return	下一个满足条件CSysNetBaseLineTask，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetBaseLineTask *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetBaseLineTask 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoSingleIterator是至多返回一个会员链路状态信息表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoSingleIterator: public CSysMdbNetPartyLinkStatusInfoIterator
{
private:
	CSysMdbNetPartyLinkStatusInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbNetPartyLinkStatusInfoSingleIterator(CSysMdbNetPartyLinkStatusInfoFactory *pFactory,CSysMdbNetPartyLinkStatusInfo *pResult)
		:CSysMdbNetPartyLinkStatusInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbNetPartyLinkStatusInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetPartyLinkStatusInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoPredict是判断一个会员链路状态信息表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbNetPartyLinkStatusInfo	要被判断的会员链路状态信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoAndPredict是对两个会员链路状态信息表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoAndPredict : public CSysMdbNetPartyLinkStatusInfoPredict
{
private:
	CSysMdbNetPartyLinkStatusInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbNetPartyLinkStatusInfoAndPredict(CSysMdbNetPartyLinkStatusInfoPredict *p1, CSysMdbNetPartyLinkStatusInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbNetPartyLinkStatusInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbNetPartyLinkStatusInfo	要被判断的会员链路状态信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return m_p1->isValid(pSysMdbNetPartyLinkStatusInfo) && m_p2->isValid(pSysMdbNetPartyLinkStatusInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoOrPredict是对两个会员链路状态信息表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoOrPredict : public CSysMdbNetPartyLinkStatusInfoPredict
{
private:
	CSysMdbNetPartyLinkStatusInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbNetPartyLinkStatusInfoOrPredict(CSysMdbNetPartyLinkStatusInfoPredict *p1, CSysMdbNetPartyLinkStatusInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbNetPartyLinkStatusInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbNetPartyLinkStatusInfo	要被判断的会员链路状态信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return m_p1->isValid(pSysMdbNetPartyLinkStatusInfo) || m_p2->isValid(pSysMdbNetPartyLinkStatusInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoNotPredict是对一个会员链路状态信息表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoNotPredict : public CSysMdbNetPartyLinkStatusInfoPredict
{
private:
	CSysMdbNetPartyLinkStatusInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbNetPartyLinkStatusInfoNotPredict(CSysMdbNetPartyLinkStatusInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbNetPartyLinkStatusInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbNetPartyLinkStatusInfo	要被判断的会员链路状态信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return !m_predict->isValid(pSysMdbNetPartyLinkStatusInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoFilter是一个对已有的会员链路状态信息表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoFilter: public CSysMdbNetPartyLinkStatusInfoIterator
{
private:
	CSysMdbNetPartyLinkStatusInfoIterator *m_baseIterator;
	CSysMdbNetPartyLinkStatusInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbNetPartyLinkStatusInfoFilter(CSysMdbNetPartyLinkStatusInfoIterator *pBaseIterator, CSysMdbNetPartyLinkStatusInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbNetPartyLinkStatusInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbNetPartyLinkStatusInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetPartyLinkStatusInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoLinkIterator是连接两个会员链路状态信息表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoLinkIterator: public CSysMdbNetPartyLinkStatusInfoIterator
{
private:
	CSysMdbNetPartyLinkStatusInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbNetPartyLinkStatusInfoLinkIterator(CSysMdbNetPartyLinkStatusInfoIterator *pBaseIterator1,CSysMdbNetPartyLinkStatusInfoIterator *pBaseIterator2)
		:CSysMdbNetPartyLinkStatusInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbNetPartyLinkStatusInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbNetPartyLinkStatusInfo
	///@return	下一个满足条件CSysMdbNetPartyLinkStatusInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbNetPartyLinkStatusInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoSingleIterator是至多返回一个会员SDH线路明细表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoSingleIterator: public CSysNetMemberSDHLineInfoIterator
{
private:
	CSysNetMemberSDHLineInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetMemberSDHLineInfoSingleIterator(CSysNetMemberSDHLineInfoFactory *pFactory,CSysNetMemberSDHLineInfo *pResult)
		:CSysNetMemberSDHLineInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetMemberSDHLineInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetMemberSDHLineInfo
	///@return	下一个满足条件CSysNetMemberSDHLineInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMemberSDHLineInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoPredict是判断一个会员SDH线路明细表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetMemberSDHLineInfo	要被判断的会员SDH线路明细表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoAndPredict是对两个会员SDH线路明细表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoAndPredict : public CSysNetMemberSDHLineInfoPredict
{
private:
	CSysNetMemberSDHLineInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMemberSDHLineInfoAndPredict(CSysNetMemberSDHLineInfoPredict *p1, CSysNetMemberSDHLineInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMemberSDHLineInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMemberSDHLineInfo	要被判断的会员SDH线路明细表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return m_p1->isValid(pSysNetMemberSDHLineInfo) && m_p2->isValid(pSysNetMemberSDHLineInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoOrPredict是对两个会员SDH线路明细表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoOrPredict : public CSysNetMemberSDHLineInfoPredict
{
private:
	CSysNetMemberSDHLineInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetMemberSDHLineInfoOrPredict(CSysNetMemberSDHLineInfoPredict *p1, CSysNetMemberSDHLineInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetMemberSDHLineInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetMemberSDHLineInfo	要被判断的会员SDH线路明细表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return m_p1->isValid(pSysNetMemberSDHLineInfo) || m_p2->isValid(pSysNetMemberSDHLineInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoNotPredict是对一个会员SDH线路明细表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoNotPredict : public CSysNetMemberSDHLineInfoPredict
{
private:
	CSysNetMemberSDHLineInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetMemberSDHLineInfoNotPredict(CSysNetMemberSDHLineInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetMemberSDHLineInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetMemberSDHLineInfo	要被判断的会员SDH线路明细表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return !m_predict->isValid(pSysNetMemberSDHLineInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoFilter是一个对已有的会员SDH线路明细表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoFilter: public CSysNetMemberSDHLineInfoIterator
{
private:
	CSysNetMemberSDHLineInfoIterator *m_baseIterator;
	CSysNetMemberSDHLineInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetMemberSDHLineInfoFilter(CSysNetMemberSDHLineInfoIterator *pBaseIterator, CSysNetMemberSDHLineInfoPredict *pPredict, bool continueResult=false)
		:CSysNetMemberSDHLineInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetMemberSDHLineInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetMemberSDHLineInfo
	///@return	下一个满足条件CSysNetMemberSDHLineInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMemberSDHLineInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoLinkIterator是连接两个会员SDH线路明细表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoLinkIterator: public CSysNetMemberSDHLineInfoIterator
{
private:
	CSysNetMemberSDHLineInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetMemberSDHLineInfoLinkIterator(CSysNetMemberSDHLineInfoIterator *pBaseIterator1,CSysNetMemberSDHLineInfoIterator *pBaseIterator2)
		:CSysNetMemberSDHLineInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetMemberSDHLineInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetMemberSDHLineInfo
	///@return	下一个满足条件CSysNetMemberSDHLineInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetMemberSDHLineInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetMemberSDHLineInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoSingleIterator是至多返回一个DDN链路信息表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoSingleIterator: public CSysNetDDNLinkInfoIterator
{
private:
	CSysNetDDNLinkInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetDDNLinkInfoSingleIterator(CSysNetDDNLinkInfoFactory *pFactory,CSysNetDDNLinkInfo *pResult)
		:CSysNetDDNLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetDDNLinkInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetDDNLinkInfo
	///@return	下一个满足条件CSysNetDDNLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDDNLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoPredict是判断一个DDN链路信息表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetDDNLinkInfo	要被判断的DDN链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoAndPredict是对两个DDN链路信息表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoAndPredict : public CSysNetDDNLinkInfoPredict
{
private:
	CSysNetDDNLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDDNLinkInfoAndPredict(CSysNetDDNLinkInfoPredict *p1, CSysNetDDNLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDDNLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDDNLinkInfo	要被判断的DDN链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return m_p1->isValid(pSysNetDDNLinkInfo) && m_p2->isValid(pSysNetDDNLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoOrPredict是对两个DDN链路信息表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoOrPredict : public CSysNetDDNLinkInfoPredict
{
private:
	CSysNetDDNLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetDDNLinkInfoOrPredict(CSysNetDDNLinkInfoPredict *p1, CSysNetDDNLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetDDNLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetDDNLinkInfo	要被判断的DDN链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return m_p1->isValid(pSysNetDDNLinkInfo) || m_p2->isValid(pSysNetDDNLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoNotPredict是对一个DDN链路信息表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoNotPredict : public CSysNetDDNLinkInfoPredict
{
private:
	CSysNetDDNLinkInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetDDNLinkInfoNotPredict(CSysNetDDNLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetDDNLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetDDNLinkInfo	要被判断的DDN链路信息表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return !m_predict->isValid(pSysNetDDNLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoFilter是一个对已有的DDN链路信息表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoFilter: public CSysNetDDNLinkInfoIterator
{
private:
	CSysNetDDNLinkInfoIterator *m_baseIterator;
	CSysNetDDNLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetDDNLinkInfoFilter(CSysNetDDNLinkInfoIterator *pBaseIterator, CSysNetDDNLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetDDNLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetDDNLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetDDNLinkInfo
	///@return	下一个满足条件CSysNetDDNLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDDNLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoLinkIterator是连接两个DDN链路信息表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoLinkIterator: public CSysNetDDNLinkInfoIterator
{
private:
	CSysNetDDNLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetDDNLinkInfoLinkIterator(CSysNetDDNLinkInfoIterator *pBaseIterator1,CSysNetDDNLinkInfoIterator *pBaseIterator2)
		:CSysNetDDNLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetDDNLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetDDNLinkInfo
	///@return	下一个满足条件CSysNetDDNLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetDDNLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetDDNLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoSingleIterator是至多返回一个非会员线路使用信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoSingleIterator: public CSysNetPseudMemberLinkInfoIterator
{
private:
	CSysNetPseudMemberLinkInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetPseudMemberLinkInfoSingleIterator(CSysNetPseudMemberLinkInfoFactory *pFactory,CSysNetPseudMemberLinkInfo *pResult)
		:CSysNetPseudMemberLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetPseudMemberLinkInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetPseudMemberLinkInfo
	///@return	下一个满足条件CSysNetPseudMemberLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPseudMemberLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoPredict是判断一个非会员线路使用信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetPseudMemberLinkInfo	要被判断的非会员线路使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoAndPredict是对两个非会员线路使用信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoAndPredict : public CSysNetPseudMemberLinkInfoPredict
{
private:
	CSysNetPseudMemberLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPseudMemberLinkInfoAndPredict(CSysNetPseudMemberLinkInfoPredict *p1, CSysNetPseudMemberLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPseudMemberLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPseudMemberLinkInfo	要被判断的非会员线路使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return m_p1->isValid(pSysNetPseudMemberLinkInfo) && m_p2->isValid(pSysNetPseudMemberLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoOrPredict是对两个非会员线路使用信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoOrPredict : public CSysNetPseudMemberLinkInfoPredict
{
private:
	CSysNetPseudMemberLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPseudMemberLinkInfoOrPredict(CSysNetPseudMemberLinkInfoPredict *p1, CSysNetPseudMemberLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPseudMemberLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPseudMemberLinkInfo	要被判断的非会员线路使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return m_p1->isValid(pSysNetPseudMemberLinkInfo) || m_p2->isValid(pSysNetPseudMemberLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoNotPredict是对一个非会员线路使用信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoNotPredict : public CSysNetPseudMemberLinkInfoPredict
{
private:
	CSysNetPseudMemberLinkInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetPseudMemberLinkInfoNotPredict(CSysNetPseudMemberLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetPseudMemberLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetPseudMemberLinkInfo	要被判断的非会员线路使用信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return !m_predict->isValid(pSysNetPseudMemberLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoFilter是一个对已有的非会员线路使用信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoFilter: public CSysNetPseudMemberLinkInfoIterator
{
private:
	CSysNetPseudMemberLinkInfoIterator *m_baseIterator;
	CSysNetPseudMemberLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetPseudMemberLinkInfoFilter(CSysNetPseudMemberLinkInfoIterator *pBaseIterator, CSysNetPseudMemberLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetPseudMemberLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetPseudMemberLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetPseudMemberLinkInfo
	///@return	下一个满足条件CSysNetPseudMemberLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPseudMemberLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoLinkIterator是连接两个非会员线路使用信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoLinkIterator: public CSysNetPseudMemberLinkInfoIterator
{
private:
	CSysNetPseudMemberLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetPseudMemberLinkInfoLinkIterator(CSysNetPseudMemberLinkInfoIterator *pBaseIterator1,CSysNetPseudMemberLinkInfoIterator *pBaseIterator2)
		:CSysNetPseudMemberLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetPseudMemberLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetPseudMemberLinkInfo
	///@return	下一个满足条件CSysNetPseudMemberLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPseudMemberLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPseudMemberLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoSingleIterator是至多返回一个远端设备信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoSingleIterator: public CSysNetOuterDeviceInfoIterator
{
private:
	CSysNetOuterDeviceInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetOuterDeviceInfoSingleIterator(CSysNetOuterDeviceInfoFactory *pFactory,CSysNetOuterDeviceInfo *pResult)
		:CSysNetOuterDeviceInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetOuterDeviceInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetOuterDeviceInfo
	///@return	下一个满足条件CSysNetOuterDeviceInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOuterDeviceInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoPredict是判断一个远端设备信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetOuterDeviceInfo	要被判断的远端设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoAndPredict是对两个远端设备信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoAndPredict : public CSysNetOuterDeviceInfoPredict
{
private:
	CSysNetOuterDeviceInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetOuterDeviceInfoAndPredict(CSysNetOuterDeviceInfoPredict *p1, CSysNetOuterDeviceInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetOuterDeviceInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetOuterDeviceInfo	要被判断的远端设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return m_p1->isValid(pSysNetOuterDeviceInfo) && m_p2->isValid(pSysNetOuterDeviceInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoOrPredict是对两个远端设备信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoOrPredict : public CSysNetOuterDeviceInfoPredict
{
private:
	CSysNetOuterDeviceInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetOuterDeviceInfoOrPredict(CSysNetOuterDeviceInfoPredict *p1, CSysNetOuterDeviceInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetOuterDeviceInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetOuterDeviceInfo	要被判断的远端设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return m_p1->isValid(pSysNetOuterDeviceInfo) || m_p2->isValid(pSysNetOuterDeviceInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoNotPredict是对一个远端设备信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoNotPredict : public CSysNetOuterDeviceInfoPredict
{
private:
	CSysNetOuterDeviceInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetOuterDeviceInfoNotPredict(CSysNetOuterDeviceInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetOuterDeviceInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetOuterDeviceInfo	要被判断的远端设备信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return !m_predict->isValid(pSysNetOuterDeviceInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoFilter是一个对已有的远端设备信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoFilter: public CSysNetOuterDeviceInfoIterator
{
private:
	CSysNetOuterDeviceInfoIterator *m_baseIterator;
	CSysNetOuterDeviceInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetOuterDeviceInfoFilter(CSysNetOuterDeviceInfoIterator *pBaseIterator, CSysNetOuterDeviceInfoPredict *pPredict, bool continueResult=false)
		:CSysNetOuterDeviceInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetOuterDeviceInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetOuterDeviceInfo
	///@return	下一个满足条件CSysNetOuterDeviceInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOuterDeviceInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoLinkIterator是连接两个远端设备信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoLinkIterator: public CSysNetOuterDeviceInfoIterator
{
private:
	CSysNetOuterDeviceInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetOuterDeviceInfoLinkIterator(CSysNetOuterDeviceInfoIterator *pBaseIterator1,CSysNetOuterDeviceInfoIterator *pBaseIterator2)
		:CSysNetOuterDeviceInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetOuterDeviceInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetOuterDeviceInfo
	///@return	下一个满足条件CSysNetOuterDeviceInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetOuterDeviceInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetOuterDeviceInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoSingleIterator是至多返回一个本地ping结果的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoSingleIterator: public CSysLocalPingResultInfoIterator
{
private:
	CSysLocalPingResultInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysLocalPingResultInfoSingleIterator(CSysLocalPingResultInfoFactory *pFactory,CSysLocalPingResultInfo *pResult)
		:CSysLocalPingResultInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysLocalPingResultInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysLocalPingResultInfo
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysLocalPingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoPredict是判断一个本地ping结果是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoPredict
{
public:
	///判断是否合法
	///@param	pSysLocalPingResultInfo	要被判断的本地ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoAndPredict是对两个本地ping结果谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoAndPredict : public CSysLocalPingResultInfoPredict
{
private:
	CSysLocalPingResultInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysLocalPingResultInfoAndPredict(CSysLocalPingResultInfoPredict *p1, CSysLocalPingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysLocalPingResultInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysLocalPingResultInfo	要被判断的本地ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return m_p1->isValid(pSysLocalPingResultInfo) && m_p2->isValid(pSysLocalPingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoOrPredict是对两个本地ping结果谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoOrPredict : public CSysLocalPingResultInfoPredict
{
private:
	CSysLocalPingResultInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysLocalPingResultInfoOrPredict(CSysLocalPingResultInfoPredict *p1, CSysLocalPingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysLocalPingResultInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysLocalPingResultInfo	要被判断的本地ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return m_p1->isValid(pSysLocalPingResultInfo) || m_p2->isValid(pSysLocalPingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoNotPredict是对一个本地ping结果谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoNotPredict : public CSysLocalPingResultInfoPredict
{
private:
	CSysLocalPingResultInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysLocalPingResultInfoNotPredict(CSysLocalPingResultInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysLocalPingResultInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysLocalPingResultInfo	要被判断的本地ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return !m_predict->isValid(pSysLocalPingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoFilter是一个对已有的本地ping结果枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoFilter: public CSysLocalPingResultInfoIterator
{
private:
	CSysLocalPingResultInfoIterator *m_baseIterator;
	CSysLocalPingResultInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysLocalPingResultInfoFilter(CSysLocalPingResultInfoIterator *pBaseIterator, CSysLocalPingResultInfoPredict *pPredict, bool continueResult=false)
		:CSysLocalPingResultInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysLocalPingResultInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysLocalPingResultInfo
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysLocalPingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoLinkIterator是连接两个本地ping结果枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoLinkIterator: public CSysLocalPingResultInfoIterator
{
private:
	CSysLocalPingResultInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysLocalPingResultInfoLinkIterator(CSysLocalPingResultInfoIterator *pBaseIterator1,CSysLocalPingResultInfoIterator *pBaseIterator2)
		:CSysLocalPingResultInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysLocalPingResultInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysLocalPingResultInfo
	///@return	下一个满足条件CSysLocalPingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysLocalPingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysLocalPingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoSingleIterator是至多返回一个远程ping结果的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoSingleIterator: public CSysRomotePingResultInfoIterator
{
private:
	CSysRomotePingResultInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysRomotePingResultInfoSingleIterator(CSysRomotePingResultInfoFactory *pFactory,CSysRomotePingResultInfo *pResult)
		:CSysRomotePingResultInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysRomotePingResultInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysRomotePingResultInfo
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysRomotePingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoPredict是判断一个远程ping结果是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoPredict
{
public:
	///判断是否合法
	///@param	pSysRomotePingResultInfo	要被判断的远程ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoAndPredict是对两个远程ping结果谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoAndPredict : public CSysRomotePingResultInfoPredict
{
private:
	CSysRomotePingResultInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysRomotePingResultInfoAndPredict(CSysRomotePingResultInfoPredict *p1, CSysRomotePingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysRomotePingResultInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysRomotePingResultInfo	要被判断的远程ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return m_p1->isValid(pSysRomotePingResultInfo) && m_p2->isValid(pSysRomotePingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoOrPredict是对两个远程ping结果谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoOrPredict : public CSysRomotePingResultInfoPredict
{
private:
	CSysRomotePingResultInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysRomotePingResultInfoOrPredict(CSysRomotePingResultInfoPredict *p1, CSysRomotePingResultInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysRomotePingResultInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysRomotePingResultInfo	要被判断的远程ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return m_p1->isValid(pSysRomotePingResultInfo) || m_p2->isValid(pSysRomotePingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoNotPredict是对一个远程ping结果谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoNotPredict : public CSysRomotePingResultInfoPredict
{
private:
	CSysRomotePingResultInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysRomotePingResultInfoNotPredict(CSysRomotePingResultInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysRomotePingResultInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysRomotePingResultInfo	要被判断的远程ping结果
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return !m_predict->isValid(pSysRomotePingResultInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoFilter是一个对已有的远程ping结果枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoFilter: public CSysRomotePingResultInfoIterator
{
private:
	CSysRomotePingResultInfoIterator *m_baseIterator;
	CSysRomotePingResultInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysRomotePingResultInfoFilter(CSysRomotePingResultInfoIterator *pBaseIterator, CSysRomotePingResultInfoPredict *pPredict, bool continueResult=false)
		:CSysRomotePingResultInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysRomotePingResultInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysRomotePingResultInfo
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysRomotePingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoLinkIterator是连接两个远程ping结果枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoLinkIterator: public CSysRomotePingResultInfoIterator
{
private:
	CSysRomotePingResultInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysRomotePingResultInfoLinkIterator(CSysRomotePingResultInfoIterator *pBaseIterator1,CSysRomotePingResultInfoIterator *pBaseIterator2)
		:CSysRomotePingResultInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysRomotePingResultInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysRomotePingResultInfo
	///@return	下一个满足条件CSysRomotePingResultInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysRomotePingResultInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysRomotePingResultInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesSingleIterator是至多返回一个会员席位交易状态的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesSingleIterator: public CSysParticTradeOrderStatesIterator
{
private:
	CSysParticTradeOrderStates *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysParticTradeOrderStatesSingleIterator(CSysParticTradeOrderStatesFactory *pFactory,CSysParticTradeOrderStates *pResult)
		:CSysParticTradeOrderStatesIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysParticTradeOrderStatesSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysParticTradeOrderStates
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticTradeOrderStates 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesPredict是判断一个会员席位交易状态是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesPredict
{
public:
	///判断是否合法
	///@param	pSysParticTradeOrderStates	要被判断的会员席位交易状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesAndPredict是对两个会员席位交易状态谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesAndPredict : public CSysParticTradeOrderStatesPredict
{
private:
	CSysParticTradeOrderStatesPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysParticTradeOrderStatesAndPredict(CSysParticTradeOrderStatesPredict *p1, CSysParticTradeOrderStatesPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysParticTradeOrderStatesAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysParticTradeOrderStates	要被判断的会员席位交易状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return m_p1->isValid(pSysParticTradeOrderStates) && m_p2->isValid(pSysParticTradeOrderStates);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesOrPredict是对两个会员席位交易状态谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesOrPredict : public CSysParticTradeOrderStatesPredict
{
private:
	CSysParticTradeOrderStatesPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysParticTradeOrderStatesOrPredict(CSysParticTradeOrderStatesPredict *p1, CSysParticTradeOrderStatesPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysParticTradeOrderStatesOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysParticTradeOrderStates	要被判断的会员席位交易状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return m_p1->isValid(pSysParticTradeOrderStates) || m_p2->isValid(pSysParticTradeOrderStates);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesNotPredict是对一个会员席位交易状态谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesNotPredict : public CSysParticTradeOrderStatesPredict
{
private:
	CSysParticTradeOrderStatesPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysParticTradeOrderStatesNotPredict(CSysParticTradeOrderStatesPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysParticTradeOrderStatesNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysParticTradeOrderStates	要被判断的会员席位交易状态
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return !m_predict->isValid(pSysParticTradeOrderStates);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesFilter是一个对已有的会员席位交易状态枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesFilter: public CSysParticTradeOrderStatesIterator
{
private:
	CSysParticTradeOrderStatesIterator *m_baseIterator;
	CSysParticTradeOrderStatesPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysParticTradeOrderStatesFilter(CSysParticTradeOrderStatesIterator *pBaseIterator, CSysParticTradeOrderStatesPredict *pPredict, bool continueResult=false)
		:CSysParticTradeOrderStatesIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysParticTradeOrderStatesFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysParticTradeOrderStates
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticTradeOrderStates 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesLinkIterator是连接两个会员席位交易状态枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesLinkIterator: public CSysParticTradeOrderStatesIterator
{
private:
	CSysParticTradeOrderStatesIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysParticTradeOrderStatesLinkIterator(CSysParticTradeOrderStatesIterator *pBaseIterator1,CSysParticTradeOrderStatesIterator *pBaseIterator2)
		:CSysParticTradeOrderStatesIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysParticTradeOrderStatesLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysParticTradeOrderStates
	///@return	下一个满足条件CSysParticTradeOrderStates，如果已经没有一个满足要求了，则返回NULL
	virtual CSysParticTradeOrderStates *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysParticTradeOrderStates 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoSingleIterator是至多返回一个系统路由信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoSingleIterator: public CSysMdbRouterInfoIterator
{
private:
	CSysMdbRouterInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbRouterInfoSingleIterator(CSysMdbRouterInfoFactory *pFactory,CSysMdbRouterInfo *pResult)
		:CSysMdbRouterInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbRouterInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbRouterInfo
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbRouterInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoPredict是判断一个系统路由信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbRouterInfo	要被判断的系统路由信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoAndPredict是对两个系统路由信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoAndPredict : public CSysMdbRouterInfoPredict
{
private:
	CSysMdbRouterInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbRouterInfoAndPredict(CSysMdbRouterInfoPredict *p1, CSysMdbRouterInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbRouterInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbRouterInfo	要被判断的系统路由信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return m_p1->isValid(pSysMdbRouterInfo) && m_p2->isValid(pSysMdbRouterInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoOrPredict是对两个系统路由信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoOrPredict : public CSysMdbRouterInfoPredict
{
private:
	CSysMdbRouterInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbRouterInfoOrPredict(CSysMdbRouterInfoPredict *p1, CSysMdbRouterInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbRouterInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbRouterInfo	要被判断的系统路由信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return m_p1->isValid(pSysMdbRouterInfo) || m_p2->isValid(pSysMdbRouterInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoNotPredict是对一个系统路由信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoNotPredict : public CSysMdbRouterInfoPredict
{
private:
	CSysMdbRouterInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbRouterInfoNotPredict(CSysMdbRouterInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbRouterInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbRouterInfo	要被判断的系统路由信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return !m_predict->isValid(pSysMdbRouterInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoFilter是一个对已有的系统路由信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoFilter: public CSysMdbRouterInfoIterator
{
private:
	CSysMdbRouterInfoIterator *m_baseIterator;
	CSysMdbRouterInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbRouterInfoFilter(CSysMdbRouterInfoIterator *pBaseIterator, CSysMdbRouterInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbRouterInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbRouterInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbRouterInfo
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbRouterInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoLinkIterator是连接两个系统路由信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoLinkIterator: public CSysMdbRouterInfoIterator
{
private:
	CSysMdbRouterInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbRouterInfoLinkIterator(CSysMdbRouterInfoIterator *pBaseIterator1,CSysMdbRouterInfoIterator *pBaseIterator2)
		:CSysMdbRouterInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbRouterInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbRouterInfo
	///@return	下一个满足条件CSysMdbRouterInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbRouterInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbRouterInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOSingleIterator是至多返回一个磁盘I/O信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOSingleIterator: public CSysMdbDiskIOIterator
{
private:
	CSysMdbDiskIO *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbDiskIOSingleIterator(CSysMdbDiskIOFactory *pFactory,CSysMdbDiskIO *pResult)
		:CSysMdbDiskIOIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbDiskIOSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbDiskIO
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDiskIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOPredict是判断一个磁盘I/O信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOPredict
{
public:
	///判断是否合法
	///@param	pSysMdbDiskIO	要被判断的磁盘I/O信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOAndPredict是对两个磁盘I/O信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOAndPredict : public CSysMdbDiskIOPredict
{
private:
	CSysMdbDiskIOPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbDiskIOAndPredict(CSysMdbDiskIOPredict *p1, CSysMdbDiskIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbDiskIOAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbDiskIO	要被判断的磁盘I/O信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return m_p1->isValid(pSysMdbDiskIO) && m_p2->isValid(pSysMdbDiskIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOOrPredict是对两个磁盘I/O信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOOrPredict : public CSysMdbDiskIOPredict
{
private:
	CSysMdbDiskIOPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbDiskIOOrPredict(CSysMdbDiskIOPredict *p1, CSysMdbDiskIOPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbDiskIOOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbDiskIO	要被判断的磁盘I/O信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return m_p1->isValid(pSysMdbDiskIO) || m_p2->isValid(pSysMdbDiskIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIONotPredict是对一个磁盘I/O信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIONotPredict : public CSysMdbDiskIOPredict
{
private:
	CSysMdbDiskIOPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbDiskIONotPredict(CSysMdbDiskIOPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbDiskIONotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbDiskIO	要被判断的磁盘I/O信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return !m_predict->isValid(pSysMdbDiskIO);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOFilter是一个对已有的磁盘I/O信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOFilter: public CSysMdbDiskIOIterator
{
private:
	CSysMdbDiskIOIterator *m_baseIterator;
	CSysMdbDiskIOPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbDiskIOFilter(CSysMdbDiskIOIterator *pBaseIterator, CSysMdbDiskIOPredict *pPredict, bool continueResult=false)
		:CSysMdbDiskIOIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbDiskIOFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbDiskIO
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDiskIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOLinkIterator是连接两个磁盘I/O信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOLinkIterator: public CSysMdbDiskIOIterator
{
private:
	CSysMdbDiskIOIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbDiskIOLinkIterator(CSysMdbDiskIOIterator *pBaseIterator1,CSysMdbDiskIOIterator *pBaseIterator2)
		:CSysMdbDiskIOIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbDiskIOLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbDiskIO
	///@return	下一个满足条件CSysMdbDiskIO，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbDiskIO *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbDiskIO 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoSingleIterator是至多返回一个系统状态信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoSingleIterator: public CSysMdbStatInfoIterator
{
private:
	CSysMdbStatInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbStatInfoSingleIterator(CSysMdbStatInfoFactory *pFactory,CSysMdbStatInfo *pResult)
		:CSysMdbStatInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbStatInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbStatInfo
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbStatInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoPredict是判断一个系统状态信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoPredict
{
public:
	///判断是否合法
	///@param	pSysMdbStatInfo	要被判断的系统状态信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoAndPredict是对两个系统状态信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoAndPredict : public CSysMdbStatInfoPredict
{
private:
	CSysMdbStatInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbStatInfoAndPredict(CSysMdbStatInfoPredict *p1, CSysMdbStatInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbStatInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbStatInfo	要被判断的系统状态信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return m_p1->isValid(pSysMdbStatInfo) && m_p2->isValid(pSysMdbStatInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoOrPredict是对两个系统状态信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoOrPredict : public CSysMdbStatInfoPredict
{
private:
	CSysMdbStatInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbStatInfoOrPredict(CSysMdbStatInfoPredict *p1, CSysMdbStatInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbStatInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbStatInfo	要被判断的系统状态信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return m_p1->isValid(pSysMdbStatInfo) || m_p2->isValid(pSysMdbStatInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoNotPredict是对一个系统状态信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoNotPredict : public CSysMdbStatInfoPredict
{
private:
	CSysMdbStatInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbStatInfoNotPredict(CSysMdbStatInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbStatInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbStatInfo	要被判断的系统状态信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return !m_predict->isValid(pSysMdbStatInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoFilter是一个对已有的系统状态信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoFilter: public CSysMdbStatInfoIterator
{
private:
	CSysMdbStatInfoIterator *m_baseIterator;
	CSysMdbStatInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbStatInfoFilter(CSysMdbStatInfoIterator *pBaseIterator, CSysMdbStatInfoPredict *pPredict, bool continueResult=false)
		:CSysMdbStatInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbStatInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbStatInfo
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbStatInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoLinkIterator是连接两个系统状态信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoLinkIterator: public CSysMdbStatInfoIterator
{
private:
	CSysMdbStatInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbStatInfoLinkIterator(CSysMdbStatInfoIterator *pBaseIterator1,CSysMdbStatInfoIterator *pBaseIterator2)
		:CSysMdbStatInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbStatInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbStatInfo
	///@return	下一个满足条件CSysMdbStatInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbStatInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbStatInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatSingleIterator是至多返回一个交易系统前置报单响应信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatSingleIterator: public CSysMdbTradeFrontOrderRttStatIterator
{
private:
	CSysMdbTradeFrontOrderRttStat *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMdbTradeFrontOrderRttStatSingleIterator(CSysMdbTradeFrontOrderRttStatFactory *pFactory,CSysMdbTradeFrontOrderRttStat *pResult)
		:CSysMdbTradeFrontOrderRttStatIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMdbTradeFrontOrderRttStatSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTradeFrontOrderRttStat 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatPredict是判断一个交易系统前置报单响应信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatPredict
{
public:
	///判断是否合法
	///@param	pSysMdbTradeFrontOrderRttStat	要被判断的交易系统前置报单响应信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatAndPredict是对两个交易系统前置报单响应信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatAndPredict : public CSysMdbTradeFrontOrderRttStatPredict
{
private:
	CSysMdbTradeFrontOrderRttStatPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTradeFrontOrderRttStatAndPredict(CSysMdbTradeFrontOrderRttStatPredict *p1, CSysMdbTradeFrontOrderRttStatPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTradeFrontOrderRttStatAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTradeFrontOrderRttStat	要被判断的交易系统前置报单响应信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return m_p1->isValid(pSysMdbTradeFrontOrderRttStat) && m_p2->isValid(pSysMdbTradeFrontOrderRttStat);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatOrPredict是对两个交易系统前置报单响应信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatOrPredict : public CSysMdbTradeFrontOrderRttStatPredict
{
private:
	CSysMdbTradeFrontOrderRttStatPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMdbTradeFrontOrderRttStatOrPredict(CSysMdbTradeFrontOrderRttStatPredict *p1, CSysMdbTradeFrontOrderRttStatPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMdbTradeFrontOrderRttStatOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMdbTradeFrontOrderRttStat	要被判断的交易系统前置报单响应信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return m_p1->isValid(pSysMdbTradeFrontOrderRttStat) || m_p2->isValid(pSysMdbTradeFrontOrderRttStat);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatNotPredict是对一个交易系统前置报单响应信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatNotPredict : public CSysMdbTradeFrontOrderRttStatPredict
{
private:
	CSysMdbTradeFrontOrderRttStatPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMdbTradeFrontOrderRttStatNotPredict(CSysMdbTradeFrontOrderRttStatPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMdbTradeFrontOrderRttStatNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMdbTradeFrontOrderRttStat	要被判断的交易系统前置报单响应信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return !m_predict->isValid(pSysMdbTradeFrontOrderRttStat);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatFilter是一个对已有的交易系统前置报单响应信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatFilter: public CSysMdbTradeFrontOrderRttStatIterator
{
private:
	CSysMdbTradeFrontOrderRttStatIterator *m_baseIterator;
	CSysMdbTradeFrontOrderRttStatPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMdbTradeFrontOrderRttStatFilter(CSysMdbTradeFrontOrderRttStatIterator *pBaseIterator, CSysMdbTradeFrontOrderRttStatPredict *pPredict, bool continueResult=false)
		:CSysMdbTradeFrontOrderRttStatIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMdbTradeFrontOrderRttStatFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTradeFrontOrderRttStat 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatLinkIterator是连接两个交易系统前置报单响应信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatLinkIterator: public CSysMdbTradeFrontOrderRttStatIterator
{
private:
	CSysMdbTradeFrontOrderRttStatIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMdbTradeFrontOrderRttStatLinkIterator(CSysMdbTradeFrontOrderRttStatIterator *pBaseIterator1,CSysMdbTradeFrontOrderRttStatIterator *pBaseIterator2)
		:CSysMdbTradeFrontOrderRttStatIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMdbTradeFrontOrderRttStatLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMdbTradeFrontOrderRttStat
	///@return	下一个满足条件CSysMdbTradeFrontOrderRttStat，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMdbTradeFrontOrderRttStat 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusSingleIterator是至多返回一个合约状态切换的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusSingleIterator: public CSysInstrumentStatusIterator
{
private:
	CSysInstrumentStatus *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysInstrumentStatusSingleIterator(CSysInstrumentStatusFactory *pFactory,CSysInstrumentStatus *pResult)
		:CSysInstrumentStatusIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysInstrumentStatusSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysInstrumentStatus
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusPredict是判断一个合约状态切换是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusPredict
{
public:
	///判断是否合法
	///@param	pSysInstrumentStatus	要被判断的合约状态切换
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusAndPredict是对两个合约状态切换谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusAndPredict : public CSysInstrumentStatusPredict
{
private:
	CSysInstrumentStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysInstrumentStatusAndPredict(CSysInstrumentStatusPredict *p1, CSysInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysInstrumentStatusAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysInstrumentStatus	要被判断的合约状态切换
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return m_p1->isValid(pSysInstrumentStatus) && m_p2->isValid(pSysInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusOrPredict是对两个合约状态切换谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusOrPredict : public CSysInstrumentStatusPredict
{
private:
	CSysInstrumentStatusPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysInstrumentStatusOrPredict(CSysInstrumentStatusPredict *p1, CSysInstrumentStatusPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysInstrumentStatusOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysInstrumentStatus	要被判断的合约状态切换
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return m_p1->isValid(pSysInstrumentStatus) || m_p2->isValid(pSysInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusNotPredict是对一个合约状态切换谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusNotPredict : public CSysInstrumentStatusPredict
{
private:
	CSysInstrumentStatusPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysInstrumentStatusNotPredict(CSysInstrumentStatusPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysInstrumentStatusNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysInstrumentStatus	要被判断的合约状态切换
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return !m_predict->isValid(pSysInstrumentStatus);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusFilter是一个对已有的合约状态切换枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusFilter: public CSysInstrumentStatusIterator
{
private:
	CSysInstrumentStatusIterator *m_baseIterator;
	CSysInstrumentStatusPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysInstrumentStatusFilter(CSysInstrumentStatusIterator *pBaseIterator, CSysInstrumentStatusPredict *pPredict, bool continueResult=false)
		:CSysInstrumentStatusIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysInstrumentStatusFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysInstrumentStatus
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusLinkIterator是连接两个合约状态切换枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusLinkIterator: public CSysInstrumentStatusIterator
{
private:
	CSysInstrumentStatusIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysInstrumentStatusLinkIterator(CSysInstrumentStatusIterator *pBaseIterator1,CSysInstrumentStatusIterator *pBaseIterator2)
		:CSysInstrumentStatusIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysInstrumentStatusLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysInstrumentStatus
	///@return	下一个满足条件CSysInstrumentStatus，如果已经没有一个满足要求了，则返回NULL
	virtual CSysInstrumentStatus *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysInstrumentStatus 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrSingleIterator是至多返回一个合约交易节信息的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrSingleIterator: public CSysCurrTradingSegmentAttrIterator
{
private:
	CSysCurrTradingSegmentAttr *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysCurrTradingSegmentAttrSingleIterator(CSysCurrTradingSegmentAttrFactory *pFactory,CSysCurrTradingSegmentAttr *pResult)
		:CSysCurrTradingSegmentAttrIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysCurrTradingSegmentAttrSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysCurrTradingSegmentAttr
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrPredict是判断一个合约交易节信息是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrPredict
{
public:
	///判断是否合法
	///@param	pSysCurrTradingSegmentAttr	要被判断的合约交易节信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrAndPredict是对两个合约交易节信息谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrAndPredict : public CSysCurrTradingSegmentAttrPredict
{
private:
	CSysCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysCurrTradingSegmentAttrAndPredict(CSysCurrTradingSegmentAttrPredict *p1, CSysCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysCurrTradingSegmentAttrAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysCurrTradingSegmentAttr	要被判断的合约交易节信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pSysCurrTradingSegmentAttr) && m_p2->isValid(pSysCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrOrPredict是对两个合约交易节信息谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrOrPredict : public CSysCurrTradingSegmentAttrPredict
{
private:
	CSysCurrTradingSegmentAttrPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysCurrTradingSegmentAttrOrPredict(CSysCurrTradingSegmentAttrPredict *p1, CSysCurrTradingSegmentAttrPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysCurrTradingSegmentAttrOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysCurrTradingSegmentAttr	要被判断的合约交易节信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return m_p1->isValid(pSysCurrTradingSegmentAttr) || m_p2->isValid(pSysCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrNotPredict是对一个合约交易节信息谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrNotPredict : public CSysCurrTradingSegmentAttrPredict
{
private:
	CSysCurrTradingSegmentAttrPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysCurrTradingSegmentAttrNotPredict(CSysCurrTradingSegmentAttrPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysCurrTradingSegmentAttrNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysCurrTradingSegmentAttr	要被判断的合约交易节信息
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return !m_predict->isValid(pSysCurrTradingSegmentAttr);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrFilter是一个对已有的合约交易节信息枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrFilter: public CSysCurrTradingSegmentAttrIterator
{
private:
	CSysCurrTradingSegmentAttrIterator *m_baseIterator;
	CSysCurrTradingSegmentAttrPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysCurrTradingSegmentAttrFilter(CSysCurrTradingSegmentAttrIterator *pBaseIterator, CSysCurrTradingSegmentAttrPredict *pPredict, bool continueResult=false)
		:CSysCurrTradingSegmentAttrIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysCurrTradingSegmentAttrFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysCurrTradingSegmentAttr
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrLinkIterator是连接两个合约交易节信息枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrLinkIterator: public CSysCurrTradingSegmentAttrIterator
{
private:
	CSysCurrTradingSegmentAttrIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysCurrTradingSegmentAttrLinkIterator(CSysCurrTradingSegmentAttrIterator *pBaseIterator1,CSysCurrTradingSegmentAttrIterator *pBaseIterator2)
		:CSysCurrTradingSegmentAttrIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysCurrTradingSegmentAttrLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysCurrTradingSegmentAttr
	///@return	下一个满足条件CSysCurrTradingSegmentAttr，如果已经没有一个满足要求了，则返回NULL
	virtual CSysCurrTradingSegmentAttr *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysCurrTradingSegmentAttr 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostSingleIterator是至多返回一个会员链路费用表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostSingleIterator: public CSysMemberLinkCostIterator
{
private:
	CSysMemberLinkCost *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysMemberLinkCostSingleIterator(CSysMemberLinkCostFactory *pFactory,CSysMemberLinkCost *pResult)
		:CSysMemberLinkCostIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysMemberLinkCostSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysMemberLinkCost
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMemberLinkCost *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMemberLinkCost 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostPredict是判断一个会员链路费用表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostPredict
{
public:
	///判断是否合法
	///@param	pSysMemberLinkCost	要被判断的会员链路费用表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostAndPredict是对两个会员链路费用表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostAndPredict : public CSysMemberLinkCostPredict
{
private:
	CSysMemberLinkCostPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMemberLinkCostAndPredict(CSysMemberLinkCostPredict *p1, CSysMemberLinkCostPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMemberLinkCostAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMemberLinkCost	要被判断的会员链路费用表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return m_p1->isValid(pSysMemberLinkCost) && m_p2->isValid(pSysMemberLinkCost);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostOrPredict是对两个会员链路费用表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostOrPredict : public CSysMemberLinkCostPredict
{
private:
	CSysMemberLinkCostPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysMemberLinkCostOrPredict(CSysMemberLinkCostPredict *p1, CSysMemberLinkCostPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysMemberLinkCostOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysMemberLinkCost	要被判断的会员链路费用表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return m_p1->isValid(pSysMemberLinkCost) || m_p2->isValid(pSysMemberLinkCost);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostNotPredict是对一个会员链路费用表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostNotPredict : public CSysMemberLinkCostPredict
{
private:
	CSysMemberLinkCostPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysMemberLinkCostNotPredict(CSysMemberLinkCostPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysMemberLinkCostNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysMemberLinkCost	要被判断的会员链路费用表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return !m_predict->isValid(pSysMemberLinkCost);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostFilter是一个对已有的会员链路费用表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostFilter: public CSysMemberLinkCostIterator
{
private:
	CSysMemberLinkCostIterator *m_baseIterator;
	CSysMemberLinkCostPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysMemberLinkCostFilter(CSysMemberLinkCostIterator *pBaseIterator, CSysMemberLinkCostPredict *pPredict, bool continueResult=false)
		:CSysMemberLinkCostIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysMemberLinkCostFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysMemberLinkCost
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMemberLinkCost *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMemberLinkCost 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostLinkIterator是连接两个会员链路费用表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostLinkIterator: public CSysMemberLinkCostIterator
{
private:
	CSysMemberLinkCostIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysMemberLinkCostLinkIterator(CSysMemberLinkCostIterator *pBaseIterator1,CSysMemberLinkCostIterator *pBaseIterator2)
		:CSysMemberLinkCostIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysMemberLinkCostLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysMemberLinkCost
	///@return	下一个满足条件CSysMemberLinkCost，如果已经没有一个满足要求了，则返回NULL
	virtual CSysMemberLinkCost *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysMemberLinkCost 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentSingleIterator是至多返回一个会员链路月租表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentSingleIterator: public CSysNetPartylinkMonthlyRentIterator
{
private:
	CSysNetPartylinkMonthlyRent *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetPartylinkMonthlyRentSingleIterator(CSysNetPartylinkMonthlyRentFactory *pFactory,CSysNetPartylinkMonthlyRent *pResult)
		:CSysNetPartylinkMonthlyRentIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetPartylinkMonthlyRentSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartylinkMonthlyRent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentPredict是判断一个会员链路月租表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentPredict
{
public:
	///判断是否合法
	///@param	pSysNetPartylinkMonthlyRent	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentAndPredict是对两个会员链路月租表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentAndPredict : public CSysNetPartylinkMonthlyRentPredict
{
private:
	CSysNetPartylinkMonthlyRentPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPartylinkMonthlyRentAndPredict(CSysNetPartylinkMonthlyRentPredict *p1, CSysNetPartylinkMonthlyRentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPartylinkMonthlyRentAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPartylinkMonthlyRent	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return m_p1->isValid(pSysNetPartylinkMonthlyRent) && m_p2->isValid(pSysNetPartylinkMonthlyRent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentOrPredict是对两个会员链路月租表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentOrPredict : public CSysNetPartylinkMonthlyRentPredict
{
private:
	CSysNetPartylinkMonthlyRentPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetPartylinkMonthlyRentOrPredict(CSysNetPartylinkMonthlyRentPredict *p1, CSysNetPartylinkMonthlyRentPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetPartylinkMonthlyRentOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetPartylinkMonthlyRent	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return m_p1->isValid(pSysNetPartylinkMonthlyRent) || m_p2->isValid(pSysNetPartylinkMonthlyRent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentNotPredict是对一个会员链路月租表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentNotPredict : public CSysNetPartylinkMonthlyRentPredict
{
private:
	CSysNetPartylinkMonthlyRentPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetPartylinkMonthlyRentNotPredict(CSysNetPartylinkMonthlyRentPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetPartylinkMonthlyRentNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetPartylinkMonthlyRent	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return !m_predict->isValid(pSysNetPartylinkMonthlyRent);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentFilter是一个对已有的会员链路月租表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentFilter: public CSysNetPartylinkMonthlyRentIterator
{
private:
	CSysNetPartylinkMonthlyRentIterator *m_baseIterator;
	CSysNetPartylinkMonthlyRentPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetPartylinkMonthlyRentFilter(CSysNetPartylinkMonthlyRentIterator *pBaseIterator, CSysNetPartylinkMonthlyRentPredict *pPredict, bool continueResult=false)
		:CSysNetPartylinkMonthlyRentIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetPartylinkMonthlyRentFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartylinkMonthlyRent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentLinkIterator是连接两个会员链路月租表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentLinkIterator: public CSysNetPartylinkMonthlyRentIterator
{
private:
	CSysNetPartylinkMonthlyRentIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetPartylinkMonthlyRentLinkIterator(CSysNetPartylinkMonthlyRentIterator *pBaseIterator1,CSysNetPartylinkMonthlyRentIterator *pBaseIterator2)
		:CSysNetPartylinkMonthlyRentIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetPartylinkMonthlyRentLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetPartylinkMonthlyRent
	///@return	下一个满足条件CSysNetPartylinkMonthlyRent，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetPartylinkMonthlyRent *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetPartylinkMonthlyRent 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoSingleIterator是至多返回一个会员链路月租表的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoSingleIterator: public CSysNetNonPartyLinkInfoIterator
{
private:
	CSysNetNonPartyLinkInfo *m_pResult;
	bool m_finished;
public:
	///构造方法
	///@param	pFactory	要使用的对象工厂
	///@param	pResult	要返回的单个结果
	CSysNetNonPartyLinkInfoSingleIterator(CSysNetNonPartyLinkInfoFactory *pFactory,CSysNetNonPartyLinkInfo *pResult)
		:CSysNetNonPartyLinkInfoIterator(pFactory)
	{
		m_pResult=pResult;
		m_finished=false;
	}

	///构造方法
	~CSysNetNonPartyLinkInfoSingleIterator(void)
	{
	}

	///寻找下一个符合条件的CSysNetNonPartyLinkInfo
	///@return	下一个满足条件CSysNetNonPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetNonPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoPredict是判断一个会员链路月租表是否符合条件的谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoPredict
{
public:
	///判断是否合法
	///@param	pSysNetNonPartyLinkInfo	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)=0;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoAndPredict是对两个会员链路月租表谓词的与谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoAndPredict : public CSysNetNonPartyLinkInfoPredict
{
private:
	CSysNetNonPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetNonPartyLinkInfoAndPredict(CSysNetNonPartyLinkInfoPredict *p1, CSysNetNonPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetNonPartyLinkInfoAndPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetNonPartyLinkInfo	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetNonPartyLinkInfo) && m_p2->isValid(pSysNetNonPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoOrPredict是对两个会员链路月租表谓词的或谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoOrPredict : public CSysNetNonPartyLinkInfoPredict
{
private:
	CSysNetNonPartyLinkInfoPredict *m_p1,*m_p2;
public:
	///构造方法
	///@param	p1	第一个谓词
	///@param	p2	第二个谓词
	CSysNetNonPartyLinkInfoOrPredict(CSysNetNonPartyLinkInfoPredict *p1, CSysNetNonPartyLinkInfoPredict *p2)
	{
		m_p1=p1;
		m_p2=p2;
	}
	
	///析构方法
	~CSysNetNonPartyLinkInfoOrPredict(void)
	{
		delete m_p1;
		delete m_p2;
	}

	///判断是否合法
	///@param	pSysNetNonPartyLinkInfo	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return m_p1->isValid(pSysNetNonPartyLinkInfo) || m_p2->isValid(pSysNetNonPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoNotPredict是对一个会员链路月租表谓词的非谓词
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoNotPredict : public CSysNetNonPartyLinkInfoPredict
{
private:
	CSysNetNonPartyLinkInfoPredict *m_predict;
public:
	///构造方法
	///@param	predict	基础谓词
	CSysNetNonPartyLinkInfoNotPredict(CSysNetNonPartyLinkInfoPredict *predict)
	{
		m_predict=predict;
	}
	
	///析构方法
	~CSysNetNonPartyLinkInfoNotPredict(void)
	{
		delete m_predict;
	}

	///判断是否合法
	///@param	pSysNetNonPartyLinkInfo	要被判断的会员链路月租表
	///@return	true表示合法，false表示不合法
	virtual bool isValid(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return !m_predict->isValid(pSysNetNonPartyLinkInfo);
	}
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoFilter是一个对已有的会员链路月租表枚举器进行过滤的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoFilter: public CSysNetNonPartyLinkInfoIterator
{
private:
	CSysNetNonPartyLinkInfoIterator *m_baseIterator;
	CSysNetNonPartyLinkInfoPredict *m_predict;
	bool m_continueResult;
	bool m_finished;
public:
	///构造函数
	///@param	pBaseIterator	基础的枚举器
	///@param	pPredict	判定是否合法的谓词
	///@param	continueResult	true表示如果结果集必须是基础枚举器给出的连续结果，false表示不必如此
	CSysNetNonPartyLinkInfoFilter(CSysNetNonPartyLinkInfoIterator *pBaseIterator, CSysNetNonPartyLinkInfoPredict *pPredict, bool continueResult=false)
		:CSysNetNonPartyLinkInfoIterator()
	{
		m_baseIterator=pBaseIterator;
		m_predict=pPredict;
		m_continueResult=continueResult;
		m_finished=false;
	}
	
	///析构函数
	~CSysNetNonPartyLinkInfoFilter(void)
	{
		m_baseIterator->free();
		delete m_predict;
	}

	///寻找下一个符合条件的CSysNetNonPartyLinkInfo
	///@return	下一个满足条件CSysNetNonPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetNonPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoLinkIterator是连接两个会员链路月租表枚举器的枚举器
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoLinkIterator: public CSysNetNonPartyLinkInfoIterator
{
private:
	CSysNetNonPartyLinkInfoIterator *m_baseIterator[2];
	int m_id;
public:
	///构造函数
	///@param	pBaseIterator1	基础的枚举器1
	///@param	pBaseIterator2	基础的枚举器2
	CSysNetNonPartyLinkInfoLinkIterator(CSysNetNonPartyLinkInfoIterator *pBaseIterator1,CSysNetNonPartyLinkInfoIterator *pBaseIterator2)
		:CSysNetNonPartyLinkInfoIterator()
	{
		m_baseIterator[0]=pBaseIterator1;
		m_baseIterator[1]=pBaseIterator2;
		m_id=0;
	}
	
	///析构函数
	~CSysNetNonPartyLinkInfoLinkIterator(void)
	{
		for (int i=0;i<2;i++)
		{
			m_baseIterator[i]->free();
		}
	}

	///寻找下一个符合条件的CSysNetNonPartyLinkInfo
	///@return	下一个满足条件CSysNetNonPartyLinkInfo，如果已经没有一个满足要求了，则返回NULL
	virtual CSysNetNonPartyLinkInfo *next(void);
	
	///删除Iterator当前指向的纪录
	///@param	pTransaction	此次删除属于的事务，NULL表示不属于任何事务，立即执行
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL);
	
	///更新当前Iterator指向的纪录
	///@param	pSysNetNonPartyLinkInfo 需要更新成的新纪录内容
	///@param	pTransaction	此次更新属于的事务，NULL表示不属于任何事务，立即执行
	///@param	updateIndex	true表示需要更新索引，false表示不需要更新索引
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true);
};


#endif
