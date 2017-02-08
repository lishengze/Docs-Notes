/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CSyncServer.h
///@brief ���÷���ͬ������Session
///@history
///20110926	��־ΰ   �������ļ�
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

		/// ע�������ַ���ô����÷���ͨ���õ�ַ���������÷���
		    /// ��ǰ���÷�����Ϊ�����÷��񣬷�����Ч����ǰ�����÷��񽫸�����Ϣͬ���������÷���
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

		/// ע�����������÷����ַ��ֻ֧��һ�������÷���
		    /// ��ǰ���÷�����Ϊ�����÷��񣬷�����Ч����ǰ�����÷���ȴ������÷������͵ĸ�����Ϣ��
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

		///֪ͨ�������ӵ��ϵĴ����÷���
		    ///@param	pkg	Ҫ���͵����ݰ�
		void NotifyAllSessions(CFTDCPackage *pkg);

	/* */
	private:
		// ��ʱ����ʶ��
		enum
		{
			SYNC_TIMMER = 1,
		};

		// ����ͬ�����Ķ�ʱ��
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

		///�½��Ựʱ���õĴ�����
		    ///@param	pChannel	�Ự������ͨ����ַ
		    ///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
		    ///@return	���ش������»Ự
		CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
		    ///@param	pSession	���ӳɹ��ĻỰָ��
		void OnSessionConnected(CSession *pSession);

		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		void OnSessionDisconnected(CSession *pSession, int nReason);

		/// �жϵ�ǰ���÷����Ƿ�Ϊ�����÷���
		    ///@return	���Ϊ�����÷��񣬷���true�����Ϊ�����÷��񣬷���false
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
		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		typedef std::vector<CFTDCSession *> SessionSet;

		///���ӵ����÷���Session
		SessionSet m_sessions;

		// ���̷߳���m_sessionsʱ�Ļ�����
		CMutex m_lock;

		///���ݿ�handler
		SyncDBOperator m_dbHandler;

		// ����ͬ�����Ķ�ʱ��
		Timmer *m_timmer;

		// ���ļ�ͬ����
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

		///����ͨѶ�׶κź���
		    ///@param	wCommPhaseNo	��Ҫ���õ�ͨ�Ž׶κ�
		void SetCommPhaseNo(WORD wCommPhaseNo);

		///��ȡ�����кź���
		    ///@return	�������ĵ�ǰ���к�
		WORD GetSequenceSeries(void);	//�����
		
		    ///��ȡ�յ����а����İ���������
		    ///@return	���ص�ǰ�����յ��İ�����
		DWORD GetReceivedCount(void);	//�յ��İ�����
		
		    ///�����յ��İ�������,�Ƿ���/����ģ���յ������ݰ�
		    ///@param	pMessage	�������յ��İ���ַ
		void HandleMessage(CFTDCPackage *pMessage);

	/* */
	private:
		CSyncServer *m_syncServer;	// a reference, don't to release it.

		// ���ļ�
		CCachedFileFlow *m_flow;
};
#endif // __CSYNC_SERVER_H
