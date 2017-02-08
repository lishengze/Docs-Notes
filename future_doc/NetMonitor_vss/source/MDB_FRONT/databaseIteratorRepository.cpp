/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseIteratorRepository.cpp
///@brief	实现了若干个内存数据库的iterator库，以便各种查询
///@history 
///20061222	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseIteratorRepository.h"

CSysInvalidateOrder *CSysInvalidateOrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysInvalidateOrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysInvalidateOrderSingleIterator::UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysInvalidateOrder,pTransaction,updateIndex);
}

CSysInvalidateOrder *CSysInvalidateOrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysInvalidateOrder *pResult;
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
	
void CSysInvalidateOrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysInvalidateOrderFilter::UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysInvalidateOrder,pTransaction,updateIndex);
}

CSysInvalidateOrder *CSysInvalidateOrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysInvalidateOrder *pResult;
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
	
void CSysInvalidateOrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysInvalidateOrderLinkIterator::UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysInvalidateOrder,pTransaction,updateIndex);
}

CSysOrderStatus *CSysOrderStatusSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysOrderStatusSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysOrderStatusSingleIterator::UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysOrderStatus,pTransaction,updateIndex);
}

CSysOrderStatus *CSysOrderStatusFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysOrderStatus *pResult;
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
	
void CSysOrderStatusFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysOrderStatusFilter::UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysOrderStatus,pTransaction,updateIndex);
}

CSysOrderStatus *CSysOrderStatusLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysOrderStatus *pResult;
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
	
void CSysOrderStatusLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysOrderStatusLinkIterator::UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysOrderStatus,pTransaction,updateIndex);
}

CSysBargainOrder *CSysBargainOrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysBargainOrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysBargainOrderSingleIterator::UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysBargainOrder,pTransaction,updateIndex);
}

CSysBargainOrder *CSysBargainOrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysBargainOrder *pResult;
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
	
void CSysBargainOrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysBargainOrderFilter::UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysBargainOrder,pTransaction,updateIndex);
}

CSysBargainOrder *CSysBargainOrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysBargainOrder *pResult;
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
	
void CSysBargainOrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysBargainOrderLinkIterator::UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysBargainOrder,pTransaction,updateIndex);
}

CSysInstProperty *CSysInstPropertySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysInstPropertySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysInstPropertySingleIterator::UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysInstProperty,pTransaction,updateIndex);
}

CSysInstProperty *CSysInstPropertyFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysInstProperty *pResult;
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
	
void CSysInstPropertyFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysInstPropertyFilter::UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysInstProperty,pTransaction,updateIndex);
}

CSysInstProperty *CSysInstPropertyLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysInstProperty *pResult;
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
	
void CSysInstPropertyLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysInstPropertyLinkIterator::UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysInstProperty,pTransaction,updateIndex);
}

CSysMarginRate *CSysMarginRateSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMarginRateSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMarginRateSingleIterator::UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMarginRate,pTransaction,updateIndex);
}

CSysMarginRate *CSysMarginRateFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMarginRate *pResult;
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
	
void CSysMarginRateFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMarginRateFilter::UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMarginRate,pTransaction,updateIndex);
}

CSysMarginRate *CSysMarginRateLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMarginRate *pResult;
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
	
void CSysMarginRateLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMarginRateLinkIterator::UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMarginRate,pTransaction,updateIndex);
}

CSysPriceLimit *CSysPriceLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysPriceLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysPriceLimitSingleIterator::UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysPriceLimit,pTransaction,updateIndex);
}

CSysPriceLimit *CSysPriceLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysPriceLimit *pResult;
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
	
void CSysPriceLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysPriceLimitFilter::UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysPriceLimit,pTransaction,updateIndex);
}

CSysPriceLimit *CSysPriceLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysPriceLimit *pResult;
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
	
void CSysPriceLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysPriceLimitLinkIterator::UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysPriceLimit,pTransaction,updateIndex);
}

CSysPartPosiLimit *CSysPartPosiLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysPartPosiLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysPartPosiLimitSingleIterator::UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysPartPosiLimit,pTransaction,updateIndex);
}

CSysPartPosiLimit *CSysPartPosiLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysPartPosiLimit *pResult;
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
	
void CSysPartPosiLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysPartPosiLimitFilter::UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysPartPosiLimit,pTransaction,updateIndex);
}

CSysPartPosiLimit *CSysPartPosiLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysPartPosiLimit *pResult;
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
	
void CSysPartPosiLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysPartPosiLimitLinkIterator::UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysPartPosiLimit,pTransaction,updateIndex);
}

CSysClientPosiLimit *CSysClientPosiLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysClientPosiLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysClientPosiLimitSingleIterator::UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysClientPosiLimit,pTransaction,updateIndex);
}

CSysClientPosiLimit *CSysClientPosiLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysClientPosiLimit *pResult;
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
	
void CSysClientPosiLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysClientPosiLimitFilter::UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysClientPosiLimit,pTransaction,updateIndex);
}

CSysClientPosiLimit *CSysClientPosiLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysClientPosiLimit *pResult;
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
	
void CSysClientPosiLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysClientPosiLimitLinkIterator::UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysClientPosiLimit,pTransaction,updateIndex);
}

CSysSpecialPosiLimit *CSysSpecialPosiLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysSpecialPosiLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysSpecialPosiLimitSingleIterator::UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysSpecialPosiLimit,pTransaction,updateIndex);
}

CSysSpecialPosiLimit *CSysSpecialPosiLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysSpecialPosiLimit *pResult;
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
	
void CSysSpecialPosiLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysSpecialPosiLimitFilter::UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysSpecialPosiLimit,pTransaction,updateIndex);
}

CSysSpecialPosiLimit *CSysSpecialPosiLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysSpecialPosiLimit *pResult;
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
	
void CSysSpecialPosiLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysSpecialPosiLimitLinkIterator::UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysSpecialPosiLimit,pTransaction,updateIndex);
}

CSysTransactionChg *CSysTransactionChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysTransactionChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysTransactionChgSingleIterator::UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysTransactionChg,pTransaction,updateIndex);
}

CSysTransactionChg *CSysTransactionChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysTransactionChg *pResult;
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
	
void CSysTransactionChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysTransactionChgFilter::UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysTransactionChg,pTransaction,updateIndex);
}

CSysTransactionChg *CSysTransactionChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysTransactionChg *pResult;
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
	
void CSysTransactionChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysTransactionChgLinkIterator::UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysTransactionChg,pTransaction,updateIndex);
}

CSysClientChg *CSysClientChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysClientChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysClientChgSingleIterator::UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysClientChg,pTransaction,updateIndex);
}

CSysClientChg *CSysClientChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysClientChg *pResult;
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
	
void CSysClientChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysClientChgFilter::UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysClientChg,pTransaction,updateIndex);
}

CSysClientChg *CSysClientChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysClientChg *pResult;
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
	
void CSysClientChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysClientChgLinkIterator::UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysClientChg,pTransaction,updateIndex);
}

CSysPartClientChg *CSysPartClientChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysPartClientChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysPartClientChgSingleIterator::UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysPartClientChg,pTransaction,updateIndex);
}

CSysPartClientChg *CSysPartClientChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysPartClientChg *pResult;
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
	
void CSysPartClientChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysPartClientChgFilter::UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysPartClientChg,pTransaction,updateIndex);
}

CSysPartClientChg *CSysPartClientChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysPartClientChg *pResult;
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
	
void CSysPartClientChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysPartClientChgLinkIterator::UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysPartClientChg,pTransaction,updateIndex);
}

CSysPosiLimitChg *CSysPosiLimitChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysPosiLimitChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysPosiLimitChgSingleIterator::UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysPosiLimitChg,pTransaction,updateIndex);
}

