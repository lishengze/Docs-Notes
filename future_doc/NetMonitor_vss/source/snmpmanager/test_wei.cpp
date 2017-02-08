#include "version.h"
#include "public.h"
#include "Config.h"
#include "xmlcfg.h"

#include "ping_common.h"
#include "CSnmpManager.h"
#include "CSysLogReader.h"
#include "CSynConnector.h"
#include "CSysLogConfig.h"
#include "CConnTaskThread.h"

#define GEN_CONDITION_CODE(str)	  \
	else if (strstr(szInfo, str)) \
	{							  \
		paramMap[#str] = szBuf;	  \
	}

typedef struct
{
	char ip[100];
} IPStruct;

IPStruct iplist[] =
{
	"172.1.128.241",
	"172.1.128.242",
	"172.1.128.1",
	"172.1.128.2",
	"172.1.128.3",
	"172.1.128.4",
	"172.1.128.5",
	"172.1.128.6",
	"172.1.128.7",
	"172.1.128.61",
	"172.1.128.62",
	"172.1.128.63",
	"172.1.128.64",
	"172.1.128.65",
	"172.1.128.66",
	"172.1.128.67",
	"172.1.128.68",
	"172.1.128.69",
	"172.1.128.70",
	"172.1.128.71",
	"172.1.128.81",
	"172.1.128.82",
	"172.1.128.83",
	"172.1.128.99",
	"172.1.128.101",
	"172.1.128.102",
	"172.1.128.105",
	"172.1.128.106",
	"172.1.128.109",
	"172.1.128.110",
	"172.1.128.141",
	"172.1.128.142",
	"172.1.128.145",
	"172.1.128.146",
	"172.1.128.149",
	"172.1.128.150",
	"172.1.128.151",
	"172.1.128.152",
	"172.1.128.153",
	"172.1.128.154",
	"172.1.128.155",
	"172.1.128.156",
	"172.1.128.157",
	"172.1.128.158",
	"172.1.128.200",
	"172.1.128.202",
	"172.1.128.205",
	"172.1.128.207",
	"172.1.128.221",
	"172.1.128.222",
	"172.1.128.195",
	"172.1.128.196",
	""
};

/*
void test_regex()
{
	regex exp1("^CPU utilization for five seconds: ([0-9]*)%/([0-9]*)%; one minute: ([0-9]*)%; five minutes: ([0-9]*)%.*$");//CPU
	regex exp2("^[ \t]*.*Pool Total:[ ]*([0-9]+) Used:[ ]*([0-9]+) Free:[ ]*([0-9]+)$");  //MEMORY
	regex exp3("^.*Port ID[\r\n]*(.*)$", match_single_line);  //CDP NEI 1
	regex exp4("^([^ \t\r\n]*)[ \t\r\n]*([^ ]*)[ ]*([0-9/]*)[ ]*([0-9]*)[ ]*([R|S|I][ ])*[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ \r\n]*)(.*)$");//(([RSI][ ])*)[ ]*(^ )*[ ]*(^ )*[ ]*(^ )*$");  //CDP NEI 2
	regex exp5("^.*Interface[\r\n]*(.*)$", match_single_line);//OSPF NEI 1
	regex exp6("^([^ ]*)[ ]*([0-9]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*(.*)$");//OSPF NEI 2
	regex exp7("^.*------[\r\n]*(.*)$", match_single_line);  //VLAN 1
	regex exp8("^([0-9]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*(.*)$"); //VLAN 2
	regex exp9("^.*Virtual IP[\r\n]*(.*)$", match_single_line); //STAND BY 1
	regex exp10("^([^ ]*)[ ]*([0-9]*)[ ]*([0-9]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*(.*)$"); //STAND BY 2
	regex exp11("^(Clock is synchronized).*$"); //ntp status
	regex exp12(".*(crash).*", regex::icase);  //boot flash
	regex exp13("^.*Protocol[\r\n]*(.*)$", match_single_line);  //ip int brief 1
	regex exp14("^([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]([^ ]*)[ ]*([^ \t]*).*$"); //ip int brief 2
	regex exp15("^([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ \t]*).*$");  //ip int brief 3
	regex exp16("^([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*(.*)$"); //int status
	regex exp17("^.*enabled protocol ([^ \r\n]*).*Root ID.*Address[ ]*([^ \r\n]*).*Bridge ID.*Address[ ]*([^ \r\n]*).*-----\r\n(.*)$", match_single_line); //spann_vlan
	regex exp18("^.*Success rate is ([0-9]*).*min/avg/max = ([0-9]*)/([0-9]*)/([0-9]*).*$");  //ping
	regex exp19("^.*Cells St[\r\n]*(.*)$", match_single_line); //atm pvc 1
	regex exp20("^[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*([^ ]*).*$"); //atm pvc 2
	regex exp21("^([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*[^ \r\n]*[ \r\n]*(.*)$");

	std::string in1 = "CPU utilization for five seconds: 0%/0%; one minute: 1%; five minutes: 1%\r\n\
					  PID Runtime(ms)   Invoked      uSecs   5Sec   1Min   5Min TTY Process \r\n\
					  1          17       231         73  0.00%  0.00%  0.00%   0 Chunk Manager    \r\n\
					  2         960   1547627          0  0.00%  0.00%  0.00%   0 Load Meter       \r\n\
					  3           0         1          0  0.00%  0.00%  0.00%   0 CEF RP IPC Backg \r\n\
					  4     6611778    917322       7207  0.00%  0.05%  0.05%   0 Check heaps      \r\n\
					  5          25        37        675  0.00%  0.00%  0.00%   0 Pool Manager     \r\n\
					  6           0         2          0  0.00%  0.00%  0.00%   0 Timers           \r\n\
					  7           0        43          0  0.00%  0.00%  0.00%   0 Net Input        \r\n\
					  8           0         1          0  0.00%  0.00%  0.00%   0 Crash writer     \r\n\
					  9     2582881  10817524        238  0.00%  0.14%  0.14%   0 ARP Input        ";
	std::string in2 = "Processor Pool Total:  378228080 Used:  130288836 Free:  247939244";
	std::string in3 = "Capability Codes: R - Router, T - Trans Bridge, B - Source Route Bridge\r\n\
                  S - Switch, H - Host, I - IGMP, r - Repeater, P - Phone\r\n\
\r\n\
Device ID        Local Intrfce     Holdtme    Capability  Platform  Port ID\r\n\
PD-JY7606GG-C2-4N105.shfe.com.cn\r\n\
                 Gig 2/2           126          R S I     CISCO7606 Gig 2/2\r\n\
PD-JY7606GG-C2-4N105.shfe.com.cn\r\n\
                 Gig 2/1           175          R S I     CISCO7606 Gig 2/1\r\n\
PD-WG3750-C4-4N101.shfe.com.cn\r\n\
                 Gig 2/24          137          R S I     WS-C3750G Gig 1/0/16\r\n\
PD-JY7606WL-C1-4N106.shfe.com.cn\r\n\
                 Gig 6/1           149          R S I     CISCO7606 Gig 6/1\r\n\
PD-JY7606WL-C1-4N106.shfe.com.cn\r\n\
                 Gig 5/1           149          R S I     CISCO7606 Gig 5/1";
	std::string in4 = "PD-JY7606GG-C2-4N105.shfe.com.cn\r\n\
		Gig 2/2           126          R S I     CISCO7606 Gig 2/2\r\n\
		PD-JY7606GG-C2-4N105.shfe.com.cn\r\n\
		Gig 2/1           175          R S I     CISCO7606 Gig 2/1";
	std::string in5 = " \r\n\
\
		Neighbor ID     Pri   State           Dead Time   Address         Interface\r\n\
		10.32.255.8     255   FULL/DR         00:00:38    10.33.254.254   GigabitEthernet1/0/50\r\n\
		10.32.255.113     1   2WAY/DROTHER    00:00:35    10.33.254.113   GigabitEthernet1/0/50";

	std::string in6 = "10.32.255.113     1   2WAY/DROTHER    00:00:35    10.33.254.113   GigabitEthernet1/0/50";
	std::string in7 = "\r\n\
		VLAN Name                             Status    Ports\r\n\
		---- -------------------------------- --------- -------------------------------\r\n\
		1    default                          active    \r\n\
		2    MGT                              active    Gi4/24\r\n\
		17   RSPAN_CWJY_B4.2                  active    \r\n\
		110  JY_B4.2                          active    Gi4/1, Gi4/2\r\n\
		700  PD-JY6504A12_To_PD-JY2000B12     active    Gi1/2, Gi2/2\r\n\
		1002 fddi-default                     act/unsup \r\n\
		1003 token-ring-default               act/unsup \r\n\
		1004 fddinet-default                  act/unsup \r\n\
		1005 trnet-default                    act/unsup ";
	std::string in8 = "1    default                          active    \r\n";
	std::string in9 = "                     P indicates configured to preempt.\r\n\
		|\r\n\
		Interface   Grp Prio P State    Active          Standby         Virtual IP     \r\n\
		Vl110       11  80   P Standby  192.168.11.252  local           192.168.11.24  \r\n\
		Vl700       70  80   P Standby  10.32.252.66    local           10.32.252.65";
	std::string in10 = "Vl110       11  80   P Standby  192.168.11.252  local           192.168.11.24  ";
	std::string in11 = "Clock is synchronized, stratum 2, reference is 172.1.0.51\r\n\
		nominal freq is 250.0000 Hz, actual freq is 250.0016 Hz, precision is 2**18\r\n\
		reference time is D1E0D808.7EEB481B (15:45:12.495 BJ Mon Aug 1 2011)\r\n\
		clock offset is 0.0868 msec, root delay is 0.73 msec\r\n\
		root dispersion is 2.99 msec, peer dispersion is 0.14 msec";
	std::string in12 = "123crAsHsdfsdfs";
	std::string in13 = "Interface              IP-Address      OK? Method Status                Protocol\r\n\
		GigabitEthernet1/1     unassigned      YES unset  up                    up      \r\n\
		GigabitEthernet1/2     unassigned      YES unset  up                    up ";
	std::string in14 = "GigabitEthernet4/3     unassigned      YES TFTP   administratively down down  ";
	std::string in15 = "GigabitEthernet4/23    unassigned      YES unset  up                    up  ";
	std::string in16 = "Gi4/24       To_PD-WG4948-C5-4N connected    2            full   1000 1000BaseT";
	std::string in17 = "\r\n\
		VLAN0110\r\n\
		Spanning tree enabled protocol ieee\r\n\
		Root ID    Priority    8302\r\n\
		Address     68ef.bdeb.d680\r\n\
		Cost        3\r\n\
		Port        1665 (Port-channel1)\r\n\
		Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
\r\n\
		Bridge ID  Priority    16494  (priority 16384 sys-id-ext 110)\r\n\
		Address     68ef.bdeb.d600\r\n\
		Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
		Aging Time 300\r\n\
\r\n\
		Interface           Role Sts Cost      Prio.Nbr Type\r\n\
		------------------- ---- --- --------- -------- --------------------------------\r\n\
		Gi4/2               Desg FWD 4         128.386  P2p \r\n\
		Po1                 Root FWD 3         128.1665 P2p";
	std::string in18 = "\r\n\
		Type escape sequence to abort.\r\n\
		Sending 1000, 100-byte ICMP Echos to 172.1.128.1, timeout is 2 seconds:\r\n\
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!\r\n\
		Success rate is 99 percent (999/1000), round-trip min/avg/max = 1/3/25 ms";
	std::string in19 = "           VCD /                                            Peak Av/Min Burst\r\n\
		Interface  Name         VPI   VCI Type    Encaps     SC     Kbps   Kbps Cells St\r\n\
		1/0/0.100  1              6   100 PVC     SNAP       CBR   50000              UP\r\n\
		1/0/0.101  2              6   101 PVC     SNAP       CBR   30000              UP";
	std::string in20 = "1/0/0.100  1              6   100 PVC     SNAP       CBR   50000              UP";
	std::string in21 = "GigabitEthernet0/1/1   172.16.224.194  YES NVRAM  up                    up      \r\n\
		GigabitEthernet0/1/2   unassigned      YES NVRAM  administratively down down    ";

	cmatch what;

	while(1)
	{
		std::string in;
		cout << "1 CPU\r\n2 MEMORY\r\n3 CDP NEIGHBOUR 1\r\n4 CDP NEIGHBOUR 2\r\n5 OSPF NEIGHBOUR 1\r\n\
6 OSPF NEIGHBOUR 2\r\n7 VLAN 1\r\n8 VLAN 2\r\n9 STAND BY 1\r\n10 STAND BY 2\r\n11 ntp status\r\n12 boot flash\r\n\
13 ip int brief 1\r\n14 ip int brief 2\r\n15 ip int brief 2\r\n16 interface status\r\n17 spann_vlan\r\n\
18 ping\r\n19 atm pvc 1\r\n20 atm pvc 2\r\nenter select:"<<endl;
		getline(cin,in);

		regex expression;

		switch(atoi(in.c_str()))
		{
		case 1:
			in = in1;
			expression = exp1;
			break;
		case 2:
			in = in2;
			expression = exp2;
			break;
		case 3:
			in = in3;
			expression = exp3;
			break;
		case 4:
			in = in4;
			expression = exp4;
			break;
		case 5:
			in = in5;
			expression = exp5;
			break;
		case 6:
			in = in6;
			expression = exp6;
			break;
		case 7:
			in = in7;
			expression = exp7;
			break;
		case 8:
			in = in8;
			expression = exp8;
			break;
		case 9:
			in = in9;
			expression = exp9;
			break;
		case 10:
			in = in10;
			expression = exp10;
			break;
		case 11:
			in = in11;
			expression = exp11;
			break;
		case 12:
			in = in12;
			expression = exp12;
			break;
		case 13:
			in = in13;
			expression = exp13;
			break;
		case 14:
			in = in14;
			expression = exp14;
			break;
		case 15:
			in = in15;
			expression = exp15;
			break;
		case 16:
			in = in16;
			expression = exp16;
			break;
		case 17:
			in = in17;
			expression = exp17;
			break;
		case 18:
			in = in18;
			expression = exp18;
			break;
		case 19:
			in = in19;
			expression = exp19;
			break;
		case 20:
			in = in20;
			expression = exp20;
			break;
		case 21:
			in = in21;
			expression = exp21;
			break;
		default:
			return;
		}

		cout<<"ori str:"<<endl<<in<<endl;

		if(regex_match(in.c_str(), what, expression))
		{
			  for(int i=1;i<what.size();i++)
					cout<<"match str:\n"<<what[i].str()<<" size="<<what[i].length()<<endl;
		}
		else
		{
		   cout<<"Error Input"<<endl;
		}
	}
}
*/
void test_syslog_parse(void)
{
	std::string filename = "snmpmanager.xml";
	if (CSysLogConfigManager::Instance()->LoadConfig(filename.c_str()) != 0)
	{
		printf("LoadConfig fail for %s\n", filename.c_str());
		return;
	}

	CSysLogConfigManager::Instance()->DumpConfig();

	if (CSysLogConfigManager::Instance()->ReloadConfig() != 0)
	{
		printf("ReloadConfig fail!\n");
		return;
	}

	//printf("condition size=%d\n", CSysLogConfigManager::Instance()->m_lConfigInfoList.size());
	//	CSysLogReader syslogReader("syslog.log");
	CSysLogReader syslogReader("C:\\sfit\\logfile\\ncolog.20110613");
	syslogReader.Create();

	syslogReader.Join();
}

void test_thread_ping(void)
{
	/*
	u_long start,val;
	u_long thr_num = 0;
	getip(start, val, "172.1.128.0" ,"255.255.255.0" );
	int count = val;
	thr_num = count/50;
	CWorkThread *workthr[20];
	std::list<std::string> ips_str;
	std::list<std::string> ips[20];

	for( int i = 0; i < 20; i++ )
	{
	      if( i < thr_num-1 )
	      {
	              workthr[i] = new CWorkThread( );
	              workthr[i]->setParas(&ips[i],start,50);
	              workthr[i]->Create();
	              start += 50;
	      }
	      else if( i == thr_num - 1 )
	      {
	              workthr[i] = new CWorkThread( );
	              workthr[i]->setParas(&ips[i],start,count-(i*50));
	              workthr[i]->Create();
	      }
	      else
	      {
	              workthr[i] = NULL;
	      }
	}


	for( int i = 0; i < thr_num; i++ )
	{
	      printf("wait for the work thread handle=[%d],id=[%d] doing ping.\n",workthr[i]->GetHandle(), i);
	      WaitForObject(workthr[i]->GetHandle());
	      printf("work thread  id=[%d] had done ping.\n", i);
	      ips_str.insert( ips_str.end(),ips[i].begin(), ips[i].end() );
	}	
*/
}

void test_snmp_get(void)
{
	CSnmpWrapper snmpwrapper("thbczh2005", "172.1.33.15");

	if (!snmpwrapper.open_session())
	{
		return;
	}

	CDPWALK_RESULT	walk_result;
	int atparam;
	if (SNMP_ERROR_SUCCESS != snmpwrapper.send_sync_walk_request(
			"1.3.6.1.4.1.9.5.1.3.1.1.1",
		walk_result))
	{
		return;
	}

	/*
	if(SNMP_ERROR_SUCCESS != snmpwrapper.send_async_walk_request("1.3.6.1.4.1.9.5.1.3.1.1.1"))
	{
		return ;
	}	
*/
	//接收数据
	snmpwrapper.recv_async_response();

	while (1)
	{
		//还没任何结果
		if (snmpwrapper.is_walk_map_empty()
		&&	snmpwrapper.is_timeout_event_empty()
		&&	snmpwrapper.is_error_event_empty())
		{
			continue;
		}

		if (!snmpwrapper.is_walk_map_empty())
		{
			//process data event
			std::string key;
			DATAMAP datamap;

			if (snmpwrapper.pop_one_walk_data(key, datamap) != 0)
			{
				printf(
					"walkdatamap not empty but pop nothing in %s\n",
					__FUNCTION__);
			}
			else
			{
				int index = 0;
				for (DATAMAPITERATOR it = datamap.begin();
					 it != datamap.end();
					 ++it)
				{
					printf(
						"key=%s type=%d, value=%s\n",
						it->first.c_str(),
						it->second.datatype,
						it->second.datavalue.c_str());
				}
			}
		}
		else if (!snmpwrapper.is_timeout_event_empty())
		{
			//process timeout event
			std::string timeoutkey;
			time_t	happentime;
			if (snmpwrapper.pop_timeout_event(timeoutkey, happentime) != 0)
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walktimeoutmap not empty but pop nothing in %s\n",
					__FUNCTION__);
#endif
			}
			else
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walkdatamap timeout in %s for oid:%s\n",
					__FUNCTION__,
					timeoutkey.c_str());
#endif
			}
		}
		else
		{
			//process error event
			std::string errorkey;
			std::string errormsg;
			if (snmpwrapper.pop_error_event(errorkey, errormsg) != 0)
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walkerrormap not empty but pop nothing in %s\n",
					__FUNCTION__);
