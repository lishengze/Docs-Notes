/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file GetOpt.h
///@brief������GetOption����������Windows���ṩgetopt()��������GetOption()�����
///@history 
///20070702 ���ٻ�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef GETOPTION_H
#define GETOPTION_H

#include <stddef.h>
#include <ctype.h>
#include <string.h>

int GetOption(int argc, char** argv, char*pszValidOpts, char** ppszParam);

#endif