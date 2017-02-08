#include "NetworkInfo.h"
#include "public.h"
#include "OSSpiImpl.h"
#include "SyslogSpiImpl.h"

#ifdef HP_UX
extern map<string, long> g_mAppNamePidMap;		// 应用进程名 - 应用进程的ID
extern map<string, string>	g_mSpcPrcMap;		// 应用进程名 - 进程所在分区 映射图
extern char *g_szHostEnvFile;					// 主机环境配置文件名
extern char *g_szNetConfFile;					// 网络配置文件名
extern char g_pHostName[32];					// 保存主机名称
extern char g_pDataCenterName[32];				// 保存数据中心名称
extern CManageConSession g_mManageConSession;	// 保存所有连接的地址信息
extern bool g_sendEvnFlag;

const char	g_szProcState[][8] =
{
	"idl*",
	"sleep",
	"run",
	"stop",
	"zomb",
	"wait*",
	NULL
};	// 进程状态描述

// 注意：其中"idl*"及"wait*"两项位置待定
bool COperatorSystemSpiImpl::GetLanCfg(void)
{
	FILE *fpSrc;
	int iNum;

	//if(g_szNetConfFile == NULL || !(fpSrc = fopen(g_szNetConfFile, "r")))
	//	return false;
	if (g_szNetConfFile == NULL)
	{
		return false;
	}

	CFileOCGuard<> guard(g_szNetConfFile, "r");
	fpSrc = guard.GetFileHandle();

	char szBuf[BLOCK_SIZE];

	char szTmp[BLOCK_SIZE_M];

	m_iLanCfg = -1;
	iNum = -1;
	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRENV);

	memset(szBuf, 0x00, sizeof(szBuf));
	while (fgets(szBuf, BLOCK_SIZE, fpSrc))
	{
		if (szBuf[0] == '#' || strlen(szBuf) < 2)
		{
			continue;	// 忽略空行及注释行
		}

		m_cLanCfg[m_iLanCfg].HostName = m_mObjectId;
		m_cLanCfg[m_iLanCfg].MonDate = m_mDate;
		m_cLanCfg[m_iLanCfg].MonTime = m_mTime;

		memset(szTmp, 0x00, sizeof(szTmp));
		memset(szBuf + strlen(szBuf) - 1, 0x00, 1); // 去除行尾换行符
		char *p = strrchr(szBuf, '"');
		if (p != NULL)
		{
			*p = '\0';
		}

		p = strrchr(szBuf, '"');
		if (p != NULL)
		{
			*p = ' ';
		}

		if (!memcmp(szBuf, LANNAME_TIP, strlen(LANNAME_TIP)))
		{
			iNum = atoi(szBuf + strlen(LANNAME_TIP) + 1);
			strcpy(szTmp, SeekChar(szBuf, EQUAL_FLAG));
			m_cLanCfg[iNum].LanName = szTmp;
			m_iLanCfg = iNum > m_iLanCfg ? iNum : m_iLanCfg;
		}
		else if (!memcmp(szBuf, LANIP_TIP, strlen(LANIP_TIP)))
		{
			iNum = atoi(szBuf + strlen(LANIP_TIP) + 1);
			strcpy(szTmp, SeekChar(szBuf, EQUAL_FLAG));
			m_cLanCfg[iNum].IpAddress = szTmp;
		}
		else if (!memcmp(szBuf, LANMASK_TIP, strlen(LANMASK_TIP)))
		{
			iNum = atoi(szBuf + strlen(LANMASK_TIP) + 1);
			strcpy(szTmp, SeekChar(szBuf, EQUAL_FLAG));
			m_cLanCfg[iNum].IpMask = szTmp;
		}
	}

	if (m_iLanCfg >= 0)
	{
		m_iLanCfg++;
	}

	if (m_iLanCfg)
	{
		for (int i = 0; i < m_iLanCfg; i++)
		{
			m_LanIPMap[(char *)(m_cLanCfg[i].LanName.getValue())] = (char *)(m_cLanCfg[i].IpAddress.getValue());
		}

		return true;
	}
	else
	{
		return false;
	}
}

bool COperatorSystemSpiImpl::GetMemory(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif

	pst_dynamic psd;

	if (m_mPageSize == 0)
	{
		pst_static	pst;
		if (pstat_getstatic(&pst, sizeof(pst), (size_t) 1, 0) == -1)
		{
			return false;
		}

		m_mPageSize = pst.page_size;
		m_mMemory = pst.physical_memory * m_mPageSize / DISK_BASIC_UNIT;		// MB
	}

	if (pstat_getdynamic(&psd, sizeof(psd), (size_t) 1, 0) == -1)
	{
		return false;
	}

	m_cMemInfo.TOTALREAL = (psd.psd_rm * m_mPageSize / MEMORY_BASIC_UNIT);		/* total real memory */
	m_cMemInfo.ACTIVEREAL = (psd.psd_arm * m_mPageSize / MEMORY_BASIC_UNIT);	/* active real memory */
	m_cMemInfo.TOTALVIRTUAL = (psd.psd_vm * m_mPageSize / MEMORY_BASIC_UNIT);	/* total virtual memory */
	m_cMemInfo.ACTIVEVIRTUAL = (psd.psd_avm * m_mPageSize / MEMORY_BASIC_UNIT); /* active virtual memory */
	m_cMemInfo.FREE = (psd.psd_free * m_mPageSize / MEMORY_BASIC_UNIT);			/* free memory pages */

	return true;
}

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

	int i;
	if ((m_bGetManifest = GetHostEnv()))
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &m_cCommon);

		// Mod by Henchi, 20100223
				/// 当会话为空时，向所有连接发送环境信息；否则仅向单个会话发送
		if (pSession != NULL)
		{
			pSession->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			OSSENDPACKAGETO;
		}

