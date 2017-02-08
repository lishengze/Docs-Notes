/* generated file, do not change it */

#include "pump.h"

void pump(void)
{
	int tmp_value[30];
#line 1 "CMemoryDB.h.tpl"
	set_file_name("CMemoryDB.h.tpl");
#line 1 "CMemoryDB.h.tpl"
	set_line_no(1);
#line 1 "CMemoryDB.h.tpl"
	use_pump_command=1;
#line 1 "CMemoryDB.h.tpl"
	enter("system");
#line 1 "CMemoryDB.h.tpl"
	display_string("\n");
#line 2 "CMemoryDB.h.tpl"
	set_line_no(2);
#line 2 "CMemoryDB.h.tpl"
	display_string("/////////////////////////////////////////////////////////////////////////");
#line 2 "CMemoryDB.h.tpl"
	display_string("\n");
#line 3 "CMemoryDB.h.tpl"
	set_line_no(3);
#line 3 "CMemoryDB.h.tpl"
	display_string("///@system 执行引擎系统");
#line 3 "CMemoryDB.h.tpl"
	display_string("\n");
#line 4 "CMemoryDB.h.tpl"
	set_line_no(4);
#line 4 "CMemoryDB.h.tpl"
	display_string("///@company 上海期货信息技术有限公司");
#line 4 "CMemoryDB.h.tpl"
	display_string("\n");
#line 5 "CMemoryDB.h.tpl"
	set_line_no(5);
#line 5 "CMemoryDB.h.tpl"
	display_string("///@file CMemoryDB.h");
#line 5 "CMemoryDB.h.tpl"
	display_string("\n");
#line 6 "CMemoryDB.h.tpl"
	set_line_no(6);
#line 6 "CMemoryDB.h.tpl"
	display_string("///@brief定义了类CMemoryDB");
#line 6 "CMemoryDB.h.tpl"
	display_string("\n");
#line 7 "CMemoryDB.h.tpl"
	set_line_no(7);
#line 7 "CMemoryDB.h.tpl"
	display_string("///@history ");
#line 7 "CMemoryDB.h.tpl"
	display_string("\n");
#line 8 "CMemoryDB.h.tpl"
	set_line_no(8);
#line 8 "CMemoryDB.h.tpl"
	display_string("///20050824\t王肇东\t\t创建该文件");
#line 8 "CMemoryDB.h.tpl"
	display_string("\n");
#line 9 "CMemoryDB.h.tpl"
	set_line_no(9);
#line 9 "CMemoryDB.h.tpl"
	display_string("/////////////////////////////////////////////////////////////////////////");
#line 9 "CMemoryDB.h.tpl"
	display_string("\n");
#line 10 "CMemoryDB.h.tpl"
	set_line_no(10);
#line 10 "CMemoryDB.h.tpl"
	display_string("\n");
#line 11 "CMemoryDB.h.tpl"
	set_line_no(11);
#line 11 "CMemoryDB.h.tpl"
	display_string("#ifndef CMEMORYDB_H");
#line 11 "CMemoryDB.h.tpl"
	display_string("\n");
#line 12 "CMemoryDB.h.tpl"
	set_line_no(12);
#line 12 "CMemoryDB.h.tpl"
	display_string("#define CMEMORYDB_H");
#line 12 "CMemoryDB.h.tpl"
	display_string("\n");
#line 13 "CMemoryDB.h.tpl"
	set_line_no(13);
#line 13 "CMemoryDB.h.tpl"
	display_string("\n");
#line 14 "CMemoryDB.h.tpl"
	set_line_no(14);
#line 14 "CMemoryDB.h.tpl"
	display_string("#include \"CBaseObject.h\"");
#line 14 "CMemoryDB.h.tpl"
	display_string("\n");
#line 15 "CMemoryDB.h.tpl"
	set_line_no(15);
#line 15 "CMemoryDB.h.tpl"
	display_string("#include \"CConfig.h\"");
#line 15 "CMemoryDB.h.tpl"
	display_string("\n");
#line 16 "CMemoryDB.h.tpl"
	set_line_no(16);
#line 16 "CMemoryDB.h.tpl"
	display_string("#include \"BaseDataStruct.h\"");
#line 16 "CMemoryDB.h.tpl"
	display_string("\n");
#line 17 "CMemoryDB.h.tpl"
	set_line_no(17);
#line 17 "CMemoryDB.h.tpl"
	display_string("#include \"databaseFactories.h\"");
#line 17 "CMemoryDB.h.tpl"
	display_string("\n");
#line 18 "CMemoryDB.h.tpl"
	set_line_no(18);
#line 18 "CMemoryDB.h.tpl"
	display_string("#include \"databaseIterators.h\"");
#line 18 "CMemoryDB.h.tpl"
	display_string("\n");
#line 19 "CMemoryDB.h.tpl"
	set_line_no(19);
#line 19 "CMemoryDB.h.tpl"
	display_string("\n");
#line 20 "CMemoryDB.h.tpl"
	set_line_no(20);
#line 20 "CMemoryDB.h.tpl"
	display_string("struct TableStruct");
#line 20 "CMemoryDB.h.tpl"
	display_string("\n");
#line 21 "CMemoryDB.h.tpl"
	set_line_no(21);
#line 21 "CMemoryDB.h.tpl"
	display_string("{");
#line 21 "CMemoryDB.h.tpl"
	display_string("\n");
#line 22 "CMemoryDB.h.tpl"
	set_line_no(22);
#line 22 "CMemoryDB.h.tpl"
	display_string("\tchar tableName[100];");
#line 22 "CMemoryDB.h.tpl"
	display_string("\n");
#line 23 "CMemoryDB.h.tpl"
	set_line_no(23);
#line 23 "CMemoryDB.h.tpl"
	display_string("\tint  reuseID;");
#line 23 "CMemoryDB.h.tpl"
	display_string("\n");
#line 24 "CMemoryDB.h.tpl"
	set_line_no(24);
#line 24 "CMemoryDB.h.tpl"
	display_string("};");
#line 24 "CMemoryDB.h.tpl"
	display_string("\n");
#line 25 "CMemoryDB.h.tpl"
	set_line_no(25);
#line 25 "CMemoryDB.h.tpl"
	display_string("/////////////////////////////////////////////////////////////////////////");
#line 25 "CMemoryDB.h.tpl"
	display_string("\n");
#line 26 "CMemoryDB.h.tpl"
	set_line_no(26);
#line 26 "CMemoryDB.h.tpl"
	display_string("///CMemoryDB是一个内存数据库类，包含了所有定义的表信息");
#line 26 "CMemoryDB.h.tpl"
	display_string("\n");
#line 27 "CMemoryDB.h.tpl"
	set_line_no(27);
#line 27 "CMemoryDB.h.tpl"
	display_string("///@author\t王肇东");
#line 27 "CMemoryDB.h.tpl"
	display_string("\n");
#line 28 "CMemoryDB.h.tpl"
	set_line_no(28);
#line 28 "CMemoryDB.h.tpl"
	display_string("///@version\t1.0,20050824");
#line 28 "CMemoryDB.h.tpl"
	display_string("\n");
#line 29 "CMemoryDB.h.tpl"
	set_line_no(29);
#line 29 "CMemoryDB.h.tpl"
	display_string("/////////////////////////////////////////////////////////////////////////");
#line 29 "CMemoryDB.h.tpl"
	display_string("\n");
#line 30 "CMemoryDB.h.tpl"
	set_line_no(30);
#line 30 "CMemoryDB.h.tpl"
	display_string("class CMemoryDB : public CBaseObject");
#line 30 "CMemoryDB.h.tpl"
	display_string("\n");
#line 31 "CMemoryDB.h.tpl"
	set_line_no(31);
#line 31 "CMemoryDB.h.tpl"
	display_string("{");
#line 31 "CMemoryDB.h.tpl"
	display_string("\n");
#line 32 "CMemoryDB.h.tpl"
	set_line_no(32);
#line 32 "CMemoryDB.h.tpl"
	display_string("public:");
#line 32 "CMemoryDB.h.tpl"
	display_string("\n");
#line 33 "CMemoryDB.h.tpl"
	set_line_no(33);
#line 33 "CMemoryDB.h.tpl"
	display_string("\t///构造方法，创建内存数据库");
#line 33 "CMemoryDB.h.tpl"
	display_string("\n");
#line 34 "CMemoryDB.h.tpl"
	set_line_no(34);
#line 34 "CMemoryDB.h.tpl"
	display_string("\tCMemoryDB(void);");
#line 34 "CMemoryDB.h.tpl"
	display_string("\n");
#line 35 "CMemoryDB.h.tpl"
	set_line_no(35);
#line 35 "CMemoryDB.h.tpl"
	display_string("\t");
#line 35 "CMemoryDB.h.tpl"
	display_string("\n");
#line 36 "CMemoryDB.h.tpl"
	set_line_no(36);
#line 36 "CMemoryDB.h.tpl"
	display_string("\t///析构方法，将负责释放所占用的空间");
#line 36 "CMemoryDB.h.tpl"
	display_string("\n");
#line 37 "CMemoryDB.h.tpl"
	set_line_no(37);
#line 37 "CMemoryDB.h.tpl"
	display_string("\tvirtual ~CMemoryDB(void);");
#line 37 "CMemoryDB.h.tpl"
	display_string("\n");
#line 38 "CMemoryDB.h.tpl"
	set_line_no(38);
#line 38 "CMemoryDB.h.tpl"
	display_string("\t");
#line 38 "CMemoryDB.h.tpl"
	display_string("\n");
#line 39 "CMemoryDB.h.tpl"
	set_line_no(39);
#line 39 "CMemoryDB.h.tpl"
	display_string("\tvirtual int isA(char *objectType);");
#line 39 "CMemoryDB.h.tpl"
	display_string("\n");
#line 40 "CMemoryDB.h.tpl"
	set_line_no(40);
#line 40 "CMemoryDB.h.tpl"
	display_string("\tvirtual char *getType(void);");
#line 40 "CMemoryDB.h.tpl"
	display_string("\n");
#line 41 "CMemoryDB.h.tpl"
	set_line_no(41);
#line 41 "CMemoryDB.h.tpl"
	display_string("\tvirtual void output(CLogger *pLogger,int indent=0);");
#line 41 "CMemoryDB.h.tpl"
	display_string("\n");
#line 42 "CMemoryDB.h.tpl"
	set_line_no(42);
#line 42 "CMemoryDB.h.tpl"
	display_string("\n");
#line 43 "CMemoryDB.h.tpl"
	set_line_no(43);
#line 43 "CMemoryDB.h.tpl"
	display_string("\t///进行初始化工作");
#line 43 "CMemoryDB.h.tpl"
	display_string("\n");
#line 44 "CMemoryDB.h.tpl"
	set_line_no(44);
#line 44 "CMemoryDB.h.tpl"
	display_string("\t///@param\tpConfig\t初始化时使用的配置信息");
#line 44 "CMemoryDB.h.tpl"
	display_string("\n");
#line 45 "CMemoryDB.h.tpl"
	set_line_no(45);
#line 45 "CMemoryDB.h.tpl"
	display_string("\t///@return\t1表示成功，0表示失败");
#line 45 "CMemoryDB.h.tpl"
	display_string("\n");
#line 46 "CMemoryDB.h.tpl"
	set_line_no(46);
#line 46 "CMemoryDB.h.tpl"
	display_string("\tvirtual int init(CConfig *pConfig,IMemoryAllocator *pAllocator=NULL,bool reuse=false);");
#line 46 "CMemoryDB.h.tpl"
	display_string("\n");
#line 47 "CMemoryDB.h.tpl"
	set_line_no(47);
#line 47 "CMemoryDB.h.tpl"
	display_string("\t");
#line 47 "CMemoryDB.h.tpl"
	display_string("\n");
#line 48 "CMemoryDB.h.tpl"
	set_line_no(48);
#line 48 "CMemoryDB.h.tpl"
	display_string("\t///进行数据载入工作");
#line 48 "CMemoryDB.h.tpl"
	display_string("\n");
#line 49 "CMemoryDB.h.tpl"
	set_line_no(49);
#line 49 "CMemoryDB.h.tpl"
	display_string("\t///@param\tpConfig\t载入数据时使用的配置信息");
#line 49 "CMemoryDB.h.tpl"
	display_string("\n");
#line 50 "CMemoryDB.h.tpl"
	set_line_no(50);
#line 50 "CMemoryDB.h.tpl"
	display_string("\t///@return\t1表示成功，0表示失败");
#line 50 "CMemoryDB.h.tpl"
	display_string("\n");
#line 51 "CMemoryDB.h.tpl"
	set_line_no(51);
#line 51 "CMemoryDB.h.tpl"
	display_string("\tvirtual int load(CConfig *pConfig);");
#line 51 "CMemoryDB.h.tpl"
	display_string("\n");
#line 52 "CMemoryDB.h.tpl"
	set_line_no(52);
#line 52 "CMemoryDB.h.tpl"
	display_string("\n");
#line 53 "CMemoryDB.h.tpl"
	set_line_no(53);
#line 53 "CMemoryDB.h.tpl"
	display_string("\t///进行数据存储工作");
#line 53 "CMemoryDB.h.tpl"
	display_string("\n");
#line 54 "CMemoryDB.h.tpl"
	set_line_no(54);
#line 54 "CMemoryDB.h.tpl"
	display_string("\t///@param\tpConfig\t保存数据时使用的配置信息");
#line 54 "CMemoryDB.h.tpl"
	display_string("\n");
#line 55 "CMemoryDB.h.tpl"
	set_line_no(55);
#line 55 "CMemoryDB.h.tpl"
	display_string("\t///@return\t1表示成功，0表示失败");
#line 55 "CMemoryDB.h.tpl"
	display_string("\n");
#line 56 "CMemoryDB.h.tpl"
	set_line_no(56);
#line 56 "CMemoryDB.h.tpl"
	display_string("\tvirtual int save(CConfig *pConfig);");
#line 56 "CMemoryDB.h.tpl"
	display_string("\n");
#line 57 "CMemoryDB.h.tpl"
	set_line_no(57);
#line 57 "CMemoryDB.h.tpl"
	display_string("\t");
#line 57 "CMemoryDB.h.tpl"
	display_string("\n");
#line 58 "CMemoryDB.h.tpl"
	set_line_no(58);
#line 58 "CMemoryDB.h.tpl"
	display_string("\t///清空所有的数据");
#line 58 "CMemoryDB.h.tpl"
	display_string("\n");
#line 59 "CMemoryDB.h.tpl"
	set_line_no(59);
#line 59 "CMemoryDB.h.tpl"
	display_string("\t///@return\t1表示成功，0表示失败");
#line 59 "CMemoryDB.h.tpl"
	display_string("\n");
#line 60 "CMemoryDB.h.tpl"
	set_line_no(60);
#line 60 "CMemoryDB.h.tpl"
	display_string("\tvirtual void clear(void);");
#line 60 "CMemoryDB.h.tpl"
	display_string("\n");
#line 61 "CMemoryDB.h.tpl"
	set_line_no(61);
#line 61 "CMemoryDB.h.tpl"
	display_string("\t");
#line 61 "CMemoryDB.h.tpl"
	display_string("\n");
#line 62 "CMemoryDB.h.tpl"
	set_line_no(62);
#line 62 "CMemoryDB.h.tpl"
	display_string("\t///完成所有外键的连接");
#line 62 "CMemoryDB.h.tpl"
	display_string("\n");
#line 63 "CMemoryDB.h.tpl"
	set_line_no(63);
#line 63 "CMemoryDB.h.tpl"
	display_string("\tvirtual void linkAll(void);");
#line 63 "CMemoryDB.h.tpl"
	display_string("\n");
#line 64 "CMemoryDB.h.tpl"
	set_line_no(64);
#line 64 "CMemoryDB.h.tpl"
	display_string("\t");
#line 64 "CMemoryDB.h.tpl"
	display_string("\n");
#line 65 "CMemoryDB.h.tpl"
	set_line_no(65);
#line 65 "CMemoryDB.h.tpl"
	display_string("\t");
#line 65 "CMemoryDB.h.tpl"
	display_string("\n");
#line 66 "CMemoryDB.h.tpl"
	set_line_no(66);
#line 66 "CMemoryDB.h.tpl"
	display_string("\t");
#line 66 "CMemoryDB.h.tpl"
	display_string("\n");
#line 67 "CMemoryDB.h.tpl"
	set_line_no(67);
#line 67 "CMemoryDB.h.tpl"
	display_string("\t");
#line 67 "CMemoryDB.h.tpl"
	use_pump_command=1;
#line 67 "CMemoryDB.h.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("tables");tmp_value[0]++)
#line 67 "CMemoryDB.h.tpl"
	{
#line 67 "CMemoryDB.h.tpl"
		enter_set("tables",tmp_value[0]);
#line 67 "CMemoryDB.h.tpl"
		display_string("\n");
#line 68 "CMemoryDB.h.tpl"
		set_line_no(68);
#line 68 "CMemoryDB.h.tpl"
		display_string("\t");
#line 68 "CMemoryDB.h.tpl"
		use_pump_command=1;
#line 68 "CMemoryDB.h.tpl"
		if (!strcmp(get_string("hasTable"),"yes"))
#line 68 "CMemoryDB.h.tpl"
		{
#line 68 "CMemoryDB.h.tpl"
			display_string("\n");
#line 69 "CMemoryDB.h.tpl"
			set_line_no(69);
#line 69 "CMemoryDB.h.tpl"
			display_string("\t///");
#line 69 "CMemoryDB.h.tpl"
			use_pump_command=1;
#line 69 "CMemoryDB.h.tpl"
			display_name("usage");
#line 69 "CMemoryDB.h.tpl"
			display_string("表");
#line 69 "CMemoryDB.h.tpl"
			display_string("\n");
#line 70 "CMemoryDB.h.tpl"
			set_line_no(70);
#line 70 "CMemoryDB.h.tpl"
			display_string("\tC");
#line 70 "CMemoryDB.h.tpl"
			use_pump_command=1;
#line 70 "CMemoryDB.h.tpl"
			display_name("name");
#line 70 "CMemoryDB.h.tpl"
			display_string("Factory *m_");
#line 70 "CMemoryDB.h.tpl"
			use_pump_command=1;
#line 70 "CMemoryDB.h.tpl"
			display_name("name");
#line 70 "CMemoryDB.h.tpl"
			display_string("Factory;");
#line 70 "CMemoryDB.h.tpl"
			display_string("\n");
#line 71 "CMemoryDB.h.tpl"
			set_line_no(71);
#line 71 "CMemoryDB.h.tpl"
			display_string("\t");
#line 71 "CMemoryDB.h.tpl"
			display_string("\n");
#line 72 "CMemoryDB.h.tpl"
			set_line_no(72);
#line 72 "CMemoryDB.h.tpl"
			display_string("\t");
#line 72 "CMemoryDB.h.tpl"
			use_pump_command=1;
#line 72 "CMemoryDB.h.tpl"
		}
#line 72 "CMemoryDB.h.tpl"
		display_string("\n");
#line 73 "CMemoryDB.h.tpl"
		set_line_no(73);
#line 73 "CMemoryDB.h.tpl"
		display_string("\t");
#line 73 "CMemoryDB.h.tpl"
		use_pump_command=1;
#line 73 "CMemoryDB.h.tpl"
		leave();
#line 73 "CMemoryDB.h.tpl"
	}
#line 73 "CMemoryDB.h.tpl"
	display_string("\n");
#line 74 "CMemoryDB.h.tpl"
	set_line_no(74);
#line 74 "CMemoryDB.h.tpl"
	display_string("private:");
#line 74 "CMemoryDB.h.tpl"
	display_string("\n");
#line 75 "CMemoryDB.h.tpl"
	set_line_no(75);
#line 75 "CMemoryDB.h.tpl"
	display_string("\tCFixMem *pMem;\t\t///用来存放表的信息");
#line 75 "CMemoryDB.h.tpl"
	display_string("\n");
#line 76 "CMemoryDB.h.tpl"
	set_line_no(76);
#line 76 "CMemoryDB.h.tpl"
	display_string("};");
#line 76 "CMemoryDB.h.tpl"
	display_string("\n");
#line 77 "CMemoryDB.h.tpl"
	set_line_no(77);
#line 77 "CMemoryDB.h.tpl"
	display_string("\n");
#line 78 "CMemoryDB.h.tpl"
	set_line_no(78);
#line 78 "CMemoryDB.h.tpl"
	display_string("#endif");
#line 78 "CMemoryDB.h.tpl"
	display_string("\n");
#line 79 "CMemoryDB.h.tpl"
	set_line_no(79);
#line 79 "CMemoryDB.h.tpl"
	use_pump_command=1;
#line 79 "CMemoryDB.h.tpl"
	leave();
#line 79 "CMemoryDB.h.tpl"
	display_string("\n");
}
