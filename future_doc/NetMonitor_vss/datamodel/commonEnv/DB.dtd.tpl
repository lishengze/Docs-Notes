!!include DataTypeDefine.tpl!!
!!enter DB!!
<?xml version="1.0" encoding="GB2312"?>
<!ELEMENT Database (!!travel schemas!!!!if @pumpid!=0!!,!!endif!!Schema_!!@name!!!!next!!)>
!!travel schemas!!
<!ELEMENT Schema_!!@name!! (!!travel self!!!!if @pumpid!=0!!,!!endif!!TG_!!@name!!!!next!!)>
!!next!!
!!travel tableGroups!!
<!ELEMENT TG_!!@group!! (!!travel self!!!!if @pumpid!=0!!|!!endif!!!!@name!!!!next!!)*>
!!travel self!!
<!ELEMENT !!@name!! EMPTY>
<!ATTLIST !!@name!!
	!!travel Columns!!
	!!@name!! !!show_string typeDefines.find(@originaltype)!! #REQUIRED
	!!next!!
>
!!next!!
!!next!!
!!leave!!