/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	systools.h
///@brief	定义了交易监控系统共用的类和函数
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_SYSTOOLS_H
#define REF_SYSTOOLS_H

#include "public.h"
#include "utility.h"
#include "RefString.h"
#include "xmlcfg.h"
#include "SelectReactor.h"
#include "EventHandler.h"

#ifdef LINUX
#include <unistd.h>
#include <sys/syscall.h>
#endif
#ifdef ___DEBUG
#define PRINTF	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__)
#else
#define PRINTF
#endif
#ifdef WIN32
#define PATH_SEP	'\\'
#elif defined HP_UX || defined LINUX
#define PATH_SEP	'/'
#endif
inline void print_errmsg(
	const char	*pFile,
	const char	*pFunc,
	int iLine,
	const char *pMsg)
{
	char *p = (char *)strrchr(pFile, PATH_SEP);
	p = p == NULL ? (char *)pFile : p + 1;
	printf("%s:%s(%d) ERR[%s]\n", p, pFunc, iLine, pMsg);
	fflush(stdout);
}

#ifdef WIN32
#define INT64	LONGLONG
#define UINT64	ULONGLONG
#elif defined HP_UX
#define INT64	long long
#define UINT64	unsigned long long
#else
#define INT64	long
#define UINT64	unsigned long
#endif
#if !defined(PRINT_DEBUG)
#define PRINT_DEBUG
#endif
#if !defined(PACKAGE_OUTPUT)
#define PACKAGE_OUTPUT
#endif
#if !defined(REAL_HOSTNAME)
#define REAL_HOSTNAME
#endif
#undef REAL_HOSTNAME
#undef PRINT_DEBUG

//#undef PACKAGE_OUTPUT
#define SAFE_FCLOSE(x) \
	if (x != NULL)	   \
	{				   \
		fclose(x);	   \
		(x) = NULL;	   \
	}

#define ERR_SUCCESS				0				// 成功
#define ERR_REACHMAXRECORDNUM	3				// 查询返回记录超过最大数
#define ERR_EXCEPTREQ			10				// 查询包异常，无法处理直接返回异常

//2008.09.10 ad by wu.yb
#define DBMSG_SUC_SUCCESS			ERR_SUCCESS // 操作数据库成功，如果是查询表示有记录
#define DBMSG_SUC_NORECORD			2			// 查询数据库成功，但没有记录
#define DBMSG_ERR_EXCEPTION			1			// 查询数据库发生异常
#define DBMSG_ERR_REACHMAXRECORDNUM ERR_REACHMAXRECORDNUM					// 查询数据库，返回的记录太多，达到限制
#define DBMSG_SUC_RECORDEXISTS		4										// 表示记录存在

//2009.01.06 add by zhou.jj
#define EVENT_DBCONNECT_ERROR	"DBConnectLost"								//数据库没有连接
#define EVENT_DBEXESP_ERROR		"DBExeSPWrong"								//数据库调用SP出错
#define EVENT_DBGETLOG_ERROR	"DBGetLogWrong"								//数据库读取日志表时出错
#define EVENT_NOMD5FILE_ERROR	"NotExistMd5File"							//文件的校验码文件不能打开
#define EVENT_MD5CHECK_TIME		"MD5CheckTime"								//最近一次MD5校验事件
#define EVENT_MD5CHECK_ERROR	"MD5CheckWrong"								//文件校验结果检查不一致
#define EVENT_MD5CHECK_SUCCESS	"MD5CheckSuccess"							//文件校验结果检查一致
#define EVENT_WEBCHECK_ERROR	"WebCheckWrong"								//测试网页检查出错
#define EVENT_WEBCHECK			"WebCheck"									//最近一次测试网页校验事件

//2010.09.20 add by zhou.jj
#define EVENT_SNMP_GET_ERROR	"SnmpGetWrong"								//snmpget命令出错
	
	///20101102 Added by Henchi
#define EVENT_CHKVER_NOCHG		"CfgNoChange"
#define EVENT_CHKVER_CHANGE		"CfgChanged"
#define EVENT_BACKUP_SUCCEED	"BackupSucc"
#define EVENT_BACKUP_FAILED		"BackupFailed"

#define PORT_TELNET				23
#define PORT_SSH				22

//2008.11.29 网卡状态定义 by zhou.jj
#define LANSTATUSUP							"Up"							// 网卡正常工作状态
#define LANSTATUSDOWN						"Down"							// 网卡非工作状态
	
	///20080911郭鹏添加前置应答错误信息
#define ERR_DATEWRONG						101								//查历史但日期为当日
#define ERR_OIDWRONG						102								//OBJECTID错误
#define ERR_TIMEWRONG						103								//查询起始时间大于结束时间
#define ERR_QRYACCWRONG						104								//查询服务器连接失败
#define ERR_USERWRONG						105								//登录用户不存在
#define ERR_PSWWRONG						106								//登录密码错误
#define ERR_PROBEUNCONNECT					107								//与探针连接已经断开
#define ERR_COUNTERUNCONNECT				108								//与事件服务连接已经断开
#define MAXQRYRETURNNUM						10000							// 单个查询允许返回记录的最大数
#define MAXTIMELEN							10								// 时间的最大长度
#define MAXOBJECTNAMELEN					256								// 对象、文件路径名最大长度
#define MAXLOCATIONLEN						30								// 监听服务名的最大长度
#define MAXONEAREASIZE						50								// 文件一个读写域的最大长度
#define MAXONECONTENTLEN					800								// 传输文件内容的一个域最大长度
#define MAXCONTENTFIELDNUM					3								// 传输文件内容时候一个包的最大域个数
#define FLOWSEQUENCEDAEMON					1								// 后台订阅流编号
#define FLOWPRIVATE							2								// 与前台私有流编号
#define MAXONESTRINGSIZE					100								// 日志一个空格分开的域最大长度
	
	///此处宏定义用来定义SAN各类属性状态报告
#define SAN_cabinet							"san_cabinet"
#define SAN_storagecell						"san_storagecell"
#define SAN_controller						"san_controller"
#define SAN_disk							"san_disk"
#define SAN_virtualdisk						"san_virtualdisk"
#define SAN_virtualdiskfolder				"san_virtualdiskfolder"
#define SAN_virtualdiskfamilyfolder			"san_virtualdiskfamilyfolder"
#define SAN_host							"san_host"
#define SAN_presentedunit					"san_presentedunit"
#define SAN_diskshelf						"san_diskshelf"					//delete
#define SAN_hostfolder						"san_hostfolder"				//delete
#define SAN_diskgrouprootfolder				"san_diskgrouprootfolder"		//delete
#define SAN_diskgroupfolder					"san_diskgroupfolder"			//delete
#define SAN_drmgroupfolder					"san_drmgroupfolder"			//delete
#define SAN_hardwarerootfolder				"san_hardwarerootfolder"		//delete
#define SAN_powersupply						"san_powersupply"				// power supply
	
	///此处宏定义用来区分配置文件中的存储过程返回值类型字段(type)定义
#define SPRETURNCURSOR						"CURSOR"						// 带游标返回结果，该游标仅有两列，为属性名、属性值方式
#define SPRETURNNOCURSOR					"NOCURSOR"						// 仅返回一行结果，没有游标返回
#define SPRETURNMULTICOL					"MULTICOL"						// 带游标返回结果，该游标含有多个列
	
	///此处宏定义用来区分CFTDReqQryTradeDayChangeField交易日切换域中ChangeType字段的含义
#define TRUNCATEFLOW						"TruncateFlow"					// 清除指定编号的流内容
#define CHANGETRADEDAY						"ChangeTradeDay"				// 交易日切换
	
	///此处宏定义用来区分CFTDReqQryUpdateSysConfigField域中UpdateType字段的含义
