/////////////////////////////////////////////////////////////////////////
// 20080727 赵鸿昊 NT-0048:扩展CSessionFactory::CreateSession参数，便于创建
//                 会话时区分不同的连接
// 20081114 赵鸿昊 NT-0055:增加Syslog
// 20090618 赵鸿昊 NT-0084:屏蔽SIGPIPE等信号
// 20100902 江鹏   NT-0107-解决fibproxy的tcp会话过多影响fib总线效率的问题
// 20101206 江鹏   NT-0119-修改fibproxy为多线程订阅和发布
/////////////////////////////////////////////////////////////////////////
#include "public.h"
#include "CXML.h"
#include "FibSubApiManager.h"
#include "CachedFileFlow.h"
#include "FileFlow.h"
#include "SelectReactor.h"
#include "FlowSubscriber.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FibProxyData.h"
#include "CDate.h"
#include "Storage.h"
#include "version.h"
#include "monitorIndex.h"
#include "CFilelogService.h"
#include "Mutex.h"

#define DEFINE_ERROR(errid, errmsg)					\
	const int g_errid##errid = errid;				\
	const char *g_errmsg##errid = errmsg;	

#define SET_ERROR(rspinfo, errid)					\
	(rspinfo)->ErrorID = g_errid##errid;			\
	(rspinfo)->ErrorMsg = g_errmsg##errid;

DEFINE_ERROR(0, "no error");
DEFINE_ERROR(1, "not login");
DEFINE_ERROR(2, "invalid user name or password");

char * CONFIG_FILE_NAME = "fibproxy.ini";

class CFtdTransFlow : public CCachedFlow
{
public:
	CFtdTransFlow() : CCachedFlow(false, 0, 0x20000)
	{
		m_pkgTrans.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 100);
	}
	
 	virtual int Get(int id, void *pObject, int length)
 	{
 		int nHeadReserve = FTDCHLEN+sizeof(TFieldHeader);
 		int nLen = CCachedFlow::Get(id, (char *)pObject+nHeadReserve, length-nHeadReserve);
 		if(nLen < 0 )
 		{
 			return nLen;
 		}
 		
 		m_pkgTrans.PreparePackage(FPP_TID_TRANSFER, FTDC_CHAIN_LAST, FPP_FTD_VERSION);
		m_pkgTrans.AllocField(0, nLen);
		m_pkgTrans.MakePackage();
		memcpy(pObject, m_pkgTrans.Address(), nHeadReserve);
		
		return nLen + nHeadReserve;
	}

private:	
	CFTDCPackage m_pkgTrans;
};

struct SData
{
	void *pObject;
	int length;
};

class CSubFlow : public CFileFlow
{
public:
	CSubFlow(int nFlowID, const char *pszFlowPath, bool bReuse)
	:CFileFlow(nFlowID, pszFlowPath, bReuse)
	{
		sprintf(m_szFlowName, "0X%08X", nFlowID); 
		new CIntPtrMonitorIndex(m_szFlowName, GetCountPtr(), 10);
	}
	
	virtual int Append(void *pObject, int length)
	{
		// 把数据加入队列
		SData data;

		data.length = length;
		data.pObject = new char[length];
		memcpy(data.pObject, pObject, length);

		m_Lock.Lock();
		m_Datas.push(data);
		m_Lock.UnLock();

		// 调用基类
		return CFileFlow::Append(pObject, length);
	}

	// 得到所有的缓存数据
	void GetDatas(queue<SData>* datas)
	{
		m_Lock.Lock();

		while (m_Datas.size() > 0)
		{
			datas->push(m_Datas.front());
			m_Datas.pop();
		}

		m_Lock.UnLock();
	}

private:	
	CMutex m_Lock;
	queue<SData> m_Datas;
	char m_szFlowName[11];
};

class CFlowManager
{
public:
	CFlowManager()
	{
	}

	~CFlowManager()
	{
	}

