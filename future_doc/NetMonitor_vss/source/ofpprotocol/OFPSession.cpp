// OFPSession.cpp: implementation of the COFPSession class.
//
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "OFPSession.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COFPSession::COFPSession(CReactor *pReactor, CChannel *pChannel, char chVersion)
:CSession(pReactor, pChannel, OFP_PACKAGE_MAX_SIZE+OFPHLEN+256)
{
	m_pOFPProtocol = new COFPProtocol(m_pReactor, chVersion);
	m_pOFPProtocol->AttachLower(m_pChannelProtocol, 0);
	m_pOFPProtocol->RegisterErrorHandler(this);
	m_pOFPProtocol->RegisterUpperHandler(this);
	m_pPackageHandler = NULL;
}

COFPSession::~COFPSession()
{
	delete m_pOFPProtocol;
}

int COFPSession::HandleEvent(int nEventID, DWORD dwParam, void *pParam)
{
	switch(nEventID)
	{
	case MSG_OFPERR_RECVHEARTBEAT:
	case MSG_OFPERR_SENDHEARTBEAT:
	case MSG_OFPERR_BADPACKAGE:
		Disconnect(nEventID);
		return 0;
	}

	return CSession::HandleEvent(nEventID, dwParam, pParam);
}

void COFPSession::GetIds(int *pReadId, int *pWriteId)
{
	m_pOFPProtocol->PublishSend();

	CSession::GetIds(pReadId, pWriteId);
}

void COFPSession::RegisterPackageHandler(COFPSessionCallback *pPackageHandler)
{
	m_pPackageHandler = pPackageHandler;
}

void COFPSession::SendRequestPackage(COFPPackage *pPackage)
{
	m_pOFPProtocol->Send(pPackage);
}

int COFPSession::HandlePackage(CPackage *pPackage,CProtocol *pProtocol)
{
	if (pProtocol == m_pOFPProtocol)
	{
		COFPPackage *pOFPPacakge = (COFPPackage *)pPackage;
		if (m_pPackageHandler == NULL)
		{
			return 0;
		}
		return m_pPackageHandler->HandlePackage(pOFPPacakge, this);
	}
	return 0;
}

void COFPSession::Publish(CReadOnlyFlow *pFlow, WORD nSequenceSeries, int nStartId)
{
	m_pOFPProtocol->Publish(pFlow, nSequenceSeries, nStartId);
}

void COFPSession::UnPublish(WORD nSequenceSeries)
{
	m_pOFPProtocol->UnPublish(nSequenceSeries);
}

void COFPSession::Disconnect(int nErrorCode)
{
	if (nErrorCode == 0)
	{
		//如果是主动断开，则尝试发送流中未发完的包
		m_pOFPProtocol->PublishSend();
	}
	CSession::Disconnect(nErrorCode);
}