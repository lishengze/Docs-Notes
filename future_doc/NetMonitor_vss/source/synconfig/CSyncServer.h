/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file CSyncServer.h
///@brief 配置服务同步数据Session
///@history
///20110926	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef __CSYNC_SERVER_H
#define __CSYNC_SERVER_H

#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "ConfigInfo.h"
#include <DBOperator.h>
#include <vector>
#include <PrjCommon.h>
#include <CachedFileFlow.h>

class FlowSync;

class CSyncServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		CSyncServer(CReactor *pReactor);

		~ CSyncServer(void);

		bool Init(void);

		/// 注册监听地址。让从配置服务通过该地址连接主配置服务。
		    /// 当前配置服务须为主配置服务，否则无效。当前主配置服务将更改信息同步给从配置服务。
		void RegisterListener(const char *location)
		{
			if (!isMaster())
			{
				assert(true && "current synconfig should be master!");
				LOG_ERROR("current synconfig should be master!");
				return;
			}

			CSessionFactory::RegisterListener(location);
		}

		/// 注册连接主配置服务地址，只支持一个主配置服务。
		    /// 当前配置服务须为从配置服务，否则无效。当前从配置服务等待主配置服务推送的更改信息。
		void RegisterMaster(const char *location)
		{
			if (isMaster())
			{
				assert(true && "current synconfig should be slavery!");
				LOG_ERROR("current synconfig should be slavery!");
				return;
			}

			CSessionFactory::RegisterConnecter(location);
		}

		///通知所有连接的上的从配置服务
		    ///@param	pkg	要发送的数据包
		void NotifyAllSessions(CFTDCPackage *pkg);

	/* */
	private:
		// 定时器标识符
		enum
		{
			SYNC_TIMMER = 1,
		};

		// 用于同步流的定时器
		class Timmer : public CEventHandler
		{
		public:
			Timmer(CReactor * pReactor, CSyncServer * srv)
			:
			CEventHandler(pReactor),
			m_syncServer(srv)
			{
			}

			void SetTimer(int nIDEvent, int nElapse)
			{
				CEventHandler::SetTimer(nIDEvent, nElapse);
			}

			void KillTimer(int nIDEvent)
			{
				CEventHandler::KillTimer(nIDEvent);
			}

		private:
			void OnTimer(int nIDEvent);

			CSyncServer *m_syncServer;	// a reference, don't delete it
		};

		friend class Timmer;
		friend class FlowSync;

		void syncFlow(void);

		///新建会话时调用的处理函数
		    ///@param	pChannel	会话所属的通道地址
		    ///@param	bIsListener	会话是否是监听服务器类型
		    ///@return	返回创建的新会话
		CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
		    ///@param	pSession	连接成功的会话指针
		void OnSessionConnected(CSession *pSession);

		/**会话连接断开时的处理函数
	* @param	pSession	断开的连接会话指针
	* @param	nReasion	断开的原因
	*/
		void OnSessionDisconnected(CSession *pSession, int nReason);

		/// 判断当前配置服务是否为主配置服务
		    ///@return	如果为主配置服务，返回true；如果为从配置服务，返回false
		bool isMaster(void)
		{
			return ConfigInfo::Instance().isMaster();
		}

		void OnReqQryFileGeneralOperTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnRtnNetSubAreaIPTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetEventLevelTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetGatherTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorAttrTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetBaseLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorCommandTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorDeviceTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorActionAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorActionGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetTimePolicyTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetOuterDeviceInfTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
				
		void OnRtnMemberLinkCostTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetGeneralOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorAttrScopeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetCommunityTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetSubEventTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetPartyLinkInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetBaseLineTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorTaskInstAttrsTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetDeviceTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetDDNLinkInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetDeviceLinkedTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetRomotePingResultInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetFuncAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetPseudMemberLinkInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMemberSDHLineInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetManufactoryTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorDeviceGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetEventExprTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetDeviceCategoryTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetSubAreaTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetEventTypeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetOIDTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorTaskInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetLocalPingResultInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);
		void OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void OnRtnNetPartylinkMonthlyRentTopic(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);
		///请求应答包处理函数
			///@param	pFTDCPackage	需要处理的FTDC包地址
			///@param	pSession	数据包所属的FTD会话指针
			///@return	返回数据包的处理结果
		int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		typedef std::vector<CFTDCSession *> SessionSet;

		///连接的配置服务Session
		SessionSet m_sessions;

		// 多线程访问m_sessions时的互斥锁
		CMutex m_lock;

		///数据库handler
		SyncDBOperator m_dbHandler;

		// 用于同步流的定时器
		Timmer *m_timmer;

		// 流文件同步者
		FlowSync *m_flowSync;

		string strAddFileName;
};

class FlowSync :
	public CFTDCSubscriber
{
	/* */
	public:
		FlowSync(CSyncServer *syncServer) :
		m_syncServer(syncServer),
		m_flow(NULL)
		{
		}

		~ FlowSync(void);

		bool setupSyncFlow(void);

		bool addToFlow(CFTDCPackage *pFTDCPackage);

		void OnReqFlowSyncTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///设置通讯阶段号函数
		    ///@param	wCommPhaseNo	需要设置的通信阶段号
		void SetCommPhaseNo(WORD wCommPhaseNo);

		///获取流序列号函数
		    ///@return	返回流的当前序列号
		WORD GetSequenceSeries(void);	//流编号
		
		    ///获取收到流中包含的包总数函数
		    ///@return	返回当前订阅收到的包总数
		DWORD GetReceivedCount(void);	//收到的包个数
		
		    ///订阅收到的包处理函数,是发布/订阅模型收到的数据包
		    ///@param	pMessage	订阅者收到的包地址
		void HandleMessage(CFTDCPackage *pMessage);

	/* */
	private:
		CSyncServer *m_syncServer;	// a reference, don't to release it.

		// 流文件
		CCachedFileFlow *m_flow;
};
#endif // __CSYNC_SERVER_H
