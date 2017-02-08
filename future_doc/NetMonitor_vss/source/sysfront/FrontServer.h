/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FrontServer.h
///@brief	定义了前置监听监控客户端连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#ifndef REF_FRONTSERVER_H
#define REF_FRONTSERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "databaseData.h"
#include "UFCopy.h"
#include "CCrypto.h"

#define RTNCOUNT	5
extern CMemoryDB *pMemoryDB;
extern CStringIdMap g_StringIdMap;
extern char *g_Today;
class CQueryAgent;
class CSlogAgent;
class CCountConnector;
class CSynConnector;
class CFlowConnector;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pClnPackOutput;	// 数据包输出到文件
extern CLogger	*g_pQryPackOutput;
extern CLogger	*g_pEntPackOutput;
extern CLogger	*g_pFibPackOutput;
extern CLogger	*g_pFwdPackOutput;
#endif

///todo:test
#define DIVIDESTR	"*:*"
#define OPTIONSTR	"*$*"

struct EventSubInfo
{
	///发生事件的对象ID指标
	CTypeObjectIDType ObjectID;

	///事件名
	CTypeObjectIDType EventName;

	///警告级别
	CTypeWarningLevelType WarningLevel;

	///过滤条件
	CTypeSubcriberObjectIDType	filter;

	///反过滤
	CTypeSubcriberObjectIDType	antifilter;

	CTypeProcessFlagType ProcessFlag;

	list<CFTDCSession *> Receiver;
};

