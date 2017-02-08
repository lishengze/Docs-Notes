/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcSysUserApiImpl.cpp
///@brief 实现了客户端接口
///@history 
///20060106	赵鸿昊		创建该文件
///20061012	赵鸿昊		增加对SSL身份校验的支持
///20070216	章捷			改变流控方法.userapi不做流控，tradeapi做流控。
/////////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FtdcSysUserApiImplBase.h"
#include "CachedFileFlow.h"
#include "FileFlow.h"
#include "CDate.h"
#include "UFCopy.h"
//#include "SslNetworkFactory.h"

#ifndef SYSINTERFACE_PRODUCT_INFO
#define SYSINTERFACE_PRODUCT_INFO "SHFE SysUserAPI v1.0"
#endif

/**CFtdcUserDialogFlow是线程安全的CCachedFlow
*对于会话流，应用程序线程和API线程会同时访问，必须加以保护
*/
class CFtdcUserDialogFlow : public CCachedFlow
{
public:
	CFtdcUserDialogFlow(bool bSyncFlag, int nMaxObjects, int nDataBlockSize)
		:CCachedFlow(bSyncFlag, nMaxObjects, nDataBlockSize)
	{
		m_nCount = CCachedFlow::GetCount();
	}
	
	/**获取流中已经有的包的个数
	*@return 包的个数
	*/
	virtual int GetCount(void)
	{
		return m_nCount;
	}
	
	/**将流尾部的包截掉
	*@param nCount 保留的包的个数
	*@return true 操作成功； false 操作失败
	*/
	virtual bool Truncate(int nCount)
	{
		m_lock.Lock();
		bool bRet = CCachedFlow::Truncate(nCount);
		m_nCount = CCachedFlow::GetCount();
		m_lock.UnLock();
		return bRet;
	}

	/**向流中增加一个对象
	*@param	pObject 要增加的对象
	*@param length 增加数据的长度
	*@return 增加后流中的包总个数，小于或等于0表示增加失败
	*/
	virtual int Append(void *pObject, int length)
	{
		m_lock.Lock();
		int nRet = CCachedFlow::Append(pObject, length);
		m_nCount = CCachedFlow::GetCount();
		m_lock.UnLock();
		return nRet;
	}

	/**获取指定编号的对象
	*@param	id	对象序号
	*@param pObject 获取对象的缓冲区
	*@param length 缓冲区大小
	*@return 取出对象的长度
	*/
 	virtual int Get(int id, void *pObject, int length)
	{
		m_lock.Lock();
		int nRet = CCachedFlow::Get(id, pObject, length);
		m_nCount = CCachedFlow::GetCount();
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
		m_nCommPhaseNo = 0;
		m_fpContentFile=NULL;
		OpenFile(pszFlowName, pszPath, bReuse);
	}
	CUserFlow::CUserFlow(int nFlowID, const char *pszPath, bool bReuse)
	{
		char szFlowName[20];
		sprintf(szFlowName, "%08x", nFlowID);
		new (this) CUserFlow(szFlowName, pszPath, bReuse);
	}

	virtual ~CUserFlow()
	{
		CloseFile();
	}

	/**获取流中已经有的包的个数
	*@return 包的个数
	*/
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

	/**获取流的通讯阶段序号
	*@return 流的通讯阶段序号
	*/
	virtual WORD GetCommPhaseNo()
	{
		return m_nCommPhaseNo;
	}

	/**设置流的通讯阶段序号
	*@param nCommPhaseNo 要设置的流的通讯阶段序号
	*/
	virtual void SetCommPhaseNo(WORD nCommPhaseNo)
	{
		if (nCommPhaseNo != m_nCommPhaseNo)
		{
			m_nCommPhaseNo = nCommPhaseNo;
			m_nCount= 0;
			WriteFile();
		}
	}

	/**将流尾部的包截掉
	*@param nCount 保留的包的个数
	*/
	virtual bool Truncate(int nCount)
	{
//		if (m_nCount <= nCount)
//		{
//			return true;
//		}
		m_nCount= nCount;
		return WriteFile();
	}
	
