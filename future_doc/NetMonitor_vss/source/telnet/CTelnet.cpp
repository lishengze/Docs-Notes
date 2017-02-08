#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LINUX
#include <term.h>
#include <termios.h>
#include <sys/file.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <curses.h>
#endif
#include "CTelnet.h"

#ifdef LINUX
termios oldtty; // 保存Telnet之前的终端环境
termios tntty;	// 保存Telnet过程中设置的新环境
#endif
fsm_trans CTelnet:: sostable[] =
{
	/* State        Input           Next State      Action  */
	/* ------       ------          -----------     ------- */
	/* Data Input */
	{ KSREMOTE, KCESCAPE, KSLOCAL, &CTelnet::no_op },
	{ KSREMOTE, KCANY, KSREMOTE, &CTelnet::soputc },

	/* Local Escape Commands */
	{ KSLOCAL, KCSCRIPT, KSCOLLECT, &CTelnet::scrinit },
	{ KSLOCAL, KCUNSCRIPT, KSREMOTE, &CTelnet::unscript },
	{ KSLOCAL, KCSUSP, KSREMOTE, &CTelnet::suspend },
	{ KSLOCAL, KCSTATUS, KSREMOTE, &CTelnet::status },
	{ KSLOCAL, KCANY, KSREMOTE, &CTelnet::sonotsup },
	{ KSLOCAL, KCDCON, KSREMOTE, &CTelnet::dcon },
	{ KSLOCAL, KCESCAPE, KSREMOTE, &CTelnet::soputc },

	/* Script Filename Gathering */
	{ KSCOLLECT, KCNL, KSREMOTE, &CTelnet::scrwrap },
	{ KSCOLLECT, KCANY, KSCOLLECT, &CTelnet::scrgetc },
	{ FSINVALID, KCANY, FSINVALID, &CTelnet::tnabort }
};

fsm_trans CTelnet:: substable[] =
{
	/* State        Input           Next State      Action  */
	/* ------       ------          -----------     ------- */
	{ SS_START, TOTERMTYPE, SS_TERMTYPE, &CTelnet::no_op },
	{ SS_START, TCANY, SS_END, &CTelnet::no_op },
	{ SS_TERMTYPE, TT_SEND, SS_END, &CTelnet::subtermtype },
	{ SS_TERMTYPE, TCANY, SS_END, &CTelnet::no_op },
	{ SS_END, TCANY, SS_END, &CTelnet::no_op },
	{ FSINVALID, TCANY, FSINVALID, &CTelnet::tnabort }
};

fsm_trans CTelnet:: ttstable[] =
{
	/* State		Input		Next State	Action	*/
	/* ------		------		-----------	-------	*/
	{ TSDATA, TCIAC, TSIAC, &CTelnet::no_op },
	{ TSDATA, TCANY, TSDATA, &CTelnet::ttputc },
	{ TSIAC, TCIAC, TSDATA, &CTelnet::ttputc },
	{ TSIAC, TCSB, TSSUBNEG, &CTelnet::no_op },

	/* Telnet Commands */
	{ TSIAC, TCNOP, TSDATA, &CTelnet::no_op },
	{ TSIAC, TCDM, TSDATA, &CTelnet::tcdm },

	/* Option Negotiation */
	{ TSIAC, TCWILL, TSWOPT, &CTelnet::recopt },
	{ TSIAC, TCWONT, TSWOPT, &CTelnet::recopt },
	{ TSIAC, TCDO, TSDOPT, &CTelnet::recopt },
	{ TSIAC, TCDONT, TSDOPT, &CTelnet::recopt },
	{ TSIAC, TCANY, TSDATA, &CTelnet::no_op },

	/* Option Subnegotion */
	{ TSSUBNEG, TCIAC, TSSUBIAC, &CTelnet::no_op },
	{ TSSUBNEG, TCANY, TSSUBNEG, &CTelnet::subopt },
	{ TSSUBIAC, TCSE, TSDATA, &CTelnet::subend },
	{ TSSUBIAC, TCANY, TSSUBNEG, &CTelnet::subopt },
	{ TSWOPT, TOECHO, TSDATA, &CTelnet::do_echo },
	{ TSWOPT, TONOGA, TSDATA, &CTelnet::do_noga },
	{ TSWOPT, TOTXBINARY, TSDATA, &CTelnet::do_txbinary },
	{ TSWOPT, TCANY, TSDATA, &CTelnet::do_notsup },
	{ TSDOPT, TOTERMTYPE, TSDATA, &CTelnet::will_termtype },
	{ TSDOPT, TOTXBINARY, TSDATA, &CTelnet::will_txbinary },
	{ TSDOPT, TCANY, TSDATA, &CTelnet::will_notsup },
	{ FSINVALID, TCANY, FSINVALID, &CTelnet::tnabort }
};

