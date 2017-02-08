#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#ifdef LINUX
#include <term.h>
#include <termios.h>
#endif
typedef unsigned char u_char;

//// 命令执行体所支持的命令集
/* TELNET Command Codes: */
#define TCSB	(u_char) 250	/* Start Subnegotiation		*/
#define TCSE	(u_char) 240	/* End Of Subnegotiation	*/
#define TCNOP	(u_char) 241	/* No Operation				*/
#define TCDM	(u_char) 242	/* Data Mark (for Sync)		*/
#define TCBRK	(u_char) 243	/* NVT Character BRK		*/
#define TCIP	(u_char) 244	/* Interrupt Process		*/
#define TCAO	(u_char) 245	/* Abort Output				*/
#define TCAYT	(u_char) 246	/* "Are You There" Function	*/
#define TCEC	(u_char) 247	/* Erase Character			*/
#define TCEL	(u_char) 248	/* Erase Line				*/
#define TCGA	(u_char) 249	/* "Go Ahead" Function		*/
#define TCWILL	(u_char) 251	/* Desire/Confirm Will Do 	*/
#define TCWONT	(u_char) 252	/* Refusal To Do Option		*/
#define TCDO	(u_char) 253	/* Request To Do Option		*/
#define TCDONT	(u_char) 254	/* Request NOT To Do Option	*/
#define TCIAC	(u_char) 255	/* Interpret As Command Escape	*/

//// Socket输入端有限状态机(FSM)的状态集
/* Telnet Socket-Input FSM States: */
#define TSDATA		0			/* normal data processing		*/
#define TSIAC		1			/* have seen IAC			*/
#define TSWOPT		2			/* have seen IAC-{WILL/WONT}		*/
#define TSDOPT		3			/* have seen IAC-{DO/DONT}		*/
#define TSSUBNEG	4			/* have seen IAC-SB			*/
#define TSSUBIAC	5			/* have seen IAC-SB-...-IAC		*/
#define NTSTATES	6			/* # of TS* states			*/

//// 子协商选项
/* Option Subnegotiation Constants: */
#define TT_IS	0				/* TERMINAL_TYPE option "IS" command	*/
#define TT_SEND 1				/* TERMINAL_TYPE option "SEND" command	*/

//// 子协商有限状态机(FSM)的状态集
/* Telnet Option Subnegotiation FSM States: */
#define SS_START	0			/* initial state			*/
#define SS_TERMTYPE 1			/* TERMINAL_TYPE option subnegotiation	*/
#define SS_END		2			/* state after all legal input		*/
#define NSSTATES	3			/* # of SS_* states			*/
#define FSINVALID	0xff		/* an invalid state number		*/
#define NCHRS		256			/* number of valid characters	*/
#define TCANY		(NCHRS + 1) /* match any character		*/

//// 键盘输入端有限状态机的状态集
/* Telnet Keyboard-Input FSM States: */
#define KSREMOTE	0			/* input goes to the socket		*/
#define KSLOCAL		1			/* input goes to a local func.		*/
#define KSCOLLECT	2			/* input is scripting-file name		*/
#define NKSTATES	3			/* # of KS* states			*/

//// 键盘指令字符
/* Keyboard Command Characters: */
#define KCESCAPE	035			/* Local escape character ('^]')		*/
#define KCDCON		'.'			/* Disconnect escape command			*/
#define KCSUSP		032			/* Suspend session escape command ('^Z')*/
#define KCSCRIPT	's'			/* Begin scripting escape command		*/
#define KCUNSCRIPT	'u'			/* End scripting escape command			*/
#define KCSTATUS	024			/* Print status escape command ('^T')	*/
#define KCNL		'\n'		/* Newline character					*/
#define KCANY		(NCHRS + 1)

//// Telnet 选项码
/* Telnet Option Codes: */
#define TOTXBINARY	(u_char) 0	/* TRANSMIT-BINARY option	*/
#define TOECHO		(u_char) 1	/* ECHO Option				*/
#define TONOGA		(u_char) 3	/* Suppress Go-Ahead Option	*/
#define TOTERMTYPE	(u_char) 24 /* Terminal-Type Option		*/

//// 网络虚拟打印机的特殊字符
/* Network Virtual Printer Special Characters: */
//#define VPNUL	'\0'			/* Null						*/
#define VPLF		'\n'		/* Line Feed				*/
#define VPCR		'\r'		/* Carriage Return			*/
#define VPBEL		'\a'		/* Bell (attention signal)	*/
#define VPBS		'\b'		/* Back Space				*/
#define VPHT		'\t'		/* Horizontal Tab			*/
#define VPVT		'\v'		/* Vertical Tab				*/
#define VPFF		'\f'		/* Form Feed				*/

