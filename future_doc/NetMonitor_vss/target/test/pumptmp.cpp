/* generated file, do not change it */

#include "pump.h"

void pump(void)
{
	int tmp_value[30];
#line 1 "c:\\amake\\windows\\makefile.win.tpl"
	set_file_name("c:\\amake\\windows\\makefile.win.tpl");
#line 1 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(1);
#line 1 "c:\\amake\\windows\\makefile.win.tpl"
	use_pump_command=1;
#line 1 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 2 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(2);
#line 2 "c:\\amake\\windows\\makefile.win.tpl"
	display_string(".SUFFIXES:  .c .cpp .o .obj .a .lib");
#line 2 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 3 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(3);
#line 3 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 4 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(4);
#line 4 "c:\\amake\\windows\\makefile.win.tpl"
	use_pump_command=1;
#line 4 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 5 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(5);
#line 5 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("CPP=cl -nologo ");
#line 5 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 6 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(6);
#line 6 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("LINK=link -nologo");
#line 6 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 7 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(7);
#line 7 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("PREP=cl -nologo -EP");
#line 7 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 8 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(8);
#line 8 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("LUA=lua");
#line 8 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 9 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(9);
#line 9 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("PUMP=pump");
#line 9 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 10 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(10);
#line 10 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("COPY=copy /y");
#line 10 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 11 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(11);
#line 11 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("DEL=del");
#line 11 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 12 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(12);
#line 12 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("MAKE=nmake");
#line 12 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 13 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(13);
#line 13 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("ECHO=echo");
#line 13 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 14 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(14);
#line 14 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 15 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(15);
#line 15 "c:\\amake\\windows\\makefile.win.tpl"
	display_string(".cpp.obj:");
#line 15 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 16 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(16);
#line 16 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\t$(CPP) $(CPPFLAGS) $(INCLUDEDIR) -c $< >> output");
#line 16 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 17 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(17);
#line 17 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\tmove $(@F) $(@D)");
#line 17 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 18 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(18);
#line 18 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 19 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(19);
#line 19 "c:\\amake\\windows\\makefile.win.tpl"
	use_pump_command=1;
#line 1 "c:\\amake\\windows\\windowsparam.tpl"
	set_file_name("c:\\amake\\windows\\windowsparam.tpl");
#line 1 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(1);
#line 1 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 1 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 2 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(2);
#line 2 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 2 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_platform","WINDOWS");
#line 2 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 3 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(3);
#line 3 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 3 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_compiler","MSVC");
#line 3 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 4 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(4);
#line 4 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 4 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_exe_suffix",".exe");
#line 4 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 5 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(5);
#line 5 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 5 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_lib_suffix",".lib");
#line 5 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 6 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(6);
#line 6 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 6 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_dll_suffix",".dll");
#line 6 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 7 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(7);
#line 7 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 7 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_obj_suffix",".obj");
#line 7 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 8 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(8);
#line 8 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 8 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_dir_convertfrom","/");
#line 8 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 9 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(9);
#line 9 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 9 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_dir_convertto","\\");
#line 9 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 10 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(10);
#line 10 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 10 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_debug_multithread_cppflags","-nologo -EHsc -MTd -Od  -Zi -FD");
#line 10 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 11 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(11);
#line 11 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 11 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_debug_singlethread_cppflags","-nologo -EHsc -MLd -Od  -Zi -FD");
#line 11 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 12 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(12);
#line 12 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 12 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_release_multithread_cppflags","-nologo -EHsc -MT -O2 -GF -FD");
#line 12 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 13 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(13);
#line 13 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 13 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_release_singlethread_cppflags","-nologo -EHsc -ML -O2 -GF -FD");
#line 13 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 14 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(14);
#line 14 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 14 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_output_ldindicate","-out:");
#line 14 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 15 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(15);
#line 15 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 15 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_implib_ldindicate","-implib:");
#line 15 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 16 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(16);
#line 16 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 16 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_libs","kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib");
#line 16 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 17 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(17);
#line 17 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 17 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_basic_exe_ldflags","/FIXED:NO");
#line 17 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 18 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(18);
#line 18 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 18 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_basic_lib_ldflags"," ");
#line 18 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 19 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(19);
#line 19 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 19 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_basic_dll_ldflags","/dll");
#line 19 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 20 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(20);
#line 20 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 20 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_debug_ldflags","/DEBUG");
#line 20 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 21 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(21);
#line 21 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 21 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_map_ldflags","/MAP /MAPINFO:EXPORTS /MAPINFO:FIXUPS /MAPINFO:LINES");
#line 21 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 22 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(22);
#line 22 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 22 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_profile_ldflags","/PROFILE");
#line 22 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 23 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(23);
#line 23 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 23 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_exit_make","exit /b 1");
#line 23 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 24 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(24);
#line 24 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 24 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning0_cppflags","-W0");
#line 24 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 25 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(25);
#line 25 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 25 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning1_cppflags","-W1");
#line 25 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 26 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(26);
#line 26 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 26 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning2_cppflags","-W3");
#line 26 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 27 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(27);
#line 27 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 27 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning3_cppflags","-W4");
#line 27 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 28 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(28);
#line 28 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 28 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning0_ldflags","/WARN:0");
#line 28 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 29 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(29);
#line 29 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 29 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning1_ldflags","/WARN:1");
#line 29 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 30 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(30);
#line 30 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 30 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning2_ldflags","/WARN:2");
#line 30 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 31 "c:\\amake\\windows\\windowsparam.tpl"
	set_line_no(31);
#line 31 "c:\\amake\\windows\\windowsparam.tpl"
	use_pump_command=1;
#line 31 "c:\\amake\\windows\\windowsparam.tpl"
	set_value("am_warning3_ldflags","/WARN:3");
#line 31 "c:\\amake\\windows\\windowsparam.tpl"
	display_string("\n");
#line 19 "c:\\amake\\windows\\makefile.win.tpl"
	use_pump_command=1;
#line 19 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
#line 20 "c:\\amake\\windows\\makefile.win.tpl"
	set_line_no(20);
#line 20 "c:\\amake\\windows\\makefile.win.tpl"
	use_pump_command=1;
#line 1 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_file_name("c:\\amake\\makefile.tpldowsparam.tpl");
#line 1 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(1);
#line 1 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 1 "c:\\amake\\makefile.tpldowsparam.tpl"
	enter("system");
#line 1 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 2 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(2);
#line 2 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 2 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 3 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(3);
#line 3 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 3 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 3 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 3 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 3 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 4 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(4);
#line 4 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 4 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 4 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 4 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 5 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(5);
#line 5 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 5 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 5 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter("system");
#line 5 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 6 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(6);
#line 6 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t\t");
#line 6 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 6 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_findpackage","no");
#line 6 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 7 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(7);
#line 7 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t\t");
#line 7 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 7 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("project");tmp_value[1]++)
#line 7 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 7 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("project",tmp_value[1]);
#line 7 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 8 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(8);
#line 8 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t\t");
#line 8 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 8 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strcmp(get_string("name"),get_string("am_packagename")))
#line 8 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 8 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 9 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(9);
#line 9 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t\t");
#line 9 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 9 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_findpackage"),"yes"))
#line 9 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 9 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 10 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(10);
#line 10 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t\t");
#line 10 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 10 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("duplicate package definition for '%s' in project file\n",get_string("name"));
#line 10 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 10 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 10 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 11 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(11);
#line 11 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 11 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 11 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 11 "c:\\amake\\makefile.tpldowsparam.tpl"
				else
#line 11 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 11 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 12 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(12);
#line 12 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t\t");
#line 12 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 12 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_findpackage","yes");
#line 12 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 13 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(13);
#line 13 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 13 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 13 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 13 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 14 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(14);
#line 14 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 14 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 14 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 14 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 15 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(15);
#line 15 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 15 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 15 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 15 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 15 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 16 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(16);
#line 16 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t\t");
#line 16 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 16 "c:\\amake\\makefile.tpldowsparam.tpl"
		if (!strcmp(get_string("am_findpackage"),"no"))
#line 16 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 16 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 17 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(17);
#line 17 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t\t");
#line 17 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 17 "c:\\amake\\makefile.tpldowsparam.tpl"
			printf("can not find package definition for '%s' in project file\n",get_string("am_packagename"));
#line 17 "c:\\amake\\makefile.tpldowsparam.tpl"
			printf("\n");
#line 17 "c:\\amake\\makefile.tpldowsparam.tpl"
			error();
#line 17 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 18 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(18);
#line 18 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 18 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 18 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 18 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 19 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(19);
#line 19 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 19 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 19 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 19 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 20 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(20);
#line 20 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 20 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 20 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 20 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 21 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(21);
#line 21 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 21 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("project");tmp_value[0]++)
#line 21 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 21 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("project",tmp_value[0]);
#line 21 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 22 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(22);
#line 22 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 22 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 22 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 22 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 23 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(23);
#line 23 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 23 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 23 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter("system");
#line 23 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 24 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(24);
#line 24 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t\t");
#line 24 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 24 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_findpackage","no");
#line 24 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 25 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(25);
#line 25 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t\t");
#line 25 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 25 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("package");tmp_value[1]++)
#line 25 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 25 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("package",tmp_value[1]);
#line 25 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 26 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(26);
#line 26 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t\t");
#line 26 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 26 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strcmp(get_string("name"),get_string("am_packagename")))
#line 26 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 26 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 27 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(27);
#line 27 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t\t");
#line 27 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 27 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_findpackage"),"yes"))
#line 27 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 27 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 28 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(28);
#line 28 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t\t");
#line 28 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 28 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("duplicate package definition for '%s' in package file\n",get_string("name"));
#line 28 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 28 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 28 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 29 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(29);
#line 29 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 29 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 29 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 29 "c:\\amake\\makefile.tpldowsparam.tpl"
				else
#line 29 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 29 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 30 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(30);
#line 30 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t\t");
#line 30 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 30 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_findpackage","yes");
#line 30 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 31 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(31);
#line 31 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 31 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 31 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 31 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 32 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(32);
#line 32 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 32 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 32 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 32 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 33 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(33);
#line 33 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 33 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 33 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 33 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 33 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 34 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(34);
#line 34 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t\t");
#line 34 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 34 "c:\\amake\\makefile.tpldowsparam.tpl"
		if (!strcmp(get_string("am_findpackage"),"no"))
#line 34 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 34 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 35 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(35);
#line 35 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t\t");
#line 35 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 35 "c:\\amake\\makefile.tpldowsparam.tpl"
			printf("can not find package definition for '%s' in package file\n",get_string("am_packagename"));
#line 35 "c:\\amake\\makefile.tpldowsparam.tpl"
			printf("\n");
#line 35 "c:\\amake\\makefile.tpldowsparam.tpl"
			error();
#line 35 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 36 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(36);
#line 36 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 36 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 36 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 36 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 37 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(37);
#line 37 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 37 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 37 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 37 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 38 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(38);
#line 38 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 38 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 38 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 38 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 39 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(39);
#line 39 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 39 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 40 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(40);
#line 40 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 40 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 40 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 40 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 40 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 41 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(41);
#line 41 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 41 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 41 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 41 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 42 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(42);
#line 42 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 42 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 42 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("depend");tmp_value[1]++)
#line 42 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 42 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("depend",tmp_value[1]);
#line 42 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 43 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(43);
#line 43 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 43 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 43 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("am_dependname",get_string("name"));
#line 43 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 44 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(44);
#line 44 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 44 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 44 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("am_dependversion",get_string("version"));
#line 44 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 45 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(45);
#line 45 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 45 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 45 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("am_found","no");
#line 45 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 46 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(46);
#line 46 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 46 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 46 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter("system");
#line 46 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 47 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(47);
#line 47 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t\t");
#line 47 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 47 "c:\\amake\\makefile.tpldowsparam.tpl"
			for (tmp_value[2]=0;tmp_value[2]<length("package");tmp_value[2]++)
#line 47 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 47 "c:\\amake\\makefile.tpldowsparam.tpl"
				enter_set("package",tmp_value[2]);
#line 47 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 48 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(48);
#line 48 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t\t");
#line 48 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 48 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("name"),get_string("am_dependname"))&&(atoi(get_string("version"))>=atoi(get_string("am_dependversion"))))
#line 48 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 48 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 49 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(49);
#line 49 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t\t");
#line 49 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 49 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_found","yes");
#line 49 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 50 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(50);
#line 50 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 50 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 50 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 50 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 51 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(51);
#line 51 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 51 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 51 "c:\\amake\\makefile.tpldowsparam.tpl"
				leave();
#line 51 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 51 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 52 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(52);
#line 52 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t\t");
#line 52 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 52 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strcmp(get_string("am_found"),"no"))
#line 52 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 52 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 53 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(53);
#line 53 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t\t");
#line 53 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 53 "c:\\amake\\makefile.tpldowsparam.tpl"
				printf("can not find package '%s.%s' which is required for '%s'\n",get_string("am_dependname"),get_string("am_dependversion"),get_string("am_packagename"));
#line 53 "c:\\amake\\makefile.tpldowsparam.tpl"
				printf("\n");
#line 53 "c:\\amake\\makefile.tpldowsparam.tpl"
				error();
#line 53 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 54 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(54);
#line 54 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 54 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 54 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 54 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 55 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(55);
#line 55 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 55 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 55 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 55 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 56 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(56);
#line 56 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 56 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 56 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 56 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 56 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 57 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(57);
#line 57 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 57 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 57 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 57 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 58 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(58);
#line 58 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 58 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 59 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(59);
#line 59 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 59 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 59 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 59 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 59 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 60 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(60);
#line 60 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 60 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 60 "c:\\amake\\makefile.tpldowsparam.tpl"
		if (strcmp(get_string("type"),"cpp"))
#line 60 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 60 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 61 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(61);
#line 61 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 61 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 61 "c:\\amake\\makefile.tpldowsparam.tpl"
			printf("package type '%s' in pakcage '%s' not supported\n",get_string("type"),get_string("name"));
#line 61 "c:\\amake\\makefile.tpldowsparam.tpl"
			printf("\n");
#line 61 "c:\\amake\\makefile.tpldowsparam.tpl"
			error();
#line 61 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 62 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(62);
#line 62 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 62 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 62 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 62 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 63 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(63);
#line 63 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 63 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 63 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 63 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 64 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(64);
#line 64 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 64 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 65 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(65);
#line 65 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 65 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 65 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 65 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 65 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 66 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(66);
#line 66 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 66 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 66 "c:\\amake\\makefile.tpldowsparam.tpl"
		if (strcmp(get_string("platform"),"all"))
#line 66 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 66 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 67 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(67);
#line 67 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 67 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 67 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strstr(get_string("platform"),get_string("am_platform")))
#line 67 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 67 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 68 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(68);
#line 68 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 68 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 68 "c:\\amake\\makefile.tpldowsparam.tpl"
				printf("package '%s' can not support %s platform\n",get_string("name"),get_string("am_platform"));
#line 68 "c:\\amake\\makefile.tpldowsparam.tpl"
				printf("\n");
#line 68 "c:\\amake\\makefile.tpldowsparam.tpl"
				error();
#line 68 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 69 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(69);
#line 69 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 69 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 69 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 69 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 70 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(70);
#line 70 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 70 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 70 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 70 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 71 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(71);
#line 71 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 71 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 71 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 71 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 72 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(72);
#line 72 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 72 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 73 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(73);
#line 73 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 73 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("project");tmp_value[0]++)
#line 73 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 73 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("project",tmp_value[0]);
#line 73 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 74 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(74);
#line 74 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 74 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 74 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 74 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 75 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(75);
#line 75 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 75 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 75 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("self");tmp_value[1]++)
#line 75 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 75 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("self",tmp_value[1]);
#line 75 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 76 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(76);
#line 76 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 76 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 76 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("am_parametername",get_string("name"));
#line 76 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 77 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(77);
#line 77 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 77 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 77 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter("system");
#line 77 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 78 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(78);
#line 78 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 78 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 78 "c:\\amake\\makefile.tpldowsparam.tpl"
			for (tmp_value[2]=0;tmp_value[2]<length("package");tmp_value[2]++)
#line 78 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 78 "c:\\amake\\makefile.tpldowsparam.tpl"
				enter_set("package",tmp_value[2]);
#line 78 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 79 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(79);
#line 79 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 79 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 79 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_packagename"),get_string("name")))
#line 79 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 79 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 80 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(80);
#line 80 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 80 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 80 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_found","no");
#line 80 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 81 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(81);
#line 81 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 81 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 81 "c:\\amake\\makefile.tpldowsparam.tpl"
					for (tmp_value[3]=0;tmp_value[3]<length("parameter");tmp_value[3]++)
#line 81 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 81 "c:\\amake\\makefile.tpldowsparam.tpl"
						enter_set("parameter",tmp_value[3]);
#line 81 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 82 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(82);
#line 82 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 82 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 82 "c:\\amake\\makefile.tpldowsparam.tpl"
						if (!strcmp(get_string("am_parametername"),get_string("name")))
#line 82 "c:\\amake\\makefile.tpldowsparam.tpl"
						{
#line 82 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 83 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(83);
#line 83 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t");
#line 83 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 83 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_value("am_found","yes");
#line 83 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 84 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(84);
#line 84 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t");
#line 84 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 84 "c:\\amake\\makefile.tpldowsparam.tpl"
						}
#line 84 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 85 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(85);
#line 85 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 85 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 85 "c:\\amake\\makefile.tpldowsparam.tpl"
						leave();
#line 85 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 85 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 86 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(86);
#line 86 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 86 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 86 "c:\\amake\\makefile.tpldowsparam.tpl"
					if (!strcmp(get_string("am_found"),"no"))
#line 86 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 86 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 87 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(87);
#line 87 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 87 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 87 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("unknown parameter '%s' in package '%s'\n",get_string("am_parametername"),get_string("am_packagename"));
#line 87 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("\n");
#line 87 "c:\\amake\\makefile.tpldowsparam.tpl"
						error();
#line 87 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 88 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(88);
#line 88 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 88 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 88 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 88 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 89 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(89);
#line 89 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 89 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 89 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 89 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 90 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(90);
#line 90 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 90 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 90 "c:\\amake\\makefile.tpldowsparam.tpl"
				leave();
#line 90 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 90 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 91 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(91);
#line 91 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 91 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 91 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 91 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 92 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(92);
#line 92 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 92 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 92 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 92 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 92 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 93 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(93);
#line 93 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 93 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 93 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 93 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 94 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(94);
#line 94 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 94 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 94 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 94 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 94 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 95 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(95);
#line 95 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 95 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 95 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 95 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 96 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(96);
#line 96 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 96 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 96 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("parameter");tmp_value[1]++)
#line 96 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 96 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("parameter",tmp_value[1]);
#line 96 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 97 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(97);
#line 97 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 97 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 97 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("am_parametername",get_string("name"));
#line 97 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 98 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(98);
#line 98 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 98 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 98 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter("system");
#line 98 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 99 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(99);
#line 99 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 99 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 99 "c:\\amake\\makefile.tpldowsparam.tpl"
			for (tmp_value[2]=0;tmp_value[2]<length("project");tmp_value[2]++)
#line 99 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 99 "c:\\amake\\makefile.tpldowsparam.tpl"
				enter_set("project",tmp_value[2]);
#line 99 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 100 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(100);
#line 100 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 100 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 100 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_packagename"),get_string("name")))
#line 100 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 100 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 101 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(101);
#line 101 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 101 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 101 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_found","no");
#line 101 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 102 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(102);
#line 102 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 102 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 102 "c:\\amake\\makefile.tpldowsparam.tpl"
					for (tmp_value[3]=0;tmp_value[3]<length("self");tmp_value[3]++)
#line 102 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 102 "c:\\amake\\makefile.tpldowsparam.tpl"
						enter_set("self",tmp_value[3]);
#line 102 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 103 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(103);
#line 103 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 103 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 103 "c:\\amake\\makefile.tpldowsparam.tpl"
						if (!strcmp(get_string("am_parametername"),get_string("name")))
#line 103 "c:\\amake\\makefile.tpldowsparam.tpl"
						{
#line 103 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 104 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(104);
#line 104 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t");
#line 104 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 104 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_value("am_found","yes");
#line 104 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 105 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(105);
#line 105 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t");
#line 105 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 105 "c:\\amake\\makefile.tpldowsparam.tpl"
						}
#line 105 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 106 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(106);
#line 106 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 106 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 106 "c:\\amake\\makefile.tpldowsparam.tpl"
						leave();
#line 106 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 106 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 107 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(107);
#line 107 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 107 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 107 "c:\\amake\\makefile.tpldowsparam.tpl"
					if (!strcmp(get_string("am_found"),"no"))
#line 107 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 107 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 108 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(108);
#line 108 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 108 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 108 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("parameter '%s' in package '%s' not defined\n",get_string("am_parametername"),get_string("am_packagename"));
#line 108 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("\n");
#line 108 "c:\\amake\\makefile.tpldowsparam.tpl"
						error();
#line 108 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 109 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(109);
#line 109 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 109 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 109 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 109 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 110 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(110);
#line 110 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 110 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 110 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 110 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 111 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(111);
#line 111 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 111 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 111 "c:\\amake\\makefile.tpldowsparam.tpl"
				leave();
#line 111 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 111 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 112 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(112);
#line 112 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 112 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 112 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 112 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 113 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(113);
#line 113 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 113 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 113 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 113 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 113 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 114 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(114);
#line 114 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 114 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 114 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 114 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 115 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(115);
#line 115 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 115 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 115 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 115 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 115 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 116 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(116);
#line 116 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 116 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 116 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 116 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 117 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(117);
#line 117 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 117 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 117 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("command");tmp_value[1]++)
#line 117 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 117 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("command",tmp_value[1]);
#line 117 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 118 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(118);
#line 118 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 118 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 118 "c:\\amake\\makefile.tpldowsparam.tpl"
			for (tmp_value[2]=0;tmp_value[2]<length("self");tmp_value[2]++)
#line 118 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 118 "c:\\amake\\makefile.tpldowsparam.tpl"
				enter_set("self",tmp_value[2]);
#line 118 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 119 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(119);
#line 119 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 119 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 119 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("type"),"parameter"))
#line 119 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 119 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 120 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(120);
#line 120 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 120 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 120 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_parametername",get_string("value"));
#line 120 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 121 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(121);
#line 121 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 121 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 121 "c:\\amake\\makefile.tpldowsparam.tpl"
					enter("system");
#line 121 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 122 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(122);
#line 122 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t\t");
#line 122 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 122 "c:\\amake\\makefile.tpldowsparam.tpl"
					for (tmp_value[3]=0;tmp_value[3]<length("package");tmp_value[3]++)
#line 122 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 122 "c:\\amake\\makefile.tpldowsparam.tpl"
						enter_set("package",tmp_value[3]);
#line 122 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 123 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(123);
#line 123 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t\t");
#line 123 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 123 "c:\\amake\\makefile.tpldowsparam.tpl"
						if (!strcmp(get_string("am_packagename"),get_string("name")))
#line 123 "c:\\amake\\makefile.tpldowsparam.tpl"
						{
#line 123 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 124 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(124);
#line 124 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t\t");
#line 124 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 124 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_value("am_found","no");
#line 124 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 125 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(125);
#line 125 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t\t");
#line 125 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 125 "c:\\amake\\makefile.tpldowsparam.tpl"
							for (tmp_value[4]=0;tmp_value[4]<length("parameter");tmp_value[4]++)
#line 125 "c:\\amake\\makefile.tpldowsparam.tpl"
							{
#line 125 "c:\\amake\\makefile.tpldowsparam.tpl"
								enter_set("parameter",tmp_value[4]);
#line 125 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\n");
#line 126 "c:\\amake\\makefile.tpldowsparam.tpl"
								set_line_no(126);
#line 126 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\t\t\t\t\t\t\t\t");
#line 126 "c:\\amake\\makefile.tpldowsparam.tpl"
								use_pump_command=1;
#line 126 "c:\\amake\\makefile.tpldowsparam.tpl"
								if (!strcmp(get_string("name"),get_string("am_parametername")))
#line 126 "c:\\amake\\makefile.tpldowsparam.tpl"
								{
#line 126 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\n");
#line 127 "c:\\amake\\makefile.tpldowsparam.tpl"
									set_line_no(127);
#line 127 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\t\t\t\t\t\t\t\t\t");
#line 127 "c:\\amake\\makefile.tpldowsparam.tpl"
									use_pump_command=1;
#line 127 "c:\\amake\\makefile.tpldowsparam.tpl"
									set_value("am_found","yes");
#line 127 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\n");
#line 128 "c:\\amake\\makefile.tpldowsparam.tpl"
									set_line_no(128);
#line 128 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\t\t\t\t\t\t\t\t");
#line 128 "c:\\amake\\makefile.tpldowsparam.tpl"
									use_pump_command=1;
#line 128 "c:\\amake\\makefile.tpldowsparam.tpl"
								}
#line 128 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\n");
#line 129 "c:\\amake\\makefile.tpldowsparam.tpl"
								set_line_no(129);
#line 129 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\t\t\t\t\t\t\t");
#line 129 "c:\\amake\\makefile.tpldowsparam.tpl"
								use_pump_command=1;
#line 129 "c:\\amake\\makefile.tpldowsparam.tpl"
								leave();
#line 129 "c:\\amake\\makefile.tpldowsparam.tpl"
							}
#line 129 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 130 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(130);
#line 130 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t\t");
#line 130 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 130 "c:\\amake\\makefile.tpldowsparam.tpl"
							if (!strcmp(get_string("am_found"),"no"))
#line 130 "c:\\amake\\makefile.tpldowsparam.tpl"
							{
#line 130 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\n");
#line 131 "c:\\amake\\makefile.tpldowsparam.tpl"
								set_line_no(131);
#line 131 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\t\t\t\t\t\t\t\t");
#line 131 "c:\\amake\\makefile.tpldowsparam.tpl"
								use_pump_command=1;
#line 131 "c:\\amake\\makefile.tpldowsparam.tpl"
								printf("'%s' is not a parameter of package '%s'\n",get_string("am_parametername"),get_string("am_packagename"));
#line 131 "c:\\amake\\makefile.tpldowsparam.tpl"
								printf("\n");
#line 131 "c:\\amake\\makefile.tpldowsparam.tpl"
								error();
#line 131 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\n");
#line 132 "c:\\amake\\makefile.tpldowsparam.tpl"
								set_line_no(132);
#line 132 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\t\t\t\t\t\t\t");
#line 132 "c:\\amake\\makefile.tpldowsparam.tpl"
								use_pump_command=1;
#line 132 "c:\\amake\\makefile.tpldowsparam.tpl"
							}
#line 132 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 133 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(133);
#line 133 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t");
#line 133 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 133 "c:\\amake\\makefile.tpldowsparam.tpl"
						}
#line 133 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 134 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(134);
#line 134 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 134 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 134 "c:\\amake\\makefile.tpldowsparam.tpl"
						leave();
#line 134 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 134 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 135 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(135);
#line 135 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 135 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 135 "c:\\amake\\makefile.tpldowsparam.tpl"
					leave();
#line 135 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 136 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(136);
#line 136 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 136 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 136 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 136 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 137 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(137);
#line 137 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 137 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 137 "c:\\amake\\makefile.tpldowsparam.tpl"
				leave();
#line 137 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 137 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 138 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(138);
#line 138 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 138 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 138 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 138 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 138 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 139 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(139);
#line 139 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 139 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 139 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 139 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 140 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(140);
#line 140 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 141 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(141);
#line 141 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 141 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 142 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(142);
#line 142 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 142 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_packagecppflags"," ");
#line 142 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 143 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(143);
#line 143 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 143 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_packageldflags"," ");
#line 143 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 144 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(144);
#line 144 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 144 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_packagearflags"," ");
#line 144 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 145 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(145);
#line 145 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 145 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_packagelibs"," ");
#line 145 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 146 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(146);
#line 146 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 146 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 146 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 146 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 146 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 147 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(147);
#line 147 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 147 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 147 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagecppflags",addstring(get_string("am_packagecppflags"),addstring(" ",get_string("cppflags"))));
#line 147 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 148 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(148);
#line 148 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 148 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 148 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packageldflags",addstring(get_string("am_packageldflags"),addstring(" ",get_string("ldflags"))));
#line 148 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 149 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(149);
#line 149 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 149 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 149 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagearflags",addstring(get_string("am_packagearflags"),addstring(" ",get_string("arflags"))));
#line 149 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 150 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(150);
#line 150 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 150 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 150 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagelibs",addstring(get_string("am_packagelibs"),addstring(" ",get_string("libs"))));
#line 150 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 151 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(151);
#line 151 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 151 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 151 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 151 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 152 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(152);
#line 152 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 153 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(153);
#line 153 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 153 "c:\\amake\\makefile.tpldowsparam.tpl"
	enter("project");
#line 153 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 154 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(154);
#line 154 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 154 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("targettype"),"lib"))
#line 154 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 154 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 155 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(155);
#line 155 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("ISLIB=Y");
#line 155 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(156);
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("DEFINES=-D");
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_platform");
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" -D");
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_compiler");
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" -DISLIB");
#line 156 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 157 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(157);
#line 157 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("target=");
#line 157 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 157 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("target");
#line 157 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 157 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_lib_suffix");
#line 157 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 158 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(158);
#line 158 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 158 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 158 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (!strcmp(get_string("targettype"),"exe"))
#line 158 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 158 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 159 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(159);
#line 159 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("ISLIB=N");
#line 159 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(160);
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("DEFINES=-D");
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_platform");
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" -D");
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_compiler");
#line 160 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 161 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(161);
#line 161 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("target=");
#line 161 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 161 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("target");
#line 161 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 161 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_exe_suffix");
#line 161 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 162 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(162);
#line 162 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 162 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 162 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (!strcmp(get_string("targettype"),"dll"))
#line 162 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 162 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 163 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(163);
#line 163 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("ISLIB=Y");
#line 163 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(164);
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("DEFINES=-D");
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_platform");
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" -D");
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_compiler");
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" -DISLIB");
#line 164 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 165 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(165);
#line 165 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("target=");
#line 165 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 165 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("target");
#line 165 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 165 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_dll_suffix");
#line 165 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 166 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(166);
#line 166 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 166 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 166 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 166 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 166 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 167 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(167);
#line 167 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 167 "c:\\amake\\makefile.tpldowsparam.tpl"
		printf("unknown target type:%s",get_string("targettype"));
