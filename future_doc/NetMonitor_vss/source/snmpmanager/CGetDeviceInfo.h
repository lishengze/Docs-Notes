/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CGetDeviceInfo.h
///@brief	������CGetDeviceInfoʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
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

///WALK���ؽ������
typedef CDPWALK_RESULT	WALK_RESULT;

///CDPWALK���ؽ��������
typedef WALK_RESULT::iterator WALK_RESULT_ITERATOR;

//�˿�״̬��
struct ifstatus_stru
{
	long ifindex;
	long ifstatus;

	// -1����  unknown
	//  1������up  (��)
	//  2������down(�ر�)
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
		///����������
		string	mlocalhost;

		///���ض˿ں�
		string	mlocalport;

		///�Զ�������
		string	mdesthost;

		///�Զ˶˿ں�
		string	mdestport;

	/* */
	public:

		///���캯��
		CCdpValue(void)
		{
		}

		///���캯��
			///@param	monTime	���ָ��Ĳɼ�ʱ�䣬time_t����
			///@param	valueType	���ָ��ֵ�����ͣ�����Ϊ�ַ���
			///@param	pValue	���ָ���ֵ
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

		///�������캯��
		CCdpValue(const CCdpValue &ob)
		{
			mlocalhost = ob.mlocalhost;
			mlocalport = ob.mlocalport;
			mdesthost = ob.mdesthost;
			mdestport = ob.mdestport;
		}

		///���ء�=�������
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

		///���ء�=�������
		SInfoHost &operator=(const SInfoHost &ob)
		{
			//�����Ը�ֵ
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

		char name[16];					//����IP��ַ
		char community[32];				//ͨѶ��

		//struct snmp_session *sess;	 /* SNMP session data */
		struct SInfoOID *current_oid;	/* How far in our poll are we */

		string	sysDescr;				//������Ϣ����
		string	SysName;				//������
		string	sysType;				//�����豸����,����Ϊ������Ϣ�ĵ�һ���ո�֮ǰ�ַ���
		string	netName;
		string	cenName;
		string	manustr;
		string	serial;

		int ifNum;						//�豸�ӿ���
		bool isablesnmp;

		list<ifstatus_stru> mListifstatus;

		///@key	 �ӿ���������20101
			///@value �ӿ����ƣ��ӿڱ��� ��Ethernet0/1��E0/1.��cisco�豸�нӿڱ���Ϊ""
		map<string, pair<string,string> > mifDescr; 

		//cdp�б���Ϣ
		list<CCdpValue> mListCdpValue;

		//trunk��Ϣ
		map<int, TrunkValue> mTrunkMap;

		//vtp�б���Ϣ
		list<VtpValue>	mListVtpValue;

		///@key	 �豸��ģ��������ȡģ����Ϣʱoid��Ӧ�����һλҶ�ӵ��ֵ
			///@value ģ�����
		map<string, ModuleValue> m_ModValues;
		CSnmpWrapper *mSnmpWrapper;		/* SNMP session */

		//����oidֵmap
			///@key	 oid_name����ipForwardng
			///@value oid_value�ԣ���<"1.3.6...", "2">
		map<string, map<string, string> > moidsValues;

		int ipforwarding;
		int sysServices;
};

class CGetDeviceInfoThread :
	public CThread
{
	/* */
	public:

		///���캯��
			///@param	pHosts	ָ�������һ��Ԫ�ص�ַ
			///@param	nArraySize	ָ���������
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

		///��������
		~CGetDeviceInfoThread(void)
		{
			ExitThread();
		}

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

		/*
	* ���³�ʼ��̽���豸����Ϣ�������ʷ��̽����
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
		/**��ȡ�豸host��cdplist��cisco private protocol
	*/
		void GetDeviceCdps(void);

		/**��ȡ�豸host�Ľӿ���Ϣ
	*/
		void GetDeviceInterface(void);

		/**��ȡ�豸host��module��Ϣ
	*/
		void GetDeviceModule(void);

		void GetDeviceModuleInfo(void);

		/** ȡ�豸vtp��Ϣ.cisco private protocol
	*/
		void GetDeviceVtpInfo(void);

		/** ȡ�豸trunk��Ϣ.
	*/
		void GetDeviceTrunkInfo(void);

		/** ȡ�豸hsrp��Ϣ.
	*/
		void GetDeviceHsrpInfo(void);

		/** ȡ�豸route��Ϣ.
	*/
		void GetDeviceRouteInfo(void);

		/** ȡ�豸stp��Ϣ.
	*/
		void GetDeviceStpInfo(void);

		/**��ȡ����������ָ�����豸��Ϣ
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

		//��ʽ����ض�������ƣ���ض������в��ܳ���'.',' '�����ַ�����β���ܳ���ָ���������ո�.
		char *FormatMonitorObjectName(char *name);

	/* */
	public:
		vector<SInfoHost> m_hosts;	//����ɨ��������б�
		SInfoHost *mpHosts;
		int mnArraySize;

		///@key	 oid_name����ipForwarding
			///@value SInfoOID����
		map<string, SInfoOID> m_oids;

		//��¼̽�⵽��Ľڵ���
		int m_active_hosts;

		//ͳ��̽�⵽���豸��
		int m_dev_count;

		//��¼�̱߳��
		int thread_id;
};
#endif
