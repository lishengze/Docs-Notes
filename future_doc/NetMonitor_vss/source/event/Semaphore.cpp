// Semaphore.cpp: implementation of the CSemaphore class.
//
// 20120626 江鹏   NT-0139 加快响应时间：增加类CSignal
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "Semaphore.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSemaphore::CSemaphore(int nValue)
{
#ifdef WIN32
	m_sid = CreateSemaphore(NULL, nValue, 1000, NULL);
#elif defined(AIX) | defined(HP_UX)
	m_nValue = nValue;
	pthread_mutex_init(&m_mutex, NULL);
	pthread_cond_init(&m_cond,	NULL);
#else
	sem_init(&m_sid, 0, nValue);
#endif
}

CSemaphore::~CSemaphore()
{
#ifdef WIN32
	CloseHandle(m_sid);
#elif defined(AIX) | defined(HP_UX)
	pthread_cond_destroy(&m_cond);
	pthread_mutex_destroy(&m_mutex);
#else
	sem_destroy(&m_sid);
#endif
}

bool CSemaphore::Lock()
{
#ifdef WIN32
	return (WaitForSingleObject(m_sid, INFINITE)==WAIT_OBJECT_0);
#elif defined(AIX)|defined(HP_UX)	
	pthread_mutex_lock(&m_mutex);
	while (m_nValue <= 0)
	{
		pthread_cond_wait(&m_cond,&m_mutex);
	}
	if(m_nValue > 0)
	{
		m_nValue--;
	}
	pthread_mutex_unlock(&m_mutex);
	return true;
#else
	return (sem_wait(&m_sid) == 0);
#endif
}

bool CSemaphore::UnLock(int *pPrevCount)
{
#ifdef WIN32
	return (ReleaseSemaphore(m_sid, 1, (long *)pPrevCount) == TRUE);
#elif defined(AIX) | defined(HP_UX)	
	pthread_mutex_lock(&m_mutex);
	m_nValue++;
	pthread_cond_signal(&m_cond);
	pthread_mutex_unlock(&m_mutex);
	if(pPrevCount != NULL)
	{
		*pPrevCount = m_nValue;
	}
	return true;
#else
	if(sem_post(&m_sid) == 0)
	{
		if(pPrevCount != NULL)
		{
			sem_getvalue(&m_sid, pPrevCount);
		}
		return true;
	}
	return false;
#endif
}

CSignal::CSignal(int value)
{	
#ifdef WIN32
	m_Semaphore = CreateSemaphore(NULL, value, LONG_MAX, NULL);
#else
	sem_init(&m_Semaphore, 0, value);
#endif
}

CSignal::~CSignal()
{
#ifdef WIN32
	CloseHandle(m_Semaphore);
#else
	sem_destroy(&m_Semaphore);
#endif
}

// 永远等待
void CSignal::Join()
{
#ifdef WIN32
	WaitForSingleObject(m_Semaphore, INFINITE);		
#else
	sem_wait(&m_Semaphore);
#endif
}

// 尝试等待到信号
bool CSignal::TryWait()
{
#ifdef WIN32
	return (WaitForSingleObject(m_Semaphore, 0) == WAIT_OBJECT_0);
#else
	return (sem_trywait(&m_Semaphore) == 0);
#endif
}

// 尝试等待到信号，超时返回
bool CSignal::TimedWait(int milliSecond)
{
#ifdef WIN32
	return (WaitForSingleObject(m_Semaphore, milliSecond) == WAIT_OBJECT_0);
#else
	// 设置超时的绝对时间
	struct timespec abs_timeout;
	
	clock_gettime(CLOCK_REALTIME, &abs_timeout);	
	abs_timeout.tv_nsec += milliSecond * 1000 * 1000;
	
	while (abs_timeout.tv_nsec > 999999999)
	{
		abs_timeout.tv_nsec -= 1000000000;
		abs_timeout.tv_sec ++;
	}
	
	return (sem_timedwait(&m_Semaphore, &abs_timeout) == 0);	
#endif
}

// 设置信号
void CSignal::Set()
{
#ifdef WIN32
	ReleaseSemaphore(m_Semaphore, 1, NULL);
#else
	sem_post(&m_Semaphore);
#endif
}
