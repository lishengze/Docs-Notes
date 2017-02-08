/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	OSSpiImpl.cpp
///@brief	实现了探针获取主机系统相关信息的类和函数
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
///20090302	晏鹤春		修正Linux探针进程信息采样的CPU利用率计算方法
///20090302	晏鹤春		修正Linux探针主机环境信息的获取方法
///20090428 晏鹤春		强制设定CPU编号为连续数列0,1,2,...N
///20090512 晏鹤春		修改HP_UX下CPU状态判定及其编号获取方式
#include "public.h"
#include "OSSpiImpl.h"
#include "SyslogSpiImpl.h"

map<string, long> g_mAppNamePidMap;				// 应用进程名 - 应用进程的ID
map<string, long> g_mAppStatus;					// 应用进程名 - 状态码
extern map<string, string>	g_mSpcPrcMap;		// 应用进程名 - 进程所在分区 映射图
extern char *g_szHostEnvFile;					// 主机环境配置文件名
extern char *g_szNetConfFile;					// 网络配置文件名
extern char g_pHostName[32];					// 保存主机名称
extern char g_pDataCenterName[32];				// 保存数据中心名称
extern CManageConSession g_mManageConSession;	// 保存所有连接的地址信息
extern bool g_sendEvnFlag;

COperatorSystemSpiImpl::COperatorSystemSpiImpl(CCachedFileFlow *pFlow)
	: m_lastGetNetInfoTime(0), m_lastRecvByte(0), m_lastRecvPkt(0),
	m_lastSendByte(0), m_lastSendPkt(0)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	m_mMemory = 0;
	m_mPageSize = 0;
	m_mCpuNum = 0;
	m_mFSNum = 0;
	m_pFlow = pFlow;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	
	SetObjectName(g_pDataCenterName, g_pHostName);

	memset(m_sCPUs, 0, sizeof(sCpuInfo) * MAX_CPUNUM);
	memset(m_cCpuInfo, 0, sizeof(CFTDRtnTopCpuInfoField) * MAX_CPUNUM);
	memset(&m_cMemInfo, 0, sizeof(CFTDRtnTopMemInfoField));
	memset(&m_cFSInfo, 0, sizeof(CFTDRtnFileSystemInfoField));
	memset(&m_cUserInfo, 0, sizeof(CFTDRtnUserInfoField));
	memset(&m_cOnlineUser, 0, sizeof(CFTDRtnOnlineUserInfoField));

#ifdef HP_UX
	m_mMemory = 4083;
	m_pProcessor = NULL;
	m_pListHead = NULL;
	m_pListTail = NULL;
	ReadPasswd();			// 读取用户信息数据并建立信息映射图
	ReadGroup();			// 读取用户组信息数据并建立信息映射图
#elif defined LINUX
	ReadPasswd();			// 读取用户信息数据并建立信息映射图
	ReadGroup();			// 读取用户组信息数据并建立信息映射图
#elif defined WINDOWS
#endif
}

COperatorSystemSpiImpl::~COperatorSystemSpiImpl(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
#ifdef HP_UX
	DropProcList();			// 释放进程链表
	if (m_pProcessor != NULL)
	{						// 释放CPU信息组
		free(m_pProcessor);
	}

#endif
}

void COperatorSystemSpiImpl::SetObjectName(const char *pszCenterName,const char *pszHost)
{
	sprintf(
		m_mObjectName,
		"%s.%s.%s",
		pszCenterName,
		DATACENTERHOST,
		pszHost);
	sprintf(m_mAppName, "%s.%s", pszCenterName, DATACENTERAPP);

	printf("Set ObjectName[%s]\n", m_mObjectName);
}

void COperatorSystemSpiImpl::GetHostActiveSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	m_cObjectAttr.ObjectID = m_mObjectName;
	m_cObjectAttr.AttrType = OSATTRACITVE;
	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrValue = "1";
	m_ObjectAttrList.add(m_cObjectAttr);
	/// Added by Henchi, 20160301
	/// 为确保变更正常过渡，Active/Alive同时产生
	m_cObjectAttr.AttrType = OSATTRALIVE;
	m_ObjectAttrList.add(m_cObjectAttr);
}

void COperatorSystemSpiImpl::GetcpuSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif

	m_pkgSend.PreparePackage(
			FTD_TID_RtnTopCpuInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	TIME_MEASURE_START(__FUNCTION__);
	if (GetCPU())
	{
		for (int i = 0; i <= m_mCpuNum; i++)
		{
			sprintf(
				m_mObjectId,
				"%s.%s.%s",
				m_mObjectName,
				HOSTATTRCPU,
				m_cCpuInfo[i].CPU.getValue());
			m_cCpuInfo[i].MonDate = m_mDate;
			m_cCpuInfo[i].MonTime = m_mTime;
			m_cCpuInfo[i].HostName = m_mObjectId;

			// Added by Henchi 20090708
			// 主机CPU个数可能大于32个...
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnTopCpuInfoField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				OSSENDPACKAGETO;
				m_pkgSend.PreparePackage(
						FTD_TID_RtnTopCpuInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &m_cCpuInfo[i]);
		}
	}

	TIME_MEASURE_END(__FUNCTION__);

#ifdef PRINT_DEBUG
	printf("PacketSend Type: TopCpuInfo    length: %d \n", m_pkgSend.Length());
#endif
	OSSENDPACKAGETO;
}

