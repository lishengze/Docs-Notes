#include "public.h"
#include "OSSpiImpl.h"
#include "SyslogSpiImpl.h"

#ifdef WIN32
#pragma comment(lib, "Psapi.lib")
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include <iphlpapi.h>
#pragma comment(lib, "IPHLPAPI.lib")

extern map<string, long> g_mAppNamePidMap;				// 应用进程名 - 应用进程的ID
extern map<string, string>	g_mSpcPrcMap;				// 应用进程名 - 进程所在分区 映射图
extern char *g_szHostEnvFile;							// 主机环境配置文件名
extern char *g_szNetConfFile;							// 网络配置文件名
extern char g_pHostName[32];							// 保存主机名称
extern char g_pDataCenterName[32];						// 保存数据中心名称
extern CManageConSession g_mManageConSession;			// 保存所有连接的地址信息
extern bool g_sendEvnFlag;

void COperatorSystemSpiImpl::GetenvSpi(CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
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
	m_cCommon.HostModel = "Windows";
	m_cCommon.OsMode = 32;
	m_cCommon.MainMemory = m_mMemory / 1024;			// MB
	m_cCommon.Processors = m_mCpuNum;

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

	g_sendEvnFlag = true;								// Add by Henchi , 20100302
}

bool COperatorSystemSpiImpl::GetMemory(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif

	MEMORYSTATUS statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatus(&statex);
	m_cMemInfo.FREE = statex.dwAvailPhys / MEMORY_BASIC_UNIT;
	m_cMemInfo.ACTIVEREAL = (statex.dwTotalPhys - statex.dwAvailPhys) / MEMORY_BASIC_UNIT;
	m_cMemInfo.ACTIVEVIRTUAL = (statex.dwTotalVirtual - statex.dwAvailVirtual) / MEMORY_BASIC_UNIT;
	m_cMemInfo.TOTALREAL = statex.dwTotalPhys / MEMORY_BASIC_UNIT;
	m_cMemInfo.TOTALVIRTUAL = statex.dwTotalVirtual / MEMORY_BASIC_UNIT;
	m_mMemory = statex.dwTotalPhys / MEMORY_BASIC_UNIT; // Added by Henchi, 20090805
	return true;
}

