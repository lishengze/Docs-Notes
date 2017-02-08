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

/**CTcpMServer是一个基于TCP的网络服务器端
*/
class  CTcpMServer 
{
public:
	/**构造函数，在指定的服务名上侦听网络的连接
	* @param  pName	指定的服务名称
	*/
	CTcpMServer(CServiceName *pName, int nCreateChannel=0);
	
	/**析构函数，释放占用的资源
	*/
	virtual ~CTcpMServer();
	
	
	void Join();
	
	/** 基于TCP的获取select文件号方法
	* @return select时的文件号
	*/
	int GetId(void);

	/**基于TCP的等待客户端连接方法
	* @param  wait	表示需要等待到连接才返回，0表示不等待
	* @return NULL   新Channel未建成功
	* @return 非NULL 新的Channel
	*/
	int Accept(int wait);

	///创建Channel用于接收客户端请求的服务。
	int CreateChannel(int id);
	///接收客户端请求的服务的内容，解析并返回处理结果。
	int ReadChannel(int nIndex);
	///关闭客户端连接。
	int CloseChannel(int nIndex);

	///获取对端地址信息
	char *GetRemoteName(int id) ;

	///获取对端地址信息
	char *GetRemoteAddress(int id) ;

	///设置本服务是否允许Oracle用户对象读入配置文件。
	void SetReloadFile(bool bReload) { m_bReloadFile = bReload;}
	//获取客户端连接表
	CMChannel *GetChannel(void) {return m_pChannel;}

private:
	int m_nID;	/**< 存储本服务器端的文件号 */
	unsigned int m_nTouchCount;		//保存服务端口被touch的次数
	bool m_bReloadFile;	  //连接到来时是否需要重新加载文件
	CMChannel *m_pChannel;	//客户端连接表
};

#endif // !defined(TCP_M_SERVER_H)