struct TradeLogStrInfo
{
	int rId;
	CFTDCSession *pSession;
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

/*
typedef struct
{
	DWORD	SessionID;
	DWORD	RequestId;
}TRID;
*/

/////////////////////////////////////////////////////////////////////////
///CFrontServer定义了前置的监控客户端连接处理类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CFrontServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CFrontServer(
			CReactor *pReactor,
			CQueryAgent *pQueryAgent,
	        CSlogAgent *pSlogAgent,
			CCountConnector *pCountConnector,
			CSynConnector *pSynConnector,
			CFlowConnector	*pFlowConnector);

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

	/* */
	protected:
		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///后台内部登录请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryClientLogin(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///HandlePackage的默认处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnDefaultProcess(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///后台内部登录请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqUserLogin(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///前台用户管理请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnQryUserMgr(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///前台用户权限请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void QryUserFunc(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///前台用户登录请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryClientLoginTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///前台LocalPing请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryLocalPingTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///前台RemotePing请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryRemotePingTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///CPU信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTopCpuInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///内存信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTopMemInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///进程信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTopProcessInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///文件系统查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryFileSystemInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///网络信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryNetworkInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///磁盘信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryDiskIOTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///系统信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryStatInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///路由信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryRouterInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///系统资源查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySystemResourceAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///内存数据库查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryMemoryDBAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///交易核心信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryKernelAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///交易系统前置信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryFrontAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///TINIT信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTinitAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///排队机信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryCompositorAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///主机系统环境变量信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryHostEnvTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///取所有监控对象请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryMonitorObjectTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///对象关系信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryObjectRationalTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///数据中心信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryDataCenterTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///对象监控指标查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryObjectAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///系统日志查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySyslogInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///系统用户信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryUserInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///系统在线用户信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryOnlineUserInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///告警事件查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryWarningEventTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///历史监控对象指标信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryHistoryObjectAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///交易系统前置信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryFrontInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///交易日志查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradeLogTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///会员信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryParticipantInitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///告警时间变更信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryWarningEventUpdateTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///日志事件变更信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySyslogEventUpdateTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///交易用户登录信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradeUserLoginInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///会员交易信息查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnPartTradeTopic(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///交易峰值查询请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryTradepeakTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///监控系统登录请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySysUserLoginTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///监控系统登出请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySysUserLogoutTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///交易系统客户请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnClientInit(CFTDCSession *pSession);

		///会员限仓请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryPartPosiLimitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///客户限仓请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryClientPosiLimitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///特殊会员限仓请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQrySpecialPosiLimitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///交易系统座席请求处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
		void OnReqQryUserInitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///处理订阅监控指标请求函数
			///@param	pPackeage	请求的数据包地址
			///@param	pSession	请求的会话
		void OnReqQrySubcriberTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///处理查询监控对象的所有监控指标请求函数
			///@param	pPackeage	请求的数据包地址
			///@param	pSession	请求的会话
		void OnReqQryOidRelationTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///处理查询监控系统所有在线用户的请求函数
			///@param	pPackeage	请求的数据包地址
			///@param	pSession	请求的会话
		void OnReqQryMonitorOnlineUser(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryFrontStat(CFTDCPackage *pPackage, CFTDCSession *pSession);

		void OnReqQryHistoryTradePeakTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQrySyslogEventSubcriberTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQrySyslogEventTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryTomcatInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryDBQueryTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryGetFileTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryWarningQueryTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryWarningActiveChange(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryGeneralOperateTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryNetMonitorTaskResultTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryNetMonitorTaskStatusResultTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryTradeUserLoginStatTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryNetRoomTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryParticTradeOrderStatesTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		void OnReqQryTradeFrontOrderRttStatTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///处理查询网络性能排序的请求函数
		///@param	pPackeage	请求的数据包地址
		///@param	pSession	请求的会话
		void OnReqQryPerformanceTopTopic(
			CFTDCPackage *pPackage,
			CFTDCSession *pSession);
		
		int UpdateCurHandlePackageRID();

		void OnSessionResponse(DWORD tid, int errID = 0, ::std::string errMsg = "");	
		
		template<typename FTDField>
		void SendReqPackageOnAgentSession(FTDField& fieldInfo, CFTDCSession *pAgentSession
			, DWORD tid, bool isOutputPackage)
		{			
			m_pkgSend.PreparePackage(tid,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
	
		#ifdef PACKAGE_OUTPUT
			if(isOutputPackage)
			{
				m_pkgSend.OutputHeader(g_pFwdPackOutput);
				FTDC_DEBUG_BODY(m_pkgSend.GetTID(), &m_pkgSend, g_pFwdPackOutput);
			}
		#endif

			m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
			pAgentSession->SendRequestPackage(&m_pkgSend);
		}

	private:
		 CFTDCPackage* pCurHandlePackage;
		 CFTDCSession* pCurHandleSession;
	/* */																												 	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		CQueryAgent *m_pQueryAgent;
		CSlogAgent *m_pSlogAgent;
		CCountConnector *m_pCountConnector;
		CSynConnector *m_pSynConnector;
		CFlowConnector	*m_pFlowConnector;

		map<string, map<string, CFTDRspQrySyslogEventField> > m_mapIPSyslogDetail;

	/* */
	public:
		///向下层推送的整合RID列表
		map<int, TRID>	m_vRid;
		int m_Rid;
		DWORD m_dwLocaPingReqID;
		void OnSysUserLoginTopic(
				CUserIDType UserID,
				int rID,
				CFTDCSession *pSession);
};

///用于添加对象关系的宏
#define ADDOBJECTFIELD(x)							  \
	CFTDRspQryOidRelationField field[x];			  \
	for (int i = 0; i < x; i++)						  \
	{												  \
		field[i].ObjectID = ftdQryField.ObjectID;	  \
		field[i].HoldObjectID = ch[i];				  \
		FTDC_ADD_FIELD(pRspFtdcPackage, &(field[i])); \
	}

#define ADDOBJECTFIELDS		for (listIt = pList->begin(); \
								 listIt != pList->end();  \
								 listIt++)				  \
	{													  \
		field.ObjectID = ftdQryField.ObjectID;			  \
		field.HoldObjectID = (*listIt).c_str();			  \
		FTDC_ADD_FIELD(pRspFtdcPackage, &(field));		  \
	}

#define ADDERRORINFOFIELD	CFTDRspInfoField fieldRspInfo; \
	fieldRspInfo.ErrorMsg = "错误";						   \
	fieldRspInfo.ErrorID = 1;							   \
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo)

