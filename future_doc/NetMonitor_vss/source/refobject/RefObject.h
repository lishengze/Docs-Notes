/////////////////////////////////////////////////////////////////////////
///@system 基础系统
///@company 上海期货信息技术有限公司
///@file RefObject.h
///@brief	定义了使用引用计数的基本类
///@history 
///20080310	王肇东		创建该文件
///20080623	周建军		修改模板类
/////////////////////////////////////////////////////////////////////////

#ifndef REF_OBJECT_H
#define REF_OBJECT_H

#include "platform.h"

/////////////////////////////////////////////////////////////////////////
///CRefObject定义了所有使用引用计数的类的基类
///@author	王肇东
///@version	1.0,20090310
///@description	对本类的使用方法如下：
///		定义一个实际使用的类T，继承本类，其析构方法必须是private或者protected的
///		使用DefineRefObjectPtr定义T的指针类(TPtr)
///		对于所有的类T的实例，必须采用new的方式创建，不得采用自动变量
///		不得使用T *这样的类型，必须全部使用TPtr这样的类
/////////////////////////////////////////////////////////////////////////
class CRefObject
{
protected:
	///引用计数
	int m_RefCount;
	
	///管理引用计数的临界区
	CRITICAL_VAR m_RefCritical;

	///析构方法
	virtual ~CRefObject(void)
	{
		DELETE_CRITICAL_VAR(m_RefCritical);
	}

public:
	///构造方法
	CRefObject(void)
	{
		m_RefCount=0;
		INIT_CRITICAL_VAR(m_RefCritical);
	}
	
	///增加引用计数
	void incRef(void)
	{
		ENTER_CRITICAL(m_RefCritical);
		m_RefCount++;
		LEAVE_CRITICAL(m_RefCritical);
	}
	
	///减少引用计数
	void decRef(void)
	{
		ENTER_CRITICAL(m_RefCritical);
		m_RefCount--;
		if (m_RefCount<=0)
		{
			LEAVE_CRITICAL(m_RefCritical);
			delete this;
			return;
		}
		LEAVE_CRITICAL(m_RefCritical);
	}
	
	///获取引用计数
	///@return	引用计数值
	int getRefCount(void) const
	{
		return m_RefCount;
	}
};

/////////////////////////////////////////////////////////////////////////
///CRefObjectPtr定义了指向CRefObject对象的指针
///@author	王肇东
///@version	1.0,20090310
/////////////////////////////////////////////////////////////////////////
class CRefObjectPtr
{
protected:
	CRefObject *p;

	void incRef(void)
	{
		if (p!=NULL)
		{
			p->incRef();
		}
	}

	void decRef(void)
	{
		if (p!=NULL)
		{
			p->decRef();
		}
	}

public:
	///构造方法
	CRefObjectPtr(void)
	{
		p=NULL;
	}

	///析构方法
	~CRefObjectPtr(void)
	{
		decRef();
	}

	///清除内容
	void clear(void)
	{
		decRef();
		p=NULL;
	}
};

/////////////////////////////////////////////////////////////////////////
///CRefSubObjectPtr模板定义了指向CRefObject子类的对象指针
///@author	王肇东
///@version	1.0,20090310
/////////////////////////////////////////////////////////////////////////
template <class T, class B> 
class CRefSubObjectPtr: public B
{
public:
	///设置空初始值的构造方法
	CRefSubObjectPtr(void)
	{
	}
	
	///析构方法
	~CRefSubObjectPtr(void)
	{
	}

	///同类复制的构造方法
	///@param	s	作为复制源的同类
	CRefSubObjectPtr(const CRefSubObjectPtr<T,B> &s)
	{
		this->p=s.p;
		this->incRef();
	}
	
	///指针复制的构造方法
	///@param	s	作为复制源的指针
	CRefSubObjectPtr(T *s)
	{
		this->p=s;
		this->incRef();
	}

	///对指针的等于符号重载
	///@param	s	源指针
	///@return	本身对象
	const CRefSubObjectPtr<T,B> & operator =(T *s)
	{
		this->decRef();
		this->p=s;
		this->incRef();
		return *this;
	}

	///对同类的等于符号重载
	///@param	s	同类引用
	///@return	本身对象
	const CRefSubObjectPtr<T,B> & operator =(const CRefSubObjectPtr<T,B> &s)
	{
		this->decRef();
		this->p=s.p;
		this->incRef();
		return *this;
	}
	
	///转化为指向内部对象的指针
	operator T *(void)
	{
		return (T *)this->p;
	}
	
	///转化为指向内部对象的指针
	operator const T *(void)
	{
		return (const T *)this->p;
	}

	///对获取值的符号重载
	///@return	所指对象
	T * operator->(void) const
	{
		return (T *)this->p;
	}

	///比较是否相同
	///@param	v	要比较的对象
	///@return	true表示相等，false表示不相同
	bool operator == (const T *v) const
	{
		return (T *)this->p==v;
	}
	
	///比较是否相同
	///@param	s	要比较的对象
	///@return	true表示相等，false表示不相同
	bool operator == (const CRefSubObjectPtr<T,B> &s) const
	{
		return this->p==s.p;
	}
	
	///比较是否不同
	///@param	v	要比较的对象
	///@return	true表示不相等，false表示相等
	bool operator != (const T *v) const
	{
		return (T *)this->p!=v;
	}
	
	///比较是否不同
	///@param	s	要比较的对象
	///@return	true表示不相等，false表示相等
	bool operator != (const CRefSubObjectPtr<T,B> &s) const
	{
		return this->p!=s.p;
	}
};

///定义一个使用引用计数的类，将自动定义其指针类
///@param	T	要定义的类
///@param	B	使用的基类，必须是CRefObject或者其子类
#define DefineRefClass(T,B)							\
	class T;										\
	typedef CRefSubObjectPtr<T,B ## Ptr> T ## Ptr;	\
	class T: public B

#endif
