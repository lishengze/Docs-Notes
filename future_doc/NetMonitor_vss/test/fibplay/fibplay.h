/////////////////////////////////////////////////////////////////////////
// 20110411 ����   NT-0129-����������л�ʱ��ˮ�쳣���������
/////////////////////////////////////////////////////////////////////////

#ifndef _FIBPLAY_H_
#define _FIBPLAY_H_

#include "public.h"
#include "FibPubApiManager.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "CDate.h"
#include "XtpPackageDesc.h"
#include "FlowReader.h"
#include "CSVParser.h"
#include "FileFlow.h"
#include "CConfig.h"
#include "monitorIndex.h"
#include "CFilelogService.h"
#include "CXML.h"

// �ļ��Ƿ���ڵ�У��λ
const int F_EXISTENCE_MODE = 0;

// flow �����ļ�Ĭ��·��
const char* FLOW_CONF_PATH = "./fibplay.xml";

// flow syslogĬ��·��
const char* FLOW_SYSLOG_PATH = "./log/Syslog";

// ʱ��ͬ���ṹ
struct TTimeSyncItem
{
	// �Ƿ�ʱ��ͬ������
	bool IsTimeSync;

	// ʱ�䴮��ʱ����
	CTimeType Time;

	// ����
	DWORD Millisec;
};

// fib�����ٶ�
struct TFibPlaySpeed
{
	// ��ʼʱ�䣬ʱ����
	CTimeType BeginTime;
	
	// ����ʱ�䣬ʱ����
	CTimeType EndTime;

	// �ٶȣ���λ����/��
	int Speed;

public:
	//���ÿ�ʼʱ��
	void setBeginTime(const char* p_szbegin)
	{
		BeginTime.setValue(p_szbegin );
	}
	
	//���ý���ʱ��
	void setEndTime(const char* p_szend)
	{
		EndTime.setValue(p_szend);
	}
	
	//�����ٶ�
	void setSpeed(const int nspeed)
	{
		Speed = nspeed;
	}	
};

// ����
struct TData
{
	TData()
	{
		Object = NULL;
		Length = 0;
	}

	~TData()
	{
		if (Object != NULL)
			delete[] Object;
	}

	// ����
	char* Object;
	
	// ����
	int Length;
};

// fib����
class CFibPlayConf
{
	public:
		CFibPlayConf();
		~CFibPlayConf();

	public:

		//���ý�����
		void setTradeDate(const string& strTradeDate);
		
		//���ö�ʱ��
		void setTimer(const int nTimer);
		
		//��������
		void setType(const string& strType);
		
		//����·��
		void setPath(const string& strPath);
		
		//��������
		void setFlowName(const string& strFlowName);
		
		//���������
		void setTopicID(const int nID);

		//���õ�ַ
		void setAddress(const string& strAddr);

		//�����ٶ�ֵ
		void setSpeed(TFibPlaySpeed* p_speed );
		
	public:
		// ������
		string m_MarketDay;

		// ��ʱ
		int m_Timer;

		// ����
		string m_Type;

		// ·��
		string m_Path;

		// ����
		string m_FlowName;

		// �����
		DWORD m_SubjectID;

		// ��ַ
		string m_Address;

		// �ٶ�
		vector<TFibPlaySpeed*>* m_Speeds;
};

// fib������
class CFibPlayFlow : public CReadOnlyFlow
{
	public:
		CFibPlayFlow(const char* name);
		~CFibPlayFlow();

	public:
		// ����ӿ�
		virtual int GetCount(void);
		virtual WORD GetCommPhaseNo();
		virtual int Get(int id, void *pObject, int length);

		// ����һ������
		void Append();

		// ����һ������
		bool ReadNext(CXTPPackage* package);

	private:
		// ���ļ�
		bool Open();

		// �ر��ļ�
		void Close();

		// �õ�id�ɶ��ļ�����
		QWORD GetIdCanReadLength();
		
		// �õ�con�ɶ��ļ�����
		QWORD GetConCanReadLength();
						
	private:
		// ����
		char m_Name[512];

		// id�ļ�
		FILE* m_IdFile;

		// con�ļ�
		FILE* m_ConFile;

		// �ļ�����
		QWORD m_IdFileLength;
		QWORD m_ConFileLength;
		QWORD m_OldConFileLength;
	
		// ��ǰ���ļ�λ��
		fpos_t m_ConPos;

		// ���ݸ���
		int m_Count;

		// ͨѶ���
		WORD m_CommPhaseNo;

		// ������
		deque<TData*>* m_Datas;
};

// fib������
class CFibPlayer : public CEventHandler
{
	public:
		CFibPlayer(CReactor* pReactor, const char* name);
		~CFibPlayer();

	public:
		// ��ʼ��
		bool Init(CFibPlayConf* config);
		
		// ��ʱ����
		virtual void OnTimer(int nIDEvent);

	private:
		// �����ݰ�
		void ReadData();

		// ��������
		void PublishData(int iCase);

		// ��ȫԭ�ٷ�������
		void PublishDataWithOrigSpeed();

		// ��ȫͬ����������
		void PublishDataWithSyncTime();

		// ���������ʷ�������
		void PublishDataWithConfig();

		// �õ��ٶ�
		int GetSpeed(CTimeType Time);

	private:
		// fib
		CFibPubApiManager* m_PubApiManager;

		// ��
		CFibPlayFlow* m_PlayFlow;
		CFlow* m_Flow;
		CFlowReader* m_Reader;
		CXTPPackage m_PkgRead;

		// ����
		CFibPlayConf* m_Config;

		// ��ǰ���ٶ�
		int m_CurSpeed;

		// ��ʼʱ��
		DWORD m_BeginTime;

		// ��ǰ�����ݸ���
		int m_CurDataNum;

		// ���ݶ���
		deque<TTimeSyncItem*>* m_TimeSyncs;

		// ���
		char m_FlowName[512];
		CIntTotalMonitorIndex* m_pFlowCount;
};

#endif
