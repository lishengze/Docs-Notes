/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSynconfig.h
///@brief	定义了配置服务管理类
///@history
///20110928	李志伟		创建该文件
#ifndef __CSYNCONFIG_H
#define __CSYNCONFIG_H

#include "CFrontServer.h"
#include "CManagerServer.h"
#include "CEventServer.h"
#include "CSyncServer.h"
#include <PrjCommon.h>
#include <systools.h>
#include "CCrypto.h"

/////////////////////////////////////////////////////////////////////////
///CSynconfig是配置服务管理类，负责配置服务的生命周期。
/////////////////////////////////////////////////////////////////////////
class CSynconfig
{
	/* */
	public:
		CSynconfig(void);

		~CSynconfig(void)
		{
		}

		///初始化配置服务
		    ///@param	argc	命令行参数数量
		    ///@param	argv	命令行参数
		    ///@return	初始化成功为true，否则为false
		bool Init(int argc, char *argv[]);

		///启动配置服务所包含的服务程序
		    ///@return	启动成功为true，否则为false
		bool Start(void);

		///终止配置服务所包含的服务程序。
		    ///此为异步调用，调用Stop之后，需要用Wait来确认内置服务已经被终止。
		void Stop(void);

		///等待配置服务所包含的服务程序终止
		    ///@return	配置服务中的内置服务正常终止为true，否则为false
		bool Wait(void);

	/* */
	private:
		bool feedUpMemoryDB(void);

	/* */
	private:
		CSelectReactor	m_frontReactor;
		CFrontServer m_frontServer;

		CSelectReactor	m_snmpReactor;
		CManagerServer	m_snmpServer;

		CSelectReactor	m_eventReactor;
		CEventServer m_eventServer;

		SysReactor	m_syncReactor;
		CSyncServer m_syncServer;

		SyncDBOperator	m_dbHandler;
};
#endif // __CSYNCONFIG_H