#ifdef PRINT_DEBUG
		printf(
			"PacketSend Type: HostEnvCommon    length: %d \n",
			m_pkgSend.Length());
#endif
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (i = 0; i < m_iLan; i++)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &m_cLan[i]);
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

#ifdef PRINT_DEBUG
		printf(
			"PacketSend Type: HostEnvLan    length: %d \n",
			m_pkgSend.Length());
#endif
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (i = 0; i < m_iStorage; i++)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &m_cStorage[i]);
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

#ifdef PRINT_DEBUG
		printf(
			"PacketSend Type: HostEnvStorage    length: %d \n",
			m_pkgSend.Length());
#endif
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (i = 0; i < m_iIO; i++)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &m_cIO[i]);
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

#ifdef PRINT_DEBUG
		printf(
			"PacketSend Type: HostEnvIO    length: %d \n",
			m_pkgSend.Length());
#endif
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (i = 0; i < m_iFS; i++)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &m_cFS[i]);
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

#ifdef PRINT_DEBUG
		printf(
			"PacketSend Type: HostEnvFS    length: %d \n",
			m_pkgSend.Length());
#endif
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (i = 0; i < m_iSwap; i++)
		{
			FTDC_ADD_FIELD(&m_pkgSend, &m_cSwap[i]);
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

#ifdef PRINT_DEBUG
		printf(
			"PacketSend Type: HostEnvSwap    length: %d \n",
			m_pkgSend.Length());
#endif
	}

	if ((m_bGetLanCfg = GetLanCfg()))
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHostEnvTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		for (i = 0; i < m_iLanCfg; i++)
		{
			if (strlen(m_cLanCfg[i].LanName.getValue()))
			{
				FTDC_ADD_FIELD(&m_pkgSend, &m_cLanCfg[i]);
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

#ifdef PRINT_DEBUG
		printf(
			"PacketSend Type: HostEnvLanCfg    length: %d \n",
			m_pkgSend.Length());
#endif
	}

	g_sendEvnFlag = true;
}

