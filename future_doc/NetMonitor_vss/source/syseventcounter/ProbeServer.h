/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	ProbeServer.h
///@brief	������̽������ɼ���������ʹ�õ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_PROBESERVER_H
#define REF_PROBESERVER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"

/////////////////////////////////////////////////////////////////////////
///CProbeServer������̽�붨�����������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CProbeTimmer :
	public CEventHandler
{
	/* */
	public:
		///���캯��
		CProbeTimmer(CReactor *pReactor);

		/** ���ö�ʱ������
	* @param	nIDEvent	��ʱ���������¼�ID
	* @param	nElapse	��ʱ����ʱ��������λms	
	*/
		void SetTimer(int nIDEvent, int nElapse);

		/** ��ʱ��������
	* @param	nIDEvent	�ö�ʱ����ID
	*/
		virtual void OnTimer(int nIDEvent);

		/** ȡ�¼�ID����
	* @param	pFTDCPackage	�յ���FTD���ݰ���ַ
	* @param	pSession	�����ݰ������ĻỰID
	* @return	�����¼���ID
	*/
		int GetEventId(void);

	/* */
	private:
		///��ʱ��ʹ�õ����ݰ�������
		CFTDCPackage m_pkgSend;

		///���涨ʱ�����¼�ID
		int m_nEventId;
};

/////////////////////////////////////////////////////////////////////////
///CProbeServer������̽������ɼ������������������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CProbeServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
		CProbeServer(CReactor *pReactor);

		/** FTD������Ӧ������
	* @param	pFTDCPackage	�յ���FTD���ݰ���ַ
	* @param	pSession	�����ݰ������ĻỰID	
	*/
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		/** �Ự�������Ӵ�����
	* @param	pChannel	�������ӵ�ͨ��ָ��
	* @param	bIsListener	�Ƿ��Ǽ����߱�־,true��ʾ������,false��ʾ�������Ӷ�	
	*/
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///���ӳɹ�ʱ���õĴ�����
			///@param	pSession	���ӳɹ��ĻỰָ��
		virtual void OnSessionConnected(CSession *pSession);

		/** �������ݰ�����
	* @param	pFTDPackage	�������ݰ��ĵ�ַ
	*/
		void SendPackageAllSession(CFTDCPackage *pFTDCPackage)
		{
			CHashMap<DWORD, CSession *, HashInt>::iterator	itor = m_mapSession.
				Begin();
			while (!itor.IsEnd())
			{
				((CFTDCSession *) (*itor))->SendRequestPackage(pFTDCPackage);
				pFTDCPackage->Pop(FTDCHLEN);
				itor++;
			}
		}

	/* */
	protected:
		/** �Ự���ӶϿ�������
	* @param	pSession	�Ͽ��Ự��ID
	* @param	nReason	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///������Ϣ�������ݰ�������
		CFTDCPackage m_pkgSend;

		///��ʱ��
		//CProbeTimmer m_timer;
};
#endif // !defined(REF_PROBESERVER_H)
