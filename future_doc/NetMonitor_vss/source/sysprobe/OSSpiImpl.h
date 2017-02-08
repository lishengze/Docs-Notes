/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	OSSpiImpl.h
///@brief	������̽���ȡ����ϵͳ�����Ϣ����ͺ���
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
#ifndef REF_OSSPIIMPL_H
#define REF_OSSPIIMPL_H

#include "public.h"
#include "FtdData.h"
#include "CachedFileFlow.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "FileOCGuard.h"

#define MIN(x, y)			((x) > (y) ? (y) : (x))
#define OSATTRACITVE		"Active"				// ������Ծ��ʶ1
#define OSATTRALIVE			"Alive"					// ������Ծ��ʶ2
#define OSATTRCPUUSAGE		"CpuUsage"			// ������CPUʹ����
#define OSATTRMAXCPUUSAGE	"MaxCpuUsage"		// �����ĵ������CPUʹ����
#define OSATTRCPUBUSYCORE	"CpuBusyCore"		// �������æ��CPUcoreID
#define OSATTRMEMORYUSAGE		"MemUsage"		// �����������ڴ�ʹ���ʣ�buffer/cacheҲ����ռ�ã�
#define OSATTRMEMORYFREEUSAGE	"MemFreeUsage"	// �����������ڴ�����ʣ�buffer/cacheҲ�������У�
#define OSATTRSWAPUSAGE		"SwapUsage"		// ������Swapʹ����
#define OSATTRMAXDISKUSAGE	"MaxDiskUsage"	// ������/boot������������ʹ����
#define OSATTRDISKBUSY		"DiskMaxBusy"	// �������̷������æ�ٷ���
#define OSATTRDISKREADKBS	"DiskReadKBs"	// ��������ÿ���ȡ�ֽ���
#define OSATTRDISKWRITEKBS	"DiskWriteKBs"	// ��������ÿ��д���ֽ���
#define OSATTRDISKIOMBS		"DiskIOMBs"		// ��������ÿ���д���ֽ���
#define OSATTRUPTIME		"Uptime"		// ��������ʱ�����룩
#define OSATTRUPTIMESTR		"UptimeStr"		// ��������ʱ���ִ�����
#define OSATTRPROCTOTAL		"ProcTotal"		// ϵͳ�ܽ�����
#define OSATTRPROCSLEEP		"ProcSleep"		// ϵͳ���߽�����
#define OSATTRPROCRUN		"ProcRun"		// ϵͳ��Ծ������
#define OSATTRPROCBLOCK		"ProcBlock"		// ϵͳ����������
#define OSATTRPROCZOMBIE	"ProcZombie"	// ϵͳ��ʬ������
#define OSATTRDEVINTER		"DevInter"		// ÿ�봦����豸�ж���
#define OSATTRDEVCONTEXT	"DevContext"	// ÿ����ɵ��������л���
#define OSATTRFSAIOMAX		"FS_aio_max_nr"
#define OSATTRFSAIONR		"FS_aio_nr"
#define OSATTRFILEMAX		"FS_file_max"
#define OSATTRFILENR		"FS_file_nr"
#define OSATTRSHMALL		"shmall"
#define OSATTRSHMMAX		"shmmax"
#define OSATTRSHMMNI		"shmmni"

#define OSATTRNETRCVBYTESPEED	"RecvByteSpeed"			// ��������ÿ������ֽ���
#define OSATTRNETRCVPKTSPEED	"RecvPktSpeed"			// ��������ÿ��������ݰ���
#define OSATTRNETSNDBYTESPEED	"SendByteSpeed"			// ��������ÿ�뷢���ֽ���
#define OSATTRNETSNDPKTSPEED	"SendPktSpeed"			// ��������ÿ�뷢�����ݰ���
#define OSATTRNETRCVERROR		"RecvError"				// �����������յĴ����
#define OSATTRNETRCVDROP		"RecvDrop"				// �����������յĶ�����
#define OSATTRNETSNDERROR		"SendError"				// �����������͵Ĵ����
#define OSATTRNETSNDDROP		"SendDrop"				// �����������͵Ķ�����
#define OSATTRNETPHYIFSPEED		"PhyIfSpeed"			// ����������������ÿ�뷢�ͺͽ��յ��ֽ�
#define OSATTRTCPLISTEN			"TcpListen"				// TCP�����˿���
#define OSATTRTCPALL			"TcpAll"				// TCP����������
#define OSATTRTCPESTABLISHED	"TcpEstablished"		// TCP��Ч������
#define OSATTRTCPOTHER			"TcpOther"				// TCP��Ч������
#define OSATTRUDPESTABLISHED	"UdpEstablished"		// UDP��Ч������
#define OSATTRUDPCLOSE			"UdpClose"				// UDP�ر�������

#define OSSENDPACKAGETOOLD	m_pkgSend.MakePackage(); \
	m_pFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

#define OSSENDPACKAGETO		g_mManageConSession.sendFTDCPackage(&m_pkgSend);

#define SAFEADDOBJATTRFIELD if (m_pkgSend.Length() +									\
								sizeof(CFTDRtnObjectAttrField) > FTDC_PACKAGE_MAX_SIZE) \
	{																					\
		OSSENDPACKAGETO;																\
		m_pkgSend.PreparePackage(														\
				FTD_TID_RtnObjectAttrTopic,												\
				FTDC_CHAIN_LAST,														\
				FTD_VERSION);															\
	}																					\
																					 \
	FTDC_ADD_FIELD(&m_pkgSend, &m_cObjectAttr)
#ifdef WIN32
#define _WIN32_WINNT	0x0501
#include "psapi.h"
#include "winternl.h"
#include "Iphlpapi.h"
#include "Tlhelp32.h"
#include "PSApi.h"

#elif defined HP_UX
#include <sys/pstat.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/dk.h>
#include <pwd.h>						//for Users info
#include <grp.h>						//for Groups info
#include <utmps.h>						//for Logged users info
#elif defined LINUX
#include <pwd.h>						//for Users info
#include <grp.h>						//for Groups info
#include <dirent.h>						//for read /proc/
#include <sys/statfs.h>					//for fs info
#include <utmp.h>						//for get logged user
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <netdb.h>
#include <paths.h>
#include <pwd.h>
#include <getopt.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#else
#endif
#ifdef WIN32
#define INT64	LONGLONG
#define UINT64	ULONGLONG
#elif defined HP_UX
#define INT64	int64_t
#define UINT64	uint64_t

