/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CounterConnector.h
///@brief	定义了连接事件计算服务器并处理该服务器通信消息的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_COUNTERCONNECTOR_H
#define REF_COUNTERCONNECTOR_H

#include "FrontServer.h"

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory定义了面向事件计算服务器连接的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CCountConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
		CCountConnector(CReactor *pReactor);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		CFTDCSession *GetCountSession(void)
		{
			return m_pCountSession;
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

		///切换交易日请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQryJDBCInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void ClearMemeryDatabase(void);

		void RemoveOneDayFromMDB(const char *strDay);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///前置机对客户端的SESSION
		CFrontServer *m_pFrontServer;

		CFTDCSession *m_pCountSession;

		///当前的交易日
		string	m_sCurTradeDay;
};

#define CLEARMEMDB(x)														 \
	{																		 \
		C##x *sfield = pMemoryDB->m_##x##Factory->startFindBytheAll();		 \
		while (sfield)														 \
		{																	 \
			C##x *tfield = pMemoryDB->m_##x##Factory->findNextBytheAll();	 \
			if (sfield->MonDate < beginDate									 \
			||	(sfield->MonDate == beginDate && sfield->MonTime < theTime)) \
			{																 \
				pMemoryDB->m_##x##Factory->remove(sfield);					 \
			}																 \
																  \
			sfield = tfield;												 \
		}																	 \
	}

#endif	// REF_COUNTERCONNECTOR_H END
