name,type,label,length,decimal,description
!!travel UFDataTypes!!
!!if !strcmp(@name,"Char")!!
!!@typename!!,!!@name!!,!!@label!!,1,0,
!!elseif !strcmp(@name,"String")!!
!!@typename!!,!!@name!!,!!@label!!,!!@length!!,0,
!!elseif !strcmp(@name,"Int")!!
!!@typename!!,!!@name!!,!!@label!!,!!@length!!,0,
!!elseif !strcmp(@name,"Float")!!
!!@typename!!,!!@name!!,!!@label!!,!!@length!!,!!@precision!!,
!!elseif !strcmp(@name,"Word")!!
!!@typename!!,!!@name!!,!!@label!!,2,0,
!!elseif !strcmp(@name,"EnumChar")!!
!!@typename!!,!!@name!!,!!@label!!,1,0,!!travel self!!!!@value!!:!!@label!! !!next!!
!!elseif !strcmp(@name,"RangeInt")!!
!!@typename!!,!!@name!!,!!@label!!,!!@length!!,0,!!@from!!..!!@to!!
!!elseif !strcmp(@name,"VString")!!
!!@typename!!,!!@name!!,!!@label!!,!!@length!!,0,
!!elseif !strcmp(@name,"Array")!!
!!@typename!!,!!@name!!,!!@label!!,!!@length!!,0,!!@element!!
!!endif!!
!!next!!
