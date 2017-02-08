/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CBaseContext.h
///@brief	������һ�����������ĵĻ���
///@history 
///20080329	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CBASE_CONTEXT_H
#define CBASE_CONTEXT_H

#include "RefString.h"

/////////////////////////////////////////////////////////////////////////
///CBaseContext������һ�����������ĵĳ����࣬ʹ�õ�ģ�����ֵ�࣬������
///CBaseValue������
///@author	���ض�
///@version	1.0,20090329
/////////////////////////////////////////////////////////////////////////
template <class V>
class CBaseContext
{
public:
	virtual ~CBaseContext(void)
	{
	}

	///��ȡһ����ʶ����Ӧ��ֵ
	///@param	result	���ý����ֵ
	///@param	identifier	Ҫ����ı�ʶ��
	///@return	true��ʾȡֵ�ɹ���false��ʾȡֵʧ��
	virtual bool getIdentifierValue(V &result, const CRefStringPtr &identifier)
	{
		return false;
	}

	///����һ���ؼ��ʶ�Ӧ��ֵ
	///@param	result	���ý����ֵ
	///@param	keyword	Ҫ����Ĺؼ���
	///@return	true��ʾ���óɹ���false��ʾ����ʧ��
	virtual bool getKeywordValue(V &result, const char *keyword)
	{
		return false;
	}

	///��ȡ��Ŀ�������ļ�����
	///@param	result	���ý����ֵ
	///@param	value	��Ŀ�����Ķ���ֵ
	///@param	thisOperator	ʹ�õĵ�Ŀ�����
	///@return	true��ʾ����ɹ���false��ʾ����ʧ��
	virtual bool getUniOperatorResult(V &result, V &value, const char *thisOperator)
	{
		return false;
	}

	///��ȡ˫Ŀ�������ļ�����
	///@param	result	���ý����ֵ
	///@param	value1	˫Ŀ�����Ķ���ֵ1
	///@param	thisOperator	ʹ�õ�˫Ŀ�����
	///@param	value1	˫Ŀ�����Ķ���ֵ2
	///@return	true��ʾ����ɹ���false��ʾ����ʧ��
	virtual bool getBiOperatorResult(V &result, V &value1, const char *thisOperator, V &value2)
	{
		return false;
	}
	
	///���㺯����ֵ������ʹ�ñ�ʶ����ע�⣬Ҳ����������������
	///@param	result	���ý����ֵ
	///@param	identifier	���������Ʊ�ʶ��
	///@param	funcSeperator	���������ķָ����ĵ�һ����һ����'('��'['�����
	///@param	paraCount	�����ĸ���
	///@param	paraList	�����嵥��
	virtual bool evalFunction(V &result, const CRefStringPtr &identifier, char funcSeperator, int paraCount, V** paraList)
	{
		return false;
	}

	///���㺯����ֵ������ʹ��ֵ��ע�⣬Ҳ����������������
	///@param	result	���ý����ֵ
	///@param	funcValue	��ֵ��ʽ��ʶ�ĺ���
	///@param	funcSeperator	���������ķָ����ĵ�һ����һ����'('��'['�����
	///@param	paraCount	�����ĸ���
	///@param	paraList	�����嵥��
	virtual bool evalFunction(V &result, V &funcValue, char funcSeperator, int paraCount, V** paraList)
	{
		return false;
	}
};

#endif
