#include "public.h"
#include "OSSpiImpl.h"
#include "SyslogSpiImpl.h"

#ifdef LINUX
extern map<string, long> g_mAppNamePidMap;		// 应用进程名 - 应用进程的ID
extern map<string, string>	g_mSpcPrcMap;		// 应用进程名 - 进程所在分区 映射图
extern char *g_szHostEnvFile;					// 主机环境配置文件名
extern char *g_szNetConfFile;					// 网络配置文件名
extern char g_pHostName[32];					// 保存主机名称
extern char g_pDataCenterName[32];				// 保存数据中心名称
extern CManageConSession g_mManageConSession;	// 保存所有连接的地址信息
extern bool g_sendEvnFlag;

st_part_info g_partitions[MAX_PARTITIONS];
st_blkio_info g_blkio_new[MAX_PARTITIONS], g_blkio_old[MAX_PARTITIONS];
st_cpu_info g_cpu_new, g_cpu_old;
int g_nPartitions = 0;	// Partitions total count
int g_nCPU = 0;			// CPU cores count


/// Added by Henchi, 20140919
/// For netstat functions
void COperatorSystemSpiImpl::TCPGetOne(int lnr, const char *line)
{
	unsigned long rxq, txq, time_len, retr, inode;
	int num, local_port, rem_port, d, state, uid, timer_run, timeout;
	char rem_addr[128], local_addr[128], timers[64], buffer[1024], more[512];
	struct aftype *ap;
#if HAVE_AFINET6
	struct sockaddr_in6 localaddr, remaddr;
	char addr6[INET6_ADDRSTRLEN];
	struct in6_addr in6;
	extern struct aftype inet6_aftype;
#else
	struct sockaddr_in localaddr, remaddr;
#endif

	if (lnr == 0)
		return;

	num = sscanf(line,
		"%d: %64[0-9A-Fa-f]:%X %64[0-9A-Fa-f]:%X %X %lX:%lX %X:%lX %lX %d %d %ld %512s\n",
		&d, local_addr, &local_port, rem_addr, &rem_port, &state,
		&txq, &rxq, &timer_run, &time_len, &retr, &uid, &timeout, &inode, more);

	if (num < 11) {
		fprintf(stderr, "warning, got bogus tcp line.\n%s", line);
		return;
	}

	if (state == NET_TCP_LISTEN)
	{
		m_iTcpListen ++;	
	}
	else
	{	///All: Non listen status
		m_iTcpAll ++;
		if (state == NET_TCP_ESTABLISHED)
		{
			m_iTcpEstablished ++;	
		}
		else
		{
			m_iTcpOther ++;
		}
	}


#if 0
	if (strlen(local_addr) > 8) {
#if HAVE_AFINET6
		/* Demangle what the kernel gives us */
		sscanf(local_addr, "%08X%08X%08X%08X",
			&in6.s6_addr32[0], &in6.s6_addr32[1],
			&in6.s6_addr32[2], &in6.s6_addr32[3]);
		inet_ntop(AF_INET6, &in6, addr6, sizeof(addr6));
		inet6_aftype.input(1, addr6, (struct sockaddr *) &localaddr);
		sscanf(rem_addr, "%08X%08X%08X%08X",
			&in6.s6_addr32[0], &in6.s6_addr32[1],
			&in6.s6_addr32[2], &in6.s6_addr32[3]);
		inet_ntop(AF_INET6, &in6, addr6, sizeof(addr6));
		inet6_aftype.input(1, addr6, (struct sockaddr *) &remaddr);
		localaddr.sin6_family = AF_INET6;
		remaddr.sin6_family = AF_INET6;
#endif
	}
	else {
		sscanf(local_addr, "%X",
			&((struct sockaddr_in *) &localaddr)->sin_addr.s_addr);
		sscanf(rem_addr, "%X",
			&((struct sockaddr_in *) &remaddr)->sin_addr.s_addr);
		((struct sockaddr *) &localaddr)->sa_family = AF_INET;
		((struct sockaddr *) &remaddr)->sa_family = AF_INET;
	}
#endif
}

int COperatorSystemSpiImpl::GetTCPInfo(void)
{
	INFO_GUTS6(_PATH_PROCNET_TCP, _PATH_PROCNET_TCP6, TCPGetOne);
}

void COperatorSystemSpiImpl::UDPGetOne(int lnr, const char *line)
{
	char buffer[8192], local_addr[64], rem_addr[64];
	char *udp_state, timers[64], more[512];
	int num, local_port, rem_port, d, state, timer_run, uid, timeout;
#if HAVE_AFINET6
	struct sockaddr_in6 localaddr, remaddr;
	char addr6[INET6_ADDRSTRLEN];
	struct in6_addr in6;
	extern struct aftype inet6_aftype;
#else
	struct sockaddr_in localaddr, remaddr;
#endif
	struct aftype *ap;
	unsigned long rxq, txq, time_len, retr, inode;

	if (lnr == 0)
		return;

	more[0] = '\0';
	num = sscanf(line,
		"%d: %64[0-9A-Fa-f]:%X %64[0-9A-Fa-f]:%X %X %lX:%lX %X:%lX %lX %d %d %ld %512s\n",
		&d, local_addr, &local_port,
		rem_addr, &rem_port, &state,
		&txq, &rxq, &timer_run, &time_len, &retr, &uid, &timeout, &inode, more);

	if (num < 10) {
		fprintf(stderr, "warning, got bogus udp line.\n%s", line);
		return;
	}
	switch (state) {
	case NET_TCP_ESTABLISHED:
		m_iUdpEstablished ++;
		break;

	case NET_TCP_CLOSE:
		m_iUdpClose ++;
		break;

	default:
		break;
	}

#if 0	
	if (strlen(local_addr) > 8) {
#if HAVE_AFINET6
		sscanf(local_addr, "%08X%08X%08X%08X",
			&in6.s6_addr32[0], &in6.s6_addr32[1],
			&in6.s6_addr32[2], &in6.s6_addr32[3]);
		inet_ntop(AF_INET6, &in6, addr6, sizeof(addr6));
		inet6_aftype.input(1, addr6, (struct sockaddr *) &localaddr);
		sscanf(rem_addr, "%08X%08X%08X%08X",
			&in6.s6_addr32[0], &in6.s6_addr32[1],
			&in6.s6_addr32[2], &in6.s6_addr32[3]);
		inet_ntop(AF_INET6, &in6, addr6, sizeof(addr6));
		inet6_aftype.input(1, addr6, (struct sockaddr *) &remaddr);
		localaddr.sin6_family = AF_INET6;
		remaddr.sin6_family = AF_INET6;
#endif
	}
	else {
		sscanf(local_addr, "%X",
			&((struct sockaddr_in *) &localaddr)->sin_addr.s_addr);
		sscanf(rem_addr, "%X",
			&((struct sockaddr_in *) &remaddr)->sin_addr.s_addr);
		((struct sockaddr *) &localaddr)->sa_family = AF_INET;
		((struct sockaddr *) &remaddr)->sa_family = AF_INET;
	}
#endif
}

int COperatorSystemSpiImpl::GetUDPInfo(void)
{
	INFO_GUTS6(_PATH_PROCNET_UDP, _PATH_PROCNET_UDP6, UDPGetOne);
}
/// netstat functions end

void COperatorSystemSpiImpl::GetenvSpi(CFTDCSession *pSession)
{
	if (g_sendEvnFlag)
	{
		return;
	}

	GetDateTime();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryHostEnvTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRENV);
	m_cCommon.HostName = m_mObjectId;
	m_cCommon.MonDate = m_mDate;
	m_cCommon.MonTime = m_mTime;
	m_cCommon.HostModel = "x86_64 GNU/Linux";
	m_cCommon.OsMode = 64;
	m_cCommon.MainMemory = m_mMemory / 1024;			// MB
	m_cCommon.Processors = m_mCpuNum;

	GetCPUInfo();

	FTDC_ADD_FIELD(&m_pkgSend, &m_cCommon);

	if (m_mapNetInfo.size())
	{
		CFTDRspQryHostEnvLanCfgField Lancfg;
		CFTDRspQryHostEnvLanField Lan;
		Lan.HostName = m_mObjectId;
		Lan.MonDate = m_mDate;
		Lan.MonTime = m_mTime;
		Lancfg.HostName = m_mObjectId;
		Lancfg.MonDate = m_mDate;
		Lancfg.MonTime = m_mTime;

		map<string, netinfo>::iterator	mapIt;
		for (mapIt = m_mapNetInfo.begin(); mapIt != m_mapNetInfo.end(); mapIt++)
		{
			Lan.LanHardwareID = mapIt->second.name.c_str();
			Lan.LanHardwareValue = mapIt->second.mac.c_str();
			Lancfg.LanName = mapIt->second.name.c_str();
			Lancfg.IpAddress = mapIt->second.ip.c_str();
			Lancfg.IpMask = mapIt->second.mask.c_str();
			FTDC_ADD_FIELD(&m_pkgSend, &Lan);
			FTDC_ADD_FIELD(&m_pkgSend, &Lancfg);
		}
	}

	// Mod by Henchi, 20100223
	if (pSession != NULL)
	{
		pSession->SendRequestPackage(&m_pkgSend);
	}
	else
	{
		OSSENDPACKAGETO;
	}

	if (m_mFSNum)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRspQryHostEnvFSField fs;
		fs.HostName = m_mObjectId;
		fs.MonDate = m_mDate;
		fs.MonTime = m_mTime;

		for (int iCount = 0; iCount < m_mFSNum; iCount++)
		{
			fs.LVMDeviceFile = m_sFSInfo[iCount].FileSystem;
			fs.MountPoint = m_sFSInfo[iCount].MountOn;
			fs.FSsize = m_sFSInfo[iCount].Size;
			fs.FSType = m_sFSInfo[iCount].FSType;
			FTDC_ADD_FIELD(&m_pkgSend, &fs);
		}

		// Mod by Henchi, 20100223
		if (pSession != NULL)
		{
			pSession->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			OSSENDPACKAGETO;
		}
	}

	if (m_iSwap)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (int iCount = 0; iCount < m_iSwap; iCount++)
		{
#ifdef PRINT_DEBUG
			printf(
				"Swap[%d]:%s %s %d %d\n",
				iCount + 1,
				(const char *)m_cSwap[iCount].location.getValue(),
				(const char *)m_cSwap[iCount].type.getValue(),
				(const int)m_cSwap[iCount].size,
				(const int)m_cSwap[iCount].priority);
#endif
			m_cSwap[iCount].HostName = m_mObjectId;
			m_cSwap[iCount].MonDate = m_mDate;
			m_cSwap[iCount].MonTime = m_mTime;
			FTDC_ADD_FIELD(&m_pkgSend, &m_cSwap[iCount]);
		}

		// Mod by Henchi, 20100223
		if (pSession != NULL)
		{
			pSession->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			OSSENDPACKAGETO;
		}
	}

	g_sendEvnFlag = true;								// Add by Henchi , 20090302
}

