/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file MemoryStack.h
///@brief	定义了以堆栈方式申请和释放的某种特定类型的内存
///@history 
///20060513	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef MEMORYSTACK_H
#define MEMORYSTACK_H

#include "CBaseObject.h"
#include "utility.h"

/////////////////////////////////////////////////////////////////////////
///CMemoryStack<T>是一个类型T的以堆栈方式申请和释放的内存管理器。也就是说，
///类型T的申请和释放将使用这个类的alloc和free方法，而且，先alloc出去的，
///一定后free。这里的T必须有缺省的构造子，而且不能在内部再申请其他空间，
///其析构方法必须无事可做
///@author	王肇东
///@version	1.0,20060513
/////////////////////////////////////////////////////////////////////////
template <class T> class CMemoryStack: public vector<T *>
{
private:
	int allocCount;
public:
	///构造函数
	CMemoryStack(void)
	{
		allocCount=0;
	}

	///申请一个
	///@return	申请得到的对象
	T *alloc(void)
	{
		if (allocCount==vector<T *>::size())
		{
			push_back(new T);
		}
		return vector<T *>::at(allocCount++);
	}

	///释放一个
	///@param	p	要释放的对象
	void free(T *p)
	{
		allocCount--;
	}
	
	///释放所有对象
	void clear(void)
	{
		allocCount=0;
	}
}; 

#endif
