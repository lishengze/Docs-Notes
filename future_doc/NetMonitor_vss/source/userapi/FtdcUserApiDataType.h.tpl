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
!!function!!
#include <set>
using namespace std;

struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};

typedef set<char *, ltstr> CTypeSet;
CTypeSet g_setUsedType;

bool InUse(char *name)
{
	char buf[100] = "C";
	strcpy(buf+1, name);
	strcat(buf,"Type");
	return (g_setUsedType.find(buf)!=g_setUsedType.end());
}

!!endfunction!!
!!enter FTD!!
!!enter fields!!
!!travel self!!
!!travel self!!
!!command g_setUsedType.insert(@type);!!
!!next!!
!!next!!
!!leave!!
/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file !!@fileid!!FtdcUserApiDataType.h
///@brief 定义了客户端接口使用的业务数据类型
///@history 
///20060106	赵鸿昊		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef FTDCDATATYPE_H
#define FTDCDATATYPE_H

enum TE_RESUME_TYPE
{
	TERT_RESTART = 0,
	TERT_RESUME,
	TERT_QUICK
};

!!travel flows!!
const int !!@macroid!!_TSS_!!@name!! = !!@seqseries!!;		//!!@comment!!
!!next!!

!!enter types!!
!!travel self!!
!!if InUse(@typename)!!
/////////////////////////////////////////////////////////////////////////
///TFtdc!!@typename!!Type是一个!!@label!!类型
/////////////////////////////////////////////////////////////////////////
!!if !strcmp(@name,"RangeInt")!!
typedef int T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"RangeChar")!!
typedef char T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"String")!!
typedef char T!!@functionid!!Ftdc!!@typename!!Type[!!show_value(atoi(@length)+1)!!];

!!elseif !strcmp(@name,"VString")!!
typedef char T!!@functionid!!Ftdc!!@typename!!Type[!!show_value(atoi(@length)+1)!!];

!!elseif !strcmp(@name,"Array")!!
typedef char T!!@functionid!!Ftdc!!@typename!!Type[!!show_value(atoi(@length)+1)!!];

!!elseif !strcmp(@name,"Int")!!
typedef int T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"Word")!!
typedef short T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"Char")!!
typedef char T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"EnumChar")!!
!!travel self!!
///!!@label!!
#define !!@macroid!!_FTDC_!!@prefix!!_!!@name!! '!!@value!!'
!!next!!

typedef char T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"Float")!!
typedef double T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"FixNumber")!!
typedef double T!!@functionid!!Ftdc!!@typename!!Type;

!!elseif !strcmp(@name,"Pointer")!!
typedef char *T!!@functionid!!Ftdc!!@typename!!Type;

!!else!!
	!!error printf("unknown type %s in %s\n",@name,@typename);!!
!!endif!!
!!endif!!
!!next!!
!!leave!!
#endif
!!leave!!