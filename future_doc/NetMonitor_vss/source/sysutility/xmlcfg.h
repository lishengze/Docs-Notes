/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	xmlcfg.h
///@brief	定义了读取XML配置文件共用的类和函数
///@history
///20080630	晏鹤春	创建该文件
///20090219	晏鹤春	SystemConfig.xml文件结构改变，主机配置项按系统域划分，解析方法作相应调整
/////////////////////////////////////////////////////////////////////////
#ifndef REF_XMLCFG_H
#define REF_XMLCFG_H

#define UNKNOWN_ATTR		0						///未知类型的数据类型
#define STRING_ATTR			1						///字符串数据类型
#define INT_ATTR			2						///整数数据类型
#define FLOAT_ATTR			3						///浮点数类型
#define PERCENT_ATTR		4						///百分比数据类型
#define STRING_ATTR_DESC	"string"				///字符串数据类型描述
#define INT_ATTR_DESC		"int"					///整数数据类型描述
#define FLOAT_ATTR_DESC		"float"					///浮点数类型描述
#define PERCENT_ATTR_DESC	"percent"				///百分比数据类型描述

// add by zhou.jj 20090302 15:20
#define DOTDATACENTERAPPDOT		".app."				// 数据中心app应用业务类型
#define DOTDATACENTERHOSTDOT	".os."				// 数据中心主机类类型
#define DOTDATACENTERTOMCATDOT	".tomcat."			// 数据中心Tomcat类类型
#define DOTDATACENTERDBDOT		".db."				// 数据中心db类类型
#define DOTDATACENTERAPACHEDOT	".apache."			// 数据中心apache类类型

// add by zhou.jj 20090626
#define DBSEPARATORSTRING			"@#$"			// 数据库返回结果用该串来分割列
#define DBSEPARATORRECORD			"\r\n"			// 数据库返回结果用该串来分割行记录
#define DATACENTERSAN				"san"			// 数据中心san应用类业务类型
#define DATACENTERAPP				"app"			// 数据中心app应用业务类型
#define DATACENTERTOMCAT			"tomcat"		// 数据中心tomcat信息类型
#define DATACENTERAPACHE			"apache"		// 数据中心apache信息类型
#define DATACENTERHOST				"os"			// 数据中心主机类类型
#define DATACENTERDB				"db"			// 数据中心数据库类型
#define DATACENTERDBNODE			"dbnode"		// 数据中心数据库节点类型
#define HOSTATTRENV					"env"			// 主机环境变量
#define HOSTATTRCPU					"cpu"			// 主机CPU
#define HOSTATTRMEM					"mem"			// 主机MEM
#define HOSTATTRPROCESS				"process"		// 主机Process
#define HOSTATTRFS					"fs"			// 主机filesystem
#define HOSTATTRNET					"network"		// 主机network
#define HOSTATTRUSER				"user"			// 主机用户列表、在线用户
#define HOSTATTRSYSLOG				"syslog"		// 主机日志
#define HOSTATTRKEYFILE				"keyfile"		// 主机关键文件
#define HOSTATTRDFMTLOG				"dfmtlog"		// DFMT文件
#define TOMCATATTROVERVIEW			"overview"		// Tomcat总览
#define TOMCATATTRWEBAPP			"webapp"		// Tomcat应用部署
#define TOMCATATTRJDBC				"jdbc"			// Tomcat数据源
#define TOMCATATTRLOGFILE			"logfile"		// Tomcat系统日志
#define TOMCATATTRTHREAD			"thread"		// Tomcat线程
#define TOMCATATTRSYSTEM			"system"		// Tomcat系统
#define TOMCATATTRCONNECTOR			"connector"		// Tomcat连接器
#define DATACENTERPUDIAN			"PuDian"		// 浦电数据中心名
#define DATACENTERZHANGJ			"ZhangJ"		// 张江数据中心名
#define DATACENTERBEIJING			"BeiJing"		// 北京数据中心名
#define OBJOrderStatus				"OrderStatus"	//报单状态对象订阅名
#define OBJBargainOrder				"BargainOrder"	//成交单对象订阅名
#define OBJInvalidateOrder			"InvalidateOrder"			// 错误报单对象订阅名
#define OBJParticipant				"ParticipantInit"			//会员订阅名
#define OBJUser						"UserInit"					//座席订阅名
#define OBJClient					"ClientInit"				//客户订阅名
#define OBJParticTradeOrderStates	"ParticTradeOrderStates"	//报单统计
#define OBJInstrumentStatus			"InstrumentStatus"			//合约状态切换
#define OBJCurrTradingSegmentAttr	"CurrTradingSegmentAttr"	//交易节信息
#define TIME_FIB2EVENT				5000						//FIBCLIENT向事件计算服务器发送信息的时间步长
#define TIME_FIB2FRONT1				5					//FIBCLIENT向前置机发送信息的时间步长
#define TIME_FIB2FRONT2				60					//FIBCLIENT向前置机发送信息的时间步长
#define TIME_FIB2FRONT3				1					//FIBCLIENT向前置机发送信息的时间步长
#define HOSTATTRAPPLOG				"applog"			// 主机系统应用类日志
#define HOSTATTRSESSIONLOG			"sessionlog"		// 二进制的Slog
#define FRONTPROTOCOL				"FTD"				// FTD协议特征字
#define ATTRFTDCLIENTCOUNT			"ftdclientcount"	//FTD使用协议类型的客户连接总数
#define XML_DEFAULT_PATHNAME		"./"				// 默认配置文件路径
#define XML_FILE_SYSTEM				"SystemConfig.xml"	// 系统配置XML文件名
#define XML_FILE_DEPLOY				"DeployConfig.xml"	// 服务配置XML文件名

