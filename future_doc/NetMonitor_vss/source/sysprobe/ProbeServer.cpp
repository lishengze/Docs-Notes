/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	ProbeServer.cpp
///@brief	ʵ����̽������ɼ���������ʹ�õ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20090305	�̺״�		�޸�̽�����Ϊ�������������֮ǰ����ENV����������Ϣ
///20120309	�̺״�		Session��������ѹ��CRPCM_ZERO
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
extern char g_mTradeDay[9];					// ������
extern char g_pHostName[32];				// ������������
extern char g_pDataCenterName[32];			// ���������������ƣ���TRADE.PuDian
extern char g_pCenterName[32];				// ���洿�����������ƣ���PuDian��ZhangJ
bool g_sendEvnFlag = false;
COperatorSystemSpiImpl	*g_pHostSpi = NULL; // �����ɼ�spiʵ����ָ��
CSyslogSpiImpl	*g_pSyslogSpi = NULL;		// ҵ��ϵͳ��־�ɼ�spiʵ����ָ��
CSyslogSpiImpl	*g_pKeyFileSpi = NULL;		// ҵ��ؼ��ļ��ɼ�spiʵ����ָ��
CSyslogSpiImpl	*g_pMsgFileSpi = NULL;		// ����ϵͳ��־�ɼ�spiʵ����ָ��
CSyslogSpiImpl	*g_pSLogSpi = NULL;			// �������ļ��ɼ�spiʵ����ָ��
CSyslogSpiImpl	*g_pDfmtLogSpi = NULL;		// dfmt�ļ��ɼ�spiʵ����ָ��
int g_timerHostAcitve = 1;					// ����Active���,ֵΪ0ʱ��ʾ���������¼�����ͬ
int g_timerHostEnv = 0;						// ��������ʱ����
int g_timerCPU = 0;						// CPUʱ����
int g_timerMemory = 0;					// �ڴ�ʱ����
int g_timerProcess = 0;					// ����ʱ����
int g_timerDisk = 0;					// ����ʱ����
int g_timerUser = 0;					// �����û�ʱ����
int g_timerNetwork = 0;					// ����ɼ�ʱ����
int g_timerNetStat = 0;					// netstat��Ϣ�ɼ�ʱ����
int g_timerAppSyslog = 0;				// ҵ�������־�ɼ���ʱ�����
int g_timerSessionLog = 0;				// ��������־�ļ��ɼ���ʱ�����
int g_timerSystemLog = 0;				// ����ϵͳ��־�ļ��ɼ���ʱ�����
int g_timerKeyFile = 0;					// ҵ��ϵͳ�ؼ��ļ��ɼ���ʱ�����
int g_timerDfmtLog = 0;					// DFMT�ļ��ɼ���ʱ�����
int g_timerDatabase = 0;				// ���ݿ�ɼ���ʱ�����
int g_timerDiskIO = 0;					// ����I/O��Ϣ�ɼ���ʱ�����
int g_timerRouter = 0;					// ϵͳ·����Ϣ�ɼ���ʱ�����
int g_timerKernel = 0;					// ϵͳ�ؼ���Ϣ�ɼ���ʱ�����
int g_timerStatInfo = 0;				// ϵͳ״̬��Ϣ�ɼ���ʱ�����
#define XML_VAL_TIMER_DISKIO	"DiskIO"
#define XML_VAL_TIMER_ROUTER	"Router"
#define XML_VAL_TIMER_KERNEL	"Kernel"
#define XML_VAL_TIMER_STATINFO	"StatInfo"

