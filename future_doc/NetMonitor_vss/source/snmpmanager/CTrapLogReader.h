#include "systools.h"

/// Trap 消息数据结构
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
		string	m_strFilePath;
		off_t m_lReadPos;
		bool m_bReadFlag;
		bool m_bFileModify;
		FILE *m_pFile;
		int m_iValidFlag;
		time_t	m_tModify;

		TemplateMutexCatch<CTrapRecord> m_listRecord;
};
