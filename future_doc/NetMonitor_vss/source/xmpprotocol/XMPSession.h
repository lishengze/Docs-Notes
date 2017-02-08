// XMPSession.h: interface for the CXMPSession class.
//
// 2007.8.1 �Ժ�� ���Ӷ�������ʱ����
// 20090427 �Ժ�� NT-0071������SetHeartbeatMode����
//                 �������ģʽΪSlave������Է���������ʱʱ��һ��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMPSESSION_H__D0B1F13E_7E9B_4AB0_BFF7_F20EC92F71CD__INCLUDED_)
#define AFX_XMPSESSION_H__D0B1F13E_7E9B_4AB0_BFF7_F20EC92F71CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Session.h"
#include "XMPProtocol.h"

class CXMPSession : public CSession  
{
public:
	CXMPSession(CReactor *pReactor,CChannel *pChannel);
	virtual ~CXMPSession();
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);
	void SetHeartbeatTimeout(DWORD dwReadTimeout);
	void SetHeartbeatMode(bool bSlaveMode);
protected:
	CXMPProtocol *m_pXMPProtocol;	/**< �����ڵĵڶ���Э��(���²���ʼ)*/

};

#endif // !defined(AFX_XMPSESSION_H__D0B1F13E_7E9B_4AB0_BFF7_F20EC92F71CD__INCLUDED_)
