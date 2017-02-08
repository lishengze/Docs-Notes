/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CFilelogService.cpp
///@brief	ʵ����ʹ���ļ�ʵ��̽��ӿ�
///@history 
///20060724	���ض�		�������ļ�
///20060827	�Ժ��		�����˴���ʵ���ķ���
///20120726 ����        ���ڲ���ȫ���������˶�Ӧ��ȫ�汾�ķ�װ��localtime
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
