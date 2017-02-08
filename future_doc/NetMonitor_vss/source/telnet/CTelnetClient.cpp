#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef LINUX
#include <sys/socket.h>
#include <dirent.h>
#endif
#include "CTelnetClient.h"


using namespace std;

map<string, list<string> > g_mapDeviceIfs; //<ip, ifs> //2013 06.17 by Lee
list<string> g_devlist;	//ssh ��½������pollingʧ�ܵ��豸list 2014.09.01
list<string> g_srxdevlit;//����srx�豸����֤��ʽҪ��SSH_AUTH_METHOD_INTERACTIVE,�����SSH_AUTH_METHOD_PASSWORD��ʽ��������в���ȡ�������

int CTelnetClient:: s_nInstanceCount = -1;	// ��¼����ʵ�����ܸ���
int CTelnetClient:: s_nInstances = -1;		// ��¼��ǰռ�ô��ڵ��߳�����
inline void CheckFileName(
	const char	*NewName,
	string	&lastFileName,
	string	&currFileName)
{
	if (strlen(NewName) == 19 && atoi(NewName) > 100000)
	{
		if (lastFileName.compare(NewName) < 0
		&&	currFileName.compare(NewName) > 0)
		{
			lastFileName = NewName;
		}
	}
}

inline void SleepMs(unsigned long nMilliseconds)
{
#ifdef WIN32
	Sleep(nMilliseconds);
#else
	usleep(nMilliseconds * 1000);
#endif
}

void CTelnetClient::TTYLock(void)
{
	s_nInstances++;
#ifdef TTY_LOCK
	if (s_nInstances == 1)
	{
		ttybackup();
	}

#endif
}

void CTelnetClient::TTYUnLock(void)
{
	s_nInstances--;
#ifdef TTY_LOCK
	if (s_nInstances == 0)
	{
		ttyresume();
	}

#endif
}

char *CTelnetClient::GetDateTime(void)
{
	memset(m_szDateTime, 0x00, sizeof(m_szDateTime));

	time_t	timep;
	struct tm curTime;
	time(&timep);
	LocalTime(&timep, &curTime);
	strftime(m_szDateTime, SIZE_DATETIME, FMT_DATETIME, &curTime);
	return m_szDateTime;
}

void CTelnetClient::Init(void)
{
	m_sHost = "";									// �������ӷ�������host��Ϣ,����ΪIP��������
	m_iPort = 0;									// Telnet�������˿�
	m_iStep = 0;									// ��ǰ��������
	m_sUser = "";									// �����û���
	m_sPswd = "";									// ��������
	m_sCfgPswd = "";								// �޸�����ʹ�õĳ�������
	m_sFilePath = "";								// ����������ļ��Ļ���·��
	m_sFileName = "";								// ����������ļ���ȫ·��
	m_sTempName = "";								// ����������ļ�����ʱȫ·��
	m_sDevice = "";									// �豸����
	m_bLogoutFlag = false;							// ��������ʶΪfalse
	m_fOutput = NULL;								// ����ļ����ļ�ָ��
	m_lCommands.clear();							// ���������ָ������
	m_manfacid = 0;

	m_sBaseTips = "";								// ������������ʾ��
	m_sTips = "";									// ����Ա��������ʾ��
	m_sSend = "";									// �������һ�η��͵���Ϣ
	m_sRecv = "";									// �������һ�ν��յ���Ϣ
	m_mapComm.clear();								// ����ͨѶ��������Ӧ����Ϣ
	m_mapPing.clear();
}

void CTelnetClient::Reset(void)
{
	m_iStep = 0;
	m_sDevice = "";
	m_sFileName = "";
	m_sTempName = "";
	m_sBaseTips = "";
	m_sTips = "";
	m_sSend = "";
	m_sRecv = "";
	m_bLogoutFlag = false;
	FILE_CLOSE(m_fOutput);
}

void CTelnetClient::Init(const char *host, int port)
{
	ASSERT_VALID_PSZ(host);
	m_sHost = host;
	m_iPort = port;
	Reset();
}

void CTelnetClient::Init(
	const char	*host,
	int port,
	ConnMode Mode,
	const char	*user,
	const char	*pswd,
	const char	*cfgpswd)
{
	ASSERT_VALID_PSZ(host);
	ASSERT_VALID_PSZ(user);
	ASSERT_VALID_PSZ(pswd);
	ASSERT_VALID_PSZ(cfgpswd);
	m_sHost = host;
	m_iPort = port;
	m_nMode = Mode;
	m_sUser = user;
	m_sPswd = pswd;
	m_sCfgPswd = cfgpswd;
	Reset();
}

void CTelnetClient::Init(CTelnetConnEntry &conn, int manuID)
{
	m_sHost = conn.m_sIP;
	m_iPort = conn.m_nPort;
	m_sUser = conn.m_sUser;
	m_sPswd = conn.m_sPswd;
	m_sCfgPswd = conn.m_sCfgPswd;
	m_manfacid = manuID;
	m_nMode = conn.m_nMode;
	m_lCommands.clear();
	copy(
		conn.m_lCommands.begin(),
		conn.m_lCommands.end(),
		back_inserter(m_lCommands));
	m_mapComm.clear();
	m_mapPing.clear();

	list<string>::iterator	it = m_lCommands.begin();
	for (; it != m_lCommands.end(); it++)
	{
		if ((*it) != "")
		{
			m_mapComm[(*it)] = "";
		}
	}

	Reset();
}

void CTelnetClient::SetOutputPath(const char *path)
{
	ASSERT_VALID_PSZ(path);

	int iLen = strlen(path);
	if (iLen > 0)
	{
		m_sFilePath = path;
#ifdef WIN32
		if (*(path + iLen - 1) != '\\')
		{
			m_sFilePath.append(1, '\\');
		}

#else
		if (*(path + iLen - 1) != '/')
		{
			m_sFilePath.append(1, '/');
		}

#endif
	}
	else
	{
#ifdef WIN32
		m_sFilePath = ".\\";
#else
		m_sFilePath = "./";
#endif
	}
}

string CTelnetClient::GetDirName(string filename)
{
#ifdef WIN32
	int index = max(filename.rfind("\\"), filename.rfind("/"));
#else
	int index = filename.rfind("/");
#endif
	string	dirname = "";
	if (index == string::npos)
	{
#ifdef WIN32
		dirname = ".\\";
#else
		dirname = "./";
#endif
	}
	else
	{
		dirname.assign(filename, 0, index + 1);
	}

	return dirname;
}

