// ServiceSession.cpp: implementation of the CServiceSession class.
//
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "ServiceSession.h"
#include "SCPProtocol.h"
#include "SCPPackageDesc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServiceSession::CServiceSession(CReactor *pReactor, CChannel *pChannel)
:CXTPSession(pReactor, pChannel)
{
}

CServiceSession::~CServiceSession()
{

}

void CServiceSession::SendNak(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID,
							  DWORD nSeqNo)
{
	//����Ҫ��֤�ɿ����䣬ʲôҲ������
}

void CServiceSession::SendAck(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID,
							  DWORD nSeqNo)
{
	//����Ҫ��֤�ɿ����䣬ʲôҲ������
}

void CServiceSession::SendHeartBeat(DWORD nSubjectID, DWORD nSeqNo)
{
	//����Ҫ������ʲôҲ������
}