#line 167 "c:\\amake\\makefile.tpldowsparam.tpl"
		printf("\n");
#line 167 "c:\\amake\\makefile.tpldowsparam.tpl"
		error();
#line 167 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 168 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(168);
#line 168 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 168 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 168 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 169 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(169);
#line 169 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 170 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(170);
#line 170 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 170 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("hasdebug"),"yes"))
#line 170 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 170 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 171 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(171);
#line 171 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("DEBUG_DEFINE=-DDEBUG -DDEBUG_LOG");
#line 171 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 172 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(172);
#line 172 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 172 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 172 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 172 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 172 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 173 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(173);
#line 173 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("DEBUG_DEFINE=");
#line 173 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 174 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(174);
#line 174 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 174 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 174 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 175 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(175);
#line 175 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 176 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(176);
#line 176 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 176 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("hasdebug"),"yes")&&!strcmp(get_string("multithread"),"yes"))
#line 176 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 176 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 177 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(177);
#line 177 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("APPEND_CPPFLAGS=");
#line 177 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 177 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_debug_multithread_cppflags");
#line 177 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 178 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(178);
#line 178 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 178 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 178 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (!strcmp(get_string("hasdebug"),"yes")&&!strcmp(get_string("multithread"),"no"))
#line 178 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 178 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 179 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(179);
#line 179 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("APPEND_CPPFLAGS=");
#line 179 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 179 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_debug_singlethread_cppflags");
#line 179 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 180 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(180);
#line 180 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 180 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 180 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (!strcmp(get_string("hasdebug"),"no")&&!strcmp(get_string("multithread"),"yes"))
#line 180 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 180 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 181 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(181);
#line 181 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("APPEND_CPPFLAGS=");
#line 181 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 181 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_release_multithread_cppflags");
#line 181 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 182 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(182);
#line 182 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 182 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 182 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (!strcmp(get_string("hasdebug"),"no")&&!strcmp(get_string("multithread"),"no"))
#line 182 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 182 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 183 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(183);
#line 183 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("APPEND_CPPFLAGS=");
#line 183 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 183 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_release_singlethread_cppflags");
#line 183 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 184 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(184);
#line 184 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 184 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 184 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 185 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(185);
#line 185 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 186 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(186);
#line 186 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 186 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("hasprofile"),"yes"))
#line 186 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 186 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 187 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(187);
#line 187 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("PROFILE_CPPFLAGS=");
#line 187 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 187 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_profile_cppflags");
#line 187 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 188 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(188);
#line 188 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 188 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 188 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 188 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 188 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 189 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(189);
#line 189 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("PROFILE_CPPFLAGS=");
#line 189 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 190 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(190);
#line 190 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 190 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 190 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 191 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(191);
#line 191 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 192 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(192);
#line 192 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 192 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (atoi(get_string("warninglevel"))==0)
#line 192 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 192 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 193 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(193);
#line 193 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_CPPFLAGS=");
#line 193 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 193 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning0_cppflags");
#line 193 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 194 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(194);
#line 194 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 194 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 194 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (atoi(get_string("warninglevel"))==1)
#line 194 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 194 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 195 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(195);
#line 195 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_CPPFLAGS=");
#line 195 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 195 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning1_cppflags");
#line 195 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 196 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(196);
#line 196 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 196 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 196 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (atoi(get_string("warninglevel"))==2)
#line 196 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 196 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 197 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(197);
#line 197 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_CPPFLAGS=");
#line 197 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 197 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning2_cppflags");
#line 197 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 198 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(198);
#line 198 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 198 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 198 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (atoi(get_string("warninglevel"))==3)
#line 198 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 198 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 199 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(199);
#line 199 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_CPPFLAGS=");
#line 199 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 199 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning3_cppflags");
#line 199 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 200 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(200);
#line 200 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 200 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 200 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 200 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 200 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 201 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(201);
#line 201 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_CPPFLAGS=");
#line 201 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 202 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(202);
#line 202 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 202 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 202 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 203 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(203);
#line 203 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(204);
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("CPPFLAGS= ");
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("cppflags");
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_packagecppflags");
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" $(APPEND_CPPFLAGS) $(PROFILE_CPPFLAGS) $(WARNING_CPPFLAGS) $(DEBUG_DEFINE) $(DEFINES)");
#line 204 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 205 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(205);
#line 205 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(206);
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("LIBS= ");
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_libs");
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("libs");
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_packagelibs");
#line 206 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 207 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(207);
#line 207 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 208 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(208);
#line 208 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 208 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("hasdebug"),"yes"))
#line 208 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 208 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 209 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(209);
#line 209 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("DEBUG_LDFLAGS=");
#line 209 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 209 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_debug_ldflags");
#line 209 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 210 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(210);
#line 210 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 210 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 210 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 210 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 210 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 211 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(211);
#line 211 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("DEBUG_LDFLAGS=");
#line 211 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 212 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(212);
#line 212 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 212 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 212 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 213 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(213);
#line 213 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 214 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(214);
#line 214 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 214 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("hasmap"),"yes"))
#line 214 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 214 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 215 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(215);
#line 215 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("MAP_LDFLAGS=");
#line 215 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 215 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_map_ldflags");
#line 215 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 216 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(216);
#line 216 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 216 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 216 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 216 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 216 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 217 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(217);
#line 217 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("MAP_LDFLAGS=");
#line 217 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 218 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(218);
#line 218 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 218 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 218 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 219 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(219);
#line 219 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 220 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(220);
#line 220 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 220 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("hasprofile"),"yes"))
#line 220 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 220 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 221 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(221);
#line 221 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("PROFILE_LDFLAGS=");
#line 221 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 221 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_profile_ldflags");
#line 221 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 222 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(222);
#line 222 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 222 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 222 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 222 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 222 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 223 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(223);
#line 223 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("PROFILE_LDFLAGS=");
#line 223 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 224 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(224);
#line 224 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 224 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 224 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 225 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(225);
#line 225 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 226 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(226);
#line 226 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 226 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (atoi(get_string("warninglevel"))==0)
#line 226 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 226 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 227 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(227);
#line 227 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_LDFLAGS=");
#line 227 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 227 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning0_ldflags");
#line 227 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 228 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(228);
#line 228 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 228 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 228 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (atoi(get_string("warninglevel"))==1)
#line 228 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 228 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 229 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(229);
#line 229 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_LDFLAGS=");
#line 229 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 229 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning1_ldflags");
#line 229 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 230 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(230);
#line 230 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 230 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 230 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (atoi(get_string("warninglevel"))==2)
#line 230 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 230 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 231 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(231);
#line 231 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_LDFLAGS=");
#line 231 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 231 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning2_ldflags");
#line 231 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 232 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(232);
#line 232 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 232 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 232 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (atoi(get_string("warninglevel"))==3)
#line 232 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 232 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 233 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(233);
#line 233 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_LDFLAGS=");
#line 233 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 233 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_warning3_ldflags");
#line 233 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 234 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(234);
#line 234 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 234 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 234 "c:\\amake\\makefile.tpldowsparam.tpl"
	else