CSysPosiLimitChg *CSysPosiLimitChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysPosiLimitChg *pResult;
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
	
void CSysPosiLimitChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysPosiLimitChgFilter::UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysPosiLimitChg,pTransaction,updateIndex);
}

CSysPosiLimitChg *CSysPosiLimitChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysPosiLimitChg *pResult;
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
	
void CSysPosiLimitChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysPosiLimitChgLinkIterator::UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysPosiLimitChg,pTransaction,updateIndex);
}

CSysClientPosiLimitChg *CSysClientPosiLimitChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysClientPosiLimitChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysClientPosiLimitChgSingleIterator::UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysClientPosiLimitChg,pTransaction,updateIndex);
}

CSysClientPosiLimitChg *CSysClientPosiLimitChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysClientPosiLimitChg *pResult;
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
	
void CSysClientPosiLimitChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysClientPosiLimitChgFilter::UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysClientPosiLimitChg,pTransaction,updateIndex);
}

CSysClientPosiLimitChg *CSysClientPosiLimitChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysClientPosiLimitChg *pResult;
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
	
void CSysClientPosiLimitChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysClientPosiLimitChgLinkIterator::UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysClientPosiLimitChg,pTransaction,updateIndex);
}

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysSpecPosiLimitChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysSpecPosiLimitChgSingleIterator::UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysSpecPosiLimitChg,pTransaction,updateIndex);
}

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysSpecPosiLimitChg *pResult;
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
	
void CSysSpecPosiLimitChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysSpecPosiLimitChgFilter::UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysSpecPosiLimitChg,pTransaction,updateIndex);
}

CSysSpecPosiLimitChg *CSysSpecPosiLimitChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysSpecPosiLimitChg *pResult;
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
	
void CSysSpecPosiLimitChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysSpecPosiLimitChgLinkIterator::UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysSpecPosiLimitChg,pTransaction,updateIndex);
}

CSysHedgeDetailChg *CSysHedgeDetailChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysHedgeDetailChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysHedgeDetailChgSingleIterator::UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysHedgeDetailChg,pTransaction,updateIndex);
}

CSysHedgeDetailChg *CSysHedgeDetailChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysHedgeDetailChg *pResult;
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
	
void CSysHedgeDetailChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysHedgeDetailChgFilter::UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysHedgeDetailChg,pTransaction,updateIndex);
}

CSysHedgeDetailChg *CSysHedgeDetailChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysHedgeDetailChg *pResult;
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
	
void CSysHedgeDetailChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysHedgeDetailChgLinkIterator::UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysHedgeDetailChg,pTransaction,updateIndex);
}

CSysParticipantChg *CSysParticipantChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysParticipantChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysParticipantChgSingleIterator::UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysParticipantChg,pTransaction,updateIndex);
}

CSysParticipantChg *CSysParticipantChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysParticipantChg *pResult;
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
	
void CSysParticipantChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysParticipantChgFilter::UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysParticipantChg,pTransaction,updateIndex);
}

CSysParticipantChg *CSysParticipantChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysParticipantChg *pResult;
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
	
void CSysParticipantChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysParticipantChgLinkIterator::UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysParticipantChg,pTransaction,updateIndex);
}

CSysMarginRateChg *CSysMarginRateChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMarginRateChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMarginRateChgSingleIterator::UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMarginRateChg,pTransaction,updateIndex);
}

CSysMarginRateChg *CSysMarginRateChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMarginRateChg *pResult;
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
	
void CSysMarginRateChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMarginRateChgFilter::UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMarginRateChg,pTransaction,updateIndex);
}

CSysMarginRateChg *CSysMarginRateChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMarginRateChg *pResult;
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
	
void CSysMarginRateChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMarginRateChgLinkIterator::UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMarginRateChg,pTransaction,updateIndex);
}

CSysUserIpChg *CSysUserIpChgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysUserIpChgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysUserIpChgSingleIterator::UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysUserIpChg,pTransaction,updateIndex);
}

CSysUserIpChg *CSysUserIpChgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysUserIpChg *pResult;
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
	
void CSysUserIpChgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysUserIpChgFilter::UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysUserIpChg,pTransaction,updateIndex);
}

CSysUserIpChg *CSysUserIpChgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysUserIpChg *pResult;
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
	
void CSysUserIpChgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysUserIpChgLinkIterator::UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysUserIpChg,pTransaction,updateIndex);
}

CSysPartTrade *CSysPartTradeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysPartTradeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysPartTradeSingleIterator::UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysPartTrade,pTransaction,updateIndex);
}

CSysPartTrade *CSysPartTradeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysPartTrade *pResult;
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
	
void CSysPartTradeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysPartTradeFilter::UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysPartTrade,pTransaction,updateIndex);
}

CSysPartTrade *CSysPartTradeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysPartTrade *pResult;
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
	
void CSysPartTradeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysPartTradeLinkIterator::UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysPartTrade,pTransaction,updateIndex);
}

CSysMdbObjectAttr *CSysMdbObjectAttrSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbObjectAttrSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbObjectAttrSingleIterator::UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbObjectAttr,pTransaction,updateIndex);
}

CSysMdbObjectAttr *CSysMdbObjectAttrFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbObjectAttr *pResult;
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
	
void CSysMdbObjectAttrFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbObjectAttrFilter::UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbObjectAttr,pTransaction,updateIndex);
}

CSysMdbObjectAttr *CSysMdbObjectAttrLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbObjectAttr *pResult;
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
	
void CSysMdbObjectAttrLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbObjectAttrLinkIterator::UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbObjectAttr,pTransaction,updateIndex);
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbSyslogInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbSyslogInfoSingleIterator::UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbSyslogInfo,pTransaction,updateIndex);
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbSyslogInfo *pResult;
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
	
void CSysMdbSyslogInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbSyslogInfoFilter::UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbSyslogInfo,pTransaction,updateIndex);
}

CSysMdbSyslogInfo *CSysMdbSyslogInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbSyslogInfo *pResult;
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
	
void CSysMdbSyslogInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbSyslogInfoLinkIterator::UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbSyslogInfo,pTransaction,updateIndex);
}

CSysUserInfo *CSysUserInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysUserInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysUserInfoSingleIterator::UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysUserInfo,pTransaction,updateIndex);
}

CSysUserInfo *CSysUserInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysUserInfo *pResult;
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
	
void CSysUserInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysUserInfoFilter::UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysUserInfo,pTransaction,updateIndex);
}

CSysUserInfo *CSysUserInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysUserInfo *pResult;
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
	
void CSysUserInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysUserInfoLinkIterator::UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysUserInfo,pTransaction,updateIndex);
}

CSysOnlineUserInfo *CSysOnlineUserInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysOnlineUserInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysOnlineUserInfoSingleIterator::UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysOnlineUserInfo,pTransaction,updateIndex);
}

CSysOnlineUserInfo *CSysOnlineUserInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysOnlineUserInfo *pResult;
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
	
void CSysOnlineUserInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysOnlineUserInfoFilter::UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysOnlineUserInfo,pTransaction,updateIndex);
}

CSysOnlineUserInfo *CSysOnlineUserInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysOnlineUserInfo *pResult;
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
	
void CSysOnlineUserInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysOnlineUserInfoLinkIterator::UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysOnlineUserInfo,pTransaction,updateIndex);
}

CSysWarningEvent *CSysWarningEventSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysWarningEventSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysWarningEventSingleIterator::UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysWarningEvent,pTransaction,updateIndex);
}

CSysWarningEvent *CSysWarningEventFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysWarningEvent *pResult;
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
	
void CSysWarningEventFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysWarningEventFilter::UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysWarningEvent,pTransaction,updateIndex);
}

CSysWarningEvent *CSysWarningEventLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysWarningEvent *pResult;
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
	
void CSysWarningEventLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysWarningEventLinkIterator::UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysWarningEvent,pTransaction,updateIndex);
}

CSysWarningQuery *CSysWarningQuerySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysWarningQuerySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysWarningQuerySingleIterator::UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysWarningQuery,pTransaction,updateIndex);
}

CSysWarningQuery *CSysWarningQueryFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysWarningQuery *pResult;
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
	
void CSysWarningQueryFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysWarningQueryFilter::UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysWarningQuery,pTransaction,updateIndex);
}

CSysWarningQuery *CSysWarningQueryLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysWarningQuery *pResult;
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
	
void CSysWarningQueryLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysWarningQueryLinkIterator::UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysWarningQuery,pTransaction,updateIndex);
}

CSyslogEvent *CSyslogEventSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSyslogEventSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSyslogEventSingleIterator::UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSyslogEvent,pTransaction,updateIndex);
}

CSyslogEvent *CSyslogEventFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSyslogEvent *pResult;
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
	
void CSyslogEventFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSyslogEventFilter::UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSyslogEvent,pTransaction,updateIndex);
}

CSyslogEvent *CSyslogEventLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSyslogEvent *pResult;
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
	
void CSyslogEventLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSyslogEventLinkIterator::UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSyslogEvent,pTransaction,updateIndex);
}

CSysEventDescrip *CSysEventDescripSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysEventDescripSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysEventDescripSingleIterator::UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysEventDescrip,pTransaction,updateIndex);
}

CSysEventDescrip *CSysEventDescripFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysEventDescrip *pResult;
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
	
void CSysEventDescripFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysEventDescripFilter::UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysEventDescrip,pTransaction,updateIndex);
}

CSysEventDescrip *CSysEventDescripLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysEventDescrip *pResult;
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
	
void CSysEventDescripLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysEventDescripLinkIterator::UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysEventDescrip,pTransaction,updateIndex);
}

CRspQryHostEnvCommon *CRspQryHostEnvCommonSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRspQryHostEnvCommonSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRspQryHostEnvCommonSingleIterator::UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRspQryHostEnvCommon,pTransaction,updateIndex);
}

CRspQryHostEnvCommon *CRspQryHostEnvCommonFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRspQryHostEnvCommon *pResult;
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
	
void CRspQryHostEnvCommonFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvCommonFilter::UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRspQryHostEnvCommon,pTransaction,updateIndex);
}

CRspQryHostEnvCommon *CRspQryHostEnvCommonLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRspQryHostEnvCommon *pResult;
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
	
void CRspQryHostEnvCommonLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvCommonLinkIterator::UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRspQryHostEnvCommon,pTransaction,updateIndex);
}

CRspQryHostEnvLan *CRspQryHostEnvLanSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRspQryHostEnvLanSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRspQryHostEnvLanSingleIterator::UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRspQryHostEnvLan,pTransaction,updateIndex);
}

CRspQryHostEnvLan *CRspQryHostEnvLanFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRspQryHostEnvLan *pResult;
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
	
void CRspQryHostEnvLanFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvLanFilter::UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRspQryHostEnvLan,pTransaction,updateIndex);
}

CRspQryHostEnvLan *CRspQryHostEnvLanLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRspQryHostEnvLan *pResult;
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
	
void CRspQryHostEnvLanLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvLanLinkIterator::UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRspQryHostEnvLan,pTransaction,updateIndex);
}

CRspQryHostEnvStorage *CRspQryHostEnvStorageSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRspQryHostEnvStorageSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRspQryHostEnvStorageSingleIterator::UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRspQryHostEnvStorage,pTransaction,updateIndex);
}

CRspQryHostEnvStorage *CRspQryHostEnvStorageFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRspQryHostEnvStorage *pResult;
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
	
void CRspQryHostEnvStorageFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvStorageFilter::UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRspQryHostEnvStorage,pTransaction,updateIndex);
}

CRspQryHostEnvStorage *CRspQryHostEnvStorageLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRspQryHostEnvStorage *pResult;
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
	
void CRspQryHostEnvStorageLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvStorageLinkIterator::UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRspQryHostEnvStorage,pTransaction,updateIndex);
}

CRspQryHostEnvIO *CRspQryHostEnvIOSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRspQryHostEnvIOSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRspQryHostEnvIOSingleIterator::UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRspQryHostEnvIO,pTransaction,updateIndex);
}

CRspQryHostEnvIO *CRspQryHostEnvIOFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRspQryHostEnvIO *pResult;
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
	
void CRspQryHostEnvIOFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvIOFilter::UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRspQryHostEnvIO,pTransaction,updateIndex);
}

CRspQryHostEnvIO *CRspQryHostEnvIOLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRspQryHostEnvIO *pResult;
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
	
void CRspQryHostEnvIOLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvIOLinkIterator::UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRspQryHostEnvIO,pTransaction,updateIndex);
}

CRspQryHostEnvFS *CRspQryHostEnvFSSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRspQryHostEnvFSSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRspQryHostEnvFSSingleIterator::UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRspQryHostEnvFS,pTransaction,updateIndex);
}

CRspQryHostEnvFS *CRspQryHostEnvFSFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRspQryHostEnvFS *pResult;
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
	
void CRspQryHostEnvFSFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvFSFilter::UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRspQryHostEnvFS,pTransaction,updateIndex);
}

CRspQryHostEnvFS *CRspQryHostEnvFSLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRspQryHostEnvFS *pResult;
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
	
void CRspQryHostEnvFSLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvFSLinkIterator::UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRspQryHostEnvFS,pTransaction,updateIndex);
}

CRspQryHostEnvSwap *CRspQryHostEnvSwapSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRspQryHostEnvSwapSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRspQryHostEnvSwapSingleIterator::UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRspQryHostEnvSwap,pTransaction,updateIndex);
}

CRspQryHostEnvSwap *CRspQryHostEnvSwapFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRspQryHostEnvSwap *pResult;
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
	
void CRspQryHostEnvSwapFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvSwapFilter::UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRspQryHostEnvSwap,pTransaction,updateIndex);
}

CRspQryHostEnvSwap *CRspQryHostEnvSwapLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRspQryHostEnvSwap *pResult;
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
	
void CRspQryHostEnvSwapLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvSwapLinkIterator::UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRspQryHostEnvSwap,pTransaction,updateIndex);
}

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRspQryHostEnvLanCfgSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRspQryHostEnvLanCfgSingleIterator::UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRspQryHostEnvLanCfg,pTransaction,updateIndex);
}

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRspQryHostEnvLanCfg *pResult;
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
	
void CRspQryHostEnvLanCfgFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvLanCfgFilter::UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRspQryHostEnvLanCfg,pTransaction,updateIndex);
}

CRspQryHostEnvLanCfg *CRspQryHostEnvLanCfgLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRspQryHostEnvLanCfg *pResult;
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
	
void CRspQryHostEnvLanCfgLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRspQryHostEnvLanCfgLinkIterator::UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRspQryHostEnvLanCfg,pTransaction,updateIndex);
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbTopCpuInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbTopCpuInfoSingleIterator::UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbTopCpuInfo,pTransaction,updateIndex);
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbTopCpuInfo *pResult;
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
	
void CSysMdbTopCpuInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbTopCpuInfoFilter::UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbTopCpuInfo,pTransaction,updateIndex);
}

CSysMdbTopCpuInfo *CSysMdbTopCpuInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbTopCpuInfo *pResult;
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
	
void CSysMdbTopCpuInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbTopCpuInfoLinkIterator::UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbTopCpuInfo,pTransaction,updateIndex);
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbTopMemInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbTopMemInfoSingleIterator::UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbTopMemInfo,pTransaction,updateIndex);
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbTopMemInfo *pResult;
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
	
void CSysMdbTopMemInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbTopMemInfoFilter::UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbTopMemInfo,pTransaction,updateIndex);
}

CSysMdbTopMemInfo *CSysMdbTopMemInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbTopMemInfo *pResult;
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
	
void CSysMdbTopMemInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbTopMemInfoLinkIterator::UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbTopMemInfo,pTransaction,updateIndex);
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbTopProcessInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbTopProcessInfoSingleIterator::UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbTopProcessInfo,pTransaction,updateIndex);
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbTopProcessInfo *pResult;
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
	
void CSysMdbTopProcessInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbTopProcessInfoFilter::UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbTopProcessInfo,pTransaction,updateIndex);
}

CSysMdbTopProcessInfo *CSysMdbTopProcessInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbTopProcessInfo *pResult;
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
	
void CSysMdbTopProcessInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbTopProcessInfoLinkIterator::UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbTopProcessInfo,pTransaction,updateIndex);
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbFileSystemInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbFileSystemInfoSingleIterator::UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbFileSystemInfo,pTransaction,updateIndex);
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbFileSystemInfo *pResult;
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
	
void CSysMdbFileSystemInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbFileSystemInfoFilter::UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbFileSystemInfo,pTransaction,updateIndex);
}

CSysMdbFileSystemInfo *CSysMdbFileSystemInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbFileSystemInfo *pResult;
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
	
void CSysMdbFileSystemInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbFileSystemInfoLinkIterator::UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbFileSystemInfo,pTransaction,updateIndex);
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbNetworkInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbNetworkInfoSingleIterator::UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbNetworkInfo,pTransaction,updateIndex);
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbNetworkInfo *pResult;
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
	
void CSysMdbNetworkInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbNetworkInfoFilter::UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbNetworkInfo,pTransaction,updateIndex);
}

CSysMdbNetworkInfo *CSysMdbNetworkInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbNetworkInfo *pResult;
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
	
void CSysMdbNetworkInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbNetworkInfoLinkIterator::UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbNetworkInfo,pTransaction,updateIndex);
}

CSysParticipantInit *CSysParticipantInitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysParticipantInitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysParticipantInitSingleIterator::UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysParticipantInit,pTransaction,updateIndex);
}

CSysParticipantInit *CSysParticipantInitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysParticipantInit *pResult;
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
	
void CSysParticipantInitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysParticipantInitFilter::UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysParticipantInit,pTransaction,updateIndex);
}

CSysParticipantInit *CSysParticipantInitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysParticipantInit *pResult;
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
	
void CSysParticipantInitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysParticipantInitLinkIterator::UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysParticipantInit,pTransaction,updateIndex);
}

CSysUserInit *CSysUserInitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysUserInitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysUserInitSingleIterator::UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysUserInit,pTransaction,updateIndex);
}

CSysUserInit *CSysUserInitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysUserInit *pResult;
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
	
void CSysUserInitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysUserInitFilter::UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysUserInit,pTransaction,updateIndex);
}

CSysUserInit *CSysUserInitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysUserInit *pResult;
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
	
void CSysUserInitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysUserInitLinkIterator::UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysUserInit,pTransaction,updateIndex);
}

CSysClientInit *CSysClientInitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysClientInitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysClientInitSingleIterator::UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysClientInit,pTransaction,updateIndex);
}

CSysClientInit *CSysClientInitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysClientInit *pResult;
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
	
void CSysClientInitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysClientInitFilter::UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysClientInit,pTransaction,updateIndex);
}

CSysClientInit *CSysClientInitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysClientInit *pResult;
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
	
void CSysClientInitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysClientInitLinkIterator::UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysClientInit,pTransaction,updateIndex);
}

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysTradeUserLoginInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysTradeUserLoginInfoSingleIterator::UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysTradeUserLoginInfo,pTransaction,updateIndex);
}

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysTradeUserLoginInfo *pResult;
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
	
void CSysTradeUserLoginInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysTradeUserLoginInfoFilter::UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysTradeUserLoginInfo,pTransaction,updateIndex);
}

CSysTradeUserLoginInfo *CSysTradeUserLoginInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysTradeUserLoginInfo *pResult;
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
	
void CSysTradeUserLoginInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysTradeUserLoginInfoLinkIterator::UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysTradeUserLoginInfo,pTransaction,updateIndex);
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbWebAppInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbWebAppInfoSingleIterator::UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbWebAppInfo,pTransaction,updateIndex);
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbWebAppInfo *pResult;
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
	
void CSysMdbWebAppInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbWebAppInfoFilter::UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbWebAppInfo,pTransaction,updateIndex);
}

CSysMdbWebAppInfo *CSysMdbWebAppInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbWebAppInfo *pResult;
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
	
void CSysMdbWebAppInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbWebAppInfoLinkIterator::UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbWebAppInfo,pTransaction,updateIndex);
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbMemPoolInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbMemPoolInfoSingleIterator::UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbMemPoolInfo,pTransaction,updateIndex);
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbMemPoolInfo *pResult;
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
	
void CSysMdbMemPoolInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbMemPoolInfoFilter::UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbMemPoolInfo,pTransaction,updateIndex);
}

CSysMdbMemPoolInfo *CSysMdbMemPoolInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbMemPoolInfo *pResult;
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
	
void CSysMdbMemPoolInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbMemPoolInfoLinkIterator::UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbMemPoolInfo,pTransaction,updateIndex);
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbConnectorInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbConnectorInfoSingleIterator::UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbConnectorInfo,pTransaction,updateIndex);
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbConnectorInfo *pResult;
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
	
void CSysMdbConnectorInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbConnectorInfoFilter::UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbConnectorInfo,pTransaction,updateIndex);
}

CSysMdbConnectorInfo *CSysMdbConnectorInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbConnectorInfo *pResult;
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
	
void CSysMdbConnectorInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbConnectorInfoLinkIterator::UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbConnectorInfo,pTransaction,updateIndex);
}

CSysMdbDBQuery *CSysMdbDBQuerySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbDBQuerySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbDBQuerySingleIterator::UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbDBQuery,pTransaction,updateIndex);
}

CSysMdbDBQuery *CSysMdbDBQueryFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbDBQuery *pResult;
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
	
void CSysMdbDBQueryFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbDBQueryFilter::UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbDBQuery,pTransaction,updateIndex);
}

CSysMdbDBQuery *CSysMdbDBQueryLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbDBQuery *pResult;
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
	
void CSysMdbDBQueryLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbDBQueryLinkIterator::UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbDBQuery,pTransaction,updateIndex);
}

CSysNetArea *CSysNetAreaSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetAreaSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetAreaSingleIterator::UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetArea,pTransaction,updateIndex);
}

CSysNetArea *CSysNetAreaFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetArea *pResult;
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
	
void CSysNetAreaFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetAreaFilter::UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetArea,pTransaction,updateIndex);
}

CSysNetArea *CSysNetAreaLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetArea *pResult;
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
	
void CSysNetAreaLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetAreaLinkIterator::UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetArea,pTransaction,updateIndex);
}

CSysNetSubArea *CSysNetSubAreaSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetSubAreaSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetSubAreaSingleIterator::UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetSubArea,pTransaction,updateIndex);
}

CSysNetSubArea *CSysNetSubAreaFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetSubArea *pResult;
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
	
void CSysNetSubAreaFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetSubAreaFilter::UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetSubArea,pTransaction,updateIndex);
}

CSysNetSubArea *CSysNetSubAreaLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetSubArea *pResult;
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
	
void CSysNetSubAreaLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetSubAreaLinkIterator::UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetSubArea,pTransaction,updateIndex);
}

CSysNetSubAreaIP *CSysNetSubAreaIPSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetSubAreaIPSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetSubAreaIPSingleIterator::UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetSubAreaIP,pTransaction,updateIndex);
}

CSysNetSubAreaIP *CSysNetSubAreaIPFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetSubAreaIP *pResult;
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
	
void CSysNetSubAreaIPFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetSubAreaIPFilter::UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetSubAreaIP,pTransaction,updateIndex);
}

CSysNetSubAreaIP *CSysNetSubAreaIPLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetSubAreaIP *pResult;
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
	
void CSysNetSubAreaIPLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetSubAreaIPLinkIterator::UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetSubAreaIP,pTransaction,updateIndex);
}

CSysNetFuncArea *CSysNetFuncAreaSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetFuncAreaSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetFuncAreaSingleIterator::UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetFuncArea,pTransaction,updateIndex);
}

CSysNetFuncArea *CSysNetFuncAreaFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetFuncArea *pResult;
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
	
void CSysNetFuncAreaFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetFuncAreaFilter::UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetFuncArea,pTransaction,updateIndex);
}

CSysNetFuncArea *CSysNetFuncAreaLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetFuncArea *pResult;
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
	
void CSysNetFuncAreaLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetFuncAreaLinkIterator::UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetFuncArea,pTransaction,updateIndex);
}

CSysNetDevice *CSysNetDeviceSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetDeviceSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetDeviceSingleIterator::UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetDevice,pTransaction,updateIndex);
}

CSysNetDevice *CSysNetDeviceFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetDevice *pResult;
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
	
void CSysNetDeviceFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceFilter::UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetDevice,pTransaction,updateIndex);
}

CSysNetDevice *CSysNetDeviceLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetDevice *pResult;
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
	
void CSysNetDeviceLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceLinkIterator::UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetDevice,pTransaction,updateIndex);
}

CSysNetDeviceLinked *CSysNetDeviceLinkedSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetDeviceLinkedSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetDeviceLinkedSingleIterator::UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetDeviceLinked,pTransaction,updateIndex);
}

CSysNetDeviceLinked *CSysNetDeviceLinkedFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetDeviceLinked *pResult;
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
	
void CSysNetDeviceLinkedFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceLinkedFilter::UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetDeviceLinked,pTransaction,updateIndex);
}

CSysNetDeviceLinked *CSysNetDeviceLinkedLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetDeviceLinked *pResult;
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
	
void CSysNetDeviceLinkedLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceLinkedLinkIterator::UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetDeviceLinked,pTransaction,updateIndex);
}

CSysNetOID *CSysNetOIDSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetOIDSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetOIDSingleIterator::UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetOID,pTransaction,updateIndex);
}

CSysNetOID *CSysNetOIDFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetOID *pResult;
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
	
void CSysNetOIDFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetOIDFilter::UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetOID,pTransaction,updateIndex);
}

CSysNetOID *CSysNetOIDLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetOID *pResult;
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
	
void CSysNetOIDLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetOIDLinkIterator::UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetOID,pTransaction,updateIndex);
}

CSysNetDeviceType *CSysNetDeviceTypeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetDeviceTypeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetDeviceTypeSingleIterator::UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetDeviceType,pTransaction,updateIndex);
}

CSysNetDeviceType *CSysNetDeviceTypeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetDeviceType *pResult;
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
	
void CSysNetDeviceTypeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceTypeFilter::UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetDeviceType,pTransaction,updateIndex);
}

CSysNetDeviceType *CSysNetDeviceTypeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetDeviceType *pResult;
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
	
void CSysNetDeviceTypeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceTypeLinkIterator::UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetDeviceType,pTransaction,updateIndex);
}

CSysNetTimePolicy *CSysNetTimePolicySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetTimePolicySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetTimePolicySingleIterator::UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetTimePolicy,pTransaction,updateIndex);
}

CSysNetTimePolicy *CSysNetTimePolicyFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetTimePolicy *pResult;
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
	
void CSysNetTimePolicyFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetTimePolicyFilter::UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetTimePolicy,pTransaction,updateIndex);
}

CSysNetTimePolicy *CSysNetTimePolicyLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetTimePolicy *pResult;
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
	
void CSysNetTimePolicyLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetTimePolicyLinkIterator::UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetTimePolicy,pTransaction,updateIndex);
}

CSysNetGatherTask *CSysNetGatherTaskSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetGatherTaskSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetGatherTaskSingleIterator::UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetGatherTask,pTransaction,updateIndex);
}

CSysNetGatherTask *CSysNetGatherTaskFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetGatherTask *pResult;
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
	
void CSysNetGatherTaskFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetGatherTaskFilter::UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetGatherTask,pTransaction,updateIndex);
}

CSysNetGatherTask *CSysNetGatherTaskLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetGatherTask *pResult;
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
	
void CSysNetGatherTaskLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetGatherTaskLinkIterator::UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetGatherTask,pTransaction,updateIndex);
}

CSysNetDeviceCategory *CSysNetDeviceCategorySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetDeviceCategorySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetDeviceCategorySingleIterator::UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetDeviceCategory,pTransaction,updateIndex);
}

CSysNetDeviceCategory *CSysNetDeviceCategoryFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetDeviceCategory *pResult;
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
	
void CSysNetDeviceCategoryFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceCategoryFilter::UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetDeviceCategory,pTransaction,updateIndex);
}

CSysNetDeviceCategory *CSysNetDeviceCategoryLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetDeviceCategory *pResult;
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
	
void CSysNetDeviceCategoryLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetDeviceCategoryLinkIterator::UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetDeviceCategory,pTransaction,updateIndex);
}

CSysNetManufactory *CSysNetManufactorySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetManufactorySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetManufactorySingleIterator::UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetManufactory,pTransaction,updateIndex);
}

CSysNetManufactory *CSysNetManufactoryFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetManufactory *pResult;
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
	
void CSysNetManufactoryFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetManufactoryFilter::UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetManufactory,pTransaction,updateIndex);
}

CSysNetManufactory *CSysNetManufactoryLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetManufactory *pResult;
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
	
void CSysNetManufactoryLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetManufactoryLinkIterator::UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetManufactory,pTransaction,updateIndex);
}

CSysNetCommunity *CSysNetCommunitySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetCommunitySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetCommunitySingleIterator::UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetCommunity,pTransaction,updateIndex);
}

CSysNetCommunity *CSysNetCommunityFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetCommunity *pResult;
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
	
void CSysNetCommunityFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetCommunityFilter::UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetCommunity,pTransaction,updateIndex);
}

CSysNetCommunity *CSysNetCommunityLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetCommunity *pResult;
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
	
void CSysNetCommunityLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetCommunityLinkIterator::UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetCommunity,pTransaction,updateIndex);
}

CSysNetPortType *CSysNetPortTypeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetPortTypeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetPortTypeSingleIterator::UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetPortType,pTransaction,updateIndex);
}

CSysNetPortType *CSysNetPortTypeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetPortType *pResult;
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
	
void CSysNetPortTypeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetPortTypeFilter::UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetPortType,pTransaction,updateIndex);
}

CSysNetPortType *CSysNetPortTypeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetPortType *pResult;
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
	
void CSysNetPortTypeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetPortTypeLinkIterator::UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetPortType,pTransaction,updateIndex);
}

CSysNetInterface *CSysNetInterfaceSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetInterfaceSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetInterfaceSingleIterator::UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetInterface,pTransaction,updateIndex);
}

CSysNetInterface *CSysNetInterfaceFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetInterface *pResult;
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
	
void CSysNetInterfaceFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetInterfaceFilter::UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetInterface,pTransaction,updateIndex);
}

CSysNetInterface *CSysNetInterfaceLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetInterface *pResult;
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
	
void CSysNetInterfaceLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetInterfaceLinkIterator::UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetInterface,pTransaction,updateIndex);
}

CSysNetGeneralOID *CSysNetGeneralOIDSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetGeneralOIDSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetGeneralOIDSingleIterator::UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetGeneralOID,pTransaction,updateIndex);
}

CSysNetGeneralOID *CSysNetGeneralOIDFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetGeneralOID *pResult;
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
	
void CSysNetGeneralOIDFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetGeneralOIDFilter::UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetGeneralOID,pTransaction,updateIndex);
}

CSysNetGeneralOID *CSysNetGeneralOIDLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetGeneralOID *pResult;
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
	
void CSysNetGeneralOIDLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetGeneralOIDLinkIterator::UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetGeneralOID,pTransaction,updateIndex);
}

CSysNetMonitorType *CSysNetMonitorTypeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorTypeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorTypeSingleIterator::UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorType,pTransaction,updateIndex);
}

