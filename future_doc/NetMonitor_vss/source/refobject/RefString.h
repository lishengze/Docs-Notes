/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file RefString.h
///@brief	定义了使用引用计数的字符串类
///@history 
///20080310	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef REF_STRING_H
#define REF_STRING_H

#include "platform.h"
#include "RefObject.h"

/////////////////////////////////////////////////////////////////////////
///CRefString定义了使用引用计数的字符串类
///@author	王肇东
///@version	1.0,20090310
/////////////////////////////////////////////////////////////////////////
class CRefString: public CRefObject
{
protected:
	///使用的字符串
	char *m_String;
	
	///字符串长度
	int m_Len;
	
	///析构方法
	virtual ~CRefString(void);

public:
	///构造方法
	///@param	value	初始化的字符串，可以为NULL
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
	
	///转化为字符串
	///@return	转化结果的字符串
	operator const char *(void) const
	{
		return m_String;
	}
	
	///获取作为值的字符串
	///@return	作为值的字符串
	const char *getValue(void) const
	{
		return m_String;
	}
	
	///获取字符串长度
	///@return	字符串长度
	int getLen(void) const
	{
		return m_Len;
	}

	///比较值是否相等
	///@param	s	要比较的对象
	///@return	true表示值相等，false表示值不相等
	bool equal(const char *s) const
	{
		return strcmp(m_String,s)==0;
	}


	/// Added by Henchi, 20121121

	///比较值是否相等
	///@param	s	要比较的对象
	///@return	true表示值相等，false表示值不相等
	bool eq(const char *s) const
	{
		return strcmp(m_String,s)==0;
	}

	///比较是否大于目标值
	///@param	s	要比较的对象
	///@return	true表示成立，false表示不成立
	bool gt(const char *s) const
	{
		return strcmp(m_String,s) > 0;
	}

	///比较是否大于等于目标值
	///@param	s	要比较的对象
	///@return	true表示成立，false表示不成立
	bool ge(const char *s) const
	{
		return strcmp(m_String,s) >= 0;
	}

	///比较是否小于目标值
	///@param	s	要比较的对象
	///@return	true表示成立，false表示不成立
	bool lt(const char *s) const
	{
		return strcmp(m_String,s) < 0;
	}

	///比较是否小于等于目标值
	///@param	s	要比较的对象
	///@return	true表示成立，false表示不成立
	bool le(const char *s) const
	{
		return strcmp(m_String,s) <= 0;
	}
	/// End of Added by Henchi

	///将本字符串输出，NULL输出为空白
	///@return	输出的字符串
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
///CRefStringPtr定义了使用引用计数的字符串指针类
///@author	王肇东
///@version	1.0,20090310
/////////////////////////////////////////////////////////////////////////
class CRefStringPtr: public CRefObjectPtr
{
public:
	///设置空初始值的构造方法
	CRefStringPtr(void)
	{
	}
	
	///析构方法
	~CRefStringPtr(void)
	{
	}

	///同类复制的构造方法
	///@param	s	作为复制源的同类
	CRefStringPtr(const CRefStringPtr &s)
	{
		p=s.p;
		incRef();
	}
	
	///指针复制的构造方法
	///@param	s	作为复制源的指针
	CRefStringPtr(CRefString *s)
	{
		p=s;
		incRef();
	}

	///从一个字符串构造
	///@param	s	作为源的字符串
	CRefStringPtr(const char *s)
	{
		p=new CRefString(s);
		incRef();
	}

	///对指针的等于符号重载
	///@param	s	源指针
	///@return	本身对象
	const CRefStringPtr & operator =(CRefString *s)
	{
		decRef();
		p=s;
		incRef();
		return *this;
	}

	///对同类的等于符号重载
	///@param	s	同类引用
	///@return	本身对象
	const CRefStringPtr & operator =(const CRefStringPtr &s)
	{
		decRef();
		p=s.p;
		incRef();
		return *this;
	}
	
	///对字符串的等于符号重载
	///@param	s	同类引用
	///@return	本身对象
	const CRefStringPtr & operator =(const char *s)
	{
		decRef();
		p=new CRefString(s);
		incRef();
		return *this;
	}
	
	///转化为指向内部对象的指针
	operator CRefString *(void) const
	{
		return (CRefString *)p;
	}
	
	///转化为指向内部对象的指针
	operator const CRefString *(void) const
	{
		return (const CRefString *)p;
	}

	///转化为字符串
	operator const char *(void) const
	{
		return ((CRefString *)p)->getValue();
	}

	///对获取值的符号重载
	///@return	所指对象
	CRefString * operator->(void) const
	{
		return (CRefString *)p;
	}

	///比较是否相同
	///@param	v	要比较的对象
	///@return	true表示相等，false表示不相同
	bool operator == (const CRefString *v) const
	{
		return (CRefString *)p==v;
	}
	
	///比较是否相同
	///@param	s	要比较的对象
	///@return	true表示相等，false表示不相同
	bool operator == (const CRefStringPtr &s) const
	{
		return p==s.p;
	}
	
	///比较是否不同
	///@param	v	要比较的对象
	///@return	true表示不相等，false表示相等
	bool operator != (const CRefString *v) const
	{
		return (CRefString *)p!=v;
	}
	
	///比较是否不同
	///@param	s	要比较的对象
	///@return	true表示不相等，false表示相等
	bool operator != (const CRefStringPtr &s) const
	{
		return p!=s.p;
	}

	///比较是否小于
	///@param	s	要比较的对象
	///@return	true表示小于，false表示不小于
	bool operator < (const CRefStringPtr &s) const
	{
		return strcmp(*this, s->getValue())<0;
	}

	///比较是否大于
	///@param	s	要比较的对象
	///@return	true表示大于，false表示不大于
	bool operator > (const CRefStringPtr &s) const
	{
		return strcmp(*this, s->getValue())>0;
	}
};

#endif
