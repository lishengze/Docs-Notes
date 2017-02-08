/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CMemorySequence.h
///@brief��������CMemorySequence
///@history 
///20041001	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CMEMORYSEQUENCE_H
#define CMEMORYSEQUENCE_H

#include "CSequenceInterface.h"

/////////////////////////////////////////////////////////////////////////
///CMemorySequence��һ�����ڴ��ж������е���
///@author	���ض�
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CMemorySequence: public CSequenceInterface
{
public:
	///���췽��������������
	///@param	startValue	��ϵ�е���ʼֵ
	CMemorySequence(int startValue=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMemorySequence(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///��ȡ�����е���һ��ֵ
	///@return	��һ��ֵ
	virtual int getNextValue(void);

	///��ȡ����Ҫ�ĵ�ǰֵ
	///@return	��ǰֵ
	virtual int getCurrentValue(void);

	///��ʼ��������
	///@param nCurrValue ���г�ʼֵ
	virtual void initValue(int nCurrValue);
private:
	int m_CurrentValue;
	int m_StartValue;
};

#endif