CSysNetMonitorType *CSysNetMonitorTypeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorType *pResult;
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
	
void CSysNetMonitorTypeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTypeFilter::UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorType,pTransaction,updateIndex);
}

CSysNetMonitorType *CSysNetMonitorTypeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorType *pResult;
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
	
void CSysNetMonitorTypeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTypeLinkIterator::UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorType,pTransaction,updateIndex);
}

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorAttrScopeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorAttrScopeSingleIterator::UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorAttrScope,pTransaction,updateIndex);
}

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorAttrScope *pResult;
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
	
void CSysNetMonitorAttrScopeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorAttrScopeFilter::UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorAttrScope,pTransaction,updateIndex);
}

CSysNetMonitorAttrScope *CSysNetMonitorAttrScopeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorAttrScope *pResult;
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
	
void CSysNetMonitorAttrScopeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorAttrScopeLinkIterator::UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorAttrScope,pTransaction,updateIndex);
}

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorAttrTypeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorAttrTypeSingleIterator::UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorAttrType,pTransaction,updateIndex);
}

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorAttrType *pResult;
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
	
void CSysNetMonitorAttrTypeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorAttrTypeFilter::UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorAttrType,pTransaction,updateIndex);
}

CSysNetMonitorAttrType *CSysNetMonitorAttrTypeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorAttrType *pResult;
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
	
void CSysNetMonitorAttrTypeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorAttrTypeLinkIterator::UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorAttrType,pTransaction,updateIndex);
}

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorCommandTypeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorCommandTypeSingleIterator::UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorCommandType,pTransaction,updateIndex);
}

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorCommandType *pResult;
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
	
void CSysNetMonitorCommandTypeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorCommandTypeFilter::UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorCommandType,pTransaction,updateIndex);
}

CSysNetMonitorCommandType *CSysNetMonitorCommandTypeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorCommandType *pResult;
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
	
void CSysNetMonitorCommandTypeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorCommandTypeLinkIterator::UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorCommandType,pTransaction,updateIndex);
}

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorActionGroupSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorActionGroupSingleIterator::UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorActionGroup,pTransaction,updateIndex);
}

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorActionGroup *pResult;
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
	
void CSysNetMonitorActionGroupFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorActionGroupFilter::UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorActionGroup,pTransaction,updateIndex);
}

CSysNetMonitorActionGroup *CSysNetMonitorActionGroupLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorActionGroup *pResult;
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
	
void CSysNetMonitorActionGroupLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorActionGroupLinkIterator::UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorActionGroup,pTransaction,updateIndex);
}

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorDeviceGroupSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorDeviceGroupSingleIterator::UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorDeviceGroup,pTransaction,updateIndex);
}

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorDeviceGroup *pResult;
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
	
void CSysNetMonitorDeviceGroupFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorDeviceGroupFilter::UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorDeviceGroup,pTransaction,updateIndex);
}

CSysNetMonitorDeviceGroup *CSysNetMonitorDeviceGroupLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorDeviceGroup *pResult;
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
	
void CSysNetMonitorDeviceGroupLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorDeviceGroupLinkIterator::UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorDeviceGroup,pTransaction,updateIndex);
}

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorTaskInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorTaskInfoSingleIterator::UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorTaskInfo,pTransaction,updateIndex);
}

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorTaskInfo *pResult;
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
	
void CSysNetMonitorTaskInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskInfoFilter::UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorTaskInfo,pTransaction,updateIndex);
}

CSysNetMonitorTaskInfo *CSysNetMonitorTaskInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorTaskInfo *pResult;
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
	
void CSysNetMonitorTaskInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskInfoLinkIterator::UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorTaskInfo,pTransaction,updateIndex);
}

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorTaskObjectSetSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorTaskObjectSetSingleIterator::UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorTaskObjectSet,pTransaction,updateIndex);
}

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorTaskObjectSet *pResult;
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
	
void CSysNetMonitorTaskObjectSetFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskObjectSetFilter::UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorTaskObjectSet,pTransaction,updateIndex);
}

CSysNetMonitorTaskObjectSet *CSysNetMonitorTaskObjectSetLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorTaskObjectSet *pResult;
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
	
void CSysNetMonitorTaskObjectSetLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskObjectSetLinkIterator::UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorTaskObjectSet,pTransaction,updateIndex);
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorTaskResultSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorTaskResultSingleIterator::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorTaskResult,pTransaction,updateIndex);
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorTaskResult *pResult;
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
	
void CSysNetMonitorTaskResultFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskResultFilter::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorTaskResult,pTransaction,updateIndex);
}

CSysNetMonitorTaskResult *CSysNetMonitorTaskResultLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorTaskResult *pResult;
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
	
void CSysNetMonitorTaskResultLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskResultLinkIterator::UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorTaskResult,pTransaction,updateIndex);
}

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetPartyLinkInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetPartyLinkInfoSingleIterator::UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetPartyLinkInfo *pResult;
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
	
void CSysNetPartyLinkInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetPartyLinkInfoFilter::UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetPartyLinkInfo *CSysNetPartyLinkInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetPartyLinkInfo *pResult;
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
	
void CSysNetPartyLinkInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetPartyLinkInfoLinkIterator::UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetDelPartyLinkInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetDelPartyLinkInfoSingleIterator::UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetDelPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetDelPartyLinkInfo *pResult;
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
	
void CSysNetDelPartyLinkInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetDelPartyLinkInfoFilter::UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetDelPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetDelPartyLinkInfo *CSysNetDelPartyLinkInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetDelPartyLinkInfo *pResult;
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
	
void CSysNetDelPartyLinkInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetDelPartyLinkInfoLinkIterator::UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetDelPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetPartyLinkAddrChangeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetPartyLinkAddrChangeSingleIterator::UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetPartyLinkAddrChange,pTransaction,updateIndex);
}

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetPartyLinkAddrChange *pResult;
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
	
void CSysNetPartyLinkAddrChangeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetPartyLinkAddrChangeFilter::UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetPartyLinkAddrChange,pTransaction,updateIndex);
}

CSysNetPartyLinkAddrChange *CSysNetPartyLinkAddrChangeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetPartyLinkAddrChange *pResult;
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
	
void CSysNetPartyLinkAddrChangeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetPartyLinkAddrChangeLinkIterator::UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetPartyLinkAddrChange,pTransaction,updateIndex);
}

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorActionAttrSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorActionAttrSingleIterator::UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorActionAttr,pTransaction,updateIndex);
}

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorActionAttr *pResult;
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
	
void CSysNetMonitorActionAttrFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorActionAttrFilter::UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorActionAttr,pTransaction,updateIndex);
}

CSysNetMonitorActionAttr *CSysNetMonitorActionAttrLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorActionAttr *pResult;
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
	
void CSysNetMonitorActionAttrLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorActionAttrLinkIterator::UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorActionAttr,pTransaction,updateIndex);
}

CSysNetModule *CSysNetModuleSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetModuleSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetModuleSingleIterator::UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetModule,pTransaction,updateIndex);
}

CSysNetModule *CSysNetModuleFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetModule *pResult;
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
	
void CSysNetModuleFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetModuleFilter::UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetModule,pTransaction,updateIndex);
}

CSysNetModule *CSysNetModuleLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetModule *pResult;
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
	
void CSysNetModuleLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetModuleLinkIterator::UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetModule,pTransaction,updateIndex);
}

CSysNetEventExpr *CSysNetEventExprSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetEventExprSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetEventExprSingleIterator::UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetEventExpr,pTransaction,updateIndex);
}

CSysNetEventExpr *CSysNetEventExprFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetEventExpr *pResult;
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
	
void CSysNetEventExprFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetEventExprFilter::UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetEventExpr,pTransaction,updateIndex);
}

CSysNetEventExpr *CSysNetEventExprLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetEventExpr *pResult;
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
	
void CSysNetEventExprLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetEventExprLinkIterator::UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetEventExpr,pTransaction,updateIndex);
}

CSysNetEventType *CSysNetEventTypeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetEventTypeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetEventTypeSingleIterator::UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetEventType,pTransaction,updateIndex);
}

