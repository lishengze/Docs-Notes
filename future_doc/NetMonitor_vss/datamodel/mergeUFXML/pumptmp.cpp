/* generated file, do not change it */

#include "pump.h"

#line 1 "..\\commonEnv\\setCommand.tpl"

#include <vector>
using namespace std;

typedef struct
{
	char *keyName;
	char *tableName;
	int setIsKey;
	int setNotNull;
}	TSetColumn;

typedef struct
{
	char *keyName;
	char *tableName;
	int setUnique;
	int setDelete;
}	TSetIndex;

vector<TSetColumn> setColumns;
vector<TSetIndex> setIndexes;

void startSetCommand(void)
{
	setColumns.clear();
	setIndexes.clear();
}

char *tryGetString(char *name)
{
	if (!valid_name(name))
	{
		return NULL;
	}
	return get_string(name);
}

int getSetting(char *name)
{
	char *value=tryGetString(name);
	
	if (value==NULL)
	{
		return 0;
	}
	if (!strcmp(value,"yes"))
	{
		return 1;
	}
	return -1;
}

void addSetCommand(void)
{
	char *name=get_string("name");
	
	if (!strcmp(name,"setColumn"))
	{
		TSetColumn setColumn;
		
		setColumn.keyName=tryGetString("columnName");
		setColumn.tableName=tryGetString("tableName");
		setColumn.setIsKey=getSetting("setIskey");
		setColumn.setNotNull=getSetting("setNotnull");
		
		setColumns.push_back(setColumn);
	}
	else if (!strcmp(name,"setIndex"))
	{
		TSetIndex setIndex;

		setIndex.keyName=tryGetString("indexName");
		setIndex.tableName=tryGetString("tableName");
		setIndex.setUnique=getSetting("setUnique");
		setIndex.setDelete=getSetting("setDelete");
		
		setIndexes.push_back(setIndex);
	}
	else
	{
		printf("unknown set command %s\n",name);
		exit(1);
	}
}

#define getItem(group,tableValue,keyValue,valueName)		\
	for (int i=0;i<group.size();i++)			\
	{							\
		if (!strcmp(group.at(i).keyName,keyValue))	\
		{						\
			if ((group.at(i).tableName==NULL)||!strcmp(group.at(i).tableName,tableValue))	\
			{					\
				if (group.at(i).valueName==1)	\
				{				\
					return 1;		\
				}				\
				if (group.at(i).valueName==-1)	\
				{				\
					return 0;		\
				}				\
				break;				\
			}					\
		}						\
	}

int isNotNull(char *tableName)
{
	char *columnName=get_string("name");
	
	getItem(setColumns,tableName,columnName,setNotNull);

	if (!strcmp(get_string("notnull"),"yes"))
	{
		return 1;
	}
	return 0;
}

int isKey(char *tableName)
{
	char *columnName=get_string("name");

	getItem(setColumns,tableName,columnName,setIsKey);

	if (!strcmp(get_string("iskey"),"yes"))
	{
		return 1;
	}
	return 0;
}

int isUnique(char *tableName)
{
	char *indexName=get_string("name");
	
	getItem(setIndexes,tableName,indexName,setUnique);

	if (!strcmp(get_string("unique"),"yes"))
	{
		return 1;
	}
	return 0;
}

int isDelete(char *tableName)
{
	char *indexName=get_string("name");
	
	getItem(setIndexes,tableName,indexName,setDelete);

	return 0;
}