// 主要标签名
#define XML_TAG_SERVICES				"Services"
#define XML_TAG_CLIENTS					"Clients"
#define XML_TAG_SERVICES_AGENT			"sysagent"
#define XML_TAG_SERVICES_EVENTCOUNTER	"syseventcounter"
#define XML_TAG_SERVICES_FIBPROXY		"fibproxy"
#define XML_TAG_SERVICES_FIBCLIENT		"sysfibclient"
#define XML_TAG_SERVICES_SNMPMANAGER	"snmpmanager"
#define XML_TAG_SERVICES_FRONT			"sysfront"
#define XML_TAG_SERVICES_PROBE			"sysprobe"
#define XML_TAG_SERVICES_QUERY			"sysquery"
#define XML_TAG_SERVICES_SLOG			"sysslog"
#define XML_TAG_SERVICES_SYNCONFIG		"synconfig"
#define XML_TAG_SERVICE					"Service"
#define XML_TAG_PROBECFG				"HostConfig"
#define XML_TAG_COMMON					"Common"
#define XML_TAG_SYSTEM					"System"
#define XML_TAG_PROBE					"Host"
#define XML_TAG_BNSS					"BNSs"
#define XML_TAG_AGENTS					"Agents"
#define XML_TAG_AGENT					"Agent"
#define XML_TAG_TIMERS					"Timers"
#define XML_TAG_CONFIGFILES				"ConfigFiles"
#define XML_TAG_APPSYSLOGS				"AppSyslogs"
#define XML_TAG_SYSTEMLOG				"SystemLog"
#define XML_TAG_WEBSITES				"Websites"
#define XML_TAG_WEBSITECODE				"WebsiteCode"
#define XML_TAG_ACCESSLOG				"AccessLog"
#define XML_TAG_SANS					"SANs"
#define XML_TAG_SANEVENTSERVER			"SANEventServer"
#define XML_TAG_KEYFILE					"KeyFile"
#define XML_TAG_SESSIONLOG				"SessionLog"
#define XML_TAG_DFMTLOG					"RecSizeLog"
#define XML_TAG_TOMCATS					"Tomcats"
#define XML_TAG_DATABASES				"Databases"
#define XML_TAG_DBMAPPING				"DBMapping"
#define XML_TAG_DATABASE				"Database"
#define XML_TAG_ATTRS					"Attrs"
#define XML_TAG_ATTRDEFINE				"AttrDefine"
#define XML_TAG_DATACENTERS				"DataCenters"
#define XML_TAG_DATACENTER				"DataCenter"
#define XML_TAG_APPSPS					"AppSPs"
#define XML_TAG_DBSPS					"DBSPs"
#define XML_TAG_NODESPS					"NodeSPs"
#define XML_TAG_SP						"SP"
#define XML_TAG_DBLOGS					"DBlogs"
#define XML_TAG_MESSAGE					"Message"
#define XML_TAG_EVENTCFG				"EventConfig"
#define XML_TAG_ATTRCFG					"AttrConfig"
#define XML_TAG_USERS					"Users"
#define XML_TAG_SUBJECTS				"Subjects"
#define XML_TAG_OBJGROUPS				"ObjectGroups"
#define XML_TAG_LVLGROUPS				"LevelGroups"
#define XML_TAG_MSGGROUPS				"MsgGroups"
#define XML_TAG_FILTERS					"Filters"

// 主要属性名
#define XML_PROP_ID				"id"
#define XML_PROP_ITEM			"item"
#define XML_PROP_ADDR			"address"
#define XML_PROP_TYPE			"type"
#define XML_PROP_NAME			"name"
#define XML_PROP_CNAME			"cname"
#define XML_PROP_MOBILE			"mobile"
#define XML_PROP_ALIAS			"alias"
#define XML_PROP_ENV			"env"
#define XML_PROP_ROLE			"role"
#define XML_PROP_SEPS			"seps"
#define XML_PROP_PATH			"path"
#define XML_PROP_URL			"url"
#define XML_PROP_CODE			"code"
#define XML_PROP_ROOT			"root"
#define XML_PROP_HOSTNAME		"hostname"
#define XML_PROP_DATACENTER		"datacenter"
#define XML_PROP_SYSTEM			"system"
#define XML_PROP_TREEVIEW		"treeview"
#define XML_PROP_DBNAME			"dbname"
#define XML_PROP_RACNAME		"racname"
#define XML_PROP_SERVICENAME	"servicename"
#define XML_PROP_SYSNAME		"sysname"
#define XML_PROP_IP				"ip"
#define XML_PROP_PORT			"port"
#define XML_PROP_USER			"username"
#define XML_PROP_PSWD			"password"
#define XML_PROP_DATABASE		"database"
#define XML_PROP_VALUETYPE		"valueType"
#define XML_PROP_INTERVAL		"interval"
#define XML_PROP_SENDER			"sender"
#define XML_PROP_PREFIX			"prefix"
#define XML_PROP_LEVEL			"level"
#define XML_PROP_OBJECT			"object"
#define XML_PROP_ATTR			"attr"
#define XML_PROP_TIMEOUT		"timeout"
#define XML_PROP_SUBJECT		"subject"
#define XML_PROP_TIME			"time"
#define XML_PROP_TYPE			"type"
#define XML_PROP_SENDGAP		"send_gap"
#define XML_PROP_FORMAT			"format"
#define XML_PROP_MAXRETRY		"maxretry"
#define XML_PROP_RETRYSPAN		"retryspan"
#define XML_PROP_COMMENT		"comment"

// 主要关键域值
#define XML_VAL_SERVICE_PROBE			"sysprobe"
#define XML_VAL_SERVICE_AGENT			"sysagent"
#define XML_VAL_SERVICE_FRONT			"sysfront"
#define XML_VAL_SERVICE_QUERY			"sysquery"
#define XML_VAL_SERVICE_SLOG			"sysslog"
#define XML_VAL_SERVICE_MANAGER			"snmpmanager"
#define XML_VAL_SERVICE_FIBCLIENT		"sysfibclient"
#define XML_VAL_SERVICE_EVENTCOUNTER	"syseventcounter"
#define XML_VAL_SERVICE_CONFIG			"synconfig"
#define XML_VAL_SERVICE_CLIENT			"client"
#define XML_VAL_TIMER_HOSTENV			"HostEnv"
#define XML_VAL_TIMER_CPU				"CPU"
#define XML_VAL_TIMER_MEMORY			"Memory"
#define XML_VAL_TIMER_PROCESS			"Process"
#define XML_VAL_TIMER_DISK				"Disk"
#define XML_VAL_TIMER_USER				"User"
#define XML_VAL_TIMER_NETWORK			"Network"
#define XML_VAL_TIMER_NETSTAT			"NetStat"
#define XML_VAL_TIMER_APPSYSLOG			"AppSyslog"
#define XML_VAL_TIMER_SYSTEMLOG			"SystemLog"
#define XML_VAL_TIMER_DFMETLOG			"DfmtLog"
#define XML_VAL_TIMER_KEYFILE			"KeyFile"
#define XML_VAL_TIMER_SESSIONLOG		"SessionLog"
#define XML_VAL_TIMER_DATEBASE			"Database"
#define XML_VAL_CFGFILE_HOSTENV			"hostenv"
#define XML_VAL_CFGFILE_NETCFG			"netconf"

#define MAX_FILENAME_LEN				256				// 最大文件名长度(含路径)
#define MAX_SRVNAME_LEN					32				// 最大服务名长度
#define MAX_EVENTFLOWNUM				9				// 事件服务器发布的流最大编号(1,2,3.....9),要求减一能被24整除
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "CXML.h"

