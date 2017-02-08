/* generated file, do not change it */

#include "pump.h"

void pump(void)
{
	int tmp_value[30];
#line 1 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_file_name("..\\..\\source\\ftdfield\\FtdData.cpp.tpl");
#line 1 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(1);
#line 1 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("#include \"public.h\"");
#line 1 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
#line 2 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(2);
#line 2 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("#include \"FtdData.h\"");
#line 2 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
#line 3 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(3);
#line 3 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("#include \"FtdPackageDesc.h\"");
#line 3 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
#line 4 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(4);
#line 4 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
#line 5 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(5);
#line 5 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("/*** 应用业务FieldID ***/");
#line 5 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
#line 6 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(6);
#line 6 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	use_pump_command=1;
#line 6 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	enter("FTD");
#line 6 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
#line 7 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(7);
#line 7 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	use_pump_command=1;
#line 7 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("fields");tmp_value[0]++)
#line 7 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	{
#line 7 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		enter_set("fields",tmp_value[0]);
#line 7 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_string("\n");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		set_line_no(8);
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_string("REGISTER_FIELD(");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		use_pump_command=1;
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_name("head");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_string("_FID_");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		use_pump_command=1;
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_name("name");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_string(", C");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		use_pump_command=1;
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_name("head");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		use_pump_command=1;
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_name("name");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_string("Field, \"");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		use_pump_command=1;
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_name("comment");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_string("\");");
#line 8 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		display_string("\n");
#line 9 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		set_line_no(9);
#line 9 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		use_pump_command=1;
#line 9 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
		leave();
#line 9 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	}
#line 9 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
#line 10 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	set_line_no(10);
#line 10 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	use_pump_command=1;
#line 10 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	leave();
#line 10 "..\\..\\source\\ftdfield\\FtdData.cpp.tpl"
	display_string("\n");
}
