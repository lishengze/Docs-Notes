/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	AgentServer.h
///@brief	�������¼���������������ɼ��������Ӵ������
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_AGENTSERVER_H
#define REF_AGENTSERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "AgentConnector.h"

/////////////////////////////////////////////////////////////////////////
///AgentServer�����˼����ɼ��������ӹ������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CAgentServer :
	public CAgentSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
			///@param	pReactor	CReactor����ָ��
			///@param	pSaveFile	�����������ļ���
		CAgentServer(CReactor *pReactor);

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
		///����Ӧ���������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
			///@return	�������ݰ��Ĵ�����
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		///Ӧ��̽���������ô�����
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRspQryHostConfig(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///�û���¼Ӧ������
			///@param	pFTDCPackage	FTDCpackage���ݰ���ַ
			///@param	pSession	���ݰ������ĻỰID
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

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
		///���ڷ������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///�����ӵı������� "ZJ-Agent06"
		string	m_sUpLinkName;

		///�����ӵ����Ӵ����� "tcp://172.18.38.61:18806"
		string	m_sUpLinkLocation;
};
#endif // REF_AGENTSERVER_H
