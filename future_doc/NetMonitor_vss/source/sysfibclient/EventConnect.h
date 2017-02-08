#ifndef SYS_FIBCLIENTEVENTCONNECT_H
#define SYS_FIBCLIENTEVENTCONNECT_H

#include "public.h"
#include "Flow.h"
#include "FileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "FibClientServer.h"

struct MemberSeatData
{
	string str_date;
	string str_time;
	int    i_count;
};

/// ȫ�ַ���
/// ���¼��ػ�Ա��ֵ�����ļ�
void ReloadHistoryData();

class CEventConnect :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		CEventConnect(CReactor *pReactor);

		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		virtual void OnSessionConnected(CSession *pSession);

		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		void ChangeTradeDayOnFibNotify(string strOldDay, string strNewDay);

		void SendMemberPeak(void);

	/* */
	private:
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void OnReqQryTradeDayChange(
				CFTDCPackage *pFTDCPackage,
				CFTDCSession *pSession);

	/* */
	private:
		CFTDCPackage m_pkgSend;
};

class CIPAnalysis
{
	/* */
	public:
		///���캯��
			///@param	pConfigPath	�����ļ�·��
		CIPAnalysis(char *pConfigPath);

		///��ʼ��IP��Ӧϯλ��ϵ����
			///@comment	����getIpTypeID֮ǰ���ȳ�ʼ��
		bool init(void);

		///����IP��ַ�ж�ϯλ���ͺ���
			///@param	pIpAddr	ip��ַ����172.16.30.224
			///@return	���ظ�ip��ַ��Ӧ��ϯλ����
		int getIpTypeID(char *pIpAddr);

	/* */
	private:
		map<string, int> m_mapIpType;
};
#endif
