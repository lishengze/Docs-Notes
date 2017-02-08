/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseIteratorRepository.cpp
///@brief	实现了若干个内存数据库的iterator库，以便各种查询
///@history 
///20061222	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseIteratorRepository.h"

CExchangeDataSyncStatus *CExchangeDataSyncStatusSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CExchangeDataSyncStatusSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CExchangeDataSyncStatusSingleIterator::UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pExchangeDataSyncStatus,pTransaction,updateIndex);
}

CExchangeDataSyncStatus *CExchangeDataSyncStatusFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CExchangeDataSyncStatus *pResult;
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
	
void CExchangeDataSyncStatusFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CExchangeDataSyncStatusFilter::UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pExchangeDataSyncStatus,pTransaction,updateIndex);
}

CExchangeDataSyncStatus *CExchangeDataSyncStatusLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CExchangeDataSyncStatus *pResult;
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
	
void CExchangeDataSyncStatusLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CExchangeDataSyncStatusLinkIterator::UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pExchangeDataSyncStatus,pTransaction,updateIndex);
}

CSGDataSyncStatus *CSGDataSyncStatusSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSGDataSyncStatusSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSGDataSyncStatusSingleIterator::UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSGDataSyncStatus,pTransaction,updateIndex);
}

CSGDataSyncStatus *CSGDataSyncStatusFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSGDataSyncStatus *pResult;
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
	
void CSGDataSyncStatusFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSGDataSyncStatusFilter::UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSGDataSyncStatus,pTransaction,updateIndex);
}

CSGDataSyncStatus *CSGDataSyncStatusLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSGDataSyncStatus *pResult;
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
	
void CSGDataSyncStatusLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSGDataSyncStatusLinkIterator::UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSGDataSyncStatus,pTransaction,updateIndex);
}

CCurrentTime *CCurrentTimeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrentTimeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrentTimeSingleIterator::UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrentTime,pTransaction,updateIndex);
}

CCurrentTime *CCurrentTimeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrentTime *pResult;
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
	
void CCurrentTimeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrentTimeFilter::UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrentTime,pTransaction,updateIndex);
}

CCurrentTime *CCurrentTimeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrentTime *pResult;
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
	
void CCurrentTimeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrentTimeLinkIterator::UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrentTime,pTransaction,updateIndex);
}

CDataCenterDesc *CDataCenterDescSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CDataCenterDescSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CDataCenterDescSingleIterator::UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pDataCenterDesc,pTransaction,updateIndex);
}

CDataCenterDesc *CDataCenterDescFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CDataCenterDesc *pResult;
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
	
void CDataCenterDescFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CDataCenterDescFilter::UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pDataCenterDesc,pTransaction,updateIndex);
}

CDataCenterDesc *CDataCenterDescLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CDataCenterDesc *pResult;
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
	
void CDataCenterDescLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CDataCenterDescLinkIterator::UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pDataCenterDesc,pTransaction,updateIndex);
}

CExchange *CExchangeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CExchangeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CExchangeSingleIterator::UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pExchange,pTransaction,updateIndex);
}

CExchange *CExchangeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CExchange *pResult;
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
	
void CExchangeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CExchangeFilter::UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pExchange,pTransaction,updateIndex);
}

CExchange *CExchangeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CExchange *pResult;
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
	
void CExchangeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CExchangeLinkIterator::UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pExchange,pTransaction,updateIndex);
}

CSettlementGroup *CSettlementGroupSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CSettlementGroupSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CSettlementGroupSingleIterator::UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pSettlementGroup,pTransaction,updateIndex);
}

CSettlementGroup *CSettlementGroupFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CSettlementGroup *pResult;
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
	
void CSettlementGroupFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CSettlementGroupFilter::UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pSettlementGroup,pTransaction,updateIndex);
}

CSettlementGroup *CSettlementGroupLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CSettlementGroup *pResult;
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
	
void CSettlementGroupLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CSettlementGroupLinkIterator::UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pSettlementGroup,pTransaction,updateIndex);
}

CMarket *CMarketSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMarketSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMarketSingleIterator::UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMarket,pTransaction,updateIndex);
}

CMarket *CMarketFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMarket *pResult;
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
	
void CMarketFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMarketFilter::UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMarket,pTransaction,updateIndex);
}

CMarket *CMarketLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMarket *pResult;
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
	
void CMarketLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMarketLinkIterator::UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMarket,pTransaction,updateIndex);
}

CMarketProduct *CMarketProductSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMarketProductSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMarketProductSingleIterator::UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMarketProduct,pTransaction,updateIndex);
}

CMarketProduct *CMarketProductFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMarketProduct *pResult;
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
	
void CMarketProductFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMarketProductFilter::UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMarketProduct,pTransaction,updateIndex);
}

CMarketProduct *CMarketProductLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMarketProduct *pResult;
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
	
void CMarketProductLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMarketProductLinkIterator::UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMarketProduct,pTransaction,updateIndex);
}

CMarketProductGroup *CMarketProductGroupSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMarketProductGroupSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMarketProductGroupSingleIterator::UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMarketProductGroup,pTransaction,updateIndex);
}

CMarketProductGroup *CMarketProductGroupFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMarketProductGroup *pResult;
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
	
void CMarketProductGroupFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMarketProductGroupFilter::UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMarketProductGroup,pTransaction,updateIndex);
}

CMarketProductGroup *CMarketProductGroupLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMarketProductGroup *pResult;
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
	
void CMarketProductGroupLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMarketProductGroupLinkIterator::UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMarketProductGroup,pTransaction,updateIndex);
}

CMdPubStatus *CMdPubStatusSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMdPubStatusSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMdPubStatusSingleIterator::UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMdPubStatus,pTransaction,updateIndex);
}

CMdPubStatus *CMdPubStatusFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMdPubStatus *pResult;
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
	
void CMdPubStatusFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMdPubStatusFilter::UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMdPubStatus,pTransaction,updateIndex);
}

CMdPubStatus *CMdPubStatusLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMdPubStatus *pResult;
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
	
void CMdPubStatusLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMdPubStatusLinkIterator::UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMdPubStatus,pTransaction,updateIndex);
}

CMarketDataTopic *CMarketDataTopicSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMarketDataTopicSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMarketDataTopicSingleIterator::UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMarketDataTopic,pTransaction,updateIndex);
}

CMarketDataTopic *CMarketDataTopicFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMarketDataTopic *pResult;
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
	
void CMarketDataTopicFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMarketDataTopicFilter::UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMarketDataTopic,pTransaction,updateIndex);
}

CMarketDataTopic *CMarketDataTopicLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMarketDataTopic *pResult;
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
	
void CMarketDataTopicLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMarketDataTopicLinkIterator::UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMarketDataTopic,pTransaction,updateIndex);
}

CPartTopicSubscribe *CPartTopicSubscribeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartTopicSubscribeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartTopicSubscribeSingleIterator::UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartTopicSubscribe,pTransaction,updateIndex);
}

CPartTopicSubscribe *CPartTopicSubscribeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartTopicSubscribe *pResult;
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
	
void CPartTopicSubscribeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartTopicSubscribeFilter::UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartTopicSubscribe,pTransaction,updateIndex);
}

CPartTopicSubscribe *CPartTopicSubscribeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartTopicSubscribe *pResult;
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
	
void CPartTopicSubscribeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartTopicSubscribeLinkIterator::UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartTopicSubscribe,pTransaction,updateIndex);
}

CParticipant *CParticipantSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CParticipantSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CParticipantSingleIterator::UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pParticipant,pTransaction,updateIndex);
}

CParticipant *CParticipantFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CParticipant *pResult;
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
	
void CParticipantFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CParticipantFilter::UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pParticipant,pTransaction,updateIndex);
}

CParticipant *CParticipantLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CParticipant *pResult;
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
	
void CParticipantLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CParticipantLinkIterator::UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pParticipant,pTransaction,updateIndex);
}

