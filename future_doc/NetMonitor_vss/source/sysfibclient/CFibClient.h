/////////////////////////////////////////////////////////////////////////
///@system 交易监控系统
///@company 上海期货信息技术有限公司
///@file CFibClient.h
///@brief	定义了面向fibproxy会话连接客户类
///@history
///20080624	郭鹏		创建该文件
///20080624	郭鹏		修订注释
#ifndef SYS_FIBCLIENT_H
#define SYS_FIBCLIENT_H

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
#include "CFPPSubscriber.h"

#include "EventConnect.h"

/////////////////////////////////////////////////////////////////////////
///CFibClient定义了面向fibproxy会话连接客户类
///@author	郭鹏
///@version	1.0,20080624
/////////////////////////////////////////////////////////////////////////
class CFibClient :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:

		///构造函数
			///@param	pReactor		所依赖CReactor对象
			///@param	pszBaseFlowPath	流保存目录
			///@param	pszUserID		登录fibproxy用户名
			///@param	pszPassword		登录fibproxy密码
		CFibClient(
		CReactor *pReactor,
		const char	*pszBaseFlowPath,
		const char	*pszUserID,
		const char	*pszPassword) :
		CSessionFactory(pReactor, 1)
		{
			m_bIsLogin = false;
			m_dwSessionID = 0;
			m_dwRequsetID = 0;
			m_strBaseFlowPath = pszBaseFlowPath;
			m_strUserID = pszUserID;
			m_strPassword = pszPassword;
			m_pkgRequest.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 100);
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 100);

			////初始化本地日期
			//time_t	timep;
			//time(&timep);
      //
			//struct tm *pGm = localtime(&timep);
      //
			//sprintf((char *)(g_strTryDate.data()),"%d%02d%02d" ,pGm->tm_year+1900 ,pGm->tm_mon+1 ,pGm->tm_mday);
		}

		///创建订阅主题函数
			///@param	wTopicID		主题ID
			///@return	无返回值
		void CreateSubscriber(WORD wTopicID);

		///创建连接函数
			///@param	pChannel		所依赖CChannel对象
			///@param	bIsListener		是否是侦听者
			///@return	创建好的CSession对象指针
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///当连接建立时被调用
			///@param	pSession	连接对应的指针
			///@return	无返回值
		virtual void OnSessionConnected(CSession *pSession);

		///当连接断开时调用	
			///@param	pSession	连接对应的指针
			///@param	nReason		连接断开的原因
			///@return	无返回值
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///事件驱动函数，此处为时间驱动函数，用于相应时钟
			///@param	nIDEvent	时钟间隔
			///@return	无返回值
		virtual void OnTimer(int nIDEvent);

		///包处理函数
			///@param	pFTDCPackage	所收到的FTD包
			///@param	pSession		收包所属的连接
			///@return	返回包处理结果信息
		int HandlePackage(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		void SetEventConentSever(CEventConnect *pEventServer)
		{
			m_pEvtSrv = pEventServer;
		}

		void SetFrontServer(CFibClientServer *pFrontSrv)
		{
			m_pFrontSrv = pFrontSrv;
		}

	/* */
	private:
		///直接发送请求
			///@return	无返回值
		int RequestDirectly(void);

		///设置重连接时间间隔
			///@return	无返回值
		void SetRetryTimer(void);

		///登录请求函数
			///@return	无返回值
		void ReqLogin(void);

		///订阅请求函数
			///@return	无返回值
		void ReqSubscribe(void);

		///重置流水订阅状态（清流）
		void ResetSubscriber(void);

		///发生错误的响应函数
			///@param	pFTDCPackage	所收到的FTD包
			///@param	pSession		收包所属的连接	
			///@return	无返回值
		void OnRspError(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///客户端登录的应答的响应函数
			///@param	pFTDCPackage	所收到的FTD包
			///@param	pSession		收包所属的连接	
			///@return	无返回值
		void OnRspUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		///客户端订阅响应函数
			///@param	pFTDCPackage	所收到的FTD包
			///@param	pSession		收包所属的连接	
			///@return	无返回值
		void OnRspSubscribe(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

		/* */
	private:
		///保存会话ID
		DWORD m_dwSessionID;

		///是否已登录的标志位
		bool m_bIsLogin;

		///一次初始化反复使用的FTD包
		CFTDCPackage m_pkgRequest;

		CFTDCPackage m_pkgSend;

		///应答时返回请求时对应的请求ID
		DWORD m_dwRequsetID;

		///超时临界值
		int m_nTimeOut;

		///订阅者与SESSIONID所对应而成的MAP类型
		typedef map<WORD, CFPPSubscriber *> CSubscriberMap;

		///订阅者与SESSIONID所对应而成的MAP对象
		CSubscriberMap	m_mapSubscriber;

		///流保存路径
		string	m_strBaseFlowPath;

		///流保存路径
		string	m_strFlowPath;

		///登录Fibproxy用户名
		string	m_strUserID;

		///登录Fibproxy密码
		string	m_strPassword;

		CEventConnect *m_pEvtSrv;
		CFibClientServer *m_pFrontSrv;
};
#endif
