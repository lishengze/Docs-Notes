/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file UFDataType.h
///@brief�����˽������ڲ����ݵĵײ�֧����
///@history 
///20020214	���ض�		�������ļ�
///20020309	���ض�		�޸Ĵ��ļ���֧�ָ���ReadOnly����
///20020330 ��ҫ��		��ÿ�����������м���getString(char *)�ķ���
///20020410 ��ҫ��		��ÿ�����������м���isNull�ķ���
///20020410 ��ҫ��		����Լ��ֵ�����м���isVilid()����
///20060218	���ض�		�����޸��˽ṹ��ʹ���е�ReadOnly���;���const����
///20100903 ����        NT-0109-���˵��Ƿ�����ֵ
///20110519 ����        NT-0132�����������ƣ����Ӷ�64λ����֧��
///20110815 ����        �޸���pow�ĵ��÷�ʽ��֧�ָ߰汾��vc����
/////////////////////////////////////////////////////////////////////////

#ifndef UFDATATYPE_H
#define UFDATATYPE_H

#include "CBaseObject.h"
#include "utility.h"

class CUFBaseStringType
{
};

class CUFBaseIntType
{
};

class CUFBaseFloatType
{
};

class CUFBaseCharType
{
};

class CUFBaseWordType
{
};

class CUFBaseQWordType
{
};

///����һ����С�ĸ������������Ӧ����Ӱ����������ִ��ڸ��ม��������
#define SMALL_DOUBLE 0.000000001

/////////////////////////////////////////////////////////////////////////
///CUFStringType<int length>��һ�������ַ���ģ���࣬ͨ��ָ�����ȣ�
///���Եõ���������ʹ�õ��ࡣCUFStringType<int length>ʵ���Ͼ��Ǹ��ݳ��ȣ�
///ֱ�ӱ����ַ�����ֵ������룬����'\0'��
///@author	���ض�
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
template <int length> class CUFStringType: public CUFBaseStringType
{
public:
	///���캯��
	CUFStringType(void)
	{
		//buffer[0] = '\0';
	}

	///���ƹ�����
	///@param	s	�����Դ����
	CUFStringType(const CUFStringType<length>& s)
	{
		setValue(s.getValue());
	}

	///���ƹ�����
	///@param	p	�����Դ����
	CUFStringType(const char *p)
	{
		setValue(p);
	}

	///���ڲ�����
	///@param	s	���ڵ�ֵ
	///@return	�����ֵ
	const CUFStringType & operator =(const CUFStringType<length>& s)
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

	///���ڲ��������������л�ȡ
	///@param	v	���ڵ�����
	///@return	���������
	const int operator =(const int v)
	{
		char tmp[100];
		sprintf(tmp,"%*d",length,v);
		setValue(tmp);
		return v;
	}

	///����ַ�������
	void clear(void)
	{
		buffer[0]='\0';
	}

	///��ȡ�ַ�����ֵ
	///@return	�ַ�����ֵ
	const char *getValue(void) const
	{
		return buffer;
	}

	///�����ַ�����ֵ
	///@param	s	Ҫ���õ��ַ���
	void setValue(const char *s)
	{
		if (s==NULL)
			buffer[0]='\0';
		else
		{
			strncpy(buffer,s,length);
			buffer[length]='\0';
		}
	}

	///��strBuf�еõ������͵��ַ�����ʾ	
	///@param	strBuf	���ڷ��ý�����ַ���
	void getString(char *strBuf) const
	{
		if (strBuf!=NULL)
		{
			memcpy(strBuf, buffer,length);
			strBuf[length]='\0';
		}	
	}

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{
		const char *p=buffer;
		while (*p)
		{
			if (*p!=' ')
			{
				return false;
			}
			p++;
		}
		return true;
	}

	///�ж��Ƿ�Ϸ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	bool isValid(void) const
	{
		return true;
	}

	///ת��Ϊ�ַ���
	///@return	�õ����ַ���
	operator const char *(void) const
	{
		return buffer;
	}

	///����ߵĿո�ɾ��
    void trimLeft(void)
    {
        // �˴�����crt��isspace���жϡ�
        // ��Ϊ�����char��������ASCII���ж����ֵ��С��128��ֵ����
        // ��msvc��debug�汾��crt�У�isspace(int c)�Բ���c�м�飬
        // �������ASCII���ж����char������ASSERT��
        if (*buffer == '\0' || *buffer != ' ')
            return;

        char* p1 = buffer + 1;
        while(*p1 == ' ') 
        {
            p1++;
        }

        char* p2 = buffer;
        while(*p2++ = *p1++) {}
    }

	///���ұߵĿո�ɾ��
	void trimRight(void)
	{
		char *p = buffer+strlen(buffer)-1;
		while (p >= buffer)
		{
			if (*p != ' ')
			{
				break;
			}
			*p = '\0';
			p--;
		}
	}

    ///���������ߵĿո�ɾ��
    void trim(void)
    {
        trimLeft();
        trimRight();
    }

	///�ж��Ƿ�С��ĳ���ַ���
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator < (const char *r) const
	{
		return strcmp(buffer,r)<0;
	}

	///�ж��Ƿ����ĳ���ַ���
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator > (const char *r) const
	{
		return strcmp(buffer, r)>0;
	}

	///�ж��Ƿ�С�ڵ���ĳ���ַ���
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator <= (const char *r) const
	{
		return strcmp(buffer,r)<=0;
	}

	///�ж��Ƿ���ڵ���ĳ���ַ���
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator >= (const char *r) const
	{
		return strcmp(buffer, r)>=0;
	}

	///�ж��Ƿ����ĳ���ַ���
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator == (const char *r) const
	{
		return strcmp(buffer, r)==0;
	}

	///�ж��Ƿ񲻵���ĳ���ַ���
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator != (const char *r) const
	{
		return strcmp(buffer, r)!=0;
	}
	
	///����hashֵ
	///@param	seed	����
	///@return	�õ���hashֵ
	unsigned int hash(unsigned int seed) const
	{
		unsigned long ret=seed;
		const char *str=buffer;
		
		if (*str == '\0')
		{
			return(ret);
		}
		long n = 0x100;
		while (*str)
		{
			unsigned long v = n|(*str);
			n += 0x100;
			int r = (int)((v>>2)^v)&0x0f;
			ret = (ret<<r)|(ret>>(32-r));
			ret &= 0xFFFFFFFFL;
			ret ^= v*v;
			str++;
		}
		return ((ret>>16)^ret);
	}


protected:
	///�洢�ַ�����ֵ
	char buffer[length+1];
};

