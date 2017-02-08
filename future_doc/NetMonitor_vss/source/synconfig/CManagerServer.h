/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CManagerServer.h
///@brief	�����˼���snmp��������Ӵ������
///@history
///20110618	��־ΰ		�������ļ�
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

///CManagerServer�����˽���SNMP��������Ӵ�����࣬�����������snmp����˵�����
class CManagerServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CManagerServer(CReactor *pReactor);

		bool Init(void);

		///֪ͨ�������ӵ��ϵ�snmp�����
		    ///@param	pkg	Ҫ���͵����ݰ�
		void NotifyAllSessions(CFTDCPackage *pkg)
		{
			m_sessionMgr.NotifyAllSessions(pkg);
		}

		///ָ֪ͨ�����ĵ�SNMP�����
		    ///@param	reqPkg	Ҫ���͵����ݰ�
		    ///@param	dc �������ı�ʶ
		void NotifySessions(CFTDCPackage *pkg, CDataCenterFlagType dc)
		{
			//m_sessionMgr.NotifySessions(pkg, dc);
		}

		void NotifySessions(char dataCenter, CFTDCPackage *pkg)
		{
			m_sessionMgr.NotifySessions(dataCenter, pkg);
		}

		///Ϊ����Session�ṩ��snmp����˷�������ķ���
		    ///@param	pkg	Ҫ���͵����ݰ�
		    ///@param	datacenter	�������snmpManger��������������
		bool RequestSnmp(CFTDCPackage *pkg, char datacenter)
		{
			return m_sessionMgr.RequestSnmp(pkg, datacenter);
		}

	/* */
	private:
		///�½��Ựʱ���õĴ�����
		    ///@param	pChannel	�Ự������ͨ����ַ
		    ///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
		    ///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
		    ///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///�û���¼��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
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
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///���ݿ�handler
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

			// ��������£�SessionSet�ĵ�һ���ڵ�Ӧ��ΪMaster Session����Ϣ��
			// ����ᴥ��TT_WAIT_MASTER��ʱ������֤�����Լ��������
			typedef std::list<SessionInfo>	SessionSet;

			class SessionTimmer;

			// SessionDataΪһ�����ĵ�������Ϣ����
			struct SessionData
			{
				SessionSet m_sessionSet;	// ���������������ϵ�Session��Ϣ
				SessionInfo *m_losedMaster; // ������ʧȥ���ӵ���Session��Ϣ
				SessionTimmer *m_timer;		// �ö���������Session�Ķ�ʱ��
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

			///snmp����˵���������������������
			SessionMap m_sessions;

			// ���̷߳���m_sessionsʱ�Ļ�����
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

				char m_dc;					// timmer��������������
				SessionMgr *m_mgr;			// a reference, don't delete it.
			};

			friend class SessionTimmer;
		};

		SessionMgr m_sessionMgr;
};
#endif // REF_CMANAGERSERVER_H
