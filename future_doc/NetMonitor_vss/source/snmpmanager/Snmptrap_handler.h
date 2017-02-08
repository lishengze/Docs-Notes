/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	Snmptrap_handlers.h
///@brief	定义了接收trap数据过程中的相关数据结构及回调处理
///@history
///20101101	LSC	参考net-snmp-5.5的snmptrapd_handlers.c实现
/////////////////////////////////////////////////////////////////////////
#ifndef REF_SNMPTRAP_HANDLER_H
#define REF_SNMPTRAP_HANDLER_H

#pragma once
#include "platform.h"
#include "net_snmp.h"

typedef struct netsnmp_trapd_handler_s	netsnmp_trapd_handler;

typedef int (Netsnmp_Trap_Handler)
	(
		netsnmp_pdu * pdu,
		netsnmp_transport * transport,
		netsnmp_trapd_handler * handler
	);

#define NETSNMP_TRAPHANDLER_FLAG_MATCH_TREE		0x1
#define NETSNMP_TRAPHANDLER_FLAG_STRICT_SUBTREE 0x2

struct netsnmp_trapd_handler_s
{
	oid *trapoid;
	int trapoid_len;
	char *token;					/* Or an array of tokens? */
	char *format;					/* Formatting string */
	int version;
	int authtypes;
	int flags;
	Netsnmp_Trap_Handler *handler;
	void *handler_data;

	netsnmp_trapd_handler *nexth;	/* Next handler for this trap */
	netsnmp_trapd_handler *prevt;	/* Doubly-linked list of traps with registered handlers */
	netsnmp_trapd_handler *nextt;
};
#define NETSNMPTRAPD_AUTH_HANDLER		1
#define NETSNMPTRAPD_PRE_HANDLER		2
#define NETSNMPTRAPD_POST_HANDLER		3
#define NETSNMPTRAPD_DEFAULT_HANDLER	4

#define NETSNMPTRAPD_HANDLER_OK			1	/* Succeed, & keep going */
#define NETSNMPTRAPD_HANDLER_FAIL		2	/* Failed but keep going */
#define NETSNMPTRAPD_HANDLER_BREAK		3	/* Move to the next list */
#define NETSNMPTRAPD_HANDLER_FINISH		4	/* No further processing */

netsnmp_trapd_handler *netsnmp_get_traphandler(oid *trapOid, int trapOidLen);

int snmp_input(
		int op,
		netsnmp_session *session,
		int reqid,
		netsnmp_pdu *pdu,
		void *magic);

class CSnmptrap_handler
{
	/* */
	public:
		CSnmptrap_handler(void);

	/* */
	public:
		~ CSnmptrap_handler(void);

		static netsnmp_trapd_handler *netsnmp_add_global_traphandler(
										int list,
										Netsnmp_Trap_Handler *handler);
};
#endif
