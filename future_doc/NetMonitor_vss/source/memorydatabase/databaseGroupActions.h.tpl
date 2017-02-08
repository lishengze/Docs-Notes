!!include function.tpl!!
!!enter system!!
/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseGroupActions.h
///@brief���������ɸ��ڴ����ݿ��Ⱥ�����
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEGROUPACTIONS_H
#define DATABASEGROUPACTIONS_H

#include "BaseDataStruct.h"
#include "databaseFactories.h"

!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!command resetEntityMap();!!
!!travel fields!!
!!command addEntity(@name,@type)!!
!!next!!

///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* T!!@name!!ActionFunc)(C!!@name!! * p!!@name!!, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* T!!@name!!UpdateFunc)(CWriteable!!@name!! * p!!@name!!, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* T!!@name!!SelectFunc)(C!!@name!! * p!!@name!!,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(C!!@name!!Iterator *pIterator, T!!@name!!ActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(C!!@name!!Iterator *pIterator, T!!@name!!UpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(C!!@name!!Iterator *pIterator, T!!@name!!SelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

!!endif!!
!!next!!
#endif
!!leave!!