bool COperatorSystemSpiImpl::GetHostEnv(void)
{
	if (g_szHostEnvFile == NULL || access(g_szHostEnvFile, R_OK) != 0)
	{
		return false;
	}

	int iCount;

	int iRtn;
	char szBuf[BLOCK_SIZE];
	char *p;

	int iProcs;
	char szModel[BLOCK_SIZE_M];
	char szMemory[BLOCK_SIZE_S];
	char szOSMode[BLOCK_SIZE_M];
	char szLanHWs[BLOCK_SIZE];
	char szStorage[MAX_STOR_NUM * BLOCK_SIZE];
	char szIFs[
			MAX_IFS_NUM * BLOCK_SIZE];
	char szFSLs[MAX_FSLRC_NUM * BLOCK_SIZE];
	char szSCs[MAX_SCRC_NUM * BLOCK_SIZE];
	char szHostName[BLOCK_SIZE_S];
	char szIP[BLOCK_SIZE_S];
	char szMask[BLOCK_SIZE_S];

	memset(szModel, 0x00, sizeof(szModel));
	memset(szMemory, 0x00, sizeof(szMemory));
	memset(szOSMode, 0x00, sizeof(szOSMode));
	memset(szLanHWs, 0x00, sizeof(szLanHWs));
	memset(szStorage, 0x00, sizeof(szStorage));
	memset(szIFs, 0x00, sizeof(szIFs));
	memset(szFSLs, 0x00, sizeof(szFSLs));
	memset(szSCs, 0x00, sizeof(szSCs));
	memset(szHostName, 0x00, sizeof(szHostName));
	memset(szIP, 0x00, sizeof(szIP));
	memset(szMask, 0x00, sizeof(szMask));

	iRtn = ReadManifest(
			g_szHostEnvFile,
			szModel,
			szMemory,
			&iProcs,
			szOSMode,
			szLanHWs,
			&m_iLan,
			szStorage,
			&m_iStorage,
			szIFs,
			&m_iIO,
			szFSLs,
			&m_iFS,
			szSCs,
			&m_iSwap,
			szHostName,
			szIP,
			szMask);
	if (iRtn >= 0)
	{
		sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRENV);

		m_cCommon.HostName = m_mObjectId;
		m_cCommon.MonDate = m_mDate;
		m_cCommon.MonTime = m_mTime;
		m_cCommon.HostModel = szModel;

		// Mod by Henchi 20090617
		// 发送由系统接口获取的物理内存值，而非manifest文件中的
		//m_cCommon.MainMemory = atol(szMemory)		;
		m_cCommon.MainMemory = m_mMemory;						// MB
		m_cCommon.Processors = iProcs;
		m_cCommon.OsMode = atol(szOSMode);

		m_cLan[0].HostName = m_mObjectId;
		m_cLan[0].MonDate = m_mDate;
		m_cLan[0].MonTime = m_mTime;
		m_cLan[0].LanHardwareID = "lan0";
		m_cLan[0].LanHardwareValue = strtok(szLanHWs, SEP_CHAR);
		for (iCount = 1; iCount < m_iLan; iCount++)
		{
			m_cLan[iCount].HostName = m_mObjectId;
			m_cLan[iCount].MonDate = m_mDate;
			m_cLan[iCount].MonTime = m_mTime;
			sprintf((char *) &m_cLan[iCount].LanHardwareID, "lan%d", iCount);
			m_cLan[iCount].LanHardwareValue = strtok(NULL, SEP_CHAR);
		}

		for (p = szStorage, iCount = 0;
			 iCount < m_iStorage;
			 p += BLOCK_SIZE, iCount++)
		{
			m_cStorage[iCount].HostName = m_mObjectId;
			m_cStorage[iCount].MonDate = m_mDate;
			m_cStorage[iCount].MonTime = m_mTime;
			m_cStorage[iCount].StorageDev = strtok(p, SEP_CHAR);
			m_cStorage[iCount].HWPath = strtok(NULL, SEP_CHAR);
			m_cStorage[iCount].Interface = strtok(NULL, SEP_CHAR);
		}

		for (p = szIFs, iCount = 0; iCount < m_iIO; p += BLOCK_SIZE, iCount++)
		{
			m_cIO[iCount].HostName = m_mObjectId;
			m_cIO[iCount].MonDate = m_mDate;
			m_cIO[iCount].MonTime = m_mTime;
			m_cIO[iCount].IoClass = strtok(p, SEP_CHAR);
			m_cIO[iCount].H_WPath = strtok(NULL, SEP_CHAR);
			m_cIO[iCount].IoDriver = strtok(NULL, SEP_CHAR);
			m_cIO[iCount].IoDescription = strtok(NULL, SEP_CHAR);
		}

		for (p = szFSLs, iCount = 0; iCount < m_iFS; p += BLOCK_SIZE, iCount++)
		{
			m_cFS[iCount].HostName = m_mObjectId;
			m_cFS[iCount].MonDate = m_mDate;
			m_cFS[iCount].MonTime = m_mTime;
			m_cFS[iCount].LVMDeviceFile = strtok(p, SEP_CHAR);
			m_cFS[iCount].MountPoint = strtok(NULL, SEP_CHAR);
			m_cFS[iCount].FSsize = atol(strtok(NULL, SEP_CHAR));
			m_cFS[iCount].FSType = strtok(NULL, SEP_CHAR);
		}

		for (p = szSCs, iCount = 0; iCount < m_iSwap; p += BLOCK_SIZE, iCount++)
		{
			m_cSwap[iCount].HostName = m_mObjectId;
			m_cSwap[iCount].MonDate = m_mDate;
			m_cSwap[iCount].MonTime = m_mTime;
			m_cSwap[iCount].type = strtok(p, SEP_CHAR);
			m_cSwap[iCount].size = atol(strtok(NULL, SEP_CHAR));
			m_cSwap[iCount].priority = atol(strtok(NULL, SEP_CHAR));
			m_cSwap[iCount].location = strtok(NULL, SEP_CHAR);
		}

		//m_cLanCfg.LanName	= szHostName;
		//m_cLanCfg.IpAddress	= szIP		;
		//m_cLanCfg.IpMask	= szMask	;
		return true;
	}

	return false;
}

