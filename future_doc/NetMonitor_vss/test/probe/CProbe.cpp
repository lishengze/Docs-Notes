#include "CProbe.h"
#include "Mutex.h"
#include "PrjCommon.h"

extern int g_nTouchCount;
extern int g_nWorkFlag; 
extern CMutex g_mWorkFlagMutex;  
extern char g_mDumpPath[200];		
extern char g_mTimeStamp[8];		//控制单次采集任务的起始时间
extern char g_pHostName[32];   // 保存主机名称

map<string, long> g_mAppNamePidMap;			// 应用进程名 - 应用进程的ID
map<string, string>	g_mSpcPrcMap;				// 应用进程名 - 进程所在分区 映射图

STORE_DATA_MAP g_mSysCPUInfo;
STORE_DATA_MAP g_mSysNetworkInfo;
STORE_DATA_MAP g_mAppCPUInfo;
STORE_DATA_MAP g_mAppAttrInfo;

#ifdef LINUX

bool CProbe::IsNumber(char *pszData)
{
	if (!pszData || !strlen(pszData))
		return false;

	char *p = pszData;
	for (int i = 0; i < strlen(pszData); i++)
	{
		if (!isdigit(*(p+i)))
			return false;
	}
	return true;
}

bool CProbe::IsDir(char *pszPath)
{
	struct stat stStat;
	if (lstat(pszPath,&stStat)<0)
	{
#ifdef PRINT_DEBUG
		printf("lstat error for %s!\n[%s(%d):%d]\n",
			pszPath, __FILE__, __LINE__, errno);
#endif
		return false;
	}
	if (S_ISDIR(stStat.st_mode)||S_ISLNK(stStat.st_mode))
	{
		return true;
	}
	return false;
}

void CProbe::ScanProcesses()
{
	char szPath[] = "/proc/";
	char szProcess[MAX_PATH_LEN], szProcCmd[MAX_PATH_LEN],
		szProcStatus[MAX_PATH_LEN], szProcStat[MAX_PATH_LEN];
	DIR *pDir;
	struct dirent *pstDirent;

	pDir = opendir(szPath);
	if (!pDir)
	{
		printf("Open FS /proc failed!\n[%s(%d):%d]\n", __FILE__, __LINE__, errno);
		fflush(stdout);
		return;
	}

	while ((pstDirent = readdir(pDir)))
	{
		if ((strcmp(pstDirent->d_name,".")==0)
			||(strcmp(pstDirent->d_name,"..")==0)
			||!IsNumber(pstDirent->d_name))
			continue;
		sprintf(szProcess, "%s%s", szPath, pstDirent->d_name);
		if (IsDir(szProcess))
		{
			sprintf(szProcCmd, "%s/cmdline", szProcess);
			sprintf(szProcStat, "%s/stat", szProcess);
			sprintf(szProcStatus, "%s/status", szProcess);
			procinfo pinfo;
			memset((void *)&pinfo, 0x00, sizeof(pinfo));
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
			if (strcmp(pinfo.cmdname, "java") == 0)
			{
				GetJavaProcInfo(pinfo);
			}
			procinfo_linux m_procinfo;
			m_procinfo = pinfo;

			SaveProcInfo(m_procinfo);
		}
	}

	closedir(pDir);
}

void CProbe::GetJavaProcInfo(procinfo &pinfo)
{
	char szCmdLine[MAX_BUF_SIZE];
	int length = strlen(pinfo.cmdline);
	memset(szCmdLine, 0x00, MAX_BUF_SIZE);
	strncpy(szCmdLine, pinfo.cmdline, MAX_BUF_SIZE -1);
	char *p = strtok(szCmdLine, " ");
	while(p != NULL)
	{
		p = strtok(NULL, " ");

		if ( p != NULL )
		{
			// 解析Java进程执行的MainClass
			if (*p != '-' && *p != ':')
			{
				char *q = (strrchr(p, '/') == NULL) ? p : strrchr(p, '/')+1;
				p = (strrchr(q, '.') == NULL) ? q : strrchr(q, '.')+1;

				// Added by Henchi, 20091021
				// 解析形如: java -Xms2048m org.tanukisoftware.wrapper.WrapperSimpleApp socket.MonitorMain
				// 应当抛弃org...WrapperSimpleApp部分，取 MonitorMain
				if ( strcmp(p, "WrapperSimpleApp") == 0 )
					continue;

				memset(pinfo.cmdname, 0x00, MAX_PATH_LEN);
				strncpy(pinfo.cmdname, p, MAX_PATH_LEN -1);

				q = strtok(NULL, " ");
				if (q != NULL)
					strncpy(pinfo.args, q, MAX_PATH_LEN -1);
				else
					strcpy(pinfo.args, "");
				break;
			}
			// Added by Henchi, 20091028
			// 用于获取排除命令行中-classpath项
			else if (strncmp(p, "-classpath", 10) == 0)
			{
				p = strtok(NULL, " ");
			}
			// Added by Henchi, 20091026
			// 用于获取Tomcat进程的实际业务名： 如-Dcatalina.base=/home/uapp2/domains/access1 中的 access1
			else if (strncmp(p, "-Dcatalina.base", 15) == 0)
			{
				char *q = strrchr(p, '=') == NULL ? p : strrchr(p, '=')+1;
				p = strrchr(q, '/') == NULL ? q : strrchr(q, '/')+1;

				if (p != NULL)
				{
					q = p + strlen(p) ;
			                while(isdigit(*(-- q)) != 0)
			                { }
					strcpy(pinfo.args, q+1);
					*(q+1) = 0x00;
					memset(pinfo.cmdname, 0x00, MAX_PATH_LEN);
					sprintf(pinfo.cmdname, "Bootstrap_%s", p);		// 得到进程名如：Bootstrap_access  1
				}
				break;
			}
		}
	}
}

