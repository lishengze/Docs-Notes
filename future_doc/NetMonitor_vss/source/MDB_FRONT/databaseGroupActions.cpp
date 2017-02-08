/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseGroupActions.cpp
///@brief实现了若干个内存数据库的群组操作
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseGroupActions.h"

void groupAction(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInvalidateOrder *pSysInvalidateOrder;
	
	while ((pSysInvalidateOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysInvalidateOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInvalidateOrder *pSysInvalidateOrder;
	CWriteableSysInvalidateOrder theSysInvalidateOrder;
	bool updateIndex;
	CSysInvalidateOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysInvalidateOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysInvalidateOrder,&theSysInvalidateOrder);
		needContinue=updateFunc(&theSysInvalidateOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysInvalidateOrder,&theSysInvalidateOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInvalidateOrder *pSysInvalidateOrder;
	int selected;
	CSysInvalidateOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysInvalidateOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysInvalidateOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysInvalidateOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysOrderStatusIterator *pIterator, TSysOrderStatusActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysOrderStatus *pSysOrderStatus;
	
	while ((pSysOrderStatus=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysOrderStatus, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysOrderStatusIterator *pIterator, TSysOrderStatusUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysOrderStatus *pSysOrderStatus;
	CWriteableSysOrderStatus theSysOrderStatus;
	bool updateIndex;
	CSysOrderStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysOrderStatus=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysOrderStatus,&theSysOrderStatus);
		needContinue=updateFunc(&theSysOrderStatus, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysOrderStatus,&theSysOrderStatus,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysOrderStatusIterator *pIterator, TSysOrderStatusSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysOrderStatus *pSysOrderStatus;
	int selected;
	CSysOrderStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysOrderStatus=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysOrderStatus, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysOrderStatus,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysBargainOrderIterator *pIterator, TSysBargainOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysBargainOrder *pSysBargainOrder;
	
	while ((pSysBargainOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysBargainOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysBargainOrderIterator *pIterator, TSysBargainOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysBargainOrder *pSysBargainOrder;
	CWriteableSysBargainOrder theSysBargainOrder;
	bool updateIndex;
	CSysBargainOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysBargainOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysBargainOrder,&theSysBargainOrder);
		needContinue=updateFunc(&theSysBargainOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysBargainOrder,&theSysBargainOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysBargainOrderIterator *pIterator, TSysBargainOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysBargainOrder *pSysBargainOrder;
	int selected;
	CSysBargainOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysBargainOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysBargainOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysBargainOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysInstPropertyIterator *pIterator, TSysInstPropertyActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInstProperty *pSysInstProperty;
	
	while ((pSysInstProperty=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysInstProperty, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysInstPropertyIterator *pIterator, TSysInstPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInstProperty *pSysInstProperty;
	CWriteableSysInstProperty theSysInstProperty;
	bool updateIndex;
	CSysInstPropertyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysInstProperty=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysInstProperty,&theSysInstProperty);
		needContinue=updateFunc(&theSysInstProperty, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysInstProperty,&theSysInstProperty,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysInstPropertyIterator *pIterator, TSysInstPropertySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInstProperty *pSysInstProperty;
	int selected;
	CSysInstPropertyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysInstProperty=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysInstProperty, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysInstProperty,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMarginRateIterator *pIterator, TSysMarginRateActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMarginRate *pSysMarginRate;
	
	while ((pSysMarginRate=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMarginRate, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMarginRateIterator *pIterator, TSysMarginRateUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMarginRate *pSysMarginRate;
	CWriteableSysMarginRate theSysMarginRate;
	bool updateIndex;
	CSysMarginRateFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMarginRate=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMarginRate,&theSysMarginRate);
		needContinue=updateFunc(&theSysMarginRate, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMarginRate,&theSysMarginRate,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMarginRateIterator *pIterator, TSysMarginRateSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMarginRate *pSysMarginRate;
	int selected;
	CSysMarginRateFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMarginRate=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMarginRate, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMarginRate,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysPriceLimitIterator *pIterator, TSysPriceLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPriceLimit *pSysPriceLimit;
	
	while ((pSysPriceLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysPriceLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysPriceLimitIterator *pIterator, TSysPriceLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPriceLimit *pSysPriceLimit;
	CWriteableSysPriceLimit theSysPriceLimit;
	bool updateIndex;
	CSysPriceLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPriceLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysPriceLimit,&theSysPriceLimit);
		needContinue=updateFunc(&theSysPriceLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysPriceLimit,&theSysPriceLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysPriceLimitIterator *pIterator, TSysPriceLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPriceLimit *pSysPriceLimit;
	int selected;
	CSysPriceLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPriceLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysPriceLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysPriceLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartPosiLimit *pSysPartPosiLimit;
	
	while ((pSysPartPosiLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysPartPosiLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartPosiLimit *pSysPartPosiLimit;
	CWriteableSysPartPosiLimit theSysPartPosiLimit;
	bool updateIndex;
	CSysPartPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPartPosiLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysPartPosiLimit,&theSysPartPosiLimit);
		needContinue=updateFunc(&theSysPartPosiLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysPartPosiLimit,&theSysPartPosiLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartPosiLimit *pSysPartPosiLimit;
	int selected;
	CSysPartPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPartPosiLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysPartPosiLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysPartPosiLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientPosiLimit *pSysClientPosiLimit;
	
	while ((pSysClientPosiLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysClientPosiLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientPosiLimit *pSysClientPosiLimit;
	CWriteableSysClientPosiLimit theSysClientPosiLimit;
	bool updateIndex;
	CSysClientPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientPosiLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysClientPosiLimit,&theSysClientPosiLimit);
		needContinue=updateFunc(&theSysClientPosiLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysClientPosiLimit,&theSysClientPosiLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientPosiLimit *pSysClientPosiLimit;
	int selected;
	CSysClientPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientPosiLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysClientPosiLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysClientPosiLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysSpecialPosiLimit *pSysSpecialPosiLimit;
	
	while ((pSysSpecialPosiLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysSpecialPosiLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysSpecialPosiLimit *pSysSpecialPosiLimit;
	CWriteableSysSpecialPosiLimit theSysSpecialPosiLimit;
	bool updateIndex;
	CSysSpecialPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysSpecialPosiLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysSpecialPosiLimit,&theSysSpecialPosiLimit);
		needContinue=updateFunc(&theSysSpecialPosiLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysSpecialPosiLimit,&theSysSpecialPosiLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysSpecialPosiLimit *pSysSpecialPosiLimit;
	int selected;
	CSysSpecialPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysSpecialPosiLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysSpecialPosiLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysSpecialPosiLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysTransactionChgIterator *pIterator, TSysTransactionChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysTransactionChg *pSysTransactionChg;
	
	while ((pSysTransactionChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysTransactionChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysTransactionChgIterator *pIterator, TSysTransactionChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysTransactionChg *pSysTransactionChg;
	CWriteableSysTransactionChg theSysTransactionChg;
	bool updateIndex;
	CSysTransactionChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysTransactionChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysTransactionChg,&theSysTransactionChg);
		needContinue=updateFunc(&theSysTransactionChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysTransactionChg,&theSysTransactionChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysTransactionChgIterator *pIterator, TSysTransactionChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysTransactionChg *pSysTransactionChg;
	int selected;
	CSysTransactionChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysTransactionChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysTransactionChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysTransactionChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysClientChgIterator *pIterator, TSysClientChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientChg *pSysClientChg;
	
	while ((pSysClientChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysClientChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysClientChgIterator *pIterator, TSysClientChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientChg *pSysClientChg;
	CWriteableSysClientChg theSysClientChg;
	bool updateIndex;
	CSysClientChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysClientChg,&theSysClientChg);
		needContinue=updateFunc(&theSysClientChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysClientChg,&theSysClientChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysClientChgIterator *pIterator, TSysClientChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientChg *pSysClientChg;
	int selected;
	CSysClientChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysClientChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysClientChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysPartClientChgIterator *pIterator, TSysPartClientChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartClientChg *pSysPartClientChg;
	
	while ((pSysPartClientChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysPartClientChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysPartClientChgIterator *pIterator, TSysPartClientChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartClientChg *pSysPartClientChg;
	CWriteableSysPartClientChg theSysPartClientChg;
	bool updateIndex;
	CSysPartClientChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPartClientChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysPartClientChg,&theSysPartClientChg);
		needContinue=updateFunc(&theSysPartClientChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysPartClientChg,&theSysPartClientChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysPartClientChgIterator *pIterator, TSysPartClientChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartClientChg *pSysPartClientChg;
	int selected;
	CSysPartClientChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPartClientChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysPartClientChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysPartClientChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPosiLimitChg *pSysPosiLimitChg;
	
	while ((pSysPosiLimitChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysPosiLimitChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPosiLimitChg *pSysPosiLimitChg;
	CWriteableSysPosiLimitChg theSysPosiLimitChg;
	bool updateIndex;
	CSysPosiLimitChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPosiLimitChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysPosiLimitChg,&theSysPosiLimitChg);
		needContinue=updateFunc(&theSysPosiLimitChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysPosiLimitChg,&theSysPosiLimitChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPosiLimitChg *pSysPosiLimitChg;
	int selected;
	CSysPosiLimitChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPosiLimitChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysPosiLimitChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysPosiLimitChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientPosiLimitChg *pSysClientPosiLimitChg;
	
	while ((pSysClientPosiLimitChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysClientPosiLimitChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientPosiLimitChg *pSysClientPosiLimitChg;
	CWriteableSysClientPosiLimitChg theSysClientPosiLimitChg;
	bool updateIndex;
	CSysClientPosiLimitChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientPosiLimitChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysClientPosiLimitChg,&theSysClientPosiLimitChg);
		needContinue=updateFunc(&theSysClientPosiLimitChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysClientPosiLimitChg,&theSysClientPosiLimitChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientPosiLimitChg *pSysClientPosiLimitChg;
	int selected;
	CSysClientPosiLimitChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientPosiLimitChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysClientPosiLimitChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysClientPosiLimitChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysSpecPosiLimitChg *pSysSpecPosiLimitChg;
	
	while ((pSysSpecPosiLimitChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysSpecPosiLimitChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysSpecPosiLimitChg *pSysSpecPosiLimitChg;
	CWriteableSysSpecPosiLimitChg theSysSpecPosiLimitChg;
	bool updateIndex;
	CSysSpecPosiLimitChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysSpecPosiLimitChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysSpecPosiLimitChg,&theSysSpecPosiLimitChg);
		needContinue=updateFunc(&theSysSpecPosiLimitChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysSpecPosiLimitChg,&theSysSpecPosiLimitChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysSpecPosiLimitChg *pSysSpecPosiLimitChg;
	int selected;
	CSysSpecPosiLimitChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysSpecPosiLimitChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysSpecPosiLimitChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysSpecPosiLimitChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysHedgeDetailChg *pSysHedgeDetailChg;
	
	while ((pSysHedgeDetailChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysHedgeDetailChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysHedgeDetailChg *pSysHedgeDetailChg;
	CWriteableSysHedgeDetailChg theSysHedgeDetailChg;
	bool updateIndex;
	CSysHedgeDetailChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysHedgeDetailChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysHedgeDetailChg,&theSysHedgeDetailChg);
		needContinue=updateFunc(&theSysHedgeDetailChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysHedgeDetailChg,&theSysHedgeDetailChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysHedgeDetailChg *pSysHedgeDetailChg;
	int selected;
	CSysHedgeDetailChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysHedgeDetailChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysHedgeDetailChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysHedgeDetailChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysParticipantChgIterator *pIterator, TSysParticipantChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticipantChg *pSysParticipantChg;
	
	while ((pSysParticipantChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysParticipantChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysParticipantChgIterator *pIterator, TSysParticipantChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticipantChg *pSysParticipantChg;
	CWriteableSysParticipantChg theSysParticipantChg;
	bool updateIndex;
	CSysParticipantChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysParticipantChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysParticipantChg,&theSysParticipantChg);
		needContinue=updateFunc(&theSysParticipantChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysParticipantChg,&theSysParticipantChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysParticipantChgIterator *pIterator, TSysParticipantChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticipantChg *pSysParticipantChg;
	int selected;
	CSysParticipantChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysParticipantChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysParticipantChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysParticipantChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMarginRateChg *pSysMarginRateChg;
	
	while ((pSysMarginRateChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMarginRateChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMarginRateChg *pSysMarginRateChg;
	CWriteableSysMarginRateChg theSysMarginRateChg;
	bool updateIndex;
	CSysMarginRateChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMarginRateChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMarginRateChg,&theSysMarginRateChg);
		needContinue=updateFunc(&theSysMarginRateChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMarginRateChg,&theSysMarginRateChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMarginRateChg *pSysMarginRateChg;
	int selected;
	CSysMarginRateChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMarginRateChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMarginRateChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMarginRateChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysUserIpChgIterator *pIterator, TSysUserIpChgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserIpChg *pSysUserIpChg;
	
	while ((pSysUserIpChg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysUserIpChg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysUserIpChgIterator *pIterator, TSysUserIpChgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserIpChg *pSysUserIpChg;
	CWriteableSysUserIpChg theSysUserIpChg;
	bool updateIndex;
	CSysUserIpChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysUserIpChg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysUserIpChg,&theSysUserIpChg);
		needContinue=updateFunc(&theSysUserIpChg, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysUserIpChg,&theSysUserIpChg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysUserIpChgIterator *pIterator, TSysUserIpChgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserIpChg *pSysUserIpChg;
	int selected;
	CSysUserIpChgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysUserIpChg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysUserIpChg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysUserIpChg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysPartTradeIterator *pIterator, TSysPartTradeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartTrade *pSysPartTrade;
	
	while ((pSysPartTrade=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysPartTrade, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysPartTradeIterator *pIterator, TSysPartTradeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartTrade *pSysPartTrade;
	CWriteableSysPartTrade theSysPartTrade;
	bool updateIndex;
	CSysPartTradeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPartTrade=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysPartTrade,&theSysPartTrade);
		needContinue=updateFunc(&theSysPartTrade, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysPartTrade,&theSysPartTrade,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysPartTradeIterator *pIterator, TSysPartTradeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysPartTrade *pSysPartTrade;
	int selected;
	CSysPartTradeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysPartTrade=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysPartTrade, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysPartTrade,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbObjectAttr *pSysMdbObjectAttr;
	
	while ((pSysMdbObjectAttr=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbObjectAttr, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbObjectAttr *pSysMdbObjectAttr;
	CWriteableSysMdbObjectAttr theSysMdbObjectAttr;
	bool updateIndex;
	CSysMdbObjectAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbObjectAttr=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbObjectAttr,&theSysMdbObjectAttr);
		needContinue=updateFunc(&theSysMdbObjectAttr, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbObjectAttr,&theSysMdbObjectAttr,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbObjectAttr *pSysMdbObjectAttr;
	int selected;
	CSysMdbObjectAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbObjectAttr=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbObjectAttr, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbObjectAttr,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbSyslogInfo *pSysMdbSyslogInfo;
	
	while ((pSysMdbSyslogInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbSyslogInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbSyslogInfo *pSysMdbSyslogInfo;
	CWriteableSysMdbSyslogInfo theSysMdbSyslogInfo;
	bool updateIndex;
	CSysMdbSyslogInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbSyslogInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbSyslogInfo,&theSysMdbSyslogInfo);
		needContinue=updateFunc(&theSysMdbSyslogInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbSyslogInfo,&theSysMdbSyslogInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbSyslogInfo *pSysMdbSyslogInfo;
	int selected;
	CSysMdbSyslogInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbSyslogInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbSyslogInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbSyslogInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysUserInfoIterator *pIterator, TSysUserInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserInfo *pSysUserInfo;
	
	while ((pSysUserInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysUserInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysUserInfoIterator *pIterator, TSysUserInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserInfo *pSysUserInfo;
	CWriteableSysUserInfo theSysUserInfo;
	bool updateIndex;
	CSysUserInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysUserInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysUserInfo,&theSysUserInfo);
		needContinue=updateFunc(&theSysUserInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysUserInfo,&theSysUserInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysUserInfoIterator *pIterator, TSysUserInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserInfo *pSysUserInfo;
	int selected;
	CSysUserInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysUserInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysUserInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysUserInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysOnlineUserInfo *pSysOnlineUserInfo;
	
	while ((pSysOnlineUserInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysOnlineUserInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysOnlineUserInfo *pSysOnlineUserInfo;
	CWriteableSysOnlineUserInfo theSysOnlineUserInfo;
	bool updateIndex;
	CSysOnlineUserInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysOnlineUserInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysOnlineUserInfo,&theSysOnlineUserInfo);
		needContinue=updateFunc(&theSysOnlineUserInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysOnlineUserInfo,&theSysOnlineUserInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysOnlineUserInfo *pSysOnlineUserInfo;
	int selected;
	CSysOnlineUserInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysOnlineUserInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysOnlineUserInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysOnlineUserInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysWarningEventIterator *pIterator, TSysWarningEventActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysWarningEvent *pSysWarningEvent;
	
	while ((pSysWarningEvent=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysWarningEvent, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysWarningEventIterator *pIterator, TSysWarningEventUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysWarningEvent *pSysWarningEvent;
	CWriteableSysWarningEvent theSysWarningEvent;
	bool updateIndex;
	CSysWarningEventFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysWarningEvent=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysWarningEvent,&theSysWarningEvent);
		needContinue=updateFunc(&theSysWarningEvent, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysWarningEvent,&theSysWarningEvent,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysWarningEventIterator *pIterator, TSysWarningEventSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysWarningEvent *pSysWarningEvent;
	int selected;
	CSysWarningEventFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysWarningEvent=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysWarningEvent, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysWarningEvent,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysWarningQueryIterator *pIterator, TSysWarningQueryActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysWarningQuery *pSysWarningQuery;
	
	while ((pSysWarningQuery=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysWarningQuery, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysWarningQueryIterator *pIterator, TSysWarningQueryUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysWarningQuery *pSysWarningQuery;
	CWriteableSysWarningQuery theSysWarningQuery;
	bool updateIndex;
	CSysWarningQueryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysWarningQuery=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysWarningQuery,&theSysWarningQuery);
		needContinue=updateFunc(&theSysWarningQuery, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysWarningQuery,&theSysWarningQuery,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysWarningQueryIterator *pIterator, TSysWarningQuerySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysWarningQuery *pSysWarningQuery;
	int selected;
	CSysWarningQueryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysWarningQuery=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysWarningQuery, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysWarningQuery,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSyslogEventIterator *pIterator, TSyslogEventActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSyslogEvent *pSyslogEvent;
	
	while ((pSyslogEvent=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSyslogEvent, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSyslogEventIterator *pIterator, TSyslogEventUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSyslogEvent *pSyslogEvent;
	CWriteableSyslogEvent theSyslogEvent;
	bool updateIndex;
	CSyslogEventFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSyslogEvent=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSyslogEvent,&theSyslogEvent);
		needContinue=updateFunc(&theSyslogEvent, pTransaction, parameter, &updateIndex);
		pFactory->update(pSyslogEvent,&theSyslogEvent,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSyslogEventIterator *pIterator, TSyslogEventSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSyslogEvent *pSyslogEvent;
	int selected;
	CSyslogEventFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSyslogEvent=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSyslogEvent, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSyslogEvent,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysEventDescripIterator *pIterator, TSysEventDescripActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysEventDescrip *pSysEventDescrip;
	
	while ((pSysEventDescrip=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysEventDescrip, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysEventDescripIterator *pIterator, TSysEventDescripUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysEventDescrip *pSysEventDescrip;
	CWriteableSysEventDescrip theSysEventDescrip;
	bool updateIndex;
	CSysEventDescripFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysEventDescrip=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysEventDescrip,&theSysEventDescrip);
		needContinue=updateFunc(&theSysEventDescrip, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysEventDescrip,&theSysEventDescrip,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysEventDescripIterator *pIterator, TSysEventDescripSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysEventDescrip *pSysEventDescrip;
	int selected;
	CSysEventDescripFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysEventDescrip=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysEventDescrip, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysEventDescrip,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvCommon *pRspQryHostEnvCommon;
	
	while ((pRspQryHostEnvCommon=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRspQryHostEnvCommon, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvCommon *pRspQryHostEnvCommon;
	CWriteableRspQryHostEnvCommon theRspQryHostEnvCommon;
	bool updateIndex;
	CRspQryHostEnvCommonFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvCommon=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRspQryHostEnvCommon,&theRspQryHostEnvCommon);
		needContinue=updateFunc(&theRspQryHostEnvCommon, pTransaction, parameter, &updateIndex);
		pFactory->update(pRspQryHostEnvCommon,&theRspQryHostEnvCommon,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvCommon *pRspQryHostEnvCommon;
	int selected;
	CRspQryHostEnvCommonFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvCommon=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRspQryHostEnvCommon, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRspQryHostEnvCommon,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvLan *pRspQryHostEnvLan;
	
	while ((pRspQryHostEnvLan=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRspQryHostEnvLan, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvLan *pRspQryHostEnvLan;
	CWriteableRspQryHostEnvLan theRspQryHostEnvLan;
	bool updateIndex;
	CRspQryHostEnvLanFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvLan=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRspQryHostEnvLan,&theRspQryHostEnvLan);
		needContinue=updateFunc(&theRspQryHostEnvLan, pTransaction, parameter, &updateIndex);
		pFactory->update(pRspQryHostEnvLan,&theRspQryHostEnvLan,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvLan *pRspQryHostEnvLan;
	int selected;
	CRspQryHostEnvLanFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvLan=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRspQryHostEnvLan, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRspQryHostEnvLan,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvStorage *pRspQryHostEnvStorage;
	
	while ((pRspQryHostEnvStorage=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRspQryHostEnvStorage, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvStorage *pRspQryHostEnvStorage;
	CWriteableRspQryHostEnvStorage theRspQryHostEnvStorage;
	bool updateIndex;
	CRspQryHostEnvStorageFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvStorage=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRspQryHostEnvStorage,&theRspQryHostEnvStorage);
		needContinue=updateFunc(&theRspQryHostEnvStorage, pTransaction, parameter, &updateIndex);
		pFactory->update(pRspQryHostEnvStorage,&theRspQryHostEnvStorage,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvStorage *pRspQryHostEnvStorage;
	int selected;
	CRspQryHostEnvStorageFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvStorage=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRspQryHostEnvStorage, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRspQryHostEnvStorage,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvIO *pRspQryHostEnvIO;
	
	while ((pRspQryHostEnvIO=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRspQryHostEnvIO, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvIO *pRspQryHostEnvIO;
	CWriteableRspQryHostEnvIO theRspQryHostEnvIO;
	bool updateIndex;
	CRspQryHostEnvIOFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvIO=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRspQryHostEnvIO,&theRspQryHostEnvIO);
		needContinue=updateFunc(&theRspQryHostEnvIO, pTransaction, parameter, &updateIndex);
		pFactory->update(pRspQryHostEnvIO,&theRspQryHostEnvIO,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvIO *pRspQryHostEnvIO;
	int selected;
	CRspQryHostEnvIOFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvIO=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRspQryHostEnvIO, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRspQryHostEnvIO,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvFS *pRspQryHostEnvFS;
	
	while ((pRspQryHostEnvFS=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRspQryHostEnvFS, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvFS *pRspQryHostEnvFS;
	CWriteableRspQryHostEnvFS theRspQryHostEnvFS;
	bool updateIndex;
	CRspQryHostEnvFSFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvFS=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRspQryHostEnvFS,&theRspQryHostEnvFS);
		needContinue=updateFunc(&theRspQryHostEnvFS, pTransaction, parameter, &updateIndex);
		pFactory->update(pRspQryHostEnvFS,&theRspQryHostEnvFS,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvFS *pRspQryHostEnvFS;
	int selected;
	CRspQryHostEnvFSFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvFS=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRspQryHostEnvFS, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRspQryHostEnvFS,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvSwap *pRspQryHostEnvSwap;
	
	while ((pRspQryHostEnvSwap=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRspQryHostEnvSwap, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvSwap *pRspQryHostEnvSwap;
	CWriteableRspQryHostEnvSwap theRspQryHostEnvSwap;
	bool updateIndex;
	CRspQryHostEnvSwapFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvSwap=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRspQryHostEnvSwap,&theRspQryHostEnvSwap);
		needContinue=updateFunc(&theRspQryHostEnvSwap, pTransaction, parameter, &updateIndex);
		pFactory->update(pRspQryHostEnvSwap,&theRspQryHostEnvSwap,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvSwap *pRspQryHostEnvSwap;
	int selected;
	CRspQryHostEnvSwapFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvSwap=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRspQryHostEnvSwap, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRspQryHostEnvSwap,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg;
	
	while ((pRspQryHostEnvLanCfg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRspQryHostEnvLanCfg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg;
	CWriteableRspQryHostEnvLanCfg theRspQryHostEnvLanCfg;
	bool updateIndex;
	CRspQryHostEnvLanCfgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvLanCfg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRspQryHostEnvLanCfg,&theRspQryHostEnvLanCfg);
		needContinue=updateFunc(&theRspQryHostEnvLanCfg, pTransaction, parameter, &updateIndex);
		pFactory->update(pRspQryHostEnvLanCfg,&theRspQryHostEnvLanCfg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg;
	int selected;
	CRspQryHostEnvLanCfgFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRspQryHostEnvLanCfg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRspQryHostEnvLanCfg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRspQryHostEnvLanCfg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopCpuInfo *pSysMdbTopCpuInfo;
	
	while ((pSysMdbTopCpuInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbTopCpuInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopCpuInfo *pSysMdbTopCpuInfo;
	CWriteableSysMdbTopCpuInfo theSysMdbTopCpuInfo;
	bool updateIndex;
	CSysMdbTopCpuInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTopCpuInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbTopCpuInfo,&theSysMdbTopCpuInfo);
		needContinue=updateFunc(&theSysMdbTopCpuInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbTopCpuInfo,&theSysMdbTopCpuInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopCpuInfo *pSysMdbTopCpuInfo;
	int selected;
	CSysMdbTopCpuInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTopCpuInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbTopCpuInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbTopCpuInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopMemInfo *pSysMdbTopMemInfo;
	
	while ((pSysMdbTopMemInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbTopMemInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopMemInfo *pSysMdbTopMemInfo;
	CWriteableSysMdbTopMemInfo theSysMdbTopMemInfo;
	bool updateIndex;
	CSysMdbTopMemInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTopMemInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbTopMemInfo,&theSysMdbTopMemInfo);
		needContinue=updateFunc(&theSysMdbTopMemInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbTopMemInfo,&theSysMdbTopMemInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopMemInfo *pSysMdbTopMemInfo;
	int selected;
	CSysMdbTopMemInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTopMemInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbTopMemInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbTopMemInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopProcessInfo *pSysMdbTopProcessInfo;
	
	while ((pSysMdbTopProcessInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbTopProcessInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopProcessInfo *pSysMdbTopProcessInfo;
	CWriteableSysMdbTopProcessInfo theSysMdbTopProcessInfo;
	bool updateIndex;
	CSysMdbTopProcessInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTopProcessInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbTopProcessInfo,&theSysMdbTopProcessInfo);
		needContinue=updateFunc(&theSysMdbTopProcessInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbTopProcessInfo,&theSysMdbTopProcessInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTopProcessInfo *pSysMdbTopProcessInfo;
	int selected;
	CSysMdbTopProcessInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTopProcessInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbTopProcessInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbTopProcessInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbFileSystemInfo *pSysMdbFileSystemInfo;
	
	while ((pSysMdbFileSystemInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbFileSystemInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbFileSystemInfo *pSysMdbFileSystemInfo;
	CWriteableSysMdbFileSystemInfo theSysMdbFileSystemInfo;
	bool updateIndex;
	CSysMdbFileSystemInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbFileSystemInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbFileSystemInfo,&theSysMdbFileSystemInfo);
		needContinue=updateFunc(&theSysMdbFileSystemInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbFileSystemInfo,&theSysMdbFileSystemInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbFileSystemInfo *pSysMdbFileSystemInfo;
	int selected;
	CSysMdbFileSystemInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbFileSystemInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbFileSystemInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbFileSystemInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbNetworkInfo *pSysMdbNetworkInfo;
	
	while ((pSysMdbNetworkInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbNetworkInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbNetworkInfo *pSysMdbNetworkInfo;
	CWriteableSysMdbNetworkInfo theSysMdbNetworkInfo;
	bool updateIndex;
	CSysMdbNetworkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbNetworkInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbNetworkInfo,&theSysMdbNetworkInfo);
		needContinue=updateFunc(&theSysMdbNetworkInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbNetworkInfo,&theSysMdbNetworkInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbNetworkInfo *pSysMdbNetworkInfo;
	int selected;
	CSysMdbNetworkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbNetworkInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbNetworkInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbNetworkInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysParticipantInitIterator *pIterator, TSysParticipantInitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticipantInit *pSysParticipantInit;
	
	while ((pSysParticipantInit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysParticipantInit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysParticipantInitIterator *pIterator, TSysParticipantInitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticipantInit *pSysParticipantInit;
	CWriteableSysParticipantInit theSysParticipantInit;
	bool updateIndex;
	CSysParticipantInitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysParticipantInit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysParticipantInit,&theSysParticipantInit);
		needContinue=updateFunc(&theSysParticipantInit, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysParticipantInit,&theSysParticipantInit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysParticipantInitIterator *pIterator, TSysParticipantInitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticipantInit *pSysParticipantInit;
	int selected;
	CSysParticipantInitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysParticipantInit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysParticipantInit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysParticipantInit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysUserInitIterator *pIterator, TSysUserInitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserInit *pSysUserInit;
	
	while ((pSysUserInit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysUserInit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysUserInitIterator *pIterator, TSysUserInitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserInit *pSysUserInit;
	CWriteableSysUserInit theSysUserInit;
	bool updateIndex;
	CSysUserInitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysUserInit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysUserInit,&theSysUserInit);
		needContinue=updateFunc(&theSysUserInit, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysUserInit,&theSysUserInit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysUserInitIterator *pIterator, TSysUserInitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysUserInit *pSysUserInit;
	int selected;
	CSysUserInitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysUserInit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysUserInit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysUserInit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysClientInitIterator *pIterator, TSysClientInitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientInit *pSysClientInit;
	
	while ((pSysClientInit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysClientInit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysClientInitIterator *pIterator, TSysClientInitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientInit *pSysClientInit;
	CWriteableSysClientInit theSysClientInit;
	bool updateIndex;
	CSysClientInitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientInit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysClientInit,&theSysClientInit);
		needContinue=updateFunc(&theSysClientInit, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysClientInit,&theSysClientInit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysClientInitIterator *pIterator, TSysClientInitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysClientInit *pSysClientInit;
	int selected;
	CSysClientInitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysClientInit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysClientInit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysClientInit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysTradeUserLoginInfo *pSysTradeUserLoginInfo;
	
	while ((pSysTradeUserLoginInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysTradeUserLoginInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysTradeUserLoginInfo *pSysTradeUserLoginInfo;
	CWriteableSysTradeUserLoginInfo theSysTradeUserLoginInfo;
	bool updateIndex;
	CSysTradeUserLoginInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysTradeUserLoginInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysTradeUserLoginInfo,&theSysTradeUserLoginInfo);
		needContinue=updateFunc(&theSysTradeUserLoginInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysTradeUserLoginInfo,&theSysTradeUserLoginInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysTradeUserLoginInfo *pSysTradeUserLoginInfo;
	int selected;
	CSysTradeUserLoginInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysTradeUserLoginInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysTradeUserLoginInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysTradeUserLoginInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbWebAppInfo *pSysMdbWebAppInfo;
	
	while ((pSysMdbWebAppInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbWebAppInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbWebAppInfo *pSysMdbWebAppInfo;
	CWriteableSysMdbWebAppInfo theSysMdbWebAppInfo;
	bool updateIndex;
	CSysMdbWebAppInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbWebAppInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbWebAppInfo,&theSysMdbWebAppInfo);
		needContinue=updateFunc(&theSysMdbWebAppInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbWebAppInfo,&theSysMdbWebAppInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbWebAppInfo *pSysMdbWebAppInfo;
	int selected;
	CSysMdbWebAppInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbWebAppInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbWebAppInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbWebAppInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbMemPoolInfo *pSysMdbMemPoolInfo;
	
	while ((pSysMdbMemPoolInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbMemPoolInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbMemPoolInfo *pSysMdbMemPoolInfo;
	CWriteableSysMdbMemPoolInfo theSysMdbMemPoolInfo;
	bool updateIndex;
	CSysMdbMemPoolInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbMemPoolInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbMemPoolInfo,&theSysMdbMemPoolInfo);
		needContinue=updateFunc(&theSysMdbMemPoolInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbMemPoolInfo,&theSysMdbMemPoolInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbMemPoolInfo *pSysMdbMemPoolInfo;
	int selected;
	CSysMdbMemPoolInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbMemPoolInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbMemPoolInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbMemPoolInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbConnectorInfo *pSysMdbConnectorInfo;
	
	while ((pSysMdbConnectorInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbConnectorInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbConnectorInfo *pSysMdbConnectorInfo;
	CWriteableSysMdbConnectorInfo theSysMdbConnectorInfo;
	bool updateIndex;
	CSysMdbConnectorInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbConnectorInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbConnectorInfo,&theSysMdbConnectorInfo);
		needContinue=updateFunc(&theSysMdbConnectorInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbConnectorInfo,&theSysMdbConnectorInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbConnectorInfo *pSysMdbConnectorInfo;
	int selected;
	CSysMdbConnectorInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbConnectorInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbConnectorInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbConnectorInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQueryActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbDBQuery *pSysMdbDBQuery;
	
	while ((pSysMdbDBQuery=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbDBQuery, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQueryUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbDBQuery *pSysMdbDBQuery;
	CWriteableSysMdbDBQuery theSysMdbDBQuery;
	bool updateIndex;
	CSysMdbDBQueryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbDBQuery=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbDBQuery,&theSysMdbDBQuery);
		needContinue=updateFunc(&theSysMdbDBQuery, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbDBQuery,&theSysMdbDBQuery,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQuerySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbDBQuery *pSysMdbDBQuery;
	int selected;
	CSysMdbDBQueryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbDBQuery=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbDBQuery, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbDBQuery,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetAreaIterator *pIterator, TSysNetAreaActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetArea *pSysNetArea;
	
	while ((pSysNetArea=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetArea, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetAreaIterator *pIterator, TSysNetAreaUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetArea *pSysNetArea;
	CWriteableSysNetArea theSysNetArea;
	bool updateIndex;
	CSysNetAreaFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetArea=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetArea,&theSysNetArea);
		needContinue=updateFunc(&theSysNetArea, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetArea,&theSysNetArea,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetAreaIterator *pIterator, TSysNetAreaSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetArea *pSysNetArea;
	int selected;
	CSysNetAreaFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetArea=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetArea, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetArea,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubArea *pSysNetSubArea;
	
	while ((pSysNetSubArea=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetSubArea, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubArea *pSysNetSubArea;
	CWriteableSysNetSubArea theSysNetSubArea;
	bool updateIndex;
	CSysNetSubAreaFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetSubArea=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetSubArea,&theSysNetSubArea);
		needContinue=updateFunc(&theSysNetSubArea, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetSubArea,&theSysNetSubArea,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubArea *pSysNetSubArea;
	int selected;
	CSysNetSubAreaFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetSubArea=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetSubArea, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetSubArea,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubAreaIP *pSysNetSubAreaIP;
	
	while ((pSysNetSubAreaIP=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetSubAreaIP, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubAreaIP *pSysNetSubAreaIP;
	CWriteableSysNetSubAreaIP theSysNetSubAreaIP;
	bool updateIndex;
	CSysNetSubAreaIPFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetSubAreaIP=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetSubAreaIP,&theSysNetSubAreaIP);
		needContinue=updateFunc(&theSysNetSubAreaIP, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetSubAreaIP,&theSysNetSubAreaIP,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubAreaIP *pSysNetSubAreaIP;
	int selected;
	CSysNetSubAreaIPFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetSubAreaIP=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetSubAreaIP, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetSubAreaIP,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetFuncArea *pSysNetFuncArea;
	
	while ((pSysNetFuncArea=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetFuncArea, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetFuncArea *pSysNetFuncArea;
	CWriteableSysNetFuncArea theSysNetFuncArea;
	bool updateIndex;
	CSysNetFuncAreaFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetFuncArea=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetFuncArea,&theSysNetFuncArea);
		needContinue=updateFunc(&theSysNetFuncArea, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetFuncArea,&theSysNetFuncArea,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetFuncArea *pSysNetFuncArea;
	int selected;
	CSysNetFuncAreaFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetFuncArea=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetFuncArea, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetFuncArea,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetDeviceIterator *pIterator, TSysNetDeviceActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDevice *pSysNetDevice;
	
	while ((pSysNetDevice=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetDevice, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetDeviceIterator *pIterator, TSysNetDeviceUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDevice *pSysNetDevice;
	CWriteableSysNetDevice theSysNetDevice;
	bool updateIndex;
	CSysNetDeviceFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDevice=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetDevice,&theSysNetDevice);
		needContinue=updateFunc(&theSysNetDevice, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetDevice,&theSysNetDevice,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetDeviceIterator *pIterator, TSysNetDeviceSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDevice *pSysNetDevice;
	int selected;
	CSysNetDeviceFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDevice=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetDevice, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetDevice,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceLinked *pSysNetDeviceLinked;
	
	while ((pSysNetDeviceLinked=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetDeviceLinked, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceLinked *pSysNetDeviceLinked;
	CWriteableSysNetDeviceLinked theSysNetDeviceLinked;
	bool updateIndex;
	CSysNetDeviceLinkedFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDeviceLinked=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetDeviceLinked,&theSysNetDeviceLinked);
		needContinue=updateFunc(&theSysNetDeviceLinked, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetDeviceLinked,&theSysNetDeviceLinked,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceLinked *pSysNetDeviceLinked;
	int selected;
	CSysNetDeviceLinkedFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDeviceLinked=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetDeviceLinked, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetDeviceLinked,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetOIDIterator *pIterator, TSysNetOIDActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetOID *pSysNetOID;
	
	while ((pSysNetOID=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetOID, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetOIDIterator *pIterator, TSysNetOIDUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetOID *pSysNetOID;
	CWriteableSysNetOID theSysNetOID;
	bool updateIndex;
	CSysNetOIDFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetOID=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetOID,&theSysNetOID);
		needContinue=updateFunc(&theSysNetOID, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetOID,&theSysNetOID,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetOIDIterator *pIterator, TSysNetOIDSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetOID *pSysNetOID;
	int selected;
	CSysNetOIDFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetOID=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetOID, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetOID,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceType *pSysNetDeviceType;
	
	while ((pSysNetDeviceType=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetDeviceType, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceType *pSysNetDeviceType;
	CWriteableSysNetDeviceType theSysNetDeviceType;
	bool updateIndex;
	CSysNetDeviceTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDeviceType=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetDeviceType,&theSysNetDeviceType);
		needContinue=updateFunc(&theSysNetDeviceType, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetDeviceType,&theSysNetDeviceType,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceType *pSysNetDeviceType;
	int selected;
	CSysNetDeviceTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDeviceType=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetDeviceType, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetDeviceType,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicyActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetTimePolicy *pSysNetTimePolicy;
	
	while ((pSysNetTimePolicy=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetTimePolicy, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicyUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetTimePolicy *pSysNetTimePolicy;
	CWriteableSysNetTimePolicy theSysNetTimePolicy;
	bool updateIndex;
	CSysNetTimePolicyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetTimePolicy=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetTimePolicy,&theSysNetTimePolicy);
		needContinue=updateFunc(&theSysNetTimePolicy, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetTimePolicy,&theSysNetTimePolicy,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetTimePolicy *pSysNetTimePolicy;
	int selected;
	CSysNetTimePolicyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetTimePolicy=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetTimePolicy, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetTimePolicy,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetGatherTask *pSysNetGatherTask;
	
	while ((pSysNetGatherTask=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetGatherTask, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetGatherTask *pSysNetGatherTask;
	CWriteableSysNetGatherTask theSysNetGatherTask;
	bool updateIndex;
	CSysNetGatherTaskFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetGatherTask=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetGatherTask,&theSysNetGatherTask);
		needContinue=updateFunc(&theSysNetGatherTask, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetGatherTask,&theSysNetGatherTask,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetGatherTask *pSysNetGatherTask;
	int selected;
	CSysNetGatherTaskFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetGatherTask=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetGatherTask, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetGatherTask,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategoryActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceCategory *pSysNetDeviceCategory;
	
	while ((pSysNetDeviceCategory=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetDeviceCategory, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategoryUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceCategory *pSysNetDeviceCategory;
	CWriteableSysNetDeviceCategory theSysNetDeviceCategory;
	bool updateIndex;
	CSysNetDeviceCategoryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDeviceCategory=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetDeviceCategory,&theSysNetDeviceCategory);
		needContinue=updateFunc(&theSysNetDeviceCategory, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetDeviceCategory,&theSysNetDeviceCategory,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategorySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDeviceCategory *pSysNetDeviceCategory;
	int selected;
	CSysNetDeviceCategoryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDeviceCategory=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetDeviceCategory, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetDeviceCategory,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetManufactoryIterator *pIterator, TSysNetManufactoryActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetManufactory *pSysNetManufactory;
	
	while ((pSysNetManufactory=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetManufactory, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetManufactoryIterator *pIterator, TSysNetManufactoryUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetManufactory *pSysNetManufactory;
	CWriteableSysNetManufactory theSysNetManufactory;
	bool updateIndex;
	CSysNetManufactoryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetManufactory=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetManufactory,&theSysNetManufactory);
		needContinue=updateFunc(&theSysNetManufactory, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetManufactory,&theSysNetManufactory,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetManufactoryIterator *pIterator, TSysNetManufactorySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetManufactory *pSysNetManufactory;
	int selected;
	CSysNetManufactoryFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetManufactory=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetManufactory, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetManufactory,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetCommunityIterator *pIterator, TSysNetCommunityActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetCommunity *pSysNetCommunity;
	
	while ((pSysNetCommunity=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetCommunity, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetCommunityIterator *pIterator, TSysNetCommunityUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetCommunity *pSysNetCommunity;
	CWriteableSysNetCommunity theSysNetCommunity;
	bool updateIndex;
	CSysNetCommunityFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetCommunity=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetCommunity,&theSysNetCommunity);
		needContinue=updateFunc(&theSysNetCommunity, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetCommunity,&theSysNetCommunity,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetCommunityIterator *pIterator, TSysNetCommunitySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetCommunity *pSysNetCommunity;
	int selected;
	CSysNetCommunityFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetCommunity=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetCommunity, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetCommunity,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPortType *pSysNetPortType;
	
	while ((pSysNetPortType=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetPortType, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPortType *pSysNetPortType;
	CWriteableSysNetPortType theSysNetPortType;
	bool updateIndex;
	CSysNetPortTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPortType=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetPortType,&theSysNetPortType);
		needContinue=updateFunc(&theSysNetPortType, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetPortType,&theSysNetPortType,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPortType *pSysNetPortType;
	int selected;
	CSysNetPortTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPortType=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetPortType, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetPortType,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetInterface *pSysNetInterface;
	
	while ((pSysNetInterface=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetInterface, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetInterface *pSysNetInterface;
	CWriteableSysNetInterface theSysNetInterface;
	bool updateIndex;
	CSysNetInterfaceFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetInterface=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetInterface,&theSysNetInterface);
		needContinue=updateFunc(&theSysNetInterface, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetInterface,&theSysNetInterface,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetInterface *pSysNetInterface;
	int selected;
	CSysNetInterfaceFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetInterface=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetInterface, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetInterface,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetGeneralOID *pSysNetGeneralOID;
	
	while ((pSysNetGeneralOID=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetGeneralOID, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetGeneralOID *pSysNetGeneralOID;
	CWriteableSysNetGeneralOID theSysNetGeneralOID;
	bool updateIndex;
	CSysNetGeneralOIDFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetGeneralOID=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetGeneralOID,&theSysNetGeneralOID);
		needContinue=updateFunc(&theSysNetGeneralOID, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetGeneralOID,&theSysNetGeneralOID,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetGeneralOID *pSysNetGeneralOID;
	int selected;
	CSysNetGeneralOIDFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetGeneralOID=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetGeneralOID, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetGeneralOID,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorType *pSysNetMonitorType;
	
	while ((pSysNetMonitorType=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorType, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorType *pSysNetMonitorType;
	CWriteableSysNetMonitorType theSysNetMonitorType;
	bool updateIndex;
	CSysNetMonitorTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorType=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorType,&theSysNetMonitorType);
		needContinue=updateFunc(&theSysNetMonitorType, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorType,&theSysNetMonitorType,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorType *pSysNetMonitorType;
	int selected;
	CSysNetMonitorTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorType=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorType, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorType,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorAttrScope *pSysNetMonitorAttrScope;
	
	while ((pSysNetMonitorAttrScope=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorAttrScope, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorAttrScope *pSysNetMonitorAttrScope;
	CWriteableSysNetMonitorAttrScope theSysNetMonitorAttrScope;
	bool updateIndex;
	CSysNetMonitorAttrScopeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorAttrScope=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorAttrScope,&theSysNetMonitorAttrScope);
		needContinue=updateFunc(&theSysNetMonitorAttrScope, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorAttrScope,&theSysNetMonitorAttrScope,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorAttrScope *pSysNetMonitorAttrScope;
	int selected;
	CSysNetMonitorAttrScopeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorAttrScope=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorAttrScope, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorAttrScope,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorAttrType *pSysNetMonitorAttrType;
	
	while ((pSysNetMonitorAttrType=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorAttrType, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorAttrType *pSysNetMonitorAttrType;
	CWriteableSysNetMonitorAttrType theSysNetMonitorAttrType;
	bool updateIndex;
	CSysNetMonitorAttrTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorAttrType=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorAttrType,&theSysNetMonitorAttrType);
		needContinue=updateFunc(&theSysNetMonitorAttrType, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorAttrType,&theSysNetMonitorAttrType,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorAttrType *pSysNetMonitorAttrType;
	int selected;
	CSysNetMonitorAttrTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorAttrType=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorAttrType, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorAttrType,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorCommandType *pSysNetMonitorCommandType;
	
	while ((pSysNetMonitorCommandType=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorCommandType, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorCommandType *pSysNetMonitorCommandType;
	CWriteableSysNetMonitorCommandType theSysNetMonitorCommandType;
	bool updateIndex;
	CSysNetMonitorCommandTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorCommandType=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorCommandType,&theSysNetMonitorCommandType);
		needContinue=updateFunc(&theSysNetMonitorCommandType, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorCommandType,&theSysNetMonitorCommandType,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorCommandType *pSysNetMonitorCommandType;
	int selected;
	CSysNetMonitorCommandTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorCommandType=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorCommandType, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorCommandType,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorActionGroup *pSysNetMonitorActionGroup;
	
	while ((pSysNetMonitorActionGroup=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorActionGroup, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorActionGroup *pSysNetMonitorActionGroup;
	CWriteableSysNetMonitorActionGroup theSysNetMonitorActionGroup;
	bool updateIndex;
	CSysNetMonitorActionGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorActionGroup=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorActionGroup,&theSysNetMonitorActionGroup);
		needContinue=updateFunc(&theSysNetMonitorActionGroup, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorActionGroup,&theSysNetMonitorActionGroup,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorActionGroup *pSysNetMonitorActionGroup;
	int selected;
	CSysNetMonitorActionGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorActionGroup=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorActionGroup, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorActionGroup,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup;
	
	while ((pSysNetMonitorDeviceGroup=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorDeviceGroup, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup;
	CWriteableSysNetMonitorDeviceGroup theSysNetMonitorDeviceGroup;
	bool updateIndex;
	CSysNetMonitorDeviceGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorDeviceGroup=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorDeviceGroup,&theSysNetMonitorDeviceGroup);
		needContinue=updateFunc(&theSysNetMonitorDeviceGroup, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorDeviceGroup,&theSysNetMonitorDeviceGroup,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup;
	int selected;
	CSysNetMonitorDeviceGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorDeviceGroup=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorDeviceGroup, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorDeviceGroup,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo;
	
	while ((pSysNetMonitorTaskInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorTaskInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo;
	CWriteableSysNetMonitorTaskInfo theSysNetMonitorTaskInfo;
	bool updateIndex;
	CSysNetMonitorTaskInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorTaskInfo,&theSysNetMonitorTaskInfo);
		needContinue=updateFunc(&theSysNetMonitorTaskInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorTaskInfo,&theSysNetMonitorTaskInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo;
	int selected;
	CSysNetMonitorTaskInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorTaskInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorTaskInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet;
	
	while ((pSysNetMonitorTaskObjectSet=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorTaskObjectSet, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet;
	CWriteableSysNetMonitorTaskObjectSet theSysNetMonitorTaskObjectSet;
	bool updateIndex;
	CSysNetMonitorTaskObjectSetFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskObjectSet=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorTaskObjectSet,&theSysNetMonitorTaskObjectSet);
		needContinue=updateFunc(&theSysNetMonitorTaskObjectSet, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorTaskObjectSet,&theSysNetMonitorTaskObjectSet,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet;
	int selected;
	CSysNetMonitorTaskObjectSetFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskObjectSet=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorTaskObjectSet, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorTaskObjectSet,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskResult *pSysNetMonitorTaskResult;
	
	while ((pSysNetMonitorTaskResult=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorTaskResult, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskResult *pSysNetMonitorTaskResult;
	CWriteableSysNetMonitorTaskResult theSysNetMonitorTaskResult;
	bool updateIndex;
	CSysNetMonitorTaskResultFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskResult=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorTaskResult,&theSysNetMonitorTaskResult);
		needContinue=updateFunc(&theSysNetMonitorTaskResult, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorTaskResult,&theSysNetMonitorTaskResult,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskResult *pSysNetMonitorTaskResult;
	int selected;
	CSysNetMonitorTaskResultFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskResult=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorTaskResult, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorTaskResult,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartyLinkInfo *pSysNetPartyLinkInfo;
	
	while ((pSysNetPartyLinkInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetPartyLinkInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartyLinkInfo *pSysNetPartyLinkInfo;
	CWriteableSysNetPartyLinkInfo theSysNetPartyLinkInfo;
	bool updateIndex;
	CSysNetPartyLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPartyLinkInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetPartyLinkInfo,&theSysNetPartyLinkInfo);
		needContinue=updateFunc(&theSysNetPartyLinkInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetPartyLinkInfo,&theSysNetPartyLinkInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartyLinkInfo *pSysNetPartyLinkInfo;
	int selected;
	CSysNetPartyLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPartyLinkInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetPartyLinkInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetPartyLinkInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo;
	
	while ((pSysNetDelPartyLinkInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetDelPartyLinkInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo;
	CWriteableSysNetDelPartyLinkInfo theSysNetDelPartyLinkInfo;
	bool updateIndex;
	CSysNetDelPartyLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDelPartyLinkInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetDelPartyLinkInfo,&theSysNetDelPartyLinkInfo);
		needContinue=updateFunc(&theSysNetDelPartyLinkInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetDelPartyLinkInfo,&theSysNetDelPartyLinkInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo;
	int selected;
	CSysNetDelPartyLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDelPartyLinkInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetDelPartyLinkInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetDelPartyLinkInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange;
	
	while ((pSysNetPartyLinkAddrChange=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetPartyLinkAddrChange, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange;
	CWriteableSysNetPartyLinkAddrChange theSysNetPartyLinkAddrChange;
	bool updateIndex;
	CSysNetPartyLinkAddrChangeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPartyLinkAddrChange=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetPartyLinkAddrChange,&theSysNetPartyLinkAddrChange);
		needContinue=updateFunc(&theSysNetPartyLinkAddrChange, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetPartyLinkAddrChange,&theSysNetPartyLinkAddrChange,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange;
	int selected;
	CSysNetPartyLinkAddrChangeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPartyLinkAddrChange=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetPartyLinkAddrChange, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetPartyLinkAddrChange,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorActionAttr *pSysNetMonitorActionAttr;
	
	while ((pSysNetMonitorActionAttr=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorActionAttr, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorActionAttr *pSysNetMonitorActionAttr;
	CWriteableSysNetMonitorActionAttr theSysNetMonitorActionAttr;
	bool updateIndex;
	CSysNetMonitorActionAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorActionAttr=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorActionAttr,&theSysNetMonitorActionAttr);
		needContinue=updateFunc(&theSysNetMonitorActionAttr, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorActionAttr,&theSysNetMonitorActionAttr,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorActionAttr *pSysNetMonitorActionAttr;
	int selected;
	CSysNetMonitorActionAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorActionAttr=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorActionAttr, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorActionAttr,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetModuleIterator *pIterator, TSysNetModuleActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetModule *pSysNetModule;
	
	while ((pSysNetModule=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetModule, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetModuleIterator *pIterator, TSysNetModuleUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetModule *pSysNetModule;
	CWriteableSysNetModule theSysNetModule;
	bool updateIndex;
	CSysNetModuleFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetModule=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetModule,&theSysNetModule);
		needContinue=updateFunc(&theSysNetModule, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetModule,&theSysNetModule,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetModuleIterator *pIterator, TSysNetModuleSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetModule *pSysNetModule;
	int selected;
	CSysNetModuleFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetModule=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetModule, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetModule,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetEventExprIterator *pIterator, TSysNetEventExprActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventExpr *pSysNetEventExpr;
	
	while ((pSysNetEventExpr=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetEventExpr, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetEventExprIterator *pIterator, TSysNetEventExprUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventExpr *pSysNetEventExpr;
	CWriteableSysNetEventExpr theSysNetEventExpr;
	bool updateIndex;
	CSysNetEventExprFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetEventExpr=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetEventExpr,&theSysNetEventExpr);
		needContinue=updateFunc(&theSysNetEventExpr, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetEventExpr,&theSysNetEventExpr,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetEventExprIterator *pIterator, TSysNetEventExprSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventExpr *pSysNetEventExpr;
	int selected;
	CSysNetEventExprFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetEventExpr=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetEventExpr, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetEventExpr,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventType *pSysNetEventType;
	
	while ((pSysNetEventType=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetEventType, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventType *pSysNetEventType;
	CWriteableSysNetEventType theSysNetEventType;
	bool updateIndex;
	CSysNetEventTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetEventType=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetEventType,&theSysNetEventType);
		needContinue=updateFunc(&theSysNetEventType, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetEventType,&theSysNetEventType,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventType *pSysNetEventType;
	int selected;
	CSysNetEventTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetEventType=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetEventType, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetEventType,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubEventType *pSysNetSubEventType;
	
	while ((pSysNetSubEventType=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetSubEventType, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubEventType *pSysNetSubEventType;
	CWriteableSysNetSubEventType theSysNetSubEventType;
	bool updateIndex;
	CSysNetSubEventTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetSubEventType=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetSubEventType,&theSysNetSubEventType);
		needContinue=updateFunc(&theSysNetSubEventType, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetSubEventType,&theSysNetSubEventType,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetSubEventType *pSysNetSubEventType;
	int selected;
	CSysNetSubEventTypeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetSubEventType=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetSubEventType, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetSubEventType,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventLevel *pSysNetEventLevel;
	
	while ((pSysNetEventLevel=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetEventLevel, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventLevel *pSysNetEventLevel;
	CWriteableSysNetEventLevel theSysNetEventLevel;
	bool updateIndex;
	CSysNetEventLevelFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetEventLevel=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetEventLevel,&theSysNetEventLevel);
		needContinue=updateFunc(&theSysNetEventLevel, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetEventLevel,&theSysNetEventLevel,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetEventLevel *pSysNetEventLevel;
	int selected;
	CSysNetEventLevelFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetEventLevel=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetEventLevel, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetEventLevel,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask;
	
	while ((pSysNetMonitorDeviceTask=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorDeviceTask, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask;
	CWriteableSysNetMonitorDeviceTask theSysNetMonitorDeviceTask;
	bool updateIndex;
	CSysNetMonitorDeviceTaskFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorDeviceTask=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorDeviceTask,&theSysNetMonitorDeviceTask);
		needContinue=updateFunc(&theSysNetMonitorDeviceTask, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorDeviceTask,&theSysNetMonitorDeviceTask,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask;
	int selected;
	CSysNetMonitorDeviceTaskFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorDeviceTask=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorDeviceTask, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorDeviceTask,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs;
	
	while ((pSysNetMonitorTaskInstAttrs=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMonitorTaskInstAttrs, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs;
	CWriteableSysNetMonitorTaskInstAttrs theSysNetMonitorTaskInstAttrs;
	bool updateIndex;
	CSysNetMonitorTaskInstAttrsFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskInstAttrs=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMonitorTaskInstAttrs,&theSysNetMonitorTaskInstAttrs);
		needContinue=updateFunc(&theSysNetMonitorTaskInstAttrs, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMonitorTaskInstAttrs,&theSysNetMonitorTaskInstAttrs,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs;
	int selected;
	CSysNetMonitorTaskInstAttrsFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMonitorTaskInstAttrs=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMonitorTaskInstAttrs, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMonitorTaskInstAttrs,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetBaseLine *pSysNetBaseLine;
	
	while ((pSysNetBaseLine=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetBaseLine, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetBaseLine *pSysNetBaseLine;
	CWriteableSysNetBaseLine theSysNetBaseLine;
	bool updateIndex;
	CSysNetBaseLineFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetBaseLine=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetBaseLine,&theSysNetBaseLine);
		needContinue=updateFunc(&theSysNetBaseLine, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetBaseLine,&theSysNetBaseLine,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetBaseLine *pSysNetBaseLine;
	int selected;
	CSysNetBaseLineFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetBaseLine=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetBaseLine, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetBaseLine,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetBaseLineTask *pSysNetBaseLineTask;
	
	while ((pSysNetBaseLineTask=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetBaseLineTask, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetBaseLineTask *pSysNetBaseLineTask;
	CWriteableSysNetBaseLineTask theSysNetBaseLineTask;
	bool updateIndex;
	CSysNetBaseLineTaskFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetBaseLineTask=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetBaseLineTask,&theSysNetBaseLineTask);
		needContinue=updateFunc(&theSysNetBaseLineTask, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetBaseLineTask,&theSysNetBaseLineTask,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetBaseLineTask *pSysNetBaseLineTask;
	int selected;
	CSysNetBaseLineTaskFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetBaseLineTask=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetBaseLineTask, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetBaseLineTask,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo;
	
	while ((pSysMdbNetPartyLinkStatusInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbNetPartyLinkStatusInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo;
	CWriteableSysMdbNetPartyLinkStatusInfo theSysMdbNetPartyLinkStatusInfo;
	bool updateIndex;
	CSysMdbNetPartyLinkStatusInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbNetPartyLinkStatusInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbNetPartyLinkStatusInfo,&theSysMdbNetPartyLinkStatusInfo);
		needContinue=updateFunc(&theSysMdbNetPartyLinkStatusInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbNetPartyLinkStatusInfo,&theSysMdbNetPartyLinkStatusInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo;
	int selected;
	CSysMdbNetPartyLinkStatusInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbNetPartyLinkStatusInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbNetPartyLinkStatusInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbNetPartyLinkStatusInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo;
	
	while ((pSysNetMemberSDHLineInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetMemberSDHLineInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo;
	CWriteableSysNetMemberSDHLineInfo theSysNetMemberSDHLineInfo;
	bool updateIndex;
	CSysNetMemberSDHLineInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMemberSDHLineInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetMemberSDHLineInfo,&theSysNetMemberSDHLineInfo);
		needContinue=updateFunc(&theSysNetMemberSDHLineInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetMemberSDHLineInfo,&theSysNetMemberSDHLineInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo;
	int selected;
	CSysNetMemberSDHLineInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetMemberSDHLineInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetMemberSDHLineInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetMemberSDHLineInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDDNLinkInfo *pSysNetDDNLinkInfo;
	
	while ((pSysNetDDNLinkInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetDDNLinkInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDDNLinkInfo *pSysNetDDNLinkInfo;
	CWriteableSysNetDDNLinkInfo theSysNetDDNLinkInfo;
	bool updateIndex;
	CSysNetDDNLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDDNLinkInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetDDNLinkInfo,&theSysNetDDNLinkInfo);
		needContinue=updateFunc(&theSysNetDDNLinkInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetDDNLinkInfo,&theSysNetDDNLinkInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetDDNLinkInfo *pSysNetDDNLinkInfo;
	int selected;
	CSysNetDDNLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetDDNLinkInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetDDNLinkInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetDDNLinkInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo;
	
	while ((pSysNetPseudMemberLinkInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetPseudMemberLinkInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo;
	CWriteableSysNetPseudMemberLinkInfo theSysNetPseudMemberLinkInfo;
	bool updateIndex;
	CSysNetPseudMemberLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPseudMemberLinkInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetPseudMemberLinkInfo,&theSysNetPseudMemberLinkInfo);
		needContinue=updateFunc(&theSysNetPseudMemberLinkInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetPseudMemberLinkInfo,&theSysNetPseudMemberLinkInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo;
	int selected;
	CSysNetPseudMemberLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPseudMemberLinkInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetPseudMemberLinkInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetPseudMemberLinkInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo;
	
	while ((pSysNetOuterDeviceInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetOuterDeviceInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo;
	CWriteableSysNetOuterDeviceInfo theSysNetOuterDeviceInfo;
	bool updateIndex;
	CSysNetOuterDeviceInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetOuterDeviceInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetOuterDeviceInfo,&theSysNetOuterDeviceInfo);
		needContinue=updateFunc(&theSysNetOuterDeviceInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetOuterDeviceInfo,&theSysNetOuterDeviceInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo;
	int selected;
	CSysNetOuterDeviceInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetOuterDeviceInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetOuterDeviceInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetOuterDeviceInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysLocalPingResultInfo *pSysLocalPingResultInfo;
	
	while ((pSysLocalPingResultInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysLocalPingResultInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysLocalPingResultInfo *pSysLocalPingResultInfo;
	CWriteableSysLocalPingResultInfo theSysLocalPingResultInfo;
	bool updateIndex;
	CSysLocalPingResultInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysLocalPingResultInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysLocalPingResultInfo,&theSysLocalPingResultInfo);
		needContinue=updateFunc(&theSysLocalPingResultInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysLocalPingResultInfo,&theSysLocalPingResultInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysLocalPingResultInfo *pSysLocalPingResultInfo;
	int selected;
	CSysLocalPingResultInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysLocalPingResultInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysLocalPingResultInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysLocalPingResultInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysRomotePingResultInfo *pSysRomotePingResultInfo;
	
	while ((pSysRomotePingResultInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysRomotePingResultInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysRomotePingResultInfo *pSysRomotePingResultInfo;
	CWriteableSysRomotePingResultInfo theSysRomotePingResultInfo;
	bool updateIndex;
	CSysRomotePingResultInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysRomotePingResultInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysRomotePingResultInfo,&theSysRomotePingResultInfo);
		needContinue=updateFunc(&theSysRomotePingResultInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysRomotePingResultInfo,&theSysRomotePingResultInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysRomotePingResultInfo *pSysRomotePingResultInfo;
	int selected;
	CSysRomotePingResultInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysRomotePingResultInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysRomotePingResultInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysRomotePingResultInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticTradeOrderStates *pSysParticTradeOrderStates;
	
	while ((pSysParticTradeOrderStates=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysParticTradeOrderStates, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticTradeOrderStates *pSysParticTradeOrderStates;
	CWriteableSysParticTradeOrderStates theSysParticTradeOrderStates;
	bool updateIndex;
	CSysParticTradeOrderStatesFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysParticTradeOrderStates=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysParticTradeOrderStates,&theSysParticTradeOrderStates);
		needContinue=updateFunc(&theSysParticTradeOrderStates, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysParticTradeOrderStates,&theSysParticTradeOrderStates,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysParticTradeOrderStates *pSysParticTradeOrderStates;
	int selected;
	CSysParticTradeOrderStatesFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysParticTradeOrderStates=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysParticTradeOrderStates, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysParticTradeOrderStates,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbRouterInfo *pSysMdbRouterInfo;
	
	while ((pSysMdbRouterInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbRouterInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbRouterInfo *pSysMdbRouterInfo;
	CWriteableSysMdbRouterInfo theSysMdbRouterInfo;
	bool updateIndex;
	CSysMdbRouterInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbRouterInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbRouterInfo,&theSysMdbRouterInfo);
		needContinue=updateFunc(&theSysMdbRouterInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbRouterInfo,&theSysMdbRouterInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbRouterInfo *pSysMdbRouterInfo;
	int selected;
	CSysMdbRouterInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbRouterInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbRouterInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbRouterInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbDiskIO *pSysMdbDiskIO;
	
	while ((pSysMdbDiskIO=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbDiskIO, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbDiskIO *pSysMdbDiskIO;
	CWriteableSysMdbDiskIO theSysMdbDiskIO;
	bool updateIndex;
	CSysMdbDiskIOFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbDiskIO=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbDiskIO,&theSysMdbDiskIO);
		needContinue=updateFunc(&theSysMdbDiskIO, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbDiskIO,&theSysMdbDiskIO,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbDiskIO *pSysMdbDiskIO;
	int selected;
	CSysMdbDiskIOFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbDiskIO=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbDiskIO, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbDiskIO,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbStatInfo *pSysMdbStatInfo;
	
	while ((pSysMdbStatInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbStatInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbStatInfo *pSysMdbStatInfo;
	CWriteableSysMdbStatInfo theSysMdbStatInfo;
	bool updateIndex;
	CSysMdbStatInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbStatInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbStatInfo,&theSysMdbStatInfo);
		needContinue=updateFunc(&theSysMdbStatInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbStatInfo,&theSysMdbStatInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbStatInfo *pSysMdbStatInfo;
	int selected;
	CSysMdbStatInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbStatInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbStatInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbStatInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat;
	
	while ((pSysMdbTradeFrontOrderRttStat=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMdbTradeFrontOrderRttStat, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat;
	CWriteableSysMdbTradeFrontOrderRttStat theSysMdbTradeFrontOrderRttStat;
	bool updateIndex;
	CSysMdbTradeFrontOrderRttStatFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTradeFrontOrderRttStat=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMdbTradeFrontOrderRttStat,&theSysMdbTradeFrontOrderRttStat);
		needContinue=updateFunc(&theSysMdbTradeFrontOrderRttStat, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMdbTradeFrontOrderRttStat,&theSysMdbTradeFrontOrderRttStat,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat;
	int selected;
	CSysMdbTradeFrontOrderRttStatFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMdbTradeFrontOrderRttStat=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMdbTradeFrontOrderRttStat, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMdbTradeFrontOrderRttStat,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInstrumentStatus *pSysInstrumentStatus;
	
	while ((pSysInstrumentStatus=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysInstrumentStatus, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInstrumentStatus *pSysInstrumentStatus;
	CWriteableSysInstrumentStatus theSysInstrumentStatus;
	bool updateIndex;
	CSysInstrumentStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysInstrumentStatus=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysInstrumentStatus,&theSysInstrumentStatus);
		needContinue=updateFunc(&theSysInstrumentStatus, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysInstrumentStatus,&theSysInstrumentStatus,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysInstrumentStatus *pSysInstrumentStatus;
	int selected;
	CSysInstrumentStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysInstrumentStatus=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysInstrumentStatus, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysInstrumentStatus,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr;
	
	while ((pSysCurrTradingSegmentAttr=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysCurrTradingSegmentAttr, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr;
	CWriteableSysCurrTradingSegmentAttr theSysCurrTradingSegmentAttr;
	bool updateIndex;
	CSysCurrTradingSegmentAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysCurrTradingSegmentAttr=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysCurrTradingSegmentAttr,&theSysCurrTradingSegmentAttr);
		needContinue=updateFunc(&theSysCurrTradingSegmentAttr, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysCurrTradingSegmentAttr,&theSysCurrTradingSegmentAttr,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr;
	int selected;
	CSysCurrTradingSegmentAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysCurrTradingSegmentAttr=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysCurrTradingSegmentAttr, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysCurrTradingSegmentAttr,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMemberLinkCost *pSysMemberLinkCost;
	
	while ((pSysMemberLinkCost=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysMemberLinkCost, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMemberLinkCost *pSysMemberLinkCost;
	CWriteableSysMemberLinkCost theSysMemberLinkCost;
	bool updateIndex;
	CSysMemberLinkCostFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMemberLinkCost=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysMemberLinkCost,&theSysMemberLinkCost);
		needContinue=updateFunc(&theSysMemberLinkCost, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysMemberLinkCost,&theSysMemberLinkCost,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysMemberLinkCost *pSysMemberLinkCost;
	int selected;
	CSysMemberLinkCostFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysMemberLinkCost=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysMemberLinkCost, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysMemberLinkCost,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent;
	
	while ((pSysNetPartylinkMonthlyRent=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetPartylinkMonthlyRent, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent;
	CWriteableSysNetPartylinkMonthlyRent theSysNetPartylinkMonthlyRent;
	bool updateIndex;
	CSysNetPartylinkMonthlyRentFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPartylinkMonthlyRent=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetPartylinkMonthlyRent,&theSysNetPartylinkMonthlyRent);
		needContinue=updateFunc(&theSysNetPartylinkMonthlyRent, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetPartylinkMonthlyRent,&theSysNetPartylinkMonthlyRent,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent;
	int selected;
	CSysNetPartylinkMonthlyRentFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetPartylinkMonthlyRent=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetPartylinkMonthlyRent, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetPartylinkMonthlyRent,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo;
	
	while ((pSysNetNonPartyLinkInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSysNetNonPartyLinkInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo;
	CWriteableSysNetNonPartyLinkInfo theSysNetNonPartyLinkInfo;
	bool updateIndex;
	CSysNetNonPartyLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetNonPartyLinkInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSysNetNonPartyLinkInfo,&theSysNetNonPartyLinkInfo);
		needContinue=updateFunc(&theSysNetNonPartyLinkInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pSysNetNonPartyLinkInfo,&theSysNetNonPartyLinkInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo;
	int selected;
	CSysNetNonPartyLinkInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSysNetNonPartyLinkInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSysNetNonPartyLinkInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSysNetNonPartyLinkInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