bool COperatorSystemSpiImpl::GetProcessInfo(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	GetDateTime();

	/* Processes Start */
	static const size_t BURST = 10;
	char szApp[MAX_NAMELEN] = "";
	pst_status	pst[BURST];
	int idx = 0;
	int count;
	int iArg;

	if (!NewProcList())
	{
		return false;
	}

	sProcInfo *pProcTmp = (sProcInfo *)malloc(sizeof(sProcInfo));
	if (!pProcTmp)
	{
		return false;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_cObjectAttr.MonDate = m_mDate;
	m_cObjectAttr.MonTime = m_mTime;
	m_cObjectAttr.ValueType = PERCENT_ATTR;

	while ((count = pstat_getproc(pst, sizeof(pst[1]), BURST, idx)) > 0)
	{
		for (int i = 0; i < count; ++i)
		{
			if (IsSpcProc(pst[i].pst_ucomm))					//属于特别关注进程
			{
				if (iArg = GetProcArgValue(pst[i].pst_cmd))
				{
					sprintf(
						m_mAppId,
						"%s.%s.%d",
						m_mAppName,
						pst[i].pst_ucomm,
						iArg);
					sprintf(szApp, "%s.%d", pst[i].pst_ucomm, iArg);
				}
				else
				{
					sprintf(m_mAppId, "%s.%s", m_mAppName, pst[i].pst_ucomm);
					sprintf(szApp, "%s", pst[i].pst_ucomm);
				}

				// Added by Henchi 20081126 针对新产生的业务进程发送相关变更信息
				if (g_mAppNamePidMap.find(
						string(szApp)) == g_mAppNamePidMap.end())
				{
					SendUpdateSyscfgPkg(
						(const char *)g_pHostName,
						(const char *)szApp);
				}

				g_mAppNamePidMap[string(szApp)] = pst[i].pst_pid;
				m_lSpcProc.push_back(string(szApp));

				/*****
				if(!IsSpcProc(szApp))
				continue;
				*/
				m_cObjectAttr.ObjectID = m_mAppId;

				m_cObjectAttr.AttrType = APPATTRCPUUSAGE;
				sprintf(
					(char *)(m_cObjectAttr.AttrValue.getValue()),
					"%.2f",
					pst[i].pst_pctcpu * 100);
				SAFEADDOBJATTRFIELD;

				m_cObjectAttr.AttrType = APPATTRMEMORYUSAGE;
				sprintf(
					(char *)(m_cObjectAttr.AttrValue.getValue()),
					"%.2f",
					GetProcMemUsage(&pst[i]));
				SAFEADDOBJATTRFIELD;

				m_cObjectAttr.AttrType = APPATTRDISKUSAGE;
				sprintf(
					(char *)(m_cObjectAttr.AttrValue.getValue()),
					"%.2f",
					GetDiskUsage((char *)g_mSpcPrcMap[szApp].c_str()));
				SAFEADDOBJATTRFIELD;
			}

			if (m_iListLen < MAX_PROC_NUM
			||	(pst[i].pst_pctcpu * 100) > m_pListTail->pCpu)	//加入链表
			{
				pProcTmp->Cpu = pst[i].pst_procnum;
				pProcTmp->TtyMajor = pst[i].pst_term.psd_major;
				pProcTmp->TtyMinor = pst[i].pst_term.psd_minor;
				pProcTmp->Pid = pst[i].pst_pid;
				pProcTmp->Uid = pst[i].pst_uid;
				pProcTmp->Pri = pst[i].pst_pri;
				pProcTmp->Nice = pst[i].pst_nice;
				pProcTmp->Size = (INT64)
					(
						(
							pst[i].pst_vtsize +
							pst[i].pst_vdsize +
							pst[i].pst_vssize +
							pst[i].pst_vshmsize +
							pst[i].pst_vmmsize +
							pst[i].pst_vusize +
							pst[i].pst_viosize
						) * m_mPageSize / MEMORY_BASIC_UNIT
					);
				pProcTmp->Res = (INT64) (pst[i].pst_rssize * m_mPageSize / MEMORY_BASIC_UNIT);
				pProcTmp->State = pst[i].pst_stat;
				pProcTmp->Time = pst[i].pst_utime + pst[i].pst_stime;
				pProcTmp->pWCpu = pst[i].pst_pctcpu * 100;
				pProcTmp->pCpu = pst[i].pst_pctcpu * 100;
				pProcTmp->Cmd[0] = 0x00;
				strcpy(pProcTmp->Cmd, pst[i].pst_cmd);
				pProcTmp->UCmd[0] = 0x00;
				strcpy(pProcTmp->UCmd, pst[i].pst_ucomm);
				pProcTmp->Next = NULL;

				if (NULL == (pProcTmp = AppendList(pProcTmp)))
				{
					return false;
				}
			}
			else
			{	//无用进程信息，不作处理
				continue;
			}
		}

		idx = pst[count - 1].pst_idx + 1;
	}

	free(pProcTmp);

	OSSENDPACKAGETO;

	FixProcInfo();
	return true;
}

bool COperatorSystemSpiImpl::NewGetNetwork(void)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	GetDateTime();
	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRNET);

	m_pkgSend.PreparePackage(
			FTD_TID_RtnNetworkInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnNetworkInfoField field;

	CNetworkInfo info;
	info.GetNetworkInfo();

	field.HostName = m_mObjectId;
	field.MonTime = m_mTime;
	field.MonDate = m_mDate;

	map<string, NetStat>::iterator	it;
	map<string, string>::iterator tmpIt;
	for (it = info.m_LanStat.begin(); it != info.m_LanStat.end(); ++it)
	{
		tmpIt = m_LanIPMap.find(it->first);
		if (tmpIt == m_LanIPMap.end() || tmpIt->second.empty())
		{
			// 无匹配的IP配置项，跳过该网卡项
			continue;
		}

		field.LANNAME = it->first.c_str();
		field.IPADDRESS = (const char *)tmpIt->second.c_str();
		field.LANSTATUS = it->second.status.c_str();
		field.SENDBYTES = it->second.outOctets;
		field.RECVBYTES = it->second.inOctets;
		field.RECVPACKETS = it->second.inPkts;
		field.SENDPACKETS = it->second.outPkts;
#ifdef PRINT_DEBUG
		printf("\n	%s\n", (const char *)field.IPADDRESS);
		printf("	%s\n", (const char *)field.LANNAME);
		printf("	%s\n", (const char *)field.LANSTATUS);
		printf("	%lf\n", (const double)field.SENDPACKETS);
		printf("	%lf\n", (const double)field.SENDBYTES);
		printf("	%lf\n", (const double)field.RECVPACKETS);
		printf("	%lf\n\n", (const double)field.RECVBYTES);
#endif
		if (m_pkgSend.Length() + sizeof(field) > FTDC_PACKAGE_MAX_SIZE)
		{
			m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
			OSSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);
	}

	OSSENDPACKAGETO;
	return true;
}

