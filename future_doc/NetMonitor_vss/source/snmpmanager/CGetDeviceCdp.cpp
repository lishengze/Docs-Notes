/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CGetDeviceCdp.cpp
///@brief	实现了CGetDeviceCdp使用的类
///@history
///20101020	周建军		创建该文件
#include "CGetDeviceCdp.h"

int cdpwalk(
	char *pHostIp,
	char *pCommKey,
	char *pRootOid,
	map<string, string> &cdrMap)
{
	netsnmp_session session;

	netsnmp_session *ss;
	netsnmp_pdu *pdu;
	netsnmp_pdu *response;
	netsnmp_variable_list *vars;
	oid name[MAX_OID_LEN];
	size_t	name_length;
	oid root[MAX_OID_LEN];
	size_t	rootlen;
	oid end_oid[MAX_OID_LEN];
	size_t	end_len = 0;
	int running;
	int status;
	int check;
	int exitval = 0;

	snmp_sess_init(&session);

	//设置session的各变量
	session.version = SNMP_VERSION_2c;
	session.peername = (char *)pHostIp;
	session.community = (u_char *)pCommKey;
	session.community_len = strlen((char *)session.community);
	init_snmp("snmpapp");

	// get the initial object and subtree
	rootlen = MAX_OID_LEN;
	if (snmp_parse_oid(pRootOid, root, &rootlen) == NULL)
	{
		snmp_perror(pRootOid);
		return (1);
	}

	memmove(end_oid, root, rootlen * sizeof(oid));
	end_len = rootlen;
	end_oid[end_len - 1]++;

	// open an SNMP session
	SOCK_STARTUP;
	ss = snmp_open(&session);
	if (ss == NULL)
	{
		// diagnose snmp_open errors with the input netsnmp_session pointer
		snmp_sess_perror("snmpwalk", &session);
		SOCK_CLEANUP;
		return (1);
	}

	// get first object to start walk
	memmove(name, root, rootlen * sizeof(oid));
	name_length = rootlen;
	running = 1;

	while (running)
	{
		// create PDU for GETNEXT request and add object name to request
		pdu = snmp_pdu_create(SNMP_MSG_GETNEXT);
		snmp_add_null_var(pdu, name, name_length);

		// do the request
		status = snmp_synch_response(ss, pdu, &response);
		if (status == STAT_SUCCESS)
		{
			if (response->errstat == SNMP_ERR_NOERROR)
			{
				// check resulting variables
				for (vars = response->variables;
					 vars;
					 vars = vars->next_variable)
				{
					if ((vars->name_length < end_len)
					||	(
							memcmp(
							end_oid,
						vars->name,
						end_len * sizeof(oid)) <= 0
					))
					{
						// not part of this subtree
						running = 0;
						continue;
					}

					//print_variable(vars->name, vars->name_length, vars);
					char idffer[32];
					sprintf(
						idffer,
						"%d.%d\n",
						vars->name[vars->name_length - 2],
						vars->name[vars->name_length - 1]);

					char valffer[128];
					memset(valffer, 0, 128);
					switch (vars->type)
					{
						case ASN_OCTET_STR:
						case ASN_BIT_STR:
						case ASN_OPAQUE:
							{
								memcpy(
									valffer,
									vars->val.string,
									min(sizeof(valffer) - 1, vars->val_len));
							}

							break;
						default:
							break;
					}

					cdrMap[idffer] = valffer;

					if ((vars->type != SNMP_ENDOFMIBVIEW)
					&&	(vars->type != SNMP_NOSUCHOBJECT)
					&&	(vars->type != SNMP_NOSUCHINSTANCE))
					{
						// not an exception value
						if (check
						&&	snmp_oid_compare(
								name,
							name_length,
							vars->name,
							vars->name_length) >= 0)
						{
							fprintf(stderr, "Error: OID not increasing: ");
							fprint_objid(stderr, name, name_length);
							fprintf(stderr, " >= ");
							fprint_objid(stderr, vars->name, vars->name_length);
							fprintf(stderr, "\n");
							running = 0;
							exitval = 1;
						}

						memmove(
							(char *)name,
							(char *)vars->name,
							vars->name_length * sizeof(oid));
						name_length = vars->name_length;
					}
					else
					{	// an exception value, so stop
						running = 0;
					}
				}
			}
			else
			{
				// error in response, print it
				running = 0;
				if (response->errstat == SNMP_ERR_NOSUCHNAME)
				{
					printf("End of MIB\n");
				}
				else
				{
					fprintf(
						stderr,
						"Error in packet.\nReason: %s\n",
						snmp_errstring(response->errstat));
					if (response->errindex != 0)
					{
						fprintf(stderr, "Failed object: ");

						int count;
						for (count = 1, vars = response->variables;
							 vars && count != response->errindex;
							 vars = vars->next_variable, count++)
							/*EMPTY*/
							;
						if (vars)
						{
							fprint_objid(stderr, vars->name, vars->name_length);
						}

						fprintf(stderr, "\n");
					}

					exitval = 2;
				}
			}
		}
		else if (status == STAT_TIMEOUT)
		{
			fprintf(stderr, "Timeout: No Response from %s\n", session.peername);
			running = 0;
			exitval = 1;
		}
		else
		{				/* status == STAT_ERROR */
			snmp_sess_perror("snmpwalk", ss);
			running = 0;
			exitval = 1;
		}

		if (response)
		{
			snmp_free_pdu(response);
		}
	}

	snmp_close(ss);
	SOCK_CLEANUP;
	return exitval;
}
