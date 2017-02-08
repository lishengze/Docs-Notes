/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file databaseGroupActions.h
///@brief定义了若干个内存数据库的群组操作
///@history 
///20060127	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEGROUPACTIONS_H
#define DATABASEGROUPACTIONS_H

#include "BaseDataStruct.h"
#include "databaseFactories.h"


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExchangeDataSyncStatusActionFunc)(CExchangeDataSyncStatus * pExchangeDataSyncStatus, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExchangeDataSyncStatusUpdateFunc)(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExchangeDataSyncStatusSelectFunc)(CExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSGDataSyncStatusActionFunc)(CSGDataSyncStatus * pSGDataSyncStatus, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSGDataSyncStatusUpdateFunc)(CWriteableSGDataSyncStatus * pSGDataSyncStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSGDataSyncStatusSelectFunc)(CSGDataSyncStatus * pSGDataSyncStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrentTimeActionFunc)(CCurrentTime * pCurrentTime, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrentTimeUpdateFunc)(CWriteableCurrentTime * pCurrentTime, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrentTimeSelectFunc)(CCurrentTime * pCurrentTime,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrentTimeIterator *pIterator, TCurrentTimeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrentTimeIterator *pIterator, TCurrentTimeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrentTimeIterator *pIterator, TCurrentTimeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDataCenterDescActionFunc)(CDataCenterDesc * pDataCenterDesc, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDataCenterDescUpdateFunc)(CWriteableDataCenterDesc * pDataCenterDesc, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDataCenterDescSelectFunc)(CDataCenterDesc * pDataCenterDesc,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CDataCenterDescIterator *pIterator, TDataCenterDescActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CDataCenterDescIterator *pIterator, TDataCenterDescUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CDataCenterDescIterator *pIterator, TDataCenterDescSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExchangeActionFunc)(CExchange * pExchange, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExchangeUpdateFunc)(CWriteableExchange * pExchange, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExchangeSelectFunc)(CExchange * pExchange,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CExchangeIterator *pIterator, TExchangeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CExchangeIterator *pIterator, TExchangeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CExchangeIterator *pIterator, TExchangeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSettlementGroupActionFunc)(CSettlementGroup * pSettlementGroup, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSettlementGroupUpdateFunc)(CWriteableSettlementGroup * pSettlementGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSettlementGroupSelectFunc)(CSettlementGroup * pSettlementGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSettlementGroupIterator *pIterator, TSettlementGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSettlementGroupIterator *pIterator, TSettlementGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSettlementGroupIterator *pIterator, TSettlementGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketActionFunc)(CMarket * pMarket, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketUpdateFunc)(CWriteableMarket * pMarket, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketSelectFunc)(CMarket * pMarket,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMarketIterator *pIterator, TMarketActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMarketIterator *pIterator, TMarketUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMarketIterator *pIterator, TMarketSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketProductActionFunc)(CMarketProduct * pMarketProduct, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketProductUpdateFunc)(CWriteableMarketProduct * pMarketProduct, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketProductSelectFunc)(CMarketProduct * pMarketProduct,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMarketProductIterator *pIterator, TMarketProductActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMarketProductIterator *pIterator, TMarketProductUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMarketProductIterator *pIterator, TMarketProductSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketProductGroupActionFunc)(CMarketProductGroup * pMarketProductGroup, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketProductGroupUpdateFunc)(CWriteableMarketProductGroup * pMarketProductGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketProductGroupSelectFunc)(CMarketProductGroup * pMarketProductGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMarketProductGroupIterator *pIterator, TMarketProductGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMarketProductGroupIterator *pIterator, TMarketProductGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMarketProductGroupIterator *pIterator, TMarketProductGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMdPubStatusActionFunc)(CMdPubStatus * pMdPubStatus, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMdPubStatusUpdateFunc)(CWriteableMdPubStatus * pMdPubStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMdPubStatusSelectFunc)(CMdPubStatus * pMdPubStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMdPubStatusIterator *pIterator, TMdPubStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMdPubStatusIterator *pIterator, TMdPubStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMdPubStatusIterator *pIterator, TMdPubStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataTopicActionFunc)(CMarketDataTopic * pMarketDataTopic, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataTopicUpdateFunc)(CWriteableMarketDataTopic * pMarketDataTopic, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataTopicSelectFunc)(CMarketDataTopic * pMarketDataTopic,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMarketDataTopicIterator *pIterator, TMarketDataTopicActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMarketDataTopicIterator *pIterator, TMarketDataTopicUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMarketDataTopicIterator *pIterator, TMarketDataTopicSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartTopicSubscribeActionFunc)(CPartTopicSubscribe * pPartTopicSubscribe, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartTopicSubscribeUpdateFunc)(CWriteablePartTopicSubscribe * pPartTopicSubscribe, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartTopicSubscribeSelectFunc)(CPartTopicSubscribe * pPartTopicSubscribe,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TParticipantActionFunc)(CParticipant * pParticipant, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TParticipantUpdateFunc)(CWriteableParticipant * pParticipant, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TParticipantSelectFunc)(CParticipant * pParticipant,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CParticipantIterator *pIterator, TParticipantActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CParticipantIterator *pIterator, TParticipantUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CParticipantIterator *pIterator, TParticipantSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserActionFunc)(CUser * pUser, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserUpdateFunc)(CWriteableUser * pUser, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserSelectFunc)(CUser * pUser,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CUserIterator *pIterator, TUserActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CUserIterator *pIterator, TUserUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CUserIterator *pIterator, TUserSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientActionFunc)(CClient * pClient, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientUpdateFunc)(CWriteableClient * pClient, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientSelectFunc)(CClient * pClient,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CClientIterator *pIterator, TClientActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CClientIterator *pIterator, TClientUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CClientIterator *pIterator, TClientSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserIPActionFunc)(CUserIP * pUserIP, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserIPUpdateFunc)(CWriteableUserIP * pUserIP, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserIPSelectFunc)(CUserIP * pUserIP,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CUserIPIterator *pIterator, TUserIPActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CUserIPIterator *pIterator, TUserIPUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CUserIPIterator *pIterator, TUserIPSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientActionFunc)(CPartClient * pPartClient, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientUpdateFunc)(CWriteablePartClient * pPartClient, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientSelectFunc)(CPartClient * pPartClient,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartClientIterator *pIterator, TPartClientActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartClientIterator *pIterator, TPartClientUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartClientIterator *pIterator, TPartClientSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClearingTradingPartActionFunc)(CClearingTradingPart * pClearingTradingPart, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClearingTradingPartUpdateFunc)(CWriteableClearingTradingPart * pClearingTradingPart, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClearingTradingPartSelectFunc)(CClearingTradingPart * pClearingTradingPart,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CClearingTradingPartIterator *pIterator, TClearingTradingPartActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CClearingTradingPartIterator *pIterator, TClearingTradingPartUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CClearingTradingPartIterator *pIterator, TClearingTradingPartSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TAliasDefineActionFunc)(CAliasDefine * pAliasDefine, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TAliasDefineUpdateFunc)(CWriteableAliasDefine * pAliasDefine, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TAliasDefineSelectFunc)(CAliasDefine * pAliasDefine,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CAliasDefineIterator *pIterator, TAliasDefineActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CAliasDefineIterator *pIterator, TAliasDefineUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CAliasDefineIterator *pIterator, TAliasDefineSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserFunctionRightActionFunc)(CUserFunctionRight * pUserFunctionRight, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserFunctionRightUpdateFunc)(CWriteableUserFunctionRight * pUserFunctionRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserFunctionRightSelectFunc)(CUserFunctionRight * pUserFunctionRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CUserFunctionRightIterator *pIterator, TUserFunctionRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CUserFunctionRightIterator *pIterator, TUserFunctionRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CUserFunctionRightIterator *pIterator, TUserFunctionRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TAccountActionFunc)(CAccount * pAccount, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TAccountUpdateFunc)(CWriteableAccount * pAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TAccountSelectFunc)(CAccount * pAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CAccountIterator *pIterator, TAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CAccountIterator *pIterator, TAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CAccountIterator *pIterator, TAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserCommFluxActionFunc)(CUserCommFlux * pUserCommFlux, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserCommFluxUpdateFunc)(CWriteableUserCommFlux * pUserCommFlux, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserCommFluxSelectFunc)(CUserCommFlux * pUserCommFlux,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CUserCommFluxIterator *pIterator, TUserCommFluxActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CUserCommFluxIterator *pIterator, TUserCommFluxUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CUserCommFluxIterator *pIterator, TUserCommFluxSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataLogActionFunc)(CMarketDataLog * pMarketDataLog, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataLogUpdateFunc)(CWriteableMarketDataLog * pMarketDataLog, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataLogSelectFunc)(CMarketDataLog * pMarketDataLog,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMarketDataLogIterator *pIterator, TMarketDataLogActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMarketDataLogIterator *pIterator, TMarketDataLogUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMarketDataLogIterator *pIterator, TMarketDataLogSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserSessionActionFunc)(CUserSession * pUserSession, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserSessionUpdateFunc)(CWriteableUserSession * pUserSession, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUserSessionSelectFunc)(CUserSession * pUserSession,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CUserSessionIterator *pIterator, TUserSessionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CUserSessionIterator *pIterator, TUserSessionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CUserSessionIterator *pIterator, TUserSessionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMDSessionActionFunc)(CMDSession * pMDSession, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMDSessionUpdateFunc)(CWriteableMDSession * pMDSession, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMDSessionSelectFunc)(CMDSession * pMDSession,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMDSessionIterator *pIterator, TMDSessionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMDSessionIterator *pIterator, TMDSessionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMDSessionIterator *pIterator, TMDSessionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TLoginInfoActionFunc)(CLoginInfo * pLoginInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TLoginInfoUpdateFunc)(CWriteableLoginInfo * pLoginInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TLoginInfoSelectFunc)(CLoginInfo * pLoginInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CLoginInfoIterator *pIterator, TLoginInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CLoginInfoIterator *pIterator, TLoginInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CLoginInfoIterator *pIterator, TLoginInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDepthMarketDataDetailActionFunc)(CDepthMarketDataDetail * pDepthMarketDataDetail, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDepthMarketDataDetailUpdateFunc)(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDepthMarketDataDetailSelectFunc)(CDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentStatusDetailActionFunc)(CInstrumentStatusDetail * pInstrumentStatusDetail, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentStatusDetailUpdateFunc)(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentStatusDetailSelectFunc)(CInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TFrontStatusActionFunc)(CFrontStatus * pFrontStatus, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TFrontStatusUpdateFunc)(CWriteableFrontStatus * pFrontStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TFrontStatusSelectFunc)(CFrontStatus * pFrontStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CFrontStatusIterator *pIterator, TFrontStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CFrontStatusIterator *pIterator, TFrontStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CFrontStatusIterator *pIterator, TFrontStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMaxLocalIDActionFunc)(CMaxLocalID * pMaxLocalID, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMaxLocalIDUpdateFunc)(CWriteableMaxLocalID * pMaxLocalID, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMaxLocalIDSelectFunc)(CMaxLocalID * pMaxLocalID,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMaxLocalIDIterator *pIterator, TMaxLocalIDActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMaxLocalIDIterator *pIterator, TMaxLocalIDUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMaxLocalIDIterator *pIterator, TMaxLocalIDSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBulletinActionFunc)(CBulletin * pBulletin, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBulletinUpdateFunc)(CWriteableBulletin * pBulletin, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBulletinSelectFunc)(CBulletin * pBulletin,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CBulletinIterator *pIterator, TBulletinActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CBulletinIterator *pIterator, TBulletinUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CBulletinIterator *pIterator, TBulletinSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataModifyActionFunc)(CMarketDataModify * pMarketDataModify, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataModifyUpdateFunc)(CWriteableMarketDataModify * pMarketDataModify, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataModifySelectFunc)(CMarketDataModify * pMarketDataModify,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMarketDataModifyIterator *pIterator, TMarketDataModifyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMarketDataModifyIterator *pIterator, TMarketDataModifyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMarketDataModifyIterator *pIterator, TMarketDataModifySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDepthMarketDataActionFunc)(CDepthMarketData * pDepthMarketData, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDepthMarketDataUpdateFunc)(CWriteableDepthMarketData * pDepthMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TDepthMarketDataSelectFunc)(CDepthMarketData * pDepthMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CDepthMarketDataIterator *pIterator, TDepthMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CDepthMarketDataIterator *pIterator, TDepthMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CDepthMarketDataIterator *pIterator, TDepthMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTopicMarketDataActionFunc)(CTopicMarketData * pTopicMarketData, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTopicMarketDataUpdateFunc)(CWriteableTopicMarketData * pTopicMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTopicMarketDataSelectFunc)(CTopicMarketData * pTopicMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CTopicMarketDataIterator *pIterator, TTopicMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CTopicMarketDataIterator *pIterator, TTopicMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CTopicMarketDataIterator *pIterator, TTopicMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTopicMarketDataVersionActionFunc)(CTopicMarketDataVersion * pTopicMarketDataVersion, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTopicMarketDataVersionUpdateFunc)(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTopicMarketDataVersionSelectFunc)(CTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInformationActionFunc)(CInformation * pInformation, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInformationUpdateFunc)(CWriteableInformation * pInformation, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInformationSelectFunc)(CInformation * pInformation,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CInformationIterator *pIterator, TInformationActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CInformationIterator *pIterator, TInformationUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CInformationIterator *pIterator, TInformationSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOrderCountActionFunc)(COrderCount * pOrderCount, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOrderCountUpdateFunc)(CWriteableOrderCount * pOrderCount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOrderCountSelectFunc)(COrderCount * pOrderCount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(COrderCountIterator *pIterator, TOrderCountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(COrderCountIterator *pIterator, TOrderCountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(COrderCountIterator *pIterator, TOrderCountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentActionFunc)(CInstrument * pInstrument, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentUpdateFunc)(CWriteableInstrument * pInstrument, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentSelectFunc)(CInstrument * pInstrument,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CInstrumentIterator *pIterator, TInstrumentActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CInstrumentIterator *pIterator, TInstrumentUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CInstrumentIterator *pIterator, TInstrumentSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCombinationLegActionFunc)(CCombinationLeg * pCombinationLeg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCombinationLegUpdateFunc)(CWriteableCombinationLeg * pCombinationLeg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCombinationLegSelectFunc)(CCombinationLeg * pCombinationLeg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCombinationLegIterator *pIterator, TCombinationLegActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCombinationLegIterator *pIterator, TCombinationLegUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCombinationLegIterator *pIterator, TCombinationLegSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartRoleAccountActionFunc)(CPartRoleAccount * pPartRoleAccount, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartRoleAccountUpdateFunc)(CWriteablePartRoleAccount * pPartRoleAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartRoleAccountSelectFunc)(CPartRoleAccount * pPartRoleAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartRoleAccountIterator *pIterator, TPartRoleAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartRoleAccountIterator *pIterator, TPartRoleAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartRoleAccountIterator *pIterator, TPartRoleAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartProductRoleActionFunc)(CPartProductRole * pPartProductRole, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartProductRoleUpdateFunc)(CWriteablePartProductRole * pPartProductRole, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartProductRoleSelectFunc)(CPartProductRole * pPartProductRole,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartProductRoleIterator *pIterator, TPartProductRoleActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartProductRoleIterator *pIterator, TPartProductRoleUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartProductRoleIterator *pIterator, TPartProductRoleSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartProductRightActionFunc)(CPartProductRight * pPartProductRight, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartProductRightUpdateFunc)(CWriteablePartProductRight * pPartProductRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartProductRightSelectFunc)(CPartProductRight * pPartProductRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartProductRightIterator *pIterator, TPartProductRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartProductRightIterator *pIterator, TPartProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartProductRightIterator *pIterator, TPartProductRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartInstrumentRightActionFunc)(CPartInstrumentRight * pPartInstrumentRight, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartInstrumentRightUpdateFunc)(CWriteablePartInstrumentRight * pPartInstrumentRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartInstrumentRightSelectFunc)(CPartInstrumentRight * pPartInstrumentRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientProductRightActionFunc)(CClientProductRight * pClientProductRight, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientProductRightUpdateFunc)(CWriteableClientProductRight * pClientProductRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientProductRightSelectFunc)(CClientProductRight * pClientProductRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CClientProductRightIterator *pIterator, TClientProductRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CClientProductRightIterator *pIterator, TClientProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CClientProductRightIterator *pIterator, TClientProductRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientInstrumentRightActionFunc)(CClientInstrumentRight * pClientInstrumentRight, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientInstrumentRightUpdateFunc)(CWriteableClientInstrumentRight * pClientInstrumentRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientInstrumentRightSelectFunc)(CClientInstrumentRight * pClientInstrumentRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientProductRightActionFunc)(CPartClientProductRight * pPartClientProductRight, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientProductRightUpdateFunc)(CWriteablePartClientProductRight * pPartClientProductRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientProductRightSelectFunc)(CPartClientProductRight * pPartClientProductRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartClientProductRightIterator *pIterator, TPartClientProductRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartClientProductRightIterator *pIterator, TPartClientProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartClientProductRightIterator *pIterator, TPartClientProductRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientInstrumentRightActionFunc)(CPartClientInstrumentRight * pPartClientInstrumentRight, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientInstrumentRightUpdateFunc)(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartClientInstrumentRightSelectFunc)(CPartClientInstrumentRight * pPartClientInstrumentRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrProductPropertyActionFunc)(CCurrProductProperty * pCurrProductProperty, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrProductPropertyUpdateFunc)(CWriteableCurrProductProperty * pCurrProductProperty, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrProductPropertySelectFunc)(CCurrProductProperty * pCurrProductProperty,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrProductPropertyIterator *pIterator, TCurrProductPropertyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrProductPropertyIterator *pIterator, TCurrProductPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrProductPropertyIterator *pIterator, TCurrProductPropertySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrInstrumentPropertyActionFunc)(CCurrInstrumentProperty * pCurrInstrumentProperty, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrInstrumentPropertyUpdateFunc)(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrInstrumentPropertySelectFunc)(CCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPriceBandingActionFunc)(CCurrPriceBanding * pCurrPriceBanding, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPriceBandingUpdateFunc)(CWriteableCurrPriceBanding * pCurrPriceBanding, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPriceBandingSelectFunc)(CCurrPriceBanding * pCurrPriceBanding,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrMarginRateActionFunc)(CCurrMarginRate * pCurrMarginRate, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrMarginRateUpdateFunc)(CWriteableCurrMarginRate * pCurrMarginRate, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrMarginRateSelectFunc)(CCurrMarginRate * pCurrMarginRate,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrMarginRateIterator *pIterator, TCurrMarginRateActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrMarginRateIterator *pIterator, TCurrMarginRateUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrMarginRateIterator *pIterator, TCurrMarginRateSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrMarginRateDetailActionFunc)(CCurrMarginRateDetail * pCurrMarginRateDetail, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrMarginRateDetailUpdateFunc)(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrMarginRateDetailSelectFunc)(CCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPartPosiLimitActionFunc)(CCurrPartPosiLimit * pCurrPartPosiLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPartPosiLimitUpdateFunc)(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPartPosiLimitSelectFunc)(CCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPartPosiLimitDetailActionFunc)(CCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPartPosiLimitDetailUpdateFunc)(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrPartPosiLimitDetailSelectFunc)(CCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrClientPosiLimitActionFunc)(CCurrClientPosiLimit * pCurrClientPosiLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrClientPosiLimitUpdateFunc)(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrClientPosiLimitSelectFunc)(CCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrClientPosiLimitDetailActionFunc)(CCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrClientPosiLimitDetailUpdateFunc)(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrClientPosiLimitDetailSelectFunc)(CCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrSpecialPosiLimitActionFunc)(CCurrSpecialPosiLimit * pCurrSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrSpecialPosiLimitUpdateFunc)(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrSpecialPosiLimitSelectFunc)(CCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrSpecialPosiLimitDetailActionFunc)(CCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrSpecialPosiLimitDetailUpdateFunc)(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrSpecialPosiLimitDetailSelectFunc)(CCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrHedgeRuleActionFunc)(CCurrHedgeRule * pCurrHedgeRule, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrHedgeRuleUpdateFunc)(CWriteableCurrHedgeRule * pCurrHedgeRule, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrHedgeRuleSelectFunc)(CCurrHedgeRule * pCurrHedgeRule,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrTradingSegmentAttrActionFunc)(CCurrTradingSegmentAttr * pCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrTradingSegmentAttrUpdateFunc)(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrTradingSegmentAttrSelectFunc)(CCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrFuseActionFunc)(CCurrFuse * pCurrFuse, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrFuseUpdateFunc)(CWriteableCurrFuse * pCurrFuse, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrFuseSelectFunc)(CCurrFuse * pCurrFuse,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrFuseIterator *pIterator, TCurrFuseActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrFuseIterator *pIterator, TCurrFuseUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrFuseIterator *pIterator, TCurrFuseSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTradingAccountActionFunc)(CTradingAccount * pTradingAccount, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTradingAccountUpdateFunc)(CWriteableTradingAccount * pTradingAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTradingAccountSelectFunc)(CTradingAccount * pTradingAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CTradingAccountIterator *pIterator, TTradingAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CTradingAccountIterator *pIterator, TTradingAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CTradingAccountIterator *pIterator, TTradingAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBaseReserveAccountActionFunc)(CBaseReserveAccount * pBaseReserveAccount, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBaseReserveAccountUpdateFunc)(CWriteableBaseReserveAccount * pBaseReserveAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBaseReserveAccountSelectFunc)(CBaseReserveAccount * pBaseReserveAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartPositionActionFunc)(CPartPosition * pPartPosition, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartPositionUpdateFunc)(CWriteablePartPosition * pPartPosition, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TPartPositionSelectFunc)(CPartPosition * pPartPosition,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CPartPositionIterator *pIterator, TPartPositionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CPartPositionIterator *pIterator, TPartPositionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CPartPositionIterator *pIterator, TPartPositionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientPositionActionFunc)(CClientPosition * pClientPosition, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientPositionUpdateFunc)(CWriteableClientPosition * pClientPosition, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClientPositionSelectFunc)(CClientPosition * pClientPosition,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CClientPositionIterator *pIterator, TClientPositionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CClientPositionIterator *pIterator, TClientPositionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CClientPositionIterator *pIterator, TClientPositionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* THedgeVolumeActionFunc)(CHedgeVolume * pHedgeVolume, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* THedgeVolumeUpdateFunc)(CWriteableHedgeVolume * pHedgeVolume, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* THedgeVolumeSelectFunc)(CHedgeVolume * pHedgeVolume,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CHedgeVolumeIterator *pIterator, THedgeVolumeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CHedgeVolumeIterator *pIterator, THedgeVolumeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CHedgeVolumeIterator *pIterator, THedgeVolumeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRemainOrderActionFunc)(CRemainOrder * pRemainOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRemainOrderUpdateFunc)(CWriteableRemainOrder * pRemainOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRemainOrderSelectFunc)(CRemainOrder * pRemainOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRemainOrderIterator *pIterator, TRemainOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRemainOrderIterator *pIterator, TRemainOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRemainOrderIterator *pIterator, TRemainOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataActionFunc)(CMarketData * pMarketData, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataUpdateFunc)(CWriteableMarketData * pMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMarketDataSelectFunc)(CMarketData * pMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMarketDataIterator *pIterator, TMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMarketDataIterator *pIterator, TMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMarketDataIterator *pIterator, TMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClearingPartPositionActionFunc)(CClearingPartPosition * pClearingPartPosition, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClearingPartPositionUpdateFunc)(CWriteableClearingPartPosition * pClearingPartPosition, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TClearingPartPositionSelectFunc)(CClearingPartPosition * pClearingPartPosition,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CClearingPartPositionIterator *pIterator, TClearingPartPositionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CClearingPartPositionIterator *pIterator, TClearingPartPositionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CClearingPartPositionIterator *pIterator, TClearingPartPositionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentStatusActionFunc)(CInstrumentStatus * pInstrumentStatus, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentStatusUpdateFunc)(CWriteableInstrumentStatus * pInstrumentStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TInstrumentStatusSelectFunc)(CInstrumentStatus * pInstrumentStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CInstrumentStatusIterator *pIterator, TInstrumentStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CInstrumentStatusIterator *pIterator, TInstrumentStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CInstrumentStatusIterator *pIterator, TInstrumentStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOrderActionFunc)(COrder * pOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOrderUpdateFunc)(CWriteableOrder * pOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOrderSelectFunc)(COrder * pOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(COrderIterator *pIterator, TOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(COrderIterator *pIterator, TOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(COrderIterator *pIterator, TOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCombOrderActionFunc)(CCombOrder * pCombOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCombOrderUpdateFunc)(CWriteableCombOrder * pCombOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCombOrderSelectFunc)(CCombOrder * pCombOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCombOrderIterator *pIterator, TCombOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCombOrderIterator *pIterator, TCombOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCombOrderIterator *pIterator, TCombOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOTCOrderActionFunc)(COTCOrder * pOTCOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOTCOrderUpdateFunc)(CWriteableOTCOrder * pOTCOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TOTCOrderSelectFunc)(COTCOrder * pOTCOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(COTCOrderIterator *pIterator, TOTCOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(COTCOrderIterator *pIterator, TOTCOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(COTCOrderIterator *pIterator, TOTCOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TImplyOrderActionFunc)(CImplyOrder * pImplyOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TImplyOrderUpdateFunc)(CWriteableImplyOrder * pImplyOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TImplyOrderSelectFunc)(CImplyOrder * pImplyOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CImplyOrderIterator *pIterator, TImplyOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CImplyOrderIterator *pIterator, TImplyOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CImplyOrderIterator *pIterator, TImplyOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TQuoteActionFunc)(CQuote * pQuote, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TQuoteUpdateFunc)(CWriteableQuote * pQuote, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TQuoteSelectFunc)(CQuote * pQuote,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CQuoteIterator *pIterator, TQuoteActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CQuoteIterator *pIterator, TQuoteUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CQuoteIterator *pIterator, TQuoteSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMBLMarketDataActionFunc)(CMBLMarketData * pMBLMarketData, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMBLMarketDataUpdateFunc)(CWriteableMBLMarketData * pMBLMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMBLMarketDataSelectFunc)(CMBLMarketData * pMBLMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMBLMarketDataIterator *pIterator, TMBLMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMBLMarketDataIterator *pIterator, TMBLMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMBLMarketDataIterator *pIterator, TMBLMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTradeActionFunc)(CTrade * pTrade, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTradeUpdateFunc)(CWriteableTrade * pTrade, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TTradeSelectFunc)(CTrade * pTrade,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CTradeIterator *pIterator, TTradeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CTradeIterator *pIterator, TTradeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CTradeIterator *pIterator, TTradeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TFusePhaseActionFunc)(CFusePhase * pFusePhase, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TFusePhaseUpdateFunc)(CWriteableFusePhase * pFusePhase, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TFusePhaseSelectFunc)(CFusePhase * pFusePhase,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CFusePhaseIterator *pIterator, TFusePhaseActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CFusePhaseIterator *pIterator, TFusePhaseUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CFusePhaseIterator *pIterator, TFusePhaseSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExecOrderActionFunc)(CExecOrder * pExecOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExecOrderUpdateFunc)(CWriteableExecOrder * pExecOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TExecOrderSelectFunc)(CExecOrder * pExecOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CExecOrderIterator *pIterator, TExecOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CExecOrderIterator *pIterator, TExecOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CExecOrderIterator *pIterator, TExecOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUniPressureActionFunc)(CUniPressure * pUniPressure, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUniPressureUpdateFunc)(CWriteableUniPressure * pUniPressure, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TUniPressureSelectFunc)(CUniPressure * pUniPressure,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CUniPressureIterator *pIterator, TUniPressureActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CUniPressureIterator *pIterator, TUniPressureUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CUniPressureIterator *pIterator, TUniPressureSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBasePriceLimitActionFunc)(CBasePriceLimit * pBasePriceLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBasePriceLimitUpdateFunc)(CWriteableBasePriceLimit * pBasePriceLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TBasePriceLimitSelectFunc)(CBasePriceLimit * pBasePriceLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CBasePriceLimitIterator *pIterator, TBasePriceLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CBasePriceLimitIterator *pIterator, TBasePriceLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CBasePriceLimitIterator *pIterator, TBasePriceLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCreditLimitActionFunc)(CCreditLimit * pCreditLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCreditLimitUpdateFunc)(CWriteableCreditLimit * pCreditLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCreditLimitSelectFunc)(CCreditLimit * pCreditLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCreditLimitIterator *pIterator, TCreditLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCreditLimitIterator *pIterator, TCreditLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCreditLimitIterator *pIterator, TCreditLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrInstrumentOptionActionFunc)(CCurrInstrumentOption * pCurrInstrumentOption, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrInstrumentOptionUpdateFunc)(CWriteableCurrInstrumentOption * pCurrInstrumentOption, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TCurrInstrumentOptionSelectFunc)(CCurrInstrumentOption * pCurrInstrumentOption,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

#endif
