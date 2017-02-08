/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSynConnector.cpp
///@brief	实现了连接配置管理服务器通信消息的类
///@history
///20110112	周建军		创建该文件
#include "Config.h"
#include "CSynConnector.h"
#include "ping_common.h"
#include "UFCopy.h"
#include "CTelnetConnThread.h"
#include "CSysLogReader.h"
#include <monitorIndex.h>
#include "CCrypto.h"

int g_count_dev = 0;					/* hosts that we have detected */

CMutex	g_Lock;
CMutex	g_RspDetectLock;
//extern CMutex g_cbLock;


CSynConnector *CSynConnector::	pInstance = NULL;

// 定义主备指标
static CBoolMonitorIndex *s_pIsMasterIndex = new CBoolMonitorIndex
	("IsMaster", 20);

enum TASK_INFO
{
	BASE_INFO	= 1,
	STATUS_INFO,
};

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;			// 数据包输出到文件
#endif
extern const char *INI_FILE_NAME;
extern int	g_nstartSeq;
extern char g_msysNetArea;
extern CSysLogReader *g_pSyslogReader;
extern CTaskInfoManager g_TaskInfoManager;
extern map<string, int> g_mapDeviceNo;	// 保存设备信息及其数组内偏移位置
extern int	g_nDeviceNo;				// 保存当前设置计数
extern CTelnetDevice g_Devices[MAX_DEVICE_NUM]; // 保存设备配置信息的数组
extern char g_mCommunity[];
extern bool g_isMasterRole;
extern map<string, string> g_mapoidAttr;

void CheckDeviceInfo(CFTDSysNetDeviceField dev);