// Host Env
#define STOR_TOKENS 3					// �洢�豸��Ϣ�ֶ���
#define IF_TOKENS	4					// I/O�ӿ���Ϣ�ֶ���
#define FSL_TOKENS	4					// �ļ�ϵͳ��Ϣ�ֶ���
#define SC_TOKENS	4					// ����������Ϣ�ֶ���
#define HW_TIP_LEN	16					// 'HW_TIP'��ǩ���� + 1
#define FS_TIP_LEN	19
#define SC_TIP_LEN	19
#define SYS_TIP_LEN 64
#define HW_TIP		"System Hardware"
#define FS_TIP		"File System layout"
#define SC_TIP		"Swap configuration"
#define SYSINFO_TIP \
		"    The following parameters were set on the configured target:"
#define MODEL_TIP	"    Model:"		// �ո���ʡ
#define MMEM_TIP	"    Main Memory:"
#define PROC_TIP	"    Processors:"
#define OSMOD_TIP	"    OS mode:"
#define LANHW_TIP	"    LAN hardware ID:"
#define KBL_TIP		"    Keyboard Language:"
#define STORAGE_TIP "    Storage devices"
#define IOI_TIP		"    I/O Interfaces"
#define HOST_TIP	"	hostname:"		// �ֶ��ײ�Ϊ���Ʊ����
#define IP_TIP		"	IP address:"
#define MASK_TIP	"	subnet mask:"
#define LANNAME_TIP "INTERFACE_NAME"
#define LANIP_TIP	"IP_ADDRESS"
#define LANMASK_TIP "SUBNET_MASK"
#else
#define INT64	long
#define UINT64	unsigned long

// Add for Linux
#define CP_USER			0				/* user mode of USER process */
#define CP_NICE			1				/* user mode of USER process at nice prio */
#define CP_SYS			2				/* kernel mode of USER process */
#define CP_IDLE			3				/* IDLE mode */
#define CP_WAIT			4				/* wait time */
#define CP_BLOCK		5				/* OBSOLETE: time blocked on a spinlock */
#define CP_SWAIT		6				/* OBSOLETE: time blocked on the kernel semaphore */
#define CP_INTR			7				/* INTERRUPT mode */
#define CP_SSYS			8				/* kernel mode of KERNEL process */
#define MAX_CPUSTATES	9				/* the number of CPU time states */
#define CPU_TIP			"cpu"
#define BOOTTIME_TIP	"btime"
#define MEM_TOTAL_TIP	"MemTotal:"
#define MEM_FREE_TIP	"MemFree:"
#define MEM_BUF_TIP		"Buffers:"
#define MEM_CACHE_TIP	"Cached:"
#define SWAP_TOTAL_TIP	"SwapTotal:"
#define SWAP_FREE_TIP	"SwapFree:"
#define UID_TIP			"Uid:"
#define SIZE_TIP		"VmSize:"
#define RES_TIP			"VmRSS:"
#define TGID_TIP     "Tgid:"
#define THREADS_TIP   "Threads:"
#endif
#ifndef MAX_PATH_LEN
#define MAX_PATH_LEN	512
#endif
#define MAX_LINE_LEN				80
#define MAX_BUF_SIZE				4096
#define MAX_NAMELEN					20
/// Mod by Henchi, 20160301
/// ���������豸CPU�����ϸߣ������޷ſ���256��
#define MAX_CPUNUM					256	// ���CPU����
#define MAX_PROC_NUM				20	// ������������
#define MAX_LANHW_NUM				8	// ���������Ϣ��
#define MAX_STOR_NUM				10	// ���洢�豸��Ϣ��
#define MAX_IFS_NUM					30	// ���I/O�ӿ���Ϣ��
#define MAX_FSLRC_NUM				16	// ����ļ�ϵͳ��Ϣ��
#define MAX_SCRC_NUM				4	// ��󽻻�������Ϣ��
#define MAX_PARTITIONS				128 // ��������
#define BLOCK_SIZE					256
#define BLOCK_SIZE_M				64
#define BLOCK_SIZE_S				16
#define SEP_CHAR					","
#define SEP_FLAG					0x2C			// ','
#define BLANK_FLAG					0x20			// ' '
#define COLON_FLAG					0x3A			// ':'
#define EQUAL_FLAG					0x3D			// '='
#define MEMORY_BASIC_UNIT			1024			// �ڴ浥λKB
#define DISK_BASIC_UNIT				(1024 * 1024)	// Ӳ�̵�λMB
#define LAN_TIP_UNIX				"lan"			// UNIX������Ϣ���ױ�ʶ
#define LAN_TIP_LINUX				"eth"			// LINUX������Ϣ���ױ�ʶ
#define TIP_CPUINFO_PROCESSOR		"processor"
#define TIP_CPUINFO_VENDOR			"vendor_id"
#define TIP_CPUINFO_MODELNAME		"model name"
#define TIP_CPUINFO_CPUMHZ			"cpu MHz"
#define TIP_CPUINFO_CACHESIZE		"cache size"
#define TIP_CPUINFO_CPUCORES		"cpu cores"
#define TIP_STATINFO_CPUTOTAL		"cpu "
#define TIP_STATINFO_PAGE			"page "
#define TIP_STATINFO_SWAP			"swap "
#define TIP_STATINFO_INTR			"intr "
#define TIP_STATINFO_CONTEXT		"ctxt "
#define TIP_STATINFO_BOOTTIME		"btime "
#define TIP_STATINFO_PROCESSES		"processes "
#define TIP_STATINFO_PROCRUN		"procs_running "
#define TIP_STATINFO_PROCBLOCKED	"procs_blocked "
#define TIP_STATINFO_PAGEIN			"pgpgin "
#define TIP_STATINFO_PAGEOUT		"pgpgout "
#define TIP_STATINFO_SWAPIN			"pswpin "
#define TIP_STATINFO_SWAPOUT		"pswpout "

#define BUFFSIZE					(64 * 1024)

typedef unsigned long long	jiff;

typedef bool NetInterfaceType;
#define NetInterface_PHYSICAL true
#define NetInterface_VIRTUAL false

// Added by Henchi 20081024 for Linux
#ifdef LINUX
typedef struct _stat_info
{
	jiff cpu_user;					// - user: normal processes executing in user mode
	jiff cpu_nice;					// - nice: niced processes executing in user mode
	jiff cpu_system;				// - system: processes executing in kernel mode
	jiff cpu_idle;					// - idle: twiddling thumbs
	jiff cpu_iowait;				// - iowait: waiting for I/O to complete
	jiff cpu_irq;					// - irq: servicing interrupts
	jiff cpu_sirq;					// - softirq: servicing softirqs
	jiff cpu_steal;					// - steal: involuntary wait
	unsigned long page_in;			// page in
	unsigned long page_out;			// page out
	unsigned long swap_in;			// swap in
	unsigned long swap_out;			// swap out
	unsigned long intr;				// counts of interrupts serviced since boot time
	unsigned long ctxt;				// context swap count
	unsigned long processes;		// the number of processes and threads created	
	unsigned long proc_run;			// running processes
	unsigned long proc_blk;			// blocked processes
} stat_info;

