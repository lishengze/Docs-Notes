/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file charSet.h
///@brief	定义了字符集合相关的类
///@history 
///20080326	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef CHAR_SET_H
#define CHAR_SET_H

#include "platform.h"
#include "RefObject.h"

/////////////////////////////////////////////////////////////////////////
///CCharSet定义了一个说明字符集合的抽象类
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSet,CRefObject)
{
protected:
	///析构方法
	virtual ~CCharSet(void)
	{
	}

public:
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch)=0;
};

/////////////////////////////////////////////////////////////////////////
///CCharSetInString定义了一个用字符串说明字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetInString,CCharSet)
{
private:
	///放置判断用的字符串
	char *m_string;

	///析构方法
	virtual ~CCharSetInString(void)
	{
		delete m_string;
	}

public:
	///构造方法
	///@param	string	用于判断是否属于的字符串
	CCharSetInString(const char *string);
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetNotInString定义了一个用字符串说明不允许的其他字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetNotInString,CCharSet)
{
private:
	///放置判断用的字符串
	char *m_string;

	///析构方法
	virtual ~CCharSetNotInString(void)
	{
		delete m_string;
	}

public:
	///构造方法
	///@param	string	用于判断是否属于的字符串
	CCharSetNotInString(const char *string);
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigit定义了一个数字字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigit,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForDigit(void)
	{
	}

public:
	///构造方法
	CCharSetForDigit(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigitX定义了一个数字字符和字母X的集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigitX,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForDigitX(void)
	{
	}

public:
	///构造方法
	CCharSetForDigitX(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigitDot定义了一个数字和小数点字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigitDot,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForDigitDot(void)
	{
	}

public:
	///构造方法
	CCharSetForDigitDot(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForDigitDotE定义了一个数字、小数点和字母E的字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForDigitDotE,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForDigitDotE(void)
	{
	}

public:
	///构造方法
	CCharSetForDigitDotE(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetter定义了一个字母的字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetter,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForLetter(void)
	{
	}

public:
	///构造方法
	CCharSetForLetter(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterUnderLine定义了一个字母和下划线的字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterUnderLine,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForLetterUnderLine(void)
	{
	}
public:
	///构造方法
	CCharSetForLetterUnderLine(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterDigitUnderLine定义了一个字母数字和下划线的字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterDigitUnderLine,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForLetterDigitUnderLine(void)
	{
	}

public:
	///构造方法
	CCharSetForLetterDigitUnderLine(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterDigitDot定义了一个字母数字和小数点的字符集合
///@author	王肇东
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterDigitDot,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForLetterDigitDot(void)
	{
	}

public:
	///构造方法
	CCharSetForLetterDigitDot(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

/////////////////////////////////////////////////////////////////////////
///CCharSetForLetterDigitDotUnderLineColon定义了一个字母数字
/// 和小数点、下划线、冒号的字符集合
///@author	周建军
///@version	1.0,2009036
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharSetForLetterDigitDotUnderLineColon,CCharSet)
{
private:
	///析构方法
	virtual ~CCharSetForLetterDigitDotUnderLineColon(void)
	{
	}

public:
	///构造方法
	CCharSetForLetterDigitDotUnderLineColon(void)
	{
	}
	
	///判断是否属于此字符集合
	///@param	ch	要判断的字符
	///@return	ture表示是，false表示不是
	virtual bool isIn(int ch);
};

#endif
