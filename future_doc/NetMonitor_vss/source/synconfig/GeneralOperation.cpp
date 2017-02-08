/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file GeneralOperation.cpp
///@brief 通用操作处理类  为通用操作提供的模板方法
///@history
///20110728	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#include "GeneralOperation.h"
#include <UFCopy.h>
#include <FTDCPackage.h>
#include <FTDCSession.h>
#include <FtdData.h>
#include <BaseDataStruct.h>
#include <CMemoryDB.h>
#include <FTDDataWrapper.h>
#include <DBOperator.h>
#include <FtdPackageDesc.h>
#include <CommonFTDMsg.h>
#include "StringUtil.h"
#include "GeneralOperationTables_internal.h"
#include "FTDDataHelper.h"
#include "SessionProxy.h"
#include <PrjCommon.h>

extern CBufferLogger *g_bufferLogger;

#define DIVIDESTR	"*:*"
#define OPTIONSTR	"*$*"

#define DO_ADD_DETAIL(tag, reqField, operData, rtntag) \
    doAddDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_F2W_T(tag),\
    FTD_RTN(rtntag), FTD_OBJ_COPIER_F2RTN_T(tag)>(\
    pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_F2W(tag), reqField, operData, FTD_TABLE(tag),\
    FTD_OBJ_COPIER_F2RTN(tag), FTD_RTN_ID(rtntag));

#define DO_DELETE_DETAIL(tag, reqField, operData, rtntag) \
    doDeleteDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_W2F_T(tag),\
    FTD_RTN(rtntag), FTD_OBJ_COPIER_F2RTN_T(tag)>(\
    pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_W2F(tag), reqField, operData, FTD_TABLE(tag),\
    FTD_OBJ_COPIER_F2RTN(tag), FTD_RTN_ID(rtntag));

#define DO_UPDATE_DETAIL(tag, reqField, operData, rtntag) \
    doUpdateDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_W2F_T(tag),\
    FTD_OBJ_COPIER_F2W_T(tag), FTD_RTN(rtntag), FTD_OBJ_COPIER_F2RTN_T(tag)>(\
    pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_W2F(tag), FTD_OBJ_COPIER_F2W(tag),\
    reqField, operData, FTD_TABLE(tag), FTD_OBJ_COPIER_F2RTN(tag), FTD_RTN_ID(rtntag));

#define DO_QUERY_DETAIL(tag, reqField, operData, rtntag) \
    doQueryDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_W2F_T(tag)>(\
    pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_W2F(tag), reqField, operData, FTD_TABLE(tag));


#define DO_ADD_DETAIL2(tag, reqField, operData, rtnTag) \
	doAddDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_F2W_T(tag),\
	FTD_RTN(tag), FTD_OBJ_COPIER_F2RTN_T(tag)>(\
	pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_F2W(tag), reqField, operData, FTD_TABLE(tag),\
	FTD_OBJ_COPIER_F2RTN(tag), FTD_RTN_ID(tag));

typedef struct
{
	string name;	// attr's name
	string value;	// attr's value
} EqualCond;

typedef struct
{
	string name;	// attr's name
	string lbound;	// attr's lower bound value
	string ubound;	// attr's upper bound value
} RegionCond;

// 解析条件字符串，将条件放入相应的容器中，供后续判断使用
bool parseCondition(
	const string &table,
	const string &conditons,
	vector<EqualCond> &equalConditioin,
	vector<RegionCond>	&regionCondition)
{
	assert(!conditons.empty());

	vector<string> conditionArray;
	if (!SplitStr(conditons, OPTIONSTR, conditionArray))
	{
		LOG_WARNING(
			"There is an invaild conditions(%s) of (%s) !\n",
			conditons.c_str(),
			table.c_str());
		return false;
	}

	bool rtn = true;
	for (vector<string>::iterator it = conditionArray.begin();
		 it != conditionArray.end();
		 it++)
	{
		vector<string> condition;
		if (!SplitStr(*it, DIVIDESTR, condition))
		{
			LOG_WARNING(
				"There is an invaild condition(%s) of (%s) !\n",
				it->c_str(),
				table.c_str());
			continue;
		}

		size_t n = condition.size();
		if (n == 2)
		{
			// delete record which attr == condition[1] (attr is condition[0])
			EqualCond e;
			e.name = condition[0];
			e.value = condition[1];
			equalConditioin.push_back(e);
		}
		else if (n == 3)
		{
			//delete record which condition[2] > attr > condition[1] (attr is condition[0])
			RegionCond r;
			r.name = condition[0];
			r.lbound = condition[1];
			r.ubound = condition[2];
			regionCondition.push_back(r);
		}
		else
		{
			LOG_WARNING(
				"There is an invaild condition(%s) of (%s) !\n",
				it->c_str(),
				table.c_str());
			continue;
		}
	}

	return rtn;
}