// 以下为HP_UX专属段
int COperatorSystemSpiImpl::GetProcArgValue(char *pCmd)
{
	char szBuf[64];

	if (!pCmd)
	{
		return -1;
	}

	strcpy(szBuf, pCmd);
	strtok(szBuf, " ");
	return atoi(strtok(NULL, " "));
}

float COperatorSystemSpiImpl::GetProcMemUsage(pst_status *pst)
{
	int iMem;
	if (m_mMemory && m_mPageSize)
	{
		iMem =
			(
				(
					pst->pst_vtsize +
					pst->pst_vdsize +
					pst->pst_vssize +
					pst->pst_vshmsize +
					pst->pst_vmmsize +
					pst->pst_vusize
				) *
				m_mPageSize /
				DISK_BASIC_UNIT
			);
		return ((float)iMem * 100 / m_mMemory);
	}

	return 0;
}

bool COperatorSystemSpiImpl::InitProcList(void)
{
	m_pListHead = (sProcInfo *)malloc(sizeof(sProcInfo));
	if (!m_pListHead)
	{
		return false;
	}

	m_pListHead->pCpu = 0.0;
	m_pListHead->Next = NULL;
	m_pListTail = m_pListHead;
	m_iListLen = 1;
	return true;
}

void COperatorSystemSpiImpl::DropProcList(void)
{
	sProcInfo *pstDrop;

	sProcInfo *pstCur;

	if (m_pListHead != NULL)
	{
		pstDrop = pstCur = m_pListHead;
		while (pstDrop->Next != NULL)
		{
			pstCur = pstDrop->Next;
			free(pstDrop);
			pstDrop = pstCur;
		}

		free(pstDrop);
	}

	m_pListHead = NULL;
	m_pListTail = NULL;
	m_iListLen = 0;
}

bool COperatorSystemSpiImpl::NewProcList(void)
{
	DropProcList();
	return InitProcList();
}

sProcInfo *COperatorSystemSpiImpl::AppendList(sProcInfo *pProcTmp)
{
	sProcInfo *pPos = m_pListHead;

	if (pProcTmp->pCpu > m_pListHead->pCpu) //节点添加为新表头
	{
		pProcTmp->Next = m_pListHead;
		m_pListHead = pProcTmp;
	}
	else	//节点添加为表中节点(不可能为表尾)
	{
		while (pProcTmp->pCpu < pPos->Next->pCpu && pPos->Next != NULL)
		{
			pPos = pPos->Next;
		}

		pProcTmp->Next = pPos->Next;
		pPos->Next = pProcTmp;
	}

	if (m_iListLen < MAX_PROC_NUM)					//因为链表未满而加入链表
	{
		m_iListLen++;								//改变链表长度,表尾不变
		return (sProcInfo *)malloc(sizeof(sProcInfo));

		//返回新节点指针用作数据缓冲
	}

	//表已满，但因为节点值>尾节点值,替入链表，其当前位置为表中
	while (pPos->Next != m_pListTail)
	{
		pPos = pPos->Next;
	}

	m_pListTail = pPos;								//新的表尾节点为原表尾节点的前续节点
	pPos = pPos->Next;
	m_pListTail->Next = NULL;

	return pPos;									//返回原表尾节点指针用作数据缓冲
}

void COperatorSystemSpiImpl::FixProcInfo(void)
{
	sProcInfo *pPos;

	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRPROCESS);
	m_pkgSend.PreparePackage(
			FTD_TID_RtnTopProcessInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_cProcInfo.HostName = m_mObjectId;
	m_cProcInfo.MonDate = m_mDate;
	m_cProcInfo.MonTime = m_mTime;

	for (pPos = m_pListHead; pPos != NULL; pPos = pPos->Next)
	{
		sprintf((char *) &m_cProcInfo.CPU, "%ld", pPos->Cpu);
		if (pPos->TtyMajor <= 0)
		{
			m_cProcInfo.TTY = "?";
		}
		else
		{
			sprintf((char *) &m_cProcInfo.TTY, "pts/%ld", pPos->TtyMinor);
		}

		m_cProcInfo.PID = pPos->Pid;
		m_cProcInfo.USERNAME = GetUserName(pPos->Uid).c_str();
		m_cProcInfo.PRI = pPos->Pri;
		m_cProcInfo.NI = pPos->Nice;
		m_cProcInfo.SIZE = pPos->Size;
		m_cProcInfo.RES = pPos->Res;
		m_cProcInfo.STATE = g_szProcState[pPos->State];
		sprintf(
			(char *) &m_cProcInfo.TIME,
			"%ld:%ld",
			pPos->Time / 60,
			pPos->Time % 60);
		m_cProcInfo.pWCPU = pPos->pWCpu;
		m_cProcInfo.pCPU = pPos->pCpu;
		m_cProcInfo.COMMAND = pPos->UCmd;

		FTDC_ADD_FIELD(&m_pkgSend, &m_cProcInfo);
	}

	OSSENDPACKAGETO;
#ifdef PRINT_DEBUG
	printf(
		"PacketSend Type: TopProcessInfo   Length: %d \n",
		m_pkgSend.Length());
#endif
}

