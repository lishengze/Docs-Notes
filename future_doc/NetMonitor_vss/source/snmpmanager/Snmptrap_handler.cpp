/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	Snmptrap_handlers.cpp
///@brief	定义了接收trap数据过程中的相关数据结构及回调处理
///@history
///20101101	LSC	参考net-snmp-5.5的snmptrapd_handlers.c实现
/////////////////////////////////////////////////////////////////////////
#include "Snmptrap_handler.h"
#include "Snmptrap_auth.h"

netsnmp_trapd_handler *netsnmp_auth_global_traphandlers = NULL;
netsnmp_trapd_handler *netsnmp_pre_global_traphandlers = NULL;
netsnmp_trapd_handler *netsnmp_post_global_traphandlers = NULL;
netsnmp_trapd_handler *netsnmp_default_traphandlers = NULL;
netsnmp_trapd_handler *netsnmp_specific_traphandlers = NULL;

typedef struct netsnmp_handler_map_t
{
	netsnmp_trapd_handler **handler;
	const char	*descr;
} netsnmp_handler_map;

static netsnmp_handler_map	handlers[] =
{
	{ &netsnmp_auth_global_traphandlers, "auth trap" },
	{ &netsnmp_pre_global_traphandlers, "pre-global trap" },
	{ NULL, "trap specific" },
	{ &netsnmp_post_global_traphandlers, "global" },
	{ NULL, NULL }
};

CSnmptrap_handler::CSnmptrap_handler(void)
{
}

CSnmptrap_handler::~CSnmptrap_handler(void)
{
}

netsnmp_trapd_handler *CSnmptrap_handler::netsnmp_add_global_traphandler(
	int list,
	Netsnmp_Trap_Handler handler)
{
	netsnmp_trapd_handler *traph;

	if (!handler)
	{
		return NULL;
	}

	traph = SNMP_MALLOC_TYPEDEF(netsnmp_trapd_handler);
	if (!traph)
	{
		return NULL;
	}

	/*
     * Add this new handler to the front of the appropriate list
     *   (or should it go on the end?)
     */
	traph->handler = handler;
	traph->authtypes = TRAP_AUTH_ALL;	/* callers will likely change this */
	switch (list)
	{
		case NETSNMPTRAPD_AUTH_HANDLER:
			traph->nexth = netsnmp_auth_global_traphandlers;
			netsnmp_auth_global_traphandlers = traph;
			break;
		case NETSNMPTRAPD_PRE_HANDLER:
			traph->nexth = netsnmp_pre_global_traphandlers;
			netsnmp_pre_global_traphandlers = traph;
			break;
		case NETSNMPTRAPD_POST_HANDLER:
			traph->nexth = netsnmp_post_global_traphandlers;
			netsnmp_post_global_traphandlers = traph;
			break;
		case NETSNMPTRAPD_DEFAULT_HANDLER:
			traph->nexth = netsnmp_default_traphandlers;
			netsnmp_default_traphandlers = traph;
			break;
		default:
			free(traph);
			return NULL;
	}

	return traph;
}

netsnmp_trapd_handler *netsnmp_get_traphandler(oid *trapOid, int trapOidLen)
{
	netsnmp_trapd_handler *traph;

	if (!trapOid || !trapOidLen)
	{
		DEBUGMSGTL(("snmptrapd:lookup", "get_traphandler no OID!\n"));
		return NULL;
	}

	DEBUGMSGTL(("snmptrapd:lookup", "Looking up Trap OID: "));
	DEBUGMSGOID(("snmptrapd:lookup", trapOid, trapOidLen));
	DEBUGMSG(("snmptrapd:lookup", "\n"));

	/*
	* Look for a matching OID, and return that list...
	*/
	for (traph = netsnmp_specific_traphandlers; traph; traph = traph->nextt)
	{
		/*
			* If the trap handler wasn't wildcarded, then the trapOID
			*   should match the registered OID exactly.
			*/
		if (!(traph->flags & NETSNMP_TRAPHANDLER_FLAG_MATCH_TREE))
		{
			if (snmp_oid_compare(
					traph->trapoid,
				traph->trapoid_len,
				trapOid,
				trapOidLen) == 0)
			{
				DEBUGMSGTL(
					(
						"snmptrapd:lookup",
							"get_traphandler exact match (%p)\n", traph
					));
				return traph;
			}
		}
		else
		{
			/*
				* If the trap handler *was* wildcarded, then the trapOID
				*   should have the registered OID as a prefix...
				*/
			if (snmp_oidsubtree_compare(
					traph->trapoid,
				traph->trapoid_len,
				trapOid,
				trapOidLen) == 0)
			{
				if (traph->flags & NETSNMP_TRAPHANDLER_FLAG_STRICT_SUBTREE)
				{
					/*
							* ... and (optionally) *strictly* as a prefix
							*   i.e. not including an exact match.
							*/
					if (snmp_oid_compare(
							traph->trapoid,
						traph->trapoid_len,
						trapOid,
						trapOidLen) != 0)
					{
						DEBUGMSGTL(
							(
								"snmptrapd:lookup",
									"get_traphandler strict subtree match (%p)\n",
									traph
							));
						return traph;
					}
				}
				else
				{
					DEBUGMSGTL(
						(
							"snmptrapd:lookup",
								"get_traphandler subtree match (%p)\n",
									traph
						));
					return traph;
				}
			}
		}
	}

	DEBUGMSGTL(
		(
			"snmptrapd:lookup", "get_traphandler default (%p)\n",
				netsnmp_default_traphandlers
		));
	return netsnmp_default_traphandlers;
}

