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

/// SANEventLog �����ڼ���SAN�¼���־����
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
		///���캯��
			///@param	pSANEventServerName	�ɼ�SAN�豸�¼���������
			///@param	pPath	�ɼ�SAN�¼���Ϣ�ı��ش��·��
			///@param	pSeps	�ɼ���ʱ��ζ���
		CSANEventThread(
			const char	*pSANEventServerName,
			const char	*pPath,
			const char	*pSeps);

		~ CSANEventThread(void);

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

		///��������������߳����ɵ����ݷ��ͳ�ȥ
		void GetSpi(void);

		///���������µ�SAN�豸�ɼ������
			///@param	pSANEventServerName	�ɼ�SAN�豸�¼���������
			///@param	pPath	�ɼ�SAN�¼���Ϣ�ı��ش��·��
			///@param	pSeps	�ɼ���ʱ��ζ���
		void Reset(
				const char	*pSANEventServerName,
				const char	*pPath,
				const char	*pSeps);

	/* */
	private:
		///SAN �¼�������������
		string	m_strSANEventServer;

		///�ɼ�SAN�¼���Ϣ�ı��ش��·��
		string	m_strPath;

		///�ɼ���ʱ���
		string	m_strSeps;

		///�յ���ָ�����
		string	m_strReuslt;

		///FTD���ݰ����ͻ�����
		CFTDCPackage m_pkgSend;

		// �����������ڱ������ݶ���
		CMutex	m_lockData;

		///�澯�¼�����
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