string CTelnetClient::GetFileName(string filepath)
{
#ifdef WIN32
	int index = max(filepath.rfind("\\"), filepath.rfind("/"));
#else
	int index = filepath.rfind("/");
#endif
	string	filename = "";
	if (index == string::npos)
	{
		filename = filepath;
	}
	else
	{
		filename.assign(filepath, index + 1, filepath.length() - index);
	}

	return filename;
}

string CTelnetClient::GetBaseName(string filename)
{
	int index = filename.rfind(".");
	string	basename = "";
	if (index == string::npos)
	{
		basename = filename;
	}
	else
	{
		basename.assign(filename, 0, index);
	}

	return basename;
}

bool CTelnetClient::IsNumber(char *pszData)
{
	if (!pszData || !strlen(pszData))
	{
		return false;
	}

	char *p = pszData;
	for (int i = 0; i < (int)strlen(pszData); i++)
	{
		if (!isdigit(*(p + i)))
		{
			return false;
		}
	}

	return true;
}

bool CTelnetClient::GetLastFileName(string filepath, string &lastFileName)
{
	string	dir = GetDirName(filepath);
	string	file = GetFileName(filepath);
	lastFileName = "";

#ifdef WIN32
	WIN32_FIND_DATA FindFileData;
	HANDLE	hFind = INVALID_HANDLE_VALUE;
	char DirSpec[MAX_PATH + 1];						// ָ��·��
	DWORD dwError;

	strncpy(DirSpec, dir.c_str(), strlen(dir.c_str()) + 1);
	strncat(DirSpec, "\*", 3);

	hFind = FindFirstFile(DirSpec, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u ", GetLastError());
		return false;
	}
	else
	{
		if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
		{
			CheckFileName(FindFileData.cFileName, lastFileName, file);
		}

		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
			{
				CheckFileName(FindFileData.cFileName, lastFileName, file);
			}
		}

		FindClose(hFind);
	}

#else
	DIR *pDir = opendir(dir.c_str());
	if (pDir == NULL)
	{
		printf("Failed to open dir %s\n", dir.c_str());
		return false;
	}

	struct dirent *pstDirent;
	while (pDir != NULL && (pstDirent = readdir(pDir)))
	{
		if ((strcmp(pstDirent->d_name, ".") == 0)
		||	(strcmp(pstDirent->d_name, "..") == 0))
		{
			continue;
		}

		CheckFileName(pstDirent->d_name, lastFileName, file);
	}

	if (pDir != NULL)
	{
		closedir(pDir);
	}

#endif
	if (lastFileName.length() > 0)
	{
		lastFileName = dir + lastFileName;
		return true;
	}
	else
	{
		return false;
	}
}

void CTelnetClient::CreatePath(const char *path)
{
	ASSERT_VALID_PSZ(path);

	char szPath[512];
	strncpy(szPath, path, sizeof(szPath));

	int iLen = strlen(szPath);

#ifdef WIN32
	for (int i = 0; i < iLen; i++)
	{
		if (szPath[i] == '\\')
		{
			szPath[i] = '\0';
			CreateDirectory(szPath, NULL);
			szPath[i] = '/';
		}
	}

	CreateDirectory(szPath, NULL);
#else
	for (int i = 0; i < iLen; i++)
	{
		if (szPath[i] == '/')
		{
			szPath[i] = '\0';

			//�жϴ�Ŀ¼�Ƿ����,�������򴴽�
			if (access(szPath, F_OK) != 0)
			{
				mkdir(szPath, 0750);
			}

			szPath[i] = '/';
		}
	}

	if (iLen > 0 && access(szPath, F_OK) != 0)
	{
		mkdir(szPath, 0750);
	}

#endif
}

void CTelnetClient::LogOut(char Buf[], int iSize, const char *cmd)
{
	char szPath[512];
	memset(szPath, 0, sizeof(szPath));

	if (m_fOutput == NULL)
	{
		if (m_sDevice.empty())
		{
			//if (m_manfacid == F5)
			//{
				sprintf(szPath, "%s%s", m_sFilePath.c_str(), m_sHost.c_str());
				CreatePath(szPath);
			//}
			//else
			//{
			//	return;
			//}
		}
		else
		{
			sprintf(
				szPath,
				"%s%s_%s",
				m_sFilePath.c_str(),
				m_sHost.c_str(),
				m_sDevice.c_str());
			CreatePath(szPath);
		}

		if (cmd == NULL)
		{
#ifdef WIN32
			sprintf(szPath, "%s\\%s.txt", szPath, GetDateTime());
#else
			sprintf(szPath, "%s/%s.txt", szPath, GetDateTime());
#endif
		}
		else if (strlen(cmd) > 0)
		{
			char *p = NULL;
			int length = 0;
			char cmdBuf[128];
			memset(cmdBuf, 0, 128);

			string cmdstr = string(cmd);
			if( (length = cmdstr.find('\"')) != string::npos )
			{
				length = min( length, 128 );
			}
			else
			{
				length = min((int)cmdstr.length(),128);
			}

			cmdstr = cmdstr.substr(0, length );
			sprintf(cmdBuf, "%s",cmdstr.c_str());

			while ((p = strchr(cmdBuf, '|')) != NULL)
			{
				*(p) = '_';
			}

			while ((p = strchr(cmdBuf, ' ')) != NULL)
			{
				*p = '_';
			}

#ifdef WIN32
			sprintf(szPath, "%s\\%s_%s.txt", szPath, cmdBuf, GetDateTime());
#else
			sprintf(szPath, "%s/%s_%s.txt", szPath, cmdBuf, GetDateTime());
#endif
		}
		else
		{
			return;
		}

		m_sFileName = szPath;
		sprintf(szPath, "%s.tmp%d", szPath, m_nInstanceID);
		m_sTempName = szPath;
		m_fOutput = fopen(szPath, "w");
		if (!m_fOutput)
		{
			printf(
				"open file %s fail in  CTelnetClient::LogOut, errno=%d, reason=%s\n",
				szPath,
				errno,
				strerror(errno));
			return;
		}
	}

	if (iSize == sizeof(Buf))
	{
		for (int nPos = 0; nPos < iSize; nPos++)
		{
			if (!m_fOutput)
			{
				printf(
					"fp NULL for file:%s 111 in CTelnetClient::LogOut\n",
					szPath);
				return;
			}

			fprintf(m_fOutput, "%c", Buf[nPos]);
		}
	}
	else
	{
		Buf[iSize] = 0x00;

		if (!m_fOutput)
		{
			printf(
				"fp NULL for file:%s 222 in CTelnetClient::LogOut\n",
				szPath);
			return;
		}

		fprintf(m_fOutput, "%s", Buf);
	}

	fflush(m_fOutput);
}

