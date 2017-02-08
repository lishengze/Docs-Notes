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
		/// 时区时间偏移量(秒)
		int m_nTimeZoneSec;

		/// 线程ID号
		int m_nThreadID;

		/// Tetnet 连接实体
		CTelnetClient m_oTelnetClient;

		/// 文本对比实体
		CFileDiff m_oFileDiff;

		///对象指标值队列
		TemplateMutexCatch<CFTDRtnObjectAttrField>	m_listObjectAttr;

		///告警事件队列
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvent;

		///日志事件队列
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvent;

		///配置文件内容
		TemplateMutexCatch<TaskConfigContent> m_listTaskConfigContent;

		///当前日期
		char m_date[10];
		char m_time[10];

	/* */
	public:
		CConnTaskThread(int nThreadID)
		{
			m_nThreadID = nThreadID;

			m_nTimeZoneSec = getTimeZoneOffset();

			/// Mod by Henchi, 20111226
					/// 添加配置文件对比时忽略的字串信息
			m_oFileDiff.AddRegExp("Current configuration : * *");
			m_oFileDiff.AddRegExp("ntp clock-period *");
		}

		CConnTaskThread(void)
		{
		}

		~CConnTaskThread(void)
		{
		}

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

		//正则过滤指令执行结果，生成指标信息
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

		///**虚函数，子类清楚实例
		//*/
		virtual void ExitInstance(void);

		/**线程开始运行，纯虚函数，子类必须继承实现
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
		///基线比对队列
		TemplateMutexCatch
			<
				pair<CFTDRtnNetBaseLineTaskField, CFTDSysNetDeviceField>
			> m_listBaseLineTaskRun;	//记录下发的基线比对任务
		TemplateMutexCatch<CConnTaskInfo> m_listMemberLinkTask;

		///基线比对队列
		TemplateMutexCatch<CFTDRtnNetBaseLineTaskField> m_listBaseLineTask; //记录已经取到config的基线比对任务
		CMutex	m_RspBaselinepLock; //用于同步baseline的配置文件与结果的发送;
};
#endif
