/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CResultSubcriber.h
///@brief	�����˶��Ľ�����ˮ������Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_CRESULTSUBSCRIBER_H
#define REF_CRESULTSUBSCRIBER_H

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

extern CMemoryDB *pMemoryDB;
extern CStringIdMap g_StringIdMap;

class CResultSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///���캯��	
		CResultSubscriber(void);

		///��������
		~ CResultSubscriber(void);

		///����ͨѶ�׶κź���
			///@param	wCommPhaseNo	��Ҫ���õ�ͨ�Ž׶κ�
		virtual void SetCommPhaseNo(WORD wCommPhaseNo);

		///��ȡ�����кź���
			///@return	�������ĵ�ǰ���к�
		virtual WORD GetSequenceSeries(void);	//�����
		
			///��ȡ�յ����а����İ���������
			///@return	���ص�ǰ�����յ��İ�����
		virtual DWORD GetReceivedCount(void);	//�յ��İ�����
		
			///�����յ��İ�������,�Ƿ���/����ģ���յ������ݰ�
			///@param	pMessage	�������յ��İ���ַ
		virtual void HandleMessage(CFTDCPackage *pMessage);

		///���½������ݵ����ڴ����ݿ�
		void ReLoad(void);

		///�������ڴ����ݿ��뱾������������
		void UnLoad(void);

	/* */
	private:
		///���󱨵�������
			///@param	pMessage	��������ݰ���ַ
		//	void OnRtnInvalidateOrderTopic(CFTDCPackage *pMessage);
		
			///����״̬������
			///@param	pMessage	��������ݰ���ַ
		//	void OnRtnOrderStatusTopic(CFTDCPackage *pMessage);
		
			///�ɽ���������
			///@param	pMessage	��������ݰ���ַ
		//	void OnRtnBargainOrderTopic(CFTDCPackage *pFTDCPackage);
		
			///��Լ���Դ�����
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRtnInstPropertyTopic(CFTDCPackage *pFTDCPackage);

		///�����û���¼������
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRspQryTradeUserLoginInfo(CFTDCPackage *pFTDCPackage);

		///�����û��ǳ�������
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRtnTradeUserLoginInfo(CFTDCPackage *pFTDCPackage);

		///��Ա���״�����
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRspQryPartTrade(CFTDCPackage *pFTDCPackage);

		///��֤���ʱ䶯������
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRtnMarginRateChgTopic(CFTDCPackage *pFTDCPackage);

		///�ǵ�ͣ��䶯������
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRtnPriceLimitChgTopic(CFTDCPackage *pFTDCPackage);

		///��Ա�޲ֱ䶯������
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRtnPartPosiLimitChgTopic(CFTDCPackage *pFTDCPackage);

		///�ͻ��޲ֱ䶯������
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRtnClientPosiLimitChgTopic(CFTDCPackage *pFTDCPackage);

		///����ͻ��޲ֱ䶯������
			///@param	pFTDCPackage	��������ݰ���ַ
		void OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pFTDCPackage);

		void OnRspQryFrontStat(CFTDCPackage *pFTDCPackage);

		void OnRtnDataCenterChgTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnSysTimeSyncTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnClientInitTopic(CFTDCPackage *pFTDCPackage);
	/* */
	public:
		///�������ݰ�������ַ
		CCachedFileFlow *m_pFlow;

		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///�������ض���־λ
		bool m_reload;
};
#endif // REF_CRESULTSUBSCRIBER_H  END