class CDBConnectString;

//////////////////////////////////////////////////////////////////////////
///CServerInfo	定义了服务器连接信息的数据类型
///@auther	晏鹤春
///@version	1.0,20100325
//////////////////////////////////////////////////////////////////////////
class CServerInfo
{
	/* */
	public:
		string	m_sName;
		string	m_sLocation;
		string	m_sType;
};

//////////////////////////////////////////////////////////////////////////
///CDBConnectString	定义了数据库连接信息的数据类型
///@auther	周建军
///@version	1.0,20080717
///20100330	晏鹤春	调整了该类型的数据结构
//////////////////////////////////////////////////////////////////////////
class CDBConnectString
{
	/* */
	public:
		string	m_sAlias;			// 监控配置内部使用的数据库别名，用于构建配置项间的映射关系
		string	m_sEnvironment;		// 标识BNS环境类型，如：Product
		string	m_sDBName;			// 向BNS发送请求的DB标签名
		string	m_sSystemName;		// 数据库对象的系统标识，如：DATABASE
		string	m_sCenterName;		// 数据库对象的中心标识，如：PuDian
		string	m_sRacServiceName;	// 数据库RAC级节点名，如：BDB
		string	m_sServiceName;		// 数据库RAC子实例节点名，如：BDB01
		string	m_sIpAddr;			// 数据库连接的IP地址
		int m_nPort;				// 数据库连接的端口
		string	m_sUserName;		// 数据库连接的用户名
		string	m_sPassword;		// 数据库连接的用户密码
		string	m_sTreeViewFlag;	// 数据库节点是否显示于TreeView中的标识
		bool m_bUpdateSP;			// SP类配置变更标记，为false表示需要发送，为true表示已经发送完成
		bool m_bUpdateRACDB;		// 数据库类RAC配置变更标记，为false表示需要发送，为true表示已经发送完成
		bool m_bUpdateNodeDB;		// 数据库类节点配置变更标记，为false表示需要发送，为true表示已经发送完成
		bool m_bUpdateAppSP;		// 数据库类APP配置变更标记，为false表示需要发送，为true表示已经发送完成
		bool m_bReConnectFlag;		// 数据库重连标记，为true表示本数据库别名对应的配置已经发生变更，

	//	意味再次使用时需要重连，连接成功时候设置为false
	public:
		CDBConnectString(void)
		{
			m_sAlias = "";
			m_sSystemName = "";
			m_sCenterName = "";
			m_sRacServiceName = "";
			m_sServiceName = "";
			m_sDBName = "";
			m_sEnvironment = "";
			m_sIpAddr = "";
			m_nPort = 1521;
			m_sUserName = "";
			m_sPassword = "";
			m_sTreeViewFlag = "";
			m_bUpdateRACDB = false;
			m_bUpdateNodeDB = false;
			m_bUpdateAppSP = false;
			m_bUpdateSP = false;
			m_bReConnectFlag = true;
		}

		CDBConnectString(const CDBConnectString &ob)
		{
			m_sAlias = ob.m_sAlias;
			m_sRacServiceName = ob.m_sRacServiceName;
			m_sSystemName = ob.m_sSystemName;
			m_sCenterName = ob.m_sCenterName;
			m_sServiceName = ob.m_sServiceName;
			m_sDBName = ob.m_sDBName;
			m_sEnvironment = ob.m_sEnvironment;
			m_sIpAddr = ob.m_sIpAddr;
			m_nPort = ob.m_nPort;
			m_sPassword = ob.m_sPassword;
			m_sUserName = ob.m_sUserName;
			m_sTreeViewFlag = ob.m_sTreeViewFlag;
			m_bUpdateRACDB = ob.m_bUpdateRACDB;
			m_bUpdateNodeDB = ob.m_bUpdateNodeDB;
			m_bUpdateAppSP = ob.m_bUpdateAppSP;
			m_bUpdateSP = ob.m_bUpdateSP;
			m_bReConnectFlag = ob.m_bReConnectFlag;
		}

		void operator=(const CDBConnectString &ob)
		{
			m_sAlias = ob.m_sAlias;
			m_sSystemName = ob.m_sSystemName;
			m_sCenterName = ob.m_sCenterName;
			m_sRacServiceName = ob.m_sRacServiceName;
			m_sServiceName = ob.m_sServiceName;
			m_sDBName = ob.m_sDBName;
			m_sEnvironment = ob.m_sEnvironment;
			m_sIpAddr = ob.m_sIpAddr;
			m_nPort = ob.m_nPort;
			m_sPassword = ob.m_sPassword;
			m_sUserName = ob.m_sUserName;
			m_sTreeViewFlag = ob.m_sTreeViewFlag;
			m_bUpdateRACDB = ob.m_bUpdateRACDB;
			m_bUpdateNodeDB = ob.m_bUpdateNodeDB;
			m_bUpdateAppSP = ob.m_bUpdateAppSP;
			m_bUpdateSP = ob.m_bUpdateSP;
			m_bReConnectFlag = ob.m_bReConnectFlag;
		}

		bool operator!=(const CDBConnectString &ob) const	// 注意：仅仅比较数据库的连接属性，不能比较更新标记和重连标记
		{
			return
				(
					m_sAlias != ob.m_sAlias
				||	m_sRacServiceName != ob.m_sRacServiceName
				||	m_sSystemName != ob.m_sSystemName
				||	m_sCenterName != ob.m_sCenterName
				||	m_sServiceName != ob.m_sServiceName
				||	m_sDBName != ob.m_sDBName
				||	m_sEnvironment != ob.m_sEnvironment
				||	m_sIpAddr != ob.m_sIpAddr
				||	m_nPort != ob.m_nPort
				||	m_sUserName != ob.m_sUserName
				||	m_sPassword != ob.m_sPassword
				) ? true : false;
		}
};

///////////////////////////////////////////////////////////////////////////
/////CRequestInfo定义了请求OraclePass服务器所需的信息。
///////////////////////////////////////////////////////////////////////////
class CRequestInfo
{
		friend class CDBConnectString;

	/* */
	public:
		CRequestInfo(void)
		{
			szEnv = "";
			szDBName = "";
			szDBUser = "";
		};
		CRequestInfo(const CRequestInfo &ob)
		{
			szEnv = ob.szEnv;
			szDBName = ob.szDBName;
			szDBUser = ob.szDBUser;
		};
		void operator=(const CRequestInfo &ob)
		{
			szEnv = ob.szEnv;
			szDBName = ob.szDBName;
			szDBUser = ob.szDBUser;
		};

