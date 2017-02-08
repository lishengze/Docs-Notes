/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	EventConfigConnector.cpp
///@brief	实现了连接配置管理服务器通信消息的类
///@history
///20110817	魏诚		创建该文件
#include "EventConfigConnector.h"
#include "UFCopy.h"
#include "CExprAnalysis.h"
#include "EventCounterServer.h"
#include "PrjCommon.h"
#include "FtdData.h"
#include "CRegexConfig.h"
#include "inputStream.h"
#include "CExprNode.h"
#include "inputToken.h"
#include "CExprParser.h"
#include "CMsgGenerator.h"

extern CExprAnalysis *g_mExprAnalysis;
extern list<string> g_warningInfoList;
extern CListWarningEventField *g_pListEvent;

//魏诚add，20120203
extern int	g_mEventProcessFuzzyMatch;
extern CWarningEventManager g_warningEventManager;

extern CDataCenter	*g_pDataCenter;		///数据中心对象列表信息
extern CMsgGenerator g_MsgGenerator;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput_config;	// 数据包输出到文件
#endif
extern CExprParser<CValue>	g_mEventParser;
extern CContext *g_pTaskContext;

extern int g_mConfigControlEvent;

map<string, string> g_DevIPList;		//设备ip地址表，key:objectid，value:ip

/*   string   to   low*/
inline char *strlwr(char *str, int length)
{
	char *orig = str;

	// process   the   string
	for (int i = 0; *(str + i) != '\0 ' && i < length; i++)
	{
		*(str + i) = tolower(*(str + i));
	}

	return orig;
}

///保存客户端设置的告警事件延期警报时间
///key:objectid;;eventname
///value:CObjectAttrKey
map<string, CObjectAttrKey> g_mapEventDelayTime;

//todo extern map <string, int > g_mapDeviceNo;			// 保存设备信息及其数组内偏移位置
//todo extern int g_nDeviceNo;								// 保存当前设置计数
#define TASK_SUCCESS		0
#define TASK_RESULT_ERROR	12