///用于管理平台部分内存数据库查询的宏:
/*
#define MANAGEPLATFORMPRSPQRY(x)\
{\
	g_OrderQryCount =1;\
	CFTDReqQry##x##Field qryfield;\
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield);\
	CSys##x *pfield =pMemoryDB->m_Sys##x##Factory->startFindByActionTime(qryfield.StartTime);\
	while(pfield)\
	{\
		if(pfield->ActionTime >qryfield.EndTime)\
			break;\
		m_pkgSend.PreparePackage(FTD_TID_RspQry##x##Topic, FTDC_CHAIN_CONTINUE, FTD_VERSION);\
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());\
		CFTDRspQry##x##Field field;\
		CopySys##x##Entity(&field,pfield);\
		FTDC_ADD_FIELD(&m_pkgSend, &field);\
		pSession->SendRequestPackage(&m_pkgSend);\
		pfield =pMemoryDB->m_Sys##x##Factory->findNextByActionTime();\
		if(++g_OrderQryCount >MAXQRYRETURNNUM)\
			{\
				pMemoryDB->m_Sys##x##Factory->endFindByActionTime();\
				m_pkgSend.PreparePackage(FTD_TID_RspQry##x##Topic, FTDC_CHAIN_LAST, FTD_VERSION);\
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());\
				CFTDRspInfoField rspInfoField;\
				memset(&rspInfoField ,0 ,sizeof(rspInfoField));\
				rspInfoField.ErrorID =ERR_REACHMAXRECORDNUM;\
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);\
				pSession->SendRequestPackage(&m_pkgSend);\
				break;\
			}\
	}\
	if(g_OrderQryCount <MAXQRYRETURNNUM)\
	{\
		pMemoryDB->m_Sys##x##Factory->endFindByActionTime();\
		m_pkgSend.PreparePackage(FTD_TID_RspQry##x##Topic, FTDC_CHAIN_LAST, FTD_VERSION);\
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());\
		CFTDRspInfoField rspInfoField;\
		memset(&rspInfoField ,0 ,sizeof(rspInfoField));\
		rspInfoField.ErrorID =0;\
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);\
		pSession->SendRequestPackage(&m_pkgSend);\
	}\
}
*/

///用于管理平台部分内存数据库查询的宏:
#define MANAGEPLATFORMPRSPQRY(x)											   \
	{																		   \
		CFTDReqQry##x##Field qryfield;										   \
		FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield);						   \
		CSys##x *pfield = pMemoryDB->m_Sys##x##Factory->startFindByActionTime( \
				qryfield.StartTime);										   \
		while (pfield)														   \
		{																	   \
			if (pfield->ActionTime > qryfield.EndTime)						   \
			{																   \
				break;														   \
			}																   \
																	\
			m_pkgSend.PreparePackage(										   \
					FTD_TID_RspQry##x##Topic,								   \
					FTDC_CHAIN_CONTINUE,									   \
					FTD_VERSION);											   \
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());			   \
			CFTDRspQry##x##Field field;										   \
			CopySys##x##Entity(&field, pfield);								   \
			FTDC_ADD_FIELD(&m_pkgSend, &field);								   \
			pSession->SendRequestPackage(&m_pkgSend);						   \
			pfield = pMemoryDB->m_Sys##x##Factory->findNextByActionTime();	   \
		}																	   \
																		\
		pMemoryDB->m_Sys##x##Factory->endFindByActionTime();				   \
		m_pkgSend.PreparePackage(											   \
				FTD_TID_RspQry##x##Topic,									   \
				FTDC_CHAIN_LAST,											   \
				FTD_VERSION);												   \
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());				   \
		CFTDRspInfoField rspInfoField;										   \
		memset(&rspInfoField, 0, sizeof(rspInfoField));						   \
		rspInfoField.ErrorID = 0;											   \
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);							   \
		pSession->SendRequestPackage(&m_pkgSend);							   \
	}

