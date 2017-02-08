// OfpData.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OFPDATA_H)
#define _OFPDATA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OFPDataType.h"

!!enter OFP!!
!!travel packages!!
//!!@comment!!
const WORD OFP_VARY_!!@name!! = !!@vary!!;

struct COFP!!@name!!Field
{
!!travel self!!
	//!!@comment!!
	!!if valid_name("length")!!
	COFP!!@type!!Type<!!@length!!> !!@name!!;
	!!else!!
	COFP!!@type!!Type !!@name!!;
	!!endif!!
!!next!!
};

void dumpOFPField(COFP!!@name!!Field *pField);

!!next!!

///获取命令字理应对应的vary值
///@param	command	命令字
///@return	对应的vary值
WORD GetOFPVary(const char *command);

#endif