	void SetFlowPath(const char *pszFlowPath)
	{
		m_strFlowPath = pszFlowPath;
	}

	CSubscriber *RegisterTopic(DWORD dwSubjectID)
	{
		CSubscriber *pSubscriber = NULL;
		CSubscriberMap::iterator i = m_mapSubscriber.find(dwSubjectID);
		if (i == m_mapSubscriber.end())
		{
			CFlow *pSubFlow = new CSubFlow(dwSubjectID, m_strFlowPath.c_str(), true);
			m_mapSubFlow[dwSubjectID] = pSubFlow;

			pSubscriber = new CFlowSubscriber(pSubFlow, dwSubjectID);
			m_mapSubscriber[dwSubjectID] = pSubscriber;

			CFlow *pPubFlow = new CFtdTransFlow();
			m_mapPubFlow[dwSubjectID] = pPubFlow;		
		}
		else
		{
			pSubscriber = (*i).second;
		}
		return pSubscriber;
	}

	CFlow *GetSubFlow(DWORD dwSubjectID)
	{
		CFlowMap::iterator i = m_mapSubFlow.find(dwSubjectID);
		if (i == m_mapSubFlow.end())
		{
			return NULL;
		}
		return  (*i).second;
	}

	CFlow *GetPubFlow(DWORD dwSubjectID)
	{
		CFlowMap::iterator i = m_mapPubFlow.find(dwSubjectID);
		if (i == m_mapPubFlow.end())
		{
			return NULL;
		}
		return  (*i).second;
	}

	WORD GetCommPhaseNo()
	{
		CFlowMap::iterator i = m_mapSubFlow.begin();
		if (i == m_mapSubFlow.end())
		{
			return 0;
		}
		return  ((*i).second)->GetCommPhaseNo();
	}
private:
	string m_strFlowPath;
	typedef map<DWORD, CFlow *> CFlowMap;
	CFlowMap m_mapSubFlow;
	CFlowMap m_mapPubFlow;
	typedef map<DWORD, CSubscriber *> CSubscriberMap;
	CSubscriberMap m_mapSubscriber;
};

class CFibProxySession : public CFTDCSession
{
public:
	CFibProxySession(CReactor *pReactor,CChannel *pChannel)
		:CFTDCSession(pReactor, pChannel)
	{
		m_bIsLogin = false;
	}

	bool IsLogin()
	{
		return m_bIsLogin;
	}

	void SetLoginInfo(const CFPPUserIDType &UserID)
	{
		m_UserID = UserID;
		if (UserID.isNull())
		{
			m_bIsLogin = false;
		}
		else
		{
			m_bIsLogin = true;
		}
	}

private:
	bool m_bIsLogin;
	CFPPUserIDType	m_UserID;
};

struct CUser
{
	CFPPUserIDType		UserID;		/**<用户代码*/
	CFPPPasswordType	Password;	/**<密码*/
};

class CUserStorage : public CStorage<CUser>
{
public:
	DEFINE_INDEX_FUNC_1(0, const char *, UserID);
	CUserStorage()
	{
		CREATE_INDEX_1(UserID);
	}
};

const int TIMER_CHECK_COMMPHASENO_ID = 2;
const int TIMER_CHECK_COMMPHASENO_INTERVAL = 1000;
const int TIMER_MONITOR	= 3;
const int INTERVAL_MONITOR	= 1000;

