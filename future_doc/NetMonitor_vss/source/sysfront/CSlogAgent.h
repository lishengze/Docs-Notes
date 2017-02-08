/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSlogAgent.h
///@brief	定义了查询代理的类
///@history
///2014.5.30	feng.gc		创建该文件

#ifndef REF_SLOGAGENT_H
#define REF_SLOGAGENT_H

#include "public.h"
#include "CachedFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"

class CFrontServer;
class CSlogAgent :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/*  和 SlogServer 连接的处理类 */
	public:
		CSlogAgent(CReactor *pReactor);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		CFTDCSession *GetSlogSession(void)
		{
			return m_pSlogSession;
		}

		void SetFrontServer(CFrontServer *pFrontServer)
		{
			m_pFrontServer = pFrontServer;
		}

		const CFTDRtnTradeOrderRttCutLineField& getRtnCutLine()const;

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

		///针对Slog的处理
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQryTradeLogTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///针对NGES前置机状态查询返回的处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQryFrontInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnTradeOrderRttCutLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///前置保单响应信息
		void OnRtnTradeFrontOrderRttStatTopic(
			CFTDCPackage *pFTDCPackage,
			CFTDCSession *pSession);

	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///登录成功标志
		bool m_bLoginFlag;

		///前置机对Slog服务器的SESSION
		CFTDCSession *m_pSlogSession;

		///前置机对客户端的SESSION
		CFrontServer *m_pFrontServer;

		// 给FrontServer调用，不用全局的变量
        CFTDRtnTradeOrderRttCutLineField m_rtnCutLine;

};

#endif
