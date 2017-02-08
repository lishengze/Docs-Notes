!!include setCommand.tpl!!
"schema","group","table","field","type","label","iskey","isnull","originaltype","basetype","length","precision"
!!enter DB!!
!!travel schemas!!
	!!let schemaName=@name!!
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
"!!@schemaName!!","!!@groupName!!","t_!!@tableName!!","!!@name!!","!!@type!!","!!@label!!","!!@keyValue!!","!!@isnull!!","!!@originaltype!!","!!@basetype!!","!!@length!!","!!@precision!!"
						!!next!!
					!!next!!
				!!endif!!
			!!next!!
		!!leave!!
	!!next!!
!!next!!
!!leave!!
