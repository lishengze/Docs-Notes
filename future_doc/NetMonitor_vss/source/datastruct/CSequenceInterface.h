/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CSequenceInterface.h
///@brief定义了接口CSequenceInterface
///@history 
///20041001	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef CSEQUENCEINTERFACE_H
#define CSEQUENCEINTERFACE_H

#include "CBaseObject.h"

/////////////////////////////////////////////////////////////////////////
///CSequenceInterface是一个定义序列的接口
///@author	王肇东
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CSequenceInterface: public CBaseObject
{
public:
	///构造方法，创建此序列
	CSequenceInterface(void);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CSequenceInterface(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);

	///获取此序列的下一个值
	///@return	下一个值
	virtual int getNextValue(void)=0;

	///获取此需要的当前值
	///@return	当前值
	virtual int getCurrentValue(void)=0;
	
	///初始化该序列
	///@param nCurrValue 序列初始值
	virtual void initValue(int nCurrValue)=0;
};

#endif
