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
typedef int (* TMonitorEntityActionFunc)(CMonitorEntity * pMonitorEntity, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMonitorEntityUpdateFunc)(CWriteableMonitorEntity * pMonitorEntity, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TMonitorEntitySelectFunc)(CMonitorEntity * pMonitorEntity,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CMonitorEntityIterator *pIterator, TMonitorEntityActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CMonitorEntityIterator *pIterator, TMonitorEntityUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CMonitorEntityIterator *pIterator, TMonitorEntitySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///操作函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TEventEntityActionFunc)(CEventEntity * pEventEntity, CTransaction * pTransaction,
	void * parameter);

///更新函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TEventEntityUpdateFunc)(CWriteableEventEntity * pEventEntity, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///选择函数类型定义，返回1表示需要继续操作，0表示需要结束操作
typedef int (* TEventEntitySelectFunc)(CEventEntity * pEventEntity,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///对一个枚举器的所有对象进行某项操作
///@param	pIterator	进行操作的枚举器
///@param	actionFunc	实际操作的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用actionFunc
void groupAction(CEventEntityIterator *pIterator, TEventEntityActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行更新操作
///@param	pIterator	进行操作的枚举器
///@param	updateFunc	实际进行更新的函数
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用updateFunc
void groupUpdate(CEventEntityIterator *pIterator, TEventEntityUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///对一个枚举器的所有对象进行删除操作
///@param	pIterator	进行操作的枚举器
///@param	selectFunc	实际需要删除的判断函数，NULL表示需要全部删除
///@param	pTransaction	操作属于的事务，NULL表示不使用事务
///@param	parameter	传递的参数，将代入每次叫用selectFunc
void groupDelete(CEventEntityIterator *pIterator, TEventEntitySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

#endif
