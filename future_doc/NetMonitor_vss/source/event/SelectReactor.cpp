// SelectReactor.cpp: implementation of the CSelectReactor class.
//
// 20090316 赵鸿昊  增加虚拟函数GetSelectTimeOut，通过其实现：如果消息队
//                  列不为空，则select的超时时间为0,以加快消息处理速度
// 20090510 赵鸿昊  NT-0074：取消GetSelectTimeOut函数，根据HandleOtherTask
//                  返回值决定Select超时时间   
// 20100520 江鹏    NT-0104-增加对文件通道通讯功能的支持
// 20110624 江鹏	NT-0139 加快响应时间
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "SelectReactor.h"
#include "ServiceName.h"
#include "TcpServer.h"

static CSocketInit _SOCKET_INIT;

const int SR_DEFAULT_SELECT_TIMEOUT = 10000; //微秒

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSelectReactor::CSelectReactor(bool bUsePipe)
{
	if (bUsePipe)
		m_pPipeEventHandler = new CPipeEventHandler(this);
	else
		m_pPipeEventHandler = NULL;

	m_bShouldSelect = true;
}

CSelectReactor::~CSelectReactor()
{
	if (m_pPipeEventHandler != NULL)
		delete m_pPipeEventHandler;
}

void CSelectReactor::DispatchIOs()
{
	DWORD dwSelectTimeOut = SR_DEFAULT_SELECT_TIMEOUT;

	// 是否有任务可以处理，如果有任务可以处理则超时时间设置为马上超时
	if (HandleOtherTask())
	{
		dwSelectTimeOut = 0;
	}

	// 当不应该select时不再阻塞
	if (!m_bShouldSelect)
	{
		dwSelectTimeOut = 0;
		m_bShouldSelect = true;

		// 当只有管道且内部通知时不再做select
		if (m_pPipeEventHandler != NULL && m_IOList.size() == 1)
		{
			return;
		}
	}

	// 准备各个io对象的id
	int MaxID = 0;
	fd_set readfds, writefds;
	PrepareIds(readfds, writefds, MaxID);	
	int ret = 0;
	bool bTimeout = true;

	if (MaxID == 0)
	{
		// 如果没有io则休眠，当启用管道时不会走到这个分支
		SleepMs(dwSelectTimeOut / 1000);
	}
	else
	{
		// 设置超时并select
		MaxID ++;

		struct timeval timeout;
		timeout.tv_sec = dwSelectTimeOut / 1000000;
		timeout.tv_usec = dwSelectTimeOut % 1000000;

		ret = select(MaxID, &readfds, &writefds, NULL, &timeout);

		// 记录是否超时
		if (ret > 0)
		{
			bTimeout = false;
		}
	}

	// 同步时间
	SyncTime();

	// 处理io事件和其它事件
	DispatchIO(readfds, writefds, bTimeout);
}

void CSelectReactor::PrepareIds(fd_set &readfds,fd_set  &writefds, int &MaxID)
{
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	
	if(	m_bIOListHasNull)
	{
		m_IOList.remove(NULL);
		m_bIOListHasNull=false;
	}
	
	CEventHandlerList::iterator itor=m_IOList.begin();
	for(; itor!=m_IOList.end(); itor++)
	{
		if((*itor) == NULL){
			continue;
		}
		
		int nReadID = 0;
		int nWriteID = 0;

		CEventHandler *pp = (CEventHandler *)(*itor);
		((CEventHandler *)(*itor))->GetIds(&nReadID, &nWriteID);
		
		if(nReadID>0)
		{
			FD_SET(nReadID, &readfds);
			if(MaxID < nReadID)
			{
				MaxID = nReadID;
			}
		}
		if(nWriteID>0)
		{
			FD_SET(nWriteID,&writefds);
			if(MaxID < nWriteID)
			{
				MaxID = nWriteID;
			}
		}
	}
	
}