void COperatorSystemSpiImpl::GetmemSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	m_pkgSend.PreparePackage(
			FTD_TID_RtnTopMemInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	TIME_MEASURE_START(__FUNCTION__);

	if (GetMemory())
	{
		// 采集内存指标
		m_cObjectAttr.ObjectID = m_mObjectName;
		m_cObjectAttr.ValueType = PERCENT_ATTR;

		m_cObjectAttr.AttrType = OSATTRMEMORYUSAGE;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%.2f",
			(m_cMemInfo.TOTALREAL > 0) ? (100.0 * m_cMemInfo.ACTIVEREAL / m_cMemInfo.TOTALREAL) : 0);	// modify by cao.ning, 虚拟机中可能取值为0
		m_ObjectAttrList.add(m_cObjectAttr);

		/// Added by Henchi, 20141021
		/// 主机内存空闲率 = 100.0 * (free + buffer + cache) / total %
		m_cObjectAttr.AttrType = OSATTRMEMORYFREEUSAGE;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%.2f",
			(m_cMemInfo.TOTALREAL > 0) ? (100.0 * m_cMemInfo.FREE / m_cMemInfo.TOTALREAL) : 0);	
		m_ObjectAttrList.add(m_cObjectAttr);

		m_cObjectAttr.AttrType = OSATTRSWAPUSAGE;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%.2f",
			(m_cMemInfo.TOTALVIRTUAL > 0) ? (100.0 * m_cMemInfo.ACTIVEVIRTUAL / m_cMemInfo.TOTALVIRTUAL) : 0);	// modify by cao.ning, 虚拟机中可能取值为0
		m_ObjectAttrList.add(m_cObjectAttr);

		sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRMEM);
		m_cMemInfo.HostName = m_mObjectId;
		m_cMemInfo.MonDate = m_mDate;
		m_cMemInfo.MonTime = m_mTime;

		// 取内存信息成功，把信息添加到流中
		FTDC_ADD_FIELD(&m_pkgSend, &m_cMemInfo);
	}

	TIME_MEASURE_END(__FUNCTION__);
#ifdef PRINT_DEBUG
	printf(
		"PacketSend Type: TopMemoryInfo    length: %d \n",
		m_pkgSend.Length());
#endif
	OSSENDPACKAGETO;
}

void COperatorSystemSpiImpl::GetprocessSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif

	m_lSpcProc.clear();

	GetProcessInfo();
	
#if defined HP_UX || defined LINUX || defined WIN32
	m_cObjectAttr.AttrType = APPATTRACTIVE;
	m_cObjectAttr.ValueType = INT_ATTR;

	TIME_MEASURE_START(__FUNCTION__);

	std::map<std::string, std::string>::iterator MapIt;

	for (MapIt = g_mSpcPrcMap.begin(); MapIt != g_mSpcPrcMap.end(); MapIt++)
	{
		sprintf(
			(char *)m_cObjectAttr.ObjectID.getValue(),
			"%s.%s",
			m_mAppName,
			MapIt->first.c_str());

		if (find(m_lSpcProc.begin(), m_lSpcProc.end(), MapIt->first) != m_lSpcProc.end())
		{
			m_cObjectAttr.AttrValue = "1";

#ifdef APP_STATUS_EVENT
			g_mAppStatus[(MapIt->first)] = 1;
#endif
		}
		else
		{
			m_cObjectAttr.AttrValue = "0";

#ifdef APP_STATUS_EVENT
			if ((g_mAppStatus[(MapIt->first)] == 1))
			{
				g_mAppStatus[(MapIt->first)] = 0;

				CFTDCPackage eventPkg;
				eventPkg.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
				eventPkg.PreparePackage(
						FTD_TID_RtnWarningEventTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);

				CFTDRtnWarningEventField fieldInfo;
				memset(&fieldInfo, 0, sizeof(fieldInfo));
				fieldInfo.MonDate = m_mDate;
				fieldInfo.MonTime = m_mTime;
				fieldInfo.Time = m_mTime;
				fieldInfo.EventName = "AppStatusInvalid";
				fieldInfo.ObjectID = m_cObjectAttr.ObjectID;
				fieldInfo.EvendID = 0;
				fieldInfo.EventNum = 0;
				fieldInfo.ProcessFlag = "N";
				fieldInfo.EventDes = "探针未能侦测到该进程";

				//				fieldInfo.WarningLevel = "info";
				FTDC_ADD_FIELD(&eventPkg, &fieldInfo);
				g_mManageConSession.sendFTDCPackage(&eventPkg);
			}
#endif
		}
#ifdef LINUX
		printf("TIME[%s][%s] PROC[%s][%ld][%s]\n", m_mDate, m_mTime, MapIt->first.c_str(), GetAppPid(MapIt->first.c_str()), (char *)m_cObjectAttr.AttrValue.getValue());
#endif
		m_ObjectAttrList.add(m_cObjectAttr);
	}

	TIME_MEASURE_END(__FUNCTION__);

#else
#endif
	
#if defined LINUX || defined WIN32
	GetUptime();
#endif

}

void COperatorSystemSpiImpl::GetfsSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	TIME_MEASURE_START(__FUNCTION__);
	GetDisk();
	TIME_MEASURE_END(__FUNCTION__);
}

void COperatorSystemSpiImpl::GetnetworkSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif

	///2008.08.15 change by Solomon Wu
	//GetNetwork();		// 取网络流量信息并打包发送到流中
#if 0						// 20090313 change by zhou.jj
#ifdef HP_UX
	GetenvSpi();			// 由主机环境信息初始化网卡列表
#endif
#endif
	TIME_MEASURE_START(__FUNCTION__);
	NewGetNetwork();
	TIME_MEASURE_END(__FUNCTION__);
}

void COperatorSystemSpiImpl::GetnetstatSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif

#if defined LINUX
	TIME_MEASURE_START(__FUNCTION__);
	GetNetStat();
	TIME_MEASURE_END(__FUNCTION__);
#endif
}

void COperatorSystemSpiImpl::GetuserSpi(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	TIME_MEASURE_START(__FUNCTION__);

	GetAllUsers();			// 取当前所有注册用户并打包发送到流中
	GetLoggedUsers();		// 取当前所有登录用户并打包发送到流中
	TIME_MEASURE_END(__FUNCTION__);
}

void COperatorSystemSpiImpl::GetstatinfoSpi(void)
{
#ifdef LINUX
	GetStatInfo();
#endif
}

void COperatorSystemSpiImpl::GetdiskioSpi(void)
{
#ifdef LINUX
	GetDiskStatus();
#endif
}

void COperatorSystemSpiImpl::GetrouterSpi(void)
{
#if defined WIN32 || defined LINUX
	GetRoute();
#endif
}

void COperatorSystemSpiImpl::GetkernelSpi(void)
{
#ifdef LINUX
	GetSysCore();
#endif
}

bool COperatorSystemSpiImpl::GetSpi(CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	TIME_MEASURE_START(__FUNCTION__);

	GetDateTime();
	GetMemory();
	GetCPU();
	GetNetCardInfo();
#ifdef LINUX
	GetDisk();
	ScanSwaps();
#endif
	GetenvSpi(pSession);
	TIME_MEASURE_END(__FUNCTION__);

	return true;
}