	/* */
	public:
		///环境
		string	szEnv;

		///数据库别名
		string	szDBName;

		///数据库用户名
		string	szDBUser;
};

class CBNSInfo
{
	/* */
	public:
		CBNSInfo(void)
		{
			m_nPort = 0;
		};
		CBNSInfo(string sServerIP, string sPort)
		{
			m_sServerIP = sServerIP;
			m_nPort = atoi(sPort.c_str());
		};
		CBNSInfo(string sServerIP, int nPort)
		{
			m_sServerIP = sServerIP;
			m_nPort = nPort;
		};
		CBNSInfo(const CBNSInfo &ob)
		{
			m_sServerIP = ob.m_sServerIP;
			m_nPort = ob.m_nPort;
		};
		void operator=(const CBNSInfo &ob)
		{
			m_sServerIP = ob.m_sServerIP;
			m_nPort = ob.m_nPort;
		};

		///服务器地址
		string	m_sServerIP;

		///服务器端口
		int m_nPort;

	/* */
	protected:
	/* */
	private:
};

class CDBConnectInfo
{
	/* */
	public:
		CDBConnectInfo(void)
		{
			m_sInstanceName = "";
			m_sServerIP = "";
			m_nServerPort = 0;
			m_sUserName = "";
			m_sPassword = "";
			m_sRacName = "";
		}

		CDBConnectInfo(const CDBConnectInfo &ob)
		{
			m_sInstanceName = ob.m_sInstanceName;
			m_sServerIP = ob.m_sServerIP;
			m_nServerPort = ob.m_nServerPort;
			m_sUserName = ob.m_sUserName;
			m_sPassword = ob.m_sPassword;
			m_sRacName = ob.m_sRacName;
		}

		void operator=(const CDBConnectInfo &ob)
		{
			m_sInstanceName = ob.m_sInstanceName;
			m_sServerIP = ob.m_sServerIP;
			m_nServerPort = ob.m_nServerPort;
			m_sUserName = ob.m_sUserName;
			m_sPassword = ob.m_sPassword;
			m_sRacName = ob.m_sRacName;
		}

		bool operator==(const CDBConnectInfo &ob)
		{
			return m_sInstanceName == ob.m_sInstanceName
			&&	m_sServerIP == ob.m_sServerIP
			&&	m_nServerPort == ob.m_nServerPort
			&&	m_sUserName == ob.m_sUserName
			&&	m_sPassword == ob.m_sPassword;
		}

		bool IsValid(void)
		{
			return m_sInstanceName.length() > 0
			&&	m_sServerIP.length() > 0
			&&	m_nServerPort > 0
			&&	m_sUserName.length() > 0
			&&	m_sPassword.length() > 0;
		}

		string	m_sInstanceName;
		string	m_sServerIP;
		int m_nServerPort;
		string	m_sUserName;
		string	m_sPassword;
		string	m_sRacName;
};

class CRequstDBConnectInfo
{
	/* */
	public:
		CRequstDBConnectInfo(void)
		{
			//m_RequestInfo = CRequestInfo();
			//m_ConnectInfo = CDBConnectInfo();
		}

		CRequstDBConnectInfo(CDBConnectString &ob)
		{
			m_RequestInfo.szDBName = ob.m_sDBName;
			m_RequestInfo.szDBUser = ob.m_sUserName;
			m_RequestInfo.szEnv = ob.m_sEnvironment;
			m_ConnectInfo.m_sInstanceName = ob.m_sServiceName;
			m_ConnectInfo.m_sServerIP = ob.m_sIpAddr;
			m_ConnectInfo.m_nServerPort = ob.m_nPort;
			m_ConnectInfo.m_sUserName = ob.m_sUserName;
			m_ConnectInfo.m_sPassword = ob.m_sPassword;
			m_ConnectInfo.m_sRacName = ob.m_sRacServiceName;
		}

		CRequstDBConnectInfo(const CRequstDBConnectInfo &ob)
		{
			m_RequestInfo = ob.m_RequestInfo;
			m_ConnectInfo = ob.m_ConnectInfo;
		}

		void operator=(const CRequstDBConnectInfo &ob)
		{
			m_RequestInfo = ob.m_RequestInfo;
			m_ConnectInfo = ob.m_ConnectInfo;
		}

		CRequestInfo m_RequestInfo;
		CDBConnectInfo	m_ConnectInfo;
};

//////////////////////////////////////////////////////////////////////////
///CTableDBRelation	定义了数据表及数据库别名对应关系的数据类型
///@auther	晏鹤春
///@version	1.0,20080717
//////////////////////////////////////////////////////////////////////////
class CTableDBRelation
{
	/* */
	public:
		string	m_sTableName;
		string	m_sDbName;

	/* */
	public:
		CTableDBRelation(void)
		{
			m_sTableName = "";
			m_sDbName = "";
		}

		CTableDBRelation(const string &sTableName, const string &sDbName)
		{
			m_sTableName = sTableName;
			m_sDbName = sDbName;
		}

		CTableDBRelation(const CTableDBRelation &ob)
		{
			m_sTableName = ob.m_sTableName;
			m_sDbName = ob.m_sDbName;
		}

		void operator=(const CTableDBRelation &ob)
		{
			m_sTableName = ob.m_sTableName;
			m_sDbName = ob.m_sDbName;
		}

		bool operator==(const CTableDBRelation &ob) const
		{
			return
				(
					m_sDbName == ob.m_sDbName
				&&	m_sTableName == ob.m_sTableName
				);
		}
};
typedef list<CTableDBRelation>	listTDB;

//////////////////////////////////////////////////////////////////////////
///CXMLConfig定义了XML配置文件对象管理类
///@auther	晏鹤春
///@version	1.0,20080630
//////////////////////////////////////////////////////////////////////////
class CXMLConfig
{
	/* */
	public:
		class CProbeConfig
		{
		public:
			///构造函数
					///@param	pProbeNode	ProbeConfig节点对象指针
					///@param	pSystemNode	System节点对象指针
					///@param	pCommonNode	公共配置项节点对象指针
			CProbeConfig
				(
					CXMLNode *
					pHostNode, CXMLNode *
					pSystemNode, CXMLNode *
					pCommonNode
				);

			///析构函数
			~CProbeConfig (void);

			///获取当前探针信息的探针名
					///@return	返回探针名字串指针,无此信息时返回""
			char *GetProbeName(void)
			{
				return m_szProbeName;
			};

			///获取当前探针节点指针
					///@return	返回探针节点指针,无此信息时返回""
			CXMLNode *GetProbeNode(void)
			{
				return m_pProbeNode;
			};

