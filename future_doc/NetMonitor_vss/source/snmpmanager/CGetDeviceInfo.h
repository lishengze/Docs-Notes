/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CGetDeviceInfo.h
///@brief	定义了CGetDeviceInfo使用的类
///@history
///20100920	周建军		创建该文件
#ifndef REF_CGETDEVICEINFO_H
#define REF_CGETDEVICEINFO_H

#include "platform.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "net_snmp.h"
#include "CSnmpWrapper.h"

#include <string>
#include <list>
#include <map>
#include <iostream>
using namespace std;

#define TEST_COMM	"thbczh2005"

///WALK返回结果容器
typedef CDPWALK_RESULT	WALK_RESULT;

///CDPWALK返回结果迭代器
typedef WALK_RESULT::iterator WALK_RESULT_ITERATOR;

//端口状态：
struct ifstatus_stru
{
	long ifindex;
	long ifstatus;

	// -1——  unknown
	//  1——　up  (打开)
	//  2——　down(关闭)
};

struct ModuleValue
{
	int modIndex;
	int modState;
	int modNumPorts;
	string	modHwVersion;
	int modStandbyState;
	int modEntPhyIndex;
	string	modEntPhyDescr;
	string	modEntPhyFwRev;
	string	modEntPhySwRev;
	string	modEntPhySerialNum;
	string	modentPhyModelName;

	ModuleValue()
	{
		modIndex = modState = modNumPorts = modStandbyState = modEntPhyIndex = 0;
		modHwVersion = modEntPhyDescr = modEntPhyFwRev = modEntPhySwRev = modEntPhySerialNum = modentPhyModelName = "";
	}
};

struct TrunkValue
{
	int trunkPortEncapsulationType; //{isl(1),dot10(2),lane(3),dot1Q(4),negotiate(5)}
	int trunkPortNativeVlan;
	int trunkPortDynamicState;		//{on(1),off(2),desirable(3),auto(4),onNoNegotiate(5)}
	int trunkPortDynamicStatus;		//{trunking(1),notTrunking(2)}
	TrunkValue()
	{
		trunkPortEncapsulationType = trunkPortNativeVlan = trunkPortDynamicState = trunkPortDynamicStatus = 0;
	}
};

struct HsrpValue
{
	int cHsrpGrpNumber;
	int cHsrpGrpPriority;
	string	cHsrpGrpVirtualIpAddr;
	string	cHsrpGrpActiveRouter;
	string	cHsrpGrpStandbyRouter;
	int cHsrpGrpStandbyState;		//{initial(1),learn(2),listen(3),speak(4),standby(5),active(6)}
	HsrpValue()
	{
		cHsrpGrpNumber = cHsrpGrpPriority = cHsrpGrpStandbyState = 0;
		cHsrpGrpVirtualIpAddr = cHsrpGrpActiveRouter = cHsrpGrpStandbyRouter = "";
	}
};

struct StpValue
{
};

struct VtpValue
{
	int vtpVersion;
	int vtpMaxVlanStorage;
	string	manageDName;
	int manageDLocalMode;			//client(1),server(2),transparent(3),off(4)
	int manageDConfigRevNumber;
	string	manageDLastUpdater;
	string	manageDLastChange;
	int manageDPruningState;		//enable(1),disable(2)
	int manageDVersionInUse;		//version1(1),version2(2),none(3),version3(4)
	VtpValue()
	{
		vtpVersion = vtpMaxVlanStorage = manageDLocalMode =
			manageDConfigRevNumber = manageDPruningState =
				manageDVersionInUse = 0;
		manageDName = manageDLastUpdater = manageDLastChange = "";
	}
};

struct RouteValue
{
	int ipRouteIfIndex;
	int ipRouteType;				//{other(1),invalid(2),direct(3),indirect(4)}
	int ipRouteProto;				//{other(1),local(2),netmgmt(3),icmp(4),egp(5),ggp(6),hello(7),rip(8),is-is(9),

	//es-is(10),ciscoIgrp(11),bbnSpfIgp(12),ospf(13),bgp(14),idpr(15),ciscoEigrp(16)}
	string	ipRouteDest;
	string	ipRouteNextHop;
	string	ipRouteMask;

	RouteValue()
	{
		ipRouteIfIndex = ipRouteType = ipRouteProto = 0;
		ipRouteDest = ipRouteNextHop = ipRouteMask = "";
	}
};

struct ArpValue
{
	string	nsIpArpIp;
	string	nsIpArpMac;
	int nsIpArpVsys;
	int nsIpArpIfIdx;
	int nsIpArpState;				//{ INTEGER {pending(1),valid(2),delete(3),static(4)}
	ArpValue()
	{
		nsIpArpVsys = nsIpArpIfIdx = nsIpArpState = 0;
		nsIpArpIp = nsIpArpMac = "";
	}
};

class CCdpValue
{
	/* */
	public:
		///本地主机名
		string	mlocalhost;

		///本地端口号
		string	mlocalport;

		///对端主机名
		string	mdesthost;

		///对端端口号
		string	mdestport;

	/* */
	public:

		///构造函数
		CCdpValue(void)
		{
		}

		///构造函数
			///@param	monTime	监控指标的采集时间，time_t类型
			///@param	valueType	监控指标值的类型，不能为字符串
			///@param	pValue	监控指标的值
		CCdpValue(
		string	localhost,
		string	localport,
		string	desthost,
		string	destport)
		{
			mlocalhost = localhost;
			mlocalport = localport;
			mdesthost = desthost;
			mdestport = destport;
		}

		///拷贝构造函数
		CCdpValue(const CCdpValue &ob)
		{
			mlocalhost = ob.mlocalhost;
			mlocalport = ob.mlocalport;
			mdesthost = ob.mdesthost;
			mdestport = ob.mdestport;
		}

		///重载“=”运算符
		void operator=(const CCdpValue &ob)
		{
			mlocalhost = ob.mlocalhost;
			mlocalport = ob.mlocalport;
			mdesthost = ob.mdesthost;
			mdestport = ob.mdestport;
		}
};

struct SInfoOID
{
	const char	*Name;
	oid Oid[MAX_OID_LEN];
	size_t	OidLen;
	bool is_table;
};

class SInfoHost
{
	/* */
	public:
		SInfoHost(void)
		{
			//sess = NULL;
			current_oid = NULL;
			sysDescr = "";
			SysName = "";
			sysType = "";
			netName = "";
			cenName = "";
			manustr = "";
			serial = "";
			ifNum = 0;
			isablesnmp = false;
			mifDescr.clear();
			mListCdpValue.clear();
			m_ModValues.clear();
			mSnmpWrapper = NULL;
			ipforwarding = -1;
			sysServices = -1;
		}

		SInfoHost(char *ipname, char *comm, string net = "", string center = "")
		{
			strcpy(name, ipname);
			strcpy(community, comm);

			//sess = NULL;
			current_oid = NULL;
			sysDescr = "";
			SysName = "";
			sysType = "";
			netName = net;
			cenName = center;
			manustr = "";
			serial = "";
			ifNum = 0;
			isablesnmp = false;
			mifDescr.clear();
			mListCdpValue.clear();
			m_ModValues.clear();
			mSnmpWrapper = new CSnmpWrapper(community, name);
			ipforwarding = -1;
			sysServices = -1;
		}

		SInfoHost(const SInfoHost &ob)
		{
			strcpy(name, ob.name);
			strcpy(community, ob.community);

			//sess = ob.sess;
			current_oid = ob.current_oid;
			sysDescr = ob.sysDescr;
			SysName = ob.SysName;
			sysType = ob.sysType;
			netName = ob.netName;
			cenName = ob.cenName;
			manustr = ob.manustr;
			serial = ob.serial;
			ifNum = ob.ifNum;
			isablesnmp = ob.isablesnmp;
			mifDescr = ob.mifDescr;
			mListCdpValue = ob.mListCdpValue;
			m_ModValues = ob.m_ModValues;

			if (NULL == ob.mSnmpWrapper)
			{
				mSnmpWrapper = NULL;
			}
			else
			{
				mSnmpWrapper = new CSnmpWrapper(
						ob.mSnmpWrapper->get_community(),
						ob.mSnmpWrapper->get_peer_name());
			}

			ipforwarding = ob.ipforwarding;
			sysServices = ob.sysServices;
		}

		///重载“=”运算符
		SInfoHost &operator=(const SInfoHost &ob)
		{
			//避免自赋值
			if (this == &ob)
			{
				return *this;
			}

			strcpy(name, ob.name);
			strcpy(community, ob.community);

			//sess = ob.sess;
			current_oid = ob.current_oid;
			sysDescr = ob.sysDescr;
			SysName = ob.SysName;
			sysType = ob.sysType;
			netName = ob.netName;
			cenName = ob.cenName;
			manustr = ob.manustr;
			serial = ob.serial;
			ifNum = ob.ifNum;
			isablesnmp = ob.isablesnmp;
			mifDescr = ob.mifDescr;
			mListCdpValue = ob.mListCdpValue;
			m_ModValues = ob.m_ModValues;

			if (NULL == ob.mSnmpWrapper)
			{
				if (mSnmpWrapper)
				{
					delete mSnmpWrapper;
				}

				mSnmpWrapper = NULL;
			}
			else
			{
				if (mSnmpWrapper)
				{
					//exceptional safe
					CSnmpWrapper *pOri = mSnmpWrapper;
					mSnmpWrapper = new CSnmpWrapper(
							ob.mSnmpWrapper->get_community(),
							ob.mSnmpWrapper->get_peer_name());
					delete pOri;
				}
				else
				{
					mSnmpWrapper = new CSnmpWrapper(
							ob.mSnmpWrapper->get_community(),
							ob.mSnmpWrapper->get_peer_name());
				}
			}

			ipforwarding = ob.ipforwarding;
			sysServices = ob.sysServices;
		}

		~SInfoHost(void)
		{
			if (mSnmpWrapper)
			{
				delete mSnmpWrapper;
			}
		}

