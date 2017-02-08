/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	Snmptrap_auth.h
///@brief	定义了接收trap数据过程中认证确认处理
///@history
///20101101	LSC	参考net-snmp-5.5的snmptrapd_auth.c实现
/////////////////////////////////////////////////////////////////////////
#ifndef REF_SNMPTRAP_AUTH_H
#define REF_SNMPTRAP_AUTH_H
#pragma once
#include "platform.h"
#include "net_snmp.h"

#include "Snmptrap_handler.h"

#define NETSNMP_DS_APP_NUMERIC_IP		16
#define NETSNMP_DS_APP_NO_AUTHORIZATION 17

int netsnmp_trapd_auth(
		netsnmp_pdu *pdu,
		netsnmp_transport *transport,
		netsnmp_trapd_handler *handler);

#define TRAP_AUTH_LOG	(1 << VACM_VIEW_LOG)		/* displaying and logging */
#define TRAP_AUTH_EXE	(1 << VACM_VIEW_EXECUTE)	/* executing code or binaries */
#define TRAP_AUTH_NET	(1 << VACM_VIEW_NET)		/* forwarding and net access */

#define TRAP_AUTH_ALL	(TRAP_AUTH_LOG | TRAP_AUTH_EXE | TRAP_AUTH_NET)
#define TRAP_AUTH_NONE	0

class CSnmptrap_auth
{
	/* */
	public:
		CSnmptrap_auth(void);

	/* */
	public:
		~ CSnmptrap_auth(void);

	/* */
	public:
		void init_netsnmp_trapd_auth(void);
		static int	netsnmp_trapd_check_auth(int authtypes);
};
#endif
