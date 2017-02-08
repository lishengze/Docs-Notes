/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file inputToken.h
///@brief	�����������token��ش�����Ľӿ�
///@history 
///20080321	���ض�		�������ļ�
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
///CInputToken������һ�������token��
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
class CInputToken
{
private:
	///token����
	int m_tokenType;
	
	///����ķ��ַ���ֵ
	union
	{
		char m_ch;
		int m_keyword;
		int m_operator;
		int m_integerConstant;
		double m_floatConstant;
		char m_charConstant;
	}	m_value;
	
	///������ַ���ֵ
	CRefStringPtr m_string;

public:
	///���췽��
	CInputToken(void)
	{
		m_tokenType=TOKEN_UNKNOWN;
	}
	
	///��������
	~CInputToken(void)
	{
	}

	///��ȡtoken����
	///@return	token�����ͣ�һ����TOKEN_��ʽ��	
	int getTokenType(void)
	{
		return m_tokenType;
	}
	
	///���token���ݣ��������ΪTOKEN_UNKNOWN
	void clear(void)
	{
		m_tokenType=TOKEN_UNKNOWN;
	}
	
	///�����ַ�token
	///@param	ch	Ҫ���õ��ַ�
	void setCharacter(int ch)
	{
		m_tokenType=TOKEN_CHARACTER;
		m_value.m_ch=ch;
	}
	
	///���ñ�ʶ��token
	///@param	identifier	Ҫ���õı�ʶ��
	void setIdentifier(char *identifier)
	{
		m_tokenType=TOKEN_IDENTIFIER;
		m_string=identifier;
	}
	
	///���ùؼ���token
	///@param	keyword	Ҫ���õĹؼ���
	void setKeyword(int keyword)
	{
		m_tokenType=TOKEN_KEYWORD;
		m_value.m_keyword=keyword;
	}
	
	///���������token
	///@param	theOperator	Ҫ���õı�ʶ��
	void setOperator(int theOperator)
	{
		m_tokenType=TOKEN_OPERATOR;
		m_value.m_operator=theOperator;
	}
	
	///������������token
	///@param	integerConstant	Ҫ���õ�����
	void setIntegerConstant(int integerConstant)
	{
		m_tokenType=TOKEN_INTEGER_CONSTANT;
		m_value.m_integerConstant=integerConstant;
	}
	
	///���ø��㳣��token
	///@param	floatConstant	Ҫ���õĸ�����
	void setFloatConstant(double floatConstant)
	{
		m_tokenType=TOKEN_FLOAT_CONSTANT;
		m_value.m_floatConstant=floatConstant;
	}
	
	///�����ַ�������token
	///@param	stringConstant	Ҫ���õ��ַ���
	void setStringConstant(char *stringConstant)
	{
		m_tokenType=TOKEN_STRING_CONSTANT;
		m_string=stringConstant;
	}
	
	///�����ַ�����token
	///@param	charConstant	Ҫ���õ��ַ�
	void setCharConstant(char charConstant)
	{
		m_tokenType=TOKEN_CHAR_CONSTANT;
		m_value.m_charConstant=charConstant;
	}

	///����EOF token
	void setEOF(void)
	{
		m_tokenType=TOKEN_EOF;
	}
	
	///��ȡ�ַ�token��ֵ
	///@return	�õ����ַ�
	int getCharacter(void)
	{
		return m_value.m_ch;
	}
	
	///��ȡ��ʶ��token��ֵ
	///@return	�õ��ı�ʶ��
	CRefStringPtr& getIdentifier(void)
	{
		return m_string;
	}
	
	///��ȡ�ؼ���token��ֵ
	///@return	�õ��Ĺؼ���
	int getKeyword(void)
	{
		return m_value.m_keyword;
	}
	
	///��ȡ�����token��ֵ
	///@return	�õ��������
	int getOperator(void)
	{
		return m_value.m_operator;
	}
	
	///��ȡ��������token��ֵ
	///@return	�õ�������
	int getIntegerConstant(void)
	{
		return m_value.m_integerConstant;
	}
	
	///��ø���������token��ֵ
	///@return	�õ��ĸ�����
	double  getFloatConstant(void)
	{
		return m_value.m_floatConstant;
	}
	
	///����ַ�������token��ֵ
	///@return	�õ����ַ���
	CRefStringPtr& getStringConstant(void)
	{
		return m_string;
	}
	
	///����ַ�����token��ֵ
	///@return	�õ����ַ�
	char getCharConstant(void)
	{
		return m_value.m_charConstant;
	}

	///�Ƿ�ΪEOF token
	///@return	true��ʾ��EOF token�����򷵻�false
	bool isEOF(void)
	{
		return (m_tokenType==TOKEN_EOF);
	}
	
