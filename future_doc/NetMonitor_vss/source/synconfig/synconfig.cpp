/////////////////////////////////////////////////////////////////////////
///@system	������ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	synconfig.cpp
///@brief	���ù����������main������ʵ��
///@history
///20110112	�ܽ���		�������ļ�
/////////////////////////////////////////////////////////////////////////
#include "public.h"
#include <CConfig.h>
#include "CSynconfig.h"
#include "version.h"

extern bool UseNetCompressLog;	// ����ѹ����Ϣ�������
CSynconfig	*synconfig;

const char	*g_FileXMLPath = "../FilePackage/";
const char	*g_FileServPath = "../FilePackage/files/";

int main(int argc, char *argv[])
{
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);

	//	signal(SIGINT, SIG_IGN);
#endif
#ifdef WIN32
	// ��������ڴ�й©
	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	tmpFlag |= _CRTDBG_CHECK_ALWAYS_DF |
		_CRTDBG_LEAK_CHECK_DF |
		_CRTDBG_ALLOC_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	//_CrtSetBreakAlloc(650);
#endif
	showVersion(argc, argv);

	// �رձ���ѹ�������Ϣ
	UseNetCompressLog = false;

	printf("program is running............................\n");
	fflush(stdout);

	try
	{
		synconfig = new CSynconfig;

		if (!synconfig->Init(argc, argv))
		{
			throw new CRuntimeError("Init Error", __FILE__, __LINE__);
		}

		LOG_INFO("synconfig is initialized ! %s", CurrentTime());

		synconfig->Start();

		LOG_INFO("synconfig is ready for connection ! %s", CurrentTime());

		synconfig->Wait();

		delete synconfig;

		return 0;
	}
	catch(...)
	{
		printf("\nTime:%sFailed, quit.\n", CurrentTime());
		delete synconfig;
		exit(-1);
	}
}