void CheckDeviceInfo(CFTDSysNetDeviceField dev)
{
	if (strlen(dev.ObjectID.getValue()) > 0
	&&	strlen(dev.IPADDR.getValue()) > 0
	&&	strlen(dev.USERNAME.getValue()) > 0
	&&	strlen(dev.PASSWD.getValue()) > 0
	&&	strlen(dev.ENPASSWD.getValue()) > 0
	&&	dev.CFGSAVETYPE > 0)
	{
		map<string, int>::iterator	mapIt = g_mapDeviceNo.find(
				dev.ObjectID.getValue());
		int iDeviceNo;
		if (mapIt == g_mapDeviceNo.end())
		{
			g_nDeviceNo++;
			g_mapDeviceNo[dev.ObjectID.getValue()] = g_nDeviceNo;
			iDeviceNo = g_nDeviceNo - 1;
		}
		else
		{
			iDeviceNo = mapIt->second - 1;
		}

		{	/// Added by Henchi, 20101102
						/// for telnetThread
			list<string> CmdList;
			CmdList.push_back("term length 0");
			CmdList.push_back("show running-config");

			//CmdList.push_back("quit");
			int iPort = dev.CFGSAVETYPE == ssh ? PORT_SSH : PORT_TELNET;

			//密码改成加密模式  20130401
			CDesEncryptAlgorithm key;
			key.SetPassword("monitor");
			char buff[256]="\0";
			key.Decrypt((char *)(dev.PASSWD.getValue()),buff);
			string Password = buff;
			memset(buff, 256, 0);
			key.Decrypt((char *)(dev.ENPASSWD.getValue()),buff);
			string CfgPassword = buff;
			g_Devices[iDeviceNo] = CTelnetDevice(
					CObjectIDName(dev.ObjectID.getValue()),
					CTelnetConnEntry(
						dev.IPADDR.getValue(),
						23,
						ssh,
						dev.USERNAME.getValue(),
						Password.c_str(),
						CfgPassword.c_str(),
						CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP);

#if 0
			static CTelnetDevice Devices[MAX_DEVICE_NUM] =
			{
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device01"),
					CTelnetConnEntry(
							"172.1.128.1",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device02"),
					CTelnetConnEntry(
							"172.1.128.2",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device03"),
					CTelnetConnEntry(
							"172.1.128.3",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device04"),
					CTelnetConnEntry(
							"172.1.128.4",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device05"),
					CTelnetConnEntry(
							"172.1.128.5",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device06"),
					CTelnetConnEntry(
							"172.1.128.6",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device07"),
					CTelnetConnEntry(
							"172.1.128.7",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device08"),
					CTelnetConnEntry(
							"172.1.128.99",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device09"),
					CTelnetConnEntry(
							"172.1.128.100",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device10"),
					CTelnetConnEntry(
							"172.1.128.101",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device11"),
					CTelnetConnEntry(
							"172.1.128.102",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device12"),
					CTelnetConnEntry(
							"172.1.128.105",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device13"),
					CTelnetConnEntry(
							"172.1.128.106",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device14"),
					CTelnetConnEntry(
							"172.1.128.109",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device15"),
					CTelnetConnEntry(
							"172.1.128.110",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device16"),
					CTelnetConnEntry(
							"172.1.128.141",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device17"),
					CTelnetConnEntry(
							"172.1.128.142",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device18"),
					CTelnetConnEntry(
							"172.1.128.143",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device19"),
					CTelnetConnEntry(
							"172.1.128.144",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device20"),
					CTelnetConnEntry(
							"172.1.128.145",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device21"),
					CTelnetConnEntry(
							"172.1.128.146",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device22"),
					CTelnetConnEntry(
							"172.1.128.149",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device23"),
					CTelnetConnEntry(
							"172.1.128.150",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device24"),
					CTelnetConnEntry(
							"172.1.128.151",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device25"),
					CTelnetConnEntry(
							"172.1.128.152",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device26"),
					CTelnetConnEntry(
							"172.1.128.153",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device27"),
					CTelnetConnEntry(
							"172.1.128.154",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device28"),
					CTelnetConnEntry(
							"172.1.128.155",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device29"),
					CTelnetConnEntry(
							"172.1.128.156",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device30"),
					CTelnetConnEntry(
							"172.1.128.157",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device31"),
					CTelnetConnEntry(
							"172.1.128.158",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device32"),
					CTelnetConnEntry(
							"172.1.128.200",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device33"),
					CTelnetConnEntry(
							"172.1.128.201",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device34"),
					CTelnetConnEntry(
							"172.1.128.202",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device35"),
					CTelnetConnEntry(
							"172.1.128.203",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device36"),
					CTelnetConnEntry(
							"172.1.128.204",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device37"),
					CTelnetConnEntry(
							"172.1.128.205",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device38"),
					CTelnetConnEntry(
							"172.1.128.206",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device39"),
					CTelnetConnEntry(
							"172.1.128.207",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device40"),
					CTelnetConnEntry(
							"172.1.128.208",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device41"),
					CTelnetConnEntry(
							"172.1.128.221",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device42"),
					CTelnetConnEntry(
							"172.1.128.222",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP),
				CTelnetDevice(
					CObjectIDName("zhangjiang", "oa", "app", "Device43"),
					CTelnetConnEntry(
							"172.1.128.236",
							23,
							ssh,
							"rsfw",
							"niuRenyg",
							"pdxqpdl5005F",
							CmdList),
					TMP_DIRNAME,
					DEFAULT_TIMESEP)
			};
#endif
		}
	}
}

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

bool CWorkThread::InitInstance(void)
{
	return true;
}

void CWorkThread::ExitInstance(void)
{
}

void CWorkThread::PingDevice(
	const char	*ip,
	const char	*mask,
	std::list<string> &hosts,
	int bound)
{
	uint32 start, val;

	getip(start, val, ip, mask);

	for (int tmp = val; tmp > bound; tmp--)
	{
		struct in_addr addr;
		addr.s_addr = ntohl(start + tmp);

		printf("ip [%s] %u\n", inet_ntoa(addr), start + tmp);

		CPing ping(3, inet_ntoa(addr));
		int result = ping.run();

		//printf("the ping result = %ld \n",ping.getReceived());
		if (result == 0 && ping.getReceived() > 0)
		{
			hosts.push_front(string(inet_ntoa(addr)));
		}
		else
		{
			printf("the ping result is false. \n");
		}
	}

	printf(
		"netsegment ip:%s,mask :%s,in where active host number is：%d.\n",
		ip,
		mask,
		hosts.size());
}

void CWorkThread::PingDevice(void)
{
	struct in_addr addr;

	//m_ipnums==0时，单ip地址探测
	int count = m_ipnums;

	do
	{
		addr.s_addr = ntohl(m_start + count);

		printf(
			"@@@@@@@@@@@@@@@@@@@ping ip [%s] %u\n",
			inet_ntoa(addr),
			m_start + count);

		CPing ping(3, inet_ntoa(addr));
		int result = ping.run();

		//printf("the ping result = %ld \n",ping.getReceived());
		if (result == 0 && ping.getReceived() > 0)
		{
			m_iplist.push_front(string(inet_ntoa(addr)));
		}
		else
		{
			printf("the ping ip[%s] result is false. \n", inet_ntoa(addr));
		}

		printf(
			"&&&&&&&&&&&ping ip [%s] %u\n",
			inet_ntoa(addr),
			m_start + count);
		count--;
	} while (count > 0);

	printf(
		"the net segment started with ip[%u] has [%d] hosts,in where active host number is %d.\n",
		m_start,
		m_ipnums,
		m_iplist.size());
}

void CWorkThread::DoSnmpDevice(void)
{
	////初始化SInfoHost
	if (m_iplist.size() > 0 && m_pSys != NULL)
	{
		//"开始探测"，匹配本次探测的网络划分信息
		string center;
		string net;

		if (m_pSys->m_detectids.find(m_reqid) != m_pSys->m_detectids.end())
		{
			m_pSys->GetNetAreaInfoByNetSubAreaID(
					m_pSys->m_detectids[m_reqid].SysNetSubAreaID.getValue(),
					net,
					center);
		}
		else
		{
			printf("error: there is no detect information!\n");
		}

		if (center.length() == 0 || net.length() == 0)
		{
			printf("error:do not find the suit center and net informations\n");
		}

		center.append(".");
		center.append(net.c_str());

		list<string>::iterator	it = m_iplist.begin();
		for (; it != m_iplist.end(); it++)
		{
			char comm[32] = "\0";
			if (m_pSys->m_comms.find(*it) != m_pSys->m_comms.end())
			{
				strcpy(comm, m_pSys->m_comms[*it].c_str());
			}
			else
			{
				strcpy(comm, g_mCommunity);
			}

			if (m_pinfoThread == NULL)
			{
				m_pinfoThread = new CGetDeviceInfoThread();
			}

			m_pinfoThread->addhosts (
					const_cast<char *>(it->c_str ()),
					comm,
					center);
		}
	}
	else
	{
		printf("warning: host number is zero.\n");
		return;
	}

	swap(m_pinfoThread->m_oids, m_pSys->m_genoids);

	if (m_pinfoThread->m_hosts.size() > 0)
	{
		m_pinfoThread->Create();
		m_pinfoThread->Join();
	}

	printf("the work thread has done the snmp work. \n");
}

void CWorkThread::Run(void)
{
	struct in_addr addr;
	addr.s_addr = ntohl(m_start);

	time_t nTime;
	char buff[32];

	printf(
		" run the thread id=[%d],start ip=[%s] \n",
		m_threadID,
		inet_ntoa(addr));

	struct tm tm_time;
	nTime = time((time_t *)NULL);
	LocalTime(&nTime, &tm_time);
	strftime(buff, 32, "%Y%m%d %H:%M:%S", &tm_time);

	printf(
		"thread id=[%d] start ping the device at time[%s]\n",
		m_threadID,
		buff);

	PingDevice();

	////发送本线程完成消息, 消息类容：线程id
	//m_pSys->RspQryNetDeviceDetectTopic( m_reqid, 2, m_threadID );
	nTime = time((time_t *)NULL);
	LocalTime(&nTime, &tm_time);
	strftime(buff, 32, "%Y%m%d %H:%M:%S", &tm_time);

	printf(
		"thread id=[%d] finish ping the device at time[%s]\n",
		m_threadID,
		buff);
	printf(
		"thread id=[%d] start snmp the device at time[%s]\n",
		m_threadID,
		buff);

#ifndef LINUX
	list<string> tmp_list;
	switch (m_threadID)
	{
		case 1:
			tmp_list.push_back("172.1.128.1");
			tmp_list.push_back("172.1.128.2");
			tmp_list.push_back("172.1.128.3");
			tmp_list.push_back("172.1.128.4");
			tmp_list.push_back("172.1.128.5");
			tmp_list.push_back("172.1.128.6");

			break;
		case 2:
			tmp_list.push_back("172.1.128.7");
			tmp_list.push_back("172.1.128.61");
			tmp_list.push_back("172.1.128.62");
			tmp_list.push_back("172.1.128.63");
			break;
		case 3:
			tmp_list.push_back("172.1.128.64");
			tmp_list.push_back("172.1.128.65");
			tmp_list.push_back("172.1.128.101");
			tmp_list.push_back("172.1.128.102");

			break;
		case 4:
			tmp_list.push_back("172.1.128.105");
			tmp_list.push_back("172.1.128.106");
			tmp_list.push_back("172.1.128.109");
			tmp_list.push_back("172.1.128.110");
			break;
		case 5:
			tmp_list.push_back("172.1.128.141");
			tmp_list.push_back("172.1.128.142");
			tmp_list.push_back("172.1.128.143");
			tmp_list.push_back("172.1.128.144");
			tmp_list.push_back("172.1.128.145");
			tmp_list.push_back("172.1.128.146");
			tmp_list.push_back("172.1.128.149");
			tmp_list.push_back("172.1.128.150");
			break;
		case 6:
			tmp_list.push_back("172.1.128.151");
			tmp_list.push_back("172.1.128.152");
			tmp_list.push_back("172.1.128.153");
			tmp_list.push_back("172.1.128.154");
			tmp_list.push_back("172.1.128.155");
			tmp_list.push_back("172.1.128.156");
			tmp_list.push_back("172.1.128.157");
			tmp_list.push_back("172.1.128.158");
			break;
		case 7:
			tmp_list.push_back("172.1.128.201");
			tmp_list.push_back("172.1.128.202");
			tmp_list.push_back("172.1.128.203");
			tmp_list.push_back("172.1.128.204");
			tmp_list.push_back("172.1.128.205");
			tmp_list.push_back("172.1.128.206");
			tmp_list.push_back("172.1.128.207");
			tmp_list.push_back("172.1.128.208");
			break;
		default:
			break;
	}

	swap(m_iplist, tmp_list);
#endif

#ifdef PINGTHREAD_DOSNMP
	if (m_pinfoThread != NULL)
	{
		m_pinfoThread->ReInitHostInfo();
	}

	DoSnmpDevice();

	nTime = time((time_t *)NULL);
	struct tm tm_time;
	LocalTime(&nTime, &tm_time);
	strftime(buff, 32, "%Y%m%d %H:%M:%S", &tm_time);

	printf(
		"thread id=[%d] finish snmp the device at time[%s]\n",
		m_threadID,
		buff);

	if (m_pinfoThread->m_hosts.size())
	{
		printf("++++++++++++++发送设备数 %d.\n", m_pinfoThread->m_hosts.size());
		m_pSys->SendHostInfo(m_pinfoThread->m_hosts, m_reqid);

		printf("+++++++++++++发送接口信息.\n");
		m_pSys->SendInterfaceInfo(m_pinfoThread->m_hosts);

		printf("+++++++++++++发送设备间的连接关系.\n");
		m_pSys->SendCDPInfo(m_pinfoThread->m_hosts);

		printf("+++++++++++++发送设备间的模块信息.\n");
		m_pSys->SendModuleInfo(m_pinfoThread->m_hosts);
	}
	else
	{
		printf("snmp 没有取到设备的有效信息.\n");
	}

	g_count_dev += m_pinfoThread->m_hosts.size();
#endif

	//发送本线程探测结束消息，消息内容：线程id
	m_pSys->RspQryNetDeviceDetectTopic(m_reqid, 3, m_threadID);

	printf("finished the work thread and exit normal\n");
}

bool CDetectWorkThread::InitInstance(void)
{
	return true;
}

void CDetectWorkThread::ExitInstance(void)
{
}

void CDetectWorkThread::DoSnmpDevice(list<string> &iplist, DWORD reqid)
{
	////初始化SInfoHost
	if (iplist.size() > 0 && m_pSys != NULL)
	{
		//"开始探测"，匹配本次探测的网络划分信息
		string center;
		string net;

		if (m_pSys->m_detectids.find(reqid) != m_pSys->m_detectids.end())
		{
			m_pSys->GetNetAreaInfoByNetSubAreaID(
					m_pSys->m_detectids[reqid].SysNetSubAreaID.getValue(),
					net,
					center);
		}
		else
		{
			printf("error: there is no detect information!\n");
		}

		if (center.length() == 0 || net.length() == 0)
		{
			printf("error:do not find the suit center and net informations\n");
		}

		center.append(".");
		center.append(net.c_str());

		list<string>::iterator	it = iplist.begin();
		for (; it != iplist.end(); it++)
		{
			char comm[32] = "\0";
			if (m_pSys->m_comms.find(*it) != m_pSys->m_comms.end())
			{
				strcpy(comm, m_pSys->m_comms[*it].c_str());
			}
			else
			{
				strcpy(comm, g_mCommunity);
			}

			if (m_pinfoThread == NULL)
			{
				m_pinfoThread = new CGetDeviceInfoThread();
			}

			m_pinfoThread->addhosts (
					const_cast<char *>(it->c_str ()),
					comm,
					center);
		}
	}
	else
	{
		printf("warning: host number is zero.\n");
		return;
	}

	swap(m_pinfoThread->m_oids, m_pSys->m_genoids);

	if (m_pinfoThread->m_hosts.size() > 0)
	{
		m_pinfoThread->Create();
		m_pinfoThread->Join();
	}

	printf("the work thread has done the snmp work. \n");
}

void CDetectWorkThread::MultiThreadDoDetect(DWORD req)
{
	uint32 start, val;
	CWorkThread *workthr[MAX_DETECT_THREAD_NUM];
	int thr_num;
	int dev_num_perthr;
	struct in_addr addr;

	list<string> iplist;

	if (m_pSys->m_detectids.find(req) != m_pSys->m_detectids.end())
	{
		getip(
			start,
			val,
			m_pSys->m_detectids[req].IP.getValue(),
			m_pSys->m_detectids[req].Mask.getValue());

		int count = val;

		if (0 == count) //单ip地址探测
		{
			thr_num = 1;
			dev_num_perthr = 1;
		}
		else
		{
			count = count - 1;
			thr_num = MAX(
					GetConfigInt(INI_FILE_NAME, "DetectThreadNum"),
					count / PINGIPNUMPERTHREAD + 1);
			dev_num_perthr = MAX(count / thr_num, 1);
		}

		addr.s_addr = ntohl(start);
		sprintf(m_pSys->m_curdetrang, "%s/%d", inet_ntoa(addr), count);
		printf(
			"the current detect rang is:[%s] in the request id=%d .\n",
			m_pSys->m_curdetrang,
			req);

		//发送探测开始消息, 消息内容包括:线程个数
		m_pSys->RspQryNetDeviceDetectTopic(req, 1, thr_num);
		if (count == 0)
		{
			workthr[0] = new CWorkThread(1);
			workthr[0]->setParas(start, 0, m_pSys, req);
			workthr[0]->Create();
		}
		else
		{
			int i;
			for (i = 0;
				 i < MAX_DETECT_THREAD_NUM && (i * dev_num_perthr) < count;
				 i++)
			{
				if (i < thr_num - 1)
				{
					workthr[i] = new CWorkThread(i + 1);	//线程id从1开始标号
					workthr[i]->setParas(start, dev_num_perthr, m_pSys, req);

					workthr[i]->Create();

					start += dev_num_perthr;
				}
				else if (i == thr_num - 1)
				{
					workthr[i] = new CWorkThread(i + 1);
					workthr[i]->setParas(
							start,
							count - (i * dev_num_perthr),
							m_pSys,
							req);

					workthr[i]->Create();
				}
				else
				{
					workthr[i] = NULL;
				}
			}

			thr_num = MIN(thr_num, i);
		}
	}

	for (int i = 0; i < thr_num; i++)
	{
		printf(
			"wait for the work thread handle=[%d],id=[%d] doing ping.\n",
			workthr[i]->GetHandle(),
			i);
		if (workthr[i]->GetHandle())
		{
			WaitForObject(workthr[i]->GetHandle());
		}

		printf("work thread  id=[%d] had done ping.\n", i);
		iplist.insert(
				iplist.end(),
				workthr[i]->m_iplist.begin(),
				workthr[i]->m_iplist.end());
	}

#ifndef PINGTHREAD_DOSNMP
	if (m_pinfoThread != NULL)
	{
		m_pinfoThread->ReInitHostInfo();
	}

	DoSnmpDevice(iplist, req);

	if (m_pinfoThread->m_hosts.size())
	{
		printf("++++++++++++++发送设备信息.\n");
		m_pSys->SendHostInfo(m_pinfoThread->m_hosts, req);

		printf("+++++++++++++发送接口信息.\n");
		m_pSys->SendInterfaceInfo(m_pinfoThread->m_hosts);

		printf("+++++++++++++发送设备间的连接关系.\n");
		m_pSys->SendCDPInfo(m_pinfoThread->m_hosts);

		printf("+++++++++++++发送设备间的模块信息.\n");
		m_pSys->SendModuleInfo(m_pinfoThread->m_hosts);
	}
	else
	{
		printf("snmp 没有取到设备的有效信息.\n");
	}

	g_count_dev += m_pinfoThread->m_dev_count;
#endif
	m_pSys->Send_FTDC_CHAIN_LAST_Msg(FTD_TID_RspQryNetDeviceTopic);
	m_pSys->Send_FTDC_CHAIN_LAST_Msg(FTD_TID_RspQryNetInterfaceTopic);
	m_pSys->Send_FTDC_CHAIN_LAST_Msg(FTD_TID_RspQryNetDeviceLinkedTopic);
	m_pSys->Send_FTDC_CHAIN_LAST_Msg(FTD_TID_RspQryNetModuleTopic);

	//发送探测开始消息, 消息内容包括:探测到的设备总数
	m_pSys->RspQryNetDeviceDetectTopic(req, 4, g_count_dev);
}

void CDetectWorkThread::Run(void)
{
	//执行探测请求的id号
	DWORD reqid;

	while (true)
	{
		if (m_pSys->m_listreq.get(reqid))
		{
			m_detLock.Lock();

			printf("开始探测请求id=[%d]的工作.\n", reqid);

			//探测结果清零
			g_count_dev = 0;

			MultiThreadDoDetect(reqid);

			//发送探测结束消息
			m_pSys->RspQryNetDeviceDetectTopic(reqid);

			printf("探测请求id=[%d]工作结束.\n", reqid);

			memset(m_pSys->m_curdetrang, 0, 32);

			m_detLock.UnLock();
		}

		SLEEP(3 * 1000);
	}

	//MultiThreadDoDetect();
	
		////发送探测结束消息
	//m_pSys->RspQryNetDeviceDetectTopic( m_reqid );
	//printf("探测工作结束\n");
}

bool CCheckConnThread::InitInstance(void)
{
	return true;
}

void CCheckConnThread::ExitInstance(void)
{
}

void CCheckConnThread::Run(void)
{
	char time_buff[10] = "\0";
	char date_buff[10] = "\0";
	char name[128] = "\0";
	hostent *ph = NULL;
	struct in_addr addr;
	CFTDRtnNetLocalPingResultInfoField field;

	if (gethostname(name, 128) == 0)
	{
		ph = gethostbyname(name);
	}

	//取第一个地址
	if (ph != NULL)
	{
		memcpy(&addr, ph->h_addr_list[0], sizeof(struct in_addr));
		printf(" the first address is: %s \n", inet_ntoa(addr));
	}

	while (true)
	{
		if (g_isMasterRole)
		{
			time_t nTime = time((time_t *)NULL);
			struct tm tm_time;
			LocalTime(&nTime, &tm_time);
			strftime(time_buff, 10, "%H:%M:%S", &tm_time);
			strftime(date_buff, 10, "%Y%m%d", &tm_time);

			NET_IP_MAP map_ip = CSynConnector::GetInstancePoint()->GetDeviceIP();
			//g_cbLock.Lock();
			for (NET_IP_MAP_ITERATOR it = map_ip.begin();
				 it != map_ip.end();
				 it++)
			{
				memset(&field, 0, sizeof(CFTDRtnNetLocalPingResultInfoField));
				field.SouIPADDR = inet_ntoa(addr);
				field.SouNAME = name;
				field.TarIPADDR = it->first.c_str();
				field.TarNAME = CSynConnector::GetInstancePoint()->GetDevNameByIP(it->first.c_str());
				field.PTimeSta = time_buff;
				field.PDateSta = date_buff;

				CPing ping(3, (char *)(it->first.c_str()));
				int result = ping.run();
				if (result == 0 && ping.getReceived() > 0)
				{
					field.ConnRate = 1;
					printf(
						"the ping ip[%s] result is true. \n",
						it->first.c_str());
				}
				else
				{
					field.ConnRate = 0;
					printf(
						"the ping ip[%s] result is false. \n",
						it->first.c_str());

					int id_type = 0;
					int id_manu = 0;
					string objID = "";
					CSynConnector::GetInstancePoint()->GetNetDeviceInfoIDByIP(
							it->first.c_str(),
							id_type,
							id_manu,
							objID);

					//产生事件
					CFTDRtnSyslogEventField syslogEvent;
					memset(&syslogEvent, 0x00, sizeof(syslogEvent));
					syslogEvent.ObjectID = objID.c_str();
					syslogEvent.MonDate = date_buff;
					syslogEvent.MonTime = time_buff;
					syslogEvent.OccurDate = date_buff;
					syslogEvent.OccurTime = time_buff;
					syslogEvent.EventName = "DEVICE_IS_ONLINE";
					syslogEvent.FullEventName = "设备不在线";

					/// 事件处理标识调整为"G"，表示系统生成的日志事件
					syslogEvent.ProcessFlag = "G";
					syslogEvent.WarningLevel = "Level4";
					syslogEvent.EventDes = "Device is offline.'";
					syslogEvent.EventDealDes = "";
					syslogEvent.IPAddress = it->first.c_str();

					g_TaskInfoManager.AddTMSyslogEventField(syslogEvent);

					CFTDRtnWarningEventField warningEvent;
					memset(&warningEvent, 0x00, sizeof(warningEvent));
					warningEvent.ObjectID = objID.c_str();
					warningEvent.MonDate = date_buff;
					warningEvent.MonTime = time_buff;
					warningEvent.OccurDate = date_buff;
					warningEvent.OccurTime = time_buff;
					warningEvent.EventName = "DEVICE_IS_ONLINE";
					warningEvent.FullEventName = "设备不在线";
					warningEvent.ProcessFlag = "N";
					warningEvent.WarningLevel = "Level4";
					warningEvent.EventDes = "Device is offline..'";
					warningEvent.EventDealDes = "";
					warningEvent.IPAddress = it->first.c_str();

					g_TaskInfoManager.AddTMWarningEvent(warningEvent);
				}

				g_TaskInfoManager.AddLocalPingResult(field);
			}
			//g_cbLock.UnLock();
		}

		SLEEP(60 * 1000);	//一分钟
	}
}

CSynConnector::CSynConnector(CReactor *pReactor) :
	CSessionFactory(pReactor, 1)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	memset(m_curdetrang, 0, 32);
	m_Flag = false;
	m_hashconfig = false;
	m_detecting = false;
	m_pSession = NULL;
	m_pThread = NULL;
	m_pdetthread = NULL;
	m_nThreadNum = 0;
	m_nCurentDisThreadID = 0;
	m_pTaskManagerThread = NULL;
}

CSession *CSynConnector::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CSynConnector::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);

	time_t timep;
	time(&timep);

	printf(
		"\t %s CSynConnector::OnSessionConnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);
	m_Flag = true;

	if (m_sysNets.size() > 0
	&&	m_sysNetSubs.size() > 0
	&&	m_sysNetSubIPs.size() > 0)
	{
		m_hashconfig = true;
	}

	m_pSession = (CFTDCSession *)pSession;

	//// 测试和配置管理服务的连通性及数据包处理 20110112
	//m_pkgSend.PreparePackage(FTD_TID_ReqUserLogin, FTDC_CHAIN_LAST, FTD_VERSION);
	//CFTDReqUserLoginField fieldLogin;
	//memset(&fieldLogin, 0, sizeof(fieldLogin));
	//fieldLogin.UserID = "snmpmanager";
	//fieldLogin.Password = "snmpmanager";
	//FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
	//((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		//// 20110112
	
		/////manager登录配置服务的身份信息.
	m_pkgSend.PreparePackage(
			FTD_TID_ReqConfigLoginTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqConfigLoginField fieldconfLogin;
	memset(&fieldconfLogin, 0, sizeof(CFTDReqConfigLoginField));
	fieldconfLogin.DataCenter = g_msysNetArea;
	fieldconfLogin.ID = g_nstartSeq;
	fieldconfLogin.HasConfig = m_hashconfig ? 1 : 0;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldconfLogin);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

	//查询网络配置划分的请求
	//RequestQry(FTD_TID_ReqQryNetAreaTopic);
	//RequestQry(FTD_TID_ReqQryNetSubAreaTopic);
	//RequestQry(FTD_TID_ReqQryNetSubAreaIPTopic);
	//请求设备、厂商信息
	//RequestQry(FTD_TID_ReqQryNetCommunityTopic);//设备通信关键字
	//RequestQry(FTD_TID_ReqQryNetManufactoryTopic);//设备厂商
	//RequestQry(FTD_TID_ReqQryNetDeviceTypeTopic);//设备型号
	//RequestQry(FTD_TID_ReqQryNetDeviceCategoryTopic);//设备类型
	//RequestQry(FTD_TID_ReqQryNetOIDTopic);
}

void CSynConnector::RequestQry(DWORD msgID)
{
	printf("ReqQryPackage:send package %0x\n", msgID);
	fflush(stdout);

	switch (msgID)
	{
		case FTD_TID_ReqQryNetAreaTopic:
			SendRequestNetAreaQry();
			break;
		case FTD_TID_ReqQryNetSubAreaTopic:
			SendRequestNetSubAreaQry();
			break;
		case FTD_TID_ReqQryNetSubAreaIPTopic:
			SendRequestNetSubAreaIPQry();
			break;
		case FTD_TID_ReqQryNetCommunityTopic:
			SendRequestNetCommQry();
			break;
		case FTD_TID_ReqQryNetManufactoryTopic:
			SendRequestDevManuQry();
			break;
		case FTD_TID_ReqQryNetDeviceTypeTopic:
			SendRequestDevSerialQry();
			break;
		case FTD_TID_ReqQryNetDeviceCategoryTopic:
			SendRequestDevTypeQry();
			break;
		case FTD_TID_ReqQryNetOIDTopic:
			SendRequestMIBOIDQry();
		default:
			break;
	}
}

void CSynConnector::SendRequestNetAreaQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetAreaTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetAreaField netareafield;
	memset(&netareafield, 0, sizeof(netareafield));

	FTDC_ADD_FIELD(&m_pkgSend, &netareafield);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

void CSynConnector::SendRequestNetSubAreaQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetSubAreaTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetSubAreaField netsubareafield;
	memset(&netsubareafield, 0, sizeof(netsubareafield));

	FTDC_ADD_FIELD(&m_pkgSend, &netsubareafield);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

void CSynConnector::SendRequestNetSubAreaIPQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetSubAreaIPTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetSubAreaIPField netsubareaipfield;
	memset(&netsubareaipfield, 0, sizeof(netsubareaipfield));

	FTDC_ADD_FIELD(&m_pkgSend, &netsubareaipfield);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

void CSynConnector::SendRequestDevTypeQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetDeviceCategoryTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetDeviceCategoryField field;
	memset(&field, 0, sizeof(field));

	FTDC_ADD_FIELD(&m_pkgSend, &field);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

void CSynConnector::SendRequestDevManuQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetManufactoryTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetManufactoryField field;
	memset(&field, 0, sizeof(field));

	FTDC_ADD_FIELD(&m_pkgSend, &field);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

void CSynConnector::SendRequestDevSerialQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetDeviceTypeTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetDeviceTypeField field;
	memset(&field, 0, sizeof(field));

	FTDC_ADD_FIELD(&m_pkgSend, &field);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

void CSynConnector::SendRequestNetCommQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetCommunityTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetCommunityField field;
	memset(&field, 0, sizeof(field));

	FTDC_ADD_FIELD(&m_pkgSend, &field);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

void CSynConnector::SendRequestMIBOIDQry(void)
{
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryNetOIDTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDReqQryNetOIDField field;
	memset(&field, 0, sizeof(field));

	FTDC_ADD_FIELD(&m_pkgSend, &field);

	m_pSession->SendRequestPackage(&m_pkgSend);
}

//发送任务状态
void CSynConnector::SendTaskStatus(int task_id, int task_status, int delay_gap)
{
	m_pkgSend.PreparePackage(
			FTD_TID_RtnNetMonitorTaskInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnNetMonitorTaskInfoField field;
	memset(&field, 0, sizeof(field));

	field.OperationType = 11;	//ask feng.qiang
	field.ID = task_id;
	field.TaskStatus = task_status;
	field.ValidFlag = delay_gap;

	FTDC_ADD_FIELD(&m_pkgSend, &field);

	if (m_pSession)
	{
		m_pSession->SendRequestPackage(&m_pkgSend);
		printf(
			"send task status to config, taskid:%d, status:%d, delay:%d\n",
			task_id,
			task_status,
			delay_gap);
	}
	else
	{
		printf(
			"config session NULL, send task status fail, id:%d, status:%d, delay:%d!\n",
			task_id,
			task_status,
			delay_gap);
	}
}

//发送任务当日执行次数
void CSynConnector::SendTaskRunTimes(int task_id, int runtimes)
{
	m_pkgSend.PreparePackage(
			FTD_TID_RtnNetMonitorTaskResultTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnNetMonitorTaskResultField field;
	memset(&field, 0, sizeof(field));

	//我们需要把操作次数同步给备份的manager, 所以数据中心
	//需要发送到synconfig, 所以复用了operationType来表示数据中心
	field.OperationType = g_msysNetArea;
	field.Task_ID = task_id;
	field.OperateTime = runtimes;

	FTDC_ADD_FIELD(&m_pkgSend, &field);

	if (m_pSession)
	{
		m_pSession->SendRequestPackage(&m_pkgSend);
		printf(
			"send task runtimes to config, taskid:%d, runtimes:%d\n",
			task_id,
			runtimes);
	}
	else
	{
		printf(
			"config session NULL, send task runtimes fail, id:%d, runtimes:%d!\n",
			task_id,
			runtimes);
	}
}

void CSynConnector::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	time_t timep;
	time(&timep);

	printf(
		"\t %s CSynConnector::OnSessionDisconnected: %0x \n",
		ctime(&timep),
		pSession);
	fflush(stdout);

	m_Flag = false;
	m_pSession = NULL;
}

int CSynConnector::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif

	//printf("\tCFlowConnector::HandlePackage:receive package %0x\n",pFTDCPackage->GetTID());
	fflush(stdout);

	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RspUserLogin:
			OnRspUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspServerTypeTopic:
			OnRspServiceRole(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetAreaTopic:
			OnRtnNetAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetAreaTopic:
			OnRspNetAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetSubAreaTopic:
			OnRtnNetSubAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetSubAreaTopic:
			OnRspNetSubAreaTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetSubAreaIPTopic:
			OnRtnNetSubAreaIPTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetSubAreaIPTopic:
			OnRspNetSubAreaIPTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetManufactoryTopic:
			OnRtnDevManuTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetManufactoryTopic:
			OnRspDevManuTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceCategoryTopic:
			OnRtnDevTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceCategoryTopic:
			OnRspDevTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceTypeTopic:
			OnRtnDevSerialTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceTypeTopic:
			OnRspDevSerialTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetCommunityTopic:
			OnRtnNetCommTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetCommunityTopic:
			OnRspNetCommTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetOIDTopic:
			OnRtnMIBOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetOIDTopic:
			OnRspMIBOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetGeneralOIDTopic:
			OnRspGenMIBOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetGeneralOIDTopic:
			OnRtnGenMIBOIDTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetTimePolicyTopic:
			OnRspTimePolicyTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetTimePolicyTopic:
			OnRtnTimePolicyTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetGatherTaskTopic:
			OnRspMonTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetGatherTaskTopic:
			OnRtnMonTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceTopic:
			OnRspNetDeviceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetDeviceTopic:
			OnRtnNetDeviceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceChgTopic:
			//OnRspChgNetDeviceTopic(pFTDCPackage, pSession); //不再响应设备objectid更改信息. 2011.11.21
			break;
		case FTD_TID_RtnNetDeviceChgTopic:
			//OnRtnChgNetDeviceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetInterfaceTopic:
			OnRspNetInterfaceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetInterfaceTopic:
			OnRtnNetIntefaceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetModuleTopic:
			OnRspNetModuleTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetModuleTopic:
			OnRtnNetModuleTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetMonitorTypeTopic:
			OnRspMonitorTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTypeTopic:
			OnRtnMonitorTypeTopic(pFTDCPackage, pSession);
			break;

		//巡检任务
		case FTD_TID_ReqQryNetMonitorTaskInfoTopic:
			OnReqLoopItemTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetMonitorTaskInfoTopic:
			OnRspLoopItemTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskInfoTopic:
			OnRtnLoopItemTopic(pFTDCPackage, pSession);
			break;

		//监控指令
		case FTD_TID_RspQryNetMonitorCommandTypeTopic:
			OnRspCommandTypeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorCommandTypeTopic:
			OnRtnCommandTypeTopic(pFTDCPackage, pSession);
			break;

		//动作族表
		case FTD_TID_RspQryNetMonitorActionGroupTopic:
			OnRspActionGroupTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorActionGroupTopic:
			OnRtnActionGroupTopic(pFTDCPackage, pSession);
			break;

		//设备对象组
		case FTD_TID_RspQryNetMonitorDeviceGroupTopic:
			OnRspDeviceGroupTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorDeviceGroupTopic:
			OnRtnDeviceGroupTopic(pFTDCPackage, pSession);
			break;

		//设备对象组明细
		case FTD_TID_RspQryNetMonitorTaskObjectSetTopic:
			OnRspQryNetMonitorTaskObjectSetTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskObjectSetTopic:
			OnRtnNetMonitorTaskObjectSetTopic(pFTDCPackage, pSession);
			break;

		//探测请求
		case FTD_TID_ReqQryNetDeviceDetectTopic:
			if (g_isMasterRole)
			{
				OnReqQryNetDeviceDetectTopic(pFTDCPackage, pSession);
			}

			break;

		//动作指标表	
		case FTD_TID_RspQryNetMonitorActionAttrTopic:
			OnRspActionAttrTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorActionAttrTopic:
			OnRtnActionAttrTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetMonitorTaskResultTopic:
			OnRspTaskRunTimeTopic(pFTDCPackage, pSession);
			break;

		//设备任务信息表    //2012.4.23
		case FTD_TID_RspQryNetMonitorDeviceTaskTopic:
			OnRspDevTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorDeviceTaskTopic:
			OnRtnDevTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetMonitorTaskInstAttrsTopic:
			OnRspInstrTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskInstAttrsTopic:
			OnRtnInstrTopic(pFTDCPackage, pSession);
			break;

		//2012.06.04 会员链路信息
		case FTD_TID_RspQryNetPartyLinkInfoTopic:
			OnRspPartLinkTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetPartyLinkInfoTopic:
			OnRtnPartLinkTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetPartyLinkStatusInfoTopic:			//标识是否第一次执行“获取设备链路状态”
			//OnRspPartLinkInfoStatus(pFTDCPackage, pSession);
			break;

		//2012.06.05 基线比对任务信息
		case FTD_TID_RspQryNetBaseLineTaskTopic:
			OnRspBaseLineTaskTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetBaseLineTaskTopic:
			OnRtnBaseLineTaskTopic(pFTDCPackage, pSession);
		default:
			break;
	}

	return 0;
}

void CSynConnector::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(
		"\t CSynConnector::OnRspUserLogin:user=%s password=%s ",
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
}

void CSynConnector::OnRspServiceRole(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspServerTypeField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	if( field.IsMaster == 1 && g_isMasterRole == false )
	{
		if( NULL != m_pTaskManagerThread )
			m_pTaskManagerThread->UpdateTime();
	}

	g_isMasterRole = field.IsMaster == 1 ? true : false;
	printf(
		"the manager server role is:[%s]\n",
		g_isMasterRole ? "MASTER" : "SLAVER");

	s_pIsMasterIndex->setValue(g_isMasterRole);
}

/*
//接收网络大区划分信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspNetAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetAreaField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetAreaField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetAreaField fielddata;

		CopySysNetAreaEntity(&fielddata, &field);

		m_sysNets[fielddata.ID.getValue()] = fielddata;

		itor.Next();
	}

	printf("receive NetArea information:[%d] records. \n", m_sysNets.size());
}

void CSynConnector::OnRtnNetAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetAreaField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	NET_AREA_MAP_ITERATOR it;
	CFTDSysNetAreaField val;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, field.ID.getValue(), m_sysNets, it);
	}
	else
	{
		CopySysNetAreaEntity(&val, &field);
		m_sysNets[field.ID.getValue()] = val;
	}
}

/*
//接收网络子区配置信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspNetSubAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetSubAreaField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetSubAreaField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetSubAreaField fielddata;

		CopySysNetSubAreaEntity(&fielddata, &field);

		m_sysNetSubs[fielddata.ID.getValue()] = fielddata;

		itor.Next();
	}
}

void CSynConnector::OnRtnNetSubAreaTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetSubAreaField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	NET_SUB_AREA_MAP_ITERATOR it;
	CFTDSysNetSubAreaField val;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(
			field,
			val,
			field.ID.getValue(),
			m_sysNetSubs,
			it);
	}
	else
	{
		CopySysNetSubAreaEntity(&val, &field);
		m_sysNetSubs[field.ID.getValue()] = val;
	}
}

/*
//接收子网络配置信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspNetSubAreaIPTopic(
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

		CopySysNetSubAreaIPEntity(&fielddata, &field);

		m_sysNetSubIPs[fielddata.ID.getValue()] = fielddata;

		itor.Next();
	}
}

void CSynConnector::OnRtnNetSubAreaIPTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetSubAreaIPField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	NET_SUB_AREA_IP_MAP_ITERATOR it;
	CFTDSysNetSubAreaIPField val;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(
			field,
			val,
			field.ID.getValue(),
			m_sysNetSubIPs,
			it);
	}
	else
	{
		CopySysNetSubAreaIPEntity(&val, &field);
		m_sysNetSubIPs[field.ID.getValue()] = val;
	}
}

/*
//接收设备厂商
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspDevManuTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetManufactoryField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetManufactoryField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetManufactoryField val;

		CopySysNetManufactoryEntity(&val, &field);

		m_devmanus[strlwr(
				(char *)field.EName.getValue(),
				strlen(field.EName.getValue()))] = val;
		
		m_IDmanu[val.ID]=val.EName.getValue();

		itor.Next();
	}
}

void CSynConnector::OnRtnDevManuTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetManufactoryField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	DEV_MANUFACTORY_MAP_ITERATOR it;
	CFTDSysNetManufactoryField val;

	string key = strlwr(
			(char *)field.EName.getValue(),
			strlen(field.EName.getValue()));
	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, key, m_devmanus, it);
	}
	else
	{
		CopySysNetManufactoryEntity(&val, &field);
		m_devmanus[key] = val;
		m_IDmanu[ val.ID ] = val.EName.getValue();
	}
}

/*
//接收设备类型信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspDevTypeTopic(
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

		CopySysNetDeviceCategoryEntity(&val, &field);

		m_devtypes[strlwr(
				(char *)field.EName.getValue(),
				strlen(field.EName.getValue()))] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnDevTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetDeviceCategoryField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	DEV_TYPE_MAP_ITERATOR it;
	CFTDSysNetDeviceCategoryField val;

	string key = strlwr(
			(char *)field.EName.getValue(),
			strlen(field.EName.getValue()));

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, key, m_devtypes, it);
	}
	else
	{
		CopySysNetDeviceCategoryEntity(&val, &field);
		m_devtypes[key] = val;
	}
}

/*
//接收网络设备型号信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspDevSerialTopic(
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

		CopySysNetDeviceTypeEntity(&val, &field);

		m_devserials[val.ID.getValue()] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnDevSerialTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetDeviceTypeField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	DEV_SERIAL_MAP_ITERATOR it;
	CFTDSysNetDeviceTypeField val;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(
			field,
			val,
			field.ID.getValue(),
			m_devserials,
			it);
	}
	else
	{
		CopySysNetDeviceTypeEntity(&val, &field);
		m_devserials[field.ID.getValue()] = val;
	}
}

/*
//接收网络通信关键字
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspNetCommTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetCommunityField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetCommunityField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		m_comms[field.IPADDR.getValue()] = field.COMMUNITY.getValue();

		itor.Next();
	}
}

void CSynConnector::OnRtnNetCommTopic(
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
void CSynConnector::OnRspMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetOIDField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetOIDField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetOIDField val;

		// add by cao.ning
		// update oid info of compound attr
		CMonDevice::UpdateCompoundAttrOid(field.EName.getValue(), field.OID.getValue());

		CopySysNetOIDEntity(&val, &field);

		string key = field.EName.getValue();
		if (!field.Manufactory.isNull())
		{
			key += CONSYM;
			key.append(
					strlwr(
						(char *)field.Manufactory.getValue(),
						strlen(field.Manufactory.getValue())));
		}

		if (!field.DeviceType.isNull())
		{
			key += CONSYM;
			key.append(
					strlwr(
						(char *)field.DeviceType.getValue(),
						strlen(field.DeviceType.getValue())));
		}

		m_oids[key] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetOIDField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CON_OID_CONTAIN_MAP_ITERATOR it;
	CFTDSysNetOIDField val;

	string key = field.EName.getValue();
	if (!field.Manufactory.isNull())
	{
		key += CONSYM;
		key.append(
				strlwr(
					(char *)field.Manufactory.getValue(),
					strlen(field.Manufactory.getValue())));
	}

	if (!field.DeviceType.isNull())
	{
		key += CONSYM;
		key.append(
				strlwr(
					(char *)field.DeviceType.getValue(),
					strlen(field.DeviceType.getValue())));
	}

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, key, m_oids, it);
	}
	else
	{
		CopySysNetOIDEntity(&val, &field);
		m_oids[key] = val;
	}
}

/*
//接收通用的oid信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspGenMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetGeneralOIDField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetGeneralOIDField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		SInfoOID oid_value;

		oid_value.Name = field.OID.getValue();
		oid_value.is_table = field.isTheTable.getValue() ? true : false;

		m_genoids[field.EName.getValue()] = oid_value;

		itor.Next();
	}
}

void CSynConnector::OnRtnGenMIBOIDTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetGeneralOIDField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	GEN_OID_MAP_ITERATOR it;
	SInfoOID val;

	string key = field.EName.getValue();

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, key, m_genoids, it);
	}
	else
	{
		val.Name = field.OID.getValue();
		val.is_table = field.isTheTable.getValue() ? true : false;
		m_genoids[key] = val;
	}
}

/*
//接收网络设备信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspNetDeviceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetDeviceField field;

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
	{
		//没有被定时器启动
		if (g_pSyslogReader->GetHandle() == (THREAD_HANDLE) 0)
		{
			g_pSyslogReader->Create();
		}
	}

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetDeviceField::m_Describe));
	CFTDSysNetDeviceField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetDeviceEntity(&val, &field);

		m_devs[field.ID.getValue()] = val;
		m_dev_ips[field.IPADDR.getValue()] = val.ID.getValue();
		g_TaskInfoManager.AddDeviceInfo(val);
		CheckDeviceInfo(val);

		itor.Next();
	}
}

void CSynConnector::OnRtnNetDeviceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetDeviceField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetDeviceField val;
	NET_DEVICE_MAP_ITERATOR it;
	map<string, int>::iterator mapIt;

	CopySysNetDeviceEntity(&val, &field);
	g_TaskInfoManager.UpdDeviceInfo(val, field.OperationType.getValue());

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			CopySysNetDeviceEntity(&val, &field);

			m_devs[field.ID.getValue()] = val;
			m_dev_ips[field.IPADDR.getValue()] = val.ID.getValue();

			CheckDeviceInfo(val);

			break;
		case 3:
			if (field.ID.getValue() == -1)
			{
				m_devs.clear();
				m_dev_ips.clear();
				break;
			}

			it = m_devs.find(field.ID.getValue());
			if (it != m_devs.end())
			{
				//2013-8-5 by Lee，修订设备删除后的ip集的同步
				NET_IP_MAP_ITERATOR it_ip = m_dev_ips.find(it->second.IPADDR.getValue());
				if(it_ip != m_dev_ips.end())
				{
					m_dev_ips.erase(it_ip);
				}
				m_devs.erase(it);
			}

			mapIt = g_mapDeviceNo.find(field.ObjectID.getValue());
			if (mapIt != g_mapDeviceNo.end())
			{
				int iDeviceNo = mapIt->second - 1;
				g_Devices[iDeviceNo].m_bValid = false;
			}

			break;
		case 4:
			it = m_devs.find(field.ID.getValue());
			if (it != m_devs.end())
			{
				if (strcmp(
						it->second.IPADDR.getValue(),
					field.IPADDR.getValue()) != 0)
				{
					m_dev_ips.erase(it->second.IPADDR.getValue());
					m_dev_ips[field.IPADDR.getValue()] = field.ID.getValue();
				}

				CopySysNetDeviceEntity(&(it->second), &field);
			}

			mapIt = g_mapDeviceNo.find(field.ObjectID.getValue());

			int iDeviceNo;
			list<string> CmdList;
			CmdList.push_back("term length 0");
			CmdList.push_back("show running-config");

			if (mapIt != g_mapDeviceNo.end())
			{
				iDeviceNo = mapIt->second - 1;
			}
			else
			{
				iDeviceNo = g_nDeviceNo;
				g_nDeviceNo++;
				g_Devices[iDeviceNo].SetPath(TMP_DIRNAME);
				g_Devices[iDeviceNo].SetJudgeRun(CJudgeRun(DEFAULT_TIMESEP));
			}

			g_Devices[iDeviceNo].SetObjectIDName(
					CObjectIDName(field.ObjectID.getValue()));

			//密码改成加密模式  20130401
			CDesEncryptAlgorithm key;
			key.SetPassword("monitor");
			char buff[256]="\0";
			key.Decrypt((char *)(field.PASSWD.getValue()),buff);
			string Password = buff;
			memset(buff, 256, 0);
			key.Decrypt((char *)(field.ENPASSWD.getValue()),buff);
			string CfgPassword = buff;
			g_Devices[iDeviceNo].SetTelnetConnEntry(
					CTelnetConnEntry(
						field.ObjectID.getValue(),
						23,
						ssh,
						field.USERNAME.getValue(),
						Password.c_str(),
						CfgPassword.c_str(),
						CmdList));

			break;
	}
}

/*
//接收网络接口信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspNetInterfaceTopic(
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
		//m_ifstrip[make_pair(
		//		field.DeviceID.getValue(),
		//		field.EName.getValue())] = field.DeviceIndex.getValue();

		m_dev_ifs[ make_pair(
			val.DeviceID.getValue(),
			val.DeviceIndex.getValue()) ] = val.ID.getValue();

		itor.Next();
	}
}

void CSynConnector::OnRtnNetIntefaceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetInterfaceField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetInterfaceField val;
	NET_INTERFACE_MAP_ITERATOR it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			CopySysNetInterfaceEntity(&val, &field);

			m_ifs[field.ID.getValue()] = val;
			//m_ifstrip[make_pair(
			//		field.DeviceID.getValue(),
			//		field.EName.getValue())] = field.DeviceIndex.getValue();

			m_dev_ifs[ make_pair(
				val.DeviceID.getValue(),
				val.DeviceIndex.getValue()) ] = val.ID.getValue();

			break;
		case 3:
			if (field.ID.getValue() == -1)
			{
				m_ifs.clear();
			}
			else
			{
				it = m_ifs.find(field.ID.getValue());
				if (it != m_ifs.end())
				{
					m_ifs.erase(it);
				}
			}

			break;
		case 4:
			it = m_ifs.find(field.ID.getValue());
			if (it != m_ifs.end())
			{
				CopySysNetInterfaceEntity(&(it->second), &field);
			}

			break;
	}
}

/*
//接收网络模块信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspNetModuleTopic(
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

		itor.Next();
	}
}

void CSynConnector::OnRtnNetModuleTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetModuleField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetModuleField val;
	NET_MODULE_MAP_ITERATOR it;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			CopySysNetModuleEntity(&val, &field);

			m_mods[field.ID.getValue()] = val;

			break;
		case 3:
			if (field.ID.getValue() == -1)
			{
				m_mods.clear();
			}
			else
			{
				it = m_mods.find(field.ID.getValue());
				if (it != m_mods.end())
				{
					m_mods.erase(it);
				}
			}

			break;
		case 4:
			it = m_mods.find(field.ID.getValue());
			if (it != m_mods.end())
			{
				CopySysNetModuleEntity(&(it->second), &field);
			}

			break;
	}
}

/*
//接收网络设备变更信息 //仅仅针对objectid变更
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspChgNetDeviceTopic(
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

			//修改对应接口的objectid
			for (NET_INTERFACE_MAP_ITERATOR it_if = m_ifs.begin();
				 it_if != m_ifs.end();
				 it_if++)
			{
				if (it_if->second.DeviceID.getValue()
						== field.DeviceID.getValue())
				{
					char buff[128] = "\0";

					string old_objid = (char *)it_if->second.ObjectID.getValue();
					sprintf(
						buff,
						"%s.%s",
						field.NewObjectID.getValue(),
						old_objid.substr(old_objid.rfind('.') + 1).c_str());

					it_if->second.DeviceObjectID = field.NewObjectID.getValue();
					it_if->second.ObjectID = buff;
				}
			}

			//修改对应模块的objectid
			for (NET_MODULE_MAP_ITERATOR it_mod = m_mods.begin();
				 it_mod != m_mods.end();
				 it_mod++)
			{
				if (it_mod->second.DeviceID.getValue()
						== field.DeviceID.getValue())
				{
					char buff[128] = "\0";

					string old_objid = it_mod->second.ObjectID.getValue();
					sprintf(
						buff,
						"%s.%s",
						field.NewObjectID.getValue(),
						old_objid.substr(old_objid.rfind('.') + 1).c_str());

					it_mod->second.ObjectID = buff;
					it_mod->second.DeviceObjectID = field.NewObjectID.getValue();
				}
			}
		}

		itor.Next();
	}
}

void CSynConnector::OnRtnChgNetDeviceTopic(
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

		//修改对应的接口objectid
		for (NET_INTERFACE_MAP_ITERATOR it_if = m_ifs.begin();
			 it_if != m_ifs.end();
			 it_if++)
		{
			if (it_if->second.DeviceID.getValue() == field.DeviceID.getValue())
			{
				char buff[128] = "\0";

				string old_objid = (char *)it_if->second.ObjectID.getValue();
				sprintf(
					buff,
					"%s.%s",
					field.NewObjectID.getValue(),
					old_objid.substr(old_objid.rfind('.') + 1).c_str());

				it_if->second.DeviceObjectID = field.NewObjectID.getValue();
				it_if->second.ObjectID = buff;
			}
		}

		//修改对应模块的objectid
		for (NET_MODULE_MAP_ITERATOR it_mod = m_mods.begin();
			 it_mod != m_mods.end();
			 it_mod++)
		{
			if (it_mod->second.DeviceID.getValue() == field.DeviceID.getValue())
			{
				char buff[128] = "\0";

				string old_objid = it_mod->second.ObjectID.getValue();
				sprintf(
					buff,
					"%s.%s",
					field.NewObjectID.getValue(),
					old_objid.substr(old_objid.rfind('.') + 1).c_str());

				it_mod->second.ObjectID = buff;
				it_mod->second.DeviceObjectID = field.NewObjectID.getValue();
			}
		}
	}
}

/*
//接收时间策略信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspTimePolicyTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetTimePolicyField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetTimePolicyField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetTimePolicyField val;

		CopySysNetTimePolicyEntity(&val, &field);

		g_TaskInfoManager.AddTimePolicyInfo(val);
		m_tpolicys[field.ID.getValue()] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnTimePolicyTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetTimePolicyField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	TIME_POLICY_MAP_ITERATOR it;
	CFTDSysNetTimePolicyField val;

	CopySysNetTimePolicyEntity(&val, &field);
	g_TaskInfoManager.UpdTimePolicyInfo(val, field.OperationType.getValue());

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, field.ID.getValue(), m_tpolicys, it);
	}
	else
	{
		if (m_tpolicys.find(field.ID.getValue()) != m_tpolicys.end())
		{
			//修改相关的任务属性（派发标志）
			g_Lock.Lock();
			for (MONITOR_TASK_MAP_ITERATOR it_task = m_montasks.begin();
				 it_task != m_montasks.end();
				 it_task++)
			{
				if (it_task->second.first.PolicyTypeID.getValue()
						== field.ID.getValue())
				{
					it_task->second.second = 0;
				}
			}

			g_Lock.UnLock();
		}

		CopySysNetTimePolicyEntity(&val, &field);
		m_tpolicys[field.ID.getValue()] = val;
	}
}

/*
//接收监控任务信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspMonTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetGatherTaskField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetGatherTaskField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetGatherTaskField val;

		CopySysNetGatherTaskEntity(&val, &field);

		g_Lock.Lock();
		m_montasks[field.ID.getValue()] = make_pair(val, PREPARE_STATUS);
		g_Lock.UnLock();

		itor.Next();
	}
}

void CSynConnector::OnRtnMonTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetGatherTaskField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetGatherTaskField val;
	MONITOR_TASK_MAP_ITERATOR it;

	g_Lock.Lock();

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2:
			CopySysNetGatherTaskEntity(&val, &field);
			m_montasks[field.ID.getValue()] = make_pair(val, PREPARE_STATUS);
			break;
		case 3:
			if (field.ID.getValue() == -1)
			{
				m_montasks.clear();
			}
			else
			{
				it = m_montasks.find(field.ID.getValue());
				if (it != m_montasks.end())
				{
					it->second.second = UNWORK_STATUS;	//标识任务无效
				}
			}

			break;
		case 4:
			if (m_montasks.find(field.ID.getValue()) != m_montasks.end())
			{
				CopySysNetGatherTaskEntity(&val, &field);
				m_montasks[field.ID.getValue()] = make_pair(val, PREPARE_STATUS);
			}

			break;
	}

	g_Lock.UnLock();
}

/*
//接收监控对象类别信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspMonitorTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTypeField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTypeField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CFTDSysNetMonitorTypeField val;

		CopySysNetMonitorTypeEntity(&val, &field);

		m_montypes[strlwr(
				(char *)field.EName.getValue(),
				strlen(field.EName.getValue()))] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnMonitorTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTypeField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorTypeField val;
	MONITOR_TYPE_MAP_ITERATOR it;

	string key = strlwr(
			(char *)field.EName.getValue(),
			strlen(field.EName.getValue()));
	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, key, m_montypes, it);
	}
	else
	{
		CopySysNetMonitorTypeEntity(&val, &field);
		m_montypes[key] = val;
	}
}

//接收任务控制
void CSynConnector::OnReqLoopItemTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorTaskInfoField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDRspQryNetMonitorTaskInfoField rspfield;
	memset(&rspfield, 0, sizeof(CFTDRspQryNetMonitorTaskInfoField));

	rspfield.ID = field.ID;
	rspfield.OperationType = field.OperationType;

	int key = field.ID.getValue();

	//CConnTaskInfo contaskinfo;
	//CSnmpTaskInfo snmptaskinfo;
	LOOP_ITEM_MAP_ITERATOR l_it = m_loopitem.find(key);

	switch (field.TaskStatus.getValue())
	{
		case TASK_STOP_EXEC:
			rspfield.TaskStatus = TASK_STOP_EXEC;

			if (l_it != m_loopitem.end())
			{
				rspfield.ValidFlag = g_TaskInfoManager.ProcessStopTaskReq(key);
			}
			else
			{
				rspfield.ValidFlag = TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
				printf("no task to stop, task_id:%d\n", key);
			}

			break;
		case TASK_PAUSE_EXEC:
			rspfield.TaskStatus = TASK_PAUSE_EXEC;
			if (l_it != m_loopitem.end())
			{
				rspfield.ValidFlag = g_TaskInfoManager.ProcessPauseTaskReq(key);
			}
			else
			{
				rspfield.ValidFlag = TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
				printf("no task to pause, task_id:%d\n", key);
			}

			break;
		case TASK_ACTIVATE_EXEC:
			rspfield.TaskStatus = TASK_WAIT_EXEC;
			if (l_it != m_loopitem.end())
			{
				rspfield.ValidFlag = g_TaskInfoManager.ProcessActivateTaskReq(key);
			}
			else
			{
				rspfield.ValidFlag = TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
				printf("no task to activate, task_id:%d\n", key);
			}

			break;
		case TASK_DELAY_EXEC:
			rspfield.TaskStatus = TASK_DELAY_EXEC;
			if (l_it != m_loopitem.end())
			{
				rspfield.ValidFlag = g_TaskInfoManager.ProcessDelayTaskReq(
						key,
						field.ValidFlag.getValue());
				rspfield.OutputPolicy_ID = field.ValidFlag.getValue();
			}
			else
			{
				rspfield.ValidFlag = TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
				printf("no task to delay, task_id:%d\n", key);
			}

			break;
		case TASK_START_EXEC:
			rspfield.TaskStatus = TASK_START_EXEC;
			if (l_it != m_loopitem.end())
			{
				printf(
					"receive the runner [%s] do task id [%d].\n",
					field.ManagerGroup.getValue(),
					key);
				//该请求中的ManagerGroup字段为当前用户（请求者）
				//ID字段为要求处理的任务ID
				rspfield.ValidFlag = g_TaskInfoManager.ProcessDoNowTaskReq(
						key,
						field.ManagerGroup.getValue()); 
			}
			else if( field.ID.getValue() == -1 )
			{
				///请求对特定设备执行某个（任务）指令
				printf(
					"receive the runner [%s] do task with commd [%s] in the device [%s].\n",
					field.ManagerGroup.getValue(),
					field.ActionGroup.getValue(),
					field.DeviceGroup.getValue() );
				//该请求中的ManagerGroup字段为当前用户（请求者），ID字段为任务ID
				// 字段ActionGroup为指令别名，DeviceGroup为指定的设备ObjectID（ID为-1时、ActionGroup、DeviceGroup必须是有效值字段）
				//该请求中的ManagerGroup字段为当前用户（请求者）
				CFTDSysNetDeviceField *hp = GetDeviceByObjID( field.DeviceGroup.getValue() );
				if( hp != NULL )
				{
					rspfield.ValidFlag = g_TaskInfoManager.ProcessDeviceTaskReq( hp, field.ActionGroup.getValue(),
						field.ManagerGroup.getValue());
				}
				else
				{
					rspfield.ValidFlag = TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
					printf("no device be found to do, device object:%s.\n", field.DeviceGroup.getValue());
				}

			}
			else
			{
				rspfield.ValidFlag = TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
				printf("no task be found to do, task_id:%d.\n", key);
			}

			break;
		default:
			rspfield.ValidFlag = TASK_STATUS_CHANGE_FAIL_TASK_STATUS_ERROR;
			printf("invalid status %d in %s\n", field.TaskStatus, __FUNCTION__);
			break;
	}

	if (rspfield.ValidFlag == TASK_STATUS_CHANGE_SUCCESS)
	{
		if (g_isMasterRole)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
			FTDC_ADD_FIELD(&m_pkgSend, &rspfield);
			((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		}

		//notify config
		CTaskCtlStatus ctlstatus;
		ctlstatus.TaskID = field.ID.getValue();
		ctlstatus.TaskStatus = field.TaskStatus.getValue();
		ctlstatus.DelayGap = field.ValidFlag.getValue();

		g_TaskInfoManager.AddTaskCtlStatus(ctlstatus);
	}
}

void CSynConnector::OnRspLoopItemTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTaskInfoField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTaskInfoField::m_Describe));

	CFTDSysNetMonitorTaskInfoField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		if (BASE_INFO == field.OperationType)
		{
			CopySysNetMonitorTaskInfoEntity(&val, &field);
			g_TaskInfoManager.AddTaskInfo(val);
			m_loopitem[val.ID.getValue()] = val;
		}
		else if (STATUS_INFO == field.OperationType)
		{
			printf(
				"task status update success, task_id:%d, newstatus:%d, validflag:%d\n",
				field.ID.getValue(),
				field.TaskStatus.getValue(),
				field.ValidFlag.getValue());
			fflush(stdout);

			g_TaskInfoManager.map_Task[field.ID.getValue()].TaskStatus = field.TaskStatus;
			g_TaskInfoManager.map_Task[field.ID.getValue()].ValidFlag = field.ValidFlag;
		}

		itor.Next();
	}
}

void CSynConnector::OnRtnLoopItemTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTaskInfoField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorTaskInfoField val;
	CopySysNetMonitorTaskInfoEntity(&val, &field);
	g_TaskInfoManager.UpdTaskInfo(val, field.OperationType.getValue());

	LOOP_ITEM_MAP_ITERATOR it;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, field.ID.getValue(), m_loopitem, it);
	}
	else
	{
		CopySysNetMonitorTaskInfoEntity(&val, &field);
		m_loopitem[field.ID.getValue()] = val;
	}
}

void CSynConnector::OnRspTaskRunTimeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTaskResultField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTaskResultField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		printf(
			"task runtimes update success, taskid:%d, runtimes:%d\n",
			field.Task_ID.getValue(),
			field.OperateTime.getValue());

		g_TaskInfoManager.UpdateTaskTimes(
				field.Task_ID.getValue(),
				field.OperateTime.getValue());

		itor.Next();
	}
}

//接收巡检指令
void CSynConnector::OnRspCommandTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorCommandTypeField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorCommandTypeField::m_Describe));

	CFTDSysNetMonitorCommandTypeField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorCommandTypeEntity(&val, &field);
		g_TaskInfoManager.AddCommandInfo(val);
		m_commands[val.ID.getValue()] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnCommandTypeTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorCommandTypeField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorCommandTypeField val;
	CopySysNetMonitorCommandTypeEntity(&val, &field);
	g_TaskInfoManager.UpdCommandInfo(val, field.OperationType.getValue());

	COMMAND_MAP_ITERATOR it;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, field.ID.getValue(), m_commands, it);
	}
	else
	{
		CopySysNetMonitorCommandTypeEntity(&val, &field);
		m_commands[field.ID.getValue()] = val;
	}
}

//接收巡检动作组
void CSynConnector::OnRspActionGroupTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorActionGroupField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorActionGroupField::m_Describe));

	CFTDSysNetMonitorActionGroupField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorActionGroupEntity(&val, &field);
		g_TaskInfoManager.AddActionGroupInfo(val);
		m_actions[val.ID.getValue()] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnActionGroupTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorActionGroupField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorActionGroupField val;
	CopySysNetMonitorActionGroupEntity(&val, &field);
	g_TaskInfoManager.UpdActionGroupInfo(val, field.OperationType.getValue());

	ACTION_GROUP_MAP_ITERATOR it;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, field.ID.getValue(), m_actions, it);
	}
	else
	{
		CopySysNetMonitorActionGroupEntity(&val, &field);
		m_actions[field.ID.getValue()] = val;
	}
}

//接收巡检设备对象组
void CSynConnector::OnRspDeviceGroupTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorDeviceGroupField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorDeviceGroupField::m_Describe));

	CFTDSysNetMonitorDeviceGroupField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorDeviceGroupEntity(&val, &field);
		g_TaskInfoManager.AddDeviceGroupInfo(val);
		m_groupdev[val.ID.getValue()] = val;

		itor.Next();
	}
}

void CSynConnector::OnRtnDeviceGroupTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorDeviceGroupField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorDeviceGroupField val;
	CopySysNetMonitorDeviceGroupEntity(&val, &field);
	g_TaskInfoManager.UpdDeviceGroupInfo(val, field.OperationType.getValue());

	DEVICE_GROUP_MAP_ITERATOR it;

	if (field.OperationType.getValue() % 2)
	{
		RTN_QRY_DEL_FIELD_DATA(field, val, field.ID.getValue(), m_groupdev, it);
	}
	else
	{
		CopySysNetMonitorDeviceGroupEntity(&val, &field);
		m_groupdev[field.ID.getValue()] = val;
	}
}

//接收巡检设备对象组明细
void CSynConnector::OnRspQryNetMonitorTaskObjectSetTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTaskObjectSetField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTaskObjectSetField::m_Describe));

	CFTDSysNetMonitorTaskObjectSetField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorTaskObjectSetEntity(&val, &field);
		g_TaskInfoManager.AddDeviceGroupListInfo(val);

		itor.Next();
	}
}

void CSynConnector::OnRtnNetMonitorTaskObjectSetTopic(
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
	g_TaskInfoManager.UpdDeviceGroupListInfo(
			val,
			field.OperationType.getValue());
}

///响应动作指标应答处理函数
///@param	pFTDCPackage	需要处理的FTDC包地址
///@param	pSession	数据包所属的FTD会话指针
void CSynConnector::OnRspActionAttrTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorActionAttrField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorActionAttrField::m_Describe));

	CFTDSysNetMonitorActionAttrField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorActionAttrEntity(&val, &field);
		g_TaskInfoManager.AddActionAttrInfo(val);
		itor.Next();
	}
}

void CSynConnector::OnRtnActionAttrTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorActionAttrField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorActionAttrField val;
	CopySysNetMonitorActionAttrEntity(&val, &field);
	g_TaskInfoManager.UpdActionAttrInfo(val, field.OperationType.getValue());
}

void CSynConnector::OnRspDevTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorDeviceTaskField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorDeviceTaskField::m_Describe));

	CFTDSysNetMonitorDeviceTaskField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorDeviceTaskEntity(&val, &field);
		g_TaskInfoManager.AddDeviceTaskInfo(val);

		itor.Next();
	}
}

void CSynConnector::OnRtnDevTaskTopic(
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
	g_TaskInfoManager.UdpDeviceTaskInfo(val, field.OperationType.getValue());
}

void CSynConnector::OnRspInstrTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetMonitorTaskInstAttrsField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetMonitorTaskInstAttrsField::m_Describe));

	CFTDSysNetMonitorTaskInstAttrsField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetMonitorTaskInstAttrsEntity(&val, &field);
		g_TaskInfoManager.AddInstructionInfo(val);

		itor.Next();
	}
}

void CSynConnector::OnRtnInstrTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTaskInstAttrsField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetMonitorTaskInstAttrsField val;
	CopySysNetMonitorTaskInstAttrsEntity(&val, &field);
	g_TaskInfoManager.UdpInstructionInfo(val, field.OperationType.getValue());
}

/*
//响应会员链路信息
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspPartLinkTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetPartyLinkInfoField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetPartyLinkInfoField::m_Describe));

	CFTDSysNetPartyLinkInfoField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetPartyLinkInfoEntity(&val, &field);
		m_partylinks[val.ID.getValue()] = val;

		string ip = val.IPADDR.getValue();

		IP_PartyLink_MAP_ITERATOR it = m_devpartylinks.find(ip);
		if (it != m_devpartylinks.end())
		{
			it->second.push_back(val.ID.getValue());
		}
		else
		{
			list<int> ids;
			ids.push_back(val.ID.getValue());
			m_devpartylinks[ip] = ids;
		}

		itor.Next();
	}
}

void CSynConnector::OnRtnPartLinkTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetPartyLinkInfoField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetPartyLinkInfoField val;
	PartyLink_MAP_ITERATOR it_pl;
	IP_PartyLink_MAP_ITERATOR it_dev;
	string ip;

	switch (field.OperationType.getValue())
	{
		case 1:
			break;
		case 2: //增加
			CopySysNetPartyLinkInfoEntity(&val, &field);
			m_partylinks[val.ID.getValue()] = val;
			ip = val.IPADDR.getValue();
			it_dev = m_devpartylinks.find(ip);
			if (it_dev != m_devpartylinks.end())
			{
				it_dev->second.push_back(val.ID.getValue());
			}
			else
			{
				list<int> ids;
				ids.push_back(val.ID.getValue());
				m_devpartylinks[ip] = ids;
				if (m_dev_ips.find(ip) != m_dev_ips.end())
				{
					int id = m_dev_ips[ip];
					if (m_devs.find(id) != m_devs.end())
					{
						g_TaskInfoManager.AddPartyLinkTask(m_devs[id]);
					}
				}
			}

			break;
		case 3: //删除
			it_pl = m_partylinks.find(field.ID.getValue());
			if (it_pl != m_partylinks.end())
			{
				m_partylinks.erase(it_pl);
				ip = field.IPADDR.getValue();
				it_dev = m_devpartylinks.find(ip);
				if (it_dev != m_devpartylinks.end())
				{
					for (list<int>::iterator it = it_dev->second.begin();
						 it != it_dev->second.end();
						 it++)
					{
						if (*it = field.ID.getValue())
						{
							it_dev->second.erase(it);
							break;
						}
					}
				}
			}

			break;
		case 4: //修改
			it_pl = m_partylinks.find(field.ID.getValue());
			if (it_pl != m_partylinks.end())
			{
				CopySysNetPartyLinkInfoEntity(&val, &field);
				ip = it_pl->second.IPADDR.getValue();					//记录old数据的ip地址
				it_pl->second = val;
				if (strcmp(ip.c_str(), field.IPADDR.getValue()) != 0)	//只处理ip变化的情况
				{
					it_dev = m_devpartylinks.find(ip);
					if (it_dev != m_devpartylinks.end())
					{
						for (list<int>::iterator it = it_dev->second.begin();
							 it != it_dev->second.end();
							 it++)
						{
							if (*it = field.ID.getValue())
							{
								it_dev->second.erase(it);
								if (it_dev->second.size() == 0)
								{
									m_devpartylinks.erase(it_dev);
								}

								break;
							}
						}

						it_dev = m_devpartylinks.find(field.IPADDR.getValue());
						if (it_dev != m_devpartylinks.end())
						{
							it_dev->second.push_back(field.ID.getValue());
						}
						else
						{
							list<int> ids;
							ids.push_back(field.ID.getValue());
							m_devpartylinks[field.IPADDR.getValue()] = ids;
						}
					}
				}
			}

			break;
		default:
			break;
	}
}

void CSynConnector::OnRspPartLinkInfoStatus(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *Session)
{
	CFTDRspQryNetPartyLinkStatusInfoField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetPartyLinkStatusInfoField::m_Describe));

	if (!itor.IsEnd())
	{
		itor.Retrieve(&field);
		if (field.OperationType == 0)	///标识第一次执行链路状态
		{
			CFTDSysNetDeviceField DeviceInfo;
			int id;
			for (IP_PartyLink_MAP_ITERATOR it = m_devpartylinks.begin();
				 it != m_devpartylinks.end();
				 it++)
			{
				string ip = it->first;
				if (m_dev_ips.find(ip) != m_dev_ips.end()
				&&	m_devs.find(m_dev_ips[ip]) != m_devs.end())
				{
					id = m_dev_ips[ip];
					DeviceInfo = m_devs[id];
					g_TaskInfoManager.AddPartyLinkTask(DeviceInfo);
				}
			}
		}
	}
}

/*
//响应基线比对任务
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnRspBaseLineTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetBaseLineTaskField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&(CFTDRspQryNetBaseLineTaskField::m_Describe));

	CFTDSysNetBaseLineTaskField val;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		CopySysNetBaseLineTaskEntity(&val, &field);
		g_TaskInfoManager.AddBaseLineTask(val);

#if 0
		CFTDSysNetDeviceField dev;
		int id;
		string dev_ids = val.DeviceIDList.getValue();
		char *p = strtok((char *)(dev_ids.c_str()), ";");
		id = atoi(p);
		if (m_devs.find(id) != m_devs.end())
		{
			dev = m_devs[id];
			g_TaskInfoManager.ProcessBaseLineTask(val, dev);
		}
		else
		{
			printf("warning: can't find device id = [%d].\n", id);
		}

		while ((p = strtok(NULL, ";")) != NULL)
		{
			id = atoi(p);
			if (m_devs.find(id) != m_devs.end())
			{
				dev = m_devs[id];
				g_TaskInfoManager.ProcessBaseLineTask(val, dev);
			}
			else
			{
				printf("warning: can't find device id = [%d].\n", id);
			}
		}

#endif
		itor.Next();
	}
}

void CSynConnector::OnRtnBaseLineTaskTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetBaseLineTaskField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	CFTDSysNetBaseLineTaskField val;

	switch (field.OperationType.getValue())
	{
		case 1: //查看
			break;
		case 3: //删除
			g_TaskInfoManager.DelBaseLineTask(field.ID.getValue());
			break;
		case 4: //修改
			g_TaskInfoManager.DelBaseLineTask(field.ID.getValue());
		case 2: //增加
			CopySysNetBaseLineTaskEntity(&val, &field);
			g_TaskInfoManager.AddBaseLineTask(val);

			CFTDSysNetDeviceField dev;
			int id;
			string dev_ids = val.DeviceIDList.getValue();
			char *p = strtok((char *)(dev_ids.c_str()), ";");
			id = atoi(p);
			if (m_devs.find(id) != m_devs.end())
			{
				dev = m_devs[id];
				g_TaskInfoManager.ProcessBaseLineTask(val, dev);
			}
			else
			{
				printf("warning: can't find device id = [%d].\n", id);
			}

			while ((p = strtok(NULL, ";")) != NULL)
			{
				id = atoi(p);
				if (m_devs.find(id) != m_devs.end())
				{
					dev = m_devs[id];
					g_TaskInfoManager.ProcessBaseLineTask(val, dev);
				}
				else
				{
					printf("warning: can't find device id = [%d].\n", id);
				}
			}

			break;
	}
}

/*
//响应探测处理
//@param	pFTDCPackage	需要处理的FTDC包地址
//@param	pSession	数据包所属的FTD会话指针
*/
void CSynConnector::OnReqQryNetDeviceDetectTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//if( m_detecting )
	//{
	//	return;
	//}
	//else
	//{
	//	m_detecting = true;
	//	//探测之前清除旧信息
	//	m_devs.clear();
	//	m_ifs.clear();
	//	m_mods.clear();
	//}	
	CFTDReqQryNetDeviceDetectField field;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &field) <= 0)
	{
		return;
	}

	DWORD reqid = pFTDCPackage->GetRequestId();

	m_detectids[reqid] = field;
	m_listreq.add(reqid);

	if (m_pdetthread == NULL)
	{
		m_pdetthread = new CDetectWorkThread(this);

		m_pdetthread->Create();
	}
}

/*
//探测答复
//@param	reqid	发送探测的id
//@param	type	答复的消息类别 0代表FTDC_CHAIN_LAST,1、2代表FTDC_CHAIN_CONTINUE
//@param	value	value值取决于type
*/
void CSynConnector::RspQryNetDeviceDetectTopic(DWORD reqid, int type, int value)
{
	if (m_detectids.find(reqid) == m_detectids.end())
	{
		printf(
			"there is no request detect information in the req_map  when response the detect topic.\n");
		return;
	}

	CFTDRspQryNetDeviceDetectField tfield;
	CFTDRspInfoField fieldRspInfo;

	tfield.SysNetAreaID = m_detectids[reqid].SysNetAreaID;
	tfield.SysNetSubAreaID = m_detectids[reqid].SysNetSubAreaID;
	tfield.IP = m_detectids[reqid].IP;
	tfield.Mask = m_detectids[reqid].Mask;

	g_RspDetectLock.Lock();
	switch (type)
	{
		case 0:
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetDeviceDetectTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			fieldRspInfo.ErrorMsg = "SUCCESS";
			m_detecting = false;
			break;
		case 1:
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetDeviceDetectTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			fieldRspInfo.ErrorMsg = "THREADNUM";
			break;
		case 2:
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetDeviceDetectTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			fieldRspInfo.ErrorMsg = "THREADID_PING";
			break;
		case 3:
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetDeviceDetectTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			fieldRspInfo.ErrorMsg = "THREADID";
			break;
		case 4:
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetDeviceDetectTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			fieldRspInfo.ErrorMsg = "DEVICENUM";
			break;
		default:
			break;
	}

	m_pkgSend.SetRequestId(reqid);
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);

	fieldRspInfo.ErrorID = value;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);

	if (m_pSession != NULL)
	{
		m_pSession->SendRequestPackage(&m_pkgSend);
	}

	g_RspDetectLock.UnLock();

	printf(
		"response the detect request msg=[%s] msgid=[%d].\n",
		fieldRspInfo.ErrorMsg.getValue(),
		fieldRspInfo.ErrorID.getValue());
}

/*
//发送CFTDRtnNetObjectAttrField数据
//@param	field	CFTDRtnNetObjectAttrField数据内容
*/
void CSynConnector::SendCFTDRtnObjectAttrField(CFTDRtnObjectAttrField &field)
{
	SYNCONN_PKGSEND(FTD_TID_RtnObjectAttrTopic, field);
}

/*
//发送cdp连接关系数据
//@param	hosts	包含cdp的设备集合
*/
void CSynConnector::SendCDPInfo(vector<SInfoHost> &hosts)
{
	if (hosts.size() == 0)
	{
		printf("没有连接关系元素!\n");
		return;
	}

	for (vector<SInfoHost>::iterator it = hosts.begin();
		 it != hosts.end();
		 it++)
	{
		if (it->SysName.length() == 0)
		{
			continue;
		}

		string netarea = it->cenName + "." + it->netName;
		netarea.append(".");

		CFTDRspQryNetDeviceLinkedField tField;

		memset(&tField, 0, sizeof(tField));

		printf("IP:%s有%d个连接对象\n", it->name, it->mListCdpValue.size());

		for (list<CCdpValue>::iterator itt = it->mListCdpValue.begin();
			 itt != it->mListCdpValue.end();
			 itt++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetDeviceLinkedTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);

			itt->mlocalhost.insert(0, netarea.c_str());
			itt->mdesthost.insert(0, netarea.c_str());

			tField.NetObjectID = itt->mlocalhost.c_str();
			tField.NetPortType = itt->mlocalport.c_str();

			//tField.NetPortID = itt->mlocalport.c_str();
			tField.LinkNetObjectID = itt->mdesthost.c_str();

			//tField.LinkNetPortID = itt->mdestport.c_str();
			tField.LinkNetPortType = itt->mdestport.c_str();

			FTDC_ADD_FIELD(&m_pkgSend, &tField);
			if (m_pSession != NULL)
			{
				m_pSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}

	//m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkedTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	//if( m_pSession != NULL )
	//{
	//	m_pSession->SendRequestPackage(&m_pkgSend);
	//}
}

/*
//发送网络设备数据
//@param	hosts	需要发送的设备集合
*/
void CSynConnector::SendHostInfo(std::vector<SInfoHost> &hosts, DWORD req)
{
	if (hosts.size() == 0)
	{
		printf("没有设备信息元素!\n");
		return;
	}

	printf("there has %d devices.\n", hosts.size());

	for (vector<SInfoHost>::iterator it = hosts.begin();
		 it != hosts.end();
		 it++)
	{
		if (it->SysName.length() == 0)
		{
			continue;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryNetDeviceTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);

		CFTDRspQryNetDeviceField tField;

		memset(&tField, 0, sizeof(tField));
		tField.IPADDR = it->name;
		tField.NAME = it->SysName.c_str();
		tField.RCOMMUNITY = it->community;

		char buff[128] = "\0";
		sprintf(
			buff,
			"%s.%s.%s",
			it->cenName.c_str(),
			it->netName.c_str(),
			it->SysName.c_str());
		printf("detect device objectid=[%s].\n", buff);

		tField.ObjectID = buff;

		int centerid = GetNetAreaIDByName(it->cenName.c_str());
		if (centerid >= 0)
		{
			tField.SysNetSubAreaID = GetNetSubAreaIDByNetArea(
					centerid,
					it->netName.c_str());
			if (m_detectids.find(req) != m_detectids.end())
			{
				tField.IPDECODE = GetNetSubAreaIPIDByNetSubArea(
						tField.SysNetSubAreaID.getValue(),
						m_detectids[req].IP.getValue(),
						m_detectids[req].Mask.getValue());
			}
			else
			{
				tField.IPDECODE = -1;
			}
		}
		else
		{
			tField.SysNetSubAreaID = -1;
		}

		tField.MonitorType_ID = GetMonitorTypeIDByName(it->sysType.c_str());	//监控对象类别
		tField.MANUFACTORY_ID = GetDevManuIDByManuName(it->manustr.c_str());	//设备厂商类别
		tField.CATEGORY_ID = GetDevTypeIDByTypeName(it->sysType.c_str());		//设备类型（大类）
		tField.DEVICETYPE = it->serial.c_str(); //暂时以SERIAL字段表示设备型号
		tField.IFNUM = it->ifNum;

		tField.DESCRIPTION = it->sysDescr.c_str();

		FTDC_ADD_FIELD(&m_pkgSend, &tField);

		if (m_pSession != NULL)
		{
			m_pSession->SendRequestPackage(&m_pkgSend);
		}
	}

	//m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	//if( m_pSession != NULL )
	//{
	//	m_pSession->SendRequestPackage(&m_pkgSend);
	//}
}

/*
//发送接口数据
//@param	hosts	需要发送的接口集合
*/
void CSynConnector::SendInterfaceInfo(std::vector<SInfoHost> &hosts)
{
	if (hosts.size() == 0)
	{
		printf("没有设备信息元素!\n");
		return;
	}

	CFTDRspQryNetInterfaceField tField;

	memset(&tField, 0, sizeof(tField));

	for (vector<SInfoHost>::iterator it = hosts.begin();
		 it != hosts.end();
		 it++)
	{
		if (it->SysName.length() == 0)
		{
			continue;
		}

		printf(
			"send: device ip[%s] has %d interface.\n",
			it->name,
			it->mifDescr.size());
		for (map<string, pair<string, string> >::iterator it_if = it->mifDescr.begin();
			 it_if != it->mifDescr.end();
			 it_if++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetInterfaceTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);

			char buff[128] = "\0";
			sprintf(
				buff,
				"%s.%s.%s",
				it->cenName.c_str(),
				it->netName.c_str(),
				it->SysName.c_str());

			tField.DeviceObjectID = buff;

			//拼接端口的objectid,如"PuDian.OA.TESTDEVNAME.FastEthernet0/48"
			sprintf(
				buff,
				"%s.%s.%s.%s",
				it->cenName.c_str(),
				it->netName.c_str(),
				it->SysName.c_str(),
				it_if->second.first.c_str());
			tField.ObjectID = buff;

			tField.DeviceIndex = it_if->first.c_str();

			tField.EName = it_if->second.first.c_str();

			//记录接口的别名
			tField.Description =  it_if->second.second.c_str();

			MONITOR_TYPE_MAP_ITERATOR it_monitor = m_montypes.find("interface");
			if (it_monitor != m_montypes.end())
			{
				tField.MonitorType_ID = it_monitor->second.ID;
			}

			FTDC_ADD_FIELD(&m_pkgSend, &tField);

			if (m_pSession != NULL)
			{
				m_pSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}
}

/*
//发送设备模块数据
//@param	hosts	需要发送的接口集合
*/
void CSynConnector::SendModuleInfo(std::vector<SInfoHost> &hosts)
{
	if (hosts.size() == 0)
	{
		printf("没有设备信息元素!\n");
		return;
	}

	CFTDRspQryNetModuleField tField;

	memset(&tField, 0, sizeof(tField));

	for (vector<SInfoHost>::iterator it = hosts.begin();
		 it != hosts.end();
		 it++)
	{
		if (it->SysName.length() == 0)
		{
			continue;
		}

		if (it->m_ModValues.size() > 0)
		{
			printf(
				"send: device ip[%s] has %d module.\n",
				it->name,
				it->m_ModValues.size());
			for (map<string, ModuleValue>::iterator it_mod = it->m_ModValues.
					 begin();
			 it_mod != it->m_ModValues.end();
				 it_mod++)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetModuleTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);

				char buff[128] = "\0";

				sprintf(
					buff,
					"%s.%s.%s",
					it->cenName.c_str(),
					it->netName.c_str(),
					it->SysName.c_str());
				tField.DeviceObjectID = buff;

				sprintf(
					buff,
					"%s.%s.%s.%s",
					it->cenName.c_str(),
					it->netName.c_str(),
					it->SysName.c_str(),
					it_mod->second.modentPhyModelName.c_str());
				tField.ObjectID = buff;

				tField.ModuleIndex = atoi(it_mod->first.c_str());	// it_mod->second.modIndex;
				tField.EntPhyIndex = it_mod->second.modEntPhyIndex;
				tField.Description = it_mod->second.modEntPhyDescr.c_str();
				tField.Name = it_mod->second.modentPhyModelName.c_str();

				//tField.Status = it_mod->second.modState;
				//tField.standbyStatus = it_mod->second.modStandbyState;
				//tField.NumPorts = it_mod->second.modNumPorts;
				//tField.HardwareVersion = it_mod->second.modHwVersion.c_str();
				//tField.firmVersion = it_mod->second.modEntPhyFwRev.c_str();
				//tField.SoftwareVersion = it_mod->second.modEntPhySwRev.c_str();
				//tField.serialNum = it_mod->second.modEntPhySerialNum.c_str();
				MONITOR_TYPE_MAP_ITERATOR it_monitor = m_montypes.find(
						"module");
				if (it_monitor != m_montypes.end())
				{
					tField.MonitorType_ID = it_monitor->second.ID;
				}

				FTDC_ADD_FIELD(&m_pkgSend, &tField);

				if (m_pSession != NULL)
				{
					m_pSession->SendRequestPackage(&m_pkgSend);
				}
			}
		}
	}
}

/*
//根据设备ObjectID获取设备对象指针
//@param	const char *id	
*/
CFTDSysNetDeviceField *CSynConnector::GetDeviceByObjID(const char *objid)
{
	for (NET_DEVICE_MAP_ITERATOR it = m_devs.begin(); it != m_devs.end(); it++)
	{
		if (strcmp(objid, it->second.ObjectID.getValue()) == 0)
		{
			return &(it->second);
		}
	}

	return NULL;
}

CFTDSysNetInterfaceField *CSynConnector::GetInterfaceByObjID(const char *obj)
{
	for (NET_INTERFACE_MAP_ITERATOR it = m_ifs.begin(); it != m_ifs.end(); it++)
	{
		if (strcmp(obj, it->second.ObjectID.getValue()) == 0)
		{
			return &(it->second);
		}
	}

	return NULL;
}

CFTDSysNetModuleField *CSynConnector::GetModuleByObjID(const char *obj)
{
	for (NET_MODULE_MAP_ITERATOR it = m_mods.begin(); it != m_mods.end(); it++)
	{
		if (strcmp(obj, it->second.ObjectID.getValue()) == 0)
		{
			return &(it->second);
		}
	}

	return NULL;
}

/*
//根据子网规划的id获取子网名称、网络中心名称
//@param	id   子网id
//@param	输出参数，net   子网名称
//@param	输出参数， center 网络中心名称
*/
void CSynConnector::GetNetAreaInfoByNetSubAreaID(
	int id,
	string &net,
	string &center)
{
	NET_SUB_AREA_MAP_ITERATOR it_sysNetSub;
	NET_AREA_MAP_ITERATOR it_sysNet;

	it_sysNetSub = m_sysNetSubs.find(id);

	if (it_sysNetSub != m_sysNetSubs.end())
	{
		net = it_sysNetSub->second.EName.getValue();

		it_sysNet = m_sysNets.find(
				it_sysNetSub->second.SysNetAreaID.getValue());

		if (it_sysNet != m_sysNets.end())
		{
			center = it_sysNet->second.EName.getValue();
		}
		else
		{
			printf(
				"The server has no center planning data SysNetAreaID=[%d] \n",
				it_sysNetSub->second.SysNetAreaID.getValue());
		}
	}
	else
	{
		printf(
			"The server has no sub net planning data SysNetSubID=[%d] \n",
			id);
	}
}

int CSynConnector::GetNetSubAreaIDByNetArea(int centerid, const char *net)
{
	for (NET_SUB_AREA_MAP_ITERATOR it = m_sysNetSubs.begin();
		 it != m_sysNetSubs.end();
		 it++)
	{
		if (centerid == it->second.SysNetAreaID.getValue()
		&&	strcmp(net, it->second.EName.getValue()) == 0)
		{
			return it->first;
		}
	}

	return 0;
}

int CSynConnector::GetNetSubAreaIPIDByNetSubArea(
	int netid,
	const char *ip,
	const char *mask)
{
	for (NET_SUB_AREA_IP_MAP_ITERATOR it = m_sysNetSubIPs.begin();
		 it != m_sysNetSubIPs.end();
		 it++)
	{
		if (netid == it->second.SysNetSubAreaID.getValue()
		&&	strcmp(ip, it->second.IP.getValue()) == 0
		&&	strcmp(mask, it->second.Mask.getValue()) == 0)
		{
			return it->first;
		}
	}

	return 0;
}

int CSynConnector::GetDevManuIDByManuName(const char *name)
{
	char *p = (char *)name;

	DEV_MANUFACTORY_MAP_ITERATOR it = m_devmanus.find(strlwr(p, strlen(p)));

	if (it != m_devmanus.end())
	{
		return it->second.ID.getValue();
	}

	return 0;
}

int CSynConnector::GetDevTypeIDByTypeName(const char *name)
{
	char *p = (char *)name;

	DEV_TYPE_MAP_ITERATOR it = m_devtypes.find(strlwr(p, strlen(p)));

	if (it != m_devtypes.end())
	{
		return it->second.ID.getValue();
	}

	return 0;
}

int CSynConnector::GetMonitorTypeIDByName(const char *name)
{
	char *p = (char *)name;

	MONITOR_TYPE_MAP_ITERATOR it = m_montypes.find(strlwr(p, strlen(p)));

	if (it != m_montypes.end())
	{
		return it->second.ID.getValue();
	}
	else
	{
		for (it = m_montypes.begin(); it != m_montypes.end(); it++)
		{
			printf("monitortype key is:%s\n", it->first.c_str());
		}

		printf("find the monitor type[%s] fail\n", strlwr(p, strlen(p)));
		printf(
			"there is no monitor type[%s] in the MONITOR_TYPE_TABLE.\n",
			name);
	}

	return 0;
}

void CSynConnector::DispatchMonTask(void)
{
	if (!g_isMasterRole)
	{
		return;
	}

	string oid_index;					//监控对象如果是接口/模块，需要存储接口索引号
	string oid;							//监控指标对应的oid值
	string appendStr;					//oid需要附加的内容，比如端口索引，模块号
	int	   oidmeans = 0;					// oid采集的方式 getbulk,getnext等等

	int thr_id;

	CFTDSysNetDeviceField *hp;			//监控设备对象指针
	CFTDSysNetInterfaceField *dev_if;	//监控接口对象指针
	CFTDSysNetModuleField *dev_mod;		//模块指针
	if (!g_Lock.TryLock())
	{
		return;
	}

#if 0
	time_t now;
	struct tm *curTime;
	char begTimeStr[20] = "\0";
	char endTimeStr[20] = "\0";
	time(&now);
	curTime = localtime(&now);
	strftime(begTimeStr, 20, "%Y%m%d %H:%M:%S", curTime);
	printf("++++++++begin time is [%s].\n", begTimeStr);
#endif
	for (MONITOR_TASK_MAP_ITERATOR it = m_montasks.begin();
		 it != m_montasks.end();)
	{
		if (it->second.second == NORMAL_STATUS)
		{
			//任务已经派发
			it++;
			continue;
		}

		oid_index = "";
		appendStr = "";
		oid = "";
		hp = NULL;
		dev_if = NULL;
		thr_id = -1;

		//监控指标的oid对应的name
		string oid_name = it->second.first.AttrType.getValue();
		if (oid_name.length() <= 0)
		{
			printf(
				"monitor task id=[%d] objectid=[%s]  fail because of no task attritype oid.\n",
				it->first,
				it->second.first.ObjectID.getValue());
			it++;
			continue;
		}

		//获取网络设备对象
		hp = GetDeviceByObjID(it->second.first.ObjectID.getValue());

		if (hp == NULL)
		{
			//指标的附值字符串,如接口、模块的名称
			appendStr = it->second.first.ObjectID.getValue();
			appendStr = appendStr.substr(appendStr.rfind('.') + 1);
		}

		//通过接口对象查找设备对象
		if (hp == NULL)
		{
			dev_if = GetInterfaceByObjID(it->second.first.ObjectID.getValue());

			if (dev_if != NULL)
			{
				oid_index = dev_if->DeviceIndex.getValue();

				if (m_devs.find(dev_if->DeviceID.getValue()) != m_devs.end())
				{
					hp = &(m_devs[dev_if->DeviceID.getValue()]);
				}
			}
		}

		//通过模块对象查找设备对象
		if (hp == NULL)
		{
			dev_mod = GetModuleByObjID(it->second.first.ObjectID.getValue());

			if (dev_mod != NULL)
			{
				char mod_buff[32] = { 0 };
				if (strcasestr(oid_name.c_str(), "entPhy") != NULL)
				{
					sprintf(mod_buff, "%d", dev_mod->EntPhyIndex.getValue());
				}
				else
				{
					sprintf(mod_buff, "%d", dev_mod->ModuleIndex.getValue());
				}

				oid_index = mod_buff;

				if (m_devs.find(dev_mod->DeviceID.getValue()) != m_devs.end())
				{
					hp = &(m_devs[dev_mod->DeviceID.getValue()]);
				}
			}
		}

		if (NULL == hp)
		{
			printf(
				"monitor task id=[%d] objectid=[%s] attritype=[%s] fail because of no monitor object.\n",
				it->first,
				it->second.first.ObjectID.getValue(),
				it->second.first.AttrType.getValue());
			if (it->second.second == UNWORK_STATUS)
			{
				m_montasks.erase(it++);
			}
			else
			{
				it++;
			}

			continue;
		}

		CON_OID_CONTAIN_MAP_ITERATOR it_oid = m_oids.find(oid_name);
		if (it_oid == m_oids.end())
		{
			//拼接厂商oid表的key，以获取监控指标的oid值
			string manu;
			GetManuNameByID(hp->MANUFACTORY_ID, manu);
			oid_name += CONSYM;
			oid_name.append(manu.c_str());
			it_oid = m_oids.find(oid_name);
		}

		if (it_oid == m_oids.end())
		{
			//拼接设备型号
			oid_name += CONSYM;
			oid_name.append(hp->DEVICETYPE.getValue());
			it_oid = m_oids.find(oid_name);
		}

		if (it_oid != m_oids.end())
		{
			oid = m_oids[oid_name].OID.getValue();
			if (oid_index.length() > 0)
			{
				oid.append(".");
				oid.append(oid_index.c_str());
			}
			else
			{
				if (!m_oids[oid_name].isTheTable)
				{
					oid.append(".0");
				}
			}
			//增加解析oid字段的UNIT属性 2014.7.15
			oidmeans = atoi( it_oid->second.Unit.getValue() );
		}
		else
		{
			printf(
				"monitor task id=[%d] objectid=[%s] attritype=[%s] key=[%s] fail because of no task oid.\n",
				it->first,
				it->second.first.ObjectID.getValue(),
				it->second.first.AttrType.getValue(),
				oid_name.c_str());
			if (it->second.second == UNWORK_STATUS)
			{
				m_montasks.erase(it++);
			}
			else
			{
				it++;
			}

			continue;
		}

		if( oidmeans == 2 )//oid_name is complex attr // 2014.7.21, by Le
		{
			//add to the attr contain
			//ComputerComplexAttr
			//addDevComAttr(hp->ObjectID.getValue(),oid_name);
			if( g_mapoidAttr.find(oid) == g_mapoidAttr.end() )
			{
				printf(
					"monitor task id=[%d] objectid=[%s] ip=[%s],complex attritype=[%s] be added succeesfully in  .\n",
					it->first,
					it->second.first.ObjectID.getValue(),
					hp->IPADDR.getValue(),
					it->second.first.AttrType.getValue());

				g_mapoidAttr[oid] = it->second.first.AttrType.getValue();
			}
			it++;
			continue;
		}

		thr_id = getDisTaskThreadIDByIP(hp->IPADDR.getValue());

		if (it->second.second == PREPARE_STATUS)		//任务就绪，需要派发
		{
			//查找监控指标的时间策略，并将指标加入到监控线程对象中
			TIME_POLICY_MAP_ITERATOR it_tp = m_tpolicys.find(
					it->second.first.PolicyTypeID.getValue());
			if (it_tp != m_tpolicys.end())
			{
				if (thr_id == -1)
				{
					thr_id = m_nCurentDisThreadID;
					m_nCurentDisThreadID = (m_nCurentDisThreadID + 1) % m_nThreadNum;
				}

				m_pThread[thr_id]->addMonDevice(
						hp,
						oid.c_str(),
						it->second.first.AttrType.getValue(),
						it_tp->second.PolicyString.getValue(),
						it->second.first.TypeFlag.getValue(),
						appendStr.c_str(),
						oidmeans);

				//m_pThread[ thr_id ]->addMonDeviceNew(hp->NAME.getValue(), hp->IPADDR.getValue(), hp->RCOMMUNITY.getValue(),
				//	hp->ObjectID.getValue(),oid.c_str(),it->second.first.AttrType.getValue(),
				//	it_tp->second.PolicyString.getValue(), it->second.first.TypeFlag.getValue(), appendStr.c_str());
				printf(
					"threadID[%d]:monitor task id=[%d] objectid=[%s] ip=[%s],attritype=[%s] oid=[%s] appendStr=[%s] be added succeesfully in  .\n",
					thr_id,
					it->first,
					it->second.first.ObjectID.getValue(),
					hp->IPADDR.getValue(),
					it->second.first.AttrType.getValue(),
					oid.c_str(),
					appendStr.c_str());
			}
			else
			{
				printf(
					"monitor task id=[%d] objectid=[%s] attritype=[%s] fail because of no time policy information.\n",
					it->first,
					it->second.first.ObjectID.getValue(),
					it->second.first.AttrType.getValue());
				it++;
				continue;
			}

			//任务派发标志置位
			it->second.second = NORMAL_STATUS;
		}
		else if (it->second.second == UNWORK_STATUS)	//任务删除
		{
			if (thr_id != -1)
			{
				m_pThread[thr_id]->removeMonTask(
						hp->IPADDR.getValue(),
						oid.c_str());
			}

			m_montasks.erase(it++);
			continue;
		}

		it++;
	}

	g_Lock.UnLock();
#if 0
	time(&now);
	curTime = localtime(&now);
	strftime(endTimeStr, 20, "%Y%m%d %H:%M:%S", curTime);
	printf("++++++++end time is [%s].\n", endTimeStr);
#endif
}

void CSynConnector::DispatchLoopTask(void)
{
	CSnmpTaskInfo task;

	//snmp优先级队列
	while (g_TaskInfoManager.GetSnmpTask(task))
	{
		RunTask(task);
	}

	//snmp延时队列
	while (g_TaskInfoManager.GetDelaySnmpTask(task))
	{
		char curtime[10];

		time_t timep;
		time(&timep);

		struct tm tm_time;
		LocalTime(&timep, &tm_time);
		strftime(curtime, 10, "%H:%M:%S", &tm_time);

		int comtime = task.TaskTime.compare(curtime);
		if (comtime > 0)
		{
			//还没到执行时间
			g_TaskInfoManager.AddDelaySnmpTask(task);

			if (g_TaskInfoManager.SnmpTaskCount() <= 1)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		else
		{
			RunTask(task);
		}
	}
}

void CSynConnector::RunTask(CSnmpTaskInfo task)
{
	char keystr[1024];
	snprintf(keystr, 1024, "%d_%d", task.TaskID, task.RunTimes);

	string oid_value;					//监控指标对应的oid值	
	string net;
	string center;
	string manu;
	string oid_name;

	CFTDSysNetDeviceField *hp = NULL;	//监控设备对象指针
	CFTDSysNetInterfaceField *dev_if;	//监控接口对象指针
	CFTDSysNetModuleField *dev_mod;		//模块指针
	CFTDRtnNetMonitorTaskResultField field;

	memset(&field, 0, sizeof(CFTDRtnNetMonitorTaskResultField));

	string appString = "";

	char curdate[10];
	char curtime[10];

	time_t timep;

	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	strftime(curtime, 10, "%H:%M:%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	field.ObjectID = task.ObjectID.c_str();
	field.Task_ID = task.TaskID;
	field.OperateTime = task.RunTimes;
	field.MonDate = curdate;
	field.MonTime = curtime;

	//notify client
	field.Flag = TASK_DOING_EXEC;
	g_TaskInfoManager.AddTaskResult(field, "");

	//modify task status
	g_TaskInfoManager.UpdateTaskStatus(
			task.TaskID,
			task.ObjectID,
			task.AttrName,
			TASK_DOING_EXEC,
			TASK_TYPE_SNMP);


	oid_name = task.AttrName;
	if (m_dev_ips.find(task.IPAddress) != m_dev_ips.end())
	{
		if (m_devs.find(m_dev_ips[task.IPAddress]) != m_devs.end())
		{
			hp = &(m_devs[m_dev_ips[task.IPAddress]]);
		}
	}

	if (hp != NULL)
	{
		CON_OID_CONTAIN_MAP_ITERATOR it_oid = m_oids.find(oid_name);
		if (it_oid == m_oids.end())
		{
			GetManuNameByID(hp->MANUFACTORY_ID, manu);
			oid_name += CONSYM;
			oid_name.append(manu.c_str());
			it_oid = m_oids.find(oid_name);
		}

		if (it_oid == m_oids.end())
		{
			oid_name += CONSYM;
			oid_name.append(hp->DEVICETYPE.getValue());
			it_oid = m_oids.find(oid_name);
		}

		if (it_oid != m_oids.end())
		{
			oid_value = m_oids[oid_name].OID.getValue();
		}
		else
		{
			printf(
				"loop task id=[%d] attritype=[%s] device manu=[%s] type=[%s] fail because of no task oid.\n",
				task.TaskID,
				task.AttrName.c_str(),
				manu.c_str(),
				hp->DEVICETYPE.getValue());
			return;
		}

		if ((task.ObjectID.length() > strlen(hp->ObjectID.getValue()))
		&&	strncmp(
				task.ObjectID.c_str(),
			hp->ObjectID.getValue(),
			strlen(hp->ObjectID.getValue())) == 0)
		{
			string index_append = "";
			appString = task.ObjectID.substr(task.ObjectID.rfind('.') + 1);

			dev_if = GetInterfaceByObjID(task.ObjectID.c_str());

			if (dev_if != NULL)
			{
				index_append = dev_if->DeviceIndex.getValue();
			}
			else
			{
				dev_mod = GetModuleByObjID(task.ObjectID.c_str());
				if (dev_mod != NULL)
				{
					if (strcasestr(oid_name.c_str(), "entPhy") != NULL)
					{
						index_append = dev_mod->EntPhyIndex.getValue();
					}
					else
					{
						index_append = dev_mod->ModuleIndex.getValue();
					}
				}
			}

			if (index_append.length() > 0)
			{
				oid_value.append(".");
				oid_value.append(index_append.c_str());
			}
		}
		else if (!m_oids[oid_name].isTheTable) //如果是标量oid，尾部加".0"
		{
			oid_value.append(".0");
		}

		GetNetAreaInfoByNetSubAreaID(
			hp->SysNetSubAreaID.getValue(),
			net,
			center);

		int thr_id = getDisTaskThreadIDByIP(task.IPAddress.c_str());

		if (thr_id == -1)
		{
			thr_id = m_nCurentDisThreadID;
			m_nCurentDisThreadID = (m_nCurentDisThreadID + 1) % m_nThreadNum;
		}

		m_pThread[thr_id]->addMonDevice(
				hp,
				oid_value.c_str(),
				task.AttrName.c_str(),
				NULL,
				1,
				appString.c_str());

		//notify client
		field.Flag = TASK_DONE_EXEC;
		g_TaskInfoManager.AddTaskResult(field, "");

		//modify task status
		g_TaskInfoManager.UpdateTaskStatus(
				task.TaskID,
				task.ObjectID,
				task.AttrName,
				TASK_DONE_EXEC,
				TASK_TYPE_SNMP);
	}
	else
	{
		printf(
			"warning: the excution of loop task id=[%d] failed because of no suitable NetDevice");
	}
}