void CTelnetClient::Filter(char *pBuf, int iSize)
{
	ASSERT_VALID_PSZ(pBuf);

	char *p = NULL;

	if (GetStepNo() <= ReqCmd)
	{
		if (strstr(pBuf, TIP_USER) != NULL)
		{											// �յ��û�����ʾ��
			SetStepNo(ReqUser);
		}
		else if (strstr(pBuf, TIP_PSWD) != NULL)
		{											// �յ��û�������ʾ��
			SetStepNo(ReqPswd);
		}
		else if ((p = strchr(pBuf, '>')) != NULL)	// �յ�����������ʾ��
		{
			SetStepNo(ReqCmd);
			if (m_manfacid != CISCO)				//��cisco�豸
			{
				if (m_sDevice.empty())
				{
					char *q = strchr(pBuf, ':');
					if (q != NULL)
					{
						m_sDevice.append(q + 1, (p - 5) - (q + 1) + 1);
					}
					else if( strstr(pBuf,")->")!=NULL )
					{
						m_sDevice.append( pBuf,p-pBuf-4 );
					}
					else
					{
						m_sDevice.append( pBuf,p-pBuf );
					}
				}
			}
		}
	}
	else if (GetStepNo() == RspCmd)
	{
		if (strstr(pBuf, TIP_PSWD) != NULL)
		{	// �յ��û�������ʾ��
			SetStepNo(ReqCfgPswd);
		}
	}
	else if (GetStepNo() == RspCfgPswd)
	{
		if ((p = strchr(pBuf, '#')) != NULL)		// �յ��߼�������ʾ��
		{
			SetStepNo(ReqCfgCmd);
			if (m_sDevice.empty())
			{
				m_sDevice.append(pBuf + 2, p - pBuf - 2);
			}
		}
		else if ((p = strchr(pBuf, '%')) != NULL)	// �յ�enable��Կ�����ʶ
		{
			printf("enable password wrong,retry , receive buff=[%s].\n", pBuf);
			SetStepNo(ReqCmd);						// ����ָ���ǩ
		}
	}
}

bool CTelnetClient::AddCommand(char *command)
{
	ASSERT_VALID_PSZ(command);
	m_lCommands.push_back(command);
	m_mapComm[command] = "";
	return m_lCommands.size() > 0 ? true : false;
}

