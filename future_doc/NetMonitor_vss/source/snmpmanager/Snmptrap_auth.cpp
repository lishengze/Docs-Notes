/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	Snmptrap_auth.cpp
///@brief	定义了接收trap数据过程中认证确认处理
///@history
///20101101	LSC	参考net-snmp-5.5的snmptrapd_auth.c实现
/////////////////////////////////////////////////////////////////////////
#include "Snmptrap_auth.h"

static int	lastlookup = 0;

CSnmptrap_auth::CSnmptrap_auth(void)
{
}

CSnmptrap_auth::~CSnmptrap_auth(void)
{
}

void CSnmptrap_auth::init_netsnmp_trapd_auth(void)
{
	/* register our function as a authorization handler */
	netsnmp_trapd_handler *traph;
	traph = CSnmptrap_handler::netsnmp_add_global_traphandler(
			NETSNMPTRAPD_AUTH_HANDLER,
			netsnmp_trapd_auth);
	traph->authtypes = TRAP_AUTH_NONE;

	/* register a config token for turning off the authorization entirely */
	netsnmp_ds_register_config(
		ASN_BOOLEAN,
		"snmptrapd",
		"disableAuthorization",
		NETSNMP_DS_APPLICATION_ID,
		NETSNMP_DS_APP_NO_AUTHORIZATION);
}

int netsnmp_trapd_auth(
	netsnmp_pdu *pdu,
	netsnmp_transport *transport,
	netsnmp_trapd_handler *handler)
{
	int ret = 0;
	oid snmptrapoid[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
	size_t	snmptrapoid_len = OID_LENGTH(snmptrapoid);
	netsnmp_pdu *newpdu = pdu;
	netsnmp_variable_list *var;

	/* check to see if authorization was not disabled */
	if (netsnmp_ds_get_boolean(
			NETSNMP_DS_APPLICATION_ID,
		NETSNMP_DS_APP_NO_AUTHORIZATION))
	{
		DEBUGMSGTL(
			("snmptrapd:auth", "authorization turned off: not checking\n"));
		return NETSNMPTRAPD_HANDLER_OK;
	}

	/* bail early if called illegally */
	if (!pdu || !transport || !handler)
	{
		return NETSNMPTRAPD_HANDLER_FINISH;
	}

	/* loop through each variable and find the snmpTrapOID.0 var
       indicating what the trap is we're staring at. */
	for (var = newpdu->variables; var != NULL; var = var->next_variable)
	{
		if (netsnmp_oid_equals(
				var->name,
			var->name_length,
			snmptrapoid,
			snmptrapoid_len) == 0)
		{
			break;
		}
	}

	/* make sure we can continue: we found the snmpTrapOID.0 and its an oid */
	if (!var || var->type != ASN_OBJECT_ID)
	{
		snmp_log(
			LOG_ERR,
			"Can't determine trap identifier; refusing to authorize it\n");
#ifndef NETSNMP_DISABLE_SNMPV1
		if (newpdu != pdu)
		{
			snmp_free_pdu(newpdu);
		}

#endif
		return NETSNMPTRAPD_HANDLER_FINISH;
	}

	DEBUGMSGTL(("snmptrapd:auth", "Final bitmask auth: %x\n", ret));

	if (ret)
	{
		/* we have policy to at least do "something".  Remember and continue. */
		lastlookup = ret;
#ifndef NETSNMP_DISABLE_SNMPV1
		if (newpdu != pdu)
		{
			snmp_free_pdu(newpdu);
		}

#endif
		return NETSNMPTRAPD_HANDLER_OK;
	}

	/* No policy was met, so we drop the PDU from further processing */
	DEBUGMSGTL(("snmptrapd:auth", "Dropping unauthorized message\n"));
#ifndef NETSNMP_DISABLE_SNMPV1
	if (newpdu != pdu)
	{
		snmp_free_pdu(newpdu);
	}

#endif
	return NETSNMPTRAPD_HANDLER_FINISH;
}

int CSnmptrap_auth::netsnmp_trapd_check_auth(int authtypes)
{
	if (netsnmp_ds_get_boolean(
			NETSNMP_DS_APPLICATION_ID,
		NETSNMP_DS_APP_NO_AUTHORIZATION))
	{
		DEBUGMSGTL(("snmptrapd:auth", "authorization turned off\n"));
		return 1;
	}

	DEBUGMSGTL(
		(
			"snmptrapd:auth",
				"Comparing auth types: result=%d, request=%d, result=%d\n",
					lastlookup, authtypes,
						((authtypes & lastlookup) == authtypes)
		));
	return ((authtypes & lastlookup) == authtypes);
}