void COperatorSystemSpiImpl::ShowHostEnv(void)
{
	int iCount;

	printf(
		"ObjectID:%s\nMonDate:%s\nMonTime:%s\nHostModel :%s\nMainMemory:%ld\nProcessors:%ld\nOsMode    :%ld\n",
		(const char *)m_cCommon.HostName,
		(const char *)m_cCommon.MonDate,
		(const char *)m_cCommon.MonTime,
		(const char *)m_cCommon.HostModel,
		(const long)m_cCommon.MainMemory,
		(const long)m_cCommon.Processors,
		(const long)m_cCommon.OsMode);

	printf("\n%d Lan Hardwares:\n", m_iLan);
	for (iCount = 0; iCount < m_iLan; iCount++)
	{
		printf(
			"%02d:  %s    %s\n",
			iCount + 1,
			(const char *)m_cLan[iCount].LanHardwareID,
			(const char *)m_cLan[iCount].LanHardwareValue);
	}

	printf("\n%d Storage Devices:\n", m_iStorage);
	for (iCount = 0; iCount < m_iStorage; iCount++)
	{
		printf(
			"%02d:  %-30s%-15s%-30s\n",
			iCount + 1,
			(const char *)m_cStorage[iCount].StorageDev,
			(const char *)m_cStorage[iCount].HWPath,
			(const char *)m_cStorage[iCount].Interface);
	}

	printf("\n%d I/O Interfaces:\n", m_iIO);
	for (iCount = 0; iCount < m_iIO; iCount++)
	{
		printf(
			"%02d:  %-10s%-10s%-15s%-40s\n",
			iCount + 1,
			(const char *)m_cIO[iCount].IoClass,
			(const char *)m_cIO[iCount].H_WPath,
			(const char *)m_cIO[iCount].IoDriver,
			(const char *)m_cIO[iCount].IoDescription);
	}

	printf("\n%d File Systems:\n", m_iFS);
	for (iCount = 0; iCount < m_iFS; iCount++)
	{
		printf(
			"%02d:  %-30s%-15s%-10ld%-15s\n",
			iCount + 1,
			(const char *)m_cFS[iCount].LVMDeviceFile,
			(const char *)m_cFS[iCount].MountPoint,
			(const long)m_cFS[iCount].FSsize,
			(const char *)m_cFS[iCount].FSType);
	}

	printf("\n%d Swap Partitions:\n", m_iSwap);
	for (iCount = 0; iCount < m_iSwap; iCount++)
	{
		printf(
			"%02d:  %-10s%-10ld%-10ld%-40s\n",
			iCount + 1,
			(const char *)m_cSwap[iCount].type,
			(const long)m_cSwap[iCount].size,
			(const long)m_cSwap[iCount].priority,
			(const char *)m_cSwap[iCount].location);
	}

	for (iCount = 0; iCount < m_iLanCfg; iCount++)
	{
		printf(
			"\n\nLanName   :%s\nIP-Address:%s\nSubnetMask:%s\n",
			(const char *)m_cLanCfg[iCount].LanName,
			(const char *)m_cLanCfg[iCount].IpAddress,
			(const char *)m_cLanCfg[iCount].IpMask);
	}

	fflush(stdout);
}

