/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file SyncEvent.h
///@brief 定义了事件类，为进程间同步提供一种工具
///@history
///20110701	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef _SYNC_EVENT_H
#define _SYNC_EVENT_H

#include "PrjCommon.h"
#include "SyncEvent_Platform.h"

#ifdef WIN32
class WinEvent;
#else
class PosixEvent;
#endif

/**
* SyncEvent 是用来线程间同步的对象。一个线程可以激发某个事件，那些由于等待该事件而阻塞
* 的线程会被唤醒。SyncEvent内部有2种状态，signalled/unsignalled
*/
class SyncEvent
{
	/* */
	public:

		/**
    * 构造函数，事件的初始状态为unsignalled
    * @param autoReSet 当为true时，从Wait中返回后，事件自动Reset为unsignalled状态。
    */
		SyncEvent(bool autoReSet = true) :
		m_event(autoReSet)
		{
		}

		~SyncEvent(void)
		{
		}

		/**
    * 激发事件并通知。事件的状态变为signalled，并唤醒由于Wait而阻塞的线程。
    * 当事件的autoReSet为true时，只有一个阻塞的线程会被唤醒，反之所有阻塞的线程都会被唤醒。
    */
		void Notify(void);

		/**
    * 等待事件被激发。该调用会阻塞当前线程。
    */
		void Wait(void);

		/**
    * 等待事件被激发。当超过指定时间时，事件还未被激发，抛出异常。
    * @param milliseconds 等待时间，以毫秒为单位
    */
		void Wait(long milliseconds);

		/**
    * 将事件的状态重置为unsignalled。
    */
		void Reset(void);

	/* */
	private:
		DISALLOW_COPY_AND_ASSIGN(SyncEvent);

		/// 具体平台对应的事件类
#ifdef WIN32
		WinEvent m_event;
#else
		PosixEvent	m_event;
#endif
};

inline void SyncEvent::Notify(void)
{
	m_event.Notify();
}

inline void SyncEvent::Wait(void)
{
	m_event.Wait();
}

inline void SyncEvent::Wait(long milliseconds)
{
	m_event.Wait(milliseconds);
}

inline void SyncEvent::Reset(void)
{
	m_event.Reset();
}

#endif //_SYNC_EVENT_H