#define NEW_FLAG_NEW_LINE	"\r\n"
int CTelnetClient::RecvMsg(int &nSwitch, char *pBuf, int iLen)
{
	// ��Ҫ�ж���Ϣ����
	int iCase = -1;
	int length = 0;

	if ((iLen >= 10 && (strstr(pBuf, "Password: ") != NULL))
	||	(
			pBuf[iLen - 3] == 'd'
	&&	pBuf[iLen - 2] == ':'
	&&	pBuf[iLen - 1] == ' '
	))
	{
		iCase = 1;	//����������Ϣ
	}
	else if (pBuf[iLen - 1] == '>'
		 ||	 (pBuf[iLen - 2] == '>' && pBuf[iLen - 1] == ' '))	//juniper�豸����ֵ��ͷ��"Remote Management Console",��β��һ���ո����  pBuf[iLen - 2]=='>'
	{
		iCase = 2;
		char *p;
		if (strstr(pBuf, "Remote Management Console") != NULL) //������Remote Management Console��ͷ
		{
			length = strlen("Remote Management Console");
			pBuf += length;
			if( strstr(pBuf,NEW_FLAG_NEW_LINE)!= NULL ) //�����Իس����з���ͷ
			{
				pBuf += strlen(NEW_FLAG_NEW_LINE);
			}
		}
		else if( (p = strchr(pBuf,'@')) != NULL ) //���juniper_srx�ͺţ����ݸ�ʽ��"username@hostname> "
		{
                        if( m_sBaseTips.empty() )
                        {
                                length = p+1-pBuf;
                                pBuf=p+1;
                        }
                        else
                        {
                                string tmp=m_sUser+"@";
                                p = strstr(pBuf,tmp.c_str());
                                if ( NULL != p )
                                        (*p)='\0';
                        }
		}
	}
	else if (pBuf[iLen - 1] == '#') //
	{
		iCase = 3;
	}
	//�����ò���
	else if (strstr(pBuf, "save? [y]/n") != NULL)
	{
		iCase = 0;
	}

	if( iLen==1 )
	{
		printf(
			"command:[%s]device is %s,case = [%d] recv length = [%d] buff=[%s] at time = [%s].\n",
			m_sSend.c_str(),
			m_sHost.c_str(),
			iCase,
			iLen,pBuf,
			GetDateTime());
	}
	else
	{
		printf(
			"command:[%s]device is %s,case = [%d] recv length = [%d] at time = [%s].\n",
			m_sSend.c_str(),
			m_sHost.c_str(),
			iCase,
			iLen,
			GetDateTime());
	}

	if (iCase > 0)
	{
		nSwitch = 1;
		Filter(pBuf, iLen - length);

		string	dataStr = pBuf;
                if( (strncmp(m_sSend.c_str(), "show hardware profile buffer monitor brief",strlen("show hardware profile buffer monitor brief")) == 0)
                  ||(strncmp(m_sSend.c_str(), "show hw-module all fpd",strlen("show hw-module all fpd")) == 0)  )
                {
                    while (dataStr.find(EQUALCHAR) != string::npos)
                    {
                            dataStr = dataStr.replace(
                                            dataStr.find(EQUALCHAR),
                                            strlen(EQUALCHAR),
                                            "-");
                    }

                    if (strstr(dataStr.c_str(), EQUALCHAR) != NULL)
                    {
                            printf("the content still has the string of [=] .\n");
                    }
                }
		while (dataStr.find(SPECIAL_STR) != string::npos)
		{
			dataStr = dataStr.replace(
					dataStr.find(SPECIAL_STR),
					strlen(SPECIAL_STR),
					"");
		}

		if (strstr(dataStr.c_str(), SPECIAL_STR) != NULL)
		{
			printf("the content still has the string of more special 1.\n");
		}

		while (dataStr.find(MORESTR) != string::npos)
		{
			dataStr = dataStr.replace(
					dataStr.find(MORESTR),
					strlen(MORESTR),
					"");
		}

		if (strstr(dataStr.c_str(), MORESTR) != NULL)
		{
			printf("the content still has the string of more 1.\n");
		}

		////trimβ���ո����
		//dataStr = trim((char *)dataStr.c_str());

		// ƴ��ͬһ�������ִ�������
		//m_sRecv.append(pBuf, iLen-length);
		m_sRecv.append(dataStr.c_str(), dataStr.length());

		// ����ȥ��ǰ��ָ�
		while
		(
			m_sSend.length() > 0
		&&	m_sRecv.length() >= m_sSend.length()
		&&	m_sRecv.compare(0, m_sSend.length(), m_sSend) == 0
		)
		{
			m_sRecv = m_sRecv.substr(
					m_sSend.length(),
					m_sRecv.length() - m_sSend.length());
		}

		while
		(
			m_sRecv.length() >= strlen(NEW_FLAG_NEW_LINE)
		&&	m_sRecv.compare(
					0,
					strlen(NEW_FLAG_NEW_LINE),
					NEW_FLAG_NEW_LINE) == 0
		)
		{
			m_sRecv = m_sRecv.substr(
					strlen(NEW_FLAG_NEW_LINE),
					m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE));
		}

		if (iCase == 2 && m_sBaseTips == "")
		{
			m_sBaseTips = m_sRecv;
		}

		if (iCase == 3 && m_sTips == "")
		{
			m_sTips = m_sRecv;
		}

		// ����ȥ�������ʾ����
		while
		(
			m_sBaseTips.length() > 0
		&&	m_sRecv.length() >= m_sBaseTips.length()
		&&	m_sRecv.compare(
					m_sRecv.length() - m_sBaseTips.length(),
					m_sBaseTips.length(),
					m_sBaseTips) == 0
		)
		{
			SetStepNo(ReqCmd);
			m_sRecv = m_sRecv.substr(
					0,
					m_sRecv.length() - m_sBaseTips.length());

			// ȥ����˻��з�
			while
			(
				m_sRecv.length() >= strlen(NEW_FLAG_NEW_LINE)
			&&	m_sRecv.compare(
						m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE),
						strlen(NEW_FLAG_NEW_LINE),
						NEW_FLAG_NEW_LINE) == 0
			)
			{
				m_sRecv = m_sRecv.substr(
						0,
						m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE));
			}
		}

		while
		(
			m_sTips.length() > 0
		&&	m_sRecv.length() >= m_sTips.length()
		&&	m_sRecv.compare(
					m_sRecv.length() - m_sTips.length(),
					m_sTips.length(),
					m_sTips) == 0
		)
		{
			SetStepNo(ReqCfgCmd);
			m_sRecv = m_sRecv.substr(0, m_sRecv.length() - m_sTips.length());

			// ȥ����˻��з�
			while
			(
				m_sRecv.length() >= strlen(NEW_FLAG_NEW_LINE)
			&&	m_sRecv.compare(
						m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE),
						strlen(NEW_FLAG_NEW_LINE),
						NEW_FLAG_NEW_LINE) == 0
			)
			{
				m_sRecv = m_sRecv.substr(
						0,
						m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE));
			}
		}

		// printf("\n\nSend:%s Recv:%s\n\n", m_sSend.c_str(), m_sRecv.c_str());
		while (m_sRecv.find(m_sBaseTips.c_str()) != string::npos)
		{
			m_sRecv = m_sRecv.replace(
					m_sRecv.find(m_sBaseTips.c_str()),
					m_sBaseTips.length(),
					"");
		}

		//ȥ����˿���
		while
		(
			m_sRecv.length() >= strlen(NEW_FLAG_NEW_LINE)
		&&	m_sRecv.compare(
					m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE),
					strlen(NEW_FLAG_NEW_LINE),
					NEW_FLAG_NEW_LINE) == 0
		)
		{
			m_sRecv = m_sRecv.substr(
					0,
					m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE));
		}

		//������������ɼ��Ľ������ 
		//�޳��˿ڶ���Ѳ������ָ���豸�Ĳ���ָ���˿� 2013 06.17 by Lee 
		if( m_sSend.compare("show interfaces summary") == 0 )
		{
			if( g_mapDeviceIfs.find(m_sHost) != g_mapDeviceIfs.end() )
			{
				for(list<string>::iterator it_ifs = g_mapDeviceIfs[m_sHost].begin(); 
					it_ifs != g_mapDeviceIfs[m_sHost].end(); it_ifs++)
				{
					char *p_begin = (char *) (m_sRecv.c_str()); //��ʶ�ס�β�ַ���ַ
					char *p_end = p_begin + m_sRecv.length() - 1;

					char *p = (char *) strstr(m_sRecv.c_str(), it_ifs->c_str());
					if( p == NULL )
					{
						continue;
					}
					char *p_left, *p_right;
					p_left = p_right = p;

					//��λǰһ���س�����
					while( p_left != p_begin )
					{
						if( *p_left == '\n' && *(p_left - 1) == '\r' )
						{
							break;
						}
						p_left--;
					}
					//��λ��һ���س�����
					while( p_right != p_end )
					{
						if( *p_right == '\r' && *(p_right + 1) == '\n' )
						{
							break;
						}
						p_right++;
					}
					
					if( p_left == p_begin && p_right == p_end )
					{
						//just one line  "remove the line with 123 in the string" 
						m_sRecv = m_sRecv.replace( p_left-p_begin, (p_right) - (p_left) + 1, "" );
					}
					else if( p_left == p_begin && p_right != p_end )
					{
						//head  "remove the line with 123 in the string\r\nxyz"
						m_sRecv = m_sRecv.replace( p_left-p_begin, (p_right+1) - (p_left) + 1, "" );
					}
					else if( p_left != p_begin && p_right == p_end )
					{
						//tail       "abc\r\nremove the line with 123 in the string"
						m_sRecv = m_sRecv.replace( p_left-1-p_begin, (p_right) - (p_left-1) + 1, "" );
					}
					else
					{
						//middle     "abc\r\nremove the line with 123 in the string\r\nxyz"
						m_sRecv = m_sRecv.replace( p_left-1-p_begin, (p_right-1) - (p_left-1) + 1, "" );
					}
				}
			}
		}

		//������ͻ��˵�"; "�����ʶ�����������Ҫ���Էſ���if����
		if (strncmp( m_sSend.c_str(), "show int | inc drop", strlen("show int | inc drop")) == 0
			|| strncmp( m_sSend.c_str(), "show chassis hardware", strlen("show chassis hardware") )== 0 ) //ԭʼ�������Ϊ��show chassis hardware | no-more
		{
			while (m_sRecv.find("; ") != string::npos)
			{
				m_sRecv = m_sRecv.replace(m_sRecv.find("; "), 2, ";");
			}

			if (strstr(m_sRecv.c_str(), "; ") != NULL)
			{
				printf("the content still has the string of special 1.\n");
			}
		}

		// ��������Ӧ���
		map<string, string>::iterator map_it = m_mapComm.find(m_sSend);
		if (map_it != m_mapComm.end())
		{
			//�޳�ǰ��ո�
			while(m_sRecv.length() >= 1&& m_sRecv.compare(0,1," ") == 0)
			{
				m_sRecv = m_sRecv.substr(1,m_sRecv.length() - 1);
			}
			while(m_sRecv.length() >= 1 && m_sRecv.compare(m_sRecv.length() - 1,1," ") == 0)
			{
				m_sRecv = m_sRecv.substr(0,m_sRecv.length() - 1);
			}
			m_mapComm[m_sSend] = m_sRecv;
		}

		// Mod by Henchi, 20110124
		// ��������յ������ý��
		//if (GetStepNo() == ReqCfgCmd && m_sSend.compare("show running-config") == 0)
		if (GetStepNo() == ReqCfgCmd)
		{
			m_bLogoutFlag = true;
			if (m_sSend.compare("show running-config") == 0)
			{
				LogOut((char *)m_sRecv.c_str(), m_sRecv.length());
			}
			else if (m_sRecv.length() > 0)
			{
				LogOut(
					(char *)m_sRecv.c_str(),
					m_sRecv.length(),
					(char *)(m_sSend.c_str()));
			}
		}

		if (GetStepNo() == ReqCmd && m_manfacid != CISCO)		//��cisco�豸
		{
			m_bLogoutFlag = true;
			if (m_sSend.compare("get config") == 0)				//Juniper�豸
			{
				RemoveSpecialChar(m_sRecv);
				LogOut((char *)m_sRecv.c_str(), m_sRecv.length());
			}
			else if (m_sSend.compare("cat bigip.conf") == 0)	//F5�豸
			{
				LogOut((char *)m_sRecv.c_str(), m_sRecv.length());
			}
			else if (m_sRecv.length() > 0)
			{
				LogOut(
					(char *)m_sRecv.c_str(),
					m_sRecv.length(),
					(char *)(m_sSend.c_str()));
			}
		}

		if (strncmp(m_sSend.c_str(), "ping", strlen("ping")) == 0)
		{
			CCiscoPingResult Result;
			if (Result.LoadResult(m_sRecv))
			{
				m_mapPing[Result.GetAddress()] = Result;
			}
		}

		m_sRecv = "";
	}
	else if (iCase == 0)
	{
		nSwitch = -1;
	}
	else if( GetStepNo() != End )
	{
		nSwitch = 0;

		////����"--- more ---"֮����ַ�
		//if (strstr(pBuf, MORESTR) != NULL)
		//{
		//	if (nSwitch != 2)
		//	{
		//		nSwitch = 2;
		//	}
		//	printf("the content still has the string of more 2.\n");
		//}

		m_sRecv.append(pBuf, iLen);
		return nSwitch;
	}

	return nSwitch;
}