#define UPDATESYSCONFIG_HOSTIDAPPID			"UP_IDRELATION"					// 主机ID与业务ID映射关系类型更新
#define UPDATESYSCONFIG_HOSTNAME			"UPXML_HOSTNAME"				// 更新xml中ip对应的探针主机名信息
#define APPATTRMEMBERSIZETUOGUAN			"MemberSize_TG"					// 托管会员数
#define APPATTRUSERSESSIONSIZETUOGUAN		"UserSessionSize_TG"			// 托管用户会话表大小
#define APPATTRMEMBERSIZETOTALTUOGUAN		"MemberSizeTotal_TG"			//托管总会员数
#define APPATTRUSERSESSIONSIZETOTALTUOGUAN	"UserSessionSizeTotal_TG"		//托管总席位数
#define APPATTRORDERSIZETUOGUAN				"OrderSize_TG"					// 托管报单数
#define APPATTRTRADESIZETUOGUAN				"TradeSize_TG"					// 托管成交数
#define APPATTRIPSCOPENAMETUOGUAN			"ipScopeName_TG"				// 托管ip范围对应的链接名称
#define APPATTRMAXMEMBERSIZE				"MaxMemberSizeTotal"			//最大会员数
#define APPATTRMAXSESSIONSIZE				"MaxUserSessionSizeTotal"		//最大座席数
#define APPATTRMAXMEMBERSIZETUOGUAN			"MaxMemberSizeTotal_TG"			//最大托管会员数
#define APPATTRMAXSESSIONSIZETUOGUAN		"MaxUserSessionSizeTotal_TG"	//最大托管座席数
#define APPATTRMEMORYDATABASE				"MemoryDatabase"				// 内存数据库使用的空间
#define APPATTRMEMORYDATABASEUSAGE			"MemoryDatabaseUsage"			// 内存数据库使用空间比例
#define APPATTRMDBBLOCK						"MDBBlock"						// 内存数据库分块数
#define APPATTRMDBBLOCKUSAGE				"MDBBlockUsage"					// 内存数据库分块数比例
#define APPATTRORDERSIZE					"OrderSize"						// 报单表大小
#define APPATTRTRADESIZE					"TradeSize"						// 成交表大小
#define APPATTRCLIENTSIZE					"ClientSize"					// 客户表大小
#define APPATTRPARTCLIENTSIZE				"PartClientSize"				// 会员客户表大小
#define APPATTRCLIENTPOSITIONSIZE			"ClientPositionSize"			// 客户持仓表大小
#define APPATTRUSERSESSIONSIZE				"UserSessionSize"				// 用户会话表大小
#define APPATTRTOTALVOLUME					"TotalVolume"					// 成交手数
#define APPATTRTOTALAMOUNT					"TotalAmount"					// 成交金额
#define APPATTRHANDLEINPUTTOTAL				"HandleInputTotal"				// 处理的请求总数量
#define APPATTRHANDLEINPUT					"HandleInput"					// 本次处理的请求数量
#define APPATTRHANDLEORDERINSERTTOTAL		"HandleOrderInsertTotal"		// 处理的报单插入总数量
#define APPATTRHANDLEORDERINSERT			"HandleOrderInsert"				// 本次处理的报单插入数量
#define APPATTRHANDLEORDERACTIONTOTAL		"HandleOrderActionTotal"		// 处理的报单操作总数量
#define APPATTRHANDLEORDERACTION			"HandleOrderAction"				// 本次处理的报单操作数量
#define APPATTRHANDLEORDERINSERTERRORTOTAL	"HandleOrderInsertErrorTotal"	// 错误的报单插入总数量
#define APPATTRHANDLEORDERINSERTERROR		"HandleOrderInsertError"		//  本次错误的报单插入数量
#define APPATTRHANDLEORDERACTIONERRORTOTAL	"HandleOrderActionErrorTotal"	// 错误的报单操作总数量
#define APPATTRHANDLEORDERACTIONERROR		"HandleOrderActionError"		// 本次错误的报单操作数量
#define APPATTRHANDLELOGINTOTAL				"HandleLoginTotal"				// 处理的登录总数量
#define APPATTRHANDLELOGIN					"HandleLogin"					// 本次处理的登录数量
#define APPATTRHANDLELOGINERRORTOTAL		"HandleLoginErrorTotal"			// 处理的登录失败总数量
#define APPATTRHANDLELOGINERROR				"HandleLoginError"				// 本次处理的登录失败数量
#define APPATTRHANDLEFTDREQUESTTOTAL		"HandleFTDRequestTotal"			// 处理的FTD请求总数量
#define APPATTRHANDLEFTDREQUEST				"HandleFTDRequest"				// 本次处理的FTD请求数量
#define APPATTRHANDLEFTDQUERYTOTAL			"HandleFTDQueryTotal"			// 处理的FTD查询总数量
#define APPATTRHANDLEFTDQUERY				"HandleFTDQuery"				// 本次处理的FTD查询数量
#define APPATTRHANDLEFTDERRORTOTAL			"HandleFTDErrorTotal"			// 处理的FTD错误总数量
#define APPATTRHANDLEFTDERROR				"HandleFTDError"				//  本次处理的FTD错误数量
#define APPATTRHANDLEOFPREQUESTTOTAL		"HandleOFPRequestTotal"			// 处理的OFP请求总数量
#define APPATTRHANDLEOFPREQUEST				"HandleOFPRequest"				// 本次处理的OFP请求数量
#define APPATTRHANDLEOFP2REQUESTTOTAL		"HandleOFP2RequestTotal"		//  处理的OFP2请求总数量
#define APPATTRHANDLEOFP2REQUEST			"HandleOFP2Request"				// 本次处理的OFP2请求数量
#define APPATTRCOMPLOGLEN					"complogLen"					// 排队机的流长度
#define APPATTRTSERIESLEN					"tseriesLen"					// 交易输入的流长度
#define APPATTRTRESULTLEN					"tresultLen"					// 交易结果的流长度
#define APPATTRTINITLEN						"tinitLen"						// 初始化的流长度
#define APPATTRDBMTLEN						"dbmtLen"						// DBMT的流长度
#define APPATTRDFMTLEN						"dfmtLen"						// DFMT的流长度
#define APPATTRFRONTLEN						"frontLen"						// 前置的流长度
#define APPATTROFPMARKETDATASENTTOTAL		"OFPMarketDataSentTotal"		// 老行情前置发送行情总数量
#define APPATTROFPMARKETDATASENT			"OFPMarketDataSent"				// 本次老行情前置发送行情数量
#define APPATTRTMDBCOUNTTOTAL				"TMDBCountTotal"				// TMDB的总数量
#define APPATTRTMDBCOUNT					"TMDBCount"						// 本次TMDB的数量
#define APPATTRCURRENTTIME					"CurrentTime"					// 当前业务时间
#define APPATTRISACTIVE						"IsActive"						// 是否活跃
#define APPATTRVERSION						"Version"						// 当前版本
#define APPATTRCOMPOSITORSTATE				"CompositorState"				// 排队机当前状态
#define APPATTRTIMESYNCTOTAL				"TimeSyncTotal"					// 发出的心跳报文个数
#define APPATTRCPUUSAGE						"CPUUsage"						// 业务进程CPU使用率
#define APPATTRMEMORYUSAGE					"MemoryUsage"					// 业务进程MEMORY使用率
#define APPATTRDISKUSAGE					"DiskUsage"						// 业务进程所在文件系统使用率
#define APPATTRINODEUSAGE					"INodeUsage"					// 业务进程所在文件系统INode使用率
#define APPATTRCENTERINFO					"Info"			// 数据中心指标汇总之后产生的信息提示属性，如产生数据中心