			///获取当前探针信息的探针地址
					///@return	返回探针地址字串指针,无此信息时返回""
			char *GetLocation(void)
			{
				return m_szLocation;
			};

			///获取当前探针信息的服务器IP
					///@return	返回探针服务器IP字串指针,无此信息时返回""
			char *GetAddress(void)
			{
				return m_szAddress;
			};

			///获取当前探针所在主机的主机名
					///@return	返回主机名字串指针,无此信息时返回""
			char *GetHostName(void)
			{
				return m_szHostName;
			};

			///获取当前探针所在主机的主机别名
					///@return	返回主机名字串指针,无此信息时返回""
			char *GetHostAlias(void)
			{
				return m_szHostAlias;
			};

			///获取当前探针所在主机所属的数据中心名
					///@return	返回数据中心名字串指针,无此信息时返回""
			char *GetDataCenter(void)
			{
				return m_szDataCenter;
			};

			///获取当前探针所在主机所属的系统名
					///@return	返回系统名字串指针,无此信息时返回""
			char *GetSystem(void)
			{
				return m_szSystem;
			};

			///获取当前探针所在主机所属的系统中文名
					///@return	返回系统名字串指针,无此信息时返回""
			char *GetSystemAlias(void)
			{
				return m_szSystemAlias;
			};

			///获取当前主机的TreeView显示标识
					///@return	返回探针名字串指针,无此信息时返回""
			char *GetTreeViewFlag(void)
			{
				return m_szTreeViewFlag;
			};

			///获取当前探针信息结点的定时器配置map
					///@return	返回定时器配置map,无此信息时map的size为0
			map<string, string> &GetTimerMap(void)
			{
				return m_timerMap;
			};

			///获取当前探针信息结点的主机环境配置文件map
					///@return	返回主机环境配置文件map,无此信息时map的size为0
			map<string, string> &GetConfigMap(void)
			{
				return m_configMap;
			};

			///获取当前探针信息结点的业务进程日志文件map
					///@return	返回业务进程日志文件map,无此信息时map的size为0
			map<string, string> &GetAppLogMap(void)
			{
				return m_applogMap;
			};

			///获取当前探针信息结点的业务进程所在分区的map
					///@return	返回业务进程所在分区信息的map,无此信息时map的size为0
			map<string, string> &GetAppPathMap(void)
			{
				return m_apppathMap;
			};

			///获取当前探针信息结点的系统日志文件map
					///@return	返回系统日志文件map,无此信息时map的size为0
			map<string, string> &GetSysLogMap(void)
			{
				return m_syslogMap;
			};

			///获取当前探针信息结点的关键文件map
					///@return	返回关键文件map,无此信息时map的size为0
			map<string, string> &GetKeyFileMap(void)
			{
				return m_keyfileMap;
			};

			///获取当前探针信息结点的会话日志文件map
					///@return	返回会话日志文件map,无此信息时map的size为0
			map<string, string> &GetSessionMap(void)
			{
				return m_sessionMap;
			};

			///获取当前探针信息结点的DFMT文件map
					///@return	返回会话日志文件map,无此信息时map的size为0
			map<string, string> &GetDFMTMap(void)
			{
				return m_dfmtMap;
			};

			///获取当前探针信息结点的数据库名转义map
					///@return	返回数据库信息map,无此信息时map的size为0
			map<string, string> &GetDBMappingMap(void)
			{
				return m_dbmappingMap;
			};

			///设置目标节点数据库连接字串信息
					///@param	pszAlias	用于保存数据库别名的字符串指针
					///@param	pDBConnect	用于保存数据库连接信息的结构指针
					///@param	pProbeNode	指向目标节点的节点指针
					///@return	返回操作结果,成功为true,否则为false
			bool SetDBConnectString(
					const char	*pszAlias,
					CDBConnectString *pDBConnect,
					CXMLNode *pProbeNode);

			///获取当前探针信息结点的Tomcat连接信息map
					///@return	返回Tomcat连接信息map,无此信息时map的size为0
			map<string, CDBConnectString> &GetTomcatMap(void)
			{
				return m_tomcatMap;
			};

			///获取当前探针信息结点的存储过程配置信息map
					///@return	返回Tomcat连接信息map,无此信息时map的size为0
			map<string, CDBConnectString> &GetAppSPMap(void)
			{
				return m_AppSPMap;
			};

			///获取当前探针信息结点的数据库结点存储过程配置信息map
					///@return	返回Tomcat连接信息map,无此信息时map的size为0
			map<string, CDBConnectString> &GetNodeSPMap(void)
			{
				return m_NodeSPMap;
			};

			///获取当前探针信息结点的存储过程配置信息map
					///@return	返回Tomcat连接信息map,无此信息时map的size为0
			map<string, CDBConnectString> &GetDBSPMap(void)
			{
				return m_DBSPMap;
			};

			///获取当前探针信息结点的DBlog采样配置信息map
					///@return	返回Tomcat连接信息map,无此信息时map的size为0
			map<string, CDBConnectString> &GetDBLogMap(void)
			{
				return m_dblogMap;
			};

			///获取当前探针信息结点的网站监控路径配置信息map
					///@return	返回map,无此信息时map的size为0
			map<string, CDBConnectString> &GetFileCodeMap(void)
			{
				return m_filecodeMap;
			};

			///获取当前探针信息结点的网站状态码校验配置信息map
					///@return	返回map,无此信息时map的size为0
			map<string, CDBConnectString> &GetWebsiteCodeMap(void)
			{
				return m_websitecodeMap;
			};

			///获取当前探针信息结点的网站访问日志配置信息map
					///@return	返回map,无此信息时map的size为0
			map<string, CDBConnectString> &GetAccessLogMap(void)
			{
				return m_accesslogMap;
			};

			///获取当前探针信息结点的SAN监控路径配置信息map
					///@return	返回map,无此信息时map的size为0
			map<string, CDBConnectString> &GetSANMap(void)
			{
				return m_sanMap;
			};

			///获取当前探针信息结点的SAN事件日志配置信息map
					///@return	返回map,无此信息时map的size为0
			map<string, CDBConnectString> &GetSANEventMap(void)
			{
				return m_saneventMap;
			};

			///获取当前探针信息结点的数据库监控指标信息map
					///@return	返回数据库连接信息map,无此信息时map的size为0
			map<string, listTDB> &GetAttrMap(void)
			{
				return m_attrMap;
			};

