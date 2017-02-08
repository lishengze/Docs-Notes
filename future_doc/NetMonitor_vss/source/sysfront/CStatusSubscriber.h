/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CStatusSubscriber.h
///@brief	�����˶����¼�������Ϣ����
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_CSTATUSSUBSCRIBER_H
#define REF_CSTATUSSUBSCRIBER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CListSession.h"
#include "databaseData.h"
#include "UFCopy.h"

extern CMemoryDB *pMemoryDB;
extern CStringIdMap g_StringIdMap;

class CStatusSubscriber :
	public CFTDCSubscriber
{
	/* */
	public:
		///���캯��	
		CStatusSubscriber(int nFlowSeq);

		///��������
		~ CStatusSubscriber(void);

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

		///�������������
		bool Truncate(int nFlowSeq)
		{
			if (nFlowSeq != m_nFlowSeq)
			{
				printf(
					"Ҫ���������� %d �뱾�����ߵ������ %d ����ͬ \n",
					nFlowSeq,
					m_nFlowSeq);
				fflush(stdout);
				return false;
			}

			return m_pFlow->Truncate(0);
		}

	/* */
	private:
		///����ҵ�����״̬������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage);

		///����ҵ�����״̬������
			///@param	pMessage	�������յ��İ���ַ
		//void OnRtnNetObjectAttrTopic(CFTDCPackage *pFTDCPackage);
		
			///����ҵ�����״̬������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage);

		///���������û���Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnUserInfoTopic(CFTDCPackage *pFTDCPackage);

		///���������û���Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnOnlineUserInfoTopic(CFTDCPackage *pFTDCPackage);

		///���ĸ澯�¼���Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage);

		///��������CPU��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage);

		///����Local Ping��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnLocalPingResultTopic(CFTDCPackage *pFTDCPackage);

		///����Remote Ping��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnRemotePingResultTopic(CFTDCPackage *pFTDCPackage);

		///���������ڴ���Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage);

		///��������������Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnTopProcessInfoTopic(CFTDCPackage *pFTDCPackage);

		///������������IO��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnDiskIOInfoTopic(CFTDCPackage *pFTDCPackage);

		///����·����Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnRouteInfoTopic(CFTDCPackage *pFTDCPackage);

		///����ϵͳ��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnStatInfoTopic(CFTDCPackage *pFTDCPackage);

		///���������ļ�ϵͳ��Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnFileSystemInfoTopic(CFTDCPackage *pFTDCPackage);

		///��������ʹ����Ϣ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnWebAppInfoTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnMemPoolInfoTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnConnectorInfoTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnDbQueryTopic(CFTDCPackage *pFTDCPackage);
		void OnRtnWarningQueryTopic(CFTDCPackage *pFTDCPackage);

		///����������Ϣ����Ӧ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRspQryHostEnvTopic(CFTDCPackage *pFTDCPackage);

		///������Ϣ��������Ӧ������
			///@param	pMessage	�������յ��İ���ַ
		void OnRtnUpdateSysConfigTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnSyslogEventTopic(CFTDCPackage *pFTDCPackage);

		///�л��澯��Ч״̬�Ķ��Ĵ�����
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRtnWarningActiveChange(CFTDCPackage *pFTDCPackage);

		///�����豸����״̬������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRtnNetDeviceLinkTopic(CFTDCPackage *pFTDCPackage);

		///�����豸����״̬������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pFTDCPackage);

		void OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pFTDCPackage);

		//��Ӧ�����ض�������Ϣ(�������нṹ)
		void OnRtnNetAreaTopic(CFTDCPackage *pFTDCPackage);

	/* */
	public:
		///���½������ݵ����ڴ����ݿ�
		void ReLoad(void);
		void OnRtnTradeUserLoginInfo(CFTDCPackage *pFTDCPackage);
		///�������ݰ�������ַ
		CCachedFileFlow *m_pFlow;

		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///�������ض���־λ
		bool m_reload;

		///�������ı��
		int m_nFlowSeq;
};

///����reload���̶���״̬�ĺ�
#define RELOADEVENTPACKAGE(x)												 \
	{																		 \
		CFTDRtn##x##Field fieldInfo;										 \
		CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(		 \
				&CFTDRtn##x##Field::m_Describe);							 \
		while (!itor.IsEnd())												 \
		{																	 \
			itor.Retrieve(&fieldInfo);										 \
			CWriteableSysMdb##x mdbfield;									 \
			mdbfield.ObjectID = g_StringIdMap.getStringId(					 \
					fieldInfo.ObjectID.getValue());							 \
			mdbfield.AttrType = g_StringIdMap.getStringId(					 \
					fieldInfo.AttrType.getValue());							 \
			mdbfield.MonTime = fieldInfo.MonTime;							 \
			mdbfield.ValueType = fieldInfo.ValueType;						 \
			mdbfield.AttrValue = fieldInfo.AttrValue;						 \
			pMemoryDB->m_SysMdb##x##Factory->add(&mdbfield, NULL);			 \
			itor.Next();													 \
			if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd()) \
			{																 \
				break;														 \
			}																 \
		}																	 \
	}

///���ڴ���������������RSP��Ϣ�ĺ�
#define ADDENVPACKAGETOMDB(x)															   \
	{																					   \
		CWriteableRspQryHostEnv##x	mdbfield;											   \
		CopyRspQryHostEnv##x##Entity(													   \
			&mdbfield,																	   \
			&field##x##Info) pMemoryDB->m_RspQryHostEnv##x##Factory->add(&mdbfield, NULL); \
	}

#endif // REF_CSTATUSSUBSCRIBER_H
