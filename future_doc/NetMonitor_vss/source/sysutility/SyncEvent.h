/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file SyncEvent.h
///@brief �������¼��࣬Ϊ���̼�ͬ���ṩһ�ֹ���
///@history
///20110701	��־ΰ   �������ļ�
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
* SyncEvent �������̼߳�ͬ���Ķ���һ���߳̿��Լ���ĳ���¼�����Щ���ڵȴ����¼�������
* ���̻߳ᱻ���ѡ�SyncEvent�ڲ���2��״̬��signalled/unsignalled
*/
class SyncEvent
{
	/* */
	public:

		/**
    * ���캯�����¼��ĳ�ʼ״̬Ϊunsignalled
    * @param autoReSet ��Ϊtrueʱ����Wait�з��غ��¼��Զ�ResetΪunsignalled״̬��
    */
		SyncEvent(bool autoReSet = true) :
		m_event(autoReSet)
		{
		}

		~SyncEvent(void)
		{
		}

		/**
    * �����¼���֪ͨ���¼���״̬��Ϊsignalled������������Wait���������̡߳�
    * ���¼���autoReSetΪtrueʱ��ֻ��һ���������̻߳ᱻ���ѣ���֮�����������̶߳��ᱻ���ѡ�
    */
		void Notify(void);

		/**
    * �ȴ��¼����������õ��û�������ǰ�̡߳�
    */
		void Wait(void);

		/**
    * �ȴ��¼���������������ָ��ʱ��ʱ���¼���δ���������׳��쳣��
    * @param milliseconds �ȴ�ʱ�䣬�Ժ���Ϊ��λ
    */
		void Wait(long milliseconds);

		/**
    * ���¼���״̬����Ϊunsignalled��
    */
		void Reset(void);

	/* */
	private:
		DISALLOW_COPY_AND_ASSIGN(SyncEvent);

		/// ����ƽ̨��Ӧ���¼���
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
