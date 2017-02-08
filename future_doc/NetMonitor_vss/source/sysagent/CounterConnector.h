/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CounterConnector.h
///@brief	�����˲ɼ��������Ӳ�����̽����Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_COUNTECONNECTOR_H
#define REF_COUNTECONNECTOR_H

#include "AgentConnector.h"

/////////////////////////////////////////////////////////////////////////
///CCounterTimmer�����˲ɼ����������������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CCounterTimmer :
	public CEventHandler
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
		CCounterTimmer(CReactor *pReactor, CEventProcess *pEventProcess);

		///��ʱ��������
			///@param	nIDEvent	�¼���ID��
		virtual void OnTimer(int nIDEvent);

	/* */
	private:
		///���ڷ������ݰ��Ļ�����
		CFTDCPackage m_pkgSend;

		///���¼�����ʹ�ö���ָ��
		CEventProcess *m_pEventProcess;
};

/////////////////////////////////////////////////////////////////////////
///CCounterConnector�����˲ɼ����������¼�����Ự������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CCounterConnector :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
			///@param	pEventProcess	�¼��������ָ�룬�ö�������ȴ���
		CCounterConnector(CReactor *pReactor, CEventProcess *pEventProcess);

		///�Ự����ʱ���õĴ�����
			///@param	pChannel	�����»Ự��ͨ��ָ��
			///@param	bIsListener	�Ự�Ƿ��Ǽ��������������ı��
			///@return	�������ɵ��»Ựָ��
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///�Ự���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӵĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

	/* */
	protected:
		/**�Ự���ӶϿ�ʱ���õĴ�����
	* @param	pSession	�Ự���ӵ�ָ��
	* @param	nReasion	�Ự�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		/**FTDC���ݰ�������
	* @param	pFTDCPackage	��Ҫ�����FTDC���ݰ���ַ
	* @param	pSession	���ݰ�������FTD�Ựָ��
	* @return	���صĴ�����
	*/
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///Ӧ��̽���������ô�����
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRspQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�û��˳���������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnReqUserLogout(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�л���������������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		///����Ķ�ʱ������
		CCounterTimmer	m_myTimer;

		///���ڷ�����Ϣ�Ļ�����
		CFTDCPackage m_pkgSend;
};
#endif // REF_COUNTECONNECTOR_H END
