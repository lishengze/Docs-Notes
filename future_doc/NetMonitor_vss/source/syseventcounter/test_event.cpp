#include <iostream>
#include <boost/regex.hpp>
#include "EventConfigConnector.h"
#include "utility.h"

using namespace boost;
using namespace std;

#define EXPR_CASE(seq)		   \
	{						   \
	case seq:				   \
		in = in##seq;		   \
		expression = exp##seq; \
		break;				   \
	}

void test_regex(void)
{
	regex exp1(
			"^CPU utilization for five seconds: ([0-9]*)%/([0-9]*)%; one minute: ([0-9]*)%; five minutes: ([0-9]*)%.*$");	//CPU
	regex exp2(
			"^[ \t]*.*?Pool Total:[ ]*([0-9]+) Used:[ ]*[0-9]+ Free:[ ]*([0-9]+).*$");	//MEMORY
	regex exp3("^.*Port ID[\r\n]*(.*)$", match_single_line);	//CDP NEI 1
	regex exp4(
			"^([^ \t\r\n]*)[ \t\r\n]*([^ ]*[ ][^ ]*)[ ]*[0-9]*[ ]*R S I[ ]*[^ ]*[ ]*([^ ]*[ ][^ \r\n]*)[\r\n ]*(.*)$"); //(([RSI][ ])*)[ ]*(^ )*[ ]*(^ )*[ ]*(^ )*$");  //CDP NEI 2
	regex exp5("^.*Interface[\r\n]*(.*)$", match_single_line);					//OSPF NEI 1
	regex exp6(
			"^([^ ]*)[ ]*([0-9]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*(.*)$");	//OSPF NEI 2
	regex exp7("^.*------[\r\n]*(.*)$", match_single_line);						//VLAN 1
	regex exp8(
			"^[\r\n ]*([0-9]*)[ ]*[^ ]*[ ]*([^ ]*)[ ]*([^\r\n]*)[\r\n]*(.*)$"); //VLAN 2
	regex exp9("^.*Virtual IP[\r\n]*(.*)$", match_single_line);					//STAND BY 1
	regex exp10(
			"^([^ ]*)[ ]*([0-9]*)[ ]*([0-9]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*(.*)$");	//STAND BY 2
	regex exp11("^(Clock is synchronized).*$");					//ntp status
	regex exp12(".*(crash).*", regex::icase);					//boot flash
	regex exp13("^.*Protocol[\r\n]*(.*)$", match_single_line);	//ip int brief 1
	regex exp14(
			"^([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]([^ ]*)[ ]*([^ \t]*).*$");		//ip int brief 2
	regex exp15(
			"^[\r\n\t ]*([^ ]*)[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*([^ ]*[ ]?[^ ]*)[ ]*([^ ]*)(.*)$");	//ip int brief 3
	regex exp16(
			"^([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*(.*)$");			//int status
	regex exp17(
			"^.*enabled protocol ([^ \r\n]*).*Root ID.*Address[ ]*([^ \r\n]*).*Bridge ID.*Address[ ]*([^ \r\n]*).*-----\r\n(.*)$",
			match_single_line); //spann_vlan
	regex exp18(
			"^.*Success rate is ([0-9]*).*min/avg/max = ([0-9]*)/([0-9]*)/([0-9]*).*$");	//ping
	regex exp19("^.*Cells St[\r\n]*(.*)$", match_single_line);	//atm pvc 1
	regex exp20(
			"^[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*[^ ]*[ ]*([^ ]*).*$"); //atm pvc 2
	regex exp21(
			"^([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*[^ \r\n]*[ \r\n]*(.*)$");
	regex exp22("^[0-9]*[ ]*[^ ]*[ ]*[^ ]*[ ]*(.*\\(P\\).*)*$");
	regex exp23("^.*input errors,[ ]*([0-9]*)[ ]*CRC.*$");
	regex exp24("^SONET .*? is ([^\.]*)\..*$");
	regex exp25("^[0-9,]*[ ]*([^ ]*[ ]+[^ ]*)[ ]*([^ ]*)[ ]*(.*)$");
	regex exp26(
			"^.*Memory \\(bytes\\)[\r\n]*(.*)Intra-area:.*$",
			match_single_line);
	regex exp27("^[^ ]*[ ]*([^ ]*)[ ]*([^ ]*).*$");
	regex exp28(
			"^[ ]*[0-9]*[ ]*[0-9]*[ ]*([0-9]*)[ ]*([0-9]*)[ ]*([0-9]*)[ ]*([0-9]*)[ ]*[ \r\n]*(.*)$");
	regex exp29("^.*my state = ([0-9]*) -ACTIVE.*$");
	regex exp30("^.*Hw     Status[\r\n]*.*------[\r\n]*(.*)$");
	regex exp31("^.*Average System Utilization:[ ]*([0-9]*)%.*$");
	regex exp32(
			"^Memory: allocated[ ]*([^ ]*), left[ ]*([^ ]*), frag[ ]*([^ ]*)$");
	regex exp33("^alloc ([^/]*)/max ([^,]*).*$");
	regex exp34("^Last 1 minute:[ ]*([^,]*).*$");
	regex exp35("^.*VLAN State VSD[ \r\n]+(.*)$", match_single_line);
	regex exp36(
			"^[\r\n\t ]*([^ \t]*)[ \t]*([^ \t]*)[ \t]*([^ \t]*)[ \t]*([^ \t]*)[ \t]*([^ \t]*)[ \t]*([^ \t]*)[ \t]*([^ \t]*)(.*)$");
	regex exp37("^.*[ ]*([0-9]+) input errors,.*$");
	regex exp38("^.*(MULTIPLE_FRAME_ESTABLISHED).*$");
	regex exp39("^[\t\r\n ]+(.*?)[\r\n\t ]*Port[ ]+Vlans.*$");
	regex exp40("^.*(group priority preempt.*)total number.*$");
	regex exp41(
			"^.*Power Supply: ([^\r\n]*)[\r\n\t]+Fan Status: ([^\r\n]*)[\r\n\t]+CPU Temperature:.*$");
	regex exp42(
			"^.*?(VLAN[0-9]*).*Address[ \t]*([^\r\n]*).*Aging Time[ ]*[0-9]*(.*)$");

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
	std::string in2 = "Processor Pool Total:  378228080 Used:  130288836 Free:  247939244\
		I/O Pool Total:   67108864 Used:   13606672 Free:   53502192";
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
	std::string in8 = "1    default                          active    \r\n\
		2    MGT                              active    Gi4/24\r\n\
		17   RSPAN_CWJY_B4.2                  active    \r\n\
		110  JY_B4.2                          active    Gi4/1, Gi4/2\r\n\
		700  PD-JY6504A12_To_PD-JY2000B12     active    Gi1/2, Gi2/2";
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
	std::string in22 = "1      Po1(SU)          -        Gi1/1(P)       Gi2/1(P)";
	std::string in23 = "GigabitEthernet1/2 is up, line protocol is up (connected)\r\n\
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
			 0 input errors, 90 CRC, 0 frame, 0 overrun, 0 ignored\r\n\
			 0 watchdog, 0 multicast, 0 pause input\r\n\
			 0 input packets with dribble condition detected\r\n\
			 11251412 packets output, 799994724 bytes, 0 underruns\r\n\
			 0 output errors, 0 collisions, 0 interface resets\r\n\
			 0 babbles, 0 late collision, 0 deferred\r\n\
			 0 lost carrier, 0 no carrier, 0 PAUSE output\r\n\
			 0 output buffer failures, 0 output buffers swapped out";

	std::string in24 = "SONET 4/0 is up.\r\n\
		Channelized OC-3/STM-1 SMI PA\r\n\
		H/W Version : 24.257.2.5, ROM Version : 1.2\r\n\
		FREEDM version : 2, F/W Version : 1.19.0\r\n\
		Applique type is Channelized Sonet/SDH\r\n\
		Clock Source is Internal, AUG mapping is AU4.\r\n\
\r\n\
		Medium info:\r\n\
Type: SDH, Line Coding: NRZ, Line Type: Short SM";

	std::string in25 = "0,1       NPEG100 (Active)    Up              1y1w ago\r\n\
		2,3       NPEG100 (Standby)   Up              1y1w ago\r\n\
		4         1PA Carrier Card    Active          1y1w ago\r\n\
		5         PA Carrier Card     Deactivated     Unknown\r\n\
\r\n\
		FPGA information:\r\n\
	Hardware            FPGA version\r\n\
		Slot Card Type           Version     Bundled    Flash    Current   \r\n\
		---- ---------           --------    -------   -------   -------   \r\n\
		0   NPEG100              02.02       02.05     02.05     02.05  \r\n\
		4   1PA Carrier Card     02.01       01.40     01.40     01.40  ";
	std::string in26 = "IP routing table name is default (0x0)\r\n\
		IP routing table maximum-paths is 32\r\n\
		Route Source    Networks    Subnets     Replicates  Overhead    Memory (bytes)\r\n\
		connected       0           83          0           4352        14276\r\n\
		static          0           38          0           1976        6536\r\n\
		ospf 100        9           296         0           15860       53680\r\n\
		Intra-area: 10 Inter-area: 3 External-1: 292 External-2: 0\r\n\
		NSSA External-1: 0 NSSA External-2: 0\r\n\
		internal        7                                               17900\r\n\
		Total           16          417         0           22188       92392";
	std::string in27 = "connected       0           83          0           4352        14276";
	std::string in28 = "    1       44          0          6          33          0\r\n\
		2       0          0          0          0          0\r\n\
		4       0          0          0          0          0";
	std::string in29 = "       my state = 13 -ACTIVE \r\n\
		peer state = 8  -STANDBY HOT \r\n\
		Mode = Duplex\r\n\
		Unit = Primary\r\n\
		Unit ID = 1\r\n\
\r\n\
		Redundancy Mode (Operational) = sso\r\n\
		Redundancy Mode (Configured)  = sso\r\n\
		Redundancy State              = sso\r\n\
		Maintenance Mode = Disabled";
	std::string in30 = "Mod Ports Card Type                              Model              Serial No.\r\n\
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
		1  MSFC3 Daughterboard         WS-SUP720          SAL1429N2PD  5.0    Ok";
	string	in31 = "Average System Utilization:  10%\r\n\
		Last 1 minute:  2%, Last 5 minutes:  2%, Last 15 minutes:  2%";
	string	in32 = "Memory: allocated 564280480, left 1203610368, frag 248";
	string	in33 = "alloc 502/max 524288, alloc failed 0, mcast alloc 0, di alloc failed 0\r\n\
		total reserved 0, free sessions in shared pool 523786\r\n\
		slot 2: hw0 alloc 110/max 1048575";
	string	in34 = "Last 1 minute: 2784, Last 5 minute: 15856, Last 15 minute: 48554";
	string	in35 = "\r\n\
		A - Active, I - Inactive, U - Up, D - Down, R - Ready \r\n\
\r\n\
		Interfaces in vsys Root: \r\n\
	Name           IP Address         Zone        MAC            VLAN State VSD      \r\n\
		mgt            172.1.1.4/18       MGT         001b.c064.e980    -   U   -  \r\n\
		eth1/1         0.0.0.0/0          Untrust     0010.dbff.2070    -   I   0  \r\n\
		eth1/2         0.0.0.0/0          Untrust     0010.dbff.2080    -   I   0  ";
	string	in36 = "mgt            172.1.1.4/18       MGT         001b.c064.e980    -   U   -  \r\n\
		eth1/1         0.0.0.0/0          Untrust     0010.dbff.2070    -   I   0  \r\n\
		eth1/2         0.0.0.0/0          Untrust     0010.dbff.2080    -   I   0  \r\n\
		eth2/1         0.0.0.0/0          Trust       0010.dbff.2150    -   I   0  ";
	string	in37 = "ATM1/0 is up, line protocol is up \r\n\
		Hardware is ENHANCED ATM PA Plus\r\n\
		MTU 4470 bytes, sub MTU 4470, BW 149760 Kbit, DLY 80 usec, \r\n\
		reliability 255/255, txload 1/255, rxload 1/255\r\n\
		Encapsulation ATM, loopback not set\r\n\
		Encapsulation(s): AAL5 \r\n\
		8191 maximum active VCs, 2 current VCCs\r\n\
		VC Auto Creation Disabled.\r\n\
		VC idle disconnect time: 300 seconds\r\n\
		0 carrier transitions\r\n\
		Last input 00:00:00, output 00:00:03, output hang never\r\n\
		Last clearing of \"show interface\" counters 30w2d\r\n\
		Input queue: 0/75/0/0 (size/max/drops/flushes); Total output drops: 0\r\n\
		Queueing strategy: Per VC Queueing\r\n\
		30 second input rate 0 bits/sec, 1 packets/sec\r\n\
		30 second output rate 0 bits/sec, 0 packets/sec\r\n\
		10747970 packets input, 623909477 bytes, 0 no buffer\r\n\
		Received 0 broadcasts, 0 runts, 0 giants, 0 throttles\r\n\
		0 input errors, 0 CRC, 0 frame, 0 overrun, 0 ignored, 0 abort\r\n\
		7664125 packets output, 437375736 bytes, 0 underruns\r\n\
		0 output errors, 0 collisions, 0 interface resets\r\n\
		0 output buffer failures, 0 output buffers swapped out";
	string	in38 = "Global ISDN Switchtype = primary-net5\r\n\
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
	The Free Channel Mask:  0xFFFF6FFF\r\n\
	Number of L2 Discards = 0, L2 Session ID = 7";
	string	in39 = "\r\n\
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
		Po1                 110,700";
	string	in40 = "\r\n\
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
		0  1518496  master          100    0        0    0    0        3";

	string	in41 = "Chassis Environment:\r\n\
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
		Severe alarm temperature is 150'F (66'C)";
	string	in42 = "\r\n\
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
		VLAN0111\r\n\
		Spanning tree enabled protocol ieee\r\n\
		Root ID    Priority    8302\r\n\
		Address     68ef.bdeb.d690\r\n\
		Cost        3\r\n\
		Port        1665 (Port-channel1)\r\n\
		Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