#line 234 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 234 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 235 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(235);
#line 235 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("WARNING_LDFLAGS=");
#line 235 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 236 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(236);
#line 236 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 236 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 236 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 237 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(237);
#line 237 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(238);
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("LDFLAGS=");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("ldflags");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_packageldflags");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_basic_exe_ldflags");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS) $(WARNING_LDFLAGS)");
#line 238 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 239 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(239);
#line 239 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(240);
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("LIBARFLAGS=");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("arflags");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_packagearflags");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_basic_lib_ldflags");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)");
#line 240 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 241 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(241);
#line 241 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(242);
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("DLLARFLAGS=");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("arflags");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_packagearflags");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_basic_dll_ldflags");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)");
#line 242 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 243 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(243);
#line 243 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 244 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(244);
#line 244 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 244 "c:\\amake\\makefile.tpldowsparam.tpl"
	leave();
#line 244 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 245 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(245);
#line 245 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 246 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(246);
#line 246 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 246 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 247 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(247);
#line 247 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("all: makefile code");
#line 247 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 248 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(248);
#line 248 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 249 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(249);
#line 249 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("code: clearoutput $(target)");
#line 249 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 250 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(250);
#line 250 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 251 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(251);
#line 251 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 251 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_packagefiles"," ");
#line 251 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 252 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(252);
#line 252 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 252 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("project");tmp_value[0]++)
#line 252 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 252 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("project",tmp_value[0]);
#line 252 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 253 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(253);
#line 253 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 253 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 253 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagefiles",multiaddstring(4,get_string("am_packagefiles"),replace(get_string("dir"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")),get_string("am_dir_convertto"),"package.des "));
#line 253 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 254 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(254);
#line 254 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 254 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 254 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 254 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(255);
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("makefile:");
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_packagefiles");
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string(" ");
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("prjfile");
#line 255 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 256 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(256);
#line 256 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\tamake ");
#line 256 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 256 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("prjfile");
#line 256 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 257 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(257);
#line 257 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\t@$(ECHO) rerun nmake");
#line 257 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 258 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(258);
#line 258 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\t@");
#line 258 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 258 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_exit_make");
#line 258 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 259 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(259);
#line 259 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 260 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(260);
#line 260 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("clearoutput:");
#line 260 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 261 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(261);
#line 261 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\t@$(ECHO) Compiling... > output");
#line 261 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 262 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(262);
#line 262 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 263 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(263);
#line 263 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 263 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 264 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(264);
#line 264 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 264 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 264 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 264 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 264 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 265 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(265);
#line 265 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 265 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 265 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 266 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(266);
#line 266 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 266 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packageincludedir",replace(get_string("includedir"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")));
#line 266 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 267 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(267);
#line 267 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 267 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter("system");
#line 267 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 268 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(268);
#line 268 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 268 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 268 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("project");tmp_value[1]++)
#line 268 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 268 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("project",tmp_value[1]);
#line 268 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 269 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(269);
#line 269 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 269 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 269 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strcmp(get_string("am_packagename"),get_string("name")))
#line 269 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 269 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 270 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(270);
#line 270 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 270 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 270 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_basedir",replace(get_string("dir"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")));
#line 270 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 271 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(271);
#line 271 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 271 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 271 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 271 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 272 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(272);
#line 272 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 272 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 272 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 272 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 272 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 273 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(273);
#line 273 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 273 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 273 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(274);
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("name");
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("_obj=");
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("cppfile");tmp_value[1]++)
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("cppfile",tmp_value[1]);
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(" ");
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_basedir");
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_dir_convertto");
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(replace(get_string("name"),".cpp",get_string("am_obj_suffix")));
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(" ");
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 274 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 275 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(275);
#line 275 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 275 "c:\\amake\\makefile.tpldowsparam.tpl"
		if (valid_name("libfile"))
