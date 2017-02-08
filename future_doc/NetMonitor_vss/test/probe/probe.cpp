#include "probe.h"
#include "Config.h"
#include "configmanager.h"
#include "CSysLogReader.h"
#include "Mutex.h"

const char	*INI_FILE_NAME		= "probe.ini";
const char  *XML_FILE_NAME		= "probe.xml";

char g_pManagerStart[200];		// ��������ʼ�����Ĺ���˿�
char g_pManagerStop[200];		// ���������������Ĺ���˿�
char g_mCfgPath[200];			//���������ļ�·��
char g_mFlowPath[200];			//�������ļ��洢·��
char g_mDumpPath[200];		//����Ӧ��������ļ�
char g_mLogPath[200];		//ϵͳ��־�洢��λ��
char g_mLogFileName[200];	//ϵͳ��־�ļ���
char g_mAppBasePath[200];	//Ӧ�û���Ŀ¼
char g_mAppListPath[200];	//Ӧ���б�·��
char g_mDumpOutput[200];    //Ӧ��syslog�����Ŀ¼
char g_mAppPathPrefix[200];	//Ӧ�ù���Ŀ¼��ǰ׺
char g_mTimeStamp[8];		//���Ƶ��βɼ��������ʼʱ��

int g_nTouchCount = 0;   //��touch�Ĵ���	
int g_nWorkFlag = 0;	// 0:����״̬; 1:�ɼ�״̬; 2:���״̬;
CMutex g_mWorkFlagMutex;  //WorkFlag��д��

char g_pHostName[32];   // ������������

extern map<string, string>	g_mSpcPrcMap;

void CProbeServer::Join()
{
	fd_set active, read;
	int nMaxFD, nRet;

	while (1) {
		FD_ZERO(&active);
		FD_SET(m_startCtrl.GetId(), &active);
		FD_SET(m_stopCtrl.GetId(), &active);

		nMaxFD = m_startCtrl.GetId();
		if (nMaxFD< m_stopCtrl.GetId()) {
			nMaxFD = m_stopCtrl.GetId();
		}

		nMaxFD++;

		read = active;
		struct timeval timeout;
		timeout.tv_sec=5;
		timeout.tv_usec=0;
		nRet = select(nMaxFD, &read, NULL, NULL, &timeout);
		if (nRet<=0) {
#ifdef WINDOWS
			Sleep(30);
#else
			usleep(1000);
#endif
			CMonitorIndex::handleOne();
			continue;
		}
		if (FD_ISSET(m_startCtrl.GetId(), &read)) {
			m_startCtrl.Accept(10);
			if (g_nWorkFlag != 1)
			{
				g_mWorkFlagMutex.Lock();
				time_t curtime = time(NULL);
				strftime(g_mTimeStamp, sizeof(g_mTimeStamp), "%H%M%S", (const tm *)localtime(&curtime));
				
				g_nWorkFlag = 1;
				g_nTouchCount++;
				g_mWorkFlagMutex.UnLock();
			}
		}
		if (FD_ISSET(m_stopCtrl.GetId(), &read)) {
			m_stopCtrl.Accept(10);
			if (g_nWorkFlag != 2)
			{
				g_mWorkFlagMutex.Lock();
				g_nWorkFlag = 2;
				g_nTouchCount++;
				g_mWorkFlagMutex.UnLock();
			}
		}
		time_t tNow=time(NULL);
		CMonitorIndex::handleOne();
	}
}