char *CProbe::SeekChar(char *psSrc, int iChar)
{
	char *p;
	if (NULL == (p = strchr(psSrc, iChar)))
	{
		return NULL;
	}
	while (*++p == BLANK_FLAG)					// 去除目标符号之后出现的空格
	{}
	return p;
}

#if defined HP_UX || defined LINUX
bool CProbe::GetCPU()
{
	static INT64 prevTotalTime[MAX_CPUNUM];
	static sCpuInfo prevCPUs[MAX_CPUNUM];
	static int iMaxActCpus = 0;
	//Add by Henchi
	INT64 absTotalTime;
	double dTotalLoad  = 0;
	double dTotalUser  = 0;
	double dTotalNice  = 0;
	double dTotalSys   = 0;
	double dTotalIdle  = 0;
	double dTotalBlock = 0;
	double dTotalSwait = 0;
	double dTotalInter = 0;
	double dTotalSsys  = 0;

#ifdef HP_UX
    if (m_mCpuNum <= 0 || iMaxActCpus <= 0)
    {
        pst_dynamic psd;
        if (pstat_getdynamic(&psd, sizeof(psd), (size_t)1, 0) != -1)
        {
            m_mCpuNum = psd.psd_proc_cnt;
            iMaxActCpus = psd.psd_max_proc_cnt;
        }
        else
            return false;
    }
    if (m_pProcessor == NULL && iMaxActCpus > 0)
        m_pProcessor = (struct pst_processor *)malloc(iMaxActCpus * sizeof(pst_processor));
	if (pstat_getprocessor(m_pProcessor, sizeof(pst_processor), iMaxActCpus, 0) != -1)
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
				continue;
#endif
			// Mod by Henchi, 20090428
			// sprintf((char *)&m_cCpuInfo[i].CPU, "%ld", m_pProcessor[i].psp_idx);
			// 强制设定CPU编号为0,1,2,...N
			sprintf((char *)&m_cCpuInfo[iCount].CPU, "%d", iCount);

			/* Add by Henchi */
			prevCPUs[iCount]      = m_sCPUs[iCount];
			m_sCPUs[iCount].User  = m_pProcessor[i].psp_cpu_time[CP_USER ];
			m_sCPUs[iCount].Nice  = m_pProcessor[i].psp_cpu_time[CP_NICE ];
			m_sCPUs[iCount].Sys   = m_pProcessor[i].psp_cpu_time[CP_SYS  ];
			m_sCPUs[iCount].Idle  = m_pProcessor[i].psp_cpu_time[CP_IDLE ];
			m_sCPUs[iCount].Block = m_pProcessor[i].psp_cpu_time[CP_BLOCK];
			m_sCPUs[iCount].Swait = m_pProcessor[i].psp_cpu_time[CP_SWAIT];
			m_sCPUs[iCount].Inter = m_pProcessor[i].psp_cpu_time[CP_INTR ];
			m_sCPUs[iCount].Ssys  = m_pProcessor[i].psp_cpu_time[CP_SSYS ];

			prevTotalTime[iCount] = m_mTotalTime[iCount];
			m_mTotalTime[iCount] = m_sCPUs[iCount].User
							+ m_sCPUs[iCount].Nice
							+ m_sCPUs[iCount].Sys
							+ m_sCPUs[iCount].Idle
							+ m_sCPUs[iCount].Block
							+ m_sCPUs[iCount].Swait
							+ m_sCPUs[iCount].Inter
							+ m_sCPUs[iCount].Ssys;

			absTotalTime = (m_mTotalTime[iCount]  - prevTotalTime[iCount] );

			m_cCpuInfo[iCount].LOAD  = m_pProcessor[i].psp_avg_1_min;
			if (absTotalTime != 0)
			{
				m_cCpuInfo[iCount].USER  = (double)((m_sCPUs[iCount].User  - prevCPUs[iCount].User ) * 100.0 / absTotalTime);
				m_cCpuInfo[iCount].NICE  = (double)((m_sCPUs[iCount].Nice  - prevCPUs[iCount].Nice ) * 100.0 / absTotalTime);
				m_cCpuInfo[iCount].SYS   = (double)((m_sCPUs[iCount].Sys   - prevCPUs[iCount].Sys  ) * 100.0 / absTotalTime);
				m_cCpuInfo[iCount].BLOCK = (double)((m_sCPUs[iCount].Block - prevCPUs[iCount].Block) * 100.0 / absTotalTime);
				m_cCpuInfo[iCount].SWAIT = (double)((m_sCPUs[iCount].Swait - prevCPUs[iCount].Swait) * 100.0 / absTotalTime);
				m_cCpuInfo[iCount].INTR  = (double)((m_sCPUs[iCount].Inter - prevCPUs[iCount].Inter) * 100.0 / absTotalTime);
				m_cCpuInfo[iCount].SSYS  = (double)((m_sCPUs[iCount].Ssys  - prevCPUs[iCount].Ssys ) * 100.0 / absTotalTime);
				m_cCpuInfo[iCount].IDLE  = (double)((m_sCPUs[iCount].Idle  - prevCPUs[iCount].Idle ) * 100.0 / absTotalTime);
			}
			else
			{
				m_cCpuInfo[iCount].USER  = (double)0;
				m_cCpuInfo[iCount].NICE  = (double)0;
				m_cCpuInfo[iCount].SYS   = (double)0;
				m_cCpuInfo[iCount].BLOCK = (double)0;
				m_cCpuInfo[iCount].SWAIT = (double)0;
				m_cCpuInfo[iCount].INTR  = (double)0;
				m_cCpuInfo[iCount].SSYS  = (double)0;
				m_cCpuInfo[iCount].IDLE  = (double)100;
			}
			dTotalLoad  += (const double)m_cCpuInfo[iCount].LOAD  ;
			dTotalUser  += (const double)m_cCpuInfo[iCount].USER  ;
			dTotalNice  += (const double)m_cCpuInfo[iCount].NICE  ;
			dTotalSys   += (const double)m_cCpuInfo[iCount].SYS   ;
			dTotalBlock += (const double)m_cCpuInfo[iCount].BLOCK ;
			dTotalSwait += (const double)m_cCpuInfo[iCount].SWAIT ;
			dTotalInter += (const double)m_cCpuInfo[iCount].INTR  ;
			dTotalSsys  += (const double)m_cCpuInfo[iCount].SSYS  ;
			dTotalIdle  += (const double)m_cCpuInfo[iCount].IDLE  ;

			// Add by Henchi 20090512
			iCount ++;
		}

		if(iCount > 0)  // 计算所有CPU的平均值
		{
			m_cCpuInfo[iCount].CPU   = "avg";
			m_cCpuInfo[iCount].LOAD  = dTotalLoad  / iCount;
			m_cCpuInfo[iCount].USER  = dTotalUser  / iCount;
			m_cCpuInfo[iCount].NICE  = dTotalNice  / iCount;
			m_cCpuInfo[iCount].SYS   = dTotalSys   / iCount;
			m_cCpuInfo[iCount].BLOCK = dTotalBlock / iCount;
			m_cCpuInfo[iCount].SWAIT = dTotalSwait / iCount;
			m_cCpuInfo[iCount].INTR  = dTotalInter / iCount;
			m_cCpuInfo[iCount].SSYS  = dTotalSsys  / iCount;
			m_cCpuInfo[iCount].IDLE  = dTotalIdle  / iCount;
		}
