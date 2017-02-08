#include "ping_common.h"

#ifdef LINUX
int CPing::__schedule_exit(int next)
{
	//unsigned long waittime;
	struct itimerval it;
	if (m_lWaittime)
	{
		if (m_lWaittime > 1000000)
		{
			m_lWaittime = m_lWaittime - 1000000;
		}
		else
		{
			m_iExiting = 1;
		}

		return next;
	}

	if (m_nReceived)
	{
		m_lWaittime = 2 * m_iTmax;
		if (m_lWaittime < 1000 * m_iInterval)
		{
			m_lWaittime = 1000 * m_iInterval;
		}
	}
	else
	{
		m_lWaittime = m_iLingertime * 1000;
	}

	if (next < 0 || next < m_lWaittime / 1000)
	{
		next = m_lWaittime / 1000;
	}

	it.it_interval.tv_sec = 0;
	it.it_interval.tv_usec = 0;
	it.it_value.tv_sec = m_lWaittime / 1000000;
	it.it_value.tv_usec = m_lWaittime % 1000000;

	//setitimer(ITIMER_REAL, &it, NULL);
	return next;
}

/* Fills all the m_ucOutpack, excluding ICMP header, but _including_
 * timestamp area with supplied pattern.
 */
int CPing::fill(char *patp)
{
	int ii = 0;

	int jj = 0;

	int kk = 0;
	int pat[16];
	char *cp;
	char *bp = (char *)(m_ucOutpack + 8);

	for (cp = patp; *cp; cp++)
	{
		if (!isxdigit(*cp))
		{
			fprintf(
				stderr,
				"ping: patterns must be specified as hex digits.\n");
			return (2);
		}
	}

	ii = sscanf(
			patp,
			"%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x%2x",
			&pat[0],
			&pat[1],
			&pat[2],
			&pat[3],
			&pat[4],
			&pat[5],
			&pat[6],
			&pat[7],
			&pat[8],
			&pat[9],
			&pat[10],
			&pat[11],
			&pat[12],
			&pat[13],
			&pat[14],
			&pat[15]);

	if (ii > 0)
	{
		for (kk = 0; kk <= m_iMaxpacket - (8 + ii); kk += ii)
		{
			for (jj = 0; jj < ii; ++jj)
			{
				bp[jj + kk] = pat[jj];
			}
		}
	}

	if (!(m_iOptions & F_QUIET))
	{
		printf("PATTERN: 0x");
		for (jj = 0; jj < ii; ++jj)
		{
			printf("%02x", bp[jj] & 0xFF);
		}

		printf("\n");
	}

	return 0;
}

int CPing::common_options(int ch)
{
	switch (ch)
	{
		case 'a':
			m_iOptions |= F_AUDIBLE;
			break;
		case 'A':
			m_iOptions |= F_ADAPTIVE;
			break;
		case 'c':
			m_nPackets = atoi(optarg);
			if (m_nPackets <= 0)
			{
				fprintf(stderr, "ping: bad number of packets to transmit.\n");
				return (2);
			}

			break;
		case 'd':
			m_iOptions |= F_SO_DEBUG;
			break;
		case 'f':
			m_iOptions |= F_FLOOD;
			setbuf(stdout, (char *)NULL);
			break;
		case 'i':	/* wait between sending packets */
			{
				if (strchr(optarg, '.'))
				{
					float t;
					if (sscanf(optarg, "%f", &t) != 1)
					{
						fprintf(stderr, "ping: bad m_iTiming interval.\n");
						return (2);
					}

					m_iInterval = (int)(t * 1000);
				}
				else if (sscanf(optarg, "%d", &m_iInterval) == 1)
				{
					m_iInterval *= 1000;
				}
				else
				{
					fprintf(stderr, "ping: bad m_iTiming interval.\n");
					return (2);
				}

				if (m_iInterval < 0)
				{
					fprintf(stderr, "ping: bad m_iTiming interval.\n");
					return (2);
				}

				m_iOptions |= F_INTERVAL;
				break;
			}

		case 'w':
			m_iDeadline = atoi(optarg);
			if (m_iDeadline < 0)
			{
				fprintf(stderr, "ping: bad wait time.\n");
				return (2);
			}

			break;
		case 'l':
			m_iPreload = atoi(optarg);
			if (m_iPreload <= 0)
			{
				fprintf(
					stderr,
					"ping: bad m_iPreload value, should be 1..%d\n",
					m_iMx_dup_ck);
				return (2);
			}

			if (m_iPreload > m_iMx_dup_ck)
			{
				m_iPreload = m_iMx_dup_ck;
			}

			if (m_iUid && m_iPreload > 3)
			{
				fprintf(stderr, "ping: cannot set m_iPreload to value > 3\n");
				return (2);
			}

			break;
		case 'S':
			m_iSndbuf = atoi(optarg);
			if (m_iSndbuf <= 0)
			{
				fprintf(stderr, "ping: bad m_iSndbuf value.\n");
				return (2);
			}

			break;
		case 'n':
			m_iOptions |= F_NUMERIC;
			break;
		case 'p':	/* fill buffer with user pattern */
			m_iOptions |= F_PINGFILLED;
			if (fill(optarg))
			{
				return (2);
			}

			break;
		case 'q':
			m_iOptions |= F_QUIET;
			break;
		case 'r':
			m_iOptions |= F_SO_DONTROUTE;
			break;
		case 's':	/* size of packet to send */
			m_iDatalen = atoi(optarg);
			if (m_iDatalen < 0)
			{
				fprintf(
					stderr,
					"ping: illegal negative packet size %d.\n",
					m_iDatalen);
				return (2);
			}

			break;
		case 'v':
			m_iOptions |= F_VERBOSE;
			break;
		case 'L':
			m_iOptions |= F_NOLOOP;
			break;
		case 't':
			m_iOptions |= F_TTL;
			m_iTtl = atoi(optarg);
			if (m_iTtl < 0 || m_iTtl > 255)
			{
				fprintf(stderr, "ping: ttl %u out of range\n", m_iTtl);
				return (2);
			}

			break;
		case 'U':
			m_iOptions |= F_LATENCY;
			break;
		case 'B':
			m_iOptions |= F_STRICTSOURCE;
			break;
		case 'W':
			m_iLingertime = atoi(optarg);
			if (m_iLingertime < 0 || m_iLingertime > INT_MAX / 1000000)
			{
				fprintf(stderr, "ping: bad linger time.\n");
				return (2);
			}

			m_iLingertime *= 1000;
			break;
		case 'V':
			printf("ping utility, iputils-ss%s\n", "020927");
			return (2);
		default:
			return (2);
			abort();
	}

	return 0;
}

void CPing::sigexit(int signo)
{
	m_iExiting = 1;
}

void CPing::sigstatus(int signo)
{
	m_iStatus_snapshot = 1;
}

/*
 * pinger --
 * 	Compose and transmit an ICMP ECHO REQUEST packet.  The IP packet
 * will be added on by the kernel.  The ID field is our UNIX process ID,
 * and the sequence number is an ascending integer.  The first 8 bytes
 * of the data portion are used to hold a UNIX "timeval" struct in VAX
 * byte-order, to compute the round-trip time.
 */