bool COperatorSystemSpiImpl::GetCPU(void)
{
	typedef NTSTATUS (*PNtQuerySystemInformation)
		(
			SYSTEM_INFORMATION_CLASS SystemInformationClass,
			PVOID SystemInformation,
			ULONG SystemInformationLength,
			PULONG ReturnLength
		);

	PNtQuerySystemInformation NtQuerySystemInformation;
	NtQuerySystemInformation = (PNtQuerySystemInformation) GetProcAddress(
			GetModuleHandle("ntdll.dll"),
			"NtQuerySystemInformation");

	if (NtQuerySystemInformation != NULL)
	{
		SYSTEM_BASIC_INFORMATION basicInformation;
		ULONG returnLength;
		NtQuerySystemInformation(
			SystemBasicInformation,
			&basicInformation,
			sizeof(basicInformation),
			&returnLength);

		int cpuNumber = basicInformation.NumberOfProcessors;

		// Addey by Henchi, 20090806
		m_mCpuNum = cpuNumber;

		SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION SysProcPerfInfo[MAX_CPUNUM];
		static UINT64 PreviousCPUIdleTime[MAX_CPUNUM];
		static UINT64 PreviousCPUUserTime[MAX_CPUNUM];
		static UINT64 PreviousCPUTotalTime[MAX_CPUNUM];
		static UINT64 PreviousCPUKernelTime[MAX_CPUNUM];
		double	CPUUsage;
		double	IdleUsage;
		double	KernelUsage;
		double	UserUsage;
		UINT64	SumCPUIdleTime = 0;
		UINT64	SumCPUUserTime = 0;
		UINT64	SumCPUTotalTime = 0;
		UINT64	SumCPUKernelTime = 0;
		UINT64	tmpCPUIdleTime = 0;
		UINT64	tmpCPUUserTime = 0;
		UINT64	tmpCPUTotalTime = 0;
		UINT64	tmpCPUKernelTime = 0;
		NtQuerySystemInformation(
			SystemProcessorPerformanceInformation,
			&SysProcPerfInfo,
			sizeof(SysProcPerfInfo),
			&returnLength);

		char szCPU[4];
		int i;
		double _maxCpuUsage = 0.0;	// 单核最大CPU利用率
		int _maxCpuCoreID = 0;
		for (i = 0; i < m_mCpuNum && i < MAX_CPUNUM; i++)
		{
			tmpCPUIdleTime = SysProcPerfInfo[i].IdleTime.QuadPart - PreviousCPUIdleTime[i];
			tmpCPUUserTime = SysProcPerfInfo[i].UserTime.QuadPart - PreviousCPUUserTime[i];
			tmpCPUTotalTime =
				(
					SysProcPerfInfo[i].UserTime.QuadPart +
					SysProcPerfInfo[i].IdleTime.QuadPart +
					SysProcPerfInfo[i].KernelTime.QuadPart
				) -
				PreviousCPUTotalTime[i];
			tmpCPUKernelTime = SysProcPerfInfo[i].KernelTime.QuadPart - PreviousCPUKernelTime[i];
			SumCPUIdleTime = SumCPUIdleTime + tmpCPUIdleTime;
			SumCPUUserTime = SumCPUUserTime + tmpCPUUserTime;
			SumCPUTotalTime = SumCPUTotalTime + tmpCPUTotalTime;
			SumCPUKernelTime = SumCPUKernelTime + tmpCPUKernelTime;
			PreviousCPUIdleTime[i] = SysProcPerfInfo[i].IdleTime.QuadPart;
			PreviousCPUUserTime[i] = SysProcPerfInfo[i].UserTime.QuadPart;
			PreviousCPUTotalTime[i] = SysProcPerfInfo[i].UserTime.QuadPart +
				SysProcPerfInfo[i].IdleTime.QuadPart +
				SysProcPerfInfo[i].KernelTime.QuadPart;
			PreviousCPUKernelTime[i] = SysProcPerfInfo[i].KernelTime.QuadPart;

			IdleUsage = (double)(tmpCPUIdleTime * 100.0) / tmpCPUTotalTime;
			KernelUsage = (double)(tmpCPUKernelTime * 100.0) / tmpCPUTotalTime;
			UserUsage = (double)(tmpCPUUserTime * 100.0) / tmpCPUTotalTime;
			CPUUsage = (double)100.0 - (tmpCPUIdleTime * 100.0) / (tmpCPUUserTime + tmpCPUKernelTime);
			sprintf(szCPU, "%d", i);
			m_cCpuInfo[i].CPU = szCPU;
			m_cCpuInfo[i].LOAD = CPUUsage;
			m_cCpuInfo[i].USER = UserUsage;
			m_cCpuInfo[i].NICE = (double)0;
			m_cCpuInfo[i].SYS = KernelUsage;
			m_cCpuInfo[i].BLOCK = (double)0;
			m_cCpuInfo[i].SWAIT = (double)0;
			m_cCpuInfo[i].INTR = (double)0;
			m_cCpuInfo[i].SSYS = CPUUsage;
			m_cCpuInfo[i].IDLE = IdleUsage;

			if (_maxCpuUsage < CPUUsage)
			{
				_maxCpuUsage = CPUUsage;
				_maxCpuCoreID = i;
			}
		}

		IdleUsage = (double)(SumCPUIdleTime * 100.0) / SumCPUTotalTime;
		KernelUsage = (double)(SumCPUKernelTime * 100.0) / SumCPUTotalTime;
		UserUsage = (double)(SumCPUUserTime * 100.0) / SumCPUTotalTime;
		CPUUsage = (double)100.0 - (SumCPUIdleTime * 100.0) / (SumCPUUserTime + SumCPUKernelTime);
		m_cCpuInfo[i].CPU = "avg";
		m_cCpuInfo[i].LOAD = CPUUsage;
		m_cCpuInfo[i].USER = UserUsage;
		m_cCpuInfo[i].NICE = (double)0;
		m_cCpuInfo[i].SYS = KernelUsage;
		m_cCpuInfo[i].BLOCK = (double)0;
		m_cCpuInfo[i].SWAIT = (double)0;
		m_cCpuInfo[i].INTR = (double)0;
		m_cCpuInfo[i].SSYS = CPUUsage;
		m_cCpuInfo[i].IDLE = IdleUsage;

		/// 计算CPU使用率指标
		m_cObjectAttr.ObjectID = m_mObjectName;
		m_cObjectAttr.MonTime = m_mTime;
		m_cObjectAttr.MonDate = m_mDate;
		m_cObjectAttr.ValueType = PERCENT_ATTR;

		m_cObjectAttr.AttrType = OSATTRCPUUSAGE;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%.2f", CPUUsage);
		m_ObjectAttrList.add(m_cObjectAttr);

		m_cObjectAttr.AttrType = OSATTRMAXCPUUSAGE;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%.2f", _maxCpuUsage);
		m_ObjectAttrList.add(m_cObjectAttr);

		m_cObjectAttr.ValueType = INT_ATTR;
		m_cObjectAttr.AttrType = OSATTRCPUBUSYCORE;
		sprintf(
			(char *)(m_cObjectAttr.AttrValue.getValue()),
			"%d", _maxCpuCoreID);
		m_ObjectAttrList.add(m_cObjectAttr);

		return true;
	}
	else
	{
		return false;
	}
}

