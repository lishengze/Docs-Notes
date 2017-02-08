#include "platform.h"
#include "ThreadPool.h"
#include "ScopedLock.h"
#include <Thread.h>
#include <RuntimeError.h>
#include "SyncEvent.h"

class PooledThread :
	public CThread
{
	/* */
	public:
		PooledThread(void);
		~ PooledThread(void);

		void Start(void);

		void End(void);

		void RunCallback(Runnable &callback);

		void JoinCallback(void);

		bool Idle(void);

	/* */
	private:
		// Derive from CThread
		void Run(void);

		DISALLOW_COPY_AND_ASSIGN(PooledThread);

		bool m_idle;
		bool m_quit;

		Runnable *m_cb;
		SyncEvent m_start;
		SyncEvent m_cbReady;
		SyncEvent m_cbCompleted;
		CMutex	m_mutex;
};

PooledThread::PooledThread(void) :
	CThread(),
	m_idle(true),
	m_quit(false),
	m_cb(NULL)
{
}

PooledThread::~PooledThread(void)
{
}

void PooledThread::Start(void)
{
	Create();

	m_start.Wait();
}

void PooledThread::End(void)
{
	{
		ScopeLock<CMutex> lock(m_mutex);

		//如果在RunCallback后立即调用End，需要睡眠1毫秒，让先前的callback能够被执行
		if (!m_idle)
		{
			SleepMs(1);
		}

		m_quit = true;
		m_cbReady.Notify();
	}

	Join();
	delete this;
}

void PooledThread::RunCallback(Runnable &callback)
{
	ScopeLock<CMutex> lock(m_mutex);

	m_cb = &callback;
	m_idle = false;
	m_cbReady.Notify();
}

bool PooledThread::Idle(void)
{
	return m_idle;
}

void PooledThread::Run(void)
{
	m_start.Notify();	// m_start.Notify 如果先于m_start.Wait()，会造成死锁问题，待改进
	while (1)
	{
		m_cbReady.Wait();

		if (m_quit)
		{
			break;
		}

		assert(m_cb);
		m_cb->Run();

		ScopeLock<CMutex> lock(m_mutex);

		m_idle = true;
		m_cbCompleted.Notify();
	}
}

void PooledThread::JoinCallback(void)
{
	if (!m_quit)
	{
		m_cbCompleted.Wait();
	}
}

/**ThreadPool的实现。
*/
ThreadPool::ThreadPool(int minCapacity, int maxCapacity) :
	m_minCapacity(minCapacity),
	m_maxCapacity(maxCapacity)
{
	assert(
		m_minCapacity > 0
		&&	m_maxCapacity > 0
		&&	m_minCapacity <= m_maxCapacity);

	for (int i = 0; i < m_minCapacity; i++)
	{
		createAndStartThread();
	}
}

ThreadPool::~ThreadPool(void)
{
	StopAndCleanAll();
}

void ThreadPool::Run(Runnable &callback)
{
	getAvailThread()->RunCallback(callback);
}

#ifdef WINDOWS
#define SLEEP_Milli(ms) Sleep(ms)
#else
#define SLEEP_Milli(ms) usleep(ms * 1000)
#endif
void ThreadPool::RunWithoutThrow(Runnable &callback)
{
	bool hasException = false;
	do
	{
		try
		{
			Run(callback);
			hasException = false;
		}

		catch (const CRuntimeError *)
		{
			SLEEP_Milli(200);
			hasException = true;
		}
	} while (hasException);
}

PooledThread *ThreadPool::createAndStartThread(void)
{
	PooledThread *pThread = new PooledThread();
	m_threadSet.push_back(pThread);
	pThread->Start();

	return pThread;
}

PooledThread *ThreadPool::getAvailThread(void)
{
	ScopeLock<CMutex> lock(m_mutex);

	PooledThread *pThread = 0;

	for (ThreadContainer::iterator it = m_threadSet.begin();
		 it != m_threadSet.end();
		 it++)
	{
		if ((*it)->Idle())
		{
			pThread = *it;
			break;
		}
	}

	if (!pThread)
	{
		if ((int)m_threadSet.size() < m_maxCapacity)
		{
			pThread = createAndStartThread();
		}
		else
		{
			//TODO change this
			throw new CRuntimeError("No available thread", __FILE__, __LINE__);
		}
	}

	return pThread;
}

void ThreadPool::StopAndCleanAll(void)
{
	ScopeLock<CMutex> lock(m_mutex);

	for (ThreadContainer::iterator it = m_threadSet.begin();
		 it != m_threadSet.end();
		 it++)
	{
		(*it)->End();
	}

	m_threadSet.clear();
}
