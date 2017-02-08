/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApiImpl.cpp
///@brief 实现了客户端接口
///@history 
///20060106	赵鸿昊  创建该文件
///20061012	赵鸿昊  增加对SSL身份校验的支持
///20070216	章捷    改变流控方法.userapi不做流控，tradeapi做流控。
///20070806	赵鸿昊  增加方法：
///                 SubscribeUserTopic 订阅交易员流。
///                 SetHeartbeatTimeout 设置心跳超时时间。
///                 OpenRequestLog 打开请求日志文件
///                 OpenResponseLog 打开应答日志文件
///20070921 赵鸿昊 将流文件由二进制改为文本
///20070924 赵鸿昊 调整继承关系，以支持nameserver
// 20080227 赵鸿昊 修正BUG：OnSessionWarning中，对警告原因的判断应为
//                 MSG_XMPWARNING_RECVHEARTBEAT,原误为MSG_XMPERR_BADPACKAGE
// 20080727 赵鸿昊 NT-0048:扩展CSessionFactory::CreateSession参数，便于创建
//                 会话时区分不同的连接
// 20090121 赵鸿昊 NT-0066:心跳超时时间缺省值改为30秒
// 20090213 赵鸿昊 NT-0067:修正OnPackageStart,OnPackageEnd回调参数错误问题
// 20090428 赵鸿昊 NT-0071:心跳超时时间缺省值改为10秒
// 20090504 赵鸿昊 NT-0072:修正UserAPI流控线程不安全问题
// 20090505 赵鸿昊 NT-0073:修正UserAPI数据流续传管理问题
//                         修正对话流缓冲区溢出问题
//                         版本信息中增加用日期时间表示的小版本号
// 20110509 江鹏   NT-0131 UserAPI功能完善：对用户的频繁登录做了限制
// 20110624 江鹏   NT-0139 加快响应时间
// 20120314 江鹏   NT-0168 修正userapi的流控多线程错误
///20120730 孙尧宇	NT-0170 对流控和日志进行完善
/////////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FtdcUserApiImplBase.h"
#include "CachedFileFlow.h"
#include "FileFlow.h"
#include "CDate.h"
#include "UFCopy.h"
#include "SslNetworkFactory.h"
#include "CSVParser.h"

/**CFtdcUserDialogFlow是线程安全的CCachedFlow
*对于会话流，应用程序线程和API线程会同时访问，必须加以保护
*/
class CFtdcUserDialogFlow : public CCachedFlow
{
public:
	CFtdcUserDialogFlow(bool bSyncFlag, int nMaxObjects, int nDataBlockSize)
		:CCachedFlow(bSyncFlag, nMaxObjects, nDataBlockSize, false)
	{
		m_nCount = CCachedFlow::GetCount();
	}
	
	virtual int GetCount(void)
	{
		return m_nCount;
	}
	
	virtual bool Truncate(int nCount)
	{
		m_lock.Lock();
		bool bRet = CCachedFlow::Truncate(nCount);
		m_nCount = CCachedFlow::GetCount();
		m_lock.UnLock();
		return bRet;
	}

	virtual int Append(void *pObject, int length)
	{
		m_lock.Lock();
		int nRet = -1;
		if( m_nMaxObjects<=0 || m_NodeQueue.size()-m_nFirstID<m_nMaxObjects)
		{
			nRet = CCachedFlow::Append(pObject, length);
			m_nCount = CCachedFlow::GetCount();
		}
		m_lock.UnLock();
		return nRet;
	}

 	virtual int Get(int id, void *pObject, int length)
	{
		m_lock.Lock();
		int nRet = CCachedFlow::Get(id, pObject, length);
		m_nCount = CCachedFlow::GetCount();
		PopFront();
		m_lock.UnLock();
		return nRet;
	}
	
private:
	int m_nCount;
	CMutex m_lock;
};
class CUserFlow : public CFlow
{
public:
	CUserFlow(const char *pszFlowName, const char *pszPath, bool bReuse)
	{
		m_nCount= 0;
		m_wCommPhaseNo = 0;
		m_fpContentFile=NULL;
		OpenFile(pszFlowName, pszPath, bReuse);
	}
	CUserFlow(int nFlowID, const char *pszPath, bool bReuse)
	{
		char szFlowName[20];
		sprintf(szFlowName, "%08x", nFlowID);
		new (this) CUserFlow(szFlowName, pszPath, bReuse);
	}

	virtual ~CUserFlow()
	{
		CloseFile();
	}

	virtual int GetCount(void)
	{
		return m_nCount;
	}
	
	virtual const int *GetCountPtr(void)
	{
		return reinterpret_cast<const int *>(&m_nCount);
	}
	
	void SetCount(int nCount)
	{
		m_nCount = nCount;
		WriteFile();
	}

	virtual WORD GetCommPhaseNo()
	{
		return m_wCommPhaseNo;
	}

