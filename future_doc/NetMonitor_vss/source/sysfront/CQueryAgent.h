/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CQueryAgent.h
///@brief	�����˲�ѯ�������
///@history
///20080810	����		�������ļ�
///20080810	����		�޶�ע��
#ifndef REF_QUERYAGENT_H
#define REF_QUERYAGENT_H

#include "public.h"
#include "CachedFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"

class CFrontServer;
class CQueryAgent :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		CQueryAgent(CReactor *pReactor);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		CFTDCSession *GetQuerySession(void)
		{
			return m_pQuerySession;
		}

		void SetFrontServer(CFrontServer *pFrontServer)
		{
			m_pFrontServer = pFrontServer;
		}

	/* */
	protected:
		/**�Ự���ӶϿ�ʱ�Ĵ�����
	* @param	pSession	�Ͽ������ӻỰָ��
	* @param	nReasion	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///��Ը澯�¼���ѯ���صĴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryWarningEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�����ʷ����״̬���Բ�ѯ���صĴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryHistoryObjectAttrTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///���NGESǰ�û�״̬��ѯ���صĴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryFrontInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///���SysMonitor��¼���صĴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQrySysUserLoginTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///���SysMonitor�ǳ����صĴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQrySysUserLogoutTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�ڲ����������ڳɹ���¼��Կͻ��˽��г�ʼ��
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnClientInit(CFTDCSession *pSession);

		///���SysQuery��SysFrontͬ��SysMonitor�����û���Ϣ�Ĵ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRtnSysUser(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void OnRtnHistoryTradePeakTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQrySyslogEventTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///����������������ѯ���صĴ�����
		///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
		///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryPerformanceTopTopic(
			CFTDCPackage *pFTDCPackage,
			CFTDCSession *pSession);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///��¼�ɹ���־
		bool m_bLoginFlag;

		///ǰ�û��Բ�ѯ��������SESSION
		CFTDCSession *m_pQuerySession;

		///ǰ�û��Կͻ��˵�SESSION
		CFrontServer *m_pFrontServer;
};

///���ڴ���������SYSQUERY��RSP���ĵĺ�
#define QUERYRSP(x)																							\
	{																										\
		int nRid = pFTDCPackage->GetRequestId();															\
		map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);									\
		TRID rid = it->second;																				\
		m_pkgSend.PreparePackage(																			\
				FTD_TID_RspQry##x##Topic,																	\
				FTDC_CHAIN_LAST,																			\
				FTD_VERSION);																				\
		m_pkgSend.SetChain(pFTDCPackage->GetChain());														\
		m_pkgSend.SetRequestId(rid.RequestId);																\
		CFTDRspInfoField rspInfoField;																		\
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)											\
		{																									\
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);														\
		}																									\
																									 \
		CFTDRspQry##x##Field sfield;																		\
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(										\
				&CFTDRspQry##x##Field::m_Describe);															\
		while (!itor.IsEnd())																				\
		{																									\
			itor.Retrieve(&sfield);																			\
			CFTDRspQry##x##Field tfield;																	\
			CopyRspQry##x##Entity(&tfield, &sfield);														\
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);															\
			itor.Next();																					\
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())								\
			{																								\
				break;																						\
			}																								\
		}																									\
																									 \
		if (m_pFrontServer->GetSession(rid.SessionID))														\
		{																									\
			((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(&m_pkgSend); \
		}																									\
																									 \
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)													\
		{																									\
			m_pFrontServer->m_vRid.erase(it);																\
		}																									\
	}

///���ڴ���������SYSQUERY�Ĺ���ϵͳ�����ĵĺ�
#define SYSMANAGERRSP																						  \
	{																										  \
		int nRid = pFTDCPackage->GetRequestId();															  \
		map<int, TRID>::iterator it = m_pFrontServer->m_vRid.find(nRid);									  \
		TRID rid = it->second;																				  \
		if (m_pFrontServer->GetSession(rid.SessionID))														  \
		{																									  \
			pFTDCPackage->SetRequestId(rid.RequestId);														  \
			((CFTDCSession *) (m_pFrontServer->GetSession(rid.SessionID)))->SendRequestPackage(pFTDCPackage); \
		}																									  \
																									   \
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)													  \
		{																									  \
			m_pFrontServer->m_vRid.erase(it);																  \
		}																									  \
	}

#endif
