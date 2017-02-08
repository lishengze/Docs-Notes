/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	EventCounterServer.h
///@brief	定义了事件计算服务器监听采集代理连接处理的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_EVENTCOUNTERSERVER_H
#define REF_EVENTCOUNTERSERVER_H

#include "CStatusAnalysis.h"
#include "CSavePosThread.h"
#include "CMdbThread.h"

#include "EventFrontServer.h"
#include "ProbeServer.h"
#include "SnmpSubcriber.h"
#include "EventConfigConnector.h"
#include "CRegexConfig.h"
#include "CFileDiff.h"

// add by cao.ning
#include "CSysInternalTopology.h"

#include <boost/regex.hpp>

#define MESSAGESENDTOPROBESESSION(listSession, pkgSend)	   \
	(pkgSend).ValidPackage();							   \
	for (list < CFTDCSession * >::iterator listSessionIt = \
			 (listSession).begin();						   \
	 listSessionIt != (listSession).end();				   \
		 listSessionIt++)								   \
	{													   \
		(*listSessionIt)->SendRequestPackage(&(pkgSend));  \
		(pkgSend).Pop(FTDCHLEN);						   \
	}

#define MESSAGESENDTOPROBEDIRECT(listSession, pkgSend)	   \
	for (list < CFTDCSession * >::iterator listSessionIt = \
			 (listSession).begin();						   \
	 listSessionIt != (listSession).end();				   \
		 listSessionIt++)								   \
	{													   \
		(*listSessionIt)->SendRequestPackage(&(pkgSend));  \
		(pkgSend).Pop(FTDCHLEN);						   \
	}
	
typedef map<string, string> T_strmap;

#ifdef WIN32
#define CHANGELINE_FLAG	"\r\n"			// 换行符
#define TMP_DIRNAME "C:\\tmp_event"
#define STRCMP	stricmp
#else
#define CHANGELINE_FLAG	"\n"			// 换行符
#define TMP_DIRNAME "../DevCfgFiles"
#define STRCMP strcasecmp
#endif


inline int TIME_TO_LONG(char *p)
{
	return atoi(p) * 3600 + atoi(p + 3) * 60 + atoi(p + 6);
}

typedef struct
{
	string	filename;
	string	filedate;
	string	filetime;
} ConfigFileInfo;

typedef struct
{
	string	name;
	string	comment;
	string	left;
	string	left_drift;
	string	right;
	string	right_drift;
	int left_time;
	int right_time;
} TradeSectionInfo;

//魏诚add, 20120203 管理未处理的告警事件类
class CWarningEventManager
{
	/* */
	public:
		//增加一个未处理的告警事件
		void add_warning_event(CFTDRtnWarningEventField &eventfield);

		//根据objid和eventname模糊查询，返回符合条件的事件列表
		//调用之后对应的事件已从容器中删除
		vector<CFTDRtnWarningEventField> fuzzy_get_warning_event(
											string	objectid,
											string	eventname,
											bool erasemark);

		//根据eventid精确查询，返回符合条件的事件列表
		//调用之后对应的事件已从容器中删除
		vector<CFTDRtnWarningEventField> exact_get_warning_event(
											string	objectid,
											string	eventname,
											int eventid,
											bool erasemark);

		//增加一条收到的原始事件
		void add_raw_warning_event(CFTDRtnWarningEventField &eventfield);
		void add_raw_syslog_event(CFTDRtnSyslogEventField &syslogfield);

		void onTimer(void); //清理过期的raw_syslog_event

		//判断是否重复产生
		bool is_duplicate_warning_event(CFTDRtnWarningEventField &eventfield);
		bool is_duplicate_syslog_event(CFTDRtnSyslogEventField &syslogfield);

	/* */
	private:
		map<string, map<int, CFTDRtnWarningEventField> > warning_event_list;	//key:objectid;;eventname, value:eventlist
		CMutex	m_lockData; //read/write lock
		map<string, int> raw_warning_event_list;			//key:objectid;;eventname;;date;;time, value:nothing
		map<string, vector<string> > raw_syslog_event_list; //key:objectid;;eventname;;date;;time, value:eventdes_list

