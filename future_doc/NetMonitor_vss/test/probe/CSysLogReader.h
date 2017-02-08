#include "systools.h"
#include "FileRecordFinder.h"


#include "FtdPackageDesc.h"

class CSysLogRecord
{
public:
	CSysLogRecord();

	CSysLogRecord(char szYear);

	~CSysLogRecord();

	void Reset();

	bool IsValidRec(string record);

	bool LoadRec(string record);

	string GetDateString(char *pszMonth, char *pszDay);

	string strDate;
	string strTime;
	string strHost;
	string strAppName;  //app名称
	string strAppNum;   //app序号
	string strAttrName;  //指标名
	string strAttrValue; //指标值
	string strYear;
	bool bValidFlag;

	//英文单词月份和数字的映射
	map<string, string> m_mapMonthStr;	
};

class CSysLogReader:public CThread
{
public:
	CSysLogReader();

	CSysLogReader(string strFilePath);

	CSysLogReader(string strFilePath, long lReads);

	CSysLogReader(string strFilePath, long lReads, int iReadTime);

	~CSysLogReader();

	bool OpenFile();

	void KeepReadFile();

	/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
	virtual bool InitInstance();

	/**虚函数，子类清楚实例
	*/
	virtual void ExitInstance();

	/**线程开始运行，纯虚函数，子类必须继承实现
	*/
	virtual void Run();
private:
	void SaveAppAttrInfo(CSysLogRecord& Rec);
private:
	string m_strFilePath;
	time_t m_tModify;
	bool  m_bFileModify;
	FILE *m_pFile;
	off_t m_lReadPos;
	bool  m_bReadFlag;
	int   m_iValidFlag;
	int   m_iReadTime;

	time_t m_tLastLoadTime;
};

