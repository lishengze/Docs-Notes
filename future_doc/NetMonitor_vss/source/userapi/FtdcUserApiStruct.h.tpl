!!let exchangeid=""!!
!!let functionid=""!!
!!let macroid=""!!
!!let fileid=""!!
!!enter exchangeinfo!!
!!travel self!!
!!if @pumpid==0!!
!!let exchangeid=@name!!
!!elseif @pumpid==1!!
!!let functionid=@name!!
!!elseif @pumpid==2!!
!!let macroid=@name!!
!!elseif @pumpid==3!!
!!let fileid=@name!!
!!endif!!
!!next!!
!!leave!!
/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file !!@fileid!!FtdcUserApiStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
///20060106	赵鸿昊		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSTRUCT_H)
#define _FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "!!@fileid!!FtdcUserApiDataType.h"

!!enter FTD!!
!!travel fields!!
!!if strcmp(@version, "0") !!
///!!@comment!!
struct C!!@functionid!!Ftdc!!@name!!Field
{
!!travel self!!
	///!!@description!!
	T!!@functionid!!Ftdc!!show_string(@type+1)!!	!!@name!!;
!!next!!
};

!!endif!!
!!next!!

!!leave!!  

#endif