class CFibPorxyServer : public CSessionFactory, public CFTDCSessionCallback
{
public:
	CFibPorxyServer(CReactor *pReactor, CFlowManager *pFlowManager)
		:CSessionFactory(pReactor, 100)
	{
		m_pFlowManager = pFlowManager;
		m_pkgResponse.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1000);
		m_wCommPhaseNo = 0;
		SetTimer(TIMER_CHECK_COMMPHASENO_ID, TIMER_CHECK_COMMPHASENO_INTERVAL);
		SetTimer(TIMER_MONITOR, INTERVAL_MONITOR);
	}

	virtual void OnTimer(int nIDEvent)
	{
		if (nIDEvent == TIMER_CHECK_COMMPHASENO_ID)
		{
			WORD wCommPhaseNo = m_pFlowManager->GetCommPhaseNo();
			if (wCommPhaseNo != m_wCommPhaseNo)
			{
				DisconnectAll(0);
				m_wCommPhaseNo = wCommPhaseNo;
			}
		}
		else if (nIDEvent == TIMER_MONITOR)
		{
			CMonitorIndex::handleOne();
		}
		CSessionFactory::OnTimer(nIDEvent);
	}

	virtual CSession *CreateSession(CChannel *pChannel, DWORD)
	{
		CFTDCSession *pSession =  new CFibProxySession(m_pReactor, pChannel);
		pSession->RegisterPackageHandler(this);
		pSession->SetCompressMethod(CRPCM_ZERO);		//设置压缩算法

//		pSession->SetHeartbeatTimeout(10);
		return pSession;
	}

	int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
	{
		CFibProxySession *pFibProxySession = (CFibProxySession *)pSession;
		NET_IO_LOG1("CFibPorxyServer::HandlePackage 0x%08x\n", pFTDCPackage->GetTID());
		if (pFTDCPackage->GetTID() != FPP_TID_ReqUserLogin)
		{
			if (!pFibProxySession->IsLogin())
			{
				CFPPRspInfoField fieldRspInfo;
				SET_ERROR(&fieldRspInfo, 1);
				SendErrorRsp(pFTDCPackage, fieldRspInfo, pFibProxySession);
				return 0;
			}
		}

		switch(pFTDCPackage->GetTID()) {
		case FPP_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pFibProxySession);
			break;
		case FPP_TID_ReqSubscribe:
			OnReqSubscribe(pFTDCPackage, pFibProxySession);
			break;
		case FPP_TID_ReqQryFlow:
			OnReqQryFlow(pFTDCPackage, pFibProxySession);
			break;
		default:
			break;
		}

		return 0;
	}
	
	void AddUser(const char *pszUserID, const char *pszPassword)
	{
		CUser data;
		data.UserID = pszUserID;
		data.Password = pszPassword;
		m_storageUser.AppendData(data);
	}