///用于管理平台INIT部分查询的宏：
#define MANAGEPLATFORMPINITRSPQRY(x)									  \
	{																	  \
		CFTDReqQry##x##Field qryfield;									  \
		FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield);					  \
		CSys##x *pfield = pMemoryDB->m_Sys##x##Factory->startFindByAll(); \
		while (pfield)													  \
		{																  \
			m_pkgSend.PreparePackage(									  \
					FTD_TID_RspQry##x##Topic,							  \
					FTDC_CHAIN_CONTINUE,								  \
					FTD_VERSION);										  \
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());		  \
			CFTDRspQry##x##Field field;									  \
			CopySys##x##Entity(&field, pfield);							  \
			FTDC_ADD_FIELD(&m_pkgSend, &field);							  \
			pSession->SendRequestPackage(&m_pkgSend);					  \
			pfield = pMemoryDB->m_Sys##x##Factory->findNextByAll();		  \
		}																  \
																   \
		pMemoryDB->m_Sys##x##Factory->endFindByAll();					  \
		m_pkgSend.PreparePackage(										  \
				FTD_TID_RspQry##x##Topic,								  \
				FTDC_CHAIN_LAST,										  \
				FTD_VERSION);											  \
		m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());			  \
		CFTDRspInfoField rspInfoField;									  \
		memset(&rspInfoField, 0, sizeof(rspInfoField));					  \
		rspInfoField.ErrorID = 0;										  \
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);						  \
		pSession->SendRequestPackage(&m_pkgSend);						  \
	}

///用于主机ENV查询应答的宏
#define RSPQRYENV(x)																  \
	{																				  \
		m_pkgSend.PrepareResponse(													  \
				pPackage,															  \
				FTD_TID_RspQryHostEnvTopic,											  \
				FTDC_CHAIN_CONTINUE,												  \
				FTD_VERSION);														  \
		CRspQryHostEnv##x *pfield##x = pMemoryDB->m_RspQryHostEnv##x##Factory->		  \
			startFindByHostName(ftdQryField.HostName);								  \
		CTimeType Time##x;															  \
		if (pfield##x)																  \
		{																			  \
			Time##x = pfield##x->MonTime;											  \
		}																			  \
		while (pfield##x)															  \
		{																			  \
			if (pfield##x->MonTime != Time##x)										  \
			{																		  \
				break;																  \
			}																		  \
																		   \
			CFTDRspQryHostEnv##x##Field field;										  \
			CopyRspQryHostEnv##x##Entity(&field, pfield##x);						  \
			FTDC_ADD_FIELD(&m_pkgSend, &field);										  \
			pfield##x = pMemoryDB->m_RspQryHostEnv##x##Factory->findNextByHostName(); \
		}																			  \
																			   \
		pMemoryDB->m_RspQryHostEnv##x##Factory->endFindByHostName();				  \
		pSession->SendRequestPackage(&m_pkgSend);									  \
	}

#define SYSMANAGERREQ(x)													  \
	{																		  \
		CFTDReqQry##x##Field qryfield;										  \
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)			  \
		{																	  \
			return 0;														  \
		}																	  \
																	   \
		TRID rid;															  \
		rid.SessionID = pSession->GetSessionID();							  \
		rid.RequestId = pFTDCPackage->GetRequestId();						  \
		int nRid = m_Rid++;													  \
		m_vRid[nRid] = rid;													  \
		CFTDReqQry##x##Field field;											  \
		CopyReqQry##x##Entity(&field, &qryfield);							  \
		m_pkgSend.PreparePackage(											  \
				FTD_TID_ReqQry##x##Topic,									  \
				FTDC_CHAIN_LAST,											  \
				FTD_VERSION);												  \
		FTDC_ADD_FIELD(&m_pkgSend, &field);									  \
		m_pkgSend.SetRequestId(nRid);										  \
		if (m_pQueryAgent->GetQuerySession())								  \
		{																	  \
			m_pQueryAgent->GetQuerySession()->SendRequestPackage(&m_pkgSend); \
		}																	  \
		else																  \
		{																	  \
			m_pkgSend.PreparePackage(										  \
					FTD_TID_RspQry##x##Topic,								  \
					FTDC_CHAIN_LAST,										  \
					FTD_VERSION);											  \
			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());			  \
			CFTDRspInfoField rspInfoField;									  \
			memset(&rspInfoField, 0, sizeof(rspInfoField));					  \
			rspInfoField.ErrorID = ERR_QRYACCWRONG;							  \
			rspInfoField.ErrorMsg = "QueryConnectError";					  \
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);						  \
			pSession->SendRequestPackage(&m_pkgSend);						  \
		}																	  \
	}

