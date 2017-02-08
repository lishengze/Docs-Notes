// Thread.cpp: implementation of the CThread class.
//
// 20070919 �Ժ��	�޸ģ�����һ��CThread���󴴽�����߳�
// 20080724 �Ժ��  NT-0003-UserAPI֧��NameServer:
//                  WIN32�������������TLS���߳�����ʱ���ȳ�ʼ����������ӡ�HP/LINUXû����
// 20090122 �Ժ��	NT-0061:Join�����߳̾������Ϊ�գ���ֹLINUX�³����쳣
// 20120626 ����    NT-0139 �ӿ���Ӧʱ�䣺������CNotifyThread
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "Thread.h"

#ifdef WIN32
DWORD WINAPI CThread::_ThreadEntry(LPVOID pParam)
#else
void * CThread::_ThreadEntry(void *pParam)
#endif
{
	CThread *pThread = (CThread *)pParam;
	try 
  	{
#ifdef WIN32
		srand((unsigned)time(NULL));
#endif
		if(pThread->InitInstance())
		{
			pThread->Run();
		}
	}
	
	catch (CDesignError *pError)
	{
		printf("design error:\n%s\nin file %s, line %d\n",pError->GetMsg(),pError->GetFile(),pError->GetLineNo());
		exit(0);
	}
	catch (CRuntimeError *pError)
	{
		printf("runtime error:\n%s\nin file %s, line %d\n",pError->GetMsg(),pError->GetFile(),pError->GetLineNo());
		exit(0);
	}

	pThread->ExitInstance();

	pThread->m_hThread = (THREAD_HANDLE)0;
	
	return NULL;
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CThread::CThread()
{
	m_hThread = (THREAD_HANDLE)0;
	m_IDThread = 0;
}

CThread::~CThread()
{
}

bool  CThread::Create()
{
	if (m_hThread != (THREAD_HANDLE)0)
	{
		return true;
	}
	bool ret = true;
#ifdef WIN32
	m_hThread = ::CreateThread(NULL,0,_ThreadEntry,this,0,&m_IDThread);
	if(m_hThread==NULL)
	{
		ret = false;
	}
#else
	ret = (::pthread_create(&m_hThread,NULL,&_ThreadEntry , this) == 0);
#endif
	return ret;
}

bool CThread::InitInstance()
{
	return true;
}

void CThread::ExitInstance()
{
}

void CThread::OSSleep(int seconds)
{
#ifdef WIN32
	::Sleep(seconds*1000);
#else
	::sleep(seconds);
#endif
}

void CThread::SleepMs(int nMilliseconds)
{
#ifdef WIN32
	::Sleep(nMilliseconds);
#else
	::usleep(nMilliseconds*1000);
#endif
}

bool CThread::IsCurrentThread()
{
#ifdef WIN32
	return ::GetCurrentThreadId() == m_IDThread;
#else
	return ::pthread_self() == m_hThread;
#endif
}

bool CThread::Join()
{
	//20090122 �Ժ�� ��ֹLINUX��join�����쳣
	THREAD_HANDLE hThread = GetHandle();
	if(hThread == (THREAD_HANDLE)0)
	{
		return true;
	}
#ifdef WIN32
	return (WaitForSingleObject(hThread,INFINITE) != 0);
#else
	return (pthread_join(hThread, NULL) == 0);
#endif
}

void CThread::ExitThread()
{
#ifdef WIN32
	::ExitThread(0);
#else
#endif
}

CNotifyThread::CNotifyThread()
{
	m_nStopCode = 0;
}

CNotifyThread::~CNotifyThread()
{
}

void CNotifyThread::Run()
{
	m_bShouldRun = true;

	while (m_bShouldRun)
	{
		// ��ѭ������û�д�������ʱ������
		if (!LoopProc())
		{
			// �ȴ�֪ͨ�ź�
			m_NotifySignal.TimedWait(10);
		}
	}
}

void CNotifyThread::Stop(DWORD nStopCode)
{
	m_nStopCode = nStopCode;

	Notify();
	m_bShouldRun = false;
}

void CNotifyThread::Notify()
{
	m_NotifySignal.Set();
}