		//用于超时淘汰,防止内存无限增长
		queue<string> raw_warning_event_queue;				//key:objectid;;eventname;;date;;time
		queue<string> raw_syslog_event_queue;				//key:objectid;;eventname;;date;;time
};

class CEventCounterServer;

/////////////////////////////////////////////////////////////////////////
///CEventTimmer定义了事件计算服务器定期器处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CEventTimmer :
	public CEventHandler
{
	/* */
	public:
		///构造函数
		CEventTimmer(
			CReactor *pReactor,
			CEventCounterServer *pEventCounterServer);

		/** 设置定时器函数
	* @param	nIDEvent	定时器产生的事件ID
	* @param	nElapse	定时器的时间间隔，单位ms	
	*/
		void SetTimer(int nIDEvent, int nElapse)
		{
			m_nEventId = nIDEvent;
			CEventHandler::SetTimer(nIDEvent, nElapse);
		}

		/** 定时器处理函数
	* @param	nIDEvent	该定时器的ID
	*/
		virtual void OnTimer(int nIDEvent);

	/* */
	private:
		///切换流时间间隔
		int m_nInterval;

		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///保存定时器的事件ID
		int m_nEventId;

		///保存上次切换时间
		time_t	m_nLastChangeTime;

		//int m_mTradeDay;
		CEventCounterServer *m_pEventCounterServer;
};

class CFlowManager
{
	/* */
	public:

		///构造函数
			///@param	nStartId	管理者启动编号
			///@param	pLocation	管理者的连接信息
			///@param	pEventCounterServer	对象指针
		CFlowManager(
		int nStartId,
		char *pLocation,
		CEventCounterServer *pEventCounterServer)
		{
			m_nStartId = nStartId;
			strcpy(m_location, pLocation);
			for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
			{
				m_pSubcriber[i] = new CSnmpSubscriber(
						i,
						nStartId,
						pEventCounterServer);
			}
		}

		bool check(int nStartId, char *pLocation)
		{
			if ((nStartId != m_nStartId)
			||	(strcmp(m_location, pLocation) != 0))
			{
				return false;
			}
			else
			{
				return true;
			}
		}

	/* */
	public:
		///流订阅指针数组
		CSnmpSubscriber *m_pSubcriber[MAX_EVENTFLOWNUM];

		///管理者启动编号
		int m_nStartId;

		///管理者的连接信息
		char m_location[64];

	/* */
	protected:
	/* */
	private:
};

// add by cao.ning
// 整点通告线程
// 修改为使用AttrConfig对整点信息进行配置，故弃用该对象
#if 0
class CPerHourMessage : public CThread
{
	
	public:
		CPerHourMessage(CEventCounterServer *pEventCounterServer);
		~ CPerHourMessage();

		virtual bool InitInstance(void);
	
		virtual void ExitInstance(void);

		virtual void Run(void);
	private:
		// 将时间和日期格式化为整点
		// input: pNowTime (当前时间)
		// output: NowTime_str, NowDate_str (格式化后的时间)
		void FormateTime(time_t &pNowTime, string &NowTime_str, string &NowDate_str);
	
	private:
		CEventCounterServer* m_pEventCounterServer;

		bool m_bSendMessage;
};
#endif


