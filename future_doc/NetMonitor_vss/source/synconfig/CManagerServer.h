/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CManagerServer.h
///@brief	定义了监听snmp管理端连接处理的类
///@history
///20110618	李志伟		创建该文件
#ifndef REF_CMANAGERSERVER_H
#define REF_CMANAGERSERVER_H

#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include <CDeployConfig.h>
#include <FTDDataWrapper.h>
#include <DBOperator.h>
#include <vector>
#include <PrjCommon.h>
#include <SyncEvent.h>

struct eventNod
{
	int eventId;
	int eventNum;
	int iTime;
	string	strDate;
	CTypeProcessFlagType processFlag;
};

///CManagerServer定义了接受SNMP管理端连接处理的类，并负责管理多个snmp管理端的连接
class CManagerServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数	
			///@param	pReactor	CReactor对象指针
		CManagerServer(CReactor *pReactor);

		bool Init(void);

		///通知所有连接的上的snmp管理端
		    ///@param	pkg	要发送的数据包
		void NotifyAllSessions(CFTDCPackage *pkg)
		{
			m_sessionMgr.NotifyAllSessions(pkg);
		}

		///通知指定中心的SNMP管理端
		    ///@param	reqPkg	要发送的数据包
		    ///@param	dc 数据中心标识
		void NotifySessions(CFTDCPackage *pkg, CDataCenterFlagType dc)
		{
			//m_sessionMgr.NotifySessions(pkg, dc);
		}

		void NotifySessions(char dataCenter, CFTDCPackage *pkg)
		{
			m_sessionMgr.NotifySessions(dataCenter, pkg);
		}

		///为其它Session提供向snmp管理端发送请求的服务
		    ///@param	pkg	要发送的数据包
		    ///@param	datacenter	被请求的snmpManger所属的数据中心
		bool RequestSnmp(CFTDCPackage *pkg, char datacenter)
		{
			return m_sessionMgr.RequestSnmp(pkg, datacenter);
		}

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
		void OnReqSnmpLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void OnRspQryNetDeviceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQryNetDeviceLinkedTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQryNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQryNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQryNetDeviceDetectTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQryNetMonitorTaskInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorTaskInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnNetMonitorTaskResultTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;

		///数据库handler
		SyncDBOperator	m_dbHandler;

		class SessionMgr
		{
		public:
			SessionMgr(CReactor * pReactor);

			~SessionMgr()
			{
			}

			void AddSession(
					char datacenter,
					const string &id,
					CFTDCSession *session);
			void RemoveSession(CFTDCSession *session);

			void NotifyAllSessions(CFTDCPackage *pkg);
			void NotifySessions(char dataCenter, CFTDCPackage *pkg);
			void NotifySessions(CFTDCPackage *pkg, CDataCenterFlagType dc);
			bool RequestSnmp(CFTDCPackage *pkg, char datacenter);
		private:
			typedef CDeployConfig::ServerType ServerType;

			struct SessionInfo
			{
				char m_dc;
				string	m_id;
				ServerType	m_serverType;
				CFTDCSession *m_session;

				SessionInfo
					(
						char datacenter, const string &id, CFTDCSession *session,
							ServerType st = CDeployConfig::ST_Invalid
					)
				:
				m_dc(datacenter),
				m_id(id),
				m_serverType(st),
				m_session(session)
				{
				}
			};

			// 正常情况下，SessionSet的第一个节点应该为Master Session的信息，
			// 否则会触发TT_WAIT_MASTER定时器来保证上面的约束条件。
			typedef std::list<SessionInfo>	SessionSet;

			class SessionTimmer;

			// SessionData为一个中心的连接信息数据
			struct SessionData
			{
				SessionSet m_sessionSet;	// 该中心所有连接上的Session信息
				SessionInfo *m_losedMaster; // 该中心失去连接的主Session信息
				SessionTimmer *m_timer;		// 裁定该中心主Session的定时器
				SessionData()
				:
				m_losedMaster(NULL),
				m_timer(NULL)
				{
				}

				~SessionData()
				{
					if (m_losedMaster)
					{
						delete m_losedMaster;
					}

					if (m_timer)
					{
						delete m_timer;
					}
				}
			};

			typedef std::map<char, SessionData> SessionMap;

			///snmp管理端的连接容器，管理多个连接
			SessionMap m_sessions;

			// 多线程访问m_sessions时的互斥锁
			CMutex m_lock;

			enum TimmerType
			{
				TT_WAIT_MASTER,
				TT_CHECK_MASTER,
			};

			class SessionTimmer : public CEventHandler
			{
			public:
				SessionTimmer(CReactor * pReactor, char datacenter, SessionMgr * mgr)
				:
				CEventHandler(pReactor),
				m_started(false),
				m_dc(datacenter),
				m_mgr(mgr)
				{
				}

				~SessionTimmer()
				{
				}

				void SetTimer(int nIDEvent, int nElapse);

				void KillTimer(int nIDEvent);

				bool Idle(void)
				{
					return !m_started;
				}

			private:
				void OnTimer(int nIDEvent);

				bool selectMaster(void);
				bool checkMaster(void);
				void cleanUnknow(void);

				bool losedMasterBack(SessionData &data);
				bool hasDefaultMaster(SessionData &data);
				bool theFirstSession(SessionData &data);

				void notifyMasterSession(SessionData &data);
				void synDataToNewMasterSession(SessionData &data);

				bool m_started;

				char m_dc;					// timmer所属的数据中心
				SessionMgr *m_mgr;			// a reference, don't delete it.
			};

			friend class SessionTimmer;
		};

		SessionMgr m_sessionMgr;
};
#endif // REF_CMANAGERSERVER_H