int COperatorSystemSpiImpl::ReadManifest(
	char *psPath,
	char *psModel,
	char *psMemory,
	int *piProcs,
	char *psOSMode,
	char *psLanHWs,
	int *piLanNum,
	char *psStorage,
	int *piStorNum,
	char *psIFs,
	int *piIFNum,
	char *psFSLs,
	int *piFSLNum,
	char *psSCs,
	int *piSCNum,
	char *psHostName,
	char *psIP,
	char *psMask)
{
	int iLen;

	int iState;

	int iRtn;
	char *p;
	char szBuf[BLOCK_SIZE];
	FILE *fpSrc;

	if (!psPath
	||	!psModel
	||	!psMemory
	||	!piProcs
	||	!psOSMode
	||	!psLanHWs
	||	!piLanNum
	||	!psStorage
	||	!piStorNum
	||	!psIFs
	||	!piIFNum
	||	!psFSLs
	||	!piFSLNum
	||	!psSCs
	||	!piSCNum
	||	!psHostName
	||	!psIP
	||	!psMask)
	{
		return -1;
	}

	//if(!(fpSrc = fopen(psPath, "r")))
	CFileOCGuard<> guard(psPath, "r");
	fpSrc = guard.GetFileHandle();
	if (!fpSrc)
	{
		return -2;
	}

	iState = 0;
	*piProcs = 0;
	*piLanNum = 0;
	*piStorNum = 0;
	*piIFNum = 0;
	*piFSLNum = 0;
	*piSCNum = 0;
	memset(szBuf, 0x00, sizeof(szBuf));
	while (fgets(szBuf, BLOCK_SIZE, fpSrc))
	{
		if ((iLen = strlen(szBuf)) < 2)				// 读到空行
		{
			continue;
		}

		/* System Hardware */
		if (HW_TIP_LEN == iLen && !memcmp(szBuf, HW_TIP, strlen(HW_TIP)))
		{
			while (fgets(szBuf, BLOCK_SIZE, fpSrc))
			{
				szBuf[strlen(szBuf) - 1] = 0x00;	// 除去行尾换行符(BUF足够大)

				/* MODEL */
				if (!memcmp(szBuf, MODEL_TIP, strlen(MODEL_TIP)))
				{
					GetInfo(psModel, szBuf);
				}

				/* Main Memory */
				else if (!memcmp(szBuf, MMEM_TIP, strlen(MMEM_TIP)))
				{
					GetInfo(psMemory, szBuf);
				}

				/* Processors */
				else if (!memcmp(szBuf, PROC_TIP, strlen(PROC_TIP)))
				{
					*piProcs = atoi(SeekChar(szBuf, COLON_FLAG));
				}

				/* OS mode */
				else if (!memcmp(szBuf, OSMOD_TIP, strlen(OSMOD_TIP)))
				{
					GetInfo(psOSMode, szBuf);
				}

				/* LAN hardware ID: */
				else if (!memcmp(szBuf, LANHW_TIP, strlen(LANHW_TIP))
					 &&	 *piLanNum < MAX_LANHW_NUM)
				{
					if (*piLanNum > 0)
					{
						sprintf(
							psLanHWs,
							"%s,%s",
							psLanHWs,
							SeekChar(szBuf, COLON_FLAG));
					}
					else
					{
						sprintf(psLanHWs, "%s", SeekChar(szBuf, COLON_FLAG));
					}

					*piLanNum += 1;
				}

				/* Storage devices */
				else if (!memcmp(szBuf, STORAGE_TIP, strlen(STORAGE_TIP)))
				{
					Segmentation(
						psStorage,
						piStorNum,
						MAX_STOR_NUM,
						2,
						STOR_TOKENS,
						fpSrc);
				}

				/* I/O Interfaces */
				else if (!memcmp(szBuf, IOI_TIP, strlen(IOI_TIP)))
				{
					while
					(
						fgets(szBuf, BLOCK_SIZE, fpSrc)
					&&	strlen(szBuf) <= 1
					)
					{				/* 滤去空行及标签行 */
					}

					Segmentation(
						psIFs,
						piIFNum,
						MAX_IFS_NUM,
						1,
						IF_TOKENS,
						fpSrc);
					break;
				}
			}
		}

		/* File System layout */
		else if (FS_TIP_LEN == iLen && !memcmp(szBuf, FS_TIP, strlen(FS_TIP)))
		{
			while (fgets(szBuf, BLOCK_SIZE, fpSrc) && strlen(szBuf) <= 1)
			{						/* 滤去空行及标签行 */
			}

			Segmentation(psFSLs, piFSLNum, MAX_FSLRC_NUM, 1, FSL_TOKENS, fpSrc);
		}

		/* Swap configuration */
		else if (SC_TIP_LEN == iLen && !memcmp(szBuf, SC_TIP, strlen(SC_TIP)))
		{
			while (fgets(szBuf, BLOCK_SIZE, fpSrc) && strlen(szBuf) <= 1)
			{						/* 滤去空行及标签行 */
			}

			Segmentation(psSCs, piSCNum, MAX_SCRC_NUM, 1, SC_TOKENS, fpSrc);
		}

		/* System Info */
		else if (SYS_TIP_LEN == iLen
			 &&	 !memcmp(szBuf, SYSINFO_TIP, strlen(SYSINFO_TIP)))
		{
			while (fgets(szBuf, BLOCK_SIZE, fpSrc))
			{
				szBuf[strlen(szBuf) - 1] = 0x00;

				/* HostName */
				if (!memcmp(szBuf, HOST_TIP, strlen(HOST_TIP)))
				{
					GetInfo(psHostName, szBuf);
				}

				/* IP */
				else if (!memcmp(szBuf, IP_TIP, strlen(IP_TIP)))
				{
					GetInfo(psIP, szBuf);
				}

				/* Mask Code */
				else if (!memcmp(szBuf, MASK_TIP, strlen(MASK_TIP)))
				{
					GetInfo(psMask, szBuf);
					break;
				}
			}
		}
	}

	return 0;
}

