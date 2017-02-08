/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file CommonFTDMsg.h
///@brief 实现CommonFTDMsg
///@history
///20110531	李志伟   创建该文件
/////////////////////////////////////////////////////////////////////////
#include "CommonFTDMsg.h"
#include <systools.h>
#include <FtdPackageDesc.h>

CCommonFTDRsp CCommonFTDRsp:: m_obj;

static CFTDRspInfoField defaultSuccInfo;
static CFTDRspInfoField defaultErrorInfo;

static CFTDRspInfoField succInfo;
static CFTDRspInfoField errorInfo;

CCommonFTDRsp *CCommonFTDRsp::Instance(void)
{
	return &m_obj;
}

void CCommonFTDRsp::initDefaultInfo(void)
{
	defaultSuccInfo.ErrorID = ERR_SUCCESS;
	defaultSuccInfo.ErrorMsg = "Success";

	defaultErrorInfo.ErrorID = -1;
	defaultErrorInfo.ErrorMsg = "Error";

	succInfo.ErrorID = ERR_SUCCESS;
	errorInfo.ErrorID = -1;
}

void CCommonFTDRsp::SendSuccRsp(
	CFTDCSession *session,
	CFTDCPackage *rsp,
	CFTDCPackage *req,
	DWORD pkgID,
	const char	*msg)
{
	assert(session && rsp && req);

	rsp->PrepareResponse(req, pkgID, FTDC_CHAIN_LAST, FTD_VERSION);

	if (msg)
	{
		succInfo.ErrorMsg = msg;
		FTDC_ADD_FIELD(rsp, &succInfo);
	}
	else
	{
		FTDC_ADD_FIELD(rsp, &defaultSuccInfo);
	}

	session->SendRequestPackage(rsp);
}

void CCommonFTDRsp::SendErroRsp(
	CFTDCSession *session,
	CFTDCPackage *rsp,
	CFTDCPackage *req,
	DWORD pkgID,
	BYTE chain,
	const char	*msg)
{
	assert(session && rsp && req);

	rsp->PrepareResponse(req, pkgID, chain, FTD_VERSION);

	if (msg)
	{
		errorInfo.ErrorMsg = msg;
		FTDC_ADD_FIELD(rsp, &errorInfo);
	}
	else
	{
		FTDC_ADD_FIELD(rsp, &defaultErrorInfo);
	}

	session->SendRequestPackage(rsp);
}

void CCommonFTDRsp::SendLastErroRsp(
	CFTDCSession *session,
	CFTDCPackage *rsp,
	CFTDCPackage *req,
	DWORD pkgID,
	const char	*msg)
{
	SendErroRsp(session, rsp, req, pkgID, FTDC_CHAIN_LAST, msg);
}

void CCommonFTDRsp::SendContinueErroRsp(
	CFTDCSession *session,
	CFTDCPackage *rsp,
	CFTDCPackage *req,
	DWORD pkgID,
	const char	*msg)
{
	SendErroRsp(session, rsp, req, pkgID, FTDC_CHAIN_CONTINUE, msg);
}
