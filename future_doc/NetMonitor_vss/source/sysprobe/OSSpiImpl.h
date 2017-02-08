/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	OSSpiImpl.h
///@brief	定义了探针获取主机系统相关信息的类和函数
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
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
#define OSATTRACITVE		"Active"				// 主机活跃标识1
#define OSATTRALIVE			"Alive"					// 主机活跃标识2
#define OSATTRCPUUSAGE		"CpuUsage"			// 主机的CPU使用率
#define OSATTRMAXCPUUSAGE	"MaxCpuUsage"		// 主机的单核最大CPU使用率
#define OSATTRCPUBUSYCORE	"CpuBusyCore"		// 主机的最繁忙的CPUcoreID
#define OSATTRMEMORYUSAGE		"MemUsage"		// 主机的物理内存使用率（buffer/cache也算作占用）
#define OSATTRMEMORYFREEUSAGE	"MemFreeUsage"	// 主机的物理内存空闲率（buffer/cache也算作空闲）
#define OSATTRSWAPUSAGE		"SwapUsage"		// 主机的Swap使用率
#define OSATTRMAXDISKUSAGE	"MaxDiskUsage"	// 主机除/boot分区外最大分区使用率
#define OSATTRDISKBUSY		"DiskMaxBusy"	// 主机磁盘分区最大繁忙百分率
#define OSATTRDISKREADKBS	"DiskReadKBs"	// 主机磁盘每秒读取字节数
#define OSATTRDISKWRITEKBS	"DiskWriteKBs"	// 主机磁盘每秒写入字节数
#define OSATTRDISKIOMBS		"DiskIOMBs"		// 主机磁盘每秒读写兆字节数
#define OSATTRUPTIME		"Uptime"		// 主机启动时长（秒）
#define OSATTRUPTIMESTR		"UptimeStr"		// 主机启动时长字串描述
#define OSATTRPROCTOTAL		"ProcTotal"		// 系统总进程数
#define OSATTRPROCSLEEP		"ProcSleep"		// 系统休眠进程数
#define OSATTRPROCRUN		"ProcRun"		// 系统活跃进程数
#define OSATTRPROCBLOCK		"ProcBlock"		// 系统阻塞进程数
#define OSATTRPROCZOMBIE	"ProcZombie"	// 系统僵尸进程数
#define OSATTRDEVINTER		"DevInter"		// 每秒处理的设备中断数
#define OSATTRDEVCONTEXT	"DevContext"	// 每秒完成的上下文切换数
#define OSATTRFSAIOMAX		"FS_aio_max_nr"
#define OSATTRFSAIONR		"FS_aio_nr"
#define OSATTRFILEMAX		"FS_file_max"
#define OSATTRFILENR		"FS_file_nr"
#define OSATTRSHMALL		"shmall"
#define OSATTRSHMMAX		"shmmax"
#define OSATTRSHMMNI		"shmmni"

#define OSATTRNETRCVBYTESPEED	"RecvByteSpeed"			// 主机网卡每秒接收字节数
#define OSATTRNETRCVPKTSPEED	"RecvPktSpeed"			// 主机网卡每秒接收数据包数
#define OSATTRNETSNDBYTESPEED	"SendByteSpeed"			// 主机网卡每秒发送字节数
#define OSATTRNETSNDPKTSPEED	"SendPktSpeed"			// 主机网卡每秒发送数据包数
#define OSATTRNETRCVERROR		"RecvError"				// 主机网卡接收的错包数
#define OSATTRNETRCVDROP		"RecvDrop"				// 主机网卡接收的丢包数
#define OSATTRNETSNDERROR		"SendError"				// 主机网卡发送的错包数
#define OSATTRNETSNDDROP		"SendDrop"				// 主机网卡发送的丢包数
#define OSATTRNETPHYIFSPEED		"PhyIfSpeed"			// 主机所有物理网卡每秒发送和接收的字节
#define OSATTRTCPLISTEN			"TcpListen"				// TCP侦听端口数
#define OSATTRTCPALL			"TcpAll"				// TCP所有连接数
#define OSATTRTCPESTABLISHED	"TcpEstablished"		// TCP有效连接数
#define OSATTRTCPOTHER			"TcpOther"				// TCP无效连接数
#define OSATTRUDPESTABLISHED	"UdpEstablished"		// UDP有效连接数
#define OSATTRUDPCLOSE			"UdpClose"				// UDP关闭连接数

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
#define STOR_TOKENS 3					// 存储设备信息字段数
#define IF_TOKENS	4					// I/O接口信息字段数
#define FSL_TOKENS	4					// 文件系统信息字段数
#define SC_TOKENS	4					// 交换分区信息字段数
#define HW_TIP_LEN	16					// 'HW_TIP'标签长度 + 1
#define FS_TIP_LEN	19
#define SC_TIP_LEN	19
#define SYS_TIP_LEN 64
#define HW_TIP		"System Hardware"
#define FS_TIP		"File System layout"
#define SC_TIP		"Swap configuration"
#define SYSINFO_TIP \
		"    The following parameters were set on the configured target:"
