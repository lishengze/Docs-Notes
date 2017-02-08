// SelectReactor.h: interface for the CSelectReactor class.
//
// 20090316 赵鸿昊  增加虚拟函数GetSelectTimeOut，使派生类可以在主循环中
//                  插入自己的处理，并可控制select的超时时间（NT-0069）
// 20090510 赵鸿昊  NT-0074：取消GetSelectTimeOut函数，根据HandleOtherTask
//                  返回值决定Select超时时间   
// 20100520 江鹏    NT-0104-增加对文件通道通讯功能的支持
// 20110526	江鹏	NT-0133-独立线程写日志并可写多个日志
// 20110624 江鹏	NT-0139 加快响应时间：增加管道通知功能
// 20111206 江鹏    NT-0158-加快灾备切换速度
// 20120409 江鹏	NT-0139 加快响应时间：增加CReactorManager类
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECTREACTOR_H__0EB9BAD9_FE38_4CE1_9923_9FB932010E5B__INCLUDED_)
#define AFX_SELECTREACTOR_H__0EB9BAD9_FE38_4CE1_9923_9FB932010E5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Reactor.h"
#include "SocketInit.h"
#include "monitorIndex.h"
#include "Flow.h"

#ifdef LINUX
#if __GLIBC__ == 2 && __GLIBC_MINOR__ < 8
# include <asm/unistd.h>
#else // __GLIBC__ == 2 && __GLIBC_MINOR__ < 8
# include <sys/eventfd.h>
#endif // __GLIBC__ == 2 && __GLIBC_MINOR__ < 8
#endif

class CPipeEventHandler;

class CSelectReactor : public CReactor, public INotify
{
public:
	CSelectReactor(bool bUsePipe = false);
	virtual ~CSelectReactor();

private:
	virtual void DispatchIOs();
	void PrepareIds(fd_set &readfds,fd_set  &writefds, int &MaxID);
	void DispatchIO(fd_set &readfds,fd_set  &writefds, bool bTimeout);

public:
	/**
	 * 通知，以解除阻塞
	 */
	virtual void Notify();

private:
	// 管道处理器
	CPipeEventHandler* m_pPipeEventHandler;

	// 是否应该select
	bool m_bShouldSelect;
};

class CReactorManager : public INotify
{
public:
	CReactorManager(bool bUsePipe = false, int nMaxThreadNum = 0)
	{
		m_bUsePipe = bUsePipe;
		m_pReactors = new vector<CSelectReactor*>();
		m_nMaxThreadNum = nMaxThreadNum;
		m_nCreateThreadCount = 0;

		// 如果有最大线程个数指定，则先把线程建立好
		for (int i = 0; i < m_nMaxThreadNum; i ++)
		{
			CSelectReactor* reactor = new CSelectReactor(m_bUsePipe);
			m_pReactors->push_back(reactor);
		}
	}

	virtual ~CReactorManager()
	{
		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			delete m_pReactors->at(i);
		}

		m_pReactors->clear();
		delete m_pReactors;
	}

public:	
	/**
	 * 初始化reactor
	 */
	bool Create()
	{
		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			m_pReactors->at(i)->Create();
		}

		return true;
	}

	/**
	 * 阻塞reactor
	 */
	bool Join()
	{
		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			m_pReactors->at(i)->Join();
		}

		return true;
	}

	/**
	 * 终止程序主循环
	 */
	void Stop(DWORD nStopCode = 0) 
	{
		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			m_pReactors->at(i)->Stop(nStopCode);
		}
	}

	/**
	 * 清除reactor
	 */
	void Clear(DWORD nStopCode = 0) 
	{
		Stop(nStopCode);
		Join();

		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			delete m_pReactors->at(i);
		}

		m_pReactors->clear();
	}

	/**
	 * 通知，以解除阻塞
	 */
	virtual void Notify()
	{
		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			m_pReactors->at(i)->Notify();
		}
	}

	/**
	 * 建立reactor
	 */
	CReactor* CreateReactor()
	{
		CSelectReactor* reactor = NULL;

		if (m_nMaxThreadNum == 0)
		{
			// 不限线程个数
			reactor = new CSelectReactor(m_bUsePipe);
			m_pReactors->push_back(reactor);
		}
		else
		{
			// 限制最大线程个数
			// 接建立的次序取出线程
			reactor = m_pReactors->at(m_nCreateThreadCount % m_pReactors->size());
			m_nCreateThreadCount ++;
		}

		return reactor;
	}

private:
	// 是否启用管道
	bool m_bUsePipe;

	// 实际的线程
	vector<CSelectReactor*>* m_pReactors;

	// 最大线程个数
	int m_nMaxThreadNum;

	// 当前的尝试建立线程次数
	int m_nCreateThreadCount;
};

class CLogTimer : public CEventHandler
{
public:
	CLogTimer(CReactor *pReactor) : CEventHandler(pReactor)
	{
		SetTimer(1, 1000);
	}
	
	virtual ~CLogTimer()
	{
		KillTimer(1);
	}

	virtual void OnTimer(int nIDEvent)
	{
		CMonitorIndex::handleOne();
	}
};

class CLogReactor : public CSelectReactor
{
private:
	virtual bool InitInstance()
	{
		m_pLogTimer = new CLogTimer(this);

		return true;
	}
	
