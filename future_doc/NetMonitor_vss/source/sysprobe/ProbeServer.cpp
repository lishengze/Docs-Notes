/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	ProbeServer.cpp
///@brief	实现了探针监听采集代理连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
///20090305	晏鹤春		修改探针机制为于主机名变更包之前发送ENV主机环境信息
///20120309	晏鹤春		Session增加数据压缩CRPCM_ZERO
#include "ProbeServer.h"
#include "xmlcfg.h"
#include "CEventReport.h"
#include "DBSpiThread.h"
#include "FileCheck.h"
#include "SANCaptureThread.h"
#include "WebLogStatics.h"
#include "SANEventThread.h"
#include "CSysInternalTopology.h"

#define DEFAULT_TIMER	300

typedef list<CTableDBRelation>	listTDB;

extern CCachedFileFlow	*g_pFlow;
extern char g_mTradeDay[9];					// 交易日
extern char g_pHostName[32];				// 保存主机名称
extern char g_pDataCenterName[32];			// 保存数据中心名称，如TRADE.PuDian
extern char g_pCenterName[32];				// 保存纯数据中心名称，如PuDian或ZhangJ
bool g_sendEvnFlag = false;
COperatorSystemSpiImpl	*g_pHostSpi = NULL; // 主机采集spi实例的指针
CSyslogSpiImpl	*g_pSyslogSpi = NULL;		// 业务系统日志采集spi实例的指针
CSyslogSpiImpl	*g_pKeyFileSpi = NULL;		// 业务关键文件采集spi实例的指针
CSyslogSpiImpl	*g_pMsgFileSpi = NULL;		// 主机系统日志采集spi实例的指针
CSyslogSpiImpl	*g_pSLogSpi = NULL;			// 二进制文件采集spi实例的指针
CSyslogSpiImpl	*g_pDfmtLogSpi = NULL;		// dfmt文件采集spi实例的指针
int g_timerHostAcitve = 1;					// 主机Active间隔,值为0时表示不产生该事件，下同
int g_timerHostEnv = 0;						// 环境变量时间间隔
int g_timerCPU = 0;						// CPU时间间隔
int g_timerMemory = 0;					// 内存时间间隔
int g_timerProcess = 0;					// 进程时间间隔
int g_timerDisk = 0;					// 分区时间间隔
int g_timerUser = 0;					// 在线用户时间间隔
int g_timerNetwork = 0;					// 网络采集时间间隔
int g_timerNetStat = 0;					// netstat信息采集时间间隔
int g_timerAppSyslog = 0;				// 业务进程日志采集定时器间隔
int g_timerSessionLog = 0;				// 二进制日志文件采集定时器间隔
int g_timerSystemLog = 0;				// 主机系统日志文件采集定时器间隔
int g_timerKeyFile = 0;					// 业务系统关键文件采集定时器间隔
int g_timerDfmtLog = 0;					// DFMT文件采集定时器间隔
int g_timerDatabase = 0;				// 数据库采集定时器间隔
int g_timerDiskIO = 0;					// 磁盘I/O信息采集定时器间隔
int g_timerRouter = 0;					// 系统路由信息采集定时器间隔
int g_timerKernel = 0;					// 系统关键信息采集定时器间隔
int g_timerStatInfo = 0;				// 系统状态信息采集定时器间隔
#define XML_VAL_TIMER_DISKIO	"DiskIO"
#define XML_VAL_TIMER_ROUTER	"Router"
#define XML_VAL_TIMER_KERNEL	"Kernel"
#define XML_VAL_TIMER_STATINFO	"StatInfo"

MapConSyslog g_mSyslogNameMap;			// 业务系统采集文件信息
MapConSyslog g_mKeyFileNameMap;			// 业务系统关键文件信息
MapConSyslog g_mMsgFileNameMap;			// 主机系统日志文件信息
MapConSyslog g_mSessionLogMap;			// 二进制文件信息
MapConSyslog g_mDfmtLogMap;				// DFMT文件信息
map<string, string> g_mSpcPrcMap;		// 业务进程名与所在硬盘分区映射
CManageConSession g_mManageConSession;	// 保存所有连接的地址信息
char *g_szHostEnvFile = NULL;			// 主机环境信息文件绝对路径名
char *g_szNetConfFile = NULL;			// 主机网络配置信息文件绝对路径名
CDBSpiThread *g_pCDBSpiThread = NULL;	// 数据库线程指针
CFileCheckThread *g_pFileCheckThread = NULL;			// 文件校验线程指针
CSANCaptureThread *g_pSANCaptureThread = NULL;			// 读取SAN线程指针
CSANEventThread *g_pSANEventThread = NULL;				// SAN Event采集线程指针
CWebLogStatSpiThread *g_pWebLogStatSpiThread = NULL;	// 网站访问日志统计线程指针

// add by cao.ning
// 系统内部连接拓扑
extern CSysInternalTopology* g_SysInternalTopology;

///数据锁，用于保护进程信息
static CMutex s_lockProcInfo;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;						// 数据包输出到文件
#endif
#undef WINDOWS_CPUUSAGE_DEBUG
CProbeTimmer::CProbeTimmer(CReactor *pReactor) :
	CEventHandler(pReactor)
{
	m_nEventId = 0;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	printf(" Flow count %d\n", g_pFlow->GetCount());
#endif
}

void CProbeTimmer::SetTimer(int nIDEvent, int nElapse)
{
	m_nEventId = nIDEvent;
	CEventHandler::SetTimer(nIDEvent, nElapse);
}