#define MODEL_TIP	"    Model:"		// 空格不能省
#define MMEM_TIP	"    Main Memory:"
#define PROC_TIP	"    Processors:"
#define OSMOD_TIP	"    OS mode:"
#define LANHW_TIP	"    LAN hardware ID:"
#define KBL_TIP		"    Keyboard Language:"
#define STORAGE_TIP "    Storage devices"
#define IOI_TIP		"    I/O Interfaces"
#define HOST_TIP	"	hostname:"		// 字段首部为‘制表符’
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
/// 由于虚拟设备CPU数量较高，将上限放宽至256个
#define MAX_CPUNUM					256	// 最大CPU个数
#define MAX_PROC_NUM				20	// 最大进程链表长度
#define MAX_LANHW_NUM				8	// 最大网卡信息数
#define MAX_STOR_NUM				10	// 最大存储设备信息数
#define MAX_IFS_NUM					30	// 最大I/O接口信息数
#define MAX_FSLRC_NUM				16	// 最大文件系统信息数
#define MAX_SCRC_NUM				4	// 最大交换分区信息数
#define MAX_PARTITIONS				128 // 最大分区数
#define BLOCK_SIZE					256
#define BLOCK_SIZE_M				64
#define BLOCK_SIZE_S				16
#define SEP_CHAR					","
#define SEP_FLAG					0x2C			// ','
#define BLANK_FLAG					0x20			// ' '
#define COLON_FLAG					0x3A			// ':'
#define EQUAL_FLAG					0x3D			// '='
#define MEMORY_BASIC_UNIT			1024			// 内存单位KB
#define DISK_BASIC_UNIT				(1024 * 1024)	// 硬盘单位MB
#define LAN_TIP_UNIX				"lan"			// UNIX网络信息行首标识
#define LAN_TIP_LINUX				"eth"			// LINUX网络信息行首标识
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
///COperatorSystemSpiImpl定义了探针读取操作系统信息的类
///@author	周建军
///@version	1.0,20080510
/////////////////////////////////////////////////////////////////////////
class COperatorSystemSpiImpl
{
	/* */
	public:
		///构造函数
			///@param	pFlow	保存探针读取的操作系统信息的内存文件流指针
		COperatorSystemSpiImpl(CCachedFileFlow *pFlow);

		///析构函数
		~ COperatorSystemSpiImpl(void);

		///取当前主机初始信息函数
			///@return	true表示成功，false表示失败
		bool GetSpi(CFTDCSession *pSession);

		///读取系统环境变量函数
		void GetenvSpi(CFTDCSession *pSession = NULL);

		///读取系统状态信息函数
		void GetstatinfoSpi(void);

		///读取磁盘I/O信息函数
		void GetdiskioSpi(void);

		///读取路由信息函数
		void GetrouterSpi(void);

		///读取核心信息函数
		void GetkernelSpi(void);

		///读取CPU信息函数
		void GetcpuSpi(void);

		///读取内存信息函数
		void GetmemSpi(void);

		///读取进程信息函数
		void GetprocessSpi(void);

		///读取文件系统信息函数
		void GetfsSpi(void);

		///读取网络流量信息函数
		void GetnetworkSpi(void);

		///读取netstat信息函数
		void GetnetstatSpi(void);

		///读取用户信息函数
		void GetuserSpi(void);

		///读取主机活动状态函数
		void GetHostActiveSpi(void);

	/* */
	public:

		///获取当前的日期，时间 2008.08.04 add by Solomon Wu
		inline void GetDateTime(void)
		{
			time_t	now;
			time(&now);
			struct tm tm_time;
			LocalTime(&now, &tm_time);			
			strftime(m_mTime, 10, "%H:%M:%S", &tm_time);
			strftime(m_mDate, 10, "%Y%m%d", &tm_time);

			/// 统一更新指标时间信息
			m_cObjectAttr.MonDate = m_mDate;
			m_cObjectAttr.MonTime = m_mTime;
		}

#ifdef HP_UX
		///取当前主机环境信息函数
			///@return	true表示成功，false表示失败
		bool GetHostEnv(void);

		///取当前主机网卡配置信息函数
			///@return	true表示成功，false表示失败
		bool GetLanCfg(void);
#endif

		///取当前内存的使用信息函数
			///@return	true表示成功，false表示失败
		bool GetMemory(void);

		///取当前CPU的使用信息函数
			///@return	true表示成功，false表示失败
		bool GetCPU(void);

		///取当前主机分区信息函数
			///@return	true表示成功，false表示失败
		bool GetDisk(void);

		///取进程信息函数
			///@return	true表示成功，false表示失败
		bool GetProcessInfo(void);

		///取当前登陆用户信息函数
			///@return	true表示成功，false表示失败
		bool GetLoggedUsers(void);

		///取全部注册用户信息函数
			///@return	true表示成功，false表示失败
		bool GetAllUsers(void);

		///取网络流量信息函数 2008.08.14 add by Solomon Wu
			///@return	true表示成功，false表示失败
		bool NewGetNetwork(void);

		///打印当前主机环境信息
		void ShowHostEnv(void);

		///打印当前CPU的使用信息
		void ShowCPU(void);

		// Added by Henchi 20081126
		///发送主机应用变更信息包
		///@param	pszHost	指定主机名字符串指针，如：DA-002
		///@param	pszApp	指定应用标识字符串指针，如：tkernel.1
		///@return	返回分区的磁盘使用率
		void SendUpdateSyscfgPkg(const char *pszHost, const char *pszApp);

		///设置对象的对象标识名
		///@param	pszCenterName	指定系统标识字符串指针，如：TRADE.PuDian
		///@param	pszHost	指定主机名字符串指针，如：DA-002
		void SetObjectName(const char *pszCenterName, const char *pszHost);

	/* */
	private:
		///保存当天的日志
		char m_mDate[10];

		///保存的当前采集时间
		char m_mTime[10];

		///保存的采集对象ID
		char m_mObjectId[64];

		///保存的采集对象名字
		char m_mObjectName[64];

		///保存的应用类采集对象ID
		char m_mAppId[64];

		///保存的应用类采集对象名
		char m_mAppName[64];

		///FTD数据包发送缓冲区
		CFTDCPackage m_pkgSend;

		///保存的内存文件流地址
		CCachedFileFlow *m_pFlow;

		///主机manifest信息是否已采集
		bool m_bGetManifest;

		///主机网卡配置信息是否已采集
		bool m_bGetLanCfg;

		///主机环境变量信息,主机名
		char m_mHostName[MAX_NAMELEN];

		///主机的内存大小,单位是KB
		int m_mMemory;

		///主机网卡设备数
		int m_iLan;

		///主机存储设备数
		int m_iStorage;

		///主机I/O接口数
		int m_iIO;

		///主机系统分区数
		int m_iFS;

		///主机交换分区数
		int m_iSwap;

		///主机Lan配置信息数
		int m_iLanCfg;

		///主机TCP侦听端口数
		int m_iTcpListen;
		
		///主机TCP所有连接数
		int m_iTcpAll;
		///主机TCP有效连接数
		int m_iTcpEstablished;
		///主机TCP无效连接数
		int m_iTcpOther;
		///主机UDP连接数
		int m_iUdpEstablished;
		///主机UDP未连接数
		int m_iUdpClose;
		
		///主机网卡IP配置map
		map<string, string> m_LanIPMap;

		///主机公共信息的FTD域
		CFTDRspQryHostEnvCommonField m_cCommon;

		///主机LAN设备的FTD域
		CFTDRspQryHostEnvLanField m_cLan[MAX_LANHW_NUM];

		///主机存储设备的FTD域
		CFTDRspQryHostEnvStorageField m_cStorage[MAX_STOR_NUM];

		///主机I/O接口的FTD域
		CFTDRspQryHostEnvIOField m_cIO[MAX_IFS_NUM];

		///主机系统分区的FTD域
		CFTDRspQryHostEnvFSField m_cFS[MAX_FSLRC_NUM];

