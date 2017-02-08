// FtdEngine.cpp: implementation of the CFtdEngine class.
//
// 2006.10.11	赵鸿昊	增加对SSL的检查，修改了方法OnReqUserLogin
//						OnReqUserLogin可能引起断线，调用处增加对返回值的检查
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "FtdEngine.h"
#include "FtdPackageDesc.h"

#include "monitorIndex.h"
#include "front.h"

const int SESSION_RSP_TIMER_ID = 9;
const int SESSION_RSP_INTERVAL = 50;
const int SEND_ACCOUNTDETAIL_INTERVAL = 10000;	// 10 seconds
const int SEND_TIMESYNC_INTERVAL = 3000;		// 1 second
#define MSG_SSLERR_INVALID_USERID	0xB001

#define FTD_BUSINESS_QRY						   \
	{											   \
		req.nSessionID = pSession->GetSessionID(); \
		req.pFtdPackage = pFTDCPackage->Clone();   \
		PutFtdReq(&req);						   \
	}											   \
												\
	//FTD查询请求发送到computeengine
//#define FTDREQ_TO_COMPUTE

//////////////////////////////////////////////////////////////////////

// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFtdEngine::CFtdEngine(CReactor *pReactor, const char *pszFlowPath) :
	CFrontEngine(pReactor, pszFlowPath)
{
	SetTimer(SESSION_RSP_TIMER_ID, SESSION_RSP_INTERVAL);

	m_rspPackage.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1000);

	OpenChannelLogFile(m_strFlowPathName.c_str());
}

CFtdEngine::~CFtdEngine(void)
{
}

CSession *CFtdEngine::CreateSession(CChannel *pChannel, bool bIsListener)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);

	//创建好Session后，就打开对话流
	//pSession->Publish(CreateDialogFlow(pSession->GetSessionID()), TSS_DIALOG, 0);
	//创建好Session后，就打开查询流
	pSession->Publish(GetQueryFlow(pSession->GetSessionID()), TSS_QUERY, 0);
	pSession->RegisterPackageHandler(this);

	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CFtdEngine::OnSessionDisconnected(CSession *pSession, int nReason)
{
	//m_mapDisseminationInfo.Erase(pSession->GetSessionID());
	orderList.remove(pSession->GetSessionID());
	cpuList.remove(pSession->GetSessionID());
	memList.remove(pSession->GetSessionID());
	centerList.remove(pSession->GetSessionID());

	CFrontEngine::OnSessionDisconnected(pSession, nReason);
}

void CFtdEngine::ForwardAgent(CFTDCPackage *pFTDCPackage)
{
	// relay "query from front" to rcwin
	CMutexGuard guard(m_rspProtect);
	CFTDCPackage *pPackage = pFTDCPackage->Clone();
	m_AgentResponse.push_back(pPackage);
}

void CFtdEngine::SendQueryRspByAgent(void)
{
	// relay "query from front" to rcwin
	CMutexGuard guard(m_rspProtect);
	int cnt = m_AgentResponse.size();
	int sent = 0;
	for (int i = 0; i < cnt; ++i)
	{
		CFTDCPackage *pPackage = m_AgentResponse.front();
		m_AgentResponse.erase(m_AgentResponse.begin());

		TForwardID	forwardid;
		string	strID;
		struct TFTDReq	req;
		bool bFound = false;
		bool bLastChain = (pPackage->GetChain() == FTDC_CHAIN_LAST);

		sprintf(forwardid, "%u", pPackage->GetRequestId());
		strID = forwardid;

		DWORD tid = pPackage->GetTID();

		CMap_ForwardQry::iterator pos = m_mapForwardQry.find(strID);
		if (pos != m_mapForwardQry.end())
		{
			bFound = true;
			req = pos->second;
			if (bLastChain)
			{
				m_mapForwardQry.erase(pos);
			}
		}

		if (bFound)
		{
			pPackage->SetRequestId(req.pFtdPackage->GetRequestId());
			if (bLastChain)
			{
				delete req.pFtdPackage;
			}
		}
		else
		{
			char buf[200];
			sprintf(buf, "failed to find forwardid id=%s", strID.c_str());

			//			////RIDKFRONTERRLOG1(buf);
			continue;
		}

		CFTDCSession *pSession = (CFTDCSession *)GetSession(req.nSessionID);
		if (pSession == NULL)
		{
			delete pPackage;

			char buf[200];
			sprintf(buf, "failed to find session sessionid=%d", req.nSessionID);

			////RIDKFRONTWARNLOG1(buf);
			continue;
		}

		//NET_IO_LOG0("CFtdEngine::SendQueryRspByAgent\n");
		//FTDC_PACKAGE_DEBUG(pPackage);
		SendToDialogFlow(pSession, pPackage);
		delete pPackage;

		if (++sent > 50)
		{
			break;
		}
	}
}

