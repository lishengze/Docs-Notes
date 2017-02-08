/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file version.h
///@brief	����һ������İ汾��
///@history 
///20020907	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "version.h"
#include "versionValue.h"
#include "monitorIndex.h"

void showVersion(int argc,char *argv[])
{
	if ((argc==2)&&(!strcmp(argv[1],"-v")))
	{
		printf("%s version: %s\n",argv[0],version);
		exit(0);
	}
	new CStringMonitorIndex("Version",version,36000);
}