// 检查FTD对象是否符合条件（相等条件或区间条件），如果符合返回true，否则返回false
bool matchCondition(
	CFtdData &obj,
	const vector<EqualCond> &equalConditioin,
	const vector<RegionCond> &regionCondition)
{
	// 就删除操作而言，没有相等条件或区间条件的约束时，即为删除该对象，因此在此返回true。
	// 对更新操作而言，没有相等条件或区间条件的约束时，是一个错误情况，但在调用此方法时已经过滤了这种错误。
	if (equalConditioin.size() == 0 && regionCondition.size() == 0)
	{
		return true;
	}

	bool isMatch = true;

	// Check euqal Condition
	int n = equalConditioin.size();
	int i;
	for (i = 0; i < n; i++)
	{
		int comp = obj.CompareAttrValue(
				equalConditioin[i].name.c_str(),
				equalConditioin[i].value.c_str());
		if (CFtdData::CR_EQ != comp)
		{
			isMatch = false;
			break;
		}
	}

	if (!isMatch)
	{
		return false;
	}

	// Check region Condition. Value should be in (regionCondition[i+1], regionCondition[i+2])
	n = regionCondition.size();
	for (i = 0; i < n; i++)
	{
		int comp = obj.CompareAttrValue(
				regionCondition[i].name.c_str(),
				regionCondition[i].lbound.c_str());
		if (CFtdData::CR_LT == comp)
		{	// not  >=
			isMatch = false;
			break;
		}

		comp = obj.CompareAttrValue(
				regionCondition[i].name.c_str(),
				regionCondition[i].ubound.c_str());
		if (CFtdData::CR_GT == comp)
		{	// not <=
			isMatch = false;
			break;
		}
	}

	return isMatch;
}

extern CMemoryDB *pMemoryDB;
extern map<string, int> g_idMaker;

template<typename CFTDT, typename CFTDRtnT, typename FTDToRtnT>
void notifySNMPAndEventMgr(
	CFTDT &field,
	const FTDToRtnT rtnCopier,
	const DWORD rtnID,
	char operType,
	General_Oper_Data *operData)
{
	CFTDRtnT rtnField;
	rtnCopier(&rtnField, &field);

	int n;
	switch (operType)
	{
		case GOT_query:
			n = 1;
			break;
		case GOT_add:
			n = 2;
			break;
		case GOT_del:
			n = 3;
			break;
		case GOT_update:
			n = 4;
			break;
		default:
			assert(false && "Invalid operation type!");
	}

	rtnField.OperationType = n;

	operData->rspPkg->PreparePackage(rtnID, FTDC_CHAIN_CONTINUE, FTD_VERSION);
	FTDC_ADD_FIELD(operData->rspPkg, &rtnField);

	SessionProxy::Instance().NotifySnmp(operData->rspPkg);

	SessionProxy::Instance().NotifyEventCounter(operData->rspPkg);

	SessionProxy::Instance().NotifySync(operData->rspPkg);
}

template
	<
		typename CFTDT, typename CFTDMemT, typename CFTDMemFactoryT, typename
			FTDCopierT, typename CFTDRtnT, typename FTDToRtnT
	>