int CConfigConnector::test_task(void)
{
	CFTDRtnNetMonitorTaskResultField resultField;

	vector<string>	instruction_chain_1;
	vector<string>	result_chain_1;

	//CPUUsageInfo
	instruction_chain_1.push_back("CPUUsageInfo");
	result_chain_1.push_back(
			"CPU utilization for five seconds: 1%/0%; one minute: 1888888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
1888888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
1888888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
888888888888888888888888888888888888888888888888888888888888888888888888888888888888\
888888888888888888888888888888888888888888888888888888888888888888888888888888888888%; five minutes: 1%");

	//MEMUsageInfo
	instruction_chain_1.push_back("MEMUsageInfo");
	result_chain_1.push_back(
			"Processor Pool Total:  378228080 Used:  130288836 Free:  247939244\r\n\
		I/O Pool Total:   67108864 Used:   13606672 Free:   53502192");

	//Ping
	instruction_chain_1.push_back("Ping");
	result_chain_1.push_back(
			"\r\n\
		Type escape sequence to abort.\r\n\
		Sending 1000, 100-byte ICMP Echos to 172.1.128.1, timeout is 2 seconds:\r\n\
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\
		!!!!!!!!!!!!!!!!!!!!\r\n\
		Success rate is 99 percent (999/1000), round-trip min/avg/max = 1/3/25 ms");

	//NTPStatus
	instruction_chain_1.push_back("NTPStatus");
	result_chain_1.push_back(
			"Clock is synchronized, stratum 2, reference is 172.1.0.51\r\n\
		nominal freq is 250.0000 Hz, actual freq is 250.0016 Hz, precision is 2**18\r\n\
		reference time is D1E0D808.7EEB481B (15:45:12.495 BJ Mon Aug 1 2011)\r\n\
		clock offset is 0.0868 msec, root delay is 0.73 msec\r\n\
		root dispersion is 2.99 msec, peer disp	ersion is 0.14 msec");

	//CrashStatus
	instruction_chain_1.push_back("CrashStatus");
	result_chain_1.push_back(
			"-#- --length-- -----date/time------ path\r\n\
		1     19267510 Sep 16 2009 10:58:42 cat4500e-ipbasek9-mz.122-44.SG1.bin\r\n\
		2     25442508 Jan 11 2010 02:30:12 cat4500e-entservicesk9-mz.122-52.SG.bin\r\n\
		3     25442405 Mar 08 2010 07:25:44 cat4500e-entservicesk9-mz.122-53.SG1.bin\r\n\
\r\n\
		53825536 bytes available (77611008 bytes used)");

	//Etherchannel
	instruction_chain_1.push_back("Etherchannel");
	result_chain_1.push_back(
			"Flags:  D - down        P - bundled in port-channel\r\n\
		I - stand-alone s - suspended\r\n\
		H - Hot-standby (LACP only)\r\n\
		R - Layer3      S - Layer2\r\n\
		U - in use      N - not in use, no aggregation\r\n\
		f - failed to allocate aggregator\r\n\
\r\n\
		M - not in use, no aggregation due to minimum links not met\r\n\
		m - not in use, port not aggregated due to minimum links not met\r\n\
		u - unsuitable for bundling\r\n\
		d - default port\r\n\
\r\n\
		w - waiting to be aggregated\r\n\
		Number of channel-groups in use: 1\r\n\
		Number of aggregators:           1\r\n\
\r\n\
		Group  Port-channel  Protocol    Ports\r\n\
		------+-------------+-----------+-----------------------------------------------\r\n\
		1      Po1(SU)          -        Gi1/1(P)       Gi2/1(P)\r\n\
		2      Po2(SU)          -        Gi2/2(P)       Gi3/2(P)");

	//Fabricchanel
	instruction_chain_1.push_back("Fabricchanel");
	result_chain_1.push_back(
			"\r\n\
		  slot channel   rxErrors   txErrors    txDrops  lbusDrops\r\n\
		  1       0          0          0          0          0\r\n\
		  2       0          0          0          0          0\r\n\
		  4       0          0          0          0          0");

	//ModleState
	instruction_chain_1.push_back("ModleState");
	result_chain_1.push_back(
			"Mod Ports Card Type                              Model              Serial No.\r\n\
		  --- ----- -------------------------------------- ------------------ -----------\r\n\
		  1    2  Supervisor Engine 720 (Active)         WS-SUP720-3B       SAL1429N2A2\r\n\
		  2    2  Supervisor Engine 720 (Hot)            WS-SUP720-3B       SAL1429N2EZ\r\n\
		  4   24  CEF720 24 port 1000mb SFP              WS-X6724-SFP       SAL1430NUDN\r\n\
\r\n\
		  Mod MAC addresses                       Hw    Fw           Sw           Status\r\n\
		  --- ---------------------------------- ------ ------------ ------------ -------\r\n\
		  1  0025.4539.bc70 to 0025.4539.bc73   5.11  8.5(4)       12.2(33)SXH6 Ok\r\n\
		  2  0022.559e.2870 to 0022.559e.2873   5.11  8.5(4)       12.2(33)SXH6 Ok\r\n\
		  4  d0d0.fd7f.42f8 to d0d0.fd7f.430f   4.4   12.2(18r)S1  12.2(33)SXH6 Ok\r\n\
\r\n\
		  Mod  Sub-Module                  Model              Serial       Hw     Status \r\n\
		  ---- --------------------------- ------------------ ----------- ------- -------\r\n\
		  1  Policy Feature Card 3       WS-F6K-PFC3B       SAL1429N11R  2.6    Ok\r\n\
		  1  MSFC3 Daughterboard         WS-SUP720          SAL1429N2PD  5.0    Ok\r\n\
		  2  Policy Feature Card 3       WS-F6K-PFC3B       SAL1429N13C  2.6    Ok\r\n\
		  2  MSFC3 Daughterboard         WS-SUP720          SAL1429N1NQ  5.0    Ok\r\n\
		  4  Centralized Forwarding Card WS-F6700-CFC       SAL1430NLVF  4.1    Ok\r\n\
\r\n\
		  Mod  Online Diag Status \r\n\
		  ---- -------------------\r\n\
		  1  Pass\r\n\
		  2  Pass\r\n\
		  4  Pass");

	//PlatformState
	instruction_chain_1.push_back("PlatformState");
	result_chain_1.push_back(
			"Slot      Card Type           Status          Insertion time\r\n\
		----      ---------           ------          --------------\r\n\
		0,1       NPEG100 (Active)    Up              1y1w ago\r\n\
		2,3       NPEG100 (Standby)   Up              1y1w ago\r\n\
		4         1PA Carrier Card    Active          1y1w ago\r\n\
		5         PA Carrier Card     Deactivated     Unknown\r\n\
\r\n\
		FPGA information:\r\n\
	Hardware            FPGA version\r\n\
		Slot Card Type           Version     Bundled    Flash    Current   \r\n\
		---- ---------           --------    -------   -------   -------   \r\n\
		0   NPEG100              02.02       02.05     02.05     02.05  \r\n\
		4   1PA Carrier Card     02.01       01.40     01.40     01.40 \r\n\
\r\n\
		* - Card needs an FPGA update\r\n\
# - Card needs to be reloaded for the new FPGA to take effect\r\n\
\r\n\
		Port Adapter Information\r\n\
		Slot      PA Type             Status          Insertion time\r\n\
		----      ---------           ------          --------------\r\n\
		4         PA-MC-STM-1SMI      Active          1y1w ago\r\n\
\r\n\
		System is compliant with hardware configuration guidelines.\r\n\
\r\n\
		Network IO Interrupt Throttling:\r\n\
	throttle count=7529, timer count=7529\r\n\
		active=0, configured=1\r\n\
		netint usec=4000, netint mask usec=200");

	//ATMPVCState
	instruction_chain_1.push_back("ATMPVCState");
	result_chain_1.push_back(
			"           VCD /                                            Peak Av/Min Burst\r\n\
Interface  Name         VPI   VCI Type    Encaps     SC     Kbps   Kbps Cells St\r\n\
1/0/0.100  1              6   100 PVC     SNAP       CBR   50000              UP\r\n\
1/0/0.101  2              6   101 PVC     SNAP       CBR   30000              UP");

	//IfsCRC
	instruction_chain_1.push_back("IfsCRC");
	result_chain_1.push_back(
			"GigabitEthernet1/2 is up, line protocol is up (connected)\r\n\
Hardware is C6k 1000Mb 802.3, address is 0025.4539.bc71 (bia 0025.4539.bc71)\r\n\
Description: To_PD-JY2000-B2-4N309_ETH2/1 \r\n\
			 MTU 1500 bytes, BW 1000000 Kbit, DLY 10 usec, \r\n\
			 reliability 255/255, txload 1/255, rxload 1/255\r\n\
			 Encapsulation ARPA, loopback not set\r\n\
			 Keepalive set (10 sec)\r\n\
			 Full-duplex, 1000Mb/s, media type is SX\r\n\
			 Media-type configured as SFP connector\r\n\
			 input flow-control is off, output flow-control is off\r\n\
			 Clock mode is auto\r\n\
			 ARP type: ARPA, ARP Timeout 04:00:00\r\n\
			 Last input never, output 00:00:28, output hang never\r\n\
			 Last clearing of \"show interface\" counters 14w1d\r\n\
			 Input queue: 0/2000/0/0 (size/max/drops/flushes); Total output drops: 0\r\n\
			 Queueing strategy: fifo\r\n\
			 Output queue: 0/40 (size/max)\r\n\
			 5 minute input rate 0 bits/sec, 0 packets/sec\r\n\
			 5 minute output rate 0 bits/sec, 0 packets/sec\r\n\
			 154087 packets input, 12875696 bytes, 0 no buffer\r\n\
			 Received 14 broadcasts (4 multicasts)\r\n\
			 0 runts, 0 giants, 0 throttles \r\n\
			 0 input errors, 0 CRC, 0 frame, 0 overrun, 0 ignored\r\n\
			 0 watchdog, 0 multicast, 0 pause input\r\n\
			 0 input packets with dribble condition detected\r\n\
			 11251412 packets output, 799994724 bytes, 0 underruns\r\n\
			 0 output errors, 0 collisions, 0 interface resets\r\n\
			 0 babbles, 0 late collision, 0 deferred\r\n\
			 0 lost carrier, 0 no carrier, 0 PAUSE output\r\n\
			 0 output buffer failures, 0 output buffers swapped out");

	//CDPInfo
	instruction_chain_1.push_back("CDPInfo");
	result_chain_1.push_back(
			"\r\n\
Capability Codes: R - Router, T - Trans Bridge, B - Source Route Bridge\r\n\
S - Switch, H - Host, I - IGMP, r - Repeater, P - Phone,\r\n\
D - Remote, C - CVTA, M - Two-port Mac Relay\r\n\
\r\n\
Device ID        Local Intrfce     Holdtme    Capability  Platform  Port ID\r\n\
T-SC3560-A1-2N413.shfe.com.cn\r\n\
Fas 1/0/4         133             R S I  WS-C3560G Gig 0/48\r\n\
T-SC3560-A2-2N412.shfe.com.cn\r\n\
Fas 1/0/1         137              S I   WS-C3560G Gig 0/48\r\n\
T-WG3750-C1-2M507.shfe.com.cn\r\n\
Gig 2/0/5         137             R S I  WS-C3560- Gig 0/1\r\n\
TEST-WG3750      Gig 2/0/1         146              S I   WS-C3750G Gig 1/0/49\r\n\
ZJ-WG3750-B1-2N602.shfe.com.cn\r\n\
Fas 1/0/23        153             R S I  WS-C3750G Gig 1/0/22\r\n\
T-SC4503-B2-2N412\r\n\
Fas 1/0/3         145             R S I  WS-C4503  Gig 1/12\r\n\
T-SC4503-C2-2N412\r\n\
Fas 1/0/2         159             R S I  WS-C4503  Gig 1/12\r\n\
T-SC4503-B1-2N413\r\n\
Fas 1/0/6         128             R S I  WS-C4503  Gig 1/12\r\n\
T-SC4503-C1-2N413\r\n\
Fas 1/0/5         141             R S I  WS-C4503  Gig 1/12\r\n\
CN2829815F0141   Fas 1/0/8         173               R    PCM6348   Gi1/0/48\r\n\
CN2829815F0167   Fas 1/0/7         167               R    PCM6348   Gi1/0/48");

	//OSPFNeighor
	instruction_chain_1.push_back("OSPFNeighor");
	result_chain_1.push_back(
			"\r\n\
Neighbor ID     Pri   State           Dead Time   Address         Interface\r\n\
10.32.255.8     255   FULL/DR         00:00:38    10.33.254.254   GigabitEthernet1/0/50\r\n\
10.32.255.113     1   2WAY/DROTHER    00:00:35    10.33.254.113   GigabitEthernet1/0/50\r\n\
10.32.255.114     1   2WAY/DROTHER    00:00:32    10.33.254.114   GigabitEthernet1/0/50\r\n\
10.32.255.116     1   2WAY/DROTHER    00:00:35    10.33.254.116   GigabitEthernet1/0/50\r\n\
10.32.255.117     1   2WAY/DROTHER    00:00:37    10.33.254.117   GigabitEthernet1/0/50\r\n\
10.32.255.118     1   2WAY/DROTHER    00:00:39    10.33.254.118   GigabitEthernet1/0/50\r\n\
10.32.255.119     1   2WAY/DROTHER    00:00:37    10.33.254.119   GigabitEthernet1/0/50\r\n\
10.32.255.120     1   2WAY/DROTHER    00:00:32    10.33.254.120   GigabitEthernet1/0/50\r\n\
10.32.255.121     1   2WAY/DROTHER    00:00:31    10.33.254.121   GigabitEthernet1/0/50\r\n\
10.32.255.122     1   2WAY/DROTHER    00:00:31    10.33.254.122   GigabitEthernet1/0/50\r\n\
10.32.255.123     1   2WAY/DROTHER    00:00:35    10.33.254.123   GigabitEthernet1/0/50\r\n\
10.32.255.125     1   2WAY/DROTHER    00:00:32    10.33.254.125   GigabitEthernet1/0/50\r\n\
10.32.255.126     1   2WAY/DROTHER    00:00:37    10.33.254.126   GigabitEthernet1/0/50\r\n\
10.32.255.127     1   2WAY/DROTHER    00:00:34    10.33.254.127   GigabitEthernet1/0/50\r\n\
10.32.255.128     1   2WAY/DROTHER    00:00:34    10.33.254.128   GigabitEthernet1/0/50\r\n\
10.32.255.129     1   2WAY/DROTHER    00:00:38    10.33.254.129   GigabitEthernet1/0/50\r\n\
10.32.255.130     1   2WAY/DROTHER    00:00:37    10.33.254.130   GigabitEthernet1/0/50\r\n\
10.32.255.131     1   FULL/BDR        00:00:33    10.33.254.131   GigabitEthernet1/0/50\r\n\
10.32.255.7     255   FULL/DR         00:00:34    10.33.253.254   GigabitEthernet1/0/49\r\n\
10.32.255.113     1   2WAY/DROTHER    00:00:39    10.33.253.113   GigabitEthernet1/0/49\r\n\
10.32.255.114     1   2WAY/DROTHER    00:00:35    10.33.253.114   GigabitEthernet1/0/49\r\n\
10.32.255.116     1   2WAY/DROTHER    00:00:35    10.33.253.116   GigabitEthernet1/0/49\r\n\
10.32.255.117     1   2WAY/DROTHER    00:00:37    10.33.253.117   GigabitEthernet1/0/49\r\n\
10.32.255.118     1   2WAY/DROTHER    00:00:39    10.33.253.118   GigabitEthernet1/0/49\r\n\
10.32.255.119     1   2WAY/DROTHER    00:00:38    10.33.253.119   GigabitEthernet1/0/49\r\n\
10.32.255.120     1   2WAY/DROTHER    00:00:33    10.33.253.120   GigabitEthernet1/0/49\r\n\
10.32.255.121     1   2WAY/DROTHER    00:00:31    10.33.253.121   GigabitEthernet1/0/49\r\n\
10.32.255.122     1   2WAY/DROTHER    00:00:32    10.33.253.122   GigabitEthernet1/0/49\r\n\
10.32.255.123     1   2WAY/DROTHER    00:00:31    10.33.253.123   GigabitEthernet1/0/49\r\n\
10.32.255.125     1   2WAY/DROTHER    00:00:39    10.33.253.125   GigabitEthernet1/0/49\r\n\
10.32.255.126     1   2WAY/DROTHER    00:00:33    10.33.253.126   GigabitEthernet1/0/49\r\n\
10.32.255.127     1   2WAY/DROTHER    00:00:39    10.33.253.127   GigabitEthernet1/0/49\r\n\
10.32.255.128     1   2WAY/DROTHER    00:00:33    10.33.253.128   GigabitEthernet1/0/49\r\n\
10.32.255.129     1   2WAY/DROTHER    00:00:35    10.33.253.129   GigabitEthernet1/0/49\r\n\
10.32.255.130     1   2WAY/DROTHER    00:00:30    10.33.253.130   GigabitEthernet1/0/49\r\n\
10.32.255.131     1   FULL/BDR        00:00:32    10.33.253.131   GigabitEthernet1/0/49");

	//IfsInfo
	instruction_chain_1.push_back("IfsInfo");
	result_chain_1.push_back(
			"Interface              IP-Address      OK? Method Status                Protocol\r\n\
GigabitEthernet1/1     unassigned      YES unset  up                    up      \r\n\
GigabitEthernet1/2     unassigned      YES unset  up                    up      \r\n\
GigabitEthernet2/1     unassigned      YES unset  up                    up      \r\n\
GigabitEthernet2/2     unassigned      YES unset  up                    up      \r\n\
GigabitEthernet4/1     unassigned      YES unset  down                  down    \r\n\
GigabitEthernet4/2     unassigned      YES unset  up                    up      \r\n\
GigabitEthernet4/3     unassigned      YES TFTP   administratively down down    \r\n\
GigabitEthernet4/4     unassigned      YES TFTP   administratively down down    ");

	//Vlan
	instruction_chain_1.push_back("Vlan");
	result_chain_1.push_back(
			"\r\n\
VLAN Name                             Status    Ports\r\n\
---- -------------------------------- --------- -------------------------------\r\n\
1    default                          active    \r\n\
2    MGT                              active    Gi4/24\r\n\
17   RSPAN_CWJY_B4.2                  active    \r\n\
110  JY_B4.2                          active    Gi4/1, Gi4/2\r\n\
700  PD-JY6504A12_To_PD-JY2000B12     active    Gi1/2, Gi2/2\r\n\
1002 fddi-default                     act/unsup \r\n\
1003 token-ring-default               act/unsup \r\n\
1004 fddinet-default                  act/unsup ");

	//Spantree
	instruction_chain_1.push_back("Spantree");
	result_chain_1.push_back(
			"\r\n\
\r\n\
VLAN0041\r\n\
  Spanning tree enabled protocol rstp\r\n\
  Root ID    Priority    32809\r\n\
             Address     001c.b0c9.5f40\r\n\
             This bridge is the root\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
\r\n\
  Bridge ID  Priority    32809  (priority 32768 sys-id-ext 41)\r\n\
             Address     001c.b0c9.5f40\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
             Aging Time 300\r\n\
\r\n\
Interface           Role Sts Cost      Prio.Nbr Type\r\n\
------------------- ---- --- --------- -------- --------------------------------\r\n\
Gi3/47              Desg FWD 4         128.303  P2p \r\n\
\r\n\
\r\n\
VLAN0210\r\n\
  Spanning tree enabled protocol rstp\r\n\
  Root ID    Priority    8402\r\n\
             Address     001c.b0c9.5f40\r\n\
             This bridge is the root\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
\r\n\
  Bridge ID  Priority    8402   (priority 8192 sys-id-ext 210)\r\n\
             Address     001c.b0c9.5f40\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
             Aging Time 300\r\n\
\r\n\
Interface           Role Sts Cost      Prio.Nbr Type\r\n\
------------------- ---- --- --------- -------- --------------------------------\r\n\
Gi4/3               Desg FWD 4         128.387  P2p \r\n\
Gi4/4               Desg FWD 4         128.388  P2p \r\n\
Po1                 Desg FWD 3         128.1665 P2p \r\n\
\r\n\
\r\n\
VLAN0800\r\n\
  Spanning tree enabled protocol rstp\r\n\
  Root ID    Priority    8992\r\n\
             Address     001c.b0c9.5f40\r\n\
             This bridge is the root\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
\r\n\
  Bridge ID  Priority    8992   (priority 8192 sys-id-ext 800)\r\n\
             Address     001c.b0c9.5f40\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
             Aging Time 300\r\n\
\r\n\
Interface           Role Sts Cost      Prio.Nbr Type\r\n\
------------------- ---- --- --------- -------- --------------------------------\r\n\
Po1                 Desg FWD 3         128.1665 P2p \r\n\
\r\n\
\r\n\
VLAN0818\r\n\
  Spanning tree enabled protocol rstp\r\n\
  Root ID    Priority    9010\r\n\
             Address     001c.b0c9.5f40\r\n\
             This bridge is the root\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
\r\n\
  Bridge ID  Priority    9010   (priority 8192 sys-id-ext 818)\r\n\
             Address     001c.b0c9.5f40\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
             Aging Time 300\r\n\
\r\n\
Interface           Role Sts Cost      Prio.Nbr Type\r\n\
------------------- ---- --- --------- -------- --------------------------------\r\n\
Gi4/17              Desg FWD 4         128.401  P2p Edge \r\n\
Gi4/18              Desg FWD 4         128.402  P2p Edge \r\n\
Po1                 Desg FWD 3         128.1665 P2p \r\n\
\r\n\
\r\n\
VLAN0899\r\n\
  Spanning tree enabled protocol rstp\r\n\
  Root ID    Priority    33667\r\n\
             Address     001c.b0c9.5f40\r\n\
             This bridge is the root\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
\r\n\
  Bridge ID  Priority    33667  (priority 32768 sys-id-ext 899)\r\n\
             Address     001c.b0c9.5f40\r\n\
             Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
             Aging Time 300\r\n\
\r\n\
Interface           Role Sts Cost      Prio.Nbr Type\r\n\
------------------- ---- --- --------- -------- --------------------------------\r\n\
Po1                 Desg FWD 3         128.1665 P2p \r\n\
");

	//Trunk
	instruction_chain_1.push_back("Trunk");
	result_chain_1.push_back(
			"\r\n\
Port                Mode         Encapsulation  Status        Native vlan\r\n\
Gi4/23              on           802.1q         trunking      1\r\n\
Po1                 on           802.1q         trunking      1\r\n\
\r\n\
Port                Vlans allowed on trunk\r\n\
Gi4/23              17\r\n\
Po1                 110,700\r\n\
\r\n\
Port                Vlans allowed and active in management domain\r\n\
Gi4/23              17\r\n\
Po1                 110,700\r\n\
\r\n\
Port                Vlans in spanning tree forwarding state and not pruned\r\n\
Gi4/23              17\r\n\
Po1                 110,700");

	//ISDNState
	instruction_chain_1.push_back("ISDNState");
	result_chain_1.push_back(
			"Global ISDN Switchtype = primary-net5\r\n\
ISDN Serial3/0:15 interface\r\n\
dsl 0, interface ISDN Switchtype = primary-net5\r\n\
Layer 1 Status:\r\n\
SHUTDOWN\r\n\
Layer 2 Status:\r\n\
TEI = 0, Ces = 1, SAPI = 0, State = TEI_ASSIGNED\r\n\
Layer 3 Status:\r\n\
0 Active Layer 3 Call(s)\r\n\
Active dsl 0 CCBs = 0\r\n\
The Free Channel Mask:  0x00000000\r\n\
Number of L2 Discards = 0, L2 Session ID = 0\r\n\
ISDN Serial3/1:15 interface\r\n\
dsl 1, interface ISDN Switchtype = primary-net5\r\n\
Layer 1 Status:\r\n\
ACTIVE\r\n\
Layer 2 Status:\r\n\
TEI = 0, Ces = 1, SAPI = 0, State = MULTIPLE_FRAME_ESTABLISHED\r\n\
Layer 3 Status:\r\n\
1 Active Layer 3 Call(s)\r\n\
CCB:callid=2606, sapi=0, ces=0, B-chan=13, calltype=VOICE\r\n\
	Active dsl 1 CCBs = 1\r\n\
	The Free Channel Mask:  0xFFFF6FFF");

	//HSRP
	instruction_chain_1.push_back("HSRP");
	result_chain_1.push_back(
			"                     P indicates configured to preempt.\r\n\
						 |\r\n\
						 Interface   Grp Prio P State    Active          Standby         Virtual IP     \r\n\
						 Vl110       11  80   P Standby  192.168.11.252  local           192.168.11.24  \r\n\
						 Vl700       70  80   P Standby  10.32.252.66    local           10.32.252.65");

	//RunTime
	instruction_chain_1.push_back("RunTime");
	result_chain_1.push_back(
			"Cisco IOS Software, C3560 Software (C3560-IPSERVICESK9-M), Version 12.2(50)SE3, RELEASE SOFTWARE (fc1)\r\n\
		Technical Support: http://www.cisco.com/techsupport\r\n\
	Copyright (c) 1986-2009 by Cisco Systems, Inc.\r\n\
		Compiled Wed 22-Jul-09 06:41 by prod_rel_team\r\n\
		Image text-base: 0x01000000, data-base: 0x02D00000\r\n\
\r\n\
123\r\n\
\r\n\
ROM: Bootstrap program is C3560 boot loader\r\n\
BOOTLDR: C3560 Boot Loader (C3560-HBOOT-M) Version 12.2(44)SE6, RELEASE SOFTWARE (fc1)\r\n\
\r\n\
		 ZJ-WG3560-C1-2M108 uptime is 13 weeks, 20 hours, 47 minutes\r\n\
		 System returned to ROM by power-on\r\n\
		 System restarted at 15:47:13 BJ Mon Jul 11 2011\r\n\
		 System image file is \"flash:c3560-ipservicesk9-mz.122-50.SE3/c3560-ipservicesk9-mz.122-50.SE3.bin\"\r\n\
\r\n\
\r\n\
		 This product contains cryptographic features and is subject to United\r\n\
		 States and local country laws governing import, export, transfer and");

	//Software Status
	instruction_chain_1.push_back("SoftwareStatus");
	result_chain_1.push_back(
			"Load Average\r\n\
 Slot  Status  1-Min  5-Min 15-Min\r\n\
  RP0 Healthy   0.00   0.00   0.00\r\n\
 ESP0 Healthy   0.00   0.03   0.00\r\n\
 SIP0 Healthy   0.02   0.20   0.38\r\n\
\r\n\
Memory (kB)\r\n\
 Slot  Status    Total     Used (Pct)     Free (Pct) Committed (Pct)\r\n\
  RP0 Healthy  8067464  2371872 (29%)  5695592 (17%)   3800208 (47%)\r\n\
 ESP0 Healthy  3877056   644080 (17%)  3232976 (83%)   2985424 (77%)\r\n\
 SIP0 Healthy   449776   344484 (77%)   105292 (23%)    367828 (82%)\r\n\
\r\n\
CPU Utilization\r\n\
 Slot  CPU   User System   Nice   Idle    IRQ   SIRQ IOwait\r\n\
  RP0    0   0.00   0.10   0.00  99.80   0.00   0.10   0.00\r\n\
         1   2.10   0.20   0.00  97.70   0.00   0.00   0.00\r\n\
 ESP0    0   0.70   0.80   0.00  98.50   0.00   0.00   0.00\r\n\
 SIP0    0   0.99   0.59   0.00  98.20   0.09   0.09   0.00");

	vector<string>	instruction_chain_3;
	vector<string>	result_chain_3;

	instruction_chain_3.push_back("DeviceStatus");
	result_chain_3.push_back(
			"PLATFORM INFORMATION --\r\n\
|     Marketing Name: BIG-IP 3400\r\n\
|     BIOS Rev: AMIBIOS(C)2002 American Megatrends, Inc.                                       BIOS Date: 02/21/05 15:21:14  Ver: 08.00.06 OBJ-0075-01 REV A.\r\n\
|     base MAC: 00:01:D7:6E:71:40\r\n\
|     PVA Version: 2\r\n\
+-> SYSTEM INFO\r\n\
|     Type: C62a\r\n\
|     Chassis   serial: bip240598s   Level 200 part: 200-0255-06 REV C\r\n\
|     Switch board   serial: PCA0100MXF7F   part: PCA-0100-03 REV C\r\n\
|     Host board   serial: TY7BU36A0136   part: MOB-0013-03 REV A\r\n\
|     Annunciator board   serial: 0714CF067421   part: OEM-0029-06 REV B\r\n\
|     Memory: 1.984GB\r\n\
+-> HARDWARE CARDS\r\n\
|   |     Type: crypto  Model: Cavium NITROX\r\n\
|   |         version: CN1000-MC-Main-SSL-0.99a\r\n\
+-> CPU 0\r\n\
|   |     Type: Intel(R) Pentium(R) 4 CPU 2.80GHz  Speed: 2799.353MHz\r\n\
|   |     Temp: 42degC   Fan speed: 10887rpm\r\n\
+-> CHASSIS TEMPERATURE\r\n\
|   |     (101) 40degC   (102) 34degC   (1) 50degC\r\n\
+-> CHASSIS FAN\r\n\
|   |     (101) active   (102) active   (103) active   (104) active\r\n\
|   |     (105) active   (106) active\r\n\
+-> POWER SUPPLY\r\n\
|   |     (101) active\r\n\
+-> LICENSE Local Traffic Manager Module add ons\r\n\
|   |     ADD 5 MBPS COMPRESSION\r\n\
|   |     ADD SSL 100");

	instruction_chain_3.push_back("MEMUsageInfo");
	result_chain_3.push_back(
			"MEMORY STATISTICS --\r\n\
|    Total = 1.528GB   Used = 21.04MB\r\n\
|    SUBSYSTEM                        Alloc     Max    Obj size\r\n\
|     connflow                         25344  639360     192\r\n\
|     laddr                             3360    3584      56\r\n\
|     listener                         46336   48128     256");

	vector<string>	instruction_chain_4;
	vector<string>	result_chain_4;

	//CPUUsage, manufactory_id=4
	instruction_chain_4.push_back("CPUUsageInfo");
	result_chain_4.push_back(
			"Average System Utilization:  1%\r\n\
							 Last 1 minute:  2%, Last 5 minutes:  2%, Last 15 minutes:  2%");

	//MEMUsage, manufactory_id=4
	instruction_chain_4.push_back("MEMUsageInfo");
	result_chain_4.push_back(
			"Memory: allocated 564280480, left 1203610368, frag 248");

	//NewSession, manufactory_id=4
	instruction_chain_4.push_back("NewSession");
	result_chain_4.push_back(
			"Last 1 minute: 2784, Last 5 minute: 15856, Last 15 minute: 48554");

	//Session, manufactory_id=4
	instruction_chain_4.push_back("Session");
	result_chain_4.push_back(
			"alloc 502/max 524288, alloc failed 0, mcast alloc 0, di alloc failed 0\r\n\
						 total reserved 0, free sessions in shared pool 523786\r\n\
						 slot 2: hw0 alloc 110/max 1048575");

	//NTPStatus,manufactory_id=4
	instruction_chain_4.push_back("NTPStatus");
	result_chain_4.push_back(
			"NTP is Enabled\r\n\
Primary server: 172.1.0.51 \r\n\
Backup1 server: 172.1.0.52 \r\n\
Backup2 server: 172.1.32.51 \r\n\
Authentication Mode: None\r\n\
Max Allowed Adjustment: 3 second(s)\r\n\
Request Interval: 10 minute(s).\r\n\
Sync NTP time to peer: Enabled\r\n\
Update Status: Idle \r\n\
Last Update at: 08/04/2011 15:08:20");

	//HA, manufactory_id=4
	instruction_chain_4.push_back("HAState");
	result_chain_4.push_back(
			"\r\n\
						 VSD group info:\r\n\
						 init hold time: 5\r\n\
						 heartbeat lost threshold: 3\r\n\
						 heartbeat interval: 1000(ms)\r\n\
						 master always exist: enabled\r\n\
						 group priority preempt holddown inelig   master       PB other members\r\n\
						 0      100 no             3 no       myself  1518512 \r\n\
						 total number of vsd groups: 1\r\n\
						 Total iteration=12781491,time=3988587793,max=34327,min=1298,average=312\r\n\
						 \r\n\
						 vsd group id: 0, member count: 2, master: 1518496\r\n\
						 member information:\r\n\
						 ---------------------------------------------------------------------\r\n\
						 group  unit_id  state          prio flag rto_peer   hb miss holddown\r\n\
						 ---------------------------------------------------------------------\r\n\
						 0  1518512  primary backup  100    0        0    1    0        3\r\n\
						 0  1518496  master          100    0        0    0    0        3");

	//Interface, manufactory_id=4
	instruction_chain_4.push_back("IfsInfo");
	result_chain_4.push_back(
			"A - Active, I - Inactive, U - Up, D - Down, R - Ready \r\n\
\r\n\
Interfaces in vsys Root: \r\n\
Name           IP Address         Zone        MAC            VLAN State VSD      \r\n\
mgt            172.1.1.4/18       MGT         001b.c064.e980    -   U   -  \r\n\
eth1/1         0.0.0.0/0          Untrust     0010.dbff.2070    -   I   0  \r\n\
eth1/2         0.0.0.0/0          Untrust     0010.dbff.2080    -   I   0  \r\n\
eth2/1         0.0.0.0/0          Trust       0010.dbff.2150    -   I   0  \r\n\
eth2/2         0.0.0.0/0          Trust       0010.dbff.2160    -   I   0  \r\n\
eth3/1         0.0.0.0/0          Null        0010.dbff.21d0    -   I   0  \r\n\
eth3/2         0.0.0.0/0          Null        0010.dbff.21e0    -   I   0  \r\n\
eth4/1         0.0.0.0/0          HA          001b.c064.e9a5    -   U   -  \r\n\
eth4/2         0.0.0.0/0          HA          001b.c064.e9a6    -   U   -  \r\n\
eth4/3         0.0.0.0/0          Null        0010.dbff.2270    -   I   0  \r\n\
eth4/4         0.0.0.0/0          Null        0010.dbff.2280    -   I   0  \r\n\
eth4/5         0.0.0.0/0          Null        0010.dbff.2290    -   I   0  ");

	//Env, manufactory_id=4
	instruction_chain_4.push_back("EnvInfo");
	result_chain_4.push_back(
			"Chassis Environment:\r\n\
Power Supply: Good\r\n\
Fan Status: Good\r\n\
CPU Temperature: 109'F ( 43'C)\r\n\
Slot Information:\r\n\
Slot  Type              S/N                Assembly-No  Version  Temperature \r\n\
0   System Board      0079122007000214   0051-006     F05      89'F (32'C),  91'F (33'C)\r\n\
4   Management        0252122007000345   0049-004     D14     109'F (43'C)\r\n\
5   ASIC Board        000599186M070077   0050-003     C02\r\n\
Marin FPGA version 9, Jupiter ASIC version 1, Fresno FPGA version 102\r\n\
I/O Board\r\n\
Slot  Type                     S/N                Version  FPGA version  \r\n\
1   2 port mini GBIC (0x5)   0141012008000004   B03           5\r\n\
2   2 port mini GBIC (0x5)   0141092007000016   B03           5\r\n\
3   2 port mini GBIC (0x5)   0141012008000022   B03           5\r\n\
4   8 port 10/100            0139052007000090   D02           6\r\n\
Alarm Control Information:\r\n\
Power failure audible alarm: disabled\r\n\
Fan failure audible alarm: disabled\r\n\
Low battery audible alarm: disabled\r\n\
Temperature audible alarm: disabled\r\n\
Normal alarm temperature is 132'F (56'C)\r\n\
Severe alarm temperature is 150'F (66'C)");

	//RouteInfo
	instruction_chain_4.push_back("RouteInfo");
	result_chain_4.push_back(
			"\r\n\
		IPv4 Dest-Routes for <untrust-vr> (0 entries)\r\n\
		--------------------------------------------------------------------------------------\r\n\
H: Host C: Connected S: Static A: Auto-Exported\r\n\
I: Imported R: RIP P: Permanent D: Auto-Discovered\r\n\
N: NHRP\r\n\
iB: IBGP eB: EBGP O: OSPF E1: OSPF external type 1\r\n\
E2: OSPF external type 2 trailing B: backup route\r\n\
\r\n\
\r\n\
	IPv4 Dest-Routes for <trust-vr> (22 entries)\r\n\
	--------------------------------------------------------------------------------------\r\n\
	ID          IP-Prefix      Interface         Gateway   P Pref    Mtr     Vsys\r\n\
	--------------------------------------------------------------------------------------\r\n\
	*         7 192.168.202.161/32         eth3/2         0.0.0.0   H    0      0     Root\r\n\
	*         6 192.168.202.160/29         eth3/2         0.0.0.0   C    0      0     Root\r\n\
	*        13     172.25.64.0/19           red1 192.168.202.209   S   20      1     Root\r\n\
	*        21     172.23.64.0/19           red1 192.168.202.209   S   20      1     Root\r\n\
	*        18     172.18.64.0/19           red1 192.168.202.209   S   20      1     Root\r\n\
	*        17   192.168.180.0/22         eth3/1 192.168.202.217   S   20      1     Root\r\n\
	*        11 192.168.202.201/32           red2         0.0.0.0   H    0      0     Root\r\n\
	*         2       172.1.0.0/18            mgt         0.0.0.0   C    0      0     Root\r\n\
	*        10 192.168.202.200/29           red2         0.0.0.0   C    0      0     Root\r\n\
	*         8 192.168.202.208/29           red1         0.0.0.0   C    0      0     Root\r\n\
	*        12     172.25.32.0/19           red1 192.168.202.209   S   20      1     Root\r\n\
	*         9 192.168.202.212/32           red1         0.0.0.0   H    0      0     Root\r\n\
	*        22     172.23.32.0/19           red1 192.168.202.209   S   20      1     Root\r\n\
	*         4 192.168.202.216/29         eth3/1         0.0.0.0   C    0      0     Root\r\n\
	*         5 192.168.202.220/32         eth3/1         0.0.0.0   H    0      0     Root");

	vector<string>	serial_chain;
	vector<string>	temperature_chain;

	//Temperature_3560_1
	serial_chain.push_back("3560");
	temperature_chain.push_back(
			"FAN is OK\r\n\
TEMPERATURE is OK\r\n\
SW  PID                 Serial#     Status           Sys Pwr  PoE Pwr  Watts\r\n\
--  ------------------  ----------  ---------------  -------  -------  -----\r\n\
1  Built-in                                         Good\r\n\
\r\n\
SW  Status          RPS Name          RPS Serial#  RPS Port#\r\n\
--  -------------   ----------------  -----------  ---------\r\n\
1   Not Present     <>");

	//Temperature_3750_1
	serial_chain.push_back("3750");
	temperature_chain.push_back(
			"FAN is OK\r\n\
TEMPERATURE is OK\r\n\
Temperature Value: 46 Degree Celsius\r\n\
Temperature State: GREEN\r\n\
Yellow Threshold : 56 Degree Celsius\r\n\
Red Threshold    : 66 Degree Celsius\r\n\
SW  PID                 Serial#     Status           Sys Pwr  PoE Pwr  Watts\r\n\
--  ------------------  ----------  ---------------  -------  -------  -----\r\n\
1  Built-in                                         Good\r\n\
\r\n\
SW  Status          RPS Name          RPS Serial#  RPS Port#\r\n\
--  -------------   ----------------  -----------  ---------\r\n\
1   Not Present     <>");

	//Temperature_1004
	serial_chain.push_back("1004");
	temperature_chain.push_back(
			"\r\n\
Number of Critical alarms:  10\r\n\
Number of Major alarms:     20\r\n\
Number of Minor alarms:     30\r\n\
\r\n\
Slot    Sensor       Current State       Reading\r\n\
----    ------       -------------       -------\r\n\
F0    V1: VMA          Normal           1796 mV\r\n\
F0    V1: VMB          Normal           1196 mV\r\n\
F0    V1: VMC          Normal           1196 mV\r\n\
F0    V1: VMD          Normal           1098 mV");

	//Temperature_4503_1
	serial_chain.push_back("4503");
	temperature_chain.push_back("no temperature alarms");

	//Temperature_3825_1
	serial_chain.push_back("3825");
	temperature_chain.push_back(
			"Redundant Power System is not present.\r\n\
\r\n\
SYS PS1 is present.\r\n\
Type: AC\r\n\
\r\n\
	  AUX(-48V) PS1 is absent.\r\n\
\r\n\
	  Fan  1 Normal\r\n\
	  Fan  2 Normal\r\n\
	  Fan  3 Normal\r\n\
\r\n\
	  Fan Speed is Normal\r\n\
\r\n\
	  Alert settings:\r\n\
Intake temperature warning: Enabled, Threshold: 55\r\n\
Core temperature warning: Enabled, Threshold: 70 (CPU: 95)\r\n\
\r\n\
Board Temperature: Normal\r\n\
Internal-ambient temperature = 25, Normal\r\n\
CPU temperature = 42, Normal\r\n\
Intake temperature = 26, Normal\r\n\
\r\n\
Voltage 1(3300) is Normal, Current voltage = 3300 mV \r\n\
Voltage 2(5150) is Normal, Current voltage = 5153 mV \r\n\
Voltage 3(2500) is Normal, Current voltage = 2525 mV \r\n\
Voltage 4(1200) is Normal, Current voltage = 1215 mV \r\n\
\r\n\
Nominal frequency");

	//Temperature_3945_1
	serial_chain.push_back("3945");
	temperature_chain.push_back(
			"SYSTEM POWER SUPPLY STATUS\r\n\
==========================\r\n\
 Internal Power Supply 1 Type: AC\r\n\
 Internal Power Supply 1 12V Output Status: Normal\r\n\
\r\n\
 Internal Power Supply 2 Type: AC\r\n\
 Internal Power Supply 2 12V Output Status: Normal\r\n\
\r\n\
SYSTEM FAN STATUS\r\n\
=================\r\n\
 Fan 1 OK, Low speed setting\r\n\
 Fan 2 OK, Low speed setting\r\n\
 Fan 3 OK, Low speed setting\r\n\
 Fan 4 OK, Low speed setting\r\n\
 Fan 5 OK, Low speed setting\r\n\
\r\n\
SYSTEM TEMPERATURE STATUS\r\n\
=========================\r\n\
 Intake Left temperature: 16 Celsius, Normal\r\n\
 Intake Right temperature: 18 Celsius, Normal\r\n\
 Exhaust Right temperature: 17 Celsius, Normal\r\n\
 Exhaust Left temperature: 18 Celsius, Normal\r\n\
 CPU temperature: 50 Celsius, Normal\r\n\
 Power Supply Unit 1 temperature: 18 Celsius, Normal\r\n\
 Power Supply Unit 2 temperature: 20 Celsius, Normal\r\n\
\r\n\
REAL TIME CLOCK BATTERY STATUS\r\n\
==============================\r\n\
 Battery OK (checked at power up)\r\n\
\r\n\
SYSTEM POWER\r\n\
===============\r\n\
 Motherboard Components Power consumption = 142.7 W\r\n\
 NM/SM slot 3 Power consumption = 8.3 W\r\n\
 Total System Power consumption is: 151.0 W\r\n\
\r\n\
 Environmental information last updated 00:00:28 ago");

	//Temperature_5350_1
	serial_chain.push_back("5350");
	temperature_chain.push_back(
			"Temperature:\r\n\
Temperature Reading:\r\n\
Temp at inlet is measured as 24C/75F.\r\n\
Temp at outlet is measured as 33C/91F.\r\n\
Temp delta of inlet and outlet is measured as 9C/48F.\r\n\
Temperature State:\r\n\
Temperature is in normal state.\r\n\
\r\n\
Voltage:\r\n\
Voltage Reading:\r\n\
MAX6656-1 Internal 3.3 Volt is measured as 3259.\r\n\
Motherbd 5V is measured as 5171.\r\n\
CPU Core 1.2V is measured as 1136.\r\n\
Memory 2.5V is measured as 2464.\r\n\
MAX6656-2 Internal 3.3 Volt is measured as 3243.\r\n\
PHY 2.5V is measured as 2601.\r\n\
HT, Crush FPGA 1.8V is measured as 1786.\r\n\
PLD 1.5V is measured as 1419.\r\n\
Voltage State:\r\n\
Voltage is in 0 state.\r\n\
\r\n\
Power Supply:\r\n\
Redundant Power System is not present.\r\n\
PS Input Voltage status:  normal\r\n\
PS Output Voltage status:  normal\r\n\
PS Fan status:  normal\r\n\
PS Thermal status:  normal\r\n\
PS OverVoltage status:  normal");

	//Temperature_7304_1
	serial_chain.push_back("7304");
	temperature_chain.push_back(
			"Temperature information:\r\n\
Active RP (NPEG100, slot 0):\r\n\
All measured readings are normal \r\n\
Standby RP (NPEG100, slot 2):\r\n\
All measured readings are normal \r\n\
Line card (1PA Carrier Card, slot 4):\r\n\
All measured readings are normal \r\n\
Voltage information:\r\n\
Active RP (NPEG100, slot 0):\r\n\
All measured readings are normal \r\n\
Standby RP (NPEG100, slot 2):\r\n\
All measured readings are normal \r\n\
Line card (1PA Carrier Card, slot 4):\r\n\
All measured readings are normal \r\n\
Fan 1 is on\r\n\
Fan 2 is on");

	int manufactory_id = 1;
	string	deviceip;
	string	deviceserial;

	resultField.ObjectID = "ZhangJ.SC.ZJ-SC6504-A1-2N607";

	int failnum = 0;

	for (int i = 0; i < instruction_chain_1.size(); ++i)
	{
		resultField.InstructChain = instruction_chain_1[i].c_str();

		string	oldresult = result_chain_1[i].c_str();
		string	newresult;

		resultField.Flag = TASK_SUCCESS;

		CEventCounterServer::RegularParseResult(
				resultField,
				oldresult,
				newresult,
				manufactory_id,
				deviceip,
				deviceserial);
		if (resultField.Flag.getValue() != TASK_SUCCESS)
		{
			printf(
				"instruction:%s parse fail, manufactory_id=%d!\n",
				resultField.InstructChain.getValue(),
				manufactory_id);
			++failnum;
		}
	}

	for (int i = 0; i < serial_chain.size(); ++i)
	{
		resultField.InstructChain = "EnvInfo";
		deviceserial = serial_chain[i];

		string	oldresult = temperature_chain[i].c_str();
		string	newresult;

		resultField.Flag = TASK_SUCCESS;

		CEventCounterServer::RegularParseResult(
				resultField,
				oldresult,
				newresult,
				manufactory_id,
				deviceip,
				deviceserial);
		if (resultField.Flag.getValue() != TASK_SUCCESS)
		{
			printf(
				"instruction:%s parse fail, manufactory_id=%d, deviceserial=%s!\n",
				resultField.InstructChain.getValue(),
				manufactory_id,
				deviceserial.c_str());
			++failnum;
		}
	}

	manufactory_id = 3;
	for (int i = 0; i < instruction_chain_3.size(); ++i)
	{
		resultField.InstructChain = instruction_chain_3[i].c_str();

		string	oldresult = result_chain_3[i].c_str();
		string	newresult;

		resultField.Flag = TASK_SUCCESS;

		CEventCounterServer::RegularParseResult(
				resultField,
				oldresult,
				newresult,
				manufactory_id,
				deviceip,
				deviceserial);
		if (resultField.Flag.getValue() != TASK_SUCCESS)
		{
			printf(
				"instruction:%s parse fail, manufactory_id=%d!\n",
				resultField.InstructChain.getValue(),
				manufactory_id);
			++failnum;
		}
	}

	manufactory_id = 4;
	for (int i = 0; i < instruction_chain_4.size(); ++i)
	{
		resultField.InstructChain = instruction_chain_4[i].c_str();

		string	oldresult = result_chain_4[i].c_str();
		string	newresult;

		resultField.Flag = TASK_SUCCESS;

		CEventCounterServer::RegularParseResult(
				resultField,
				oldresult,
				newresult,
				manufactory_id,
				deviceip,
				deviceserial);
		if (resultField.Flag.getValue() != TASK_SUCCESS)
		{
			printf(
				"instruction:%s parse fail, manufactory_id=%d!\n",
				resultField.InstructChain.getValue(),
				manufactory_id);
			++failnum;
		}
	}

	int totalnum = instruction_chain_1.size() +
		instruction_chain_4.size() +
		serial_chain.size();
	if (totalnum > 0)
	{
		printf(
			"success rate is %.2f%%\n",
			100 * (float)(totalnum - failnum) / totalnum);
	}

	return 0;
}

CConfigConnector::CConfigConnector(CReactor *pReactor) :
	CSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_Flag = false;
	m_pSession = NULL;

	/*
	///test code start
	CFTDSysNetDeviceField field;
	field.ID = 2;
	
	field.ObjectID = "ZJ.OAE.T-MN3750-B1_1B2_1-2M501";
	field.IPADDR = "172.1.128.1";

	m_devs[2] = field;

	BaseLineInfo baseinfo;
	baseinfo.name = "123";
	baseinfo.data = "service tcp-keepalives-in\n\
\n\
service tcp-keepalives-out\n\
\n\
service timestamps debug datetime msec localtime show-timezone\n\
\n\
service timestamps log datetime msec localtime show-timezone\n\
\n\
service password-encryption\n\
\n\
service sequence-numbers\n\
\n\
logging buffered 512000\n\
\n\
- logging console\n\
\n\
username rsfw password $* $*\n\
\n\
aaa new-model\n\
\n\
aaa authentication login userauth group tacacs+ local\n\
\n\
aaa authentication login no_tacacs local\n\
\n\
aaa authentication enable default group tacacs+ enable\n\
\n\
aaa authorization exec default group tacacs+ local\n\
aaa authorization commands 1 default group tacacs+ local\n\
aaa authorization commands 15 default group tacacs+ local\n\
\n\
aaa accounting exec default start-stop group tacacs+\n\
aaa accounting commands 1 default start-stop group tacacs+\n\
aaa accounting commands 15 default start-stop group tacacs+\n\
\n\
aaa session-id common\n\
\n\
clock timezone BJ 8\n\
\n\
ip subnet-zero\n\
\n\
no ip gratuitous-arps\n\
\n\
no ip domain-lookup\n\
\n\
no ip source-route\n\
\n\
ip classless\n\
\n\
no ip http server\n\
\n\
no ip http secure-server\n\
\n\
ip domain-name shfe.com.cn\n\
\n\
ip ssh version 2\n\
\n\
logging history size 200\n\
\n\
- logging trap\n\
\n\
logging 172.1.0.57\n\
\n\
logging 172.1.32.57\n\
\n\
logging 172.1.0.59\n\
\n\
logging 172.1.32.59\n\
\n\
access-list 88 permit 172.1.0.0 0.0.255.255\n\
\n\
snmp-server community thbczh2005 RO 88\n\
\n\
- snmp-server enable traps\n\
\n\
tacacs-server host 172.1.32.65\n\
tacacs-server host 172.1.0.65\n\
tacacs-server timeout 3\n\
tacacs-server directed-request\n\
tacacs-server key 7 $*\n\
\n\
ip access-list standard TelnetAuth\n\
 permit 172.1.0.0 0.0.255.255\n\
\n\
line con 0\n\
 exec-timeout 30 0\n\
 logging synchronous\n\
 login authentication no_tacacs\n\
\n\
line vty 0 4\n\
 access-class TelnetAuth in\n\
 exec-timeout 30 0\n\
 logging synchronous\n\
 login authentication userauth\n\
 transport input ssh\n\
\n\
line vty 5 15\n\
 access-class TelnetAuth in\n\
 exec-timeout 30 0\n\
 logging synchronous\n\
 login authentication userauth\n\
 transport input ssh\n\
\n\
ntp authentication-key 2 md5 $* $*\n\
ntp authenticate\n\
ntp trusted-key 2\n\
\n\
ntp server 172.1.0.51 prefer\n\
ntp server 172.1.0.52";

	m_baselines[1] = baseinfo;
	///test code end
*/
}

CSession *CConfigConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CConfigConnector::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);

	time_t	timep;
	time(&timep);

	printf(
		"\t %s CConfigConnector::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	m_Flag = true;

	m_pSession = (CFTDCSession *)pSession;

	// 测试和配置管理服务的连通性及数据包处理 20110112
	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "eventcounter";
	fieldLogin.Password = "eventcounter";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

	//清空数据容器
	m_mExprTaskList.clear();
	m_loopitem.clear();
	m_warnexprs.clear();
	m_attr_devs.clear();
}

void CConfigConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	time_t	timep;
	time(&timep);

	printf(
		"\t %s CConfigConnector::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);

	m_Flag = false;
	m_pSession = NULL;

	m_baselines.clear();
}

int CConfigConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput_config);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput_config);
#endif

	//printf("\tCConfigConnector::HandlePackage:receive package %0x\n",pFTDCPackage->GetTID());
	fflush(stdout);

	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;

		//区域名
		case FTD_TID_RtnNetAreaTopic:
			OnRtnNetAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetAreaTopic:
			OnRspNetAreaTopic(pFTDCPackage, pSession);
			break;

		//子网名
		case FTD_TID_RtnNetSubAreaTopic:
			OnRtnNetSubAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetSubAreaTopic:
			OnRspNetSubAreaTopic(pFTDCPackage, pSession);
			break;

		//子网IP
		case FTD_TID_RtnNetSubAreaIPTopic:
			OnRtnNetSubAreaIPTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetSubAreaIPTopic:
			OnRspNetSubAreaIPTopic(pFTDCPackage, pSession);
			break;

		//厂商
		case FTD_TID_RtnNetManufactoryTopic:
			OnRtnDevManuTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetManufactoryTopic:
			OnRspDevManuTopic(pFTDCPackage, pSession);
			break;

		//设备类型
		case FTD_TID_RtnNetDeviceCategoryTopic:
			OnRtnDevTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceCategoryTopic:
			OnRspDevTypeTopic(pFTDCPackage, pSession);
			break;

		//设备型号
		case FTD_TID_RtnNetDeviceTypeTopic:
			OnRtnDevSerialTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceTypeTopic:
			OnRspDevSerialTopic(pFTDCPackage, pSession);
			break;

		//共同体
		case FTD_TID_RtnNetCommunityTopic:
			OnRtnNetCommTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetCommunityTopic:
			OnRspNetCommTopic(pFTDCPackage, pSession);
			break;

		//MIB OID
		case FTD_TID_RtnNetOIDTopic:
			OnRtnMIBOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetOIDTopic:
			OnRspMIBOIDTopic(pFTDCPackage, pSession);
			break;

		//通用OID
		case FTD_TID_RspQryNetGeneralOIDTopic:
			OnRspGenMIBOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetGeneralOIDTopic:
			OnRtnGenMIBOIDTopic(pFTDCPackage, pSession);
			break;

		//时间策略
		case FTD_TID_RspQryNetTimePolicyTopic:
			OnRspTimePolicyTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetTimePolicyTopic:
			OnRtnTimePolicyTopic(pFTDCPackage, pSession);
			break;

		//设备信息
		case FTD_TID_RspQryNetDeviceTopic:
			OnRspNetDeviceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceTopic:
			OnRtnNetDeviceTopic(pFTDCPackage, pSession);
			break;

		//设备变更信息
		case FTD_TID_RspQryNetDeviceChgTopic:
			OnRspChgNetDeviceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceChgTopic:
			OnRtnChgNetDeviceTopic(pFTDCPackage, pSession);
			break;

		//接口信息
		case FTD_TID_RspQryNetInterfaceTopic:
			OnRspNetInterfaceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetInterfaceTopic:
			OnRtnNetIntefaceTopic(pFTDCPackage, pSession);
			break;

		//监控对象类别
		case FTD_TID_RspQryNetMonitorTypeTopic:
			OnRspMonitorTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTypeTopic:
			OnRtnMonitorTypeTopic(pFTDCPackage, pSession);
			break;

		//监控指标
		case FTD_TID_RspQryNetMonitorAttrTypeTopic:
			OnRspMonitorAttrTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorAttrTypeTopic:
			OnRtnMonitorAttrTypeTopic(pFTDCPackage, pSession);
			break;

		//告警表达式
		case FTD_TID_RspQryNetEventExprTopic:
			OnRspNetEventExprTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetEventExprTopic:
			OnRtnNetEventExprTopic(pFTDCPackage, pSession);
			break;

		//巡检任务
		case FTD_TID_RspQryNetMonitorTaskInfoTopic:
			OnRspLoopItemTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskInfoTopic:
			OnRtnLoopItemTopic(pFTDCPackage, pSession);
			break;

		//设备对象组明细
		case FTD_TID_RspQryNetMonitorTaskObjectSetTopic:
			OnRspQryNetMonitorTaskObjectSetTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskObjectSetTopic:
			OnRtnNetMonitorTaskObjectSetTopic(pFTDCPackage, pSession);
			break;

		//模块信息
		case FTD_TID_RspQryNetModuleTopic:
			OnRspNetModuleTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetModuleTopic:
			OnRtnNetModuleTopic(pFTDCPackage, pSession);
			break;

		//告警事件
		case FTD_TID_RtnWarningEventTopic:
			OnRtnWarningEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnSyslogEventTopic:
			OnRtnSyslogEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningEventUpdateTopic:
			OnReqQryWarningEventUpdate(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningActiveChange:
			OnReqQryWarningEventActiveChange(pFTDCPackage, pSession);
			break;

		//任务命令的结果分析规则	
		case FTD_TID_RspQryNetMonitorDeviceTaskTopic:
			OnRspDeviceTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorDeviceTaskTopic:
			OnRtnDeviceTaskTopic(pFTDCPackage, pSession);
			break;

		//任务命令对应的指标列表
		case FTD_TID_RspQryNetMonitorTaskInstAttrsTopic:
			OnRspTaskCmdAttrListTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskInstAttrsTopic:
			OnRtnTaskCmdAttrListTopic(pFTDCPackage, pSession);
			break;

		//设备基线列表
		case FTD_TID_RspQryNetBaseLineTopic:
			OnRspBaseLineTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetBaseLineTopic:
			OnRtnBaseLineTopic(pFTDCPackage, pSession);
			break;

		//会员链路信息
		case FTD_TID_RspQryNetPartyLinkInfoTopic:
			OnRspPartyLinkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetPartyLinkInfoTopic:
			OnRtnPartyLinkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetRoomTopic:
			OnReqQryNetRoomTopic(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

void CConfigConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(
		"\t CConfigConnector::OnRspUserLogin:user=%s password=%s ",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "成功";
	fieldRspInfo.ErrorID = 0;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldRspInfo);
	printf(
		" reponse msg %s ID %d\n",
		(const char *)fieldRspInfo.ErrorMsg,
		(const int)fieldRspInfo.ErrorID);

	/////test//////
	//test_task();
}

/*
//接收网络大区划分信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspNetAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetAreaField	field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetAreaField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetAreaField fielddata;

		fielddata.ID = field.ID;
		fielddata.CName = field.CName;
		fielddata.EName = field.EName;
		fielddata.m_Describe = field.m_Describe;

		m_sysNets[fielddata.ID.getValue()] = fielddata;

		//添加到对象树中
		g_pDataCenter->addAppIdName(
				(char *)field.EName.getValue(),
				(char *)field.CName.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = field.EName;
		objecttree.CName = field.CName;

		AddNetMonitorObjectTree(objecttree);

		itor.Next();
	}

	printf("receive NetArea information:[%d] records. \n", m_sysNets.size());
}

void CConfigConnector::OnRtnNetAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetAreaField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetAreaField fielddata;
	fielddata.ID = field.ID;
	fielddata.CName = field.CName;
	fielddata.EName = field.EName;
	fielddata.m_Describe = field.m_Describe;

	m_sysNets[fielddata.ID.getValue()] = fielddata;

	//添加到对象树中
	g_pDataCenter->addAppIdName(
			(char *)field.EName.getValue(),
			(char *)field.CName.getValue());

	CFTDRtnNetAreaField objecttree;
	memset(&objecttree, 0, sizeof(objecttree));

	objecttree.ID = EVENT_FLAG_GREEN;
	objecttree.EName = field.EName;
	objecttree.CName = field.CName;

	AddNetMonitorObjectTree(objecttree);
}

/*
//接收网络子区配置信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspNetSubAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetSubAreaField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetSubAreaField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetSubAreaField	fielddata;
		fielddata.ID = field.ID;
		fielddata.SysNetAreaID = field.SysNetAreaID;
		fielddata.CName = field.CName;
		fielddata.EName = field.EName;
		fielddata.m_Describe = field.m_Describe;

		m_sysNetSubs[fielddata.ID.getValue()] = fielddata;

		//添加到对象树中
		NET_AREA_MAP_ITERATOR n_it = m_sysNets.find(
				field.SysNetAreaID.getValue());
		if (n_it != m_sysNets.end())
		{
			string	objectid = n_it->second.EName.getValue();
			objectid += ".";
			objectid += field.EName.getValue();

			g_pDataCenter->addAppIdName(
					(char *)objectid.c_str(),
					(char *)field.CName.getValue());

			CFTDRtnNetAreaField objecttree;
			memset(&objecttree, 0, sizeof(objecttree));

			objecttree.ID = EVENT_FLAG_GREEN;
			objecttree.EName = objectid.c_str();
			objecttree.CName = field.CName;

			AddNetMonitorObjectTree(objecttree);
		}
		else
		{
			printf(
				"can't find area by areaid:%d in %s\n",
				field.SysNetAreaID.getValue(),
				__FUNCTION__);
		}

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetSubAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetSubAreaField	field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetSubAreaField	fielddata;

	fielddata.ID = field.ID;
	fielddata.SysNetAreaID = field.SysNetAreaID;
	fielddata.CName = field.CName;
	fielddata.EName = field.EName;
	fielddata.m_Describe = field.m_Describe;

	m_sysNetSubs[fielddata.ID.getValue()] = fielddata;

	//添加到对象树中
	NET_AREA_MAP_ITERATOR n_it = m_sysNets.find(field.SysNetAreaID.getValue());
	if (n_it != m_sysNets.end())
	{
		string	objectid = n_it->second.EName.getValue();
		objectid += ".";
		objectid += field.EName.getValue();

		g_pDataCenter->addAppIdName(
				(char *)objectid.c_str(),
				(char *)field.CName.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = objectid.c_str();
		objecttree.CName = field.CName;

		AddNetMonitorObjectTree(objecttree);
	}
	else
	{
		printf(
			"can't find area by areaid:%d in %s\n",
			field.SysNetAreaID.getValue(),
			__FUNCTION__);
	}
}

/*
//接收子网络配置信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspNetSubAreaIPTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetSubAreaIPField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetSubAreaIPField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetSubAreaIPField fielddata;

		fielddata.ID = field.ID;
		fielddata.SysNetSubAreaID = field.SysNetSubAreaID;
		fielddata.IP = field.IP;
		fielddata.Mask = field.Mask;
		fielddata.m_Describe = field.m_Describe;

		m_sysNetSubIPs[fielddata.ID.getValue()] = fielddata;

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetSubAreaIPTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetSubAreaIPField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetSubAreaIPField fielddata;

	fielddata.ID = field.ID;
	fielddata.SysNetSubAreaID = field.SysNetSubAreaID;
	fielddata.IP = field.IP;
	fielddata.Mask = field.Mask;
	fielddata.m_Describe = field.m_Describe;

	m_sysNetSubIPs[fielddata.ID.getValue()] = fielddata;
}

/*
//接收设备厂商
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspDevManuTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetManufactoryField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetManufactoryField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetManufactoryField	val;

		val.ID = field.ID;
		val.EName = field.EName;
		val.CName = field.CName;

		m_devmanus[strlwr(
				(char *)field.EName.getValue(),
				strlen(field.EName.getValue()))] = val;

		itor.Next();
	}
}

void CConfigConnector::OnRtnDevManuTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetManufactoryField	field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	DEV_MANUFACTORY_MAP_ITERATOR it;

	switch (field.OperationType.getValue()) ///1,2,3,4  代表: 查/增/删/改
	{
		case 1:
			break;
		case 3:
			it = m_devmanus.find(
					strlwr(
						(char *)field.EName.getValue(),
						strlen(field.EName.getValue())));
			if (it != m_devmanus.end())
			{
				m_devmanus.erase(it);
			}

			break;
		case 2:
		case 4:
			CFTDSysNetManufactoryField val;

			val.ID = field.ID;
			val.EName = field.EName;
			val.CName = field.CName;

			m_devmanus[strlwr(
					(char *)field.EName.getValue(),
					strlen(field.EName.getValue()))] = val;

			break;
	}
}

/*
//接收设备类型信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspDevTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetDeviceCategoryField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetDeviceCategoryField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetDeviceCategoryField val;

		val.ID = field.ID;
		val.CName = field.CName;
		val.EName = field.EName;

		m_devtypes[strlwr(
				(char *)field.EName.getValue(),
				strlen(field.EName.getValue()))] = val;

		itor.Next();
	}
}

void CConfigConnector::OnRtnDevTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetDeviceCategoryField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	DEV_TYPE_MAP_ITERATOR it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 3:
			it = m_devtypes.find(
					strlwr(
						(char *)field.EName.getValue(),
						strlen(field.EName.getValue())));
			if (it != m_devtypes.end())
			{
				m_devtypes.erase(it);
			}

			break;
		case 2:
		case 4:
			CFTDSysNetDeviceCategoryField val;

			val.ID = field.ID;
			val.CName = field.CName;
			val.EName = field.EName;

			m_devtypes[strlwr(
					(char *)field.EName.getValue(),
					strlen(field.EName.getValue()))] = val;

			break;
	}
}

/*
//接收网络设备型号信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspDevSerialTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetDeviceTypeField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetDeviceTypeField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetDeviceTypeField val;

		val.ID = field.ID;
		val.Manufactory = field.Manufactory;
		val.DeviceType = field.DeviceType;

		m_devserials[val.ID.getValue()] = val;

		itor.Next();
	}
}

void CConfigConnector::OnRtnDevSerialTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetDeviceTypeField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	DEV_SERIAL_MAP_ITERATOR it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 3:
			it = m_devserials.find(field.ID.getValue());
			if (it != m_devserials.end())
			{
				m_devserials.erase(it);
			}

			break;
		case 2:
		case 4:
			CFTDSysNetDeviceTypeField val;

			val.ID = field.ID;
			val.DeviceType = field.DeviceType;
			val.Manufactory = field.Manufactory;

			m_devserials[val.ID.getValue()] = val;

			break;
	}
}

/*
//接收网络通信关键字
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspNetCommTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetCommunityField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryNetCommunityField::m_Describe);

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		m_comms[field.IPADDR.getValue()] = field.COMMUNITY.getValue();

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetCommTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetCommunityField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	m_comms[field.IPADDR.getValue()] = field.COMMUNITY.getValue();
}

/*
//接收厂商oid信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetOIDField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetOIDField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetOIDField	oid_value;

		oid_value.EName = field.EName;
		oid_value.OID = field.OID;
		oid_value.Manufactory = field.Manufactory;
		oid_value.DeviceType = field.DeviceType;
		oid_value.Unit = field.Unit;
		oid_value.isTheTable = field.isTheTable;

		string	key = field.EName.getValue();
		key += CONSYM;
		key.append(
				strlwr(
					(char *)field.Manufactory.getValue(),
					strlen(field.Manufactory.getValue())));

		if (!field.DeviceType.isNull())
		{
			key += CONSYM;
			key.append(
					strlwr(
						(char *)field.DeviceType.getValue(),
						strlen(field.DeviceType.getValue())));
		}

		m_oids[key] = oid_value;

		itor.Next();
	}
}

void CConfigConnector::OnRtnMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetOIDField	field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 3:
			break;
		case 2:
		case 4:
			CFTDSysNetOIDField oid_value;

			oid_value.EName = field.EName;
			oid_value.OID = field.OID;
			oid_value.Manufactory = field.Manufactory;
			oid_value.DeviceType = field.DeviceType;
			oid_value.Unit = field.Unit;
			oid_value.isTheTable = field.isTheTable;

			string	key = field.EName.getValue();
			key += CONSYM;
			key.append(
					strlwr(
						(char *)field.Manufactory.getValue(),
						strlen(field.Manufactory.getValue())));

			if (!field.DeviceType.isNull())
			{
				key += CONSYM;
				key.append(
						strlwr(
							(char *)field.DeviceType.getValue(),
							strlen(field.DeviceType.getValue())));
			}

			m_oids[key] = oid_value;
			break;
	}
}

/*
//接收通用的oid信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspGenMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetGeneralOIDField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetGeneralOIDField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		/*todo
		SInfoOID  oid_value;

		oid_value.Name = field.OID.getValue();
		oid_value.is_table = field.isTable.getValue()?true:false;

		m_genoids[ field.EName.getValue() ] = oid_value;
*/
		itor.Next();
	}
}

