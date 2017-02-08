/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file inputToken.h
///@brief	定义了输入的token相关处理类的接口
///@history 
///20080321	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef INPUT_TOKEN_H
#define INPUT_TOKEN_H

#include "inputStream.h"
#include "CExprException.h"
#include "charSet.h"
#include "RefString.h"

#define TOKEN_UNKNOWN 0
#define TOKEN_CHARACTER 1
#define TOKEN_IDENTIFIER 2
#define TOKEN_KEYWORD 3
#define TOKEN_OPERATOR 4
#define TOKEN_INTEGER_CONSTANT 5
#define TOKEN_FLOAT_CONSTANT 6
#define TOKEN_STRING_CONSTANT 7
#define TOKEN_CHAR_CONSTANT 8
#define TOKEN_EOF 9

#ifndef MAX_IDENTIFIER_LEN
#define MAX_IDENTIFIER_LEN 256
#endif

#ifndef MAX_STRING_CONSTANT_LEN
#define MAX_STRING_CONSTANT_LEN 1024
#endif

#ifndef MAX_OPERATOR_LEN
#define MAX_OPERATOR_LEN 4
#endif

#ifndef MAX_NUMBER_LEN
#define MAX_NUMBER_LEN 40
#endif

/////////////////////////////////////////////////////////////////////////
///CInputToken定义了一个输入的token类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
class CInputToken
{
private:
	///token类型
	int m_tokenType;
	
	///保存的非字符串值
	union
	{
		char m_ch;
		int m_keyword;
		int m_operator;
		int m_integerConstant;
		double m_floatConstant;
		char m_charConstant;
	}	m_value;
	
	///保存的字符串值
	CRefStringPtr m_string;

public:
	///构造方法
	CInputToken(void)
	{
		m_tokenType=TOKEN_UNKNOWN;
	}
	
	///析构方法
	~CInputToken(void)
	{
	}

	///获取token类型
	///@return	token的类型，一定是TOKEN_形式的	
	int getTokenType(void)
	{
		return m_tokenType;
	}
	
	///清除token内容，即将其变为TOKEN_UNKNOWN
	void clear(void)
	{
		m_tokenType=TOKEN_UNKNOWN;
	}
	
	///设置字符token
	///@param	ch	要设置的字符
	void setCharacter(int ch)
	{
		m_tokenType=TOKEN_CHARACTER;
		m_value.m_ch=ch;
	}
	
	///设置标识符token
	///@param	identifier	要设置的标识符
	void setIdentifier(char *identifier)
	{
		m_tokenType=TOKEN_IDENTIFIER;
		m_string=identifier;
	}
	
	///设置关键词token
	///@param	keyword	要设置的关键字
	void setKeyword(int keyword)
	{
		m_tokenType=TOKEN_KEYWORD;
		m_value.m_keyword=keyword;
	}
	
	///设置运算符token
	///@param	theOperator	要设置的标识符
	void setOperator(int theOperator)
	{
		m_tokenType=TOKEN_OPERATOR;
		m_value.m_operator=theOperator;
	}
	
	///设置整数常数token
	///@param	integerConstant	要设置的整数
	void setIntegerConstant(int integerConstant)
	{
		m_tokenType=TOKEN_INTEGER_CONSTANT;
		m_value.m_integerConstant=integerConstant;
	}
	
	///设置浮点常数token
	///@param	floatConstant	要设置的浮点数
	void setFloatConstant(double floatConstant)
	{
		m_tokenType=TOKEN_FLOAT_CONSTANT;
		m_value.m_floatConstant=floatConstant;
	}
	
	///设置字符串常数token
	///@param	stringConstant	要设置的字符串
	void setStringConstant(char *stringConstant)
	{
		m_tokenType=TOKEN_STRING_CONSTANT;
		m_string=stringConstant;
	}
	
	///设置字符常数token
	///@param	charConstant	要设置的字符
	void setCharConstant(char charConstant)
	{
		m_tokenType=TOKEN_CHAR_CONSTANT;
		m_value.m_charConstant=charConstant;
	}

	///设置EOF token
	void setEOF(void)
	{
		m_tokenType=TOKEN_EOF;
	}
	
	///获取字符token的值
	///@return	得到的字符
	int getCharacter(void)
	{
		return m_value.m_ch;
	}
	
	///获取标识符token的值
	///@return	得到的标识符
	CRefStringPtr& getIdentifier(void)
	{
		return m_string;
	}
	
	///获取关键词token的值
	///@return	得到的关键词
	int getKeyword(void)
	{
		return m_value.m_keyword;
	}
	