	virtual void SetCommPhaseNo(WORD nCommPhaseNo)
	{
		if (nCommPhaseNo != m_wCommPhaseNo)
		{
			m_wCommPhaseNo = nCommPhaseNo;
			m_nCount= 0;
			WriteFile();
		}
	}

	virtual bool Truncate(int nCount)
	{
//		if (m_nCount <= nCount)
//		{
//			return true;
//		}
		m_nCount= nCount;
		return WriteFile();
	}
	
	virtual int Append(void *pObject, int length)
	{
		m_nCount++;
		WriteFile();
		return m_nCount-1;		
	}

 	virtual int Get(int id, void *pObject, int length)
	{
		RAISE_RUNTIME_ERROR("Can't use this function - CUserFlow::Get\n");
		return 0;
	}

protected:	
	bool WriteFile()
	{
		fseek(m_fpContentFile, 0, SEEK_SET);
		if(fprintf(m_fpContentFile, "%5d,%10d\n", m_wCommPhaseNo, m_nCount) <= 0)
		{
			return false;
		}
		fflush(m_fpContentFile);
		return true;
	}
	void OpenFile(const char *pszFlowName, const char *pszPath, bool bReuse)
	{
		ASSERT(pszPath != NULL);
		m_nCount = 0;
		CloseFile();
		char szContentFilename[512];
		sprintf(szContentFilename, "%s%s.con", pszPath, pszFlowName);
		m_fpContentFile = mfopen(szContentFilename,"r+b");
		if (m_fpContentFile == NULL)
		{
			m_fpContentFile = mfopen(szContentFilename,"w+b");
			if(m_fpContentFile == NULL)
			{
				CloseFile();
				RAISE_RUNTIME_ERROR("can not open CFlow file");
			}			
		}
		
		fseek(m_fpContentFile, 0, SEEK_SET);
		if (!bReuse || fscanf(m_fpContentFile, "%d,%d\n", &m_wCommPhaseNo, &m_nCount)!=2)
		{
			if (!WriteFile())
			{
				CloseFile();
				RAISE_RUNTIME_ERROR("can not init CFlow file");
			}
		}
	}

	void CloseFile()
	{
		if(m_fpContentFile != NULL){
			fclose(m_fpContentFile);
			m_fpContentFile = NULL;
		}
	}

private:
	FILE *m_fpContentFile;			/**< 存储内容的文件 */
	DWORD m_nCount;					/**< 已经存在的包个数 */
	WORD m_wCommPhaseNo;			/**< 通讯阶段编号*/
};

class CFtdcUserFlowCtrlAutoPtr
{
public:
	CFtdcUserFlowCtrlAutoPtr(CMutex *pMutex)
	{
		m_pMutex = pMutex;
		m_pMutex->Lock();
	}
	~CFtdcUserFlowCtrlAutoPtr()
	{
		m_pMutex->UnLock();
	}
private:
	CMutex *m_pMutex;
};

#define FTDC_FLOWCTRL_SYNC		\
	CFtdcUserFlowCtrlAutoPtr __FtdcUserFlowCtrlAutoPtr(&m_mutexFlowControl);

/////////////////////////////////////////////////////////////////////////

CFtdcUserSubscriber::CFtdcUserSubscriber(CFtdcUserApiImplBase *pUserApiImplBase,
										 CFlow *pFlow, WORD wSequenceSeries)
{
	m_pUserApiImplBase = pUserApiImplBase;
	m_pFlow = pFlow;
	m_wSequenceSeries = wSequenceSeries;
	m_nCount = 0;
	m_wCommPhaseNo = 0;
	m_nResumeType = TERT_RESUME;

	if (wSequenceSeries == TSS_QUERY) {
#ifdef NGES_TRADEAPILIMIT
		m_nMaxUnfinished = MAXQUERYUNFINISHED;
		m_nMaxPerSecond  = MAXQUERYPERSECOND;
#else
		m_nMaxUnfinished = 0x7fffffff;
		m_nMaxPerSecond  = 0x7fffffff;
#endif
		m_nTimeoutForQueryFlow = 30;
		CleanControl();
	}
	
	if (wSequenceSeries == TSS_DIALOG) {
#ifdef NGES_TRADEAPILIMIT
		m_nMaxUnfinished = MAXDIALOGUNFINISHED;
		m_nMaxPerSecond  = MAXDIALOGPERSECOND;
#else
		m_nMaxUnfinished = 0x7fffffff;
		m_nMaxPerSecond  = 0x7fffffff;
#endif
		CleanControl();
	}
}

CFtdcUserSubscriber::~CFtdcUserSubscriber()
{
}