#if defined HP_UX || defined LINUX
bool COperatorSystemSpiImpl::GetCPU(void)
{
	static INT64 prevTotalTime[MAX_CPUNUM];
	static sCpuInfo prevCPUs[MAX_CPUNUM];
	static int	iMaxActCpus = 0;

	//Add by Henchi
	INT64 absTotalTime;
	double	dTotalLoad = 0;
	double	dTotalUser = 0;
	double	dTotalNice = 0;
	double	dTotalSys = 0;
	double	dTotalIdle = 0;
	double	dTotalBlock = 0;
	double	dTotalSwait = 0;
	double	dTotalInter = 0;
	double	dTotalSsys = 0;
	double	dMinIdle = 100.0;
	unsigned int uBusyCore = 0;

#ifdef HP_UX
	if (m_mCpuNum <= 0 || iMaxActCpus <= 0)
	{
		pst_dynamic psd;
		if (pstat_getdynamic(&psd, sizeof(psd), (size_t) 1, 0) != -1)
		{
			m_mCpuNum = psd.psd_proc_cnt;
			iMaxActCpus = psd.psd_max_proc_cnt;
		}
		else
		{
			return false;
		}
	}

	if (m_pProcessor == NULL && iMaxActCpus > 0)
	{
		m_pProcessor = (struct pst_processor *)malloc(
				iMaxActCpus * sizeof(pst_processor));
	}

	if (pstat_getprocessor(
			m_pProcessor,
		sizeof(pst_processor),
		iMaxActCpus,
		0) != -1)
#elif defined LINUX
		if ((m_mCpuNum = GetProcessor(m_pProcessor)) != -1)
#endif

		//if GetCpuInfo succeed...
		{
			int iCount = 0;

#ifdef HP_UX
			for (int i = 0; i < iMaxActCpus && iCount < m_mCpuNum; ++i)
#elif defined LINUX
				for (int i = 0; iCount < m_mCpuNum; ++i)
#endif

				// for()
				{
#ifdef HP_UX
					// Add by Henchi 20090512
					if (m_pProcessor[i].psp_processor_state != 1)
					{
						continue;
					}

#endif

					// Mod by Henchi, 20090428
					// sprintf((char *)&m_cCpuInfo[i].CPU, "%ld", m_pProcessor[i].psp_idx);
					// 强制设定CPU编号为0,1,2,...N
					sprintf((char *) &m_cCpuInfo[iCount].CPU, "%d", iCount);

					/* Add by Henchi */
					prevCPUs[iCount] = m_sCPUs[iCount];
					m_sCPUs[iCount].User = m_pProcessor[i].psp_cpu_time[CP_USER];
					m_sCPUs[iCount].Nice = m_pProcessor[i].psp_cpu_time[CP_NICE];
					m_sCPUs[iCount].Sys = m_pProcessor[i].psp_cpu_time[CP_SYS];
					m_sCPUs[iCount].Idle = m_pProcessor[i].psp_cpu_time[CP_IDLE];
					m_sCPUs[iCount].Block = m_pProcessor[i].psp_cpu_time[CP_BLOCK];
					m_sCPUs[iCount].Swait = m_pProcessor[i].psp_cpu_time[CP_SWAIT];
					m_sCPUs[iCount].Inter = m_pProcessor[i].psp_cpu_time[CP_INTR];
					m_sCPUs[iCount].Ssys = m_pProcessor[i].psp_cpu_time[CP_SSYS];

					prevTotalTime[iCount] = m_mTotalTime[iCount];
					m_mTotalTime[iCount] = m_sCPUs[iCount].User +
						m_sCPUs[iCount].Nice +
						m_sCPUs[iCount].Sys +
						m_sCPUs[iCount].Idle +
						m_sCPUs[iCount].Block +
						m_sCPUs[iCount].Swait +
						m_sCPUs[iCount].Inter +
						m_sCPUs[iCount].Ssys;

					absTotalTime =
						(
							m_mTotalTime[iCount] -
							prevTotalTime[iCount]
						);

					m_cCpuInfo[iCount].LOAD = m_pProcessor[i].psp_avg_1_min;
					if (absTotalTime != 0)
					{
						m_cCpuInfo[iCount].USER = (double)
							(
								(m_sCPUs[iCount].User - prevCPUs[iCount].User) *
								100.0 /
								absTotalTime
							);
						m_cCpuInfo[iCount].NICE = (double)
							(
								(m_sCPUs[iCount].Nice - prevCPUs[iCount].Nice) *
								100.0 /
								absTotalTime
							);
						m_cCpuInfo[iCount].SYS = (double)
							(
								(m_sCPUs[iCount].Sys - prevCPUs[iCount].Sys) *
								100.0 /
								absTotalTime
							);
						m_cCpuInfo[iCount].BLOCK = (double)
							(
								(m_sCPUs[iCount].Block - prevCPUs[iCount].Block) *
								100.0 /
								absTotalTime
							);
						m_cCpuInfo[iCount].SWAIT = (double)
							(
								(m_sCPUs[iCount].Swait - prevCPUs[iCount].Swait) *
								100.0 /
								absTotalTime
							);
						m_cCpuInfo[iCount].INTR = (double)
							(
								(m_sCPUs[iCount].Inter - prevCPUs[iCount].Inter) *
								100.0 /
								absTotalTime
							);
						m_cCpuInfo[iCount].SSYS = (double)
							(
								(m_sCPUs[iCount].Ssys - prevCPUs[iCount].Ssys) *
								100.0 /
								absTotalTime
							);
						m_cCpuInfo[iCount].IDLE = (double)
							(
								(m_sCPUs[iCount].Idle - prevCPUs[iCount].Idle) *
								100.0 /
								absTotalTime
							);
					}
					else
					{
						m_cCpuInfo[iCount].USER = (double)0;
						m_cCpuInfo[iCount].NICE = (double)0;
						m_cCpuInfo[iCount].SYS = (double)0;
						m_cCpuInfo[iCount].BLOCK = (double)0;
						m_cCpuInfo[iCount].SWAIT = (double)0;
						m_cCpuInfo[iCount].INTR = (double)0;
						m_cCpuInfo[iCount].SSYS = (double)0;
						m_cCpuInfo[iCount].IDLE = (double)100;
					}

					dTotalLoad += (const double)m_cCpuInfo[iCount].LOAD;
					dTotalUser += (const double)m_cCpuInfo[iCount].USER;
					dTotalNice += (const double)m_cCpuInfo[iCount].NICE;
					dTotalSys += (const double)m_cCpuInfo[iCount].SYS;
					dTotalBlock += (const double)m_cCpuInfo[iCount].BLOCK;
					dTotalSwait += (const double)m_cCpuInfo[iCount].SWAIT;
					dTotalInter += (const double)m_cCpuInfo[iCount].INTR;
					dTotalSsys += (const double)m_cCpuInfo[iCount].SSYS;
					dTotalIdle += (const double)m_cCpuInfo[iCount].IDLE;

					if (dMinIdle > (const double)m_cCpuInfo[iCount].IDLE)
					{
						dMinIdle = (const double)m_cCpuInfo[iCount].IDLE;
						uBusyCore = iCount;
					}

					// Add by Henchi 20090512
					iCount++;
				}

			if (iCount > 0) // 计算所有CPU的平均值
			{
				m_cCpuInfo[iCount].CPU = "avg";
				m_cCpuInfo[iCount].LOAD = dTotalLoad / iCount;
				m_cCpuInfo[iCount].USER = dTotalUser / iCount;
				m_cCpuInfo[iCount].NICE = dTotalNice / iCount;
				m_cCpuInfo[iCount].SYS = dTotalSys / iCount;
				m_cCpuInfo[iCount].BLOCK = dTotalBlock / iCount;
				m_cCpuInfo[iCount].SWAIT = dTotalSwait / iCount;
				m_cCpuInfo[iCount].INTR = dTotalInter / iCount;
				m_cCpuInfo[iCount].SSYS = dTotalSsys / iCount;
				m_cCpuInfo[iCount].IDLE = dTotalIdle / iCount;
			}

			/// 计算CPU使用率指标
			m_cObjectAttr.ObjectID = m_mObjectName;
			m_cObjectAttr.ValueType = PERCENT_ATTR;

			m_cObjectAttr.AttrType = OSATTRCPUUSAGE;
			sprintf(
				(char *)(m_cObjectAttr.AttrValue.getValue()),
				"%.2f",
				100.00 - m_cCpuInfo[iCount].IDLE);
			m_ObjectAttrList.add(m_cObjectAttr);

			m_cObjectAttr.AttrType = OSATTRMAXCPUUSAGE;
			sprintf(
				(char *)(m_cObjectAttr.AttrValue.getValue()),
				"%.2f",
				100.00 - dMinIdle);
			m_ObjectAttrList.add(m_cObjectAttr);

			m_cObjectAttr.ValueType = INT_ATTR;
			m_cObjectAttr.AttrType = OSATTRCPUBUSYCORE;
			sprintf(
				(char *)(m_cObjectAttr.AttrValue.getValue()),
				"%d",
				uBusyCore);
			m_ObjectAttrList.add(m_cObjectAttr);

#ifdef PRINT_DEBUG
			ShowCPU();
#endif
			return true;
		}					// end if(pstat_getprocessor)

	return false;
}

