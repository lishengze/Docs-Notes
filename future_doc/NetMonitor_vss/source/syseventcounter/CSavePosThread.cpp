

#include "CSavePosThread.h"

CSavePosThread::CSavePosThread (char *pSaveFile, int keyLength) :
	m_mSaveFile(pSaveFile, keyLength),
	m_iWork(0)
{
}

CSavePosThread::~CSavePosThread(void)
{
	ExitThread();
}

/**�麯�����������һЩʵ��������
* @return true:�����ɹ� false:����ʧ��
*/
bool CSavePosThread::InitInstance(void)
{
	return true;
}

/**�麯�����������ʵ��
*/
void CSavePosThread::ExitInstance(void)
{
}

/**�߳̿�ʼ���У����麯�����������̳�ʵ��
*/
void CSavePosThread::Run(void)
{
#ifdef LINUX
	printf("CSavePosThread pid = %d tid = %d\n", getpid(), syscall(SYS_gettid));
	fflush(stdout);
#endif

	CPosition tmpPos;
	bool emptyFlag;
	while (1)
	{
		if (m_lockData.TryLock())
		{
			if (m_listData.empty())
			{
				emptyFlag = true;
			}
			else
			{
				emptyFlag = false;
				tmpPos.SetValue(
						(char *)(m_listData.front().sKey.c_str()),
						m_listData.front().m_pos,
						m_listData.front().m_time,
						m_listData.front().m_flag);
				m_listData.pop_front();
			}

			m_lockData.UnLock();
		}

		if (!emptyFlag)
		{
			m_mutexCommand.Lock();
			m_mSaveFile.WriteKeyValue(
					(char *)tmpPos.sKey.c_str(),
					tmpPos.m_pos,
					tmpPos.m_time);
			if (tmpPos.m_flag)
			{
				m_mSaveFile.FlushToFile();
			}

			m_mutexCommand.UnLock();
		}
		else
		{
			m_mutexCommand.Lock();
			m_mSaveFile.FlushToFile();
			m_mutexCommand.UnLock();
			OSSleep(1);
		}
	}
}
