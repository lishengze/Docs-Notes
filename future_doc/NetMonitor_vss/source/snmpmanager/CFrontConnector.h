/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CFrontConnector.h
///@brief	ʵ�������Ӽ��ǰ��ͨ����Ϣ����
///@history
///20110116	LSC		�������ļ�
#ifndef REF_CFRONTCONNECTOR_H
#define REF_CFRONTCONNECTOR_H

#include "public.h"
#include "CachedFlow.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CDate.h"
#include "systools.h"
#include "CAsyncGetDevices.h"
#include "CGetDeviceInfo.h"

#include <list>
#include <vector>
#include <map>
using namespace std;

// �����¼�������������ӵ���
//
#define uint32	unsigned long

class CFrontConnector :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///���캯��	
			///@param	pReactor	CReactor����ָ��
		CFrontConnector(CReactor *pReactor);

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

		///�û���¼Ӧ������
			///@param	pFTDCPackage	��Ҫ�����FTDC����ַ
			///@param	pSession	���ݰ�������FTD�Ựָ��
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	/* */
	private:
		///�������ݰ�ʹ�õĻ�����
		CFTDCPackage m_pkgSend;

		///������snmp�ɼ��߳���
		int m_nThreadNum;

		///��FIBCLIENT���ӳɹ��ı�־λ
		bool m_Flag;
};
#endif // REF_CFRONTCONNECTOR_H end
