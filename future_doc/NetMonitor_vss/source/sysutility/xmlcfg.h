/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	xmlcfg.h
///@brief	�����˶�ȡXML�����ļ����õ���ͺ���
///@history
///20080630	�̺״�	�������ļ�
///20090219	�̺״�	SystemConfig.xml�ļ��ṹ�ı䣬���������ϵͳ�򻮷֣�������������Ӧ����
/////////////////////////////////////////////////////////////////////////
#ifndef REF_XMLCFG_H
#define REF_XMLCFG_H

#define UNKNOWN_ATTR		0						///δ֪���͵���������
#define STRING_ATTR			1						///�ַ�����������
#define INT_ATTR			2						///������������
#define FLOAT_ATTR			3						///����������
#define PERCENT_ATTR		4						///�ٷֱ���������
#define STRING_ATTR_DESC	"string"				///�ַ���������������
#define INT_ATTR_DESC		"int"					///����������������
#define FLOAT_ATTR_DESC		"float"					///��������������
#define PERCENT_ATTR_DESC	"percent"				///�ٷֱ�������������

// add by zhou.jj 20090302 15:20
#define DOTDATACENTERAPPDOT		".app."				// ��������appӦ��ҵ������
#define DOTDATACENTERHOSTDOT	".os."				// ������������������
#define DOTDATACENTERTOMCATDOT	".tomcat."			// ��������Tomcat������
#define DOTDATACENTERDBDOT		".db."				// ��������db������
#define DOTDATACENTERAPACHEDOT	".apache."			// ��������apache������

// add by zhou.jj 20090626
#define DBSEPARATORSTRING			"@#$"			// ���ݿⷵ�ؽ���øô����ָ���
#define DBSEPARATORRECORD			"\r\n"			// ���ݿⷵ�ؽ���øô����ָ��м�¼
#define DATACENTERSAN				"san"			// ��������sanӦ����ҵ������
#define DATACENTERAPP				"app"			// ��������appӦ��ҵ������
#define DATACENTERTOMCAT			"tomcat"		// ��������tomcat��Ϣ����
#define DATACENTERAPACHE			"apache"		// ��������apache��Ϣ����
#define DATACENTERHOST				"os"			// ������������������
#define DATACENTERDB				"db"			// �����������ݿ�����
#define DATACENTERDBNODE			"dbnode"		// �����������ݿ�ڵ�����
#define HOSTATTRENV					"env"			// ������������
#define HOSTATTRCPU					"cpu"			// ����CPU
#define HOSTATTRMEM					"mem"			// ����MEM
#define HOSTATTRPROCESS				"process"		// ����Process
#define HOSTATTRFS					"fs"			// ����filesystem
#define HOSTATTRNET					"network"		// ����network
#define HOSTATTRUSER				"user"			// �����û��б������û�
#define HOSTATTRSYSLOG				"syslog"		// ������־
#define HOSTATTRKEYFILE				"keyfile"		// �����ؼ��ļ�
#define HOSTATTRDFMTLOG				"dfmtlog"		// DFMT�ļ�
#define TOMCATATTROVERVIEW			"overview"		// Tomcat����
#define TOMCATATTRWEBAPP			"webapp"		// TomcatӦ�ò���
#define TOMCATATTRJDBC				"jdbc"			// Tomcat����Դ
#define TOMCATATTRLOGFILE			"logfile"		// Tomcatϵͳ��־
#define TOMCATATTRTHREAD			"thread"		// Tomcat�߳�
#define TOMCATATTRSYSTEM			"system"		// Tomcatϵͳ
#define TOMCATATTRCONNECTOR			"connector"		// Tomcat������
#define DATACENTERPUDIAN			"PuDian"		// �ֵ�����������
#define DATACENTERZHANGJ			"ZhangJ"		// �Ž�����������
#define DATACENTERBEIJING			"BeiJing"		// ��������������
#define OBJOrderStatus				"OrderStatus"	//����״̬��������
#define OBJBargainOrder				"BargainOrder"	//�ɽ�����������
#define OBJInvalidateOrder			"InvalidateOrder"			// ���󱨵���������
#define OBJParticipant				"ParticipantInit"			//��Ա������
#define OBJUser						"UserInit"					//��ϯ������
#define OBJClient					"ClientInit"				//�ͻ�������
#define OBJParticTradeOrderStates	"ParticTradeOrderStates"	//����ͳ��
#define OBJInstrumentStatus			"InstrumentStatus"			//��Լ״̬�л�
#define OBJCurrTradingSegmentAttr	"CurrTradingSegmentAttr"	//���׽���Ϣ
#define TIME_FIB2EVENT				5000						//FIBCLIENT���¼����������������Ϣ��ʱ�䲽��
#define TIME_FIB2FRONT1				5					//FIBCLIENT��ǰ�û�������Ϣ��ʱ�䲽��
#define TIME_FIB2FRONT2				60					//FIBCLIENT��ǰ�û�������Ϣ��ʱ�䲽��
#define TIME_FIB2FRONT3				1					//FIBCLIENT��ǰ�û�������Ϣ��ʱ�䲽��
#define HOSTATTRAPPLOG				"applog"			// ����ϵͳӦ������־
#define HOSTATTRSESSIONLOG			"sessionlog"		// �����Ƶ�Slog
#define FRONTPROTOCOL				"FTD"				// FTDЭ��������
#define ATTRFTDCLIENTCOUNT			"ftdclientcount"	//FTDʹ��Э�����͵Ŀͻ���������
#define XML_DEFAULT_PATHNAME		"./"				// Ĭ�������ļ�·��
#define XML_FILE_SYSTEM				"SystemConfig.xml"	// ϵͳ����XML�ļ���
#define XML_FILE_DEPLOY				"DeployConfig.xml"	// ��������XML�ļ���

// ��Ҫ��ǩ��
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

// ��Ҫ������
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

// ��Ҫ�ؼ���ֵ
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

#define MAX_FILENAME_LEN				256				// ����ļ�������(��·��)
#define MAX_SRVNAME_LEN					32				// ������������
#define MAX_EVENTFLOWNUM				9				// �¼��������������������(1,2,3.....9),Ҫ���һ�ܱ�24����
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "CXML.h"

class CDBConnectString;

//////////////////////////////////////////////////////////////////////////
///CServerInfo	�����˷�����������Ϣ����������
///@auther	�̺״�
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
///CDBConnectString	���������ݿ�������Ϣ����������
///@auther	�ܽ���
///@version	1.0,20080717
///20100330	�̺״�	�����˸����͵����ݽṹ
//////////////////////////////////////////////////////////////////////////
class CDBConnectString
{
	/* */
	public:
		string	m_sAlias;			// ��������ڲ�ʹ�õ����ݿ���������ڹ�����������ӳ���ϵ
		string	m_sEnvironment;		// ��ʶBNS�������ͣ��磺Product
		string	m_sDBName;			// ��BNS���������DB��ǩ��
		string	m_sSystemName;		// ���ݿ�����ϵͳ��ʶ���磺DATABASE
		string	m_sCenterName;		// ���ݿ��������ı�ʶ���磺PuDian
		string	m_sRacServiceName;	// ���ݿ�RAC���ڵ������磺BDB
		string	m_sServiceName;		// ���ݿ�RAC��ʵ���ڵ������磺BDB01
		string	m_sIpAddr;			// ���ݿ����ӵ�IP��ַ
		int m_nPort;				// ���ݿ����ӵĶ˿�
		string	m_sUserName;		// ���ݿ����ӵ��û���
		string	m_sPassword;		// ���ݿ����ӵ��û�����
		string	m_sTreeViewFlag;	// ���ݿ�ڵ��Ƿ���ʾ��TreeView�еı�ʶ
		bool m_bUpdateSP;			// SP�����ñ����ǣ�Ϊfalse��ʾ��Ҫ���ͣ�Ϊtrue��ʾ�Ѿ��������
		bool m_bUpdateRACDB;		// ���ݿ���RAC���ñ����ǣ�Ϊfalse��ʾ��Ҫ���ͣ�Ϊtrue��ʾ�Ѿ��������
		bool m_bUpdateNodeDB;		// ���ݿ���ڵ����ñ����ǣ�Ϊfalse��ʾ��Ҫ���ͣ�Ϊtrue��ʾ�Ѿ��������
		bool m_bUpdateAppSP;		// ���ݿ���APP���ñ����ǣ�Ϊfalse��ʾ��Ҫ���ͣ�Ϊtrue��ʾ�Ѿ��������
		bool m_bReConnectFlag;		// ���ݿ�������ǣ�Ϊtrue��ʾ�����ݿ������Ӧ�������Ѿ����������

	//	��ζ�ٴ�ʹ��ʱ��Ҫ���������ӳɹ�ʱ������Ϊfalse
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

		bool operator!=(const CDBConnectString &ob) const	// ע�⣺�����Ƚ����ݿ���������ԣ����ܱȽϸ��±�Ǻ��������
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
/////CRequestInfo����������OraclePass�������������Ϣ��
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
		///����
		string	szEnv;

		///���ݿ����
		string	szDBName;

		///���ݿ��û���
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

		///��������ַ
		string	m_sServerIP;

		///�������˿�
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
///CTableDBRelation	���������ݱ����ݿ������Ӧ��ϵ����������
///@auther	�̺״�
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
///CXMLConfig������XML�����ļ����������
///@auther	�̺״�
///@version	1.0,20080630
//////////////////////////////////////////////////////////////////////////
class CXMLConfig
{
	/* */
	public:
		class CProbeConfig
		{
		public:
			///���캯��
					///@param	pProbeNode	ProbeConfig�ڵ����ָ��
					///@param	pSystemNode	System�ڵ����ָ��
					///@param	pCommonNode	����������ڵ����ָ��
			CProbeConfig
				(
					CXMLNode *
					pHostNode, CXMLNode *
					pSystemNode, CXMLNode *
					pCommonNode
				);