	virtual void ExitInstance()
	{
		delete m_pLogTimer;
	}

private:
	CLogTimer* m_pLogTimer;
};

class CSelectInterrupter
{
public:
	CSelectInterrupter();
	~CSelectInterrupter();

	inline int GetFd();
	void Interrupt();
	bool Reset();
private:
#ifdef LINUX
	int m_event_fd;
#else
#endif
	volatile bool m_signaled;
};

inline int CSelectInterrupter::GetFd()
{
#ifdef LINUX
	return m_event_fd;
#else
	return 0;
#endif
}

/**
 * CPipeEventHandler是一个通知处理对象，主要用来触发CSelectReactor,防治其深度睡眠，
 * 从而导致其不能及时处理来自队列的任务
 */
class CPipeEventHandler: public CEventHandler
{
public:
	/**
	 * 构造函数
	 * @param pReactor 当前运行对象归属的引擎 
	 */
	CPipeEventHandler(CSelectReactor *pReactor);
	
	/**
	 * 析构函数
	 */
	virtual ~CPipeEventHandler();
	
	/**
	 * 处理IO操作的读操作，由CReactor调用
	 * @return 保留
	 */
	virtual int HandleInput();
	
	/**
	 * 获取读、写socket，供select使用
	 * @param pReadId   输出参数，返回读所使用的socket，为0表示不需要读
	 * @param pWriteId  输出参数，返回写所使用的socket，为0表示不需要写 
	 */
	virtual void GetIds(int *pReadId, int *pWriteId);
	
	/**
	 * 产生通知
	 */
	virtual void Notify();
	
protected:
	CSelectReactor *m_pDestReactor;
	CSelectInterrupter m_SelectInterrupter;
	int m_nEventFD;
};

// 管理函数的函数指针
typedef void (*manage_func)(void);

// 管理端口结构
struct SManagePort
{
	// 端口
	int m_Port;
			
	// 函数
	manage_func m_Func;
			
	// 名称
	string m_Name;
			
	// 侦听socket
	int m_Socket;
};

// 管理定时器
class CManageTimer : public CEventHandler
{
public:
	CManageTimer(CReactor *pReactor, vector<SManagePort*>* pManagePorts) : CEventHandler(pReactor)
	{
		m_pManagePorts = pManagePorts;
		SetTimer(1, 100);
	}
	
	virtual ~CManageTimer()
	{
		KillTimer(1);
	}

	virtual void OnTimer(int nIDEvent)
	{
		SManagePort* pManagePort = NULL;

		for (int i = 0; i < m_pManagePorts->size(); i ++)
		{
			pManagePort = m_pManagePorts->at(i);

			// 接收用户socket
			if (pManagePort->m_Socket == NULL)
				continue;
			
			int socket = accept(pManagePort->m_Socket, NULL, NULL);
	
			if (socket == NULL)
				continue;
			
			// 关闭socket
			closesocket(socket);
								
			// 管理函数
			pManagePort->m_Func();
		
			// 日志
			REPORT_EVENT(LOG_INFO, "ManageFunc", "%s", pManagePort->m_Name.c_str());
		}		
	}

private:
	// 管理数组
	vector<SManagePort*>* m_pManagePorts;				
};

// 管理端口线程
class CManageReactor : public CSelectReactor
{
public:
	CManageReactor() : CSelectReactor(false)
	{
		m_pManagePorts = new vector<SManagePort*>();
	}

	virtual ~CManageReactor()
	{
		SManagePort* pManagePort = NULL;

		for (int i = 0; i < m_pManagePorts->size(); i ++)
		{
			pManagePort = m_pManagePorts->at(i);

			if (pManagePort->m_Socket != NULL)
				closesocket(pManagePort->m_Socket);

			delete pManagePort;
		}

		m_pManagePorts->clear();
		delete m_pManagePorts;
	}

private:
	virtual bool InitInstance()
	{
		SManagePort* pManagePort = NULL;

		for (int i = 0; i < m_pManagePorts->size(); i ++)
		{
			pManagePort = m_pManagePorts->at(i);

			if (pManagePort->m_Port != 0)
			{
				pManagePort->m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	
		
				sockaddr_in addr; 	
				memset(&addr, 0, sizeof(addr));
	
				addr.sin_family = AF_INET; 
				addr.sin_port = htons(pManagePort->m_Port);
	
				::bind(pManagePort->m_Socket ,(sockaddr*) &addr, sizeof(addr));
				listen(pManagePort->m_Socket, SOMAXCONN);
			}
		}

		m_pManageTimer = new CManageTimer(this, m_pManagePorts);

		return true;
	}
	
	virtual void ExitInstance()
	{
		delete m_pManageTimer;
	}

public:
	// 设置管理函数
	void SetManage(int port, manage_func func, const char* name)
	{
		SManagePort* pManagePort = new SManagePort();

		pManagePort->m_Port = port;
		pManagePort->m_Func = func;
		pManagePort->m_Name = name;
		pManagePort->m_Socket = NULL;

		m_pManagePorts->push_back(pManagePort);
	}

private:
	// 定时
	CManageTimer* m_pManageTimer;

	// 管理数组
	vector<SManagePort*>* m_pManagePorts;				
};

#endif // !defined(AFX_SELECTREACTOR_H__0EB9BAD9_FE38_4CE1_9923_9FB932010E5B__INCLUDED_)
