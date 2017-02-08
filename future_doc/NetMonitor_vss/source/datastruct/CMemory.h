/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CMemory.h
///@brief��������CMemory���stringMemoryȫ�ֱ���
///@history 
///20020214	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CMEMORY_H
#define CMEMORY_H

#include "platform.h"
#include "CBaseObject.h"

///������ȱʡ��ÿ���ڴ���С
#define BLOCK_SIZE 10240

/////////////////////////////////////////////////////////////////////////
///CMemory��һ�������ڴ����Ķ�����������ڴ������Ǳ䳤�ģ��ܴ�Сֻ�ᵥ��������
///������١�������С��ģ���ַ����ڴ�ռ����
///@author	���ض�
///@version	1.0,20020214
/////////////////////////////////////////////////////////////////////////
class CMemory: public CBaseObject
{
public:
	///���캯��������ָ����blockSize����ʼ��ϵͳ����ռ䣬�Ա��ṩ����
	///@param	blockSize	ÿ���ڴ������Ĵ�С��������ڴ��������ָ
	///			�Ѿ�������ڴ��������ǣ�������ÿ��׷������
	///			�Ŀ��С������������ȱʡΪBLOCK_SIZE
	CMemory(int blockSize=BLOCK_SIZE);
	
	///����������û��ʵ�ʹ���
	virtual ~CMemory(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///����ָ����С��һ�οռ�
	///@param	size	Ҫ����Ŀռ��С����byte��
	///@return	ָ�����뵽�Ŀռ���׵�ַ
	///@exception	CDesignError	�����������Ŀռ䳬��blockSize����ô�׳����쳣
	char *alloc(int size);

	///����һ���ַ�����������strlen(s)+1��С�Ŀռ�
	///@param	s	Ҫ���Ƶ��ַ���
	///@return	���Ƶõ����ַ����׵�ַ
	char *dup(char *s);

	///����һ�οռ䣬������size��С�Ŀռ�
	///@param	buffer	Ҫ���ƵĿռ���׵�ַ
	///@param	size	Ҫ���ƵĿռ�Ĵ�С
	///@return	���Ƶõ��Ŀռ��׵�ַ
	char *dup(char *buffer, int size);
private:
	///����һ���µ��ڴ棬���С��blockSizeָ����
	///@exception	CRuntimeError	���ڴ治��ʱ�׳����쳣
	void newBlock(void);
	
	///���ڴ洢ÿ���ڴ������Ĵ�С
	int blockSize;
	
	///���ڴ洢��ǰ�ڴ��������׵�ַ
	char *base;
	
	///���ڴ洢��ǰ������л�û��ʹ�õĿռ���׵�ַ
	char *current;
};

///ȫ�ֱ��������ڸ���ϵͳ�����ַ����ռ�
extern CMemory stringMemory;

#endif