	///��ʾ��token
	///@param	output	Ҫ��������ļ�
	void display(FILE *output=stdout);
};

/////////////////////////////////////////////////////////////////////////
///CInputTokenMaker������һ������token������Ļ���
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CInputTokenMaker,CRefObject)
{
protected:
	///��������
	virtual ~CInputTokenMaker(void)
	{
	}
	
public:
	///����һ������token�����ȡpStream��������һ����ȡ���ַ����ڱ�token��ĵ�һ���ַ�
	///@param	pStream	ʹ�õ�������
	///@param	ch	�Ѿ������ĵ�һ���ַ�
	///@param	resultToken	���ڷ��ý��������token
	///@return	true��ʾ�ɹ��ض�ȡ��һ��token��false��ʾ���Ǳ��ฺ�������token����ʱ����Ӱ��pStream��
	///@exception	����Ǳ��ฺ������������޷���ȷ����token������½��׳�CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken)=0;
};

/////////////////////////////////////////////////////////////////////////
///CInputTokenGenerator������һ������һ��token���������ϲ�����token������
///@author	���ض�
///@version	1.0,20090326
/////////////////////////////////////////////////////////////////////////
class CInputTokenGenerator
{
	///�������е�token������
	vector<CInputTokenMakerPtr> m_makerList;
	
	///ʹ�õ�������
	CInputStreamPtr m_pStream;
public:
	///���췽��
	///@param	pStream	ʹ�õ�������
	CInputTokenGenerator(const CInputStreamPtr &pStream);
	
	///��������
	~CInputTokenGenerator(void);
	
	//�ڱ����ڼ���һ���µ�token������
	void addInputTokenMaker(const CInputTokenMakerPtr &thisMaker);
	
