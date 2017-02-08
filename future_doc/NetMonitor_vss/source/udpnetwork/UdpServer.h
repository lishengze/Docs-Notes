// UdpServer.h: interface for the CUdpServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDPSERVER_H__AA737DFB_1BC5_4B35_9EEB_BCC53F1617FC__INCLUDED_)
#define AFX_UDPSERVER_H__AA737DFB_1BC5_4B35_9EEB_BCC53F1617FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Channel.h"
#include "ServiceName.h"
#include "Server.h"

class CUdpServer : public CServerBase 
{
public:
	CUdpServer(CServiceName *pName);
	virtual ~CUdpServer();
	
protected:
	/*���տͻ�������
	* @param  wait	��ʾ��Ҫ�ȴ������Ӳŷ��أ�0��ʾ���ȴ�
	* @return NULL   ��Channelδ���ɹ�
	* @return ��NULL �µ�Channel
	*/
	virtual CChannel *Accept(int wait);

	virtual int GetId(void);
private:
	int m_nID;	/**< �׽��� */
	CServiceName m_ServiceName;
	bool m_bConnected;
};

#endif // !defined(AFX_UDPSERVER_H__AA737DFB_1BC5_4B35_9EEB_BCC53F1617FC__INCLUDED_)
