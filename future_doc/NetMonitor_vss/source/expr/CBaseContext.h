/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file CBaseContext.h
///@brief	定义了一个计算上下文的基类
///@history 
///20080329	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef CBASE_CONTEXT_H
#define CBASE_CONTEXT_H

#include "RefString.h"

/////////////////////////////////////////////////////////////////////////
///CBaseContext定义了一个计算上下文的抽象类，使用的模板基于值类，必须是
///CBaseValue的子类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CBaseContext
{
public:
	virtual ~CBaseContext(void)
	{
	}

	///获取一个标识符对应的值
	///@param	result	放置结果的值
	///@param	identifier	要计算的标识符
	///@return	true表示取值成功，false表示取值失败
	virtual bool getIdentifierValue(V &result, const CRefStringPtr &identifier)
	{
		return false;
	}

	///根据一个关键词对应的值
	///@param	result	放置结果的值
	///@param	keyword	要计算的关键词
	///@return	true表示设置成功，false表示设置失败
	virtual bool getKeywordValue(V &result, const char *keyword)
	{
		return false;
	}

	///获取单目操作符的计算结果
	///@param	result	放置结果的值
	///@param	value	单目操作的对象值
	///@param	thisOperator	使用的单目运算符
	///@return	true表示计算成功，false表示计算失败
	virtual bool getUniOperatorResult(V &result, V &value, const char *thisOperator)
	{
		return false;
	}

	///获取双目操作符的计算结果
	///@param	result	放置结果的值
	///@param	value1	双目操作的对象值1
	///@param	thisOperator	使用的双目运算符
	///@param	value1	双目操作的对象值2
	///@return	true表示计算成功，false表示计算失败
	virtual bool getBiOperatorResult(V &result, V &value1, const char *thisOperator, V &value2)
	{
		return false;
	}
	
	///计算函数的值，函数使用标识符（注意，也可能是数组等情况）
	///@param	result	放置结果的值
	///@param	identifier	函数的名称标识符
	///@param	funcSeperator	函数参数的分隔符的第一个，一般是'('、'['等情况
	///@param	paraCount	参数的个数
	///@param	paraList	参数清单，
	virtual bool evalFunction(V &result, const CRefStringPtr &identifier, char funcSeperator, int paraCount, V** paraList)
	{
		return false;
	}

	///计算函数的值，函数使用值（注意，也可能是数组等情况）
	///@param	result	放置结果的值
	///@param	funcValue	以值方式标识的函数
	///@param	funcSeperator	函数参数的分隔符的第一个，一般是'('、'['等情况
	///@param	paraCount	参数的个数
	///@param	paraList	参数清单，
	virtual bool evalFunction(V &result, V &funcValue, char funcSeperator, int paraCount, V** paraList)
	{
		return false;
	}
};

#endif