#endif
void COperatorSystemSpiImpl::ShowCPU(void)
{
	for (int i = 0; i <= m_mCpuNum; i++)
	{
		printf(
			"CPU:%s,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
			(const char *)m_cCpuInfo[i].CPU,
			(const double)m_cCpuInfo[i].LOAD,
			(const double)m_cCpuInfo[i].USER,
			(const double)m_cCpuInfo[i].NICE,
			(const double)m_cCpuInfo[i].SYS,
			(const double)m_cCpuInfo[i].IDLE,
			(const double)m_cCpuInfo[i].BLOCK,
			(const double)m_cCpuInfo[i].SWAIT,
			(const double)m_cCpuInfo[i].INTR,
			(const double)m_cCpuInfo[i].SSYS);
	}
}

void COperatorSystemSpiImpl::SendUpdateSyscfgPkg(
	const char	*pszHost,
	const char	*pszApp)
{
	CFTDCPackage m_mpkgSend;
	m_mpkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_mpkgSend.PreparePackage(
			FTD_TID_RtnUpdateSysConfigTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnUpdateSysConfigField fieldInfo;

	//fieldInfo.UpdateType:主机ID与业务ID映射关系类型
	fieldInfo.UpdateType = UPDATESYSCONFIG_HOSTIDAPPID;

	//fieldInfo.OldValue:保存主机ID，如：PuDian.os.DA-002
	sprintf(
		(char *)fieldInfo.OldValue.getValue(),
		"%s.%s.%s",
		g_pDataCenterName,
		DATACENTERHOST,
		pszHost);

	//fieldInfo.NewValue:保存业务ID，如：PuDian.app.tkernel.1
	sprintf(
		(char *)fieldInfo.NewValue.getValue(),
		"%s.%s.%s",
		g_pDataCenterName,
		DATACENTERAPP,
		pszApp);
	FTDC_ADD_FIELD(&m_mpkgSend, &fieldInfo);

	// SENDPACKAGETOFLOW;
	g_mManageConSession.sendFTDCPackage(&m_mpkgSend);
}

int COperatorSystemSpiImpl::IsSpcProc(char *szUcomm)
{
	std::map<std::string, std::string>::iterator MapIt;

	for (MapIt = g_mSpcPrcMap.begin(); MapIt != g_mSpcPrcMap.end(); MapIt++)
	{
		if (strcmp(szUcomm, (char *)(MapIt->first.c_str())) == 0)
		{
			return 2;
		}
		else if (strncmp(szUcomm, (char *)(MapIt->first.c_str()), strlen(szUcomm)) ==0)
		{
			char *p = (char *)(MapIt->first.c_str()) + strlen(szUcomm);
			if (p != NULL && *p == '.')
			{
				return 1;
			}
		}
	}
	return 0;
}

#if defined HP_UX || defined LINUX
bool COperatorSystemSpiImpl::GetDisk(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	m_cFSInfo.MonDate = m_mDate;
	m_cFSInfo.MonTime = m_mTime;

	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRFS);

	m_cFSInfo.HostName = m_mObjectId;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnFileSystemInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	double maxusage = 0.0;

	//Read Mount Info
	FILE *fpSrc = NULL;
	char sTemp[BLOCK_SIZE], sBuf[BLOCK_SIZE];
#ifdef HP_UX
	char szFileName[] = "/etc/fstab";
	struct statvfs buf;
#elif defined LINUX
	char szFileName[] = "/etc/mtab";
	struct statfs buf;
#endif
	INT64 blocksize;

	if (m_mFSNum == 0)
	{
		CFileOCGuard<> guard(szFileName, "r");
		fpSrc = guard.GetFileHandle();
		if (!fpSrc)
		{
			printf("fopen %s failed %d\n", szFileName);
			return false;
		}

		while (!feof(fpSrc))
		{
			if (fgets(sBuf, BLOCK_SIZE, fpSrc) && sBuf[0] == '/')
			{
				strcpy(sTemp, sBuf);
				strcpy(m_sFSInfo[m_mFSNum].FileSystem, strtok(sTemp, " "));
				strcpy(m_sFSInfo[m_mFSNum].MountOn, strtok(NULL, " "));
				strcpy(m_sFSInfo[m_mFSNum].FSType, strtok(NULL, " "));
				m_mFSNum++;
			}
		}
	}

	//for (int iCount = 0; m_mFSNum > 0 && iCount < m_mFSNum; iCount ++)
	for (int iCount = 0; iCount < m_mFSNum; iCount++)
	{
#ifdef HP_UX
		if (statvfs(m_sFSInfo[iCount].MountOn, &buf) >= 0)
#elif defined LINUX
			if (statfs(m_sFSInfo[iCount].MountOn, &buf) >= 0)
#endif

			// if statfs secceed...
			{
				blocksize = buf.f_frsize;
				m_sFSInfo[iCount].Size = buf.f_blocks * blocksize / (DISK_BASIC_UNIT);
				m_sFSInfo[iCount].Avail = buf.f_bavail * blocksize / (DISK_BASIC_UNIT);
				m_sFSInfo[iCount].Used = m_sFSInfo[iCount].Size - m_sFSInfo[iCount].Avail;
				m_sFSInfo[iCount].pUsed = (m_sFSInfo[iCount].Used * 100.0) / m_sFSInfo[iCount].Size;
				m_sFSInfo[iCount].ISize = buf.f_files;
#ifdef HP_UX
				m_sFSInfo[iCount].IFree = buf.f_favail;
				m_sFSInfo[iCount].IUsed = buf.f_files - buf.f_favail;
#elif defined LINUX
				m_sFSInfo[iCount].IFree = buf.f_ffree;
				m_sFSInfo[iCount].IUsed = buf.f_files - buf.f_ffree;
#endif
				m_sFSInfo[iCount].pIUsed = (m_sFSInfo[iCount].IUsed * 100.0) / m_sFSInfo[iCount].ISize;
				m_cFSInfo.FILESYSTEM = m_sFSInfo[iCount].FileSystem;
				m_cFSInfo.SIZE = m_sFSInfo[iCount].Size;
				m_cFSInfo.USED = m_sFSInfo[iCount].Used;
				m_cFSInfo.AVAIL = m_sFSInfo[iCount].Avail;
				m_cFSInfo.pUSERD = m_sFSInfo[iCount].pUsed;
				m_cFSInfo.ISIZE = m_sFSInfo[iCount].ISize;
				m_cFSInfo.IUSED = m_sFSInfo[iCount].IUsed;
				m_cFSInfo.IFREE = m_sFSInfo[iCount].IFree;
				m_cFSInfo.pIUSED = m_sFSInfo[iCount].pIUsed;
				m_cFSInfo.MountedOn = m_sFSInfo[iCount].MountOn;

				FTDC_ADD_FIELD(&m_pkgSend, &m_cFSInfo);

				if (strcmp(m_sFSInfo[iCount].FileSystem, "/boot") != 0)
				{
					maxusage = maxusage >= m_sFSInfo[iCount].pUsed ? maxusage : m_sFSInfo[iCount].pUsed;
				}

#ifdef PRINT_DEBUG
				printf("----------------------------------------\n");
				printf("FILESYSTEM:%s\n", (const char *)m_cFSInfo.FILESYSTEM);
				printf("DISKTOTAL :%ld Mb\n", (const long)m_cFSInfo.SIZE);
				printf("DISKUSED  :%ld Mb\n", (const long)m_cFSInfo.USED);
				printf("DISKFREE  :%ld Mb\n", (const long)m_cFSInfo.AVAIL);
				printf("DISKUSAGE :%2.4f %%\n", (const float)m_cFSInfo.pUSERD);
				printf("NODETOTAL :%ld\n", (const long)m_cFSInfo.ISIZE);
				printf("NODEUSED  :%ld\n", (const long)m_cFSInfo.IUSED);
				printf("NODEFREE  :%ld\n", (const long)m_cFSInfo.IFREE);
				printf("NODEUSAGE :%2.4f %%\n", (const float)m_cFSInfo.pIUSED);
				printf("MOUNTON   :%s\n", (const char *)m_cFSInfo.MountedOn);
#endif
			}

#ifdef PRINT_DEBUG
		else
		{
			printf(
				"获取文件系统[%s]信息失败[%d]\n",
				m_sFSInfo[iCount].MountOn,
				errno);
		}

#endif
	}

	OSSENDPACKAGETO;

	/// 采集磁盘使用率指标
	m_cObjectAttr.ObjectID = m_mObjectName;
	m_cObjectAttr.ValueType = PERCENT_ATTR;

	m_cObjectAttr.AttrType = OSATTRMAXDISKUSAGE;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%.2f", maxusage);
	m_ObjectAttrList.add(m_cObjectAttr);

	return true;
}

