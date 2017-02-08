#ifndef CTELNETCLIENT_H
#define CTELNETCLIENT_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <list>
#include <iterator>

#define LIBSSH_STATIC
extern "C"
{
#ifdef WIN32
#include "libssh.h"
#else
#include "ssh_threads.h"
#endif
}

#include "CTelnet.h"
#include "systools.h"

#define SIZE_DATETIME	15 + 1
#define FMT_DATETIME	"%Y%m%d_%H%M%S" // 用作文件名的时间日期格式定义
#define TIP_USER		"Username:"		// Telnet登录提示符
#define TIP_PSWD		"Password:"
#define TIP_FAILED		"failed"

#define SPACECHAR		" "
#define MORESTR			"--- more --- "
#define EQUALCHAR       "="
#define SPECIAL_STR \
		"\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b"
#define SPECIAL_STR_1 \
		"--- more --- \b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b"

#ifdef WIN32
#define FLAG_NEW_LINE	"\r\n"			// 换行符
#else
#define FLAG_NEW_LINE	"\n"			// 换行符
#endif
#define FILE_CLOSE(x) \
	if (x != NULL)	  \
	{				  \
		fclose(x);	  \
		x = NULL;	  \
	}

#define ASSERT_VALID_PSZ(x) assert(x != NULL)
#define CISCO_REACH			'!'			// CISCO ping 单条成功标识
#define CISCO_UNREACH		'U'			// CISCO ping 单条不可达标识
#define CISCO_TIMEOUT		'.'			// CISCO ping 单条超时标识
#define CISCO_QUENCH		'C'			// CISCO ping 单条ICMP抑制标识
#define CISCO_LOOP			'&'			// CISCO ping 单条ICMP超时(路由圆环)标识
#define CISCO_TIP_INFO		"Type escape sequence to abort."	// CISCO ping 指令结果标签
#define CISCO_TIP_SEND		"Sending"			// CISCO ping 指令结果标签
#define CISCO_TIP_SUCC		"Success rate is"	// CISCO ping 指令结果标签
typedef list<string> LIST_STR;
typedef list<string>::iterator	LIST_STR_ITER;
typedef enum
{
	telnet	= 1,
	ssh		= 2
} ConnMode;
typedef enum
{
	Start		= 0,
	ReqUser,
	RspUser,
	ReqPswd,
	RspPswd,
	ReqCmd,
	RspCmd,
	ReqCfgPswd,
	RspCfgPswd,
	ReqCfgCmd,
	End,
	Error,
	ReqUser_error,
	RspUser_error,
	ReqPswd_error,
	RspPswd_error,
	ReqCmd_error,
	RspCmd_error,
	ReqCfgPswd_error,
	RspCfgPswd_error,
	ReqCfgCmd_error
} ConnStep;

typedef enum
{
	CISCO		= 1,
	BLADE,
	F5,
	JUNIPER,
	HUAWEI
} DEV_MANUF;	//顺序不能变
using namespace std;

class CObjectIDName;
class CTelnetConnEntry;
class CTelnetDevice;
class CTelnetClient;

class CObjectIDName
{
	/* */
	public:
		/// 对象一级域名;
		string	m_sSystemName;

		/// 对象二级域名;
		string	m_sDatacenter;

		/// 对象三级域名;
		string	m_sObjectType;

		/// 对象四级域名;
		string	m_sObjectName;

		/// 完整对象ID名;
		string	m_sObjectIDName;

	/* */
	private:
		/// 对象ID名类型;0为未初始化;1为分级加载型;2为完整加载型
		int m_iNameType;

	/* */
	public:
		CObjectIDName(void)
		{
			m_sSystemName = "";
			m_sDatacenter = "";
			m_sObjectType = "";
			m_sObjectName = "";
			m_sObjectIDName = "";
			m_iNameType = 0;
		}

		CObjectIDName(
		const char	*name1,
		const char	*name2,
		const char	*name3,
		const char	*name4)
		{
			m_sSystemName = name1;
			m_sDatacenter = name2;
			m_sObjectType = name3;
			m_sObjectName = name4;
			m_sObjectIDName = "";
			m_iNameType = 1;
		}

		CObjectIDName(const char *name)
		{
			m_sSystemName = "";
			m_sDatacenter = "";
			m_sObjectType = "";
			m_sObjectName = "";
			m_sObjectIDName = name;
			m_iNameType = 2;
		}