int COperatorSystemSpiImpl::GetInfo(char *psDst, char *psSrc)
{
	char *p;

	if (!psDst || !psSrc || !(p = SeekChar(psSrc, COLON_FLAG)))
	{
		return -1;
	}

	strcpy(psDst, p);
	return 0;
}

int COperatorSystemSpiImpl::Segmentation(
	char *psDst,
	int *piNum,
	const int iMaxNum,
	const int iSepMinNum,
	const int iTokens,
	FILE *fpSrc)
{
	int i;

	int iCount;

	int iFlag;
	char *p;
	char *pPos;
	char szBuf[BLOCK_SIZE];

	if (!psDst || !piNum || !fpSrc)
	{
		return -1;
	}

	*piNum = 0;
	pPos = psDst;
	memset(szBuf, 0x00, sizeof(szBuf));

	///strlen(szBuf)>0 不对空行进行分析 2008.08.05 add by wu.yb
	while (fgets(szBuf, BLOCK_SIZE, fpSrc) && strlen(szBuf) > 1)
	{
		///去掉最后的换行符
		szBuf[strlen(szBuf) - 1] = 0x00;
		for (p = szBuf, i = 0, iCount = 1, iFlag = 0; *p != 0x00; p++)
		{
			if (*p == BLANK_FLAG && iCount < iTokens)
			{
				iFlag++;
			}
			else
			{
				if (iFlag >= iSepMinNum && i > 0)
				{
					pPos[i++] = SEP_FLAG;
					iCount += 1;
				}
				else if (iFlag == 1 && i > 0)
				{
					pPos[i++] = BLANK_FLAG;
				}

				pPos[i++] = *p;
				iFlag = 0;
			}
		}

		pPos[i] = 0x00;
		if (i = (iTokens - iCount))
		{
			while (i--)
			{
				strcat(pPos, ", "); //域数不足的填充空格
			}
		}

		pPos += BLOCK_SIZE;
		if (++ *piNum >= iMaxNum)
		{
			break;
		}

		///不需要的代码 2008.08.05 add by wu.yb
				///memset(szBuf, 0x00, sizeof(szBuf));
	}

	return 0;
}

/*
shell>/usr/sbin/lanscan
Hardware Station        Crd Hdw   Net-Interface  NM  MAC       HP-DLPI DLPI
Path     Address        In# State NamePPA        ID  Type      Support Mjr#
0/1/2/0  0x001560045E64 0   UP    lan0 snap0     1   ETHER     Yes     119
0/1/2/1  0x001560045E65 1   UP    lan1 snap1     2   ETHER     Yes     119
0/2/1/0  0x001321EA065D 2   UP    lan2 snap2     3   ETHER     Yes     119
0/4/1/0  0x001321EA36F0 3   UP    lan3 snap3     4   ETHER     Yes     119
0/5/1/0  0x001321EA068E 4   UP    lan4 snap4     5   ETHER     Yes     119
*/

//分析上面的数据
bool COperatorSystemSpiImpl::GetLanStateMap(map<string, string> &lanstateMap)
{
	const int BLOCK_SIZE_LARGE = 2048;
	char szBuf[BLOCK_SIZE_LARGE];
	{
		CFileOCGuard<true> guard("/usr/sbin/lanscan", "r");

		FILE *fpSrc = guard.GetFileHandle();

		if (!fpSrc)
		{
			printf("popen() /usr/sbin/lanscan failed! [%d]\n", errno);
			return false;
		}

		fread(szBuf, sizeof(char), BLOCK_SIZE_LARGE, fpSrc);
	}

	char *szTmp = &szBuf[0];
	int iCount = 0;
	char *ret;
	char *p;
	while (!isdigit(szTmp[0]))
	{
		ret = strchr(szTmp, '\n');
		if (ret == NULL)
		{
			return false;
		}

		szTmp = ++ret;
	}

	iCount = 0;
	p = strtok(szTmp, " \n");

	char *pLanState;

	char *pLanName;

	while (p = strtok(NULL, " \n"))
	{
		iCount++;
		if (iCount == 3)
		{
			pLanState = p;
		}
		else if (iCount == 4)
		{
			pLanName = p;
		}
		else if (iCount == 10)
		{
			lanstateMap[pLanName] = pLanState;
			iCount = 0;
		}
	}
}