CClearingTradingPart *CClearingTradingPartOfParticipantIterator::next(void)
{
	CParticipant *pParticipant;
	while ((pParticipant=m_baseIterator->next())!=NULL)
	{
		m_current=pParticipant->getClearingTradingPart();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CClearingTradingPartOfParticipantIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CClearingTradingPartOfParticipantIterator::UpdateCurrent(CWriteableClearingTradingPart *pClearingTradingPart,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pClearingTradingPart,pTransaction,updateIndex);
}

CUser *CUserSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CUserSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CUserSingleIterator::UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pUser,pTransaction,updateIndex);
}

CUser *CUserFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CUser *pResult;
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
	
void CUserFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CUserFilter::UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pUser,pTransaction,updateIndex);
}

CUser *CUserLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CUser *pResult;
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
	
void CUserLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CUserLinkIterator::UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pUser,pTransaction,updateIndex);
}

CClient *CClientSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CClientSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CClientSingleIterator::UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pClient,pTransaction,updateIndex);
}

CClient *CClientFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CClient *pResult;
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
	
void CClientFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CClientFilter::UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pClient,pTransaction,updateIndex);
}

CClient *CClientLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CClient *pResult;
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
	
void CClientLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CClientLinkIterator::UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pClient,pTransaction,updateIndex);
}

CUserIP *CUserIPSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CUserIPSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CUserIPSingleIterator::UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pUserIP,pTransaction,updateIndex);
}

CUserIP *CUserIPFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CUserIP *pResult;
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
	
void CUserIPFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CUserIPFilter::UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pUserIP,pTransaction,updateIndex);
}

CUserIP *CUserIPLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CUserIP *pResult;
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
	
void CUserIPLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CUserIPLinkIterator::UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pUserIP,pTransaction,updateIndex);
}

CPartClient *CPartClientSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartClientSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartClientSingleIterator::UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartClient,pTransaction,updateIndex);
}

CPartClient *CPartClientFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartClient *pResult;
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
	
void CPartClientFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartClientFilter::UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartClient,pTransaction,updateIndex);
}

CPartClient *CPartClientLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartClient *pResult;
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
	
void CPartClientLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartClientLinkIterator::UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartClient,pTransaction,updateIndex);
}

CParticipant *CParticipantOfPartClientIterator::next(void)
{
	CPartClient *pPartClient;
	while ((pPartClient=m_baseIterator->next())!=NULL)
	{
		m_current=pPartClient->getParticipant();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CParticipantOfPartClientIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CParticipantOfPartClientIterator::UpdateCurrent(CWriteableParticipant *pParticipant,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pParticipant,pTransaction,updateIndex);
}

CClient *CClientOfPartClientIterator::next(void)
{
	CPartClient *pPartClient;
	while ((pPartClient=m_baseIterator->next())!=NULL)
	{
		m_current=pPartClient->getClient();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CClientOfPartClientIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CClientOfPartClientIterator::UpdateCurrent(CWriteableClient *pClient,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pClient,pTransaction,updateIndex);
}

CClearingTradingPart *CClearingTradingPartSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CClearingTradingPartSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CClearingTradingPartSingleIterator::UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pClearingTradingPart,pTransaction,updateIndex);
}

CClearingTradingPart *CClearingTradingPartFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CClearingTradingPart *pResult;
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
	
void CClearingTradingPartFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CClearingTradingPartFilter::UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pClearingTradingPart,pTransaction,updateIndex);
}

CClearingTradingPart *CClearingTradingPartLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CClearingTradingPart *pResult;
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
	
void CClearingTradingPartLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CClearingTradingPartLinkIterator::UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pClearingTradingPart,pTransaction,updateIndex);
}

CAliasDefine *CAliasDefineSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CAliasDefineSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CAliasDefineSingleIterator::UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pAliasDefine,pTransaction,updateIndex);
}

CAliasDefine *CAliasDefineFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CAliasDefine *pResult;
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
	
void CAliasDefineFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CAliasDefineFilter::UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pAliasDefine,pTransaction,updateIndex);
}

CAliasDefine *CAliasDefineLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CAliasDefine *pResult;
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
	
void CAliasDefineLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CAliasDefineLinkIterator::UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pAliasDefine,pTransaction,updateIndex);
}

CUserFunctionRight *CUserFunctionRightSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CUserFunctionRightSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CUserFunctionRightSingleIterator::UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pUserFunctionRight,pTransaction,updateIndex);
}

CUserFunctionRight *CUserFunctionRightFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CUserFunctionRight *pResult;
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
	
void CUserFunctionRightFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CUserFunctionRightFilter::UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pUserFunctionRight,pTransaction,updateIndex);
}

CUserFunctionRight *CUserFunctionRightLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CUserFunctionRight *pResult;
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
	
void CUserFunctionRightLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CUserFunctionRightLinkIterator::UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pUserFunctionRight,pTransaction,updateIndex);
}

CAccount *CAccountSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CAccountSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CAccountSingleIterator::UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pAccount,pTransaction,updateIndex);
}

CAccount *CAccountFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CAccount *pResult;
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
	
void CAccountFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CAccountFilter::UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pAccount,pTransaction,updateIndex);
}

CAccount *CAccountLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CAccount *pResult;
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
	
void CAccountLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CAccountLinkIterator::UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pAccount,pTransaction,updateIndex);
}

CTradingAccount *CTradingAccountOfAccountIterator::next(void)
{
	CAccount *pAccount;
	while ((pAccount=m_baseIterator->next())!=NULL)
	{
		m_current=pAccount->getTradingAccount();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CTradingAccountOfAccountIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CTradingAccountOfAccountIterator::UpdateCurrent(CWriteableTradingAccount *pTradingAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pTradingAccount,pTransaction,updateIndex);
}

CUserCommFlux *CUserCommFluxSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CUserCommFluxSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CUserCommFluxSingleIterator::UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pUserCommFlux,pTransaction,updateIndex);
}

CUserCommFlux *CUserCommFluxFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CUserCommFlux *pResult;
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
	
void CUserCommFluxFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CUserCommFluxFilter::UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pUserCommFlux,pTransaction,updateIndex);
}

CUserCommFlux *CUserCommFluxLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CUserCommFlux *pResult;
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
	
void CUserCommFluxLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CUserCommFluxLinkIterator::UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pUserCommFlux,pTransaction,updateIndex);
}

CMarketDataLog *CMarketDataLogSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMarketDataLogSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMarketDataLogSingleIterator::UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMarketDataLog,pTransaction,updateIndex);
}

CMarketDataLog *CMarketDataLogFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMarketDataLog *pResult;
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
	
void CMarketDataLogFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMarketDataLogFilter::UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMarketDataLog,pTransaction,updateIndex);
}

CMarketDataLog *CMarketDataLogLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMarketDataLog *pResult;
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
	
void CMarketDataLogLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMarketDataLogLinkIterator::UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMarketDataLog,pTransaction,updateIndex);
}

CUserSession *CUserSessionSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CUserSessionSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CUserSessionSingleIterator::UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pUserSession,pTransaction,updateIndex);
}

CUserSession *CUserSessionFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CUserSession *pResult;
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
	
void CUserSessionFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CUserSessionFilter::UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pUserSession,pTransaction,updateIndex);
}

CUserSession *CUserSessionLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CUserSession *pResult;
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
	
void CUserSessionLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CUserSessionLinkIterator::UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pUserSession,pTransaction,updateIndex);
}

CUser *CUserOfUserSessionIterator::next(void)
{
	CUserSession *pUserSession;
	while ((pUserSession=m_baseIterator->next())!=NULL)
	{
		m_current=pUserSession->getUser();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CUserOfUserSessionIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CUserOfUserSessionIterator::UpdateCurrent(CWriteableUser *pUser,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pUser,pTransaction,updateIndex);
}

CMDSession *CMDSessionSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMDSessionSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMDSessionSingleIterator::UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMDSession,pTransaction,updateIndex);
}

CMDSession *CMDSessionFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMDSession *pResult;
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
	
void CMDSessionFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMDSessionFilter::UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMDSession,pTransaction,updateIndex);
}

