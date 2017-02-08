// ListenCtrl.h: interface for the CListenCtrl class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTENCTRL_H__203EA6D7_4E89_4512_9A8C_7D762BAF2D9F__INCLUDED_)
#define AFX_LISTENCTRL_H__203EA6D7_4E89_4512_9A8C_7D762BAF2D9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EventHandler.h"
#include "Server.h"
#include "Channel.h"

/**��һ������TCP������������ˣ���EventHandler�����࣬���ܿͻ��˵���������
*/
class  CListenCtrl : public CEventHandler  
{
public:
	/**���캯��
	* @param pReactor  ��������ָ��
	* @param pServer   һ��TcpServer��ָ��
	*/
	CListenCtrl(CReactor *pReactor,CServerBase *pServer);
	
	/**��������
	*/
	virtual ~CListenCtrl();
	
	/**��Reactor���ã��������������¼�
	* @return 0 �ɹ�
	* @return -1 ʧ��
	*/
	virtual int HandleInput();
	
	/**��ü���id
	* @param pReadId   һ��Server�׽���Idָ�룬���ڷ���
	* @param pWriteId  ����
	*/
	virtual void GetIds(int *pReadId, int *pWriteId);
protected:

	/**�����µ�����ʱ�����õķ������������ʵ�ָ÷���
	* @param pChannel  һ���µ�Channelָ��
	* @return 0 �ɹ�
	*/
	virtual int OnConnected(CChannel *pChannel)=0;
protected:
	CServerBase *m_pServer;		/**< һ��Serverָ�� */
};

/**
 * ��һ������UDP������������ˣ���EventHandler�����࣬����UDP���ݱ��㲥��
 */
class  CUdpListenCtrl : public CEventHandler  
{
public:
	/**���캯��
	 * @param pReactor  ��������ָ��
	 * @param pServer   һ��TcpServer��ָ��
	 */
	CUdpListenCtrl(CReactor *pReactor, CServerBase *pServer);
	
	/**��������
	 */
	virtual ~CUdpListenCtrl();
	
	/**��Reactor���ã��������������¼�
	 * @return 0 �ɹ�
	 * @return -1 ʧ��
	 */
	virtual int HandleInput();
	
	/**��ü���id
	 * @param pReadId   һ��Server�׽���Idָ�룬���ڷ���
	 * @param pWriteId  ����
	 */
	virtual void GetIds(int *pReadId, int *pWriteId);

protected:

	/**
	 * �����µ�udp ���ݱ�����ʱ�����õķ������������ʵ�ָ÷���
	 * @param pChannel  һ����Channelָ��
	 * @return 0 �ɹ�
	 */
	virtual int OnRecvDatagram(CChannel *pChannel)=0;
protected:
	CChannel *m_pChannel;		/**< һ��Channelָ�� */
	CServerBase *m_pServer;	/**< һ��Serverָ�� */
};

#endif // !defined(AFX_LISTENCTRL_H__203EA6D7_4E89_4512_9A8C_7D762BAF2D9F__INCLUDED_)