#endif
bool COperatorSystemSpiImpl::GetLoggedUsers(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
#ifdef WIN32
	return false;
#elif defined HP_UX || defined LINUX
	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRUSER);
	m_cOnlineUser.ObjectID = m_mObjectId;
	m_cOnlineUser.MonDate = m_mDate;
	m_cOnlineUser.MonTime = m_mTime;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnOnlineUserInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

#ifdef HP_UX
	struct utmps *pstUTmps;
	setutsent();
	while ((pstUTmps = getutsent(sizeof(struct utmps))))
#elif defined LINUX
		struct utmp current_record, *pstUTmps;
	int utmpfd;
	int reclen = sizeof(current_record);
	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
	{
		perror(UTMP_FILE);
		return false;
	}

	pstUTmps = &current_record;
	while (read(utmpfd, &current_record, reclen) == reclen)
#endif

	//while(getutsent ...)
	{
		if (pstUTmps->ut_type == USER_PROCESS)
		{
			m_cOnlineUser.USERNAME = pstUTmps->ut_user;
			m_cOnlineUser.TTY = pstUTmps->ut_line;
			m_cOnlineUser.PID = pstUTmps->ut_pid;

			long lTime = (long)pstUTmps->ut_tv.tv_sec;
			m_cOnlineUser.TIME = ctime(&lTime) + 4;
			m_cOnlineUser.CONNECTIME = 0;
			if (strlen(pstUTmps->ut_host) == 0
			&&	!strcmp(pstUTmps->ut_line, "console"))
			{
				m_cOnlineUser.IP = "system console";
			}
			else
			{
				m_cOnlineUser.IP = pstUTmps->ut_host;
			}

			if (m_pkgSend.Length() +
				sizeof(CFTDRtnOnlineUserInfoField) > FTDC_PACKAGE_MAX_SIZE)
			{
#ifdef PRINT_DEBUG
				printf(
					"PacketSend Type: OnlineUserInfo  Length: %d \n",
					m_pkgSend.Length());
#endif
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				OSSENDPACKAGETO;
				m_pkgSend.PreparePackage(
						FTD_TID_RtnOnlineUserInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &m_cOnlineUser);

#ifdef PRINT_DEBUG
			printf(
				"OnlineUser: %-8s  %-8s  %8d  %s  %s\n",
				(const char *)m_cOnlineUser.USERNAME,	//User login name
				(const char *)m_cOnlineUser.TTY,		//Device name
				(const int)m_cOnlineUser.PID,			//Process Id
				(const char *)m_cOnlineUser.TIME,		//Logged time
				(const char *)m_cOnlineUser.IP			//Host name, if remote
					   );
#endif
		}
	}	// end of while

#ifdef HP_UX
	endutsent();
#elif defined LINUX
	close(utmpfd);
#endif
#ifdef PRINT_DEBUG
	printf(
		"PacketSend Type: OnlineUserInfo  Length: %d \n",
		m_pkgSend.Length());
#endif
	OSSENDPACKAGETO;
	return true;
#else
	return false;
#endif
}

