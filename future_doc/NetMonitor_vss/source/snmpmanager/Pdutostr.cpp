/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	Pdutostr.cpp
///@brief	实现将接收到的trap信息中的Pdu结构转换成string
///@history
///20101101	LSC	create
/////////////////////////////////////////////////////////////////////////
#include "Pdutostr.h"

const char *CPdutostr::trap_description(int trap)
{
	switch (trap)
	{
		case SNMP_TRAP_COLDSTART:
			return "Cold Start";
		case SNMP_TRAP_WARMSTART:
			return "Warm Start";
		case SNMP_TRAP_LINKDOWN:
			return "Link Down";
		case SNMP_TRAP_LINKUP:
			return "Link Up";
		case SNMP_TRAP_AUTHFAIL:
			return "Authentication Failure";
		case SNMP_TRAP_EGPNEIGHBORLOSS:
			return "EGP Neighbor Loss";
		case SNMP_TRAP_ENTERPRISESPECIFIC:
			return "Enterprise Specific";
		default:
			return "Unknown Type";
	}
}

void CPdutostr::init_options(options_type *options)
{
	options->cmd = '*';
	options->width = 0;
	options->precision = UNDEF_PRECISION;
	options->left_justify = FALSE;
	options->alt_format = FALSE;
	options->leading_zeroes = FALSE;
	return;
}

int CPdutostr::realloc_dispatch_format_cmd(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	options_type *options,
	netsnmp_pdu *pdu,
	netsnmp_transport *transport)
{
	char fmt_cmd = options->cmd;	/* for speed */

	/*
     * choose the appropriate command handler 
     */
	if (is_cur_time_cmd(fmt_cmd) || is_up_time_cmd(fmt_cmd))
	{
		return realloc_handle_time_fmt(
				buf,
				buf_len,
				out_len,
				allow_realloc,
				options,
				pdu);
	}
	else if (is_agent_cmd(fmt_cmd) || is_pdu_ip_cmd(fmt_cmd))
	{
		return realloc_handle_ip_fmt(
				buf,
				buf_len,
				out_len,
				allow_realloc,
				options,
				pdu,
				transport);
	}
	else if (is_trap_cmd(fmt_cmd))
	{
		return realloc_handle_trap_fmt(
				buf,
				buf_len,
				out_len,
				allow_realloc,
				options,
				pdu);
	}
	else if (is_auth_cmd(fmt_cmd))
	{
		return realloc_handle_auth_fmt(
				buf,
				buf_len,
				out_len,
				allow_realloc,
				options,
				pdu);
	}
	else if (fmt_cmd == CHR_PDU_ENT || fmt_cmd == CHR_TRAP_CONTEXTID)
	{
		return realloc_handle_ent_fmt(
				buf,
				buf_len,
				out_len,
				allow_realloc,
				options,
				pdu);
	}
	else if (fmt_cmd == CHR_PDU_WRAP)
	{
		return realloc_handle_wrap_fmt(
				buf,
				buf_len,
				out_len,
				allow_realloc,
				pdu);
	}
	else
	{
		/*
         * unknown format command - just output the character 
         */
		char fmt_cmd_string[2] = { 0, 0 };
		fmt_cmd_string[0] = fmt_cmd;

		return snmp_strcat(
				buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)fmt_cmd_string);
	}
}