void CConfigConnector::OnRtnGenMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetGeneralOIDField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 3:
			break;
		case 2:
		case 4:
			/*todo		SInfoOID  oid_value;

		oid_value.Name = field.OID.getValue();
		oid_value.is_table = field.isTable.getValue()?true:false;

		m_genoids[ field.EName.getValue() ] = oid_value;
*/
			break;
	}
}

/*
//接收网络设备信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspNetDeviceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetDeviceField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetDeviceField::m_Describe));
	CFTDSysNetDeviceField dev;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetDeviceEntity(&dev, &field);

		m_devs[dev.ID.getValue()] = dev;

		g_DevIPList[field.ObjectID.getValue()] = field.IPADDR.getValue();

		m_dev_objids[field.ObjectID.getValue()] = dev.ID.getValue();

		//todo	g_TaskInfoManager.AddDeviceInfo(dev);
		//添加到对象树中	
		g_pDataCenter->addAppIdName(
				(char *)field.ObjectID.getValue(),
				(char *)field.NAME.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = field.ObjectID;
		objecttree.CName = field.NAME;

		AddNetMonitorObjectTree(objecttree);

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetDeviceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetDeviceField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetDeviceField dev;
	NET_DEVICE_MAP_ITERATOR it;
	map<string, int>::iterator	mapIt;
	map<string, string>::iterator g_i;

	CopySysNetDeviceEntity(&dev, &field);

	//todo	g_TaskInfoManager.UpdDeviceInfo(dev, field.OperationType.getValue());
	switch (field.OperationType.getValue())
	{
		case 2:
			CopySysNetDeviceEntity(&dev, &field);

			m_devs[dev.ID.getValue()] = dev;

			g_DevIPList[field.ObjectID.getValue()] = field.IPADDR.getValue();

			m_dev_objids[field.ObjectID.getValue()] = dev.ID.getValue();
			break;
		case 3:
			it = m_devs.find(field.ID.getValue());
			if (it != m_devs.end())
			{
				m_devs.erase(it);
				m_dev_objids.erase(field.ObjectID.getValue());
			}

			g_i = g_DevIPList.find(field.ObjectID.getValue());
			if (g_i != g_DevIPList.end())
			{
				g_DevIPList.erase(g_i);
			}

			/* todo
		mapIt = g_mapDeviceNo.find(field.ObjectID.getValue());
		if (mapIt != g_mapDeviceNo.end())
		{
			int iDeviceNo = mapIt->second -1;
		//todo	g_Devices[iDeviceNo].m_bValid = false;
		}
*/
			//todo 更新对象树，删除子节点数据
			break;
		case 4:
			it = m_devs.find(field.ID.getValue());
			if (it != m_devs.end())
			{
				if (strcmp(
						it->second.IPADDR.getValue(),
					field.IPADDR.getValue()) != 0)
				{
					m_dev_objids.erase(it->second.ObjectID.getValue());
					m_dev_objids[field.ObjectID.getValue()] = field.ID.getValue();

					g_DevIPList[field.ObjectID.getValue()] = field.IPADDR.getValue();
				}

				CopySysNetDeviceEntity(&(it->second), &field);
			}

			/*
		mapIt = g_mapDeviceNo.find(field.ObjectID.getValue());
		int iDeviceNo;
		list<string> CmdList;
		CmdList.push_back("term length 0");
		CmdList.push_back("show running-config");

		if (mapIt != g_mapDeviceNo.end())
		{
			iDeviceNo = mapIt->second -1;
		}
		else
		{
			iDeviceNo = g_nDeviceNo;
			g_nDeviceNo++;
			g_Devices[iDeviceNo].SetPath(TMP_DIRNAME);
			g_Devices[iDeviceNo].SetJudgeRun(CJudgeRun(DEFAULT_TIMESEP));
		}
		g_Devices[iDeviceNo].SetObjectIDName(CObjectIDName(field.ObjectID.getValue()));
		g_Devices[iDeviceNo].SetTelnetConnEntry(CTelnetConnEntry(field.ObjectID.getValue(), 23, ssh, field.USERNAME.getValue(),
			field.PASSWD.getValue(), field.ENPASSWD.getValue(), CmdList));
*/
			break;
		default:
			return;
	}

	if (field.OperationType.getValue() % 2 == 0)
	{
		//添加到对象树中
		g_pDataCenter->addAppIdName(
				(char *)field.ObjectID.getValue(),
				(char *)field.NAME.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = field.ObjectID;
		objecttree.CName = field.NAME;

		AddNetMonitorObjectTree(objecttree);
	}

	/*
	//wei.c modify, 计算attr管理你的设备、接口、模块信息	
	PrepareExprData();

	//wei.c modify, update expression
	if(g_mExprAnalysis)
	{		
		g_mExprAnalysis->generateObjectExpr(m_mExprTaskList, m_attr_devs, m_warnexprs);
	}		
*/
}