CMDSession *CMDSessionLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMDSession *pResult;
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
	
void CMDSessionLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMDSessionLinkIterator::UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMDSession,pTransaction,updateIndex);
}

CLoginInfo *CLoginInfoSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CLoginInfoSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CLoginInfoSingleIterator::UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pLoginInfo,pTransaction,updateIndex);
}

CLoginInfo *CLoginInfoFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CLoginInfo *pResult;
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
	
void CLoginInfoFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CLoginInfoFilter::UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pLoginInfo,pTransaction,updateIndex);
}

CLoginInfo *CLoginInfoLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CLoginInfo *pResult;
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
	
void CLoginInfoLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CLoginInfoLinkIterator::UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pLoginInfo,pTransaction,updateIndex);
}

CDepthMarketDataDetail *CDepthMarketDataDetailSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CDepthMarketDataDetailSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CDepthMarketDataDetailSingleIterator::UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pDepthMarketDataDetail,pTransaction,updateIndex);
}

CDepthMarketDataDetail *CDepthMarketDataDetailFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CDepthMarketDataDetail *pResult;
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
	
void CDepthMarketDataDetailFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CDepthMarketDataDetailFilter::UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pDepthMarketDataDetail,pTransaction,updateIndex);
}

CDepthMarketDataDetail *CDepthMarketDataDetailLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CDepthMarketDataDetail *pResult;
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
	
void CDepthMarketDataDetailLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CDepthMarketDataDetailLinkIterator::UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pDepthMarketDataDetail,pTransaction,updateIndex);
}

CInstrumentStatusDetail *CInstrumentStatusDetailSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CInstrumentStatusDetailSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CInstrumentStatusDetailSingleIterator::UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pInstrumentStatusDetail,pTransaction,updateIndex);
}

CInstrumentStatusDetail *CInstrumentStatusDetailFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CInstrumentStatusDetail *pResult;
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
	
void CInstrumentStatusDetailFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CInstrumentStatusDetailFilter::UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pInstrumentStatusDetail,pTransaction,updateIndex);
}

CInstrumentStatusDetail *CInstrumentStatusDetailLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CInstrumentStatusDetail *pResult;
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
	
void CInstrumentStatusDetailLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CInstrumentStatusDetailLinkIterator::UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pInstrumentStatusDetail,pTransaction,updateIndex);
}

CFrontStatus *CFrontStatusSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CFrontStatusSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CFrontStatusSingleIterator::UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pFrontStatus,pTransaction,updateIndex);
}

CFrontStatus *CFrontStatusFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CFrontStatus *pResult;
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
	
void CFrontStatusFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CFrontStatusFilter::UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pFrontStatus,pTransaction,updateIndex);
}

CFrontStatus *CFrontStatusLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CFrontStatus *pResult;
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
	
void CFrontStatusLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CFrontStatusLinkIterator::UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pFrontStatus,pTransaction,updateIndex);
}

CMaxLocalID *CMaxLocalIDSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMaxLocalIDSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMaxLocalIDSingleIterator::UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMaxLocalID,pTransaction,updateIndex);
}

CMaxLocalID *CMaxLocalIDFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMaxLocalID *pResult;
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
	
void CMaxLocalIDFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMaxLocalIDFilter::UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMaxLocalID,pTransaction,updateIndex);
}

CMaxLocalID *CMaxLocalIDLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMaxLocalID *pResult;
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
	
void CMaxLocalIDLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMaxLocalIDLinkIterator::UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMaxLocalID,pTransaction,updateIndex);
}

CBulletin *CBulletinSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CBulletinSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CBulletinSingleIterator::UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pBulletin,pTransaction,updateIndex);
}

CBulletin *CBulletinFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CBulletin *pResult;
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
	
void CBulletinFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CBulletinFilter::UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pBulletin,pTransaction,updateIndex);
}

CBulletin *CBulletinLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CBulletin *pResult;
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
	
void CBulletinLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CBulletinLinkIterator::UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pBulletin,pTransaction,updateIndex);
}

CMarketDataModify *CMarketDataModifySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMarketDataModifySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMarketDataModifySingleIterator::UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMarketDataModify,pTransaction,updateIndex);
}

CMarketDataModify *CMarketDataModifyFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMarketDataModify *pResult;
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
	
void CMarketDataModifyFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMarketDataModifyFilter::UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMarketDataModify,pTransaction,updateIndex);
}

CMarketDataModify *CMarketDataModifyLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMarketDataModify *pResult;
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
	
void CMarketDataModifyLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMarketDataModifyLinkIterator::UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMarketDataModify,pTransaction,updateIndex);
}

CDepthMarketData *CDepthMarketDataOfMarketDataModifyIterator::next(void)
{
	CMarketDataModify *pMarketDataModify;
	while ((pMarketDataModify=m_baseIterator->next())!=NULL)
	{
		m_current=pMarketDataModify->getDepthMarketData();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CDepthMarketDataOfMarketDataModifyIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CDepthMarketDataOfMarketDataModifyIterator::UpdateCurrent(CWriteableDepthMarketData *pDepthMarketData,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pDepthMarketData,pTransaction,updateIndex);
}

CDepthMarketData *CDepthMarketDataSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CDepthMarketDataSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CDepthMarketDataSingleIterator::UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pDepthMarketData,pTransaction,updateIndex);
}

CDepthMarketData *CDepthMarketDataFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CDepthMarketData *pResult;
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
	
void CDepthMarketDataFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CDepthMarketDataFilter::UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pDepthMarketData,pTransaction,updateIndex);
}

CDepthMarketData *CDepthMarketDataLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CDepthMarketData *pResult;
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
	
void CDepthMarketDataLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CDepthMarketDataLinkIterator::UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pDepthMarketData,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfDepthMarketDataIterator::next(void)
{
	CDepthMarketData *pDepthMarketData;
	while ((pDepthMarketData=m_baseIterator->next())!=NULL)
	{
		m_current=pDepthMarketData->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfDepthMarketDataIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfDepthMarketDataIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CTopicMarketData *CTopicMarketDataSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CTopicMarketDataSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CTopicMarketDataSingleIterator::UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pTopicMarketData,pTransaction,updateIndex);
}

CTopicMarketData *CTopicMarketDataFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CTopicMarketData *pResult;
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
	
void CTopicMarketDataFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CTopicMarketDataFilter::UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pTopicMarketData,pTransaction,updateIndex);
}

CTopicMarketData *CTopicMarketDataLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CTopicMarketData *pResult;
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
	
void CTopicMarketDataLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CTopicMarketDataLinkIterator::UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pTopicMarketData,pTransaction,updateIndex);
}

CTopicMarketDataVersion *CTopicMarketDataVersionSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CTopicMarketDataVersionSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CTopicMarketDataVersionSingleIterator::UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pTopicMarketDataVersion,pTransaction,updateIndex);
}

CTopicMarketDataVersion *CTopicMarketDataVersionFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CTopicMarketDataVersion *pResult;
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
	
void CTopicMarketDataVersionFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CTopicMarketDataVersionFilter::UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pTopicMarketDataVersion,pTransaction,updateIndex);
}

CTopicMarketDataVersion *CTopicMarketDataVersionLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CTopicMarketDataVersion *pResult;
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
	
void CTopicMarketDataVersionLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CTopicMarketDataVersionLinkIterator::UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pTopicMarketDataVersion,pTransaction,updateIndex);
}

CInformation *CInformationSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CInformationSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CInformationSingleIterator::UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pInformation,pTransaction,updateIndex);
}

CInformation *CInformationFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CInformation *pResult;
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
	
void CInformationFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CInformationFilter::UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pInformation,pTransaction,updateIndex);
}

CInformation *CInformationLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CInformation *pResult;
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
	
void CInformationLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CInformationLinkIterator::UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pInformation,pTransaction,updateIndex);
}

COrderCount *COrderCountSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void COrderCountSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void COrderCountSingleIterator::UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pOrderCount,pTransaction,updateIndex);
}

