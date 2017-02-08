// 20081223 赵鸿昊  NT-0061: 修正线程安全结束问题，将互斥量设为递归型
#ifndef __MUTEX_H_
#define __MUTEX_H_
#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif


class   CMutex {
public:
	CMutex()
	{
#ifdef  WIN32
		m_lock=CreateMutex(NULL, FALSE, NULL);
#else
		pthread_mutexattr_t mattr;
		pthread_mutexattr_init(&mattr);
		pthread_mutexattr_settype(&mattr, PTHREAD_MUTEX_RECURSIVE );
		pthread_mutex_init(&m_lock, &mattr);
		pthread_mutexattr_destroy(&mattr);
#endif
	}

	~CMutex()
	{
#ifdef  WIN32
		CloseHandle(m_lock);
#else
		pthread_mutex_destroy(&m_lock);
#endif
	}


	void Lock()
	{
#ifdef  WIN32
		WaitForSingleObject(m_lock, INFINITE);
#else
		pthread_mutex_lock(&m_lock);
#endif
	}

	bool TryLock()
	{
#ifdef  WIN32
		return (WaitForSingleObject(m_lock, 0) == WAIT_OBJECT_0);
#else
		return (pthread_mutex_trylock(&m_lock) == 0);
#endif
	}

	void UnLock()
	{
#ifdef  WIN32
		ReleaseMutex(m_lock);
#else
		pthread_mutex_unlock(&m_lock);
#endif
	}	
private:
#ifdef WIN32
	HANDLE  m_lock;
#else
	pthread_mutex_t m_lock;
#endif
};

#endif
