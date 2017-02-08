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

/// 全局方法
/// 重新加载会员峰值数据文件
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
		///构造函数
			///@param	pConfigPath	配置文件路径
		CIPAnalysis(char *pConfigPath);

		///初始化IP对应席位关系函数
			///@comment	调用getIpTypeID之前需先初始化
		bool init(void);

		///根据IP地址判断席位类型函数
			///@param	pIpAddr	ip地址，如172.16.30.224
			///@return	返回该ip地址对应的席位类型
		int getIpTypeID(char *pIpAddr);

	/* */
	private:
		map<string, int> m_mapIpType;
};
#endif
