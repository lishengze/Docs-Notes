/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSnmptrap.cpp
///@brief	实现了CSnmptrap类，接收trap数据包。
///@history
///20101008	LSC		创建该文件
/////////////////////////////////////////////////////////////////////////
#include "CSnmptrap.h"
#include "systools.h"
#include "Pdutostr.h"

const char	*conf = "snmptrapd.conf";

//存储trap数据包列表
TemplateMutexCatch<string>	g_listtrapdata;
CPdutostr g_pdutostr;

CSnmptrap::CSnmptrap(void)
{
	default_port = DEFAULT_PORT;

#if HAVE_GETPID
	PID = NULL;
	pid_file = NULL;
#endif
	sess_list = NULL;
	m_pauth = NULL;
}

CSnmptrap::~CSnmptrap(void)
{
	//是否要清除listcache的内容
	//if(m_pauth != NULL)
	//{
	//	delete m_pauth;
	//	m_pauth = NULL;
	//}
}

int oidtostr(
	oid *srcOid,
	unsigned long size,
	char *outString,
	size_t	&how_many_bytes)
{
	assert(outString != NULL);
	outString[0] = 0;

	// verify there is something to copy
	if (size == 0)
	{
		return 0;
	}

	sprintf(outString, "%lu", srcOid[0]);
	for (int index = 1; index < size; index++)
	{
		sprintf(outString + strlen(outString), ".%lu", srcOid[index]);
	}

	how_many_bytes = strlen(outString);
	return 1;
}

