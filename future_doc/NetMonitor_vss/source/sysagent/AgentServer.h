/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	AgentServer.h
///@brief	定义了事件计算服务器监听采集代理连接处理的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_AGENTSERVER_H
#define REF_AGENTSERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "AgentConnector.h"

/////////////////////////////////////////////////////////////////////////
///AgentServer定义了监听采集代理连接管理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
			///@param	pSaveFile	保存索引的文件名
		CAgentServer(CReactor *pReactor);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

	/* */
	protected:
		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///应答探针请求配置处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRspQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///用户登录应答处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///用户退出请求处理函数
			///@param	pFTDCPackage	FTDCpackage数据包地址
			///@param	pSession	数据包所属的会话ID
		void OnReqUserLogout(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///切换交易日请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///此链接的别名，如 "ZJ-Agent06"
		string	m_sUpLinkName;

		///此链接的连接串，如 "tcp://172.18.38.61:18806"
		string	m_sUpLinkLocation;
};
#endif // REF_AGENTSERVER_H
