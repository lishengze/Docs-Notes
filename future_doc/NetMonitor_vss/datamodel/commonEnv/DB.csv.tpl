!!include setCommand.tpl!!
"schema","table","field","type","label","iskey","isnull"
!!enter DB!!
!!travel schemas!!
	!!let schemaName=@name!!
	!!let schemaInit="yes"!!
	!!travel self!!
		!!let groupName=@name!!
			!!let groupName=@name!!
			!!command startSetCommand();!!
			!!travel self!!
				!!command addSetCommand();!!
			!!next!!
		!!enter DB!!
			!!travel tableGroups!!
				!!if !strcmp(@group,@groupName)!!
					!!travel self!!
						!!let tableName=@name!!
						!!let tableInit="yes"!!
						!!travel Columns!!
							!!if isNotNull(@tableName)!!
								!!let isnull="T"!!
							!!else!!
								!!let isnull="F"!!
							!!endif!!
							!!if isKey(@tableName)!!
								!!let keyValue="T"!!
							!!else!!
								!!let keyValue="F"!!
							!!endif!!
!!if !strcmp(@schemaInit,"yes")!!"!!@schemaName!!"!!endif!!,!!if !strcmp(@tableInit,"yes")!!"t_!!@tableName!!"!!endif!!,"!!@name!!","!!@originaltype!!","!!@label!!","!!@keyValue!!","!!@isnull!!"
							!!let schemaInit="no"!!
							!!let tableInit="no"!!
						!!next!!
					!!next!!
				!!endif!!
			!!next!!
		!!leave!!
	!!next!!
!!next!!
!!leave!!
