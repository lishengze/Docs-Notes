<?xml version="1.0" encoding="gb2312"?>
<!-- edited with pump(UFDataType.xml) by wang.xiping -->

!!enter UFDataTypes!!
!!travel self!!
!!if !strcmp(@name,"EnumChar") !!
<EnumChar name="!!@typename!!" label="!!@label!!">
!!travel self!!
  <enum name="!!@name!!" value="!!@value!!" label="!!@label!!"/>
!!next!!
</EnumChar>
!!endif!!
!!next!!
!!leave!!