int CPdutostr::realloc_handle_time_fmt(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	options_type *options,
	netsnmp_pdu *pdu)
{
	time_t	time_val;				/* the time value to output */
	unsigned long time_ul;			/* u_long time/timeticks */
	struct tm parsed_time;			/* parsed version of current time */
	char *safe_bfr = NULL;
	char fmt_cmd = options->cmd;	/* the format command to use */
	int offset = 0;					/* offset into string to display */
	size_t	year_len;				/* length of year string */

	if ((safe_bfr = (char *)calloc(30, 1)) == NULL)
	{
		return 0;
	}

	//  Get the time field to output.
	if (is_up_time_cmd(fmt_cmd))
	{
		time_ul = pdu->time;
	}
	else
	{
		time(&time_val);
		time_ul = (unsigned long)time_val;
	}

	/*
     * Handle output in Unix time format.  
     */
	if (fmt_cmd == CHR_CUR_TIME)
	{
		sprintf(safe_bfr, "%lu", time_ul);
	}
	else if (fmt_cmd == CHR_UP_TIME && !options->alt_format)
	{
		sprintf(safe_bfr, "%lu", time_ul);
	}
	else if (fmt_cmd == CHR_UP_TIME)
	{
		unsigned int centisecs;

		unsigned int seconds;

		unsigned int minutes;

		unsigned int hours;

		unsigned int days;

		centisecs = time_ul % 100;
		time_ul /= 100;
		days = time_ul / (60 * 60 * 24);
		time_ul %= (60 * 60 * 24);

		hours = time_ul / (60 * 60);
		time_ul %= (60 * 60);

		minutes = time_ul / 60;
		seconds = time_ul % 60;

		switch (days)
		{
			case 0:
				sprintf(
					safe_bfr,
					"%u:%02u:%02u.%02u",
					hours,
					minutes,
					seconds,
					centisecs);
				break;
			case 1:
				sprintf(
					safe_bfr,
					"1 day, %u:%02u:%02u.%02u",
					hours,
					minutes,
					seconds,
					centisecs);
				break;
			default:
				sprintf(
					safe_bfr,
					"%u days, %u:%02u:%02u.%02u",
					days,
					hours,
					minutes,
					seconds,
					centisecs);
		}
	}
	else
	{
		if (options->alt_format)
		{
			GMTime(&time_val, &parsed_time);
		}
		else
		{
			LocalTime(&time_val, &parsed_time);
		}

		switch (fmt_cmd)
		{
			case CHR_CUR_YEAR:
			case CHR_UP_YEAR:
				sprintf(safe_bfr, "%d", parsed_time.tm_year + 1900);
				if (options->precision != UNDEF_PRECISION)
				{
					year_len = (size_t) strlen(safe_bfr);
					if (year_len > options->precision)
					{
						offset = year_len - options->precision;
					}
				}

				break;
			case CHR_CUR_MONTH:
			case CHR_UP_MONTH:
				sprintf(safe_bfr, "%d", parsed_time.tm_mon + 1);
				break;
			case CHR_CUR_MDAY:
			case CHR_UP_MDAY:
				sprintf(safe_bfr, "%d", parsed_time.tm_mday);
				break;
			case CHR_CUR_HOUR:
			case CHR_UP_HOUR:
				sprintf(safe_bfr, "%d", parsed_time.tm_hour);
				break;
			case CHR_CUR_MIN:
			case CHR_UP_MIN:
				sprintf(safe_bfr, "%d", parsed_time.tm_min);
				break;
			case CHR_CUR_SEC:
			case CHR_UP_SEC:
				sprintf(safe_bfr, "%d", parsed_time.tm_sec);
				break;
			default:
				sprintf(safe_bfr, "%c", fmt_cmd);
		}
	}

	return realloc_output_temp_bfr(
			buf,
			buf_len,
			out_len,
			allow_realloc,
			(u_char **) &safe_bfr,
			options);
}

int CPdutostr::realloc_output_temp_bfr(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	u_char	**temp_buf,
	options_type *options)
{
	size_t	temp_len;				/* length of temporary buffer */
	size_t	temp_to_write;			/* # of chars to write from temp bfr */
	size_t	char_to_write;			/* # of other chars to write */
	size_t	zeroes_to_write;		/* fill to precision with zeroes for numbers */

	if (temp_buf == NULL || *temp_buf == NULL)
	{
		return 1;
	}

	temp_len = strlen((char *) *temp_buf);
	temp_to_write = temp_len;

	if (options->precision != UNDEF_PRECISION
	&&	temp_to_write > options->precision)
	{
		temp_to_write = options->precision;
	}

	if ((!options->left_justify) && (temp_to_write < options->width))
	{
		zeroes_to_write = options->precision - temp_to_write;
		if (!is_numeric_cmd(options->cmd))
		{
			zeroes_to_write = 0;
		}

		for (char_to_write = options->width - temp_to_write;
			 char_to_write > 0;
			 char_to_write--)
		{
			if ((*out_len + 1) >= *buf_len)
			{
				if (!(allow_realloc && snmp_realloc(buf, buf_len)))
				{
					*(*buf +*out_len) = '\0';
					free(*temp_buf);
					return 0;
				}
			}

			if (options->leading_zeroes || zeroes_to_write-- > 0)
			{
				*(*buf +*out_len) = '0';
			}
			else
			{
				*(*buf +*out_len) = ' ';
			}

			(*out_len)++;
		}
	}

	/*
     * Truncate the temporary buffer and append its contents.  
     */
	*(*temp_buf + temp_to_write) = '\0';
	if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, *temp_buf))
	{
		free(*temp_buf);
		return 0;
	}

	/*
     * Handle trailing characters.  
     */
	if ((options->left_justify) && (temp_to_write < options->width))
	{
		for (char_to_write = options->width - temp_to_write;
			 char_to_write > 0;
			 char_to_write--)
		{
			if ((*out_len + 1) >= *buf_len)
			{
				if (!(allow_realloc && snmp_realloc(buf, buf_len)))
				{
					*(*buf +*out_len) = '\0';
					free(*temp_buf);
					return 0;
				}
			}

			*(*buf +*out_len) = '0';
			(*out_len)++;
		}
	}

	*(*buf +*out_len) = '\0';
	free(*temp_buf);
	*temp_buf = NULL;
	return 1;
}

