/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	SnmpSubcriber.h
///@brief	�������¼��������������snmpmanager����
///@history
///20100910	�ܽ���		�������ļ�
#ifndef REF_SNMPSUBCRIBER_H
#define REF_SNMPSUBCRIBER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "databaseData.h"

class CEventCounterServer;
class CSnmpSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///���캯��	
			///@param	nFlowSeq	�����
			///@param	nManagerId	������������
		CSnmpSubscriber(
			int nFLowSeq,
			int nManagerId,
			CEventCounterServer *pEventCounterServer);

		///��������
		~ CSnmpSubscriber(void);

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
	public:
		void SetSession(CFTDCSession *pSession)
		{
			m_pSession = pSession;
		}

	/* */
	public:
		///�������ݰ�������ַ
		CCachedFileFlow *m_pFlow;

		///����CounterServer����ָ��
		CEventCounterServer *m_pEventCounterServer;

		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///�����
		int m_nFlowSeq;

		///������������
		int m_nManagerId;

		///�������������ĻỰ
		CFTDCSession *m_pSession;
};

class CResultSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:

		///���캯��	
		CResultSubscriber(void)
		{
			m_pFlow = new CCachedFileFlow(
					"fibResultFlow",
					"./flow/",
					true,
					100,
					32 * 1024);
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		}

		///��������
		~CResultSubscriber(void)
		{
			delete m_pFlow;
		}

		///����ͨѶ�׶κź���
			///@param	wCommPhaseNo	��Ҫ���õ�ͨ�Ž׶κ�
		virtual void SetCommPhaseNo(WORD wCommPhaseNo)
		{
		}

		///��ȡ�����кź���
			///@return	�������ĵ�ǰ���к�
		virtual WORD GetSequenceSeries(void)	//�����
		{
			return 1000;
		}

		///��ȡ�յ����а����İ���������
			///@return	���ص�ǰ�����յ��İ�����
		virtual DWORD GetReceivedCount(void)	//�յ��İ�����
		{
			return m_pFlow->GetCount();
		}

		///�����յ��İ�������,�Ƿ���/����ģ���յ������ݰ�
			///@param	pMessage	�������յ��İ���ַ
		virtual void HandleMessage(CFTDCPackage *pMessage)
		{
			printf(
				"\CResultSubscriber::HandlePackage:receive package %0x\n",
				pMessage->GetTID());
		}

	/* */
	private:
	/* */
	public:
		///�������ݰ�������ַ
		CCachedFileFlow *m_pFlow;

		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;
};
#endif
