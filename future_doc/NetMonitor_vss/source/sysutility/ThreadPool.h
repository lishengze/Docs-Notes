/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file ThreadPool.h
///@brief 定义线程池，为并发操作提供便利
///@history
///20110701	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include "PrjCommon.h"
#include <Mutex.h>
#include <vector>

class PooledThread;

/// 线程池中的线程每次异步运行的对象
class Runnable
{
	/* */
	public:
		Runnable(void)
		{
		}

		virtual~Runnable(void)
		{
		}

		/// 所有需要通过线程池中的线程运行的对象，均要重载此方法来实现具体的操作
		virtual void Run(void) = 0;
};

class ThreadPool
{
	/* */
	public:
		/**线程池的构造函数
	* @param minCapacity 线程池内可同时运行的线程的最小数量，默认为2
	* @param maxCapacity  线程池内可运行的线程的最大数量，默认为8
	* @param idleTime  线程池内的线程处于idle状态的最长时间，单位为秒。超过此时间，线程被终止并回收。
	*/
		ThreadPool(int minCapacity = 2, int maxCapacity = 8);

		~ ThreadPool(void);

		/**通过线程池运行Runnable对象上的Run方法，
    * 该方法将在一个独立的线程中运行。当线程池中可运行的线程达到上限时，
    * 会抛出线程池满的异常。
	* @param func 异步执行的函数，一个参数，无返回值。
	*/
		void Run(Runnable &callback);

		/**通过线程池运行Runnable对象上的Run方法，
    * 该方法将在一个独立的线程中运行。当线程池中可运行的线程达到上限时，
    * 会等待直到有可用线程执行Runnable对象方法为止。
	* @param func 异步执行的函数，一个参数，无返回值。
	*/
		void RunWithoutThrow(Runnable &callback);

		/**终止线程池中所有线程，然后清理所有线程资源。
    * 线程池中有正在运行的线程，会等待线程完成当前操作，然后再终止线程。
	*/
		void StopAndCleanAll(void);

	/* */
	private:
		PooledThread *getAvailThread(void);

		PooledThread *createAndStartThread(void);

		DISALLOW_COPY_AND_ASSIGN(ThreadPool);

		typedef std::vector<PooledThread *> ThreadContainer;

		/// 线程池中线程的容器
		ThreadContainer m_threadSet;

		/// 线程池中提供互斥访问的锁
		CMutex m_mutex;

		/// 线程池中最少的线程数量
		int m_minCapacity;

		/// 线程池中最多的线程数量
		int m_maxCapacity;
};
#endif // _THREAD_POOL_H