#define TINVALID	0xff		/* an invalid transition index */
#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif /*	INADDR_NONE	,no inaddr	*/

#define TBUFSIZE	2048
#define BUFSIZE		2048		/* read buffer size	*/
#define SFBUFSZ		2048		/* script filename buffer size	*/

class CTelnet;

typedef int (CTelnet:: *FuncPointer) (FILE * sfp, FILE * tfp, int c);

//// 有限状态机 状态转换结构
struct fsm_trans
{
	unsigned char ft_state; /* current state		*/
	short ft_char;			/* input character		*/
	unsigned char ft_next;	/* next state			*/
	FuncPointer ft_action;	/* action to take		*/
};

class CTelnet
{
	/* */
	protected:
		char *host;					/* host to use if none supplied */
		char *term;					/* terminal name */
		unsigned char option_cmd;	/* has value WILL, WONT, DO, or DONT */

		char synching;				/* non-zero if we are doing telnet SYNCH	*/
		char doecho;				/* non-zero if remote ECHO					*/
		char termtype;				/* non-zero if received "DO TERMTYPE" 		*/
		char sndbinary;				/* non-zero if TRANSMIT-BINARY				*/
		char rcvbinary;				/* non-zero if remote TRANSMIT-BINARY		*/

		// script
		FILE *scrfp;
		char scrname[SFBUFSZ];
		int scrindex;

		/* Special chars: */
		char t_flushc;

		/* Special chars: */
		char t_intrc;

		/* Special chars: */
		char t_quitc;

		/* Special chars: */
		char sg_erase;

		/* Special chars: */
		char sg_kill;

		static fsm_trans sostable[];
		static fsm_trans substable[];
		static fsm_trans ttstable[];
		fsm_trans *sostab;
		fsm_trans *substab;
		fsm_trans *ttstab;

		int sostate;
		int substate;
		int ttstate;
		u_char	sofsm[NKSTATES][NCHRS];
		u_char	subfsm[NSSTATES][NCHRS];
		u_char	ttfsm[NTSTATES][NCHRS];
		int iStatus;				/* current status: 0 is OK, 1 is Error */

	/* */
	public:
		CTelnet(void)
		{
			iStatus = 0;
			sostab = sostable;
			substab = substable;
			ttstab = ttstable;
		}

		~CTelnet(void)
		{
		}

