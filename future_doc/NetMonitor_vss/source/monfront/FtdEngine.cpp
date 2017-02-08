/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FtdEngine.cpp
///@brief	移动监控会话服务器实现
///@history
///20140617	刘博		创建该文件
/////////////////////////////////////////////////////////////////////////


#include "FtdEngine.h"
#include "FtdPackageDesc.h"

// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFtdEngine::CFtdEngine(CReactor *pReactor, const char *pszFlowPath) :
	CSessionFactory(pReactor, 500)
{
	m_rspPackage.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1000);
}

CFtdEngine::~CFtdEngine(void)
{
	CUserFlowMap::iterator user = m_mapUserFlow.Begin();
	while (!user.IsEnd())
	{
		delete (*user);
		user ++;
	}
	m_mapUserFlow.Clear();

	CParticipantFlowMap::iterator part = m_mapPrivateFlow.Begin();
	while (!part.IsEnd())
	{
		delete (*part);
		part ++;
	}
	m_mapPrivateFlow.Clear();

	m_mapSessionInfo.Clear();
	delete m_pPrivateFlow;
	delete m_pPublicFlow;
}

void CFtdEngine::SendErrorRsp(CFTDCPackage *pRequest, CFTDCSession *pSession, 
	const int nErrorCode, const char *pszErrorMsg)
{
	CFTDRspInfoField ftdRspInfoField;
	ftdRspInfoField.ErrorID = nErrorCode;
	ftdRspInfoField.ErrorMsg = pszErrorMsg;
	m_rspPackage.PrepareResponse(pRequest, FTD_TID_RspError, FTDC_CHAIN_LAST, FTD_VERSION);
	FTDC_ADD_FIELD(&m_rspPackage, &ftdRspInfoField);
	SendToDialogFlow(pSession, &m_rspPackage);	
}

int CFtdEngine::HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession)
{
	if (pFTDCPackage->GetTID() != FTD_TID_ReqUserLogin)
	{
		if (!IsSessionLogin(pSession->GetSessionID()))
		{
			SendErrorRsp(pFTDCPackage, pSession, 1, "Not Login");
			return 0;
		}
	}

	int nRet = 0;
	switch(pFTDCPackage->GetTID()) {
	case FTD_TID_ReqUserLogin:
		nRet = OnReqUserLogin(pFTDCPackage, (CFTDCSession *)pSession);
		break;
	case FTD_TID_ReqQrySysUserLoginTopic:
		printf("HandlePackage : FTD_TID_ReqQrySysUserLoginTopic\n");
		break;
	default:
		SendErrorRsp(pFTDCPackage, pSession, 1, "Unrecognized ftd tid");
		break;
	}

	return 0;
}

CSession *CFtdEngine::CreateSession(CChannel *pChannel, DWORD)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	pSession->SetCompressMethod(CRPCM_ZERO);
	return pSession;
}

void CFtdEngine::OnSessionConnected(CSession *pSession)
{
	//先调用基类的方法
	CSessionFactory::OnSessionConnected(pSession);

	printf("CFtdEngine::OnSessionConnected = %d\n", pSession->GetSessionID());

	TFrontSessionInfo sinfo;
	memset(&sinfo, 0, sizeof(TFrontSessionInfo));
	sinfo.nSessionID = pSession->GetSessionID();
	sinfo.bIsLogin = false;
	sinfo.nConnectTime = m_pReactor->Time();
	sinfo.nCommFlux = 0;
	sinfo.nMaxCommFlux = 0;
	m_mapSessionInfo.Insert(sinfo.nSessionID, sinfo);
}

void CFtdEngine::OnSessionDisconnected(CSession *pSession, int nReason)
{
	m_mapSessionInfo.Erase(pSession->GetSessionID());
	//最后调用基类的方法
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	
}

TFrontSessionInfo *CFtdEngine::GetSessionInfo(DWORD nSessionID)
{
	return m_mapSessionInfo.Find(nSessionID);
}

bool CFtdEngine::IsSessionLogin(DWORD nSessionID)
{
	TFrontSessionInfo *pFind = m_mapSessionInfo.Find(nSessionID);
	if (pFind == NULL)
	{
		return false;
	}
	return pFind->bIsLogin;
}



void CFtdEngine::SendToPublicFlow(CPackage *pPackage)
{
	pPackage->MakePackage();
	CFlow *pFlow = GetPublicFlow();
	pFlow->Append(pPackage->Address(), pPackage->Length());
}