/////////////////////////////////////////////////////////////////////////
///CEventCounterServer定义了监听采集代理连接管理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CEventCounterServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
			///@param	pSaveFile	保存索引的文件名
			///@param	pEventCfgPath	事件定义文件路径
			///@param	pXmlFileName	xml配置文件
			///@param	pFlowPath	流文件保存路径
		CEventCounterServer(
			CReactor *pReactor,
			char *pSaveFile,
			char *pEventCfgPath,
			char *pXmlFileName,
			char *pFlowPath);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		/** 发送数据包函数
	* @param	pFTDPackage	发送数据包的地址
	*/
		void SendPackageAllSession(CFTDCPackage *pFTDCPackage)
		{
			CHashMap<DWORD, CSession *, HashInt>::iterator	itor = m_mapSession.
				Begin();
			while (!itor.IsEnd())
			{
				((CFTDCSession *) (*itor))->SendRequestPackage(pFTDCPackage);
				pFTDCPackage->Pop(FTDCHLEN);
				itor++;
			}
		}

	/* */
	protected:
		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///探针请求配置处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnReqQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///用户登录请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///用户登录应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///用户报单插入处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqOrderInsert(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///切换交易日请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///默认处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnDefaultProcess(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///对象属性处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRtnObjectAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///主机名变更处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
		void OnRtnUpdateSysConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///内存请求应答处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage);

		///CPU请求应答处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage);

		///Network请求应答处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage);

		///业务系统日志处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

		///应用日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRtnSyslogInfoApplog(CFTDCPackage *pFTDCPackage);

		///Slog日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRtnSyslogInfoSessionlog(CFTDCPackage *pFTDCPackage);

		///主机日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRtnSyslogInfoSyslog(CFTDCPackage *pFTDCPackage);

		///Web服务器访问日志信息处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRtnDBQueryAccessLog(CFTDCPackage *pFTDCPackage);

		///关键文件日志处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRtnSyslogInfoKeyfile(CFTDCPackage *pFTDCPackage);

		///订阅进程占用CPU资源信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnCPUUsageTopic(CFTDCPackage *pFTDCPackage);

		///订阅业务进程占用内存资源信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnMemoryUsageTopic(CFTDCPackage *pFTDCPackage);

		///订阅业务进程占用硬盘资源信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnDiskUsageTopic(CFTDCPackage *pFTDCPackage);

		///订阅对象属性处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage);

		///订阅任务运行结果处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pFTDCPackage);

		///订阅任务状态信息处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pFTDCPackage);

		///订阅探针发送出来的告警处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage);

		///订阅探针发送出来的告警处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnSyslogEventTopic(CFTDCPackage *pFTDCPackage);

		///订阅探针发送出来的动态列处理函数
			///@param	pMessage	订阅者收到的包地址
		void OnRtnDBQueryTopic(CFTDCPackage *pFTDCPackage);

		///任务配置文件内容
			///@param	pMessage	订阅者收到的包地址
		void OnRspQryNetMonitorTaskResultTopic(CFTDCPackage *pFTDCPackage);

		///基线任务信息
			///@param	pMessage	收到的包地址
		void OnRtnBaseLineTaskTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnNetLocalPingResultTaskTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnNetRemotePingResultTaskTopic(CFTDCPackage *pFTDCPackage);

		/// 交易日切换操作
		///@param TradingDay	新交易日的整型码
		void TradingDayChange(int TradingDay);

		///处理单个状态函数
			///@param	pBuffer	标准状态缓冲区地址
		void ProcessOneStatus(char *pBuffer);

		///落地配置文件
		int LogConfigInfo(
				string	objectid,
				string	buffer,
				int version,
				string	filedate,
				string	filetime);

		///加载落地的配置文件列表
		void LoadConfigFileList(void);

		///设置落地配置文件的路径
		void SetOutputPath(const char *path);

		///创建文件路径
		void CreatePath(const char *path);

		int ParseShowIPInterfaceResult(
				int taskid,
				vector<AttrNodeInfo> attrlist,
				string	objectid,
				string	deviceip);

		void ClearMemeryDatabase(void);

		//获取文件内容
		string	GetFileContent(string &path);

		//给定文件和基线文件进行比对,返回基线文件中比对不一致的部分
		string	BaseLineComare(string basecontent, string curcontent);

		//比较配置文件版本是否变化
		int  CheckFileVersion(
			string	objectid,
			string	buffer,
			string	filedate,
			string	filetime);

		///// 得到与配置文件同目录的最近一个配置文件的全路径名
		bool GetLastFileName(
			string objectid,
			string filepath,
			string filename,
			string& lastfilename);
		//根据关键字所在行中的位置，按列split字符串
		void Split_Data_Column(const string &in, string &out, const string &key);

		//构造cisco设备NUXUS7K型号的温度状态巡检结果
		void Combinate_Data_Env_NUXUS( string &in, string &out );

		//构造cisco设备NUXUS7K型号的电源状态巡检结果
		void Combinate_Data_Power_NUXUS( string &in, string &out );

	/* */
	public:
		///发送告警事件,协商模式发给config，非协商模式发给Client
		void SendWarningEvent(CFTDRtnWarningEventField warningevent);

		///子集匹配，判断给定的内容是否是result的子集
		static int	SubMatchInResult(
						vector<map<int, string> > &subresult,
						string	result);

		///解析思科设备3825型号的环境结果
		static int	ParseEnv_3825(string result, string &newresult);

		///解析思科设备3945型号的环境结果
		static int	ParseEnv_3945(string result, string &newresult);

		///解析思科设备5350型号的环境结果
		static int	ParseEnv_5350(string result, string &newresult);

		///解析思科设备7304型号的环境结果
		static int	ParseEnv_7304(string result, string &newresult);

		///解析Juniper设备SRX型号的并发会话巡检结果
		static int	ParseConSessions_SRX(string result);

		///解析Juniper设备SRX型号的RE利用率巡检结果
		static int	ParseFPC_SRX(string result, string &newresult);

		static int ParsePerfSession_SRX(CFTDRtnNetMonitorTaskResultField &resultField,string result,int manufactory_id,string deviceserial,int& threadhold);

		///解析Juniper设备SRX型号的RE利用率巡检结果
		static int	ParseREUsage_SRX(string result, string &newresult);

		///子集匹配，判断给定的内容是否是attrlist的子集
		static int	SubMatchInAttrList(
						vector<map<int, string> > &subresult,
						vector<string>	attrlist,
						vector<vector<AttrNodeInfo> > &valuelist);

		///分析指令返回结果
		int RegularParse(
				CFTDRtnNetMonitorTaskResultField &resultField,
				string	&oldresult,
				string	&newresult);

		static int	RegularParseResult(
						CFTDRtnNetMonitorTaskResultField &resultField,
						string	&oldresult,
						string	&newresult,
						int manufactory_id,
						string	deviceip,
						string	deviceserial);

		///分析指令返回结果
		int RegularParse(
				CFTDRspQryNetMonitorTaskResultField &resultField,
				string	&oldresult,
				string	&newresult);

		///用给定字符集替换字符串中的内容
		static void ReplayString(
						string	&ori,
						string	&srcContent,
						string	&dstContent,
						string	&result);

		///将表达式中的变量替换为对应的值
		static string ReplaceAttrByValue(
						vector<AttrNodeInfo> &attr_value,
						string	expr);

		///从字符串中提取时间值，eg:"1 year, 11 weeks, 3 days, 12 hours, 22 minutes",提取1,11,3,12,22
		static int	getTimeValueFromStr(
						string	&valuestring,
						const char	*typestring);

		//从RateLimiter巡检结果的原始文件中提取droped字段
		static int GetDropCounterFromStr(const string &olddata, string &newdata);

		static int GetNexusTemp_3548FromStr(const string &olddata, string &newdata);

		static int GetSrxFpcStatus_SRXFromStr(string olddata, string &newdata);

		static void remove_postfix_forSRX(string& result);

		//从SRX起动时间的巡检结果原始文件中提取system,protocols时间字段
		static int GetSRXUptimeFromStr(const string &olddata, string &newdata);

		///加载配置文件
		void loadXmlConfig(void);

		//修正告警事件级别
		string	modifyWarningEventLevel(string ip, string orilevel);

		/// 返回时间串所属的交易节信息，不在交易节内则为空
		string	getTradingSection(char *pTime);

		//更新事件发生次数
		void UpdateWarningCount(CFTDRtnWarningEventField &event);

		//获取事件发生次数
		int GetWarningCount(CFTDRtnWarningEventField &event);

		//更新会员链路状态
		void UpdateLinkStatusByWarningEvent(
				CFTDRtnWarningEventField &fieldInfo);
		void UpdateLinkStatusBySyslogEvent(CFTDRtnSyslogEventField &fieldInfo);

		//席位链路状态分析
		void SeatLinkAnalysis(CFTDRtnSyslogEventField &fieldInfo);

		char GenerateMaskValue(int nMaskValue);
		int SplitString(
				const string &strSrc,
				const string &strDelimiter,
				vector<string>	&strArrayRes);
		bool IsBelongIPRange(
				const string &strIPRange,
				const string &strIPAddrSample);

		///计算链路状态，处理中视为已恢复
		int GetPortStatus(LinkStatusInfo &statusinfo);

		///计算链路状态，处理中视为未恢复
		int GetPortRealStatus(LinkStatusInfo &statusinfo);

		//下发会员链路状态信息
		void SendLinkStatus(string objectid, string ipaddr);

		static bool ProcessRunTime(
						vector<map<int, string> > &regularparams,
						vector<vector<AttrNodeInfo> > &attr_value_list);
		static bool ProcessSoftewareStatus(string oldresult);

		static bool ProcessSrxFpcStatus(CFTDRtnNetMonitorTaskResultField &resultField,string result,int manufactory_id,string deviceserial);

		
		static bool ProcessLACPPDUSRPacketStatus(
			vector<vector<AttrNodeInfo> >& attr_value_list,
			map<int, string>& regularparams);

		static bool ProcessF5HAState(
			vector<map<int, string> > &regularparams,
			vector<vector<AttrNodeInfo> > &attr_value_list);

	static int expr_caculate(string real_regular, bool & grouppass);

	static int platform_state_parse(vector<vector<AttrNodeInfo> >& attr_value_list, int i, bool& grouppass, bool& regularpass);

	static void pre_process_attrlist(CFTDRtnNetMonitorTaskResultField &resultField
	, vector<vector<AttrNodeInfo> >& attr_value_list, string & oldresult, int manufactory_id);

	static void process_memory_task(int manufactory_id,vector<vector<AttrNodeInfo> >& attr_value_list,int i,string	&newresult);

	static int parse_other_result(CFTDRtnNetMonitorTaskResultField &resultField
	, int manufactory_id, string deviceip, string deviceserial, string	&oldresult, string	&newresult);

	//测试交易日相关的表达式
	bool test_trading(string inputstr);

	/* */
	private:
		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgPbeSend;

		///定时器对象
		CEventTimmer m_eventTimer;

		///保存索引的文件名
		char *m_pSaveFile;

		///保存的监控对象字符串
		char m_mObjectId[MAXONESTRINGSIZE];

		///保存的当前日期
		char m_mDate[MAXONESTRINGSIZE];

		///保存的当前时间
		char m_mTime[MAXONESTRINGSIZE];

		///保存的当前指标名
		char m_mObjectAttr[MAXONESTRINGSIZE];

		///保存的当前指标值
		char m_mValue[MAXONESTRINGSIZE];

		///保存读取索引的线程对象
		CSavePosThread	m_threadFiler;

		///需要做截断处理的属性map
			///@key	属性名，如CPUUsage，OrderSize
			///@value	为1表示需要把对象的指标值作为中心的指标值
		map<string, int> m_mapApp;

		///保存需要将动态列的状态信息转化成事件的列信息
			///key	动态列的属性名,如san_cabinet
			///value	map<string, string>对象，key保存KeyType，value保存Attend
		map<string, T_strmap> m_mapRtnDBQueryClomn;

		// key: objectId, attrId
		// value: 最新指标的时间戳
		map<CObjectAttrKey, CObjectAttrValue> m_mapLastItem;

		// 保存落地配置文件的目录
		string	m_sFilePath;

		//任务配置文件缓存器
		//key:objectid_date_time, value: filecontent
		map<string, string> m_mapConfigContent;

		//任务执行结果
		//key:ObjectID_Task_ID_OperateTime_MonDate_MonTime_InstructChain
		map<string, vector<CFTDRtnNetMonitorTaskResultField> >	m_mapTaskResult;

		//修正告警事件级别的ip列表
		map<string, int> m_chgWarnLevelIPList;

		//保存交易节列表信息
		vector<TradeSectionInfo> m_TradeSectionsVec;

		//保存交易节需要统计的对象指标信息
		map<CObjectAttrKey, int> m_StatObjectAttrMap;

		//对象按交易节保存最大值数据的map
		map<string, string> m_TradeSectionPeaks;

		//配置文件名
		string	m_sXMLFileName;

		/// 文本对比实体
		CFileDiff m_oFileDiff;

		// 整点通告线程
		// 已弃用，详见被注释的CPerHourMessage定义
		//CPerHourMessage m_PerHourMessagethread;

	/* */
	public:
		// key: objectId	对象ID，此处用来记录对象ID截至数据中心名对应的Active时间戳, 如TRADE.PuDian.app
		// value: 最新指标Active的时间戳
		map<string, int> m_center;

		///内存数据库操作线程对象
		CMdbThread	*m_pThreadMdber;

	/* */
	public:
		CProbeServer m_cProbeServer;
		CFrontConnector m_cFrontServer;
		CNodeCacheBuffer *m_pNodeBuffer;		// 保存属性的缓冲区
		CNodeCacheBuffer *m_pEventBuffer;		// 保存事件的缓冲区
		CConfigConnector m_cConfigConnector;	//配置服务器连接器
		unsigned int m_mSyslogEventId;			///当日事件发生的ID编号，递增不重复
		unsigned int m_mWarningEventId;

		// 保存作为探针需要关注的对象指标名
		map<CObjectAttrKey, int> m_mapProbeConfig;

		void RegisterAllConector(
		map<int, string> &mapCon,
		const char	*pConfigLocation)
		{
			for (map<int, string>::iterator itor = mapCon.begin();
				 itor != mapCon.end();
				 itor++)
			{
				RegisterConnecter((char *)itor->second.c_str());

				CFlowManager *pFlowM = new CFlowManager(
						itor->first,
						(char *)itor->second.c_str(),
						this);
				m_mapSnmpFlow[itor->second] = pFlowM;
			}

			//连接配置服务器
			m_cConfigConnector.RegisterConnecter(pConfigLocation);
		}

		void RegisterAllListener(
		const char	*pCounterLocation,
		const char	*pFrontLocation,
		const char	*pProbeLocation)
		{
			RegisterListener((char *)pCounterLocation);
			m_cFrontServer.RegisterListener((char *)pFrontLocation);
			m_cProbeServer.RegisterListener((char *)pProbeLocation);
		}

		void StartAll(void)
		{
			Start();
			m_cFrontServer.Start();
			m_cProbeServer.Start();
			m_cConfigConnector.Start();
		}

		void initBuffer(void)
		{
			m_mSyslogEventId = 1;
			m_mWarningEventId = 1;
			m_mOsInterval = 300;
#ifdef DEVELOP_ENV
			m_pNodeBuffer = new CNodeCacheBuffer(
					200000,
					sizeof(CFTDRtnObjectAttrField));
			m_pEventBuffer = new CNodeCacheBuffer(
					100000,
					sizeof(CFTDRtnSyslogEventField));
#else
			m_pNodeBuffer = new CNodeCacheBuffer(
					2000000,
					sizeof(CFTDRtnObjectAttrField));
			m_pEventBuffer = new CNodeCacheBuffer(
					1000000,
					sizeof(CFTDRtnSyslogEventField));
#endif

			/*
		time_t timep;
		struct tm *p;
		time(&timep);
		p = localtime(&timep);
		m_mTradeDay = (1900+p->tm_year)*10000+(1+p->tm_mon)*100+p->tm_mday;
		*/
		}

	/* */
	public:
		int m_mOsInterval;			// 操作系统类数据统计频率
		static int	m_mTradeDay;	// 当前的交易日

	/* */
	private:
		map<string, CFlowManager *> m_mapSnmpFlow;
};