bool COperatorSystemSpiImpl::GetMemory(void)
{
	return ScanMemInfo();
}

bool COperatorSystemSpiImpl::GetProcessInfo(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	m_vctProcUsage.clear();
	ScanProcesses();
	sort(m_vctProcUsage.begin(), m_vctProcUsage.end());
	if (m_vctProcUsage.size())
	{
		sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRPROCESS);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTopProcessInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_cProcInfo.HostName = m_mObjectId;
		m_cProcInfo.MonDate = m_mDate;
		m_cProcInfo.MonTime = m_mTime;
#ifdef PRINT_DEBUG
		printf(
			"\n-CPU--TTY---PID---USER---PRI--NI------SIZE--------RES----S--TIME---%%CPU-----COMMAND-----\n");
#endif
		for (int j = 0, i = m_vctProcUsage.size() - 1;
			 i >= 0 && j < MAX_PROC_NUM;
			 i--, j++)
		{
			procinfo_linux	&pinfo = m_mapProcInfo[(m_vctProcUsage[i].pid)];
			sprintf((char *) &m_cProcInfo.CPU, "%d", pinfo.processor);
			if (pinfo.tty / 256 <= 0)
			{
				m_cProcInfo.TTY = "?";
			}
			else
			{
				sprintf((char *) &m_cProcInfo.TTY, "pts/%ld", pinfo.tty % 256);
			}

			m_cProcInfo.PID = pinfo.pid;
			m_cProcInfo.USERNAME = GetUserName(pinfo.uid).c_str();
			m_cProcInfo.PRI = pinfo.counter;
			m_cProcInfo.NI = pinfo.priority;
			m_cProcInfo.SIZE = pinfo.vsize;
			m_cProcInfo.RES = pinfo.rss;
			m_cProcInfo.STATE = pinfo.state;
			sprintf(
				(char *) &m_cProcInfo.TIME,
				"%d:%02d",
				(const int)(pinfo.utime + pinfo.stime) / 100 / 60,
				(const int)(pinfo.utime + pinfo.stime) / 100 % 60);
			m_cProcInfo.pWCPU = pinfo.cpuusage;
			m_cProcInfo.pCPU = pinfo.cpuusage;
			m_cProcInfo.COMMAND = pinfo.cmdname;
			FTDC_ADD_FIELD(&m_pkgSend, &m_cProcInfo);
#ifdef PRINT_DEBUG
			ShowProcInfo(pinfo);
#endif
		}

		OSSENDPACKAGETO;
	}

	return true;
}

bool COperatorSystemSpiImpl::NewGetNetwork(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRNET);

	m_pkgSend.PreparePackage(
			FTD_TID_RtnNetworkInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnNetworkInfoField field;

	static unsigned int uCount = 0;
	map<string, netinfo>::iterator	mapIt;
	if (0 == m_mapNetInfo.size() || 0 == uCount++ % 10) // 每10次尝试刷新网卡状态(UP/DOWN)
	{
		GetNetCardInfo();
	}

	if (ScanNetDev())
	{
		field.HostName = m_mObjectId;
		field.MonTime = m_mTime;
		field.MonDate = m_mDate;
		for (mapIt = m_mapNetInfo.begin(); mapIt != m_mapNetInfo.end(); mapIt++)
		{
#if 0
			printf(
				"LanName:%s %s %s\n%ld %ld %ld %ld\n",
				mapIt->second.name.c_str(),
				mapIt->second.state.c_str(),
				mapIt->second.ip.c_str(),
				mapIt->second.rcvpkgs,
				mapIt->second.sndpkgs,
				mapIt->second.rcvbytes,
				mapIt->second.sndbytes);
#endif
			field.LANNAME = mapIt->second.name.c_str();
			field.LANSTATUS = mapIt->second.state.c_str();
			field.IPADDRESS = mapIt->second.ip.c_str();
			field.RECVBYTES = mapIt->second.rcvbytes;
			field.RECVPACKETS = mapIt->second.rcvpkgs;
			field.RECVERRORPACKETS = mapIt->second.rcverrpkgs;
			field.RECVDROPPACKETS = mapIt->second.rcvdrppkgs;
			field.SENDBYTES = mapIt->second.sndbytes;
			field.SENDPACKETS = mapIt->second.sndpkgs;
			field.SENDERRORPACKETS = mapIt->second.snderrpkgs;
			field.SENDDROPPACKETS = mapIt->second.snddrppkgs;
			if (m_pkgSend.Length() + sizeof(field) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				OSSENDPACKAGETO;
				m_pkgSend.PreparePackage(
						FTD_TID_RtnNetworkInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &field);
		}

		OSSENDPACKAGETO;

		// 更新主机流量信息
		UpdateHostNetFlowInfo();

		return true;
	}
	else
	{
		return false;
	}
}

// 以下为LINUX专属段

// Added by Henchi 20081024 for Linux
bool COperatorSystemSpiImpl::GetNetCardInfo(void)
{
	int fd;

	int interface = 0;
	struct ifreq buf[MAX_LANHW_NUM];
	struct ifconf ifc;
	netinfo ninfo;

	TIME_MEASURE_START(__FUNCTION__);

	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		return false;
	}

	ifc.ifc_len = sizeof buf;
	ifc.ifc_buf = (caddr_t) buf;
	if (!ioctl(fd, SIOCGIFCONF, (char *) &ifc))
	{
		interface = ifc.ifc_len / sizeof(struct ifreq);

		char macaddr[32] = "";
		while (interface-- > 0)
		{
			bool isLoopbackIF = false;
			ninfo.name = buf[interface].ifr_name;
			if (!(ioctl(fd, SIOCGIFFLAGS, (char *) &buf[interface])))
			{
				if (buf[interface].ifr_flags & IFF_PROMISC)
				{	// Promisc
					ninfo.state = "Promisc";
				}
				else if (buf[interface].ifr_flags & IFF_UP)
				{	// Up
					ninfo.state = "Up";
				}
				else
				{	// Down
					ninfo.state = "Down";
				}

				if (buf[interface].ifr_flags & IFF_LOOPBACK)
				{
					isLoopbackIF = true;
				}
			}
			else
			{
				continue;
			}

			// asuming this interface is a virtual interface
			// then we determine by its address and loopback
			ninfo.iftype = NetInterface_VIRTUAL;
			/*Get IP of the net card */
			if (!(ioctl(fd, SIOCGIFADDR, (char *) &buf[interface])))
			{
				ninfo.ip = inet_ntoa(
						((struct sockaddr_in *)(&buf[interface].ifr_addr))->sin_addr);
				// if this interface has an ip address, and alos it's not a loopback interface
				// then we consider it is a physical interface
				if (!isLoopbackIF)
				{
					ninfo.iftype = NetInterface_PHYSICAL;
#ifdef PRINT_DEBUG
					printf("%s is a Physical Interface\n", ninfo.ip.c_str());
#endif
				}
			}
			else
			{
				ninfo.ip = "0.0.0.0";
			}

			/* Get Mask of the net card */
			if (!(ioctl(fd, SIOCGIFNETMASK, (char *) &buf[interface])))
			{
				ninfo.mask = inet_ntoa(
						((struct sockaddr_in *)(&buf[interface].ifr_netmask))->sin_addr);
			}
			else
			{
				ninfo.mask = "255.0.0.0";
			}

			/*Get GateWay ... can use SIOCGIFBRDADDR */
			/* Get MacAddr of the net card */
			if (!(ioctl(fd, SIOCGIFHWADDR, (char *) &buf[interface])))
			{
				sprintf(
					macaddr,
					"0x%02x%02x%02x%02x%02x%02x",
					(unsigned char)buf[interface].ifr_hwaddr.sa_data[0],
					(unsigned char)buf[interface].ifr_hwaddr.sa_data[1],
					(unsigned char)buf[interface].ifr_hwaddr.sa_data[2],
					(unsigned char)buf[interface].ifr_hwaddr.sa_data[3],
					(unsigned char)buf[interface].ifr_hwaddr.sa_data[4],
					(unsigned char)buf[interface].ifr_hwaddr.sa_data[5]);
				ninfo.mac = macaddr;
			}
			else
			{
				ninfo.mac = "";
			}

			// add info into map
			m_mapNetInfo[ninfo.name] = ninfo;
#ifdef PRINT_DEBUG
			printf(
				"NetCard:%s\t%s\t%s\t%s\t%s\n",
				ninfo.name.c_str(),
				ninfo.state.c_str(),
				ninfo.ip.c_str(),
				ninfo.mask.c_str(),
				ninfo.mac.c_str());
#endif
		}			//end of while
	}

	close(fd);
	TIME_MEASURE_END(__FUNCTION__);
	return m_mapNetInfo.size() > 0 ? true : false;
}

void COperatorSystemSpiImpl::show_logged_info(struct utmp *utbufp)
{
	if (utbufp->ut_type != USER_PROCESS)
	{
		return;
	}

	long ltime = (long)utbufp->ut_time;
	printf(
		"%-8.8s %-12.12s %12.12s (%s)\n",
		utbufp->ut_name,
		utbufp->ut_line,
		ctime(&ltime) + 4,
		utbufp->ut_host);
}

