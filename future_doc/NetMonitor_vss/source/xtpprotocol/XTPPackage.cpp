// XTPPackage.cpp: implementation of the CXTPPackage class.
//
// 20110901 �Ժ�� NT-0150 XTP����������չͷ
// 20110914 ����   NT-0150 xtpЭ������׷�ݺͶ�������: �����˶���XTP����ͷ�����ͨ�÷�����ForcePushHeader��ForcePopHeader
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "XTPPackage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CXTPPackage::CXTPPackage()
{
	m_XTPHeader.Chain=CHAIN_LAST;
	m_extHeader.Init();
}

CXTPPackage::~CXTPPackage()
{

}

DWORD CXTPPackage::GetActiveID()
{
	if (m_XTPHeader.Type == XTP_PUBLISH)
	{
		return m_XTPHeader.SubjectID;
	}
	return 0;
}

int CXTPPackage::ValidPackage()
{
	if(Length()<XTPHLEN)
		return -1;			//��ͷ���Ȳ���

	m_XTPHeader.FromStream(m_pHead);

/*	char *pData=m_pHead+XTPHLEN;
	if(m_XTPHeader.ContentLength!=Length()-XTPHLEN)
	{
		DEBUG_LOG3("Tid=%08x,Length()-XTPHLEN=%d m_XTPHeader.ContentLength=%d\n",
			m_XTPHeader.Tid, Length(), m_XTPHeader.ContentLength);
		return -2;			//���峤�����ͷ����
	}*/


	Pop(XTPHLEN);

	Truncate(m_XTPHeader.ContentLength);

	m_extHeader.Init();

	if (m_XTPHeader.ContentLength > XTPEXTHLEN)
	{
		WORD wFieldID = FID_XTP_EXT_HEADER;
		CHANGE_ENDIAN(wFieldID);
		if (memcmp(&wFieldID, Address(), sizeof(WORD)) == 0)
		{
			m_extHeader.FromStream(Address());
			Pop(XTPEXTHLEN);
		}
	}

	return m_XTPHeader.ContentLength+XTPHLEN;
}

int CXTPPackage::MakePackage()
{
	m_XTPHeader.ContentLength = Length();
	char *pBuffer = NULL;
	if (m_extHeader.Size > 0)
	{
		m_XTPHeader.ContentLength += XTPEXTHLEN;
		
		pBuffer = Push(XTPEXTHLEN);
		if (pBuffer == NULL) 
		{
			return -1;
		}
		m_extHeader.ToStream(pBuffer);
	}
	pBuffer = Push(XTPHLEN);
	if (pBuffer == NULL) 
	{
		return -1;
	}
	m_XTPHeader.ToStream(pBuffer);
//	DEBUG_LOG0("CXTPPackage::MakePackage End\n");
	return 0;
}

void CXTPPackage::PrepareRequest(DWORD tid, BYTE chain)
{
	AllocateMax();
	Truncate(0);
	memset(&m_XTPHeader, 0, sizeof(TXTPHeader));
	m_XTPHeader.Tid = tid;
	m_XTPHeader.Chain = chain;
	m_XTPHeader.Type = XTP_REQUEST;
	m_extHeader.Init();
}


void CXTPPackage::PrepareResponse(CXTPPackage *pRequest, DWORD tid, BYTE chain)
{
	AllocateMax();
	Truncate(0);
	TXTPHeader *pReqHeader = pRequest->GetXTPHeader();
	m_XTPHeader.Type = XTP_RESPONSE;
	m_XTPHeader.Chain = chain;
	m_XTPHeader.ContentLength = 0;
	m_XTPHeader.SubjectID = 0;
	m_XTPHeader.Tid = tid;
	m_XTPHeader.CommPhaseNo = 0;
	m_XTPHeader.SequenceNo = 0;
	m_XTPHeader.RequestID = pReqHeader->RequestID;
	m_XTPHeader.SessionID = pReqHeader->SessionID;
	m_XTPHeader.FrontID = pReqHeader->FrontID;
	memcpy(&m_extHeader, pRequest->GetExtHeader(), XTPEXTHLEN);
}
	
void CXTPPackage::PreparePublish(DWORD tid, BYTE chain)
{
	AllocateMax();
	Pop(XTPEXTHLEN);
	Truncate(0);
	memset(&m_XTPHeader, 0, sizeof(TXTPHeader));
	m_XTPHeader.Tid = tid;
	m_XTPHeader.Chain = chain;
	m_XTPHeader.Type = XTP_PUBLISH;
	m_extHeader.Init();	
}

CXTPPackage *CXTPPackage::CreatePackage(int nHeaderReserve)
{
	CXTPPackage *pPackage = new CXTPPackage;
	pPackage->ConstructAllocate(XTP_PACKAGE_MAX_SIZE, nHeaderReserve);
	return pPackage;
}

void CXTPPackage::OutputHeader(CLogger *pLogger)
{
	TXTPHeader *pHeader = GetXTPHeader();
	pLogger->output(LL_DEBUG, "\tXTP PACKAGE HEADER\n");
	pLogger->output(LL_DEBUG, "\tType[0X%02X],Chain[0X%02X],ContentLength[%d],",
		pHeader->Type&0xFF, pHeader->Chain&0xFF, pHeader->ContentLength&0xFFFF);
	pLogger->output(LL_DEBUG, "SubjectID[0X%08X],Tid[0X%08X]\n",
		pHeader->SubjectID, pHeader->Tid);
	pLogger->output(LL_DEBUG, "\tCommPhaseNo[%d],SequenceNo[%d],RequestID[%d]",
		pHeader->CommPhaseNo, pHeader->SequenceNo, pHeader->RequestID);
	pLogger->output(LL_DEBUG, "SessionID[%d],FrontID[%d]\n",
		pHeader->SessionID, pHeader->FrontID);	

	TXTPExtHeader *pExtHeader = GetExtHeader();
	if (pExtHeader->Size > 0)
	{
		pLogger->output(LL_DEBUG, "\tFrontSubject[0X%04X],FrontSeqNo[%d],CompSeqNo[%d],FrontRecvSec[%d],FrontRecvUsec[%d],CompUseTime[%d],TkernelUseTime[%d]\n",
			pExtHeader->FrontSubjectID, pExtHeader->FrontSeqNo, pExtHeader->CompSeqNo, pExtHeader->FrontRecvSec, 
			pExtHeader->FrontRecvUsec, pExtHeader->CompUseTime, pExtHeader->TkernelUseTime);
	}
}

void CXTPPackage::ForcePushHeader()
{
	if (m_extHeader.IsEnable())
	{
		Push(XTPEXTHLEN);
	}

	Push(XTPHLEN);
}

void CXTPPackage::ForcePopHeader()
{
	Pop(XTPHLEN);
	
	if (m_extHeader.IsEnable())
	{
		Pop(XTPEXTHLEN);
	}
}
