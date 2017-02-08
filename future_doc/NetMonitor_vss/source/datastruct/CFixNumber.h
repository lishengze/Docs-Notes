/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CFixNumber.h
///@brief����������
///@history 
///20050811	�ż���		�������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef _FIX_NUMBER_H
#define _FIX_NUMBER_H
#include "CBaseObject.h"
//#include "ErrorHandle.h"
#include "UFDataType.h"
#include <string>
#include <vector>
using namespace std;


/////////////////////////////////////////////////////////////////////////
///CFixNumberImpl��һ����������ľ���ʵ�֡�����ඨ����һ�����ڶ���������Ĳ�����ͬʱ
///��������Ӧ�ļ��ķ�����
///@author	�ż���
///@version	1.0,20050811
/////////////////////////////////////////////////////////////////////////

class CFixNumberImpl;
CFixNumberImpl operator+(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);
CFixNumberImpl operator-(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);
CFixNumberImpl operator*(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);
CFixNumberImpl operator/(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);

class CFixNumberImpl:public CBaseObject
{
friend CFixNumberImpl operator+(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);
friend CFixNumberImpl operator-(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);
friend CFixNumberImpl operator*(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);
friend CFixNumberImpl operator/(const CFixNumberImpl& leftValue,const CFixNumberImpl& rightValue);

public:
	///ȱ��Ĺ��캯��
	CFixNumberImpl();		
	///���ݴ�����ַ�������
	CFixNumberImpl(char *szNumber,int length); 
	///���ݴ����String����
	CFixNumberImpl(string strNumber,int length);
	///���ݴ����ֵ,����ָ������
	CFixNumberImpl(double dbValue,int precision,int length);
	///���ݴ����ֵ,����ָ������
	CFixNumberImpl(float fValue,int precision,int length);
	///���ݴ����ֵ,����ָ������
	CFixNumberImpl(int intValue,int precision,int length);

	///Copy Constructor
	CFixNumberImpl(const CFixNumberImpl& rValue);

	///operator =
	CFixNumberImpl& operator=(const CFixNumberImpl& rightValue);

	///�ж�һ������������Ƿ����ָ���Ķ������͡��ú�����һ���麯���������̳�
	///����Ҫ���¶�������������ڼ���������ʱ����ʹobjectType���ϱ������
	///ĳ�������࣬Ҳ��Ϊ����ȷ�ģ���Ϊ��Ϊ�̳��࣬��Ҳ���������һ�֡�
	virtual int isA(char *objectType);

	///������������������Ҫ���ڵ��ԡ��ú�����һ���麯���������̳���
	///��Ҫ���¶���ú�����
	///@param	pLogger	���������
	///@param	indent	������
	virtual void output(CLogger *pLogger,int indent=0);

	///���ر�ʾ���������͵��ַ�����һ����Ǳ�������������ú�����һ���麯����
	///�����̳�����Ҫ���¶���ú�����
	///@return	��ʾ���������͵��ַ���
	virtual char *getType(void);

	///�����������Ϊһ��string	
	string toString();
	
	///���þ���
	void setPrecision(int precision);

	///װ����Double
	double toDouble(){
		return m_dValue;
	}

private:
	///��ʼ������,
	///@param	strNumber	������ַ���
	void initData(string strNumber);
	void initString(string str);

private:
	int m_precision;			//���澫��
	int m_nLength;				//���ֵ���󳤶�
	vector<int>	m_numbervect;	//�����б�
	bool m_bIsPositive;			//�Ƿ�Ϊ��,true:�� false:����
	double m_dValue;			//�����ֵ,�������˷��ͳ���
};




/////////////////////////////////////////////////////////////////////////
///CFixNumber��һ����������ġ�����ඨ����һ�����ڶ���������Ĳ�����ͬʱ
///��������Ӧ�ļ��ķ�����ģ������ƶ����������ֵľ���.
///@author	�ż���
///@version	1.0,20050811
/////////////////////////////////////////////////////////////////////////

template<int length,int precision>
class CFixNumber
{
public:
	CFixNumber():m_fixNumberImpl(0.00,precision){};
	CFixNumber(double dValue):m_fixNumberImpl(dValue,precision,length){m_strNumber=m_fixNumberImpl.toString().c_str();}
	CFixNumber(int intValue):m_fixNumberImpl(intValue,precision,length){m_strNumber=m_fixNumberImpl.toString().c_str();}
	CFixNumber(float fValue):m_fixNumberImpl(fValue,precision,length){m_strNumber=m_fixNumberImpl.toString().c_str();}
	CFixNumber(string strValue):m_fixNumberImpl(strValue,length){
		m_fixNumberImpl.setPrecision(precision);
		m_strNumber=m_fixNumberImpl.toString().c_str();
	}
	CFixNumber(char *szValue):m_fixNumberImpl(szValue,length){
		m_fixNumberImpl.setPrecision(precision);
		m_strNumber=m_fixNumberImpl.toString().c_str();
	}

	CFixNumber<length,precision> operator+(const CFixNumber<length,precision>& value)
	{
		CFixNumberImpl temp1(m_strNumber,precision);
		CFixNumberImpl temp2(value.m_strNumber,precision);
		CFixNumberImpl result =  temp1 + temp2;		
		CFixNumber<length,precision> value1(result);
		return value1;
	}
	
	CFixNumber<length,precision> operator-(const CFixNumber<length,precision>& value)
	{
		CFixNumberImpl temp1(m_strNumber,precision);
		CFixNumberImpl temp2(value.m_strNumber,precision);
		CFixNumberImpl result =  temp1 - temp2;		
		CFixNumber<length,precision> value1(result);
		return value1;
	}

	/*CFixNumber<precision*2> operator*(const CFixNumber<precision>& value)
	{
		CFixNumberImpl result = m_fixNumberImpl*value.m_fixNumberImpl;		
		CFixNumber<precision*2> value1(result);
		return value1;
	}*/

	template<int length2,int precision2>
	CFixNumber<length+length2,precision+precision2> operator*(const CFixNumber<length2,precision2>& value)
	{
		CFixNumberImpl result = m_fixNumberImpl*value.m_fixNumberImpl;		
		CFixNumber<length+length2,precision+precision2> value1(result);
		return value1;
	}

	template<int length2,int precision2>
	CFixNumber<length,precision> operator/(const CFixNumber<length2,precision2>& value)
	{
		CFixNumberImpl result = m_fixNumberImpl/value.m_fixNumberImpl;		
		CFixNumber<length,precision> value1(result);
		return value1;
	}

	///�����������Ϊһ��string	
	string toString() const {
		return string(m_strNumber.getValue());
	}

	double toDouble() const {
		CFixNumberImpl temp(m_strNumber.getValue(),precision);
		return temp.toDouble();
	}

	CFixNumber(CFixNumberImpl& value):m_fixNumberImpl(value){m_fixNumberImpl.setPrecision(precision);}	
	CFixNumber(const CFixNumber<length,precision>& value){
		m_fixNumberImpl = CFixNumberImpl(value.toDouble(),precision,length);
		m_strNumber = value.toString().c_str();
	}

	template<int length2,int precision2>
	CFixNumber<length,precision>& operator=(const CFixNumber<length2,precision2>& value)
	{
		m_fixNumberImpl = CFixNumberImpl(value.toDouble(),precision,length);
		m_strNumber = value.toString().c_str();
		return *this;
	}
private:
	CFixNumberImpl m_fixNumberImpl;
	CUFStringType<length> m_strNumber;
};

#endif
