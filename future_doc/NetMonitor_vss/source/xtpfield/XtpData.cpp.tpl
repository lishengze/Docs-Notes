// XtpData.cpp: 
//
///20090118	���ض�		�����˲�ѯ����־��NT-0065��
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "XtpData.h"
#include "XtpPackageDesc.h"

/*** Ӧ��ҵ��FieldID ***/
!!enter XTP!!
!!travel fields!!
REGISTER_FIELD(FID_!!@name!!, C!!@name!!Field, "!!@comment!!");

bool C!!@name!!Field::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=!!show_value strlen(@name)!!;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"!!@name!!");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	!!travel self!!
	!!@name!!.getString(buf);
	thisLen=!!show_value strlen(@name)!!+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",!!@name!!,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	!!next!!
	
	return true;
}

!!next!!
!!leave!!
