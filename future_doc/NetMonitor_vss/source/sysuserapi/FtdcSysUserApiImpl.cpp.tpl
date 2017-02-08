!!function!!
#include <set>
using namespace std;

struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};

typedef set<char *, ltstr> CPackageSet;
CPackageSet g_setUsePackage;

bool InUse(char *name)
{
	return (g_setUsePackage.find(name)!=g_setUsePackage.end());
}

!!endfunction!!


!!enter sysuserapi!!
!!travel self!!	
!!command g_setUsePackage.insert(@name);!!
!!next!!
!!leave!!

/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApiImpl.cpp
///@brief 实现了客户端接口
///@history 
///20060106	赵鸿昊		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FtdcSysUserApiImpl.h"
CFtdcSysUserApiImpl::CFtdcSysUserApiImpl(const char *pszFlowPath, CSelectReactor *pReactor)
:CFtdcSysUserApiImplBase(pszFlowPath, pReactor)
{
}

!!enter FTD!!
!!travel packages!!
!!let package_name=@name!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Req",3) && strcmp(@name,"ReqUserLogin") && strcmp(@name,"ReqQryInstPositionRate")  && strcmp(@name,"ReqSimulateStressTest")!!
///!!@comment!!
int CFtdcSysUserApiImpl::!!@name!!(!!travel self!!!!if @pumpid!=0!!, !!endif!!CShfeFtdc!!@name!!Field *p!!@name!!!!next!!, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_!!@package_name!!, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
!!travel self!!
	CFTD!!@name!!Field !!@name!!Field;
	memcpy(&!!@name!!Field, p!!@name!!, sizeof(CFTD!!@name!!Field));
	FTDC_ADD_FIELD(&m_reqPackage, &!!@name!!Field);
!!next!!

!!if !strncmp(@package_name, "ReqQry", 6) !!
	int nRet = RequestToQueryFlow();
!!else!!
	int nRet = RequestToDialogFlow();
!!endif!!	
	m_mutexAction.UnLock();
	
	return nRet;
}
!!endif!!
!!endif!!
!!next!!

void CFtdcSysUserApiImpl::HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries)
{

	switch(pMessage->GetTID()) {
!!travel packages!!
!!let package_name=@name!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rsp",3)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!elseif !strncmp(@name,"Rtn",3)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!elseif !strncmp(@name,"ErrRtn",6)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!elseif !strncmp(@name,"Intl",4)!!
	///!!@comment!!
	case FTD_TID_!!@name!!:
		On!!@name!!(pMessage, nSequenceSeries);
		break;
!!endif!!
!!endif!!
!!next!!
	default:
		break;
	}
}

CShfeFtdcSysUserApi *CShfeFtdcSysUserApi::CreateFtdcSysUserApi(const char *pszFlowPath)
{
	return new CFtdcSysUserApiImpl(pszFlowPath, new CSelectReactor());
}

!!travel packages!!
!!let package_name=@name!!
!!if InUse(@name)!!
!!if !strncmp(@name,"Rsp",3) && strcmp(@name, "RspError")!!
///!!@comment!!
void CFtdcSysUserApiImpl::On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
!!travel self!!
!!if strcmp(@name, "RspInfo")!!
	CFTD!!@name!!Field !!@name!!;
	CShfeFtdc!!@name!!Field *p!!@name!! = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTD!!@name!!Field::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&!!@name!!);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			p!!@name!! = (CShfeFtdc!!@name!!Field *)&!!@name!!;
			m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (p!!@name!! == NULL && m_pSpi != NULL)
	{
		m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField, pMessage->GetRequestId(), true);
	}
!!endif!!
!!next!!
}

!!elseif !strncmp(@name,"Rtn",3)!!
///!!@comment!!
void CFtdcSysUserApiImpl::On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
!!travel self!!
	CFTD!!@name!!Field !!@name!!;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTD!!@name!!Field::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&!!@name!!);
		!!if !strcmp(@name, "DepthMarketData")!!
		CFtdcSysUserApiImplBase::OnRtnDepthMarketData(&!!@name!!, nSequenceSeries);
		!!endif!!
		if (m_pSpi != NULL)
		{
			m_pSpi->On!!@package_name!!((CShfeFtdc!!@name!!Field *)&!!@name!!);
		}
		itor.Next();
	}
!!next!!
}

!!elseif !strncmp(@name,"ErrRtn",6)!!
///!!@comment!!
void CFtdcSysUserApiImpl::On!!@name!!(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
!!travel self!!
!!if strcmp(@name, "RspInfo")!!
	CFTD!!@name!!Field !!@name!!;
	CShfeFtdc!!@name!!Field *p!!@name!! = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTD!!@name!!Field::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&!!@name!!);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			p!!@name!! = (CShfeFtdc!!@name!!Field *)&!!@name!!;
			m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField);
		}
	}
	
	if (p!!@name!! == NULL && m_pSpi != NULL)
	{
		m_pSpi->On!!@package_name!!(p!!@name!!, pRspInfoField);
	}
!!endif!!
!!next!!
}

!!endif!!
!!endif!!
!!next!!

!!leave!!  