#if 0
bool COperatorSystemSpiImpl::GetCPU(void)
{
	typedef NTSTATUS (*PNtQuerySystemInformation)
		(
			SYSTEM_INFORMATION_CLASS SystemInformationClass,
			PVOID SystemInformation,
			ULONG SystemInformationLength,
			PULONG ReturnLength
		);

	PNtQuerySystemInformation NtQuerySystemInformation;
	NtQuerySystemInformation = (PNtQuerySystemInformation) GetProcAddress(
			GetModuleHandle("ntdll.dll"),
			"NtQuerySystemInformation");

	static LONGLONG s_user = 0;
	static LONGLONG s_kernel = 0;
	static LONGLONG s_idle = 0;
	static double s_cpuusage = 0;
	if (NtQuerySystemInformation != NULL)
	{
		SYSTEM_BASIC_INFORMATION basicInformation;
		ULONG returnLength;
		NtQuerySystemInformation(
			SystemBasicInformation,
			&basicInformation,
			sizeof(basicInformation),
			&returnLength);

		int cpuNumber = basicInformation.NumberOfProcessors;
		m_mCpuNum = cpuNumber;	// Addey by Henchi, 20090805
		SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION processorPerfInfo;
		NtQuerySystemInformation(
			SystemProcessorPerformanceInformation,
			&processorPerfInfo,
			sizeof(processorPerfInfo),
			&returnLength);

		LONGLONG user = processorPerfInfo.UserTime.QuadPart - s_user;
		LONGLONG kernel = processorPerfInfo.KernelTime.QuadPart - s_kernel;
		LONGLONG idle = processorPerfInfo.IdleTime.QuadPart - s_idle;
		LONGLONG system = user + kernel;

		if (system > 1000)		//如果间隔太短则不更新CPU利用率
		{
			double	cpuusage = (system - idle) * 100.0 / system;
			s_cpuusage = cpuusage;
		}

		s_user = processorPerfInfo.UserTime.QuadPart;
		s_kernel = processorPerfInfo.KernelTime.QuadPart;
		s_idle = processorPerfInfo.IdleTime.QuadPart;

		sprintf((char *) &m_cCpuInfo[0].CPU, "%ld", 0);
		if (0 == s_user + s_kernel + s_idle)
		{
			return true;
		}

		m_cCpuInfo[0].LOAD = s_cpuusage;
		m_cCpuInfo[0].USER = 100.0 * s_user / (s_user + s_kernel + s_idle);
		m_cCpuInfo[0].NICE = 100.0 * s_idle / (s_user + s_kernel + s_idle);
		m_cCpuInfo[0].SYS = 100.0 * s_kernel / (s_user + s_kernel + s_idle);
		m_cCpuInfo[0].BLOCK = 0.0;
		m_cCpuInfo[0].SWAIT = 0.0;
		m_cCpuInfo[0].INTR = 0.0;
		m_cCpuInfo[0].SSYS = 0.0;
		m_cCpuInfo[0].IDLE = 0.0;

		return true;
	}
	else
	{
		return false;
	}
}

#endif
#define MIN_ELAPSED_TIME	(10000)
static LONGLONG fileTimeToInt64(const FILETIME *time)
{
	ULARGE_INTEGER	_time;

	_time.LowPart = time->dwLowDateTime;
	_time.HighPart = time->dwHighDateTime;

	return _time.QuadPart;
}

double GetProcessCPUUsage(HANDLE hProcess)	// 取进程占用CPU
{
#ifdef WIN32
	FILETIME creationTime;

	FILETIME exitTime;

	FILETIME kernelTime;

	FILETIME userTime;

	FILETIME nowTime;
	LONGLONG elapsedTime;
	DWORD errCode;
	LPVOID	lpMsgBuf;

	BOOL resultSuccessful = GetProcessTimes(
			(HANDLE) hProcess,
			&creationTime,
			&exitTime,
			&kernelTime,
			&userTime);

	if (!resultSuccessful)
	{
		errCode = GetLastError();
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			errCode,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) & lpMsgBuf,
			0,
			NULL);

		printf(
			"[CPUmon] An error occured while trying to get CPU time.\n Error code: %ld\n  Error description: %s\n",
			errCode,
			lpMsgBuf);
		fflush(stdout);
		LocalFree(lpMsgBuf);
		return -1.0;
	}

	GetSystemTimeAsFileTime(&nowTime);

	/*
	NOTE: win32 system time is not very precise [~10ms resolution], use
	sufficiently long sampling intervals if you make use of this method.
	*/
	elapsedTime = fileTimeToInt64(&nowTime) - fileTimeToInt64(&creationTime);

	if (elapsedTime < MIN_ELAPSED_TIME)
	{
		return 0.0;
	}
	else
	{
		return
			(
				(double)
					(fileTimeToInt64(&kernelTime) + fileTimeToInt64(&userTime))
			) / (elapsedTime) * 100.0;
	}

#else
#endif
	return 0.0;
}

#ifdef WIN32
int get_memory_usage(HANDLE hProcess, UINT64 &mem, UINT64 &vmem)	// 取进程占用内存、虚存
{
	PROCESS_MEMORY_COUNTERS pmc;
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		mem = pmc.WorkingSetSize / MEMORY_BASIC_UNIT;
		vmem = pmc.PagefileUsage / MEMORY_BASIC_UNIT;
		return 0;
	}
	else
	{
		printf("GetProcessMemoryInfo failed!\n");
	}

	return -1;
}

#endif

// by zhou.jj 20090727
BOOL CALLBACK EnablePrivilege(LPCTSTR lpszPrivilegeName, BOOL bEnable)
{
	HANDLE	hToken;
	TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!OpenProcessToken(
			GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY | TOKEN_READ,
		&hToken))
	{
		return FALSE;
	}

	if (!LookupPrivilegeValue(NULL, lpszPrivilegeName, &luid))
	{
		return TRUE;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = (bEnable) ? SE_PRIVILEGE_ENABLED : 0;

	AdjustTokenPrivileges(
		hToken,
		FALSE,
		&tp,
		sizeof(TOKEN_PRIVILEGES),
		NULL,
		NULL);

	CloseHandle(hToken);

	return (GetLastError() == ERROR_SUCCESS);
}