typedef struct __pst_processor
{
	double	psp_avg_1_min;
	long psp_cpu_time[MAX_CPUSTATES];
	unsigned long psp_idx;
} pst_processor;

typedef struct statstruct_proc
{
	int pid;						/** The process id. **/
	char cmdname[MAX_PATH_LEN];		/** The filename of the executable **/
	char cmdline[MAX_BUF_SIZE];		/** The cmdline of the executable **/
	char args[MAX_PATH_LEN];		/** the first argument of the start cmdline **/
	char state;						/** R is running, S is sleeping,    D is sleeping in an uninterruptible wait,   Z is zombie, T is traced or stopped **/
	unsigned int uid;				/** effective user id **/
	unsigned int egid;				/** effective group id **/
	int ppid;						/** The pid of the parent. **/
	int pgrp;						/** The pgrp of the process. **/
	int session;					/** The session id of the process. **/
	int tty;						/** The tty the process uses **/
	int tpgid;						/** (too long) **/
	
	/// Added by Henchi, 20150421
	int tgid;							/** Taskgroup ID, Main Thread & childs are in the same taskgroup **/
	int threads;					/** Threads counts in the taskgroup **/
	
	unsigned int flags;				/** The flags of the process. **/
	unsigned int minflt;			/** The number of minor faults **/
	unsigned int cminflt;			/** The number of minor faults with childs **/
	unsigned int majflt;			/** The number of major faults **/
	unsigned int cmajflt;			/** The number of major faults with childs **/
	int utime;						/** user mode jiffies **/
	int stime;						/** kernel mode jiffies **/
	int cutime;						/** user mode jiffies with childs **/
	int cstime;						/** kernel mode jiffies with childs **/
	int counter;					/** process's next timeslice **/
	int priority;					/** the standard nice value, plus fifteen **/
	unsigned int timeout;			/** The time in jiffies of the next timeout **/
	unsigned int itrealvalue;		/** The time before the next SIGALRM is sent to the process **/
	unsigned int starttime;			/** Time the process started after system boot **/
	unsigned int currenttime;		/** Current timestamp **/
	unsigned int vsize;				/** Virtual memory size **/
	unsigned int rss;				/** Resident Set Size **/
	unsigned int rlim;				/** Current limit in bytes on the rss **/
	unsigned int startcode;			/** The address above which program text can run **/
	unsigned int endcode;			/** The address below which program text can run **/
	unsigned int startstack;		/** The address of the start of the stack **/
	unsigned int kstkesp;			/** The current value of ESP **/
	unsigned int kstkeip;			/** The current value of EIP **/
	int signal;						/** The bitmap of pending signals **/
	int blocked;					/** The bitmap of blocked signals **/
	int sigignore;					/** The bitmap of ignored signals **/
	int sigcatch;					/** The bitmap of catched signals **/
	unsigned int wchan;				/** This is the "channel" in which the process is waiting. **/
	unsigned int nswap;				/** Number of pages swapped (not maintained) **/
	unsigned int cnswap;			/** Cumulative nswap for child processes (not maintained) **/
	int exit_signal;				/** Signal to be sent to parent when we die **/
	int processor;					/** CPU number last executed on. **/
	unsigned int rt_priority;		/** Real-time scheduling priority **/
	unsigned int policy;			/** Scheduling policy **/
} procinfo;

typedef struct _procinfo_linux
{
public:
	int pid;						/** The process id. **/
	char cmdname[MAX_PATH_LEN];		/** The filename of the executable **/
	char args[MAX_PATH_LEN];		/** the first argument of the start cmdline **/
	char state[2];					/** R is running, S is sleeping,    D is sleeping in an uninterruptible wait,   Z is zombie, T is traced or stopped **/
	int uid;						/** user id **/
	int ppid;						/** The pid of the parent. **/
	int tty;						/** The tty the process uses **/
	int utime;						/** user mode jiffies **/
	int stime;						/** kernel mode jiffies **/
	int counter;					/** process's next timeslice **/
	int priority;					/** the standard nice value, plus fifteen **/
	unsigned int starttime;			/** Time the process started after system boot **/
	unsigned int vsize;				/** Virtual memory size **/
	unsigned int rss;				/** Resident Set Size **/
	int processor;					/** CPU number last executed on. **/
	int threads;					/** Threads counts in the taskgroup **/
	long currenttime;				/** Current timestamp **/
	float cpuusage;					/** The CPU percentage **/
public:
	void operator=(const statstruct_proc &ob)
	{
		memset(cmdname, 0x00, sizeof(cmdname));
		memset(args, 0x00, sizeof(args));
		strncpy(cmdname, ob.cmdname, MAX_PATH_LEN - 1);
		strncpy(args, ob.args, MAX_PATH_LEN - 1);
		state[0] = ob.state;
		state[1] = 0x00;
		pid = ob.pid;
		uid = ob.uid;
		ppid = ob.ppid;
		tty = ob.tty;
		utime = ob.utime;
		stime = ob.stime;
		counter = ob.counter;
		priority = ob.priority;
		starttime = ob.starttime;
		vsize = ob.vsize;
		rss = ob.rss;
		processor = ob.processor;
		threads = ob.threads;
		currenttime = ob.currenttime;
		cpuusage = 0.0;
	}

	bool operator < (const _procinfo_linux &rhs)const
	{
		return cpuusage < rhs.cpuusage;
	}
}
procinfo_linux;

typedef struct _netinfo
{
	string	name;
	string	state;
	string	ip;
	string	mask;
	string	mac;
	unsigned long long	rcvbytes;
	unsigned long long	rcvpkgs;
	unsigned long long	rcverrpkgs;
	unsigned long long	rcvdrppkgs;
	unsigned long long	sndbytes;
	unsigned long long	sndpkgs;
	unsigned long long	snderrpkgs;
	unsigned long long	snddrppkgs;
	NetInterfaceType	iftype;		// physical adapter OR virtual adapter
} netinfo;

typedef struct _proc_cpuusage
{
public:
	int pid;
	float cpuusage;
public:
	void operator=(const _procinfo_linux &rhs)
	{
		pid = rhs.pid;
		cpuusage = rhs.cpuusage;
	}

	bool operator < (const _proc_cpuusage &rhs)const
	{
		return cpuusage < rhs.cpuusage;
	}

	bool operator==(const _proc_cpuusage &rhs) const
	{
		return pid == rhs.pid;
	}
}
proc_cpuusage;

typedef struct _part_info
{
	unsigned int major;				/* Device major number */
	unsigned int minor;				/* Device minor number */
	unsigned long long	blocks;		/* Blocks total count  */
	char name[32];
} st_part_info;