bool COperatorSystemSpiImpl::GetAllUsers(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
#ifdef WIN32
	return false;
#elif defined HP_UX || defined LINUX
	std::map<int, sUserInfo>::iterator	UserInfoItr;
	if (m_iUserNum == 0 || m_iGroupNum == 0)
	{
		return false;
	}

	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRUSER);
	m_cUserInfo.ObjectID = m_mObjectId;
	m_cUserInfo.MonDate = m_mDate;
	m_cUserInfo.MonTime = m_mTime;

	m_pkgSend.PreparePackage(
			FTD_TID_RtnUserInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	for (UserInfoItr = m_UserInfoMap.begin();
		 UserInfoItr != m_UserInfoMap.end();
		 ++UserInfoItr)
	{
		m_cUserInfo.USERNAME = UserInfoItr->second.UserName;
		m_cUserInfo.USERID = UserInfoItr->second.Uid;
		m_cUserInfo.GROUPNAME = GetGroupName(UserInfoItr->second.Gid).c_str();
		m_cUserInfo.GROUPID = UserInfoItr->second.Gid;
		m_cUserInfo.HOMEPATH = UserInfoItr->second.HomeDir;
		m_cUserInfo.SHELL = UserInfoItr->second.UserShell;

		if (m_pkgSend.Length() +
			sizeof(CFTDRtnUserInfoField) > FTDC_PACKAGE_MAX_SIZE)
		{
#ifdef PRINT_DEBUG
			printf(
				"PacketSend Type: AllUserInfo   Length: %d \n",
				m_pkgSend.Length());
#endif
			m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
			OSSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnUserInfoTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &m_cUserInfo);
#ifdef PRINT_DEBUG
		printf("UserName :%s\n", (const char *)m_cUserInfo.USERNAME);
		printf("UserId   :%d\n", (const int)m_cUserInfo.USERID);
		printf("GroupName:%s\n", (const char *)m_cUserInfo.GROUPNAME);
		printf("GroupId  :%d\n", (const int)m_cUserInfo.GROUPID);
		printf("HomeDir  :%s\n", (const char *)m_cUserInfo.HOMEPATH);
		printf("UserShell:%s\n", (const char *)m_cUserInfo.SHELL);
		printf("------------------------------------------------\n");
#endif
	}

#ifdef PRINT_DEBUG
	printf("PacketSend Type: AllUserInfo   Length: %d \n", m_pkgSend.Length());
#endif
	OSSENDPACKAGETO;
	return true;
#else
	return false;
#endif
}

// 以下为HP_UX和LINUX的共用段
// Mod by Henchi 20081024
#if defined HP_UX || defined LINUX
char *COperatorSystemSpiImpl::SeekChar(char *psSrc, int iChar)
{
	char *p;
	if (NULL == (p = strchr(psSrc, iChar)))
	{
		return NULL;
	}

	while (*++p == BLANK_FLAG)	// 去除目标符号之后出现的空格
	{
	}

	return p;
}