		///主机交换分区的FTD域
		CFTDRspQryHostEnvSwapField	m_cSwap[MAX_SCRC_NUM];

		///主机网络配置的FTD域
		CFTDRspQryHostEnvLanCfgField m_cLanCfg[MAX_LANHW_NUM];

		///对象属性信息的FTD域
		CFTDRtnObjectAttrField	m_cObjectAttr;

		///单CPU的总CPU时间
		INT64 m_mTotalTime[MAX_CPUNUM];

		///系统CPU个数,调用GetCPU方法时候返回值的个数为 m_mCpuNum+1
		INT64 m_mCpuNum;

		///保存的系统页面大小
		INT64 m_mPageSize;

		///保存的上次读取的CPU信息
		sCpuInfo m_sCPUs[MAX_CPUNUM];

		///CPU信息的FTD域
		CFTDRtnTopCpuInfoField	m_cCpuInfo[MAX_CPUNUM];

		///当前系统空闲内存(KB)
		UINT64	m_memFree;

		///当前系统全部虚拟内存(KB)
		UINT64	m_memAllVirtual;

		///当前系统活跃虚拟内存(KB)
		UINT64	m_memActVirtual;

		///当前系统全部(non-sys)物理内存(KB)
		UINT64	m_memAllReal;

		///当前系统活跃(non-sys)物理内存(KB)
		UINT64	m_memActReal;

		///内存信息的FTD域
		CFTDRtnTopMemInfoField	m_cMemInfo;

		///进程链表头指针
		sProcInfo *m_pListHead;

		///进程链表尾指针
		sProcInfo *m_pListTail;

		///进程链表长度
		int m_iListLen;

		///进程信息的FTD域
		CFTDRtnTopProcessInfoField	m_cProcInfo;

		///文件系统信息结构对象
		sFSInfo m_sFSInfo[MAX_FSLRC_NUM];

		///文件系统信息结构对象个数
		int m_mFSNum;

		///文件系统信息的FTD域
		CFTDRtnFileSystemInfoField	m_cFSInfo;

		///系统注册用户数
		int m_iUserNum;

		///系统注册用户组数
		int m_iGroupNum;

		///用户名-用户标识 映射图
		map<string, int> m_UnameUidMap;

		///用户组名-用户组标识 映射图
		map<string, int> m_GnameGidMap;

		///用户标识-用户信息 映射图
		map<int, sUserInfo> m_UserInfoMap;

		///用户组标识-用户组信息 映射图
		map<int, sGroupInfo> m_GroupInfoMap;

		///系统注册用户信息的FTD域
		CFTDRtnUserInfoField m_cUserInfo;

		///系统在线用户信息的FTD域
		CFTDRtnOnlineUserInfoField	m_cOnlineUser;

		///网络流量信息的FTD域
			///2008.08.05 改变量的信息每次都是重新创建的，不必要作为一个成员变量 chg by wu.yb

		// 保存上一次获取主机网卡数据时的时刻值
		time_t m_lastGetNetInfoTime;
		unsigned long long m_lastRecvByte;
		unsigned long long m_lastRecvPkt;
		unsigned long long m_lastSendByte;
		unsigned long long m_lastSendPkt;
		unsigned long long m_lastPhyPkt;

	//CFTDRtnNetworkInfoField m_cNetworkInfo;
	public:
		///采集对象指标的缓存队列
		TemplateMutexCatch<CFTDRtnObjectAttrField>	m_ObjectAttrList;

	/* */

	private:
		/* 更新主机的流量信息 */
		void UpdateHostNetFlowInfo();

#ifdef WIN32
	private:
		///获取进程列表信息
			///@return	true表示获取进程列表信息成功，false表示失败
		bool GetProcInfo(void);

		///获取进程名（去除文件后缀）
			///@param	exename	进程的可执行文件全名
			///@return	返回进程名
		string	GetProcName(string exename);

		///获取进程的内存使用率
			///@param	mem	进程占用的物理内存，单位KB
			///@return	进程内存使用率
		double	GetProcessMemoryUsage(ULONGLONG mem);

		///向终端输出指定进程信息
			///@param	pinfo	保存进程信息的结构对象引用
		void ShowProcInfo(CWinProcessInfo pinfo);

		///保存系统进程信息的映射 KEY：PID  VALUE：进程信息结构
		map<int, CWinProcessInfo> m_winprocMap;

