#pragma once
#include "public.h"
#include "Thread.h"
#include "DatabaseSpiImpl.h"
#include "SyslogSpiImpl.h"

class CDBSpiThread :
	public CThread
{
	/* */
	public:
		CDBSpiThread(void);
		~ CDBSpiThread(void);

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

	/* */
	public:
		// ��������������߳����ɵ����ݷ��ͳ�ȥ
		void GetSpi(void);

#if 0
		///���ڸ������ݿ�����map������
			///@param	sConfigName	���ݿ�ı���
			///@param	sConnectString	���ݿ�ĵ�ַ������Ϣ
		void UpdateDatabaseInfoMap(
				string	sConfigName,
				CDBConnectString sConnectString);

		///���ڸ���ָ��ɼ�map������������������ͳ�Ʊ��С
			///@param	pAttrName	���ݿ�ָ������
			///@param	pSeps	ָ�����ʱ���Ƶ��
			///@param	pDNSName	���ݿ�ı���
			///@param	pTableName	���ݿ�ı�����
		void UpdateDBAttrMap(
				const char	*pAttrName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pTableName);

		///���ڸ������ݿ���ô洢���̶�����
			///@param	pSPName	SP����
			///@param	pSeps	��ȡSP��ʱ�估Ƶ����Ϣ
			///@param	pDNSName	���ݿ������Ϣ
			///@param	pSPType	SP�ķ���ֵ����
		void UpdateSPInfoMap(
				const char	*pSPName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pSPType);

		///���ڸ������ݿ��ȡ��־�������
			///@param	pTableName	��־������
			///@param	pSeps	��ȡ��־���ʱ�估Ƶ����Ϣ
			///@param	pDNSName	���ݿ������Ϣ
			///@param	pPosition	���ݿ���Ѿ���ȡ����ƫ������Ϣ
		void UpdateDBLogMap(
				const char	*pTableName,
				const char	*pSeps,
				const char	*pDNSName,
				const char	*pPosition);
#endif

		///���ڸ������ݿ���ʱ��ѯ���������
			///@param	pObjectId	�������ݿ�����ID
			///@param	pAttrType	�������ݿ��ѯ��SP����
			///@param	dRequestId	�����RequestId���
			///@param	pSession	������������ftd Session
		void UpdateSPQuery(
				const char	*pObjectId,
				const char	*pAttrType,
				const DWORD dRequestId,
				const CFTDCSession	*pSession);
		void UpdateConfig(CFTDRspQryHostConfigField *hostConfig);

	/* */
	private:
		// �����Ƿ��˳�
		bool m_bExit;

		// �����Ƿ���й����� ��������ʱ������
		int m_iWork;

		///FTD���ݰ����ͻ�����
		CFTDCPackage m_pkgSend;

		///���ݿ�ȡָ��spi
		CDatabaseSpiImpl *pDatabaseSpi;
};
