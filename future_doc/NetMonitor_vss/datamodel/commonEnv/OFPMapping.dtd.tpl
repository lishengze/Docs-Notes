<?xml version="1.0" encoding="gb2312"?>
!!enter OFP!!
!!let mappingList=""!!
!!travel packages!!
	!!if strcmp(@XTPPackage,"notDefined")!!
		!!let mappingList=multiaddstring(3,@mappingList,",",@name)!!
	!!endif!!
!!next!!
!!let mappingList=@mappingList+1!!
<!ELEMENT OFPMapping (!!@mappingList!!)>
!!travel packages!!
	!!if strcmp(@XTPPackage,"notDefined")!!
		!!let mappingName=@name!!
		!!if !strcmp(@isUp,"yes")!!
			!!let sourceFields=""!!
			!!travel self!!
				!!let sourceFields=multiaddstring(5,@sourceFields,"|",@name,":",@comment)!!
			!!next!!
			!!let sourceFields=@sourceFields+1!!
			!!let itemList=""!!
			!!let XTPPackageName=@XTPPackage!!
			!!enter PumpRoot!!
				!!enter XTP.packages!!
					!!enter_expr @XTPPackageName!!
						!!travel self!!
							!!let fieldName=@name!!
							!!enter XTP!!
								!!enter fields!!
									!!enter_expr @fieldName!!
										!!travel self!!
											!!let itemList=multiaddstring(9,@itemList,",",@mappingName,".",@fieldName,".",@name,":",@description)!!
<!ELEMENT !!@mappingName!!.!!@fieldName!!.!!@name!!:!!@description!! EMPTY>
<!ATTLIST !!@mappingName!!.!!@fieldName!!.!!@name!!:!!@description!!
	SourceField (!!@sourceFields!!) #IMPLIED
	Transfer CDATA #IMPLIED
	Function CDATA #IMPLIED
	Constant CDATA #IMPLIED
	Comment CDATA #IMPLIED
>
										!!next!!
									!!leave!!
								!!leave!!
							!!leave!!
						!!next!!
					!!leave!!
				!!leave!!
			!!leave!!
			!!let itemList=@itemList+1!!
<!ELEMENT !!@mappingName!! (!!@itemList!!)>
		!!else!!
			!!let sourceFields=""!!
			!!let XTPPackageName=@XTPPackage!!
			!!enter PumpRoot!!
				!!enter XTP.packages!!
					!!enter_expr @XTPPackageName!!
						!!travel self!!
							!!let fieldName=@name!!
							!!enter XTP!!
								!!enter fields!!
									!!enter_expr @fieldName!!
										!!travel self!!
											!!let sourceFields=multiaddstring(9,@sourceFields,"|",@XTPPackageName,".",@fieldName,".",@name,":",@description)!!
										!!next!!
									!!leave!!
								!!leave!!
							!!leave!!
						!!next!!
					!!leave!!
				!!leave!!
			!!leave!!
			!!if strcmp(@OFPRequest,"notDefined")!!
				!!let requestName=@OFPRequest!!
				!!enter packages!!
					!!enter_expr @requestName!!
						!!travel self!!
							!!let sourceFields=multiaddstring(7,@sourceFields,"|",@requestName,".",@name,":",@comment)!!
						!!next!!
					!!leave!!
				!!leave!!
			!!endif!!
			!!let sourceFields=@sourceFields+1!!
			!!let itemList=""!!
			!!travel self!!
				!!let itemList=multiaddstring(7,@itemList,",",@mappingName,".",@name,":",@comment)!!
<!ELEMENT !!@mappingName!!.!!@name!!:!!@comment!! EMPTY>
<!ATTLIST !!@mappingName!!.!!@name!!:!!@comment!!
	SourceField (!!@sourceFields!!) #IMPLIED
	Transfer CDATA #IMPLIED
	Function CDATA #IMPLIED
	Constant CDATA #IMPLIED
	Comment CDATA #IMPLIED
>
			!!next!!
			!!let itemList=@itemList+1!!
<!ELEMENT !!@mappingName!! (!!@itemList!!)>
		!!endif!!
	!!endif!!
!!next!!

!!leave!!
