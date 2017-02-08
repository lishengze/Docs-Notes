/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CEventServer.h
///@brief	�����˼���eventcounter�����Ӵ������
///@history
///20110818	��־ΰ		�������ļ�
#ifndef REF_CEVENTSERVER_H
#define REF_CEVENTSERVER_H

#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CMsgGenerator.h"

#include <FTDDataWrapper.h>
#include <DBOperator.h>
#include <PrjCommon.h>

#define EVENT_MIN_CYCLE 5

class CEventServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CEventServer(CReactor *pReactor);

		bool Init(void)
		{
			return true;
		}

		bool Init(char *pszPath, char *pszMsgPolicy, char *pszSystemID)
		{
			m_MsgGenerator.Init(pszPath, pszMsgPolicy, pszSystemID);
			m_MsgGenerator.Create();
			return true;
		}

		void NotifyAllSessions(CFTDCPackage *reqPkg);

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

		void OnRtnWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnSyslogEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///������Ϣ�ļ��Ĺ��������
		CMsgGenerator m_MsgGenerator;

		friend class SessionProxy;

		typedef std::vector<CFTDCSession *> SessionSet;
		SessionSet m_sessions;

		// ���̷߳���m_sessionsʱ�Ļ�����
		CMutex m_lock;
};
#endif // REF_CEVENTSERVER_H