#define SYNCFGREQ(x)															\
	{																			\
		CFTDReqQry##x##Field qryfield;											\
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)				\
		{																		\
			return 0;															\
		}																		\
																		 \
		TRID rid;																\
		rid.SessionID = pSession->GetSessionID();								\
		rid.RequestId = pFTDCPackage->GetRequestId();							\
		int nRid = m_Rid++;														\
		m_vRid[nRid] = rid;														\
		CFTDReqQry##x##Field field;												\
		CopyReqQry##x##Entity(&field, &qryfield);								\
		m_pkgSend.PreparePackage(												\
				FTD_TID_ReqQry##x##Topic,										\
				FTDC_CHAIN_LAST,												\
				FTD_VERSION);													\
		FTDC_ADD_FIELD(&m_pkgSend, &field);										\
		m_pkgSend.SetRequestId(nRid);											\
		if (m_pSynConnector->GetQuerySession())									\
		{																		\
			m_pSynConnector->GetQuerySession()->SendRequestPackage(&m_pkgSend); \
		}																		\
	}

#define CopyTSysObjectAttrEntity(target, source)						  \
		(target)->ObjectID = g_StringIdMap.getString((source)->ObjectID); \
	(target)->AttrType = g_StringIdMap.getString((source)->AttrType);	  \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->ValueType = (source)->ValueType;							  \
	(target)->AttrValue = (source)->AttrValue;

#define CopyTSysTopCpuInfoEntity(target, source)						  \
		(target)->HostName = g_StringIdMap.getString((source)->HostName); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->CPU = (source)->CPU;										  \
	(target)->LOAD = (source)->LOAD;									  \
	(target)->USER = (source)->USER;									  \
	(target)->NICE = (source)->NICE;									  \
	(target)->SYS = (source)->SYS;										  \
	(target)->IDLE = (source)->IDLE;									  \
	(target)->BLOCK = (source)->BLOCK;									  \
	(target)->SWAIT = (source)->SWAIT;									  \
	(target)->INTR = (source)->INTR;									  \
	(target)->SSYS = (source)->SSYS;

#define CopyTSysTopMemInfoEntity(target, source)						  \
		(target)->HostName = g_StringIdMap.getString((source)->HostName); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->TOTALREAL = (source)->TOTALREAL;							  \
	(target)->ACTIVEREAL = (source)->ACTIVEREAL;						  \
	(target)->TOTALVIRTUAL = (source)->TOTALVIRTUAL;					  \
	(target)->ACTIVEVIRTUAL = (source)->ACTIVEVIRTUAL;					  \
	(target)->FREE = (source)->FREE;

