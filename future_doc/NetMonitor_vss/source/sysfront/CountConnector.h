/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CounterConnector.h
///@brief	�����������¼����������������÷�����ͨ����Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_COUNTERCONNECTOR_H
#define REF_COUNTERCONNECTOR_H

#include "FrontServer.h"

/////////////////////////////////////////////////////////////////////////
///CAgentSessionFactory�����������¼�������������ӵ���
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CCountConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
		CCountConnector(CReactor *pReactor);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		CFTDCSession *GetCountSession(void)
		{
			return m_pCountSession;
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

		///�л���������������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRspQryJDBCInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void ClearMemeryDatabase(void);

		void RemoveOneDayFromMDB(const char *strDay);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///ǰ�û��Կͻ��˵�SESSION
		CFrontServer *m_pFrontServer;

		CFTDCSession *m_pCountSession;

		///��ǰ�Ľ�����
		string	m_sCurTradeDay;
};

#define CLEARMEMDB(x)														 \
	{																		 \
		C##x *sfield = pMemoryDB->m_##x##Factory->startFindBytheAll();		 \
		while (sfield)														 \
		{																	 \
			C##x *tfield = pMemoryDB->m_##x##Factory->findNextBytheAll();	 \
			if (sfield->MonDate < beginDate									 \
			||	(sfield->MonDate == beginDate && sfield->MonTime < theTime)) \
			{																 \
				pMemoryDB->m_##x##Factory->remove(sfield);					 \
			}																 \
																  \
			sfield = tfield;												 \
		}																	 \
	}

#endif	// REF_COUNTERCONNECTOR_H END
