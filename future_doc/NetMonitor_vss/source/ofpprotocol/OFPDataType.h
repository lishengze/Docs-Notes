//**********************************************************************
//系统名：消息总线系统
//公司名：上海期货交易所
//文件名：OFPDataType.h
//主要功能:定义了OFP的若干底层支持类，以及相关的宏
//修改历史：
//20020315	王肇东		创建该文件
//20020515	宫耀东		增加getString方法
//**********************************************************************

#ifndef OFPDATATYPE_H
#define OFPDATATYPE_H

#include "UFDataType.h"

///COFPCharType就是CUFCharType
typedef CUFCharType COFPCharType;

///COFPNullStringType就是CUFStringType
#define COFPNullStringType CUFStringType

/////////////////////////////////////////////////////////////////////////
///COFPStringType<int length>是一个OFP中字符串处理的模版类，通过指定长度，可以
///得到真正可以使用的类。COFPStringType<int length>实质上就是根据长度，直接保存
///各个字符串，左对齐，不在最后加'\0'，而是对于空余的部分加空格。
///@author	王肇东
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
template <int length> class COFPStringType
{
public:
	///构造函数
	COFPStringType(void)
	{
		clear();
	}

	///复制构造子
	///@param	s	构造的源对象
	COFPStringType(const COFPStringType<length>& s)
	{
		setValue(s.getValue());
	}

	///复制构造子
	///@param	p	构造的源对象
	COFPStringType(const char *p)
	{
		setValue(p);
	}

	///等于操作符
	///@param	s	等于的值
	///@return	输入的值
	const COFPStringType & operator =(const COFPStringType<length>& s)
	{
		setValue(s.getValue());
		return s;
	}

	///等于操作符，从字符串中获取
	///@param	p	等于的字符串
	///@return	输入的字符串
	const char * operator =(const char *p)
	{
		setValue(p);
		return p;
	}

	///清除字符串内容
	void clear(void)
	{
		memset(buffer,' ',length);
	}

	///获取字符串的值
	///@return	字符串的值
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

	///设置字符串的值
	///@param	s	要设置的字符串
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

	///判断是否为空
	///@return	true表示为空，false表示不为空
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

	///转化为字符串
	///@return	得到的字符串
	operator const char *(void) const
	{
		return getValue();
	}

	///判断是否等于某个字符串
	///@param	r	右边项
	///@return	true表示是，false表示否
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
	///存储字符串的值
	char buffer[length];
};

//**********************************************************************
//COFPNumberType<int length>是一个OFP中文字化整数处理的模版类，通过指定长度，可以
//得到真正可以使用的类。COFPNUmberType<int length>实质上就是根据长度，直接保存
//各个整数变成的文字，右对齐，不在最后加'\0'，而是对于空余的部分加空格。
//@作者	王肇东
//@版本	1.0,20020315
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
	
	//清除内容，实质上就是设为0
	void clear(void)
	{
		char temp[length+1];
		sprintf(temp,"%*d",length,0);
		memcpy(this->buffer,temp,length);
	}
	
	//获取值
	//@返回	所包含的值
	int getValue(void)
	{
		char temp[length+1];
		memcpy(temp,this->buffer,length);
		temp[length]='\0';
		return atoi(temp);
	}
	
	//设置值
	//@参数	v	要设置的值
	void setValue(int v)
	{
		char temp[length+1];
		sprintf(temp,"%0*d",length,v);
		memcpy(this->buffer,temp,length);
	}

	//设置二进制值
	//@参数	v	要设置的值，将ASCII码编号为v/100和v%100的值赋给buffer的前两个字节
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
//COFPFloatType是一个OFP中文字化浮点数处理的模版类，其长度和精度固定为15和2。
//COFPNFloatType，直接保存各个浮点数变成的文字，右对齐，不在最后加'\0'，而是对于
//空余的部分加空格。
//@作者	王肇东
//@版本	1.0,20020315
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
	
	//清除值，就是设为0.0
	void clear(void)
	{
		char temp[15+1];
		sprintf(temp,"%*.*f",15,2,0.0);
		memcpy(this->buffer,temp,15);
	}
	
	//获取值
	//@返回	所包含的值
	double getValue(void)
	{
		char temp[15+1];
		memcpy(temp,this->buffer,15);
		temp[15]='\0';
		return atof(temp);
	}
	
	//设置值
	//@参数	所要设置的值
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
