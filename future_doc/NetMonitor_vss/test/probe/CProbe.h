// CProbe.h: interface for the CProbe class .
//
//////////////////////////////////////////////////////////////////////

#if !defined(CPROBE_H)

#define CPROBE_H
#include "public.h"
#include "FtdData.h"
#include "systools.h"
#include "configmanager.h"

//key:������.����id.������,value:(key:ʱ���, value:����ֵ)
typedef map<string, map<string, string> > STORE_DATA_MAP;
typedef STORE_DATA_MAP::iterator STORE_DATA_ITERATOR;

#define   MIN(x,y)   ((x) > (y) ? (y) :(x))

#define OSSENDPACKAGETOOLD 	m_pkgSend.MakePackage(); \
	m_pFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

#define OSSENDPACKAGETO g_mManageConSession.sendFTDCPackage(&m_pkgSend);

#define SAFEADDOBJATTRFIELD				\
	if (m_pkgSend.Length() + sizeof(CFTDRtnObjectAttrField) > FTDC_PACKAGE_MAX_SIZE)       	\
	{                                                                                       \
	OSSENDPACKAGETO;                                                                    \
	m_pkgSend.PreparePackage(FTD_TID_RtnObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION); \
	}                                                                                       \
	FTDC_ADD_FIELD(&m_pkgSend, &m_cObjectAttr)


#ifdef WIN32
	#define _WIN32_WINNT 0x0501
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
	#include <pwd.h>                    //for Users info
	#include <grp.h>					//for Groups info
	#include <utmps.h>					//for Logged users info
#elif defined LINUX
	#include <pwd.h>                    //for Users info
	#include <grp.h>					//for Groups info
	#include <dirent.h>					//for read /proc/
	#include <sys/statfs.h>				//for fs info
	#include <utmp.h>					//for get logged user
	#include <sys/param.h>
	#include <sys/ioctl.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <net/if_arp.h>
	#include <net/if.h>
#else
#endif
#ifdef WIN32
	#define INT64 LONGLONG
	#define UINT64 ULONGLONG
#elif defined HP_UX
	#define INT64 int64_t
	#define UINT64 uint64_t
	// Host Env
	#define STOR_TOKENS		3					// �洢�豸��Ϣ�ֶ���
	#define IF_TOKENS		4					// I/O�ӿ���Ϣ�ֶ���
	#define FSL_TOKENS		4					// �ļ�ϵͳ��Ϣ�ֶ���
	#define SC_TOKENS		4					// ����������Ϣ�ֶ���
	#define HW_TIP_LEN		16					// 'HW_TIP'��ǩ���� + 1
	#define FS_TIP_LEN		19
	#define SC_TIP_LEN		19
	#define SYS_TIP_LEN		64
	#define HW_TIP			"System Hardware"
	#define FS_TIP			"File System layout"
	#define SC_TIP			"Swap configuration"
	#define SYSINFO_TIP		"    The following parameters were set on the configured target:"
	#define MODEL_TIP		"    Model:"		// �ո���ʡ
	#define MMEM_TIP		"    Main Memory:"
	#define PROC_TIP		"    Processors:"
	#define OSMOD_TIP		"    OS mode:"
	#define LANHW_TIP		"    LAN hardware ID:"
	#define KBL_TIP			"    Keyboard Language:"
	#define STORAGE_TIP		"    Storage devices"
	#define IOI_TIP			"    I/O Interfaces"
	#define HOST_TIP		"	hostname:"		// �ֶ��ײ�Ϊ���Ʊ����
	#define IP_TIP			"	IP address:"
	#define MASK_TIP		"	subnet mask:"
	#define LANNAME_TIP		"INTERFACE_NAME"
	#define LANIP_TIP		"IP_ADDRESS"
	#define LANMASK_TIP		"SUBNET_MASK"