#endif
			}
			else
			{
#ifdef PACKAGE_OUTPUT
				printf(
					"walkdatamap error in %s for oid:%s, msg:%s\n",
					__FUNCTION__,
					errorkey.c_str(),
					errormsg.c_str());
#endif
			}
		}

		break;
	}

	/*
	#define THREAD_NUM 1
	CGetDeviceInfoThread * m_pinfoThread[THREAD_NUM];

	for(int i = 0; i < THREAD_NUM; ++i)
	{
		m_pinfoThread[i] = new CGetDeviceInfoThread();
	}
	
	int index = 0;
	while(strcmp(iplist[index].ip,"") != 0)
	{
		m_pinfoThread[index%THREAD_NUM]->addhosts(iplist[index].ip,"thbczh2005", "");
		index++;
	}

	//m_pinfoThread->addhosts("172.1.128.1","thbczh2005", "");
	//m_pinfoThread->addhosts("172.1.128.2","thbczh2005", "");
	//m_pinfoThread->addhosts("172.1.128.3","thbczh2005", "");
	//m_pinfoThread->addhosts("172.1.128.4","thbczh2005", "");	
	//m_pinfoThread->addhosts("172.1.128.5","thbczh2005", "");
	//m_pinfoThread->addhosts("172.1.128.6","thbczh2005", "");
	//m_pinfoThread->addhosts("172.1.128.7","thbczh2005", "");

	for(int i = 0; i < THREAD_NUM; ++i)
	{
		m_pinfoThread[i]->Create();
	}

	for(int i = 0; i < THREAD_NUM; ++i)
	{
		m_pinfoThread[i]->Join();
		printf("thread %d end\n", i);
		delete m_pinfoThread[i];
	}
*/
}

