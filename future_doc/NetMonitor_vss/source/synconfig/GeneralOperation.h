/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file GeneralOperation.h
///@brief 通用操作处理类  为通用操作提供的模板方法
///@history
///20110728	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#ifndef __GENERAL_OPERATION_H
#define __GENERAL_OPERATION_H
#include "CCrypto.h"
class CFTDCPackage;
class CFTDCSession;
class CFTDReqQryGeneralOperateField;
class DBOperator;
class CFrontServer;

typedef struct
{
	// Msg Sender
	CFTDCPackage *reqPkg;
	CFTDCPackage *rspPkg;
	CFTDCSession *frontSession;

	// CFrontServer reference
	CFrontServer *frontServer;

	// DB Handler
	DBOperator	*dbOper;
} General_Oper_Data;

void DoGeneralOperation(
		const CFTDReqQryGeneralOperateField &reqField,
		General_Oper_Data *operData);

#endif // __GENERAL_OPERATION_H