#ifdef PRINT_DEBUG
		ShowCPU();
#endif		

		SaveSysCPUInfo();

		return true;
	}  // end if(pstat_getprocessor)
	return false;
}
#endif

int CProbe::GetProcessor(pst_processor * processor)
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
	char szBuf[MAX_LINE_LEN], szTmp[MAX_LINE_LEN];
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf)-1] = 0x00;	// 除去行尾换行符
		if (0 == strncmp(szBuf, CPU_TIP, strlen(CPU_TIP)))
		{
			p = szBuf + strlen(CPU_TIP);
			if (*p != BLANK_FLAG)		// CPU - n
			{
				p = SeekChar(p, BLANK_FLAG);
				if (7 == sscanf(p, "%ld %ld %ld %ld %ld %ld %ld",
					&(processor[iCpuNum].psp_cpu_time[CP_USER]),
					&(processor[iCpuNum].psp_cpu_time[CP_NICE]),
					&(processor[iCpuNum].psp_cpu_time[CP_SYS]),
					&(processor[iCpuNum].psp_cpu_time[CP_IDLE]),
					&(processor[iCpuNum].psp_cpu_time[CP_SWAIT]),
					&(processor[iCpuNum].psp_cpu_time[CP_INTR]),
					&(processor[iCpuNum].psp_cpu_time[CP_SSYS]))
					)
				{
					processor[iCpuNum].psp_cpu_time[CP_BLOCK] = 0;
					processor[iCpuNum].psp_avg_1_min = (const double)loadavg;
					processor[iCpuNum].psp_idx = (unsigned long)iCpuNum;
					iCpuNum++;
				}
			}
		}
		else
			continue;
	}
	fclose(fpSrc);
	return iCpuNum;
}

float CProbe::GetLoadAvg_1M()
{
	FILE *fpSrc;
	char avg1[10];
	float avg;

	if ((fpSrc = fopen("/proc/loadavg", "r")))
	{
		fscanf(fpSrc,"%f %*s %*s %*s %*s", &avg);
		fclose(fpSrc);
		return avg;
	}
	else
	{
		return 0.0;
	}
}