int CTelnet::ttygetattr(int fd, struct termios *termios_p)
{
#ifdef LINUX
	return tcgetattr(fd, termios_p);
#else
	return 0;
#endif
}

int CTelnet::ttysetattr(
	int fd,
	int optional_actions,
	const struct termios *termios_p)
{
#ifdef LINUX
	return tcsetattr(fd, optional_actions, termios_p);
#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * ttybackup - backup old tty
 *------------------------------------------------------------------------
 */
int CTelnet::ttybackup(void)
{
#ifdef LINUX
	if (ttygetattr(0, &oldtty) < 0)
	{				/* save original tty state	*/
		errexit("can't get tty modes: %s\n", strerror(errno));
	}

	sg_erase = oldtty.c_cc[VERASE];
	sg_kill = oldtty.c_cc[VKILL];
	t_intrc = oldtty.c_cc[VINTR];
	t_quitc = oldtty.c_cc[VQUIT];
	t_flushc = oldtty.c_cc[VDISCARD];

	tntty = oldtty; /* make a copy to change	*/

	/* disable some special characters */
	tntty.c_cc[VINTR] = _POSIX_VDISABLE;
	tntty.c_cc[VQUIT] = _POSIX_VDISABLE;
	tntty.c_cc[VSUSP] = _POSIX_VDISABLE;
#ifdef VDSUSP
	tntty.c_cc[VDSUSP] = _POSIX_VDISABLE;
#endif
	if (ttysetattr(0, TCSADRAIN, &tntty) < 0)
	{
		errexit("can't set new tty modes: %s\n", strerror(errno));
	}

#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * ttyresume - resume old tty
 *------------------------------------------------------------------------
 */
int CTelnet::ttyresume(void)
{
#ifdef LINUX
	if (ttysetattr(0, TCSADRAIN, &oldtty) < 0)
	{
		errexit("can't set old tty modes: %s\n", strerror(errno));
	}

#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * ttyrefresh - refresh tty
 *------------------------------------------------------------------------
 */
int CTelnet::ttyrefresh(void)
{
#ifdef LINUX
	if (ttysetattr(0, TCSADRAIN, &tntty) < 0)
	{
		errexit("can't set new tty modes: %s\n", strerror(errno));
	}

#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * ttwrite - do output processing for (local) network virtual printer
 *------------------------------------------------------------------------
 */
int CTelnet::ttwrite(FILE *sfp, FILE *tfp, unsigned char *buf, int cc)
{
#ifdef LINUX
	struct fsm_trans *pt;
	int i;
	int ti;

	for (i = 0; i < cc; ++i)
	{
		int c = buf[i];

		ti = ttfsm[ttstate][c];
		pt = ttstab + ti;

		FuncPointer fp = (FuncPointer) (pt->ft_action);
		(this->*fp) (sfp, tfp, c);
		ttstate = pt->ft_next;
	}

#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * errexit - print an error message and exit
 *------------------------------------------------------------------------
 */
int CTelnet::errexit(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	iStatus = 1;
	return iStatus;
}

/*------------------------------------------------------------------------
 * no_op - do nothing
 *------------------------------------------------------------------------
 */
int CTelnet::no_op(FILE *sfp, FILE *tfp, int c)
{
	return 0;
}

/*------------------------------------------------------------------------
 * soputc - move a character from the keyboard to the socket
 *------------------------------------------------------------------------
 */
int CTelnet::soputc(FILE *sfp, FILE *tfp, int c)
{
	if (sndbinary)
	{
		if (c == TCIAC)
		{
			(void)putc(TCIAC, sfp); /* byte-stuff IAC	*/
		}

		(void)putc(c, sfp);
		return 0;
	}

	c &= 0x7f;						/* 7-bit ASCII only */
	if (c == t_intrc || c == t_quitc)
	{	/* Interrupt		*/
		(void)putc(TCIAC, sfp);
		(void)putc(TCIP, sfp);
	}
	else if (c == sg_erase)
	{	/* Erase Char		*/
		(void)putc(TCIAC, sfp);
		(void)putc(TCEC, sfp);
	}
	else if (c == sg_kill)
	{	/* Erase Line		*/
		(void)putc(TCIAC, sfp);
		(void)putc(TCEL, sfp);
	}
	else if (c == t_flushc)
	{	/* Abort Output		*/
		(void)putc(TCIAC, sfp);
		(void)putc(TCAO, sfp);
	}
	else
	{
		(void)putc(c, sfp);
	}

	return 0;
}

/*------------------------------------------------------------------------
 * scrinit - initialize tty modes for script file collection
 *------------------------------------------------------------------------
 */
int CTelnet::scrinit(FILE *sfp, FILE *tfp, int c)
{
#ifdef LINUX
	struct termios	newtty;
	if (!doecho)
	{
		fprintf(tfp, "\nscripting requires remote ECHO.\n");
		return -1;
	}

	if (scrfp)
	{
		fprintf(tfp, "\nalready scripting to \"%s\".\n", scrname);
		return -1;
	}

	scrindex = 0;

	ttyrefresh();

	fprintf(tfp, "\nscript file: ");
	(void)fflush(tfp);
	return 0;
#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * unscript - end session scripting
 *------------------------------------------------------------------------
 */
int CTelnet::unscript(FILE *sfp, FILE *tfp, int c)
{
#ifdef LINUX
	struct stat statb;
	if (scrfp == 0)
	{
		fprintf(tfp, "\nNot scripting.\n");
		return 0;
	}

	(void)fflush(scrfp);
	if (fstat(fileno(scrfp), &statb) == 0)
	{
		fprintf(tfp, "\n\"%s\": %d bytes.\n", scrname, statb.st_size);
	}

	(void)fclose(scrfp);
	scrfp = 0;
	return 0;
#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * dcon - disconnect from remote
 *------------------------------------------------------------------------
 */
int CTelnet::dcon(FILE *sfp, FILE *tfp, int c)
{
	fprintf(tfp, "disconnecting.\n");
	iStatus = 1;
	return iStatus;
}

/*------------------------------------------------------------------------
 * suspend - suspend execution temporarily
 *------------------------------------------------------------------------
 */
int CTelnet::suspend(FILE *sfp, FILE *tfp, int c)
{
	// Disable suspend by Henchi
#if 1
	return 0;
#else
	ttyresume();
	(void)kill(0, SIGTSTP);
	ttyrefresh();
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * status - print connection status information
 *------------------------------------------------------------------------
 */
int CTelnet::status(FILE *sfp, FILE *tfp, int c)
{
#ifdef LINUX
	struct sockaddr_in	sin;
	int sinlen;

	fprintf(tfp, "\nconnected to \"%s\" ", host);

	sinlen = sizeof(sin);
	if (getsockname(
			fileno(sfp),
		(struct sockaddr *) &sin,
		(socklen_t *) &sinlen) == 0)
	{
		fprintf(tfp, "local port %d ", ntohs(sin.sin_port));
	}

	sinlen = sizeof(sin);
	if (getpeername(
			fileno(sfp),
		(struct sockaddr *) &sin,
		(socklen_t *) &sinlen) == 0)
	{
		fprintf(tfp, "remote port %d ", ntohs(sin.sin_port));
	}

	(void)putc('\n', tfp);
	if (doecho || sndbinary || rcvbinary)
	{
		printf("options in effect: ");
		if (doecho)
		{
			fprintf(tfp, "remote_echo ");
		}

		if (sndbinary)
		{
			fprintf(tfp, "send_binary ");
		}

		if (rcvbinary)
		{
			fprintf(tfp, "receive_binary ");
		}

		(void)putc('\n', tfp);
	}

	if (scrfp)
	{
		fprintf(tfp, "scripting to file \"%s\"\n", scrname);
	}

	return 0;
#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * sonotsup - an unsupported escape command
 *------------------------------------------------------------------------
 */
int CTelnet::sonotsup(FILE *sfp, FILE *tfp, int c)
{
	fprintf(tfp, "\nunsupported escape: %c.\n", c);
	fprintf(tfp, "s  - turn on scripting\t\t");
	fprintf(tfp, "u  - turn off scripting\n");
	fprintf(tfp, ".  - disconnect\t\t\t");
	fprintf(tfp, "^Z - suspend\n");
	fprintf(tfp, "^T - print status\n");
	return 0;
}

/*------------------------------------------------------------------------
 * scrwrap - wrap-up script filename collection
 *------------------------------------------------------------------------
 */
int CTelnet::scrwrap(FILE *sfp, FILE *tfp, int c)
{
#ifdef LINUX
	int fd;
	if (scrindex)
	{
		scrname[scrindex] = '\0';
		scrindex = 0;
		fd = open(scrname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			fprintf(
				tfp,
				"\ncan't write \"%s\": %s\n",
				scrname,
				strerror(errno));
		}
		else
		{
			scrfp = fdopen(fd, "w");
		}
	}

	ttyrefresh();

	return 0;
#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * scrgetc - begin session scripting
 *------------------------------------------------------------------------
 */
int CTelnet::scrgetc(FILE *sfp, FILE *tfp, int c)
{
	scrname[scrindex++] = c;
	if (scrindex >= SFBUFSZ)
	{	/* too far */
		fprintf(tfp, "\nname too long\n");
		ttyresume();
		return -1;
	}

	return 0;
}

/*------------------------------------------------------------------------
 * tnabort - abort telnet due to invalid state
 *------------------------------------------------------------------------
 */
int CTelnet::tnabort(FILE *sfp, FILE *tfp, int c)
{
	errexit("invalid state reached (aborting)\n");
	return 0;
}

/*------------------------------------------------------------------------
 * subtermtype - do terminal type option subnegotation
 *------------------------------------------------------------------------
 */
int CTelnet::subtermtype(FILE *sfp, FILE *tfp, int c)
{
	/* have received IAC.SB.TERMTYPE.SEND */
	(void)putc(TCIAC, sfp);
	(void)putc(TCSB, sfp);
	(void)putc(TOTERMTYPE, sfp);
	(void)putc(TT_IS, sfp);
	fputs(term, sfp);
	(void)putc(TCIAC, sfp);
	(void)putc(TCSE, sfp);
	return 0;
}

/*------------------------------------------------------------------------
 * tcdm - handle the telnet "DATA MARK" command (marks end of SYNCH)
 *------------------------------------------------------------------------
 */
int CTelnet::tcdm(FILE *sfp, FILE *tfp, int c)
{
	if (synching > 0)
	{
		synching--;
	}

	return 0;
}

/*------------------------------------------------------------------------
 * recopt - record option type
 *------------------------------------------------------------------------
 */
int CTelnet::recopt(FILE *sfp, FILE *tfp, int c)
{
	option_cmd = c;
	return 0;
}

/*------------------------------------------------------------------------
 * subopt - do option subnegotiation FSM transitions
 *------------------------------------------------------------------------
 */
int CTelnet::subopt(FILE *sfp, FILE *tfp, int c)
{
	struct fsm_trans *pt;
	int ti;

	ti = subfsm[substate][c];
	pt = substab + ti;

	FuncPointer fp = (FuncPointer) (pt->ft_action);
	(this->*fp) (sfp, tfp, c);
	substate = pt->ft_next;
	return 0;
}

/*------------------------------------------------------------------------
 * subend - end of an option subnegotiation; reset FSM
 *------------------------------------------------------------------------
 */
int CTelnet::subend(FILE *sfp, FILE *tfp, int c)
{
	substate = SS_START;
	return 0;
}

/*------------------------------------------------------------------------
 * do_echo - handle TELNET WILL/WON'T ECHO option
 *------------------------------------------------------------------------
 */
int CTelnet::do_echo(FILE *rfp, FILE *tfp, int c)
{
#ifdef LINUX
	return 0;

	struct termios	tio;
	static char savec[2];
	int ok;
	int tfd = fileno(tfp);

	if (doecho)
	{
		if (option_cmd == TCWILL)
		{
			return 0;	/* already doing ECHO		*/
		}
	}
	else if (option_cmd == TCWONT)
	{
		return 0;		/* already NOT doing ECHO	*/
		}

	if (ok = ttygetattr(tfd, &tio) == 0)
	{
		if (option_cmd == TCWILL)
		{
			tio.c_lflag &= ~(ECHO | ICANON);

			/* VMIN & VTIME are overloaded with other chars,
			 * so save and restore them later.
			 */
			savec[0] = tio.c_cc[VMIN];
			savec[1] = tio.c_cc[VTIME];
			tio.c_cc[VMIN] = 1;
			tio.c_cc[VTIME] = 0;
		}
		else
		{
			tio.c_lflag |= (ECHO | ICANON);
			tio.c_cc[VMIN] = savec[0];
			tio.c_cc[VTIME] = savec[1];
		}

		ok &= ttysetattr(tfd, TCSADRAIN, &tio) == 0;
	}

	if (ok)
	{
		doecho = !doecho;
	}

	(void)putc(TCIAC, rfp);
	if (doecho)
	{
		(void)putc(TCDO, rfp);
	}
	else
	{
		(void)putc(TCDONT, rfp);
	}

	(void)putc((char)c, rfp);
	return 0;
#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * do_noga - don't do telnet Go-Ahead's
 *------------------------------------------------------------------------
 */
int CTelnet::do_noga(FILE *sfp, FILE *tfp, int c)
{
	static int	noga;

	if (noga)
	{
		if (option_cmd == TCWILL)
		{
			return 0;
		}
	}
	else if (option_cmd == TCWONT)
	{
		return 0;
	}

	noga = !noga;
	(void)putc(TCIAC, sfp);
	if (noga)
	{
		(void)putc(TCDO, sfp);
	}
	else
	{
		(void)putc(TCDONT, sfp);
	}

	(void)putc((char)c, sfp);
	return 0;
}

/*------------------------------------------------------------------------
 * do_txbinary - handle telnet "will/won't" TRANSMIT-BINARY option
 *------------------------------------------------------------------------
 */
int CTelnet::do_txbinary(FILE *sfp, FILE *tfp, int c)
{
	if (rcvbinary)
	{
		if (option_cmd == TCWILL)
		{
			return 0;
		}
	}
	else if (option_cmd == TCWONT)
	{
		return 0;
	}

	rcvbinary = !rcvbinary;
	(void)putc(TCIAC, sfp);
	if (rcvbinary)
	{
		(void)putc(TCDO, sfp);
	}
	else
	{
		(void)putc(TCDONT, sfp);
	}

	(void)putc((char)c, sfp);
	return 0;
}

/*------------------------------------------------------------------------
 * do_notsup - handle an unsupported telnet "will/won't" option
 *------------------------------------------------------------------------
 */
int CTelnet::do_notsup(FILE *sfp, FILE *tfp, int c)
{
	(void)putc(TCIAC, sfp);
	(void)putc(TCDONT, sfp);
	(void)putc((char)c, sfp);
	return 0;
}

/*------------------------------------------------------------------------
 * will_termtype - handle telnet "do/don't" TERMINAL-TYPE option
 *------------------------------------------------------------------------
 */
int CTelnet::will_termtype(FILE *sfp, FILE *tfp, int c)
{
	if (termtype)
	{
		if (option_cmd == TCDO)
		{
			return 0;
		}
	}
	else if (option_cmd == TCDONT)
	{
		return 0;
	}

	termtype = !termtype;
	if (termtype)
	{
		if (!term && !(term = getenv("TERM")))
		{
			termtype = !termtype;	/* can't do it... */
		}
	}

	(void)putc(TCIAC, sfp);
	if (termtype)
	{
		(void)putc(TCWILL, sfp);
	}
	else
	{
		(void)putc(TCWONT, sfp);
	}

	(void)putc((char)c, sfp);
	if (termtype)
	{	/* set up binary data path; send WILL, DO */
		option_cmd = TCWILL;
		(void)do_txbinary(sfp, tfp, TOTXBINARY);
		option_cmd = TCDO;
		(void)will_txbinary(sfp, tfp, TOTXBINARY);
	}

	return 0;
}

/*------------------------------------------------------------------------
 * will_txbinary - handle telnet "do/don't" TRANSMIT-BINARY option
 *------------------------------------------------------------------------
 */
int CTelnet::will_txbinary(FILE *sfp, FILE *tfp, int c)
{
	if (sndbinary)
	{
		if (option_cmd == TCDO)
		{
			return 0;
		}
	}
	else if (option_cmd == TCDONT)
	{
		return 0;
	}

	sndbinary = !sndbinary;
	(void)putc(TCIAC, sfp);
	if (sndbinary)
	{
		(void)putc(TCWILL, sfp);
	}
	else
	{
		(void)putc(TCWONT, sfp);
	}

	(void)putc((char)c, sfp);
	return 0;
}

/*------------------------------------------------------------------------
 * will_notsup - handle an unsupported telnet "do/don't" option
 *------------------------------------------------------------------------
 */
int CTelnet::will_notsup(FILE *sfp, FILE *tfp, int c)
{
	(void)putc(TCIAC, sfp);
	(void)putc(TCWONT, sfp);
	(void)putc((char)c, sfp);
	return 0;
}

/*------------------------------------------------------------------------
 * sowrite - do output processing to the socket
 *------------------------------------------------------------------------
 */
int CTelnet::sowrite(FILE *sfp, FILE *tfp, unsigned char *buf, int cc)
{
	struct fsm_trans *pt;
	int i;
	int ki;

	for (i = 0; i < cc; ++i)
	{
		int c = buf[i];
		ki = sofsm[sostate][c];
		pt = sostab + ki;

		FuncPointer fp = (FuncPointer) (pt->ft_action);
		if (((this->*fp)) (sfp, tfp, c) < 0)
		{
			sostate = KSREMOTE; /* an error occurred	*/
		}
		else
		{
			sostate = pt->ft_next;
		}
	}

	return 0;
}

/*------------------------------------------------------------------------
 * sowrite - do output processing to the socket
 *------------------------------------------------------------------------
 */
int CTelnet::sowriteline(FILE *sfp, FILE *tfp, unsigned char *buf, int cc)
{
	struct fsm_trans *pt;
	int i;
	int ki;
	int c = 0;

	for (i = 0; i <= cc; ++i)
	{
		if (i == cc)
		{
			// 已经输出完成，若尾部无换行符，则添加
			if (c != KCNL)
			{
				c = KCNL;
			}
			else
			{
				break;
			}
		}
		else
		{
			c = buf[i];
		}

		ki = sofsm[sostate][c];
		pt = sostab + ki;

		FuncPointer fp = (FuncPointer) (pt->ft_action);
		if (((this->*fp)) (sfp, tfp, c) < 0)
		{
			sostate = KSREMOTE; /* an error occurred	*/
		}
		else
		{
			sostate = pt->ft_next;
		}
	}

	return 0;
}

/*------------------------------------------------------------------------
 * rcvurg - receive urgent data input (indicates a telnet SYNCH)
 *------------------------------------------------------------------------
 */
void CTelnet::rcvurg(int sig)
{
	synching++;
}

/*------------------------------------------------------------------------
 * xputc - putc with optional file scripting
 *------------------------------------------------------------------------
 */
int CTelnet::xputc(char ch, FILE *fp)
{
	if (scrfp)
	{
		(void)putc(ch, scrfp);
	}

	return putc(ch, fp);
}

/*------------------------------------------------------------------------
 * xfputs - fputs with optional file scripting
 *------------------------------------------------------------------------
 */
int CTelnet::xfputs(char *str, FILE *fp)
{
	if (scrfp)
	{
		fputs(str, scrfp);
	}

	fputs(str, fp);
	return 0;
}

/*------------------------------------------------------------------------
 * tcout - print the indicated terminal capability on the given stream
 *------------------------------------------------------------------------
 */
int CTelnet::tcout(char *cap, FILE *tfp)
{
#ifdef LINUX
	static int	init;
	static char *term;
	static char tbuf[TBUFSIZE];
	static char buf[TBUFSIZE];
	static char *bp = buf;
	char *sv;

	if (!init)
	{
		init = 1;
		term = getenv("TERM");
	}

	if (term == 0 || tgetent(&tbuf[0], term) != 1)
	{
		return 0;
	}

	if (sv = tgetstr(cap, &bp))
	{
		xfputs(sv, tfp);
		return 1;
	}

	return 0;
#else
	return 0;
#endif
}

/*------------------------------------------------------------------------
 * ttputc - print a single character on a Network Virtual Terminal
 *------------------------------------------------------------------------
 */
int CTelnet::ttputc(FILE *sfp, FILE *tfp, int c)
{
	static int	last_char;
	int tc;

	if (rcvbinary)
	{
		(void)xputc(c, tfp);	/* print uninterpretted	*/
		return 0;
	}

	if (synching)
	{					/* no data, if in SYNCH	*/
		return 0;
	}

	if ((last_char == VPCR && c == VPLF) || (last_char == VPLF && c == VPCR))
	{
		(void)xputc(VPLF, tfp);
		last_char = 0;
		return 0;
	}

	if (last_char == VPCR)
	{
		(void)tcout("cr", tfp);
	}
	else if (last_char == VPLF)
	{
		(void)tcout("do", tfp);
	}

	if (c >= ' ' && c < TCIAC)
	{					/* printable ASCII	*/
		(void)xputc(c, tfp);
	}
	else
	{					/* NVT special		*/
		switch (c)
		{
			case VPLF:	/* see if CR follows	*/
			case VPCR:
				tc = 1; /* see if LF follows	*/
				break;
			case VPBEL:
				tc = tcout("bl", tfp);
				break;
			case VPBS:
				tc = tcout("bc", tfp);
				break;
			case VPHT:
				tc = tcout("ta", tfp);
				break;
			case VPVT:
				tc = tcout("do", tfp);
				break;
			case VPFF:
				tc = tcout("cl", tfp);
				break;
			default:
				tc = 1;
				break;	/* no action */
		}

		if (!tc)
		{				/* if no termcap, assume ASCII */
			(void)xputc(c, tfp);
		}
	}

	last_char = c;
	return 0;
}

/*------------------------------------------------------------------------
 * fsminit - Finite State Machine initializer
 *------------------------------------------------------------------------
 */
int CTelnet::fsminit(
	unsigned char fsm[][NCHRS],
	struct fsm_trans ttab[],
	int nstates)
{
	struct fsm_trans *pt;
	int sn;
	int ti;
	int cn;

	for (cn = 0; cn < NCHRS; ++cn)
	{
		for (ti = 0; ti < nstates; ++ti)
		{
			fsm[ti][cn] = TINVALID;
		}
	}

	for (ti = 0; ttab[ti].ft_state != FSINVALID; ++ti)
	{
		pt = &ttab[ti];
		sn = pt->ft_state;
		if (pt->ft_char == TCANY)
		{
			for (cn = 0; cn < NCHRS; ++cn)
			{
				if (fsm[sn][cn] == TINVALID)
				{
					fsm[sn][cn] = ti;
				}
			}
		}
		else
		{
			fsm[sn][pt->ft_char] = ti;
		}
	}

	/* set all uninitialized indices to an invalid transition	*/
	for (cn = 0; cn < NCHRS; ++cn)
	{
		for (sn = 0; sn < nstates; ++sn)
		{
			if (fsm[sn][cn] == TINVALID)
			{
				fsm[sn][cn] = ti;
			}
		}
	}

	return 0;
}

/*------------------------------------------------------------------------
 * fsmbuild - build the Finite State Machine data structures
 *------------------------------------------------------------------------
 */
int CTelnet::fsmbuild(void)
{
	fsminit(ttfsm, ttstab, NTSTATES);
	ttstate = TSDATA;

	fsminit(sofsm, sostab, NKSTATES);
	sostate = KSREMOTE;

	fsminit(subfsm, substab, NSSTATES);
	substate = SS_START;
	return 0;
}

/*--------------------------------------------------------------
  *	connectsock	-	allocate & connect a socket using TCP or UDP
  *--------------------------------------------------------------
*/
int CTelnet::connect_sock(const char *host, int port, const char *transport)
{
#ifdef LINUX
	/*
	*arguments:
	*			host:		name of the host(name or ip) you want to connect;
	*			port: 		the port that the connection use;
	*			transport:	transport protocol("tcp" or "udp");
	*return:
	*			s:			a new descripter used to read/write;
	*/
	struct hostent	*phe;	//pointer to host info entry;
	struct protoent *ppe;	//pointer to protocol info entry;
	struct sockaddr_in	sin;		//an internet endpoint address
	int s;

	//an internet endpoint address
	int type;

	memset(&sin, 0, sizeof(sin));	//init 0
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);

	/*	Map host name to IP address,allowing for dotted decimal	*/
	if ((phe = gethostbyname(host)))
	{
		memcpy(&sin.sin_addr, phe->h_addr_list[0], phe->h_length);
	}
	else
	{	//		if ( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE )
		errexit("can't get \"%s\" host entry \n", host);
	}

	/*	Map transport protocol name to protocal number	*/
	if ((ppe = getprotobyname(transport)) == 0)
	{
		errexit("can't get \"%s\" protocol entry\n", transport);
	}

	/*	Use protocol to choose a socket type	*/
	if (strcmp(transport, "udp") == 0)
	{
		type = SOCK_DGRAM;
	}
	else
	{
		type = SOCK_STREAM;
	}

	/*	allocate a socket	*/
	s = socket(PF_INET, type, ppe->p_proto);
	if (s < 0)
	{
		errexit("can't create socket: %s\n", strerror(errno));
	}

	/*	Connect the socket	*/
	if (connect(s, (struct sockaddr *) &sin, sizeof(sin)) < 0)
	{
		errexit("can't connect to %s.%d:%s\n", host, port, strerror(errno));
	}

	return s;
#else
	return 0;
#endif
}

/*	--------------------------------------------------------------------
	*connect_tcp -	connect a specified TCP service on a specified host;
	*-------------------------------------------------------------------
*/
int CTelnet::connect_TCP(const char *host, int port)
/*
*	Argument:
*		host		- name of host which connection want;
*		port		- the port which connection use;
*	Return:
*		s			- a new descripter used to read/write;
*/
{
	return connect_sock(host, port, "tcp");
}
