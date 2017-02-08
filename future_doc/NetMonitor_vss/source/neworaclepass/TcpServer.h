// TcpServer.h: interface for the CTcpServer class .
//
// 2006.10.11	�Ժ��	Ϊ֧��SSL�����ӷ���CreateChannel 
// 2007.07.02	���ٻ�	���ӿͻ���Channel������
// 2008.03.11   wang.xp ����LINUX֧��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPSERVER_H__FE5CED67_6EC3_11D7_BB64_444553540000__INCLUDED_)
#define AFX_TCPSERVER_H__FE5CED67_6EC3_11D7_BB64_444553540000__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "platform.h"
#include "ServiceName.h"
#include "DBUser.h"
#include "CLogger.h"

#include <time.h>

#define CHANNEL_MAX 128
#define CHANNEL_TIMEOUT 30

#ifdef LINUX
typedef  socklen_t name_len_t;
#else
#ifdef AIX
typedef  socklen_t name_len_t;
#else
typedef int name_len_t;
#endif
#endif


class CChannel {
public:
	int m_nID;
	char buffer[512];
    int nLen;
	time_t tLogin;
	char addr[32];
	unsigned int nIP;
};

/**CTcpServer��һ������TCP�������������
*/
class  CTcpServer 
{
public:
	/**���캯������ָ���ķ��������������������
	* @param  pName	ָ���ķ�������
	*/
	CTcpServer(CServiceName *pName, CFileLogger *fpLog, int nCreateChannel=0);
	
	/**�����������ͷ�ռ�õ���Դ
	*/
	virtual ~CTcpServer();
	
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

	///����Oracle�û��ӿڶ���
	void SetDBUser(CDBUser *pDBUser) {m_pDBUser = pDBUser;}

	///���ñ������Ƿ�����Oracle�û�������������ļ���
	void SetReloadFile(bool bReload) { m_bReloadFile = bReload;}
	//��ȡ�ͻ������ӱ�
	CChannel *GetChannel(void) {return m_pChannel;}

private:
	int m_nID;	/**< �洢���������˵��ļ��� */
	CDBUser *m_pDBUser;	//Oracle�û��ӿڶ���
	bool m_bReloadFile;	  //���ӵ���ʱ�Ƿ���Ҫ���¼����ļ�
	CChannel *m_pChannel;	//�ͻ������ӱ�
	CFileLogger *m_fpLog;	//��־�ļ�����ָ��
};

#endif // !defined(AFX_TCPSERVER_H__FE5CED67_6EC3_11D7_BB64_444553540000__INCLUDED_)