typedef struct _blkio_info
{
	unsigned int rd_ios;			/* Read I/O operations */
	unsigned int rd_merges;			/* Reads merged */
	unsigned long long	rd_sectors; /* Sectors read */
	unsigned int rd_ticks;			/* Time in queue + service for read */
	unsigned int wr_ios;			/* Write I/O operations */
	unsigned int wr_merges;			/* Writes merged */
	unsigned long long	wr_sectors; /* Sectors written */
	unsigned int wr_ticks;			/* Time in queue + service for write */
	unsigned int ticks;				/* Time of requests in queue */
	unsigned int aveq;				/* Average queue length */
} st_blkio_info;

typedef struct _cpu_info
{
	unsigned long long	user;
	unsigned long long	system;
	unsigned long long	idle;
	unsigned long long	iowait;
} st_cpu_info;



#define INFO_GUTS1(file,proc)			\
	FILE * procinfo = fopen((file), "r");			\
if (procinfo != NULL) {\
do {	\
	if (fgets(buffer, sizeof(buffer), procinfo))	\
		(proc)(lnr++, buffer);				\
} while (!feof(procinfo));				\
fclose(procinfo);					\
}

#if HAVE_AFINET6
#define INFO_GUTS2(file,proc)				\
	lnr = 0;						\
	FILE * procinfo = fopen((file), "r");		       	\
if (procinfo != NULL) {\
do {	\
	if (fgets(buffer, sizeof(buffer), procinfo))	\
		(proc)(lnr++, buffer);				\
} while (!feof(procinfo));				\
fclose(procinfo);					\
}

#else
#define INFO_GUTS2(file,proc)

#endif

#define INFO_GUTS3					\
	return rc;

#define INFO_GUTS6(file,file6,proc)		\
	char buffer[8192];					\
	int rc = 0;						\
	int lnr = 0;						\
	INFO_GUTS1(file, proc)				\
	INFO_GUTS2(file6, proc)				\
	INFO_GUTS3

#define INFO_GUTS(file,proc)			\
	char buffer[8192];					\
	int rc = 0;						\
	int lnr = 0;						\
	INFO_GUTS1(file, proc)				\
	INFO_GUTS3

#define _PATH_PROCNET_TCP		"/proc/net/tcp"
#define _PATH_PROCNET_TCP6		"/proc/net/tcp6"
#define _PATH_PROCNET_UDP		"/proc/net/udp"
#define _PATH_PROCNET_UDP6		"/proc/net/udp6"


/* These enums are used by IPX too. :-( */
enum {
	NET_TCP_ESTABLISHED = 1,
	NET_TCP_SYN_SENT,
	NET_TCP_SYN_RECV,
	NET_TCP_FIN_WAIT1,
	NET_TCP_FIN_WAIT2,
	NET_TCP_TIME_WAIT,
	NET_TCP_CLOSE,
	NET_TCP_CLOSE_WAIT,
	NET_TCP_LAST_ACK,
	NET_TCP_LISTEN,
	NET_TCP_CLOSING			/* now a valid state */
};


static const char *tcp_state[] =
{
	"",
	"ESTABLISHED",
	"SYN_SENT",
	"SYN_RECV",
	"FIN_WAIT1",
	"FIN_WAIT2",
	"TIME_WAIT",
	"CLOSE",
	"CLOSE_WAIT",
	"LAST_ACK",
	"LISTEN",
	"CLOSING"
};
#endif // end of "#ifdef LINUX"

// Added end
// Added by Henchi, 20090730
#ifdef WIN32
class CWinProcessInfo
{
	/* */
	public:
		int pid;
		int ppid;
		string	procname;
		string	cmdline;
		string	username;
		string	status;
		ULONGLONG mem;
		ULONGLONG vmem;
		double	cpuusage;
		double	memusage;
};

class CProcCPUUsage
{
	/* */
	public:
		int pid;
		double	cpuusage;

	/* */
	public:
		void operator=(const CProcCPUUsage rhs)
		{
			pid = rhs.pid;
			cpuusage = rhs.cpuusage;
		}

		void operator=(const CWinProcessInfo rhs)
		{
			pid = rhs.pid;
			cpuusage = rhs.cpuusage;
		}

		bool operator < (const CProcCPUUsage rhs)const
		{
			return cpuusage < rhs.cpuusage;
		}

		bool operator==(const CProcCPUUsage rhs) const
		{
			return pid == rhs.pid;
		}
};

// Interface
typedef struct _netinfo
{
	string	name;
	string	state;
	string	ip;
	string	mask;
	string	mac;
	unsigned long long	rcvbytes;
	unsigned long long	rcvpkgs;
	unsigned long long	rcverrpkgs;
	unsigned long long	rcvdrppkgs;
	unsigned long long	sndbytes;
	unsigned long long	sndpkgs;
	unsigned long long	snderrpkgs;
	unsigned long long	snddrppkgs;
	NetInterfaceType	iftype;		// physical adapter OR virtual adapter
} netinfo;

#endif

// CPU
typedef struct __sCpuInfo
{
public:
	long User;
	long Nice;
	long Sys;
	long Idle;
	long Block;
	long Swait;
	long Inter;
	long Ssys;
} sCpuInfo;

//Processes
typedef struct _sProcInfo
{
	INT64 Cpu;
	INT64 TtyMajor;
	INT64 TtyMinor;
	INT64 Pid;
	INT64 Uid;
	INT64 Pri;
	INT64 Nice;
	INT64 Size;
	INT64 Res;
	INT64 State;
	INT64 Time;
	float pWCpu;
	float pCpu;
	char Cmd[64];
	char UCmd[16];
	_sProcInfo	*Next;
} sProcInfo;

//File System
typedef struct _sFSInfo
{
	char FileSystem[64];
	char MountOn[16];
	char FSType[16];
	INT64 Size;
	INT64 Avail;
	INT64 Used;
	float pUsed;
	INT64 ISize;
	INT64 IFree;
	INT64 IUsed;
	float pIUsed;
} sFSInfo;

//User
typedef struct _sUserInfo
{
public:
	char UserName[MAX_NAMELEN];
	char Password[MAX_NAMELEN];
	int Uid;
	int Gid;
	char HomeDir[MAX_NAMELEN];
	char UserShell[MAX_NAMELEN];
} sUserInfo;

//Group
typedef struct _sGroupInfo
{
public:
	char GroupName[MAX_NAMELEN];
	int Gid;
} sGroupInfo;


