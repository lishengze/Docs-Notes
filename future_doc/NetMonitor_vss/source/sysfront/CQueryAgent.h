/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CQueryAgent.h
///@brief	定义了查询代理的类
///@history
///20080810	郭鹏		创建该文件
///20080810	郭鹏		修订注释
#ifndef REF_QUERYAGENT_H
#define REF_QUERYAGENT_H

#include "public.h"
#include "CachedFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"

class CFrontServer;
class CQueryAgent :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		CQueryAgent(CReactor *pReactor);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		CFTDCSession *GetQuerySession(void)
		{
			return m_pQuerySession;
		}

		void SetFrontServer(CFrontServer *pFrontServer)
		{
			m_pFrontServer = pFrontServer;
		}

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

		///针对告警事件查询返回的处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQryWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///针对历史主机状态属性查询返回的处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQryHistoryObjectAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///针对NGES前置机状态查询返回的处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQryFrontInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///针对SysMonitor登录返回的处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQrySysUserLoginTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///针对SysMonitor登出返回的处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspQrySysUserLogoutTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///内部函数，用于成功登录后对客户端进行初始化
			///@param	pSession	数据包所属的FTD会话指针
		void OnClientInit(CFTDCSession *pSession);

		///针对SysQuery对SysFront同步SysMonitor所有用户信息的处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRtnSysUser(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void OnRtnHistoryTradePeakTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQrySyslogEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///针对网络性能排序查询返回的处理函数
		///@param	pFTDCPackage	需要处理的FTDC包地址
		///@param	pSession	数据包所属的FTD会话指针
		void OnRspQryPerformanceTopTopic(
			CFTDCPackage *pFTDCPackage,
			CFTDCSession *pSession);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///登录成功标志
		bool m_bLoginFlag;

		///前置机对查询服务器的SESSION
		CFTDCSession *m_pQuerySession;

		///前置机对客户端的SESSION
		CFrontServer *m_pFrontServer;
};

///用于处理来自于SYSQUERY的RSP报文的宏
#define QUERYRSP(x)																							\
	{																										\
		int nRid = pFTDCPackage->GetRequestId();															\
		map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);									\
		TRID rid = it->second;																				\
		m_pkgSend.PreparePackage(																			\
				FTD_TID_RspQry##x##Topic,																	\
				FTDC_CHAIN_LAST,																			\
				FTD_VERSION);																				\
		m_pkgSend.SetChain(pFTDCPackage->GetChain());														\
		m_pkgSend.SetRequestId(rid.RequestId);																\
		CFTDRspInfoField rspInfoField;																		\
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)											\
		{																									\
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);														\
		}																									\
																									 \
		CFTDRspQry##x##Field sfield;																		\
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(										\
				&CFTDRspQry##x##Field::m_Describe);															\
		while (!itor.IsEnd())																				\
		{																									\
			itor.Retrieve(&sfield);																			\
			CFTDRspQry##x##Field tfield;																	\
			CopyRspQry##x##Entity(&tfield, &sfield);														\
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);															\
			itor.Next();																					\
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())								\
			{																								\
				break;																						\
			}																								\
		}																									\
																									 \
		if (m_pFrontServer->GetSession(rid.SessionID))														\
		{																									\
			((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend); \
		}																									\
																									 \
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)													\
		{																									\
			m_pFrontServer->m_vRid.erase(it);																\
		}																									\
	}

///用于处理来自于SYSQUERY的关于系统管理报文的宏
#define SYSMANAGERRSP																						  \
	{																										  \
		int nRid = pFTDCPackage->GetRequestId();															  \
		map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);									  \
		TRID rid = it->second;																				  \
		if (m_pFrontServer->GetSession(rid.SessionID))														  \
		{																									  \
			pFTDCPackage->SetRequestId(rid.RequestId);														  \
			((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(pFTDCPackage); \
		}																									  \
																									   \
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)													  \
		{																									  \
			m_pFrontServer->m_vRid.erase(it);																  \
		}																									  \
	}

#endif