private:
	void SendErrorRsp(CFTDCPackage *pRequest, CFPPRspInfoField &fieldRspInfo, CFibProxySession *pSession)
	{
		m_pkgResponse.PrepareResponse(pRequest, FPP_TID_RspError, FTDC_CHAIN_LAST, FPP_FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgResponse, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgResponse);
	}

	void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFibProxySession *pSession)
	{
		CFPPReqUserLoginField fieldReqUserLogin;
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldReqUserLogin) <= 0)
		{
			return;
		}

		m_pkgResponse.PrepareResponse(pFTDCPackage, FPP_TID_RspUserLogin, 
			FTDC_CHAIN_LAST, FPP_FTD_VERSION);
		CFPPRspUserLoginField fieldRspUserLogin;
		fieldRspUserLogin.LoginTime = "";
		fieldRspUserLogin.TradingDay = CDate::LongToDate((DWORD)m_wCommPhaseNo);
		fieldRspUserLogin.UserID = fieldReqUserLogin.UserID;
		FTDC_ADD_FIELD(&m_pkgResponse, &fieldRspUserLogin);

		CFPPRspInfoField fieldRspInfo;
		//check 
		CUser *pUser = m_storageUser.GetByUserID(fieldReqUserLogin.UserID);
		if (pUser == NULL || pUser->Password != fieldReqUserLogin.Password)
		{
			//登录失败
			SET_ERROR(&fieldRspInfo, 2);
		}
		else
		{
			SET_ERROR(&fieldRspInfo, 0);
			pSession->SetLoginInfo(fieldReqUserLogin.UserID);
		}
		//--

		FTDC_ADD_FIELD(&m_pkgResponse, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgResponse);
	}

	void OnReqSubscribe(CFTDCPackage *pFTDCPackage, CFibProxySession *pSession)
	{
		m_pkgResponse.PrepareResponse(pFTDCPackage, FPP_TID_RspSubscribe,
			FTDC_CHAIN_LAST, FPP_FTD_VERSION);
		CFPPDisseminationField fieldDissemination;
		CNamedFieldIterator itor =  pFTDCPackage->GetNamedFieldIterator(
			&CFPPDisseminationField::m_Describe);
		for (; !itor.IsEnd(); itor.Next())
		{
			itor.Retrieve(&fieldDissemination);
			CFlow *pFlow = m_pFlowManager->GetPubFlow(fieldDissemination.SequenceSeries);
			if (pFlow == NULL)
			{
				continue;
			}
			pSession->Publish(pFlow, fieldDissemination.SequenceSeries,
				fieldDissemination.SequenceNo);

			fieldDissemination.SequenceNo = pFlow->GetCount();
			FTDC_ADD_FIELD(&m_pkgResponse, &fieldDissemination);
		}
		CFPPRspInfoField fieldRspInfo;
		SET_ERROR(&fieldRspInfo, 0);
		FTDC_ADD_FIELD(&m_pkgResponse, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgResponse);
	}

	void OnReqQryFlow(CFTDCPackage *pFTDCPackage, CFibProxySession *pSession)
	{
		m_pkgResponse.PrepareResponse(pFTDCPackage, FPP_TID_RspQryFlow,
			FTDC_CHAIN_LAST, FPP_FTD_VERSION);
		CFPPDisseminationField fieldDissemination;
		CNamedFieldIterator itor =  pFTDCPackage->GetNamedFieldIterator(
			&CFPPDisseminationField::m_Describe);
		for (; !itor.IsEnd(); itor.Next())
		{
			itor.Retrieve(&fieldDissemination);
			CFlow *pFlow = m_pFlowManager->GetPubFlow(fieldDissemination.SequenceSeries);
			if (pFlow == NULL)
			{
				fieldDissemination.SequenceNo = 0;
				continue;
			}
			else
			{
				fieldDissemination.SequenceNo = pFlow->GetCount();
			}
			FTDC_ADD_FIELD(&m_pkgResponse, &fieldDissemination);
		}
		CFPPRspInfoField fieldRspInfo;
		SET_ERROR(&fieldRspInfo, 0);
		FTDC_ADD_FIELD(&m_pkgResponse, &fieldRspInfo);
		pSession->SendRequestPackage(&m_pkgResponse);
	}

private:	
	CFlowManager *m_pFlowManager;
	CFTDCPackage m_pkgResponse;
	WORD m_wCommPhaseNo;

	CUserStorage m_storageUser;
};


class CXmlParaMap : public CParameterMap
{
public:
	CXmlParaMap(CXMLPropertyList *pXMLPropertyList)
	{
		m_pXMLPropertyList = pXMLPropertyList;
	}
	virtual char *getConfig(char *name, int *pStartId=NULL)
	{
		char *value = m_pXMLPropertyList->findValue(name);
		if (value == NULL)
		{
			return "";
		}
		return value;
	}
private:
	CXMLPropertyList *m_pXMLPropertyList;
};

class CPubReactor : public CSelectReactor  
{
public:
	void SetFlowManager(CFlowManager *pFlowManager)
	{
		m_pFlowManager = pFlowManager;
	}