void CTelnetClient::SendMsg(void *pDest, char *pBuf, int iLen)
{
	m_sSend = pBuf;
	if (m_nMode == telnet)
	{
#ifdef LINUX
		sowriteline((FILE *)pDest, stdout, (unsigned char *)pBuf, iLen);
#endif
	}
	else if (m_nMode == ssh)
	{
		channelwriteline((ssh_channel) pDest, pBuf, iLen);
	}
}

void CTelnetClient::channelwriteline(ssh_channel channel, char *pBuf, int iLen)
{
	char *p = pBuf;
	ssh_channel_write(channel, pBuf, iLen);
	if (*(p + iLen - 1) != '\n')
	{
		ssh_channel_write(channel, "\n", 1);
	}
}

void CTelnetClient::DoResponse(
	int &nSwitch,
	void *pDest,
	LIST_STR_ITER &listIt,
	LIST_STR_ITER &listEnd)
{
	if (nSwitch == 1
	&&	pDest != NULL
	&&	GetStepNo() > Start
	&&	GetStepNo() < End)
	{
		if (GetStepNo() == ReqUser)
		{
			// Send UserName
			SendMsg(pDest, (char *)m_sUser.c_str(), m_sUser.length());
			SetStepNo(RspUser);
		}
		else if (GetStepNo() == ReqPswd)
		{
			// Send Password
			SendMsg(pDest, (char *)m_sPswd.c_str(), m_sPswd.length());
			SetStepNo(RspPswd);
		}
		else if (GetStepNo() == ReqCmd)
		{
			if (m_manfacid == CISCO)	//cisco�豸
			{
				// Send "enable"
				SendMsg(pDest, (char *)"enable", strlen("enable"));
				SetStepNo(RspCmd);
			}
			else						//��cisco�豸
			{
				if (listIt != listEnd)
				{
					// Send Commands
					SendMsg(
						pDest,
						(char *)(*listIt).c_str(),
						strlen((*listIt).c_str()));
					listIt++;
				}
				else
				{
					// Send "exit"
					SetStepNo(End);
					SendMsg(pDest, (char *)"exit", strlen("exit")); //
				}
			}
		}
		else if (GetStepNo() == ReqCfgPswd)
		{
			// Send config Password
			SendMsg(pDest, (char *)m_sCfgPswd.c_str(), m_sCfgPswd.length());
			SetStepNo(RspCfgPswd);
		}
		else if (GetStepNo() == ReqCfgCmd)
		{
			if (listIt != listEnd)
			{
				// Send Commands
				SendMsg(
					pDest,
					(char *)(*listIt).c_str(),
					strlen((*listIt).c_str()));
				listIt++;
			}
			else
			{
				// Send "quit"
				SetStepNo(End);
				SendMsg(pDest, (char *)"quit", strlen("quit"));
			}
		}

		nSwitch = 0;
	}
	//else if (nSwitch == 2)					//moreģʽ��ȡ
	//{
	//	if (GetStepNo() != End)
	//	{
	//		string	temp_send = m_sSend;	//��¼ԭʼ��������
	//		SendMsg(pDest, (char *)SPACECHAR, strlen(SPACECHAR));	//moreģʽ��ȡ
	//		m_sSend = temp_send;
	//	}

	//	nSwitch = 0;
	//}
	else if (nSwitch == -1)
	{
		SendMsg(pDest, (char *)"n", strlen("n"));
		nSwitch = 0;
	}
	else if(GetStepNo() == End)
	{
		SendMsg(pDest, (char *)"exit", strlen("exit"));
		nSwitch = 0;
	}
}

