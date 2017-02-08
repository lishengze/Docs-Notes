/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file inputStream.h
///@brief	�������������ĳ����༰�䳣��ʵ�ֵĽӿ�
///@history 
///20080321	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef INPUT_STREAM_H
#define INPUT_STREAM_H

#include "platform.h"
#include "RefObject.h"

/////////////////////////////////////////////////////////////////////////
///CInputStream������һ�����������������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CInputStream,CRefObject)
{
private:
	///ָ���˻ص��Ǹ��ַ������û��������Ϊ0������Ѿ����ļ�β��������ΪEOF
	int m_ungotChar;
	
	///��ǰ���к�
	int m_lineNo;
	
	///��ǰ���к�
	int m_columnNo;
public:
	///���췽��
	CInputStream(void);
	
	///��ȡ��һ���ַ����ڷ���EOF������ٴε��ã��������Ǽ�������EOF
	///@return	�õ�����һ���ַ�������Ѿ�������򷵻�EOF����Ҫ����ungetChar
	virtual int getNextChar(void);
	
	///�˻�һ���ַ�
	///@param	ch	Ҫ�˻ص��ַ�
	virtual void ungetChar(int ch);
	
	///��ȡ��һ���ǿհ��ַ�
	///@return	�õ�����һ���ǿհ��ַ�������Ѿ�������򷵻�EOF
	virtual int getNextNonSpaceChar(void);

	///��ȡ��ǰ���к�
	virtual int getLineNo(void);

	///��ȡ��ǰ���к�
	virtual int getColumnNo(void);

	///�ж�һ���ַ��Ƿ�Ϊ�հ��ַ�
	///@return	true��ʾ�ǿհ��ַ���false��ʾ���ǿհ��ַ�
	virtual bool isSpace(int ch);

protected:
	///��������
	virtual ~CInputStream(void);
	
	///��ȡ��һ���ַ���ʵ�֣��ڷ���EOF�󣬵��÷�Ӧ����֤���ٵ���
	///@return	�õ�����һ���ַ�������Ѿ�������򷵻�EOF������Ҫ����ungetChar
	virtual int getNextCharImpl(void)=0;
};

/////////////////////////////////////////////////////////////////////////
///CStringInputStream������һ�������ַ���������������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CStringInputStream,CInputStream)
{
private:
	///���ڴ��ʵ���������ݵ��ַ���
	const char *m_string;

	///ָ����һ�����ص��ַ���ָ��
	const char *m_next;

	///����ָ�����һ���ַ��ĺ�һ���ַ��������ʹ������ģʽ����������ΪNULL
	const char *m_term;

	///˵���������ַ��������������ģʽ������Ϊ0;
	int m_termChar;

	///˵��������ֵĽ����ַ��ĸ���
	int m_termCharCount;

	///˵���Ѿ����ֵĽ����ַ�����
	int m_termCharOccur;

public:
	///���췽����ʹ��һ���ַ�����Ϊ���룬��'\0'��Ϊ����
	///@param	string	ʹ�õ��ַ���
	CStringInputStream(const char *string);
	
	///���췽����ʹ��һ���ַ�����Ϊ���룬ָ��������λ��
	///@param	string	ʹ�õ��ַ���
	///@param	term	ָ�����λ�õ���һ���ַ�
	CStringInputStream(const char *string, const char *term);
	
	///���췽����ʹ��һ���ַ�����Ϊ����ָ�������������ַ������
	///@param	string	ʹ�õ��ַ���
	///@param	termCharCount	�����ַ�����
	///@param	termChar	�����ַ�
	CStringInputStream(const char *string, int termCharCount, int termChar='\n');
	
	///��ȡ��һ���ַ���ָ�룬һ������ʹ�ù�������ָ����������λ�á�����Ľ���λ�ö������£�
	///		����ǵ�'\0'�����ģ���ָ��'\0'���һ���ַ�
	///		����ǵ�ָ���Ľ���λ�ý����ģ������term
	///		����ǵ������ַ�������ģ���ָ������ַ����һ���ַ�
	///@return	������һ���ַ���ָ��
	const char *getNextCharPoint(void);

protected:
	///��������
	virtual ~CStringInputStream(void);

	///��ȡ��һ���ַ���ʵ��
	///@return	�õ�����һ���ַ�������Ѿ�������򷵻�EOF������Ҫ����ungetChar
	virtual int getNextCharImpl(void);
};

/////////////////////////////////////////////////////////////////////////
///CFileInputStream������һ�������ļ�������������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CFileInputStream,CInputStream)
{
private:
	///���ڴ��ʵ���������ݵ��ļ�
	FILE *m_input;

	///˵���������ַ��������������ģʽ������Ϊ0;
	int m_termChar;

	///˵��������ֵĽ����ַ��ĸ���
	int m_termCharCount;

	///˵���Ѿ����ֵĽ����ַ�����
	int m_termCharOccur;

public:
	///���췽����ʹ��һ���ļ���Ϊ���룬���ļ�������Ϊ����
	///@param	input	ʹ�õ��ļ�
	CFileInputStream(FILE *input);
	
	///���췽����ʹ��һ���ļ���Ϊ���룬ָ�������������ַ������
	///@param	input	ʹ�õ��ļ�
	///@param	termCharCount	�����ַ�����
	///@param	termChar	�����ַ�
	CFileInputStream(FILE *input, int termCharCount, int termChar='\n');
	
protected:
	///��������
	virtual ~CFileInputStream(void);

	///��ȡ��һ���ַ���ʵ��
	///@return	�õ�����һ���ַ�������Ѿ�������򷵻�EOF������Ҫ����ungetChar
	virtual int getNextCharImpl(void);
};

#endif