void CFtdcUserSubscriber::SetTradeMaxCommFlux(int nMaxCommFlux)
{
#ifdef NGES_TRADEAPILIMIT
	if(nMaxCommFlux>0&&m_wSequenceSeries==TSS_DIALOG)
	{
		m_nMaxPerSecond=nMaxCommFlux;
	}
#endif
	return;
}
void CFtdcUserSubscriber::SetTradeMaxOnWayCommFlux(int nMaxOnWayCommFlux)
{
#ifdef NGES_TRADEAPILIMIT
	if(nMaxOnWayCommFlux>0&&m_wSequenceSeries==TSS_DIALOG)
	{
		m_nMaxUnfinished=nMaxOnWayCommFlux;
	}
#endif
	return;
}
void CFtdcUserSubscriber::SetQueryMaxCommFlux(int nMaxCommFlux)
{
#ifdef NGES_TRADEAPILIMIT
	if(nMaxCommFlux>0&&m_wSequenceSeries==TSS_QUERY)
	{
		m_nMaxPerSecond=nMaxCommFlux;
	}
#endif
	return;
}
void CFtdcUserSubscriber::SetQueryMaxOnWayCommFlux(int nMaxOnWayCommFlux)
{
#ifdef NGES_TRADEAPILIMIT
	if(nMaxOnWayCommFlux>0&&m_wSequenceSeries==TSS_QUERY)
	{
		m_nMaxUnfinished=nMaxOnWayCommFlux;
	}
#endif
	return;
}
void CFtdcUserSubscriber::CleanControl(void)
{
	FTDC_FLOWCTRL_SYNC;
	m_nCntPerSecond = 0;
	m_lastTime = 0;
	m_nUnfinished.clear();
}

int CFtdcUserSubscriber::AddOneToFlow(void)
{
	FTDC_FLOWCTRL_SYNC;
	if (m_wSequenceSeries != TSS_QUERY && m_wSequenceSeries != TSS_DIALOG)
		return 0;

	time_t t = time(NULL);
	// check unfinished
	if (m_nUnfinished.size() >= m_nMaxUnfinished) {
		if (m_wSequenceSeries == TSS_DIALOG)
			return -2;
		
		// TSS_QUERY
		list<time_t>::iterator pos = m_nUnfinished.begin();
		if (pos != m_nUnfinished.end()) {
			time_t t2 = *pos;
			if (t - t2 > m_nTimeoutForQueryFlow) {
				m_nUnfinished.pop_front();
			} else {
				return -2;
			}
		}

	}

	// check pre-second
	if (t != m_lastTime) {
		m_nCntPerSecond = 1;
		m_lastTime = t;
	} else {
		if (m_nCntPerSecond >= m_nMaxPerSecond) {
			return -3;
		}
		++m_nCntPerSecond;
	}

	m_nUnfinished.push_back(t);
	return 0;
}

void CFtdcUserSubscriber::DequeueRequest(CFTDCPackage *pResponse)
{
	FTDC_FLOWCTRL_SYNC;

	if (m_wSequenceSeries == TSS_QUERY || m_wSequenceSeries == TSS_DIALOG) {
		if (pResponse->GetChain() == FTDC_CHAIN_LAST) {
			if (m_nUnfinished.size() > 0)
				m_nUnfinished.pop_front();
		}
	}
}

WORD CFtdcUserSubscriber::GetSequenceSeries()
{
	return m_wSequenceSeries;
}

DWORD CFtdcUserSubscriber::GetReceivedCount()
{
	if (m_pFlow == NULL)
	{
		return m_nCount;
	}
	return m_pFlow->GetCount();
}

void CFtdcUserSubscriber::SetCommPhaseNo(WORD wCommPhaseNo)
{
	if (m_pFlow != NULL)
	{
		m_pFlow->SetCommPhaseNo(wCommPhaseNo);
	}
	if (m_wCommPhaseNo != wCommPhaseNo)
	{
		m_nCount = 0;
		m_wCommPhaseNo = wCommPhaseNo;
	}
}

WORD CFtdcUserSubscriber::GetCommPhaseNo()
{
	if (m_pFlow != NULL)
	{
		return m_pFlow->GetCommPhaseNo();
	}
	return m_wCommPhaseNo;
}

void CFtdcUserSubscriber::HandleMessage(CFTDCPackage *pMessage)
{
	NET_IO_LOG0("CFtdcUserSubscriber::HandleMessage\n");
	FTDC_PACKAGE_DEBUG(pMessage);

	DequeueRequest(pMessage);

	//提交给上层应用程序
	m_pUserApiImplBase->HandleResponse(pMessage, m_wSequenceSeries);

	if (m_pFlow != NULL)
	{
		//将报文加入流中
		pMessage->Push(FTDCHLEN);
		m_pFlow->Append(pMessage->Address(), pMessage->Length());
		pMessage->Pop(FTDCHLEN);
	}
	m_nCount++;
}

TE_RESUME_TYPE CFtdcUserSubscriber::GetResumeType()
{
	return m_nResumeType;
}

