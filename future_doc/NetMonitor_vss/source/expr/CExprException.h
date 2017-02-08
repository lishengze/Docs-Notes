/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file CExprException.h
///@brief	定义了类CExprException
///@history 
///20080322	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef C_EXPR_EXCEPTION_H
#define C_EXPR_EXCEPTION_H

#include "platform.h"

/////////////////////////////////////////////////////////////////////////
///CParseException定义了一个语法输入的异常
///@author	王肇东
///@version	1.0,20090322
/////////////////////////////////////////////////////////////////////////
class  CExprException
{
public:
	///构造函数，用于创建该异常对象
	///@param	msg	本异常的错误信息
	///@param	lineNo	发生错误的行号
	///@param	columnNo	发生错误的列号
	CExprException(char *msg, int lineNo, int columnNo);
	
	///构造函数，用于创建该异常对象
	///@param	lineNo	发生错误的行号
	///@param	columnNo	发生错误的列号
	///@param	format	本异常的错误格式，按照printf格式要求
	///@param	...	按照printf要求的值
	CExprException(int lineNo, int columnNo, char *format, ...);

	///析构函数
	~CExprException(void);
	
	///获取错误信息
	///@return	错误信息
	char *getMsg(void);
	
	///获取发生错误的行号
	///@return 行号
	int getLineNo(void);

	///获取发生错误的列号
	///@return 列号
	int getColumnNo(void);
	
	///将此错误信息进行输出
	///@param	output	要输出的文件
	void display(FILE *output=stdout);

private:
	///保存的错误信息
	char *m_msg;
	
	///保存的行号
	int m_lineNo;

	///保存的列号
	int m_columnNo;
};

#endif
