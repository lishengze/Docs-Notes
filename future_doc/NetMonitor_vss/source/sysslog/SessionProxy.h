/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file SessionProxy.h
///@brief 会话代理类，为向CSlogServer发送数据提供代理。
///@history
///20120316	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef __SESSION_PROXY_H
#define __SESSION_PROXY_H

#include "CSlogServer.h"
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
		void Init(CSlogServer *frontMgr)
		{
			assert(frontMgr);

			m_frontMgr = frontMgr;
		}

		///通知所有的前置连接
		    ///@param	pkg	要发送的数据包
		void NotifyAllFront(CFTDCPackage *pkg)
		{
			assert(pkg);

			if (m_frontMgr)
			{
				m_frontMgr->NotifyAllSession(pkg);
			}
		}

	/* */
	private:
		SessionProxy(void) :
		m_frontMgr(NULL)
		{
		}

		/// 前置服务管理端，不负责管理其生命周期。
		CSlogServer *m_frontMgr;

		/// 互斥锁，提供线程安全性保护
		CMutex	m_mutex;

		/// SessionProxy的单件对象
		static SessionProxy m_obj;
};
#endif // __SESSION_PROXY_H