\r\n\
		Bridge ID  Priority    16494  (priority 16384 sys-id-ext 110)\r\n\
		Address     68ef.bdeb.d600\r\n\
		Hello Time   2 sec  Max Age 20 sec  Forward Delay 15 sec\r\n\
		Aging Time 301\r\n\
\r\n\
		Interface           Role Sts Cost      Prio.Nbr Type\r\n\
		------------------- ---- --- --------- -------- --------------------------------\r\n\
		Gi4/2               Desg FWD 4         128.386  P2p \r\n\
		Po1                 Root FWD 3         128.1665 P2p";

	cmatch	what;

	while (1)
	{
		std::string in;
		cout <<
			"1 CPU\r\n2 MEMORY\r\n3 CDP NEIGHBOUR 1\r\n4 CDP NEIGHBOUR 2\r\n5 OSPF NEIGHBOUR 1\r\n\
6 OSPF NEIGHBOUR 2\r\n7 VLAN 1\r\n8 VLAN 2\r\n9 STAND BY 1\r\n10 STAND BY 2\r\n11 ntp status\r\n12 boot flash\r\n\
13 ip int brief 1\r\n14 ip int brief 2\r\n15 ip int brief 2\r\n16 interface status\r\n17 spann_vlan\r\n\
18 ping\r\n19 atm pvc 1\r\n20 atm pvc 2\r\n22 port bind\r\n23 CRC\r\n24 SONET is up\r\n25 Slot\r\nenter select:" <<
			endl;
		getline(cin, in);

		regex expression;

		switch (atoi(in.c_str()))
		{
				EXPR_CASE(1) EXPR_CASE(2) EXPR_CASE(3) EXPR_CASE(4) EXPR_CASE(
						5) EXPR_CASE(6) EXPR_CASE(7) EXPR_CASE(8) EXPR_CASE(9) EXPR_CASE(
						10) EXPR_CASE(11) EXPR_CASE(12) EXPR_CASE(13) EXPR_CASE(
						14) EXPR_CASE(15) EXPR_CASE(16) EXPR_CASE(17) EXPR_CASE(
						18) EXPR_CASE(19) EXPR_CASE(20) EXPR_CASE(21) EXPR_CASE(
						22) EXPR_CASE(23) EXPR_CASE(24) EXPR_CASE(25) EXPR_CASE(
						26) EXPR_CASE(27) EXPR_CASE(28) EXPR_CASE(29) EXPR_CASE(
						30) EXPR_CASE(31) EXPR_CASE(32) EXPR_CASE(33) EXPR_CASE(
						34) EXPR_CASE(35) EXPR_CASE(36) EXPR_CASE(37) EXPR_CASE(
						38) EXPR_CASE(39) EXPR_CASE(40) EXPR_CASE(41) EXPR_CASE(42)
			/*
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
		case 22:
			in = in22;
			expression = exp22;
			break;
		case 23:
			in = in23;
			expression = exp23;
			break;
		case 24:
			in = in24;
			expression = exp24;
			break;
		case 25:
			in = in25;
			expression = exp25;
			break;
		case 26:
			in = in26;
			expression = exp26;
			break;
		case 27:
			in = in27;
			expression = exp27;
			break;
		case 28:
			in = in28;
			expression = exp28;
			break;
		case 29:
			in = in29;
			expression = exp29;
			break;
		case 30:
			in = in30;
			expression = exp30;
			break;
			EXPR_CASE(31)
*/
			default:
				return;
		}

		cout << "ori str:" << endl << in << endl;

		if (regex_match(in.c_str(), what, expression))
		{
			for (int i = 1; i < what.size(); i++)
			{
				string	tmp = trim((char *)what[i].str().c_str());
				cout <<
					"match str:\n" <<
					what[i].str() <<
					" size=" <<
					tmp.length() <<
					" pos=" <<
					what.position() <<
					endl;
			}
		}
		else
		{
			cout << "Error Input" << endl;
		}
	}
}