void globalEnvInit()
{
	if (gethostname(g_pHostName,31)!=0)
	{
		memset(g_pHostName, 0, 32);
	}
	else
	{
		char *p;
		while ((p = strchr(g_pHostName, '.')))			// Mod by Henchi, 20090423
			*p = '_';
	}

	//����probe.ini�ļ�
	GetConfigString(INI_FILE_NAME, "ManagerStart", g_pManagerStart,  sizeof(g_pManagerStart));
	GetConfigString(INI_FILE_NAME, "ManagerStop", g_pManagerStop,  sizeof(g_pManagerStop));
	GetConfigString(INI_FILE_NAME, "ConfigPath",   g_mCfgPath, sizeof(g_mCfgPath));
	GetConfigString(INI_FILE_NAME, "FlowPath",   g_mFlowPath, sizeof(g_mFlowPath));
	GetConfigString(INI_FILE_NAME, "DumpPath", g_mDumpPath,  sizeof(g_mDumpPath));	
	GetConfigString(INI_FILE_NAME, "LogPath",   g_mLogPath, sizeof(g_mLogPath));
	GetConfigString(INI_FILE_NAME, "LogFile",   g_mLogFileName, sizeof(g_mLogFileName));
	GetConfigString(INI_FILE_NAME, "AppPath",   g_mAppBasePath, sizeof(g_mAppBasePath));
	GetConfigString(INI_FILE_NAME, "SrvList",   g_mAppListPath, sizeof(g_mAppListPath));
	GetConfigString(INI_FILE_NAME, "DumpOutput",   g_mDumpOutput, sizeof(g_mDumpOutput));
	GetConfigString(INI_FILE_NAME, "AppPathPrefix",   g_mAppPathPrefix, sizeof(g_mAppPathPrefix));
}

//����ϵͳָ��������
void setSystemAttrSeps(CProbe & probe)
{
	//Ĭ��Ϊ3��
	int iProcessSep = 3;
	int iCPUSep = 3;
	int iNetworkSep = 3;

	map<string, int>::iterator p_it = CConfigManager::Instance()->m_mSysAttrTimers.find("Process");
	if(p_it != CConfigManager::Instance()->m_mSysAttrTimers.end())
	{
		iProcessSep = p_it->second;
	}

	map<string, int>::iterator c_it = CConfigManager::Instance()->m_mSysAttrTimers.find("CPU");
	if(c_it != CConfigManager::Instance()->m_mSysAttrTimers.end())
	{
		iCPUSep = c_it->second;
	}

	map<string, int>::iterator n_it = CConfigManager::Instance()->m_mSysAttrTimers.find("Network");
	if(n_it != CConfigManager::Instance()->m_mSysAttrTimers.end())
	{
		iNetworkSep = n_it->second;
	}

	printf("process_sep=%d, cpu_sep=%d, network_sep=%d\n", iProcessSep, iCPUSep, iNetworkSep);

	probe.SetSysSeps(iProcessSep, iCPUSep, iNetworkSep);
}

int main(int argc, char **argv)
{
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	//	signal(SIGINT, SIG_IGN);
#endif
	globalEnvInit();
	
	CProbe probe;

#ifdef LINUX
	//�ȶ�ȡ����ip
	probe.GetNetwork();
#endif

	//������ip�б�
	vector<string> iplist;
	
#ifdef LINUX
	map <string, netinfo>::iterator i_it = probe.m_mapNetInfo.begin();
	for(; i_it != probe.m_mapNetInfo.end(); ++i_it)
	{
		iplist.push_back(i_it->second.ip);	
	}
#endif

	//���������ļ�
	CConfigManager::Instance()->LoadConfig(iplist);

	//����ϵͳָ��������
	setSystemAttrSeps(probe);

	//��ʼ����app��syslog
	for(map<string, string>::iterator mapIt = g_mSpcPrcMap.begin(); mapIt != g_mSpcPrcMap.end(); mapIt++)
	{
		CSysLogReader * pSyslogReader = new CSysLogReader(mapIt->second);
		pSyslogReader->Create();
	}
	
	probe.Create();
	//CTcpMServer srvManage(&CServiceName(pProbeLocation), 0);
	//srvManage.Join(); 
	CProbeServer probeServer(&CServiceName(g_pManagerStart), &CServiceName(g_pManagerStop));
	probeServer.Join();
	probe.Join();
	return 0;
}