#line 275 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 275 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(276);
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("name");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("_lib=");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			for (tmp_value[1]=0;tmp_value[1]<length("libfile");tmp_value[1]++)
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				enter_set("libfile",tmp_value[1]);
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_basedir");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_dir_convertto");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("name");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_lib_suffix");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
				leave();
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 276 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 277 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(277);
#line 277 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 277 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 277 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(278);
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("name");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("_include=");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("headfile");tmp_value[1]++)
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("headfile",tmp_value[1]);
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(" ");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_basedir");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_dir_convertto");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("name");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(" ");
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 278 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(279);
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("name");
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("_includedir=-I");
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_basedir");
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_dir_convertto");
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_packageincludedir");
#line 279 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 280 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(280);
#line 280 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 280 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 280 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 280 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 281 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(281);
#line 281 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 282 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(282);
#line 282 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 282 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(283);
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("all_objs=");
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("project");tmp_value[0]++)
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("project",tmp_value[0]);
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" $(");
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("name");
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("_obj) ");
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 283 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(284);
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("all_libs=");
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("project");tmp_value[0]++)
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("project",tmp_value[0]);
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" $(");
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("name");
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("_lib) ");
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 284 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(285);
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("INCLUDEDIR=");
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("project");tmp_value[0]++)
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("project",tmp_value[0]);
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" $(");
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("name");
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("_includedir) ");
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 285 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 286 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(286);
#line 286 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 287 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(287);
#line 287 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 287 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 288 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(288);
#line 288 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 288 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 288 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 288 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 288 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 289 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(289);
#line 289 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 289 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 289 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 290 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(290);
#line 290 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 290 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter("system");
#line 290 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 291 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(291);
#line 291 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 291 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 291 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("project");tmp_value[1]++)
#line 291 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 291 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("project",tmp_value[1]);
#line 291 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 292 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(292);
#line 292 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 292 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 292 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strcmp(get_string("am_packagename"),get_string("name")))
#line 292 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 292 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 293 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(293);
#line 293 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 293 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 293 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_basedir",replace(get_string("dir"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")));
#line 293 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 294 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(294);
#line 294 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 294 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 294 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 294 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 295 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(295);
#line 295 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 295 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 295 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 295 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 295 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 296 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(296);
#line 296 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 296 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 296 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 297 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(297);
#line 297 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 297 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_dependinclude"," ");
#line 297 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 298 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(298);
#line 298 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 298 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("depend");tmp_value[1]++)
#line 298 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 298 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("depend",tmp_value[1]);
#line 298 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 299 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(299);
#line 299 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 299 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("am_dependinclude",addstring(get_string("am_dependinclude"),addstring(" $(",addstring(get_string("name"),"_include)"))));
#line 299 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 300 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(300);
#line 300 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 300 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 300 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 300 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 301 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(301);
#line 301 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 301 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("cppfile");tmp_value[1]++)
#line 301 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 301 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("cppfile",tmp_value[1]);
#line 301 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(302);
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_basedir");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_dir_convertto");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(replace(get_string("name"),".cpp",get_string("am_obj_suffix")));
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(": ");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_basedir");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_dir_convertto");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("name");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(" $(");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_packagename");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("_include) ");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_dependinclude");
#line 302 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 303 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(303);
#line 303 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 304 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(304);
#line 304 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 304 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 304 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 304 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 305 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(305);
#line 305 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 305 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 305 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 305 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 306 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(306);
#line 306 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 307 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(307);
#line 307 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 307 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 308 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(308);
#line 308 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 308 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_customtarget"," ");
#line 308 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 309 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(309);
#line 309 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 309 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_pumptargetall"," ");
#line 309 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 310 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(310);
#line 310 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 310 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_value("am_luatargetall"," ");
#line 310 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 311 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(311);
#line 311 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 311 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("package");tmp_value[0]++)
#line 311 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 311 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("package",tmp_value[0]);
#line 311 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 312 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(312);
#line 312 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 312 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 312 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_value("am_packagename",get_string("name"));
#line 312 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 313 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(313);
#line 313 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 313 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 313 "c:\\amake\\makefile.tpldowsparam.tpl"
		for (tmp_value[1]=0;tmp_value[1]<length("command");tmp_value[1]++)