COrderCount *COrderCountFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		COrderCount *pResult;
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
	
void COrderCountFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void COrderCountFilter::UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pOrderCount,pTransaction,updateIndex);
}

COrderCount *COrderCountLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			COrderCount *pResult;
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
	
void COrderCountLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void COrderCountLinkIterator::UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pOrderCount,pTransaction,updateIndex);
}

CInstrument *CInstrumentSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CInstrumentSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CInstrumentSingleIterator::UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pInstrument,pTransaction,updateIndex);
}

CInstrument *CInstrumentFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CInstrument *pResult;
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
	
void CInstrumentFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CInstrumentFilter::UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pInstrument,pTransaction,updateIndex);
}

CInstrument *CInstrumentLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CInstrument *pResult;
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
	
void CInstrumentLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CInstrumentLinkIterator::UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pInstrument,pTransaction,updateIndex);
}

CInstrument *CBaseInstrumentOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getBaseInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CBaseInstrumentOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CBaseInstrumentOfInstrumentIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CCurrInstrumentProperty *CInstrumentPropertyOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getInstrumentProperty();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentPropertyOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentPropertyOfInstrumentIterator::UpdateCurrent(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pCurrInstrumentProperty,pTransaction,updateIndex);
}

CInstrumentStatus *CInstrumentStatusOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getInstrumentStatus();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentStatusOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentStatusOfInstrumentIterator::UpdateCurrent(CWriteableInstrumentStatus *pInstrumentStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrumentStatus,pTransaction,updateIndex);
}

CMarketData *CMarketDataOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getMarketData();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CMarketDataOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CMarketDataOfInstrumentIterator::UpdateCurrent(CWriteableMarketData *pMarketData,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pMarketData,pTransaction,updateIndex);
}

CCurrHedgeRule *CCurrHedgeRuleOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getCurrHedgeRule();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CCurrHedgeRuleOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CCurrHedgeRuleOfInstrumentIterator::UpdateCurrent(CWriteableCurrHedgeRule *pCurrHedgeRule,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pCurrHedgeRule,pTransaction,updateIndex);
}

CCurrFuse *CCurrFuseOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getCurrFuse();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CCurrFuseOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CCurrFuseOfInstrumentIterator::UpdateCurrent(CWriteableCurrFuse *pCurrFuse,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pCurrFuse,pTransaction,updateIndex);
}

CFusePhase *CFusePhaseOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getFusePhase();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CFusePhaseOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CFusePhaseOfInstrumentIterator::UpdateCurrent(CWriteableFusePhase *pFusePhase,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pFusePhase,pTransaction,updateIndex);
}

CBasePriceLimit *CBasePriceLimitOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getBasePriceLimit();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CBasePriceLimitOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CBasePriceLimitOfInstrumentIterator::UpdateCurrent(CWriteableBasePriceLimit *pBasePriceLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pBasePriceLimit,pTransaction,updateIndex);
}

CUniPressure *CUniPressureOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getUniPressure();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CUniPressureOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CUniPressureOfInstrumentIterator::UpdateCurrent(CWriteableUniPressure *pUniPressure,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pUniPressure,pTransaction,updateIndex);
}

CSGDataSyncStatus *CSGDataSyncStatusOfInstrumentIterator::next(void)
{
	CInstrument *pInstrument;
	while ((pInstrument=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrument->getSGDataSyncStatus();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CSGDataSyncStatusOfInstrumentIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CSGDataSyncStatusOfInstrumentIterator::UpdateCurrent(CWriteableSGDataSyncStatus *pSGDataSyncStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pSGDataSyncStatus,pTransaction,updateIndex);
}

CCombinationLeg *CCombinationLegSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCombinationLegSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCombinationLegSingleIterator::UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCombinationLeg,pTransaction,updateIndex);
}

CCombinationLeg *CCombinationLegFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCombinationLeg *pResult;
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
	
void CCombinationLegFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCombinationLegFilter::UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCombinationLeg,pTransaction,updateIndex);
}

CCombinationLeg *CCombinationLegLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCombinationLeg *pResult;
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
	
void CCombinationLegLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCombinationLegLinkIterator::UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCombinationLeg,pTransaction,updateIndex);
}

CInstrument *CCombinationInstrumentOfCombinationLegIterator::next(void)
{
	CCombinationLeg *pCombinationLeg;
	while ((pCombinationLeg=m_baseIterator->next())!=NULL)
	{
		m_current=pCombinationLeg->getCombinationInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CCombinationInstrumentOfCombinationLegIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CCombinationInstrumentOfCombinationLegIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CInstrument *CLegInstrumentOfCombinationLegIterator::next(void)
{
	CCombinationLeg *pCombinationLeg;
	while ((pCombinationLeg=m_baseIterator->next())!=NULL)
	{
		m_current=pCombinationLeg->getLegInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CLegInstrumentOfCombinationLegIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CLegInstrumentOfCombinationLegIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CPartRoleAccount *CPartRoleAccountSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartRoleAccountSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartRoleAccountSingleIterator::UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartRoleAccount,pTransaction,updateIndex);
}

CPartRoleAccount *CPartRoleAccountFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartRoleAccount *pResult;
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
	
void CPartRoleAccountFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartRoleAccountFilter::UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartRoleAccount,pTransaction,updateIndex);
}

CPartRoleAccount *CPartRoleAccountLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartRoleAccount *pResult;
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
	
void CPartRoleAccountLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartRoleAccountLinkIterator::UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartRoleAccount,pTransaction,updateIndex);
}

CTradingAccount *CTradingAccountOfPartRoleAccountIterator::next(void)
{
	CPartRoleAccount *pPartRoleAccount;
	while ((pPartRoleAccount=m_baseIterator->next())!=NULL)
	{
		m_current=pPartRoleAccount->getTradingAccount();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CTradingAccountOfPartRoleAccountIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CTradingAccountOfPartRoleAccountIterator::UpdateCurrent(CWriteableTradingAccount *pTradingAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pTradingAccount,pTransaction,updateIndex);
}

CPartProductRole *CPartProductRoleSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartProductRoleSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartProductRoleSingleIterator::UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartProductRole,pTransaction,updateIndex);
}

CPartProductRole *CPartProductRoleFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartProductRole *pResult;
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
	
void CPartProductRoleFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartProductRoleFilter::UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartProductRole,pTransaction,updateIndex);
}

CPartProductRole *CPartProductRoleLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartProductRole *pResult;
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
	
void CPartProductRoleLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartProductRoleLinkIterator::UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartProductRole,pTransaction,updateIndex);
}

CPartProductRight *CPartProductRightSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartProductRightSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartProductRightSingleIterator::UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartProductRight,pTransaction,updateIndex);
}

CPartProductRight *CPartProductRightFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartProductRight *pResult;
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
	
void CPartProductRightFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartProductRightFilter::UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartProductRight,pTransaction,updateIndex);
}

CPartProductRight *CPartProductRightLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartProductRight *pResult;
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
	
void CPartProductRightLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartProductRightLinkIterator::UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartProductRight,pTransaction,updateIndex);
}

CPartInstrumentRight *CPartInstrumentRightSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartInstrumentRightSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartInstrumentRightSingleIterator::UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartInstrumentRight,pTransaction,updateIndex);
}

CPartInstrumentRight *CPartInstrumentRightFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartInstrumentRight *pResult;
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
	
void CPartInstrumentRightFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartInstrumentRightFilter::UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartInstrumentRight,pTransaction,updateIndex);
}

CPartInstrumentRight *CPartInstrumentRightLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartInstrumentRight *pResult;
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
	
void CPartInstrumentRightLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartInstrumentRightLinkIterator::UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartInstrumentRight,pTransaction,updateIndex);
}

CClientProductRight *CClientProductRightSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CClientProductRightSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CClientProductRightSingleIterator::UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pClientProductRight,pTransaction,updateIndex);
}

CClientProductRight *CClientProductRightFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CClientProductRight *pResult;
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
	
void CClientProductRightFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CClientProductRightFilter::UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pClientProductRight,pTransaction,updateIndex);
}

CClientProductRight *CClientProductRightLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CClientProductRight *pResult;
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
	
void CClientProductRightLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CClientProductRightLinkIterator::UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pClientProductRight,pTransaction,updateIndex);
}

CClientInstrumentRight *CClientInstrumentRightSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CClientInstrumentRightSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CClientInstrumentRightSingleIterator::UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pClientInstrumentRight,pTransaction,updateIndex);
}

CClientInstrumentRight *CClientInstrumentRightFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CClientInstrumentRight *pResult;
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
	
void CClientInstrumentRightFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CClientInstrumentRightFilter::UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pClientInstrumentRight,pTransaction,updateIndex);
}

CClientInstrumentRight *CClientInstrumentRightLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CClientInstrumentRight *pResult;
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
	
void CClientInstrumentRightLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CClientInstrumentRightLinkIterator::UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pClientInstrumentRight,pTransaction,updateIndex);
}

CPartClientProductRight *CPartClientProductRightSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartClientProductRightSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartClientProductRightSingleIterator::UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartClientProductRight,pTransaction,updateIndex);
}

CPartClientProductRight *CPartClientProductRightFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartClientProductRight *pResult;
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
	
void CPartClientProductRightFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartClientProductRightFilter::UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartClientProductRight,pTransaction,updateIndex);
}

CPartClientProductRight *CPartClientProductRightLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartClientProductRight *pResult;
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
	
void CPartClientProductRightLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartClientProductRightLinkIterator::UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartClientProductRight,pTransaction,updateIndex);
}

CPartClientInstrumentRight *CPartClientInstrumentRightSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartClientInstrumentRightSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartClientInstrumentRightSingleIterator::UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartClientInstrumentRight,pTransaction,updateIndex);
}

CPartClientInstrumentRight *CPartClientInstrumentRightFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartClientInstrumentRight *pResult;
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
	
void CPartClientInstrumentRightFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartClientInstrumentRightFilter::UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartClientInstrumentRight,pTransaction,updateIndex);
}

CPartClientInstrumentRight *CPartClientInstrumentRightLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartClientInstrumentRight *pResult;
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
	
void CPartClientInstrumentRightLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartClientInstrumentRightLinkIterator::UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartClientInstrumentRight,pTransaction,updateIndex);
}

CCurrProductProperty *CCurrProductPropertySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrProductPropertySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrProductPropertySingleIterator::UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrProductProperty,pTransaction,updateIndex);
}

CCurrProductProperty *CCurrProductPropertyFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrProductProperty *pResult;
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
	
void CCurrProductPropertyFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrProductPropertyFilter::UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrProductProperty,pTransaction,updateIndex);
}

CCurrProductProperty *CCurrProductPropertyLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrProductProperty *pResult;
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
	
void CCurrProductPropertyLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrProductPropertyLinkIterator::UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrProductProperty,pTransaction,updateIndex);
}

CCurrInstrumentProperty *CCurrInstrumentPropertySingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrInstrumentPropertySingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrInstrumentPropertySingleIterator::UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrInstrumentProperty,pTransaction,updateIndex);
}

CCurrInstrumentProperty *CCurrInstrumentPropertyFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrInstrumentProperty *pResult;
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
	
void CCurrInstrumentPropertyFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrInstrumentPropertyFilter::UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrInstrumentProperty,pTransaction,updateIndex);
}

CCurrInstrumentProperty *CCurrInstrumentPropertyLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrInstrumentProperty *pResult;
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
	
void CCurrInstrumentPropertyLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrInstrumentPropertyLinkIterator::UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrInstrumentProperty,pTransaction,updateIndex);
}

CCurrPriceBanding *CCurrPriceBandingSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrPriceBandingSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrPriceBandingSingleIterator::UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrPriceBanding,pTransaction,updateIndex);
}

CCurrPriceBanding *CCurrPriceBandingFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrPriceBanding *pResult;
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
	
void CCurrPriceBandingFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrPriceBandingFilter::UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrPriceBanding,pTransaction,updateIndex);
}

CCurrPriceBanding *CCurrPriceBandingLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrPriceBanding *pResult;
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
	
void CCurrPriceBandingLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrPriceBandingLinkIterator::UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrPriceBanding,pTransaction,updateIndex);
}

CCurrMarginRate *CCurrMarginRateSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrMarginRateSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrMarginRateSingleIterator::UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrMarginRate,pTransaction,updateIndex);
}

CCurrMarginRate *CCurrMarginRateFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrMarginRate *pResult;
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
	
void CCurrMarginRateFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrMarginRateFilter::UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrMarginRate,pTransaction,updateIndex);
}

CCurrMarginRate *CCurrMarginRateLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrMarginRate *pResult;
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
	
void CCurrMarginRateLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrMarginRateLinkIterator::UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrMarginRate,pTransaction,updateIndex);
}

CCurrMarginRateDetail *CCurrMarginRateDetailSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrMarginRateDetailSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrMarginRateDetailSingleIterator::UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrMarginRateDetail,pTransaction,updateIndex);
}

CCurrMarginRateDetail *CCurrMarginRateDetailFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrMarginRateDetail *pResult;
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
	
void CCurrMarginRateDetailFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrMarginRateDetailFilter::UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrMarginRateDetail,pTransaction,updateIndex);
}

CCurrMarginRateDetail *CCurrMarginRateDetailLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrMarginRateDetail *pResult;
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
	
void CCurrMarginRateDetailLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrMarginRateDetailLinkIterator::UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrMarginRateDetail,pTransaction,updateIndex);
}

CCurrPartPosiLimit *CCurrPartPosiLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrPartPosiLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrPartPosiLimitSingleIterator::UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrPartPosiLimit,pTransaction,updateIndex);
}

CCurrPartPosiLimit *CCurrPartPosiLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrPartPosiLimit *pResult;
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
	
void CCurrPartPosiLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrPartPosiLimitFilter::UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrPartPosiLimit,pTransaction,updateIndex);
}

CCurrPartPosiLimit *CCurrPartPosiLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrPartPosiLimit *pResult;
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
	
void CCurrPartPosiLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrPartPosiLimitLinkIterator::UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrPartPosiLimit,pTransaction,updateIndex);
}

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrPartPosiLimitDetailSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrPartPosiLimitDetailSingleIterator::UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrPartPosiLimitDetail,pTransaction,updateIndex);
}

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrPartPosiLimitDetail *pResult;
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
	
void CCurrPartPosiLimitDetailFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrPartPosiLimitDetailFilter::UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrPartPosiLimitDetail,pTransaction,updateIndex);
}

CCurrPartPosiLimitDetail *CCurrPartPosiLimitDetailLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrPartPosiLimitDetail *pResult;
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
	
void CCurrPartPosiLimitDetailLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrPartPosiLimitDetailLinkIterator::UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrPartPosiLimitDetail,pTransaction,updateIndex);
}

CCurrClientPosiLimit *CCurrClientPosiLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrClientPosiLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrClientPosiLimitSingleIterator::UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrClientPosiLimit,pTransaction,updateIndex);
}

CCurrClientPosiLimit *CCurrClientPosiLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrClientPosiLimit *pResult;
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
	
void CCurrClientPosiLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrClientPosiLimitFilter::UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrClientPosiLimit,pTransaction,updateIndex);
}

CCurrClientPosiLimit *CCurrClientPosiLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrClientPosiLimit *pResult;
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
	
void CCurrClientPosiLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrClientPosiLimitLinkIterator::UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrClientPosiLimit,pTransaction,updateIndex);
}

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrClientPosiLimitDetailSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrClientPosiLimitDetailSingleIterator::UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrClientPosiLimitDetail,pTransaction,updateIndex);
}

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrClientPosiLimitDetail *pResult;
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
	
void CCurrClientPosiLimitDetailFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrClientPosiLimitDetailFilter::UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrClientPosiLimitDetail,pTransaction,updateIndex);
}

