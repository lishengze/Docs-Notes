/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CDumpLog.h
///@brief��������CDumpLog
///@history 
///20041001	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CDUMPLOG_H
#define CDUMPLOG_H

#include "CMemoryDB.h"

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderDumpTrigger�ǲ�����Ч����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderDumpTrigger: public CSysInvalidateOrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysInvalidateOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysInvalidateOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysInvalidateOrder	Ҫ�����SysInvalidateOrder
	virtual void beforeAdd(CWriteableSysInvalidateOrder *pSysInvalidateOrder);
	
	///����ǰ����	
	///@param	pSysInvalidateOrder	��ˢ�µ�CSysInvalidateOrder
	///@param	pNewSysInvalidateOrder	�µ�ֵ
	virtual void beforeUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder);
	
	///ɾ��ǰ����
	///@param	pSysInvalidateOrder	Ҫɾ����CSysInvalidateOrder
	virtual void beforeRemove(CSysInvalidateOrder *pSysInvalidateOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusDumpTrigger�ǲ�������״̬ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusDumpTrigger: public CSysOrderStatusActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysOrderStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysOrderStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysOrderStatus	Ҫ�����SysOrderStatus
	virtual void beforeAdd(CWriteableSysOrderStatus *pSysOrderStatus);
	
	///����ǰ����	
	///@param	pSysOrderStatus	��ˢ�µ�CSysOrderStatus
	///@param	pNewSysOrderStatus	�µ�ֵ
	virtual void beforeUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus);
	
	///ɾ��ǰ����
	///@param	pSysOrderStatus	Ҫɾ����CSysOrderStatus
	virtual void beforeRemove(CSysOrderStatus *pSysOrderStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderDumpTrigger�ǲ��������ɽ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderDumpTrigger: public CSysBargainOrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysBargainOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysBargainOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysBargainOrder	Ҫ�����SysBargainOrder
	virtual void beforeAdd(CWriteableSysBargainOrder *pSysBargainOrder);
	
	///����ǰ����	
	///@param	pSysBargainOrder	��ˢ�µ�CSysBargainOrder
	///@param	pNewSysBargainOrder	�µ�ֵ
	virtual void beforeUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder);
	
	///ɾ��ǰ����
	///@param	pSysBargainOrder	Ҫɾ����CSysBargainOrder
	virtual void beforeRemove(CSysBargainOrder *pSysBargainOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyDumpTrigger�ǲ�����Լ��������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyDumpTrigger: public CSysInstPropertyActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysInstPropertyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysInstPropertyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysInstProperty	Ҫ�����SysInstProperty
	virtual void beforeAdd(CWriteableSysInstProperty *pSysInstProperty);
	
	///����ǰ����	
	///@param	pSysInstProperty	��ˢ�µ�CSysInstProperty
	///@param	pNewSysInstProperty	�µ�ֵ
	virtual void beforeUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty);
	
	///ɾ��ǰ����
	///@param	pSysInstProperty	Ҫɾ����CSysInstProperty
	virtual void beforeRemove(CSysInstProperty *pSysInstProperty);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateDumpTrigger�ǲ�����Լ��֤����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateDumpTrigger: public CSysMarginRateActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMarginRateDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMarginRateDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMarginRate	Ҫ�����SysMarginRate
	virtual void beforeAdd(CWriteableSysMarginRate *pSysMarginRate);
	
	///����ǰ����	
	///@param	pSysMarginRate	��ˢ�µ�CSysMarginRate
	///@param	pNewSysMarginRate	�µ�ֵ
	virtual void beforeUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate);
	
	///ɾ��ǰ����
	///@param	pSysMarginRate	Ҫɾ����CSysMarginRate
	virtual void beforeRemove(CSysMarginRate *pSysMarginRate);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitDumpTrigger�ǲ�����Լ�ǵ�ͣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitDumpTrigger: public CSysPriceLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysPriceLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysPriceLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysPriceLimit	Ҫ�����SysPriceLimit
	virtual void beforeAdd(CWriteableSysPriceLimit *pSysPriceLimit);
	
	///����ǰ����	
	///@param	pSysPriceLimit	��ˢ�µ�CSysPriceLimit
	///@param	pNewSysPriceLimit	�µ�ֵ
	virtual void beforeUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit);
	
	///ɾ��ǰ����
	///@param	pSysPriceLimit	Ҫɾ����CSysPriceLimit
	virtual void beforeRemove(CSysPriceLimit *pSysPriceLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitDumpTrigger�ǲ�����Ա�޲�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitDumpTrigger: public CSysPartPosiLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysPartPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysPartPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysPartPosiLimit	Ҫ�����SysPartPosiLimit
	virtual void beforeAdd(CWriteableSysPartPosiLimit *pSysPartPosiLimit);
	
	///����ǰ����	
	///@param	pSysPartPosiLimit	��ˢ�µ�CSysPartPosiLimit
	///@param	pNewSysPartPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit);
	
	///ɾ��ǰ����
	///@param	pSysPartPosiLimit	Ҫɾ����CSysPartPosiLimit
	virtual void beforeRemove(CSysPartPosiLimit *pSysPartPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitDumpTrigger�ǲ����ͻ��޲�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitDumpTrigger: public CSysClientPosiLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysClientPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysClientPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysClientPosiLimit	Ҫ�����SysClientPosiLimit
	virtual void beforeAdd(CWriteableSysClientPosiLimit *pSysClientPosiLimit);
	
	///����ǰ����	
	///@param	pSysClientPosiLimit	��ˢ�µ�CSysClientPosiLimit
	///@param	pNewSysClientPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit);
	
	///ɾ��ǰ����
	///@param	pSysClientPosiLimit	Ҫɾ����CSysClientPosiLimit
	virtual void beforeRemove(CSysClientPosiLimit *pSysClientPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitDumpTrigger�ǲ�������ͻ��޲�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitDumpTrigger: public CSysSpecialPosiLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysSpecialPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysSpecialPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysSpecialPosiLimit	Ҫ�����SysSpecialPosiLimit
	virtual void beforeAdd(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit);
	
	///����ǰ����	
	///@param	pSysSpecialPosiLimit	��ˢ�µ�CSysSpecialPosiLimit
	///@param	pNewSysSpecialPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit);
	
	///ɾ��ǰ����
	///@param	pSysSpecialPosiLimit	Ҫɾ����CSysSpecialPosiLimit
	virtual void beforeRemove(CSysSpecialPosiLimit *pSysSpecialPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgDumpTrigger�ǲ����˻�������ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgDumpTrigger: public CSysTransactionChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysTransactionChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysTransactionChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysTransactionChg	Ҫ�����SysTransactionChg
	virtual void beforeAdd(CWriteableSysTransactionChg *pSysTransactionChg);
	
	///����ǰ����	
	///@param	pSysTransactionChg	��ˢ�µ�CSysTransactionChg
	///@param	pNewSysTransactionChg	�µ�ֵ
	virtual void beforeUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg);
	
	///ɾ��ǰ����
	///@param	pSysTransactionChg	Ҫɾ����CSysTransactionChg
	virtual void beforeRemove(CSysTransactionChg *pSysTransactionChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgDumpTrigger�ǲ����ͻ����ݱ䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgDumpTrigger: public CSysClientChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysClientChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysClientChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysClientChg	Ҫ�����SysClientChg
	virtual void beforeAdd(CWriteableSysClientChg *pSysClientChg);
	
	///����ǰ����	
	///@param	pSysClientChg	��ˢ�µ�CSysClientChg
	///@param	pNewSysClientChg	�µ�ֵ
	virtual void beforeUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg);
	
	///ɾ��ǰ����
	///@param	pSysClientChg	Ҫɾ����CSysClientChg
	virtual void beforeRemove(CSysClientChg *pSysClientChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgDumpTrigger�ǲ�����Ա�ͻ����ձ䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgDumpTrigger: public CSysPartClientChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysPartClientChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysPartClientChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysPartClientChg	Ҫ�����SysPartClientChg
	virtual void beforeAdd(CWriteableSysPartClientChg *pSysPartClientChg);
	
	///����ǰ����	
	///@param	pSysPartClientChg	��ˢ�µ�CSysPartClientChg
	///@param	pNewSysPartClientChg	�µ�ֵ
	virtual void beforeUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg);
	
	///ɾ��ǰ����
	///@param	pSysPartClientChg	Ҫɾ����CSysPartClientChg
	virtual void beforeRemove(CSysPartClientChg *pSysPartClientChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgDumpTrigger�ǲ����޲����ݱ䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgDumpTrigger: public CSysPosiLimitChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysPosiLimitChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysPosiLimitChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysPosiLimitChg	Ҫ�����SysPosiLimitChg
	virtual void beforeAdd(CWriteableSysPosiLimitChg *pSysPosiLimitChg);
	
	///����ǰ����	
	///@param	pSysPosiLimitChg	��ˢ�µ�CSysPosiLimitChg
	///@param	pNewSysPosiLimitChg	�µ�ֵ
	virtual void beforeUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg);
	
	///ɾ��ǰ����
	///@param	pSysPosiLimitChg	Ҫɾ����CSysPosiLimitChg
	virtual void beforeRemove(CSysPosiLimitChg *pSysPosiLimitChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgDumpTrigger�ǲ����޲����ݱ䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgDumpTrigger: public CSysClientPosiLimitChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysClientPosiLimitChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysClientPosiLimitChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysClientPosiLimitChg	Ҫ�����SysClientPosiLimitChg
	virtual void beforeAdd(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg);
	
	///����ǰ����	
	///@param	pSysClientPosiLimitChg	��ˢ�µ�CSysClientPosiLimitChg
	///@param	pNewSysClientPosiLimitChg	�µ�ֵ
	virtual void beforeUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg);
	
	///ɾ��ǰ����
	///@param	pSysClientPosiLimitChg	Ҫɾ����CSysClientPosiLimitChg
	virtual void beforeRemove(CSysClientPosiLimitChg *pSysClientPosiLimitChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgDumpTrigger�ǲ����޲����ݱ䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgDumpTrigger: public CSysSpecPosiLimitChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysSpecPosiLimitChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysSpecPosiLimitChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysSpecPosiLimitChg	Ҫ�����SysSpecPosiLimitChg
	virtual void beforeAdd(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
	
	///����ǰ����	
	///@param	pSysSpecPosiLimitChg	��ˢ�µ�CSysSpecPosiLimitChg
	///@param	pNewSysSpecPosiLimitChg	�µ�ֵ
	virtual void beforeUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg);
	
	///ɾ��ǰ����
	///@param	pSysSpecPosiLimitChg	Ҫɾ����CSysSpecPosiLimitChg
	virtual void beforeRemove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgDumpTrigger�ǲ�����ֵ��ȱ䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgDumpTrigger: public CSysHedgeDetailChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysHedgeDetailChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysHedgeDetailChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysHedgeDetailChg	Ҫ�����SysHedgeDetailChg
	virtual void beforeAdd(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg);
	
	///����ǰ����	
	///@param	pSysHedgeDetailChg	��ˢ�µ�CSysHedgeDetailChg
	///@param	pNewSysHedgeDetailChg	�µ�ֵ
	virtual void beforeUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg);
	
	///ɾ��ǰ����
	///@param	pSysHedgeDetailChg	Ҫɾ����CSysHedgeDetailChg
	virtual void beforeRemove(CSysHedgeDetailChg *pSysHedgeDetailChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgDumpTrigger�ǲ�����Ա�䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgDumpTrigger: public CSysParticipantChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysParticipantChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysParticipantChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysParticipantChg	Ҫ�����SysParticipantChg
	virtual void beforeAdd(CWriteableSysParticipantChg *pSysParticipantChg);
	
	///����ǰ����	
	///@param	pSysParticipantChg	��ˢ�µ�CSysParticipantChg
	///@param	pNewSysParticipantChg	�µ�ֵ
	virtual void beforeUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg);
	
	///ɾ��ǰ����
	///@param	pSysParticipantChg	Ҫɾ����CSysParticipantChg
	virtual void beforeRemove(CSysParticipantChg *pSysParticipantChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgDumpTrigger�ǲ�����֤���ʱ䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgDumpTrigger: public CSysMarginRateChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMarginRateChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMarginRateChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMarginRateChg	Ҫ�����SysMarginRateChg
	virtual void beforeAdd(CWriteableSysMarginRateChg *pSysMarginRateChg);
	
	///����ǰ����	
	///@param	pSysMarginRateChg	��ˢ�µ�CSysMarginRateChg
	///@param	pNewSysMarginRateChg	�µ�ֵ
	virtual void beforeUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg);
	
	///ɾ��ǰ����
	///@param	pSysMarginRateChg	Ҫɾ����CSysMarginRateChg
	virtual void beforeRemove(CSysMarginRateChg *pSysMarginRateChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgDumpTrigger�ǲ���IP��ַ�䶯��ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgDumpTrigger: public CSysUserIpChgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysUserIpChgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysUserIpChgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysUserIpChg	Ҫ�����SysUserIpChg
	virtual void beforeAdd(CWriteableSysUserIpChg *pSysUserIpChg);
	
	///����ǰ����	
	///@param	pSysUserIpChg	��ˢ�µ�CSysUserIpChg
	///@param	pNewSysUserIpChg	�µ�ֵ
	virtual void beforeUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg);
	
	///ɾ��ǰ����
	///@param	pSysUserIpChg	Ҫɾ����CSysUserIpChg
	virtual void beforeRemove(CSysUserIpChg *pSysUserIpChg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeDumpTrigger�ǲ�����Ա������Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeDumpTrigger: public CSysPartTradeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysPartTradeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysPartTradeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysPartTrade	Ҫ�����SysPartTrade
	virtual void beforeAdd(CWriteableSysPartTrade *pSysPartTrade);
	
	///����ǰ����	
	///@param	pSysPartTrade	��ˢ�µ�CSysPartTrade
	///@param	pNewSysPartTrade	�µ�ֵ
	virtual void beforeUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade);
	
	///ɾ��ǰ����
	///@param	pSysPartTrade	Ҫɾ����CSysPartTrade
	virtual void beforeRemove(CSysPartTrade *pSysPartTrade);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrDumpTrigger�ǲ�������״ָ̬��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrDumpTrigger: public CSysMdbObjectAttrActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbObjectAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbObjectAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbObjectAttr	Ҫ�����SysMdbObjectAttr
	virtual void beforeAdd(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr);
	
	///����ǰ����	
	///@param	pSysMdbObjectAttr	��ˢ�µ�CSysMdbObjectAttr
	///@param	pNewSysMdbObjectAttr	�µ�ֵ
	virtual void beforeUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr);
	
	///ɾ��ǰ����
	///@param	pSysMdbObjectAttr	Ҫɾ����CSysMdbObjectAttr
	virtual void beforeRemove(CSysMdbObjectAttr *pSysMdbObjectAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoDumpTrigger�ǲ�����־�ļ����ݴ�����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoDumpTrigger: public CSysMdbSyslogInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbSyslogInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbSyslogInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbSyslogInfo	Ҫ�����SysMdbSyslogInfo
	virtual void beforeAdd(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo);
	
	///����ǰ����	
	///@param	pSysMdbSyslogInfo	��ˢ�µ�CSysMdbSyslogInfo
	///@param	pNewSysMdbSyslogInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbSyslogInfo	Ҫɾ����CSysMdbSyslogInfo
	virtual void beforeRemove(CSysMdbSyslogInfo *pSysMdbSyslogInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoDumpTrigger�ǲ����û���Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoDumpTrigger: public CSysUserInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysUserInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysUserInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysUserInfo	Ҫ�����SysUserInfo
	virtual void beforeAdd(CWriteableSysUserInfo *pSysUserInfo);
	
	///����ǰ����	
	///@param	pSysUserInfo	��ˢ�µ�CSysUserInfo
	///@param	pNewSysUserInfo	�µ�ֵ
	virtual void beforeUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo);
	
	///ɾ��ǰ����
	///@param	pSysUserInfo	Ҫɾ����CSysUserInfo
	virtual void beforeRemove(CSysUserInfo *pSysUserInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoDumpTrigger�ǲ��������û���Ϣ��ѯӦ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoDumpTrigger: public CSysOnlineUserInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysOnlineUserInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysOnlineUserInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysOnlineUserInfo	Ҫ�����SysOnlineUserInfo
	virtual void beforeAdd(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo);
	
	///����ǰ����	
	///@param	pSysOnlineUserInfo	��ˢ�µ�CSysOnlineUserInfo
	///@param	pNewSysOnlineUserInfo	�µ�ֵ
	virtual void beforeUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo);
	
	///ɾ��ǰ����
	///@param	pSysOnlineUserInfo	Ҫɾ����CSysOnlineUserInfo
	virtual void beforeRemove(CSysOnlineUserInfo *pSysOnlineUserInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventDumpTrigger�ǲ����澯�¼���ѯӦ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventDumpTrigger: public CSysWarningEventActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysWarningEventDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysWarningEventDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysWarningEvent	Ҫ�����SysWarningEvent
	virtual void beforeAdd(CWriteableSysWarningEvent *pSysWarningEvent);
	
	///����ǰ����	
	///@param	pSysWarningEvent	��ˢ�µ�CSysWarningEvent
	///@param	pNewSysWarningEvent	�µ�ֵ
	virtual void beforeUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent);
	
	///ɾ��ǰ����
	///@param	pSysWarningEvent	Ҫɾ����CSysWarningEvent
	virtual void beforeRemove(CSysWarningEvent *pSysWarningEvent);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryDumpTrigger�ǲ����澯��ϸӦ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryDumpTrigger: public CSysWarningQueryActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysWarningQueryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysWarningQueryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysWarningQuery	Ҫ�����SysWarningQuery
	virtual void beforeAdd(CWriteableSysWarningQuery *pSysWarningQuery);
	
	///����ǰ����	
	///@param	pSysWarningQuery	��ˢ�µ�CSysWarningQuery
	///@param	pNewSysWarningQuery	�µ�ֵ
	virtual void beforeUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery);
	
	///ɾ��ǰ����
	///@param	pSysWarningQuery	Ҫɾ����CSysWarningQuery
	virtual void beforeRemove(CSysWarningQuery *pSysWarningQuery);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventDumpTrigger�ǲ�����־�¼���ѯӦ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventDumpTrigger: public CSyslogEventActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSyslogEventDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSyslogEventDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSyslogEvent	Ҫ�����SyslogEvent
	virtual void beforeAdd(CWriteableSyslogEvent *pSyslogEvent);
	
	///����ǰ����	
	///@param	pSyslogEvent	��ˢ�µ�CSyslogEvent
	///@param	pNewSyslogEvent	�µ�ֵ
	virtual void beforeUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent);
	
	///ɾ��ǰ����
	///@param	pSyslogEvent	Ҫɾ����CSyslogEvent
	virtual void beforeRemove(CSyslogEvent *pSyslogEvent);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripDumpTrigger�ǲ����¼�������ѯʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripDumpTrigger: public CSysEventDescripActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysEventDescripDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysEventDescripDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysEventDescrip	Ҫ�����SysEventDescrip
	virtual void beforeAdd(CWriteableSysEventDescrip *pSysEventDescrip);
	
	///����ǰ����	
	///@param	pSysEventDescrip	��ˢ�µ�CSysEventDescrip
	///@param	pNewSysEventDescrip	�µ�ֵ
	virtual void beforeUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip);
	
	///ɾ��ǰ����
	///@param	pSysEventDescrip	Ҫɾ����CSysEventDescrip
	virtual void beforeRemove(CSysEventDescrip *pSysEventDescrip);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonDumpTrigger�ǲ�������������Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonDumpTrigger: public CRspQryHostEnvCommonActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRspQryHostEnvCommonDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRspQryHostEnvCommonDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRspQryHostEnvCommon	Ҫ�����RspQryHostEnvCommon
	virtual void beforeAdd(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon);
	
	///����ǰ����	
	///@param	pRspQryHostEnvCommon	��ˢ�µ�CRspQryHostEnvCommon
	///@param	pNewRspQryHostEnvCommon	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon);
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvCommon	Ҫɾ����CRspQryHostEnvCommon
	virtual void beforeRemove(CRspQryHostEnvCommon *pRspQryHostEnvCommon);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanDumpTrigger�ǲ�����������Lan��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanDumpTrigger: public CRspQryHostEnvLanActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRspQryHostEnvLanDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRspQryHostEnvLanDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRspQryHostEnvLan	Ҫ�����RspQryHostEnvLan
	virtual void beforeAdd(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan);
	
	///����ǰ����	
	///@param	pRspQryHostEnvLan	��ˢ�µ�CRspQryHostEnvLan
	///@param	pNewRspQryHostEnvLan	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan);
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvLan	Ҫɾ����CRspQryHostEnvLan
	virtual void beforeRemove(CRspQryHostEnvLan *pRspQryHostEnvLan);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageDumpTrigger�ǲ������������洢�豸��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageDumpTrigger: public CRspQryHostEnvStorageActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRspQryHostEnvStorageDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRspQryHostEnvStorageDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRspQryHostEnvStorage	Ҫ�����RspQryHostEnvStorage
	virtual void beforeAdd(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage);
	
	///����ǰ����	
	///@param	pRspQryHostEnvStorage	��ˢ�µ�CRspQryHostEnvStorage
	///@param	pNewRspQryHostEnvStorage	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage);
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvStorage	Ҫɾ����CRspQryHostEnvStorage
	virtual void beforeRemove(CRspQryHostEnvStorage *pRspQryHostEnvStorage);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIODumpTrigger�ǲ�����������IO�豸��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIODumpTrigger: public CRspQryHostEnvIOActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRspQryHostEnvIODumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRspQryHostEnvIODumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRspQryHostEnvIO	Ҫ�����RspQryHostEnvIO
	virtual void beforeAdd(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO);
	
	///����ǰ����	
	///@param	pRspQryHostEnvIO	��ˢ�µ�CRspQryHostEnvIO
	///@param	pNewRspQryHostEnvIO	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO);
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvIO	Ҫɾ����CRspQryHostEnvIO
	virtual void beforeRemove(CRspQryHostEnvIO *pRspQryHostEnvIO);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSDumpTrigger�ǲ������������ļ�ϵͳ��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSDumpTrigger: public CRspQryHostEnvFSActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRspQryHostEnvFSDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRspQryHostEnvFSDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRspQryHostEnvFS	Ҫ�����RspQryHostEnvFS
	virtual void beforeAdd(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS);
	
	///����ǰ����	
	///@param	pRspQryHostEnvFS	��ˢ�µ�CRspQryHostEnvFS
	///@param	pNewRspQryHostEnvFS	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS);
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvFS	Ҫɾ����CRspQryHostEnvFS
	virtual void beforeRemove(CRspQryHostEnvFS *pRspQryHostEnvFS);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapDumpTrigger�ǲ���������������������Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapDumpTrigger: public CRspQryHostEnvSwapActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRspQryHostEnvSwapDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRspQryHostEnvSwapDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRspQryHostEnvSwap	Ҫ�����RspQryHostEnvSwap
	virtual void beforeAdd(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap);
	
	///����ǰ����	
	///@param	pRspQryHostEnvSwap	��ˢ�µ�CRspQryHostEnvSwap
	///@param	pNewRspQryHostEnvSwap	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap);
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvSwap	Ҫɾ����CRspQryHostEnvSwap
	virtual void beforeRemove(CRspQryHostEnvSwap *pRspQryHostEnvSwap);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgDumpTrigger�ǲ���������������������Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgDumpTrigger: public CRspQryHostEnvLanCfgActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRspQryHostEnvLanCfgDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRspQryHostEnvLanCfgDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRspQryHostEnvLanCfg	Ҫ�����RspQryHostEnvLanCfg
	virtual void beforeAdd(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
	
	///����ǰ����	
	///@param	pRspQryHostEnvLanCfg	��ˢ�µ�CRspQryHostEnvLanCfg
	///@param	pNewRspQryHostEnvLanCfg	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg);
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvLanCfg	Ҫɾ����CRspQryHostEnvLanCfg
	virtual void beforeRemove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoDumpTrigger�ǲ���CPU��Դʹ����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoDumpTrigger: public CSysMdbTopCpuInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbTopCpuInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbTopCpuInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbTopCpuInfo	Ҫ�����SysMdbTopCpuInfo
	virtual void beforeAdd(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
	
	///����ǰ����	
	///@param	pSysMdbTopCpuInfo	��ˢ�µ�CSysMdbTopCpuInfo
	///@param	pNewSysMdbTopCpuInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbTopCpuInfo	Ҫɾ����CSysMdbTopCpuInfo
	virtual void beforeRemove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoDumpTrigger�ǲ����ڴ���Դʹ����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoDumpTrigger: public CSysMdbTopMemInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbTopMemInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbTopMemInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbTopMemInfo	Ҫ�����SysMdbTopMemInfo
	virtual void beforeAdd(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo);
	
	///����ǰ����	
	///@param	pSysMdbTopMemInfo	��ˢ�µ�CSysMdbTopMemInfo
	///@param	pNewSysMdbTopMemInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbTopMemInfo	Ҫɾ����CSysMdbTopMemInfo
	virtual void beforeRemove(CSysMdbTopMemInfo *pSysMdbTopMemInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoDumpTrigger�ǲ���������Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoDumpTrigger: public CSysMdbTopProcessInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbTopProcessInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbTopProcessInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbTopProcessInfo	Ҫ�����SysMdbTopProcessInfo
	virtual void beforeAdd(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
	
	///����ǰ����	
	///@param	pSysMdbTopProcessInfo	��ˢ�µ�CSysMdbTopProcessInfo
	///@param	pNewSysMdbTopProcessInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbTopProcessInfo	Ҫɾ����CSysMdbTopProcessInfo
	virtual void beforeRemove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoDumpTrigger�ǲ����ļ�ϵͳ��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoDumpTrigger: public CSysMdbFileSystemInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbFileSystemInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbFileSystemInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbFileSystemInfo	Ҫ�����SysMdbFileSystemInfo
	virtual void beforeAdd(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
	
	///����ǰ����	
	///@param	pSysMdbFileSystemInfo	��ˢ�µ�CSysMdbFileSystemInfo
	///@param	pNewSysMdbFileSystemInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbFileSystemInfo	Ҫɾ����CSysMdbFileSystemInfo
	virtual void beforeRemove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoDumpTrigger�ǲ�������ʹ����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoDumpTrigger: public CSysMdbNetworkInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbNetworkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbNetworkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbNetworkInfo	Ҫ�����SysMdbNetworkInfo
	virtual void beforeAdd(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo);
	
	///����ǰ����	
	///@param	pSysMdbNetworkInfo	��ˢ�µ�CSysMdbNetworkInfo
	///@param	pNewSysMdbNetworkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbNetworkInfo	Ҫɾ����CSysMdbNetworkInfo
	virtual void beforeRemove(CSysMdbNetworkInfo *pSysMdbNetworkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitDumpTrigger�ǲ�����Աʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitDumpTrigger: public CSysParticipantInitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysParticipantInitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysParticipantInitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysParticipantInit	Ҫ�����SysParticipantInit
	virtual void beforeAdd(CWriteableSysParticipantInit *pSysParticipantInit);
	
	///����ǰ����	
	///@param	pSysParticipantInit	��ˢ�µ�CSysParticipantInit
	///@param	pNewSysParticipantInit	�µ�ֵ
	virtual void beforeUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit);
	
	///ɾ��ǰ����
	///@param	pSysParticipantInit	Ҫɾ����CSysParticipantInit
	virtual void beforeRemove(CSysParticipantInit *pSysParticipantInit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitDumpTrigger�ǲ��������û�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitDumpTrigger: public CSysUserInitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysUserInitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysUserInitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysUserInit	Ҫ�����SysUserInit
	virtual void beforeAdd(CWriteableSysUserInit *pSysUserInit);
	
	///����ǰ����	
	///@param	pSysUserInit	��ˢ�µ�CSysUserInit
	///@param	pNewSysUserInit	�µ�ֵ
	virtual void beforeUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit);
	
	///ɾ��ǰ����
	///@param	pSysUserInit	Ҫɾ����CSysUserInit
	virtual void beforeRemove(CSysUserInit *pSysUserInit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitDumpTrigger�ǲ����ͻ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitDumpTrigger: public CSysClientInitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysClientInitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysClientInitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysClientInit	Ҫ�����SysClientInit
	virtual void beforeAdd(CWriteableSysClientInit *pSysClientInit);
	
	///����ǰ����	
	///@param	pSysClientInit	��ˢ�µ�CSysClientInit
	///@param	pNewSysClientInit	�µ�ֵ
	virtual void beforeUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit);
	
	///ɾ��ǰ����
	///@param	pSysClientInit	Ҫɾ����CSysClientInit
	virtual void beforeRemove(CSysClientInit *pSysClientInit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoDumpTrigger�ǲ�������ϵͳ��¼��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoDumpTrigger: public CSysTradeUserLoginInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysTradeUserLoginInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysTradeUserLoginInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysTradeUserLoginInfo	Ҫ�����SysTradeUserLoginInfo
	virtual void beforeAdd(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
	
	///����ǰ����	
	///@param	pSysTradeUserLoginInfo	��ˢ�µ�CSysTradeUserLoginInfo
	///@param	pNewSysTradeUserLoginInfo	�µ�ֵ
	virtual void beforeUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo);
	
	///ɾ��ǰ����
	///@param	pSysTradeUserLoginInfo	Ҫɾ����CSysTradeUserLoginInfo
	virtual void beforeRemove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoDumpTrigger�ǲ���WebӦ����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoDumpTrigger: public CSysMdbWebAppInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbWebAppInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbWebAppInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbWebAppInfo	Ҫ�����SysMdbWebAppInfo
	virtual void beforeAdd(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo);
	
	///����ǰ����	
	///@param	pSysMdbWebAppInfo	��ˢ�µ�CSysMdbWebAppInfo
	///@param	pNewSysMdbWebAppInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbWebAppInfo	Ҫɾ����CSysMdbWebAppInfo
	virtual void beforeRemove(CSysMdbWebAppInfo *pSysMdbWebAppInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoDumpTrigger�ǲ���ϵͳ�ڴ����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoDumpTrigger: public CSysMdbMemPoolInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbMemPoolInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbMemPoolInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbMemPoolInfo	Ҫ�����SysMdbMemPoolInfo
	virtual void beforeAdd(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
	
	///����ǰ����	
	///@param	pSysMdbMemPoolInfo	��ˢ�µ�CSysMdbMemPoolInfo
	///@param	pNewSysMdbMemPoolInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbMemPoolInfo	Ҫɾ����CSysMdbMemPoolInfo
	virtual void beforeRemove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoDumpTrigger�ǲ�����������Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoDumpTrigger: public CSysMdbConnectorInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbConnectorInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbConnectorInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbConnectorInfo	Ҫ�����SysMdbConnectorInfo
	virtual void beforeAdd(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo);
	
	///����ǰ����	
	///@param	pSysMdbConnectorInfo	��ˢ�µ�CSysMdbConnectorInfo
	///@param	pNewSysMdbConnectorInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbConnectorInfo	Ҫɾ����CSysMdbConnectorInfo
	virtual void beforeRemove(CSysMdbConnectorInfo *pSysMdbConnectorInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryDumpTrigger�ǲ������ݿ��ѯӦ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryDumpTrigger: public CSysMdbDBQueryActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbDBQueryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbDBQueryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbDBQuery	Ҫ�����SysMdbDBQuery
	virtual void beforeAdd(CWriteableSysMdbDBQuery *pSysMdbDBQuery);
	
	///����ǰ����	
	///@param	pSysMdbDBQuery	��ˢ�µ�CSysMdbDBQuery
	///@param	pNewSysMdbDBQuery	�µ�ֵ
	virtual void beforeUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery);
	
	///ɾ��ǰ����
	///@param	pSysMdbDBQuery	Ҫɾ����CSysMdbDBQuery
	virtual void beforeRemove(CSysMdbDBQuery *pSysMdbDBQuery);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaDumpTrigger�ǲ��������������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaDumpTrigger: public CSysNetAreaActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetAreaDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetAreaDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetArea	Ҫ�����SysNetArea
	virtual void beforeAdd(CWriteableSysNetArea *pSysNetArea);
	
	///����ǰ����	
	///@param	pSysNetArea	��ˢ�µ�CSysNetArea
	///@param	pNewSysNetArea	�µ�ֵ
	virtual void beforeUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea);
	
	///ɾ��ǰ����
	///@param	pSysNetArea	Ҫɾ����CSysNetArea
	virtual void beforeRemove(CSysNetArea *pSysNetArea);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaDumpTrigger�ǲ�����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaDumpTrigger: public CSysNetSubAreaActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetSubAreaDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetSubAreaDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetSubArea	Ҫ�����SysNetSubArea
	virtual void beforeAdd(CWriteableSysNetSubArea *pSysNetSubArea);
	
	///����ǰ����	
	///@param	pSysNetSubArea	��ˢ�µ�CSysNetSubArea
	///@param	pNewSysNetSubArea	�µ�ֵ
	virtual void beforeUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea);
	
	///ɾ��ǰ����
	///@param	pSysNetSubArea	Ҫɾ����CSysNetSubArea
	virtual void beforeRemove(CSysNetSubArea *pSysNetSubArea);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPDumpTrigger�ǲ�����������IPʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPDumpTrigger: public CSysNetSubAreaIPActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetSubAreaIPDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetSubAreaIPDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetSubAreaIP	Ҫ�����SysNetSubAreaIP
	virtual void beforeAdd(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP);
	
	///����ǰ����	
	///@param	pSysNetSubAreaIP	��ˢ�µ�CSysNetSubAreaIP
	///@param	pNewSysNetSubAreaIP	�µ�ֵ
	virtual void beforeUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP);
	
	///ɾ��ǰ����
	///@param	pSysNetSubAreaIP	Ҫɾ����CSysNetSubAreaIP
	virtual void beforeRemove(CSysNetSubAreaIP *pSysNetSubAreaIP);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaDumpTrigger�ǲ���ְ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaDumpTrigger: public CSysNetFuncAreaActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetFuncAreaDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetFuncAreaDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetFuncArea	Ҫ�����SysNetFuncArea
	virtual void beforeAdd(CWriteableSysNetFuncArea *pSysNetFuncArea);
	
	///����ǰ����	
	///@param	pSysNetFuncArea	��ˢ�µ�CSysNetFuncArea
	///@param	pNewSysNetFuncArea	�µ�ֵ
	virtual void beforeUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea);
	
	///ɾ��ǰ����
	///@param	pSysNetFuncArea	Ҫɾ����CSysNetFuncArea
	virtual void beforeRemove(CSysNetFuncArea *pSysNetFuncArea);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceDumpTrigger�ǲ��������豸ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceDumpTrigger: public CSysNetDeviceActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetDeviceDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetDeviceDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetDevice	Ҫ�����SysNetDevice
	virtual void beforeAdd(CWriteableSysNetDevice *pSysNetDevice);
	
	///����ǰ����	
	///@param	pSysNetDevice	��ˢ�µ�CSysNetDevice
	///@param	pNewSysNetDevice	�µ�ֵ
	virtual void beforeUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice);
	
	///ɾ��ǰ����
	///@param	pSysNetDevice	Ҫɾ����CSysNetDevice
	virtual void beforeRemove(CSysNetDevice *pSysNetDevice);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedDumpTrigger�ǲ��������豸���ӹ�ϵʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedDumpTrigger: public CSysNetDeviceLinkedActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetDeviceLinkedDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetDeviceLinkedDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetDeviceLinked	Ҫ�����SysNetDeviceLinked
	virtual void beforeAdd(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked);
	
	///����ǰ����	
	///@param	pSysNetDeviceLinked	��ˢ�µ�CSysNetDeviceLinked
	///@param	pNewSysNetDeviceLinked	�µ�ֵ
	virtual void beforeUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked);
	
	///ɾ��ǰ����
	///@param	pSysNetDeviceLinked	Ҫɾ����CSysNetDeviceLinked
	virtual void beforeRemove(CSysNetDeviceLinked *pSysNetDeviceLinked);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDDumpTrigger�ǲ���OIDʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDDumpTrigger: public CSysNetOIDActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetOIDDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetOIDDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetOID	Ҫ�����SysNetOID
	virtual void beforeAdd(CWriteableSysNetOID *pSysNetOID);
	
	///����ǰ����	
	///@param	pSysNetOID	��ˢ�µ�CSysNetOID
	///@param	pNewSysNetOID	�µ�ֵ
	virtual void beforeUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID);
	
	///ɾ��ǰ����
	///@param	pSysNetOID	Ҫɾ����CSysNetOID
	virtual void beforeRemove(CSysNetOID *pSysNetOID);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeDumpTrigger�ǲ��������豸����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeDumpTrigger: public CSysNetDeviceTypeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetDeviceTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetDeviceTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetDeviceType	Ҫ�����SysNetDeviceType
	virtual void beforeAdd(CWriteableSysNetDeviceType *pSysNetDeviceType);
	
	///����ǰ����	
	///@param	pSysNetDeviceType	��ˢ�µ�CSysNetDeviceType
	///@param	pNewSysNetDeviceType	�µ�ֵ
	virtual void beforeUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType);
	
	///ɾ��ǰ����
	///@param	pSysNetDeviceType	Ҫɾ����CSysNetDeviceType
	virtual void beforeRemove(CSysNetDeviceType *pSysNetDeviceType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyDumpTrigger�ǲ���ʱ�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyDumpTrigger: public CSysNetTimePolicyActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetTimePolicyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetTimePolicyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetTimePolicy	Ҫ�����SysNetTimePolicy
	virtual void beforeAdd(CWriteableSysNetTimePolicy *pSysNetTimePolicy);
	
	///����ǰ����	
	///@param	pSysNetTimePolicy	��ˢ�µ�CSysNetTimePolicy
	///@param	pNewSysNetTimePolicy	�µ�ֵ
	virtual void beforeUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy);
	
	///ɾ��ǰ����
	///@param	pSysNetTimePolicy	Ҫɾ����CSysNetTimePolicy
	virtual void beforeRemove(CSysNetTimePolicy *pSysNetTimePolicy);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskDumpTrigger�ǲ����ɼ�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskDumpTrigger: public CSysNetGatherTaskActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetGatherTaskDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetGatherTaskDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetGatherTask	Ҫ�����SysNetGatherTask
	virtual void beforeAdd(CWriteableSysNetGatherTask *pSysNetGatherTask);
	
	///����ǰ����	
	///@param	pSysNetGatherTask	��ˢ�µ�CSysNetGatherTask
	///@param	pNewSysNetGatherTask	�µ�ֵ
	virtual void beforeUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask);
	
	///ɾ��ǰ����
	///@param	pSysNetGatherTask	Ҫɾ����CSysNetGatherTask
	virtual void beforeRemove(CSysNetGatherTask *pSysNetGatherTask);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryDumpTrigger�ǲ��������豸���ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryDumpTrigger: public CSysNetDeviceCategoryActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetDeviceCategoryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetDeviceCategoryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetDeviceCategory	Ҫ�����SysNetDeviceCategory
	virtual void beforeAdd(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory);
	
	///����ǰ����	
	///@param	pSysNetDeviceCategory	��ˢ�µ�CSysNetDeviceCategory
	///@param	pNewSysNetDeviceCategory	�µ�ֵ
	virtual void beforeUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory);
	
	///ɾ��ǰ����
	///@param	pSysNetDeviceCategory	Ҫɾ����CSysNetDeviceCategory
	virtual void beforeRemove(CSysNetDeviceCategory *pSysNetDeviceCategory);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryDumpTrigger�ǲ����豸����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryDumpTrigger: public CSysNetManufactoryActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetManufactoryDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetManufactoryDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetManufactory	Ҫ�����SysNetManufactory
	virtual void beforeAdd(CWriteableSysNetManufactory *pSysNetManufactory);
	
	///����ǰ����	
	///@param	pSysNetManufactory	��ˢ�µ�CSysNetManufactory
	///@param	pNewSysNetManufactory	�µ�ֵ
	virtual void beforeUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory);
	
	///ɾ��ǰ����
	///@param	pSysNetManufactory	Ҫɾ����CSysNetManufactory
	virtual void beforeRemove(CSysNetManufactory *pSysNetManufactory);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityDumpTrigger�ǲ����豸��ͬ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityDumpTrigger: public CSysNetCommunityActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetCommunityDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetCommunityDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetCommunity	Ҫ�����SysNetCommunity
	virtual void beforeAdd(CWriteableSysNetCommunity *pSysNetCommunity);
	
	///����ǰ����	
	///@param	pSysNetCommunity	��ˢ�µ�CSysNetCommunity
	///@param	pNewSysNetCommunity	�µ�ֵ
	virtual void beforeUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity);
	
	///ɾ��ǰ����
	///@param	pSysNetCommunity	Ҫɾ����CSysNetCommunity
	virtual void beforeRemove(CSysNetCommunity *pSysNetCommunity);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeDumpTrigger�ǲ����˿�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeDumpTrigger: public CSysNetPortTypeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetPortTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetPortTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetPortType	Ҫ�����SysNetPortType
	virtual void beforeAdd(CWriteableSysNetPortType *pSysNetPortType);
	
	///����ǰ����	
	///@param	pSysNetPortType	��ˢ�µ�CSysNetPortType
	///@param	pNewSysNetPortType	�µ�ֵ
	virtual void beforeUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType);
	
	///ɾ��ǰ����
	///@param	pSysNetPortType	Ҫɾ����CSysNetPortType
	virtual void beforeRemove(CSysNetPortType *pSysNetPortType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceDumpTrigger�ǲ����˿�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceDumpTrigger: public CSysNetInterfaceActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetInterfaceDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetInterfaceDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetInterface	Ҫ�����SysNetInterface
	virtual void beforeAdd(CWriteableSysNetInterface *pSysNetInterface);
	
	///����ǰ����	
	///@param	pSysNetInterface	��ˢ�µ�CSysNetInterface
	///@param	pNewSysNetInterface	�µ�ֵ
	virtual void beforeUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface);
	
	///ɾ��ǰ����
	///@param	pSysNetInterface	Ҫɾ����CSysNetInterface
	virtual void beforeRemove(CSysNetInterface *pSysNetInterface);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDDumpTrigger�ǲ���ͨ��OIDʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDDumpTrigger: public CSysNetGeneralOIDActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetGeneralOIDDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetGeneralOIDDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetGeneralOID	Ҫ�����SysNetGeneralOID
	virtual void beforeAdd(CWriteableSysNetGeneralOID *pSysNetGeneralOID);
	
	///����ǰ����	
	///@param	pSysNetGeneralOID	��ˢ�µ�CSysNetGeneralOID
	///@param	pNewSysNetGeneralOID	�µ�ֵ
	virtual void beforeUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID);
	
	///ɾ��ǰ����
	///@param	pSysNetGeneralOID	Ҫɾ����CSysNetGeneralOID
	virtual void beforeRemove(CSysNetGeneralOID *pSysNetGeneralOID);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeDumpTrigger�ǲ�����ض������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeDumpTrigger: public CSysNetMonitorTypeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorType	Ҫ�����SysNetMonitorType
	virtual void beforeAdd(CWriteableSysNetMonitorType *pSysNetMonitorType);
	
	///����ǰ����	
	///@param	pSysNetMonitorType	��ˢ�µ�CSysNetMonitorType
	///@param	pNewSysNetMonitorType	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorType	Ҫɾ����CSysNetMonitorType
	virtual void beforeRemove(CSysNetMonitorType *pSysNetMonitorType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeDumpTrigger�ǲ���ָ��ͳ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeDumpTrigger: public CSysNetMonitorAttrScopeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorAttrScopeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorAttrScopeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorAttrScope	Ҫ�����SysNetMonitorAttrScope
	virtual void beforeAdd(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
	
	///����ǰ����	
	///@param	pSysNetMonitorAttrScope	��ˢ�µ�CSysNetMonitorAttrScope
	///@param	pNewSysNetMonitorAttrScope	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorAttrScope	Ҫɾ����CSysNetMonitorAttrScope
	virtual void beforeRemove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeDumpTrigger�ǲ������ָ���ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeDumpTrigger: public CSysNetMonitorAttrTypeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorAttrTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorAttrTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorAttrType	Ҫ�����SysNetMonitorAttrType
	virtual void beforeAdd(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType);
	
	///����ǰ����	
	///@param	pSysNetMonitorAttrType	��ˢ�µ�CSysNetMonitorAttrType
	///@param	pNewSysNetMonitorAttrType	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorAttrType	Ҫɾ����CSysNetMonitorAttrType
	virtual void beforeRemove(CSysNetMonitorAttrType *pSysNetMonitorAttrType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeDumpTrigger�ǲ������ָ���ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeDumpTrigger: public CSysNetMonitorCommandTypeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorCommandTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorCommandTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorCommandType	Ҫ�����SysNetMonitorCommandType
	virtual void beforeAdd(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType);
	
	///����ǰ����	
	///@param	pSysNetMonitorCommandType	��ˢ�µ�CSysNetMonitorCommandType
	///@param	pNewSysNetMonitorCommandType	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorCommandType	Ҫɾ����CSysNetMonitorCommandType
	virtual void beforeRemove(CSysNetMonitorCommandType *pSysNetMonitorCommandType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupDumpTrigger�ǲ����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupDumpTrigger: public CSysNetMonitorActionGroupActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorActionGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorActionGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorActionGroup	Ҫ�����SysNetMonitorActionGroup
	virtual void beforeAdd(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
	
	///����ǰ����	
	///@param	pSysNetMonitorActionGroup	��ˢ�µ�CSysNetMonitorActionGroup
	///@param	pNewSysNetMonitorActionGroup	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorActionGroup	Ҫɾ����CSysNetMonitorActionGroup
	virtual void beforeRemove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupDumpTrigger�ǲ����豸�������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupDumpTrigger: public CSysNetMonitorDeviceGroupActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorDeviceGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorDeviceGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorDeviceGroup	Ҫ�����SysNetMonitorDeviceGroup
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
	
	///����ǰ����	
	///@param	pSysNetMonitorDeviceGroup	��ˢ�µ�CSysNetMonitorDeviceGroup
	///@param	pNewSysNetMonitorDeviceGroup	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorDeviceGroup	Ҫɾ����CSysNetMonitorDeviceGroup
	virtual void beforeRemove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoDumpTrigger�ǲ���������Ϣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoDumpTrigger: public CSysNetMonitorTaskInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorTaskInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorTaskInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorTaskInfo	Ҫ�����SysNetMonitorTaskInfo
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
	
	///����ǰ����	
	///@param	pSysNetMonitorTaskInfo	��ˢ�µ�CSysNetMonitorTaskInfo
	///@param	pNewSysNetMonitorTaskInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskInfo	Ҫɾ����CSysNetMonitorTaskInfo
	virtual void beforeRemove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetDumpTrigger�ǲ����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetDumpTrigger: public CSysNetMonitorTaskObjectSetActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorTaskObjectSetDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorTaskObjectSetDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorTaskObjectSet	Ҫ�����SysNetMonitorTaskObjectSet
	virtual void beforeAdd(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
	
	///����ǰ����	
	///@param	pSysNetMonitorTaskObjectSet	��ˢ�µ�CSysNetMonitorTaskObjectSet
	///@param	pNewSysNetMonitorTaskObjectSet	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskObjectSet	Ҫɾ����CSysNetMonitorTaskObjectSet
	virtual void beforeRemove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultDumpTrigger�ǲ�����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultDumpTrigger: public CSysNetMonitorTaskResultActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorTaskResultDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorTaskResultDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorTaskResult	Ҫ�����SysNetMonitorTaskResult
	virtual void beforeAdd(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
	
	///����ǰ����	
	///@param	pSysNetMonitorTaskResult	��ˢ�µ�CSysNetMonitorTaskResult
	///@param	pNewSysNetMonitorTaskResult	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskResult	Ҫɾ����CSysNetMonitorTaskResult
	virtual void beforeRemove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoDumpTrigger�ǲ�����Ա��·��Ϣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoDumpTrigger: public CSysNetPartyLinkInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetPartyLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetPartyLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetPartyLinkInfo	Ҫ�����SysNetPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
	
	///����ǰ����	
	///@param	pSysNetPartyLinkInfo	��ˢ�µ�CSysNetPartyLinkInfo
	///@param	pNewSysNetPartyLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetPartyLinkInfo	Ҫɾ����CSysNetPartyLinkInfo
	virtual void beforeRemove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoDumpTrigger�ǲ�����Ա��·��Ϣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoDumpTrigger: public CSysNetDelPartyLinkInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetDelPartyLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetDelPartyLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetDelPartyLinkInfo	Ҫ�����SysNetDelPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
	
	///����ǰ����	
	///@param	pSysNetDelPartyLinkInfo	��ˢ�µ�CSysNetDelPartyLinkInfo
	///@param	pNewSysNetDelPartyLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetDelPartyLinkInfo	Ҫɾ����CSysNetDelPartyLinkInfo
	virtual void beforeRemove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeDumpTrigger�ǲ�����Ա��·��Ϣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeDumpTrigger: public CSysNetPartyLinkAddrChangeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetPartyLinkAddrChangeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetPartyLinkAddrChangeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetPartyLinkAddrChange	Ҫ�����SysNetPartyLinkAddrChange
	virtual void beforeAdd(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
	
	///����ǰ����	
	///@param	pSysNetPartyLinkAddrChange	��ˢ�µ�CSysNetPartyLinkAddrChange
	///@param	pNewSysNetPartyLinkAddrChange	�µ�ֵ
	virtual void beforeUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange);
	
	///ɾ��ǰ����
	///@param	pSysNetPartyLinkAddrChange	Ҫɾ����CSysNetPartyLinkAddrChange
	virtual void beforeRemove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrDumpTrigger�ǲ�����ض���ָ����ձ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrDumpTrigger: public CSysNetMonitorActionAttrActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorActionAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorActionAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorActionAttr	Ҫ�����SysNetMonitorActionAttr
	virtual void beforeAdd(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
	
	///����ǰ����	
	///@param	pSysNetMonitorActionAttr	��ˢ�µ�CSysNetMonitorActionAttr
	///@param	pNewSysNetMonitorActionAttr	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorActionAttr	Ҫɾ����CSysNetMonitorActionAttr
	virtual void beforeRemove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleDumpTrigger�ǲ���ģ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleDumpTrigger: public CSysNetModuleActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetModuleDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetModuleDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetModule	Ҫ�����SysNetModule
	virtual void beforeAdd(CWriteableSysNetModule *pSysNetModule);
	
	///����ǰ����	
	///@param	pSysNetModule	��ˢ�µ�CSysNetModule
	///@param	pNewSysNetModule	�µ�ֵ
	virtual void beforeUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule);
	
	///ɾ��ǰ����
	///@param	pSysNetModule	Ҫɾ����CSysNetModule
	virtual void beforeRemove(CSysNetModule *pSysNetModule);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprDumpTrigger�ǲ����澯���ʽ��Ϣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprDumpTrigger: public CSysNetEventExprActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetEventExprDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetEventExprDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetEventExpr	Ҫ�����SysNetEventExpr
	virtual void beforeAdd(CWriteableSysNetEventExpr *pSysNetEventExpr);
	
	///����ǰ����	
	///@param	pSysNetEventExpr	��ˢ�µ�CSysNetEventExpr
	///@param	pNewSysNetEventExpr	�µ�ֵ
	virtual void beforeUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr);
	
	///ɾ��ǰ����
	///@param	pSysNetEventExpr	Ҫɾ����CSysNetEventExpr
	virtual void beforeRemove(CSysNetEventExpr *pSysNetEventExpr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeDumpTrigger�ǲ����¼�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeDumpTrigger: public CSysNetEventTypeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetEventTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetEventTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetEventType	Ҫ�����SysNetEventType
	virtual void beforeAdd(CWriteableSysNetEventType *pSysNetEventType);
	
	///����ǰ����	
	///@param	pSysNetEventType	��ˢ�µ�CSysNetEventType
	///@param	pNewSysNetEventType	�µ�ֵ
	virtual void beforeUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType);
	
	///ɾ��ǰ����
	///@param	pSysNetEventType	Ҫɾ����CSysNetEventType
	virtual void beforeRemove(CSysNetEventType *pSysNetEventType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeDumpTrigger�ǲ����¼�������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeDumpTrigger: public CSysNetSubEventTypeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetSubEventTypeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetSubEventTypeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetSubEventType	Ҫ�����SysNetSubEventType
	virtual void beforeAdd(CWriteableSysNetSubEventType *pSysNetSubEventType);
	
	///����ǰ����	
	///@param	pSysNetSubEventType	��ˢ�µ�CSysNetSubEventType
	///@param	pNewSysNetSubEventType	�µ�ֵ
	virtual void beforeUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType);
	
	///ɾ��ǰ����
	///@param	pSysNetSubEventType	Ҫɾ����CSysNetSubEventType
	virtual void beforeRemove(CSysNetSubEventType *pSysNetSubEventType);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelDumpTrigger�ǲ����¼�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelDumpTrigger: public CSysNetEventLevelActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetEventLevelDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetEventLevelDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetEventLevel	Ҫ�����SysNetEventLevel
	virtual void beforeAdd(CWriteableSysNetEventLevel *pSysNetEventLevel);
	
	///����ǰ����	
	///@param	pSysNetEventLevel	��ˢ�µ�CSysNetEventLevel
	///@param	pNewSysNetEventLevel	�µ�ֵ
	virtual void beforeUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel);
	
	///ɾ��ǰ����
	///@param	pSysNetEventLevel	Ҫɾ����CSysNetEventLevel
	virtual void beforeRemove(CSysNetEventLevel *pSysNetEventLevel);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskDumpTrigger�ǲ������������������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskDumpTrigger: public CSysNetMonitorDeviceTaskActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorDeviceTaskDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorDeviceTaskDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorDeviceTask	Ҫ�����SysNetMonitorDeviceTask
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
	
	///����ǰ����	
	///@param	pSysNetMonitorDeviceTask	��ˢ�µ�CSysNetMonitorDeviceTask
	///@param	pNewSysNetMonitorDeviceTask	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorDeviceTask	Ҫɾ����CSysNetMonitorDeviceTask
	virtual void beforeRemove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsDumpTrigger�ǲ�������ָ��ָ�꼯��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsDumpTrigger: public CSysNetMonitorTaskInstAttrsActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMonitorTaskInstAttrsDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMonitorTaskInstAttrsDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMonitorTaskInstAttrs	Ҫ�����SysNetMonitorTaskInstAttrs
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
	
	///����ǰ����	
	///@param	pSysNetMonitorTaskInstAttrs	��ˢ�µ�CSysNetMonitorTaskInstAttrs
	///@param	pNewSysNetMonitorTaskInstAttrs	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs);
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskInstAttrs	Ҫɾ����CSysNetMonitorTaskInstAttrs
	virtual void beforeRemove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineDumpTrigger�ǲ������߱�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineDumpTrigger: public CSysNetBaseLineActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetBaseLineDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetBaseLineDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetBaseLine	Ҫ�����SysNetBaseLine
	virtual void beforeAdd(CWriteableSysNetBaseLine *pSysNetBaseLine);
	
	///����ǰ����	
	///@param	pSysNetBaseLine	��ˢ�µ�CSysNetBaseLine
	///@param	pNewSysNetBaseLine	�µ�ֵ
	virtual void beforeUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine);
	
	///ɾ��ǰ����
	///@param	pSysNetBaseLine	Ҫɾ����CSysNetBaseLine
	virtual void beforeRemove(CSysNetBaseLine *pSysNetBaseLine);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskDumpTrigger�ǲ������������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskDumpTrigger: public CSysNetBaseLineTaskActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetBaseLineTaskDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetBaseLineTaskDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetBaseLineTask	Ҫ�����SysNetBaseLineTask
	virtual void beforeAdd(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask);
	
	///����ǰ����	
	///@param	pSysNetBaseLineTask	��ˢ�µ�CSysNetBaseLineTask
	///@param	pNewSysNetBaseLineTask	�µ�ֵ
	virtual void beforeUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask);
	
	///ɾ��ǰ����
	///@param	pSysNetBaseLineTask	Ҫɾ����CSysNetBaseLineTask
	virtual void beforeRemove(CSysNetBaseLineTask *pSysNetBaseLineTask);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoDumpTrigger�ǲ�����Ա��·״̬��Ϣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoDumpTrigger: public CSysMdbNetPartyLinkStatusInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbNetPartyLinkStatusInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbNetPartyLinkStatusInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫ�����SysMdbNetPartyLinkStatusInfo
	virtual void beforeAdd(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
	
	///����ǰ����	
	///@param	pSysMdbNetPartyLinkStatusInfo	��ˢ�µ�CSysMdbNetPartyLinkStatusInfo
	///@param	pNewSysMdbNetPartyLinkStatusInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫɾ����CSysMdbNetPartyLinkStatusInfo
	virtual void beforeRemove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoDumpTrigger�ǲ�����ԱSDH��·��ϸ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoDumpTrigger: public CSysNetMemberSDHLineInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetMemberSDHLineInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetMemberSDHLineInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetMemberSDHLineInfo	Ҫ�����SysNetMemberSDHLineInfo
	virtual void beforeAdd(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
	
	///����ǰ����	
	///@param	pSysNetMemberSDHLineInfo	��ˢ�µ�CSysNetMemberSDHLineInfo
	///@param	pNewSysNetMemberSDHLineInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetMemberSDHLineInfo	Ҫɾ����CSysNetMemberSDHLineInfo
	virtual void beforeRemove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoDumpTrigger�ǲ���DDN��·��Ϣ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoDumpTrigger: public CSysNetDDNLinkInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetDDNLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetDDNLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetDDNLinkInfo	Ҫ�����SysNetDDNLinkInfo
	virtual void beforeAdd(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
	
	///����ǰ����	
	///@param	pSysNetDDNLinkInfo	��ˢ�µ�CSysNetDDNLinkInfo
	///@param	pNewSysNetDDNLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetDDNLinkInfo	Ҫɾ����CSysNetDDNLinkInfo
	virtual void beforeRemove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoDumpTrigger�ǲ����ǻ�Ա��·ʹ����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoDumpTrigger: public CSysNetPseudMemberLinkInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetPseudMemberLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetPseudMemberLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetPseudMemberLinkInfo	Ҫ�����SysNetPseudMemberLinkInfo
	virtual void beforeAdd(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
	
	///����ǰ����	
	///@param	pSysNetPseudMemberLinkInfo	��ˢ�µ�CSysNetPseudMemberLinkInfo
	///@param	pNewSysNetPseudMemberLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetPseudMemberLinkInfo	Ҫɾ����CSysNetPseudMemberLinkInfo
	virtual void beforeRemove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoDumpTrigger�ǲ���Զ���豸��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoDumpTrigger: public CSysNetOuterDeviceInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetOuterDeviceInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetOuterDeviceInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetOuterDeviceInfo	Ҫ�����SysNetOuterDeviceInfo
	virtual void beforeAdd(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
	
	///����ǰ����	
	///@param	pSysNetOuterDeviceInfo	��ˢ�µ�CSysNetOuterDeviceInfo
	///@param	pNewSysNetOuterDeviceInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetOuterDeviceInfo	Ҫɾ����CSysNetOuterDeviceInfo
	virtual void beforeRemove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoDumpTrigger�ǲ�������ping���ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoDumpTrigger: public CSysLocalPingResultInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysLocalPingResultInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysLocalPingResultInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysLocalPingResultInfo	Ҫ�����SysLocalPingResultInfo
	virtual void beforeAdd(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo);
	
	///����ǰ����	
	///@param	pSysLocalPingResultInfo	��ˢ�µ�CSysLocalPingResultInfo
	///@param	pNewSysLocalPingResultInfo	�µ�ֵ
	virtual void beforeUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo);
	
	///ɾ��ǰ����
	///@param	pSysLocalPingResultInfo	Ҫɾ����CSysLocalPingResultInfo
	virtual void beforeRemove(CSysLocalPingResultInfo *pSysLocalPingResultInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoDumpTrigger�ǲ���Զ��ping���ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoDumpTrigger: public CSysRomotePingResultInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysRomotePingResultInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysRomotePingResultInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysRomotePingResultInfo	Ҫ�����SysRomotePingResultInfo
	virtual void beforeAdd(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo);
	
	///����ǰ����	
	///@param	pSysRomotePingResultInfo	��ˢ�µ�CSysRomotePingResultInfo
	///@param	pNewSysRomotePingResultInfo	�µ�ֵ
	virtual void beforeUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo);
	
	///ɾ��ǰ����
	///@param	pSysRomotePingResultInfo	Ҫɾ����CSysRomotePingResultInfo
	virtual void beforeRemove(CSysRomotePingResultInfo *pSysRomotePingResultInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesDumpTrigger�ǲ�����Աϯλ����״̬ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesDumpTrigger: public CSysParticTradeOrderStatesActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysParticTradeOrderStatesDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysParticTradeOrderStatesDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysParticTradeOrderStates	Ҫ�����SysParticTradeOrderStates
	virtual void beforeAdd(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates);
	
	///����ǰ����	
	///@param	pSysParticTradeOrderStates	��ˢ�µ�CSysParticTradeOrderStates
	///@param	pNewSysParticTradeOrderStates	�µ�ֵ
	virtual void beforeUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates);
	
	///ɾ��ǰ����
	///@param	pSysParticTradeOrderStates	Ҫɾ����CSysParticTradeOrderStates
	virtual void beforeRemove(CSysParticTradeOrderStates *pSysParticTradeOrderStates);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoDumpTrigger�ǲ���ϵͳ·����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoDumpTrigger: public CSysMdbRouterInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbRouterInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbRouterInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbRouterInfo	Ҫ�����SysMdbRouterInfo
	virtual void beforeAdd(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo);
	
	///����ǰ����	
	///@param	pSysMdbRouterInfo	��ˢ�µ�CSysMdbRouterInfo
	///@param	pNewSysMdbRouterInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbRouterInfo	Ҫɾ����CSysMdbRouterInfo
	virtual void beforeRemove(CSysMdbRouterInfo *pSysMdbRouterInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIODumpTrigger�ǲ�������I/O��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIODumpTrigger: public CSysMdbDiskIOActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbDiskIODumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbDiskIODumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbDiskIO	Ҫ�����SysMdbDiskIO
	virtual void beforeAdd(CWriteableSysMdbDiskIO *pSysMdbDiskIO);
	
	///����ǰ����	
	///@param	pSysMdbDiskIO	��ˢ�µ�CSysMdbDiskIO
	///@param	pNewSysMdbDiskIO	�µ�ֵ
	virtual void beforeUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO);
	
	///ɾ��ǰ����
	///@param	pSysMdbDiskIO	Ҫɾ����CSysMdbDiskIO
	virtual void beforeRemove(CSysMdbDiskIO *pSysMdbDiskIO);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoDumpTrigger�ǲ���ϵͳ״̬��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoDumpTrigger: public CSysMdbStatInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbStatInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbStatInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbStatInfo	Ҫ�����SysMdbStatInfo
	virtual void beforeAdd(CWriteableSysMdbStatInfo *pSysMdbStatInfo);
	
	///����ǰ����	
	///@param	pSysMdbStatInfo	��ˢ�µ�CSysMdbStatInfo
	///@param	pNewSysMdbStatInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo);
	
	///ɾ��ǰ����
	///@param	pSysMdbStatInfo	Ҫɾ����CSysMdbStatInfo
	virtual void beforeRemove(CSysMdbStatInfo *pSysMdbStatInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatDumpTrigger�ǲ�������ϵͳǰ�ñ�����Ӧ��Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatDumpTrigger: public CSysMdbTradeFrontOrderRttStatActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMdbTradeFrontOrderRttStatDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMdbTradeFrontOrderRttStatDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫ�����SysMdbTradeFrontOrderRttStat
	virtual void beforeAdd(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
	
	///����ǰ����	
	///@param	pSysMdbTradeFrontOrderRttStat	��ˢ�µ�CSysMdbTradeFrontOrderRttStat
	///@param	pNewSysMdbTradeFrontOrderRttStat	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat);
	
	///ɾ��ǰ����
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫɾ����CSysMdbTradeFrontOrderRttStat
	virtual void beforeRemove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusDumpTrigger�ǲ�����Լ״̬�л�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusDumpTrigger: public CSysInstrumentStatusActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysInstrumentStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysInstrumentStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysInstrumentStatus	Ҫ�����SysInstrumentStatus
	virtual void beforeAdd(CWriteableSysInstrumentStatus *pSysInstrumentStatus);
	
	///����ǰ����	
	///@param	pSysInstrumentStatus	��ˢ�µ�CSysInstrumentStatus
	///@param	pNewSysInstrumentStatus	�µ�ֵ
	virtual void beforeUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus);
	
	///ɾ��ǰ����
	///@param	pSysInstrumentStatus	Ҫɾ����CSysInstrumentStatus
	virtual void beforeRemove(CSysInstrumentStatus *pSysInstrumentStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrDumpTrigger�ǲ�����Լ���׽���Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrDumpTrigger: public CSysCurrTradingSegmentAttrActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysCurrTradingSegmentAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysCurrTradingSegmentAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysCurrTradingSegmentAttr	Ҫ�����SysCurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
	
	///����ǰ����	
	///@param	pSysCurrTradingSegmentAttr	��ˢ�µ�CSysCurrTradingSegmentAttr
	///@param	pNewSysCurrTradingSegmentAttr	�µ�ֵ
	virtual void beforeUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr);
	
	///ɾ��ǰ����
	///@param	pSysCurrTradingSegmentAttr	Ҫɾ����CSysCurrTradingSegmentAttr
	virtual void beforeRemove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostDumpTrigger�ǲ�����Ա��·���ñ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostDumpTrigger: public CSysMemberLinkCostActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysMemberLinkCostDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysMemberLinkCostDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysMemberLinkCost	Ҫ�����SysMemberLinkCost
	virtual void beforeAdd(CWriteableSysMemberLinkCost *pSysMemberLinkCost);
	
	///����ǰ����	
	///@param	pSysMemberLinkCost	��ˢ�µ�CSysMemberLinkCost
	///@param	pNewSysMemberLinkCost	�µ�ֵ
	virtual void beforeUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost);
	
	///ɾ��ǰ����
	///@param	pSysMemberLinkCost	Ҫɾ����CSysMemberLinkCost
	virtual void beforeRemove(CSysMemberLinkCost *pSysMemberLinkCost);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentDumpTrigger�ǲ�����Ա��·�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentDumpTrigger: public CSysNetPartylinkMonthlyRentActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetPartylinkMonthlyRentDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetPartylinkMonthlyRentDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetPartylinkMonthlyRent	Ҫ�����SysNetPartylinkMonthlyRent
	virtual void beforeAdd(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
	
	///����ǰ����	
	///@param	pSysNetPartylinkMonthlyRent	��ˢ�µ�CSysNetPartylinkMonthlyRent
	///@param	pNewSysNetPartylinkMonthlyRent	�µ�ֵ
	virtual void beforeUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent);
	
	///ɾ��ǰ����
	///@param	pSysNetPartylinkMonthlyRent	Ҫɾ����CSysNetPartylinkMonthlyRent
	virtual void beforeRemove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoDumpTrigger�ǲ�����Ա��·�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoDumpTrigger: public CSysNetNonPartyLinkInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSysNetNonPartyLinkInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSysNetNonPartyLinkInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSysNetNonPartyLinkInfo	Ҫ�����SysNetNonPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
	
	///����ǰ����	
	///@param	pSysNetNonPartyLinkInfo	��ˢ�µ�CSysNetNonPartyLinkInfo
	///@param	pNewSysNetNonPartyLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo);
	
	///ɾ��ǰ����
	///@param	pSysNetNonPartyLinkInfo	Ҫɾ����CSysNetNonPartyLinkInfo
	virtual void beforeRemove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDumpLog��һ�������е��޸���Dump��ʽ����Ľ�����������ʵ��
///@author	���ض�
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CDumpLog
{
public:
	///���췽��������һ�������
	///@param	pDB	Ҫ������ڴ����ݿ�
	///@param	pConfig	������Ϣ
	CDumpLog(CMemoryDB *pDB, CConfig *pConfig);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDumpLog(void);

	///����dump
	void start(void);
	
	///ֹͣdump
	void stop(void);
	
	///�Ƿ��Ѿ�����
	///@return	1��ʾ�Ѿ�������0��ʾû������
	int isStarted(void);
	
	///�����Ϣ
	///@param	format	��Ϣ��ʽ������fprintf��Ҫ��
	///@param	...	��Ϣ����ϸ����
	void dumpMsg(char *format,...);

private:
	///����ļ�
	FILE *m_DumpOutput;
	
	///�ڴ����ݿ�
	CMemoryDB *m_DB;
	
	///�Ƿ��Ѿ�����
	int m_Started;
	
	CSysInvalidateOrderDumpTrigger *m_SysInvalidateOrderTrigger;
	CSysOrderStatusDumpTrigger *m_SysOrderStatusTrigger;
	CSysBargainOrderDumpTrigger *m_SysBargainOrderTrigger;
	CSysInstPropertyDumpTrigger *m_SysInstPropertyTrigger;
	CSysMarginRateDumpTrigger *m_SysMarginRateTrigger;
	CSysPriceLimitDumpTrigger *m_SysPriceLimitTrigger;
	CSysPartPosiLimitDumpTrigger *m_SysPartPosiLimitTrigger;
	CSysClientPosiLimitDumpTrigger *m_SysClientPosiLimitTrigger;
	CSysSpecialPosiLimitDumpTrigger *m_SysSpecialPosiLimitTrigger;
	CSysTransactionChgDumpTrigger *m_SysTransactionChgTrigger;
	CSysClientChgDumpTrigger *m_SysClientChgTrigger;
	CSysPartClientChgDumpTrigger *m_SysPartClientChgTrigger;
	CSysPosiLimitChgDumpTrigger *m_SysPosiLimitChgTrigger;
	CSysClientPosiLimitChgDumpTrigger *m_SysClientPosiLimitChgTrigger;
	CSysSpecPosiLimitChgDumpTrigger *m_SysSpecPosiLimitChgTrigger;
	CSysHedgeDetailChgDumpTrigger *m_SysHedgeDetailChgTrigger;
	CSysParticipantChgDumpTrigger *m_SysParticipantChgTrigger;
	CSysMarginRateChgDumpTrigger *m_SysMarginRateChgTrigger;
	CSysUserIpChgDumpTrigger *m_SysUserIpChgTrigger;
	CSysPartTradeDumpTrigger *m_SysPartTradeTrigger;
	CSysMdbObjectAttrDumpTrigger *m_SysMdbObjectAttrTrigger;
	CSysMdbSyslogInfoDumpTrigger *m_SysMdbSyslogInfoTrigger;
	CSysUserInfoDumpTrigger *m_SysUserInfoTrigger;
	CSysOnlineUserInfoDumpTrigger *m_SysOnlineUserInfoTrigger;
	CSysWarningEventDumpTrigger *m_SysWarningEventTrigger;
	CSysWarningQueryDumpTrigger *m_SysWarningQueryTrigger;
	CSyslogEventDumpTrigger *m_SyslogEventTrigger;
	CSysEventDescripDumpTrigger *m_SysEventDescripTrigger;
	CRspQryHostEnvCommonDumpTrigger *m_RspQryHostEnvCommonTrigger;
	CRspQryHostEnvLanDumpTrigger *m_RspQryHostEnvLanTrigger;
	CRspQryHostEnvStorageDumpTrigger *m_RspQryHostEnvStorageTrigger;
	CRspQryHostEnvIODumpTrigger *m_RspQryHostEnvIOTrigger;
	CRspQryHostEnvFSDumpTrigger *m_RspQryHostEnvFSTrigger;
	CRspQryHostEnvSwapDumpTrigger *m_RspQryHostEnvSwapTrigger;
	CRspQryHostEnvLanCfgDumpTrigger *m_RspQryHostEnvLanCfgTrigger;
	CSysMdbTopCpuInfoDumpTrigger *m_SysMdbTopCpuInfoTrigger;
	CSysMdbTopMemInfoDumpTrigger *m_SysMdbTopMemInfoTrigger;
	CSysMdbTopProcessInfoDumpTrigger *m_SysMdbTopProcessInfoTrigger;
	CSysMdbFileSystemInfoDumpTrigger *m_SysMdbFileSystemInfoTrigger;
	CSysMdbNetworkInfoDumpTrigger *m_SysMdbNetworkInfoTrigger;
	CSysParticipantInitDumpTrigger *m_SysParticipantInitTrigger;
	CSysUserInitDumpTrigger *m_SysUserInitTrigger;
	CSysClientInitDumpTrigger *m_SysClientInitTrigger;
	CSysTradeUserLoginInfoDumpTrigger *m_SysTradeUserLoginInfoTrigger;
	CSysMdbWebAppInfoDumpTrigger *m_SysMdbWebAppInfoTrigger;
	CSysMdbMemPoolInfoDumpTrigger *m_SysMdbMemPoolInfoTrigger;
	CSysMdbConnectorInfoDumpTrigger *m_SysMdbConnectorInfoTrigger;
	CSysMdbDBQueryDumpTrigger *m_SysMdbDBQueryTrigger;
	CSysNetAreaDumpTrigger *m_SysNetAreaTrigger;
	CSysNetSubAreaDumpTrigger *m_SysNetSubAreaTrigger;
	CSysNetSubAreaIPDumpTrigger *m_SysNetSubAreaIPTrigger;
	CSysNetFuncAreaDumpTrigger *m_SysNetFuncAreaTrigger;
	CSysNetDeviceDumpTrigger *m_SysNetDeviceTrigger;
	CSysNetDeviceLinkedDumpTrigger *m_SysNetDeviceLinkedTrigger;
	CSysNetOIDDumpTrigger *m_SysNetOIDTrigger;
	CSysNetDeviceTypeDumpTrigger *m_SysNetDeviceTypeTrigger;
	CSysNetTimePolicyDumpTrigger *m_SysNetTimePolicyTrigger;
	CSysNetGatherTaskDumpTrigger *m_SysNetGatherTaskTrigger;
	CSysNetDeviceCategoryDumpTrigger *m_SysNetDeviceCategoryTrigger;
	CSysNetManufactoryDumpTrigger *m_SysNetManufactoryTrigger;
	CSysNetCommunityDumpTrigger *m_SysNetCommunityTrigger;
	CSysNetPortTypeDumpTrigger *m_SysNetPortTypeTrigger;
	CSysNetInterfaceDumpTrigger *m_SysNetInterfaceTrigger;
	CSysNetGeneralOIDDumpTrigger *m_SysNetGeneralOIDTrigger;
	CSysNetMonitorTypeDumpTrigger *m_SysNetMonitorTypeTrigger;
	CSysNetMonitorAttrScopeDumpTrigger *m_SysNetMonitorAttrScopeTrigger;
	CSysNetMonitorAttrTypeDumpTrigger *m_SysNetMonitorAttrTypeTrigger;
	CSysNetMonitorCommandTypeDumpTrigger *m_SysNetMonitorCommandTypeTrigger;
	CSysNetMonitorActionGroupDumpTrigger *m_SysNetMonitorActionGroupTrigger;
	CSysNetMonitorDeviceGroupDumpTrigger *m_SysNetMonitorDeviceGroupTrigger;
	CSysNetMonitorTaskInfoDumpTrigger *m_SysNetMonitorTaskInfoTrigger;
	CSysNetMonitorTaskObjectSetDumpTrigger *m_SysNetMonitorTaskObjectSetTrigger;
	CSysNetMonitorTaskResultDumpTrigger *m_SysNetMonitorTaskResultTrigger;
	CSysNetPartyLinkInfoDumpTrigger *m_SysNetPartyLinkInfoTrigger;
	CSysNetDelPartyLinkInfoDumpTrigger *m_SysNetDelPartyLinkInfoTrigger;
	CSysNetPartyLinkAddrChangeDumpTrigger *m_SysNetPartyLinkAddrChangeTrigger;
	CSysNetMonitorActionAttrDumpTrigger *m_SysNetMonitorActionAttrTrigger;
	CSysNetModuleDumpTrigger *m_SysNetModuleTrigger;
	CSysNetEventExprDumpTrigger *m_SysNetEventExprTrigger;
	CSysNetEventTypeDumpTrigger *m_SysNetEventTypeTrigger;
	CSysNetSubEventTypeDumpTrigger *m_SysNetSubEventTypeTrigger;
	CSysNetEventLevelDumpTrigger *m_SysNetEventLevelTrigger;
	CSysNetMonitorDeviceTaskDumpTrigger *m_SysNetMonitorDeviceTaskTrigger;
	CSysNetMonitorTaskInstAttrsDumpTrigger *m_SysNetMonitorTaskInstAttrsTrigger;
	CSysNetBaseLineDumpTrigger *m_SysNetBaseLineTrigger;
	CSysNetBaseLineTaskDumpTrigger *m_SysNetBaseLineTaskTrigger;
	CSysMdbNetPartyLinkStatusInfoDumpTrigger *m_SysMdbNetPartyLinkStatusInfoTrigger;
	CSysNetMemberSDHLineInfoDumpTrigger *m_SysNetMemberSDHLineInfoTrigger;
	CSysNetDDNLinkInfoDumpTrigger *m_SysNetDDNLinkInfoTrigger;
	CSysNetPseudMemberLinkInfoDumpTrigger *m_SysNetPseudMemberLinkInfoTrigger;
	CSysNetOuterDeviceInfoDumpTrigger *m_SysNetOuterDeviceInfoTrigger;
	CSysLocalPingResultInfoDumpTrigger *m_SysLocalPingResultInfoTrigger;
	CSysRomotePingResultInfoDumpTrigger *m_SysRomotePingResultInfoTrigger;
	CSysParticTradeOrderStatesDumpTrigger *m_SysParticTradeOrderStatesTrigger;
	CSysMdbRouterInfoDumpTrigger *m_SysMdbRouterInfoTrigger;
	CSysMdbDiskIODumpTrigger *m_SysMdbDiskIOTrigger;
	CSysMdbStatInfoDumpTrigger *m_SysMdbStatInfoTrigger;
	CSysMdbTradeFrontOrderRttStatDumpTrigger *m_SysMdbTradeFrontOrderRttStatTrigger;
	CSysInstrumentStatusDumpTrigger *m_SysInstrumentStatusTrigger;
	CSysCurrTradingSegmentAttrDumpTrigger *m_SysCurrTradingSegmentAttrTrigger;
	CSysMemberLinkCostDumpTrigger *m_SysMemberLinkCostTrigger;
	CSysNetPartylinkMonthlyRentDumpTrigger *m_SysNetPartylinkMonthlyRentTrigger;
	CSysNetNonPartyLinkInfoDumpTrigger *m_SysNetNonPartyLinkInfoTrigger;
};

#endif
