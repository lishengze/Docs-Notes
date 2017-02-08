!!enter FTD!!
"fieldName","fid","comment","itemName","type","description"
!!travel fields!!
	!!let fieldName=@name!!
	!!let fieldInit="yes"!!
	!!travel self!!
!!if !strcmp(@fieldInit,"yes")!!"!!@fieldName!!","!!@fid!!","!!@comment!!"!!else!!,,!!endif!!,"!!@name!!","!!@type!!","!!@description!!"
		!!let fieldInit="no"!!
	!!next!!
!!next!!
!!leave!!
