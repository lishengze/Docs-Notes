/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CSlogServer.h
///@brief	定义了前置监听监控客户端连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
///20140528 史战伟      修订注释
#ifndef REF_SLOGSERVER_H
#define REF_SLOGSERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "slogparser.h"

class CSlogServer;

/////////////////////////////////////////////////////////////////////////
///CQueryTimmer定义了前置定期器处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CQueryTimmer :
	public CEventHandler
{
	/* */
	public:
		///构造函数
		CQueryTimmer(CReactor *pReactor, CSlogServer *pQuery);

		/** 设置定时器函数
	* @param	nIDEvent	定时器产生的事件ID
	* @param	nElapse	定时器的时间间隔，单位ms
	*/
		void SetTimer(int nIDEvent, int nElapse);

		/** 定时器处理函数
	* @param	nIDEvent	该定时器的ID
	*/
		virtual void OnTimer(int nIDEvent);

	/* */
	private:
		///用于发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///保存定时器的事件ID
		int m_nEventId;

		CSlogServer *m_pQueryServer;
};

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory定义了采集代理探针会话连接类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentSessionFactory :
	public CSessionFactory
{
	/* */
	public:

		///构造函数
		CAgentSessionFactory(CReactor *pReactor, int nMaxSession) :
		CSessionFactory(pReactor, nMaxSession)
		{
		}

		///注册连接函数
			///@param	location	连接的地址
		void RegisterConnecter(char *location)
		{
			CSessionFactory::RegisterConnecter(location);
			memset(m_location, 0, MAXLOCATIONLEN);
			strcpy(m_location, location);
		}

		///取连接地址函数
			///@return	返回连接地址的指针
		char *GetLocationName(void)
		{
			return m_location;
		}

	/* */
	private:
		///保存注册的连接地址
		char m_location[MAXLOCATIONLEN];
};

/////////////////////////////////////////////////////////////////////////
///CFrontServer定义了前置的监控客户端连接处理类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CSlogServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
		CSlogServer(CReactor *pReactor);

		///析构函数
		~ CSlogServer(void);

		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///新建会话时调用的处理函数
			///@param	pChannel	会话所属的通道地址
			///@param	bIsListener	会话是否是监听服务器类型
			///@return	返回创建的新会话
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		void NotifyAllSession(CFTDCPackage *pkg);

		//定时检查slog的rtt是否有新数据要推给前置
		void CheckTradeFrontRtt(void);

	/* */
	protected:
		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///Slog日志查询
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradeLog(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///最近几个Slog日志查询
		    ///@param	pFTDCPackage	需要处理的FTDC包地址
		    ///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryLatestTradeLog(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///历史对象状态查询
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryHistoryObjectAttr(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///前置响应分析查询
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryFrontInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///用户注册
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySysUserRegister(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQrySysUserLogin(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQrySysUserLogout(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQrySysUserPasswordUpdate(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQrySysUserDelete(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);


	///在VC 6.0 下这样的使用会存在问题
		///template<class INFIELD, class OUTFIELD>
		///void  query(const DWORD TID, const string &tableName, CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///定时器对象
		CQueryTimmer m_eventTimer;

	//20080715 add wy.yb
	private:

	/* */
	private:
		list<CFTDCSession *> m_frontSessions;
		static CQWordMonitorIndex* m_pRtt2FrontByteMonitor;
};
#endif // REF_SLOGSERVER_H
