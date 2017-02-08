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

		///重载=运算符
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

		/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
		virtual bool InitInstance(void);

		/**虚函数，子类清楚实例
	*/
		virtual void ExitInstance(void);

		/**线程开始运行，纯虚函数，子类必须继承实现
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
		// 控制是否进行工作， 不工作的时候休眠
		int m_iWork;

		// 数据锁，用于保护 数据队列
		CMutex	m_lockData;

		list<CPosition> m_listData;

		// 作为主程序发送 工作要求的锁
		CMutex	m_mutexCommand;

		// 保存读写位置类对象
		CReadWriteFile	m_mSaveFile;
};