void CConfigConnector::OnRspBaseLineTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetBaseLineField	field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetBaseLineField::m_Describe));
	CFTDSysNetBaseLineField baseline;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetBaseLineEntity(&baseline, &field);

		NET_BASELINE_MAP_ITERATOR it = m_baselines.find(baseline.ID.getValue());
		if (it == m_baselines.end())
		{
			BaseLineInfo baseinfo;

			baseinfo.name = baseline.Name.getValue();
			baseinfo.data = baseline.data.getValue();
			baseinfo.flag = baseline.Flag.getValue();

			m_baselines[baseline.ID.getValue()] = baseinfo;
		}
		else
		{
			it->second.data += baseline.data.getValue();
			it->second.flag = baseline.Flag.getValue();
		}

		itor.Next();
	}
}

void CConfigConnector::OnRtnBaseLineTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetBaseLineField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetBaseLineField baseline;
	CopySysNetBaseLineEntity(&baseline, &field);

	NET_BASELINE_MAP_ITERATOR it;
	BaseLineInfo baseinfo;

	switch (field.OperationType.getValue())
	{
		case 2:
			it = m_baselines.find(baseline.ID.getValue());
			if (it == m_baselines.end())
			{
				baseinfo.name = baseline.Name.getValue();
				baseinfo.data = baseline.data.getValue();
				baseinfo.flag = baseline.Flag.getValue();

				m_baselines[baseline.ID.getValue()] = baseinfo;
			}
			else
			{
				it->second.data += baseline.data.getValue();
				it->second.flag = baseline.Flag.getValue();
			}

			break;
		case 3:
			it = m_baselines.find(baseline.ID.getValue());
			if (it != m_baselines.end())
			{
				m_baselines.erase(it);
			}

			break;
		case 4:
			it = m_baselines.find(baseline.ID.getValue());
			if (it != m_baselines.end())
			{
				if (it->second.flag != 0)
				{
					//内存中的是完整包(老数据)
					m_baselines.erase(it);

					baseinfo.name = baseline.Name.getValue();
					baseinfo.data = baseline.data.getValue();
					baseinfo.flag = baseline.Flag.getValue();

					m_baselines[baseline.ID.getValue()] = baseinfo;
				}
				else
				{
					//内存中的是中间包(新数据)
					it->second.data += baseline.data.getValue();
					it->second.flag = baseline.Flag.getValue();
				}
			}

			break;
		default:
			return;
	}
}

void CConfigConnector::OnRspPartyLinkInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetPartyLinkInfoField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetPartyLinkInfoField::m_Describe));
	CFTDSysNetPartyLinkInfoField partylink;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetPartyLinkInfoEntity(&partylink, &field);

		if (strlen(partylink.IPADDR.getValue()) > 0
		&&	strlen(partylink.Interface.getValue()) > 0)
		{
			string	key = partylink.IPADDR.getValue();
			key += "_";
			key += partylink.Interface.getValue();

			m_partylinkinfo[key] = partylink;
		}

		itor.Next();
	}
}

void CConfigConnector::OnRtnPartyLinkInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetPartyLinkInfoField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetPartyLinkInfoField partylink;
	CopySysNetPartyLinkInfoEntity(&partylink, &field);

	MAP_PARTYLINK_INFO_IT it;

	switch (field.OperationType.getValue())
	{
		case 2:
			if (strlen(partylink.IPADDR.getValue()) > 0
			&&	strlen(partylink.Interface.getValue()) > 0)
			{
				string	key = partylink.IPADDR.getValue();
				key += "_";
				key += partylink.Interface.getValue();

				m_partylinkinfo[key] = partylink;
			}

			break;
		case 3:
			if (strlen(partylink.IPADDR.getValue()) > 0
			&&	strlen(partylink.Interface.getValue()) > 0)
			{
				string	key = partylink.IPADDR.getValue();
				key += "_";
				key += partylink.Interface.getValue();

				it = m_partylinkinfo.find(key);
				if (it != m_partylinkinfo.end())
				{
					m_partylinkinfo.erase(it);
				}
			}

			break;
		case 4:
			if (strlen(partylink.IPADDR.getValue()) > 0
			&&	strlen(partylink.Interface.getValue()) > 0)
			{
				string	key = partylink.IPADDR.getValue();
				key += "_";
				key += partylink.Interface.getValue();

				it = m_partylinkinfo.find(key);
				if (it != m_partylinkinfo.end())
				{
					m_partylinkinfo.erase(it);
				}

				m_partylinkinfo[key] = partylink;
			}

			break;
		default:
			return;
	}
}

