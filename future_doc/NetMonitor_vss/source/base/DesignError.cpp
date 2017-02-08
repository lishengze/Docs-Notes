//**********************************************************************
//ϵͳ�����Ϻ��ڻ�������ϵͳ����
//��˾�����Ϻ��ڻ���Ϣ�������޹�˾
//�ļ�����CDesignError.h
//��Ҫ����:ʵ������CDesignError
//�޸���ʷ��
//20020214	���ض�		�������ļ�
//**********************************************************************

#include "CBaseObject.h"

CDesignError::CDesignError(char *pszMsg, char *pszFile, int nLineNo)
{
	m_pszMsg = new char[strlen(pszMsg)+1];
	strcpy(m_pszMsg, pszMsg);
	m_pszFile = pszFile;
	m_nLineNo = nLineNo;
}

CDesignError::~CDesignError()
{
	delete m_pszMsg;
}

char *CDesignError::GetMsg(void)
{
	return m_pszMsg;
}

char *CDesignError::GetFile(void)
{
	return m_pszFile;
}

int CDesignError::GetLineNo(void)
{
	return m_nLineNo;
}