class CWarnInfo
{
	/* */
	public:
		CFTDRtnWarningEventField m_warningField;
		CFTDRtnWarningQueryField m_warningInfo;
		CWarnInfo(void)
		{
		}

		CWarnInfo(
		const CFTDRtnWarningEventField	&warningField,
		const CFTDRtnWarningQueryField	&warningInfo)
		{
			m_warningInfo = warningInfo;
			m_warningField = warningField;
		}

		CWarnInfo(const CWarnInfo &ob)
		{
			m_warningInfo = ob.m_warningInfo;
			m_warningField = ob.m_warningField;
		}

		void operator=(const CWarnInfo &ob)
		{
			m_warningInfo = ob.m_warningInfo;
			m_warningField = ob.m_warningField;
		}
};
class CListWarningEventField
{
	/* */
	public:
		CListWarningEventField(void)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		~ CListWarningEventField(void);

		///将告警事件写入到数据队列函数
			///@param	warningEvent	告警事件对象
			///@return	true表示成功，false表示失败
		bool WriteValue(
		CFTDRtnWarningEventField &warningEvent,
		CFTDRtnWarningQueryField &warningInfo)
		{
			m_lockData.Lock();
			m_listEvent.push_back(CWarnInfo(warningEvent, warningInfo));
			m_lockData.UnLock();
			return true;
		}