		CObjectIDName(const CObjectIDName &ob)
		{
			m_sSystemName = ob.m_sSystemName;
			m_sDatacenter = ob.m_sDatacenter;
			m_sObjectType = ob.m_sObjectType;
			m_sObjectName = ob.m_sObjectName;
			m_sObjectIDName = ob.m_sObjectIDName;
			m_iNameType = ob.m_iNameType;
		}

		CObjectIDName &operator=(const CObjectIDName &ob)
		{
			m_sSystemName = ob.m_sSystemName;
			m_sDatacenter = ob.m_sDatacenter;
			m_sObjectType = ob.m_sObjectType;
			m_sObjectName = ob.m_sObjectName;
			m_sObjectIDName = ob.m_sObjectIDName;
			m_iNameType = ob.m_iNameType;
			return *this;
		}
};

class CTelnetConnEntry
{
	/* */
	public:
		/// Telnet 设备IP
		string	m_sIP;

		/// Telnet 通讯端口
		int m_nPort;

		/// 连接模式,可选telnet或ssh
		ConnMode m_nMode;

		/// Telnet 登录用户名
		string	m_sUser;

		/// Telnet 登录密码
		string	m_sPswd;

		/// Telnet 配置密码
		string	m_sCfgPswd;

		/// Telnet 执行的指令序列
		list<string> m_lCommands;

	/* */
	public:
		CTelnetConnEntry(void)
		{
			m_sIP = "";
			m_nPort = 0;
			m_nMode = telnet;
			m_sUser = "";
			m_sPswd = "";
			m_sCfgPswd = "";
			m_lCommands.clear();
		}

		CTelnetConnEntry(
		const char	*IP,
		int Port,
		ConnMode Mode,
		const char	*User,
		const char	*Pswd,
		const char	*CfgPswd,
		list<string> &list)
		{
			ASSERT_VALID_PSZ(IP);
			ASSERT_VALID_PSZ(User);
			ASSERT_VALID_PSZ(Pswd);
			ASSERT_VALID_PSZ(CfgPswd);
			m_sIP = IP;
			m_nPort = Port;
			m_nMode = Mode;
			m_sUser = User;
			m_sPswd = Pswd;
			m_sCfgPswd = CfgPswd;
			m_lCommands.clear();
			copy(list.begin(), list.end(), back_inserter(m_lCommands));
		}

		CTelnetConnEntry(
		const char	*IP,
		int Port,
		ConnMode Mode,
		const char	*User,
		const char	*Pswd,
		const char	*CfgPswd,
		const char	*Cmd)
		{
			ASSERT_VALID_PSZ(IP);
			ASSERT_VALID_PSZ(User);
			ASSERT_VALID_PSZ(Pswd);
			ASSERT_VALID_PSZ(CfgPswd);
			m_sIP = IP;
			m_nPort = Port == 0 ? 23 : Port;
			m_nMode = Mode;
			m_sUser = User;
			m_sPswd = Pswd;
			m_sCfgPswd = CfgPswd;
			m_lCommands.clear();

			char szCmd[4096];
			strncpy(szCmd, Cmd, sizeof(szCmd) - 1);

			char *p = strtok(szCmd, ";");
			if (p != NULL)
			{
				m_lCommands.push_back(p);
				while ((p = strtok(NULL, ";")) != NULL)
				{
					m_lCommands.push_back(p);
				}
			}
		}

		CTelnetConnEntry(const CTelnetConnEntry &ob)
		{
			m_sUser = ob.m_sUser;
			m_sPswd = ob.m_sPswd;
			m_sCfgPswd = ob.m_sCfgPswd;
			m_sIP = ob.m_sIP;
			m_nPort = ob.m_nPort;
			m_nMode = ob.m_nMode;
			m_lCommands.clear();
			copy(
				ob.m_lCommands.begin(),
				ob.m_lCommands.end(),
				back_inserter(m_lCommands));
		}

		CTelnetConnEntry &operator=(const CTelnetConnEntry &ob)
		{
			m_sUser = ob.m_sUser;
			m_sPswd = ob.m_sPswd;
			m_sCfgPswd = ob.m_sCfgPswd;
			m_sIP = ob.m_sIP;
			m_nPort = ob.m_nPort;
			m_nMode = ob.m_nMode;
			m_lCommands.clear();
			copy(
				ob.m_lCommands.begin(),
				ob.m_lCommands.end(),
				back_inserter(m_lCommands));
			return *this;
		}

