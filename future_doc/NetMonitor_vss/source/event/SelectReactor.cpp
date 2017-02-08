// SelectReactor.cpp: implementation of the CSelectReactor class.
//
// 20090316 �Ժ��  �������⺯��GetSelectTimeOut��ͨ����ʵ�֣������Ϣ��
//                  �в�Ϊ�գ���select�ĳ�ʱʱ��Ϊ0,�Լӿ���Ϣ�����ٶ�
// 20090510 �Ժ��  NT-0074��ȡ��GetSelectTimeOut����������HandleOtherTask
//                  ����ֵ����Select��ʱʱ��   
// 20100520 ����    NT-0104-���Ӷ��ļ�ͨ��ͨѶ���ܵ�֧��
// 20110624 ����	NT-0139 �ӿ���Ӧʱ��
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "SelectReactor.h"
#include "ServiceName.h"
#include "TcpServer.h"

static CSocketInit _SOCKET_INIT;

const int SR_DEFAULT_SELECT_TIMEOUT = 10000; //΢��

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

	// �Ƿ���������Դ��������������Դ�����ʱʱ������Ϊ���ϳ�ʱ
	if (HandleOtherTask())
	{
		dwSelectTimeOut = 0;
	}

	// ����Ӧ��selectʱ��������
	if (!m_bShouldSelect)
	{
		dwSelectTimeOut = 0;
		m_bShouldSelect = true;

		// ��ֻ�йܵ����ڲ�֪ͨʱ������select
		if (m_pPipeEventHandler != NULL && m_IOList.size() == 1)
		{
			return;
		}
	}

	// ׼������io�����id
	int MaxID = 0;
	fd_set readfds, writefds;
	PrepareIds(readfds, writefds, MaxID);	
	int ret = 0;
	bool bTimeout = true;

	if (MaxID == 0)
	{
		// ���û��io�����ߣ������ùܵ�ʱ�����ߵ������֧
		SleepMs(dwSelectTimeOut / 1000);
	}
	else
	{
		// ���ó�ʱ��select
		MaxID ++;

		struct timeval timeout;
		timeout.tv_sec = dwSelectTimeOut / 1000000;
		timeout.tv_usec = dwSelectTimeOut % 1000000;

		ret = select(MaxID, &readfds, &writefds, NULL, &timeout);

		// ��¼�Ƿ�ʱ
		if (ret > 0)
		{
			bTimeout = false;
		}
	}

	// ͬ��ʱ��
	SyncTime();

	// ����io�¼��������¼�
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
			continue;	//�¼������������ѱ�ɾ��
		}
	
		pEventHandler = (CEventHandler *) (*itor);

		// ����select����˺���ʱ����io����������
		if (!bTimeout)
		{
			// ׼��id
			int nReadID = 0;
			int nWriteID = 0;
			pEventHandler->GetIds(&nReadID, &nWriteID);

			if ((*itor)==NULL)
			{
				continue;	//�¼������������ѱ�ɾ��
			}

			// ��������
			if (nReadID<0 || (nReadID>0 && FD_ISSET(nReadID,&readfds)))
			{
				pEventHandler->HandleInput();
			}
		
			if ((*itor)==NULL)
			{
				continue;	//�¼������������ѱ�ɾ��
			}
		
			// �������
			if (nWriteID<0 || (nWriteID>0 && FD_ISSET(nWriteID, &writefds)))
			{
				pEventHandler->HandleOutput();
			}
		}

		if ((*itor)==NULL)
		{
			continue;	//�¼������������ѱ�ɾ��
		}

		// ��������
		pEventHandler->HandleOther();
	}
}

void CSelectReactor::Notify()
{
	if (IsCurrentThread())
	{
		// ���ѷ�����֪ͨ
		m_bShouldSelect = false;
	}
	else
	{
		// ���˷�����֪ͨ
		if (m_pPipeEventHandler != NULL)
			m_pPipeEventHandler->Notify();
	}
}

CPipeEventHandler::CPipeEventHandler(CSelectReactor *pReactor) : CEventHandler(pReactor)
{
	m_pDestReactor = pReactor;
	m_nEventFD = m_SelectInterrupter.GetFd();
	
	// ע��io
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