		///从数据队列读出事件写入到前置的流和查询流
			///@param	eventcounter	事件服务全局指针
		void ReadValue(CEventCounterServer * &eventcounter);

	/* */
	protected:
	/* */
	private:
		// 告警事件保存队列
		list<CWarnInfo> m_listEvent;

		// 数据锁，用于保护 数据队列
		CMutex	m_lockData;

		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
};

/************************************************************************
* 行情登录统计、告警功能
************************************************************************/
// 使用string描述行情ID
typedef std::string MdLoginRecordID;

/////////////////////////////////////////////////////////////////////////
/// MdLoginRecord定义了行情登录统计信息
/// 该对象仅负责统计登陆信息，具体的告警计算由其他对象负责
/// @author	曹宁
/// @version	1.0,20150520
/////////////////////////////////////////////////////////////////////////
class MdLoginRecord
{
public:
	enum MdLoginState	// 行情登录的状态，两种
	{
		AllState,		// 实际中没有此状态，作为表示两种状态的合集
		Success,
		Failure
	};
public:
	// 从统计列表中获取一个记录，若无则添加对应的记录并返回对象
	static MdLoginRecord* fetchRecord(const MdLoginRecordID& _id);
	// 从统计列表中删除一个记录
	static void removeRecord(const MdLoginRecordID& _id);
	// 重置所有记录
	static void resetAllRecords();

public:
	// 获取ID
	const MdLoginRecordID& getRecordID() const { return m_RecordID; }