#line 313 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 313 "c:\\amake\\makefile.tpldowsparam.tpl"
			enter_set("command",tmp_value[1]);
#line 313 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 314 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(314);
#line 314 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 314 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 314 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("am_command",get_string("name"));
#line 314 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 315 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(315);
#line 315 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 315 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 315 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strcmp(get_string("name"),"copy"))
#line 315 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 315 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 316 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(316);
#line 316 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 316 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 316 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_copysource","notdefined");
#line 316 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 317 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(317);
#line 317 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 317 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 317 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_copytarget","notdefined");
#line 317 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 318 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(318);
#line 318 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 318 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 318 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 318 "c:\\amake\\makefile.tpldowsparam.tpl"
			else if (!strcmp(get_string("name"),"pump"))
#line 318 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 318 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 319 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(319);
#line 319 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 319 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 319 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_pumptarget","notdefined");
#line 319 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 320 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(320);
#line 320 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 320 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 320 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_pumptpl","notdefined");
#line 320 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 321 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(321);
#line 321 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 321 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 321 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_pumpenv","notdefined");
#line 321 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 322 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(322);
#line 322 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 322 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 322 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 322 "c:\\amake\\makefile.tpldowsparam.tpl"
			else if (!strcmp(get_string("name"),"lua"))
#line 322 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 322 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 323 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(323);
#line 323 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 323 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 323 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_luatarget","notdefined");
#line 323 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 324 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(324);
#line 324 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 324 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 324 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_luatpl","notdefined");
#line 324 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 325 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(325);
#line 325 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 325 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 325 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_luaenv","notdefined");
#line 325 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 325 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 326 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(326);
#line 326 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 326 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 326 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 326 "c:\\amake\\makefile.tpldowsparam.tpl"
			else
