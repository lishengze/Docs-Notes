!!include DataTypeDefine.tpl!!
!!enter XTP!!
<?xml version="1.0" encoding="GB2312"?>
<!ELEMENT XTPPackages (
	!!travel packages!!!!if @pumpid!=0!!|!!endif!!!!@name!!Package
	!!next!!)*>
!!travel packages!!
<!ELEMENT !!@name!!Package (!!travel self!!!!if @pumpid!=0!!|!!endif!!!!@name!!Field!!next!!)*>
<!ATTLIST !!@name!!Package
	tid (!!@tid!!) #REQUIRED
	comment (!!@comment!!) #REQUIRED
	frontid CDATA #REQUIRED
	sessionid CDATA #REQUIRED
>
!!next!!
!!travel fields!!
<!ELEMENT !!@name!!Field EMPTY>
<!ATTLIST !!@name!!Field
	fid (!!@fid!!) #REQUIRED
	comment (!!@comment!!) #REQUIRED
	!!travel self!!
	!!@name!! !!show_string typeDefines.find(@type)!! #REQUIRED
	!!next!!
>
!!next!!
!!leave!!