	// 登陆次数+1
	void record(time_t _time, MdLoginState _state, const char* _mdkernelID)
	{ m_LoginRecords.push_back(LoginInfo(_time, _state, _mdkernelID)); }

	// 计算从_endMoment时刻向前_timeLength秒内指定状态的登录次数
	// 默认值AllState表示所有状态
	int loginCount(time_t _endMoment = 0, int _timeLength = 0, MdLoginState _state = AllState) const;
	// 获取所有指定状态的登录明细
	// _endMoment记录的终止时刻，_timeLength向前计算的时间长度
	// _outputLen排序后输出前N个数据，以免输出字符串超长
	// _state指定状态
	string loginDetail(time_t _endMoment = 0, int _timeLength = 0, int _outputLen = 2, MdLoginState _state = AllState) const;

	// 获取登录状态计数明细，即成功登录次数、失败登录次数
	// Interval=%d, IntSucc=%d, IntFail=%d, IntAll=%d, TotalSucc=%d, TotalFail=%d, TotalAll=%d
	string loginCountDetail(time_t _endMoment = 0, int _timeLength = 0);
	
	// 重置记录
	void resetRecord() { m_LoginRecords.clear(); }

private:
	MdLoginRecord(const MdLoginRecordID& _RecordID)
		: m_RecordID(_RecordID) { }

