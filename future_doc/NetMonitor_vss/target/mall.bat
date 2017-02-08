@echo const char *version="%date:~0,4%%date:~5,2%%date:~8,2%.%time:~0,8%"; > ../source/version/versionValue.h
@echo off
@echo make sysagent
@cd sysagent
@call amake sysagent.prj
@call nmake /nologo
@cd ..
@echo make syseventcounter
@cd syseventcounter
@call amake syseventcounter.prj
@call nmake /nologo
@cd ..
@echo make sysfibclient
@cd sysfibclient
@call amake sysfibclient.prj
@call nmake /nologo
@cd ..
@echo make sysfront
@cd sysfront
@call amake sysfront.prj
@call nmake /nologo
@cd ..
@echo make sysprobe
@cd sysprobe
@call amake sysprobe.prj
@call nmake /nologo
@cd ..
@echo make sysquery
@cd sysquery
@call amake sysquery.prj
@call nmake /nologo
@cd ..