#define CopyTSysTopProcessInfoEntity(target, source)					  \
		(target)->HostName = g_StringIdMap.getString((source)->HostName); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->CPU = (source)->CPU;										  \
	(target)->TTY = (source)->TTY;										  \
	(target)->PID = (source)->PID;										  \
	(target)->USERNAME = (source)->USERNAME;							  \
	(target)->PRI = (source)->PRI;										  \
	(target)->NI = (source)->NI;										  \
	(target)->SIZE = (source)->SIZE;									  \
	(target)->RES = (source)->RES;										  \
	(target)->STATE = (source)->STATE;									  \
	(target)->TIME = (source)->TIME;									  \
	(target)->pWCPU = (source)->pWCPU;									  \
	(target)->pCPU = (source)->pCPU;									  \
	(target)->COMMAND = (source)->COMMAND;

#define CopyTSysFileSystemInfoEntity(target, source)					  \
		(target)->HostName = g_StringIdMap.getString((source)->HostName); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->FILESYSTEM = (source)->FILESYSTEM;						  \
	(target)->SIZE = (source)->SIZE;									  \
	(target)->USED = (source)->USED;									  \
	(target)->AVAIL = (source)->AVAIL;									  \
	(target)->pUSERD = (source)->pUSERD;								  \
	(target)->ISIZE = (source)->ISIZE;									  \
	(target)->IUSED = (source)->IUSED;									  \
	(target)->IFREE = (source)->IFREE;									  \
	(target)->pIUSED = (source)->pIUSED;								  \
	(target)->MountedOn = (source)->MountedOn;

#define CopyTSysNetworkInfoEntity(target, source)						  \
		(target)->HostName = g_StringIdMap.getString((source)->HostName); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->LANNAME = (source)->LANNAME;								  \
	(target)->LANSTATUS = (source)->LANSTATUS;							  \
	(target)->IPADDRESS = (source)->IPADDRESS;							  \
	(target)->SENDPACKETS = (source)->SENDPACKETS;						  \
	(target)->SENDBYTES = (source)->SENDBYTES;							  \
	(target)->SENDDROPPACKETS = (source)->SENDDROPPACKETS;				  \
	(target)->SENDERRORPACKETS = (source)->SENDERRORPACKETS;			  \
	(target)->RECVPACKETS = (source)->RECVPACKETS;						  \
	(target)->RECVBYTES = (source)->RECVBYTES;							  \
	(target)->RECVDROPPACKETS = (source)->RECVDROPPACKETS;				  \
	(target)->RECVERRORPACKETS = (source)->RECVERRORPACKETS;

#define CopyTSysWebAppInfoEntity(target, source)						  \
		(target)->ObjectID = g_StringIdMap.getString((source)->ObjectID); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->AppName = (source)->AppName;								  \
	(target)->Status = (source)->Status;								  \
	(target)->Desc = (source)->Desc;									  \
	(target)->StartTime = (source)->StartTime;							  \
	(target)->ServletNum = (source)->ServletNum;						  \
	(target)->ProcessTime = (source)->ProcessTime;						  \
	(target)->RequestNum = (source)->RequestNum;						  \
	(target)->ErrorNum = (source)->ErrorNum;							  \
	(target)->SessionSize = (source)->SessionSize;						  \
	(target)->TimeOut = (source)->TimeOut;								  \
	(target)->JDBCUsage = (source)->JDBCUsage;							  \
	(target)->JSPNum = (source)->JSPNum;

#define CopyTSysMemPoolInfoEntity(target, source)						  \
		(target)->ObjectID = g_StringIdMap.getString((source)->ObjectID); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->PoolName = (source)->PoolName;							  \
	(target)->Usage = (source)->Usage;									  \
	(target)->committedbytes = (source)->committedbytes;				  \
	(target)->initbytes = (source)->initbytes;							  \
	(target)->maxbytes = (source)->maxbytes;							  \
	(target)->usedbytes = (source)->usedbytes;							  \
	(target)->Type = (source)->Type;

