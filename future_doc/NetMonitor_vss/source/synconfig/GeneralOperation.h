/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file GeneralOperation.h
///@brief ͨ�ò���������  Ϊͨ�ò����ṩ��ģ�巽��
///@history
///20110728	��־ΰ   �������ļ�
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
