/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CMemory.cpp
///@brief������ʵ��CMemory��Ͷ���stringMemoryȫ�ֱ���
///@history 
///20020214	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "CBaseObject.h"
#include "CMemory.h"

CMemory::CMemory(int blockSize)
{
	this->blockSize=blockSize;
	newBlock();
}

CMemory::~CMemory(void)
{
	CHECK_TYPE("CMemory");
	/// we needn't free any memory
}

int CMemory::isA(char *objectType)
{
	if (!strcmp(objectType,"CMemory"))
		return 1;
	return CBaseObject::isA(objectType);
}

char *CMemory::getType(void)
{
	return "CMemory";
}


void CMemory::output(CLogger *pLogger,int indent)
{
	CHECK_TYPE("CMemory");
	pLogger->output(indent,0,"CMemory:block_size=%d,offset=%d",blockSize,current-base);
}

char *CMemory::alloc(int size)
{
	char *ptr;

	CHECK_TYPE("CMemory");
	if (size>blockSize)
		RAISE_DESIGN_ERROR("too large single memory alloc");
	if (blockSize-(current-base)<size)
	{
		newBlock();
	}
	ptr=current;
	current+=size;
	return ptr;
}

char *CMemory::dup(char *s)
{
	char *ptr;

	ptr=alloc(strlen(s)+1);
	strcpy(ptr,s);
	return ptr;
}

char *CMemory::dup(char *buffer, int size)
{
	char *ptr;

	ptr=alloc(size);
	memcpy(ptr,buffer,size);
	return ptr;
}

void CMemory::newBlock(void)
{
	base=(char *)malloc(blockSize);
	if (base==NULL)
		RAISE_RUNTIME_ERROR("No enough memory");
	current=base;
}

CMemory stringMemory;
