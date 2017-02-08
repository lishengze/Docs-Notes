/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CDatabaseDataFactory.h
///@brief��������CDatabaseDataFactory
///@history 
///20020214	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CDATABASEDATAFACTORY_H
#define CDATABASEDATAFACTORY_H

#include "CBaseObject.h"
#include "CFixMem.h"
#include "CConfig.h"
#include "Allocator.h"

const int MDB_DEFAULT_BLOCK_SIZE = 4096;

/////////////////////////////////////////////////////////////////////////
///CDatabaseDataFactory��һ������Ľ������ڲ����ݶ��󹤳�����ʹ��CFixMem������
///ȫ�����ݣ������ڲ����ݶ���Ĵ�����ɾ�������ĺ��滻���ܡ������һ���ڲ���������
///��Ϊ�����ݿ��е�һ�У���ô�ڲ����ݶ��󹤳����൱��һ����������������Ľ�����
///�ڲ�������Ҫ�ֱ�̳�����࣬ʵ���Լ��Ķ��󹤳���
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CDatabaseDataFactory : public CBaseObject
{
public:
	///���췽�����������Լ���CFixMem
	///@param	unitSize	ÿ�����ݶ���Ĵ�С
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CDatabaseDataFactory(int unitSize, int maxUnit,IMemoryAllocator *pAllocator,bool reuse=false, int reuseID = -1, int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDatabaseDataFactory(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///��ȡ��CDatabaseDataFactory���Ѿ��еļ�¼����
	///@return	��¼����
	int getCount(void)
	{
		return pMem->getCount();
	}

	///��ȡָ��CDatabaseDataFactory�����м�¼������ָ��
	///@return	ָ��CDatabaseDataFactory�����м�¼������ָ��
	const int *getCountPtr(void)
	{
		return pMem->GetCountPtr();
	}

	
	///������еļ�¼
	virtual void clearAll(void);

	///��CSV�ļ��ж�ȡ���еĶ���
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename)=0;

	///��CSV�ļ��ж�ȡ���еĶ����ļ��������������ļ��еĶ���
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig)=0;
	
	///��CSV�ļ���д�����еĶ���
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename)=0;

	///��CSV�ļ���д�����еĶ����ļ��������������ļ��еĶ���
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig)=0;

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *)=0;

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename)=0;

	int	getReuseID();

protected:
	///����һ������
	///@return	ָ���������λ�õ�ָ��
	void *createObject(void)
	{
		return pMem->alloc();
	}
	
	///ɾ��һ������
	///@param	pObject	ָ����������ָ��
	void deleteObject(void *pObject)
	{
		pMem->free(pObject);
	}

	///���ڴ�����ݵ�CFixMem
	CFixMem *pMem;
	
	///���������
	int maxUnit;
};

#endif