#else
	#define INT64 long
	#define UINT64 unsigned long
	// Add for Linux
	#define CP_USER			0			/* user mode of USER process */
	#define CP_NICE			1			/* user mode of USER process at nice prio */
	#define CP_SYS			2			/* kernel mode of USER process */
	#define CP_IDLE			3			/* IDLE mode */
	#define CP_WAIT			4   		/* wait time */
	#define CP_BLOCK		5			/* OBSOLETE: time blocked on a spinlock */
	#define CP_SWAIT		6			/* OBSOLETE: time blocked on the kernel semaphore */
	#define CP_INTR			7			/* INTERRUPT mode */
	#define CP_SSYS			8			/* kernel mode of KERNEL process */
	#define MAX_CPUSTATES	9			/* the number of CPU time states */
	#define CPU_TIP				"cpu"
	#define BOOTTIME_TIP	"btime"
	#define MEM_TOTAL_TIP	"MemTotal:"
	#define MEM_FREE_TIP	"MemFree:"
	#define MEM_BUF_TIP		"Buffers:"
	#define MEM_CACHE_TIP	"Cached:"
	#define SWAP_TOTAL_TIP	"SwapTotal:"
	#define SWAP_FREE_TIP	"SwapFree:"
	#define UID_TIP				"Uid:"
	#define SIZE_TIP			"VmSize:"
	#define RES_TIP				"VmRSS:"
#endif

#ifndef MAX_PATH_LEN
	#define MAX_PATH_LEN	512
#endif
#define MAX_LINE_LEN	80
#define MAX_BUF_SIZE	4096
#define MAX_NAMELEN		20
#define MAX_CPUNUM		64					// ���CPU����
#define MAX_PROC_NUM	20					// ������������
#define MAX_LANHW_NUM	8					// ���������Ϣ��
#define MAX_STOR_NUM	10					// ���洢�豸��Ϣ��
#define MAX_IFS_NUM		30					// ���I/O�ӿ���Ϣ��
#define MAX_FSLRC_NUM	16					// ����ļ�ϵͳ��Ϣ��
#define MAX_SCRC_NUM	4					// ��󽻻�������Ϣ��
#define BLOCK_SIZE		256
#define BLOCK_SIZE_M	64
#define BLOCK_SIZE_S	16
#define SEP_CHAR		","
#define SEP_FLAG        0x2C				// ','
#define BLANK_FLAG		0x20				// ' '
#define COLON_FLAG		0x3A				// ':'
#define EQUAL_FLAG		0x3D				// '='
#define MEMORY_BASIC_UNIT	1024			// �ڴ浥λKB
#define DISK_BASIC_UNIT		(1024*1024)		// Ӳ�̵�λMB
#define LAN_TIP_UNIX	"lan"				// UNIX������Ϣ���ױ�ʶ
#define LAN_TIP_LINUX	"eth"				// LINUX������Ϣ���ױ�ʶ