void CProbe::ShowCPU()
{
	for(int i = 0; i <= m_mCpuNum; i ++)
	{
		printf("CPU:%s,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
			(const char *)m_cCpuInfo[i].CPU  ,
			(const double)m_cCpuInfo[i].LOAD ,
			(const double)m_cCpuInfo[i].USER ,
			(const double)m_cCpuInfo[i].NICE ,
			(const double)m_cCpuInfo[i].SYS  ,
			(const double)m_cCpuInfo[i].IDLE ,
			(const double)m_cCpuInfo[i].BLOCK,
			(const double)m_cCpuInfo[i].SWAIT,
			(const double)m_cCpuInfo[i].INTR ,
			(const double)m_cCpuInfo[i].SSYS );
	}
}

bool CProbe::GetProcessInfo()
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
#endif

	GetDateTime();
	m_vctProcUsage.clear();
	ScanProcesses();
	sort(m_vctProcUsage.begin(), m_vctProcUsage.end());
	if (m_vctProcUsage.size())
	{
#ifdef PRINT_DEBUG
		printf("\n-CPU--TTY---PID---USER---PRI--NI------SIZE--------RES----S--TIME---%%CPU-----COMMAND-----\n");
#endif
		for (int j = 0, i = m_vctProcUsage.size()-1; i >= 0 && j < MAX_PROC_NUM; i--, j++)
		{
			procinfo_linux & pinfo = m_mapProcInfo[(m_vctProcUsage[i].pid)];
#ifdef PRINT_DEBUG
			ShowProcInfo(pinfo);
#endif
		}
	}
	return true;
}

void CProbe::SaveProcInfo(procinfo_linux & pinfo)
{
	/* 判断此进程信息是否为新启动进程，若为新，则其CPU使用率初始为0,并保存信息入map
	若不为新，则结合其初始信息计算CPU使用率，更新map信息，并写vector*/
	//	map < int, procinfo_linux > m_mapProcInfo;
	//	vector < proc_cpuusage > m_vctProcUsage;
	map < int, procinfo_linux >::iterator mapIt = m_mapProcInfo.find(pinfo.pid);

	/// Modify by Henchi, 20090302 修正原代码中除法溢出BUG
	if ( mapIt != m_mapProcInfo.end() && strcmp(pinfo.cmdname ,(mapIt->second).cmdname) == 0
		&& pinfo.currenttime > (mapIt->second).currenttime)
	{
		// 属于原有进程，需计算新的CPU使用率
		pinfo.cpuusage = (float)(((pinfo.utime - (mapIt->second).utime) + (pinfo.stime- (mapIt->second).stime))*1.00
			/ (pinfo.currenttime - (mapIt->second).currenttime));
		proc_cpuusage pusage;
		pusage = pinfo;
		m_vctProcUsage.push_back(pusage);
	}
	m_mapProcInfo[pinfo.pid] = pinfo;

	// 特殊进程的处理
	if (IsSpcProc(pinfo.cmdname))
	{
		char szApp[MAX_NAMELEN];
		int iArg = 0;

		if ((iArg = atoi(pinfo.args)))
		{
			sprintf(m_mAppId, "%s.%s.%d", m_mAppName, pinfo.cmdname, iArg);
			sprintf(szApp, "%s.%d", pinfo.cmdname, iArg);
		}
		else
		{
			sprintf(m_mAppId, "%s.%s", m_mAppName, pinfo.cmdname);
			sprintf(szApp, "%s", pinfo.cmdname);
		}
		// Added by Henchi 20081126 针对新产生的业务进程发送相关变更信息
		if (g_mAppNamePidMap.find(string(szApp)) == g_mAppNamePidMap.end())
		{
			// SendUpdateSyscfgPkg((const char *)g_pHostName, (const char *)szApp);
		}
		g_mAppNamePidMap[string(szApp)] = pinfo.pid;

		//保存进程信息
		SaveAppProcessInfo(pinfo);
	}
}

bool CProbe::IsSpcProc(char * szUcomm)
{
	std::map<std::string, std::string>::iterator MapIt;

	for(MapIt = g_mSpcPrcMap.begin(); MapIt != g_mSpcPrcMap.end(); MapIt ++)
	{
		if(strncmp(szUcomm, MapIt->first.c_str(), strlen(szUcomm)) == 0
			&& (strlen(MapIt->first.c_str()) - strlen(szUcomm)) <= 3 )
			return true;
	}
	return false;
}

void CProbe::ScanStatus(char *pszFileName, procinfo &pinfo)
{
	if (!pszFileName)
		return;

	FILE *fpSrc;
	if (!(fpSrc = fopen(pszFileName, "r")))
		return;
	char szBuf[MAX_LINE_LEN];
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		szBuf[strlen(szBuf)-1] = 0x00;	// 除去行尾换行符
		if (0 == strncmp(szBuf, UID_TIP, strlen(UID_TIP)))
		{
			pinfo.uid = atoi(SeekChar(szBuf, COLON_FLAG));
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
			continue;
	}
	fclose(fpSrc);
}