			///��������
			~CProbeConfig (void);

			///��ȡ��ǰ̽����Ϣ��̽����
					///@return	����̽�����ִ�ָ��,�޴���Ϣʱ����""
			char *GetProbeName(void)
			{
				return m_szProbeName;
			};

			///��ȡ��ǰ̽��ڵ�ָ��
					///@return	����̽��ڵ�ָ��,�޴���Ϣʱ����""
			CXMLNode *GetProbeNode(void)
			{
				return m_pProbeNode;
			};

			///��ȡ��ǰ̽����Ϣ��̽���ַ
					///@return	����̽���ַ�ִ�ָ��,�޴���Ϣʱ����""
			char *GetLocation(void)
			{
				return m_szLocation;
			};

			///��ȡ��ǰ̽����Ϣ�ķ�����IP
					///@return	����̽�������IP�ִ�ָ��,�޴���Ϣʱ����""
			char *GetAddress(void)
			{
				return m_szAddress;
			};

			///��ȡ��ǰ̽������������������
					///@return	�����������ִ�ָ��,�޴���Ϣʱ����""
			char *GetHostName(void)
			{
				return m_szHostName;
			};

			///��ȡ��ǰ̽��������������������
					///@return	�����������ִ�ָ��,�޴���Ϣʱ����""
			char *GetHostAlias(void)
			{
				return m_szHostAlias;
			};

			///��ȡ��ǰ̽��������������������������
					///@return	���������������ִ�ָ��,�޴���Ϣʱ����""
			char *GetDataCenter(void)
			{
				return m_szDataCenter;
			};

			///��ȡ��ǰ̽����������������ϵͳ��
					///@return	����ϵͳ���ִ�ָ��,�޴���Ϣʱ����""
			char *GetSystem(void)
			{
				return m_szSystem;
			};

			///��ȡ��ǰ̽����������������ϵͳ������
					///@return	����ϵͳ���ִ�ָ��,�޴���Ϣʱ����""
			char *GetSystemAlias(void)
			{
				return m_szSystemAlias;
			};

			///��ȡ��ǰ������TreeView��ʾ��ʶ
					///@return	����̽�����ִ�ָ��,�޴���Ϣʱ����""
			char *GetTreeViewFlag(void)
			{
				return m_szTreeViewFlag;
			};

			///��ȡ��ǰ̽����Ϣ���Ķ�ʱ������map
					///@return	���ض�ʱ������map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetTimerMap(void)
			{
				return m_timerMap;
			};

			///��ȡ��ǰ̽����Ϣ�����������������ļ�map
					///@return	�����������������ļ�map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetConfigMap(void)
			{
				return m_configMap;
			};

			///��ȡ��ǰ̽����Ϣ����ҵ�������־�ļ�map
					///@return	����ҵ�������־�ļ�map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetAppLogMap(void)
			{
				return m_applogMap;
			};

			///��ȡ��ǰ̽����Ϣ����ҵ��������ڷ�����map
					///@return	����ҵ��������ڷ�����Ϣ��map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetAppPathMap(void)
			{
				return m_apppathMap;
			};

			///��ȡ��ǰ̽����Ϣ����ϵͳ��־�ļ�map
					///@return	����ϵͳ��־�ļ�map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetSysLogMap(void)
			{
				return m_syslogMap;
			};

			///��ȡ��ǰ̽����Ϣ���Ĺؼ��ļ�map
					///@return	���عؼ��ļ�map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetKeyFileMap(void)
			{
				return m_keyfileMap;
			};

			///��ȡ��ǰ̽����Ϣ���ĻỰ��־�ļ�map
					///@return	���ػỰ��־�ļ�map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetSessionMap(void)
			{
				return m_sessionMap;
			};

			///��ȡ��ǰ̽����Ϣ����DFMT�ļ�map
					///@return	���ػỰ��־�ļ�map,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetDFMTMap(void)
			{
				return m_dfmtMap;
			};

			///��ȡ��ǰ̽����Ϣ�������ݿ���ת��map
					///@return	�������ݿ���Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetDBMappingMap(void)
			{
				return m_dbmappingMap;
			};

			///����Ŀ��ڵ����ݿ������ִ���Ϣ
					///@param	pszAlias	���ڱ������ݿ�������ַ���ָ��
					///@param	pDBConnect	���ڱ������ݿ�������Ϣ�Ľṹָ��
					///@param	pProbeNode	ָ��Ŀ��ڵ�Ľڵ�ָ��
					///@return	���ز������,�ɹ�Ϊtrue,����Ϊfalse
			bool SetDBConnectString(
					const char	*pszAlias,
					CDBConnectString *pDBConnect,
					CXMLNode *pProbeNode);

			///��ȡ��ǰ̽����Ϣ����Tomcat������Ϣmap
					///@return	����Tomcat������Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetTomcatMap(void)
			{
				return m_tomcatMap;
			};

