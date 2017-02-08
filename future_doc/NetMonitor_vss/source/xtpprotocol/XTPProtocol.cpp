// XTPProtocl.cpp: implementation of the CXTPProtocl class.
//
// 20110624 ����   NT-0139 �ӿ���Ӧʱ�䣺�ɶ�ʱ�����޸�Ϊ֪ͨ����
// 20120409 ����   NT-0139 �ӿ���Ӧʱ�䣺xtpЭ���޸�Ϊ΢�뼶����
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "XTPProtocol.h"
#include "XTPPackage.h"

const int XTP_TIMER_DRIVE = 0;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXTPProtocol::CXTPProtocol(CReactor *pReactor, CXTPPubHelper *pPubHelper, CXTPSubHelper *pSubHelper)
:CProtocol(pReactor, XTPHLEN, new CXTPPackage(), new CXTPPackage())
{
	m_pSubHelper = pSubHelper;
	m_pPubHelper = pPubHelper;
	m_nSubCommPhaseNo = 0;

	m_pReactor->RegisterIO(this);
	SetTimer(XTP_TIMER_DRIVE, 20);
}

CXTPProtocol::~CXTPProtocol()
{
	CSubEndPointMap::iterator sitor = m_mapSubEndPoint.Begin();
	while (!sitor.IsEnd())
	{
		delete (*sitor);
		sitor++;
	}
	m_mapSubEndPoint.Clear();

	CPubEndPointMap::iterator pitor = m_mapPubEndPoint.Begin();
	while (!pitor.IsEnd())
	{
		delete (*pitor);
		pitor++;
	}
	m_mapPubEndPoint.Clear();
}

int CXTPProtocol::Pop(CPackage *pPackage)
{
	DWORD nCurrClock = m_pReactor->GetClock();
	CXTPPackage *pXTPPackage = (CXTPPackage *)pPackage;
	CXTPSubEndPoint *pSubEndPoint = GetSubEndPoint(pXTPPackage->GetXTPHeader()->SubjectID);
	if (pSubEndPoint != NULL)
	{
		return pSubEndPoint->HandlePackage(pXTPPackage, nCurrClock);
	}

	return CProtocol::Pop(pPackage);
}

void CXTPProtocol::OnTimer(int nIDEvent)
{
	if (nIDEvent == XTP_TIMER_DRIVE)
	{
		DWORD nCurrClock = m_pReactor->GetClock();
		CSubEndPointMap::iterator sitor = m_mapSubEndPoint.Begin();
		while (!sitor.IsEnd())
		{
			(*sitor)->OnTimer(nCurrClock);
			sitor++;
		}

		CPubEndPointMap::iterator pitor = m_mapPubEndPoint.Begin();
		while (!pitor.IsEnd())
		{
			(*pitor)->OnTimer(nCurrClock);
			pitor++;
		}
	}
}

int CXTPProtocol::OnRecvErrorPackage(CPackage *pPackage)
{
	NotifyError(MSG_XTPERR_BADPACKAGE, 0, this);
	return 0;
}

void CXTPProtocol::OnHeartBeat(DWORD nSubjectID, WORD nCommPhaseNo, int nSeqNo)
{
	DWORD nCurrClock = m_pReactor->GetClock();
	CXTPSubEndPoint *pSubEndPoint = GetSubEndPoint(nSubjectID);
	if (pSubEndPoint != NULL)
	{
		pSubEndPoint->OnHeartBeat(nCommPhaseNo, nSeqNo, nCurrClock);
	}
}