int sprint_variable(char *buffer, const netsnmp_variable_list *var)
{
	assert(buffer != NULL && var != NULL);

	size_t	size = 0;
	u_char	*ip;

	oidtostr(var->name, var->name_length, buffer, size);
	buffer[size] = ':';
	size = size + 1;

	//printf("111  buffer=%s \n",buffer);
	switch (var->type)
	{
		case ASN_INTEGER:
			sprintf(buffer + size, "%ld", *var->val.integer);
			break;
		case ASN_OCTET_STR:
			memcpy(buffer + size, var->val.string, min(sizeof(1023), var->val_len));
			break;
		case ASN_BIT_STR:
			memcpy(
				buffer + size,
				var->val.bitstring,
				min(sizeof(1023), var->val_len));
			break;

			//sprint_realloc_bitstring(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_OPAQUE:
			memcpy(buffer + size, var->val.string, min(sizeof(1023), var->val_len));
			break;

			//sprint_realloc_opaque(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_OBJECT_ID:
			snprint_objid(
				buffer + size,
				sizeof(1023),
				var->val.objid,
				var->val_len / sizeof(oid));
			break;

			//sprint_realloc_object_identifier(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_TIMETICKS:
			sprintf(buffer + size, "%lu", *(u_long *)var->val.integer);
			break;

			//sprint_realloc_timeticks(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_GAUGE:
			sprintf(buffer + size, "%lu", *var->val.integer);
			break;

			//sprint_realloc_gauge(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_COUNTER:
			sprintf(buffer + size, "%lu", *var->val.integer);
			break;

			//sprint_realloc_counter(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_IPADDRESS:
			ip = var->val.string;
			if (ip)
			{
				sprintf(buffer + size, "%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
			}

			break;

			//sprint_realloc_ipaddress(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_NULL:
			strcpy(buffer + size, "NULL");
			break;

			//sprint_realloc_null(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_UINTEGER:
			sprintf(buffer + size, "%lu", *var->val.integer);
			break;	//sprint_realloc_uinteger(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
	#ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
		case ASN_OPAQUE_I64:
			printI64(buffer + size, var->val.counter64);
			break;

			//sprint_realloc_counter64(buf, buf_len, out_len, allow_realloc, var, NULL, NULL, NULL);
		case ASN_OPAQUE_U64:
		case ASN_OPAQUE_COUNTER64:
	#endif \
		\
		/* NETSNMP_WITH_OPAQUE_SPECIAL_TYPES */
		case ASN_COUNTER64:
			printU64(buffer + size, var->val.counter64);
			break;

	#ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
		case ASN_OPAQUE_FLOAT:
			sprintf(buffer + size, "%f", *var->val.floatVal);
			break;
		case ASN_OPAQUE_DOUBLE:
			sprintf(buffer + size, "%f", *var->val.doubleVal);
			break;
	#endif \
		\
		/* NETSNMP_WITH_OPAQUE_SPECIAL_TYPES */
		case SNMP_NOSUCHOBJECT:
			printf("No Such Object available on this agent at this OID\n");
			break;

			//snmp_strcat(buf, buf_len, out_len, allow_realloc, (const u_char *)"No Such Object available on this agent at this OID");
		case SNMP_NOSUCHINSTANCE:
			printf("No Such Instance currently exists at this OID\n");
			break;

			//snmp_strcat(buf, buf_len, out_len, allow_realloc, (const u_char *)"No Such Instance currently exists at this OID");
		case SNMP_ENDOFMIBVIEW:
			printf(
				"No more variables left in this MIB View (It is past the end of the MIB tree)\n");
			break;
		default:
			printf("Variable has bad type\n");
			break;
	}

	//printf("222  buffer=%s \n",buffer);
	return 1;
}

int traptostring(netsnmp_pdu *pdu, netsnmp_transport *transport)
{
	size_t	i;
	size_t	size;

	//关键字信息
	char comm[64] = "\0";
	if (pdu->community_len + 1 < 64)
	{
		for (i = 0; i < pdu->community_len; i++)
		{
			comm[i] = pdu->community[i];
		}
	}
	else
	{
		printf("the community length is overflow.\n");
	}

	snmp_log(LOG_INFO, "community=%s \n", comm);

	//时间信息，以ticks计数
	char buf_time[64] = "\0";
	sprintf(buf_time, "%lu ticks", pdu->time);
	snmp_log(LOG_INFO, "time=%s \n", buf_time);

	//transport domain信息
	char buf_domain[64] = "\0";
	oidtostr (
		const_cast<oid *>(pdu->tDomain),
		pdu->tDomainLen,
		buf_domain,
		size);
	snmp_log(LOG_INFO, "Domain=%s \n", buf_domain);

	//System OID信息
	char buf_enterprise[64] = "\0";
	oidtostr(pdu->enterprise, pdu->enterprise_length, buf_enterprise, size);
	snmp_log(LOG_INFO, "enterprise=%s \n", buf_enterprise);

	//transport_data信息
	char *tstr_transport_data = transport->f_fmtaddr(
			transport,
			pdu->transport_data,
			pdu->transport_data_length);
	snmp_log(LOG_INFO, "transport_data=%s \n", tstr_transport_data);

	//变量列表信息
	netsnmp_variable_list *vars;
	list<string> variables;
	for (vars = pdu->variables; vars != NULL; vars = vars->next_variable)
	{
		char var_buf[1024] = "\0";
		if (!sprint_variable(var_buf, vars))
		{
			return 0;
		}

		//printf("***** vars_buf=%s \n",string(var_buf).c_str());
		//variables.append(var_buf);
		//variables.append((char *)vars->buf);
		//printf("variables = %s.\n",variables.c_str());
		variables.push_back(string(var_buf));
	}

	char vars_buff[1024] = "\0";
	int index = 0;
	for (list<string>::iterator it = variables.begin();
		 it != variables.end();
		 it++)
	{
		sprintf(vars_buff + index, "%s,", it->c_str());
		index = index + it->length() + 1;
	}

	vars_buff[index - 1] = '\0';
	printf("vars_buff = %s.\n", vars_buff);

	char buffer[1024] = "\0";
	sprintf(
		buffer,
		"version=%ld;command=%d;reqid=%ld;msgid=%ld;transid=%ld;sessid=%ld;errstat=%ld;errindex=%ld \n"
		"securityModel=%d;securityLevel=%d;msgParseModel=%d;trap_type=%ld;specific_type=%ld \n"
		"AgentX fields:priority=%d;AgentX fields:range_subid=%d;community=%s;time=%s;Domain=%s \n"
		"enterprise=%s;transport_data=%s;variables=%s \n",
		pdu->version,
		pdu->command,
		pdu->reqid,
		pdu->msgid,
		pdu->transid,
		pdu->sessid,
		pdu->errstat,
		pdu->errindex,
		pdu->securityModel,
		pdu->securityLevel,
		pdu->msgParseModel,
		pdu->trap_type,
		pdu->specific_type,
		pdu->priority,
		pdu->range_subid,
		comm,
		buf_time,
		buf_domain,
		buf_enterprise,
		tstr_transport_data,
		vars_buff);

	snmp_log(LOG_INFO, "%s", buffer);
	g_listtrapdata.add(string((char *)buffer));

	printf("the count of trapdata is %d.\n", g_listtrapdata.size());
	return NETSNMPTRAPD_HANDLER_OK;
}

/*
 *  Trap handler for restore in cache
 */
int CSnmptrap::restore_handler(
	netsnmp_pdu *pdu,
	netsnmp_transport *transport,
	netsnmp_trapd_handler *handler)
{
	return traptostring(pdu, transport);

	/////////////////////支持特定格式输出
	u_char	*rbuf = NULL;
	size_t	r_len = 64;
	size_t	o_len = 0;
	int trunc = 0;

	if ((rbuf = (u_char *)calloc(r_len, 1)) == NULL)
	{
		snmp_log(LOG_ERR, "couldn't display trap -- malloc failed\n");
		return NETSNMPTRAPD_HANDLER_FAIL;		/* Failed but keep going */
	}

	//If there's a format string registered for this trap, then use it
	if (handler != NULL && handler->format != NULL)
	{
		trunc = g_pdutostr.format_trap(
				&rbuf,
				&r_len,
				&o_len,
				1,
				handler->format,
				pdu,
				transport);
		printf("At present,do not support the formatting of the handler");
	}
	else
	{
		if (pdu->command == SNMP_MSG_TRAP)
		{
			DEBUGMSGTL(("snmptrapd", "v1 format\n"));
			trunc = g_pdutostr.format_plain_trap(
					&rbuf,
					&r_len,
					&o_len,
					1,
					pdu,
					transport);
		}
		else
		{
			DEBUGMSGTL(("snmptrapd", "v2/3 format\n"));
			trunc = g_pdutostr.format_trap(
					&rbuf,
					&r_len,
					&o_len,
					1,
					PRINT_V23_NOTIFICATION_FORMAT,
					pdu,
					transport);
		}
	}

	snmp_log(LOG_INFO, "%s%s", rbuf, (trunc ? " [TRUNCATED]\n" : ""));

	g_listtrapdata.add(string((char *)rbuf));

	printf("the count of trapdata is %d.\n", g_listtrapdata.size());
	free(rbuf);

	return NETSNMPTRAPD_HANDLER_OK;
}

netsnmp_session *CSnmptrap::snmptrapd_add_session(netsnmp_transport *t)
{
	netsnmp_session sess;

	netsnmp_session *session = &sess;

	netsnmp_session *rc = NULL;

	snmp_sess_init(session);
	session->peername = SNMP_DEFAULT_PEERNAME;	/* Original code had NULL here */
	session->version = SNMP_DEFAULT_VERSION;
	session->community_len = SNMP_DEFAULT_COMMUNITY_LEN;
	session->retries = SNMP_DEFAULT_RETRIES;
	session->timeout = SNMP_DEFAULT_TIMEOUT;
	session->callback = snmp_input;
	session->callback_magic = (void *)t;
	session->authenticator = NULL;
	sess.isAuthoritative = SNMP_SESS_UNKNOWNAUTH;

	rc = snmp_add(session, t, NULL, NULL);
	if (rc == NULL)
	{
		snmp_sess_perror("snmptrapd", session);
	}

	return rc;
}

void CSnmptrap::snmptrapd_close_sessions(netsnmp_session *sess_list)
{
	netsnmp_session *s = NULL;

	netsnmp_session *next = NULL;

	for (s = sess_list; s != NULL; s = next)
	{
		next = s->next;
		snmp_close(s);
	}
}

/*******************************************************************
 * 初始化，主要包括读配置文件、socket启动、创建会话
 *******************************************************************/
void CSnmptrap::init(void)
{
	netsnmp_transport *transport = NULL;
	netsnmp_trapd_handler *traph;

#ifdef WIN32
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
#else
	setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
#endif

	//读取配置信息
	netsnmp_ds_set_string(
		NETSNMP_DS_LIBRARY_ID,
		NETSNMP_DS_LIB_OPTIONALCONFIG,
		conf);

	if (snmp_log_options("o", 0, NULL) < 0)
	{
		exit(1);
	}

	SOCK_STARTUP;

	m_pauth = new CSnmptrap_auth();
	if (m_pauth == NULL)
	{
		printf("warning : failed to initilize the object!");
	}

	traph = CSnmptrap_handler::netsnmp_add_global_traphandler(
			NETSNMPTRAPD_PRE_HANDLER,
			restore_handler);

	traph->authtypes = TRAP_AUTH_LOG;

	/* register our authorization handler */
	m_pauth->init_netsnmp_trapd_auth();

	// Initialize the world.
	init_snmp("snmptrapd");

	//创建session会话
	transport = netsnmp_transport_open_server("snmptrap", default_port);
	if (transport == NULL)
	{
		snmp_log(
			LOG_ERR,
			"couldn't open %s -- errno %d (\"%s\")\n",
			default_port,
			errno,
			strerror(errno));
		snmptrapd_close_sessions(sess_list);
		SOCK_CLEANUP;
		exit(1);
	}
	else
	{
		sess_list = snmptrapd_add_session(transport);
		if (sess_list == NULL)
		{
			// Shouldn't happen?  We have already opened the transport
			// successfully so what could have gone wrong?
			snmptrapd_close_sessions(sess_list);
			netsnmp_transport_free(transport);
			snmp_log(LOG_ERR, "couldn't open snmp - %s", strerror(errno));
			SOCK_CLEANUP;
			exit(1);
		}
	}

#if HAVE_GETPID
	if (pid_file != NULL)
	{
		if ((PID = fopen(pid_file, "w")) == NULL)
		{
			snmp_log_perror("fopen");
			exit(1);
		}

		fprintf(PID, "%d\n", (int)getpid());
		fclose(PID);
	}

#endif
	netsnmp_running = 1;

	snmp_log(LOG_INFO, "NET-SNMP version %s\n", netsnmp_get_version());
}

/*
* Setup and start the trap receiver daemon.
* 启动接收trap数据循环
*/
void CSnmptrap::run(void)
{
	int count;

	int numfds;

	int block;
	fd_set	readfds;
	fd_set	writefds;
	fd_set	exceptfds;
	struct timeval	timeout;
	struct timeval	*tvp;
	struct timeval	Now;

	init();

	while (netsnmp_running)
	{
		numfds = 0;
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		FD_ZERO(&exceptfds);
		block = 0;
		tvp = &timeout;
		timerclear(tvp);
		tvp->tv_sec = 5;
		snmp_select_info(&numfds, &readfds, tvp, &block);
		if (block == 1)
		{
			tvp = NULL; /* block without timeout */
		}

		netsnmp_external_event_info(&numfds, &readfds, &writefds, &exceptfds);
		count = select(numfds, &readfds, &writefds, &exceptfds, tvp);

		gettimeofday(&Now, NULL);
		if (count > 0)
		{
			netsnmp_dispatch_external_events(
				&count,
				&readfds,
				&writefds,
				&exceptfds);

			/* If there are any more events after external events, then
			* try SNMP events. */
			if (count > 0)
			{
				snmp_read(&readfds);
			}
		}
		else
		{
			switch (count)
			{
				case 0:
					snmp_timeout();
					break;
				case -1:
					if (errno == EINTR)
					{
						continue;
					}

					snmp_log_perror("select");
					netsnmp_running = 0;
					break;
				default:
					fprintf(stderr, "select returned %d\n", count);
					netsnmp_running = 0;
			}
		}
	}

	snmp_log(LOG_INFO, "Stopping snmptrapd\n");

	snmptrapd_close_sessions(sess_list);
	snmp_shutdown("snmptrapd");

	snmp_disable_log();
	SOCK_CLEANUP;
}