int CFtdEngine::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	// handle request message from user
	NET_IO_LOG0("CFtdEngine::HandlePackage\n");
	FTDC_PACKAGE_DEBUG(pFTDCPackage);

	DWORD tid = pFTDCPackage->GetTID();

	struct TFTDReq	req;
	std::string strID;

	switch (tid)
	{
		//sysmonitor指标请求:
		case FTD_TID_ReqQryTopCpuInfoTopic:
		case FTD_TID_ReqQryTopMemInfoTopic:
		case FTD_TID_ReqQryTopProcessInfoTopic:
		case FTD_TID_ReqQryFileSystemInfoTopic:
		case FTD_TID_ReqQryNetworkInfoTopic:
		case FTD_TID_ReqQrySystemResourceAttrTopic:
		case FTD_TID_ReqQryMemoryDBAttrTopic:
		case FTD_TID_ReqQryKernelAttrTopic:
		case FTD_TID_ReqQryFrontAttrTopic:
		case FTD_TID_ReqQryTinitAttrTopic:
		case FTD_TID_ReqQryCompositorAttrTopic:
		case FTD_TID_ReqQryHostEnvTopic:
		case FTD_TID_ReqQryClientLoginTopic:
		case FTD_TID_ReqQryMonitorObjectTopic:
		case FTD_TID_ReqQryObjectRationalTopic:
		case FTD_TID_ReqQryDataCenterTopic:
		case FTD_TID_ReqQrySysOrderTopic:
		case FTD_TID_ReqQrySubscriberTopic:
			FTD_BUSINESS_QRY;
			break;
	}

	return 0;
}

void CFtdEngine::SendErrorRsp(
	CFTDCSession *pSession,
	const int nErrorCode,
	const char	*pszErrorMsg)
{
	CFTDRspInfoField ftdRspInfoField;
	ftdRspInfoField.ErrorID = nErrorCode;
	ftdRspInfoField.ErrorMsg = pszErrorMsg;
	m_rspPackage.PreparePackage(FTD_TID_RspError, FTDC_CHAIN_LAST, FTD_VERSION);
	FTDC_ADD_FIELD(&m_rspPackage, &ftdRspInfoField);
	SendToDialogFlow(pSession, &m_rspPackage);
}

void CFtdEngine::PutFtdReq(struct TFTDReq *pPackage)
{
	m_UserRequest.AddIn(pPackage);
}

void CFtdEngine::GetFtdReq(struct TFTDReq *pPackage)
{
	m_UserRequest.GetOut(pPackage);
}

void CFtdEngine::PutFtdRsp(struct TFTDRsp *pRsp, bool bPutToFront)
{
	CMutexGuard guard(m_rspProtect);
	if (bPutToFront)
	{
		m_UserRsp.push_front(pRsp);
	}
	else
	{
		m_UserRsp.push_back(pRsp);
	}
}

struct TFTDRsp *CFtdEngine::GetFtdRsp(void)
{
	struct TFTDRsp	*pRsp = NULL;
	{
		CMutexGuard guard(m_rspProtect);
		if (m_UserRsp.size() > 0)
		{
			pRsp = m_UserRsp.front();
			m_UserRsp.erase(m_UserRsp.begin());
		}
	}

	return pRsp;
}

void CFtdEngine::OnTimer(int nIDEvent)
{
	struct TFTDRsp	*pRsp = NULL;
	while (pRsp = GetFtdRsp())
	{
		int sent = 0;
		int cnt = pRsp->rsplist.size();
		for (int i = 0; i < cnt; ++i, ++sent)
		{
			CFTDCPackage *pPackage = pRsp->rsplist.front();
			pRsp->rsplist.erase(pRsp->rsplist.begin());

			CFTDCSession *pSession = (CFTDCSession *)GetSession(
					pRsp->nSessionID);
			if (pSession == NULL)
			{
				char buf[200];
				sprintf(
					buf,
					"failed to get session, sessionid=%d",
					pRsp->nSessionID);

				////RIDKFRONTWARNLOG1(buf);
			}
			else if (pPackage->GetTID() == FTD_TID_RspUserLogin)
			{
				pSession->SendRequestPackage(pPackage);
			}
			else
			{
				SendToDialogFlow(pSession, pPackage);
			}

			delete pPackage;
			if (sent > 500)
			{
				break;
			}
		}

		if (pRsp->rsplist.size() > 0)
		{
			PutFtdRsp(pRsp);
		}
		else
		{
			delete pRsp;
		}
	}
}