bool COperatorSystemSpiImpl::IsDir(char *pszPath)
{
	struct stat stStat;
	if (lstat(pszPath, &stStat) < 0)
	{
#ifdef PRINT_DEBUG
		printf(
			"lstat error for %s!\n[%s(%d):%d]\n",
			pszPath,
			__FILE__,
			__LINE__,
			errno);
#endif
		return false;
	}

	if (S_ISDIR(stStat.st_mode) || S_ISLNK(stStat.st_mode))
	{
		return true;
	}

	return false;
}

bool COperatorSystemSpiImpl::IsNumber(char *pszData)
{
	if (!pszData || !strlen(pszData))
	{
		return false;
	}

	char *p = pszData;
	for (int i = 0; i < strlen(pszData); i++)
	{
		if (!isdigit(*(p + i)))
		{
			return false;
		}
	}

	return true;
}

int COperatorSystemSpiImpl::GetProcessor(pst_processor *processor)
{
	char szFileName[] = "/proc/stat";
	char *p = NULL;
	int iCpuNum = 0;
	FILE *fpSrc;

	float loadavg = GetLoadAvg_1M();
#ifdef PRINT_DEBUG
	printf("LoadAvg = %f \n", loadavg);
#endif
	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_LINE_LEN];

	char szTmp[MAX_LINE_LEN];
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;				// 除去行尾换行符
		if (0 == strncmp(szBuf, CPU_TIP, strlen(CPU_TIP)))
		{
			p = szBuf + strlen(CPU_TIP);
			if (*p != BLANK_FLAG)						// CPU - n
			{
				p = SeekChar(p, BLANK_FLAG);
				if (7 == sscanf(
						p,
					"%ld %ld %ld %ld %ld %ld %ld",
					&(processor[iCpuNum].psp_cpu_time[CP_USER]),
					&(processor[iCpuNum].psp_cpu_time[CP_NICE]),
					&(processor[iCpuNum].psp_cpu_time[CP_SYS]),
					&(processor[iCpuNum].psp_cpu_time[CP_IDLE]),
					&(processor[iCpuNum].psp_cpu_time[CP_SWAIT]),
					&(processor[iCpuNum].psp_cpu_time[CP_INTR]),
					&(processor[iCpuNum].psp_cpu_time[CP_SSYS])))
				{
					processor[iCpuNum].psp_cpu_time[CP_BLOCK] = 0;
					processor[iCpuNum].psp_avg_1_min = (const double)loadavg;
					processor[iCpuNum].psp_idx = (unsigned long)iCpuNum;
					/// Mod by Henchi, 20160301
					/// 避免CPU个数超过MAX_CPUNUM而造成内存溢出
					if (MAX_CPUNUM <= ++iCpuNum)
					{
						printf("\nNOTIFY: CPU Cores is More than threshold [%d]\n\n", MAX_CPUNUM);
						break;	
					}									
				}
			}
		}
		else
		{
			continue;
		}
	}

	fclose(fpSrc);
	/// Notify: 应确保返回的iCpuNum不超出容量大小限制MAX_CPUNUM
	return iCpuNum;
}

float COperatorSystemSpiImpl::GetLoadAvg_1M(void)
{
	FILE *fpSrc;
	char avg1[10];
	float avg;

	if ((fpSrc = fopen("/proc/loadavg", "r")))
	{
		fscanf(fpSrc, "%f %*s %*s %*s %*s", &avg);
		fclose(fpSrc);
		return avg;
	}
	else
	{
		return 0.0;
	}
}

bool COperatorSystemSpiImpl::ScanSwaps(void)
{
	FILE *fpSrc;
	char szBuf[BLOCK_SIZE];
	int iTmp;
	if (!(fpSrc = fopen("/proc/swaps", "r")))
	{
		return false;
	}

	/* 须解析如下形式信息
	Filename                                Type            Size    Used    Priority
	/dev/cciss/c0d0p6                       partition       8393920 0       -1
	*/
	m_iSwap = 0;
	fgets(szBuf, BLOCK_SIZE, fpSrc);					// Head tips, Drop
	while (fgets(szBuf, BLOCK_SIZE, fpSrc))
	{
		if (5 == sscanf(
				szBuf,
			"%s %s %d %d %d\n",
			(const char *)m_cSwap[m_iSwap].location.getValue(),
			(const char *)m_cSwap[m_iSwap].type.getValue(),
			(const int *) &m_cSwap[m_iSwap].size,
			&iTmp,
			(const int *) &m_cSwap[m_iSwap].priority))
		{
			m_cSwap[m_iSwap].size /= 1024;
			m_iSwap++;
		}
	}

	fclose(fpSrc);
	return m_iSwap ? true : false;
}

bool COperatorSystemSpiImpl::ScanMemInfo(void)
{
	char szFileName[] = "/proc/meminfo";
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return false;
	}

	char szBuf[MAX_LINE_LEN];

	char szTmp[MAX_LINE_LEN];
	long lTotalReal;
	long lFreeReal;
	long lBuffer;
	long lCache;
	long lTotalSwap;
	long lFreeSwap;
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;				// 除去行尾换行符
		if (0 == strncmp(szBuf, MEM_TOTAL_TIP, strlen(MEM_TOTAL_TIP)))
		{
			lTotalReal = atol(SeekChar(szBuf, COLON_FLAG));
			m_mMemory = lTotalReal;
		}
		else if (0 == strncmp(szBuf, MEM_FREE_TIP, strlen(MEM_FREE_TIP)))
		{
			lFreeReal = atol(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, MEM_BUF_TIP, strlen(MEM_BUF_TIP)))
		{
			lBuffer = atol(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, MEM_CACHE_TIP, strlen(MEM_CACHE_TIP)))
		{
			lCache = atol(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, SWAP_TOTAL_TIP, strlen(SWAP_TOTAL_TIP)))
		{
			lTotalSwap = atol(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, SWAP_FREE_TIP, strlen(SWAP_FREE_TIP)))
		{
			lFreeSwap = atol(SeekChar(szBuf, COLON_FLAG));
		}
		else
		{
			continue;
		}
	}

	m_cMemInfo.TOTALREAL = lTotalReal;					// 实际总物理内存
	m_cMemInfo.ACTIVEREAL = lTotalReal - lFreeReal;		// 系统已分配占用的内存
	m_cMemInfo.TOTALVIRTUAL = lTotalSwap;				// 实际交换分区(虚存)
	m_cMemInfo.ACTIVEVIRTUAL = lTotalSwap - lFreeSwap;	// 实际已分配占用的虚存
	m_cMemInfo.FREE = lFreeReal + lBuffer + lCache;		// 总空闲内存量
	fclose(fpSrc);
	return true;
}

bool COperatorSystemSpiImpl::ScanNetDev(void)
{
	char szFileName[] = "/proc/net/dev";
	char *p = NULL;
	FILE *fpSrc;

	TIME_MEASURE_START(__FUNCTION__);
	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return false;
	}

	struct ifinfo
	{
		char name[8];
		unsigned long long	r_bytes;
		unsigned long long	r_pkt;
		unsigned long long	r_err;
		unsigned long long	r_drop;
		unsigned long long	r_fifo;
		unsigned long long	r_frame;
		unsigned long long	r_compr;
		unsigned long long	r_mcast;
		unsigned long long	x_bytes;
		unsigned long long	x_pkt;
		unsigned long long	x_err;
		unsigned long long	x_drop;
		unsigned long long	x_fifo;
		unsigned long long	x_coll;
		unsigned long long	x_carrier;
		unsigned long long	x_compr;
	} sifc;

	char szBuf[1024];

	char szTmp[1024];
	fgets(szBuf, sizeof(szBuf), fpSrc);					// header
	fgets(szBuf, sizeof(szBuf), fpSrc);
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		if (sscanf(
				szBuf,
			" %6[^:]:%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",
		&sifc.name,
			&sifc.r_bytes,
			&sifc.r_pkt,
			&sifc.r_err,
			&sifc.r_drop,
			&sifc.r_fifo,
			&sifc.r_frame,
			&sifc.r_compr,
			&sifc.r_mcast,
			&sifc.x_bytes,
			&sifc.x_pkt,
			&sifc.x_err,
			&sifc.x_drop,
			&sifc.x_fifo,
			&sifc.x_coll,
			&sifc.x_carrier,
			&sifc.x_compr) == 16)
		{
			map<string, netinfo>::iterator	mapIt;
			if ((mapIt = m_mapNetInfo.find(sifc.name)) != m_mapNetInfo.end())
			{
				mapIt->second.rcvbytes = sifc.r_bytes;
				mapIt->second.rcvpkgs = sifc.r_pkt;
				mapIt->second.rcverrpkgs = sifc.r_err;
				mapIt->second.rcvdrppkgs = sifc.r_drop;
				mapIt->second.sndbytes = sifc.x_bytes;
				mapIt->second.sndpkgs = sifc.x_pkt;
				mapIt->second.snderrpkgs = sifc.x_err;
				mapIt->second.snddrppkgs = sifc.x_drop;
			}
		}
	}

	fclose(fpSrc);
	TIME_MEASURE_END(__FUNCTION__);
	return true;
}

void COperatorSystemSpiImpl::ScanCmd(char *pszFileName, procinfo &pinfo)
{
	if (!pszFileName)
	{
		return;
	}

	FILE *fpSrc;
	if (!(fpSrc = fopen(pszFileName, "r")))
	{
		return;
	}

	char szCmdLine[MAX_BUF_SIZE];
	memset(szCmdLine, 0x00, MAX_BUF_SIZE);

	int iRead = fread(szCmdLine, 1, MAX_BUF_SIZE - 1, fpSrc);
	fclose(fpSrc);

	memset(&(pinfo.cmdline), 0x00, MAX_BUF_SIZE);
	for (int i = 0, j = 0; i < iRead; i++)
	{
		while (i < iRead)
		{
			if (!isgraph(szCmdLine[i]))
			{
				i++;
			}
			else if (strlen(pinfo.cmdline) + strlen(szCmdLine + i) < MAX_BUF_SIZE)
			{
				j++;
				if (strlen(pinfo.cmdline))
				{
					/// Mod by Henchi, 20150526
					strcat(pinfo.cmdline, "#");			// separated the arguments by sharp
				}

				if (j == 2)
				{
					strncpy(pinfo.args, szCmdLine + i, MAX_PATH_LEN - 1);	// get first argument
				}

				strcat(pinfo.cmdline, szCmdLine + i);
				i += strlen(szCmdLine + i);
			}
			else
			{
				break;
			}
		}
	}
}