// 的CPUUsage之后，则产生CPUUsageInfo指标，值为是哪个对象产生的数据中心CPUUsage
#define APPATTRLANSESSIONSIZE		"LanSessionSize"		// 场内席位数
#define APPATTRWANSESSIONSIZE		"WanSessionSize"		// 远程席位数
#define APPATTRMEMBERSIZE			"MemberSize"			// 会员数
#define APPATTRACTIVE				"Active"				// 主机或业务进程活动状态报告
#define APPATTRIPSCOPENAME			"ipScopeName"			// ip范围对应的链接名称
#define APPATTRMEMBERSIZETOTAL		"MemberSizeTotal"		//总会员数
#define APPATTRUSERSESSIONSIZETOTAL "UserSessionSizeTotal"	//总席位数
#define APPATTRMDSESSIONSIZE		"MdSessionSize"			// mdkernel的连接个数
#define APPATTRTHREADS				"Threads"				// 主机进程所含线程数
#define EVENT_FLAG_GREEN			0						// 事件状态为开放
#define EVENT_FLAG_BLUE				1						// 事件状态为关闭
#define EVENT_FLAG_RED				2						// 事件状态为关联关闭
#define EVENT_FLAG_GRAY				3						// 事件状态为子节点含关闭
#define APP_ARB						"app.arb"
#define APP_COMPOSITOT				"app.compositor"
#define APP_FRONT					"app.front"
#define APP_MDKERNEL				"app.mdkernel"
#define APP_OFPMD					"app.ofpmd"
#define APP_QKERNEL					"app.qkernel"
#define APP_TKERNEL					"app.tkernel"
#define APP_TINIT					"app.tinit"
#define APP_TMDB					"app.tmdb"
#define APP_DBMT					"app.dbmt"
#define APP_FIBGATE					"app.fibgate"
#define APP_MD2KERNEL				"app.md2kernel"
#define APP_CONSOLE					"app.console"

#define APP_SUFFIX_SP				"_sp"
#define APP_SUFFIX_DBLOG			"_dblog"

#define XML_EVENT_NAME				"name"
#define XML_EVENT_TYPE				"type"
#define XML_EVENT_FULLNAME			"FullName"
#define XML_EVENT_LEVEL				"level"
#define XML_EVENT_GIVEUPTIME		"GiveupTime"
#define XML_EVENT_INTERVAL			"Interval"
#define XML_EVENT_CONTROL			"Control"
#define XML_EVENT_EXPR				"Expr"
#define XML_EVENT_OBJECTID			"ObjectId"
#define XML_EVENT_OBJECTATTR		"ObjectAttr"
#define XML_EVENT_COMMENT			"Comment"

#define HOSTCFG_REQTYPE_HOST		"Host"
#define HOSTCFG_REQTYPE_TOMCAT		"Tomcat"
#define HOSTCFG_REQTYPE_SP			"SP"
#define HOSTCFG_REQTYPE_SAN			"SAN"
#define HOSTCFG_REQTYPE_SANEVENT	"SANEvent"
#define HOSTCFG_REQTYPE_DBLOG		"DBLog"
#define HOSTCFG_REQTYPE_TIMER		"Timer"
#define HOSTCFG_REQTYPE_CFGFILE		"CfgFile"
#define HOSTCFG_REQTYPE_APPROOT		"AppRoot"
#define HOSTCFG_REQTYPE_APPSYSLOG	"AppSyslog"
#define HOSTCFG_REQTYPE_SYSTEMLOG	"SystemLog"
#define HOSTCFG_REQTYPE_KEYFILE		"KeyFile"
#define HOSTCFG_REQTYPE_DFMTLOG		"DfmtLog"
#define HOSTCFG_REQTYPE_WEBSITE		"Website"
#define HOSTCFG_REQTYPE_WEBSITECODE "WebsiteCode"
#define HOSTCFG_REQTYPE_ACCESSLOG	"AccessLog"
#define HOSTCFG_REQTYPE_SESSIONLOG	"SessionLog"
#define HOSTCFG_REQTYPE_DATABASE	"Database"
#define HOSTCFG_REQTYPE_DBATTR		"Attr"

