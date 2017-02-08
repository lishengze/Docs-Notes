#ifndef _AUTO_PTR_H
#define _AUTO_PTR_H

/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file     CAutoPtr.h
///@brief    CAutoPtr ��һ���Զ���װ����ָ����࣬ͨ��������ɶ�ָ��Ĳ���
///@history 
///20050623	�ż���		�������ļ�
/////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// CAutoPtr ��һ���Զ���װ����ָ����࣬ͨ��������ɶ�ָ��Ĳ������Ա���
///   �����ڴ�й¶�����⡣
///   �����а����Ķ�����Ҫ���⼸������
/// void AddRef �������ü���
/// void Release �������ü��������Ҹ������ü����������ʵ��
/// ע��1. ����Ľ⹹֮���Է��ڶ���֮�����д�������Ϊ���������ṩ�����
///         ����ԣ���������Щ����ֻ��ͨ��auto_ptr�����д���֮��Ĺ�����
///     2. �������д����߳���ص���������಻���κδ���
/// ʹ�÷�����
///     1. ʾ����
///			class A
///			{
///			public:
///				A():m_nCount(0){
///				}
///			protected:
///				virtual ~A(){} //���Է�ֹ���ⲿʹ��delete��ɾ��
///			public:
///				void AddRef(){
///					m_nCount++;
///				}
///
///				virtual void Release(){
///					m_nCount--;
///					if(m_nCount == 0)
///						delete this;	
///				}
///				int m_nCount;
///			};
///		 2. ʹ�÷���
///			CAutoPtr<A> pa(new A());
//////////////////////////////////////////////////////////////////////////

template <class T>
class CAutoPtr
{
	typedef T element_type;
private:
	T*   _point;		///����Ķ���ָ��
public:
	//////////////////////////////////////////////////////////////////////////
	/// ���캯��,���������Լ�operatot = 
	//////////////////////////////////////////////////////////////////////////
	explicit CAutoPtr(T* p=0) throw():_point(p){	//��һ��ָ�봴��
		_point->AddRef();
	}	

	CAutoPtr(CAutoPtr& rhs) throw()          ///Copy contructor
	{
		_point = rhs._point;
		_point->AddRef();
	}

	template <class Y>
		CAutoPtr(CAutoPtr<Y>& rhs) throw()   ///֧�ּ̳�����
	{
		_point = rhs._point();
		_point->AddRef();
	}

	CAutoPtr& operator=(CAutoPtr& rhs) throw() ///Operator = 
	{
		_point = rhs._point;
		_point->AddRef();
		return *this;
	}

	template <class Y>
		CAutoPtr& operator=(CAutoPtr<Y>& rhs) throw()	///Operator = 
	{
		_point = rhs.operator ->();
		_point->AddRef();
		return *this;
	}


	~CAutoPtr() throw()				///��������
	{
		_point->Release();
		/*if(_point->GetRefCount() == 0)
		delete _point;*/
	}				

	//////////////////////////////////////////////////////////////////////////
	/// ��Ա����
	//////////////////////////////////////////////////////////////////////////
	T& operator*() const throw()
	{
		return *_point;
	}

	T* operator->() const throw()
	{
		return _point;
	}

	void reset(T* p=0) throw()
	{
		if(_point != p)
		{
			_point->Release();
			_point = p;
		}
	}
};
#endif