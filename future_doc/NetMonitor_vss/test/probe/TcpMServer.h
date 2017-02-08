// TcpServer.h: interface for the CTcpMServer class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(TCP_M_SERVER_H)

#define TCP_M_SERVER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "platform.h"
#include "ServiceName.h"
#include "CLogger.h"
#include "monitorIndex.h"
#include <time.h>

#define CHANNEL_MAX 128
#define CHANNEL_TIMEOUT 30

#ifdef LINUX
typedef  socklen_t name_len_t;
#else
typedef int name_len_t;
#endif


class CMChannel {
public:
	int m_nID;
	char buffer[512];
    int nLen;
	time_t tLogin;
	char addr[32];
	unsigned int nIP;
};

/**CTcpMServer��һ������TCP�������������
*/
class  CTcpMServer 
{
public:
	/**���캯������ָ���ķ��������������������
	* @param  pName	ָ���ķ�������
	*/
	CTcpMServer(CServiceName *pName, int nCreateChannel=0);
	
	/**�����������ͷ�ռ�õ���Դ
	*/
	virtual ~CTcpMServer();
	
	
	void Join();
	
	/** ����TCP�Ļ�ȡselect�ļ��ŷ���
	* @return selectʱ���ļ���
	*/
	int GetId(void);

	/**����TCP�ĵȴ��ͻ������ӷ���
	* @param  wait	��ʾ��Ҫ�ȴ������Ӳŷ��أ�0��ʾ���ȴ�
	* @return NULL   ��Channelδ���ɹ�
	* @return ��NULL �µ�Channel
	*/
	int Accept(int wait);

	///����Channel���ڽ��տͻ�������ķ���
	int CreateChannel(int id);
	///���տͻ�������ķ�������ݣ����������ش�������
	int ReadChannel(int nIndex);
	///�رտͻ������ӡ�
	int CloseChannel(int nIndex);

	///��ȡ�Զ˵�ַ��Ϣ
	char *GetRemoteName(int id) ;

	///��ȡ�Զ˵�ַ��Ϣ
	char *GetRemoteAddress(int id) ;

	///���ñ������Ƿ�����Oracle�û�������������ļ���
	void SetReloadFile(bool bReload) { m_bReloadFile = bReload;}
	//��ȡ�ͻ������ӱ�
	CMChannel *GetChannel(void) {return m_pChannel;}

private:
	int m_nID;	/**< �洢���������˵��ļ��� */
	unsigned int m_nTouchCount;		//�������˿ڱ�touch�Ĵ���
	bool m_bReloadFile;	  //���ӵ���ʱ�Ƿ���Ҫ���¼����ļ�
	CMChannel *m_pChannel;	//�ͻ������ӱ�
};

#endif // !defined(TCP_M_SERVER_H)