void test_syslog_classify(void)
{
	/*	g_pSyslogReader = new CSysLogReader("C:\\sfit\\logfile\\ncolog.20110613");
	g_pSyslogReader->Create();

	g_pSyslogReader->Join();

*/
	FILE *fp = fopen("C:\\sfit\\logfile\\ncolog.20110611", "rb");
	if (!fp)
	{
		printf("Can't open file!\n");
		return;
	}

	std::map<std::string, std::string>	paramMap;

	char szBuf[4096] = { 0 };
	while ((fgets(szBuf, sizeof(szBuf) - 1, fp)) != NULL)
	{
		int iYear, iMonth,
				iDay,
				iHour,
				iMinite,
				iSecond;
		char szMonth[16], szDay[16],
						szTime[16],
						szHostname[64],
						szInfo[4096];

		int iRtn = sscanf(
				szBuf,
				"%[A-Za-z] %[0-9] %[0-9:] %s %[^\n]\n",
				szMonth,
				szDay,
				szTime,
				szHostname,
				szInfo);
		if (iRtn == 5)
		{
			char ip0[16], ip1[16],
						ip2[16],
						ip3[16];
			int iRtn = sscanf(
					szHostname,
					"%[1-9].%[0-9].%[0-9].%[0-9]\n",
					ip0,
					ip1,
					ip2,
					ip3);
			if (iRtn == 4)
			{
				//拆分日志信息
				int curindex = 0;
				int seglen = 0; //分隔段的长度
				int count = 0;
				std::map<int, std::string>	seginfo;
				std::string strInfo = szInfo;

				//printf("strInfo:%s\n",strInfo.c_str());
				while (strInfo[curindex] != '\0')
				{
					if (strInfo[curindex] == ' '
					&&	strInfo[curindex + 1] != ' ')
					{
						seginfo[count] = strInfo.substr(
								curindex - seglen,
								seglen);

						curindex++;
						count++;
						seglen = 0;

						if (strInfo[curindex] == '\0')
						{
							break;
						}
					}

					seglen++;
					curindex++;
				}

				if (seginfo.find(6) != seginfo.end())
				{
					if (seginfo[6][0] == '%')
					{
						paramMap[seginfo[6]] = szInfo;
					}
				}
			}

			char szBuf0[1000];
			char szBuf1[1000];
			char szBuf2[1000];
			char szBuf3[1000];
			char szBuf4[1000];
			char szBuf5[1000];
			char szBuf6[1000];
			char szBuf7[1000];
			char szBuf8[1000];
			char szBuf9[1000];

			/*			if (strcmp(szHostname, "q-ncos2") == 0 ||strcmp(szHostname, "q-ncos1") == 0|| strcmp(szHostname, "Q-NCOS1") == 0)
			{
				iRtn = sscanf(szInfo, "%s %s %s %s %s %s %s %s %s %[^\n]\n",szBuf0, szBuf1, szBuf2, szBuf3, szBuf4, szBuf5, szBuf6, szBuf7, szBuf8, szBuf9);
				if(iRtn == 10)
				{
					if(strcmp(szBuf0, "Enms") == 0)
					{
						if(strstr(szBuf8, "GigabitEthernet"))
						{
							paramMap["GigabitEthernet"] = szBuf;
						}
						else if(strstr(szBuf8, "Serial"))
						{
							paramMap["Serial"] = szBuf;
						}
						else if(strstr(szBuf8, "System clock updated"))
						{
							paramMap["System clock updated"] = szBuf;
						}
						else
						{
							std::string paramstr = szBuf7;
							paramstr += " ";
							paramstr += szBuf8;
							paramMap[paramstr] = szBuf;
						}
					}
					else if(strstr(szBuf0, "sendmail"))
					{
						paramMap["sendmail"] = szBuf;
					}
					else
					{
						paramMap[szInfo] = szBuf;
					}
				}
				else
				{
					if(strstr(szBuf0, "crond"))
					{
						paramMap["crond"] = szBuf;
					}
					else if(strcmp(szBuf0, "0") == 0 && strcmp(szBuf1, "UA") == 0)
					{
						paramMap["UA"] = szBuf;
					}
					else if(strstr(szBuf0, "sendmail"))
					{
						paramMap["sendmail"] = szBuf;
					}
					else
					{
						paramMap[szInfo] = szBuf;
					}
				}
			}
			GEN_CONDITION_CODE("System clock updated")
			GEN_CONDITION_CODE("flapping between port")
			GEN_CONDITION_CODE("Sticky ARP")
			GEN_CONDITION_CODE("NetScreen device_id=")
			GEN_CONDITION_CODE("changed state to up")
			GEN_CONDITION_CODE("changed state to down")
			GEN_CONDITION_CODE("monitor status up")
			GEN_CONDITION_CODE("monitor status down")
			GEN_CONDITION_CODE("disconnected from")
			GEN_CONDITION_CODE("connected to")
			GEN_CONDITION_CODE("IN-INTERNET-NEW")
			GEN_CONDITION_CODE("has invalid spi for")
			GEN_CONDITION_CODE("Neighbor Down")
			GEN_CONDITION_CODE("LOADING to FULL")
			GEN_CONDITION_CODE("started - CLI initiated")
			GEN_CONDITION_CODE("started - reconnection")
			GEN_CONDITION_CODE("No members available for pool")
			GEN_CONDITION_CODE("reached its maximum threshold")
			else
			{
				char szzBuf0[100], szzBuf1[100], szzBuf2[100]; 

				int iRtn = sscanf(szInfo, "%s %s %s\n",szzBuf0, szzBuf1, szzBuf2);
				if (iRtn == 1)
				{
					paramMap["few params"] = szBuf;
				}
				else
				{
					paramMap[szBuf] = szBuf;

				}
			}
			//printf("%s %s\n", szBuf7, szBuf8);*/
		}

		memset(szBuf, 0x00, sizeof(szBuf));
	}

	printf("paramMap size = %d\n", paramMap.size());

	FILE *fpWrite = fopen("C:\\sfit\\logfile\\ncolog_result.20110614", "w");
	if (fpWrite)
	{
		for (std::map < std::string, std::string >::iterator it = paramMap.
				 begin();
		 it != paramMap.end();
			 ++it)
		{
			fwrite(it->second.c_str(), it->second.length(), 1, fpWrite);
			fputc('\r', fpWrite);
		}

		fclose(fpWrite);
	}
	else
	{
		printf("write file open fail!\n");
	}

	printf("parse over!\n");

	fclose(fp);
}