int CTelnetClient::GetConfig(void)
{
#ifndef LINUX
	return -1;
#else
	unsigned char buf[BUFSIZE];
	int s;
	int nfds;					/* socket and # file descriptors */
	int cc;
	int on = 1;
	fd_set	arfds;
	fd_set	awfds;
	fd_set	rfds;
	fd_set	wfds;
	FILE *sfp;

	s = connect_TCP(m_sHost.c_str(), m_iPort);
	fsmbuild();					/* set up FSM's */
	(void)setsockopt(s, SOL_SOCKET, SO_OOBINLINE, (char *) &on, sizeof(on));
	nfds = getdtablesize();
	FD_ZERO(&arfds);
	FD_ZERO(&awfds);
	FD_SET(s, &arfds);			/* the socket			*/
	sfp = fdopen(s, "w");		/* to get buffered output	*/

	SetStepNo(0);

	int nSwitch = 0;
	LIST_STR_ITER listIt = m_lCommands.begin();
	LIST_STR_ITER listEnd = m_lCommands.end();

	while (1)
	{
		memcpy(&rfds, &arfds, sizeof(rfds));
		memcpy(&wfds, &awfds, sizeof(rfds));

		if (select(nfds, &rfds, &wfds, (fd_set *)0, (struct timeval *)0) < 0)
		{
			if (errno == EINTR)
			{
				continue;		/* just a signal	*/
			}

			errexit("select: %s\n", strerror(errno));
			FILE_CLOSE(sfp);
			return 1;
		}

		if (FD_ISSET(s, &rfds))
		{
			memset(buf, 0x00, sizeof(buf));
			cc = read(s, (char *)buf, sizeof(buf) - 1);
			if (cc < 0)
			{
				errexit("socket read: %s\n", strerror(errno));
				FILE_CLOSE(sfp);
				return 1;
			}
			else if (cc == 0)
			{
				//				printf("\nconnection closed.\n");
				if (GetStepNo() != End)
				{
					SetStepNo(GetStepNo()+(ReqUser_error-ReqUser));
				}

				return;

				FILE_CLOSE(sfp);
				return 0;
			}
			else
			{
				//				ttwrite(sfp, stdout, buf, cc);		/* Standard output */
				RecvMsg(nSwitch, (char *)buf, cc);
				DoResponse(nSwitch, (void *)sfp, listIt, listEnd);
			}
		}

		(void)fflush(sfp);
		(void)fflush(stdout);
	}

#endif
}

