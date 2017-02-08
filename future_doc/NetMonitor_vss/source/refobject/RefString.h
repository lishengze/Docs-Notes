/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file RefString.h
///@brief	������ʹ�����ü������ַ�����
///@history 
///20080310	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef REF_STRING_H
#define REF_STRING_H

#include "platform.h"
#include "RefObject.h"

/////////////////////////////////////////////////////////////////////////
///CRefString������ʹ�����ü������ַ�����
///@author	���ض�
///@version	1.0,20090310
/////////////////////////////////////////////////////////////////////////
class CRefString: public CRefObject
{
protected:
	///ʹ�õ��ַ���
	char *m_String;
	
	///�ַ�������
	int m_Len;
	
	///��������
	virtual ~CRefString(void);

public:
	///���췽��
	///@param	value	��ʼ�����ַ���������ΪNULL
	CRefString(const char *value)
	{
		if (value!=NULL)
		{
			m_String=strdup(value);
			m_Len=strlen(m_String);
		}
		else
		{
			m_String=NULL;
			m_Len=0;
		}
	}
	
	///ת��Ϊ�ַ���
	///@return	ת��������ַ���
	operator const char *(void) const
	{
		return m_String;
	}
	
	///��ȡ��Ϊֵ���ַ���
	///@return	��Ϊֵ���ַ���
	const char *getValue(void) const
	{
		return m_String;
	}
	
	///��ȡ�ַ�������
	///@return	�ַ�������
	int getLen(void) const
	{
		return m_Len;
	}

	///�Ƚ�ֵ�Ƿ����
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾֵ��ȣ�false��ʾֵ�����
	bool equal(const char *s) const
	{
		return strcmp(m_String,s)==0;
	}


	/// Added by Henchi, 20121121

	///�Ƚ�ֵ�Ƿ����
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾֵ��ȣ�false��ʾֵ�����
	bool eq(const char *s) const
	{
		return strcmp(m_String,s)==0;
	}

	///�Ƚ��Ƿ����Ŀ��ֵ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ������false��ʾ������
	bool gt(const char *s) const
	{
		return strcmp(m_String,s) > 0;
	}

	///�Ƚ��Ƿ���ڵ���Ŀ��ֵ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ������false��ʾ������
	bool ge(const char *s) const
	{
		return strcmp(m_String,s) >= 0;
	}

	///�Ƚ��Ƿ�С��Ŀ��ֵ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ������false��ʾ������
	bool lt(const char *s) const
	{
		return strcmp(m_String,s) < 0;
	}

	///�Ƚ��Ƿ�С�ڵ���Ŀ��ֵ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ������false��ʾ������
	bool le(const char *s) const
	{
		return strcmp(m_String,s) <= 0;
	}
	/// End of Added by Henchi

	///�����ַ��������NULL���Ϊ�հ�
	///@return	������ַ���
	const char *display(void) const
	{
		if (m_String!=NULL)
		{
			return m_String;
		}
		else
		{
			return "";
		}
	}
};

/////////////////////////////////////////////////////////////////////////
///CRefStringPtr������ʹ�����ü������ַ���ָ����
///@author	���ض�
///@version	1.0,20090310
/////////////////////////////////////////////////////////////////////////
class CRefStringPtr: public CRefObjectPtr
{
public:
	///���ÿճ�ʼֵ�Ĺ��췽��
	CRefStringPtr(void)
	{
	}
	
	///��������
	~CRefStringPtr(void)
	{
	}

	///ͬ�ิ�ƵĹ��췽��
	///@param	s	��Ϊ����Դ��ͬ��
	CRefStringPtr(const CRefStringPtr &s)
	{
		p=s.p;
		incRef();
	}
	
	///ָ�븴�ƵĹ��췽��
	///@param	s	��Ϊ����Դ��ָ��
	CRefStringPtr(CRefString *s)
	{
		p=s;
		incRef();
	}

	///��һ���ַ�������
	///@param	s	��ΪԴ���ַ���
	CRefStringPtr(const char *s)
	{
		p=new CRefString(s);
		incRef();
	}

	///��ָ��ĵ��ڷ�������
	///@param	s	Դָ��
	///@return	�������
	const CRefStringPtr & operator =(CRefString *s)
	{
		decRef();
		p=s;
		incRef();
		return *this;
	}

	///��ͬ��ĵ��ڷ�������
	///@param	s	ͬ������
	///@return	�������
	const CRefStringPtr & operator =(const CRefStringPtr &s)
	{
		decRef();
		p=s.p;
		incRef();
		return *this;
	}
	
	///���ַ����ĵ��ڷ�������
	///@param	s	ͬ������
	///@return	�������
	const CRefStringPtr & operator =(const char *s)
	{
		decRef();
		p=new CRefString(s);
		incRef();
		return *this;
	}
	
	///ת��Ϊָ���ڲ������ָ��
	operator CRefString *(void) const
	{
		return (CRefString *)p;
	}
	
	///ת��Ϊָ���ڲ������ָ��
	operator const CRefString *(void) const
	{
		return (const CRefString *)p;
	}

	///ת��Ϊ�ַ���
	operator const char *(void) const
	{
		return ((CRefString *)p)->getValue();
	}

	///�Ի�ȡֵ�ķ�������
	///@return	��ָ����
	CRefString * operator->(void) const
	{
		return (CRefString *)p;
	}

	///�Ƚ��Ƿ���ͬ
	///@param	v	Ҫ�ȽϵĶ���
	///@return	true��ʾ��ȣ�false��ʾ����ͬ
	bool operator == (const CRefString *v) const
	{
		return (CRefString *)p==v;
	}
	
	///�Ƚ��Ƿ���ͬ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ��ȣ�false��ʾ����ͬ
	bool operator == (const CRefStringPtr &s) const
	{
		return p==s.p;
	}
	
	///�Ƚ��Ƿ�ͬ
	///@param	v	Ҫ�ȽϵĶ���
	///@return	true��ʾ����ȣ�false��ʾ���
	bool operator != (const CRefString *v) const
	{
		return (CRefString *)p!=v;
	}
	
	///�Ƚ��Ƿ�ͬ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ����ȣ�false��ʾ���
	bool operator != (const CRefStringPtr &s) const
	{
		return p!=s.p;
	}

	///�Ƚ��Ƿ�С��
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾС�ڣ�false��ʾ��С��
	bool operator < (const CRefStringPtr &s) const
	{
		return strcmp(*this, s->getValue())<0;
	}

	///�Ƚ��Ƿ����
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ���ڣ�false��ʾ������
	bool operator > (const CRefStringPtr &s) const
	{
		return strcmp(*this, s->getValue())>0;
	}
};

#endif
