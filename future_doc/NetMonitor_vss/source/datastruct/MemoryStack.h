/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file MemoryStack.h
///@brief	�������Զ�ջ��ʽ������ͷŵ�ĳ���ض����͵��ڴ�
///@history 
///20060513	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef MEMORYSTACK_H
#define MEMORYSTACK_H

#include "CBaseObject.h"
#include "utility.h"

/////////////////////////////////////////////////////////////////////////
///CMemoryStack<T>��һ������T���Զ�ջ��ʽ������ͷŵ��ڴ��������Ҳ����˵��
///����T��������ͷŽ�ʹ��������alloc��free���������ң���alloc��ȥ�ģ�
///һ����free�������T������ȱʡ�Ĺ����ӣ����Ҳ������ڲ������������ռ䣬
///�����������������¿���
///@author	���ض�
///@version	1.0,20060513
/////////////////////////////////////////////////////////////////////////
template <class T> class CMemoryStack: public vector<T *>
{
private:
	int allocCount;
public:
	///���캯��
	CMemoryStack(void)
	{
		allocCount=0;
	}

	///����һ��
	///@return	����õ��Ķ���
	T *alloc(void)
	{
		if (allocCount==vector<T *>::size())
		{
			push_back(new T);
		}
		return vector<T *>::at(allocCount++);
	}

	///�ͷ�һ��
	///@param	p	Ҫ�ͷŵĶ���
	void free(T *p)
	{
		allocCount--;
	}
	
	///�ͷ����ж���
	void clear(void)
	{
		allocCount=0;
	}
}; 

#endif