	/* */
	protected:
		/*------------------------------------------------------------------------
	 * no_op - do nothing
	 *------------------------------------------------------------------------
	 */
		int no_op(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * soputc - move a character from the keyboard to the socket
	 *------------------------------------------------------------------------
	 */
		int soputc(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * scrinit - initialize tty modes for script file collection
	 *------------------------------------------------------------------------
	 */
		int scrinit(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * unscript - end session scripting
	 *------------------------------------------------------------------------
	 */
		int unscript(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * dcon - disconnect from remote
	 *------------------------------------------------------------------------
	 */
		int dcon(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * suspend - suspend execution temporarily
	 *------------------------------------------------------------------------
	 */
		int suspend(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * status - print connection status information
	 *------------------------------------------------------------------------
	 */
		int status(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * sonotsup - an unsupported escape command
	 *------------------------------------------------------------------------
	 */
		int sonotsup(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * scrwrap - wrap-up script filename collection
	 *------------------------------------------------------------------------
	 */
		int scrwrap(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * scrgetc - begin session scripting
	 *------------------------------------------------------------------------
	 */
		int scrgetc(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * tnabort - abort telnet due to invalid state
	 *------------------------------------------------------------------------
	 */
		int tnabort(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * subtermtype - do terminal type option subnegotation
	 *------------------------------------------------------------------------
	 */
		int subtermtype(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * tcdm - handle the telnet "DATA MARK" command (marks end of SYNCH)
	 *------------------------------------------------------------------------
	 */
		int tcdm(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * recopt - record option type
	 *------------------------------------------------------------------------
	 */
		int recopt(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * subopt - do option subnegotiation FSM transitions
	 *------------------------------------------------------------------------
	 */
		int subopt(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * subend - end of an option subnegotiation; reset FSM
	 *------------------------------------------------------------------------
	 */
		int subend(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * do_echo - handle TELNET WILL/WON'T ECHO option
	 *------------------------------------------------------------------------
	 */
		int do_echo(FILE *rfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * do_noga - don't do telnet Go-Ahead's
	 *------------------------------------------------------------------------
	 */
		int do_noga(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * do_txbinary - handle telnet "will/won't" TRANSMIT-BINARY option
	 *------------------------------------------------------------------------
	 */
		int do_txbinary(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * do_notsup - handle an unsupported telnet "will/won't" option
	 *------------------------------------------------------------------------
	 */
		int do_notsup(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * will_termtype - handle telnet "do/don't" TERMINAL-TYPE option
	 *------------------------------------------------------------------------
	 */
		int will_termtype(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * will_txbinary - handle telnet "do/don't" TRANSMIT-BINARY option
	 *------------------------------------------------------------------------
	 */
		int will_txbinary(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * will_notsup - handle an unsupported telnet "do/don't" option
	 *------------------------------------------------------------------------
	 */
		int will_notsup(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * sowrite - do output processing to the socket
	 *------------------------------------------------------------------------
	 */
		int sowrite(FILE *sfp, FILE *tfp, unsigned char *buf, int cc);

		/*------------------------------------------------------------------------
	 * sowriteline - do output processing to the socket end with KCNL
	 *------------------------------------------------------------------------
	 */
		int sowriteline(FILE *sfp, FILE *tfp, unsigned char *buf, int cc);

		/*------------------------------------------------------------------------
	 * rcvurg - receive urgent data input (indicates a telnet SYNCH)
	 *------------------------------------------------------------------------
	 */
		void rcvurg(int sig);

		/*------------------------------------------------------------------------
	 * xputc - putc with optional file scripting
	 *------------------------------------------------------------------------
	 */
		int xputc(char ch, FILE *fp);

		/*------------------------------------------------------------------------
	 * xfputs - fputs with optional file scripting
	 *------------------------------------------------------------------------
	 */
		int xfputs(char *str, FILE *fp);

		/*------------------------------------------------------------------------
	 * tcout - print the indicated terminal capability on the given stream
	 *------------------------------------------------------------------------
	 */
		int tcout(char *cap, FILE *tfp);

		/*------------------------------------------------------------------------
	 * ttputc - print a single character on a Network Virtual Terminal
	 *------------------------------------------------------------------------
	 */
		int ttputc(FILE *sfp, FILE *tfp, int c);

		/*------------------------------------------------------------------------
	 * fsminit - Finite State Machine initializer
	 *------------------------------------------------------------------------
	 */
		int fsminit(
				unsigned char fsm[][NCHRS],
				struct fsm_trans ttab[],
				int nstates);

		/*------------------------------------------------------------------------
	 * fsmbuild - build the Finite State Machine data structures
	 *------------------------------------------------------------------------
	 */
		int fsmbuild(void);

		/*------------------------------------------------------------------------
	 * ttygetattr - get tty attr
	 *------------------------------------------------------------------------
	 */
		int ttygetattr(int fd, struct termios *termios_p);

		/*------------------------------------------------------------------------
	 * ttysetattr - set tty attr
	 *------------------------------------------------------------------------
	 */
		int ttysetattr(
				int fd,
				int optional_actions,
				const struct termios *termios_p);

		/*------------------------------------------------------------------------
	 * ttybackup - backup tty
	 *------------------------------------------------------------------------
	 */
		int ttybackup(void);

		/*------------------------------------------------------------------------
	 * ttyresume - resume tty
	 *------------------------------------------------------------------------
	 */
		int ttyresume(void);

		/*------------------------------------------------------------------------
	 * ttyrefresh - refresh tty
	 *------------------------------------------------------------------------
	 */
		int ttyrefresh(void);

		/*------------------------------------------------------------------------
	 * ttwrite - do output processing for (local) network virtual printer
	 *------------------------------------------------------------------------
	 */
		int ttwrite(FILE *sfp, FILE *tfp, unsigned char *buf, int cc);

		/*--------------------------------------------------------------
	 * connectsock - allocate & connect a socket using TCP or UDP
	 *--------------------------------------------------------------
	*/
		int connect_sock(const char *host, int port, const char *transport);

		/*	--------------------------------------------------------------------
	 * connect_tcp - connect a specified TCP service on a specified host
	 *----------------------------------------------------------------------
	*/
		int connect_TCP(const char *host, int port);

		/*------------------------------------------------------------------------
	 * errexit - print an error message and exit
	 *------------------------------------------------------------------------
	 */
		int errexit(const char *format, ...);
};