void COperatorSystemSpiImpl::ScanProcStat(char *pszFileName, procinfo &pinfo)
{
	if (!pszFileName)
	{
		return;
	}

	FILE *fpSrc;
	if (!(fpSrc = fopen(pszFileName, "r")))
	{
		return;
	}

	char szStatStr[MAX_BUF_SIZE];

	char *s;

	char *t;

	if ((s = fgets(szStatStr, sizeof(szStatStr), fpSrc)) == NULL)
	{
		fclose(fpSrc);
		return;
	}

	fclose(fpSrc);

	unsigned int uTime = time((time_t *)NULL);
	sscanf(szStatStr, "%u", &(pinfo.pid));
	s = strchr(szStatStr, '(') + 1;
	t = strchr(szStatStr, ')');
	strncpy(pinfo.cmdname, s, t - s);
	pinfo.cmdname[t - s] = '\0';
	/// Added by Henchi, 20150727
	/// for SmartsControl.p => SmartsControl
	s = strchr(pinfo.cmdname, '.');
	if (s != NULL)
		*s = 0x00;
		
	pinfo.currenttime = uTime;

	/*              1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 */
	sscanf(
		t + 2,
		"%c %d %d %d %d %d %u %u %u %u %u %d %d %d %d %d %d %u %u %u %u %u %u %u %u %u %u %u %d %d %d %d %u %u %u %d %d %u %u",
		&(pinfo.state),
		&(pinfo.ppid),
		&(pinfo.pgrp),
		&(pinfo.session),
		&(pinfo.tty),
		&(pinfo.tpgid),
		&(pinfo.flags),
		&(pinfo.minflt),
		&(pinfo.cminflt),
		&(pinfo.majflt),					// 10
		&(pinfo.cmajflt),
		&(pinfo.utime),
		&(pinfo.stime),
		&(pinfo.cutime),
		&(pinfo.cstime),
		&(pinfo.counter),
		&(pinfo.priority),
		&(pinfo.timeout),
		&(pinfo.itrealvalue),
		&(pinfo.starttime),					// 20
		&(pinfo.vsize),
		&(pinfo.rss),
		&(pinfo.rlim),
		&(pinfo.startcode),
		&(pinfo.endcode),
		&(pinfo.startstack),
		&(pinfo.kstkesp),
		&(pinfo.kstkeip),
		&(pinfo.signal),
		&(pinfo.blocked),					// 30
		&(pinfo.sigignore),
		&(pinfo.sigcatch),
		&(pinfo.wchan),
		&(pinfo.nswap),
		&(pinfo.cnswap),
		&(pinfo.exit_signal),
		&(pinfo.processor),
		&(pinfo.rt_priority),
		&(pinfo.policy));
}

void COperatorSystemSpiImpl::ShowProcInfo(procinfo_linux &pinfo)
{
	printf(
		"  %d  %3d/%d %5d %5d   %3d %3d %10u K %8u K %c %3d:%02d %6.2f %-s\n",
		pinfo.processor,
		(const int)(pinfo.tty) / 256,
		(const int)(pinfo.tty) % 256,
		pinfo.pid,
		pinfo.uid,
		pinfo.counter,
		pinfo.priority,
		pinfo.vsize,
		pinfo.rss,
		pinfo.state,
		(const int)(pinfo.utime + pinfo.stime) / 100 / 60,
		(const int)(pinfo.utime + pinfo.stime) / 100 % 60,
		pinfo.cpuusage,
		pinfo.cmdname);
}

void COperatorSystemSpiImpl::ScanStatus(char *pszFileName, procinfo &pinfo)
{
	if (!pszFileName)
	{
		return;
	}

	FILE *fpSrc;
	if (!(fpSrc = fopen(pszFileName, "r")))
	{
		return;
	}

	char szBuf[MAX_LINE_LEN];
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;	// 除去行尾换行符
		if (0 == strncmp(szBuf, UID_TIP, strlen(UID_TIP)))
		{
			pinfo.uid = atoi(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, TGID_TIP, strlen(TGID_TIP)))
		{
			pinfo.tgid = atoi(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, THREADS_TIP, strlen(THREADS_TIP)))
		{
			pinfo.threads = atoi(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, SIZE_TIP, strlen(SIZE_TIP)))
		{
			pinfo.vsize = atoi(SeekChar(szBuf, COLON_FLAG));
		}
		else if (0 == strncmp(szBuf, RES_TIP, strlen(RES_TIP)))
		{
			pinfo.rss = atoi(SeekChar(szBuf, COLON_FLAG));
		}
		else
		{
			continue;
		}
	}

	fclose(fpSrc);
}

///	Save the information of process into map<> or vector<>
void COperatorSystemSpiImpl::SaveProcInfo(procinfo_linux &pinfo)
{
	/* 判断此进程信息是否为新启动进程，若为新，则其CPU使用率初始为0,并保存信息入map
	若不为新，则结合其初始信息计算CPU使用率，更新map信息，并写vector*/
	//	map < int, procinfo_linux > m_mapProcInfo;
	//	vector < proc_cpuusage > m_vctProcUsage;
	TIME_MEASURE_START(__FUNCTION__);

	map<int, procinfo_linux>::iterator	mapIt = m_mapProcInfo.find(pinfo.pid);

	/// Modify by Henchi, 20090302 修正原代码中除法溢出BUG
	if (mapIt != m_mapProcInfo.end()
	&&	strcmp(pinfo.cmdname, (mapIt->second).cmdname) == 0
	&&	pinfo.currenttime > (mapIt->second).currenttime)
	{
		// 属于原有进程，需计算新的CPU使用率
		pinfo.cpuusage = (float)
			(
				(
					(pinfo.utime - (mapIt->second).utime) +
						(pinfo.stime - (mapIt->second).stime)
				) * 1.00 / (pinfo.currenttime - (mapIt->second).currenttime)
			);

		proc_cpuusage pusage;
		pusage = pinfo;
		m_vctProcUsage.push_back(pusage);
	}

	m_mapProcInfo[pinfo.pid] = pinfo;

	// 特殊进程的处理
	int iFlag = IsSpcProc(pinfo.cmdname);
	if (iFlag >0)
	{
		char szApp[MAX_NAMELEN];
		int iArg = atoi(pinfo.args);

		/// Mod by Henchi, 20150427
		/// g_mSpcPrcMap 中可能出现被破坏的数据
		/// 改为仅通过Args信息判断		
		
		//if (iFlag == 2 || iArg == 0 )
		if ( iArg <= 0 )
		{
			sprintf(szApp, "%s", pinfo.cmdname);
		}
		else
		{
			sprintf(szApp, "%s.%d", pinfo.cmdname, iArg);
		}
		sprintf(m_mAppId, "%s.%s", m_mAppName, szApp);

		// Added by Henchi 20081126 针对新产生的业务进程发送相关变更信息
		if (g_mAppNamePidMap.find(string(szApp)) == g_mAppNamePidMap.end())
		{
			SendUpdateSyscfgPkg((const char *)g_pHostName, (const char *)szApp);
		}

		g_mAppNamePidMap[string(szApp)] = pinfo.pid;
		m_lSpcProc.push_back(string(szApp));

		m_cObjectAttr.ObjectID = m_mAppId;
		m_cObjectAttr.ValueType = INT_ATTR;
		m_cObjectAttr.AttrType = APPATTRTHREADS;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%d",
			pinfo.threads);
		m_ObjectAttrList.add(m_cObjectAttr);

		m_cObjectAttr.ValueType = INT_ATTR;
		m_cObjectAttr.AttrType = APPATTRACTIVE;
		m_cObjectAttr.AttrValue = "1";
		m_ObjectAttrList.add(m_cObjectAttr);

		m_cObjectAttr.ValueType = PERCENT_ATTR;
		m_cObjectAttr.AttrType = APPATTRCPUUSAGE;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%.2f",
			pinfo.cpuusage);
		m_ObjectAttrList.add(m_cObjectAttr);

		m_cObjectAttr.AttrType = APPATTRMEMORYUSAGE;

		float fMemUsage = m_mMemory > 0 ? (pinfo.rss * 100.0 / m_mMemory) : 0;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%.2f",
			fMemUsage);
		m_ObjectAttrList.add(m_cObjectAttr);

		float fDiskUsage, fInodeUsage;
		if (GetDiskUsage((char *)g_mSpcPrcMap[szApp].c_str(), fDiskUsage,  fInodeUsage))
		{
			m_cObjectAttr.AttrType = APPATTRDISKUSAGE;
			sprintf(
				(char *)(m_cObjectAttr.AttrValue.getValue()),
				"%.2f",
				fDiskUsage);
			m_ObjectAttrList.add(m_cObjectAttr);
			
			m_cObjectAttr.AttrType = APPATTRINODEUSAGE;
			sprintf(
				(char *)(m_cObjectAttr.AttrValue.getValue()),
				"%.2f",
				fInodeUsage);
			m_ObjectAttrList.add(m_cObjectAttr);
		}
	}

	TIME_MEASURE_END(__FUNCTION__);
}