void CProbe::ScanProcStat(char *pszFileName, procinfo &pinfo)
{
	if (!pszFileName)
		return;

	FILE *fpSrc;
	if (!(fpSrc = fopen(pszFileName, "r")))
		return;

	char szStatStr[MAX_BUF_SIZE], *s, *t;

	if ((s = fgets (szStatStr, sizeof(szStatStr), fpSrc)) == NULL)
	{
		fclose(fpSrc);
		return;
	}
	fclose(fpSrc);

	unsigned int uTime = time((time_t *)NULL);
	sscanf(szStatStr, "%u", &(pinfo.pid));
	s = strchr(szStatStr, '(') + 1;
	t = strchr (szStatStr, ')');
	strncpy(pinfo.cmdname, s, t - s);
	pinfo.cmdname[t - s] = '\0';
	pinfo.currenttime = uTime;
	/*              1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 */
	sscanf(t + 2, "%c %d %d %d %d %d %u %u %u %u %u %d %d %d %d %d %d %u %u %u %u %u %u %u %u %u %u %u %d %d %d %d %u %u %u %d %d %u %u",
		&(pinfo.state),
		&(pinfo.ppid),
		&(pinfo.pgrp),
		&(pinfo.session),
		&(pinfo.tty),
		&(pinfo.tpgid),
		&(pinfo.flags),
		&(pinfo.minflt),
		&(pinfo.cminflt),
		&(pinfo.majflt),				// 10
		&(pinfo.cmajflt),
		&(pinfo.utime),
		&(pinfo.stime),
		&(pinfo.cutime),
		&(pinfo.cstime),
		&(pinfo.counter),
		&(pinfo.priority),
		&(pinfo.timeout),
		&(pinfo.itrealvalue),
		&(pinfo.starttime),				// 20
		&(pinfo.vsize),
		&(pinfo.rss),
		&(pinfo.rlim),
		&(pinfo.startcode),
		&(pinfo.endcode),
		&(pinfo.startstack),
		&(pinfo.kstkesp),
		&(pinfo.kstkeip),
		&(pinfo.signal),
		&(pinfo.blocked),				// 30
		&(pinfo.sigignore),
		&(pinfo.sigcatch),
		&(pinfo.wchan),
		&(pinfo.nswap),
		&(pinfo.cnswap),
		&(pinfo.exit_signal),
		&(pinfo.processor),
		&(pinfo.rt_priority),
		&(pinfo.policy)
		);
}

void CProbe::ShowProcInfo(procinfo_linux & pinfo)
{
	printf("  %d  %3d/%d %5d %5d   %3d %3d %10u K %8u K %s %3d:%02d %6.2f %-s\n",
		pinfo.processor,
		(const int)(pinfo.tty)/256,
		(const int)(pinfo.tty)%256,
		pinfo.pid,
		pinfo.uid,
		pinfo.counter,
		pinfo.priority,
		pinfo.vsize,
		pinfo.rss,
		pinfo.state,
		(const int)(pinfo.utime + pinfo.stime)/100/60,
		(const int)(pinfo.utime + pinfo.stime)/100%60,
		pinfo.cpuusage,
		pinfo.cmdname
		);

}

void CProbe::ScanCmd(char *pszFileName, procinfo &pinfo)
{
	if (!pszFileName)
		return;

	FILE *fpSrc;
	if (!(fpSrc = fopen(pszFileName, "r")))
		return;

	char szCmdLine[MAX_BUF_SIZE];
	memset(szCmdLine, 0x00, MAX_BUF_SIZE);
	int iRead = fread(szCmdLine, 1, MAX_BUF_SIZE-1, fpSrc);
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
			else if(strlen(pinfo.cmdline) + strlen(szCmdLine+i) < MAX_BUF_SIZE)
			{
				j++;
				if (strlen(pinfo.cmdline))
					strcat(pinfo.cmdline, " ");			// seperated the arguments by blanks
				if (j == 2)
					strncpy(pinfo.args, szCmdLine+i, MAX_PATH_LEN-1);	// get first argument

				strcat(pinfo.cmdline, szCmdLine+i);
				i += strlen(szCmdLine+i);
			}
			else
				break;
		}
	}
}

bool CProbe::ScanNetDev()
{
	char szFileName[] = "/proc/net/dev";
	char *p = NULL;
	FILE *fpSrc;

	if (!(fpSrc = fopen(szFileName, "r")))
	{
		printf("[ERROR]Failed to open \"%s\" !\n", szFileName);
		fflush(stdout);
		return false;
	}

	struct ifinfo
	{
		char name[8];
		unsigned int r_bytes, r_pkt, r_err, r_drop, r_fifo, r_frame;
		unsigned int r_compr, r_mcast;
		unsigned int x_bytes, x_pkt, x_err, x_drop, x_fifo, x_coll;
		unsigned int x_carrier, x_compr;
	}sifc  ;

	char szBuf[1024], szTmp[1024];
	fgets(szBuf, sizeof(szBuf), fpSrc);		// header
	fgets(szBuf, sizeof(szBuf), fpSrc);
	while (fgets(szBuf, sizeof(szBuf), fpSrc))
	{
		if ( sscanf(szBuf, " %6[^:]:%u %u %u %u %u %u %u %u %u %u %u %u %u %u %u\n",
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
			&sifc.x_compr) == 16 )
		{
			map < string, netinfo >::iterator mapIt;
			if ((mapIt = m_mapNetInfo.find(sifc.name)) != m_mapNetInfo.end())
			{
				mapIt->second.rcvpkgs  = sifc.r_pkt;
				mapIt->second.sndpkgs  = sifc.x_pkt;
				mapIt->second.rcvbytes = sifc.r_bytes;
				mapIt->second.sndbytes = sifc.x_bytes;
			}
		}
	}
	fclose(fpSrc);
	return true;
}