#line 326 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 326 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 327 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(327);
#line 327 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 327 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 327 "c:\\amake\\makefile.tpldowsparam.tpl"
				printf("unknown command '%s' in package '%s'\n",get_string("name"),get_string("am_packagename"));
#line 327 "c:\\amake\\makefile.tpldowsparam.tpl"
				printf("\n");
#line 327 "c:\\amake\\makefile.tpldowsparam.tpl"
				error();
#line 327 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 328 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(328);
#line 328 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 328 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 328 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 328 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 329 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(329);
#line 329 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 329 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 329 "c:\\amake\\makefile.tpldowsparam.tpl"
			for (tmp_value[2]=0;tmp_value[2]<length("self");tmp_value[2]++)
#line 329 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 329 "c:\\amake\\makefile.tpldowsparam.tpl"
				enter_set("self",tmp_value[2]);
#line 329 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 330 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(330);
#line 330 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 330 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 330 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("type"),"parameter"))
#line 330 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 330 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 331 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(331);
#line 331 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 331 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 331 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_parametername",get_string("value"));
#line 331 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 332 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(332);
#line 332 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 332 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 332 "c:\\amake\\makefile.tpldowsparam.tpl"
					enter("system");
#line 332 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 333 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(333);
#line 333 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 333 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 333 "c:\\amake\\makefile.tpldowsparam.tpl"
					for (tmp_value[3]=0;tmp_value[3]<length("project");tmp_value[3]++)
#line 333 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 333 "c:\\amake\\makefile.tpldowsparam.tpl"
						enter_set("project",tmp_value[3]);
#line 333 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 334 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(334);
#line 334 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 334 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 334 "c:\\amake\\makefile.tpldowsparam.tpl"
						if (!strcmp(get_string("name"),get_string("am_packagename")))
