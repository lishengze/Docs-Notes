/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file inputToken.cpp
///@brief	实现了输入的token相关处理类
///@history 
///20080321	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "inputToken.h"

void CInputToken::display(FILE *output)
{
	switch (m_tokenType)
	{
		case TOKEN_UNKNOWN:
			fprintf(output,"Unknown Token");
			break;
		case TOKEN_CHARACTER:
			fprintf(output,"Char Token:%c",m_value.m_ch);
			break;
		case TOKEN_IDENTIFIER:
			fprintf(output,"Identifier Token:%s",m_string->getValue());
			break;
		case TOKEN_KEYWORD:
			fprintf(output,"Keyword Token:%d",m_value.m_keyword);
			break;
		case TOKEN_OPERATOR:
			fprintf(output,"Operator Token:%d",m_value.m_operator);
			break;
		case TOKEN_INTEGER_CONSTANT:
			fprintf(output,"Integer Constant Token:%d",m_value.m_integerConstant);
			break;
		case TOKEN_FLOAT_CONSTANT:
			fprintf(output,"Float Constant Token:%f",m_value.m_floatConstant);
			break;
		case TOKEN_STRING_CONSTANT:
			fprintf(output,"String Constant Token:%s",m_string->getValue());
			break;
		case TOKEN_CHAR_CONSTANT:
			fprintf(output,"Char Constant Token:%c",m_value.m_charConstant);
			break;
		case TOKEN_EOF:
			fprintf(output,"EOF Token");
			break;
		default:
			fprintf(output,"Invalid Token");
	}
}

CInputTokenGenerator::CInputTokenGenerator(const CInputStreamPtr &pStream)
{
	m_pStream=pStream;
}
	
CInputTokenGenerator::~CInputTokenGenerator(void)
{
}

void CInputTokenGenerator::addInputTokenMaker(const CInputTokenMakerPtr &thisMaker)
{
	m_makerList.push_back(thisMaker);
}
	
bool CInputTokenGenerator::getNextToken(CInputToken &resultToken)
{
	int ch;
	ch=m_pStream->getNextNonSpaceChar();
	if (ch==EOF)
	{
		resultToken.setEOF();
		return false;
	}
	vector<CInputTokenMakerPtr>::iterator it;
	for (it=m_makerList.begin();it!=m_makerList.end();it++)
	{
		if ((*it)->makeToken(m_pStream,ch,resultToken))
		{
			//resultToken.display();
			//printf("\n");
			return true;
		}
	}
	throw new CExprException(m_pStream->getLineNo(),m_pStream->getColumnNo(),"Unexpected character:%c",ch);
	return false;
}

CIdentifierInputTokenMaker::CIdentifierInputTokenMaker(CCharSetPtr firstCharSet, CCharSetPtr continueCharSet)
{
	if (firstCharSet!=NULL)
	{
		m_firstCharSet=firstCharSet;
	}
	else
	{
		m_firstCharSet=new CCharSetForLetterUnderLine();
	}
	if (continueCharSet!=NULL)
	{
		m_continueCharSet=continueCharSet;
	}
	else
	{
		m_continueCharSet=new CCharSetForLetterDigitUnderLine();
	}
}

bool CIdentifierInputTokenMaker::makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken)
{
	if (!m_firstCharSet->isIn(ch))
	{
		return false;
	}
	char *pBuffer=m_result;
	*pBuffer++=ch;
	for (;;)
	{
		ch=pStream->getNextChar();
		// next add by zhou.jj on 20090427 增加解释转义字符/
		if (ch=='\\')
		{
			ch=pStream->getNextChar();
			*pBuffer++ = ch;
			ch=pStream->getNextChar();
		}
		// before add by zhou.jj on 20090427
		if (!m_continueCharSet->isIn(ch))
		{
			*pBuffer='\0';
			pStream->ungetChar(ch);
			break;
		}
		if (pBuffer>=m_result+MAX_IDENTIFIER_LEN)
		{
			throw new CExprException("Too long identifier",pStream->getLineNo(),pStream->getColumnNo());
		}
		*pBuffer++=ch;
	}
	setResult(resultToken);
	return true;
}

void CIdentifierInputTokenMaker::setResult(CInputToken &resultToken)
{
	resultToken.setIdentifier(m_result);
}

CIKInputTokenMaker::CIKInputTokenMaker(const char *keywords[],CCharSetPtr firstCharSet,CCharSetPtr continueCharSet):
	CIdentifierInputTokenMaker(firstCharSet,continueCharSet)
{
	for (int i=0;keywords[i]!=NULL;i++)
	{
		m_keywordMap.insert(TKeywordPair(keywords[i],i));
	}
}

void CIKInputTokenMaker::setResult(CInputToken &resultToken)
{
	map<string,int>::iterator it;
	it=m_keywordMap.find(m_result);
	if (it!=m_keywordMap.end())
	{
		resultToken.setKeyword(it->second);
	}
	else
	{
		resultToken.setIdentifier(m_result);
	}
}

