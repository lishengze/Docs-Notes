// OfpData.cpp: 
//
//////////////////////////////////////////////////////////////////////

#include "OfpData.h"

!!enter OFP!!
!!travel packages!!

void dumpOFPField(COFP!!@name!!Field *pField)
{
	NET_PACKAGE_LOG0("COFP!!@name!! = {\n");
	!!if atoi(@son_size)>0!!
	char buffer[1024];
	!!endif!!
	!!travel self!!
		pField->!!@name!!.getString(buffer);
		NET_PACKAGE_LOG1("\t!!@name!! = %s [!!@comment!!]\n",buffer);
	!!next!!
	NET_PACKAGE_LOG0("}\n");
}

!!next!!

WORD GetOFPVary(const char *command)
{
!!travel packages!!
!!if !strcmp(@isUp,"yes")!!
	if (!strcmp(command,"!!@comm!!"))
	{
		return OFP_VARY_!!@name!!;
	}
!!endif!!
!!next!!
	return 0;
}

