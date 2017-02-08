/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseIteratorRepository.cpp
///@brief	实现了若干个内存数据库的iterator库，以便各种查询
///@history 
///20061222	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseIteratorRepository.h"

CMonitorEntity *CMonitorEntitySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMonitorEntitySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMonitorEntitySingleIterator::UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMonitorEntity,pTransaction,updateIndex);
}

CMonitorEntity *CMonitorEntityFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMonitorEntity *pResult;
		pResult=m_baseIterator->next();
		if (pResult==NULL)
		{
			m_finished=true;
			return NULL;
		}
		if (m_predict->isValid(pResult))
		{
			return pResult;
		}
		if (m_continueResult)
		{
			m_finished=true;
			return NULL;
		}
	}
}
	
void CMonitorEntityFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMonitorEntityFilter::UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMonitorEntity,pTransaction,updateIndex);
}

CMonitorEntity *CMonitorEntityLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMonitorEntity *pResult;
			pResult=m_baseIterator[m_id]->next();
			if (pResult==NULL)
			{
				break;
			}
			return pResult;
		}
	}
	return NULL;
}
	
void CMonitorEntityLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMonitorEntityLinkIterator::UpdateCurrent(CWriteableMonitorEntity * pMonitorEntity,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMonitorEntity,pTransaction,updateIndex);
}

CEventEntity *CEventEntitySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CEventEntitySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CEventEntitySingleIterator::UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pEventEntity,pTransaction,updateIndex);
}

CEventEntity *CEventEntityFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CEventEntity *pResult;
		pResult=m_baseIterator->next();
		if (pResult==NULL)
		{
			m_finished=true;
			return NULL;
		}
		if (m_predict->isValid(pResult))
		{
			return pResult;
		}
		if (m_continueResult)
		{
			m_finished=true;
			return NULL;
		}
	}
}
	
void CEventEntityFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CEventEntityFilter::UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pEventEntity,pTransaction,updateIndex);
}

CEventEntity *CEventEntityLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CEventEntity *pResult;
			pResult=m_baseIterator[m_id]->next();
			if (pResult==NULL)
			{
				break;
			}
			return pResult;
		}
	}
	return NULL;
}
	
void CEventEntityLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CEventEntityLinkIterator::UpdateCurrent(CWriteableEventEntity * pEventEntity,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pEventEntity,pTransaction,updateIndex);
}