			///��ȡ��ǰ̽����Ϣ���Ĵ洢����������Ϣmap
					///@return	����Tomcat������Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetAppSPMap(void)
			{
				return m_AppSPMap;
			};

			///��ȡ��ǰ̽����Ϣ�������ݿ���洢����������Ϣmap
					///@return	����Tomcat������Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetNodeSPMap(void)
			{
				return m_NodeSPMap;
			};

			///��ȡ��ǰ̽����Ϣ���Ĵ洢����������Ϣmap
					///@return	����Tomcat������Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetDBSPMap(void)
			{
				return m_DBSPMap;
			};

			///��ȡ��ǰ̽����Ϣ����DBlog����������Ϣmap
					///@return	����Tomcat������Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetDBLogMap(void)
			{
				return m_dblogMap;
			};

			///��ȡ��ǰ̽����Ϣ������վ���·��������Ϣmap
					///@return	����map,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetFileCodeMap(void)
			{
				return m_filecodeMap;
			};

			///��ȡ��ǰ̽����Ϣ������վ״̬��У��������Ϣmap
					///@return	����map,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetWebsiteCodeMap(void)
			{
				return m_websitecodeMap;
			};

			///��ȡ��ǰ̽����Ϣ������վ������־������Ϣmap
					///@return	����map,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetAccessLogMap(void)
			{
				return m_accesslogMap;
			};

			///��ȡ��ǰ̽����Ϣ����SAN���·��������Ϣmap
					///@return	����map,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetSANMap(void)
			{
				return m_sanMap;
			};

			///��ȡ��ǰ̽����Ϣ����SAN�¼���־������Ϣmap
					///@return	����map,�޴���Ϣʱmap��sizeΪ0
			map<string, CDBConnectString> &GetSANEventMap(void)
			{
				return m_saneventMap;
			};

			///��ȡ��ǰ̽����Ϣ�������ݿ���ָ����Ϣmap
					///@return	�������ݿ�������Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, listTDB> &GetAttrMap(void)
			{
				return m_attrMap;
			};

			///��ȡ��ǰ̽����Ϣ�������ݿ���ָ�꼰�������ʱ����Ϣmap
					///@return	�������ݿ�������Ϣmap,�޴���Ϣʱmap��sizeΪ0
			map<string, string> &GetAttrTimerMap(void)
			{
				return m_attrtimerMap;
			};
		private:
			///��ȡĿ��ڵ�ָ����������ַ���ֵ
					///@param	pszValue	���ڱ���ֵ����ַ���ָ��
					///@param	pszProp	���ڱ������������ַ���ָ��
					///@param	iMaxLen	ֵ������������Ϸ��ַ�������
					///@param	pNode	Ŀ��ڵ����ָ��
			void getPropValue(
					char *pszValue,
					char *pszProp,
					const int iMaxLen,
					CXMLNode *pNode);

			///��ȡĿ��ڵ��¸�������Ϣ�����������Ϣ�������Ӧ��Աӳ��ͼ��
					///@param	pHostNode	Ŀ��ڵ����ָ��
			void loadMaps(CXMLNode *pHostNode);
		private:
			///̽����
			char m_szProbeName[MAX_SRVNAME_LEN];

			///̽���ַ
			char m_szLocation[MAX_SRVNAME_LEN];

			///̽��IP��ַ
			char m_szAddress[MAX_SRVNAME_LEN];

			///̽������������
			char m_szHostName[MAX_SRVNAME_LEN];

			///̽��������������
			char m_szHostAlias[MAX_SRVNAME_LEN];

			///̽��������������������������
			char m_szDataCenter[MAX_SRVNAME_LEN];

			///̽����������������ϵͳ��
			char m_szSystem[MAX_SRVNAME_LEN];

			///̽����������������ϵͳ������
			char m_szSystemAlias[MAX_SRVNAME_LEN];

			///�������Ƿ���ʾ��TreeView�еı�ʶ
			char m_szTreeViewFlag[MAX_SRVNAME_LEN];

			///̽��ڵ����ָ��
			CXMLNode *m_pProbeNode;

			///����̽�붨ʱ����Ϣ��map
					///@param	key	���涨ʱ����ӦӦ�ý�����
					///@param	value	���涨ʱ�����ʱ��(��λ:��)
			map<string, string> m_timerMap;

			///�����������������ļ���Ϣ��map
					///@param	key	��������������
					///@param	value	�����������������ļ���(��·��)
			map<string, string> m_configMap;

			///����ҵ�������־�ļ���Ϣ��map
					///@param	key	����ҵ�������
					///@param	value	����ҵ�������־�ļ���(��·��)
			map<string, string> m_applogMap;

			///����ҵ��������ڷ�����map
					///@param	key	����ҵ�������
					///@param	value	����ҵ����̵ķ�����,��"/home"
			map<string, string> m_apppathMap;