/*
shell>netstat -i
Name      Mtu  Network         Address         Ipkts   Ierrs Opkts   Oerrs Coll
lan0      1500 172.16.30.0     kf4640          2685722075 0     1844978865 0     0
lo0       4136 loopback        localhost       6926625 0     6926625 0     0
*/

// 分析上面的数据
bool COperatorSystemSpiImpl::GetNetStat(
	list<CFTDRtnNetworkInfoField *> &networkInfo)
{
	const int BLOCK_SIZE_LARGE = 2048;
	char szBuf[BLOCK_SIZE_LARGE];
	{
		CFileOCGuard<true> guard("netstat -i", "r");

		FILE *fpSrc = guard.GetFileHandle();
		if (!fpSrc)
		{
			printf("popen() netstat -i failed! [%d]\n", errno);
			return false;
		}

		fread(szBuf, sizeof(char), BLOCK_SIZE_LARGE, fpSrc);
	}

	char *szTmp = &szBuf[0];
	int iCount = 0;

	double	dBytes = 0;

	char *pLanName;
	char *pIP;
	char *pRecvPack;
	char *pSendPack;
	char *p;

	while (szTmp = strstr(szTmp, LAN_TIP_UNIX))
	{
		iCount = 0;

		p = strtok(szTmp, " \n");
		pLanName = p;
		while ((p = strtok(NULL, " \n")))
		{
			iCount++;
			if (iCount == 1)
			{
				dBytes = (double)(atoi(p) * 0.5);
			}
			else if (iCount == 2)
			{
				pIP = p;
			}
			else if (iCount == 4)
			{
				pRecvPack = p;
			}
			else if (iCount == 6)	// 需要的数据都已经获取了，不再对本行进行分析
			{
				pSendPack = p;
				szTmp = p;

				CFTDRtnNetworkInfoField *field = new CFTDRtnNetworkInfoField;
				field->LANNAME = pLanName;
				field->IPADDRESS = pIP;
				field->RECVPACKETS = pRecvPack;
				field->SENDPACKETS = pSendPack;

				//map<string,string>::iterator it = m_LanIPMap.find((char *)m_cNetworkInfo.LANNAME.getValue());
				map<string, string>::iterator it = m_LanIPMap.find(pLanName);
				if (it != m_LanIPMap.end() && !it->second.empty())
				{
					field->IPADDRESS = (const char *)it->second.c_str();
				}

				field->SENDBYTES = ((long long)(dBytes)) * (const long long)field->SENDPACKETS;
				field->RECVBYTES = ((long long)(dBytes)) * (const long long)field->RECVPACKETS;

				networkInfo.push_back(field);

				break;
			}

			// else if (iCount==8)
		}	//end of strtok
	}		//enf of strstr : find "lan"
}

#endif
#if 0
bool COperatorSystemSpiImpl::GetNetwork(void)
{
#ifdef HP_UX
	map<string, string> lanStateMap;
	GetLanStateMap(lanStateMap);

	list<CFTDRtnNetworkInfoField *> networkInfo;
	GetNetStat(networkInfo);

	GetDateTime();

	sprintf(m_mObjectId, "%s.%s", m_mObjectName, HOSTATTRNET);

	m_pkgSend.PreparePackage(
			FTD_TID_RtnNetworkInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	list<CFTDRtnNetworkInfoField *>::iterator it;

	map<string, string>::iterator mapIt;
	for (it = networkInfo.begin(); it != networkInfo.end(); ++it)
	{
		(*it)->HostName = m_mObjectId;
		(*it)->MonTime = m_mTime;
		(*it)->MonDate = m_mDate;

		mapIt = lanStateMap.begin();
		if (mapIt != lanStateMap.end())
		{
			(*it)->LANSTATUS = (*mapIt).second.c_str();

			//(*mapIt).second = "OK";
			lanStateMap.erase(mapIt);
		}

		FTDC_ADD_FIELD(&m_pkgSend, (*it));
		delete(*it);
	}

	printf("netstat: lanStateMap.size() = %d\n", lanStateMap.size());

	CFTDRtnNetworkInfoField field;
	for (mapIt = lanStateMap.begin(); mapIt != lanStateMap.end(); mapIt++)
	{
		field.HostName = m_mObjectId;
		field.MonTime = m_mTime;
		field.MonDate = m_mDate;

		field.LANNAME = mapIt->first.c_str();
		field.SENDBYTES = 0.0;
		field.RECVBYTES = 0.0;
		field.IPADDRESS = "";
		field.RECVPACKETS = 0.0;
		field.SENDPACKETS = 0.0;
		field.LANSTATUS = mapIt->second.c_str();
		FTDC_ADD_FIELD(&m_pkgSend, &field);
	}

	OSSENDPACKAGETO;

	return true;
#else
	return false;
#endif
}

#endif