COperatorInputTokenMaker::COperatorInputTokenMaker(const char *operators[])
{
	for (int i=0;operators[i]!=NULL;i++)
	{
		m_operatorMap.insert(TOperatorPair(operators[i],i));
	}
}

bool COperatorInputTokenMaker::isValidSegment(char *buffer, int &operatorId, bool &isOperator, bool &canBeContinued)
{
	map<string,int>::iterator it;
	it=m_operatorMap.lower_bound(buffer);
	int len=strlen(buffer);
	if ((it==m_operatorMap.end())||(strncmp(it->first.c_str(),buffer,len)))
	{
		isOperator=false;
		canBeContinued=false;
	}
	else
	{
		if (it->first==buffer)
		{
			isOperator=true;
			operatorId=it->second;
			it++;
			if ((it==m_operatorMap.end())||(strncmp(it->first.c_str(),buffer,len)))
			{
				canBeContinued=false;
			}
			else
			{
				canBeContinued=true;
			}
		}
		else
		{
			isOperator=false;
			canBeContinued=true;
		}
	}
	return isOperator||canBeContinued;
}
	
bool COperatorInputTokenMaker::makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken)
{
	int operatorId=getOperatorId(pStream,ch);
	if (operatorId==-1)
	{
		return false;
	}
	resultToken.setOperator(operatorId);
	return true;
}

int COperatorInputTokenMaker::getOperatorId(CInputStreamPtr pStream, int ch)
{
	char buffer[MAX_OPERATOR_LEN+1];
	char *pBuffer=buffer;
	
	int operatorId;
	bool isOperator,canBeContinued;

	*pBuffer++=ch;
	*pBuffer='\0';
	if (!isValidSegment(buffer,operatorId,isOperator,canBeContinued))
	{
		return -1;
	}
	for (;;)
	{
		if (!canBeContinued)
		{
			if (isOperator)
			{
				return operatorId;
			}
			else
			{
				throw CExprException("Invalid Operator",pStream->getLineNo(),pStream->getColumnNo());
			}
		}
		ch=pStream->getNextChar();
		*pBuffer++=ch;
		*pBuffer='\0';
		if (!isValidSegment(buffer,operatorId,isOperator,canBeContinued))
		{
			pStream->ungetChar(ch);
			return operatorId;
		}
	}
	return true;
}

void CIntegerConstantInputTokenMaker::setResult(CInputStreamPtr pStream, CInputToken &resultToken)
{
	unsigned long result;
	char *endPtr;
	if (m_supportOnlyDec)
	{
		result=strtoul(m_result,&endPtr,10);
	}
	else
	{
		result=strtoul(m_result,&endPtr,0);
	}
	if (*endPtr!='\0')
	{
		throw new CExprException("Invalid Integer Number",pStream->getLineNo(),pStream->getColumnNo());
	}
	resultToken.setIntegerConstant(result);
}

CIntegerConstantInputTokenMaker::CIntegerConstantInputTokenMaker(bool supportOnlyDec, CCharSetPtr firstCharSet,CCharSetPtr continueCharSet)
{
	m_supportOnlyDec=supportOnlyDec;
	if (firstCharSet!=NULL)
	{
		m_firstCharSet=firstCharSet;
	}
	else
	{
		m_firstCharSet=new CCharSetForDigit();
	}
	if (continueCharSet!=NULL)
	{
		m_continueCharSet=continueCharSet;
	}
	else
	{
		if (m_supportOnlyDec)
		{
			m_continueCharSet=m_firstCharSet;
		}
		else
		{
			m_continueCharSet=new CCharSetForDigitX();
		}
	}
}

bool CIntegerConstantInputTokenMaker::makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken)
{
	if (!m_firstCharSet->isIn(ch))
	{
		return false;
	}
	char *pBuffer=m_result;
	*pBuffer++=ch;
	for (;;)
	{
		ch=pStream->getNextChar();
		if (!m_continueCharSet->isIn(ch))
		{
			*pBuffer='\0';
			pStream->ungetChar(ch);
			break;
		}
		if (pBuffer>=m_result+MAX_NUMBER_LEN)
		{
			throw new CExprException("Too long number",pStream->getLineNo(),pStream->getColumnNo());
		}
		*pBuffer++=ch;
	}
	setResult(pStream,resultToken);
	return true;
}

CNumberConstantInputTokenMaker::CNumberConstantInputTokenMaker(bool supportOnlyDecInt) :
	CIntegerConstantInputTokenMaker(supportOnlyDecInt,new CCharSetForDigitDot(), new CCharSetForLetterDigitDot())
{
}

