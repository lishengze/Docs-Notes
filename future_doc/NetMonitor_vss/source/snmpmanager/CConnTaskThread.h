#ifndef REF_CCONNTASKTHREAD_H
#define REF_CCONNTASKTHREAD_H

#include "systools.h"
#include "FtdPackageDesc.h"
#include "CTelnetClient.h"
#include "CFileDiff.h"
#include "CTaskManager.h"

#define MAX_DEVICE_NUM	500
#define MAX_THREAD_NUM	32

#ifdef WIN32
#define TMP_DIRNAME		"C:\\tmp"
#define RESULT_DIRNAME	"C:\\result"
#else
#define TMP_DIRNAME		"../DevCfgFiles"
#define RESULT_DIRNAME	"../DevResultFiles"
#endif
#define DEFAULT_TIMESEP "00:00:00-23:59:00.20"

typedef struct
{
	string	objectid;
	string	filedate;
	string	filetime;
	string	filecontent;
	int task_id;
	int fileversion;
} TaskConfigContent;

class CConnTaskThread :
	public CThread
{
	/* */
	private:
		/// ʱ��ʱ��ƫ����(��)
		int m_nTimeZoneSec;

		/// �߳�ID��
		int m_nThreadID;

		/// Tetnet ����ʵ��
		CTelnetClient m_oTelnetClient;

		/// �ı��Ա�ʵ��
		CFileDiff m_oFileDiff;

		///����ָ��ֵ����
		TemplateMutexCatch<CFTDRtnObjectAttrField>	m_listObjectAttr;

		///�澯�¼�����
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///��־�¼�����
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///�����ļ�����
		TemplateMutexCatch<TaskConfigContent> m_listTaskConfigContent;

		///��ǰ����
		char m_date[10];
		char m_time[10];

	/* */
	public:
		CConnTaskThread(int nThreadID)
		{
			m_nThreadID = nThreadID;

			m_nTimeZoneSec = getTimeZoneOffset();

			/// Mod by Henchi, 20111226
					/// ��������ļ��Ա�ʱ���Ե��ִ���Ϣ
			m_oFileDiff.AddRegExp("Current configuration : * *");
			m_oFileDiff.AddRegExp("ntp clock-period *");
		}

		CConnTaskThread(void)
		{
		}

		~CConnTaskThread(void)
		{
		}

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

		bool getObjectAttr(CFTDRtnObjectAttrField &objectAttr)
		{
			return m_listObjectAttr.get(objectAttr);
		}

		bool getWarningEvent(CFTDRtnWarningEventField &warningEvent)
		{
			return m_listWarningEvent.get(warningEvent);
		}

		bool getSyslogEvent(CFTDRtnSyslogEventField &syslogEvent)
		{
			return m_listSyslogEvent.get(syslogEvent);
		}

		bool getTaskConfigContent(TaskConfigContent &taskConfigContent)
		{
			return m_listTaskConfigContent.get(taskConfigContent);
		}

	/* */
	private:
		void CheckVersion(CConnTaskInfo TaskInfo, string cmd, string result);
		void SendTaskResult(
				CFTDRtnNetMonitorTaskResultField &field,
				string	cmd,
				string	result);
		void SendConfigFile(
				string	objectid,
				string	date,
				string	time,
				string	content,
				int version,
				int taskid = 0);

	/* */
	public:
		int RunTask(CConnTaskInfo TaskInfo);

		//�������ָ��ִ�н��������ָ����Ϣ
		//void ParseCommandResult(string command, string result, string objectid, string deviceip);
		//void ParseShowIPInterfaceResult(cmatch what, string objectid, string curdate, string curtime, string deviceip);
};

class CConnBaseLineTaskThread :
	public CConnTaskThread
{
	/* */
	public:
		CConnBaseLineTaskThread(void)
		{
		}

		~CConnBaseLineTaskThread(void)
		{
		}

		virtual bool  InitInstance(void);

		///**�麯�����������ʵ��
		//*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

	/* */
	public:
		bool getBaseLineTask(CFTDRtnNetBaseLineTaskField &bl_task)
		{
			return m_listBaseLineTask.get(bl_task);
		}

	/* */
	public:
		///���߱ȶԶ���
		TemplateMutexCatch
			<
				pair<CFTDRtnNetBaseLineTaskField, CFTDSysNetDeviceField>
			> m_listBaseLineTaskRun;	//��¼�·��Ļ��߱ȶ�����
		TemplateMutexCatch<CConnTaskInfo> m_listMemberLinkTask;

		///���߱ȶԶ���
		TemplateMutexCatch<CFTDRtnNetBaseLineTaskField> m_listBaseLineTask; //��¼�Ѿ�ȡ��config�Ļ��߱ȶ�����
		CMutex	m_RspBaselinepLock; //����ͬ��baseline�������ļ������ķ���;
};
#endif