		bool AddCommand(char *command)
		{
			ASSERT_VALID_PSZ(command);
			m_lCommands.push_back(command);
			return m_lCommands.size() > 0 ? true : false;
		}
};

class CTelnetDevice
{
	/* */
	private:
		// 设备配置文件落地的目录
		string	m_sPath;

		// 设备对应的域名标识
		CObjectIDName m_ObjectID;

		// 设备连接信息体
		CTelnetConnEntry m_ConnEntry;

		// 设备采样时间控制器
		CJudgeRun m_JudgeRun;

	/* */
	public:
		// 设备信息有效性标识
		bool m_bValid;

	/* */
	public:
		CTelnetDevice(void)
		{
			m_sPath = "";
			m_bValid = false;
		}

		~CTelnetDevice(void)
		{
		}

		CTelnetDevice(
		const CObjectIDName &object,
		const CTelnetConnEntry	&entry,
		string	sPath,
		string	sSeps)
		{
			m_sPath = sPath;
			m_ObjectID = object;
			m_ConnEntry = entry;
			m_JudgeRun = CJudgeRun(sSeps.c_str());
			m_bValid = true;
		}

		CTelnetDevice(const CTelnetDevice &ob)
		{
			m_sPath = ob.m_sPath;
			m_ObjectID = ob.m_ObjectID;
			m_ConnEntry = ob.m_ConnEntry;
			m_JudgeRun = ob.m_JudgeRun;
			m_bValid = ob.m_bValid;
		}

		CTelnetDevice &operator=(const CTelnetDevice &ob)
		{
			m_sPath = ob.m_sPath;
			m_ObjectID = ob.m_ObjectID;
			m_ConnEntry = ob.m_ConnEntry;
			m_JudgeRun = ob.m_JudgeRun;
			m_bValid = ob.m_bValid;
			return *this;
		}

		void SetTelnetConnEntry(const CTelnetConnEntry &ob)
		{
			m_ConnEntry = ob;
		}

		CTelnetConnEntry &GetTelnetConnEntry(void)
		{
			return m_ConnEntry;
		}

		void SetObjectIDName(const CObjectIDName &ob)
		{
			m_ObjectID = ob;
		}

		CObjectIDName &GetObjectIDName(void)
		{
			return m_ObjectID;
		}

		void SetPath(const string &ob)
		{
			m_sPath = ob;
		}

		string &GetPath(void)
		{
			return m_sPath;
		}

		void SetJudgeRun(const CJudgeRun &ob)
		{
			m_JudgeRun = ob;
		}

		CJudgeRun &GetJudgeRun(void)
		{
			return m_JudgeRun;
		}

		bool ShouldRun(const int nNowSec)
		{
			return m_JudgeRun.needExcute(nNowSec);
		}
};

class CCiscoPingResult
{
	/* */
	protected:
		string	m_sAddress;
		int m_iPkgCount;
		int m_iPkgLength;
		int m_iFlag;
		int m_iTimeOut;
		int m_iFlagReach;
		int m_iFlagTimeOut;
		int m_iFlagUnreach;
		int m_iFlagQuench;
		int m_iFlagLoop;
		int m_iPercent;
		int m_iSuccCount;
		int m_iTotalCount;
		int m_iMin;
		int m_iAvg;
		int m_iMax;

	/* */
	public:
		CCiscoPingResult(void)
		{
			m_sAddress = "";
			m_iPkgCount = 0;
			m_iPkgLength = 0;
			m_iFlag = 0;
			m_iTimeOut = 0;
			m_iFlagReach = 0;
			m_iFlagTimeOut = 0;
			m_iFlagUnreach = 0;
			m_iFlagQuench = 0;
			m_iFlagLoop = 0;
			m_iPercent = 0;
			m_iSuccCount = 0;
			m_iTotalCount = 0;
			m_iMin = 0;
			m_iAvg = 0;
			m_iMax = 0;
		}

		~CCiscoPingResult(void)
		{
		}

		string GetAddress(void)
		{
			return m_sAddress;
		}

		int GetSuccCount(void)
		{
			return m_iSuccCount;
		}

		int GetMinDelay(void)
		{
			return m_iMin;
		}