/*
void test_regex_match()
{
	//加载正则表达式过滤信息的配置文件
	if(CRegexConfigManager::Instance()->LoadConfig("snmpmanager.regex") != 0)
	{
		printf("LoadConfig faile for snmpmanager.regex\n");
		return;
	}

	CRegexConfigManager::Instance()->DumpConfig();

	CConnTaskThread testthread(1);
	
//	testthread.ParseCommandResult("show proc cpu | include CPU utilization", "CPU utilization for five seconds: 1%/0%; one minute: 1%; five minutes: 5%", "123","127.0.0.1");
	testthread.ParseCommandResult("show cdp neighbor", "Capability Codes: R - Router, T - Trans Bridge, B - Source Route Bridge\r\n\
		S - Switch, H - Host, I - IGMP, r - Repeater, P - Phone\r\n\
\r\n\
Device ID        Local Intrfce     Holdtme    Capability  Platform  Port ID\r\n\
PD-JY7606GG-C2-4N105.shfe.com.cn\r\n\
Gig 2/2           126          R S I     CISCO7606 Gig 2/2\r\n\
PD-JY7606GG-C2-4N105.shfe.com.cn\r\n\
Gig 2/1           175          R S I     CISCO7606 Gig 2/1\r\n\
PD-WG3750-C4-4N101.shfe.com.cn\r\n\
Gig 2/24          137          R S I     WS-C3750G Gig 1/0/16\r\n\
PD-JY7606WL-C1-4N106.shfe.com.cn\r\n\
Gig 6/1           149          R S I     CISCO7606 Gig 6/1\r\n\
PD-JY7606WL-C1-4N106.shfe.com.cn\r\n\
Gig 5/1           149          R S I     CISCO7606 Gig 5/1", "123", "127.0.0.1");
	testthread.ParseCommandResult("show ntp status", "222Clock is synchronized, stratum 2, reference is 172.1.0.51\r\n\
		nominal freq is 250.0000 Hz, actual freq is 250.0016 Hz, precision is 2**18\r\n\
		reference time is D1E0D808.7EEB481B (15:45:12.495 BJ Mon Aug 1 2011)\r\n\
		clock offset is 0.0868 msec, root delay is 0.73 msec\r\n\
		root dispersion is 2.99 msec, peer dispersion is 0.14 msec", "123", "127.0.0.1");
}
*/
int ssh_count;