void COperatorSystemSpiImpl::ScanProcesses(void)
{
	char szPath[] = "/proc/";
	char szProcess[MAX_PATH_LEN];
	char szProcCmd[MAX_PATH_LEN];
	char szProcStatus[
		MAX_PATH_LEN];
	char szProcStat[MAX_PATH_LEN];
	DIR *pDir;
	struct dirent *pstDirent;

	TIME_MEASURE_START(__FUNCTION__);

	pDir = opendir(szPath);
	if (!pDir)
	{
		printf(
			"Open FS /proc failed!\n[%s(%d):%d]\n",
			__FILE__,
			__LINE__,
			errno);
		fflush(stdout);
		return;
	}

	m_cObjectAttr.ValueType = PERCENT_ATTR;

	int iTotal = 0;
	int iBlocked = 0;
	int iSleep = 0;
	int iRun = 0;
	int iZombie = 0;

	while ((pstDirent = readdir(pDir)))
	{
		if ((strcmp(pstDirent->d_name, ".") == 0)
		||	(strcmp(pstDirent->d_name, "..") == 0)
		||	!IsNumber(pstDirent->d_name))
		{
			continue;
		}

		sprintf(szProcess, "%s%s", szPath, pstDirent->d_name);
		if (IsDir(szProcess))
		{
			sprintf(szProcCmd, "%s/cmdline", szProcess);
			sprintf(szProcStat, "%s/stat", szProcess);
			sprintf(szProcStatus, "%s/status", szProcess);

			procinfo pinfo;
			memset((void *) &pinfo, 0x00, sizeof(pinfo));
			if (0 == access(szProcCmd, F_OK))
			{
				ScanCmd(szProcCmd, pinfo);
			}

			if (0 == access(szProcStat, F_OK))
			{
				ScanProcStat(szProcStat, pinfo);
			}

			if (0 == access(szProcStatus, F_OK))
			{
				ScanStatus(szProcStatus, pinfo);
			}

			if (strcmp(pinfo.cmdname, "java") == 0 || strcmp(pinfo.cmdname, "/usr/bin/java") == 0)
			{
				GetJavaProcInfo(pinfo);
			}
			/// /usr/bin/perl /smarts/control/latest/SmartsControl.pl
			/// /proc/PID/stat中对应 cmdname SmartsControl.p
			/// 改采用cmdline来识别perl进程
			else if (memcmp(pinfo.cmdline, "perl", strlen("perl")) == 0 || memcmp(pinfo.cmdline, "/usr/bin/perl", strlen("/usr/bin/perl")) == 0)
			{
				GetPerlProcInfo(pinfo);
			}

			iTotal++;
			switch (pinfo.state)
			{
				case 'D':
					iBlocked++;
					break;
				case 'R':
					iRun++;
					break;
				case 'S':
					iSleep++;
					break;
				case 'Z':
					iZombie++;
					break;
				default:
					break;
			}

			/// Mod by Henchi, 20150421
			/// Only Save main process infos
			if (pinfo.pid == pinfo.tgid)
			{
				procinfo_linux	m_procinfo;
				m_procinfo = pinfo;
				SaveProcInfo(m_procinfo);
			}

		}
	}

	// 采集内存指标
	m_cObjectAttr.ObjectID = m_mObjectName;
	m_cObjectAttr.ValueType = INT_ATTR;

	m_cObjectAttr.AttrType = OSATTRPROCTOTAL;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%d", iTotal);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRPROCSLEEP;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%d", iSleep);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRPROCRUN;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%d", iRun);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRPROCBLOCK;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%d", iBlocked);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRPROCZOMBIE;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%d", iZombie);
	m_ObjectAttrList.add(m_cObjectAttr);

	closedir(pDir);
	TIME_MEASURE_END(__FUNCTION__);
}

void COperatorSystemSpiImpl::GetPerlProcInfo(procinfo &pinfo)
{
	char szCmdLine[MAX_BUF_SIZE];
	char szCmdName[MAX_BUF_SIZE];

	int length = strlen(pinfo.cmdline);
	memset(szCmdName, 0x00, MAX_BUF_SIZE);
	memset(szCmdLine, 0x00, MAX_BUF_SIZE);
	strncpy(szCmdLine, pinfo.cmdline, MAX_BUF_SIZE - 1);

	int i = 0;
	char *p = strtok(szCmdLine, "#");
	while (p != NULL)
	{
		p = strtok(NULL, "#");
		if (p != NULL && strcmp(p +strlen(p)-3, ".pl") ==0)
		{
			char *q = strrchr(p, '/');
			if (q != NULL)
			{
				strncpy(szCmdName, q+1, strlen(q+1) -3);	
			}
			else
			{
				strncpy(szCmdName, p, strlen(p) -3);
			}	
			p = strtok(NULL, "#");
			if (p != NULL) strcpy(pinfo.args, p);
			break;
		}
	}
	/// 截断所有文件后缀名
	p = strrchr(szCmdName, '.');
	if (p != NULL)
		*p = 0x00;
	sprintf((char *)&pinfo.cmdname, "perl_%s", szCmdName);
}

void COperatorSystemSpiImpl::GetJavaProcInfo(procinfo &pinfo)
{
	char szCmdLine[MAX_BUF_SIZE];
	char szCmdName[MAX_BUF_SIZE];
	int length = strlen(pinfo.cmdline);
	memset(szCmdLine, 0x00, MAX_BUF_SIZE);
	memset(szCmdName, 0x00, MAX_BUF_SIZE);

	strncpy(szCmdLine, pinfo.cmdline, MAX_BUF_SIZE - 1);

	char *p = strtok(szCmdLine, "#");
	while (p != NULL)
	{
		p = strtok(NULL, "#");

		if (p != NULL)
		{
			// 解析Java进程执行的MainClass
			if (*p != '-' && *p != ':')
			{
				char *q = (strrchr(p, '/') == NULL) ? p : strrchr(p, '/') + 1;
				strncpy(szCmdName, q, MAX_PATH_LEN - 1);
				
				p = (strrchr(szCmdName, '.') == NULL) ? szCmdName : strrchr(szCmdName, '.');
				
				// Added by Henchi, 20150724
				// 解析形如: java -X... com.cmcrc.feedprocessor.Main
				// 取 feedprocessor
				if (strcmp(p, ".Main") == 0)
				{
					*p = 0x00;
					p = (strrchr(szCmdName, '.') == NULL) ? szCmdName : strrchr(szCmdName, '.') +1;
					strncpy(pinfo.cmdname, p, MAX_PATH_LEN - 1);				
				}
				// Added by Henchi, 20091021
				// 解析形如: java -Xms2048m org.tanukisoftware.wrapper.WrapperSimpleApp socket.MonitorMain
				// 应当抛弃org...WrapperSimpleApp部分，取 MonitorMain
				else if (strcmp(p, ".WrapperSimpleApp") == 0)
				{
					continue;
				}
				else
				{
					if (strlen(p) >1 && *p == '.')
					{
						p++;
					}	
					strncpy(pinfo.cmdname, p, MAX_PATH_LEN - 1);				
				}
				
				q = strtok(NULL, "#");
				if (q != NULL)
				{
					strncpy(pinfo.args, q, MAX_PATH_LEN - 1);
				}
				else
				{
					strcpy(pinfo.args, "");
				}

				break;
			}

			// Added by Henchi, 20091028
			// 用于获取排除命令行中-classpath项
			else if (strncmp(p, "-classpath", 10) == 0)
			{
				p = strtok(NULL, "#");
			}

			// Added by Henchi, 20091026
			// 用于获取Tomcat进程的实际业务名： 如-Dcatalina.base=/home/uapp2/domains/access1 中的 access1
			else if (strncmp(p, "-Dcatalina.base", 15) == 0)
			{
				char *q = strrchr(p, '=') == NULL ? p : strrchr(p, '=') + 1;
				p = strrchr(q, '/') == NULL ? q : strrchr(q, '/') + 1;

				if (p != NULL)
				{
					q = p + strlen(p);
					while (isdigit(*(--q)) != 0)
					{
					}

					strcpy(pinfo.args, q + 1);
					*(q + 1) = 0x00;
					memset(pinfo.cmdname, 0x00, MAX_PATH_LEN);
					sprintf(pinfo.cmdname, "Bootstrap_%s", p);	// 得到进程名如：Bootstrap_access  1
				}

				break;
			}
		}
	}
}

int COperatorSystemSpiImpl::GetUptime(void)
{
	unsigned long long	llSecs = atoll(GetFirstLine("/proc/uptime"));

	m_cObjectAttr.ObjectID = m_mObjectName;

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRUPTIME;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%lld", llSecs);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = STRING_ATTR;
	m_cObjectAttr.AttrType = OSATTRUPTIMESTR;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%d days, %02d:%02d:%02d",
		llSecs / 86400,
		llSecs % 86400 / 3600,
		llSecs % 3600 / 60,
		llSecs % 60);
	m_ObjectAttrList.add(m_cObjectAttr);

	return 0;
}

int COperatorSystemSpiImpl::GetCPUInfo(void)
{
	char szFileName[] = "/proc/cpuinfo";
	char *p = NULL;
	FILE *fpSrc;
	char szVendor[MAX_BUF_SIZE] = "";
	char szModelName[MAX_BUF_SIZE] = "";
	char szCPUMHz[MAX_BUF_SIZE] = "";
	char szCacheSize[MAX_BUF_SIZE] = "";
	int iCores = 0;
	int iCPUs = 0;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_BUF_SIZE];
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;						// 除去行尾换行符
		if (
			strncmp(
				szBuf,
				TIP_CPUINFO_PROCESSOR,
				strlen(TIP_CPUINFO_PROCESSOR)) == 0
		)
		{
			iCPUs++;
		}
		else if (
			strlen(szVendor) == 0 &&
			strncmp(
				szBuf,
				TIP_CPUINFO_VENDOR,
				strlen(TIP_CPUINFO_VENDOR)) == 0
		)
		{
			strcpy(szVendor, strchr(szBuf, ':') + 2);
		}
		else if (
			strlen(szModelName) == 0 &&
			strncmp(
				szBuf,
				TIP_CPUINFO_MODELNAME,
				strlen(TIP_CPUINFO_MODELNAME)) == 0
		)
		{
			strcpy(szModelName, strchr(szBuf, ':') + 2);
		}
		else if (
			strlen(szCPUMHz) == 0 &&
			strncmp(
				szBuf,
				TIP_CPUINFO_CPUMHZ,
				strlen(TIP_CPUINFO_CPUMHZ)) == 0
		)
		{
			strcpy(szCPUMHz, strchr(szBuf, ':') + 2);
		}
		else if (
			strlen(szCacheSize) == 0 &&
			strncmp(
				szBuf,
				TIP_CPUINFO_CACHESIZE,
				strlen(TIP_CPUINFO_CACHESIZE)) == 0
		)
		{
			strcpy(szCacheSize, strchr(szBuf, ':') + 2);
		}
		else if (
			strncmp(
				szBuf,
				TIP_CPUINFO_CPUCORES,
				strlen(TIP_CPUINFO_CPUCORES)) == 0
		)
		{
			iCores = atoi(strchr(szBuf, ':') + 2);
		}
	}

	sprintf(m_cCommon.CPUVendor.getValue(), "%s", szVendor);
	sprintf(m_cCommon.CPUModel.getValue(), "%s", szModelName);
	sprintf(m_cCommon.CPUMHz.getValue(), "%s", szCPUMHz);
	sprintf(m_cCommon.CPUCache.getValue(), "%s", szCacheSize);
	m_cCommon.CPUCores = iCores;