int CPdutostr::realloc_handle_backslash(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	char fmt_cmd)
{
	char temp_bfr[3];				/* for bulding temporary strings */

	/*
     * select the proper output character(s) 
     */
	switch (fmt_cmd)
	{
		case 'a':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\a");
		case 'b':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\b");
		case 'f':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\f");
		case 'n':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\n");
		case 'r':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\r");
		case 't':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\t");
		case 'v':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\v");
		case '\\':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\\");
		case '?':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"?");
		case '%':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"%");
		case '\'':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\'");
		case '"':
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)"\"");
		default:
			sprintf(temp_bfr, "\\%c", fmt_cmd);
			return snmp_strcat(
					buf,
					buf_len,
					out_len,
					allow_realloc,
					(const u_char *)temp_bfr);
	}
}

int CPdutostr::realloc_handle_wrap_fmt(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	netsnmp_pdu *pdu)
{
	size_t	i = 0;

	switch (pdu->command)
	{
		case SNMP_MSG_TRAP:
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)"TRAP"))
			{
				return 0;
			}

			break;
		case SNMP_MSG_TRAP2:
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)"TRAP2"))
			{
				return 0;
			}

			break;
		case SNMP_MSG_INFORM:
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)"INFORM"))
			{
				return 0;
			}

			break;
	}

	switch (pdu->version)
	{
	#ifndef NETSNMP_DISABLE_SNMPV1
		case SNMP_VERSION_1:
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)", SNMP v1"))
			{
				return 0;
			}

			break;
	#endif
	#ifndef NETSNMP_DISABLE_SNMPV2C
		case SNMP_VERSION_2c:
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)", SNMP v2c"))
			{
				return 0;
			}

			break;
	#endif
		case SNMP_VERSION_3:
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)", SNMP v3"))
			{
				return 0;
			}

			break;
	}

	switch (pdu->version)
	{
	#ifndef NETSNMP_DISABLE_SNMPV1
		case SNMP_VERSION_1:
	#endif
	#ifndef NETSNMP_DISABLE_SNMPV2C
		case SNMP_VERSION_2c:
	#endif
	#if !defined(NETSNMP_DISABLE_SNMPV1) || !defined(NETSNMP_DISABLE_SNMPV2C)
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)", community "))
			{
				return 0;
			}

			while ((*out_len + pdu->community_len + 1) >= *buf_len)
			{
				if (!(allow_realloc && snmp_realloc(buf, buf_len)))
				{
					return 0;
				}
			}

			for (i = 0; i < pdu->community_len; i++)
			{
				if (isprint(pdu->community[i]))
				{
					*(*buf +*out_len) = pdu->community[i];
				}
				else
				{
					*(*buf +*out_len) = '.';
				}

				(*out_len)++;
			}

			*(*buf +*out_len) = '\0';
			break;
	#endif
		case SNMP_VERSION_3:
			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)", user "))
			{
				return 0;
			}

			while ((*out_len + pdu->securityNameLen + 1) >= *buf_len)
			{
				if (!(allow_realloc && snmp_realloc(buf, buf_len)))
				{
					return 0;
				}
			}

			for (i = 0; i < pdu->securityNameLen; i++)
			{
				if (isprint(pdu->securityName[i]))
				{
					*(*buf +*out_len) = pdu->securityName[i];
				}
				else
				{
					*(*buf +*out_len) = '.';
				}

				(*out_len)++;
			}

			*(*buf +*out_len) = '\0';

			if (!snmp_strcat(
					buf,
				buf_len,
				out_len,
				allow_realloc,
				(const u_char *)", context "))
			{
				return 0;
			}

			while ((*out_len + pdu->contextNameLen + 1) >= *buf_len)
			{
				if (!(allow_realloc && snmp_realloc(buf, buf_len)))
				{
					return 0;
				}
			}

			for (i = 0; i < pdu->contextNameLen; i++)
			{
				if (isprint(pdu->contextName[i]))
				{
					*(*buf +*out_len) = pdu->contextName[i];
				}
				else
				{
					*(*buf +*out_len) = '.';
				}

				(*out_len)++;
			}

			*(*buf +*out_len) = '\0';
	}

	return 1;
}

