!!include function.tpl!!
!!enter system!!
/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseFactories.pp
///@briefʵ�������ɸ��ڴ����ݿ�Ķ��󹤳�
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "databaseResources.h"
#include "monitorIndex.h"

//#define COUNT_SEARCH
!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!command resetEntityMap();!!
!!travel fields!!
!!command addEntity(@name,@type)!!
!!next!!
!!let tableName=@name!!
!!travel index!!
int compareFor!!@name!!in!!@tableName!!(const void *pV1, const void *pV2)
{
	C!!@tableName!! *p1,*p2;
	p1=(C!!@tableName!! *)pV1;
	p2=(C!!@tableName!! *)pV2;
	!!if atoi(@son_size)==0!!
		!!error printf("index %s in table %s has no items\n",@name,@tableName)!!
	!!endif!!
	!!travel self!!
	switch (compare(p1->!!@name!!.getValue(),p2->!!@name!!.getValue()))
	{
	!!if !strcmp(@isAsc,"yes")!!
	case 1:
		return 1;
	case -1:
		return -1;
	!!else!!
	case 1:
		return -1;
	case -1:
		return 1;
	!!endif!!
	case 0:
	default:
		break;
	}
	!!next!!
	return 0;
}
!!next!!
!!travel search!!

!!if (!strcmp(@searchUnique,"yes"))!!
#ifdef COUNT_SEARCH
int find!!@name!!For!!@tableName!!=0;
#endif
C!!@tableName!! *C!!@tableName!!Factory::find!!@name!!(!!travel parameter!!!!if (@pumpid!=0)!!, !!endif!! const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!&  !!@name!!!!next!!)
{
	if (runLevel<!!@runLevel!!)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use find!!@name!! of C!!@tableName!! while run level < !!@runLevel!!");
	}
!!if strcmp(@indexName,"noIndex")!!
#ifdef COUNT_SEARCH
	find!!@name!!For!!@tableName!!++;
#endif
	CAVLNode *pNode;
	!!travel parameter!!
	compareObject.!!@name!!=!!@name!!.getValue();
	!!next!!
	!!travel default!!
	compareObject.!!@name!!=!!@value!!;
	!!next!!
	!!let hasNoCheck="no"!!
	!!travel parameter!!
	!!if strcmp(@checkParameter,"yes")!!
		!!let hasNoCheck="yes"!!
	!!endif!!
	!!next!!
	!!travel default!!
	!!if strcmp(@checkDefault,"yes")!!
		!!let hasNoCheck="yes"!!
	!!endif!!
	!!next!!
	!!if !strcmp(@hasNoCheck,"no")!!	
	pNode=p!!@indexName!!->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	!!else!!
	pNode=p!!@indexName!!->searchFirstGreatEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	!!travel parameter!!
	!!if !strcmp(@checkParameter,"yes")!!
	if (compare(((C!!@tableName!! *)(pNode->pObject))->!!@name!!.getValue(),!!@name!!.getValue())!=0)
	{
		return NULL;
	}
	!!endif!!
	!!next!!
	!!travel default!!
	!!if !strcmp(@checkDefault,"yes")!!
	if (compare(((C!!@tableName!! *)(pNode->pObject))->!!@name!!.getValue(),!!@value!!)!=0)
	{
		return NULL;
	}
	!!endif!!
	!!next!!
	!!endif!!
	return (C!!@tableName!! *)(pNode->pObject);