int CPing::pinger(void)
{
	int oom_count = 0;
	int tokens = 0;
	int i = 0;

	//printf("pinger m_iExiting %d m_nPackets %d m_nTransmitted %d m_nPackets %d m_iDeadline %d\n",
	//m_iExiting,m_nPackets,m_nTransmitted,m_nPackets,m_iDeadline);
	/* Have we already sent enough? If we have, return an arbitrary positive value. */
	if (m_iExiting
	||	(m_nPackets && m_nTransmitted >= m_nPackets && !m_iDeadline))
	{
		//printf("pinger return\n");
		return 1000;
	}

	/* Check that packets < rate*time + m_iPreload */
	if (m_sCur_time.tv_sec == 0)
	{
		gettimeofday(&m_sCur_time, NULL);
		tokens = m_iInterval * (m_iPreload - 1);
	}
	else
	{
		long ntokens = 0;
		struct timeval	tv;

		gettimeofday(&tv, NULL);
		ntokens = (tv.tv_sec - m_sCur_time.tv_sec) * 1000 + (tv.tv_usec - m_sCur_time.tv_usec) / 1000;
		if (!m_iInterval)
		{
			/* Case of unlimited flood is special;
			 * if we see no reply, they are limited to 100pps */
			if (ntokens < MININTERVAL && in_flight() >= m_iPreload)
			{
				//printf("1return value %d %d\n",MININTERVAL,ntokens);
				return MININTERVAL - ntokens;
			}
		}

		//		printf("ntokens %u\n", ntokens);
		//		printf("tokens  %u\n", tokens);
		ntokens += tokens;
		if (ntokens > m_iInterval * m_iPreload)
		{
			ntokens = m_iInterval * m_iPreload;
		}

		if (ntokens < m_iInterval)
		{
			//printf("2return value %u %u\n",m_iInterval,ntokens);
			return m_iInterval - ntokens;
		}

		m_sCur_time = tv;
		tokens = ntokens - m_iInterval;
	}

resend:
	i = send_probe();

	if (i == 0)
	{
		oom_count = 0;
		advance_ntransmitted();
		if (!(m_iOptions & F_QUIET) && (m_iOptions & F_FLOOD))
		{
			/* Very silly, but without this output with
			 * high m_iPreload or pipe size is very confusing. */
			if ((
					m_iPreload < m_iScreen_width
			&&	m_iPipesize < m_iScreen_width
			)
			||	in_flight() < m_iScreen_width)
			{
				write(STDOUT_FILENO, ".", 1);
			}
		}

		//printf("3return value %d %d\n",m_iInterval,tokens);
		return m_iInterval - tokens;
	}

	/* And handle various errors... */
	if (i > 0)
	{
		/* Apparently, it is some fatal bug. */
		abort();
	}
	else if (errno == ENOBUFS || errno == ENOMEM)
	{
		int nores_interval = 0;

		/* Device queue overflow or OOM. Packet is not sent. */
		tokens = 0;

		/* Slowdown. This works only in adaptive mode (option -A) */
		m_iRtt_addend += (m_iRtt < 8 * 50000 ? m_iRtt / 8 : 50000);
		if (m_iOptions & F_ADAPTIVE)
		{
			update_interval();
		}

		nores_interval = SCHINT(m_iInterval / 2);
		if (nores_interval > 500)
		{
			nores_interval = 500;
		}

		oom_count++;
		if (oom_count * nores_interval < m_iLingertime)
		{
			//printf("4return value %d \n",nores_interval);
			return nores_interval;
		}

		i = 0;

		/* Fall to hard error. It is to avoid complete deadlock
		 * on stuck output device even when dealine was not requested.
		 * Expected timings are screwed up in any case, but we will
		 * exit some day. :-) */
	}
	else if (errno == EAGAIN)
	{
		/* Socket buffer is full. */
		tokens += m_iInterval;
		return MININTERVAL;
	}
	else
	{
		if ((i = receive_error_msg()) > 0)
		{
			/* An ICMP error arrived. */
			tokens += m_iInterval;
			return MININTERVAL;
		}

		/* Compatibility with old linuces. */
		if (i == 0 && m_iConfirm_flag && errno == EINVAL)
		{
			m_iConfirm_flag = 0;
			errno = 0;
		}

		if (!errno)
		{
			goto resend;
		}
	}

	/* Hard local error. Pretend we sent packet. */
	advance_ntransmitted();

	//printf("m_iOptions %d \n",m_iOptions);
	if (i == 0 && !(m_iOptions & F_QUIET))
	{
		if (m_iOptions & F_FLOOD)
		{
			write(STDOUT_FILENO, "E", 1);
		}
		else
		{
			perror("ping: sendmsg");
		}
	}

	tokens = 0;

	//printf("5return value %d \n",SCHINT(m_iInterval));	
	return SCHINT(m_iInterval);
}

/* Set socket buffers, "alloc" is an estimate of memory taken by single packet. */
void CPing::sock_setbufs(int icmp_sock, int alloc)
{
	int rcvbuf = 0;

	int hold = 0;
	int tmplen = sizeof(hold);

	if (!m_iSndbuf)
	{
		m_iSndbuf = alloc;
	}

	setsockopt(
		icmp_sock,
		SOL_SOCKET,
		SO_SNDBUF,
		(char *) &m_iSndbuf,
		sizeof(m_iSndbuf));

	rcvbuf = hold = alloc * m_iPreload;
	if (hold < 65536)
	{
		hold = 65536;
	}

	setsockopt(icmp_sock, SOL_SOCKET, SO_RCVBUF, (char *) &hold, sizeof(hold));
	if (getsockopt(
			icmp_sock,
		SOL_SOCKET,
		SO_RCVBUF,
		(char *) &hold,
		(socklen_t *) &tmplen) == 0)
	{
		if (hold < rcvbuf)
		{
			fprintf(
				stderr,
				"WARNING: probably, rcvbuf is not enough to hold m_iPreload.\n");
		}
	}
}

/* Protocol independent setup and parameter checks. */
int CPing::setup(int icmp_sock)
{
	int hold = 0;
	struct timeval	tv;

	if ((m_iOptions & F_FLOOD) && !(m_iOptions & F_INTERVAL))
	{
		m_iInterval = 0;
	}

	if (m_iUid && m_iInterval < MINUSERINTERVAL)
	{
		fprintf(
			stderr,
			"ping: cannot flood; minimal interval, allowed for user, is %dms\n",
			MINUSERINTERVAL);
		return (2);
	}

	if (m_iInterval >= INT_MAX / m_iPreload)
	{
		fprintf(stderr, "ping: illegal m_iPreload and/or interval\n");
		return (2);
	}

	hold = 1;
	if (m_iOptions & F_SO_DEBUG)
	{
		setsockopt(
			icmp_sock,
			SOL_SOCKET,
			SO_DEBUG,
			(char *) &hold,
			sizeof(hold));
	}

	if (m_iOptions & F_SO_DONTROUTE)
	{
		setsockopt(
			icmp_sock,
			SOL_SOCKET,
			SO_DONTROUTE,
			(char *) &hold,
			sizeof(hold));
	}

#ifdef SO_TIMESTAMP
	if (!(m_iOptions & F_LATENCY))
	{
		int on = 1;
		if (setsockopt(icmp_sock, SOL_SOCKET, SO_TIMESTAMP, &on, sizeof(on)))
		{
			fprintf(
				stderr,
				"Warning: no SO_TIMESTAMP support, falling back to SIOCGSTAMP\n");
		}
	}

#endif

	/* Set some SNDTIMEO to prevent blocking forever
	 * on sends, when m_pDevice is too slow or stalls. Just put limit
	 * of one second, or "interval", if it is less.
	 */
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (m_iInterval < 1000)
	{
		tv.tv_sec = 0;
		tv.tv_usec = 1000 * SCHINT(m_iInterval);
	}

	setsockopt(icmp_sock, SOL_SOCKET, SO_SNDTIMEO, (char *) &tv, sizeof(tv));

	/* Set RCVTIMEO to "interval". Note, it is just an optimization
	 * allowing to avoid redundant poll(). */
	tv.tv_sec = SCHINT(m_iInterval) / 1000;
	tv.tv_usec = 1000 * (SCHINT(m_iInterval) % 1000);
	if (setsockopt(
			icmp_sock,
		SOL_SOCKET,
		SO_RCVTIMEO,
		(char *) &tv,
		sizeof(tv)))
	{
		m_iOptions |= F_FLOOD_POLL;
	}

	if (!(m_iOptions & F_PINGFILLED))
	{
		int i;
		char *p = (char *)(m_ucOutpack + 8);

		/* Do not forget about case of small m_iDatalen,
		 * fill timestamp area too!
		 */
		for (i = 0; i < m_iDatalen; ++i)
		{
			*p++ = i;
		}
	}

	m_iIdent = getpid() & 0xFFFF;

	// by zhou.jj
	//	set_signal(SIGINT, sigexit);
	//	set_signal(SIGALRM, sigexit);
	//	set_signal(SIGQUIT, sigstatus);
	gettimeofday(&m_sStart_time, NULL);

	if (m_iDeadline)
	{
		struct itimerval it;

		it.it_interval.tv_sec = 0;
		it.it_interval.tv_usec = 0;
		it.it_value.tv_sec = m_iDeadline;
		it.it_value.tv_usec = 0;
		m_lWaittime = m_iDeadline * 1000000;

		//setitimer(ITIMER_REAL, &it, NULL);
	}

	if (isatty(STDOUT_FILENO))
	{
		struct winsize	w;

		if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != -1)
		{
			if (w.ws_col > 0)
			{
				m_iScreen_width = w.ws_col;
			}
		}
	}

	return 0;
}