void CSelectReactor::DispatchIO(fd_set &readfds,fd_set  &writefds, bool bTimeout)
{
	CEventHandler* pEventHandler = NULL;
	CEventHandlerList::iterator itor=m_IOList.begin();
	
	for(; itor != m_IOList.end(); itor++)
	{
		if ((*itor)==NULL)
		{
			continue;	//事件处理对象可能已被删除
		}
	
		pEventHandler = (CEventHandler *) (*itor);

		// 当是select进入此函数时才做io的输入和输出
		if (!bTimeout)
		{
			// 准备id
			int nReadID = 0;
			int nWriteID = 0;
			pEventHandler->GetIds(&nReadID, &nWriteID);

			if ((*itor)==NULL)
			{
				continue;	//事件处理对象可能已被删除
			}

			// 处理输入
			if (nReadID<0 || (nReadID>0 && FD_ISSET(nReadID,&readfds)))
			{
				pEventHandler->HandleInput();
			}
		
			if ((*itor)==NULL)
			{
				continue;	//事件处理对象可能已被删除
			}
		
			// 处理输出
			if (nWriteID<0 || (nWriteID>0 && FD_ISSET(nWriteID, &writefds)))
			{
				pEventHandler->HandleOutput();
			}
		}

		if ((*itor)==NULL)
		{
			continue;	//事件处理对象可能已被删除
		}

		// 处理其它
		pEventHandler->HandleOther();
	}
}

void CSelectReactor::Notify()
{
	if (IsCurrentThread())
	{
		// 自已发出的通知
		m_bShouldSelect = false;
	}
	else
	{
		// 别人发出的通知
		if (m_pPipeEventHandler != NULL)
			m_pPipeEventHandler->Notify();
	}
}

CPipeEventHandler::CPipeEventHandler(CSelectReactor *pReactor) : CEventHandler(pReactor)
{
	m_pDestReactor = pReactor;
	m_nEventFD = m_SelectInterrupter.GetFd();
	
	// 注册io
	m_pDestReactor->RegisterIO(this);
}

CPipeEventHandler::~CPipeEventHandler()
{
}

void CPipeEventHandler::GetIds(int *pReadId, int *pWriteId)
{
	*pReadId = m_nEventFD;
	*pWriteId = 0;
}

int CPipeEventHandler::HandleInput()
{
	m_SelectInterrupter.Reset();

	return 0;
}

void CPipeEventHandler::Notify()
{	
	m_SelectInterrupter.Interrupt();
}

CSelectInterrupter::CSelectInterrupter()
{
	m_signaled = false;
#ifdef LINUX
#if __GLIBC__ == 2 && __GLIBC_MINOR__ < 8
	m_event_fd = syscall(__NR_eventfd, 0);
#else // __GLIBC__ == 2 && __GLIBC_MINOR__ < 8
	m_event_fd = ::eventfd(0, 0);
#endif // __GLIBC__ == 2 && __GLIBC_MINOR__ < 8
	if (m_event_fd <= 0)
	{
		EMERGENCY_EXIT("create eventfd\n");
	}
	::fcntl(m_event_fd, F_SETFL, O_NONBLOCK);
#else
#endif
}

CSelectInterrupter::~CSelectInterrupter()
{
#ifdef LINUX
	close(m_event_fd);
#else
#endif
}

void CSelectInterrupter::Interrupt()
{
	if (!m_signaled)
	{
		m_signaled = true;
#ifdef LINUX
		uint64_t counter(1UL);
		::write(m_event_fd, &counter, sizeof(uint64_t));
#else
#endif
	}
}

bool CSelectInterrupter::Reset()
{
	bool signaled = m_signaled;
#ifdef LINUX
	uint64_t counter(0);
	int bytes_read = 0;
	do 
	{
		bytes_read = ::read(m_event_fd, &counter, sizeof(uint64_t));
	} while (bytes_read > 0);
#else
#endif

	m_signaled = false;
	
	return signaled;
}