void CFtdcUserSubscriber::SetResumeType(TE_RESUME_TYPE nResumeType)
{
	m_nResumeType = nResumeType;
}

void CFtdcUserSubscriber::MoveTo(int nOffset)
{
	if (m_pFlow != NULL)
	{
		m_pFlow->Truncate(nOffset);
	}
	m_nCount = nOffset;
}

/////////////////////////////////////////////////////////////////////////
CMarketDataFlowManager::CMarketDataFlowManager(const char *pszFlowPath)
{
	m_strFlowPath = pszFlowPath;
}

CMarketDataFlowManager::~CMarketDataFlowManager()
{
	CFlowMap::iterator itor = m_mapFlow.Begin();
	while (!itor.IsEnd())
	{
		delete (*itor);
		itor++;
	}
}

CFlow *CMarketDataFlowManager::GetFlow(DWORD nTopicID)
{
	CFlow **pFind = m_mapFlow.Find(nTopicID);
	if (pFind == NULL)
	{
		return NULL;
	}
	return *pFind;
}

bool CMarketDataFlowManager::RegisterTopic(DWORD nTopicID)
{
	if (GetFlow(nTopicID) != NULL)
	{
		//已经注册过了
		return false;
	}
	CFlow *pFlow  = new CUserFlow(nTopicID, m_strFlowPath.c_str(), true);
	m_mapFlow.Insert(nTopicID, pFlow);
	return true;
}

/////////////////////////////////////////////////////////////////////////
CFtdcUserResumeInfo::CFtdcUserResumeInfo(const char *pszPath, const char *pszUserApiType, 
										 const char *pszFileName)
{
	InitResumeInfo();
	m_strFullFileName = pszPath;
	m_strFullFileName += pszUserApiType;
	m_strFullFileName +=  pszFileName;
	if(!SerializeLoad())
	{
		InitResumeInfo();
		SerializeStore();
	}
}

CFtdcUserResumeInfo::~CFtdcUserResumeInfo()
{
}
const CDateType &CFtdcUserResumeInfo::GetTradingDay()
{
	return m_TradingDay;
}

const CDataCenterIDType &CFtdcUserResumeInfo::GetDataCenterID()
{
	return m_DataCenterID;
}

bool CFtdcUserResumeInfo::Update(const CDateType &TradingDay, CDataCenterIDType &DataCenterID)
{
	m_TradingDay = TradingDay;
	m_DataCenterID = DataCenterID;
	return SerializeStore();
}

void CFtdcUserResumeInfo::InitResumeInfo()
{
	m_nFileVersion = CFtdcUserResumeInfo::FILE_VERSION;
	m_TradingDay = "";
	m_DataCenterID = 0;
}

bool CFtdcUserResumeInfo::SerializeLoad()
{
	bool bRet = false;
	FILE *fp = mfopen(m_strFullFileName.c_str(), "rb");
	if (fp == NULL)
	{
		return bRet;
	}

	char buf[100];
	memset(buf, 0, sizeof(buf));
	if (fread(buf, 1, sizeof(buf)-1, fp) > 0)
	{
		CCSVParser parser(buf);
		int nItem = 0;
		for (; ;nItem++)
		{
			char *pToken = parser.GetNextToken();
			if (pToken == NULL)
			{
				break;
			}
			switch(nItem) {
			case 0:
				m_nFileVersion = atoi(pToken);
				break;
			case 1:
				m_TradingDay = pToken;
				break;
			case 2:
				m_DataCenterID = atoi(pToken);
				break;
			default:
				break;
			}
		}
		if (nItem == 3 && m_nFileVersion == CFtdcUserResumeInfo::FILE_VERSION)
		{
			bRet = true;
		}
	}
	fclose(fp);

	return bRet;
}

bool CFtdcUserResumeInfo::SerializeStore()
{
	bool bRet = false;
	FILE *fp = mfopen(m_strFullFileName.c_str(), "wb");
	if (fp == NULL)
	{
		return bRet;
	}
	if (fprintf(fp, "%d,%s,%d\n", m_nFileVersion, m_TradingDay.getValue(), 
		m_DataCenterID.getValue()) >0)
	{
		bRet = true;
	}
	fclose(fp);
	return bRet;
}

/////////////////////////////////////////////////////////////////////////

CFtdcUserApiImplBase::CFtdcUserApiImplBase(const char *pszFlowPath,
										   const char *pszUserApiType,
										   CSelectReactor *pReactor)
