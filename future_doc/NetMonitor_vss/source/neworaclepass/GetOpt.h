/////////////////////////////////////////////////////////////////////////
///@system OraclePass
///@company 上海期货信息技术有限公司
///@file GetOpt.h
///@brief声明了GetOption函数。由于Windows不提供getopt()函数，用GetOption()替代。
///@history 
///20070702 严少辉		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef GETOPTION_H
#define GETOPTION_H

#include <stddef.h>
#include <ctype.h>
#include <string.h>

int GetOption(int argc, char** argv, char*pszValidOpts, char** ppszParam);

#endif