/////////////////////////////////////////////////////////////////////////
///COperatorSystemSpiImpl������̽���ȡ����ϵͳ��Ϣ����
///@author	�ܽ���
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class COperatorSystemSpiImpl
{
	/* */
	public:
		///���캯��
			///@param	pFlow	����̽���ȡ�Ĳ���ϵͳ��Ϣ���ڴ��ļ���ָ��
		COperatorSystemSpiImpl(CCachedFileFlow *pFlow);

		///��������
		~ COperatorSystemSpiImpl(void);

		///ȡ��ǰ������ʼ��Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetSpi(CFTDCSession *pSession);

		///��ȡϵͳ������������
		void GetenvSpi(CFTDCSession *pSession = NULL);

		///��ȡϵͳ״̬��Ϣ����
		void GetstatinfoSpi(void);

		///��ȡ����I/O��Ϣ����
		void GetdiskioSpi(void);

		///��ȡ·����Ϣ����
		void GetrouterSpi(void);

		///��ȡ������Ϣ����
		void GetkernelSpi(void);

		///��ȡCPU��Ϣ����
		void GetcpuSpi(void);

		///��ȡ�ڴ���Ϣ����
		void GetmemSpi(void);

		///��ȡ������Ϣ����
		void GetprocessSpi(void);

		///��ȡ�ļ�ϵͳ��Ϣ����
		void GetfsSpi(void);

		///��ȡ����������Ϣ����
		void GetnetworkSpi(void);

		///��ȡnetstat��Ϣ����
		void GetnetstatSpi(void);

		///��ȡ�û���Ϣ����
		void GetuserSpi(void);

		///��ȡ�����״̬����
		void GetHostActiveSpi(void);

	/* */
	public:

		///��ȡ��ǰ�����ڣ�ʱ�� 2008.08.04 add by Solomon Wu
		inline void GetDateTime(void)
		{
			time_t	now;
			time(&now);
			struct tm tm_time;
			LocalTime(&now, &tm_time);			
			strftime(m_mTime, 10, "%H:%M:%S", &tm_time);
			strftime(m_mDate, 10, "%Y%m%d", &tm_time);

			/// ͳһ����ָ��ʱ����Ϣ
			m_cObjectAttr.MonDate = m_mDate;
			m_cObjectAttr.MonTime = m_mTime;
		}

#ifdef HP_UX
		///ȡ��ǰ����������Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetHostEnv(void);

		///ȡ��ǰ��������������Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetLanCfg(void);
#endif

		///ȡ��ǰ�ڴ��ʹ����Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetMemory(void);

		///ȡ��ǰCPU��ʹ����Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetCPU(void);

		///ȡ��ǰ����������Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetDisk(void);

		///ȡ������Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetProcessInfo(void);

		///ȡ��ǰ��½�û���Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetLoggedUsers(void);

		///ȡȫ��ע���û���Ϣ����
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool GetAllUsers(void);

		///ȡ����������Ϣ���� 2008.08.14 add by Solomon Wu
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool NewGetNetwork(void);

		///��ӡ��ǰ����������Ϣ
		void ShowHostEnv(void);

		///��ӡ��ǰCPU��ʹ����Ϣ
		void ShowCPU(void);

		// Added by Henchi 20081126
		///��������Ӧ�ñ����Ϣ��
		///@param	pszHost	ָ���������ַ���ָ�룬�磺DA-002
		///@param	pszApp	ָ��Ӧ�ñ�ʶ�ַ���ָ�룬�磺tkernel.1
		///@return	���ط����Ĵ���ʹ����
		void SendUpdateSyscfgPkg(const char *pszHost, const char *pszApp);

		///���ö���Ķ����ʶ��
		///@param	pszCenterName	ָ��ϵͳ��ʶ�ַ���ָ�룬�磺TRADE.PuDian
		///@param	pszHost	ָ���������ַ���ָ�룬�磺DA-002
		void SetObjectName(const char *pszCenterName, const char *pszHost);

	/* */
	private:
		///���浱�����־
		char m_mDate[10];

		///����ĵ�ǰ�ɼ�ʱ��
		char m_mTime[10];

		///����Ĳɼ�����ID
		char m_mObjectId[64];

		///����Ĳɼ���������
		char m_mObjectName[64];

		///�����Ӧ����ɼ�����ID
		char m_mAppId[64];

		///�����Ӧ����ɼ�������
		char m_mAppName[64];

		///FTD���ݰ����ͻ�����
		CFTDCPackage m_pkgSend;

		///������ڴ��ļ�����ַ
		CCachedFileFlow *m_pFlow;

		///����manifest��Ϣ�Ƿ��Ѳɼ�
		bool m_bGetManifest;

		///��������������Ϣ�Ƿ��Ѳɼ�
		bool m_bGetLanCfg;

		///��������������Ϣ,������
		char m_mHostName[MAX_NAMELEN];

		///�������ڴ��С,��λ��KB
		int m_mMemory;

		///���������豸��
		int m_iLan;

		///�����洢�豸��
		int m_iStorage;

		///����I/O�ӿ���
		int m_iIO;

		///����ϵͳ������
		int m_iFS;

		///��������������
		int m_iSwap;

		///����Lan������Ϣ��
		int m_iLanCfg;

		///����TCP�����˿���
		int m_iTcpListen;
		
		///����TCP����������
		int m_iTcpAll;
		///����TCP��Ч������
		int m_iTcpEstablished;
		///����TCP��Ч������
		int m_iTcpOther;
		///����UDP������
		int m_iUdpEstablished;
		///����UDPδ������
		int m_iUdpClose;
		
		///��������IP����map
		map<string, string> m_LanIPMap;

		///����������Ϣ��FTD��
		CFTDRspQryHostEnvCommonField m_cCommon;

		///����LAN�豸��FTD��
		CFTDRspQryHostEnvLanField m_cLan[MAX_LANHW_NUM];

		///�����洢�豸��FTD��
		CFTDRspQryHostEnvStorageField m_cStorage[MAX_STOR_NUM];

		///����I/O�ӿڵ�FTD��
		CFTDRspQryHostEnvIOField m_cIO[MAX_IFS_NUM];

		///����ϵͳ������FTD��
		CFTDRspQryHostEnvFSField m_cFS[MAX_FSLRC_NUM];

		///��������������FTD��
		CFTDRspQryHostEnvSwapField	m_cSwap[MAX_SCRC_NUM];

		///�����������õ�FTD��
		CFTDRspQryHostEnvLanCfgField m_cLanCfg[MAX_LANHW_NUM];

		///����������Ϣ��FTD��
		CFTDRtnObjectAttrField	m_cObjectAttr;

		///��CPU����CPUʱ��
		INT64 m_mTotalTime[MAX_CPUNUM];

		///ϵͳCPU����,����GetCPU����ʱ�򷵻�ֵ�ĸ���Ϊ m_mCpuNum+1
		INT64 m_mCpuNum;

		///�����ϵͳҳ���С
		INT64 m_mPageSize;

		///������ϴζ�ȡ��CPU��Ϣ
		sCpuInfo m_sCPUs[MAX_CPUNUM];

		///CPU��Ϣ��FTD��
		CFTDRtnTopCpuInfoField	m_cCpuInfo[MAX_CPUNUM];

		///��ǰϵͳ�����ڴ�(KB)
		UINT64	m_memFree;

		///��ǰϵͳȫ�������ڴ�(KB)
		UINT64	m_memAllVirtual;

		///��ǰϵͳ��Ծ�����ڴ�(KB)
		UINT64	m_memActVirtual;

		///��ǰϵͳȫ��(non-sys)�����ڴ�(KB)
		UINT64	m_memAllReal;

		///��ǰϵͳ��Ծ(non-sys)�����ڴ�(KB)
		UINT64	m_memActReal;

		///�ڴ���Ϣ��FTD��
		CFTDRtnTopMemInfoField	m_cMemInfo;

		///��������ͷָ��
		sProcInfo *m_pListHead;

		///��������βָ��
		sProcInfo *m_pListTail;

		///����������
		int m_iListLen;

		///������Ϣ��FTD��
		CFTDRtnTopProcessInfoField	m_cProcInfo;

		///�ļ�ϵͳ��Ϣ�ṹ����
		sFSInfo m_sFSInfo[MAX_FSLRC_NUM];

		///�ļ�ϵͳ��Ϣ�ṹ�������
		int m_mFSNum;

		///�ļ�ϵͳ��Ϣ��FTD��
		CFTDRtnFileSystemInfoField	m_cFSInfo;

		///ϵͳע���û���
		int m_iUserNum;

		///ϵͳע���û�����
		int m_iGroupNum;

		///�û���-�û���ʶ ӳ��ͼ
		map<string, int> m_UnameUidMap;

		///�û�����-�û����ʶ ӳ��ͼ
		map<string, int> m_GnameGidMap;

		///�û���ʶ-�û���Ϣ ӳ��ͼ
		map<int, sUserInfo> m_UserInfoMap;

		///�û����ʶ-�û�����Ϣ ӳ��ͼ
		map<int, sGroupInfo> m_GroupInfoMap;

		///ϵͳע���û���Ϣ��FTD��
		CFTDRtnUserInfoField m_cUserInfo;

		///ϵͳ�����û���Ϣ��FTD��
		CFTDRtnOnlineUserInfoField	m_cOnlineUser;

		///����������Ϣ��FTD��
			///2008.08.05 �ı�������Ϣÿ�ζ������´����ģ�����Ҫ��Ϊһ����Ա���� chg by wu.yb

		// ������һ�λ�ȡ������������ʱ��ʱ��ֵ
		time_t m_lastGetNetInfoTime;
		unsigned long long m_lastRecvByte;
		unsigned long long m_lastRecvPkt;
		unsigned long long m_lastSendByte;
		unsigned long long m_lastSendPkt;
		unsigned long long m_lastPhyPkt;

	//CFTDRtnNetworkInfoField m_cNetworkInfo;
	public:
		///�ɼ�����ָ��Ļ������
		TemplateMutexCatch<CFTDRtnObjectAttrField>	m_ObjectAttrList;

	/* */

	private:
		/* ����������������Ϣ */
		void UpdateHostNetFlowInfo();

#ifdef WIN32
	private:
		///��ȡ�����б���Ϣ
			///@return	true��ʾ��ȡ�����б���Ϣ�ɹ���false��ʾʧ��
		bool GetProcInfo(void);

		///��ȡ��������ȥ���ļ���׺��
			///@param	exename	���̵Ŀ�ִ���ļ�ȫ��
			///@return	���ؽ�����
		string	GetProcName(string exename);

		///��ȡ���̵��ڴ�ʹ����
			///@param	mem	����ռ�õ������ڴ棬��λKB
			///@return	�����ڴ�ʹ����
		double	GetProcessMemoryUsage(ULONGLONG mem);

		///���ն����ָ��������Ϣ
			///@param	pinfo	���������Ϣ�Ľṹ��������
		void ShowProcInfo(CWinProcessInfo pinfo);

		///����ϵͳ������Ϣ��ӳ�� KEY��PID  VALUE��������Ϣ�ṹ
		map<int, CWinProcessInfo> m_winprocMap;

		///����ϵͳ����CPUʹ������Ϣ����������������CPUʹ���ʵ�TOP-N������Ϣ
		vector<CProcCPUUsage> m_winprocList;

		/// ��ȡ����������ʱ��
		int GetUptime(void);
		
		///��ȡ�����ӿ�״̬��Ϣ
		///@return	true��ʾ�����ɹ���false��ʾ����ʧ��
		bool GetNetCardInfo(void);

		/// ��ȡϵͳ·����Ϣ
		int GetRoute(void);
		
	public:
		/// ��ȡ����������������Ϣ��windows��
		/// ͨ��ע����windows����GetAdaptersInfo()��ȡ
		/// static������Ӧ��������һ��
		bool InitNetInterfaceInfo_win(void);
	
	private:
		///����ID - ������Ϣ ӳ��ͼ
		map<string, netinfo> m_mapNetInfo;
#endif

		///��Ӧ�����жϽ����Ƿ�Ϊָ��Ӧ�ý���
			///@param	pszUcomm	ָ�����Ӧ�������ַ���ָ��
			///@return	0��ʾ�ý��̲���ָ����Ӧ�ý��̣�1��ʾ�ý���Ϊָ����Ӧ�ý��̣�2��ʾΪָ����������������ʶ��Ϊ0��
		int IsSpcProc(char *pszUcomm);

		///����ɨ�赽��ҵ������б�
		list <string> m_lSpcProc;

#if defined HP_UX || defined LINUX

	//����ΪHP_UX��LINUX���ö�
	private:
		///�ж�ָ���ļ�·���Ƿ�ΪĿ¼(DIR)
			///@param	pszPath	ָ��·�������ַ���ָ��
			///@return	true��ʾָ��·����ΪһĿ¼��falseָ��·��������Ŀ¼
		bool IsDir(char *pszPath);

		///�ж�ָ���ִ��Ƿ�ȫ�����ֹ���(������"+-."���κ���ѧ����)
			///@param	pszData	ָ��Ŀ���ַ���ָ��
			///@return	true��ʾ���ִ�Ϊ���ִ���false��ʾ���ִ��������ִ�
		bool IsNumber(char *pszData);

		///��ȡָ���ļ������Ĵ���ʹ����
		///@param	pszPath	ָ���ļ������ַ���ָ��
		///@return	���ط����Ĵ���ʹ����
		float GetDiskUsage(char *pszPath);

		///��ȡָ���ļ������Ĵ���ʹ����
		///@param	pszPath	ָ���ļ������ַ���ָ��
		///@param	fDiskUsage	ָ���ļ���������ʹ����
		///@param	fInodeUsage	ָ���ļ�����INodeʹ����
		///@return	true��ʾ��ȡ�ɹ���false��ʾ��ȡʧ��
		bool GetDiskUsage(char *pszPath, float & fDiskUsage, float & fInodeUsage);

		///��Դ�ַ������ҵ�Ŀ���ַ�,������Ŀ���ַ����׸��ǿ��ַ���ַ
			///@param	psSrc	Դ�ַ���ָ��
			///@param	iChar	Ŀ���ַ���ASCII��ֵ
			///@return	NULL��ʾδ�ҵ�Ŀ���ַ���Ŀ���ַ����޺Ϸ�����,������ʾĿ���ַ����׸��ǿ��ַ���ַ
		char *SeekChar(char *psSrc, int iChar);

		///��ȡ�û���Ϣ�ļ�,�������û���Ϣӳ��ͼ
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool ReadPasswd(void);

		///��ȡ�û�����Ϣ�ļ�,�������û�����Ϣӳ��ͼ
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool ReadGroup(void);

		///���û���ʶ�õ��û���
			///@param	nUid	�û���ʶ
			///@return	�����û�ID����Ӧ���û���,���������򷵻ؿ��ִ�
		string	GetUserName(int nUid);

		///���û����ʶ�õ��û�����
			///@param	nGid	�û����ʶ
			///@return	�����û���ID����Ӧ������,���������򷵻ؿ��ִ�
		string	GetGroupName(int nGid);

		///���û����õ��û���ʶ
			///@param	strUserName	�û���
			///@return	�����û�������Ӧ���û���ʶ,���������򷵻�-1
		int GetUid(string strUserName);

		///���û������õ��û����ʶ
			///@param	strGroupName	�û�����
			///@return	�����û���������Ӧ�����ʶ,���������򷵻�-1
		int GetGid(string strGroupName);

#ifdef HP_UX

	//����ΪHP_UXר�ö�
	private:
		///��ʼ������������Ϣ
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool InitProcList(void);

		///�ع���������
			///@return	true��ʾ�ɹ���false��ʾʧ��
		bool NewProcList(void);

		///���ٽ�������
		void DropProcList(void);

		///��ȡ����������Ϣ���������
		void FixProcInfo(void);

		///������������Ϣ�������������
			///@param	pProcTmp	ָ���½�����Ϣ�ڵ��ָ��
			///@return	����һ�������ڽ����½�����Ϣ����ʱ�ڵ�ָ��
		sProcInfo *AppendList(sProcInfo *pProcTmp);

		///��Ӧ�ý��������л�ȡ�ؼ�����
			///@param	pszCmd	ָ�����ִ�������е��ַ���ָ��
			///@return	����ҵ���������ʱ�����ı�ʶ����,���򷵻�0
		int GetProcArgValue(char *pszCmd);

		///��ȡָ��Ӧ�ý��̵��ڴ�ʹ����
			///@param	pst	ָ�����״̬��Ϣ�ṹ(pst_status)��ָ��
			///@return	����Ӧ�ý��̵��ڴ�ʹ����
		float GetProcMemUsage(pst_status *pst);

		///��ȡ�������������ļ�(manifest)����Ϣ
			///@param	psPath	�������������ļ����ַ���ָ��
			///@param	psModel	�����ͺű�ʶ�ַ���ָ��
			///@param	psMemory	�������ڴ���Ϣ�ַ���ָ��
			///@param	piProcs	��������������
			///@param	psOSMode	��������ϵͳ�����ַ���ָ��
			///@param	psLanHWs	���������豸��Ϣ����ָ��
			///@param	piLanNum	���������豸��Ϣ����Ԫ����
			///@param	psStorage	�����洢�豸��Ϣ����ָ��
			///@param	piStorNum	�����洢�豸��Ϣ����Ԫ����
			///@param	psIFs	����I/O�豸��Ϣ����ָ��
			///@param	piIFNum	����I/O�豸��Ϣ����Ԫ����
			///@param	psFSLs	����ϵͳ������Ϣ����ָ��
			///@param	piFSLNum	����ϵͳ������Ϣ����Ԫ����
			///@param	psSCs	��������������Ϣ����ָ��
			///@param	piSCNum	��������������Ϣ����Ԫ����
			///@param	psHostName	�����������ַ���ָ��
			///@param	psIP	��������IP�ַ���ָ��
			///@param	psMask	�������������ַ���ָ��
			///@return	-2��ʾ����Ĳ���ָ�벻�Ϸ���-1��ʾ�޷��������ļ���0��ʾ��ȡ�ɹ�
		int ReadManifest(
				char *psPath,
				char *psModel,
				char *psMemory,
				int *piProcs,
				char *psOSMode,
				char *psLanHWs,
				int *piLanNum,
				char *psStorage,
				int *piStorNum,
				char *psIFs,
				int *piIFNum,
				char *psFSLs,
				int *piFSLNum,
				char *psSCs,
				int *piSCNum,
				char *psHostName,
				char *psIP,
				char *psMask);

		///��Դ�ļ�����ȡ�����ŵ���Ϣ���ݲ������ַ�������,ÿ��������','�ָ�������
			///@param	psDst	��������ַ��������ָ��
			///@param	piNum	��������ַ��������Ԫ����
			///@param	iMaxNum	��������ַ�������ɴ�ŵ����Ԫ����
			///@param	iSepMinNum	��ǰ���ִ���������������iSepMinNum���ո�ʱ��Ϊ�ǲ�ͬ����Ϣ��
			///@param	iTokens	��ÿ�����ݼ�¼���ֵ�����
			///@param	fpSrc	Դ�ļ�ָ��
			///@return	-1��ʾ����Ĳ���ָ�벻�Ϸ���0��ʾ��ȡ���ݲ���ֳɹ�
		int Segmentation(
				char *psDst,
				int *piNum,
				const int iMaxNum,
				const int iSepMinNum,
				const int iTokens,
				FILE *fpSrc);

		///��Դ�ַ����н�ȡ��Ϣ�ַ���(���SeekCharʹ��)
			///@param	psDst	�����Ϣ�ַ���ָ��
			///@param	psSrc	Դ��Ϣ�ַ���ָ��
			///@return	-1��ʾ����Ĳ���ָ�벻�Ϸ���0��ʾ��ȡ���ݳɹ�
		int GetInfo(char *psDst, char *psSrc);

		///��ȡ����״̬ӳ��ͼ
			///@param	lanstateMap	��������״̬��Ϣ��MAP����
			///@return	true��ʾ�����ɹ���false��ʾ����ʧ��
		bool GetLanStateMap(map<string, string> &lanstateMap);

		///��������Ϣ�����Ա�׼��FTD����ʽ�����������
			///@param	networkInfo	�����Ϣ�ַ���ָ��
			///@return	-1��ʾ����Ĳ���ָ�벻�Ϸ���0��ʾ��ȡ���ݳɹ�
		bool GetNetStat(list<CFTDRtnNetworkInfoField *> &networkInfo);

	/* */
	private:
		///��ȡϵͳCPU��Ϣ�ṹ���õ���ָ��
		pst_processor *m_pProcessor;

#elif defined LINUX

	//����ΪLINUXר�ö�
	private:
		///ѭ�������Զ�ȡ/proc/stat�ļ��д�������ʱ��Ƭ��Ϣ��������Ϣ�ṹ������
			///@param	processor	���ڱ��洦������Ϣ�Ľṹ������ָ��
			///@return	-1��ʾ���ļ�ʧ�ܣ����򷵻ش���������
		int GetProcessor(pst_processor *processor);

		///����JAVA���̵������У��Ӷ���ȡ��ʵӦ����������������
			///@param	pinfo	���ڱ���JAVA������Ϣ�Ľṹ����
		void GetJavaProcInfo(procinfo &pinfo);

		///����Perl���̵������У��Ӷ���ȡ��ʵӦ����������������
			///@param	pinfo	���ڱ���Perl������Ϣ�Ľṹ����
		void GetPerlProcInfo(procinfo &pinfo);

		///��ȡ/proc/loadavg�ļ���ÿ����ϵͳ�ĸ���ֵ
			///@return	0��ʾ��ȡ��Ϣʧ�ܣ����򷵻ظ���ֵ
		float GetLoadAvg_1M(void);

		///������/proc/PID/stat�ļ��л�ȡ�ĵ���������Ϣ����Ӧ�������Լ���CPU������
			///@param	pinfo	���ڱ��������Ϣ�Ľṹ��������
		void SaveProcInfo(procinfo_linux &pinfo);

		///ͨ����ȡ/proc/PID/cmdline�ļ���ȡָ�����̵������в������������Ӧ������Ϣ�ṹ����
			///@param	pszFileName	���ڱ���/proc/PID/cmdline�ļ������ִ�ָ��
			///@param	pinfo	���ڱ��������Ϣ�Ľṹ��������
		void ScanCmd(char *pszFileName, procinfo &pinfo);

		///ͨ����ȡ/proc/meminfo�ļ���ȡϵͳ�ڴ���Ϣ���������Ա����
			///@return	true��ʾ�����ɹ���false��ʾ����ʧ��
		bool ScanMemInfo(void);

		///����/proc�ļ�ϵͳ�¸�������Ϣ��������һ������
		void ScanProcesses(void);

		///��ȡ/proc/PID/stat�ļ�����ȡĳʱ��ʱ�ý��̵������Ϣ����������Ӧ�ṹ����
			///@param	pszFileName	���ڱ���/proc/PID/stat�ļ������ִ�ָ��
			///@param	pinfo	���ڱ��������Ϣ�Ľṹ��������
		void ScanProcStat(char *pszFileName, procinfo &pinfo);

		///��ȡ/proc/PID/status�ļ�����ȡĳʱ��ʱ�ý��̵��ڴ�ռ����Ϣ����������Ӧ�ṹ����
			///@param	pszFileName	���ڱ���/proc/PID/status�ļ������ִ�ָ��
			///@param	pinfo	���ڱ��������Ϣ�Ľṹ��������
		void ScanStatus(char *pszFileName, procinfo &pinfo);

		///���ն����ָ��������Ϣ
			///@param	pinfo	���������Ϣ�Ľṹ��������
		void ShowProcInfo(procinfo_linux &pinfo);

		///���ն����ϵͳ�����û���Ϣ
			///@param	utbufp	���������û���Ϣ�Ľṹָ��
		void show_logged_info(struct utmp *utbufp);

		///��ȡ�����ӿ�״̬��Ϣ
			///@return	true��ʾ�����ɹ���false��ʾ����ʧ��
		bool GetNetCardInfo(void);

		///ͨ����ȡ/proc/net/dev��ȡ��������������Ϣ
			///@return	true��ʾ�����ɹ���false��ʾ����ʧ��
		bool ScanNetDev(void);

		///ͨ����ȡ/proc/swaps��ȡ����������Ϣ
			///@return	true��ʾ�����ɹ���false��ʾ����ʧ��
		bool ScanSwaps(void);

		/// Added by Henchi, 20121113
			/// ��ȡ����������ʱ��
		int GetUptime(void);

		/// ��ȡ������ģʽ��Ϣ
		int GetCPUInfo(void);

		/// ��16����ʾ�����ִ�ת��ΪIP��
		void HexStr2IP(char *pSrc, char *pDst, char *pDefault);

		/// ��ȡϵͳ·����Ϣ
		int GetRoute(void);

		/// ��ȡϵͳ������Ϣ
		int GetPartitions(void);

		/// ��ȡ������ʱ��
		int GetCPUTime(void);

		/// ��ȡ����I/O״̬��Ϣ
		int GetDiskStats(void);

		/// ��ȡ�ļ�������Ϣ
		char *GetFirstLine(const char *pFileName);

		/// ��ȡϵͳ�ں˲���
		void GetSysCore(void);

		/// ����ԭʼ����IO����
		void SaveOldStatus(void);

		/// �������I/O����
		void ComputeIORates(void);

		/// ��ȡ����I/O����
		int GetDiskStatus(void);

		/// ��ȡϵͳstat��Ϣ
		void GetStatInfo(void);

		/// ��ȡϵͳnetstat����
		int GetNetStat(void);

		/// ��ȡϵͳTCP�����������
		int GetTCPInfo(void);

		/// ��ȡϵͳUDP�����������
		int GetUDPInfo(void);

		/// ����һ��UDP������Ϣ
		void UDPGetOne(int lnr, const char *line);
		
		/// ����һ��TCP������Ϣ
		void TCPGetOne(int lnr, const char *line);

		/// ��ȡϵͳstat����
		void GetStat(stat_info *pStatInfo);

		/// ��ȡϵͳvmstat����
		void GetVMStat(stat_info *pStatInfo);

		/// ��ȡָ�������������ֵ�PID
		long GetAppPid(string AppName);

	/* */
	private:
		///���ڱ������������Ϣ�Ľṹ����
		pst_processor m_pProcessor[MAX_CPUNUM];

		///����PID - ������Ϣ ӳ��ͼ
		map<int, procinfo_linux> m_mapProcInfo;

		///����ID - ������Ϣ ӳ��ͼ
		map<string, netinfo> m_mapNetInfo;

		///���������CPU��������Ϣ���������Vector
		vector<proc_cpuusage> m_vctProcUsage;
		


		stat_info m_stat_info[2];
#endif // end of "#ifdef HP_UX" and "#elif defined LINUX" ר��
#endif // end of "#if defined HP_UX || defined LINUX"     ����
};
#endif //REF_OSSPIIMPL_H
