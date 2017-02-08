// TcpServer.h: interface for the CTcpServer class .
//
// 2006.10.11	赵鸿昊	为支持SSL，增加方法CreateChannel 
// 2007.07.02	严少辉	增加客户端Channel处理方法
// 2008.03.11   wang.xp 增加LINUX支持
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

/**CTcpServer是一个基于TCP的网络服务器端
*/
class  CTcpServer 
{
public:
	/**构造函数，在指定的服务名上侦听网络的连接
	* @param  pName	指定的服务名称
	*/
	CTcpServer(CServiceName *pName, CFileLogger *fpLog, int nCreateChannel=0);
	
	/**析构函数，释放占用的资源
	*/
	virtual ~CTcpServer();
	
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

	///设置Oracle用户接口对象
	void SetDBUser(CDBUser *pDBUser) {m_pDBUser = pDBUser;}

	///设置本服务是否允许Oracle用户对象读入配置文件。
	void SetReloadFile(bool bReload) { m_bReloadFile = bReload;}
	//获取客户端连接表
	CChannel *GetChannel(void) {return m_pChannel;}

private:
	int m_nID;	/**< 存储本服务器端的文件号 */
	CDBUser *m_pDBUser;	//Oracle用户接口对象。
	bool m_bReloadFile;	  //连接到来时是否需要重新加载文件
	CChannel *m_pChannel;	//客户端连接表
	CFileLogger *m_fpLog;	//日志文件对象指针
};

#endif // !defined(AFX_TCPSERVER_H__FE5CED67_6EC3_11D7_BB64_444553540000__INCLUDED_)
