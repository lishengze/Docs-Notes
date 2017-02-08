!!include TableDefine.tpl!!
!!function!!
int step=0;
!!endfunction!!
--created with pump(DP.xxxx-xxxxxx.xml DB.xml) by wang.xiping 
--step 0
!!enter DataPrepare!!
	!!travel self!!
		!!let subName=substr(@name,0,2)!!
		!!let schemaName=substr(@name,3,strlen(@name))!!
		!!if !strcmp(@subName,"DB") !!
			!!travel self!!
				!!let tableName=substr(@name,strlen(@schemaName)+1,strlen(@name))!!
	delete from !!@schemaName!!.t_!!@tableName!!;
			!!next!!
		!!endif!!
	!!next!!
!!leave!!

!!enter DataPrepare!!
	!!travel self!!
	!!command step++!!
	!!let stepStr=to_string(step)!!
--step !!@stepStr!!
	!!let subName=substr(@name,0,2)!!
	!!let schemaName=substr(@name,3,strlen(@name))!!
	!!if !strcmp(@subName,"DB") !!
		!!travel self!!
	--!!@action!! !!@name!!:!!@comment!!
			!!let tableName=substr(@name,strlen(@schemaName)+1,strlen(@name))!!
			!!**≤Â»Î”Ôæ‰!!
			!!if !strcmp(@action,"insert")!!
				!!let CurrColName=""!!
				!!let CurrValStr=""!!
				!!let colName=tables.find(@schemaName,@tableName)!!
				!!loop 0;tables.cnt();!!
					!!let orgValStr=""!!
					!!if valid_name(@colName)!!
						!!let orgValStr=get_string(@colName)!!
					!!endif!!
					!!if !strcmp(@orgValStr,"")!!
						!!if (!strcmp(tables.notnull(),"yes")) ||(!strcmp(tables.type(),"EnumChar"))!!
							!!command printf("error:%s.t_%s.%s is null\n",@schemaName,@tableName,@colName)!!
							!!error!!
						!!else!!
							!!let orgValStr="null"!!
						!!endif!!
					!!endif!!	
					!!if (strcmp(@orgValStr,"null"))&&((!strcmp(tables.type(),"String"))||(!strcmp(tables.type(),"VString"))||(!strcmp(tables.type(),"Char"))||(!strcmp(tables.type(),"Array")))!!
						!!let valueStr=multiaddstring(3,"'",@orgValStr,"'")!!
					!!elseif (!strcmp(tables.type(),"EnumChar"))!!
						!!let valueStr=multiaddstring(3,"'",substr(@orgValStr,0,1),"'")!!
					!!else!!
						!!let valueStr=@orgValStr!!
					!!endif!!
					!!if !strcmp(@CurrColName,"")!!
						!!let CurrColName=multiaddstring(2,@CurrColName,@colName)!!
						!!let CurrValStr=multiaddstring(2,@CurrValStr,@valueStr)!!
					!!else!!
						!!let CurrColName=multiaddstring(3,@CurrColName,",",@colName)!!
						!!let CurrValStr=multiaddstring(3,@CurrValStr,",",@valueStr)!!
					!!endif!!
					!!let colName=tables.findNext(@schemaName,@tableName)!!
				!!endloop!!
	insert into !!@schemaName!!.t_!!@tableName!! (!!@CurrColName!!) values (!!@CurrValStr!!);
			!!endif!!
			!!**–ﬁ∏ƒ”Ôæ‰!!
			!!if !strcmp(@action,"update")!!
				!!let upColName=""!!
				!!let upValName=""!!
				!!let whereStr=""!!
				!!let colName=tables.find(@schemaName,@tableName)!!
				!!loop 0;tables.cnt();!!
					!!let orgValStr=""!!
					!!if valid_name(@colName)!!
						!!let orgValStr=get_string(@colName)!!
					!!endif!!
					!!if !strcmp(@orgValStr,"")!!
						!!if (!strcmp(tables.notnull(),"yes")) ||(!strcmp(tables.type(),"EnumChar"))!!
							!!command printf("error:%s.t_%s.%s is null\n",@schemaName,@tableName,@colName)!!
							!!error!!
						!!else!!
							!!let orgValStr="null"!!
						!!endif!!
					!!endif!!	
					!!if (strcmp(@orgValStr,"null"))&&((!strcmp(tables.type(),"String"))||(!strcmp(tables.type(),"VString"))||(!strcmp(tables.type(),"Char"))||(!strcmp(tables.type(),"Array")))!!
						!!let valueStr=multiaddstring(3,"'",@orgValStr,"'")!!
					!!elseif (!strcmp(tables.type(),"EnumChar"))!!
						!!let valueStr=multiaddstring(3,"'",substr(@orgValStr,0,1),"'")!!
					!!else!!
						!!let valueStr=@orgValStr!!
					!!endif!!
					!!if !strcmp(@upColName,"")!!
						!!let upColName=multiaddstring(2,@upColName,@colName)!!
					!!else!!
						!!let upColName=multiaddstring(3,@upColName,",",@colName)!!
					!!endif!!
					!!if !strcmp(@upValName,"")!!
						!!let upValName=multiaddstring(2,@upValName,@valueStr)!!
					!!else!!
						!!let upValName=multiaddstring(3,@upValName,",",@valueStr)!!
					!!endif!!
					!!if !strcmp(tables.iskey(),"yes")!!
						!!if !strcmp(@whereStr,"")!!
							!!let whereStr=multiaddstring(4,@whereStr,@colName,"=",@valueStr)!!
						!!else!!
							!!let whereStr=multiaddstring(5,@whereStr," and ",@colName,"=",@valueStr)!!
						!!endif!!
					!!endif!!
					!!let colName=tables.findNext(@schemaName,@tableName)!!
				!!endloop!!
	update !!@schemaName!!.t_!!@tableName!!  set(!!@upColName!!)=(!!@upValName!!) where (!!@whereStr!!);
			!!endif!!
			!!**…æ≥˝”Ôæ‰!!
			!!if !strcmp(@action,"delete")!!
				!!let whereStr=""!!
				!!let colName=tables.find(@schemaName,@tableName)!!
				!!loop 0;tables.cnt();!!
					!!let orgValStr=""!!
					!!if valid_name(@colName)!!
						!!let orgValStr=get_string(@colName)!!
					!!endif!!
					!!if !strcmp(@orgValStr,"")!!
						!!if (!strcmp(tables.notnull(),"yes")) ||(!strcmp(tables.type(),"EnumChar"))!!
							!!command printf("error:%s.t_%s.%s is null\n",@schemaName,@tableName,@colName)!!
							!!error!!
						!!else!!
							!!let orgValStr="null"!!
						!!endif!!
					!!endif!!	
					!!if (strcmp(@orgValStr,"null"))&&((!strcmp(tables.type(),"String"))||(!strcmp(tables.type(),"VString"))||(!strcmp(tables.type(),"Char"))||(!strcmp(tables.type(),"Array")))!!
						!!let valueStr=multiaddstring(3,"'",@orgValStr,"'")!!
					!!elseif (!strcmp(tables.type(),"EnumChar"))!!
						!!let valueStr=multiaddstring(3,"'",substr(@orgValStr,0,1),"'")!!
					!!else!!
						!!let valueStr=@orgValStr!!
					!!endif!!
					!!if !strcmp(tables.iskey(),"yes")!!
						!!if !strcmp(@whereStr,"")!!
							!!let whereStr=multiaddstring(4,@whereStr,@colName,"=",@valueStr)!!
						!!else!!
							!!let whereStr=multiaddstring(5,@whereStr," and ",@colName,"=",@valueStr)!!
						!!endif!!
					!!endif!!
					!!let colName=tables.findNext(@schemaName,@tableName)!!
				!!endloop!!
	delete from !!@schemaName!!.t_!!@tableName!! where !!@whereStr!!;
			!!endif!!
		!!next!!
	!!else!!
	!!if valid_name("comment")!!
	--!!@name!!: !!@comment!!
	!!else!!
	--!!@name!!
	!!endif!!
		!!travel self!!
		!!if valid_name("comment")!!
		--!!@name!!: !!@comment!!
		!!else!!
		--!!@name!!
		!!endif!!
		!!next!!
	!!endif!!
	
	!!next!!
!!leave!!