void CPing::main_loop(int icmp_sock, __u8 *packet, int packlen)
{
	char addrbuf[128];
	char ans_data[4096];
	struct iovec iov;
	struct msghdr msg;
	struct cmsghdr	*c;
	int cc = 0;
	int next = 0;
	int polling = 0;

	iov.iov_base = (char *)packet;

	for (;;)
	{
		/* Check exit conditions. */
		if (m_iExiting)
		{
			break;
		}

		if (m_nPackets && m_nReceived + m_nErrors >= m_nPackets)
		{
			break;
		}

		if (m_iDeadline && m_nErrors)
		{
			break;
		}

		/* Check for and do special actions. */
		if (m_iStatus_snapshot)
		{
			status();
		}

		/* Send probes scheduled to this time. */
		do
		{
			next = pinger();

			//printf("next %d m_iExiting %d\n",next,m_iExiting);
			next = schedule_exit(next);

			//printf("dowhile next %d m_iExiting %d\n",next,m_iExiting);
		} while (next <= 0);

		/* "next" is time to send next probe, if positive.
		 * If next<=0 send now or as soon as possible. */
		/* Technical part. Looks wicked. Could be dropped,
		 * if everyone used the newest kernel. :-) 
		 * Its purpose is:
		 * 1. Provide intervals less than resolution of scheduler.
		 *    Solution: spinning.
		 * 2. Avoid use of poll(), when recvmsg() can provide
		 *    timed waiting (SO_RCVTIMEO). */
		polling = 0;
		if ((m_iOptions & (F_ADAPTIVE | F_FLOOD_POLL))
		||	next < SCHINT(m_iInterval))
		{
			int recv_expected = in_flight();

			/* If we are here, recvmsg() is unable to wait for
			 * required timeout. */
			if (1000 * next <= 1000000 / (int)HZ)
			{
				/* Very short timeout... So, if we wait for
				 * something, we sleep for MININTERVAL.
				 * Otherwise, spin! */
				if (recv_expected)
				{
					next = MININTERVAL;
				}
				else
				{
					next = 0;

					/* When spinning, no reasons to poll.
					 * Use nonblocking recvmsg() instead. */
					polling = MSG_DONTWAIT;

					/* But yield yet. */
					sched_yield();
				}
			}

			if (!polling
			&&	((m_iOptions & (F_ADAPTIVE | F_FLOOD_POLL)) || m_iInterval))
			{
				struct pollfd pset;
				pset.fd = icmp_sock;
				pset.events = POLLIN | POLLERR;
				pset.revents = 0;
				if (poll(&pset, 1, next) < 1
				||	!(pset.revents & (POLLIN | POLLERR)))
				{
					continue;
				}

				polling = MSG_DONTWAIT;
			}
		}

		for (;;)
		{
			struct timeval	*recv_timep = NULL;
			struct timeval	recv_time;
			int not_ours = 0;	/* Raw socket can receive messages
					   * destined to other running pings. */

			iov.iov_len = packlen;
			msg.msg_name = addrbuf;
			msg.msg_namelen = sizeof(addrbuf);
			msg.msg_iov = &iov;
			msg.msg_iovlen = 1;
			msg.msg_control = ans_data;
			msg.msg_controllen = sizeof(ans_data);

			cc = recvmsg(icmp_sock, &msg, polling);
			polling = MSG_DONTWAIT;

			if (cc < 0)
			{
				if (errno == EAGAIN || errno == EINTR)
				{
					break;
				}

				if (!receive_error_msg())
				{
					if (errno)
					{
						perror("ping: recvmsg");
						break;
					}

					not_ours = 1;
				}
			}
			else
			{
#ifdef SO_TIMESTAMP
				for (c = CMSG_FIRSTHDR(&msg); c; c = CMSG_NXTHDR(&msg, c))
				{
					if (c->cmsg_level != SOL_SOCKET
					||	c->cmsg_type != SO_TIMESTAMP)
					{
						continue;
					}

					if (c->cmsg_len < CMSG_LEN(sizeof(struct timeval)))
					{
						continue;
					}

					recv_timep = (struct timeval *)CMSG_DATA(c);
				}

#endif
				if ((m_iOptions & F_LATENCY) || recv_timep == NULL)
				{
					if ((m_iOptions & F_LATENCY)
					||	ioctl(icmp_sock, SIOCGSTAMP, &recv_time))
					{
						gettimeofday(&recv_time, NULL);
					}

					recv_timep = &recv_time;
				}

				//printf("parse_reply =================\n");
				not_ours = parse_reply(&msg, cc, addrbuf, recv_timep);
			}

			/* See? ... someone runs another ping on this host. */
			if (not_ours)
			{
				install_filter();
			}

			/* If nothing is in flight, "break" returns us to pinger. */
			if (in_flight() == 0)
			{
				break;
			}

			/* Otherwise, try to recvmsg() again. recvmsg()
			 * is nonblocking after the first iteration, so that
			 * if nothing is queued, it will receive EAGAIN
			 * and return to pinger. */
		}
	}

	finish();
}

int CPing::gather_statistics(
	__u8 *ptr,
	int cc,
	__u16 seq,
	int hops,
	int csfailed,
	struct timeval	*tv,
	char *from)
{
	int dupflag = 0;
	long triptime = 0;

	++m_nReceived;
	if (!csfailed)
	{
		acknowledge(seq);
	}

	if (m_iTiming && cc >= 8 + sizeof(struct timeval))
	{
		struct timeval	tmp_tv;
		memcpy(&tmp_tv, ptr, sizeof(tmp_tv));

restamp:
		tvsub(tv, &tmp_tv);
		triptime = tv->tv_sec * 1000000 + tv->tv_usec;
		if (triptime < 0)
		{
			fprintf(
				stderr,
				"Warning: time of day goes back (%ldus), taking countermeasures.\n",
				triptime);
			triptime = 0;
			if (!(m_iOptions & F_LATENCY))
			{
				gettimeofday(tv, NULL);
				m_iOptions |= F_LATENCY;
				goto restamp;
			}
		}

		if (!csfailed)
		{
			m_lTsum += triptime;
			m_lTsum2 += (long long)triptime * (long long)triptime;
			if (triptime < m_iTmin)
			{
				m_iTmin = triptime;
			}

			if (triptime > m_iTmax)
			{
				m_iTmax = triptime;
			}

			if (!m_iRtt)
			{
				m_iRtt = triptime * 8;
			}
			else
			{
				m_iRtt += triptime - m_iRtt / 8;
			}

			if (m_iOptions & F_ADAPTIVE)
			{
				update_interval();
			}
		}
	}

	if (csfailed)
	{
		++m_nChecksum;
		--m_nReceived;
	}
	else if (TST(seq % m_iMx_dup_ck))
	{
		++m_nRepeats;
		--m_nReceived;
		dupflag = 1;
	}
	else
	{
		SET(seq % m_iMx_dup_ck);
		dupflag = 0;
	}

	m_iConfirm = m_iConfirm_flag;

	if (m_iOptions & F_QUIET)
	{
		return 1;
	}

	if (m_iOptions & F_FLOOD)
	{
		if (!csfailed)
		{
			write(STDOUT_FILENO, "\b \b", 3);
		}
		else
		{
			write(STDOUT_FILENO, "\bC", 1);
		}
	}
	else
	{
		int i;
		__u8 *cp;
		__u8 *dp;
		printf("%d bytes from %s: icmp_seq=%u", cc, from, seq);

		if (hops >= 0)
		{
			printf(" ttl=%d", hops);
		}

		if (cc < m_iDatalen + 8)
		{
			printf(" (truncated)\n");
			return 1;
		}

		if (m_iTiming)
		{
			if (triptime >= 100000)
			{
				printf(" time=%ld ms", triptime / 1000);
			}
			else if (triptime >= 10000)
			{
				printf(
					" time=%ld.%01ld ms",
					triptime / 1000,
					(triptime % 1000) / 100);
			}
			else if (triptime >= 1000)
			{
				printf(
					" time=%ld.%02ld ms",
					triptime / 1000,
					(triptime % 1000) / 10);
			}
			else
			{
				printf(" time=%ld.%03ld ms", triptime / 1000, triptime % 1000);
			}
		}

		if (dupflag)
		{
			printf(" (DUP!)");
		}

		if (csfailed)
		{
			printf(" (BAD CHECKSUM!)");
		}

		/* check the data */
		cp = ((u_char *)ptr) + sizeof(struct timeval);
		dp = &m_ucOutpack[8 + sizeof(struct timeval)];
		for (i = sizeof(struct timeval); i < m_iDatalen; ++i, ++cp, ++dp)
		{
			if (*cp != *dp)
			{
				printf(
					"\nwrong data byte #%d should be 0x%x but was 0x%x",
					i,
					*dp,
					*cp);
				cp = (u_char *)ptr + sizeof(struct timeval);
				for (i = sizeof(struct timeval); i < m_iDatalen; ++i, ++cp)
				{
					if ((i % 32) == sizeof(struct timeval))
					{
						printf("\n#%d\t", i);
					}

					printf("%x ", *cp);
				}

				break;
			}
		}
	}

	return 0;
}