#line 334 "c:\\amake\\makefile.tpldowsparam.tpl"
						{
#line 334 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 335 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(335);
#line 335 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t");
#line 335 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 335 "c:\\amake\\makefile.tpldowsparam.tpl"
							for (tmp_value[4]=0;tmp_value[4]<length("self");tmp_value[4]++)
#line 335 "c:\\amake\\makefile.tpldowsparam.tpl"
							{
#line 335 "c:\\amake\\makefile.tpldowsparam.tpl"
								enter_set("self",tmp_value[4]);
#line 335 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\n");
#line 336 "c:\\amake\\makefile.tpldowsparam.tpl"
								set_line_no(336);
#line 336 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\t\t\t\t\t\t\t");
#line 336 "c:\\amake\\makefile.tpldowsparam.tpl"
								use_pump_command=1;
#line 336 "c:\\amake\\makefile.tpldowsparam.tpl"
								if (!strcmp(get_string("name"),get_string("am_parametername")))
#line 336 "c:\\amake\\makefile.tpldowsparam.tpl"
								{
#line 336 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\n");
#line 337 "c:\\amake\\makefile.tpldowsparam.tpl"
									set_line_no(337);
#line 337 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\t\t\t\t\t\t\t\t");
#line 337 "c:\\amake\\makefile.tpldowsparam.tpl"
									use_pump_command=1;
#line 337 "c:\\amake\\makefile.tpldowsparam.tpl"
									set_value("am_argumentvalue",replace(get_string("value"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")));
#line 337 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\n");
#line 338 "c:\\amake\\makefile.tpldowsparam.tpl"
									set_line_no(338);
#line 338 "c:\\amake\\makefile.tpldowsparam.tpl"
									display_string("\t\t\t\t\t\t\t");
#line 338 "c:\\amake\\makefile.tpldowsparam.tpl"
									use_pump_command=1;
#line 338 "c:\\amake\\makefile.tpldowsparam.tpl"
								}
#line 338 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\n");
#line 339 "c:\\amake\\makefile.tpldowsparam.tpl"
								set_line_no(339);
#line 339 "c:\\amake\\makefile.tpldowsparam.tpl"
								display_string("\t\t\t\t\t\t");
#line 339 "c:\\amake\\makefile.tpldowsparam.tpl"
								use_pump_command=1;
#line 339 "c:\\amake\\makefile.tpldowsparam.tpl"
								leave();
#line 339 "c:\\amake\\makefile.tpldowsparam.tpl"
							}
#line 339 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 340 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(340);
#line 340 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t");
#line 340 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 340 "c:\\amake\\makefile.tpldowsparam.tpl"
						}
#line 340 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 341 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(341);
#line 341 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 341 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 341 "c:\\amake\\makefile.tpldowsparam.tpl"
						leave();
#line 341 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 341 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 342 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(342);
#line 342 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 342 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 342 "c:\\amake\\makefile.tpldowsparam.tpl"
					leave();
#line 342 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 343 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(343);
#line 343 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 343 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 343 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 343 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("type"),"file"))
#line 343 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 343 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 344 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(344);
#line 344 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 344 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 344 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_value("am_filename",replace(get_string("value"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")));
#line 344 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 345 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(345);
#line 345 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 345 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 345 "c:\\amake\\makefile.tpldowsparam.tpl"
					enter("system");
#line 345 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 346 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(346);
#line 346 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 346 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 346 "c:\\amake\\makefile.tpldowsparam.tpl"
					for (tmp_value[3]=0;tmp_value[3]<length("project");tmp_value[3]++)
#line 346 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 346 "c:\\amake\\makefile.tpldowsparam.tpl"
						enter_set("project",tmp_value[3]);
#line 346 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 347 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(347);
#line 347 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 347 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 347 "c:\\amake\\makefile.tpldowsparam.tpl"
						if (!strcmp(get_string("name"),get_string("am_packagename")))
#line 347 "c:\\amake\\makefile.tpldowsparam.tpl"
						{
#line 347 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 348 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(348);
#line 348 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t\t");
#line 348 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 348 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_value("am_argumentvalue",multiaddstring(3,replace(get_string("dir"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")),get_string("am_dir_convertto"),get_string("am_filename")));
#line 348 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\n");
#line 349 "c:\\amake\\makefile.tpldowsparam.tpl"
							set_line_no(349);
#line 349 "c:\\amake\\makefile.tpldowsparam.tpl"
							display_string("\t\t\t\t\t");
#line 349 "c:\\amake\\makefile.tpldowsparam.tpl"
							use_pump_command=1;
#line 349 "c:\\amake\\makefile.tpldowsparam.tpl"
						}
#line 349 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 350 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(350);
#line 350 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 350 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 350 "c:\\amake\\makefile.tpldowsparam.tpl"
						leave();
#line 350 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 350 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 351 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(351);
#line 351 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 351 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 351 "c:\\amake\\makefile.tpldowsparam.tpl"
					leave();
#line 351 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 352 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(352);
#line 352 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 352 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 352 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 352 "c:\\amake\\makefile.tpldowsparam.tpl"
				else
#line 352 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 352 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 353 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(353);
#line 353 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 353 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 353 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("unknown type '%s' in package '%s'\n",get_string("type"),get_string("am_packagename"));
#line 353 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 353 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 353 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 354 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(354);
#line 354 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 354 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 354 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 354 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 355 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(355);
#line 355 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 355 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 355 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_argumentvalue",replace(get_string("am_argumentvalue"),get_string("am_dir_convertfrom"),get_string("am_dir_convertto")));
#line 355 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 356 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(356);
#line 356 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 356 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 356 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_command"),"copy"))
#line 356 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 356 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 357 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(357);
#line 357 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 357 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 357 "c:\\amake\\makefile.tpldowsparam.tpl"
					if (!strcmp(get_string("name"),"source"))
#line 357 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 357 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 358 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(358);
#line 358 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 358 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 358 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_copysource",get_string("am_argumentvalue"));
#line 358 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 359 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(359);
#line 359 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 359 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 359 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 359 "c:\\amake\\makefile.tpldowsparam.tpl"
					else if (!strcmp(get_string("name"),"target"))
#line 359 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 359 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 360 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(360);
#line 360 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 360 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 360 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_copytarget",get_string("am_argumentvalue"));
#line 360 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 361 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(361);
#line 361 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 361 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 361 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 361 "c:\\amake\\makefile.tpldowsparam.tpl"
					else
#line 361 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 361 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 362 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(362);
#line 362 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 362 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 362 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("'%s' is not an argument of command 'copy' in package '%s'\n",get_string("name"),get_string("am_packagename"));
#line 362 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("\n");
#line 362 "c:\\amake\\makefile.tpldowsparam.tpl"
						error();
#line 362 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 363 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(363);
#line 363 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 363 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 363 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 363 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 364 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(364);
#line 364 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 364 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 364 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 364 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("am_command"),"pump"))
#line 364 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 364 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 365 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(365);
#line 365 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 365 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 365 "c:\\amake\\makefile.tpldowsparam.tpl"
					if (!strcmp(get_string("name"),"target"))
#line 365 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 365 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 366 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(366);
#line 366 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 366 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 366 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_pumptarget",get_string("am_argumentvalue"));
#line 366 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 367 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(367);
#line 367 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 367 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 367 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 367 "c:\\amake\\makefile.tpldowsparam.tpl"
					else if (!strcmp(get_string("name"),"template"))
#line 367 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 367 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 368 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(368);
#line 368 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 368 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 368 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_pumptpl",get_string("am_argumentvalue"));
#line 368 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 369 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(369);
#line 369 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 369 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 369 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 369 "c:\\amake\\makefile.tpldowsparam.tpl"
					else if (!strcmp(get_string("name"),"env"))
#line 369 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 369 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 370 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(370);
#line 370 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 370 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 370 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_pumpenv",get_string("am_argumentvalue"));
#line 370 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 371 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(371);
#line 371 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 371 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 371 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 371 "c:\\amake\\makefile.tpldowsparam.tpl"
					else
#line 371 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 371 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 372 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(372);
#line 372 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 372 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 372 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("'%s' is not an argument of command 'pump' in package '%s'\n",get_string("name"),get_string("am_packagename"));
#line 372 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("\n");
#line 372 "c:\\amake\\makefile.tpldowsparam.tpl"
						error();
#line 372 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 373 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(373);
#line 373 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 373 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 373 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 373 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 374 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(374);
#line 374 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 374 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 374 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 374 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("am_command"),"lua"))
#line 374 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 374 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 375 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(375);
#line 375 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 375 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 375 "c:\\amake\\makefile.tpldowsparam.tpl"
					if (!strcmp(get_string("name"),"target"))
#line 375 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 375 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 376 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(376);
#line 376 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 376 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 376 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_luatarget",get_string("am_argumentvalue"));
#line 376 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 377 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(377);
#line 377 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 377 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 377 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 377 "c:\\amake\\makefile.tpldowsparam.tpl"
					else if (!strcmp(get_string("name"),"template"))
#line 377 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 377 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 378 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(378);
#line 378 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 378 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 378 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_luatpl",get_string("am_argumentvalue"));
#line 378 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 379 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(379);
#line 379 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 379 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 379 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 379 "c:\\amake\\makefile.tpldowsparam.tpl"
					else if (!strcmp(get_string("name"),"env"))
#line 379 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 379 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 380 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(380);
#line 380 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 380 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 380 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_value("am_luaenv",get_string("am_argumentvalue"));
#line 380 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 381 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(381);
#line 381 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 381 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 381 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 381 "c:\\amake\\makefile.tpldowsparam.tpl"
					else
#line 381 "c:\\amake\\makefile.tpldowsparam.tpl"
					{
#line 381 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 382 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(382);
#line 382 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t\t");
#line 382 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 382 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("'%s' is not an argument of command 'lua' in package '%s'\n",get_string("name"),get_string("am_packagename"));
#line 382 "c:\\amake\\makefile.tpldowsparam.tpl"
						printf("\n");
#line 382 "c:\\amake\\makefile.tpldowsparam.tpl"
						error();
#line 382 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\n");
#line 383 "c:\\amake\\makefile.tpldowsparam.tpl"
						set_line_no(383);
#line 383 "c:\\amake\\makefile.tpldowsparam.tpl"
						display_string("\t\t\t\t");
#line 383 "c:\\amake\\makefile.tpldowsparam.tpl"
						use_pump_command=1;
#line 383 "c:\\amake\\makefile.tpldowsparam.tpl"
					}
#line 383 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 383 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 384 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(384);
#line 384 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 384 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 384 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 384 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 385 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(385);
#line 385 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 385 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 385 "c:\\amake\\makefile.tpldowsparam.tpl"
				leave();
#line 385 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 385 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 386 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(386);
#line 386 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t\t");
#line 386 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 386 "c:\\amake\\makefile.tpldowsparam.tpl"
			if (!strcmp(get_string("am_command"),"copy"))
#line 386 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 386 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 387 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(387);
#line 387 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 387 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 387 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_copysource"),"notdefined"))
#line 387 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 387 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 388 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(388);
#line 388 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 388 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 388 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("source not defined for copy command in package '%s'",get_string("am_packagename"));
#line 388 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 388 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 388 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 389 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(389);
#line 389 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 389 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 389 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 389 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("am_copytarget"),"notdefined"))
#line 389 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 389 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 390 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(390);
#line 390 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 390 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 390 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("target not defined for copy command in package '%s'",get_string("am_packagename"));
#line 390 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 390 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 390 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 391 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(391);
#line 391 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 391 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 391 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 391 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 392 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(392);
#line 392 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 392 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 392 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_customtarget",addstring(get_string("am_customtarget"),addstring(" ",get_string("am_copytarget"))));
#line 392 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 393 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(393);
#line 393 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 393 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_copytarget");
#line 393 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(":");
#line 393 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 393 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_copysource");
#line 393 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(394);
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t$(COPY) ");
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_copysource");
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_copytarget");
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" >> output");
#line 394 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 395 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(395);
#line 395 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 395 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 395 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 395 "c:\\amake\\makefile.tpldowsparam.tpl"
			else if (!strcmp(get_string("am_command"),"pump"))
#line 395 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 395 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 396 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(396);
#line 396 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 396 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 396 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_pumptarget"),"notdefined"))
#line 396 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 396 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 397 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(397);
#line 397 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 397 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 397 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("target not defined for pump command in package '%s'",get_string("am_packagename"));
#line 397 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 397 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 397 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 398 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(398);
#line 398 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 398 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 398 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 398 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("am_pumptpl"),"notdefined"))
#line 398 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 398 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 399 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(399);
#line 399 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 399 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 399 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("template not defined for pump command in package '%s'",get_string("am_packagename"));
#line 399 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 399 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 399 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 400 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(400);
#line 400 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 400 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 400 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 400 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("am_pumpenv"),"notdefined"))
#line 400 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 400 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 401 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(401);
#line 401 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 401 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 401 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("env not defined for pump command in package '%s'",get_string("am_packagename"));
#line 401 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 401 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 401 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 402 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(402);
#line 402 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 402 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 402 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 402 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 403 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(403);
#line 403 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 403 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 403 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_customtarget",addstring(get_string("am_customtarget"),addstring(" ",get_string("am_pumptarget"))));
#line 403 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 404 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(404);
#line 404 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 404 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 404 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_pumptargetall",multiaddstring(3,get_string("am_pumptargetall")," ",get_string("am_pumptarget")));
#line 404 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(405);
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_pumptarget");
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(":");
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_pumptpl");
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_pumpenv");
#line 405 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(406);
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t$(PUMP) ");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_pumptarget");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_pumptpl");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_pumpenv");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" >> output");
#line 406 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(407);
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
			else if (!strcmp(get_string("am_command"),"lua"))
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
			{
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t");
#line 407 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 408 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(408);
#line 408 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 408 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 408 "c:\\amake\\makefile.tpldowsparam.tpl"
				if (!strcmp(get_string("am_luatarget"),"notdefined"))
#line 408 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 408 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 409 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(409);
#line 409 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 409 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 409 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("target not defined for lua command in package '%s'",get_string("am_packagename"));
#line 409 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 409 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 409 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 410 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(410);
#line 410 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 410 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 410 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 410 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("am_luatpl"),"notdefined"))
#line 410 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 410 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 411 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(411);
#line 411 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 411 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 411 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("template not defined for lua command in package '%s'",get_string("am_packagename"));
#line 411 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 411 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 411 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 412 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(412);
#line 412 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 412 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 412 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 412 "c:\\amake\\makefile.tpldowsparam.tpl"
				else if (!strcmp(get_string("am_luaenv"),"notdefined"))
#line 412 "c:\\amake\\makefile.tpldowsparam.tpl"
				{
#line 412 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 413 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(413);
#line 413 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t\t");
#line 413 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 413 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("env not defined for lua command in package '%s'",get_string("am_packagename"));
#line 413 "c:\\amake\\makefile.tpldowsparam.tpl"
					printf("\n");
#line 413 "c:\\amake\\makefile.tpldowsparam.tpl"
					error();
#line 413 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\n");
#line 414 "c:\\amake\\makefile.tpldowsparam.tpl"
					set_line_no(414);
#line 414 "c:\\amake\\makefile.tpldowsparam.tpl"
					display_string("\t\t\t");
#line 414 "c:\\amake\\makefile.tpldowsparam.tpl"
					use_pump_command=1;
#line 414 "c:\\amake\\makefile.tpldowsparam.tpl"
				}
#line 414 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 415 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(415);
#line 415 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 415 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 415 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_customtarget",addstring(get_string("am_customtarget"),addstring(" ",get_string("am_luatarget"))));
#line 415 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 416 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(416);
#line 416 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t\t");
#line 416 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 416 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_value("am_luatargetall",multiaddstring(3,get_string("am_luatargetall")," ",get_string("am_luatarget")));
#line 416 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(417);
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_luatarget");
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(":");
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_luatpl");
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_luaenv");
#line 417 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(418);
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t$(LUA) ");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_luatpl");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_luaenv");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" ");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_name("am_luatarget");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string(" >> output\t\t\t");
#line 418 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\n");
#line 419 "c:\\amake\\makefile.tpldowsparam.tpl"
				set_line_no(419);
