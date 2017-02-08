// Session.cpp: implementation of the CSession class.
//
// 20080620 �Ժ�� ���Ӽ���Ƿ�д��æ�Ľӿ�IsChannelWriteBusy
// 20090604 �Ժ�� NT-0082:���������Ͽ��Ự�쳣����
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "Session.h"

static DWORD g_dwSessionIDBase = 0;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CSession::CSession(CReactor *pReactor,CChannel *pChannel,int nMaxPackageSize)
:CEventHandler(pReactor)
{
	m_bSuspendRead = false;
	m_nSessionID = ++g_dwSessionIDBase + (time(NULL)<<16);
	if(pChannel==NULL){
		RAISE_DESIGN_ERROR("CXTPControl can't use NULL channel");
	}
	m_pChannel=pChannel;
	m_pChannelProtocol=new CChannelProtocol(m_pReactor,pChannel,nMaxPackageSize);
	m_pChannelProtocol->RegisterErrorHandler(this);
	m_pSessionCallback = NULL;
}

CSession::~CSession()
{
	delete m_pChannelProtocol;
	m_pChannel->Disconnect();
	delete m_pChannel;
}


int CSession::HandleInput()
{
	return m_pChannelProtocol->HandleInput();
}

int CSession::HandleOutput()
{
	return m_pChannelProtocol->HandleOutput();
}

int CSession::HandleEvent(int nEventID, DWORD dwParam, void *pParam)
{
	switch(nEventID)
	{
	case MSG_DRSTROY_ME:
		delete this;
		return 0;
	case MSG_CHNLERR_READ:
	case MSG_CHNLERR_WRITE:
		Disconnect(nEventID);
		return 0;
	}
	return 0;
}	

void CSession::Disconnect(int nErrorCode)
{
	if (nErrorCode == 0)
	{
		//�����Ͽ������Խ�δ���͵����ݾ�������
		if(m_pChannelProtocol->Flush() < 0)
		{
			//NT-0082:�Ự�Ѿ������ˣ�ֱ�ӷ���
			return;
		}
	}
	m_pChannel->Disconnect();
	OnChannelLost(nErrorCode);
//	PostEvent(MSG_DRSTROY_ME, 0, this);
	delete this;
}

void CSession::GetIds(int *pReadId, int *pWriteId)
{
	m_pChannelProtocol->GetIds(pReadId,pWriteId);
	if (m_bSuspendRead)
	{
		*pReadId = 0;
	}
}

void CSession::OnChannelLost(int nErrorCode)
{
	if (m_pSessionCallback != NULL) 
	{
		m_pSessionCallback->OnSessionDisconnected(this, nErrorCode);
	}
}

void CSession::SuspendRead(bool bSuspend)
{
	m_bSuspendRead = bSuspend;
}

bool CSession::OpenChannelLogFile(const char *pszPath, const char *pszFileName)
{
	char szFullFilename[512];
	sprintf(szFullFilename, "%s%s.slog",pszPath, pszFileName);
	FILE *fp = fopen(szFullFilename, "ab");
	if (fp == NULL)
	{
		return false;
	}
	m_pChannel->SetLogFile(fp);
	return true;
}

void CSession::CloseChannelLogFile()
{
	FILE *fp = m_pChannel->GetLogFile();
	if (fp != NULL)
	{
		fclose(fp);
		m_pChannel->SetLogFile(NULL);
	}
}

bool CSession::IsChannelWriteBusy()
{
	return m_pChannelProtocol->IsWriteBusy();
}