void CProbeTimmer::OnTimer(int nIDEvent)
{
	if (g_mManageConSession.isValidFtdcSession() == false)
	{
		return;
	}

	if (nIDEvent == 1)
	{
		/// 主机信息采集时不允许多并发
		s_lockProcInfo.Lock();

		int mTime = time((time_t *)NULL) % 86400;
		if (g_pHostSpi != NULL)
		{
			g_pHostSpi->GetDateTime();

			if (g_timerHostAcitve && mTime % g_timerHostAcitve == 0)
			{
				g_pHostSpi->GetHostActiveSpi();
			}

			if (g_timerCPU && mTime % g_timerCPU == 0)
			{
				g_pHostSpi->GetcpuSpi();
			}

			if (g_timerMemory && mTime % g_timerMemory == 0)
			{
				g_pHostSpi->GetmemSpi();
			}

			if (g_timerProcess && mTime % g_timerProcess == 0)
			{
				g_pHostSpi->GetprocessSpi();
			}

			if (g_timerDisk && mTime % g_timerDisk == 0)
			{
				g_pHostSpi->GetfsSpi();
			}

			if (g_timerUser && mTime % g_timerUser == 0)
			{
				g_pHostSpi->GetuserSpi();
			}

			if (g_timerNetwork && mTime % g_timerNetwork == 0)
			{
				g_pHostSpi->GetnetworkSpi();
			}

			if (g_timerNetStat && mTime % g_timerNetStat == 0)
			{
				g_pHostSpi->GetnetstatSpi();
			}

			if (g_timerStatInfo && mTime % g_timerStatInfo == 0)
			{
				g_pHostSpi->GetstatinfoSpi();
			}

			if (g_timerDiskIO && mTime % g_timerDiskIO == 0)
			{
				g_pHostSpi->GetdiskioSpi();
			}

			if (g_timerRouter && mTime % g_timerRouter == 0)
			{
				g_pHostSpi->GetrouterSpi();
			}

			if (g_timerKernel && mTime % g_timerKernel == 0)
			{
				g_pHostSpi->GetkernelSpi();
			}

			if (g_sendEvnFlag == false)
			{
				g_pHostSpi->GetenvSpi();
			}

			m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRtnObjectAttrField	ObjectAttr;
			bool bSendFlag = false;
			while (g_pHostSpi->m_ObjectAttrList.get(ObjectAttr))
			{
#if 0
				printf(
					"Get ObjectAttr:\nObjectID[%s:%s]\nDateTime[%s %s]\nValue[%s]\n",
					ObjectAttr.ObjectID.getValue(),
					ObjectAttr.AttrType.getValue(),
					ObjectAttr.MonDate.getValue(),
					ObjectAttr.MonTime.getValue(),
					ObjectAttr.AttrValue.getValue());
#endif
				if (m_pkgSend.Length() +
					sizeof(CFTDRtnObjectAttrField) > FTDC_PACKAGE_MAX_SIZE)
				{
					g_mManageConSession.sendFTDCPackage(&m_pkgSend);
					m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
				}

				FTDC_ADD_FIELD(&m_pkgSend, &ObjectAttr);
				bSendFlag = true;
			}

			if (bSendFlag)
			{
				g_mManageConSession.sendFTDCPackage(&m_pkgSend);
			}
		}
		/// 主机信息采集的互斥锁
		s_lockProcInfo.UnLock();

		if (g_pMsgFileSpi != NULL)
		{
			if (g_timerSystemLog)
			{
				if (mTime % g_timerSystemLog == 0)
				{
					g_pMsgFileSpi->GetSpi();		// 取主机日志spi
				}
			}
		}

		if (g_pKeyFileSpi != NULL)
		{
			if (g_timerKeyFile)
			{
				if (mTime % g_timerKeyFile == 0)
				{
					g_pKeyFileSpi->GetTotalSpi();	// 取关键文件spi
				}
			}
		}

		if (g_pSLogSpi != NULL)
		{
			if (g_timerSessionLog)
			{
				if (mTime % g_timerSessionLog == 0)
				{
					g_pSLogSpi->GetBinSpi();		// 取slog文件spi
				}
			}
		}

		if (g_pDfmtLogSpi != NULL)
		{
			if (g_timerDfmtLog)
			{
				if (mTime % g_timerDfmtLog == 0)
				{
					g_pDfmtLogSpi->GetSizeSpi();	// 取dfmt文件大小spi
				}
			}
		}

		if (g_pCDBSpiThread != NULL)
		{
			g_pCDBSpiThread->GetSpi();				// 取数据库指标spi
		}

		if (g_pFileCheckThread != NULL)
		{
			g_pFileCheckThread->GetSpi();			// 网站防篡改spi
		}

		if (g_pSANCaptureThread != NULL)
		{
			g_pSANCaptureThread->GetSpi();			// SAN指标spi
		}

		if (g_pWebLogStatSpiThread != NULL)
		{
			g_pWebLogStatSpiThread->GetSpi();		// 网站访问量统计spi
		}

		return;
	}
	else if (nIDEvent == 2)
	{
		if (g_pSyslogSpi != NULL)
		{
			g_pSyslogSpi->GetSpi();					// 取业务进程日志spi
		}
	}

	return;
}

int CProbeTimmer::GetEventId(void)
{
	return m_nEventId;
}

CProbeServer::CProbeServer(CReactor *pReactor) :
	CSessionFactory(pReactor, 10),
	m_timer(pReactor)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_timer.SetTimer(1, 1000);
	m_timer.SetTimer(2, 100);
	g_pCDBSpiThread = new CDBSpiThread();
	g_pCDBSpiThread->Create();
}

