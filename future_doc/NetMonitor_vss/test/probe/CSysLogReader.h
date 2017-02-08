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
	string strAppName;  //app����
	string strAppNum;   //app���
	string strAttrName;  //ָ����
	string strAttrValue; //ָ��ֵ
	string strYear;
	bool bValidFlag;

	//Ӣ�ĵ����·ݺ����ֵ�ӳ��
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

	/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
	virtual bool InitInstance();

	/**�麯�����������ʵ��
	*/
	virtual void ExitInstance();

	/**�߳̿�ʼ���У����麯�����������̳�ʵ��
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