int CPdutostr::realloc_handle_ip_fmt(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	options_type *options,
	netsnmp_pdu *pdu,
	netsnmp_transport *transport)
{
	struct in_addr	*agent_inaddr = (struct in_addr *)pdu->agent_addr;
	struct hostent	*host = NULL;	/* corresponding host name */
	char fmt_cmd = options->cmd;	/* what we're formatting */
	u_char	*temp_buf = NULL;
	size_t	temp_buf_len = 64;
	size_t	temp_out_len = 0;
	char *tstr;
	unsigned int oflags;

	if ((temp_buf = (u_char *)calloc(temp_buf_len, 1)) == NULL)
	{
		return 0;
	}

	/*
     * Decide exactly what to output.  
     */
	switch (fmt_cmd)
	{
		case CHR_AGENT_IP:
			/*
         * Write a numerical address.  
         */
			if (!snmp_strcat(
					&temp_buf,
				&temp_buf_len,
				&temp_out_len,
				1,
				(u_char *)inet_ntoa(*agent_inaddr)))
			{
				if (temp_buf != NULL)
				{
					free(temp_buf);
				}

				return 0;
			}

			break;
		case CHR_AGENT_NAME:
			/*
         * Try to resolve the agent_addr field as a hostname; fall back
         * to numerical address.  
         */
			if (!netsnmp_ds_get_boolean(
					NETSNMP_DS_APPLICATION_ID,
				NETSNMP_DS_APP_NUMERIC_IP))
			{
				host = gethostbyaddr((char *)pdu->agent_addr, 4, AF_INET);
			}

			if (host != NULL)
			{
				if (!snmp_strcat(
						&temp_buf,
					&temp_buf_len,
					&temp_out_len,
					1,
					(u_char *)host->h_name))
				{
					if (temp_buf != NULL)
					{
						free(temp_buf);
					}

					return 0;
				}
			}
			else
			{
				if (!snmp_strcat(
						&temp_buf,
					&temp_buf_len,
					&temp_out_len,
					1,
					(u_char *)inet_ntoa(*agent_inaddr)))
				{
					if (temp_buf != NULL)
					{
						free(temp_buf);
					}

					return 0;
				}
			}

			break;
		case CHR_PDU_IP:
			/*
         * Write the numerical transport information.  
         */
			if (transport != NULL && transport->f_fmtaddr != NULL)
			{
				oflags = transport->flags;
				transport->flags &= ~NETSNMP_TRANSPORT_FLAG_HOSTNAME;
				tstr = transport->f_fmtaddr(
						transport,
						pdu->transport_data,
						pdu->transport_data_length);
				transport->flags = oflags;

				if (!tstr)
				{
					goto noip;
				}

				if (!snmp_strcat(
						&temp_buf,
					&temp_buf_len,
					&temp_out_len,
					1,
					(u_char *)tstr))
				{
					SNMP_FREE(temp_buf);
					SNMP_FREE(tstr);
					return 0;
				}

				SNMP_FREE(tstr);
			}
			else
			{
	noip:
				if (!snmp_strcat(
						&temp_buf,
					&temp_buf_len,
					&temp_out_len,
					1,
					(const u_char *)"<UNKNOWN>"))
				{
					SNMP_FREE(temp_buf);
					return 0;
				}
			}

			break;
		case CHR_PDU_NAME:
			/*
         * Try to convert the numerical transport information
         *  into a hostname.  Or rather, have the transport-specific
         *  address formatting routine do this.
         * Otherwise falls back to the numeric address format.
         */
			if (transport != NULL && transport->f_fmtaddr != NULL)
			{
				oflags = transport->flags;
				if (!netsnmp_ds_get_boolean(
						NETSNMP_DS_APPLICATION_ID,
					NETSNMP_DS_APP_NUMERIC_IP))
				{
					transport->flags |= NETSNMP_TRANSPORT_FLAG_HOSTNAME;
				}

				tstr = transport->f_fmtaddr(
						transport,
						pdu->transport_data,
						pdu->transport_data_length);
				transport->flags = oflags;

				if (!tstr)
				{
					goto nohost;
				}

				if (!snmp_strcat(
						&temp_buf,
					&temp_buf_len,
					&temp_out_len,
					1,
					(u_char *)tstr))
				{
					SNMP_FREE(temp_buf);
					SNMP_FREE(tstr);
					return 0;
				}

				SNMP_FREE(tstr);
			}
			else
			{
	nohost:
				if (!snmp_strcat(
						&temp_buf,
					&temp_buf_len,
					&temp_out_len,
					1,
					(const u_char *)"<UNKNOWN>"))
				{
					SNMP_FREE(temp_buf);
					return 0;
				}
			}

			break;

		/*
         * Don't know how to handle this command - write the character itself.  
         */
		default:
			temp_buf[0] = fmt_cmd;
	}

	/*
     * Output with correct justification, leading zeroes, etc.  
     */
	return realloc_output_temp_bfr(
			buf,
			buf_len,
			out_len,
			allow_realloc,
			&temp_buf,
			options);
}

int CPdutostr::realloc_handle_ent_fmt(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	options_type *options,
	netsnmp_pdu *pdu)
{
	char fmt_cmd = options->cmd;	/* what we're formatting */
	u_char	*temp_buf = NULL;
	size_t	temp_buf_len = 64;
	size_t	temp_out_len = 0;

	if ((temp_buf = (u_char *)calloc(temp_buf_len, 1)) == NULL)
	{
		return 0;
	}

	/*
     * Decide exactly what to output.  
     */
	switch (fmt_cmd)
	{
		case CHR_PDU_ENT:
			/*
         * Write the enterprise oid.  
         */
			if (!sprint_realloc_objid(
					&temp_buf,
				&temp_buf_len,
				&temp_out_len,
				1,
				pdu->enterprise,
				pdu->enterprise_length))
			{
				free(temp_buf);
				return 0;
			}

			break;
		case CHR_TRAP_CONTEXTID:
			/*
         * Write the context oid.  
         */
			if (!sprint_realloc_hexstring(
					&temp_buf,
				&temp_buf_len,
				&temp_out_len,
				1,
				pdu->contextEngineID,
				pdu->contextEngineIDLen))
			{
				free(temp_buf);
				return 0;
			}

			break;

		/*
         * Don't know how to handle this command - write the character itself.  
         */
		default:
			temp_buf[0] = fmt_cmd;
	}

	/*
     * Output with correct justification, leading zeroes, etc.  
     */
	return realloc_output_temp_bfr(
			buf,
			buf_len,
			out_len,
			allow_realloc,
			&temp_buf,
			options);
}

