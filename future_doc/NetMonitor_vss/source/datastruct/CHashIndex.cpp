/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CHashIndex.cpp
///@brief	实现了类CHashIndex
///@history 
///20020611	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "CHashIndex.h"
#include "HashMap.h"

CHashIndex::CHashIndex(int hashKeySize, IMemoryAllocator *pAllocator,bool reuse, int reuseID, int readOnly)
{
	int i = 0;
	for (;i<__stl_num_primes;i++)
	{
		if (__stl_prime_list[i]>=hashKeySize)
		{
			m_hashKeySize=__stl_prime_list[i];
			break;
		}
	}
	if (i==__stl_num_primes)
	{
		RAISE_RUNTIME_ERROR("Too large hash size");
	}
	pIndexMem=new CFixMem(sizeof(CHashIndexNode),4096,pAllocator,reuse,reuseID,readOnly);
	if (pIndexMem==NULL)
	{
		RAISE_RUNTIME_ERROR("Insufficient memory space");
	}
	if (!reuse)
	{
		init();
	}
}

CHashIndex::~CHashIndex(void)
{
	delete pIndexMem;
}

void CHashIndex::init(void)
{
	for (int i=0;i<m_hashKeySize;i++)
	{
		CHashIndexNode *pNode=(CHashIndexNode *)(pIndexMem->alloc());
		pNode->pObject=NULL;
		pNode->next=NULL;
	}
}