void CFtdEngine::SendToPrivateFlow(const CParticipantIDType &participantID, int nIndex)
{
	CIndexPackageFlow *pFlow = GetPrivateFlow(participantID);
	pFlow->Append(nIndex);
}

void CFtdEngine::SendToDialogFlow(CFTDCSession *pSession, CFTDCPackage *pPackage)
{
	TFrontSessionInfo *pSessionInfo = GetSessionInfo(pSession->GetSessionID());
	if (pSessionInfo == NULL)
	{
		return;
	}
	TFTDCHeader  *pHeader = pPackage->GetFTDCHeader();
	pHeader->SequenceNumber = ++(pSessionInfo->nDialogFlowSeqNo);
	pHeader->SequenceSeries = TSS_DIALOG;
	pSession->SendRequestPackage(pPackage);
}


void CFtdEngine::SendToQueryFlow(CFTDCSession *pSession, CFTDCPackage *pPackage)
{
	TFrontSessionInfo *pSessionInfo = GetSessionInfo(pSession->GetSessionID());
	if (pSessionInfo == NULL)
	{
		return;
	}
	TFTDCHeader  *pHeader = pPackage->GetFTDCHeader();
	pHeader->SequenceNumber = ++(pSessionInfo->nQueryFlowSeqNo);
	pHeader->SequenceSeries = TSS_QUERY;
	pSession->SendRequestPackage(pPackage);
}

void CFtdEngine::SendToUserFlow(const CUserIDType &userID, int nIndex)
{
	CIndexPackageFlow *pFlow = GetUserFlow(userID);
	pFlow->Append(nIndex);
}

CFlow *CFtdEngine::GetPublicFlow()
{
	return m_pPublicFlow;
}

CIndexPackageFlow *CFtdEngine::GetPrivateFlow(const CParticipantIDType &participantID)
{
	CIndexPackageFlow *pFlow = NULL;
	CIndexPackageFlow **pFind = m_mapPrivateFlow.Find(participantID);
	if (pFind == NULL)
	{
		pFlow = new CIndexPackageFlow();
		pFlow->AttachUnderFlow(m_pPrivateFlow);
		m_mapPrivateFlow.Insert(participantID, pFlow);
	}
	else
	{
		pFlow = *pFind;
	}
	return pFlow;
}

CIndexPackageFlow *CFtdEngine::GetUserFlow(const CUserIDType &userID)
{
	CIndexPackageFlow *pFlow = NULL;
	CIndexPackageFlow **pFind = m_mapUserFlow.Find(userID);
	if (pFind == NULL)
	{
		pFlow = new CIndexPackageFlow();
		pFlow->AttachUnderFlow(m_pPrivateFlow);
		m_mapUserFlow.Insert(userID, pFlow);
	}
	else
	{
		pFlow = *pFind;
	}
	return pFlow;
}

int CFtdEngine::AppendToPrivateFlow(CPackage *pPackage)
{
	pPackage->MakePackage();
	return m_pPrivateFlow->Append(pPackage->Address(), pPackage->Length());
}

bool CFtdEngine::PublishFlow(CFTDCSession *pSession, WORD wSequenceSeries, int nSubStartId,
	int &nPubStartId, bool bCheckDataCenter)
{
	TFrontSessionInfo *pSessionInfo = GetSessionInfo(pSession->GetSessionID());
	if (pSessionInfo == NULL)
	{
		return false;
	}

	CReadOnlyFlow *pFlow = NULL;
	switch (wSequenceSeries)
	{
	case TSS_PRIVATE:
		if (pSessionInfo->UserType == UT_SingleTrader)
		{
			pFlow = GetUserFlow(pSessionInfo->UserID);
		}
		else
		{
			pFlow = GetPrivateFlow(pSessionInfo->ParticipantID);
		}
		break;
	case TSS_PUBLIC:
		pFlow = GetPublicFlow();
		break;
	case TSS_USER:
		pFlow = GetUserFlow(pSessionInfo->UserID);
		break;
	default:
		break;
	}
	if (pFlow == NULL)
	{
		return false;
	}

	nPubStartId = nSubStartId;

	//增加起始序号有效性判断,如果起始序号小于0且非-1,则清零
	if (nSubStartId == -1)
	{
		nPubStartId = pFlow->GetCount();
	}
	else if (nSubStartId < 0)
	{
		nPubStartId = 0;
	}

	pSession->Publish(pFlow, wSequenceSeries, nPubStartId);
	return true;

}

int CFtdEngine::OnReqUserLogin(CFTDCPackage *pPackage, CFTDCSession *pSession)
{
	return 0;
}