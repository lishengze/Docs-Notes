#include "Allocator.h"
#include <memory.h>
#include <stdio.h>
#include <iostream>
#include "platform.h"
#include "CBaseObject.h"
#include "CConfig.h"
#include "monitorIndex.h"

// 32λ�£�ȱʡʹ��512M�Ŀռ�
#define DEFAULT_MEMORY_SIZE_32 (512)

// 64λ�£�ȱʡʹ��4G�Ŀռ�
#define DEFAULT_MEMORY_SIZE_64 (4*1024)

/// 32λ�£�ȱʡ�����ɷ���Ŀ���
#define DEFAULT_MAX_BLOCK_COUNT_32		(16*1024)

/// 64λ�£�ȱʡ�����ɷ���Ŀ���
#define DEFAULT_MAX_BLOCK_COUNT_64		(128*1024)

/// �����ڴ�ʱ��ʹ�õ��ڴ���
#define SHARE_MEMORY_START_ID	15

/// ������ڴ��С
unsigned long dwMemorySize;

/// ���ɷ������
unsigned int maxBlockCount;

///��ʾ�ڴ���ʹ�����
struct UsedBlockStruct		
{
	void* startPosition;	///�ڴ�����ʼ��ַ
};

///������ڴ��ͷ
struct MemoryAllocatorHead
{
	void* m_pthisPoint;	///ָ���Լ���ָ�룬�������м���
	int version;		///�汾��
	int usedBlockNo;	///�Ѿ���ռ�õĿ���
	void* m_firstEmptyAddress;		///ָ�����ȿ��õ��ڴ�����
	UsedBlockStruct blockVect[1];	///�ڴ���ʹ��״����ʵ�ʵ������СӦ����maxBlockCount����
};

static CIntUsageMonitorIndex *pMemoryIndex, *pBlockCountIndex;

CMemoryAllocator::CMemoryAllocator()
{
	if (sizeof(void *)==4)
	{
		/// 32λ����
		dwMemorySize=DEFAULT_MEMORY_SIZE_32*1024l*1024l;
		maxBlockCount=DEFAULT_MAX_BLOCK_COUNT_32;
	}
	else if (sizeof(void *)==8)
	{
		/// 64λ����
		dwMemorySize=DEFAULT_MEMORY_SIZE_64*1024l*1024l;
		maxBlockCount=DEFAULT_MAX_BLOCK_COUNT_64;
	}
	else
	{
		RAISE_RUNTIME_ERROR("Unknown machine word size");
	}
	if (currentConfig!=NULL)
	{
		int memorySize=atoi(currentConfig->getConfig("MemorySize"));
		if (memorySize>0)
		{
			dwMemorySize=memorySize*1024l*1024l;
		}

		int blockCount=atoi(currentConfig->getConfig("MaxBlockCount"));
		if (blockCount>0)
		{
			maxBlockCount=blockCount;
		}
	}
	pMemoryIndex=new CIntUsageMonitorIndex("MemoryDatabase",dwMemorySize/1024l/1024l,20);
	pBlockCountIndex=new CIntUsageMonitorIndex("MDBBlock",maxBlockCount,20);
}

CMemoryAllocator::~CMemoryAllocator()
{
}

void CMemoryAllocator::UpdateUseCount(int value)
{
	m_pHead->usedBlockNo = value;
}

int	CMemoryAllocator::GetUseCount()
{
	return m_pHead->usedBlockNo;
}

void CMemoryAllocator::UpdateEmptyAddress(char *Address)
{
	m_pHead->m_firstEmptyAddress = (void *)Address;
}

char* CMemoryAllocator::GetEmptyAddress()
{
	return (char *)m_pHead->m_firstEmptyAddress;
}

bool CMemoryAllocator::IsBlockUsed(int blockID)
{
	if(blockID >= maxBlockCount)
		return true;
	if(m_pHead->blockVect[blockID].startPosition != NULL)
		return true;
	return false;
}

bool CMemoryAllocator::isValid()
{
	if(m_pHead->m_pthisPoint != &m_pHead)
		return false;
	return true;
}

