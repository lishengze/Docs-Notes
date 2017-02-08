!!function!!
#include <vector>
using namespace std;

typedef struct
{
	char *typeName;
	char *validString;
}	TTypeDefine;

class CTypeDefines: protected vector<TTypeDefine>
{
public:
	void add(char *typeName,char *validString)
	{
		TTypeDefine theTypeDefine;
		theTypeDefine.typeName=strdup(typeName);
		theTypeDefine.validString=strdup(validString);
		push_back(theTypeDefine);
	}
	char *find(char *typeName)
	{
		iterator it;
		for (it=begin();it<end();it++)
		{
			if (!strcmp(it->typeName,typeName))
			{
				return it->validString;
			}
			char extendTypeName[100];
			sprintf(extendTypeName,"C%sType",it->typeName);
			if (!strcmp(extendTypeName,typeName))
			{
				return it->validString;
			}
		}
		return "CDATA";
	}
};

CTypeDefines typeDefines;

!!endfunction!!
!!enter UFDataTypes!!
!!travel self!!
	!!if !strcmp(@name,"EnumChar")!!
		!!let validString="("!!
		!!travel self!!
			!!if @pumpid!=0!!
				!!let validString=addstring(@validString,"|")!!
			!!endif!!
			!!let validString=multiaddstring(4,@validString,@value,":",@label)!!
			!!let validString=multiaddstring(3,@validString,"|",@value)!!
		!!next!!
		!!let validString=addstring(@validString,")")!!
		!!command typeDefines.add(@typename,@validString)!!
	!!endif!!
!!next!!
!!leave!!
