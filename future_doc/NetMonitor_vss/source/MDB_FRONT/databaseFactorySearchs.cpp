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
int compareForSysInsertTimeIndexinSysInvalidateOrder(const void *pV1, const void *pV2)
{
	CSysInvalidateOrder *p1,*p2;
	p1=(CSysInvalidateOrder *)pV1;
	p2=(CSysInvalidateOrder *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysInvalidateOrder=0;
#endif

CSysInvalidateOrder *CSysInvalidateOrderFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysInvalidateOrder while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInvalidateOrder++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysInvalidateOrder *theSysInvalidateOrder;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysInsertTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysInvalidateOrder=(CSysInvalidateOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInvalidateOrder;
}

CSysInvalidateOrder *CSysInvalidateOrderFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInvalidateOrder++;
#endif
	CSysInvalidateOrder *theSysInvalidateOrder;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysInsertTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysInvalidateOrder=(CSysInvalidateOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInvalidateOrder;
}

void CSysInvalidateOrderFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysOrderStatus(const void *pV1, const void *pV2)
{
	CSysOrderStatus *p1,*p2;
	p1=(CSysOrderStatus *)pV1;
	p2=(CSysOrderStatus *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysOrderStatus=0;
#endif

CSysOrderStatus *CSysOrderStatusFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysOrderStatus while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysOrderStatus++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysOrderStatus *theSysOrderStatus;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysOrderStatus=(CSysOrderStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysOrderStatus;
}

CSysOrderStatus *CSysOrderStatusFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysOrderStatus++;
#endif
	CSysOrderStatus *theSysOrderStatus;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysOrderStatus=(CSysOrderStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysOrderStatus;
}

void CSysOrderStatusFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysTradeTimeIndexinSysBargainOrder(const void *pV1, const void *pV2)
{
	CSysBargainOrder *p1,*p2;
	p1=(CSysBargainOrder *)pV1;
	p2=(CSysBargainOrder *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysBargainOrder=0;
#endif

CSysBargainOrder *CSysBargainOrderFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysBargainOrder while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysBargainOrder++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysBargainOrder *theSysBargainOrder;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysBargainOrder=(CSysBargainOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysBargainOrder;
}

CSysBargainOrder *CSysBargainOrderFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysBargainOrder++;
#endif
	CSysBargainOrder *theSysBargainOrder;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysBargainOrder=(CSysBargainOrder *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysBargainOrder;
}

void CSysBargainOrderFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysInstrumentIDIndexinSysInstProperty(const void *pV1, const void *pV2)
{
	CSysInstProperty *p1,*p2;
	p1=(CSysInstProperty *)pV1;
	p2=(CSysInstProperty *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysInstProperty=0;
#endif

CSysInstProperty *CSysInstPropertyFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysInstProperty while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysInstProperty++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysInstProperty *theSysInstProperty;
	compareObject.InstrumentID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysInstProperty=(CSysInstProperty *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInstProperty;
}

CSysInstProperty *CSysInstPropertyFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysInstProperty++;
#endif
	CSysInstProperty *theSysInstProperty;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysInstProperty=(CSysInstProperty *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInstProperty;
}

void CSysInstPropertyFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysInstProperty=0;
#endif
CSysInstProperty *CSysInstPropertyFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysInstProperty while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysInstProperty++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysInstProperty *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysMarginRate(const void *pV1, const void *pV2)
{
	CSysMarginRate *p1,*p2;
	p1=(CSysMarginRate *)pV1;
	p2=(CSysMarginRate *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->TradingRole.getValue(),p2->TradingRole.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysMarginRate=0;
#endif

CSysMarginRate *CSysMarginRateFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMarginRate while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysMarginRate++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMarginRate *theSysMarginRate;
	compareObject.InstrumentID="";
	compareObject.ParticipantID="";
	compareObject.TradingRole="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMarginRate=(CSysMarginRate *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMarginRate;
}

CSysMarginRate *CSysMarginRateFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMarginRate++;
#endif
	CSysMarginRate *theSysMarginRate;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMarginRate=(CSysMarginRate *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMarginRate;
}

void CSysMarginRateFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMarginRate=0;
#endif
CSysMarginRate *CSysMarginRateFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMarginRate while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMarginRate++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.TradingRole=TradingRole.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMarginRate *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysPriceLimit(const void *pV1, const void *pV2)
{
	CSysPriceLimit *p1,*p2;
	p1=(CSysPriceLimit *)pV1;
	p2=(CSysPriceLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysPriceLimit=0;
#endif

CSysPriceLimit *CSysPriceLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysPriceLimit while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysPriceLimit++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysPriceLimit *theSysPriceLimit;
	compareObject.InstrumentID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysPriceLimit=(CSysPriceLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPriceLimit;
}

CSysPriceLimit *CSysPriceLimitFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysPriceLimit++;
#endif
	CSysPriceLimit *theSysPriceLimit;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysPriceLimit=(CSysPriceLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPriceLimit;
}

void CSysPriceLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysPriceLimit=0;
#endif
CSysPriceLimit *CSysPriceLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysPriceLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysPriceLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysPriceLimit *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysPartPosiLimit(const void *pV1, const void *pV2)
{
	CSysPartPosiLimit *p1,*p2;
	p1=(CSysPartPosiLimit *)pV1;
	p2=(CSysPartPosiLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysPartPosiLimit=0;
#endif

CSysPartPosiLimit *CSysPartPosiLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysPartPosiLimit while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartPosiLimit++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysPartPosiLimit *theSysPartPosiLimit;
	compareObject.InstrumentID="";
	compareObject.ParticipantID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysPartPosiLimit=(CSysPartPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPartPosiLimit;
}

CSysPartPosiLimit *CSysPartPosiLimitFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartPosiLimit++;
#endif
	CSysPartPosiLimit *theSysPartPosiLimit;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysPartPosiLimit=(CSysPartPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPartPosiLimit;
}

void CSysPartPosiLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysPartPosiLimit=0;
#endif
CSysPartPosiLimit *CSysPartPosiLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysPartPosiLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysPartPosiLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ParticipantID=ParticipantID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysPartPosiLimit *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysClientPosiLimit(const void *pV1, const void *pV2)
{
	CSysClientPosiLimit *p1,*p2;
	p1=(CSysClientPosiLimit *)pV1;
	p2=(CSysClientPosiLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ClientType.getValue(),p2->ClientType.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysClientPosiLimit=0;
#endif

CSysClientPosiLimit *CSysClientPosiLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysClientPosiLimit while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientPosiLimit++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysClientPosiLimit *theSysClientPosiLimit;
	compareObject.InstrumentID="";
	compareObject.ClientType=CT_Person;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysClientPosiLimit=(CSysClientPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientPosiLimit;
}

CSysClientPosiLimit *CSysClientPosiLimitFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientPosiLimit++;
#endif
	CSysClientPosiLimit *theSysClientPosiLimit;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysClientPosiLimit=(CSysClientPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientPosiLimit;
}

void CSysClientPosiLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysClientPosiLimit=0;
#endif
CSysClientPosiLimit *CSysClientPosiLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysClientPosiLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysClientPosiLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientType=ClientType.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysClientPosiLimit *)(pNode->pObject);
}


int compareForSysInstrumentIDIndexinSysSpecialPosiLimit(const void *pV1, const void *pV2)
{
	CSysSpecialPosiLimit *p1,*p2;
	p1=(CSysSpecialPosiLimit *)pV1;
	p2=(CSysSpecialPosiLimit *)pV2;
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ClientID.getValue(),p2->ClientID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysSpecialPosiLimit=0;
#endif

CSysSpecialPosiLimit *CSysSpecialPosiLimitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysSpecialPosiLimit while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysSpecialPosiLimit++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysSpecialPosiLimit *theSysSpecialPosiLimit;
	compareObject.InstrumentID="";
	compareObject.ClientID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysSpecialPosiLimit=(CSysSpecialPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysSpecialPosiLimit;
}

CSysSpecialPosiLimit *CSysSpecialPosiLimitFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysSpecialPosiLimit++;
#endif
	CSysSpecialPosiLimit *theSysSpecialPosiLimit;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysInstrumentIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysSpecialPosiLimit=(CSysSpecialPosiLimit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysSpecialPosiLimit;
}

void CSysSpecialPosiLimitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysSpecialPosiLimit=0;
#endif
CSysSpecialPosiLimit *CSysSpecialPosiLimitFactory::findByOne( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysSpecialPosiLimit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysSpecialPosiLimit++;
#endif
	CAVLNode *pNode;
	compareObject.InstrumentID=InstrumentID.getValue();
	compareObject.ClientID=ClientID.getValue();
	pNode=pSysInstrumentIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysSpecialPosiLimit *)(pNode->pObject);
}


int compareForSysActionTimeIndexinSysTransactionChg(const void *pV1, const void *pV2)
{
	CSysTransactionChg *p1,*p2;
	p1=(CSysTransactionChg *)pV1;
	p2=(CSysTransactionChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysTransactionChg=0;
#endif

CSysTransactionChg *CSysTransactionChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysTransactionChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysTransactionChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysTransactionChg *theSysTransactionChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysTransactionChg=(CSysTransactionChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysTransactionChg;
}

CSysTransactionChg *CSysTransactionChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysTransactionChg++;
#endif
	CSysTransactionChg *theSysTransactionChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysTransactionChg=(CSysTransactionChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysTransactionChg;
}

void CSysTransactionChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysClientChg(const void *pV1, const void *pV2)
{
	CSysClientChg *p1,*p2;
	p1=(CSysClientChg *)pV1;
	p2=(CSysClientChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysClientChg=0;
#endif

CSysClientChg *CSysClientChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysClientChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysClientChg *theSysClientChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysClientChg=(CSysClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientChg;
}

CSysClientChg *CSysClientChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientChg++;
#endif
	CSysClientChg *theSysClientChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysClientChg=(CSysClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientChg;
}

void CSysClientChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysPartClientChg(const void *pV1, const void *pV2)
{
	CSysPartClientChg *p1,*p2;
	p1=(CSysPartClientChg *)pV1;
	p2=(CSysPartClientChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysPartClientChg=0;
#endif

CSysPartClientChg *CSysPartClientChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysPartClientChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPartClientChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysPartClientChg *theSysPartClientChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysPartClientChg=(CSysPartClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPartClientChg;
}

CSysPartClientChg *CSysPartClientChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPartClientChg++;
#endif
	CSysPartClientChg *theSysPartClientChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysPartClientChg=(CSysPartClientChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPartClientChg;
}

void CSysPartClientChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysPosiLimitChg(const void *pV1, const void *pV2)
{
	CSysPosiLimitChg *p1,*p2;
	p1=(CSysPosiLimitChg *)pV1;
	p2=(CSysPosiLimitChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysPosiLimitChg=0;
#endif

CSysPosiLimitChg *CSysPosiLimitChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysPosiLimitChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPosiLimitChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysPosiLimitChg *theSysPosiLimitChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysPosiLimitChg=(CSysPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPosiLimitChg;
}

CSysPosiLimitChg *CSysPosiLimitChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysPosiLimitChg++;
#endif
	CSysPosiLimitChg *theSysPosiLimitChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysPosiLimitChg=(CSysPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPosiLimitChg;
}

void CSysPosiLimitChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysClientPosiLimitChg(const void *pV1, const void *pV2)
{
	CSysClientPosiLimitChg *p1,*p2;
	p1=(CSysClientPosiLimitChg *)pV1;
	p2=(CSysClientPosiLimitChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysClientPosiLimitChg=0;
#endif

CSysClientPosiLimitChg *CSysClientPosiLimitChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysClientPosiLimitChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientPosiLimitChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysClientPosiLimitChg *theSysClientPosiLimitChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysClientPosiLimitChg=(CSysClientPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientPosiLimitChg;
}

CSysClientPosiLimitChg *CSysClientPosiLimitChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysClientPosiLimitChg++;
#endif
	CSysClientPosiLimitChg *theSysClientPosiLimitChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysClientPosiLimitChg=(CSysClientPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientPosiLimitChg;
}

void CSysClientPosiLimitChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysSpecPosiLimitChg(const void *pV1, const void *pV2)
{
	CSysSpecPosiLimitChg *p1,*p2;
	p1=(CSysSpecPosiLimitChg *)pV1;
	p2=(CSysSpecPosiLimitChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysSpecPosiLimitChg=0;
#endif

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysSpecPosiLimitChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysSpecPosiLimitChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysSpecPosiLimitChg *theSysSpecPosiLimitChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysSpecPosiLimitChg=(CSysSpecPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysSpecPosiLimitChg;
}

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysSpecPosiLimitChg++;
#endif
	CSysSpecPosiLimitChg *theSysSpecPosiLimitChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysSpecPosiLimitChg=(CSysSpecPosiLimitChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysSpecPosiLimitChg;
}

void CSysSpecPosiLimitChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysHedgeDetailChg(const void *pV1, const void *pV2)
{
	CSysHedgeDetailChg *p1,*p2;
	p1=(CSysHedgeDetailChg *)pV1;
	p2=(CSysHedgeDetailChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysHedgeDetailChg=0;
#endif

CSysHedgeDetailChg *CSysHedgeDetailChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysHedgeDetailChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysHedgeDetailChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysHedgeDetailChg *theSysHedgeDetailChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysHedgeDetailChg=(CSysHedgeDetailChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysHedgeDetailChg;
}

CSysHedgeDetailChg *CSysHedgeDetailChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysHedgeDetailChg++;
#endif
	CSysHedgeDetailChg *theSysHedgeDetailChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysHedgeDetailChg=(CSysHedgeDetailChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysHedgeDetailChg;
}

void CSysHedgeDetailChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysParticipantChg(const void *pV1, const void *pV2)
{
	CSysParticipantChg *p1,*p2;
	p1=(CSysParticipantChg *)pV1;
	p2=(CSysParticipantChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysParticipantChg=0;
#endif

CSysParticipantChg *CSysParticipantChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysParticipantChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysParticipantChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysParticipantChg *theSysParticipantChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysParticipantChg=(CSysParticipantChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysParticipantChg;
}

CSysParticipantChg *CSysParticipantChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysParticipantChg++;
#endif
	CSysParticipantChg *theSysParticipantChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysParticipantChg=(CSysParticipantChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysParticipantChg;
}

void CSysParticipantChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysMarginRateChg(const void *pV1, const void *pV2)
{
	CSysMarginRateChg *p1,*p2;
	p1=(CSysMarginRateChg *)pV1;
	p2=(CSysMarginRateChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysMarginRateChg=0;
#endif

CSysMarginRateChg *CSysMarginRateChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysMarginRateChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysMarginRateChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMarginRateChg *theSysMarginRateChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMarginRateChg=(CSysMarginRateChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMarginRateChg;
}

CSysMarginRateChg *CSysMarginRateChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysMarginRateChg++;
#endif
	CSysMarginRateChg *theSysMarginRateChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysMarginRateChg=(CSysMarginRateChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMarginRateChg;
}

void CSysMarginRateChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysActionTimeIndexinSysUserIpChg(const void *pV1, const void *pV2)
{
	CSysUserIpChg *p1,*p2;
	p1=(CSysUserIpChg *)pV1;
	p2=(CSysUserIpChg *)pV2;
	switch (compare(p1->ActionTime.getValue(),p2->ActionTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysUserIpChg=0;
#endif

CSysUserIpChg *CSysUserIpChgFactory::startFindByActionTime( const CReadOnlyTimeType& ActionTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysUserIpChg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryActionTimeInSearchByActionTime= ActionTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysUserIpChg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysUserIpChg *theSysUserIpChg;
	compareObject.ActionTime=ActionTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysUserIpChg=(CSysUserIpChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysUserIpChg;
}

CSysUserIpChg *CSysUserIpChgFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysUserIpChg++;
#endif
	CSysUserIpChg *theSysUserIpChg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysActionTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysUserIpChg=(CSysUserIpChg *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysUserIpChg;
}

void CSysUserIpChgFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}

int compareForSysPartInstrumentIndexinSysPartTrade(const void *pV1, const void *pV2)
{
	CSysPartTrade *p1,*p2;
	p1=(CSysPartTrade *)pV1;
	p2=(CSysPartTrade *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->InstrumentID.getValue(),p2->InstrumentID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysPartTrade=0;
#endif

CSysPartTrade *CSysPartTradeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysPartTrade while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartTrade++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysPartTrade *theSysPartTrade;
	compareObject.ParticipantID="";
	compareObject.InstrumentID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysPartInstrumentIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysPartTrade=(CSysPartTrade *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPartTrade;
}

CSysPartTrade *CSysPartTradeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysPartTrade++;
#endif
	CSysPartTrade *theSysPartTrade;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysPartInstrumentIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysPartTrade=(CSysPartTrade *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysPartTrade;
}

void CSysPartTradeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysPartTrade=0;
#endif
CSysPartTrade *CSysPartTradeFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysPartTrade while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysPartTrade++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.InstrumentID=InstrumentID.getValue();
	pNode=pSysPartInstrumentIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysPartTrade *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysMdbObjectAttr(const void *pV1, const void *pV2)
{
	CSysMdbObjectAttr *p1,*p2;
	p1=(CSysMdbObjectAttr *)pV1;
	p2=(CSysMdbObjectAttr *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindByIDType( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbObjectAttr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByIDType= SubcriberID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbObjectAttr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbObjectAttr->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextByIDType(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbObjectAttr->SubcriberID,querySubcriberIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbObjectAttr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbObjectAttr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbObjectAttr->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbObjectAttr->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbObjectAttr=0;
#endif
CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findByOne( const CReadOnlyVolumeType&  SubcriberID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbObjectAttr while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbObjectAttr++;
#endif
	CAVLNode *pNode;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbObjectAttr *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbObjectAttr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbObjectAttr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbObjectAttr=0;
#endif

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbObjectAttr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbObjectAttr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbObjectAttr *theSysMdbObjectAttr;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbObjectAttr->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

CSysMdbObjectAttr *CSysMdbObjectAttrFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbObjectAttr++;
#endif
	CSysMdbObjectAttr *theSysMdbObjectAttr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbObjectAttr=(CSysMdbObjectAttr *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbObjectAttr->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbObjectAttr;
}

void CSysMdbObjectAttrFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbSyslogInfo(const void *pV1, const void *pV2)
{
	CSysMdbSyslogInfo *p1,*p2;
	p1=(CSysMdbSyslogInfo *)pV1;
	p2=(CSysMdbSyslogInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->AttrType.getValue(),p2->AttrType.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbSyslogInfo(const void *pV1, const void *pV2)
{
	CSysMdbSyslogInfo *p1,*p2;
	p1=(CSysMdbSyslogInfo *)pV1;
	p2=(CSysMdbSyslogInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->AttrType.getValue(),p2->AttrType.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysMdbSyslogInfo=0;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::startFindByAll( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyVolumeType& AttrType)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMdbSyslogInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByAll= ObjectID.getValue();
	queryAttrTypeInSearchByAll= AttrType.getValue();

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbSyslogInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.AttrType=AttrType.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbSyslogInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType.getValue(),AttrType.getValue()))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbSyslogInfo;
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbSyslogInfo++;
#endif
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbSyslogInfo->ObjectID,queryObjectIDInSearchByAll))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType,queryAttrTypeInSearchByAll))
	{
		pLastFoundInSearchByAll=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbSyslogInfo;
}

void CSysMdbSyslogInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbSyslogInfo=0;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbSyslogInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbSyslogInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;
	compareObject.ObjectID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbSyslogInfo;
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbSyslogInfo++;
#endif
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbSyslogInfo;
}

void CSysMdbSyslogInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbSyslogInfo=0;
#endif

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyVolumeType& AttrType,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbSyslogInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryAttrTypeInSearchByDataDelete= AttrType.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbSyslogInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.AttrType=AttrType.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbSyslogInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType.getValue(),AttrType.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbSyslogInfo;
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbSyslogInfo++;
#endif
	CSysMdbSyslogInfo *theSysMdbSyslogInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbSyslogInfo=(CSysMdbSyslogInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbSyslogInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysMdbSyslogInfo->AttrType,queryAttrTypeInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbSyslogInfo;
}

void CSysMdbSyslogInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysUserInfo(const void *pV1, const void *pV2)
{
	CSysUserInfo *p1,*p2;
	p1=(CSysUserInfo *)pV1;
	p2=(CSysUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysUserInfo(const void *pV1, const void *pV2)
{
	CSysUserInfo *p1,*p2;
	p1=(CSysUserInfo *)pV1;
	p2=(CSysUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysUserInfo=0;
#endif

CSysUserInfo *CSysUserInfoFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysUserInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByHostName= ObjectID.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysUserInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysUserInfo *theSysUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysUserInfo;
}

CSysUserInfo *CSysUserInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysUserInfo++;
#endif
	CSysUserInfo *theSysUserInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysUserInfo->ObjectID,queryObjectIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysUserInfo;
}

void CSysUserInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysUserInfo=0;
#endif

CSysUserInfo *CSysUserInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysUserInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysUserInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysUserInfo *theSysUserInfo;
	compareObject.ObjectID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysUserInfo;
}

CSysUserInfo *CSysUserInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysUserInfo++;
#endif
	CSysUserInfo *theSysUserInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysUserInfo;
}

void CSysUserInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysUserInfo=0;
#endif

CSysUserInfo *CSysUserInfoFactory::startFindByDsc( const CReadOnlyTypeObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysUserInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysUserInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysUserInfo *theSysUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysUserInfo;
}

CSysUserInfo *CSysUserInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysUserInfo++;
#endif
	CSysUserInfo *theSysUserInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysUserInfo=(CSysUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysUserInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysUserInfo;
}

void CSysUserInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}

int compareForSysHostNameIndexinSysOnlineUserInfo(const void *pV1, const void *pV2)
{
	CSysOnlineUserInfo *p1,*p2;
	p1=(CSysOnlineUserInfo *)pV1;
	p2=(CSysOnlineUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysOnlineUserInfo(const void *pV1, const void *pV2)
{
	CSysOnlineUserInfo *p1,*p2;
	p1=(CSysOnlineUserInfo *)pV1;
	p2=(CSysOnlineUserInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysOnlineUserInfo=0;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysOnlineUserInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByHostName= ObjectID.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysOnlineUserInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysOnlineUserInfo *theSysOnlineUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysOnlineUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysOnlineUserInfo;
}

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysOnlineUserInfo++;
#endif
	CSysOnlineUserInfo *theSysOnlineUserInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysOnlineUserInfo->ObjectID,queryObjectIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysOnlineUserInfo;
}

void CSysOnlineUserInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysOnlineUserInfo=0;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysOnlineUserInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysOnlineUserInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysOnlineUserInfo *theSysOnlineUserInfo;
	compareObject.ObjectID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysOnlineUserInfo;
}

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysOnlineUserInfo++;
#endif
	CSysOnlineUserInfo *theSysOnlineUserInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysOnlineUserInfo;
}

void CSysOnlineUserInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysOnlineUserInfo=0;
#endif

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::startFindByDsc( const CReadOnlyTypeObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysOnlineUserInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysOnlineUserInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysOnlineUserInfo *theSysOnlineUserInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysOnlineUserInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysOnlineUserInfo;
}

CSysOnlineUserInfo *CSysOnlineUserInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysOnlineUserInfo++;
#endif
	CSysOnlineUserInfo *theSysOnlineUserInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysOnlineUserInfo=(CSysOnlineUserInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysOnlineUserInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysOnlineUserInfo;
}

void CSysOnlineUserInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}

int compareForSysHostNameIndexinSysWarningEvent(const void *pV1, const void *pV2)
{
	CSysWarningEvent *p1,*p2;
	p1=(CSysWarningEvent *)pV1;
	p2=(CSysWarningEvent *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->OccurTime.getValue(),p2->OccurTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSysWarningEvent(const void *pV1, const void *pV2)
{
	CSysWarningEvent *p1,*p2;
	p1=(CSysWarningEvent *)pV1;
	p2=(CSysWarningEvent *)pV2;
	switch (compare(p1->EvendID.getValue(),p2->EvendID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& OccurTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysWarningEvent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByTime= MonDate.getValue();
	queryOccurTimeInSearchByTime= OccurTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningEvent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysWarningEvent *theSysWarningEvent;
	compareObject.MonDate=MonDate.getValue();
	compareObject.OccurTime=OccurTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByTime=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextByTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByTime=pSysHostNameIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysWarningEvent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysWarningEvent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysWarningEvent *theSysWarningEvent;
	compareObject.MonDate="zzzzzzzz";
	compareObject.OccurTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSysWarningEvent=0;
#endif
CSysWarningEvent *CSysWarningEventFactory::findByEvendID( const CReadOnlyVolumeType&  EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSysWarningEvent while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSysWarningEvent++;
#endif
	CAVLNode *pNode;
	compareObject.EvendID=EvendID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysWarningEvent *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByEvendIDsForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindByEvendIDs( const CReadOnlyVolumeType& EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByEvendIDs of CSysWarningEvent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByEvendIDs!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByEvendIDs();
	}

	///��¼���еĲ�ѯֵ
	queryEvendIDInSearchByEvendIDs= EvendID.getValue();

#ifdef COUNT_SEARCH
	multiFindByEvendIDsForSysWarningEvent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysWarningEvent *theSysWarningEvent;
	compareObject.EvendID=EvendID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByEvendIDs=pSysEventIdIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByEvendIDs==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByEvendIDs->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysWarningEvent->EvendID.getValue(),EvendID.getValue()))
	{
		pLastFoundInSearchByEvendIDs=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextByEvendIDs(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByEvendIDs==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByEvendIDsForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByEvendIDs=pSysEventIdIndex->getNextNode(pLastFoundInSearchByEvendIDs);
	if (pLastFoundInSearchByEvendIDs==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchByEvendIDs->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysWarningEvent->EvendID,queryEvendIDInSearchByEvendIDs))
	{
		pLastFoundInSearchByEvendIDs=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindByEvendIDs(void)
{
	pLastFoundInSearchByEvendIDs=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysWarningEvent=0;
#endif

CSysWarningEvent *CSysWarningEventFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysWarningEvent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysWarningEvent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysWarningEvent *theSysWarningEvent;
	compareObject.EvendID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysEventIdIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

CSysWarningEvent *CSysWarningEventFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysWarningEvent++;
#endif
	CSysWarningEvent *theSysWarningEvent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysEventIdIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysWarningEvent=(CSysWarningEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningEvent;
}

void CSysWarningEventFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysWarningQuery(const void *pV1, const void *pV2)
{
	CSysWarningQuery *p1,*p2;
	p1=(CSysWarningQuery *)pV1;
	p2=(CSysWarningQuery *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSysWarningQuery(const void *pV1, const void *pV2)
{
	CSysWarningQuery *p1,*p2;
	p1=(CSysWarningQuery *)pV1;
	p2=(CSysWarningQuery *)pV2;
	switch (compare(p1->EvendID.getValue(),p2->EvendID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysWarningQuery=0;
#endif

CSysWarningQuery *CSysWarningQueryFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysWarningQuery while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByTime= MonDate.getValue();
	queryMonTimeInSearchByTime= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningQuery++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysWarningQuery *theSysWarningQuery;
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByTime=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysWarningQuery=(CSysWarningQuery *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningQuery;
}

CSysWarningQuery *CSysWarningQueryFactory::findNextByTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysWarningQuery++;
#endif
	CSysWarningQuery *theSysWarningQuery;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByTime=pSysHostNameIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysWarningQuery=(CSysWarningQuery *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysWarningQuery;
}

void CSysWarningQueryFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSysWarningQuery=0;
#endif
CSysWarningQuery *CSysWarningQueryFactory::findByEvendID( const CReadOnlyVolumeType&  EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSysWarningQuery while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSysWarningQuery++;
#endif
	CAVLNode *pNode;
	compareObject.EvendID=EvendID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysWarningQuery *)(pNode->pObject);
}


int compareForSysTimeIndexinSyslogEvent(const void *pV1, const void *pV2)
{
	CSyslogEvent *p1,*p2;
	p1=(CSyslogEvent *)pV1;
	p2=(CSyslogEvent *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->OccurTime.getValue(),p2->OccurTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSyslogEvent(const void *pV1, const void *pV2)
{
	CSyslogEvent *p1,*p2;
	p1=(CSyslogEvent *)pV1;
	p2=(CSyslogEvent *)pV2;
	switch (compare(p1->EvendID.getValue(),p2->EvendID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSyslogEvent=0;
#endif

CSyslogEvent *CSyslogEventFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& OccurTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSyslogEvent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByTime= MonDate.getValue();
	queryOccurTimeInSearchByTime= OccurTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSyslogEvent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSyslogEvent *theSyslogEvent;
	compareObject.MonDate=MonDate.getValue();
	compareObject.OccurTime=OccurTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByTime=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSyslogEvent;
}

CSyslogEvent *CSyslogEventFactory::findNextByTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSyslogEvent++;
#endif
	CSyslogEvent *theSyslogEvent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByTime=pSysTimeIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSyslogEvent;
}

void CSyslogEventFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSyslogEvent=0;
#endif

CSyslogEvent *CSyslogEventFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSyslogEvent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSyslogEvent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSyslogEvent *theSyslogEvent;
	compareObject.MonDate="zzzzzzzz";
	compareObject.OccurTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSyslogEvent;
}

CSyslogEvent *CSyslogEventFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSyslogEvent++;
#endif
	CSyslogEvent *theSyslogEvent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSyslogEvent;
}

void CSyslogEventFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSyslogEvent=0;
#endif

CSyslogEvent *CSyslogEventFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSyslogEvent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSyslogEvent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSyslogEvent *theSyslogEvent;
	compareObject.MonDate="zzzzzzzz";
	compareObject.OccurTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSyslogEvent;
}

CSyslogEvent *CSyslogEventFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSyslogEvent++;
#endif
	CSyslogEvent *theSyslogEvent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSyslogEvent=(CSyslogEvent *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSyslogEvent;
}

void CSyslogEventFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSyslogEvent=0;
#endif
CSyslogEvent *CSyslogEventFactory::findByEvendID( const CReadOnlyVolumeType&  EvendID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSyslogEvent while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSyslogEvent++;
#endif
	CAVLNode *pNode;
	compareObject.EvendID=EvendID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSyslogEvent *)(pNode->pObject);
}


int compareForSysTimeIndexinSysEventDescrip(const void *pV1, const void *pV2)
{
	CSysEventDescrip *p1,*p2;
	p1=(CSysEventDescrip *)pV1;
	p2=(CSysEventDescrip *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysEventIdIndexinSysEventDescrip(const void *pV1, const void *pV2)
{
	CSysEventDescrip *p1,*p2;
	p1=(CSysEventDescrip *)pV1;
	p2=(CSysEventDescrip *)pV2;
	switch (compare(p1->EventDesID.getValue(),p2->EventDesID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysEventDescrip=0;
#endif

CSysEventDescrip *CSysEventDescripFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysEventDescrip while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByTime= MonDate.getValue();
	queryMonTimeInSearchByTime= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysEventDescrip++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysEventDescrip *theSysEventDescrip;
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByTime=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysEventDescrip;
}

CSysEventDescrip *CSysEventDescripFactory::findNextByTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysEventDescrip++;
#endif
	CSysEventDescrip *theSysEventDescrip;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByTime=pSysTimeIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysEventDescrip;
}

void CSysEventDescripFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysEventDescrip=0;
#endif

CSysEventDescrip *CSysEventDescripFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysEventDescrip while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysEventDescrip++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysEventDescrip *theSysEventDescrip;
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysEventDescrip;
}

CSysEventDescrip *CSysEventDescripFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysEventDescrip++;
#endif
	CSysEventDescrip *theSysEventDescrip;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysEventDescrip;
}

void CSysEventDescripFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysEventDescrip=0;
#endif

CSysEventDescrip *CSysEventDescripFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysEventDescrip while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysEventDescrip++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysEventDescrip *theSysEventDescrip;
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysEventDescrip;
}

CSysEventDescrip *CSysEventDescripFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysEventDescrip++;
#endif
	CSysEventDescrip *theSysEventDescrip;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysEventDescrip=(CSysEventDescrip *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysEventDescrip;
}

void CSysEventDescripFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByEvendIDForSysEventDescrip=0;
#endif
CSysEventDescrip *CSysEventDescripFactory::findByEvendID( const CReadOnlyEventDesIDType&  EventDesID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByEvendID of CSysEventDescrip while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByEvendIDForSysEventDescrip++;
#endif
	CAVLNode *pNode;
	compareObject.EventDesID=EventDesID.getValue();
	pNode=pSysEventIdIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysEventDescrip *)(pNode->pObject);
}


int compareForSysHostNameIndexinRspQryHostEnvCommon(const void *pV1, const void *pV2)
{
	CRspQryHostEnvCommon *p1,*p2;
	p1=(CRspQryHostEnvCommon *)pV1;
	p2=(CRspQryHostEnvCommon *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvCommon=0;
#endif

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvCommon while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvCommon++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvCommon->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvCommon;
}

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvCommon++;
#endif
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvCommon->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvCommon;
}

void CRspQryHostEnvCommonFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvCommon=0;
#endif

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvCommon while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvCommon++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvCommon;
}

CRspQryHostEnvCommon *CRspQryHostEnvCommonFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvCommon++;
#endif
	CRspQryHostEnvCommon *theRspQryHostEnvCommon;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvCommon=(CRspQryHostEnvCommon *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvCommon;
}

void CRspQryHostEnvCommonFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvLan(const void *pV1, const void *pV2)
{
	CRspQryHostEnvLan *p1,*p2;
	p1=(CRspQryHostEnvLan *)pV1;
	p2=(CRspQryHostEnvLan *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvLan=0;
#endif

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvLan while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLan++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvLan *theRspQryHostEnvLan;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvLan->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvLan;
}

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLan++;
#endif
	CRspQryHostEnvLan *theRspQryHostEnvLan;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvLan->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvLan;
}

void CRspQryHostEnvLanFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvLan=0;
#endif

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvLan while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLan++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvLan *theRspQryHostEnvLan;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvLan;
}

CRspQryHostEnvLan *CRspQryHostEnvLanFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLan++;
#endif
	CRspQryHostEnvLan *theRspQryHostEnvLan;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLan=(CRspQryHostEnvLan *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvLan;
}

void CRspQryHostEnvLanFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvStorage(const void *pV1, const void *pV2)
{
	CRspQryHostEnvStorage *p1,*p2;
	p1=(CRspQryHostEnvStorage *)pV1;
	p2=(CRspQryHostEnvStorage *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvStorage=0;
#endif

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvStorage while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvStorage++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvStorage->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvStorage;
}

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvStorage++;
#endif
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvStorage->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvStorage;
}

void CRspQryHostEnvStorageFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvStorage=0;
#endif

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvStorage while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvStorage++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvStorage;
}

CRspQryHostEnvStorage *CRspQryHostEnvStorageFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvStorage++;
#endif
	CRspQryHostEnvStorage *theRspQryHostEnvStorage;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvStorage=(CRspQryHostEnvStorage *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvStorage;
}

void CRspQryHostEnvStorageFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvIO(const void *pV1, const void *pV2)
{
	CRspQryHostEnvIO *p1,*p2;
	p1=(CRspQryHostEnvIO *)pV1;
	p2=(CRspQryHostEnvIO *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvIO=0;
#endif

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvIO while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvIO++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvIO *theRspQryHostEnvIO;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvIO->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvIO;
}

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvIO++;
#endif
	CRspQryHostEnvIO *theRspQryHostEnvIO;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvIO->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvIO;
}

void CRspQryHostEnvIOFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvIO=0;
#endif

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvIO while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvIO++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvIO *theRspQryHostEnvIO;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvIO;
}

CRspQryHostEnvIO *CRspQryHostEnvIOFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvIO++;
#endif
	CRspQryHostEnvIO *theRspQryHostEnvIO;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvIO=(CRspQryHostEnvIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvIO;
}

void CRspQryHostEnvIOFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvFS(const void *pV1, const void *pV2)
{
	CRspQryHostEnvFS *p1,*p2;
	p1=(CRspQryHostEnvFS *)pV1;
	p2=(CRspQryHostEnvFS *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvFS=0;
#endif

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvFS while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvFS++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvFS *theRspQryHostEnvFS;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvFS->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvFS;
}

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvFS++;
#endif
	CRspQryHostEnvFS *theRspQryHostEnvFS;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvFS->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvFS;
}

void CRspQryHostEnvFSFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvFS=0;
#endif

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvFS while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvFS++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvFS *theRspQryHostEnvFS;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvFS;
}

CRspQryHostEnvFS *CRspQryHostEnvFSFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvFS++;
#endif
	CRspQryHostEnvFS *theRspQryHostEnvFS;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvFS=(CRspQryHostEnvFS *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvFS;
}

void CRspQryHostEnvFSFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvSwap(const void *pV1, const void *pV2)
{
	CRspQryHostEnvSwap *p1,*p2;
	p1=(CRspQryHostEnvSwap *)pV1;
	p2=(CRspQryHostEnvSwap *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvSwap=0;
#endif

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvSwap while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvSwap++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvSwap->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvSwap;
}

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvSwap++;
#endif
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvSwap->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvSwap;
}

void CRspQryHostEnvSwapFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvSwap=0;
#endif

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvSwap while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvSwap++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvSwap;
}

CRspQryHostEnvSwap *CRspQryHostEnvSwapFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvSwap++;
#endif
	CRspQryHostEnvSwap *theRspQryHostEnvSwap;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvSwap=(CRspQryHostEnvSwap *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvSwap;
}

void CRspQryHostEnvSwapFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinRspQryHostEnvLanCfg(const void *pV1, const void *pV2)
{
	CRspQryHostEnvLanCfg *p1,*p2;
	p1=(CRspQryHostEnvLanCfg *)pV1;
	p2=(CRspQryHostEnvLanCfg *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForRspQryHostEnvLanCfg=0;
#endif

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::startFindByHostName( const CReadOnlyTypeObjectIDType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CRspQryHostEnvLanCfg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLanCfg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;
	compareObject.HostName=HostName.getValue();
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvLanCfg->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvLanCfg;
}

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForRspQryHostEnvLanCfg++;
#endif
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theRspQryHostEnvLanCfg->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theRspQryHostEnvLanCfg;
}

void CRspQryHostEnvLanCfgFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForRspQryHostEnvLanCfg=0;
#endif

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CRspQryHostEnvLanCfg while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLanCfg++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvLanCfg;
}

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForRspQryHostEnvLanCfg++;
#endif
	CRspQryHostEnvLanCfg *theRspQryHostEnvLanCfg;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theRspQryHostEnvLanCfg=(CRspQryHostEnvLanCfg *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theRspQryHostEnvLanCfg;
}

void CRspQryHostEnvLanCfgFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysMdbTopCpuInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopCpuInfo *p1,*p2;
	p1=(CSysMdbTopCpuInfo *)pV1;
	p2=(CSysMdbTopCpuInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTopCpuInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopCpuInfo *p1,*p2;
	p1=(CSysMdbTopCpuInfo *)pV1;
	p2=(CSysMdbTopCpuInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbTopCpuInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopCpuInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopCpuInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopCpuInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTopCpuInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopCpuInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopCpuInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopCpuInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTopCpuInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopCpuInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbTopCpuInfo=0;
#endif

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbTopCpuInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByDataDelete= HostName.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopCpuInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopCpuInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopCpuInfo++;
#endif
	CSysMdbTopCpuInfo *theSysMdbTopCpuInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbTopCpuInfo=(CSysMdbTopCpuInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopCpuInfo->HostName,queryHostNameInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopCpuInfo;
}

void CSysMdbTopCpuInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbTopMemInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopMemInfo *p1,*p2;
	p1=(CSysMdbTopMemInfo *)pV1;
	p2=(CSysMdbTopMemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTopMemInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopMemInfo *p1,*p2;
	p1=(CSysMdbTopMemInfo *)pV1;
	p2=(CSysMdbTopMemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbTopMemInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopMemInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopMemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopMemInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTopMemInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopMemInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopMemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopMemInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTopMemInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopMemInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbTopMemInfo=0;
#endif

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbTopMemInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByDataDelete= HostName.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopMemInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopMemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbTopMemInfo++;
#endif
	CSysMdbTopMemInfo *theSysMdbTopMemInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbTopMemInfo=(CSysMdbTopMemInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopMemInfo->HostName,queryHostNameInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopMemInfo;
}

void CSysMdbTopMemInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbTopProcessInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopProcessInfo *p1,*p2;
	p1=(CSysMdbTopProcessInfo *)pV1;
	p2=(CSysMdbTopProcessInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTopProcessInfo(const void *pV1, const void *pV2)
{
	CSysMdbTopProcessInfo *p1,*p2;
	p1=(CSysMdbTopProcessInfo *)pV1;
	p2=(CSysMdbTopProcessInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbTopProcessInfo=0;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbTopProcessInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopProcessInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopProcessInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopProcessInfo;
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbTopProcessInfo++;
#endif
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopProcessInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopProcessInfo;
}

void CSysMdbTopProcessInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTopProcessInfo=0;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTopProcessInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopProcessInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopProcessInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopProcessInfo;
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTopProcessInfo++;
#endif
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTopProcessInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTopProcessInfo;
}

void CSysMdbTopProcessInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTopProcessInfo=0;
#endif

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTopProcessInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopProcessInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTopProcessInfo;
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTopProcessInfo++;
#endif
	CSysMdbTopProcessInfo *theSysMdbTopProcessInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTopProcessInfo=(CSysMdbTopProcessInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTopProcessInfo;
}

void CSysMdbTopProcessInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysMdbFileSystemInfo(const void *pV1, const void *pV2)
{
	CSysMdbFileSystemInfo *p1,*p2;
	p1=(CSysMdbFileSystemInfo *)pV1;
	p2=(CSysMdbFileSystemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbFileSystemInfo(const void *pV1, const void *pV2)
{
	CSysMdbFileSystemInfo *p1,*p2;
	p1=(CSysMdbFileSystemInfo *)pV1;
	p2=(CSysMdbFileSystemInfo *)pV2;
	switch (compare(p1->HostName.getValue(),p2->HostName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbFileSystemInfo=0;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::startFindByHostName( const CReadOnlyVolumeType& HostName,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbFileSystemInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByHostName= HostName.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbFileSystemInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbFileSystemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbFileSystemInfo;
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbFileSystemInfo++;
#endif
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbFileSystemInfo->HostName,queryHostNameInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbFileSystemInfo;
}

void CSysMdbFileSystemInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbFileSystemInfo=0;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::startFindByDsc( const CReadOnlyVolumeType& HostName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbFileSystemInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryHostNameInSearchByDsc= HostName.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbFileSystemInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;
	compareObject.HostName=HostName.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbFileSystemInfo->HostName.getValue(),HostName.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbFileSystemInfo;
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbFileSystemInfo++;
#endif
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbFileSystemInfo->HostName,queryHostNameInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbFileSystemInfo;
}

void CSysMdbFileSystemInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbFileSystemInfo=0;
#endif

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbFileSystemInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbFileSystemInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;
	compareObject.HostName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbFileSystemInfo;
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbFileSystemInfo++;
#endif
	CSysMdbFileSystemInfo *theSysMdbFileSystemInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbFileSystemInfo=(CSysMdbFileSystemInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbFileSystemInfo;
}

void CSysMdbFileSystemInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysHostNameIndexinSysMdbNetworkInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetworkInfo *p1,*p2;
	p1=(CSysMdbNetworkInfo *)pV1;
	p2=(CSysMdbNetworkInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbNetworkInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetworkInfo *p1,*p2;
	p1=(CSysMdbNetworkInfo *)pV1;
	p2=(CSysMdbNetworkInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbNetworkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbNetworkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetworkInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetworkInfo->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbNetworkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetworkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetworkInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetworkInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbNetworkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbNetworkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbNetworkInfo=0;
#endif

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbNetworkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbNetworkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetworkInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbNetworkInfo++;
#endif
	CSysMdbNetworkInfo *theSysMdbNetworkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbNetworkInfo=(CSysMdbNetworkInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetworkInfo->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetworkInfo;
}

void CSysMdbNetworkInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysParticipantIDIndexinSysParticipantInit(const void *pV1, const void *pV2)
{
	CSysParticipantInit *p1,*p2;
	p1=(CSysParticipantInit *)pV1;
	p2=(CSysParticipantInit *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysParticipantInit=0;
#endif

CSysParticipantInit *CSysParticipantInitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysParticipantInit while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticipantInit++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysParticipantInit *theSysParticipantInit;
	compareObject.ParticipantID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysParticipantIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysParticipantInit=(CSysParticipantInit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysParticipantInit;
}

CSysParticipantInit *CSysParticipantInitFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticipantInit++;
#endif
	CSysParticipantInit *theSysParticipantInit;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysParticipantIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysParticipantInit=(CSysParticipantInit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysParticipantInit;
}

void CSysParticipantInitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysParticipantInit=0;
#endif
CSysParticipantInit *CSysParticipantInitFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysParticipantInit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysParticipantInit++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	pNode=pSysParticipantIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysParticipantInit *)(pNode->pObject);
}


int compareForSysUserIDIndexinSysUserInit(const void *pV1, const void *pV2)
{
	CSysUserInit *p1,*p2;
	p1=(CSysUserInit *)pV1;
	p2=(CSysUserInit *)pV2;
	switch (compare(p1->UserID.getValue(),p2->UserID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysUserInit=0;
#endif

CSysUserInit *CSysUserInitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysUserInit while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysUserInit++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysUserInit *theSysUserInit;
	compareObject.UserID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysUserIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysUserInit=(CSysUserInit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysUserInit;
}

CSysUserInit *CSysUserInitFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysUserInit++;
#endif
	CSysUserInit *theSysUserInit;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysUserIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysUserInit=(CSysUserInit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysUserInit;
}

void CSysUserInitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysUserInit=0;
#endif
CSysUserInit *CSysUserInitFactory::findByOne( const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysUserInit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysUserInit++;
#endif
	CAVLNode *pNode;
	compareObject.UserID=UserID.getValue();
	pNode=pSysUserIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysUserInit *)(pNode->pObject);
}


int compareForSysClientIDIndexinSysClientInit(const void *pV1, const void *pV2)
{
	CSysClientInit *p1,*p2;
	p1=(CSysClientInit *)pV1;
	p2=(CSysClientInit *)pV2;
	switch (compare(p1->ClientID.getValue(),p2->ClientID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysClientInit=0;
#endif

CSysClientInit *CSysClientInitFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysClientInit while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientInit++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysClientInit *theSysClientInit;
	compareObject.ClientID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysClientIDIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysClientInit=(CSysClientInit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientInit;
}

CSysClientInit *CSysClientInitFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysClientInit++;
#endif
	CSysClientInit *theSysClientInit;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysClientIDIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysClientInit=(CSysClientInit *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysClientInit;
}

void CSysClientInitFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysClientInit=0;
#endif
CSysClientInit *CSysClientInitFactory::findByOne( const CReadOnlyClientIDType&  ClientID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysClientInit while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysClientInit++;
#endif
	CAVLNode *pNode;
	compareObject.ClientID=ClientID.getValue();
	pNode=pSysClientIDIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysClientInit *)(pNode->pObject);
}


int compareForSysTradeUserLoginInfoIndexinSysTradeUserLoginInfo(const void *pV1, const void *pV2)
{
	CSysTradeUserLoginInfo *p1,*p2;
	p1=(CSysTradeUserLoginInfo *)pV1;
	p2=(CSysTradeUserLoginInfo *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->UserID.getValue(),p2->UserID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysTradeUserLoginInfo=0;
#endif

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysTradeUserLoginInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysTradeUserLoginInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysTradeUserLoginInfo *theSysTradeUserLoginInfo;
	compareObject.ParticipantID="";
	compareObject.UserID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysTradeUserLoginInfoIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysTradeUserLoginInfo=(CSysTradeUserLoginInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysTradeUserLoginInfo;
}

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysTradeUserLoginInfo++;
#endif
	CSysTradeUserLoginInfo *theSysTradeUserLoginInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysTradeUserLoginInfoIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysTradeUserLoginInfo=(CSysTradeUserLoginInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysTradeUserLoginInfo;
}

void CSysTradeUserLoginInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysTradeUserLoginInfo=0;
#endif
CSysTradeUserLoginInfo *CSysTradeUserLoginInfoFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyUserIDType&  UserID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysTradeUserLoginInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysTradeUserLoginInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.UserID=UserID.getValue();
	pNode=pSysTradeUserLoginInfoIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysTradeUserLoginInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysMdbWebAppInfo(const void *pV1, const void *pV2)
{
	CSysMdbWebAppInfo *p1,*p2;
	p1=(CSysMdbWebAppInfo *)pV1;
	p2=(CSysMdbWebAppInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbWebAppInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByIDType= ObjectID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbWebAppInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbWebAppInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextByIDType(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbWebAppInfo->ObjectID,queryObjectIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindByDsc( const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbWebAppInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbWebAppInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbWebAppInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbWebAppInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbWebAppInfo=0;
#endif
CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbWebAppInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbWebAppInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbWebAppInfo *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbWebAppInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbWebAppInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbWebAppInfo=0;
#endif

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbWebAppInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbWebAppInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbWebAppInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbWebAppInfo++;
#endif
	CSysMdbWebAppInfo *theSysMdbWebAppInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbWebAppInfo=(CSysMdbWebAppInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbWebAppInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbWebAppInfo;
}

void CSysMdbWebAppInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbMemPoolInfo(const void *pV1, const void *pV2)
{
	CSysMdbMemPoolInfo *p1,*p2;
	p1=(CSysMdbMemPoolInfo *)pV1;
	p2=(CSysMdbMemPoolInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbMemPoolInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByIDType= ObjectID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbMemPoolInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbMemPoolInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextByIDType(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbMemPoolInfo->ObjectID,queryObjectIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindByDsc( const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbMemPoolInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbMemPoolInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbMemPoolInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbMemPoolInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbMemPoolInfo=0;
#endif
CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbMemPoolInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbMemPoolInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbMemPoolInfo *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbMemPoolInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbMemPoolInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbMemPoolInfo=0;
#endif

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbMemPoolInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbMemPoolInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbMemPoolInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbMemPoolInfo++;
#endif
	CSysMdbMemPoolInfo *theSysMdbMemPoolInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbMemPoolInfo=(CSysMdbMemPoolInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbMemPoolInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbMemPoolInfo;
}

void CSysMdbMemPoolInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbConnectorInfo(const void *pV1, const void *pV2)
{
	CSysMdbConnectorInfo *p1,*p2;
	p1=(CSysMdbConnectorInfo *)pV1;
	p2=(CSysMdbConnectorInfo *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbConnectorInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByIDType= ObjectID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbConnectorInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbConnectorInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextByIDType(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbConnectorInfo->ObjectID,queryObjectIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindByDsc( const CReadOnlyVolumeType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbConnectorInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDsc= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbConnectorInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbConnectorInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbConnectorInfo->ObjectID,queryObjectIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbConnectorInfo=0;
#endif
CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findByOne( const CReadOnlyVolumeType&  ObjectID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbConnectorInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbConnectorInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbConnectorInfo *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbConnectorInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbConnectorInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbConnectorInfo=0;
#endif

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& ObjectID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbConnectorInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbConnectorInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbConnectorInfo->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbConnectorInfo++;
#endif
	CSysMdbConnectorInfo *theSysMdbConnectorInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbConnectorInfo=(CSysMdbConnectorInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbConnectorInfo->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbConnectorInfo;
}

void CSysMdbConnectorInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysMdbDBQuery(const void *pV1, const void *pV2)
{
	CSysMdbDBQuery *p1,*p2;
	p1=(CSysMdbDBQuery *)pV1;
	p2=(CSysMdbDBQuery *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindByIDType( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysMdbDBQuery while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByIDType= SubcriberID.getValue();
	queryMonDateInSearchByIDType= MonDate.getValue();
	queryMonTimeInSearchByIDType= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbDBQuery++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDBQuery->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextByIDType(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDBQuery->SubcriberID,querySubcriberIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbDBQuery while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDBQuery++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDBQuery->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDBQuery->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysMdbDBQuery=0;
#endif
CSysMdbDBQuery *CSysMdbDBQueryFactory::findByOne( const CReadOnlyVolumeType&  SubcriberID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysMdbDBQuery while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysMdbDBQuery++;
#endif
	CAVLNode *pNode;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbDBQuery *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbDBQuery while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDBQuery++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbDBQuery=0;
#endif

CSysMdbDBQuery *CSysMdbDBQueryFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbDBQuery while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDBQuery++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDBQuery *theSysMdbDBQuery;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDBQuery->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

CSysMdbDBQuery *CSysMdbDBQueryFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDBQuery++;
#endif
	CSysMdbDBQuery *theSysMdbDBQuery;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbDBQuery=(CSysMdbDBQuery *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDBQuery->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDBQuery;
}

void CSysMdbDBQueryFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysNetArea(const void *pV1, const void *pV2)
{
	CSysNetArea *p1,*p2;
	p1=(CSysNetArea *)pV1;
	p2=(CSysNetArea *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetArea=0;
#endif

CSysNetArea *CSysNetAreaFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetArea while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetArea++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetArea *theSysNetArea;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetArea=(CSysNetArea *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetArea;
}

CSysNetArea *CSysNetAreaFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetArea++;
#endif
	CSysNetArea *theSysNetArea;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetArea=(CSysNetArea *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetArea;
}

void CSysNetAreaFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetArea=0;
#endif
CSysNetArea *CSysNetAreaFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetArea while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetArea++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetArea *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetSubArea(const void *pV1, const void *pV2)
{
	CSysNetSubArea *p1,*p2;
	p1=(CSysNetSubArea *)pV1;
	p2=(CSysNetSubArea *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetSubArea=0;
#endif

CSysNetSubArea *CSysNetSubAreaFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetSubArea while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubArea++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetSubArea *theSysNetSubArea;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetSubArea=(CSysNetSubArea *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetSubArea;
}

CSysNetSubArea *CSysNetSubAreaFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubArea++;
#endif
	CSysNetSubArea *theSysNetSubArea;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetSubArea=(CSysNetSubArea *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetSubArea;
}

void CSysNetSubAreaFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetSubArea=0;
#endif
CSysNetSubArea *CSysNetSubAreaFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetSubArea while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetSubArea++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetSubArea *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetSubAreaIP(const void *pV1, const void *pV2)
{
	CSysNetSubAreaIP *p1,*p2;
	p1=(CSysNetSubAreaIP *)pV1;
	p2=(CSysNetSubAreaIP *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetSubAreaIP=0;
#endif

CSysNetSubAreaIP *CSysNetSubAreaIPFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetSubAreaIP while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubAreaIP++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetSubAreaIP *theSysNetSubAreaIP;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetSubAreaIP=(CSysNetSubAreaIP *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetSubAreaIP;
}

CSysNetSubAreaIP *CSysNetSubAreaIPFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubAreaIP++;
#endif
	CSysNetSubAreaIP *theSysNetSubAreaIP;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetSubAreaIP=(CSysNetSubAreaIP *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetSubAreaIP;
}

void CSysNetSubAreaIPFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetSubAreaIP=0;
#endif
CSysNetSubAreaIP *CSysNetSubAreaIPFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetSubAreaIP while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetSubAreaIP++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetSubAreaIP *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetFuncArea(const void *pV1, const void *pV2)
{
	CSysNetFuncArea *p1,*p2;
	p1=(CSysNetFuncArea *)pV1;
	p2=(CSysNetFuncArea *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetFuncArea=0;
#endif

CSysNetFuncArea *CSysNetFuncAreaFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetFuncArea while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetFuncArea++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetFuncArea *theSysNetFuncArea;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetFuncArea=(CSysNetFuncArea *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetFuncArea;
}

CSysNetFuncArea *CSysNetFuncAreaFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetFuncArea++;
#endif
	CSysNetFuncArea *theSysNetFuncArea;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetFuncArea=(CSysNetFuncArea *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetFuncArea;
}

void CSysNetFuncAreaFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetFuncArea=0;
#endif
CSysNetFuncArea *CSysNetFuncAreaFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetFuncArea while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetFuncArea++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetFuncArea *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysIPDECODETypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->IPDECODE.getValue(),p2->IPDECODE.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysSubAreaIDTypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->SysNetSubAreaID.getValue(),p2->SysNetSubAreaID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysObjectIDTypeIndexinSysNetDevice(const void *pV1, const void *pV2)
{
	CSysNetDevice *p1,*p2;
	p1=(CSysNetDevice *)pV1;
	p2=(CSysNetDevice *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDevice=0;
#endif

CSysNetDevice *CSysNetDeviceFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDevice while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDevice++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDevice *theSysNetDevice;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDevice;
}

CSysNetDevice *CSysNetDeviceFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDevice++;
#endif
	CSysNetDevice *theSysNetDevice;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDevice;
}

void CSysNetDeviceFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDevice=0;
#endif
CSysNetDevice *CSysNetDeviceFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDevice while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDevice++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDevice *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByIPDECODEForSysNetDevice=0;
#endif

CSysNetDevice *CSysNetDeviceFactory::startFindByIPDECODE( const CReadOnlyVolumeType& IPDECODE)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIPDECODE of CSysNetDevice while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIPDECODE!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIPDECODE();
	}

	///��¼���еĲ�ѯֵ
	queryIPDECODEInSearchByIPDECODE= IPDECODE.getValue();

#ifdef COUNT_SEARCH
	multiFindByIPDECODEForSysNetDevice++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDevice *theSysNetDevice;
	compareObject.IPDECODE=IPDECODE.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIPDECODE=pSysIPDECODETypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIPDECODE==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByIPDECODE->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDevice->IPDECODE.getValue(),IPDECODE.getValue()))
	{
		pLastFoundInSearchByIPDECODE=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDevice;
}

CSysNetDevice *CSysNetDeviceFactory::findNextByIPDECODE(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIPDECODE==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIPDECODEForSysNetDevice++;
#endif
	CSysNetDevice *theSysNetDevice;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIPDECODE=pSysIPDECODETypeIndex->getNextNode(pLastFoundInSearchByIPDECODE);
	if (pLastFoundInSearchByIPDECODE==NULL)
	{
		return NULL;
	}

	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchByIPDECODE->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDevice->IPDECODE,queryIPDECODEInSearchByIPDECODE))
	{
		pLastFoundInSearchByIPDECODE=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDevice;
}

void CSysNetDeviceFactory::endFindByIPDECODE(void)
{
	pLastFoundInSearchByIPDECODE=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBySubAreaIDForSysNetDevice=0;
#endif

CSysNetDevice *CSysNetDeviceFactory::startFindBySubAreaID( const CReadOnlyVolumeType& SysNetSubAreaID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBySubAreaID of CSysNetDevice while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBySubAreaID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBySubAreaID();
	}

	///��¼���еĲ�ѯֵ
	querySysNetSubAreaIDInSearchBySubAreaID= SysNetSubAreaID.getValue();

#ifdef COUNT_SEARCH
	multiFindBySubAreaIDForSysNetDevice++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDevice *theSysNetDevice;
	compareObject.SysNetSubAreaID=SysNetSubAreaID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBySubAreaID=pSysSubAreaIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBySubAreaID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchBySubAreaID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDevice->SysNetSubAreaID.getValue(),SysNetSubAreaID.getValue()))
	{
		pLastFoundInSearchBySubAreaID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDevice;
}

CSysNetDevice *CSysNetDeviceFactory::findNextBySubAreaID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBySubAreaID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBySubAreaIDForSysNetDevice++;
#endif
	CSysNetDevice *theSysNetDevice;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBySubAreaID=pSysSubAreaIDTypeIndex->getNextNode(pLastFoundInSearchBySubAreaID);
	if (pLastFoundInSearchBySubAreaID==NULL)
	{
		return NULL;
	}

	theSysNetDevice=(CSysNetDevice *)(pLastFoundInSearchBySubAreaID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDevice->SysNetSubAreaID,querySysNetSubAreaIDInSearchBySubAreaID))
	{
		pLastFoundInSearchBySubAreaID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDevice;
}

void CSysNetDeviceFactory::endFindBySubAreaID(void)
{
	pLastFoundInSearchBySubAreaID=NULL;
}


#ifdef COUNT_SEARCH
int findByObjectIDForSysNetDevice=0;
#endif
CSysNetDevice *CSysNetDeviceFactory::findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByObjectID of CSysNetDevice while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByObjectIDForSysNetDevice++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	pNode=pSysObjectIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDevice *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDeviceLinked(const void *pV1, const void *pV2)
{
	CSysNetDeviceLinked *p1,*p2;
	p1=(CSysNetDeviceLinked *)pV1;
	p2=(CSysNetDeviceLinked *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysNetObjectIDTypeIndexinSysNetDeviceLinked(const void *pV1, const void *pV2)
{
	CSysNetDeviceLinked *p1,*p2;
	p1=(CSysNetDeviceLinked *)pV1;
	p2=(CSysNetDeviceLinked *)pV2;
	switch (compare(p1->NetObjectID.getValue(),p2->NetObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysLinkObjectIDTypeIndexinSysNetDeviceLinked(const void *pV1, const void *pV2)
{
	CSysNetDeviceLinked *p1,*p2;
	p1=(CSysNetDeviceLinked *)pV1;
	p2=(CSysNetDeviceLinked *)pV2;
	switch (compare(p1->LinkNetObjectID.getValue(),p2->LinkNetObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDeviceLinked=0;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDeviceLinked while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceLinked++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDeviceLinked *theSysNetDeviceLinked;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDeviceLinked;
}

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceLinked++;
#endif
	CSysNetDeviceLinked *theSysNetDeviceLinked;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDeviceLinked;
}

void CSysNetDeviceLinkedFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDeviceLinked=0;
#endif
CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDeviceLinked while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDeviceLinked++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDeviceLinked *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByNetObjectIDForSysNetDeviceLinked=0;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::startFindByNetObjectID( const CReadOnlyNetObjectIDType& NetObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByNetObjectID of CSysNetDeviceLinked while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByNetObjectID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByNetObjectID();
	}

	///��¼���еĲ�ѯֵ
	queryNetObjectIDInSearchByNetObjectID= NetObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetDeviceLinked++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDeviceLinked *theSysNetDeviceLinked;
	compareObject.NetObjectID=NetObjectID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDeviceLinked->NetObjectID.getValue(),NetObjectID.getValue()))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDeviceLinked;
}

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findNextByNetObjectID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetDeviceLinked++;
#endif
	CSysNetDeviceLinked *theSysNetDeviceLinked;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->getNextNode(pLastFoundInSearchByNetObjectID);
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDeviceLinked->NetObjectID,queryNetObjectIDInSearchByNetObjectID))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDeviceLinked;
}

void CSysNetDeviceLinkedFactory::endFindByNetObjectID(void)
{
	pLastFoundInSearchByNetObjectID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByLinkNetObjectIDForSysNetDeviceLinked=0;
#endif

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::startFindByLinkNetObjectID( const CReadOnlyNetObjectIDType& LinkNetObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByLinkNetObjectID of CSysNetDeviceLinked while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByLinkNetObjectID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByLinkNetObjectID();
	}

	///��¼���еĲ�ѯֵ
	queryLinkNetObjectIDInSearchByLinkNetObjectID= LinkNetObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByLinkNetObjectIDForSysNetDeviceLinked++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDeviceLinked *theSysNetDeviceLinked;
	compareObject.LinkNetObjectID=LinkNetObjectID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByLinkNetObjectID=pSysLinkObjectIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByLinkNetObjectID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByLinkNetObjectID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDeviceLinked->LinkNetObjectID.getValue(),LinkNetObjectID.getValue()))
	{
		pLastFoundInSearchByLinkNetObjectID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDeviceLinked;
}

CSysNetDeviceLinked *CSysNetDeviceLinkedFactory::findNextByLinkNetObjectID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByLinkNetObjectID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByLinkNetObjectIDForSysNetDeviceLinked++;
#endif
	CSysNetDeviceLinked *theSysNetDeviceLinked;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByLinkNetObjectID=pSysLinkObjectIDTypeIndex->getNextNode(pLastFoundInSearchByLinkNetObjectID);
	if (pLastFoundInSearchByLinkNetObjectID==NULL)
	{
		return NULL;
	}

	theSysNetDeviceLinked=(CSysNetDeviceLinked *)(pLastFoundInSearchByLinkNetObjectID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetDeviceLinked->LinkNetObjectID,queryLinkNetObjectIDInSearchByLinkNetObjectID))
	{
		pLastFoundInSearchByLinkNetObjectID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetDeviceLinked;
}

void CSysNetDeviceLinkedFactory::endFindByLinkNetObjectID(void)
{
	pLastFoundInSearchByLinkNetObjectID=NULL;
}

int compareForSysIDTypeIndexinSysNetOID(const void *pV1, const void *pV2)
{
	CSysNetOID *p1,*p2;
	p1=(CSysNetOID *)pV1;
	p2=(CSysNetOID *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetOID=0;
#endif

CSysNetOID *CSysNetOIDFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetOID while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOID++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetOID *theSysNetOID;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetOID=(CSysNetOID *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetOID;
}

CSysNetOID *CSysNetOIDFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOID++;
#endif
	CSysNetOID *theSysNetOID;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetOID=(CSysNetOID *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetOID;
}

void CSysNetOIDFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetOID=0;
#endif
CSysNetOID *CSysNetOIDFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetOID while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetOID++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetOID *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDeviceType(const void *pV1, const void *pV2)
{
	CSysNetDeviceType *p1,*p2;
	p1=(CSysNetDeviceType *)pV1;
	p2=(CSysNetDeviceType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDeviceType=0;
#endif

CSysNetDeviceType *CSysNetDeviceTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDeviceType while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceType++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDeviceType *theSysNetDeviceType;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDeviceType=(CSysNetDeviceType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDeviceType;
}

CSysNetDeviceType *CSysNetDeviceTypeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceType++;
#endif
	CSysNetDeviceType *theSysNetDeviceType;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDeviceType=(CSysNetDeviceType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDeviceType;
}

void CSysNetDeviceTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDeviceType=0;
#endif
CSysNetDeviceType *CSysNetDeviceTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDeviceType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDeviceType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDeviceType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetTimePolicy(const void *pV1, const void *pV2)
{
	CSysNetTimePolicy *p1,*p2;
	p1=(CSysNetTimePolicy *)pV1;
	p2=(CSysNetTimePolicy *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetTimePolicy=0;
#endif

CSysNetTimePolicy *CSysNetTimePolicyFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetTimePolicy while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetTimePolicy++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetTimePolicy *theSysNetTimePolicy;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetTimePolicy=(CSysNetTimePolicy *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetTimePolicy;
}

CSysNetTimePolicy *CSysNetTimePolicyFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetTimePolicy++;
#endif
	CSysNetTimePolicy *theSysNetTimePolicy;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetTimePolicy=(CSysNetTimePolicy *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetTimePolicy;
}

void CSysNetTimePolicyFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetTimePolicy=0;
#endif
CSysNetTimePolicy *CSysNetTimePolicyFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetTimePolicy while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetTimePolicy++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetTimePolicy *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetGatherTask(const void *pV1, const void *pV2)
{
	CSysNetGatherTask *p1,*p2;
	p1=(CSysNetGatherTask *)pV1;
	p2=(CSysNetGatherTask *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysNetObjectIDTypeIndexinSysNetGatherTask(const void *pV1, const void *pV2)
{
	CSysNetGatherTask *p1,*p2;
	p1=(CSysNetGatherTask *)pV1;
	p2=(CSysNetGatherTask *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetGatherTask=0;
#endif

CSysNetGatherTask *CSysNetGatherTaskFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetGatherTask while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGatherTask++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetGatherTask *theSysNetGatherTask;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetGatherTask;
}

CSysNetGatherTask *CSysNetGatherTaskFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGatherTask++;
#endif
	CSysNetGatherTask *theSysNetGatherTask;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetGatherTask;
}

void CSysNetGatherTaskFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetGatherTask=0;
#endif
CSysNetGatherTask *CSysNetGatherTaskFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetGatherTask while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetGatherTask++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetGatherTask *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByNetObjectIDForSysNetGatherTask=0;
#endif

CSysNetGatherTask *CSysNetGatherTaskFactory::startFindByNetObjectID( const CReadOnlyNetObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByNetObjectID of CSysNetGatherTask while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByNetObjectID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByNetObjectID();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByNetObjectID= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetGatherTask++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetGatherTask *theSysNetGatherTask;
	compareObject.ObjectID=ObjectID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetGatherTask->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetGatherTask;
}

CSysNetGatherTask *CSysNetGatherTaskFactory::findNextByNetObjectID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByNetObjectIDForSysNetGatherTask++;
#endif
	CSysNetGatherTask *theSysNetGatherTask;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByNetObjectID=pSysNetObjectIDTypeIndex->getNextNode(pLastFoundInSearchByNetObjectID);
	if (pLastFoundInSearchByNetObjectID==NULL)
	{
		return NULL;
	}

	theSysNetGatherTask=(CSysNetGatherTask *)(pLastFoundInSearchByNetObjectID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetGatherTask->ObjectID,queryObjectIDInSearchByNetObjectID))
	{
		pLastFoundInSearchByNetObjectID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetGatherTask;
}

void CSysNetGatherTaskFactory::endFindByNetObjectID(void)
{
	pLastFoundInSearchByNetObjectID=NULL;
}

int compareForSysIDTypeIndexinSysNetDeviceCategory(const void *pV1, const void *pV2)
{
	CSysNetDeviceCategory *p1,*p2;
	p1=(CSysNetDeviceCategory *)pV1;
	p2=(CSysNetDeviceCategory *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDeviceCategory=0;
#endif

CSysNetDeviceCategory *CSysNetDeviceCategoryFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDeviceCategory while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceCategory++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDeviceCategory *theSysNetDeviceCategory;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDeviceCategory=(CSysNetDeviceCategory *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDeviceCategory;
}

CSysNetDeviceCategory *CSysNetDeviceCategoryFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDeviceCategory++;
#endif
	CSysNetDeviceCategory *theSysNetDeviceCategory;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDeviceCategory=(CSysNetDeviceCategory *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDeviceCategory;
}

void CSysNetDeviceCategoryFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDeviceCategory=0;
#endif
CSysNetDeviceCategory *CSysNetDeviceCategoryFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDeviceCategory while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDeviceCategory++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDeviceCategory *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetManufactory(const void *pV1, const void *pV2)
{
	CSysNetManufactory *p1,*p2;
	p1=(CSysNetManufactory *)pV1;
	p2=(CSysNetManufactory *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetManufactory=0;
#endif

CSysNetManufactory *CSysNetManufactoryFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetManufactory while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetManufactory++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetManufactory *theSysNetManufactory;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetManufactory=(CSysNetManufactory *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetManufactory;
}

CSysNetManufactory *CSysNetManufactoryFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetManufactory++;
#endif
	CSysNetManufactory *theSysNetManufactory;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetManufactory=(CSysNetManufactory *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetManufactory;
}

void CSysNetManufactoryFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetManufactory=0;
#endif
CSysNetManufactory *CSysNetManufactoryFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetManufactory while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetManufactory++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetManufactory *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetCommunity(const void *pV1, const void *pV2)
{
	CSysNetCommunity *p1,*p2;
	p1=(CSysNetCommunity *)pV1;
	p2=(CSysNetCommunity *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetCommunity=0;
#endif

CSysNetCommunity *CSysNetCommunityFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetCommunity while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetCommunity++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetCommunity *theSysNetCommunity;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetCommunity=(CSysNetCommunity *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetCommunity;
}

CSysNetCommunity *CSysNetCommunityFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetCommunity++;
#endif
	CSysNetCommunity *theSysNetCommunity;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetCommunity=(CSysNetCommunity *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetCommunity;
}

void CSysNetCommunityFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetCommunity=0;
#endif
CSysNetCommunity *CSysNetCommunityFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetCommunity while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetCommunity++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetCommunity *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetPortType(const void *pV1, const void *pV2)
{
	CSysNetPortType *p1,*p2;
	p1=(CSysNetPortType *)pV1;
	p2=(CSysNetPortType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPortType=0;
#endif

CSysNetPortType *CSysNetPortTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPortType while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPortType++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetPortType *theSysNetPortType;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetPortType=(CSysNetPortType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPortType;
}

CSysNetPortType *CSysNetPortTypeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPortType++;
#endif
	CSysNetPortType *theSysNetPortType;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPortType=(CSysNetPortType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPortType;
}

void CSysNetPortTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetPortType=0;
#endif
CSysNetPortType *CSysNetPortTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetPortType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetPortType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetPortType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetInterface(const void *pV1, const void *pV2)
{
	CSysNetInterface *p1,*p2;
	p1=(CSysNetInterface *)pV1;
	p2=(CSysNetInterface *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysDeviceIDTypeIndexinSysNetInterface(const void *pV1, const void *pV2)
{
	CSysNetInterface *p1,*p2;
	p1=(CSysNetInterface *)pV1;
	p2=(CSysNetInterface *)pV2;
	switch (compare(p1->DeviceID.getValue(),p2->DeviceID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysObjectIDTypeIndexinSysNetInterface(const void *pV1, const void *pV2)
{
	CSysNetInterface *p1,*p2;
	p1=(CSysNetInterface *)pV1;
	p2=(CSysNetInterface *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetInterface=0;
#endif

CSysNetInterface *CSysNetInterfaceFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetInterface while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetInterface++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetInterface *theSysNetInterface;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetInterface;
}

CSysNetInterface *CSysNetInterfaceFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetInterface++;
#endif
	CSysNetInterface *theSysNetInterface;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetInterface;
}

void CSysNetInterfaceFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetInterface=0;
#endif
CSysNetInterface *CSysNetInterfaceFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetInterface while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetInterface++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetInterface *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByDeviceIDForSysNetInterface=0;
#endif

CSysNetInterface *CSysNetInterfaceFactory::startFindByDeviceID( const CReadOnlyVolumeType& DeviceID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDeviceID of CSysNetInterface while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDeviceID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDeviceID();
	}

	///��¼���еĲ�ѯֵ
	queryDeviceIDInSearchByDeviceID= DeviceID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetInterface++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetInterface *theSysNetInterface;
	compareObject.DeviceID=DeviceID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByDeviceID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetInterface->DeviceID.getValue(),DeviceID.getValue()))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetInterface;
}

CSysNetInterface *CSysNetInterfaceFactory::findNextByDeviceID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetInterface++;
#endif
	CSysNetInterface *theSysNetInterface;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->getNextNode(pLastFoundInSearchByDeviceID);
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	theSysNetInterface=(CSysNetInterface *)(pLastFoundInSearchByDeviceID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetInterface->DeviceID,queryDeviceIDInSearchByDeviceID))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetInterface;
}

void CSysNetInterfaceFactory::endFindByDeviceID(void)
{
	pLastFoundInSearchByDeviceID=NULL;
}


#ifdef COUNT_SEARCH
int findByObjectIDForSysNetInterface=0;
#endif
CSysNetInterface *CSysNetInterfaceFactory::findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByObjectID of CSysNetInterface while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByObjectIDForSysNetInterface++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	pNode=pSysObjectIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetInterface *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetGeneralOID(const void *pV1, const void *pV2)
{
	CSysNetGeneralOID *p1,*p2;
	p1=(CSysNetGeneralOID *)pV1;
	p2=(CSysNetGeneralOID *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetGeneralOID=0;
#endif

CSysNetGeneralOID *CSysNetGeneralOIDFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetGeneralOID while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGeneralOID++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetGeneralOID *theSysNetGeneralOID;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetGeneralOID=(CSysNetGeneralOID *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetGeneralOID;
}

CSysNetGeneralOID *CSysNetGeneralOIDFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetGeneralOID++;
#endif
	CSysNetGeneralOID *theSysNetGeneralOID;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetGeneralOID=(CSysNetGeneralOID *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetGeneralOID;
}

void CSysNetGeneralOIDFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetGeneralOID=0;
#endif
CSysNetGeneralOID *CSysNetGeneralOIDFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetGeneralOID while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetGeneralOID++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetGeneralOID *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorType(const void *pV1, const void *pV2)
{
	CSysNetMonitorType *p1,*p2;
	p1=(CSysNetMonitorType *)pV1;
	p2=(CSysNetMonitorType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorType=0;
#endif

CSysNetMonitorType *CSysNetMonitorTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorType while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorType++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorType *theSysNetMonitorType;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorType=(CSysNetMonitorType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorType;
}

CSysNetMonitorType *CSysNetMonitorTypeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorType++;
#endif
	CSysNetMonitorType *theSysNetMonitorType;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorType=(CSysNetMonitorType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorType;
}

void CSysNetMonitorTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorType=0;
#endif
CSysNetMonitorType *CSysNetMonitorTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorAttrScope(const void *pV1, const void *pV2)
{
	CSysNetMonitorAttrScope *p1,*p2;
	p1=(CSysNetMonitorAttrScope *)pV1;
	p2=(CSysNetMonitorAttrScope *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorAttrScope=0;
#endif

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorAttrScope while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrScope++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorAttrScope *theSysNetMonitorAttrScope;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorAttrScope=(CSysNetMonitorAttrScope *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorAttrScope;
}

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrScope++;
#endif
	CSysNetMonitorAttrScope *theSysNetMonitorAttrScope;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorAttrScope=(CSysNetMonitorAttrScope *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorAttrScope;
}

void CSysNetMonitorAttrScopeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorAttrScope=0;
#endif
CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorAttrScope while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorAttrScope++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorAttrScope *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorAttrType(const void *pV1, const void *pV2)
{
	CSysNetMonitorAttrType *p1,*p2;
	p1=(CSysNetMonitorAttrType *)pV1;
	p2=(CSysNetMonitorAttrType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorAttrType=0;
#endif

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorAttrType while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrType++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorAttrType *theSysNetMonitorAttrType;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorAttrType=(CSysNetMonitorAttrType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorAttrType;
}

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorAttrType++;
#endif
	CSysNetMonitorAttrType *theSysNetMonitorAttrType;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorAttrType=(CSysNetMonitorAttrType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorAttrType;
}

void CSysNetMonitorAttrTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorAttrType=0;
#endif
CSysNetMonitorAttrType *CSysNetMonitorAttrTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorAttrType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorAttrType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorAttrType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorCommandType(const void *pV1, const void *pV2)
{
	CSysNetMonitorCommandType *p1,*p2;
	p1=(CSysNetMonitorCommandType *)pV1;
	p2=(CSysNetMonitorCommandType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorCommandType=0;
#endif

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorCommandType while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorCommandType++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorCommandType *theSysNetMonitorCommandType;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorCommandType=(CSysNetMonitorCommandType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorCommandType;
}

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorCommandType++;
#endif
	CSysNetMonitorCommandType *theSysNetMonitorCommandType;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorCommandType=(CSysNetMonitorCommandType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorCommandType;
}

void CSysNetMonitorCommandTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorCommandType=0;
#endif
CSysNetMonitorCommandType *CSysNetMonitorCommandTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorCommandType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorCommandType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorCommandType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorActionGroup(const void *pV1, const void *pV2)
{
	CSysNetMonitorActionGroup *p1,*p2;
	p1=(CSysNetMonitorActionGroup *)pV1;
	p2=(CSysNetMonitorActionGroup *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorActionGroup=0;
#endif

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorActionGroup while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionGroup++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorActionGroup *theSysNetMonitorActionGroup;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorActionGroup=(CSysNetMonitorActionGroup *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorActionGroup;
}

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionGroup++;
#endif
	CSysNetMonitorActionGroup *theSysNetMonitorActionGroup;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorActionGroup=(CSysNetMonitorActionGroup *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorActionGroup;
}

void CSysNetMonitorActionGroupFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorActionGroup=0;
#endif
CSysNetMonitorActionGroup *CSysNetMonitorActionGroupFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorActionGroup while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorActionGroup++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorActionGroup *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorDeviceGroup(const void *pV1, const void *pV2)
{
	CSysNetMonitorDeviceGroup *p1,*p2;
	p1=(CSysNetMonitorDeviceGroup *)pV1;
	p2=(CSysNetMonitorDeviceGroup *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorDeviceGroup=0;
#endif

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorDeviceGroup while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceGroup++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorDeviceGroup *theSysNetMonitorDeviceGroup;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorDeviceGroup=(CSysNetMonitorDeviceGroup *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorDeviceGroup;
}

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceGroup++;
#endif
	CSysNetMonitorDeviceGroup *theSysNetMonitorDeviceGroup;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorDeviceGroup=(CSysNetMonitorDeviceGroup *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorDeviceGroup;
}

void CSysNetMonitorDeviceGroupFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorDeviceGroup=0;
#endif
CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorDeviceGroup while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorDeviceGroup++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorDeviceGroup *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorTaskInfo(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskInfo *p1,*p2;
	p1=(CSysNetMonitorTaskInfo *)pV1;
	p2=(CSysNetMonitorTaskInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskInfo=0;
#endif

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskInfo *theSysNetMonitorTaskInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskInfo=(CSysNetMonitorTaskInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskInfo;
}

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInfo++;
#endif
	CSysNetMonitorTaskInfo *theSysNetMonitorTaskInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskInfo=(CSysNetMonitorTaskInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskInfo;
}

void CSysNetMonitorTaskInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorTaskInfo=0;
#endif
CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorTaskInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorTaskInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorTaskInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorTaskObjectSet(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskObjectSet *p1,*p2;
	p1=(CSysNetMonitorTaskObjectSet *)pV1;
	p2=(CSysNetMonitorTaskObjectSet *)pV2;
	switch (compare(p1->DeviceGroup_ID.getValue(),p2->DeviceGroup_ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskObjectSet=0;
#endif

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskObjectSet while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskObjectSet++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;
	compareObject.DeviceGroup_ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskObjectSet;
}

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskObjectSet++;
#endif
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskObjectSet;
}

void CSysNetMonitorTaskObjectSetFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet=0;
#endif

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::startFindByDeviceGroup_ID( const CReadOnlyVolumeType& DeviceGroup_ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDeviceGroup_ID of CSysNetMonitorTaskObjectSet while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDeviceGroup_ID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDeviceGroup_ID();
	}

	///��¼���еĲ�ѯֵ
	queryDeviceGroup_IDInSearchByDeviceGroup_ID= DeviceGroup_ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;
	compareObject.DeviceGroup_ID=DeviceGroup_ID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDeviceGroup_ID=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDeviceGroup_ID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByDeviceGroup_ID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskObjectSet->DeviceGroup_ID.getValue(),DeviceGroup_ID.getValue()))
	{
		pLastFoundInSearchByDeviceGroup_ID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskObjectSet;
}

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFactory::findNextByDeviceGroup_ID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDeviceGroup_ID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet++;
#endif
	CSysNetMonitorTaskObjectSet *theSysNetMonitorTaskObjectSet;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDeviceGroup_ID=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByDeviceGroup_ID);
	if (pLastFoundInSearchByDeviceGroup_ID==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskObjectSet=(CSysNetMonitorTaskObjectSet *)(pLastFoundInSearchByDeviceGroup_ID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskObjectSet->DeviceGroup_ID,queryDeviceGroup_IDInSearchByDeviceGroup_ID))
	{
		pLastFoundInSearchByDeviceGroup_ID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskObjectSet;
}

void CSysNetMonitorTaskObjectSetFactory::endFindByDeviceGroup_ID(void)
{
	pLastFoundInSearchByDeviceGroup_ID=NULL;
}

int compareForSysTaskIndexinSysNetMonitorTaskResult(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskResult *p1,*p2;
	p1=(CSysNetMonitorTaskResult *)pV1;
	p2=(CSysNetMonitorTaskResult *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->Task_ID.getValue(),p2->Task_ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->OperateTime.getValue(),p2->OperateTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskResult while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskResult++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate="zzzzzzzz";
	compareObject.Task_ID=-10;
	compareObject.ObjectID="";
	compareObject.OperateTime=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysTaskIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByTask_IDForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByTask_ID( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTask_ID of CSysNetMonitorTaskResult while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByTask_ID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTask_ID();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByTask_ID= MonDate.getValue();
	queryTask_IDInSearchByTask_ID= Task_ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByTask_IDForSysNetMonitorTaskResult++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=Task_ID.getValue();
	compareObject.ObjectID="";
	compareObject.OperateTime=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByTask_ID=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByTask_ID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByTask_ID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID.getValue(),Task_ID.getValue()))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByTask_ID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByTask_ID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTask_IDForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByTask_ID=pSysTaskIndex->getNextNode(pLastFoundInSearchByTask_ID);
	if (pLastFoundInSearchByTask_ID==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByTask_ID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByTask_ID))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID,queryTask_IDInSearchByTask_ID))
	{
		pLastFoundInSearchByTask_ID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByTask_ID(void)
{
	pLastFoundInSearchByTask_ID=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByOnlyDateForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByOnlyDate( const CReadOnlyDateType& MonDate)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByOnlyDate of CSysNetMonitorTaskResult while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByOnlyDate!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByOnlyDate();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByOnlyDate= MonDate.getValue();

#ifdef COUNT_SEARCH
	multiFindByOnlyDateForSysNetMonitorTaskResult++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=-10;
	compareObject.ObjectID="";
	compareObject.OperateTime=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByOnlyDate=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByOnlyDate==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByOnlyDate->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByOnlyDate=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByOnlyDate(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByOnlyDate==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByOnlyDateForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByOnlyDate=pSysTaskIndex->getNextNode(pLastFoundInSearchByOnlyDate);
	if (pLastFoundInSearchByOnlyDate==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByOnlyDate->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByOnlyDate))
	{
		pLastFoundInSearchByOnlyDate=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByOnlyDate(void)
{
	pLastFoundInSearchByOnlyDate=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDTaskTimeForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByIDTaskTime( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID,  const CReadOnlyNetObjectIDType& ObjectID,  const CReadOnlyVolumeType& OperateTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDTaskTime of CSysNetMonitorTaskResult while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDTaskTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDTaskTime();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByIDTaskTime= MonDate.getValue();
	queryTask_IDInSearchByIDTaskTime= Task_ID.getValue();
	queryObjectIDInSearchByIDTaskTime= ObjectID.getValue();
	queryOperateTimeInSearchByIDTaskTime= OperateTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTaskTimeForSysNetMonitorTaskResult++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=Task_ID.getValue();
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.OperateTime=OperateTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDTaskTime=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDTaskTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByIDTaskTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID.getValue(),Task_ID.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->OperateTime.getValue(),OperateTime.getValue()))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByIDTaskTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDTaskTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTaskTimeForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDTaskTime=pSysTaskIndex->getNextNode(pLastFoundInSearchByIDTaskTime);
	if (pLastFoundInSearchByIDTaskTime==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByIDTaskTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID,queryTask_IDInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID,queryObjectIDInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->OperateTime,queryOperateTimeInSearchByIDTaskTime))
	{
		pLastFoundInSearchByIDTaskTime=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByIDTaskTime(void)
{
	pLastFoundInSearchByIDTaskTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysNetMonitorTaskResult=0;
#endif

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::startFindByDataDelete( const CReadOnlyDateType& MonDate,  const CReadOnlyVolumeType& Task_ID,  const CReadOnlyNetObjectIDType& ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysNetMonitorTaskResult while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryTask_IDInSearchByDataDelete= Task_ID.getValue();
	queryObjectIDInSearchByDataDelete= ObjectID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysNetMonitorTaskResult++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;
	compareObject.MonDate=MonDate.getValue();
	compareObject.Task_ID=Task_ID.getValue();
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.OperateTime=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pSysTaskIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate.getValue(),MonDate.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID.getValue(),Task_ID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysNetMonitorTaskResult++;
#endif
	CSysNetMonitorTaskResult *theSysNetMonitorTaskResult;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pSysTaskIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskResult=(CSysNetMonitorTaskResult *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorTaskResult->MonDate,queryMonDateInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->Task_ID,queryTask_IDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}
	if (compare(theSysNetMonitorTaskResult->ObjectID,queryObjectIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskResult;
}

void CSysNetMonitorTaskResultFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysIDTypeIndexinSysNetPartyLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetPartyLinkInfo *p1,*p2;
	p1=(CSysNetPartyLinkInfo *)pV1;
	p2=(CSysNetPartyLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPartyLinkInfo=0;
#endif

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPartyLinkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetPartyLinkInfo *theSysNetPartyLinkInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetPartyLinkInfo=(CSysNetPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartyLinkInfo;
}

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkInfo++;
#endif
	CSysNetPartyLinkInfo *theSysNetPartyLinkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPartyLinkInfo=(CSysNetPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartyLinkInfo;
}

void CSysNetPartyLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetPartyLinkInfo=0;
#endif
CSysNetPartyLinkInfo *CSysNetPartyLinkInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetPartyLinkInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetPartyLinkInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetPartyLinkInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetDelPartyLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetDelPartyLinkInfo *p1,*p2;
	p1=(CSysNetDelPartyLinkInfo *)pV1;
	p2=(CSysNetDelPartyLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDelPartyLinkInfo=0;
#endif

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDelPartyLinkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDelPartyLinkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDelPartyLinkInfo *theSysNetDelPartyLinkInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDelPartyLinkInfo=(CSysNetDelPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDelPartyLinkInfo;
}

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDelPartyLinkInfo++;
#endif
	CSysNetDelPartyLinkInfo *theSysNetDelPartyLinkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDelPartyLinkInfo=(CSysNetDelPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDelPartyLinkInfo;
}

void CSysNetDelPartyLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetDelPartyLinkInfo=0;
#endif
CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetDelPartyLinkInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetDelPartyLinkInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetDelPartyLinkInfo *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetPartyLinkAddrChange(const void *pV1, const void *pV2)
{
	CSysNetPartyLinkAddrChange *p1,*p2;
	p1=(CSysNetPartyLinkAddrChange *)pV1;
	p2=(CSysNetPartyLinkAddrChange *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPartyLinkAddrChange=0;
#endif

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPartyLinkAddrChange while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkAddrChange++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetPartyLinkAddrChange *theSysNetPartyLinkAddrChange;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetPartyLinkAddrChange=(CSysNetPartyLinkAddrChange *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartyLinkAddrChange;
}

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartyLinkAddrChange++;
#endif
	CSysNetPartyLinkAddrChange *theSysNetPartyLinkAddrChange;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPartyLinkAddrChange=(CSysNetPartyLinkAddrChange *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartyLinkAddrChange;
}

void CSysNetPartyLinkAddrChangeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetPartyLinkAddrChange=0;
#endif
CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetPartyLinkAddrChange while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetPartyLinkAddrChange++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetPartyLinkAddrChange *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorActionAttr(const void *pV1, const void *pV2)
{
	CSysNetMonitorActionAttr *p1,*p2;
	p1=(CSysNetMonitorActionAttr *)pV1;
	p2=(CSysNetMonitorActionAttr *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorActionAttr=0;
#endif

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorActionAttr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionAttr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorActionAttr *theSysNetMonitorActionAttr;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorActionAttr=(CSysNetMonitorActionAttr *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorActionAttr;
}

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorActionAttr++;
#endif
	CSysNetMonitorActionAttr *theSysNetMonitorActionAttr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorActionAttr=(CSysNetMonitorActionAttr *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorActionAttr;
}

void CSysNetMonitorActionAttrFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetMonitorActionAttr=0;
#endif
CSysNetMonitorActionAttr *CSysNetMonitorActionAttrFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetMonitorActionAttr while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetMonitorActionAttr++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetMonitorActionAttr *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetModule(const void *pV1, const void *pV2)
{
	CSysNetModule *p1,*p2;
	p1=(CSysNetModule *)pV1;
	p2=(CSysNetModule *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysDeviceIDTypeIndexinSysNetModule(const void *pV1, const void *pV2)
{
	CSysNetModule *p1,*p2;
	p1=(CSysNetModule *)pV1;
	p2=(CSysNetModule *)pV2;
	switch (compare(p1->DeviceID.getValue(),p2->DeviceID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForSysObjectIDTypeIndexinSysNetModule(const void *pV1, const void *pV2)
{
	CSysNetModule *p1,*p2;
	p1=(CSysNetModule *)pV1;
	p2=(CSysNetModule *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetModule=0;
#endif

CSysNetModule *CSysNetModuleFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetModule while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetModule++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetModule *theSysNetModule;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetModule;
}

CSysNetModule *CSysNetModuleFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetModule++;
#endif
	CSysNetModule *theSysNetModule;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetModule;
}

void CSysNetModuleFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetModule=0;
#endif
CSysNetModule *CSysNetModuleFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetModule while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetModule++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetModule *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByDeviceIDForSysNetModule=0;
#endif

CSysNetModule *CSysNetModuleFactory::startFindByDeviceID( const CReadOnlyVolumeType& DeviceID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDeviceID of CSysNetModule while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDeviceID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDeviceID();
	}

	///��¼���еĲ�ѯֵ
	queryDeviceIDInSearchByDeviceID= DeviceID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetModule++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetModule *theSysNetModule;
	compareObject.DeviceID=DeviceID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByDeviceID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetModule->DeviceID.getValue(),DeviceID.getValue()))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetModule;
}

CSysNetModule *CSysNetModuleFactory::findNextByDeviceID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDeviceIDForSysNetModule++;
#endif
	CSysNetModule *theSysNetModule;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDeviceID=pSysDeviceIDTypeIndex->getNextNode(pLastFoundInSearchByDeviceID);
	if (pLastFoundInSearchByDeviceID==NULL)
	{
		return NULL;
	}

	theSysNetModule=(CSysNetModule *)(pLastFoundInSearchByDeviceID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetModule->DeviceID,queryDeviceIDInSearchByDeviceID))
	{
		pLastFoundInSearchByDeviceID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetModule;
}

void CSysNetModuleFactory::endFindByDeviceID(void)
{
	pLastFoundInSearchByDeviceID=NULL;
}


#ifdef COUNT_SEARCH
int findByObjectIDForSysNetModule=0;
#endif
CSysNetModule *CSysNetModuleFactory::findByObjectID( const CReadOnlyNetObjectIDType&  ObjectID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByObjectID of CSysNetModule while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByObjectIDForSysNetModule++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	pNode=pSysObjectIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetModule *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetEventExpr(const void *pV1, const void *pV2)
{
	CSysNetEventExpr *p1,*p2;
	p1=(CSysNetEventExpr *)pV1;
	p2=(CSysNetEventExpr *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetEventExpr=0;
#endif

CSysNetEventExpr *CSysNetEventExprFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetEventExpr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventExpr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetEventExpr *theSysNetEventExpr;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetEventExpr=(CSysNetEventExpr *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetEventExpr;
}

CSysNetEventExpr *CSysNetEventExprFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventExpr++;
#endif
	CSysNetEventExpr *theSysNetEventExpr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetEventExpr=(CSysNetEventExpr *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetEventExpr;
}

void CSysNetEventExprFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetEventExpr=0;
#endif
CSysNetEventExpr *CSysNetEventExprFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetEventExpr while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetEventExpr++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetEventExpr *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetEventType(const void *pV1, const void *pV2)
{
	CSysNetEventType *p1,*p2;
	p1=(CSysNetEventType *)pV1;
	p2=(CSysNetEventType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetEventType=0;
#endif

CSysNetEventType *CSysNetEventTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetEventType while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventType++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetEventType *theSysNetEventType;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetEventType=(CSysNetEventType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetEventType;
}

CSysNetEventType *CSysNetEventTypeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventType++;
#endif
	CSysNetEventType *theSysNetEventType;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetEventType=(CSysNetEventType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetEventType;
}

void CSysNetEventTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetEventType=0;
#endif
CSysNetEventType *CSysNetEventTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetEventType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetEventType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetEventType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetSubEventType(const void *pV1, const void *pV2)
{
	CSysNetSubEventType *p1,*p2;
	p1=(CSysNetSubEventType *)pV1;
	p2=(CSysNetSubEventType *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetSubEventType=0;
#endif

CSysNetSubEventType *CSysNetSubEventTypeFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetSubEventType while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubEventType++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetSubEventType *theSysNetSubEventType;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetSubEventType=(CSysNetSubEventType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetSubEventType;
}

CSysNetSubEventType *CSysNetSubEventTypeFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetSubEventType++;
#endif
	CSysNetSubEventType *theSysNetSubEventType;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetSubEventType=(CSysNetSubEventType *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetSubEventType;
}

void CSysNetSubEventTypeFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetSubEventType=0;
#endif
CSysNetSubEventType *CSysNetSubEventTypeFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetSubEventType while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetSubEventType++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetSubEventType *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetEventLevel(const void *pV1, const void *pV2)
{
	CSysNetEventLevel *p1,*p2;
	p1=(CSysNetEventLevel *)pV1;
	p2=(CSysNetEventLevel *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetEventLevel=0;
#endif

CSysNetEventLevel *CSysNetEventLevelFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetEventLevel while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventLevel++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetEventLevel *theSysNetEventLevel;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetEventLevel=(CSysNetEventLevel *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetEventLevel;
}

CSysNetEventLevel *CSysNetEventLevelFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetEventLevel++;
#endif
	CSysNetEventLevel *theSysNetEventLevel;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetEventLevel=(CSysNetEventLevel *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetEventLevel;
}

void CSysNetEventLevelFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetEventLevel=0;
#endif
CSysNetEventLevel *CSysNetEventLevelFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetEventLevel while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetEventLevel++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetEventLevel *)(pNode->pObject);
}


int compareForSysIDTypeIndexinSysNetMonitorDeviceTask(const void *pV1, const void *pV2)
{
	CSysNetMonitorDeviceTask *p1,*p2;
	p1=(CSysNetMonitorDeviceTask *)pV1;
	p2=(CSysNetMonitorDeviceTask *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->SecondID.getValue(),p2->SecondID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorDeviceTask=0;
#endif

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorDeviceTask while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceTask++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;
	compareObject.ID=0;
	compareObject.SecondID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorDeviceTask;
}

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorDeviceTask++;
#endif
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorDeviceTask;
}

void CSysNetMonitorDeviceTaskFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDForSysNetMonitorDeviceTask=0;
#endif

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::startFindByID( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByID of CSysNetMonitorDeviceTask while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByID();
	}

	///��¼���еĲ�ѯֵ
	queryIDInSearchByID= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetMonitorDeviceTask++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;
	compareObject.ID=ID.getValue();
	compareObject.SecondID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByID=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorDeviceTask->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorDeviceTask;
}

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFactory::findNextByID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetMonitorDeviceTask++;
#endif
	CSysNetMonitorDeviceTask *theSysNetMonitorDeviceTask;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByID=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByID);
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	theSysNetMonitorDeviceTask=(CSysNetMonitorDeviceTask *)(pLastFoundInSearchByID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetMonitorDeviceTask->ID,queryIDInSearchByID))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetMonitorDeviceTask;
}

void CSysNetMonitorDeviceTaskFactory::endFindByID(void)
{
	pLastFoundInSearchByID=NULL;
}

int compareForSysIDTypeIndexinSysNetMonitorTaskInstAttrs(const void *pV1, const void *pV2)
{
	CSysNetMonitorTaskInstAttrs *p1,*p2;
	p1=(CSysNetMonitorTaskInstAttrs *)pV1;
	p2=(CSysNetMonitorTaskInstAttrs *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMonitorTaskInstAttrs=0;
#endif

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMonitorTaskInstAttrs while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInstAttrs++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMonitorTaskInstAttrs *theSysNetMonitorTaskInstAttrs;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMonitorTaskInstAttrs=(CSysNetMonitorTaskInstAttrs *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskInstAttrs;
}

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMonitorTaskInstAttrs++;
#endif
	CSysNetMonitorTaskInstAttrs *theSysNetMonitorTaskInstAttrs;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMonitorTaskInstAttrs=(CSysNetMonitorTaskInstAttrs *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMonitorTaskInstAttrs;
}

void CSysNetMonitorTaskInstAttrsFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetBaseLine(const void *pV1, const void *pV2)
{
	CSysNetBaseLine *p1,*p2;
	p1=(CSysNetBaseLine *)pV1;
	p2=(CSysNetBaseLine *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetBaseLine=0;
#endif

CSysNetBaseLine *CSysNetBaseLineFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetBaseLine while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLine++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetBaseLine *theSysNetBaseLine;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetBaseLine;
}

CSysNetBaseLine *CSysNetBaseLineFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLine++;
#endif
	CSysNetBaseLine *theSysNetBaseLine;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetBaseLine;
}

void CSysNetBaseLineFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDForSysNetBaseLine=0;
#endif

CSysNetBaseLine *CSysNetBaseLineFactory::startFindByID( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByID of CSysNetBaseLine while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByID();
	}

	///��¼���еĲ�ѯֵ
	queryIDInSearchByID= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetBaseLine++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetBaseLine *theSysNetBaseLine;
	compareObject.ID=ID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByID=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetBaseLine->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetBaseLine;
}

CSysNetBaseLine *CSysNetBaseLineFactory::findNextByID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDForSysNetBaseLine++;
#endif
	CSysNetBaseLine *theSysNetBaseLine;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByID=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByID);
	if (pLastFoundInSearchByID==NULL)
	{
		return NULL;
	}

	theSysNetBaseLine=(CSysNetBaseLine *)(pLastFoundInSearchByID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysNetBaseLine->ID,queryIDInSearchByID))
	{
		pLastFoundInSearchByID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysNetBaseLine;
}

void CSysNetBaseLineFactory::endFindByID(void)
{
	pLastFoundInSearchByID=NULL;
}

int compareForSysIDTypeIndexinSysNetBaseLineTask(const void *pV1, const void *pV2)
{
	CSysNetBaseLineTask *p1,*p2;
	p1=(CSysNetBaseLineTask *)pV1;
	p2=(CSysNetBaseLineTask *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetBaseLineTask=0;
#endif

CSysNetBaseLineTask *CSysNetBaseLineTaskFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetBaseLineTask while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLineTask++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetBaseLineTask *theSysNetBaseLineTask;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetBaseLineTask=(CSysNetBaseLineTask *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetBaseLineTask;
}

CSysNetBaseLineTask *CSysNetBaseLineTaskFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetBaseLineTask++;
#endif
	CSysNetBaseLineTask *theSysNetBaseLineTask;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetBaseLineTask=(CSysNetBaseLineTask *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetBaseLineTask;
}

void CSysNetBaseLineTaskFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysDateTimeIndexinSysMdbNetPartyLinkStatusInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetPartyLinkStatusInfo *p1,*p2;
	p1=(CSysMdbNetPartyLinkStatusInfo *)pV1;
	p2=(CSysMdbNetPartyLinkStatusInfo *)pV2;
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbNetPartyLinkStatusInfo(const void *pV1, const void *pV2)
{
	CSysMdbNetPartyLinkStatusInfo *p1,*p2;
	p1=(CSysMdbNetPartyLinkStatusInfo *)pV1;
	p2=(CSysMdbNetPartyLinkStatusInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByTimeForSysMdbNetPartyLinkStatusInfo=0;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::startFindByTime( const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByTime of CSysMdbNetPartyLinkStatusInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByTime();
	}

	///��¼���еĲ�ѯֵ
	queryMonDateInSearchByTime= MonDate.getValue();
	queryMonTimeInSearchByTime= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByTimeForSysMdbNetPartyLinkStatusInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByTime=pSysDateTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbNetPartyLinkStatusInfo;
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::findNextByTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByTimeForSysMdbNetPartyLinkStatusInfo++;
#endif
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByTime=pSysDateTimeIndex->getNextNode(pLastFoundInSearchByTime);
	if (pLastFoundInSearchByTime==NULL)
	{
		return NULL;
	}

	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbNetPartyLinkStatusInfo;
}

void CSysMdbNetPartyLinkStatusInfoFactory::endFindByTime(void)
{
	pLastFoundInSearchByTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbNetPartyLinkStatusInfo=0;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbNetPartyLinkStatusInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetPartyLinkStatusInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetPartyLinkStatusInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetPartyLinkStatusInfo;
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbNetPartyLinkStatusInfo++;
#endif
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbNetPartyLinkStatusInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbNetPartyLinkStatusInfo;
}

void CSysMdbNetPartyLinkStatusInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysMdbNetPartyLinkStatusInfo=0;
#endif

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMdbNetPartyLinkStatusInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbNetPartyLinkStatusInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysDateTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbNetPartyLinkStatusInfo;
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMdbNetPartyLinkStatusInfo++;
#endif
	CSysMdbNetPartyLinkStatusInfo *theSysMdbNetPartyLinkStatusInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysDateTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMdbNetPartyLinkStatusInfo=(CSysMdbNetPartyLinkStatusInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbNetPartyLinkStatusInfo;
}

void CSysMdbNetPartyLinkStatusInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetMemberSDHLineInfo(const void *pV1, const void *pV2)
{
	CSysNetMemberSDHLineInfo *p1,*p2;
	p1=(CSysNetMemberSDHLineInfo *)pV1;
	p2=(CSysNetMemberSDHLineInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetMemberSDHLineInfo=0;
#endif

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetMemberSDHLineInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMemberSDHLineInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetMemberSDHLineInfo *theSysNetMemberSDHLineInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetMemberSDHLineInfo=(CSysNetMemberSDHLineInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMemberSDHLineInfo;
}

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetMemberSDHLineInfo++;
#endif
	CSysNetMemberSDHLineInfo *theSysNetMemberSDHLineInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetMemberSDHLineInfo=(CSysNetMemberSDHLineInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetMemberSDHLineInfo;
}

void CSysNetMemberSDHLineInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetDDNLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetDDNLinkInfo *p1,*p2;
	p1=(CSysNetDDNLinkInfo *)pV1;
	p2=(CSysNetDDNLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetDDNLinkInfo=0;
#endif

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetDDNLinkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDDNLinkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetDDNLinkInfo *theSysNetDDNLinkInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetDDNLinkInfo=(CSysNetDDNLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDDNLinkInfo;
}

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetDDNLinkInfo++;
#endif
	CSysNetDDNLinkInfo *theSysNetDDNLinkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetDDNLinkInfo=(CSysNetDDNLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetDDNLinkInfo;
}

void CSysNetDDNLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetPseudMemberLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetPseudMemberLinkInfo *p1,*p2;
	p1=(CSysNetPseudMemberLinkInfo *)pV1;
	p2=(CSysNetPseudMemberLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPseudMemberLinkInfo=0;
#endif

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPseudMemberLinkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPseudMemberLinkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetPseudMemberLinkInfo *theSysNetPseudMemberLinkInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetPseudMemberLinkInfo=(CSysNetPseudMemberLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPseudMemberLinkInfo;
}

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPseudMemberLinkInfo++;
#endif
	CSysNetPseudMemberLinkInfo *theSysNetPseudMemberLinkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPseudMemberLinkInfo=(CSysNetPseudMemberLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPseudMemberLinkInfo;
}

void CSysNetPseudMemberLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetOuterDeviceInfo(const void *pV1, const void *pV2)
{
	CSysNetOuterDeviceInfo *p1,*p2;
	p1=(CSysNetOuterDeviceInfo *)pV1;
	p2=(CSysNetOuterDeviceInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetOuterDeviceInfo=0;
#endif

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetOuterDeviceInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOuterDeviceInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetOuterDeviceInfo *theSysNetOuterDeviceInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetOuterDeviceInfo=(CSysNetOuterDeviceInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetOuterDeviceInfo;
}

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetOuterDeviceInfo++;
#endif
	CSysNetOuterDeviceInfo *theSysNetOuterDeviceInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetOuterDeviceInfo=(CSysNetOuterDeviceInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetOuterDeviceInfo;
}

void CSysNetOuterDeviceInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysLocalPingResultInfo(const void *pV1, const void *pV2)
{
	CSysLocalPingResultInfo *p1,*p2;
	p1=(CSysLocalPingResultInfo *)pV1;
	p2=(CSysLocalPingResultInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysLocalPingResultInfo=0;
#endif

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysLocalPingResultInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysLocalPingResultInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysLocalPingResultInfo;
}

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysLocalPingResultInfo++;
#endif
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysLocalPingResultInfo;
}

void CSysLocalPingResultInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysLocalPingResultInfo=0;
#endif

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysLocalPingResultInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///��¼���еĲ�ѯֵ
	queryIDInSearchByIDType= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysLocalPingResultInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;
	compareObject.ID=ID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysLocalPingResultInfo->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysLocalPingResultInfo;
}

CSysLocalPingResultInfo *CSysLocalPingResultInfoFactory::findNextByIDType(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysLocalPingResultInfo++;
#endif
	CSysLocalPingResultInfo *theSysLocalPingResultInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysLocalPingResultInfo=(CSysLocalPingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysLocalPingResultInfo->ID,queryIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysLocalPingResultInfo;
}

void CSysLocalPingResultInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}

int compareForSysIDTypeIndexinSysRomotePingResultInfo(const void *pV1, const void *pV2)
{
	CSysRomotePingResultInfo *p1,*p2;
	p1=(CSysRomotePingResultInfo *)pV1;
	p2=(CSysRomotePingResultInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysRomotePingResultInfo=0;
#endif

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysRomotePingResultInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysRomotePingResultInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysRomotePingResultInfo;
}

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysRomotePingResultInfo++;
#endif
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysRomotePingResultInfo;
}

void CSysRomotePingResultInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByIDTypeForSysRomotePingResultInfo=0;
#endif

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::startFindByIDType( const CReadOnlyVolumeType& ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByIDType of CSysRomotePingResultInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByIDType!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByIDType();
	}

	///��¼���еĲ�ѯֵ
	queryIDInSearchByIDType= ID.getValue();

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysRomotePingResultInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;
	compareObject.ID=ID.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByIDType=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysRomotePingResultInfo->ID.getValue(),ID.getValue()))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysRomotePingResultInfo;
}

CSysRomotePingResultInfo *CSysRomotePingResultInfoFactory::findNextByIDType(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByIDTypeForSysRomotePingResultInfo++;
#endif
	CSysRomotePingResultInfo *theSysRomotePingResultInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByIDType=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByIDType);
	if (pLastFoundInSearchByIDType==NULL)
	{
		return NULL;
	}

	theSysRomotePingResultInfo=(CSysRomotePingResultInfo *)(pLastFoundInSearchByIDType->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysRomotePingResultInfo->ID,queryIDInSearchByIDType))
	{
		pLastFoundInSearchByIDType=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysRomotePingResultInfo;
}

void CSysRomotePingResultInfoFactory::endFindByIDType(void)
{
	pLastFoundInSearchByIDType=NULL;
}

int compareForMemUsrIndexinSysParticTradeOrderStates(const void *pV1, const void *pV2)
{
	CSysParticTradeOrderStates *p1,*p2;
	p1=(CSysParticTradeOrderStates *)pV1;
	p2=(CSysParticTradeOrderStates *)pV2;
	switch (compare(p1->ParticipantID.getValue(),p2->ParticipantID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->UserID.getValue(),p2->UserID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysParticTradeOrderStates=0;
#endif

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysParticTradeOrderStates while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticTradeOrderStates++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;
	compareObject.ParticipantID="";
	compareObject.UserID="";
	compareObject.MonDate="";
	compareObject.MonTime="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pMemUsrIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysParticTradeOrderStates;
}

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysParticTradeOrderStates++;
#endif
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pMemUsrIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysParticTradeOrderStates;
}

void CSysParticTradeOrderStatesFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysParticTradeOrderStates=0;
#endif
CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::findByOne( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyUserIDType&  UserID,  const CReadOnlyDateType&  MonDate,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysParticTradeOrderStates while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysParticTradeOrderStates++;
#endif
	CAVLNode *pNode;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.UserID=UserID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pMemUsrIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysParticTradeOrderStates *)(pNode->pObject);
}



#ifdef COUNT_SEARCH
int multiFindByUserIDForSysParticTradeOrderStates=0;
#endif

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::startFindByUserID( const CReadOnlyParticipantIDType& ParticipantID,  const CReadOnlyUserIDType& UserID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByUserID of CSysParticTradeOrderStates while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByUserID!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByUserID();
	}

	///��¼���еĲ�ѯֵ
	queryParticipantIDInSearchByUserID= ParticipantID.getValue();
	queryUserIDInSearchByUserID= UserID.getValue();
	queryMonDateInSearchByUserID= MonDate.getValue();
	queryMonTimeInSearchByUserID= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByUserIDForSysParticTradeOrderStates++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;
	compareObject.ParticipantID=ParticipantID.getValue();
	compareObject.UserID=UserID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByUserID=pMemUsrIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByUserID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysParticTradeOrderStates->ParticipantID.getValue(),ParticipantID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}
	if (compare(theSysParticTradeOrderStates->UserID.getValue(),UserID.getValue()))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysParticTradeOrderStates;
}

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFactory::findNextByUserID(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByUserIDForSysParticTradeOrderStates++;
#endif
	CSysParticTradeOrderStates *theSysParticTradeOrderStates;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByUserID=pMemUsrIndex->getNextNode(pLastFoundInSearchByUserID);
	if (pLastFoundInSearchByUserID==NULL)
	{
		return NULL;
	}

	theSysParticTradeOrderStates=(CSysParticTradeOrderStates *)(pLastFoundInSearchByUserID->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysParticTradeOrderStates->ParticipantID,queryParticipantIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}
	if (compare(theSysParticTradeOrderStates->UserID,queryUserIDInSearchByUserID))
	{
		pLastFoundInSearchByUserID=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysParticTradeOrderStates;
}

void CSysParticTradeOrderStatesFactory::endFindByUserID(void)
{
	pLastFoundInSearchByUserID=NULL;
}

int compareForSysHostNameIndexinSysMdbRouterInfo(const void *pV1, const void *pV2)
{
	CSysMdbRouterInfo *p1,*p2;
	p1=(CSysMdbRouterInfo *)pV1;
	p2=(CSysMdbRouterInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbRouterInfo(const void *pV1, const void *pV2)
{
	CSysMdbRouterInfo *p1,*p2;
	p1=(CSysMdbRouterInfo *)pV1;
	p2=(CSysMdbRouterInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbRouterInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbRouterInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbRouterInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbRouterInfo->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbRouterInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbRouterInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbRouterInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbRouterInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbRouterInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbRouterInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbRouterInfo=0;
#endif

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbRouterInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbRouterInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbRouterInfo *theSysMdbRouterInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbRouterInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

CSysMdbRouterInfo *CSysMdbRouterInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbRouterInfo++;
#endif
	CSysMdbRouterInfo *theSysMdbRouterInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbRouterInfo=(CSysMdbRouterInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbRouterInfo->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbRouterInfo;
}

void CSysMdbRouterInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbDiskIO(const void *pV1, const void *pV2)
{
	CSysMdbDiskIO *p1,*p2;
	p1=(CSysMdbDiskIO *)pV1;
	p2=(CSysMdbDiskIO *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbDiskIO(const void *pV1, const void *pV2)
{
	CSysMdbDiskIO *p1,*p2;
	p1=(CSysMdbDiskIO *)pV1;
	p2=(CSysMdbDiskIO *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbDiskIO while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbDiskIO++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDiskIO->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDiskIO->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbDiskIO while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDiskIO++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDiskIO->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDiskIO->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbDiskIO while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDiskIO++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbDiskIO=0;
#endif

CSysMdbDiskIO *CSysMdbDiskIOFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbDiskIO while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDiskIO++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbDiskIO *theSysMdbDiskIO;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDiskIO->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

CSysMdbDiskIO *CSysMdbDiskIOFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbDiskIO++;
#endif
	CSysMdbDiskIO *theSysMdbDiskIO;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbDiskIO=(CSysMdbDiskIO *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbDiskIO->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbDiskIO;
}

void CSysMdbDiskIOFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbStatInfo(const void *pV1, const void *pV2)
{
	CSysMdbStatInfo *p1,*p2;
	p1=(CSysMdbStatInfo *)pV1;
	p2=(CSysMdbStatInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbStatInfo(const void *pV1, const void *pV2)
{
	CSysMdbStatInfo *p1,*p2;
	p1=(CSysMdbStatInfo *)pV1;
	p2=(CSysMdbStatInfo *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByHostNameForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindByHostName( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByHostName of CSysMdbStatInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByHostName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByHostName();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByHostName= SubcriberID.getValue();
	queryMonDateInSearchByHostName= MonDate.getValue();
	queryMonTimeInSearchByHostName= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbStatInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByHostName=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbStatInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextByHostName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByHostNameForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByHostName=pSysHostNameIndex->getNextNode(pLastFoundInSearchByHostName);
	if (pLastFoundInSearchByHostName==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByHostName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbStatInfo->SubcriberID,querySubcriberIDInSearchByHostName))
	{
		pLastFoundInSearchByHostName=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindByHostName(void)
{
	pLastFoundInSearchByHostName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbStatInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbStatInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbStatInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbStatInfo->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbStatInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbStatInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDataDeleteForSysMdbStatInfo=0;
#endif

CSysMdbStatInfo *CSysMdbStatInfoFactory::startFindByDataDelete( const CReadOnlyVolumeType& SubcriberID,  const CReadOnlyDateType& MonDate,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDataDelete of CSysMdbStatInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDataDelete!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDataDelete();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDataDelete= SubcriberID.getValue();
	queryMonDateInSearchByDataDelete= MonDate.getValue();
	queryMonTimeInSearchByDataDelete= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbStatInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbStatInfo *theSysMdbStatInfo;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate=MonDate.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDataDelete=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbStatInfo->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

CSysMdbStatInfo *CSysMdbStatInfoFactory::findNextByDataDelete(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDataDeleteForSysMdbStatInfo++;
#endif
	CSysMdbStatInfo *theSysMdbStatInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDataDelete=pDecIndex->getNextNode(pLastFoundInSearchByDataDelete);
	if (pLastFoundInSearchByDataDelete==NULL)
	{
		return NULL;
	}

	theSysMdbStatInfo=(CSysMdbStatInfo *)(pLastFoundInSearchByDataDelete->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbStatInfo->SubcriberID,querySubcriberIDInSearchByDataDelete))
	{
		pLastFoundInSearchByDataDelete=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbStatInfo;
}

void CSysMdbStatInfoFactory::endFindByDataDelete(void)
{
	pLastFoundInSearchByDataDelete=NULL;
}

int compareForSysHostNameIndexinSysMdbTradeFrontOrderRttStat(const void *pV1, const void *pV2)
{
	CSysMdbTradeFrontOrderRttStat *p1,*p2;
	p1=(CSysMdbTradeFrontOrderRttStat *)pV1;
	p2=(CSysMdbTradeFrontOrderRttStat *)pV2;
	switch (compare(p1->ObjectID.getValue(),p2->ObjectID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}
int compareForDecIndexinSysMdbTradeFrontOrderRttStat(const void *pV1, const void *pV2)
{
	CSysMdbTradeFrontOrderRttStat *p1,*p2;
	p1=(CSysMdbTradeFrontOrderRttStat *)pV1;
	p2=(CSysMdbTradeFrontOrderRttStat *)pV2;
	switch (compare(p1->SubcriberID.getValue(),p2->SubcriberID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonDate.getValue(),p2->MonDate.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	switch (compare(p1->MonTime.getValue(),p2->MonTime.getValue()))
	{
	case 1:
		return -1;
	case -1:
		return 1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat=0;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::startFindByFrontIndex( const CReadOnlyTypeObjectIDType& ObjectID,  const CReadOnlyTimeType& MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByFrontIndex of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByFrontIndex!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByFrontIndex();
	}

	///��¼���еĲ�ѯֵ
	queryObjectIDInSearchByFrontIndex= ObjectID.getValue();
	queryMonTimeInSearchByFrontIndex= MonTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByFrontIndex=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByFrontIndex==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByFrontIndex->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTradeFrontOrderRttStat->ObjectID.getValue(),ObjectID.getValue()))
	{
		pLastFoundInSearchByFrontIndex=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTradeFrontOrderRttStat;
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findNextByFrontIndex(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByFrontIndex==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat++;
#endif
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByFrontIndex=pSysHostNameIndex->getNextNode(pLastFoundInSearchByFrontIndex);
	if (pLastFoundInSearchByFrontIndex==NULL)
	{
		return NULL;
	}

	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByFrontIndex->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTradeFrontOrderRttStat->ObjectID,queryObjectIDInSearchByFrontIndex))
	{
		pLastFoundInSearchByFrontIndex=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTradeFrontOrderRttStat;
}

void CSysMdbTradeFrontOrderRttStatFactory::endFindByFrontIndex(void)
{
	pLastFoundInSearchByFrontIndex=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByDscForSysMdbTradeFrontOrderRttStat=0;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::startFindByDsc( const CReadOnlyVolumeType& SubcriberID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByDsc of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByDsc!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByDsc();
	}

	///��¼���еĲ�ѯֵ
	querySubcriberIDInSearchByDsc= SubcriberID.getValue();

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTradeFrontOrderRttStat++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;
	compareObject.SubcriberID=SubcriberID.getValue();
	compareObject.MonDate="zzzzzzzz";
	compareObject.MonTime="zzzzzzzz";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByDsc=pDecIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTradeFrontOrderRttStat->SubcriberID.getValue(),SubcriberID.getValue()))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTradeFrontOrderRttStat;
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findNextByDsc(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByDscForSysMdbTradeFrontOrderRttStat++;
#endif
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByDsc=pDecIndex->getNextNode(pLastFoundInSearchByDsc);
	if (pLastFoundInSearchByDsc==NULL)
	{
		return NULL;
	}

	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchByDsc->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���
	if (compare(theSysMdbTradeFrontOrderRttStat->SubcriberID,querySubcriberIDInSearchByDsc))
	{
		pLastFoundInSearchByDsc=NULL;
		return NULL;
	}

	///�����ҵ��Ľ��
	return theSysMdbTradeFrontOrderRttStat;
}

void CSysMdbTradeFrontOrderRttStatFactory::endFindByDsc(void)
{
	pLastFoundInSearchByDsc=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMdbTradeFrontOrderRttStat=0;
#endif

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTradeFrontOrderRttStat++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;
	compareObject.ObjectID="";
	compareObject.MonTime="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysHostNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTradeFrontOrderRttStat;
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMdbTradeFrontOrderRttStat++;
#endif
	CSysMdbTradeFrontOrderRttStat *theSysMdbTradeFrontOrderRttStat;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysHostNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMdbTradeFrontOrderRttStat=(CSysMdbTradeFrontOrderRttStat *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMdbTradeFrontOrderRttStat;
}

void CSysMdbTradeFrontOrderRttStatFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int findByTheOneForSysMdbTradeFrontOrderRttStat=0;
#endif
CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFactory::findByTheOne( const CReadOnlyTypeObjectIDType&  ObjectID,  const CReadOnlyTimeType&  MonTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByTheOne of CSysMdbTradeFrontOrderRttStat while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByTheOneForSysMdbTradeFrontOrderRttStat++;
#endif
	CAVLNode *pNode;
	compareObject.ObjectID=ObjectID.getValue();
	compareObject.MonTime=MonTime.getValue();
	pNode=pSysHostNameIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysMdbTradeFrontOrderRttStat *)(pNode->pObject);
}


int compareForSysTradeTimeIndexinSysInstrumentStatus(const void *pV1, const void *pV2)
{
	CSysInstrumentStatus *p1,*p2;
	p1=(CSysInstrumentStatus *)pV1;
	p2=(CSysInstrumentStatus *)pV2;
	switch (compare(p1->EnterTime.getValue(),p2->EnterTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysInstrumentStatus=0;
#endif

CSysInstrumentStatus *CSysInstrumentStatusFactory::startFindByActionTime( const CReadOnlyTimeType& EnterTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysInstrumentStatus while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryEnterTimeInSearchByActionTime= EnterTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInstrumentStatus++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysInstrumentStatus *theSysInstrumentStatus;
	compareObject.EnterTime=EnterTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInstrumentStatus;
}

CSysInstrumentStatus *CSysInstrumentStatusFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysInstrumentStatus++;
#endif
	CSysInstrumentStatus *theSysInstrumentStatus;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInstrumentStatus;
}

void CSysInstrumentStatusFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysInstrumentStatus=0;
#endif

CSysInstrumentStatus *CSysInstrumentStatusFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysInstrumentStatus while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysInstrumentStatus++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysInstrumentStatus *theSysInstrumentStatus;
	compareObject.EnterTime="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInstrumentStatus;
}

CSysInstrumentStatus *CSysInstrumentStatusFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysInstrumentStatus++;
#endif
	CSysInstrumentStatus *theSysInstrumentStatus;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysInstrumentStatus=(CSysInstrumentStatus *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysInstrumentStatus;
}

void CSysInstrumentStatusFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysTradeTimeIndexinSysCurrTradingSegmentAttr(const void *pV1, const void *pV2)
{
	CSysCurrTradingSegmentAttr *p1,*p2;
	p1=(CSysCurrTradingSegmentAttr *)pV1;
	p2=(CSysCurrTradingSegmentAttr *)pV2;
	switch (compare(p1->StartTime.getValue(),p2->StartTime.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByActionTimeForSysCurrTradingSegmentAttr=0;
#endif

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::startFindByActionTime( const CReadOnlyTimeType& StartTime)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByActionTime of CSysCurrTradingSegmentAttr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByActionTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByActionTime();
	}

	///��¼���еĲ�ѯֵ
	queryStartTimeInSearchByActionTime= StartTime.getValue();

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysCurrTradingSegmentAttr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;
	compareObject.StartTime=StartTime.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysCurrTradingSegmentAttr;
}

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::findNextByActionTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByActionTimeForSysCurrTradingSegmentAttr++;
#endif
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByActionTime=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchByActionTime);
	if (pLastFoundInSearchByActionTime==NULL)
	{
		return NULL;
	}

	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchByActionTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysCurrTradingSegmentAttr;
}

void CSysCurrTradingSegmentAttrFactory::endFindByActionTime(void)
{
	pLastFoundInSearchByActionTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysCurrTradingSegmentAttr=0;
#endif

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysCurrTradingSegmentAttr while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysCurrTradingSegmentAttr++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;
	compareObject.StartTime="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysCurrTradingSegmentAttr;
}

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysCurrTradingSegmentAttr++;
#endif
	CSysCurrTradingSegmentAttr *theSysCurrTradingSegmentAttr;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysTradeTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysCurrTradingSegmentAttr=(CSysCurrTradingSegmentAttr *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysCurrTradingSegmentAttr;
}

void CSysCurrTradingSegmentAttrFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}

int compareForSysPayTimeIndexinSysMemberLinkCost(const void *pV1, const void *pV2)
{
	CSysMemberLinkCost *p1,*p2;
	p1=(CSysMemberLinkCost *)pV1;
	p2=(CSysMemberLinkCost *)pV2;
	switch (compare(p1->Pay_Date.getValue(),p2->Pay_Date.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByPayTimeForSysMemberLinkCost=0;
#endif

CSysMemberLinkCost *CSysMemberLinkCostFactory::startFindByPayTime( const CReadOnlyCfgNameType& Pay_Date)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByPayTime of CSysMemberLinkCost while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByPayTime!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByPayTime();
	}

	///��¼���еĲ�ѯֵ
	queryPay_DateInSearchByPayTime= Pay_Date.getValue();

#ifdef COUNT_SEARCH
	multiFindByPayTimeForSysMemberLinkCost++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMemberLinkCost *theSysMemberLinkCost;
	compareObject.Pay_Date=Pay_Date.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByPayTime=pSysPayTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByPayTime==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByPayTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMemberLinkCost;
}

CSysMemberLinkCost *CSysMemberLinkCostFactory::findNextByPayTime(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByPayTime==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByPayTimeForSysMemberLinkCost++;
#endif
	CSysMemberLinkCost *theSysMemberLinkCost;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByPayTime=pSysPayTimeIndex->getNextNode(pLastFoundInSearchByPayTime);
	if (pLastFoundInSearchByPayTime==NULL)
	{
		return NULL;
	}

	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByPayTime->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMemberLinkCost;
}

void CSysMemberLinkCostFactory::endFindByPayTime(void)
{
	pLastFoundInSearchByPayTime=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysMemberLinkCost=0;
#endif

CSysMemberLinkCost *CSysMemberLinkCostFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysMemberLinkCost while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMemberLinkCost++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMemberLinkCost *theSysMemberLinkCost;
	compareObject.Pay_Date="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysPayTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMemberLinkCost;
}

CSysMemberLinkCost *CSysMemberLinkCostFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysMemberLinkCost++;
#endif
	CSysMemberLinkCost *theSysMemberLinkCost;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysPayTimeIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMemberLinkCost;
}

void CSysMemberLinkCostFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysMemberLinkCost=0;
#endif

CSysMemberLinkCost *CSysMemberLinkCostFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysMemberLinkCost while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysMemberLinkCost++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysMemberLinkCost *theSysMemberLinkCost;
	compareObject.Pay_Date="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysPayTimeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMemberLinkCost;
}

CSysMemberLinkCost *CSysMemberLinkCostFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysMemberLinkCost++;
#endif
	CSysMemberLinkCost *theSysMemberLinkCost;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysPayTimeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysMemberLinkCost=(CSysMemberLinkCost *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysMemberLinkCost;
}

void CSysMemberLinkCostFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysLineNameIndexinSysNetPartylinkMonthlyRent(const void *pV1, const void *pV2)
{
	CSysNetPartylinkMonthlyRent *p1,*p2;
	p1=(CSysNetPartylinkMonthlyRent *)pV1;
	p2=(CSysNetPartylinkMonthlyRent *)pV2;
	switch (compare(p1->LineName.getValue(),p2->LineName.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByLineNameForSysNetPartylinkMonthlyRent=0;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::startFindByLineName( const CReadOnlyParticipantNameType& LineName)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByLineName of CSysNetPartylinkMonthlyRent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByLineName!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByLineName();
	}

	///��¼���еĲ�ѯֵ
	queryLineNameInSearchByLineName= LineName.getValue();

#ifdef COUNT_SEARCH
	multiFindByLineNameForSysNetPartylinkMonthlyRent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;
	compareObject.LineName=LineName.getValue();
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByLineName=pSysLineNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByLineName==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByLineName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartylinkMonthlyRent;
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::findNextByLineName(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByLineName==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByLineNameForSysNetPartylinkMonthlyRent++;
#endif
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByLineName=pSysLineNameIndex->getNextNode(pLastFoundInSearchByLineName);
	if (pLastFoundInSearchByLineName==NULL)
	{
		return NULL;
	}

	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByLineName->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartylinkMonthlyRent;
}

void CSysNetPartylinkMonthlyRentFactory::endFindByLineName(void)
{
	pLastFoundInSearchByLineName=NULL;
}


#ifdef COUNT_SEARCH
int multiFindBytheAllForSysNetPartylinkMonthlyRent=0;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::startFindBytheAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindBytheAll of CSysNetPartylinkMonthlyRent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchBytheAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindBytheAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysNetPartylinkMonthlyRent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;
	compareObject.LineName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchBytheAll=pSysLineNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartylinkMonthlyRent;
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::findNextBytheAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindBytheAllForSysNetPartylinkMonthlyRent++;
#endif
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchBytheAll=pSysLineNameIndex->getNextNode(pLastFoundInSearchBytheAll);
	if (pLastFoundInSearchBytheAll==NULL)
	{
		return NULL;
	}

	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchBytheAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartylinkMonthlyRent;
}

void CSysNetPartylinkMonthlyRentFactory::endFindBytheAll(void)
{
	pLastFoundInSearchBytheAll=NULL;
}


#ifdef COUNT_SEARCH
int multiFindByAllForSysNetPartylinkMonthlyRent=0;
#endif

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetPartylinkMonthlyRent while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartylinkMonthlyRent++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;
	compareObject.LineName="";
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysLineNameIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartylinkMonthlyRent;
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetPartylinkMonthlyRent++;
#endif
	CSysNetPartylinkMonthlyRent *theSysNetPartylinkMonthlyRent;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysLineNameIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetPartylinkMonthlyRent=(CSysNetPartylinkMonthlyRent *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetPartylinkMonthlyRent;
}

void CSysNetPartylinkMonthlyRentFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}

int compareForSysIDTypeIndexinSysNetNonPartyLinkInfo(const void *pV1, const void *pV2)
{
	CSysNetNonPartyLinkInfo *p1,*p2;
	p1=(CSysNetNonPartyLinkInfo *)pV1;
	p2=(CSysNetNonPartyLinkInfo *)pV2;
	switch (compare(p1->ID.getValue(),p2->ID.getValue()))
	{
	case 1:
		return 1;
	case -1:
		return -1;
	case 0:
	default:
		break;
	}
	return 0;
}

#ifdef COUNT_SEARCH
int multiFindByAllForSysNetNonPartyLinkInfo=0;
#endif

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoFactory::startFindByAll()
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use startFindByAll of CSysNetNonPartyLinkInfo while run level < 0");
	}
	///���ԭ�����ڲ�ѯ���Ͳ����ٴο�ʼ��ѯ�ˣ������������
	if (pLastFoundInSearchByAll!=NULL)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","start a new find before the end of another one");
		endFindByAll();
	}

	///��¼���еĲ�ѯֵ

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetNonPartyLinkInfo++;
#endif
	///���ݲ�����ȱʡֵ���������ڱȽϵĶ���ĸ�������
	CSysNetNonPartyLinkInfo *theSysNetNonPartyLinkInfo;
	compareObject.ID=0;
	
	///��������Ѱ�ҵ�һ������������
	pLastFoundInSearchByAll=pSysIDTypeIndex->searchFirstGreatEqual(&compareObject);
	
	///���û���ҵ����򷵻�
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	///��ȡ�ҵ��Ķ���
	theSysNetNonPartyLinkInfo=(CSysNetNonPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetNonPartyLinkInfo;
}

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoFactory::findNextByAll(void)
{
	///��û�п�ʼ���ң������Ѿ��ҵ����һ���ˣ�����������
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

#ifdef COUNT_SEARCH
	multiFindByAllForSysNetNonPartyLinkInfo++;
#endif
	CSysNetNonPartyLinkInfo *theSysNetNonPartyLinkInfo;

	///����һ���ڵ㣬���û�У�����ҽ���
	pLastFoundInSearchByAll=pSysIDTypeIndex->getNextNode(pLastFoundInSearchByAll);
	if (pLastFoundInSearchByAll==NULL)
	{
		return NULL;
	}

	theSysNetNonPartyLinkInfo=(CSysNetNonPartyLinkInfo *)(pLastFoundInSearchByAll->pObject);
	
	///�����һ�����������㣬��ʧ�ܷ���

	///�����ҵ��Ľ��
	return theSysNetNonPartyLinkInfo;
}

void CSysNetNonPartyLinkInfoFactory::endFindByAll(void)
{
	pLastFoundInSearchByAll=NULL;
}


#ifdef COUNT_SEARCH
int findByOneForSysNetNonPartyLinkInfo=0;
#endif
CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoFactory::findByOne( const CReadOnlyVolumeType&  ID)
{
	if (runLevel<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"InternalError","Can not use findByOne of CSysNetNonPartyLinkInfo while run level < 0");
	}
#ifdef COUNT_SEARCH
	findByOneForSysNetNonPartyLinkInfo++;
#endif
	CAVLNode *pNode;
	compareObject.ID=ID.getValue();
	pNode=pSysIDTypeIndex->searchFirstEqual(&compareObject);
	if (pNode==NULL)
	{
		return NULL;
	}
	return (CSysNetNonPartyLinkInfo *)(pNode->pObject);
}


#ifdef COUNT_SEARCH
void showAllSearchCount(void)
{
	printf("\n");
	if (multiFindByActionTimeForSysInvalidateOrder !=0)
	{
		printf("\tmultiFindByActionTimeForSysInvalidateOrder:%d\n",multiFindByActionTimeForSysInvalidateOrder);
	}
	if (multiFindByActionTimeForSysOrderStatus !=0)
	{
		printf("\tmultiFindByActionTimeForSysOrderStatus:%d\n",multiFindByActionTimeForSysOrderStatus);
	}
	if (multiFindByActionTimeForSysBargainOrder !=0)
	{
		printf("\tmultiFindByActionTimeForSysBargainOrder:%d\n",multiFindByActionTimeForSysBargainOrder);
	}
	if (multiFindByAllForSysInstProperty !=0)
	{
		printf("\tmultiFindByAllForSysInstProperty:%d\n",multiFindByAllForSysInstProperty);
	}
	if (findByOneForSysInstProperty !=0)
	{
		printf("\tfindByOneForSysInstProperty:%d\n",findByOneForSysInstProperty);
	}
	if (multiFindByAllForSysMarginRate !=0)
	{
		printf("\tmultiFindByAllForSysMarginRate:%d\n",multiFindByAllForSysMarginRate);
	}
	if (findByOneForSysMarginRate !=0)
	{
		printf("\tfindByOneForSysMarginRate:%d\n",findByOneForSysMarginRate);
	}
	if (multiFindByAllForSysPriceLimit !=0)
	{
		printf("\tmultiFindByAllForSysPriceLimit:%d\n",multiFindByAllForSysPriceLimit);
	}
	if (findByOneForSysPriceLimit !=0)
	{
		printf("\tfindByOneForSysPriceLimit:%d\n",findByOneForSysPriceLimit);
	}
	if (multiFindByAllForSysPartPosiLimit !=0)
	{
		printf("\tmultiFindByAllForSysPartPosiLimit:%d\n",multiFindByAllForSysPartPosiLimit);
	}
	if (findByOneForSysPartPosiLimit !=0)
	{
		printf("\tfindByOneForSysPartPosiLimit:%d\n",findByOneForSysPartPosiLimit);
	}
	if (multiFindByAllForSysClientPosiLimit !=0)
	{
		printf("\tmultiFindByAllForSysClientPosiLimit:%d\n",multiFindByAllForSysClientPosiLimit);
	}
	if (findByOneForSysClientPosiLimit !=0)
	{
		printf("\tfindByOneForSysClientPosiLimit:%d\n",findByOneForSysClientPosiLimit);
	}
	if (multiFindByAllForSysSpecialPosiLimit !=0)
	{
		printf("\tmultiFindByAllForSysSpecialPosiLimit:%d\n",multiFindByAllForSysSpecialPosiLimit);
	}
	if (findByOneForSysSpecialPosiLimit !=0)
	{
		printf("\tfindByOneForSysSpecialPosiLimit:%d\n",findByOneForSysSpecialPosiLimit);
	}
	if (multiFindByActionTimeForSysTransactionChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysTransactionChg:%d\n",multiFindByActionTimeForSysTransactionChg);
	}
	if (multiFindByActionTimeForSysClientChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysClientChg:%d\n",multiFindByActionTimeForSysClientChg);
	}
	if (multiFindByActionTimeForSysPartClientChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysPartClientChg:%d\n",multiFindByActionTimeForSysPartClientChg);
	}
	if (multiFindByActionTimeForSysPosiLimitChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysPosiLimitChg:%d\n",multiFindByActionTimeForSysPosiLimitChg);
	}
	if (multiFindByActionTimeForSysClientPosiLimitChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysClientPosiLimitChg:%d\n",multiFindByActionTimeForSysClientPosiLimitChg);
	}
	if (multiFindByActionTimeForSysSpecPosiLimitChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysSpecPosiLimitChg:%d\n",multiFindByActionTimeForSysSpecPosiLimitChg);
	}
	if (multiFindByActionTimeForSysHedgeDetailChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysHedgeDetailChg:%d\n",multiFindByActionTimeForSysHedgeDetailChg);
	}
	if (multiFindByActionTimeForSysParticipantChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysParticipantChg:%d\n",multiFindByActionTimeForSysParticipantChg);
	}
	if (multiFindByActionTimeForSysMarginRateChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysMarginRateChg:%d\n",multiFindByActionTimeForSysMarginRateChg);
	}
	if (multiFindByActionTimeForSysUserIpChg !=0)
	{
		printf("\tmultiFindByActionTimeForSysUserIpChg:%d\n",multiFindByActionTimeForSysUserIpChg);
	}
	if (multiFindByAllForSysPartTrade !=0)
	{
		printf("\tmultiFindByAllForSysPartTrade:%d\n",multiFindByAllForSysPartTrade);
	}
	if (findByOneForSysPartTrade !=0)
	{
		printf("\tfindByOneForSysPartTrade:%d\n",findByOneForSysPartTrade);
	}
	if (multiFindByIDTypeForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbObjectAttr:%d\n",multiFindByIDTypeForSysMdbObjectAttr);
	}
	if (multiFindByDscForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindByDscForSysMdbObjectAttr:%d\n",multiFindByDscForSysMdbObjectAttr);
	}
	if (findByOneForSysMdbObjectAttr !=0)
	{
		printf("\tfindByOneForSysMdbObjectAttr:%d\n",findByOneForSysMdbObjectAttr);
	}
	if (multiFindBytheAllForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbObjectAttr:%d\n",multiFindBytheAllForSysMdbObjectAttr);
	}
	if (multiFindByDataDeleteForSysMdbObjectAttr !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbObjectAttr:%d\n",multiFindByDataDeleteForSysMdbObjectAttr);
	}
	if (multiFindByAllForSysMdbSyslogInfo !=0)
	{
		printf("\tmultiFindByAllForSysMdbSyslogInfo:%d\n",multiFindByAllForSysMdbSyslogInfo);
	}
	if (multiFindBytheAllForSysMdbSyslogInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbSyslogInfo:%d\n",multiFindBytheAllForSysMdbSyslogInfo);
	}
	if (multiFindByDataDeleteForSysMdbSyslogInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbSyslogInfo:%d\n",multiFindByDataDeleteForSysMdbSyslogInfo);
	}
	if (multiFindByHostNameForSysUserInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysUserInfo:%d\n",multiFindByHostNameForSysUserInfo);
	}
	if (multiFindBytheAllForSysUserInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysUserInfo:%d\n",multiFindBytheAllForSysUserInfo);
	}
	if (multiFindByDscForSysUserInfo !=0)
	{
		printf("\tmultiFindByDscForSysUserInfo:%d\n",multiFindByDscForSysUserInfo);
	}
	if (multiFindByHostNameForSysOnlineUserInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysOnlineUserInfo:%d\n",multiFindByHostNameForSysOnlineUserInfo);
	}
	if (multiFindBytheAllForSysOnlineUserInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysOnlineUserInfo:%d\n",multiFindBytheAllForSysOnlineUserInfo);
	}
	if (multiFindByDscForSysOnlineUserInfo !=0)
	{
		printf("\tmultiFindByDscForSysOnlineUserInfo:%d\n",multiFindByDscForSysOnlineUserInfo);
	}
	if (multiFindByTimeForSysWarningEvent !=0)
	{
		printf("\tmultiFindByTimeForSysWarningEvent:%d\n",multiFindByTimeForSysWarningEvent);
	}
	if (multiFindByAllForSysWarningEvent !=0)
	{
		printf("\tmultiFindByAllForSysWarningEvent:%d\n",multiFindByAllForSysWarningEvent);
	}
	if (findByEvendIDForSysWarningEvent !=0)
	{
		printf("\tfindByEvendIDForSysWarningEvent:%d\n",findByEvendIDForSysWarningEvent);
	}
	if (multiFindByEvendIDsForSysWarningEvent !=0)
	{
		printf("\tmultiFindByEvendIDsForSysWarningEvent:%d\n",multiFindByEvendIDsForSysWarningEvent);
	}
	if (multiFindBytheAllForSysWarningEvent !=0)
	{
		printf("\tmultiFindBytheAllForSysWarningEvent:%d\n",multiFindBytheAllForSysWarningEvent);
	}
	if (multiFindByTimeForSysWarningQuery !=0)
	{
		printf("\tmultiFindByTimeForSysWarningQuery:%d\n",multiFindByTimeForSysWarningQuery);
	}
	if (findByEvendIDForSysWarningQuery !=0)
	{
		printf("\tfindByEvendIDForSysWarningQuery:%d\n",findByEvendIDForSysWarningQuery);
	}
	if (multiFindByTimeForSyslogEvent !=0)
	{
		printf("\tmultiFindByTimeForSyslogEvent:%d\n",multiFindByTimeForSyslogEvent);
	}
	if (multiFindBytheAllForSyslogEvent !=0)
	{
		printf("\tmultiFindBytheAllForSyslogEvent:%d\n",multiFindBytheAllForSyslogEvent);
	}
	if (multiFindByAllForSyslogEvent !=0)
	{
		printf("\tmultiFindByAllForSyslogEvent:%d\n",multiFindByAllForSyslogEvent);
	}
	if (findByEvendIDForSyslogEvent !=0)
	{
		printf("\tfindByEvendIDForSyslogEvent:%d\n",findByEvendIDForSyslogEvent);
	}
	if (multiFindByTimeForSysEventDescrip !=0)
	{
		printf("\tmultiFindByTimeForSysEventDescrip:%d\n",multiFindByTimeForSysEventDescrip);
	}
	if (multiFindBytheAllForSysEventDescrip !=0)
	{
		printf("\tmultiFindBytheAllForSysEventDescrip:%d\n",multiFindBytheAllForSysEventDescrip);
	}
	if (multiFindByAllForSysEventDescrip !=0)
	{
		printf("\tmultiFindByAllForSysEventDescrip:%d\n",multiFindByAllForSysEventDescrip);
	}
	if (findByEvendIDForSysEventDescrip !=0)
	{
		printf("\tfindByEvendIDForSysEventDescrip:%d\n",findByEvendIDForSysEventDescrip);
	}
	if (multiFindByHostNameForRspQryHostEnvCommon !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvCommon:%d\n",multiFindByHostNameForRspQryHostEnvCommon);
	}
	if (multiFindBytheAllForRspQryHostEnvCommon !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvCommon:%d\n",multiFindBytheAllForRspQryHostEnvCommon);
	}
	if (multiFindByHostNameForRspQryHostEnvLan !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvLan:%d\n",multiFindByHostNameForRspQryHostEnvLan);
	}
	if (multiFindBytheAllForRspQryHostEnvLan !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvLan:%d\n",multiFindBytheAllForRspQryHostEnvLan);
	}
	if (multiFindByHostNameForRspQryHostEnvStorage !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvStorage:%d\n",multiFindByHostNameForRspQryHostEnvStorage);
	}
	if (multiFindBytheAllForRspQryHostEnvStorage !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvStorage:%d\n",multiFindBytheAllForRspQryHostEnvStorage);
	}
	if (multiFindByHostNameForRspQryHostEnvIO !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvIO:%d\n",multiFindByHostNameForRspQryHostEnvIO);
	}
	if (multiFindBytheAllForRspQryHostEnvIO !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvIO:%d\n",multiFindBytheAllForRspQryHostEnvIO);
	}
	if (multiFindByHostNameForRspQryHostEnvFS !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvFS:%d\n",multiFindByHostNameForRspQryHostEnvFS);
	}
	if (multiFindBytheAllForRspQryHostEnvFS !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvFS:%d\n",multiFindBytheAllForRspQryHostEnvFS);
	}
	if (multiFindByHostNameForRspQryHostEnvSwap !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvSwap:%d\n",multiFindByHostNameForRspQryHostEnvSwap);
	}
	if (multiFindBytheAllForRspQryHostEnvSwap !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvSwap:%d\n",multiFindBytheAllForRspQryHostEnvSwap);
	}
	if (multiFindByHostNameForRspQryHostEnvLanCfg !=0)
	{
		printf("\tmultiFindByHostNameForRspQryHostEnvLanCfg:%d\n",multiFindByHostNameForRspQryHostEnvLanCfg);
	}
	if (multiFindBytheAllForRspQryHostEnvLanCfg !=0)
	{
		printf("\tmultiFindBytheAllForRspQryHostEnvLanCfg:%d\n",multiFindBytheAllForRspQryHostEnvLanCfg);
	}
	if (multiFindByHostNameForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbTopCpuInfo:%d\n",multiFindByHostNameForSysMdbTopCpuInfo);
	}
	if (multiFindByDscForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbTopCpuInfo:%d\n",multiFindByDscForSysMdbTopCpuInfo);
	}
	if (multiFindBytheAllForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTopCpuInfo:%d\n",multiFindBytheAllForSysMdbTopCpuInfo);
	}
	if (multiFindByDataDeleteForSysMdbTopCpuInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbTopCpuInfo:%d\n",multiFindByDataDeleteForSysMdbTopCpuInfo);
	}
	if (multiFindByHostNameForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbTopMemInfo:%d\n",multiFindByHostNameForSysMdbTopMemInfo);
	}
	if (multiFindByDscForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbTopMemInfo:%d\n",multiFindByDscForSysMdbTopMemInfo);
	}
	if (multiFindBytheAllForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTopMemInfo:%d\n",multiFindBytheAllForSysMdbTopMemInfo);
	}
	if (multiFindByDataDeleteForSysMdbTopMemInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbTopMemInfo:%d\n",multiFindByDataDeleteForSysMdbTopMemInfo);
	}
	if (multiFindByHostNameForSysMdbTopProcessInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbTopProcessInfo:%d\n",multiFindByHostNameForSysMdbTopProcessInfo);
	}
	if (multiFindByDscForSysMdbTopProcessInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbTopProcessInfo:%d\n",multiFindByDscForSysMdbTopProcessInfo);
	}
	if (multiFindBytheAllForSysMdbTopProcessInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTopProcessInfo:%d\n",multiFindBytheAllForSysMdbTopProcessInfo);
	}
	if (multiFindByHostNameForSysMdbFileSystemInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbFileSystemInfo:%d\n",multiFindByHostNameForSysMdbFileSystemInfo);
	}
	if (multiFindByDscForSysMdbFileSystemInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbFileSystemInfo:%d\n",multiFindByDscForSysMdbFileSystemInfo);
	}
	if (multiFindBytheAllForSysMdbFileSystemInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbFileSystemInfo:%d\n",multiFindBytheAllForSysMdbFileSystemInfo);
	}
	if (multiFindByHostNameForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbNetworkInfo:%d\n",multiFindByHostNameForSysMdbNetworkInfo);
	}
	if (multiFindByDscForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbNetworkInfo:%d\n",multiFindByDscForSysMdbNetworkInfo);
	}
	if (multiFindBytheAllForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbNetworkInfo:%d\n",multiFindBytheAllForSysMdbNetworkInfo);
	}
	if (multiFindByDataDeleteForSysMdbNetworkInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbNetworkInfo:%d\n",multiFindByDataDeleteForSysMdbNetworkInfo);
	}
	if (multiFindByAllForSysParticipantInit !=0)
	{
		printf("\tmultiFindByAllForSysParticipantInit:%d\n",multiFindByAllForSysParticipantInit);
	}
	if (findByOneForSysParticipantInit !=0)
	{
		printf("\tfindByOneForSysParticipantInit:%d\n",findByOneForSysParticipantInit);
	}
	if (multiFindByAllForSysUserInit !=0)
	{
		printf("\tmultiFindByAllForSysUserInit:%d\n",multiFindByAllForSysUserInit);
	}
	if (findByOneForSysUserInit !=0)
	{
		printf("\tfindByOneForSysUserInit:%d\n",findByOneForSysUserInit);
	}
	if (multiFindByAllForSysClientInit !=0)
	{
		printf("\tmultiFindByAllForSysClientInit:%d\n",multiFindByAllForSysClientInit);
	}
	if (findByOneForSysClientInit !=0)
	{
		printf("\tfindByOneForSysClientInit:%d\n",findByOneForSysClientInit);
	}
	if (multiFindByAllForSysTradeUserLoginInfo !=0)
	{
		printf("\tmultiFindByAllForSysTradeUserLoginInfo:%d\n",multiFindByAllForSysTradeUserLoginInfo);
	}
	if (findByOneForSysTradeUserLoginInfo !=0)
	{
		printf("\tfindByOneForSysTradeUserLoginInfo:%d\n",findByOneForSysTradeUserLoginInfo);
	}
	if (multiFindByIDTypeForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbWebAppInfo:%d\n",multiFindByIDTypeForSysMdbWebAppInfo);
	}
	if (multiFindByDscForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbWebAppInfo:%d\n",multiFindByDscForSysMdbWebAppInfo);
	}
	if (findByOneForSysMdbWebAppInfo !=0)
	{
		printf("\tfindByOneForSysMdbWebAppInfo:%d\n",findByOneForSysMdbWebAppInfo);
	}
	if (multiFindBytheAllForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbWebAppInfo:%d\n",multiFindBytheAllForSysMdbWebAppInfo);
	}
	if (multiFindByDataDeleteForSysMdbWebAppInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbWebAppInfo:%d\n",multiFindByDataDeleteForSysMdbWebAppInfo);
	}
	if (multiFindByIDTypeForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbMemPoolInfo:%d\n",multiFindByIDTypeForSysMdbMemPoolInfo);
	}
	if (multiFindByDscForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbMemPoolInfo:%d\n",multiFindByDscForSysMdbMemPoolInfo);
	}
	if (findByOneForSysMdbMemPoolInfo !=0)
	{
		printf("\tfindByOneForSysMdbMemPoolInfo:%d\n",findByOneForSysMdbMemPoolInfo);
	}
	if (multiFindBytheAllForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbMemPoolInfo:%d\n",multiFindBytheAllForSysMdbMemPoolInfo);
	}
	if (multiFindByDataDeleteForSysMdbMemPoolInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbMemPoolInfo:%d\n",multiFindByDataDeleteForSysMdbMemPoolInfo);
	}
	if (multiFindByIDTypeForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbConnectorInfo:%d\n",multiFindByIDTypeForSysMdbConnectorInfo);
	}
	if (multiFindByDscForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbConnectorInfo:%d\n",multiFindByDscForSysMdbConnectorInfo);
	}
	if (findByOneForSysMdbConnectorInfo !=0)
	{
		printf("\tfindByOneForSysMdbConnectorInfo:%d\n",findByOneForSysMdbConnectorInfo);
	}
	if (multiFindBytheAllForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbConnectorInfo:%d\n",multiFindBytheAllForSysMdbConnectorInfo);
	}
	if (multiFindByDataDeleteForSysMdbConnectorInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbConnectorInfo:%d\n",multiFindByDataDeleteForSysMdbConnectorInfo);
	}
	if (multiFindByIDTypeForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindByIDTypeForSysMdbDBQuery:%d\n",multiFindByIDTypeForSysMdbDBQuery);
	}
	if (multiFindByDscForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindByDscForSysMdbDBQuery:%d\n",multiFindByDscForSysMdbDBQuery);
	}
	if (findByOneForSysMdbDBQuery !=0)
	{
		printf("\tfindByOneForSysMdbDBQuery:%d\n",findByOneForSysMdbDBQuery);
	}
	if (multiFindBytheAllForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbDBQuery:%d\n",multiFindBytheAllForSysMdbDBQuery);
	}
	if (multiFindByDataDeleteForSysMdbDBQuery !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbDBQuery:%d\n",multiFindByDataDeleteForSysMdbDBQuery);
	}
	if (multiFindByAllForSysNetArea !=0)
	{
		printf("\tmultiFindByAllForSysNetArea:%d\n",multiFindByAllForSysNetArea);
	}
	if (findByOneForSysNetArea !=0)
	{
		printf("\tfindByOneForSysNetArea:%d\n",findByOneForSysNetArea);
	}
	if (multiFindByAllForSysNetSubArea !=0)
	{
		printf("\tmultiFindByAllForSysNetSubArea:%d\n",multiFindByAllForSysNetSubArea);
	}
	if (findByOneForSysNetSubArea !=0)
	{
		printf("\tfindByOneForSysNetSubArea:%d\n",findByOneForSysNetSubArea);
	}
	if (multiFindByAllForSysNetSubAreaIP !=0)
	{
		printf("\tmultiFindByAllForSysNetSubAreaIP:%d\n",multiFindByAllForSysNetSubAreaIP);
	}
	if (findByOneForSysNetSubAreaIP !=0)
	{
		printf("\tfindByOneForSysNetSubAreaIP:%d\n",findByOneForSysNetSubAreaIP);
	}
	if (multiFindByAllForSysNetFuncArea !=0)
	{
		printf("\tmultiFindByAllForSysNetFuncArea:%d\n",multiFindByAllForSysNetFuncArea);
	}
	if (findByOneForSysNetFuncArea !=0)
	{
		printf("\tfindByOneForSysNetFuncArea:%d\n",findByOneForSysNetFuncArea);
	}
	if (multiFindByAllForSysNetDevice !=0)
	{
		printf("\tmultiFindByAllForSysNetDevice:%d\n",multiFindByAllForSysNetDevice);
	}
	if (findByOneForSysNetDevice !=0)
	{
		printf("\tfindByOneForSysNetDevice:%d\n",findByOneForSysNetDevice);
	}
	if (multiFindByIPDECODEForSysNetDevice !=0)
	{
		printf("\tmultiFindByIPDECODEForSysNetDevice:%d\n",multiFindByIPDECODEForSysNetDevice);
	}
	if (multiFindBySubAreaIDForSysNetDevice !=0)
	{
		printf("\tmultiFindBySubAreaIDForSysNetDevice:%d\n",multiFindBySubAreaIDForSysNetDevice);
	}
	if (findByObjectIDForSysNetDevice !=0)
	{
		printf("\tfindByObjectIDForSysNetDevice:%d\n",findByObjectIDForSysNetDevice);
	}
	if (multiFindByAllForSysNetDeviceLinked !=0)
	{
		printf("\tmultiFindByAllForSysNetDeviceLinked:%d\n",multiFindByAllForSysNetDeviceLinked);
	}
	if (findByOneForSysNetDeviceLinked !=0)
	{
		printf("\tfindByOneForSysNetDeviceLinked:%d\n",findByOneForSysNetDeviceLinked);
	}
	if (multiFindByNetObjectIDForSysNetDeviceLinked !=0)
	{
		printf("\tmultiFindByNetObjectIDForSysNetDeviceLinked:%d\n",multiFindByNetObjectIDForSysNetDeviceLinked);
	}
	if (multiFindByLinkNetObjectIDForSysNetDeviceLinked !=0)
	{
		printf("\tmultiFindByLinkNetObjectIDForSysNetDeviceLinked:%d\n",multiFindByLinkNetObjectIDForSysNetDeviceLinked);
	}
	if (multiFindByAllForSysNetOID !=0)
	{
		printf("\tmultiFindByAllForSysNetOID:%d\n",multiFindByAllForSysNetOID);
	}
	if (findByOneForSysNetOID !=0)
	{
		printf("\tfindByOneForSysNetOID:%d\n",findByOneForSysNetOID);
	}
	if (multiFindByAllForSysNetDeviceType !=0)
	{
		printf("\tmultiFindByAllForSysNetDeviceType:%d\n",multiFindByAllForSysNetDeviceType);
	}
	if (findByOneForSysNetDeviceType !=0)
	{
		printf("\tfindByOneForSysNetDeviceType:%d\n",findByOneForSysNetDeviceType);
	}
	if (multiFindByAllForSysNetTimePolicy !=0)
	{
		printf("\tmultiFindByAllForSysNetTimePolicy:%d\n",multiFindByAllForSysNetTimePolicy);
	}
	if (findByOneForSysNetTimePolicy !=0)
	{
		printf("\tfindByOneForSysNetTimePolicy:%d\n",findByOneForSysNetTimePolicy);
	}
	if (multiFindByAllForSysNetGatherTask !=0)
	{
		printf("\tmultiFindByAllForSysNetGatherTask:%d\n",multiFindByAllForSysNetGatherTask);
	}
	if (findByOneForSysNetGatherTask !=0)
	{
		printf("\tfindByOneForSysNetGatherTask:%d\n",findByOneForSysNetGatherTask);
	}
	if (multiFindByNetObjectIDForSysNetGatherTask !=0)
	{
		printf("\tmultiFindByNetObjectIDForSysNetGatherTask:%d\n",multiFindByNetObjectIDForSysNetGatherTask);
	}
	if (multiFindByAllForSysNetDeviceCategory !=0)
	{
		printf("\tmultiFindByAllForSysNetDeviceCategory:%d\n",multiFindByAllForSysNetDeviceCategory);
	}
	if (findByOneForSysNetDeviceCategory !=0)
	{
		printf("\tfindByOneForSysNetDeviceCategory:%d\n",findByOneForSysNetDeviceCategory);
	}
	if (multiFindByAllForSysNetManufactory !=0)
	{
		printf("\tmultiFindByAllForSysNetManufactory:%d\n",multiFindByAllForSysNetManufactory);
	}
	if (findByOneForSysNetManufactory !=0)
	{
		printf("\tfindByOneForSysNetManufactory:%d\n",findByOneForSysNetManufactory);
	}
	if (multiFindByAllForSysNetCommunity !=0)
	{
		printf("\tmultiFindByAllForSysNetCommunity:%d\n",multiFindByAllForSysNetCommunity);
	}
	if (findByOneForSysNetCommunity !=0)
	{
		printf("\tfindByOneForSysNetCommunity:%d\n",findByOneForSysNetCommunity);
	}
	if (multiFindByAllForSysNetPortType !=0)
	{
		printf("\tmultiFindByAllForSysNetPortType:%d\n",multiFindByAllForSysNetPortType);
	}
	if (findByOneForSysNetPortType !=0)
	{
		printf("\tfindByOneForSysNetPortType:%d\n",findByOneForSysNetPortType);
	}
	if (multiFindByAllForSysNetInterface !=0)
	{
		printf("\tmultiFindByAllForSysNetInterface:%d\n",multiFindByAllForSysNetInterface);
	}
	if (findByOneForSysNetInterface !=0)
	{
		printf("\tfindByOneForSysNetInterface:%d\n",findByOneForSysNetInterface);
	}
	if (multiFindByDeviceIDForSysNetInterface !=0)
	{
		printf("\tmultiFindByDeviceIDForSysNetInterface:%d\n",multiFindByDeviceIDForSysNetInterface);
	}
	if (findByObjectIDForSysNetInterface !=0)
	{
		printf("\tfindByObjectIDForSysNetInterface:%d\n",findByObjectIDForSysNetInterface);
	}
	if (multiFindByAllForSysNetGeneralOID !=0)
	{
		printf("\tmultiFindByAllForSysNetGeneralOID:%d\n",multiFindByAllForSysNetGeneralOID);
	}
	if (findByOneForSysNetGeneralOID !=0)
	{
		printf("\tfindByOneForSysNetGeneralOID:%d\n",findByOneForSysNetGeneralOID);
	}
	if (multiFindByAllForSysNetMonitorType !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorType:%d\n",multiFindByAllForSysNetMonitorType);
	}
	if (findByOneForSysNetMonitorType !=0)
	{
		printf("\tfindByOneForSysNetMonitorType:%d\n",findByOneForSysNetMonitorType);
	}
	if (multiFindByAllForSysNetMonitorAttrScope !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorAttrScope:%d\n",multiFindByAllForSysNetMonitorAttrScope);
	}
	if (findByOneForSysNetMonitorAttrScope !=0)
	{
		printf("\tfindByOneForSysNetMonitorAttrScope:%d\n",findByOneForSysNetMonitorAttrScope);
	}
	if (multiFindByAllForSysNetMonitorAttrType !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorAttrType:%d\n",multiFindByAllForSysNetMonitorAttrType);
	}
	if (findByOneForSysNetMonitorAttrType !=0)
	{
		printf("\tfindByOneForSysNetMonitorAttrType:%d\n",findByOneForSysNetMonitorAttrType);
	}
	if (multiFindByAllForSysNetMonitorCommandType !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorCommandType:%d\n",multiFindByAllForSysNetMonitorCommandType);
	}
	if (findByOneForSysNetMonitorCommandType !=0)
	{
		printf("\tfindByOneForSysNetMonitorCommandType:%d\n",findByOneForSysNetMonitorCommandType);
	}
	if (multiFindByAllForSysNetMonitorActionGroup !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorActionGroup:%d\n",multiFindByAllForSysNetMonitorActionGroup);
	}
	if (findByOneForSysNetMonitorActionGroup !=0)
	{
		printf("\tfindByOneForSysNetMonitorActionGroup:%d\n",findByOneForSysNetMonitorActionGroup);
	}
	if (multiFindByAllForSysNetMonitorDeviceGroup !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorDeviceGroup:%d\n",multiFindByAllForSysNetMonitorDeviceGroup);
	}
	if (findByOneForSysNetMonitorDeviceGroup !=0)
	{
		printf("\tfindByOneForSysNetMonitorDeviceGroup:%d\n",findByOneForSysNetMonitorDeviceGroup);
	}
	if (multiFindByAllForSysNetMonitorTaskInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskInfo:%d\n",multiFindByAllForSysNetMonitorTaskInfo);
	}
	if (findByOneForSysNetMonitorTaskInfo !=0)
	{
		printf("\tfindByOneForSysNetMonitorTaskInfo:%d\n",findByOneForSysNetMonitorTaskInfo);
	}
	if (multiFindByAllForSysNetMonitorTaskObjectSet !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskObjectSet:%d\n",multiFindByAllForSysNetMonitorTaskObjectSet);
	}
	if (multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet !=0)
	{
		printf("\tmultiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet:%d\n",multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet);
	}
	if (multiFindByAllForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskResult:%d\n",multiFindByAllForSysNetMonitorTaskResult);
	}
	if (multiFindByTask_IDForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByTask_IDForSysNetMonitorTaskResult:%d\n",multiFindByTask_IDForSysNetMonitorTaskResult);
	}
	if (multiFindByOnlyDateForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByOnlyDateForSysNetMonitorTaskResult:%d\n",multiFindByOnlyDateForSysNetMonitorTaskResult);
	}
	if (multiFindByIDTaskTimeForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByIDTaskTimeForSysNetMonitorTaskResult:%d\n",multiFindByIDTaskTimeForSysNetMonitorTaskResult);
	}
	if (multiFindByDataDeleteForSysNetMonitorTaskResult !=0)
	{
		printf("\tmultiFindByDataDeleteForSysNetMonitorTaskResult:%d\n",multiFindByDataDeleteForSysNetMonitorTaskResult);
	}
	if (multiFindByAllForSysNetPartyLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetPartyLinkInfo:%d\n",multiFindByAllForSysNetPartyLinkInfo);
	}
	if (findByOneForSysNetPartyLinkInfo !=0)
	{
		printf("\tfindByOneForSysNetPartyLinkInfo:%d\n",findByOneForSysNetPartyLinkInfo);
	}
	if (multiFindByAllForSysNetDelPartyLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetDelPartyLinkInfo:%d\n",multiFindByAllForSysNetDelPartyLinkInfo);
	}
	if (findByOneForSysNetDelPartyLinkInfo !=0)
	{
		printf("\tfindByOneForSysNetDelPartyLinkInfo:%d\n",findByOneForSysNetDelPartyLinkInfo);
	}
	if (multiFindByAllForSysNetPartyLinkAddrChange !=0)
	{
		printf("\tmultiFindByAllForSysNetPartyLinkAddrChange:%d\n",multiFindByAllForSysNetPartyLinkAddrChange);
	}
	if (findByOneForSysNetPartyLinkAddrChange !=0)
	{
		printf("\tfindByOneForSysNetPartyLinkAddrChange:%d\n",findByOneForSysNetPartyLinkAddrChange);
	}
	if (multiFindByAllForSysNetMonitorActionAttr !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorActionAttr:%d\n",multiFindByAllForSysNetMonitorActionAttr);
	}
	if (findByOneForSysNetMonitorActionAttr !=0)
	{
		printf("\tfindByOneForSysNetMonitorActionAttr:%d\n",findByOneForSysNetMonitorActionAttr);
	}
	if (multiFindByAllForSysNetModule !=0)
	{
		printf("\tmultiFindByAllForSysNetModule:%d\n",multiFindByAllForSysNetModule);
	}
	if (findByOneForSysNetModule !=0)
	{
		printf("\tfindByOneForSysNetModule:%d\n",findByOneForSysNetModule);
	}
	if (multiFindByDeviceIDForSysNetModule !=0)
	{
		printf("\tmultiFindByDeviceIDForSysNetModule:%d\n",multiFindByDeviceIDForSysNetModule);
	}
	if (findByObjectIDForSysNetModule !=0)
	{
		printf("\tfindByObjectIDForSysNetModule:%d\n",findByObjectIDForSysNetModule);
	}
	if (multiFindByAllForSysNetEventExpr !=0)
	{
		printf("\tmultiFindByAllForSysNetEventExpr:%d\n",multiFindByAllForSysNetEventExpr);
	}
	if (findByOneForSysNetEventExpr !=0)
	{
		printf("\tfindByOneForSysNetEventExpr:%d\n",findByOneForSysNetEventExpr);
	}
	if (multiFindByAllForSysNetEventType !=0)
	{
		printf("\tmultiFindByAllForSysNetEventType:%d\n",multiFindByAllForSysNetEventType);
	}
	if (findByOneForSysNetEventType !=0)
	{
		printf("\tfindByOneForSysNetEventType:%d\n",findByOneForSysNetEventType);
	}
	if (multiFindByAllForSysNetSubEventType !=0)
	{
		printf("\tmultiFindByAllForSysNetSubEventType:%d\n",multiFindByAllForSysNetSubEventType);
	}
	if (findByOneForSysNetSubEventType !=0)
	{
		printf("\tfindByOneForSysNetSubEventType:%d\n",findByOneForSysNetSubEventType);
	}
	if (multiFindByAllForSysNetEventLevel !=0)
	{
		printf("\tmultiFindByAllForSysNetEventLevel:%d\n",multiFindByAllForSysNetEventLevel);
	}
	if (findByOneForSysNetEventLevel !=0)
	{
		printf("\tfindByOneForSysNetEventLevel:%d\n",findByOneForSysNetEventLevel);
	}
	if (multiFindByAllForSysNetMonitorDeviceTask !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorDeviceTask:%d\n",multiFindByAllForSysNetMonitorDeviceTask);
	}
	if (multiFindByIDForSysNetMonitorDeviceTask !=0)
	{
		printf("\tmultiFindByIDForSysNetMonitorDeviceTask:%d\n",multiFindByIDForSysNetMonitorDeviceTask);
	}
	if (multiFindByAllForSysNetMonitorTaskInstAttrs !=0)
	{
		printf("\tmultiFindByAllForSysNetMonitorTaskInstAttrs:%d\n",multiFindByAllForSysNetMonitorTaskInstAttrs);
	}
	if (multiFindByAllForSysNetBaseLine !=0)
	{
		printf("\tmultiFindByAllForSysNetBaseLine:%d\n",multiFindByAllForSysNetBaseLine);
	}
	if (multiFindByIDForSysNetBaseLine !=0)
	{
		printf("\tmultiFindByIDForSysNetBaseLine:%d\n",multiFindByIDForSysNetBaseLine);
	}
	if (multiFindByAllForSysNetBaseLineTask !=0)
	{
		printf("\tmultiFindByAllForSysNetBaseLineTask:%d\n",multiFindByAllForSysNetBaseLineTask);
	}
	if (multiFindByTimeForSysMdbNetPartyLinkStatusInfo !=0)
	{
		printf("\tmultiFindByTimeForSysMdbNetPartyLinkStatusInfo:%d\n",multiFindByTimeForSysMdbNetPartyLinkStatusInfo);
	}
	if (multiFindByDscForSysMdbNetPartyLinkStatusInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbNetPartyLinkStatusInfo:%d\n",multiFindByDscForSysMdbNetPartyLinkStatusInfo);
	}
	if (multiFindByAllForSysMdbNetPartyLinkStatusInfo !=0)
	{
		printf("\tmultiFindByAllForSysMdbNetPartyLinkStatusInfo:%d\n",multiFindByAllForSysMdbNetPartyLinkStatusInfo);
	}
	if (multiFindByAllForSysNetMemberSDHLineInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetMemberSDHLineInfo:%d\n",multiFindByAllForSysNetMemberSDHLineInfo);
	}
	if (multiFindByAllForSysNetDDNLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetDDNLinkInfo:%d\n",multiFindByAllForSysNetDDNLinkInfo);
	}
	if (multiFindByAllForSysNetPseudMemberLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetPseudMemberLinkInfo:%d\n",multiFindByAllForSysNetPseudMemberLinkInfo);
	}
	if (multiFindByAllForSysNetOuterDeviceInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetOuterDeviceInfo:%d\n",multiFindByAllForSysNetOuterDeviceInfo);
	}
	if (multiFindByAllForSysLocalPingResultInfo !=0)
	{
		printf("\tmultiFindByAllForSysLocalPingResultInfo:%d\n",multiFindByAllForSysLocalPingResultInfo);
	}
	if (multiFindByIDTypeForSysLocalPingResultInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysLocalPingResultInfo:%d\n",multiFindByIDTypeForSysLocalPingResultInfo);
	}
	if (multiFindByAllForSysRomotePingResultInfo !=0)
	{
		printf("\tmultiFindByAllForSysRomotePingResultInfo:%d\n",multiFindByAllForSysRomotePingResultInfo);
	}
	if (multiFindByIDTypeForSysRomotePingResultInfo !=0)
	{
		printf("\tmultiFindByIDTypeForSysRomotePingResultInfo:%d\n",multiFindByIDTypeForSysRomotePingResultInfo);
	}
	if (multiFindByAllForSysParticTradeOrderStates !=0)
	{
		printf("\tmultiFindByAllForSysParticTradeOrderStates:%d\n",multiFindByAllForSysParticTradeOrderStates);
	}
	if (findByOneForSysParticTradeOrderStates !=0)
	{
		printf("\tfindByOneForSysParticTradeOrderStates:%d\n",findByOneForSysParticTradeOrderStates);
	}
	if (multiFindByUserIDForSysParticTradeOrderStates !=0)
	{
		printf("\tmultiFindByUserIDForSysParticTradeOrderStates:%d\n",multiFindByUserIDForSysParticTradeOrderStates);
	}
	if (multiFindByHostNameForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbRouterInfo:%d\n",multiFindByHostNameForSysMdbRouterInfo);
	}
	if (multiFindByDscForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbRouterInfo:%d\n",multiFindByDscForSysMdbRouterInfo);
	}
	if (multiFindBytheAllForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbRouterInfo:%d\n",multiFindBytheAllForSysMdbRouterInfo);
	}
	if (multiFindByDataDeleteForSysMdbRouterInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbRouterInfo:%d\n",multiFindByDataDeleteForSysMdbRouterInfo);
	}
	if (multiFindByHostNameForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbDiskIO:%d\n",multiFindByHostNameForSysMdbDiskIO);
	}
	if (multiFindByDscForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindByDscForSysMdbDiskIO:%d\n",multiFindByDscForSysMdbDiskIO);
	}
	if (multiFindBytheAllForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbDiskIO:%d\n",multiFindBytheAllForSysMdbDiskIO);
	}
	if (multiFindByDataDeleteForSysMdbDiskIO !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbDiskIO:%d\n",multiFindByDataDeleteForSysMdbDiskIO);
	}
	if (multiFindByHostNameForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindByHostNameForSysMdbStatInfo:%d\n",multiFindByHostNameForSysMdbStatInfo);
	}
	if (multiFindByDscForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindByDscForSysMdbStatInfo:%d\n",multiFindByDscForSysMdbStatInfo);
	}
	if (multiFindBytheAllForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbStatInfo:%d\n",multiFindBytheAllForSysMdbStatInfo);
	}
	if (multiFindByDataDeleteForSysMdbStatInfo !=0)
	{
		printf("\tmultiFindByDataDeleteForSysMdbStatInfo:%d\n",multiFindByDataDeleteForSysMdbStatInfo);
	}
	if (multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tmultiFindByFrontIndexForSysMdbTradeFrontOrderRttStat:%d\n",multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat);
	}
	if (multiFindByDscForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tmultiFindByDscForSysMdbTradeFrontOrderRttStat:%d\n",multiFindByDscForSysMdbTradeFrontOrderRttStat);
	}
	if (multiFindBytheAllForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tmultiFindBytheAllForSysMdbTradeFrontOrderRttStat:%d\n",multiFindBytheAllForSysMdbTradeFrontOrderRttStat);
	}
	if (findByTheOneForSysMdbTradeFrontOrderRttStat !=0)
	{
		printf("\tfindByTheOneForSysMdbTradeFrontOrderRttStat:%d\n",findByTheOneForSysMdbTradeFrontOrderRttStat);
	}
	if (multiFindByActionTimeForSysInstrumentStatus !=0)
	{
		printf("\tmultiFindByActionTimeForSysInstrumentStatus:%d\n",multiFindByActionTimeForSysInstrumentStatus);
	}
	if (multiFindBytheAllForSysInstrumentStatus !=0)
	{
		printf("\tmultiFindBytheAllForSysInstrumentStatus:%d\n",multiFindBytheAllForSysInstrumentStatus);
	}
	if (multiFindByActionTimeForSysCurrTradingSegmentAttr !=0)
	{
		printf("\tmultiFindByActionTimeForSysCurrTradingSegmentAttr:%d\n",multiFindByActionTimeForSysCurrTradingSegmentAttr);
	}
	if (multiFindBytheAllForSysCurrTradingSegmentAttr !=0)
	{
		printf("\tmultiFindBytheAllForSysCurrTradingSegmentAttr:%d\n",multiFindBytheAllForSysCurrTradingSegmentAttr);
	}
	if (multiFindByPayTimeForSysMemberLinkCost !=0)
	{
		printf("\tmultiFindByPayTimeForSysMemberLinkCost:%d\n",multiFindByPayTimeForSysMemberLinkCost);
	}
	if (multiFindBytheAllForSysMemberLinkCost !=0)
	{
		printf("\tmultiFindBytheAllForSysMemberLinkCost:%d\n",multiFindBytheAllForSysMemberLinkCost);
	}
	if (multiFindByAllForSysMemberLinkCost !=0)
	{
		printf("\tmultiFindByAllForSysMemberLinkCost:%d\n",multiFindByAllForSysMemberLinkCost);
	}
	if (multiFindByLineNameForSysNetPartylinkMonthlyRent !=0)
	{
		printf("\tmultiFindByLineNameForSysNetPartylinkMonthlyRent:%d\n",multiFindByLineNameForSysNetPartylinkMonthlyRent);
	}
	if (multiFindBytheAllForSysNetPartylinkMonthlyRent !=0)
	{
		printf("\tmultiFindBytheAllForSysNetPartylinkMonthlyRent:%d\n",multiFindBytheAllForSysNetPartylinkMonthlyRent);
	}
	if (multiFindByAllForSysNetPartylinkMonthlyRent !=0)
	{
		printf("\tmultiFindByAllForSysNetPartylinkMonthlyRent:%d\n",multiFindByAllForSysNetPartylinkMonthlyRent);
	}
	if (multiFindByAllForSysNetNonPartyLinkInfo !=0)
	{
		printf("\tmultiFindByAllForSysNetNonPartyLinkInfo:%d\n",multiFindByAllForSysNetNonPartyLinkInfo);
	}
	if (findByOneForSysNetNonPartyLinkInfo !=0)
	{
		printf("\tfindByOneForSysNetNonPartyLinkInfo:%d\n",findByOneForSysNetNonPartyLinkInfo);
	}
}

void initAllSearchCount(void)
{
	multiFindByActionTimeForSysInvalidateOrder=0;
	multiFindByActionTimeForSysOrderStatus=0;
	multiFindByActionTimeForSysBargainOrder=0;
	multiFindByAllForSysInstProperty=0;
	findByOneForSysInstProperty=0;
	multiFindByAllForSysMarginRate=0;
	findByOneForSysMarginRate=0;
	multiFindByAllForSysPriceLimit=0;
	findByOneForSysPriceLimit=0;
	multiFindByAllForSysPartPosiLimit=0;
	findByOneForSysPartPosiLimit=0;
	multiFindByAllForSysClientPosiLimit=0;
	findByOneForSysClientPosiLimit=0;
	multiFindByAllForSysSpecialPosiLimit=0;
	findByOneForSysSpecialPosiLimit=0;
	multiFindByActionTimeForSysTransactionChg=0;
	multiFindByActionTimeForSysClientChg=0;
	multiFindByActionTimeForSysPartClientChg=0;
	multiFindByActionTimeForSysPosiLimitChg=0;
	multiFindByActionTimeForSysClientPosiLimitChg=0;
	multiFindByActionTimeForSysSpecPosiLimitChg=0;
	multiFindByActionTimeForSysHedgeDetailChg=0;
	multiFindByActionTimeForSysParticipantChg=0;
	multiFindByActionTimeForSysMarginRateChg=0;
	multiFindByActionTimeForSysUserIpChg=0;
	multiFindByAllForSysPartTrade=0;
	findByOneForSysPartTrade=0;
	multiFindByIDTypeForSysMdbObjectAttr=0;
	multiFindByDscForSysMdbObjectAttr=0;
	findByOneForSysMdbObjectAttr=0;
	multiFindBytheAllForSysMdbObjectAttr=0;
	multiFindByDataDeleteForSysMdbObjectAttr=0;
	multiFindByAllForSysMdbSyslogInfo=0;
	multiFindBytheAllForSysMdbSyslogInfo=0;
	multiFindByDataDeleteForSysMdbSyslogInfo=0;
	multiFindByHostNameForSysUserInfo=0;
	multiFindBytheAllForSysUserInfo=0;
	multiFindByDscForSysUserInfo=0;
	multiFindByHostNameForSysOnlineUserInfo=0;
	multiFindBytheAllForSysOnlineUserInfo=0;
	multiFindByDscForSysOnlineUserInfo=0;
	multiFindByTimeForSysWarningEvent=0;
	multiFindByAllForSysWarningEvent=0;
	findByEvendIDForSysWarningEvent=0;
	multiFindByEvendIDsForSysWarningEvent=0;
	multiFindBytheAllForSysWarningEvent=0;
	multiFindByTimeForSysWarningQuery=0;
	findByEvendIDForSysWarningQuery=0;
	multiFindByTimeForSyslogEvent=0;
	multiFindBytheAllForSyslogEvent=0;
	multiFindByAllForSyslogEvent=0;
	findByEvendIDForSyslogEvent=0;
	multiFindByTimeForSysEventDescrip=0;
	multiFindBytheAllForSysEventDescrip=0;
	multiFindByAllForSysEventDescrip=0;
	findByEvendIDForSysEventDescrip=0;
	multiFindByHostNameForRspQryHostEnvCommon=0;
	multiFindBytheAllForRspQryHostEnvCommon=0;
	multiFindByHostNameForRspQryHostEnvLan=0;
	multiFindBytheAllForRspQryHostEnvLan=0;
	multiFindByHostNameForRspQryHostEnvStorage=0;
	multiFindBytheAllForRspQryHostEnvStorage=0;
	multiFindByHostNameForRspQryHostEnvIO=0;
	multiFindBytheAllForRspQryHostEnvIO=0;
	multiFindByHostNameForRspQryHostEnvFS=0;
	multiFindBytheAllForRspQryHostEnvFS=0;
	multiFindByHostNameForRspQryHostEnvSwap=0;
	multiFindBytheAllForRspQryHostEnvSwap=0;
	multiFindByHostNameForRspQryHostEnvLanCfg=0;
	multiFindBytheAllForRspQryHostEnvLanCfg=0;
	multiFindByHostNameForSysMdbTopCpuInfo=0;
	multiFindByDscForSysMdbTopCpuInfo=0;
	multiFindBytheAllForSysMdbTopCpuInfo=0;
	multiFindByDataDeleteForSysMdbTopCpuInfo=0;
	multiFindByHostNameForSysMdbTopMemInfo=0;
	multiFindByDscForSysMdbTopMemInfo=0;
	multiFindBytheAllForSysMdbTopMemInfo=0;
	multiFindByDataDeleteForSysMdbTopMemInfo=0;
	multiFindByHostNameForSysMdbTopProcessInfo=0;
	multiFindByDscForSysMdbTopProcessInfo=0;
	multiFindBytheAllForSysMdbTopProcessInfo=0;
	multiFindByHostNameForSysMdbFileSystemInfo=0;
	multiFindByDscForSysMdbFileSystemInfo=0;
	multiFindBytheAllForSysMdbFileSystemInfo=0;
	multiFindByHostNameForSysMdbNetworkInfo=0;
	multiFindByDscForSysMdbNetworkInfo=0;
	multiFindBytheAllForSysMdbNetworkInfo=0;
	multiFindByDataDeleteForSysMdbNetworkInfo=0;
	multiFindByAllForSysParticipantInit=0;
	findByOneForSysParticipantInit=0;
	multiFindByAllForSysUserInit=0;
	findByOneForSysUserInit=0;
	multiFindByAllForSysClientInit=0;
	findByOneForSysClientInit=0;
	multiFindByAllForSysTradeUserLoginInfo=0;
	findByOneForSysTradeUserLoginInfo=0;
	multiFindByIDTypeForSysMdbWebAppInfo=0;
	multiFindByDscForSysMdbWebAppInfo=0;
	findByOneForSysMdbWebAppInfo=0;
	multiFindBytheAllForSysMdbWebAppInfo=0;
	multiFindByDataDeleteForSysMdbWebAppInfo=0;
	multiFindByIDTypeForSysMdbMemPoolInfo=0;
	multiFindByDscForSysMdbMemPoolInfo=0;
	findByOneForSysMdbMemPoolInfo=0;
	multiFindBytheAllForSysMdbMemPoolInfo=0;
	multiFindByDataDeleteForSysMdbMemPoolInfo=0;
	multiFindByIDTypeForSysMdbConnectorInfo=0;
	multiFindByDscForSysMdbConnectorInfo=0;
	findByOneForSysMdbConnectorInfo=0;
	multiFindBytheAllForSysMdbConnectorInfo=0;
	multiFindByDataDeleteForSysMdbConnectorInfo=0;
	multiFindByIDTypeForSysMdbDBQuery=0;
	multiFindByDscForSysMdbDBQuery=0;
	findByOneForSysMdbDBQuery=0;
	multiFindBytheAllForSysMdbDBQuery=0;
	multiFindByDataDeleteForSysMdbDBQuery=0;
	multiFindByAllForSysNetArea=0;
	findByOneForSysNetArea=0;
	multiFindByAllForSysNetSubArea=0;
	findByOneForSysNetSubArea=0;
	multiFindByAllForSysNetSubAreaIP=0;
	findByOneForSysNetSubAreaIP=0;
	multiFindByAllForSysNetFuncArea=0;
	findByOneForSysNetFuncArea=0;
	multiFindByAllForSysNetDevice=0;
	findByOneForSysNetDevice=0;
	multiFindByIPDECODEForSysNetDevice=0;
	multiFindBySubAreaIDForSysNetDevice=0;
	findByObjectIDForSysNetDevice=0;
	multiFindByAllForSysNetDeviceLinked=0;
	findByOneForSysNetDeviceLinked=0;
	multiFindByNetObjectIDForSysNetDeviceLinked=0;
	multiFindByLinkNetObjectIDForSysNetDeviceLinked=0;
	multiFindByAllForSysNetOID=0;
	findByOneForSysNetOID=0;
	multiFindByAllForSysNetDeviceType=0;
	findByOneForSysNetDeviceType=0;
	multiFindByAllForSysNetTimePolicy=0;
	findByOneForSysNetTimePolicy=0;
	multiFindByAllForSysNetGatherTask=0;
	findByOneForSysNetGatherTask=0;
	multiFindByNetObjectIDForSysNetGatherTask=0;
	multiFindByAllForSysNetDeviceCategory=0;
	findByOneForSysNetDeviceCategory=0;
	multiFindByAllForSysNetManufactory=0;
	findByOneForSysNetManufactory=0;
	multiFindByAllForSysNetCommunity=0;
	findByOneForSysNetCommunity=0;
	multiFindByAllForSysNetPortType=0;
	findByOneForSysNetPortType=0;
	multiFindByAllForSysNetInterface=0;
	findByOneForSysNetInterface=0;
	multiFindByDeviceIDForSysNetInterface=0;
	findByObjectIDForSysNetInterface=0;
	multiFindByAllForSysNetGeneralOID=0;
	findByOneForSysNetGeneralOID=0;
	multiFindByAllForSysNetMonitorType=0;
	findByOneForSysNetMonitorType=0;
	multiFindByAllForSysNetMonitorAttrScope=0;
	findByOneForSysNetMonitorAttrScope=0;
	multiFindByAllForSysNetMonitorAttrType=0;
	findByOneForSysNetMonitorAttrType=0;
	multiFindByAllForSysNetMonitorCommandType=0;
	findByOneForSysNetMonitorCommandType=0;
	multiFindByAllForSysNetMonitorActionGroup=0;
	findByOneForSysNetMonitorActionGroup=0;
	multiFindByAllForSysNetMonitorDeviceGroup=0;
	findByOneForSysNetMonitorDeviceGroup=0;
	multiFindByAllForSysNetMonitorTaskInfo=0;
	findByOneForSysNetMonitorTaskInfo=0;
	multiFindByAllForSysNetMonitorTaskObjectSet=0;
	multiFindByDeviceGroup_IDForSysNetMonitorTaskObjectSet=0;
	multiFindByAllForSysNetMonitorTaskResult=0;
	multiFindByTask_IDForSysNetMonitorTaskResult=0;
	multiFindByOnlyDateForSysNetMonitorTaskResult=0;
	multiFindByIDTaskTimeForSysNetMonitorTaskResult=0;
	multiFindByDataDeleteForSysNetMonitorTaskResult=0;
	multiFindByAllForSysNetPartyLinkInfo=0;
	findByOneForSysNetPartyLinkInfo=0;
	multiFindByAllForSysNetDelPartyLinkInfo=0;
	findByOneForSysNetDelPartyLinkInfo=0;
	multiFindByAllForSysNetPartyLinkAddrChange=0;
	findByOneForSysNetPartyLinkAddrChange=0;
	multiFindByAllForSysNetMonitorActionAttr=0;
	findByOneForSysNetMonitorActionAttr=0;
	multiFindByAllForSysNetModule=0;
	findByOneForSysNetModule=0;
	multiFindByDeviceIDForSysNetModule=0;
	findByObjectIDForSysNetModule=0;
	multiFindByAllForSysNetEventExpr=0;
	findByOneForSysNetEventExpr=0;
	multiFindByAllForSysNetEventType=0;
	findByOneForSysNetEventType=0;
	multiFindByAllForSysNetSubEventType=0;
	findByOneForSysNetSubEventType=0;
	multiFindByAllForSysNetEventLevel=0;
	findByOneForSysNetEventLevel=0;
	multiFindByAllForSysNetMonitorDeviceTask=0;
	multiFindByIDForSysNetMonitorDeviceTask=0;
	multiFindByAllForSysNetMonitorTaskInstAttrs=0;
	multiFindByAllForSysNetBaseLine=0;
	multiFindByIDForSysNetBaseLine=0;
	multiFindByAllForSysNetBaseLineTask=0;
	multiFindByTimeForSysMdbNetPartyLinkStatusInfo=0;
	multiFindByDscForSysMdbNetPartyLinkStatusInfo=0;
	multiFindByAllForSysMdbNetPartyLinkStatusInfo=0;
	multiFindByAllForSysNetMemberSDHLineInfo=0;
	multiFindByAllForSysNetDDNLinkInfo=0;
	multiFindByAllForSysNetPseudMemberLinkInfo=0;
	multiFindByAllForSysNetOuterDeviceInfo=0;
	multiFindByAllForSysLocalPingResultInfo=0;
	multiFindByIDTypeForSysLocalPingResultInfo=0;
	multiFindByAllForSysRomotePingResultInfo=0;
	multiFindByIDTypeForSysRomotePingResultInfo=0;
	multiFindByAllForSysParticTradeOrderStates=0;
	findByOneForSysParticTradeOrderStates=0;
	multiFindByUserIDForSysParticTradeOrderStates=0;
	multiFindByHostNameForSysMdbRouterInfo=0;
	multiFindByDscForSysMdbRouterInfo=0;
	multiFindBytheAllForSysMdbRouterInfo=0;
	multiFindByDataDeleteForSysMdbRouterInfo=0;
	multiFindByHostNameForSysMdbDiskIO=0;
	multiFindByDscForSysMdbDiskIO=0;
	multiFindBytheAllForSysMdbDiskIO=0;
	multiFindByDataDeleteForSysMdbDiskIO=0;
	multiFindByHostNameForSysMdbStatInfo=0;
	multiFindByDscForSysMdbStatInfo=0;
	multiFindBytheAllForSysMdbStatInfo=0;
	multiFindByDataDeleteForSysMdbStatInfo=0;
	multiFindByFrontIndexForSysMdbTradeFrontOrderRttStat=0;
	multiFindByDscForSysMdbTradeFrontOrderRttStat=0;
	multiFindBytheAllForSysMdbTradeFrontOrderRttStat=0;
	findByTheOneForSysMdbTradeFrontOrderRttStat=0;
	multiFindByActionTimeForSysInstrumentStatus=0;
	multiFindBytheAllForSysInstrumentStatus=0;
	multiFindByActionTimeForSysCurrTradingSegmentAttr=0;
	multiFindBytheAllForSysCurrTradingSegmentAttr=0;
	multiFindByPayTimeForSysMemberLinkCost=0;
	multiFindBytheAllForSysMemberLinkCost=0;
	multiFindByAllForSysMemberLinkCost=0;
	multiFindByLineNameForSysNetPartylinkMonthlyRent=0;
	multiFindBytheAllForSysNetPartylinkMonthlyRent=0;
	multiFindByAllForSysNetPartylinkMonthlyRent=0;
	multiFindByAllForSysNetNonPartyLinkInfo=0;
	findByOneForSysNetNonPartyLinkInfo=0;
}
#endif