bool CProbe::GetNetwork()
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
#endif

	GetDateTime();
	sprintf(m_mObjectId,"%s.%s",m_mObjectName,HOSTATTRNET);

	static unsigned int uCount = 0;
	map < string, netinfo >::iterator mapIt;
	if (0 == m_mapNetInfo.size())		// 尝试刷新网卡状态(UP/DOWN)
	{
		GetNetCardInfo();
	}
	if (ScanNetDev())
	{
		for ( mapIt = m_mapNetInfo.begin();  mapIt != m_mapNetInfo.end(); mapIt++)
		{
#ifdef PRINT_DEBUG
			printf("LanName:%s %s %s\n%ld %ld %ld %ld\n",
				mapIt->second.name.c_str(),
				mapIt->second.state.c_str(),
				mapIt->second.ip.c_str(),
				mapIt->second.rcvpkgs,
				mapIt->second.sndpkgs,
				mapIt->second.rcvbytes,
				mapIt->second.sndbytes
				);
#endif
		}

		SaveSysNetWorkInfo();
		
		return true;
	}
	else
	{
		return false;
	}
}

bool CProbe::GetNetCardInfo()
{
	int fd, interface = 0;
	struct ifreq buf[MAX_LANHW_NUM];
	struct ifconf ifc;
	netinfo ninfo;

	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		return false;

	ifc.ifc_len = sizeof buf;
	ifc.ifc_buf = (caddr_t) buf;
	if (!ioctl(fd, SIOCGIFCONF, (char *) &ifc))
	{
		interface = ifc.ifc_len / sizeof(struct ifreq);
		char macaddr[32] = "";
		while (interface-- > 0)
		{
			ninfo.name = buf[interface].ifr_name;
			if (!(ioctl(fd, SIOCGIFFLAGS, (char *) &buf[interface])))
			{
				if (buf[interface].ifr_flags & IFF_PROMISC)			// Promisc
					ninfo.state = "Promisc";
				else if (buf[interface].ifr_flags & IFF_UP)			// Up
					ninfo.state = "Up";
				else		// Down
					ninfo.state = "Down";
			}
			else
			{
				continue;
			}
			/*Get IP of the net card */
			if (!(ioctl(fd, SIOCGIFADDR, (char *) &buf[interface])))
				ninfo.ip = inet_ntoa(((struct sockaddr_in *)(&buf[interface].ifr_addr))->sin_addr);
			else
				ninfo.ip = "0.0.0.0";
			/* Get Mask of the net card */
			if (!(ioctl(fd, SIOCGIFNETMASK, (char *) &buf[interface])))
				ninfo.mask = inet_ntoa(((struct sockaddr_in *)(&buf[interface].ifr_netmask))->sin_addr);
			else
				ninfo.mask = "255.0.0.0";
			/*Get GateWay ... can use SIOCGIFBRDADDR */

			/* Get MacAddr of the net card */
			if (!(ioctl(fd, SIOCGIFHWADDR, (char *) &buf[interface])))
			{
				sprintf(macaddr, "0x%02x%02x%02x%02x%02x%02x",
					(unsigned char) buf[interface].ifr_hwaddr.sa_data[0],
					(unsigned char) buf[interface].ifr_hwaddr.sa_data[1],
					(unsigned char) buf[interface].ifr_hwaddr.sa_data[2],
					(unsigned char) buf[interface].ifr_hwaddr.sa_data[3],
					(unsigned char) buf[interface].ifr_hwaddr.sa_data[4],
					(unsigned char) buf[interface].ifr_hwaddr.sa_data[5]);
				ninfo.mac = macaddr;
			}
			else
			{
				ninfo.mac = "";
			}
			// add info into map
			m_mapNetInfo[ninfo.name] = ninfo;
#ifdef PRINT_DEBUG
			printf("NetCard:%s\t%s\t%s\t%s\t%s\n", ninfo.name.c_str(), ninfo.state.c_str(), ninfo.ip.c_str(), ninfo.mask.c_str(), ninfo.mac.c_str());
#endif
		}//end of while
	}

	close(fd);
	
	return m_mapNetInfo.size() > 0 ? true:false ;
}

void CProbe::SetTimer(int nIDEvent, int nElapse)
{
	CEventHandler::SetTimer(nIDEvent, nElapse);
}

void CProbe::OnTimer(int nIDEvent)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	fflush(stdout);
#endif
	static int iTimes = 0;
	
	// 0:待命状态; 1:采集状态; 2:落地状态;

	if (g_nWorkFlag == 0)
	{
		return;
	}
	else if (g_nWorkFlag == 1)
	{
	  	if (nIDEvent == 1)
	  	{
	  		if(iTimes%m_iProcessSep == 0)
	  		{
#ifdef PRINT_DEBUG	  		
	  			printf("start GetProcessInfo\n");
#endif
	  			GetProcessInfo();
			}

			if(iTimes%m_iNetworkSep == 0)
			{
#ifdef PRINT_DEBUG			
	  			printf("start GetNetwork\n");
#endif
	  			GetNetwork();
			}

			if(iTimes%m_iCPUSep == 0)
	  		{
#ifdef PRINT_DEBUG	  		
	  			printf("start GetCPU\n");	  		
#endif
	  			GetCPU();
			}
			
			iTimes++;
	  	}
	}
	else
	{
		DumpCSV();
	}
}
 