void CTelnetClient::SSHSelectLoop(ssh_session session, ssh_channel channel)
{
	ssh_channel channels[2];

	ssh_channel outchannels[2];
	char buffer[4096];
	int cc;
	int maxfd = ssh_get_fd(session) + 1;
	fd_set	fds;
	struct timeval	timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;

	int fd = ssh_get_fd(session);

	SetStepNo(0);

	int nSwitch = 0;
	LIST_STR_ITER listIt = m_lCommands.begin();
	LIST_STR_ITER listEnd = m_lCommands.end();

	int repeats = 0;

	while (channel)
	{
		FD_ZERO(&fds);
		FD_SET(fd, &fds);

		channels[0] = channel;	// set the first channel we want to read from
		channels[1] = NULL;

		int ret = ssh_select(channels, outchannels, maxfd, &fds, &timeout);
		if (ret == EINTR || ret == SSH_EINTR)
		{
			continue;
		}

		if (channel && ssh_channel_is_closed(channel))
		{
			if (GetStepNo() != End)
			{
                            SetStepNo(GetStepNo()+(ReqUser_error-ReqUser));
			}

			return;
		}

		if( channel
		&&	ssh_channel_is_open(channel)
		&&	ssh_channel_poll(channel, 0) )
		{
			while( channel && ssh_channel_is_open(channel) )
			{
				memset(buffer, 0x00, sizeof(buffer));
				cc = ssh_channel_read(channel, buffer, sizeof(buffer) - 1, 0);

				if (cc == -1 || cc == -127 )
				{
					printf("return read length=[%d],GetStepNo=[%d] device=[%s] send=[%s] receive length=[%d]\n",
						cc,GetStepNo(),m_sHost.c_str(),m_sSend.c_str(),m_sRecv.length());
					return;
				}
                                else if( cc == -2 )
                                {
                                        continue;
                                }
				else if (cc == 0)
				{
					if (GetStepNo()>Start && GetStepNo() != End)
					{
						//SetStepNo(Error);
                                       		 printf("current read length=[%d],GetStepNo=[%d] device=[%s] send=[%s] receive length=[%d]\n",
                                               		 cc,GetStepNo(),m_sHost.c_str(),m_sSend.c_str(),m_sRecv.length());
						continue;
					}
					else
					{
						if( GetStepNo() == Start )
						{
							printf("can't analyse [%s][%d][%s]!\n",m_sRecv.c_str(),m_sRecv.length(),m_sHost.c_str());
						}
						return;
					}
				}
				else
				{
					if (strchr(buffer, '\b') != NULL)
					{
						char data[4096] = "\0";
						int index = 0;
						char *p = buffer;
						while ((*p) != '\0')
						{
							if ((*p) != '\b')
							{
								sprintf(data + index, "%c", *p);
								index++;
							}

							p++;
						}

						RecvMsg(nSwitch, (char *)data, index);
					}
					else
					{
						RecvMsg(nSwitch, (char *)buffer, cc);
					}

					DoResponse(nSwitch, (void *)channel, listIt, listEnd);
				}
			}
			//���е������ʾchannel�쳣
			printf("warning:ssh_channel_is_open=[%d]\n", ssh_channel_is_open(channel));
		}

		//ִ�е��ˣ�˵������whileѭ������������(�����豸��Ϊssh_channel_poll����������)
		if ( (m_manfacid == F5)
			|| (m_manfacid == CISCO&&find(g_devlist.begin(),g_devlist.end(), m_sHost)!=g_devlist.end() ) )	//��F5 Big-IP�豸�����Ƶ�cisco�豸���⴦��
		{
			for (; listIt != listEnd; listIt++)
			{
				//send command
				//recv data
				if (channel && ssh_channel_is_open(channel))
				{
					SendMsg(
						(void *)channel,
						(char *)(*listIt).c_str(),
						listIt->length());
				}

				while (channel && ssh_channel_is_open(channel))
				{
					memset(buffer, 0x00, sizeof(buffer));
					cc = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
					if (cc > 0)
					{
						m_sRecv.append(buffer, cc);
					}
					else if ((cc == 0) || (cc == -2))	//-2��ʶ��ʱ
					{
						if (m_sRecv.length() == 0 && cc != -2)
						{
							//���û�ж������ݣ��ǳ�ʱ����£������ٴζ�ȡ
							continue;
						}
						//�޳�ǰ��ո�
						while(m_sRecv.length() >= 1&& m_sRecv.compare(0,1," ") == 0)
						{
							m_sRecv = m_sRecv.substr(1,m_sRecv.length() - 1);
						}

						////�޳�ǰ�˿���
						while(m_sRecv.length() >= strlen(FLAG_NEW_LINE)
							&&	m_sRecv.compare(0,strlen(FLAG_NEW_LINE),FLAG_NEW_LINE) == 0)
						{
							m_sRecv = m_sRecv.substr(strlen(FLAG_NEW_LINE),m_sRecv.length() - strlen(FLAG_NEW_LINE));
						}
						//ȥ����˿���
						while(m_sRecv.length() >= strlen(NEW_FLAG_NEW_LINE)
							&&	m_sRecv.compare(m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE),strlen(NEW_FLAG_NEW_LINE),
									NEW_FLAG_NEW_LINE) == 0 )
						{
							m_sRecv = m_sRecv.substr(0,m_sRecv.length() - strlen(NEW_FLAG_NEW_LINE));
						}


                                                if( strncmp(m_sSend.c_str(), "show hardware profile buffer monitor brief",strlen("show hardware profile buffer monitor brief")) == 0 ||(strncmp(m_sSend.c_str(), "show hw-module all fpd",strlen("show hw-module all fpd")) == 0)  )
                                                {
                                                    while (m_sRecv.find(EQUALCHAR) != string::npos)
                                                    {
                                                           m_sRecv = m_sRecv.replace(
                                                                                     m_sRecv.find(EQUALCHAR),
                                                                                     strlen(EQUALCHAR),
                                                                                     "-");
                                                    }
  
                                                    if (strstr(m_sRecv.c_str(), EQUALCHAR) != NULL)
                                                    {
                                                           printf("the content still has the string of [=]CSIO .\n");
                                                    }
                                                }


						//���ؽ���в��ܰ�����; �������ַ�����Ŀǰ��ʱֻ�������������У�����Ҫ���Էſ����������
						//if (strncmp(m_sSend.c_str(), "show chassis hardware",
						//		strlen("show chassis hardware")) == 0)
						//{
						//	while (m_sRecv.find("; ") != string::npos)
						//	{
						//		m_sRecv = m_sRecv.replace(m_sRecv.find("; "), 2, ";");
						//	}
						//}

						if ( m_sSend.compare("show running-config") == 0 )
						{
							//delete special line.
							int pos,pos_begin,pos_end;
							if( (pos = m_sRecv.find("!Time:") ) != string::npos )
							{
								pos_begin = m_sRecv.rfind(FLAG_NEW_LINE, pos);
								pos_end = m_sRecv.find(FLAG_NEW_LINE, pos);
								if( pos_begin != string::npos && pos_end != string::npos )
								{
									m_sRecv = m_sRecv.replace(pos_begin+strlen(FLAG_NEW_LINE),pos_end -(pos_begin+strlen(FLAG_NEW_LINE)),"");
								}
							}
							LogOut((char *)m_sRecv.c_str(), m_sRecv.length());
						}
						else if( m_sSend.compare("cat bigip.conf") == 0 )
						{
							LogOut((char *)m_sRecv.c_str(), m_sRecv.length());
						}
						else if (m_sRecv.length() > 0 && m_sSend.compare("term length 0") !=0  )
						{
							LogOut(
								(char *)m_sRecv.c_str(),
								m_sRecv.length(),
								(char *)(m_sSend.c_str()));
						}
						
						map<string, string>::iterator map_it = m_mapComm.find(
								m_sSend);
						if (map_it != m_mapComm.end())
						{
							m_mapComm[m_sSend] = m_sRecv;
						}

						m_bLogoutFlag = true;
						m_sRecv = "";
						break;
					}
					else
					{
						break;
					}
				}
			}

			return;
		}
		
		repeats++;
		if( repeats > 3600 )
		{
			printf("Host ip=[%s] repeat times=[%d] cmds count=[%d] first cmd=[%s].\n",
				m_sHost.c_str(),repeats,m_lCommands.size(),m_lCommands.begin()->c_str());
			break;
		}
		SleepMs(1);
	}

	if (GetStepNo() != End)
	{
            SetStepNo(GetStepNo()+(ReqUser_error-ReqUser));
	}

	return;
}

int CTelnetClient::Authenticate_kbdint(
	ssh_session session,
	const char	*password)
{
	int err;

	err = ssh_userauth_kbdint(session, NULL, NULL);
	while (err == SSH_AUTH_INFO)
	{
		const char	*instruction;
		const char	*name;
		char buffer[128];
		int i;
		int n;

		name = ssh_userauth_kbdint_getname(session);
		instruction = ssh_userauth_kbdint_getinstruction(session);
		n = ssh_userauth_kbdint_getnprompts(session);

		if (name && strlen(name) > 0)
		{
			printf("%s\n", name);
		}

		if (instruction && strlen(instruction) > 0)
		{
			printf("%s\n", instruction);
		}

		for (i = 0; i < n; i++)
		{
			const char	*answer;
			const char	*prompt;
			char echo;

			prompt = ssh_userauth_kbdint_getprompt(session, i, &echo);
			if (prompt == NULL)
			{
				break;
			}

			if (echo)
			{
				char *p;

				printf("%s", prompt);

				if (fgets(buffer, sizeof(buffer), stdin) == NULL)
				{
					return SSH_AUTH_ERROR;
				}

				buffer[sizeof(buffer) - 1] = '\0';
				if ((p = strchr(buffer, '\n')))
				{
					*p = '\0';
				}

				if (ssh_userauth_kbdint_setanswer(session, i, buffer) < 0)
				{
					return SSH_AUTH_ERROR;
				}

				memset(buffer, 0, strlen(buffer));
			}
			else
			{
				if (password && strstr(prompt, "Password:"))
				{
					answer = password;
				}
				else
				{
					buffer[0] = '\0';

					if (ssh_getpass(prompt, buffer, sizeof(buffer), 0, 0) < 0)
					{
						return SSH_AUTH_ERROR;
					}

					answer = buffer;
				}

				if (ssh_userauth_kbdint_setanswer(session, i, answer) < 0)
				{
					return SSH_AUTH_ERROR;
				}
			}
		}

		err = ssh_userauth_kbdint(session, NULL, NULL);
	}

	return err;
}