		///保存系统进程CPU使用率信息的链表，用于排序求CPU使用率的TOP-N进程信息
		vector<CProcCPUUsage> m_winprocList;

		/// 获取服务器启动时间
		int GetUptime(void);
		
		///获取网卡接口状态信息
		///@return	true表示操作成功，false表示操作失败
		bool GetNetCardInfo(void);

		/// 获取系统路由信息
		int GetRoute(void);
		
	public:
		/// 获取主机的物理网卡信息（windows）
		/// 通过注册表和windows函数GetAdaptersInfo()获取
		/// static函数，应当仅调用一次
		bool InitNetInterfaceInfo_win(void);
	
	private:
		///网口ID - 网络信息 映射图
		map<string, netinfo> m_mapNetInfo;
#endif

		///由应用名判断进程是否为指定应用进程
			///@param	pszUcomm	指向进程应用名的字符串指针
			///@return	0表示该进程并非指定的应用进程，1表示该进程为指定的应用进程，2表示为指定进程且无启动标识（为0）
		int IsSpcProc(char *pszUcomm);

		///保存扫描到的业务进程列表
		list <string> m_lSpcProc;

#if defined HP_UX || defined LINUX

	//以下为HP_UX及LINUX共用段
	private:
		///判断指定文件路径是否为目录(DIR)
			///@param	pszPath	指向路径名的字符串指针
			///@return	true表示指向路径名为一目录，false指向路径名不是目录
		bool IsDir(char *pszPath);

		///判断指定字串是否全由数字构成(不包括"+-."等任何数学符号)
			///@param	pszData	指向目标字符串指针
			///@return	true表示该字串为数字串，false表示该字串不是数字串
		bool IsNumber(char *pszData);

		///获取指定文件分区的磁盘使用率
		///@param	pszPath	指定文件分区字符串指针
		///@return	返回分区的磁盘使用率
		float GetDiskUsage(char *pszPath);

		///获取指定文件分区的磁盘使用率
		///@param	pszPath	指定文件分区字符串指针
		///@param	fDiskUsage	指定文件分区磁盘使用率
		///@param	fInodeUsage	指定文件分区INode使用率
		///@return	true表示获取成功，false表示获取失败
		bool GetDiskUsage(char *pszPath, float & fDiskUsage, float & fInodeUsage);

		///从源字符串中找到目标字符,并返回目标字符后首个非空字符地址
			///@param	psSrc	源字符串指针
			///@param	iChar	目标字符的ASCII码值
			///@return	NULL表示未找到目标字符或目标字符后无合法数据,其它表示目标字符后首个非空字符地址
		char *SeekChar(char *psSrc, int iChar);

		///读取用户信息文件,并建立用户信息映射图
			///@return	true表示成功，false表示失败
		bool ReadPasswd(void);

		///读取用户组信息文件,并建立用户组信息映射图
			///@return	true表示成功，false表示失败
		bool ReadGroup(void);

		///由用户标识得到用户名
			///@param	nUid	用户标识
			///@return	返回用户ID所对应的用户名,若不存在则返回空字串
		string	GetUserName(int nUid);

		///由用户组标识得到用户组名
			///@param	nGid	用户组标识
			///@return	返回用户组ID所对应的组名,若不存在则返回空字串
		string	GetGroupName(int nGid);

		///由用户名得到用户标识
			///@param	strUserName	用户名
			///@return	返回用户组所对应的用户标识,若不存在则返回-1
		int GetUid(string strUserName);

		///由用户组名得到用户组标识
			///@param	strGroupName	用户组名
			///@return	返回用户组名所对应的组标识,若不存在则返回-1
		int GetGid(string strGroupName);

#ifdef HP_UX

	//以下为HP_UX专用段
	private:
		///初始化进程链表信息
			///@return	true表示成功，false表示失败
		bool InitProcList(void);

		///重构进程链表
			///@return	true表示成功，false表示失败
		bool NewProcList(void);

		///销毁进程链表
		void DropProcList(void);

		///读取进程链表信息并打包发送
		void FixProcInfo(void);

		///将单个进程信息结点加入进程链表
			///@param	pProcTmp	指向新进程信息节点的指针
			///@return	返回一个可用于接纳新进程信息的临时节点指针
		sProcInfo *AppendList(sProcInfo *pProcTmp);

		///由应用进程命令行获取关键参数
			///@param	pszCmd	指向进程执行命令行的字符串指针
			///@return	返回业务进程启动时所带的标识参数,无则返回0
		int GetProcArgValue(char *pszCmd);