void pump(void)
{
	int tmp_value[30];
#line 1 "..\\commonEnv\\DBAll.sql.tpl"
	set_file_name("..\\commonEnv\\DBAll.sql.tpl");
#line 1 "..\\commonEnv\\DBAll.sql.tpl"
	set_line_no(1);
#line 1 "..\\commonEnv\\DBAll.sql.tpl"
	use_pump_command=1;
#line 1 "..\\commonEnv\\setCommand.tpl"
	set_file_name("..\\commonEnv\\setCommand.tpl");
#line 1 "..\\commonEnv\\setCommand.tpl"
	set_line_no(1);
#line 1 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 1 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 2 "..\\commonEnv\\setCommand.tpl"
	set_line_no(2);
#line 2 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 2 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 3 "..\\commonEnv\\setCommand.tpl"
	set_line_no(3);
#line 3 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 3 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 4 "..\\commonEnv\\setCommand.tpl"
	set_line_no(4);
#line 4 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 4 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 5 "..\\commonEnv\\setCommand.tpl"
	set_line_no(5);
#line 5 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 5 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 6 "..\\commonEnv\\setCommand.tpl"
	set_line_no(6);
#line 6 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 6 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 7 "..\\commonEnv\\setCommand.tpl"
	set_line_no(7);
#line 7 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 7 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 8 "..\\commonEnv\\setCommand.tpl"
	set_line_no(8);
#line 8 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 8 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 9 "..\\commonEnv\\setCommand.tpl"
	set_line_no(9);
#line 9 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 9 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 10 "..\\commonEnv\\setCommand.tpl"
	set_line_no(10);
#line 10 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 10 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 11 "..\\commonEnv\\setCommand.tpl"
	set_line_no(11);
#line 11 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 11 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 12 "..\\commonEnv\\setCommand.tpl"
	set_line_no(12);
#line 12 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 12 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 13 "..\\commonEnv\\setCommand.tpl"
	set_line_no(13);
#line 13 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 13 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 14 "..\\commonEnv\\setCommand.tpl"
	set_line_no(14);
#line 14 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 14 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 15 "..\\commonEnv\\setCommand.tpl"
	set_line_no(15);
#line 15 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 15 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 16 "..\\commonEnv\\setCommand.tpl"
	set_line_no(16);
#line 16 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 16 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 17 "..\\commonEnv\\setCommand.tpl"
	set_line_no(17);
#line 17 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 17 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 18 "..\\commonEnv\\setCommand.tpl"
	set_line_no(18);
#line 18 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 18 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 19 "..\\commonEnv\\setCommand.tpl"
	set_line_no(19);
#line 19 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 19 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 20 "..\\commonEnv\\setCommand.tpl"
	set_line_no(20);
#line 20 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 20 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 21 "..\\commonEnv\\setCommand.tpl"
	set_line_no(21);
#line 21 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 21 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 22 "..\\commonEnv\\setCommand.tpl"
	set_line_no(22);
#line 22 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 22 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 23 "..\\commonEnv\\setCommand.tpl"
	set_line_no(23);
#line 23 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 23 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 24 "..\\commonEnv\\setCommand.tpl"
	set_line_no(24);
#line 24 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 24 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 25 "..\\commonEnv\\setCommand.tpl"
	set_line_no(25);
#line 25 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 25 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 26 "..\\commonEnv\\setCommand.tpl"
	set_line_no(26);
#line 26 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 26 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 27 "..\\commonEnv\\setCommand.tpl"
	set_line_no(27);
#line 27 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 27 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 28 "..\\commonEnv\\setCommand.tpl"
	set_line_no(28);
#line 28 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 28 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 29 "..\\commonEnv\\setCommand.tpl"
	set_line_no(29);
#line 29 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 29 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 30 "..\\commonEnv\\setCommand.tpl"
	set_line_no(30);
#line 30 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 30 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 31 "..\\commonEnv\\setCommand.tpl"
	set_line_no(31);
#line 31 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 31 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 32 "..\\commonEnv\\setCommand.tpl"
	set_line_no(32);
#line 32 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 32 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 33 "..\\commonEnv\\setCommand.tpl"
	set_line_no(33);
#line 33 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 33 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 34 "..\\commonEnv\\setCommand.tpl"
	set_line_no(34);
#line 34 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 34 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 35 "..\\commonEnv\\setCommand.tpl"
	set_line_no(35);
#line 35 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 35 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 36 "..\\commonEnv\\setCommand.tpl"
	set_line_no(36);
#line 36 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 36 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 37 "..\\commonEnv\\setCommand.tpl"
	set_line_no(37);
#line 37 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 37 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 38 "..\\commonEnv\\setCommand.tpl"
	set_line_no(38);
#line 38 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 38 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 39 "..\\commonEnv\\setCommand.tpl"
	set_line_no(39);
#line 39 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 39 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 40 "..\\commonEnv\\setCommand.tpl"
	set_line_no(40);
#line 40 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 40 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 41 "..\\commonEnv\\setCommand.tpl"
	set_line_no(41);
#line 41 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 41 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 42 "..\\commonEnv\\setCommand.tpl"
	set_line_no(42);
#line 42 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 42 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 43 "..\\commonEnv\\setCommand.tpl"
	set_line_no(43);
#line 43 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 43 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 44 "..\\commonEnv\\setCommand.tpl"
	set_line_no(44);
#line 44 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 44 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 45 "..\\commonEnv\\setCommand.tpl"
	set_line_no(45);
#line 45 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 45 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 46 "..\\commonEnv\\setCommand.tpl"
	set_line_no(46);
#line 46 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 46 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 47 "..\\commonEnv\\setCommand.tpl"
	set_line_no(47);
#line 47 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 47 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 48 "..\\commonEnv\\setCommand.tpl"
	set_line_no(48);
#line 48 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 48 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 49 "..\\commonEnv\\setCommand.tpl"
	set_line_no(49);
#line 49 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 49 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 50 "..\\commonEnv\\setCommand.tpl"
	set_line_no(50);
#line 50 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 50 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 51 "..\\commonEnv\\setCommand.tpl"
	set_line_no(51);
#line 51 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 51 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 52 "..\\commonEnv\\setCommand.tpl"
	set_line_no(52);
#line 52 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 52 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 53 "..\\commonEnv\\setCommand.tpl"
	set_line_no(53);
#line 53 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 53 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 54 "..\\commonEnv\\setCommand.tpl"
	set_line_no(54);
#line 54 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 54 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 55 "..\\commonEnv\\setCommand.tpl"
	set_line_no(55);
#line 55 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 55 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 56 "..\\commonEnv\\setCommand.tpl"
	set_line_no(56);
#line 56 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 56 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 57 "..\\commonEnv\\setCommand.tpl"
	set_line_no(57);
#line 57 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 57 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 58 "..\\commonEnv\\setCommand.tpl"
	set_line_no(58);
#line 58 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 58 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 59 "..\\commonEnv\\setCommand.tpl"
	set_line_no(59);
#line 59 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 59 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 60 "..\\commonEnv\\setCommand.tpl"
	set_line_no(60);
#line 60 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 60 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 61 "..\\commonEnv\\setCommand.tpl"
	set_line_no(61);
#line 61 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 61 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 62 "..\\commonEnv\\setCommand.tpl"
	set_line_no(62);
#line 62 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 62 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 63 "..\\commonEnv\\setCommand.tpl"
	set_line_no(63);
#line 63 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 63 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 64 "..\\commonEnv\\setCommand.tpl"
	set_line_no(64);
#line 64 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 64 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 65 "..\\commonEnv\\setCommand.tpl"
	set_line_no(65);
#line 65 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 65 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 66 "..\\commonEnv\\setCommand.tpl"
	set_line_no(66);
#line 66 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 66 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 67 "..\\commonEnv\\setCommand.tpl"
	set_line_no(67);
#line 67 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 67 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 68 "..\\commonEnv\\setCommand.tpl"
	set_line_no(68);
#line 68 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 68 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 69 "..\\commonEnv\\setCommand.tpl"
	set_line_no(69);
#line 69 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 69 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 70 "..\\commonEnv\\setCommand.tpl"
	set_line_no(70);
#line 70 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 70 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 71 "..\\commonEnv\\setCommand.tpl"
	set_line_no(71);
#line 71 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 71 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 72 "..\\commonEnv\\setCommand.tpl"
	set_line_no(72);
#line 72 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 72 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 73 "..\\commonEnv\\setCommand.tpl"
	set_line_no(73);
#line 73 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 73 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 74 "..\\commonEnv\\setCommand.tpl"
	set_line_no(74);
#line 74 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 74 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 75 "..\\commonEnv\\setCommand.tpl"
	set_line_no(75);
#line 75 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 75 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 76 "..\\commonEnv\\setCommand.tpl"
	set_line_no(76);
#line 76 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 76 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 77 "..\\commonEnv\\setCommand.tpl"
	set_line_no(77);
#line 77 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 77 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 78 "..\\commonEnv\\setCommand.tpl"
	set_line_no(78);
#line 78 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 78 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 79 "..\\commonEnv\\setCommand.tpl"
	set_line_no(79);
#line 79 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 79 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 80 "..\\commonEnv\\setCommand.tpl"
	set_line_no(80);
#line 80 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 80 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 81 "..\\commonEnv\\setCommand.tpl"
	set_line_no(81);
#line 81 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 81 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 82 "..\\commonEnv\\setCommand.tpl"
	set_line_no(82);
#line 82 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 82 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 83 "..\\commonEnv\\setCommand.tpl"
	set_line_no(83);
#line 83 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 83 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 84 "..\\commonEnv\\setCommand.tpl"
	set_line_no(84);
#line 84 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 84 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 85 "..\\commonEnv\\setCommand.tpl"
	set_line_no(85);
#line 85 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 85 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 86 "..\\commonEnv\\setCommand.tpl"
	set_line_no(86);
#line 86 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 86 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 87 "..\\commonEnv\\setCommand.tpl"
	set_line_no(87);
#line 87 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 87 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 88 "..\\commonEnv\\setCommand.tpl"
	set_line_no(88);
#line 88 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 88 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 89 "..\\commonEnv\\setCommand.tpl"
	set_line_no(89);
#line 89 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 89 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 90 "..\\commonEnv\\setCommand.tpl"
	set_line_no(90);
#line 90 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 90 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 91 "..\\commonEnv\\setCommand.tpl"
	set_line_no(91);
#line 91 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 91 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 92 "..\\commonEnv\\setCommand.tpl"
	set_line_no(92);
#line 92 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 92 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 93 "..\\commonEnv\\setCommand.tpl"
	set_line_no(93);
#line 93 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 93 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 94 "..\\commonEnv\\setCommand.tpl"
	set_line_no(94);
#line 94 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 94 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 95 "..\\commonEnv\\setCommand.tpl"
	set_line_no(95);
#line 95 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 95 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 96 "..\\commonEnv\\setCommand.tpl"
	set_line_no(96);
#line 96 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 96 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 97 "..\\commonEnv\\setCommand.tpl"
	set_line_no(97);
#line 97 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 97 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 98 "..\\commonEnv\\setCommand.tpl"
	set_line_no(98);
#line 98 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 98 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 99 "..\\commonEnv\\setCommand.tpl"
	set_line_no(99);
#line 99 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 99 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 100 "..\\commonEnv\\setCommand.tpl"
	set_line_no(100);
#line 100 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 100 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 101 "..\\commonEnv\\setCommand.tpl"
	set_line_no(101);
#line 101 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 101 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 102 "..\\commonEnv\\setCommand.tpl"
	set_line_no(102);
#line 102 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 102 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 103 "..\\commonEnv\\setCommand.tpl"
	set_line_no(103);
#line 103 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 103 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 104 "..\\commonEnv\\setCommand.tpl"
	set_line_no(104);
#line 104 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 104 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 105 "..\\commonEnv\\setCommand.tpl"
	set_line_no(105);
#line 105 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 105 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 106 "..\\commonEnv\\setCommand.tpl"
	set_line_no(106);
#line 106 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 106 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 107 "..\\commonEnv\\setCommand.tpl"
	set_line_no(107);
#line 107 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 107 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 108 "..\\commonEnv\\setCommand.tpl"
	set_line_no(108);
#line 108 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 108 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 109 "..\\commonEnv\\setCommand.tpl"
	set_line_no(109);
#line 109 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 109 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 110 "..\\commonEnv\\setCommand.tpl"
	set_line_no(110);
#line 110 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 110 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 111 "..\\commonEnv\\setCommand.tpl"
	set_line_no(111);
#line 111 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 111 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 112 "..\\commonEnv\\setCommand.tpl"
	set_line_no(112);
#line 112 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 112 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 113 "..\\commonEnv\\setCommand.tpl"
	set_line_no(113);
#line 113 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 113 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 114 "..\\commonEnv\\setCommand.tpl"
	set_line_no(114);
#line 114 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 114 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 115 "..\\commonEnv\\setCommand.tpl"
	set_line_no(115);
#line 115 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 115 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 116 "..\\commonEnv\\setCommand.tpl"
	set_line_no(116);
#line 116 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 116 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 117 "..\\commonEnv\\setCommand.tpl"
	set_line_no(117);
#line 117 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 117 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 118 "..\\commonEnv\\setCommand.tpl"
	set_line_no(118);
#line 118 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 118 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 119 "..\\commonEnv\\setCommand.tpl"
	set_line_no(119);
#line 119 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 119 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 120 "..\\commonEnv\\setCommand.tpl"
	set_line_no(120);
#line 120 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 120 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 121 "..\\commonEnv\\setCommand.tpl"
	set_line_no(121);
#line 121 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 121 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 122 "..\\commonEnv\\setCommand.tpl"
	set_line_no(122);
#line 122 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 122 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 123 "..\\commonEnv\\setCommand.tpl"
	set_line_no(123);
#line 123 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 123 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 124 "..\\commonEnv\\setCommand.tpl"
	set_line_no(124);
#line 124 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 124 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 125 "..\\commonEnv\\setCommand.tpl"
	set_line_no(125);
#line 125 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 125 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 126 "..\\commonEnv\\setCommand.tpl"
	set_line_no(126);
#line 126 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 126 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 127 "..\\commonEnv\\setCommand.tpl"
	set_line_no(127);
#line 127 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 127 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 128 "..\\commonEnv\\setCommand.tpl"
	set_line_no(128);
#line 128 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 128 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 129 "..\\commonEnv\\setCommand.tpl"
	set_line_no(129);
#line 129 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 129 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 130 "..\\commonEnv\\setCommand.tpl"
	set_line_no(130);
#line 130 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 130 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 131 "..\\commonEnv\\setCommand.tpl"
	set_line_no(131);
#line 131 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 131 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 132 "..\\commonEnv\\setCommand.tpl"
	set_line_no(132);
#line 132 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 132 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 133 "..\\commonEnv\\setCommand.tpl"
	set_line_no(133);
#line 133 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 133 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 134 "..\\commonEnv\\setCommand.tpl"
	set_line_no(134);
#line 134 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 134 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 135 "..\\commonEnv\\setCommand.tpl"
	set_line_no(135);
#line 135 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 135 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 136 "..\\commonEnv\\setCommand.tpl"
	set_line_no(136);
#line 136 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 136 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 137 "..\\commonEnv\\setCommand.tpl"
	set_line_no(137);
#line 137 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 137 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 138 "..\\commonEnv\\setCommand.tpl"
	set_line_no(138);
#line 138 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 138 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 139 "..\\commonEnv\\setCommand.tpl"
	set_line_no(139);
#line 139 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 139 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 140 "..\\commonEnv\\setCommand.tpl"
	set_line_no(140);
#line 140 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 140 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 141 "..\\commonEnv\\setCommand.tpl"
	set_line_no(141);
#line 141 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 141 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 142 "..\\commonEnv\\setCommand.tpl"
	set_line_no(142);
#line 142 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 142 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 143 "..\\commonEnv\\setCommand.tpl"
	set_line_no(143);
#line 143 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 143 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 144 "..\\commonEnv\\setCommand.tpl"
	set_line_no(144);
#line 144 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 144 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 145 "..\\commonEnv\\setCommand.tpl"
	set_line_no(145);
#line 145 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 145 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 146 "..\\commonEnv\\setCommand.tpl"
	set_line_no(146);
#line 146 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 146 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 147 "..\\commonEnv\\setCommand.tpl"
	set_line_no(147);
#line 147 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 147 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 148 "..\\commonEnv\\setCommand.tpl"
	set_line_no(148);
#line 148 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 148 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 149 "..\\commonEnv\\setCommand.tpl"
	set_line_no(149);
#line 149 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 149 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 150 "..\\commonEnv\\setCommand.tpl"
	set_line_no(150);
#line 150 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 150 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 151 "..\\commonEnv\\setCommand.tpl"
	set_line_no(151);
#line 151 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 151 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 152 "..\\commonEnv\\setCommand.tpl"
	set_line_no(152);
#line 152 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 152 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 153 "..\\commonEnv\\setCommand.tpl"
	set_line_no(153);
#line 153 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 153 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 154 "..\\commonEnv\\setCommand.tpl"
	set_line_no(154);
#line 154 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 154 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 155 "..\\commonEnv\\setCommand.tpl"
	set_line_no(155);
#line 155 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 155 "..\\commonEnv\\setCommand.tpl"
	use_pump_command=1;
#line 155 "..\\commonEnv\\setCommand.tpl"
	display_string("\n");
#line 1 "..\\commonEnv\\DBAll.sql.tpl"
	use_pump_command=1;
#line 1 "..\\commonEnv\\DBAll.sql.tpl"
	display_string("\n");
#line 2 "..\\commonEnv\\DBAll.sql.tpl"
	set_line_no(2);
#line 2 "..\\commonEnv\\DBAll.sql.tpl"
	use_pump_command=1;
#line 2 "..\\commonEnv\\DBAll.sql.tpl"
	enter("DB");
#line 2 "..\\commonEnv\\DBAll.sql.tpl"
	display_string("\n");
#line 3 "..\\commonEnv\\DBAll.sql.tpl"
	set_line_no(3);
#line 3 "..\\commonEnv\\DBAll.sql.tpl"
	display_string("\t");
#line 3 "..\\commonEnv\\DBAll.sql.tpl"
	use_pump_command=1;
#line 3 "..\\commonEnv\\DBAll.sql.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("schemas");tmp_value[0]++)
#line 3 "..\\commonEnv\\DBAll.sql.tpl"
	{
#line 3 "..\\commonEnv\\DBAll.sql.tpl"
		enter_set("schemas",tmp_value[0]);
#line 3 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 4 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(4);
#line 4 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\t\t");
#line 4 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 4 "..\\commonEnv\\DBAll.sql.tpl"
		set_value("schemaName",get_string("name"));
#line 4 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 5 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(5);
#line 5 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("----\\");
#line 5 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 5 "..\\commonEnv\\DBAll.sql.tpl"
		display_name("schemaName");
#line 5 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("_create.sql");
#line 5 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 6 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(6);
#line 6 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 6 "..\\commonEnv\\DBAll.sql.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("self");tmp_value[1]++)
#line 6 "..\\commonEnv\\DBAll.sql.tpl"
		{
#line 6 "..\\commonEnv\\DBAll.sql.tpl"
			enter_set("self",tmp_value[1]);
#line 6 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(7);
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("@");
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			display_name("schemaName");
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("_");
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			display_name("name");
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("_create");
#line 7 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 8 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(8);
#line 8 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 8 "..\\commonEnv\\DBAll.sql.tpl"
			leave();
#line 8 "..\\commonEnv\\DBAll.sql.tpl"
		}
#line 8 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 9 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(9);
#line 9 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("----\\");
#line 9 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 9 "..\\commonEnv\\DBAll.sql.tpl"
		display_name("schemaName");
#line 9 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("_clear.sql");
#line 9 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 10 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(10);
#line 10 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 10 "..\\commonEnv\\DBAll.sql.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("self");tmp_value[1]++)
#line 10 "..\\commonEnv\\DBAll.sql.tpl"
		{
#line 10 "..\\commonEnv\\DBAll.sql.tpl"
			enter_set("self",tmp_value[1]);
#line 10 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(11);
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("@");
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			display_name("schemaName");
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("_");
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			display_name("name");
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("_clear");
#line 11 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 12 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(12);
#line 12 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 12 "..\\commonEnv\\DBAll.sql.tpl"
			leave();
#line 12 "..\\commonEnv\\DBAll.sql.tpl"
		}
#line 12 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 13 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(13);
#line 13 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("----\\");
#line 13 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 13 "..\\commonEnv\\DBAll.sql.tpl"
		display_name("schemaName");
#line 13 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("_drop.sql");
#line 13 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 14 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(14);
#line 14 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 14 "..\\commonEnv\\DBAll.sql.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("self");tmp_value[1]++)
#line 14 "..\\commonEnv\\DBAll.sql.tpl"
		{
#line 14 "..\\commonEnv\\DBAll.sql.tpl"
			enter_set("self",tmp_value[1]);
#line 14 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(15);
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("@");
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			display_name("schemaName");
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("_");
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			display_name("name");
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("_drop");
#line 15 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 16 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(16);
#line 16 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 16 "..\\commonEnv\\DBAll.sql.tpl"
			leave();
#line 16 "..\\commonEnv\\DBAll.sql.tpl"
		}
#line 16 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 17 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(17);
#line 17 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\t\t");
#line 17 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 17 "..\\commonEnv\\DBAll.sql.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("self");tmp_value[1]++)
#line 17 "..\\commonEnv\\DBAll.sql.tpl"
		{
#line 17 "..\\commonEnv\\DBAll.sql.tpl"
			enter_set("self",tmp_value[1]);
#line 17 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 18 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(18);
#line 18 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\t\t\t");
#line 18 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 18 "..\\commonEnv\\DBAll.sql.tpl"
			set_value("groupName",get_string("name"));
#line 18 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 19 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(19);
#line 19 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\t\t\t");
#line 19 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 19 "..\\commonEnv\\DBAll.sql.tpl"
			startSetCommand();;
#line 19 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 20 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(20);
#line 20 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\t\t\t");
#line 20 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 20 "..\\commonEnv\\DBAll.sql.tpl"
			for (tmp_value[2]=0;tmp_value[2]<length("self");tmp_value[2]++)
#line 20 "..\\commonEnv\\DBAll.sql.tpl"
			{
#line 20 "..\\commonEnv\\DBAll.sql.tpl"
				enter_set("self",tmp_value[2]);
#line 20 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\n");
#line 21 "..\\commonEnv\\DBAll.sql.tpl"
				set_line_no(21);
#line 21 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\t\t\t\t");
#line 21 "..\\commonEnv\\DBAll.sql.tpl"
				use_pump_command=1;
#line 21 "..\\commonEnv\\DBAll.sql.tpl"
				addSetCommand();;
#line 21 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\n");
#line 22 "..\\commonEnv\\DBAll.sql.tpl"
				set_line_no(22);
#line 22 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\t\t\t");
#line 22 "..\\commonEnv\\DBAll.sql.tpl"
				use_pump_command=1;
#line 22 "..\\commonEnv\\DBAll.sql.tpl"
				leave();
#line 22 "..\\commonEnv\\DBAll.sql.tpl"
			}
#line 22 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 23 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(23);
#line 23 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\t\t\t");
#line 23 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 23 "..\\commonEnv\\DBAll.sql.tpl"
			enter("DB");
#line 23 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 24 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(24);
#line 24 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\t\t\t\t");
#line 24 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 24 "..\\commonEnv\\DBAll.sql.tpl"
			for (tmp_value[2]=0;tmp_value[2]<length("tableGroups");tmp_value[2]++)
#line 24 "..\\commonEnv\\DBAll.sql.tpl"
			{
#line 24 "..\\commonEnv\\DBAll.sql.tpl"
				enter_set("tableGroups",tmp_value[2]);
#line 24 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\n");
#line 25 "..\\commonEnv\\DBAll.sql.tpl"
				set_line_no(25);
#line 25 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\t\t\t\t\t");
#line 25 "..\\commonEnv\\DBAll.sql.tpl"
				use_pump_command=1;
#line 25 "..\\commonEnv\\DBAll.sql.tpl"
				if (!strcmp(get_string("group"),get_string("groupName")))
#line 25 "..\\commonEnv\\DBAll.sql.tpl"
				{
#line 25 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\n");
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					set_line_no(26);
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("----\\");
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					display_name("schemaName");
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("_");
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					display_name("group");
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("_create.sql");
#line 26 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\n");
#line 27 "..\\commonEnv\\DBAll.sql.tpl"
					set_line_no(27);
#line 27 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 1 "..\\commonEnv\\createTable.sql.tpl"
					set_file_name("..\\commonEnv\\createTable.sql.tpl");
#line 1 "..\\commonEnv\\createTable.sql.tpl"
					set_line_no(1);
#line 1 "..\\commonEnv\\createTable.sql.tpl"
					use_pump_command=1;
#line 1 "..\\commonEnv\\createTable.sql.tpl"
					for (tmp_value[3]=0;tmp_value[3]<length("self");tmp_value[3]++)
#line 1 "..\\commonEnv\\createTable.sql.tpl"
					{
#line 1 "..\\commonEnv\\createTable.sql.tpl"
						enter_set("self",tmp_value[3]);
#line 1 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 2 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(2);
#line 2 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 2 "..\\commonEnv\\createTable.sql.tpl"
						set_value("tableName",get_string("name"));
#line 2 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 3 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(3);
#line 3 "..\\commonEnv\\createTable.sql.tpl"
						display_string("--******************************");
#line 3 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 4 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(4);
#line 4 "..\\commonEnv\\createTable.sql.tpl"
						display_string("--创建");
#line 4 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 4 "..\\commonEnv\\createTable.sql.tpl"
						display_name("title");
#line 4 "..\\commonEnv\\createTable.sql.tpl"
						display_string("表");
#line 4 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 5 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(5);
#line 5 "..\\commonEnv\\createTable.sql.tpl"
						display_string("--******************************");
#line 5 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 6 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(6);
#line 6 "..\\commonEnv\\createTable.sql.tpl"
						display_string("create table t_");
#line 6 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 6 "..\\commonEnv\\createTable.sql.tpl"
						display_name("name");
#line 6 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 7 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(7);
#line 7 "..\\commonEnv\\createTable.sql.tpl"
						display_string("(");
#line 7 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 8 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(8);
#line 8 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 8 "..\\commonEnv\\createTable.sql.tpl"
						set_value("keyList"," ");
#line 8 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 9 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(9);
#line 9 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 9 "..\\commonEnv\\createTable.sql.tpl"
						for (tmp_value[4]=0;tmp_value[4]<length("Columns");tmp_value[4]++)
#line 9 "..\\commonEnv\\createTable.sql.tpl"
						{
#line 9 "..\\commonEnv\\createTable.sql.tpl"
							enter_set("Columns",tmp_value[4]);
#line 9 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(10);
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\t");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							if (tmp_value[4]!=0)
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							{
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								display_string(",");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							}
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							display_name("name");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							display_string(" ");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							display_name("type");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							display_string(" ");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							if (valid_name("default"))
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							{
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								display_string(" default ");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								display_name("default");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								display_string(" ");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							}
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							if (isNotNull(get_string("tableName")))
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							{
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								display_string("not null");
#line 10 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							}
#line 10 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 11 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(11);
#line 11 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\t");
#line 11 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 11 "..\\commonEnv\\createTable.sql.tpl"
							if (isKey(get_string("tableName")))
#line 11 "..\\commonEnv\\createTable.sql.tpl"
							{
#line 11 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 12 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(12);
#line 12 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\t\t");
#line 12 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 12 "..\\commonEnv\\createTable.sql.tpl"
								if (!strcmp(get_string("keyList")," "))
#line 12 "..\\commonEnv\\createTable.sql.tpl"
								{
#line 12 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\n");
#line 13 "..\\commonEnv\\createTable.sql.tpl"
									set_line_no(13);
#line 13 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\t\t\t");
#line 13 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 13 "..\\commonEnv\\createTable.sql.tpl"
									set_value("keyList",get_string("name"));
#line 13 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\n");
#line 14 "..\\commonEnv\\createTable.sql.tpl"
									set_line_no(14);
#line 14 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\t\t");
#line 14 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 14 "..\\commonEnv\\createTable.sql.tpl"
								}
#line 14 "..\\commonEnv\\createTable.sql.tpl"
								else
#line 14 "..\\commonEnv\\createTable.sql.tpl"
								{
#line 14 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\n");
#line 15 "..\\commonEnv\\createTable.sql.tpl"
									set_line_no(15);
#line 15 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\t\t\t");
#line 15 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 15 "..\\commonEnv\\createTable.sql.tpl"
									set_value("keyList",multiaddstring(3,get_string("keyList"),",",get_string("name")));
#line 15 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\n");
#line 16 "..\\commonEnv\\createTable.sql.tpl"
									set_line_no(16);
#line 16 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\t\t");
#line 16 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 16 "..\\commonEnv\\createTable.sql.tpl"
								}
#line 16 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 17 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(17);
#line 17 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\t");
#line 17 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 17 "..\\commonEnv\\createTable.sql.tpl"
							}
#line 17 "..\\commonEnv\\createTable.sql.tpl"
							display_string(" ");
#line 17 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 18 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(18);
#line 18 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 18 "..\\commonEnv\\createTable.sql.tpl"
							leave();
#line 18 "..\\commonEnv\\createTable.sql.tpl"
						}
#line 18 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 19 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(19);
#line 19 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 19 "..\\commonEnv\\createTable.sql.tpl"
						if (strcmp(get_string("keyList")," "))
#line 19 "..\\commonEnv\\createTable.sql.tpl"
						{
#line 19 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(20);
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\t,constraint pk_");
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							display_name("name");
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							display_string(" primary key (");
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							display_name("keyList");
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							display_string(")");
#line 20 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 21 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(21);
#line 21 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 21 "..\\commonEnv\\createTable.sql.tpl"
						}
#line 21 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 22 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(22);
#line 22 "..\\commonEnv\\createTable.sql.tpl"
						display_string(");");
#line 22 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 23 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(23);
#line 23 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(24);
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						display_string("comment on table t_");
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						display_name("name");
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						display_string(" is '");
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						display_name("title");
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						display_string("';");
#line 24 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 25 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(25);
#line 25 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 25 "..\\commonEnv\\createTable.sql.tpl"
						for (tmp_value[4]=0;tmp_value[4]<length("Columns");tmp_value[4]++)
#line 25 "..\\commonEnv\\createTable.sql.tpl"
						{
#line 25 "..\\commonEnv\\createTable.sql.tpl"
							enter_set("Columns",tmp_value[4]);
#line 25 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(26);
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\tcomment on column t_");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_name("tableName");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_string(".");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_name("name");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_string(" is '");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_name("label");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_string("';");
#line 26 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 27 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(27);
#line 27 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 27 "..\\commonEnv\\createTable.sql.tpl"
							leave();
#line 27 "..\\commonEnv\\createTable.sql.tpl"
						}
#line 27 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 28 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(28);
#line 28 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 29 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(29);
#line 29 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 29 "..\\commonEnv\\createTable.sql.tpl"
						for (tmp_value[4]=0;tmp_value[4]<length("Index");tmp_value[4]++)
#line 29 "..\\commonEnv\\createTable.sql.tpl"
						{
#line 29 "..\\commonEnv\\createTable.sql.tpl"
							enter_set("Index",tmp_value[4]);
#line 29 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 30 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(30);
#line 30 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 30 "..\\commonEnv\\createTable.sql.tpl"
							if (!isDelete(get_string("tableName")))
#line 30 "..\\commonEnv\\createTable.sql.tpl"
							{
#line 30 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(31);
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								display_string("--创建");
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								display_name("title");
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								display_string("表的");
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								display_name("label");
#line 31 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(32);
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_string("create ");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								if (isUnique(get_string("tableName")))
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								{
#line 32 "..\\commonEnv\\createTable.sql.tpl"
									display_string("unique");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								}
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_string(" index i_");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_name("tableName");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_string("_");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_name("name");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_string(" on t_");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_name("tableName");
#line 32 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 33 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(33);
#line 33 "..\\commonEnv\\createTable.sql.tpl"
								display_string("(");
#line 33 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 34 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(34);
#line 34 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 34 "..\\commonEnv\\createTable.sql.tpl"
								for (tmp_value[5]=0;tmp_value[5]<length("self");tmp_value[5]++)
#line 34 "..\\commonEnv\\createTable.sql.tpl"
								{
#line 34 "..\\commonEnv\\createTable.sql.tpl"
									enter_set("self",tmp_value[5]);
#line 34 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\n");
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									set_line_no(35);
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\t");
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									if (tmp_value[5]!=0)
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									{
#line 35 "..\\commonEnv\\createTable.sql.tpl"
										display_string(",");
#line 35 "..\\commonEnv\\createTable.sql.tpl"
										use_pump_command=1;
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									}
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									display_name("name");
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									display_string(" ");
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									display_name("order");
#line 35 "..\\commonEnv\\createTable.sql.tpl"
									display_string("\n");
#line 36 "..\\commonEnv\\createTable.sql.tpl"
									set_line_no(36);
#line 36 "..\\commonEnv\\createTable.sql.tpl"
									use_pump_command=1;
#line 36 "..\\commonEnv\\createTable.sql.tpl"
									leave();
#line 36 "..\\commonEnv\\createTable.sql.tpl"
								}
#line 36 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 37 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(37);
#line 37 "..\\commonEnv\\createTable.sql.tpl"
								display_string(");");
#line 37 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 38 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(38);
#line 38 "..\\commonEnv\\createTable.sql.tpl"
								display_string("\n");
#line 39 "..\\commonEnv\\createTable.sql.tpl"
								set_line_no(39);
#line 39 "..\\commonEnv\\createTable.sql.tpl"
								use_pump_command=1;
#line 39 "..\\commonEnv\\createTable.sql.tpl"
							}
#line 39 "..\\commonEnv\\createTable.sql.tpl"
							display_string("\n");
#line 40 "..\\commonEnv\\createTable.sql.tpl"
							set_line_no(40);
#line 40 "..\\commonEnv\\createTable.sql.tpl"
							use_pump_command=1;
#line 40 "..\\commonEnv\\createTable.sql.tpl"
							leave();
#line 40 "..\\commonEnv\\createTable.sql.tpl"
						}
#line 40 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 41 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(41);
#line 41 "..\\commonEnv\\createTable.sql.tpl"
						display_string("\n");
#line 42 "..\\commonEnv\\createTable.sql.tpl"
						set_line_no(42);
#line 42 "..\\commonEnv\\createTable.sql.tpl"
						use_pump_command=1;
#line 42 "..\\commonEnv\\createTable.sql.tpl"
						leave();
#line 42 "..\\commonEnv\\createTable.sql.tpl"
					}
#line 42 "..\\commonEnv\\createTable.sql.tpl"
					display_string("\n");
#line 27 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 27 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\n");
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					set_line_no(28);
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("----\\");
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					display_name("schemaName");
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("_");
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					display_name("group");
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("_clear.sql");
#line 28 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\n");
#line 29 "..\\commonEnv\\DBAll.sql.tpl"
					set_line_no(29);
#line 29 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 1 "..\\commonEnv\\clearTable.sql.tpll"
					set_file_name("..\\commonEnv\\clearTable.sql.tpll");
#line 1 "..\\commonEnv\\clearTable.sql.tpll"
					set_line_no(1);
#line 1 "..\\commonEnv\\clearTable.sql.tpll"
					use_pump_command=1;
#line 1 "..\\commonEnv\\clearTable.sql.tpll"
					for (tmp_value[3]=0;tmp_value[3]<length("self");tmp_value[3]++)
#line 1 "..\\commonEnv\\clearTable.sql.tpll"
					{
#line 1 "..\\commonEnv\\clearTable.sql.tpll"
						enter_set("self",tmp_value[3]);
#line 1 "..\\commonEnv\\clearTable.sql.tpll"
						display_string("\n");
#line 2 "..\\commonEnv\\clearTable.sql.tpll"
						set_line_no(2);
#line 2 "..\\commonEnv\\clearTable.sql.tpll"
						display_string("--清空");
#line 2 "..\\commonEnv\\clearTable.sql.tpll"
						use_pump_command=1;
#line 2 "..\\commonEnv\\clearTable.sql.tpll"
						display_name("title");
#line 2 "..\\commonEnv\\clearTable.sql.tpll"
						display_string("表");
#line 2 "..\\commonEnv\\clearTable.sql.tpll"
						display_string("\n");
#line 3 "..\\commonEnv\\clearTable.sql.tpll"
						set_line_no(3);
#line 3 "..\\commonEnv\\clearTable.sql.tpll"
						display_string("truncate table t_");
#line 3 "..\\commonEnv\\clearTable.sql.tpll"
						use_pump_command=1;
#line 3 "..\\commonEnv\\clearTable.sql.tpll"
						display_name("name");
#line 3 "..\\commonEnv\\clearTable.sql.tpll"
						display_string(";");
#line 3 "..\\commonEnv\\clearTable.sql.tpll"
						display_string("\n");
#line 4 "..\\commonEnv\\clearTable.sql.tpll"
						set_line_no(4);
#line 4 "..\\commonEnv\\clearTable.sql.tpll"
						display_string("\n");
#line 5 "..\\commonEnv\\clearTable.sql.tpll"
						set_line_no(5);
#line 5 "..\\commonEnv\\clearTable.sql.tpll"
						use_pump_command=1;
#line 5 "..\\commonEnv\\clearTable.sql.tpll"
						leave();
#line 5 "..\\commonEnv\\clearTable.sql.tpll"
					}
#line 5 "..\\commonEnv\\clearTable.sql.tpll"
					display_string("\n");
#line 29 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 29 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\n");
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					set_line_no(30);
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("----\\");
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					display_name("schemaName");
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("_");
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					display_name("group");
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("_drop.sql");
#line 30 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\n");
#line 31 "..\\commonEnv\\DBAll.sql.tpl"
					set_line_no(31);
#line 31 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 1 "..\\commonEnv\\dropTable.sql.tplll"
					set_file_name("..\\commonEnv\\dropTable.sql.tplll");
#line 1 "..\\commonEnv\\dropTable.sql.tplll"
					set_line_no(1);
#line 1 "..\\commonEnv\\dropTable.sql.tplll"
					use_pump_command=1;
#line 1 "..\\commonEnv\\dropTable.sql.tplll"
					for (tmp_value[3]=0;tmp_value[3]<length("self");tmp_value[3]++)
#line 1 "..\\commonEnv\\dropTable.sql.tplll"
					{
#line 1 "..\\commonEnv\\dropTable.sql.tplll"
						enter_set("self",tmp_value[3]);
#line 1 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("\n");
#line 2 "..\\commonEnv\\dropTable.sql.tplll"
						set_line_no(2);
#line 2 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("--删除");
#line 2 "..\\commonEnv\\dropTable.sql.tplll"
						use_pump_command=1;
#line 2 "..\\commonEnv\\dropTable.sql.tplll"
						display_name("title");
#line 2 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("表");
#line 2 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("\n");
#line 3 "..\\commonEnv\\dropTable.sql.tplll"
						set_line_no(3);
#line 3 "..\\commonEnv\\dropTable.sql.tplll"
						use_pump_command=1;
#line 3 "..\\commonEnv\\dropTable.sql.tplll"
						set_value("tableName",get_string("name"));
#line 3 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("\n");
#line 4 "..\\commonEnv\\dropTable.sql.tplll"
						set_line_no(4);
#line 4 "..\\commonEnv\\dropTable.sql.tplll"
						use_pump_command=1;
#line 4 "..\\commonEnv\\dropTable.sql.tplll"
						for (tmp_value[4]=0;tmp_value[4]<length("Index");tmp_value[4]++)
#line 4 "..\\commonEnv\\dropTable.sql.tplll"
						{
#line 4 "..\\commonEnv\\dropTable.sql.tplll"
							enter_set("Index",tmp_value[4]);
#line 4 "..\\commonEnv\\dropTable.sql.tplll"
							display_string("\n");
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							set_line_no(5);
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							display_string("drop index i_");
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							use_pump_command=1;
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							display_name("tableName");
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							display_string("_");
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							use_pump_command=1;
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							display_name("name");
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							display_string(";");
#line 5 "..\\commonEnv\\dropTable.sql.tplll"
							display_string("\n");
#line 6 "..\\commonEnv\\dropTable.sql.tplll"
							set_line_no(6);
#line 6 "..\\commonEnv\\dropTable.sql.tplll"
							use_pump_command=1;
#line 6 "..\\commonEnv\\dropTable.sql.tplll"
							leave();
#line 6 "..\\commonEnv\\dropTable.sql.tplll"
						}
#line 6 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("\n");
#line 7 "..\\commonEnv\\dropTable.sql.tplll"
						set_line_no(7);
#line 7 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("drop table t_");
#line 7 "..\\commonEnv\\dropTable.sql.tplll"
						use_pump_command=1;
#line 7 "..\\commonEnv\\dropTable.sql.tplll"
						display_name("name");
#line 7 "..\\commonEnv\\dropTable.sql.tplll"
						display_string(";");
#line 7 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("\n");
#line 8 "..\\commonEnv\\dropTable.sql.tplll"
						set_line_no(8);
#line 8 "..\\commonEnv\\dropTable.sql.tplll"
						display_string("\n");
#line 9 "..\\commonEnv\\dropTable.sql.tplll"
						set_line_no(9);
#line 9 "..\\commonEnv\\dropTable.sql.tplll"
						use_pump_command=1;
#line 9 "..\\commonEnv\\dropTable.sql.tplll"
						leave();
#line 9 "..\\commonEnv\\dropTable.sql.tplll"
					}
#line 9 "..\\commonEnv\\dropTable.sql.tplll"
					display_string("\n");
#line 31 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 31 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\n");
#line 32 "..\\commonEnv\\DBAll.sql.tpl"
					set_line_no(32);
#line 32 "..\\commonEnv\\DBAll.sql.tpl"
					display_string("\t\t\t\t\t");
#line 32 "..\\commonEnv\\DBAll.sql.tpl"
					use_pump_command=1;
#line 32 "..\\commonEnv\\DBAll.sql.tpl"
				}
#line 32 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\n");
#line 33 "..\\commonEnv\\DBAll.sql.tpl"
				set_line_no(33);
#line 33 "..\\commonEnv\\DBAll.sql.tpl"
				display_string("\t\t\t\t");
#line 33 "..\\commonEnv\\DBAll.sql.tpl"
				use_pump_command=1;
#line 33 "..\\commonEnv\\DBAll.sql.tpl"
				leave();
#line 33 "..\\commonEnv\\DBAll.sql.tpl"
			}
#line 33 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 34 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(34);
#line 34 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\t\t\t");
#line 34 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 34 "..\\commonEnv\\DBAll.sql.tpl"
			leave();
#line 34 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\n");
#line 35 "..\\commonEnv\\DBAll.sql.tpl"
			set_line_no(35);
#line 35 "..\\commonEnv\\DBAll.sql.tpl"
			display_string("\t\t");
#line 35 "..\\commonEnv\\DBAll.sql.tpl"
			use_pump_command=1;
#line 35 "..\\commonEnv\\DBAll.sql.tpl"
			leave();
#line 35 "..\\commonEnv\\DBAll.sql.tpl"
		}
#line 35 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\n");
#line 36 "..\\commonEnv\\DBAll.sql.tpl"
		set_line_no(36);
#line 36 "..\\commonEnv\\DBAll.sql.tpl"
		display_string("\t");
#line 36 "..\\commonEnv\\DBAll.sql.tpl"
		use_pump_command=1;
#line 36 "..\\commonEnv\\DBAll.sql.tpl"
		leave();
#line 36 "..\\commonEnv\\DBAll.sql.tpl"
	}
#line 36 "..\\commonEnv\\DBAll.sql.tpl"
	display_string("\n");
#line 37 "..\\commonEnv\\DBAll.sql.tpl"
	set_line_no(37);
#line 37 "..\\commonEnv\\DBAll.sql.tpl"
	use_pump_command=1;
#line 37 "..\\commonEnv\\DBAll.sql.tpl"
	leave();
#line 37 "..\\commonEnv\\DBAll.sql.tpl"
	display_string("\n");
}