long CPing::llsqrt(long long a)
{
	long long prev = ~((long long)1 << 63);
	long long x = a;

	if (x > 0)
	{
		while (x < prev)
		{
			prev = x;
			x = (x + (a / x)) / 2;
		}
	}

	return (long)x;
}

/*
 * finish --
 *	Print out statistics, and give up.
 */
void CPing::finish(void)
{
	struct timeval	tv = m_sCur_time;

	tvsub(&tv, &m_sStart_time);

	putchar('\n');
	fflush(stdout);
	printf("--- %s ping statistics ---\n", m_pHostname);
	printf("%ld packets transmitted, ", m_nTransmitted);
	printf("%ld received", m_nReceived);
	if (m_nRepeats)
	{
		printf(", +%ld duplicates", m_nRepeats);
	}

	if (m_nChecksum)
	{
		printf(", +%ld corrupted", m_nChecksum);
	}

	if (m_nErrors)
	{
		printf(", +%ld errors", m_nErrors);
	}

	if (m_nTransmitted)
	{
		printf(
			", %d%% packet loss",
			(int)
				(
					(((long long)(m_nTransmitted - m_nReceived)) * 100) /
					m_nTransmitted
				));
		printf(", time %ldms", 1000 * tv.tv_sec + tv.tv_usec / 1000);
	}

	putchar('\n');

	if (m_nReceived && m_iTiming)
	{
		long tmdev = 0;

		m_lTsum /= m_nReceived + m_nRepeats;
		m_lTsum2 /= m_nReceived + m_nRepeats;
		tmdev = llsqrt(m_lTsum2 - m_lTsum * m_lTsum);

		printf(
			"rtt min/avg/max/mdev = %ld.%03ld/%lu.%03ld/%ld.%03ld/%ld.%03ld ms",
			m_iTmin / 1000,
			m_iTmin % 1000,
			(unsigned long)(m_lTsum / 1000),
			(long)(m_lTsum % 1000),
			m_iTmax / 1000,
			m_iTmax % 1000,
			tmdev / 1000,
			tmdev % 1000);
	}

	if (m_iPipesize > 1)
	{
		printf(", pipe %d", m_iPipesize);
	}

	if (m_nTransmitted > 1
	&&	(!m_iInterval || (m_iOptions & (F_FLOOD | F_ADAPTIVE))))
	{
		int ipg = (1000000 * (long long)tv.tv_sec + tv.tv_usec) /
			(m_nTransmitted - 1);
		printf(
			", ipg/ewma %d.%03d/%d.%03d ms",
			ipg / 1000,
			ipg % 1000,
			m_iRtt / 8000,
			(m_iRtt / 8) % 1000);
	}

	putchar('\n');

	//exit(!m_nReceived || (m_iDeadline && m_nReceived < m_nPackets));
}

void CPing::status(void)
{
	int loss = 0;
	long tavg = 0;

	m_iStatus_snapshot = 0;

	if (m_nTransmitted)
	{
		loss = (((long long)(m_nTransmitted - m_nReceived)) * 100) / m_nTransmitted;
	}

	fprintf(
		stderr,
		"\r%ld/%ld packets, %d%% loss",
		m_nTransmitted,
		m_nReceived,
		loss);

	if (m_nReceived && m_iTiming)
	{
		tavg = m_lTsum / (m_nReceived + m_nRepeats);

		fprintf(
			stderr,
			", min/avg/ewma/max = %ld.%03ld/%lu.%03ld/%d.%03d/%ld.%03ld ms",
			m_iTmin / 1000,
			m_iTmin % 1000,
			tavg / 1000,
			tavg % 1000,
			m_iRtt / 8000,
			(m_iRtt / 8) % 1000,
			m_iTmax / 1000,
			m_iTmax % 1000);
	}

	fprintf(stderr, "\n");
}

int CPing::receive_error_msg(void)
{
	int res = 0;
	char cbuf[512];
	struct iovec iov;
	struct msghdr msg;
	struct cmsghdr	*pcmsghdr;
	struct sock_extended_err *e;
	struct icmphdr	icmph;
	struct sockaddr_in	target;
	int net_errors = 0;
	int local_errors = 0;
	int saved_errno = errno;

	iov.iov_base = &icmph;
	iov.iov_len = sizeof(icmph);
	msg.msg_name = (void *) &target;
	msg.msg_namelen = sizeof(target);
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	msg.msg_flags = 0;
	msg.msg_control = cbuf;
	msg.msg_controllen = sizeof(cbuf);

	res = recvmsg(m_iIcmp_sock, &msg, MSG_ERRQUEUE | MSG_DONTWAIT);
	if (res < 0)
	{
		goto out;
	}

	e = NULL;
	for (pcmsghdr = CMSG_FIRSTHDR(&msg);
		 pcmsghdr;
		 pcmsghdr = CMSG_NXTHDR(&msg, pcmsghdr))
	{
		if (pcmsghdr->cmsg_level == SOL_IP)
		{
			if (pcmsghdr->cmsg_type == IP_RECVERR)
			{
				e = (struct sock_extended_err *)CMSG_DATA(pcmsghdr);
			}
		}
	}

	if (e == NULL)
	{
		abort();
	}

	if (e->ee_origin == SO_EE_ORIGIN_LOCAL)
	{
		local_errors++;
		if (m_iOptions & F_QUIET)
		{
			goto out;
		}

		if (m_iOptions & F_FLOOD)
		{
			write(STDOUT_FILENO, "E", 1);
		}
		else if (e->ee_errno != EMSGSIZE)
		{
			fprintf(stderr, "ping: local error: %s\n", strerror(e->ee_errno));
		}
		else
		{
			fprintf(
				stderr,
				"ping: local error: Message too long, mtu=%u\n",
				e->ee_info);
		}

		m_nErrors++;
	}
	else if (e->ee_origin == SO_EE_ORIGIN_ICMP)
	{
		struct sockaddr_in	*sin = (struct sockaddr_in *)(e + 1);

		if (res < sizeof(icmph)
		||	target.sin_addr.s_addr != m_sWhereto.sin_addr.s_addr
		||	icmph.type != ICMP_ECHO
		||	icmph.un.echo.id != m_iIdent)
		{
			/* Not our error, not an error at all. Clear. */
			saved_errno = 0;
			goto out;
		}

		acknowledge(ntohs(icmph.un.echo.sequence));

		if (!m_iWorking_recverr)
		{
			struct icmp_filter	filt;
			m_iWorking_recverr = 1;

			/* OK, it works. Add stronger filter. */
			filt.data = ~
				(
					(1 << ICMP_SOURCE_QUENCH) | (1 << ICMP_REDIRECT) |
						(1 << ICMP_ECHOREPLY)
				);
			if (setsockopt(
					m_iIcmp_sock,
				SOL_RAW,
				ICMP_FILTER,
				(char *) &filt,
				sizeof(filt)) == -1)
			{
				perror("\rWARNING: setsockopt(ICMP_FILTER)");
			}
		}

		net_errors++;
		m_nErrors++;
		if (m_iOptions & F_QUIET)
		{
			goto out;
		}

		if (m_iOptions & F_FLOOD)
		{
			write(STDOUT_FILENO, "\bE", 2);
		}
		else
		{
			printf(
				"From %s icmp_seq=%u ",
				pr_addr(sin->sin_addr.s_addr),
				ntohs(icmph.un.echo.sequence));
			pr_icmph(e->ee_type, e->ee_code, e->ee_info, NULL);
			fflush(stdout);
		}
	}

out:
	errno = saved_errno;
	return net_errors ? : -local_errors;
}

/*
 * pinger --
 * 	Compose and transmit an ICMP ECHO REQUEST packet.  The IP packet
 * will be added on by the kernel.  The ID field is our UNIX process ID,
 * and the sequence number is an ascending integer.  The first 8 bytes
 * of the data portion are used to hold a UNIX "timeval" struct in VAX
 * byte-order, to compute the round-trip time.
 */
