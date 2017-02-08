/////////////////////////////////////////////////////////////////////////
///@system ����ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file RefObject.h
///@brief	������ʹ�����ü����Ļ�����
///@history 
///20080310	���ض�		�������ļ�
///20080623	�ܽ���		�޸�ģ����
/////////////////////////////////////////////////////////////////////////

#ifndef REF_OBJECT_H
#define REF_OBJECT_H

#include "platform.h"

/////////////////////////////////////////////////////////////////////////
///CRefObject����������ʹ�����ü�������Ļ���
///@author	���ض�
///@version	1.0,20090310
///@description	�Ա����ʹ�÷������£�
///		����һ��ʵ��ʹ�õ���T���̳б��࣬����������������private����protected��
///		ʹ��DefineRefObjectPtr����T��ָ����(TPtr)
///		�������е���T��ʵ�����������new�ķ�ʽ���������ò����Զ�����
///		����ʹ��T *���������ͣ�����ȫ��ʹ��TPtr��������
/////////////////////////////////////////////////////////////////////////
class CRefObject
{
protected:
	///���ü���
	int m_RefCount;
	
	///�������ü������ٽ���
	CRITICAL_VAR m_RefCritical;

	///��������
	virtual ~CRefObject(void)
	{
		DELETE_CRITICAL_VAR(m_RefCritical);
	}

public:
	///���췽��
	CRefObject(void)
	{
		m_RefCount=0;
		INIT_CRITICAL_VAR(m_RefCritical);
	}
	
	///�������ü���
	void incRef(void)
	{
		ENTER_CRITICAL(m_RefCritical);
		m_RefCount++;
		LEAVE_CRITICAL(m_RefCritical);
	}
	
	///�������ü���
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
	
	///��ȡ���ü���
	///@return	���ü���ֵ
	int getRefCount(void) const
	{
		return m_RefCount;
	}
};

/////////////////////////////////////////////////////////////////////////
///CRefObjectPtr������ָ��CRefObject�����ָ��
///@author	���ض�
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
	///���췽��
	CRefObjectPtr(void)
	{
		p=NULL;
	}

	///��������
	~CRefObjectPtr(void)
	{
		decRef();
	}

	///�������
	void clear(void)
	{
		decRef();
		p=NULL;
	}
};

/////////////////////////////////////////////////////////////////////////
///CRefSubObjectPtrģ�嶨����ָ��CRefObject����Ķ���ָ��
///@author	���ض�
///@version	1.0,20090310
/////////////////////////////////////////////////////////////////////////
template <class T, class B> 
class CRefSubObjectPtr: public B
{
public:
	///���ÿճ�ʼֵ�Ĺ��췽��
	CRefSubObjectPtr(void)
	{
	}
	
	///��������
	~CRefSubObjectPtr(void)
	{
	}

	///ͬ�ิ�ƵĹ��췽��
	///@param	s	��Ϊ����Դ��ͬ��
	CRefSubObjectPtr(const CRefSubObjectPtr<T,B> &s)
	{
		this->p=s.p;
		this->incRef();
	}
	
	///ָ�븴�ƵĹ��췽��
	///@param	s	��Ϊ����Դ��ָ��
	CRefSubObjectPtr(T *s)
	{
		this->p=s;
		this->incRef();
	}

	///��ָ��ĵ��ڷ�������
	///@param	s	Դָ��
	///@return	�������
	const CRefSubObjectPtr<T,B> & operator =(T *s)
	{
		this->decRef();
		this->p=s;
		this->incRef();
		return *this;
	}

	///��ͬ��ĵ��ڷ�������
	///@param	s	ͬ������
	///@return	�������
	const CRefSubObjectPtr<T,B> & operator =(const CRefSubObjectPtr<T,B> &s)
	{
		this->decRef();
		this->p=s.p;
		this->incRef();
		return *this;
	}
	
	///ת��Ϊָ���ڲ������ָ��
	operator T *(void)
	{
		return (T *)this->p;
	}
	
	///ת��Ϊָ���ڲ������ָ��
	operator const T *(void)
	{
		return (const T *)this->p;
	}

	///�Ի�ȡֵ�ķ�������
	///@return	��ָ����
	T * operator->(void) const
	{
		return (T *)this->p;
	}

	///�Ƚ��Ƿ���ͬ
	///@param	v	Ҫ�ȽϵĶ���
	///@return	true��ʾ��ȣ�false��ʾ����ͬ
	bool operator == (const T *v) const
	{
		return (T *)this->p==v;
	}
	
	///�Ƚ��Ƿ���ͬ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ��ȣ�false��ʾ����ͬ
	bool operator == (const CRefSubObjectPtr<T,B> &s) const
	{
		return this->p==s.p;
	}
	
	///�Ƚ��Ƿ�ͬ
	///@param	v	Ҫ�ȽϵĶ���
	///@return	true��ʾ����ȣ�false��ʾ���
	bool operator != (const T *v) const
	{
		return (T *)this->p!=v;
	}
	
	///�Ƚ��Ƿ�ͬ
	///@param	s	Ҫ�ȽϵĶ���
	///@return	true��ʾ����ȣ�false��ʾ���
	bool operator != (const CRefSubObjectPtr<T,B> &s) const
	{
		return this->p!=s.p;
	}
};

///����һ��ʹ�����ü������࣬���Զ�������ָ����
///@param	T	Ҫ�������
///@param	B	ʹ�õĻ��࣬������CRefObject����������
#define DefineRefClass(T,B)							\
	class T;										\
	typedef CRefSubObjectPtr<T,B ## Ptr> T ## Ptr;	\
	class T: public B

#endif