MapConSyslog g_mSyslogNameMap;			// ҵ��ϵͳ�ɼ��ļ���Ϣ
MapConSyslog g_mKeyFileNameMap;			// ҵ��ϵͳ�ؼ��ļ���Ϣ
MapConSyslog g_mMsgFileNameMap;			// ����ϵͳ��־�ļ���Ϣ
MapConSyslog g_mSessionLogMap;			// �������ļ���Ϣ
MapConSyslog g_mDfmtLogMap;				// DFMT�ļ���Ϣ
map<string, string> g_mSpcPrcMap;		// ҵ�������������Ӳ�̷���ӳ��
CManageConSession g_mManageConSession;	// �����������ӵĵ�ַ��Ϣ
char *g_szHostEnvFile = NULL;			// ����������Ϣ�ļ�����·����
char *g_szNetConfFile = NULL;			// ��������������Ϣ�ļ�����·����
CDBSpiThread *g_pCDBSpiThread = NULL;	// ���ݿ��߳�ָ��
CFileCheckThread *g_pFileCheckThread = NULL;			// �ļ�У���߳�ָ��
CSANCaptureThread *g_pSANCaptureThread = NULL;			// ��ȡSAN�߳�ָ��
CSANEventThread *g_pSANEventThread = NULL;				// SAN Event�ɼ��߳�ָ��
CWebLogStatSpiThread *g_pWebLogStatSpiThread = NULL;	// ��վ������־ͳ���߳�ָ��

// add by cao.ning
// ϵͳ�ڲ���������
extern CSysInternalTopology* g_SysInternalTopology;

