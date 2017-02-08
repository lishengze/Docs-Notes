// FTDCSession.cpp: implementation of the CFTDCSession class.
//
// 20070128 �Ժ�� ���⣺�ڽ��շ������ٶȺ���ʱ�����ĳЩ�������ݺܶ࣬����
//                 GetIds��û�����أ���Ѹ�ٽ�channel����������������������
//                 ���ͺ��������ڴ����ĺܴ�
//                 �ָ�Ϊ����GetIds�У����channel�Ļ�����Ϊ�գ��Ž����е�
//                 ���ķ���channel
// 20100125 �Ժ�� NT-0096:����FTDCSession���ڴ�й©����
// 20110224 ����   NT-0125:����mdkernel���û�logout֮�����յ����������
// 20120425 ����   NT-0139 �ӿ���Ӧʱ�䣺��ftdcЭ������֪ͨ����
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
	// �������û���������������ݲ�֪ͨ
	if (!IsChannelWriteBusy())
	{
		// �Ѱ��ŵ�������
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
		//����������Ͽ������Է�������δ����İ�
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
