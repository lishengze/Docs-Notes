#include "systools.h"
#include "FileRecordFinder.h"

#include "FtdPackageDesc.h"

/// Trap ��Ϣ���ݽṹ
class CSysLogRecord
{
	/* */
	public:
		CSysLogRecord(void);
		CSysLogRecord(const CSysLogRecord& rec);

		CSysLogRecord(char szYear);

		~ CSysLogRecord(void);

		void Reset(void);

		bool IsValidRec(string record);

		bool LoadRec(string record);

		string	GetDateString(char *pszMonth, char *pszDay);

		string	strDate;
		string	strTime;
		string	strHost;
		string	strInfo;
		string	strYear;
		bool bValidFlag;
};

class CSysLogReader :
	public CThread
{
	/* */
	public:
		CSysLogReader(void);

		CSysLogReader(string strFilePath);

		CSysLogReader(string strFilePath, long lReads);

		CSysLogReader(string strFilePath, long lReads, int iReadTime);

		~ CSysLogReader(void);

		bool OpenFile(void);

		void KeepReadFile(void);

		void FilterEvents(CSysLogRecord record);

		//κ��add
		void FilterEventsNew(CSysLogRecord record);

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

		TemplateMutexCatch<CFTDRtnWarningEventField> m_listWarningEvents;
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listSyslogEvents;

	/* */
	private:
		string	m_strFilePath;
		time_t	m_tModify;
		bool m_bFileModify;
		FILE *m_pFile;
		off_t m_lReadPos;
		bool m_bReadFlag;
		int m_iValidFlag;
		int m_iReadTime;

		TemplateMutexCatch<CSysLogRecord> m_listRecord;
		time_t	m_tLastLoadTime;
};