			///����ϵͳ��־�ļ���Ϣ��map
					///@param	key	����ϵͳ��־�ļ���
					///@param	value	����ϵͳ��־�ļ���(��·��)
			map<string, string> m_syslogMap;

			///����ϵͳ�ؼ��ļ���Ϣ��map
					///@param	key	����ؼ��ļ���
					///@param	value	����ؼ��ļ���(��·��)
			map<string, string> m_keyfileMap;

			///����DFMT�ļ���Ϣ��map
					///@param	key	����Ự��־�ļ���
					///@param	value	����DFMT�ļ���(��·��)
			map<string, string> m_dfmtMap;

			///����Ự��־�ļ���Ϣ��map
					///@param	key	����Ự��־�ļ���
					///@param	value	����Ự��־�ļ���(��·��)
			map<string, string> m_sessionMap;

			///�������ݿ�������Ϣ��map
					///@param	key	���ݿ������
					///@param	value	���ݿ������
			map<string, string> m_databaseMap;

			///�������ݿ����ӳ���map
					///@param	key	���ݿ����
					///@param	value	���ݿ�������
			map<string, string> m_dbmappingMap;

			///����Tomcat������Ϣ��map
					///@param	key	Tomcate������
					///@param	value	���ݿ�������Ϣ
			map<string, CDBConnectString> m_tomcatMap;

			///����Ӧ���ʹ洢����������Ϣ��map
					///@param	key	�洢���̶�����
					///@param	value	�洢����������Ϣ
			map<string, CDBConnectString> m_AppSPMap;

			///�������ݿ�ڵ��ʹ洢����������Ϣ��map
					///@param	key	�洢���̶�����
					///@param	value	�洢����������Ϣ
			map<string, CDBConnectString> m_NodeSPMap;

			///�������ݿ��ʹ洢����������Ϣ��map
					///@param	key	�洢���̶�����
					///@param	value	�洢����������Ϣ
			map<string, CDBConnectString> m_DBSPMap;

			///����DBlog������Ϣ��map
					///@param	key	DBlog���ö�����
					///@param	value	DBlog������Ϣ
			map<string, CDBConnectString> m_dblogMap;

			///������վ�ļ�У��·��������Ϣ��map
					///@param	key	�ļ�·��
					///@param	value	������Ϣ��
			map<string, CDBConnectString> m_filecodeMap;

			///������վ״̬��У��������Ϣ��map
					///@param	key	��վ����
					///@param	value	������Ϣ��
			map<string, CDBConnectString> m_websitecodeMap;

			///������վ������־��Ϣ��map
					///@param	key	��վ��������
					///@param	value	������Ϣ��
			map<string, CDBConnectString> m_accesslogMap;

			///����SAN������Ϣ��map
					///@param	key	SAN�豸��
					///@param	value	������Ϣ��
			map<string, CDBConnectString> m_sanMap;

			///����SAN�¼���־������Ϣ��map
					///@param	key	SAN�豸��
					///@param	value	������Ϣ��
			map<string, CDBConnectString> m_saneventMap;

			///�������ݿ���ָ����Ϣ��map
					///@param	key	���������
					///@param	value	�ö����������ݱ���Ӧ���ݿ������Ϣ��
			map<string, listTDB> m_attrMap;

			///�������ݿ���ָ�꼰�������ʱ����Ϣ��map
					///@param	key	���������
					///@param	value	������ʱ��������Ϣ
			map<string, string> m_attrtimerMap;
		};

	/* */
	public:
		///���캯��
			///@param	pszPathName	XML�����ļ�����·����,��"../config"
		CXMLConfig(char *pszPathName);

		///��������
		~ CXMLConfig(void);

		///��ȡȫ��Agent���ýڵ�����
			///@return	�������ýڵ�����,NULL��ʾ��ȡʧ��
		CXMLNodeList *GetAgentsCfgNodeList(void);

		///��ȡָ��Agent��������Ϣ
			///@param	pszAgentName	Agent�������
			///@return	�������ýڵ���,NULL��ʾ��ȡʧ��
		CXMLNode *GetAgentCfgNodeByName(char *pszAgentName);

		///��ȡָ��Agent�ϲ�����б�
			///@param	pszAgentName	Agent�������
			///@param	listInfo	���ڼ�¼Agent�ϲ��������Ϣ���б�
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetAgentConnListByName(
				char *pszAgentName,
				list<CServerInfo> &listInfo);

		///��ȡBNS�������б�
			///@param	listInfo	���ڼ�¼Agent�ϲ��������Ϣ���б�
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetBNSList(list<CBNSInfo> &listInfo);

		///��ȡָ��Agent�ĵ�ַ��Ϣ
			///@param	pszAgentName	Agent�������
			///@return	����Tcp��ַ��,NULL��ʾ��ȡʧ��
		char *GetAgentLocationByName(char *pszAgentName);

		///��ȡȫ��ǰ����������Ϣmap
			///@param	frontMap	���ڱ���ǰ����������Ϣ��map����
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetFrontMap(map<int, string> &frontMap);

