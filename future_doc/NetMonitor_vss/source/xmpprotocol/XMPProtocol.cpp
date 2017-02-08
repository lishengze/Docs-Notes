// XMPProtocol.cpp: implementation of the CXMPProtocol class.
//
// 20070801 �Ժ�� ���Ӷ�������ʱ����
// 20080227 �Ժ�� ����BUG���������泬ʱ��m_LastWarnTimeӦ��֪ͨ����£�
//                 ����֪ͨ��ʱʱ�������Ϊ0
// 20090427 �Ժ�� NT-0071������SetHeartbeatMode����
//                 �������ģʽΪSlave������Է���������ʱʱ��һ��
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "XMPProtocol.h"

//////////////////////////////////////////////////////////////////////

#define WRITE_TIMEOUT_DEFAULT		60
#define READ_TIMEOUT_DEFAULT		120
#define WARNING_TIMEOUT_DEFAULT		80

#define XMP_HEARTBEAT_TIMER_ID		1

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXMPProtocol::CXMPProtocol(CReactor *pReactor)
:CProtocol(pReactor, XMPHLEN+XMPEXTHLEN+XMP_EXTHEAD_MAX_SIZE,
		   new CXMPPackage(), new CXMPPackage())
{
	m_LastWriteTime = pReactor->Time();
	m_LastReadTime = pReactor->Time();
	m_LastWarnTime = m_LastReadTime;

	m_bHeartEnable = false;

	m_dwHeartbeatMode = 0;
	
	m_dwWriteTimeout = WRITE_TIMEOUT_DEFAULT;
	m_dwReadTimeout = READ_TIMEOUT_DEFAULT;
	m_dwWarningTimeout = WARNING_TIMEOUT_DEFAULT;

	EnableHeartbeat(true);
}

CXMPProtocol::~CXMPProtocol()
{
}

int CXMPProtocol::Pop(CPackage *pPackage)
{
	//���������յ����ݰ���ʱ��
	m_LastReadTime = m_pReactor->Time();
	m_LastWarnTime = m_LastReadTime;

//	DEBUG_LOG1("�յ�XMP���ݰ���ʱ�䣺%lu\n",m_LastReadTime);	

	//����ǲ�������
	CXMPPackage *pXMPPackage = (CXMPPackage *)pPackage;
	if(pXMPPackage->GetActiveID() == XMPTypeNone&& 
		pXMPPackage->GetExtTag() == XMPTagHeartbeatTimeOut)
	{
		SetWriteTimeout(pXMPPackage);
		return 0;
	}
	return CProtocol::Pop(pPackage);
}

int CXMPProtocol::Push(CPackage *pPackage, CProtocol *pUpper)
{
	((CXMPPackage *)m_pSendPackage)->GetXMPHeader()->Type = (BYTE)pUpper->GetActiveID();

	//�������·������ݰ���ʱ��
	m_LastWriteTime = m_pReactor->Time();

	return CProtocol::Push(pPackage, pUpper);
}

void CXMPProtocol::OnTimer(int nIDEvent)
{
	if(nIDEvent == XMP_HEARTBEAT_TIMER_ID)
	{
		if(m_pReactor->Time()-m_LastReadTime > m_dwReadTimeout)
		{
			//��������ʱ��֪ͨ�²�Э��
			NET_CONNECT_LOG2("Heartbeat Receive Timeout, CurrentTime=%lu LastTime=%lu\n",m_pReactor->Time(),m_LastReadTime);	
			NotifyError(MSG_XMPERR_RECVHEARTBEAT, 0, this);
			return ;
		}

		if(m_pReactor->Time()-m_LastWriteTime >= m_dwWriteTimeout)
		{
			NET_CONNECT_LOG1("Send Heartbeat %d\n", m_pReactor->Time());			
			//��������ʱ������������
			if(SendHeartbeat()<0)
			{
				NotifyError(MSG_XMPERR_SENDHEARTBEAT, 0, this);
				return ;
			}
		}

		if(m_pReactor->Time()-m_LastWarnTime > m_dwWarningTimeout)
		{
			//��������ʱ��֪ͨ�²�Э��
			NET_CONNECT_LOG2("Heartbeat Receive Warning, CurrentTime=%lu LastTime=%lu\n",m_pReactor->Time(),m_LastWarnTime);	
			NotifyError(MSG_XMPWARNING_RECVHEARTBEAT, m_pReactor->Time() - m_LastWarnTime, this);
			m_LastWarnTime = m_pReactor->Time();
			return ;
		}
	}
}

int CXMPProtocol::SendHeartbeat()
{
	int len = GetHdrReserveLen();
	CXMPPackage HeartbeatPackage;
	HeartbeatPackage.ConstructAllocate(0, len);

	HeartbeatPackage.SetExtHeader(XMPTagKeepAlive, 0, NULL);
	
	//�������·������ݰ���ʱ��
	m_LastWriteTime = m_pReactor->Time();

	int ret = Send(&HeartbeatPackage);

	return ret;
}

int CXMPProtocol::OnRecvErrorPackage(CPackage *pPackage)
{
	NotifyError(MSG_XMPERR_BADPACKAGE, 0, this);
	return 0;
}

void CXMPProtocol::EnableHeartbeat(bool bEnable)
{
	if (m_bHeartEnable == bEnable)
	{
		return ;
	}
	if (bEnable)
	{
		SetTimer(XMP_HEARTBEAT_TIMER_ID, 1000);
	}
	else
	{
		KillTimer(XMP_HEARTBEAT_TIMER_ID);
	}
	m_bHeartEnable = bEnable;
}

void CXMPProtocol::SetHeartbeatTimeout(DWORD dwReadTimeout)
{
	if (m_dwReadTimeout != dwReadTimeout)
	{
		m_dwReadTimeout = dwReadTimeout;
		if (m_dwReadTimeout < 4)
		{
			m_dwReadTimeout = 4;
		}
		m_dwWarningTimeout = dwReadTimeout/2;
		DWORD dwWriteTimeout = (m_dwReadTimeout-1)/3;
		SendWriteTimeout(dwWriteTimeout);
	}
}

int CXMPProtocol::SendWriteTimeout(DWORD dwWriteTimeout)
{
	int len = GetHdrReserveLen();
	CXMPPackage pkgHeartbeatTimeout;
	pkgHeartbeatTimeout.ConstructAllocate(sizeof(dwWriteTimeout), len);

	CHANGE_ENDIAN(dwWriteTimeout);

	pkgHeartbeatTimeout.SetExtHeader(XMPTagHeartbeatTimeOut, 
		sizeof(dwWriteTimeout), (BYTE *)&dwWriteTimeout);
	
	//�������·������ݰ���ʱ��
	m_LastWriteTime = m_pReactor->Time();

	int ret = Send(&pkgHeartbeatTimeout);

	return ret;
}

void CXMPProtocol::SetWriteTimeout(CXMPPackage *pPackage)
{
	if (pPackage->GetExtTagLen() != sizeof(DWORD))
	{
		return;
	}
	memcpy(&m_dwWriteTimeout, pPackage->GetExtData(), sizeof(DWORD ));
	CHANGE_ENDIAN(m_dwWriteTimeout);
	if (m_dwHeartbeatMode & XMPHBT_SLAVE_MODE)
	{
		SetHeartbeatTimeout(m_dwWriteTimeout*3+1+3);
	}
}

void CXMPProtocol::SetHeartbeatMode(DWORD dwHeartbeatMode)
{
	m_dwHeartbeatMode = dwHeartbeatMode;
}

