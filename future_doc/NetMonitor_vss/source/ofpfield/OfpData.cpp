// OfpData.cpp: 
//
//////////////////////////////////////////////////////////////////////

#include "OfpData.h"


void dumpOFPField(COFPPingRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPPingRequest = {\n");
	char buffer[1024];
		pField->Date.getString(buffer);
		NET_PACKAGE_LOG1("\tDate = %s [处理机日期]\n",buffer);
		pField->Time.getString(buffer);
		NET_PACKAGE_LOG1("\tTime = %s [处理机时间]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginRequest = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginV2RequestField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginV2Request = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [私有流最大编号]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Password.getString(buffer);
		NET_PACKAGE_LOG1("\tPassword = %s [口令]\n",buffer);
		pField->Usernm.getString(buffer);
		NET_PACKAGE_LOG1("\tUsernm = %s [交易员姓名]\n",buffer);
		pField->Localno0.getString(buffer);
		NET_PACKAGE_LOG1("\tLocalno0 = %s [交易员用最大本地编号]\n",buffer);
		pField->Time.getString(buffer);
		NET_PACKAGE_LOG1("\tTime = %s [交易系统时间]\n",buffer);
		pField->Sysstat.getString(buffer);
		NET_PACKAGE_LOG1("\tSysstat = %s [交易系统状态]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [所属会员]\n",buffer);
		pField->Section.getString(buffer);
		NET_PACKAGE_LOG1("\tSection = %s [当前交易代码]\n",buffer);
		pField->Sstatus.getString(buffer);
		NET_PACKAGE_LOG1("\tSstatus = %s [交易节状态]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginV2ResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginV2Response = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Password.getString(buffer);
		NET_PACKAGE_LOG1("\tPassword = %s [口令]\n",buffer);
		pField->Usernm.getString(buffer);
		NET_PACKAGE_LOG1("\tUsernm = %s [交易员姓名]\n",buffer);
		pField->Date.getString(buffer);
		NET_PACKAGE_LOG1("\tDate = %s [交易日期]\n",buffer);
		pField->Time.getString(buffer);
		NET_PACKAGE_LOG1("\tTime = %s [交易系统时间]\n",buffer);
		pField->Sysstat.getString(buffer);
		NET_PACKAGE_LOG1("\tSysstat = %s [交易系统状态]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [所属会员]\n",buffer);
		pField->Section.getString(buffer);
		NET_PACKAGE_LOG1("\tSection = %s [当前交易代码]\n",buffer);
		pField->Sstatus.getString(buffer);
		NET_PACKAGE_LOG1("\tSstatus = %s [交易节状态]\n",buffer);
		pField->Localno0.getString(buffer);
		NET_PACKAGE_LOG1("\tLocalno0 = %s [交易员用最大报单本地编号]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [私有流最大编号]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLoginV2ErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLoginV2ErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [私有流最大编号]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLogoutRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPLogoutRequest = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLogoutResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLogoutResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPLogoutErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPLogoutErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPasswordUpdateRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPPasswordUpdateRequest = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->OldPasswd.getString(buffer);
		NET_PACKAGE_LOG1("\tOldPasswd = %s [旧口令]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPasswordUpdateResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPPasswordUpdateResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->OldPasswd.getString(buffer);
		NET_PACKAGE_LOG1("\tOldPasswd = %s [旧口令]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPasswordUpdateErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPPasswordUpdateErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->OldPasswd.getString(buffer);
		NET_PACKAGE_LOG1("\tOldPasswd = %s [旧口令]\n",buffer);
		pField->Passwd.getString(buffer);
		NET_PACKAGE_LOG1("\tPasswd = %s [口令]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPSystemWarningField *pField)
{
	NET_PACKAGE_LOG0("COFPSystemWarning = {\n");
	char buffer[1024];
		pField->Content.getString(buffer);
		NET_PACKAGE_LOG1("\tContent = %s [警告信息]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertRequest = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertNotUseRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertNotUseRequest = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Back.getString(buffer);
		NET_PACKAGE_LOG1("\tBack = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderInsertErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderInsertErrorResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelRequest = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelErrorResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOrderDelNotFoundResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPOrderDelNotFoundResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPAuthorizedOrderDelRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPAuthorizedOrderDelRequest = {\n");
	char buffer[1024];
		pField->orderid.getString(buffer);
		NET_PACKAGE_LOG1("\torderid = %s [报单系统编号，数字型]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPAuthorizedOrderDelResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPAuthorizedOrderDelResponse = {\n");
	char buffer[1024];
		pField->orderid.getString(buffer);
		NET_PACKAGE_LOG1("\torderid = %s [报单系统编号，数字型]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPAuthorizedOrderDelErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPAuthorizedOrderDelErrorResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号，数字型]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInternationalMarketRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInternationalMarketRequest = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [发送命令交易员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInternationalMarketResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInternationalMarketResponse = {\n");
	char buffer[1024];
		pField->content.getString(buffer);
		NET_PACKAGE_LOG1("\tcontent = %s [文本信息]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInternationalMarketErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInternationalMarketErrorResponse = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [发送命令交易员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryRubberMarketRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryRubberMarketRequest = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [发送命令交易员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryRubberMarketResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryRubberMarketResponse = {\n");
	char buffer[1024];
		pField->content.getString(buffer);
		NET_PACKAGE_LOG1("\tcontent = %s [文本信息]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryRubberMarketErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryRubberMarketErrorResponse = {\n");
	char buffer[1024];
		pField->userid.getString(buffer);
		NET_PACKAGE_LOG1("\tuserid = %s [发送命令交易员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPMBackOrderField *pField)
{
	NET_PACKAGE_LOG0("COFPMBackOrder = {\n");
	char buffer[1024];
		pField->mqid.getString(buffer);
		NET_PACKAGE_LOG1("\tmqid = %s [私有流序列号]\n",buffer);
		pField->cmd.getString(buffer);
		NET_PACKAGE_LOG1("\tcmd = %s [信息类型]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Orderf.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderf = %s [报单状态]\n",buffer);
		pField->Orderd.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderd = %s [报单录入日期]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [报单录入时间]\n",buffer);
		pField->Orderdt.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderdt = %s [报单删除时间]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPMBackOrderErrorField *pField)
{
	NET_PACKAGE_LOG0("COFPMBackOrderError = {\n");
	char buffer[1024];
		pField->mqid.getString(buffer);
		NET_PACKAGE_LOG1("\tmqid = %s [私有流序列号]\n",buffer);
		pField->cmd.getString(buffer);
		NET_PACKAGE_LOG1("\tcmd = %s [信息类型]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [申报价格]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [申报手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPTradeInsertField *pField)
{
	NET_PACKAGE_LOG0("COFPTradeInsert = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [报单申报手数]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [报单申报价格]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [报单当前成交手数]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [报单当前成交价格]\n",buffer);
		pField->Balance.getString(buffer);
		NET_PACKAGE_LOG1("\tBalance = %s [报单未成交剩余手数]\n",buffer);
		pField->Comps.getString(buffer);
		NET_PACKAGE_LOG1("\tComps = %s [未用]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Matcno.getString(buffer);
		NET_PACKAGE_LOG1("\tMatcno = %s [当前撮合编号]\n",buffer);
		pField->Compd.getString(buffer);
		NET_PACKAGE_LOG1("\tCompd = %s [撮合日期]\n",buffer);
		pField->Compt.getString(buffer);
		NET_PACKAGE_LOG1("\tCompt = %s [撮合时间]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPMBackTradeField *pField)
{
	NET_PACKAGE_LOG0("COFPMBackTrade = {\n");
	char buffer[1024];
		pField->mqid.getString(buffer);
		NET_PACKAGE_LOG1("\tmqid = %s [私有流序列号]\n",buffer);
		pField->cmd.getString(buffer);
		NET_PACKAGE_LOG1("\tcmd = %s [信息类型]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [报单申报手数]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [报单申报价格]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [报单当前成交手数]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [报单当前成交价格]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员编码]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [本地编号]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志]\n",buffer);
		pField->Matcno.getString(buffer);
		NET_PACKAGE_LOG1("\tMatcno = %s [当前撮合编号]\n",buffer);
		pField->Compd.getString(buffer);
		NET_PACKAGE_LOG1("\tCompd = %s [撮合日期]\n",buffer);
		pField->Compt.getString(buffer);
		NET_PACKAGE_LOG1("\tCompt = %s [撮合时间]\n",buffer);
		pField->Filler.getString(buffer);
		NET_PACKAGE_LOG1("\tFiller = %s [未用]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryDepositRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryDepositRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryDepositResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryDepositResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员]\n",buffer);
		pField->Margit.getString(buffer);
		NET_PACKAGE_LOG1("\tMargit = %s [日初资金]\n",buffer);
		pField->Credii.getString(buffer);
		NET_PACKAGE_LOG1("\tCredii = %s [未使用]\n",buffer);
		pField->Buymar.getString(buffer);
		NET_PACKAGE_LOG1("\tBuymar = %s [买入使用资金]\n",buffer);
		pField->Sellma.getString(buffer);
		NET_PACKAGE_LOG1("\tSellma = %s [卖出使用资金]\n",buffer);
		pField->Totall.getString(buffer);
		NET_PACKAGE_LOG1("\tTotall = %s [开仓使用资金]\n",buffer);
		pField->Closec.getString(buffer);
		NET_PACKAGE_LOG1("\tClosec = %s [剩余可用资金]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryDepositErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryDepositErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeResponse = {\n");
	char buffer[1024];
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [交易员所属会员的客户编码]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Brequam.getString(buffer);
		NET_PACKAGE_LOG1("\tBrequam = %s [买保值额度申请吨数]\n",buffer);
		pField->Buseram.getString(buffer);
		NET_PACKAGE_LOG1("\tBuseram = %s [买保值额度使用吨数]\n",buffer);
		pField->Bbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tBbalance = %s [买保值额度剩余吨数]\n",buffer);
		pField->Srequam.getString(buffer);
		NET_PACKAGE_LOG1("\tSrequam = %s [卖保值额度申请吨数]\n",buffer);
		pField->Suseram.getString(buffer);
		NET_PACKAGE_LOG1("\tSuseram = %s [卖保值额度使用吨数]\n",buffer);
		pField->Sbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tSbalance = %s [卖保值额度剩余吨数]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeV2RequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeV2Request = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeV2ResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeV2Response = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [交易员所属会员编码]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [交易员所属会员的客户编码]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Brequam.getString(buffer);
		NET_PACKAGE_LOG1("\tBrequam = %s [买保值额度申请吨数]\n",buffer);
		pField->Buseram.getString(buffer);
		NET_PACKAGE_LOG1("\tBuseram = %s [买保值额度使用吨数]\n",buffer);
		pField->Bbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tBbalance = %s [买保值额度剩余吨数]\n",buffer);
		pField->Srequam.getString(buffer);
		NET_PACKAGE_LOG1("\tSrequam = %s [卖保值额度申请吨数]\n",buffer);
		pField->Suseram.getString(buffer);
		NET_PACKAGE_LOG1("\tSuseram = %s [卖保值额度使用吨数]\n",buffer);
		pField->Sbalance.getString(buffer);
		NET_PACKAGE_LOG1("\tSbalance = %s [卖保值额度剩余吨数]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryHedgeV2ErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryHedgeV2ErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryClientRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryClientRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryClientResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryClientResponse = {\n");
	char buffer[1024];
		pField->Rstus.getString(buffer);
		NET_PACKAGE_LOG1("\tRstus = %s [未用]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Custnm.getString(buffer);
		NET_PACKAGE_LOG1("\tCustnm = %s [客户名称]\n",buffer);
		pField->Custad.getString(buffer);
		NET_PACKAGE_LOG1("\tCustad = %s [客户地址]\n",buffer);
		pField->Custtel.getString(buffer);
		NET_PACKAGE_LOG1("\tCusttel = %s [客户联系电话]\n",buffer);
		pField->Tradtp.getString(buffer);
		NET_PACKAGE_LOG1("\tTradtp = %s [客户企业性质]\n",buffer);
		pField->Reprnm.getString(buffer);
		NET_PACKAGE_LOG1("\tReprnm = %s [法人代表]\n",buffer);
		pField->custle.getString(buffer);
		NET_PACKAGE_LOG1("\tcustle = %s [客户标志]\n",buffer);
		pField->Emplid.getString(buffer);
		NET_PACKAGE_LOG1("\tEmplid = %s [所属会员]\n",buffer);
		pField->Credit.getString(buffer);
		NET_PACKAGE_LOG1("\tCredit = %s [未用]\n",buffer);
		pField->Trades.getString(buffer);
		NET_PACKAGE_LOG1("\tTrades = %s [是否允许交易]\n",buffer);
		pField->Tradau.getString(buffer);
		NET_PACKAGE_LOG1("\tTradau = %s [未用]\n",buffer);
		pField->Indate.getString(buffer);
		NET_PACKAGE_LOG1("\tIndate = %s [开户日期]\n",buffer);
		pField->Modate.getString(buffer);
		NET_PACKAGE_LOG1("\tModate = %s [未用]\n",buffer);
		pField->Instaff.getString(buffer);
		NET_PACKAGE_LOG1("\tInstaff = %s [未用]\n",buffer);
		pField->Mostaff.getString(buffer);
		NET_PACKAGE_LOG1("\tMostaff = %s [未用]\n",buffer);
		pField->Comple.getString(buffer);
		NET_PACKAGE_LOG1("\tComple = %s [客户类型]\n",buffer);
		pField->Regisf.getString(buffer);
		NET_PACKAGE_LOG1("\tRegisf = %s [注册／营运资金]\n",buffer);
		pField->Floortr.getString(buffer);
		NET_PACKAGE_LOG1("\tFloortr = %s [未用]\n",buffer);
		pField->Zjhm.getString(buffer);
		NET_PACKAGE_LOG1("\tZjhm = %s [证件号码或身份证号码]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryClientErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryClientErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentRequest = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentResponse = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种代码]\n",buffer);
		pField->Commnm.getString(buffer);
		NET_PACKAGE_LOG1("\tCommnm = %s [交易品种名称]\n",buffer);
		pField->Delim.getString(buffer);
		NET_PACKAGE_LOG1("\tDelim = %s [交割月份，格式为yymm＋space（2）]\n",buffer);
		pField->Abbr.getString(buffer);
		NET_PACKAGE_LOG1("\tAbbr = %s [大类品种的数字编码，如‘01’为铜]\n",buffer);
		pField->Trade.getString(buffer);
		NET_PACKAGE_LOG1("\tTrade = %s [每手数量（吨）]\n",buffer);
		pField->Tick.getString(buffer);
		NET_PACKAGE_LOG1("\tTick = %s [最小变动价位]\n",buffer);
		pField->Daill.getString(buffer);
		NET_PACKAGE_LOG1("\tDaill = %s [未用，应该是涨跌停板率]\n",buffer);
		pField->Closed.getString(buffer);
		NET_PACKAGE_LOG1("\tClosed = %s [未用，应该是保值平仓允许开始日期]\n",buffer);
		pField->Commtp.getString(buffer);
		NET_PACKAGE_LOG1("\tCommtp = %s [品种类型，‘f’‘F’期货／其他]\n",buffer);
		pField->Stard.getString(buffer);
		NET_PACKAGE_LOG1("\tStard = %s [开始交易日期]\n",buffer);
		pField->Delid.getString(buffer);
		NET_PACKAGE_LOG1("\tDelid = %s [开始交割日期]\n",buffer);
		pField->Stopd.getString(buffer);
		NET_PACKAGE_LOG1("\tStopd = %s [结束交易日期]\n",buffer);
		pField->Posil.getString(buffer);
		NET_PACKAGE_LOG1("\tPosil = %s [报单单笔最大申报手数]\n",buffer);
		pField->Commst.getString(buffer);
		NET_PACKAGE_LOG1("\tCommst = %s [品种交易状态，‘a’允许／其他不允许]\n",buffer);
		pField->Lastde.getString(buffer);
		NET_PACKAGE_LOG1("\tLastde = %s [结束交割日期]\n",buffer);
		pField->Margin.getString(buffer);
		NET_PACKAGE_LOG1("\tMargin = %s [未用，为‘1．00’]\n",buffer);
		pField->Sxfl.getString(buffer);
		NET_PACKAGE_LOG1("\tSxfl = %s [未用，为‘0．00’]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentErrorResponse = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAuthorizedOrderRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAuthorizedOrderRequest = {\n");
	char buffer[1024];
		pField->username.getString(buffer);
		NET_PACKAGE_LOG1("\tusername = %s [指定交易员或会员的编码]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAuthorizedOrderResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAuthorizedOrderResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向，‘b’买／‘s’卖]\n",buffer);
		pField->Orderf.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderf = %s [报单状态，‘o’有效报单]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志，‘0’保值／‘1’投机]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [报单申报手数]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [报单申报价格]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [总成交手数]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [最后一笔成交价格]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [报单时间]\n",buffer);
		pField->DOrdt.getString(buffer);
		NET_PACKAGE_LOG1("\tDOrdt = %s [报单删除时间]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [报单本地编号]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAuthorizedOrderErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAuthorizedOrderErrorResponse = {\n");
	char buffer[1024];
		pField->username.getString(buffer);
		NET_PACKAGE_LOG1("\tusername = %s [指定交易员或会员的编码]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryOrderRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryOrderRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryAllOrderRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryAllOrderRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryOrderResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryOrderResponse = {\n");
	char buffer[1024];
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [报单申报时间]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Delim.getString(buffer);
		NET_PACKAGE_LOG1("\tDelim = %s [交割月份，未用]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖方向，‘b’买／‘s’卖]\n",buffer);
		pField->Orderf.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderf = %s [报单状态，‘o’有效报单]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [报单申报手数]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [报单申报价格]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [总成交手数]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [最后一笔成交价格]\n",buffer);
		pField->Balance.getString(buffer);
		NET_PACKAGE_LOG1("\tBalance = %s [报单剩余手数]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员]\n",buffer);
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [报单本地编号]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志，‘0’保值／‘1’投机]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryOrderErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryOrderErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTradeRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTradeRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTradeResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTradeResponse = {\n");
	char buffer[1024];
		pField->Lorderid.getString(buffer);
		NET_PACKAGE_LOG1("\tLorderid = %s [报单本地编号]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Posit.getString(buffer);
		NET_PACKAGE_LOG1("\tPosit = %s [买卖标志，‘b’买／‘s’卖]\n",buffer);
		pField->Closef.getString(buffer);
		NET_PACKAGE_LOG1("\tClosef = %s [开平仓标志]\n",buffer);
		pField->Tjbz.getString(buffer);
		NET_PACKAGE_LOG1("\tTjbz = %s [投机保值标志，‘0’保值／‘1’投机]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [总成交手数]\n",buffer);
		pField->Compp.getString(buffer);
		NET_PACKAGE_LOG1("\tCompp = %s [最后一笔成交价格]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [交易员]\n",buffer);
		pField->Compd.getString(buffer);
		NET_PACKAGE_LOG1("\tCompd = %s [成交日期，格式ccyymmdd]\n",buffer);
		pField->Compt.getString(buffer);
		NET_PACKAGE_LOG1("\tCompt = %s [成交时间，格式hhmmssuu]\n",buffer);
		pField->Matcno.getString(buffer);
		NET_PACKAGE_LOG1("\tMatcno = %s [撮合编号]\n",buffer);
		pField->Orderid.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderid = %s [报单系统编号]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [报单申报手数]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [报单申报价格]\n",buffer);
		pField->Ordert.getString(buffer);
		NET_PACKAGE_LOG1("\tOrdert = %s [报单时间]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTradeErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTradeErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPPositionResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员编码]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码，为ASCII空格]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [买保值手数]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [买投机手数]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [卖保值手数]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [卖投机手数]\n",buffer);
		pField->Openbvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvb = %s [今买保值新开仓手数]\n",buffer);
		pField->Openbvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvt = %s [今买投机新开仓手数]\n",buffer);
		pField->Opensvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvb = %s [今卖保值新开仓手数]\n",buffer);
		pField->Opensvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvt = %s [今卖投机新开仓手数]\n",buffer);
		pField->Fbuyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvb = %s [买保值冻结持仓手数]\n",buffer);
		pField->Fbuyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvt = %s [买投机冻结持仓手数]\n",buffer);
		pField->Fsellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvb = %s [卖保值冻结持仓手数]\n",buffer);
		pField->Fsellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvt = %s [卖投机冻结持仓手数]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [前交易日结算价]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [未用，保值使用保证金（格式％15．2f）]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [未用，投机使用保证金（格式％15．2f）]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPPositionResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员编码]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [买保值手数]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [买投机手数]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [卖保值手数]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [卖投机手数]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [前交易日结算价]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [未用，保值使用保证金（格式％15．2f）]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [未用，投机使用保证金（格式％15．2f）]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [查询起始客户]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [查询结束客户]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPositionResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员编码]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码，为ASCII空格]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [买保值手数]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [买投机手数]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [卖保值手数]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [卖投机手数]\n",buffer);
		pField->Openbvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvb = %s [今买保值新开仓手数]\n",buffer);
		pField->Openbvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpenbvt = %s [今买投机新开仓手数]\n",buffer);
		pField->Opensvb.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvb = %s [今卖保值新开仓手数]\n",buffer);
		pField->Opensvt.getString(buffer);
		NET_PACKAGE_LOG1("\tOpensvt = %s [今卖投机新开仓手数]\n",buffer);
		pField->Fbuyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvb = %s [买保值冻结持仓手数]\n",buffer);
		pField->Fbuyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFbuyvt = %s [买投机冻结持仓手数]\n",buffer);
		pField->Fsellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvb = %s [卖保值冻结持仓手数]\n",buffer);
		pField->Fsellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tFsellvt = %s [卖投机冻结持仓手数]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [前交易日结算价]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [未用，保值使用保证金（格式％15．2f）]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [未用，投机使用保证金（格式％15．2f）]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [查询起始客户]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [查询结束客户]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPositionRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPositionRequest = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [查询起始客户]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [查询结束客户]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPositionResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPositionResponse = {\n");
	char buffer[1024];
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [客户编码，为ASCII空格]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Buyvb.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvb = %s [买保值手数]\n",buffer);
		pField->Buyvt.getString(buffer);
		NET_PACKAGE_LOG1("\tBuyvt = %s [买投机手数]\n",buffer);
		pField->Sellvb.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvb = %s [卖保值手数]\n",buffer);
		pField->Sellvt.getString(buffer);
		NET_PACKAGE_LOG1("\tSellvt = %s [卖投机手数]\n",buffer);
		pField->Clearp.getString(buffer);
		NET_PACKAGE_LOG1("\tClearp = %s [前交易日结算价]\n",buffer);
		pField->Margamb.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamb = %s [未用，保值使用保证金（格式％15．2f）]\n",buffer);
		pField->Margamt.getString(buffer);
		NET_PACKAGE_LOG1("\tMargamt = %s [未用，投机使用保证金（格式％15．2f）]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryBriefPositionErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryBriefPositionErrorResponse = {\n");
	char buffer[1024];
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [查询起始会员]\n",buffer);
		pField->Membidt.getString(buffer);
		NET_PACKAGE_LOG1("\tMembidt = %s [查询结束会员]\n",buffer);
		pField->Custid.getString(buffer);
		NET_PACKAGE_LOG1("\tCustid = %s [查询起始客户]\n",buffer);
		pField->Custidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCustidt = %s [查询结束客户]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentPriceRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentPriceRequest = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentPriceResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentPriceResponse = {\n");
	char buffer[1024];
		pField->Bsflag.getString(buffer);
		NET_PACKAGE_LOG1("\tBsflag = %s [买卖报价，‘b’买／‘s’卖]\n",buffer);
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [交易品种]\n",buffer);
		pField->Orderp.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderp = %s [报价]\n",buffer);
		pField->Orderv.getString(buffer);
		NET_PACKAGE_LOG1("\tOrderv = %s [所有申报手数]\n",buffer);
		pField->Compv.getString(buffer);
		NET_PACKAGE_LOG1("\tCompv = %s [所有成交手数]\n",buffer);
		pField->Cancelv.getString(buffer);
		NET_PACKAGE_LOG1("\tCancelv = %s [所有撤单手数]\n",buffer);
		pField->Currentv.getString(buffer);
		NET_PACKAGE_LOG1("\tCurrentv = %s [所有有效手数]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentPriceErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentPriceErrorResponse = {\n");
	char buffer[1024];
		pField->Commid.getString(buffer);
		NET_PACKAGE_LOG1("\tCommid = %s [查询起始交易品种]\n",buffer);
		pField->Commidt.getString(buffer);
		NET_PACKAGE_LOG1("\tCommidt = %s [查询结束交易品种]\n",buffer);
		pField->Option.getString(buffer);
		NET_PACKAGE_LOG1("\tOption = %s [查询选项]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentNumberRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentNumberRequest = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentNumberResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentNumberResponse = {\n");
	char buffer[1024];
		pField->rstus.getString(buffer);
		NET_PACKAGE_LOG1("\trstus = %s [未用，为‘　’]\n",buffer);
		pField->comm.getString(buffer);
		NET_PACKAGE_LOG1("\tcomm = %s [交易品种大类代码，如‘cu’，‘al’等]\n",buffer);
		pField->abbrev.getString(buffer);
		NET_PACKAGE_LOG1("\tabbrev = %s [交易品种大类数字代码，如‘01’、‘02’等]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryInstrumentNumberErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryInstrumentNumberErrorResponse = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTrasnferIdRequestField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTrasnferIdRequest = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员用户]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员编号]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTrasnferIdResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTrasnferIdResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员用户]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员编号]\n",buffer);
		pField->Transferid.getString(buffer);
		NET_PACKAGE_LOG1("\tTransferid = %s [交易系统会员私有流回报目前最大编号]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPQryTrasnferIdErrorResponseField *pField)
{
	NET_PACKAGE_LOG0("COFPQryTrasnferIdErrorResponse = {\n");
	char buffer[1024];
		pField->Userid.getString(buffer);
		NET_PACKAGE_LOG1("\tUserid = %s [交易员用户]\n",buffer);
		pField->Membid.getString(buffer);
		NET_PACKAGE_LOG1("\tMembid = %s [会员编号]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPStartField *pField)
{
	NET_PACKAGE_LOG0("COFPStart = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOpenField *pField)
{
	NET_PACKAGE_LOG0("COFPOpen = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPauseField *pField)
{
	NET_PACKAGE_LOG0("COFPPause = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPCloseField *pField)
{
	NET_PACKAGE_LOG0("COFPClose = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPEndField *pField)
{
	NET_PACKAGE_LOG0("COFPEnd = {\n");
	char buffer[1024];
		pField->rstatus.getString(buffer);
		NET_PACKAGE_LOG1("\trstatus = %s [未使用，为‘　’]\n",buffer);
		pField->sectid.getString(buffer);
		NET_PACKAGE_LOG1("\tsectid = %s [交易节]\n",buffer);
		pField->desc.getString(buffer);
		NET_PACKAGE_LOG1("\tdesc = %s [交易节描述]\n",buffer);
		pField->sects0.getString(buffer);
		NET_PACKAGE_LOG1("\tsects0 = %s [交易节状态]\n",buffer);
		pField->sects1.getString(buffer);
		NET_PACKAGE_LOG1("\tsects1 = %s [交易节是否收盘集合竞价初始化标志，‘1’是／其他否]\n",buffer);
		pField->f2.getString(buffer);
		NET_PACKAGE_LOG1("\tf2 = %s [未使用，为‘　’]\n",buffer);
		pField->starttime.getString(buffer);
		NET_PACKAGE_LOG1("\tstarttime = %s [客户端不用知道内容]\n",buffer);
		pField->endtime.getString(buffer);
		NET_PACKAGE_LOG1("\tendtime = %s [客户端不用知道内容]\n",buffer);
		pField->cu.getString(buffer);
		NET_PACKAGE_LOG1("\tcu = %s [本节铜是否交易，‘1’交易／其他否]\n",buffer);
		pField->al.getString(buffer);
		NET_PACKAGE_LOG1("\tal = %s [本节铝是否交易，‘1’交易／其他否]\n",buffer);
		pField->ru.getString(buffer);
		NET_PACKAGE_LOG1("\tru = %s [本节橡胶是否交易，‘1’交易／其他否]\n",buffer);
		pField->pw.getString(buffer);
		NET_PACKAGE_LOG1("\tpw = %s [本节甲板是否交易，‘1’交易／其他否]\n",buffer);
		pField->rc.getString(buffer);
		NET_PACKAGE_LOG1("\trc = %s [本节籼米是否交易，‘1’交易／其他否]\n",buffer);
		pField->f3.getString(buffer);
		NET_PACKAGE_LOG1("\tf3 = %s [未使用，为‘　’]\n",buffer);
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPPresectField *pField)
{
	NET_PACKAGE_LOG0("COFPPresect = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPSectionStartField *pField)
{
	NET_PACKAGE_LOG0("COFPSectionStart = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPSectionStopField *pField)
{
	NET_PACKAGE_LOG0("COFPSectionStop = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOpenAuctionSectionStartField *pField)
{
	NET_PACKAGE_LOG0("COFPOpenAuctionSectionStart = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPOpenAuctionSectionStopField *pField)
{
	NET_PACKAGE_LOG0("COFPOpenAuctionSectionStop = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPCloseAuctionSectionStartField *pField)
{
	NET_PACKAGE_LOG0("COFPCloseAuctionSectionStart = {\n");
	NET_PACKAGE_LOG0("}\n");
}


void dumpOFPField(COFPCloseAuctionSectionStopField *pField)
{
	NET_PACKAGE_LOG0("COFPCloseAuctionSectionStop = {\n");
	NET_PACKAGE_LOG0("}\n");
}


WORD GetOFPVary(const char *command)
{
	if (!strcmp(command,"ping"))
	{
		return OFP_VARY_PingRequest;
	}
	if (!strcmp(command,"login"))
	{
		return OFP_VARY_LoginRequest;
	}
	if (!strcmp(command,"login"))
	{
		return OFP_VARY_LoginV2Request;
	}
	if (!strcmp(command,"logout"))
	{
		return OFP_VARY_LogoutRequest;
	}
	if (!strcmp(command,"modpwd"))
	{
		return OFP_VARY_PasswordUpdateRequest;
	}
	if (!strcmp(command,"buy"))
	{
		return OFP_VARY_OrderInsertRequest;
	}
	if (!strcmp(command,"sell"))
	{
		return OFP_VARY_OrderInsertNotUseRequest;
	}
	if (!strcmp(command,"delor"))
	{
		return OFP_VARY_OrderDelRequest;
	}
	if (!strcmp(command,"udelor"))
	{
		return OFP_VARY_AuthorizedOrderDelRequest;
	}
	if (!strcmp(command,"eqit"))
	{
		return OFP_VARY_QryInternationalMarketRequest;
	}
	if (!strcmp(command,"eqfg"))
	{
		return OFP_VARY_QryRubberMarketRequest;
	}
	if (!strcmp(command,"eqmag"))
	{
		return OFP_VARY_QryDepositRequest;
	}
	if (!strcmp(command,"eqbzsq"))
	{
		return OFP_VARY_QryHedgeRequest;
	}
	if (!strcmp(command,"eqbzsqy2"))
	{
		return OFP_VARY_QryHedgeV2Request;
	}
	if (!strcmp(command,"eqmem"))
	{
		return OFP_VARY_QryClientRequest;
	}
	if (!strcmp(command,"eqcomm"))
	{
		return OFP_VARY_QryInstrumentRequest;
	}
	if (!strcmp(command,"eqory3"))
	{
		return OFP_VARY_QryAuthorizedOrderRequest;
	}
	if (!strcmp(command,"eqorsect"))
	{
		return OFP_VARY_QryOrderRequest;
	}
	if (!strcmp(command,"eqor"))
	{
		return OFP_VARY_QryAllOrderRequest;
	}
	if (!strcmp(command,"eqcotry4"))
	{
		return OFP_VARY_QryTradeRequest;
	}
	if (!strcmp(command,"eqpstln"))
	{
		return OFP_VARY_QryPPositionRequest;
	}
	if (!strcmp(command,"eqpstl"))
	{
		return OFP_VARY_QryBriefPPositionRequest;
	}
	if (!strcmp(command,"eqpstln"))
	{
		return OFP_VARY_QryPositionRequest;
	}
	if (!strcmp(command,"eqpstl"))
	{
		return OFP_VARY_QryBriefPositionRequest;
	}
	if (!strcmp(command,"eqortl"))
	{
		return OFP_VARY_QryInstrumentPriceRequest;
	}
	if (!strcmp(command,"eqcomma"))
	{
		return OFP_VARY_QryInstrumentNumberRequest;
	}
	if (!strcmp(command,"eqbackid"))
	{
		return OFP_VARY_QryTrasnferIdRequest;
	}
	return 0;
}