	/**向流中增加一个对象
	*@param	pObject 要增加的对象
	*@param length 增加数据的长度
	*@return 对象在流中的序号，小于0表示增加失败
	*/
	virtual int Append(void *pObject, int length)
	{
		m_nCount++;
		WriteFile();
		return m_nCount-1;		
	}

	/**获取指定编号的对象
	*@param	id	对象序号
	*@param pObject 获取对象的缓冲区
	*@param length 缓冲区大小
	*@return 取出对象的长度
	*/
 	virtual int Get(int id, void *pObject, int length)
	{
		RAISE_RUNTIME_ERROR("Can't use this function - CUserFlow::Get\n");
		return 0;
	}

protected:	
	/**写入流存贮文件
	* @return true 写文件成功  false 写文件失败
	*/
	bool WriteFile()
	{
		fseek(m_fpContentFile, 0, SEEK_SET);
		WORD nCommPhaseNo = m_nCommPhaseNo;
		CHANGE_ENDIAN(nCommPhaseNo);
		if(fwrite(&nCommPhaseNo, sizeof(nCommPhaseNo), 1, m_fpContentFile) != 1)
		{
			return false;
		}
		DWORD nCount = m_nCount;
		CHANGE_ENDIAN(nCount);
		if(fwrite(&nCount, sizeof(nCount), 1, m_fpContentFile) != 1)
		{
			return false;
		}
		fflush(m_fpContentFile);
		return true;
	}
	
	/**重新打开流文件
	*@param	szIdFilename	存储地址的文件名
	*@param	szContentFilename	存储内容的文件名
	*@param	bReuse	是否重用此文件
	*@异常	CRuntimeError	如果文件名为空或文件读写错误，则抛出此异常
	*/
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
		if (bReuse &&
			fread(&m_nCommPhaseNo, sizeof(m_nCommPhaseNo), 1, m_fpContentFile)==1 &&
			fread(&m_nCount, sizeof(m_nCount), 1, m_fpContentFile) == 1)
		{
			CHANGE_ENDIAN(m_nCommPhaseNo);
			CHANGE_ENDIAN(m_nCount);
		}
		else
		{
			if (!WriteFile())
			{
				CloseFile();
				RAISE_RUNTIME_ERROR("can not init CFlow file");
			}
		}
	}

	/**关闭存贮包的文件
	*/
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
	WORD m_nCommPhaseNo;			/**< 通讯阶段编号*/
};

/////////////////////////////////////////////////////////////////////////

CFtdcUserSubscriber::CFtdcUserSubscriber(CFtdcSysUserApiImplBase *pUserApiImplBase,
										 CFlow *pFlow, WORD wSequenceSeries)
{
	m_pUserApiImplBase = pUserApiImplBase;
	m_pFlow = pFlow;
	m_wSequenceSeries = wSequenceSeries;
	m_nResumeType = TERT_RESUME;

	if (wSequenceSeries == TSS_QUERY) {

		m_nMaxUnfinished = 0x7fffffff;
		m_nMaxPerSecond  = 0x7fffffff;

		m_nTimeoutForQueryFlow = 30;
		CleanControl();
	}
	
	if (wSequenceSeries == TSS_DIALOG) {

		m_nMaxUnfinished = 0x7fffffff;
		m_nMaxPerSecond  = 0x7fffffff;

		CleanControl();
	}
}

CFtdcUserSubscriber::~CFtdcUserSubscriber()
{
}

void CFtdcUserSubscriber::CleanControl(void)
{
	m_nCntPerSecond = 0;
	m_lastTime = 0;
	m_nUnfinished.clear();
}