#define CopyTSysConnectorInfoEntity(target, source)						  \
		(target)->ObjectID = g_StringIdMap.getString((source)->ObjectID); \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->Name = (source)->Name;									  \
	(target)->ThreadsCount = (source)->ThreadsCount;					  \
	(target)->BusyThreadsCount = (source)->BusyThreadsCount;			  \
	(target)->MaxThreads = (source)->MaxThreads;						  \
	(target)->MaxSpareThreads = (source)->MaxSpareThreads;				  \
	(target)->MinSpareThreads = (source)->MinSpareThreads;				  \
	(target)->MaxTime = (source)->MaxTime;								  \
	(target)->MaxProcTime = (source)->MaxProcTime;						  \
	(target)->RequestCount = (source)->RequestCount;					  \
	(target)->ErrorCount = (source)->ErrorCount;						  \
	(target)->BytesReceived = (source)->BytesReceived;					  \
	(target)->BytesSent = (source)->BytesSent;

#define CopyTSysDBQueryEntity(target, source)							  \
		(target)->ObjectID = g_StringIdMap.getString((source)->ObjectID); \
	(target)->AttrType = g_StringIdMap.getString((source)->AttrType);	  \
	(target)->MonDate = (source)->MonDate;								  \
	(target)->MonTime = (source)->MonTime;								  \
	(target)->DBQueryResult = (source)->DBQueryResult;

#define CopyTSysDiskIOEntity(target, source)	   \
	(target)->HostName = (source)->HostName;	   \
	(target)->MonDate = (source)->MonDate;		   \
	(target)->MonTime = (source)->MonTime;		   \
	(target)->PartName = (source)->PartName;	   \
	(target)->ReadMerges = (source)->ReadMerges;   \
	(target)->WriteMerges = (source)->WriteMerges; \
	(target)->ReadIOs = (source)->ReadIOs;		   \
	(target)->WriteIOs = (source)->WriteIOs;	   \
	(target)->ReadKBs = (source)->ReadKBs;		   \
	(target)->WriteKBs = (source)->WriteKBs;	   \
	(target)->SizeVal = (source)->SizeVal;		   \
	(target)->QueueVal = (source)->QueueVal;	   \
	(target)->Svc_t = (source)->Svc_t;			   \
	(target)->Busy = (source)->Busy;

#define CopyTSysRouterInfoEntity(target, source)   \
	(target)->HostName = (source)->HostName;	   \
	(target)->MonDate = (source)->MonDate;		   \
	(target)->MonTime = (source)->MonTime;		   \
	(target)->Dev = (source)->Dev;				   \
	(target)->Destination = (source)->Destination; \
	(target)->Gateway = (source)->Gateway;		   \
	(target)->Mask = (source)->Mask;			   \
	(target)->Flag = (source)->Flag;			   \
	(target)->RefCnt = (source)->RefCnt;		   \
	(target)->Use = (source)->Use;				   \
	(target)->Metric = (source)->Metric;		   \
	(target)->Mtu = (source)->Mtu;				   \
	(target)->Win = (source)->Win;				   \
	(target)->Rtt = (source)->Rtt;

#define CopyTSysStatInfoEntity(target, source) \
	(target)->HostName = (source)->HostName;   \
	(target)->MonDate = (source)->MonDate;	   \
	(target)->MonTime = (source)->MonTime;	   \
	(target)->ProcRun = (source)->ProcRun;	   \
	(target)->ProcBlk = (source)->ProcBlk;	   \
	(target)->SwapIn = (source)->SwapIn;	   \
	(target)->SwapOut = (source)->SwapOut;	   \
	(target)->BlockIn = (source)->BlockIn;	   \
	(target)->BlockOut = (source)->BlockOut;   \
	(target)->Inter = (source)->Inter;		   \
	(target)->Context = (source)->Context;	   \
	(target)->CPUUser = (source)->CPUUser;	   \
	(target)->CPUSys = (source)->CPUSys;	   \
	(target)->CPUIdle = (source)->CPUIdle;	   \
	(target)->CPUIOWait = (source)->CPUIOWait; \
	(target)->CPUSteal = (source)->CPUSteal;

