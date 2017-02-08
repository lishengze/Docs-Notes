/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSlogAgent.h
///@brief	�����˲�ѯ�������
///@history
///2014.5.30	feng.gc		�������ļ�

#ifndef REF_SLOGAGENT_H
#define REF_SLOGAGENT_H

#include "public.h"
#include "CachedFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"

class CFrontServer;
class CSlogAgent :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/*  �� SlogServer ���ӵĴ����� */
	public:
		CSlogAgent(CReactor *pReactor);

		///�½��Ựʱ���õĴ�����
			///@param	pChannel	�Ự������ͨ����ַ
			///@param	bIsListener	�Ự�Ƿ��Ǽ�������������
			///@return	���ش������»Ự
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		CFTDCSession *GetSlogSession(void)
		{
			return m_pSlogSession;
		}

		void SetFrontServer(CFrontServer *pFrontServer)
		{
			m_pFrontServer = pFrontServer;
		}

		const CFTDRtnTradeOrderRttCutLineField& getRtnCutLine()const;

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

		///���Slog�Ĵ���
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryTradeLogTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///���NGESǰ�û�״̬��ѯ���صĴ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspQryFrontInfoTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		void OnRtnTradeOrderRttCutLineTopic(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

		///ǰ�ñ�����Ӧ��Ϣ
		void OnRtnTradeFrontOrderRttStatTopic(
			CFTDCPackage *pFTDCPackage,
			CFTDCSession *pSession);

	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///��¼�ɹ���־
		bool m_bLoginFlag;

		///ǰ�û���Slog��������SESSION
		CFTDCSession *m_pSlogSession;

		///ǰ�û��Կͻ��˵�SESSION
		CFrontServer *m_pFrontServer;

		// ��FrontServer���ã�����ȫ�ֵı���
        CFTDRtnTradeOrderRttCutLineField m_rtnCutLine;

};

#endif