:CNsSessionFactory(pReactor, 1), 
m_ResumeInfo(pszFlowPath, pszUserApiType, "resume.con")
{
	m_LastLoginTime = 0;
	
	m_pSpi = NULL;
	m_reqPackage.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1000);
	
	m_nSessionID = 0;
	m_dwHeartbeatTimeout = 10;		//心跳超时缺省为10秒
	
	m_pDialogReqFlow = NULL;
	m_pQueryReqFlow = NULL;
	m_pPrivateFlow = NULL;
	m_pUserFlow = NULL;
	m_pPublicFlow = NULL;	
	m_strFlowPath = pszFlowPath;
	m_strUserApiType = pszUserApiType;

	m_mapSubscriber[TSS_DIALOG] = new CFtdcUserSubscriber(this, NULL, TSS_DIALOG);
	m_mapSubscriber[TSS_QUERY] = new CFtdcUserSubscriber(this, NULL, TSS_QUERY);
	m_pMarketDataFlowManager = new CMarketDataFlowManager(pszFlowPath);
	
	m_fpRequstDump = NULL;
	m_fpResponseDump = NULL;

	m_bManagedResume = false;
}
	
CFtdcUserApiImplBase::~CFtdcUserApiImplBase()
{
	CNsSessionFactory::Stop();
	CUserSubscriberMap::iterator itor = m_mapSubscriber.begin();
	for (;itor!=m_mapSubscriber.end(); itor++)
	{
		delete (*itor).second;
	}
	RemoveDialogFlow();
	RemoveQueryFlow();
	delete m_pPrivateFlow;
	m_pPrivateFlow = NULL;
	delete m_pUserFlow;
	m_pUserFlow = NULL;
	delete m_pPublicFlow;
	m_pPublicFlow = NULL;
	delete m_pMarketDataFlowManager;
	m_pMarketDataFlowManager = NULL;

	if (m_fpRequstDump != NULL)
	{
		fclose(m_fpRequstDump);
	}
	if (m_fpResponseDump != NULL)
	{
		fclose(m_fpResponseDump);
	}
}

void CFtdcUserApiImplBase::Release()
{
	m_pReactor->Stop();
	m_pReactor->Join();
	CReactor *p = m_pReactor;
	delete this;
	delete p;
}
	
void CFtdcUserApiImplBase::Init()
{
	m_pReactor->Create();
	Start();
}

int CFtdcUserApiImplBase::Join()
{
	return m_pReactor->Join();
}

const char *CFtdcUserApiImplBase::GetTradingDay()
{
	return m_ResumeInfo.GetTradingDay();
}

void CFtdcUserApiImplBase::RegisterFront(char *pszFrontAddress)
{
	RegisterConnecter(pszFrontAddress);
}

void CFtdcUserApiImplBase::RegisterNameServer(char *pszFrontAddress)
{
	CNsSessionFactory::RegisterNameServer(pszFrontAddress);
}

void CFtdcUserApiImplBase::RegisterSpi(FTDCUSERSPI *pSpi)
{
	m_pSpi = pSpi;	
}

int CFtdcUserApiImplBase::RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword)
{
	return CSslNetworkFactory::m_instance.RegisterCertificateFile(true, pszCertFileName, pszKeyFileName, 
		pszCaFileName, pszKeyFilePassword);
}

void CFtdcUserApiImplBase::CreateSubscriber(int nTopicID, CFlow *pFlow, TE_RESUME_TYPE nResumeType)
{
	m_bManagedResume = true;

	CUserSubscriberMap::iterator itor = m_mapSubscriber.find(WORD(nTopicID));
	CFtdcUserSubscriber *pSubscriber = NULL;
	if (itor == m_mapSubscriber.end())
	{
		pSubscriber = new CFtdcUserSubscriber(this, pFlow, nTopicID);
		m_mapSubscriber[(WORD)nTopicID] = pSubscriber;
	}
	else
	{
		pSubscriber = (*itor).second;
	}
	pSubscriber->SetResumeType(nResumeType);
}

void CFtdcUserApiImplBase::SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType)
{
	m_pMarketDataFlowManager->RegisterTopic(nTopicID);
	
	CreateSubscriber(nTopicID, (CUserFlow *)m_pMarketDataFlowManager->GetFlow((DWORD)nTopicID),
		nResumeType);
}

void CFtdcUserApiImplBase::SubscribePrivateTopic(TE_RESUME_TYPE nResumeType)
{
	if (m_pPrivateFlow == NULL)
	{
		m_pPrivateFlow = new CUserFlow("Private", m_strFlowPath.c_str(), true);
	}
	CreateSubscriber(TSS_PRIVATE, m_pPrivateFlow, nResumeType);
}

void CFtdcUserApiImplBase::SubscribePublicTopic(TE_RESUME_TYPE nResumeType)
{
	if (m_pPublicFlow == NULL)
	{
		m_pPublicFlow = new CUserFlow("Public",  m_strFlowPath.c_str(), true);
	}
	CreateSubscriber(TSS_PUBLIC, m_pPublicFlow, nResumeType);
}

void CFtdcUserApiImplBase::SubscribeUserTopic(TE_RESUME_TYPE nResumeType)
{
	if (m_pUserFlow == NULL)
	{
		m_pUserFlow = new CUserFlow("User", m_strFlowPath.c_str(), true);
	}
	CreateSubscriber(TSS_USER, m_pUserFlow, nResumeType);
}