// Added by Henchi 20081024 for Linux
#ifdef LINUX
	typedef struct __pst_processor {
		double		psp_avg_1_min;
		long		psp_cpu_time[MAX_CPUSTATES];
		unsigned long psp_idx;
	}pst_processor;

	typedef struct statstruct_proc {
		int           pid;                      /** The process id. **/
		char          cmdname[MAX_PATH_LEN];    /** The filename of the executable **/
		char          cmdline[MAX_BUF_SIZE];    /** The cmdline of the executable **/
		char          args[MAX_PATH_LEN];		/** the first argument of the start cmdline **/
		char          state;                    /** R is running, S is sleeping,    D is sleeping in an uninterruptible wait,   Z is zombie, T is traced or stopped **/
		unsigned int  uid;                      /** effective user id **/
		unsigned int  egid;                     /** effective group id **/
		int           ppid;                     /** The pid of the parent. **/
		int           pgrp;                     /** The pgrp of the process. **/
		int           session;                  /** The session id of the process. **/
		int           tty;                      /** The tty the process uses **/
		int           tpgid;                    /** (too long) **/
		unsigned int  flags;                    /** The flags of the process. **/
		unsigned int  minflt;                   /** The number of minor faults **/
		unsigned int  cminflt;                  /** The number of minor faults with childs **/
		unsigned int  majflt;                   /** The number of major faults **/
		unsigned int  cmajflt;                  /** The number of major faults with childs **/
		int           utime;                    /** user mode jiffies **/
		int           stime;                    /** kernel mode jiffies **/
		int	          cutime;                   /** user mode jiffies with childs **/
		int           cstime;                   /** kernel mode jiffies with childs **/
		int           counter;                  /** process's next timeslice **/
		int           priority;                 /** the standard nice value, plus fifteen **/
		unsigned int  timeout;                  /** The time in jiffies of the next timeout **/
		unsigned int  itrealvalue;              /** The time before the next SIGALRM is sent to the process **/
		unsigned int  starttime;                /** Time the process started after system boot **/
		unsigned int  currenttime;				/** Current timestamp **/
		unsigned int  vsize;                    /** Virtual memory size **/
		unsigned int  rss;                      /** Resident Set Size **/
		unsigned int  rlim;                     /** Current limit in bytes on the rss **/
		unsigned int  startcode;                /** The address above which program text can run **/
		unsigned int  endcode;                  /** The address below which program text can run **/
		unsigned int  startstack;               /** The address of the start of the stack **/
		unsigned int  kstkesp;                  /** The current value of ESP **/
		unsigned int  kstkeip;                  /** The current value of EIP **/
		int           signal;                   /** The bitmap of pending signals **/
		int           blocked;                  /** The bitmap of blocked signals **/
		int           sigignore;                /** The bitmap of ignored signals **/
		int           sigcatch;                 /** The bitmap of catched signals **/
		unsigned int  wchan;                    /** This is the "channel" in which the process is waiting. **/
		unsigned int  nswap;                    /** Number of pages swapped (not maintained) **/
		unsigned int  cnswap;                   /** Cumulative nswap for child processes (not maintained) **/
		int           exit_signal;              /** Signal to be sent to parent when we die **/
		int           processor;                /** CPU number last executed on. **/
		unsigned int  rt_priority;              /** Real-time scheduling priority **/
		unsigned int  policy;                   /** Scheduling policy **/
	}procinfo;

	typedef struct _procinfo_linux{
	public:
		int           pid;                      /** The process id. **/
		char          cmdname[MAX_PATH_LEN];    /** The filename of the executable **/
		char          args[MAX_PATH_LEN];		/** the first argument of the start cmdline **/
		char          state[2];    				/** R is running, S is sleeping,    D is sleeping in an uninterruptible wait,   Z is zombie, T is traced or stopped **/
		int           uid;                      /** user id **/
		int           ppid;                     /** The pid of the parent. **/
		int           tty;                      /** The tty the process uses **/
		int           utime;                    /** user mode jiffies **/
		int           stime;                    /** kernel mode jiffies **/
		int           counter;                  /** process's next timeslice **/
		int           priority;                 /** the standard nice value, plus fifteen **/
		unsigned int  starttime;                /** Time the process started after system boot **/
		unsigned int  vsize;                    /** Virtual memory size **/
		unsigned int  rss;                      /** Resident Set Size **/
		int           processor;                /** CPU number last executed on. **/
		long          currenttime;              /** Current timestamp **/
		float         cpuusage;					/** The CPU percentage **/

	public:
		void operator = (const statstruct_proc & ob)
		{
			memset(cmdname, 0x00, sizeof(cmdname));
			memset(args, 0x00, sizeof(args));
			strncpy(cmdname, ob.cmdname, MAX_PATH_LEN -1);
			strncpy(args, ob.args, MAX_PATH_LEN -1);
			state[0]	= ob.state		 ;
			state[1]	= 0x00			 ;
			pid         = ob.pid         ;
			uid         = ob.uid         ;
			ppid        = ob.ppid        ;
			tty         = ob.tty         ;
			utime       = ob.utime       ;
			stime       = ob.stime       ;
			counter     = ob.counter     ;
			priority    = ob.priority    ;
			starttime   = ob.starttime   ;
			vsize       = ob.vsize       ;
			rss         = ob.rss         ;
			processor   = ob.processor   ;
			currenttime = ob.currenttime ;
			cpuusage	= 0.0	 ;
		}
		bool operator < (const _procinfo_linux & rhs) const
		{
			return cpuusage < rhs.cpuusage;
		}
	}procinfo_linux;

	typedef struct _netinfo
	{
		string name;
		string state;
		string ip;
		string mask;
		string mac;
		unsigned long rcvpkgs;
		unsigned long sndpkgs;
		unsigned long rcvbytes;
		unsigned long sndbytes;
	}netinfo;

	typedef struct _proc_cpuusage
	{
	public:
		int pid;
		float cpuusage;

	public:
		void operator = (const _procinfo_linux & rhs)
		{
			pid = rhs.pid;
			cpuusage = rhs.cpuusage;
		}
		bool operator < (const _proc_cpuusage & rhs) const
		{
			return cpuusage < rhs.cpuusage;
		}
		bool operator == (const _proc_cpuusage & rhs) const
		{
			return pid == rhs.pid;
		}
	}proc_cpuusage;