void CProbe::DumpCSV()
{
#ifdef PRINT_DEBUG
	printf("%s enters, syscpuinfo.size=%d, sysnetwork.size=%d, appcpu.size=%d, appattr.size=%d\n"
		, __FUNCTION__, g_mSysCPUInfo.size(), g_mSysNetworkInfo.size(), g_mAppCPUInfo.size(), g_mAppAttrInfo.size());
#endif

	g_mWorkFlagMutex.Lock();

	STORE_DATA_ITERATOR cpu_it = g_mSysCPUInfo.begin();
	for(; cpu_it != g_mSysCPUInfo.end(); ++cpu_it)
	{
		char filepath[1024] = {0};
		SNPRINTF(filepath, sizeof(filepath), "%sCAP%02d_%s.%s.csv"
			, g_mDumpPath, g_nTouchCount/2, g_mTimeStamp, cpu_it->first.c_str());
		FILE * fp = fopen(filepath, "wb");
		if(fp)
		{	
			string linetitle = "Time,LOAD,USER,NICE,SYS,IDLE,BLOCK,SWAIT,INTR,SSYS\r\n";
			fwrite(linetitle.c_str(), 1, linetitle.length(), fp);	
			fflush(fp);
			
			map<string,string>::iterator c_it = cpu_it->second.begin();
			for(; c_it != cpu_it->second.end(); ++c_it)
			{
				string linecontent = c_it->first;
				linecontent += ",";
				linecontent += c_it->second;
				linecontent += "\r\n";
				
				fwrite(linecontent.c_str(), 1, linecontent.length(), fp);	
				fflush(fp);
			}

			fclose(fp);
		}
	}

	STORE_DATA_ITERATOR net_it = g_mSysNetworkInfo.begin();
	for(; net_it != g_mSysNetworkInfo.end(); ++net_it)
	{
		char filepath[1024] = {0};
		SNPRINTF(filepath, sizeof(filepath), "%sCAP%02d_%s.%s.csv"
			, g_mDumpPath, g_nTouchCount/2, g_mTimeStamp, net_it->first.c_str());
		FILE * fp = fopen(filepath, "wb");
		if(fp)
		{	
			string linetitle = "Time,rcvpkgs,sndpkgs,rcvbytes,sndbytes\r\n";
			fwrite(linetitle.c_str(), 1, linetitle.length(), fp);	
			fflush(fp);
			
			map<string,string>::iterator c_it = net_it->second.begin();
			for(; c_it != net_it->second.end(); ++c_it)
			{
				if(c_it == net_it->second.begin())
				{
					//第一条统计信息没意义，丢弃
					continue;
				}
				
				string linecontent = c_it->first;
				linecontent += ",";
				linecontent += c_it->second;
				linecontent += "\r\n";
				
				fwrite(linecontent.c_str(), 1, linecontent.length(), fp);	
				fflush(fp);
			}

			fclose(fp);
		}
	}
	
	STORE_DATA_ITERATOR acpu_it = g_mAppCPUInfo.begin();
	for(; acpu_it != g_mAppCPUInfo.end(); ++acpu_it)
	{
		char filepath[1024] = {0};
		SNPRINTF(filepath, sizeof(filepath), "%sCAP%02d_%s.%s.csv"
			, g_mDumpPath, g_nTouchCount/2, g_mTimeStamp, acpu_it->first.c_str());
		FILE * fp = fopen(filepath, "wb");
		if(fp)
		{	
			string linetitle = "Time,CPUUsage\r\n";
			fwrite(linetitle.c_str(), 1, linetitle.length(), fp);	
			fflush(fp);
			
			map<string,string>::iterator c_it = acpu_it->second.begin();
			for(; c_it != acpu_it->second.end(); ++c_it)
			{
				string linecontent = c_it->first;
				linecontent += ",";
				linecontent += c_it->second;
				linecontent += "\r\n";
				
				fwrite(linecontent.c_str(), 1, linecontent.length(), fp);	
				fflush(fp);
			}

			fclose(fp);
		}
	}	
	
	STORE_DATA_ITERATOR aa_it = g_mAppAttrInfo.begin();
	for(; aa_it != g_mAppAttrInfo.end(); ++aa_it)
	{
		char filepath[1024] = {0};
		SNPRINTF(filepath, sizeof(filepath), "%sCAP%02d_%s.%s.csv"
			, g_mDumpPath, g_nTouchCount/2, g_mTimeStamp, aa_it->first.c_str());
		FILE * fp = fopen(filepath, "wb");
		if(fp)
		{	
			string linetitle = "Time,AttrValue\r\n";
			fwrite(linetitle.c_str(), 1, linetitle.length(), fp);	
			fflush(fp);
			
			map<string,string>::iterator c_it = aa_it->second.begin();
			for(; c_it != aa_it->second.end(); ++c_it)
			{
				string linecontent = c_it->first;
				linecontent += ",";
				linecontent += c_it->second;
				linecontent += "\r\n";
				
				fwrite(linecontent.c_str(), 1, linecontent.length(), fp);	
				fflush(fp);
			}

			fclose(fp);
		}
	}	
	g_nWorkFlag = 0;

	g_mSysCPUInfo.clear();
	g_mSysNetworkInfo.clear();
	g_mAppCPUInfo.clear();
	g_mAppAttrInfo.clear();

	g_mWorkFlagMutex.UnLock();
}