#line 419 "c:\\amake\\makefile.tpldowsparam.tpl"
				display_string("\t\t");
#line 419 "c:\\amake\\makefile.tpldowsparam.tpl"
				use_pump_command=1;
#line 419 "c:\\amake\\makefile.tpldowsparam.tpl"
			}
#line 419 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 420 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(420);
#line 420 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 421 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(421);
#line 421 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t");
#line 421 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 421 "c:\\amake\\makefile.tpldowsparam.tpl"
			leave();
#line 421 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 421 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 422 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(422);
#line 422 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 422 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 422 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 422 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 423 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(423);
#line 423 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 424 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(424);
#line 424 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 424 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 425 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(425);
#line 425 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 425 "c:\\amake\\makefile.tpldowsparam.tpl"
	enter("project");
#line 425 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 426 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(426);
#line 426 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 426 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("targettype"),"dll"))
#line 426 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 426 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 427 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(427);
#line 427 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("$(target): $(all_objs)");
#line 427 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(428);
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t$(LINK) $(DLLARFLAGS) ");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_output_ldindicate");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("$@ ");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_implib_ldindicate");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("target");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_lib_suffix");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string(" $(all_objs) $(all_libs) $(LIBS) >> output");
#line 428 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 429 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(429);
#line 429 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 429 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 429 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (!strcmp(get_string("targettype"),"exe"))
#line 429 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 429 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 430 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(430);
#line 430 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 431 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(431);
#line 431 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 431 "c:\\amake\\makefile.tpldowsparam.tpl"
		if (!valid_name("nodef"))
#line 431 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 431 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 432 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(432);
#line 432 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 432 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_value("nodef","");
#line 432 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 433 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(433);
#line 433 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 433 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 433 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 434 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(434);
#line 434 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 435 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(435);
#line 435 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 435 "c:\\amake\\makefile.tpldowsparam.tpl"
		if (!strcmp(get_string("nodef"),""))
#line 435 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 435 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 436 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(436);
#line 436 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("$(target): $(all_objs)");
#line 436 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 437 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(437);
#line 437 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t$(LINK) $(LDFLAGS) ");
#line 437 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 437 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_output_ldindicate");
#line 437 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("$@ $(all_objs) $(all_libs) $(LIBS) >> output");
#line 437 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 438 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(438);
#line 438 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 438 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 438 "c:\\amake\\makefile.tpldowsparam.tpl"
		else if (!strcmp(get_string("am_compiler"),"MSVC"))
#line 438 "c:\\amake\\makefile.tpldowsparam.tpl"
		{
#line 438 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 439 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(439);
#line 439 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("$(target): $(all_objs)");
#line 439 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(440);
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\t$(LINK) $(LDFLAGS) -NODEFAULTLIB:");
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("nodef");
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string(".lib ");
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_name("am_output_ldindicate");
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("$@ $(all_objs) $(all_libs) $(LIBS) >> output");
#line 440 "c:\\amake\\makefile.tpldowsparam.tpl"
			display_string("\n");
#line 441 "c:\\amake\\makefile.tpldowsparam.tpl"
			set_line_no(441);
#line 441 "c:\\amake\\makefile.tpldowsparam.tpl"
			use_pump_command=1;
#line 441 "c:\\amake\\makefile.tpldowsparam.tpl"
		}
#line 441 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 442 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(442);
#line 442 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 443 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(443);
#line 443 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 443 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 443 "c:\\amake\\makefile.tpldowsparam.tpl"
	else if (!strcmp(get_string("targettype"),"lib"))
#line 443 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 443 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 444 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(444);
#line 444 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("$(target): $(all_objs)");
#line 444 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 445 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(445);
#line 445 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t$(LINK) $(LIBARFLAGS) ");
#line 445 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 445 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_output_ldindicate");
#line 445 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("$@ $(all_objs) $(all_libs) $(LIBS) >> output");
#line 445 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 446 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(446);
#line 446 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 446 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 446 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 447 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(447);
#line 447 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 448 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(448);
#line 448 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 448 "c:\\amake\\makefile.tpldowsparam.tpl"
	leave();
#line 448 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 449 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(449);
#line 449 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 450 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(450);
#line 450 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 450 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 451 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(451);
#line 451 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 451 "c:\\amake\\makefile.tpldowsparam.tpl"
	enter("project");
#line 451 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 452 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(452);
#line 452 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("clean:");
#line 452 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 453 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(453);
#line 453 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\t");
#line 453 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 453 "c:\\amake\\makefile.tpldowsparam.tpl"
	for (tmp_value[0]=0;tmp_value[0]<length("self");tmp_value[0]++)
#line 453 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 453 "c:\\amake\\makefile.tpldowsparam.tpl"
		enter_set("self",tmp_value[0]);
#line 453 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 454 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(454);
#line 454 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t-$(DEL) $(");
#line 454 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 454 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("name");
#line 454 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("_obj)");
#line 454 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 455 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(455);
#line 455 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 455 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 455 "c:\\amake\\makefile.tpldowsparam.tpl"
		leave();
#line 455 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 455 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 456 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(456);
#line 456 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\t");
#line 456 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 456 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (strlen(get_string("am_customtarget"))>1)
#line 456 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 456 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 457 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(457);
#line 457 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t-$(DEL) ");
#line 457 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 457 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_customtarget");
#line 457 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 458 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(458);
#line 458 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 458 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 458 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 458 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 459 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(459);
#line 459 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\t-$(DEL) $(target)");
#line 459 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 460 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(460);
#line 460 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\t");
#line 460 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 460 "c:\\amake\\makefile.tpldowsparam.tpl"
	if (!strcmp(get_string("targettype"),"dll"))
#line 460 "c:\\amake\\makefile.tpldowsparam.tpl"
	{
#line 460 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 461 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(461);
#line 461 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t-$(DEL) ");
#line 461 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 461 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("target");
#line 461 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 461 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_name("am_lib_suffix");
#line 461 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\n");
#line 462 "c:\\amake\\makefile.tpldowsparam.tpl"
		set_line_no(462);
#line 462 "c:\\amake\\makefile.tpldowsparam.tpl"
		display_string("\t");
#line 462 "c:\\amake\\makefile.tpldowsparam.tpl"
		use_pump_command=1;
#line 462 "c:\\amake\\makefile.tpldowsparam.tpl"
	}
#line 462 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 463 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(463);
#line 463 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 463 "c:\\amake\\makefile.tpldowsparam.tpl"
	leave();
#line 463 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 464 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(464);
#line 464 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 465 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(465);
#line 465 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 465 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 466 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(466);
#line 466 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("pump: ");
#line 466 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 466 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_pumptargetall");
#line 466 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 467 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(467);
#line 467 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 468 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(468);
#line 468 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("lua: ");
#line 468 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 468 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_name("am_luatargetall");
#line 468 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 469 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(469);
#line 469 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 470 "c:\\amake\\makefile.tpldowsparam.tpl"
	set_line_no(470);
#line 470 "c:\\amake\\makefile.tpldowsparam.tpl"
	use_pump_command=1;
#line 470 "c:\\amake\\makefile.tpldowsparam.tpl"
	leave();
#line 470 "c:\\amake\\makefile.tpldowsparam.tpl"
	display_string("\n");
#line 20 "c:\\amake\\windows\\makefile.win.tpl"
	use_pump_command=1;
#line 20 "c:\\amake\\windows\\makefile.win.tpl"
	display_string("\n");
}