		int GetMaxDelay(void)
		{
			return m_iMax;
		}

		int GetAvgDelay(void)
		{
			return m_iAvg;
		}

		bool LoadResult(string msg)
		{
			bool res = true;
			char *p = strtok((char *)msg.c_str(), "\r\n");
			if (strncmp(p, CISCO_TIP_INFO, strlen(CISCO_TIP_INFO)) == 0)
			{
				while ((p = strtok(NULL, "\r\n")) != NULL)
				{
					if (strncmp(p, CISCO_TIP_SEND, strlen(CISCO_TIP_SEND)) == 0)
					{
						char szTmp[64];

						//Sending 100, 4096-byte ICMP Echos to 172.16.94.21, timeout is 1 seconds:
						if (sscanf(
								p,
							"Sending %d, %d-byte ICMP Echos to %[0-9z-aA-Z.-_@], timeout is %d seconds:",
						&m_iPkgCount,
							&m_iPkgLength,
							szTmp,
							&m_iTimeOut) == 4)
						{
							res = res && true;
							m_sAddress = szTmp;
						}
						else
						{
							res = res && false;
						}
					}
					else if (strncmp(
								 p,
							 CISCO_TIP_SUCC,
							 strlen(CISCO_TIP_SUCC)) == 0)
					{
						// Success rate is 100 percent (100/100), round-trip min/avg/max = 1/4/9 ms
						if (sscanf(
								p,
							"Success rate is %d percent (%d/%d), round-trip min/avg/max = %d/%d/%d ms",
						&m_iPercent,
							&m_iSuccCount,
							&m_iTotalCount,
							&m_iMin,
							&m_iAvg,
							&m_iMax) == 6)
						{
							res = res && true;
						}

						// Success rate is 0 percent (0/100)
						else if (sscanf(
									 p,
								 "Success rate is %d percent (%d/%d)",
								 &m_iPercent,
								 &m_iSuccCount,
								 &m_iTotalCount) == 3)
						{
							res = res && true;
						}
						else
						{
							res = res && false;
						}
					}
					else if (*p == CISCO_REACH
						 ||	 *p == CISCO_UNREACH
						 ||	 *p == CISCO_TIMEOUT
						 ||	 *p == CISCO_QUENCH
						 ||	 *p == CISCO_LOOP)
					{
						for (int i = 0; i < strlen(p); i++)
						{
							if (*(p + i) == CISCO_REACH)
							{
								m_iFlagReach++;
							}
							else if (*(p + i) == CISCO_UNREACH)
							{
								m_iFlagUnreach++;
							}
							else if (*(p + i) == CISCO_TIMEOUT)
							{
								m_iFlagTimeOut++;
							}
							else if (*(p + i) == CISCO_QUENCH)
							{
								m_iFlagQuench++;
							}
							else if (*(p + i) == CISCO_LOOP)
							{
								m_iFlagLoop++;
							}
						}
					}
					else
					{
						//error
					}
				}

				return res && (m_iFlagReach == m_iSuccCount);
			}
			else
			{
				return false;
			}
		}
};

