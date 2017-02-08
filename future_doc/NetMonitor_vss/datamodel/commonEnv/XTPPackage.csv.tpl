!!enter XTP!!
"packageName","tid","comment","fieldName"
!!travel packages!!
	!!let packageName=@name!!
	!!let packageInit="yes"!!
	!!travel self!!
!!if !strcmp(@packageInit,"yes")!!"!!@packageName!!","!!@tid!!","!!@comment!!"!!else!!,,!!endif!!,!!@name!!
		!!let packageInit="no"!!
	!!next!!
!!next!!
!!leave!!