int CPing::send_probe(void)
{
	struct icmphdr	*icp;
	int cc = 0;
	int i = 0;

	icp = (struct icmphdr *)m_ucOutpack;
	icp->type = ICMP_ECHO;
	icp->code = 0;
	icp->checksum = 0;
	icp->un.echo.sequence = htons(m_nTransmitted + 1);
	icp->un.echo.id = m_iIdent; /* ID */

	CLR((m_nTransmitted + 1) % m_iMx_dup_ck);

	if (m_iTiming)
	{
		if (m_iOptions & F_LATENCY)
		{
			volatile int fake_fucked_egcs = sizeof(struct timeval);
			struct timeval	tmp_tv;
			gettimeofday(&tmp_tv, NULL);

			/* egcs is crap or glibc is crap, but memcpy 
			   does not copy anything, if len is constant! */
			memcpy(icp + 1, &tmp_tv, fake_fucked_egcs);
		}
		else
		{
			memset(icp + 1, 0, sizeof(struct timeval));
		}
	}

	cc = m_iDatalen + 8;		/* skips ICMP portion */

	/* compute ICMP checksum here */
	icp->checksum = in_cksum((u_short *)icp, cc, 0);

	if (m_iTiming && !(m_iOptions & F_LATENCY))
	{
		volatile int fake_fucked_egcs = sizeof(struct timeval);
		struct timeval	tmp_tv;
		gettimeofday(&tmp_tv, NULL);

		/* egcs is crap or glibc is crap, but memcpy 
		   does not copy anything, if len is constant! */
		memcpy(icp + 1, &tmp_tv, fake_fucked_egcs);
		icp->checksum = in_cksum(
				(u_short *) (icp + 1),
				fake_fucked_egcs,
				~icp->checksum);
	}

	do
	{
		struct iovec iov = { m_ucOutpack, 0 };
		struct msghdr m =
		{
			&m_sWhereto,
			sizeof(m_sWhereto),
			&iov,
			1,
			&m_sCmsg,
			0,
			0
		};
		m.msg_controllen = m_iCmsg_len;
		iov.iov_len = cc;

		i = sendmsg(m_iIcmp_sock, &m, m_iConfirm);
		m_iConfirm = 0;
	} while (0);

	return (cc == i ? 0 : i);
}

/*
 * parse_reply --
 *	Print out the packet, if it came from us.  This logic is necessary
 * because ALL readers of the ICMP socket get a copy of ALL ICMP packets
 * which arrive ('tis only fair).  This permits multiple copies of this
 * program to be run without having intermingled output (or statistics!).
 */
int CPing::parse_reply(
	struct msghdr *msg,
	int cc,
	void *addr,
	struct timeval	*tv)
{
	struct sockaddr_in	*from = (struct sockaddr_in *)addr;
	__u8 *buf = (__u8 *)msg->msg_iov->iov_base;
	struct icmphdr	*icp;
	struct iphdr *ip;
	int hlen = 0;
	int csfailed = 0;

	/* Check the IP header */
	ip = (struct iphdr *)buf;
	hlen = ip->ihl * 4;
	if (cc < hlen + 8 || ip->ihl < 5)
	{
		if (m_iOptions & F_VERBOSE)
		{
			fprintf(
				stderr,
				"ping: packet too short (%d bytes) from %s\n",
				cc,
				pr_addr(from->sin_addr.s_addr));
		}

		return 1;
	}

	/* Now the ICMP part */
	cc -= hlen;
	icp = (struct icmphdr *)(buf + hlen);
	csfailed = in_cksum((u_short *)icp, cc, 0);

	std::string fromip = pr_addr(from->sin_addr.s_addr);
	if (fromip.compare(m_pHostname) != 0)
	{
		//	printf("from ip:%s not sourceip:%s\n", fromip.c_str(), m_pHostname);
		return 0;
	}

	if (icp->type == ICMP_ECHOREPLY)
	{
		if (icp->un.echo.id != m_iIdent)
		{
			return 1;					/* 'Twas not our ECHO */
		}

		if (gather_statistics(
				(__u8 *) (icp + 1),
			cc,
			ntohs(icp->un.echo.sequence),
			ip->ttl,
			0,
			tv,
			pr_addr(from->sin_addr.s_addr)))
		{
			return 0;
		}
	}
	else
	{
		/* We fall here when a redirect or m_sSource quench arrived.
		 * Also this branch processes icmp errors, when IP_RECVERR
		 * is broken. */
		switch (icp->type)
		{
			case ICMP_ECHO:
				/* MUST NOT */
				return 1;
			case ICMP_SOURCE_QUENCH:
			case ICMP_REDIRECT:
			case ICMP_DEST_UNREACH:
			case ICMP_TIME_EXCEEDED:
			case ICMP_PARAMETERPROB:
				{
					struct iphdr *iph = (struct iphdr *)(&icp[1]);
					struct icmphdr	*icp1 = (struct icmphdr *)
						((unsigned char *)iph + iph->ihl * 4);
					int error_pkt;
					if (cc < 8 + sizeof(struct iphdr) + 8
					||	cc < 8 + iph->ihl * 4 + 8)
					{
						return 1;
					}

					if (icp1->type != ICMP_ECHO
					||	iph->daddr != m_sWhereto.sin_addr.s_addr
					||	icp1->un.echo.id != m_iIdent)
					{
						return 1;
					}

					error_pkt =
						(
							icp->type != ICMP_REDIRECT
						&&	icp->type != ICMP_SOURCE_QUENCH
						);
					if (error_pkt)
					{
						acknowledge(ntohs(icp1->un.echo.sequence));
						if (m_iWorking_recverr)
						{
							return 0;
						}
						else
						{
							//int once=0;
							/* Sigh, IP_RECVERR for raw socket
						 * was broken until 2.4.9. So, we ignore
						 * the first error and warn on the second.
						 */
							if (m_iErrOnce++ == 1)
							{
								fprintf(
									stderr,
									"\rWARNING: kernel is not very fresh, upgrade is recommended.\n");
							}

							if (m_iErrOnce == 1)
							{
								return 0;
							}
						}
					}

					m_nErrors += error_pkt;
					if (m_iOptions & F_QUIET)
					{
						return !error_pkt;
					}

					if (m_iOptions & F_FLOOD)
					{
						if (error_pkt)
						{
							write(STDOUT_FILENO, "\bE", 2);
						}

						return !error_pkt;
					}

					printf(
						"From %s: icmp_seq=%u ",
						pr_addr(from->sin_addr.s_addr),
						ntohs(icp1->un.echo.sequence));
					if (csfailed)
					{
						printf("(BAD CHECKSUM)");
					}

					pr_icmph(icp->type, icp->code, ntohl(icp->un.gateway), icp);
					return !error_pkt;
				}

			default:
				/* MUST NOT */
				break;
		}

		if ((m_iOptions & F_FLOOD) && !(m_iOptions & (F_VERBOSE | F_QUIET)))
		{
			if (!csfailed)
			{
				write(STDOUT_FILENO, "!E", 2);
			}
			else
			{
				write(STDOUT_FILENO, "!EC", 3);
			}

			return 0;
		}

		if (!(m_iOptions & F_VERBOSE) || m_iUid)
		{
			return 0;
		}

		printf("From %s: ", pr_addr(from->sin_addr.s_addr));
		if (csfailed)
		{
			printf("(BAD CHECKSUM)\n");
			return 0;
		}

		pr_icmph(icp->type, icp->code, ntohl(icp->un.gateway), icp);
		return 0;
	}

	if (!(m_iOptions & F_FLOOD))
	{
		pr_options(buf + sizeof(struct iphdr), hlen);

		if (m_iOptions & F_AUDIBLE)
		{
			putchar('\a');
		}

		putchar('\n');
		fflush(stdout);
	}

	return 0;
}

u_short CPing::in_cksum(const u_short *addr, register int len, u_short csum)
{
	register int nleft = len;
	const u_short *w = addr;
	register u_short answer;
	register int sum = csum;

	/*
	 *  Our algorithm is simple, using a 32 bit accumulator (sum),
	 *  we add sequential 16 bit words to it, and at the end, fold
	 *  back all the carry bits from the top 16 bits into the lower
	 *  16 bits.
	 */
	while (nleft > 1)
	{
		sum += *w++;
		nleft -= 2;
	}

	/* mop up an odd byte, if necessary */
	if (nleft == 1)
	{
		sum += htons(*(u_char *)w << 8);
	}

	/*
	 * add back carry outs from top 16 bits to low 16 bits
	 */
	sum = (sum >> 16) + (sum & 0xffff); /* add hi 16 to low 16 */
	sum += (sum >> 16);					/* add carry */
	answer = ~sum;						/* truncate to 16 bits */
	return (answer);
}

/*
 * pr_icmph --
 *	Print a descriptive string about an ICMP header.
 */
