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
typedef int (* TSysInvalidateOrderActionFunc)(CSysInvalidateOrder * pSysInvalidateOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInvalidateOrderUpdateFunc)(CWriteableSysInvalidateOrder * pSysInvalidateOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInvalidateOrderSelectFunc)(CSysInvalidateOrder * pSysInvalidateOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysOrderStatusActionFunc)(CSysOrderStatus * pSysOrderStatus, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysOrderStatusUpdateFunc)(CWriteableSysOrderStatus * pSysOrderStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysOrderStatusSelectFunc)(CSysOrderStatus * pSysOrderStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysOrderStatusIterator *pIterator, TSysOrderStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysOrderStatusIterator *pIterator, TSysOrderStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysOrderStatusIterator *pIterator, TSysOrderStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysBargainOrderActionFunc)(CSysBargainOrder * pSysBargainOrder, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysBargainOrderUpdateFunc)(CWriteableSysBargainOrder * pSysBargainOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysBargainOrderSelectFunc)(CSysBargainOrder * pSysBargainOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysBargainOrderIterator *pIterator, TSysBargainOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysBargainOrderIterator *pIterator, TSysBargainOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysBargainOrderIterator *pIterator, TSysBargainOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInstPropertyActionFunc)(CSysInstProperty * pSysInstProperty, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInstPropertyUpdateFunc)(CWriteableSysInstProperty * pSysInstProperty, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInstPropertySelectFunc)(CSysInstProperty * pSysInstProperty,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysInstPropertyIterator *pIterator, TSysInstPropertyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysInstPropertyIterator *pIterator, TSysInstPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysInstPropertyIterator *pIterator, TSysInstPropertySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMarginRateActionFunc)(CSysMarginRate * pSysMarginRate, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMarginRateUpdateFunc)(CWriteableSysMarginRate * pSysMarginRate, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMarginRateSelectFunc)(CSysMarginRate * pSysMarginRate,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMarginRateIterator *pIterator, TSysMarginRateActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMarginRateIterator *pIterator, TSysMarginRateUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMarginRateIterator *pIterator, TSysMarginRateSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPriceLimitActionFunc)(CSysPriceLimit * pSysPriceLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPriceLimitUpdateFunc)(CWriteableSysPriceLimit * pSysPriceLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPriceLimitSelectFunc)(CSysPriceLimit * pSysPriceLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysPriceLimitIterator *pIterator, TSysPriceLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysPriceLimitIterator *pIterator, TSysPriceLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysPriceLimitIterator *pIterator, TSysPriceLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartPosiLimitActionFunc)(CSysPartPosiLimit * pSysPartPosiLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartPosiLimitUpdateFunc)(CWriteableSysPartPosiLimit * pSysPartPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartPosiLimitSelectFunc)(CSysPartPosiLimit * pSysPartPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientPosiLimitActionFunc)(CSysClientPosiLimit * pSysClientPosiLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientPosiLimitUpdateFunc)(CWriteableSysClientPosiLimit * pSysClientPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientPosiLimitSelectFunc)(CSysClientPosiLimit * pSysClientPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysSpecialPosiLimitActionFunc)(CSysSpecialPosiLimit * pSysSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysSpecialPosiLimitUpdateFunc)(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysSpecialPosiLimitSelectFunc)(CSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysTransactionChgActionFunc)(CSysTransactionChg * pSysTransactionChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysTransactionChgUpdateFunc)(CWriteableSysTransactionChg * pSysTransactionChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysTransactionChgSelectFunc)(CSysTransactionChg * pSysTransactionChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysTransactionChgIterator *pIterator, TSysTransactionChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysTransactionChgIterator *pIterator, TSysTransactionChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysTransactionChgIterator *pIterator, TSysTransactionChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientChgActionFunc)(CSysClientChg * pSysClientChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientChgUpdateFunc)(CWriteableSysClientChg * pSysClientChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientChgSelectFunc)(CSysClientChg * pSysClientChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysClientChgIterator *pIterator, TSysClientChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysClientChgIterator *pIterator, TSysClientChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysClientChgIterator *pIterator, TSysClientChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartClientChgActionFunc)(CSysPartClientChg * pSysPartClientChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartClientChgUpdateFunc)(CWriteableSysPartClientChg * pSysPartClientChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartClientChgSelectFunc)(CSysPartClientChg * pSysPartClientChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysPartClientChgIterator *pIterator, TSysPartClientChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysPartClientChgIterator *pIterator, TSysPartClientChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysPartClientChgIterator *pIterator, TSysPartClientChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPosiLimitChgActionFunc)(CSysPosiLimitChg * pSysPosiLimitChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPosiLimitChgUpdateFunc)(CWriteableSysPosiLimitChg * pSysPosiLimitChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPosiLimitChgSelectFunc)(CSysPosiLimitChg * pSysPosiLimitChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientPosiLimitChgActionFunc)(CSysClientPosiLimitChg * pSysClientPosiLimitChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientPosiLimitChgUpdateFunc)(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientPosiLimitChgSelectFunc)(CSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysSpecPosiLimitChgActionFunc)(CSysSpecPosiLimitChg * pSysSpecPosiLimitChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysSpecPosiLimitChgUpdateFunc)(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysSpecPosiLimitChgSelectFunc)(CSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysHedgeDetailChgActionFunc)(CSysHedgeDetailChg * pSysHedgeDetailChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysHedgeDetailChgUpdateFunc)(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysHedgeDetailChgSelectFunc)(CSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticipantChgActionFunc)(CSysParticipantChg * pSysParticipantChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticipantChgUpdateFunc)(CWriteableSysParticipantChg * pSysParticipantChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticipantChgSelectFunc)(CSysParticipantChg * pSysParticipantChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysParticipantChgIterator *pIterator, TSysParticipantChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysParticipantChgIterator *pIterator, TSysParticipantChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysParticipantChgIterator *pIterator, TSysParticipantChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMarginRateChgActionFunc)(CSysMarginRateChg * pSysMarginRateChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMarginRateChgUpdateFunc)(CWriteableSysMarginRateChg * pSysMarginRateChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMarginRateChgSelectFunc)(CSysMarginRateChg * pSysMarginRateChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserIpChgActionFunc)(CSysUserIpChg * pSysUserIpChg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserIpChgUpdateFunc)(CWriteableSysUserIpChg * pSysUserIpChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserIpChgSelectFunc)(CSysUserIpChg * pSysUserIpChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysUserIpChgIterator *pIterator, TSysUserIpChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysUserIpChgIterator *pIterator, TSysUserIpChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysUserIpChgIterator *pIterator, TSysUserIpChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartTradeActionFunc)(CSysPartTrade * pSysPartTrade, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartTradeUpdateFunc)(CWriteableSysPartTrade * pSysPartTrade, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysPartTradeSelectFunc)(CSysPartTrade * pSysPartTrade,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysPartTradeIterator *pIterator, TSysPartTradeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysPartTradeIterator *pIterator, TSysPartTradeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysPartTradeIterator *pIterator, TSysPartTradeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbObjectAttrActionFunc)(CSysMdbObjectAttr * pSysMdbObjectAttr, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbObjectAttrUpdateFunc)(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbObjectAttrSelectFunc)(CSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbSyslogInfoActionFunc)(CSysMdbSyslogInfo * pSysMdbSyslogInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbSyslogInfoUpdateFunc)(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbSyslogInfoSelectFunc)(CSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserInfoActionFunc)(CSysUserInfo * pSysUserInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserInfoUpdateFunc)(CWriteableSysUserInfo * pSysUserInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserInfoSelectFunc)(CSysUserInfo * pSysUserInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysUserInfoIterator *pIterator, TSysUserInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysUserInfoIterator *pIterator, TSysUserInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysUserInfoIterator *pIterator, TSysUserInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysOnlineUserInfoActionFunc)(CSysOnlineUserInfo * pSysOnlineUserInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysOnlineUserInfoUpdateFunc)(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysOnlineUserInfoSelectFunc)(CSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysWarningEventActionFunc)(CSysWarningEvent * pSysWarningEvent, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysWarningEventUpdateFunc)(CWriteableSysWarningEvent * pSysWarningEvent, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysWarningEventSelectFunc)(CSysWarningEvent * pSysWarningEvent,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysWarningEventIterator *pIterator, TSysWarningEventActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysWarningEventIterator *pIterator, TSysWarningEventUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysWarningEventIterator *pIterator, TSysWarningEventSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysWarningQueryActionFunc)(CSysWarningQuery * pSysWarningQuery, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysWarningQueryUpdateFunc)(CWriteableSysWarningQuery * pSysWarningQuery, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysWarningQuerySelectFunc)(CSysWarningQuery * pSysWarningQuery,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysWarningQueryIterator *pIterator, TSysWarningQueryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysWarningQueryIterator *pIterator, TSysWarningQueryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysWarningQueryIterator *pIterator, TSysWarningQuerySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSyslogEventActionFunc)(CSyslogEvent * pSyslogEvent, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSyslogEventUpdateFunc)(CWriteableSyslogEvent * pSyslogEvent, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSyslogEventSelectFunc)(CSyslogEvent * pSyslogEvent,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSyslogEventIterator *pIterator, TSyslogEventActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSyslogEventIterator *pIterator, TSyslogEventUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSyslogEventIterator *pIterator, TSyslogEventSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysEventDescripActionFunc)(CSysEventDescrip * pSysEventDescrip, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysEventDescripUpdateFunc)(CWriteableSysEventDescrip * pSysEventDescrip, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysEventDescripSelectFunc)(CSysEventDescrip * pSysEventDescrip,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysEventDescripIterator *pIterator, TSysEventDescripActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysEventDescripIterator *pIterator, TSysEventDescripUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysEventDescripIterator *pIterator, TSysEventDescripSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvCommonActionFunc)(CRspQryHostEnvCommon * pRspQryHostEnvCommon, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvCommonUpdateFunc)(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvCommonSelectFunc)(CRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvLanActionFunc)(CRspQryHostEnvLan * pRspQryHostEnvLan, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvLanUpdateFunc)(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvLanSelectFunc)(CRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvStorageActionFunc)(CRspQryHostEnvStorage * pRspQryHostEnvStorage, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvStorageUpdateFunc)(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvStorageSelectFunc)(CRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvIOActionFunc)(CRspQryHostEnvIO * pRspQryHostEnvIO, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvIOUpdateFunc)(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvIOSelectFunc)(CRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvFSActionFunc)(CRspQryHostEnvFS * pRspQryHostEnvFS, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvFSUpdateFunc)(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvFSSelectFunc)(CRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvSwapActionFunc)(CRspQryHostEnvSwap * pRspQryHostEnvSwap, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvSwapUpdateFunc)(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvSwapSelectFunc)(CRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvLanCfgActionFunc)(CRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvLanCfgUpdateFunc)(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TRspQryHostEnvLanCfgSelectFunc)(CRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopCpuInfoActionFunc)(CSysMdbTopCpuInfo * pSysMdbTopCpuInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopCpuInfoUpdateFunc)(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopCpuInfoSelectFunc)(CSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopMemInfoActionFunc)(CSysMdbTopMemInfo * pSysMdbTopMemInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopMemInfoUpdateFunc)(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopMemInfoSelectFunc)(CSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopProcessInfoActionFunc)(CSysMdbTopProcessInfo * pSysMdbTopProcessInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopProcessInfoUpdateFunc)(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTopProcessInfoSelectFunc)(CSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbFileSystemInfoActionFunc)(CSysMdbFileSystemInfo * pSysMdbFileSystemInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbFileSystemInfoUpdateFunc)(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbFileSystemInfoSelectFunc)(CSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbNetworkInfoActionFunc)(CSysMdbNetworkInfo * pSysMdbNetworkInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbNetworkInfoUpdateFunc)(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbNetworkInfoSelectFunc)(CSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticipantInitActionFunc)(CSysParticipantInit * pSysParticipantInit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticipantInitUpdateFunc)(CWriteableSysParticipantInit * pSysParticipantInit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticipantInitSelectFunc)(CSysParticipantInit * pSysParticipantInit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysParticipantInitIterator *pIterator, TSysParticipantInitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysParticipantInitIterator *pIterator, TSysParticipantInitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysParticipantInitIterator *pIterator, TSysParticipantInitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserInitActionFunc)(CSysUserInit * pSysUserInit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserInitUpdateFunc)(CWriteableSysUserInit * pSysUserInit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysUserInitSelectFunc)(CSysUserInit * pSysUserInit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysUserInitIterator *pIterator, TSysUserInitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysUserInitIterator *pIterator, TSysUserInitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysUserInitIterator *pIterator, TSysUserInitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientInitActionFunc)(CSysClientInit * pSysClientInit, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientInitUpdateFunc)(CWriteableSysClientInit * pSysClientInit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysClientInitSelectFunc)(CSysClientInit * pSysClientInit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysClientInitIterator *pIterator, TSysClientInitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysClientInitIterator *pIterator, TSysClientInitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysClientInitIterator *pIterator, TSysClientInitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysTradeUserLoginInfoActionFunc)(CSysTradeUserLoginInfo * pSysTradeUserLoginInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysTradeUserLoginInfoUpdateFunc)(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysTradeUserLoginInfoSelectFunc)(CSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbWebAppInfoActionFunc)(CSysMdbWebAppInfo * pSysMdbWebAppInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbWebAppInfoUpdateFunc)(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbWebAppInfoSelectFunc)(CSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbMemPoolInfoActionFunc)(CSysMdbMemPoolInfo * pSysMdbMemPoolInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbMemPoolInfoUpdateFunc)(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbMemPoolInfoSelectFunc)(CSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbConnectorInfoActionFunc)(CSysMdbConnectorInfo * pSysMdbConnectorInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbConnectorInfoUpdateFunc)(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbConnectorInfoSelectFunc)(CSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbDBQueryActionFunc)(CSysMdbDBQuery * pSysMdbDBQuery, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbDBQueryUpdateFunc)(CWriteableSysMdbDBQuery * pSysMdbDBQuery, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbDBQuerySelectFunc)(CSysMdbDBQuery * pSysMdbDBQuery,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQueryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQueryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQuerySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetAreaActionFunc)(CSysNetArea * pSysNetArea, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetAreaUpdateFunc)(CWriteableSysNetArea * pSysNetArea, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetAreaSelectFunc)(CSysNetArea * pSysNetArea,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetAreaIterator *pIterator, TSysNetAreaActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetAreaIterator *pIterator, TSysNetAreaUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetAreaIterator *pIterator, TSysNetAreaSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubAreaActionFunc)(CSysNetSubArea * pSysNetSubArea, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubAreaUpdateFunc)(CWriteableSysNetSubArea * pSysNetSubArea, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubAreaSelectFunc)(CSysNetSubArea * pSysNetSubArea,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubAreaIPActionFunc)(CSysNetSubAreaIP * pSysNetSubAreaIP, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubAreaIPUpdateFunc)(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubAreaIPSelectFunc)(CSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetFuncAreaActionFunc)(CSysNetFuncArea * pSysNetFuncArea, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetFuncAreaUpdateFunc)(CWriteableSysNetFuncArea * pSysNetFuncArea, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetFuncAreaSelectFunc)(CSysNetFuncArea * pSysNetFuncArea,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceActionFunc)(CSysNetDevice * pSysNetDevice, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceUpdateFunc)(CWriteableSysNetDevice * pSysNetDevice, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceSelectFunc)(CSysNetDevice * pSysNetDevice,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetDeviceIterator *pIterator, TSysNetDeviceActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetDeviceIterator *pIterator, TSysNetDeviceUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetDeviceIterator *pIterator, TSysNetDeviceSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceLinkedActionFunc)(CSysNetDeviceLinked * pSysNetDeviceLinked, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceLinkedUpdateFunc)(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceLinkedSelectFunc)(CSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetOIDActionFunc)(CSysNetOID * pSysNetOID, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetOIDUpdateFunc)(CWriteableSysNetOID * pSysNetOID, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetOIDSelectFunc)(CSysNetOID * pSysNetOID,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetOIDIterator *pIterator, TSysNetOIDActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetOIDIterator *pIterator, TSysNetOIDUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetOIDIterator *pIterator, TSysNetOIDSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceTypeActionFunc)(CSysNetDeviceType * pSysNetDeviceType, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceTypeUpdateFunc)(CWriteableSysNetDeviceType * pSysNetDeviceType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceTypeSelectFunc)(CSysNetDeviceType * pSysNetDeviceType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetTimePolicyActionFunc)(CSysNetTimePolicy * pSysNetTimePolicy, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetTimePolicyUpdateFunc)(CWriteableSysNetTimePolicy * pSysNetTimePolicy, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetTimePolicySelectFunc)(CSysNetTimePolicy * pSysNetTimePolicy,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetGatherTaskActionFunc)(CSysNetGatherTask * pSysNetGatherTask, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetGatherTaskUpdateFunc)(CWriteableSysNetGatherTask * pSysNetGatherTask, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetGatherTaskSelectFunc)(CSysNetGatherTask * pSysNetGatherTask,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceCategoryActionFunc)(CSysNetDeviceCategory * pSysNetDeviceCategory, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceCategoryUpdateFunc)(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDeviceCategorySelectFunc)(CSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategoryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategoryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategorySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetManufactoryActionFunc)(CSysNetManufactory * pSysNetManufactory, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetManufactoryUpdateFunc)(CWriteableSysNetManufactory * pSysNetManufactory, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetManufactorySelectFunc)(CSysNetManufactory * pSysNetManufactory,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetManufactoryIterator *pIterator, TSysNetManufactoryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetManufactoryIterator *pIterator, TSysNetManufactoryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetManufactoryIterator *pIterator, TSysNetManufactorySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetCommunityActionFunc)(CSysNetCommunity * pSysNetCommunity, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetCommunityUpdateFunc)(CWriteableSysNetCommunity * pSysNetCommunity, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetCommunitySelectFunc)(CSysNetCommunity * pSysNetCommunity,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetCommunityIterator *pIterator, TSysNetCommunityActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetCommunityIterator *pIterator, TSysNetCommunityUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetCommunityIterator *pIterator, TSysNetCommunitySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPortTypeActionFunc)(CSysNetPortType * pSysNetPortType, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPortTypeUpdateFunc)(CWriteableSysNetPortType * pSysNetPortType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPortTypeSelectFunc)(CSysNetPortType * pSysNetPortType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetInterfaceActionFunc)(CSysNetInterface * pSysNetInterface, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetInterfaceUpdateFunc)(CWriteableSysNetInterface * pSysNetInterface, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetInterfaceSelectFunc)(CSysNetInterface * pSysNetInterface,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetGeneralOIDActionFunc)(CSysNetGeneralOID * pSysNetGeneralOID, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetGeneralOIDUpdateFunc)(CWriteableSysNetGeneralOID * pSysNetGeneralOID, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetGeneralOIDSelectFunc)(CSysNetGeneralOID * pSysNetGeneralOID,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTypeActionFunc)(CSysNetMonitorType * pSysNetMonitorType, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTypeUpdateFunc)(CWriteableSysNetMonitorType * pSysNetMonitorType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTypeSelectFunc)(CSysNetMonitorType * pSysNetMonitorType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorAttrScopeActionFunc)(CSysNetMonitorAttrScope * pSysNetMonitorAttrScope, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorAttrScopeUpdateFunc)(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorAttrScopeSelectFunc)(CSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorAttrTypeActionFunc)(CSysNetMonitorAttrType * pSysNetMonitorAttrType, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorAttrTypeUpdateFunc)(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorAttrTypeSelectFunc)(CSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorCommandTypeActionFunc)(CSysNetMonitorCommandType * pSysNetMonitorCommandType, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorCommandTypeUpdateFunc)(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorCommandTypeSelectFunc)(CSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorActionGroupActionFunc)(CSysNetMonitorActionGroup * pSysNetMonitorActionGroup, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorActionGroupUpdateFunc)(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorActionGroupSelectFunc)(CSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorDeviceGroupActionFunc)(CSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorDeviceGroupUpdateFunc)(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorDeviceGroupSelectFunc)(CSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskInfoActionFunc)(CSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskInfoUpdateFunc)(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskInfoSelectFunc)(CSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskObjectSetActionFunc)(CSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskObjectSetUpdateFunc)(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskObjectSetSelectFunc)(CSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskResultActionFunc)(CSysNetMonitorTaskResult * pSysNetMonitorTaskResult, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskResultUpdateFunc)(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskResultSelectFunc)(CSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartyLinkInfoActionFunc)(CSysNetPartyLinkInfo * pSysNetPartyLinkInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartyLinkInfoUpdateFunc)(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartyLinkInfoSelectFunc)(CSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDelPartyLinkInfoActionFunc)(CSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDelPartyLinkInfoUpdateFunc)(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDelPartyLinkInfoSelectFunc)(CSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartyLinkAddrChangeActionFunc)(CSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartyLinkAddrChangeUpdateFunc)(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartyLinkAddrChangeSelectFunc)(CSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorActionAttrActionFunc)(CSysNetMonitorActionAttr * pSysNetMonitorActionAttr, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorActionAttrUpdateFunc)(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorActionAttrSelectFunc)(CSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetModuleActionFunc)(CSysNetModule * pSysNetModule, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetModuleUpdateFunc)(CWriteableSysNetModule * pSysNetModule, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetModuleSelectFunc)(CSysNetModule * pSysNetModule,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetModuleIterator *pIterator, TSysNetModuleActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetModuleIterator *pIterator, TSysNetModuleUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetModuleIterator *pIterator, TSysNetModuleSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventExprActionFunc)(CSysNetEventExpr * pSysNetEventExpr, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventExprUpdateFunc)(CWriteableSysNetEventExpr * pSysNetEventExpr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventExprSelectFunc)(CSysNetEventExpr * pSysNetEventExpr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetEventExprIterator *pIterator, TSysNetEventExprActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetEventExprIterator *pIterator, TSysNetEventExprUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetEventExprIterator *pIterator, TSysNetEventExprSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventTypeActionFunc)(CSysNetEventType * pSysNetEventType, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventTypeUpdateFunc)(CWriteableSysNetEventType * pSysNetEventType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventTypeSelectFunc)(CSysNetEventType * pSysNetEventType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubEventTypeActionFunc)(CSysNetSubEventType * pSysNetSubEventType, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubEventTypeUpdateFunc)(CWriteableSysNetSubEventType * pSysNetSubEventType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetSubEventTypeSelectFunc)(CSysNetSubEventType * pSysNetSubEventType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventLevelActionFunc)(CSysNetEventLevel * pSysNetEventLevel, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventLevelUpdateFunc)(CWriteableSysNetEventLevel * pSysNetEventLevel, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetEventLevelSelectFunc)(CSysNetEventLevel * pSysNetEventLevel,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorDeviceTaskActionFunc)(CSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorDeviceTaskUpdateFunc)(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorDeviceTaskSelectFunc)(CSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskInstAttrsActionFunc)(CSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskInstAttrsUpdateFunc)(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMonitorTaskInstAttrsSelectFunc)(CSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetBaseLineActionFunc)(CSysNetBaseLine * pSysNetBaseLine, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetBaseLineUpdateFunc)(CWriteableSysNetBaseLine * pSysNetBaseLine, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetBaseLineSelectFunc)(CSysNetBaseLine * pSysNetBaseLine,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetBaseLineTaskActionFunc)(CSysNetBaseLineTask * pSysNetBaseLineTask, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetBaseLineTaskUpdateFunc)(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetBaseLineTaskSelectFunc)(CSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbNetPartyLinkStatusInfoActionFunc)(CSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbNetPartyLinkStatusInfoUpdateFunc)(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbNetPartyLinkStatusInfoSelectFunc)(CSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMemberSDHLineInfoActionFunc)(CSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMemberSDHLineInfoUpdateFunc)(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetMemberSDHLineInfoSelectFunc)(CSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDDNLinkInfoActionFunc)(CSysNetDDNLinkInfo * pSysNetDDNLinkInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDDNLinkInfoUpdateFunc)(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetDDNLinkInfoSelectFunc)(CSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPseudMemberLinkInfoActionFunc)(CSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPseudMemberLinkInfoUpdateFunc)(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPseudMemberLinkInfoSelectFunc)(CSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetOuterDeviceInfoActionFunc)(CSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetOuterDeviceInfoUpdateFunc)(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetOuterDeviceInfoSelectFunc)(CSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysLocalPingResultInfoActionFunc)(CSysLocalPingResultInfo * pSysLocalPingResultInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysLocalPingResultInfoUpdateFunc)(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysLocalPingResultInfoSelectFunc)(CSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysRomotePingResultInfoActionFunc)(CSysRomotePingResultInfo * pSysRomotePingResultInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysRomotePingResultInfoUpdateFunc)(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysRomotePingResultInfoSelectFunc)(CSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticTradeOrderStatesActionFunc)(CSysParticTradeOrderStates * pSysParticTradeOrderStates, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticTradeOrderStatesUpdateFunc)(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysParticTradeOrderStatesSelectFunc)(CSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbRouterInfoActionFunc)(CSysMdbRouterInfo * pSysMdbRouterInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbRouterInfoUpdateFunc)(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbRouterInfoSelectFunc)(CSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbDiskIOActionFunc)(CSysMdbDiskIO * pSysMdbDiskIO, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbDiskIOUpdateFunc)(CWriteableSysMdbDiskIO * pSysMdbDiskIO, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbDiskIOSelectFunc)(CSysMdbDiskIO * pSysMdbDiskIO,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbStatInfoActionFunc)(CSysMdbStatInfo * pSysMdbStatInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbStatInfoUpdateFunc)(CWriteableSysMdbStatInfo * pSysMdbStatInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbStatInfoSelectFunc)(CSysMdbStatInfo * pSysMdbStatInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTradeFrontOrderRttStatActionFunc)(CSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTradeFrontOrderRttStatUpdateFunc)(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMdbTradeFrontOrderRttStatSelectFunc)(CSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInstrumentStatusActionFunc)(CSysInstrumentStatus * pSysInstrumentStatus, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInstrumentStatusUpdateFunc)(CWriteableSysInstrumentStatus * pSysInstrumentStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysInstrumentStatusSelectFunc)(CSysInstrumentStatus * pSysInstrumentStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysCurrTradingSegmentAttrActionFunc)(CSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysCurrTradingSegmentAttrUpdateFunc)(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysCurrTradingSegmentAttrSelectFunc)(CSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMemberLinkCostActionFunc)(CSysMemberLinkCost * pSysMemberLinkCost, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMemberLinkCostUpdateFunc)(CWriteableSysMemberLinkCost * pSysMemberLinkCost, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysMemberLinkCostSelectFunc)(CSysMemberLinkCost * pSysMemberLinkCost,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartylinkMonthlyRentActionFunc)(CSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartylinkMonthlyRentUpdateFunc)(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetPartylinkMonthlyRentSelectFunc)(CSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetNonPartyLinkInfoActionFunc)(CSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetNonPartyLinkInfoUpdateFunc)(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TSysNetNonPartyLinkInfoSelectFunc)(CSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

#endif