int CPdutostr::realloc_handle_trap_fmt(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	options_type *options,
	netsnmp_pdu *pdu)
{
	netsnmp_variable_list *vars;	/* variables assoc with trap */
	char fmt_cmd = options->cmd;	/* what we're outputting */
	u_char	*temp_buf = NULL;
	size_t	tbuf_len = 64;
	size_t	tout_len = 0;
	const char	*sep = separator;
	const char	*default_sep = "\t";
	const char	*default_alt_sep = ", ";

	if ((temp_buf = (u_char *)calloc(tbuf_len, 1)) == NULL)
	{
		return 0;
	}

	/*
     * Decide exactly what to output.  
     */
	switch (fmt_cmd)
	{
		case CHR_TRAP_NUM:
			/*
         * Write the trap's number.  
         */
			tout_len = sprintf((char *)temp_buf, "%ld", pdu->trap_type);
			break;
		case CHR_TRAP_DESC:
			/*
         * Write the trap's description.  
         */
			tout_len = sprintf(
					(char *)temp_buf,
					"%s",
					trap_description(pdu->trap_type));
			break;
		case CHR_TRAP_STYPE:
			/*
         * Write the trap's subtype.  
         */
			if (pdu->trap_type != SNMP_TRAP_ENTERPRISESPECIFIC)
			{
				tout_len = sprintf((char *)temp_buf, "%ld", pdu->specific_type);
			}
			else
			{
				/*
             * Get object ID for the trap.  
             */
				size_t	obuf_len = 64;

				/*
             * Get object ID for the trap.  
             */
				size_t	oout_len = 0;

				/*
             * Get object ID for the trap.  
             */
				size_t	trap_oid_len = 0;
				oid trap_oid[MAX_OID_LEN + 2] = { 0 };
				u_char	*obuf = NULL;
				char *ptr = NULL;

				if ((obuf = (u_char *)calloc(obuf_len, 1)) == NULL)
				{
					free(temp_buf);
					return 0;
				}

				trap_oid_len = pdu->enterprise_length;
				memcpy(trap_oid, pdu->enterprise, trap_oid_len * sizeof(oid));
				if (trap_oid[trap_oid_len - 1] != 0)
				{
					trap_oid[trap_oid_len] = 0;
					trap_oid_len++;
				}

				trap_oid[trap_oid_len] = pdu->specific_type;
				trap_oid_len++;

				/*
             * Find the element after the last dot.  
             */
				if (!sprint_realloc_objid(
						&obuf,
					&obuf_len,
					&oout_len,
					1,
					trap_oid,
					trap_oid_len))
				{
					if (obuf != NULL)
					{
						free(obuf);
					}

					free(temp_buf);
					return 0;
				}

				ptr = strrchr((char *)obuf, '.');
				if (ptr != NULL)
				{
					if (!snmp_strcat(
							&temp_buf,
						&tbuf_len,
						&tout_len,
						1,
						(u_char *)ptr))
					{
						free(obuf);
						if (temp_buf != NULL)
						{
							free(temp_buf);
						}

						return 0;
					}

					free(obuf);
				}
				else
				{
					free(temp_buf);
					temp_buf = obuf;
					tbuf_len = obuf_len;
					tout_len = oout_len;
				}
			}

			break;
		case CHR_TRAP_VARS:
			/*
         * Write the trap's variables.  
         */
			if (!sep || !*sep)
			{
				sep = (options->alt_format ? default_alt_sep : default_sep);
			}

			for (vars = pdu->variables; vars != NULL; vars = vars->next_variable)
			{
				/*
             * Print a separator between variables,
             *   (plus beforehand if the alt format is used)
             */
				if (options->alt_format || vars != pdu->variables)
				{
					if (!snmp_strcat(
							&temp_buf,
						&tbuf_len,
						&tout_len,
						1,
						(const u_char *)sep))
					{
						if (temp_buf != NULL)
						{
							free(temp_buf);
						}

						return 0;
					}
				}

				if (!sprint_realloc_variable(
						&temp_buf,
					&tbuf_len,
					&tout_len,
					1,
					vars->name,
					vars->name_length,
					vars))
				{
					if (temp_buf != NULL)
					{
						free(temp_buf);
					}

					return 0;
				}
			}

			break;
		default:
			/*
         * Don't know how to handle this command - write the character itself.  
         */
			temp_buf[0] = fmt_cmd;
	}

	/*
     * Output with correct justification, leading zeroes, etc.  
     */
	return realloc_output_temp_bfr(
			buf,
			buf_len,
			out_len,
			allow_realloc,
			&temp_buf,
			options);
}

