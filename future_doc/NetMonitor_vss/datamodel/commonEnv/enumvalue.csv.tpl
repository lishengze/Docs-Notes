"type","value","id","label"
!!travel UFDataTypes!!
	!!if !strcmp(@name,"EnumChar")!!
		!!let typeName=@typename!!
		!!travel self!!
"!!@typeName!!","!!@value!!","!!@prefix!!_!!@name!!","!!@label!!"
		!!next!!
	!!endif!!
!!next!!
