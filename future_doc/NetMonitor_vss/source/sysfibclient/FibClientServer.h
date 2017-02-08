/////////////////////////////////////////////////////////////////////////
///@system ���׼��ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file FibClientServer.h
///@brief	����������ǰ�û��Ự���ӷ�����
///@history
///20080624	����		�������ļ�
///20080624	����		�޶�ע��
#ifndef SYS_FIBCLIENTSERVER_H
#define SYS_FIBCLIENTSERVER_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FTDCSubscriber.h"
#include "XTPPackage.h"
#include "FibProxyData.h"
#include "FileFlow.h"
#include "CConfig.h"
#include "CachedFileFlow.h"
#include "XtpPackageDesc.h"
#include "FtdPackageDesc.h"

extern CCachedFlow	*m_TRFlow;
extern string g_mainDataCenter;

/////////////////////////////////////////////////////////////////////////
///CFibClientServer����������ǰ�û��Ự���ӷ�����
///@author	����
///@version	1.0,20080624
/////////////////////////////////////////////////////////////////////////
class CFibClientServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:

		///���캯��
			///@param	pReactor	������CReactor����
		CFibClientServer(CReactor *pReactor) :
		CSessionFactory(pReactor, 100)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

			m_pkgSend.PreparePackage(
					FTD_TID_RtnDataCenterChgTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRtnDataCenterChgField tfield;
			memset(&tfield, 0, sizeof(tfield));
			strcpy(
				(char *)(tfield.DataCenterID.getValue()),
				g_mainDataCenter.data());
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		///�������Ӻ���
			///@param	pChannel		������CChannel����
			///@param	bIsListener		�Ƿ���������
			///@return	�����õ�CSession����ָ��
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark)
		{
			CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
			pSession->RegisterPackageHandler(this);

			/// Added by Henchi, 20120309
			pSession->SetCompressMethod(CRPCM_ZERO);	//����ѹ���㷨
			return pSession;
		}

		///�����ӽ���ʱ������
			///@param	pSession	���Ӷ�Ӧ��ָ��
			///@return	�޷���ֵ
		virtual void OnSessionConnected(CSession *pSession);

		///�����ӶϿ�ʱ����	
			///@param	pSession	���Ӷ�Ӧ��ָ��
			///@param	nReason		���ӶϿ���ԭ��
			///@return	�޷���ֵ
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///��������
			///@param	pFTDCPackage	���յ���FTD��
			///@param	pSession		�հ�����������
			///@return	���ذ���������Ϣ
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		//֪ͨfront����
		void NotifyFrontNewTradeDay(string strOldDay, string strNewDay);

	/* */
	private:
		///ǰ�û���¼����Ӧ����
			///@param	pFTDCPackage	���յ���FTD��
			///@param	pSession		�հ�����������	
			///@return	�޷���ֵ
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	/* */
	private:
		///һ�γ�ʼ������ʹ�õ�FTD��
		CFTDCPackage m_pkgSend;
};
#endif