int CPdutostr::realloc_handle_auth_fmt(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	options_type *options,
	netsnmp_pdu *pdu)
{
	char fmt_cmd = options->cmd;	/* what we're outputting */
	u_char	*temp_buf = NULL;
	size_t	tbuf_len = 64;
	size_t	tout_len = 0;
	int i;

	if ((temp_buf = (u_char *)calloc(tbuf_len, 1)) == NULL)
	{
		return 0;
	}

	switch (fmt_cmd)
	{
		case CHR_SNMP_VERSION:
			tout_len = snprintf((char *)temp_buf, tbuf_len, "%ld", pdu->version);
			break;
		case CHR_SNMP_SECMOD:
			tout_len = snprintf(
					(char *)temp_buf,
					tbuf_len,
					"%d",
					pdu->securityModel);
			break;
		case CHR_SNMP_USER:
			switch (pdu->version)
			{
		#ifndef NETSNMP_DISABLE_SNMPV1
				case SNMP_VERSION_1:
		#endif
		#ifndef NETSNMP_DISABLE_SNMPV2C
				case SNMP_VERSION_2c:
		#endif
		#if !defined(NETSNMP_DISABLE_SNMPV1) || !defined(NETSNMP_DISABLE_SNMPV2C)
					while ((*out_len + pdu->community_len + 1) >= *buf_len)
					{
						if (!(allow_realloc && snmp_realloc(buf, buf_len)))
						{
							return 0;
						}
					}

					for (i = 0; i < pdu->community_len; i++)
					{
						if (isprint(pdu->community[i]))
						{
							*(*buf +*out_len) = pdu->community[i];
						}
						else
						{
							*(*buf +*out_len) = '.';
						}

						(*out_len)++;
					}

					*(*buf +*out_len) = '\0';
					break;
		#endif
				default:
					tout_len = snprintf(
							(char *)temp_buf,
							tbuf_len,
							"%s",
							pdu->securityName);
			}

			break;
		default:
			/*
         * Don't know how to handle this command - write the character itself.  
         */
			temp_buf[0] = fmt_cmd;
	}

	/*
     * Output with correct justification, leading zeroes, etc.  
     */
	return realloc_output_temp_bfr(
			buf,
			buf_len,
			out_len,
			allow_realloc,
			&temp_buf,
			options);
}

CPdutostr::CPdutostr(void)
{
	memset(separator, 0, sizeof(separator));
}

CPdutostr::~CPdutostr(void)
{
}