///�����������ڱ���������Ϣ
static CMutex s_lockProcInfo;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;						// ���ݰ�������ļ�
#endif
#undef WINDOWS_CPUUSAGE_DEBUG
CProbeTimmer::CProbeTimmer(CReactor *pReactor) :
	CEventHandler(pReactor)
{
	m_nEventId = 0;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
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
		/// ������Ϣ�ɼ�ʱ������ಢ��
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
		/// ������Ϣ�ɼ��Ļ�����
		s_lockProcInfo.UnLock();

		if (g_pMsgFileSpi != NULL)
		{
			if (g_timerSystemLog)
			{
				if (mTime % g_timerSystemLog == 0)
				{
					g_pMsgFileSpi->GetSpi();		// ȡ������־spi
				}
			}
		}

		if (g_pKeyFileSpi != NULL)
		{
			if (g_timerKeyFile)
			{
				if (mTime % g_timerKeyFile == 0)
				{
					g_pKeyFileSpi->GetTotalSpi();	// ȡ�ؼ��ļ�spi
				}
			}
		}

		if (g_pSLogSpi != NULL)
		{
			if (g_timerSessionLog)
			{
				if (mTime % g_timerSessionLog == 0)
				{
					g_pSLogSpi->GetBinSpi();		// ȡslog�ļ�spi
				}
			}
		}

		if (g_pDfmtLogSpi != NULL)
		{
			if (g_timerDfmtLog)
			{
				if (mTime % g_timerDfmtLog == 0)
				{
					g_pDfmtLogSpi->GetSizeSpi();	// ȡdfmt�ļ���Сspi
				}
			}
		}

		if (g_pCDBSpiThread != NULL)
		{
			g_pCDBSpiThread->GetSpi();				// ȡ���ݿ�ָ��spi
		}

		if (g_pFileCheckThread != NULL)
		{
			g_pFileCheckThread->GetSpi();			// ��վ���۸�spi
		}

		if (g_pSANCaptureThread != NULL)
		{
			g_pSANCaptureThread->GetSpi();			// SANָ��spi
		}

		if (g_pWebLogStatSpiThread != NULL)
		{
			g_pWebLogStatSpiThread->GetSpi();		// ��վ������ͳ��spi
		}

		return;
	}
	else if (nIDEvent == 2)
	{
		if (g_pSyslogSpi != NULL)
		{
			g_pSyslogSpi->GetSpi();					// ȡҵ�������־spi
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

string	g_sProbeLocation;						// ̽���ַ tcp://172.16.94.21:33312,sysprobe
string	g_sProbeName;							// ̽����� TRADELOG-FE76
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
				/// ���յ����Զ���ɼ�����(����ת,ֱ��EventCounter)��̽������Ϣ
				CFTDRtnMonitorObjectField fieldObject;
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldObject);
				g_sProbeLocation = fieldObject.ObjectID.getValue();
				g_sProbeName = fieldObject.ObjectName.getValue();

				/// ������������������Ϣ
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
	pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
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
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif
	if (g_mManageConSession.getStatus(pSession) == 1)
	{	// �������Ѿ�ȡ����������Ϣ,����Ҫ�ٴ�����
		printf(
			"CProbeServer::OnReqUserLogin Session [%0x] Status 1\n",
			(CFTDCSession *)pSession);
		printf("g_mSyslogNameMap size %d\n", g_mSyslogNameMap.size());

		///@param	pname	��ȡ���ļ���(��·��)
				///@param	pType	�ļ�������(syslog,applog,keyfile,slog,dfmt�ļ�)
				///@param	pFileName	�ļ���Syslog.log, ������dfmt.dfmtLen��dfmt�ļ��ž߱�����������������Ϊ����·�����ļ�����
				///@param	pObjectID	����ID,��PuDian.os.AC-01.applog
				///@param	pConn	�ɼ��������Ӵ���Ϣ
				///@param	pHaveRead	�ɼ������Ѿ���ȡ�����ļ�����
				///@param	pReadTime	�ɼ������Ѿ���ȡ�����ļ�ʱ��
				///@param	pProbeLoation	̽��ĵ�ַ��Ϣ
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

		/// by zhou.jj 20100407 �������ñ����Ϣ������ֱ�ӷ���
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
		fieldRspInfo.ErrorMsg = "�ɹ�";
		fieldRspInfo.ErrorID = 0;
		FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	MapConSyslog::iterator	logit;
	CFTDRspQryHostConfigField fieldConfigInfo;
	static CFTDRtnUpdateSysConfigField	sysConfigInfo;	// ϵͳ��Ϣ�����
	static bool bModFlag = false;						// �Ƿ���������������ı�ʶ
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
			// fieldHostConfig.CfgName     = g_mTradeDay			;	// ������
			// fieldHostConfig.CfgLocation = pProbeCfg->GetLocation() ; // ��ȡ̽���ַ
			// fieldHostConfig.CfgHostName = pProbeCfg->GetHostName() ; // ��ȡ������
			// fieldHostConfig.CfgAttend   = pProbeCfg->GetDataCenter(); // ��ȡ������������������
			
			// Mod by Henchi, 20100108
			// Mod by zhou.jj 20100128 ���·ſ�
			/// ��������Ϣֻ��������ʼ������OnReqQryTradeDayChange()�������и��£������ط���������
			strcpy(g_mTradeDay, fieldConfigInfo.CfgName.getValue());

			// Mod by Henchi, 20130513
			// ϵͳ��ʶ����������������̬����
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
					// ���ϵͳȡ����������Ϊ�գ������̽�����õ����ƣ������ͱ�����ݰ�
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
						else						// ������������ϵͳȡ�������ֲ���ͬ����������������ݱ�
						{
							//fieldInfo.UpdateType:�������������
							sysConfigInfo.UpdateType = UPDATESYSCONFIG_HOSTNAME;

							//fieldInfo.OldValue:����̽�����õ���������
							sprintf(
								(char *)sysConfigInfo.OldValue.getValue(),
								"%s.%s.%s",
								g_pDataCenterName,
								DATACENTERHOST,
								fieldConfigInfo.CfgHostName.getValue());

							//fieldInfo.NewValue:����ϵͳȡ������������
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

			/// ����������Ϣ�̵߳Ķ������Ʊ�ʶ
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
				printf("\t �ɼ�̽���ַ����û��ȡ��������! \n");
				fflush(stdout);
			}
		}
		else if (strcmp(
					 fieldConfigInfo.CfgType.getValue(),
				 HOSTCFG_REQTYPE_TIMER) == 0)
		{
			// 			fieldHostConfig.CfgType  = HOSTCFG_REQTYPE_TIMER  ;  // ��ʱ��������
			// 			fieldHostConfig.CfgName     = timerMapIt->first.c_str() ; // ��ʱ��������
			// 			fieldHostConfig.CfgLocation = "";  // ���ֶ�����
			// 			fieldHostConfig.CfgHostName = "";  // ���ֶ�����
			// 			fieldHostConfig.CfgAttend   = timerMapIt->second  ; // ��ʱ��ʱ����(��)
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
			// fieldHostConfig.CfgType  = HOSTCFG_REQTYPE_CFGFILE ; // �������������ļ���
			// fieldHostConfig.CfgName     = configMapIt->first.c_str(); // �����ļ���
			// fieldHostConfig.CfgLocation = configMapIt->second.c_str(); // �����ļ�·��
			// fieldHostConfig.CfgHostName = "";  // ���ֶ�����
			// fieldHostConfig.CfgAttend   = "";  // ���ֶ�����
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
			// fieldHostConfig.CfgType  = HOSTCFG_REQTYPE_APPROOT ;  // Ӧ�ý��̷�����
			// fieldHostConfig.CfgName     = apppathMapIt->first.c_str();  // Ӧ�ý�����
			// fieldHostConfig.CfgLocation = apppathMapIt->second.c_str();  // Ӧ�ý������ڷ���
			// fieldHostConfig.CfgHostName = "";  // ���ֶ�����
			// fieldHostConfig.CfgAttend   = "";  // ���ֶ�����
			
			printf("CFG_SPCPROC[%s %s]\n", (char *)fieldConfigInfo.CfgName.getValue(),
				(char *)fieldConfigInfo.CfgLocation.getValue()
			);
			/// ������Ϣ������
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
			if (logit == g_mSyslogNameMap.end())	// ����־�ļ����ڲɼ���
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
			if (logit == g_mMsgFileNameMap.end())	// ����־�ļ����ڲɼ���
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
			if (logit == g_mKeyFileNameMap.end())	// ����־�ļ����ڲɼ���
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
			if (logit == g_mSessionLogMap.end())	// ����־�ļ����ڲɼ���
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

			// 						fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DFMTLOG	;			// DFMT�ļ���
			// 						fieldHostConfig.CfgName     = dfmtMapIt->first.c_str();		// DFMT������
			// 						fieldHostConfig.CfgLocation = dfmtMapIt->second.c_str();		// DFMT�ļ�·��
			// 						fieldHostConfig.CfgHostName = "";		// ���ֶ�����
			// 						fieldHostConfig.CfgAttend   = "";		// ���ֶ�����
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
			if (logit == g_mDfmtLogMap.end())		// ����־�ļ����ڲɼ���
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
			//fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_WEBSITE	;					// ��վ�ļ�У��������
			//fieldHostConfig.CfgName     = filecodeMapIt->second.m_sRacServiceName.c_str();		// ��У���ļ�·��
			//fieldHostConfig.CfgLocation = filecodeMapIt->second.m_sRacServiceName.c_str();		// У���ļ�����·��
			//fieldHostConfig.CfgHostName = filecodeMapIt->second.m_sIpAddr.c_str();		// ����ʱ��
			//fieldHostConfig.CfgAttend   = "";		// ���ֶ�����
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
			//fieldHostConfig.CfgType	  = HOSTCFG_REQTYPE_WEBSITECODE	;						// ��վ״̬��У��������
			//fieldHostConfig.CfgName     = WebsiteCodeMapIt->second.m_sRacServiceName.c_str();			// ��վ������
			//fieldHostConfig.CfgLocation = WebsiteCodeMapIt->second.m_sUserName.c_str();		// ��վ״̬��У��URL
			//fieldHostConfig.CfgHostName = WebsiteCodeMapIt->second.m_sIpAddr.c_str();			// ����ʱ��
			//fieldHostConfig.CfgAttend   = WebsiteCodeMapIt->second.m_sPassword.c_str();		// ��վ�Ϸ�״̬��ʶ��
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
				printf("��վ״̬��У��URL���ø�ʽ����ȷ\n");
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
			//fieldHostConfig.CfgType	  = HOSTCFG_REQTYPE_ACCESSLOG	;						// ��վ������־������Ϣ��
			//fieldHostConfig.CfgName     = AccessLogMapIt->second.m_sRacServiceName.c_str();			// ��վ��������
			//fieldHostConfig.CfgLocation = AccessLogMapIt->second.m_sIpAddr.c_str();			// ������־·��
			//fieldHostConfig.CfgHostName = AccessLogMapIt->second.m_sUserName.c_str();		// ������־ͳ��ʱ��Ƶ��
			//fieldHostConfig.CfgAttend   = AccessLogMapIt->second.m_sPassword.c_str();		// ������־ͳ�Ʒ�Χ����
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
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DATABASE	;		// ���ݿ�������Ϣ��
			//			fieldHostConfig.CfgName     = databaseMapIt->first.c_str();		// ���ݿ����
			//			fieldHostConfig.CfgLocation = szDatabase;						// ���ݿ����������磺"monitor1 monitor 172.16.30.124 1521"
			//			fieldHostConfig.CfgHostName = databaseMapIt->second.m_sUserName.c_str();		// ���ݿ��½�û�
			//			fieldHostConfig.CfgAttend   = databaseMapIt->second.m_sPassword.c_str();		// ���ݿ��½����
			CDBConnectString DBInfo;
			char *p;
			char szTmp[200] = "";
			strcpy(szTmp, fieldConfigInfo.CfgLocation);

			// Mod by Henchi, 20100322 ������ݿ�����Ϣ��
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
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_SP	;					// �洢���̲���������
			//			fieldHostConfig.CfgName     = SPMapIt->second.m_sUserName.c_str();		// �洢���̱���
			//			fieldHostConfig.CfgLocation = SPMapIt->second.m_sIpAddr.c_str();		// �洢���̲���ʱ�䴮
			//			fieldHostConfig.CfgHostName = SPMapIt->second.m_sRacServiceName.c_str();		// ���ݿ����
			//			fieldHostConfig.CfgAttend   = SPMapIt->second.m_sPassword.c_str();		// ���ͱ�ʶ:�Ƿ�Ϊ�α�
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
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DBLOG	;					// DBLog����������
			//			fieldHostConfig.CfgName     = DBLogMapIt->second.m_sUserName.c_str();	// DBLog��
			//			fieldHostConfig.CfgLocation = DBLogMapIt->second.m_sIpAddr.c_str();		// DBLog����ʱ�䴮
			//			fieldHostConfig.CfgHostName = DBLogMapIt->second.m_sRacServiceName.c_str();		// ���ݿ����
			//			fieldHostConfig.CfgAttend   = "";										// �˴�����
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
			//			fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_SAN	;					// SAN����������
			//			fieldHostConfig.CfgName     = SANMapIt->second.m_sRacServiceName.c_str();		// SAN����
			//			fieldHostConfig.CfgLocation = SANMapIt->second.m_sIpAddr.c_str();		// SAN����ʱ�䴮
			//			fieldHostConfig.CfgHostName = SANMapIt->second.m_sUserName.c_str();		// �ű��ļ�·��
			//			fieldHostConfig.CfgAttend   = "";										// �˴�����
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
			//fieldHostConfig.CfgType     = HOSTCFG_REQTYPE_SANEVENT	;					// SANEvent����������
			//fieldHostConfig.CfgName     = SANEventMapIt->second.m_sAlias.c_str();		// SANEvent����
			//fieldHostConfig.CfgLocation = SANEventMapIt->second.m_sIpAddr.c_str();		// SANEvent����ʱ�䴮
			//fieldHostConfig.CfgHostName = SANEventMapIt->second.m_sUserName.c_str();	// EventLog ���·��
			//fieldHostConfig.CfgAttend   = "";											// �˴�����
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
			//fieldHostConfig.CfgType		= HOSTCFG_REQTYPE_DBATTR	;				// ���ݿ��ض�����Ϣ��
			//fieldHostConfig.CfgName     = attrMapIt->first.c_str();					// ���ݿ��ض��������磺"dfmt.dfmtLen"
			//fieldHostConfig.CfgLocation = AttrTimerMap[attrMapIt->first].c_str();		// ������ʱ��������磺"08:00:00-15:00:00.120,15:00:00-15:20:00.20"
			//fieldHostConfig.CfgHostName = (*listIt).m_sRacServiceName.c_str();				// ���ݿ�������磺"monitor1"
			//fieldHostConfig.CfgAttend   = (*listIt).m_sTableName.c_str();				// ���ݿ�������磺"table1"
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

		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())	// �����û���¼���������
		{
			printf(
				"CProbeServer::OnReqUserLogout setStatus to true [%0x] [1]\n",
				(CFTDCSession *)pSession);
			fflush(stdout);
			g_mManageConSession.setStatus(pSession, 1);						// �����ղɼ��������ӳ�ͨ�����Կ�ʼ�������ݰ������вɼ�����
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

			// �ȷ���������ʼ��Ϣ��
			if (g_pHostSpi)
			{
				g_pHostSpi->GetSpi(pSession);
			}

			// �ٷ��������������
			if (bModFlag)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RtnUpdateSysConfigTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &sysConfigInfo);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			///���������¼�İ�����,�����Ҫ������spiʵ��
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
			{	// �Ѿ�ȡ��������Ϣ,����Ҫ��ȡ��
				return;
			}

			// ����͵����ӿ��ܳ�ͨ��̽�뷢������������Ϣ
			DoReqQryHostConfig(pSession);
		}
		else if (strcmp("Disconnect", fieldInfo.UserID.getValue()) == 0)
		{
			// ����͵������Ѿ��Ͽ���̽����Ҫ�رձ��Ự��������Ϣ(���Ӳ��ر�)
			printf(
				"CProbeServer::OnReqUserLogout setStatus to false [%0x] [-1]\n",
				(CFTDCSession *)pSession);
			g_mManageConSession.setStatus(pSession, -1);	// ���Ӵ���,���������κ����ݵ����еĲɼ�����
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

void CProbeServer::OnSessionConnected(CSession *pSession)	// �������ش������ӶϿ��¼�
{
	CSessionFactory::OnSessionConnected(pSession);	// ������ø��ദ�����ӶϿ��¼�
	time_t	timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionConnected: CFTDCSession %0x  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	g_sendEvnFlag = false;

	// ����͵����ӿ��ܳ�ͨ��̽�뷢������������Ϣ
	//DoReqQryHostConfig(pSession);
}

void CProbeServer::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
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
	CSessionFactory::OnSessionDisconnected(pSession, nReason);		// ������ø��ദ�����ӶϿ��¼�
}

