// Thread.h: interface for the CThread class .
//
// 20120626 ����   NT-0139 �ӿ���Ӧʱ�䣺������CNotifyThread
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREAD_H__78AB7118_0B3F_4314_A272_B539E6E11EA6__INCLUDED_)
#define AFX_THREAD_H__78AB7118_0B3F_4314_A272_B539E6E11EA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#include <windows.h>
typedef HANDLE THREAD_HANDLE ;
#else
#include <pthread.h>
typedef pthread_t THREAD_HANDLE ;
#endif

#include "Semaphore.h"
#include "Flow.h"

/**������һ���̶߳���
*/
class  CThread  
{
public:
	/**���캯��
	*/
	CThread();
	
	/**��������
	*/
	virtual ~CThread();
	
	/**����һ���߳�
	* @return true:�����ɹ� false:����ʧ��
	*/
	virtual bool Create();
	
	/**��ñ��̶߳���洢���߳̾��
	* @return ���̶߳���洢���߳̾���߳̾��
	*/
	inline THREAD_HANDLE GetHandle();

	/**�߳�˯��seconds��
	* @param seconds ˯������
	*/
	void OSSleep(int nSeconds);

	void SleepMs(int nMilliseconds);

	bool Join();

	bool IsCurrentThread();

	void ExitThread();

private:	
#ifdef WIN32
	static DWORD WINAPI _ThreadEntry(LPVOID pParam);
#else
	static void * _ThreadEntry(void *pParam);
#endif

	/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
	virtual bool InitInstance();
	
	/**�麯�����������ʵ��
	*/
	virtual void ExitInstance();
	
	/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
	virtual void Run() = 0;
	
private:
	 THREAD_HANDLE m_hThread;	/**< �߳̾�� */
	 DWORD m_IDThread;

};


inline THREAD_HANDLE CThread::GetHandle()
{
	return m_hThread;
}

// ֪ͨ�߳�
class CNotifyThread : public CThread, public INotify
{
public:
	CNotifyThread();
	virtual ~CNotifyThread();

	/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
	virtual void Run();

	/**��ֹ������ѭ��
	*/
	virtual void Stop(DWORD nStopCode = 0);

	// ֪ͨ
	virtual void Notify();

	// ѭ������
	virtual bool LoopProc() = 0;

protected:
	CSignal m_NotifySignal;
	bool m_bShouldRun;				/**< ѭ�����б�־ */
	DWORD m_nStopCode;
};

#endif // !defined(AFX_THREAD_H__78AB7118_0B3F_4314_A272_B539E6E11EA6__INCLUDED_)