void CFtdcUserApiImplBase::SetHeartbeatTimeout(unsigned int timeout)
{
	m_dwHeartbeatTimeout = timeout;
}

int CFtdcUserApiImplBase::OpenRequestLog(const char *pszReqLogFileName)
{
	if (m_fpRequstDump != NULL)
	{
		fclose(m_fpRequstDump);
		m_fpRequstDump = NULL;
	}
	m_fpRequstDump = fopen(pszReqLogFileName, "ab");
	if (m_fpRequstDump == NULL)
	{
		NET_EXCEPTION_LOG1("Can't open request log file [%s]\n", pszReqLogFileName);
		
		return -1;
	}
	return 0;
}

int CFtdcUserApiImplBase::OpenResponseLog(const char *pszRspLogFileName)
{
	if (m_fpResponseDump != NULL)
	{
		fclose(m_fpResponseDump);
		m_fpResponseDump = NULL;
	}
	m_fpResponseDump = fopen(pszRspLogFileName, "ab");
	if (m_fpResponseDump == NULL)
	{
		NET_EXCEPTION_LOG1("Can't open request log file [%s]\n", pszRspLogFileName);
		
		return -1;
	}
	return 0;
}

int CFtdcUserApiImplBase::ReqUserLogin(FTDCREQUSERLOGINFIELD *pReqUserLoginField, int nRequestID)
{
	m_mutexAction.Lock();

	// 对用户登录进行流控
	// 得到当前时间
	DWORD curClock = GetSysClock();

	// 查看是否超过登录限制
	if (curClock - m_LastLoginTime < MINLOGINTIMESPAN)
	{
		// 超过限制，等待
		SLEEP(MINLOGINTIMESPAN);
	}

	// 设置最后登录时间
	m_LastLoginTime = curClock;

	CFTDReqUserLoginField reqUserloginField;
	memcpy(&reqUserloginField, pReqUserLoginField, sizeof(CFTDReqUserLoginField));
	if (m_bManagedResume)
	{
		reqUserloginField.TradingDay = m_ResumeInfo.GetTradingDay();
		reqUserloginField.DataCenterID = m_ResumeInfo.GetDataCenterID();
	}
	
	int nMajorVersion=0, nMinorVersion=0;
	reqUserloginField.InterfaceProductInfo = GetVersion(nMajorVersion, nMinorVersion);

	char buf[100];
	sprintf(buf, "FTDC %d", (int)m_reqPackage.GetFTDCHeader()->Version);
	reqUserloginField.ProtocolInfo = buf;

	m_reqPackage.PreparePackage(FTD_TID_ReqUserLogin, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	FTDC_ADD_FIELD(&m_reqPackage, &reqUserloginField);
	
	CFTDDisseminationField disseminationField;
	CUserSubscriberMap::iterator itor = m_mapSubscriber.begin();
	for (; itor!=m_mapSubscriber.end(); itor++)
	{
		CFtdcUserSubscriber *pSubscriber = (*itor).second;
		disseminationField.SequenceSeries = pSubscriber->GetSequenceSeries();
		switch(pSubscriber->GetResumeType())
		{
		case TERT_RESTART:
			disseminationField.SequenceNo = 0;
			break;
		case TERT_RESUME:
			disseminationField.SequenceNo = pSubscriber->GetReceivedCount();
			break;
		case TERT_QUICK:
			disseminationField.SequenceNo = -1;
			break;
		default:
			break;
		}
		FTDC_ADD_FIELD(&m_reqPackage, &disseminationField);
	}
	
	int nRet = RequestDirectly();
	
	
	m_mutexAction.UnLock();
	
	return nRet;
}

int CFtdcUserApiImplBase::HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	NET_IO_LOG0("CFtdcUserApiImplBase::HandlePackage\n");
	FTDC_PACKAGE_DEBUG(pFTDCPackage);
	if (pFTDCPackage->GetTID() == FTD_TID_RspUserLogin)
	{
		CFTDRspUserLoginField rspUserLoginField;
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspUserLoginField) <= 0)
		{
			return 0;
		}
		CFTDRspInfoField rspInfoField;
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) <= 0)
		{
			return 0;
		}
		if (rspInfoField.ErrorID == 0)
		{
			m_ResumeInfo.Update(rspUserLoginField.TradingDay, 
				rspUserLoginField.DataCenterID);
			CUserSubscriberMap::iterator itor = m_mapSubscriber.begin();
			for (; itor!=m_mapSubscriber.end(); itor++)
			{
				CFtdcUserSubscriber *pSubscriber = (*itor).second;
				if (pSubscriber->GetSequenceSeries() == TSS_DIALOG ||
					pSubscriber->GetSequenceSeries() == TSS_QUERY )
				{
					//对话流和查询流的清理依靠连接中断、重连完成
					continue;
				}
				
				pSubscriber->SetCommPhaseNo(CDate::DateToLong(m_ResumeInfo.GetTradingDay()));
			}
		}
	}
	else if(pFTDCPackage->GetTID() == FTD_TID_RtnDepthMarketData) 
	{
		HandleResponse(pFTDCPackage, pFTDCPackage->GetRequestId());
		return 0;
	}
	
	HandleResponse(pFTDCPackage, pFTDCPackage->GetFTDCHeader()->SequenceSeries);
	return 0;
}
	
