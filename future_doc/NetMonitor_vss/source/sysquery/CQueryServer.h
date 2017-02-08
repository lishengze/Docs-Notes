/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	QueryServer.h
///@brief	������ǰ�ü�����ؿͻ�������ʹ�õ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
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
		CQueryTimmer(CReactor *pReactor, CQueryServer *pQuery);

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

		CQueryServer *m_pQueryServer;
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
class CQueryServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
		CQueryServer(CReactor *pReactor);

		///��������
		~ CQueryServer(void);

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

		///��ʷ�澯�¼���ѯ
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryWarningEvent(
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

		void OnReqQryHistoryCpuInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	///��ʷCpu״̬��ѯ
		void OnReqQryHistoryMemInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	///��ʷMem״̬��ѯ
		void OnReqQryHistoryNetworkInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	///��ʷ����״̬��ѯ
		void OnReqQryWebVisitInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ��վ����ͳ����Ϣ��ѯ
		void OnReqQryNetMonitorTaskResult(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ��ʷѲ������ѯ
		void OnReqQryNetPartyLinkStatusInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ��Ա״̬��ѯ
		void OnReqQryNetBaseLineResult(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ���߽����ѯ
		void OnReqQryTradeFrontOrderRttStat(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ǰ����Ӧʱ��
		void OnReqQryOrderRttCutLine(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ����ͳ���õ�����
		void OnReqQryNetLocalPingResult(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ����ping���
		void OnReqQryNetRomotePingResultInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// Զ��ping���
		void OnReqQryRouterInfoInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ϵͳ·��
		void OnReqQryDiskIOInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ����io
		void OnReqQryStatInfoInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ϵͳ״̬
		void OnReqQryTopProcessInfo(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);	/// ������Ϣ��ѯ
		void OnReqQryParticTradeOrderStates(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);
		void OnReqQryPerformanceTopTopic(	/// ��������TopN��ѯ
			CFTDCPackage *pFTDCPackage,
			CFTDCSession *pSession);

		void GetRow(
				SACommand *pCommand,
				char *buf,
				CFieldDescribe	*pFieldDescribe);

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
		///�������ݿ⣬����������ŵģ��Ͳ��ٽ�������
			///2009.1.5 chg by Solomon, ����ֵ��void ��Ϊbool
			///return:
			/// true ��������ȷ������
		bool connectDB(void);

		/// the database server connection status
			/// ����ʹ�õ�SQLAPI�汾û������������µİ汾��
		bool isAlive(SAConnection *conn) const;

		///����ȫ�ֱ���������ip:port/dbname���ַ���
		string	getConnectStr(
					const string &ip,
					const string &port,
					const string &dbName) const;

		/// ȡ�������û�����Ϣ
			/// return:
			///		0 - "db query finish"; ���ʳɹ����м�¼
			///		1 - "DB access exception";
			///		2 - ���ݿ���ʳɹ�������û�м�¼
		int getUserInfoList(list<CFTDRtnSysUserField *> &userList);

		/// ȡ�õ����û�����Ϣ
			/// return:
			///		0 - "db query finish"; ���ʳɹ����м�¼
			///		1 - "DB access exception";
			///		2 - ���ݿ���ʳɹ�������û�м�¼
		int getUserInfoSingle(
				CFTDRtnSysUserField &record,
				const string &userID);

		/// ȡ�õ����û�����Ϣ
			/// return:
			///		0 - "db query finish"; ���ʳɹ����м�¼
			///		1 - "DB access exception";
			///		2 - ���ݿ���ʳɹ�������û�м�¼
		int getUserInfoSingle(
				CFTDRtnSysUserField &record,
				const string &userID,
				const string &password);

	/* */
	private:
		///���ݿ�����Ӿ�� (����ʹ�õĲ���������sysquery.cpp����ʱ)
		SAConnection *m_sqlConnect;

		SyncDBOperator	m_hander;

		list<CFTDCSession *> m_frontSessions;
};
#endif // REF_QUERYSERVER_H END