#define CopyTSysTradeFrontOrderRttStatEntity(target, source) \
		(target)->ObjectID = (source)->ObjectID;			 \
	(target)->MonDate = (source)->MonDate;					 \
	(target)->MonTime = (source)->MonTime;					 \
	(target)->OrderCount = (source)->OrderCount;			 \
	(target)->OrderRttSum = (source)->OrderRttSum;			 \
	(target)->OrderMaxRtt = (source)->OrderMaxRtt;			 \
	(target)->OrderMinRtt = (source)->OrderMinRtt;			 \
	(target)->OrderRttSqu = (source)->OrderRttSqu;			 \
	(target)->OrderRttCutDistrib = (source)->OrderRttCutDistrib;

#define RTNSUBCRIBER(x)													   \
	{																	   \
		list<CFTDRtn##x##Field> lFtd;									   \
		list<CFTDRtn##x##Field>::iterator it;							   \
		int icount = 0;													   \
		if (ftdQryField.ObjectNum < 0)									   \
		{																   \
			CSysMdb##x	*sfield = pMemoryDB->m_SysMdb##x##Factory->		   \
				startFindByDsc(objectid);								   \
			while (sfield)												   \
			{															   \
				{														   \
					if (sfield->MonDate < ftdQryField.MonDate			   \
					||	(												   \
							sfield->MonDate == ftdQryField.MonDate		   \
					&&	sfield->MonTime < ftdQryField.MonTime			   \
					))													   \
					{													   \
						break;											   \
					}													   \
				}														   \
															\
				m_pkgSend.SetRequestId(pPackage->GetRequestId());		   \
				CFTDRtn##x##Field tfield;								   \
				CopyTSys##x##Entity(&tfield, sfield);					   \
				lFtd.push_front(tfield);								   \
				sfield = pMemoryDB->m_SysMdb##x##Factory->findNextByDsc(); \
			}															   \
																\
			pMemoryDB->m_SysMdb##x##Factory->endFindByDsc();			   \
			for (it = lFtd.begin(); it != lFtd.end(); it++)				   \
			{															   \
				m_pkgSend.PreparePackage(								   \
						FTD_TID_Rtn##x##Topic,							   \
						FTDC_CHAIN_CONTINUE,							   \
						FTD_VERSION);									   \
				FTDC_ADD_FIELD(&m_pkgSend, &(*it));						   \
				pSession->SendRequestPackage(&m_pkgSend);				   \
			}															   \
		}																   \
		else if (ftdQryField.ObjectNum == 0)							   \
		{																   \
			return;														   \
		}																   \
		else															   \
		{																   \
			CSysMdb##x	*sfield = pMemoryDB->m_SysMdb##x##Factory->		   \
				startFindByDsc(objectid);								   \
			while (sfield)												   \
			{															   \
				if (icount >= ftdQryField.ObjectNum)					   \
				{														   \
					break;												   \
				}														   \
															\
				m_pkgSend.SetRequestId(pPackage->GetRequestId());		   \
				CFTDRtn##x##Field tfield;								   \
				CopyTSys##x##Entity(&tfield, sfield);					   \
				lFtd.push_front(tfield);								   \
				sfield = pMemoryDB->m_SysMdb##x##Factory->findNextByDsc(); \
				icount++;												   \
			}															   \
																\
			pMemoryDB->m_SysMdb##x##Factory->endFindByDsc();			   \
			for (it = lFtd.begin(); it != lFtd.end(); it++)				   \
			{															   \
				m_pkgSend.PreparePackage(								   \
						FTD_TID_Rtn##x##Topic,							   \
						FTDC_CHAIN_CONTINUE,							   \
						FTD_VERSION);									   \
				FTDC_ADD_FIELD(&m_pkgSend, &(*it));						   \
				pSession->SendRequestPackage(&m_pkgSend);				   \
			}															   \
		}																   \
	}

#endif	// REF_FRONTSERVER_H END