int CFtdcUserSubscriber::AddOneToFlow(void)
{
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

WORD CFtdcUserSubscriber::GetSequenceSeries()
{
	return m_wSequenceSeries;
}

DWORD CFtdcUserSubscriber::GetReceivedCount()
{
	if (m_pFlow == NULL)
	{
		return 0;
	}
	return m_pFlow->GetCount();
}

void CFtdcUserSubscriber::SetCommPhaseNo(WORD wCommPhaseNo)
{
	if (m_pFlow != NULL)
	{
		m_pFlow->SetCommPhaseNo(wCommPhaseNo);
	}
}

void CFtdcUserSubscriber::HandleMessage(CFTDCPackage *pMessage)
{
//	NET_IO_LOG0("CFtdcUserSubscriber::HandleMessage\n");
//	FTDC_PACKAGE_DEBUG(pMessage);

	if (m_pFlow->GetCount()+1 != pMessage->GetFTDCHeader()->SequenceNumber)
	{
		NET_EXCEPTION_LOG2("CFtdcUserSubscriber::HandleMessage,receive[%d],want[%d]\n",
			m_pFlow->GetCount(), pMessage->GetFTDCHeader()->SequenceNumber);
		return;
	}

	//提交给上层应用程序
	if (m_wSequenceSeries == TSS_QUERY || m_wSequenceSeries == TSS_DIALOG) {
		if (pMessage->GetChain() == FTDC_CHAIN_LAST) {
			if (m_nUnfinished.size() > 0)
				m_nUnfinished.pop_front();
		}
	}

	m_pUserApiImplBase->HandleResponse(pMessage, m_wSequenceSeries);

	if (m_pFlow != NULL)
	{
		//将报文加入流中
		pMessage->Push(FTDCHLEN);
		m_pFlow->Append(pMessage->Address(), pMessage->Length());
		pMessage->Pop(FTDCHLEN);
	}	
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
	m_pFlow->Truncate(nOffset);
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

CFtdcSysUserApiImplBase::CFtdcSysUserApiImplBase(const char *pszFlowPath, CSelectReactor *pReactor)
:CSessionFactory(pReactor, 1)
{
	m_pReactor = pReactor;
	m_pSpi = NULL;
	m_reqPackage.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1000);
	
	m_nSessionID = 0;
	
	m_pDialogReqFlow = NULL;
	m_pDialogRspFlow = new CUserFlow("DialogRsp", pszFlowPath, false);
	m_pQueryReqFlow = NULL;
	m_pQueryRspFlow = new CUserFlow("QueryRsp", pszFlowPath, false);
	m_pPrivateFlow = NULL;
	m_pPublicFlow = NULL;
	m_pTradingDayFlow = new CUserFlow("TradingDay", pszFlowPath, true);
	
	m_strFlowPath = pszFlowPath;

	m_mapSubscriber[TSS_DIALOG] = new CFtdcUserSubscriber(this, m_pDialogRspFlow, TSS_DIALOG);
	m_mapSubscriber[TSS_QUERY] = new CFtdcUserSubscriber(this, m_pQueryRspFlow, TSS_QUERY);

	m_pMarketDataFlowManager = new CMarketDataFlowManager(pszFlowPath);
	
	m_TradingDay = CDate::LongToDate((long)m_pTradingDayFlow->GetCommPhaseNo());
}
	
CFtdcSysUserApiImplBase::~CFtdcSysUserApiImplBase()
{
	CSessionFactory::Stop();
	CUserSubscriberMap::iterator itor = m_mapSubscriber.begin();
	for (;itor!=m_mapSubscriber.end(); itor++)
	{
		delete (*itor).second;
	}
	RemoveDialogFlow();
	RemoveQueryFlow();
	delete m_pDialogRspFlow;
	m_pDialogRspFlow = NULL;
	delete m_pQueryRspFlow;
	m_pQueryRspFlow = NULL;
	delete m_pPrivateFlow;
	m_pPrivateFlow = NULL;
	delete m_pPublicFlow;
	m_pPublicFlow = NULL;
	delete m_pTradingDayFlow;
	m_pTradingDayFlow = NULL;
	delete m_pMarketDataFlowManager;
	m_pMarketDataFlowManager = NULL;
}

void CFtdcSysUserApiImplBase::Release()
{
	m_pReactor->Stop();
	m_pReactor->Join();
	CSelectReactor *p = m_pReactor;
	delete this;
	delete p;
}
	
void CFtdcSysUserApiImplBase::Init()
{
	m_pReactor->Create();
	Start();
}

int CFtdcSysUserApiImplBase::Join()
{
	return m_pReactor->Join();
}

const char *CFtdcSysUserApiImplBase::GetTradingDay()
{
	return m_TradingDay;
}

void CFtdcSysUserApiImplBase::RegisterFront(char *pszFrontAddress)
{
	RegisterConnecter(pszFrontAddress);
}

void CFtdcSysUserApiImplBase::RegisterSpi(CShfeFtdcSysUserSpi *pSpi)
{
	m_pSpi = pSpi;	
}

/*int CFtdcSysUserApiImplBase::RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, 
		const char *pszCaFileName, const char *pszKeyFilePassword)
{
	return CSslNetworkFactory::m_instance.RegisterCertificateFile(true, pszCertFileName, pszKeyFileName, 
		pszCaFileName, pszKeyFilePassword);
}
*/
void CFtdcSysUserApiImplBase::CreateSubscriber(int nTopicID, CFlow *pFlow, TE_RESUME_TYPE nResumeType)
{
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

void CFtdcSysUserApiImplBase::SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType)
{
	m_pMarketDataFlowManager->RegisterTopic(nTopicID);
	
	CreateSubscriber(nTopicID, (CUserFlow *)m_pMarketDataFlowManager->GetFlow((DWORD)nTopicID),
		nResumeType);
}

void CFtdcSysUserApiImplBase::SubscribePartAccount(void)
{
}

void CFtdcSysUserApiImplBase::SubscribePrivateTopic(TE_RESUME_TYPE nResumeType)
{
	if (m_pPrivateFlow == NULL)
	{
		m_pPrivateFlow = new CUserFlow("Private", m_strFlowPath.c_str(), true);
	}
	CreateSubscriber(TSS_PRIVATE, m_pPrivateFlow, nResumeType);
}

void CFtdcSysUserApiImplBase::SubscribePublicTopic(TE_RESUME_TYPE nResumeType)
{
	if (m_pPublicFlow == NULL)
	{
		m_pPublicFlow = new CUserFlow("Public",  m_strFlowPath.c_str(), true);
	}
	CreateSubscriber(TSS_PUBLIC, m_pPublicFlow, nResumeType);
}

int CFtdcSysUserApiImplBase::ReqUserLogin(CShfeFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	m_mutexAction.Lock();
	

	CFTDReqUserLoginField reqUserloginField;
	memcpy(&reqUserloginField, pReqUserLoginField, sizeof(CFTDReqUserLoginField));
	reqUserloginField.TradingDay = m_TradingDay;
	reqUserloginField.InterfaceProductInfo = SYSINTERFACE_PRODUCT_INFO;

	//char buf[100];
	//sprintf(buf, "FTDC %d", (int)m_reqPackage.GetFTDCHeader()->Version);
	//reqUserloginField.ProtocolInfo = buf;

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

int CFtdcSysUserApiImplBase::HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
//	NET_IO_LOG0("CFtdcSysUserApiImplBase::HandlePackage\n");
//	FTDC_PACKAGE_DEBUG(pFTDCPackage);
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
			if (m_TradingDay != rspUserLoginField.TradingDay)
			{
				m_TradingDay = rspUserLoginField.TradingDay;
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
					
					pSubscriber->SetCommPhaseNo(CDate::DateToLong(m_TradingDay));
				}
				m_pTradingDayFlow->SetCommPhaseNo(CDate::DateToLong(m_TradingDay));
			}		
		}
	}
	else if(pFTDCPackage->GetTID() == FTD_TID_RtnDepthMarketData) 
	{
		HandleResponse(pFTDCPackage, pFTDCPackage->GetRequestId());
		return 0;
	}
	
	HandleResponse(pFTDCPackage, 0);
	return 0;
}
	