	~MdLoginRecord() {}

	// 保存所有行情的统计信息
	static map<MdLoginRecordID, MdLoginRecord*> m_AllRecords;

	/* LoginRecordID */
	MdLoginRecordID m_RecordID;

	/* 记录该行情的登录信息，登录状态、发生时间和登录的Mdkernel ID */
	struct LoginInfo
	{
		LoginInfo(time_t _time, MdLoginState _state, const string& _mdkernelID)
			: LoginTime(_time), LoginState(_state), MdkernelID(_mdkernelID) { }
		time_t LoginTime;
		MdLoginState LoginState;
		string MdkernelID;
	};
	vector<LoginInfo> m_LoginRecords;
};

/////////////////////////////////////////////////////////////////////////
///MdLoginWarningCalculate定义了行情登录告警计算功能
///@author	曹宁
///@version	1.0,20150513
/////////////////////////////////////////////////////////////////////////
class MdLoginWarningCalculate
{
public:
	/* 从配置文件中读取计算对象 */
	static bool loadCalculateObjectFromXml(const char* _fileName);

	/* 字符串格式时间转化为time_t，发生错误时返回-1 */
	static inline time_t convertToTime(const CDateType& _date, const CTimeType& _time)
	{
		struct tm sTM;
		sscanf(_date.getValue(), "%4d%2d%2d",
			&sTM.tm_year, &sTM.tm_mon, &sTM.tm_mday);
		sscanf(_time.getValue(), "%2d:%2d:%2d",
			&sTM.tm_hour, &sTM.tm_min, &sTM.tm_sec);
		sTM.tm_year -= 1900;
		sTM.tm_mon--;
		sTM.tm_isdst = -1;
		return mktime(&sTM);
	}

private:
	MdLoginWarningCalculate(
		const char* _EventName,
		int _Interval,
		int _Threshold,
		int _WarningGap,
		MdLoginRecord::MdLoginState _TargetState)
		: m_EventName(_EventName), m_Interval(_Interval),
		m_Threshold(_Threshold), m_WarningGap(_WarningGap),
		m_TargetState(_TargetState)
	{
	}
	~MdLoginWarningCalculate() {}

public:
	/* 处理一个行情登录信息 */
	static void HandleMdLogin(
		const CDateType& _loginDate,				// 行情登录的日期
		const CTimeType& _loginTime,				// 行情登录的时间
		MdLoginRecord::MdLoginState _loginState,	// 行情登录的状态
		const char* _mdkernelID,					// 行情本次登录的mdkernel的ObjectID
		MdLoginRecordID _recordID);					// 行情ID