		///��ȡȫ��snmpmanager��������Ϣmap
			///@param	frontMap	���ڱ���������������Ϣ��map����
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetSnmpManagerMap(map<int, string> &managerMap);

		///��ȡָ��ǰ�õĵ�ַ��Ϣ
			///@param	pszLocation	���ڱ���ָ��ǰ�õĵ�ַ��Ϣ
			///@param	iFrontID	ָ��ǰ�õı�ʶ��
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetFrontLocation(char *pszLocation, int iFrontID);

		///��ȡ���ز�ѯ��������ַ,�����ڶ��,��������׸�
			///@param	pszLocation	���ڱ��ز�ѯ��������ַ���ִ�ָ��
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetQueryLocation(char *pszLocation);

		///��ȡ�¼������������˿���Ϣ,�����ڶ��,�����������ҵ���
			///@param	pszAgentLocation	���ڱ���ɼ��������ַ���ִ�ָ��
			///@param	pszFrontLocation	���ڱ���ǰ�ò����ַ���ִ�ָ��
			///@param	pszProbeLocation	���ڱ�����Ϊ̽���ַ���ִ�ָ��, 20090807 zhou.jj
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetEventCounterListener(
				char *pszAgentLocation,
				char *pszFrontLocation,
				char *pszProbeLocation);

		///��ȡ����fibproxy�Ĳ����ַ�б�
			///@param	listLocations	���ڱ���fibproxy�����ַ�������������
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetFibProxyLocation(list<string> &listLocations);

		///��ȡfibclient����sysfront�Ĳ����ַ,�����ڶ��,��������׸�
			///@param	pszLocation	���ڱ���fibclient�����ַ���ִ�ָ��
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetFibClientLocation(char *pszLocation);

		///��ȡfibclient����syseventcounter�Ĳ����ַ,�����ڶ��,��������׸�
			///@param	pszLocation	���ڱ���fibclient�����ַ���ִ�ָ��
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetFibEventLocation(char *pszLocation);

		///��ȡָ������Ĳ����ַ,�����ڶ��,��������׸�
			///@param	pszLocation	���ڱ���������ַ���ִ�ָ��
			///@param	pszService	���ڱ�������ʶ�ִ�ָ��
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetServiceLocation(char *pszLocation, char *pszService);

		///��ȡָ������Ĳ����ַ,�����ڶ��,��������׸�
			///@param	pszLocation	���ڱ���������ַ���ִ�ָ��
			///@param	pszService	���ڱ�������ʶ�ִ�ָ��
			///@param	pszProp	���ڱ����������ؼ������ִ�ָ��
			///@param	pszValue	���ڱ����������ؼ�����ֵ���ִ�ָ��
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetServiceLocation(
				char *pszLocation,
				char *pszService,
				char *pszProp,
				char *pszValue);

		///�ͷ�ָ���ɼ������Ӧ��̽�����list
			///@param	probeList	���ڱ���ָ���ɼ������Ӧ��̽������list����
		void DropAgentProbeCfgList(list<CProbeConfig *> &probeList);

		///��ȡ����̽��������Ϣ������,��list�ɵ����߸����ͷ�(�ɵ���DropAgentProbeCfgList())
			///@param	probeList	���ڱ���̽��������Ϣ��list����
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetProbeConfigList(list<CProbeConfig *> &probeList);

		///��ȡ�������������Ӧ������������map
			///@param	probeList	�����������������Ӧ������������map����
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetHostDataCenterMap(map<string, string> &HostDataCenterMap);

		///�ͷ�������ַ���Ӧ̽��������Ϣ��map
			///@param	probeList	������ַ���Ӧ̽��������Ϣ��map
		void DropLocationProbeMap(map<string, CProbeConfig *> &probeMap);

		///��ȡ���ָ�������Ӧ������Ϣ��map
			///@param	attrtypeMap	���ڱ�����ָ�������Ӧ���͵�map����
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetAttrTypeMap(map<string, int> &attrtypeMap);

		///��ȡ���ָ��������ͬ�ڵ�map
			///@param	attrintervalMap	���ڱ�����ָ�������Ӧ���͵�map����
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetAttrIntervalMap(map<string, int> &attrintervalMap);

		///��ȡ���ָ�������ӦӦ�ö��������map
			///@param	attrappMap	���ڱ�����ָ�������ӦӦ�ö��������map����
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetAttrAppMap(map<string, list<string> > &attrappMap);

		///��ȡָ���������Ĳ�����Ӧ�õ�ID����
			///@param	piCenterID	ָ�򱣴��������ĵ�ID�ŵ�ָ��
			///@param	strCenterName	���ڱ�����������ȫ��(��ϵͳ��)��string����
			///@param	appList	���ڱ��潻��Ӧ��ID��list����
			///@param	pszDataCenter	ָ������������,��"PuDian"
			///@param	pszAppName	ָ������Ӧ�õ����ƣ���"front"
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetAppList(
				int *piCenterID,
				string	&strCenterName,
				list<string> &appList,
				const char	*pszDataCenter,
				const char	*pszAppName);

