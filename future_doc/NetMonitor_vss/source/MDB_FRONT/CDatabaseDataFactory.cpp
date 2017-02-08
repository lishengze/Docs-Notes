/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CDatabaseDataFactory.cpp
///@briefʵ������CDatabaseDataFactory
///@history 
///20020214	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "CDatabaseDataFactory.h"


CDatabaseDataFactory::CDatabaseDataFactory(int unitSize, int maxUnit,IMemoryAllocator *pAllocator,bool reuse, int reuseID, int readOnly)
{
	if(maxUnit == 0)	///���Ϊ0������Ϊ��ȱʡֵ
		maxUnit = MDB_DEFAULT_BLOCK_SIZE;
	pMem=new CFixMem(unitSize,maxUnit,pAllocator,reuse,reuseID,readOnly);
	if (pMem==NULL)
		RAISE_RUNTIME_ERROR("Insufficient memory space");
	this->maxUnit=maxUnit;
}

CDatabaseDataFactory::~CDatabaseDataFactory(void)
{
	CHECK_TYPE("CDatabaseDataFactory");
	delete pMem;
}

int CDatabaseDataFactory::isA(char *objectType)
{
	if (!strcmp(objectType,"CDatabaseDataFactory"))
		return 1;
	return CBaseObject::isA(objectType);
}

char *CDatabaseDataFactory::getType(void)
{
	return "CDatabaseDataFactory";
}

void CDatabaseDataFactory::output(CLogger *pLogger,int indent)
{
	CHECK_TYPE("CDatabaseDataFactory");
	pLogger->output(indent,0,"CDatabaseDataFactory:max_unit=%d",maxUnit);
	pMem->output(pLogger,indent+1);
}

void CDatabaseDataFactory::clearAll(void)
{
	pMem->freeAll();
}

int	CDatabaseDataFactory::getReuseID()
{
	return pMem->GetReuseID();
}