//获取进程用户函数：
LPCTSTR GetProcessUserName(HANDLE hProcess) // 进程ID
{
	if (hProcess == NULL)
	{
		return NULL;
	}

	HANDLE	hToken = NULL;
	BOOL bResult = FALSE;
	DWORD dwSize = 0;

	static TCHAR szUserName[256] = { 0 };
	TCHAR szDomain[256] = { 0 };
	DWORD dwDomainSize = 256;
	DWORD dwNameSize = 256;

	SID_NAME_USE SNU;
	PTOKEN_USER pTokenUser = NULL;
	__try
	{
		if (!OpenProcessToken(hProcess, TOKEN_QUERY, &hToken))
		{
			bResult = FALSE;
			__leave;
		}

		if (!GetTokenInformation(
				hToken,
			TokenUser,
			pTokenUser,
			dwSize,
			&dwSize))
		{
			if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
			{
				bResult = FALSE;
				__leave;
			}
		}

		pTokenUser = NULL;
		pTokenUser = (PTOKEN_USER) malloc(dwSize);
		if (pTokenUser == NULL)
		{
			bResult = FALSE;
			__leave;
		}

		if (!GetTokenInformation(
				hToken,
			TokenUser,
			pTokenUser,
			dwSize,
			&dwSize))
		{
			bResult = FALSE;
			__leave;
		}

		if (LookupAccountSid(
				NULL,
			pTokenUser->User.Sid,
			szUserName,
			&dwNameSize,
			szDomain,
			&dwDomainSize,
			&SNU) != 0)
		{
			return szUserName;
		}
	}

	__finally
	{
		CloseHandle(hToken);
		if (pTokenUser != NULL)
		{
			free(pTokenUser);
		}
	}

	return NULL;
}

// by zhou.jj 20090727
bool COperatorSystemSpiImpl::GetProcessInfo(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	GetDateTime();
	m_winprocMap.clear();
	m_winprocList.clear();
	if (GetProcInfo())
	{
		sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRPROCESS);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTopProcessInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_cProcInfo.HostName = m_mObjectId;
		m_cProcInfo.MonDate = m_mDate;
		m_cProcInfo.MonTime = m_mTime;
		sort(m_winprocList.begin(), m_winprocList.end());
#ifdef PRINT_DEBUG
		printf(
			"*************************** Top %d Processes ***************************\n",
			MAX_PROC_NUM);
#endif
		for (int j = 0, i = m_winprocList.size() - 1;
			 i >= 0 && j < MAX_PROC_NUM;
			 i--, j++)
		{
			CWinProcessInfo procinfo = m_winprocMap[(m_winprocList[i].pid)];
			m_cProcInfo.CPU = "";
			m_cProcInfo.TTY = "";
			m_cProcInfo.PID = procinfo.pid;
			m_cProcInfo.PRI = "";
			m_cProcInfo.NI = "";
			m_cProcInfo.SIZE = procinfo.vmem;
			m_cProcInfo.RES = procinfo.mem;
			m_cProcInfo.TIME = "";
			m_cProcInfo.pWCPU = procinfo.cpuusage;
			m_cProcInfo.pCPU = procinfo.cpuusage;

			// Mod by Henchi, 20100302
			char szTmp[10] = "";
			strncpy(szTmp, procinfo.username.c_str(), 9);
			strtok(szTmp, " ");
			m_cProcInfo.USERNAME = szTmp;
			strncpy(
				(char *)m_cProcInfo.STATE.getValue(),
				procinfo.status.c_str(),
				sizeof(m_cProcInfo.STATE) - 1);
			strncpy(
				(char *)m_cProcInfo.COMMAND.getValue(),
				procinfo.procname.c_str(),
				sizeof(m_cProcInfo.COMMAND) - 1);

			FTDC_ADD_FIELD(&m_pkgSend, &m_cProcInfo);
#ifdef PRINT_DEBUG
			ShowProcInfo(procinfo);
#endif
		}

		OSSENDPACKAGETO;

		m_cObjectAttr.MonDate = m_mDate;
		m_cObjectAttr.MonTime = m_mTime;
		m_cObjectAttr.ObjectID = m_mObjectName;
		m_cObjectAttr.ValueType = INT_ATTR;

		m_cObjectAttr.AttrType = OSATTRPROCTOTAL;
		sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%d", m_winprocList.size());
		m_ObjectAttrList.add(m_cObjectAttr);
		
		return true;
	}
	else
	{
		return false;
	}
}

bool COperatorSystemSpiImpl::NewGetNetwork(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	GetDateTime();
	if (GetNetCardInfo())
	{
		sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRNET);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnNetworkInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
		
		for (map<string, netinfo>::iterator mapIt = m_mapNetInfo.begin();
			mapIt != m_mapNetInfo.end();
			mapIt++)
		{
			CFTDRtnNetworkInfoField field;
			field.HostName = m_mObjectId;
			field.MonTime = m_mTime;
			field.MonDate = m_mDate;
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
	}
	return true;
}

bool COperatorSystemSpiImpl::GetDisk(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	GetDateTime();

	m_cFSInfo.MonDate = m_mDate;
	m_cFSInfo.MonTime = m_mTime;

	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRFS);

	m_cFSInfo.HostName = m_mObjectId;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnFileSystemInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	__int64 i64FreeBytesToCaller;

	__int64 i64TotalBytes;

	__int64 i64FreeBytes;
	char path[MAX_PATH + 1];
	GetModuleFileName(NULL, path, MAX_PATH);
	path[3] = '\0'; //只取盘符
	GetDiskFreeSpaceEx(
		path,
		(PULARGE_INTEGER) & i64FreeBytesToCaller,
		(PULARGE_INTEGER) & i64TotalBytes,
		(PULARGE_INTEGER) & i64FreeBytes);

	int m_diskTotal = (int)(i64TotalBytes / DISK_BASIC_UNIT);
	int m_diskUsed = (int)((i64TotalBytes - i64FreeBytes) / DISK_BASIC_UNIT);
	int m_diskFree = (int)(i64FreeBytes / DISK_BASIC_UNIT);
	float m_diskUsage = m_diskUsed * 100.0 / m_diskTotal;

	m_cFSInfo.FILESYSTEM = path;
	m_cFSInfo.AVAIL = m_diskFree;
	m_cFSInfo.SIZE = m_diskTotal;
	m_cFSInfo.USED = m_diskUsed;
	m_cFSInfo.pUSERD = m_diskUsage;

	FTDC_ADD_FIELD(&m_pkgSend, &m_cFSInfo);

	OSSENDPACKAGETO;
	return true;
}