		///��̽������ȡ����̽����������Ϣ��,CProbeConfig�����ɵ����߸����ͷ�
			///@param	pszProbeName	���ڴ���Ŀ��̽�����Ƶ��ִ�ָ��
			///@return	����̽����������Ϣ��,���򷵻�NULL
		CProbeConfig *GetProbeConfigN(char *pszProbeName);

		///��̽���������ȡ����̽����������Ϣ��,CProbeConfig�����ɵ����߸����ͷ�
			///@param	pszProp	���ڴ���Ŀ��̽���������Ƶ��ִ�ָ��
			///@param	pszValue	���ڴ���Ŀ��̽������ֵ���ִ�ָ��
			///@return	����̽����������Ϣ��,���򷵻�NULL
		CProbeConfig *GetProbeConfig(char *pszProp, char *pszValue);

		///��̽���ַ��ȡ����̽����������Ϣ��,CProbeConfig�����ɵ����߸����ͷ�
			///@param	pszLocation	���ڴ���Ŀ��̽���ַ���ִ�ָ��
			///@return	����̽����������Ϣ��,���򷵻�NULL
		CProbeConfig *GetProbeConfigL(char *pszLocation);

		///��ȡDeploy�����ļ��еĲ�ѯ���������ݿ�������Ϣ
			///@param	DatabaseInfo	���ڱ����ȡ�����ݿ�������Ϣ
			///@return	���ز������,true��ʾ��ȡ�ɹ�,false��ʾ��ȡʧ��
		bool GetQueryDBInfo(CDBConnectString &DatabaseInfo);

		///��ȡSystem�����ļ����ڵ�ָ��
			///@return	���ظ��ڵ�ָ��,������ʱΪNULL
		CXMLNode *GetSystemRootNode(void)
		{
			return m_pSystemCfgRoot;
		};

		///��ȡDeploy�����ļ����ڵ�ָ��
			///@return	���ظ��ڵ�ָ��,������ʱΪNULL
		CXMLNode *GetDeployRootNode(void)
		{
			return m_pDeployCfgRoot;
		};

		///��ȡSystem�����ļ����ڵ�ָ��
			///@return	���ظ��ڵ�ָ��,������ʱΪNULL
		CXMLDoc *GetSystemCfgDoc(void)
		{
			return m_pSystemCfgDoc;
		};

		///��ȡDeploy�����ļ����ڵ�ָ��
			///@return	���ظ��ڵ�ָ��,������ʱΪNULL
		CXMLDoc *GetDeployCfgDoc(void)
		{
			return m_pDeployCfgDoc;
		};

	/* */
	public:
		///����System�����ļ���Ϣ,��ȡ�����ļ������
		void LoadSystemConfig(void);

		///����Deploy�����ļ���Ϣ,��ȡ�����ļ������
		void LoadDeployConfig(void);

		///��ȡȫ�����ݿ������ִ��б�
			///@param	listInfo	�������ݿ������ִ���list����
			///@return	���ز��������TrueΪ�ɹ���FalseΪʧ��
		bool GetDBConnectStringList(list<CDBConnectString> &listInfo);

		///��ȡĿ�����ָ�������ִ�
			///@param	pNode	Ŀ�����ָ��
			///@param	pProperty	ָ�������ִ������ַ�ָ��
			///@param	sObject	�洢����ַ���string����
			///@return	���������ִ�ֵ��������ʱ���ؿ��ִ�����
		static bool GetNodeProperty(
						CXMLNode *pNode,
						const char	*pszProperty,
						string	&sObject);

		///��ȡ��������ڵ�ָ��
			///@return	���ط�������ڵ�ָ��,������ʱΪNULL
		CXMLNode *GetServicesNode(void);

		///��ȡָ����������ڵ�ָ��
			///@param	pszNodeTag	���ڱ�������ʶ�ַ�ָ��
			///@return	���ط�������ڵ�ָ��,������ʱΪNULL
		CXMLNode *GetServiceNode(char *pszNodeTag);

		///��ȡĿ��ڵ���ָ�����Լ�Ĺ�ϵӳ��ͼ
			///@param	dstMap	����ӳ���ϵ��map����
			///@param	pszKeyProp	���ڱ�����Ϊ�ؼ�������������ַ�ָ��
			///@param	pszValueProp	���ڱ�����Ϊֵ����������ַ�ָ��
			///@param	pNode	Ŀ��ڵ����ָ��
		static void getIntStringMap(
						map<int, string> &dstMap,
						char *pszKeyProp,
						char *pszValueProp,
						CXMLNode *pNode);