CCurrClientPosiLimitDetail *CCurrClientPosiLimitDetailLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrClientPosiLimitDetail *pResult;
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
	
void CCurrClientPosiLimitDetailLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrClientPosiLimitDetailLinkIterator::UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrClientPosiLimitDetail,pTransaction,updateIndex);
}

CCurrSpecialPosiLimit *CCurrSpecialPosiLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrSpecialPosiLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrSpecialPosiLimitSingleIterator::UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrSpecialPosiLimit,pTransaction,updateIndex);
}

CCurrSpecialPosiLimit *CCurrSpecialPosiLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrSpecialPosiLimit *pResult;
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
	
void CCurrSpecialPosiLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrSpecialPosiLimitFilter::UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrSpecialPosiLimit,pTransaction,updateIndex);
}

CCurrSpecialPosiLimit *CCurrSpecialPosiLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrSpecialPosiLimit *pResult;
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
	
void CCurrSpecialPosiLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrSpecialPosiLimitLinkIterator::UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrSpecialPosiLimit,pTransaction,updateIndex);
}

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrSpecialPosiLimitDetailSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrSpecialPosiLimitDetailSingleIterator::UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrSpecialPosiLimitDetail,pTransaction,updateIndex);
}

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrSpecialPosiLimitDetail *pResult;
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
	
void CCurrSpecialPosiLimitDetailFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrSpecialPosiLimitDetailFilter::UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrSpecialPosiLimitDetail,pTransaction,updateIndex);
}

CCurrSpecialPosiLimitDetail *CCurrSpecialPosiLimitDetailLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrSpecialPosiLimitDetail *pResult;
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
	
void CCurrSpecialPosiLimitDetailLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrSpecialPosiLimitDetailLinkIterator::UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrSpecialPosiLimitDetail,pTransaction,updateIndex);
}

CCurrHedgeRule *CCurrHedgeRuleSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrHedgeRuleSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrHedgeRuleSingleIterator::UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrHedgeRule,pTransaction,updateIndex);
}

CCurrHedgeRule *CCurrHedgeRuleFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrHedgeRule *pResult;
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
	
void CCurrHedgeRuleFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrHedgeRuleFilter::UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrHedgeRule,pTransaction,updateIndex);
}

CCurrHedgeRule *CCurrHedgeRuleLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrHedgeRule *pResult;
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
	
void CCurrHedgeRuleLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrHedgeRuleLinkIterator::UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrHedgeRule,pTransaction,updateIndex);
}

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrTradingSegmentAttrSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrTradingSegmentAttrSingleIterator::UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrTradingSegmentAttr,pTransaction,updateIndex);
}

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrTradingSegmentAttr *pResult;
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
	
void CCurrTradingSegmentAttrFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrTradingSegmentAttrFilter::UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrTradingSegmentAttr,pTransaction,updateIndex);
}

CCurrTradingSegmentAttr *CCurrTradingSegmentAttrLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrTradingSegmentAttr *pResult;
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
	
void CCurrTradingSegmentAttrLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrTradingSegmentAttrLinkIterator::UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrTradingSegmentAttr,pTransaction,updateIndex);
}

CCurrFuse *CCurrFuseSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrFuseSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrFuseSingleIterator::UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrFuse,pTransaction,updateIndex);
}

CCurrFuse *CCurrFuseFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrFuse *pResult;
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
	
void CCurrFuseFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrFuseFilter::UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrFuse,pTransaction,updateIndex);
}

CCurrFuse *CCurrFuseLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrFuse *pResult;
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
	
void CCurrFuseLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrFuseLinkIterator::UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrFuse,pTransaction,updateIndex);
}

CTradingAccount *CTradingAccountSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CTradingAccountSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CTradingAccountSingleIterator::UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pTradingAccount,pTransaction,updateIndex);
}

CTradingAccount *CTradingAccountFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CTradingAccount *pResult;
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
	
void CTradingAccountFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CTradingAccountFilter::UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pTradingAccount,pTransaction,updateIndex);
}

CTradingAccount *CTradingAccountLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CTradingAccount *pResult;
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
	
void CTradingAccountLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CTradingAccountLinkIterator::UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pTradingAccount,pTransaction,updateIndex);
}

CBaseReserveAccount *CBaseReserveAccountOfTradingAccountIterator::next(void)
{
	CTradingAccount *pTradingAccount;
	while ((pTradingAccount=m_baseIterator->next())!=NULL)
	{
		m_current=pTradingAccount->getBaseReserveAccount();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CBaseReserveAccountOfTradingAccountIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CBaseReserveAccountOfTradingAccountIterator::UpdateCurrent(CWriteableBaseReserveAccount *pBaseReserveAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pBaseReserveAccount,pTransaction,updateIndex);
}

CBaseReserveAccount *CBaseReserveAccountSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CBaseReserveAccountSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CBaseReserveAccountSingleIterator::UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pBaseReserveAccount,pTransaction,updateIndex);
}

CBaseReserveAccount *CBaseReserveAccountFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CBaseReserveAccount *pResult;
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
	
void CBaseReserveAccountFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CBaseReserveAccountFilter::UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pBaseReserveAccount,pTransaction,updateIndex);
}

CBaseReserveAccount *CBaseReserveAccountLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CBaseReserveAccount *pResult;
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
	
void CBaseReserveAccountLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CBaseReserveAccountLinkIterator::UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pBaseReserveAccount,pTransaction,updateIndex);
}

CPartPosition *CPartPositionSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CPartPositionSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CPartPositionSingleIterator::UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pPartPosition,pTransaction,updateIndex);
}

CPartPosition *CPartPositionFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CPartPosition *pResult;
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
	
void CPartPositionFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CPartPositionFilter::UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pPartPosition,pTransaction,updateIndex);
}

CPartPosition *CPartPositionLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CPartPosition *pResult;
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
	
void CPartPositionLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CPartPositionLinkIterator::UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pPartPosition,pTransaction,updateIndex);
}

CClientPosition *CClientPositionSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CClientPositionSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CClientPositionSingleIterator::UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pClientPosition,pTransaction,updateIndex);
}

CClientPosition *CClientPositionFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CClientPosition *pResult;
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
	
void CClientPositionFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CClientPositionFilter::UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pClientPosition,pTransaction,updateIndex);
}

CClientPosition *CClientPositionLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CClientPosition *pResult;
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
	
void CClientPositionLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CClientPositionLinkIterator::UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pClientPosition,pTransaction,updateIndex);
}

CCreditLimit *CCreditLimitOfClientPositionIterator::next(void)
{
	CClientPosition *pClientPosition;
	while ((pClientPosition=m_baseIterator->next())!=NULL)
	{
		m_current=pClientPosition->getCreditLimit();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CCreditLimitOfClientPositionIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CCreditLimitOfClientPositionIterator::UpdateCurrent(CWriteableCreditLimit *pCreditLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pCreditLimit,pTransaction,updateIndex);
}

CPartRoleAccount *CPartRoleAccountOfClientPositionIterator::next(void)
{
	CClientPosition *pClientPosition;
	while ((pClientPosition=m_baseIterator->next())!=NULL)
	{
		m_current=pClientPosition->getPartRoleAccount();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CPartRoleAccountOfClientPositionIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CPartRoleAccountOfClientPositionIterator::UpdateCurrent(CWriteablePartRoleAccount *pPartRoleAccount,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pPartRoleAccount,pTransaction,updateIndex);
}

CHedgeVolume *CHedgeVolumeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CHedgeVolumeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CHedgeVolumeSingleIterator::UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pHedgeVolume,pTransaction,updateIndex);
}

CHedgeVolume *CHedgeVolumeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CHedgeVolume *pResult;
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
	
void CHedgeVolumeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CHedgeVolumeFilter::UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pHedgeVolume,pTransaction,updateIndex);
}

CHedgeVolume *CHedgeVolumeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CHedgeVolume *pResult;
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
	
void CHedgeVolumeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CHedgeVolumeLinkIterator::UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pHedgeVolume,pTransaction,updateIndex);
}

