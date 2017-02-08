/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file charSet.cpp
///@brief	ʵ�����ַ�������ص���
///@history 
///20080326	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "charSet.h"

CCharSetInString::CCharSetInString(const char *string)
{
	m_string=strdup(string);
}
	
bool CCharSetInString::isIn(int ch)
{
	return strchr(m_string,ch)!=NULL;
}

CCharSetNotInString::CCharSetNotInString(const char *string)
{
	m_string=strdup(string);
}
	
bool CCharSetNotInString::isIn(int ch)
{
	return ((ch!=EOF)&&(strchr(m_string,ch)==NULL));
}

bool CCharSetForDigit::isIn(int ch)
{
	return isdigit(ch)!=0;
}

bool CCharSetForDigitX::isIn(int ch)
{
	return (isxdigit(ch)!=0)||(ch=='x')||(ch=='X');
}

bool CCharSetForDigitDot::isIn(int ch)
{
	return (isdigit(ch)!=0)||(ch=='.');
}

bool CCharSetForDigitDotE::isIn(int ch)
{
	return (isdigit(ch)!=0)||(ch=='.')||(ch=='E')||(ch=='e');
}

bool CCharSetForLetter::isIn(int ch)
{
	return isalpha(ch)!=0;
}

bool CCharSetForLetterUnderLine::isIn(int ch)
{
	return (isalpha(ch)!=0)||(ch=='_');
}

bool CCharSetForLetterDigitUnderLine::isIn(int ch)
{
	return (isalnum(ch)!=0)||(ch=='_');
}

bool CCharSetForLetterDigitDot::isIn(int ch)
{
	return (isalnum(ch)!=0)||(ch=='.');
}

bool CCharSetForLetterDigitDotUnderLineColon::isIn(int ch)
{
	return (isalnum(ch)!=0)||(ch=='.')||(ch=='_')||(ch==':');
}
