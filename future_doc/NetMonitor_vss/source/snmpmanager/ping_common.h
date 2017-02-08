/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	ping_common.h
///@brief	定义了ping的类
///@history
///20100819	周建军	根据linux的ping源代码改造实现
#ifndef REF_PING_COMMON_H
#define REF_PING_COMMON_H

#include "platform.h"

#ifdef WIN32
#include <Windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef LINUX
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sched.h>
#include <ctype.h>
#include <asm/types.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/signal.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <sys/poll.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <linux/sockios.h>
#include <linux/filter.h>

/*
 *      constants for (set|get)sockopt
 */
#define ICMP_FILTER 1
struct icmp_filter{ __u32 data; };
#ifndef _LINUX_ERRQUEUE_H
#define _LINUX_ERRQUEUE_H	1
struct sock_extended_err{ __u32 ee_errno; __u8	ee_origin; __u8	 ee_type; __u8
		ee_code; __u8  ee_pad; __u32 ee_info; __u32 ee_data; };
#define SO_EE_ORIGIN_NONE	0
#define SO_EE_ORIGIN_LOCAL	1
#define SO_EE_ORIGIN_ICMP	2
#define SO_EE_ORIGIN_ICMP6	3
#define SO_EE_OFFENDER(ee) \
	((struct sockaddr *)((ee) + 1))
#endif //_LINUX_ERRQUEUE_H
struct sCMSG
{
	struct cmsghdr	cm;
	struct in_pktinfo ipi;
};
#endif
#define DEFDATALEN		(64 - 8)				/* default data length */
#define MAXWAIT			10						/* max seconds to wait for response */
#define MININTERVAL		10						/* Minimal interpacket gap */
#define MINUSERINTERVAL 200						/* Minimal allowed interval for non-root */
#define SCHINT(a)		(((a) <= MININTERVAL) ? MININTERVAL : (a))
#define A(bit)			rcvd_tbl[(bit) >> 3]	/* identify byte in array */
#define B(bit)			(1 << ((bit) & 0x07))	/* identify bit in byte */
#define SET(bit)		(A(bit) |= B(bit))
#define CLR(bit)		(A(bit) &= (~B(bit)))
#define TST(bit)		(A(bit) & B(bit))
#define F_FLOOD			0x001
#define F_INTERVAL		0x002
#define F_NUMERIC		0x004
#define F_PINGFILLED	0x008
#define F_QUIET			0x010
#define F_RROUTE		0x020
#define F_SO_DEBUG		0x040
#define F_SO_DONTROUTE	0x080
#define F_VERBOSE		0x100
#define F_TIMESTAMP		0x200
#define F_FLOWINFO		0x200
#define F_SOURCEROUTE	0x400
#define F_TCLASS		0x400
#define F_FLOOD_POLL	0x800
#define F_LATENCY		0x1000
#define F_AUDIBLE		0x2000
#define F_ADAPTIVE		0x4000
#define F_STRICTSOURCE	0x8000
#define F_NOLOOP		0x10000
#define F_TTL			0x20000

#define MAXIPLEN		60
#define MAXICMPLEN		76
#define NROUTES			9						/* number of record route slots */
#define TOS_MAX			255						/* 8-bit TOS field */

/*
 * MAX_DUP_CHK is the number of bits in received table, i.e. the maximum
 * number of received sequence numbers we can keep track of.
 */
#define MAX_DUP_CHK 0x10000

#ifndef MSG_CONFIRM
#define MSG_CONFIRM 0
#endif //MSG_CONFIRM
#define COMMON_OPTIONS \
case 'a':			   \
case 'U':			   \
case 'c':			   \
case 'd':			   \
case 'f':			   \
case 'i':			   \
case 'w':			   \
case 'l':			   \
case 'S':			   \
case 'n':			   \
case 'p':			   \
case 'q':			   \
case 'r':			   \
case 's':			   \
case 'v':			   \
case 'L':			   \
case 't':			   \
case 'A':			   \
case 'W':			   \
case 'B':
#define COMMON_OPTSTR	"h?VQ:I:M:aUc:dfi:w:l:S:np:qrs:vLt:AW:B"

class CPing
{
	/* */
	public:

		///构造函数
			///@param	nPackets	发送数据包个数
			///@param	pHostName	对端主机的IP地址或主机名
		CPing(int nPackets, char *pHostName)
		{
			m_nPackets = nPackets;	//最大发送数据包个数
			m_lWaittime = 0;
			m_pDevice = NULL;
			memset(m_mHostname, 0, MAXIPLEN);
			strncpy(m_mHostname, pHostName, MAXIPLEN);
			m_pHostname = m_mHostname;

			m_iOptions = 0;
			m_iSndbuf = 0;
			m_iTtl = 0;
			m_iRtt = 0;
			m_iRtt_addend = 0;
			m_usAcked = 0;
			m_iWorking_recverr = 0;
			m_iStatus_snapshot = 0;
			m_iCmsg_len = 0;

			m_iMx_dup_ck = MAX_DUP_CHK;
			m_iInterval = 1000;		/* interval between packets (msec) */
			m_iDeadline = 0;		/* time to die */
			m_iLingertime = MAXWAIT * 1000;
			m_iConfirm = 0;
			m_iConfirm_flag = MSG_CONFIRM;
			m_iTmin = LONG_MAX;		/* minimum round trip time */
			m_iPipesize = -1;
			m_iDatalen = DEFDATALEN;
			m_iScreen_width = INT_MAX;
			m_iOptlen = 0;
			m_iSettos = 0;			/* Set TOS, Precendence or other QOS options */
			m_iMaxpacket = sizeof(m_ucOutpack);
			m_iPmtudisc = -1;
			m_iBroadcast_pings = 0;
#ifdef LINUX
			m_sCmsg.cm.cmsg_len = sizeof(struct cmsghdr) + sizeof(struct in_pktinfo);
			m_sCmsg.cm.cmsg_level = SOL_IP;
			m_sCmsg.cm.cmsg_type = IP_PKTINFO;
			m_sCmsg.ipi.ipi_ifindex = 0;
#endif
			m_nReceived = 0;		/* # of packets we got back */
			m_nRepeats = 0;			/* number of duplicates */
			m_nTransmitted = 0;		/* sequence # for outbound packets = #sent */
			m_nChecksum = 0;		/* replies with bad checksum */
			m_nErrors = 0;			/* icmp errors */
			m_iPreload = 0;
			m_lTsum = 0;
			m_lTsum2 = 0;
			m_iExiting = 0;
			m_iOnce = 0;
			m_iErrOnce = 0;
			m_iIcmp_sock = -1;
			memset(&m_sStart_time, 0, sizeof(m_sStart_time));
			memset(&m_sCur_time, 0, sizeof(m_sCur_time));
		};
		~CPing(void)
		{
			if (m_iIcmp_sock >= 0)
			{
				close(m_iIcmp_sock);
			}
		}

		int run(void);
		long getReceived(void)
		{
			return m_nReceived;
		}

	/* */
	private:
#ifdef LINUX
		int __schedule_exit(int next);
		int fill(char *patp);
		int common_options(int ch);
		void sigexit(int signo);
		void sigstatus(int signo);
		int pinger(void);
		void sock_setbufs(int icmp_sock, int alloc);
		int setup(int icmp_sock);
		void main_loop(int icmp_sock, __u8 *packet, int packlen);
		int gather_statistics(
				__u8 *ptr,
				int cc,
				__u16 seq,
				int hops,
				int csfailed,
				struct timeval	*tv,
				char *from);
		long llsqrt(long long a);
		void finish(void);
		void status(void);
		int receive_error_msg(void);
		int send_probe(void);
		int parse_reply(
				struct msghdr *msg,
				int cc,
				void *addr,
				struct timeval	*tv);
		u_short in_cksum(const u_short *addr, register int len, u_short csum);
		void pr_icmph(__u8 type, __u8 code, __u32 info, struct icmphdr *icp);
		void pr_options(unsigned char *cp, int hlen);
		void pr_iph(struct iphdr *ip);
		char *pr_addr(__u32 addr);
		int parsetos(char *str);
		void install_filter(void);
		void usage(void);
#endif

	/* */
	private:
		unsigned long m_lWaittime;		// 超时退出时间
		char rcvd_tbl[MAX_DUP_CHK / 8];
		int m_iOptions;
		int m_iSndbuf;
		int m_iTtl;
		int m_iRtt;
		int m_iRtt_addend;
#ifdef LINUX
		__u16 m_usAcked;
#else
		unsigned short	m_usAcked;
#endif
		int m_iMx_dup_ck;				//= MAX_DUP_CHK;

		/* counters */
		long m_nPackets;				/* max packets to transmit */
		long m_nReceived;				/* # of packets we got back */
		long m_nRepeats;				/* number of duplicates */
		long m_nTransmitted;			/* sequence # for outbound packets = #sent */
		long m_nChecksum;				/* replies with bad checksum */
		long m_nErrors;					/* icmp errors */

		int m_iInterval;				// = 1000;	/* interval between packets (msec) */
		int m_iPreload;
		int m_iDeadline;				//= 0;		/* time to die (sec) */
		int m_iLingertime;				//= MAXWAIT*1000;
		struct timeval	m_sStart_time;

		//= MAXWAIT*1000;
		struct timeval	m_sCur_time;
		volatile int m_iExiting;
		volatile int m_iStatus_snapshot;
		int m_iConfirm;					//= 0;

		/* Stupid workarounds for bugs/missing functionality in older linuces.
	 * m_iConfirm_flag fixes refusing service of kernels without MSG_CONFIRM.
	 * i.e. for linux-2.2 */
		int m_iConfirm_flag;			//= MSG_CONFIRM;

		/* And this is workaround for bug in IP_RECVERR on raw sockets which is present
	 * in linux-2.2.[0-19], linux-2.4.[0-7] */
		int m_iWorking_recverr;

