/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file ScopedLock.h
///@brief 定义了mutex的RAII类
///@history
///20110701	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef _SCOPED_LOCK_H
#define _SCOPED_LOCK_H

#include "PrjCommon.h"

template<typename T>
class ScopeLock
{
	/* */
	public:

		/// 构造函数
		    ///@param lock 锁资源，自动将锁资源上锁。
		ScopeLock(T &lock) :
		m_lock(lock)
		{
			m_lock.Lock();
		}

		/// 析构函数，自动将锁资源解锁
		~ScopeLock(void)
		{
			m_lock.UnLock();
		}

	/* */
	private:
		DISALLOW_COPY_AND_ASSIGN(ScopeLock);

		/// 锁资源
		T &m_lock;
};
#endif //_SCOPED_LOCK_H