/*
*/
int CPdutostr::format_plain_trap(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	netsnmp_pdu *pdu,
	netsnmp_transport_s *transport)
{
	time_t	now;					/* the current time */
	struct tm *now_parsed;			/* time in struct format */
	char safe_bfr[200];				/* holds other strings */
	struct in_addr	*agent_inaddr = (struct in_addr *)pdu->agent_addr;
	struct hostent	*host = NULL;	/* host name */
	netsnmp_variable_list *vars;	/* variables assoc with trap */

	if (buf == NULL)
	{
		return 0;
	}

	//
	time(&now);
	now_parsed = localtime(&now);
	sprintf(
		safe_bfr,
		"%.4d-%.2d-%.2d %.2d:%.2d:%.2d ",
		now_parsed->tm_year + 1900,
		now_parsed->tm_mon + 1,
		now_parsed->tm_mday,
		now_parsed->tm_hour,
		now_parsed->tm_min,
		now_parsed->tm_sec);
	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)safe_bfr))
	{
		return 0;
	}

	//
	if (!netsnmp_ds_get_boolean(
			NETSNMP_DS_APPLICATION_ID,
		NETSNMP_DS_APP_NUMERIC_IP))
	{
		host = gethostbyaddr((char *)pdu->agent_addr, 4, AF_INET);
	}

	if (host != (struct hostent *)NULL)
	{
		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)host->h_name))
		{
			return 0;
		}

		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)" ["))
		{
			return 0;
		}

		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)inet_ntoa(*agent_inaddr)))
		{
			return 0;
		}

		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)"] "))
		{
			return 0;
		}
	}
	else
	{
		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)inet_ntoa(*agent_inaddr)))
		{
			return 0;
		}
	}

	if (transport != NULL && transport->f_fmtaddr != NULL)
	{
		char *tstr = transport->f_fmtaddr(
				transport,
				pdu->transport_data,
				pdu->transport_data_length);
		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)"(via "))
		{
			if (tstr != NULL)
			{
				free(tstr);
			}

			return 0;
		}

		if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, (u_char *)tstr))
		{
			if (tstr != NULL)
			{
				free(tstr);
			}

			return 0;
		}

		if (tstr != NULL)
		{
			free(tstr);
		}

		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)") "))
		{
			return 0;
		}
	}

	/*
     * Add security wrapper information.  
     */
	if (!realloc_handle_wrap_fmt(buf, buf_len, out_len, allow_realloc, pdu))
	{
		return 0;
	}

	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)"\n\t"))
	{
		return 0;
	}

	/*
     * Add enterprise information.  
     */
	if (!sprint_realloc_objid(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		pdu->enterprise,
		pdu->enterprise_length))
	{
		return 0;
	}

	if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, (const u_char *)" "))
	{
		return 0;
	}

	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)trap_description(pdu->trap_type)))
	{
		return 0;
	}

	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)" Trap ("))
	{
		return 0;
	}

	/*
     * Handle enterprise specific traps.  
     */
	if (pdu->trap_type == SNMP_TRAP_ENTERPRISESPECIFIC)
	{
		size_t	obuf_len = 64;

		size_t	oout_len = 0;

		size_t	trap_oid_len = 0;
		oid trap_oid[MAX_OID_LEN + 2] = { 0 };
		char *ent_spec_code = NULL;
		u_char	*obuf = NULL;

		if ((obuf = (u_char *)calloc(obuf_len, 1)) == NULL)
		{
			return 0;
		}

		/*
         * Get object ID for the trap.  
         */
		trap_oid_len = pdu->enterprise_length;
		memcpy(trap_oid, pdu->enterprise, trap_oid_len * sizeof(oid));
		if (trap_oid[trap_oid_len - 1] != 0)
		{
			trap_oid[trap_oid_len] = 0;
			trap_oid_len++;
		}

		trap_oid[trap_oid_len] = pdu->specific_type;
		trap_oid_len++;

		/*
         * Find the element after the last dot.  
         */
		if (!sprint_realloc_objid(
				&obuf,
			&obuf_len,
			&oout_len,
			1,
			trap_oid,
			trap_oid_len))
		{
			if (obuf != NULL)
			{
				free(obuf);
			}

			return 0;
		}

		ent_spec_code = strrchr((char *)obuf, '.');
		if (ent_spec_code != NULL)
		{
			ent_spec_code++;
		}
		else
		{
			ent_spec_code = (char *)obuf;
		}

		/*
         * Print trap info.  
         */
		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)ent_spec_code))
		{
			free(obuf);
			return 0;
		}

		free(obuf);
	}
	else
	{
		/*
         * Handle traps that aren't enterprise specific.  
         */
		sprintf(safe_bfr, "%ld", pdu->specific_type);
		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)safe_bfr))
		{
			return 0;
		}
	}

	/*
     * Finish the line.  
     */
	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)") Uptime: "))
	{
		return 0;
	}

	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)uptime_string(pdu->time, safe_bfr)))
	{
		return 0;
	}

	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)"\n"))
	{
		return 0;
	}

	/*
     * Finally, output the PDU variables. 
     */
	for (vars = pdu->variables; vars != NULL; vars = vars->next_variable)
	{
		if (!snmp_strcat(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			(const u_char *)"\t"))
		{
			return 0;
		}

		if (!sprint_realloc_variable(
				buf,
			buf_len,
			out_len,
			allow_realloc,
			vars->name,
			vars->name_length,
			vars))
		{
			return 0;
		}
	}

	if (!snmp_strcat(
			buf,
		buf_len,
		out_len,
		allow_realloc,
		(const u_char *)"\n"))
	{
		return 0;
	}

	/*
     * String is already null-terminated.  That's all folks!  
     */
	return 1;
}