bool COperatorSystemSpiImpl::ReadPasswd(void)
{
	sUserInfo UserInfo;
	struct passwd *pstPW;
	m_iUserNum = 0;
	setpwent();
	while (pstPW = getpwent())
	{
		UserInfo.Uid = pstPW->pw_uid;
		UserInfo.Gid = pstPW->pw_gid;
		strncpy(UserInfo.UserName, pstPW->pw_name, sizeof(UserInfo.UserName));
		strncpy(UserInfo.Password, pstPW->pw_passwd, sizeof(UserInfo.Password));
		strncpy(UserInfo.HomeDir, pstPW->pw_dir, sizeof(UserInfo.HomeDir));
		strncpy(
			UserInfo.UserShell,
			pstPW->pw_shell,
			sizeof(UserInfo.UserShell));
		m_UnameUidMap[(std::string) UserInfo.UserName] = UserInfo.Uid;
		m_UserInfoMap.insert(pair<long, sUserInfo> (UserInfo.Uid, UserInfo));
		memset(&UserInfo, 0x00, sizeof(UserInfo));
		m_iUserNum++;
	}

	endpwent();
	if (m_iUserNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool COperatorSystemSpiImpl::ReadGroup(void)
{
	sGroupInfo GroupInfo;
	struct group *pstGR;
	m_iGroupNum = 0;
	setgrent();
	while (pstGR = getgrent())
	{
		GroupInfo.Gid = pstGR->gr_gid;
		strncpy(
			GroupInfo.GroupName,
			pstGR->gr_name,
			sizeof(GroupInfo.GroupName));
		m_GnameGidMap[(std::string) GroupInfo.GroupName] = GroupInfo.Gid;
		m_GroupInfoMap.insert(
				pair<long, sGroupInfo> (GroupInfo.Gid, GroupInfo));
		memset(&GroupInfo, 0x00, sizeof(GroupInfo));
		m_iGroupNum++;
	}

	endgrent();
	if (m_iGroupNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string COperatorSystemSpiImpl::GetUserName(int nUid)
{
	return m_UserInfoMap[nUid].UserName;
}

std::string COperatorSystemSpiImpl::GetGroupName(int nGid)
{
	return m_GroupInfoMap[nGid].GroupName;
}

int COperatorSystemSpiImpl::GetUid(std::string strUserName)
{
	return m_UnameUidMap[strUserName];
}

int COperatorSystemSpiImpl::GetGid(std::string strGroupName)
{
	return m_GnameGidMap[strGroupName];
}

float COperatorSystemSpiImpl::GetDiskUsage(char *pszPath)
{
	char szPath[BLOCK_SIZE] = "";
#ifdef HP_UX
	struct statvfs buf;
#elif defined LINUX
	struct statfs buf;
#endif
	if (!pszPath)
	{
		return 0;
	}

	if (strlen(pszPath))
	{
		strcpy(szPath, pszPath);
	}
	else
	{
		strcpy(szPath, "/");
	}

#ifdef HP_UX
	if (statvfs(szPath, &buf) >= 0 && buf.f_blocks > 0)
#elif defined LINUX
	if (statfs(szPath, &buf) >= 0 && buf.f_blocks > 0)
#endif

		// if (statfs())
		{
			return ((buf.f_blocks - buf.f_bavail) * 100.0) / buf.f_blocks;
		}

	return 0;
}


bool COperatorSystemSpiImpl::GetDiskUsage(char *pszPath, float & fDiskUsage, float & fInodeUsage)
{
	char szPath[BLOCK_SIZE] = "";
#ifdef HP_UX
	struct statvfs buf;
#elif defined LINUX
	struct statfs buf;
#endif
	if (!pszPath)
	{
		return false;
	}

	if (strlen(pszPath))
	{
		strcpy(szPath, pszPath);
	}
	else
	{
		strcpy(szPath, "/");
	}

#ifdef HP_UX
	if (statvfs(szPath, &buf) >= 0 && buf.f_blocks > 0 && buf.f_files > 0)
#elif defined LINUX
	if (statfs(szPath, &buf) >= 0 && buf.f_blocks > 0 && buf.f_files > 0)
#endif
	
	{
		fDiskUsage = ((buf.f_blocks - buf.f_bavail) * 100.0) / buf.f_blocks;
#ifdef HP_UX
		fInodeUsage = ((buf.f_files - buf.f_favail) * 100.0) / buf.f_files;
#elif defined LINUX
		fInodeUsage = ((buf.f_files - buf.f_ffree) * 100.0) / buf.f_files;
#endif
		return true;
	}

	return false;
}

#endif // end of #if defined HP_UX || defined LINUX

void COperatorSystemSpiImpl::UpdateHostNetFlowInfo()
{
	if (m_lastGetNetInfoTime == 0)
	{
		m_lastGetNetInfoTime = time(NULL);
		m_lastRecvByte = m_lastRecvPkt = m_lastSendByte = m_lastSendPkt = m_lastPhyPkt = 0;

		for (map<string, netinfo>::iterator iterAdapter = m_mapNetInfo.begin();
			iterAdapter != m_mapNetInfo.end();
			++iterAdapter)
		{
			m_lastRecvByte += iterAdapter->second.rcvbytes;
			m_lastRecvPkt += iterAdapter->second.rcvpkgs;
			m_lastSendByte += iterAdapter->second.sndbytes;
			m_lastSendPkt += iterAdapter->second.sndpkgs;
			if (iterAdapter->second.iftype == NetInterface_PHYSICAL)
			{
				m_lastPhyPkt += iterAdapter->second.rcvbytes;
				m_lastPhyPkt += iterAdapter->second.sndbytes;
			}
		}
		return;
	}

	// 计算速率
	time_t nowTime = time(NULL);
	int timeOffset = (int)(nowTime - m_lastGetNetInfoTime);
	if (timeOffset <= 0)
	{
		// 错误，重置为0，再次调用会重新记录报文信息
		m_lastGetNetInfoTime = 0;
		UpdateHostNetFlowInfo();
		return;
	}

	unsigned long long thisRecvByte = 0, thisRecvPkt = 0, thisSendByte = 0, thisSendPkt = 0;
	unsigned long long recvError = 0, recvDrop = 0, sendError = 0, sendDrop = 0;
	unsigned long long thisPhyByte = 0;

	for (map<string, netinfo>::iterator iterAdapter = m_mapNetInfo.begin();
		iterAdapter != m_mapNetInfo.end();
		++iterAdapter)
	{
		thisRecvByte += iterAdapter->second.rcvbytes;
		thisRecvPkt += iterAdapter->second.rcvpkgs;
		thisSendByte += iterAdapter->second.sndbytes;
		thisSendPkt += iterAdapter->second.sndpkgs;
		recvError += iterAdapter->second.rcverrpkgs;
		recvDrop += iterAdapter->second.rcvdrppkgs;
		sendError += iterAdapter->second.snderrpkgs;
		sendDrop += iterAdapter->second.snddrppkgs;
		if (iterAdapter->second.iftype == NetInterface_PHYSICAL)
		{
			thisPhyByte += iterAdapter->second.rcvbytes;
			thisPhyByte += iterAdapter->second.sndbytes;
		}
	}
	
	unsigned long long
		RecvByteSpeed = (thisRecvByte - m_lastRecvByte) / timeOffset,
		RecvPktSpeed = (thisRecvPkt - m_lastRecvPkt) / timeOffset,
		SendByteSpeed = (thisSendByte - m_lastSendByte) / timeOffset,
		SendPktSpeed = (thisSendPkt - m_lastSendPkt) / timeOffset,
		PhyByteSpeed = (thisPhyByte - m_lastPhyPkt) / timeOffset;
	if (RecvByteSpeed < 0 || RecvPktSpeed < 0
		|| SendByteSpeed < 0 || SendPktSpeed < 0
		|| PhyByteSpeed < 0)
	{
		// 错误，重置为0，再次调用会重新记录报文信息
		m_lastGetNetInfoTime = 0;
		UpdateHostNetFlowInfo();
		return;
	}

	m_cObjectAttr.ObjectID = m_mObjectName;

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETRCVBYTESPEED;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", RecvByteSpeed);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETRCVPKTSPEED;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", RecvPktSpeed);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETSNDBYTESPEED;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", SendByteSpeed);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETSNDPKTSPEED;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", SendPktSpeed);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETRCVERROR;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", recvError);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETRCVDROP;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", recvDrop);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETSNDERROR;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", sendError);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETSNDDROP;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", sendDrop);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRNETPHYIFSPEED;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%llu", PhyByteSpeed);
	m_ObjectAttrList.add(m_cObjectAttr);

#if 0
	printf("#IF Recv Speed: thisByte[%llu] - lastByte[%llu] = Offset[%lld] Speed[%lld]Bps\n",
		thisRecvByte, m_lastRecvByte, thisRecvByte - m_lastRecvByte, RecvByteSpeed);
	printf("#IF Recv Packet: thisPkt[%llu] - lastPkt[%llu] = Offset[%lld] Speed[%lld]P/s\n",
		thisRecvPkt, m_lastRecvPkt, thisRecvPkt - m_lastRecvPkt, RecvPktSpeed);
	printf("#IF Send Speed: thisByte[%llu] - lastByte[%llu] = Offset[%lld] Speed[%lld]Bps\n",
		thisSendByte, m_lastSendByte, thisSendByte - m_lastSendByte, SendByteSpeed);
	printf("#IF PhyIf Speed: thisPhyByte[%llu] - lastPhyByte[%llu] = Offset[%lld] Speed[%lld]Bps\n",
		thisPhyByte, m_lastPhyPkt, thisPhyByte - m_lastPhyPkt, PhyByteSpeed);
	fflush(stdout);
#endif
	// update last values
	m_lastRecvByte = thisRecvByte;
	m_lastRecvPkt = thisRecvPkt;
	m_lastSendByte = thisSendByte;
	m_lastSendPkt = thisSendPkt;
	m_lastPhyPkt = thisPhyByte;
	m_lastGetNetInfoTime = nowTime;
}