#define TIME_MEASURE_START(name)	time_t name##TimeStart = time(NULL)
#define TIME_MEASURE_END(name)													  \
	time_t name##TimeEnd = time(NULL);											  \
	if (name##TimeEnd >= name##TimeStart + 2)									  \
	{																			  \
		printf(																	  \
			"Warning: File [%s] Line [%d]\n         Name [%s] Time [%d] secs.\n", \
			__FILE__,															  \
			__LINE__,															  \
			name,																  \
			name##TimeEnd - name##TimeStart);									  \
	}																			  \
																			   \
///校验并获取程序的启动标识
///@param	argc	程序argc
///@param	argv	程序argv
///@return	返回程序的启动标识,若启动标识不合法则程序直接退出
inline int getStartId(int argc, char **argv)
{
	if (argc < 2 || (atoi(argv[1])) <= 0)
	{
		printf("\nUsage:%s [启动标识]\n\n", argv[0]);
		fflush(stdout);
		exit(0);
	}

	return atoi(argv[1]);
}

///计算散列值函数,计算字符串的三列值
///@param	pStrbuff	计算字符串的地址
///@param	len	计算的长度
///@return	返回字符串计算出来的散列值
unsigned int cal_crc(char *pStrbuff, int len);

typedef struct __SHashObject
{
	char mMonitorAttr[64];
	unsigned int mHashValue;
} SHashObject;

//Added by Henchi, 20100609
class CObjectIdStatus
{
	/* */
	public:
		CObjectIdStatus(void)
		{
			m_sObjectId = "";
			m_sObjectName = "";
			m_iEventFlag = EVENT_FLAG_GREEN;
		}

		CObjectIdStatus(string ObjectId, string ObjectName)
		{
			m_sObjectId = ObjectId;
			m_sObjectName = ObjectName;
			m_iEventFlag = EVENT_FLAG_GREEN;
		}

		CObjectIdStatus(const char *pObjectId, const char *pObjectName)
		{
			m_sObjectId = pObjectId;
			m_sObjectName = pObjectName;
			m_iEventFlag = EVENT_FLAG_GREEN;
		}

		///对象ID,如:TRADE.PuDian.app.tkernel.1
		string	m_sObjectId;

		///对象名,如:tkernel.1
		string	m_sObjectName;

		///对象事件状态标识: 0表示开放事件;1表示关闭事件;2表示关联关闭事件
		int m_iEventFlag;
};

//////////////////////////////////////////////////////////////////////////
///CDataCenterManage定义了数据中心对象管理类
///@auther	周建军
///@version	1.0,20080510
//////////////////////////////////////////////////////////////////////////
class CDataCenterManage
{
	/* */
	public:
		///构造函数
		CDataCenterManage(void);

		///析构函数
		~ CDataCenterManage(void);

		///获取进程属性列表函数,调用本函数之前需要调用XMLInit函数
			///@param	appName	进程类型名称,如app.tkernel
			///@return	返回进程属性列表
		list<string> *getAttrFromApp(string &appName);

		///获取进程属性列表函数,调用本函数之前需要调用XMLInit函数
			///@param	appName	ID名称,如PuDian.app.tkernel.1
			///@return	返回进程属性列表
		list<string> *getAttrFromAppId(string &appName);

		// Added by Henchi
			///获取应用ID与应用类型映射图,调用本函数之前需要调用XMLInit函数
			///@return	返回应用ID与应用类型映射图
		map<string, string> &getAppIdTypeMap(void)
		{
			return m_mapAppIdType;
		};

		///获取应用ID与主机关系映射图,调用本函数之前需要调用XMLInit函数
			///@return	返回应用ID与主机关系映射图
		map<string, string> &getAppIdHostMap(void)
		{
			return m_mapAppIdHost;
		};

		///获取应用ID与应用名映射图,调用本函数之前需要调用XMLInit函数
			///@return	返回应用ID与应用名映射图
		map<string, CObjectIdStatus> &getAppIdNameMap(void)
		{
			return m_mapAppIdName;
		};

		///获取主机名与数据中心映射图,调用本函数之前需要调用XMLInit函数
			///@return	返回应用ID与应用名映射图
		map<string, string> &getHostDataCenterMap(void)
		{
			return m_mapHostDataCenter;
		};

		///获取对象ID与服务器IP对应关系map,调用本函数之前需要调用XMLInit函数
			///@return	返回对象ID与服务器IP对应关系map
		map<string, string> &getObjectIDAddressMap(void)
		{
			return m_mapObjectIDAddress;
		};
		
		map<int, string>& getFrontUniqueID()
		{
			return m_mapFrontAllocateID;
		}

		// Added End
		
			///判断属性是否是该进程的函数
			///@param	appName	进程名,如app.tkernel
			///@param	attrName	属性名,如MemoryDatabase
			///@return	返回判断结果,true表示该进程具备该指标,false表示不具备
		bool judgeAttrOfApp(string &appName, string &attrName);

		///取具备属性的所有监控对象ID的函数
			///@param	appList	放置所有监控对象ID的列表
			///@param	attrName	监控的指标属性
			///@return	返回值,true表示成功,false表示失败
		bool getAppIdFromAttr(list<string> &appList, string &attrName);

		///取监控指标的值类型
			///@param	pAttr	指标名称
			///@return	返回指标的值类型
		int getAttrType(char *pAttr);

		///取监控指标的监控周期
			///@param	pAttr	指标名称
			///@return	返回指标的值类型
		int getAttrInterval(const char *pAttr);

		///取监控指标的值类型,如果指标名称不存在就根据pValue来判断
			///@param	pAttr	指标名称
			///@param	pValue	指标的值
			///@return	返回指标的值类型
		int getAttrType(const char *pAttr, const char *pValue);

		///输出函数,打印map中所有进程和属性关系信息
		void print(void);

	/* */
	public:
		///增加进程属性关系函数
			///@param	appName	应用进程名,如app.tkernel(TotalAmount),PuDian.os.KF4660.keyfile(check.txt)
			///@param	attrName	应用进程的属性
		void addAppAttr(string &appName, string &attrName);

		///增加进程属性关系函数
			///@param	appName	应用进程名,app.tkernel(TotalAmount),PuDian.os.KF4660.keyfile(check.txt)
			///@param	attrName	应用进程的属性
		void addAppAttr(char *appName, char *attrName);

		///增加应用ID与类型映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	appType	所属的业务类型,如app.tkernel
		void addAppIdType(string &appId, string &appType);

		///增加应用ID与类型映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	appType	所属的业务类型,如app.tkernel
		void addAppIdType(char *appId, char *appType);

		// Added by Henchi
			///增加应用ID与主机映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	Host	应用进程所在主机，如PuDian.os.AC-01
		void addAppIdHost(string &appId, string &Host);

		///增加应用ID与主机映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	Host	应用进程所在主机，如PuDian.os.AC-01
		void addAppIdHost(char *appId, char *Host);

		///增加应用ID与应用名映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	appName	应用进程名
		void addAppIdName(string &appId, string &appName);

		///更新应用ID的当前状态，不更新子节点
		void updateCurAppIDStatus(string &appId, string &appName, int status);

		///增加应用ID与应用名映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	appName	应用进程名
		void addAppIdName(char *appId, char *appName);

		///增加对象ID与服务器IP对应关系函数
			///@param	objId	对象ID, 如TRADE.PuDian.app.tkernel.1
			///@param	addr	保存服务器IP地址，如 192.168.77.31
		void addObjectIDAddress(char *objId, char *addr);

		///增加对象ID与服务器IP对应关系函数
			///@param	objId	对象ID, 如TRADE.PuDian.app.tkernel.1
			///@return	返回服务器IP地址，如 192.168.77.31
		string	getAddressByObjectID(char *objId);

		///更新应用ID与应用名映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	oldAppId	需要删除的原AppId
		void UpDateAppIdName(char *appId, char *oldAppId);

		///更新应用ID与应用名映射关系函数
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@param	status	事件状态变更: 0为开放事件;1为关闭事件
		void UpDateObjectIdStatus(char *appId, int status);

		///查询对象ID当前是否已被标识关闭其告警事件
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@return	返回值,true表示成功,false表示失败
		bool IsObjectEventOff(char *appId);

		///获取对象所对应父节点对象的ID
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
			///@return	返回值,父对象ID串,不存在父对象时返回“”
		string	GetParentObjectId(char *appId);

		///通过遍历直接子节点的告警状态来更新本节点告警状态
			///@param	appId	应用级的ID,如PuDian.app.tkernel.1
		void ReFreshObjectIdStatus(char *appId);

		///由XML文件获取主机对象初始化函数
		void XMLInit(char *pszCfgPath);

		///更新主机关键文件和系统日志关系：
		void UpdateAppAttr(char *newHostName, char *oldHostName);
		void addFrontUniqueID(char* szObjectID);
	// Added End
	protected:
		///保存应用进程属性关系map
			///@param	key	保存应用进程类型,app.tkernel
			///@param	value	保存进程拥有的所有指标列表
		map<string, list<string> *> m_mapAppAttr;

		///保存应用ID与类型关系map
			///@param	key	保存应用的ID,如PuDian.app.tkernel.1
			///@param	value	保存应用类型,如app.tkernel
		map<string, string> m_mapAppIdType;

		///保存应用ID与主机关系map
			///@param	key	保存应用的ID,如PuDian.app.tkernel.1
			///@param	value	保存应用运行的主机名,如PuDian.os.AC-01
		map<string, string> m_mapAppIdHost;

		///保存应用ID对应的名字关系map
			///@param	key	保存应用的ID,如PuDian.app.tkernel.1,PuDian.os.AC-01
			///@param	value	保存应用ID状态结构
		map<string, CObjectIdStatus> m_mapAppIdName;

		///保存监控指标与类型的对应关系map
			///@param	key	保存监控的属性, 如TotalVolume,表示成交手数
			///@param	value	保存监控属性值的类型, 如INT_ATTR, 表示该指标为整数
		map<string, int> m_mapAttrType;

		///保存监控指标与其监控周期(秒)的对应关系map
			///@param	key	保存监控的属性, 如TotalVolume,表示成交手数
			///@param	value	保存监控指标数据产生的周期，单位为秒
		map<string, int> m_mapAttrInterval;

		///保存主机名与数据中心对应关系map;
			///@param	key	保存主机名, 如AC-01
			///@param	value	保存数据中心名字，如 PuDian
		map<string, string> m_mapHostDataCenter;

		///保存对象ID与服务器IP对应关系map;
			///@param	key	对象ID, 如TRADE.PuDian.app.tkernel.1
			///@param	value	保存服务器IP地址，如 192.168.77.31
		map<string, string> m_mapObjectIDAddress;
		
		map<int, string>	m_mapFrontAllocateID;
};

/////////////////////////////////////////////////////////////////////////
///CReadWriteFile定义了保存关键字和值的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
typedef struct
{
	string	m_key;			//关键字名
	string	m_pos;			//关键字对应的偏移量
	string	m_time;			//偏移量对应的时间
} SWriteFilePos;

#define MAX_SAVEKEYNUM	512
#define MAX_KEYSIZE		60
typedef struct
{
	char mkey[MAX_KEYSIZE]; //关键字
	unsigned long npos;		//偏移量
	int ntime;				//时间戳
} SPosition;

class CReadWriteFile
{
	/* */
	private:
		///保存的文件描述符
		FILE *m_mFd;

		///保存的读取位置的文件名
		char *m_pSaveFile;

		///保存到文件的关键字
		char *m_pKey;

		///关键字对应的值
		long m_mKeyPosition;

		///关键字和值操作缓冲区
		char *m_mSaveBuff;

		///关键字和值的长度
		int m_mLength;

		///关键字的个数
		int m_nKeyNum;

		///保存在内存中的首地址
		char *m_pBuffer;

		///关键字、位移
			///@key	关键字的值
			///@value	关键字对应到m_pBuffer的位移
		map<string, int> m_mKeyId;

	/* */
	public:

		///构造函数
			///@param	pSaveFile	存储的文件名
			///@param	keyLength	保存关键字和值的长度
		CReadWriteFile(char *pSaveFile, int keyLength)
		{
			m_mLength = keyLength;
			m_mSaveBuff = (char *)malloc(m_mLength + 1);
			m_pSaveFile = pSaveFile;
			if ((m_mFd = fopen(m_pSaveFile, "r")) == NULL)	// 只读方式打开文件，判断文件是否存在，如果不存在先创建文件
			{
				if ((m_mFd = fopen(m_pSaveFile, "a")) == NULL)
				{	// 创建文件失败，退出
					exit(0);
				}
				else
				{
					SAFE_FCLOSE(m_mFd);
				}
			}
			else
			{		// 文件存在，先关闭文件，然后重新打开文件
				SAFE_FCLOSE(m_mFd);
			}

			m_mFd = fopen(m_pSaveFile, "rb+");
			if (m_mFd == NULL)
			{
				exit(0);
			}

			m_mKeyPosition = 0;
			if (fseek(m_mFd, 0, SEEK_SET) != 0)
			{
				exit(0);
			}

			m_pBuffer = (char *)malloc(sizeof(SPosition) * MAX_SAVEKEYNUM);
			memset(m_pBuffer, 0, sizeof(SPosition) * MAX_SAVEKEYNUM);
			m_nKeyNum = fread(
					m_pBuffer,
					sizeof(SPosition),
					MAX_SAVEKEYNUM,
					m_mFd);

			SPosition *pSpos = (SPosition *)m_pBuffer;
			for (int i = 0; i < m_nKeyNum && i < MAX_SAVEKEYNUM; i++)
			{
				m_mKeyId[string(pSpos[i].mkey)] = i;
			}
		}

		///析构函数,退出时关闭文件描述符
		~CReadWriteFile(void)
		{
			if (m_mFd)
			{
				SAFE_FCLOSE(m_mFd);
			}

			if (m_mSaveBuff)
			{
				free(m_mSaveBuff);
				m_mSaveBuff = NULL;
			}

			if (m_pBuffer)
			{
				free(m_pBuffer);
				m_pBuffer = NULL;
			}
		}

		///取值函数,从文件中读取指定探针对应的所有值
			///@param	pKey	指定的关键字名
			///@param	mPosList	返回满足条件的所有值列表
			///@return	true成功，false失败
		bool ReadKeyValue(char *pKey, list<SWriteFilePos> &mPosList)
		{
			char *pValuePos;
			char str[30];
			SWriteFilePos sPos;
			SPosition *pSpos = (SPosition *)m_pBuffer;
			for (int i = 0; i < m_nKeyNum && i < MAX_SAVEKEYNUM; i++)
			{
				if ((pValuePos = strstr(pSpos[i].mkey, pKey)) != NULL
				&&	pSpos[i].mkey[strlen(pKey)] == ',')
				{
					sPos.m_key = pSpos[i].mkey + strlen(pKey) + 1;
					sprintf(str, "%lu", pSpos[i].npos);
					sPos.m_pos = str;
					sprintf(str, "%lu", pSpos[i].ntime);
					sPos.m_time = str;
					mPosList.push_back(sPos);
				}
			}

			return true;
#if 0
			size_t	mPos;
			SWriteFilePos sPos;
			memset(m_mSaveBuff, 0, m_mLength + 1);
			if (fseek(m_mFd, 0, SEEK_SET) < 0)
			{
				exit(1);
			}

			while ((mPos = fread(m_mSaveBuff, 1, m_mLength, m_mFd)) == m_mLength)
			{
				if ((pValuePos = strstr(m_mSaveBuff, pKey)) != NULL
				&&	m_mSaveBuff[strlen(pKey)] == ',')
				{
					pValuePos = pValuePos + strlen(pKey) + 1;

					char *p = strchr(pValuePos, '=');
					if (p == NULL)
					{
						continue;
					}

					*p = '\0';
					sPos.m_key = pValuePos;

					pValuePos = p + 1;
					p = strchr(pValuePos, ',');
					if (p == NULL)
					{
						continue;
					}

					*p = '\0';
					p++;
					sPos.m_pos = pValuePos;
					sPos.m_time = p;

					mPosList.push_back(sPos);
				}
			}

			return true;
#endif
		}

		///保存偏移量到文件函数
			///@return	true表示更新成功,false表示失败
		bool FlushToFile(void)
		{
			if (fseek(m_mFd, 0, SEEK_SET) < 0)
			{
				exit(1);
			}

			if (m_nKeyNum <= 0)
			{
				return true;
			}

			int iTest = fwrite(
					m_pBuffer,
					1,
					m_nKeyNum * sizeof(SPosition),
					m_mFd);
			if (iTest <= 0)
			{
				exit(1);
			}

			if (fflush(m_mFd) != 0)
			{
				exit(1);
			}

			return true;
		}

		///更新值函数,更新m_pKey关键字对应的值到文件中
			///@param	pKey	关键字字符串
			///@param	mNum	关键字对应的值
			///@param	mTime	关键字对应值的时间值
			///@return	true表示更新成功,false表示失败
		bool WriteKeyValue(char *pKey, long mNum, int mTime)
		{
			SPosition *pSpos = (SPosition *)m_pBuffer;
			map<string, int>::iterator	it = m_mKeyId.find(string(pKey));
			if (it == m_mKeyId.end())
			{
				m_mKeyId[string(pKey)] = m_nKeyNum;
				strcpy(pSpos[m_nKeyNum].mkey, pKey);
				pSpos[m_nKeyNum].npos = mNum;
				pSpos[m_nKeyNum].ntime = mTime;
				m_nKeyNum++;
				if (m_nKeyNum >= MAX_SAVEKEYNUM)
				{
					printf(
						"警告：超过最大文件保存位移数，将不保存该位移量！！！！\n");
					fflush(stdout);
					return false;
				}
			}
			else
			{
				if (it->second >= MAX_SAVEKEYNUM)
				{
					return false;
				}

				pSpos[it->second].npos = mNum;
				pSpos[it->second].ntime = mTime;
			}

			return true;
#if 0
			char *pValuePos;
			size_t	mPos;

			if (fseek(m_mFd, 0, SEEK_SET) < 0)
			{
				exit(1);
			}

			m_mKeyPosition = 0;
			while ((mPos = fread(m_mSaveBuff, 1, m_mLength, m_mFd)) == m_mLength)
			{
				if ((pValuePos = strstr(m_mSaveBuff, pKey)) != NULL
				&&	m_mSaveBuff[strlen(pKey)] == '=')
				{
					break;
				}

				m_mKeyPosition = m_mKeyPosition + mPos;
			}

			memset(m_mSaveBuff, 0, m_mLength + 1);
#ifdef WIN32
			_snprintf(m_mSaveBuff, m_mLength, "%s=%ld,%d", pKey, mNum, mTime);
#else
			snprintf(m_mSaveBuff, m_mLength, "%s=%ld,%d", pKey, mNum, mTime);
#endif
			if (fseek(m_mFd, m_mKeyPosition, SEEK_SET) < 0)
			{
				exit(1);
			}

			int iTest = fwrite(m_mSaveBuff, 1, m_mLength, m_mFd);

			//printf("+++++++++ iTest %d +++++++++ m_pKey %s nMum %ld \n",iTest,m_pKey, mNum);
			if (iTest <= 0)
			{
				exit(1);
			}

			if (fflush(m_mFd) != 0)
			{
				exit(1);
			}

			return true;
#endif
		}
};

/////////////////////////////////////////////////////////////////////////
///CReadWriteFile定义了字符串和ID映射关系的类
///@author	王肇东
///@version	1.0,20080510
///@history
///20080623	周建军		增加方法,修订注释
/////////////////////////////////////////////////////////////////////////
class CStringIdMap
{
	/* */
	private:
		///保存字符串和ID映射关系的map对象
		map<string, int> m_stringMap;

		///保存字符串引用的verctor数组
		vector<CRefStringPtr> m_stringList;

		///取字符串ID函数,查找字符串对应的ID
			///@param	s	需要查找的字符串地址
			///@return	返回该字符串对应的ID,如果字符串不存在就返回-1
		int findStringId(const char *s)
		{
			map<string, int>::iterator	it;
			it = m_stringMap.find(s);
			if (it == m_stringMap.end())
			{
				return -1;
			}
			else
			{
				return it->second;
			}
		}

		///添加字符串函数,将字符串添加到map和vector数组中
			///@param	s	需要添加的字符串引用
			///@return	返回该字符串对应的ID
		int addStringId(const CRefStringPtr &s)
		{
			int result = m_stringList.size();
			m_stringList.push_back(s);
			m_stringMap.insert(pair<string, int> (s->getValue(), result));
			return result;
		}

	/* */
	public:

		///取当前内存中已注册的对象ID个数值
			///@return 返回当前已注册的对象ID个数值
		int getMapSize(void)
		{
			return m_stringMap.size();
		}

		///取当前内存中已注册的对象ID个数值
			///@return 返回当前已注册的对象ID个数值
		int getListSize(void)
		{
			return m_stringList.size();
		}

		///取字符串ID函数,查找字符串对应的ID,如果该字符串不存在就增加
			///@param	s	需要查找的字符串地址
			///@return	返回该字符串对应的ID
		int getStringId(const char *s)
		{
			int result;
			if ((result = findStringId(s)) != -1)
			{
				return result;
			}

			return addStringId(s);
		}

		///取字符串ID函数,查找字符串对应的ID,如果该字符串不存在就增加
			///@param	s	需要查找的字符串引用
			///@return	返回该字符串对应的ID
		int getStringId(const CRefStringPtr &s)
		{
			int result;
			if ((result = findStringId(s)) != -1)
			{
				return result;
			}

			return addStringId(s);
		}

		///根据ID取字符串函数,查找指定ID的字符串
			///@param	id	需要查找的字符串ID
			///@return	返回该字符串的地址
		const char *getString(int id)
		{
			if (id < 0 || id >= (int)m_stringList.size())
			{
				return NULL;
			}

			vector<CRefStringPtr>::iterator it;
			it = m_stringList.begin() + id;
			return *it;
		}

		/**查找字符串ID及其字串ID函数,该函数根据字符串中的第一个冒号分割成两个字符串
	* ,查找该字符串及其两个字串的ID
	* @param	objectId	保存冒号前的字串ID
	* @param	itemId	保存冒号后的字串ID
	* @param	s	查找的字符串指针
	* @return	返回字符串对应的ID,如果该字符串中不含有冒号就返回-1
	*/
		int getStringSubId(int &objectId, int &itemId, const char *s)
		{
			if (s == NULL)
			{
				return -1;
			}

			int result;
			if ((result = findStringId(s)) == -1)
			{
				result = addStringId(s);
			}

			char temp[1024 + 1];
			memset(temp, 0, 1024);
			strncpy(temp, s, strlen(s) < 1024 ? strlen(s) : 1024);

			char *p = strchr(temp, ':');
			if (p == NULL)
			{
				return -1;
			}

			*p = '\0';
			p++;
			objectId = getStringId(temp);
			itemId = getStringId(p);
			return result;
		}

		/**查找字符串ID及其字串ID函数,该函数根据字符串中的第一个冒号分割成两个字符串
	* ,查找该字符串及其两个字串的ID
	* @param	objectId	保存冒号前的字串ID
	* @param	itemId	保存冒号后的字串ID
	* @param	s	查找的字符串引用
	* @return	返回字符串对应的ID,如果该字符串中不含有冒号就返回-1
	*/
		int getStringSubId(int &objectId, int &itemId, const CRefStringPtr &s)
		{
			int result;
			if ((result = findStringId(s)) == -1)
			{
				result = addStringId(s);
			}

			char temp[1024 + 1];
			memset(temp, 0, 1024);
			strncpy(temp, s, strlen(s) < 1024 ? strlen(s) : 1024);

			char *p = strchr(temp, ':');
			if (p == NULL)
			{
				return -1;
			}

			*p = '\0';
			p++;
			objectId = getStringId(temp);
			itemId = getStringId(p);
			return result;
		}

		/**查找字符串ID及其字串ID函数,该函数根据字符串中的最后一个.分割成两个字符串
	* ,查找该字符串及其两个字串的ID
	* @param	objectId	保存.前的字串ID
	* @param	itemId	保存.后的字串ID
	* @param	s	查找的字符串指针
	* @return	返回字符串对应的ID,如果该字符串中不含有.就返回-1
	*/
		int getStringSubIdRFromDot(int &objectId, int &itemId, const char *s)
		{
			int result = findStringId(s);
			if ((result = findStringId(s)) == -1)
			{
				result = addStringId(s);
			}

			char temp[1024 + 1];
			memset(temp, 0, 1024);
			strncpy(temp, s, strlen(s) < 1024 ? strlen(s) : 1024);

			char *p = strrchr(temp, '.');
			if (p == NULL)
			{
				return -1;
			}

			*p = '\0';
			p++;
			objectId = getStringId(temp);
			itemId = getStringId(p);
			return result;
		}

		///打印输出函数,打印当前map中保存的所有字符串映射关系
		void print(void)
		{
			map<string, int>::iterator	it;
			it = m_stringMap.begin();
			while (it != m_stringMap.end())
			{
				printf("%s %d\n", it->first.c_str(), it->second);
				it++;
			}
		}
};

///从整数时间取字符串时间函数
///@param	nTime	整数时间的秒
///@return	返回字符串时间，格式 HH24:MM:SS
inline char *getStrFromTime(int nTime)
{
	static char buffer[9];
	time_t	timep = nTime;
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(buffer, "%02d:%02d:%02d", tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
	return buffer;
}

///从整数时间取字符串日期函数
///@param	nTime	整数时间的秒
///@return	返回字符串时间，格式 YYYYMMDD
inline char *getStrFromDate(int nTime)
{
	static char buffer[9];
	time_t	timep = nTime;
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		buffer,
		"%04d%02d%02d",
		1900 + tm_time.tm_year,
		1 + tm_time.tm_mon,
		tm_time.tm_mday);
	return buffer;
}

///从整数时间取字符串日期函数
///@param	pOutDate	输出的日期，格式YYYYMMDD
///@param	nYear		输入的年，整数
///@param	nMonth		输入的月份，整数，1-12
///@param	pDay		输入的日期，整数
inline void getDateFromMonDay(char *pOutDate, int nYear, int nMonth, int nDay)
{
	if (nMonth < 1 || nMonth > 12)
	{
		printf("错误的月份 %d\n", nMonth);
		fflush(stdout);
	}

	if (nDay < 1 || nDay > 31)
	{
		printf("错误的日期 %d\n", nDay);
		fflush(stdout);
	}

	sprintf(pOutDate, "%04d%02d%02d", nYear / 10000, nMonth, nDay);
}

//带内部缓冲的日志
class CBufferLogger :
	public CLogger
{
	/* */
	public:
#define MAX_OUTPUTPACKAGESIZE	10000
		CBufferLogger(void)
		{
			reset();
		}

		~CBufferLogger(void)
		{
			m_pBufferEnd = m_pBufferCurr = NULL;
		}

		void reset(void)
		{
			m_pBufferCurr = m_buf;
			m_pBufferEnd = m_buf + MAX_OUTPUTPACKAGESIZE;
			memset(m_buf, 0, MAX_OUTPUTPACKAGESIZE + 1);
		}

		const char *getValue(int &nPackLen)
		{
			nPackLen = m_pBufferCurr - m_buf;
			return m_buf;
		}

		virtual void output(int level, char *format, ...)
		{
			int capacity = m_pBufferEnd - m_pBufferCurr;
			assert(capacity >= 0 && capacity <= MAX_OUTPUTPACKAGESIZE);
			if (!capacity)
			{
				return;
			}

			int len;

			va_list v;
			va_start(v, format);
			len = vsnprintf(m_pBufferCurr, capacity, format, v);
			va_end(v);

			/// Added by Henchi, 20121017
		/// 若len标记出现异常，则重置该值为最大量,避免断言异常
			if (len > capacity)
			{
				printf(
					"CBufferLogger::output(): length error, cap[%d] len[%d] pos[%d] Info[%s]\n",
					capacity,
					len,
					m_pBufferCurr - m_buf,
					m_pBufferCurr);
				len = capacity;
				m_buf[MAX_OUTPUTPACKAGESIZE] = 0x00;
			}

			m_pBufferCurr += len;
		}

	/* */
	private:
		char m_buf[MAX_OUTPUTPACKAGESIZE + 1];

		char *m_pBufferCurr;
		char *m_pBufferEnd;
};

class CFileLogger :
	public CLogger
{
	/* */
	public:
		CFileLogger(int level = LL_DEBUG)
		{
			m_fpLogFile = NULL;
			m_level = level;
			INIT_CRITICAL_VAR(m_varCritical);
		}

		~CFileLogger(void)
		{
			DELETE_CRITICAL_VAR(m_varCritical);
			if (m_fpLogFile != NULL)
			{
				SAFE_FCLOSE(m_fpLogFile);
			}
		}

		bool Open(const char *pszFileName)
		{
			ENTER_CRITICAL(m_varCritical);

			//该方法只允许调用一次，用断言来保证
			assert(m_fpLogFile == NULL);

			m_fpLogFile = fopen(pszFileName, "wb");

			LEAVE_CRITICAL(m_varCritical);

			return m_fpLogFile ? true : false;
		}

		/*
    void outputLevelHeader(int level)
    {
        if (level > m_level)
            return;

        ENTER_CRITICAL(m_varCritical); 

        switch (level)
        {
        case LL_EMERG:
            fprintf(m_fpLogFile, "EMERG:\n");
            break;
        case LL_ALERT:
            fprintf(m_fpLogFile, "ALERT:\n");
            break;
        case LL_CRIT:
            fprintf(m_fpLogFile, "CRIT:\n");
            break;
        case LL_ERR:
            fprintf(m_fpLogFile, "ERROR:\n");
            break;
        case LL_WARNING:
            fprintf(m_fpLogFile, "WARNING:\n");
            break;
        case LL_NOTICE:
            fprintf(m_fpLogFile, "NOTICE:\n");
            break;
        case LL_INFO:
            fprintf(m_fpLogFile, "INFO:\n");
            break;
        case LL_DEBUG:
            fprintf(m_fpLogFile, "DEBUG:\n");
            break;
        default:
            assert("Invalid level\n");
        }  

        LEAVE_CRITICAL(m_varCritical);
    }
*/
		virtual void output(int level, char *format, ...)
		{
			if (level > m_level)
			{
				return;
			}

			ENTER_CRITICAL(m_varCritical);

			va_list v;
			va_start(v, format);
			vfprintf(m_fpLogFile, format, v);
			va_end(v);

			fflush(m_fpLogFile);
			LEAVE_CRITICAL(m_varCritical);
		}

	/* */
	private:
		//void outputPrefix(int level)
		//{
		//    switch (level)
		//    {
		//    case LL_EMERG:
		//        fprintf(m_fpLogFile, "EMERG:\n");
		//        break;
		//    case LL_ALERT:
		//        fprintf(m_fpLogFile, "ALERT:\n");
		//        break;
		//    case LL_CRIT:
		//        fprintf(m_fpLogFile, "CRIT:\n");
		//        break;
		//    case LL_ERR:
		//        fprintf(m_fpLogFile, "ERROR:\n");
		//        break;
		//    case LL_WARNING:
		//        fprintf(m_fpLogFile, "WARNING:\n");
		//        break;
		//    case LL_NOTICE:
		//        fprintf(m_fpLogFile, "NOTICE:\n");
		//        break;
		//    case LL_INFO:
		//        fprintf(m_fpLogFile, "INFO:\n");
		//        break;
		//    case LL_DEBUG:
		//        fprintf(m_fpLogFile, "DEBUG:\n");
		//        break;
		//    default:
		//        assert("Invalid level\n");
		//    }
		//}
		FILE *m_fpLogFile;
		int m_level;	// 日志记录的级别
		CRITICAL_VAR m_varCritical;
};

#include "FTDCSession.h"

///对象ID及所属session管理类
class CObjectIdSession
{
	/* */
	public:
		CObjectIdSession(void)
		{
		}

		~CObjectIdSession(void)
		{
		}

		///增加对象ID所属FTD的session信息
			///@param	objectId	对象ID名
			///@param	pSession	该对象所对应的session
		void addObjectIdSession(const char *objectId, CFTDCSession *pSession)
		{
			//if (m_mapObjectIdSession[objectId] != NULL)
			//{
			//	printf("objectId : %s session %x has exist! \n", objectId, pSession);
			//	fflush(stdout);	
			//}
			m_mapObjectIdSession[objectId] = pSession;
		}

		///取对象ID所在的会话
			///@param	objectId	对象ID名
			///@return	返回对象所在session
		CFTDCSession *getObjectIdSession(const char *objectId)
		{
			return m_mapObjectIdSession[objectId];
		}

		///删除该session的所有对象ID
			///@param	pSession	需要删除的FTD的session
		void delSession(CFTDCSession *pSession)
		{
			map<string, CFTDCSession *>::iterator iter;
			for (iter = m_mapObjectIdSession.begin();
				 iter != m_mapObjectIdSession.end();)
			{
				if (iter->second == pSession)
				{
					m_mapObjectIdSession.erase(iter++);
				}
				else
				{
					++iter;
				}
			}
		}

	/* */
	protected:
	/* */
	private:
		map<string, CFTDCSession *> m_mapObjectIdSession;
};

typedef struct
{
	DWORD SessionID;
	DWORD RequestId;
	int ConnectId;
} TRID;
class CTRID
{
	/* */
	public:
		DWORD SessionID;	///接收到请求的会话ID
		DWORD RequestId;	///接收到请求的请求ID
		int ConnectId;		///FTD连接的ID，可以缺省不填充

	/* */
	public:
		CTRID(void)
		{
			SessionID = 0;
			RequestId = 0;
			ConnectId = 0;
		}

		CTRID(DWORD mSessionID, DWORD mRequestID, int mConnectID)
		{
			SessionID = mSessionID;
			RequestId = mRequestID;
			ConnectId = mConnectID;
		}

		CTRID(const CTRID &ob)
		{
			SessionID = ob.SessionID;
			RequestId = ob.RequestId;
			ConnectId = ob.ConnectId;
		}

		void operator=(const CTRID &ob)
		{
			SessionID = ob.SessionID;
			RequestId = ob.RequestId;
			ConnectId = ob.ConnectId;
		}
};
class CManageReqIDSession
{
	/* */
	private:
		vector<CTRID> m_vFid;	///当前所有的SessionID容器，包含有效的和失效的
		list<int> m_lPosition;	///vector容器中已经失效的位置列表

	/* */
	public:

		///向容器中放置请求的SessionID、RequestID
			///@param	mSessionID	接收到请求的会话ID
			///@param	mRequestID	接收到请求的请求ID
			///@param	mConnectID	FTD连接的ID，可以缺省不填充
			///@return	返回向上转发的新的RequestID
		int putRequestId(DWORD mSessionID, DWORD mRequestID, int mConnectID)
		{
			m_vFid.push_back(CTRID(mSessionID, mRequestID, mConnectID));
			return m_vFid.size();
		}

		/*
	int putRequestId(DWORD mSessionID, DWORD mRequestID, int mConnectID)
	{
	if (m_lPosition.size()==0)
	{
	m_vFid.push_back(CTRID(mSessionID,mRequestID,mConnectID));
	return (m_vFid.size()-1);
	}else{
	int pos = m_lPosition.front();
	m_lPosition.pop_front();
	m_vFid[pos]=CTRID(mSessionID,mRequestID,mConnectID);
	return pos;
	}
	}
	*/

		///根据应当的RequestID找回当初请求的SessionID、RequestID、ConnectID
			///@param	mCTRID	返回对应请求的值
			///@param	mRequestID	接收到请求的请求ID
			///@param	bChain	应答包的结束标记
			///@return	返回成功或失败
		bool getRequestId(CTRID &mTRID, DWORD mRequestID, BYTE bChain)
		{
			if (mRequestID > m_vFid.size())
			{
				return false;
			}

			mTRID = m_vFid[mRequestID - 1];
			return true;
		}

		/*
	bool getRequestId(CTRID & mTRID, DWORD mRequestID, BYTE bChain)
	{
	if (mRequestID >= m_vFid.size())
	{
	return false;
	}
	mTRID=m_vFid[mRequestID];
	if (FTDC_CHAIN_LAST == bChain)
	{
	m_lPosition.push_back(mRequestID);
	}
	return true;
	}
	*/
};

/////////////////////////////////////////////////////////////////////////
///CSeps定义了时间段及对应采样周期管理类
///@author	周建军
///@version	1.0,20090625
/////////////////////////////////////////////////////////////////////////
class CSeps
{
	/* */
	public:

		///构造函数
			///@param	pStr	字符串形式的时间间隔,08:00:00-12:00:00.120
		CSeps(const char *pStr)
		{
			char *p = (char *)pStr;
			m_nStart = atoi(p) * 3600 + atoi(p + 3) * 60 + atoi(p + 6);
			p = strchr(p, '-');
			if (p == NULL)
			{
				m_nStart = m_nEnd = m_nInterval = 0;
				printf("配置的时间间隔字符串不正确 : [%s]\n", pStr);
				fflush(stdout);
			}
			else
			{
				p++;
				m_nEnd = atoi(p) * 3600 + atoi(p + 3) * 60 + atoi(p + 6);
				if (*(p + 8) != '.' && *(p + 8) != '/')
				{
					printf("配置的时间间隔与频率格式不正确 ; [%s]\n", pStr);
					fflush(stdout);
				}

				m_nInterval = atoi(p + 9);
			}
		}

		CSeps(void)
		{
			m_nStart = 0;
			m_nEnd = 0;
			m_nInterval = 0;
		}

		CSeps(const CSeps &ob)
		{
			m_nStart = ob.m_nStart;
			m_nEnd = ob.m_nEnd;
			m_nInterval = ob.m_nInterval;
		}

	/* */
	public:
		int m_nStart;
		int m_nEnd;
		int m_nInterval;
};

/////////////////////////////////////////////////////////////////////////
///CJudgeRun定义了判断当前时间是否该满足指定时间段频率特性类
///@author	周建军
///@version	1.0,20101025
/////////////////////////////////////////////////////////////////////////
class CJudgeRun
{
	/* */
	public:
		CJudgeRun(void)
		{
			m_nLastRunSec = 0;
			m_nInterval = 0;
		}

		CJudgeRun(const char *pSeps)
		{
			m_nLastRunSec = 0;
			m_nInterval = 0;

			char *p = (char *)pSeps;
			while (p != NULL)
			{
				if (isValid(p))
				{
					m_vSep.push_back(CSeps(p));
				}

				p = strchr(p, ',');
				if (p != NULL)
				{
					p++;
				}
			}
		}

		///拷贝构造函数
		CJudgeRun(const CJudgeRun &ob)
		{
			m_nLastRunSec = ob.m_nLastRunSec;
			m_nInterval = ob.m_nInterval;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}
		}

		CJudgeRun &operator=(const CJudgeRun &ob)
		{
			m_nLastRunSec = ob.m_nLastRunSec;
			m_nInterval = ob.m_nInterval;
			m_vSep.clear();
			for (unsigned int i = 0; i < ob.m_vSep.size(); i++)
			{
				m_vSep.push_back(ob.m_vSep[i]);
			}

			return *this;
		}

		///判断字符串是否符合时间段频率定义格式
		bool isValid(char *p)
		{
			return
				(
					*(p + 2) == ':'
				&&	*(p + 5) == ':'
				&&	*(p + 8) == '-'
				&&	*(p + 11) == ':'
				&&	*(p + 14) == ':'
				&&	*(p + 17) == '.'
				);
		}

		///判断是否需要取该指标
			///@param	nNowSec	从系统中取得的秒数（已经补充了时差）
			///@return	true需要执行,false不需要执行
		bool needExcute(const int nNowSec)
		{
			if (nNowSec < m_nLastRunSec)
			{
				return false;
			}
			else
			{
				int nTemp = nNowSec % 86400;
				for (unsigned int i = 0; i < m_vSep.size(); i++)
				{
					if (nTemp < m_vSep[i].m_nStart)
					{
						m_nLastRunSec = nNowSec - nTemp + m_vSep[i].m_nStart;
						return false;
					}
					else if (nTemp >= m_vSep[i].m_nStart
						 &&	 nTemp < m_vSep[i].m_nEnd)	// 取该时间段的采样频率
					{
						m_nLastRunSec = nNowSec -
							(
								nNowSec %
								m_vSep[i].m_nInterval
							) +
									m_vSep[i].m_nInterval;
						m_nInterval = m_vSep[i].m_nInterval;
						return true;
					}
				}

				if (m_vSep.size() == 0)
				{
					m_nLastRunSec = nNowSec + 86400;
					return false;
				}
				else
				{
					m_nLastRunSec = nNowSec -
						nTemp +
						86400 +
						m_vSep[0].m_nStart;
					return false;
				}
			}
		}

		int GetInterval(void)
		{
			return m_nInterval;
		}

	/* */
	private:
		///操作时段数组
		vector<CSeps> m_vSep;

		///上次操作数据库时间,从当日零点开始的秒数
		int m_nLastRunSec;

		///若当前需执行,对应的时间间隔值
		int m_nInterval;
};

/////////////////////////////////////////////////////////////////////////
///TemplateMutexCatch定义了线程安全的列表管理类，
///该类封装了线程安全的列表，支持增加和获取及取列表大小
///@author	周建军
///@version	1.0,20101025
/////////////////////////////////////////////////////////////////////////
template<class T>
class TemplateMutexCatch
{
	/* */
	public:
		TemplateMutexCatch(void)
		{
		}

		~TemplateMutexCatch(void)
		{
		}

		void add(const T &x)
		{
			m_lock.Lock();
			m_listCache.push_front(x);
			m_lock.UnLock();
		}

		bool get(T &x)
		{
			m_lock.Lock();
			if (m_listCache.size() == 0)
			{
				m_listCache.resize(0);
				m_lock.UnLock();
				return false;
			}
			else
			{
				x = m_listCache.back();
				m_listCache.pop_back();
				m_lock.UnLock();
				return true;
			}
		}

		int size(void)
		{
			int listSize = 0;
			m_lock.Lock();
			listSize = m_listCache.size();
			m_lock.UnLock();
			return listSize;
		}

		void clear(void)
		{
			m_lock.Lock();
			m_listCache.clear();
			m_lock.UnLock();
		}

	/* */
	private:
		CMutex	m_lock;
		list<T> m_listCache;
};

/////////////////////////////////////////////////////////////////////////
///TemplateMutexMap定义了线程安全的map类，
///@author    周建军
///@version   1.0,20101025
/////////////////////////////////////////////////////////////////////////
template<class K, class V>
class TemplateMutexMap
{
	/* */
	public:
		TemplateMutexMap(void)
		{
		}

		~TemplateMutexMap(void)
		{
		}

		void add(const K &k, const V &v)
		{
			m_lock.Lock();
			m_mapCache[k] = v;
			m_lock.UnLock();
		}

		bool get(K &k, V &v)
		{
			m_lock.Lock();

			typename map<K, V>::iterator it = m_mapCache.find(k);
			if (it != m_mapCache.end())
			{
				v = m_mapCache[k];
				m_lock.UnLock();
				return true;
			}
			else
			{
				m_lock.UnLock();
				return false;
			}
		}

		//魏诚add, 20110815，删除map中的元素
		bool del(const K &k)
		{
			m_lock.Lock();

			typename map<K, V>::iterator it = m_mapCache.find(k);
			if (it != m_mapCache.end())
			{
				m_mapCache.erase(it);
				m_lock.UnLock();
				return true;
			}
			else
			{
				m_lock.UnLock();
				return false;
			}
		}

		//魏诚add,20110815，修改map中的元素
		bool modify(const K &k, const V &v)
		{
			m_lock.Lock();

			typename map<K, V>::iterator it = m_mapCache.find(k);
			if (it != m_mapCache.end())
			{
				it->second = v;
				m_lock.UnLock();
				return true;
			}
			else
			{
				m_lock.UnLock();
				return false;
			}
		}

		int size(void)
		{
			int listSize = 0;
			m_lock.Lock();
			listSize = m_mapCache.size();
			m_lock.UnLock();
			return listSize;
		}

	/* */
	private:
		CMutex	m_lock;
		map<K, V> m_mapCache;
};

///用于Syslog输出的计时器
class SysReactor :
	public CSelectReactor,
	public CEventHandler
{
	/* */
	public:
		SysReactor(void) :
		CEventHandler(this)
		{
			SetTimer(5, 1000);
		}

		virtual void OnTimer(int nIDEvent)
		{
			if (nIDEvent == 5)
			{
				CMonitorIndex::handleOne();
			}
		}
};
#endif //REF_SYSTOOLS_H