int test_submatch_result(void)
{
	string	result = "Codes: L - local, C - connected, S - static, R - RIP, M - mobile, B - BGP\r\n\
       D - EIGRP, EX - EIGRP external, O - OSPF, IA - OSPF inter area \r\n\
       N1 - OSPF NSSA external type 1, N2 - OSPF NSSA external type 2\r\n\
       E1 - OSPF external type 1, E2 - OSPF external type 2\r\n\
       i - IS-IS, su - IS-IS summary, L1 - IS-IS level-1, L2 - IS-IS level-2\r\n\
       ia - IS-IS inter area, * - candidate default, U - per-user static route\r\n\
       o - ODR, P - periodic downloaded static route, + - replicated route\r\n\
\r\n\
Gateway of last resort is not set\r\n\
\r\n\
      10.0.0.0/8 is variably subnetted, 410 subnets, 6 masks\r\n\
O E1     10.0.0.0/12 [110/5] via 10.32.253.254, 7w0d, GigabitEthernet0\r\n\
O E1     10.10.2.0/24 [110/5] via 10.32.253.254, 6w4d, GigabitEthernet0\r\n\
O E1     10.16.0.0/12 [110/5] via 10.32.253.254, 7w0d, GigabitEthernet0\r\n\
O E1     10.32.0.0/12 [110/5] via 10.32.253.254, 7w0d, GigabitEthernet0\r\n\
O E1     10.32.0.0/30 [110/3] via 10.32.253.7, 4d04h, GigabitEthernet0\r\n\
O E1     10.32.0.4/30 [110/5] via 10.32.253.7, 4d18h, GigabitEthernet0\r\n\
C        10.32.7.0/30 is directly connected, Serial4/0.1/1/1/1:0\r\n\
L        10.32.7.1/32 is directly connected, Serial4/0.1/1/1/1:0\r\n\
C        10.32.7.4/30 is directly connected, Serial4/0.1/1/1/2:0\r\n\
L        10.32.7.5/32 is directly connected, Serial4/0.1/1/1/2:0\r\n\
C        10.32.7.12/30 is directly connected, Serial4/0.1/1/2/1:0\r\n\
L        10.32.7.13/32 is directly connected, Serial4/0.1/1/2/1:0\r\n\
C        10.32.7.16/30 is directly connected, Serial4/0.1/1/2/2:0\r\n\
L        10.32.7.17/32 is directly connected, Serial4/0.1/1/2/2:0\r\n\
C        10.32.7.24/30 is directly connected, Serial4/0.1/1/3/1:0\r\n\
L        10.32.7.25/32 is directly connected, Serial4/0.1/1/3/1:0\r\n\
C        10.32.7.28/30 is directly connected, Serial4/0.1/1/3/2:0\r\n\
L        10.32.7.29/32 is directly connected, Serial4/0.1/1/3/2:0\r\n\
C        10.32.7.36/30 is directly connected, Serial4/0.1/1/4/1:0\r\n\
L        10.32.7.37/32 is directly connected, Serial4/0.1/1/4/1:0\r\n\
C        10.32.7.40/30 is directly connected, Serial4/0.1/1/4/2:0\r\n\
L        10.32.7.41/32 is directly connected, Serial4/0.1/1/4/2:0\r\n\
C        10.32.7.48/30 is directly connected, Serial4/0.1/1/5/1:0\r\n\
L        10.32.7.49/32 is directly connected, Serial4/0.1/1/5/1:0\r\n\
C        10.32.7.52/30 is directly connected, Serial4/0.1/1/5/2:0\r\n\
L        10.32.7.53/32 is directly connected, Serial4/0.1/1/5/2:0\r\n\
C        10.32.7.60/30 is directly connected, Serial4/0.1/1/6/1:0\r\n\
L        10.32.7.61/32 is directly connected, Serial4/0.1/1/6/1:0\r\n\
C        10.32.7.64/30 is directly connected, Serial4/0.1/1/6/2:0\r\n\
L        10.32.7.65/32 is directly connected, Serial4/0.1/1/6/2:0\r\n\
C        10.32.7.72/30 is directly connected, Serial4/0.1/1/7/1:0\r\n\
L        10.32.7.73/32 is directly connected, Serial4/0.1/1/7/1:0";

	vector<map<int, string> > regularparams;

	map<int, string> params1;
	params1[0] = "L";
	params1[1] = "10.32.7.1";
	params1[2] = "connected";
	params1[3] = "Serial4/0.1/1/1/1:0";

	regularparams.push_back(params1);

	map<int, string> params2;
	params2[0] = "C";
	params2[1] = "10.32.7.60";
	params2[2] = "connected";
	params2[3] = "Serial4/0.1/1/6/1:0";

	regularparams.push_back(params2);

	//将返回结果按行拆分
	vector<string>	rows;
	CConfigConnector::splitStringBySeprator(result, "\r\n", rows);

	//查找给定的内容是否和上面的行相匹配
	for (int j = 0; j < regularparams.size(); ++j)
	{
		bool bOneRowMatch = false;
		for (int i = 0; i < rows.size(); ++i)
		{
			bOneRowMatch = true;

			map<int, string>::iterator	r_i = regularparams[j].begin();
			while (r_i != regularparams[j].end())
			{
				size_t	pos = rows[i].find(r_i->second);
				if (pos == string::npos)
				{
					bOneRowMatch = false;
					break;
				}
				else
				{
					//排除真子集的情况，一定要完整匹配
					if (pos == 0)
					{
						if (isalnum(rows[i][pos + r_i->second.size()]))
						{
							bOneRowMatch = false;
							break;
						}
					}
					else
					{
						if (isalnum(rows[i][pos - 1])
						||	isalnum(rows[i][pos + r_i->second.size()]))
						{
							bOneRowMatch = false;
							break;
						}
					}

					++r_i;
				}
			}

			if (bOneRowMatch)
			{
				break;
			}
		}

		if (!bOneRowMatch)
		{
			return -1;
		}
	}

	return 0;
}