// Added by Henchi, 20090805
double COperatorSystemSpiImpl::GetProcessMemoryUsage(ULONGLONG mem)
{
	return m_mMemory > 0 ? mem * 100.0 / m_mMemory : 0.0;
}

bool COperatorSystemSpiImpl::GetProcInfo(void)
{
	HANDLE	hProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32	pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (hProcessSnapshot == NULL)
	{
		return false;
	}

	if (!Process32First(hProcessSnapshot, &pe32))
	{
		printf("Process32First Error\n");
		fflush(stdout);
		CloseHandle(hProcessSnapshot);
		return false;
	}

	ULONGLONG mem = 0;

	ULONGLONG vmem = 0;
	CWinProcessInfo procInfo;
	CProcCPUUsage usageInfo;

	// Added by Henchi, 20091119
	m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_cObjectAttr.MonDate = m_mDate;
	m_cObjectAttr.MonTime = m_mTime;
	m_cObjectAttr.ValueType = PERCENT_ATTR;

	bool bSendFlag = false;
	do
	{
		if (pe32.th32ProcessID <= 4)
		{
			continue;	// System process
		}

		HANDLE	hProcess = OpenProcess(
				PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
				FALSE,
				pe32.th32ProcessID);
		if (hProcess)
		{
			get_memory_usage(hProcess, mem, vmem);
			procInfo.cmdline = pe32.szExeFile;
			procInfo.procname = GetProcName(procInfo.cmdline);
			procInfo.pid = pe32.th32ProcessID;
			procInfo.ppid = pe32.th32ParentProcessID;
			procInfo.username = GetProcessUserName(
					hProcess) != NULL ? GetProcessUserName(hProcess) : "SYSTEM";
			procInfo.mem = mem;
			procInfo.vmem = vmem;
			procInfo.status = "running";
			procInfo.cpuusage = GetProcessCPUUsage(hProcess);
			procInfo.memusage = GetProcessMemoryUsage(mem);
			usageInfo = procInfo;
			m_winprocMap[procInfo.pid] = procInfo;
			m_winprocList.push_back(usageInfo);

			if (IsSpcProc((char *)procInfo.procname.c_str()))
			{
				g_mAppNamePidMap[procInfo.procname] = procInfo.pid; // 加入全局映射表
				m_lSpcProc.push_back(procInfo.procname);
				
				sprintf(
					m_mAppId,
					"%s.%s",
					m_mAppName,
					procInfo.procname.c_str());
				m_cObjectAttr.ObjectID = m_mAppId;
				m_cObjectAttr.AttrType = APPATTRCPUUSAGE;
				sprintf(
					(char *)(m_cObjectAttr.AttrValue.getValue()),
					"%.2f",
					procInfo.cpuusage);
				SAFEADDOBJATTRFIELD;
				m_cObjectAttr.AttrType = APPATTRMEMORYUSAGE;
				sprintf(
					(char *)(m_cObjectAttr.AttrValue.getValue()),
					"%.2f",
					procInfo.memusage);
				SAFEADDOBJATTRFIELD;
				m_cObjectAttr.AttrType = APPATTRDISKUSAGE;
				sprintf(
					(char *)(m_cObjectAttr.AttrValue.getValue()),
					"%.2f",
					m_cFSInfo.pUSERD);
				SAFEADDOBJATTRFIELD;
				bSendFlag = true;
			}

			CloseHandle(hProcess);
		}
		else
		{
			printf(
				"OpenProcess Failed, th32ProcessID %u\n",
				pe32.th32ProcessID);
		}
	} while (Process32Next(hProcessSnapshot, &pe32));
	if (bSendFlag)
	{
		OSSENDPACKAGETO;
	}

	CloseHandle(hProcessSnapshot);
	return true;
}

void COperatorSystemSpiImpl::ShowProcInfo(CWinProcessInfo pinfo)
{
	printf(
		"  %5d %5d %ld %ld %f %f  %s\n",
		pinfo.pid,
		pinfo.ppid,
		(const long)pinfo.mem,
		(const long)pinfo.vmem,
		(const float)pinfo.memusage,
		(const float)pinfo.cpuusage,
		pinfo.procname.c_str());
}

string COperatorSystemSpiImpl::GetProcName(string exename)
{
	int pos = exename.find_last_of(".");
	return pos > 0 ? exename.substr(0, pos) : exename;
}

