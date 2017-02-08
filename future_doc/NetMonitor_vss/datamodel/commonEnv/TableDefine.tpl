!!function!!
#include <vector>
using namespace std;

typedef struct
{
	char *schema;
	char *table;
	char *column;
	char *type;
	char *iskey;
	char *notnull;
	int   cnt;
} TTable;


class CTable: protected vector<TTable>
{
public:
	void add(char *schema,char *table,char *column,char *type,char *iskey,char *notnull,int cnt)
	{
		TTable theTable;
		theTable.schema=strdup(schema);
		theTable.table=strdup(table);
		theTable.column=strdup(column);
		theTable.type=strdup(type);
		theTable.iskey=strdup(iskey);
		theTable.notnull=strdup(notnull);
		theTable.cnt=cnt;
		
		push_back(theTable);
	}
	char *find(char *schema, char *table)
	{
		for (it=begin();it<end();it++)
		{
			if ((!strcmp(it->schema,schema)) &&(!strcmp(it->table,table)))
			{
				return it->column;
			}
		}
		return "";
	}
	char *type()
	{
		if(it<end())
		{
			return it->type;
		}
		else
		{
			return "";
		}
	}
	
	char *iskey()
	{
		if(it<end())
		{
			return it->iskey;
		}
		else
		{
			return "";
		}
	}
	
	char *notnull()
	{
		if(it<end())
		{
			return it->notnull;
		}
		else
		{
			return "";
		}
	}
	
	int  cnt()
	{
		if(it<end())
		{
			return it->cnt;
		}
		else
		{
			return 0;
		}
	}
	
	char *findNext(char *schema, char *table)
	{
		it++;
		for (;it<end();it++)
		{
			if ((!strcmp(it->schema,schema)) &&(!strcmp(it->table,table)))
			{
				return it->column;
			}
		}
		return "";
	}
	void print()
	{
		for (it=begin();it<end();it++)
		{
			printf("%s %s %s %s %s %s %1d\n",it->schema,it->table,it->column,it->type,it->iskey,it->notnull,it->cnt);	
		}
	}

	iterator it;
};

CTable tables;
int cnt;

!!endfunction!!
!!enter DB!!
	!!travel schemas!!
		!!let schemaName=@name!!
		!!travel self!!
			!!let tableGroupName=@name!!
			!!enter DB!!
			!!travel tableGroups!!
				!!if !strcmp(@group,@tableGroupName) !!
					!!travel self!!
						!!let tableName=@name!!
						!!command cnt=length("Columns")!!
						!!travel Columns!!
							!!if valid_name("iskey")!!
								!!let iskeyStr=@iskey!!
							!!else!!
								!!let iskeyStr=""!!
							!!endif!!
							!!if valid_name("notnull")!!
								!!let notnullStr=@notnull!!
							!!else!!
								!!let notnullStr=""!!
							!!endif!!
							!!command tables.add(@schemaName,@tableName,@name,@basetype,@iskeyStr,@notnullStr,cnt)!!
						!!next!!
					!!next!!
				!!endif!!
			!!next!!
			!!leave!!
		!!next!!
	!!next!!
!!leave!!