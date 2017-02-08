/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	Pdutostr.h
///@brief	将Pdu转换成string
///@history
///20101101	LSC	create
/////////////////////////////////////////////////////////////////////////
#ifndef REF_PDUTOSTR_H
#define REf_PDUTOSTR_H
#pragma once
#include "platform.h"
#include "net_snmp.h"

#define PRINT_V23_NOTIFICATION_FORMAT \
			"%.4y-%.2m-%.2l %.2h:%.2j:%.2k %B [%b]:\n%v\n"

#define NETSNMP_DS_APP_NUMERIC_IP		16
#define NETSNMP_DS_APP_NO_AUTHORIZATION 17

	//标识可选项options中没有定义的取值
#define UNDEF_CMD		'*'
#define UNDEF_PRECISION - \
		1

	//表示单一格式化命令的结构
	typedef struct
	{
		char cmd;				/* the format command itself */
	size_t	width;				/* the field's minimum width */
	size_t	precision;			/* the field's precision */
	int left_justify;			/* if true, left justify this field */
	int alt_format;				/* if true, display in alternate format */
	int leading_zeroes;			/* if true, display with leading zeroes */
} options_type;

//
typedef enum
{
	CHR_FMT_DELIM		= '%',	/* starts a format command */
	CHR_LEFT_JUST		= '-',	/* left justify */
	CHR_LEAD_ZERO		= '0',	/* use leading zeroes */
	CHR_ALT_FORM		= '#',	/* use alternate format */
	CHR_FIELD_SEP		= '.',	/* separates width and precision fields */

	/* Date / Time Information */
	CHR_CUR_TIME		= 't',	/* current time, Unix format */
	CHR_CUR_YEAR		= 'y',	/* current year */
	CHR_CUR_MONTH		= 'm',	/* current month */
	CHR_CUR_MDAY		= 'l',	/* current day of month */
	CHR_CUR_HOUR		= 'h',	/* current hour */
	CHR_CUR_MIN			= 'j',	/* current minute */
	CHR_CUR_SEC			= 'k',	/* current second */
	CHR_UP_TIME			= 'T',	/* uptime, Unix format */
	CHR_UP_YEAR			= 'Y',	/* uptime year */
	CHR_UP_MONTH		= 'M',	/* uptime month */
	CHR_UP_MDAY			= 'L',	/* uptime day of month */
	CHR_UP_HOUR			= 'H',	/* uptime hour */
	CHR_UP_MIN			= 'J',	/* uptime minute */
	CHR_UP_SEC			= 'K',	/* uptime second */

	/* transport information */
	CHR_AGENT_IP		= 'a',	/* agent's IP address */
	CHR_AGENT_NAME		= 'A',	/* agent's host name if available */

	/* authentication information */
	CHR_SNMP_VERSION	= 's',	/* SNMP Version Number */
	CHR_SNMP_SECMOD		= 'S',	/* SNMPv3 Security Model Version Number */
	CHR_SNMP_USER		= 'u',	/* SNMPv3 secName or v1/v2c community */
	CHR_TRAP_CONTEXTID	= 'E',	/* SNMPv3 context engineID if available */

	/* PDU information */
	CHR_PDU_IP			= 'b',	/* PDU's IP address */
	CHR_PDU_NAME		= 'B',	/* PDU's host name if available */
	CHR_PDU_ENT			= 'N',	/* PDU's enterprise string */
	CHR_PDU_WRAP		= 'P',	/* PDU's wrapper info (community, security) */
	CHR_TRAP_NUM		= 'w',	/* trap number */
	CHR_TRAP_DESC		= 'W',	/* trap's description (textual) */
	CHR_TRAP_STYPE		= 'q',	/* trap's subtype */
	CHR_TRAP_VARSEP		= 'V',	/* character (or string) to separate variables */
	CHR_TRAP_VARS		= 'v'	/* tab-separated list of trap's variables */
} parse_chr_type;

typedef enum
{
	PARSE_NORMAL,				/* looking for next character */
	PARSE_BACKSLASH,			/* saw a backslash */
	PARSE_IN_FORMAT,			/* saw a % sign, in a format command */
	PARSE_GET_WIDTH,			/* getting field width */
	PARSE_GET_PRECISION,		/* getting field precision */
	PARSE_GET_SEPARATOR			/* getting field separator */
} parse_state_type;

//判别宏
///////////////////////
#define is_fmt_cmd(chr)						  \
		(									  \
			(								  \
				is_cur_time_cmd(chr)		  \
			||	is_up_time_cmd(chr)			  \
			||	is_auth_cmd(chr)			  \
			||	is_agent_cmd(chr)			  \
			||	is_pdu_ip_cmd(chr)			  \
			||	((chr) == CHR_PDU_ENT)		  \
			||	((chr) == CHR_TRAP_CONTEXTID) \
			||	((chr) == CHR_PDU_WRAP)		  \
			||	is_trap_cmd(chr)			  \
			) ? TRUE : FALSE				  \
		)

