// FTDCSession.cpp: implementation of the CFTDCSession class.
//
// 20070128 赵鸿昊 问题：在接收方接收速度很慢时，如果某些流中数据很多，由于
//                 GetIds中没有流控，会迅速将channel缓冲区填满，导致其它流
//                 发送很慢，且内存消耗很大。
//                 现改为：在GetIds中，如果channel的缓冲区为空，才将流中的
//                 报文发向channel
// 20100125 赵鸿昊 NT-0096:修正FTDCSession的内存泄漏问题
// 20110224 江鹏   NT-0125:修正mdkernel在用户logout之后还能收到行情的问题
// 20120425 江鹏   NT-0139 加快响应时间：给ftdc协议增加通知功能
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FTDCPackage.h"
#include "FTDCSession.h"

const DWORD XMPTypeFTDC = 0x01;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFTDCSession::CFTDCSession(CReactor *pReactor,CChannel *pChannel)
:CXMPSession(pReactor, pChannel)
{
	m_pCRPProtocol = new CCompressProtocol(m_pReactor);
	m_pCRPProtocol->AttachLower(m_pXMPProtocol, XMPTypeCompressed);
	m_pFTDCProtocol = new CFTDCProtocol(m_pReactor);
	m_pFTDCProtocol->AttachLower(m_pCRPProtocol, XMPTypeFTDC);

	m_pFTDCProtocol->RegisterErrorHandler(this);
	m_pFTDCProtocol->RegisterUpperHandler(this);
	
	m_pPackageHandler = NULL;
	
}

CFTDCSession::~CFTDCSession()
{
	delete m_pFTDCProtocol;
	delete m_pCRPProtocol;
}

int CFTDCSession::HandleEvent(int nEventID, DWORD dwParam, void *pParam)
{
	switch(nEventID)
	{
	case MSG_XMPERR_RECVHEARTBEAT:
	case MSG_XMPERR_SENDHEARTBEAT:
	case MSG_XMPERR_BADPACKAGE:
	case MSG_FTDCERR_BADPACKAGE:
		Disconnect(nEventID);
		return 0;
	case MSG_XMPWARNING_RECVHEARTBEAT:
		if (m_pSessionCallback != NULL)
		{
			m_pSessionCallback->OnSessionWarning(this, nEventID, (int)dwParam);
		}
		return 0;
	}

	return CSession::HandleEvent(nEventID, dwParam, pParam);
}	

int CFTDCSession::HandleOther()
{
	// 如果队列没有数据则增加数据并通知
	if (!IsChannelWriteBusy())
	{
		// 把包放到队列中
		m_pFTDCProtocol->PublishSend();
	}

	return 0;
}

void CFTDCSession::RegisterPackageHandler(CFTDCSessionCallback *pPackageHandler)
{
	m_pPackageHandler = pPackageHandler;
}

int CFTDCSession::HandlePackage(CPackage *pPackage,CProtocol *pProtocol)
{
	if (pProtocol == m_pFTDCProtocol)
	{
		CFTDCPackage *pFTDCPacakge = (CFTDCPackage *)pPackage;
		if (m_pPackageHandler == NULL)
		{
			return 0;
		}
		return m_pPackageHandler->HandlePackage(pFTDCPacakge, this);
	}
	return 0;
}


void CFTDCSession::Publish(CReadOnlyFlow *pFlow, WORD wSequenceSeries, int nStartId)
{
	m_pFTDCProtocol->Publish(pFlow, wSequenceSeries, nStartId);
}

void CFTDCSession::UnPublish(WORD wSequenceSeries)
{
	m_pFTDCProtocol->UnPublish(wSequenceSeries);
}

void CFTDCSession::QuerySubscribeTopic(vector<WORD>* topics)
{
	m_pFTDCProtocol->QuerySubscribeTopic(topics);
}

CFTDCPackage *CFTDCSession::CreatePackage()
{
	CFTDCPackage *pPackage = new CFTDCPackage;
	pPackage->ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, m_pFTDCProtocol->GetHdrReserveLen());
	return pPackage;
}

void CFTDCSession::SendRequestPackage(CFTDCPackage *pPackage)
{
	m_pFTDCProtocol->Send(pPackage);
}

void CFTDCSession::RegisterSubscriber(CFTDCSubscriber *pSubscriber)
{
	m_pFTDCProtocol->RegisterSubscriber(pSubscriber);
}

void CFTDCSession::UnRegisterSubscriber(CFTDCSubscriber *pSubscriber)
{
	m_pFTDCProtocol->UnRegisterSubscriber(pSubscriber);
}

void CFTDCSession::SetCommPhaseNo(WORD wCommPhaseNo)
{
	m_pFTDCProtocol->SetCommPhaseNo(wCommPhaseNo);
}

void CFTDCSession::Disconnect(int nErrorCode)
{
	if (nErrorCode == 0)
	{
		//如果是主动断开，则尝试发送流中未发完的包
		m_pFTDCProtocol->PublishSend();
	}

	m_pFTDCProtocol->Clear();
	
	CXMPSession::Disconnect(nErrorCode);
}

void CFTDCSession::SetCompressMethod(BYTE chCompressMethod)
{
	m_pCRPProtocol->SetCompressMethod(XMPTypeFTDC, chCompressMethod);
}

void CFTDCSession::SetVersion(BYTE version)
{
	m_version=version;
}
	
BYTE CFTDCSession::GetVersion(void)
{
	return m_version;
}