/*
*/
int CPdutostr::format_trap(
	u_char	**buf,
	size_t	*buf_len,
	size_t	*out_len,
	int allow_realloc,
	const char	*format_str,
	netsnmp_pdu *pdu,
	netsnmp_transport_s *transport)
{
	unsigned long fmt_idx = 0;	/* index into the format string */
	options_type options;		/* formatting options */
	parse_state_type state = PARSE_NORMAL;	/* state of the parser */
	char next_chr;				/* for speed */
	int reset_options = TRUE;	/* reset opts on next NORMAL state */

	if (buf == NULL)
	{
		return 0;
	}

	// Go until we reach the end of the format string:
	for (fmt_idx = 0; format_str[fmt_idx] != '\0'; fmt_idx++)
	{
		next_chr = format_str[fmt_idx];
		switch (state)
		{
			case PARSE_NORMAL:
				// Looking for next character
				if (reset_options)
				{
					init_options(&options);
					reset_options = FALSE;
				}

				if (next_chr == '\\')
				{
					state = PARSE_BACKSLASH;
				}
				else if (next_chr == CHR_FMT_DELIM)
				{
					state = PARSE_IN_FORMAT;
				}
				else
				{
					if ((*out_len + 1) >= *buf_len)
					{
						if (!(allow_realloc && snmp_realloc(buf, buf_len)))
						{
							return 0;
						}
					}

					*(*buf +*out_len) = next_chr;
					(*out_len)++;
				}

				break;
			case PARSE_GET_SEPARATOR:
				// Parse the separator character
				// XXX - Possibly need to handle quoted strings ??
				{
					char *sep = separator;
					size_t	i;
					size_t	j;
					i = sizeof(separator);
					j = 0;
					memset(separator, 0, i);
					while (j < i && next_chr && next_chr != CHR_FMT_DELIM)
					{
						if (next_chr == '\\')
						{
							/*
					* Handle backslash interpretation
					* Print to "separator" string rather than the output buffer
					*    (a bit of a hack, but it should work!)
					*/
							next_chr = format_str[++fmt_idx];
							if (!realloc_handle_backslash(
									(u_char **) &sep,
								&i,
								&j,
								0,
								next_chr))
							{
								return 0;
							}
						}
						else
						{
							separator[j++] = next_chr;
						}

						next_chr = format_str[++fmt_idx];
					}
				}

				state = PARSE_IN_FORMAT;
				break;
			case PARSE_BACKSLASH:
				/*
			* Found a backslash.  
			*/
				if (!realloc_handle_backslash(
						buf,
					buf_len,
					out_len,
					allow_realloc,
					next_chr))
				{
					return 0;
				}

				state = PARSE_NORMAL;
				break;
			case PARSE_IN_FORMAT:
				/*
			* In a format command.  
			*/
				reset_options = TRUE;
				if (next_chr == CHR_LEFT_JUST)
				{
					options.left_justify = TRUE;
				}
				else if (next_chr == CHR_LEAD_ZERO)
				{
					options.leading_zeroes = TRUE;
				}
				else if (next_chr == CHR_ALT_FORM)
				{
					options.alt_format = TRUE;
				}
				else if (next_chr == CHR_FIELD_SEP)
				{
					state = PARSE_GET_PRECISION;
				}
				else if (next_chr == CHR_TRAP_VARSEP)
				{
					state = PARSE_GET_SEPARATOR;
				}
				else if ((next_chr >= '1') && (next_chr <= '9'))
				{
					options.width = ((unsigned long)next_chr) - ((unsigned long)'0');
					state = PARSE_GET_WIDTH;
				}
				else if (is_fmt_cmd(next_chr))
				{
					options.cmd = next_chr;
					if (!realloc_dispatch_format_cmd(
							buf,
						buf_len,
						out_len,
						allow_realloc,
						&options,
						pdu,
						transport))
					{
						return 0;
					}

					state = PARSE_NORMAL;
				}
				else
				{
					if ((*out_len + 1) >= *buf_len)
					{
						if (!(allow_realloc && snmp_realloc(buf, buf_len)))
						{
							return 0;
						}
					}

					*(*buf +*out_len) = next_chr;
					(*out_len)++;
					state = PARSE_NORMAL;
				}

				break;
			case PARSE_GET_WIDTH:
				/*
			* Parsing a width field.  
			*/
				reset_options = TRUE;
				if (isdigit(next_chr))
				{
					options.width *= 10;
					options.width += (unsigned long)next_chr - (unsigned long)'0';
				}
				else if (next_chr == CHR_FIELD_SEP)
				{
					state = PARSE_GET_PRECISION;
				}
				else if (is_fmt_cmd(next_chr))
				{
					options.cmd = next_chr;
					if (!realloc_dispatch_format_cmd(
							buf,
						buf_len,
						out_len,
						allow_realloc,
						&options,
						pdu,
						transport))
					{
						return 0;
					}

					state = PARSE_NORMAL;
				}
				else
				{
					if ((*out_len + 1) >= *buf_len)
					{
						if (!(allow_realloc && snmp_realloc(buf, buf_len)))
						{
							return 0;
						}
					}

					*(*buf +*out_len) = next_chr;
					(*out_len)++;
					state = PARSE_NORMAL;
				}

				break;
			case PARSE_GET_PRECISION:
				/*
			* Parsing a precision field.  
			*/
				reset_options = TRUE;
				if (isdigit(next_chr))
				{
					if (options.precision == UNDEF_PRECISION)
					{
						options.precision = (unsigned long)next_chr - (unsigned long)'0';
					}
					else
					{
						options.precision *= 10;
						options.precision += (unsigned long)next_chr - (unsigned long)'0';
					}
				}
				else if (is_fmt_cmd(next_chr))
				{
					options.cmd = next_chr;
					if (options.width < options.precision)
					{
						options.width = options.precision;
					}

					if (!realloc_dispatch_format_cmd(
							buf,
						buf_len,
						out_len,
						allow_realloc,
						&options,
						pdu,
						transport))
					{
						return 0;
					}

					state = PARSE_NORMAL;
				}
				else
				{
					if ((*out_len + 1) >= *buf_len)
					{
						if (!(allow_realloc && snmp_realloc(buf, buf_len)))
						{
							return 0;
						}
					}

					*(*buf +*out_len) = next_chr;
					(*out_len)++;
					state = PARSE_NORMAL;
				}

				break;
			default:
				/*
			* Unknown state.  
			*/
				reset_options = TRUE;
				if ((*out_len + 1) >= *buf_len)
				{
					if (!(allow_realloc && snmp_realloc(buf, buf_len)))
					{
						return 0;
					}
				}

				*(*buf +*out_len) = next_chr;
				(*out_len)++;
				state = PARSE_NORMAL;
		}
	}

	*(*buf +*out_len) = '\0';
	return 1;
}