string	g_sProbeLocation;						// 探针地址 tcp://172.16.94.21:33312,sysprobe
string	g_sProbeName;							// 探针别名 TRADELOG-FE76
int CProbeServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//printf("\tCProbeServer::HandlePackage:Receive Package %0x\n",pFTDCPackage->GetTID());
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_RtnMonitorObjectTopic:
			{
				/// 接收到来自顶层采集代理(非中转,直连EventCounter)的探针名信息
				CFTDRtnMonitorObjectField fieldObject;
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldObject);
				g_sProbeLocation = fieldObject.ObjectID.getValue();
				g_sProbeName = fieldObject.ObjectName.getValue();

				/// 发送主机配置请求信息
				DoReqQryHostConfig(pSession);
			}

			break;
		case FTD_TID_RspQryHostConfig:
			OnRspQryHostConfig(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnHostConfig:
			OnRspQryHostConfig(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqUserLogout:
			OnReqUserLogout(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			OnReqQryTradeDayChange(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryDBQueryTopic:
			OnReqQryDBQuery(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysInternalTopologyTopic:
			if (g_SysInternalTopology)
				g_SysInternalTopology->OnReqQrySysInternalTopologyTopic(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

CSession *CProbeServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	printf(
		"\tCProbeServer::CreateSession:CFTDCSession %0x Connected ==\n",
		(CFTDCSession *)pSession);
	fflush(stdout);
	return pSession;
}

void CProbeServer::OnRspQryHostConfig(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
#endif
	if (g_mManageConSession.getStatus(pSession) == 1)
	{	// 本连接已经取到了配置信息,不需要再处理了
		printf(
			"CProbeServer::OnReqUserLogin Session [%0x] Status 1\n",
			(CFTDCSession *)pSession);
		printf("g_mSyslogNameMap size %d\n", g_mSyslogNameMap.size());

		///@param	pname	读取的文件名(含路径)
				///@param	pType	文件的类型(syslog,applog,keyfile,slog,dfmt文件)
				///@param	pFileName	文件名Syslog.log, 属性名dfmt.dfmtLen（dfmt文件才具备属性名，其他类型为不含路径的文件名）
				///@param	pObjectID	对象ID,如PuDian.os.AC-01.applog
				///@param	pConn	采集代理连接串信息
				///@param	pHaveRead	采集代理已经读取到的文件长度
				///@param	pReadTime	采集代理已经读取到的文件时间
				///@param	pProbeLoation	探针的地址信息
		MapConSyslog::iterator	map_it;
		for (map_it = g_mSyslogNameMap.begin();
			 map_it != g_mSyslogNameMap.end();
			 map_it++)
		{
			printf(
				"Filename: %s  Session %0x , Filename:%s Filename:%s Filetype:%s FileId:%d Haveread:%u ReadTime:%d Valid:%u\n",
				map_it->first.m_mPath.c_str(),
				map_it->first.m_mSession,
				map_it->second.m_mName.c_str(),
				map_it->second.m_mFileName.c_str(),
				map_it->second.m_mType.c_str(),
				map_it->second.m_mFd,
				map_it->second.m_mHaveRead,
				map_it->second.m_mIntTime,
				map_it->second.m_mValid);
		}

		/// by zhou.jj 20100407 接收配置变更消息，不能直接返回
		//return ;
	}

	CFTDReqUserLoginField fieldLogin;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDReqUserLoginField::m_Describe);
	if (!itor.IsEnd())
	{
		itor.Retrieve(&fieldLogin);
		printf(
			"\tCProbeServer::OnReqUserLogin:user=%s password=%s ProtocolInfo=%s\n",
			(const char *)fieldLogin.UserID,
			(const char *)fieldLogin.Password,
			(const char *)fieldLogin.ProtocolInfo);
		fflush(stdout);

		m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspUserLogin,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

		CFTDRspInfoField fieldRspInfo;
		fieldRspInfo.ErrorMsg = "成功";
		fieldRspInfo.ErrorID = 0;
		FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	MapConSyslog::iterator	logit;
	CFTDRspQryHostConfigField fieldConfigInfo;
	static CFTDRtnUpdateSysConfigField	sysConfigInfo;	// 系统信息变更包
	static bool bModFlag = false;						// 是否发送主机名变更包的标识
	itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRspQryHostConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldConfigInfo);

		if (strcmp(
				fieldConfigInfo.CfgType.getValue(),
			HOSTCFG_REQTYPE_HOST) == 0)
		{
			// fieldHostConfig.CfgType  = HOSTCFG_REQTYPE_HOST  ;
			// fieldHostConfig.CfgName     = g_mTradeDay			;	// 交易日
			// fieldHostConfig.CfgLocation = pProbeCfg->GetLocation() ; // 获取探针地址
			// fieldHostConfig.CfgHostName = pProbeCfg->GetHostName() ; // 获取主机名
			// fieldHostConfig.CfgAttend   = pProbeCfg->GetDataCenter(); // 获取主机所在数据中心名
			
			// Mod by Henchi, 20100108
			// Mod by zhou.jj 20100128 重新放开
			/// 交易日信息只由启动初始化，由OnReqQryTradeDayChange()方法进行更新，其它地方不作处理
			strcpy(g_mTradeDay, fieldConfigInfo.CfgName.getValue());

			// Mod by Henchi, 20130513
			// 系统标识及主机名配置允许动态更新
			//if ((g_pDataCenterName[0] == '\0')	&&	(!fieldConfigInfo.CfgAttend.isNull()))
			if (!fieldConfigInfo.CfgAttend.isNull())
			{
				strcpy(g_pDataCenterName, fieldConfigInfo.CfgAttend.getValue());

				char *p = strchr(g_pDataCenterName, '.');
				if (p != NULL)
					strcpy(g_pCenterName, ++p);
			}

			if (!fieldConfigInfo.CfgHostName.isNull())
			{
				if (strcmp(
						g_pHostName,
					fieldConfigInfo.CfgHostName.getValue()) != 0)
				{
					// 如果系统取出的主机名为空，则采用探针配置的名称，不发送变更数据包
#ifdef REAL_HOSTNAME
					// try to use real hostname
					if (g_pHostName[0] == '\0')
#else
						// try to use config hostname
						if (1)
#endif
						{
							strcpy(
								g_pHostName,
								fieldConfigInfo.CfgHostName.getValue());
							bModFlag = false;
						}
						else						// 主机配置名和系统取出的名字不相同，发主机名变更数据报
						{
							//fieldInfo.UpdateType:主机名变更类型
							sysConfigInfo.UpdateType = UPDATESYSCONFIG_HOSTNAME;

							//fieldInfo.OldValue:保存探针配置的主机名称
							sprintf(
								(char *)sysConfigInfo.OldValue.getValue(),
								"%s.%s.%s",
								g_pDataCenterName,
								DATACENTERHOST,
								fieldConfigInfo.CfgHostName.getValue());

							//fieldInfo.NewValue:保存系统取出的主机名称
							sprintf(
								(char *)sysConfigInfo.NewValue.getValue(),
								"%s.%s.%s",
								g_pDataCenterName,
								DATACENTERHOST,
								g_pHostName);
							sysConfigInfo.Standby = fieldConfigInfo.CfgLocation.getValue();
							bModFlag = true;
						}
				}
			}

			/// 更新主机信息线程的对象名称标识
			if (g_pHostSpi)
			{
				g_pHostSpi->SetObjectName(g_pDataCenterName, g_pHostName);
			}

			if (!fieldConfigInfo.CfgLocation.isNull())
			{
				g_mManageConSession.addProbeLocation(
						fieldConfigInfo.CfgLocation.getValue(),
						pSession);
			}
			else
			{
				printf("\t 采集探针地址配置没有取到，错误! \n");
				fflush(stdout);
			}
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_TIMER) == 0)
		{
			// 			fieldHostConfig.CfgType  = HOSTCFG_REQTYPE_TIMER  ;  // 定时器配置类
			// 			fieldHostConfig.CfgName     = timerMapIt->first.c_str() ; // 定时器对象名
			// 			fieldHostConfig.CfgLocation = "";  // 此字段留空
			// 			fieldHostConfig.CfgHostName = "";  // 此字段留空
			// 			fieldHostConfig.CfgAttend   = timerMapIt->second  ; // 定时器时间间隔(秒)
			if (strcmp(
					fieldConfigInfo.CfgName.getValue(),
				XML_VAL_TIMER_HOSTENV) == 0)
			{
				if (g_timerHostEnv == 0)
				{
					g_timerHostEnv = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_CPU) == 0)
			{
				if (g_timerCPU == 0)
				{
					g_timerCPU = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_MEMORY) == 0)
			{
				if (g_timerMemory == 0)
				{
					g_timerMemory = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_PROCESS) == 0)
			{
				if (g_timerProcess == 0)
				{
					g_timerProcess = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_DISK) == 0)
			{
				if (g_timerDisk == 0)
				{
					g_timerDisk = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_USER) == 0)
			{
				if (g_timerUser == 0)
				{
					g_timerUser = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
				fieldConfigInfo.CfgName.getValue(),
				XML_VAL_TIMER_NETWORK) == 0)
			{
				if (g_timerNetwork == 0)
				{
					g_timerNetwork = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
				fieldConfigInfo.CfgName.getValue(),
				XML_VAL_TIMER_NETSTAT) == 0)
			{
				if (g_timerNetStat == 0)
				{
					g_timerNetStat = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_APPSYSLOG) == 0)
			{
				if (g_timerAppSyslog == 0)
				{
					g_timerAppSyslog = atoi(
							fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_SYSTEMLOG) == 0)
			{
				if (g_timerSystemLog == 0)
				{
					g_timerSystemLog = atoi(
							fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_SESSIONLOG) == 0)
			{
				if (g_timerSessionLog == 0)
				{
					g_timerSessionLog = atoi(
							fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_DFMETLOG) == 0)
			{
				if (g_timerDfmtLog == 0)
				{
					g_timerDfmtLog = atoi(fieldConfigInfo.CfgAttend.getValue());
				}

				printf("\n\nTimer Sign: %d\n", g_timerDfmtLog);
				fflush(stdout);
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_KEYFILE) == 0)
			{
				if (g_timerKeyFile == 0)
				{
					g_timerKeyFile = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_DATEBASE) == 0)
			{
				if (g_timerDatabase == 0)
				{
					g_timerDatabase = atoi(
							fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_DISKIO) == 0)
			{
				if (g_timerDiskIO == 0)
				{
					g_timerDiskIO = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_ROUTER) == 0)
			{
				if (g_timerRouter == 0)
				{
					g_timerRouter = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_KERNEL) == 0)
			{
				if (g_timerKernel == 0)
				{
					g_timerKernel = atoi(fieldConfigInfo.CfgAttend.getValue());
				}
			}
			else if (strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_TIMER_STATINFO) == 0)
			{
				if (g_timerStatInfo == 0)
				{
					g_timerStatInfo = atoi(
							fieldConfigInfo.CfgAttend.getValue());
				}
			}
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_CFGFILE) == 0)
		{
			// fieldHostConfig.CfgType  = HOSTCFG_REQTYPE_CFGFILE ; // 主机环境配置文件类
			// fieldHostConfig.CfgName     = configMapIt->first.c_str(); // 配置文件名
			// fieldHostConfig.CfgLocation = configMapIt->second.c_str(); // 配置文件路径
			// fieldHostConfig.CfgHostName = "";  // 此字段留空
			// fieldHostConfig.CfgAttend   = "";  // 此字段留空
			if ((g_szHostEnvFile == NULL)
			&&	(
					strcmp(
					fieldConfigInfo.CfgName.getValue(),
				XML_VAL_CFGFILE_HOSTENV) == 0
			))
			{
				g_szHostEnvFile = (char *)malloc(
						strlen(fieldConfigInfo.CfgLocation.getValue()) + 1);
				strcpy(g_szHostEnvFile, fieldConfigInfo.CfgLocation.getValue());
			}
			else if ((g_szNetConfFile == NULL)
				 &&	 (
						 strcmp(
						 fieldConfigInfo.CfgName.getValue(),
					 XML_VAL_CFGFILE_NETCFG) == 0
				 ))
			{
				g_szNetConfFile = (char *)malloc(
						strlen(fieldConfigInfo.CfgLocation.getValue()) + 1);
				strcpy(g_szNetConfFile, fieldConfigInfo.CfgLocation.getValue());
			}
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_APPROOT) == 0)
		{
			// fieldHostConfig.CfgType  = HOSTCFG_REQTYPE_APPROOT ;  // 应用进程分区类
			// fieldHostConfig.CfgName     = apppathMapIt->first.c_str();  // 应用进程名
			// fieldHostConfig.CfgLocation = apppathMapIt->second.c_str();  // 应用进程所在分区
			// fieldHostConfig.CfgHostName = "";  // 此字段留空
			// fieldHostConfig.CfgAttend   = "";  // 此字段留空
			
			printf("CFG_SPCPROC[%s %s]\n", (char *)fieldConfigInfo.CfgName.getValue(),
				(char *)fieldConfigInfo.CfgLocation.getValue()
			);
			/// 进程信息互斥锁
			s_lockProcInfo.Lock();
			printf("NUM_SPCPROC[%d]->", g_mSpcPrcMap.size());
			g_mSpcPrcMap[string(fieldConfigInfo.CfgName.getValue())] = string(
					fieldConfigInfo.CfgLocation.getValue());					
			printf("[%d]\n", g_mSpcPrcMap.size());
			s_lockProcInfo.UnLock();
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_APPSYSLOG) == 0)
		{
			logit = g_mSyslogNameMap.find(
					CConStringKey(
						string(fieldConfigInfo.CfgLocation.getValue()),
						pSession));
			if (logit == g_mSyslogNameMap.end())	// 此日志文件不在采集中
			{
				printf(
					"\t New File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}
			else
			{
				printf(
					"\t Old File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}

			char objectId[200];
			if (g_pDataCenterName[0] != '\0' && g_pHostName[0] != '\0')
			{
				sprintf(
					objectId,
					"%s.%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName,
					HOSTATTRAPPLOG);
			}

			g_mSyslogNameMap[CConStringKey(
					string(fieldConfigInfo.CfgLocation.getValue()),
					pSession)] = CSyslogValue(
					fieldConfigInfo.CfgLocation.getValue(),
					HOSTATTRAPPLOG,
					(char *)fieldConfigInfo.CfgName.getValue(),
					objectId,
					(char *)"",
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue(),
					g_mManageConSession.getProbeLocation(pSession));
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_SYSTEMLOG) == 0)
		{
			logit = g_mMsgFileNameMap.find(
					CConStringKey(
						string(fieldConfigInfo.CfgLocation.getValue()),
						pSession));
			if (logit == g_mMsgFileNameMap.end())	// 此日志文件不在采集中
			{
				printf(
					"\t New File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}
			else
			{
				printf(
					"\t Old File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}

			char objectId[200];
			if (g_pDataCenterName[0] != '\0' && g_pHostName[0] != '\0')
			{
				sprintf(
					objectId,
					"%s.%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName,
					HOSTATTRSYSLOG);
			}

			g_mMsgFileNameMap[CConStringKey(
					string(fieldConfigInfo.CfgLocation.getValue()),
					pSession)] = CSyslogValue(
					fieldConfigInfo.CfgLocation.getValue(),
					HOSTATTRSYSLOG,
					(char *)fieldConfigInfo.CfgName.getValue(),
					objectId,
					(char *)"",
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue(),
					g_mManageConSession.getProbeLocation(pSession));
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_KEYFILE) == 0)
		{
			logit = g_mKeyFileNameMap.find(
					CConStringKey(
						string(fieldConfigInfo.CfgLocation.getValue()),
						pSession));
			if (logit == g_mKeyFileNameMap.end())	// 此日志文件不在采集中
			{
				printf(
					"\t New File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}
			else
			{
				printf(
					"\t Old File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}

			char objectId[200];
			if (g_pDataCenterName[0] != '\0' && g_pHostName[0] != '\0')
			{
				sprintf(
					objectId,
					"%s.%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName,
					HOSTATTRKEYFILE);
			}

			g_mKeyFileNameMap[CConStringKey(
					string(fieldConfigInfo.CfgLocation.getValue()),
					pSession)] = CSyslogValue(
					fieldConfigInfo.CfgLocation.getValue(),
					HOSTATTRKEYFILE,
					(char *)fieldConfigInfo.CfgName.getValue(),
					objectId,
					(char *)"",
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue(),
					g_mManageConSession.getProbeLocation(pSession));
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_SESSIONLOG) == 0)
		{
			logit = g_mSessionLogMap.find(
					CConStringKey(
						string(fieldConfigInfo.CfgLocation.getValue()),
						pSession));
			if (logit == g_mSessionLogMap.end())	// 此日志文件不在采集中
			{
				printf(
					"\t New File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}
			else
			{
				printf(
					"\t Old File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}

			char objectId[200];
			if (g_pDataCenterName[0] != '\0' && g_pHostName[0] != '\0')
			{
				sprintf(
					objectId,
					"%s.%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName,
					HOSTATTRSESSIONLOG);
			}

			g_mSessionLogMap[CConStringKey(
					string(fieldConfigInfo.CfgLocation.getValue()),
					pSession)] = CSyslogValue(
					fieldConfigInfo.CfgLocation.getValue(),
					HOSTATTRSESSIONLOG,
					(char *)fieldConfigInfo.CfgName.getValue(),
					objectId,
					(char *)"",
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue(),
					g_mManageConSession.getProbeLocation(pSession));
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_DFMTLOG) == 0)
		{
			logit = g_mDfmtLogMap.find(
					CConStringKey(
						string(fieldConfigInfo.CfgLocation.getValue()),
						pSession));

			// 						fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DFMTLOG	;			// DFMT文件类
			// 						fieldHostConfig.CfgName     = dfmtMapIt->first.c_str();		// DFMT属性名
			// 						fieldHostConfig.CfgLocation = dfmtMapIt->second.c_str();		// DFMT文件路径
			// 						fieldHostConfig.CfgHostName = "";		// 此字段留空
			// 						fieldHostConfig.CfgAttend   = "";		// 此字段留空
			char objectId[200];
			if (g_pDataCenterName[0] != '\0' && g_pHostName[0] != '\0')
			{
				sprintf(
					objectId,
					"%s.%s.%s.%s",
					g_pDataCenterName,
					DATACENTERHOST,
					g_pHostName,
					HOSTATTRDFMTLOG);
			}

			g_mDfmtLogMap[CConStringKey(
					string(fieldConfigInfo.CfgLocation.getValue()),
					pSession)] = CSyslogValue(
					fieldConfigInfo.CfgLocation.getValue(),
					HOSTATTRDFMTLOG,
					(char *)fieldConfigInfo.CfgName.getValue(),
					objectId,
					(char *)"",
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue(),
					g_mManageConSession.getProbeLocation(pSession));
			if (logit == g_mDfmtLogMap.end())		// 此日志文件不在采集中
			{
				printf(
					"\t New File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}
			else
			{
				printf(
					"\t Old File fieldSyslogInfo.FileName = %s %s %s\n",
					(const char *)fieldConfigInfo.CfgLocation,
					(char *)fieldConfigInfo.CfgHostName.getValue(),
					(char *)fieldConfigInfo.CfgAttend.getValue());
				fflush(stdout);
			}
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_WEBSITE) == 0)
		{
			// Added by Henchi 20090715
			//fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_WEBSITE	;					// 网站文件校验配置类
			//fieldHostConfig.CfgName     = filecodeMapIt->second.m_sRacServiceName.c_str();		// 待校验文件路径
			//fieldHostConfig.CfgLocation = filecodeMapIt->second.m_sRacServiceName.c_str();		// 校验文件所在路径
			//fieldHostConfig.CfgHostName = filecodeMapIt->second.m_sIpAddr.c_str();		// 采样时段
			//fieldHostConfig.CfgAttend   = "";		// 此字段留空
			if (NULL == g_pFileCheckThread)
			{
				g_pFileCheckThread = new CFileCheckThread();
				g_pFileCheckThread->Create();
			}

			g_pFileCheckThread->UpdateCheckConfig(
					(const char *)fieldConfigInfo.CfgName,
					(const char *)fieldConfigInfo.CfgLocation,
					(const char *)fieldConfigInfo.CfgHostName);
			printf(
				"WebCheck  %-12s --- %s \n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation);
			fflush(stdout);
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_WEBSITECODE) == 0)
		{
			// Added by Henchi 20090903
			//fieldHostConfig.CfgType	  = HOSTCFG_REQTYPE_WEBSITECODE	;						// 网站状态码校验配置类
			//fieldHostConfig.CfgName     = WebsiteCodeMapIt->second.m_sRacServiceName.c_str();			// 网站域名项
			//fieldHostConfig.CfgLocation = WebsiteCodeMapIt->second.m_sUserName.c_str();		// 网站状态码校验URL
			//fieldHostConfig.CfgHostName = WebsiteCodeMapIt->second.m_sIpAddr.c_str();			// 采样时段
			//fieldHostConfig.CfgAttend   = WebsiteCodeMapIt->second.m_sPassword.c_str();		// 网站合法状态标识码
			string	domainName;

			// Added by Henchi 20090903
			string	testUrl;
			int httpPort;
			if (explainUrl(
					fieldConfigInfo.CfgLocation.getValue(),
				domainName,
				httpPort,
				testUrl))
			{
				if (NULL == g_pFileCheckThread)
				{
					g_pFileCheckThread = new CFileCheckThread();
					g_pFileCheckThread->Create();
				}

				g_pFileCheckThread->UpdateCheckHtml(
						fieldConfigInfo.CfgName.getValue(),
						domainName,
						httpPort,
						testUrl,
						fieldConfigInfo.CfgAttend.getValue(),
						fieldConfigInfo.CfgHostName.getValue());
			}
			else
			{
				printf("网站状态码校验URL配置格式不正确\n");
			}

			printf(
				"WebsiteCode %-12s --- %s %s\n",
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName,
				(const char *)fieldConfigInfo.CfgAttend);
			fflush(stdout);
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_ACCESSLOG) == 0)
		{
			//fieldHostConfig.CfgType	  = HOSTCFG_REQTYPE_ACCESSLOG	;						// 网站访问日志配置信息类
			//fieldHostConfig.CfgName     = AccessLogMapIt->second.m_sRacServiceName.c_str();			// 网站服务器名
			//fieldHostConfig.CfgLocation = AccessLogMapIt->second.m_sIpAddr.c_str();			// 访问日志路径
			//fieldHostConfig.CfgHostName = AccessLogMapIt->second.m_sUserName.c_str();		// 访问日志统计时段频率
			//fieldHostConfig.CfgAttend   = AccessLogMapIt->second.m_sPassword.c_str();		// 访问日志统计范围区间
			if (NULL == g_pWebLogStatSpiThread)
			{
				g_pWebLogStatSpiThread = new CWebLogStatSpiThread();
				g_pWebLogStatSpiThread->Create();
			}

			printf(
				"AccessLog  %-12s --- %s %s %s\n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName,
				(const char *)fieldConfigInfo.CfgAttend);
			fflush(stdout);

			g_pWebLogStatSpiThread->UpdateConfig(
					(const char *)fieldConfigInfo.CfgName,
					(const char *)fieldConfigInfo.CfgLocation,
					(const char *)fieldConfigInfo.CfgHostName,
					(const char *)fieldConfigInfo.CfgAttend);
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_DATABASE) == 0)
		{
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DATABASE	;		// 数据库连接信息类
			//			fieldHostConfig.CfgName     = databaseMapIt->first.c_str();		// 数据库别名
			//			fieldHostConfig.CfgLocation = szDatabase;						// 数据库特征串，如："monitor1 monitor 172.16.30.124 1521"
			//			fieldHostConfig.CfgHostName = databaseMapIt->second.m_sUserName.c_str();		// 数据库登陆用户
			//			fieldHostConfig.CfgAttend   = databaseMapIt->second.m_sPassword.c_str();		// 数据库登陆密码
			CDBConnectString DBInfo;
			char *p;
			char szTmp[200] = "";
			strcpy(szTmp, fieldConfigInfo.CfgLocation);

			// Mod by Henchi, 20100322 添加数据库结点信息项
			DBInfo.m_sServiceName = strtok(szTmp, " ");
			p = strtok(NULL, " ");
			if (p)
			{
				DBInfo.m_sRacServiceName = p;
			}

			p = strtok(NULL, " ");
			if (p)
			{
				DBInfo.m_sIpAddr = p;
			}

			p = strtok(NULL, " ");
			if (p)
			{
				DBInfo.m_nPort = atoi(p);
			}

			DBInfo.m_sUserName = fieldConfigInfo.CfgHostName.getValue();
			DBInfo.m_sPassword = fieldConfigInfo.CfgAttend.getValue();

			//g_pCDBSpiThread->UpdateDatabaseInfoMap(string(fieldConfigInfo.CfgName.getValue()),DBInfo);
			g_pCDBSpiThread->UpdateConfig(&fieldConfigInfo);

			printf(
				"01  %-12s --- %s %s %s \n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName,
				(const char *)fieldConfigInfo.CfgAttend);
			fflush(stdout);
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_SP) == 0)
		{
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_SP	;					// 存储过程采样配置类
			//			fieldHostConfig.CfgName     = SPMapIt->second.m_sUserName.c_str();		// 存储过程别名
			//			fieldHostConfig.CfgLocation = SPMapIt->second.m_sIpAddr.c_str();		// 存储过程采样时间串
			//			fieldHostConfig.CfgHostName = SPMapIt->second.m_sRacServiceName.c_str();		// 数据库别名
			//			fieldHostConfig.CfgAttend   = SPMapIt->second.m_sPassword.c_str();		// 类型标识:是否为游标
			g_pCDBSpiThread->UpdateConfig(&fieldConfigInfo);

			//g_pCDBSpiThread->UpdateSPInfoMap(fieldConfigInfo.CfgName.getValue(), fieldConfigInfo.CfgLocation.getValue(),
			//	fieldConfigInfo.CfgHostName.getValue(), fieldConfigInfo.CfgAttend.getValue());
			printf(
				"02  %-12s --- %s %s %s \n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName,
				(const char *)fieldConfigInfo.CfgAttend);
			fflush(stdout);
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_DBLOG) == 0)
		{
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DBLOG	;					// DBLog采样配置类
			//			fieldHostConfig.CfgName     = DBLogMapIt->second.m_sUserName.c_str();	// DBLog名
			//			fieldHostConfig.CfgLocation = DBLogMapIt->second.m_sIpAddr.c_str();		// DBLog采样时间串
			//			fieldHostConfig.CfgHostName = DBLogMapIt->second.m_sRacServiceName.c_str();		// 数据库别名
			//			fieldHostConfig.CfgAttend   = "";										// 此处留空
			g_pCDBSpiThread->UpdateConfig(&fieldConfigInfo);

			//g_pCDBSpiThread->UpdateDBLogMap(fieldConfigInfo.CfgName.getValue(), fieldConfigInfo.CfgLocation.getValue(),
			//	fieldConfigInfo.CfgHostName.getValue(),fieldConfigInfo.CfgAttend.getValue());
			printf(
				"03  %-12s --- %s %s\n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName);
			fflush(stdout);
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_SAN) == 0)
		{
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_SAN	;					// SAN采样配置类
			//			fieldHostConfig.CfgName     = SANMapIt->second.m_sRacServiceName.c_str();		// SAN别名
			//			fieldHostConfig.CfgLocation = SANMapIt->second.m_sIpAddr.c_str();		// SAN采样时间串
			//			fieldHostConfig.CfgHostName = SANMapIt->second.m_sUserName.c_str();		// 脚本文件路径
			//			fieldHostConfig.CfgAttend   = "";										// 此处留空
			if (NULL == g_pSANCaptureThread)
			{
				g_pSANCaptureThread = new CSANCaptureThread(
						fieldConfigInfo.CfgName.getValue(),
						fieldConfigInfo.CfgHostName.getValue(),
						fieldConfigInfo.CfgLocation.getValue());
				g_pSANCaptureThread->Create();
			}
			else
			{
				g_pSANCaptureThread->AddSANCapture(
						fieldConfigInfo.CfgName.getValue(),
						fieldConfigInfo.CfgHostName.getValue());
			}

			printf(
				"05  %-12s --- %s %s\n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName);
			fflush(stdout);
		}

		/// Added by Henchi, 20110705
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_SANEVENT) == 0)
		{
			//fieldHostConfig.CfgType     = HOSTCFG_REQTYPE_SANEVENT	;					// SANEvent采样配置类
			//fieldHostConfig.CfgName     = SANEventMapIt->second.m_sAlias.c_str();		// SANEvent别名
			//fieldHostConfig.CfgLocation = SANEventMapIt->second.m_sIpAddr.c_str();		// SANEvent采样时间串
			//fieldHostConfig.CfgHostName = SANEventMapIt->second.m_sUserName.c_str();	// EventLog 存放路径
			//fieldHostConfig.CfgAttend   = "";											// 此处留空
			if (NULL == g_pSANEventThread)
			{
				g_pSANEventThread = new CSANEventThread(
						fieldConfigInfo.CfgName.getValue(),
						fieldConfigInfo.CfgHostName.getValue(),
						fieldConfigInfo.CfgLocation.getValue());
				g_pSANEventThread->Create();
			}
			else
			{
				g_pSANEventThread->Reset(
						fieldConfigInfo.CfgName.getValue(),
						fieldConfigInfo.CfgHostName.getValue(),
						fieldConfigInfo.CfgLocation.getValue());
			}

			printf(
				"05  %-12s --- %s %s\n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName);
			fflush(stdout);
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_DBATTR) == 0)
		{
			//fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DBATTR	;				// 数据库监控对象信息类
			//fieldHostConfig.CfgName     = attrMapIt->first.c_str();					// 数据库监控对象名，如："dfmt.dfmtLen"
			//fieldHostConfig.CfgLocation = AttrTimerMap[attrMapIt->first].c_str();		// 采样定时器配置项，如："08:00:00-15:00:00.120,15:00:00-15:20:00.20"
			//fieldHostConfig.CfgHostName = (*listIt).m_sRacServiceName.c_str();				// 数据库别名，如："monitor1"
			//fieldHostConfig.CfgAttend   = (*listIt).m_sTableName.c_str();				// 数据库表名，如："table1"
			g_pCDBSpiThread->UpdateConfig(&fieldConfigInfo);

			//g_pCDBSpiThread->UpdateDBAttrMap(fieldConfigInfo.CfgName.getValue(), fieldConfigInfo.CfgLocation.getValue(),
			//	fieldConfigInfo.CfgHostName.getValue(), fieldConfigInfo.CfgAttend.getValue());
			printf(
				"04    %-12s --- %s %s %s \n",
				(const char *)fieldConfigInfo.CfgName,
				(const char *)fieldConfigInfo.CfgLocation,
				(const char *)fieldConfigInfo.CfgHostName,
				(const char *)fieldConfigInfo.CfgAttend);
			fflush(stdout);
		}

		itor.Next();

		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())	// 本次用户登录请求结束包
		{
			printf(
				"CProbeServer::OnReqUserLogout setStatus to true [%0x] [1]\n",
				(CFTDCSession *)pSession);
			fflush(stdout);
			g_mManageConSession.setStatus(pSession, 1);						// 到最终采集代理连接畅通，可以开始发送数据包到下行采集代理
			g_sendEvnFlag = false;

			if (g_pHostSpi == NULL)
			{
				g_pHostSpi = new COperatorSystemSpiImpl(g_pFlow);
			}

			if ((g_mDfmtLogMap.size() > 0) && (g_pDfmtLogSpi == NULL))
			{
				g_pDfmtLogSpi = new CSyslogSpiImpl(g_pFlow, &g_mDfmtLogMap);
				if (g_timerDfmtLog == 0)
				{
					g_timerDfmtLog = DEFAULT_TIMER;
				}
			}

			if ((g_mSessionLogMap.size() > 0) && (g_pSLogSpi == NULL))
			{
				g_pSLogSpi = new CSyslogSpiImpl(g_pFlow, &g_mSessionLogMap);
				if (g_timerSessionLog == 0)
				{
					g_timerSessionLog = DEFAULT_TIMER;
				}
			}

			if ((g_mSyslogNameMap.size() > 0) && (g_pSyslogSpi == NULL))
			{
				g_pSyslogSpi = new CSyslogSpiImpl(g_pFlow, &g_mSyslogNameMap);
				if (g_timerAppSyslog == 0)
				{
					g_timerAppSyslog = DEFAULT_TIMER;
				}
			}

			if ((g_mKeyFileNameMap.size() > 0) && (g_pKeyFileSpi == NULL))
			{
				g_pKeyFileSpi = new CSyslogSpiImpl(g_pFlow, &g_mKeyFileNameMap);
				if (g_timerKeyFile == 0)
				{
					g_timerKeyFile = DEFAULT_TIMER;
				}
			}

			if ((g_mMsgFileNameMap.size() > 0) && (g_pMsgFileSpi == NULL))
			{
				g_pMsgFileSpi = new CSyslogSpiImpl(g_pFlow, &g_mMsgFileNameMap);
				if (g_timerSystemLog == 0)
				{
					g_timerSystemLog = DEFAULT_TIMER;
				}
			}

			// 先发送主机初始信息包
			if (g_pHostSpi)
			{
				g_pHostSpi->GetSpi(pSession);
			}

			// 再发送主机名变更包
			if (bModFlag)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RtnUpdateSysConfigTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &sysConfigInfo);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			///本次请求登录的包结束,检查需要启动的spi实例
			break;
		}
	}
}

void CProbeServer::DoReqQryHostConfig(CFTDCSession *pSession)
{
	CFTDReqQryHostConfigField fieldConfigInfo;
	memset(&fieldConfigInfo, 0, sizeof(fieldConfigInfo));
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryHostConfigTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	fieldConfigInfo.CfgType = "GetProbeConfig";
	fieldConfigInfo.CfgName = g_sProbeName.c_str();
	fieldConfigInfo.CfgAttend = g_sProbeLocation.c_str();
	FTDC_ADD_FIELD(&m_pkgSend, &fieldConfigInfo);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CProbeServer::OnReqUserLogout(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLogoutField	fieldInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo))
	{
		if (strcmp("Connect", fieldInfo.UserID.getValue()) == 0)
		{
			if (g_mManageConSession.getStatus(pSession) == 1)
			{	// 已经取到配置信息,不需要再取了
				return;
			}

			// 向后发送的连接可能畅通，探针发送请求配置信息
			DoReqQryHostConfig(pSession);
		}
		else if (strcmp("Disconnect", fieldInfo.UserID.getValue()) == 0)
		{
			// 向后发送的连接已经断开，探针需要关闭本会话的所有信息(连接不关闭)
			printf(
				"CProbeServer::OnReqUserLogout setStatus to false [%0x] [-1]\n",
				(CFTDCSession *)pSession);
			g_mManageConSession.setStatus(pSession, -1);	// 连接存在,但不发送任何数据到下行的采集代理
			g_mManageConSession.delSyslog(
					(CFTDCSession *)pSession,
					g_mSyslogNameMap);
			g_mManageConSession.delSyslog(
					(CFTDCSession *)pSession,
					g_mKeyFileNameMap);
			g_mManageConSession.delSyslog(
					(CFTDCSession *)pSession,
					g_mMsgFileNameMap);
			g_mManageConSession.delSyslog(
					(CFTDCSession *)pSession,
					g_mSessionLogMap);
			g_mManageConSession.delSyslog(
					(CFTDCSession *)pSession,
					g_mDfmtLogMap);
		}
	}
}

void CProbeServer::OnSessionConnected(CSession *pSession)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionConnected(pSession);	// 子类调用父类处理连接断开事件
	time_t	timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionConnected: CFTDCSession %0x  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	g_sendEvnFlag = false;

	// 向后发送的连接可能畅通，探针发送请求配置信息
	//DoReqQryHostConfig(pSession);
}

void CProbeServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	time_t	timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionDisconnected: CFTDCSession %0x Disconnected!  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	g_mManageConSession.delSession((CFTDCSession *)pSession);
	g_mManageConSession.delSyslog((CFTDCSession *)pSession, g_mSyslogNameMap);
	g_mManageConSession.delSyslog((CFTDCSession *)pSession, g_mKeyFileNameMap);
	g_mManageConSession.delSyslog((CFTDCSession *)pSession, g_mMsgFileNameMap);
	g_mManageConSession.delSyslog((CFTDCSession *)pSession, g_mSessionLogMap);
	g_mManageConSession.delSyslog((CFTDCSession *)pSession, g_mDfmtLogMap);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);		// 子类调用父类处理连接断开事件
}

void CProbeServer::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	g_sendEvnFlag = false;

	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	// Mod by Henchi, 20100108
		/// 当新交易日信息与当前交易日一致则不作处理
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0
	&&	strcmp(fieldChange.NewDate.getValue(), g_mTradeDay) != 0)	// 更换交易日处理
	{
		//1.设置本地交易日信息
		strcpy(g_mTradeDay, fieldChange.NewDate.getValue());

		//2.清除本session的所有读取记录信息
		//遇到切换交易日则认为向后发送的连接已经断开，探针需要关闭本会话的所有信息(连接不关闭)
		//printf("CProbeServer::OnReqQryTradeDayChange setStatus to false [%0x] [-1]\n",(CFTDCSession *)pSession);
		//fflush(stdout);
		//g_mManageConSession.setStatus(pSession,-1); // 连接存在,但不发送任何数据到下行的采集代理
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mSyslogNameMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mKeyFileNameMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mMsgFileNameMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mSessionLogMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mDfmtLogMap);
		//3.重新发送请求配置信息
		//CFTDReqQryHostConfigField fieldConfigInfo;
		//m_pkgSend.PreparePackage(FTD_TID_ReqQryHostConfigTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		//fieldConfigInfo.CfgType="GetProbeConfig";
		//FTDC_ADD_FIELD(&m_pkgSend, &fieldConfigInfo);
		//((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		//g_sendEvnFlag = false;
	}
}