class CSSHThread :
	public CThread
{
	/* */
	public:
		CSSHThread(string ip) :
		hostip(ip)
		{
		};
		virtual void Run(void)
		{
			while (1)
			{
				CTelnetClient m_oTelnetClient;

				m_oTelnetClient.TTYLock();

				CTelnetConnEntry entry = CTelnetConnEntry(
						hostip.c_str(),
						0,
						ssh,
						"rsfw",
						"niuRenyg",
						"pdxqpdl5005F",
						"term length 0;show running-config");

				CTelnetConnEntry entry_f5 = CTelnetConnEntry(
						hostip.c_str(),
						0,
						ssh,
						"admin",
						"netscreen",
						"pdxqpdl5005F",
						"set page 0;get config");

				// 初始化任务的采集对象
				m_oTelnetClient.Init(entry);

				// 重置输出文件目录
				m_oTelnetClient.SetOutputPath(TMP_DIRNAME);

				// 进行一次任务执行
				int ret = m_oTelnetClient.DoTask();
				if (ret != 0)
				{
					printf(
						"task exec fail, ip:%s, ret=%d\n",
						hostip.c_str(),
						ret);
				}
				else
				{
					printf(
						"task count:%d, ip:%s\n",
						++ssh_count,
						hostip.c_str());
				}

				m_oTelnetClient.TTYUnLock();

				OSSleep(3);
			}
		}

	/* */
	public:
		string hostip;
};