int doAddDetail(
	CFTDMemFactoryT *memFactory,
	FTDCopierT copier,
	const CFTDReqQryGeneralOperateField &reqField,
	General_Oper_Data *operData,
	const char *table,
	FTDToRtnT rtnCopier,
	const DWORD rtnID)
{
	assert(memFactory && copier && operData);

	vector<string> records;

	if (!SplitStr(reqField.GeneralOperateSet.getValue(), OPTIONSTR, records))
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				operData->frontSession,
				operData->rspPkg,
				operData->reqPkg,
				FTD_RSP_ID(GeneralOperate));
		return -1;
	}

	CFTDT ftdField;
	CFTDMemT memField;

	CFtdData obj(&ftdField, &CFTDT::m_Describe);

	for (vector<string>::iterator it = records.begin();
		 it != records.end();
		 it++)
	{
		if (!obj.FromString(*it, DIVIDESTR))
		{
			continue;
		}

		// 赋予合适的ID索引
		ftdField.ID = g_idMaker[reqField.GeneralOperateTable.getValue()]++;

		// 更新数据库
		if (!operData->dbOper->InsertRecord(table, &obj))
		{
			CCommonFTDRsp::Instance()->SendContinueErroRsp(
					operData->frontSession,
					operData->rspPkg,
					operData->reqPkg,
					FTD_RSP_ID(GeneralOperate),
					"Insert record failed");
			continue;
		}

		// 更新内存数据库
		copier(&memField, &ftdField);
		memFactory->add(&memField);

		// send response
		CFTDRspQryGeneralOperateField rspField;
		rspField.GeneralOperateType = GOT_add;
		rspField.GeneralOperateTable = reqField.GeneralOperateTable;
		rspField.GeneralOperateSet = obj.ToString(DIVIDESTR).c_str();

		operData->rspPkg->PrepareResponse(
				operData->reqPkg,
				FTD_RSP_ID(GeneralOperate),
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		FTDC_ADD_FIELD(operData->rspPkg, &rspField);
		LogPkg(operData->rspPkg, g_bufferLogger, g_traceLog);
		operData->frontSession->SendRequestPackage(operData->rspPkg);

		//// send rtn
		FTD_RTN(GeneralOperate) rtnFiled;
		rtnFiled.GeneralOperateType = GOT_add;
		rtnFiled.GeneralOperateTable = reqField.GeneralOperateTable;
		rtnFiled.GeneralOperateSet = obj.ToString(DIVIDESTR).c_str();

		NEW_PKG_WITH_FIELD(
			operData->rspPkg,
			operData->reqPkg,
			FTD_RTN_ID(GeneralOperate),
			FTDC_CHAIN_CONTINUE,
			rtnFiled);
		operData->frontServer->NotifyAllSession(operData->rspPkg);

		notifySNMPAndEventMgr<CFTDT, CFTDRtnT, FTDToRtnT> (ftdField, rtnCopier, rtnID, reqField.GeneralOperateType, operData);
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			operData->frontSession,
			operData->rspPkg,
			operData->reqPkg,
			FTD_RSP_ID(GeneralOperate));

	return 0;
}

template
	<
		typename CFTDT, typename CFTDMemT, typename CFTDMemFactoryT, typename
			FTDCopierT, typename CFTDRtnT, typename FTDToRtnT
	>
