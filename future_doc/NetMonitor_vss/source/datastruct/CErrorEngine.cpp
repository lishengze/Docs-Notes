/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CErrorEngine.cpp
///@briefʵ������CErrorEngine
///@history 
///20050214	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "CErrorEngine.h"

CErrorEngine::CErrorEngine(void)
{
	m_LastErrorID=0;
	m_LastErrorMsg="��ȷ";
}

CErrorEngine::~CErrorEngine(void)
{
}
	
void CErrorEngine::registerErrorType(int errorID, char *errorMsg)
{
	char buffer[200];
	if (!insert(value_type(errorID,errorMsg)).second)
	{
		sprintf(buffer,"duplicate errorID definition:%d",errorID);
		RAISE_DESIGN_ERROR(buffer);
	}
}

void CErrorEngine::registerErrorType(TErrorType pErrorType[])
{
	int i;
	for (i=0;;i++)
	{
		if (pErrorType[i].errorID==0)
		{
			break;
		}
		registerErrorType(pErrorType[i].errorID,pErrorType[i].errorMsg);
	}
}

void CErrorEngine::reportError(const int errorID)
{
	iterator it;
	char buffer[200];

	it=find(errorID);
	if (it==end())
	{
		sprintf(buffer,"undefined error id %d",errorID);
		RAISE_DESIGN_ERROR(buffer);
	}
	m_LastErrorID=errorID;
	m_LastErrorMsg=it->second;
}
	
char *CErrorEngine::getErrorMsg(const int errorID)
{
	iterator it;
	
	it=find(errorID);
	if (it==end())
	{
		return NULL;
	}
	return it->second;
}

void CErrorEngine::getLastError(int *pLastErrorID,char **pLastErrorMsg)
{
	if (pLastErrorID!=NULL)
	{
		*pLastErrorID=m_LastErrorID;
	}
	if (pLastErrorMsg!=NULL)
	{
		*pLastErrorMsg=m_LastErrorMsg;
	}
	m_LastErrorID=0;
	m_LastErrorMsg="��ȷ";
}

void CErrorEngine::getLastErrorWithoutClear(int *pLastErrorID,char **pLastErrorMsg)
{
	if (pLastErrorID!=NULL)
	{
		*pLastErrorID=m_LastErrorID;
	}
	if (pLastErrorMsg!=NULL)
	{
		*pLastErrorMsg=m_LastErrorMsg;
	}
}