CSession *CFtdcSysUserApiImplBase::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	CreateDialogFlow();
	m_pDialogRspFlow->Truncate(0);
	pSession->Publish(m_pDialogReqFlow, TSS_DIALOG, 0);
	CreateQueryFlow();
	m_pQueryRspFlow->Truncate(0);
	pSession->Publish(m_pQueryReqFlow, TSS_QUERY, 0);

	CUserSubscriberMap::iterator itor = m_mapSubscriber.begin();
	for (;itor!=m_mapSubscriber.end(); itor++)
	{
		pSession->RegisterSubscriber((*itor).second);
	}

	pSession->RegisterPackageHandler(this);
	return pSession;
}

void CFtdcSysUserApiImplBase::OnSessionConnected(CSession *pSession)
{
	// flow control added by zhangjie
	m_mapSubscriber[TSS_DIALOG]->CleanControl();
	m_mapSubscriber[TSS_QUERY]->CleanControl();

	m_nSessionID = pSession->GetSessionID();
	CSessionFactory::OnSessionConnected(pSession);
	if (m_pSpi != NULL)
	{
		m_pSpi->OnFrontConnected();
	}
}

void CFtdcSysUserApiImplBase::OnSessionDisconnected(CSession *pSession, int nReason)
{
	m_mutexAction.Lock();
	printf("CFtdcSysUserApiImplBase::OnSessionDisconnected[%p][%5d][%5d]\n",
		pSession, pSession->GetSessionID(), nReason);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);
	
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

