/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file charSet.h
///@brief	�������ַ�������ص���
///@history 
///20080326	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CHAR_SET_H
#define CHAR_SET_H

#include "platform.h"
#include "RefObject.h"

/////////////////////////////////////////////////////////////////////////
///CCharSet������һ��˵���ַ����ϵĳ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSet,CRefObject)
{
protected:
	///��������
	virtual ~CCharSet(void)
	{
	}

public:
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCharSetInString������һ�����ַ���˵���ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetInString,CCharSet)
{
private:
	///�����ж��õ��ַ���
	char *m_string;

	///��������
	virtual ~CCharSetInString(void)
	{
		delete m_string;
	}

public:
	///���췽��
	///@param	string	�����ж��Ƿ����ڵ��ַ���
	CCharSetInString(const char *string);
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetNotInString������һ�����ַ���˵��������������ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetNotInString,CCharSet)
{
private:
	///�����ж��õ��ַ���
	char *m_string;

	///��������
	virtual ~CCharSetNotInString(void)
	{
		delete m_string;
	}

public:
	///���췽��
	///@param	string	�����ж��Ƿ����ڵ��ַ���
	CCharSetNotInString(const char *string);
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigit������һ�������ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigit,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForDigit(void)
	{
	}

public:
	///���췽��
	CCharSetForDigit(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigitX������һ�������ַ�����ĸX�ļ���
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigitX,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForDigitX(void)
	{
	}

public:
	///���췽��
	CCharSetForDigitX(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigitDot������һ�����ֺ�С�����ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigitDot,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForDigitDot(void)
	{
	}

public:
	///���췽��
	CCharSetForDigitDot(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigitDotE������һ�����֡�С�������ĸE���ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigitDotE,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForDigitDotE(void)
	{
	}

public:
	///���췽��
	CCharSetForDigitDotE(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetter������һ����ĸ���ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetter,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForLetter(void)
	{
	}

public:
	///���췽��
	CCharSetForLetter(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterUnderLine������һ����ĸ���»��ߵ��ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterUnderLine,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForLetterUnderLine(void)
	{
	}
public:
	///���췽��
	CCharSetForLetterUnderLine(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterDigitUnderLine������һ����ĸ���ֺ��»��ߵ��ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterDigitUnderLine,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForLetterDigitUnderLine(void)
	{
	}

public:
	///���췽��
	CCharSetForLetterDigitUnderLine(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterDigitDot������һ����ĸ���ֺ�С������ַ�����
///@author	���ض�
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterDigitDot,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForLetterDigitDot(void)
	{
	}

public:
	///���췽��
	CCharSetForLetterDigitDot(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterDigitDotUnderLineColon������һ����ĸ����
/// ��С���㡢�»��ߡ�ð�ŵ��ַ�����
///@author	�ܽ���
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterDigitDotUnderLineColon,CCharSet)
{
private:
	///��������
	virtual ~CCharSetForLetterDigitDotUnderLineColon(void)
	{
	}

public:
	///���췽��
	CCharSetForLetterDigitDotUnderLineColon(void)
	{
	}
	
	///�ж��Ƿ����ڴ��ַ�����
	///@param	ch	Ҫ�жϵ��ַ�
	///@return	ture��ʾ�ǣ�false��ʾ����
	virtual bool isIn(int ch);
};

#endif