CRemainOrder *CRemainOrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CRemainOrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CRemainOrderSingleIterator::UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pRemainOrder,pTransaction,updateIndex);
}

CRemainOrder *CRemainOrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CRemainOrder *pResult;
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
	
void CRemainOrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CRemainOrderFilter::UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pRemainOrder,pTransaction,updateIndex);
}

CRemainOrder *CRemainOrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CRemainOrder *pResult;
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
	
void CRemainOrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CRemainOrderLinkIterator::UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pRemainOrder,pTransaction,updateIndex);
}

CMarketData *CMarketDataSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMarketDataSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMarketDataSingleIterator::UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMarketData,pTransaction,updateIndex);
}

CMarketData *CMarketDataFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMarketData *pResult;
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
	
void CMarketDataFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMarketDataFilter::UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMarketData,pTransaction,updateIndex);
}

CMarketData *CMarketDataLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMarketData *pResult;
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
	
void CMarketDataLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMarketDataLinkIterator::UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMarketData,pTransaction,updateIndex);
}

CClearingPartPosition *CClearingPartPositionSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CClearingPartPositionSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CClearingPartPositionSingleIterator::UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pClearingPartPosition,pTransaction,updateIndex);
}

CClearingPartPosition *CClearingPartPositionFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CClearingPartPosition *pResult;
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
	
void CClearingPartPositionFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CClearingPartPositionFilter::UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pClearingPartPosition,pTransaction,updateIndex);
}

CClearingPartPosition *CClearingPartPositionLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CClearingPartPosition *pResult;
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
	
void CClearingPartPositionLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CClearingPartPositionLinkIterator::UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pClearingPartPosition,pTransaction,updateIndex);
}

CInstrumentStatus *CInstrumentStatusSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CInstrumentStatusSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CInstrumentStatusSingleIterator::UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pInstrumentStatus,pTransaction,updateIndex);
}

CInstrumentStatus *CInstrumentStatusFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CInstrumentStatus *pResult;
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
	
void CInstrumentStatusFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CInstrumentStatusFilter::UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pInstrumentStatus,pTransaction,updateIndex);
}

CInstrumentStatus *CInstrumentStatusLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CInstrumentStatus *pResult;
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
	
void CInstrumentStatusLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CInstrumentStatusLinkIterator::UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pInstrumentStatus,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfInstrumentStatusIterator::next(void)
{
	CInstrumentStatus *pInstrumentStatus;
	while ((pInstrumentStatus=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrumentStatus->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfInstrumentStatusIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfInstrumentStatusIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CCurrPriceBanding *CCurrPriceBandingOfInstrumentStatusIterator::next(void)
{
	CInstrumentStatus *pInstrumentStatus;
	while ((pInstrumentStatus=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrumentStatus->getCurrPriceBanding();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CCurrPriceBandingOfInstrumentStatusIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CCurrPriceBandingOfInstrumentStatusIterator::UpdateCurrent(CWriteableCurrPriceBanding *pCurrPriceBanding,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pCurrPriceBanding,pTransaction,updateIndex);
}

CMdPubStatus *CMdPubStatusOfInstrumentStatusIterator::next(void)
{
	CInstrumentStatus *pInstrumentStatus;
	while ((pInstrumentStatus=m_baseIterator->next())!=NULL)
	{
		m_current=pInstrumentStatus->getMdPubStatus();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CMdPubStatusOfInstrumentStatusIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CMdPubStatusOfInstrumentStatusIterator::UpdateCurrent(CWriteableMdPubStatus *pMdPubStatus,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pMdPubStatus,pTransaction,updateIndex);
}

COrder *COrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void COrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void COrderSingleIterator::UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pOrder,pTransaction,updateIndex);
}

COrder *COrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		COrder *pResult;
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
	
void COrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void COrderFilter::UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pOrder,pTransaction,updateIndex);
}

COrder *COrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			COrder *pResult;
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
	
void COrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void COrderLinkIterator::UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pOrder,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfOrderIterator::next(void)
{
	COrder *pOrder;
	while ((pOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pOrder->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfOrderIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CPartClient *CPartClientOfOrderIterator::next(void)
{
	COrder *pOrder;
	while ((pOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pOrder->getPartClient();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CPartClientOfOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CPartClientOfOrderIterator::UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pPartClient,pTransaction,updateIndex);
}

CClientPosition *CClientPositionOfOrderIterator::next(void)
{
	COrder *pOrder;
	while ((pOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pOrder->getClientPosition();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CClientPositionOfOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CClientPositionOfOrderIterator::UpdateCurrent(CWriteableClientPosition *pClientPosition,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pClientPosition,pTransaction,updateIndex);
}

CCombOrder *CCombOrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCombOrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCombOrderSingleIterator::UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCombOrder,pTransaction,updateIndex);
}

CCombOrder *CCombOrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCombOrder *pResult;
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
	
void CCombOrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCombOrderFilter::UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCombOrder,pTransaction,updateIndex);
}

CCombOrder *CCombOrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCombOrder *pResult;
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
	
void CCombOrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCombOrderLinkIterator::UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCombOrder,pTransaction,updateIndex);
}

CPartClient *CPartClientOfCombOrderIterator::next(void)
{
	CCombOrder *pCombOrder;
	while ((pCombOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pCombOrder->getPartClient();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CPartClientOfCombOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CPartClientOfCombOrderIterator::UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pPartClient,pTransaction,updateIndex);
}

CInstrument *CInstrument1OfCombOrderIterator::next(void)
{
	CCombOrder *pCombOrder;
	while ((pCombOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pCombOrder->getInstrument1();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrument1OfCombOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrument1OfCombOrderIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CInstrument *CInstrument2OfCombOrderIterator::next(void)
{
	CCombOrder *pCombOrder;
	while ((pCombOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pCombOrder->getInstrument2();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrument2OfCombOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrument2OfCombOrderIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CInstrument *CInstrument3OfCombOrderIterator::next(void)
{
	CCombOrder *pCombOrder;
	while ((pCombOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pCombOrder->getInstrument3();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrument3OfCombOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrument3OfCombOrderIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CInstrument *CInstrument4OfCombOrderIterator::next(void)
{
	CCombOrder *pCombOrder;
	while ((pCombOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pCombOrder->getInstrument4();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrument4OfCombOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrument4OfCombOrderIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

COTCOrder *COTCOrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void COTCOrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void COTCOrderSingleIterator::UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pOTCOrder,pTransaction,updateIndex);
}

COTCOrder *COTCOrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		COTCOrder *pResult;
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
	
void COTCOrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void COTCOrderFilter::UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pOTCOrder,pTransaction,updateIndex);
}

COTCOrder *COTCOrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			COTCOrder *pResult;
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
	
void COTCOrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void COTCOrderLinkIterator::UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pOTCOrder,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfOTCOrderIterator::next(void)
{
	COTCOrder *pOTCOrder;
	while ((pOTCOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pOTCOrder->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfOTCOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfOTCOrderIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CImplyOrder *CImplyOrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CImplyOrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CImplyOrderSingleIterator::UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pImplyOrder,pTransaction,updateIndex);
}

CImplyOrder *CImplyOrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CImplyOrder *pResult;
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
	
void CImplyOrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CImplyOrderFilter::UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pImplyOrder,pTransaction,updateIndex);
}

CImplyOrder *CImplyOrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CImplyOrder *pResult;
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
	
void CImplyOrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CImplyOrderLinkIterator::UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pImplyOrder,pTransaction,updateIndex);
}

CQuote *CQuoteSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CQuoteSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CQuoteSingleIterator::UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pQuote,pTransaction,updateIndex);
}

CQuote *CQuoteFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CQuote *pResult;
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
	
void CQuoteFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CQuoteFilter::UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pQuote,pTransaction,updateIndex);
}

CQuote *CQuoteLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CQuote *pResult;
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
	
void CQuoteLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CQuoteLinkIterator::UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pQuote,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfQuoteIterator::next(void)
{
	CQuote *pQuote;
	while ((pQuote=m_baseIterator->next())!=NULL)
	{
		m_current=pQuote->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfQuoteIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfQuoteIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CPartClient *CPartClientOfQuoteIterator::next(void)
{
	CQuote *pQuote;
	while ((pQuote=m_baseIterator->next())!=NULL)
	{
		m_current=pQuote->getPartClient();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CPartClientOfQuoteIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CPartClientOfQuoteIterator::UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pPartClient,pTransaction,updateIndex);
}

CMBLMarketData *CMBLMarketDataSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CMBLMarketDataSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CMBLMarketDataSingleIterator::UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pMBLMarketData,pTransaction,updateIndex);
}

CMBLMarketData *CMBLMarketDataFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CMBLMarketData *pResult;
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
	
void CMBLMarketDataFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CMBLMarketDataFilter::UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pMBLMarketData,pTransaction,updateIndex);
}

CMBLMarketData *CMBLMarketDataLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CMBLMarketData *pResult;
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
	
void CMBLMarketDataLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CMBLMarketDataLinkIterator::UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pMBLMarketData,pTransaction,updateIndex);
}