void CMemoryAllocator::writeLog()
{
	pBlockCountIndex->setValue(GetUseCount());
	pMemoryIndex->setValue(((char *)GetEmptyAddress()-(char *)m_pHead)/1024l/1024l);
}

void* CMemoryAllocator::alloc(int size,int &reuseID,bool isReuse)
{	
	if(!isReuse)		///�����������
	{
		if(reuseID == -1)	///��Allocator�������ID��
		{
			int totalBlock = GetUseCount();
			while(IsBlockUsed(totalBlock))		///�ҵ�һ��δ����Ŀ��õı��
			{
				if (totalBlock >= maxBlockCount)
				{
					RAISE_RUNTIME_ERROR("Insufficient meomry space controled by allocator(block count overflow)");
				}
				totalBlock++;
			}
			reuseID = totalBlock;
			UpdateUseCount(totalBlock);

			void *pEmpty = m_pHead->m_firstEmptyAddress;
			m_pHead->m_firstEmptyAddress = (char *)pEmpty +size;
			if(m_pHead->m_firstEmptyAddress > m_maxEndPosition)	///���������ڴ��ַ�Ѵ��������õ��ڴ�,����!
				RAISE_RUNTIME_ERROR("Insufficient meomry space controled by allocator");
			m_pHead->blockVect[totalBlock].startPosition = pEmpty;
			writeLog();
			return pEmpty;
		}
		else		///���ݴ����ID�������ڴ�
		{	
			if(IsBlockUsed(reuseID))
				return 0;
			void *pEmpty = m_pHead->m_firstEmptyAddress;
			m_pHead->m_firstEmptyAddress = (char *)pEmpty +size;
			m_pHead->blockVect[reuseID].startPosition = pEmpty;
			writeLog();
			return pEmpty;
		}
	}
	else		///��������õ����
	{
		if(IsBlockUsed(reuseID))
		{
			return m_pHead->blockVect[reuseID].startPosition;
		}
	}
	return 0;
}

void CMemoryAllocator::init(bool reuse)
{
	if(!reuse)
	{
		if(m_startPosition == NULL)
			RAISE_RUNTIME_ERROR("Not Enough Memory!");
		m_pHead = (MemoryAllocatorHead *)m_startPosition;
		m_pHead->m_pthisPoint = (void *)m_startPosition;
		m_pHead->version = 1;
		m_pHead->m_firstEmptyAddress = m_startPosition + sizeof(MemoryAllocatorHead)+sizeof(UsedBlockStruct)*(maxBlockCount-1);
		m_pHead->usedBlockNo = RESERVE_BLOCK_ID;
		for(int i =0;i<maxBlockCount;i++)
		{
			m_pHead->blockVect[i].startPosition = NULL;
		}
		m_maxEndPosition = m_startPosition + dwMemorySize;	///������������ڴ��λ��
	}
	else
	{
		if(!isValid())
			RAISE_RUNTIME_ERROR("Invalid Memory Reuse!");
		m_pHead = (MemoryAllocatorHead *)m_startPosition;
		if(m_pHead == NULL)
			RAISE_RUNTIME_ERROR("Reuse Memory Error!");
	}	
}

CNormalMemoryAllocator::CNormalMemoryAllocator()
{
}

void CNormalMemoryAllocator::init(bool reuse)
{	
	if(!reuse)
	{
		m_startPosition = new char[dwMemorySize];
		CMemoryAllocator::init(reuse);
	}
	else
	{
		RAISE_DESIGN_ERROR("Normal memory can not reuse");
	}
}


CShareMemoryAllocator::CShareMemoryAllocator()
{
}

void CShareMemoryAllocator::init(bool reuse)
{
	if(!reuse)
	{
		ALLOC_SHARE_MEMORY(&m_startPosition,SHARE_MEMORY_START_ID,dwMemorySize);
	}
	else
	{
		REUSE_SHARE_MEMORY(&m_startPosition,SHARE_MEMORY_START_ID,dwMemorySize);
	}
	CMemoryAllocator::init(reuse);
}