		/* m_iTiming */
		int m_iTiming;					/* flag to do m_iTiming */
		long m_iTmin;					//= LONG_MAX;		/* minimum round trip time */
		long m_iTmax;					/* maximum round trip time */

		/* Message for rpm maintainers: have _shame_. If you want
	 * to fix something send the patch to me for sanity checking.
	 * "sparcfix" patch is a complete non-sense, apparenly the person
	 * prepared it was stoned.
	 */
		long long m_lTsum;				/* sum of all times, for doing average */
		long long m_lTsum2;
		int m_iPipesize;				//= -1;
		int m_iDatalen;					//= DEFDATALEN;
		char m_mHostname[MAXIPLEN];
		char *m_pHostname;
		int m_iUid;
		int m_iIdent;					/* process id to identify our packets */

		int m_iScreen_width;			//= INT_MAX;
		int m_iTs_type;
		int m_iNroute;					//= 0;
#ifdef LINUX
		__u32 m_aRoute[10];
		struct sockaddr_in	m_sWhereto; /* who to ping */
		struct sCMSG m_sCmsg;			//= { {sizeof(struct cmsghdr) + sizeof(struct in_pktinfo), SOL_IP, IP_PKTINFO},{0, }};
#else
		unsigned int m_aRoute[10];
#endif
		int m_iOptlen;					//= 0;
		int m_iSettos;					//= 0;			/* Set TOS, Precendence or other QOS options */
		int m_iIcmp_sock;				/* socket file descriptor */
		u_char	m_ucOutpack[0x10000];
		int m_iMaxpacket;				//= sizeof(m_ucOutpack);
		int m_iCmsg_len;
		struct sockaddr_in	m_sSource;
		char *m_pDevice;
		int m_iPmtudisc;				//= -1;
		int m_iBroadcast_pings;			//= 0;
		int m_iOnce;					//装载一次标记
		int m_iErrOnce;					//错包报告一次标记

	/* */
	private:
#ifdef LINUX

		/*
	 * tvsub --
	 *	Subtract 2 timeval structs:  out = out - in.  Out is assumed to
	 * be >= in.
	 */
		inline void tvsub(struct timeval *out, struct timeval *in)
		{
			if ((out->tv_usec -= in->tv_usec) < 0)
			{
				--out->tv_sec;
				out->tv_usec += 1000000;
			}

			out->tv_sec -= in->tv_sec;
		}

		inline void set_signal(int signo, void (*handler) (int))
		{
			struct sigaction sa;

			memset(&sa, 0, sizeof(sa));

			sa.sa_handler = (void(*) (int)) handler;
#ifdef SA_INTERRUPT
			sa.sa_flags = SA_INTERRUPT;
#endif
			sigaction(signo, &sa, NULL);
		}

		inline int schedule_exit(int next)
		{
			if (m_nPackets && m_nTransmitted >= m_nPackets && !m_iDeadline)
			{
				next = __schedule_exit(next);
			}

			return next;
		}

		inline int in_flight(void)
		{
			__u16 diff = (__u16) m_nTransmitted - m_usAcked;
			return (diff <= 0x7FFF) ? diff : m_nTransmitted -
				m_nReceived -
				m_nErrors;
		}

		inline void acknowledge(__u16 seq)
		{
			__u16 diff = (__u16) m_nTransmitted - seq;
			if (diff <= 0x7FFF)
			{
				if ((int)diff + 1 > m_iPipesize)
				{
					m_iPipesize = (int)diff + 1;
				}

				if ((__s16) (seq - m_usAcked) > 0
				||	(__u16) m_nTransmitted - m_usAcked > 0x7FFF)
				{
					m_usAcked = seq;
				}
			}
		}

		inline void advance_ntransmitted(void)
		{
			m_nTransmitted++;

			/* Invalidate acked, if 16 bit seq overflows. */
			if ((__u16) m_nTransmitted - m_usAcked > 0x7FFF)
			{
				m_usAcked = (__u16) m_nTransmitted + 1;
			}
		}

		inline void update_interval(void)
		{
			int est = m_iRtt ? m_iRtt / 8 : m_iInterval * 1000;

			m_iInterval = (est + m_iRtt_addend + 500) / 1000;
			if (m_iUid && m_iInterval < MINUSERINTERVAL)
			{
				m_iInterval = MINUSERINTERVAL;
			}
		}

#endif
};

///根据IP+掩码计算ip起始地址和区间大小
///@param	startIp	返回的起始地址
///@param	ipNum	返回的ip区间大小
///@param	ipAddr	IP地址
///@param	ipMask	IP地址对应的掩码
///@return	返回成功和失败,0 true
inline int getip(
	unsigned long &startIp,
	unsigned long &ipNum,
	const char	*ipAddr,
	const char	*ipMask)
{
	unsigned long ip = htonl(inet_addr(ipAddr));
	unsigned long mask = htonl(inet_addr(ipMask));
	startIp = ip & mask;
	ipNum = ~mask;
	return 0;
}

#endif // REF_PING_COMMON_H
