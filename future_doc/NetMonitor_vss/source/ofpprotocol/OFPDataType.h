//**********************************************************************
//ϵͳ������Ϣ����ϵͳ
//��˾�����Ϻ��ڻ�������
//�ļ�����OFPDataType.h
//��Ҫ����:������OFP�����ɵײ�֧���࣬�Լ���صĺ�
//�޸���ʷ��
//20020315	���ض�		�������ļ�
//20020515	��ҫ��		����getString����
//**********************************************************************

#ifndef OFPDATATYPE_H
#define OFPDATATYPE_H

#include "UFDataType.h"

///COFPCharType����CUFCharType
typedef CUFCharType COFPCharType;

///COFPNullStringType����CUFStringType
#define COFPNullStringType CUFStringType

/////////////////////////////////////////////////////////////////////////
///COFPStringType<int length>��һ��OFP���ַ��������ģ���࣬ͨ��ָ�����ȣ�����
///�õ���������ʹ�õ��ࡣCOFPStringType<int length>ʵ���Ͼ��Ǹ��ݳ��ȣ�ֱ�ӱ���
///�����ַ���������룬��������'\0'�����Ƕ��ڿ���Ĳ��ּӿո�
///@author	���ض�
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
template <int length> class COFPStringType
{
public:
	///���캯��
	COFPStringType(void)
	{
		clear();
	}

	///���ƹ�����
	///@param	s	�����Դ����
	COFPStringType(const COFPStringType<length>& s)
	{
		setValue(s.getValue());
	}

	///���ƹ�����
	///@param	p	�����Դ����
	COFPStringType(const char *p)
	{
		setValue(p);
	}

	///���ڲ�����
	///@param	s	���ڵ�ֵ
	///@return	�����ֵ
	const COFPStringType & operator =(const COFPStringType<length>& s)
	{
		setValue(s.getValue());
		return s;
	}

	///���ڲ����������ַ����л�ȡ
	///@param	p	���ڵ��ַ���
	///@return	������ַ���
	const char * operator =(const char *p)
	{
		setValue(p);
		return p;
	}

	///����ַ�������
	void clear(void)
	{
		memset(buffer,' ',length);
	}

	///��ȡ�ַ�����ֵ
	///@return	�ַ�����ֵ
	const char *getValue(void) const
	{
		static char temp[length+1];
		
		memcpy(temp, buffer, length);
		temp[length] = '\0';
		char *p = temp+length-1;
		while (p >= temp)
		{
			if (*p != ' ')
			{
				break;
			}
			*p = '\0';
			p--;
		}
		return temp;
	}

	///�����ַ�����ֵ
	///@param	s	Ҫ���õ��ַ���
	void setValue(const char *s)
	{
		const char *source  = s;
		char *target = buffer;
		int i = 0;
		for (; i< length; i++)
		{
			if (*source == '\0')
			{
				break;
			}
			*target = *source;
			target++;
			source++;
		}

		for (; i<length; i++)
		{
			*target = ' ';
			target++;
		}
	}

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{		
		int i;		
		for(i=0;i<length;i++)
		{
			if (buffer[i]!=' ')
				return false;
		}		
		return true;
	}

	///ת��Ϊ�ַ���
	///@return	�õ����ַ���
	operator const char *(void) const
	{
		return getValue();
	}

	///�ж��Ƿ����ĳ���ַ���
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator == (const char *r) const
	{
		return strcmp(buffer, r)==0;
	}

	void getString(char *target) const
	{
		memcpy(target,buffer,length);
		target[length]='\0';
	}

protected:
	///�洢�ַ�����ֵ
	char buffer[length];
};

//**********************************************************************
//COFPNumberType<int length>��һ��OFP�����ֻ����������ģ���࣬ͨ��ָ�����ȣ�����
//�õ���������ʹ�õ��ࡣCOFPNUmberType<int length>ʵ���Ͼ��Ǹ��ݳ��ȣ�ֱ�ӱ���
//����������ɵ����֣��Ҷ��룬��������'\0'�����Ƕ��ڿ���Ĳ��ּӿո�
//@����	���ض�
//@�汾	1.0,20020315
//**********************************************************************
template <int length> class COFPNumberType : public COFPStringType<length>
{
public:
	COFPNumberType()
	{
		clear();
	}

	COFPNumberType(int v)
	{
		setValue(v);
	}
	
	//������ݣ�ʵ���Ͼ�����Ϊ0
	void clear(void)
	{
		char temp[length+1];
		sprintf(temp,"%*d",length,0);
		memcpy(this->buffer,temp,length);
	}
	
	//��ȡֵ
	//@����	��������ֵ
	int getValue(void)
	{
		char temp[length+1];
		memcpy(temp,this->buffer,length);
		temp[length]='\0';
		return atoi(temp);
	}
	
	//����ֵ
	//@����	v	Ҫ���õ�ֵ
	void setValue(int v)
	{
		char temp[length+1];
		sprintf(temp,"%0*d",length,v);
		memcpy(this->buffer,temp,length);
	}

	//���ö�����ֵ
	//@����	v	Ҫ���õ�ֵ����ASCII����Ϊv/100��v%100��ֵ����buffer��ǰ�����ֽ�
	void setValueBinary(int v)
	{
		char temp[length];
		memset(temp,0,length);
		temp[0] = (char)(v/100);
		temp[1] = (char)(v%100);
		memcpy(this->buffer,temp,length);
	}

	operator const int (void)
	{
		return getValue();
	}
};

//**********************************************************************
//COFPFloatType��һ��OFP�����ֻ������������ģ���࣬�䳤�Ⱥ;��ȹ̶�Ϊ15��2��
//COFPNFloatType��ֱ�ӱ��������������ɵ����֣��Ҷ��룬��������'\0'�����Ƕ���
//����Ĳ��ּӿո�
//@����	���ض�
//@�汾	1.0,20020315
//**********************************************************************
class COFPFloatType : public COFPStringType<15>
{
public:
	COFPFloatType()
	{
		clear();
	}

	COFPFloatType(double v)
	{
		setValue(v);
	}
	
	//���ֵ��������Ϊ0.0
	void clear(void)
	{
		char temp[15+1];
		sprintf(temp,"%*.*f",15,2,0.0);
		memcpy(this->buffer,temp,15);
	}
	
	//��ȡֵ
	//@����	��������ֵ
	double getValue(void)
	{
		char temp[15+1];
		memcpy(temp,this->buffer,15);
		temp[15]='\0';
		return atof(temp);
	}
	
	//����ֵ
	//@����	��Ҫ���õ�ֵ
	void setValue(double v)
	{
		char temp[15+1];
		sprintf(temp,"%*.*f",15,2,v);
		memcpy(buffer,temp,15);
	}

	operator const double (void)
	{
		return getValue();
	}
};

#endif