void test_ssh(void)
{
	ssh_init();

#define THREAD_NUM	1
	CSSHThread	*m_pSSHThread[THREAD_NUM];
	ssh_count = 0;

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		char ipstr[20];
		sprintf(ipstr, "172.1.128.%d", i + 61);
		m_pSSHThread[i] = new CSSHThread(ipstr);
	}

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		m_pSSHThread[i]->Create();
	}

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		m_pSSHThread[i]->Join();
		printf("thread %d end\n", i);
		delete m_pSSHThread[i];
	}

	ssh_finalize();
}

/*
void ParseShowIPInterfaceResult(cmatch what, string objectid, string curdate, string curtime, string deviceip)
{
	string interface_id = what[1].str();
								
	char *p = NULL;
	while((p= strchr((char *)interface_id.c_str(),'.') )!= NULL)
	{
		*p = '_';
	}
	
	string status = what[2].str();
	string protocol = what[3].str();

	string attrvalue;
	
	string eventname = "";
	string eventlevel;
	string eventinfo;

	if(status.compare("up") == 0)
	{
		if(protocol.compare("up") == 0)
		{
			attrvalue = "0";
		}
		else if(protocol.compare("down") == 0)
		{
			attrvalue = "2";
		}
		else
		{
			printf("invalid protocol:%s for show ip interface brief\n", protocol.c_str());
			return;
		}
	}
	else if(status.compare("down") == 0)
	{
		attrvalue = "1";
		
		eventname = "LINK_UPDOWN";
		eventlevel = "Level2";
		
		eventinfo = "Interface ";
		eventinfo += interface_id;
		eventinfo += ", changed state to down";
	}
	else if(status.compare("administratively") == 0)
	{
		attrvalue = "3";
		
		eventname = "LINKADMIN_UPDOWN";
		eventlevel = "Level4";
		
		eventinfo = "Interface ";
		eventinfo += interface_id;
		eventinfo += ", changed state to down";
	}
	else
	{
		printf("invalid status:%s for show ip interface brief\n", status.c_str());
		return;
	}
	
	CFTDRtnObjectAttrField fieldinfo;

	memset(&fieldinfo, 0, sizeof(CFTDRtnObjectAttrField));

	//generate attr value
	string total_id = objectid;
	total_id += ".";
	total_id += interface_id;

	fieldinfo.ObjectID = total_id.c_str();
	fieldinfo.MonDate = curdate.c_str();
	fieldinfo.MonTime = curtime.c_str();
	fieldinfo.AttrType = "interfaceStatus";

	fieldinfo.ValueType = INT_ATTR;
	fieldinfo.AttrValue = attrvalue.c_str();

	printf("$$$$$$$$$$$$$generate 11111 attrname:%s, attrvalue:%s, total_id:%s\n"
		, fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue(), total_id.c_str());
	//m_listObjectAttr.add(fieldinfo);

	//generate warning event according to "status"
	if(eventname.length() > 0)
	{
		CFTDRtnWarningEventField warninglogEvent;

		memset(&warninglogEvent, 0, sizeof(CFTDRtnWarningEventField));

		warninglogEvent.ObjectID = total_id.c_str();
		warninglogEvent.MonDate = curdate.c_str();
		warninglogEvent.MonTime = curtime.c_str();

		warninglogEvent.OccurDate = curdate.c_str();
		warninglogEvent.OccurTime = curtime.c_str();
		
		warninglogEvent.EventName = eventname.c_str();		

		warninglogEvent.EventType = "1";
		warninglogEvent.WarningLevel = eventlevel.c_str();
		
		warninglogEvent.EventDes = eventinfo.c_str();
		warninglogEvent.ProcessFlag = "N";
		warninglogEvent.IPAddress = deviceip.c_str();

		//m_listWarningEvent.add(warninglogEvent);
	}

	//generate warning event according to "proto"
	if(protocol.compare("down") == 0)
	{
		eventname = "LINEPROTO_UPDOWN";
		eventlevel = "Level3";
		
		eventinfo = "Line protocol on Interface ";
		eventinfo += interface_id;
		eventinfo += ", changed state to down";

		CFTDRtnWarningEventField warninglogEvent;

		memset(&warninglogEvent, 0, sizeof(CFTDRtnWarningEventField));

		warninglogEvent.ObjectID = total_id.c_str();
		warninglogEvent.MonDate = curdate.c_str();
		warninglogEvent.MonTime = curtime.c_str();

		warninglogEvent.OccurDate = curdate.c_str();
		warninglogEvent.OccurTime = curtime.c_str();
		
		warninglogEvent.EventName = eventname.c_str();		

		warninglogEvent.EventType = "1";
		warninglogEvent.WarningLevel = eventlevel.c_str();
		
		warninglogEvent.EventDes = eventinfo.c_str();
		warninglogEvent.ProcessFlag = "N";
		warninglogEvent.IPAddress = deviceip.c_str();

		//m_listWarningEvent.add(warninglogEvent);		
	}
}

void ParseCommandResult(string command, string result, string objectid, string deviceip)
{
	time_t timep;

	time(&timep);
	struct tm *curTime=localtime(&timep);

	char curTimeStr[10];
	char curDateStr[10];

	strftime(curTimeStr,10, "%H:%M:%S", curTime);
	strftime(curDateStr,10, "%Y%m%d"  , curTime);

	map<string, vector<CRegexNode> >::iterator r_i = CRegexConfigManager::Instance()->m_mRegexList.find(command);
	if(r_i != CRegexConfigManager::Instance()->m_mRegexList.end())
	{		
		for(int i = 0; i < r_i->second.size(); ++i)
		{
			cmatch what;	
			int flag_type = regex_constants::normal;

			if(r_i->second[i].ismatchsingle)
			{
				flag_type |= regex_constants::match_single_line;
			}

			if(r_i->second[i].ignorecase)
			{
				flag_type |= regex::icase;
			}

			regex expression(r_i->second[i].condition.c_str(), flag_type);
			if(regex_match(result.c_str(), what, expression))
			{
				for(int m=1;m<what.size();m++)
				{
					//printf("what %d value %s\n", m, what[m].str().c_str());
					if(r_i->second[i].attrnamelist.size() < m)
					{
						printf("attrname config error for command:%s condition:%s\n"
							, command.c_str(), r_i->second[i].condition.c_str());
						return;
					}
					else
					{
						if(r_i->second[i].attrnamelist[m - 1].compare("regex_next_input_value") == 0)
						{
							result = what[m].str();
						}
						else
						{
							if(command.compare("show ip interface brief") == 0)
							{
								if(m != 1)
								{
									continue;
								}

								ParseShowIPInterfaceResult(what, objectid, curDateStr, curTimeStr, deviceip);
							}
							else
							{
								CFTDRtnObjectAttrField fieldinfo;

								//generate attr value
								fieldinfo.ObjectID = objectid.c_str();
								fieldinfo.MonDate = curDateStr;
								fieldinfo.MonTime = curTimeStr;
								fieldinfo.AttrType = r_i->second[i].attrnamelist[m - 1].c_str();

								fieldinfo.ValueType = STRING_ATTR;
								fieldinfo.AttrValue = what[m].str().c_str();

								printf("$$$$$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
								//m_listObjectAttr.add(fieldinfo);
							}
						}
					}
				}

				if(r_i->second[i].isloop)
				{
					while(result.size() > 0)
					{
						cmatch what2;
						if(regex_match(result.c_str(), what2, expression))
						{
							for(int n=1;n<what2.size();n++)
							{
								if(r_i->second[i].attrnamelist.size() < n)
								{
									printf("attrname config error for command:%s condition:%s\n"
										, command.c_str(), r_i->second[i].condition.c_str());
									return;
								}
								else
								{
									if(r_i->second[i].attrnamelist[n - 1].compare("regex_next_input_value") == 0)
									{
										result = what2[n].str();
									}
									else
									{
										if(command.compare("show ip interface brief") == 0)
										{
											if(n != 1)
											{
												continue;
											}

											ParseShowIPInterfaceResult(what2, objectid, curDateStr, curTimeStr, deviceip);
										}
										else
										{
											CFTDRtnObjectAttrField fieldinfo;
											memset(&fieldinfo, 0, sizeof(CFTDRtnObjectAttrField));

											//generate attr value
											fieldinfo.ObjectID = objectid.c_str();
											fieldinfo.MonDate = curDateStr;
											fieldinfo.MonTime = curTimeStr;
											fieldinfo.AttrType = r_i->second[i].attrnamelist[n - 1].c_str();

											fieldinfo.ValueType = STRING_ATTR;
											fieldinfo.AttrValue = what2[n].str().c_str();

											printf("$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
											//m_listObjectAttr.add(fieldinfo);
										}
									}
								}
							}	
						}
						else
						{
							printf("command:%s not match condition:%s, result:%s\n"
								, command.c_str(), r_i->second[i].condition.c_str(), result.c_str());

							if(r_i->second[i].notmatchattrname.size() > 0)
							{
								CFTDRtnObjectAttrField fieldinfo;

								//generate attr value
								fieldinfo.ObjectID = objectid.c_str();
								fieldinfo.MonDate = curDateStr;
								fieldinfo.MonTime = curTimeStr;
								fieldinfo.AttrType = r_i->second[i].notmatchattrname.c_str();

								fieldinfo.ValueType = STRING_ATTR;
								fieldinfo.AttrValue = "";

								printf("$$$$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
								//m_listObjectAttr.add(fieldinfo);
							}

							break;
						}
					}

					//循环匹配一定出现在最底层的条件中
					return;
				}

			}
			else
			{
				printf("command:%s not match condition:%s, result:%s\n"
					, command.c_str(), r_i->second[i].condition.c_str(), result.c_str());

				if(r_i->second[i].notmatchattrname.size() > 0)
				{
					CFTDRtnObjectAttrField fieldinfo;

					//generate attr value
					fieldinfo.ObjectID = objectid.c_str();
					fieldinfo.MonDate = curDateStr;
					fieldinfo.MonTime = curTimeStr;
					fieldinfo.AttrType = r_i->second[i].notmatchattrname.c_str();

					fieldinfo.ValueType = STRING_ATTR;
					fieldinfo.AttrValue = "";

					printf("$$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
					//m_listObjectAttr.add(fieldinfo);
				}

				//当前条件不匹配，不进行剩余条件的匹配
				return;
			}
		}
	}
}

void test_interface()
{
	//加载正则表达式过滤信息的配置文件
	if(CRegexConfigManager::Instance()->LoadConfig("snmpmanager.regex") != 0)
	{
		//printf("LoadConfig faile for %s\n", REGEX_CFG_NAME);
		return;
	}

	CRegexConfigManager::Instance()->DumpConfig();

	string result = "Interface              IP-Address      OK? Method Status                Protocol\r\n\
		GigabitEthernet0       10.64.253.41    YES NVRAM  down                    up      \r\n\
		GigabitEthernet1       10.64.254.41    YES NVRAM  up                    down      \r\n\
		GigabitEthernet2       172.1.33.41     YES NVRAM  administratively down                    down      \r\n\
		Serial4/0.1/1/1/1:0    10.64.1.1       YES NVRAM  up                    up      ";

	//string result = "Interface              IP-Address      OK? Method Status                Protocol\r\n\
	//	GigabitEthernet0/0/0   10.32.0.18      YES NVRAM  up                    up      \r\n\
	//	GigabitEthernet0/0/1   10.112.22.1     YES NVRAM  up                    up      \r\n\
	//	GigabitEthernet0/1/0   172.16.224.178  YES NVRAM  up                    up      \r\n\
	//	GigabitEthernet0/1/1   172.16.224.194  YES NVRAM  up                    up      \r\n\
	//	GigabitEthernet0/1/2   unassigned      YES NVRAM  administratively down down    \r\n\
	//	GigabitEthernet0/1/3   unassigned      YES NVRAM  administratively down down    \r\n\
	//	GigabitEthernet0/1/4   unassigned      YES NVRAM  administratively down down    \r\n\
	//	ATM0/2/0               unassigned      YES NVRAM  administratively down down    \r\n\
	//	GigabitEthernet0       172.1.50.13     YES NVRAM  up                    up      \r\n\
	//	GMPLS0                 unassigned      YES NVRAM  administratively down down ";

	ParseCommandResult("show ip interface brief", result, "123","127.0.0.1");

}

*/
void test_map_erase(void)
{
	std::map<int, string> map_int;
	for (int i = 0; i < 9; i++)
	{
		if (i % 2)
		{
			map_int[i + 1] = "2n";
		}
		else
		{
			map_int[i + 1] = "2n+1";
		}
	}

	for (map<int, string>::iterator it = map_int.begin(); it != map_int.end();)
	{
		if (strcmp(it->second.c_str(), "2n") == 0)
		{
			map_int.erase(it++);
		}
		else
		{
			it++;
		}
	}
}

