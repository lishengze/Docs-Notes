"table","field","type","label"
!!enter system!!
!!travel tables!!
	!!let tableName=@name!!
	!!let tableInit="yes"!!
	!!travel fields!!
!!if !strcmp(@tableInit,"yes")!!"!!@tableName!!"!!endif!!,"!!@name!!","!!@type!!","!!@comment!!"
	!!let tableInit="no"!!
	!!next!!
!!next!!
!!leave!!
