/////////////////////////////////////////////////////////////////////////
///@system 交易监控系统
///@company 上海期货信息技术有限公司
///@file FibClientServer.h
///@brief	定义了面向前置机会话连接服务类
///@history
///20080624	郭鹏		创建该文件
///20080624	郭鹏		修订注释
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
///CFibClientServer定义了面向前置机会话连接服务类
///@author	郭鹏
///@version	1.0,20080624
/////////////////////////////////////////////////////////////////////////
class CFibClientServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:

		///构造函数
			///@param	pReactor	所依赖CReactor对象
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

		///创建连接函数
			///@param	pChannel		所依赖CChannel对象
			///@param	bIsListener		是否是侦听者
			///@return	创建好的CSession对象指针
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark)
		{
			CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
			pSession->RegisterPackageHandler(this);

			/// Added by Henchi, 20120309
			pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
			return pSession;
		}

		///当连接建立时被调用
			///@param	pSession	连接对应的指针
			///@return	无返回值
		virtual void OnSessionConnected(CSession *pSession);

		///当连接断开时调用	
			///@param	pSession	连接对应的指针
			///@param	nReason		连接断开的原因
			///@return	无返回值
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

		///包处理函数
			///@param	pFTDCPackage	所收到的FTD包
			///@param	pSession		收包所属的连接
			///@return	返回包处理结果信息
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		//通知front清流
		void NotifyFrontNewTradeDay(string strOldDay, string strNewDay);

	/* */
	private:
		///前置机登录的响应函数
			///@param	pFTDCPackage	所收到的FTD包
			///@param	pSession		收包所属的连接	
			///@return	无返回值
		void OnReqUserLogin(CFTDCPackage *pFTDCPackage, CFTDCSession *pSession);

	/* */
	private:
		///一次初始化反复使用的FTD包
		CFTDCPackage m_pkgSend;
};
#endif