		char name[16];					//主机IP地址
		char community[32];				//通讯字

		//struct snmp_session *sess;	 /* SNMP session data */
		struct SInfoOID *current_oid;	/* How far in our poll are we */

		string	sysDescr;				//主机信息描述
		string	SysName;				//主机名
		string	sysType;				//主机设备类型,设置为描述信息的第一个空格之前字符串
		string	netName;
		string	cenName;
		string	manustr;
		string	serial;

		int ifNum;						//设备接口数
		bool isablesnmp;

		list<ifstatus_stru> mListifstatus;

		///@key	 接口索引，如20101
			///@value 接口名称，接口别名 如Ethernet0/1，E0/1.非cisco设备中接口别名为""
		map<string, pair<string,string> > mifDescr; 

		//cdp列表信息
		list<CCdpValue> mListCdpValue;

		//trunk信息
		map<int, TrunkValue> mTrunkMap;

		//vtp列表信息
		list<VtpValue>	mListVtpValue;

		///@key	 设备中模块索引，取模块信息时oid对应的最后一位叶子点的值
			///@value 模块对象
		map<string, ModuleValue> m_ModValues;
		CSnmpWrapper *mSnmpWrapper;		/* SNMP session */

		//请求oid值map
			///@key	 oid_name，如ipForwardng
			///@value oid_value对，如<"1.3.6...", "2">
		map<string, map<string, string> > moidsValues;

		int ipforwarding;
		int sysServices;
};

class CGetDeviceInfoThread :
	public CThread
{
	/* */
	public:

		///构造函数
			///@param	pHosts	指针数组第一个元素地址
			///@param	nArraySize	指针数组个数
		CGetDeviceInfoThread(
		SInfoHost *pHosts = NULL,
		int nArraySize = 0,
		int id = 0)
		{
			mpHosts = pHosts;
			mnArraySize = nArraySize;
			thread_id = id;
			m_dev_count = 0;
		}

		///析构函数
		~CGetDeviceInfoThread(void)
		{
			ExitThread();
		}

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

		/*
	* 重新初始化探测设备的信息，清除历史上探测结果
	*/
		void ReInitHostInfo(void)
		{
			m_active_hosts = 0;
			m_dev_count = 0;
			m_hosts.clear();
		}

		void addhosts(char *ipname, char *comm, string netarea)
		{
			string	center;
			string	net;
			if (netarea.size() > 2)
			{
				char buff[128];
				strcpy(buff, netarea.c_str());

				char *q = strchr(buff, '.');
				if (q != NULL)
				{
					*q = '\0';
				}
				else
				{
					printf("recv netarea format wrong [%s]\n", netarea.c_str());
					return;
				}

				center = buff;
				q++;

				char *p = strchr(q, '.');
				if (p != NULL)
				{
					*p = '\0';
				}

				net = q;
			}

			printf(
				" 0000000000000000000000 %s %s %s \n",
				netarea.c_str(),
				center.c_str(),
				net.c_str());
			m_hosts.push_back(SInfoHost(ipname, comm, net, center));
		}

		vector<SInfoHost> gethosts(void)
		{
			return m_hosts;
		}

	/* */
	private:
		/**获取设备host的cdplist，cisco private protocol
	*/
		void GetDeviceCdps(void);

		/**获取设备host的接口信息
	*/
		void GetDeviceInterface(void);

		/**获取设备host的module信息
	*/
		void GetDeviceModule(void);

		void GetDeviceModuleInfo(void);

		/** 取设备vtp信息.cisco private protocol
	*/
		void GetDeviceVtpInfo(void);

		/** 取设备trunk信息.
	*/
		void GetDeviceTrunkInfo(void);

		/** 取设备hsrp信息.
	*/
		void GetDeviceHsrpInfo(void);

		/** 取设备route信息.
	*/
		void GetDeviceRouteInfo(void);

		/** 取设备stp信息.
	*/
		void GetDeviceStpInfo(void);

		/**获取由配置中心指定的设备信息
	*/
		void GetDecDeviceInfo(SInfoHost *pHosts, int nArraySize);

		void DoAttemptSnmp(SInfoHost *pHosts, int nArraySize);

		void GetDeviceBaseInfo(SInfoHost *pHosts, int nArraySize);

		void ProcessDeviceBaseInfoResult(SInfoHost *pHosts, int nArraySize);

		void ParseAsyncResult(
				SInfoHost *pHost,
				string	key,
				SNMPRESULTDATA	data,
				int index);

		//格式化监控对象的名称，监控对象名中不能出现'.',' '特殊字符，首尾不能出现指定域名及空格.
		char *FormatMonitorObjectName(char *name);

	/* */
	public:
		vector<SInfoHost> m_hosts;	//本次扫描的主机列表。
		SInfoHost *mpHosts;
		int mnArraySize;

		///@key	 oid_name，如ipForwarding
			///@value SInfoOID对象
		map<string, SInfoOID> m_oids;

		//记录探测到活动的节点数
		int m_active_hosts;

		//统计探测到的设备数
		int m_dev_count;

		//记录线程编号
		int thread_id;
};
#endif