int doDeleteDetail(
	CFTDMemFactoryT *memFactory,
	FTDCopierT copier,
	const CFTDReqQryGeneralOperateField &reqField,
	General_Oper_Data *operData,
	const char *table,
	FTDToRtnT rtnCopier,
	const DWORD rtnID)
{
	assert(memFactory && copier && operData);

	vector<EqualCond> equalConditioin;
	vector<RegionCond> regionCondition;

	string condition = reqField.GeneralOperateOption.getValue();

	if (!condition.empty()
	&&	!parseCondition(table, condition, equalConditioin, regionCondition))
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				operData->frontSession,
				operData->rspPkg,
				operData->reqPkg,
				FTD_RSP_ID(GeneralOperate));
		return -1;
	}

	CFTDT ftdField;

	if (equalConditioin.size() == 0 && regionCondition.size() == 0)
	{
		// 删除所有记录
		if (!operData->dbOper->DeleteRecord(table))
		{
			CCommonFTDRsp::Instance()->SendLastErroRsp(
					operData->frontSession,
					operData->rspPkg,
					operData->reqPkg,
					FTD_RSP_ID(GeneralOperate),
					"Delete record failed");
			return -1;
		}

		memFactory->clearAll();

		BUILD_CONTINUE_PKG_BY_FIELD(
			RTN,
			GeneralOperate,
			operData->reqPkg,
			operData->rspPkg,
			reqField);
		operData->frontServer->NotifyAllSession(operData->rspPkg);

		// 和其它服务器的约定，ID为-1即为删除所有记录
		ftdField.ID = -1;
		notifySNMPAndEventMgr<CFTDT, CFTDRtnT, FTDToRtnT> (ftdField, rtnCopier, rtnID, reqField.GeneralOperateType, operData);
	}
	else
	{
		// 删除指定记录
		CFTDMemT *memField = (CFTDMemT *)memFactory->startFindByAll();
		CFTDMemT *nextField;
		for (; memField != NULL; memField = nextField)
		{
			nextField = (CFTDMemT *)memFactory->findNextByAll();

			copier(&ftdField, memField);

			CFtdData obj(&ftdField, &CFTDT::m_Describe);

			if (matchCondition(obj, equalConditioin, regionCondition))
			{
				// 删除数据库中指定记录，目前只支持删除与相等条件匹配的记录
				DBOperator::ColumnArray cmpValues;
				for (size_t i = 0; i < equalConditioin.size(); i++)
				{
					cmpValues.push_back(
							DBOperator::Column(
									&obj,
									equalConditioin[i].name.c_str()));
				}

				if (!operData->dbOper->DeleteRecord(
						table,
					cmpValues,
					cmpValues))
				{
					CCommonFTDRsp::Instance()->SendContinueErroRsp(
							operData->frontSession,
							operData->rspPkg,
							operData->reqPkg,
							FTD_RSP_ID(GeneralOperate),
							"Delete record failed");
					continue;
				}

				// 删除内存数据库中记录
				memFactory->remove(memField);

				FTD_RTN(GeneralOperate) rtnFiled;
				rtnFiled.GeneralOperateType = GOT_del;
				rtnFiled.GeneralOperateTable = reqField.GeneralOperateTable;
				rtnFiled.GeneralOperateSet = obj.ToString(DIVIDESTR).c_str();

				NEW_PKG_WITH_FIELD(
					operData->rspPkg,
					operData->reqPkg,
					FTD_RTN_ID(GeneralOperate),
					FTDC_CHAIN_CONTINUE,
					rtnFiled);
				operData->frontServer->NotifyAllSession(operData->rspPkg);

				notifySNMPAndEventMgr<CFTDT, CFTDRtnT, FTDToRtnT>
					(
						ftdField, rtnCopier, rtnID, reqField.GeneralOperateType,
							operData
					);
			}
		}

		memFactory->endFindByAll();
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			operData->frontSession,
			operData->rspPkg,
			operData->reqPkg,
			FTD_RSP_ID(GeneralOperate));

	return 0;
}

template
	<
		typename CFTDT, typename CFTDMemT, typename CFTDMemFactoryT, typename
			FTDCopierWTFT, typename FTDCopierFTWT, typename CFTDRtnT, typename FTDToRtnT
	>
