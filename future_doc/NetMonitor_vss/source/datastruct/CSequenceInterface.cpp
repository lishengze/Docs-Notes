/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CSequenceInterface.cpp
///@brief实现了类CSequenceInterface
///@history 
///20041001	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "CSequenceInterface.h"

CSequenceInterface::CSequenceInterface()
{
}

CSequenceInterface::~CSequenceInterface(void)
{
	CHECK_TYPE("CSequenceInterface");
}

int CSequenceInterface::isA(char *objectType)
{
	if (!strcmp(objectType,"CSequenceInterface"))
		return 1;
	return CSequenceInterface::isA(objectType);
}

char *CSequenceInterface::getType(void)
{
	return "CSequenceInterface";
}