void CXTPProtocol::Publish(CReadOnlyFlow *pFlow, DWORD nSubjectID, WORD nCommPhaseNo, 
						   DWORD dwSubscriberID, int nStartId)
{
//	DEBUG_LOG3("reqphase=[%d], flowphase=[%d], startid=[%d]\n",
//		nCommPhaseNo,pFlow->GetCommPhaseNo(), nStartId);
	if (nCommPhaseNo > pFlow->GetCommPhaseNo())
	{
		//�յ������Ľϴ�ͨѶ�׶εı��ģ��޷��ṩ��ֻ�ܺ��Ե�
		return;
	}
	if (nCommPhaseNo != pFlow->GetCommPhaseNo())
	{
		nStartId = 0;		//���������ͨѶ�׶��뷢����ͨѶ�׶β�ͬ�����ͷ��ʼ����
	}
	
	CXTPPubEndPoint *pPubEndPoint = GetPubEndPoint(nSubjectID);
	if (pPubEndPoint == NULL)
	{
		pPubEndPoint = new CXTPPubEndPoint(pFlow, nSubjectID, this, m_pPubHelper);
		m_mapPubEndPoint.Insert(nSubjectID, pPubEndPoint);
	}
	pPubEndPoint->OnNak(dwSubscriberID, nStartId, m_pReactor->GetClock());
}

void CXTPProtocol::UnPublish(DWORD nSubjectID)
{
	CXTPPubEndPoint *pPubEndPoint = GetPubEndPoint(nSubjectID);
	if (pPubEndPoint != NULL)
	{
		delete pPubEndPoint;
		m_mapPubEndPoint.Erase(nSubjectID);
	}
}

void CXTPProtocol::RegisterSubscriber(CSubscriber *pSubscriber, DWORD dwSubscriberID)
{
	pSubscriber->SetCommPhaseNo(m_nSubCommPhaseNo);
	DWORD nSubjectID = pSubscriber->GetSubjectID();
	CXTPSubEndPoint *pSubEndPoint = GetSubEndPoint(nSubjectID);
	if (pSubEndPoint == NULL)
	{
		pSubEndPoint = new CXTPSubEndPoint(pSubscriber, dwSubscriberID, m_pSubHelper);
		m_mapSubEndPoint.Insert(nSubjectID, pSubEndPoint);
	}
}

void CXTPProtocol::UnRegisterSubscriber(CSubscriber *pSubscriber)
{
	DWORD nSubjectID = pSubscriber->GetSubjectID();
	CXTPSubEndPoint *pSubEndPoint = GetSubEndPoint(nSubjectID);
	if (pSubEndPoint != NULL)
	{
		delete pSubEndPoint;
		m_mapSubEndPoint.Erase(nSubjectID);
	}
}

CXTPSubEndPoint *CXTPProtocol::GetSubEndPoint(DWORD nSubjectID)
{
	CXTPSubEndPoint **pFind = m_mapSubEndPoint.Find(nSubjectID);
	if (pFind != NULL)
	{
		return (*pFind);
	}
	return NULL;
}

CXTPPubEndPoint *CXTPProtocol::GetPubEndPoint(DWORD nSubjectID)
{
	CXTPPubEndPoint **pFind = m_mapPubEndPoint.Find(nSubjectID);
	if (pFind != NULL)
	{
		return (*pFind);
	}
	return NULL;
}

void CXTPProtocol::SetSubCommPhaseNo(WORD nCommPhaseNo)
{
	CSubEndPointMap::iterator sitor = m_mapSubEndPoint.Begin();
	while (!sitor.IsEnd())
	{
		(*sitor)->SetSubCommPhaseNo(nCommPhaseNo);
		sitor++;
	}
	m_nSubCommPhaseNo = nCommPhaseNo;
}

void CXTPProtocol::OnAck(DWORD dwSubscriberID, DWORD dwSubjectID, 
		int nStartId, WORD wCommPhaseNo)
{
	CXTPPubEndPoint *pPubEndPoint = GetPubEndPoint(dwSubjectID);
	if (pPubEndPoint != NULL)
	{
		pPubEndPoint->OnAck(dwSubscriberID, nStartId, m_pReactor->GetClock());
	}
}

void CXTPProtocol::GetIds(int *pReadId, int *pWriteId)
{
	*pReadId = 0;
	*pWriteId = 0;
}

int CXTPProtocol::HandleOther()
{
	// ����
	CPubEndPointMap::iterator pitor = m_mapPubEndPoint.Begin();
		
	while (!pitor.IsEnd())
	{
		(*pitor)->Publish(m_pReactor->GetMicroClock());
		pitor++;
	}

	return 0;
}