CSysNetEventType *CSysNetEventTypeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetEventType *pResult;
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
	
void CSysNetEventTypeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetEventTypeFilter::UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetEventType,pTransaction,updateIndex);
}

CSysNetEventType *CSysNetEventTypeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetEventType *pResult;
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
	
void CSysNetEventTypeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetEventTypeLinkIterator::UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetEventType,pTransaction,updateIndex);
}

CSysNetSubEventType *CSysNetSubEventTypeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetSubEventTypeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetSubEventTypeSingleIterator::UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetSubEventType,pTransaction,updateIndex);
}

CSysNetSubEventType *CSysNetSubEventTypeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetSubEventType *pResult;
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
	
void CSysNetSubEventTypeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetSubEventTypeFilter::UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetSubEventType,pTransaction,updateIndex);
}

CSysNetSubEventType *CSysNetSubEventTypeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetSubEventType *pResult;
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
	
void CSysNetSubEventTypeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetSubEventTypeLinkIterator::UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetSubEventType,pTransaction,updateIndex);
}

CSysNetEventLevel *CSysNetEventLevelSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetEventLevelSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetEventLevelSingleIterator::UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetEventLevel,pTransaction,updateIndex);
}

CSysNetEventLevel *CSysNetEventLevelFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetEventLevel *pResult;
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
	
void CSysNetEventLevelFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetEventLevelFilter::UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetEventLevel,pTransaction,updateIndex);
}

CSysNetEventLevel *CSysNetEventLevelLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetEventLevel *pResult;
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
	
void CSysNetEventLevelLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetEventLevelLinkIterator::UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetEventLevel,pTransaction,updateIndex);
}

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorDeviceTaskSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorDeviceTaskSingleIterator::UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorDeviceTask,pTransaction,updateIndex);
}

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorDeviceTask *pResult;
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
	
void CSysNetMonitorDeviceTaskFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorDeviceTaskFilter::UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorDeviceTask,pTransaction,updateIndex);
}

CSysNetMonitorDeviceTask *CSysNetMonitorDeviceTaskLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorDeviceTask *pResult;
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
	
void CSysNetMonitorDeviceTaskLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorDeviceTaskLinkIterator::UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorDeviceTask,pTransaction,updateIndex);
}

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMonitorTaskInstAttrsSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMonitorTaskInstAttrsSingleIterator::UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMonitorTaskInstAttrs,pTransaction,updateIndex);
}

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMonitorTaskInstAttrs *pResult;
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
	
void CSysNetMonitorTaskInstAttrsFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskInstAttrsFilter::UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMonitorTaskInstAttrs,pTransaction,updateIndex);
}

CSysNetMonitorTaskInstAttrs *CSysNetMonitorTaskInstAttrsLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMonitorTaskInstAttrs *pResult;
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
	
void CSysNetMonitorTaskInstAttrsLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMonitorTaskInstAttrsLinkIterator::UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMonitorTaskInstAttrs,pTransaction,updateIndex);
}

CSysNetBaseLine *CSysNetBaseLineSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetBaseLineSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetBaseLineSingleIterator::UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetBaseLine,pTransaction,updateIndex);
}

CSysNetBaseLine *CSysNetBaseLineFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetBaseLine *pResult;
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
	
void CSysNetBaseLineFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetBaseLineFilter::UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetBaseLine,pTransaction,updateIndex);
}

CSysNetBaseLine *CSysNetBaseLineLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetBaseLine *pResult;
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
	
void CSysNetBaseLineLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetBaseLineLinkIterator::UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetBaseLine,pTransaction,updateIndex);
}

CSysNetBaseLineTask *CSysNetBaseLineTaskSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetBaseLineTaskSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetBaseLineTaskSingleIterator::UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetBaseLineTask,pTransaction,updateIndex);
}

CSysNetBaseLineTask *CSysNetBaseLineTaskFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetBaseLineTask *pResult;
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
	
void CSysNetBaseLineTaskFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetBaseLineTaskFilter::UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetBaseLineTask,pTransaction,updateIndex);
}

CSysNetBaseLineTask *CSysNetBaseLineTaskLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetBaseLineTask *pResult;
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
	
void CSysNetBaseLineTaskLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetBaseLineTaskLinkIterator::UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetBaseLineTask,pTransaction,updateIndex);
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbNetPartyLinkStatusInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbNetPartyLinkStatusInfoSingleIterator::UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbNetPartyLinkStatusInfo,pTransaction,updateIndex);
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbNetPartyLinkStatusInfo *pResult;
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
	
void CSysMdbNetPartyLinkStatusInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbNetPartyLinkStatusInfoFilter::UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbNetPartyLinkStatusInfo,pTransaction,updateIndex);
}

CSysMdbNetPartyLinkStatusInfo *CSysMdbNetPartyLinkStatusInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbNetPartyLinkStatusInfo *pResult;
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
	
void CSysMdbNetPartyLinkStatusInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbNetPartyLinkStatusInfoLinkIterator::UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbNetPartyLinkStatusInfo,pTransaction,updateIndex);
}

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetMemberSDHLineInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetMemberSDHLineInfoSingleIterator::UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetMemberSDHLineInfo,pTransaction,updateIndex);
}

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetMemberSDHLineInfo *pResult;
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
	
void CSysNetMemberSDHLineInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetMemberSDHLineInfoFilter::UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetMemberSDHLineInfo,pTransaction,updateIndex);
}

CSysNetMemberSDHLineInfo *CSysNetMemberSDHLineInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetMemberSDHLineInfo *pResult;
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
	
void CSysNetMemberSDHLineInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetMemberSDHLineInfoLinkIterator::UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetMemberSDHLineInfo,pTransaction,updateIndex);
}

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetDDNLinkInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetDDNLinkInfoSingleIterator::UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetDDNLinkInfo,pTransaction,updateIndex);
}

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetDDNLinkInfo *pResult;
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
	
void CSysNetDDNLinkInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetDDNLinkInfoFilter::UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetDDNLinkInfo,pTransaction,updateIndex);
}

CSysNetDDNLinkInfo *CSysNetDDNLinkInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetDDNLinkInfo *pResult;
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
	
void CSysNetDDNLinkInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetDDNLinkInfoLinkIterator::UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetDDNLinkInfo,pTransaction,updateIndex);
}

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetPseudMemberLinkInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetPseudMemberLinkInfoSingleIterator::UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetPseudMemberLinkInfo,pTransaction,updateIndex);
}

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetPseudMemberLinkInfo *pResult;
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
	
void CSysNetPseudMemberLinkInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetPseudMemberLinkInfoFilter::UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetPseudMemberLinkInfo,pTransaction,updateIndex);
}

CSysNetPseudMemberLinkInfo *CSysNetPseudMemberLinkInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetPseudMemberLinkInfo *pResult;
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
	
void CSysNetPseudMemberLinkInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetPseudMemberLinkInfoLinkIterator::UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetPseudMemberLinkInfo,pTransaction,updateIndex);
}

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetOuterDeviceInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetOuterDeviceInfoSingleIterator::UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetOuterDeviceInfo,pTransaction,updateIndex);
}

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetOuterDeviceInfo *pResult;
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
	
void CSysNetOuterDeviceInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetOuterDeviceInfoFilter::UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetOuterDeviceInfo,pTransaction,updateIndex);
}

CSysNetOuterDeviceInfo *CSysNetOuterDeviceInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetOuterDeviceInfo *pResult;
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
	
void CSysNetOuterDeviceInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetOuterDeviceInfoLinkIterator::UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetOuterDeviceInfo,pTransaction,updateIndex);
}

CSysLocalPingResultInfo *CSysLocalPingResultInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysLocalPingResultInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysLocalPingResultInfoSingleIterator::UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysLocalPingResultInfo,pTransaction,updateIndex);
}

CSysLocalPingResultInfo *CSysLocalPingResultInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysLocalPingResultInfo *pResult;
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
	
void CSysLocalPingResultInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysLocalPingResultInfoFilter::UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysLocalPingResultInfo,pTransaction,updateIndex);
}