void test_strtok(string str, string delim, list<string> &str_list)
{
	char *p = strtok((char *)str.c_str(), delim.c_str());
	str_list.push_back(p);
	while ((p = strtok(NULL, delim.c_str())) != NULL)
	{
		str_list.push_back(p);
	}
}

void test_strmore(void)
{
	char pBuf[1024] = "\0";
	string s = "set service \"TCP_42009\" protocol tcp src-port 0-65535 dst-port 42009-42009 \
		              set service \"TCP_33011\" protocol tcp src-port 0-65535 dst-port \
		              set service \"www\" protocol tcp src-port 0-65535 dst-port 80-80 ";

	string s_ori = "set service \"TCP_42009\" protocol tcp src-port 0-65535 dst-port 42009-42009 \
		              set service \"www\" protocol tcp src-port 0-65535 dst-port 80-80 \
		set service \"TCP_8080\" protocol tcp src-port 0-65535 dst-port 8080-8080 ";
	strcpy(pBuf, s_ori.c_str());
	printf("origen string is: %s.\n", pBuf);

	string value = "1 YEAR, 49 WEEKS, 3 DAYS, 22 HOURS, 34 MINUTES";
	string value_o = "1 year, 49 weeks, 3 days, 22 hours, 34 minutes";
	string dt_value = "1 YEAR, 48 WEEKS, 5 DAYS, 11 HOURS, 15 MINUTES";
	int res = strcmp(value.c_str(), dt_value.c_str());
	res = 0;
	res = strcasecmp(value_o.c_str(), dt_value.c_str());

	//剔除"--- more ---"之类的字符
	string str_temp = "";
	if (strstr(pBuf, MORESTR) != NULL)			//包含MORESTR
	{
		str_temp = string(pBuf);
		while (str_temp.find(MORESTR) != string::npos)
		{
			str_temp = str_temp.replace(
					str_temp.find(MORESTR),
					strlen(MORESTR),
					"");
		}

		while (str_temp.find(SPECIAL_STR) != string::npos)
		{
			str_temp = str_temp = str_temp.replace(
					str_temp.find(SPECIAL_STR),
					strlen(SPECIAL_STR),
					"");
		}
	}
	else if (strstr(pBuf, SPECIAL_STR) != NULL) //仅包含MORESPE_STR
	{
		str_temp = string(pBuf);
		printf(
			" old string length = %d,\n content is: %s.\n",
			str_temp.length(),
			str_temp.c_str());
		while (str_temp.find(SPECIAL_STR) != string::npos)
		{
			str_temp = str_temp.replace(
					str_temp.find(SPECIAL_STR),
					strlen(SPECIAL_STR),
					"");
		}

		printf(
			" new string length = %d,\n content is: %s.\n",
			str_temp.length(),
			str_temp.c_str());
	}
	else
	{
	}
}

int test_main(void)
{
	string str = "abc,spantree,vlan,OSPFNeight";

	list<string> str_list;
	test_strtok(str, ",", str_list);
	test_strtok(str, ";", str_list);

	test_map_erase();

	int len_mor = strlen(SPECIAL_STR);
	test_strmore();

	//	test_regex();
	//	test_syslog_parse();
	//	test_thread_ping();
	//	test_snmp_get();
	//	test_syslog_classify();
	//	test_regex_match();
	test_ssh();

	//	test_interface();
	char buf[16] = "\0";
	long sum = 0;
	int max_cpu;

	//for( ; it_data != dm.end(); it_data++ )
	//{
	max_cpu = 2;
	sum = max_cpu > sum ? max_cpu : sum;

	//}
	sprintf(buf, "%ld", sum);

	time_t timep;
	time(&timep);

	struct tm *curTime = localtime(&timep);
	char curTimeStr[10];
	char curDateStr[10];

	strftime(curTimeStr, 10, "%H%M%S", curTime);
	strftime(curDateStr, 10, "%Y%m%d", curTime);

	printf("current time=[%s].\n", curTimeStr);
	printf("current date=[%s].\n", curDateStr);

	return 0;
}