#ifdef PRINT_DEBUG
	printf(
		"CPUINFO:\nVendor[%s]\nModel [%s]\nCPUMHz[%s]\nCache [%s]\nCPUs  [%d]\nCores [%d]\n",
		szVendor,
		szModelName,
		szCPUMHz,
		szCacheSize,
		iCPUs,
		iCores);
#endif
	g_nCPU = iCPUs;
	fclose(fpSrc);
	return iCPUs;
}

void COperatorSystemSpiImpl::HexStr2IP(char *pSrc, char *pDst, char *pDefault)
{
	if (pSrc == NULL || pDst == NULL || pDefault == NULL)
	{
		return;
	}

	if (strcmp(pSrc, "00000000") == 0)
	{
		strcpy(pDst, pDefault);
		return;
	}

	*pDst = 0x00;

	char szTmp[MAX_LINE_LEN];
	strcpy(szTmp, pSrc);

	int iCode;
	for (int i = 6; i >= 0; i -= 2)
	{
		sscanf(szTmp + i, "%0X", &iCode);
		if (i == 6)
		{
			sprintf(pDst, "%d", iCode);
		}
		else
		{
			sprintf(pDst, "%s.%d", pDst, iCode);
		}

		*(szTmp + i) = 0x00;
	}
}

int COperatorSystemSpiImpl::GetRoute(void)
{
	char szFileName[] = "/proc/net/route";
	char *p = NULL;
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_BUF_SIZE];
	char szIf[MAX_LINE_LEN];
	char szDest[MAX_LINE_LEN];
	char szGate[MAX_LINE_LEN];
	char szMask[MAX_LINE_LEN];
	char szDestStr[MAX_LINE_LEN];
	char szGateStr[MAX_LINE_LEN];
	char szMaskStr[MAX_LINE_LEN];
	int iFlags;
	int iRefCnt;
	int iUse;
	int iMetric;
	int iMtu;
	int iWin;
	int iRtt;

	m_pkgSend.PreparePackage(
		FTD_TID_RtnRouterInfoTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	CFTDRtnRouterInfoField	field;

	sprintf(m_mObjectId, "%s.route", m_mObjectName);
	field.HostName = m_mObjectId;
	field.MonTime = m_mTime;
	field.MonDate = m_mDate;

	int iCount = 0;
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;						// 除去行尾换行符

		// printf("BUF[%s]\n", szBuf);
		if (11 == sscanf(
			szBuf,
			"%s %s %s %d %d %d %d %s %d %d %d\n",
			szIf,
			szDest,
			szGate,
			&iFlags,
			&iRefCnt,
			&iUse,
			&iMetric,
			szMask,
			&iMtu,
			&iWin,
			&iRtt))
		{
			HexStr2IP(szDest, szDestStr, "default");
			HexStr2IP(szGate, szGateStr, "*");
			HexStr2IP(szMask, szMaskStr, "0.0.0.0");

			sprintf(field.Dev.getValue(), "%s", szIf);
			sprintf(field.Destination.getValue(), "%s", szDestStr);
			sprintf(field.Gateway.getValue(), "%s", szGateStr);
			sprintf(field.Mask.getValue(), "%s", szMaskStr);
			sprintf(field.Flag.getValue(), "%d", iFlags);
			field.RefCnt = iRefCnt;
			field.Use = iUse;
			field.Metric = iMetric;
			field.Mtu = iMtu;
			field.Win = iWin;
			field.Rtt = iRtt;

			if (m_pkgSend.Length() + sizeof(field) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				OSSENDPACKAGETO;
				m_pkgSend.PreparePackage(
					FTD_TID_RtnRouterInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &field);

#ifdef PRINT_DEBUG
			printf(
				"Get Info[%-8s %-16s %-16s %d %d %d %d %-16s %d %d %d]\n",
				szIf,
				szDestStr,
				szGateStr,
				iFlags,
				iRefCnt,
				iUse,
				iMetric,
				szMaskStr,
				iMtu,
				iWin,
				iRtt);
#endif
			iCount++;
		}
	}

	if (iCount > 0)
	{
		OSSENDPACKAGETO;
	}

	fclose(fpSrc);
	return iCount;
}

int COperatorSystemSpiImpl::GetNetStat(void)
{
	/// 单线程访问类对象
	m_iTcpListen = 0;
	m_iTcpAll = 0;
	m_iTcpEstablished = 0;
	m_iTcpOther = 0;
	m_iUdpEstablished = 0;
	m_iUdpClose = 0;

	GetTCPInfo();
	GetUDPInfo();

	/// 记录主机性能指标对象
	m_cObjectAttr.ObjectID = m_mObjectName;
	m_cObjectAttr.ValueType = INT_ATTR;

	m_cObjectAttr.AttrType = OSATTRTCPLISTEN;
	sprintf(
		(char *)(m_cObjectAttr.AttrValue.getValue()),
		"%d",
		m_iTcpListen);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRTCPALL;
	sprintf(
		(char *)(m_cObjectAttr.AttrValue.getValue()),
		"%d",
		m_iTcpAll);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRTCPESTABLISHED;
	sprintf(
		(char *)(m_cObjectAttr.AttrValue.getValue()),
		"%d",
		m_iTcpEstablished);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRTCPOTHER;
	sprintf(
		(char *)(m_cObjectAttr.AttrValue.getValue()),
		"%d",
		m_iTcpOther);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRUDPESTABLISHED;
	sprintf(
		(char *)(m_cObjectAttr.AttrValue.getValue()),
		"%d",
		m_iUdpEstablished);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRUDPCLOSE;
	sprintf(
		(char *)(m_cObjectAttr.AttrValue.getValue()),
		"%d",
		m_iUdpClose);
	m_ObjectAttrList.add(m_cObjectAttr);

#if defined PRINT_DEBUG
	printf("Netstat info:\nHOST[%s] DATETIME[%s %s]\nTCP:L[%d] A[%d] E[%d] O[%d]\nUDP:E[%d] C[%d]\n\n", 
		m_cObjectAttr.ObjectID.getValue(), m_cObjectAttr.MonDate.getValue(), m_cObjectAttr.MonTime.getValue(),
		m_iTcpListen, m_iTcpAll, m_iTcpEstablished, m_iTcpOther, m_iUdpEstablished, m_iUdpClose
		);
#endif
}

int COperatorSystemSpiImpl::GetPartitions(void)
{
	char szFileName[] = "/proc/partitions";
	char *p = NULL;
	int iRtn;
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_BUF_SIZE];
	int iCount = 0;
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;						// 除去行尾换行符

		// printf("BUF[%s]\n", szBuf);
		if (4 == sscanf(
				szBuf,
			"%u %u %llu %s\n",
			&g_partitions[iCount].major,
			&g_partitions[iCount].minor,
			&g_partitions[iCount].blocks,
			g_partitions[iCount].name))
		{
#ifdef PRINT_DEBUG
			printf(
				"Get Info[%u %u %llu %s]\n",
				g_partitions[iCount].major,
				g_partitions[iCount].minor,
				g_partitions[iCount].blocks,
				g_partitions[iCount].name);
#endif
			iCount++;
		}
	}

	fclose(fpSrc);
	return iCount <= MAX_PARTITIONS ? iCount : MAX_PARTITIONS;
}

int COperatorSystemSpiImpl::GetCPUTime(void)
{
	char szFileName[] = "/proc/stat";
	char *p = NULL;
	int iRtn;
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_BUF_SIZE];
	int iCount = 0;
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		if (!strncmp(szBuf, "cpu ", 4))
		{
			int items;
			unsigned long long	nice;
			unsigned long long	irq;
			unsigned long long	softirq;

			items = sscanf(
					szBuf,
					"cpu %llu %llu %llu %llu %llu %llu %llu",
					&g_cpu_new.user,
					&nice,
					&g_cpu_new.system,
					&g_cpu_new.idle,
					&g_cpu_new.iowait,
					&irq,
					&softirq);
			g_cpu_new.user += nice;
			if (items == 4)
			{
				g_cpu_new.iowait = 0;
			}

			if (items == 7)
			{
				g_cpu_new.system += irq + softirq;
			}

			break;
		}
	}

	fclose(fpSrc);
	return 0;
}

void COperatorSystemSpiImpl::GetStat(stat_info *pStatInfo)
{
	char szFileName[] = "/proc/stat";
	char *p = NULL;
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_LINE_LEN];

	char szTmp[MAX_LINE_LEN];
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;						// 除去行尾换行符
		if ((p = strstr(szBuf, TIP_STATINFO_CPUTOTAL)) != NULL)
		{
			sscanf(
				p + strlen(TIP_STATINFO_CPUTOTAL),
				"%Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu",
				&pStatInfo->cpu_user,
				&pStatInfo->cpu_nice,
				&pStatInfo->cpu_system,
				&pStatInfo->cpu_idle,
				&pStatInfo->cpu_iowait,
				&pStatInfo->cpu_irq,
				&pStatInfo->cpu_sirq,
				&pStatInfo->cpu_steal);
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_INTR)) != NULL)
		{
			sscanf(p + strlen(TIP_STATINFO_INTR), "%Lu", &pStatInfo->intr);
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_CONTEXT)) != NULL)
		{
			sscanf(p + strlen(TIP_STATINFO_CONTEXT), "%Lu", &pStatInfo->ctxt);
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_PROCESSES)) != NULL)
		{
			sscanf(
				p + strlen(TIP_STATINFO_CONTEXT),
				"%Lu",
				&pStatInfo->processes);
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_PROCRUN)) != NULL)
		{
			sscanf(
				p + strlen(TIP_STATINFO_PROCRUN),
				"%u",
				&pStatInfo->proc_run);
			pStatInfo->proc_run = pStatInfo->proc_run > 0 ? pStatInfo->
					proc_run -
				1 : 0;
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_PROCBLOCKED)) != NULL)
		{
			sscanf(
				p + strlen(TIP_STATINFO_PROCBLOCKED),
				"%u",
				&pStatInfo->proc_blk);
		}
	}

	fclose(fpSrc);
}

