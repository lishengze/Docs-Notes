/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSlogServer.h
///@brief	������ǰ�ü�����ؿͻ�������ʹ�õ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20140528 ʷսΰ      �޶�ע��
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
///CQueryTimmer������ǰ�ö������������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CQueryTimmer :
	public CEventHandler
{
	/* */
	public:
		///���캯��
		CQueryTimmer(CReactor *pReactor, CSlogServer *pQuery);

		/** ���ö�ʱ������
	* @param	nIDEvent	��ʱ���������¼�ID
	* @param	nElapse	��ʱ����ʱ��������λms
	*/
		void SetTimer(int nIDEvent, int nElapse);

		/** ��ʱ��������
	* @param	nIDEvent	�ö�ʱ����ID
	*/
		virtual void OnTimer(int nIDEvent);

	/* */
	private:
		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///���涨ʱ�����¼�ID
		int m_nEventId;

		CSlogServer *m_pQueryServer;
};

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory�����˲ɼ�����̽��Ự������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentSessionFactory :
	public CSessionFactory
{
	/* */
	public:

		///���캯��
		CAgentSessionFactory(CReactor *pReactor, int nMaxSession) :
		CSessionFactory(pReactor, nMaxSession)
		{
		}

		///ע�����Ӻ���
			///@param	location	���ӵĵ�ַ
		void RegisterConnecter(char *location)
		{
			CSessionFactory::RegisterConnecter(location);
			memset(m_location, 0, MAXLOCATIONLEN);
			strcpy(m_location, location);
		}

		///ȡ���ӵ�ַ����
			///@return	�������ӵ�ַ��ָ��
		char *GetLocationName(void)
		{
			return m_location;
		}

	/* */
	private:
		///����ע������ӵ�ַ
		char m_location[MAXLOCATIONLEN];
};

/////////////////////////////////////////////////////////////////////////
///CFrontServer������ǰ�õļ�ؿͻ������Ӵ�����
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CSlogServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
		CSlogServer(CReactor *pReactor);

		///��������
		~ CSlogServer(void);

		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		void NotifyAllSession(CFTDCPackage *pkg);

		//��ʱ���slog��rtt�Ƿ���������Ҫ�Ƹ�ǰ��
		void CheckTradeFrontRtt(void);

	/* */
	protected:
		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///Slog��־��ѯ
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTradeLog(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�������Slog��־��ѯ
		    ///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		    ///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryLatestTradeLog(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��ʷ����״̬��ѯ
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryHistoryObjectAttr(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///ǰ����Ӧ������ѯ
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryFrontInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�û�ע��
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
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


	///��VC 6.0 ��������ʹ�û��������
		///template<class INFIELD, class OUTFIELD>
		///void  query(const DWORD TID, const string &tableName, CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///��ʱ������
		CQueryTimmer m_eventTimer;

	//20080715 add wy.yb
	private:

	/* */
	private:
		list<CFTDCSession *> m_frontSessions;
		static CQWordMonitorIndex* m_pRtt2FrontByteMonitor;
};
#endif // REF_SLOGSERVER_H
