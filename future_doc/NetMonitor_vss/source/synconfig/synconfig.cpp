/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	synconfig.cpp
///@brief	配置管理服务器的main主函数实现
///@history
///20110112	周建军		创建该文件
/////////////////////////////////////////////////////////////////////////
#include "public.h"
#include <CConfig.h>
#include "CSynconfig.h"
#include "version.h"

extern bool UseNetCompressLog;	// 报文压缩信息输出开关
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
	// 用来检测内存泄漏
	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	tmpFlag |= _CRTDBG_CHECK_ALWAYS_DF |
		_CRTDBG_LEAK_CHECK_DF |
		_CRTDBG_ALLOC_MEM_DF;
	_CrtSetDbgFlag(tmpFlag);

	//_CrtSetBreakAlloc(650);
#endif
	showVersion(argc, argv);

	// 关闭报文压缩输出信息
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