void CPing::pr_icmph(__u8 type, __u8 code, __u32 info, struct icmphdr *icp)
{
	switch (type)
	{
		case ICMP_ECHOREPLY:
			printf("Echo Reply\n");

			/* XXX ID + Seq + Data */
			break;
		case ICMP_DEST_UNREACH:
			switch (code)
			{
				case ICMP_NET_UNREACH:
					printf("Destination Net Unreachable\n");
					break;
				case ICMP_HOST_UNREACH:
					printf("Destination Host Unreachable\n");
					break;
				case ICMP_PROT_UNREACH:
					printf("Destination Protocol Unreachable\n");
					break;
				case ICMP_PORT_UNREACH:
					printf("Destination Port Unreachable\n");
					break;
				case ICMP_FRAG_NEEDED:
					printf("Frag needed and DF set (mtu = %u)\n", info);
					break;
				case ICMP_SR_FAILED:
					printf("Source Route Failed\n");
					break;
				case ICMP_PKT_FILTERED:
					printf("Packet filtered\n");
					break;
				default:
					printf("Dest Unreachable, Bad Code: %d\n", code);
					break;
			}

			if (icp && (m_iOptions & F_VERBOSE))
			{
				pr_iph((struct iphdr *)(icp + 1));
			}

			break;
		case ICMP_SOURCE_QUENCH:
			printf("Source Quench\n");
			if (icp && (m_iOptions & F_VERBOSE))
			{
				pr_iph((struct iphdr *)(icp + 1));
			}

			break;
		case ICMP_REDIRECT:
			switch (code)
			{
				case ICMP_REDIR_NET:
					printf("Redirect Network");
					break;
				case ICMP_REDIR_HOST:
					printf("Redirect Host");
					break;
				case ICMP_REDIR_NETTOS:
					printf("Redirect Type of Service and Network");
					break;
				case ICMP_REDIR_HOSTTOS:
					printf("Redirect Type of Service and Host");
					break;
				default:
					printf("Redirect, Bad Code: %d", code);
					break;
			}

			if (icp)
			{
				printf("(New nexthop: %s)\n", pr_addr(icp->un.gateway));
			}

			if (icp && (m_iOptions & F_VERBOSE))
			{
				pr_iph((struct iphdr *)(icp + 1));
			}

			break;
		case ICMP_ECHO:
			printf("Echo Request\n");

			/* XXX ID + Seq + Data */
			break;
		case ICMP_TIME_EXCEEDED:
			switch (code)
			{
				case ICMP_EXC_TTL:
					printf("Time to live exceeded\n");
					break;
				case ICMP_EXC_FRAGTIME:
					printf("Frag reassembly time exceeded\n");
					break;
				default:
					printf("Time exceeded, Bad Code: %d\n", code);
					break;
			}

			if (icp && (m_iOptions & F_VERBOSE))
			{
				pr_iph((struct iphdr *)(icp + 1));
			}

			break;
		case ICMP_PARAMETERPROB:
			printf(
				"Parameter problem: pointer = %u\n",
				icp ? (ntohl(icp->un.gateway) >> 24) : info);
			if (icp && (m_iOptions & F_VERBOSE))
			{
				pr_iph((struct iphdr *)(icp + 1));
			}

			break;
		case ICMP_TIMESTAMP:
			printf("Timestamp\n");

			/* XXX ID + Seq + 3 timestamps */
			break;
		case ICMP_TIMESTAMPREPLY:
			printf("Timestamp Reply\n");

			/* XXX ID + Seq + 3 timestamps */
			break;
		case ICMP_INFO_REQUEST:
			printf("Information Request\n");

			/* XXX ID + Seq */
			break;
		case ICMP_INFO_REPLY:
			printf("Information Reply\n");

			/* XXX ID + Seq */
			break;
	#ifdef ICMP_MASKREQ
		case ICMP_MASKREQ:
			printf("Address Mask Request\n");
			break;
	#endif
	#ifdef ICMP_MASKREPLY
		case ICMP_MASKREPLY:
			printf("Address Mask Reply\n");
			break;
	#endif
		default:
			printf("Bad ICMP type: %d\n", type);
	}
}

void CPing::pr_options(unsigned char *cp, int hlen)
{
	int i = 0;

	int j = 0;
	int totlen = 0;
	unsigned char *optptr;
	int old_rrlen = 0;
	char old_rr[MAX_IPOPTLEN];

	totlen = hlen - sizeof(struct iphdr);
	optptr = cp;

	while (totlen > 0)
	{
		if (*optptr == IPOPT_EOL)
		{
			break;
		}

		if (*optptr == IPOPT_NOP)
		{
			totlen--;
			optptr++;
			printf("\nNOP");
			continue;
		}

		cp = optptr;
		m_iOptlen = optptr[1];
		if (m_iOptlen < 2 || m_iOptlen > totlen)
		{
			break;
		}

		switch (*cp)
		{
			case IPOPT_SSRR:
			case IPOPT_LSRR:
				printf("\n%cSRR: ", *cp == IPOPT_SSRR ? 'S' : 'L');
				j = *++cp;
				i = *++cp;
				i -= 4;
				cp++;
				if (j > IPOPT_MINOFF)
				{
					for (;;)
					{
						__u32 address;
						memcpy(&address, cp, 4);
						cp += 4;
						if (address == 0)
						{
							printf("\t0.0.0.0");
						}
						else
						{
							printf("\t%s", pr_addr(address));
						}

						j -= 4;
						putchar('\n');
						if (j <= IPOPT_MINOFF)
						{
							break;
						}
					}
				}

				break;
			case IPOPT_RR:
				j = *++cp;		/* get length */
				i = *++cp;		/* and pointer */
				if (i > j)
				{
					i = j;
				}

				i -= IPOPT_MINOFF;
				if (i <= 0)
				{
					continue;
				}

				if (i == old_rrlen
				&&	!bcmp((char *)cp, old_rr, i)
				&&	!(m_iOptions & F_FLOOD))
				{
					printf("\t(same route)");
					i = ((i + 3) / 4) * 4;
					cp += i;
					break;
				}

				old_rrlen = i;
				bcopy((char *)cp, old_rr, i);
				printf("\nRR: ");
				cp++;
				for (;;)
				{
					__u32 address;
					memcpy(&address, cp, 4);
					cp += 4;
					if (address == 0)
					{
						printf("\t0.0.0.0");
					}
					else
					{
						printf("\t%s", pr_addr(address));
					}

					i -= 4;
					putchar('\n');
					if (i <= 0)
					{
						break;
					}
				}

				break;
			case IPOPT_TS:
				{
					int stdtime = 0;

					int nonstdtime = 0;
					__u8 flags;
					j = *++cp;	/* get length */
					i = *++cp;	/* and pointer */
					if (i > j)
					{
						i = j;
					}

					i -= 5;
					if (i <= 0)
					{
						continue;
					}

					flags = *++cp;
					printf("\nTS: ");
					cp++;
					for (;;)
					{
						long l;

						if ((flags & 0xF) != IPOPT_TS_TSONLY)
						{
							__u32 address;
							memcpy(&address, cp, 4);
							cp += 4;
							if (address == 0)
							{
								printf("\t0.0.0.0");
							}
							else
							{
								printf("\t%s", pr_addr(address));
							}

							i -= 4;
							if (i <= 0)
							{
								break;
							}
						}

						l = *cp++;
						l = (l << 8) +*cp++;
						l = (l << 8) +*cp++;
						l = (l << 8) +*cp++;

						if (l & 0x80000000)
						{
							if (nonstdtime == 0)
							{
								printf(
									"\t%ld absolute not-standard",
									l & 0x7fffffff);
							}
							else
							{
								printf(
									"\t%ld not-standard",
									(l & 0x7fffffff) - nonstdtime);
							}

							nonstdtime = l & 0x7fffffff;
						}
						else
						{
							if (stdtime == 0)
							{
								printf("\t%ld absolute", l);
							}
							else
							{
								printf("\t%ld", l - stdtime);
							}

							stdtime = l;
						}

						i -= 4;
						putchar('\n');
						if (i <= 0)
						{
							break;
						}
					}

					if (flags >> 4)
					{
						printf("Unrecorded hops: %d\n", flags >> 4);
					}

					break;
				}

			default:
				printf("\nunknown option %x", *cp);
				break;
		}

		totlen -= m_iOptlen;
		optptr += m_iOptlen;
	}
}

/*
 * pr_iph --
 *	Print an IP header with options.
 */
void CPing::pr_iph(struct iphdr *ip)
{
	int hlen = 0;
	u_char	*cp;

	hlen = ip->ihl << 2;
	cp = (u_char *)ip + 20; /* point to options */

	printf(
		"Vr HL TOS  Len   ID Flg  off TTL Pro  cks      Src      Dst Data\n");
	printf(
		" %1x  %1x  %02x %04x %04x",
		ip->version,
		ip->ihl,
		ip->tos,
		ip->tot_len,
		ip->id);
	printf(
		"   %1x %04x",
		((ip->frag_off) & 0xe000) >> 13,
		(ip->frag_off) & 0x1fff);
	printf("  %02x  %02x %04x", ip->ttl, ip->protocol, ip->check);
	printf(" %s ", inet_ntoa(*(struct in_addr *) &ip->saddr));
	printf(" %s ", inet_ntoa(*(struct in_addr *) &ip->daddr));
	printf("\n");
	pr_options(cp, hlen);
}

