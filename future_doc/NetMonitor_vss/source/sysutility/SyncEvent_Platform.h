/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file SyncEvent_Platfrom.h
///@brief 定义了事件类，为进程间同步提供一种工具
///@history
///20110701	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef _SYNC_EVENT_PLATFORM_H
#define _SYNC_EVENT_PLATFORM_H

/**
* 不同平台上SyncEvent的实现
*/
#include <platform.h>

#ifdef WIN32

/// Windows平台上事件的实现
class WinEvent
{
	/* */
	public:
		WinEvent(bool autoReSet);
		~ WinEvent(void);

		void Notify(void);
		void Wait(void);
		void Wait(long milliseconds);
		void Reset(void);

	/* */
	private:
		HANDLE	m_event;
};

inline WinEvent::WinEvent(bool autoReSet)
{
	m_event = CreateEvent(NULL, autoReSet ? FALSE : TRUE, FALSE, NULL);
}

inline WinEvent::~WinEvent(void)
{
	CloseHandle(m_event);
}

inline void WinEvent::Notify(void)
{
	if (!SetEvent(m_event))
	{
		//TODO log
	}
}

inline void WinEvent::Wait(void)
{
	switch (WaitForSingleObject(m_event, INFINITE))
	{
		case WAIT_OBJECT_0:
			return;
		default:
			//TODO
			;
	}
}

inline void WinEvent::Wait(long milliseconds)
{
	//TODO
}

inline void WinEvent::Reset(void)
{
	if (!ResetEvent(m_event))
	{
		//TODO log
	}
}

#else // posix
	
	/// 基于posix标准的事件的实现
class PosixEvent
{
	/* */
	public:
		PosixEvent(bool autoReSet);
		~ PosixEvent(void);

		void Notify(void);
		void Wait(void);
		void Wait(long milliseconds);
		void Reset(void);

	/* */
	private:
		bool m_auto;
		volatile bool m_signalled;
		pthread_mutex_t m_mutex;
		pthread_cond_t	m_cond;
};

inline PosixEvent::PosixEvent(bool autoReSet) :
	m_auto(autoReSet),
	m_signalled(false)
{
	pthread_mutex_init(&m_mutex, NULL);
	pthread_cond_init(&m_cond, NULL);
}

inline PosixEvent::~PosixEvent(void)
{
	pthread_cond_destroy(&m_cond);
	pthread_mutex_destroy(&m_mutex);
}

inline void PosixEvent::Notify(void)
{
	pthread_mutex_lock(&m_mutex);

	m_signalled = true;
	if (m_auto)
	{
		pthread_cond_signal(&m_cond);
	}
	else
	{
		pthread_cond_broadcast(&m_cond);
	}

	pthread_mutex_unlock(&m_mutex);
}

inline void PosixEvent::Wait(void)
{
	pthread_mutex_lock(&m_mutex);

	pthread_cond_wait(&m_cond, &m_mutex);

	if (m_auto)
	{
		m_signalled = false;
	}

	pthread_mutex_unlock(&m_mutex);
}

inline void PosixEvent::Wait(long milliseconds)
{
	//TODO
}

inline void PosixEvent::Reset(void)
{
	pthread_mutex_lock(&m_mutex);

	m_signalled = false;

	pthread_mutex_unlock(&m_mutex);
}

#endif // end WIN32
#endif // _SYNC_EVENT_PLATFORM_H
