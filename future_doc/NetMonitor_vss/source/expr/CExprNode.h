/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file CExprNode.h
///@brief	定义了表达式节点
///@history 
///20080329	王肇东		创建该文件
///20080624 周建军		修改模板类和迭代器定义,在g++中模板类中的迭代器
///						定义需要增加类型定义说明
/////////////////////////////////////////////////////////////////////////

#ifndef CEXPR_NODE_H
#define CEXPR_NODE_H

#include "CBaseValue.h"
#include "CBaseContext.h"
#include "CExprException.h"

/////////////////////////////////////////////////////////////////////////
///CExprNode定义了一个表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CExprNode
{
protected:
	///本节点的值，其定义随着各个子类而不同
	V m_value;
	
	///本节点的行号和列号，用于在报错时定位
	int m_lineNo,m_columnNo;

	///输出前导空白
	///@param	output	要输出的文件
	///@param	count	要输出的个数
	void displayTABs(FILE *output,int count)
	{
		for (int i=0;i<count;i++)
		{
			fprintf(output,"\t");
		}
	}

public:
	///构造方法
	///@param	lineNo	行号
	///@param	columnNo	列号
	CExprNode(int lineNo, int columnNo)
	{
		m_lineNo=lineNo;
		m_columnNo=columnNo;
	}
	
	///析构方法
	virtual ~CExprNode(void)
	{
	}

	bool getConstantFlag(void)
	{
		return m_value.getConstantFlag();
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
	virtual V& eval(CBaseContext<V> &context)=0;
	
	///设置行号和列号
	///@param	lineNo	行号
	///@param	columnNo	列号
	virtual void setLineColumnNo(int lineNo, int columnNo)
	{
		m_lineNo=lineNo;
		m_columnNo=columnNo;
	}
	
	///获取行号和列号
	///@param	lineNo	返回的行号
	///@param	columnNo	返回的列号
	virtual void getLineColumnNo(int& lineNo, int& columnNo)
	{
		lineNo=m_lineNo;
		columnNo=m_columnNo;
	}

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)=0;
};

/////////////////////////////////////////////////////////////////////////
///CConstantExprNode定义了一个常数的表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CConstantExprNode: public CExprNode<V>
{
public:
	///构造方法
	///@param	value	要设置的值
	///@param	lineNo	行号
	///@param	columnNo	列号
	CConstantExprNode(V &value,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		this->m_value=value;
		this->m_value.setConstantFlag(true);
	}
	
	///析构方法
	virtual ~CConstantExprNode(void)
	{
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		return this->m_value;
	}

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
	virtual void display(bool showValue=false,FILE *output=stdout, int indent=0)
	{
		displayTABs(output,indent);
		this->m_value.display(output);
		fprintf(output,"\n");
	}
};

