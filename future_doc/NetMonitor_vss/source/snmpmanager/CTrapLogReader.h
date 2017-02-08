#include "systools.h"

/// Trap ��Ϣ���ݽṹ
class CTrapRecord
{
	/* */
	public:
		CTrapRecord(void);

		~ CTrapRecord(void);

		void Reset(void);

		bool IsValidRec(string record);

		bool LoadRec(string record);

		string	strDate;
		string	strTime;
		string	strHost;
		string	strProtocal;
		string	strSrcIP;
		string	strDstIP;
		string	strSrcPort;
		string	strType;
		string	strSnmpVer;
		string	strCommunity;
		string	strVariables;
		bool bValidFlag;
};

class CTrapLogReader :
	public CThread
{
	/* */
	public:
		CTrapLogReader(void);

		CTrapLogReader(string strFilePath);

		CTrapLogReader(string strFilePath, long lReads);

		~ CTrapLogReader(void);

		bool OpenFile(void);

		void KeepReadFile(void);

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
		string	m_strFilePath;
		off_t m_lReadPos;
		bool m_bReadFlag;
		bool m_bFileModify;
		FILE *m_pFile;
		int m_iValidFlag;
		time_t	m_tModify;

		TemplateMutexCatch<CTrapRecord> m_listRecord;
};