#endif   		// end of "#ifdef LINUX"
// Added end


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
}sCpuInfo;

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
	_sProcInfo * Next;
}sProcInfo;


/// CProbe �ඨ���˻������׼�ص���Ϣ�ɼ��ֶ�
class CProbe : public CSelectReactor, public CEventHandler
{	
public:
	CProbe():CEventHandler(this) 
	{
		SetTimer(1, 1000);	
	}
	~CProbe() {}   

	void SetSysSeps(int process_sep, int cpu_sep, int network_sep)
	{
		m_iProcessSep = process_sep;
		m_iCPUSep = cpu_sep;
		m_iNetworkSep = network_sep;
	}
#ifdef LINUX
	///���ڴ����������CSV�ļ�
	void DumpCSV();   
	bool GetProcessInfo();
	bool GetNetwork();
	bool GetCPU();
	
private:
	bool IsNumber(char *pszData);
	bool IsDir(char *pszPath);
	bool ScanNetDev();
	void ScanProcesses();
	char *SeekChar(char *psSrc, int iChar);
	void SaveProcInfo(procinfo_linux & pinfo);
	bool IsSpcProc(char * szUcomm);
	void ScanStatus(char *pszFileName, procinfo &pinfo);
	void ScanProcStat(char *pszFileName, procinfo &pinfo);
	void ShowProcInfo(procinfo_linux & pinfo);
	void ScanCmd(char *pszFileName, procinfo &pinfo);
	bool GetNetCardInfo();
	void GetJavaProcInfo(procinfo &pinfo);
	int GetProcessor(pst_processor * processor);
	float GetLoadAvg_1M();
	void SetTimer(int nIDEvent, int nElapse);
	void ShowCPU();

	//����ϵͳCPU��Ϣ,����ÿ��CPU������CPU��ƽ��ֵ
	void SaveSysCPUInfo();
	//����ϵͳ������Ϣ
	void SaveSysNetWorkInfo();
	//�������CPU��Ϣ
	void SaveAppProcessInfo(procinfo_linux & pinfo);
	/** ��ʱ��������
	* @param	nIDEvent	�ö�ʱ����ID
	*/
	
	virtual void OnTimer(int nIDEvent);
	
	inline void GetDateTime()
	{
		time_t now;
		time(&now);
		strftime(m_mTime,10, "%H:%M:%S", localtime(&now));
		strftime(m_mDate,10, "%Y%m%d", localtime(&now));
	}
public:
	///����ID - ������Ϣ ӳ��ͼ
	map < string, netinfo> m_mapNetInfo;
	///�ϴβ�����������Ϣ
	map < string, netinfo> m_mapLastNetInfo;

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

	///��CPU����CPUʱ��
	INT64 m_mTotalTime[MAX_CPUNUM];

	///ϵͳCPU����,����GetCPU����ʱ�򷵻�ֵ�ĸ���Ϊ m_mCpuNum+1
	INT64 m_mCpuNum;

	///�����ϵͳҳ���С
	INT64 m_mPageSize;

	///������ϴζ�ȡ��CPU��Ϣ
	sCpuInfo m_sCPUs[MAX_CPUNUM];

	///CPU��Ϣ��FTD��
	CFTDRtnTopCpuInfoField m_cCpuInfo[MAX_CPUNUM];

	///���ڱ������������Ϣ�Ľṹ����
	pst_processor m_pProcessor[MAX_CPUNUM];

	///����PID - ������Ϣ ӳ��ͼ
	map < int, procinfo_linux > m_mapProcInfo;

	///���������CPU��������Ϣ���������Vector
	vector < proc_cpuusage > m_vctProcUsage;
#endif	// LINUX
	///ϵͳCPU�������
	int m_iCPUSep;

	///ϵͳNetwork�������
	int m_iNetworkSep;

	///���̲������
	int m_iProcessSep;
};

#endif //!defined(CPROBE_H)