	///��ȡ��һ��token
	///@param	resultToken	���ڷ��ý��������token
	///@return	true��ʾ�ɹ��ض�ȡ��һ��token��false��ʾ�Ѿ�����stream�Ľ�β
	///@exception	����дʷ������׳�CParseException
	bool getNextToken(CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CIdentifierInputTokenMaker������һ����ʶ������token������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CIdentifierInputTokenMaker,CInputTokenMaker)
{
protected:
	///˵����ʶ�������ַ����Ϻͼ����ַ�����
	CCharSetPtr m_firstCharSet, m_continueCharSet;
	
	///���ڴ�Ž���Ŀռ�
	char m_result[MAX_IDENTIFIER_LEN+1];
	
	///��������
	virtual ~CIdentifierInputTokenMaker(void)
	{
	}
	
	///���ý��
	///@param	resultToken	���ڷ��ý��������token
	virtual void setResult(CInputToken &resultToken);
public:
	///���췽��
	///@param	firstCharSet	ʹ�õ����ַ����ϣ�ȱʡֵ��ʹ��CCharSetForLetterUnderLine
	///@param	continueCharSet	ʹ�õļ����ַ����ϣ�ȱʡֵ��ʹ��CCharSetForLetterDigitUnderLine
	CIdentifierInputTokenMaker(CCharSetPtr firstCharSet=NULL,CCharSetPtr continueCharSet=NULL);

	///����һ������token�����ȡpStream��������һ����ȡ���ַ����ڱ�token��ĵ�һ���ַ�
	///@param	pStream	ʹ�õ�������
	///@param	ch	�Ѿ������ĵ�һ���ַ�
	///@param	resultToken	���ڷ��ý��������token
	///@return	true��ʾ�ɹ��ض�ȡ��һ��token��false��ʾ���Ǳ��ฺ�������token����ʱ����Ӱ��pStream��
	///@exception	����Ǳ��ฺ������������޷���ȷ����token������½��׳�CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CIKInputTokenMaker������һ����ʶ���͹ؼ��ʵ�����token������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CIKInputTokenMaker,CIdentifierInputTokenMaker)
{
protected:
	///���ڷ��ùؼ��ʵ�ӳ���
	map<string,int> m_keywordMap;
	
	typedef pair<string,int> TKeywordPair;
	
	///��������
	virtual ~CIKInputTokenMaker(void)
	{
	}
	
	///���ý��
	///@param	resultToken	���ڷ��ý��������token
	virtual void setResult(CInputToken &resultToken);
public:
	///���췽��
	///@param	keywords	���йؼ��ʵ��嵥�����һ��������Ҫ��һ��NULL
	///@param	firstCharSet	ʹ�õ����ַ����ϣ�ȱʡֵ��ʹ��CCharSetForLetterUnderLine
	///@param	continueCharSet	ʹ�õļ����ַ����ϣ�ȱʡֵ��ʹ��CCharSetForLetterDigitUnderLine
	CIKInputTokenMaker(const char *keywords[],CCharSetPtr firstCharSet=NULL,CCharSetPtr continueCharSet=NULL);
};

/////////////////////////////////////////////////////////////////////////
///COperatorInputTokenMaker������һ�����������token������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(COperatorInputTokenMaker,CInputTokenMaker)
{
protected:
	///���ڷ���������ؼ��ʵ�ӳ���
	map<string,int> m_operatorMap;
	
	typedef pair<string,int> TOperatorPair;
	
	///��������
	virtual ~COperatorInputTokenMaker(void)
	{
	}
	
	///�Ƿ�Ϸ��������ǰ��
	///@param	buffer	Ҫ�жϵ��ַ���
	///@param	operatorId	����һ�������������ʱ�����ظ�������ı�ţ�����������
	///@param	isOperator	����һ�������������ʱ������true�����򷵻�false
	///@param	canBeContinued	�������ַ������γ������������ʱ������true�����򷵻�false
	///@return	����һ���������ǰ�Σ�����������������������ʱ������true�����򷵻�false
	bool isValidSegment(char *buffer, int &operatorId, bool &isOperator, bool &canBeContinued);
	
	///��ȡ��������
	///@param	pStream	ʹ�õ�������
	///@param	ch	�Ѿ������ĵ�һ���ַ�
	///@return	����ɹ���ã��򷵻��������ţ����򷵻�-1
	int getOperatorId(CInputStreamPtr pStream, int ch);
public:
	///���췽��
	///@param	operators	����Ԫ������嵥������һ��������Ҫ��һ��NULL
	COperatorInputTokenMaker(const char *operators[]);
	
	///����һ������token�����ȡpStream��������һ����ȡ���ַ����ڱ�token��ĵ�һ���ַ�
	///@param	pStream	ʹ�õ�������
	///@param	ch	�Ѿ������ĵ�һ���ַ�
	///@param	resultToken	���ڷ��ý��������token
	///@return	true��ʾ�ɹ��ض�ȡ��һ��token��false��ʾ���Ǳ��ฺ�������token����ʱ����Ӱ��pStream��
	///@exception	����Ǳ��ฺ������������޷���ȷ����token������½��׳�CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);	
};

/////////////////////////////////////////////////////////////////////////
///CIntegerConstantInputTokenMaker������һ����������������token������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CIntegerConstantInputTokenMaker,CInputTokenMaker)
{
protected:
	///˵����ʶ�������ַ����Ϻͼ����ַ�����
	CCharSetPtr m_firstCharSet, m_continueCharSet;
	
	///˵���Ƿ�ֻ֧��10����
	bool m_supportOnlyDec;
	
	///���ڴ�Ž���Ŀռ�
	char m_result[MAX_NUMBER_LEN+1];
	
	///��������
	virtual ~CIntegerConstantInputTokenMaker(void)
	{
	}
	
	///���ý��
	///@param	pStream	ʹ�õ�������
	///@param	resultToken	���ڷ��ý��������token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);
public:
	///���췽��
	///@param	supportOnlyDec	�Ƿ�ֻ֧��10����
	///@param	firstCharSet	ʹ�õ����ַ����ϣ�ȱʡֵ��ʹ��CCharSetForDigit
	///@param	continueCharSet	ʹ�õļ����ַ����ϣ�ȱʡֵ��ʹ��CCharSetForDigit����CCharSetForDigitX���ڷ�ֻ֧��10�����£�
	CIntegerConstantInputTokenMaker(bool supportOnlyDec=true, CCharSetPtr firstCharSet=NULL,CCharSetPtr continueCharSet=NULL);

	///����һ������token�����ȡpStream��������һ����ȡ���ַ����ڱ�token��ĵ�һ���ַ�
	///@param	pStream	ʹ�õ�������
	///@param	ch	�Ѿ������ĵ�һ���ַ�
	///@param	resultToken	���ڷ��ý��������token
	///@return	true��ʾ�ɹ��ض�ȡ��һ��token��false��ʾ���Ǳ��ฺ�������token����ʱ����Ӱ��pStream��
	///@exception	����Ǳ��ฺ������������޷���ȷ����token������½��׳�CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CNumberConstantInputTokenMaker������һ�������͸���������������token������
///@author	���ض�
///@version	1.0,20090321
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CNumberConstantInputTokenMaker,CIntegerConstantInputTokenMaker)
{
protected:
	///��������
	virtual ~CNumberConstantInputTokenMaker(void)
	{
	}
	
	///���ý��
	///@param	pStream	ʹ�õ�������
	///@param	resultToken	���ڷ��ý��������token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);
public:
	///���췽��
	///@param	supportOnlyDecInt	�Ƿ�ֻ֧��10��������
	CNumberConstantInputTokenMaker(bool supportOnlyDecInt=false);
};

#define C_STYLE_STRING 1
#define CSV_STYLE_STRING 2
#define XML_STYLE_STRING 3

/////////////////////////////////////////////////////////////////////////
///CStringConstantInputTokenMaker������һ���ַ�������������token������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CStringConstantInputTokenMaker,CInputTokenMaker)
{
protected:
	///�ַ�����ת����
	int m_convertStyle;
	
	///�ָ��ַ�
	char *m_seperateChar;
	
	///���εĿ�ʼ�ַ���'\0'��ʾ�޿�ʼ�ַ�
	char m_leadingChar;

	///���ڴ�Ž���Ŀռ�
	char m_result[MAX_STRING_CONSTANT_LEN+1];
	
	///��������
	virtual ~CStringConstantInputTokenMaker(void)
	{
	}
	
	///���ý��
	///@param	pStream	ʹ�õ�������
	///@param	resultToken	���ڷ��ý��������token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);

public:
	///���췽��
	///@param	convertStyle	�ַ�����ת���񣬱���ΪC_STYLE_STRING��CSV_STYLE_STRING����XML_STYLE_STRING������XML_STYLE_STRING��δʵ��
	///@param	seperateChar	��������ķָ��ַ�
	///@description	��C_STYLE_STRING������£������C���Եķ�б��ת�崦��
	///		��CSV_STYLE_STRING������£�����ظ���ʼ�ַ�����ת�壬
	CStringConstantInputTokenMaker(int convertStyle=C_STYLE_STRING, char *seperateChar="\"\'");

	///����һ������token�����ȡpStream��������һ����ȡ���ַ����ڱ�token��ĵ�һ���ַ�
	///@param	pStream	ʹ�õ�������
	///@param	ch	�Ѿ������ĵ�һ���ַ�
	///@param	resultToken	���ڷ��ý��������token
	///@return	true��ʾ�ɹ��ض�ȡ��һ��token��false��ʾ���Ǳ��ฺ�������token����ʱ����Ӱ��pStream��
	///@exception	����Ǳ��ฺ������������޷���ȷ����token������½��׳�CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};

/////////////////////////////////////////////////////////////////////////
///CStringCharConstantInputTokenMaker������һ���ַ�������������token������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CStringCharConstantInputTokenMaker,CStringConstantInputTokenMaker)
{
protected:
	///�ַ������ķָ��
	char *m_charSeperateChar;

	///��������
	virtual ~CStringCharConstantInputTokenMaker(void)
	{
	}
	
	///���ý��
	///@param	pStream	ʹ�õ�������
	///@param	resultToken	���ڷ��ý��������token
	virtual void setResult(CInputStreamPtr pStream, CInputToken &resultToken);

public:
	///���췽��
	///@param	convertStyle	�ַ�����ת���񣬱���ΪC_STYLE_STRING��CSV_STYLE_STRING����XML_STYLE_STRING������XML_STYLE_STRING��δʵ��
	///@param	seperateChar	��������ķָ��ַ�
	///@param	charSeperateChar	����������ַ������ķָ��ַ�
	///@description	��C_STYLE_STRING������£������C���Եķ�б��ת�崦��
	///		��CSV_STYLE_STRING������£�����ظ���ʼ�ַ�����ת�壬
	CStringCharConstantInputTokenMaker(int convertStyle=C_STYLE_STRING, char *seperateChar="\"\'",char *charSeperateChar="\'");
};

/////////////////////////////////////////////////////////////////////////
///CCharacterInputTokenMaker������һ���ַ�������token������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
DefineRefClass(CCharacterInputTokenMaker,CInputTokenMaker)
{
protected:
	///����������ַ�����
	CCharSetPtr m_allowCharacterSet;

	///��������
	virtual ~CCharacterInputTokenMaker(void)
	{
	}
	
	///���ý��
	///@param	pStream	ʹ�õ�������
	///@param	ch	Ҫ���õ��ַ�
	///@param	resultToken	���ڷ��ý��������token
	virtual void setResult(CInputStreamPtr pStream, char ch, CInputToken &resultToken);

public:
	///���췽��
	///@param	allowCharacterSet	����������ַ����ϣ�ȱʡΪ�����ַ�
	CCharacterInputTokenMaker(CCharSetPtr allowCharacterSet=NULL);

	///����һ������token�����ȡpStream��������һ����ȡ���ַ����ڱ�token��ĵ�һ���ַ�
	///@param	pStream	ʹ�õ�������
	///@param	ch	�Ѿ������ĵ�һ���ַ�
	///@param	resultToken	���ڷ��ý��������token
	///@return	true��ʾ�ɹ��ض�ȡ��һ��token��false��ʾ���Ǳ��ฺ�������token����ʱ����Ӱ��pStream��
	///@exception	����Ǳ��ฺ������������޷���ȷ����token������½��׳�CParseException
	virtual bool makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken);
};
#endif
