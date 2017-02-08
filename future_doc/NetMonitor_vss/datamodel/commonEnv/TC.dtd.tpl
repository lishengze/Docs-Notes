!!include DataTypeDefine.tpl!!
<?xml version="1.0" encoding="GB2312"?>
!!enter DB!!
!!let DBList=""!!
!!let CheckDBList=""!!
!!travel schemas!!
	!!let DBList=multiaddstring(4,@DBList,"DB_",@name,"|")!!
	!!let CheckDBList=multiaddstring(4,@CheckDBList,"CheckDB_",@name,"|")!!
!!next!!
!!leave!!
<!ELEMENT DataPrepare (!!@DBList!!Operation|Manual|Wait|Comment)*>
<!ATTLIST DataPrepare
	ID CDATA #REQUIRED
	Name CDATA #REQUIRED
	Comment CDATA #REQUIRED
>
<!ELEMENT Execution (!!@DBList!!!!@CheckDBList!!Operation|CheckResponse|CheckNotify|Manual|ManualCheck|Wait|Comment)*>
<!ATTLIST Execution
	ID CDATA #REQUIRED
	Name CDATA #REQUIRED
	DataPrepare CDATA #REQUIRED
	Comment CDATA #REQUIRED
>
!!enter DB!!
!!travel schemas!!

!!let schemaName=@name!!
!!let tableList=""!!
!!travel self!!
!!let groupName=@name!!
!!enter DB!!
!!travel tableGroups!!
!!if !strcmp(@groupName,@group)!!
!!travel self!!
	!!let tableList=multiaddstring(5,@tableList,"|",@schemaName,".",@name)!!
<!ELEMENT !!@schemaName!!.!!@name!! EMPTY>
<!ATTLIST !!@schemaName!!.!!@name!!
	action (insert|update|delete) #REQUIRED
	comment CDATA #REQUIRED
	!!travel Columns!!
	!!@name!! !!show_string typeDefines.find(@originaltype)!! #REQUIRED
	!!next!!
>
!!next!!
!!endif!!
!!next!!
!!leave!!
!!next!!
!!let tableList=@tableList+1!!
<!ELEMENT DB_!!@name!! (!!@tableList!!)*>
<!ELEMENT CheckDB_!!@name!! (!!@tableList!!)*>

!!next!!
!!++!!
!!travel tableGroups!!
<!ELEMENT TG_!!@group!! (!!travel self!!!!if @pumpid!=0!!|!!endif!!!!@group!!.!!@name!!!!next!!)*>
!!travel self!!
<!ELEMENT !!@group!!.!!@name!! EMPTY>
<!ATTLIST !!@group!!.!!@name!!
	action (insert|update|delete) #REQUIRED
	comment CDATA #REQUIRED
	!!travel Columns!!
	!!@name!! !!show_string typeDefines.find(@originaltype)!! #REQUIRED
	!!next!!
>
!!next!!
!!next!!
!!--!!
!!leave!!
!!enter FTD!!
!!let operationlist=""!!
!!let responselist=""!!
!!let notifylist=""!!
!!travel packages!!
	!!if !strncmp(@name,"Req",3)!!
		!!let operationlist=multiaddstring(4,@operationlist,"|",@name,"Package")!!
	!!elseif !strncmp(@name,"Rsp",3)!!
		!!let responselist=multiaddstring(4,@responselist,"|",@name,"Package")!!
	!!elseif !strncmp(@name,"Rtn",3)!!
		!!let notifylist=multiaddstring(4,@notifylist,"|",@name,"Package")!!
	!!endif!!
!!next!!
!!let operationlist=@operationlist+1!!
!!let responselist=@responselist+1!!
!!let notifylist=@notifylist+1!!
<!ELEMENT Operation (!!@operationlist!!)*>
<!ELEMENT CheckResponse (!!@responselist!!)*>
<!ELEMENT CheckNotify (!!@notifylist!!)*>
!!travel packages!!
<!ELEMENT !!@name!!Package (!!travel self!!!!if @pumpid!=0!!|!!endif!!!!@name!!Field!!next!!)*>
<!ATTLIST !!@name!!Package
	packagecomment (!!@comment!!) #IMPLIED
	comment CDATA #REQUIRED
	sessionid CDATA #REQUIRED
>
!!next!!
!!travel fields!!
<!ELEMENT !!@name!!Field EMPTY>
<!ATTLIST !!@name!!Field
	fieldcomment (!!@comment!!) #IMPLIED
	comment CDATA #REQUIRED
	!!travel self!!
	!!@name!! !!show_string typeDefines.find(@type)!! #REQUIRED
	!!next!!
>
!!next!!
!!leave!!
<!ELEMENT Wait EMPTY>
<!ATTLIST Wait
	time CDATA #REQUIRED
	comment CDATA #REQUIRED
>
<!ELEMENT Comment EMPTY>
<!ATTLIST Comment
	comment CDATA #REQUIRED
>
<!ELEMENT Manual EMPTY>
<!ATTLIST Manual
	operation CDATA #REQUIRED
	comment CDATA #REQUIRED
>
<!ELEMENT ManualCheck EMPTY>
<!ATTLIST ManualCheck
	check CDATA #REQUIRED
	comment CDATA #REQUIRED
>