			///获取当前探针信息结点的数据库监控指标及其采样定时器信息map
					///@return	返回数据库连接信息map,无此信息时map的size为0
			map<string, string> &GetAttrTimerMap(void)
			{
				return m_attrtimerMap;
			};
		private:
			///获取目标节点指定属性项的字符串值
					///@param	pszValue	用于保存值域的字符串指针
					///@param	pszProp	用于保存属性名的字符串指针
					///@param	iMaxLen	值域所允许的最大合法字符串长度
					///@param	pNode	目标节点对象指针
			void getPropValue(
					char *pszValue,
					char *pszProp,
					const int iMaxLen,
					CXMLNode *pNode);

			///获取目标节点下各配置信息项，并将配置信息存入各相应成员映射图中
					///@param	pHostNode	目标节点对象指针
			void loadMaps(CXMLNode *pHostNode);
		private:
			///探针名
			char m_szProbeName[MAX_SRVNAME_LEN];

			///探针地址
			char m_szLocation[MAX_SRVNAME_LEN];

			///探针IP地址
			char m_szAddress[MAX_SRVNAME_LEN];

			///探针所在主机名
			char m_szHostName[MAX_SRVNAME_LEN];

			///探针所在主机别名
			char m_szHostAlias[MAX_SRVNAME_LEN];

			///探针所在主机所属的数据中心名
			char m_szDataCenter[MAX_SRVNAME_LEN];

			///探针所在主机所属的系统名
			char m_szSystem[MAX_SRVNAME_LEN];

			///探针所在主机所属的系统中文名
			char m_szSystemAlias[MAX_SRVNAME_LEN];

			///该主机是否显示于TreeView中的标识
			char m_szTreeViewFlag[MAX_SRVNAME_LEN];

			///探针节点对象指针
			CXMLNode *m_pProbeNode;

			///保存探针定时器信息的map
					///@param	key	保存定时器对应应用进程名
					///@param	value	保存定时器间隔时长(单位:秒)
			map<string, string> m_timerMap;

			///保存主机环境配置文件信息的map
					///@param	key	保存主机环境项
					///@param	value	保存主机环境配置文件名(含路径)
			map<string, string> m_configMap;

			///保存业务进程日志文件信息的map
					///@param	key	保存业务进程名
					///@param	value	保存业务进程日志文件名(含路径)
			map<string, string> m_applogMap;

			///保存业务进程所在分区的map
					///@param	key	保存业务进程名
					///@param	value	保存业务进程的分区名,如"/home"
			map<string, string> m_apppathMap;

			///保存系统日志文件信息的map
					///@param	key	保存系统日志文件项
					///@param	value	保存系统日志文件名(含路径)
			map<string, string> m_syslogMap;

			///保存系统关键文件信息的map
					///@param	key	保存关键文件项
					///@param	value	保存关键文件名(含路径)
			map<string, string> m_keyfileMap;

			///保存DFMT文件信息的map
					///@param	key	保存会话日志文件项
					///@param	value	保存DFMT文件名(含路径)
			map<string, string> m_dfmtMap;

			///保存会话日志文件信息的map
					///@param	key	保存会话日志文件项
					///@param	value	保存会话日志文件名(含路径)
			map<string, string> m_sessionMap;

			///保存数据库连接信息的map
					///@param	key	数据库对象名
					///@param	value	数据库对象名
			map<string, string> m_databaseMap;

			///保存数据库别名映射的map
					///@param	key	数据库别名
					///@param	value	数据库连接名
			map<string, string> m_dbmappingMap;

			///保存Tomcat连接信息的map
					///@param	key	Tomcate对象名
					///@param	value	数据库连接信息
			map<string, CDBConnectString> m_tomcatMap;

			///保存应用型存储过程配置信息的map
					///@param	key	存储过程对象名
					///@param	value	存储过程配置信息
			map<string, CDBConnectString> m_AppSPMap;

			///保存数据库节点型存储过程配置信息的map
					///@param	key	存储过程对象名
					///@param	value	存储过程配置信息
			map<string, CDBConnectString> m_NodeSPMap;

			///保存数据库型存储过程配置信息的map
					///@param	key	存储过程对象名
					///@param	value	存储过程配置信息
			map<string, CDBConnectString> m_DBSPMap;

			///保存DBlog配置信息的map
					///@param	key	DBlog配置对象名
					///@param	value	DBlog配置信息
			map<string, CDBConnectString> m_dblogMap;

			///保存网站文件校验路径配置信息的map
					///@param	key	文件路径
					///@param	value	配置信息项
			map<string, CDBConnectString> m_filecodeMap;

			///保存网站状态码校验配置信息的map
					///@param	key	网站域名
					///@param	value	配置信息项
			map<string, CDBConnectString> m_websitecodeMap;

			///保存网站访问日志信息的map
					///@param	key	网站服务器名
					///@param	value	配置信息项
			map<string, CDBConnectString> m_accesslogMap;

			///保存SAN配置信息的map
					///@param	key	SAN设备名
					///@param	value	配置信息项
			map<string, CDBConnectString> m_sanMap;

			///保存SAN事件日志配置信息的map
					///@param	key	SAN设备名
					///@param	value	配置信息项
			map<string, CDBConnectString> m_saneventMap;

			///保存数据库监控指标信息的map
					///@param	key	监控属性名
					///@param	value	该对象所在数据表及对应数据库别名信息表
			map<string, listTDB> m_attrMap;

			///保存数据库监控指标及其采样定时器信息的map
					///@param	key	监控属性名
					///@param	value	采样定时器配置信息
			map<string, string> m_attrtimerMap;
		};

	/* */
	public:
		///构造函数
			///@param	pszPathName	XML配置文件所在路径名,如"../config"
		CXMLConfig(char *pszPathName);

		///析构函数
		~ CXMLConfig(void);

		///获取全部Agent配置节点链表
			///@return	返回配置节点链表,NULL表示获取失败
		CXMLNodeList *GetAgentsCfgNodeList(void);

		///获取指定Agent的配置信息
			///@param	pszAgentName	Agent对象别名
			///@return	返回配置节点项,NULL表示获取失败
		CXMLNode *GetAgentCfgNodeByName(char *pszAgentName);

		///获取指定Agent上层服务列表
			///@param	pszAgentName	Agent对象别名
			///@param	listInfo	用于记录Agent上层服务项信息的列表
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetAgentConnListByName(
				char *pszAgentName,
				list<CServerInfo> &listInfo);

		///获取BNS服务器列表
			///@param	listInfo	用于记录Agent上层服务项信息的列表
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetBNSList(list<CBNSInfo> &listInfo);

		///获取指定Agent的地址信息
			///@param	pszAgentName	Agent对象别名
			///@return	返回Tcp地址串,NULL表示获取失败
		char *GetAgentLocationByName(char *pszAgentName);

