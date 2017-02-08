/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	monfront.cpp
///@brief	�ƶ����ǰ�õ�main������ʵ��
///@history
///20140617	����		�������ļ�
/////////////////////////////////////////////////////////////////////////
#include "public.h"
#include "Config.h"
#include "xmlcfg.h"
#include "CDeployConfig.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "version.h"
#include "CFilelogService.h"
#include "FtdEngine.h"
#include <iostream>

using namespace std;

const char	*INI_FILE_NAME = "monfront.ini";
char *g_mXMLPath = "./monfront.xml";

bool globalInit(void)
{
	time_t	timep;
	time(&timep);
	printf("%s sysfront Start Running !!!\n", ctime(&timep));
	fflush(stdout);

	return true;
}


class CPackageHandleCounter
{
public:
	virtual int GetHandleCount() = 0;
};

class CFrontReactor : public CSelectReactor, public CPackageHandleCounter
{
public:
	CFrontReactor(DWORD dwFrontID, CFlow *pTradeResult)
	{
		m_dwFrontID = dwFrontID;
		m_pFtdEngine = NULL;
		m_pLogFlow = pTradeResult;
	}

	virtual bool InitInstance()
	{
		m_pFtdEngine = new CFtdEngine(this, NULL);
		m_pFtdEngine->RegisterListener("tcp://192.168.1.10:12345");

		//Redo();

		return true;
	}

	virtual void ExitInstance()
	{
		delete m_pFtdEngine;
	}

	void Redo()
	{
		//m_reader.AttachFlow(m_pLogFlow, 0);
		for(;;)
		{
			//if(!m_reader.GetNext(XXX, XXX))
				break;
		}
	}

	virtual bool HandleOtherTask()
	{
		return CSelectReactor::HandleOtherTask();
	}
	
	virtual int GetHandleCount()
	{
		return 0;
	}
private:
	DWORD m_dwFrontID;
	CFtdEngine *m_pFtdEngine;
	CFlow *m_pLogFlow;
	CFlowReader m_reader;
};

int main(int argc, char *argv[])
{
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
#endif

	showVersion(argc, argv);
	
	globalInit();

	try
	{
		CFrontReactor *pFrontReactor = NULL;
		pFrontReactor = new CFrontReactor(0, NULL);
		pFrontReactor->Create();
		pFrontReactor->Join();
		return 0;
	}
	catch(...)
	{
		time_t	t;
		time(&t);
		printf("\nTime:%sFailed, quit.\n", ctime(&t));
		exit(-1);
	}
}
