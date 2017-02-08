/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CExprException.cpp
///@brief	ʵ������CExprException
///@history 
///20080322	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "CExprException.h"

CExprException::CExprException(char *msg, int lineNo, int columnNo)
{
	m_msg=strdup(msg);
	m_lineNo=lineNo;
	m_columnNo=columnNo;
}

CExprException::CExprException(int lineNo, int columnNo, char *format, ...)
{
	char buffer[1024];
	va_list v;
	va_start(v,format);
	vsprintf(buffer,format,v);
	va_end(v);
	m_msg=strdup(buffer);
	m_lineNo=lineNo;
	m_columnNo=columnNo;
}
	
CExprException::~CExprException(void)
{
	delete m_msg;
}
	
char *CExprException::getMsg(void)
{
	return m_msg;
}
	
int CExprException::getLineNo(void)
{
	return m_lineNo;
}

int CExprException::getColumnNo(void)
{
	return m_columnNo;
}
	
void CExprException::display(FILE *output)
{
	fprintf(output,"%s at line %d colume %d\n",m_msg,m_lineNo,m_columnNo);
}