		///获取全部前置配置项信息map
			///@param	frontMap	用于保存前置配置项信息的map引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetFrontMap(map<int, string> &frontMap);

		///获取全部snmpmanager配置项信息map
			///@param	frontMap	用于保存连接配置项信息的map引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetSnmpManagerMap(map<int, string> &managerMap);

		///获取指定前置的地址信息
			///@param	pszLocation	用于保存指定前置的地址信息
			///@param	iFrontID	指定前置的标识号
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetFrontLocation(char *pszLocation, int iFrontID);

		///获取本地查询服务器地址,若存在多个,则仅返回首个
			///@param	pszLocation	用于本地查询服务器地址的字串指针
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetQueryLocation(char *pszLocation);

		///获取事件记数器侦听端口信息,若存在多个,仅返回最先找到的
			///@param	pszAgentLocation	用于保存采集代理部署地址的字串指针
			///@param	pszFrontLocation	用于保存前置部署地址的字串指针
			///@param	pszProbeLocation	用于保存作为探针地址的字串指针, 20090807 zhou.jj
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetEventCounterListener(
				char *pszAgentLocation,
				char *pszFrontLocation,
				char *pszProbeLocation);

		///获取所有fibproxy的部署地址列表
			///@param	listLocations	用于保存fibproxy部署地址的链表对象引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetFibProxyLocation(list<string> &listLocations);

		///获取fibclient面向sysfront的部署地址,若存在多个,则仅返回首个
			///@param	pszLocation	用于保存fibclient部署地址的字串指针
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetFibClientLocation(char *pszLocation);

		///获取fibclient面向syseventcounter的部署地址,若存在多个,则仅返回首个
			///@param	pszLocation	用于保存fibclient部署地址的字串指针
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetFibEventLocation(char *pszLocation);

		///获取指定服务的部署地址,若存在多个,则仅返回首个
			///@param	pszLocation	用于保存服务部署地址的字串指针
			///@param	pszService	用于保存服务标识字串指针
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetServiceLocation(char *pszLocation, char *pszService);

		///获取指定服务的部署地址,若存在多个,则仅返回首个
			///@param	pszLocation	用于保存服务部署地址的字串指针
			///@param	pszService	用于保存服务标识字串指针
			///@param	pszProp	用于保存服务检索关键属性字串指针
			///@param	pszValue	用于保存服务检索关键属性值域字串指针
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetServiceLocation(
				char *pszLocation,
				char *pszService,
				char *pszProp,
				char *pszValue);

		///释放指定采集代理对应的探针对象list
			///@param	probeList	用于保存指定采集代理对应的探针对象的list引用
		void DropAgentProbeCfgList(list<CProbeConfig *> &probeList);

		///获取所有探针配置信息的链表,该list由调用者负责释放(可调用DropAgentProbeCfgList())
			///@param	probeList	用于保存探针配置信息的list引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetProbeConfigList(list<CProbeConfig *> &probeList);

		///获取所有主机名与对应数据中心名的map
			///@param	probeList	用于所有主机名与对应数据中心名的map引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetHostDataCenterMap(map<string, string> &HostDataCenterMap);

		///释放主机地址与对应探针配置信息的map
			///@param	probeList	主机地址与对应探针配置信息的map
		void DropLocationProbeMap(map<string, CProbeConfig *> &probeMap);

		///获取监控指标与其对应类型信息的map
			///@param	attrtypeMap	用于保存监控指标与其对应类型的map引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetAttrTypeMap(map<string, int> &attrtypeMap);

		///获取监控指标与其监控同期的map
			///@param	attrintervalMap	用于保存监控指标与其对应类型的map引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetAttrIntervalMap(map<string, int> &attrintervalMap);

		///获取监控指标与其对应应用对象链表的map
			///@param	attrappMap	用于保存监控指标与其对应应用对象链表的map引用
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetAttrAppMap(map<string, list<string> > &attrappMap);

		///获取指定数据中心部署交易应用的ID链表
			///@param	piCenterID	指向保存数据中心的ID号的指针
			///@param	strCenterName	用于保存数据中心全名(含系统名)的string引用
			///@param	appList	用于保存交易应用ID的list引用
			///@param	pszDataCenter	指定数据中心名,如"PuDian"
			///@param	pszAppName	指定交易应用的名称．如"front"
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetAppList(
				int *piCenterID,
				string	&strCenterName,
				list<string> &appList,
				const char	*pszDataCenter,
				const char	*pszAppName);

		///由探针名获取单个探针配置项信息项,CProbeConfig对象由调用者负责释放
			///@param	pszProbeName	用于传入目标探针名称的字串指针
			///@return	返回探针配置项信息项,无则返回NULL
		CProbeConfig *GetProbeConfigN(char *pszProbeName);

		///由探针属性项获取单个探针配置项信息项,CProbeConfig对象由调用者负责释放
			///@param	pszProp	用于传入目标探针属性名称的字串指针
			///@param	pszValue	用于传入目标探针属性值的字串指针
			///@return	返回探针配置项信息项,无则返回NULL
		CProbeConfig *GetProbeConfig(char *pszProp, char *pszValue);

		///由探针地址获取单个探针配置项信息项,CProbeConfig对象由调用者负责释放
			///@param	pszLocation	用于传入目标探针地址的字串指针
			///@return	返回探针配置项信息项,无则返回NULL
		CProbeConfig *GetProbeConfigL(char *pszLocation);

		///获取Deploy配置文件中的查询服务器数据库连接信息
			///@param	DatabaseInfo	用于保存获取的数据库连接信息
			///@return	返回操作结果,true表示获取成功,false表示获取失败
		bool GetQueryDBInfo(CDBConnectString &DatabaseInfo);

		///获取System配置文件根节点指针
			///@return	返回根节点指针,不存在时为NULL
		CXMLNode *GetSystemRootNode(void)
		{
			return m_pSystemCfgRoot;
		};

		///获取Deploy配置文件根节点指针
			///@return	返回根节点指针,不存在时为NULL
		CXMLNode *GetDeployRootNode(void)
		{
			return m_pDeployCfgRoot;
		};

		///获取System配置文件根节点指针
			///@return	返回根节点指针,不存在时为NULL
		CXMLDoc *GetSystemCfgDoc(void)
		{
			return m_pSystemCfgDoc;
		};

		///获取Deploy配置文件根节点指针
			///@return	返回根节点指针,不存在时为NULL
		CXMLDoc *GetDeployCfgDoc(void)
		{
			return m_pDeployCfgDoc;
		};

	/* */
	public:
		///加载System配置文件信息,获取配置文件根结点
		void LoadSystemConfig(void);

