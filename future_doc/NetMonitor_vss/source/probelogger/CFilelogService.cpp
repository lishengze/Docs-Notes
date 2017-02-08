/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CFilelogService.cpp
///@brief	实现了使用文件实现探针接口
///@history 
///20060724	王肇东		创建该文件
///20060827	赵鸿昊		增加了创建实例的方法
///20120726 江鹏        对于不安全函数进行了对应安全版本的封装：localtime
/////////////////////////////////////////////////////////////////////////
#include "CFilelogService.h"

void CFilelogService::SendProbeMessageImpl
	(
		const char *programName,
		const int globalSeq,
		const char *parameter,
		const char *value
	)
{
	if (m_fp!=NULL)
	{
		time_t now;
		time(&now);
		char timeBuffer[100];
		struct tm tmNow;
		LocalTime(&now, &tmNow);
		strftime(timeBuffer, 100,"%b %d %H:%M:%S",&tmNow);
		fprintf(m_fp, "%s %s %s %d[%d]: %s %s\n", timeBuffer,m_hostname,programName, globalSeq, m_pid, parameter, value );
		fflush(m_fp);
	}
}

CFilelogService *CFilelogService::CreateInstance(int argc, char *argv[], const char *fileName)
{
	if ((fileName==NULL)||(fileName[0]=='\0'))
	{
		return NULL;
	}
	int globalSeq;
	if (argc>=2)
	{
		globalSeq=atoi(argv[1]);
	}
	else
	{
		globalSeq=0;
	}

	char fullProgramName[500];
	strcpy(fullProgramName,argv[0]);

	char *programName;
	programName=strrchr(fullProgramName,PATH_SPLIT);
	if (programName!=NULL)
	{
		programName++;
	}
	else
	{
		programName=fullProgramName;
	}
	programName=strtok(programName,".");
	programName=strdup(programName);

	return new CFilelogService(programName,globalSeq,fileName);
}