void CProbeServer::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	g_sendEvnFlag = false;

	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	// Mod by Henchi, 20100108
		/// ���½�������Ϣ�뵱ǰ������һ����������
	if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0
	&&	strcmp(fieldChange.NewDate.getValue(), g_mTradeDay) != 0)	// ���������մ���
	{
		//1.���ñ��ؽ�������Ϣ
		strcpy(g_mTradeDay, fieldChange.NewDate.getValue());

		//2.�����session�����ж�ȡ��¼��Ϣ
		//�����л�����������Ϊ����͵������Ѿ��Ͽ���̽����Ҫ�رձ��Ự��������Ϣ(���Ӳ��ر�)
		//printf("CProbeServer::OnReqQryTradeDayChange setStatus to false [%0x] [-1]\n",(CFTDCSession *)pSession);
		//fflush(stdout);
		//g_mManageConSession.setStatus(pSession,-1); // ���Ӵ���,���������κ����ݵ����еĲɼ�����
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mSyslogNameMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mKeyFileNameMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mMsgFileNameMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mSessionLogMap);
		//g_mManageConSession.delSyslog((CFTDCSession *)pSession,g_mDfmtLogMap);
		//3.���·�������������Ϣ
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
	//if (it!=g_mDBAttrMap.end()) 		// ���ݿ���ָ���Ѵ���,ֻ��Ҫ���ӿ��
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
