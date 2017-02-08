/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file CExprParser.h
///@brief	定义了一个表达式分析器的类
///@history 
///20080329	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef CEXPR_PARSER_H
#define CEXPR_PARSER_H

#include "inputStream.h"
#include "CExprNode.h"

#define UNI_OPERATOR_LEFT 0		///在左侧的单目运算符
#define UNI_OPERATOR_RIGHT 1	///在右侧的单目运算符
#define BI_OPERATOR_LEFT 2		///左结合的双目运算符
#define BI_OPERATOR_RIGHT 3		///右结合的双目运算符

///定义了一个优先级的所有运算符的说明类型
typedef struct
{
	///说明本优先级的运算符的类型，必须是UNI_OPERATOR_LEFT、
	///UNI_OPERATOR_RIGHT、BI_OPERATOR_LEFT或者BI_OPERATOR_RIGHT
	int operatorType;

	///本优先级所有的运算符，以空格隔开
	const char *operators;
}	TOperatorLine;

/////////////////////////////////////////////////////////////////////////
///CExprParser定义了一个表达式分析器的模板类，使用的模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CExprParser
{
private:
	///运算符的优先级层数
	int m_operatorLine;

	///运算符表
	map<string,int> m_operatorMap;

	///所有运算符的数组（按照运算符编号）
	const char **m_operators;

	///一个优先级的运算符的内部定义
	typedef struct
	{
		int operatorType;
		set<int> *operatorSet;
		char *buffer;
	}	TOperatorLineDefine;

	///各个优先级的运算符的定义
	TOperatorLineDefine *m_operatorLineDefines;

	///使用的token产生类
	CInputTokenGenerator *m_generator;

	///当前使用的输入流
	CInputStreamPtr m_pInputStream;

	///当前读到的token
	CInputToken m_curToken;

	///函数的分隔符表
	const char **m_funcSeperators;

	///函数参数的分隔符
	char m_funcParaSeperator;

	///标识符的首字符集合和后续字符集合
	CCharSetPtr m_identifierFirstCharSet, m_identifierContinueCharSet;

	///是否支持浮点数
	bool m_supportFloat;

	///是否只支持十进制的整数
	bool m_supportOnlyDecInt;

	///是否只支持字符串
	bool m_supportOnlyString;

	///字符串转换模式
	int m_stringConvertStyle;

	///字符串和字符所有允许的分隔符
	char *m_stringSeperatorChar;

	///字符所有允许的分隔符，应当是stringSeperatorChar的子集
	char *m_charSeperatorChar;
	
	///关键词表
	const char **m_keywords;

	///判断当前token是否函数的分隔符
	///@return	true表示是，false表示不是
	bool isFuncSeperator(void)
	{
		if (m_curToken.getTokenType()==TOKEN_CHARACTER)
		{
			char ch=m_curToken.getCharacter();
			const char **thisSeperator;
			for (thisSeperator=m_funcSeperators;*thisSeperator!=NULL;thisSeperator++)
			{
				if (ch==(*thisSeperator)[0])
				{
					return true;
				}
			}
		}
		return false;
	}

	///判断当前token是否函数参数的分隔符
	///@return	true表示是，false表示不是
	bool isFuncParaSeperator(void)
	{
		if (m_curToken.getTokenType()==TOKEN_CHARACTER)
		{
			char ch=m_curToken.getCharacter();
			if (ch==m_funcParaSeperator)
			{
				return true;
			}
		}
		return false;
	}

	///判断当前token是否指定函数分隔符对应的结尾符
	///@param	funcSeperator	指定的函数分隔符
	///@return	true表示是，false表示不是
	bool isFuncEndSeperator(char funcSeperator)
	{
		if (m_curToken.getTokenType()==TOKEN_CHARACTER)
		{
			char ch=m_curToken.getCharacter();
			const char **thisSeperator;
			for (thisSeperator=m_funcSeperators;*thisSeperator!=NULL;thisSeperator++)
			{
				if (funcSeperator==(*thisSeperator)[0])
				{
					if (ch==(*thisSeperator)[1])
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		return false;
	}

	///扫描一个原子
	///@return	得到的原子
	CExprNode<V> *parseAtom(void)
	{
		CExprNode<V> *pResult;
		V constantValue;
		switch (m_curToken.getTokenType())
		{
		case TOKEN_IDENTIFIER:
			{
				CRefStringPtr theIdentifier=m_curToken.getIdentifier();
				int lineNo=m_pInputStream->getLineNo();
				int columnNo=m_pInputStream->getColumnNo();
				m_generator->getNextToken(m_curToken);
				if (isFuncSeperator())
				{
					char funcSeperator=m_curToken.getCharacter();
					CIdentifierFunctionExprNode<V> *pThisResult;
					pThisResult=new CIdentifierFunctionExprNode<V>(theIdentifier,funcSeperator,lineNo,columnNo);
					pResult=pThisResult;
					m_generator->getNextToken(m_curToken);
					if (!isFuncEndSeperator(funcSeperator))
					{
						for (;;)
						{
							CExprNode<V> *pSon;
							pSon=parseTerm(0);
							pThisResult->addNode(pSon);
							if (isFuncParaSeperator())
							{
								m_generator->getNextToken(m_curToken);
							}
							else if (isFuncEndSeperator(funcSeperator))
							{
								break;
							}
							else
							{
								throw new CExprException("Syntax error in parameter defines",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
							}
						}
					}
					m_generator->getNextToken(m_curToken);
				}
				else
				{
					if (!constantValue.setIdentifierConstant(theIdentifier))
					{
						pResult=new CIdentifierExprNode<V>(theIdentifier,lineNo,columnNo);
					}
					else
					{
						pResult=new CConstantExprNode<V>(constantValue,lineNo,columnNo);
					}
				}
				break;
			}
		case TOKEN_INTEGER_CONSTANT:
			if (!constantValue.setIntegerConstant(m_curToken.getIntegerConstant()))
			{
				throw new CExprException("Can not use integer constant",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			}
			pResult=new CConstantExprNode<V>(constantValue,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			m_generator->getNextToken(m_curToken);
			break;
		case TOKEN_FLOAT_CONSTANT:
			if (!constantValue.setFloatConstant(m_curToken.getFloatConstant()))
			{
				throw new CExprException("Can not use Float constant",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			}
			pResult=new CConstantExprNode<V>(constantValue,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			m_generator->getNextToken(m_curToken);
			break;
		case TOKEN_STRING_CONSTANT:
			if (!constantValue.setStringConstant(m_curToken.getStringConstant()))
			{
				throw new CExprException("Can not use string constant",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			}
			pResult=new CConstantExprNode<V>(constantValue,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			m_generator->getNextToken(m_curToken);
			break;
		case TOKEN_CHAR_CONSTANT:
			if (!constantValue.setCharConstant(m_curToken.getCharConstant()))
			{
				throw new CExprException("Can not use char constant",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			}
			pResult=new CConstantExprNode<V>(constantValue,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			m_generator->getNextToken(m_curToken);
			break;
		case TOKEN_KEYWORD:
			if (!constantValue.setKeywordConstant(m_keywords[m_curToken.getKeyword()]))
			{
				pResult=new CKeywordExprNode<V>(m_keywords[m_curToken.getKeyword()],m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			}
			else
			{
				pResult=new CConstantExprNode<V>(constantValue,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
			}
			m_generator->getNextToken(m_curToken);
			break;
		case TOKEN_CHARACTER:
			if (m_curToken.getCharacter()=='(')
			{
				m_generator->getNextToken(m_curToken);
				pResult=parseTerm(0);
				if ((m_curToken.getTokenType()!=TOKEN_CHARACTER)||(m_curToken.getCharacter()!=')'))
				{
					throw new CExprException("Can not find ) for (",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
				}
				m_generator->getNextToken(m_curToken);
				break;
			}
		default:
			throw new CExprException("Invalid atom",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
		}
		return pResult;
	}

	///扫描一个原子函数
	///@return	得到的原子函数
	CExprNode<V> *parseAtomFunc(void)
	{
		CExprNode<V> *pFunc=parseAtom();
		for (;;)
		{
			if (isFuncSeperator())
			{
				char funcSeperator=m_curToken.getCharacter();
				CHighLevelFunctionExprNode<V> *pThisResult;
				pThisResult=new CHighLevelFunctionExprNode<V>(pFunc,funcSeperator,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
				m_generator->getNextToken(m_curToken);
				if (!isFuncEndSeperator(funcSeperator))
				{
					for (;;)
					{
						CExprNode<V> *pSon;
						pSon=parseTerm(0);
						pThisResult->addNode(pSon);
						if (isFuncParaSeperator())
						{
							m_generator->getNextToken(m_curToken);
						}
						else if (isFuncEndSeperator(funcSeperator))
						{
							break;
						}
						else
						{
							throw new CExprException("Syntax error in parameter defines",m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
						}
					}
				}
				m_generator->getNextToken(m_curToken);
				pFunc=pThisResult;
			}
			else
			{
				return pFunc;
			}
		}
	}

	///扫描一个指定优先级的项
	///@param	operatorLine	指定的优先级
	///@return	得到的表达式节点
	CExprNode<V> *parseTerm(int operatorLine)
	{
		if (operatorLine>=m_operatorLine)
		{
			///超出了优先级的定义，那就扫描原子
			return parseAtomFunc();
		}
		set<int>::iterator it;
		switch (m_operatorLineDefines[operatorLine].operatorType)
		{
		case UNI_OPERATOR_LEFT:
			///在左边的单目运算符
			if (m_curToken.getTokenType()==TOKEN_OPERATOR)
			{
				///当前是一个运算符的情况，看看是否本优先级需要处理的运算符
				int operatorId=m_curToken.getOperator();
				it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
				if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
				{
					///不是本优先级处理的，那就直接返回高一个优先级的扫描结果即可
					return parseTerm(operatorLine+1);
				}
				else
				{
					///是本优先级处理的，那就递归后面的计算，再产生本节点即可
					m_generator->getNextToken(m_curToken);
					CExprNode<V> *pSon=parseTerm(operatorLine);
					return new CUniOperatorExprNode<V>(m_operators[operatorId],pSon,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
				}
			}
			else
			{
				///当前不是一个运算符，那就直接返回高一个优先级的扫描结果即可
				return parseTerm(operatorLine+1);
			}
			break;
		case UNI_OPERATOR_RIGHT:
			///在右边的单目运算符
			{
				///先将高一个优先级的扫描结果得到
				CExprNode<V> *pNode=parseTerm(operatorLine+1);
				while (m_curToken.getTokenType()==TOKEN_OPERATOR)
				{
					///当前是一个运算符的情况，看看是否本优先级需要处理的运算符
					int operatorId=m_curToken.getOperator();
					it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
					if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
					{
						///不是本优先级处理的，那就可以返回了
						break;
					}
					///是本优先级处理的，那就产生本节点
					pNode=new CUniOperatorExprNode<V>(m_operators[operatorId],pNode,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
					m_generator->getNextToken(m_curToken);
				}
				return pNode;
			}
		case BI_OPERATOR_LEFT:
			///左结合的双目运算符
			{
				///先将左边一个扫描出来
				CExprNode<V> *pNode1=parseTerm(operatorLine+1);
				while (m_curToken.getTokenType()==TOKEN_OPERATOR)
				{
					///当前是一个运算符的情况，看看是否本优先级需要处理的运算符
					int operatorId=m_curToken.getOperator();
					it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
					if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
					{
						///不是本优先级处理的，那就可以返回了
						break;
					}
					///是本优先级处理的，那就扫描后面一个项，并产生本节点
					m_generator->getNextToken(m_curToken);
					CExprNode<V> *pNode2=parseTerm(operatorLine+1);
					pNode1=new CBiOperatorExprNode<V>(m_operators[operatorId],pNode1,pNode2,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
				}
				return pNode1;
			}
		case BI_OPERATOR_RIGHT:
			///右结合的双目运算符
			{
				///先将左边一个扫描出来
				CExprNode<V> *pNode1=parseTerm(operatorLine+1);
				if (m_curToken.getTokenType()==TOKEN_OPERATOR)
				{
					///当前是一个运算符的情况，看看是否本优先级需要处理的运算符
					int operatorId=m_curToken.getOperator();
					it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
					if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
					{
						///不是本优先级处理的，那就可以返回了
						return pNode1;
					}
					else
					{
						///是本优先级处理的，那就递归后面的计算，然后产生本节点即可
						m_generator->getNextToken(m_curToken);
						CExprNode<V> *pNode2=parseTerm(operatorLine);
						return new CBiOperatorExprNode<V>(m_operators[operatorId],pNode1,pNode2,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
					}
				}
				else
				{
					///当前不是一个运算符的情况，那就可以返回了
					return pNode1;
				}
			}
		default:
			throw new CExprException("Unknown operator type",0,0);
			return NULL;
		}
	}

public:
	///构造方法
	///@param	operators	所有运算符的定义
	///@param	operatorLineCount	运算符的优先级层数
	CExprParser(TOperatorLine *operators, int operatorLineCount)
	{
		static const char *defaultFuncSeperators[]={"()","[]",NULL};
	
		m_funcSeperators=defaultFuncSeperators;
		m_funcParaSeperator=',';

		m_identifierFirstCharSet=NULL;
		m_identifierContinueCharSet=NULL;

		m_supportFloat=true;
		m_supportOnlyDecInt=true;

		m_supportOnlyString=false;
		m_stringConvertStyle=C_STYLE_STRING;
		m_stringSeperatorChar="\"\'";
		m_charSeperatorChar="\'";
		
		m_keywords=NULL;

		m_generator=NULL;
		m_operatorLine=operatorLineCount;

		int operatorCount=0;
		map<string,int>::iterator it;

		if (m_operatorLine==0)
		{
			m_operatorLineDefines=NULL;
		}
		else
		{
			m_operatorLineDefines=new TOperatorLineDefine[m_operatorLine];
			for (int i=0;i<m_operatorLine;i++)
			{
				m_operatorLineDefines[i].operatorType=operators[i].operatorType;
				m_operatorLineDefines[i].buffer=strdup(operators[i].operators);
				m_operatorLineDefines[i].operatorSet=new set<int>;
				char *thisOperator=strtok(m_operatorLineDefines[i].buffer," ");
				while (thisOperator!=NULL)
				{
					int thisOperatorId;
					it=m_operatorMap.find(thisOperator);
					if (it!=m_operatorMap.end())
					{
						thisOperatorId=it->second;
					}
					else
					{
						thisOperatorId=operatorCount++;
						m_operatorMap.insert(pair<string,int>(thisOperator,thisOperatorId));
					}
					m_operatorLineDefines[i].operatorSet->insert(thisOperatorId);
					thisOperator=strtok(NULL," ");
				}
			}
		}
		m_operators=new const char *[operatorCount+1];
		m_operators[operatorCount]=NULL;
		for (it=m_operatorMap.begin();it!=m_operatorMap.end();it++)
		{
			m_operators[it->second]=it->first.c_str();
		}
	}
	
	///析构方法
	~CExprParser(void)
	{
		if (m_operatorLineDefines!=NULL)
		{
			for (int i=0;i<m_operatorLine;i++)
			{
				delete m_operatorLineDefines[i].buffer;
				delete m_operatorLineDefines[i].operatorSet;
			}
			delete m_operatorLineDefines;
		}
		if (m_operators!=NULL)
		{
			delete m_operators;
		}
		if (m_generator!=NULL)
		{
			delete m_generator;
		}
	}

	///扫描产生表达式节点
	///@param	inputStream	要扫描的输入流
	///@return	得到的表达式节点
	///@exception	如果扫描失败，则抛出CExprException
	CExprNode<V> *parse(CInputStreamPtr &inputStream)
	{
		m_pInputStream=inputStream;
		m_generator=new CInputTokenGenerator(inputStream);

		if (m_keywords==NULL)
		{
			m_generator->addInputTokenMaker(new CIdentifierInputTokenMaker(m_identifierFirstCharSet, m_identifierContinueCharSet));
		}
		else
		{
			m_generator->addInputTokenMaker(new CIKInputTokenMaker(m_keywords,m_identifierFirstCharSet, m_identifierContinueCharSet));
		}
		
		m_generator->addInputTokenMaker(new COperatorInputTokenMaker(m_operators));

		if (m_supportFloat)
		{
			m_generator->addInputTokenMaker(new CNumberConstantInputTokenMaker(m_supportOnlyDecInt));
		}
		else
		{
			m_generator->addInputTokenMaker(new CIntegerConstantInputTokenMaker(m_supportOnlyDecInt));
		}
		
		if (m_supportOnlyString)
		{
			m_generator->addInputTokenMaker(new CStringConstantInputTokenMaker(m_stringConvertStyle,m_stringSeperatorChar));
		}
		else
		{
			m_generator->addInputTokenMaker(new CStringCharConstantInputTokenMaker(m_stringConvertStyle,m_stringSeperatorChar,m_charSeperatorChar));
		}
		m_generator->addInputTokenMaker(new CCharacterInputTokenMaker());

		if (!m_generator->getNextToken(m_curToken))
		{
			throw new CExprException("Empty input",inputStream->getLineNo(),inputStream->getColumnNo());
		}

		CExprNode<V> *pResult=parseTerm(0);

		if (!m_curToken.isEOF())
		{
			throw new CExprException("End of input expected",inputStream->getLineNo(),inputStream->getColumnNo());
		}

		delete m_generator;
		m_generator=NULL;
		m_pInputStream=NULL;

		return pResult;
	}

	///设置关键词表
	///@param	keywords	所有使用的关键词
	void setKeywords(const char **keywords)
	{
		m_keywords=keywords;
	}

	///设置函数的分隔符，缺省为()和[]
	///@param	funcSeperators	指定的函数分隔符，形式为{"()","[]",NULL}这种模式
	void setFuncSeperators(const char **funcSeperators)
	{
		m_funcSeperators=funcSeperators;
	}

	///设置函数参数的分隔符，缺省为逗号
	///@param	funcParaSeperator	指定的函数参数分隔符
	void setFuncParaSeperator(char funcParaSeperator)
	{
		m_funcParaSeperator=funcParaSeperator;
	}

	///设置标识符字符集合
	///@param	identifierFirstCharSet	标识符首字符集合，如果为NULL则表示字母下划线
	///@param	identifierContinueCharSet	标识符继续字符结合，如果为NULL表示字母数字下划线
	void setIdentifierCharSet(CCharSetPtr identifierFirstCharSet,CCharSetPtr identifierContinueCharSet)
	{
		m_identifierFirstCharSet=identifierFirstCharSet;
		m_identifierContinueCharSet=identifierContinueCharSet;
	}

	///设置数值支持情况
	///@param	supportFloat	是否支持浮点数，缺省是支持的
	///@param	supportOnlyDecInt	整数是否只支持10进制，缺省是支持10进制，改为false将支持0x__或者0__这样的16进制和10进制数
	void setNumberSupport(bool supportFloat, bool supportOnlyDecInt)
	{
		m_supportFloat=supportFloat;
		m_supportOnlyDecInt=supportOnlyDecInt;
	}

	///设置字符串的支持情况
	///@param	supportOnlyString	是否只支持字符串，缺省为false
	///@param	stringConvertStyle	字符串转换方式，缺省为C_STYLE_STRING，还可以为CSV_STYLE_STRING
	///@param	stringSeperatorChar	所有字符串和字符的分隔符，缺省为"和'
	///@param	charSeperatorChar	所有字符的分隔符，缺省为'，在supportOnlyString为true时无意义，必须是stringSeperatorChar的子集
	void setStringSupport(bool supportOnlyString, int stringConvertStyle, char *stringSeperatorChar, char *charSeperatorChar)
	{
		m_supportOnlyString=supportOnlyString;
		m_stringConvertStyle=stringConvertStyle;
		m_stringSeperatorChar=stringSeperatorChar;
		m_charSeperatorChar=charSeperatorChar;
	}
};

#endif
