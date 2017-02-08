/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file CBaseValue.h
///@brief	定义了一个值的基类
///@history 
///20080329	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef CBASE_VALUE_H
#define CBASE_VALUE_H

#include "RefString.h"

#define NO_VALUE 0

/////////////////////////////////////////////////////////////////////////
///CBaseValue定义了一个说明一个值的抽象类
///@author	王肇东
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
class CBaseValue
{
protected:
	///值的类型，NO_VALUE表示无值，其他由使用者定义
	int m_valueType;

	///值的静态标识
	bool m_bConstant;

public:
	///构造方法，注意，子类必须保证无参数的构造方法存在
	CBaseValue(void)
	{
		m_valueType=NO_VALUE;
		m_bConstant = false;
	}
	
	///析构方法
	virtual ~CBaseValue(void)
	{
	}

	///获取值类型
	///@return	值类型
	int getValueType(void)
	{
		return m_valueType;
	}
	
	bool getConstantFlag(void)
	{
		return m_bConstant;
	}

	void setConstantFlag(bool bFlag)
	{
		m_bConstant = bFlag;
	}

	///设置一个整数常数
	///@param	value	要设置的值
	///@return	true表示设置成功，false表示设置失败
	virtual bool setIntegerConstant(int value)
	{
		return false;
	}

	///设置一个浮点常数
	///@param	value	要设置的值
	///@return	true表示设置成功，false表示设置失败
	virtual bool setFloatConstant(double value)
	{
		return false;
	}

	///设置一个字符串常数
	///@param	value	要设置的值
	///@return	true表示设置成功，false表示设置失败
	virtual bool setStringConstant(const CRefStringPtr &value)
	{
		return false;
	}

	///设置一个字符常数
	///@param	value	要设置的值
	///@return	true表示设置成功，false表示设置失败
	virtual bool setCharConstant(char value)
	{
		return false;
	}

	///根据一个关键词设置一个常数
	///@param	value	要设置的值
	///@return	true表示设置成功，false表示设置失败
	virtual bool setKeywordConstant(const char *value)
	{
		return false;
	}

	///根据一个标识符设置一个常数
	///@param	value	要设置的值
	///@return	true表示设置成功，false表示设置失败
	virtual bool setIdentifierConstant(const CRefStringPtr &value)
	{
		return false;
	}

	///将本值输出到文件
	///@param	output	要输出的文件
	virtual void display(FILE *output=stdout)
	{
	}
};

#endif