int doUpdateDetail(
	CFTDMemFactoryT *memFactory,
	FTDCopierWTFT WTFCopier,
	FTDCopierFTWT FTWCopier,
	const CFTDReqQryGeneralOperateField &reqField,
	General_Oper_Data *operData,
	const char *table,
	FTDToRtnT rtnCopier,
	const DWORD rtnID)
{
	assert(memFactory && WTFCopier && FTWCopier && operData);

	vector<EqualCond> equalConditioin;
	vector<RegionCond> regionCondition;

	string condition = reqField.GeneralOperateOption.getValue();
	if (!condition.empty()
	&&	!parseCondition(table, condition, equalConditioin, regionCondition))
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				operData->frontSession,
				operData->rspPkg,
				operData->reqPkg,
				FTD_RSP_ID(GeneralOperate));
		return -1;
	}

	if (equalConditioin.size() == 0 && regionCondition.size() == 0)
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				operData->frontSession,
				operData->rspPkg,
				operData->reqPkg,
				FTD_RSP_ID(GeneralOperate));
		return -1;
	}

	CFTDT ftdField;

	CFTDMemT *memField = (CFTDMemT *)memFactory->startFindByAll();
	CFTDMemT *nextField;
	for (; memField != NULL; memField = nextField)
	{
		nextField = (CFTDMemT *)memFactory->findNextByAll();

		WTFCopier(&ftdField, memField);

		CFtdData obj(&ftdField, &CFTDT::m_Describe);

		if (matchCondition(obj, equalConditioin, regionCondition))
		{
			CFTDT newField;
			CFtdData newObj(&newField, &CFTDT::m_Describe);

			if (!newObj.FromString(
					reqField.GeneralOperateSet.getValue(),
				DIVIDESTR))
			{
				continue;
			}

			// 更新数据库记录，目前只支持更新与相等条件匹配的记录
			DBOperator::ColumnArray cmpValues;
			for (size_t i = 0; i < equalConditioin.size(); i++)
			{
				cmpValues.push_back(
						DBOperator::Column(
								&newObj,
								equalConditioin[i].name.c_str()));
			}
			
			if (!operData->dbOper->UpdateRecord(table, cmpValues, cmpValues))
			{
				CCommonFTDRsp::Instance()->SendContinueErroRsp(
						operData->frontSession,
						operData->rspPkg,
						operData->reqPkg,
						FTD_RSP_ID(GeneralOperate),
						"Update record failed");
 				continue;
			}

			// 更新内存数据库中记录
			CFTDMemT newMemObj;
			FTWCopier(&newMemObj, &newField);
			memFactory->update(memField, &newMemObj);

			BUILD_CONTINUE_PKG_BY_FIELD(
				RTN,
				GeneralOperate,
				operData->reqPkg,
				operData->rspPkg,
				reqField);
			operData->frontServer->NotifyAllSession(operData->rspPkg);

			notifySNMPAndEventMgr<CFTDT, CFTDRtnT, FTDToRtnT>
				(
					newField, rtnCopier, rtnID, reqField.GeneralOperateType,
						operData
				);
		}
	}

	memFactory->endFindByAll();

	CCommonFTDRsp::Instance()->SendSuccRsp(
			operData->frontSession,
			operData->rspPkg,
			operData->reqPkg,
			FTD_RSP_ID(GeneralOperate));

	return 0;
}

template
	<
		typename CFTDT, typename CFTDMemT, typename CFTDMemFactoryT, typename FTDCopierT
	>