!!elseif valid_name("hashIndexName")!!
	CHashIndexNode *pNode;
	!!travel parameter!!
	compareObject.!!@name!!=!!@name!!.getValue();
	!!next!!
	!!travel default!!
	compareObject.!!@name!!=!!@value!!;
	!!next!!
	
	!!let thisHashIndexName=@hashIndexName!!
	!!enter tables!!
		!!enter_expr @tableName!!
			!!enter hashindex!!
				!!enter_expr @thisHashIndexName!!
					!!let thisHashKey=@hashKey!!
				!!leave!!
			!!leave!!
		!!leave!!
	!!leave!!
	compareObject.calHash!!@thisHashKey!!();
	for (pNode=p!!@hashIndexName!!->searchFirstEqual(compareObject.Hash!!@thisHashKey!!);
		pNode!=NULL;
		pNode=p!!@hashIndexName!!->searchNextEqual(pNode))
	{
		if (((C!!@tableName!! *)(pNode->pObject))->Hash!!@thisHashKey!! != compareObject.Hash!!@thisHashKey!!)
		{
			continue;
		}
		!!travel parameter!!
		!!if !strcmp(@checkParameter,"yes")!!
		if (compare(((C!!@tableName!! *)(pNode->pObject))->!!@name!!.getValue(),!!@name!!.getValue())!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		!!travel default!!
		!!if !strcmp(@checkDefault,"yes")!!
		if (compare(((C!!@tableName!! *)(pNode->pObject))->!!@name!!.getValue(),!!@value!!)!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		return (C!!@tableName!! *)(pNode->pObject);
	}
	return NULL;
!!else!!
	C!!@tableName!! *the!!@tableName!!;
	for (the!!@tableName!!=(C!!@tableName!! *)(pMem->getFirst());
		the!!@tableName!!!=NULL;
		the!!@tableName!!=(C!!@tableName!! *)(pMem->getNext()))
	{
		!!travel parameter!!
		!!if !strcmp(@checkParameter,"yes")!!
		if (compare(the!!@tableName!!->!!@name!!.getValue(),!!@name!!.getValue())!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		!!travel default!!
		!!if !strcmp(@checkDefault,"yes")!!
		if (compare(the!!@tableName!!->!!@name!!.getValue(),!!@value!!)!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		return the!!@tableName!!;
	}
	return NULL;
!!endif!!
}

!!if !strcmp(@isPK,"yes")!!
C!!@tableName!! *C!!@tableName!!Factory::findByPK(!!travel parameter!!!!if (@pumpid!=0)!!, !!endif!! const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!&  !!@name!!!!next!!)
{
	return find!!@name!!(!!travel parameter!!!!if (@pumpid!=0)!!, !!endif!!!!@name!!!!next!!);
}
	
C!!@tableName!! *C!!@tableName!!Factory::findByPK(CWriteable!!@tableName!! *p!!@tableName!!)
{
	return findByPK(
		!!travel parameter!!
		!!if @pumpid!=0!!
		,
		!!endif!!
		p!!@tableName!!->!!@name!!
		!!next!!
		);
}

bool C!!@tableName!!Factory::retrieveByPK(CWriteable!!@tableName!! *p!!@tableName!!)
{
	C!!@tableName!! *pOriginal!!@tableName!!;
	pOriginal!!@tableName!!=findByPK(p!!@tableName!!);
	if (pOriginal!!@tableName!!==NULL)
	{
		return false;
	}
	retrieve(pOriginal!!@tableName!!,p!!@tableName!!);
	return true;
}

C!!@tableName!! *C!!@tableName!!Factory::addByPK(CWriteable!!@tableName!! *p!!@tableName!!, CTransaction *pTransaction)
{
	C!!@tableName!! *pOriginal!!@tableName!!;
	pOriginal!!@tableName!!=findByPK(p!!@tableName!!);
	if (pOriginal!!@tableName!! != NULL)
	{
		return NULL;
	}
	return add(p!!@tableName!!,pTransaction);
}

bool C!!@tableName!!Factory::updateByPK(CWriteable!!@tableName!! *p!!@tableName!!, CTransaction *pTransaction, bool updateIndex)
{
	C!!@tableName!! *pOriginal!!@tableName!!;
	pOriginal!!@tableName!!=findByPK(p!!@tableName!!);
	if (pOriginal!!@tableName!!==NULL)
	{
		return false;
	}
	p!!@tableName!!->calAllHash();
	update(pOriginal!!@tableName!!,p!!@tableName!!,pTransaction,updateIndex);
	return true;
}

bool C!!@tableName!!Factory::removeByPK(CWriteable!!@tableName!! *p!!@tableName!!, CTransaction *pTransaction)
{
	C!!@tableName!! *pOriginal!!@tableName!!;
	pOriginal!!@tableName!!=findByPK(p!!@tableName!!);
	if (pOriginal!!@tableName!!==NULL)
	{
		return false;
	}
	remove(pOriginal!!@tableName!!,pTransaction);
	return true;
}

!!endif!!

!!else!!
#ifdef COUNT_SEARCH
int multiFind!!@name!!For!!@tableName!!=0;
#endif

C!!@tableName!! *C!!@tableName!!Factory::startFind!!@name!!(!!travel parameter!!!!if (@pumpid!=0)!!, !!endif!! const !!command getReadOnlyEntityTypeName(@name);!!!!show_string (char *)strResult.c_str()!!& !!@name!!!!next!!)
{
	if (runLevel<!!@runLevel!!)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFind!!@name!! of C!!@tableName!! while run level < !!@runLevel!!");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearch!!@name!!!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFind!!@name!!();
	}

	///��¼���еĲ�ѯֵ
	!!let searchName=@name!!
	!!travel parameter!!
	query!!@name!!InSearch!!@searchName!!= !!@name!!.getValue();
	!!next!!

!!if strcmp(@indexName,"noIndex")!!
#ifdef COUNT_SEARCH
	multiFind!!@name!!For!!@tableName!!++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	C!!@tableName!! *the!!@tableName!!;
	!!travel parameter!!
	compareObject.!!@name!!=!!@name!!.getValue();
	!!next!!
	!!travel default!!
	compareObject.!!@name!!=!!@value!!;
	!!next!!
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearch!!@name!!=p!!@indexName!!->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearch!!@name!!==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	the!!@tableName!!=(C!!@tableName!! *)(pLastFoundInSearch!!@name!!->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	!!travel parameter!!
	!!if !strcmp(@checkParameter,"yes")!!
	if (compare(the!!@tableName!!->!!@name!!.getValue(),!!@name!!.getValue()))
	{
		pLastFoundInSearch!!@searchName!!=NULL;
		return NULL;
	}
	!!endif!!
	!!next!!
	!!travel default!!
	!!if !strcmp(@checkDefault,"yes")!!
	if (compare(the!!@tableName!!->!!@name!!,!!@value!!))
	{
		pLastFoundInSearch!!@searchName!!=NULL;
		return NULL;
	}
	!!endif!!
	!!next!!

	///�����ҵ��Ľ��
	return the!!@tableName!!;
!!elseif valid_name("hashIndexName")!!
	C!!@tableName!! *the!!@tableName!!;
	!!travel parameter!!
	compareObject.!!@name!!=!!@name!!.getValue();
	!!next!!
	!!travel default!!
	compareObject.!!@name!!=!!@value!!;
	!!next!!
	
	!!let thisHashIndexName=@hashIndexName!!
	!!enter tables!!
		!!enter_expr @tableName!!
			!!enter hashindex!!
				!!enter_expr @thisHashIndexName!!
					!!let thisHashKey=@hashKey!!
				!!leave!!
			!!leave!!
		!!leave!!
	!!leave!!
	compareObject.calHash!!@thisHashKey!!();

	
	for (pLastFoundInSearch!!@name!!=p!!@hashIndexName!!->searchFirstEqual(compareObject.Hash!!@thisHashKey!!);
		pLastFoundInSearch!!@name!! !=NULL;
		pLastFoundInSearch!!@name!!=p!!@hashIndexName!!->searchNextEqual(pLastFoundInSearch!!@name!!))
	{
		the!!@tableName!!=(C!!@tableName!! *)(pLastFoundInSearch!!@name!!->pObject);
		if (the!!@tableName!!->Hash!!@thisHashKey!! != compareObject.Hash!!@thisHashKey!!)
		{
			continue;
		}
		!!travel parameter!!
		!!if !strcmp(@checkParameter,"yes")!!
		if (compare(the!!@tableName!!->!!@name!!.getValue(),!!@name!!.getValue())!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		!!travel default!!
		!!if !strcmp(@checkDefault,"yes")!!
		if (compare(the!!@tableName!!->!!@name!!.getValue(),!!@value!!)!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		return the!!@tableName!!;
	}
	return NULL;
!!else!!
	///���һ������Ҳû�У��ͷ���ʧ��
	pLastFoundInSearch!!@name!!=(C!!@tableName!! *)(pMem->getFirst());
	
	if (pLastFoundInSearch!!@name!!==NULL)
	{
		return NULL;
	}
	
	///�����һ������ȷ����ʹ��findNext!!@searchName!!��Ѱ����һ��
	!!travel parameter!!
	!!if !strcmp(@checkParameter,"yes")!!
	if (compare(pLastFoundInSearch!!@searchName!!->!!@name!!.getValue(),!!@name!!.getValue()))
	{
		return findNext!!@searchName!!();
	}
	!!endif!!
	!!next!!
	!!travel default!!
	!!if !strcmp(@checkDefault,"yes")!!
	if (compare(pLastFoundInSearch!!@searchName!!->!!@name!!,!!@value!!))
	{
		return findNext!!@searchName!!();
	}
	!!endif!!
	!!next!!
	
	///�����ҵ��Ľ��
	return pLastFoundInSearch!!@name!!;
!!endif!!
}

C!!@tableName!! *C!!@tableName!!Factory::findNext!!@name!!(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearch!!@name!!==NULL)
	{
		return NULL;
	}

!!if strcmp(@indexName,"noIndex")!!
#ifdef COUNT_SEARCH
	multiFind!!@name!!For!!@tableName!!++;
#endif
	C!!@tableName!! *the!!@tableName!!;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearch!!@name!!=p!!@indexName!!->getNextNode(pLastFoundInSearch!!@name!!);
	if (pLastFoundInSearch!!@name!!==NULL)
	{
		return NULL;
	}

	the!!@tableName!!=(C!!@tableName!! *)(pLastFoundInSearch!!@name!!->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	!!travel parameter!!
	!!if !strcmp(@checkParameter,"yes")!!
	if (compare(the!!@tableName!!->!!@name!!,query!!@name!!InSearch!!@searchName!!))
	{
		pLastFoundInSearch!!@searchName!!=NULL;
		return NULL;
	}
	!!endif!!
	!!next!!
	!!travel default!!
	!!if !strcmp(@checkDefault,"yes")!!
	if (compare(the!!@tableName!!->!!@name!!,!!@value!!))
	{
		pLastFoundInSearch!!@searchName!!=NULL;
		return NULL;
	}
	!!endif!!
	!!next!!

	///�����ҵ��Ľ��
	return the!!@tableName!!;
!!elseif valid_name("hashIndexName")!!
	C!!@tableName!! *the!!@tableName!!;
	
	!!let thisHashIndexName=@hashIndexName!!
	!!enter tables!!
		!!enter_expr @tableName!!
			!!enter hashindex!!
				!!enter_expr @thisHashIndexName!!
					!!let thisHashKey=@hashKey!!
				!!leave!!
			!!leave!!
		!!leave!!
	!!leave!!

	
	for (;;)
	{
		pLastFoundInSearch!!@name!!=p!!@hashIndexName!!->searchNextEqual(pLastFoundInSearch!!@name!!);
		if (pLastFoundInSearch!!@name!!==NULL)
		{
			return NULL;
		}
		the!!@tableName!!=(C!!@tableName!! *)(pLastFoundInSearch!!@name!!->pObject);
		if (the!!@tableName!!->Hash!!@thisHashKey!! != compareObject.Hash!!@thisHashKey!!)
		{
			continue;
		}
		!!travel parameter!!
		!!if !strcmp(@checkParameter,"yes")!!
		if (compare(the!!@tableName!!->!!@name!!.getValue(),compareObject.!!@name!!.getValue())!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		!!travel default!!
		!!if !strcmp(@checkDefault,"yes")!!
		if (compare(the!!@tableName!!->!!@name!!.getValue(),compareObject.!!@value!!)!=0)
		{
			continue;
		}
		!!endif!!
		!!next!!
		return the!!@tableName!!;
	}
	return NULL;
!!else!!
	///��������Ѱ��
	for (;;)
	{
		///����Ѿ�û����һ���ˣ���ʧ�ܷ���
		pLastFoundInSearch!!@name!!=(C!!@tableName!! *)(pMem->getNext());
		if (pLastFoundInSearch!!@name!!==NULL)
		{
			return NULL;
		}

		///���һ�����������㣬������һ��
		!!travel parameter!!
		!!if !strcmp(@checkParameter,"yes")!!
		if (compare(pLastFoundInSearch!!@searchName!!->!!@name!!,query!!@name!!InSearch!!@searchName!!))
		{
			continue;
		}
		!!endif!!
		!!next!!
		!!travel default!!
		!!if !strcmp(@checkDefault,"yes")!!
		if (compare(pLastFoundInSearch!!@searchName!!->!!@name!!,!!@value!!))
		{
			continue;
		}
		!!endif!!
		!!next!!
		///�����ҵ��Ľ��
		return pLastFoundInSearch!!@searchName!!;
	}
!!endif!!
}

void C!!@tableName!!Factory::endFind!!@name!!(void)
{
	pLastFoundInSearch!!@name!!=NULL;
}

!!endif!!
!!next!!
!!endif!!
!!next!!
#ifdef COUNT_SEARCH
void showAllSearchCount(void)
{
	printf("\n");
!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!let tableName=@name!!
!!travel search!!
!!if (!strcmp(@searchUnique,"yes"))!!
	if (find!!@name!!For!!@tableName!! !=0)
	{
		printf("\tfind!!@name!!For!!@tableName!!:%d\n",find!!@name!!For!!@tableName!!);
	}
!!else!!
	if (multiFind!!@name!!For!!@tableName!! !=0)
	{
		printf("\tmultiFind!!@name!!For!!@tableName!!:%d\n",multiFind!!@name!!For!!@tableName!!);
	}
!!endif!!
!!next!!
!!endif!!
!!next!!
}

void initAllSearchCount(void)
{
!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
!!let tableName=@name!!
!!travel search!!
!!if (!strcmp(@searchUnique,"yes"))!!
	find!!@name!!For!!@tableName!!=0;
!!else!!
	multiFind!!@name!!For!!@tableName!!=0;
!!endif!!
!!next!!
!!endif!!
!!next!!
}
#endif
!!leave!!
