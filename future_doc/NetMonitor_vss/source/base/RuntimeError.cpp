//**********************************************************************
//�ļ�����CRuntimeError.h
//��Ҫ����:ʵ������CRuntimeError
//�޸���ʷ��
//**********************************************************************

#include "CBaseObject.h"

CRuntimeError::CRuntimeError(char *pszMsg, char *pszFile, int nLineNo)
{
	m_pszMsg = new char[strlen(pszMsg)+1];
	strcpy(m_pszMsg, pszMsg);
	m_pszFile = pszFile;
	m_nLineNo = nLineNo;
}

CRuntimeError::~CRuntimeError()
{
	delete m_pszMsg;
}

char *CRuntimeError::GetMsg(void)
{
	return m_pszMsg;
}

char *CRuntimeError::GetFile(void)
{
	return m_pszFile;
}

int CRuntimeError::GetLineNo(void)
{
	return m_nLineNo;
}