		///获取指定应用进程的内存使用率
			///@param	pst	指向进程状态信息结构(pst_status)的指针
			///@return	返回应用进程的内存使用率
		float GetProcMemUsage(pst_status *pst);

		///读取主机环境配置文件(manifest)的信息
			///@param	psPath	主机环境配置文件名字符串指针
			///@param	psModel	主机型号标识字符串指针
			///@param	psMemory	主机主内存信息字符串指针
			///@param	piProcs	主机处理器个数
			///@param	psOSMode	主机操作系统类型字符串指针
			///@param	psLanHWs	主机网络设备信息数组指针
			///@param	piLanNum	主机网络设备信息数组元素数
			///@param	psStorage	主机存储设备信息数组指针
			///@param	piStorNum	主机存储设备信息数组元素数
			///@param	psIFs	主机I/O设备信息数组指针
			///@param	piIFNum	主机I/O设备信息数组元素数
			///@param	psFSLs	主机系统分区信息数组指针
			///@param	piFSLNum	主机系统分区信息数组元素数
			///@param	psSCs	主机交换分区信息数组指针
			///@param	piSCNum	主机交换分区信息数组元素数
			///@param	psHostName	主机网络名字符串指针
			///@param	psIP	主机网络IP字符串指针
			///@param	psMask	主机网络掩码字符串指针
			///@return	-2表示传入的参数指针不合法，-1表示无法打开配置文件，0表示读取成功
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

		///从源文件中提取规则存放的信息数据并存入字符串数组,每个串中以','分隔各个域
			///@param	psDst	结果数据字符串数组的指针
			///@param	piNum	结果数据字符串数组的元素数
			///@param	iMaxNum	结果数据字符串数组可存放的最大元素数
			///@param	iSepMinNum	当前后字串间连续出现至少iSepMinNum个空格时认为是不同的信息域
			///@param	iTokens	将每条数据记录划分的域数
			///@param	fpSrc	源文件指针
			///@return	-1表示传入的参数指针不合法，0表示提取数据并拆分成功
		int Segmentation(
				char *psDst,
				int *piNum,
				const int iMaxNum,
				const int iSepMinNum,
				const int iTokens,
				FILE *fpSrc);

		///从源字符串中截取信息字符串(结合SeekChar使用)
			///@param	psDst	输出信息字符串指针
			///@param	psSrc	源信息字符串指针
			///@return	-1表示传入的参数指针不合法，0表示提取数据成功
		int GetInfo(char *psDst, char *psSrc);

		///获取网络状态映射图
			///@param	lanstateMap	保存网络状态信息的MAP引用
			///@return	true表示操作成功，false表示操作失败
		bool GetLanStateMap(map<string, string> &lanstateMap);

		///将网络信息加入以标准备FTD域形式保存的链表中
			///@param	networkInfo	输出信息字符串指针
			///@return	-1表示传入的参数指针不合法，0表示提取数据成功
		bool GetNetStat(list<CFTDRtnNetworkInfoField *> &networkInfo);

	/* */
	private:
		///读取系统CPU信息结构组用到的指针
		pst_processor *m_pProcessor;

#elif defined LINUX

	//以下为LINUX专用段
	private:
		///循环调用以读取/proc/stat文件中处理器的时间片信息，存入信息结构数组中
			///@param	processor	用于保存处理器信息的结构数组首指针
			///@return	-1表示打开文件失败，否则返回处理器个数
		int GetProcessor(pst_processor *processor);

		///过滤JAVA进程的命令行，从而获取真实应用名及启动命令行
			///@param	pinfo	用于保存JAVA进程信息的结构对象
		void GetJavaProcInfo(procinfo &pinfo);

		///过滤Perl进程的命令行，从而获取真实应用名及启动命令行
			///@param	pinfo	用于保存Perl进程信息的结构对象
		void GetPerlProcInfo(procinfo &pinfo);

		///读取/proc/loadavg文件中每分钟系统的负载值
			///@return	0表示读取信息失败，否则返回负载值
		float GetLoadAvg_1M(void);

		///保存由/proc/PID/stat文件中获取的单个进程信息入相应容器，以计算CPU利用率
			///@param	pinfo	用于保存进程信息的结构对象引用
		void SaveProcInfo(procinfo_linux &pinfo);

