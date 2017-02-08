/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CExprParser.h
///@brief	������һ�����ʽ����������
///@history 
///20080329	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CEXPR_PARSER_H
#define CEXPR_PARSER_H

#include "inputStream.h"
#include "CExprNode.h"

#define UNI_OPERATOR_LEFT 0		///�����ĵ�Ŀ�����
#define UNI_OPERATOR_RIGHT 1	///���Ҳ�ĵ�Ŀ�����
#define BI_OPERATOR_LEFT 2		///���ϵ�˫Ŀ�����
#define BI_OPERATOR_RIGHT 3		///�ҽ�ϵ�˫Ŀ�����

///������һ�����ȼ��������������˵������
typedef struct
{
	///˵�������ȼ�������������ͣ�������UNI_OPERATOR_LEFT��
	///UNI_OPERATOR_RIGHT��BI_OPERATOR_LEFT����BI_OPERATOR_RIGHT
	int operatorType;

	///�����ȼ����е���������Կո����
	const char *operators;
}	TOperatorLine;

/////////////////////////////////////////////////////////////////////////
///CExprParser������һ�����ʽ��������ģ���࣬ʹ�õ�ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CExprParser
{
private:
	///����������ȼ�����
	int m_operatorLine;

	///�������
	map<string,int> m_operatorMap;

	///��������������飨�����������ţ�
	const char **m_operators;

	///һ�����ȼ�����������ڲ�����
	typedef struct
	{
		int operatorType;
		set<int> *operatorSet;
		char *buffer;
	}	TOperatorLineDefine;

	///�������ȼ���������Ķ���
	TOperatorLineDefine *m_operatorLineDefines;

	///ʹ�õ�token������
	CInputTokenGenerator *m_generator;

	///��ǰʹ�õ�������
	CInputStreamPtr m_pInputStream;

	///��ǰ������token
	CInputToken m_curToken;

	///�����ķָ�����
	const char **m_funcSeperators;

	///���������ķָ���
	char m_funcParaSeperator;

	///��ʶ�������ַ����Ϻͺ����ַ�����
	CCharSetPtr m_identifierFirstCharSet, m_identifierContinueCharSet;

	///�Ƿ�֧�ָ�����
	bool m_supportFloat;

	///�Ƿ�ֻ֧��ʮ���Ƶ�����
	bool m_supportOnlyDecInt;

	///�Ƿ�ֻ֧���ַ���
	bool m_supportOnlyString;

	///�ַ���ת��ģʽ
	int m_stringConvertStyle;

	///�ַ������ַ���������ķָ���
	char *m_stringSeperatorChar;

	///�ַ���������ķָ�����Ӧ����stringSeperatorChar���Ӽ�
	char *m_charSeperatorChar;
	
	///�ؼ��ʱ�
	const char **m_keywords;

	///�жϵ�ǰtoken�Ƿ����ķָ���
	///@return	true��ʾ�ǣ�false��ʾ����
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

	///�жϵ�ǰtoken�Ƿ��������ķָ���
	///@return	true��ʾ�ǣ�false��ʾ����
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

	///�жϵ�ǰtoken�Ƿ�ָ�������ָ�����Ӧ�Ľ�β��
	///@param	funcSeperator	ָ���ĺ����ָ���
	///@return	true��ʾ�ǣ�false��ʾ����
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

	///ɨ��һ��ԭ��
	///@return	�õ���ԭ��
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

	///ɨ��һ��ԭ�Ӻ���
	///@return	�õ���ԭ�Ӻ���
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

	///ɨ��һ��ָ�����ȼ�����
	///@param	operatorLine	ָ�������ȼ�
	///@return	�õ��ı��ʽ�ڵ�
	CExprNode<V> *parseTerm(int operatorLine)
	{
		if (operatorLine>=m_operatorLine)
		{
			///���������ȼ��Ķ��壬�Ǿ�ɨ��ԭ��
			return parseAtomFunc();
		}
		set<int>::iterator it;
		switch (m_operatorLineDefines[operatorLine].operatorType)
		{
		case UNI_OPERATOR_LEFT:
			///����ߵĵ�Ŀ�����
			if (m_curToken.getTokenType()==TOKEN_OPERATOR)
			{
				///��ǰ��һ�������������������Ƿ����ȼ���Ҫ����������
				int operatorId=m_curToken.getOperator();
				it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
				if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
				{
					///���Ǳ����ȼ�����ģ��Ǿ�ֱ�ӷ��ظ�һ�����ȼ���ɨ��������
					return parseTerm(operatorLine+1);
				}
				else
				{
					///�Ǳ����ȼ�����ģ��Ǿ͵ݹ����ļ��㣬�ٲ������ڵ㼴��
					m_generator->getNextToken(m_curToken);
					CExprNode<V> *pSon=parseTerm(operatorLine);
					return new CUniOperatorExprNode<V>(m_operators[operatorId],pSon,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
				}
			}
			else
			{
				///��ǰ����һ����������Ǿ�ֱ�ӷ��ظ�һ�����ȼ���ɨ��������
				return parseTerm(operatorLine+1);
			}
			break;
		case UNI_OPERATOR_RIGHT:
			///���ұߵĵ�Ŀ�����
			{
				///�Ƚ���һ�����ȼ���ɨ�����õ�
				CExprNode<V> *pNode=parseTerm(operatorLine+1);
				while (m_curToken.getTokenType()==TOKEN_OPERATOR)
				{
					///��ǰ��һ�������������������Ƿ����ȼ���Ҫ����������
					int operatorId=m_curToken.getOperator();
					it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
					if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
					{
						///���Ǳ����ȼ�����ģ��ǾͿ��Է�����
						break;
					}
					///�Ǳ����ȼ�����ģ��ǾͲ������ڵ�
					pNode=new CUniOperatorExprNode<V>(m_operators[operatorId],pNode,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
					m_generator->getNextToken(m_curToken);
				}
				return pNode;
			}
		case BI_OPERATOR_LEFT:
			///���ϵ�˫Ŀ�����
			{
				///�Ƚ����һ��ɨ�����
				CExprNode<V> *pNode1=parseTerm(operatorLine+1);
				while (m_curToken.getTokenType()==TOKEN_OPERATOR)
				{
					///��ǰ��һ�������������������Ƿ����ȼ���Ҫ����������
					int operatorId=m_curToken.getOperator();
					it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
					if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
					{
						///���Ǳ����ȼ�����ģ��ǾͿ��Է�����
						break;
					}
					///�Ǳ����ȼ�����ģ��Ǿ�ɨ�����һ������������ڵ�
					m_generator->getNextToken(m_curToken);
					CExprNode<V> *pNode2=parseTerm(operatorLine+1);
					pNode1=new CBiOperatorExprNode<V>(m_operators[operatorId],pNode1,pNode2,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
				}
				return pNode1;
			}
		case BI_OPERATOR_RIGHT:
			///�ҽ�ϵ�˫Ŀ�����
			{
				///�Ƚ����һ��ɨ�����
				CExprNode<V> *pNode1=parseTerm(operatorLine+1);
				if (m_curToken.getTokenType()==TOKEN_OPERATOR)
				{
					///��ǰ��һ�������������������Ƿ����ȼ���Ҫ����������
					int operatorId=m_curToken.getOperator();
					it=m_operatorLineDefines[operatorLine].operatorSet->find(operatorId);
					if (it==m_operatorLineDefines[operatorLine].operatorSet->end())
					{
						///���Ǳ����ȼ�����ģ��ǾͿ��Է�����
						return pNode1;
					}
					else
					{
						///�Ǳ����ȼ�����ģ��Ǿ͵ݹ����ļ��㣬Ȼ��������ڵ㼴��
						m_generator->getNextToken(m_curToken);
						CExprNode<V> *pNode2=parseTerm(operatorLine);
						return new CBiOperatorExprNode<V>(m_operators[operatorId],pNode1,pNode2,m_pInputStream->getLineNo(),m_pInputStream->getColumnNo());
					}
				}
				else
				{
					///��ǰ����һ���������������ǾͿ��Է�����
					return pNode1;
				}
			}
		default:
			throw new CExprException("Unknown operator type",0,0);
			return NULL;
		}
	}

public:
	///���췽��
	///@param	operators	����������Ķ���
	///@param	operatorLineCount	����������ȼ�����
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
	
	///��������
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

	///ɨ��������ʽ�ڵ�
	///@param	inputStream	Ҫɨ���������
	///@return	�õ��ı��ʽ�ڵ�
	///@exception	���ɨ��ʧ�ܣ����׳�CExprException
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

	///���ùؼ��ʱ�
	///@param	keywords	����ʹ�õĹؼ���
	void setKeywords(const char **keywords)
	{
		m_keywords=keywords;
	}

	///���ú����ķָ�����ȱʡΪ()��[]
	///@param	funcSeperators	ָ���ĺ����ָ�������ʽΪ{"()","[]",NULL}����ģʽ
	void setFuncSeperators(const char **funcSeperators)
	{
		m_funcSeperators=funcSeperators;
	}

	///���ú��������ķָ�����ȱʡΪ����
	///@param	funcParaSeperator	ָ���ĺ��������ָ���
	void setFuncParaSeperator(char funcParaSeperator)
	{
		m_funcParaSeperator=funcParaSeperator;
	}

	///���ñ�ʶ���ַ�����
	///@param	identifierFirstCharSet	��ʶ�����ַ����ϣ����ΪNULL���ʾ��ĸ�»���
	///@param	identifierContinueCharSet	��ʶ�������ַ���ϣ����ΪNULL��ʾ��ĸ�����»���
	void setIdentifierCharSet(CCharSetPtr identifierFirstCharSet,CCharSetPtr identifierContinueCharSet)
	{
		m_identifierFirstCharSet=identifierFirstCharSet;
		m_identifierContinueCharSet=identifierContinueCharSet;
	}

	///������ֵ֧�����
	///@param	supportFloat	�Ƿ�֧�ָ�������ȱʡ��֧�ֵ�
	///@param	supportOnlyDecInt	�����Ƿ�ֻ֧��10���ƣ�ȱʡ��֧��10���ƣ���Ϊfalse��֧��0x__����0__������16���ƺ�10������
	void setNumberSupport(bool supportFloat, bool supportOnlyDecInt)
	{
		m_supportFloat=supportFloat;
		m_supportOnlyDecInt=supportOnlyDecInt;
	}

	///�����ַ�����֧�����
	///@param	supportOnlyString	�Ƿ�ֻ֧���ַ�����ȱʡΪfalse
	///@param	stringConvertStyle	�ַ���ת����ʽ��ȱʡΪC_STYLE_STRING��������ΪCSV_STYLE_STRING
	///@param	stringSeperatorChar	�����ַ������ַ��ķָ�����ȱʡΪ"��'
	///@param	charSeperatorChar	�����ַ��ķָ�����ȱʡΪ'����supportOnlyStringΪtrueʱ�����壬������stringSeperatorChar���Ӽ�
	void setStringSupport(bool supportOnlyString, int stringConvertStyle, char *stringSeperatorChar, char *charSeperatorChar)
	{
		m_supportOnlyString=supportOnlyString;
		m_stringConvertStyle=stringConvertStyle;
		m_stringSeperatorChar=stringSeperatorChar;
		m_charSeperatorChar=charSeperatorChar;
	}
};

#endif
