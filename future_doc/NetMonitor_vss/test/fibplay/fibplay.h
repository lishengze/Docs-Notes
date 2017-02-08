/////////////////////////////////////////////////////////////////////////
// 20110411 江鹏   NT-0129-解决三中心切换时流水异常增大的问题
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

// 文件是否存在的校验位
const int F_EXISTENCE_MODE = 0;

// flow 配置文件默认路径
const char* FLOW_CONF_PATH = "./fibplay.xml";

// flow syslog默认路径
const char* FLOW_SYSLOG_PATH = "./log/Syslog";

// 时间同步结构
struct TTimeSyncItem
{
	// 是否时间同步工项
	bool IsTimeSync;

	// 时间串，时分秒
	CTimeType Time;

	// 毫秒
	DWORD Millisec;
};

// fib播放速度
struct TFibPlaySpeed
{
	// 开始时间，时分秒
	CTimeType BeginTime;
	
	// 结束时间，时分秒
	CTimeType EndTime;

	// 速度，单位：个/秒
	int Speed;

public:
	//设置开始时间
	void setBeginTime(const char* p_szbegin)
	{
		BeginTime.setValue(p_szbegin );
	}
	
	//设置结束时间
	void setEndTime(const char* p_szend)
	{
		EndTime.setValue(p_szend);
	}
	
	//设置速度
	void setSpeed(const int nspeed)
	{
		Speed = nspeed;
	}	
};

// 数据
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

	// 对象
	char* Object;
	
	// 长度
	int Length;
};

// fib配置
class CFibPlayConf
{
	public:
		CFibPlayConf();
		~CFibPlayConf();

	public:

		//设置交易日
		void setTradeDate(const string& strTradeDate);
		
		//设置定时器
		void setTimer(const int nTimer);
		
		//设置类型
		void setType(const string& strType);
		
		//设置路径
		void setPath(const string& strPath);
		
		//设置流名
		void setFlowName(const string& strFlowName);
		
		//设置主题号
		void setTopicID(const int nID);

		//设置地址
		void setAddress(const string& strAddr);

		//设置速度值
		void setSpeed(TFibPlaySpeed* p_speed );
		
	public:
		// 交易日
		string m_MarketDay;

		// 定时
		int m_Timer;

		// 类型
		string m_Type;

		// 路径
		string m_Path;

		// 流名
		string m_FlowName;

		// 主题号
		DWORD m_SubjectID;

		// 地址
		string m_Address;

		// 速度
		vector<TFibPlaySpeed*>* m_Speeds;
};

// fib播放流
class CFibPlayFlow : public CReadOnlyFlow
{
	public:
		CFibPlayFlow(const char* name);
		~CFibPlayFlow();

	public:
		// 基类接口
		virtual int GetCount(void);
		virtual WORD GetCommPhaseNo();
		virtual int Get(int id, void *pObject, int length);

		// 增加一个数据
		void Append();

		// 读下一个数据
		bool ReadNext(CXTPPackage* package);

	private:
		// 打开文件
		bool Open();

		// 关闭文件
		void Close();

		// 得到id可读文件长度
		QWORD GetIdCanReadLength();
		
		// 得到con可读文件长度
		QWORD GetConCanReadLength();
						
	private:
		// 流名
		char m_Name[512];

		// id文件
		FILE* m_IdFile;

		// con文件
		FILE* m_ConFile;

		// 文件长度
		QWORD m_IdFileLength;
		QWORD m_ConFileLength;
		QWORD m_OldConFileLength;
	
		// 当前的文件位置
		fpos_t m_ConPos;

		// 数据个数
		int m_Count;

		// 通讯编号
		WORD m_CommPhaseNo;

		// 流数据
		deque<TData*>* m_Datas;
};

// fib播放者
class CFibPlayer : public CEventHandler
{
	public:
		CFibPlayer(CReactor* pReactor, const char* name);
		~CFibPlayer();

	public:
		// 初始化
		bool Init(CFibPlayConf* config);
		
		// 定时处理
		virtual void OnTimer(int nIDEvent);

	private:
		// 读数据包
		void ReadData();

		// 发布数据
		void PublishData(int iCase);

		// 完全原速发布数据
		void PublishDataWithOrigSpeed();

		// 完全同步发布数据
		void PublishDataWithSyncTime();

		// 以配置速率发布数据
		void PublishDataWithConfig();

		// 得到速度
		int GetSpeed(CTimeType Time);

	private:
		// fib
		CFibPubApiManager* m_PubApiManager;

		// 流
		CFibPlayFlow* m_PlayFlow;
		CFlow* m_Flow;
		CFlowReader* m_Reader;
		CXTPPackage m_PkgRead;

		// 参数
		CFibPlayConf* m_Config;

		// 当前的速度
		int m_CurSpeed;

		// 开始时间
		DWORD m_BeginTime;

		// 当前的数据个数
		int m_CurDataNum;

		// 数据队列
		deque<TTimeSyncItem*>* m_TimeSyncs;

		// 监控
		char m_FlowName[512];
		CIntTotalMonitorIndex* m_pFlowCount;
};

#endif
