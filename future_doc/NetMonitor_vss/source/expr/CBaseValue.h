/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CBaseValue.h
///@brief	������һ��ֵ�Ļ���
///@history 
///20080329	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CBASE_VALUE_H
#define CBASE_VALUE_H

#include "RefString.h"

#define NO_VALUE 0

/////////////////////////////////////////////////////////////////////////
///CBaseValue������һ��˵��һ��ֵ�ĳ�����
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
class CBaseValue
{
protected:
	///ֵ�����ͣ�NO_VALUE��ʾ��ֵ��������ʹ���߶���
	int m_valueType;

	///ֵ�ľ�̬��ʶ
	bool m_bConstant;

public:
	///���췽����ע�⣬������뱣֤�޲����Ĺ��췽������
	CBaseValue(void)
	{
		m_valueType=NO_VALUE;
		m_bConstant = false;
	}
	
	///��������
	virtual ~CBaseValue(void)
	{
	}

	///��ȡֵ����
	///@return	ֵ����
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

	///����һ����������
	///@param	value	Ҫ���õ�ֵ
	///@return	true��ʾ���óɹ���false��ʾ����ʧ��
	virtual bool setIntegerConstant(int value)
	{
		return false;
	}

	///����һ�����㳣��
	///@param	value	Ҫ���õ�ֵ
	///@return	true��ʾ���óɹ���false��ʾ����ʧ��
	virtual bool setFloatConstant(double value)
	{
		return false;
	}

	///����һ���ַ�������
	///@param	value	Ҫ���õ�ֵ
	///@return	true��ʾ���óɹ���false��ʾ����ʧ��
	virtual bool setStringConstant(const CRefStringPtr &value)
	{
		return false;
	}

	///����һ���ַ�����
	///@param	value	Ҫ���õ�ֵ
	///@return	true��ʾ���óɹ���false��ʾ����ʧ��
	virtual bool setCharConstant(char value)
	{
		return false;
	}

	///����һ���ؼ�������һ������
	///@param	value	Ҫ���õ�ֵ
	///@return	true��ʾ���óɹ���false��ʾ����ʧ��
	virtual bool setKeywordConstant(const char *value)
	{
		return false;
	}

	///����һ����ʶ������һ������
	///@param	value	Ҫ���õ�ֵ
	///@return	true��ʾ���óɹ���false��ʾ����ʧ��
	virtual bool setIdentifierConstant(const CRefStringPtr &value)
	{
		return false;
	}

	///����ֵ������ļ�
	///@param	output	Ҫ������ļ�
	virtual void display(FILE *output=stdout)
	{
	}
};

#endif
