/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseGroupActions.cpp
///@brief实现了若干个内存数据库的群组操作
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "databaseGroupActions.h"

void groupAction(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExchangeDataSyncStatus *pExchangeDataSyncStatus;
	
	while ((pExchangeDataSyncStatus=pIterator->next())!=NULL)
	{
		if (!actionFunc(pExchangeDataSyncStatus, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExchangeDataSyncStatus *pExchangeDataSyncStatus;
	CWriteableExchangeDataSyncStatus theExchangeDataSyncStatus;
	bool updateIndex;
	CExchangeDataSyncStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pExchangeDataSyncStatus=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pExchangeDataSyncStatus,&theExchangeDataSyncStatus);
		needContinue=updateFunc(&theExchangeDataSyncStatus, pTransaction, parameter, &updateIndex);
		pFactory->update(pExchangeDataSyncStatus,&theExchangeDataSyncStatus,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExchangeDataSyncStatus *pExchangeDataSyncStatus;
	int selected;
	CExchangeDataSyncStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pExchangeDataSyncStatus=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pExchangeDataSyncStatus, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pExchangeDataSyncStatus,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSGDataSyncStatus *pSGDataSyncStatus;
	
	while ((pSGDataSyncStatus=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSGDataSyncStatus, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSGDataSyncStatus *pSGDataSyncStatus;
	CWriteableSGDataSyncStatus theSGDataSyncStatus;
	bool updateIndex;
	CSGDataSyncStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSGDataSyncStatus=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSGDataSyncStatus,&theSGDataSyncStatus);
		needContinue=updateFunc(&theSGDataSyncStatus, pTransaction, parameter, &updateIndex);
		pFactory->update(pSGDataSyncStatus,&theSGDataSyncStatus,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSGDataSyncStatus *pSGDataSyncStatus;
	int selected;
	CSGDataSyncStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSGDataSyncStatus=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSGDataSyncStatus, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSGDataSyncStatus,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrentTimeIterator *pIterator, TCurrentTimeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrentTime *pCurrentTime;
	
	while ((pCurrentTime=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrentTime, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrentTimeIterator *pIterator, TCurrentTimeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrentTime *pCurrentTime;
	CWriteableCurrentTime theCurrentTime;
	bool updateIndex;
	CCurrentTimeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrentTime=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrentTime,&theCurrentTime);
		needContinue=updateFunc(&theCurrentTime, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrentTime,&theCurrentTime,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrentTimeIterator *pIterator, TCurrentTimeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrentTime *pCurrentTime;
	int selected;
	CCurrentTimeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrentTime=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrentTime, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrentTime,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CDataCenterDescIterator *pIterator, TDataCenterDescActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDataCenterDesc *pDataCenterDesc;
	
	while ((pDataCenterDesc=pIterator->next())!=NULL)
	{
		if (!actionFunc(pDataCenterDesc, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CDataCenterDescIterator *pIterator, TDataCenterDescUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDataCenterDesc *pDataCenterDesc;
	CWriteableDataCenterDesc theDataCenterDesc;
	bool updateIndex;
	CDataCenterDescFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pDataCenterDesc=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pDataCenterDesc,&theDataCenterDesc);
		needContinue=updateFunc(&theDataCenterDesc, pTransaction, parameter, &updateIndex);
		pFactory->update(pDataCenterDesc,&theDataCenterDesc,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CDataCenterDescIterator *pIterator, TDataCenterDescSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDataCenterDesc *pDataCenterDesc;
	int selected;
	CDataCenterDescFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pDataCenterDesc=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pDataCenterDesc, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pDataCenterDesc,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CExchangeIterator *pIterator, TExchangeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExchange *pExchange;
	
	while ((pExchange=pIterator->next())!=NULL)
	{
		if (!actionFunc(pExchange, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CExchangeIterator *pIterator, TExchangeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExchange *pExchange;
	CWriteableExchange theExchange;
	bool updateIndex;
	CExchangeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pExchange=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pExchange,&theExchange);
		needContinue=updateFunc(&theExchange, pTransaction, parameter, &updateIndex);
		pFactory->update(pExchange,&theExchange,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CExchangeIterator *pIterator, TExchangeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExchange *pExchange;
	int selected;
	CExchangeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pExchange=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pExchange, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pExchange,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CSettlementGroupIterator *pIterator, TSettlementGroupActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSettlementGroup *pSettlementGroup;
	
	while ((pSettlementGroup=pIterator->next())!=NULL)
	{
		if (!actionFunc(pSettlementGroup, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CSettlementGroupIterator *pIterator, TSettlementGroupUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSettlementGroup *pSettlementGroup;
	CWriteableSettlementGroup theSettlementGroup;
	bool updateIndex;
	CSettlementGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSettlementGroup=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pSettlementGroup,&theSettlementGroup);
		needContinue=updateFunc(&theSettlementGroup, pTransaction, parameter, &updateIndex);
		pFactory->update(pSettlementGroup,&theSettlementGroup,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CSettlementGroupIterator *pIterator, TSettlementGroupSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CSettlementGroup *pSettlementGroup;
	int selected;
	CSettlementGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pSettlementGroup=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pSettlementGroup, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pSettlementGroup,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMarketIterator *pIterator, TMarketActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarket *pMarket;
	
	while ((pMarket=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMarket, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMarketIterator *pIterator, TMarketUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarket *pMarket;
	CWriteableMarket theMarket;
	bool updateIndex;
	CMarketFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarket=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMarket,&theMarket);
		needContinue=updateFunc(&theMarket, pTransaction, parameter, &updateIndex);
		pFactory->update(pMarket,&theMarket,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMarketIterator *pIterator, TMarketSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarket *pMarket;
	int selected;
	CMarketFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarket=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMarket, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMarket,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMarketProductIterator *pIterator, TMarketProductActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketProduct *pMarketProduct;
	
	while ((pMarketProduct=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMarketProduct, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMarketProductIterator *pIterator, TMarketProductUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketProduct *pMarketProduct;
	CWriteableMarketProduct theMarketProduct;
	bool updateIndex;
	CMarketProductFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketProduct=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMarketProduct,&theMarketProduct);
		needContinue=updateFunc(&theMarketProduct, pTransaction, parameter, &updateIndex);
		pFactory->update(pMarketProduct,&theMarketProduct,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMarketProductIterator *pIterator, TMarketProductSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketProduct *pMarketProduct;
	int selected;
	CMarketProductFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketProduct=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMarketProduct, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMarketProduct,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMarketProductGroupIterator *pIterator, TMarketProductGroupActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketProductGroup *pMarketProductGroup;
	
	while ((pMarketProductGroup=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMarketProductGroup, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMarketProductGroupIterator *pIterator, TMarketProductGroupUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketProductGroup *pMarketProductGroup;
	CWriteableMarketProductGroup theMarketProductGroup;
	bool updateIndex;
	CMarketProductGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketProductGroup=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMarketProductGroup,&theMarketProductGroup);
		needContinue=updateFunc(&theMarketProductGroup, pTransaction, parameter, &updateIndex);
		pFactory->update(pMarketProductGroup,&theMarketProductGroup,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMarketProductGroupIterator *pIterator, TMarketProductGroupSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketProductGroup *pMarketProductGroup;
	int selected;
	CMarketProductGroupFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketProductGroup=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMarketProductGroup, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMarketProductGroup,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMdPubStatusIterator *pIterator, TMdPubStatusActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMdPubStatus *pMdPubStatus;
	
	while ((pMdPubStatus=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMdPubStatus, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMdPubStatusIterator *pIterator, TMdPubStatusUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMdPubStatus *pMdPubStatus;
	CWriteableMdPubStatus theMdPubStatus;
	bool updateIndex;
	CMdPubStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMdPubStatus=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMdPubStatus,&theMdPubStatus);
		needContinue=updateFunc(&theMdPubStatus, pTransaction, parameter, &updateIndex);
		pFactory->update(pMdPubStatus,&theMdPubStatus,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMdPubStatusIterator *pIterator, TMdPubStatusSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMdPubStatus *pMdPubStatus;
	int selected;
	CMdPubStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMdPubStatus=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMdPubStatus, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMdPubStatus,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMarketDataTopicIterator *pIterator, TMarketDataTopicActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataTopic *pMarketDataTopic;
	
	while ((pMarketDataTopic=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMarketDataTopic, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMarketDataTopicIterator *pIterator, TMarketDataTopicUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataTopic *pMarketDataTopic;
	CWriteableMarketDataTopic theMarketDataTopic;
	bool updateIndex;
	CMarketDataTopicFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketDataTopic=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMarketDataTopic,&theMarketDataTopic);
		needContinue=updateFunc(&theMarketDataTopic, pTransaction, parameter, &updateIndex);
		pFactory->update(pMarketDataTopic,&theMarketDataTopic,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMarketDataTopicIterator *pIterator, TMarketDataTopicSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataTopic *pMarketDataTopic;
	int selected;
	CMarketDataTopicFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketDataTopic=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMarketDataTopic, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMarketDataTopic,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartTopicSubscribe *pPartTopicSubscribe;
	
	while ((pPartTopicSubscribe=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartTopicSubscribe, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartTopicSubscribe *pPartTopicSubscribe;
	CWriteablePartTopicSubscribe thePartTopicSubscribe;
	bool updateIndex;
	CPartTopicSubscribeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartTopicSubscribe=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartTopicSubscribe,&thePartTopicSubscribe);
		needContinue=updateFunc(&thePartTopicSubscribe, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartTopicSubscribe,&thePartTopicSubscribe,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartTopicSubscribe *pPartTopicSubscribe;
	int selected;
	CPartTopicSubscribeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartTopicSubscribe=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartTopicSubscribe, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartTopicSubscribe,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CParticipantIterator *pIterator, TParticipantActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CParticipant *pParticipant;
	
	while ((pParticipant=pIterator->next())!=NULL)
	{
		if (!actionFunc(pParticipant, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CParticipantIterator *pIterator, TParticipantUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CParticipant *pParticipant;
	CWriteableParticipant theParticipant;
	bool updateIndex;
	CParticipantFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pParticipant=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pParticipant,&theParticipant);
		needContinue=updateFunc(&theParticipant, pTransaction, parameter, &updateIndex);
		pFactory->update(pParticipant,&theParticipant,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CParticipantIterator *pIterator, TParticipantSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CParticipant *pParticipant;
	int selected;
	CParticipantFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pParticipant=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pParticipant, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pParticipant,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CUserIterator *pIterator, TUserActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUser *pUser;
	
	while ((pUser=pIterator->next())!=NULL)
	{
		if (!actionFunc(pUser, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CUserIterator *pIterator, TUserUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUser *pUser;
	CWriteableUser theUser;
	bool updateIndex;
	CUserFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUser=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pUser,&theUser);
		needContinue=updateFunc(&theUser, pTransaction, parameter, &updateIndex);
		pFactory->update(pUser,&theUser,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CUserIterator *pIterator, TUserSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUser *pUser;
	int selected;
	CUserFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUser=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pUser, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pUser,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CClientIterator *pIterator, TClientActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClient *pClient;
	
	while ((pClient=pIterator->next())!=NULL)
	{
		if (!actionFunc(pClient, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CClientIterator *pIterator, TClientUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClient *pClient;
	CWriteableClient theClient;
	bool updateIndex;
	CClientFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClient=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pClient,&theClient);
		needContinue=updateFunc(&theClient, pTransaction, parameter, &updateIndex);
		pFactory->update(pClient,&theClient,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CClientIterator *pIterator, TClientSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClient *pClient;
	int selected;
	CClientFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClient=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pClient, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pClient,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CUserIPIterator *pIterator, TUserIPActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserIP *pUserIP;
	
	while ((pUserIP=pIterator->next())!=NULL)
	{
		if (!actionFunc(pUserIP, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CUserIPIterator *pIterator, TUserIPUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserIP *pUserIP;
	CWriteableUserIP theUserIP;
	bool updateIndex;
	CUserIPFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserIP=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pUserIP,&theUserIP);
		needContinue=updateFunc(&theUserIP, pTransaction, parameter, &updateIndex);
		pFactory->update(pUserIP,&theUserIP,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CUserIPIterator *pIterator, TUserIPSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserIP *pUserIP;
	int selected;
	CUserIPFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserIP=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pUserIP, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pUserIP,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartClientIterator *pIterator, TPartClientActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClient *pPartClient;
	
	while ((pPartClient=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartClient, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartClientIterator *pIterator, TPartClientUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClient *pPartClient;
	CWriteablePartClient thePartClient;
	bool updateIndex;
	CPartClientFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartClient=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartClient,&thePartClient);
		needContinue=updateFunc(&thePartClient, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartClient,&thePartClient,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartClientIterator *pIterator, TPartClientSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClient *pPartClient;
	int selected;
	CPartClientFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartClient=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartClient, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartClient,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CClearingTradingPartIterator *pIterator, TClearingTradingPartActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClearingTradingPart *pClearingTradingPart;
	
	while ((pClearingTradingPart=pIterator->next())!=NULL)
	{
		if (!actionFunc(pClearingTradingPart, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CClearingTradingPartIterator *pIterator, TClearingTradingPartUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClearingTradingPart *pClearingTradingPart;
	CWriteableClearingTradingPart theClearingTradingPart;
	bool updateIndex;
	CClearingTradingPartFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClearingTradingPart=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pClearingTradingPart,&theClearingTradingPart);
		needContinue=updateFunc(&theClearingTradingPart, pTransaction, parameter, &updateIndex);
		pFactory->update(pClearingTradingPart,&theClearingTradingPart,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CClearingTradingPartIterator *pIterator, TClearingTradingPartSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClearingTradingPart *pClearingTradingPart;
	int selected;
	CClearingTradingPartFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClearingTradingPart=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pClearingTradingPart, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pClearingTradingPart,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CAliasDefineIterator *pIterator, TAliasDefineActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CAliasDefine *pAliasDefine;
	
	while ((pAliasDefine=pIterator->next())!=NULL)
	{
		if (!actionFunc(pAliasDefine, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CAliasDefineIterator *pIterator, TAliasDefineUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CAliasDefine *pAliasDefine;
	CWriteableAliasDefine theAliasDefine;
	bool updateIndex;
	CAliasDefineFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pAliasDefine=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pAliasDefine,&theAliasDefine);
		needContinue=updateFunc(&theAliasDefine, pTransaction, parameter, &updateIndex);
		pFactory->update(pAliasDefine,&theAliasDefine,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CAliasDefineIterator *pIterator, TAliasDefineSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CAliasDefine *pAliasDefine;
	int selected;
	CAliasDefineFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pAliasDefine=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pAliasDefine, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pAliasDefine,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CUserFunctionRightIterator *pIterator, TUserFunctionRightActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserFunctionRight *pUserFunctionRight;
	
	while ((pUserFunctionRight=pIterator->next())!=NULL)
	{
		if (!actionFunc(pUserFunctionRight, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CUserFunctionRightIterator *pIterator, TUserFunctionRightUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserFunctionRight *pUserFunctionRight;
	CWriteableUserFunctionRight theUserFunctionRight;
	bool updateIndex;
	CUserFunctionRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserFunctionRight=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pUserFunctionRight,&theUserFunctionRight);
		needContinue=updateFunc(&theUserFunctionRight, pTransaction, parameter, &updateIndex);
		pFactory->update(pUserFunctionRight,&theUserFunctionRight,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CUserFunctionRightIterator *pIterator, TUserFunctionRightSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserFunctionRight *pUserFunctionRight;
	int selected;
	CUserFunctionRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserFunctionRight=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pUserFunctionRight, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pUserFunctionRight,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CAccountIterator *pIterator, TAccountActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CAccount *pAccount;
	
	while ((pAccount=pIterator->next())!=NULL)
	{
		if (!actionFunc(pAccount, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CAccountIterator *pIterator, TAccountUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CAccount *pAccount;
	CWriteableAccount theAccount;
	bool updateIndex;
	CAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pAccount=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pAccount,&theAccount);
		needContinue=updateFunc(&theAccount, pTransaction, parameter, &updateIndex);
		pFactory->update(pAccount,&theAccount,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CAccountIterator *pIterator, TAccountSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CAccount *pAccount;
	int selected;
	CAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pAccount=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pAccount, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pAccount,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CUserCommFluxIterator *pIterator, TUserCommFluxActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserCommFlux *pUserCommFlux;
	
	while ((pUserCommFlux=pIterator->next())!=NULL)
	{
		if (!actionFunc(pUserCommFlux, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CUserCommFluxIterator *pIterator, TUserCommFluxUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserCommFlux *pUserCommFlux;
	CWriteableUserCommFlux theUserCommFlux;
	bool updateIndex;
	CUserCommFluxFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserCommFlux=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pUserCommFlux,&theUserCommFlux);
		needContinue=updateFunc(&theUserCommFlux, pTransaction, parameter, &updateIndex);
		pFactory->update(pUserCommFlux,&theUserCommFlux,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CUserCommFluxIterator *pIterator, TUserCommFluxSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserCommFlux *pUserCommFlux;
	int selected;
	CUserCommFluxFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserCommFlux=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pUserCommFlux, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pUserCommFlux,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMarketDataLogIterator *pIterator, TMarketDataLogActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataLog *pMarketDataLog;
	
	while ((pMarketDataLog=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMarketDataLog, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMarketDataLogIterator *pIterator, TMarketDataLogUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataLog *pMarketDataLog;
	CWriteableMarketDataLog theMarketDataLog;
	bool updateIndex;
	CMarketDataLogFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketDataLog=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMarketDataLog,&theMarketDataLog);
		needContinue=updateFunc(&theMarketDataLog, pTransaction, parameter, &updateIndex);
		pFactory->update(pMarketDataLog,&theMarketDataLog,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMarketDataLogIterator *pIterator, TMarketDataLogSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataLog *pMarketDataLog;
	int selected;
	CMarketDataLogFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketDataLog=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMarketDataLog, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMarketDataLog,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CUserSessionIterator *pIterator, TUserSessionActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserSession *pUserSession;
	
	while ((pUserSession=pIterator->next())!=NULL)
	{
		if (!actionFunc(pUserSession, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CUserSessionIterator *pIterator, TUserSessionUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserSession *pUserSession;
	CWriteableUserSession theUserSession;
	bool updateIndex;
	CUserSessionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserSession=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pUserSession,&theUserSession);
		needContinue=updateFunc(&theUserSession, pTransaction, parameter, &updateIndex);
		pFactory->update(pUserSession,&theUserSession,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CUserSessionIterator *pIterator, TUserSessionSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUserSession *pUserSession;
	int selected;
	CUserSessionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUserSession=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pUserSession, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pUserSession,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMDSessionIterator *pIterator, TMDSessionActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMDSession *pMDSession;
	
	while ((pMDSession=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMDSession, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMDSessionIterator *pIterator, TMDSessionUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMDSession *pMDSession;
	CWriteableMDSession theMDSession;
	bool updateIndex;
	CMDSessionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMDSession=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMDSession,&theMDSession);
		needContinue=updateFunc(&theMDSession, pTransaction, parameter, &updateIndex);
		pFactory->update(pMDSession,&theMDSession,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMDSessionIterator *pIterator, TMDSessionSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMDSession *pMDSession;
	int selected;
	CMDSessionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMDSession=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMDSession, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMDSession,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CLoginInfoIterator *pIterator, TLoginInfoActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CLoginInfo *pLoginInfo;
	
	while ((pLoginInfo=pIterator->next())!=NULL)
	{
		if (!actionFunc(pLoginInfo, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CLoginInfoIterator *pIterator, TLoginInfoUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CLoginInfo *pLoginInfo;
	CWriteableLoginInfo theLoginInfo;
	bool updateIndex;
	CLoginInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pLoginInfo=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pLoginInfo,&theLoginInfo);
		needContinue=updateFunc(&theLoginInfo, pTransaction, parameter, &updateIndex);
		pFactory->update(pLoginInfo,&theLoginInfo,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CLoginInfoIterator *pIterator, TLoginInfoSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CLoginInfo *pLoginInfo;
	int selected;
	CLoginInfoFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pLoginInfo=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pLoginInfo, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pLoginInfo,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDepthMarketDataDetail *pDepthMarketDataDetail;
	
	while ((pDepthMarketDataDetail=pIterator->next())!=NULL)
	{
		if (!actionFunc(pDepthMarketDataDetail, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDepthMarketDataDetail *pDepthMarketDataDetail;
	CWriteableDepthMarketDataDetail theDepthMarketDataDetail;
	bool updateIndex;
	CDepthMarketDataDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pDepthMarketDataDetail=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pDepthMarketDataDetail,&theDepthMarketDataDetail);
		needContinue=updateFunc(&theDepthMarketDataDetail, pTransaction, parameter, &updateIndex);
		pFactory->update(pDepthMarketDataDetail,&theDepthMarketDataDetail,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDepthMarketDataDetail *pDepthMarketDataDetail;
	int selected;
	CDepthMarketDataDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pDepthMarketDataDetail=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pDepthMarketDataDetail, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pDepthMarketDataDetail,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrumentStatusDetail *pInstrumentStatusDetail;
	
	while ((pInstrumentStatusDetail=pIterator->next())!=NULL)
	{
		if (!actionFunc(pInstrumentStatusDetail, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrumentStatusDetail *pInstrumentStatusDetail;
	CWriteableInstrumentStatusDetail theInstrumentStatusDetail;
	bool updateIndex;
	CInstrumentStatusDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInstrumentStatusDetail=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pInstrumentStatusDetail,&theInstrumentStatusDetail);
		needContinue=updateFunc(&theInstrumentStatusDetail, pTransaction, parameter, &updateIndex);
		pFactory->update(pInstrumentStatusDetail,&theInstrumentStatusDetail,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrumentStatusDetail *pInstrumentStatusDetail;
	int selected;
	CInstrumentStatusDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInstrumentStatusDetail=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pInstrumentStatusDetail, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pInstrumentStatusDetail,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CFrontStatusIterator *pIterator, TFrontStatusActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CFrontStatus *pFrontStatus;
	
	while ((pFrontStatus=pIterator->next())!=NULL)
	{
		if (!actionFunc(pFrontStatus, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CFrontStatusIterator *pIterator, TFrontStatusUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CFrontStatus *pFrontStatus;
	CWriteableFrontStatus theFrontStatus;
	bool updateIndex;
	CFrontStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pFrontStatus=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pFrontStatus,&theFrontStatus);
		needContinue=updateFunc(&theFrontStatus, pTransaction, parameter, &updateIndex);
		pFactory->update(pFrontStatus,&theFrontStatus,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CFrontStatusIterator *pIterator, TFrontStatusSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CFrontStatus *pFrontStatus;
	int selected;
	CFrontStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pFrontStatus=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pFrontStatus, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pFrontStatus,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMaxLocalIDIterator *pIterator, TMaxLocalIDActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMaxLocalID *pMaxLocalID;
	
	while ((pMaxLocalID=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMaxLocalID, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMaxLocalIDIterator *pIterator, TMaxLocalIDUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMaxLocalID *pMaxLocalID;
	CWriteableMaxLocalID theMaxLocalID;
	bool updateIndex;
	CMaxLocalIDFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMaxLocalID=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMaxLocalID,&theMaxLocalID);
		needContinue=updateFunc(&theMaxLocalID, pTransaction, parameter, &updateIndex);
		pFactory->update(pMaxLocalID,&theMaxLocalID,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMaxLocalIDIterator *pIterator, TMaxLocalIDSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMaxLocalID *pMaxLocalID;
	int selected;
	CMaxLocalIDFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMaxLocalID=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMaxLocalID, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMaxLocalID,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CBulletinIterator *pIterator, TBulletinActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBulletin *pBulletin;
	
	while ((pBulletin=pIterator->next())!=NULL)
	{
		if (!actionFunc(pBulletin, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CBulletinIterator *pIterator, TBulletinUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBulletin *pBulletin;
	CWriteableBulletin theBulletin;
	bool updateIndex;
	CBulletinFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pBulletin=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pBulletin,&theBulletin);
		needContinue=updateFunc(&theBulletin, pTransaction, parameter, &updateIndex);
		pFactory->update(pBulletin,&theBulletin,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CBulletinIterator *pIterator, TBulletinSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBulletin *pBulletin;
	int selected;
	CBulletinFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pBulletin=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pBulletin, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pBulletin,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMarketDataModifyIterator *pIterator, TMarketDataModifyActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataModify *pMarketDataModify;
	
	while ((pMarketDataModify=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMarketDataModify, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMarketDataModifyIterator *pIterator, TMarketDataModifyUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataModify *pMarketDataModify;
	CWriteableMarketDataModify theMarketDataModify;
	bool updateIndex;
	CMarketDataModifyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketDataModify=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMarketDataModify,&theMarketDataModify);
		needContinue=updateFunc(&theMarketDataModify, pTransaction, parameter, &updateIndex);
		pFactory->update(pMarketDataModify,&theMarketDataModify,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMarketDataModifyIterator *pIterator, TMarketDataModifySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketDataModify *pMarketDataModify;
	int selected;
	CMarketDataModifyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketDataModify=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMarketDataModify, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMarketDataModify,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CDepthMarketDataIterator *pIterator, TDepthMarketDataActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDepthMarketData *pDepthMarketData;
	
	while ((pDepthMarketData=pIterator->next())!=NULL)
	{
		if (!actionFunc(pDepthMarketData, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CDepthMarketDataIterator *pIterator, TDepthMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDepthMarketData *pDepthMarketData;
	CWriteableDepthMarketData theDepthMarketData;
	bool updateIndex;
	CDepthMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pDepthMarketData=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pDepthMarketData,&theDepthMarketData);
		needContinue=updateFunc(&theDepthMarketData, pTransaction, parameter, &updateIndex);
		pFactory->update(pDepthMarketData,&theDepthMarketData,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CDepthMarketDataIterator *pIterator, TDepthMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CDepthMarketData *pDepthMarketData;
	int selected;
	CDepthMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pDepthMarketData=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pDepthMarketData, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pDepthMarketData,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CTopicMarketDataIterator *pIterator, TTopicMarketDataActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTopicMarketData *pTopicMarketData;
	
	while ((pTopicMarketData=pIterator->next())!=NULL)
	{
		if (!actionFunc(pTopicMarketData, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CTopicMarketDataIterator *pIterator, TTopicMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTopicMarketData *pTopicMarketData;
	CWriteableTopicMarketData theTopicMarketData;
	bool updateIndex;
	CTopicMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTopicMarketData=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pTopicMarketData,&theTopicMarketData);
		needContinue=updateFunc(&theTopicMarketData, pTransaction, parameter, &updateIndex);
		pFactory->update(pTopicMarketData,&theTopicMarketData,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CTopicMarketDataIterator *pIterator, TTopicMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTopicMarketData *pTopicMarketData;
	int selected;
	CTopicMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTopicMarketData=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pTopicMarketData, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pTopicMarketData,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTopicMarketDataVersion *pTopicMarketDataVersion;
	
	while ((pTopicMarketDataVersion=pIterator->next())!=NULL)
	{
		if (!actionFunc(pTopicMarketDataVersion, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTopicMarketDataVersion *pTopicMarketDataVersion;
	CWriteableTopicMarketDataVersion theTopicMarketDataVersion;
	bool updateIndex;
	CTopicMarketDataVersionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTopicMarketDataVersion=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pTopicMarketDataVersion,&theTopicMarketDataVersion);
		needContinue=updateFunc(&theTopicMarketDataVersion, pTransaction, parameter, &updateIndex);
		pFactory->update(pTopicMarketDataVersion,&theTopicMarketDataVersion,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTopicMarketDataVersion *pTopicMarketDataVersion;
	int selected;
	CTopicMarketDataVersionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTopicMarketDataVersion=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pTopicMarketDataVersion, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pTopicMarketDataVersion,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CInformationIterator *pIterator, TInformationActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInformation *pInformation;
	
	while ((pInformation=pIterator->next())!=NULL)
	{
		if (!actionFunc(pInformation, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CInformationIterator *pIterator, TInformationUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInformation *pInformation;
	CWriteableInformation theInformation;
	bool updateIndex;
	CInformationFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInformation=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pInformation,&theInformation);
		needContinue=updateFunc(&theInformation, pTransaction, parameter, &updateIndex);
		pFactory->update(pInformation,&theInformation,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CInformationIterator *pIterator, TInformationSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInformation *pInformation;
	int selected;
	CInformationFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInformation=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pInformation, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pInformation,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(COrderCountIterator *pIterator, TOrderCountActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	COrderCount *pOrderCount;
	
	while ((pOrderCount=pIterator->next())!=NULL)
	{
		if (!actionFunc(pOrderCount, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(COrderCountIterator *pIterator, TOrderCountUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	COrderCount *pOrderCount;
	CWriteableOrderCount theOrderCount;
	bool updateIndex;
	COrderCountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pOrderCount=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pOrderCount,&theOrderCount);
		needContinue=updateFunc(&theOrderCount, pTransaction, parameter, &updateIndex);
		pFactory->update(pOrderCount,&theOrderCount,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(COrderCountIterator *pIterator, TOrderCountSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	COrderCount *pOrderCount;
	int selected;
	COrderCountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pOrderCount=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pOrderCount, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pOrderCount,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CInstrumentIterator *pIterator, TInstrumentActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrument *pInstrument;
	
	while ((pInstrument=pIterator->next())!=NULL)
	{
		if (!actionFunc(pInstrument, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CInstrumentIterator *pIterator, TInstrumentUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrument *pInstrument;
	CWriteableInstrument theInstrument;
	bool updateIndex;
	CInstrumentFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInstrument=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pInstrument,&theInstrument);
		needContinue=updateFunc(&theInstrument, pTransaction, parameter, &updateIndex);
		pFactory->update(pInstrument,&theInstrument,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CInstrumentIterator *pIterator, TInstrumentSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrument *pInstrument;
	int selected;
	CInstrumentFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInstrument=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pInstrument, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pInstrument,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCombinationLegIterator *pIterator, TCombinationLegActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCombinationLeg *pCombinationLeg;
	
	while ((pCombinationLeg=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCombinationLeg, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCombinationLegIterator *pIterator, TCombinationLegUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCombinationLeg *pCombinationLeg;
	CWriteableCombinationLeg theCombinationLeg;
	bool updateIndex;
	CCombinationLegFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCombinationLeg=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCombinationLeg,&theCombinationLeg);
		needContinue=updateFunc(&theCombinationLeg, pTransaction, parameter, &updateIndex);
		pFactory->update(pCombinationLeg,&theCombinationLeg,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCombinationLegIterator *pIterator, TCombinationLegSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCombinationLeg *pCombinationLeg;
	int selected;
	CCombinationLegFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCombinationLeg=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCombinationLeg, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCombinationLeg,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartRoleAccountIterator *pIterator, TPartRoleAccountActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartRoleAccount *pPartRoleAccount;
	
	while ((pPartRoleAccount=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartRoleAccount, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartRoleAccountIterator *pIterator, TPartRoleAccountUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartRoleAccount *pPartRoleAccount;
	CWriteablePartRoleAccount thePartRoleAccount;
	bool updateIndex;
	CPartRoleAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartRoleAccount=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartRoleAccount,&thePartRoleAccount);
		needContinue=updateFunc(&thePartRoleAccount, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartRoleAccount,&thePartRoleAccount,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartRoleAccountIterator *pIterator, TPartRoleAccountSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartRoleAccount *pPartRoleAccount;
	int selected;
	CPartRoleAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartRoleAccount=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartRoleAccount, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartRoleAccount,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartProductRoleIterator *pIterator, TPartProductRoleActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartProductRole *pPartProductRole;
	
	while ((pPartProductRole=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartProductRole, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartProductRoleIterator *pIterator, TPartProductRoleUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartProductRole *pPartProductRole;
	CWriteablePartProductRole thePartProductRole;
	bool updateIndex;
	CPartProductRoleFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartProductRole=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartProductRole,&thePartProductRole);
		needContinue=updateFunc(&thePartProductRole, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartProductRole,&thePartProductRole,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartProductRoleIterator *pIterator, TPartProductRoleSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartProductRole *pPartProductRole;
	int selected;
	CPartProductRoleFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartProductRole=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartProductRole, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartProductRole,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartProductRightIterator *pIterator, TPartProductRightActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartProductRight *pPartProductRight;
	
	while ((pPartProductRight=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartProductRight, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartProductRightIterator *pIterator, TPartProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartProductRight *pPartProductRight;
	CWriteablePartProductRight thePartProductRight;
	bool updateIndex;
	CPartProductRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartProductRight=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartProductRight,&thePartProductRight);
		needContinue=updateFunc(&thePartProductRight, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartProductRight,&thePartProductRight,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartProductRightIterator *pIterator, TPartProductRightSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartProductRight *pPartProductRight;
	int selected;
	CPartProductRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartProductRight=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartProductRight, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartProductRight,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartInstrumentRight *pPartInstrumentRight;
	
	while ((pPartInstrumentRight=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartInstrumentRight, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartInstrumentRight *pPartInstrumentRight;
	CWriteablePartInstrumentRight thePartInstrumentRight;
	bool updateIndex;
	CPartInstrumentRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartInstrumentRight=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartInstrumentRight,&thePartInstrumentRight);
		needContinue=updateFunc(&thePartInstrumentRight, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartInstrumentRight,&thePartInstrumentRight,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartInstrumentRight *pPartInstrumentRight;
	int selected;
	CPartInstrumentRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartInstrumentRight=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartInstrumentRight, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartInstrumentRight,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CClientProductRightIterator *pIterator, TClientProductRightActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientProductRight *pClientProductRight;
	
	while ((pClientProductRight=pIterator->next())!=NULL)
	{
		if (!actionFunc(pClientProductRight, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CClientProductRightIterator *pIterator, TClientProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientProductRight *pClientProductRight;
	CWriteableClientProductRight theClientProductRight;
	bool updateIndex;
	CClientProductRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClientProductRight=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pClientProductRight,&theClientProductRight);
		needContinue=updateFunc(&theClientProductRight, pTransaction, parameter, &updateIndex);
		pFactory->update(pClientProductRight,&theClientProductRight,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CClientProductRightIterator *pIterator, TClientProductRightSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientProductRight *pClientProductRight;
	int selected;
	CClientProductRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClientProductRight=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pClientProductRight, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pClientProductRight,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientInstrumentRight *pClientInstrumentRight;
	
	while ((pClientInstrumentRight=pIterator->next())!=NULL)
	{
		if (!actionFunc(pClientInstrumentRight, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientInstrumentRight *pClientInstrumentRight;
	CWriteableClientInstrumentRight theClientInstrumentRight;
	bool updateIndex;
	CClientInstrumentRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClientInstrumentRight=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pClientInstrumentRight,&theClientInstrumentRight);
		needContinue=updateFunc(&theClientInstrumentRight, pTransaction, parameter, &updateIndex);
		pFactory->update(pClientInstrumentRight,&theClientInstrumentRight,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientInstrumentRight *pClientInstrumentRight;
	int selected;
	CClientInstrumentRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClientInstrumentRight=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pClientInstrumentRight, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pClientInstrumentRight,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartClientProductRightIterator *pIterator, TPartClientProductRightActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClientProductRight *pPartClientProductRight;
	
	while ((pPartClientProductRight=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartClientProductRight, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartClientProductRightIterator *pIterator, TPartClientProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClientProductRight *pPartClientProductRight;
	CWriteablePartClientProductRight thePartClientProductRight;
	bool updateIndex;
	CPartClientProductRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartClientProductRight=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartClientProductRight,&thePartClientProductRight);
		needContinue=updateFunc(&thePartClientProductRight, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartClientProductRight,&thePartClientProductRight,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartClientProductRightIterator *pIterator, TPartClientProductRightSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClientProductRight *pPartClientProductRight;
	int selected;
	CPartClientProductRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartClientProductRight=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartClientProductRight, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartClientProductRight,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClientInstrumentRight *pPartClientInstrumentRight;
	
	while ((pPartClientInstrumentRight=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartClientInstrumentRight, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClientInstrumentRight *pPartClientInstrumentRight;
	CWriteablePartClientInstrumentRight thePartClientInstrumentRight;
	bool updateIndex;
	CPartClientInstrumentRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartClientInstrumentRight=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartClientInstrumentRight,&thePartClientInstrumentRight);
		needContinue=updateFunc(&thePartClientInstrumentRight, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartClientInstrumentRight,&thePartClientInstrumentRight,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartClientInstrumentRight *pPartClientInstrumentRight;
	int selected;
	CPartClientInstrumentRightFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartClientInstrumentRight=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartClientInstrumentRight, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartClientInstrumentRight,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrProductPropertyIterator *pIterator, TCurrProductPropertyActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrProductProperty *pCurrProductProperty;
	
	while ((pCurrProductProperty=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrProductProperty, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrProductPropertyIterator *pIterator, TCurrProductPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrProductProperty *pCurrProductProperty;
	CWriteableCurrProductProperty theCurrProductProperty;
	bool updateIndex;
	CCurrProductPropertyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrProductProperty=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrProductProperty,&theCurrProductProperty);
		needContinue=updateFunc(&theCurrProductProperty, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrProductProperty,&theCurrProductProperty,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrProductPropertyIterator *pIterator, TCurrProductPropertySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrProductProperty *pCurrProductProperty;
	int selected;
	CCurrProductPropertyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrProductProperty=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrProductProperty, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrProductProperty,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertyActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrInstrumentProperty *pCurrInstrumentProperty;
	
	while ((pCurrInstrumentProperty=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrInstrumentProperty, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrInstrumentProperty *pCurrInstrumentProperty;
	CWriteableCurrInstrumentProperty theCurrInstrumentProperty;
	bool updateIndex;
	CCurrInstrumentPropertyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrInstrumentProperty=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrInstrumentProperty,&theCurrInstrumentProperty);
		needContinue=updateFunc(&theCurrInstrumentProperty, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrInstrumentProperty,&theCurrInstrumentProperty,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertySelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrInstrumentProperty *pCurrInstrumentProperty;
	int selected;
	CCurrInstrumentPropertyFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrInstrumentProperty=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrInstrumentProperty, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrInstrumentProperty,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPriceBanding *pCurrPriceBanding;
	
	while ((pCurrPriceBanding=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrPriceBanding, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPriceBanding *pCurrPriceBanding;
	CWriteableCurrPriceBanding theCurrPriceBanding;
	bool updateIndex;
	CCurrPriceBandingFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrPriceBanding=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrPriceBanding,&theCurrPriceBanding);
		needContinue=updateFunc(&theCurrPriceBanding, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrPriceBanding,&theCurrPriceBanding,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPriceBanding *pCurrPriceBanding;
	int selected;
	CCurrPriceBandingFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrPriceBanding=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrPriceBanding, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrPriceBanding,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrMarginRateIterator *pIterator, TCurrMarginRateActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrMarginRate *pCurrMarginRate;
	
	while ((pCurrMarginRate=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrMarginRate, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrMarginRateIterator *pIterator, TCurrMarginRateUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrMarginRate *pCurrMarginRate;
	CWriteableCurrMarginRate theCurrMarginRate;
	bool updateIndex;
	CCurrMarginRateFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrMarginRate=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrMarginRate,&theCurrMarginRate);
		needContinue=updateFunc(&theCurrMarginRate, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrMarginRate,&theCurrMarginRate,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrMarginRateIterator *pIterator, TCurrMarginRateSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrMarginRate *pCurrMarginRate;
	int selected;
	CCurrMarginRateFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrMarginRate=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrMarginRate, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrMarginRate,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrMarginRateDetail *pCurrMarginRateDetail;
	
	while ((pCurrMarginRateDetail=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrMarginRateDetail, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrMarginRateDetail *pCurrMarginRateDetail;
	CWriteableCurrMarginRateDetail theCurrMarginRateDetail;
	bool updateIndex;
	CCurrMarginRateDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrMarginRateDetail=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrMarginRateDetail,&theCurrMarginRateDetail);
		needContinue=updateFunc(&theCurrMarginRateDetail, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrMarginRateDetail,&theCurrMarginRateDetail,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrMarginRateDetail *pCurrMarginRateDetail;
	int selected;
	CCurrMarginRateDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrMarginRateDetail=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrMarginRateDetail, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrMarginRateDetail,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPartPosiLimit *pCurrPartPosiLimit;
	
	while ((pCurrPartPosiLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrPartPosiLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPartPosiLimit *pCurrPartPosiLimit;
	CWriteableCurrPartPosiLimit theCurrPartPosiLimit;
	bool updateIndex;
	CCurrPartPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrPartPosiLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrPartPosiLimit,&theCurrPartPosiLimit);
		needContinue=updateFunc(&theCurrPartPosiLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrPartPosiLimit,&theCurrPartPosiLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPartPosiLimit *pCurrPartPosiLimit;
	int selected;
	CCurrPartPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrPartPosiLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrPartPosiLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrPartPosiLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail;
	
	while ((pCurrPartPosiLimitDetail=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrPartPosiLimitDetail, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail;
	CWriteableCurrPartPosiLimitDetail theCurrPartPosiLimitDetail;
	bool updateIndex;
	CCurrPartPosiLimitDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrPartPosiLimitDetail=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrPartPosiLimitDetail,&theCurrPartPosiLimitDetail);
		needContinue=updateFunc(&theCurrPartPosiLimitDetail, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrPartPosiLimitDetail,&theCurrPartPosiLimitDetail,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail;
	int selected;
	CCurrPartPosiLimitDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrPartPosiLimitDetail=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrPartPosiLimitDetail, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrPartPosiLimitDetail,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrClientPosiLimit *pCurrClientPosiLimit;
	
	while ((pCurrClientPosiLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrClientPosiLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrClientPosiLimit *pCurrClientPosiLimit;
	CWriteableCurrClientPosiLimit theCurrClientPosiLimit;
	bool updateIndex;
	CCurrClientPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrClientPosiLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrClientPosiLimit,&theCurrClientPosiLimit);
		needContinue=updateFunc(&theCurrClientPosiLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrClientPosiLimit,&theCurrClientPosiLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrClientPosiLimit *pCurrClientPosiLimit;
	int selected;
	CCurrClientPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrClientPosiLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrClientPosiLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrClientPosiLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail;
	
	while ((pCurrClientPosiLimitDetail=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrClientPosiLimitDetail, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail;
	CWriteableCurrClientPosiLimitDetail theCurrClientPosiLimitDetail;
	bool updateIndex;
	CCurrClientPosiLimitDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrClientPosiLimitDetail=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrClientPosiLimitDetail,&theCurrClientPosiLimitDetail);
		needContinue=updateFunc(&theCurrClientPosiLimitDetail, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrClientPosiLimitDetail,&theCurrClientPosiLimitDetail,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail;
	int selected;
	CCurrClientPosiLimitDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrClientPosiLimitDetail=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrClientPosiLimitDetail, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrClientPosiLimitDetail,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrSpecialPosiLimit *pCurrSpecialPosiLimit;
	
	while ((pCurrSpecialPosiLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrSpecialPosiLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrSpecialPosiLimit *pCurrSpecialPosiLimit;
	CWriteableCurrSpecialPosiLimit theCurrSpecialPosiLimit;
	bool updateIndex;
	CCurrSpecialPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrSpecialPosiLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrSpecialPosiLimit,&theCurrSpecialPosiLimit);
		needContinue=updateFunc(&theCurrSpecialPosiLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrSpecialPosiLimit,&theCurrSpecialPosiLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrSpecialPosiLimit *pCurrSpecialPosiLimit;
	int selected;
	CCurrSpecialPosiLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrSpecialPosiLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrSpecialPosiLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrSpecialPosiLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail;
	
	while ((pCurrSpecialPosiLimitDetail=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrSpecialPosiLimitDetail, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail;
	CWriteableCurrSpecialPosiLimitDetail theCurrSpecialPosiLimitDetail;
	bool updateIndex;
	CCurrSpecialPosiLimitDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrSpecialPosiLimitDetail=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrSpecialPosiLimitDetail,&theCurrSpecialPosiLimitDetail);
		needContinue=updateFunc(&theCurrSpecialPosiLimitDetail, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrSpecialPosiLimitDetail,&theCurrSpecialPosiLimitDetail,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail;
	int selected;
	CCurrSpecialPosiLimitDetailFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrSpecialPosiLimitDetail=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrSpecialPosiLimitDetail, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrSpecialPosiLimitDetail,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrHedgeRule *pCurrHedgeRule;
	
	while ((pCurrHedgeRule=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrHedgeRule, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrHedgeRule *pCurrHedgeRule;
	CWriteableCurrHedgeRule theCurrHedgeRule;
	bool updateIndex;
	CCurrHedgeRuleFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrHedgeRule=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrHedgeRule,&theCurrHedgeRule);
		needContinue=updateFunc(&theCurrHedgeRule, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrHedgeRule,&theCurrHedgeRule,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrHedgeRule *pCurrHedgeRule;
	int selected;
	CCurrHedgeRuleFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrHedgeRule=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrHedgeRule, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrHedgeRule,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrTradingSegmentAttr *pCurrTradingSegmentAttr;
	
	while ((pCurrTradingSegmentAttr=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrTradingSegmentAttr, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrTradingSegmentAttr *pCurrTradingSegmentAttr;
	CWriteableCurrTradingSegmentAttr theCurrTradingSegmentAttr;
	bool updateIndex;
	CCurrTradingSegmentAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrTradingSegmentAttr=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrTradingSegmentAttr,&theCurrTradingSegmentAttr);
		needContinue=updateFunc(&theCurrTradingSegmentAttr, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrTradingSegmentAttr,&theCurrTradingSegmentAttr,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrTradingSegmentAttr *pCurrTradingSegmentAttr;
	int selected;
	CCurrTradingSegmentAttrFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrTradingSegmentAttr=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrTradingSegmentAttr, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrTradingSegmentAttr,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrFuseIterator *pIterator, TCurrFuseActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrFuse *pCurrFuse;
	
	while ((pCurrFuse=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrFuse, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrFuseIterator *pIterator, TCurrFuseUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrFuse *pCurrFuse;
	CWriteableCurrFuse theCurrFuse;
	bool updateIndex;
	CCurrFuseFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrFuse=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrFuse,&theCurrFuse);
		needContinue=updateFunc(&theCurrFuse, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrFuse,&theCurrFuse,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrFuseIterator *pIterator, TCurrFuseSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrFuse *pCurrFuse;
	int selected;
	CCurrFuseFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrFuse=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrFuse, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrFuse,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CTradingAccountIterator *pIterator, TTradingAccountActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTradingAccount *pTradingAccount;
	
	while ((pTradingAccount=pIterator->next())!=NULL)
	{
		if (!actionFunc(pTradingAccount, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CTradingAccountIterator *pIterator, TTradingAccountUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTradingAccount *pTradingAccount;
	CWriteableTradingAccount theTradingAccount;
	bool updateIndex;
	CTradingAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTradingAccount=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pTradingAccount,&theTradingAccount);
		needContinue=updateFunc(&theTradingAccount, pTransaction, parameter, &updateIndex);
		pFactory->update(pTradingAccount,&theTradingAccount,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CTradingAccountIterator *pIterator, TTradingAccountSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTradingAccount *pTradingAccount;
	int selected;
	CTradingAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTradingAccount=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pTradingAccount, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pTradingAccount,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBaseReserveAccount *pBaseReserveAccount;
	
	while ((pBaseReserveAccount=pIterator->next())!=NULL)
	{
		if (!actionFunc(pBaseReserveAccount, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBaseReserveAccount *pBaseReserveAccount;
	CWriteableBaseReserveAccount theBaseReserveAccount;
	bool updateIndex;
	CBaseReserveAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pBaseReserveAccount=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pBaseReserveAccount,&theBaseReserveAccount);
		needContinue=updateFunc(&theBaseReserveAccount, pTransaction, parameter, &updateIndex);
		pFactory->update(pBaseReserveAccount,&theBaseReserveAccount,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBaseReserveAccount *pBaseReserveAccount;
	int selected;
	CBaseReserveAccountFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pBaseReserveAccount=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pBaseReserveAccount, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pBaseReserveAccount,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CPartPositionIterator *pIterator, TPartPositionActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartPosition *pPartPosition;
	
	while ((pPartPosition=pIterator->next())!=NULL)
	{
		if (!actionFunc(pPartPosition, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CPartPositionIterator *pIterator, TPartPositionUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartPosition *pPartPosition;
	CWriteablePartPosition thePartPosition;
	bool updateIndex;
	CPartPositionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartPosition=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pPartPosition,&thePartPosition);
		needContinue=updateFunc(&thePartPosition, pTransaction, parameter, &updateIndex);
		pFactory->update(pPartPosition,&thePartPosition,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CPartPositionIterator *pIterator, TPartPositionSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CPartPosition *pPartPosition;
	int selected;
	CPartPositionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pPartPosition=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pPartPosition, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pPartPosition,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CClientPositionIterator *pIterator, TClientPositionActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientPosition *pClientPosition;
	
	while ((pClientPosition=pIterator->next())!=NULL)
	{
		if (!actionFunc(pClientPosition, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CClientPositionIterator *pIterator, TClientPositionUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientPosition *pClientPosition;
	CWriteableClientPosition theClientPosition;
	bool updateIndex;
	CClientPositionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClientPosition=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pClientPosition,&theClientPosition);
		needContinue=updateFunc(&theClientPosition, pTransaction, parameter, &updateIndex);
		pFactory->update(pClientPosition,&theClientPosition,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CClientPositionIterator *pIterator, TClientPositionSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClientPosition *pClientPosition;
	int selected;
	CClientPositionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClientPosition=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pClientPosition, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pClientPosition,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CHedgeVolumeIterator *pIterator, THedgeVolumeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CHedgeVolume *pHedgeVolume;
	
	while ((pHedgeVolume=pIterator->next())!=NULL)
	{
		if (!actionFunc(pHedgeVolume, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CHedgeVolumeIterator *pIterator, THedgeVolumeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CHedgeVolume *pHedgeVolume;
	CWriteableHedgeVolume theHedgeVolume;
	bool updateIndex;
	CHedgeVolumeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pHedgeVolume=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pHedgeVolume,&theHedgeVolume);
		needContinue=updateFunc(&theHedgeVolume, pTransaction, parameter, &updateIndex);
		pFactory->update(pHedgeVolume,&theHedgeVolume,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CHedgeVolumeIterator *pIterator, THedgeVolumeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CHedgeVolume *pHedgeVolume;
	int selected;
	CHedgeVolumeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pHedgeVolume=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pHedgeVolume, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pHedgeVolume,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CRemainOrderIterator *pIterator, TRemainOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRemainOrder *pRemainOrder;
	
	while ((pRemainOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pRemainOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CRemainOrderIterator *pIterator, TRemainOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRemainOrder *pRemainOrder;
	CWriteableRemainOrder theRemainOrder;
	bool updateIndex;
	CRemainOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRemainOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pRemainOrder,&theRemainOrder);
		needContinue=updateFunc(&theRemainOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pRemainOrder,&theRemainOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CRemainOrderIterator *pIterator, TRemainOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CRemainOrder *pRemainOrder;
	int selected;
	CRemainOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pRemainOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pRemainOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pRemainOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMarketDataIterator *pIterator, TMarketDataActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketData *pMarketData;
	
	while ((pMarketData=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMarketData, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMarketDataIterator *pIterator, TMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketData *pMarketData;
	CWriteableMarketData theMarketData;
	bool updateIndex;
	CMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketData=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMarketData,&theMarketData);
		needContinue=updateFunc(&theMarketData, pTransaction, parameter, &updateIndex);
		pFactory->update(pMarketData,&theMarketData,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMarketDataIterator *pIterator, TMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMarketData *pMarketData;
	int selected;
	CMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMarketData=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMarketData, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMarketData,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CClearingPartPositionIterator *pIterator, TClearingPartPositionActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClearingPartPosition *pClearingPartPosition;
	
	while ((pClearingPartPosition=pIterator->next())!=NULL)
	{
		if (!actionFunc(pClearingPartPosition, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CClearingPartPositionIterator *pIterator, TClearingPartPositionUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClearingPartPosition *pClearingPartPosition;
	CWriteableClearingPartPosition theClearingPartPosition;
	bool updateIndex;
	CClearingPartPositionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClearingPartPosition=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pClearingPartPosition,&theClearingPartPosition);
		needContinue=updateFunc(&theClearingPartPosition, pTransaction, parameter, &updateIndex);
		pFactory->update(pClearingPartPosition,&theClearingPartPosition,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CClearingPartPositionIterator *pIterator, TClearingPartPositionSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CClearingPartPosition *pClearingPartPosition;
	int selected;
	CClearingPartPositionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pClearingPartPosition=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pClearingPartPosition, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pClearingPartPosition,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CInstrumentStatusIterator *pIterator, TInstrumentStatusActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrumentStatus *pInstrumentStatus;
	
	while ((pInstrumentStatus=pIterator->next())!=NULL)
	{
		if (!actionFunc(pInstrumentStatus, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CInstrumentStatusIterator *pIterator, TInstrumentStatusUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrumentStatus *pInstrumentStatus;
	CWriteableInstrumentStatus theInstrumentStatus;
	bool updateIndex;
	CInstrumentStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInstrumentStatus=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pInstrumentStatus,&theInstrumentStatus);
		needContinue=updateFunc(&theInstrumentStatus, pTransaction, parameter, &updateIndex);
		pFactory->update(pInstrumentStatus,&theInstrumentStatus,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CInstrumentStatusIterator *pIterator, TInstrumentStatusSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CInstrumentStatus *pInstrumentStatus;
	int selected;
	CInstrumentStatusFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pInstrumentStatus=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pInstrumentStatus, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pInstrumentStatus,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(COrderIterator *pIterator, TOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	COrder *pOrder;
	
	while ((pOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(COrderIterator *pIterator, TOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	COrder *pOrder;
	CWriteableOrder theOrder;
	bool updateIndex;
	COrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pOrder,&theOrder);
		needContinue=updateFunc(&theOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pOrder,&theOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(COrderIterator *pIterator, TOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	COrder *pOrder;
	int selected;
	COrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCombOrderIterator *pIterator, TCombOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCombOrder *pCombOrder;
	
	while ((pCombOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCombOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCombOrderIterator *pIterator, TCombOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCombOrder *pCombOrder;
	CWriteableCombOrder theCombOrder;
	bool updateIndex;
	CCombOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCombOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCombOrder,&theCombOrder);
		needContinue=updateFunc(&theCombOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pCombOrder,&theCombOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCombOrderIterator *pIterator, TCombOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCombOrder *pCombOrder;
	int selected;
	CCombOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCombOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCombOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCombOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(COTCOrderIterator *pIterator, TOTCOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	COTCOrder *pOTCOrder;
	
	while ((pOTCOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pOTCOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(COTCOrderIterator *pIterator, TOTCOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	COTCOrder *pOTCOrder;
	CWriteableOTCOrder theOTCOrder;
	bool updateIndex;
	COTCOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pOTCOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pOTCOrder,&theOTCOrder);
		needContinue=updateFunc(&theOTCOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pOTCOrder,&theOTCOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(COTCOrderIterator *pIterator, TOTCOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	COTCOrder *pOTCOrder;
	int selected;
	COTCOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pOTCOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pOTCOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pOTCOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CImplyOrderIterator *pIterator, TImplyOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CImplyOrder *pImplyOrder;
	
	while ((pImplyOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pImplyOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CImplyOrderIterator *pIterator, TImplyOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CImplyOrder *pImplyOrder;
	CWriteableImplyOrder theImplyOrder;
	bool updateIndex;
	CImplyOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pImplyOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pImplyOrder,&theImplyOrder);
		needContinue=updateFunc(&theImplyOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pImplyOrder,&theImplyOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CImplyOrderIterator *pIterator, TImplyOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CImplyOrder *pImplyOrder;
	int selected;
	CImplyOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pImplyOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pImplyOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pImplyOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CQuoteIterator *pIterator, TQuoteActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CQuote *pQuote;
	
	while ((pQuote=pIterator->next())!=NULL)
	{
		if (!actionFunc(pQuote, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CQuoteIterator *pIterator, TQuoteUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CQuote *pQuote;
	CWriteableQuote theQuote;
	bool updateIndex;
	CQuoteFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pQuote=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pQuote,&theQuote);
		needContinue=updateFunc(&theQuote, pTransaction, parameter, &updateIndex);
		pFactory->update(pQuote,&theQuote,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CQuoteIterator *pIterator, TQuoteSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CQuote *pQuote;
	int selected;
	CQuoteFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pQuote=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pQuote, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pQuote,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CMBLMarketDataIterator *pIterator, TMBLMarketDataActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMBLMarketData *pMBLMarketData;
	
	while ((pMBLMarketData=pIterator->next())!=NULL)
	{
		if (!actionFunc(pMBLMarketData, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CMBLMarketDataIterator *pIterator, TMBLMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMBLMarketData *pMBLMarketData;
	CWriteableMBLMarketData theMBLMarketData;
	bool updateIndex;
	CMBLMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMBLMarketData=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pMBLMarketData,&theMBLMarketData);
		needContinue=updateFunc(&theMBLMarketData, pTransaction, parameter, &updateIndex);
		pFactory->update(pMBLMarketData,&theMBLMarketData,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CMBLMarketDataIterator *pIterator, TMBLMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CMBLMarketData *pMBLMarketData;
	int selected;
	CMBLMarketDataFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pMBLMarketData=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pMBLMarketData, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pMBLMarketData,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CTradeIterator *pIterator, TTradeActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTrade *pTrade;
	
	while ((pTrade=pIterator->next())!=NULL)
	{
		if (!actionFunc(pTrade, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CTradeIterator *pIterator, TTradeUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTrade *pTrade;
	CWriteableTrade theTrade;
	bool updateIndex;
	CTradeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTrade=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pTrade,&theTrade);
		needContinue=updateFunc(&theTrade, pTransaction, parameter, &updateIndex);
		pFactory->update(pTrade,&theTrade,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CTradeIterator *pIterator, TTradeSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CTrade *pTrade;
	int selected;
	CTradeFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pTrade=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pTrade, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pTrade,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CFusePhaseIterator *pIterator, TFusePhaseActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CFusePhase *pFusePhase;
	
	while ((pFusePhase=pIterator->next())!=NULL)
	{
		if (!actionFunc(pFusePhase, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CFusePhaseIterator *pIterator, TFusePhaseUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CFusePhase *pFusePhase;
	CWriteableFusePhase theFusePhase;
	bool updateIndex;
	CFusePhaseFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pFusePhase=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pFusePhase,&theFusePhase);
		needContinue=updateFunc(&theFusePhase, pTransaction, parameter, &updateIndex);
		pFactory->update(pFusePhase,&theFusePhase,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CFusePhaseIterator *pIterator, TFusePhaseSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CFusePhase *pFusePhase;
	int selected;
	CFusePhaseFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pFusePhase=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pFusePhase, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pFusePhase,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CExecOrderIterator *pIterator, TExecOrderActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExecOrder *pExecOrder;
	
	while ((pExecOrder=pIterator->next())!=NULL)
	{
		if (!actionFunc(pExecOrder, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CExecOrderIterator *pIterator, TExecOrderUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExecOrder *pExecOrder;
	CWriteableExecOrder theExecOrder;
	bool updateIndex;
	CExecOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pExecOrder=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pExecOrder,&theExecOrder);
		needContinue=updateFunc(&theExecOrder, pTransaction, parameter, &updateIndex);
		pFactory->update(pExecOrder,&theExecOrder,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CExecOrderIterator *pIterator, TExecOrderSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CExecOrder *pExecOrder;
	int selected;
	CExecOrderFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pExecOrder=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pExecOrder, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pExecOrder,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CUniPressureIterator *pIterator, TUniPressureActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUniPressure *pUniPressure;
	
	while ((pUniPressure=pIterator->next())!=NULL)
	{
		if (!actionFunc(pUniPressure, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CUniPressureIterator *pIterator, TUniPressureUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUniPressure *pUniPressure;
	CWriteableUniPressure theUniPressure;
	bool updateIndex;
	CUniPressureFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUniPressure=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pUniPressure,&theUniPressure);
		needContinue=updateFunc(&theUniPressure, pTransaction, parameter, &updateIndex);
		pFactory->update(pUniPressure,&theUniPressure,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CUniPressureIterator *pIterator, TUniPressureSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CUniPressure *pUniPressure;
	int selected;
	CUniPressureFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pUniPressure=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pUniPressure, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pUniPressure,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CBasePriceLimitIterator *pIterator, TBasePriceLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBasePriceLimit *pBasePriceLimit;
	
	while ((pBasePriceLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pBasePriceLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CBasePriceLimitIterator *pIterator, TBasePriceLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBasePriceLimit *pBasePriceLimit;
	CWriteableBasePriceLimit theBasePriceLimit;
	bool updateIndex;
	CBasePriceLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pBasePriceLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pBasePriceLimit,&theBasePriceLimit);
		needContinue=updateFunc(&theBasePriceLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pBasePriceLimit,&theBasePriceLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CBasePriceLimitIterator *pIterator, TBasePriceLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CBasePriceLimit *pBasePriceLimit;
	int selected;
	CBasePriceLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pBasePriceLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pBasePriceLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pBasePriceLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCreditLimitIterator *pIterator, TCreditLimitActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCreditLimit *pCreditLimit;
	
	while ((pCreditLimit=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCreditLimit, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCreditLimitIterator *pIterator, TCreditLimitUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCreditLimit *pCreditLimit;
	CWriteableCreditLimit theCreditLimit;
	bool updateIndex;
	CCreditLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCreditLimit=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCreditLimit,&theCreditLimit);
		needContinue=updateFunc(&theCreditLimit, pTransaction, parameter, &updateIndex);
		pFactory->update(pCreditLimit,&theCreditLimit,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCreditLimitIterator *pIterator, TCreditLimitSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCreditLimit *pCreditLimit;
	int selected;
	CCreditLimitFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCreditLimit=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCreditLimit, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCreditLimit,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

void groupAction(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionActionFunc actionFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrInstrumentOption *pCurrInstrumentOption;
	
	while ((pCurrInstrumentOption=pIterator->next())!=NULL)
	{
		if (!actionFunc(pCurrInstrumentOption, pTransaction, parameter))
		{
			return;
		}
	}
}

void groupUpdate(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionUpdateFunc updateFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrInstrumentOption *pCurrInstrumentOption;
	CWriteableCurrInstrumentOption theCurrInstrumentOption;
	bool updateIndex;
	CCurrInstrumentOptionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrInstrumentOption=pIterator->next())!=NULL)
	{
		pFactory->retrieve(pCurrInstrumentOption,&theCurrInstrumentOption);
		needContinue=updateFunc(&theCurrInstrumentOption, pTransaction, parameter, &updateIndex);
		pFactory->update(pCurrInstrumentOption,&theCurrInstrumentOption,pTransaction,updateIndex);
		if (!needContinue)
		{
			return;
		}
	}
}

void groupDelete(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionSelectFunc selectFunc,
	CTransaction *pTransaction, void *parameter)
{
	CCurrInstrumentOption *pCurrInstrumentOption;
	int selected;
	CCurrInstrumentOptionFactory *pFactory;
	int needContinue;
	
	pFactory=pIterator->getFactory();
	
	while ((pCurrInstrumentOption=pIterator->next())!=NULL)
	{
		if (selectFunc==NULL)
		{
			needContinue=1;
			selected=1;
		}
		else
		{
			needContinue=selectFunc(pCurrInstrumentOption, pTransaction, parameter, &selected);
		}
		if (selected)
		{
			pFactory->remove(pCurrInstrumentOption,pTransaction);
		}
		if (!needContinue)
		{
			return;
		}
	}
}

