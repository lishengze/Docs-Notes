// XtpData.h: 
//
///20090118	���ض�		�����˲�ѯ����־��NT-0065��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPDATA_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_)
#define AFX_XTPDATA_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FieldDescribe.h"
#include "customDataType.h"

!!enter XTP!!
!!travel fields!!
///!!@comment!!
class C!!@name!!Field
{
public:
!!travel self!!
	///!!@description!!
	!!@type!!	!!@name!!;
!!next!!
	TYPE_DESCRIPTOR((
	!!travel self!!
		!!if @pumpid!=0!!
		,
		!!endif!!
		TYPE_DESC(!!@name!!)
	!!next!!
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_!!@name!!=!!@fid!!;

!!next!!


!!leave!!  

#endif