/*
//接收网络接口信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspNetInterfaceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetInterfaceField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetInterfaceField::m_Describe));
	CFTDSysNetInterfaceField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetInterfaceEntity(&val, &field);

		m_ifs[val.ID.getValue()] = val;

		//添加到对象树中		
		g_pDataCenter->addAppIdName(
				(char *)field.ObjectID.getValue(),
				(char *)field.EName.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = field.ObjectID;
		objecttree.CName = field.EName;

		AddNetMonitorObjectTree(objecttree);

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetIntefaceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetInterfaceField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetInterfaceField dev;
	NET_INTERFACE_MAP_ITERATOR	it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			CopySysNetInterfaceEntity(&dev, &field);

			m_ifs[dev.ID.getValue()] = dev;

			break;
		case 3:
			it = m_ifs.find(field.ID.getValue());
			if (it != m_ifs.end())
			{
				m_ifs.erase(it);
			}

			//todo 更新对象树，删除子节点数据
			break;
		case 4:
			it = m_ifs.find(field.ID.getValue());
			if (it != m_ifs.end())
			{
				CopySysNetInterfaceEntity(&(it->second), &field);
			}

			break;
		default:
			return;
	}

	if (field.OperationType.getValue() % 2 == 0)
	{
		//添加到对象树中					
		g_pDataCenter->addAppIdName(
				(char *)field.ObjectID.getValue(),
				(char *)field.EName.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = field.ObjectID;
		objecttree.CName = field.EName;

		AddNetMonitorObjectTree(objecttree);
	}
}

/*
//接收模块信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspNetModuleTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetModuleField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetModuleField::m_Describe));
	CFTDSysNetModuleField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetModuleEntity(&val, &field);

		m_mods[val.ID.getValue()] = val;

		//添加到对象树中					
		g_pDataCenter->addAppIdName(
				(char *)field.ObjectID.getValue(),
				(char *)field.Name.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = field.ObjectID;
		objecttree.CName = field.Name;

		AddNetMonitorObjectTree(objecttree);

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetModuleTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetModuleField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetModuleField dev;
	NET_MODULE_MAP_ITERATOR it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			CopySysNetModuleEntity(&dev, &field);

			m_mods[dev.ID.getValue()] = dev;

			break;
		case 3:
			it = m_mods.find(field.ID.getValue());
			if (it != m_mods.end())
			{
				m_mods.erase(it);
			}

			//todo 更新对象树，删除子节点数据
			break;
		case 4:
			it = m_mods.find(field.ID.getValue());
			if (it != m_mods.end())
			{
				CopySysNetModuleEntity(&(it->second), &field);
			}

			break;
		default:
			return;
	}

	if (field.OperationType.getValue() % 2 == 0)
	{
		//添加到对象树中
		g_pDataCenter->addAppIdName(
				(char *)field.ObjectID.getValue(),
				(char *)field.Name.getValue());

		CFTDRtnNetAreaField objecttree;
		memset(&objecttree, 0, sizeof(objecttree));

		objecttree.ID = EVENT_FLAG_GREEN;
		objecttree.EName = field.ObjectID;
		objecttree.CName = field.Name;

		AddNetMonitorObjectTree(objecttree);
	}
}

/*
//接收网络设备变更信息 //仅仅针对objectid变更
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspChgNetDeviceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetDeviceChgField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetDeviceField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		NET_DEVICE_MAP_ITERATOR it = m_devs.find(field.DeviceID.getValue());

		if (it != m_devs.end()
		&&	strcmp(
				it->second.ObjectID.getValue(),
			field.OldObjectID.getValue()) == 0)
		{
			it->second.ObjectID = field.NewObjectID;

			for (NET_INTERFACE_MAP_ITERATOR it_if = m_ifs.begin();
				 it_if != m_ifs.end();
				 it_if++)
			{
				if (it_if->second.DeviceID.getValue()
						== field.DeviceID.getValue())
				{
					char buff[128] = "\0";

					string	old_objid =
						(char *)it_if->second.DeviceObjectID.getValue();
					sprintf(
						buff,
						"%s.%s",
						field.NewObjectID.getValue(),
						old_objid.substr(old_objid.rfind('.') + 1).c_str());

					it_if->second.DeviceObjectID = buff;
				}
			}
		}

		itor.Next();
	}

	/*
	//wei.c modify, 计算attr管理你的设备、接口、模块信息	
	PrepareExprData();

	//wei.c modify, update expression
	if(g_mExprAnalysis)
	{		
		g_mExprAnalysis->generateObjectExpr(m_mExprTaskList, m_attr_devs, m_warnexprs);
	}
*/
}

void CConfigConnector::OnRtnChgNetDeviceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetDeviceChgField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	NET_DEVICE_MAP_ITERATOR it = m_devs.find(field.DeviceID.getValue());

	if (it != m_devs.end()
	&&	strcmp(
			it->second.ObjectID.getValue(),
		field.OldObjectID.getValue()) == 0)
	{
		it->second.ObjectID = field.NewObjectID;

		for (NET_INTERFACE_MAP_ITERATOR it_if = m_ifs.begin();
			 it_if != m_ifs.end();
			 it_if++)
		{
			if (it_if->second.DeviceID.getValue() == field.DeviceID.getValue())
			{
				char buff[128] = "\0";

				string	old_objid =
					(char *)it_if->second.DeviceObjectID.getValue();
				sprintf(
					buff,
					"%s.%s",
					field.NewObjectID.getValue(),
					old_objid.substr(old_objid.rfind('.') + 1).c_str());

				it_if->second.DeviceObjectID = buff;
			}
		}

		//wei.c modify, 计算attr管理你的设备、接口、模块信息	
		PrepareExprData();

		//wei.c modify, update expression
		if (g_mExprAnalysis)
		{
			g_mExprAnalysis->generateObjectExpr(
					m_mExprTaskList,
					m_attr_devs,
					m_warnexprs);
		}
	}
}

/*
//接收时间策略信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspTimePolicyTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetTimePolicyField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetTimePolicyField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetTimePolicyField policy;

		policy.ID = field.ID;
		policy.PolicyType = field.PolicyType;
		policy.PolicyString = field.PolicyString;
		policy.TradingDay = field.TradingDay;
		policy.Description = field.Description;
		policy.Operation = field.Operation;
		policy.EName = field.EName;
		policy.CName = field.CName;

		//todo		g_TaskInfoManager.AddTimePolicyInfo(policy);
		m_tpolicys[policy.ID.getValue()] = policy;

		itor.Next();
	}
}

void CConfigConnector::OnRtnTimePolicyTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetTimePolicyField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetTimePolicyField policy;
	CopySysNetTimePolicyEntity(&policy, &field);

	//todo	g_TaskInfoManager.UpdTimePolicyInfo(policy, field.OperationType.getValue());
	TIME_POLICY_MAP_ITERATOR it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			policy.ID = field.ID;
			policy.PolicyType = field.PolicyType;
			policy.PolicyString = field.PolicyString;
			policy.TradingDay = field.TradingDay;
			policy.Description = field.Description;
			policy.Operation = field.Operation;
			policy.EName = field.EName;
			policy.CName = field.CName;

			m_tpolicys[field.ID.getValue()] = policy;

			break;
		case 3:
			it = m_tpolicys.find(field.ID.getValue());
			if (it != m_tpolicys.end())
			{
				m_tpolicys.erase(it);
			}

			break;
		case 4:
			it = m_tpolicys.find(field.ID.getValue());
			if (it != m_tpolicys.end())
			{
				it->second.PolicyType = field.PolicyType;
				it->second.PolicyString = field.PolicyString;
				it->second.TradingDay = field.TradingDay;
				it->second.Description = field.Description;
				it->second.Operation = field.Operation;
				it->second.EName = field.EName;
				it->second.CName = field.CName;
			}

			break;
	}
}

/*
//接收监控对象类别信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CConfigConnector::OnRspMonitorTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTypeField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTypeField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetMonitorTypeField	val;

		val.ID = field.ID;
		val.EName = field.EName;
		val.CName = field.CName;

		m_montypes[strlwr(
				(char *)field.EName.getValue(),
				strlen(field.EName.getValue()))] = val;

		itor.Next();
	}
}

void CConfigConnector::OnRtnMonitorTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTypeField	field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorTypeField	val;
	MONITOR_TYPE_MAP_ITERATOR it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			val.ID = field.ID;
			val.EName = field.EName;
			val.CName = field.CName;

			m_montypes[strlwr(
					(char *)field.EName.getValue(),
					strlen(field.EName.getValue()))] = val;

			break;
		case 3:
			break;
		case 4:
			break;
	}
}

/*
//接收监控指标表
*/
void CConfigConnector::OnRspMonitorAttrTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorAttrTypeField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorAttrTypeField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		char idbuf[100] = { 0 };
		sprintf(
			idbuf,
			"%d;;;%d",
			field.MANUFACTORY_ID.getValue(),
			field.MonitorType_ID.getValue());

		string	key = idbuf;

		MONITOR_ATTR_MAP_ITERATOR it = m_attrs.find(key);
		if (it != m_attrs.end())
		{
			it->second[field.AttrType.getValue()] = 1;
		}
		else
		{
			map<string, int> attr;
			attr[field.AttrType.getValue()] = 1;

			m_attrs[key] = attr;
		}

		itor.Next();
	}
}

void CConfigConnector::OnRtnMonitorAttrTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorAttrTypeField	field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorAttrTypeField	val;
	MONITOR_ATTR_MAP_ITERATOR it;

	char idbuf[100];
	sprintf(
		idbuf,
		"%d;;;%d",
		field.MANUFACTORY_ID.getValue(),
		field.MonitorType_ID.getValue());

	string	key = idbuf;

	switch (field.OperationType.getValue())
	{
		case 2:
			//增加
			it = m_attrs.find(key);
			if (it != m_attrs.end())
			{
				m_attrs[key][field.AttrType.getValue()] = 1;
			}
			else
			{
				map<string, int> attrmap;
				attrmap[field.AttrType.getValue()] = 1;

				m_attrs[key] = attrmap;
			}

			break;
		case 3:
			//删除
			it = m_attrs.find(key);
			if (it != m_attrs.end())
			{
				m_attrs.erase(it);
			}

			break;
		case 4:
			//修改
			it = m_attrs.find(key);
			if (it != m_attrs.end())
			{
				m_attrs.erase(it);

				map<string, int> attrmap;
				attrmap[field.AttrType.getValue()] = 1;

				m_attrs[key] = attrmap;
			}

			break;
		default:
			return;
	}

	//wei.c modify, 计算attr管理你的设备、接口、模块信息	
	PrepareExprData();

	//wei.c modify, update expression
	if (g_mExprAnalysis)
	{
		g_mExprAnalysis->generateObjectExpr(
				m_mExprTaskList,
				m_attr_devs,
				m_warnexprs);
	}
}

/*
//接收告警表达式
*/
void CConfigConnector::OnRspNetEventExprTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetEventExprField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetEventExprField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		m_warnexprs[field.ID.getValue()] = field;

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetEventExprTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetEventExprField field;
	WARNING_EXPRESSION_ITERATOR it;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDRspQryNetEventExprField rspfield;
	rspfield.ID = field.ID;
	rspfield.ADMINGROUP_ID = field.ADMINGROUP_ID;
	rspfield.BRIEF = field.BRIEF;
	rspfield.CNAME = field.CNAME;
	rspfield.CONTROL = field.CONTROL;
	rspfield.DISCRIPTION = field.DISCRIPTION;
	rspfield.ENAME = field.ENAME;
	rspfield.EventTypeID = field.EventTypeID;
	rspfield.EXPR = field.EXPR;
	rspfield.GIVEUPTIME = field.GIVEUPTIME;
	rspfield.WarningLEVEL = field.WarningLEVEL;

	switch (field.OperationType.getValue())
	{
		case 2:
			//增加
			m_warnexprs[rspfield.ID.getValue()] = rspfield;

			break;
		case 3:
			//删除所有表达式
			if (-1 == field.ID.getValue())
			{
				m_warnexprs.clear();
			}
			else
			{
				//删除指定表达式
				it = m_warnexprs.find(field.ID.getValue());
				if (it != m_warnexprs.end())
				{
					m_warnexprs.erase(it);
					break;
				}
				else
				{
					//没修改，不重新计算
					return;
				}
			}

		case 4:
			//修改
			it = m_warnexprs.find(field.ID.getValue());
			if (it != m_warnexprs.end())
			{
				m_warnexprs[rspfield.ID.getValue()] = rspfield;
				break;
			}
			else
			{
				//没有修改，不重新计算
				return;
			}

		default:
			break;
	}

	//重新生成表达式
	if (g_mExprAnalysis)
	{
		g_mExprAnalysis->generateObjectExpr(
				m_mExprTaskList,
				m_attr_devs,
				m_warnexprs);
	}
}

//接收巡检任务
void CConfigConnector::OnRspLoopItemTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTaskInfoField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTaskInfoField::m_Describe));

	CFTDSysNetMonitorTaskInfoField	val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorTaskInfoEntity(&val, &field);
		m_loopitem[val.ID.getValue()] = val;

		AddExprDeviceList(val);
		itor.Next();
	}

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
	{
		//重新生成表达式
		if (g_mExprAnalysis)
		{
			PrepareExprData();
			g_mExprAnalysis->generateObjectExpr(
					m_mExprTaskList,
					m_attr_devs,
					m_warnexprs);
		}
	}
}

void CConfigConnector::OnRtnLoopItemTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTaskInfoField	field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorTaskInfoField	val;
	CopySysNetMonitorTaskInfoEntity(&val, &field);

	LOOP_ITEM_MAP_ITERATOR	it;

	switch (field.OperationType.getValue())
	{
		case 1:
			return;
		case 2:
			CopySysNetMonitorTaskInfoEntity(&val, &field);
			m_loopitem[val.ID.getValue()] = val;

			AddExprDeviceList(val);

			break;
		case 3:
			it = m_loopitem.find(field.ID.getValue());
			if (it != m_loopitem.end())
			{
				m_loopitem.erase(it);
			}

			DelExprDeviceList(val);

			break;
		case 4:
			it = m_loopitem.find(field.ID.getValue());
			if (it != m_loopitem.end())
			{
				CopySysNetMonitorTaskInfoEntity(&(it->second), &field);
			}

			DelExprDeviceList(val);
			AddExprDeviceList(val);

			break;
	}

	//重新生成表达式
	if (g_mExprAnalysis)
	{
		g_mExprAnalysis->generateObjectExpr(
				m_mExprTaskList,
				m_attr_devs,
				m_warnexprs);
	}
}

//接收巡检设备对象组明细
void CConfigConnector::OnRspQryNetMonitorTaskObjectSetTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTaskObjectSetField	field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTaskObjectSetField::m_Describe));

	CFTDSysNetMonitorTaskObjectSetField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorTaskObjectSetEntity(&val, &field);

		MAP_DEVICEGROUPLIST_IT	it = map_DeviceGroupList.find(
				val.DeviceGroup_ID.getValue());
		if (it != map_DeviceGroupList.end())
		{
			LIST_ID &List = it->second;
			List.push_back(val.Device_ID.getValue());
			List.unique();
		}
		else
		{
			LIST_ID List;
			List.push_back(val.Device_ID.getValue());
			List.unique();
			map_DeviceGroupList[val.DeviceGroup_ID.getValue()] = List;
		}

		itor.Next();
	}
}

void CConfigConnector::OnRtnNetMonitorTaskObjectSetTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTaskObjectSetField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorTaskObjectSetField val;
	CopySysNetMonitorTaskObjectSetEntity(&val, &field);

	MAP_DEVICEGROUPLIST_IT	it = map_DeviceGroupList.find(
			val.DeviceGroup_ID.getValue());
	switch (field.OperationType.getValue())
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			if (it != map_DeviceGroupList.end())
			{
				LIST_ID &List = it->second;
				List.push_back(val.Device_ID.getValue());
				List.unique();
			}
			else
			{
				LIST_ID List;
				List.push_back(val.Device_ID.getValue());
				List.unique();
				map_DeviceGroupList[val.DeviceGroup_ID.getValue()] = List;
			}

			break;
		case 3:
			/// 删除
			if (it != map_DeviceGroupList.end())
			{
				LIST_ID &List = it->second;
				LIST_ID_IT	iter = List.begin();
				for (; iter != List.end(); iter++)
				{
					if ((*iter) == val.Device_ID.getValue())
					{
						List.erase(iter);
						break;
					}
				}
			}

			break;
		case 4:
			/// 修改
			break;
	}
}

///响应巡检命令的结果过滤规则处理函数
void CConfigConnector::OnRspDeviceTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorDeviceTaskField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorDeviceTaskField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetMonitorDeviceTaskField val;

		CopySysNetMonitorDeviceTaskEntity(&val, &field);

		map<int, vector<CFTDSysNetMonitorDeviceTaskField> >::iterator c_it =
			m_mapDeviceTask.find(val.ID.getValue());
		if (c_it == m_mapDeviceTask.end())
		{
			vector<CFTDSysNetMonitorDeviceTaskField> val_list;
			val_list.push_back(val);
			m_mapDeviceTask[val.ID.getValue()] = val_list;

			c_it = m_mapDeviceTask.find(val.ID.getValue());
		}
		else
		{
			c_it->second.push_back(val);
		}

		if (field.Flag.getValue() != 0)
		{
			//一个数据包已经收完
			//汇总数据
			string	paramresult;

			for (int i = 0; i < c_it->second.size(); ++i)
			{
				paramresult += c_it->second[i].DefParamChain.getValue();
			}

			ParseDeviceTaskResult(val, paramresult);

			//删除已处理完的缓存数据
			c_it->second.clear();
			m_mapDeviceTask.erase(c_it);
		}

		itor.Next();
	}
}

