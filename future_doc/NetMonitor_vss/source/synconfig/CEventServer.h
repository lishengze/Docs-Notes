/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CEventServer.h
///@brief	定义了监听eventcounter端连接处理的类
///@history
///20110818	李志伟		创建该文件
#ifndef REF_CEVENTSERVER_H
#define REF_CEVENTSERVER_H

#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CMsgGenerator.h"

#include <FTDDataWrapper.h>
#include <DBOperator.h>
#include <PrjCommon.h>

#define EVENT_MIN_CYCLE 5

class CEventServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CEventServer(CReactor *pReactor);

		bool Init(void)
		{
			return true;
		}

		bool Init(char *pszPath, char *pszMsgPolicy, char *pszSystemID)
		{
			m_MsgGenerator.Init(pszPath, pszMsgPolicy, pszSystemID);
			m_MsgGenerator.Create();
			return true;
		}

		void NotifyAllSessions(CFTDCPackage *reqPkg);

	/* */
	private:
		///新建会话时调用的处理函数
		    ///@param	pChannel	会话所属的通道地址
		    ///@param	bIsListener	会话是否是监听服务器类型
		    ///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
		    ///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///用户登录请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void OnRtnWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnSyslogEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///生成消息文件的工具类对象
		CMsgGenerator m_MsgGenerator;

		friend class SessionProxy;

		typedef std::vector<CFTDCSession *> SessionSet;
		SessionSet m_sessions;

		// 多线程访问m_sessions时的互斥锁
		CMutex m_lock;
};
#endif // REF_CEVENTSERVER_H