		///通过读取/proc/PID/cmdline文件获取指定进程的命令行参数项，并存入相应进程信息结构对象
			///@param	pszFileName	用于保存/proc/PID/cmdline文件名的字串指针
			///@param	pinfo	用于保存进程信息的结构对象引用
		void ScanCmd(char *pszFileName, procinfo &pinfo);

		///通过读取/proc/meminfo文件获取系统内存信息，并存入成员变量
			///@return	true表示操作成功，false表示操作失败
		bool ScanMemInfo(void);

		///遍历/proc文件系统下各进程信息，并作进一步处理
		void ScanProcesses(void);

		///读取/proc/PID/stat文件，获取某时刻时该进程的相关信息，并存入相应结构对象
			///@param	pszFileName	用于保存/proc/PID/stat文件名的字串指针
			///@param	pinfo	用于保存进程信息的结构对象引用
		void ScanProcStat(char *pszFileName, procinfo &pinfo);

		///读取/proc/PID/status文件，获取某时刻时该进程的内存占用信息，并存入相应结构对象
			///@param	pszFileName	用于保存/proc/PID/status文件名的字串指针
			///@param	pinfo	用于保存进程信息的结构对象引用
		void ScanStatus(char *pszFileName, procinfo &pinfo);

		///向终端输出指定进程信息
			///@param	pinfo	保存进程信息的结构对象引用
		void ShowProcInfo(procinfo_linux &pinfo);

		///向终端输出系统在线用户信息
			///@param	utbufp	保存在线用户信息的结构指针
		void show_logged_info(struct utmp *utbufp);

		///获取网卡接口状态信息
			///@return	true表示操作成功，false表示操作失败
		bool GetNetCardInfo(void);

		///通过读取/proc/net/dev获取网卡数据流量信息
			///@return	true表示操作成功，false表示操作失败
		bool ScanNetDev(void);

		///通过读取/proc/swaps获取交换分区信息
			///@return	true表示操作成功，false表示操作失败
		bool ScanSwaps(void);

		/// Added by Henchi, 20121113
			/// 获取服务器启动时间
		int GetUptime(void);

		/// 获取处理器模式信息
		int GetCPUInfo(void);

		/// 将16进制示数的字串转化为IP码
		void HexStr2IP(char *pSrc, char *pDst, char *pDefault);

		/// 获取系统路由信息
		int GetRoute(void);

		/// 获取系统分区信息
		int GetPartitions(void);

		/// 获取处理器时间
		int GetCPUTime(void);

		/// 获取磁盘I/O状态信息
		int GetDiskStats(void);

		/// 获取文件首行信息
		char *GetFirstLine(const char *pFileName);

		/// 获取系统内核参数
		void GetSysCore(void);

		/// 保存原始磁盘IO数据
		void SaveOldStatus(void);

		/// 计算磁盘I/O数据
		void ComputeIORates(void);

		/// 获取磁盘I/O数据
		int GetDiskStatus(void);

		/// 获取系统stat信息
		void GetStatInfo(void);

		/// 获取系统netstat数据
		int GetNetStat(void);

		/// 获取系统TCP连接相关数据
		int GetTCPInfo(void);

		/// 获取系统UDP连接相关数据
		int GetUDPInfo(void);

		/// 解析一行UDP连接信息
		void UDPGetOne(int lnr, const char *line);
		
		/// 解析一行TCP连接信息
		void TCPGetOne(int lnr, const char *line);

		/// 获取系统stat数据
		void GetStat(stat_info *pStatInfo);

		/// 获取系统vmstat数据
		void GetVMStat(stat_info *pStatInfo);

		/// 获取指定进程名最后出现的PID
		long GetAppPid(string AppName);

	/* */
	private:
		///用于保存各处理器信息的结构数组
		pst_processor m_pProcessor[MAX_CPUNUM];

		///进程PID - 进程信息 映射图
		map<int, procinfo_linux> m_mapProcInfo;

		///网口ID - 网络信息 映射图
		map<string, netinfo> m_mapNetInfo;

		///保存各进程CPU利用率信息以作排序的Vector
		vector<proc_cpuusage> m_vctProcUsage;
		


		stat_info m_stat_info[2];
#endif // end of "#ifdef HP_UX" and "#elif defined LINUX" 专用
#endif // end of "#if defined HP_UX || defined LINUX"     共用
};
#endif //REF_OSSPIIMPL_H