void CProbe::SaveSysCPUInfo()
{
	time_t curtime = time(NULL);
	char szDatetime[100] = {0};
	strftime(szDatetime, sizeof(szDatetime), "%H:%M:%S", (const tm *)localtime(&curtime));
	
	for(int i = 0; i <= m_mCpuNum; i ++)
	{
		char keystr[100] = {0};
		SNPRINTF(keystr, sizeof(keystr), "os.%s.cpu.%s", g_pHostName, (const char *)m_cCpuInfo[i].CPU);

		char cpuinfo[1024] = {0};
		SNPRINTF(cpuinfo, sizeof(cpuinfo), "%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f",
			(const double)m_cCpuInfo[i].LOAD ,
			(const double)m_cCpuInfo[i].USER ,
			(const double)m_cCpuInfo[i].NICE ,
			(const double)m_cCpuInfo[i].SYS  ,
			(const double)m_cCpuInfo[i].IDLE ,
			(const double)m_cCpuInfo[i].BLOCK,
			(const double)m_cCpuInfo[i].SWAIT,
			(const double)m_cCpuInfo[i].INTR ,
			(const double)m_cCpuInfo[i].SSYS );

		STORE_DATA_ITERATOR s_it = g_mSysCPUInfo.find(keystr);
		if(s_it == g_mSysCPUInfo.end())
		{
			map<string, string> cpumap;
			cpumap[szDatetime] = cpuinfo;

			g_mSysCPUInfo[keystr] = cpumap;
		}
		else
		{
			s_it->second[szDatetime] = cpuinfo;
		}			
	}
}

void CProbe::SaveSysNetWorkInfo()
{
	time_t curtime = time(NULL);
	char szDatetime[100] = {0};
	strftime(szDatetime, sizeof(szDatetime), "%H:%M:%S", (const tm *)localtime(&curtime));
	
	map < string, netinfo >::iterator mapIt;
	for ( mapIt = m_mapNetInfo.begin();  mapIt != m_mapNetInfo.end(); mapIt++)
	{
		char keystr[1024] = {0};
		SNPRINTF(keystr, sizeof(keystr), "os.%s.network.%s", g_pHostName, mapIt->first.c_str());

		//增量数据
		int inc_rcvpkgs, inc_sndpkgs, inc_rcvbytes, inc_sndbytes;
		
		map < string, netinfo >::iterator mapLastIt = m_mapLastNetInfo.find(mapIt->first);
		if(mapLastIt != m_mapLastNetInfo.end())
		{
			//非第一次采样
			inc_rcvpkgs = mapIt->second.rcvpkgs - mapLastIt->second.rcvpkgs;
			inc_sndpkgs = mapIt->second.sndpkgs - mapLastIt->second.sndpkgs;
			inc_rcvbytes = mapIt->second.rcvbytes - mapLastIt->second.rcvbytes;
			inc_sndbytes = mapIt->second.sndbytes - mapLastIt->second.sndbytes;

			char netinfo[1024] = {0};
			SNPRINTF(netinfo, sizeof(netinfo), "%ld,%ld,%ld,%ld"
				, inc_rcvpkgs, inc_sndpkgs,inc_rcvbytes,inc_sndbytes);

			STORE_DATA_ITERATOR s_it = g_mSysNetworkInfo.find(keystr);
			if(s_it == g_mSysNetworkInfo.end())
			{
				map<string, string> networkmap;
				networkmap[szDatetime] = netinfo;

				g_mSysNetworkInfo[keystr] = networkmap;
			}
			else
			{
				s_it->second[szDatetime] = netinfo;
			}			
		}

		//更新上次网络信息
		m_mapLastNetInfo[mapIt->first] = mapIt->second;
	}
}

void CProbe::SaveAppProcessInfo(procinfo_linux & pinfo)
{
	//记录app占用的cpu信息
	char keystr[1024] = {0};
	SNPRINTF(keystr, sizeof(keystr), "app.%s.%d.CPUUsage", pinfo.cmdname, atoi(pinfo.args));

	time_t curtime = time(NULL);
	
	char szDatetime[100] = {0};
	strftime(szDatetime, sizeof(szDatetime), "%H:%M:%S", (const tm *)localtime(&curtime));

	char cpuusage[100] = {0};
	SNPRINTF(cpuusage, sizeof(cpuusage), "%0.2f", pinfo.cpuusage);

	STORE_DATA_ITERATOR s_it = g_mAppCPUInfo.find(keystr);
	if(s_it == g_mAppCPUInfo.end())
	{
		map<string, string> cpumap;
		cpumap[szDatetime] = cpuusage;

		g_mAppCPUInfo[keystr] = cpumap;
	}
	else
	{
		s_it->second[szDatetime] = cpuusage;
	}
}

#endif	// LINUX
