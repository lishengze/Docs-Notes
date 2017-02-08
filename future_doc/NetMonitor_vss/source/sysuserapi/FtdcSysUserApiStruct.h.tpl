/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
///20070227	zhangjie		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSSTRUCT_H)
#define _FTDCSYSSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcSysUserApiDataType.h"

!!enter FTD!!
!!travel fields!!
///!!@comment!!
struct CShfeFtdc!!@name!!Field
{
!!travel self!!
	///!!@description!!
	TShfeFtdc!!show_string(@type+1)!!	!!@name!!;
!!next!!
};

!!next!!

!!leave!!  

#endif
