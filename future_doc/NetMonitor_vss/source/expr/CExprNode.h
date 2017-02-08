/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CExprNode.h
///@brief	�����˱��ʽ�ڵ�
///@history 
///20080329	���ض�		�������ļ�
///20080624 �ܽ���		�޸�ģ����͵���������,��g++��ģ�����еĵ�����
///						������Ҫ�������Ͷ���˵��
/////////////////////////////////////////////////////////////////////////

#ifndef CEXPR_NODE_H
#define CEXPR_NODE_H

#include "CBaseValue.h"
#include "CBaseContext.h"
#include "CExprException.h"

/////////////////////////////////////////////////////////////////////////
///CExprNode������һ�����ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CExprNode
{
protected:
	///���ڵ��ֵ���䶨�����Ÿ����������ͬ
	V m_value;
	
	///���ڵ���кź��кţ������ڱ���ʱ��λ
	int m_lineNo,m_columnNo;

	///���ǰ���հ�
	///@param	output	Ҫ������ļ�
	///@param	count	Ҫ����ĸ���
	void displayTABs(FILE *output,int count)
	{
		for (int i=0;i<count;i++)
		{
			fprintf(output,"\t");
		}
	}

public:
	///���췽��
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CExprNode(int lineNo, int columnNo)
	{
		m_lineNo=lineNo;
		m_columnNo=columnNo;
	}
	
	///��������
	virtual ~CExprNode(void)
	{
	}

	bool getConstantFlag(void)
	{
		return m_value.getConstantFlag();
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)=0;
	
	///�����кź��к�
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	virtual void setLineColumnNo(int lineNo, int columnNo)
	{
		m_lineNo=lineNo;
		m_columnNo=columnNo;
	}
	
	///��ȡ�кź��к�
	///@param	lineNo	���ص��к�
	///@param	columnNo	���ص��к�
	virtual void getLineColumnNo(int& lineNo, int& columnNo)
	{
		lineNo=m_lineNo;
		columnNo=m_columnNo;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)=0;
};

/////////////////////////////////////////////////////////////////////////
///CConstantExprNode������һ�������ı��ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CConstantExprNode: public CExprNode<V>
{
public:
	///���췽��
	///@param	value	Ҫ���õ�ֵ
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CConstantExprNode(V &value,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		this->m_value=value;
		this->m_value.setConstantFlag(true);
	}
	
	///��������
	virtual ~CConstantExprNode(void)
	{
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		return this->m_value;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		this->m_value.display(output);
		fprintf(output,"\n");
	}
};

/////////////////////////////////////////////////////////////////////////
///CIdentifierExprNode������һ����ʶ���ı��ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CIdentifierExprNode: public CExprNode<V>
{
protected:
	///ʹ�õı�ʶ��
	CRefStringPtr m_identifier;
	
public:
	///���췽��
	///@param	identifier	ʹ�õı�ʶ��
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CIdentifierExprNode(CRefStringPtr &identifier,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_identifier=identifier;
	}
	
	///��������
	virtual ~CIdentifierExprNode(void)
	{
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (!getConstantFlag() && !context.getIdentifierValue(this->m_value,m_identifier))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval identifier %s",m_identifier->getValue());
		}
		return this->m_value;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		fprintf(output,"identifier:%s",m_identifier->getValue());
		if (showValue)
		{
			fprintf(output,"(");
			this->m_value.display(output);
			fprintf(output,")");
		}
		fprintf(output,"\n");
	}
};

/////////////////////////////////////////////////////////////////////////
///CKeywordExprNode������һ���ؼ��ʵı��ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CKeywordExprNode: public CExprNode<V>
{
protected:
	///ʹ�õı�ʶ��
	const char *m_keyword;
	
public:
	///���췽��
	///@param	identifier	ʹ�õĹؼ���
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CKeywordExprNode(const char *keyword,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_keyword=keyword;
	}
	
	///��������
	virtual ~CKeywordExprNode(void)
	{
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (!getConstantFlag() && !context.getKeywordValue(this->m_value,m_keyword))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval keyword %s",m_keyword);
		}
		return this->m_value;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		fprintf(output,"keyword:%s",m_keyword);
		if (showValue)
		{
			fprintf(output,"(");
			this->m_value.display(output);
			fprintf(output,")");
		}
		fprintf(output,"\n");
	}
};

