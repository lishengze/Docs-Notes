#pragma once
#include "public.h"
#include "Thread.h"
#include "Mutex.h"
#include "systools.h"

class CPosition
{
	/* */
	public:
		string	sKey;
		unsigned long m_pos;
		int m_time;
		bool m_flag;

	/* */
	public:
		CPosition(void)
		{
			sKey = "";
			m_pos = 0;
			m_time = 0;
			m_flag = false;
		}

		CPosition(const CPosition &ob)
		{
			sKey = ob.sKey;
			m_pos = ob.m_pos;
			m_time = ob.m_time;
			m_flag = ob.m_flag;
		}

		CPosition(char *pKey, long mPos, int mTime, bool bFlag)
		{
			sKey = pKey;
			m_pos = mPos;
			m_time = mTime;
			m_flag = bFlag;
		}

		~CPosition(void)
		{
		}

		///����=�����
		void operator=(const CPosition &ob)
		{
			sKey = ob.sKey;
			m_pos = ob.m_pos;
			m_time = ob.m_time;
			m_flag = ob.m_flag;
		}

		void SetValue(char *pKey, long mPos, int mTime, bool bFlag)
		{
			sKey = pKey;
			m_pos = mPos;
			m_time = mTime;
			m_flag = bFlag;
		};
};

class CSavePosThread :
	public CThread
{
	/* */
	public:
		CSavePosThread(char *pSaveFile, int keyLength);
		~ CSavePosThread(void);

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);
		bool ReadKeyValue(char *pKey, list<SWriteFilePos> &mPosList)
		{
			m_mutexCommand.Lock();
			m_mSaveFile.ReadKeyValue(pKey, mPosList);
			m_mutexCommand.UnLock();
			return true;
		}

		bool WriteKeyValue(char *pKey, long mNum, int mTime, bool mFlag)
		{
			m_lockData.Lock();
			m_listData.push_back(CPosition(pKey, mNum, mTime, mFlag));
			m_lockData.UnLock();
			return true;
		}

	/* */
	private:
		// �����Ƿ���й����� ��������ʱ������
		int m_iWork;

		// �����������ڱ��� ���ݶ���
		CMutex	m_lockData;

		list<CPosition> m_listData;

		// ��Ϊ�������� ����Ҫ�����
		CMutex	m_mutexCommand;

		// �����дλ�������
		CReadWriteFile	m_mSaveFile;
};