void CConfigConnector::OnRtnDeviceTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorDeviceTaskField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorDeviceTaskField val;

	CopySysNetMonitorDeviceTaskEntity(&val, &field);

	map<int, vector<CFTDSysNetMonitorDeviceTaskField> >::iterator c_it =
		m_mapDeviceTask.find(val.ID.getValue());
	if (c_it == m_mapDeviceTask.end())
	{
		vector<CFTDSysNetMonitorDeviceTaskField> val_list;
		val_list.push_back(val);
		m_mapDeviceTask[val.ID.getValue()] = val_list;

		c_it = m_mapDeviceTask.find(val.ID.getValue());
	}
	else
	{
		c_it->second.push_back(val);
	}

	if (field.Flag.getValue() == 0)
	{
		//中间包，还未收完
		return;
	}

	//汇总数据
	string	paramresult;

	for (int i = 0; i < c_it->second.size(); ++i)
	{
		paramresult += c_it->second[i].DefParamChain.getValue();
	}

	switch (field.OperationType.getValue())
	{
		case 1:
			/// 查询
			break;
		case 2:
			{
				/// 增加
				ParseDeviceTaskResult(val, paramresult);

				break;
			}

		case 3:
			{
				/// 删除
				char key[1024] = { 0 };
				SNPRINTF(
					key,
					1024,
					"%d_%s_%s",
					field.Manufactory_ID.getValue(),
					field.ObjectID.getValue(),
					field.InstructAlias.getValue());

				MAP_TASK_REGULAR_PARAM_IT it = map_TaskRegularParams.find(key);
				if (it != map_TaskRegularParams.end())
				{
					map_TaskRegularParams.erase(it);
				}

				break;
			}

		case 4:
			{
				/// 修改,先删除再增加
				char key[1024] = { 0 };
				SNPRINTF(
					key,
					1024,
					"%d_%s_%s",
					field.Manufactory_ID.getValue(),
					field.ObjectID.getValue(),
					field.InstructAlias.getValue());

				MAP_TASK_REGULAR_PARAM_IT it = map_TaskRegularParams.find(key);
				if (it != map_TaskRegularParams.end())
				{
					map_TaskRegularParams.erase(it);
				}

				ParseDeviceTaskResult(val, paramresult);

				break;
			}
	}

	//删除已处理完的缓存数据
	c_it->second.clear();
	m_mapDeviceTask.erase(c_it);
}

///响应巡检命令的列表处理函数
void CConfigConnector::OnRspTaskCmdAttrListTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTaskInstAttrsField	field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTaskInstAttrsField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CInstructionInfo instrinfo;

		instrinfo.defaultregular = field.DefRegularChain.getValue();

		splitStringBySeprator(
			field.AttrsChain.getValue(),
			"\\;",
			instrinfo.attrlist);

		//多组数据用"\;"分隔
		vector<string>	rows;
		splitStringBySeprator(field.DefParamChain.getValue(), "\\;", rows);

		vector<map<int, string> > paramlist;

		for (int i = 0; i < rows.size(); ++i)
		{
			map<int, string> params;

			//一组数据内元素用"\,"分隔
			vector<string>	cols;
			splitStringBySeprator(rows[i], "\\,", cols);

			for (int j = 0; j < cols.size(); ++j)
			{
				bool isDigit = true;
				for (int k = 0; k < cols[j].size(); ++k)
				{
					if (cols[j][k] < '0' || cols[j][k] > '9')
					{
						isDigit = false;
						break;
					}
				}

				if (isDigit)
				{
					params[j] = cols[j];
				}
				else
				{
					//字符串拼接上""
					string	val = "\"";
					val += cols[j];
					val += "\"";
					params[j] = val;
				}
			}

			paramlist.push_back(params);
		}

		instrinfo.defaultparams = paramlist;

		vector<string>	deviceserials;
		splitStringBySeprator(field.DEVICETYPE.getValue(), ";", deviceserials);

		for (int i = 0; i < deviceserials.size(); ++i)
		{
			char key[1024] = { 0 };
			if (deviceserials[i].compare("default") == 0)
			{
				SNPRINTF(
					key,
					1024,
					"%s_%d_",
					field.InstructAlias.getValue(),
					field.Manufactory_ID.getValue());
			}
			else
			{
				SNPRINTF(
					key,
					1024,
					"%s_%d_%s",
					field.InstructAlias.getValue(),
					field.Manufactory_ID.getValue(),
					deviceserials[i].c_str());
			}

			map_InstrInfo[key] = instrinfo;
		}

		itor.Next();
	}
}

void CConfigConnector::OnRtnTaskCmdAttrListTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTaskInstAttrsField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	switch (field.OperationType.getValue())
	{
		case 1:
			/// 查询
			break;
		case 2:
			{
				/// 增加
				CInstructionInfo instrinfo;

				instrinfo.defaultregular = field.DefRegularChain.getValue();

				splitStringBySeprator(
					field.AttrsChain.getValue(),
					"\\;",
					instrinfo.attrlist);

				//多组数据用"\;"分隔
				vector<string>	rows;
				splitStringBySeprator(field.DefParamChain.getValue(), "\\;", rows);

				vector<map<int, string> > paramlist;

				for (int i = 0; i < rows.size(); ++i)
				{
					map<int, string> params;

					//一组数据内元素用"\,"分隔
					vector<string>	cols;
					splitStringBySeprator(rows[i], "\\,", cols);

					for (int j = 0; j < cols.size(); ++j)
					{
						bool isDigit = true;
						for (int k = 0; k < cols[j].size(); ++k)
						{
							if (cols[j][k] < '0' || cols[j][k] > '9')
							{
								isDigit = false;
								break;
							}
						}

						if (isDigit)
						{
							params[j] = cols[j];
						}
						else
						{
							//字符串拼接上""
							string	val = "\"";
							val += cols[j];
							val += "\"";
							params[j] = val;
						}
					}

					paramlist.push_back(params);
				}

				instrinfo.defaultparams = paramlist;

				vector<string>	deviceserials;
				splitStringBySeprator(
					field.DEVICETYPE.getValue(),
					";",
					deviceserials);

				for (int i = 0; i < deviceserials.size(); ++i)
				{
					char key[1024] = { 0 };
					if (deviceserials[i].compare("default") == 0)
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue());
					}
					else
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_%s",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue(),
							deviceserials[i].c_str());
					}

					map_InstrInfo[key] = instrinfo;
				}

				break;
			}

		case 3:
			{
				/// 删除
				vector<string>	deviceserials;
				splitStringBySeprator(
					field.DEVICETYPE.getValue(),
					";",
					deviceserials);

				for (int i = 0; i < deviceserials.size(); ++i)
				{
					char key[1024] = { 0 };
					if (deviceserials[i].compare("default") == 0)
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue());
					}
					else
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_%s",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue(),
							deviceserials[i].c_str());
					}

					MAP_INSTRINFO_IT it = map_InstrInfo.find(key);
					if (it != map_InstrInfo.end())
					{
						map_InstrInfo.erase(it);
					}
				}

				break;
			}

		case 4:
			{
				/// 修改,先删除再增加
				vector<string>	deviceserials;
				splitStringBySeprator(
					field.DEVICETYPE.getValue(),
					";",
					deviceserials);

				for (int i = 0; i < deviceserials.size(); ++i)
				{
					char key[1024] = { 0 };
					if (deviceserials[i].compare("default") == 0)
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue());
					}
					else
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_%s",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue(),
							deviceserials[i].c_str());
					}

					MAP_INSTRINFO_IT it = map_InstrInfo.find(key);
					if (it != map_InstrInfo.end())
					{
						map_InstrInfo.erase(it);
					}
				}

				CInstructionInfo instrinfo;

				instrinfo.defaultregular = field.DefRegularChain.getValue();

				splitStringBySeprator(
					field.AttrsChain.getValue(),
					"\\;",
					instrinfo.attrlist);

				//多组数据用"\;"分隔
				vector<string>	rows;
				splitStringBySeprator(field.DefParamChain.getValue(), "\\;", rows);

				vector<map<int, string> > paramlist;

				for (int i = 0; i < rows.size(); ++i)
				{
					map<int, string> params;

					//一组数据内元素用"\,"分隔
					vector<string>	cols;
					splitStringBySeprator(rows[i], "\\,", cols);

					for (int j = 0; j < cols.size(); ++j)
					{
						bool isDigit = true;
						for (int k = 0; k < cols[j].size(); ++k)
						{
							if (cols[j][k] < '0' || cols[j][k] > '9')
							{
								isDigit = false;
								break;
							}
						}

						if (isDigit)
						{
							params[j] = cols[j];
						}
						else
						{
							//字符串拼接上""
							string	val = "\"";
							val += cols[j];
							val += "\"";
							params[j] = val;
						}
					}

					paramlist.push_back(params);
				}

				instrinfo.defaultparams = paramlist;

				deviceserials.clear();
				splitStringBySeprator(
					field.DEVICETYPE.getValue(),
					";",
					deviceserials);

				for (int i = 0; i < deviceserials.size(); ++i)
				{
					char key[1024] = { 0 };
					if (deviceserials[i].compare("default") == 0)
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue());
					}
					else
					{
						SNPRINTF(
							key,
							1024,
							"%s_%d_%s",
							field.InstructAlias.getValue(),
							field.Manufactory_ID.getValue(),
							deviceserials[i].c_str());
					}

					map_InstrInfo[key] = instrinfo;
				}

				break;
			}
	}
}

void CConfigConnector::OnRtnWarningEventTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnWarningEventField eventField;
	memset(&eventField, 0, sizeof(CFTDRtnWarningEventField));

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &eventField) <= 0)
	{
		printf("FTDC_GET_SINGLE_FIELD fail in %s\n", __FUNCTION__);
		return;
	}

	string	exprkey = eventField.ObjectID.getValue();
	exprkey += "_";
	exprkey += eventField.EventName.getValue();
	exprkey += "_";
	exprkey += eventField.MonDate.getValue();
	exprkey += "_";
	exprkey += eventField.MonTime.getValue();

	//魏诚add，保存未处理的告警事件
	g_warningEventManager.add_warning_event(eventField);

	if (g_mExprAnalysis)
	{
		string	exprstr;
		if (g_mExprAnalysis->m_mapWarningEventExpr.get(exprkey, exprstr))
		{
			//该事件是表达式计算产生的
			g_mExprAnalysis->m_mapWarningEventExpr.del(exprkey);

			CFTDRtnWarningQueryField warningInfo;
			memset(&warningInfo, 0, sizeof(CFTDRtnWarningQueryField));
			warningInfo.MonDate = eventField.MonDate;
			warningInfo.MonTime = eventField.MonTime;

			string	outInfo;
			g_mExprAnalysis->m_mapWarningInfo.get(exprkey, outInfo);
			g_mExprAnalysis->m_mapWarningInfo.del(exprkey);

			warningInfo.EvendID = eventField.EvendID.getValue();
			warningInfo.DBQueryResult = outInfo.c_str();

			g_pListEvent->WriteValue(eventField, warningInfo);
		}
		else
		{
			//该事件是syslog产生的
			AddWarningEvent(eventField);

			if ((
					strcmp(eventField.ProcessFlag.getValue(), "N") == 0
			||	strcmp(eventField.ProcessFlag.getValue(), "=") == 0
			)
			&&	(
					strcmp(
					eventField.EventName.getValue(),
				"LINK_UPDOWN") == 0
			||	strcmp(
					eventField.EventName.getValue(),
				"LINK_SP_UPDOWN") == 0
			||	strcmp(
					eventField.EventName.getValue(),
				"LINEPROTO_UPDOWN") == 0
			||	strcmp(
					eventField.EventName.getValue(),
				"LINEPROTO_SP_UPDOWN") == 0
			))
			{
				//updown事件产生链路状态统计信息
				string	wholeid = eventField.ObjectID.getValue();
				size_t	pos = wholeid.rfind(".");
				if (pos != string::npos)
				{
					string	portid = wholeid.substr(pos + 1);

					CFTDRtnNetPartyLinkStatusInfoField	partylinkstatus;
					memset(&partylinkstatus, 0, sizeof(partylinkstatus));

					partylinkstatus.Interface = portid.c_str();
					partylinkstatus.IPADDR = eventField.IPAddress.getValue();
					partylinkstatus.MonDate = eventField.OccurDate.getValue();
					partylinkstatus.MonTime = eventField.OccurTime.getValue();

					string	partylink_key = eventField.IPAddress.getValue();
					partylink_key += "_";
					partylink_key += portid;

					MAP_PARTYLINK_INFO_IT p_it = m_partylinkinfo.find(
							partylink_key);
					if (p_it != m_partylinkinfo.end())
					{
						partylinkstatus.SEAT_NO = p_it->second.SEAT_NO;
						partylinkstatus.status = "down";

						AddPartyLinkStatusInfo(partylinkstatus);
					}
					else
					{
						printf(
							"no partylink info for ip:%s, port:%s in %s\n",
							eventField.IPAddress.getValue(),
							portid.c_str(),
							__FUNCTION__);
					}
				}
				else
				{
					printf("Invalid objectid for updown event, no \".\"!\n");
				}
			}
		}
	}
}

void CConfigConnector::OnRtnSyslogEventTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnSyslogEventField syslogField;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &syslogField) <= 0)
	{
		printf("FTDC_GET_SINGLE_FIELD fail in %s\n", __FUNCTION__);
		return;
	}

	//该事件是syslog产生的
	AddSyslogEvent(syslogField);

	if (strcmp(syslogField.ProcessFlag.getValue(), "N") == 0
	&&	(
			strcmp(
			syslogField.EventName.getValue(),
		"LINEPROTO_UPDOWN") == 0
	||	strcmp(
			syslogField.EventName.getValue(),
		"LINEPROTO_SP_UPDOWN") == 0
	))
	{
		//updown事件产生链路状态统计信息
		string	wholeid = syslogField.ObjectID.getValue();
		size_t	pos = wholeid.rfind(".");
		if (pos != string::npos)
		{
			string	portid = wholeid.substr(pos + 1);

			CFTDRtnNetPartyLinkStatusInfoField	partylinkstatus;
			memset(&partylinkstatus, 0, sizeof(partylinkstatus));

			partylinkstatus.Interface = portid.c_str();
			partylinkstatus.IPADDR = syslogField.IPAddress.getValue();
			partylinkstatus.MonDate = syslogField.OccurDate;
			partylinkstatus.MonTime = syslogField.OccurTime;

			string	partylink_key = syslogField.IPAddress.getValue();
			partylink_key += "_";
			partylink_key += portid;

			MAP_PARTYLINK_INFO_IT p_it = m_partylinkinfo.find(partylink_key);
			if (p_it != m_partylinkinfo.end())
			{
				partylinkstatus.SEAT_NO = p_it->second.SEAT_NO;
				partylinkstatus.status = "up";

				AddPartyLinkStatusInfo(partylinkstatus);
			}
			else
			{
				printf(
					"no partylink info for ip:%s, port:%s in %s\n",
					syslogField.IPAddress.getValue(),
					portid.c_str(),
					__FUNCTION__);
			}
		}
		else
		{
			printf("Invalid objectid for updown event, no \".\"!\n");
		}
	}
}

