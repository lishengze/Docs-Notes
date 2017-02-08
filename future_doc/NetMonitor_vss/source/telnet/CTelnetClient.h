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
#define FMT_DATETIME	"%Y%m%d_%H%M%S" // �����ļ�����ʱ�����ڸ�ʽ����
#define TIP_USER		"Username:"		// Telnet��¼��ʾ��
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
#define FLAG_NEW_LINE	"\r\n"			// ���з�
#else
#define FLAG_NEW_LINE	"\n"			// ���з�
#endif
#define FILE_CLOSE(x) \
	if (x != NULL)	  \
	{				  \
		fclose(x);	  \
		x = NULL;	  \
	}

#define ASSERT_VALID_PSZ(x) assert(x != NULL)
#define CISCO_REACH			'!'			// CISCO ping �����ɹ���ʶ
#define CISCO_UNREACH		'U'			// CISCO ping �������ɴ��ʶ
#define CISCO_TIMEOUT		'.'			// CISCO ping ������ʱ��ʶ
#define CISCO_QUENCH		'C'			// CISCO ping ����ICMP���Ʊ�ʶ
#define CISCO_LOOP			'&'			// CISCO ping ����ICMP��ʱ(·��Բ��)��ʶ
#define CISCO_TIP_INFO		"Type escape sequence to abort."	// CISCO ping ָ������ǩ
#define CISCO_TIP_SEND		"Sending"			// CISCO ping ָ������ǩ
#define CISCO_TIP_SUCC		"Success rate is"	// CISCO ping ָ������ǩ
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
} DEV_MANUF;	//˳���ܱ�
using namespace std;

class CObjectIDName;
class CTelnetConnEntry;
class CTelnetDevice;
class CTelnetClient;

class CObjectIDName
{
	/* */
	public:
		/// ����һ������;
		string	m_sSystemName;

		/// �����������;
		string	m_sDatacenter;

		/// ������������;
		string	m_sObjectType;

		/// �����ļ�����;
		string	m_sObjectName;

		/// ��������ID��;
		string	m_sObjectIDName;

	/* */
	private:
		/// ����ID������;0Ϊδ��ʼ��;1Ϊ�ּ�������;2Ϊ����������
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
		/// Telnet �豸IP
		string	m_sIP;

		/// Telnet ͨѶ�˿�
		int m_nPort;

		/// ����ģʽ,��ѡtelnet��ssh
		ConnMode m_nMode;

		/// Telnet ��¼�û���
		string	m_sUser;

		/// Telnet ��¼����
		string	m_sPswd;

		/// Telnet ��������
		string	m_sCfgPswd;

		/// Telnet ִ�е�ָ������
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
		// �豸�����ļ���ص�Ŀ¼
		string	m_sPath;

		// �豸��Ӧ��������ʶ
		CObjectIDName m_ObjectID;

		// �豸������Ϣ��
		CTelnetConnEntry m_ConnEntry;

		// �豸����ʱ�������
		CJudgeRun m_JudgeRun;

	/* */
	public:
		// �豸��Ϣ��Ч�Ա�ʶ
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
		string	m_sHost;			// �������ӷ�������host��Ϣ,����ΪIP��������
		int m_iPort;				// Telnet�������˿�
		string	m_sUser;			// �����û���
		string	m_sPswd;			// ��������
		string	m_sCfgPswd;			// �޸�����ʹ�õĳ�������
		string	m_sFilePath;		// ����������ļ���Ŀ¼
		string	m_sFileName;		// ����������ļ���ȫ·��
		string	m_sTempName;		// ����������ļ�����ʱ·��
		string	m_sDevice;			// �豸����
		bool m_bLogoutFlag;			// �Ƿ�������ļ��ı�ʶ
		list<string> m_lCommands;	// ���������ָ������
		FILE *m_fOutput;			// ��������ļ����ļ�ָ��
		int m_iStep;				// ���浱ǰ��������
		int m_manfacid;				//�豸����ID 1:cisco,2:Blade,3:F5,4:Juniper,5:Huawei
		char m_szDateTime[SIZE_DATETIME];

		string	m_sBaseTips;		// ������������ʾ��
		string	m_sTips;			// ����Ա��������ʾ��
		string	m_sSend;			// �������һ�η��͵���Ϣ
		string	m_sRecv;			// �������һ�ν��յ���Ϣ(��ǰ����Ľ��)
		map<string, string> m_mapComm;				// ����ִ�е�ָ�Ӧ����Ϣ
		map<string, CCiscoPingResult> m_mapPing;	// ����Ping�豸�Ľ����Ϣ
		ConnMode m_nMode;				// ����ģʽ,��ѡtelnet��ssh
		int m_nInstanceID;				// ��¼��ǰʵ���ĳ�ʼ�����
		static int	s_nInstanceCount;	// ��¼����ʵ�����ܴ�������

	/* */
	public:
		static int	s_nInstances;	// ��¼��ǰռ�ô��ڵ��߳�����

	/* */
	public:
		CTelnetClient(void)
		{
			// �״�ʵ����ʱ
			if (s_nInstanceCount == -1)
			{
				s_nInstanceCount = 0;
			}

			if (s_nInstances == -1)
			{
				s_nInstances = 0;
			}

			m_nMode = telnet;	// Ĭ�ϲ���telnet��ʽ
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

		//telnet��ʼ����ֻ�ܵ���һ��
		static void TelnetGlobalInit(void)
		{
#ifndef WIN32
			//�Զ��̵߳�֧��
			ssh_threads_set_callbacks(ssh_threads_get_pthread());
#endif
			ssh_init();
		}

		//telnet��������ֻ�ܵ���һ��
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

		// ��ʼ��״̬���
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

		/// �õ��������ļ�ͬĿ¼�����һ�������ļ���ȫ·����
		bool GetLastFileName(string filepath, string &lastFileName);

		// ��ִ����
		int DoTask(void);
		void TTYLock(void);
		void TTYUnLock(void);
		void SetConnMode(ConnMode mode)
		{
			m_nMode = mode;
		}

	/* */
	protected:
		/// ��������ʱ,���ò���״̬
		void Reset(void);

		/// ��ȡ�����豸��������
		int GetConfig(void);

		/// �����ļ�·��
		void CreatePath(const char *path);

		/// �õ�·���е�Ŀ¼��
		string	GetDirName(string filename);

		/// �õ�·���е��ļ���
		string	GetFileName(string filepath);

		/// �õ��ļ������޺�׺��
		string	GetBaseName(string filename);

		/// �ж��ִ��Ƿ�ȫ���������
		bool IsNumber(char *pszData);

		/// ����ļ�
		void LogOut(char *pBuf, int iSize, const char *cmd = NULL);

		/// ����������,������ǰ���в���
		void Filter(char *pBuf, int iSize);

		/// �õ���ʽ����ʱ�䴮,�����ļ���
		char *GetDateTime(void);

		/// �޳�����е������ַ�
		void RemoveSpecialChar(string &data);

		/// �����յ���ping���
		void AnalyzePing(string msg);
		int RecvMsg(int &nSwitch, char *pBuf, int iLen);
		void SendMsg(void *pDest, char *pBuf, int iLen);
		void DoResponse(
				int &nSwitch,
				void *pDest,
				LIST_STR_ITER &listIt,
				LIST_STR_ITER &listEnd);

		/* ����ΪSSHЭ���ķ� */
		void channelwriteline(ssh_channel chan, char *pBuf, int iLen);
		int SSHGetConfig(void);
		void SSHSelectLoop(ssh_session session, ssh_channel channel);
		int Authenticate_kbdint(ssh_session session, const char *password);
};
#endif