/*
 * pr_addr --
 *	Return an ascii host address as a dotted quad and optionally with
 * a hostname.
 */
char *CPing::pr_addr(__u32 addr)
{
	struct hostent	*hp;
	static char buf[4096];

	if ((m_iOptions & F_NUMERIC)
	||	!(hp = gethostbyaddr((char *) &addr, 4, AF_INET)))
	{
		sprintf(buf, "%s", inet_ntoa(*(struct in_addr *) &addr));
	}
	else
	{
		snprintf(
			buf,
			sizeof(buf),
			"%s (%s)",
			hp->h_name,
			inet_ntoa(*(struct in_addr *) &addr));
	}

	return (buf);
}

/* Set Type of Service (TOS) and other Quality of Service relating bits */
int CPing::parsetos(char *str)
{
	const char	*cp;
	int tos = 0;
	char *ep;

	/* handle both hex and decimal values */
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		cp = str + 2;
		tos = (int)strtol(cp, &ep, 16);
	}
	else
	{
		tos = (int)strtol(str, &ep, 10);
	}

	/* doesn't look like decimal or hex, eh? */
	if (*ep != '\0')
	{
		fprintf(stderr, "ping: \"%s\" bad value for TOS\n", str);
		exit(2);
	}

	if (tos > TOS_MAX)
	{
		fprintf(
			stderr,
			"ping: the decimal value of TOS bits must be 0-254 (or zero)\n");
		exit(2);
	}

	return (tos);
}

void CPing::install_filter(void)
{
	//int once=0;
	sock_filter insns[] =
	{
		BPF_STMT(BPF_LDX | BPF_B | BPF_MSH, 0),						/* Skip IP header. F..g BSD... Look into ping6. */
		BPF_STMT(BPF_LD | BPF_H | BPF_IND, 4),						/* Load icmp echo m_iIdent */
		BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, 0xAAAA, 0, 1),			/* Ours? */
		BPF_STMT(BPF_RET | BPF_K, ~0U),								/* Yes, it passes. */
		BPF_STMT(BPF_LD | BPF_B | BPF_IND, 0),						/* Load icmp type */
		BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, ICMP_ECHOREPLY, 1, 0),	/* Echo? */
		BPF_STMT(BPF_RET | BPF_K, 0xFFFFFFF),						/* No. It passes. */
		BPF_STMT(BPF_RET | BPF_K, 0)	/* Echo with wrong m_iIdent. Reject. */
	};
	struct sock_fprog filter = { sizeof insns / sizeof(insns[0]), insns };

	if (m_iOnce)
	{
		return;
	}

	m_iOnce = 1;

	/* Patch bpflet for current identifier. */
	insns[2] = (struct sock_filter)BPF_JUMP(
			BPF_JMP | BPF_JEQ | BPF_K,
			htons(m_iIdent),
			0,
			1);

	if (setsockopt(
			m_iIcmp_sock,
		SOL_SOCKET,
		SO_ATTACH_FILTER,
		&filter,
		sizeof(filter)))
	{
		perror("WARNING: failed to install socket filter\n");
	}
}

void CPing::usage(void)
{
	fprintf(
		stderr,
		"Usage: ping [-LRUbdfnqrvVaA] [-c count] [-i interval] [-w m_iDeadline]\n"
		"            [-p pattern] [-s packetsize] [-t ttl] [-I interface or address]\n"
		"            [-M mtu discovery hint] [-S m_iSndbuf]\n"
		"            [ -T timestamp option ] [ -Q tos ] [hop1 ...] destination\n"
		"   attention:need set to root suid, excute 'chown root ping' and 'chmod u+s ping' \n");
	exit(2);
}

