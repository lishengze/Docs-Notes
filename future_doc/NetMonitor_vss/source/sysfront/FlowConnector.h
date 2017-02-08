/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	FlowConnector.h
///@brief	���������ӽ�����ˮ����������������÷�����ͨ����Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_FLOWCONNECTOR_H
#define REF_FLOWCONNECTOR_H

#include "FrontServer.h"

// �����¼�������������ӵ���

//
class CFlowConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CFlowConnector(CReactor *pReactor);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		CFTDCSession *GetFlowSession(void)
		{
			return m_pFlowSession;
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

		///�û���¼Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///Ĭ������Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnDefaultProcess(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		//���׷�ֵ����Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryTradepeak(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///��FIBCLIENT���ӳɹ��ı�־λ
		bool m_Flag;

		CFrontServer *m_pFrontServer;

		CFTDCSession *m_pFlowSession;
};

#define FLOWRSP(x)																							\
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

#endif // REF_FLOWCONNECTOR_H end