///////////////////////
#define is_cur_time_cmd(chr)			 \
		(								 \
			(							 \
				((chr) == CHR_CUR_TIME)	 \
			||	((chr) == CHR_CUR_YEAR)	 \
			||	((chr) == CHR_CUR_MONTH) \
			||	((chr) == CHR_CUR_MDAY)	 \
			||	((chr) == CHR_CUR_HOUR)	 \
			||	((chr) == CHR_CUR_MIN)	 \
			||	((chr) == CHR_CUR_SEC)	 \
			) ? TRUE : FALSE			 \
		)

///////////////////////
#define is_up_time_cmd(chr)				\
		(								\
			(							\
				((chr) == CHR_UP_TIME)	\
			||	((chr) == CHR_UP_YEAR)	\
			||	((chr) == CHR_UP_MONTH) \
			||	((chr) == CHR_UP_MDAY)	\
			||	((chr) == CHR_UP_HOUR)	\
			||	((chr) == CHR_UP_MIN)	\
			||	((chr) == CHR_UP_SEC)	\
			) ? TRUE : FALSE			\
		)

///////////////////////
#define is_agent_cmd(chr) \
		((((chr) == CHR_AGENT_IP) || ((chr) == CHR_AGENT_NAME)) ? TRUE : FALSE)

///////////////////////
#define is_pdu_ip_cmd(chr) \
		((((chr) == CHR_PDU_IP) || ((chr) == CHR_PDU_NAME)) ? TRUE : FALSE)

///////////////////////
#define is_auth_cmd(chr)					  \
		(									  \
			(								  \
				(							  \
					(chr) == CHR_SNMP_VERSION \
				||	(chr) == CHR_SNMP_SECMOD  \
				||	(chr) == CHR_SNMP_USER	  \
				)							  \
			) ? TRUE : FALSE				  \
		)

///////////////////////
#define is_trap_cmd(chr)				  \
		(								  \
			(							  \
				((chr) == CHR_TRAP_NUM)	  \
			||	((chr) == CHR_TRAP_DESC)  \
			||	((chr) == CHR_TRAP_STYPE) \
			||	((chr) == CHR_TRAP_VARS)  \
			) ? TRUE : FALSE			  \
		)

///////////////////////
#define is_fmt_cmd(chr)						  \
		(									  \
			(								  \
				is_cur_time_cmd(chr)		  \
			||	is_up_time_cmd(chr)			  \
			||	is_auth_cmd(chr)			  \
			||	is_agent_cmd(chr)			  \
			||	is_pdu_ip_cmd(chr)			  \
			||	((chr) == CHR_PDU_ENT)		  \
			||	((chr) == CHR_TRAP_CONTEXTID) \
			||	((chr) == CHR_PDU_WRAP)		  \
			||	is_trap_cmd(chr)			  \
			) ? TRUE : FALSE				  \
		)

///////////////////////
#define is_numeric_cmd(chr) \
		((is_cur_time_cmd(chr) || is_up_time_cmd(chr) || (chr) == CHR_TRAP_NUM) ? TRUE : FALSE)

///////////////////////
#define reference(var)	((var) == (var))

class CPdutostr
{
	/* */
	public:
		CPdutostr(void);

	/* */
	public:
		~ CPdutostr(void);

		//description：格式化trap信息。内容分配新的存储空间
		//return：格式化后的信息内容长度
		//Input Parameters:
		//   buf, buf_len, out_len, allow_realloc - 内存分配参数
		//   format_str - 处理trap信息时指定的格式,(暂不支持)
		//   pdu        - the pdu information
		//   transport  - the transport descriptor
		//默认的格式处理trap信息
		int format_plain_trap(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				netsnmp_pdu *pdu,
				struct netsnmp_transport_s	*transport);

		int format_trap(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				const char	*format_str,
				netsnmp_pdu *pdu,
				struct netsnmp_transport_s	*transport);

	/* */
	private:
		const char	*trap_description(int trap);

		int realloc_handle_wrap_fmt(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				netsnmp_pdu *pdu);

		void init_options(options_type *options);

		int realloc_handle_backslash(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				char fmt_cmd);

		int realloc_dispatch_format_cmd(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				options_type *options,
				netsnmp_pdu *pdu,
				netsnmp_transport *transport);

		int realloc_handle_time_fmt(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				options_type *options,
				netsnmp_pdu *pdu);

		int realloc_handle_ip_fmt(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				options_type *options,
				netsnmp_pdu *pdu,
				netsnmp_transport *transport);

		int realloc_handle_ent_fmt(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				options_type *options,
				netsnmp_pdu *pdu);

		int realloc_handle_trap_fmt(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				options_type *options,
				netsnmp_pdu *pdu);

		int realloc_handle_auth_fmt(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				options_type *options,
				netsnmp_pdu *pdu);

		int realloc_output_temp_bfr(
				u_char	**buf,
				size_t	*buf_len,
				size_t	*out_len,
				int allow_realloc,
				u_char	**temp_buf,
				options_type *options);

	/* */
	private:
		char separator[32];
};
#endif
