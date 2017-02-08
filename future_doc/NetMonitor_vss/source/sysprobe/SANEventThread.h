#include "public.h"
#include "Thread.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "SyslogSpiImpl.h"
#include "DatabaseSpiImpl.h"
#include "list"

using namespace std;

#define TAG_INFOTYPE_PRO		"problem"
#define TAG_INFOTYPE_INF		"information"

#define KEYWORD_INFOTYPE_PRO	"---------- Problem Found:"
#define KEYWORD_INFOTYPE_INF	"---------- Information:"
#define KEYWORD_EVENTTIME		"    Event Time:"
#define KEYWORD_REPORTTIME		"    Report Time:"
#define KEYWORD_EXPTIME			"    Expiration Time:"
#define KEYWORD_STORAGE_SRV		"Storage Management Server:"
#define KEYWORD_CONTROLLER		"Controller Type:"
#define KEYWORD_DEVICE_TYPE		"Device Type:"
#define KEYWORD_BREIF			"Brief Description:"
#define KEYWORD_SEVERITY		"Rule Severity:"
#define KEYWORD_REPORT_NODE		"Reporting Node:"
#define KEYWORD_DESCRIPTION		"Full Description:"
#define KEYWORD_STORAGE_SYS		"   Storage System Name:"

#define KEYNUM_DEVICE_TYPE		1
#define KEYNUM_BREIF			2
#define KEYNUM_SEVERITY			3
#define KEYNUM_REPORT_NODE		4
#define KEYNUM_DESCRIPTION		5

/// SANEventLog 类用于加载SAN事件日志内容
class SANEventLog
{
	/* */
	public:
		SANEventLog(void);
		~ SANEventLog(void);

		bool LoadFile(string strFileName);

		list<string> &GetLinesList(void);
		list<string> m_strLines;
};

class SANEventInfo
{
	/* */
	public:
		SANEventInfo(void);
		~ SANEventInfo(void);
		void Reset(void);

		string	m_strInfoType;
		string	m_strInfoTag;
		string	m_strEventTime;
		string	m_strReportTime;
		string	m_strExpirationTime;
		string	m_strServer;
		string	m_strController;
		string	m_strStorageSystem;
		string	m_strDeviceType;
		string	m_strBreif;
		string	m_strRuleSeverity;
		string	m_strReportNode;
		string	m_strDescription;
};

class SANEventLogAnalyzer
{
	/* */
	public:
		SANEventLogAnalyzer(string strFileName);
		~ SANEventLogAnalyzer(void);

	/* */
	private:
		void Analyze(void);
		void AnalyzeLine(string &LineInfo);
		bool HaveKey(string &LineInfo);
		bool IsBlank(string &LineInfo);

		int m_iTagKey;
		bool m_bWaitValue;
		SANEventLog m_EventLog;
		SANEventInfo m_EventInfo;
		list<SANEventInfo>	m_listSANEventInfo;
};

class CSANEventThread :
	public CThread
{
	/* */
	public:
		///构造函数
			///@param	pSANEventServerName	采集SAN设备事件服务器名
			///@param	pPath	采集SAN事件信息的本地存放路径
			///@param	pSeps	采集的时间段定义
		CSANEventThread(
			const char	*pSANEventServerName,
			const char	*pPath,
			const char	*pSeps);

		~ CSANEventThread(void);

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

		///用于让主程序把线程生成的数据发送出去
		void GetSpi(void);

		///用于增加新的SAN设备采集命令函数
			///@param	pSANEventServerName	采集SAN设备事件服务器名
			///@param	pPath	采集SAN事件信息的本地存放路径
			///@param	pSeps	采集的时间段定义
		void Reset(
				const char	*pSANEventServerName,
				const char	*pPath,
				const char	*pSeps);

	/* */
	private:
		///SAN 事件服务器对象名
		string	m_strSANEventServer;

		///采集SAN事件信息的本地存放路径
		string	m_strPath;

		///采集的时间段
		string	m_strSeps;

		///收到的指令输出
		string	m_strReuslt;

		///FTD数据包发送缓冲区
		CFTDCPackage m_pkgSend;

		// 数据锁，用于保护数据队列
		CMutex	m_lockData;

		///告警事件队列
		list<CFTDRtnWarningEventField>	m_warningEvent;

		CJudgeRun *m_pJudgeRun;

		string	GenCmdline(int nInterval);

#ifdef WINDOWS
		HANDLE	hChildStdinRd;
		HANDLE	hChildStdinWr;
		HANDLE	hChildStdinWrDup;
		HANDLE	hChildStdoutRd;
		HANDLE	hChildStdoutWr;
		HANDLE	hChildStdoutRdDup;
		HANDLE	hInputFile;
		HANDLE	hStdout;
		BOOL CreateChildProcess(const char *pCommand);
		VOID ReadFromPipe(const char *pCommand);
		VOID ErrorExit(LPTSTR, const char *);
		VOID ErrMsg(LPTSTR, BOOL);
		VOID SANEventCapture(const char *pCommand);
#endif
};