int doQueryDetail(
	CFTDMemFactoryT *memFactory,
	FTDCopierT copier,
	const CFTDReqQryGeneralOperateField &reqField,
	General_Oper_Data *operData,
	const char *table)
{
	assert(memFactory && copier && operData);

	vector<EqualCond> equalConditioin;
	vector<RegionCond> regionCondition;

	string condition = reqField.GeneralOperateOption.getValue();

	if (!condition.empty()
	&&	!parseCondition(table, condition, equalConditioin, regionCondition))
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				operData->frontSession,
				operData->rspPkg,
				operData->reqPkg,
				FTD_RSP_ID(GeneralOperate));
		return -1;
	}

	operData->rspPkg->PrepareResponse(
			operData->reqPkg,
			FTD_RSP_ID(GeneralOperate),
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);

	CFTDT ftdField;

	CFTDMemT *memField = (CFTDMemT *)memFactory->startFindByAll();

	for (; memField != NULL; memField = (CFTDMemT *)memFactory->findNextByAll())
	{
		copier(&ftdField, memField);

		CFtdData obj(&ftdField, &CFTDT::m_Describe);

		if (matchCondition(obj, equalConditioin, regionCondition))
		{
			CFTDRspQryGeneralOperateField rspField;    
			rspField.GeneralOperateType = GOT_add;
			rspField.GeneralOperateTable = reqField.GeneralOperateTable;

			if (rspField.GeneralOperateTable == "SysNetDevice")  
			{
				bool NeedUpdate=false;
				CDesEncryptAlgorithm despassw;
				despassw.SetPassword("monitor");
				char* cs=new char[257];
				if(obj.GetAttr("PASSWD",CFtdData::AT_String,cs,257))
				{
				  if (!despassw.IsEnOrDe(cs))
				  {
			         	char* miwen=new char[257];
				     	despassw.Encrypt(cs,miwen);   
						obj.SetAttr("PASSWD",CFtdData::AT_String,miwen);
						if (strcmp(cs,""))
						{
						    NeedUpdate=true;
						}
						
				  }
				}
				if(obj.GetAttr("ENPASSWD",CFtdData::AT_String,cs,257))
				{
					if (!despassw.IsEnOrDe(cs))
					{
						char* miwen=new char[257];
						despassw.Encrypt(cs,miwen);
						obj.SetAttr("ENPASSWD",CFtdData::AT_String,miwen);
						if (strcmp(cs,""))
						{
							NeedUpdate=true;
						}
					}
				}

				if (NeedUpdate)
				{
					if (!operData->dbOper->UpdateRecord(table,&obj,"ID"))
					{

					}
				}
				
			}
			rspField.GeneralOperateSet = obj.ToString(DIVIDESTR).c_str();
			
			AddRspWithField<CFTDRspQryGeneralOperateField>
				(
					operData->rspPkg, &rspField, operData->frontSession, operData->
						reqPkg, FTD_RSP_ID(GeneralOperate)
				);
		}
	}

	memFactory->endFindByAll();

	LogPkg(operData->rspPkg, g_bufferLogger, g_traceLog);
	operData->frontSession->SendRequestPackage(operData->rspPkg);

	CCommonFTDRsp::Instance()->SendSuccRsp(
			operData->frontSession,
			operData->rspPkg,
			operData->reqPkg,
			FTD_RSP_ID(GeneralOperate));

	return 0;
}


void defaultGeneralOperation(General_Oper_Data *operData)
{
	assert(operData);

	CCommonFTDRsp::Instance()->SendLastErroRsp(
			operData->frontSession,
			operData->rspPkg,
			operData->reqPkg,
			FTD_RSP_ID(GeneralOperate));
}

void DeleteDeviceRelation(
		const CFTDReqQryGeneralOperateField &reqField,
		General_Oper_Data *operData);

void CopyPartyLinkInfo(
	const CFTDReqQryGeneralOperateField &reqField,
	General_Oper_Data *operData);

