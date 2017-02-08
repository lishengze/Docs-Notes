#pragma once
#include "public.h"
#include "Thread.h"
#include "Mutex.h"
#include "systools.h"
#include "databaseData.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "FtdData.h"
#include "CachedFileFlow.h"
#include "CStatusAnalysis.h"
#include "EventFrontServer.h"

#define SYSTEM_TYPE_REAL_UNREAL 0
#define SYSTEM_TYPE_NETMONITOR	1

class CMdbThread :
	public CThread
{
	/* */
	public:
		CMdbThread(
			CNodeCacheBuffer *pNodeBuffer,
			CNodeCacheBuffer *pEventBuffer,
			char *pEventCfgPath);
		~ CMdbThread(void);

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

	/* */
	private:
		// 控制是否进行工作， 不工作的时候休眠
		int m_iWork;

		CNodeCacheBuffer *m_pNodeBuffer;	// 保存属性的缓冲区
		CNodeCacheBuffer *m_pEventBuffer;	// 保存事件的缓冲区

	/* */
	public:
		CStatusStat m_mStatusStat;
};