#define DefineStringType(length,newType)				\
	typedef CUFStringType<length> C ## newType;			\
	typedef const CUFStringType<length> CReadOnly ## newType;

/////////////////////////////////////////////////////////////////////////
///CUFFloatType��һ���ڲ����ݵĸ�������
///@author	���ض�
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
///���ض���20070328
///�����˶Ը�������Χ���ж�����ֹ���ֳ�Խ��Χ������
template <int length, int precision> class CUFFloatType: public CUFBaseFloatType
{
public:
	///���캯��
	CUFFloatType(void)
	{
		//clear();
	}

	///���ƹ�����
	///@param	f	�����Դ����
	CUFFloatType(const CUFFloatType& f)
	{
		setValue(f.getValue());
	}

	///���ƹ�����
	///@param	value	�����Դ����
	CUFFloatType(const double value)
	{
		setValue(value);
	}

	///���ڲ�����
	///@param	f	���ڵ�ֵ
	///@return	�����ֵ
	const CUFFloatType & operator =(const CUFFloatType& f)
	{
		setValue(f.getValue());
		return f;
	}

	///���ڲ��������Ӹ������л�ȡ
	///@param	v	���ڵĸ�����
	///@return	������ָ�����
	const double operator =(const double value)
	{
		setValue(value);
		return value;
	}

	///���ڲ����������ַ����л�ȡ
	///@param	v	���ڵ��ַ���
	///@return	������ַ���
	const char * operator = (const char *v)
	{
		if (v[0]=='\0')
		{
			setValue(DOUBLE_NaN);
		}
		else
		{
			setValue((double)atof(v));
		}
		return v;
	}

	///������ݣ����ǽ�ֵ��Ϊ0
	void clear(void)
	{
		value=0.0;
	}

	///��ȡֵ
	///@return	��ȡ��ֵ
	const double getValue(void) const
	{
		return value;
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(const double v)
	{
		if ((v<SMALL_DOUBLE)&&(v>-SMALL_DOUBLE))
		{
			///������Ϊ�˷�ֹ����-0.00000�����������ĳЩ������������ڼ�������-31.0+31.0ʱ���õ��Ľ����-0.0������0.0
			value=0.0;
		}
		else
		{
			value=v;
		}
	}

	///��strBuf�еõ������͵��ַ�����ʾ	
	///@param	strBuf	���ڷ��ý�����ַ���
	void getString(char *strBuf) const
	{
		if (strBuf!=NULL)
		{
			if (value==DOUBLE_NaN)
			{
				strcpy(strBuf,"");
			}
			else
			{
				sprintf(strBuf,"%.5f", value);
			}
		}	
	}	

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{
		if (value==DOUBLE_NaN)
			return true;
		else
			return false;
	}

	///�ж��Ƿ�Ϸ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	bool isValid(void) const
	{
		if (isnan(value))
			return false;

		if (value==DOUBLE_NaN)
			return true;
		else if (value>=pow((double)10,(double)(length-precision-1)))
			return false;
		else if (value<=-pow((double)10,(double)(length-precision-2)))
			return false;
		return true;
	}

	///ת��Ϊʵ��
	///@return	�õ���ʵ��
	operator const double (void) const
	{
		return value;
	}
	
	///����ĳ��ֵ
	///@param	v	Ҫ�ӵ�ֵ
	///@return	�����Ժ�Ľ��
	const double operator += (const double v)
	{
		setValue(value+v);
		return v;
	}

	///��ȥĳ��ֵ
	///@param	v	Ҫ����ֵ
	///@return	�����Ժ�Ľ��
	const double operator -= (double v)
	{
		setValue(value-v);
		return v;
	}

	///����ĳ��ֵ
	///@param	v	Ҫ�˵�ֵ
	///@return	�����Ժ�Ľ��
	const double operator *= (const double v)
	{
		setValue(value*v);
		return v;
	}

	///����ĳ��ֵ
	///@param	v	Ҫ����ֵ
	///@return	�����Ժ�Ľ��
	const double operator /= (const double v)
	{
		setValue(value/v);
		return v;
	}
	
	///����ĳ��ֵ
	///@param	v	Ҫ����ֵ
	///@return	�����Ժ�Ľ��
	const int operator &(const double v) const
	{
		//******//
		//	���ض�,200609028�������˵�value/v�Ľ��Ϊ��ֵʱ�Ĵ���
		//******//
		return (int)(floor(value/v+SMALL_DOUBLE));
	}

	///�ж��Ƿ�С��ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator < (double r) const
	{
		return value < r-SMALL_DOUBLE;
	}

	///�ж��Ƿ����ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator > (double r) const
	{
		return value > r+SMALL_DOUBLE;
	}

	///�ж��Ƿ�С�ڵ���ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator <= (double r) const
	{
		return value <= r+SMALL_DOUBLE;
	}

	///�ж��Ƿ���ڵ���ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator >= (double r) const
	{
		return value >= r-SMALL_DOUBLE;
	}

	///�ж��Ƿ����ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator == (double r) const
	{
		return fabs(value-r)<=SMALL_DOUBLE;
	}

	///�ж��Ƿ񲻵���ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator != (double r) const
	{
		return fabs(value-r)>SMALL_DOUBLE;
	}

	///�ж��Ƿ�С��ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator < (int r) const
	{
		return value < r-SMALL_DOUBLE;
	}

	///�ж��Ƿ����ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator > (int r) const
	{
		return value > r+SMALL_DOUBLE;
	}

	///�ж��Ƿ�С�ڵ���ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator <= (int r) const
	{
		return value <= r+SMALL_DOUBLE;
	}

	///�ж��Ƿ���ڵ���ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator >= (int r) const
	{
		return value >= r-SMALL_DOUBLE;
	}

	///�ж��Ƿ����ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator == (int r) const
	{
		return fabs(value-r)<=SMALL_DOUBLE;
	}

	///�ж��Ƿ񲻵���ĳ��ֵ
	///@param	r	�ұ���
	///@return	true��ʾ�ǣ�false��ʾ��
	bool operator != (int r) const
	{
		return fabs(value-r)>SMALL_DOUBLE;
	}

	///����hashֵ
	///@param	seed	����
	///@return	�õ���hashֵ
	unsigned int hash(unsigned int seed) const
	{
		unsigned long ret=seed;
		const char *str=(char *)&value;
		int i;
		
		long n = 0x100;
		for (i=0;i<sizeof(double);i++)
		{
			unsigned long v = n|(*str);
			n += 0x100;
			int r = (int)((v>>2)^v)&0x0f;
			ret = (ret<<r)|(ret>>(32-r));
			ret &= 0xFFFFFFFFL;
			ret ^= v*v;
			str++;
		}
		return ((ret>>16)^ret);
	}

protected:
	///�洢��������ֵ
	double value;
};

#define DefineFloatType(maxValue,minValue,newType)			\
	typedef CUFFloatType<maxValue,minValue> C ## newType;	\
	typedef const CUFFloatType<maxValue,minValue> CReadOnly ## newType;

/////////////////////////////////////////////////////////////////////////
///CUFIntType��һ���ڲ����ݵ�������
///@author	���ض�
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
class CUFIntType: public CUFBaseIntType
{
public:
	///���캯��
	CUFIntType(void)
	{
		//clear();
	}

	///���ƹ�����
	///@param	i	�����Դ����
	CUFIntType(const CUFIntType& i)
	{
		setValue(i.getValue());
	}

	///���ƹ�����
	///@param	i	�����Դ����
	CUFIntType(const int i)
	{
		setValue(i);
	}

	///���ڲ�����
	///@param	i	���ڵ�ֵ
	///@return	�����ֵ
	const CUFIntType & operator =(const CUFIntType& i)
	{
		setValue(i.getValue());
		return i;
	}

	///���ڲ��������������л�ȡ
	///@param	i	���ڵ�����
	///@return	���������
	const int operator =(const int i)
	{
		setValue(i);
		return i;
	}

	///���ڲ����������ַ����л�ȡ
	///@param	v	���ڵ��ַ���
	///@return	������ַ���
	const char * operator =(const char *v)
	{
		setValue(atoi(v));
		return v;
	}

	///������ݣ����ǽ�ֵ��Ϊ0
	void clear(void)
	{
		value=0;
	}
	
	///��ȡֵ
	///@return	��ȡ��ֵ
	const int getValue(void) const
	{
		return value;
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(const int v)
	{
		value=v;
	}

	///��strBuf�еõ������͵��ַ�����ʾ	
	///@param	strBuf	���ڷ��ý�����ַ���
	void getString(char *strBuf) const
	{
		if (strBuf!=NULL)
		{
			sprintf(strBuf,"%d", value);
		}	
	}	

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{
		return false;
	}

	///�ж��Ƿ�Ϸ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	bool isValid(void) const
	{
		return true;
	}

	///ת��Ϊ����
	///@return	�õ�������
	operator const int (void) const
	{
		return value;
	}

	///���������ĳ��ֵ
	///@param	v	Ҫ�ӵ�ֵ
	///@return	�õ���ֵ
	const int operator += (const int v)
	{
		setValue(value+v);
		return value;
	}
	
	///�������ȥĳ��ֵ
	///@param	v	Ҫ����ֵ
	///@return	�õ���ֵ
	const int operator -= (const int v)
	{
		setValue(value-v);
		return value;
	}

	///���������ĳ��ֵ
	///@param	v	Ҫ�˵�ֵ
	///@return	�õ���ֵ
	const int operator *= (const int v)
	{
		setValue(value*v);
		return value;
	}

	///���������ĳ��ֵ
	///@param	v	Ҫ����ֵ
	///@return	�õ���ֵ
	const int operator /= (const int v)
	{
		setValue(value/v);
		return value;
	}

	///������ģĳ��ֵ
	///@param	v	Ҫģ��ֵ
	///@return	�õ���ֵ
	const int operator %= (const int v)
	{
		setValue(value%v);
		return value;
	}

	///����hashֵ
	///@param	seed	����
	///@return	�õ���hashֵ
	unsigned int hash(unsigned int seed) const
	{
		unsigned long ret=seed;
		unsigned  long v = 0x100 | value;
		int r = (int)((v>>2)^v)&0x0f;
		ret = (ret<<r)|(ret>>(32-r));
		ret &= 0xFFFFFFFFL;
		ret ^= v*v;
		return ((ret>>16)^ret);
	}

protected:
	///�洢������ֵ
	int value;
};

typedef const CUFIntType CReadOnlyUFIntType;

/////////////////////////////////////////////////////////////////////////
///CUFRangeIntType<int from,int to>��һ���ڲ������з�Χ�޶�������
///ģ���࣬ͨ��ָ����Χ�����Եõ���������ʹ�õ��ࡣCUFRangeIntType<int 
///from, int to>ʵ���Ͼ��Ǵ洢һ������������������ֵʱ�������
///@author	���ض�
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
template <int from, int to> class CUFRangeIntType: public CUFBaseIntType
{
public:
	///���캯��
	CUFRangeIntType(void)
	{
		//clear();
	}

	///���ƹ�����
	///@param	i	�����Դ����
	CUFRangeIntType(const CUFRangeIntType<from,to>& i)
	{
		setValue(i.getValue());
	}

	///���ƹ�����
	///@param	i	�����Դ����
	CUFRangeIntType(const int i)
	{
		setValue(i);
	}

	///���ڲ�����
	///@param	i	���ڵ�ֵ
	///@return	�����ֵ
	const CUFRangeIntType<from,to> & operator =(const CUFRangeIntType<from,to>& i)
	{
		setValue(i.getValue());
		return i;
	}

	///���ڲ��������������л�ȡ
	///@param	i	���ڵ�����
	///@return	���������
	const int operator =(const int i)
	{
		setValue(i);
		return i;
	}

	///���ڲ����������ַ����л�ȡ
	///@param	v	���ڵ��ַ���
	///@return	������ַ���
	const char * operator =(const char *v)
	{
		setValue(atoi(v));
		return v;
	}

	///������ݣ����ǽ�ֵ��Ϊfrom
	void clear(void)
	{
		value=from;
	}

	///��ȡֵ
	///@return	��ȡ��ֵ
	const int getValue(void) const
	{
		return value;
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	///@exception	CRuntimeError	������ֵԽ�磬���׳����쳣
	void setValue(const int v)
	{
		/*
		if ((v>to)||(v<from))
		{
			RAISE_RUNTIME_WARNING("out of range");
		}
		*/
		value=v;
	}

	///��strBuf�еõ������͵��ַ�����ʾ	
	///@param	strBuf	���ڷ��ý�����ַ���
	void getString(char *strBuf) const
	{
		if (strBuf!=NULL)
		{
			sprintf(strBuf,"%d", value);
		}	
	}

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{
		return false;
	}

	///�ж��Ƿ�Ϸ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	bool isValid(void) const
	{
		if ((value>to)||(value<from))
			return false;
		else
			return true;
	}

	///ת��Ϊ����
	///@return	�õ�������
	operator const int (void) const
	{
		return value;
	}

	///���������ĳ��ֵ
	///@param	v	Ҫ�ӵ�ֵ
	///@return	�õ���ֵ
	const int operator += (const int v)
	{
		setValue(value+v);
		return value;
	}
	
	///�������ȥĳ��ֵ
	///@param	v	Ҫ����ֵ
	///@return	�õ���ֵ
	const int operator -= (const int v)
	{
		setValue(value-v);
		return value;
	}

	///���������ĳ��ֵ
	///@param	v	Ҫ�˵�ֵ
	///@return	�õ���ֵ
	const int operator *= (const int v)
	{
		setValue(value*v);
		return value;
	}

	///���������ĳ��ֵ
	///@param	v	Ҫ����ֵ
	///@return	�õ���ֵ
	const int operator /= (const int v)
	{
		setValue(value/v);
		return value;
	}

	///������ģĳ��ֵ
	///@param	v	Ҫģ��ֵ
	///@return	�õ���ֵ
	const int operator %= (const int v)
	{
		setValue(value%v);
		return value;
	}

	///����hashֵ
	///@param	seed	����
	///@return	�õ���hashֵ
	unsigned int hash(unsigned int seed) const
	{
		unsigned long ret=seed;
		unsigned  long v = 0x100 | value;
		int r = (int)((v>>2)^v)&0x0f;
		ret = (ret<<r)|(ret>>(32-r));
		ret &= 0xFFFFFFFFL;
		ret ^= v*v;
		return ((ret>>16)^ret);
	}
protected:
	///�洢������ֵ
	int value;
};

#define DefineRangeIntType(from,to,newType)					\
	typedef CUFRangeIntType<from,to> C ## newType;			\
	typedef const CUFRangeIntType<from,to> CReadOnly ## newType;

/////////////////////////////////////////////////////////////////////////
///CUFCharType��һ���ڲ����ݵ��ַ���
///@author	���ض�
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
class CUFCharType: public CUFBaseCharType
{
public:
	///���캯��
	CUFCharType(void)
	{
		//clear();
	}

	///���ƹ�����
	///@param	c	�����Դ����
	CUFCharType(const CUFCharType& c)
	{
		setValue(c.getValue());
	}

	///���ƹ�����
	///@param	c	�����Դ����
	CUFCharType(const char c)
	{
		setValue(c);
	}

	///���ڲ�����
	///@param	c	���ڵ�ֵ
	///@return	�����ֵ
	const CUFCharType & operator =(const CUFCharType& c)
	{
		setValue(c.getValue());
		return c;
	}

	///���ڲ����������ַ��л�ȡ
	///@param	c	���ڵ��ַ�
	///@return	������ַ�
	const char operator =(const char c)
	{
		setValue(c);
		return c;
	}

	///���ڲ����������ַ����л�ȡ
	///@param	v	���ڵ��ַ���
	///@return	������ַ���
	const char * operator =(const char *v)
	{
		setValue(*v);
		return v;
	}

	///������ݣ����ǽ�ֵ��Ϊ'\0'
	void clear(void)
	{
		value='\0';
	}
	
	///��ȡֵ
	///@return	��ȡ��ֵ
	char getValue(void) const
	{
		return value;
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(const char v)
	{
		value=v;
	}

	///��strBuf�еõ������͵��ַ�����ʾ	
	///@param	strBuf	���ڷ��ý�����ַ���
	void getString(char *strBuf) const
	{
		if (strBuf!=NULL)
		{
			sprintf(strBuf,"%c", value);
		}	
	}	

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{
		return false;
	}

	///�ж��Ƿ�Ϸ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	bool isValid(void) const
	{
		return true;
	}

	///ת��Ϊ�ַ�
	///@return	�õ����ַ�
	operator const char (void) const
	{
		return value;
	}

	///����hashֵ
	///@param	seed	����
	///@return	�õ���hashֵ
	unsigned int hash(unsigned int seed) const
	{
		unsigned long ret=seed;
		unsigned  long v = 0x100 | value;
		int r = (int)((v>>2)^v)&0x0f;
		ret = (ret<<r)|(ret>>(32-r));
		ret &= 0xFFFFFFFFL;
		ret ^= v*v;
		return ((ret>>16)^ret);
	}
protected:
	///�洢�ַ���ֵ
	char value;
};

typedef const CUFCharType CReadOnlyUFCharType;

#define EnumNull ' '

///���ڶ���һ�����м����ַ�����
///@param	typename	Ҫ���������
///@param	validString	��������ȡֵ���ַ����ɵ��ַ���
#define DefineEnumCharType(typename,validString)				\
	class C ## typename: public CUFCharType						\
	{															\
	public:														\
		C ## typename(void)										\
		{														\
		}														\
		C ## typename(const C ## typename &v)					\
		{														\
			setValue(v.getValue());								\
		}														\
		C ## typename(const char v)								\
		{														\
			setValue(v);										\
		}														\
		C ## typename(const CUFCharType &v)						\
		{														\
			setValue(v.getValue());								\
		}														\
		C ## typename& operator=(const C ## typename &c)		\
		{														\
			setValue(c.getValue());								\
			return *this;										\
		}														\
		C ## typename& operator=(const CUFCharType &c)			\
		{														\
			setValue(c.getValue());								\
			return *this;										\
		}														\
		const char operator =(const char c)						\
		{														\
			setValue(c);										\
			return c;											\
		}														\
		const char * operator =(const char *v)					\
		{														\
			setValue(*v);										\
			return v;											\
		}														\
		void clear(void)										\
		{														\
			setValue(validString[0]);							\
		}														\
		void setValue(const char v)								\
		{														\
/*			if ((v!=EnumNull)&&!strchr(validString,v))			\
			{													\
				RAISE_RUNTIME_WARNING("out of enum char range");\
			}													\
*/			value=v;											\
		} 														\
		bool isNull(void) const									\
		{														\
			return value==EnumNull;								\
		}														\
		bool isValid(void) const								\
		{														\
			if (value=='\0')									\
				return false;									\
			if (strchr(validString,value))						\
				return true;									\
			else												\
				return false;									\
		} 														\
		static bool isValid(const char ch)						\
		{														\
			if (strchr(validString,ch))							\
				return true;									\
			else												\
				return false;									\
		}														\
	};															\
	typedef const C ## typename CReadOnly ## typename;			\

/////////////////////////////////////////////////////////////////////////
///CUFWordType��һ���ڲ����ݵ��ַ���
///@author	���ض�
///@version	2.0,20060218
/////////////////////////////////////////////////////////////////////////
class CUFWordType : public CUFBaseWordType
{
public:
	///���캯��
	CUFWordType(void)
	{
//		clear();
	}

	///���ƹ�����
	///@param	w	�����Դ����
	CUFWordType(const CUFWordType& w)
	{
		setValue(w.getValue());
	}

	///���ƹ�����
	///@param	w	�����Դ����
	CUFWordType(WORD w)
	{
		setValue(w);
	}
	
	///���ڲ�����
	///@param	w	���ڵ�ֵ
	///@return	�����ֵ
	const CUFWordType & operator =(const CUFWordType& w)
	{
		setValue(w.getValue());
		return w;
	}

	///���ڲ������������л�ȡ
	///@param	w	���ڵ���
	///@return	�������
	const WORD operator =(const WORD w)
	{
		setValue(w);
		return w;
	}

	///���ڲ����������ַ����л�ȡ
	///@param	v	���ڵ��ַ���
	///@return	������ַ���
	const char * operator =(const char *v)
	{
		setValue(atoi(v));
		return v;
	}

	///������ݣ����ǽ�ֵ��Ϊ0
	void clear(void)
	{
		value=0;
	}

	///��ȡֵ
	///@return	��ȡ��ֵ
	WORD getValue(void) const
	{
		return value;
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(WORD v)
	{
		value=v;
	}

	///��strBuf�еõ������͵��ַ�����ʾ	
	///@param	strBuf	���ڷ��ý�����ַ���
	void getString(char *strBuf) const
	{
		if (strBuf!=NULL)
		{
			sprintf(strBuf,"%d", value);
		}	
	}	

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{
		return false;
	}

	///�ж��Ƿ�Ϸ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	bool isValid(void) const
	{
		return true;
	}

	///ת��Ϊ��
	///@return	�õ�����
	operator const WORD (void)
	{
		return value;
	}

	///����hashֵ
	///@param	seed	����
	///@return	�õ���hashֵ
	unsigned int hash(unsigned int seed) const
	{
		unsigned long ret=seed;
		unsigned  long v = 0x100 | value;
		int r = (int)((v>>2)^v)&0x0f;
		ret = (ret<<r)|(ret>>(32-r));
		ret &= 0xFFFFFFFFL;
		ret ^= v*v;
		return ((ret>>16)^ret);
	}
protected:
	///�洢�ַ���ֵ
	WORD value;
};

typedef const CUFWordType CReadOnlyUFWordType;

/////////////////////////////////////////////////////////////////////////
///CUFQWordType��һ���ڲ����ݵ��ַ���
///@author	����
///@version	1.0,20110519
/////////////////////////////////////////////////////////////////////////
class CUFQWordType : public CUFBaseQWordType
{
public:
	///���캯��
	CUFQWordType(void)
	{
//		clear();
	}

	///���ƹ�����
	///@param	qw	�����Դ����
	CUFQWordType(const CUFQWordType& qw)
	{
		setValue(qw.getValue());
	}

	///���ƹ�����
	///@param	qw	�����Դ����
	CUFQWordType(QWORD qw)
	{
		setValue(qw);
	}
	
	///���ڲ�����
	///@param	qw	���ڵ�ֵ
	///@return	�����ֵ
	const CUFQWordType & operator =(const CUFQWordType& qw)
	{
		setValue(qw.getValue());
		return qw;
	}

	///���ڲ������������л�ȡ
	///@param	qw	���ڵ���
	///@return	�������
	const QWORD operator =(const QWORD qw)
	{
		setValue(qw);
		return qw;
	}

	///���ڲ����������ַ����л�ȡ
	///@param	v	���ڵ��ַ���
	///@return	������ַ���
	const char * operator =(const char *v)
	{
		QWORD qw = 0;
		
#ifdef WINDOWS
		sscanf(v, "%I64d",&qw);
#else
		sscanf(v, "%lld", &qw);
#endif		
		setValue(qw);
		return v;
	}

	///������ݣ����ǽ�ֵ��Ϊ0
	void clear(void)
	{
		value=0;
	}

	///��ȡֵ
	///@return	��ȡ��ֵ
	QWORD getValue(void) const
	{
		return value;
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(QWORD v)
	{
		value=v;
	}

	///��strBuf�еõ������͵��ַ�����ʾ	
	///@param	strBuf	���ڷ��ý�����ַ���
	void getString(char *strBuf) const
	{
		if (strBuf!=NULL)
		{
#ifdef WINDOWS
			sprintf(strBuf,"%I64d", value);
#else
			sprintf(strBuf,"%lld", value);
#endif		
		}	
	}	

	///�ж��Ƿ�Ϊ��
	///@return	true��ʾΪ�գ�false��ʾ��Ϊ��
	bool isNull(void) const
	{
		return false;
	}

	///�ж��Ƿ�Ϸ�
	///@return	true��ʾ�Ϸ���false��ʾ���Ϸ�
	bool isValid(void) const
	{
		return true;
	}

	///ת��Ϊ����
	///@return	�õ�������
	operator const QWORD (void) const
	{
		return value;
	}

	///����hashֵ
	///@param	seed	����
	///@return	�õ���hashֵ
	unsigned int hash(unsigned int seed) const
	{
		unsigned long ret=seed;
		unsigned  long v = 0x100 | value;
		int r = (int)((v>>2)^v)&0x0f;
		ret = (ret<<r)|(ret>>(32-r));
		ret &= 0xFFFFFFFFL;
		ret ^= v*v;
		return ((ret>>16)^ret);
	}
protected:
	///�洢��ֵ
	QWORD value;
};

typedef const CUFQWordType CReadOnlyUFQWordType;


#define DefineUFType(pureType, newType)			\
	typedef C ## pureType C ## newType;			\
	typedef CReadOnly ## pureType CReadOnly ## newType;	\
/*
template<int length,int precision> class CFixNumberType;

template <int length, int precision> 
class CReadOnlyFixNumberType
{
protected:
	CReadOnlyFixNumberType(const CReadOnlyFixNumberType<length,precision>& );
	CReadOnlyFixNumberType<length,precision>& operator=(const CReadOnlyFixNumberType<length,precision>&);
public:
	CReadOnlyFixNumberType(void)
	{
	}
	double getValue(void)
	{
		return atof(value);
	}
	///��strBuf�еõ������͵��ַ�����ʾ	
	void getString(char *strBuf)
	{
		strcpy(value);
	}	
	int isNull(void)
	{
		if (value[0]=='\0')
			return true;
		else
			return false;
	}
	int isValid(void)
	{
		return 1;
	}
	operator double (void)
	{
		return getValue();
	}
	operator int (void)
	{
		return getValue();
	}
	operator char *(void)
	{
		return getValue();
	}
	CFixNumberType<length,precision> operator + (CReadOnlyFixNumberType<length,precision> &v)
	{
	}
	CFixNumberType<length,precision> operator + (int v)
	{
	}
	CFixNumberType<length,precision> operator + (double v)
	{
	}
	CFixNumberType<length,precision> operator + (char *v)
	{
	}
protected:
	char value[length+1];
};

template<int length,int precision>
class CFixNumberType: public CReadOnlyFixNumberType<length,precision>
{
public:
	CFixNumberType(const CFixNumberType<length,precision>& f)
	{
		strcpy(value,f.value);
	}
	CFixNumberType<length,precision>& operator=(const CFixNumberType<length,precision>& f)
	{
		strcpy(value,f.value);
		return *this;
	}
	CFixNumberType<length,precision>& operator=(double f)
	{
	}
	CFixNumberType<length,precision>& operator=(int f)
	{
	}
	CFixNumberType<length,precision>& operator=(char *f)
	{
	}

	CFixNumberType()
	{
		clear();
	}

	///������ݣ����ǽ�ֵ��Ϊ0
	void clear(void)
	{
		value[0]='\0';
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(char *v)
	{
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(int v)
	{
	}

	///����ֵ
	///@param	v	Ҫ���õ�ֵ
	void setValue(double v)
	{
	}

	CFixNumberType<length,precision> &operator += (double v)
	{
	}
	CFixNumberType<length,precision> &operator += (int v)
	{
	}
	CFixNumberType<length,precision> &operator += (char *v)
	{
	}
	CFixNumberType<length,precision> &operator += (CReadOnlyFixNumberType &v)
	{
	}
}; 

#define DefineFixNumberType(length,precision,newType)					\
	typedef CUFFixNumberType<length,precision> C ## newType;			\
	typedef CReadOnlyUFFixNumberType<length,precision> CReadOnly ## newType;
*/
#endif
