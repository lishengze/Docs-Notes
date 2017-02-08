/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	FrontServer.h
///@brief	������ǰ�ü�����ؿͻ�������ʹ�õ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
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
extern CLogger	*g_pClnPackOutput;	// ���ݰ�������ļ�
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
	///�����¼��Ķ���IDָ��
	CTypeObjectIDType ObjectID;

	///�¼���
	CTypeObjectIDType EventName;

	///���漶��
	CTypeWarningLevelType WarningLevel;

	///��������
	CTypeSubcriberObjectIDType	filter;

	///������
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

/*
typedef struct
{
	DWORD	SessionID;
	DWORD	RequestId;
}TRID;
*/

/////////////////////////////////////////////////////////////////////////
///CFrontServer������ǰ�õļ�ؿͻ������Ӵ�����
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CFrontServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CFrontServer(
			CReactor *pReactor,
			CQueryAgent *pQueryAgent,
	        CSlogAgent *pSlogAgent,
			CCountConnector *pCountConnector,
			CSynConnector *pSynConnector,
			CFlowConnector	*pFlowConnector);

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

	/* */
	protected:
		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///��̨�ڲ���¼��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryClientLogin(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///HandlePackage��Ĭ�ϴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnDefaultProcess(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///��̨�ڲ���¼��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqUserLogin(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///ǰ̨�û�������������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnQryUserMgr(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///ǰ̨�û�Ȩ����������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void QryUserFunc(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///ǰ̨�û���¼��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryClientLoginTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ǰ̨LocalPing��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryLocalPingTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ǰ̨RemotePing��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryRemotePingTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///CPU��Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTopCpuInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�ڴ���Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTopMemInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTopProcessInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�ļ�ϵͳ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryFileSystemInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryNetworkInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryDiskIOTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ϵͳ��Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryStatInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///·����Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryRouterInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ϵͳ��Դ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQrySystemResourceAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�ڴ����ݿ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryMemoryDBAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///���׺�����Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryKernelAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///����ϵͳǰ����Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryFrontAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///TINIT��Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTinitAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�Ŷӻ���Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryCompositorAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///����ϵͳ����������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryHostEnvTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ȡ���м�ض�����������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryMonitorObjectTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����ϵ��Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryObjectRationalTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///����������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryDataCenterTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///������ָ���ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryObjectAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ϵͳ��־��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQrySyslogInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ϵͳ�û���Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryUserInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///ϵͳ�����û���Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryOnlineUserInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�澯�¼���ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryWarningEventTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///��ʷ��ض���ָ����Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryHistoryObjectAttrTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///����ϵͳǰ����Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryFrontInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///������־��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTradeLogTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///��Ա��Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryParticipantInitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�澯ʱ������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryWarningEventUpdateTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///��־�¼������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQrySyslogEventUpdateTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����û���¼��Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTradeUserLoginInfoTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///��Ա������Ϣ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnPartTradeTopic(CFTDCPackage *pPackage, CFTDCSession *pSession);

		///���׷�ֵ��ѯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTradepeakTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///���ϵͳ��¼��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQrySysUserLoginTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///���ϵͳ�ǳ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQrySysUserLogoutTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///����ϵͳ�ͻ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnClientInit(CFTDCSession *pSession);

		///��Ա�޲���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryPartPosiLimitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�ͻ��޲���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryClientPosiLimitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����Ա�޲���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQrySpecialPosiLimitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///����ϵͳ��ϯ��������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryUserInitTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����ļ��ָ��������
			///@param	pPackeage	��������ݰ���ַ
			///@param	pSession	����ĻỰ
		void OnReqQrySubcriberTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����ѯ��ض�������м��ָ��������
			///@param	pPackeage	��������ݰ���ַ
			///@param	pSession	����ĻỰ
		void OnReqQryOidRelationTopic(
				CFTDCPackage *pPackage,
				CFTDCSession *pSession);

		///�����ѯ���ϵͳ���������û���������
			///@param	pPackeage	��������ݰ���ַ
			///@param	pSession	����ĻỰ
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

		///�����ѯ�������������������
		///@param	pPackeage	��������ݰ���ַ
		///@param	pSession	����ĻỰ
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
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		CQueryAgent *m_pQueryAgent;
		CSlogAgent *m_pSlogAgent;
		CCountConnector *m_pCountConnector;
		CSynConnector *m_pSynConnector;
		CFlowConnector	*m_pFlowConnector;

		map<string, map<string, CFTDRspQrySyslogEventField> > m_mapIPSyslogDetail;

	/* */
	public:
		///���²����͵�����RID�б�
		map<int, TRID>	m_vRid;
		int m_Rid;
		DWORD m_dwLocaPingReqID;
		void OnSysUserLoginTopic(
				CUserIDType UserID,
				int rID,
				CFTDCSession *pSession);
};

///������Ӷ����ϵ�ĺ�
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
	fieldRspInfo.ErrorMsg = "����";						   \
	fieldRspInfo.ErrorID = 1;							   \
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo)

///���ڹ���ƽ̨�����ڴ����ݿ��ѯ�ĺ�:
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

///���ڹ���ƽ̨�����ڴ����ݿ��ѯ�ĺ�:
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

///���ڹ���ƽ̨INIT���ֲ�ѯ�ĺ꣺
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

///��������ENV��ѯӦ��ĺ�
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