void COperatorSystemSpiImpl::GetVMStat(stat_info *pStatInfo)
{
	char szFileName[] = "/proc/vmstat";
	char *p = NULL;
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_LINE_LEN];

	char szTmp[MAX_LINE_LEN];
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;						// 除去行尾换行符
		if ((p = strstr(szBuf, TIP_STATINFO_PAGEIN)) != NULL)
		{
			sscanf(p + strlen(TIP_STATINFO_PAGEIN), "%Lu", &pStatInfo->page_in);
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_PAGEOUT)) != NULL)
		{
			sscanf(
				p + strlen(TIP_STATINFO_PAGEOUT),
				"%Lu",
				&pStatInfo->page_out);
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_SWAPIN)) != NULL)
		{
			sscanf(p + strlen(TIP_STATINFO_SWAPIN), "%Lu", &pStatInfo->swap_in);
		}
		else if ((p = strstr(szBuf, TIP_STATINFO_SWAPOUT)) != NULL)
		{
			sscanf(
				p + strlen(TIP_STATINFO_SWAPOUT),
				"%Lu",
				&pStatInfo->swap_out);
		}
	}

	fclose(fpSrc);
}


long COperatorSystemSpiImpl::GetAppPid(string AppName)
{
	if (g_mAppNamePidMap.find(AppName) == g_mAppNamePidMap.end())
	{
		return -1;
	}
	else
	{
		return g_mAppNamePidMap[AppName];
	}
}

void COperatorSystemSpiImpl::GetStatInfo(void)
{
	static char format[] = "%2u %2u %4u %4u %5u %5u %4u %4u %2.2f %2.2f %2.2f %2.2f %2.2f\n";
	static unsigned int tog = 0;
	static unsigned long kb_per_page = sysconf(_SC_PAGESIZE) / 1024ul;
	static jiff dEbt = 0;
	static time_t tOrigTime = 0;
	static time_t tCurrTime = 0;
	static time_t delta_time = 0;

	if (tOrigTime == 0)
	{
		tOrigTime = atoll(GetFirstLine("/proc/uptime"));
	}
	else
	{
		tCurrTime = atoll(GetFirstLine("/proc/uptime"));
		delta_time = tCurrTime - tOrigTime;
		tOrigTime = delta_time > 0 ? tCurrTime : tOrigTime;
	}

	if (tog == 0 && delta_time == 0)
	{
		GetStat(&m_stat_info[tog % 2]);
		GetVMStat(&m_stat_info[tog % 2]);
		tog++;
	}
	else if (tog > 0 && delta_time > 0)
	{
		GetStat(&m_stat_info[tog % 2]);
		GetVMStat(&m_stat_info[tog % 2]);

		// not first time
		jiff dTotal =
			(
				(
					m_stat_info[tog % 2].cpu_user +
					m_stat_info[tog % 2].cpu_nice +
					m_stat_info[tog % 2].cpu_system +
					m_stat_info[tog % 2].cpu_idle +
					m_stat_info[tog % 2].cpu_iowait +
					m_stat_info[tog % 2].cpu_irq +
					m_stat_info[tog % 2].cpu_sirq +
					m_stat_info[tog % 2].cpu_steal
				) -
				(
					m_stat_info[(tog - 1) % 2].cpu_user +
					m_stat_info[(tog - 1) % 2].cpu_nice +
					m_stat_info[(tog - 1) % 2].cpu_system +
					m_stat_info[(tog - 1) % 2].cpu_idle +
					m_stat_info[(tog - 1) % 2].cpu_iowait +
					m_stat_info[(tog - 1) % 2].cpu_irq +
					m_stat_info[(tog - 1) % 2].cpu_sirq +
					m_stat_info[(tog - 1) % 2].cpu_steal
				)
			);
		jiff dUse =
			(
				m_stat_info[tog % 2].cpu_user +
				m_stat_info[tog % 2].cpu_nice
			) -
			(
				m_stat_info[(tog - 1) % 2].cpu_user +
				m_stat_info[(tog - 1) % 2].cpu_nice
			);
		jiff dSys =
			(
				m_stat_info[tog % 2].cpu_system +
				m_stat_info[tog % 2].cpu_sirq +
				m_stat_info[tog % 2].cpu_steal
			) -
			(
				m_stat_info[(tog - 1) % 2].cpu_system +
				m_stat_info[(tog - 1) % 2].cpu_sirq +
				m_stat_info[(tog - 1) % 2].cpu_steal
			);
		jiff dIdl = m_stat_info[tog % 2].cpu_idle -
			m_stat_info[(tog - 1) % 2].cpu_idle;
		jiff dIow = m_stat_info[tog % 2].cpu_iowait -
			m_stat_info[(tog - 1) % 2].cpu_iowait;
		jiff dStl = m_stat_info[tog % 2].cpu_steal -
			m_stat_info[(tog - 1) % 2].cpu_steal;

#if 0
		unsigned long delta_time = 0;
		if (g_nCPU > 0)
		{
			delta_time = dTotal / g_nCPU / HZ;
		}
		else
		{
			delta_time = 5;
		}

#endif
		m_pkgSend.PreparePackage(
				FTD_TID_RtnStatInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnStatInfoField field;
		sprintf(m_mObjectId, "%s.statinfo", m_mObjectName);
		field.HostName = m_mObjectId;
		field.MonTime = m_mTime;
		field.MonDate = m_mDate;
		field.ProcRun = (unsigned)m_stat_info[tog % 2].proc_run;
		field.ProcBlk = (unsigned)m_stat_info[tog % 2].proc_blk;
		field.SwapIn = (unsigned)
			(
				delta_time / 2 + m_stat_info[tog % 2].swap_in - m_stat_info[
					(tog - 1) % 2].swap_in
			) / delta_time;
		field.SwapOut = (unsigned)
			(
				delta_time / 2 + m_stat_info[tog % 2].swap_out - m_stat_info[
					(tog - 1) % 2].swap_out
			) / delta_time;
		field.BlockIn = (unsigned)
			(
				delta_time / 2 + m_stat_info[tog % 2].page_in - m_stat_info[
					(tog - 1) % 2].page_in
			) / delta_time;
		field.BlockOut = (unsigned)
			(
				delta_time / 2 + m_stat_info[tog % 2].page_out - m_stat_info[
					(tog - 1) % 2].page_out
			) / delta_time;
		field.Inter = (unsigned)
			(
				delta_time /
				2 +
				m_stat_info[tog % 2].intr -
				m_stat_info[(tog - 1) % 2].intr
			) / delta_time;
		field.Context = (unsigned)
			(
				delta_time /
				2 +
				m_stat_info[tog % 2].ctxt -
				m_stat_info[(tog - 1) % 2].ctxt
			) / delta_time;
		if (dTotal > 0)
		{
			field.CPUUser = (100.0 * dUse) / dTotal;
			field.CPUSys = (100.0 * dSys) / dTotal;
			field.CPUIdle = (100.0 * dIdl) / dTotal;
			field.CPUIOWait = (100.0 * dIow) / dTotal;
			field.CPUSteal = (100.0 * dStl) / dTotal;
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		OSSENDPACKAGETO;

		/// 记录主机性能指标对象
		m_cObjectAttr.ObjectID = m_mObjectName;
		m_cObjectAttr.ValueType = INT_ATTR;

		m_cObjectAttr.AttrType = OSATTRDEVINTER;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%d",
			field.Inter.getValue());
		m_ObjectAttrList.add(m_cObjectAttr);

		m_cObjectAttr.AttrType = OSATTRDEVCONTEXT;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%d",
			field.Context.getValue());
		m_ObjectAttrList.add(m_cObjectAttr);

#ifdef PRINT_DEBUG
		printf("procs ---swap-- -----io---- -system-- -----cpu-----\n");
		printf(
			"%2s %2s %4s %4s %5s %5s %4s %4s %2s %2s %2s %2s %2s\n",
			"r",
			"b",
			"si",
			"so",
			"bi",
			"bo",
			"in",
			"cs",
			"us",
			"sy",
			"id",
			"wa",
			"st");
		printf(
			format,
			(unsigned)m_stat_info[tog % 2].proc_run,
			(unsigned)m_stat_info[tog % 2].proc_blk,
			(unsigned)
				(
					delta_time /
					2 +
					m_stat_info[tog % 2].swap_in -
					m_stat_info[(tog - 1) % 2].swap_in
				) / delta_time,				/*si*/
			(unsigned)
				(
					delta_time /
					2 +
					m_stat_info[tog % 2].swap_out -
					m_stat_info[(tog - 1) % 2].swap_out
				) / delta_time,				/*so*/
			(unsigned)
				(
					delta_time /
					2 +
					m_stat_info[tog % 2].page_in -
					m_stat_info[(tog - 1) % 2].page_in
				) / delta_time,				/*bi*/
			(unsigned)
				(
					delta_time /
					2 +
					m_stat_info[tog % 2].page_out -
					m_stat_info[(tog - 1) % 2].page_out
				) / delta_time,				/*bo*/
			(unsigned)
				(
					delta_time / 2 + m_stat_info[tog % 2].intr - m_stat_info[
						(tog - 1) % 2].intr
				) / delta_time,				/*in*/
			(unsigned)
				(
					delta_time / 2 + m_stat_info[tog % 2].ctxt - m_stat_info[
						(tog - 1) % 2].ctxt
				) / delta_time,				/*cs*/
			(100.0 * dUse) / dTotal,		/*us*/
			(100.0 * dSys) / dTotal,		/*sy*/
			(100.0 * dIdl) / dTotal,		/*id*/
			(100.0 * dIow) / dTotal,		/*iw*/
			(100.0 * dStl) / dTotal			/*st*/
			   );
#endif
		tog++;
	}
}