	///获取运算符token的值
	///@return	得到的运算符
	int getOperator(void)
	{
		return m_value.m_operator;
	}
	
	///获取整数常数token的值
	///@return	得到的整数
	int getIntegerConstant(void)
	{
		return m_value.m_integerConstant;
	}
	
	///获得浮点数常数token的值
	///@return	得到的浮点数
	double  getFloatConstant(void)
	{
		return m_value.m_floatConstant;
	}
	
	///获得字符串常数token的值
	///@return	得到的字符串
	CRefStringPtr& getStringConstant(void)
	{
		return m_string;
	}
	
	///获得字符常数token的值
	///@return	得到的字符
	char getCharConstant(void)
	{
		return m_value.m_charConstant;
	}

	///是否为EOF token
	///@return	true表示是EOF token，否则返回false
	bool isEOF(void)
	{
		return (m_tokenType==TOKEN_EOF);
	}
	
	///显示此token
	///@param	output	要输出到的文件
	void display(FILE *output=stdout);
};

/////////////////////////////////////////////////////////////////////////
///CInputTokenMaker定义了一个输入token产生类的基类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CInputTokenMaker,CRefObject)
{
protected:
	///析构方法
	virtual ~CInputTokenMaker(void)
	{
	}
	
public:
	///建立一个输入token，会读取pStream，并将下一个读取的字符置于本token后的第一个字符
	///@param	pStream	使用的输入流
	///@param	ch	已经读出的第一个字符
	///@param	resultToken	用于放置结果的输入token
	///@return	true表示成功地读取了一个token，false表示不是本类负责产生的token（此时不会影响pStream）
	///@exception	如果是本类负责产生，而又无法正确产生token的情况下将抛出CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInputTokenGenerator定义了一个根据一组token产生类的组合产生的token产生类
///@author	王肇东
///@version	1.0,20090326
/////////////////////////////////////////////////////////////////////////
class CInputTokenGenerator
{
	///本组所有的token产生类
	vector<CInputTokenMakerPtr> m_makerList;
	
	///使用的输入流
	CInputStreamPtr m_pStream;
public:
	///构造方法
	///@param	pStream	使用的输入流
	CInputTokenGenerator(const CInputStreamPtr &pStream);
	
	///析构方法
	~CInputTokenGenerator(void);
	
	//在本组内加入一个新的token产生类
	void addInputTokenMaker(const CInputTokenMakerPtr &thisMaker);
	
	///获取下一个token
	///@param	resultToken	用于放置结果的输入token
	///@return	true表示成功地读取了一个token，false表示已经到了stream的结尾
	///@exception	如果有词法错误将抛出CParseException
	bool getNextToken(CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CIdentifierInputTokenMaker定义了一个标识符输入token产生类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CIdentifierInputTokenMaker,CInputTokenMaker)
{
protected:
	///说明标识符的首字符集合和继续字符集合
	CCharSetPtr m_firstCharSet, m_continueCharSet;
	
	///用于存放结果的空间
	char m_result[MAX_IDENTIFIER_LEN+1];
	
	///析构方法
	virtual ~CIdentifierInputTokenMaker(void)
	{
	}
	
	///设置结果
	///@param	resultToken	用于放置结果的输入token
	virtual void setResult(CInputToken &resultToken);
public:
	///构造方法
	///@param	firstCharSet	使用的首字符集合，缺省值下使用CCharSetForLetterUnderLine
	///@param	continueCharSet	使用的继续字符集合，缺省值下使用CCharSetForLetterDigitUnderLine
	CIdentifierInputTokenMaker(CCharSetPtr firstCharSet=NULL,CCharSetPtr continueCharSet=NULL);

	///建立一个输入token，会读取pStream，并将下一个读取的字符置于本token后的第一个字符
	///@param	pStream	使用的输入流
	///@param	ch	已经读出的第一个字符
	///@param	resultToken	用于放置结果的输入token
	///@return	true表示成功地读取了一个token，false表示不是本类负责产生的token（此时不会影响pStream）
	///@exception	如果是本类负责产生，而又无法正确产生token的情况下将抛出CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CIKInputTokenMaker定义了一个标识符和关键词的输入token产生类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CIKInputTokenMaker,CIdentifierInputTokenMaker)
{
protected:
	///用于放置关键词的映射表
	map<string,int> m_keywordMap;
	
	typedef pair<string,int> TKeywordPair;
	
	///析构方法
	virtual ~CIKInputTokenMaker(void)
	{
	}
	
	///设置结果
	///@param	resultToken	用于放置结果的输入token
	virtual void setResult(CInputToken &resultToken);
public:
	///构造方法
	///@param	keywords	所有关键词的清单，最后一个后面需要有一个NULL
	///@param	firstCharSet	使用的首字符集合，缺省值下使用CCharSetForLetterUnderLine
	///@param	continueCharSet	使用的继续字符集合，缺省值下使用CCharSetForLetterDigitUnderLine
	CIKInputTokenMaker(const char *keywords[],CCharSetPtr firstCharSet=NULL,CCharSetPtr continueCharSet=NULL);
};

/////////////////////////////////////////////////////////////////////////
///COperatorInputTokenMaker定义了一个运算符输入token产生类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(COperatorInputTokenMaker,CInputTokenMaker)
{
protected:
	///用于放置运算符关键词的映射表
	map<string,int> m_operatorMap;
	
	typedef pair<string,int> TOperatorPair;
	
	///析构方法
	virtual ~COperatorInputTokenMaker(void)
	{
	}
	
	///是否合法的运算符前段
	///@param	buffer	要判断的字符串
	///@param	operatorId	当是一个完整的运算符时，返回该运算符的编号，否则无意义
	///@param	isOperator	当是一个完整的运算符时，返回true，否则返回false
	///@param	canBeContinued	当增加字符可以形成完整的运算符时，返回true，否则返回false
	///@return	当是一个运算符的前段（包含是完整运算符的情况）时，返回true，否则返回false
	bool isValidSegment(char *buffer, int &operatorId, bool &isOperator, bool &canBeContinued);
	
	///获取运算符编号
	///@param	pStream	使用的输入流
	///@param	ch	已经读出的第一个字符
	///@return	如果成功获得，则返回运算符编号，否则返回-1
	int getOperatorId(CInputStreamPtr pStream, int ch);
public:
	///构造方法
	///@param	operators	所有元算符的清单，最有一个后面需要有一个NULL
	COperatorInputTokenMaker(const char *operators[]);
	
	///建立一个输入token，会读取pStream，并将下一个读取的字符置于本token后的第一个字符
	///@param	pStream	使用的输入流
	///@param	ch	已经读出的第一个字符
	///@param	resultToken	用于放置结果的输入token
	///@return	true表示成功地读取了一个token，false表示不是本类负责产生的token（此时不会影响pStream）
	///@exception	如果是本类负责产生，而又无法正确产生token的情况下将抛出CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);	
};

/////////////////////////////////////////////////////////////////////////
///CIntegerConstantInputTokenMaker定义了一个整数常数的输入token产生类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CIntegerConstantInputTokenMaker,CInputTokenMaker)
{
protected:
	///说明标识符的首字符集合和继续字符集合
	CCharSetPtr m_firstCharSet, m_continueCharSet;
	
	///说明是否只支持10进制
	bool m_supportOnlyDec;
	
	///用于存放结果的空间
	char m_result[MAX_NUMBER_LEN+1];
	
	///析构方法
	virtual ~CIntegerConstantInputTokenMaker(void)
	{
	}
	
	///设置结果
	///@param	pStream	使用的输入流
	///@param	resultToken	用于放置结果的输入token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);
public:
	///构造方法
	///@param	supportOnlyDec	是否只支持10进制
	///@param	firstCharSet	使用的首字符集合，缺省值下使用CCharSetForDigit
	///@param	continueCharSet	使用的继续字符集合，缺省值下使用CCharSetForDigit或者CCharSetForDigitX（在非只支持10进制下）
	CIntegerConstantInputTokenMaker(bool supportOnlyDec=true, CCharSetPtr firstCharSet=NULL,CCharSetPtr continueCharSet=NULL);

	///建立一个输入token，会读取pStream，并将下一个读取的字符置于本token后的第一个字符
	///@param	pStream	使用的输入流
	///@param	ch	已经读出的第一个字符
	///@param	resultToken	用于放置结果的输入token
	///@return	true表示成功地读取了一个token，false表示不是本类负责产生的token（此时不会影响pStream）
	///@exception	如果是本类负责产生，而又无法正确产生token的情况下将抛出CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CNumberConstantInputTokenMaker定义了一个整数和浮点数常数的输入token产生类
///@author	王肇东
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CNumberConstantInputTokenMaker,CIntegerConstantInputTokenMaker)
{
protected:
	///析构方法
	virtual ~CNumberConstantInputTokenMaker(void)
	{
	}
	
	///设置结果
	///@param	pStream	使用的输入流
	///@param	resultToken	用于放置结果的输入token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);
public:
	///构造方法
	///@param	supportOnlyDecInt	是否只支持10进制整数
	CNumberConstantInputTokenMaker(bool supportOnlyDecInt=false);
};

#define C_STYLE_STRING 1
#define CSV_STYLE_STRING 2
#define XML_STYLE_STRING 3

/////////////////////////////////////////////////////////////////////////
///CStringConstantInputTokenMaker定义了一个字符串常数的输入token产生类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CStringConstantInputTokenMaker,CInputTokenMaker)
{
protected:
	///字符串的转义风格
	int m_convertStyle;
	
	///分割字符
	char *m_seperateChar;
	
	///本次的开始字符，'\0'表示无开始字符
	char m_leadingChar;

	///用于存放结果的空间
	char m_result[MAX_STRING_CONSTANT_LEN+1];
	
	///析构方法
	virtual ~CStringConstantInputTokenMaker(void)
	{
	}
	
	///设置结果
	///@param	pStream	使用的输入流
	///@param	resultToken	用于放置结果的输入token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);

public:
	///构造方法
	///@param	convertStyle	字符串的转义风格，必须为C_STYLE_STRING、CSV_STYLE_STRING或者XML_STYLE_STRING，其中XML_STYLE_STRING尚未实现
	///@param	seperateChar	所有允许的分隔字符
	///@description	在C_STYLE_STRING的情况下，会进行C语言的反斜杠转义处理
	///		在CSV_STYLE_STRING的情况下，会对重复开始字符进行转义，
	CStringConstantInputTokenMaker(int convertStyle=C_STYLE_STRING, char *seperateChar="\"\'");

	///建立一个输入token，会读取pStream，并将下一个读取的字符置于本token后的第一个字符
	///@param	pStream	使用的输入流
	///@param	ch	已经读出的第一个字符
	///@param	resultToken	用于放置结果的输入token
	///@return	true表示成功地读取了一个token，false表示不是本类负责产生的token（此时不会影响pStream）
	///@exception	如果是本类负责产生，而又无法正确产生token的情况下将抛出CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CStringCharConstantInputTokenMaker定义了一个字符串常数的输入token产生类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CStringCharConstantInputTokenMaker,CStringConstantInputTokenMaker)
{
protected:
	///字符常数的分割符
	char *m_charSeperateChar;

	///析构方法
	virtual ~CStringCharConstantInputTokenMaker(void)
	{
	}
	
	///设置结果
	///@param	pStream	使用的输入流
	///@param	resultToken	用于放置结果的输入token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);

public:
	///构造方法
	///@param	convertStyle	字符串的转义风格，必须为C_STYLE_STRING、CSV_STYLE_STRING或者XML_STYLE_STRING，其中XML_STYLE_STRING尚未实现
	///@param	seperateChar	所有允许的分隔字符
	///@param	charSeperateChar	所有允许的字符常数的分隔字符
	///@description	在C_STYLE_STRING的情况下，会进行C语言的反斜杠转义处理
	///		在CSV_STYLE_STRING的情况下，会对重复开始字符进行转义，
	CStringCharConstantInputTokenMaker(int convertStyle=C_STYLE_STRING, char *seperateChar="\"\'",char *charSeperateChar="\'");
};

/////////////////////////////////////////////////////////////////////////
///CCharacterInputTokenMaker定义了一个字符的输入token产生类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharacterInputTokenMaker,CInputTokenMaker)
{
protected:
	///所有允许的字符集合
	CCharSetPtr m_allowCharacterSet;

	///析构方法
	virtual ~CCharacterInputTokenMaker(void)
	{
	}
	
	///设置结果
	///@param	pStream	使用的输入流
	///@param	ch	要设置的字符
	///@param	resultToken	用于放置结果的输入token
	virtual void setResult(CInputStreamPtr pStream, char ch, CInputToken &resultToken);

public:
	///构造方法
	///@param	allowCharacterSet	所有允许的字符集合，缺省为所有字符
	CCharacterInputTokenMaker(CCharSetPtr allowCharacterSet=NULL);

	///建立一个输入token，会读取pStream，并将下一个读取的字符置于本token后的第一个字符
	///@param	pStream	使用的输入流
	///@param	ch	已经读出的第一个字符
	///@param	resultToken	用于放置结果的输入token
	///@return	true表示成功地读取了一个token，false表示不是本类负责产生的token（此时不会影响pStream）
	///@exception	如果是本类负责产生，而又无法正确产生token的情况下将抛出CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};
#endif