void CProbeServer::OnReqQryDBQuery(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryDBQueryField	fieldInfo;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldInfo);
	g_pCDBSpiThread->UpdateSPQuery(
			fieldInfo.ObjectID.getValue(),
			fieldInfo.AttrType.getValue(),
			pFTDCPackage->GetRequestId(),
			pSession);
}

void CProbeServer::addDBAttr(
	const char	*attrName,
	const CTableDBRelation	&tableinfo)
{
	//map<string, listTDB>::iterator	it;
	//it = g_mDBAttrMap.find(string(attrName));
	//if (it!=g_mDBAttrMap.end()) 		// 数据库监控指标已存在,只需要增加库表
	//{
	//	listTDB::iterator listIt = find(it->second.begin(),it->second.end(),tableinfo);
	//	if (listIt == it->second.end())
	//	{
	//		it->second.push_back(tableinfo);
	//	}
	//} else
	//{
	//	listTDB tableinfoList;
	//	tableinfoList.push_back(tableinfo);
	//	g_mDBAttrMap[attrName] = tableinfoList;
	//}
}

// 20101207 by zhou.jj
#if 0
void CProbeReactor::DispatchIOs(void)
{
	DWORD dwSelectTimeOut = m_dwSelectTimeOut;
	bool bRdFlag = false;
	if (g_pSyslogSpi)
	{
		bRdFlag = g_pSyslogSpi->DispatchIOsSpi() || bRdFlag;
	}

	if (bRdFlag)
	{
		//printf("DispatchIOs:TimeOut 0\n");
		m_dwSelectTimeOut = 0;
	}
	else
	{
		//printf("DispatchIOs:TimeOut 1\n");
	}

	CSelectReactor::DispatchIOs();
	m_dwSelectTimeOut = dwSelectTimeOut;
}

#endif