int COperatorSystemSpiImpl::GetDiskStats(void)
{
	char szFileName[] = "/proc/diskstats";
	char *p = NULL;
	int iRtn;
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_BUF_SIZE];
	int iCount = 0;
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf) - 1] = 0x00;	// 除去行尾换行符

		// printf("BUF[%s]\n", szBuf);
		st_part_info curr;
		st_blkio_info blkio;

		int items = sscanf(
				szBuf,
				"%4d %4d %*s %u %u %llu %u %u %u %llu %u %*u %u %u",
				&curr.major,
				&curr.minor,
				&blkio.rd_ios,
				&blkio.rd_merges,
				&blkio.rd_sectors,
				&blkio.rd_ticks,
				&blkio.wr_ios,
				&blkio.wr_merges,
				&blkio.wr_sectors,
				&blkio.wr_ticks,
				&blkio.ticks,
				&blkio.aveq);
		if (items == 6)
		{
			blkio.rd_sectors = blkio.rd_merges;
			blkio.wr_sectors = blkio.rd_ticks;
			blkio.rd_ios = 0;
			blkio.rd_merges = 0;
			blkio.rd_ticks = 0;
			blkio.wr_ios = 0;
			blkio.wr_merges = 0;
			blkio.wr_ticks = 0;
			blkio.ticks = 0;
			blkio.aveq = 0;
			items = 12;
		}

		if (items == 12)
		{
			for (int i = 0; i < g_nPartitions; i++)
			{
				if (g_partitions[i].major == curr.major
				&&	g_partitions[i].minor == curr.minor)
				{
					g_blkio_new[i] = blkio;
					break;
				}
			}
		}
	}

	fclose(fpSrc);
	return g_nPartitions;
}

char *COperatorSystemSpiImpl::GetFirstLine(const char *pFileName)
{
	FILE *fpSrc;
	if (!(fpSrc = fopen(pFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", pFileName);
		fflush(stdout);
		return -1;
	}

	char szBuf[MAX_BUF_SIZE];
	*szBuf = 0x00;
	fgets(szBuf, sizeof(szBuf), fpSrc);
	if (szBuf[strlen(szBuf) - 1] == '\n')
	{
		szBuf[strlen(szBuf) - 1] = 0x00;
	}

	fclose(fpSrc);
	return szBuf;
}

void COperatorSystemSpiImpl::GetSysCore(void)
{
	m_cObjectAttr.ObjectID = m_mObjectName;
	m_cObjectAttr.ValueType = STRING_ATTR;

	m_cObjectAttr.AttrType = OSATTRFSAIOMAX;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%lld",
		atol(GetFirstLine("/proc/sys/fs/aio-max-nr")));
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRFSAIONR;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%lld",
		atol(GetFirstLine("/proc/sys/fs/aio-nr")));
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRFILEMAX;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%lld",
		atol(GetFirstLine("/proc/sys/fs/file-max")));
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRFILENR;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%lld",
		atol(GetFirstLine("/proc/sys/fs/file-nr")));
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRSHMALL;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%lld",
		atol(GetFirstLine("/proc/sys/kernel/shmall")));
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRSHMMAX;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%lld",
		atol(GetFirstLine("/proc/sys/kernel/shmmax")));
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.AttrType = OSATTRSHMMNI;
	sprintf(
		m_cObjectAttr.AttrValue.getValue(),
		"%lld",
		atol(GetFirstLine("/proc/sys/kernel/shmmni")));
	m_ObjectAttrList.add(m_cObjectAttr);
}

void COperatorSystemSpiImpl::SaveOldStatus(void)
{
	for (int i = 0; i < g_nPartitions; i++)
	{
		g_blkio_old[i] = g_blkio_new[i];
	}

	g_cpu_old = g_cpu_new;
}

void COperatorSystemSpiImpl::ComputeIORates(void)
{
	double	deltaMS = 1.0;
	if (g_nCPU > 0)
	{
		deltaMS = 1000.0 *
			(
				(
					g_cpu_new.user +
					g_cpu_new.system +
					g_cpu_new.idle +
					g_cpu_new.iowait
				) -
					(
						g_cpu_old.user +
						g_cpu_old.system +
						g_cpu_old.idle +
						g_cpu_old.iowait
					)
			) / g_nCPU / HZ;
	}
	else
	{
		GetCPUInfo();
		return;
	}

#define PER_SEC(x)	(1000.0 * (x) / deltaMS)
	st_blkio_info blkio;
	double	n_ios;		/* Number of requests */
	double	n_ticks;	/* Total service time */
	double	n_kbytes;	/* Total kbytes transferred */
	double	busy;		/* Utilization at disk	(percent) */
	double	svc_t;		/* Average disk service time */
	double	wait;		/* Average wait */
	double	size;		/* Average request size */
	double	queue;		/* Average queue */

	double	n_rkbytes = 0;
	double	n_wkbytes = 0;
	double	maxbusy = 0;

#ifdef PRINT_DEBUG
	printf(
		"\n------------------------------------------------------------------------------\n"
		"device mgr/s mgw/s    r/s    w/s    kr/s    "
		"kw/s   size queue   wait svc_t  %%b\n");
#endif
	m_pkgSend.PreparePackage(
			FTD_TID_RtnDiskIOTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnDiskIOField	field;
	sprintf(m_mObjectId, "%s.diskio", m_mObjectName);
	field.HostName = m_mObjectId;
	field.MonTime = m_mTime;
	field.MonDate = m_mDate;
	for (int i = 0; i < g_nPartitions; i++)
	{
		blkio.rd_ios = g_blkio_new[i].rd_ios - g_blkio_old[i].rd_ios;
		blkio.rd_merges = g_blkio_new[i].rd_merges - g_blkio_old[i].rd_merges;
		blkio.rd_sectors = g_blkio_new[i].rd_sectors - g_blkio_old[i].rd_sectors;
		blkio.rd_ticks = g_blkio_new[i].rd_ticks - g_blkio_old[i].rd_ticks;
		blkio.wr_ios = g_blkio_new[i].wr_ios - g_blkio_old[i].wr_ios;
		blkio.wr_merges = g_blkio_new[i].wr_merges - g_blkio_old[i].wr_merges;
		blkio.wr_sectors = g_blkio_new[i].wr_sectors - g_blkio_old[i].wr_sectors;
		blkio.wr_ticks = g_blkio_new[i].wr_ticks - g_blkio_old[i].wr_ticks;
		blkio.ticks = g_blkio_new[i].ticks - g_blkio_old[i].ticks;
		blkio.aveq = g_blkio_new[i].aveq - g_blkio_old[i].aveq;

		n_ios = blkio.rd_ios + blkio.wr_ios;
		n_ticks = blkio.rd_ticks + blkio.wr_ticks;
		n_kbytes = (blkio.rd_sectors + blkio.wr_sectors) / 2.0;

		queue = blkio.aveq / deltaMS;
		size = n_ios ? n_kbytes / n_ios : 0.0;
		wait = n_ios ? n_ticks / n_ios : 0.0;
		svc_t = n_ios ? blkio.ticks / n_ios : 0.0;
		busy = 100.0 * blkio.ticks / deltaMS;	/* percentage! */
		if (busy > 100.0)
		{
			busy = 100.0;
		}

		maxbusy = maxbusy >= busy ? maxbusy : busy;
		n_rkbytes += PER_SEC(blkio.rd_sectors) / 2.0;
		n_wkbytes += PER_SEC(blkio.wr_sectors) / 2.0;
#ifdef PRINT_DEBUG
		printf(
			"%-6s %5.0f %5.0f %6.1f %6.1f %7.1f ""%7.1f %6.1f %5.1f %6.1f %5.1f %3.0f\n",
			g_partitions[i].name,
			PER_SEC(blkio.rd_merges),
			PER_SEC(blkio.wr_merges),
			PER_SEC(blkio.rd_ios),
			PER_SEC(blkio.wr_ios),
			PER_SEC(blkio.rd_sectors) / 2.0,
			PER_SEC(blkio.wr_sectors) / 2.0,
			size,
			queue,
			wait,
			svc_t,
			busy);
#endif
		sprintf(field.PartName.getValue(), "%s", g_partitions[i].name);
		field.ReadMerges = PER_SEC(blkio.rd_merges);
		field.WriteMerges = PER_SEC(blkio.wr_merges);
		field.ReadIOs = PER_SEC(blkio.rd_ios);
		field.WriteIOs = PER_SEC(blkio.wr_ios);
		field.ReadKBs = PER_SEC(blkio.rd_sectors) / 2.0;
		field.WriteKBs = PER_SEC(blkio.wr_sectors) / 2.0;
		field.SizeVal = size;
		field.QueueVal = queue;
		field.Svc_t = svc_t;
		field.Busy = busy;

		if (m_pkgSend.Length() + sizeof(field) > FTDC_PACKAGE_MAX_SIZE)
		{
			m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
			OSSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnDiskIOTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);
	}

	if (g_nPartitions > 0)
	{
		OSSENDPACKAGETO;
	}

	m_cObjectAttr.ObjectID = m_mObjectName;

	m_cObjectAttr.ValueType = PERCENT_ATTR;
	m_cObjectAttr.AttrType = OSATTRDISKBUSY;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%.2f", maxbusy);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRDISKREADKBS;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%.2f", n_rkbytes);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRDISKWRITEKBS;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%.2f", n_wkbytes);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRDISKIOMBS;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%.2f", (n_rkbytes + n_wkbytes)/ 1024.0);
	m_ObjectAttrList.add(m_cObjectAttr);
}

int COperatorSystemSpiImpl::GetDiskStatus(void)
{
	if (g_nPartitions <= 0 || g_nPartitions > MAX_PARTITIONS)
	{
		g_nPartitions = GetPartitions();
	}

	if (g_nPartitions > 0 && g_nPartitions <= MAX_PARTITIONS)
	{
		SaveOldStatus();
		GetDiskStats();
		GetCPUTime();
		ComputeIORates();
	}
}

#endif
