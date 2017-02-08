// SelectReactor.h: interface for the CSelectReactor class.
//
// 20090316 �Ժ��  �������⺯��GetSelectTimeOut��ʹ�������������ѭ����
//                  �����Լ��Ĵ������ɿ���select�ĳ�ʱʱ�䣨NT-0069��
// 20090510 �Ժ��  NT-0074��ȡ��GetSelectTimeOut����������HandleOtherTask
//                  ����ֵ����Select��ʱʱ��   
// 20100520 ����    NT-0104-���Ӷ��ļ�ͨ��ͨѶ���ܵ�֧��
// 20110526	����	NT-0133-�����߳�д��־����д�����־
// 20110624 ����	NT-0139 �ӿ���Ӧʱ�䣺���ӹܵ�֪ͨ����
// 20111206 ����    NT-0158-�ӿ��ֱ��л��ٶ�
// 20120409 ����	NT-0139 �ӿ���Ӧʱ�䣺����CReactorManager��
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
	 * ֪ͨ���Խ������
	 */
	virtual void Notify();

private:
	// �ܵ�������
	CPipeEventHandler* m_pPipeEventHandler;

	// �Ƿ�Ӧ��select
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

		// ���������̸߳���ָ�������Ȱ��߳̽�����
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
	 * ��ʼ��reactor
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
	 * ����reactor
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
	 * ��ֹ������ѭ��
	 */
	void Stop(DWORD nStopCode = 0) 
	{
		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			m_pReactors->at(i)->Stop(nStopCode);
		}
	}

	/**
	 * ���reactor
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
	 * ֪ͨ���Խ������
	 */
	virtual void Notify()
	{
		for (int i = 0; i < m_pReactors->size(); i ++)
		{
			m_pReactors->at(i)->Notify();
		}
	}

	/**
	 * ����reactor
	 */
	CReactor* CreateReactor()
	{
		CSelectReactor* reactor = NULL;

		if (m_nMaxThreadNum == 0)
		{
			// �����̸߳���
			reactor = new CSelectReactor(m_bUsePipe);
			m_pReactors->push_back(reactor);
		}
		else
		{
			// ��������̸߳���
			// �ӽ����Ĵ���ȡ���߳�
			reactor = m_pReactors->at(m_nCreateThreadCount % m_pReactors->size());
			m_nCreateThreadCount ++;
		}

		return reactor;
	}

private:
	// �Ƿ����ùܵ�
	bool m_bUsePipe;

	// ʵ�ʵ��߳�
	vector<CSelectReactor*>* m_pReactors;

	// ����̸߳���
	int m_nMaxThreadNum;

	// ��ǰ�ĳ��Խ����̴߳���
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
 * CPipeEventHandler��һ��֪ͨ���������Ҫ��������CSelectReactor,���������˯�ߣ�
 * �Ӷ������䲻�ܼ�ʱ�������Զ��е�����
 */
class CPipeEventHandler: public CEventHandler
{
public:
	/**
	 * ���캯��
	 * @param pReactor ��ǰ���ж������������ 
	 */
	CPipeEventHandler(CSelectReactor *pReactor);
	
	/**
	 * ��������
	 */
	virtual ~CPipeEventHandler();
	
	/**
	 * ����IO�����Ķ���������CReactor����
	 * @return ����
	 */
	virtual int HandleInput();
	
	/**
	 * ��ȡ����дsocket����selectʹ��
	 * @param pReadId   ������������ض���ʹ�õ�socket��Ϊ0��ʾ����Ҫ��
	 * @param pWriteId  �������������д��ʹ�õ�socket��Ϊ0��ʾ����Ҫд 
	 */
	virtual void GetIds(int *pReadId, int *pWriteId);
	
	/**
	 * ����֪ͨ
	 */
	virtual void Notify();
	
protected:
	CSelectReactor *m_pDestReactor;
	CSelectInterrupter m_SelectInterrupter;
	int m_nEventFD;
};

// �������ĺ���ָ��
typedef void (*manage_func)(void);

// ����˿ڽṹ
struct SManagePort
{
	// �˿�
	int m_Port;
			
	// ����
	manage_func m_Func;
			
	// ����
	string m_Name;
			
	// ����socket
	int m_Socket;
};

// ����ʱ��
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

			// �����û�socket
			if (pManagePort->m_Socket == NULL)
				continue;
			
			int socket = accept(pManagePort->m_Socket, NULL, NULL);
	
			if (socket == NULL)
				continue;
			
			// �ر�socket
			closesocket(socket);
								
			// ������
			pManagePort->m_Func();
		
			// ��־
			REPORT_EVENT(LOG_INFO, "ManageFunc", "%s", pManagePort->m_Name.c_str());
		}		
	}

private:
	// ��������
	vector<SManagePort*>* m_pManagePorts;				
};

// ����˿��߳�
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
	// ���ù�����
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
	// ��ʱ
	CManageTimer* m_pManageTimer;

	// ��������
	vector<SManagePort*>* m_pManagePorts;				
};

#endif // !defined(AFX_SELECTREACTOR_H__0EB9BAD9_FE38_4CE1_9923_9FB932010E5B__INCLUDED_)