/////////////////////////////////////////////////////////////////////////
///CIdentifierExprNode定义了一个标识符的表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CIdentifierExprNode: public CExprNode<V>
{
protected:
	///使用的标识符
	CRefStringPtr m_identifier;
	
public:
	///构造方法
	///@param	identifier	使用的标识符
	///@param	lineNo	行号
	///@param	columnNo	列号
	CIdentifierExprNode(CRefStringPtr &identifier,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_identifier=identifier;
	}
	
	///析构方法
	virtual ~CIdentifierExprNode(void)
	{
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (!getConstantFlag() && !context.getIdentifierValue(this->m_value,m_identifier))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval identifier %s",m_identifier->getValue());
		}
		return this->m_value;
	}

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
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
///CKeywordExprNode定义了一个关键词的表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CKeywordExprNode: public CExprNode<V>
{
protected:
	///使用的标识符
	const char *m_keyword;
	
public:
	///构造方法
	///@param	identifier	使用的关键词
	///@param	lineNo	行号
	///@param	columnNo	列号
	CKeywordExprNode(const char *keyword,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_keyword=keyword;
	}
	
	///析构方法
	virtual ~CKeywordExprNode(void)
	{
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
	virtual V& eval(CBaseContext<V> &context)
	{
		if (!getConstantFlag() && !context.getKeywordValue(this->m_value,m_keyword))
		{
			throw new CExprException(this->m_lineNo,this->m_columnNo,"Can not eval keyword %s",m_keyword);
		}
		return this->m_value;
	}

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
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
///CUniOperatorExprNode定义了一个单目运算符的表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CUniOperatorExprNode: public CExprNode<V>
{
protected:
	///使用的单目运算符
	const char *m_operator;
	
	///指向子节点
	CExprNode<V> *m_son;

public:
	///构造方法
	///@param	thisOperator	使用的标识符
	///@param	pSon	使用的子节点
	///@param	lineNo	行号
	///@param	columnNo	列号
	CUniOperatorExprNode(const char *thisOperator, CExprNode<V> *pSon,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_operator=thisOperator;
		m_son=pSon;
	}
	
	///析构方法
	virtual ~CUniOperatorExprNode(void)
	{
		delete m_son;
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
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

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
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
///CBiOperatorExprNode定义了一个双目运算符的表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CBiOperatorExprNode: public CExprNode<V>
{
protected:
	///使用的单目运算符
	const char *m_operator;
	
	///指向的两个子节点
	CExprNode<V> *m_son1,*m_son2;

public:
	///构造方法
	///构造方法
	///@param	thisOperator	使用的标识符
	///@param	pSon1	使用的子节点1
	///@param	pSon2	使用的子节点2
	///@param	lineNo	行号
	///@param	columnNo	列号
	CBiOperatorExprNode(const char *thisOperator, CExprNode<V> *pSon1, CExprNode<V> *pSon2,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_operator=thisOperator;
		m_son1=pSon1;
		m_son2=pSon2;
	}
	
	///析构方法
	virtual ~CBiOperatorExprNode(void)
	{
		delete m_son1;
		delete m_son2;
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
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

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
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
///CIdentifierFunctionExprNode定义了一个标识符函数的表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CIdentifierFunctionExprNode: public CExprNode<V>
{
protected:
	///使用的函数标识符
	CRefStringPtr m_identifier;
	
	///指向所有的子节点
	vector<CExprNode<V> *> m_sons;

	///函数分隔符
	char m_funcSeperator;

	///指向所有参数的值
	V** m_paras;

public:
	///构造方法
	///构造方法
	///@param	identifier	使用的标识符
	///@param	funcSeperator	使用的函数分隔符
	///@param	lineNo	行号
	///@param	columnNo	列号
	CIdentifierFunctionExprNode(CRefStringPtr &identifier,char funcSeperator,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_paras=NULL;
		m_identifier=identifier;
		m_funcSeperator=funcSeperator;
	}
	
	///析构方法
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

	///增加一个参数节点
	///@param	pSon	要增加的参数节点
	void addNode(CExprNode<V> *pSon)
	{
		m_sons.push_back(pSon);
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
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

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
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
///CHighLevelFunctionExprNode定义了一个高阶函数的表达式节点的模板类，模板必须基于CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CHighLevelFunctionExprNode: public CExprNode<V>
{
protected:
	///使用的函数计算引用节点
	CExprNode<V> *m_func;
	
	///指向所有的子节点
	vector<CExprNode<V> *> m_sons;

	///函数分隔符
	char m_funcSeperator;

	V *m_funcValue;

	///指向所有参数的值
	V** m_paras;

public:
	///构造方法
	///构造方法
	///@param	func	使用的函数引用计算节点
	///@param	funcSeperator	使用的函数分隔符
	///@param	lineNo	行号
	///@param	columnNo	列号
	CHighLevelFunctionExprNode(CExprNode<V> *func,char funcSeperator,int lineNo, int columnNo):
	  CExprNode<V>(lineNo,columnNo)
	{
		m_paras=NULL;
		m_func=func;
		m_funcSeperator=funcSeperator;
	}
	
	///析构方法
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

	///增加一个参数节点
	///@param	pSon	要增加的参数节点
	void addNode(CExprNode<V> *pSon)
	{
		m_sons.push_back(pSon);
	}

	///计算本节点的值
	///@param	context	计算上下文
	///@return	计算结果的值
	///@exception	如果计算失败，则抛出CExprException
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

	///将本节点输出到文件
	///@param	showValue	是否要输出值
	///@param	output	要输出的文件
	///@param	indent	缩进的数量
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
