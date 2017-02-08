/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	QueryServer.h
///@brief	定义了前置监听监控客户端连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_QUERYSERVER_H
#define REF_QUERYSERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "slogparser.h"

#include <SQLAPI.h>
#include <DBOperator.h>

class CQueryServer;

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
		CQueryTimmer(CReactor *pReactor, CQueryServer *pQuery);

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

		CQueryServer *m_pQueryServer;
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
class CQueryServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
			///@param	pReactor	CReactor对象指针
		CQueryServer(CReactor *pReactor);

		///析构函数
		~ CQueryServer(void);

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

		///历史告警事件查询
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryWarningEvent(
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

		void OnReqQryHistoryCpuInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	///历史Cpu状态查询
		void OnReqQryHistoryMemInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	///历史Mem状态查询
		void OnReqQryHistoryNetworkInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	///历史网络状态查询
		void OnReqQryWebVisitInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 网站访问统计信息查询
		void OnReqQryNetMonitorTaskResult(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 历史巡检结果查询
		void OnReqQryNetPartyLinkStatusInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 会员状态查询
		void OnReqQryNetBaseLineResult(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 基线结果查询
		void OnReqQryTradeFrontOrderRttStat(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 前置响应时间
		void OnReqQryOrderRttCutLine(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 报单统计用的区间
		void OnReqQryNetLocalPingResult(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 本地ping结果
		void OnReqQryNetRomotePingResultInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 远程ping结果
		void OnReqQryRouterInfoInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 系统路由
		void OnReqQryDiskIOInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 磁盘io
		void OnReqQryStatInfoInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 系统状态
		void OnReqQryTopProcessInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// 进程信息查询
		void OnReqQryParticTradeOrderStates(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnReqQryPerformanceTopTopic(	/// 网络性能TopN查询
			CFTDCPackage *pFTDCPackage,
			CFTDCSession *pSession);

		void GetRow(
				SACommand *pCommand,
				char *buf,
				CFieldDescribe	*pFieldDescribe);

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
		///连接数据库，如果是连接着的，就不再进行连接
			///2009.1.5 chg by Solomon, 返回值由void 改为bool
			///return:
			/// true 进行了正确的连接
		bool connectDB(void);

		/// the database server connection status
			/// 我们使用的SQLAPI版本没有这个函数，新的版本有
		bool isAlive(SAConnection *conn) const;

		///利用全局变量，生成ip:port/dbname的字符串
		string	getConnectStr(
					const string &ip,
					const string &port,
					const string &dbName) const;

		/// 取得所有用户的信息
			/// return:
			///		0 - "db query finish"; 访问成功，有记录
			///		1 - "DB access exception";
			///		2 - 数据库访问成功，但是没有记录
		int getUserInfoList(list<CFTDRtnSysUserField *> &userList);

		/// 取得单个用户的信息
			/// return:
			///		0 - "db query finish"; 访问成功，有记录
			///		1 - "DB access exception";
			///		2 - 数据库访问成功，但是没有记录
		int getUserInfoSingle(
				CFTDRtnSysUserField &record,
				const string &userID);

		/// 取得单个用户的信息
			/// return:
			///		0 - "db query finish"; 访问成功，有记录
			///		1 - "DB access exception";
			///		2 - 数据库访问成功，但是没有记录
		int getUserInfoSingle(
				CFTDRtnSysUserField &record,
				const string &userID,
				const string &password);

	/* */
	private:
		///数据库的连接句柄 (连接使用的参数定义在sysquery.cpp，暂时)
		SAConnection *m_sqlConnect;

		SyncDBOperator	m_hander;

		list<CFTDCSession *> m_frontSessions;
};
#endif // REF_QUERYSERVER_H END