class CTelnetClient :
	public CTelnet
{
	/* */
	protected:
		string	m_sHost;			// 保存连接服务器的host信息,可能为IP或主机名
		int m_iPort;				// Telnet服务器端口
		string	m_sUser;			// 连接用户名
		string	m_sPswd;			// 连接密码
		string	m_sCfgPswd;			// 修改配置使用的超级密码
		string	m_sFilePath;		// 保存结果输出文件的目录
		string	m_sFileName;		// 保存结果输出文件的全路径
		string	m_sTempName;		// 保存结果输出文件的临时路径
		string	m_sDevice;			// 设备名称
		bool m_bLogoutFlag;			// 是否已输出文件的标识
		list<string> m_lCommands;	// 保存输出的指令序列
		FILE *m_fOutput;			// 保存输出文件的文件指针
		int m_iStep;				// 保存当前采样进度
		int m_manfacid;				//设备厂商ID 1:cisco,2:Blade,3:F5,4:Juniper,5:Huawei
		char m_szDateTime[SIZE_DATETIME];

		string	m_sBaseTips;		// 基本命令行提示符
		string	m_sTips;			// 管理员命令行提示符
		string	m_sSend;			// 保存最后一次发送的信息
		string	m_sRecv;			// 保存最后一次接收的信息(当前命令的结果)
		map<string, string> m_mapComm;				// 保存执行的指令及应答信息
		map<string, CCiscoPingResult> m_mapPing;	// 保存Ping设备的结果信息
		ConnMode m_nMode;				// 连接模式,可选telnet或ssh
		int m_nInstanceID;				// 记录当前实例的初始化序号
		static int	s_nInstanceCount;	// 记录本类实例的总创生个数

	/* */
	public:
		static int	s_nInstances;	// 记录当前占用串口的线程数量

	/* */
	public:
		CTelnetClient(void)
		{
			// 首次实例化时
			if (s_nInstanceCount == -1)
			{
				s_nInstanceCount = 0;
			}

			if (s_nInstances == -1)
			{
				s_nInstances = 0;
			}

			m_nMode = telnet;	// 默认采用telnet方式
			s_nInstanceCount++;
			m_nInstanceID = s_nInstanceCount;

			Init();
		}

		~CTelnetClient(void)
		{
			FILE_CLOSE(m_fOutput);

			if (s_nInstances == 0)
			{
				s_nInstances = -1;
			}
		}

		//telnet初始化，只能调用一次
		static void TelnetGlobalInit(void)
		{
#ifndef WIN32
			//对多线程的支持
			ssh_threads_set_callbacks(ssh_threads_get_pthread());
#endif
			ssh_init();
		}

		//telnet结束处理，只能调用一次
		static void TelnetGlobalFinish(void)
		{
			ssh_finalize();
		}

		string GetFileName(void)
		{
			return m_sFileName;
		}

		string GetDeviceName(void)
		{
			return m_sDevice;
		}

		int GetCommandNum(void)
		{
			return m_lCommands.size();
		}

		int GetStepNo(void)
		{
			return m_iStep;
		}

		void SetStepNo(int iStep)
		{
			m_iStep = iStep;
		}

		map<string, string> &getCommMap(void)
		{
			return m_mapComm;
		}

		map<string, CCiscoPingResult> &getPingCommMap(void)
		{
			return m_mapPing;
		}

		// 初始化状态相关
		void Init(void);
		void Init(const char *host, int port);
		void Init(
				const char	*host,
				int port,
				ConnMode Mode,
				const char	*user,
				const char	*pswd,
				const char	*cfgpswd);
		void Init(CTelnetConnEntry &conn, int manid = 0);
		void SetOutputPath(const char *path);
		bool AddCommand(char *command);

		/// 得到与配置文件同目录的最近一个配置文件的全路径名
		bool GetLastFileName(string filepath, string &lastFileName);

		// 主执行体
		int DoTask(void);
		void TTYLock(void);
		void TTYUnLock(void);
		void SetConnMode(ConnMode mode)
		{
			m_nMode = mode;
		}

	/* */
	protected:
		/// 连续采样时,重置采样状态
		void Reset(void);

		/// 获取网络设备运行配置
		int GetConfig(void);

		/// 创建文件路径
		void CreatePath(const char *path);

		/// 得到路径中的目录串
		string	GetDirName(string filename);

		/// 得到路径中的文件名
		string	GetFileName(string filepath);

		/// 得到文件名的无后缀名
		string	GetBaseName(string filename);

		/// 判断字串是否全由数字组成
		bool IsNumber(char *pszData);

		/// 输出文件
		void LogOut(char *pBuf, int iSize, const char *cmd = NULL);

		/// 过滤特征串,分析当前进行步骤
		void Filter(char *pBuf, int iSize);

		/// 得到格式化的时间串,用作文件名
		char *GetDateTime(void);

		/// 剔除结果中的特殊字符
		void RemoveSpecialChar(string &data);

		/// 分析收到的ping结果
		void AnalyzePing(string msg);
		int RecvMsg(int &nSwitch, char *pBuf, int iLen);
		void SendMsg(void *pDest, char *pBuf, int iLen);
		void DoResponse(
				int &nSwitch,
				void *pDest,
				LIST_STR_ITER &listIt,
				LIST_STR_ITER &listEnd);

		/* 以下为SSH协议文法 */
		void channelwriteline(ssh_channel chan, char *pBuf, int iLen);
		int SSHGetConfig(void);
		void SSHSelectLoop(ssh_session session, ssh_channel channel);
		int Authenticate_kbdint(ssh_session session, const char *password);
};
#endif