int test_submatch_attrlist(void)
{
	vector<map<int, string> > regularparams;

	map<int, string> params1;
	params1[0] = "1";
	params1[1] = "active";
	params1[2] = "";

	regularparams.push_back(params1);

	map<int, string> params2;
	params2[0] = "2";
	params2[1] = "active";
	params2[2] = "Gi4/1, Gi4/2";

	regularparams.push_back(params2);

	vector<map<string, string> > valuelist;

	map<string, string> params11;
	params11["VLAN"] = "1";
	params11["Status"] = "active";
	params11["Ports"] = "";

	valuelist.push_back(params11);

	map<string, string> params21;
	params21["VLAN"] = "2";
	params21["Status"] = "active";
	params21["Ports"] = "Gi4/1, Gi4/2";

	valuelist.push_back(params21);

	map<string, string> params31;
	params31["VLAN"] = "3";
	params31["Status"] = "active";
	params31["Ports"] = "Gi4/1, Gi4/2";

	valuelist.push_back(params31);

	vector<string>	attrlist;

	attrlist.push_back("VLAN");
	attrlist.push_back("Status");
	attrlist.push_back("Ports");

	//查找给定的内容是否和上面的行相匹配
	for (int j = 0; j < regularparams.size(); ++j)
	{
		bool bOneRowMatch = false;
		for (int i = 0; i < valuelist.size(); ++i)
		{
			bOneRowMatch = true;

			map<int, string>::iterator	r_i = regularparams[j].begin();

			while (r_i != regularparams[j].end())
			{
				if (attrlist.size() < r_i->first + 1)
				{
					printf(
						"attrlist size:%d != regularparams size:%d in %s\n",
						attrlist.size(),
						r_i->first,
						__FUNCTION__);
					return -1;
				}

				map<string, string>::iterator v_i = valuelist[i].find(
						attrlist[r_i->first]);
				if (v_i != valuelist[i].end())
				{
					if (r_i->second.compare(v_i->second) != 0)
					{
						bOneRowMatch = false;
						break;
					}
					else
					{
						++r_i;
					}
				}
				else
				{
					bOneRowMatch = false;
					break;
				}
			}

			if (bOneRowMatch)
			{
				break;
			}
		}

		if (!bOneRowMatch)
		{
			return -1;
		}
	}

	return 0;
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
int test_main(void)
{
	test_regex();

	//	test_regex_match();
	//	test_submatch_result();
	//	test_submatch_attrlist();
	return 0;
}