int snmp_input(
	int op,
	netsnmp_session *session,
	int reqid,
	netsnmp_pdu *pdu,
	void *magic)
{
	oid stdTrapOidRoot[] = { 1, 3, 6, 1, 6, 3, 1, 1, 5 };
	oid snmpTrapOid[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	oid trapOid[MAX_OID_LEN + 2] = { 0 };
	int trapOidLen;
	netsnmp_variable_list *vars;
	netsnmp_trapd_handler *traph;
	netsnmp_transport *transport = (netsnmp_transport *)magic;
	int ret;
	int idx;

	switch (op)
	{
		case NETSNMP_CALLBACK_OP_RECEIVED_MESSAGE:
			// Drops packets with reception problems
			if (session->s_snmp_errno)
			{
				/* drop problem packets */
				return 1;
			}

			/* Determine the OID that identifies the trap being handled*/
			DEBUGMSGTL(("snmptrapd", "input: %x\n", pdu->command));
			switch (pdu->command)
			{
				case SNMP_MSG_TRAP:
					/*
		* Convert v1 traps into a v2-style trap OID
		*/
					if (pdu->trap_type == SNMP_TRAP_ENTERPRISESPECIFIC)
					{
						trapOidLen = pdu->enterprise_length;
						memcpy(trapOid, pdu->enterprise, sizeof(oid) * trapOidLen);
						if (trapOid[trapOidLen - 1] != 0)
						{
							trapOid[trapOidLen++] = 0;
						}

						trapOid[trapOidLen++] = pdu->specific_type;
					}
					else
					{
						memcpy(trapOid, stdTrapOidRoot, sizeof(stdTrapOidRoot));
						trapOidLen = OID_LENGTH(stdTrapOidRoot);	/* 9 */
						trapOid[trapOidLen++] = pdu->trap_type + 1;
					}

					break;
				case SNMP_MSG_TRAP2:
				case SNMP_MSG_INFORM:
					vars = pdu->variables;
					if (vars)
					{
						vars = vars->next_variable;
					}

					if (!vars
					||	snmp_oid_compare(
							vars->name,
						vars->name_length,
						snmpTrapOid,
						OID_LENGTH(snmpTrapOid)))
					{
						// Didn't find it! look through the full list....
						for (vars = pdu->variables; vars; vars = vars->next_variable)
						{
							if (!snmp_oid_compare(
									vars->name,
								vars->name_length,
								snmpTrapOid,
								OID_LENGTH(snmpTrapOid)))
							{
								break;
							}
						}

						if (!vars)
						{
							// Still can't find it!  Give up.
							snmp_log(LOG_ERR, "Cannot find TrapOID in TRAP2 PDU\n");
							return 1;
						}
					}

					memcpy(trapOid, vars->val.objid, vars->val_len);
					trapOidLen = vars->val_len / sizeof(oid);
					break;
				default:
					/* SHOULDN'T HAPPEN! */
					return 1;
			}

			DEBUGMSGTL(("snmptrapd", "Trap OID: "));
			DEBUGMSGOID(("snmptrapd", trapOid, trapOidLen));
			DEBUGMSG(("snmptrapd", "\n"));

			/*
		*  OK - We've found the Trap OID used to identify this trap.
		*  Call each of the various lists of handlers:
		*     a) authentication-related handlers,
		*     b) other handlers to be applied to all traps
		*		(*before* trap-specific handlers)
		*     c) the handler(s) specific to this trap
		t        *     d) any other global handlers
		*/
			for (idx = 0; handlers[idx].descr; ++idx)
			{
				DEBUGMSGTL(
					("snmptrapd", "Running %s handlers\n", handlers[idx].descr));
				if (NULL == handlers[idx].handler)
				{					/* specific */
					traph = netsnmp_get_traphandler(trapOid, trapOidLen);
				}
				else
				{
					traph = *handlers[idx].handler;
				}

				for (; traph; traph = traph->nexth)
				{
					if (!CSnmptrap_auth::netsnmp_trapd_check_auth(traph->authtypes))
					{
						continue;	/* we continue on and skip this one */
					}

					ret = (*(traph->handler)) (pdu, transport, traph);
					if (NETSNMPTRAPD_HANDLER_FINISH == ret)
					{
						return 1;
					}

					if (ret == NETSNMPTRAPD_HANDLER_BREAK)
					{
						break;		/* move on to next type */
					}
				}					/* traph */
			}						/* handlers */

			if (pdu->command == SNMP_MSG_INFORM)
			{
				netsnmp_pdu *reply = snmp_clone_pdu(pdu);
				if (!reply)
				{
					snmp_log(LOG_ERR, "couldn't clone PDU for INFORM response\n");
				}
				else
				{
					reply->command = SNMP_MSG_RESPONSE;
					reply->errstat = 0;
					reply->errindex = 0;
					if (!snmp_send(session, reply))
					{
						snmp_sess_perror(
							"snmptrapd: Couldn't respond to inform pdu",
							session);
						snmp_free_pdu(reply);
					}
				}
			}

			break;
		case NETSNMP_CALLBACK_OP_TIMED_OUT:
			snmp_log(LOG_ERR, "Timeout: This shouldn't happen!\n");
			break;
		case NETSNMP_CALLBACK_OP_SEND_FAILED:
			snmp_log(LOG_ERR, "Send Failed: This shouldn't happen either!\n");
			break;
		case NETSNMP_CALLBACK_OP_CONNECT:
		case NETSNMP_CALLBACK_OP_DISCONNECT:
			/* Ignore silently */
			break;
		default:
			snmp_log(
				LOG_ERR,
				"Unknown operation (%d): This shouldn't happen!\n",
				op);
			break;
	}

	return 0;
}
