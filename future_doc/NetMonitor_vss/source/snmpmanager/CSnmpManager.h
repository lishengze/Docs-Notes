/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CSnmpManager.h
///@brief	������SnmpManagerʹ�õ���
///@history
///20100920	�ܽ���		�������ļ�
#ifndef REF_CSNMPMANAGER_H
#define REF_CSNMPMANAGER_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CAsyncGetThread.h"
#include "CSynConnector.h"
#include "CTaskManager.h"
#include "CConnTaskThread.h"

/////////////////////////////////////////////////////////////////////////
///CProbeTimmer�����˹�������ʱ����
///@author	�ܽ���
///@version	1.0,20100920
/////////////////////////////////////////////////////////////////////////
class CManagerTimmer :
	public CEventHandler
{
	/* */
	public:
		///���캯��
		CManagerTimmer(CReactor *pReactor);

		/** ���ö�ʱ������
	* @param	nIDEvent	��ʱ���������¼�ID
	* @param	nElapse	��ʱ����ʱ��������λms	
	*/
		void SetTimer(int nIDEvent, int nElapse)
		{
			m_nEventId = nIDEvent;
			CEventHandler::SetTimer(nIDEvent, nElapse);
		}

		/** ��ʱ��������
	* @param	nIDEvent	�ö�ʱ����ID
	*/
		virtual void OnTimer(int nIDEvent);

		/** ȡ�¼�ID����
	* @param	pFTDCPackage	�յ���FTD���ݰ���ַ
	* @param	pSession	�����ݰ������ĻỰID
	* @return	�����¼���ID
	*/
		int GetEventId(void)
		{
			return m_nEventId;
		}

		/************************************************************************/
		/* �����߳������ַ���̸߳�������                                       */

		/************************************************************************/
		void setThreadPoint(CAyncGetThread **pThread, int nThreadNum)
		{
			m_nThreadNum = nThreadNum;
			m_pThread = pThread;
		}

		void setConnTaskPoint(CConnTaskThread **pThread, int nThreadNum)
		{
			m_nConnTaskThreadNum = nThreadNum;
			m_pConnTaskThread = pThread;
		}

		void setFlowPoint(CCachedFileFlow **pFlowArray)
		{
			m_pFlowArray = pFlowArray;
			m_pCurrFlow = m_pFlowArray[0];
			m_nFlowPosition = 0;
			m_nLastChangeTime = time((time_t *)NULL);
		}

		void setSessionMapPoint(
		CHashMap<DWORD, CSession *, HashInt> *pSessionMap)
		{
			m_pSessionMap = pSessionMap;
		}

		void setCSynConnectorPoint(CSynConnector *pThread)
		{
			m_pcSyn = pThread;
		}

		void setTaskManagerThreadPoint(CTaskManagerThread *pThread)
		{
			m_pTaskManagerThread = pThread;
		}

	/* */
	private:
		///���е�ǰServer��session
		CHashMap<DWORD, CSession *, HashInt> *m_pSessionMap;

		///��ʱ��ʹ�õ����ݰ�������
		CFTDCPackage m_pkgSend;

		///���涨ʱ�����¼�ID
		int m_nEventId;

		///�߳�����ָ��
		CAyncGetThread	**m_pThread;

		///�߳���������
		int m_nThreadNum;

		///CConnTaskThreadָ������
		CConnTaskThread **m_pConnTaskThread;

		///CConnTaskThread��������
		int m_nConnTaskThreadNum;

		///������ָ��
		CCachedFileFlow **m_pFlowArray;

		///��ǰ����д�������
		CCachedFileFlow *m_pCurrFlow;

		///�ϴ��л�����ʱ��
		time_t	m_nLastChangeTime;

		///synconnector����ʵ��ָ��
		CSynConnector *m_pcSyn;

		///TaskManagerThreadָ��
		CTaskManagerThread	*m_pTaskManagerThread;

		//// ȡcdp�߳�ָ��
		//CGetDeviceInfoThread *m_pcdpThread;
			///�ϴ��л�������ָ���������е�λ��
		int m_nFlowPosition;
};

/////////////////////////////////////////////////////////////////////////
///CSnmpManagerServer������snmp�������������������
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CSnmpManagerServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��
			///@param	pReactor
			///@param	nThreadNum	�����̸߳���
			///@param	pMibPath	mib�ļ�·��
			///@param	pFlowPath	���ļ��洢·��
			///@param	nStartId	�����������
			///@param	pLocation	���Ӵ�
		CSnmpManagerServer(
			CReactor *pconfReactor,
			int nThreadNum,
			const char	*pMibPath,
			const char	*pFlowPath,
			int nStartId,
			const char	*pLocation);
		~CSnmpManagerServer(void)
		{
			delete[] m_pThread;
			delete[] m_pConnTaskThread;
			delete m_pTaskManagerThread;
		}

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

	/* */
	protected:
		/** �Ự���ӶϿ�������
	* @param	pSession	�Ͽ��Ự��ID
	* @param	nReason	�Ͽ���ԭ��
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	public:
		///�û���¼Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///ע�����˿ں���
			///@param	pSynConfigLocation	����snmp���ӵ�synconfig��������˿�
		void RegisterSynConnecter(const char *pSynConfigLocation)
		{
			m_cSynConnector.RegisterConnecter(pSynConfigLocation);
		}

		///�������з���˿ں���
		void StartAll(void)
		{
			Start();
			m_cSynConnector.Start();
		}

		void LoadDataFile(const char *filename = NULL);

		CSynConnector &GetConnectorObject(void)
		{
			return m_cSynConnector;
		}

	/* */
	private:
		///synconnector����ʵ��
		CSynConnector m_cSynConnector;

		///������Ϣ�������ݰ�������
		CFTDCPackage m_pkgSend;

		///��ʱ��
		CManagerTimmer	m_timer;

		///������snmp�ɼ��߳���
		int m_nThreadNum;

		///������Telnet�ɼ��߳���
		int m_nTelnetThreadNum;

		///�������߳�ָ��
		CAyncGetThread	*m_pThread[MAX_THREAD_NUM];

		///������ConnTaskThreadָ��
		CConnTaskThread *m_pConnTaskThread[MAX_THREAD_NUM];

		///��������߳�ָ��
		CTaskManagerThread	*m_pTaskManagerThread;

		///�ҽӵ��������ݷ�����
		CCachedFileFlow *m_pFlowArray[MAX_EVENTFLOWNUM];

		//ȡcpd�߳�
		//CGetDeviceInfoThread *m_pcdpThread;
		
			///�����������
		int m_nStartId;

		///ͨ�����Ӵ�
		char *m_pLocation;
};
#endif //REF_SNMPMANAGER_H