CTrade *CTradeSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CTradeSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CTradeSingleIterator::UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pTrade,pTransaction,updateIndex);
}

CTrade *CTradeFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CTrade *pResult;
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
	
void CTradeFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CTradeFilter::UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pTrade,pTransaction,updateIndex);
}

CTrade *CTradeLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CTrade *pResult;
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
	
void CTradeLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CTradeLinkIterator::UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pTrade,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfTradeIterator::next(void)
{
	CTrade *pTrade;
	while ((pTrade=m_baseIterator->next())!=NULL)
	{
		m_current=pTrade->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfTradeIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfTradeIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CPartClient *CPartClientOfTradeIterator::next(void)
{
	CTrade *pTrade;
	while ((pTrade=m_baseIterator->next())!=NULL)
	{
		m_current=pTrade->getPartClient();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CPartClientOfTradeIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CPartClientOfTradeIterator::UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pPartClient,pTransaction,updateIndex);
}

CFusePhase *CFusePhaseSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CFusePhaseSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CFusePhaseSingleIterator::UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pFusePhase,pTransaction,updateIndex);
}

CFusePhase *CFusePhaseFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CFusePhase *pResult;
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
	
void CFusePhaseFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CFusePhaseFilter::UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pFusePhase,pTransaction,updateIndex);
}

CFusePhase *CFusePhaseLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CFusePhase *pResult;
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
	
void CFusePhaseLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CFusePhaseLinkIterator::UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pFusePhase,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfFusePhaseIterator::next(void)
{
	CFusePhase *pFusePhase;
	while ((pFusePhase=m_baseIterator->next())!=NULL)
	{
		m_current=pFusePhase->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfFusePhaseIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfFusePhaseIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CExecOrder *CExecOrderSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CExecOrderSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CExecOrderSingleIterator::UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pExecOrder,pTransaction,updateIndex);
}

CExecOrder *CExecOrderFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CExecOrder *pResult;
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
	
void CExecOrderFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CExecOrderFilter::UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pExecOrder,pTransaction,updateIndex);
}

CExecOrder *CExecOrderLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CExecOrder *pResult;
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
	
void CExecOrderLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CExecOrderLinkIterator::UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pExecOrder,pTransaction,updateIndex);
}

CPartClient *CPartClientOfExecOrderIterator::next(void)
{
	CExecOrder *pExecOrder;
	while ((pExecOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pExecOrder->getPartClient();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CPartClientOfExecOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CPartClientOfExecOrderIterator::UpdateCurrent(CWriteablePartClient *pPartClient,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pPartClient,pTransaction,updateIndex);
}

CInstrument *CInstrumentOfExecOrderIterator::next(void)
{
	CExecOrder *pExecOrder;
	while ((pExecOrder=m_baseIterator->next())!=NULL)
	{
		m_current=pExecOrder->getInstrument();
		if (m_current!=NULL)
		{
			return m_current;
		}
	}
	return NULL;
}
	
void CInstrumentOfExecOrderIterator::DeleteCurrent(CTransaction *pTransaction)
{
	m_Factory->remove(m_current,pTransaction);
}
	
void CInstrumentOfExecOrderIterator::UpdateCurrent(CWriteableInstrument *pInstrument,CTransaction *pTransaction, bool updateIndex)
{
	m_Factory->update(m_current,pInstrument,pTransaction,updateIndex);
}

CUniPressure *CUniPressureSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CUniPressureSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CUniPressureSingleIterator::UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pUniPressure,pTransaction,updateIndex);
}

CUniPressure *CUniPressureFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CUniPressure *pResult;
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
	
void CUniPressureFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CUniPressureFilter::UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pUniPressure,pTransaction,updateIndex);
}

CUniPressure *CUniPressureLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CUniPressure *pResult;
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
	
void CUniPressureLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CUniPressureLinkIterator::UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pUniPressure,pTransaction,updateIndex);
}

CBasePriceLimit *CBasePriceLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CBasePriceLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CBasePriceLimitSingleIterator::UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pBasePriceLimit,pTransaction,updateIndex);
}

CBasePriceLimit *CBasePriceLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CBasePriceLimit *pResult;
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
	
void CBasePriceLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CBasePriceLimitFilter::UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pBasePriceLimit,pTransaction,updateIndex);
}

CBasePriceLimit *CBasePriceLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CBasePriceLimit *pResult;
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
	
void CBasePriceLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CBasePriceLimitLinkIterator::UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pBasePriceLimit,pTransaction,updateIndex);
}

CCreditLimit *CCreditLimitSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCreditLimitSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCreditLimitSingleIterator::UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCreditLimit,pTransaction,updateIndex);
}

CCreditLimit *CCreditLimitFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCreditLimit *pResult;
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
	
void CCreditLimitFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCreditLimitFilter::UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCreditLimit,pTransaction,updateIndex);
}

CCreditLimit *CCreditLimitLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCreditLimit *pResult;
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
	
void CCreditLimitLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCreditLimitLinkIterator::UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCreditLimit,pTransaction,updateIndex);
}

CCurrInstrumentOption *CCurrInstrumentOptionSingleIterator::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	m_finished=true;
	return m_pResult;
}
	
void CCurrInstrumentOptionSingleIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->remove(m_pResult,pTransaction);
}
	
void CCurrInstrumentOptionSingleIterator::UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction, bool updateIndex)
{
	if ((m_finished)||(m_pResult==NULL))
	{
		RAISE_RUNTIME_ERROR("Delete NULL record");
	}
	m_Factory->update(m_pResult,pCurrInstrumentOption,pTransaction,updateIndex);
}

CCurrInstrumentOption *CCurrInstrumentOptionFilter::next(void)
{
	if (m_finished)
	{
		return NULL;
	}
	for (;;)
	{
		CCurrInstrumentOption *pResult;
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
	
void CCurrInstrumentOptionFilter::DeleteCurrent(CTransaction *pTransaction)
{
	m_baseIterator->DeleteCurrent(pTransaction);
}
	
void CCurrInstrumentOptionFilter::UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction, bool updateIndex)
{
	m_baseIterator->UpdateCurrent(pCurrInstrumentOption,pTransaction,updateIndex);
}

CCurrInstrumentOption *CCurrInstrumentOptionLinkIterator::next(void)
{
	for (;m_id<2;m_id++)
	{
		for (;;)
		{
			CCurrInstrumentOption *pResult;
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
	
void CCurrInstrumentOptionLinkIterator::DeleteCurrent(CTransaction *pTransaction)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->DeleteCurrent(pTransaction);
}
	
void CCurrInstrumentOptionLinkIterator::UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction, bool updateIndex)
{
	if (m_id>=2)
	{
		RAISE_RUNTIME_ERROR("Delete Empty");
	}
	m_baseIterator[m_id]->UpdateCurrent(pCurrInstrumentOption,pTransaction,updateIndex);
}

