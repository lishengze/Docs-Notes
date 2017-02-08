/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CBaseObject.cpp
///@briefʵ���˳���Ķ������CBaseObject
///@history 
///20020212	���ض�		�������ļ�
///20020214	���ض�		�޸Ĵ��ļ���ʹcheckType�������ļ������к�
/////////////////////////////////////////////////////////////////////////

#include "CBaseObject.h"
#include "CLogger.h"

FILE *errorOutput=stderr;
int runLevel=0;

CBaseObject::CBaseObject(void)
{
}

CBaseObject::~CBaseObject(void)
{
}

int CBaseObject::isA(char *objectType)
{
	if (!strcmp(objectType,"CBaseObject"))
		return 1;
	return 0;
}

char *CBaseObject::getType(void)
{
	return "CBaseObject";
}

void CBaseObject::checkType(char *objectType, char *filename, int line)
{
	if (!isA(objectType))
	{
		throw (new CDesignError("Invalid Object",filename,line));
	}
}
/*
void CBaseObject::output(CLogger *pLogger,int indent)
{
	pLogger->output(indent,0,"CBaseObject");
}
*/