void DoGeneralOperation(
	const CFTDReqQryGeneralOperateField &reqField,
	General_Oper_Data *operData)
{
	char reqFlag = reqField.GeneralOperateType;

	// handle SysNetDevice delete operation
	if (reqFlag == GOT_del && reqField.GeneralOperateTable == "SysNetDevice")
	{
		DeleteDeviceRelation(reqField, operData);
	}
	//if (reqFlag == GOT_del && reqField.GeneralOperateTable == "SysNetDelPartyLinkInfo")
	//{
	//	CopyPartyLinkInfo(reqField, operData);
	//}

	// 	if (reqField.GeneralOperateTable == "SysNetOuterDeviceInfo")
	// 	{
	// 		if (reqFlag == GOT_add)
	// 		{
	// 			doAddDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_F2W_T(tag),\
	// 				FTD_TID_RtnNetOuterDeviceInfTopic, FTD_OBJ_COPIER_F2RTN_T(tag)>(\
	// 				pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_F2W(tag), reqField, operData, FTD_TABLE(tag),\
	// 				FTD_OBJ_COPIER_F2RTN(tag), FTD_TID_RtnNetOuterDeviceInfTopic);
	// 		}
	// 		else if (reqFlag == GOT_del)
	// 		{
	// 			doDeleteDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_W2F_T(tag),\
	// 				FTD_RTN(tag), FTD_OBJ_COPIER_F2RTN_T(tag)>(\
	// 				pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_W2F(tag), reqField, operData, FTD_TABLE(tag),\
	// 				FTD_OBJ_COPIER_F2RTN(tag), FTD_RTN_ID(tag));
	// 		}
	// 		else if (reqFlag == GOT_query)
	// 		{
	// 			doQueryDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_W2F_T(tag)>(\
	// 				pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_W2F(tag), reqField, operData, FTD_TABLE(tag));
	// 		}
	// 		else if (reqFlag == GOT_update)
	// 		{
	// 			doUpdateDetail<FTD_FIELD(tag), FTD_WRITABLE(tag), FTD_FACTORY(tag), FTD_OBJ_COPIER_W2F_T(tag),\
	// 				FTD_OBJ_COPIER_F2W_T(tag), FTD_RTN(tag), FTD_OBJ_COPIER_F2RTN_T(tag)>(\
	// 				pMemoryDB->FTD_FACTORY_OBJ(tag), FTD_OBJ_COPIER_W2F(tag), FTD_OBJ_COPIER_F2W(tag),\
	// 				reqField, operData, FTD_TABLE(tag), FTD_OBJ_COPIER_F2RTN(tag), FTD_RTN_ID(tag));
	// 		}
	// 		else
	// 		{
	// 			//error flag
	// 		}
	// 		return;
	// 	}
	switch (reqFlag)
	{
		case GOT_add:
			{
				DO_OPERATION(
					reqField.GeneralOperateTable,
					reqField,
					DO_ADD_DETAIL,
					operData,
					defaultGeneralOperation);
				break;
			}

		case GOT_del:
			{
				DO_OPERATION(
					reqField.GeneralOperateTable,
					reqField,
					DO_DELETE_DETAIL,
					operData,
					defaultGeneralOperation);
				break;
			}

		case GOT_update:
			{
				DO_OPERATION(
					reqField.GeneralOperateTable,
					reqField,
					DO_UPDATE_DETAIL,
					operData,
					defaultGeneralOperation);
				break;
			}

		case GOT_query:
			{
				DO_OPERATION(
					reqField.GeneralOperateTable,
					reqField,
					DO_QUERY_DETAIL,
					operData,
					defaultGeneralOperation);
				break;
			}

		default:
			LOG_WARNING(
				"DoGeneralOperation: GeneralOperateType contains invalid value (%c)\n",
				reqField.GeneralOperateType);
			break;
	}
}