/////////////////////////////////////////////////////////////////////////
///CUniOperatorExprNode������һ����Ŀ������ı��ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CUniOperatorExprNode: public CExprNode<V>
{
protected:
	///ʹ�õĵ�Ŀ�����
	const char *m_operator;
	
	///ָ���ӽڵ�
	CExprNode<V> *m_son;

public:
	///���췽��
	///@param	thisOperator	ʹ�õı�ʶ��
	///@param	pSon	ʹ�õ��ӽڵ�
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CUniOperatorExprNode(const char *thisOperator, CExprNode<V> *pSon,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_operator=thisOperator;
		m_son=pSon;
	}
	
	///��������
	virtual ~CUniOperatorExprNode(void)
	{
		delete m_son;
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (getConstantFlag())
			return this->m_value;

		V& sonValue=m_son->eval(context);
		if (!context.getUniOperatorResult(this->m_value,sonValue,m_operator))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval unioperator %s",m_operator);
		}
		return this->m_value;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		fprintf(output,"UniOperator:%s",m_operator);
		if (showValue)
		{
			fprintf(output,"(");
			this->m_value.display(output);
			fprintf(output,")");
		}
		fprintf(output,"\n");
		m_son->display(showValue,output,indent+1);
	}
};

/////////////////////////////////////////////////////////////////////////
///CBiOperatorExprNode������һ��˫Ŀ������ı��ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CBiOperatorExprNode: public CExprNode<V>
{
protected:
	///ʹ�õĵ�Ŀ�����
	const char *m_operator;
	
	///ָ��������ӽڵ�
	CExprNode<V> *m_son1,*m_son2;

public:
	///���췽��
	///���췽��
	///@param	thisOperator	ʹ�õı�ʶ��
	///@param	pSon1	ʹ�õ��ӽڵ�1
	///@param	pSon2	ʹ�õ��ӽڵ�2
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CBiOperatorExprNode(const char *thisOperator, CExprNode<V> *pSon1, CExprNode<V> *pSon2,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_operator=thisOperator;
		m_son1=pSon1;
		m_son2=pSon2;
	}
	
	///��������
	virtual ~CBiOperatorExprNode(void)
	{
		delete m_son1;
		delete m_son2;
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (getConstantFlag())
			return this->m_value;

		V& son1Value=m_son1->eval(context);
		V& son2Value=m_son2->eval(context);
		if (!context.getBiOperatorResult(this->m_value,son1Value,m_operator,son2Value))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval bioperator %s",m_operator);
		}
		return this->m_value;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		fprintf(output,"BiOperator:%s",m_operator);
		if (showValue)
		{
			fprintf(output,"(");
			this->m_value.display(output);
			fprintf(output,")");
		}
		fprintf(output,"\n");
		m_son1->display(showValue,output,indent+1);
		m_son2->display(showValue,output,indent+1);
	}
};

/////////////////////////////////////////////////////////////////////////
///CIdentifierFunctionExprNode������һ����ʶ�������ı��ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CIdentifierFunctionExprNode: public CExprNode<V>
{
protected:
	///ʹ�õĺ�����ʶ��
	CRefStringPtr m_identifier;
	
	///ָ�����е��ӽڵ�
	vector<CExprNode<V> *> m_sons;

	///�����ָ���
	char m_funcSeperator;

	///ָ�����в�����ֵ
	V** m_paras;

public:
	///���췽��
	///���췽��
	///@param	identifier	ʹ�õı�ʶ��
	///@param	funcSeperator	ʹ�õĺ����ָ���
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CIdentifierFunctionExprNode(CRefStringPtr &identifier,char funcSeperator,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_paras=NULL;
		m_identifier=identifier;
		m_funcSeperator=funcSeperator;
	}
	
	///��������
	virtual ~CIdentifierFunctionExprNode(void)
	{
		if (m_paras!=NULL)
		{
			delete m_paras;
		}
#ifdef WINDOWS
		vector<CExprNode<V> *>::iterator it;
#else
		class vector<CExprNode<V> *>::iterator it;
#endif
		for (it=m_sons.begin();it!=m_sons.end();it++)
		{
			delete *it;
		}
	}

	///����һ�������ڵ�
	///@param	pSon	Ҫ���ӵĲ����ڵ�
	void addNode(CExprNode<V> *pSon)
	{
		m_sons.push_back(pSon);
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (getConstantFlag())
			return this->m_value;

		if ((m_paras==NULL)&&(m_sons.size()!=0))
		{
			m_paras=new V*[m_sons.size()];
		}
#ifdef WINDOWS
		vector<CExprNode<V> *>::iterator it;
#else
		class vector<CExprNode<V> *>::iterator it;
#endif
		int id=0;
		for (it=m_sons.begin();it!=m_sons.end();it++)
		{
			m_paras[id++]=&((*it)->eval(context));
		}
		if (!context.evalFunction(this->m_value,m_identifier,m_funcSeperator,m_sons.size(),m_paras))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval function %s",m_identifier->getValue());
		}
		return this->m_value;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		fprintf(output,"Function using %c:%s",m_funcSeperator,m_identifier->getValue());
		if (showValue)
		{
			fprintf(output,"(");
			this->m_value.display(output);
			fprintf(output,")");
		}
		fprintf(output,"\n");
#ifdef WINDOWS
		vector<CExprNode<V> *>::iterator it;
#else
		class vector<CExprNode<V> *>::iterator it;
#endif
		for (it=m_sons.begin();it!=m_sons.end();it++)
		{
			(*it)->display(showValue,output,indent+1);
		}
	}
};