void CNumberConstantInputTokenMaker::setResult(CInputStreamPtr pStream, CInputToken &resultToken)
{
	bool isFloat=false;
	if (strchr(m_result,'.'))
	{
		isFloat=true;
	}
	else if ((m_result[1]!='x')&&(m_result[1]!='X'))
	{
		if (strchr(m_result,'e')||strchr(m_result,'E'))
		{
			isFloat=true;
		}
	}
	if (isFloat)
	{
		char *endPtr;
		double result=strtod(m_result,&endPtr);
		if (*endPtr!='\0')
		{
			throw new CExprException("Invalid Float Number",pStream->getLineNo(),pStream->getColumnNo());
		}
		resultToken.setFloatConstant(result);	
	}
	else
	{
		CIntegerConstantInputTokenMaker::setResult(pStream,resultToken);
	}
}

void CStringConstantInputTokenMaker::setResult(CInputStreamPtr pStream, CInputToken &resultToken)
{
	resultToken.setStringConstant(m_result);
}

CStringConstantInputTokenMaker::CStringConstantInputTokenMaker(int convertStyle, char *seperateChar)
{
	m_convertStyle=convertStyle;
	m_seperateChar=seperateChar;
}

bool CStringConstantInputTokenMaker::makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken)
{
	char *pResult=m_result;
	if (strchr(m_seperateChar,ch))
	{
		///发现了分隔字符
		m_leadingChar=ch;
		ch=pStream->getNextChar();
	}
	else
	{
		///那就不是字符串了
		return false;
	}
	for (;;)
	{
		if (ch==EOF)
		{
			///到了结束位置了，那就有问题了
			throw new CExprException("Unexpected end at string constant",pStream->getLineNo(),pStream->getColumnNo());
		}
		if (m_convertStyle=C_STYLE_STRING)
		{
			if (ch==m_leadingChar)
			{
				///找到了开始字符，那就完成本字符串了
				*pResult='\0';
				setResult(pStream,resultToken);
				return true;
			}
			///对于C字符串转移模式的处理
			if (ch=='\\')
			{
				ch=pStream->getNextChar();
				if (ch==EOF)
				{
					throw new CExprException("Unexpected end at string constant",pStream->getLineNo(),pStream->getColumnNo());
				}
				switch (ch)
				{
				case 'f':
					ch='\f';
					break;
				case 'n':
					ch='\n';
					break;
				case 'r':
					ch='\r';
					break;
				case 't':
					ch='\t';
					break;
				case '\\':
					ch='\\';
					break;
				case '\"':
					ch='\"';
					break;
				case '\'':
					ch='\'';
					break;
				case '0':
					{
						int thisAsc=0;
						while (isdigit(ch=pStream->getNextChar()))
						{
							thisAsc=thisAsc*8+ch-'0';
						}
						pStream->ungetChar(ch);
						ch=(char)thisAsc;
					}
				default:
					break;
				}
			}
		}
		else if (m_convertStyle=CSV_STYLE_STRING)
		{
			if (ch==m_leadingChar)
			{
				///找到了开始字符
				ch=pStream->getNextChar();
				if (ch!=m_leadingChar)
				{
					///看来不是开始字符转义，那就说明结束了
					pStream->ungetChar(ch);
					*pResult='\0';
					setResult(pStream,resultToken);
					return true;
				}
				///否则就是转义，只要加入本字符就可以了
			}
		}
		if (pResult>=m_result+MAX_STRING_CONSTANT_LEN)
		{
			throw new CExprException("Too long string constant",pStream->getLineNo(),pStream->getColumnNo());
		}
		*pResult++=ch;
		ch=pStream->getNextChar();
	}
}

void CStringCharConstantInputTokenMaker::setResult(CInputStreamPtr pStream, CInputToken &resultToken)
{
	if (strchr(m_charSeperateChar,m_leadingChar))
	{
		if (strlen(m_result)>1)
		{
			throw new CExprException("Too long character constant",pStream->getLineNo(),pStream->getColumnNo());
		}
		resultToken.setCharConstant(m_result[0]);
	}
	else
	{
		CStringConstantInputTokenMaker::setResult(pStream,resultToken);
	}
}

CStringCharConstantInputTokenMaker::CStringCharConstantInputTokenMaker(int convertStyle, char *seperateChar,char *charSeperateChar) :
	CStringConstantInputTokenMaker(convertStyle,seperateChar)
{
	m_charSeperateChar=charSeperateChar;
}

void CCharacterInputTokenMaker::setResult(CInputStreamPtr pStream, char ch, CInputToken &resultToken)
{
	resultToken.setCharacter(ch);
}

CCharacterInputTokenMaker::CCharacterInputTokenMaker(CCharSetPtr allowCharacterSet)
{
	if (allowCharacterSet==NULL)
	{
		m_allowCharacterSet=new CCharSetNotInString("");
	}
	else
	{
		m_allowCharacterSet=allowCharacterSet;
	}
}

bool CCharacterInputTokenMaker::makeToken(CInputStreamPtr pStream, int ch, CInputToken &resultToken)
{
	if (m_allowCharacterSet->isIn(ch))
	{
		setResult(pStream,ch,resultToken);
		return true;
	}
	else
	{
		return false;
	}
}
