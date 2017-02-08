/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CFrontServer.h
///@brief	�����˼���ǰ�����Ӵ������
///@history
///20110112	�ܽ���		�������ļ�
#ifndef REF_FRONTSERVER_H
#define REF_FRONTSERVER_H

#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include <FTDDataWrapper.h>
#include <DBOperator.h>
#include <vector>
#include <PrjCommon.h>

struct taskStatus
{
	int times;	//����ִ�д���
	int status; // ����ִ��״̬ -1��ʾ�Ѿ�����������
	int delay;
};

/////////////////////////////////////////////////////////////////////////
///CManagerServer�����˽���SNMP��������Ӵ������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CFrontServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CFrontServer(CReactor *pReactor);

		~ CFrontServer(void);

		bool Init(void);

		///֪ͨ���е�ǰ������
		    ///@param	pkg	Ҫ���͵����ݰ�
		void NotifyAllSession(CFTDCPackage *pkg);

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
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///ͨ�ò�����������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryGeneralOperateTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///ʱ�������������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetTimePolicyTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�豸�ı���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetDeviceChgTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�豸̽����������
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetDeviceDetectTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�����豸��ѯ��������
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetDeviceRequestTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�����豸�˿ڲ�ѯ��������
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetInterfaceTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�����豸ģ���ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetModuleTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�����豸���ӹ�ϵ��ѯ��������
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetDeviceLinkedTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�ɼ�������������
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetGatherTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�豸��������������
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetMonitorDeviceGroupTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�ɼ�������������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetMonitorTaskInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�˳���������
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnSysServerExitTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�ɼ�����״̬��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetMonitorTaskStatusResultTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///ָ��ͳ����������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetMonitorAttrScopeTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQryFileGeneralOperTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQrySysUserLoginTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQryGetFileTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///���ߴ�����
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetBaseLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQryNetMonitorDeviceTaskTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		bool AddDeviceTaskItem2DB(
				CFTDCPackage *pFTDCPackage,
				CFTDReqQryNetMonitorDeviceTaskField &qryfield,
				int nTaskFlitID);

		bool RemoveDeviceTaskItem4DB(
				CFTDCPackage *pFTDCPackage,
				CFTDReqQryNetMonitorDeviceTaskField &qryfield,
				int nTaskFlitID);

		///��������
		    ///@param	session	�µ�Session����
		bool AddSession(CFTDCSession *session)
		{
			assert(session);

			m_sessions.push_back(session);
			return true;
		}

		///ɾ������
		    ///@param	session	ʧЧSession����
		bool DeleteSession(CFTDCSession *session)
		{
			assert(session);

			list<CFTDCSession *>::iterator	it = find(
					m_sessions.begin(),
					m_sessions.end(),
					session);
			if (it != m_sessions.end())
			{
				m_sessions.erase(it);
			}

			return true;
		}
		void OnReqQryEventDescriptionTopic( CFTDCPackage *pFTDCPackage, CFTDCSession *pSession );
	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///���ݿ�handler
		SyncDBOperator	m_dbHandler;

		///���ǰ�����ӵĹ�����
		list<CFTDCSession *> m_sessions;

		// ���̷߳���m_sessionsʱ�Ļ�����
		CMutex	m_lock;

		string	strAddFileName;

		int m_nDeviceTaskPrimID;
};
#endif // REF_FRONTSERVER_H