#endif
int CPing::run(void)
{
#ifdef LINUX
	struct hostent	*hp;
	int ch;
	int hold;
	int packlen;
	int socket_errno;
	u_char	*packet;
	char hnamebuf[MAXHOSTNAMELEN];
	char rspace[3 + 4 * NROUTES + 1];	/* record route space */

	m_iIcmp_sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	socket_errno = errno;

	m_iUid = getuid();

	//setuid(m_iUid);
	m_sSource.sin_family = AF_INET;
	m_iPreload = 1;

	bzero((char *) &m_sWhereto, sizeof(m_sWhereto));
	m_sWhereto.sin_family = AF_INET;

	//printf("m_pHostname [%s]\n",m_pHostname);
	if (inet_aton(m_pHostname, &m_sWhereto.sin_addr) == 1)
	{
		//printf("1 m_pHostname [%s]\n",m_pHostname);
		m_iOptions |= F_NUMERIC;
	}
	else
	{
		hp = gethostbyname(m_pHostname);
		if (!hp)
		{
			fprintf(stderr, "ping: unknown host %s\n", m_pHostname);
			return (2);
		}

		memcpy(&m_sWhereto.sin_addr, hp->h_addr, 4);
		strncpy(hnamebuf, hp->h_name, sizeof(hnamebuf) - 1);
		hnamebuf[sizeof(hnamebuf) - 1] = 0;

		//m_pHostname = hnamebuf;
		//printf("2 m_pHostname [%s]\n",m_pHostname);
	}

	if (m_sSource.sin_addr.s_addr == 0)
	{
		int alen;
		struct sockaddr_in	dst = m_sWhereto;
		int probe_fd = socket(AF_INET, SOCK_DGRAM, 0);

		if (probe_fd < 0)
		{
			perror("socket");
			return (2);
		}

		if (m_pDevice)
		{
			struct ifreq ifr;
			memset(&ifr, 0, sizeof(ifr));
			strncpy(ifr.ifr_name, m_pDevice, IFNAMSIZ - 1);
			if (setsockopt(
					probe_fd,
				SOL_SOCKET,
				SO_BINDTODEVICE,
				m_pDevice,
				strlen(m_pDevice) + 1) == -1)
			{
				if (IN_MULTICAST(ntohl(dst.sin_addr.s_addr)))
				{
					struct ip_mreqn imr;
					if (ioctl(probe_fd, SIOCGIFINDEX, &ifr) < 0)
					{
						fprintf(stderr, "ping: unknown iface %s\n", m_pDevice);
						return (2);
					}

					memset(&imr, 0, sizeof(imr));
					imr.imr_ifindex = ifr.ifr_ifindex;
					if (setsockopt(
							probe_fd,
						SOL_IP,
						IP_MULTICAST_IF,
						&imr,
						sizeof(imr)) == -1)
					{
						perror("ping: IP_MULTICAST_IF");
						return (2);
					}
				}
			}
		}

		if (m_iSettos
		&&	setsockopt(
				probe_fd,
			IPPROTO_IP,
			IP_TOS,
			(char *) &m_iSettos,
			sizeof(int)) < 0)
		{
			perror("Warning: error setting QOS sockopts");
		}

		dst.sin_port = htons(1025);
		if (m_iNroute)
		{
			dst.sin_addr.s_addr = m_aRoute[0];
		}

		if (connect(probe_fd, (struct sockaddr *) &dst, sizeof(dst)) == -1)
		{
			if (errno == EACCES)
			{
				if (m_iBroadcast_pings == 0)
				{
					fprintf(stderr, "Do you want to ping broadcast? Then -b\n");
					return (2);
				}

				fprintf(stderr, "WARNING: pinging broadcast address\n");
				if (setsockopt(
						probe_fd,
					SOL_SOCKET,
					SO_BROADCAST,
					&m_iBroadcast_pings,
					sizeof(m_iBroadcast_pings)) < 0)
				{
					perror("can't set broadcasting");
					return (2);
				}

				if (connect(
						probe_fd,
					(struct sockaddr *) &dst,
					sizeof(dst)) == -1)
				{
					perror("connect");
					return (2);
				}
			}
			else
			{
				perror("connect");
				return (2);
			}
		}

		alen = sizeof(m_sSource);
		if (getsockname(
				probe_fd,
			(struct sockaddr *) &m_sSource,
			(socklen_t *) &alen) == -1)
		{
			perror("getsockname");
			return (2);
		}

		m_sSource.sin_port = 0;
		close(probe_fd);
	}

	while (0);

	if (m_sWhereto.sin_addr.s_addr == 0)
	{
		m_sWhereto.sin_addr.s_addr = m_sSource.sin_addr.s_addr;
	}

	if (m_iIcmp_sock < 0)
	{
		errno = socket_errno;
		perror("ping: icmp open socket");
		return (2);
	}

	if (m_pDevice)
	{
		struct ifreq ifr;

		memset(&ifr, 0, sizeof(ifr));
		strncpy(ifr.ifr_name, m_pDevice, IFNAMSIZ - 1);
		if (ioctl(m_iIcmp_sock, SIOCGIFINDEX, &ifr) < 0)
		{
			fprintf(stderr, "ping: unknown iface %s\n", m_pDevice);
			return (2);
		}

		m_sCmsg.ipi.ipi_ifindex = ifr.ifr_ifindex;
		m_iCmsg_len = sizeof(m_sCmsg);
	}

	if (m_iBroadcast_pings || IN_MULTICAST(ntohl(m_sWhereto.sin_addr.s_addr)))
	{
		if (m_iUid)
		{
			if (m_iInterval < 1000)
			{
				fprintf(
					stderr,
					"ping: broadcast ping with too short interval.\n");
				return (2);
			}

			if (m_iPmtudisc >= 0 && m_iPmtudisc != IP_PMTUDISC_DO)
			{
				fprintf(stderr, "ping: broadcast ping does not fragment.\n");
				return (2);
			}
		}

		if (m_iPmtudisc < 0)
		{
			m_iPmtudisc = IP_PMTUDISC_DO;
		}
	}

	if (m_iPmtudisc >= 0)
	{
		if (setsockopt(
				m_iIcmp_sock,
			SOL_IP,
			IP_MTU_DISCOVER,
			&m_iPmtudisc,
			sizeof(m_iPmtudisc)) == -1)
		{
			perror("ping: IP_MTU_DISCOVER");
			return (2);
		}
	}

	if ((m_iOptions & F_STRICTSOURCE)
	&&	bind(
			m_iIcmp_sock,
		(struct sockaddr *) &m_sSource,
		sizeof(m_sSource)) == -1)
	{
		perror("bind");
		return (2);
	}

	if (1)
	{
		struct icmp_filter	filt;
		filt.data = ~
			(
				(1 << ICMP_SOURCE_QUENCH) | (1 << ICMP_DEST_UNREACH) |
					(1 << ICMP_TIME_EXCEEDED) | (1 << ICMP_PARAMETERPROB) |
						(1 << ICMP_REDIRECT) | (1 << ICMP_ECHOREPLY)
			);
		if (setsockopt(
				m_iIcmp_sock,
			SOL_RAW,
			ICMP_FILTER,
			(char *) &filt,
			sizeof(filt)) == -1)
		{
			perror("WARNING: setsockopt(ICMP_FILTER)");
		}
	}

	hold = 1;
	if (setsockopt(
			m_iIcmp_sock,
		SOL_IP,
		IP_RECVERR,
		(char *) &hold,
		sizeof(hold)))
	{
		fprintf(stderr, "WARNING: your kernel is veeery old. No problems.\n");
	}

	/* record route option */
	if (m_iOptions & F_RROUTE)
	{
		bzero(rspace, sizeof(rspace));
		rspace[0] = IPOPT_NOP;
		rspace[1 + IPOPT_OPTVAL] = IPOPT_RR;
		rspace[1 + IPOPT_OLEN] = sizeof(rspace) - 1;
		rspace[1 + IPOPT_OFFSET] = IPOPT_MINOFF;
		m_iOptlen = 40;
		if (setsockopt(
				m_iIcmp_sock,
			IPPROTO_IP,
			IP_OPTIONS,
			rspace,
			sizeof(rspace)) < 0)
		{
			perror("ping: record route");
			return (2);
		}
	}

	if (m_iOptions & F_TIMESTAMP)
	{
		bzero(rspace, sizeof(rspace));
		rspace[0] = IPOPT_TIMESTAMP;
		rspace[1] = (m_iTs_type == IPOPT_TS_TSONLY ? 40 : 36);
		rspace[2] = 5;
		rspace[3] = m_iTs_type;
		if (m_iTs_type == IPOPT_TS_PRESPEC)
		{
			int i;
			rspace[1] = 4 + m_iNroute * 8;
			for (i = 0; i < m_iNroute; i++)
			{
				*(__u32 *) &rspace[4 + i * 8] = m_aRoute[i];
			}
		}

		if (setsockopt(
				m_iIcmp_sock,
			IPPROTO_IP,
			IP_OPTIONS,
			rspace,
			rspace[1]) < 0)
		{
			rspace[3] = 2;
			if (setsockopt(
					m_iIcmp_sock,
				IPPROTO_IP,
				IP_OPTIONS,
				rspace,
				rspace[1]) < 0)
			{
				perror("ping: ts option");
				return (2);
			}
		}

		m_iOptlen = 40;
	}

	if (m_iOptions & F_SOURCEROUTE)
	{
		int i;
		bzero(rspace, sizeof(rspace));
		rspace[0] = IPOPT_NOOP;
		rspace[1 + IPOPT_OPTVAL] = (m_iOptions & F_SO_DONTROUTE) ? IPOPT_SSRR : IPOPT_LSRR;
		rspace[1 + IPOPT_OLEN] = 3 + m_iNroute * 4;
		rspace[1 + IPOPT_OFFSET] = IPOPT_MINOFF;
		for (i = 0; i < m_iNroute; i++)
		{
			*(__u32 *) &rspace[4 + i * 4] = m_aRoute[i];
		}

		if (setsockopt(
				m_iIcmp_sock,
			IPPROTO_IP,
			IP_OPTIONS,
			rspace,
			4 + m_iNroute * 4) < 0)
		{
			perror("ping: record route");
			return (2);
		}

		m_iOptlen = 40;
	}

	/* Estimate memory eaten by single packet. It is rough estimate.
	 * Actually, for small m_iDatalen's it depends on kernel side a lot. */
	hold = m_iDatalen + 8;
	hold += ((hold + 511) / 512) * (m_iOptlen + 20 + 16 + 64 + 160);
	sock_setbufs(m_iIcmp_sock, hold);

	if (m_iBroadcast_pings)
	{
		if (setsockopt(
				m_iIcmp_sock,
			SOL_SOCKET,
			SO_BROADCAST,
			&m_iBroadcast_pings,
			sizeof(m_iBroadcast_pings)) < 0)
		{
			perror("ping: can't set broadcasting");
			return (2);
		}
	}

	if (m_iOptions & F_NOLOOP)
	{
		int loop = 0;
		if (setsockopt(
				m_iIcmp_sock,
			IPPROTO_IP,
			IP_MULTICAST_LOOP,
			&loop,
			1) == -1)
		{
			perror("ping: can't disable multicast loopback");
			return (2);
		}
	}

	if (m_iOptions & F_TTL)
	{
		int ittl = m_iTtl;
		if (setsockopt(
				m_iIcmp_sock,
			IPPROTO_IP,
			IP_MULTICAST_TTL,
			&m_iTtl,
			1) == -1)
		{
			perror("ping: can't set multicast time-to-live");
			return (2);
		}

		if (setsockopt(
				m_iIcmp_sock,
			IPPROTO_IP,
			IP_TTL,
			&ittl,
			sizeof(ittl)) == -1)
		{
			perror("ping: can't set unicast time-to-live");
			return (2);
		}
	}

	if (m_iDatalen > 0xFFFF - 8 - m_iOptlen - 20)
	{
		if (m_iUid || m_iDatalen > sizeof(m_ucOutpack) - 8)
		{
			fprintf(
				stderr,
				"Error: packet size %d is too large. Maximum is %d\n",
				m_iDatalen,
				0xFFFF - 8 - 20 - m_iOptlen);
			return (2);
		}

		/* Allow small oversize to root yet. It will cause EMSGSIZE. */
		fprintf(
			stderr,
			"WARNING: packet size %d is too large. Maximum is %d\n",
			m_iDatalen,
			0xFFFF - 8 - 20 - m_iOptlen);
	}

	if (m_iDatalen >= sizeof(struct timeval))
	{	/* can we time transfer */
		m_iTiming = 1;
	}

	packlen = m_iDatalen + MAXIPLEN + MAXICMPLEN;
	if (!(packet = (u_char *)malloc((u_int) packlen)))
	{
		fprintf(stderr, "ping: out of memory.\n");
		return (2);
	}

	printf("PING %s (%s) ", m_pHostname, inet_ntoa(m_sWhereto.sin_addr));
	if (m_pDevice || (m_iOptions & F_STRICTSOURCE))
	{
		printf("from %s %s: ", inet_ntoa(m_sSource.sin_addr), m_pDevice ? : "");
	}

	printf(
		"%d(%d) bytes of data.\n",
		m_iDatalen,
		m_iDatalen + 8 + m_iOptlen + 20);

	if (setup(m_iIcmp_sock))
	{
		return (2);
	}

	main_loop(m_iIcmp_sock, packet, packlen);
#endif
	return 0;
}
