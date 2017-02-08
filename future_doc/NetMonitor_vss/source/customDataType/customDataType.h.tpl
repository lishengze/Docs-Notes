!!enter UFDataTypes!!
/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file customDataType.h
///@brief�����˽������ڲ����ݵĵײ�֧����
///@history 
///20050324	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CUSTOMDATATYPE_H
#define CUSTOMDATATYPE_H

#include "UFDataType.h"

!!travel self!!
/////////////////////////////////////////////////////////////////////////
///C!!@name!!Type��һ��!!@label!!��
/////////////////////////////////////////////////////////////////////////
!!if !strcmp(@name,"RangeInt")!!
DefineRangeIntType(!!@from!!,!!@to!!,!!@typename!!Type)

!!elseif !strcmp(@name,"RangeChar")!!
DefineRangeCharType(!!@from!!,!!@to!!,!!@typename!!Type)

!!elseif !strcmp(@name,"String")!!
DefineStringType(!!@length!!,!!@typename!!Type)

!!elseif !strcmp(@name,"VString")!!
DefineStringType(!!@length!!,!!@typename!!Type)

!!elseif !strcmp(@name,"Array")!!
DefineStringType(!!@length!!,!!@typename!!Type)

!!elseif !strcmp(@name,"Int")!!
DefineUFType(UFIntType,!!@typename!!Type)

!!elseif !strcmp(@name,"Word")!!
DefineUFType(UFWordType,!!@typename!!Type)

!!elseif !strcmp(@name,"QWord")!!
DefineUFType(UFQWordType,!!@typename!!Type)

!!elseif !strcmp(@name,"Char")!!
DefineUFType(UFCharType,!!@typename!!Type)

!!elseif !strcmp(@name,"EnumChar")!!
!!travel self!!
///!!@label!!
#define !!@prefix!!_!!@name!! '!!@value!!'
!!next!!
DefineEnumCharType(!!@typename!!Type,"!!travel self!!!!@value!!!!next!!")

!!elseif !strcmp(@name,"Float")!!
DefineFloatType(!!@length!!,!!@precision!!,!!@typename!!Type)

!!elseif !strcmp(@name,"FixNumber")!!
//DefineFixNumberType(!!@length!!,!!@precision!!,!!@typename!!Type)
DefineFloatType(!!@length!!,!!@precision!!,!!@typename!!Type)

!!elseif !strcmp(@name,"Pointer")!!
DefineUFType(UFPointerType,!!@typename!!Type)

!!else!!
	!!error printf("unknown type %s in %s\n",@name,@typename);!!
!!endif!!
!!next!!
#endif
!!leave!!