int COperatorSystemSpiImpl::GetUptime(void)
{
	MMTIME startTime;
	if (timeGetSystemTime(&startTime, sizeof(startTime)) != TIMERR_NOERROR)
	{
		return -1;
	}
	unsigned long _startTime_sec = startTime.u.ms / 1000;

	m_cObjectAttr.ObjectID = m_mObjectName;
	m_cObjectAttr.MonTime = m_mTime;
	m_cObjectAttr.MonDate = m_mDate;

	m_cObjectAttr.ValueType = INT_ATTR;
	m_cObjectAttr.AttrType = OSATTRUPTIME;
	sprintf((char *)(m_cObjectAttr.AttrValue.getValue()), "%u", _startTime_sec);
	m_ObjectAttrList.add(m_cObjectAttr);

	m_cObjectAttr.ValueType = STRING_ATTR;
	m_cObjectAttr.AttrType = OSATTRUPTIMESTR;
	char _buff[512] = { 0 };
	sprintf(_buff, "%d days, %02d:%02d:%02d",
		_startTime_sec / 86400,
		_startTime_sec % 86400 / 3600,
		_startTime_sec % 3600 / 60,
		_startTime_sec % 60);
	m_cObjectAttr.AttrValue = _buff;
	m_ObjectAttrList.add(m_cObjectAttr);

	return 0;
}

string createIfNameFromIfIndex(DWORD ifindex)
{
	char _nameBuff[10];
	sprintf(_nameBuff, "if-%u", ifindex);
	return _nameBuff;
}