void CFtdcSysUserApiImplBase::OnSessionWarning(CSession *pSession, int nReason, int nParam)
{
	if (nReason == MSG_XMPERR_BADPACKAGE)
	{
		if (m_pSpi != NULL)
		{
			m_pSpi->OnHeartBeatWarning(nParam);
		}
	}
}

int CFtdcSysUserApiImplBase::RequestToDialogFlow()
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
	m_pDialogReqFlow->Append(m_reqPackage.Address(), m_reqPackage.Length());
	
	return 0;
}

void CFtdcSysUserApiImplBase::CreateDialogFlow()
{
	RemoveDialogFlow();
	m_pDialogReqFlow = new CFtdcUserDialogFlow(false, 0, 10000);
}

void CFtdcSysUserApiImplBase::RemoveDialogFlow()
{
	delete m_pDialogReqFlow;
	m_pDialogReqFlow = NULL;
}

int CFtdcSysUserApiImplBase::RequestToQueryFlow()
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
	m_pQueryReqFlow->Append(m_reqPackage.Address(), m_reqPackage.Length());
	
	return 0;
}

void CFtdcSysUserApiImplBase::CreateQueryFlow()
{
	RemoveQueryFlow();
	m_pQueryReqFlow = new CFtdcUserDialogFlow(false, 0, 10000);
}

void CFtdcSysUserApiImplBase::RemoveQueryFlow()
{
	delete m_pQueryReqFlow;
	m_pQueryReqFlow = NULL;
}

int CFtdcSysUserApiImplBase::RequestDirectly()
{
	NET_IO_LOG1("CFtdcSysUserApiImplBase::RequestDirectly SessionID=%d\n", m_nSessionID);
	CFTDCSession *pSession = (CFTDCSession *)GetSession(m_nSessionID);
	if (pSession == NULL)
	{
		return -1;
	}
	
	NET_IO_LOG0("CFtdcSysUserApiImplBase::RequestDirectly Send\n");
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


void CFtdcSysUserApiImplBase::OnIntlRtnDepthMarketData(CFTDCPackage *pMessage, WORD wSequenceSeries)
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
//		m_pSpi->OnRtnDepthMarketData((CShfeFtdcDepthMarketDataField*)pTopicDepthMarketData);
	}
}

void CFtdcSysUserApiImplBase::OnIntlRtnDissemination(CFTDCPackage *pMessage, WORD wSequenceSeries)
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

void CFtdcSysUserApiImplBase::OnRtnDepthMarketData(CFTDDepthMarketDataField *pMarketData, WORD wSequenceSeries)
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