int CTelnetClient::SSHGetConfig(void)
{
	ssh_session session = ssh_new();
	if (session != NULL)
	{
		if (ssh_options_set(
				session,
			SSH_OPTIONS_HOST,
			m_sHost.c_str()) < 0
		||	ssh_options_set(session, SSH_OPTIONS_USER, m_sUser.c_str()) < 0)
		{
			ssh_free(session);
			return -1;
		}
		else
		{
			ssh_options_parse_config(session, NULL);
		}
	}
	else
	{
		return -1;
	}

	if (ssh_connect(session) != 0)
	{
		ssh_free(session);
		return -1;
	}
	else
	{
		if( find(g_srxdevlit.begin(),g_srxdevlit.end(),m_sHost ) != g_srxdevlit.end() )
		{
                        if (Authenticate_kbdint(
                                        session,
                                m_sPswd.c_str()) != SSH_AUTH_SUCCESS)
                        {
                                printf(
                                        "device [%s] with username [%s] password [%s] authenticate fail.\n",
                                        m_sHost.c_str(),
                                        m_sUser.c_str(),
                                        m_sPswd.c_str());
                                ssh_disconnect(session);
                                ssh_free(session);
                                return -1;
                        }
		}
		else if (ssh_userauth_password(
				session,
			NULL,
			m_sPswd.c_str()) != SSH_AUTH_SUCCESS)
		{
			if (Authenticate_kbdint(
					session,
				m_sPswd.c_str()) != SSH_AUTH_SUCCESS)
			{
				printf(
					"device [%s] with username [%s] password [%s] authenticate fail.\n",
					m_sHost.c_str(),
					m_sUser.c_str(),
					m_sPswd.c_str());
				ssh_disconnect(session);
				ssh_free(session);
				return -1;
			}
		}
	}

	ssh_channel channel = ssh_channel_new(session);
	if (channel != NULL)
	{
		if (ssh_channel_open_session(channel) != 0)
		{
			ssh_channel_free(channel);
			ssh_disconnect(session);
			ssh_free(session);
			return -1;
		}
		else
		{
			if (ssh_channel_request_shell(channel) != 0)
			{
				ssh_channel_free(channel);
				ssh_disconnect(session);
				ssh_free(session);
				return -1;
			}
		}
	}

	SSHSelectLoop(session, channel);

	if (channel)
	{
		ssh_channel_free(channel);
		channel = NULL;
	}

	if (session)
	{
		ssh_disconnect(session);
		ssh_free(session);
	}

	return 0;
}

int CTelnetClient::DoTask(void)
{
	if (m_nMode == telnet)
	{
		GetConfig();
	}
	else if (m_nMode == ssh)
	{
		SSHGetConfig();
	}

	FILE_CLOSE(m_fOutput);

	/// ע��:���߳�ͬʱ������ΪͬһĿ���ļ�ʱ,���ܲ���������ʧ��.
		/// ��ͨ����Ӧ���ж���߳�ͬʱ�ɼ�ͬһ�豸���������...
	///GetStepNo() != 0���������ӦSSHSelectLoop�����еķ�֧if(!ssh_channel_poll(channel, 0))
	int iRtn = ( (GetStepNo() != 0) && (GetStepNo() != End)) ? max(
			1,
			GetStepNo()) : 0;
    if( iRtn > 0 )
    {
        //��ӡ�쳣���
        printf("warning:device [%s] with username [%s] password [%s] fail,result is: GetStepNo()=[%d].\n",
			m_sHost.c_str(),
			m_sUser.c_str(),
			m_sPswd.c_str(),
			GetStepNo());
    }
    if (m_bLogoutFlag && iRtn == 0)
    {
        if(m_sTempName.empty()
          && m_sFileName.empty()
          &&((m_sSend.compare("show interface | include drop | exclude \"0 watchdog  0 bad etype drop  0 bad proto drop  0 if down drop\" | no-more") == 0)
          ||(m_sSend.compare("show interface | include error | exclude \"0 output error  0 collision  0 deferred  0 late collision\" | exclude \"0 input error  0 short frame  0 overrun   0 underrun  0 ignored\" | no-more") == 0)
          ||(m_sSend.compare("show policy-map interface | include drop | exclude \"action: drop\"| exclude \"queue dropped pkts : 0\" | no-more")==0 )))
        {
            //do nothing
        }
        else
            iRtn = rename(m_sTempName.c_str(), m_sFileName.c_str());
        if( iRtn != 0 )
        {
            //��ӡ�쳣���
            printf("warning:rename fail  device [%s] m_sTempName [%s], m_sFileName [%s] , iRtn=[%d].\n",
                m_sHost.c_str(),
                m_sTempName.c_str(),
                m_sFileName.c_str(),
                iRtn);
        }
    }
    else
    {
        printf("warning:task fail device [%s] when writing file because of m_bLogoutFlag = [%s], iRtn = [%d].\n",m_sHost.c_str(),m_bLogoutFlag?"true":"false",iRtn);
    }

	return iRtn;
}

void CTelnetClient::RemoveSpecialChar(string &data)
{
	while (strstr(data.c_str(), SPECIAL_STR) != NULL)	//����MORESPE_STR
	{
		data = data.replace(data.find(SPECIAL_STR), strlen(SPECIAL_STR), "");
	}

	if (strstr(data.c_str(), SPECIAL_STR) != NULL)
	{
		printf("the content still has the string of more special 2.\n");
	}

	while (strstr(data.c_str(), MORESTR) != NULL)
	{
		data = data.replace(data.find(MORESTR), strlen(MORESTR), "");
	}

	if (strstr(data.c_str(), MORESTR) != NULL)
	{
		printf("the content still has the string of more 2.\n");
	}
}
