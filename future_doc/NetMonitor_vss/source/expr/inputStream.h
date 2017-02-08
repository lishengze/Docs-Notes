/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file inputStream.h
///@brief	定义了输入流的抽象类及其常用实现的接口
///@history 
///20080321	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef INPUT_STREAM_H
#define INPUT_STREAM_H

#include "platform.h"
#include "RefObject.h"

/////////////////////////////////////////////////////////////////////////
///CInputStream定义了一个抽象的输入流的类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CInputStream,CRefObject)
{
private:
	///指出退回的那个字符，如果没有则设置为0，如果已经到文件尾，则设置为EOF
	int m_ungotChar;
	
	///当前的行号
	int m_lineNo;
	
	///当前的列号
	int m_columnNo;
public:
	///构造方法
	CInputStream(void);
	
	///获取下一个字符，在返回EOF后可以再次调用，不过总是继续返回EOF
	///@return	得到的下一个字符，如果已经到最后，则返回EOF，需要考虑ungetChar
	virtual int getNextChar(void);
	
	///退回一个字符
	///@param	ch	要退回的字符
	virtual void ungetChar(int ch);
	
	///获取下一个非空白字符
	///@return	得到的下一个非空白字符，如果已经到最后，则返回EOF
	virtual int getNextNonSpaceChar(void);

	///获取当前的行号
	virtual int getLineNo(void);

	///获取当前的列号
	virtual int getColumnNo(void);

	///判断一个字符是否为空白字符
	///@return	true表示是空白字符，false表示不是空白字符
	virtual bool isSpace(int ch);

protected:
	///析构方法
	virtual ~CInputStream(void);
	
	///获取下一个字符的实现，在返回EOF后，调用方应当保证不再调用
	///@return	得到的下一个字符，如果已经到最后，则返回EOF，不需要考虑ungetChar
	virtual int getNextCharImpl(void)=0;
};

/////////////////////////////////////////////////////////////////////////
///CStringInputStream定义了一个基于字符串的输入流的类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CStringInputStream,CInputStream)
{
private:
	///用于存放实际输入数据的字符串
	const char *m_string;

	///指向下一个返回的字符的指针
	const char *m_next;

	///用于指向最后一个字符的后一个字符，如果不使用这种模式结束，就设为NULL
	const char *m_term;

	///说明结束的字符，如果不用这种模式，就设为0;
	int m_termChar;

	///说明允许出现的结束字符的个数
	int m_termCharCount;

	///说明已经出现的结束字符个数
	int m_termCharOccur;

public:
	///构造方法，使用一个字符串作为输入，以'\0'作为结束
	///@param	string	使用的字符串
	CStringInputStream(const char *string);
	
	///构造方法，使用一个字符串作为输入，指定结束的位置
	///@param	string	使用的字符串
	///@param	term	指向结束位置的下一个字符
	CStringInputStream(const char *string, const char *term);
	
	///构造方法，使用一个字符串作为输入指定数量个结束字符后结束
	///@param	string	使用的字符串
	///@param	termCharCount	结束字符个数
	///@param	termChar	结束字符
	CStringInputStream(const char *string, int termCharCount, int termChar='\n');
	
	///获取下一个字符的指针，一般用在使用过后用于指明最后结束的位置。这里的结束位置定义如下：
	///		如果是到'\0'结束的，则指向'\0'后的一个字符
	///		如果是到指定的结束位置结束的，则就是term
	///		如果是到结束字符后结束的，则指向结束字符后的一个字符
	///@return	返回下一个字符的指针
	const char *getNextCharPoint(void);

protected:
	///析构方法
	virtual ~CStringInputStream(void);

	///获取下一个字符的实现
	///@return	得到的下一个字符，如果已经到最后，则返回EOF，不需要考虑ungetChar
	virtual int getNextCharImpl(void);
};

/////////////////////////////////////////////////////////////////////////
///CFileInputStream定义了一个基于文件的输入流的类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CFileInputStream,CInputStream)
{
private:
	///用于存放实际输入数据的文件
	FILE *m_input;

	///说明结束的字符，如果不用这种模式，就设为0;
	int m_termChar;

	///说明允许出现的结束字符的个数
	int m_termCharCount;

	///说明已经出现的结束字符个数
	int m_termCharOccur;

public:
	///构造方法，使用一个文件作为输入，以文件结束作为结束
	///@param	input	使用的文件
	CFileInputStream(FILE *input);
	
	///构造方法，使用一个文件作为输入，指定数量个结束字符后结束
	///@param	input	使用的文件
	///@param	termCharCount	结束字符个数
	///@param	termChar	结束字符
	CFileInputStream(FILE *input, int termCharCount, int termChar='\n');
	
protected:
	///析构方法
	virtual ~CFileInputStream(void);

	///获取下一个字符的实现
	///@return	得到的下一个字符，如果已经到最后，则返回EOF，不需要考虑ungetChar
	virtual int getNextCharImpl(void);
};

#endif
