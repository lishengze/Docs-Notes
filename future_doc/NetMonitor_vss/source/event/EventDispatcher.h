// EventDispatcher.h: interface for the CEventDispatcher class.
//
// 20081223 �Ժ��  NT-0061: �����̰߳�ȫ�������⣬���ӱ����߳�����״̬
//                  �Ļ�����
// 20090510 �Ժ��  NT-0074��DispatchIOs��Ϊ˽�з���
// 20120409 ����    NT-0139 �ӿ���Ӧʱ�䣺���Ӹ���ȷʱ�ӷ���GetMicroClock
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVENTDISPATCHER_H__B37EDF0F_3FEF_442A_A5C9_C68C301EF606__INCLUDED_)
#define AFX_EVENTDISPATCHER_H__B37EDF0F_3FEF_442A_A5C9_C68C301EF606__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Thread.h"
#include "EventHandler.h"
#include "EventQueue.h"
#include "TimerQueue.h"

const int SM_USER		= 0x1000;


class CEventDispatcher : public CThread  
{
public:
	CEventDispatcher();
	virtual ~CEventDispatcher();

	/**ע��һ����ʱ������ж���
	* @param pEventHandler ��ʱ����ָ�� 
	* @param nIDEvent ��ʱ���ı�ʾ 
	* @param nElapse ��ʱ����ʱ���� ����
	*/
	void RegisterTimer(CEventHandler *pEventHandler, int nIDEvent, int nElapse);

	/**�Ӷ�ʱ����������ȥһ����ʱ������
	* @param pEventHandler ��ʱ�������ָ�� 
	* @param nIDEvent ��ʱ����CReatctor�ı�ʾ��=0 ��ȥ�ö�ʱ������ע��
	*        >0 ��ȥ�ö�ʱ��ָ��ע��
	*/
	void RemoveTimer(CEventHandler *pEventHandler, int nIDEvent);
	
	/*��EventHandler�����첽�¼�
	* @param pEventHander Ŀ��EventHandler
	* @param nEventID �¼�ID
	* @param dwParam ˫���Ͳ���
	* @param pParam �޷���ָ���Ͳ���
	*/
	bool PostEvent(CEventHandler *pEventHandler, int nEventID, DWORD dwParam, void *pParam);

	/*��EventHandler����ͬ���¼�
	* @param pEventHander Ŀ��EventHandler
	* @param nEventID �¼�ID
	* @param dwParam ˫���Ͳ���
	* @param pParam �޷���ָ���Ͳ���
	*/
	int SendEvent(CEventHandler *pEventHandler, int nEventID, DWORD dwParam, void *pParam);

	/**û���¼�������������¼�ʱ����Reactor�����������¼�,
	* @param nEventID �¼�ID
	* @param dwParam ��һ������
	* @param pParam �ڶ�������
	* @return ������
	*/
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);
	
	/**���һ��ʧЧ��EventHandler���������е��¼�
	* @param pEventHander ʧЧ��EventHandler
	*/
	inline void ClearEvent(CEventHandler *pEventHandler);
	/**CReactor��ʼ����
	*/
	virtual void Run();
	
	/**��ȡ��ǰϵͳʱ��
	* @return ��ǰϵͳʱ��
	*/
	inline DWORD Time();

	/**��ȡ��ǰϵͳʱ��ĺ��벿��
	* @return ��ǰϵͳʱ��ĺ��벿��
	*/
	inline DWORD GetMilTime();
	
	/**��ȡ��ǰϵͳ������
	*@return  ��ǰϵͳ���������Ժ����)
	*/
	inline DWORD GetClock();

	/**��ȡ��ǰϵͳ������
	*@return  ��ǰϵͳ����������΢���)
	*/
	inline QWORD GetMicroClock();

	/**��ֹ������ѭ��
	*/
	void Stop(DWORD nStopCode = 0);
	
	inline DWORD GetStopCode();
protected:
	/**��鶨ʱ�������Ƿ��е����¼���������ִ�ж�ʱ��������OnTimer()����
	*/
	void CheckTimer();
	
	/**��ȡ��ǰϵͳʱ��
	*/
	inline void SyncTime();

	/**���¼�������ȡ���¼������ɸ���Ӧ���¼�������
	*/
	void DispatchEvents();
private:
	virtual void DispatchIOs() = 0;

protected:
	bool m_bShouldRun;				/**< ѭ�����б�־ */
	DWORD m_nCurrMilTime;			/**< ��ǰϵͳʱ�����*/
	DWORD m_nCurrTime;				/**< ��ǰϵͳʱ����*/
	DWORD m_nCurrClock;				/**< ��ǰϵͳ������������*/
	QWORD m_nCurrMicroClock;		/**< ��ǰϵͳ��������΢��*/

	CEventQueue m_queueEvent;		/**< �¼�����*/
	CTimerQueue *m_pTimerQueue;

	DWORD m_nStopCode;

	CMutex m_lockActive;
};

inline DWORD CEventDispatcher::Time()
{
	return m_nCurrTime;
}

inline DWORD CEventDispatcher::GetMilTime()
{
	return m_nCurrMilTime;
}

inline DWORD CEventDispatcher::GetClock()
{
	return m_nCurrClock;
}

inline QWORD CEventDispatcher::GetMicroClock()
{
	return m_nCurrMicroClock;
}

inline void CEventDispatcher::SyncTime()
{
	QWORD currMicroTime = 0;

#ifdef WIN32	
   struct _timeb timebuffer;
   _ftime( &timebuffer );
	m_nCurrTime = (DWORD)timebuffer.time;	
	m_nCurrMilTime = timebuffer.millitm;
	m_nCurrClock = m_nCurrTime*1000 + timebuffer.millitm;
	currMicroTime = ((QWORD) timebuffer.millitm) * 1000;
#else
	struct timeval timeout;
    gettimeofday(&timeout, 0);
	m_nCurrTime = timeout.tv_sec;	
	m_nCurrMilTime = timeout.tv_usec/1000;
	m_nCurrClock = m_nCurrTime*1000 + timeout.tv_usec/1000;
	currMicroTime = timeout.tv_usec;
#endif

	m_nCurrMicroClock = ((QWORD) m_nCurrTime) * 1000000 + currMicroTime;
}

inline void CEventDispatcher::ClearEvent(CEventHandler *pEventHandler)
{
	m_queueEvent.ClearEvent(pEventHandler);
}

inline DWORD CEventDispatcher::GetStopCode()
{
	return m_nStopCode;
}

#endif // !defined(AFX_EVENTDISPATCHER_H__B37EDF0F_3FEF_442A_A5C9_C68C301EF606__INCLUDED_)
