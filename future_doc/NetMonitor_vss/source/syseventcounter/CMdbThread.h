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

	/* */
	private:
		// �����Ƿ���й����� ��������ʱ������
		int m_iWork;

		CNodeCacheBuffer *m_pNodeBuffer;	// �������ԵĻ�����
		CNodeCacheBuffer *m_pEventBuffer;	// �����¼��Ļ�����

	/* */
	public:
		CStatusStat m_mStatusStat;
};