CSysLocalPingResultInfo *CSysLocalPingResultInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysLocalPingResultInfo *pResult;
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
	
void CSysLocalPingResultInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysLocalPingResultInfoLinkIterator::UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysLocalPingResultInfo,pTransaction,updateIndex);
}

CSysRomotePingResultInfo *CSysRomotePingResultInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysRomotePingResultInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysRomotePingResultInfoSingleIterator::UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysRomotePingResultInfo,pTransaction,updateIndex);
}

CSysRomotePingResultInfo *CSysRomotePingResultInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysRomotePingResultInfo *pResult;
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
	
void CSysRomotePingResultInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysRomotePingResultInfoFilter::UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysRomotePingResultInfo,pTransaction,updateIndex);
}

CSysRomotePingResultInfo *CSysRomotePingResultInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysRomotePingResultInfo *pResult;
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
	
void CSysRomotePingResultInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysRomotePingResultInfoLinkIterator::UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysRomotePingResultInfo,pTransaction,updateIndex);
}

CSysParticTradeOrderStates *CSysParticTradeOrderStatesSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysParticTradeOrderStatesSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysParticTradeOrderStatesSingleIterator::UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysParticTradeOrderStates,pTransaction,updateIndex);
}

CSysParticTradeOrderStates *CSysParticTradeOrderStatesFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysParticTradeOrderStates *pResult;
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
	
void CSysParticTradeOrderStatesFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysParticTradeOrderStatesFilter::UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysParticTradeOrderStates,pTransaction,updateIndex);
}

CSysParticTradeOrderStates *CSysParticTradeOrderStatesLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysParticTradeOrderStates *pResult;
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
	
void CSysParticTradeOrderStatesLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysParticTradeOrderStatesLinkIterator::UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysParticTradeOrderStates,pTransaction,updateIndex);
}

CSysMdbRouterInfo *CSysMdbRouterInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbRouterInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbRouterInfoSingleIterator::UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbRouterInfo,pTransaction,updateIndex);
}

CSysMdbRouterInfo *CSysMdbRouterInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbRouterInfo *pResult;
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
	
void CSysMdbRouterInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbRouterInfoFilter::UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbRouterInfo,pTransaction,updateIndex);
}

CSysMdbRouterInfo *CSysMdbRouterInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbRouterInfo *pResult;
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
	
void CSysMdbRouterInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbRouterInfoLinkIterator::UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbRouterInfo,pTransaction,updateIndex);
}

CSysMdbDiskIO *CSysMdbDiskIOSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbDiskIOSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbDiskIOSingleIterator::UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbDiskIO,pTransaction,updateIndex);
}

CSysMdbDiskIO *CSysMdbDiskIOFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbDiskIO *pResult;
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
	
void CSysMdbDiskIOFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbDiskIOFilter::UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbDiskIO,pTransaction,updateIndex);
}

CSysMdbDiskIO *CSysMdbDiskIOLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbDiskIO *pResult;
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
	
void CSysMdbDiskIOLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbDiskIOLinkIterator::UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbDiskIO,pTransaction,updateIndex);
}

CSysMdbStatInfo *CSysMdbStatInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbStatInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbStatInfoSingleIterator::UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbStatInfo,pTransaction,updateIndex);
}

CSysMdbStatInfo *CSysMdbStatInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbStatInfo *pResult;
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
	
void CSysMdbStatInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbStatInfoFilter::UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbStatInfo,pTransaction,updateIndex);
}

CSysMdbStatInfo *CSysMdbStatInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbStatInfo *pResult;
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
	
void CSysMdbStatInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbStatInfoLinkIterator::UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbStatInfo,pTransaction,updateIndex);
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMdbTradeFrontOrderRttStatSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMdbTradeFrontOrderRttStatSingleIterator::UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMdbTradeFrontOrderRttStat,pTransaction,updateIndex);
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMdbTradeFrontOrderRttStat *pResult;
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
	
void CSysMdbTradeFrontOrderRttStatFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMdbTradeFrontOrderRttStatFilter::UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMdbTradeFrontOrderRttStat,pTransaction,updateIndex);
}

CSysMdbTradeFrontOrderRttStat *CSysMdbTradeFrontOrderRttStatLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMdbTradeFrontOrderRttStat *pResult;
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
	
void CSysMdbTradeFrontOrderRttStatLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMdbTradeFrontOrderRttStatLinkIterator::UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMdbTradeFrontOrderRttStat,pTransaction,updateIndex);
}

CSysInstrumentStatus *CSysInstrumentStatusSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysInstrumentStatusSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysInstrumentStatusSingleIterator::UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysInstrumentStatus,pTransaction,updateIndex);
}

CSysInstrumentStatus *CSysInstrumentStatusFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysInstrumentStatus *pResult;
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
	
void CSysInstrumentStatusFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysInstrumentStatusFilter::UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysInstrumentStatus,pTransaction,updateIndex);
}

CSysInstrumentStatus *CSysInstrumentStatusLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysInstrumentStatus *pResult;
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
	
void CSysInstrumentStatusLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysInstrumentStatusLinkIterator::UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysInstrumentStatus,pTransaction,updateIndex);
}

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysCurrTradingSegmentAttrSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysCurrTradingSegmentAttrSingleIterator::UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysCurrTradingSegmentAttr,pTransaction,updateIndex);
}

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysCurrTradingSegmentAttr *pResult;
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
	
void CSysCurrTradingSegmentAttrFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysCurrTradingSegmentAttrFilter::UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysCurrTradingSegmentAttr,pTransaction,updateIndex);
}

CSysCurrTradingSegmentAttr *CSysCurrTradingSegmentAttrLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysCurrTradingSegmentAttr *pResult;
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
	
void CSysCurrTradingSegmentAttrLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysCurrTradingSegmentAttrLinkIterator::UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysCurrTradingSegmentAttr,pTransaction,updateIndex);
}

CSysMemberLinkCost *CSysMemberLinkCostSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysMemberLinkCostSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysMemberLinkCostSingleIterator::UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysMemberLinkCost,pTransaction,updateIndex);
}

CSysMemberLinkCost *CSysMemberLinkCostFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysMemberLinkCost *pResult;
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
	
void CSysMemberLinkCostFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysMemberLinkCostFilter::UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysMemberLinkCost,pTransaction,updateIndex);
}

CSysMemberLinkCost *CSysMemberLinkCostLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysMemberLinkCost *pResult;
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
	
void CSysMemberLinkCostLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysMemberLinkCostLinkIterator::UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysMemberLinkCost,pTransaction,updateIndex);
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetPartylinkMonthlyRentSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetPartylinkMonthlyRentSingleIterator::UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetPartylinkMonthlyRent,pTransaction,updateIndex);
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetPartylinkMonthlyRent *pResult;
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
	
void CSysNetPartylinkMonthlyRentFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetPartylinkMonthlyRentFilter::UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetPartylinkMonthlyRent,pTransaction,updateIndex);
}

CSysNetPartylinkMonthlyRent *CSysNetPartylinkMonthlyRentLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetPartylinkMonthlyRent *pResult;
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
	
void CSysNetPartylinkMonthlyRentLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetPartylinkMonthlyRentLinkIterator::UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetPartylinkMonthlyRent,pTransaction,updateIndex);
}

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSysNetNonPartyLinkInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSysNetNonPartyLinkInfoSingleIterator::UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSysNetNonPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSysNetNonPartyLinkInfo *pResult;
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
	
void CSysNetNonPartyLinkInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSysNetNonPartyLinkInfoFilter::UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSysNetNonPartyLinkInfo,pTransaction,updateIndex);
}

CSysNetNonPartyLinkInfo *CSysNetNonPartyLinkInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSysNetNonPartyLinkInfo *pResult;
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
	
void CSysNetNonPartyLinkInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSysNetNonPartyLinkInfoLinkIterator::UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSysNetNonPartyLinkInfo,pTransaction,updateIndex);
}

