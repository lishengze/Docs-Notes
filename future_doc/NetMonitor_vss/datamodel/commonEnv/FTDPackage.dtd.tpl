!!enter FTD!!
<?xml version="1.0" encoding="GB2312"?>
<!ELEMENT FTDPackages (!!travel packages!!!!if @pumpid!=0!!|!!endif!!!!@name!!Package!!next!!)*>
!!travel packages!!
<!ELEMENT !!@name!!Package (!!travel self!!!!if @pumpid!=0!!|!!endif!!!!@name!!Field!!next!!)*>
<!ATTLIST !!@name!!Package
	tid (!!@tid!!) #REQUIRED
	comment (!!@comment!!) #REQUIRED
	date CDATA #REQUIRED
	time CDATA #REQUIRED
	millisec CDATA #REQUIRED
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
	!!@name!! CDATA #REQUIRED
	!!next!!
>
!!next!!
!!leave!!