		///加载Deploy配置文件信息,获取配置文件根结点
		void LoadDeployConfig(void);

		///获取全局数据库连接字串列表
			///@param	listInfo	保存数据库连接字串的list引用
			///@return	返回操作结果，True为成功，False为失败
		bool GetDBConnectStringList(list<CDBConnectString> &listInfo);

		///获取目标结点的指定属性字串
			///@param	pNode	目标结点的指针
			///@param	pProperty	指定属性字串名的字符指针
			///@param	sObject	存储结果字符的string引用
			///@return	返回属性字串值，不存在时返回空字串“”
		static bool GetNodeProperty(
						CXMLNode *pNode,
						const char	*pszProperty,
						string	&sObject);

		///获取服务部署项节点指针
			///@return	返回服务部署项节点指针,不存在时为NULL
		CXMLNode *GetServicesNode(void);

		///获取指定服务部署项节点指针
			///@param	pszNodeTag	用于保存服务标识字符指针
			///@return	返回服务部署项节点指针,不存在时为NULL
		CXMLNode *GetServiceNode(char *pszNodeTag);

		///获取目标节点下指定属性间的关系映射图
			///@param	dstMap	用于映射关系的map引用
			///@param	pszKeyProp	用于保存作为关键字项的属性名字符指针
			///@param	pszValueProp	用于保存作为值项的属性名字符指针
			///@param	pNode	目标节点对象指针
		static void getIntStringMap(
						map<int, string> &dstMap,
						char *pszKeyProp,
						char *pszValueProp,
						CXMLNode *pNode);

		///获取目标节点下指定属性间的字符型关系映射图
			///@param	dstMap	用于映射关系的map引用
			///@param	pszKeyProp	用于保存作为关键字项的属性名字符指针
			///@param	pszValueProp	用于保存作为值项的属性名字符指针
			///@param	pNode	目标节点对象指针
		static void getStringMap(
						map<string, string> &dstMap,
						char *pszKeyProp,
						char *pszValueProp,
						CXMLNode *pNode);

		///获取指定子节点下指定属性间的字符型关系映射图
			///@param	mapString	用于存储映射关系的map引用
			///@param	pszTagName	用于保存作为子结点关键字项的Tag字符指针
			///@param	pszKeyPropName	用于保存作为关键字项的属性名字符指针
			///@param	pszValuePropName	用于保存作为值项的属性名字符指针
			///@param	pNode	父结点指针项
		static void NodeGetStringMap(
						map<string, string> &mapString,
						char *pszTagName,
						char *pszKeyPropName,
						char *pszValuePropName,
						CXMLNode *pNode);

		///获取指定子节点下指定属性间的字符型关系映射图
			///@param	mapString	用于存储映射关系的map引用
			///@param	pszTagName	用于保存作为子结点关键字项的Tag字符指针
			///@param	pszKeyProp1	用于保存作为首要关键字项的属性名字符指针
			///@param	pszKeyProp2	用于保存作为次要关键字项的属性名字符指针
			///@param	pszValuePropName	用于保存作为值项的属性名字符指针
			///@param	pNode	父结点指针项
		static void NodeGetStringMap(
						map<string, string> &mapString,
						char *pszTagName,
						char *pszKeyProp1,
						char *pszKeyProp2,
						char *pszValuePropName,
						CXMLNode *pNode);

		///获取指定子节点下指定属性间的关系映射图
			///@param	mapDBConnect	用于存储映射关系的map引用
			///@param	pszTagName	用于保存作为子结点关键字项的Tag字符指针
			///@param	pszKeyProp	用于作为map关键字项的属性段字符指针
			///@param	pszPropName	作为关键属性名的字符指针
			///@param	pszPropIP	作为某特定值的字符指针
			///@param	pszPropUser	作为某特定值的字符指针
			///@param	pszPropPswd	作为某特定值的字符指针
			///@param	pszPropEnv	作为某特定值的字符指针
			///@param	pNode	父结点指针项
		static void NodeGetDBStringMap(
						map<string, CDBConnectString> &mapDBConnect,
						char *pszTagName,
						char *pszKeyProp,
						char *pszPropName,
						char *pszPropIP,
						char *pszPropUser,
						char *pszPropPswd,
						char *pszIntPort,
						CXMLNode *pNode);

		///获取指定子节点下指定属性间的关系映射图
			///@param	mapDBConnect	用于存储映射关系的map引用
			///@param	pszTagName	用于保存作为子结点关键字项的Tag字符指针
			///@param	pszKeyProp	用于作为map关键字项的属性段字符指针
			///@param	pszPropName	作为关键属性名的字符指针
			///@param	pszPropIP	作为某特定值的字符指针
			///@param	pszPropUser	作为某特定值的字符指针
			///@param	pszPropPswd	作为某特定值的字符指针
			///@param	pszPropEnv	作为某特定值的字符指针
			///@param	pNode	父结点指针项
		static void NodeGetDBStringMapS(
						map<string, CDBConnectString> &mapDBConnect,
						char *pszTagName,
						char *pszKeyProp,
						char *pszPropName,
						char *pszPropIP,
						char *pszPropUser,
						char *pszPropPswd,
						char *pszPropEnv,
						CXMLNode *pNode);

		///获取目标节点下指定属性间的字符型关系映射图
			///@param	dstMap	用于映射关系的map引用
			///@param	pszKeyProp1	用于保存作为首要关键字项的属性名字符指针
			///@param	pszKeyProp2	用于保存作为次要关键字项的属性名字符指针
			///@param	pszValueProp	用于保存作为值项的属性名字符指针
			///@param	pNode	目标节点对象指针
		static void getStringMap(
						map<string, string> &dstMap,
						char *pszKeyProp1,
						char *pszKeyProp2,
						char *pszValueProp,
						CXMLNode *pNode);

	/* */
	public:
		///用于保存System配置文件名(含路径)
		char m_szSystemConfig[MAX_FILENAME_LEN];

		///用于保存Deploy配置文件名(含路径)
		char m_szDeployConfig[MAX_FILENAME_LEN];

	/* */
	private:
		///用于保存配置文件所在路径
		char m_szPathName[MAX_FILENAME_LEN];

		///System配置文件文档对象指针
		CXMLDoc *m_pSystemCfgDoc;

		///Deploy配置文件文档对象指针
		CXMLDoc *m_pDeployCfgDoc;

		///System配置文件根节点指针
		CXMLNode *m_pSystemCfgRoot;

		///Deploy配置文件根节点指针
		CXMLNode *m_pDeployCfgRoot;
};
#endif // end of "#ifndef REF_XMLCFG_H"