CSession *CFtdcUserApiImplBase::CreateSession(CChannel *pChannel, DWORD)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	CreateDialogFlow();
	pSession->Publish(m_pDialogReqFlow, TSS_DIALOG, 0);
	CreateQueryFlow();
	pSession->Publish(m_pQueryReqFlow, TSS_QUERY, 0);

	CUserSubscriberMap::iterator itor = m_mapSubscriber.begin();
	for (;itor!=m_mapSubscriber.end(); itor++)
	{
		pSession->RegisterSubscriber((*itor).second);
	}

	pSession->RegisterPackageHandler(this);
	
	if(m_dwHeartbeatTimeout != 0)
	{
		pSession->SetHeartbeatTimeout(m_dwHeartbeatTimeout);
	}
	return pSession;
}

void CFtdcUserApiImplBase::OnSessionConnected(CSession *pSession)
{
	// flow control added by zhangjie
	m_mapSubscriber[TSS_DIALOG]->CleanControl();
	m_mapSubscriber[TSS_QUERY]->CleanControl();
	m_mapSubscriber[TSS_DIALOG]->MoveTo(0);
	m_mapSubscriber[TSS_QUERY]->MoveTo(0);

	m_nSessionID = pSession->GetSessionID();
	CNsSessionFactory::OnSessionConnected(pSession);
	if (m_pSpi != NULL)
	{
		m_pSpi->OnFrontConnected();
	}
}

void CFtdcUserApiImplBase::OnSessionDisconnected(CSession *pSession, int nReason)
{
	m_mutexAction.Lock();
	CNsSessionFactory::OnSessionDisconnected(pSession, nReason);
	
	m_nSessionID = 0;
	
	if (m_pSpi != NULL)
	{
		m_pSpi->OnFrontDisconnected(nReason);
	}
	RemoveDialogFlow();
	RemoveQueryFlow();
	m_storageTopicDepthMarketData.Clear();
	m_mutexAction.UnLock();
}

void CFtdcUserApiImplBase::OnSessionWarning(CSession *pSession, int nReason, int nParam)
{
	if (nReason == MSG_XMPWARNING_RECVHEARTBEAT)
	{
		if (m_pSpi != NULL)
		{
			m_pSpi->OnHeartBeatWarning(nParam);
		}
	}
}

int CFtdcUserApiImplBase::RequestToDialogFlow()
{
	if (m_pDialogReqFlow == NULL)
	{
		return -1;
	}

	// flow control added by zhangjie
	int rtn = m_mapSubscriber[TSS_DIALOG]->AddOneToFlow();
	if (rtn)
		return rtn;

	m_reqPackage.MakePackage();
	rtn = m_pDialogReqFlow->Append(m_reqPackage.Address(), m_reqPackage.Length());
	if (rtn < 0)
	{
		return -1;
	}
	return 0;
}

void CFtdcUserApiImplBase::CreateDialogFlow()
{
	RemoveDialogFlow();
	m_pDialogReqFlow = new CFtdcUserDialogFlow(false, 10000, 10000);

	// 设置通知功能
	m_pDialogReqFlow->SetNotifyHandler((CSelectReactor*) m_pReactor);
}

void CFtdcUserApiImplBase::RemoveDialogFlow()
{
	delete m_pDialogReqFlow;
	m_pDialogReqFlow = NULL;
}

int CFtdcUserApiImplBase::RequestToQueryFlow()
{
	if (m_pQueryReqFlow == NULL)
	{
		return -1;
	}

	// flow control added by zhangjie
	int rtn = m_mapSubscriber[TSS_QUERY]->AddOneToFlow();
	if (rtn)
		return rtn;

	m_reqPackage.MakePackage();
	rtn = m_pQueryReqFlow->Append(m_reqPackage.Address(), m_reqPackage.Length());
	if (rtn < 0)
	{
		return -1;
	}
	return 0;
}

void CFtdcUserApiImplBase::CreateQueryFlow()
{
	RemoveQueryFlow();
	m_pQueryReqFlow = new CFtdcUserDialogFlow(false, 10000, 10000);
}

void CFtdcUserApiImplBase::RemoveQueryFlow()
{
	delete m_pQueryReqFlow;
	m_pQueryReqFlow = NULL;
}