	/* 清理所有告警计算对象的中间状态 */
	static void reset()
	{
		for (vector<MdLoginWarningCalculate*>::iterator
			itObject = m_AllCalculate.begin();
			itObject != m_AllCalculate.end();
		++itObject)
		{
			(*itObject)->clearMdStateState();
		}
	}

private:
	// 清理当前告警对象下的所有席位中间状态
	void clearMdStateState() { m_AllRecordState.clear(); }

	// 处理一条记录，_BasisTime为该记录的基准时刻，_LocalTime为本地时间
	void HandleRecord(MdLoginRecord* _Record, time_t _BasisTime, time_t _LocalTime);

private:
	/* 告警名称 */
	string m_EventName;

	/* 统计周期 */
	int m_Interval;

	/* 告警阈值 */
	int m_Threshold;

	/* 该告警是否针对的Login状态 */
	MdLoginRecord::MdLoginState m_TargetState;

	/* 告警间隔 */
	int m_WarningGap;

	/* 针对该告警计算对象，保存每个记录的中间状态 */
	struct RecordState
	{
		RecordState() : LastWarningTime(0) {}
		time_t LastWarningTime;	// 该用户上一次发送该告警的时间
	};
	map<MdLoginRecordID, RecordState> m_AllRecordState;

	/* 获取特定记录的中间状态，返回引用 */
	RecordState& getRecordState(const MdLoginRecordID& _RecordID);

	/* 保存所有的计算对象 */
	static vector<MdLoginWarningCalculate*> m_AllCalculate;

	/* 存放用于发送数据的包 */
	static CFTDCPackage m_pkgSend;
	/* 存放用于数据域 */
	static CFTDRtnSyslogEventField m_SyslogEventField;
};

#endif // REF_EVENTCOUNTERSERVER_H
