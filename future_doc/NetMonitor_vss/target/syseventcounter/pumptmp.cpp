/* generated file, do not change it */

#include "pump.h"

void pump(void)
{
	int tmp_value[30];
#line 1 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_file_name("..\\..\\source\\UFCopy\\FTDCopy.h.tpl");
#line 1 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(1);
#line 1 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	use_pump_command=1;
#line 1 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	enter("FTD");
#line 1 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 2 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(2);
#line 2 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	use_pump_command=1;
#line 2 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	enter("entities");
#line 2 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 3 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(3);
#line 3 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("/////////////////////////////////////////////////////////////////////////");
#line 3 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 4 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(4);
#line 4 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("///@system 执行引擎系统");
#line 4 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 5 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(5);
#line 5 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("///@company 上海期货信息技术有限公司");
#line 5 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 6 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(6);
#line 6 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("///@file FTDCopy.h");
#line 6 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 7 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(7);
#line 7 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("///@brief实现了FTD Entity之间互相复制的程序");
#line 7 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 8 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(8);
#line 8 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("///@history ");
#line 8 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 9 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(9);
#line 9 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("///20051210\t王肇东\t\t创建该文件");
#line 9 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 10 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(10);
#line 10 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("/////////////////////////////////////////////////////////////////////////");
#line 10 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 11 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(11);
#line 11 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 12 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(12);
#line 12 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("#ifndef FTDCopy_H");
#line 12 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 13 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(13);
#line 13 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("#define FTDCopy_H");
#line 13 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 14 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(14);
#line 14 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 15 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(15);
#line 15 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	use_pump_command=1;
#line 1 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
	set_file_name("..\\..\\source\\UFCopy\\CopyEntity.tpl");
#line 1 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
	set_line_no(1);
#line 1 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
	use_pump_command=1;
#line 1 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("self");tmp_value[0]++)
#line 1 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
	{
#line 1 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		enter_set("self",tmp_value[0]);
#line 1 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("\n");
#line 2 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		set_line_no(2);
#line 2 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("#ifndef Copy");
#line 2 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		use_pump_command=1;
#line 2 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_name("name");
#line 2 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("Entity");
#line 2 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("\n");
#line 3 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		set_line_no(3);
#line 3 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("#define Copy");
#line 3 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		use_pump_command=1;
#line 3 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_name("name");
#line 3 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("Entity(target,source)\t\\");
#line 3 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("\n");
#line 4 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		set_line_no(4);
#line 4 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("\t");
#line 4 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		use_pump_command=1;
#line 4 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("self");tmp_value[1]++)
#line 4 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		{
#line 4 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			enter_set("self",tmp_value[1]);
#line 4 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			display_string("\n");
#line 5 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			set_line_no(5);
#line 5 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			display_string("\t\t");
#line 5 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			use_pump_command=1;
#line 5 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			if (!strcmp(get_string("name"),"Ref"))
#line 5 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			{
#line 5 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\n");
#line 6 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				set_line_no(6);
#line 6 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\t\t\tCopy");
#line 6 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				use_pump_command=1;
#line 6 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_name("entity");
#line 6 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("Entity(target,source);\t\\");
#line 6 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\n");
#line 7 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				set_line_no(7);
#line 7 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\t\t");
#line 7 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				use_pump_command=1;
#line 7 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			}
#line 7 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			else
#line 7 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			{
#line 7 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\n");
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				set_line_no(8);
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\t\t\t(target)->");
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				use_pump_command=1;
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_name("name");
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("=(source)->");
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				use_pump_command=1;
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_name("name");
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string(";\t\\");
#line 8 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\n");
#line 9 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				set_line_no(9);
#line 9 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				display_string("\t\t");
#line 9 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
				use_pump_command=1;
#line 9 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			}
#line 9 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			display_string("\n");
#line 10 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			set_line_no(10);
#line 10 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			display_string("\t");
#line 10 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			use_pump_command=1;
#line 10 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
			leave();
#line 10 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		}
#line 10 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("\n");
#line 11 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		set_line_no(11);
#line 11 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("\n");
#line 12 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		set_line_no(12);
#line 12 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("#endif");
#line 12 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		display_string("\n");
#line 13 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		set_line_no(13);
#line 13 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		use_pump_command=1;
#line 13 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
		leave();
#line 13 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
	}
#line 13 "..\\..\\source\\UFCopy\\CopyEntity.tpl"
	display_string("\n");
#line 15 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	use_pump_command=1;
#line 15 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 16 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(16);
#line 16 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 17 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(17);
#line 17 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("#endif");
#line 17 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 18 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(18);
#line 18 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	use_pump_command=1;
#line 18 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	leave();
#line 18 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
#line 19 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	set_line_no(19);
#line 19 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	use_pump_command=1;
#line 19 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	leave();
#line 19 "..\\..\\source\\UFCopy\\FTDCopy.h.tpl"
	display_string("\n");
}