	void RegisterTopic(DWORD dwSubjectID)
	{
		m_Subjects.push_back(dwSubjectID);
	}

protected:
	virtual bool HandleOtherTask()
	{
		bool ret = false;
		DWORD subject = 0;
		CSubFlow* subFlow = NULL;
		CFlow* pubFlow = NULL;
		SData data;
		queue<SData> datas;

		for (int i = 0; i < m_Subjects.size(); i ++)
		{
			// 得到主题
			subject = m_Subjects.at(i);

			// 得到订阅流
			subFlow = (CSubFlow*) m_pFlowManager->GetSubFlow(subject);

			// 得到发布流
			pubFlow = m_pFlowManager->GetPubFlow(subject);

			// 把订阅流中的数据移到发布流里来
			subFlow->GetDatas(&datas);

			while (datas.size() > 0)
			{
				data = datas.front();				
				pubFlow->Append(data.pObject, data.length);
				datas.pop();

				delete[] data.pObject;
				ret = true;
			}
		}

		return ret;
	}

private:
	CFlowManager *m_pFlowManager;
	vector<DWORD> m_Subjects;
};

int main(int argc, char *argv[])
{
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGINT, SIG_IGN);
#endif

	showVersion(argc,argv);

//	UseNetStatusLog=UseNetConnectLog=UseNetIOLog=UseNetPackageLog=UseNetCompressLog=UseNetExceptionLog = false;
	UseNetCompressLog = false;
	CFlowManager flowManager;
	CSelectReactor subReactor;
	CPubReactor pubReactor;
	pubReactor.SetFlowManager(&flowManager);
	CFibPorxyServer proxyServer(&pubReactor, &flowManager);
	CFibSubApiManager subApiManager(&subReactor, 0x7911);

	CXMLDoc xmlConfig;

	try
	{
		xmlConfig.read(CONFIG_FILE_NAME);

		CXMLNode *pRoot = xmlConfig.getRootNode();

		CXMLPropertyList *pRootPropertyList = pRoot->getPropertyList();
		CXmlParaMap cfg(pRootPropertyList);

		char *pszSyslogFileName = cfg.getConfig("SyslogPath");
		CMonitorIndex::init(CFilelogService::CreateInstance(argc, argv, pszSyslogFileName), &cfg);

		flowManager.SetFlowPath(pRoot->findProperty("flowpath"));

		proxyServer.RegisterListener(pRoot->findProperty("listenaddr"));

		CXMLNodeList *pNodeList = pRoot->getNodeList();
		CXMLNodeList::iterator pos;
		for (pos = pNodeList->begin(); pos != pNodeList->end(); ++pos) {
			CXMLNode *pNode = *pos;
			printf("%s id=%s\n", pNode->getName(), pNode->findProperty("id"));
			if (strcmp(pNode->getName(), "topic") == 0)
			{
				pubReactor.RegisterTopic(atoi(pNode->findProperty("id")));
				CSubscriber *pSubscriber = flowManager.RegisterTopic(atoi(pNode->findProperty("id")));
				CXMLNodeList *pSubNodeList = pNode->getNodeList();
				CXMLNodeList::iterator subpos = pSubNodeList->begin();
				for (; subpos!=pSubNodeList->end(); subpos++)
				{
					CXMLNode *pSubNode = *subpos;
					if (strcmp(pSubNode->getName(), "subscribe") == 0)
					{
						printf("from :%s\n", pSubNode->findProperty("address"));
						CFibSubscribeApi *pSubscribeApi = subApiManager.GetFibSubscribeApi(
							pSubNode->findProperty("address"));
						pSubscribeApi->SetSubCommPhaseNo(flowManager.GetCommPhaseNo());
						pSubscribeApi->Subscribe(pSubscriber, 0x7911);
					}
				}
			}
			else if(strcmp(pNode->getName(), "user") == 0)
			{
				proxyServer.AddUser(pNode->findProperty("userid"),
					pNode->findProperty("password"));
			}
		}

	} 
	catch (CParseError *pParseError)
	{
		printf("\nline=%d, error:%s\n", pParseError->getLineNo(), pParseError->getMsg());
		printf("Failed to read configuration file %s, quit.\n", CONFIG_FILE_NAME);
		exit(-1);
	}

	pubReactor.Create();
	subReactor.Create();

	proxyServer.Start();

	subReactor.Join();
	pubReactor.Join();

	return 0;
}
