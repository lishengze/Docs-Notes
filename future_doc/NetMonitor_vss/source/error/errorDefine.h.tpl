!!enter errors!!
/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file errorDefine.h
///@brief定义了各种错误
///@history 
///20060114	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef ERRORDEFINE_H
#define ERRORDEFINE_H

#include "CErrorEngine.h"

!!travel self!!
#define ERROR_!!@id!! !!@value!!
!!next!!

///定义所有的错误
///@param	pEngine	要定义错误的错误引擎
void defineErrors(CErrorEngine *pEngine);

#endif
!!leave!!
