/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSynConnector.h
///@brief	定义了连接配置管理服务器通信消息的类
///@history
///20110112	周建军		创建该文件
#ifndef REF_CSYNCONNECTOR_H
#define REF_CSYNCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"

// 面向事件计算服务器连接的类
//
class CFrontServer;
class CSynConnector :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CSynConnector(CReactor *pReactor);

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
			return m_pSynSession;
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

		///用户登录应答处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///对FIBCLIENT连接成功的标志位
		bool m_Flag;

		///前置机对配置服务器的SESSION
		CFTDCSession *m_pSynSession;

		///前置机对客户端的SESSION
		CFrontServer *m_pFrontServer;
};

#define SYNCFGRSP(x)																						\
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

#endif // REF_CSYNCONNECTOR_H end
