/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file inputStream.cpp
///@brief	ʵ�����������ĳ����༰�䳣��ʵ��
///@history 
///20080321	���ض�		�������ļ�
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
		///�Ѿ�������
		result=EOF;
	}
	else if (m_ungotChar!=0)
	{
		///�ղ�����ungetChar��
		result=m_ungotChar;
		m_ungotChar=0;
	}
	else
	{
		///���ȡһ���ַ�
		result=getNextCharImpl();
		if (result==EOF)
		{
			///���½�����
			m_ungotChar=EOF;
		}
		else
		{
			///����ȡ�����ַ��ˣ�������Ҫ�����к�
			m_columnNo++;
			if (result=='\n')
			{
				///�ǻ��У��Ǿͻ���Ҫ�����к���
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
		///�Ѿ������˽���λ��
		return EOF;
	}
	int ch=*m_next++;
	if (ch=='\0')
	{
		///�Ѿ��������ַ�������
		return EOF;
	}
	if (ch==m_termChar)
	{
		///�����˽����ַ�
		m_termCharOccur++;
		if (m_termCharOccur>=m_termCharCount)
		{
			///�����ַ��ﵽ�˹涨��Ҫ��
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
		///�Ѿ��������ļ�����
		return EOF;
	}
	if (ch==m_termChar)
	{
		///�����˽����ַ�
		m_termCharOccur++;
		if (m_termCharOccur>=m_termCharCount)
		{
			///�����ַ��ﵽ�˹涨��Ҫ��
			return EOF;
		}
	}
	return ch;
}

CFileInputStream::~CFileInputStream(void)
{
}
