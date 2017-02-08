/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file SessionProxy.h
///@brief 会话代理类，为CFrontServer和CManagerServer相互发送数据提供代理。
///@history
///20110728	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef __SESSION_PROXY_H
#define __SESSION_PROXY_H

#include "CFrontServer.h"
#include "CManagerServer.h"
#include "CEventServer.h"
#include "CSyncServer.h"
#include <ScopedLock.h>
#include <Mutex.h>
#include <systools.h>
#include <list>
#include <PrjCommon.h>

///SessionProxy为多个Session间通信提供代理
class SessionProxy
{
	/* */
	public:

		/// SessionProxy的实例，SessionProxy为单件模式。
		static SessionProxy &Instance(void)
		{
			return m_obj;
		}

		///析构函数	
		~SessionProxy(void)
		{
		}

		///初始化函数，提供各个服务连接的管理端，必须调用。
		    ///@param	frontMgr	和前置服务连接的管理端
		    ///@param	snmpMgr	和SNMP服务连接的管理端
		    ///@param	eventMgr	和事件服务连接的管理端
		    ///@param	syncMgr	和同步配置服务连接的管理端
		void Init(
		CFrontServer *frontMgr,
		CManagerServer	*snmpMgr,
		CEventServer *eventMgr,
		CSyncServer *syncMgr)
		{
			assert(frontMgr && frontMgr && eventMgr && syncMgr);

			m_frontMgr = frontMgr;
			m_snmpMgr = snmpMgr;
			m_eventMgr = eventMgr;
			m_syncMgr = syncMgr;
		}

		///通知SNMP管理端
		    ///@param	reqPkg	要发送的数据包
		void NotifySnmp(CFTDCPackage *reqPkg)
		{
			assert(reqPkg && m_snmpMgr);
			m_snmpMgr->NotifyAllSessions(reqPkg);
		}

		///通知指定中心的SNMP管理端
		    ///@param	reqPkg	要发送的数据包
		    ///@param	dc 数据中心标识
		void NotifySnmp(CFTDCPackage *reqPkg, CDataCenterFlagType dc)
		{
			assert(reqPkg && m_snmpMgr);
			m_snmpMgr->NotifySessions(reqPkg, dc);
		}

		void NotifySnmp(char dataCenter, CFTDCPackage *reqPkg)
		{
			assert(reqPkg && m_snmpMgr);
			m_snmpMgr->NotifySessions(dataCenter, reqPkg);
		}

		///通知事件服务管理端
		    ///@param	reqPkg	要发送的数据包
		void NotifyEventCounter(CFTDCPackage *reqPkg)
		{
			assert(reqPkg && m_eventMgr);
			m_eventMgr->NotifyAllSessions(reqPkg);
		}

		///通知所有的前置连接
		    ///@param	pkg	要发送的数据包
		void NotifyFront(CFTDCPackage *pkg)
		{
			assert(pkg && m_frontMgr);
			m_frontMgr->NotifyAllSession(pkg);
		}

		///通知所有的从配置服务
		    ///@param	pkg	要发送的数据包
		void NotifySync(CFTDCPackage *pkg)
		{
			assert(pkg && m_syncMgr);
			m_syncMgr->NotifyAllSessions(pkg);
		}

		///前置服务向SNMP管理端发送请求，该方法是线程安全的。
		    ///@param	reqPkg   请求的数据包
		    ///@param	reqSession	发送请求的session
		    ///@param	rspPkg	要发送的数据包
		    ///@param	datacenter	被请求的snmpManger所属的数据中心
		void RequestSnmp(
				CFTDCPackage *reqPkg,
				CFTDCSession *reqSession,
				CFTDCPackage *rspPkg,
				char datacenter);

		//SNMP管理端向前置服务发送响应，该方法是线程安全的。
		    ///@param	reqID	数据包的ID
		    ///@param	rspPkg	要发送的数据包
		    ///@param	lastRsp	是否是最后一个响应包。
		void RespondFront(int rspID, CFTDCPackage *rspPkg, bool lastRsp);

	/* */
	private:
		SessionProxy(void) :
		m_index(0)
		{
		}

		/// 前置服务管理端，不负责管理其生命周期。
		CFrontServer *m_frontMgr;

		/// SNMP服务管理端，不负责管理其生命周期。
		CManagerServer	*m_snmpMgr;

		/// 事件服务管理端，不负责管理其生命周期。
		CEventServer *m_eventMgr;

		/// 同步服务管理端，不负责管理其生命周期。
		CSyncServer *m_syncMgr;

		/// 互斥锁，提供线程安全性保护
		CMutex	m_mutex;

		/// 管理front与snmp之间通信的包与会话
		typedef map<DWORD, TRID> SessionPkgSet;
		SessionPkgSet m_vRid;
		DWORD m_index;

		/// SessionProxy的单件对象
		static SessionProxy m_obj;
};
#endif // __SESSION_PROXY_H