// SysNetDeviceLinked SysNetInterface SysNetModule
void DeleteDeviceRelation(
	const CFTDReqQryGeneralOperateField &reqField,
	General_Oper_Data *operData)
{
	assert(
		reqField.GeneralOperateTable == "SysNetDevice"
		&&	reqField.GeneralOperateType == GOT_del);
	assert(operData);

	vector<EqualCond> equalConditioin;
	vector<RegionCond> regionCondition;

	string condition = reqField.GeneralOperateOption.getValue();

	if (!condition.empty()
	&&	!parseCondition(
			"SysNetDevice",
		condition,
		equalConditioin,
		regionCondition))
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				operData->frontSession,
				operData->rspPkg,
				operData->reqPkg,
				FTD_RSP_ID(GeneralOperate));
		return;
	}

	if (equalConditioin.size() != 1 && equalConditioin[0].name != "ID")
	{
		LOG_WARNING(
			"General Operation: Delete Device need through ID! Client need check message!\n");
		return;
	}

	int deviceID = atoi(equalConditioin[0].value.c_str());
	string strDeviceID = equalConditioin[0].value.c_str();

	FTD_SysClass(NetDevice) * memObj = pMemoryDB->FTD_FACTORY_OBJ(
			NetDevice)->findByOne(deviceID);
	if (!memObj)
	{
		LOG_WARNING(
			"Can't delete Device BY ID (%d), There is no one!\n",
			deviceID);
		return;
	}

	string deviceObjID = memObj->ObjectID.getValue();

	// NetModule
	{
		string condition = "DeviceID";
		condition += DIVIDESTR;
		condition += strDeviceID;

		CFTDReqQryGeneralOperateField newRequest;
		newRequest.GeneralOperateType = GOT_del;
		newRequest.GeneralOperateTable = "SysNetModule";
		newRequest.GeneralOperateOption = condition.c_str();

		DoGeneralOperation(newRequest, operData);
	}

	// NetInterface
	{
		string condition = "DeviceID";
		condition += DIVIDESTR;
		condition += strDeviceID;

		CFTDReqQryGeneralOperateField newRequest;
		newRequest.GeneralOperateType = GOT_del;
		newRequest.GeneralOperateTable = "SysNetInterface";
		newRequest.GeneralOperateOption = condition.c_str();

		DoGeneralOperation(newRequest, operData);
	}

	// NetDeviceLinked
	{
		// NetDeviceID
		string condition = "NetObjectID";
		condition += DIVIDESTR;
		condition += deviceObjID;

		CFTDReqQryGeneralOperateField newRequest;
		newRequest.GeneralOperateType = GOT_del;
		newRequest.GeneralOperateTable = "SysNetDeviceLinked";
		newRequest.GeneralOperateOption = condition.c_str();

		DoGeneralOperation(newRequest, operData);

		// LinkNetDeviceID
		condition = "LinkNetObjectID";
		condition += DIVIDESTR;
		condition += deviceObjID;
		newRequest.GeneralOperateOption = condition.c_str();

		DoGeneralOperation(newRequest, operData);
	}
}
	void CopyPartyLinkInfo(
		const CFTDReqQryGeneralOperateField &reqField,
		General_Oper_Data *operData)
{
	// 首先将NetpartyLinkInfo数据表里面的数据取出来存进SysNetDelPartyLinkInfo表里面
	FTD_FACTORY(NetPartyLinkInfo) *memFactory = pMemoryDB->FTD_FACTORY_OBJ(NetPartyLinkInfo);
	FTD_OBJ_COPIER_W2F_T(NetPartyLinkInfo) copier = FTD_OBJ_COPIER_W2F(NetPartyLinkInfo);
	const char *table = FTD_TABLE(SysNetPartyLinkInfo);
	assert(memFactory && copier && operData);

	vector<EqualCond> equalConditioin;
	vector<RegionCond> regionCondition;

	string condition = reqField.GeneralOperateOption.getValue();

	if (!condition.empty() && !parseCondition(table, condition, equalConditioin, regionCondition))
	{
		CCommonFTDRsp::Instance()->SendLastErroRsp(
			operData->frontSession,
			operData->rspPkg,
			operData->reqPkg,
			FTD_RSP_ID(GeneralOperate));
		return ;
	}
	FTD_FIELD(NetPartyLinkInfo) ftdField;

	FTD_WRITABLE(NetPartyLinkInfo) *memField = (FTD_WRITABLE(NetPartyLinkInfo) *)memFactory->startFindByAll();

	for (; memField != NULL; memField = (FTD_WRITABLE(NetPartyLinkInfo) *)memFactory->findNextByAll())
	{
		copier(&ftdField, memField);

		CFtdData obj(&ftdField, &FTD_FIELD(NetPartyLinkInfo)::m_Describe);

		if (matchCondition(obj, equalConditioin, regionCondition))
		{
			// 首先将元素添加到 SysNetDelPartyLinkInfo表里
			CFTDReqQryGeneralOperateField newRspField; 
			memset(&newRspField, 0, sizeof(CFTDReqQryGeneralOperateField));
			newRspField.GeneralOperateType = GOT_add;
			newRspField.GeneralOperateTable = "SysNetDelPartyLinkInfo";

			newRspField.GeneralOperateSet = obj.ToString(DIVIDESTR).c_str();

			DoGeneralOperation(newRspField, operData);
		}
	}
	memFactory->endFindByAll();
}