/////////////////////////////////////////////////////////////////////////
///CHighLevelFunctionExprNode������һ���߽׺����ı��ʽ�ڵ��ģ���࣬ģ��������CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CHighLevelFunctionExprNode: public CExprNode<V>
{
protected:
	///ʹ�õĺ����������ýڵ�
	CExprNode<V> *m_func;
	
	///ָ�����е��ӽڵ�
	vector<CExprNode<V> *> m_sons;

	///�����ָ���
	char m_funcSeperator;

	V *m_funcValue;

	///ָ�����в�����ֵ
	V** m_paras;

public:
	///���췽��
	///���췽��
	///@param	func	ʹ�õĺ������ü���ڵ�
	///@param	funcSeperator	ʹ�õĺ����ָ���
	///@param	lineNo	�к�
	///@param	columnNo	�к�
	CHighLevelFunctionExprNode(CExprNode<V> *func,char funcSeperator,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_paras=NULL;
		m_func=func;
		m_funcSeperator=funcSeperator;
	}
	
	///��������
	virtual ~CHighLevelFunctionExprNode(void)
	{
		if (m_paras!=NULL)
		{
			delete m_paras;
		}

#ifdef WINDOWS
		vector<CExprNode<V> *>::iterator it;
#else
		class vector<CExprNode<V> *>::iterator it;
#endif
		for (it=m_sons.begin();it!=m_sons.end();it++)
		{
			delete *it;
		}
		delete m_func;
	}

	///����һ�������ڵ�
	///@param	pSon	Ҫ���ӵĲ����ڵ�
	void addNode(CExprNode<V> *pSon)
	{
		m_sons.push_back(pSon);
	}

	///���㱾�ڵ��ֵ
	///@param	context	����������
	///@return	��������ֵ
	///@exception	�������ʧ�ܣ����׳�CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (getConstantFlag())
			return this->m_value;

		if ((m_paras==NULL)&&(m_sons.size()!=0))
		{
			m_paras=new V*[m_sons.size()];
		}
#ifdef WINDOWS
		vector<CExprNode<V> *>::iterator it;
#else
		class vector<CExprNode<V> *>::iterator it;
#endif
		int id=0;
		for (it=m_sons.begin();it!=m_sons.end();it++)
		{
			m_paras[id++]=&((*it)->eval(context));
		}
		m_funcValue=&(m_func->eval(context));
		if (!context.evalFunction(this->m_value,*m_funcValue,m_funcSeperator,m_sons.size(),m_paras))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval function");
		}
		return this->m_value;
	}

	///�����ڵ�������ļ�
	///@param	showValue	�Ƿ�Ҫ���ֵ
	///@param	output	Ҫ������ļ�
	///@param	indent	����������
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		fprintf(output,"High Level Function using %c:",m_funcSeperator);
		if (showValue)
		{
			fprintf(output,"(");
			this->m_value.display(output);
			fprintf(output,")");
		}
		fprintf(output,"\n");
		m_func->display(showValue,output,indent+1);
#ifdef WINDOWS
		vector<CExprNode<V> *>::iterator it;
#else
		class vector<CExprNode<V> *>::iterator it;
#endif
		for (it=m_sons.begin();it!=m_sons.end();it++)
		{
			(*it)->display(showValue,output,indent+1);
		}
	}
};

#endif