bool COperatorSystemSpiImpl::GetNetCardInfo(void)
{
	// update net interface information
	InitNetInterfaceInfo_win();

	// Declare and initialize variables.
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;

	/* variables used for GetIfTable and GetIfEntry */
	MIB_IFTABLE *pIfTable = NULL;
	MIB_IFROW *pIfRow = NULL;
	try
	{
		// Allocate memory for our pointers.
		pIfTable = (MIB_IFTABLE *)malloc(sizeof(MIB_IFTABLE));
		if (pIfTable == NULL)
		{
			throw "[GetNetCardInfo] Error allocating memory needed to call GetIfTable.";
		}

		// Before calling GetIfEntry, we call GetIfTable to make
		// sure there are entries to get and retrieve the interface index.

		// Make an initial call to GetIfTable to get the
		// necessary size into dwSize
		dwSize = sizeof(MIB_IFTABLE);
		if (GetIfTable(pIfTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER)
		{
			free(pIfTable);
			pIfTable = (MIB_IFTABLE *)malloc(dwSize);
			if (pIfTable == NULL) throw "[GetNetCardInfo] Error allocating memory.";
		}

		// Make a second call to GetIfTable to get the actual
		// data we want.
		if ((dwRetVal = GetIfTable(pIfTable, &dwSize, 0)) == NO_ERROR)
		{
			if (pIfTable->dwNumEntries > 0)
			{
				pIfRow = (MIB_IFROW *)malloc(sizeof(MIB_IFROW));
				if (pIfRow == NULL) throw "Error allocating memory.";

				for (int i = 0; i < pIfTable->dwNumEntries; i++)
				{
					//DWORD ifIndex = pIfTable->table[i].dwIndex;
					// set interface index
					pIfRow->dwIndex = pIfTable->table[i].dwIndex;

					// get interface information
					if ((dwRetVal = GetIfEntry(pIfRow)) == NO_ERROR)
					{
						string ifName = createIfNameFromIfIndex(pIfRow->dwIndex);
						map<string, netinfo>::iterator itNetIF = m_mapNetInfo.find(ifName);
						if (itNetIF == m_mapNetInfo.end())
							continue;

						// get this interface information
						_netinfo &_thisNetInfo = itNetIF->second;

						// interface state
						switch (pIfRow->dwAdminStatus)
						{
						case IF_ADMIN_STATUS_UP:
							_thisNetInfo.state = "UP";
							break;
						case IF_ADMIN_STATUS_DOWN:
							_thisNetInfo.state = "DOWN";
							break;
						case IF_ADMIN_STATUS_TESTING:
							_thisNetInfo.state = "TEST";
							break;
						default:
							_thisNetInfo.state = "Unknown";
							break;
						}

						_thisNetInfo.rcvbytes = pIfRow->dwInOctets;
						_thisNetInfo.rcvpkgs = pIfRow->dwInUcastPkts + pIfRow->dwInNUcastPkts;
						_thisNetInfo.rcverrpkgs = pIfRow->dwInErrors;
						_thisNetInfo.rcvdrppkgs = pIfRow->dwInDiscards;

						_thisNetInfo.sndbytes = pIfRow->dwOutOctets;
						_thisNetInfo.sndpkgs = pIfRow->dwOutUcastPkts + pIfRow->dwOutNUcastPkts;
						_thisNetInfo.snderrpkgs = pIfRow->dwOutErrors;
						_thisNetInfo.snddrppkgs = pIfRow->dwOutDiscards;
					}
					else
					{
						printf("GetIfEntry failed for index %d with error: %ld\n", i, dwRetVal);
					}
				}
			}
			else
			{
				printf("\tGetIfTable failed with error: %ld\n", dwRetVal);
			}

		}
	}
	catch (const char* _err)
	{
		printf("%s\n", _err);
		free(pIfTable);
		free(pIfRow);
		return false;
	}

	free(pIfTable);
	free(pIfRow);
	return true;
}

int COperatorSystemSpiImpl::GetRoute(void)
{
	/* variables used for GetIfForwardTable */
	PMIB_IPFORWARDTABLE pIpForwardTable = NULL;
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;

	char szDestIp[128];
	char szMaskIp[128];
	char szGatewayIp[128];

	struct in_addr IpAddr;
	try
	{
		pIpForwardTable = (MIB_IPFORWARDTABLE *)malloc(sizeof(MIB_IPFORWARDTABLE));
		if (pIpForwardTable == NULL)
		{
			throw "COperatorSystemSpiImpl::GetRoute. Error allocating memory.";
		}

		if (GetIpForwardTable(pIpForwardTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER)
		{
			free(pIpForwardTable);
			pIpForwardTable = (MIB_IPFORWARDTABLE *)malloc(dwSize);
			if (pIpForwardTable == NULL)
			{
				throw "COperatorSystemSpiImpl::GetRoute. Error allocating memory";
			}
		}

		/* Note that the IPv4 addresses returned in
		* GetIpForwardTable entries are in network byte order
		*/
		if ((dwRetVal = GetIpForwardTable(pIpForwardTable, &dwSize, 0)) != NO_ERROR)
			throw "GetIpForwardTable failed.";


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
		for (int i = 0; i < (int)pIpForwardTable->dwNumEntries; i++)
		{
			char _buff[8] = { 0 };
			sprintf(_buff, "if-%u", pIpForwardTable->table[i].dwForwardIfIndex);
			field.Dev = _buff;

			/* Convert IPv4 addresses to strings */
			IpAddr.S_un.S_addr = (u_long)pIpForwardTable->table[i].dwForwardDest;
			strcpy_s(szDestIp, sizeof(szDestIp), inet_ntoa(IpAddr));
			field.Destination = szDestIp;

			IpAddr.S_un.S_addr = (u_long)pIpForwardTable->table[i].dwForwardMask;
			strcpy_s(szMaskIp, sizeof(szMaskIp), inet_ntoa(IpAddr));
			field.Mask = szMaskIp;

			IpAddr.S_un.S_addr = (u_long)pIpForwardTable->table[i].dwForwardNextHop;
			strcpy_s(szGatewayIp, sizeof(szGatewayIp), inet_ntoa(IpAddr));
			field.Gateway = szGatewayIp;

			field.Flag = 1;

			field.RefCnt = 0;
			field.Use = 0;
			field.Metric = pIpForwardTable->table[i].dwForwardMetric1;
			field.Mtu = 0;
			field.Win = 0;
			field.Rtt = 0;

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
			iCount++;
		}

		if (iCount > 0)
		{
			m_pkgSend.SetChain(FTDC_CHAIN_LAST);
			OSSENDPACKAGETO;
		}

	}
	catch (const char* _err)
	{
		printf("%s\n", _err);
		free(pIpForwardTable);
		return -1;
	}

	free(pIpForwardTable);
	return 0;
}


static const string NetworkAdapterRegeditKey = "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}";
bool COperatorSystemSpiImpl::InitNetInterfaceInfo_win(void)
{
	// 通过注册表获取网卡类型信息
	// key: Name, such as {DF4A9D2C-8742-4EB1-8703-D395C4183F33}
	// value: physical adapter OR virtual adapter
	map<string, bool> _adapterInfoInRegedit;
	do
	{
		/*
		* 通过注册表信息获取网卡的类别
		* 字段Characteristics
		* ox1 NCF_VIRTUAL 说明组件是个虚拟适配器
		* ox2 NCF_SOFTWARE_ENUMERATED 说明组件是一个软件模拟的适配器
		* ox4 NCF_PHYSICAL 说明组件是一个物理适配器
		* ox8 NCF_HIDDEN 说明组件不显示用户接口
		* ox10 NCF_NO_SERVICE 说明组件没有相关的服务(设备驱动程序)
		* ox20 NCF_NOT_USER_REMOVABLE 说明不能被用户删除(例如，通过控制面板或设备管理器)
		* ox40 NCF_MULTIPORT_INSTANCED_ADAPTER 说明组件有多个端口，每个端口作为单独的设备安装。
		* 每个端口有自己的hw_id(组件ID)并可被单独安装，这只适合于EISA适配器
		* ox80 NCF_HAS_UI 说明组件支持用户接口(例如，Advanced Page或CustomerProperties Sheet)
		* ox400 NCF_FILTER 说明组件是一个过滤器
		*/
		/*
		* 在注册表中没有网卡的Index字段，因此只能用网卡的Name字段进行标示，与GetAdaptersInfo()函数
		* 获取的网卡信息进行匹配
		*/
		
		// Network Adapter Regedit Key Handle
		HKEY NARKhandle;
		int res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, NetworkAdapterRegeditKey.c_str(),
			0, KEY_READ, &NARKhandle);
		if (res != ERROR_SUCCESS)
		{
			RegCloseKey(NARKhandle);
			break;;
		}

		DWORD dwSubKeyCnt;          // 子键的数量  
		DWORD dwSubKeyNameMaxLen;   // 子键名称的最大长度(不包含结尾的null字符)  
		DWORD dwKeyValueCnt;        // 键值项的数量  
		DWORD dwKeyValueNameMaxLen; // 键值项名称的最大长度(不包含结尾的null字符)  
		DWORD dwKeyValueDataMaxLen; // 键值项数据的最大长度(in bytes)  

		res = RegQueryInfoKey(NARKhandle, NULL, NULL, NULL, &dwSubKeyCnt,
			&dwSubKeyNameMaxLen, NULL, &dwKeyValueCnt,
			&dwKeyValueNameMaxLen, &dwKeyValueDataMaxLen,
			NULL, NULL);
		if (res != ERROR_SUCCESS)
		{
			RegCloseKey(NARKhandle);
			break;
		}

		// 遍历注册表下的健值
		LPTSTR lpszSubKeyName = new char[dwSubKeyNameMaxLen + 1];
		for (int index = 0; index < dwSubKeyCnt; ++index)
		{
			memset(lpszSubKeyName, 0, dwSubKeyNameMaxLen + 1);
			DWORD dwNameCnt = dwSubKeyNameMaxLen + 1;
			res = RegEnumKeyEx(NARKhandle, index, lpszSubKeyName, &dwNameCnt,
				NULL, NULL, NULL, NULL);
			if (res != ERROR_SUCCESS) break;

			// 获取到子键的名称，打开子键
			string subKeyPath = NetworkAdapterRegeditKey + "\\";
			subKeyPath.append(lpszSubKeyName);

			HKEY subKeyHandle;
			res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, subKeyPath.c_str(), 0, KEY_READ, &subKeyHandle);
			if (res != ERROR_SUCCESS)
			{
				RegCloseKey(subKeyHandle);
				continue;
			}

			// 获取子键中NetCfgInstanceId的值
			DWORD dwKeyValueType = ULONG_MAX;
			DWORD dwKeyValueDataSize = ULONG_MAX;
			char lpbNetCfgInstanceIdValue[MAX_ADAPTER_NAME_LENGTH + 4];		// NetCfgInstanceId
			memset(lpbNetCfgInstanceIdValue, 0, MAX_ADAPTER_NAME_LENGTH + 4);
			res = RegQueryValueEx(subKeyHandle, "NetCfgInstanceId", NULL, &dwKeyValueType,
				(LPBYTE)lpbNetCfgInstanceIdValue, &dwKeyValueDataSize);
			if (res != ERROR_SUCCESS)
			{
				RegCloseKey(subKeyHandle);
				continue;
			}

			// 获取子键中Characteristics的值
			dwKeyValueType = ULONG_MAX;
			dwKeyValueDataSize = ULONG_MAX;
			DWORD dwCharacteristicsValue;	// Characteristics DWORD
			DWORD valuex;
			res = RegQueryValueEx(subKeyHandle, "Characteristics", NULL, &dwKeyValueType,
				(LPBYTE)&dwCharacteristicsValue, &dwKeyValueDataSize);
			if (res != ERROR_SUCCESS)
			{
				RegCloseKey(subKeyHandle);
				continue;
			}

			// 保存信息
			bool isPhysicalAdapter = (dwCharacteristicsValue & 0x04) ? NetInterface_PHYSICAL : NetInterface_VIRTUAL;
			_adapterInfoInRegedit.insert(make_pair(lpbNetCfgInstanceIdValue, isPhysicalAdapter));
			RegCloseKey(subKeyHandle);
		}

		delete[] lpszSubKeyName;
		RegCloseKey(NARKhandle);
	} while (false);

	// 通过GetAdaptersInfo()函数获取网卡适配器信息
	{
		/* Declare and initialize variables */

		// It is possible for an adapter to have multiple
		// IPv4 addresses, gateways, and secondary WINS servers
		// assigned to the adapter. 
		//
		// Note that this sample code only prints out the 
		// first entry for the IP address/mask, and gateway, and
		// the primary and secondary WINS server for each adapter. 

		PIP_ADAPTER_INFO pAdapterInfo;
		PIP_ADAPTER_INFO pAdapterIndex = NULL;
		DWORD dwRetVal = 0;

		ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
		pAdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
		if (pAdapterInfo == NULL)
		{
			printf("Error allocating memory needed to call GetAdaptersinfo\n");
			return false;
		}
		// Make an initial call to GetAdaptersInfo to get
		// the necessary size into the ulOutBufLen variable
		if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW)
		{
			free(pAdapterInfo);
			pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen);
			if (pAdapterInfo == NULL)
			{
				printf("Error allocating memory needed to call GetAdaptersinfo\n");
				return false;
			}
		}

		// 获取有效接口的信息
		if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR)
		{
			pAdapterIndex = pAdapterInfo;
			while (pAdapterIndex)
			{
				netinfo pNetIfInfo;

				map<string, bool>::iterator itAdapterInRegedit = 
					_adapterInfoInRegedit.find(pAdapterIndex->AdapterName);
				if (itAdapterInRegedit != _adapterInfoInRegedit.end())
					pNetIfInfo.iftype = itAdapterInRegedit->second;
				else
					pNetIfInfo.iftype = NetInterface_VIRTUAL;

				// get interface name
				pNetIfInfo.name = createIfNameFromIfIndex(pAdapterIndex->Index);

				// formate MAC address
				for (int i = 0; i < pAdapterIndex->AddressLength; i++)
				{
					char _buff[8];
					if (i == (pAdapterIndex->AddressLength - 1))
						sprintf(_buff, "%.2X", (int)pAdapterIndex->Address[i]);
					else
						sprintf(_buff, "%.2X-", (int)pAdapterIndex->Address[i]);
					pNetIfInfo.mac.append(_buff);
				}
				pNetIfInfo.ip = pAdapterIndex->IpAddressList.IpAddress.String;
				pNetIfInfo.mask = pAdapterIndex->IpAddressList.IpMask.String;

				m_mapNetInfo[pNetIfInfo.name] = pNetIfInfo;

				pAdapterIndex = pAdapterIndex->Next;
			}
		}
		else
		{
			if (pAdapterInfo) free(pAdapterInfo);
			printf("GetAdaptersInfo failed with error: %d\n", dwRetVal);
			return false;
		}
		if (pAdapterInfo) free(pAdapterInfo);
	}
	return true;
}


// Added end
#endif
