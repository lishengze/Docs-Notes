// Thread.cpp: implementation of the CThread class.
//
// 20070919 赵鸿昊	修改：避免一个CThread对象创建多个线程
// 20080724 赵鸿昊  NT-0003-UserAPI支持NameServer:
//                  WIN32下随机数种子是TLS，线程启动时，先初始化随机数种子。HP/LINUX没问题
// 20090122 赵鸿昊	NT-0061:Join函数线程句柄不能为空，防止LINUX下出现异常
// 20120626 江鹏    NT-0139 加快响应时间：增加类CNotifyThread
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
	//20090122 赵鸿昊 防止LINUX下join出现异常
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
		// 当循环处理没有处理到数据时才阻塞
		if (!LoopProc())
		{
			// 等待通知信号
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