int CFtdcUserApiImplBase::RequestDirectly()
{
	NET_IO_LOG1("CFtdcUserApiImplBase::RequestDirectly SessionID=%d\n", m_nSessionID);
	CFTDCSession *pSession = (CFTDCSession *)GetSession(m_nSessionID);
	if (pSession == NULL)
	{
		return -1;
	}
	
	NET_IO_LOG0("CFtdcUserApiImplBase::RequestDirectly Send\n");
	pSession->SendRequestPackage(&m_reqPackage);
	
	return 0;
}

#define GET_PART_MARKETDATA(name)											\
		case FTD_FID_##name:												\
			{																\
				CFTD##name##Field field##name;								\
				titor.Retrieve(&field##name.m_Describe, &field##name);		\
				Copy##name##Entity(pTopicDepthMarketData, &field##name);	\
			}																\
			break;


void CFtdcUserApiImplBase::OnIntlRtnDepthMarketData(CFTDCPackage *pMessage, WORD wSequenceSeries)
{
	CFTDMarketDataUpdateTimeField fieldMarketDataUpdateTime;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &fieldMarketDataUpdateTime) <= 0)
	{
		//必须找到合约代码
		return;
	}
	CTopicDepthMarketDataField *pTopicDepthMarketData = m_storageTopicDepthMarketData.GetBySequenceSeriesInstrumentID(
		wSequenceSeries, fieldMarketDataUpdateTime.InstrumentID);
	if (pTopicDepthMarketData == NULL)
	{
		CTopicDepthMarketDataField fieldTopicDepthMarketDataField;
		memset(&fieldTopicDepthMarketDataField, 0, sizeof(fieldTopicDepthMarketDataField));
		fieldTopicDepthMarketDataField.InstrumentID = fieldMarketDataUpdateTime.InstrumentID;
		fieldTopicDepthMarketDataField.SequenceSeries = wSequenceSeries;
		pTopicDepthMarketData = m_storageTopicDepthMarketData.
			AppendData(fieldTopicDepthMarketDataField);
	}
	CopyMarketDataUpdateTimeEntity(pTopicDepthMarketData, &fieldMarketDataUpdateTime);

	TFieldHeader fieldHeader;
	CFieldTypeIterator titor = pMessage->GetFieldTypeIterator();
	while (!titor.IsEnd())
	{
		titor.RetrieveHeader(fieldHeader);
		switch(fieldHeader.FieldID)
		{
		GET_PART_MARKETDATA(MarketDataBase);
		GET_PART_MARKETDATA(MarketDataStatic);
		GET_PART_MARKETDATA(MarketDataLastMatch);
		GET_PART_MARKETDATA(MarketDataBestPrice);
		GET_PART_MARKETDATA(MarketDataBid23);
		GET_PART_MARKETDATA(MarketDataAsk23);
		GET_PART_MARKETDATA(MarketDataBid45);
		GET_PART_MARKETDATA(MarketDataAsk45);
		default:
			break;
		}
		titor.Next();
	}
	
	if (m_pSpi != NULL)
	{
		m_pSpi->OnPackageStart((int)wSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
		m_pSpi->OnRtnDepthMarketData((FTDCDEPTHMARKETDATAFIELD*)pTopicDepthMarketData);
		m_pSpi->OnPackageEnd((int)wSequenceSeries, pMessage->GetFTDCHeader()->SequenceNumber);
	}
}

void CFtdcUserApiImplBase::OnIntlRtnDissemination(CFTDCPackage *pMessage, WORD wSequenceSeries)
{
	CFTDDisseminationField disseminationField;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDDisseminationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&disseminationField);
		CUserSubscriberMap::iterator i = m_mapSubscriber.find(
			disseminationField.SequenceSeries);
		if (i != m_mapSubscriber.end())
		{
			(*i).second->MoveTo(disseminationField.SequenceNo);
		}
		itor.Next();
	}		
}

void CFtdcUserApiImplBase::OnRtnDepthMarketData(CFTDDepthMarketDataField *pMarketData, WORD wSequenceSeries)
{
	CTopicDepthMarketDataField *pTopicDepthMarketData = m_storageTopicDepthMarketData.GetBySequenceSeriesInstrumentID(
		wSequenceSeries, pMarketData->InstrumentID);
	if (pTopicDepthMarketData == NULL)
	{
		CTopicDepthMarketDataField fieldTopicDepthMarketDataField;
		memset(&fieldTopicDepthMarketDataField, 0, sizeof(fieldTopicDepthMarketDataField));
		fieldTopicDepthMarketDataField.InstrumentID = pMarketData->InstrumentID;
		fieldTopicDepthMarketDataField.SequenceSeries = wSequenceSeries;
		pTopicDepthMarketData = m_storageTopicDepthMarketData.
			AppendData(fieldTopicDepthMarketDataField);
	}
	CopyDepthMarketDataEntity(pTopicDepthMarketData, pMarketData);
}
