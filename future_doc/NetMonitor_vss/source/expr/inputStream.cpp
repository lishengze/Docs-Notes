/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file inputStream.cpp
///@brief	实现了输入流的抽象类及其常用实现
///@history 
///20080321	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "inputStream.h"

CInputStream::CInputStream(void)
{
	m_ungotChar=0;
	m_lineNo=1;
	m_columnNo=0;
}
	
CInputStream::~CInputStream(void)
{
}
	
int CInputStream::getNextChar(void)
{
	int result;
	if (m_ungotChar==EOF)
	{
		///已经结束了
		result=EOF;
	}
	else if (m_ungotChar!=0)
	{
		///刚才曾经ungetChar过
		result=m_ungotChar;
		m_ungotChar=0;
	}
	else
	{
		///真的取一个字符
		result=getNextCharImpl();
		if (result==EOF)
		{
			///这下结束了
			m_ungotChar=EOF;
		}
		else
		{
			///就用取到的字符了，不过需要调整列号
			m_columnNo++;
			if (result=='\n')
			{
				///是换行，那就还需要调整行号了
				m_lineNo++;
				m_columnNo=0;
			}
		}
	}
	return result;
}
	
void CInputStream::ungetChar(int ch)
{
	m_ungotChar=ch;
}
	
int CInputStream::getNextNonSpaceChar(void)
{
	int ch;
	while ((ch=getNextChar())!=EOF)
	{
		if (!isSpace(ch))
		{
			break;
		}
	}
	return ch;
}

int CInputStream::getLineNo(void)
{
	return m_lineNo;
}

int CInputStream::getColumnNo(void)
{
	return m_columnNo;
}

bool CInputStream::isSpace(int ch)
{
	return isspace(ch)!=0;
}

CStringInputStream::CStringInputStream(const char *string)
{
	m_string=string;
	m_term=NULL;
	m_termChar=0;

	m_next=m_string;
}
	
CStringInputStream::CStringInputStream(const char *string, const char *term)
{
	m_string=string;
	m_term=term;
	m_termChar=0;

	m_next=m_string;
}
	
CStringInputStream::CStringInputStream(const char *string, int termCharCount, int termChar)
{
	m_string=string;
	m_term=NULL;
	m_termChar=termChar;
	m_termCharCount=termCharCount;
	m_termCharOccur=0;
	
	m_next=m_string;
}

const char *CStringInputStream::getNextCharPoint(void)
{
	return m_next;
}

int CStringInputStream::getNextCharImpl(void)
{
	if ((m_term!=NULL)&&(m_next>=m_term))
	{
		///已经超出了结束位置
		return EOF;
	}
	int ch=*m_next++;
	if (ch=='\0')
	{
		///已经碰到了字符串结束
		return EOF;
	}
	if (ch==m_termChar)
	{
		///碰到了结束字符
		m_termCharOccur++;
		if (m_termCharOccur>=m_termCharCount)
		{
			///结束字符达到了规定的要求
			return EOF;
		}
	}
	return ch;
}

CStringInputStream::~CStringInputStream(void)
{
}

CFileInputStream::CFileInputStream(FILE *input)
{
	m_input=input;
	m_termChar=0;
}
	
CFileInputStream::CFileInputStream(FILE *input, int termCharCount, int termChar)
{
	m_input=input;
	m_termChar=termChar;
	m_termCharCount=termCharCount;
	m_termCharOccur=0;
}
	
int CFileInputStream::getNextCharImpl(void)
{
	int ch=fgetc(m_input);
	if (ch==EOF)
	{
		///已经碰到了文件结束
		return EOF;
	}
	if (ch==m_termChar)
	{
		///碰到了结束字符
		m_termCharOccur++;
		if (m_termCharOccur>=m_termCharCount)
		{
			///结束字符达到了规定的要求
			return EOF;
		}
	}
	return ch;
}

CFileInputStream::~CFileInputStream(void)
{
}