void CConfigConnector::OnReqQryWarningEventUpdate(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryWarningEventUpdateField fieldinfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldinfo);

	bool erasemark = false;
	if (strcmp(fieldinfo.ProcessFlag.getValue(), "Y") == 0)
	{
		//该事件已处理，删除内存中的数据
		erasemark = true;
	}

	vector<CFTDRtnWarningEventField> resultFieldList;
	if (g_mEventProcessFuzzyMatch)
	{
		resultFieldList = g_warningEventManager.fuzzy_get_warning_event(
				fieldinfo.ObjectID.getValue(),
				fieldinfo.EventName.getValue(),
				erasemark);
	}
	else
	{
		resultFieldList = g_warningEventManager.exact_get_warning_event(
				fieldinfo.ObjectID.getValue(),
				fieldinfo.EventName.getValue(),
				fieldinfo.EvendID.getValue(),
				erasemark);
	}

	CFTDRtnWarningEventField eventField;
	memset(&eventField, 0, sizeof(CFTDRtnWarningEventField));

	eventField.ProcessFlag = fieldinfo.ProcessFlag;
	eventField.EventDealDes = fieldinfo.EventDealDes;

	for (int i = 0; i < resultFieldList.size(); ++i)
	{
		eventField.EvendID = resultFieldList[i].EvendID;	//eventid要替换成本中心的id，以免客户端找不到对应的事件
		eventField.EventDes = resultFieldList[i].EventDes;	//描述要保留最原始的内容
		eventField.EventName = resultFieldList[i].EventName;
		eventField.FullEventName = resultFieldList[i].FullEventName;
		eventField.EventNum = resultFieldList[i].EventNum;
		eventField.MonDate = resultFieldList[i].MonDate;
		eventField.MonTime = resultFieldList[i].MonTime;
		eventField.ObjectID = resultFieldList[i].ObjectID;
		eventField.OccurDate = resultFieldList[i].OccurDate;
		eventField.OccurTime = resultFieldList[i].OccurTime;
		eventField.WarningLevel = resultFieldList[i].WarningLevel;
		eventField.IPAddress = resultFieldList[i].IPAddress;

		AddWarningEvent(eventField);
	}

	//已处理的事件变成处理中或未处理，只恢复当前事件，针对协商模式
	if(resultFieldList.size() == 0 && g_mConfigControlEvent)
	{
		eventField.EvendID = fieldinfo.EvendID;	
		eventField.EventDes = fieldinfo.EventDes;	
		eventField.EventName = fieldinfo.EventName;
		eventField.FullEventName = fieldinfo.FullEventName;
		eventField.EventNum = fieldinfo.EventNum;
		eventField.MonDate = fieldinfo.MonDate;
		eventField.MonTime = fieldinfo.MonTime;
		eventField.ObjectID = fieldinfo.ObjectID;
		eventField.OccurDate = fieldinfo.OccurDate;
		eventField.OccurTime = fieldinfo.OccurTime;
		eventField.WarningLevel = fieldinfo.WarningLevel;
		eventField.IPAddress = fieldinfo.IPAddress;
		
		//之前已处理标记删掉了相关事件
		AddWarningEvent(eventField);
	}

	string	delay_key = fieldinfo.ObjectID.getValue();
	delay_key += ";;";
	delay_key += fieldinfo.EventName.getValue();

	if ((!fieldinfo.ActiveDate.isNull()) && (!fieldinfo.ActiveTime.isNull()))
	{
		g_mapEventDelayTime[delay_key] = CObjectAttrKey(
				fieldinfo.ActiveDate.getValue(),
				fieldinfo.ActiveTime.getValue(),
				fieldinfo.ProcessFlag.getValue(),
				fieldinfo.EventDealDes.getValue());
	}
}

void CConfigConnector::OnReqQryWarningEventActiveChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryWarningActiveChangeField	fieldinfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldinfo);

	CFTDRtnWarningActiveChangeField rtnField;
	rtnField.ObjectID = fieldinfo.ObjectID;
	rtnField.MonTime = fieldinfo.MonTime;
	rtnField.MonDate = fieldinfo.MonDate;
	rtnField.WarningActive = fieldinfo.WarningActive;

	printf(
		"in %s objectid=%s\n, warningactive=%d",
		__FUNCTION__,
		fieldinfo.ObjectID.getValue(),
		fieldinfo.WarningActive.getValue());

	// 切换当前内存中对象告警状态
	g_pDataCenter->UpDateObjectIdStatus(
			(char *)fieldinfo.ObjectID.getValue(),
			(int)fieldinfo.WarningActive);

	AddWarningEventActiveChange(rtnField);
}

void CConfigConnector::OnReqQryNetRoomTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetRoomField	fieldinfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldinfo);

	printf(
		"in %s id=%d\n, status=%d",
		__FUNCTION__,
		fieldinfo.ID.getValue(),
		fieldinfo.SysNetBuildingID.getValue());

	CFTDRtnNetRoomField rtnField;
	memset(&rtnField, 0, sizeof(rtnField));

	rtnField.ID = fieldinfo.ID;
	rtnField.SysNetBuildingID = fieldinfo.SysNetBuildingID;

	AddRtnNetRoom(rtnField);

	if (rtnField.ID.getValue() == -2)
	{
		g_MsgGenerator.setNetworkEventFlag(
				rtnField.SysNetBuildingID.getValue());
	}
	else if (rtnField.ID.getValue() == -3)
	{
		g_MsgGenerator.setBusinessEventFlag(
				rtnField.SysNetBuildingID.getValue());
	}
	else if (rtnField.ID.getValue() == -4)
	{
		g_MsgGenerator.setAttrFlag(rtnField.SysNetBuildingID.getValue());
	}
}

void CConfigConnector::PrepareExprData(void)
{
	//指标附属的设备集合
	m_attr_devs.clear();

	map<string, map<string, int> >::iterator a_i;

	//根据manu;;;monitor_type找到指标列表
	//device
	for (NET_DEVICE_MAP_ITERATOR it = m_devs.begin(); it != m_devs.end(); ++it)
	{
		char idbuf[100] = { 0 };
		sprintf(
			idbuf,
			"%d;;;%d",
			it->second.MANUFACTORY_ID.getValue(),
			it->second.MonitorType_ID.getValue());

		string	key = idbuf;

		MONITOR_ATTR_MAP_ITERATOR it_m = m_attrs.find(key);
		if (it_m != m_attrs.end())
		{
			//反向映射, attr->obj1, obj2...
			map<string, int>::iterator	it_mm = it_m->second.begin();
			for (; it_mm != it_m->second.end(); ++it_mm)
			{
				a_i = m_attr_devs.find(it_mm->first);
				if (a_i != m_attr_devs.end())
				{
					a_i->second[it->second.ObjectID.getValue()] = 1;
				}
				else
				{
					map<string, int> devobjid;
					devobjid[it->second.ObjectID.getValue()] = 1;
					m_attr_devs[it_mm->first] = devobjid;
				}
			}
		}
	}

	//interface
	for (NET_INTERFACE_MAP_ITERATOR it = m_ifs.begin(); it != m_ifs.end(); ++it)
	{
		//查找所属设备的manufactory_id
		NET_DEV_OBJID_MAP_ITERATOR	d_m_it = m_dev_objids.find(
				it->second.DeviceObjectID.getValue());
		if (d_m_it == m_dev_objids.end())
		{
			printf(
				"can't find device index by deviceobid:%s for interface %s\n",
				it->second.DeviceObjectID.getValue(),
				it->second.ObjectID.getValue());
			continue;
		}

		NET_DEVICE_MAP_ITERATOR d_it = m_devs.find(d_m_it->second);
		if (d_it == m_devs.end())
		{
			printf(
				"can't find device info by index:%d for interface %s\n",
				d_m_it->second,
				it->second.ObjectID.getValue());
			continue;
		}

		char idbuf[100] = { 0 };
		sprintf(
			idbuf,
			"%d;;;%d",
			d_it->second.MANUFACTORY_ID.getValue(),
			it->second.MonitorType_ID.getValue());

		string	key = idbuf;

		MONITOR_ATTR_MAP_ITERATOR it_m = m_attrs.find(key);
		if (it_m != m_attrs.end())
		{
			//反向映射, attr->obj1, obj2...
			map<string, int>::iterator	it_mm = it_m->second.begin();
			for (; it_mm != it_m->second.end(); ++it_mm)
			{
				a_i = m_attr_devs.find(it_mm->first);
				if (a_i != m_attr_devs.end())
				{
					a_i->second[it->second.ObjectID.getValue()] = 1;
				}
				else
				{
					map<string, int> devobjid;
					devobjid[it->second.ObjectID.getValue()] = 1;
					m_attr_devs[it_mm->first] = devobjid;
				}
			}
		}
	}

	//module
	for (NET_MODULE_MAP_ITERATOR it = m_mods.begin(); it != m_mods.end(); ++it)
	{
		//查找所属设备的manufactory_id
		NET_DEV_OBJID_MAP_ITERATOR	d_m_it = m_dev_objids.find(
				it->second.DeviceObjectID.getValue());
		if (d_m_it == m_dev_objids.end())
		{
			printf(
				"can't find device index by deviceobid:%s for module %s\n",
				it->second.DeviceObjectID.getValue(),
				it->second.ObjectID.getValue());
			continue;
		}

		NET_DEVICE_MAP_ITERATOR d_it = m_devs.find(d_m_it->second);
		if (d_it == m_devs.end())
		{
			printf(
				"can't find device info by index:%d for module %s\n",
				d_m_it->second,
				it->second.ObjectID.getValue());
			continue;
		}

		char idbuf[100] = { 0 };
		sprintf(
			idbuf,
			"%d;;;%d",
			d_it->second.MANUFACTORY_ID.getValue(),
			it->second.MonitorType_ID.getValue());

		string	key = idbuf;

		MONITOR_ATTR_MAP_ITERATOR it_m = m_attrs.find(key);
		if (it_m != m_attrs.end())
		{
			//反向映射, attr->obj1, obj2...
			map<string, int>::iterator	it_mm = it_m->second.begin();
			for (; it_mm != it_m->second.end(); ++it_mm)
			{
				a_i = m_attr_devs.find(it_mm->first);
				if (a_i != m_attr_devs.end())
				{
					a_i->second[it->second.ObjectID.getValue()] = 1;
				}
				else
				{
					map<string, int> devobjid;
					devobjid[it->second.ObjectID.getValue()] = 1;
					m_attr_devs[it_mm->first] = devobjid;
				}
			}
		}
	}
}

void CConfigConnector::AddExprDeviceList(CFTDSysNetMonitorTaskInfoField &field)
{
	//提取任务关联的表达式id列表
	string	expstr = field.EventExprStr.getValue();
	char *p = strtok((char *)expstr.c_str(), ";\r\n");
	printf(
		"taskid=%d, expr=%s\n",
		field.ID.getValue(),
		field.EventExprStr.getValue());

	while (p)
	{
		int expid = atoi(p);
		EXPR_DEVICE_LIST_ITERATOR e_i = m_mExprTaskList.find(expid);

		//提取任务关联的设备列表
		MAP_DEVICEGROUPLIST_IT	map_it = map_DeviceGroupList.find(
				field.DeviceGroup_ID.getValue());
		if (map_it != map_DeviceGroupList.end() && map_it->second.size() > 0)
		{
			LIST_ID &List = map_it->second;
			for (LIST_ID_IT list_it = List.begin();
				 list_it != List.end();
				 list_it++)
			{
				int iDeviceID = (*list_it);
				MAP_DEVICE_IT map_Device_it = m_devs.find(iDeviceID);
				if (map_Device_it != m_devs.end())
				{
					if (e_i == m_mExprTaskList.end())
					{
						//表达式还未创建
						map<string, int> devidmap;
						devidmap[map_Device_it->second.ObjectID.getValue()] = 1;

						m_mExprTaskList[expid] = devidmap;

						e_i = m_mExprTaskList.find(expid);
					}
					else
					{
						m_mExprTaskList[expid][map_Device_it->second.ObjectID.getValue()] = 1;
					}
				}
			}
		}

		p = strtok(NULL, ";\r\n");
	}
}

void CConfigConnector::DelExprDeviceList(CFTDSysNetMonitorTaskInfoField &field)
{
	//提取任务关联的设备列表
	MAP_DEVICEGROUPLIST_IT	map_it = map_DeviceGroupList.find(
			field.DeviceGroup_ID.getValue());
	if (map_it != map_DeviceGroupList.end() && map_it->second.size() > 0)
	{
		LIST_ID &List = map_it->second;
		for (LIST_ID_IT list_it = List.begin();
			 list_it != List.end();
			 list_it++)
		{
			int iDeviceID = (*list_it);
			MAP_DEVICE_IT map_Device_it = m_devs.find(iDeviceID);
			if (map_Device_it != m_devs.end())
			{
				//将设备从表达式中删除
				EXPR_DEVICE_LIST_ITERATOR e_i = m_mExprTaskList.begin();
				for (; e_i != m_mExprTaskList.end(); ++e_i)
				{
					map<string, int>::iterator	d_i = e_i->second.find(
							map_Device_it->second.ObjectID.getValue());
					if (d_i != e_i->second.end())
					{
						e_i->second.erase(d_i);
					}
				}
			}
		}
	}
}

//根据指定的分隔符将字符串拆分成多个单元
void CConfigConnector::splitStringBySeprator(
	string	ori,
	string	splitstr,
	vector<string>	&result)
{
	int pos1 = 0;
	int pos2 = ori.find(splitstr, pos1);
	while (pos2 != string::npos)
	{
		string	substr = ori.substr(pos1, pos2 - pos1);
		if (substr.length() >= 0)
		{
			result.push_back(substr);
		}

		pos1 = pos2 + splitstr.length();
		pos2 = ori.find(splitstr, pos1);
	}

	string	substr = ori.substr(pos1);
	if (substr.length() > 0)
	{
		result.push_back(substr);
	}
}

int CConfigConnector::GetDeviceManufacoryIdAndIP(
	string	objectid,
	int &manuid,
	string	&deviceip,
	string	&deviceserial)
{
	NET_DEV_OBJID_MAP_ITERATOR	o_it = m_dev_objids.find(objectid);
	if (o_it == m_dev_objids.end())
	{
		return -1;
	}

	NET_DEVICE_MAP_ITERATOR d_it = m_devs.find(o_it->second);
	if (d_it == m_devs.end())
	{
		return -1;
	}
	else
	{
		manuid = d_it->second.MANUFACTORY_ID.getValue();
		deviceip = d_it->second.IPADDR.getValue();
		deviceserial = d_it->second.DEVICETYPE.getValue();
		return 0;
	}
}

void CConfigConnector::GetDeviceName(string objectid, string &devname)
{
	devname = "";

	NET_DEV_OBJID_MAP_ITERATOR	do_it = m_dev_objids.find(objectid);
	if (do_it == m_dev_objids.end())
	{
		//端口或模块
		string	devobj = objectid.substr(0, objectid.find_last_of("."));
		do_it = m_dev_objids.find(devobj);
	}

	if (do_it != m_dev_objids.end())
	{
		NET_DEVICE_MAP_ITERATOR d_it = m_devs.find(do_it->second);
		if (d_it != m_devs.end())
		{
			devname = d_it->second.NAME.getValue();
		}
	}
}

void CConfigConnector::ParseDeviceTaskResult(
	CFTDSysNetMonitorDeviceTaskField &info,
	string	&result)
{
	char key[1024] = { 0 };
	SNPRINTF(
		key,
		1024,
		"%d_%s_%s",
		info.Manufactory_ID.getValue(),
		info.ObjectID.getValue(),
		info.InstructAlias.getValue());

	//多组数据用"\;"分隔
	vector<string>	rows;
	splitStringBySeprator(result, "\\;", rows);

	vector<map<int, string> > paramlist;

	for (int i = 0; i < rows.size(); ++i)
	{
		map<int, string> params;

		//一组数据内元素用"\,"分隔
		vector<string>	cols;
		splitStringBySeprator(rows[i], "\\,", cols);

		for (int j = 0; j < cols.size(); ++j)
		{
			bool isDigit = true;
			for (int k = 0; k < cols[j].size(); ++k)
			{
				if (cols[j][k] < '0' || cols[j][k] > '9')
				{
					isDigit = false;
					break;
				}
			}

			if (isDigit)
			{
				params[j] = cols[j];
			}
			else
			{
				//字符串拼接上""
				string	val = "\"";
				val += cols[j];
				val += "\"";
				params[j] = val;
			}
		}

		paramlist.push_back(params);
	}

	map_TaskRegularParams[key] = paramlist;
}

void CConfigConnector::GetPartyLinkMemberName(
	CFTDRtnWarningEventField &event,
	string	&membername)
{
	membername = "";

	string	wholeid = event.ObjectID.getValue();
	size_t	pos = wholeid.rfind(".");
	if (pos != string::npos)
	{
		string	portid = wholeid.substr(pos + 1);

		string	partylink_key = event.IPAddress.getValue();
		partylink_key += "_";
		partylink_key += portid;

		MAP_PARTYLINK_INFO_IT p_it = m_partylinkinfo.find(partylink_key);
		if (p_it != m_partylinkinfo.end())
		{
			//提取会员名
			membername = p_it->second.MEMBER_NAME.getValue();
		}
	}
}
