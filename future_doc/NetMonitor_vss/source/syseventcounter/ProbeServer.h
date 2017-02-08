/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	ProbeServer.h
///@brief	定义了探针监听采集代理连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
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
///CProbeServer定义了探针定期器处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CProbeTimmer :
	public CEventHandler
{
	/* */
	public:
		///构造函数
		CProbeTimmer(CReactor *pReactor);

		/** 设置定时器函数
	* @param	nIDEvent	定时器产生的事件ID
	* @param	nElapse	定时器的时间间隔，单位ms	
	*/
		void SetTimer(int nIDEvent, int nElapse);

		/** 定时器处理函数
	* @param	nIDEvent	该定时器的ID
	*/
		virtual void OnTimer(int nIDEvent);

		/** 取事件ID函数
	* @param	pFTDCPackage	收到的FTD数据包地址
	* @param	pSession	该数据包所属的会话ID
	* @return	返回事件的ID
	*/
		int GetEventId(void);

	/* */
	private:
		///定时器使用的数据包缓冲区
		CFTDCPackage m_pkgSend;

		///保存定时器的事件ID
		int m_nEventId;
};

/////////////////////////////////////////////////////////////////////////
///CProbeServer定义了探针监听采集代理连接请求处理的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class CProbeServer :
	public CSessionFactory,
	public CFTDCSessionCallback
{
	/* */
	public:
		///构造函数
		CProbeServer(CReactor *pReactor);

		/** FTD请求响应处理函数
	* @param	pFTDCPackage	收到的FTD数据包地址
	* @param	pSession	该数据包所属的会话ID	
	*/
		virtual int HandlePackage(
						CFTDCPackage *pFTDCPackage,
						CFTDCSession *pSession);

		/** 会话建立连接处理函数
	* @param	pChannel	建立连接的通道指针
	* @param	bIsListener	是否是监听者标志,true表示监听者,false表示请求连接端	
	*/
		virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark);

		///连接成功时调用的处理函数
			///@param	pSession	连接成功的会话指针
		virtual void OnSessionConnected(CSession *pSession);

		/** 发送数据包函数
	* @param	pFTDPackage	发送数据包的地址
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
		/** 会话连接断开处理函数
	* @param	pSession	断开会话的ID
	* @param	nReason	断开的原因
	*/
		virtual void OnSessionDisconnected(CSession *pSession, int nReason);

	/* */
	private:
		///主机信息发送数据包缓冲区
		CFTDCPackage m_pkgSend;

		///定时器
		//CProbeTimmer m_timer;
};
#endif // !defined(REF_PROBESERVER_H)
