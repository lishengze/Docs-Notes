!!enter OFP!!
"packageName","vary","command","packageComment","v1use","v2use","fieldName","type","length","fieldComment"
!!travel packages!!
	!!let packageName=@name!!
	!!let packageComment=@comment!!
	!!let packageInit="yes"!!
	!!travel self!!
		!!if !strcmp(@type,"String")!!
			!!let typeLength=@length!!
		!!elseif !strcmp(@type,"Number")!!
			!!let typeLength=@length!!
		!!elseif !strcmp(@type,"Char")!!
			!!let typeLength="1"!!
		!!elseif !strcmp(@type,"Float")!!
			!!let typeLength="15"!!
		!!else!!
			!!let typeLength="1"!!
		!!endif!!
!!if !strcmp(@packageInit,"yes")!!"!!@packageName!!","!!@vary!!","!!@comm!!","!!@packageComment!!","!!@v1use!!","!!@v2use!!"!!else!!,,,,,!!endif!!,"!!@name!!","!!@type!!","!!@typeLength!!","!!@comment!!"
		!!let packageInit="no"!!
	!!next!!
!!next!!
!!leave!!
