/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CSequenceInterface.h
///@brief�����˽ӿ�CSequenceInterface
///@history 
///20041001	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CSEQUENCEINTERFACE_H
#define CSEQUENCEINTERFACE_H

#include "CBaseObject.h"

/////////////////////////////////////////////////////////////////////////
///CSequenceInterface��һ���������еĽӿ�
///@author	���ض�
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CSequenceInterface: public CBaseObject
{
public:
	///���췽��������������
	CSequenceInterface(void);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSequenceInterface(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);

	///��ȡ�����е���һ��ֵ
	///@return	��һ��ֵ
	virtual int getNextValue(void)=0;

	///��ȡ����Ҫ�ĵ�ǰֵ
	///@return	��ǰֵ
	virtual int getCurrentValue(void)=0;
	
	///��ʼ��������
	///@param nCurrValue ���г�ʼֵ
	virtual void initValue(int nCurrValue)=0;
};

#endif
