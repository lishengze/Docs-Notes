/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CResource.cpp
///@briefʵ������CTransaction
///@history 
///20020301	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "CTransaction.h"
#include "CTimeMeter.h"

#define MAX_TRANSACTION_PRIORITY 3

CMemoryStack<CTransactionSavePoint> CTransactionSavePoint::resourceList;
/*
CTransactionSavePoint::CTransactionSavePoint(CTransaction *pTransaction)
{
	m_Transaction=pTransaction;
	pTransaction->setSavePoint(this);
	pTransaction->m_SavePointCount++;
}
*/
CTransactionSavePoint *CTransactionSavePoint::alloc(CTransaction *pTransaction)
{
	CTransactionSavePoint *pSavePoint=resourceList.alloc();
	pSavePoint->m_Transaction=pTransaction;
	pTransaction->setSavePoint(pSavePoint);
	pTransaction->m_SavePointCount++;
	return pSavePoint;
}

CTransactionSavePoint::~CTransactionSavePoint(void)
{
	m_Transaction->m_SavePointCount--;
}

void CTransactionSavePoint::free(void)
{
	m_Transaction->m_SavePointCount--;
	resourceList.free(this);
}

CTransaction::CTransaction(void)
{
	m_SavePointCount=0;
	ref=NULL;
}

CTransaction::~CTransaction(void)
{
	rollback();
}
/*
void CTransaction::addResource(CResource *pResource)
{
	if (mergeBack(size(),pResource,false))
	{
		///�ϲ��ɹ����ǾͲ��ü���
		pResource->free();
	}
	else
	{
		///�ϲ����ɹ����Ǿ�Ҫ����
		push_back(pResource);
	}
}
*/	
void CTransaction::commit(void)
{
	vector<CResource *> toBeCommit[MAX_TRANSACTION_PRIORITY+1];
	int priority;
	int pos;
	///��ǰ��󣬽���Ҫcommit����Դ����toBeCommit������
	for (pos=size()-1;pos>=0;pos--)
	{
		if (at(pos)->isControl())
		{
			///����ǿ�������Դ����ֱ���ͷ���
			at(pos)->free();
			continue;
		}
		if (m_SavePointCount>0)
		{
			if (mergeBack(pos,at(pos),true))
			{
				///���ϲ����ˣ��ǾͲ���commit��
				at(pos)->free();
				continue;
			}
		}
		///�ϲ��������Ǿ�ֻ�÷���ȴ�commit�Ķ�������
		priority=at(pos)->getPriority();
		if (priority<0)
		{
			priority=0;
		}
		else if (priority>MAX_TRANSACTION_PRIORITY)
		{
			priority=MAX_TRANSACTION_PRIORITY;
		}
		toBeCommit[priority].push_back(at(pos));
		///�����Ч�ʲ��ߣ�������Դ�Ķ��η��Ľ�����ɺϲ���commit��
		///��Ȼû�н�������Ľף����ǻ��Ƕ�ϵ����һ����Ӱ�졣���ǲ���
		///m_SavePointCount�������Ƿ���ҪmergeBack�����ʹ�󲿷�û��
		///ʹ��savepoint������Ч����ߡ�
	}
	///�������ȼ��ӵ͵��ߣ�λ�ôӺ���ǰ�����������Դ��commit���ͷ�
	for (priority=0;priority<=MAX_TRANSACTION_PRIORITY;priority++)
	{
		vector<CResource *>::reverse_iterator it;
		for (it=toBeCommit[priority].rbegin();it<toBeCommit[priority].rend();it++)
		//vector<CResource *>::iterator it;
		//for (it=toBeCommit[priority].begin();it<toBeCommit[priority].end();it++)
		{
			(*it)->commit();
			(*it)->free();
		}
	}
	clear();
	m_SavePointCount=0;
}
/*
bool CTransaction::mergeBack(int pos,CResource *pResource,bool forceMerge)
{
	METER_START(3);
	for (pos--;pos>=0;pos--)
	{
		switch (at(pos)->merge(pResource))
		{
		case RESOURCE_MERGE_OK:
			///�ϲ��ɹ�
			METER_END(3);
			return true;
		case RESOURCE_MERGE_FAIL_THIS:
			///���û�кϲ��ɹ���Ӧ��������һ��
			break;
		case RESOURCE_MERGE_FAIL_ALL:
			///ȫ��ʧ��
			if (!forceMerge)
			{
				//����������
				METER_END(3);
				return false;
			}
			break;
		}
	}
	METER_END(3);
	return false;
}
*/
void CTransaction::rollback(void)
{
	rollbackToSavePoint(NULL);
	m_SavePointCount=0;
}

void CTransaction::rollbackToSavePoint(CTransactionSavePoint *pSavePoint)
{
	int pos;
	///�Ӻ���ǰ��rollback����ָ���������ǰ����Դ
	for (pos=size()-1;pos>=0;pos--)
	{
		if (at(pos)==pSavePoint)
		{
			///�ҵ��ñ�����ˣ��Ǿ�ɾ�������������Դ������Ҫ����Ŀǰ���������㣬Ȼ�󷵻�
			erase(begin()+pos+1,end());
			return;
		}
		///����Դ�Ǳ�����Ժ����Դ���Ǿͽ���rollback���������ͷ�
		at(pos)->rollback();
		at(pos)->free();
	}
	///������Դ���Ѿ�rollback�ˣ�����û���ҵ�ָ���ı���㣬�Ǿ͵���ȫ��rollback
	clear();
}

void CTransaction::setSavePoint(CTransactionSavePoint *pSavePoint)
{
	push_back(pSavePoint);
}
