/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CSequenceInterface.cpp
///@briefʵ������CSequenceInterface
///@history 
///20041001	���ض�		�������ļ�
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