		///��ȡĿ��ڵ���ָ�����Լ���ַ��͹�ϵӳ��ͼ
			///@param	dstMap	����ӳ���ϵ��map����
			///@param	pszKeyProp	���ڱ�����Ϊ�ؼ�������������ַ�ָ��
			///@param	pszValueProp	���ڱ�����Ϊֵ����������ַ�ָ��
			///@param	pNode	Ŀ��ڵ����ָ��
		static void getStringMap(
						map<string, string> &dstMap,
						char *pszKeyProp,
						char *pszValueProp,
						CXMLNode *pNode);

		///��ȡָ���ӽڵ���ָ�����Լ���ַ��͹�ϵӳ��ͼ
			///@param	mapString	���ڴ洢ӳ���ϵ��map����
			///@param	pszTagName	���ڱ�����Ϊ�ӽ��ؼ������Tag�ַ�ָ��
			///@param	pszKeyPropName	���ڱ�����Ϊ�ؼ�������������ַ�ָ��
			///@param	pszValuePropName	���ڱ�����Ϊֵ����������ַ�ָ��
			///@param	pNode	�����ָ����
		static void NodeGetStringMap(
						map<string, string> &mapString,
						char *pszTagName,
						char *pszKeyPropName,
						char *pszValuePropName,
						CXMLNode *pNode);

		///��ȡָ���ӽڵ���ָ�����Լ���ַ��͹�ϵӳ��ͼ
			///@param	mapString	���ڴ洢ӳ���ϵ��map����
			///@param	pszTagName	���ڱ�����Ϊ�ӽ��ؼ������Tag�ַ�ָ��
			///@param	pszKeyProp1	���ڱ�����Ϊ��Ҫ�ؼ�������������ַ�ָ��
			///@param	pszKeyProp2	���ڱ�����Ϊ��Ҫ�ؼ�������������ַ�ָ��
			///@param	pszValuePropName	���ڱ�����Ϊֵ����������ַ�ָ��
			///@param	pNode	�����ָ����
		static void NodeGetStringMap(
						map<string, string> &mapString,
						char *pszTagName,
						char *pszKeyProp1,
						char *pszKeyProp2,
						char *pszValuePropName,
						CXMLNode *pNode);

		///��ȡָ���ӽڵ���ָ�����Լ�Ĺ�ϵӳ��ͼ
			///@param	mapDBConnect	���ڴ洢ӳ���ϵ��map����
			///@param	pszTagName	���ڱ�����Ϊ�ӽ��ؼ������Tag�ַ�ָ��
			///@param	pszKeyProp	������Ϊmap�ؼ���������Զ��ַ�ָ��
			///@param	pszPropName	��Ϊ�ؼ����������ַ�ָ��
			///@param	pszPropIP	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pszPropUser	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pszPropPswd	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pszPropEnv	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pNode	�����ָ����
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

		///��ȡָ���ӽڵ���ָ�����Լ�Ĺ�ϵӳ��ͼ
			///@param	mapDBConnect	���ڴ洢ӳ���ϵ��map����
			///@param	pszTagName	���ڱ�����Ϊ�ӽ��ؼ������Tag�ַ�ָ��
			///@param	pszKeyProp	������Ϊmap�ؼ���������Զ��ַ�ָ��
			///@param	pszPropName	��Ϊ�ؼ����������ַ�ָ��
			///@param	pszPropIP	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pszPropUser	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pszPropPswd	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pszPropEnv	��Ϊĳ�ض�ֵ���ַ�ָ��
			///@param	pNode	�����ָ����
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

		///��ȡĿ��ڵ���ָ�����Լ���ַ��͹�ϵӳ��ͼ
			///@param	dstMap	����ӳ���ϵ��map����
			///@param	pszKeyProp1	���ڱ�����Ϊ��Ҫ�ؼ�������������ַ�ָ��
			///@param	pszKeyProp2	���ڱ�����Ϊ��Ҫ�ؼ�������������ַ�ָ��
			///@param	pszValueProp	���ڱ�����Ϊֵ����������ַ�ָ��
			///@param	pNode	Ŀ��ڵ����ָ��
		static void getStringMap(
						map<string, string> &dstMap,
						char *pszKeyProp1,
						char *pszKeyProp2,
						char *pszValueProp,
						CXMLNode *pNode);

	/* */
	public:
		///���ڱ���System�����ļ���(��·��)
		char m_szSystemConfig[MAX_FILENAME_LEN];

		///���ڱ���Deploy�����ļ���(��·��)
		char m_szDeployConfig[MAX_FILENAME_LEN];

	/* */
	private:
		///���ڱ��������ļ�����·��
		char m_szPathName[MAX_FILENAME_LEN];

		///System�����ļ��ĵ�����ָ��
		CXMLDoc *m_pSystemCfgDoc;

		///Deploy�����ļ��ĵ�����ָ��
		CXMLDoc *m_pDeployCfgDoc;

		///System�����ļ����ڵ�ָ��
		CXMLNode *m_pSystemCfgRoot;

		///Deploy�����ļ����ڵ�ָ��
		CXMLNode *m_pDeployCfgRoot;
};
#endif // end of "#ifndef REF_XMLCFG_H"
