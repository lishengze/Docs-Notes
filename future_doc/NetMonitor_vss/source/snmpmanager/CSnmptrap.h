/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSnmptrap.h
///@brief	定义了snmp中接收trap数据的处理类
///@history
///20101008	LSC	参考net-snmp-5.5的snmptrapd实现
/////////////////////////////////////////////////////////////////////////
#ifndef REF_CSNMPTRAP_H
#define REF_CSNMPTRAP_H

#include "platform.h"
#include "net_snmp.h"

#include "Snmptrap_auth.h"

#include <signal.h>
#include <errno.h>

#ifdef WINDOWS
#include "windows/library/fd_event_manager.h"
#else
#include "unix/library/fd_event_manager.h"
#endif
#define DEFAULT_PORT	"udp:162"

class CSnmptrap
{
	/* */
	private:
		char *default_port;
		netsnmp_session *sess_list;
		int netsnmp_running;

#if HAVE_GETPID
		FILE *PID;
		char *pid_file;
#endif
		CSnmptrap_auth	*m_pauth;

	/* */
	public:
		//constructor
		CSnmptrap(void);

		//destructer
		~ CSnmptrap(void);

		void init(void);

		//主体执行函数体
		void run(void);

		void version(void)
		{
			printf("\nNET-SNMP Version:  %s\n", netsnmp_get_version());
			exit(0);
		};

	/* */
	private:
		//存储收到的trap数据包
		static Netsnmp_Trap_Handler restore_handler;

		netsnmp_session *snmptrapd_add_session(netsnmp_transport *t);

		void snmptrapd_close_sessions(netsnmp_session *sess_list);
};
#endif /* REF_CSNMPTRAP_H */
